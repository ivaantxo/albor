#!/usr/bin/env python3
"""Pasa el blockdata de los layouts al bloque nuevo: colision de 1 bit + ID de 15.

Bloque viejo (el de antes de este cambio, no el de pokeemerald):

    bits 0-11   ID de metatile
    bit  12     colision
    bits 13-15  elevacion

Bloque nuevo (include/global.fieldmap.h):

    bits 0-14   ID de metatile
    bit  15     colision

La elevacion desaparece del bloque: el juego la saca del metatile (ver
GetMetatileElevationById en src/fieldmap.c). Este script hace la misma cuenta
para cada casilla y avisa de las que cambiarian de altura al convertirlas:

  - En una casilla que se pisa, el aviso importa. Hay que darle a ese metatile
    un nivel fijo (METATILE_NIVEL_*) o pintar ahi otro metatile.
  - En una casilla bloqueada, la altura no la mira nadie... salvo un objeto que
    este puesto encima, y de esos se avisa aparte.

Se hace una sola vez: el formato no lleva marca y pasarlo dos veces lo estropea.
Sin --escribir solo informa.

    python3 tools/mapeado/convertir_bloques.py             # informe
    python3 tools/mapeado/convertir_bloques.py --escribir  # convierte
"""

import argparse
import json
import re
import struct
import sys
from pathlib import Path

RAIZ = Path(__file__).resolve().parents[2]

VIEJO_ID = 0x0FFF
VIEJO_COLISION = 0x1000
VIEJO_ELEVACION_SHIFT = 13

NUEVO_ID = 0x7FFF
NUEVO_COLISION = 0x8000

# Las mismas cuentas que GetMetatileElevationById.
ATTR_BEHAVIOR = 0x00FF
ATTR_NIVEL = 0x0F00
ATTR_NIVEL_SHIFT = 8
NIVEL_AUTO = 0
NIVEL_0 = 8
MAX_ELEVATION_LEVEL = 7

# Los de MetatileBehavior_IsBridgeOverWater.
PUENTES = {
    "MB_BRIDGE_OVER_OCEAN",
    "MB_BRIDGE_OVER_POND_LOW",
    "MB_BRIDGE_OVER_POND_MED",
    "MB_BRIDGE_OVER_POND_HIGH",
    "MB_BRIDGE_OVER_POND_HIGH_EDGE_1",
    "MB_BRIDGE_OVER_POND_HIGH_EDGE_2",
    "MB_BIKE_BRIDGE_OVER_BARRIER",
}


def leer_u16(ruta):
    datos = ruta.read_bytes()
    return list(struct.unpack(f"<{len(datos) // 2}H", datos))


def escribir_u16(ruta, valores):
    ruta.write_bytes(struct.pack(f"<{len(valores)}H", *valores))


def comportamientos():
    """Numero -> nombre de los MB_*, en el orden del enum."""
    texto = (RAIZ / "include/constants/metatile_behaviors.h").read_text()
    cuerpo = texto[texto.index("{") + 1:texto.index("}")]
    nombres, valor = {}, 0
    for linea in cuerpo.splitlines():
        linea = linea.split("//")[0].strip().rstrip(",")
        if not linea:
            continue
        if "=" in linea:
            nombre, expr = (p.strip() for p in linea.split("="))
            valor = int(expr, 0)
        else:
            nombre = linea
        nombres[valor] = nombre
        valor += 1
    return nombres


def surfeables():
    """Los MB_* que llevan TILE_FLAG_SURFABLE en sTileBitAttributes."""
    texto = (RAIZ / "src/metatile_behavior.c").read_text()
    return set(re.findall(r"\[(MB_\w+)\]\s*=[^,\n]*TILE_FLAG_SURFABLE", texto))


def define(ruta, nombre):
    m = re.search(rf"#define\s+{nombre}\s+(\w+)", (RAIZ / ruta).read_text())
    return int(m.group(1), 0)


def atributos_de_tilesets():
    """gTileset_X -> lista de atributos de sus metatiles."""
    cabeceras = (RAIZ / "src/data/tilesets/headers.h").read_text()
    metatiles = (RAIZ / "src/data/tilesets/metatiles.h").read_text()
    rutas = dict(re.findall(r"(gMetatileAttributes_\w+)\[\]\s*=\s*INCBIN_U16\(\"([^\"]+)\"\)", metatiles))
    tilesets = {}
    for nombre, cuerpo in re.findall(r"const struct Tileset (gTileset_\w+)\s*=\s*\{(.*?)\};", cabeceras, re.S):
        m = re.search(r"\.metatileAttributes\s*=\s*(\w+)", cuerpo)
        if m and m.group(1) in rutas:
            tilesets[nombre] = leer_u16(RAIZ / rutas[m.group(1)])
    return tilesets


class Elevaciones:
    def __init__(self, primario, secundario, en_primario, nombres, surf):
        self.primario, self.secundario = primario, secundario
        self.en_primario = en_primario
        self.nombres, self.surf = nombres, surf

    def atributos(self, metatile):
        if metatile < self.en_primario:
            tabla, i = self.primario, metatile
        else:
            tabla, i = self.secundario, metatile - self.en_primario
        return tabla[i] if i < len(tabla) else None

    def de_metatile(self, metatile):
        attr = self.atributos(metatile)
        if attr is None:
            return None
        nivel = (attr & ATTR_NIVEL) >> ATTR_NIVEL_SHIFT
        if nivel != NIVEL_AUTO:
            return nivel - NIVEL_0
        behavior = self.nombres.get(attr & ATTR_BEHAVIOR, "")
        if behavior in self.surf:
            return 1
        if behavior in PUENTES:
            return MAX_ELEVATION_LEVEL
        return 3


def convertir(bloque):
    colision = NUEVO_COLISION if bloque & VIEJO_COLISION else 0
    return (bloque & VIEJO_ID) | colision


def objetos_por_layout():
    """LAYOUT_X -> [(mapa, x, y, grafico)] de los object_events de sus mapas."""
    objetos = {}
    for ruta in sorted((RAIZ / "data/maps").glob("*/map.json")):
        mapa = json.loads(ruta.read_text())
        for obj in mapa.get("object_events") or []:
            objetos.setdefault(mapa["layout"], []).append(
                (mapa["name"], obj["x"], obj["y"], obj["graphics_id"]))
    return objetos


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--escribir", action="store_true", help="convierte los .bin (sin esto, solo informa)")
    args = p.parse_args()

    nombres = comportamientos()
    surf = surfeables()
    tilesets = atributos_de_tilesets()
    en_primario = define("include/fieldmap.h", "NUM_METATILES_IN_PRIMARY")
    objetos = objetos_por_layout()
    layouts = json.loads((RAIZ / "data/layouts/layouts.json").read_text())["layouts"]

    avisos = 0
    for layout in layouts:
        if "blockdata_filepath" not in layout:
            continue
        ancho = layout["width"]
        elev = Elevaciones(tilesets[layout["primary_tileset"]], tilesets[layout["secondary_tileset"]],
                           en_primario, nombres, surf)
        ruta_mapa = RAIZ / layout["blockdata_filepath"]
        ruta_borde = RAIZ / layout["border_filepath"]
        mapa, borde = leer_u16(ruta_mapa), leer_u16(ruta_borde)

        cambian_pisables, cambian_bloqueadas = [], {}
        for i, bloque in enumerate(mapa):
            metatile = bloque & VIEJO_ID
            antes = bloque >> VIEJO_ELEVACION_SHIFT
            despues = elev.de_metatile(metatile)
            if despues is None or despues == antes:
                continue
            x, y = i % ancho, i // ancho
            if bloque & VIEJO_COLISION:
                cambian_bloqueadas[(x, y)] = (metatile, antes, despues)
            else:
                cambian_pisables.append((x, y, metatile, antes, despues))

        print(f"{layout['id']}: {len(mapa)} casillas, borde {len(borde)}")
        for x, y, metatile, antes, despues in cambian_pisables:
            print(f"  AVISO ({x},{y}) metatile {metatile:#x}: se pisa y pasa de altura {antes} a {despues}")
            avisos += 1
        if cambian_bloqueadas:
            print(f"  {len(cambian_bloqueadas)} casillas bloqueadas cambian de altura (no se pisan)")
        for mapa_nombre, x, y, grafico in objetos.get(layout["id"], []):
            if (x, y) in cambian_bloqueadas:
                metatile, antes, despues = cambian_bloqueadas[(x, y)]
                print(f"  AVISO {mapa_nombre}: {grafico} en ({x},{y}) esta en una casilla bloqueada"
                      f" que pasa de altura {antes} a {despues}")
                avisos += 1

        if args.escribir:
            escribir_u16(ruta_mapa, [convertir(b) for b in mapa])
            escribir_u16(ruta_borde, [convertir(b) for b in borde])

    print(f"{avisos} avisos." + ("" if args.escribir else " No se ha escrito nada: falta --escribir."))
    return 0


if __name__ == "__main__":
    sys.exit(main())

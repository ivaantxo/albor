#!/usr/bin/env python3
"""Importa en lote los sprites animados de Negro/Blanco desde WikiDex.

Para cada especie de species.txt busca su GIF en la wiki, elige cuatro fotogramas
con papeles definidos, los encaja en 96x96 y escribe el PNG indexado y la paleta
en desarrollo/pokemon/<especie>/, listo para copiar sobre graphics/pokemon.

Los cuatro fotogramas no se eligen "por ser distintos", sino por el papel que
tienen que cumplir en la animacion:

    0  reposo       el fotograma de partida
    1  vaiven       el mayor movimiento ordinario, el que se repite
    2  especial     la pose mas extrema de toda la animacion
    3  transicion   un paso intermedio para volver al reposo sin cortes

que es lo que luego reproduce el guion: 0,1 varias veces y cada tanto 2,3.

Uso:
    lote_bw.py                     todas las especies
    lote_bw.py --solo bulbasaur venusaur
    lote_bw.py --limite 10         las diez primeras, para probar
    lote_bw.py --solo-informe      no descarga ni escribe, dice que haria
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from usa_entorno import asegura_pillow
asegura_pillow()

import argparse
import json
import re
import time
import unicodedata
import urllib.parse
import urllib.request
from PIL import Image

API = "https://www.wikidex.net/api.php"
CATEGORIA = "Categoría:Sprites animados de Pokémon Negro y Blanco"
AGENTE = "albor-importador/1.0 (proyecto personal de romhacking)"
ESPERA = 0.35                      # segundos entre peticiones, por educacion

LADO = 96
COLORES = 16
TRANSPARENTE = (255, 0, 255)       # magenta, el mismo para todas las especies

# Formas cuyo nombre en la wiki no se deduce del de la enum.
EQUIVALENCIAS = {
    "NIDORAN_F": "Nidoran hembra",
    "NIDORAN_M": "Nidoran macho",
    "CASTFORM_SUNNY": "Castform sol",
    "CASTFORM_RAINY": "Castform lluvia",
    "CASTFORM_SNOWY": "Castform nieve",
    "DEOXYS_NORMAL": "Deoxys",
    "DEOXYS_ATTACK": "Deoxys ataque",
    "DEOXYS_DEFENSE": "Deoxys defensa",
    "DEOXYS_SPEED": "Deoxys velocidad",
    "ROTOM_HEAT": "Rotom calor",
    "ROTOM_WASH": "Rotom lavado",
    "ROTOM_FROST": "Rotom frío",
    "ROTOM_FAN": "Rotom ventilador",
    "ROTOM_MOW": "Rotom corte",
}


# --------------------------------------------------------------- utilidades

def normaliza(s):
    """Deja un nombre en mayusculas sin acentos ni signos, para comparar."""
    s = unicodedata.normalize("NFD", s)
    s = "".join(c for c in s if unicodedata.category(c) != "Mn")
    s = s.replace("♀", "_F").replace("♂", "_M")
    return re.sub(r"[^A-Za-z0-9]+", "_", s).strip("_").upper()


def pide(parametros):
    url = API + "?" + urllib.parse.urlencode(parametros)
    peticion = urllib.request.Request(url, headers={"User-Agent": AGENTE})
    return json.load(urllib.request.urlopen(peticion, timeout=30))


def catalogo():
    """Todos los ficheros de la categoria, en un diccionario nombre -> titulo."""
    titulos, sigue = [], None
    while True:
        p = {"action": "query", "list": "categorymembers", "cmtitle": CATEGORIA,
             "cmlimit": "500", "format": "json"}
        if sigue:
            p["cmcontinue"] = sigue
        d = pide(p)
        titulos += [m["title"] for m in d["query"]["categorymembers"]]
        sigue = d.get("continue", {}).get("cmcontinue")
        if not sigue:
            break
        time.sleep(ESPERA)

    machos, hembras = {}, {}
    for t in titulos:
        base = t[len("Archivo:"):]
        if base.endswith(" NB hembra.gif"):
            hembras[normaliza(base[:-len(" NB hembra.gif")])] = t
        elif base.endswith(" NB.gif"):
            machos[normaliza(base[:-len(" NB.gif")])] = t
    return machos, hembras


def url_de(titulo):
    d = pide({"action": "query", "titles": titulo, "prop": "imageinfo",
              "iiprop": "url", "format": "json"})
    for pagina in d["query"]["pages"].values():
        info = pagina.get("imageinfo")
        if info:
            return info[0]["url"]
    return None


def descarga(url, destino):
    peticion = urllib.request.Request(url, headers={"User-Agent": AGENTE})
    with urllib.request.urlopen(peticion, timeout=60) as r:
        open(destino, "wb").write(r.read())


def especies_del_proyecto():
    salida = []
    for linea in open("species.txt"):
        m = re.match(r"\s*(SPECIES_[A-Z0-9_]+)\s*,", linea)
        if m and m.group(1) not in ("SPECIES_NONE", "SPECIES_EGG"):
            salida.append(m.group(1))
    return salida


# ------------------------------------------------------- lectura y eleccion

def fotogramas_de(ruta):
    """Los fotogramas del GIF, ya compuestos por Pillow (no componer a mano)."""
    img = Image.open(ruta)
    salida = []
    for n in range(getattr(img, "n_frames", 1)):
        img.seek(n)
        salida.append(img.convert("RGBA").copy())
    return salida


def distancia(a, b):
    pa, pb = a.load(), b.load()
    n = 0
    for y in range(a.height):
        for x in range(a.width):
            if pa[x, y] != pb[x, y]:
                n += 1
    return n


def elige_cuatro(marcos):
    """Reposo, vaiven, especial y transicion. Devuelve cuatro indices.

    El reposo es siempre el primero, que es como arrancan estas animaciones. El
    especial es la pose que mas se aleja de el. El vaiven es el mayor movimiento
    que NO llega a ser el especial, y por eso se busca solo entre los que se
    quedan por debajo de la mitad de esa distancia: si se cogiera el segundo mas
    lejano saldria casi el mismo gesto y el bucle no se notaria. La transicion se
    busca despues del especial en el tiempo, a media distancia del reposo, que es
    justo el paso intermedio para volver sin cortes.
    """
    if len(marcos) == 1:
        return [0, 0, 0, 0]

    d = [distancia(m, marcos[0]) for m in marcos]
    especial = max(range(len(marcos)), key=lambda i: d[i])
    if d[especial] == 0:
        return [0, 0, 0, 0]

    umbral = d[especial] / 2
    ordinarios = [i for i in range(len(marcos)) if 0 < d[i] <= umbral]
    vaiven = max(ordinarios, key=lambda i: d[i]) if ordinarios else especial

    posteriores = list(range(especial + 1, len(marcos))) + list(range(0, especial))
    transicion = (min(posteriores, key=lambda i: abs(d[i] - umbral))
                  if posteriores else vaiven)

    return [0, vaiven, especial, transicion]


# ------------------------------------------------------- encaje y paleta

def caja_de(marcos):
    cajas = [m.getbbox() for m in marcos if m.getbbox()]
    if not cajas:
        return None
    return (min(c[0] for c in cajas), min(c[1] for c in cajas),
            max(c[2] for c in cajas), max(c[3] for c in cajas))


def encaja(marcos):
    """Centrado en horizontal y apoyado al suelo. Devuelve None y la causa si no cabe."""
    caja = caja_de(marcos)
    if caja is None:
        return None, "el sprite esta vacio"

    ancho, alto = caja[2] - caja[0], caja[3] - caja[1]
    if ancho > LADO:
        return None, "exceso de ancho: %d px, caben %d" % (ancho, LADO)
    if alto > LADO:
        return None, "exceso de alto: %d px, caben %d" % (alto, LADO)

    x, y = (LADO - ancho) // 2, LADO - alto
    salida = []
    for m in marcos:
        lienzo = Image.new("RGBA", (LADO, LADO), (0, 0, 0, 0))
        lienzo.paste(m.crop(caja), (x, y))
        salida.append(lienzo)
    return salida, None


def colores_de(marcos):
    vistos = []
    for m in marcos:
        px = m.load()
        for y in range(m.height):
            for x in range(m.width):
                r, g, b, a = px[x, y]
                if a >= 128 and (r, g, b) not in vistos:
                    vistos.append((r, g, b))
    return vistos


def indexa(marcos, paleta):
    tira = Image.new("P", (LADO, LADO * len(marcos)))
    plana = []
    for c in paleta:
        plana.extend(c)
    tira.putpalette(plana)

    directo = {c: i for i, c in enumerate(paleta)}
    for n, m in enumerate(marcos):
        px = m.load()
        for y in range(LADO):
            for x in range(LADO):
                r, g, b, a = px[x, y]
                tira.putpixel((x, n * LADO + y),
                              0 if a < 128 else directo.get((r, g, b), 0))
    return tira


def escribe_paleta(ruta, paleta):
    with open(ruta, "w") as f:
        f.write("JASC-PAL\n0100\n%d\n" % COLORES)
        for c in paleta:
            f.write("%d %d %d\n" % c)


# ------------------------------------------------------------------ especie

def procesa(especie, machos, hembras, destino_raiz, cache, solo_informe):
    """Devuelve (estado, detalle). Estado: 'bien', 'sin sprite' o 'no cabe'."""
    corto = especie[len("SPECIES_"):]
    clave = normaliza(EQUIVALENCIAS.get(corto, corto))

    if clave not in machos:
        return "sin sprite", "no hay sprite de Negro/Blanco en la wiki"

    carpeta = os.path.join(destino_raiz, corto.lower())
    trabajos = [("anim_front.png", machos[clave])]
    if clave in hembras:
        trabajos.append(("anim_frontf.png", hembras[clave]))

    # Macho y hembra se procesan juntos porque en el juego comparten la ranura de
    # paleta del combatiente: si cada uno trajera la suya, el segundo se dibujaria
    # con los colores del primero. Se construye una paleta comun con los colores de
    # los dos y solo se separan si no caben en 16.
    conjuntos = []
    for nombre, titulo in trabajos:
        if solo_informe:
            conjuntos.append((nombre, None))
            continue

        gif = os.path.join(cache, titulo[len("Archivo:"):])
        if not os.path.exists(gif):
            url = url_de(titulo)
            if url is None:
                return "sin sprite", "la wiki no da URL para %s" % titulo
            descarga(url, gif)
            time.sleep(ESPERA)

        marcos = fotogramas_de(gif)
        elegidos = [marcos[i] for i in elige_cuatro(marcos)]
        encajados, causa = encaja(elegidos)
        if encajados is None:
            return "no cabe", "%s: %s" % (nombre, causa)
        conjuntos.append((nombre, encajados))

    if solo_informe:
        return "bien", "%d fichero(s)" % len(trabajos)

    # Primero se intenta que compartan paleta, que es lo habitual. Si entre los dos
    # se pasan de 16, la hembra se lleva la suya: el motor lo admite (paletteFemale)
    # y es mejor que renunciar a la especie entera.
    def paleta_de(marcos, quien):
        colores = colores_de(marcos)
        if len(colores) > COLORES - 1:
            return None, ("exceso de colores en %s: %d, caben %d"
                          % (quien, len(colores), COLORES - 1))
        p = [TRANSPARENTE] + colores
        return p + [(0, 0, 0)] * (COLORES - len(p)), None

    todos = [m for _, marcos in conjuntos for m in marcos]
    compartida, _ = paleta_de(todos, "el conjunto")

    os.makedirs(carpeta, exist_ok=True)

    if compartida is not None:
        for nombre, marcos in conjuntos:
            indexa(marcos, compartida).save(os.path.join(carpeta, nombre))
        escribe_paleta(os.path.join(carpeta, "normal.pal"), compartida)
        return "bien", ("%d fichero(s), %d colores"
                        % (len(trabajos), sum(1 for c in compartida if c != (0, 0, 0))))

    aparte = []
    for nombre, marcos in conjuntos:
        quien = "la hembra" if "frontf" in nombre else "el macho"
        propia, causa = paleta_de(marcos, quien)
        if propia is None:
            return "no cabe", causa
        indexa(marcos, propia).save(os.path.join(carpeta, nombre))
        destino_pal = "normalf.pal" if "frontf" in nombre else "normal.pal"
        escribe_paleta(os.path.join(carpeta, destino_pal), propia)
        aparte.append(destino_pal)

    return "bien", "%d fichero(s), paletas separadas (%s)" % (len(trabajos), ", ".join(aparte))


def escribe_guiones(ruta, hechas):
    """Los sAnim_ de las especies procesadas, para revisar y pegar aparte.

    El patron repite el vaiven tres veces por cada aparicion del gesto especial,
    que es como se comportan los de BW: movimiento continuo y, de tarde en tarde,
    algo mas llamativo.
    """
    with open(ruta, "w") as f:
        f.write("// Generado por tools/importador_bw/lote_bw.py\n")
        f.write("// Revisar y pegar en src/data/pokemon/front_pic_anims.h.\n")
        f.write("//\n")
        f.write("// 0 reposo, 1 vaiven, 2 especial, 3 transicion.\n\n")
        for especie in hechas:
            nombre = especie[len("SPECIES_"):].title().replace("_", "")
            f.write("static const union AnimCmd sAnim_%s[] =\n{\n" % nombre)
            for _ in range(3):
                f.write("    ANIMCMD_FRAME(0, 10),\n    ANIMCMD_FRAME(1, 10),\n")
            f.write("    ANIMCMD_FRAME(2, 12),\n    ANIMCMD_FRAME(3, 10),\n")
            f.write("    ANIMCMD_JUMP(0),\n};\n\n")


def main():
    p = argparse.ArgumentParser(description="Importa en lote los sprites de BW.")
    p.add_argument("--destino", default="desarrollo/pokemon")
    p.add_argument("--cache", default="desarrollo/.gif_bw",
                   help="donde se guardan los GIF descargados, para no repetir")
    p.add_argument("--solo", nargs="*", help="solo estas especies, por nombre corto")
    p.add_argument("--limite", type=int, help="procesar como mucho N especies")
    p.add_argument("--solo-informe", action="store_true")
    args = p.parse_args()

    print("Pidiendo el catalogo a WikiDex...")
    machos, hembras = catalogo()
    print("  %d sprites, de ellos %d variantes hembra\n" % (len(machos), len(hembras)))

    especies = especies_del_proyecto()
    if args.solo:
        quiere = {normaliza(s) for s in args.solo}
        especies = [e for e in especies if normaliza(e[len("SPECIES_"):]) in quiere]
    if args.limite:
        especies = especies[:args.limite]

    if not args.solo_informe:
        os.makedirs(args.cache, exist_ok=True)

    hechas, sin_sprite, no_caben = [], [], []
    for n, especie in enumerate(especies, 1):
        try:
            estado, detalle = procesa(especie, machos, hembras, args.destino,
                                      args.cache, args.solo_informe)
        except Exception as e:                    # una especie rota no para el lote
            estado, detalle = "no cabe", "error inesperado: %s" % e

        marca = {"bien": "  ok  ", "sin sprite": " ---- ", "no cabe": " FALLO"}[estado]
        print("[%3d/%3d]%s %-22s %s" % (n, len(especies), marca,
                                        especie[len("SPECIES_"):].lower(), detalle))
        sys.stdout.flush()
        (hechas if estado == "bien" else
         sin_sprite if estado == "sin sprite" else no_caben).append((especie, detalle))

    print("\n" + "=" * 70)
    print("PROCESADAS BIEN : %d" % len(hechas))
    print("SIN SPRITE EN BW: %d  (formas regionales y especies de 6a en adelante)"
          % len(sin_sprite))
    print("NO CABEN        : %d" % len(no_caben))

    if no_caben:
        print("\n--- las que no caben, con la causa ---")
        for especie, causa in no_caben:
            print("  %-22s %s" % (especie[len("SPECIES_"):].lower(), causa))

    if sin_sprite:
        print("\n--- sin sprite en Negro/Blanco ---")
        print("  " + ", ".join(e[len("SPECIES_"):].lower() for e, _ in sin_sprite))

    if hechas and not args.solo_informe:
        ruta = os.path.join(args.destino, "anims_generados.h")
        escribe_guiones(ruta, [e for e, _ in hechas])
        print("\nGuiones de animacion en %s" % ruta)


if __name__ == "__main__":
    main()

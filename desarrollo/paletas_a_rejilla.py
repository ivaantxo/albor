#!/usr/bin/env python3
"""Lleva las paletas del repositorio a los colores que el GBA ensena de verdad.

La consola guarda cinco bits por canal: 32 niveles, no 256. gbagfx baja el valor
truncando -v // 8- y lo vuelve a subir con (v * 255) // 31, asi que de los 256
valores que caben en un .pal o en un PNG solo 32 llegan a la pantalla. Los demas
se caen al escalon de abajo, siempre hacia el lado oscuro y hasta siete puntos.

Esto reescribe cada color en su escalon. NO cambia lo que se ve en la consola:
el .gbapal que sale de gbagfx es byte a byte el mismo antes y despues, porque el
valor de cinco bits no se toca. Lo que cambia es que el archivo deja de mentir:
lo que abres en Aseprite pasa a ser lo que se ve jugando.

Tambien avisa de las paletas donde dos entradas DISTINTAS acaban siendo el mismo
color en la consola. Eso no lo arregla este programa y no se puede arreglar
reescribiendo nada: el dibujo se hizo con diferencias que el hardware no puede
ensenar. Recuperarlas es volver a elegir esos colores a mano.

    python3 desarrollo/paletas_a_rejilla.py                 # solo mirar
    python3 desarrollo/paletas_a_rejilla.py --aplicar       # escribir
    python3 desarrollo/paletas_a_rejilla.py graphics/pokemon --aplicar

Solo toca .pal con cabecera JASC-PAL y PNG indexados -su bloque PLTE-. Los .pla
no son paletas, son listas de indices, y se quedan como estan.
"""

from __future__ import annotations

import argparse
import struct
import zlib
from pathlib import Path

# Los 32 valores de 8 bits que sobreviven al viaje de ida y vuelta de gbagfx.
REJILLA = [(v5 * 255) // 31 for v5 in range(32)]

FIRMA_PNG = b"\x89PNG\r\n\x1a\n"


def a_rejilla(valor: int) -> int:
    return REJILLA[min(valor // 8, 31)]


def cinco_bits(color) -> tuple:
    return tuple(min(v // 8, 31) for v in color)


def colisiones(colores: list[tuple]) -> list[list[tuple]]:
    """Grupos de colores distintos que la consola ensena iguales."""
    por_escalon: dict[tuple, set] = {}
    for color in colores:
        por_escalon.setdefault(cinco_bits(color), set()).add(tuple(color))
    return [sorted(v) for v in por_escalon.values() if len(v) > 1]


def ajusta_jasc(ruta: Path) -> tuple[bytes | None, list, list]:
    """Devuelve (contenido nuevo o None, colores, colisiones)."""
    texto = ruta.read_text(errors="replace")
    lineas = texto.splitlines()
    if not lineas or lineas[0].strip() != "JASC-PAL":
        return None, [], []

    colores, salida, movidos = [], lineas[:3], []
    for linea in lineas[3:]:
        partes = linea.split()
        if len(partes) != 3 or not all(p.isdigit() for p in partes):
            salida.append(linea)
            continue
        color = tuple(int(p) for p in partes)
        nuevo = tuple(a_rejilla(v) for v in color)
        colores.append(color)
        if nuevo != color:
            movidos.append((color, nuevo))
        salida.append(" ".join(str(v) for v in nuevo))

    if not movidos:
        return None, colores, colisiones(colores)
    final = "\n".join(salida)
    if texto.endswith("\n"):
        final += "\n"
    return final.encode(), colores, colisiones(colores)


def ajusta_png(ruta: Path) -> tuple[bytes | None, list, list]:
    """Parchea el bloque PLTE en su sitio, sin volver a comprimir la imagen.

    Reescribir el PNG con una biblioteca lo re-codifica entero y cambia bytes
    que no tienen nada que ver con la paleta. Aqui se sustituyen los tres bytes
    de cada color y se rehace el CRC del bloque; todo lo demas queda intacto.
    """
    datos = bytearray(ruta.read_bytes())
    if bytes(datos[:8]) != FIRMA_PNG:
        return None, [], []

    pos, colores, movidos = 8, [], False
    while pos + 8 <= len(datos):
        largo = struct.unpack(">I", datos[pos:pos + 4])[0]
        tipo = bytes(datos[pos + 4:pos + 8])
        inicio = pos + 8
        if tipo == b"PLTE":
            for i in range(inicio, inicio + largo - 2, 3):
                color = tuple(datos[i:i + 3])
                nuevo = tuple(a_rejilla(v) for v in color)
                colores.append(color)
                if nuevo != color:
                    datos[i:i + 3] = bytes(nuevo)
                    movidos = True
            if movidos:
                crc = zlib.crc32(bytes(datos[pos + 4:inicio + largo]))
                datos[inicio + largo:inicio + largo + 4] = struct.pack(">I", crc)
            break
        if tipo == b"IDAT":
            break  # la paleta va siempre antes; si llegamos aqui, no hay
        pos = inicio + largo + 4

    return (bytes(datos) if movidos else None), colores, colisiones(colores)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("raices", nargs="*", default=["graphics"],
                        help="carpetas a recorrer (por omision: graphics)")
    parser.add_argument("--aplicar", action="store_true",
                        help="escribir los cambios; sin esto solo se informa")
    args = parser.parse_args()

    tocados = revisados = colores_movidos = 0
    con_colision: list[tuple[Path, list]] = []

    for raiz in args.raices:
        for ruta in sorted(Path(raiz).rglob("*")):
            if ruta.suffix == ".pal":
                nuevo, colores, choques = ajusta_jasc(ruta)
            elif ruta.suffix == ".png":
                nuevo, colores, choques = ajusta_png(ruta)
            else:
                continue

            revisados += 1
            if choques:
                con_colision.append((ruta, choques))
            if nuevo is None:
                continue
            tocados += 1
            colores_movidos += sum(1 for c in colores
                                   if tuple(a_rejilla(v) for v in c) != tuple(c))
            if args.aplicar:
                ruta.write_bytes(nuevo)

    print(f"archivos con paleta revisados : {revisados}")
    print(f"archivos fuera de la rejilla  : {tocados}"
          f"  ({colores_movidos} colores)")
    print("escritos                      : "
          + (str(tocados) if args.aplicar else "0 (falta --aplicar)"))
    print(f"\npaletas donde la consola funde dos colores distintos: {len(con_colision)}")
    for ruta, choques in con_colision[:15]:
        print(f"   {ruta}: {choques}")
    if len(con_colision) > 15:
        print(f"   ... y {len(con_colision) - 15} mas")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

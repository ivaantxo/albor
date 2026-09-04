#!/usr/bin/env python3
"""Instala en graphics/pokemon lo generado en desarrollo/pokemon.

No es una copia a secas. La paleta de una especie la comparten el sprite frontal,
el de espalda, el follower y el icono, asi que al traer una paleta nueva de BW hay
que REINDEXAR todo lo demas o se dibujaria con colores que ya no significan lo
mismo. Eso es lo que costo media tarde descubrir con el back de Bulbasaur.

Uso:
    instalar.py --solo-informe      dice que haria, sin tocar nada
    instalar.py                     lo hace
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from usa_entorno import asegura_pillow
asegura_pillow()

import argparse
import re
import shutil
from PIL import Image

ORIGEN = "desarrollo/pokemon"
DESTINO = "graphics/pokemon"
COLORES = 16

# Las formas alternativas no tienen carpeta propia: cuelgan de la especie base.
SUBCARPETAS = {}
for base, formas in (("castform", ("sunny", "rainy", "snowy")),
                     ("deoxys", ("attack", "defense", "speed")),
                     ("rotom", ("heat", "wash", "frost", "fan", "mow"))):
    for f in formas:
        SUBCARPETAS["%s_%s" % (base, f)] = os.path.join(base, f)
SUBCARPETAS["deoxys_normal"] = "deoxys"     # la forma normal es la carpeta base

# Lo que hay que reindexar a la paleta nueva, y a cual de las dos.
REINDEXAR = [
    ("back.png", "normal.pal"),
    ("follower.png", "normal.pal"),
    ("backf.png", "normalf.pal"),
    ("followerf.png", "normalf.pal"),
]


def lee_pal(ruta):
    lineas = [l.strip() for l in open(ruta) if l.strip()]
    return [tuple(int(v) for v in l.split()) for l in lineas[3:]]


def escribe_pal(ruta, paleta):
    with open(ruta, "w") as f:
        f.write("JASC-PAL\n0100\n%d\n" % COLORES)
        for c in paleta:
            f.write("%d %d %d\n" % c)


def mas_parecido(rgb, paleta):
    mejor, mejorD = 1, None
    for i in range(1, len(paleta)):
        p = paleta[i]
        d = (rgb[0]-p[0])**2 + (rgb[1]-p[1])**2 + (rgb[2]-p[2])**2
        if mejorD is None or d < mejorD:
            mejor, mejorD = i, d
    return mejor


def reindexa(ruta, paleta):
    """Mismo dibujo, colores nuevos. No toca tamano ni encuadre."""
    origen = Image.open(ruta).convert("RGBA")
    salida = Image.new("P", origen.size)
    plana = []
    for c in paleta:
        plana.extend(c)
    salida.putpalette(plana)

    directo = {c: i for i, c in enumerate(paleta)}
    px = origen.load()
    for y in range(origen.height):
        for x in range(origen.width):
            r, g, b, a = px[x, y]
            if a < 128 or (r, g, b) == paleta[0]:
                indice = 0
            else:
                indice = directo.get((r, g, b))
                if indice is None or indice == 0:
                    indice = mas_parecido((r, g, b), paleta)
            salida.putpixel((x, y), indice)
    salida.save(ruta)


def completas():
    salida = []
    for nombre in sorted(os.listdir(ORIGEN)):
        d = os.path.join(ORIGEN, nombre)
        if (os.path.isdir(d) and os.path.exists(os.path.join(d, "anim_front.png"))
                and os.path.exists(os.path.join(d, "normal.pal"))):
            salida.append(nombre)
    return salida


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--solo-informe", action="store_true")
    args = p.parse_args()

    especies = completas()
    print("Especies completas en %s: %d\n" % (ORIGEN, len(especies)))

    instaladas, sin_carpeta, reindexados = 0, [], 0
    for nombre in especies:
        org = os.path.join(ORIGEN, nombre)
        dst = os.path.join(DESTINO, SUBCARPETAS.get(nombre, nombre))

        if not os.path.isdir(dst):
            # Especie que aun no esta implementada en el proyecto: se deja el arte
            # preparado para cuando la anadas, y se avisa al final.
            sin_carpeta.append(nombre)
            if args.solo_informe:
                continue
            os.makedirs(dst, exist_ok=True)

        if args.solo_informe:
            instaladas += 1
            continue

        for f in ("anim_front.png", "normal.pal", "anim_frontf.png", "normalf.pal"):
            if os.path.exists(os.path.join(org, f)):
                shutil.copy2(os.path.join(org, f), os.path.join(dst, f))

        # La shiny queda como copia de la normal: no es la definitiva, pero asi los
        # variocolor se ven como los normales en vez de como un destrozo de colores
        # mientras las rehaces a mano.
        shutil.copy2(os.path.join(dst, "normal.pal"), os.path.join(dst, "shiny.pal"))
        if os.path.exists(os.path.join(dst, "normalf.pal")):
            shutil.copy2(os.path.join(dst, "normalf.pal"),
                         os.path.join(dst, "shinyf.pal"))

        for fichero, cual in REINDEXAR:
            ruta = os.path.join(dst, fichero)
            pal = os.path.join(dst, cual)
            if not os.path.exists(pal):                 # sin paleta hembra propia,
                pal = os.path.join(dst, "normal.pal")   # va a la comun
            if os.path.exists(ruta):
                reindexa(ruta, lee_pal(pal))
                reindexados += 1

        instaladas += 1
        if instaladas % 50 == 0:
            print("  %d especies..." % instaladas)

    print("\n" + "=" * 60)
    print("INSTALADAS       : %d" % instaladas)
    print("REINDEXADOS      : %d ficheros (back, follower y sus variantes)" % reindexados)
    if sin_carpeta:
        print("SIN CARPETA EN graphics/pokemon: %d" % len(sin_carpeta))
        print("  " + ", ".join(sin_carpeta))


if __name__ == "__main__":
    main()

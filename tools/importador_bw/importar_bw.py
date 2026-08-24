#!/usr/bin/env python3
"""Importa sprites animados de BW/B2W2 al formato de graficos del proyecto.

Coge una animacion (GIF animado, hoja de sprites o carpeta de PNG numerados),
la encaja en el lienzo del juego, elige los fotogramas mas representativos y
escribe el PNG indexado y la paleta que espera la cadena de gbagfx.

Uso tipico:

    importar_bw.py venusaur.gif --especie venusaur --frames 4
    importar_bw.py hoja.png --especie pikachu --rejilla 96x96 --lado back
    importar_bw.py carpeta/ --especie gengar --paleta-existente

Con --solo-informe no escribe nada: dice que haria y que problemas ve.
"""

import argparse
import os
import sys
from PIL import Image, ImageSequence

COLOR_TRANSPARENTE_POR_DEFECTO = (152, 160, 208)   # el que usa el proyecto
COLORES_MAXIMOS = 16                                # 4bpp


# ---------------------------------------------------------------- entrada

def carga_fotogramas(ruta, rejilla):
    """Devuelve una lista de imagenes RGBA, venga de donde venga la entrada."""
    if os.path.isdir(ruta):
        nombres = sorted(n for n in os.listdir(ruta)
                         if n.lower().endswith((".png", ".gif", ".bmp")))
        if not nombres:
            raise SystemExit("No hay imagenes en %s" % ruta)
        return [Image.open(os.path.join(ruta, n)).convert("RGBA") for n in nombres]

    img = Image.open(ruta)

    if getattr(img, "n_frames", 1) > 1:
        # GIF animado: hay que componer cada fotograma sobre el anterior, porque
        # muchos guardan solo lo que cambia.
        salida, lienzo = [], None
        for marco in ImageSequence.Iterator(img):
            marco = marco.convert("RGBA")
            if lienzo is None:
                lienzo = marco.copy()
            else:
                lienzo = lienzo.copy()
                lienzo.alpha_composite(marco)
            salida.append(lienzo.copy())
        return salida

    img = img.convert("RGBA")
    if rejilla:
        ancho, alto = rejilla
        cols, filas = img.width // ancho, img.height // alto
        if cols == 0 or filas == 0:
            raise SystemExit("La rejilla %dx%d no cabe en una imagen de %dx%d"
                             % (ancho, alto, img.width, img.height))
        return [img.crop((c * ancho, f * alto, (c + 1) * ancho, (f + 1) * alto))
                for f in range(filas) for c in range(cols)]

    return [img]


# ---------------------------------------------------------------- encaje

def caja_visible(img):
    """Recuadro de lo que no es transparente, o None si esta vacio."""
    return img.getbbox() if img.getbbox() else None


def caja_comun(fotogramas):
    """Recuadro que engloba todos los fotogramas.

    Se usa el comun y no el de cada uno: si cada fotograma se centrara por su
    cuenta, la animacion daria saltos al reencuadrarse sola.
    """
    cajas = [c for c in (caja_visible(f) for f in fotogramas) if c]
    if not cajas:
        raise SystemExit("Todos los fotogramas estan vacios")
    return (min(c[0] for c in cajas), min(c[1] for c in cajas),
            max(c[2] for c in cajas), max(c[3] for c in cajas))


def encaja(fotogramas, lado, anclaje):
    caja = caja_comun(fotogramas)
    ancho, alto = caja[2] - caja[0], caja[3] - caja[1]

    if ancho > lado or alto > lado:
        raise SystemExit(
            "DEMASIADO GRANDE: el contenido mide %dx%d y el lienzo es de %dx%d.\n"
            "  Recorta el original o sube el lienzo con --lienzo." % (ancho, alto, lado, lado))

    x = (lado - ancho) // 2
    y = (lado - alto) // 2 if anclaje == "centro" else lado - alto

    salida = []
    for f in fotogramas:
        lienzo = Image.new("RGBA", (lado, lado), (0, 0, 0, 0))
        lienzo.paste(f.crop(caja), (x, y))
        salida.append(lienzo)
    return salida, (ancho, alto)


# ---------------------------------------------------- eleccion de fotogramas

def diferencia(a, b):
    """Cuantos pixeles cambian entre dos fotogramas."""
    pa, pb = a.load(), b.load()
    n = 0
    for y in range(a.height):
        for x in range(a.width):
            if pa[x, y] != pb[x, y]:
                n += 1
    return n


def elige_fotogramas(fotogramas, cuantos):
    """Se queda con los mas distintos entre si.

    No basta con coger los de mayor salto respecto al anterior: en una animacion
    con un tramo rapido, esos salen todos seguidos y se pierde el resto del ciclo.
    Se empieza por el primero y cada vez se anade aquel que mas lejos esta de todo
    lo ya elegido, que es lo que de verdad reparte el ciclo.
    """
    if cuantos >= len(fotogramas):
        return list(range(len(fotogramas)))

    elegidos = [0]
    distancia = [diferencia(f, fotogramas[0]) for f in fotogramas]

    while len(elegidos) < cuantos:
        siguiente = max(range(len(fotogramas)), key=lambda i: distancia[i])
        if distancia[siguiente] == 0:
            break                                   # ya no queda nada distinto
        elegidos.append(siguiente)
        for i, f in enumerate(fotogramas):
            distancia[i] = min(distancia[i], diferencia(f, fotogramas[siguiente]))

    return sorted(elegidos)


# ---------------------------------------------------------------- paleta

def lee_paleta_jasc(ruta):
    with open(ruta) as f:
        lineas = [l.strip() for l in f if l.strip()]
    return [tuple(int(v) for v in l.split()) for l in lineas[3:]]


def escribe_paleta_jasc(ruta, colores):
    with open(ruta, "w") as f:
        f.write("JASC-PAL\n0100\n%d\n" % COLORES_MAXIMOS)
        for c in colores:
            f.write("%d %d %d\n" % c)


def saca_paleta(fotogramas, transparente):
    """Los colores que usa la animacion, con el transparente en el indice 0."""
    vistos = []
    for f in fotogramas:
        pixeles = f.load()
        for y in range(f.height):
            for x in range(f.width):
                r, g, b, a = pixeles[x, y]
                if a < 128:
                    continue
                if (r, g, b) not in vistos:
                    vistos.append((r, g, b))

    if len(vistos) > COLORES_MAXIMOS - 1:
        raise SystemExit(
            "DEMASIADOS COLORES: la animacion usa %d y solo caben %d mas el "
            "transparente.\n  Reduce la paleta en el original." % (len(vistos), COLORES_MAXIMOS - 1))

    paleta = [transparente] + vistos
    return paleta + [(0, 0, 0)] * (COLORES_MAXIMOS - len(paleta))


def mas_parecido(rgb, paleta):
    mejor, mejorD = 1, None
    for i in range(1, len(paleta)):                 # el 0 es el transparente
        p = paleta[i]
        d = (rgb[0] - p[0]) ** 2 + (rgb[1] - p[1]) ** 2 + (rgb[2] - p[2]) ** 2
        if mejorD is None or d < mejorD:
            mejor, mejorD = i, d
    return mejor


def indexa(fotogramas, paleta, lado):
    """Apila los fotogramas en un PNG indexado, uno debajo de otro."""
    tira = Image.new("P", (lado, lado * len(fotogramas)))
    plana = []
    for c in paleta:
        plana.extend(c)
    tira.putpalette(plana)

    directo = {c: i for i, c in enumerate(paleta)}
    for n, f in enumerate(fotogramas):
        pixeles = f.load()
        for y in range(lado):
            for x in range(lado):
                r, g, b, a = pixeles[x, y]
                if a < 128:
                    indice = 0
                else:
                    indice = directo.get((r, g, b))
                    if indice is None or indice == 0:
                        indice = mas_parecido((r, g, b), paleta)
                tira.putpixel((x, n * lado + y), indice)
    return tira


# ---------------------------------------------------------------- principal

def main():
    p = argparse.ArgumentParser(description="Importa sprites animados de BW/B2W2.")
    p.add_argument("entrada", help="GIF animado, hoja de sprites, o carpeta de PNG")
    p.add_argument("--especie", required=True, help="nombre en minusculas, p.ej. venusaur")
    p.add_argument("--lado", choices=["front", "back"], default="front")
    p.add_argument("--frames", type=int, default=4, help="maximo de fotogramas (por defecto 4)")
    p.add_argument("--lienzo", type=int, default=80, help="lado del lienzo (por defecto 80)")
    p.add_argument("--anclaje", choices=["centro", "suelo"], default="centro")
    p.add_argument("--rejilla", help="para hojas de sprites, p.ej. 96x96")
    p.add_argument("--raiz", default="graphics/pokemon", help="carpeta de graficos")
    p.add_argument("--paleta-existente", action="store_true",
                   help="reindexa a la paleta que ya tiene la especie en vez de crear una")
    p.add_argument("--solo-informe", action="store_true", help="no escribe nada")
    args = p.parse_args()

    rejilla = None
    if args.rejilla:
        a, _, b = args.rejilla.partition("x")
        rejilla = (int(a), int(b))

    destino = os.path.join(args.raiz, args.especie)
    ruta_pal = os.path.join(destino, "normal.pal")
    nombre = "anim_front.png" if args.lado == "front" else "back.png"

    brutos = carga_fotogramas(args.entrada, rejilla)
    print("Leidos %d fotogramas de %s" % (len(brutos), args.entrada))

    encajados, (ancho, alto) = encaja(brutos, args.lienzo, args.anclaje)
    print("Contenido de %dx%d, encajado en %dx%d (%s)"
          % (ancho, alto, args.lienzo, args.lienzo, args.anclaje))

    indices = elige_fotogramas(encajados, args.frames)
    elegidos = [encajados[i] for i in indices]
    print("Elegidos %d de %d: %s" % (len(elegidos), len(encajados), indices))

    if args.paleta_existente:
        if not os.path.exists(ruta_pal):
            raise SystemExit("No existe %s, no puedo reindexar a la paleta actual" % ruta_pal)
        paleta = lee_paleta_jasc(ruta_pal)
        print("Reindexando a la paleta existente (%d colores)" % len(paleta))
    else:
        transparente = (lee_paleta_jasc(ruta_pal)[0] if os.path.exists(ruta_pal)
                        else COLOR_TRANSPARENTE_POR_DEFECTO)
        paleta = saca_paleta(elegidos, transparente)
        print("Paleta nueva: %d colores usados, transparente %s"
              % (sum(1 for c in paleta if c != (0, 0, 0)), transparente))

    if args.solo_informe:
        print("\n(--solo-informe: no se ha escrito nada)")
        print("Escribiria: %s  y  %s" % (os.path.join(destino, nombre), ruta_pal))
        return

    tira = indexa(elegidos, paleta, args.lienzo)
    os.makedirs(destino, exist_ok=True)
    tira.save(os.path.join(destino, nombre))
    if not args.paleta_existente:
        escribe_paleta_jasc(ruta_pal, paleta)

    print("\nEscrito %s  (%dx%d)" % (os.path.join(destino, nombre), args.lienzo,
                                     args.lienzo * len(elegidos)))
    print("Recuerda poner en species_info.h:  %s_PIC(%s, %d, %d)"
          % ("FRONT" if args.lado == "front" else "BACK",
             args.especie.capitalize(), args.lienzo, args.lienzo))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Importa los sprites de HeartGold/SoulSilver desde las hojas de graficos/.

Se ejecuta ESTE fichero, no hoja.py, que es solo el modulo que sabe leer la
rejilla de las hojas.

No hace falta preparar nada: si Pillow no esta disponible, el script se relanza
solo con el entorno que ya trae tools/importador_bw. Si ese entorno tampoco
existe, lo dice y explica como crearlo.

Uso:
    importar_hgss.py --informe              que especies encuentra, sin escribir
    importar_hgss.py --solo bulbasaur       una o varias especies
    importar_hgss.py                        todas
"""

import os
import sys

RAIZ = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ENTORNO = os.path.join(RAIZ, "tools", "importador_bw", "entorno", "bin", "python")


def _relanzar_con_entorno():
    """Vuelve a arrancar con el interprete que tiene Pillow."""
    if os.environ.get("IMPORTADOR_HGSS_RELANZADO"):
        sys.exit("El entorno existe pero sigue sin Pillow:\n    %s\n"
                 "Instalalo con:\n    %s -m pip install Pillow" % (ENTORNO, ENTORNO))

    if not os.path.exists(ENTORNO):
        sys.exit("Falta Pillow y no encuentro el entorno de tools/importador_bw.\n"
                 "Crealo con:\n"
                 "    python3 -m venv tools/importador_bw/entorno\n"
                 "    tools/importador_bw/entorno/bin/pip install Pillow")

    os.environ["IMPORTADOR_HGSS_RELANZADO"] = "1"
    os.execv(ENTORNO, [ENTORNO, os.path.abspath(__file__)] + sys.argv[1:])


try:
    from PIL import Image
except ModuleNotFoundError:
    _relanzar_con_entorno()

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hoja
import minis


DESTINO = "desarrollo/pokemon"


def especies_del_proyecto():
    """Las que albor declara en species.txt."""
    import re
    fuera = set()
    for linea in open("species.txt", encoding="utf-8"):
        m = re.match(r"\s*SPECIES_(\w+),", linea)
        if m:
            fuera.add(m.group(1).lower())
    return fuera


def catalogo():
    """Cada especie de las hojas, con la imagen y el bloque donde esta."""
    primera = Image.open(os.path.join("graficos", hoja.HOJAS_GRANDES[0] + ".png")).convert("RGB")
    huecos = (primera.size[0] - hoja.X_PRIMER_BLOQUE) // hoja.ANCHO_BLOQUE + 1
    letras = hoja.aprende_letras(primera, huecos)

    fichas, nombre_de = {}, {}
    for nombre in hoja.HOJAS_GRANDES:
        ruta = os.path.join("graficos", nombre + ".png")
        if not os.path.exists(ruta):
            continue
        im = Image.open(ruta).convert("RGB")
        for bloque in hoja.bloques_de_especie(im):
            especie = hoja.especie_de_bloque(im, bloque, letras)
            if especie:
                fichas[especie] = (im, bloque)
                nombre_de[bloque.numero] = especie
    return fichas, nombre_de


def importa(especie, im, bloque):
    """Escribe anim_front, back y las dos paletas de una especie."""
    # Columnas: 0 y 1 el frente, 2 y 3 la espalda. De las especies con macho y
    # hembra se coge el macho, que es la forma por defecto del juego.
    frente = [hoja.recorta_celda(im, bloque, c, False) for c in (0, 1)]
    espalda = [hoja.recorta_celda(im, bloque, c, False) for c in (2, 3)]
    frente_vc = [hoja.recorta_celda(im, bloque, c, True) for c in (0, 1)]
    espalda_vc = [hoja.recorta_celda(im, bloque, c, True) for c in (2, 3)]

    # Cada dibujo con SU paleta, no una compartida.
    #
    # En HGSS el frente y la espalda no siempre usan los mismos colores -juntar los
    # de Charizard pide diecisiete- y aproximar uno al otro los estropea. Se dejan
    # los cuatro con sus dieciseis colores buenos y el ajuste a una sola paleta se
    # hace despues a mano, que es donde se decide que se pierde.
    perdidos = []

    def anota(color, veces):
        perdidos.append((color, veces))

    normal = hoja.paleta_de(frente, anota)
    normal_espalda = hoja.paleta_de(espalda, anota)
    variocolor = hoja.paleta_de(frente_vc, anota)
    variocolor_espalda = hoja.paleta_de(espalda_vc, anota)

    carpeta = os.path.join(DESTINO, especie)
    os.makedirs(carpeta, exist_ok=True)
    hoja.indexa(frente, normal).save(os.path.join(carpeta, "anim_front.png"))
    hoja.indexa(espalda, normal_espalda).save(os.path.join(carpeta, "back.png"))
    hoja.escribe_pal(os.path.join(carpeta, "normal.pal"), normal)
    hoja.escribe_pal(os.path.join(carpeta, "shiny.pal"), variocolor)

    # Solo si la espalda no se conforma con la paleta del frente. Asi, una carpeta
    # con estos dos ficheros es justo una que hay que mirar a mano.
    if normal_espalda != normal:
        hoja.escribe_pal(os.path.join(carpeta, "normal_back.pal"), normal_espalda)
    if variocolor_espalda != variocolor:
        hoja.escribe_pal(os.path.join(carpeta, "shiny_back.pal"), variocolor_espalda)

    return perdidos


def importa_follower(especie, im, bloque_x, bloque_y, fondo):
    """El follower de una especie: 32x32 por fotograma, en una tira horizontal.

    El primero va transparente a proposito: es el de estar quieto, y lo dibuja el
    usuario a mano. Detras van dos de frente, dos de espaldas y dos de lado, y si
    el bicho no se espeja, otros dos mirando al otro lado.
    """
    def recorta(columna, fila):
        celda = im.crop(minis.celda(bloque_x, bloque_y, columna, fila)).convert("RGB")
        if celda.size != (minis.LADO, minis.LADO):
            entera = Image.new("RGB", (minis.LADO, minis.LADO), fondo)
            entera.paste(celda, (0, 0))
            celda = entera
        pixeles = celda.load()
        for y in range(minis.LADO):
            for x in range(minis.LADO):
                if pixeles[x, y] == fondo:
                    pixeles[x, y] = hoja.MAGENTA
        return celda

    poses = [Image.new("RGB", (minis.LADO, minis.LADO), hoja.MAGENTA)]
    for grupo in (minis.FRENTE, minis.ESPALDAS, minis.DE_LADO):
        poses += [recorta(c, f) for c, f in grupo]

    otro_lado = [recorta(c, f) for c, f in minis.AL_OTRO_LADO]
    if not minis.se_espeja(poses[5], otro_lado[0]):
        poses += otro_lado

    paleta = hoja.paleta_de(poses)
    ancho = minis.LADO * len(poses)
    tira = Image.new("RGB", (ancho, minis.LADO), hoja.MAGENTA)
    for i, pose in enumerate(poses):
        tira.paste(pose, (i * minis.LADO, 0))

    carpeta = os.path.join(DESTINO, especie)
    os.makedirs(carpeta, exist_ok=True)
    hoja.indexa([tira], paleta).save(os.path.join(carpeta, "follower.png"))
    hoja.escribe_pal(os.path.join(carpeta, "follower.pal"), paleta)
    return len(poses)


def catalogo_minis(nombre_de):
    """Especie -> (imagen, esquina, fondo) para cada bloque de las hojas de minis."""
    import collections
    fichas = {}
    for nombre, primero in minis.HOJAS_MINIS:
        ruta = os.path.join("graficos", nombre + ".png")
        if not os.path.exists(ruta):
            continue
        im = Image.open(ruta).convert("RGB")
        cuenta = collections.Counter(im.getdata()).most_common(2)
        fondo = cuenta[0][0]
        # El separador es el color de la linea vertical que hay a 64 pixeles.
        separador = im.getpixel((minis.LADO * 2, minis.LADO))
        for numero, esquina in minis.bloques_de_hoja(im, primero):
            especie = nombre_de.get(numero)
            if especie:
                fichas[especie] = (im, esquina, fondo, separador)
    return fichas


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--informe", action="store_true", help="no escribe nada")
    ap.add_argument("--solo", nargs="+", metavar="ESPECIE")
    args = ap.parse_args()

    os.chdir(RAIZ)
    fichas, nombre_de = catalogo()
    minifichas = catalogo_minis(nombre_de)
    delproyecto = especies_del_proyecto()

    pedidas = set(args.solo) if args.solo else None
    hechas, saltadas, fallos, apretados = [], [], [], []
    grandes, sin_espejo = [], []

    for especie in sorted(fichas):
        if pedidas is not None and especie not in pedidas:
            continue
        if pedidas is None and especie not in delproyecto:
            saltadas.append(especie)
            continue
        if args.informe:
            hechas.append(especie)
            continue
        try:
            if especie in minifichas:
                im, (bx, by), fondo, separador = minifichas[especie]
                if minis.se_sale_de_la_celda(im, bx, by, fondo, separador):
                    grandes.append(especie)
                else:
                    cuadros = importa_follower(especie, im, bx, by, fondo)
                    if cuadros > 7:
                        sin_espejo.append(especie)
            perdidos = importa(especie, *fichas[especie])
            hechas.append(especie)
            if perdidos:
                apretados.append((especie, perdidos))
        except Exception as e:
            fallos.append((especie, e))

    print("En las hojas hay %d especies." % len(fichas))
    print("%s %d en %s." % ("Se importarian" if args.informe else "Importadas",
                            len(hechas), DESTINO))
    if saltadas:
        print("Saltadas %d que no estan en species.txt." % len(saltadas))
    sin_sprite = sorted(e for e in delproyecto if e not in fichas
                        and os.path.isdir(os.path.join("graphics/pokemon", e)))
    if sin_sprite:
        print("Sin sprite en las hojas (posteriores a la 4a generacion): %d"
              % len(sin_sprite))
    if grandes:
        print("Followers que no caben en 32x32, sin tocar: %d" % len(grandes))
        print("   %s" % ", ".join(sorted(grandes)[:10]))
    if sin_espejo:
        print("Followers que no se espejan, con nueve fotogramas: %d" % len(sin_espejo))
        print("   %s" % ", ".join(sorted(sin_espejo)[:10]))
    if apretados:
        print("Con mas de 15 colores, se quedaron los mas usados: %d" % len(apretados))
        for especie, perdidos in apretados[:8]:
            print("   %-14s %s" % (especie, perdidos))
    for especie, e in fallos:
        print("   FALLO en %s: %s" % (especie, e))


if __name__ == "__main__":
    main()

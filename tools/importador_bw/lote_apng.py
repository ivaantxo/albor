#!/usr/bin/env python3
"""Trae los sprites animados de BW de Bulbagarden y los deja listos en desarrollo.

Para cada especie escribe en desarrollo/pokemon/<especie>/ un anim_front.png y un
back.png indexados y CON LA MISMA PALETA, con tantos fotogramas como distintos
tenga la animacion y en el orden en que salen.

Uso:
    lote_apng.py --informe            dice que haria, sin escribir
    lote_apng.py --solo 1 6 143       unas cuantas, por numero de Pokedex
    lote_apng.py --hasta 493          todas
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from usa_entorno import asegura_pillow
asegura_pillow()

import argparse
import re

RAIZ = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import bulbapedia
from apng_a_pic import (fotogramas_distintos, caja_comun, lado_para,
                        paleta_compartida, monta_tira, LADOS)

DESTINO = "desarrollo/pokemon"


def nombres_por_numero():
    """Numero nacional -> carpeta.

    La tabla esta en un fichero aparte y NO se saca de species.txt: la enum del
    proyecto va ordenada por lineas evolutivas, no por Pokedex nacional -Pichu esta
    en el 25 y Espeon en el 150-, asi que usarla de indice pone los sprites en la
    especie equivocada.
    """
    import json
    ruta = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                        "nombres_nacionales.json")
    return {int(k): v for k, v in json.load(open(ruta, encoding="utf-8")).items()}


def importa(numero, carpeta, informe):
    frente_apng = bulbapedia.descarga(numero, False)
    espalda_apng = bulbapedia.descarga(numero, True)
    if frente_apng is None or espalda_apng is None:
        return "no esta en Bulbagarden"

    frente = fotogramas_distintos(frente_apng)
    espalda = fotogramas_distintos(espalda_apng)
    caja = caja_comun([frente, espalda])
    if caja is None:
        return "sin dibujo"

    ancho, alto = caja[2] - caja[0], caja[3] - caja[1]
    lado = lado_para(caja)
    colores = paleta_compartida(frente, espalda, caja)
    nota = "%dx%d -> %d%s, %d fotogramas frente y %d espalda, %d colores" % (
        ancho, alto, lado, "" if lado in LADOS else " (especial)",
        len(frente), len(espalda), len(colores))
    if len(colores) > 16:
        nota += "  OJO: pasa de 16"

    if informe:
        return nota

    ruta = os.path.join(RAIZ, DESTINO, carpeta)
    os.makedirs(ruta, exist_ok=True)
    monta_tira(frente, caja, lado, colores).save(os.path.join(ruta, "anim_front.png"))
    monta_tira(espalda, caja, lado, colores).save(os.path.join(ruta, "back.png"))
    return nota


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--informe", action="store_true")
    p.add_argument("--solo", nargs="*", type=int)
    p.add_argument("--hasta", type=int, default=493)
    args = p.parse_args()

    os.chdir(RAIZ)
    nombres = nombres_por_numero()
    cuales = args.solo if args.solo else range(1, args.hasta + 1)

    hechas = fallos = grandes = 0
    for numero in cuales:
        carpeta = nombres.get(numero, "?%03d" % numero)
        try:
            nota = importa(numero, carpeta, args.informe)
        except Exception as e:
            nota = "FALLO: %s" % e
        print("  %03d %-14s %s" % (numero, carpeta, nota))
        if nota.startswith(("FALLO", "no ")):
            fallos += 1
            if "no cabe" in nota:
                grandes += 1
        else:
            hechas += 1

    print("\n%s %d especies. Sin poder: %d (de ellas %d por tamano)."
          % ("Saldrian" if args.informe else "Hechas", hechas, fallos, grandes))


if __name__ == "__main__":
    main()

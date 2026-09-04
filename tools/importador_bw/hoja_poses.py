#!/usr/bin/env python3
"""Deja a la vista las animaciones de BW de una especie, para elegir poses a mano.

Los PNG animados que se bajan de Bulbagarden viven en desarrollo/.apng_bw, que es
una carpeta oculta y con los ficheros numerados por Pokedex nacional: no hay forma
de trabajar ahi. Esto los pone en desarrollo/pokemon/<especie>/ con nombre, y ademas
monta una hoja de contactos con TODAS las poses distintas numeradas.

Las animaciones se guardan en GIF, no en PNG animado. Aseprite no sabe leer APNG:
abre el fichero y ensena el primer fotograma como si fuera una imagen suelta. El GIF
si lo abre como animacion, con sus tiempos, y se puede recorrer cuadro a cuadro.

Los numeros de la hoja son los mismos que van en ANIMCMD_FRAME: salen de
fotogramas_distintos, igual que la tira que monta el importador, asi que lo que se
lee en la hoja se puede escribir tal cual en BUCLE_PRINCIPAL y BUCLE_ESPECIAL.

Uso:
    hoja_poses.py 1 4 7            por numero de Pokedex nacional
    hoja_poses.py bulbasaur        o por nombre de carpeta
    hoja_poses.py --todas          las 493, tarda
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from usa_entorno import asegura_pillow
asegura_pillow()

import argparse
import shutil

RAIZ = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from PIL import Image, ImageDraw, ImageFont

import bulbapedia
from apng_a_pic import fotogramas_distintos, caja_comun, indexa, MAGENTA
from lote_apng import nombres_por_numero, DESTINO

# Lo que dura un fotograma cuando el APNG no lo dice, en milisegundos.
DURACION_POR_DEFECTO = 100

# La hoja se ve en pantalla, no en la consola: los sprites son de 64 o 96 px y a
# tamano natural no se distingue una pose de la siguiente.
AUMENTO = 2
POR_FILA = 8
MARGEN = 12
ALTO_ETIQUETA = 22

FONDO = (28, 28, 32)
TEXTO = (235, 235, 240)
APAGADO = (120, 120, 130)
ARRIBA = (120, 200, 255)
ABAJO = (255, 170, 90)
CUADRO_CLARO = (76, 76, 84)
CUADRO_OSCURO = (60, 60, 68)
LADO_CUADRO = 8


def letra(tamano):
    try:
        return ImageFont.load_default(size=tamano)
    except TypeError:
        # Pillow viejo: la de siempre, diminuta pero legible.
        return ImageFont.load_default()


def tablero(ancho, alto):
    """Un cuadriculado detras del sprite. Sobre un color liso no se sabe donde
    acaba el dibujo y donde empieza el hueco, y eso es justo lo que hay que juzgar
    para elegir poses: cuanto se mueve cada una respecto al reposo."""
    fondo = Image.new("RGB", (ancho, alto), CUADRO_OSCURO)
    pinta = ImageDraw.Draw(fondo)
    for y in range(0, alto, LADO_CUADRO):
        for x in range(0, ancho, LADO_CUADRO):
            if (x // LADO_CUADRO + y // LADO_CUADRO) % 2 == 0:
                pinta.rectangle([x, y, x + LADO_CUADRO - 1, y + LADO_CUADRO - 1],
                                fill=CUADRO_CLARO)
    return fondo


def guarda_gif(ruta_apng, destino):
    """El PNG animado, tal cual, pasado a GIF para poder abrirlo en Aseprite.

    Van TODOS los fotogramas y con sus tiempos, no solo los distintos: aqui no se
    trata de contar poses sino de ver el movimiento, y las repeticiones son parte de
    como se mueve.

    No se recorta el lienzo. Ese margen vacio que el importador quita no sobra: es
    por donde se desplaza el bicho, y recortandolo la animacion se queda quieta.
    """
    from PIL import ImageSequence

    im = Image.open(ruta_apng)
    marcos, duraciones = [], []
    for f in ImageSequence.Iterator(im):
        marcos.append(f.convert("RGBA"))
        duraciones.append(f.info.get("duration") or DURACION_POR_DEFECTO)

    if not marcos:
        return 0

    # Una sola paleta para toda la animacion, con el magenta en el indice 0 haciendo
    # de transparente: es el mismo convenio que usa el resto del importador.
    colores = [MAGENTA]
    for m in marcos:
        for _, color in (m.getcolors(65536) or []):
            if color[3] != 0 and color[:3] not in colores:
                colores.append(color[:3])

    paginas = [indexa(m, colores) for m in marcos]

    paginas[0].save(destino, save_all=True, append_images=paginas[1:],
                    duration=duraciones, loop=0, transparency=0,
                    # Cada cuadro borra al anterior. Sin esto el bicho va dejando
                    # rastro de si mismo segun se mueve.
                    disposal=2, optimize=False)
    return len(paginas)


def desplazamientos(marcos):
    """Cuanto sube o baja el dibujo en cada pose respecto a la primera.

    Esto es el dato que hace falta y que el ojo no da: entre dos fotogramas de BW
    hay uno o dos pixeles de diferencia, asi que puestas una al lado de otra las
    veintitantas poses parecen la misma. Medido, se lee de un vistazo cual es el
    reposo, cual la de arriba y cual la de abajo.

    Se mide el borde de ARRIBA del dibujo, que es el que se mueve cuando el bicho
    da un saltito; los pies suelen quedarse donde estan.
    """
    arriba = []
    for m in marcos:
        b = m.getchannel("A").getbbox()
        arriba.append(None if b is None else b[1])

    base = next((a for a in arriba if a is not None), 0)
    return [None if a is None else base - a for a in arriba]


def fila_de_poses(marcos, caja, titulo):
    """Un bloque con el titulo y las poses numeradas, en filas de POR_FILA."""
    ancho_caja = (caja[2] - caja[0]) * AUMENTO
    alto_caja = (caja[3] - caja[1]) * AUMENTO
    celda_ancho = ancho_caja + MARGEN
    celda_alto = alto_caja + ALTO_ETIQUETA + MARGEN

    columnas = min(len(marcos), POR_FILA)
    filas = (len(marcos) + POR_FILA - 1) // POR_FILA

    ancho = max(columnas * celda_ancho + MARGEN, 360)
    alto = MARGEN + ALTO_ETIQUETA + filas * celda_alto

    subidas = desplazamientos(marcos)
    mas_alta = max(range(len(marcos)), key=lambda i: subidas[i] or 0)
    mas_baja = min(range(len(marcos)), key=lambda i: subidas[i] or 0)

    hoja = Image.new("RGB", (ancho, alto), FONDO)
    pinta = ImageDraw.Draw(hoja)
    pinta.text((MARGEN, MARGEN // 2),
               "%s  -  %d poses distintas  -  recorrido %d px"
               % (titulo, len(marcos), (subidas[mas_alta] or 0) - (subidas[mas_baja] or 0)),
               font=letra(16), fill=TEXTO)

    for i, marco in enumerate(marcos):
        columna, fila = i % POR_FILA, i // POR_FILA
        x = MARGEN + columna * celda_ancho
        y = MARGEN + ALTO_ETIQUETA + fila * celda_alto

        trozo = marco.crop(caja).resize((ancho_caja, alto_caja), Image.NEAREST)
        celda = tablero(ancho_caja, alto_caja)
        celda.paste(trozo, (0, 0), trozo)
        hoja.paste(celda, (x, y))

        # Un marco de color a los dos extremos del recorrido: son los candidatos a
        # "arriba" y "abajo" del vaiven, y asi no hay que buscarlos leyendo numeros.
        if i == mas_alta and subidas[i]:
            pinta.rectangle([x - 2, y - 2, x + ancho_caja + 1, y + alto_caja + 1],
                            outline=ARRIBA, width=2)
        elif i == mas_baja and subidas[i]:
            pinta.rectangle([x - 2, y - 2, x + ancho_caja + 1, y + alto_caja + 1],
                            outline=ABAJO, width=2)

        # El numero va DEBAJO y bien grande: es el dato que se copia al guion.
        pinta.text((x + 2, y + alto_caja + 3), str(i), font=letra(18), fill=TEXTO)

        subida = subidas[i]
        if i == 0:
            marca, color = "reposo", APAGADO
        elif not subida:
            marca, color = "=", APAGADO
        else:
            marca = ("sube %d" if subida > 0 else "baja %d") % abs(subida)
            color = ARRIBA if subida > 0 else ABAJO
        pinta.text((x + 20, y + alto_caja + 6), marca, font=letra(12), fill=color)

    return hoja


def apila(bloques):
    ancho = max(b.width for b in bloques)
    alto = sum(b.height for b in bloques)
    hoja = Image.new("RGB", (ancho, alto), FONDO)
    y = 0
    for b in bloques:
        hoja.paste(b, (0, y))
        y += b.height
    return hoja


def haz(numero, carpeta):
    frente_apng = bulbapedia.descarga(numero, False)
    espalda_apng = bulbapedia.descarga(numero, True)
    if frente_apng is None or espalda_apng is None:
        return "no esta en Bulbagarden"

    frente = fotogramas_distintos(frente_apng)
    espalda = fotogramas_distintos(espalda_apng)
    caja = caja_comun([frente, espalda])
    if caja is None:
        return "sin dibujo"

    ruta = os.path.join(RAIZ, DESTINO, carpeta)
    os.makedirs(ruta, exist_ok=True)

    # Las animaciones, donde se trabaja y en un formato que Aseprite abre moviendose.
    cuadros_f = guarda_gif(frente_apng, os.path.join(ruta, "bw_frente.gif"))
    cuadros_e = guarda_gif(espalda_apng, os.path.join(ruta, "bw_espalda.gif"))

    # Los .png animados que dejaba la version anterior ya no valen: Aseprite solo les
    # sacaba el primer cuadro, que es justo el problema que venimos a arreglar.
    for viejo in ("bw_frente_animado.png", "bw_espalda_animado.png"):
        if os.path.exists(os.path.join(ruta, viejo)):
            os.remove(os.path.join(ruta, viejo))

    apila([fila_de_poses(frente, caja, "FRENTE"),
           fila_de_poses(espalda, caja, "ESPALDA")]) \
        .save(os.path.join(ruta, "poses.png"))

    return "%d poses de frente y %d de espalda  (gif de %d y %d cuadros)" % (
        len(frente), len(espalda), cuadros_f, cuadros_e)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("cuales", nargs="*",
                   help="numeros de Pokedex nacional o nombres de carpeta")
    p.add_argument("--todas", action="store_true")
    args = p.parse_args()

    os.chdir(RAIZ)
    nombres = nombres_por_numero()
    por_nombre = {v: k for k, v in nombres.items()}

    if args.todas:
        numeros = sorted(nombres)
    else:
        numeros = []
        for cual in args.cuales:
            if cual.isdigit():
                numeros.append(int(cual))
            elif cual in por_nombre:
                numeros.append(por_nombre[cual])
            else:
                print("  no se quien es '%s'" % cual)

    if not numeros:
        p.error("dime al menos una especie, o --todas")

    for numero in numeros:
        carpeta = nombres.get(numero, "?%03d" % numero)
        try:
            nota = haz(numero, carpeta)
        except Exception as e:
            nota = "FALLO: %s" % e
        print("  %03d %-14s %s" % (numero, carpeta, nota))


if __name__ == "__main__":
    main()

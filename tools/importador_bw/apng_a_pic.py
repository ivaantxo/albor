#!/usr/bin/env python3
"""Convierte los PNG animados de Negro/Blanco en los pic que usa el juego.

De cada especie salen dos ficheros indexados que COMPARTEN PALETA:

    anim_front.png   lado x (lado * fotogramas)
    back.png         igual

Lo que hace, por orden:

  1. Saca los fotogramas de los dos PNG animados y se queda con los DISTINTOS,
     en el orden en que salen. Como las animaciones de BW son un ciclo repetido
     unas cuantas veces y al final un gesto que se hace una vez, ese orden deja
     el ciclo primero y lo especial al final, que es como se quiere leer.
  2. Mide la caja que ocupa el dibujo en TODOS los fotogramas de los dos, y elige
     el lado mas pequeno donde quepa. El lienzo del original no sirve: lleva mucho
     margen vacio, que es el recorrido de la animacion.
  3. Monta una sola paleta para los dos: el magenta primero, luego los colores del
     frente y detras los que solo aparezcan en la espalda.
  4. Pega cada fotograma en su caja e indexa.

No se recorta ni se reescala nada del dibujo: si una especie no cabe en el lado
mayor, se dice y se deja fuera para mirarla a mano.
"""

from PIL import Image, ImageSequence

MAGENTA = (255, 0, 255)

# Los lados que el juego sabe dibujar. 64 es el unico que cabe en un solo objeto
# de GBA: los demas hay que repartirlos en piezas.
LADOS = (64, 80, 96)


def fotogramas_distintos(ruta):
    """Los fotogramas que no se repiten, en orden de aparicion."""
    im = Image.open(ruta)
    vistos, salida = set(), []
    for f in ImageSequence.Iterator(im):
        marco = f.convert("RGBA")
        clave = marco.tobytes()
        if clave not in vistos:
            vistos.add(clave)
            salida.append(marco)
    return salida


def caja_comun(grupos):
    """La caja que abarca el dibujo de todos los fotogramas de todos los grupos."""
    caja = None
    for marcos in grupos:
        for m in marcos:
            b = m.getchannel("A").getbbox()
            if b is None:
                continue
            caja = b if caja is None else (min(caja[0], b[0]), min(caja[1], b[1]),
                                           max(caja[2], b[2]), max(caja[3], b[3]))
    return caja


def lado_para(caja):
    """El lado mas pequeno donde cabe el dibujo. Siempre CUADRADO.

    Cuadrado a proposito, aunque el dibujo sea apaisado: el juego elige como
    trocear el pic por lo que pesa un fotograma, y con cajas rectangulares dos
    tamanos distintos podrian pesar lo mismo y confundirse.

    Los que no caben en el mayor de LADOS no se descartan: se les da su propia
    caja, redondeada al tile de arriba, porque un pic tiene que medir un numero
    entero de tiles para poder repartirse en piezas.
    """
    lado = max(caja[2] - caja[0], caja[3] - caja[1])

    for normal in LADOS:
        if lado <= normal:
            return normal

    return (lado + 7) // 8 * 8


def colores_de(marcos, caja):
    """Los colores que usa un grupo de fotogramas, sin repetir y en orden estable."""
    salida = []
    for m in marcos:
        for cuenta, color in (m.crop(caja).getcolors(65536) or []):
            if color[3] == 0:          # transparente: no es un color de la paleta
                continue
            rgb = color[:3]
            if rgb not in salida:
                salida.append(rgb)
    return salida


def paleta_compartida(frente, espalda, caja):
    """Magenta primero, luego el frente y detras lo que solo tenga la espalda."""
    colores = [MAGENTA]
    for rgb in colores_de(frente, caja):
        if rgb not in colores:
            colores.append(rgb)
    for rgb in colores_de(espalda, caja):
        if rgb not in colores:
            colores.append(rgb)
    return colores


def monta_tira(marcos, caja, lado, colores, pegado_a_la_derecha=True):
    """Los fotogramas uno debajo de otro, ya indexados.

    Se pega abajo y a la derecha. Lo de la derecha es una eleccion del proyecto,
    no una necesidad: pasando pegado_a_la_derecha en falso se centra a lo ancho.
    """
    ancho, alto = caja[2] - caja[0], caja[3] - caja[1]
    x = (lado - ancho) if pegado_a_la_derecha else (lado - ancho) // 2
    y = lado - alto

    tira = Image.new("RGBA", (lado, lado * len(marcos)), MAGENTA + (255,))
    for i, m in enumerate(marcos):
        trozo = m.crop(caja)
        tira.paste(trozo, (x, y + lado * i), trozo)

    return indexa(tira, colores)


def indexa(imagen, colores):
    """Pasa a paleta, dejando el magenta en el indice 0."""
    plana = Image.new("RGB", imagen.size, MAGENTA)
    plana.paste(imagen, (0, 0), imagen)

    paleta = Image.new("P", (1, 1))
    tabla = []
    for rgb in colores:
        tabla += list(rgb)
    tabla += [0, 0, 0] * (256 - len(colores))
    paleta.putpalette(tabla)

    return plana.quantize(palette=paleta, dither=Image.Dither.NONE)

#!/usr/bin/env python3
"""Lectura de las hojas de followers (los "minis") de HGSS.

A diferencia de las hojas de combate, estas no llevan cabecera con el nombre, asi
que la unica forma de saber que especie es cada bloque es contarlos en orden.

Cada especie ocupa un bloque de 64x128: dos columnas por cuatro filas de 32x32,
con lineas de separacion de un pixel. El reparto de las ocho celdas es:

        columna 1                     columna 2
  f1    espaldas, pie izquierdo       de lado, pie izquierdo
  f2    espaldas, pie derecho         de lado, pie derecho
  f3    de frente, pie izquierdo      al otro lado, pie izquierdo
  f4    de frente, pie derecho        al otro lado, pie derecho

Las especies con sprite distinto por genero ocupan DOS bloques seguidos y llevan
un punto de color entre la primera y la segunda fila: azul el macho, rosa la
hembra.
"""

LADO = 32
PASO_COLUMNA = 65        # 64 de bloque mas su linea
PASO_FILA = 129          # 128 de bloque mas su linea
COLUMNAS_BLOQUE = 2
FILAS_BLOQUE = 4

MARCA_MACHO = (0, 128, 255)
MARCA_HEMBRA = (255, 0, 255)

# Donde cae el punto de genero, dentro del bloque.
ZONA_MARCA = (28, 38, 28, 40)   # x0, x1, y0, y1

# Las cuatro hojas y por que numero empieza cada una. Van por generacion, igual
# que las hojas de combate, asi que el numero de partida no hay que deducirlo:
# se sabe. Comprobado en la primera, que acaba justo en Mew con tres bloques en
# su ultima fila.
HOJAS_MINIS = (("26794", 1), ("26795", 152), ("26828", 252), ("26953", 387))

# Que celda es cada pose. La columna va primero, luego la fila.
FRENTE = ((0, 2), (0, 3))
ESPALDAS = ((0, 0), (0, 1))
DE_LADO = ((1, 0), (1, 1))
AL_OTRO_LADO = ((1, 2), (1, 3))


def rejilla(im):
    """Cuantos bloques hay a lo ancho y a lo alto.

    Cuenta TODO bloque que empiece dentro de la hoja, aunque se salga por el
    borde. El ultimo de cada fila suele estar recortado -en la primera hoja
    quedan 60 pixeles de los 65- y aun asi lleva su especie: alli vive Kakuna, y
    descartarlo desplazaba a todos los que venian detras.
    """
    ancho, alto = im.size
    columnas = -(-ancho // PASO_COLUMNA)
    filas = -(-alto // PASO_FILA)
    return columnas, filas


def celda(bloque_x, bloque_y, columna, fila):
    """Caja de una de las ocho celdas de 32x32 de un bloque.

    Dentro del bloque las celdas van pegadas: 64 son dos de 32 y 128 son cuatro
    de 32, sin nada en medio. El pixel de separacion esta solo ENTRE bloques, y
    de ahi salen el paso de 65 y el de 129. Contar 33 por celda metia la linea
    azul del separador debajo de cada sprite.
    """
    x = bloque_x + columna * LADO
    y = bloque_y + fila * LADO
    return (x, y, x + LADO, y + LADO)


# Las especies con follower distinto por genero, que ocupan dos bloques. Van a
# mano porque son cinco y detectarlas por el punto de color no es fiable: hay
# dibujos que llevan ese mismo azul o ese mismo rosa entre sus colores.
DOBLES = (3, 25, 154, 208, 214)     # Venusaur, Pikachu, Meganium, Steelix, Heracross


def dobles_de_hoja(im):
    """Las especies de dos bloques, por su marca de color.

    Un doble de verdad es una marca de macho con una de hembra en el bloque de al
    lado. Pedir las dos quita los falsos positivos: hay dibujos que llevan ese
    mismo azul entre sus colores, y cuatro de la ultima fila de la primera hoja
    se colaban por eso.
    """
    px = im.load()
    ancho, alto = im.size
    columnas, filas = rejilla(im)

    def marca(columna, fila):
        bx, by = columna * PASO_COLUMNA, fila * PASO_FILA
        colores = {px[bx + x, by + y]
                   for x in range(min(64, ancho - bx))
                   for y in range(min(128, alto - by))}
        if MARCA_MACHO in colores:
            return 'M'
        return 'H' if MARCA_HEMBRA in colores else None

    salida = set()
    for fila in range(filas):
        for columna in range(columnas - 1):
            if marca(columna, fila) == 'M' and marca(columna + 1, fila) == 'H':
                salida.add((columna, fila))
    return salida


def bloques_de_hoja(im, primero):
    """Pares (numero de Pokedex, esquina del bloque) de una hoja."""
    columnas, filas = rejilla(im)
    dobles = dobles_de_hoja(im)

    salida = []
    numero = primero
    fila = columna = 0
    while fila < filas and numero <= 493:
        salida.append((numero, (columna * PASO_COLUMNA, fila * PASO_FILA)))
        columna += 2 if (columna, fila) in dobles else 1
        numero += 1
        while columna >= columnas:
            columna -= columnas
            fila += 1
    return salida


def espejo(imagen):
    from PIL import Image as _I
    return imagen.transpose(_I.Transpose.FLIP_LEFT_RIGHT)


def se_espeja(izquierda, derecha, tolerancia=8):
    """Cierto si el sprite de un lado es el otro dado la vuelta.

    Los que NO se espejan -Togekiss, Kingler- tienen dibujo propio para cada lado
    y hay que llevarse los cuatro fotogramas en vez de dos.
    """
    a = espejo(izquierda).convert('RGB')
    b = derecha.convert('RGB')
    if a.size != b.size:
        return False

    distintos = sum(1 for p, q in zip(a.getdata(), b.getdata()) if p != q)
    return distintos <= tolerancia


def se_sale_de_la_celda(im, bloque_x, bloque_y, fondo, separador):
    """Cierto si el dibujo invade las lineas de separacion del bloque.

    Un sprite de 32x32 toca el borde de su celda por definicion, asi que eso no
    dice nada. Lo que delata a los grandes -Steelix, Kyogre, Groudon, Rayquaza-
    es que se derraman sobre la linea que separa su bloque del de al lado. Esos se
    dejan estar: el usuario los ajusta a mano.

    Hay que descontar el color de la propia linea, claro: esa linea NO es del
    color del fondo, y compararla solo contra el fondo daba por grandes a casi
    todos.
    """
    px = im.load()
    ancho, alto = im.size

    # Solo las lineas que rodean al bloque: dentro no hay ninguna.
    separaciones = [(bloque_x + 2 * LADO, None), (None, bloque_y + FILAS_BLOQUE * LADO)]

    for x, y in separaciones:
        if x is not None:
            if x >= ancho:
                continue
            franja = [(x, bloque_y + i) for i in range(min(128, alto - bloque_y))]
        else:
            if y >= alto:
                continue
            franja = [(bloque_x + i, y) for i in range(min(64, ancho - bloque_x))]
        invasores = sum(1 for a, b in franja if px[a, b] not in (fondo, separador))
        if invasores > PIXELES_QUE_NO_SON_DERRAME:
            return True
    return False


# Un pixel suelto en la separacion no es un sprite que se sale: es el punto de
# genero, o el borde de un dibujo que roza. Los grandes de verdad la invaden a lo
# largo.
PIXELES_QUE_NO_SON_DERRAME = 6

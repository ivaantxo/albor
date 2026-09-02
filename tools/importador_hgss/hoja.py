#!/usr/bin/env python3
"""Lectura de las hojas de sprites de HGSS de The Spriters Resource.

La rejilla es regular: celdas de 80x80 separadas por una linea de 1 pixel, y
bloques verticales de 195 px (34 de cabecera + 80 de la fila normal + 1 de
separacion + 80 de la fila variocolor).

Lo que NO es regular es el ancho de cada especie. La mayoria ocupa cuatro
columnas -frente 1, frente 2, espalda 1, espalda 2- pero las que tienen sprite
distinto por genero ocupan ocho, asi que la posicion de una especie no se puede
calcular: hay que leer el numero de Pokedex de su cabecera.
"""

from PIL import Image

ALTO_CABECERA = 34
LADO_CELDA = 80
PASO_CELDA = 81          # la celda mas su linea de separacion
ALTO_BLOQUE = 195        # cabecera + fila normal + separacion + fila variocolor

# Los dos fondos que usa la hoja. El verde significa "igual que en Platino" y el
# azul "propio de HeartGold/SoulSilver"; para extraer da lo mismo, los dos son
# fondo y hay que quitarlos.
FONDOS = {(147, 187, 236), (84, 165, 75)}
AZUL_CABECERA = (50, 97, 168)
BLANCO = (248, 248, 248)   # el texto de las cabeceras no es blanco puro


def bandas_de_cabecera(im):
    """Las y donde empieza cada fila de bloques."""
    ancho, alto = im.size
    return list(range(0, alto - ALTO_BLOQUE + 1, ALTO_BLOQUE))


def _mascara_texto(im, y0):
    """Columnas de la cabecera que llevan algun pixel de texto blanco."""
    px = im.load()
    ancho = im.size[0]
    return [any(px[x, y] == BLANCO for y in range(y0 + 2, y0 + 12))
            for x in range(ancho)]


def glifos_de_la_cabecera(im, y0, x_desde, x_hasta):
    """Recorta los glifos sueltos del texto, en orden, como listas de columnas."""
    px = im.load()
    columnas = []
    for x in range(x_desde, x_hasta):
        col = tuple(1 if px[x, y] == BLANCO else 0 for y in range(y0 + 2, y0 + 14))
        columnas.append((x, col))

    glifos, actual = [], []
    for x, col in columnas:
        if any(col):
            actual.append(col)
        elif actual:
            glifos.append(tuple(actual))
            actual = []
    if actual:
        glifos.append(tuple(actual))
    return glifos


def inicios_de_bloque(im, y0):
    """Las x donde empieza cada especie dentro de una banda de cabecera.

    El titulo se pega al borde izquierdo de su bloque, asi que basta con buscar
    donde arranca cada grupo de texto. Entre un titulo y el siguiente hay mucho
    azul; dentro de un titulo, los huecos entre letras son de pocos pixeles.
    """
    hay_texto = _mascara_texto(im, y0)
    ancho = len(hay_texto)

    inicios, hueco = [], HUECO_ENTRE_TITULOS
    for x in range(ancho):
        if hay_texto[x]:
            if hueco >= HUECO_ENTRE_TITULOS:
                inicios.append(x)
            hueco = 0
        else:
            hueco += 1
    return inicios


# Un titulo entero mide poco mas de cien pixeles y el bloque mas estrecho son
# cuatro columnas, o sea 324. Con este hueco no se parte un titulo por dentro ni
# se juntan dos.
HUECO_ENTRE_TITULOS = 40


def numero_de_bloque(im, y0, x0, plantillas):
    """Los tres digitos del principio del titulo, como entero."""
    glifos = glifos_de_la_cabecera(im, y0, x0, x0 + 40)
    if len(glifos) < 3:
        return None

    digitos = ''
    for glifo in glifos[:3]:
        d = plantillas.get(glifo)
        if d is None:
            return None
        digitos += d
    return int(digitos)


# Las cuatro hojas cubren de la 001 a la 493 sin huecos.
HOJAS_GRANDES = ("132565", "132566", "132567", "132568")

X_PRIMER_BLOQUE = 4
ANCHO_BLOQUE = 324       # cuatro celdas de 80 mas sus lineas


class Bloque:
    """Lo que ocupa una especie en la hoja."""

    def __init__(self, numero, x, y, doble):
        self.numero = numero      # numero de Pokedex, leido de la cabecera
        self.x = x
        self.y = y                # la y de SU cabecera
        self.doble = doble        # cierto si trae macho y hembra

    def celda(self, columna, variocolor):
        """Caja (izq, arriba, der, abajo) de una de sus celdas de 80x80.

        columna: 0 frente 1, 1 frente 2, 2 espalda 1, 3 espalda 2.
        """
        # self.x es donde empieza el TEXTO del titulo, tres pixeles a la derecha
        # del borde del bloque. La rejilla de celdas va en multiplos de 81 mas uno,
        # asi que hay que volver al borde antes de contar columnas: si no, cada
        # recorte se lleva la linea de separacion de la celda siguiente.
        x = (self.x - X_PRIMER_BLOQUE) + 1 + PASO_CELDA * columna
        y = self.y + ALTO_CABECERA + (LADO_CELDA + 1 if variocolor else 0)
        return (x, y, x + LADO_CELDA, y + LADO_CELDA)


_digitos = None


def aprende_digitos(im, huecos):
    """Las formas de los diez digitos, sacadas de los diez primeros titulos.

    Se aprenden UNA vez y de la PRIMERA hoja, porque el metodo se apoya en que
    sus diez primeros bloques son el 001 al 010. En las otras hojas los numeros
    empiezan por donde acabo la anterior y la correspondencia no valdria.

    Se aprenden en cada ejecucion en vez de guardarlas en una tabla: si algun dia
    cambia la fuente de las hojas, esto se entera solo.
    """
    global _digitos
    if _digitos is not None:
        return _digitos
    formas = []
    for y0 in bandas_de_cabecera(im):
        for k in range(huecos):
            x = X_PRIMER_BLOQUE + ANCHO_BLOQUE * k
            if x + 40 > im.size[0]:
                continue
            g = glifos_de_la_cabecera(im, y0, x, x + 40)
            if len(g) >= 3:
                formas.append(tuple(g[:3]))
        if len(formas) >= 10:
            break

    plantillas = {}
    for i, glifos in enumerate(formas[:10]):
        for glifo, digito in zip(glifos, "%03d" % (i + 1)):
            plantillas.setdefault(glifo, digito)

    _digitos = plantillas
    return plantillas


def bloques_de_especie(im):
    """Todas las especies de una hoja, con su numero y su sitio.

    Los huecos van cada 324 pixeles. Un hueco sin titulo no es un error: es la
    mitad hembra del bloque anterior.
    """
    huecos = (im.size[0] - X_PRIMER_BLOQUE) // ANCHO_BLOQUE + 1
    plantillas = aprende_digitos(im, huecos)

    bloques = []
    for y0 in bandas_de_cabecera(im):
        anterior = None
        for k in range(huecos):
            x = X_PRIMER_BLOQUE + ANCHO_BLOQUE * k
            if x + 40 > im.size[0]:
                continue
            numero = numero_de_bloque(im, y0, x, plantillas)
            if numero is None:
                # Sin titulo: continuacion del bloque de al lado.
                if anterior is not None:
                    anterior.doble = True
                continue
            anterior = Bloque(numero, x, y0, False)
            bloques.append(anterior)
    return bloques


# Semilla para aprender las letras, igual que los diez primeros numeros sirven
# para aprender los digitos. Van por numero de Pokedex NACIONAL, que es lo que
# lleva la hoja y no cambia nunca.
#
# No son los treinta primeros por gusto: hacen falta los justos para cubrir el
# alfabeto. La J solo sale en Jigglypuff y la X solo en Xatu, asi que esos dos
# estan aqui aunque no vengan seguidos.
SEMILLA_NOMBRES = {
    1: "BULBASAUR",   2: "IVYSAUR",     3: "VENUSAUR",    4: "CHARMANDER",
    5: "CHARMELEON",  6: "CHARIZARD",   7: "SQUIRTLE",    8: "WARTORTLE",
    9: "BLASTOISE",  10: "CATERPIE",   11: "METAPOD",    12: "BUTTERFREE",
   13: "WEEDLE",     14: "KAKUNA",     15: "BEEDRILL",   16: "PIDGEY",
   22: "FEAROW",     23: "EKANS",      24: "ARBOK",      25: "PIKACHU",
   37: "VULPIX",      39: "JIGGLYPUFF",
}

_letras = None


def aprende_letras(im, huecos):
    """Las formas de las letras, sacadas de los diez primeros titulos.

    El titulo es "NNN NOMBRE", asi que los glifos del cuarto en adelante son el
    nombre. Se aprende de la primera hoja por lo mismo que los digitos.
    """
    global _letras
    if _letras is not None:
        return _letras

    digitos = aprende_digitos(im, huecos)
    plantillas = {}
    for y0 in bandas_de_cabecera(im):
        for k in range(huecos):
            x = X_PRIMER_BLOQUE + ANCHO_BLOQUE * k
            if x + 200 > im.size[0]:
                continue
            numero = numero_de_bloque(im, y0, x, digitos)
            nombre = SEMILLA_NOMBRES.get(numero)
            if nombre is None:
                continue
            for glifo, letra in zip(glifos_de_la_cabecera(im, y0, x, x + 200)[3:],
                                    nombre):
                plantillas.setdefault(glifo, letra)

    _letras = plantillas
    return plantillas


def nombre_de_bloque(im, y0, x0, letras):
    """El nombre de la especie, leido de su cabecera. None si algo no se conoce."""
    glifos = glifos_de_la_cabecera(im, y0, x0, x0 + 200)
    if len(glifos) < 4:
        return None

    nombre = ''
    for glifo in glifos[3:]:
        letra = letras.get(glifo)
        if letra is None:
            return None
        nombre += letra
    return nombre


# Los ocho titulos que no se pueden leer letra a letra porque llevan algo que no
# es una letra: los simbolos de genero de Nidoran, el apostrofe de Farfetch'd, el
# punto de Mr. Mime y Mime Jr., el guion de Ho-Oh y Porygon-Z, y el 2 de Porygon2.
# El numero si se lee, asi que basta con decir a que especie corresponden.
NOMBRES_CON_SIMBOLOS = {
     29: "nidoran_f",   32: "nidoran_m",   83: "farfetchd",  122: "mr_mime",
    233: "porygon2",   250: "ho_oh",      439: "mime_jr",    474: "porygon_z",
}


def especie_de_bloque(im, bloque, letras):
    """Nombre de carpeta de la especie de un bloque, en minusculas."""
    if bloque.numero in NOMBRES_CON_SIMBOLOS:
        return NOMBRES_CON_SIMBOLOS[bloque.numero]

    nombre = nombre_de_bloque(im, bloque.y, bloque.x, letras)
    return nombre.lower() if nombre else None


MAGENTA = (255, 0, 255)   # el transparente del proyecto
COLORES = 16


def recorta_celda(im, bloque, columna, variocolor):
    """Una celda de 80x80 con el fondo de la hoja pasado a magenta."""
    celda = im.crop(bloque.celda(columna, variocolor)).convert("RGB")
    pixeles = celda.load()
    for y in range(celda.size[1]):
        for x in range(celda.size[0]):
            if pixeles[x, y] in FONDOS:
                pixeles[x, y] = MAGENTA
    return celda


def paleta_de(imagenes, avisa=None):
    """Los colores de unos recortes, con el magenta el primero.

    El magenta va en el indice 0 porque es lo que espera el resto del proyecto,
    asi que para el dibujo quedan quince.

    Si sobran, se quedan los mas usados. Casi siempre lo que sobra es ruido del
    ripeo -a la espalda variocolor de Chimchar se le colo UN pixel del azul de las
    cabeceras-, y por eso se avisa solo cuando lo descartado tiene cuerpo: por
    debajo de este numero de pixeles no merece la pena ni mirarlo.
    """
    cuenta = {}
    for im in imagenes:
        for veces, color in im.getcolors(4096) or []:
            if color != MAGENTA:
                cuenta[color] = cuenta.get(color, 0) + veces

    orden = sorted(cuenta, key=lambda c: -cuenta[c])
    colores = orden[:COLORES - 1]

    if avisa is not None:
        for color in orden[COLORES - 1:]:
            if cuenta[color] > PIXELES_QUE_SON_RUIDO:
                avisa(color, cuenta[color])

    colores = [MAGENTA] + colores
    return colores + [MAGENTA] * (COLORES - len(colores))


# Un color con esto o menos pixeles es basura del ripeo, no parte del dibujo.
PIXELES_QUE_SON_RUIDO = 4


def colores_ajenos(imagenes, colores):
    """Cuantos colores de estos recortes no estan en la paleta.

    Sirve para avisar: la espalda se aproxima a la paleta del frente, y si usa
    tonos que alli no existen el dibujo se degrada y hay que mirarlo a mano.
    """
    dentro = set(colores)
    fuera = set()
    for im in imagenes:
        for _, color in im.getcolors(4096) or []:
            if color not in dentro:
                fuera.add(color)
    return fuera


def indexa(imagenes, colores):
    """Apila los recortes en vertical y los indexa a la paleta dada."""
    ancho = imagenes[0].size[0]
    alto = sum(im.size[1] for im in imagenes)
    hoja = Image.new("RGB", (ancho, alto), MAGENTA)
    y = 0
    for im in imagenes:
        hoja.paste(im, (0, y))
        y += im.size[1]

    plana = []
    for c in colores:
        plana += list(c)

    referencia = Image.new("P", (1, 1))
    referencia.putpalette(plana)
    return hoja.quantize(palette=referencia, dither=Image.Dither.NONE)


def escribe_pal(ruta, colores):
    with open(ruta, "w") as f:
        f.write("JASC-PAL\n0100\n%d\n" % COLORES)
        for r, g, b in colores:
            f.write("%d %d %d\n" % (r, g, b))

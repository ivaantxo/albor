#!/usr/bin/env python3
"""Descarga de los sprites animados de Negro/Blanco desde Bulbagarden.

No son gif: son PNG animados. Bulbapedia guarda el frente en Spr_5b_NNN.png y la
espalda en Spr_b_5b_NNN.png, los dos con todos los fotogramas dentro, y Pillow los
lee igual que un gif.

Las URL no se pueden componer a mano -llevan un hash en la ruta-, asi que hay que
preguntarle a la API por cada fichero. Se guarda lo descargado para no volver a
pedirlo: son casi mil ficheros y no hay que darle la lata al servidor dos veces.
"""

import os
import time
import urllib.parse
import urllib.request
import json

API = "https://archives.bulbagarden.net/w/api.php"
CACHE = "desarrollo/.apng_bw"

# Quien pide las cosas, por si al otro lado quieren saberlo. Un agente vacio o
# fingiendo ser un navegador es mala educacion y ademas suele acabar bloqueado.
AGENTE = "albor-importer/1.0 (proyecto personal; ivan.martinezl@icloud.com)"

# Entre peticion y peticion. No hay prisa y el servidor es de una wiki.
ESPERA = 0.5


INTENTOS = 3


def _pide(url):
    """Con reintentos: la wiki deja caer alguna peticion de vez en cuando."""
    for intento in range(INTENTOS):
        try:
            req = urllib.request.Request(url, headers={"User-Agent": AGENTE})
            with urllib.request.urlopen(req, timeout=30) as r:
                return r.read()
        except Exception:
            if intento == INTENTOS - 1:
                raise
            time.sleep(2 * (intento + 1))


def nombres_posibles(numero, espalda):
    """Los nombres con los que puede estar guardado, en orden de preferencia.

    Las especies con sprite distinto por genero no tienen fichero a secas: van con
    sufijo _m y _f. Se coge el macho, que es la forma por defecto del juego.
    """
    base = "Spr_%s5b_%03d" % ("b_" if espalda else "", numero)
    return [base + ".png", base + "_m.png"]


def url_de(numero, espalda):
    """Pregunta a la API donde vive el fichero. None si no existe."""
    for nombre in nombres_posibles(numero, espalda):
        url = _busca(nombre)
        if url is not None:
            return url
    return None


def _busca(nombre):
    titulo = "File:" + nombre
    consulta = urllib.parse.urlencode({
        "action": "query", "titles": titulo, "prop": "imageinfo",
        "iiprop": "url|size", "format": "json",
    })
    datos = json.loads(_pide(API + "?" + consulta))
    for pagina in datos.get("query", {}).get("pages", {}).values():
        info = pagina.get("imageinfo")
        if info:
            return info[0]["url"]
    return None


def descarga(numero, espalda):
    """Ruta local del sprite, bajandolo si hace falta. None si no existe."""
    os.makedirs(CACHE, exist_ok=True)
    destino = os.path.join(CACHE, "%s%03d.png" % ("b" if espalda else "f", numero))

    if os.path.exists(destino):
        return destino

    url = url_de(numero, espalda)
    if url is None:
        return None

    time.sleep(ESPERA)
    with open(destino, "wb") as f:
        f.write(_pide(url))
    time.sleep(ESPERA)
    return destino

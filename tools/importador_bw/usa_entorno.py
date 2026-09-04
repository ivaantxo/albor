"""Vuelve a lanzar el script con el Python del entorno si aqui no hay Pillow.

Pillow no esta en el Python del sistema: vive en tools/importador_bw/entorno, que se
monta aparte. Hasta ahora, llamar a cualquiera de estos scripts con "python loquesea.py"
soltaba un ModuleNotFoundError de PIL sin decir por que ni que hacer, y solo funcionaba
si te acordabas de escribir la ruta larga del interprete.

Asi funcionan las dos formas: si falta Pillow, el script se relanza solo con el
interprete correcto y sigue como si nada.

El fichero NO se puede llamar "entorno.py": al lado hay una carpeta llamada "entorno",
y Python 3 la tomaria por un paquete de espacio de nombres e importaria la carpeta.
"""

import os
import sys

# Para no reejecutar en bucle si el entorno tampoco lo trae.
CENTINELA = "ALBOR_IMPORTADOR_REEJECUTADO"

AQUI = os.path.dirname(os.path.abspath(__file__))
INTERPRETE = os.path.join(AQUI, "entorno", "bin", "python")


def asegura_pillow():
    try:
        import PIL  # noqa: F401
        return
    except ImportError:
        pass

    if os.environ.get(CENTINELA):
        sys.exit("El entorno de %s no trae Pillow.\n"
                 "  %s/entorno/bin/pip install Pillow" % (AQUI, AQUI))

    if not os.path.exists(INTERPRETE):
        sys.exit("Falta Pillow y no hay entorno en %s.\n"
                 "  cd %s && python3 -m venv entorno && entorno/bin/pip install Pillow"
                 % (INTERPRETE, AQUI))

    os.environ[CENTINELA] = "1"
    os.execv(INTERPRETE, [INTERPRETE] + sys.argv)

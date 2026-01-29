import re
from pathlib import Path

file = Path("src/battle_message.c")  # ajusta ruta

text = file.read_text()

# -------------------------------------------------
# 1. Extraer definiciones sText_*
# -------------------------------------------------

pattern = re.compile(
    r'static const u8 (sText_[A-Za-z0-9_]+)\[\] = _\("((?:\\.|[^"])*)"\);'
)

strings = dict(pattern.findall(text))

print(f"Encontradas {len(strings)} strings")

# -------------------------------------------------
# 2. Reemplazar en la tabla
# -------------------------------------------------

def replace_table(match):
    key = match.group(1)
    if key in strings:
        return f'COMPOUND_STRING("{strings[key]}")'
    else:
        print("⚠️ no encontrada:", key)
        return key

text = re.sub(
    r'=\s*(sText_[A-Za-z0-9_]+)',
    lambda m: "= " + replace_table(m),
    text
)

# -------------------------------------------------
# 3. Eliminar definiciones originales
# -------------------------------------------------

text = pattern.sub("", text)

file.write_text(text)

print("✔ Conversión completada")
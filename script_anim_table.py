import re

# Cargar tablas
with open("src/data/battle_anim.h", "r") as f:
    content = f.read()

# Regex para sheet
sheet_pattern = re.compile(r"\{\s*(gBattleAnimSpriteGfx_[A-Za-z0-9_]+)\s*,\s*(\d+)\s*,\s*(ANIM_TAG_[A-Z0-9_]+)\s*\}")
sheets = {}
for m in sheet_pattern.findall(content):
    sheet_name = m[0]
    sheet_size = int(m[1])
    tag = m[2]
    sheets[tag] = (sheet_name, sheet_size)

# Regex para palette
pal_pattern = re.compile(r"\{\s*(gBattleAnimSpritePal_[A-Za-z0-9_]+)\s*,\s*(ANIM_TAG_[A-Z0-9_]+)\s*\}")
pals = {m[1]: m[0] for m in pal_pattern.findall(content)}

# Generar tabla unificada
lines = []
for tag in sheets:
    if tag in pals:
        sheet, size = sheets[tag]
        palette = pals[tag]
        lines.append(f"[{tag}] = {{{sheet}, {palette}, {size}, {tag}}},")

# Imprimir
print("const struct CompressedSpriteSheetAndPalette gBattleAnimTable[] = {")
for line in lines:
    print("    " + line)
print("};")
# Pega aquí tu tabla completa entre """..."""
table_text = """

"""

# Filtrar solo líneas con '='
lines = [line.strip() for line in table_text.strip().splitlines() if '=' in line]

parsed_lines = []
max_cols = 0

for line in lines:
    m = line.split('=', 1)
    left = m[0].strip()
    inside = m[1].strip().lstrip('{').rstrip('},').split(',')
    inside = [x.strip() for x in inside]
    parsed_lines.append((left, inside))
    max_cols = max(max_cols, len(inside))

# Inicializar anchos por columna
column_widths = [0] * max_cols
left_width = max(len(p[0]) for p in parsed_lines)

# Calcular ancho máximo de cada columna
for _, inside in parsed_lines:
    for i, col in enumerate(inside):
        column_widths[i] = max(column_widths[i], len(col))

# Generar líneas alineadas
aligned_lines = []
for left, inside in parsed_lines:
    line = left.ljust(left_width) + " = {"
    for i, col in enumerate(inside):
        # siempre coma pegada al elemento salvo el último
        if i < len(inside) - 1:
            line += col.ljust(column_widths[i]) + ", "
        else:
            line += col.ljust(column_widths[i])
    line += "},"
    aligned_lines.append(line)

# Imprimir tabla
print("const struct CompressedSpriteSheetAndPalette gBattleAnimTable[] = {")
for l in aligned_lines:
    print("    " + l)
print("};")
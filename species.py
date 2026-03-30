import re

INPUT_FILE = "species.txt"
OUTPUT_FILE = "pokedex.html"

def format_name(enum_name):
    name = enum_name.replace("SPECIES_", "").lower()

    # formas regionales
    name = name.replace("_alola", "-alolan")
    name = name.replace("_galar", "-galarian")
    name = name.replace("_hisui", "-hisuian")

    name = name.replace("_", "-")

    return name

def display_name(enum_name):
    name = enum_name.replace("SPECIES_", "").lower().replace("_", " ")

    # capitalizar
    return " ".join(word.capitalize() for word in name.split())

species = []

with open(INPUT_FILE, "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()

        # ignorar comentarios completos
        if line.startswith("//"):
            continue

        # quitar comentarios inline
        line = line.split("//")[0].strip()

        match = re.match(r"SPECIES_[A-Z0-9_]+", line)
        if not match:
            continue

        enum = match.group()

        if enum in ["SPECIES_NONE", "SPECIES_EGG"]:
            continue

        if "NUM_SPECIES" in enum:
            continue

        species.append(enum)

# generar html
html = """
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
body { font-family: sans-serif; }
.grid {
    display: grid;
    grid-template-columns: repeat(8, 1fr);
    gap: 12px;
}
.card {
    text-align: center;
}
img {
    width: 96px;
}
</style>
</head>
<body>

<div class="grid">
"""

for s in species:
    url_name = format_name(s)
    display = display_name(s)

    sprite = f"https://img.pokemondb.net/sprites/home/normal/{url_name}.png"

    html += f"""
    <div class="card">
        <img src="{sprite}">
        <div>{display}</div>
    </div>
    """

html += """
</div>
</body>
</html>
"""

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    f.write(html)

print("HTML generado:", OUTPUT_FILE)
#!/usr/bin/env python3
"""Describe every HGSS OW frame without modifying the source sheet.

Run from the repository root with the Pillow-enabled project interpreter:
  desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_hgss/build_manifest.py
"""

import json
from collections import Counter
from pathlib import Path

from PIL import Image, ImageDraw


ROOT = Path(__file__).resolve().parents[3]
SOURCE = ROOT / "entrenadores/26955.png"
OUTPUT = ROOT / "entrenadores/importacion/ow_hgss.json"
HERE = Path(__file__).resolve().parent

# Several blocks are 94/95 px wide. They are not on a uniform 96 px grid.
ORIGINS_X = [
    [0, 96, 192, 288, 384, 479, 573, 669, 765, 861],
    [0, 96, 192, 288, 383, 479, 575, 671, 766, 861],
    [0, 95, 191, 287, 383, 479, 575, 671, 765, 861],
    [0, 95, 191, 287, 383, 479, 575, 671, 765, 861],
    [0, 95, 191, 287, 383, 479, 575, 671, 765, 861],
    [0, 95, 191, 287, 383, 479, 574, 670, 765, 861],
    [0, 95, 191, 287, 383, 479, 574, 670, 765, 859],
    [0, 95, 191, 287, 383, 479, 575, 671, 767, 859],
]

# Visual identities supported by the actual sprite artwork. Uncertain matches
# are deliberately kept out of this map rather than coupled to a wrong front.
# Keys are one-based row/group coordinates printed on contact.png.
IDENTITIES = {
    (1, 1): ("professor_elm", "Professor Elm"),
    (1, 2): ("silver", "Silver"),
    (1, 3): ("steven", "Steven"),
    (1, 7): ("twins", "Twins"),
    (1, 8): ("youngster", "Youngster"),
    (1, 9): ("bug_catcher", "Bug Catcher"),
    (2, 1): ("lass", "Lass"),
    (2, 5): ("ace_trainer_m", "Ace Trainer M"),
    (2, 7): ("beauty", "Beauty"),
    (2, 8): ("ace_trainer_f", "Ace Trainer F"),
    (3, 3): ("pokefan_f", "Pokéfan F"),
    (3, 5): ("gentleman", "Gentleman"),
    (3, 6): ("swimmer_m", "Swimmer M"),
    (3, 7): ("swimmer_f", "Swimmer F"),
    (3, 8): ("scientist", "Scientist"),
    (3, 9): ("falkner", "Falkner"),
    (3, 10): ("bugsy", "Bugsy"),
    (4, 1): ("whitney", "Whitney"),
    (4, 2): ("morty", "Morty"),
    (4, 3): ("chuck", "Chuck"),
    (4, 4): ("jasmine", "Jasmine"),
    (4, 5): ("pryce", "Pryce"),
    (4, 6): ("clair", "Clair"),
    (4, 7): ("will", "Will"),
    (4, 8): ("koga", "Koga"),
    (4, 9): ("bruno", "Bruno"),
    (4, 10): ("karen", "Karen"),
    (5, 1): ("lance", "Lance"),
    (5, 3): ("lt_surge", "Lt. Surge"),
    (5, 4): ("sabrina", "Sabrina"),
    (5, 5): ("misty", "Misty"),
    (5, 6): ("erika", "Erika"),
    (5, 7): ("janine", "Janine"),
    (5, 8): ("brock", "Brock"),
    (5, 9): ("blaine", "Blaine"),
    (5, 10): ("blue", "Blue"),
    (6, 1): ("red", "Red"),
    (6, 2): ("giovanni", "Giovanni"),
    (6, 4): ("team_rocket_grunt_f", "Team Rocket Grunt F"),
    (6, 5): ("team_rocket_grunt_m", "Team Rocket Grunt M"),
    (6, 6): ("ariana", "Ariana"),
    (6, 7): ("archer", "Archer"),
    (6, 9): ("poke_maniac", "Poké Maniac"),
    (6, 10): ("biker", "Biker"),
    (7, 1): ("kimono_girl", "Kimono Girl"),
    (7, 3): ("sailor", "Sailor"),
    (7, 4): ("black_belt", "Black Belt"),
    (7, 5): ("juggler", "Juggler"),
}

CANDIDATES = {
    (1, 4): "Anciano con sombrero azul y adornos amarillos; posible Elder/Dragon Elder.",
    (1, 5): "Anciano con sombrero azul sin adornos; posible variante de Elder.",
    (1, 6): "Niño de pelo oscuro y ropa verde; no se confirma su clase de combate.",
    (1, 10): "Chico castaño con mochila; posible School Kid M.",
    (2, 2): "Chica castaña; posible School Kid F o NPC sin clase de combate.",
    (2, 3): "Chico castaño vestido de azul/blanco; posible Ace Trainer M.",
    (2, 4): "Chica rubia de coleta con ropa roja/negra; posible Ace Trainer F.",
    (2, 5): "Hombre de pelo oscuro recogido y traje rojo/naranja; posible Psychic M.",
    (2, 6): "Chica castaña de ropa rosa/azul; clase no confirmada.",
    (2, 8): "Mujer de coleta oscura y traje rojo/naranja; posible Psychic F.",
    (2, 9): "Anciano calvo, ropa oliva; NPC sin clase confirmada.",
    (2, 10): "Mujer con sombrero marrón y ropa roja/blanca; clase no confirmada.",
    (3, 1): "Anciano con pelo blanco lateral y ropa verde.",
    (3, 2): "Anciana con moño blanco y ropa marrón.",
    (3, 4): "Hombre de gafas y pelo azul oscuro; posible Super Nerd.",
    (5, 2): "Mujer de sombrero marrón y ropa clara; posible Daisy, sin confirmar.",
    (6, 3): "Hombre calvo con ropa gris/negra; clase no confirmada.",
    (6, 8): "Hombre con sombrero blanco/verde y ropa amarilla/naranja; posible Fisher.",
    (7, 2): "Mujer castaña de ropa lila/azul; posible madre/NPC.",
    (7, 6): "Mujer rubia de ropa violeta/negra; clase no confirmada.",
    (7, 7): "Anciano de gorro/pelo blanco alto y túnica azul; posible Elder.",
    (7, 8): "Mujer de pelo negro liso y ropa rosa/verde; posible Medium.",
    (7, 9): "Niña de pelo rosa y ropa verde/rosa; clase no confirmada.",
    (7, 10): "Niño o disfraz verde; clase no confirmada.",
    (8, 1): "Mujer de gorro azul y ropa roja; clase no confirmada.",
    (8, 2): "Hombre con gorra y uniforme burdeos; posible empleado/NPC.",
    (8, 3): "Mujer con gorra y uniforme burdeos; posible empleada/NPC.",
    (8, 4): "Anciano de pelo blanco y ropa verde.",
    (8, 5): "Hombre con sombrero negro y abrigo verde; posible PI.",
    (8, 6): "Hombre de pelo castaño y abrigo verde; clase no confirmada.",
    (8, 7): "Anciano calvo de barba blanca larga y ropa morada; posible Sage.",
    (8, 8): "Hombre de pelo morado y ropa gris; clase no confirmada.",
    (8, 9): "Hombre de sombrero oscuro, pelo turquesa y abrigo oscuro; clase no confirmada.",
    (8, 10): "Hombre con sombrero naranja y uniforme oscuro; clase no confirmada.",
}

PHYSICAL_LABELS = ["north_idle", "east_idle", "north_step_a", "west_step_a", "east_step_a", "south_idle", "west_idle", "east_step_b", "south_step_a", "west_step_b", "north_step_b", "south_step_b"]
TARGET_LABELS = ["south_idle", "south_step_a", "south_step_b", "north_idle", "north_step_a", "north_step_b", "west_idle", "west_step_a", "west_step_b", "east_idle", "east_step_a", "east_step_b"]
TARGET_ORDER = [5, 8, 11, 0, 2, 10, 6, 3, 9, 1, 4, 7]


def main():
    image = Image.open(SOURCE).convert("RGB")
    entries = []
    contact = Image.new("RGB", (10 * 112, 8 * 124), (35, 40, 45))
    draw = ImageDraw.Draw(contact)
    for row, origins in enumerate(ORIGINS_X):
        for column, x in enumerate(origins):
            end_x = (origins + [image.width])[column + 1]
            y = row * 128
            background = image.getpixel((x, y))
            identity = IDENTITIES.get((row + 1, column + 1))
            slug = identity[0] + "_hgss" if identity else f"hgss_ow_r{row + 1:02}_c{column + 1:02}"
            frames, rendered = [], []
            for index in range(12):
                frame_x = x + index % 3 * 32
                frame_y = y + index // 3 * 32
                # The last row of each 32 px cell is blank in the sheet.
                # Some contain unrelated neighboring backgrounds. Exclude it.
                # Footer starts at y=1022; preserve all artwork above it.
                width = min(32, end_x - frame_x)
                height = min(31, 1022 - frame_y)
                backgrounds = [list(background)]
                if (row, column, index) == (6, 8, 9):
                    # Two stray background pixels belonging to the left block.
                    backgrounds.append([80, 168, 80])
                rect = [frame_x, frame_y, width, height]
                frame = {"rect": rect, "background": list(background), "backgrounds": backgrounds, "canvas_offset": [0, 0], "canvas_size": [32, 32], "direction_phase": PHYSICAL_LABELS[index]}
                crop = image.crop((frame_x, frame_y, frame_x + width, frame_y + height)).convert("RGBA")
                transparent_colors = {tuple(color) for color in backgrounds}
                crop.putdata([(0, 0, 0, 0) if pixel[:3] in transparent_colors else pixel for pixel in crop.get_flattened_data()])
                canvas = Image.new("RGBA", (32, 32))
                canvas.paste(crop, (0, 0))
                frame["empty"] = canvas.getbbox() is None
                frame["opaque_bbox"] = list(canvas.getbbox()) if canvas.getbbox() else None
                frames.append(frame)
                rendered.append(canvas)
            mirrored_canvas = all(rendered[w].transpose(Image.Transpose.FLIP_LEFT_RIGHT).tobytes() == rendered[e].tobytes() for w, e in [(6, 1), (3, 4), (9, 7)])
            mirrored_art = all(rendered[w].crop(rendered[w].getbbox()).transpose(Image.Transpose.FLIP_LEFT_RIGHT).tobytes() == rendered[e].crop(rendered[e].getbbox()).tobytes() and rendered[w].crop(rendered[w].getbbox()).size == rendered[e].crop(rendered[e].getbbox()).size for w, e in [(6, 1), (3, 4), (9, 7)])
            target_order = TARGET_ORDER[:9] if mirrored_canvas else TARGET_ORDER[:]
            notes = ["Los doce frames originales están presentes.", "La fila inferior vacía se excluye del rectángulo y se rellena transparente para completar 32×32."]
            if not identity:
                notes.append(CANDIDATES.get((row + 1, column + 1), "Identidad no confirmada."))
            if mirrored_art and not mirrored_canvas:
                notes.append("Este es reflejo exacto del dibujo oeste pero su posición en el lienzo difiere; se conservan las cuatro direcciones para no cambiar el anclaje original.")
            entry = {"id": slug, "name": identity[1] if identity else f"OW HGSS sin identificar r{row + 1:02} c{column + 1:02}", "game": "hgss", "source": "entrenadores/26955.png", "source_group": {"row": row + 1, "column": column + 1, "rect": [x, y, end_x - x, min(128, 1022 - y)]}, "identity_status": "identified" if identity else "unidentified", "confidence": "high_visual" if identity else "unidentified", "frames": frames, "target_order": target_order, "target_labels": TARGET_LABELS[:len(target_order)], "all_directions_order": TARGET_ORDER, "east_mirror_of_west": mirrored_canvas, "east_art_is_mirrored_west": mirrored_art, "missing_frames": [PHYSICAL_LABELS[i] for i, frame in enumerate(frames) if frame["empty"]], "notes": notes}
            entries.append(entry)
            contact.paste(rendered[5].resize((96, 96), Image.Resampling.NEAREST), (column * 112 + 8, row * 124), rendered[5].resize((96, 96), Image.Resampling.NEAREST))
            draw.text((column * 112 + 4, row * 124 + 97), f"r{row + 1:02} c{column + 1:02}", fill="white")
            draw.text((column * 112 + 4, row * 124 + 109), identity[0][:16] if identity else "sin identificar", fill="white")
    result = {"schema_version": 1, "source": "entrenadores/26955.png", "sheet_size": list(image.size), "frame_canvas": [32, 32], "frame_order": "south idle, south step A/B, north idle, north step A/B, west idle, west step A/B, optional east idle/step A/B", "animation_mapping": "Fila fuente empaquetada; no confundir los tres frames de cada fila con tres direcciones completas.", "normalization": "Sin redimensionado. Quitar backgrounds y pegar en canvas32 en canvas_offset; índice0 de transparencia final magenta lo resuelve el ensamblador.", "credits": "Trainer Overworlds ripped by Dragoon. For TSR. Credit wanted but not needed (footer original).", "statistics": {"entities": len(entries), "identified": sum(entry["identity_status"] == "identified" for entry in entries), "unidentified": sum(entry["identity_status"] == "unidentified" for entry in entries), "source_frames": sum(len(entry["frames"]) for entry in entries), "missing_frames": sum(len(entry["missing_frames"]) for entry in entries), "east_mirrored_on_canvas": sum(entry["east_mirror_of_west"] for entry in entries), "east_mirrored_art": sum(entry["east_art_is_mirrored_west"] for entry in entries)}, "entries": entries}
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    contact.save(HERE / "contact.png")
    print(json.dumps(result["statistics"], ensure_ascii=False))
    print(OUTPUT.relative_to(ROOT))


if __name__ == "__main__":
    main()

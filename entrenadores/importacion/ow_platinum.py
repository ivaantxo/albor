"""Describe las celdas de OW de Platinum; nunca modifica las hojas originales."""
from pathlib import Path
import json
from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent
ORDER = [0, 3, 6, 1, 4, 7, 2, 5, 8]

# Identidades que se reconocen en la hoja. Las demás conservan un identificador
# de procedencia; no se asocian a un front por parecido de colores.
KNOWN = {
    (1, 2): "camper", (1, 3): "picnicker", (1, 4): "twins",
    (1, 11): "cameraman",
    (2, 3): "youngster", (2, 5): "sailor", (2, 8): "hiker",
    (2, 9): "scientist", (2, 10): "gentleman", (2, 11): "worker",
    (2, 12): "ninja_boy", (2, 13): "policeman",
    (2, 14): "gentleman_elder", (2, 15): "socialite", (2, 16): "cook",
    (3, 5): "cyclist_m", (3, 6): "cyclist_f", (3, 9): "school_kid_f",
    (3, 11): "old_woman", (3, 12): "old_woman_variant",
    (4, 1): "skier_m", (4, 2): "skier_f", (4, 3): "roughneck",
    (4, 4): "swimmer_m_water", (4, 5): "swimmer_f_water",
    (4, 6): "deliveryman", (4, 10): "ski_lift_m", (4, 11): "ski_lift_f",
    (5, 0): "cyrus", (5, 1): "galactic_grunt_m", (5, 2): "galactic_grunt_f",
    (5, 3): "mars", (5, 4): "saturn", (5, 5): "jupiter", (5, 6): "barry",
    (5, 7): "professor_rowan", (5, 9): "palmer", (5, 10): "riley",
    (5, 11): "cheryl", (5, 12): "johanna", (5, 13): "buck",
    (5, 14): "marley", (5, 15): "mira",
}


def entry(source, x, y, identity, key, extra=0):
    image = Image.open(ROOT / source).convert("RGB")
    frames = []
    for frame in range(9 + extra):
        rect = [x, y + frame * 32, 32, 32]
        frames.append({"rect": rect, "background": list(image.getpixel((rect[0], rect[1])))})
    return {
        "id": (identity + "_platinum") if identity else key,
        "identity": identity,
        "name": identity.replace("_", " ").title() if identity else key,
        "game": "platinum", "kind": "ow", "source": source,
        "source_key": key,
        "frames": frames, "target_order": ORDER,
        "extra_frames": list(range(9, 9 + extra)),
        "east_mirrored": True,
        "confidence": "identified" if identity else "unidentified",
        "notes": ["Este no está dibujado en la hoja: se refleja el oeste."],
    }


def main():
    entries = []
    for column, name in enumerate(["roark", "gardenia", "maylene", "crasher_wake", "fantina", "byron", "candice", "volkner"]):
        entries.append(entry("entrenadores/25790.png", 65 + 32 * column, 113, name, "platinum_leader_" + str(column)))
    for column, name in enumerate(["aaron", "bertha", "flint", "lucian", "cynthia"]):
        entries.append(entry("entrenadores/25790.png", 353 + 32 * column, 113, name, "platinum_elite_" + str(column)))
    for block, (y, count) in enumerate([(97, 17), (385, 17), (673, 17), (961, 17), (1249, 12), (1561, 16)]):
        for column in range(count):
            key = f"platinum_ow_b{block}_c{column:02d}"
            entries.append(entry("entrenadores/25791.png", 17 + column * 32, y,
                                 KNOWN.get((block, column)), key,
                                 3 if block == 5 and column >= 10 else 0))
    data = {"version": 1, "entries": entries,
            "credits": {"25790.png": "Spacemotion", "25791.png": "Spacemotion"},
            "target_slots": ["south_idle", "south_step_left", "south_step_right", "north_idle", "north_step_left", "north_step_right", "west_idle", "west_step_left", "west_step_right"]}
    (OUT / "ow_platinum.json").write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n")
    print(f"{len(entries)} OW descritos en {OUT / 'ow_platinum.json'}")


if __name__ == "__main__":
    main()

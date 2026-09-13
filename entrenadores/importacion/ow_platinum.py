"""Describe las celdas de OW de Platinum; nunca modifica las hojas originales."""
from pathlib import Path
import json
from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent
# Comprobado sobre líderes, NPC y Barry: las filas 3/4 miran al norte,
# las filas 5/6 al sur. Los dos pasos laterales siguen el orden 8/7 para
# coincidir con las fases de la hoja individual de Barry (47490.png).
ORDER = [0, 5, 6, 1, 3, 4, 2, 8, 7]

# Identidades que se reconocen en la hoja. Las demás conservan un identificador
# de procedencia; no se asocian a un front por parecido de colores.
KNOWN = {
    (0, 0): "ruin_maniac", (0, 2): "ace_trainer_m", (0, 3): "roughneck",
    (0, 5): "black_belt", (0, 6): "pokemon_breeder_m", (0, 7): "rich_boy",
    (0, 10): "battle_girl", (0, 11): "beauty", (0, 12): "ace_trainer_f",
    (0, 13): "idol", (0, 14): "socialite", (0, 15): "swimmer_f", (0, 16): "maid",
    (1, 0): "youngster", (1, 1): "school_kid_f",
    (1, 2): "camper", (1, 3): "picnicker", (1, 4): "twins",
    (1, 7): "waiter", (1, 8): "waitress", (1, 11): "cameraman",
    (1, 12): "reporter", (1, 13): "cowgirl", (1, 14): "jogger", (1, 15): "fisher",
    (2, 0): "ace_trainer_snow_m", (2, 1): "ace_trainer_snow_f",
    (2, 5): "sailor", (2, 6): "hiker", (2, 8): "pokefan_m",
    (2, 9): "scientist", (2, 10): "gentleman", (2, 11): "worker",
    (2, 12): "clown", (2, 13): "policeman",
    (3, 0): "tuber_m", (3, 1): "tuber_f", (3, 5): "cycler_m", (3, 6): "cycler_f",
    (3, 7): "psychic_m", (3, 8): "psychic_f",
    (4, 1): "skier_m", (4, 2): "skier_f",
    (5, 0): "cyrus", (5, 1): "galactic_grunt_m", (5, 2): "galactic_grunt_f",
    (5, 3): "mars", (5, 4): "saturn", (5, 5): "jupiter", (5, 6): "barry",
    (5, 7): "professor_rowan", (5, 8): "looker", (5, 9): "palmer", (5, 10): "riley",
    (5, 11): "cheryl", (5, 13): "buck",
    (5, 14): "marley", (5, 15): "mira",
}

# Son pistas para revisión humana, NO asociaciones de paleta/front.
CANDIDATES = {
    (0, 1): "old_man", (0, 4): "pokemon_ranger_m", (0, 8): "lass",
    (0, 9): "school_kid_m", (1, 5): "old_man", (1, 6): "parasol_lady",
    (1, 9): "young_man", (1, 10): "young_woman", (1, 16): "old_man",
    (2, 2): "bug_catcher", (2, 3): "dragon_tamer", (2, 4): "bird_keeper",
    (2, 7): "young_woman", (2, 14): "veteran", (2, 15): "artist", (2, 16): "cook",
    (3, 2): "dragon_tamer", (3, 3): "bird_keeper", (3, 4): "pokemon_ranger_f",
    (3, 9): "lady", (3, 10): "old_man", (3, 11): "old_woman", (3, 12): "old_woman",
    (3, 13): "swimmer_f", (3, 14): "swimmer_m", (3, 15): "worker",
    (3, 16): "reporter", (4, 0): "reporter", (4, 3): "man_with_sunglasses",
    (4, 4): "swimmer_m", (4, 5): "swimmer_f", (4, 6): "deliveryman",
    (4, 7): "school_kid_m", (4, 8): "school_kid_f", (4, 9): "young_woman",
    (4, 10): "ski_lift_m", (4, 11): "ski_lift_f", (5, 12): "johanna",
}


def entry(source, x, y, identity, key, extra=0):
    image = Image.open(ROOT / source).convert("RGB")
    frames = []
    for frame in range(9 + extra):
        rect = [x, y + frame * 32, 32, 32]
        frames.append({"rect": rect, "background": list(image.getpixel((rect[0], rect[1])))})
    result = {
        "id": (identity + "_platinum") if identity else key,
        "identity": identity,
        "name": identity.replace("_", " ").title() if identity else key,
        "game": "platinum", "kind": "ow", "source": source,
        "source_key": key,
        "frames": frames, "target_order": ORDER,
        "extra_frames": list(range(9, 9 + extra)),
        "east_mirrored": True,
        "confidence": "identified" if identity else "unidentified",
        "notes": ["Este no está dibujado en la hoja: se refleja el oeste.",
                  "Orden original: S quieto,N quieto,O quieto,N paso1,N paso2,S paso1,S paso2,O paso2,O paso1."],
    }
    return result


def main():
    entries = []
    for column, name in enumerate(["roark", "gardenia", "maylene", "crasher_wake", "fantina", "byron", "candice", "volkner"]):
        entries.append(entry("entrenadores/25790.png", 65 + 32 * column, 113, name, "platinum_leader_" + str(column)))
    for column, name in enumerate(["aaron", "bertha", "flint", "lucian", "cynthia"]):
        entries.append(entry("entrenadores/25790.png", 353 + 32 * column, 113, name, "platinum_elite_" + str(column)))
    for block, (y, count) in enumerate([(97, 17), (385, 17), (673, 17), (961, 17), (1249, 12), (1561, 16)]):
        for column in range(count):
            key = f"platinum_ow_b{block}_c{column:02d}"
            current = entry("entrenadores/25791.png", 17 + column * 32, y,
                            KNOWN.get((block, column)), key,
                            3 if block == 5 and column >= 10 else 0)
            if current["identity"] is None and (block, column) in CANDIDATES:
                current["candidate_identity"] = CANDIDATES[(block, column)]
                current["notes"].append("Candidato sin confirmar; mantener en cajón de sastre sin asociar a su front.")
            entries.append(current)
    front_ids = {entry["id"] for entry in json.loads((OUT / "fronts.json").read_text())["entries"]}
    for current in entries:
        current["front_id"] = current["id"] if current["id"] in front_ids else None
    assert len({e["id"] for e in entries}) == len(entries)
    data = {"version": 1, "entries": entries,
            "credits": {"25790.png": "Spacemotion", "25791.png": "Spacemotion"},
            "target_slots": ["south_idle", "south_step_left", "south_step_right", "north_idle", "north_step_left", "north_step_right", "west_idle", "west_step_left", "west_step_right"]}
    (OUT / "ow_platinum.json").write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n")
    print(f"{len(entries)} OW: {sum(e['identity'] is not None for e in entries)} identificados; "
          f"{sum(e['front_id'] is not None for e in entries)} fronts asociados; "
          f"{sum(e['identity'] is None for e in entries)} sin forzar identidad.")


if __name__ == "__main__":
    main()

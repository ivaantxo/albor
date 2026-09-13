"""Inventario exacto del OW de Barry de 47490.png, sin modificar gráficos."""
from pathlib import Path
import hashlib
import json
from PIL import Image, ImageOps

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent


def main():
    image = Image.open(ROOT / "entrenadores/47490.png").convert("RGB")
    crops = []
    frames = []
    directions = ["south", "north", "west", "east"]
    phases = ["idle", "step_1", "idle_repeated", "step_2"]
    for row in range(4):
        for column in range(4):
            x,y = 2 + 34*column, 2 + 34*row
            crop = image.crop((x,y,x+32,y+32))
            crops.append(crop)
            frames.append({"rect": [x,y,32,32], "background": list(crop.getpixel((0,0))),
                           "direction": directions[row], "phase": phases[column],
                           "rgb_sha256": hashlib.sha256(crop.tobytes()).hexdigest()})
    duplicates = {str(4*r+2): 4*r for r in range(4)}
    mirrored = {str(12+c): 8+c for c in range(4)}
    assert all(crops[int(a)].tobytes()==crops[b].tobytes() for a,b in duplicates.items())
    assert all(crops[int(a)].tobytes()==ImageOps.mirror(crops[b]).tobytes() for a,b in mirrored.items())
    # Verify phase mapping to the same trainer in the other supplied sheet.
    source = Image.open(ROOT / "entrenadores/25791.png").convert("RGB")
    def mask(crop):
        background = crop.getpixel((0,0))
        return bytes(c != background for c in crop.get_flattened_data())
    equivalent = [0,4,8,5,7,1,3,11,9]
    for source_frame, barry_frame in enumerate(equivalent):
        y = 1561 + 32*source_frame
        other = source.crop((209,y,241,y+32))
        assert mask(other)==mask(crops[barry_frame]), (source_frame,barry_frame)
    entry = {
        "id": "barry_47490", "identity": "barry", "name": "Barry — hoja individual",
        "game": "platinum", "kind": "ow", "source": "entrenadores/47490.png",
        "source_key": "barry_47490", "front_id": "barry_47490", "frames": frames,
        "target_order": [0,1,3,4,5,7,8,9,11],
        "extra_frames": [2,6,10,12,13,14,15], "east_mirrored": True,
        "confidence": "identified", "duplicate_frames": duplicates,
        "east_mirror_frames": mirrored,
        "equivalent_25791_frame_to_47490_frame": equivalent,
        "notes": ["Cada fila contiene quieto,paso1,quieto idéntico,paso2; filas S,N,O,E.",
                  "Las cuatro imágenes este son espejos exactos píxel a píxel del oeste, sin desplazamientos.",
                  "Se conservan todos los frames originales; target_order selecciona los nueve necesarios.",
                  "Las nueve máscaras de las fases coinciden exactamente con Barry de 25791.png."],
    }
    data = {"version": 1, "entries": [entry], "credits": {"47490.png": "redblueyellow"},
            "target_slots": ["south_idle","south_step_left","south_step_right", "north_idle",
                             "north_step_left","north_step_right","west_idle","west_step_left","west_step_right"]}
    (OUT / "ow_barry.json").write_text(json.dumps(data,indent=2,ensure_ascii=False)+"\n")
    print("Barry: 16 originales, 9 seleccionados; 4 duplicados idle y 4 espejos este verificados.")


if __name__ == "__main__":
    main()

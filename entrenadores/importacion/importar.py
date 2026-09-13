#!/usr/bin/env python3
"""Importación reproducible de las hojas aportadas; no modifica las fuentes.

Ejecutar con desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/importar.py
Los rectángulos y las identidades se revisan en fronts.json y ow_*.json.
"""
from collections import Counter
from functools import lru_cache
import hashlib
import json
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
DEST = ROOT / "graphics/entrenadores"
MAGENTA = (255, 0, 255)
TRANSPARENT = (*MAGENTA, 0)
SLOTS = [f"{direction}_{phase}" for direction in ("sur", "norte", "oeste", "este")
         for phase in ("reposo", "paso_izquierda", "paso_derecha")]


def write_json(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n")


@lru_cache(maxsize=None)
def source_image(source):
    return Image.open(ROOT / source).convert("RGBA")


def extract(source, spec, size):
    if spec is None:
        return Image.new("RGBA", size, TRANSPARENT)
    x, y, w, h = spec["rect"]
    src = source_image(source)
    assert 0 <= x < x + w <= src.width and 0 <= y < y + h <= src.height, spec
    rect = src.crop((x, y, x + w, y + h))
    backgrounds = {tuple(c) for c in spec.get("backgrounds", [spec["background"]])}
    rect.putdata([TRANSPARENT if p[3] == 0 or p[:3] in backgrounds else p
                  for p in rect.get_flattened_data()])
    result = Image.new("RGBA", size, TRANSPARENT)
    ox, oy = spec.get("canvas_offset", [0, 0])
    assert ox >= 0 and oy >= 0 and ox + w <= size[0] and oy + h <= size[1], spec
    result.paste(rect, (ox, oy))
    return result


def strip(frames):
    assert frames and len({f.size for f in frames}) == 1
    w, h = frames[0].size
    result = Image.new("RGBA", (w * len(frames), h), TRANSPARENT)
    for i, frame in enumerate(frames):
        result.paste(frame, (w * i, 0))
    return result


def colors(image):
    return Counter(p[:3] for p in image.get_flattened_data() if p[3])


@lru_cache(maxsize=None)
def lab(rgb):
    """sRGB/D65 -> CIELAB; ΔE76, sin dithering ni colores añadidos al front."""
    c = [v / 255 for v in rgb]
    r, g, b = [v / 12.92 if v <= 0.04045 else ((v + 0.055) / 1.055) ** 2.4 for v in c]
    xyz = ((.4124564*r + .3575761*g + .1804375*b) / .95047,
           .2126729*r + .7151522*g + .0721750*b,
           (.0193339*r + .1191920*g + .9503041*b) / 1.08883)
    x, y, z = [v ** (1/3) if v > (6/29)**3 else v / (3*(6/29)**2) + 4/29 for v in xyz]
    return (116*y - 16, 500*(x-y), 200*(y-z))


def delta(a, b):
    return sum((x-y)**2 for x, y in zip(lab(a), lab(b))) ** .5


def index_image(image, opaque_palette, exact=False):
    assert 1 <= len(opaque_palette) <= 15 and MAGENTA not in opaque_palette
    counts = colors(image)
    mapping = {c: min(opaque_palette, key=lambda p: delta(c, p)) for c in counts}
    if exact:
        assert all(c == p for c, p in mapping.items()), "El front no se puede recolorear"
    indices = {c: i + 1 for i, c in enumerate(opaque_palette)}
    pal = [MAGENTA] + opaque_palette
    pal += [opaque_palette[-1]] * (16 - len(pal))
    indexed = Image.new("P", image.size, 0)
    indexed.putpalette([v for c in pal for v in c])
    indexed.putdata([0 if not p[3] else indices[mapping[p[:3]]] for p in image.get_flattened_data()])
    indexed.info["transparency"] = 0
    changes = [{"original": c, "adaptado": p, "pixeles": counts[c], "delta_e_76": round(delta(c,p), 3)}
               for c, p in sorted(mapping.items()) if c != p]
    total = sum(counts.values())
    report = {"colores_originales": len(counts), "colores_modificados": len(changes),
              "pixeles_modificados": sum(c["pixeles"] for c in changes),
              "pixeles_opacos": total,
              "delta_e_medio": round(sum(counts[c]*delta(c,p) for c,p in mapping.items()) / max(1,total), 3),
              "delta_e_maximo": round(max((delta(c,p) for c,p in mapping.items()), default=0), 3),
              "conversiones": changes}
    return indexed, pal, report


def own_palette(image):
    palette = sorted(colors(image))
    assert palette, "Un OW sin front debe contener píxeles"
    if len(palette) <= 15:
        return palette
    # Sólo para OW sin front si una futura hoja excede 15 colores. Nunca fronts.
    pixels = [p[:3] for p in image.get_flattened_data() if p[3]]
    sample = Image.new("RGB", (len(pixels), 1))
    sample.putdata(pixels)
    reduced = sample.quantize(colors=15, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
    return sorted(set(reduced.convert("RGB").get_flattened_data()))


def import_entry(identifier, front, ow):
    directory = DEST / identifier if front else DEST / "cajon_de_sastre" / identifier
    directory.mkdir(parents=True, exist_ok=True)
    front_frames = [extract(front["source"], spec, (80, 80)) for spec in front["frames"]] if front else [extract("", None, (80, 80))]
    original_ow_frames = [extract(ow["source"], spec, (32, 32)) for spec in ow["frames"]] if ow else []
    order = ow["target_order"] if ow else [None] * 9
    ow_frames = [original_ow_frames[i] if i is not None else extract("", None, (32,32)) for i in order]
    front_image, ow_image = strip(front_frames), strip(ow_frames)
    palette = sorted(colors(front_image)) if front else own_palette(ow_image)
    assert len(palette) <= 15, identifier
    front_indexed, pal, _ = index_image(front_image, palette, exact=True)
    ow_indexed, _, conversion = index_image(ow_image, palette)
    front_indexed.save(directory / "front.png", bits=4, transparency=0)
    ow_indexed.save(directory / "ow.png", bits=4, transparency=0)
    (directory / f"{identifier}.pal").write_text("JASC-PAL\n0100\n16\n" + "\n".join(" ".join(map(str,c)) for c in pal) + "\n")
    # Verify what is actually persisted, including transparency and shared indices.
    saved_front = Image.open(directory / "front.png")
    saved_ow = Image.open(directory / "ow.png")
    assert saved_front.convert("RGBA").tobytes() == front_image.tobytes(), identifier
    assert saved_front.getpalette() == saved_ow.getpalette(), identifier
    assert saved_front.getpalette()[:3] == list(MAGENTA)
    assert saved_ow.convert("RGBA").getchannel("A").tobytes() == ow_image.getchannel("A").tobytes(), identifier
    missing = [{"grafico": "front", "frame": 0, "motivo": "No hay front identificado para este OW"}] if not front else []
    for i, frame in enumerate(ow_frames):
        if not frame.getchannel("A").getbbox():
            missing.append({"grafico": "ow", "frame": i, "pose": SLOTS[i],
                            "motivo": "No hay OW identificado" if not ow else "Celda ausente o vacía en la fuente"})
    originals = []
    if ow:
        orig = directory / "originales"
        orig.mkdir(exist_ok=True)
        strip(ow_frames).save(orig / "ow.png")
        strip(original_ow_frames).save(orig / "ow_todas_las_poses.png")
        originals.extend(["originales/ow.png", "originales/ow_todas_las_poses.png"])
        # Conservar también cada celda con su fondo original, antes del enmascarado.
        raw = []
        for spec in ow["frames"]:
            if spec is None:
                raw.append(extract("", None, (32,32)))
                continue
            x,y,w,h = spec["rect"]
            canvas = Image.new("RGBA", (32,32), TRANSPARENT)
            canvas.paste(source_image(ow["source"]).crop((x,y,x+w,y+h)), tuple(spec.get("canvas_offset",[0,0])))
            raw.append(canvas)
        strip(raw).save(orig / "ow_celdas_fuente.png")
        originals.append("originales/ow_celdas_fuente.png")
    extras = []
    if front:
        for extra in front.get("extras", []):
            if extra["kind"] == "ow" and ow:
                continue
            size = tuple(extra["frames"][0]["rect"][2:])
            frames = [extract(extra["source"], f, size) for f in extra["frames"]]
            path = directory / "originales" / (extra["name"] + ".png")
            path.parent.mkdir(exist_ok=True)
            strip(frames).save(path)
            extras.append({"archivo": str(path.relative_to(directory)), "tipo": extra["kind"],
                           "frame_size": size, "frames": len(frames), "integrado": False,
                           "motivo": "Extra preservado sin alterar; esta importación registra fronts y OW"})
    mirrored = bool(ow.get("east_mirrored", ow.get("east_mirror_of_west", len(order) == 9))) if ow else True
    metadata = {
        "id": identifier, "name": (front or ow)["name"], "game": (front or ow)["game"],
        "directory": str(directory.relative_to(ROOT)), "has_front": bool(front), "has_ow": bool(ow),
        "front_frames": len(front_frames), "ow_frames": len(ow_frames), "east_mirrored": mirrored,
        "front_frame_size": [80,80], "ow_frame_size": [32,32], "ow_slots": SLOTS[:len(order)],
        "palette": f"{identifier}.pal", "palette_origin": "front" if front else "ow_provisional_sin_front",
        "palette_rgb": pal, "front_colors_unchanged": True if front else None,
        "ow_palette_conversion": conversion, "missing": missing, "originals": originals, "extras": extras,
        "animation": {"available": bool(front and len(front_frames) > 1),
                      "order": list(range(len(front_frames))),
                      "durations_ticks": [12] * (len(front_frames)-1) + [24] if len(front_frames)>1 else [],
                      "note": "Secuencia de entrada propuesta: las hojas no contienen los tiempos originales; reposo en frame 0."},
        "front_source": front, "ow_source": ow,
        "code": {"front": "TRAINER_PIC_" + identifier.upper() if front else None,
                 "ow": "OBJ_EVENT_GFX_" + identifier.upper() if ow else None,
                 "palette": "gPaletaEntrenador_" + identifier},
    }
    write_json(directory / "importacion.json", metadata)
    return metadata


def report(entries, source_hashes):
    counts = {"carpetas": len(entries), "fronts": sum(e["has_front"] for e in entries),
              "frames_front": sum(e["front_frames"] for e in entries if e["has_front"]),
              "fronts_con_animacion": sum(e["animation"]["available"] for e in entries),
              "ow": sum(e["has_ow"] for e in entries),
              "parejas": sum(e["has_front"] and e["has_ow"] for e in entries),
              "solo_front": sum(e["has_front"] and not e["has_ow"] for e in entries),
              "cajon_de_sastre": sum(not e["has_front"] for e in entries),
              "ow_recoloreados": sum(bool(e["ow_palette_conversion"]["colores_modificados"]) for e in entries),
              "ow_con_este_propio": sum(e["has_ow"] and not e["east_mirrored"] for e in entries),
              "frames_ausentes": sum(len(e["missing"]) for e in entries)}
    write_json(HERE / "catalogo.json", {"version": 1, "counts": counts, "sources_sha256": source_hashes, "entries": entries})
    lines = ["# Importación de entrenadores", "",
             "Fronts de 80×80 y OW de 32×32 por frame. Las tiras se leen horizontalmente, de izquierda a derecha.", "",
             "## Resultado", ""]
    lines += [f"- **{v}** {k.replace('_', ' ')}." for k,v in counts.items()]
    lines += ["", "## Formato y paletas", "",
              "Cada carpeta contiene `front.png`, `ow.png`, `<id>.pal` e `importacion.json`. Los PNG son indexados, comparten exactamente los mismos 16 índices y el índice 0 es magenta transparente (255,0,255). Los píxeles opacos del front y su posición se conservan exactamente, también al unir sus poses en una paleta.", "",
              "El OW se adapta al color más cercano del front mediante distancia CIELAB ΔE76, sin dithering. La paleta no gana colores procedentes del OW. En `originales/ow.png` está la tira anterior a esa conversión; `ow_todas_las_poses.png` conserva además todas las poses originales y `ow_celdas_fuente.png` conserva sus fondos. Las hojas aportadas tampoco se modifican. Las estadísticas y conversiones color a color están en cada `importacion.json`.", "",
              "Los OW sin correspondencia segura se separan en `graphics/entrenadores/cajon_de_sastre/<id>/`. Tienen un front transparente de reserva y una paleta provisional propia hasta identificar su front. Los fronts identificados sin OW conservan nueve celdas transparentes. No se han inventado dibujos para completar ausencias.", "",
              "| Frames OW | Dirección | Orden |", "|---|---|---|",
              "| 0, 1, 2 | Sur / frente | Reposo, paso izquierda, paso derecha |",
              "| 3, 4, 5 | Norte / espalda | Reposo, paso izquierda, paso derecha |",
              "| 6, 7, 8 | Oeste | Reposo, paso izquierda, paso derecha |",
              "| 9, 10, 11 | Este, cuando es distinto | Reposo, paso izquierda, paso derecha |", "",
              "Si la tira tiene nueve frames, el este usa el oeste reflejado. No se elimina un este dibujado si difiere por algún píxel o por su posición. En las hojas que sólo incluyen oeste se utiliza ese reflejo convencional. Las dos fases de paso conservan su orden en la fuente; el juego reproduce paso A → reposo → paso B → reposo.", "",
              "## Animaciones y código", "",
              "Se registran todos los fronts disponibles y todos los OW disponibles, incluidos los del cajón de sastre con su ID de procedencia. Los placeholders transparentes no se registran como recursos utilizables. Las constantes exactas aparecen en el catálogo inferior y en los metadatos.", "",
              "Los fronts con varias poses usan una entrada secuencial de 12 ticks por pose y 24 en la última, y regresan al frame 0. Es una temporización propuesta, porque las hojas PNG no aportan la secuencia temporal original. Las variantes censuradas y UNUSED permanecen independientes. Los backs y el retrato alto de Barry se conservan como extras originales; no se recortan ni deforman para hacerlos pasar por un front.", "",
              "El motor admite los 80×80 completos en combate y menús. Las transiciones antiguas de mugshot generan una vista temporal de 64×64 en RAM, centrada horizontalmente y alineada arriba; los archivos originales y los sprites de combate mantienen 80×80. No se asignan estos gráficos a equipos o mapas existentes automáticamente.", "",
              "Ejemplo de uso en un entrenador existente: `.trainerPic = TRAINER_PIC_CYNTHIA_PLATINUM`. En un objeto de mapa: `\"graphics_id\": \"OBJ_EVENT_GFX_CYNTHIA_PLATINUM\"`. La paleta compartida se carga desde las tablas registradas, sin indicarla en el mapa.", "",
              "Los IDs existentes se conservan y los nuevos se añaden al final. Revisar el diff de las constantes antes de reimportar tras añadir o renombrar entidades, porque las entradas nuevas se ordenan por ID.", "",
              "## Reproducir", "", "Desde la raíz del repositorio:", "", "```sh",
              "desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/inventariar_fronts.py",
              "desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_platinum.py",
              "desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_hgss/build_manifest.py",
              "desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_barry.py",
              "desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/importar.py", "```", "",
              "Las correcciones de identidades y rectángulos se realizan en los generadores de manifiestos. El importador valida dimensiones, límites, paleta compartida, transparencia y conservación exacta de todos los fronts al guardar. Los PNG generados se reemplazan al reimportar: conserva tus modificaciones artísticas fuera de este paso o actualiza las fuentes.", "",
              "## Faltantes", "", "| Carpeta | Frames transparentes pendientes |", "|---|---|"]
    for e in entries:
        if e["missing"]:
            grouped = "front 0" if not e["has_front"] else "OW 0–8 (sin OW identificado)"
            if e["has_front"] and e["has_ow"]:
                grouped = ", ".join(f"{m['grafico']} {m['frame']}" for m in e["missing"])
            lines.append(f"| [{e['id']}](../../{e['directory']}) | {grouped} |")
    lines += ["", "## Catálogo e identificadores", "", "| Carpeta | Front | OW | Conversión OW |", "|---|---|---|---|"]
    for e in entries:
        lines.append(f"| [{e['id']}](../../{e['directory']}) | {e['code']['front'] or 'Pendiente'} | {e['code']['ow'] or 'Pendiente'} | {e['ow_palette_conversion']['pixeles_modificados']} píxeles |")
    lines += ["", "## Fuentes conservadas", "", "Las hojas conservan sus créditos originales: MufasaKong (fronts), Spacemotion (OW Platinum), Dragoon (OW HGSS) y redblueyellow (Barry). Los manifiestos detallan la procedencia de cada celda.", ""]
    (HERE / "INFORME.md").write_text("\n".join(lines))
    return counts


def main():
    fronts = json.loads((HERE / "fronts.json").read_text())["entries"]
    ow_entries = sum((json.loads((HERE / file).read_text())["entries"]
                      for file in ("ow_platinum.json", "ow_hgss.json", "ow_barry.json")), [])
    sources = sorted({e["source"] for e in fronts + ow_entries})
    hashes = {s: hashlib.sha256((ROOT/s).read_bytes()).hexdigest() for s in sources}
    front_ids = {f["id"] for f in fronts}
    assert len(front_ids) == len(fronts)
    by_id = {}
    for ow in ow_entries:
        assert ow["id"] not in by_id, f"Identidad OW duplicada: {ow['id']}"
        by_id[ow["id"]] = ow
    entries = [import_entry(f["id"], f, by_id.pop(f["id"], None)) for f in fronts]
    entries += [import_entry(ow["id"], None, ow) for ow in by_id.values()]
    entries.sort(key=lambda e: e["id"])
    assert len(entries) == len({e['id'] for e in entries})
    assert sum(e["has_front"] for e in entries) == len(fronts)
    assert sum(e["has_ow"] for e in entries) == len(ow_entries)
    assert all(hashlib.sha256((ROOT/s).read_bytes()).hexdigest() == digest for s,digest in hashes.items())
    from generar_codigo import generar
    generar(entries)
    print(json.dumps(report(entries, hashes), indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

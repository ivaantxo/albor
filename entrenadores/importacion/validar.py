#!/usr/bin/env python3
"""Independent checks of imported trainer artwork and optional compiled graphics.

Usage (from any directory, using an interpreter with Pillow):
    python entrenadores/importacion/validar.py [--compilados]

No importer or generator helpers are used. The validator reads catalogo.json,
the original sheets, saved PNGs and JASC palettes. --compilados also decodes GBA
4bpp tiles and LZ77 streams to compare every palette index, including index zero.
Only validacion.json is written; source sheets and generated assets are read-only.
"""

import argparse
from datetime import datetime, timezone
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import struct

from PIL import Image


HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
MAGENTA = (255, 0, 255)
TRANSPARENT = MAGENTA + (0,)


def require(condition, explanation):
    if not condition:
        raise ValueError(explanation)


def normalized_rgb(image):
    """RGB bytes in raster order; transparent pixels have canonical magenta RGB."""
    rgba = image.convert("RGBA")
    return bytes(channel for pixel in rgba.get_flattened_data()
                 for channel in (MAGENTA if pixel[3] == 0 else pixel[:3]))


@lru_cache(maxsize=None)
def source_image(relative_path):
    return Image.open(ROOT / relative_path).convert("RGBA")


def source_frame(source, specification, side, keep_background=False):
    """Reconstruct source geometry using direct coordinate checks, without helpers."""
    result = Image.new("RGBA", (side, side), TRANSPARENT)
    if specification is None:
        return result
    x, y, width, height = specification["rect"]
    offset_x, offset_y = specification.get("canvas_offset", [0, 0])
    image = source_image(source)
    require(0 <= x < x + width <= image.width and 0 <= y < y + height <= image.height,
            f"Rectángulo fuente fuera de la hoja: {specification['rect']}")
    require(0 <= offset_x <= side - width and 0 <= offset_y <= side - height,
            "El offset fuente desborda el frame final")
    backgrounds = {tuple(color) for color in specification.get("backgrounds", [specification["background"]])}
    output = result.load()
    pixels = image.load()
    for local_y in range(height):
        for local_x in range(width):
            value = pixels[x + local_x, y + local_y]
            if keep_background or (value[3] and value[:3] not in backgrounds):
                output[offset_x + local_x, offset_y + local_y] = value
    return result


def combine_frames(frames, side):
    result = Image.new("RGBA", (side * len(frames), side), TRANSPARENT)
    for index, frame in enumerate(frames):
        result.paste(frame, (side * index, 0))
    return result


def jasc_palette(path):
    lines = path.read_text(encoding="utf-8").splitlines()
    require(lines[:3] == ["JASC-PAL", "0100", "16"], f"Paleta JASC inválida: {path.name}")
    require(len(lines) == 19, f"{path.name}: debe contener exactamente dieciséis colores")
    palette = [tuple(map(int, line.split())) for line in lines[3:]]
    require(all(len(color) == 3 and all(0 <= value <= 255 for value in color) for color in palette),
            f"Canales RGB inválidos: {path.name}")
    return palette


def indexed_png(path, side, count, palette):
    image = Image.open(path)
    image.load()
    require(image.mode == "P", f"{path.name}: modo {image.mode}, debe ser P")
    require(image.size == (side * count, side), f"{path.name}: dimensiones {image.size} incorrectas")
    values = image.getpalette()
    require(values is not None and len(values) == 48, f"{path.name}: PLTE debe tener dieciséis colores")
    require(values == [channel for color in palette for channel in color], f"{path.name}: paleta PNG distinta de la paleta compartida")
    indices = image.tobytes()
    require(all(index < 16 for index in indices), f"{path.name}: contiene índices fuera de 0..15")
    rgba = image.convert("RGBA")
    require(all(pixel[3] == (0 if index == 0 else 255)
                for pixel, index in zip(rgba.get_flattened_data(), indices)),
            f"{path.name}: sólo el índice cero debe ser transparente")
    return image


def decode_4bpp(data, side, frames):
    """Decode frame-major, row-major 8x8 tiles into a horizontal PNG index raster."""
    require(side % 8 == 0, "Dimensiones no divisibles por ocho")
    require(len(data) == side * side * frames // 2, "Tamaño 4bpp distinto de los frames declarados")
    width = side * frames
    output = bytearray(width * side)
    bytes_per_frame = side * side // 2
    tiles_per_row = side // 8
    for frame in range(frames):
        for y in range(side):
            for x in range(side):
                tile = (y // 8) * tiles_per_row + x // 8
                offset = frame * bytes_per_frame + tile * 32 + (y % 8) * 4 + (x % 8) // 2
                output[y * width + frame * side + x] = (data[offset] >> (4 * (x % 2))) & 15
    return bytes(output)


def decode_lz77(data):
    require(len(data) >= 4 and data[0] == 0x10, "Cabecera LZ77 GBA inválida")
    expected = int.from_bytes(data[1:4], "little")
    require(expected > 0, "LZ77 declara tamaño cero")
    output = bytearray()
    cursor = 4
    while len(output) < expected:
        require(cursor < len(data), "LZ77 truncado antes de byte de control")
        flags = data[cursor]
        cursor += 1
        for bit in range(7, -1, -1):
            if len(output) >= expected:
                break
            if flags & (1 << bit):
                require(cursor + 2 <= len(data), "LZ77 truncado en referencia")
                token = int.from_bytes(data[cursor:cursor + 2], "big")
                cursor += 2
                length, distance = (token >> 12) + 3, (token & 0xFFF) + 1
                require(distance <= len(output), "LZ77 referencia bytes anteriores al inicio")
                require(len(output) + length <= expected, "LZ77 referencia desborda el tamaño declarado")
                for _ in range(length):
                    output.append(output[-distance])
            else:
                require(cursor < len(data), "LZ77 truncado en literal")
                output.append(data[cursor])
                cursor += 1
    return bytes(output)


def compiled_entry(directory, entry, front, ow, palette):
    checked = []
    palette_path = directory / f"{entry['id']}.gbapal"
    palette_bytes = palette_path.read_bytes()
    require(len(palette_bytes) == 32, ".gbapal debe ocupar 32 bytes")
    expected_words = [(r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10) for r, g, b in palette]
    require(list(struct.unpack("<16H", palette_bytes)) == expected_words, ".gbapal no coincide con los RGB de cinco bits de la paleta")
    checked.append(palette_path.name)
    for kind, side, image in [("front", 80, front), ("ow", 32, ow)]:
        if not entry[f"has_{kind}"]:
            continue  # Placeholders have no code reference and are not required build targets.
        count = entry[f"{kind}_frames"]
        path = directory / f"{kind}.4bpp"
        data = path.read_bytes()
        require(decode_4bpp(data, side, count) == image.tobytes(),
                f"{path.name}: los índices decodificados no coinciden con cada píxel del PNG")
        checked.append(path.name)
        if kind == "front":
            compressed_path = directory / "front.4bpp.lz"
            compressed = compressed_path.read_bytes()
            require(int.from_bytes(compressed[1:4], "little") == len(data), "LZ77 declara un tamaño distinto del front completo")
            require(decode_lz77(compressed) == data, "LZ77 no reproduce exactamente front.4bpp")
            checked.append(compressed_path.name)
    return checked


def validate_entry(entry, compilados):
    directory = ROOT / entry["directory"]
    palette = jasc_palette(directory / entry["palette"])
    require(palette[0] == MAGENTA, "El índice cero de la paleta debe ser magenta")
    require(all(color != MAGENTA for color in palette[1:]), "Magenta no debe ocupar índices opacos")
    require(palette == list(map(tuple, entry["palette_rgb"])), "Paleta distinta de catalogo.json")
    front = indexed_png(directory / "front.png", 80, entry["front_frames"], palette)
    ow = indexed_png(directory / "ow.png", 32, entry["ow_frames"], palette)
    front_source = entry.get("front_source")
    require(bool(front_source) == entry["has_front"], "has_front y front_source difieren")
    front_hashes = []
    if front_source:
        require(len(front_source["frames"]) == entry["front_frames"], "Número de frames front distinto de la fuente")
        for index, specification in enumerate(front_source["frames"]):
            frame = front.crop((index * 80, 0, (index + 1) * 80, 80))
            expected = specification["normalized_rgb_sha256"]
            digest = hashlib.sha256(normalized_rgb(frame)).hexdigest()
            require(digest == expected, f"front frame {index}: colores o geometría difieren del hash original")
            original = source_frame(front_source["source"], specification, 80)
            require(hashlib.sha256(normalized_rgb(original)).hexdigest() == expected,
                    f"front frame {index}: el hash del inventario no coincide con la hoja fuente")
            require(frame.convert("RGBA").tobytes() == original.tobytes(),
                    f"front frame {index}: alpha o píxeles difieren del original")
            front_hashes.append(digest)
        front_colors = {pixel[:3] for pixel in front.convert("RGBA").get_flattened_data() if pixel[3]}
        require(set(palette[1:]) == front_colors, "La paleta compartida contiene colores ajenos al front o pierde alguno")

    ow_source = entry.get("ow_source")
    require(bool(ow_source) == entry["has_ow"], "has_ow y ow_source difieren")
    original_ow_checked = False
    if ow_source:
        originals = [source_frame(ow_source["source"], spec, 32) for spec in ow_source["frames"]]
        order = ow_source["target_order"]
        require(len(order) == entry["ow_frames"], "Número de slots OW distinto de la fuente")
        arranged = [Image.new("RGBA", (32, 32), TRANSPARENT) if index is None else originals[index] for index in order]
        expected_ow = combine_frames(arranged, 32)
        saved_original = Image.open(directory / "originales/ow.png").convert("RGBA")
        require(saved_original.size == expected_ow.size and saved_original.tobytes() == expected_ow.tobytes(),
                "originales/ow.png no conserva exactamente colores, alpha, orden y posición de la fuente")
        require(saved_original.getchannel("A").tobytes() == ow.convert("RGBA").getchannel("A").tobytes(),
                "La conversión OW alteró la silueta o la transparencia")
        all_poses = Image.open(directory / "originales/ow_todas_las_poses.png").convert("RGBA")
        require(all_poses.size == (32 * len(originals), 32) and all_poses.tobytes() == combine_frames(originals, 32).tobytes(),
                "originales/ow_todas_las_poses.png no conserva todas las poses fuente")
        raw_frames = [source_frame(ow_source["source"], spec, 32, keep_background=True) for spec in ow_source["frames"]]
        raw = Image.open(directory / "originales/ow_celdas_fuente.png").convert("RGBA")
        require(raw.size == (32 * len(raw_frames), 32) and raw.tobytes() == combine_frames(raw_frames, 32).tobytes(),
                "originales/ow_celdas_fuente.png altera las celdas fuente sin enmascarar")
        original_ow_checked = True
        for original, index in zip(saved_original.get_flattened_data(), ow.tobytes()):
            require((original[3] == 0) == (index == 0), "Un píxel opaco OW fue convertido al índice transparente")
            if index:
                require(palette[index] in palette[1:], "El OW utiliza colores ajenos a su paleta")

    missing = {(item["grafico"], item["frame"]) for item in entry["missing"]}
    observed_missing = set()
    for kind, image, side in [("front", front, 80), ("ow", ow, 32)]:
        for index in range(entry[f"{kind}_frames"]):
            frame = image.crop((side * index, 0, side * (index + 1), side))
            if not any(frame.tobytes()):
                observed_missing.add((kind, index))
    require(missing == observed_missing, f"Listado de frames ausentes incorrecto: declarados={sorted(missing)}, observados={sorted(observed_missing)}")
    binaries = compiled_entry(directory, entry, front, ow, palette) if compilados else []
    return {"id": entry["id"], "ok": True, "front_frames": entry["front_frames"], "ow_frames": entry["ow_frames"],
            "front_hashes_checked": len(front_hashes), "original_ow_checked": original_ow_checked,
            "missing_frames_checked": len(missing), "compiled_files_checked": binaries}


def validar(catalogo=HERE / "catalogo.json", compilados=False):
    """Read and verify without writing; return a JSON-compatible report."""
    catalogo = Path(catalogo)
    data = json.loads(catalogo.read_text(encoding="utf-8"))
    results, errors = [], []
    for source, expected in data.get("sources_sha256", {}).items():
        try:
            require(hashlib.sha256((ROOT / source).read_bytes()).hexdigest() == expected, "La hoja fuente cambió desde la importación")
        except (OSError, ValueError) as error:
            errors.append({"source": source, "error": str(error)})
    identities = [entry["id"] for entry in data["entries"]]
    if len(set(identities)) != len(identities):
        errors.append({"error": "El catálogo contiene identificadores repetidos"})
    for entry in data["entries"]:
        try:
            results.append(validate_entry(entry, compilados))
        except (OSError, ValueError, KeyError, IndexError, TypeError, struct.error) as error:
            detail = {"id": entry.get("id"), "ok": False, "error": str(error)}
            results.append(detail)
            errors.append(detail)
    return {
        "version": 1, "checked_at_utc": datetime.now(timezone.utc).isoformat(),
        "catalog": str(catalogo), "compiled": compilados, "ok": not errors,
        "summary": {"entries": len(results), "passed": sum(item["ok"] for item in results),
                    "errors": len(errors), "source_sheets": len(data.get("sources_sha256", {})),
                    "front_source_hashes": sum(item.get("front_hashes_checked", 0) for item in results),
                    "preserved_ow_originals": sum(item.get("original_ow_checked", False) for item in results),
                    "transparent_missing_frames": sum(item.get("missing_frames_checked", 0) for item in results),
                    "compiled_files": sum(len(item.get("compiled_files_checked", [])) for item in results)},
        "errors": errors, "entries": results,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compilados", action="store_true", help="Decodificar también 4bpp, LZ77 y paletas GBA")
    parser.add_argument("--catalogo", type=Path, default=HERE / "catalogo.json")
    parser.add_argument("--resultado", type=Path, default=HERE / "validacion.json")
    arguments = parser.parse_args()
    try:
        report = validar(arguments.catalogo, arguments.compilados)
    except (OSError, ValueError, KeyError) as error:
        report = {"version": 1, "ok": False, "compiled": arguments.compilados,
                  "errors": [{"error": str(error)}], "entries": []}
    arguments.resultado.parent.mkdir(parents=True, exist_ok=True)
    arguments.resultado.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"ok": report["ok"], "summary": report.get("summary"), "errors": report["errors"],
                      "result": str(arguments.resultado)}, ensure_ascii=False, indent=2))
    return 0 if report["ok"] else 1


if __name__ == "__main__":
    raise SystemExit(main())

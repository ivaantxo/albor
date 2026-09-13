"""Native game artwork used when an exact form/gender has no APNG source.

The existing PNGs are vertical strips, not animated PNGs.  Their square canvas
size comes from the PNG layout: SpeciesInfo's old MON_COORDS_SIZE dimensions
often describe the occupied silhouette (e.g. 64 x 56), not the stored frame.
No pixels, poses, gender differences or BW timing are invented here.
"""

from __future__ import annotations

from copy import deepcopy
from pathlib import Path
from typing import Sequence

import numpy as np
from PIL import Image


MAGENTA = (255, 0, 255)


def infer_frame_layout(size: tuple[int, int], frame_size=None) -> dict:
    """Infer vertical square strips; require explicit dimensions for grids.

    ``frame_size`` is an integer or [width, height].  It denotes the stored
    canvas and must never be populated blindly from a bounding-box macro.
    """
    width, height = size
    if frame_size is None:
        if height % width:
            raise ValueError(
                f"Tira PNG {width}x{height} ambigua: indica legacy_frame_size "
                "con el tamaño de lienzo almacenado, no el bounding box.")
        frame_width = frame_height = width
        method = "png_vertical_square_strip"
    else:
        if type(frame_size) is int:
            frame_size = [frame_size, frame_size]
        if (not isinstance(frame_size, (list, tuple)) or len(frame_size) != 2
                or any(type(v) is not int or v <= 0 for v in frame_size)):
            raise ValueError("legacy_frame_size debe ser un entero positivo o [ancho, alto].")
        frame_width, frame_height = frame_size
        method = "explicit_frame_size"
    if width % frame_width or height % frame_height:
        raise ValueError(f"El lienzo de frame {frame_width}x{frame_height} no divide la tira {width}x{height}.")
    columns, rows = width // frame_width, height // frame_height
    return {
        "strip_size": [width, height],
        "frame_size": [frame_width, frame_height],
        "columns": columns,
        "rows": rows,
        "frame_count": columns * rows,
        "frame_size_method": method,
        "layout": "vertical" if columns == 1 else "horizontal" if rows == 1 else "grid_row_major",
    }


def load_legacy_animation(path: str | Path, side: str, frame_size=None, *,
                          frame_durations_ms: Sequence[float] | None = None
                          ) -> tuple[list[Image.Image], list[float], dict]:
    """Decode a native PNG strip as RGBA poses plus explicit provenance.

    Index zero, pure magenta and PNG alpha are transparent.  Opaque RGB values
    are retained exactly from the PNG palette; a .pal reference may guide later
    ordering but must not silently replace colors of this existing artwork.
    Static source poses remain static.  ``100 ms`` is a documented fallback,
    not timing recovered from BW; callers can supply known per-pose durations.
    """
    if side not in ("front", "back"):
        raise ValueError("side debe ser front o back.")
    path = Path(path)
    with Image.open(path) as source:
        if getattr(source, "n_frames", 1) != 1:
            raise ValueError("La fuente legacy es un PNG animado; usa el lector APNG.")
        layout = infer_frame_layout(source.size, frame_size)
        palette = source.getpalette() if source.mode == "P" else None
        rgba = np.array(source.convert("RGBA"), dtype=np.uint8)
        rgba[np.all(rgba[:, :, :3] == MAGENTA, axis=2), 3] = 0
        if source.mode == "P":
            rgba[np.asarray(source) == 0, 3] = 0
        rgba[rgba[:, :, 3] == 0] = 0
        canonical = Image.fromarray(rgba)
        frame_width, frame_height = layout["frame_size"]
        frames = [canonical.crop((x, y, x + frame_width, y + frame_height))
                  for y in range(0, source.height, frame_height)
                  for x in range(0, source.width, frame_width)]
        warnings = [
            "Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW."]
        if any(frame.getchannel("A").getbbox() is None for frame in frames):
            raise ValueError(f"La tira heredada contiene un frame vacío: {path}.")
        unique_count = len({frame.tobytes() for frame in frames})
        if unique_count == 1:
            warnings.append("Solo hay una pose original: el resultado será estático, sin inventar movimiento.")
        if frame_durations_ms is None:
            durations = [100.0] * len(frames)
            timing_kind = "fallback_100ms_no_source_timing"
        else:
            durations = [float(value) for value in frame_durations_ms]
            if len(durations) != len(frames) or any(not np.isfinite(d) or d <= 0 for d in durations):
                raise ValueError("Se requiere una duración finita y positiva por frame de la tira.")
            timing_kind = "provided_pose_durations"
        metadata = {
            "source_type": "legacy_strip",
            "side": side,
            **layout,
            "unique_count": unique_count,
            "source_mode": source.mode,
            "source_palette": [palette[i:i + 3] for i in range(0, len(palette), 3)] if palette else None,
            "transparency_policy": "index_0_or_magenta_or_png_alpha",
            "timing_kind": timing_kind,
            "warnings": warnings,
        }
    return frames, durations, metadata


def supplement_catalog(entries: list[dict], repo: Path) -> list[dict]:
    """Fill only missing sources with the exact artwork referenced by catalog.

    The catalog owns the species whitelist, form identity and graphics symbol
    resolution.  This helper never searches neighboring forms or substitutes a
    male picture for an explicitly different female picture.  Existing APNGs
    retain priority.  Source type is attached per view for the correct decoder.
    """
    repo = Path(repo).resolve()
    result = deepcopy(entries)
    for entry in result:
        default = next((v for v in entry["variants"] if v["key"] == "default"), None)
        for variant in entry["variants"]:
            female = variant["key"] == "female"
            variant["palette_output"] = "normalf.pal" if female else "normal.pal"
            for side in ("front", "back"):
                # A few existing symbol declarations accidentally alias the
                # male drawing despite a distinct *f PNG being present (e.g.
                # Staravia's back).  Preserve that actual female artwork too.
                if female and variant.get(f"original_{side}"):
                    original_path = repo / variant[f"original_{side}"]
                    folder = (repo / "graphics/pokemon" / entry["output_dir"]
                              if entry.get("output_dir") else original_path.parent)
                    exact = (folder / ("anim_frontf.png" if side == "front" else "backf.png")).resolve()
                    if (exact.is_relative_to(repo / "graphics/pokemon")
                            and exact.is_file() and exact != original_path.resolve()):
                        variant[f"original_game_{side}"] = variant[f"original_{side}"]
                        variant[f"original_{side}"] = exact.relative_to(repo).as_posix()
                        if variant.get(f"{side}_shared_with_default"):
                            variant[side] = None
                        variant[f"{side}_shared_with_default"] = False
                if variant.get(side):
                    variant.setdefault(f"{side}_source_type", "apng")
                    continue
                original = variant.get(f"original_{side}")
                if not original:
                    continue
                path = (repo / original).resolve()
                if not path.is_relative_to(repo / "graphics/pokemon") or not path.is_file():
                    continue
                shared = bool(female and default and original == default.get(f"original_{side}"))
                if shared and default.get(side):
                    variant[side] = default[side]
                    variant[f"{side}_source_type"] = default.get(f"{side}_source_type", "apng")
                else:
                    variant[side] = path.relative_to(repo).as_posix()
                    variant[f"{side}_source_type"] = "legacy_strip"
                variant[f"{side}_shared_with_default"] = shared
                variant["warnings"] = [w for w in variant.get("warnings", [])
                                       if not w.startswith(f"Falta APNG {side} ")]
                variant["warnings"].append(
                    f"{side}: recuperado del arte original del juego; revisar las poses y su duración.")
            variant["status"] = "available" if variant.get("front") and variant.get("back") else "missing_source"
    return result

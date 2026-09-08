"""Shared, indexed sprite palettes with transparent magenta in slot zero.

Only opaque source pixels participate in palette construction.  Palette ordering
is a *heuristic*: contiguous reference-palette blocks help distinguish body
regions whose shadows share a hue; without references, hue ramps are used.
References guide grouping and placement; their RGB values never replace the
source's colors.
"""

from __future__ import annotations

import colorsys
from functools import lru_cache
from typing import Iterable, Sequence

import numpy as np
from PIL import Image


TRANSPARENT = (255, 0, 255)
RGB = tuple[int, int, int]


def _lab(rgb: np.ndarray) -> np.ndarray:
    """sRGB -> CIE Lab (D65), used only for perceptual matching."""
    values = np.asarray(rgb, dtype=np.float64) / 255.0
    linear = np.where(values <= 0.04045, values / 12.92,
                      ((values + 0.055) / 1.055) ** 2.4)
    xyz = linear @ np.array([[0.4124564, 0.2126729, 0.0193339],
                             [0.3575761, 0.7151522, 0.1191920],
                             [0.1804375, 0.0721750, 0.9503041]])
    xyz /= np.array([0.95047, 1.0, 1.08883])
    delta = 6.0 / 29.0
    f = np.where(xyz > delta ** 3, np.cbrt(xyz),
                 xyz / (3 * delta ** 2) + 4.0 / 29.0)
    return np.stack((116 * f[..., 1] - 16,
                     500 * (f[..., 0] - f[..., 1]),
                     200 * (f[..., 1] - f[..., 2])), axis=-1)


def _collect(frames: Iterable[Image.Image]) -> tuple[np.ndarray, np.ndarray, dict]:
    hist: dict[RGB, int] = {}
    pixel_count = transparent_count = partial_alpha_count = frame_count = 0
    for frame in frames:
        rgba = np.asarray(frame.convert("RGBA"), dtype=np.uint8)
        alpha = rgba[..., 3]
        visible = alpha > 0
        pixels = rgba[..., :3][visible]
        frame_count += 1
        pixel_count += int(alpha.size)
        transparent_count += int(np.count_nonzero(~visible))
        partial_alpha_count += int(np.count_nonzero((alpha > 0) & (alpha < 255)))
        if not pixels.size:
            continue
        colors, counts = np.unique(pixels, axis=0, return_counts=True)
        for color, count in zip(colors, counts):
            rgb = tuple(map(int, color))
            hist[rgb] = hist.get(rgb, 0) + int(count)
    if not frame_count:
        raise ValueError("build_palette needs at least one frame")
    if not hist:
        raise ValueError("Cannot build a sprite palette from fully transparent frames")
    colors = np.asarray(sorted(hist), dtype=np.uint8)
    counts = np.asarray([hist[tuple(map(int, color))] for color in colors],
                        dtype=np.int64)
    return colors, counts, {
        "frame_count": frame_count,
        "total_pixels": pixel_count,
        "opaque_pixels": int(counts.sum()),
        "transparent_pixels": transparent_count,
        "partial_alpha_pixels": partial_alpha_count,
        "alpha_policy": "alpha == 0 is transparent; alpha > 0 is opaque",
    }


def _quantize(colors: np.ndarray, counts: np.ndarray, size: int = 15
              ) -> tuple[np.ndarray, np.ndarray, dict]:
    """Weighted Lab k-means followed by source-color medoids, no dithering.

    Medoids keep surviving RGB values exact, which is useful for pixel artwork
    and avoids inventing intermediate outline or highlight colors.
    """
    source_lab = _lab(colors)
    if len(colors) <= size:
        return colors.copy(), counts.copy(), {
            "quantized": False, "method": "exact_source_colors",
            "changed_opaque_pixels": 0, "mean_delta_e76": 0.0,
            "max_delta_e76": 0.0,
        }

    # Deterministic, frequency-aware farthest-point initialization still gives
    # rare accent colors a chance to survive when perceptually distinctive.
    seeds = [int(np.argmax(counts))]
    min_distance = np.sum((source_lab - source_lab[seeds[0]]) ** 2, axis=1)
    for _ in range(1, size):
        score = min_distance * np.sqrt(counts)
        score[seeds] = -1
        next_seed = int(np.argmax(score))
        seeds.append(next_seed)
        min_distance = np.minimum(min_distance,
                                  np.sum((source_lab - source_lab[next_seed]) ** 2,
                                         axis=1))
    centers = source_lab[seeds].copy()
    previous = None
    for _ in range(40):
        distances = np.sum((source_lab[:, None] - centers[None]) ** 2, axis=2)
        labels = np.argmin(distances, axis=1)
        if previous is not None and np.array_equal(labels, previous):
            break
        previous = labels.copy()
        for index in range(size):
            mask = labels == index
            if mask.any():
                centers[index] = np.average(source_lab[mask], axis=0,
                                            weights=counts[mask])

    representatives = []
    for index in range(size):
        members = np.flatnonzero(labels == index)
        if not members.size:
            continue
        delta = np.sum((source_lab[members] - centers[index]) ** 2, axis=1)
        representatives.append(int(members[np.argmin(delta)]))
    # Empty clusters are unusual, but preserve all available palette capacity.
    while len(representatives) < size:
        distances = np.sum((source_lab[:, None] -
                            source_lab[representatives][None]) ** 2, axis=2)
        score = distances.min(axis=1) * counts
        score[representatives] = -1
        representatives.append(int(np.argmax(score)))
    result = colors[representatives]
    distance_squared = np.sum((source_lab[:, None] - _lab(result)[None]) ** 2,
                              axis=2)
    nearest = np.argmin(distance_squared, axis=1)
    errors = np.sqrt(distance_squared[np.arange(len(colors)), nearest])
    result_counts = np.bincount(nearest, weights=counts,
                               minlength=len(result)).astype(np.int64)
    changed = np.any(colors != result[nearest], axis=1)
    return result, result_counts, {
        "quantized": True,
        "method": "joint_weighted_lab_kmeans_source_medoids_no_dither",
        "changed_opaque_pixels": int(counts[changed].sum()),
        "mean_delta_e76": round(float(np.average(errors, weights=counts)), 5),
        "max_delta_e76": round(float(errors.max()), 5),
    }


def _hue_distance(a: float, b: float) -> float:
    return abs((a - b + 180.0) % 360.0 - 180.0)


def _describe_groups(colors: np.ndarray, counts: np.ndarray,
                     groups: list[list[int]]) -> list[dict]:
    hsv = np.asarray([colorsys.rgb_to_hsv(*(color / 255.0)) for color in colors])
    hues = hsv[:, 0] * 360.0
    neutral = hsv[:, 1] < 0.16
    labs = _lab(colors)
    result = []
    for members in groups:
        members = sorted(members, key=lambda index: (float(labs[index, 0]),
                                                    tuple(map(int, colors[index]))))
        weights = counts[members]
        if not weights.sum():
            weights = np.ones(len(members))
        angle = np.radians(hues[members])
        mean_hue = float(np.degrees(np.arctan2(np.average(np.sin(angle), weights=weights),
                                              np.average(np.cos(angle), weights=weights)))
                         % 360.0)
        # Shadows can shift a leaf ramp toward the body's teal.  Match family
        # regions by equally weighted mids/highlights, independent of how much
        # shadow happens to be visible in a selected front or back frame.
        representative = members[1:] if len(members) >= 3 else members
        match_angle = np.radians(hues[representative])
        matching_hue = float(np.degrees(np.arctan2(np.mean(np.sin(match_angle)),
                                                   np.mean(np.cos(match_angle)))) % 360.0)
        result.append({"members": members, "neutral": bool(np.all(neutral[members])),
                       "hue": mean_hue, "matching_hue": matching_hue,
                       "weight": int(counts[members].sum()),
                       "first": min(members) + 1})
    return result


def _ramps(colors: np.ndarray, counts: np.ndarray) -> list[dict]:
    hsv = np.asarray([colorsys.rgb_to_hsv(*(color / 255.0)) for color in colors])
    hues = hsv[:, 0] * 360.0
    neutral = hsv[:, 1] < 0.16
    groups = [[index] for index in range(len(colors)) if not neutral[index]]
    # Complete-linkage hue clustering prevents a chain of intermediate colors
    # from merging a body's teal ramp with a leaf's yellow-green ramp.
    while len(groups) > 1:
        best = None
        for left in range(len(groups)):
            for right in range(left + 1, len(groups)):
                maximum = max(_hue_distance(hues[a], hues[b])
                              for a in groups[left] for b in groups[right])
                if maximum <= 42.0 and (best is None or maximum < best[0]):
                    best = (maximum, left, right)
        if best is None:
            break
        _, left, right = best
        groups[left] += groups.pop(right)
    if neutral.any():
        groups.append(list(map(int, np.flatnonzero(neutral))))
    return _describe_groups(colors, counts, groups)


def _guide(reference: Sequence[Sequence[int]] | None) -> list[dict]:
    if reference is None:
        return []
    values = [tuple(map(int, color)) for color in reference]
    if any(len(color) != 3 or any(v < 0 or v > 255 for v in color)
           for color in values):
        raise ValueError("Reference palettes must contain RGB triples in 0..255")
    # The public API accepts conventional 16-entry palettes including slot 0,
    # or an explicit list of up to 15 opaque colors.
    if len(values) == 16:
        values = values[1:]
    if not 1 <= len(values) <= 15:
        raise ValueError("Reference palettes need 1..15 opaque or 16 total entries")
    # Duplicate padding entries should not increase the size of a guide ramp.
    unique = []
    original_slots = []
    for index, value in enumerate(values, start=1):
        if value == TRANSPARENT or value in unique:
            continue
        unique.append(value)
        original_slots.append(index)
    if not unique:
        return []
    colors = np.asarray(unique, dtype=np.uint8)
    hsv = np.asarray([colorsys.rgb_to_hsv(*(color / 255.0)) for color in colors])
    hues, neutral, lightness = hsv[:, 0] * 360.0, hsv[:, 1] < 0.16, _lab(colors)[:, 0]
    blocks: list[list[int]] = []
    for index in range(len(unique)):
        if neutral[index]:
            continue
        previous = blocks[-1][-1] if blocks else None
        adjacent = previous is not None and original_slots[index] == original_slots[previous] + 1
        join = False
        if adjacent:
            distance = _hue_distance(hues[previous], hues[index])
            # Many original palettes put a blue/teal leaf shadow immediately
            # before greener leaf mids.  Preserve that dark-to-light block
            # instead of reassigning its shadow to the adjacent teal body.
            shifted_shadow = (lightness[previous] < 40 and
                              lightness[index] - lightness[previous] > 15 and
                              distance <= 80)
            join = distance <= 42 or shifted_shadow
        if join:
            blocks[-1].append(index)
        else:
            blocks.append([index])
    # A neutral entry can interrupt a ramp (e.g. Venusaur's flower stem).
    # Merge only separated, closely related blocks; never undo a boundary
    # between two adjacent chromatic blocks inferred above.
    changed = True
    while changed:
        changed = False
        for left in range(len(blocks)):
            for right in range(left + 1, len(blocks)):
                a, b = blocks[left], blocks[right]
                touching = any(abs(original_slots[i] - original_slots[j]) == 1
                               for i in a for j in b)
                maximum = max(_hue_distance(hues[i], hues[j]) for i in a for j in b)
                if not touching and maximum <= 35:
                    blocks[left] += blocks.pop(right)
                    changed = True
                    break
            if changed:
                break
    if neutral.any():
        blocks.append(list(map(int, np.flatnonzero(neutral))))
    groups = _describe_groups(colors, np.ones(len(unique), dtype=np.int64), blocks)
    for group in groups:
        group["slots"] = sorted(original_slots[index] for index in group["members"])
        group["first"] = min(group["slots"])
        group["colors"] = colors[group["members"]]
    return sorted(groups, key=lambda group: group["first"])


def _source_groups(colors: np.ndarray, counts: np.ndarray,
                   own_guide: list[dict]) -> tuple[list[dict], int]:
    """Transfer region membership through close own-species reference colors.

    Source exports can differ by a rounding unit from normal.pal.  Lab matching
    tolerates those changes; colors far from every reference use hue fallback.
    Family palettes are intentionally excluded from this membership decision.
    """
    if not own_guide:
        return _ramps(colors, counts), 0
    reference_colors = np.concatenate([group["colors"] for group in own_guide])
    reference_groups = np.concatenate([np.full(len(group["colors"]), index)
                                        for index, group in enumerate(own_guide)])
    distances = np.sum((_lab(colors)[:, None] - _lab(reference_colors)[None]) ** 2, axis=2)
    nearest = np.argmin(distances, axis=1)
    accepted = distances[np.arange(len(colors)), nearest] <= 18 ** 2
    labels = reference_groups[nearest]
    blocks = [list(map(int, np.flatnonzero(accepted & (labels == index))))
              for index in range(len(own_guide))]
    blocks = [block for block in blocks if block]
    unmatched = np.flatnonzero(~accepted)
    if unmatched.size:
        blocks.extend([[int(unmatched[index]) for index in group["members"]]
                       for group in _ramps(colors[unmatched], counts[unmatched])])
    return _describe_groups(colors, counts, blocks), int(accepted.sum())


def _match_ramps(groups: list[dict], guide: list[dict]) -> dict[int, dict]:
    """A small assignment problem; unmatched ramps retain their own ordering."""
    if not guide:
        return {}
    candidates = []
    for source_index, source in enumerate(groups):
        for guide_index, target in enumerate(guide):
            if source["neutral"] != target["neutral"]:
                continue
            hue_distance = 0.0 if source["neutral"] else _hue_distance(source["matching_hue"], target["matching_hue"])
            if hue_distance > 75:
                continue
            cost = hue_distance + 3.0 * abs(len(source["members"]) - len(target["members"]))
            candidates.append((cost, source_index, guide_index))
    # There are usually 2..5 ramps.  The low-cost greedy assignment is explicit
    # and conservative: we do not force unrelated colors into a family region.
    selected = {}
    used_targets = set()
    for cost, source_index, guide_index in sorted(candidates):
        if source_index not in selected and guide_index not in used_targets:
            selected[source_index] = {"target": guide[guide_index],
                                      "hue_cost": float(cost)}
            used_targets.add(guide_index)
    return selected


def _ordered_palette(colors: np.ndarray, counts: np.ndarray,
                     reference: Sequence[Sequence[int]] | None,
                     family_reference: Sequence[Sequence[int]] | None
                     ) -> tuple[list[RGB], dict]:
    own_guide = _guide(reference)
    family_guide = _guide(family_reference)
    groups, reference_grouped_colors = _source_groups(colors, counts, own_guide)
    own_matches = _match_ramps(groups, own_guide)
    family_matches = _match_ramps(groups, family_guide)
    dominant = sorted(range(len(groups)),
                      key=lambda index: (groups[index]["neutral"],
                                         -groups[index]["weight"],
                                         groups[index]["hue"]))
    natural_starts = {}
    next_slot = 1
    for index in dominant:
        natural_starts[index] = next_slot
        next_slot += len(groups[index]["members"])
    for index, group in enumerate(groups):
        family_match = family_matches.get(index)
        own_match = own_matches.get(index)
        match = family_match or own_match
        group["target_start"] = match["target"]["first"] if match else natural_starts[index]
        group["reference"] = "family" if family_match else "species" if own_match else "dominant_color"
        group["source_index"] = index
    groups.sort(key=lambda group: (group["target_start"], group["neutral"],
                                    -group["weight"], group["hue"]))

    # Place whole contiguous ramps.  Dynamic programming preserves guide start
    # indices where there is room, and shifts blocks only when sizes require it.
    @lru_cache(maxsize=None)
    def place(group_index: int, first_free: int):
        if group_index == len(groups):
            return 0.0, ()
        remaining = sum(len(group["members"]) for group in groups[group_index:])
        best = (float("inf"), ())
        group = groups[group_index]
        for start in range(first_free, 17 - remaining):
            cost, tail = place(group_index + 1, start + len(group["members"]))
            guide_weight = 2.0 if group["reference"] == "family" else 1.0
            cost += guide_weight * (start - group["target_start"]) ** 2
            cost += 0.01 * (start - first_free)
            if cost < best[0]:
                best = cost, (start,) + tail
        return best

    _, starts = place(0, 1)
    # Unused slots must not duplicate an actual source color: nearest-color
    # matching could otherwise choose a blank earlier slot instead of its
    # intended semantic index.  Magenta padding also remains ignorable when a
    # palette becomes the next evolutionary stage's family reference.
    retained = {tuple(map(int, color)) for color in colors}
    padding = TRANSPARENT
    if padding in retained:
        padding = next((0, 0, value) for value in range(256)
                       if (0, 0, value) not in retained)
    palette = [TRANSPARENT] + [padding] * 15
    ramps = []
    occupied = set()
    for group, start in zip(groups, starts):
        indices = list(range(start, start + len(group["members"])))
        for palette_index, source_index in zip(indices, group["members"]):
            palette[palette_index] = tuple(map(int, colors[source_index]))
            occupied.add(palette_index)
        ramps.append({"indices": indices,
                      "colors": [list(palette[index]) for index in indices],
                      "kind": "neutral" if group["neutral"] else "chromatic",
                      "hue_degrees": round(group["hue"], 2),
                      "opaque_pixel_count": group["weight"],
                      "ordering_reference": group["reference"],
                      "preferred_start_index": group["target_start"],
                      "start_preserved": start == group["target_start"],
                      "order": "dark_to_light_CIE_Lstar"})
    return palette, {
        "ordering_method": "heuristic_reference_blocks_then_dark_to_light_with_family_slots",
        "species_reference_grouped_colors": reference_grouped_colors,
        "anatomical_grouping_verified": False,
        "family_alignment_verified": False,
        "species_reference_provided": reference is not None,
        "family_reference_provided": family_reference is not None,
        "family_matched_ramps": len(family_matches),
        "ramps": ramps,
        "unused_indices": sorted(set(range(1, 16)) - occupied),
    }


def build_palette(frames: list[Image.Image], reference: list[RGB] | None = None,
                  family_reference: list[RGB] | None = None
                  ) -> tuple[list[RGB], dict]:
    """Build one shared 16-entry palette for all supplied views and genders.

    Pass every selected front/back/gender frame together.  Entries 1..15 contain
    opaque colors; entry 0 is always RGB(255, 0, 255).  No shiny palette is made.
    `reference` and `family_reference` influence index ordering only.
    """
    colors, counts, metadata = _collect(frames)
    metadata["source_opaque_color_count"] = len(colors)
    reduced, reduced_counts, quantization = _quantize(colors, counts)
    result, ordering = _ordered_palette(reduced, reduced_counts,
                                        reference, family_reference)
    metadata.update(quantization)
    metadata.update(ordering)
    metadata["opaque_palette_color_count"] = len(reduced)
    metadata["palette_size"] = 16
    metadata["transparent_index"] = 0
    metadata["transparent_rgb"] = list(TRANSPARENT)
    metadata["opaque_magenta_present"] = bool(np.any(np.all(colors == TRANSPARENT, axis=1)))
    metadata["review_reasons"] = ["body regions and evolution correspondence use color heuristics"]
    if metadata["quantized"]:
        metadata["review_reasons"].append("more than 15 opaque source colors required joint reduction")
    if metadata["partial_alpha_pixels"]:
        metadata["review_reasons"].append("partial alpha was converted to binary transparency")
    family_match_count = sum(ramp["ordering_reference"] == "family"
                             for ramp in ordering["ramps"])
    if family_reference is not None and family_match_count < len(ordering["ramps"]):
        metadata["review_reasons"].append("some color ramps could not be aligned with the family reference")
    if any(not ramp["start_preserved"] for ramp in ordering["ramps"]):
        metadata["review_reasons"].append("ramp sizes required shifting some preferred palette indices")
    return result, metadata


def index_image(image: Image.Image, palette: Sequence[Sequence[int]]) -> Image.Image:
    """Index RGBA pixels against this exact palette, excluding slot 0 for opacities.

    Uses nearest Lab color with no dithering.  Exact source colors are kept when
    present; transparency is represented by PNG palette index 0, never RGB alone.
    """
    if len(palette) != 16 or tuple(palette[0]) != TRANSPARENT:
        raise ValueError("Expected 16 RGB entries with transparent magenta at index 0")
    values = np.asarray(palette)
    if values.shape != (16, 3) or np.any(values < 0) or np.any(values > 255):
        raise ValueError("Palette entries must be RGB triples in 0..255")
    rgba = np.asarray(image.convert("RGBA"), dtype=np.uint8)
    visible = rgba[..., 3] > 0
    indexed = np.zeros(rgba.shape[:2], dtype=np.uint8)
    pixels = rgba[..., :3][visible]
    if pixels.size:
        colors, inverse = np.unique(pixels, axis=0, return_inverse=True)
        distances = np.sum((_lab(colors)[:, None] - _lab(values[1:])[None]) ** 2,
                           axis=2)
        mapped = np.argmin(distances, axis=1).astype(np.uint8) + 1
        indexed[visible] = mapped[inverse]
    result = Image.fromarray(indexed)
    result.putpalette(values.astype(np.uint8).flatten().tolist())
    result.info["transparency"] = 0
    return result

"""Select native APNG poses without changing pixels or per-frame placement.

The selector is deliberately a heuristic, not a semantic classifier.  It first
looks for a repeated introductory motion and chooses the two ends of that
motion.  Front specials come from a later excursion outside that motion.  Its
indices and diagnostics are intended to be reviewed and overridden by a person.
"""

from __future__ import annotations

from hashlib import blake2b
from pathlib import Path
from typing import Sequence

import numpy as np
from PIL import Image


TRANSPARENT = (255, 0, 255)


def load_animation(path: str | Path) -> tuple[list[Image.Image], list[float]]:
    """Read Pillow-composited, full-canvas APNG frames and milliseconds.

    Pillow applies APNG blend/dispose operations when seeking sequentially.
    An APNG's optional nonanimated default image is excluded.  Pure magenta is
    always transparent in this project, including files without a PNG tRNS.
    Frame indices returned by the selector refer to this animation-only list.
    """
    frames: list[Image.Image] = []
    durations: list[float] = []
    with Image.open(path) as source:
        first = 1 if source.info.get("default_image", False) else 0
        for index in range(first, getattr(source, "n_frames", 1)):
            source.seek(index)
            pixels = np.array(source.convert("RGBA"), dtype=np.uint8)
            magenta = np.all(pixels[:, :, :3] == TRANSPARENT, axis=2)
            pixels[magenta, 3] = 0
            pixels[pixels[:, :, 3] == 0] = 0
            frames.append(Image.fromarray(pixels))
            duration = float(source.info.get("duration", 100) or 100)
            durations.append(duration if duration > 0 else 100.0)
    if not frames:
        raise ValueError(f"No hay fotogramas de animación en {path}")
    return frames, durations


def frame_metrics(frame: Image.Image) -> dict:
    """Geometric measurements in unchanged APNG canvas coordinates."""
    pixels = np.asarray(frame.convert("RGBA"))
    alpha = pixels[:, :, 3].astype(np.float64) / 255
    y, x = np.nonzero(alpha)
    area = float(alpha.sum())
    if not area:
        return {"bbox": None, "centroid": None, "area": 0, "opaque_pixels": 0}
    weights = alpha[y, x]
    return {
        "bbox": [int(x.min()), int(y.min()), int(x.max()) + 1, int(y.max()) + 1],
        "centroid": [round(float(np.sum(x * weights) / area), 4),
                     round(float(np.sum(y * weights) / area), 4)],
        "area": round(area, 4),
        "opaque_pixels": int(len(x)),
    }


def _features(frames: Sequence[Image.Image]) -> tuple[np.ndarray, list[int], list[dict]]:
    signatures = []
    labels = []
    label_by_hash: dict[bytes, int] = {}
    metrics = []
    for frame in frames:
        rgba = np.array(frame.convert("RGBA"), dtype=np.uint8)
        rgba[np.all(rgba[:, :, :3] == TRANSPARENT, axis=2), 3] = 0
        rgba[rgba[:, :, 3] == 0] = 0
        key = blake2b(rgba.tobytes(), digest_size=16).digest()
        labels.append(label_by_hash.setdefault(key, len(label_by_hash)))
        canonical = Image.fromarray(rgba)
        metrics.append(frame_metrics(canonical))
        # Premultiplied colour and coverage preserve translation, silhouette,
        # and internal changes such as eyes opening.  No frame is recentered.
        tiny = np.asarray(canonical.resize((24, 24), Image.Resampling.BOX), dtype=np.float32) / 255
        alpha = tiny[:, :, 3:4]
        signature = np.concatenate((tiny[:, :, :3] * alpha * .75, alpha * 2), axis=2)
        signatures.append(signature.reshape(-1))
    features = np.asarray(signatures, dtype=np.float32)
    squares = np.einsum("ij,ij->i", features, features)
    distances_squared = squares[:, None] + squares[None, :] - 2 * (features @ features.T)
    distances = np.sqrt(np.maximum(distances_squared, 0) / (24 * 24))
    # Floating-point cancellation must never make identical frames distinct.
    labels_array = np.asarray(labels)
    distances[labels_array[:, None] == labels_array[None, :]] = 0
    return distances, labels, metrics


def _runs(labels: Sequence[int]) -> list[int]:
    return [index for index, label in enumerate(labels)
            if index == 0 or label != labels[index - 1]]


def _find_loop(distances: np.ndarray, labels: list[int]) -> dict:
    runs = _runs(labels)
    length = len(runs)
    candidates = []
    approximate = []
    # Compare entire consecutive cycles, not just the return to a base pose.
    # Collapsing held frames makes recurrence independent of APNG timing.
    for period in range(2, length // 2 + 1):
        comparisons = min(2 * period, length - period)
        left = np.asarray(runs[:comparisons])
        right = np.asarray(runs[period:period + comparisons])
        residual = distances[left, right]
        first_residual = residual[:period]
        spread = float(np.max(distances[np.ix_(runs[:period], runs[:period])]))
        if spread < .025:
            continue
        mean_error = float(np.mean(first_residual))
        close_fraction = float(np.mean(first_residual <= .055))
        # Some exports vary tiny details between nominally repeated cycles
        # (Pikachu's ears, Magikarp's fins).  Corresponding phases must be
        # much closer than arbitrary phase pairs to count as recurrence.
        cross = distances[np.ix_(runs[:period], runs[period:2 * period])]
        background_error = float(np.mean(cross))
        ratio = mean_error / max(background_error, .001)
        exact_fraction = float(np.mean(first_residual == 0))
        if period >= 3 and (ratio < .45 or (exact_fraction >= .4 and ratio < .6)):
            approximate.append((ratio + .02 * period / max(1, length), period, mean_error))
        if mean_error > .035 or close_fraction < .85:
            continue
        # Exact repeats win over merely similar short fragments.  A small
        # length penalty prefers the elementary cycle over its multiples.
        score = mean_error + .012 * period / max(1, length)
        candidates.append((score, period, mean_error, close_fraction, residual))
    if candidates:
        _, period, error, close, residual = min(candidates, key=lambda item: item[0])
        end = runs[period]
        confidence = "high" if error < .012 and close >= .95 else "medium"
        return {
            "detected": True, "confidence": confidence,
            "start": 0, "end_exclusive": end,
            "period_runs": period, "mean_error": round(error, 5),
            "compared_runs": int(len(residual)),
            "indices": list(range(end)),
        }
    if approximate:
        _, period, error = min(approximate)
        end = runs[period]
        reference_end_run = min(2 * period, length)
        # Teach the novelty comparison the observed small variants, while
        # selecting base poses solely from the first complete cycle.
        for start in range(2 * period, length - period + 1, period):
            cross = distances[np.ix_(runs[:period], runs[start:start + period])]
            ratio = float(np.mean(np.diag(cross))) / max(float(np.mean(cross)), .001)
            if ratio > .55:
                break
            reference_end_run = start + period
        reference_end = runs[reference_end_run] if reference_end_run < length else len(labels)
        return {
            "detected": True, "confidence": "medium", "method": "approximate",
            "start": 0, "end_exclusive": end,
            "period_runs": period, "mean_error": round(error, 5),
            "compared_runs": period, "indices": list(range(end)),
            "reference_indices": list(range(reference_end)),
        }
    # No reliable repeated prefix: use the introductory part and state the
    # uncertainty.  A short intro is safer than calling a late attack idle.
    end = max(1, min(len(labels), max(3, int(np.ceil(len(labels) * .35)))))
    return {
        "detected": False, "confidence": "low", "start": 0,
        "end_exclusive": end, "period_runs": None, "mean_error": None,
        "compared_runs": 0, "indices": list(range(end)),
    }


def _unique(indices: Sequence[int], labels: Sequence[int]) -> list[int]:
    seen = set()
    result = []
    for index in indices:
        if labels[index] not in seen:
            seen.add(labels[index])
            result.append(int(index))
    return result


def _idle_poses(idle: list[int], distances: np.ndarray, labels: list[int],
                metrics: list[dict], durations: Sequence[float]) -> tuple[list[int], dict, list[str]]:
    candidates = _unique(idle, labels)
    visible = [index for index in candidates if metrics[index]["centroid"] is not None]
    if visible:
        candidates = visible
    warnings = []
    if len(candidates) == 1:
        return candidates * 3, {"axis": "y", "displacements": [0, 0, 0]}, [
            "El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento."]
    positions = np.array([metrics[index]["centroid"] or [0, 0] for index in candidates])
    ranges = np.ptp(positions, axis=0)
    axis = 1 if ranges[1] >= ranges[0] * .75 else 0
    values = positions[:, axis]
    extent = float(np.ptp(values))
    matrix = distances[np.ix_(candidates, candidates)]
    spread = max(float(matrix.max()), .001)
    geometric_center = (float(values.min()) + float(values.max())) / 2
    centrality = np.abs(values - geometric_center) / max(extent, .1)
    medoid = np.mean(matrix, axis=1) / spread
    # Prefer the original neutral pose whenever it can support motion on both
    # sides; otherwise take a central recurrent pose as the output frame zero.
    base_scores = .55 * centrality + .3 * medoid
    base_scores[0] -= .20
    # The preference for source frame zero must not eliminate an available
    # two-sided movement.  Small silhouette changes can leave that first
    # centroid effectively at one extreme (for example Gyarados's front).
    interior = (values > float(values.min()) + .1) & (values < float(values.max()) - .1)
    if extent >= .5 and np.any(interior):
        base_scores[~interior] = np.inf
    base_local = int(np.argmin(base_scores))
    base = candidates[base_local]
    base_value = float(values[base_local])
    choices = []
    for sign in (-1, 1):
        eligible = [index for index in candidates if index != base and index not in choices]
        if not eligible:
            eligible = [index for index in candidates if index != base] or [base]
        directional = [index for index in eligible
                       if sign * (float(values[candidates.index(index)]) - base_value) > .1]
        if directional:
            eligible = directional
        def score(index: int) -> float:
            local = candidates.index(index)
            movement = sign * (float(values[local]) - base_value) / max(extent, .1)
            diversity = float(distances[base, index]) / spread
            if choices:
                diversity = min(diversity, float(distances[choices[0], index]) / spread)
            return movement + .22 * diversity
        choices.append(max(eligible, key=score))
    selected = [base, *choices]
    displacement = [round(float((metrics[index]["centroid"] or [0, 0])[axis] - base_value), 4)
                    for index in selected]
    if extent < .5:
        warnings.append("El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.")
    elif displacement[1] >= -.1 or displacement[2] <= .1:
        warnings.append("El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.")
    if len({labels[index] for index in selected}) < 3:
        warnings.append("El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.")
    return selected, {
        "axis": "y" if axis == 1 else "x",
        "range_px": round(extent, 4), "displacements": displacement,
    }, warnings


def _episodes(active: list[int], max_gap: int) -> list[list[int]]:
    groups: list[list[int]] = []
    for index in active:
        if not groups or index - groups[-1][-1] > max_gap + 1:
            groups.append([index])
        else:
            groups[-1].append(index)
    return groups


def _special_poses(idle: list[int], base_poses: list[int], distances: np.ndarray,
                   labels: list[int], durations: Sequence[float], loop: dict) -> tuple[list[int], dict, list[str]]:
    references = loop.get("reference_indices", idle)
    novelty = np.min(distances[:, references], axis=1)
    residual = loop["mean_error"] or 0
    threshold = max(.027, min(.09, residual * .5)) if loop.get("method") == "approximate" else max(.027, residual * 3)
    active = [index for index in range(loop["end_exclusive"], len(labels))
              if novelty[index] > threshold]
    episodes = _episodes(active, max_gap=2)
    warnings = []
    # A real special should be recognizably outside the repeated motion.  We
    # never claim that a uniform loop contains an independently detected one.
    if not episodes:
        warnings.append("No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.")
        remaining = [index for index in _unique(range(len(labels)), labels)
                     if labels[index] not in {labels[value] for value in base_poses}]
        if remaining:
            first = max(remaining, key=lambda index: float(np.min(distances[index, base_poses])))
            others = [index for index in remaining if index != first]
            second = max(others, key=lambda index: float(np.min(distances[index, [*base_poses, first]]))) if others else first
            selected = sorted([first, second])
        else:
            selected = [base_poses[1], base_poses[2]]
            selected.sort()
        return selected, {"detected": False, "range": None,
                          "novelty_threshold": threshold,
                          "novelty": [round(float(value), 5) for value in novelty]}, warnings

    def episode_score(episode: list[int]) -> float:
        representatives = _unique(episode, labels)
        # Reward distinct special poses, their novelty, and time on screen.
        # Cap length support so a prolonged hold does not dominate a gesture.
        diversity = float(np.max(distances[np.ix_(representatives, representatives)]))
        hold = min(sum(durations[index] for index in episode) / 1000, 1)
        return float(np.max(novelty[episode])) + .6 * diversity + .015 * hold

    episode = max(episodes, key=episode_score)
    candidates = _unique(episode, labels)
    peak_novelty = float(np.max(novelty[episode]))
    best_pair = None
    best_score = -1.0
    for position, first in enumerate(candidates):
        for second in candidates[position + 1:]:
            # End on a culmination of the gesture, not on its return toward
            # idle.  Otherwise a moving flame or tail can make a nearly-base
            # final pose score highly merely because it differs from the peak.
            if (novelty[first] < peak_novelty * .45
                    or novelty[second] < peak_novelty * .9
                    or novelty[second] < novelty[first]):
                continue
            separation = float(distances[first, second])
            score = .7 * separation + .5 * min(float(novelty[first]), float(novelty[second]))
            score += .15 * max(float(novelty[first]), float(novelty[second]))
            # A final special pose should be later in this same excursion.
            score += .012 * (second - first) / max(1, episode[-1] - episode[0])
            if score > best_score:
                best_score, best_pair = score, [first, second]
    if best_pair is None:
        peak = max(candidates, key=lambda index: float(novelty[index]))
        others = [index for index in candidates if labels[index] != labels[peak]]
        if others:
            other = max(others, key=lambda index: float(distances[index, peak]))
            best_pair = sorted([peak, other])
            warnings.append("El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.")
        else:
            best_pair = [peak, peak]
            warnings.append("El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.")
    elif distances[best_pair[0], best_pair[1]] < .018:
        warnings.append("Las dos poses especiales son muy parecidas; revisar manualmente.")
    return best_pair, {
        "detected": True, "range": [int(episode[0]), int(episode[-1])],
        "novelty_threshold": round(threshold, 5),
        "novelty": [round(float(value), 5) for value in novelty],
    }, warnings


def select_frames(frames: Sequence[Image.Image], durations: Sequence[float], count: int) -> dict:
    """Return exactly 3 back or 5 front source indices plus review diagnostics.

    ``indices`` order is base, up/left, down/right, special 1, special 2.
    The two specials keep source chronological order within one excursion.
    Images are never changed, cropped, resized, translated, or synthesized.
    ``unique_count`` counts exact visible RGBA poses in the whole animation.
    """
    if count not in (3, 5):
        raise ValueError("La selección debe tener 3 frames back o 5 frames front")
    if not frames or len(frames) != len(durations):
        raise ValueError("Se requiere una duración por fotograma y al menos un fotograma")
    if len({frame.size for frame in frames}) != 1:
        raise ValueError("Los frames deben conservar el mismo lienzo APNG")
    if any(not np.isfinite(duration) or duration <= 0 for duration in durations):
        raise ValueError("Las duraciones deben ser positivas y finitas")
    distances, labels, metrics = _features(frames)
    loop = _find_loop(distances, labels)
    warnings = []
    if not loop["detected"]:
        warnings.append("No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.")
    elif loop.get("method") == "approximate":
        warnings.append("El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.")
    if any(metric["area"] == 0 for metric in metrics):
        warnings.append("La animación contiene frames completamente transparentes.")
    idle = loop["indices"]
    selected, motion, idle_warnings = _idle_poses(idle, distances, labels, metrics, durations)
    warnings.extend(idle_warnings)
    special = {"detected": False, "range": None}
    if count == 5:
        specials, special, special_warnings = _special_poses(idle, selected, distances, labels, durations, loop)
        selected.extend(specials)
        warnings.extend(special_warnings)
    unique_count = len(set(labels))
    if unique_count < count:
        warnings.append(f"La fuente solo tiene {unique_count} poses distintas para {count} frames; se conservan repeticiones.")
    if len({labels[index] for index in selected}) < min(unique_count, count):
        warnings.append("La separación entre ciclo base y especial obliga a repetir alguna pose; índices editables para revisión.")
    return {
        "indices": [int(index) for index in selected],
        "unique_count": unique_count,
        "selected_unique_count": len({labels[index] for index in selected}),
        "warnings": list(dict.fromkeys(warnings)),
        "metrics": {
            "canvas": list(frames[0].size), "frame_count": len(frames),
            "duration_ms": round(float(sum(durations)), 3),
            "frame_metrics": metrics, "pose_labels": labels,
            "selected_durations_ms": [float(durations[index]) for index in selected],
            "selected_pair_distances": [[round(float(distances[left, right]), 5)
                                         for right in selected] for left in selected],
            "loop": loop, "motion": motion, "special": special,
        },
    }

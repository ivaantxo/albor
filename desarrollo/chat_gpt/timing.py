"""Project an APNG timeline onto the retained poses without speeding it up.

The image slots are semantic (base, up/left, down/right, special 1, special 2),
not chronological.  Each original interval is assigned to a retained pose and
its entire duration is kept.  Identical consecutive slots become a single
AnimCmd hold; returns to an earlier slot remain separate commands.

``sequence`` is the authoritative game/preview timeline. ``loop`` and
``special`` are representative building blocks for an explicit cadence
override; repeating the blocks cannot preserve variable delays between the
original cycles. No image is changed by this module.
"""

from __future__ import annotations

import math
from typing import Sequence


DEFAULT_FPS = 60


def _round_ticks(milliseconds: float, fps: float) -> int:
    return int(math.floor(milliseconds * fps / 1000 + .5))


def _runs(slots: Sequence[int], durations: Sequence[float]) -> list[dict]:
    result = []
    for slot, duration in zip(slots, durations):
        if result and result[-1]['frame'] == slot:
            result[-1]['duration_ms'] += duration
        else:
            result.append({'frame': int(slot), 'duration_ms': float(duration)})
    return result


def _base_first(runs: list[dict]) -> list[dict]:
    """Rotate a cyclic script, keeping the total elapsed time unchanged."""
    if not runs:
        return []
    first = next((index for index, run in enumerate(runs) if run['frame'] == 0), 0)
    result = [dict(run) for run in runs[first:] + runs[:first]]
    # A hold split by the APNG file boundary belongs to one continuous pose.
    merged = []
    for run in result:
        if merged and merged[-1]['frame'] == run['frame']:
            merged[-1]['duration_ms'] += run['duration_ms']
        else:
            merged.append(run)
    return merged


def _quantize(runs: list[dict], fps: float) -> list[dict]:
    """Round elapsed boundaries, not each APNG delay independently.

    The resulting sum differs from the requested duration by at most half a
    video tick. Intervals shorter than the display refresh may disappear;
    they must not be rounded up separately and slow down the animation.
    """
    result = []
    elapsed_ms = 0.0
    previous_ticks = 0
    for run in runs:
        elapsed_ms += run['duration_ms']
        elapsed_ticks = _round_ticks(elapsed_ms, fps)
        ticks = elapsed_ticks - previous_ticks
        previous_ticks = elapsed_ticks
        if ticks <= 0:
            continue
        if result and result[-1]['frame'] == run['frame']:
            result[-1]['ticks'] += ticks
        else:
            result.append({'frame': run['frame'], 'ticks': ticks})
    # A static source shorter than one VBlank still needs a drawable frame.
    if not result and runs:
        result = [{'frame': runs[0]['frame'], 'ticks': 1}]
    return result


def _visual_distances(source_frames, indices: list[int]):
    """Premultiplied colour + alpha, matching the selector's pose metric."""
    import numpy as np
    from PIL import Image

    features = []
    for frame in source_frames:
        pixels = np.array(frame.convert('RGBA'), dtype=np.uint8)
        pixels[np.all(pixels[:, :, :3] == (255, 0, 255), axis=2), 3] = 0
        pixels[pixels[:, :, 3] == 0] = 0
        tiny = np.asarray(Image.fromarray(pixels).resize(
            (24, 24), Image.Resampling.BOX), dtype=np.float32) / 255
        alpha = tiny[:, :, 3:4]
        features.append(np.concatenate((tiny[:, :, :3] * alpha * .75,
                                        alpha * 2), axis=2).reshape(-1))
    matrix = np.asarray(features)
    retained = matrix[indices]
    return np.sum((matrix[:, None, :] - retained[None, :, :]) ** 2, axis=2)


def _projection(source_indices: list[int], durations: list[float], labels: list[int],
                retained: list[int], allowed: list[list[int]], distances=None,
                cyclic: bool = True) -> list[int]:
    """Map every interval, preferring exact poses, then visual or time distance."""
    starts = []
    elapsed = 0.0
    for source_index in source_indices:
        starts.append(elapsed + durations[source_index] / 2)
        elapsed += durations[source_index]
    anchors = [(position, slot)
               for position, source_index in enumerate(source_indices)
               for slot, selected_index in enumerate(retained)
               if labels[source_index] == labels[selected_index]
               and slot in allowed[position]]
    projected = []
    for position, source_index in enumerate(source_indices):
        choices = allowed[position]
        exact = [slot for slot in choices
                 if labels[source_index] == labels[retained[slot]]]
        if exact:
            projected.append(min(exact))
        elif distances is not None:
            projected.append(min(choices, key=lambda slot: (distances[source_index][slot], slot)))
        else:
            candidates = [(anchor, slot) for anchor, slot in anchors if slot in choices]
            if candidates:
                def distance(anchor):
                    delta = abs(starts[position] - starts[anchor[0]])
                    return (min(delta, elapsed - delta) if cyclic else delta, anchor[1])
                projected.append(min(candidates, key=distance)[1])
            else:
                # Manual selections can lie outside the detected idle cycle.
                # The diagnostic makes this fallback visible to the reviewer.
                projected.append(min(choices, key=lambda slot: abs(source_index - retained[slot])))
    return projected


def build_timing(view: dict, source_frames=None, *, fps: float = DEFAULT_FPS,
                 idle_cycles_before_special: int | None = None) -> dict:
    """Build a serializable, variable-duration 5-front / 3-back AnimCmd script.

    ``view`` is one selection.json view, with ``indices``, ``side``,
    ``source_durations_ms`` and ``automatic_selection.metrics``. Pass original
    composited RGBA frames for visual nearest-pose projection. Without images,
    exact pose labels and their elapsed-time proximity are used instead.

    Fronts with a detected special retain the complete source chronology and
    total duration, including differently timed repeats. Backs repeat just the
    detected initial idle cycle. A front without an independently detected
    special plays four idle cycles followed by one five-pose projection of the
    idle cycle; this *synthetic cadence* is explicitly reported for review.

    An explicit ``idle_cycles_before_special`` replaces source cadence with
    that many representative idle cycles plus one representative gesture.
    All durations are positive video ticks accepted by ANIMCMD_FRAME, whose
    duration in this repository is u32 (the old 63-tick limit does not apply).
    """
    durations = [float(value) for value in view['source_durations_ms']]
    retained = list(view['indices'])
    side = view.get('side', 'front' if len(retained) == 5 else 'back')
    if side not in ('front', 'back') or len(retained) != (5 if side == 'front' else 3):
        raise ValueError('Se requieren 5 índices front o 3 índices back')
    if not durations or any(not math.isfinite(value) or value <= 0 for value in durations):
        raise ValueError('Las duraciones APNG deben ser positivas y finitas')
    if any(not isinstance(index, int) or not 0 <= index < len(durations) for index in retained):
        raise ValueError('Un índice seleccionado está fuera de la animación APNG')
    if not math.isfinite(fps) or fps <= 0:
        raise ValueError('fps debe ser positivo y finito')
    if (idle_cycles_before_special is not None
            and (not isinstance(idle_cycles_before_special, int) or idle_cycles_before_special < 0)):
        raise ValueError('idle_cycles_before_special debe ser un entero no negativo')
    if source_frames is not None and len(source_frames) != len(durations):
        raise ValueError('Se necesita una imagen fuente por duración APNG')

    metrics = view.get('automatic_selection', {}).get('metrics', {})
    labels = metrics.get('pose_labels', list(range(len(durations))))
    if len(labels) != len(durations):
        raise ValueError('pose_labels debe contener una etiqueta por frame APNG')
    loop_metadata = metrics.get('loop', {})
    loop_indices = loop_metadata.get('indices') or list(range(len(durations)))
    if any(not 0 <= index < len(durations) for index in loop_indices):
        raise ValueError('El ciclo contiene un frame APNG inexistente')
    distances = _visual_distances(source_frames, retained) if source_frames is not None else None
    warnings = []
    if not loop_metadata.get('detected'):
        warnings.append('El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.')
    if any(labels[index] not in {labels[value] for value in loop_indices} for index in retained[:3]):
        # Un aleteo o una llama puede repetirse antes de que el cuerpo complete
        # su vaiven. La seleccion tiene prioridad: incluir todos sus extremos.
        last_anchor = max(retained[:3])
        first_label = labels[loop_indices[0]]
        expanded_end = next((i for i in range(last_anchor + 1, len(labels))
                             if labels[i] == first_label), len(labels))
        loop_indices = list(range(loop_indices[0], expanded_end))
        loop_metadata = {**loop_metadata, 'end_exclusive': expanded_end}
        warnings.append('Ciclo ampliado para incluir todas las poses base elegidas; '
                        'la repeticion corta detectaba un movimiento secundario.')

    idle_slots = _projection(loop_indices, durations, labels, retained,
                             [[0, 1, 2] for _ in loop_indices], distances)
    idle_runs = _base_first(_runs(idle_slots, [durations[index] for index in loop_indices]))
    source_duration_ms = sum(durations)
    special_metadata = metrics.get('special', {})
    detected = bool(side == 'front' and special_metadata.get('detected')
                    and special_metadata.get('range'))
    special_runs = []
    special_range = None
    source_projection = []
    inferred_cycles = None

    if side == 'back':
        sequence_runs = idle_runs
        mode = 'source_idle_cycle'
    elif detected:
        start, end = special_metadata['range']
        if not (0 <= start <= end < len(durations)):
            raise ValueError('El episodio especial sale de los límites APNG')
        loop_end = int(loop_metadata.get('end_exclusive', loop_indices[-1] + 1))
        novelty = special_metadata.get('novelty', [])
        threshold = special_metadata.get('novelty_threshold', 0)
        all_indices = list(range(len(durations)))
        allowed = []
        for index in all_indices:
            novel = novelty[index] > threshold if len(novelty) == len(durations) else index >= start
            slots = [0, 1, 2, 3, 4] if index >= loop_end and novel else [0, 1, 2]
            # Explicit choices must retain their identity even when a heuristic
            # novelty threshold classifies the selected transition as idle.
            for slot in (3, 4):
                if index == retained[slot] and slot not in slots:
                    slots.append(slot)
            allowed.append(slots)
        source_projection = _projection(all_indices, durations, labels, retained, allowed, distances)
        sequence_runs = _base_first(_runs(source_projection, durations))
        # Include the preparation since the preceding idle-cycle boundary and
        # the return until the next source cycle starts, when one exists.
        special_start = max(0, (start // max(1, loop_end)) * loop_end)
        special_end = next((index for index in range(end + 1, len(durations))
                            if labels[index] == labels[loop_indices[0]]), len(durations))
        special_range = [special_start, special_end]
        special_runs = _runs(source_projection[special_start:special_end],
                             durations[special_start:special_end])
        inferred_cycles = special_start // max(1, loop_end)
        mode = 'source_timeline'
        if idle_cycles_before_special is not None:
            sequence_runs = _base_first(idle_runs * idle_cycles_before_special + special_runs)
            mode = 'custom_cadence'
    else:
        count = 4 if idle_cycles_before_special is None else idle_cycles_before_special
        # Some manual special choices are outside the detected idle cycle;
        # include them in the representative excursion rather than omit them.
        excursion = sorted(set(loop_indices) | set(retained[3:]))
        slots = _projection(excursion, durations, labels, retained,
                            [list(range(5)) for _ in excursion], distances)
        special_runs = _base_first(_runs(slots, [durations[index] for index in excursion]))
        sequence_runs = _base_first(idle_runs * count + special_runs)
        inferred_cycles = count
        mode = 'synthetic_special_cadence'
        warnings.append('No se detecta un especial independiente: se usa una cadencia sintética '
                        'de ciclos base y una pasada con las cinco poses seleccionadas.')

    sequence = _quantize(sequence_runs, fps)
    loop = _quantize(idle_runs, fps)
    special = _quantize(special_runs, fps)
    effective_ms = sum(run['duration_ms'] for run in sequence_runs)
    return {
        'version': 1,
        'mode': mode,
        'method': 'nearest_visual_pose' if distances is not None else 'nearest_temporal_pose_anchor',
        'fps': fps,
        'loop': loop,
        'special': special,
        'sequence': sequence,
        'idle_cycles_before_special': (idle_cycles_before_special if idle_cycles_before_special is not None
                                       else inferred_cycles),
        'source_duration_ms': round(source_duration_ms, 6),
        'effective_duration_ms': round(effective_ms, 6),
        'cycle_ticks': sum(step['ticks'] for step in sequence),
        'loop_ticks': sum(step['ticks'] for step in loop),
        'special_ticks': sum(step['ticks'] for step in special),
        'source_special_range_exclusive': special_range,
        'source_frame_to_slot': source_projection,
        'warnings': warnings,
    }


def animcmd_lines(timing: dict, *, end: bool = False,
                  frame_macro: str = 'POSE_DURANTE') -> list[str]:
    """Render the authoritative script using variable-duration game macros."""
    result = [f"{frame_macro}({step['frame']}, {step['ticks']}),"
              for step in timing['sequence']]
    result.append('TERMINA,' if end else 'VUELTA_AL_PRINCIPIO,')
    return result

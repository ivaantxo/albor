#!/usr/bin/env python3
"""Selector BW reproducible. Solo escribe dentro de desarrollo/chat_gpt."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import sys
import tempfile
from collections import Counter

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
try:
    from PIL import Image, ImageDraw
    import numpy as np
except ImportError:
    interpreter = HERE / '.venv/bin/python'
    if interpreter.exists() and Path(sys.prefix).resolve() != (HERE / '.venv').resolve():
        os.execv(str(interpreter), [str(interpreter), str(Path(__file__).resolve()), *sys.argv[1:]])
    sys.exit('Instala las dependencias: desarrollo/chat_gpt/.venv/bin/python -m pip install -r desarrollo/chat_gpt/requirements.txt')

from catalog import build_catalog
from palette import build_palette, index_image
from selection import load_animation, select_frames

MAGENTA = (255, 0, 255)
SIDES = {'front': 5, 'back': 3}
ROLES = ['base', 'arriba / izquierda', 'abajo / derecha', 'especial 1', 'especial 2']


def dump_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + '.tmp')
    temporary.write_text(json.dumps(value, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
    temporary.replace(path)


def read_palette(path):
    if not path.is_file():
        return None
    lines = path.read_text().splitlines()
    if lines[:3] != ['JASC-PAL', '0100', '16']:
        return None
    return [tuple(map(int, row.split())) for row in lines[3:19]]


def save_palette(path, palette):
    path.write_text('JASC-PAL\n0100\n16\n' + ''.join(f'{r} {g} {b}\n' for r, g, b in palette), encoding='ascii')


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def common_bbox(frames):
    boxes = [im.getchannel('A').getbbox() for im in frames]
    if not all(boxes):
        raise ValueError('La selección contiene un frame vacío.')
    return (min(b[0] for b in boxes), min(b[1] for b in boxes),
            max(b[2] for b in boxes), max(b[3] for b in boxes))


def integer(value, label, minimum=None):
    if type(value) is not int or (minimum is not None and value < minimum):
        raise ValueError(f'{label} debe ser un entero' + (f' >= {minimum}' if minimum is not None else ''))
    return value


def place_frames(frames, options):
    """Una traslación por vista; nunca reescala ni alinea frames por separado."""
    if len({im.size for im in frames}) != 1:
        raise ValueError('Los frames de una animación deben compartir lienzo.')
    box = common_bbox(frames)
    width, height = box[2] - box[0], box[3] - box[1]
    exceptional = max(width, height) > 96
    offset = options.get('offset', [0, 0])
    if not isinstance(offset, list) or len(offset) != 2:
        raise ValueError('offset debe ser [x, y].')
    dx, dy = (integer(v, 'offset') for v in offset)
    if exceptional:
        if (dx, dy) != (0, 0) or options.get('size', 'native') != 'native':
            raise ValueError('Un sprite excepcional conserva lienzo y posición originales; no admite size ni offset.')
        size = frames[0].size
        translation = (0, 0)
    else:
        side = options.get('size', next(s for s in (64, 80, 96) if max(width, height) <= s))
        if type(side) is not int or side not in (64, 80, 96):
            raise ValueError('size debe ser 64, 80 o 96.')
        size = (side, side)
        translation = ((side - width) // 2 - box[0] + dx, side - box[3] + dy)
    tx, ty = translation
    if box[0] + tx < 0 or box[1] + ty < 0 or box[2] + tx > size[0] or box[3] + ty > size[1]:
        raise ValueError('El tamaño/offset recortaría píxeles. Aumenta size o reduce el desplazamiento.')
    placed = []
    for frame in frames:
        canvas = Image.new('RGBA', size, MAGENTA + (0,))
        # Copia sin máscara: usar el propio alpha como máscara lo multiplicaría.
        canvas.paste(frame, translation)
        placed.append(canvas)
    return placed, {'source_canvas': list(frames[0].size), 'frame_size': list(size),
                    'source_bbox': list(box), 'translation': list(translation),
                    'offset': offset, 'exceptional_size': exceptional,
                    'alignment': 'native' if exceptional else 'union_center_bottom'}


def sheet(frames, indices, title, path, columns=8, roles=None):
    """Informe visual raster, con los índices originales para overrides.json."""
    if not frames:
        return
    zoom = 2
    w, h = frames[0].size
    cell_w, cell_h = max(w * zoom + 16, 222 if roles else 152), h * zoom + 42
    cols = min(columns, len(frames))
    rows = (len(frames) + cols - 1) // cols
    result = Image.new('RGB', (cols * cell_w, 36 + rows * cell_h), '#202733')
    draw = ImageDraw.Draw(result)
    draw.text((10, 10), title, fill='white')
    for i, (frame, source_index) in enumerate(zip(frames, indices)):
        x, y = (i % cols) * cell_w, 36 + (i // cols) * cell_h
        draw.rectangle((x + 4, y + 4, x + cell_w - 5, y + cell_h - 5), fill='#d8dce4')
        scaled = frame.convert('RGBA').resize((w * zoom, h * zoom), Image.Resampling.NEAREST)
        result.paste(scaled, (x + (cell_w - w * zoom) // 2, y + 4), scaled)
        label = f'{i}: {roles[i]} | APNG {source_index}' if roles else f'APNG {source_index}'
        draw.text((x + 9, y + h * zoom + 11), label, fill='#17202c')
    result.save(path)


def source_sheet(frames, path, title):
    seen, unique, indices = set(), [], []
    for i, frame in enumerate(frames):
        digest = hashlib.sha256(frame.tobytes()).digest()
        if digest not in seen:
            seen.add(digest)
            unique.append(frame)
            indices.append(i)
    sheet(unique, indices, title + ' / poses distintas; indice APNG original', path)


def save_preview(path, indexed, order, milliseconds):
    frames = [indexed[i] for i in order]
    frames[0].save(path, save_all=True, append_images=frames[1:], duration=milliseconds,
                   loop=0, transparency=0, disposal=2, optimize=False)


def palette_sheet(palette, path):
    result = Image.new('RGB', (16 * 58, 82), '#202733')
    draw = ImageDraw.Draw(result)
    for i, color in enumerate(palette):
        draw.rectangle((i * 58 + 3, 3, i * 58 + 54, 43), fill=color)
        draw.text((i * 58 + 5, 48), str(i), fill='white')
        draw.text((i * 58 + 3, 64), ''.join(f'{v:02X}' for v in color), fill='white')
    result.save(path)


def relative(path):
    return str(path.resolve().relative_to(REPO))


def normalize_species(value):
    return value.upper().removeprefix('SPECIES_')


def managed_files(entry):
    names = {'selection.json'}
    if entry.get('views'):
        names.update({'normal.pal', 'palette.png'})
    for view in entry.get('views', []):
        names.add(view['filename'])
        names.update(f"{view['stem']}_{suffix}" for suffix in ('selected.png', 'source.png', 'preview.gif'))
        if view['variant'] == 'female':
            names.add('normalf.pal')
    if any(Path(name).name != name for name in names):
        raise ValueError('El manifiesto contiene nombres de archivo inválidos.')
    return names


def prepare_species(entry, config, settings, all_sheets):
    """Renderiza primero; publica después y archiva los archivos que ya no aplican."""
    folder = HERE / 'pokemon' / entry['output_dir']
    if not folder.resolve().is_relative_to((HERE / 'pokemon').resolve()):
        raise ValueError('Ruta de salida fuera de pokemon.')
    folder.mkdir(parents=True, exist_ok=True)
    previous = json.loads((folder / 'selection.json').read_text()) if (folder / 'selection.json').exists() else {}
    # Si ya existían hojas originales, mantenerlas sincronizadas incluso en build sin flag.
    all_sheets = all_sheets or any(folder.glob('*_source.png'))
    staging = HERE / '.staging'
    staging.mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='species-', dir=staging) as temporary:
        working = Path(temporary)
        result = _prepare_species_files(entry, config, settings, all_sheets, working)
        new_names = {p.name for p in working.iterdir()}
        archived = []
        for name in sorted(managed_files(previous) - new_names):
            old = folder / name
            if old.is_file():
                destination = HERE / 'archive' / entry['output_dir'] / sha256(old)[:16] / name
                destination.parent.mkdir(parents=True, exist_ok=True)
                old.replace(destination)
                archived.append(str(destination.relative_to(HERE)))
        if archived:
            result['archived_files'] = archived
            dump_json(working / 'selection.json', result)
        for path in sorted(working.iterdir(), key=lambda p: p.name == 'selection.json'):
            path.replace(folder / path.name)
    return result


def _prepare_species_files(entry, config, settings, all_sheets, folder):
    views, warnings = [], list(entry.get('warnings', [])) + list(config.get('notes', []))
    variants = [dict(v) for v in entry['variants']]
    # Una fuente manual puede añadir hembras y especies posteriores sin cambiar catálogo.
    for key in config:
        if key in ('default', 'female') and not any(v['key'] == key for v in variants):
            variants.append({'key': key, 'front': None, 'back': None,
                             'front_output': 'anim_frontf.png' if key == 'female' else 'anim_front.png',
                             'back_output': 'backf.png' if key == 'female' else 'back.png'})
    missing, shared = [], {}
    for variant in variants:
        key = variant['key']
        for side, count in SIDES.items():
            options = config.get(key, {}).get(side, {})
            if variant.get(f'{side}_shared_with_default') and not options:
                shared[f'{key}.{side}'] = f'default.{side}'
                continue
            source = options.get('source') or variant.get(side)
            if source is None:
                missing.append(f'{key}.{side}')
                continue
            path = (REPO / source).resolve()
            if not path.is_relative_to(REPO):
                raise ValueError('Las fuentes deben estar dentro del repositorio.')
            frames, durations = load_animation(path)
            selection = select_frames(frames, durations, count)
            indices = options.get('indices', selection['indices'])
            if not isinstance(indices, list) or len(indices) != count:
                raise ValueError(f'{key}.{side}: se necesitan exactamente {count} indices.')
            if any(type(i) is not int or not 0 <= i < len(frames) for i in indices):
                raise ValueError(f'{key}.{side}: índice fuera del APNG (0..{len(frames)-1}).')
            chosen = [frames[i] for i in indices]
            placed, layout = place_frames(chosen, options)
            name = variant.get(f'{side}_output') or ('anim_front' if side == 'front' else 'back') + ('f' if key == 'female' else '') + '.png'
            stem = Path(name).stem
            if Path(name).name != name:
                raise ValueError('El nombre del sprite debe ser un archivo, sin carpetas.')
            if len({frame.tobytes() for frame in chosen}) < count:
                warnings.append(f'{key}.{side}: la selección repite poses.')
            if layout['exceptional_size']:
                warnings.append(f'{key}.{side}: tamaño excepcional; conserva lienzo y coordenadas de origen.')
            if 'indices' not in options:
                warnings.extend(f'{key}.{side}: {w}' for w in selection.get('warnings', []))
            views.append({'variant': key, 'side': side, 'filename': name, 'stem': stem,
                          'source': relative(path), 'source_sha256': sha256(path),
                          'source_frame_count': len(frames), 'source_durations_ms': durations,
                          'indices': indices, 'selected_unique_count': len({frame.tobytes() for frame in chosen}),
                          'automatic_selection': selection,
                          'manual_selection': 'indices' in options, 'layout': layout,
                          'frames': placed, 'source_frames': frames if all_sheets else None})
    family_reference = settings.get('family_reference')
    palette, metadata = (None, None)
    if views:
        palette, metadata = build_palette([frame for view in views for frame in view['frames']],
                                          read_palette(REPO / 'graphics/pokemon' / entry['output_dir'] / 'normal.pal'),
                                          family_reference)
        if 'palette_order' in config:
            order = config['palette_order']
            if not isinstance(order, list) or any(type(i) is not int for i in order) or sorted(order) != list(range(16)) or order[0] != 0:
                raise ValueError('palette_order debe permutar 0..15 manteniendo 0 al principio.')
            palette = [palette[i] for i in order]
            metadata['manual_order'] = order
            inverse = {old: new for new, old in enumerate(order)}
            for ramp in metadata.get('ramps', []):
                ramp['indices'] = [inverse[i] for i in ramp['indices']]
            metadata['unused_indices'] = sorted(inverse[i] for i in metadata.get('unused_indices', []))
        palette = [tuple(color) for color in palette]
        save_palette(folder / 'normal.pal', palette)
        if any(view['variant'] == 'female' for view in views):
            save_palette(folder / 'normalf.pal', palette)
        palette_sheet(palette, folder / 'palette.png')
    sequences = {'front': {'loop': [0, 1, 0, 2], 'special': [0, 3, 4, 0],
                           'idle_cycles_before_special': settings['idle_cycles'], 'frame_ms': settings['frame_ms']},
                 'back': {'loop': [0, 1, 0, 2], 'frame_ms': settings['frame_ms']}}
    for view in views:
        indexed = [index_image(frame, palette) for frame in view['frames']]
        w, h = indexed[0].size
        strip = Image.new('P', (w, h * len(indexed)), 0)
        strip.putpalette([channel for color in palette for channel in color])
        strip.info['transparency'] = 0
        for i, frame in enumerate(indexed):
            strip.paste(frame, (0, i * h))
        strip.save(folder / view['filename'], bits=4, transparency=0)
        side = view['side']
        order = sequences[side]['loop']
        if side == 'front':
            order = order * settings['idle_cycles'] + sequences[side]['special']
        save_preview(folder / f"{view['stem']}_preview.gif", indexed, order, settings['frame_ms'])
        sheet([im.convert('RGBA') for im in indexed], view['indices'],
              f"{entry['species']} / {view['variant']} / {side}",
              folder / f"{view['stem']}_selected.png", columns=5, roles=ROLES[:len(indexed)])
        if all_sheets:
            source_sheet(view['source_frames'], folder / f"{view['stem']}_source.png", f"{entry['species']} / {view['variant']} / {side}")
        del view['frames'], view['source_frames']
    result = {'species': entry['species'], 'national_id': entry.get('national_id'),
              'output_dir': entry['output_dir'], 'family': entry.get('family'),
              'status': ('partial' if missing else 'generated') if views else 'missing',
              'missing_views': missing, 'shared_views': shared, 'warnings': warnings,
              'palette': palette, 'palette_metadata': metadata,
              'palette_groups': config.get('palette_groups', []),
              'animation': sequences, 'views': views}
    dump_json(folder / 'selection.json', result)
    return result


def report(entries, errors):
    summary = {'species_in_manifest': len(entries), 'status': dict(Counter(e['status'] for e in entries)),
               'generated_views': sum(len(e['views']) for e in entries),
               'sizes': dict(Counter('x'.join(map(str, v['layout']['frame_size'])) for e in entries for v in e['views'])),
               'exceptional_views': sum(v['layout']['exceptional_size'] for e in entries for v in e['views']),
               'quantized_species': sum(bool((e.get('palette_metadata') or {}).get('quantized')) for e in entries),
               'with_selection_warnings': sum(bool(e['warnings']) for e in entries),
               'errors': errors}
    dump_json(HERE / 'report.json', {'summary': summary, 'species': entries})
    lines = ['# Selección de sprites BW', '',
             f"Especies en el informe: {len(entries)}. Vistas exportadas: {summary['generated_views']}.", '',
             'Solo se exportan fuentes disponibles; no se sustituyen formas ni géneros por otros.', '',
             '| Especie | Estado | Front / back | Pendiente |', '| --- | --- | --- | --- |']
    for entry in entries:
        details = ', '.join(f"{v['variant']}.{v['side']} {'x'.join(map(str, v['layout']['frame_size']))}" for v in entry['views'])
        lines.append(f"| [{entry['species']}](pokemon/{entry['output_dir']}/selection.json) | {entry['status']} | {details} | {', '.join(entry['missing_views'])} |")
    lines.extend(['', '## Tamaños excepcionales', ''])
    for entry in entries:
        for v in entry['views']:
            if v['layout']['exceptional_size']:
                lines.append(f"- {entry['species']} {v['variant']}.{v['side']}: {v['layout']['frame_size']}; índices {v['indices']}. Conserva el lienzo original.")
    if errors:
        lines.extend(['', '## Errores', '', *[f"- {k}: {v}" for k, v in errors.items()]])
    (HERE / 'REPORT.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
    gallery_dir = HERE / 'gallery'
    gallery_dir.mkdir(exist_ok=True)
    available = [e for e in entries if e['views']]
    gallery = ['# Galería de selección', '',
               'Cada página muestra hasta 25 especies para facilitar la revisión de las animaciones. Los enlaces llevan a los frames elegidos y a las poses originales.', '',
               '| Página | Especies |', '| --- | --- |']
    for start in range(0, len(available), 25):
        chunk = available[start:start + 25]
        page = start // 25 + 1
        name = f'page_{page:02}.md'
        gallery.append(f"| [Página {page}](gallery/{name}) | {', '.join(e['species'] for e in chunk)} |")
        navigation = '[Índice](../GALLERY.md)'
        if page > 1:
            navigation += f' · [Anterior](page_{page-1:02}.md)'
        if start + 25 < len(available):
            navigation += f' · [Siguiente](page_{page+1:02}.md)'
        lines = [f'# Galería / página {page}', '', navigation, '']
        for entry in chunk:
            lines.extend([f"## {entry['species']}", ''])
            for v in entry['views']:
                base = f"../pokemon/{entry['output_dir']}/{v['stem']}"
                lines.extend([f"{v['variant']}.{v['side']} · {'×'.join(map(str, v['layout']['frame_size']))} · APNG {v['indices']}", '',
                              f"![{entry['species']} {v['side']}]({base}_preview.gif)", '',
                              f"[Frames elegidos]({base}_selected.png)" +
                              (f" · [Todas las poses]({base}_source.png)" if (gallery_dir / f'{base}_source.png').exists() else ''), ''])
        lines.extend([navigation, ''])
        (gallery_dir / name).write_text('\n'.join(lines), encoding='utf-8')
    (HERE / 'GALLERY.md').write_text('\n'.join(gallery) + '\n', encoding='utf-8')
    review = ['# Casos para revisar', '',
              'La separación entre ciclo base y gesto especial y la correspondencia anatómica de paletas son heurísticas. Estos casos necesitan especial atención.', '']
    for entry in entries:
        notes = list(entry['warnings'])
        meta = entry.get('palette_metadata') or {}
        if meta.get('quantized'):
            notes.append(f"Paleta reducida de {meta['source_opaque_color_count']} a {meta['opaque_palette_color_count']} colores opacos.")
        if notes:
            review.extend([f"## [{entry['species']}](pokemon/{entry['output_dir']}/selection.json)", '',
                           *[f'- {note}' for note in notes], ''])
    (HERE / 'REVIEW.md').write_text('\n'.join(review) + '\n', encoding='utf-8')
    return summary


def validate(entries, catalog):
    failures, checked = [], 0
    allowed = {entry['species']: entry['output_dir'] for entry in catalog}
    seen = set()
    for entry in entries:
        try:
            assert entry['species'] in allowed, 'especie fuera de species.txt'
            assert entry['species'] not in seen, 'especie duplicada en los resultados'
            seen.add(entry['species'])
            assert entry['output_dir'] == allowed[entry['species']], 'carpeta distinta de graphics/pokemon'
            folder = HERE / 'pokemon' / entry['output_dir']
            if not entry['views']:
                assert not any((folder / name).exists() for name in ('anim_front.png', 'back.png', 'anim_frontf.png', 'backf.png', 'normal.pal', 'normalf.pal')), 'quedan sprites o paletas antiguos para una especie sin fuente'
                continue
            expected = [tuple(c) for c in entry['palette']]
            assert len(expected) == 16 and expected[0] == MAGENTA, 'paleta inválida'
            assert read_palette(folder / 'normal.pal') == expected, 'normal.pal diferente'
            if any(v['variant'] == 'female' for v in entry['views']):
                assert read_palette(folder / 'normalf.pal') == expected, 'normalf.pal diferente'
            for view in entry['views']:
                count = SIDES[view['side']]
                assert view['variant'] in ('default', 'female'), 'variante no admitida'
                assert len(view['indices']) == count, 'número de índices incorrecto'
                assert Path(view['filename']).name == view['filename'], 'nombre de sprite inválido'
                source = (REPO / view['source']).resolve()
                assert source.is_relative_to(REPO.resolve()), 'fuente fuera del repositorio'
                assert sha256(source) == view['source_sha256'], 'fuente modificada desde la exportación'
                frames, _ = load_animation(source)
                assert all(type(i) is int and 0 <= i < len(frames) for i in view['indices']), 'índice fuera de la fuente'
                selected = [frames[i] for i in view['indices']]
                layout = view['layout']
                size, shift = tuple(layout['frame_size']), tuple(layout['translation'])
                image = Image.open(folder / view['filename'])
                assert image.mode == 'P', 'PNG no indexado'
                assert image.size == (size[0], size[1] * count), 'número/tamaño de frames incorrecto'
                assert image.info.get('transparency') == 0, 'transparencia distinta de índice cero'
                assert image.getpalette()[:48] == [v for c in expected for v in c], 'paleta PNG diferente'
                assert image.getextrema()[1] < 16, 'índice fuera de 4 bpp'
                if layout['exceptional_size']:
                    assert size == selected[0].size and shift == (0, 0), 'excepción redimensionada o movida'
                else:
                    assert size[0] == size[1] and size[0] in (64, 80, 96), 'lienzo no admitido'
                for i, original in enumerate(selected):
                    placed = Image.new('RGBA', size, MAGENTA + (0,))
                    placed.paste(original, shift)
                    assert np.count_nonzero(np.asarray(placed)[:, :, 3]) == np.count_nonzero(np.asarray(original)[:, :, 3]), 'píxeles recortados'
                    actual = image.crop((0, i * size[1], size[0], (i + 1) * size[1]))
                    assert actual.tobytes() == index_image(placed, expected).tobytes(), 'frame/posición/colores distintos de la selección'
                checked += 1
        except (AssertionError, ValueError, OSError, KeyError) as exc:
            failures.append(f"{entry['species']}: {exc}")
    result = {'checked_views': checked, 'checked_species': len(seen),
              'unbuilt_species': sorted(set(allowed) - seen), 'failures': failures, 'ok': not failures}
    dump_json(HERE / 'validation.json', result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['build', 'verify', 'catalog', 'review'])
    parser.add_argument('--only', nargs='+', help='Nombres de species.txt (con o sin SPECIES_).')
    parser.add_argument('--overrides', type=Path, default=HERE / 'overrides.json')
    parser.add_argument('--source-sheets', action='store_true', help='Añade hojas de todas las poses distintas del APNG.')
    args = parser.parse_args()
    catalog = build_catalog(REPO, REPO / 'desarrollo/.apng_bw')
    only = {normalize_species(s) for s in args.only} if args.only else None
    if only and only - {entry['species'] for entry in catalog}:
        parser.error('Especies fuera de species.txt: ' + ', '.join(sorted(only - {e['species'] for e in catalog})))
    if args.command == 'catalog':
        dump_json(HERE / 'catalog.json', catalog)
        print(f'Catálogo: {len(catalog)} entradas; {HERE / "catalog.json"}')
        return
    if args.command == 'verify':
        entries = [json.loads(path.read_text()) for path in sorted((HERE / 'pokemon').rglob('selection.json'))]
        if only:
            entries = [e for e in entries if e['species'] in only]
        if not entries:
            parser.error('No hay resultados que verificar. Ejecuta build primero.')
        result = validate(entries, [e for e in catalog if not only or e['species'] in only])
        if result['unbuilt_species']:
            result['failures'].append('Faltan manifiestos: ' + ', '.join(result['unbuilt_species']))
            result['ok'] = False
            dump_json(HERE / 'validation.json', result)
        print(json.dumps(result, indent=2, ensure_ascii=False))
        sys.exit(0 if result['ok'] else 1)
    if args.command == 'review':
        if not only:
            parser.error('review requiere --only ESPECIE [ESPECIE ...].')
        for entry in catalog:
            if entry['species'] not in only:
                continue
            folder = HERE / 'pokemon' / entry['output_dir']
            manifest = folder / 'selection.json'
            if not manifest.exists():
                parser.error(f"Genera {entry['species']} con build primero.")
            for view in json.loads(manifest.read_text())['views']:
                frames, _ = load_animation(REPO / view['source'])
                source_sheet(frames, folder / f"{view['stem']}_source.png", f"{entry['species']} / {view['variant']} / {view['side']}")
            print(folder)
        return
    config = json.loads(args.overrides.read_text(encoding='utf-8'))
    species_config = {normalize_species(k): v for k, v in config.get('species', {}).items()}
    unknown = set(species_config) - {e['species'] for e in catalog}
    if unknown:
        parser.error('Overrides fuera de species.txt: ' + ', '.join(sorted(unknown)))
    if set(config) - {'settings', 'species'}:
        parser.error('Claves desconocidas en overrides.json: ' + ', '.join(set(config) - {'settings', 'species'}))
    for name, options in species_config.items():
        if not isinstance(options, dict) or set(options) - {'default', 'female', 'palette_order', 'palette_groups', 'notes'}:
            parser.error(f'{name}: claves permitidas: default, female, palette_order, palette_groups, notes.')
        if 'notes' in options and (not isinstance(options['notes'], list) or not all(isinstance(note, str) for note in options['notes'])):
            parser.error(f'{name}.notes debe ser una lista de textos.')
        for variant in ('default', 'female'):
            if variant not in options:
                continue
            if not isinstance(options[variant], dict) or set(options[variant]) - set(SIDES):
                parser.error(f'{name}.{variant}: solo front y back.')
            for side, view_options in options[variant].items():
                if not isinstance(view_options, dict) or set(view_options) - {'indices', 'offset', 'size', 'source'}:
                    parser.error(f'{name}.{variant}.{side}: solo indices, offset, size y source.')
    settings = config.get('settings', {})
    if set(settings) - {'idle_cycles', 'frame_ms'}:
        parser.error('settings solo admite idle_cycles y frame_ms.')
    settings = {'idle_cycles': integer(settings.get('idle_cycles', 4), 'idle_cycles', 1),
                'frame_ms': integer(settings.get('frame_ms', 140), 'frame_ms', 10)}
    dump_json(HERE / 'catalog.json', catalog)
    by_species = {e['species']: e for e in catalog}
    entries, errors = [], {}
    for entry in catalog:
        if only and entry['species'] not in only:
            existing = HERE / 'pokemon' / entry['output_dir'] / 'selection.json'
            if existing.exists():
                entries.append(json.loads(existing.read_text()))
            continue
        family = by_species.get(normalize_species(entry.get('family') or ''))
        family_reference = read_palette(REPO / 'graphics/pokemon' / family['output_dir'] / 'normal.pal') if family else None
        try:
            result = prepare_species(entry, species_config.get(entry['species'], {}),
                                     {**settings, 'family_reference': family_reference}, args.source_sheets)
            entries.append(result)
            sizes = ', '.join(f"{v['variant']}.{v['side']}={v['layout']['frame_size']}" for v in result['views'])
            print(f"{entry['species']}: {result['status']} {sizes}", flush=True)
        except (ValueError, OSError, KeyError) as exc:
            errors[entry['species']] = str(exc)
            print(f"ERROR {entry['species']}: {exc}", file=sys.stderr, flush=True)
    summary = report(entries, errors)
    print(json.dumps(summary, indent=2, ensure_ascii=False))
    sys.exit(1 if errors else 0)


if __name__ == '__main__':
    main()

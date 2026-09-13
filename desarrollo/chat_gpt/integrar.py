#!/usr/bin/env python3
"""Genera datos C para make BW_SPRITES=1. No modifica graphics/pokemon.

Solo activa especies completas, con datos de juego y lienzos compatibles.
Los ficheros C generados conservan los datos originales de las demás especies.
No necesita Pillow y no copia ni genera paletas shiny.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import re
import struct

from catalog import build_catalog
from timing import animcmd_lines

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
MAX_COMMANDS = 2048


def replace_macro(body, name, arguments):
    pattern = rf'(?m)^([ \t]*){name}\([^\n]*\),[ \t]*$'
    matches = list(re.finditer(pattern, body))
    if len(matches) > 1:
        raise ValueError(f'Macro duplicada: {name}')
    replacement = f'{name}({arguments}),'
    if matches:
        return re.sub(pattern, lambda m: m[1] + replacement, body)
    # Insertar antes de la llave final de la entrada, no después de ella.
    closing = body.rfind('}')
    if closing < 0:
        raise ValueError('Bloque SpeciesInfo sin cierre')
    return body[:closing] + '    ' + replacement + '\n    ' + body[closing:]


def rewrite_species(body, symbol, views):
    """Actualiza campos visuales; las dimensiones son silueta, no stride PNG."""
    for key, view in views.items():
        variant, side = key
        macro = ('FRONT_PIC' if side == 'front' else 'BACK_PIC')
        if variant == 'female':
            macro += '_HEMBRA'
        x0, y0, x1, y1 = view['layout']['source_bbox']
        width, height = ((x1-x0+7)//8*8, (y1-y0+7)//8*8)
        body = replace_macro(body, macro, f'{symbol}, {width}, {height}')
    for name in ('ELEVACION_FRONT_PIC', 'ELEVACION_BACK_PIC'):
        body = replace_macro(body, name, '0')
    body = replace_macro(body, 'PALETAS', symbol)
    if ('female', 'front') in views:
        body = replace_macro(body, 'PALETAS_HEMBRA', symbol)
    front = re.search(r'FRONT_ANIM\(\s*\w+\s*,\s*(\w+)\s*\)', body)
    if not front:
        raise ValueError('Falta FRONT_ANIM: no se puede conservar la animacion afin')
    body = replace_macro(body, 'FRONT_ANIM', f'{symbol}, {front[1]}')
    return replace_macro(body, 'ANIM_ESPALDA', symbol)


def validate_view(folder, view):
    path = folder / view['filename']
    if path.parent.resolve() != folder.resolve():
        raise ValueError('Ruta PNG fuera de su especie')
    data = path.read_bytes()
    if data[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError(f'PNG invalido: {path}')
    width, height = struct.unpack('>II', data[16:24])
    frame_size = view['layout']['frame_size']
    count = 5 if view['side'] == 'front' else 3
    if width not in (64, 80, 96) or frame_size != [width, width] or height != width * count:
        raise ValueError('Lienzo excepcional o tira modificada: requiere edicion y regenerar metadatos')
    if data[24] > 4 or data[25] != 3:
        raise ValueError('Se requiere PNG indexado de 4 bpp como maximo')
    timing = view.get('timing', {})
    sequence = timing.get('sequence', [])
    if not sequence or len(sequence) + 1 > MAX_COMMANDS or any(
            type(s.get('frame')) is not int or not 0 <= s['frame'] < count or
            type(s.get('ticks')) is not int or not 1 <= s['ticks'] <= 0xffffffff
            for s in sequence):
        raise ValueError('Timing ausente o fuera de limites; ejecuta selector.py build')


def generate(repo=REPO, here=HERE):
    repo, here = Path(repo), Path(here)
    source_path = repo / 'src/data/pokemon/species_info.h'
    source = source_path.read_text(encoding='utf-8')
    starts = list(re.finditer(r'\[SPECIES_([A-Z0-9_]+)\]\s*=\s*\{', source))
    blocks = {m[1]: (m.end(), starts[i+1].start() if i+1 < len(starts) else source.rfind('};'))
              for i, m in enumerate(starts)}
    graphics, animations, assets, inputs, selections, replacements = [], [], [], [], [], []
    report = {'active': [], 'skipped': [], 'sources': {}}
    # Los helpers heredados definen las tablas de reposo y las macros SINGLE_ANIMATION/ESPALDA.
    old_animation_path = repo / 'src/data/pokemon/animaciones_pokemon.h'
    old_animations = old_animation_path.read_text(encoding='utf-8-sig')
    old_animations = old_animations.replace('static const ', 'static const __attribute__((unused)) ')
    animations.append(old_animations)
    for entry in build_catalog(repo, repo / 'desarrollo/.apng_bw'):
        species = entry['species']
        try:
            if species not in blocks:
                raise ValueError('No tiene entrada en species_info.h')
            folder = here / 'pokemon' / entry['output_dir']
            if not folder.resolve().is_relative_to((here / 'pokemon').resolve()):
                raise ValueError('Ruta fuera de pokemon')
            selection_path = folder / 'selection.json'
            selection = json.loads(selection_path.read_text())
            selections.append(selection_path.relative_to(repo).as_posix())
            if selection['species'] != species:
                raise ValueError('La seleccion pertenece a otra especie')
            views = {(v['variant'], v['side']): v for v in selection.get('views', [])}
            required = {(v['key'], side) for v in entry['variants'] for side in ('front', 'back')}
            if required - views.keys() or selection.get('missing_views'):
                raise ValueError('Faltan vistas de la especie o de su variante hembra')
            for view in views.values():
                validate_view(folder, view)
            symbol = 'BW_' + species
            begin, end = blocks[species]
            body = rewrite_species(source[begin:end], symbol, views)
            species_graphics, species_assets = [], []
            for (variant, side), view in views.items():
                suffix = 'F' if variant == 'female' else ''
                path = (folder / view['filename']).with_suffix('.4bpp.lz').relative_to(repo).as_posix()
                kind = 'Front' if side == 'front' else 'Back'
                species_graphics.append(f'const u32 gMon{kind}Pic_{symbol}{suffix}[] = INCBIN_U32("{path}");')
                species_assets.append(path)
                inputs.append((folder / view['filename']).relative_to(repo).as_posix())
            shiny_fallback = []
            for variant in sorted({v['variant'] for v in views.values()}):
                suffix = 'F' if variant == 'female' else ''
                file_suffix = 'f' if suffix else ''
                for shiny in (False, True):
                    filename = ('shiny' if shiny else 'normal') + file_suffix + '.pal'
                    palette = folder / filename
                    if shiny and not palette.is_file():
                        palette = folder / ('normal' + file_suffix + '.pal')
                        shiny_fallback.append(variant)
                    if not palette.is_file():
                        raise ValueError(f'Falta {palette.name}')
                    path = palette.with_suffix('.gbapal').relative_to(repo).as_posix()
                    pal_kind = 'ShinyPalette' if shiny else 'Palette'
                    species_graphics.append(f'const u16 gMon{pal_kind}_{symbol}{suffix}[] = INCBIN_U16("{path}");')
                    species_assets.append(path)
                    inputs.append(palette.relative_to(repo).as_posix())
            for side in ('front', 'back'):
                # Las tablas del motor se comparten por sexo. Sus cinco/tres slots
                # tienen los mismos papeles; los dibujos y paletas son independientes.
                timing = views['default', side]['timing']
                name = ('sAnim_' if side == 'front' else 'sAnimEspalda_') + symbol
                animations.extend([f'static const union AnimCmd {name}[] =', '{',
                                   *('    '+line for line in animcmd_lines(timing)), '};',
                                   f'{"SINGLE_ANIMATION" if side == "front" else "ESPALDA"}({symbol});'])
            replacements.append((begin, end, body))
            graphics.extend(species_graphics)
            assets.extend(species_assets)
            report['active'].append({'species': species, 'output_dir': entry['output_dir'],
                                     'female': ('female', 'front') in views,
                                     'shiny_uses_normal': shiny_fallback,
                                     'frames': {f'{v}.{s}': x['layout']['frame_size'] for (v,s),x in views.items()},
                                     'timing': {s: views['default',s]['timing']['mode'] for s in ('front','back')}})
            report['sources'][selection_path.relative_to(repo).as_posix()] = hashlib.sha256(selection_path.read_bytes()).hexdigest()
        except (ValueError, OSError, KeyError) as error:
            report['skipped'].append({'species': species, 'reason': str(error)})
    for begin, end, replacement in sorted(replacements, reverse=True):
        source = source[:begin] + replacement + source[end:]
    if not report['active']:
        raise ValueError('No hay especies integrables. Ejecuta selector.py build primero.')
    for path in (source_path, old_animation_path, repo / 'species.txt'):
        report['sources'][path.relative_to(repo).as_posix()] = hashlib.sha256(path.read_bytes()).hexdigest()
    output = here / 'generated'
    output.mkdir(exist_ok=True)
    banner = '// Generado por desarrollo/chat_gpt/integrar.py. Regenerar tras cambiar fuentes o selecciones.\n'
    outputs = {'species_info_bw.h': banner + source,
               'graphics_bw.h': banner + '\n'.join(graphics) + '\n',
               'animaciones_bw.h': banner + '\n'.join(animations) + '\n',
               'assets.mk': '# Generado por integrar.py\nBW_ASSETS := ' + ' '.join(sorted(set(assets))) + '\n'
                            + 'BW_INPUTS := ' + ' '.join(sorted(set(inputs))) + '\n'
                            + 'BW_SELECTIONS := ' + ' '.join(sorted(set(selections))) + '\n',
               'integration.json': json.dumps(report, ensure_ascii=False, indent=2) + '\n'}
    for name, text in outputs.items():
        path = output / name
        if not path.is_file() or path.read_text() != text:
            path.write_text(text)
    # Make usa este archivo incluido como sello incluso si el contenido no cambia.
    (output / 'assets.mk').touch()
    return report


if __name__ == '__main__':
    result = generate()
    print(f"Integradas: {len(result['active'])}; conservan datos originales: {len(result['skipped'])}.")
    print('Detalle: desarrollo/chat_gpt/generated/integration.json')
    print('Compilar: make BW_SPRITES=1 -j4  ->  albor_bw.gba')

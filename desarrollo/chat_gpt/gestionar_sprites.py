#!/usr/bin/env python3
"""Exporta los sprites definitivos o limpia auxiliares. Simula salvo --aplicar.

anim_front.png/back.png YA contienen los frames elegidos. Las hojas *_selected
son material de revisión y no se convierten ni se renombran como sprites.
"""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path
import shutil

from catalog import build_catalog

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
SOURCE = HERE / 'pokemon'
FINAL_NAMES = frozenset({'anim_front.png', 'back.png', 'normal.pal',
                         'anim_frontf.png', 'backf.png', 'normalf.pal',
                         'shiny.pal', 'shinyf.pal'})
AUX_NAMES = frozenset({'palette.png', 'selection.json'} | {
    f'{stem}_{suffix}'
    for stem in ('anim_front', 'back', 'anim_frontf', 'backf')
    for suffix in ('selected.png', 'source.png', 'preview.gif')
})


def matching_files(source, names, folders=None):
    """Lista exacta de nombres; nunca usa anim_front* o back* para borrar."""
    source = source.resolve()
    files = []
    for path in sorted(source.rglob('*')):
        if path.name not in names or not path.is_file():
            continue
        if folders is not None and path.parent.relative_to(source).as_posix() not in folders:
            continue
        if path.is_symlink() or not path.resolve().is_relative_to(source):
            raise ValueError(f'Archivo enlazado fuera de la carpeta de sprites: {path}')
        files.append(path)
    return files


def digest(path):
    return hashlib.sha256(path.read_bytes()).digest()


def plan_export(source, destination, folders=None, overwrite=False):
    source, destination = source.resolve(), destination.resolve()
    if destination.is_relative_to(source) or source.is_relative_to(destination):
        raise ValueError('El destino debe ser una carpeta independiente de pokemon/.')
    if destination.exists() and not destination.is_dir():
        raise ValueError(f'El destino no es una carpeta: {destination}')
    copies, unchanged = [], 0
    for original in matching_files(source, FINAL_NAMES, folders):
        target = destination / original.relative_to(source)
        # No seguir enlaces existentes ni atravesar archivos como directorios.
        for parent in [target, *target.parents]:
            if parent == destination.parent:
                break
            if parent.is_symlink():
                raise ValueError(f'Enlace en el destino: {parent}')
            if parent != target and parent.exists() and not parent.is_dir():
                raise ValueError(f'No es un directorio: {parent}')
        if target.exists():
            if not target.is_file():
                raise ValueError(f'No es un archivo: {target}')
            if digest(original) == digest(target):
                unchanged += 1
                continue
            if not overwrite:
                raise ValueError(f'Ya existe una versión diferente: {target}. Usa otro destino o --sobrescribir.')
        copies.append((original, target))
    return copies, unchanged


def apply_export(copies):
    for original, target in copies:
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(original, target)


def apply_cleanup(files):
    # Segunda comprobación de la lista exacta antes de efectuar ningún borrado.
    if any(path.name not in AUX_NAMES for path in files):
        raise ValueError('La lista contiene un archivo que no es auxiliar.')
    for path in files:
        path.unlink()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    export = sub.add_parser('exportar', help='Copia solo los PNG definitivos y las paletas normales.')
    export.add_argument('--destino', type=Path, default=HERE / 'pokemon_definitivos')
    export.add_argument('--sobrescribir', action='store_true', help='Permite reemplazar archivos diferentes en el destino.')
    clean = sub.add_parser('limpiar', help='Elimina únicamente auxiliares generados dentro de pokemon/.')
    for command in (export, clean):
        command.add_argument('--aplicar', action='store_true', help='Ejecuta el plan. Sin esta opción solo informa.')
        command.add_argument('--solo', nargs='+', help='Especies de species.txt, por ejemplo ARON BULBASAUR.')
        command.add_argument('--listar', action='store_true', help='Muestra todos los archivos del plan.')
    args = parser.parse_args()
    try:
        catalog = build_catalog(REPO, REPO / 'desarrollo/.apng_bw')
        selected = {s.upper().removeprefix('SPECIES_') for s in args.solo} if args.solo else None
        if selected and selected - {e['species'] for e in catalog}:
            raise ValueError('Especies fuera de species.txt: ' + ', '.join(sorted(selected - {e['species'] for e in catalog})))
        folders = {e['output_dir'] for e in catalog if not selected or e['species'] in selected}
        if args.command == 'exportar':
            destination = args.destino.resolve()
            copies, unchanged = plan_export(SOURCE, destination, folders, args.sobrescribir)
            files = [original for original, _ in copies]
            print(f'Exportar {len(files)} archivos; {unchanged} ya son idénticos.\nDestino: {destination}')
            print('Se copian literalmente los definitivos, incluidos los tamaños excepcionales; no se convierte ninguna hoja de revisión.')
        else:
            files = matching_files(SOURCE, AUX_NAMES, folders)
            print(f'Limpiar {len(files)} auxiliares de {SOURCE}')
            print('Esto elimina las previsualizaciones y selection.json: la galería, verify y review necesitarán regenerarse.')
        total = sum(path.stat().st_size for path in files)
        print(f'Tamaño: {total / (1024 * 1024):.2f} MiB')
        if args.listar:
            for path in files:
                print(path.relative_to(SOURCE))
        if not args.aplicar:
            print('SIMULACIÓN: no se ha copiado ni borrado nada. Añade --aplicar para ejecutar.')
            return
        if args.command == 'exportar':
            apply_export(copies)
        else:
            apply_cleanup(files)
        print('Terminado.')
    except (OSError, ValueError) as exc:
        parser.exit(1, f'Error: {exc}\n')


if __name__ == '__main__':
    main()

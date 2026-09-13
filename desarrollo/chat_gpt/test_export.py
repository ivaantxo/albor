"""Exportación completa con APNG pequeños y repositorios temporales aislados."""

from contextlib import redirect_stderr, redirect_stdout
from copy import deepcopy
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import numpy as np
from PIL import Image, ImageDraw

import selector


class ExportTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory(prefix='bw-export-test-')
        self.addCleanup(temporary.cleanup)
        self.repo = Path(temporary.name).resolve()
        self.here = self.repo / 'desarrollo/chat_gpt'
        self.here.mkdir(parents=True)
        self.addCleanup(patch.stopall)
        patch.object(selector, 'REPO', self.repo).start()
        patch.object(selector, 'HERE', self.here).start()
        self.sources = {}
        source_dir = self.repo / 'desarrollo/.apng_bw'
        source_dir.mkdir(parents=True)
        for side, color in (('front', (40, 170, 80)), ('back', (70, 90, 190))):
            frames = []
            for dx, dy in ((0, 0), (1, -2), (-1, 2), (2, -1), (0, 1), (-3, -3), (3, 3)):
                frame = Image.new('RGBA', (90, 90), (255, 0, 255, 255))
                draw = ImageDraw.Draw(frame)
                draw.rectangle((30 + dx, 25 + dy, 47 + dx, 49 + dy), fill=color + (255,))
                draw.rectangle((32 + dx, 27 + dy, 36 + dx, 32 + dy), fill=(10, 20, 30, 255))
                frames.append(frame)
            path = source_dir / f'{side}.png'
            frames[0].save(path, save_all=True, append_images=frames[1:], duration=100,
                           loop=0, disposal=0, blend=0)
            self.sources[side] = str(path.relative_to(self.repo))
        self.entry = {
            'species': 'BULBASAUR', 'national_id': 1, 'output_dir': 'bulbasaur',
            'family': 'bulbasaur', 'warnings': [],
            'variants': [{'key': 'default', **self.sources,
                          'front_output': 'anim_front.png', 'back_output': 'back.png'}],
        }
        self.settings = {'idle_cycles': 4, 'frame_ms': 140}
        self.config = {'default': {
            'front': {'indices': [0, 1, 2, 5, 6], 'offset': [1, -3]},
            'back': {'indices': [0, 1, 2], 'offset': [-1, -2]},
        }}
        self.folder = self.here / 'pokemon/bulbasaur'
        original = self.repo / 'graphics/pokemon/bulbasaur'
        original.mkdir(parents=True)
        (original / 'original.txt').write_text('No modificar los originales.\n')

    def build(self, entry=None, config=None, sheets=False):
        return selector.prepare_species(entry or self.entry, self.config if config is None else config,
                                        self.settings, sheets)

    def test_export_uses_manual_frames_offsets_and_one_exact_palette(self):
        original = self.repo / 'graphics/pokemon/bulbasaur/original.txt'
        before = original.read_bytes()
        result = self.build(sheets=True)
        self.assertEqual(result['status'], 'generated')
        self.assertEqual(len(result['views']), 2)
        palette = selector.read_palette(self.folder / 'normal.pal')
        self.assertEqual(len(palette), 16)
        self.assertEqual(palette[0], (255, 0, 255))
        for view in result['views']:
            side = view['side']
            self.assertEqual(view['indices'], self.config['default'][side]['indices'])
            self.assertEqual(view['layout']['offset'], self.config['default'][side]['offset'])
            self.assertTrue(view['manual_selection'])
            source, _ = selector.load_animation(self.repo / self.sources[side])
            w, h = view['layout']['frame_size']
            with Image.open(self.folder / view['filename']) as strip:
                self.assertEqual(strip.size, (w, h * selector.SIDES[side]))
                self.assertEqual(strip.mode, 'P')
                self.assertEqual(strip.info.get('transparency'), 0)
                self.assertLess(strip.getextrema()[1], 16)
                self.assertEqual(strip.getpalette()[:48], [value for rgb in palette for value in rgb])
                for slot, original_index in enumerate(view['indices']):
                    expected = Image.new('RGBA', (w, h), (0, 0, 0, 0))
                    expected.paste(source[original_index], tuple(view['layout']['translation']))
                    actual = strip.crop((0, slot * h, w, (slot + 1) * h)).convert('RGBA')
                    expected_pixels, actual_pixels = np.array(expected), np.array(actual)
                    self.assertTrue(np.array_equal(expected_pixels[..., 3], actual_pixels[..., 3]))
                    opaque = expected_pixels[..., 3] > 0
                    self.assertTrue(np.array_equal(expected_pixels[opaque], actual_pixels[opaque]))
        self.assertEqual(original.read_bytes(), before)
        self.assertFalse(list(self.folder.glob('*shiny*')))
        self.assertEqual(result['animation']['front']['special'], [0, 3, 4, 0])
        self.assertNotIn('special', result['animation']['back'])
        validation = selector.validate([result], [self.entry])
        self.assertTrue(validation['ok'], validation)
        self.assertEqual(validation['checked_views'], 2)

    def test_manual_palette_order_reindexes_both_views_without_recoloring(self):
        first = self.build()
        old_palette = selector.read_palette(self.folder / 'normal.pal')
        before = {}
        for view in first['views']:
            with Image.open(self.folder / view['filename']) as image:
                before[view['filename']] = image.convert('RGBA').tobytes()
        config = deepcopy(self.config)
        config['palette_order'] = [0, *range(15, 0, -1)]
        result = self.build(config=config)
        self.assertEqual(selector.read_palette(self.folder / 'normal.pal'),
                         [old_palette[i] for i in config['palette_order']])
        for view in result['views']:
            with Image.open(self.folder / view['filename']) as image:
                self.assertEqual(image.convert('RGBA').tobytes(), before[view['filename']])
        self.assertTrue(selector.validate([result], [self.entry])['ok'])

    def test_female_exports_shared_back_in_its_own_palette(self):
        entry = deepcopy(self.entry)
        entry['variants'].append({
            'key': 'female', **self.sources, 'front_output': 'anim_frontf.png',
            'back_output': 'backf.png', 'back_shared_with_default': True,
        })
        config = deepcopy(self.config)
        config['female'] = {'front': {'indices': [0, 1, 2, 5, 6]}}
        result = self.build(entry, config)
        self.assertEqual(result['shared_views'], {'female.back': 'default.back'})
        self.assertEqual(len(result['views']), 4)
        self.assertTrue((self.folder / 'backf.png').exists())
        self.assertEqual((self.folder / 'normalf.pal').read_bytes(),
                         (self.folder / 'normal.pal').read_bytes())
        self.assertTrue(selector.validate([result], [entry])['ok'])

    def test_female_palette_can_differ_from_default(self):
        entry = deepcopy(self.entry)
        entry['variants'].append({
            'key': 'female', **self.sources, 'front_output': 'anim_frontf.png',
            'back_output': 'backf.png',
        })
        config = deepcopy(self.config)
        config['female'] = {'front': {'indices': [0, 1, 2, 5, 6]}}
        config['palette_order_female'] = [0, *range(15, 0, -1)]
        result = self.build(entry, config)
        self.assertNotEqual((self.folder / 'normalf.pal').read_bytes(),
                            (self.folder / 'normal.pal').read_bytes())
        self.assertTrue(selector.validate([result], [entry])['ok'])

    def test_regeneration_retires_artifacts_for_a_removed_variant(self):
        config = deepcopy(self.config)
        config['female'] = {side: {'source': source} for side, source in self.sources.items()}
        self.build(config=config, sheets=True)
        self.assertTrue((self.folder / 'anim_frontf.png').exists())
        (self.folder / 'mis_notas.txt').write_text('Conservar mi revisión.\n')
        result = self.build()
        for name in ('anim_frontf.png', 'backf.png', 'normalf.pal', 'anim_frontf_source.png',
                     'backf_preview.gif', 'anim_frontf_selected.png'):
            self.assertFalse((self.folder / name).exists(), name)
        self.assertEqual((self.folder / 'mis_notas.txt').read_text(), 'Conservar mi revisión.\n')
        self.assertTrue(selector.validate([result], [self.entry])['ok'])

    def test_validation_rejects_manifest_with_truncated_frame_selection(self):
        result = self.build()
        result['views'][0]['indices'].pop()
        validation = selector.validate([result], [self.entry])
        self.assertFalse(validation['ok'], 'Debe comprobar los cinco índices además de la altura PNG.')

    def test_failed_regeneration_preserves_previous_successful_export(self):
        self.build(sheets=True)
        before = {p.relative_to(self.folder): p.read_bytes()
                  for p in self.folder.rglob('*') if p.is_file()}
        config = deepcopy(self.config)
        config['palette_order'] = [0, *range(15, 0, -1)]
        # Fallo posterior a la creación de paleta y tira en el área temporal.
        with patch.object(selector, 'save_preview', side_effect=OSError('Fallo de escritura simulado')):
            with self.assertRaisesRegex(OSError, 'simulado'):
                self.build(config=config)
        after = {p.relative_to(self.folder): p.read_bytes()
                 for p in self.folder.rglob('*') if p.is_file()}
        self.assertEqual(after, before)

    def test_existing_source_sheet_is_updated_when_override_changes_source(self):
        self.build(sheets=True)
        sheet = self.folder / 'anim_front_source.png'
        original = sheet.read_bytes()
        config = deepcopy(self.config)
        config['default']['front']['source'] = self.sources['back']
        self.build(config=config, sheets=False)
        self.assertNotEqual(sheet.read_bytes(), original,
                            'Una hoja antigua no debe seguir mostrando la fuente anterior.')

    def test_verify_only_detects_requested_missing_species_and_scopes_report(self):
        self.build()
        second = deepcopy(self.entry)
        second.update(species='IVYSAUR', national_id=2, output_dir='ivysaur')
        for names, status, unbuilt in ((['BULBASAUR'], 0, []),
                                       (['BULBASAUR', 'IVYSAUR'], 1, ['IVYSAUR'])):
            with self.subTest(names=names), \
                    patch.object(selector, 'build_catalog', return_value=[self.entry, second]), \
                    patch('sys.argv', ['selector.py', 'verify', '--only', *names]), \
                    redirect_stdout(io.StringIO()):
                with self.assertRaises(SystemExit) as error:
                    selector.main()
                self.assertEqual(error.exception.code, status)
                validation = json.loads((self.here / 'validation.json').read_text())
                self.assertEqual(validation['unbuilt_species'], unbuilt)

    def test_cli_refuses_species_outside_whitelist_before_writing(self):
        overrides = self.here / 'overrides.json'
        overrides.write_text(json.dumps({'species': {'CHARIZARD': {}}}))
        cases = [
            ['selector.py', 'build', '--only', 'CHARIZARD', '--overrides', str(overrides)],
            ['selector.py', 'build', '--overrides', str(overrides)],
        ]
        for argv in cases:
            with self.subTest(argv=argv), patch.object(selector, 'build_catalog', return_value=[self.entry]), \
                    patch('sys.argv', argv), redirect_stderr(io.StringIO()), redirect_stdout(io.StringIO()):
                with self.assertRaises(SystemExit) as error:
                    selector.main()
                self.assertEqual(error.exception.code, 2)
        self.assertFalse((self.here / 'pokemon').exists())


if __name__ == '__main__':
    unittest.main()

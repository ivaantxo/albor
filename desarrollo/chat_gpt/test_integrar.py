"""La integracion cambia solo datos visuales completos y conserva los originales."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from PIL import Image

import integrar


class IntegrationTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        self.repo = Path(temporary.name)
        self.here = self.repo / 'desarrollo/chat_gpt'
        self.folder = self.here / 'pokemon/bulbasaur'
        self.folder.mkdir(parents=True)
        data = self.repo / 'src/data/pokemon'
        data.mkdir(parents=True)
        self.original = data / 'species_info.h'
        self.original.write_text('''const struct SpeciesInfo gSpeciesInfo[] = {
    [SPECIES_BULBASAUR] = {
        PS(45),
        FRONT_PIC(Bulbasaur, 64, 64),
        FRONT_ANIM(Bulbasaur, V_SLIDE),
        ELEVACION_FRONT_PIC(12),
        BACK_PIC(Bulbasaur, 64, 64),
        PALETAS(Bulbasaur),
        ELEVACION_COMO_ENEMIGO(5),
    },
};
''')
        (data / 'animaciones_pokemon.h').write_text('// Tablas originales\n')
        (self.repo / 'species.txt').write_text('SPECIES_BULBASAUR\n')
        self.entry = {'species': 'BULBASAUR', 'output_dir': 'bulbasaur',
                      'variants': [{'key': 'default'}, {'key': 'female'}]}
        self.selection = {'species': 'BULBASAUR', 'views': [], 'missing_views': []}
        for variant in ('default', 'female'):
            suffix = 'f' if variant == 'female' else ''
            (self.folder / f'normal{suffix}.pal').write_text('paleta distinta ' + variant)
            for side, stem, count in [('front', 'anim_front', 5), ('back', 'back', 3)]:
                filename = f'{stem}{suffix}.png'
                Image.new('P', (64, 64 * count)).save(self.folder / filename, bits=4)
                self.selection['views'].append({
                    'variant': variant, 'side': side, 'filename': filename,
                    'layout': {'frame_size': [64, 64], 'source_bbox': [10, 10, 40, 44]},
                    'timing': {'mode': 'manual', 'sequence': [{'frame': 0, 'ticks': 12},
                                                             {'frame': count-1, 'ticks': 6}]},
                })
        patcher = patch.object(integrar, 'build_catalog', return_value=[self.entry])
        patcher.start()
        self.addCleanup(patcher.stop)

    def generate(self):
        (self.folder / 'selection.json').write_text(json.dumps(self.selection))
        return integrar.generate(self.repo, self.here)

    def test_shared_timing_distinct_gender_art_and_visible_sizes(self):
        original = self.original.read_bytes()
        report = self.generate()
        self.assertEqual(len(report['active']), 1)
        source = (self.here / 'generated/species_info_bw.h').read_text()
        for code in ['PS(45)', 'ELEVACION_COMO_ENEMIGO(5)',
                     'FRONT_PIC(BW_BULBASAUR, 32, 40)',
                     'FRONT_PIC_HEMBRA(BW_BULBASAUR, 32, 40)',
                     'BACK_PIC_HEMBRA(BW_BULBASAUR, 32, 40)',
                     'PALETAS_HEMBRA(BW_BULBASAUR)', 'ANIM_ESPALDA(BW_BULBASAUR)',
                     'ELEVACION_FRONT_PIC(0)']:
            self.assertIn(code, source)
        graphics = (self.here / 'generated/graphics_bw.h').read_text()
        self.assertIn('anim_frontf.4bpp.lz', graphics)
        self.assertIn('normalf.gbapal', graphics)
        self.assertNotIn('shinyf.gbapal', graphics)
        self.assertEqual(self.original.read_bytes(), original)
        self.assertFalse(list(self.folder.glob('shiny*')))
        self.assertEqual(report['active'][0]['shiny_uses_normal'], ['default', 'female'])
        animations = (self.here / 'generated/animaciones_bw.h').read_text()
        self.assertIn('POSE_DURANTE(4, 6)', animations)
        self.assertIn('ESPALDA(BW_BULBASAUR)', animations)

    def test_manual_shiny_is_used_without_rewriting_it(self):
        shiny = self.folder / 'shinyf.pal'
        shiny.write_text('paleta shiny del usuario')
        self.generate()
        graphics = (self.here / 'generated/graphics_bw.h').read_text()
        self.assertIn('shinyf.gbapal', graphics)
        self.assertEqual(shiny.read_text(), 'paleta shiny del usuario')

    def test_incomplete_gender_cannot_silently_fall_back_to_new_male_palette(self):
        self.selection['views'].pop()
        with self.assertRaisesRegex(ValueError, 'No hay especies integrables'):
            self.generate()
        self.assertFalse((self.here / 'generated').exists())

    def test_exceptional_view_is_rejected_as_a_whole_species(self):
        self.selection['views'][-1]['layout']['frame_size'] = [112, 112]
        with self.assertRaisesRegex(ValueError, 'No hay especies integrables'):
            self.generate()

    def test_modified_strip_cannot_invalidate_game_frame_stride(self):
        Image.new('P', (80, 80*4)).save(self.folder / 'anim_front.png', bits=4)
        with self.assertRaisesRegex(ValueError, 'No hay especies integrables'):
            self.generate()


if __name__ == '__main__':
    unittest.main()

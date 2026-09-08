"""Palette invariants and a regression for teal bodies with teal leaf shadows."""

import unittest
from pathlib import Path

import numpy as np
from PIL import Image

from palette import TRANSPARENT, _lab, build_palette, index_image
from selection import load_animation, select_frames


ROOT = Path(__file__).resolve().parents[2]


def strip(colors):
    pixels = np.array([[[*color, 255] for color in colors] + [[31, 51, 71, 0]]],
                      dtype=np.uint8)
    return Image.fromarray(pixels)


def read_palette(name):
    return [tuple(map(int, row.split())) for row in
            (ROOT / 'graphics/pokemon' / name / 'normal.pal').read_text().splitlines()[3:]]


class PaletteTests(unittest.TestCase):
    def test_shared_indexing_preserves_every_opaque_rgb_and_transparency(self):
        colors = [(12, 23, 34), (60, 95, 80), (220, 60, 90), (245, 250, 255)]
        front, back = strip(colors[:3]), strip(colors[2:])
        palette, metadata = build_palette([front, back])
        self.assertEqual(palette[0], TRANSPARENT)
        self.assertEqual(len(palette), 16)
        self.assertFalse(metadata['quantized'])
        self.assertEqual(metadata['source_opaque_color_count'], 4)
        for frame in (front, back):
            indexed = index_image(frame, palette)
            original, restored = np.asarray(frame), np.asarray(indexed.convert('RGBA'))
            visible = original[:, :, 3] > 0
            np.testing.assert_array_equal(original[visible], restored[visible])
            np.testing.assert_array_equal(restored[:, :, 3], original[:, :, 3])
            self.assertTrue(np.all(np.asarray(indexed)[visible] > 0))
            self.assertEqual(indexed.info['transparency'], 0)

    def test_joint_reduction_uses_source_colors_is_deterministic_and_no_dither(self):
        colors = [(i * 11 % 256, i * 47 % 256, i * 83 % 256) for i in range(30)]
        front, back = strip(colors[:20]), strip(colors[10:])
        palette, metadata = build_palette([front, back])
        again, _ = build_palette([back, front])
        self.assertEqual(palette, again)
        self.assertTrue(metadata['quantized'])
        self.assertEqual(metadata['source_opaque_color_count'], 30)
        self.assertEqual(metadata['opaque_palette_color_count'], 15)
        self.assertTrue(set(palette[1:]).issubset(colors))
        self.assertGreater(metadata['changed_opaque_pixels'], 0)
        for color in colors:
            flat = Image.new('RGBA', (8, 8), (*color, 255))
            self.assertEqual(len(np.unique(np.asarray(index_image(flat, palette)))), 1)

    def test_reference_rgb_never_replaces_source_values(self):
        colors = [(16, 65, 74), (32, 148, 131), (90, 205, 189), (131, 230, 213)]
        reference = read_palette('ivysaur')
        palette, metadata = build_palette([strip(colors)], reference,
                                          read_palette('bulbasaur'))
        self.assertEqual(set(palette[1:]) - {TRANSPARENT}, set(colors))
        self.assertEqual(palette[1:5], colors)
        self.assertEqual(metadata['species_reference_grouped_colors'], 4)

    def test_real_family_keeps_leaf_shadows_out_of_body_ramp(self):
        expected_body = {
            'bulbasaur': [(24, 74, 74), (49, 115, 115), (57, 148, 148),
                          (98, 213, 180), (131, 238, 197)],
            'ivysaur': [(16, 65, 74), (32, 148, 131), (90, 205, 189), (131, 230, 213)],
            'venusaur': [(16, 123, 106), (32, 180, 156), (90, 213, 197)],
        }
        family_reference = read_palette('bulbasaur')
        for number, name in enumerate(expected_body, 1):
            with self.subTest(species=name):
                selected = []
                for view, count in [('f', 5), ('b', 3)]:
                    frames, durations = load_animation(ROOT / 'desarrollo/.apng_bw' / f'{view}{number:03d}.png')
                    result = select_frames(frames, durations, count)
                    selected.extend(frames[index] for index in result['indices'])
                palette, metadata = build_palette(selected, read_palette(name),
                                                  family_reference if number > 1 else None)
                body = expected_body[name]
                self.assertEqual(palette[1:1 + len(body)], body)
                self.assertFalse(metadata['quantized'])
                self.assertEqual(metadata['species_reference_grouped_colors'],
                                 metadata['source_opaque_color_count'])
                for ramp in metadata['ramps']:
                    lightness = _lab(np.asarray(ramp['colors']))[:, 0]
                    self.assertTrue(np.all(np.diff(lightness) >= 0))
                if name == 'ivysaur':
                    self.assertEqual(palette[6:10], [(16, 74, 57), (49, 123, 82),
                                                    (98, 172, 90), (123, 213, 115)])
                if name == 'venusaur':
                    leaves = next(ramp for ramp in metadata['ramps']
                                  if [16, 82, 65] in ramp['colors'])
                    self.assertEqual(leaves['ordering_reference'], 'family')
                    self.assertEqual(leaves['preferred_start_index'], 6)
                for frame in selected:
                    original = np.asarray(frame)
                    restored = np.asarray(index_image(frame, palette).convert('RGBA'))
                    visible = original[:, :, 3] > 0
                    np.testing.assert_array_equal(original[visible], restored[visible])

    def test_empty_frames_report_clear_error(self):
        with self.assertRaisesRegex(ValueError, 'at least one frame'):
            build_palette([])
        with self.assertRaisesRegex(ValueError, 'fully transparent'):
            build_palette([Image.new('RGBA', (8, 8))])


if __name__ == '__main__':
    unittest.main()

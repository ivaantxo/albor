"""Behavioral checks for APNG-to-AnimCmd duration and motion preservation."""

import math
import unittest

from PIL import Image, ImageDraw

from timing import animcmd_lines, build_timing


def view(labels, indices, durations=None, loop_end=4, special_range=None):
    count = len(labels)
    special = {'detected': special_range is not None, 'range': special_range}
    if special_range:
        special.update(novelty_threshold=.1,
                       novelty=[1 if special_range[0] <= index <= special_range[1] else 0
                                for index in range(count)])
    return {
        'side': 'front' if len(indices) == 5 else 'back',
        'indices': indices,
        'source_durations_ms': durations or [100] * count,
        'automatic_selection': {'metrics': {
            'pose_labels': labels,
            'loop': {'detected': True, 'indices': list(range(loop_end)),
                     'end_exclusive': loop_end},
            'special': special,
        }},
    }


class TimingTests(unittest.TestCase):
    def test_short_wing_cycle_cannot_hide_selected_body_motion(self):
        source = view([0, 1, 0, 1, 2, 3, 2, 3, 4, 5, 4, 5, 0, 1],
                      [4, 1, 8], loop_end=2)
        result = build_timing(source)
        self.assertEqual({s['frame'] for s in result['sequence']}, {0, 1, 2})
        self.assertEqual(result['loop_ticks'], 12 * 6)
        self.assertTrue(any('ampliado' in warning for warning in result['warnings']))

    def test_discarded_intermediate_images_still_contribute_elapsed_time(self):
        result = build_timing(view([0, 4, 1, 5, 0, 6, 2, 7], [0, 2, 6], loop_end=8))
        self.assertEqual(result['cycle_ticks'], 48)  # All eight 100 ms source intervals.
        self.assertGreater(result['cycle_ticks'], 3 * 6)
        self.assertEqual({step['frame'] for step in result['sequence']}, {0, 1, 2})
        self.assertEqual(result['sequence'][0]['frame'], 0)

    def test_returns_to_a_pose_are_kept_in_chronological_order(self):
        result = build_timing(view([0, 1, 0, 2] * 3, [0, 1, 3]))
        self.assertEqual(result['loop'], [
            {'frame': 0, 'ticks': 6}, {'frame': 1, 'ticks': 6},
            {'frame': 0, 'ticks': 6}, {'frame': 2, 'ticks': 6},
        ])
        self.assertEqual(result['sequence'], result['loop'])

    def test_slot_order_does_not_replace_source_order(self):
        result = build_timing(view([1, 0, 2, 0], [1, 0, 2]))
        self.assertEqual([step['frame'] for step in result['loop']], [0, 2, 0, 1])

    def test_front_keeps_variable_holds_repeated_idle_and_special(self):
        labels = [0, 1, 0, 2] * 3 + [0, 3, 4, 3, 0]
        durations = [100] * len(labels)
        durations[8] = 500
        durations[14] = 1700
        result = build_timing(view(labels, [0, 1, 3, 13, 14], durations,
                                   special_range=[13, 15]))
        self.assertEqual(result['mode'], 'source_timeline')
        self.assertEqual(result['cycle_ticks'], round(sum(durations) * 60 / 1000))
        self.assertEqual(result['idle_cycles_before_special'], 3)
        self.assertIn({'frame': 4, 'ticks': 102}, result['sequence'])
        self.assertEqual([step['frame'] for step in result['sequence']][-4:], [3, 4, 3, 0])
        self.assertNotEqual(result['cycle_ticks'], result['loop_ticks'] * 3 + result['special_ticks'])

    def test_rounding_conserves_total_instead_of_accumulating_per_frame_error(self):
        labels = [0, 1, 0, 2] * 7 + [3, 4]
        durations = [23.4] * len(labels)
        result = build_timing(view(labels, [0, 1, 3, 28, 29], durations,
                                   special_range=[28, 29]))
        self.assertEqual(result['cycle_ticks'], math.floor(sum(durations) * .06 + .5))
        self.assertNotEqual(result['cycle_ticks'], len(durations) * round(23.4 * .06))
        self.assertTrue(all(step['ticks'] > 0 for step in result['sequence']))

    def test_cadence_override_uses_representative_blocks(self):
        source = view([0, 1, 0, 2] * 3 + [3, 4], [0, 1, 3, 12, 13], special_range=[12, 13])
        result = build_timing(source, idle_cycles_before_special=5)
        self.assertEqual(result['mode'], 'custom_cadence')
        self.assertEqual(result['cycle_ticks'], 5 * result['loop_ticks'] + result['special_ticks'])
        self.assertEqual(result['idle_cycles_before_special'], 5)

    def test_missing_independent_gesture_is_reported_as_synthetic(self):
        source = view([0, 1, 3, 0, 2, 4] * 3, [0, 1, 4, 2, 5], loop_end=6)
        result = build_timing(source)
        self.assertEqual(result['mode'], 'synthetic_special_cadence')
        self.assertTrue(result['warnings'])
        self.assertEqual(result['idle_cycles_before_special'], 4)
        self.assertEqual({step['frame'] for step in result['sequence']}, set(range(5)))

    def test_visual_projection_uses_closest_shape_for_removed_pose(self):
        frames = []
        for width in (3, 4, 10, 3, 15):
            frame = Image.new('RGBA', (24, 24))
            ImageDraw.Draw(frame).rectangle((2, 5, 2 + width, 15), fill=(50, 160, 90, 255))
            frames.append(frame)
        source = view([0, 3, 1, 0, 2], [0, 2, 4], loop_end=5)
        result = build_timing(source, frames)
        self.assertEqual(result['method'], 'nearest_visual_pose')
        self.assertEqual(result['loop'][0], {'frame': 0, 'ticks': 12})
        self.assertEqual(result['cycle_ticks'], 30)

    def test_invalid_input_does_not_generate_a_misleading_script(self):
        for durations in ([0, 100, 100, 100], [float('nan')] * 4):
            with self.assertRaises(ValueError):
                build_timing(view([0, 1, 0, 2], [0, 1, 3], durations))
        with self.assertRaises(ValueError):
            build_timing(view([0, 1, 0, 2], [0, 1, 999]))
        with self.assertRaises(ValueError):
            build_timing(view([0, 1, 0, 2], [0, 1, 3]), idle_cycles_before_special=-1)

    def test_macro_output_can_loop_or_finish_for_battle_entry(self):
        timing = build_timing(view([0, 1, 0, 2], [0, 1, 3]))
        self.assertEqual(animcmd_lines(timing)[0], 'POSE_DURANTE(0, 6),')
        self.assertEqual(animcmd_lines(timing)[-1], 'VUELTA_AL_PRINCIPIO,')
        self.assertEqual(animcmd_lines(timing, end=True)[-1], 'TERMINA,')


if __name__ == '__main__':
    unittest.main()

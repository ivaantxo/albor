"""Focused checks for frame selection and native APNG composition."""

import tempfile
import unittest
from pathlib import Path

from PIL import Image, ImageDraw

from selection import load_animation, select_frames


def pose(y=8, special=0):
    frame = Image.new("RGBA", (32, 32))
    draw = ImageDraw.Draw(frame)
    draw.rectangle((10, y, 21, y + 12), fill=(50, 160, 100, 255))
    if special:
        draw.rectangle((3 if special == 1 else 23, y + 3,
                        8 if special == 1 else 28, y + 9), fill=(220, 80, 30, 255))
    return frame


class SelectionTests(unittest.TestCase):
    def test_recurring_motion_and_separate_chronological_special(self):
        cycle = [pose(8), pose(6), pose(8), pose(10)]
        frames = cycle * 4 + [pose(8, 1), pose(8, 2)] + cycle
        original = [frame.tobytes() for frame in frames]
        result = select_frames(frames, [100] * len(frames), 5)
        self.assertTrue(result["metrics"]["loop"]["detected"])
        self.assertEqual(result["selected_unique_count"], 5)
        self.assertEqual(result["indices"][3:], [16, 17])
        displacement = result["metrics"]["motion"]["displacements"]
        self.assertLess(displacement[1], 0)
        self.assertGreater(displacement[2], 0)
        self.assertEqual(original, [frame.tobytes() for frame in frames])

    def test_back_avoids_later_special(self):
        cycle = [pose(8), pose(6), pose(8), pose(10)]
        frames = cycle * 3 + [pose(8, 1), pose(8, 2)]
        result = select_frames(frames, [100] * len(frames), 3)
        self.assertEqual(len(result["indices"]), 3)
        self.assertTrue(all(index < 4 for index in result["indices"]))

    def test_base_uses_available_two_sided_motion_despite_first_pose_bias(self):
        cycle = []
        for width in (2, 0, 10, 24):
            frame = pose()
            if width:
                ImageDraw.Draw(frame).rectangle(
                    (16 - width // 2, 21, 15 + width // 2, 21),
                    fill=(50, 160, 100, 255))
            cycle.append(frame)
        frames = cycle * 4
        result = select_frames(frames, [100] * len(frames), 3)
        displacement = result["metrics"]["motion"]["displacements"]
        self.assertLess(displacement[1], -.1)
        self.assertGreater(displacement[2], .1)
        self.assertFalse(any("opuestos" in warning for warning in result["warnings"]))

    def test_small_cycle_variants_are_not_selected_as_the_special(self):
        frames = []
        for cycle in range(4):
            for y in (8, 5, 8, 11):
                frame = pose(y)
                x = cycle * 6 + 1
                ImageDraw.Draw(frame).rectangle((x, 1, x + 1, 2),
                                                fill=(200, 60, 10, 255))
                frames.append(frame)
        frames.extend((pose(8, 1), pose(8, 2)))
        result = select_frames(frames, [100] * len(frames), 5)
        self.assertEqual(result["metrics"]["loop"].get("method"), "approximate")
        self.assertEqual(result["indices"][3:], [16, 17])

    def test_final_special_pose_is_the_gesture_peak_before_returning(self):
        cycle = [pose(8), pose(6), pose(8), pose(10)]
        preparation = pose(8, 1)
        peak = pose(8)
        ImageDraw.Draw(peak).rectangle((1, 10, 8, 20), fill=(220, 80, 30, 255))
        returning = pose(8)
        ImageDraw.Draw(returning).rectangle((23, 16, 26, 20), fill=(220, 80, 30, 255))
        frames = cycle * 4 + [preparation, peak, returning] + cycle
        result = select_frames(frames, [100] * len(frames), 5)
        self.assertEqual(result["indices"][3:], [16, 17])

    def test_static_source_keeps_count_and_reports_limitation(self):
        result = select_frames([pose()] * 8, [100] * 8, 5)
        self.assertEqual(result["indices"], [0] * 5)
        self.assertEqual(result["unique_count"], 1)
        self.assertTrue(result["warnings"])
        self.assertFalse(result["metrics"]["special"]["detected"])

    def test_uniform_cycle_does_not_claim_special(self):
        frames = [pose(8), pose(6), pose(8), pose(10)] * 4
        result = select_frames(frames, [100] * len(frames), 5)
        self.assertFalse(result["metrics"]["special"]["detected"])
        self.assertTrue(any("especial separado" in warning for warning in result["warnings"]))

    def test_apng_decoding_retains_offsets_and_durations(self):
        frames = [pose(8), pose(6), pose(10)]
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "native.png"
            frames[0].save(path, save_all=True, append_images=frames[1:],
                           duration=[100, 200, 300], loop=0)
            loaded, durations = load_animation(path)
        self.assertEqual([frame.size for frame in loaded], [(32, 32)] * 3)
        self.assertEqual([frame.getbbox() for frame in loaded],
                         [frame.getbbox() for frame in frames])
        self.assertEqual(durations, [100, 200, 300])

    def test_apng_nonanimated_default_image_is_excluded(self):
        frames = [pose(8), pose(6), pose(10)]
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "with_poster.png"
            pose(8, 1).save(path, save_all=True, append_images=frames,
                            default_image=True, duration=[100, 200, 300], loop=0)
            loaded, durations = load_animation(path)
        self.assertEqual([frame.tobytes() for frame in loaded],
                         [frame.tobytes() for frame in frames])
        self.assertEqual(durations, [100, 200, 300])

    def test_magenta_is_transparent_and_invisible_colours_do_not_create_poses(self):
        first = Image.new("RGBA", (16, 16), (255, 0, 255, 255))
        second = Image.new("RGBA", (16, 16), (10, 20, 30, 0))
        result = select_frames([first, second], [100, 100], 3)
        self.assertEqual(result["unique_count"], 1)


if __name__ == "__main__":
    unittest.main()

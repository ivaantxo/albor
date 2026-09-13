"""Native strips must retain identity, poses, offsets and palette colors."""

from pathlib import Path
import tempfile
import unittest

from PIL import Image

from legacy_sources import infer_frame_layout, load_legacy_animation, supplement_catalog


class LegacySourceTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.repo = Path(self.temporary.name)

    def strip(self, filename="graphics/pokemon/example/anim_frontf.png", frames=4):
        path = self.repo / filename
        path.parent.mkdir(parents=True, exist_ok=True)
        # Legacy index zero is not necessarily magenta, and magenta is not
        # necessarily at index zero.  Both should become transparent.
        sprite = Image.new("P", (64, 64 * frames), 0)
        sprite.putpalette([20, 100, 10, 220, 60, 130, 255, 0, 255] + [0] * (768 - 9))
        for n in range(frames):
            sprite.putpixel((10 + n, 8 + n + 64 * n), 1)
            sprite.putpixel((0, n * 64), 2)
        sprite.save(path)
        return path

    def test_indexed_strip_retains_each_pose_and_relative_positions(self):
        path = self.strip()
        original = path.read_bytes()
        frames, durations, metadata = load_legacy_animation(path, "front")
        self.assertEqual(len(frames), 4)
        self.assertEqual([frame.size for frame in frames], [(64, 64)] * 4)
        self.assertEqual(durations, [100.0] * 4)
        self.assertEqual(metadata["source_palette"][1], [220, 60, 130])
        self.assertEqual(metadata["unique_count"], 4)
        for n, frame in enumerate(frames):
            self.assertEqual(frame.getpixel((10 + n, 8 + n)), (220, 60, 130, 255))
            self.assertEqual(frame.getpixel((0, 0))[3], 0)
            self.assertEqual(frame.getpixel((1, 0))[3], 0)
        self.assertEqual(path.read_bytes(), original)

    def test_single_pose_stays_one_pose_and_reports_static_source(self):
        frames, durations, metadata = load_legacy_animation(self.strip(frames=1), "back")
        self.assertEqual(len(frames), 1)
        self.assertEqual(metadata["unique_count"], 1)
        self.assertTrue(any("estático" in warning for warning in metadata["warnings"]))

    def test_uses_png_canvas_and_rejects_bbox_as_strip_height(self):
        self.assertEqual(infer_frame_layout((96, 384))["frame_count"], 4)
        self.assertEqual(infer_frame_layout((64, 128))["frame_size"], [64, 64])
        with self.assertRaises(ValueError):
            infer_frame_layout((64, 128), [64, 56])
        with self.assertRaises(ValueError):
            infer_frame_layout((128, 64))
        self.assertEqual(infer_frame_layout((128, 64), 64)["frame_count"], 2)

    def test_explicit_timing_and_validation(self):
        path = self.strip(frames=2)
        _, durations, metadata = load_legacy_animation(path, "front", frame_durations_ms=[120, 240])
        self.assertEqual(durations, [120, 240])
        self.assertEqual(metadata["timing_kind"], "provided_pose_durations")
        with self.assertRaises(ValueError):
            load_legacy_animation(path, "front", frame_durations_ms=[120])
        with self.assertRaises(ValueError):
            load_legacy_animation(path, "front", frame_durations_ms=[120, float("nan")])

    def test_apng_is_not_silently_read_as_a_single_native_pose(self):
        path = self.repo / "animation.png"
        a = Image.new("RGBA", (64, 64), "red")
        b = Image.new("RGBA", (64, 64), "blue")
        a.save(path, save_all=True, append_images=[b], duration=100)
        with self.assertRaises(ValueError):
            load_legacy_animation(path, "front")

    def test_female_identity_shared_side_and_whitelist_are_preserved(self):
        female = self.strip()
        default = self.strip("graphics/pokemon/example/anim_front.png")
        back = self.strip("graphics/pokemon/example/back.png", frames=1)
        entries = [{"species": "EXAMPLE", "variants": [
            {"key": "default", "front": "desarrollo/.apng_bw/f001.png", "back": None,
             "original_front": str(default.relative_to(self.repo)),
             "original_back": str(back.relative_to(self.repo))},
            {"key": "female", "front": None, "back": None,
             "original_front": str(female.relative_to(self.repo)),
             "original_back": str(back.relative_to(self.repo))},
        ]}]
        result = supplement_catalog(entries, self.repo)
        male, female_result = result[0]["variants"]
        self.assertEqual(male["front_source_type"], "apng")
        self.assertEqual(female_result["front"], str(female.relative_to(self.repo)))
        self.assertEqual(female_result["front_source_type"], "legacy_strip")
        self.assertFalse(female_result["front_shared_with_default"])
        self.assertEqual(female_result["back"], male["back"])
        self.assertTrue(female_result["back_shared_with_default"])
        self.assertEqual(female_result["palette_output"], "normalf.pal")
        self.assertIsNone(entries[0]["variants"][1]["front"])
        self.assertEqual([e["species"] for e in result], ["EXAMPLE"])

    def test_missing_distinct_female_is_not_replaced_with_male(self):
        self.strip("graphics/pokemon/example/anim_front.png")
        result = supplement_catalog([{"species": "EXAMPLE", "variants": [
            {"key": "default", "front": "desarrollo/.apng_bw/f001.png", "back": None,
             "original_front": "graphics/pokemon/example/anim_front.png"},
            {"key": "female", "front": None, "back": None,
             "original_front": "graphics/pokemon/example/anim_frontf.png"},
        ]}], self.repo)
        self.assertIsNone(result[0]["variants"][1]["front"])

    def test_existing_female_png_wins_over_accidental_symbol_alias(self):
        male_back = self.strip("graphics/pokemon/example/back.png", frames=1)
        female_back = self.strip("graphics/pokemon/example/backf.png", frames=1)
        original = str(male_back.relative_to(self.repo))
        result = supplement_catalog([{"species": "EXAMPLE", "output_dir": "example", "variants": [
            {"key": "default", "front": None, "back": "desarrollo/.apng_bw/b001.png",
             "original_back": original},
            {"key": "female", "front": None, "back": None,
             "original_back": original},
        ]}], self.repo)
        female = result[0]["variants"][1]
        self.assertEqual(female["back"], str(female_back.relative_to(self.repo)))
        self.assertEqual(female["original_game_back"], original)
        self.assertFalse(female["back_shared_with_default"])


if __name__ == "__main__":
    unittest.main()

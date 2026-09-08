"""Invariantes de lienzo y posiciones que no debe romper una selección manual."""
import unittest

import numpy as np
from PIL import Image, ImageDraw

from selector import place_frames


def sprite(size, box):
    frame = Image.new('RGBA', size, (0, 0, 0, 0))
    ImageDraw.Draw(frame).rectangle(box, fill=(12, 100, 200, 255))
    return frame


class LayoutTests(unittest.TestCase):
    def test_relative_horizontal_and_vertical_motion_survives(self):
        frames = [sprite((90, 90), (30, 30, 49, 49)), sprite((90, 90), (32, 27, 51, 46)),
                  sprite((90, 90), (28, 33, 47, 52))]
        placed, metadata = place_frames(frames, {})
        boxes = [im.getchannel('A').getbbox() for im in placed]
        self.assertEqual(metadata['frame_size'], [64, 64])
        self.assertEqual(boxes[1][0] - boxes[0][0], 2)
        self.assertEqual(boxes[1][1] - boxes[0][1], -3)
        self.assertEqual(boxes[2][0] - boxes[0][0], -2)
        self.assertEqual(boxes[2][1] - boxes[0][1], 3)
        self.assertEqual(max(box[3] for box in boxes), 64)
        self.assertEqual(min(box[0] for box in boxes), 64 - max(box[2] for box in boxes))

    def test_only_transparent_margins_are_removed(self):
        frames = [sprite((120, 120), (5, 5, 77, 65))]
        placed, metadata = place_frames(frames, {})
        self.assertEqual(metadata['frame_size'], [80, 80])
        self.assertEqual(np.count_nonzero(np.asarray(frames[0])[:, :, 3]),
                         np.count_nonzero(np.asarray(placed[0])[:, :, 3]))

    def test_exception_keeps_native_rectangle_and_coordinates(self):
        frame = sprite((127, 113), (6, 9, 109, 103))
        placed, metadata = place_frames([frame], {})
        self.assertTrue(metadata['exceptional_size'])
        self.assertEqual(placed[0].size, (127, 113))
        self.assertEqual(placed[0].tobytes(), frame.tobytes())
        self.assertEqual(metadata['translation'], [0, 0])

    def test_manual_offset_cannot_clip_any_frame(self):
        frames = [sprite((64, 64), (5, 10, 30, 40)), sprite((64, 64), (5, 12, 30, 42))]
        with self.assertRaisesRegex(ValueError, 'recortaría'):
            place_frames(frames, {'offset': [0, 1]})
        placed, _ = place_frames(frames, {'offset': [0, -5]})
        self.assertEqual(max(im.getchannel('A').getbbox()[3] for im in placed), 59)

    def test_manual_size_cannot_shrink_drawing(self):
        frame = sprite((100, 100), (10, 10, 88, 80))
        with self.assertRaises(ValueError):
            place_frames([frame], {'size': 64})

    def test_exception_rejects_resizing(self):
        frame = sprite((120, 110), (0, 0, 100, 100))
        with self.assertRaisesRegex(ValueError, 'excepcional'):
            place_frames([frame], {'size': 96})


if __name__ == '__main__':
    unittest.main()

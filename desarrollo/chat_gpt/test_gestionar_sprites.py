"""Pruebas del helper exclusivamente sobre archivos temporales."""
from pathlib import Path
import tempfile
import unittest

from gestionar_sprites import (AUX_NAMES, FINAL_NAMES, apply_cleanup, apply_export,
                              matching_files, plan_export)


class ManageSpritesTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.source = self.root / 'pokemon'
        self.folder = self.source / 'raichu/alola'
        self.folder.mkdir(parents=True)
        for name in FINAL_NAMES | AUX_NAMES | {'back_80x80.png', 'notas.txt'}:
            (self.folder / name).write_bytes(name.encode())

    def test_export_preserves_final_bytes_and_subfolders_without_auxiliaries(self):
        destination = self.root / 'testing'
        copies, identical = plan_export(self.source, destination)
        self.assertFalse(destination.exists(), 'Planificar no debe escribir')
        self.assertEqual(identical, 0)
        self.assertEqual({p.name for p, _ in copies}, FINAL_NAMES)
        apply_export(copies)
        self.assertEqual({p.name for p in destination.rglob('*') if p.is_file()}, FINAL_NAMES)
        for name in FINAL_NAMES:
            self.assertEqual((destination / 'raichu/alola' / name).read_bytes(), (self.folder / name).read_bytes())
        self.assertEqual(plan_export(self.source, destination), ([], len(FINAL_NAMES)))

    def test_cleanup_keeps_all_final_gender_files_and_personal_files(self):
        files = matching_files(self.source, AUX_NAMES)
        self.assertTrue((self.folder / 'selection.json').exists())
        apply_cleanup(files)
        self.assertEqual({p.name for p in self.folder.iterdir()}, FINAL_NAMES | {'back_80x80.png', 'notas.txt'})
        with self.assertRaises(ValueError):
            apply_cleanup([self.folder / 'anim_frontf.png'])
        self.assertTrue((self.folder / 'anim_frontf.png').exists())

    def test_conflicting_destination_fails_before_copying_and_requires_explicit_overwrite(self):
        destination = self.root / 'testing'
        target = destination / 'raichu/alola/back.png'
        target.parent.mkdir(parents=True)
        target.write_bytes(b'manual edit')
        with self.assertRaisesRegex(ValueError, 'versión diferente'):
            plan_export(self.source, destination)
        self.assertEqual(list(target.parent.iterdir()), [target])
        copies, _ = plan_export(self.source, destination, overwrite=True)
        self.assertTrue(any(p == target.resolve() for _, p in copies))
        self.assertEqual(target.read_bytes(), b'manual edit', 'Planificar no debe sobrescribir')

    def test_folder_filter_and_source_overlap(self):
        self.assertEqual(matching_files(self.source, AUX_NAMES, {'bulbasaur'}), [])
        self.assertEqual(len(matching_files(self.source, FINAL_NAMES, {'raichu/alola'})), len(FINAL_NAMES))
        for destination in (self.source, self.source / 'testing', self.root):
            with self.assertRaises(ValueError):
                plan_export(self.source, destination)


if __name__ == '__main__':
    unittest.main()

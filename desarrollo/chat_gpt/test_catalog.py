"""Catalogue identity and missing-source guardrails, using isolated fixtures."""

import base64
import json
from pathlib import Path
import tempfile
import unittest

from catalog import audit_sources, build_catalog


class CatalogTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory(prefix="bw-catalog-test-")
        self.addCleanup(self.temporary.cleanup)
        self.repo = Path(self.temporary.name)
        self.source = self.repo / "desarrollo/.apng_bw"
        self.source.mkdir(parents=True)
        self.write("species.txt", """
enum Species {
    SPECIES_NONE,
    SPECIES_PICHU,
    SPECIES_PIKACHU,
    SPECIES_RAICHU_ALOLA,
    SPECIES_BULBASAUR,
    SPECIES_IVYSAUR,
    SPECIES_VENUSAUR,
    SPECIES_DEOXYS_NORMAL,
    SPECIES_DEOXYS_ATTACK,
    SPECIES_NIDORAN_F,
    SPECIES_MR_MIME,
    SPECIES_ODDISH,
    SPECIES_GLOOM,
    SPECIES_BELLOSSOM,
    /* SPECIES_CHARIZARD, */
    // SPECIES_SQUIRTLE,
    SPECIES_EGG,
    NUM_SPECIES
};
""")
        self.write("tools/importador_bw/nombres_nacionales.json", json.dumps({
            1: "bulbasaur", 2: "ivysaur", 3: "venusaur", 6: "charizard",
            25: "pikachu", 26: "raichu", 29: "nidoran_f", 122: "mr_mime",
            172: "pichu", 386: "deoxys", 43: "oddish", 44: "gloom", 182: "bellossom",
        }))
        self.write("src/data/pokemon/species_info.h", """
[SPECIES_PICHU] = {
    FRONT_PIC(Pichu, 64, 64),
    .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_PIKACHU}),
},
[SPECIES_PIKACHU] = {
    FRONT_PIC(Pikachu, 64, 64),
    .evolutions = EVOLUTION({EVO_MAP, 3, SPECIES_RAICHU_ALOLA}),
},
[SPECIES_RAICHU_ALOLA] = { FRONT_PIC(RaichuAlola, 64, 64), },
[SPECIES_BULBASAUR] = {
    FRONT_PIC(Bulbasaur, 64, 64),
    .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_IVYSAUR}),
},
[SPECIES_IVYSAUR] = {
    FRONT_PIC(Ivysaur, 64, 64),
    .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_VENUSAUR}),
},
[SPECIES_VENUSAUR] = {
    FRONT_PIC(Venusaur, 64, 64),
    FRONT_PIC_HEMBRA(Venusaur, 64, 64),
    BACK_PIC(Venusaur, 64, 64),
},
[SPECIES_DEOXYS_NORMAL] = { FRONT_PIC(DeoxysNormal, 64, 64), },
[SPECIES_DEOXYS_ATTACK] = { FRONT_PIC(DeoxysAttack, 64, 64), },
[SPECIES_EGG] = {},
""")
        self.write("src/data/graphics/pokemon.h", "\n".join(
            f'const u32 gMonFrontPic_{name}[] = INCBIN_U32("graphics/pokemon/{directory}/{filename}.4bpp.lz");'
            for name, directory, filename in [
                ("Pichu", "pichu", "anim_front"),
                ("Pikachu", "pikachu", "anim_front"),
                ("RaichuAlola", "raichu/alola", "anim_front"),
                ("Bulbasaur", "bulbasaur", "anim_front"),
                ("Ivysaur", "ivysaur", "anim_front"),
                ("Venusaur", "venusaur", "anim_front"),
                ("VenusaurF", "venusaur", "anim_frontf"),
                ("DeoxysNormal", "deoxys", "anim_front"),
                ("DeoxysAttack", "deoxys/attack", "anim_front"),
            ]))
        for number in (1, 2, 3, 6, 25, 26, 29, 43, 44, 122, 172, 182, 386):
            for side in "fb":
                (self.source / f"{side}{number:03d}.png").touch()

    def write(self, relative, content):
        path = self.repo / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")

    def catalog(self):
        return {entry["species"]: entry for entry in build_catalog(self.repo, self.source)}

    def test_whitelist_and_national_numbers_are_independent_of_enum_order(self):
        entries = self.catalog()
        self.assertNotIn("NONE", entries)
        self.assertNotIn("CHARIZARD", entries)
        self.assertNotIn("SQUIRTLE", entries)
        self.assertIn("EGG", entries)
        self.assertIsNone(entries["EGG"]["national_id"])
        self.assertEqual(entries["PICHU"]["national_id"], 172)
        self.assertTrue(entries["PICHU"]["variants"][0]["front"].endswith("f172.png"))
        self.assertEqual(entries["NIDORAN_F"]["national_id"], 29)
        self.assertEqual(entries["NIDORAN_F"]["output_dir"], "nidoran_f")
        self.assertEqual(entries["MR_MIME"]["output_dir"], "mr_mime")

    def test_base_sources_do_not_fill_regional_or_alternate_forms(self):
        entries = self.catalog()
        for species in ("RAICHU_ALOLA", "DEOXYS_ATTACK"):
            for side in ("front", "back"):
                self.assertIsNone(entries[species]["variants"][0][side])
        self.assertEqual(entries["RAICHU_ALOLA"]["output_dir"], "raichu/alola")
        self.assertEqual(entries["DEOXYS_ATTACK"]["output_dir"], "deoxys/attack")
        self.assertEqual(entries["DEOXYS_NORMAL"]["output_dir"], "deoxys")
        self.assertTrue(entries["DEOXYS_NORMAL"]["variants"][0]["front"].endswith("f386.png"))

    def test_missing_female_view_is_not_disguised_with_male_art(self):
        variants = self.catalog()["VENUSAUR"]["variants"]
        female = next(v for v in variants if v["key"] == "female")
        self.assertIsNone(female["front"])
        self.assertFalse(female["front_shared_with_default"])
        self.assertEqual(female["front_output"], "anim_frontf.png")
        # The fixture genuinely shares its back; there is no female back asset
        # or female BACK_PIC macro. Such reuse is explicit, not a substitution.
        self.assertTrue(female["back"].endswith("b003.png"))
        self.assertTrue(female["back_shared_with_default"])
        self.assertEqual(female["status"], "missing_source")
        self.write("graphics/pokemon/venusaur/backf.png", "fixture")
        female = next(v for v in self.catalog()["VENUSAUR"]["variants"] if v["key"] == "female")
        self.assertIsNone(female["back"])
        self.assertFalse(female["back_shared_with_default"])

    def test_explicit_form_and_gender_files_resolve_to_their_own_identity(self):
        for name in ("f026_alola.png", "b026_alola.png", "f003_f.png", "b003_f.png"):
            (self.source / name).touch()
        entries = self.catalog()
        alola = entries["RAICHU_ALOLA"]["variants"][0]
        self.assertEqual(alola["status"], "available")
        self.assertTrue(alola["front"].endswith("f026_alola.png"))
        female = next(v for v in entries["VENUSAUR"]["variants"] if v["key"] == "female")
        self.assertEqual(female["status"], "available")
        self.assertTrue(female["front"].endswith("f003_f.png"))
        self.assertTrue(female["back"].endswith("b003_f.png"))
        self.assertFalse(female["back_shared_with_default"])

    def test_evolution_families_include_branches_forms_and_missing_data(self):
        entries = self.catalog()
        for group in (("PICHU", "PIKACHU", "RAICHU_ALOLA"),
                      ("BULBASAUR", "IVYSAUR", "VENUSAUR"),
                      ("DEOXYS_NORMAL", "DEOXYS_ATTACK"),
                      ("ODDISH", "GLOOM", "BELLOSSOM")):
            with self.subTest(group=group):
                self.assertEqual(len({entries[s]["family"] for s in group}), 1)
        self.assertNotEqual(entries["PICHU"]["family"], entries["BULBASAUR"]["family"])

    def test_catalog_is_read_only_and_output_directories_are_unique(self):
        snapshot = {p.relative_to(self.repo): p.read_bytes() for p in self.repo.rglob("*") if p.is_file()}
        entries = self.catalog()
        after = {p.relative_to(self.repo): p.read_bytes() for p in self.repo.rglob("*") if p.is_file()}
        self.assertEqual(snapshot, after)
        self.assertEqual(len(entries), len({e["output_dir"] for e in entries.values()}))

    def test_audit_reports_invalid_files_and_byte_identical_duplicates(self):
        clean = self.repo / "audit_fixture"
        clean.mkdir()
        png = base64.b64decode("iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAQAAAC1HAwCAAAAC0lEQVR42mP8/x8AAwMCAO+j2ioAAAAASUVORK5CYII=")
        (clean / "f001.png").write_bytes(png)
        (clean / "copy.png").write_bytes(png)
        (clean / "f493.png").touch()
        (clean / "truncated.png").write_bytes(png[:20])
        audit = audit_sources(clean)
        self.assertEqual(audit["png_files"], 4)
        self.assertEqual(audit["byte_identical_duplicates"], 1)
        invalid = [r for r in audit["files"] if "error" in r]
        self.assertEqual([r["file"] for r in invalid], ["f493.png", "truncated.png"])


if __name__ == "__main__":
    unittest.main()

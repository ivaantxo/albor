"""Read-only species, graphics and APNG catalogue for the BW frame selector.

The project enum is an evolution-oriented order, NOT National Pokédex order.
Only species explicitly present in species.txt are returned.  Missing forms and
female artwork remain missing: a base/male APNG is never disguised as one.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from collections import Counter
from pathlib import Path


# The existing local national-name table stops at 493.  These explicit National
# Pokédex numbers extend it only for later species requested by this project.
LATER_NATIONAL_IDS = {
    "SANDILE": 551, "KROKOROK": 552, "KROOKODILE": 553,
    "YAMASK": 562, "COFAGRIGUS": 563,
    "GOTHITA": 574, "GOTHORITA": 575, "GOTHITELLE": 576,
    "FRILLISH": 592, "JELLICENT": 593, "JOLTIK": 595, "GALVANTULA": 596,
    "FERROSEED": 597, "FERROTHORN": 598,
    "LITWICK": 607, "LAMPENT": 608, "CHANDELURE": 609,
    "AXEW": 610, "FRAXURE": 611, "HAXORUS": 612,
    "CUBCHOO": 613, "BEARTIC": 614, "GOLETT": 622, "GOLURK": 623,
    "PAWNIARD": 624, "BISHARP": 625,
    "DEINO": 633, "ZWEILOUS": 634, "HYDREIGON": 635,
    "LARVESTA": 636, "VOLCARONA": 637,
    "FENNEKIN": 653, "BRAIXEN": 654, "DELPHOX": 655,
    "FLETCHLING": 661, "FLETCHINDER": 662, "TALONFLAME": 663,
    "TYRUNT": 696, "TYRANTRUM": 697, "AMAURA": 698, "AURORUS": 699,
    "SYLVEON": 700, "ROWLET": 722, "DARTRIX": 723, "DECIDUEYE": 724,
    "JANGMO_O": 782, "HAKAMO_O": 783, "KOMMO_O": 784,
    "ROOKIDEE": 821, "CORVISQUIRE": 822, "CORVIKNIGHT": 823,
    "BLIPBUG": 824, "DOTTLER": 825, "ORBEETLE": 826,
    "SNOM": 872, "FROSMOTH": 873,
    "DREEPY": 885, "DRAKLOAK": 886, "DRAGAPULT": 887,
    "WYRDEER": 899, "KLEAVOR": 900, "SNEASLER": 903,
    "ANNIHILAPE": 979,
}

FORM_SUFFIXES = {
    "RAICHU_ALOLA": ("RAICHU", "ALOLA"),
    "SANDSHREW_ALOLA": ("SANDSHREW", "ALOLA"),
    "SANDSLASH_ALOLA": ("SANDSLASH", "ALOLA"),
    "VULPIX_ALOLA": ("VULPIX", "ALOLA"),
    "NINETALES_ALOLA": ("NINETALES", "ALOLA"),
    "GROWLITHE_HISUI": ("GROWLITHE", "HISUI"),
    "ARCANINE_HISUI": ("ARCANINE", "HISUI"),
    "MAROWAK_ALOLA": ("MAROWAK", "ALOLA"),
    "WEEZING_GALAR": ("WEEZING", "GALAR"),
    **{f"CASTFORM_{f}": ("CASTFORM", f) for f in ("SUNNY", "RAINY", "SNOWY")},
    **{f"DEOXYS_{f}": ("DEOXYS", f) for f in ("NORMAL", "ATTACK", "DEFENSE", "SPEED")},
    **{f"ROTOM_{f}": ("ROTOM", f) for f in ("HEAT", "WASH", "FROST", "FAN", "MOW")},
}

# Some requested species have no SpeciesInfo block yet.  Keep their established
# evolutionary families together for palette-slot ordering.  These are family
# memberships, not replacement evolution rules for the game. Sneasler belongs
# to the wider Sneasel family through the Hisuian form, absent from species.txt.
FAMILY_SUPPLEMENTS = (
    ("SPEAROW", "FEAROW"),
    ("ODDISH", "GLOOM", "VILEPLUME", "BELLOSSOM"),
    ("GROWLITHE_HISUI", "ARCANINE_HISUI"),
    ("SLOWPOKE", "SLOWBRO", "SLOWKING"),
    ("DODUO", "DODRIO"),
    ("SPOINK", "GRUMPIG"),
    ("SANDILE", "KROKOROK", "KROOKODILE"),
    ("GOTHITA", "GOTHORITA", "GOTHITELLE"),
    ("GOLETT", "GOLURK"),
    ("SNEASEL", "WEAVILE", "SNEASLER"),
)


def _without_comments(text: str) -> str:
    return re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)


def requested_species(repo: Path) -> list[str]:
    """Keep EGG as an auditable missing entry; NONE is only an enum sentinel."""
    text = _without_comments((repo / "species.txt").read_text(encoding="utf-8"))
    return list(dict.fromkeys(s for s in re.findall(r"\bSPECIES_([A-Z0-9_]+)\b", text)
                              if s != "NONE"))


def _relative(path: Path, repo: Path) -> str:
    try:
        return path.relative_to(repo).as_posix()
    except ValueError:
        return path.as_posix()


def _species_blocks(repo: Path) -> dict[str, str]:
    text = _without_comments((repo / "src/data/pokemon/species_info.h").read_text(encoding="utf-8"))
    starts = list(re.finditer(r"\[SPECIES_([A-Z0-9_]+)\]\s*=\s*\{", text))
    return {m.group(1): text[m.end(): starts[i + 1].start() if i + 1 < len(starts) else len(text)]
            for i, m in enumerate(starts)}


def _graphics_symbols(repo: Path) -> dict[str, str]:
    text = _without_comments((repo / "src/data/graphics/pokemon.h").read_text(encoding="utf-8"))
    result = {}
    for symbol, path in re.findall(r'(gMon(?:FrontPic|BackPic|Palette)_\w+)\s*\[\]\s*=\s*INCBIN_\w+\("([^"]+)"\)', text):
        if "Pic_" in symbol:
            path = re.sub(r"\.4bpp(?:\.lz)?$", ".png", path)
        else:
            path = re.sub(r"\.gbapal(?:\.lz)?$", ".pal", path)
        result[symbol] = path
    return result


def _macro_symbol(body: str, macro: str, prefix: str, female: bool = False) -> str | None:
    match = re.search(r"\b" + macro + r"\s*\(\s*(\w+)", body)
    if match:
        return prefix + match.group(1) + ("F" if female else "")
    return None


def _families(species: list[str], blocks: dict[str, str]) -> dict[str, str]:
    parent = {s: s for s in species}
    order = {s: i for i, s in enumerate(species)}

    def root(s: str) -> str:
        while parent[s] != s:
            parent[s] = parent[parent[s]]
            s = parent[s]
        return s

    def join(a: str, b: str) -> None:
        if a not in parent or b not in parent:
            return
        a, b = root(a), root(b)
        if order[a] > order[b]:
            a, b = b, a
        parent[b] = a

    for s in species:
        body = blocks.get(s, "")
        # All evolution targets live after .evolutions.  This does not confuse
        # sprite symbols, cries or the game's separately numbered dex entries.
        match = re.search(r"\.evolutions\s*=\s*EVOLUTION\(", body)
        if match:
            depth, end = 1, match.end()
            while end < len(body) and depth:
                depth += (body[end] == "(") - (body[end] == ")")
                end += 1
            for target in re.findall(r"\bSPECIES_([A-Z0-9_]+)\b", body[match.end():end]):
                join(s, target)
        if s in FORM_SUFFIXES:
            base, _ = FORM_SUFFIXES[s]
            # Deoxys' normal form uses its own enum name in this project.
            join(s, "DEOXYS_NORMAL" if base == "DEOXYS" else base)
    for family in FAMILY_SUPPLEMENTS:
        for member in family[1:]:
            join(family[0], member)
    return {s: root(s).lower() for s in species}


def _source_candidates(source: Path, number: int | None, species: str,
                       side: str, female: bool) -> list[Path]:
    """Named files permit later additions without silently borrowing base forms.

    Examples: f026_alola.png, b026_alola.png, f003_f.png, b003_f.png.
    Species names such as f_raichu_alola.png are also unambiguous.
    """
    marker = "f" if side == "front" else "b"
    gender = "_f" if female else ""
    candidates = [source / f"{marker}_{species.lower()}{gender}.png"]
    if number is None:
        return candidates
    _, form = FORM_SUFFIXES.get(species, (species, None))
    form = None if form == "NORMAL" and species == "DEOXYS_NORMAL" else form
    form_suffix = f"_{form.lower()}" if form else ""
    candidates += [source / f"{marker}{number:03d}{form_suffix}{gender}.png"]
    if not female:
        candidates += [source / f"{marker}{number:03d}{form_suffix}_m.png"]
    # Bulbagarden names encode non-default forms differently; support only
    # explicit names whose identity is unambiguous here, never guess their form.
    if form is None:
        bulb = f"Spr_{'b_' if side == 'back' else ''}5b_{number:03d}"
        candidates += [source / f"{bulb}{gender}.png"]
        if not female:
            candidates += [source / f"{bulb}_m.png"]
    return candidates


def build_catalog(repo: Path, source: Path) -> list[dict]:
    """Return one JSON-serializable record per requested species, including gaps.

    Source paths and original_* reference paths are relative to repo (absolute
    if the source is outside it). output_dir is relative to the generated
    pokemon/ directory. *_output names are relative to that species directory.
    """
    repo, source = Path(repo).resolve(), Path(source).resolve()
    species = requested_species(repo)
    national_path = repo / "tools/importador_bw/nombres_nacionales.json"
    names = json.loads(national_path.read_text(encoding="utf-8"))
    national = {v.upper().replace("-", "_"): int(k) for k, v in names.items()}
    national.update(LATER_NATIONAL_IDS)
    blocks, symbols = _species_blocks(repo), _graphics_symbols(repo)
    families = _families(species, blocks)
    result = []

    for s in species:
        base, form = FORM_SUFFIXES.get(s, (s, None))
        number = national.get(base)
        body = blocks.get(s, "")
        default_front = symbols.get(_macro_symbol(body, "FRONT_PIC", "gMonFrontPic_"))
        default_back = symbols.get(_macro_symbol(body, "BACK_PIC", "gMonBackPic_"))
        default_palette = symbols.get(_macro_symbol(body, "PALETAS", "gMonPalette_"))
        if default_front:
            output_dir = Path(default_front).parent.relative_to("graphics/pokemon").as_posix()
        elif form:
            output_dir = base.lower() + ("/" + form.lower() if form != "NORMAL" else "")
        else:
            output_dir = s.lower()
        graphics_dir = repo / "graphics/pokemon" / output_dir
        default_front = default_front or _relative(graphics_dir / "anim_front.png", repo)
        default_back = default_back or _relative(graphics_dir / "back.png", repo)
        default_palette = default_palette or _relative(graphics_dir / "normal.pal", repo)
        warnings = []
        if s not in blocks:
            warnings.append("La especie no tiene bloque de datos en species_info.h.")
        if number is None:
            warnings.append("Sin número nacional; EGG no es una especie de la Pokédex." if s == "EGG"
                            else "No hay un número nacional conocido para esta especie.")

        female_front = symbols.get(_macro_symbol(body, "FRONT_PIC_HEMBRA", "gMonFrontPic_", True))
        female_back = symbols.get(_macro_symbol(body, "BACK_PIC_HEMBRA", "gMonBackPic_", True))
        female_palette = symbols.get(_macro_symbol(body, "PALETAS_HEMBRA", "gMonPalette_", True))
        # Include actual gender-specific assets even if the species table does
        # not currently hook them into the game.
        if (graphics_dir / "anim_frontf.png").is_file():
            female_front = female_front or _relative(graphics_dir / "anim_frontf.png", repo)
        if (graphics_dir / "backf.png").is_file():
            female_back = female_back or _relative(graphics_dir / "backf.png", repo)
        if (graphics_dir / "normalf.pal").is_file():
            female_palette = female_palette or _relative(graphics_dir / "normalf.pal", repo)
        source_female = any(p.is_file() for side in ("front", "back")
                            for p in _source_candidates(source, number, s, side, True))
        genders = [False, True] if female_front or female_back or source_female else [False]
        variants = []
        for female in genders:
            variant = {
                "key": "female" if female else "default",
                "front_output": "anim_frontf.png" if female else "anim_front.png",
                "back_output": "backf.png" if female else "back.png",
                "palette_output": Path(female_palette if female and female_palette else default_palette).name,
                "original_front": female_front if female and female_front else default_front,
                "original_back": female_back if female and female_back else default_back,
                "original_palette": female_palette if female and female_palette else default_palette,
                "warnings": [],
            }
            for side in ("front", "back"):
                candidates = _source_candidates(source, number, s, side, female)
                found = next((p for p in candidates if p.is_file()), None)
                shared = False
                female_original = female_front if side == "front" else female_back
                # A view genuinely shared by genders in the project's graphics
                # can use its default source. A distinct but absent female view
                # cannot. The explicit shared flag makes this reviewable.
                if female and found is None and not female_original:
                    base_candidates = _source_candidates(source, number, s, side, False)
                    found = next((p for p in base_candidates if p.is_file()), None)
                    shared = found is not None
                variant[side] = _relative(found, repo) if found else None
                variant[f"{side}_shared_with_default"] = shared
                if found is None:
                    kind = "hembra" if female else ("forma " + form.lower() if form and form != "NORMAL" else "base")
                    variant["warnings"].append(f"Falta APNG {side} de {kind} en la carpeta de origen.")
            variant["status"] = "available" if variant["front"] and variant["back"] else "missing_source"
            variants.append(variant)

        result.append({
            "species": s,
            "national_id": number,
            "output_dir": output_dir,
            "family": families[s],
            "variants": variants,
            "warnings": warnings,
        })
    return result


def audit_sources(source: Path) -> dict:
    """Audit PNG headers and duplicates without loading pixels or using network."""
    source = Path(source).resolve()
    records, hashes, numbered = [], {}, {"front": set(), "back": set()}
    for path in sorted(source.glob("*.png")):
        data = path.read_bytes()
        digest = hashlib.sha256(data).hexdigest()
        record = {"file": path.name, "sha256": digest, "bytes": len(data)}
        if data[:8] != b"\x89PNG\r\n\x1a\n":
            record["error"] = "Invalid PNG signature"
        elif len(data) < 33 or data[12:16] != b"IHDR":
            record["error"] = "Invalid or truncated PNG IHDR"
        else:
            record["width"], record["height"] = struct.unpack(">II", data[16:24])
            record["frames"] = 1
            position = 8
            while position + 12 <= len(data):
                size = struct.unpack(">I", data[position:position + 4])[0]
                chunk = data[position + 4:position + 8]
                if position + size + 12 > len(data):
                    record["error"] = "Truncated PNG chunk"
                    break
                if chunk == b"acTL":
                    if size != 8:
                        record["error"] = "Invalid APNG acTL chunk"
                        break
                    record["frames"], record["plays"] = struct.unpack(">II", data[position + 8:position + 16])
                    break
                position += size + 12
        if digest in hashes:
            record["identical_to"] = hashes[digest]
        else:
            hashes[digest] = path.name
        match = re.fullmatch(r"([bf])(\d+)\.png", path.name)
        if match:
            numbered["front" if match.group(1) == "f" else "back"].add(int(match.group(2)))
        records.append(record)
    return {
        "png_files": len(records),
        "animated_png_files": sum(r.get("frames", 1) > 1 for r in records),
        "byte_identical_duplicates": sum("identical_to" in r for r in records),
        "numbered_fronts": sorted(numbered["front"]),
        "numbered_backs": sorted(numbered["back"]),
        "files": records,
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--source", type=Path)
    parser.add_argument("--json", type=Path, help="Write full catalogue JSON to this path")
    parser.add_argument("--audit", type=Path, help="Write detailed source audit JSON to this path")
    args = parser.parse_args()
    source = args.source or args.repo / "desarrollo/.apng_bw"
    records = build_catalog(args.repo, source)
    if args.json:
        args.json.write_text(json.dumps(records, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if args.audit:
        args.audit.write_text(json.dumps(audit_sources(source), ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    variants = [v for s in records for v in s["variants"]]
    print(json.dumps({"requested_entries": len(records),
                      "requested_pokemon": sum(s["species"] != "EGG" for s in records),
                      "default_status": dict(Counter(s["variants"][0]["status"] for s in records)),
                      "variant_status": dict(Counter(v["status"] for v in variants)),
                      "female_variants": sum(v["key"] == "female" for v in variants)}, indent=2))


if __name__ == "__main__":
    main()

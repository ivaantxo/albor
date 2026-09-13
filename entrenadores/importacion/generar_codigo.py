"""Generate C registration fragments from the normalized trainer catalog.

Public API: generar(entries) writes the generated headers and returns their paths.
Importing this module has no side effects. The importer owns the images and the
call sites that include these files; this module only writes generated headers.

Each entry has id, directory, has_front, has_ow, front_frames, ow_frames and
east_mirrored. Files are <directory>/<id>.gbapal, front.4bpp.lz and ow.4bpp.
OW frames use S0/S1/S2, N0/N1/N2, W0/W1/W2, optionally E0/E1/E2.
"""

from pathlib import Path, PurePosixPath
import re


ROOT = Path(__file__).resolve().parents[2]
NOTICE = "// Generado por entrenadores/importacion/generar_codigo.py. No editar a mano.\n"


def _guard(path, text):
    guard = "GUARD_" + re.sub(r"[^A-Z0-9]", "_", path.upper())
    return f"{NOTICE}#ifndef {guard}\n#define {guard}\n\n{text.rstrip()}\n\n#endif // {guard}\n"


def _fragment(context, lines):
    return NOTICE + f"// Incluir {context}.\n\n" + "\n".join(lines) + "\n"


def _validate(entries):
    result = []
    seen = set()
    for original in entries:
        entry = dict(original)
        slug = entry["id"]
        if not re.fullmatch(r"[a-z][a-z0-9_]*", slug):
            raise ValueError(f"Identificador C inválido: {slug!r}")
        if slug in seen:
            raise ValueError(f"Identificador de entrenador repetido: {slug}")
        seen.add(slug)
        path = PurePosixPath(entry["directory"])
        if path.is_absolute() or ".." in path.parts or not str(path).startswith("graphics/entrenadores/"):
            raise ValueError(f"Directorio de entrenador inválido: {path}")
        if not re.fullmatch(r"[a-zA-Z0-9_./-]+", str(path)):
            raise ValueError(f"Directorio no representable en INCBIN: {path}")
        entry["directory"] = str(path)
        entry["has_front"] = bool(entry["has_front"])
        entry["has_ow"] = bool(entry["has_ow"])
        entry["front_frames"] = int(entry.get("front_frames", 0))
        entry["ow_frames"] = int(entry.get("ow_frames", 0))
        entry["east_mirrored"] = bool(entry.get("east_mirrored", False))
        if entry["has_front"] and not 1 <= entry["front_frames"] <= 20:
            raise ValueError(f"{slug}: número de frames front fuera de 1..20 (límite u16 de frontPic.size)")
        if entry["has_ow"]:
            if entry["ow_frames"] not in (9, 12):
                raise ValueError(f"{slug}: OW debe tener 9 o 12 frames")
            if entry["east_mirrored"] != (entry["ow_frames"] == 9):
                raise ValueError(f"{slug}: east_mirrored y ow_frames no coinciden")
        result.append(entry)
    return sorted(result, key=lambda entry: entry["id"])


def _front_graphics(entries):
    lines = [
        '#include "pic_combate.h"',
        "",
        "// Una única definición de paleta por entrenador; combate y OW la comparten.",
    ]
    for entry in entries:
        slug, directory = entry["id"], entry["directory"]
        lines.append(f'const u16 gPaletaEntrenador_{slug}[] = INCBIN_U16("{directory}/{slug}.gbapal");')
        if entry["has_front"]:
            lines.append(f'const u32 gTrainerFrontPic_Importado_{slug}[] = INCBIN_U32("{directory}/front.4bpp.lz");')
        lines.append("")

    counts = sorted({entry["front_frames"] for entry in entries if entry["has_front"]})
    if counts:
        lines.extend([
            "// Índices usados por TrainerSprite.animation: reposo, entrada, reposo.",
            "static const union AnimCmd sAnim_EntrenadorImportadoReposo[] =",
            "{", "    ANIMCMD_FRAME(0, 1),", "    ANIMCMD_END,", "};", "",
        ])
    for count in counts:
        entry_symbol = "sAnim_EntrenadorImportadoReposo"
        if count > 1:
            entry_symbol = f"sAnim_EntrenadorImportadoEntrada{count}"
            lines.extend([f"static const union AnimCmd {entry_symbol}[] =", "{"])
            for frame in range(count):
                duration = 24 if frame == count - 1 else 12
                lines.append(f"    ANIMCMD_FRAME({frame}, {duration}),")
            lines.extend(["    ANIMCMD_FRAME(0, 1),", "    ANIMCMD_END,", "};", ""])
        lines.extend([
            f"static const union AnimCmd *const sAnimTable_EntrenadorImportado{count}[] =",
            "{",
            "    sAnim_EntrenadorImportadoReposo,",
            f"    {entry_symbol},",
            "    sAnim_EntrenadorImportadoReposo,",
            "};", "",
        ])
    return "\n".join(lines)


def _front_registrations(entries):
    lines = []
    for entry in entries:
        if not entry["has_front"]:
            continue
        slug, constant, count = entry["id"], entry["id"].upper(), entry["front_frames"]
        lines.extend([
            f"    [TRAINER_PIC_{constant}] =",
            "    {",
            f"        .frontPic = {{gTrainerFrontPic_Importado_{slug}, PIC_80_BYTES * {count}, TRAINER_PIC_{constant}}},",
            f"        .palette = {{gPaletaEntrenador_{slug}, TRAINER_PIC_{constant}}},",
            f"        .animation = sAnimTable_EntrenadorImportado{count},",
            "        .mugshotCoords = {0, 0},",
            "        .mugshotRotation = 512,",
            "        .bytesPorFotograma = PIC_80_BYTES,",
            "    },",
        ])
    return _fragment("dentro de gTrainerSprites[]", lines)


def _ow_animations(entries):
    variants = sorted({entry["ow_frames"] for entry in entries if entry["has_ow"]})
    if not variants:
        return []
    modes = [("FACE", "Face", None), ("GO", "Go", 8), ("GO_FAST", "GoFast", 4), ("GO_FASTER", "GoFaster", 2), ("GO_FASTEST", "GoFastest", 1)]
    directions = [("SOUTH", "South", 0), ("NORTH", "North", 3), ("WEST", "West", 6)]
    for variant in variants:
        directions.append(("EAST", f"East{variant}", 6 if variant == 9 else 9))
    lines = [
        "// Orden canónico de cada dirección: reposo, paso A, paso B.",
        "// Las velocidades y los veinte índices mantienen el contrato ANIM_STD_*.",
    ]
    for _, mode, duration in modes:
        for _, direction, base in directions:
            flip = ", .hFlip = TRUE" if direction == "East9" else ""
            lines.extend([f"static const union AnimCmd sAnim_OWEntrenadorImportado_{mode}{direction}[] =", "{"])
            if duration is None:
                lines.append(f"    ANIMCMD_FRAME({base}, 16{flip}),")
            else:
                for frame in (base + 1, base, base + 2, base):
                    lines.append(f"    ANIMCMD_FRAME({frame}, {duration}{flip}),")
            lines.extend(["    ANIMCMD_JUMP(0),", "};", ""])
    for variant in variants:
        lines.extend([f"static const union AnimCmd *const sAnimTable_OWEntrenadoresImportados{variant}[] =", "{"])
        for mode_constant, mode, _ in modes:
            for direction_constant, direction in [("SOUTH", "South"), ("NORTH", "North"), ("WEST", "West"), ("EAST", f"East{variant}")]:
                lines.append(f"    [ANIM_STD_{mode_constant}_{direction_constant}] = sAnim_OWEntrenadorImportado_{mode}{direction},")
        lines.extend(["};", ""])
    return lines


def _ow_graphics(entries):
    lines = [
        "// Incluir después de base_oam.h y object_event_subsprites.h.",
        "// Las paletas se definen una sola vez en graphics/entrenadores_importados.h.",
        "",
    ]
    lines.extend(_ow_animations(entries))
    for entry in entries:
        if not entry["has_ow"]:
            continue
        slug, constant, directory = entry["id"], entry["id"].upper(), entry["directory"]
        lines.extend([
            f"extern const u16 gPaletaEntrenador_{slug}[];",
            f'const u32 gObjectEventPic_Importado_{slug}[] = INCBIN_U32("{directory}/ow.4bpp");',
            f"static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_{slug}[] =",
            "{",
            f"    overworld_ascending_frames(gObjectEventPic_Importado_{slug}, 4, 4),",
            "};", "",
            f"const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_{slug} =",
            "{",
            "    .tileTag = TAG_NONE,",
            f"    .paletteTag = OBJ_EVENT_PAL_TAG_{constant},",
            "    .size = 512,",
            "    .width = 32,",
            "    .height = 32,",
            "    .shadowSize = SHADOW_SIZE_M,",
            "    .inanimate = FALSE,",
            "    .compressed = FALSE,",
            "    .tracks = TRACKS_FOOT,",
            "    .oam = &gObjectEventBaseOam_32x32,",
            "    .subspriteTables = sOamTables_32x32,",
            f"    .anims = sAnimTable_OWEntrenadoresImportados{entry['ow_frames']},",
            f"    .images = sPicTable_OWEntrenadorImportado_{slug},",
            "    .affineAnims = gDummySpriteAffineAnimTable,",
            "};", "",
        ])
    return "\n".join(lines)


def _render(entries):
    """Build all output text in memory; useful for checking before any writes."""
    entries = _validate(entries)
    fronts = [entry for entry in entries if entry["has_front"]]
    ows = [entry for entry in entries if entry["has_ow"]]
    generated = {
        "include/constants/trainer_pics_importados.h": _fragment("dentro de enum TrainerPics, antes de TRAINER_PIC_COUNT", [f"    TRAINER_PIC_{entry['id'].upper()}," for entry in fronts]),
        "include/constants/ow_entrenadores_importados.h": _fragment("dentro del enum OBJ_EVENT_GFX_*, antes de NUM_OBJ_EVENT_GFX", [f"    OBJ_EVENT_GFX_{entry['id'].upper()}," for entry in ows]),
        "include/constants/paletas_entrenadores_importadas.h": _fragment("dentro del enum OBJ_EVENT_PAL_TAG_*, antes de su terminador", [f"    OBJ_EVENT_PAL_TAG_{entry['id'].upper()}," for entry in ows]),
        "src/data/graphics/trainer_sprites_importados.h": _front_registrations(entries),
        "src/data/object_events/entrenadores_importados_punteros.h": _fragment("dentro de gObjectEventGraphicsInfoPointers[]", [f"    [OBJ_EVENT_GFX_{entry['id'].upper()}] = &gObjectEventGraphicsInfo_Importado_{entry['id']}," for entry in ows]),
        "src/data/object_events/entrenadores_importados_paletas.h": _fragment("dentro de sObjectEventSpritePalettes[], antes de OBJ_EVENT_PAL_TAG_NONE", [f"    {{gPaletaEntrenador_{entry['id']}, OBJ_EVENT_PAL_TAG_{entry['id'].upper()}}}," for entry in ows]),
    }
    declarations = "\n".join(f"extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_{entry['id']};\nextern const u16 gPaletaEntrenador_{entry['id']}[];" for entry in ows)
    for path, body in [
        ("src/data/graphics/entrenadores_importados.h", _front_graphics(entries)),
        ("src/data/object_events/entrenadores_importados.h", _ow_graphics(entries)),
        ("src/data/object_events/entrenadores_importados_declaraciones.h", declarations),
    ]:
        generated[path] = _guard(path, body)
    return generated


def generar(entries):
    """Write deterministic registration headers; returns repository-relative paths.

    Every entry is validated before any file is written. Constant fragments are
    also expanded into their marked enum blocks: the project's script preproc
    cannot handle an #include inside an enum. Only these generated blocks change.
    """
    generated = _render(entries)
    for relative_path, contents in generated.items():
        destination = ROOT / relative_path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(contents, encoding="utf-8")
    blocks = [
        ("include/constants/trainers.h", "trainer_pics_importados"),
        ("include/constants/event_objects.h", "ow_entrenadores_importados"),
        ("include/constants/event_objects.h", "paletas_entrenadores_importadas"),
    ]
    for target, name in blocks:
        path = ROOT / target
        text = path.read_text()
        start = f"    // BEGIN GENERATED {name}"
        end = f"    // END GENERATED {name}"
        # Keep the standalone fragments as a compact record of imported IDs.
        declarations = "\n".join(line for line in generated[f"include/constants/{name}.h"].splitlines()
                                 if line.startswith("    "))
        block = f"{start}\n{declarations}\n{end}"
        if start in text:
            pattern = re.escape(start) + r".*?" + re.escape(end)
            text, count = re.subn(pattern, lambda _: block, text, flags=re.S)
            if count != 1:
                raise ValueError(f"Bloque generado ambiguo en {target}: {name}")
        else:
            anchor = f'#include "constants/{name}.h"'
            if text.count(anchor) != 1:
                raise ValueError(f"Falta el punto de inserción {name} en {target}")
            text = text.replace(anchor, block)
        path.write_text(text)
    return sorted(generated)

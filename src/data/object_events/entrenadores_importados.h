// Generado por entrenadores/importacion/generar_codigo.py. No editar a mano.
#ifndef GUARD_SRC_DATA_OBJECT_EVENTS_ENTRENADORES_IMPORTADOS_H
#define GUARD_SRC_DATA_OBJECT_EVENTS_ENTRENADORES_IMPORTADOS_H

// Incluir después de base_oam.h y object_event_subsprites.h.
// Las paletas se definen una sola vez en graphics/entrenadores_importados.h.

// Orden canónico de cada dirección: reposo, paso A, paso B.
// Las velocidades y los veinte índices mantienen el contrato ANIM_STD_*.
static const union AnimCmd sAnim_OWEntrenadorImportado_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_FaceNorth[] =
{
    ANIMCMD_FRAME(3, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_FaceWest[] =
{
    ANIMCMD_FRAME(6, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_FaceEast9[] =
{
    ANIMCMD_FRAME(6, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_FaceEast12[] =
{
    ANIMCMD_FRAME(9, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoSouth[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoNorth[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoWest[] =
{
    ANIMCMD_FRAME(7, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoEast9[] =
{
    ANIMCMD_FRAME(7, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoEast12[] =
{
    ANIMCMD_FRAME(10, 8),
    ANIMCMD_FRAME(9, 8),
    ANIMCMD_FRAME(11, 8),
    ANIMCMD_FRAME(9, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastSouth[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastWest[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastEast9[] =
{
    ANIMCMD_FRAME(7, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastEast12[] =
{
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFasterSouth[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFasterNorth[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFasterWest[] =
{
    ANIMCMD_FRAME(7, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFasterEast9[] =
{
    ANIMCMD_FRAME(7, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFasterEast12[] =
{
    ANIMCMD_FRAME(10, 2),
    ANIMCMD_FRAME(9, 2),
    ANIMCMD_FRAME(11, 2),
    ANIMCMD_FRAME(9, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastestSouth[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastestNorth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastestWest[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastestEast9[] =
{
    ANIMCMD_FRAME(7, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_OWEntrenadorImportado_GoFastestEast12[] =
{
    ANIMCMD_FRAME(10, 1),
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_FRAME(11, 1),
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_OWEntrenadoresImportados9[] =
{
    [ANIM_STD_FACE_SOUTH] = sAnim_OWEntrenadorImportado_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_OWEntrenadorImportado_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_OWEntrenadorImportado_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_OWEntrenadorImportado_FaceEast9,
    [ANIM_STD_GO_SOUTH] = sAnim_OWEntrenadorImportado_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_OWEntrenadorImportado_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_OWEntrenadorImportado_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_OWEntrenadorImportado_GoEast9,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_OWEntrenadorImportado_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_OWEntrenadorImportado_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_OWEntrenadorImportado_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_OWEntrenadorImportado_GoFastEast9,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_OWEntrenadorImportado_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_OWEntrenadorImportado_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_OWEntrenadorImportado_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_OWEntrenadorImportado_GoFasterEast9,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_OWEntrenadorImportado_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_OWEntrenadorImportado_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_OWEntrenadorImportado_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_OWEntrenadorImportado_GoFastestEast9,
};

static const union AnimCmd *const sAnimTable_OWEntrenadoresImportados12[] =
{
    [ANIM_STD_FACE_SOUTH] = sAnim_OWEntrenadorImportado_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_OWEntrenadorImportado_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_OWEntrenadorImportado_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_OWEntrenadorImportado_FaceEast12,
    [ANIM_STD_GO_SOUTH] = sAnim_OWEntrenadorImportado_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_OWEntrenadorImportado_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_OWEntrenadorImportado_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_OWEntrenadorImportado_GoEast12,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_OWEntrenadorImportado_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_OWEntrenadorImportado_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_OWEntrenadorImportado_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_OWEntrenadorImportado_GoFastEast12,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_OWEntrenadorImportado_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_OWEntrenadorImportado_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_OWEntrenadorImportado_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_OWEntrenadorImportado_GoFasterEast12,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_OWEntrenadorImportado_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_OWEntrenadorImportado_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_OWEntrenadorImportado_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_OWEntrenadorImportado_GoFastestEast12,
};

extern const u16 gPaletaEntrenador_aaron_platinum[];
const u32 gObjectEventPic_Importado_aaron_platinum[] = INCBIN_U32("graphics/entrenadores/aaron_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_aaron_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_aaron_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_aaron_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_AARON_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_aaron_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_f_hgss[];
const u32 gObjectEventPic_Importado_ace_trainer_f_hgss[] = INCBIN_U32("graphics/entrenadores/ace_trainer_f_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_f_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_f_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_f_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_F_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_f_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_f_platinum[];
const u32 gObjectEventPic_Importado_ace_trainer_f_platinum[] = INCBIN_U32("graphics/entrenadores/ace_trainer_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_m_hgss[];
const u32 gObjectEventPic_Importado_ace_trainer_m_hgss[] = INCBIN_U32("graphics/entrenadores/ace_trainer_m_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_m_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_m_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_m_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_M_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_m_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_m_platinum[];
const u32 gObjectEventPic_Importado_ace_trainer_m_platinum[] = INCBIN_U32("graphics/entrenadores/ace_trainer_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_snow_f_platinum[];
const u32 gObjectEventPic_Importado_ace_trainer_snow_f_platinum[] = INCBIN_U32("graphics/entrenadores/ace_trainer_snow_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_snow_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_snow_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_snow_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_SNOW_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_snow_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ace_trainer_snow_m_platinum[];
const u32 gObjectEventPic_Importado_ace_trainer_snow_m_platinum[] = INCBIN_U32("graphics/entrenadores/ace_trainer_snow_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ace_trainer_snow_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ace_trainer_snow_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ace_trainer_snow_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ACE_TRAINER_SNOW_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ace_trainer_snow_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_archer_hgss[];
const u32 gObjectEventPic_Importado_archer_hgss[] = INCBIN_U32("graphics/entrenadores/archer_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_archer_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_archer_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_archer_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ARCHER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_archer_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ariana_hgss[];
const u32 gObjectEventPic_Importado_ariana_hgss[] = INCBIN_U32("graphics/entrenadores/ariana_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ariana_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ariana_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ariana_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ARIANA_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ariana_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_barry_47490[];
const u32 gObjectEventPic_Importado_barry_47490[] = INCBIN_U32("graphics/entrenadores/barry_47490/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_barry_47490[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_barry_47490, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_barry_47490 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BARRY_47490,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_barry_47490,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_barry_platinum[];
const u32 gObjectEventPic_Importado_barry_platinum[] = INCBIN_U32("graphics/entrenadores/barry_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_barry_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_barry_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_barry_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BARRY_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_barry_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_battle_girl_platinum[];
const u32 gObjectEventPic_Importado_battle_girl_platinum[] = INCBIN_U32("graphics/entrenadores/battle_girl_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_battle_girl_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_battle_girl_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_battle_girl_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BATTLE_GIRL_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_battle_girl_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_beauty_hgss[];
const u32 gObjectEventPic_Importado_beauty_hgss[] = INCBIN_U32("graphics/entrenadores/beauty_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_beauty_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_beauty_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_beauty_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BEAUTY_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_beauty_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_beauty_platinum[];
const u32 gObjectEventPic_Importado_beauty_platinum[] = INCBIN_U32("graphics/entrenadores/beauty_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_beauty_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_beauty_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_beauty_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BEAUTY_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_beauty_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_bertha_platinum[];
const u32 gObjectEventPic_Importado_bertha_platinum[] = INCBIN_U32("graphics/entrenadores/bertha_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_bertha_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_bertha_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_bertha_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BERTHA_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_bertha_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_biker_hgss[];
const u32 gObjectEventPic_Importado_biker_hgss[] = INCBIN_U32("graphics/entrenadores/biker_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_biker_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_biker_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_biker_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BIKER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_biker_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_black_belt_hgss[];
const u32 gObjectEventPic_Importado_black_belt_hgss[] = INCBIN_U32("graphics/entrenadores/black_belt_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_black_belt_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_black_belt_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_black_belt_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BLACK_BELT_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_black_belt_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_black_belt_platinum[];
const u32 gObjectEventPic_Importado_black_belt_platinum[] = INCBIN_U32("graphics/entrenadores/black_belt_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_black_belt_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_black_belt_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_black_belt_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BLACK_BELT_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_black_belt_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_blaine_hgss[];
const u32 gObjectEventPic_Importado_blaine_hgss[] = INCBIN_U32("graphics/entrenadores/blaine_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_blaine_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_blaine_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_blaine_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BLAINE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_blaine_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_blue_hgss[];
const u32 gObjectEventPic_Importado_blue_hgss[] = INCBIN_U32("graphics/entrenadores/blue_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_blue_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_blue_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_blue_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BLUE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_blue_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_brock_hgss[];
const u32 gObjectEventPic_Importado_brock_hgss[] = INCBIN_U32("graphics/entrenadores/brock_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_brock_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_brock_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_brock_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BROCK_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_brock_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_bruno_hgss[];
const u32 gObjectEventPic_Importado_bruno_hgss[] = INCBIN_U32("graphics/entrenadores/bruno_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_bruno_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_bruno_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_bruno_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BRUNO_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_bruno_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_buck_platinum[];
const u32 gObjectEventPic_Importado_buck_platinum[] = INCBIN_U32("graphics/entrenadores/buck_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_buck_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_buck_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_buck_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BUCK_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_buck_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_bug_catcher_hgss[];
const u32 gObjectEventPic_Importado_bug_catcher_hgss[] = INCBIN_U32("graphics/entrenadores/bug_catcher_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_bug_catcher_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_bug_catcher_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_bug_catcher_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BUG_CATCHER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_bug_catcher_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_bugsy_hgss[];
const u32 gObjectEventPic_Importado_bugsy_hgss[] = INCBIN_U32("graphics/entrenadores/bugsy_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_bugsy_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_bugsy_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_bugsy_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BUGSY_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_bugsy_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_byron_platinum[];
const u32 gObjectEventPic_Importado_byron_platinum[] = INCBIN_U32("graphics/entrenadores/byron_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_byron_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_byron_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_byron_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_BYRON_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_byron_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cameraman_platinum[];
const u32 gObjectEventPic_Importado_cameraman_platinum[] = INCBIN_U32("graphics/entrenadores/cameraman_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cameraman_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cameraman_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cameraman_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CAMERAMAN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cameraman_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_camper_platinum[];
const u32 gObjectEventPic_Importado_camper_platinum[] = INCBIN_U32("graphics/entrenadores/camper_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_camper_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_camper_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_camper_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CAMPER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_camper_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_candice_platinum[];
const u32 gObjectEventPic_Importado_candice_platinum[] = INCBIN_U32("graphics/entrenadores/candice_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_candice_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_candice_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_candice_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CANDICE_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_candice_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cheryl_platinum[];
const u32 gObjectEventPic_Importado_cheryl_platinum[] = INCBIN_U32("graphics/entrenadores/cheryl_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cheryl_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cheryl_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cheryl_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CHERYL_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cheryl_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_chuck_hgss[];
const u32 gObjectEventPic_Importado_chuck_hgss[] = INCBIN_U32("graphics/entrenadores/chuck_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_chuck_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_chuck_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_chuck_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CHUCK_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_chuck_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_clair_hgss[];
const u32 gObjectEventPic_Importado_clair_hgss[] = INCBIN_U32("graphics/entrenadores/clair_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_clair_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_clair_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_clair_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CLAIR_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_clair_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_clown_platinum[];
const u32 gObjectEventPic_Importado_clown_platinum[] = INCBIN_U32("graphics/entrenadores/clown_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_clown_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_clown_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_clown_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CLOWN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_clown_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cowgirl_platinum[];
const u32 gObjectEventPic_Importado_cowgirl_platinum[] = INCBIN_U32("graphics/entrenadores/cowgirl_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cowgirl_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cowgirl_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cowgirl_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_COWGIRL_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cowgirl_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_crasher_wake_platinum[];
const u32 gObjectEventPic_Importado_crasher_wake_platinum[] = INCBIN_U32("graphics/entrenadores/crasher_wake_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_crasher_wake_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_crasher_wake_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_crasher_wake_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CRASHER_WAKE_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_crasher_wake_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cycler_f_platinum[];
const u32 gObjectEventPic_Importado_cycler_f_platinum[] = INCBIN_U32("graphics/entrenadores/cycler_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cycler_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cycler_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cycler_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CYCLER_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cycler_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cycler_m_platinum[];
const u32 gObjectEventPic_Importado_cycler_m_platinum[] = INCBIN_U32("graphics/entrenadores/cycler_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cycler_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cycler_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cycler_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CYCLER_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cycler_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cynthia_platinum[];
const u32 gObjectEventPic_Importado_cynthia_platinum[] = INCBIN_U32("graphics/entrenadores/cynthia_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cynthia_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cynthia_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cynthia_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CYNTHIA_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cynthia_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_cyrus_platinum[];
const u32 gObjectEventPic_Importado_cyrus_platinum[] = INCBIN_U32("graphics/entrenadores/cyrus_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_cyrus_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_cyrus_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_cyrus_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_CYRUS_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_cyrus_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_erika_hgss[];
const u32 gObjectEventPic_Importado_erika_hgss[] = INCBIN_U32("graphics/entrenadores/erika_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_erika_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_erika_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_erika_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ERIKA_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_erika_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_falkner_hgss[];
const u32 gObjectEventPic_Importado_falkner_hgss[] = INCBIN_U32("graphics/entrenadores/falkner_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_falkner_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_falkner_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_falkner_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_FALKNER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_falkner_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_fantina_platinum[];
const u32 gObjectEventPic_Importado_fantina_platinum[] = INCBIN_U32("graphics/entrenadores/fantina_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_fantina_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_fantina_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_fantina_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_FANTINA_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_fantina_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_fisher_platinum[];
const u32 gObjectEventPic_Importado_fisher_platinum[] = INCBIN_U32("graphics/entrenadores/fisher_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_fisher_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_fisher_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_fisher_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_FISHER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_fisher_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_flint_platinum[];
const u32 gObjectEventPic_Importado_flint_platinum[] = INCBIN_U32("graphics/entrenadores/flint_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_flint_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_flint_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_flint_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_FLINT_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_flint_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_galactic_grunt_f_platinum[];
const u32 gObjectEventPic_Importado_galactic_grunt_f_platinum[] = INCBIN_U32("graphics/entrenadores/galactic_grunt_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_galactic_grunt_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_galactic_grunt_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_galactic_grunt_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GALACTIC_GRUNT_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_galactic_grunt_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_galactic_grunt_m_platinum[];
const u32 gObjectEventPic_Importado_galactic_grunt_m_platinum[] = INCBIN_U32("graphics/entrenadores/galactic_grunt_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_galactic_grunt_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_galactic_grunt_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_galactic_grunt_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GALACTIC_GRUNT_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_galactic_grunt_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_gardenia_platinum[];
const u32 gObjectEventPic_Importado_gardenia_platinum[] = INCBIN_U32("graphics/entrenadores/gardenia_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_gardenia_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_gardenia_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_gardenia_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GARDENIA_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_gardenia_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_gentleman_hgss[];
const u32 gObjectEventPic_Importado_gentleman_hgss[] = INCBIN_U32("graphics/entrenadores/gentleman_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_gentleman_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_gentleman_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_gentleman_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GENTLEMAN_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_gentleman_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_gentleman_platinum[];
const u32 gObjectEventPic_Importado_gentleman_platinum[] = INCBIN_U32("graphics/entrenadores/gentleman_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_gentleman_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_gentleman_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_gentleman_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GENTLEMAN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_gentleman_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_giovanni_hgss[];
const u32 gObjectEventPic_Importado_giovanni_hgss[] = INCBIN_U32("graphics/entrenadores/giovanni_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_giovanni_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_giovanni_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_giovanni_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_GIOVANNI_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_giovanni_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r01_c04[];
const u32 gObjectEventPic_Importado_hgss_ow_r01_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r01_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r01_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r01_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R01_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r01_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r01_c05[];
const u32 gObjectEventPic_Importado_hgss_ow_r01_c05[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c05/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r01_c05[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r01_c05, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r01_c05 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R01_C05,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r01_c05,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r01_c06[];
const u32 gObjectEventPic_Importado_hgss_ow_r01_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r01_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r01_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r01_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R01_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r01_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r01_c10[];
const u32 gObjectEventPic_Importado_hgss_ow_r01_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r01_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r01_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r01_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R01_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r01_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c02[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c03[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c04[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c06[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c09[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r02_c10[];
const u32 gObjectEventPic_Importado_hgss_ow_r02_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r02_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r02_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r02_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R02_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r02_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r03_c01[];
const u32 gObjectEventPic_Importado_hgss_ow_r03_c01[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c01/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r03_c01[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r03_c01, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r03_c01 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R03_C01,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r03_c01,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r03_c02[];
const u32 gObjectEventPic_Importado_hgss_ow_r03_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r03_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r03_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r03_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R03_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r03_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r03_c04[];
const u32 gObjectEventPic_Importado_hgss_ow_r03_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r03_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r03_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r03_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R03_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r03_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r05_c02[];
const u32 gObjectEventPic_Importado_hgss_ow_r05_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r05_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r05_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r05_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r05_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R05_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r05_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r06_c03[];
const u32 gObjectEventPic_Importado_hgss_ow_r06_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r06_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r06_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r06_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R06_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r06_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r06_c08[];
const u32 gObjectEventPic_Importado_hgss_ow_r06_c08[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c08/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r06_c08[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r06_c08, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r06_c08 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R06_C08,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r06_c08,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c02[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c06[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c07[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c07[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c07/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c07[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c07, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c07 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C07,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c07,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c08[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c08[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c08/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c08[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c08, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c08 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C08,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c08,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c09[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r07_c10[];
const u32 gObjectEventPic_Importado_hgss_ow_r07_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r07_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r07_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r07_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R07_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r07_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c01[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c01[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c01/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c01[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c01, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c01 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C01,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c01,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c02[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c03[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c04[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c05[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c05[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c05/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c05[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c05, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c05 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C05,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c05,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c06[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c07[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c07[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c07/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c07[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c07, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c07 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C07,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c07,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c08[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c08[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c08/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c08[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c08, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c08 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C08,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c08,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c09[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hgss_ow_r08_c10[];
const u32 gObjectEventPic_Importado_hgss_ow_r08_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hgss_ow_r08_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hgss_ow_r08_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hgss_ow_r08_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HGSS_OW_R08_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hgss_ow_r08_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_hiker_platinum[];
const u32 gObjectEventPic_Importado_hiker_platinum[] = INCBIN_U32("graphics/entrenadores/hiker_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_hiker_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_hiker_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_hiker_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_HIKER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_hiker_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_idol_platinum[];
const u32 gObjectEventPic_Importado_idol_platinum[] = INCBIN_U32("graphics/entrenadores/idol_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_idol_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_idol_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_idol_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_IDOL_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_idol_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_janine_hgss[];
const u32 gObjectEventPic_Importado_janine_hgss[] = INCBIN_U32("graphics/entrenadores/janine_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_janine_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_janine_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_janine_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_JANINE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_janine_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_jasmine_hgss[];
const u32 gObjectEventPic_Importado_jasmine_hgss[] = INCBIN_U32("graphics/entrenadores/jasmine_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_jasmine_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_jasmine_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_jasmine_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_JASMINE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_jasmine_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_jogger_platinum[];
const u32 gObjectEventPic_Importado_jogger_platinum[] = INCBIN_U32("graphics/entrenadores/jogger_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_jogger_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_jogger_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_jogger_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_JOGGER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_jogger_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_juggler_hgss[];
const u32 gObjectEventPic_Importado_juggler_hgss[] = INCBIN_U32("graphics/entrenadores/juggler_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_juggler_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_juggler_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_juggler_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_JUGGLER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_juggler_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_jupiter_platinum[];
const u32 gObjectEventPic_Importado_jupiter_platinum[] = INCBIN_U32("graphics/entrenadores/jupiter_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_jupiter_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_jupiter_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_jupiter_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_JUPITER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_jupiter_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_karen_hgss[];
const u32 gObjectEventPic_Importado_karen_hgss[] = INCBIN_U32("graphics/entrenadores/karen_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_karen_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_karen_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_karen_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_KAREN_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_karen_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_kimono_girl_hgss[];
const u32 gObjectEventPic_Importado_kimono_girl_hgss[] = INCBIN_U32("graphics/entrenadores/kimono_girl_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_kimono_girl_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_kimono_girl_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_kimono_girl_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_KIMONO_GIRL_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_kimono_girl_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_koga_hgss[];
const u32 gObjectEventPic_Importado_koga_hgss[] = INCBIN_U32("graphics/entrenadores/koga_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_koga_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_koga_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_koga_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_KOGA_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_koga_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_lance_hgss[];
const u32 gObjectEventPic_Importado_lance_hgss[] = INCBIN_U32("graphics/entrenadores/lance_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_lance_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_lance_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_lance_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_LANCE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_lance_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_lass_hgss[];
const u32 gObjectEventPic_Importado_lass_hgss[] = INCBIN_U32("graphics/entrenadores/lass_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_lass_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_lass_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_lass_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_LASS_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_lass_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_looker_platinum[];
const u32 gObjectEventPic_Importado_looker_platinum[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/looker_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_looker_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_looker_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_looker_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_LOOKER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_looker_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_lt_surge_hgss[];
const u32 gObjectEventPic_Importado_lt_surge_hgss[] = INCBIN_U32("graphics/entrenadores/lt_surge_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_lt_surge_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_lt_surge_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_lt_surge_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_LT_SURGE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_lt_surge_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_lucian_platinum[];
const u32 gObjectEventPic_Importado_lucian_platinum[] = INCBIN_U32("graphics/entrenadores/lucian_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_lucian_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_lucian_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_lucian_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_LUCIAN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_lucian_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_maid_platinum[];
const u32 gObjectEventPic_Importado_maid_platinum[] = INCBIN_U32("graphics/entrenadores/maid_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_maid_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_maid_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_maid_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAID_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_maid_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_marley_platinum[];
const u32 gObjectEventPic_Importado_marley_platinum[] = INCBIN_U32("graphics/entrenadores/marley_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_marley_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_marley_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_marley_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MARLEY_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_marley_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_mars_platinum[];
const u32 gObjectEventPic_Importado_mars_platinum[] = INCBIN_U32("graphics/entrenadores/mars_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_mars_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_mars_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_mars_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MARS_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_mars_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_maylene_platinum[];
const u32 gObjectEventPic_Importado_maylene_platinum[] = INCBIN_U32("graphics/entrenadores/maylene_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_maylene_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_maylene_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_maylene_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAYLENE_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_maylene_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_mira_platinum[];
const u32 gObjectEventPic_Importado_mira_platinum[] = INCBIN_U32("graphics/entrenadores/mira_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_mira_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_mira_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_mira_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MIRA_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_mira_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_misty_hgss[];
const u32 gObjectEventPic_Importado_misty_hgss[] = INCBIN_U32("graphics/entrenadores/misty_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_misty_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_misty_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_misty_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MISTY_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_misty_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_morty_hgss[];
const u32 gObjectEventPic_Importado_morty_hgss[] = INCBIN_U32("graphics/entrenadores/morty_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_morty_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_morty_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_morty_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MORTY_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_morty_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_palmer_platinum[];
const u32 gObjectEventPic_Importado_palmer_platinum[] = INCBIN_U32("graphics/entrenadores/palmer_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_palmer_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_palmer_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_palmer_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PALMER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_palmer_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_picnicker_platinum[];
const u32 gObjectEventPic_Importado_picnicker_platinum[] = INCBIN_U32("graphics/entrenadores/picnicker_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_picnicker_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_picnicker_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_picnicker_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PICNICKER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_picnicker_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b0_c01[];
const u32 gObjectEventPic_Importado_platinum_ow_b0_c01[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c01/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b0_c01[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b0_c01, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b0_c01 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B0_C01,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b0_c01,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b0_c04[];
const u32 gObjectEventPic_Importado_platinum_ow_b0_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b0_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b0_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b0_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B0_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b0_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b0_c08[];
const u32 gObjectEventPic_Importado_platinum_ow_b0_c08[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c08/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b0_c08[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b0_c08, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b0_c08 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B0_C08,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b0_c08,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b0_c09[];
const u32 gObjectEventPic_Importado_platinum_ow_b0_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b0_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b0_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b0_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B0_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b0_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b1_c05[];
const u32 gObjectEventPic_Importado_platinum_ow_b1_c05[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c05/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b1_c05[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b1_c05, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b1_c05 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B1_C05,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b1_c05,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b1_c06[];
const u32 gObjectEventPic_Importado_platinum_ow_b1_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b1_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b1_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b1_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B1_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b1_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b1_c09[];
const u32 gObjectEventPic_Importado_platinum_ow_b1_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b1_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b1_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b1_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B1_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b1_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b1_c10[];
const u32 gObjectEventPic_Importado_platinum_ow_b1_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b1_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b1_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b1_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B1_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b1_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b1_c16[];
const u32 gObjectEventPic_Importado_platinum_ow_b1_c16[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c16/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b1_c16[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b1_c16, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b1_c16 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B1_C16,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b1_c16,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c02[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c03[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c04[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c07[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c07[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c07/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c07[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c07, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c07 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C07,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c07,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c14[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c14[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c14/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c14[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c14, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c14 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C14,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c14,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c15[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c15[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c15/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c15[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c15, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c15 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C15,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c15,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b2_c16[];
const u32 gObjectEventPic_Importado_platinum_ow_b2_c16[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c16/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b2_c16[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b2_c16, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b2_c16 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B2_C16,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b2_c16,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c02[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c02[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c02/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c02[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c02, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c02 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C02,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c02,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c03[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c04[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c09[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c10[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c11[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c11[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c11/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c11[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c11, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c11 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C11,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c11,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c12[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c12[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c12/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c12[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c12, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c12 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C12,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c12,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c13[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c13[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c13/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c13[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c13, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c13 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C13,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c13,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c14[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c14[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c14/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c14[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c14, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c14 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C14,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c14,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c15[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c15[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c15/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c15[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c15, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c15 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C15,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c15,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b3_c16[];
const u32 gObjectEventPic_Importado_platinum_ow_b3_c16[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c16/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b3_c16[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b3_c16, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b3_c16 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B3_C16,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b3_c16,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c00[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c00[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c00/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c00[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c00, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c00 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C00,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c00,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c03[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c03[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c03/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c03[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c03, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c03 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C03,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c03,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c04[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c04[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c04/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c04[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c04, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c04 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C04,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c04,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c05[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c05[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c05/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c05[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c05, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c05 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C05,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c05,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c06[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c06[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c06/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c06[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c06, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c06 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C06,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c06,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c07[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c07[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c07/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c07[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c07, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c07 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C07,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c07,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c08[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c08[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c08/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c08[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c08, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c08 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C08,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c08,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c09[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c09[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c09/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c09[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c09, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c09 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C09,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c09,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c10[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c10[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c10/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c10[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c10, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c10 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C10,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c10,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b4_c11[];
const u32 gObjectEventPic_Importado_platinum_ow_b4_c11[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c11/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b4_c11[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b4_c11, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b4_c11 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B4_C11,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b4_c11,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_platinum_ow_b5_c12[];
const u32 gObjectEventPic_Importado_platinum_ow_b5_c12[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/platinum_ow_b5_c12/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_platinum_ow_b5_c12[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_platinum_ow_b5_c12, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_platinum_ow_b5_c12 =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLATINUM_OW_B5_C12,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_platinum_ow_b5_c12,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_poke_maniac_hgss[];
const u32 gObjectEventPic_Importado_poke_maniac_hgss[] = INCBIN_U32("graphics/entrenadores/poke_maniac_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_poke_maniac_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_poke_maniac_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_poke_maniac_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_POKE_MANIAC_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_poke_maniac_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_pokefan_f_hgss[];
const u32 gObjectEventPic_Importado_pokefan_f_hgss[] = INCBIN_U32("graphics/entrenadores/pokefan_f_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_pokefan_f_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_pokefan_f_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_pokefan_f_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_POKEFAN_F_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_pokefan_f_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_pokefan_m_platinum[];
const u32 gObjectEventPic_Importado_pokefan_m_platinum[] = INCBIN_U32("graphics/entrenadores/pokefan_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_pokefan_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_pokefan_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_pokefan_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_POKEFAN_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_pokefan_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_pokemon_breeder_m_platinum[];
const u32 gObjectEventPic_Importado_pokemon_breeder_m_platinum[] = INCBIN_U32("graphics/entrenadores/pokemon_breeder_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_pokemon_breeder_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_pokemon_breeder_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_pokemon_breeder_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_POKEMON_BREEDER_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_pokemon_breeder_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_policeman_platinum[];
const u32 gObjectEventPic_Importado_policeman_platinum[] = INCBIN_U32("graphics/entrenadores/policeman_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_policeman_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_policeman_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_policeman_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_POLICEMAN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_policeman_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_professor_elm_hgss[];
const u32 gObjectEventPic_Importado_professor_elm_hgss[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/professor_elm_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_professor_elm_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_professor_elm_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_professor_elm_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PROFESSOR_ELM_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_professor_elm_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_professor_rowan_platinum[];
const u32 gObjectEventPic_Importado_professor_rowan_platinum[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/professor_rowan_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_professor_rowan_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_professor_rowan_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_professor_rowan_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PROFESSOR_ROWAN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_professor_rowan_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_pryce_hgss[];
const u32 gObjectEventPic_Importado_pryce_hgss[] = INCBIN_U32("graphics/entrenadores/pryce_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_pryce_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_pryce_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_pryce_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PRYCE_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_pryce_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_psychic_f_platinum[];
const u32 gObjectEventPic_Importado_psychic_f_platinum[] = INCBIN_U32("graphics/entrenadores/psychic_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_psychic_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_psychic_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_psychic_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PSYCHIC_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_psychic_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_psychic_m_platinum[];
const u32 gObjectEventPic_Importado_psychic_m_platinum[] = INCBIN_U32("graphics/entrenadores/psychic_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_psychic_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_psychic_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_psychic_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PSYCHIC_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_psychic_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_red_hgss[];
const u32 gObjectEventPic_Importado_red_hgss[] = INCBIN_U32("graphics/entrenadores/red_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_red_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_red_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_red_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_RED_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_red_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_reporter_platinum[];
const u32 gObjectEventPic_Importado_reporter_platinum[] = INCBIN_U32("graphics/entrenadores/reporter_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_reporter_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_reporter_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_reporter_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_REPORTER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_reporter_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_rich_boy_platinum[];
const u32 gObjectEventPic_Importado_rich_boy_platinum[] = INCBIN_U32("graphics/entrenadores/rich_boy_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_rich_boy_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_rich_boy_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_rich_boy_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_RICH_BOY_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_rich_boy_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_riley_platinum[];
const u32 gObjectEventPic_Importado_riley_platinum[] = INCBIN_U32("graphics/entrenadores/riley_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_riley_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_riley_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_riley_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_RILEY_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_riley_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_roark_platinum[];
const u32 gObjectEventPic_Importado_roark_platinum[] = INCBIN_U32("graphics/entrenadores/roark_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_roark_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_roark_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_roark_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ROARK_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_roark_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_rocket_grunt_f_hgss[];
const u32 gObjectEventPic_Importado_rocket_grunt_f_hgss[] = INCBIN_U32("graphics/entrenadores/rocket_grunt_f_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_rocket_grunt_f_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_rocket_grunt_f_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_rocket_grunt_f_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ROCKET_GRUNT_F_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_rocket_grunt_f_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_rocket_grunt_m_hgss[];
const u32 gObjectEventPic_Importado_rocket_grunt_m_hgss[] = INCBIN_U32("graphics/entrenadores/rocket_grunt_m_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_rocket_grunt_m_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_rocket_grunt_m_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_rocket_grunt_m_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ROCKET_GRUNT_M_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_rocket_grunt_m_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_roughneck_platinum[];
const u32 gObjectEventPic_Importado_roughneck_platinum[] = INCBIN_U32("graphics/entrenadores/roughneck_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_roughneck_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_roughneck_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_roughneck_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_ROUGHNECK_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_roughneck_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_ruin_maniac_platinum[];
const u32 gObjectEventPic_Importado_ruin_maniac_platinum[] = INCBIN_U32("graphics/entrenadores/ruin_maniac_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_ruin_maniac_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_ruin_maniac_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_ruin_maniac_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_RUIN_MANIAC_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_ruin_maniac_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_sabrina_hgss[];
const u32 gObjectEventPic_Importado_sabrina_hgss[] = INCBIN_U32("graphics/entrenadores/sabrina_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_sabrina_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_sabrina_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_sabrina_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SABRINA_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_sabrina_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_sailor_hgss[];
const u32 gObjectEventPic_Importado_sailor_hgss[] = INCBIN_U32("graphics/entrenadores/sailor_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_sailor_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_sailor_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_sailor_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SAILOR_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_sailor_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_sailor_platinum[];
const u32 gObjectEventPic_Importado_sailor_platinum[] = INCBIN_U32("graphics/entrenadores/sailor_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_sailor_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_sailor_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_sailor_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SAILOR_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_sailor_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_saturn_platinum[];
const u32 gObjectEventPic_Importado_saturn_platinum[] = INCBIN_U32("graphics/entrenadores/saturn_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_saturn_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_saturn_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_saturn_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SATURN_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_saturn_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_school_kid_f_platinum[];
const u32 gObjectEventPic_Importado_school_kid_f_platinum[] = INCBIN_U32("graphics/entrenadores/school_kid_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_school_kid_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_school_kid_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_school_kid_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SCHOOL_KID_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_school_kid_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_scientist_hgss[];
const u32 gObjectEventPic_Importado_scientist_hgss[] = INCBIN_U32("graphics/entrenadores/scientist_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_scientist_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_scientist_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_scientist_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SCIENTIST_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_scientist_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_scientist_platinum[];
const u32 gObjectEventPic_Importado_scientist_platinum[] = INCBIN_U32("graphics/entrenadores/scientist_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_scientist_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_scientist_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_scientist_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SCIENTIST_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_scientist_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_silver_hgss[];
const u32 gObjectEventPic_Importado_silver_hgss[] = INCBIN_U32("graphics/entrenadores/silver_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_silver_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_silver_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_silver_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SILVER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_silver_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_skier_f_platinum[];
const u32 gObjectEventPic_Importado_skier_f_platinum[] = INCBIN_U32("graphics/entrenadores/skier_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_skier_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_skier_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_skier_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SKIER_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_skier_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_skier_m_platinum[];
const u32 gObjectEventPic_Importado_skier_m_platinum[] = INCBIN_U32("graphics/entrenadores/skier_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_skier_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_skier_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_skier_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SKIER_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_skier_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_socialite_platinum[];
const u32 gObjectEventPic_Importado_socialite_platinum[] = INCBIN_U32("graphics/entrenadores/socialite_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_socialite_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_socialite_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_socialite_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SOCIALITE_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_socialite_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_steven_hgss[];
const u32 gObjectEventPic_Importado_steven_hgss[] = INCBIN_U32("graphics/entrenadores/cajon_de_sastre/steven_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_steven_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_steven_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_steven_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_STEVEN_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_steven_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_swimmer_f_hgss[];
const u32 gObjectEventPic_Importado_swimmer_f_hgss[] = INCBIN_U32("graphics/entrenadores/swimmer_f_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_swimmer_f_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_swimmer_f_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_swimmer_f_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SWIMMER_F_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_swimmer_f_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_swimmer_f_platinum[];
const u32 gObjectEventPic_Importado_swimmer_f_platinum[] = INCBIN_U32("graphics/entrenadores/swimmer_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_swimmer_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_swimmer_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_swimmer_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SWIMMER_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_swimmer_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_swimmer_m_hgss[];
const u32 gObjectEventPic_Importado_swimmer_m_hgss[] = INCBIN_U32("graphics/entrenadores/swimmer_m_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_swimmer_m_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_swimmer_m_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_swimmer_m_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_SWIMMER_M_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_swimmer_m_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_tuber_f_platinum[];
const u32 gObjectEventPic_Importado_tuber_f_platinum[] = INCBIN_U32("graphics/entrenadores/tuber_f_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_tuber_f_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_tuber_f_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_tuber_f_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_TUBER_F_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_tuber_f_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_tuber_m_platinum[];
const u32 gObjectEventPic_Importado_tuber_m_platinum[] = INCBIN_U32("graphics/entrenadores/tuber_m_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_tuber_m_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_tuber_m_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_tuber_m_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_TUBER_M_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_tuber_m_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_twins_hgss[];
const u32 gObjectEventPic_Importado_twins_hgss[] = INCBIN_U32("graphics/entrenadores/twins_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_twins_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_twins_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_twins_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_TWINS_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_twins_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_twins_platinum[];
const u32 gObjectEventPic_Importado_twins_platinum[] = INCBIN_U32("graphics/entrenadores/twins_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_twins_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_twins_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_twins_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_TWINS_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_twins_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_volkner_platinum[];
const u32 gObjectEventPic_Importado_volkner_platinum[] = INCBIN_U32("graphics/entrenadores/volkner_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_volkner_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_volkner_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_volkner_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_VOLKNER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_volkner_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_waiter_platinum[];
const u32 gObjectEventPic_Importado_waiter_platinum[] = INCBIN_U32("graphics/entrenadores/waiter_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_waiter_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_waiter_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_waiter_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_WAITER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_waiter_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_waitress_platinum[];
const u32 gObjectEventPic_Importado_waitress_platinum[] = INCBIN_U32("graphics/entrenadores/waitress_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_waitress_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_waitress_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_waitress_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_WAITRESS_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_waitress_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_whitney_hgss[];
const u32 gObjectEventPic_Importado_whitney_hgss[] = INCBIN_U32("graphics/entrenadores/whitney_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_whitney_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_whitney_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_whitney_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_WHITNEY_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados12,
    .images = sPicTable_OWEntrenadorImportado_whitney_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_will_hgss[];
const u32 gObjectEventPic_Importado_will_hgss[] = INCBIN_U32("graphics/entrenadores/will_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_will_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_will_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_will_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_WILL_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_will_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_worker_platinum[];
const u32 gObjectEventPic_Importado_worker_platinum[] = INCBIN_U32("graphics/entrenadores/worker_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_worker_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_worker_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_worker_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_WORKER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_worker_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_youngster_hgss[];
const u32 gObjectEventPic_Importado_youngster_hgss[] = INCBIN_U32("graphics/entrenadores/youngster_hgss/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_youngster_hgss[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_youngster_hgss, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_youngster_hgss =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_YOUNGSTER_HGSS,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_youngster_hgss,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u16 gPaletaEntrenador_youngster_platinum[];
const u32 gObjectEventPic_Importado_youngster_platinum[] = INCBIN_U32("graphics/entrenadores/youngster_platinum/ow.4bpp");
static const struct SpriteFrameImage sPicTable_OWEntrenadorImportado_youngster_platinum[] =
{
    overworld_ascending_frames(gObjectEventPic_Importado_youngster_platinum, 4, 4),
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Importado_youngster_platinum =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_YOUNGSTER_PLATINUM,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_OWEntrenadoresImportados9,
    .images = sPicTable_OWEntrenadorImportado_youngster_platinum,
    .affineAnims = gDummySpriteAffineAnimTable,
};

#endif // GUARD_SRC_DATA_OBJECT_EVENTS_ENTRENADORES_IMPORTADOS_H

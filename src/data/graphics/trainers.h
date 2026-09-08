#include "constants/trainers.h"
#include "data.h"
#include "constants/battle.h"   // ENTRADA_ENTRENADOR_SUELTA
#include "pic_combate.h"        // PIC_80_BYTES








































































const u32 gTrainerFrontPic_Brendan[] = INCBIN_U32("graphics/trainers/front_pics/brendan.4bpp.lz");
const u16 gTrainerPalette_Brendan[] = INCBIN_U16("graphics/trainers/palettes/brendan.gbapal");

const u32 gTrainerFrontPic_May[] = INCBIN_U32("graphics/trainers/front_pics/may.4bpp.lz");
const u16 gTrainerPalette_May[] = INCBIN_U16("graphics/trainers/palettes/may.gbapal");




const u32 gTrainerFrontPic_MagmaLeaderMaxie[] = INCBIN_U32("graphics/trainers/front_pics/magma_leader_maxie.4bpp.lz");
const u16 gTrainerPalette_MagmaLeaderMaxie[] = INCBIN_U16("graphics/trainers/front_pics/magma_leader_maxie.gbapal");










const u32 gTrainerFrontPic_Cynthia[] = INCBIN_U32("graphics/trainers/front_pics/cynthia.4bpp.lz");
const u16 gTrainerPalette_Cynthia[] = INCBIN_U16("graphics/trainers/front_pics/cynthia.gbapal");

const u32 gTrainerFrontPic_Lance[] = INCBIN_U32("graphics/trainers/front_pics/lance.4bpp.lz");
const u16 gTrainerPalette_Lance[] = INCBIN_U16("graphics/trainers/front_pics/lance.gbapal");

const u8 gTrainerBackPic_Brendan[] = INCBIN_U8("graphics/trainers/back_pics/brendan.4bpp");
const u8 gTrainerBackPic_May[] = INCBIN_U8("graphics/trainers/back_pics/may.4bpp");


// The first two parameters invoke a front pic and palette by
// calling a "TRAINER_PIC" constant (e.g. TRAINER_PIC_HIKER), and
// gTrainerFrontPic/gTrainerPalette pointers, (e.g "gTrainerFrontPic_Hiker" and "gTrainerPalette_Hiker").
// The last three parameters control the X and Y coordinates and rotation of the mugshot on the screen.
// They default to 0, 0, and 512 which are default values used by the majority of the game's trainer sprites.
#define TRAINER_SPRITE(trainerPic, file, ...)                                             \
    [TRAINER_PIC_##trainerPic] =                                                          \
    {                                                                                     \
        .frontPic = {gTrainerFrontPic_##file, TRAINER_PIC_SIZE, TRAINER_PIC_##trainerPic},\
        .palette = {gTrainerPalette_##file, TRAINER_PIC_##trainerPic},                    \
        .mugshotCoords = {DEFAULT(0, __VA_ARGS__), DEFAULT_2(0, __VA_ARGS__)},            \
        .mugshotRotation = DEFAULT_3(512, __VA_ARGS__),                                   \
    }

const struct TrainerSprite gTrainerSprites[] =
{
    TRAINER_SPRITE(BRENDAN, Brendan),
    TRAINER_SPRITE(MAY, May),
    TRAINER_SPRITE(MAGMA_LEADER_MAXIE, MagmaLeaderMaxie),
    TRAINER_SPRITE(CYNTHIA, Cynthia),
    TRAINER_SPRITE(LANCE, Lance),
};

static const union AnimCmd sAnimCmd_Hoenn[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_Point_HGSS[] =
{
    ANIMCMD_FRAME(3, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

// Cuatro fotogramas y en el orden de vanilla: 0 brazo estirado con la bola, 1 brazo
// recogido, 2 lanzando, 3 quieto con los brazos caidos. Por eso la pose de reposo
// -el indice 0 de esta tabla- es el fotograma 3 y no el 0.
//
// Brendan ya no usa esta tabla: se paso al orden propio del proyecto. Ver
// sBackAnims_TresPoses.
static const union AnimCmd *const sBackAnims_Hoenn[] =
{
    sAnim_GeneralFrame3,
    sAnimCmd_Hoenn,
    sAnimCmd_Point_HGSS,
};

// ---------------------------------------------------------------------------
// El orden del proyecto para las espaldas de entrenador: TRES poses, y en el orden
// en que ocurren.
//
//     0  quieto, brazos caidos       <- la de reposo, y por eso va la primera
//     1  lanzando
//     2  brazo del todo estirado
//
// Asi la pose de reposo es el fotograma 0, que es lo que espera cualquiera que mire
// la hoja, y la animacion es simplemente recorrerlos en orden. La de vanilla llevaba
// cuatro y empezaba por el brazo estirado, con lo que el entrenador aparecia con el
// gesto ya hecho.
// ---------------------------------------------------------------------------

// Cuantas poses trae una espalda del proyecto. No es un maximo: son exactamente
// estas tres, y la animacion las recorre en orden.
#define POSES_ENTRENADOR 3

static const union AnimCmd sAnimCmd_TresPoses[] =
{
    ANIMCMD_FRAME(0, ENTRADA_ENTRENADOR_SUELTA),    // quieto, hasta que suelta
    ANIMCMD_FRAME(1, 9),                            // el gesto
    ANIMCMD_FRAME(2, 50),                           // y se queda estirado
    ANIMCMD_END,
};

static const union AnimCmd *const sBackAnims_TresPoses[] =
{
    sAnim_GeneralFrame0,
    sAnimCmd_TresPoses,
    sAnimCmd_TresPoses,     // sin variante de senalar: es el mismo gesto
};

const struct SpriteFrameImage gTrainerBackPicTable_Brendan[] =
{
    {gTrainerBackPic_Brendan + TRAINER_PIC_SIZE * 0, TRAINER_PIC_SIZE},
    {gTrainerBackPic_Brendan + TRAINER_PIC_SIZE * 1, TRAINER_PIC_SIZE},
    {gTrainerBackPic_Brendan + TRAINER_PIC_SIZE * 2, TRAINER_PIC_SIZE},
};

const struct SpriteFrameImage gTrainerBackPicTable_May[] =
{
    {gTrainerBackPic_May + TRAINER_PIC_SIZE * 0, TRAINER_PIC_SIZE},
    {gTrainerBackPic_May + TRAINER_PIC_SIZE * 1, TRAINER_PIC_SIZE},
    {gTrainerBackPic_May + TRAINER_PIC_SIZE * 2, TRAINER_PIC_SIZE},
    {gTrainerBackPic_May + TRAINER_PIC_SIZE * 3, TRAINER_PIC_SIZE},
};

// .backPic goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
#define TRAINER_BACK_SPRITE(trainerPic, yOffset, sprite, pal, anim)                                                                                       \
    [TRAINER_BACK_PIC_##trainerPic] =                                                                                                                     \
    {                                                                                                                                                     \
        .coordinates = {.size = 8, .y_offset = yOffset},                                                                                                  \
        .backPic = {(const u32 *)gTrainerBackPic_##sprite, TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_##sprite), TRAINER_BACK_PIC_##trainerPic}, \
        .palette = {gTrainer##pal, TRAINER_BACK_PIC_##trainerPic},                                                                                        \
        .animation = sBackAnims_##anim,                                                                                                                   \
        .bytesPorFotograma = TRAINER_PIC_SIZE,                                                                                                            \
    }

// Las espaldas del proyecto: 80x80 y tres poses, con el grafico y la paleta en la
// carpeta de la especie de entrenador. El lienzo no cabe en un objeto de GBA, asi que
// se trocea; de eso se encarga pic_combate mirando bytesPorFotograma.
#define ESPALDA_ENTRENADOR(trainerPic, yOffset, carpeta)                                                             \
    [TRAINER_BACK_PIC_##trainerPic] =                                                                                \
    {                                                                                                                \
        .coordinates = {.size = 8, .y_offset = yOffset},                                                             \
        .backPic = {(const u32 *)gEspaldaEntrenador_##carpeta,                                                       \
                    PIC_80_BYTES * POSES_ENTRENADOR, TRAINER_BACK_PIC_##trainerPic},                                 \
        .palette = {gPaletaEntrenador_##carpeta, TRAINER_BACK_PIC_##trainerPic},                                     \
        .animation = sBackAnims_TresPoses,                                                                           \
        .bytesPorFotograma = PIC_80_BYTES,                                                                            \
    }

// ---------------------------------------------------------------------------
// Espaldas del proyecto. La paleta sale del propio back y la comparte con el
// frontal del mismo entrenador.
// ---------------------------------------------------------------------------
const u8 gEspaldaEntrenador_Ethan[] = INCBIN_U8("graphics/entrenadores/ethan/back.4bpp");
const u16 gPaletaEntrenador_Ethan[] = INCBIN_U16("graphics/entrenadores/ethan/back.gbapal");

const struct TrainerBacksprite gTrainerBacksprites[] =
{
    ESPALDA_ENTRENADOR(ETHAN, 4, Ethan),
    TRAINER_BACK_SPRITE(BRENDAN, 4, Brendan, Palette_Brendan, TresPoses),
    TRAINER_BACK_SPRITE(MAY, 4, May, Palette_May, Hoenn),
};

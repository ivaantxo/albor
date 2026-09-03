#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "data.h"
#include "graphics.h"
#include "battle_transition.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/battle_ai.h"

#define BATTLER_OFFSET(i) (gHeap + 0x8000 + MON_PIC_SIZE * (i))

const struct SpriteFrameImage gBattlerPicTable_PlayerLeft[] =
{
    {BATTLER_OFFSET(0), MON_PIC_SIZE},
    {BATTLER_OFFSET(1), MON_PIC_SIZE},
    {BATTLER_OFFSET(2), MON_PIC_SIZE},
    {BATTLER_OFFSET(3), MON_PIC_SIZE},
};

const struct SpriteFrameImage gBattlerPicTable_OpponentLeft[] =
{
    {BATTLER_OFFSET(4), MON_PIC_SIZE},
    {BATTLER_OFFSET(5), MON_PIC_SIZE},
    {BATTLER_OFFSET(6), MON_PIC_SIZE},
    {BATTLER_OFFSET(7), MON_PIC_SIZE},
};

const struct SpriteFrameImage gBattlerPicTable_PlayerRight[] =
{
    {BATTLER_OFFSET(8),  MON_PIC_SIZE},
    {BATTLER_OFFSET(9),  MON_PIC_SIZE},
    {BATTLER_OFFSET(10), MON_PIC_SIZE},
    {BATTLER_OFFSET(11), MON_PIC_SIZE},
};

const struct SpriteFrameImage gBattlerPicTable_OpponentRight[] =
{
    {BATTLER_OFFSET(12), MON_PIC_SIZE},
    {BATTLER_OFFSET(13), MON_PIC_SIZE},
    {BATTLER_OFFSET(14), MON_PIC_SIZE},
    {BATTLER_OFFSET(15), MON_PIC_SIZE},
};

const union AnimCmd sAnim_GeneralFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

const union AnimCmd sAnim_GeneralFrame3[] =
{
    ANIMCMD_FRAME(3, 0),
    ANIMCMD_END,
};

// Many of these affine anims seem to go unused, and
// instead SetSpriteRotScale is used to manipulate
// the battler sprites directly (for instance, in AnimTask_SwitchOutShrinkMon).
// Those with explicit indexes are referenced elsewhere.

static const union AffineAnimCmd sAffineAnim_Battler_Normal[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_Emerge[] =
{
    AFFINEANIMCMD_FRAME(0x28, 0x28, 0, 0),
    AFFINEANIMCMD_FRAME(0x12, 0x12, 0, 12),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_Return[] =
{
    AFFINEANIMCMD_FRAME( -0x2,  -0x2, 0, 18),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_HorizontalSquishLoop[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME( 0x4,   0x0, 0, 8),
    AFFINEANIMCMD_FRAME(-0x4,   0x0, 0, 8),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd sAffineAnim_Battler_Grow[] =
{
    AFFINEANIMCMD_FRAME(0x2, 0x2, 0, 20),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_Shrink[] =
{
    AFFINEANIMCMD_FRAME(-0x2, -0x2, 0, 20),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_BigToSmall[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0, 9),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_GrowLarge[] =
{
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 63),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_TipRight[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -3, 5),
    AFFINEANIMCMD_FRAME(0x0, 0x0,  3, 5),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[] =
{
    [BATTLER_AFFINE_NORMAL] = sAffineAnim_Battler_Normal,
    [BATTLER_AFFINE_EMERGE] = sAffineAnim_Battler_Emerge,
    [BATTLER_AFFINE_RETURN] = sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_GrowLarge,
    sAffineAnim_Battler_TipRight,
    sAffineAnim_Battler_BigToSmall,
};

static const union AffineAnimCmd sAffineAnim_Battler_SpinShrink[] =
{
    AFFINEANIMCMD_FRAME(-0x4, -0x4, 4, 63),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_TipLeft[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0,  3, 5),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -3, 5),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_RotateUpAndBack[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0,  0, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0,  5, 20),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Battler_Spin[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 9, 110),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[] =
{
    [BATTLER_AFFINE_NORMAL] = sAffineAnim_Battler_Normal,
    [BATTLER_AFFINE_EMERGE] = sAffineAnim_Battler_Emerge,
    [BATTLER_AFFINE_RETURN] = sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_SpinShrink,
    sAffineAnim_Battler_TipLeft,
    sAffineAnim_Battler_RotateUpAndBack,
    sAffineAnim_Battler_BigToSmall,
    sAffineAnim_Battler_Spin,
};

const union AffineAnimCmd *const gAffineAnims_BattleSpriteContest[] =
{
    [BATTLER_AFFINE_NORMAL] = sAffineAnim_Battler_Flipped,
    [BATTLER_AFFINE_EMERGE] = sAffineAnim_Battler_Emerge,
    [BATTLER_AFFINE_RETURN] = sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_SpinShrink,
    sAffineAnim_Battler_TipLeft,
    sAffineAnim_Battler_RotateUpAndBack,
    sAffineAnim_Battler_BigToSmall,
    sAffineAnim_Battler_Spin,
};

static const union AnimCmd sAnim_MonPic_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonPic_1[] =
{
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END,
};

// Vaiven continuo entre los dos primeros fotogramas. Es la animacion de los sprites
// de espalda, que no tienen tabla propia por especie como los frontales: todos
// comparten esta. Solo debe arrancarse en los pics grandes, porque los de 64x64
// tienen un unico fotograma y el segundo seria basura del buffer.
static const union AnimCmd sAnim_MonPic_Bucle[] =
{
    ANIMCMD_FRAME(0, 600),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_JUMP(0),
};

// Cuantas ANIMACIONES distintas puede pedir un pic, que no tiene nada que ver con
// cuantos fotogramas tiene. Estaba declarada con NUMERO_FRAMES_POKEMON porque las
// dos valian cuatro, y al subir los fotogramas la tabla crecia sola llena de NULL:
// pedir cualquiera de las nuevas habria saltado a la nada.
//
// Ojo: hay que rellenarlas todas.
const union AnimCmd *const gAnims_MonPic[ANIMACIONES_POR_PIC] =
{
    sAnim_MonPic_0,
    sAnim_MonPic_1,
    sAnim_MonPic_Bucle,
    sAnim_MonPic_0,
};

static const union AnimCmd sAnim_TrainerPic_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TrainerPic_1[] =
{
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END,
};


static const union AnimCmd sAnim_TrainerPic_2[] =
{
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_Trainer[] =
{
    sAnim_TrainerPic_0,
    sAnim_TrainerPic_1,
    sAnim_TrainerPic_2
};

const struct SpritePalette gEgg1PaletteTable[] =
{
    [TIPO_NORMAL]       =   {gMonPalette_Egg_Normal1,   SPECIES_EGG},
    [TIPO_LUCHA]        =   {gMonPalette_Egg_Fighting1, SPECIES_EGG},
    [TIPO_VOLADOR]      =   {gMonPalette_Egg_Flying1,   SPECIES_EGG},
    [TIPO_VENENO]       =   {gMonPalette_Egg_Poison1,   SPECIES_EGG},
    [TIPO_TIERRA]       =   {gMonPalette_Egg_Ground1,   SPECIES_EGG},
    [TIPO_ROCA]         =   {gMonPalette_Egg_Rock1,     SPECIES_EGG},
    [TIPO_BICHO]        =   {gMonPalette_Egg_Bug1,      SPECIES_EGG},
    [TIPO_FANTASMA]     =   {gMonPalette_Egg_Ghost1,    SPECIES_EGG},
    [TIPO_ACERO]        =   {gMonPalette_Egg_Steel1,    SPECIES_EGG},
    [TIPO_FUEGO]        =   {gMonPalette_Egg_Fire1,     SPECIES_EGG},
    [TIPO_AGUA]         =   {gMonPalette_Egg_Water1,    SPECIES_EGG},
    [TIPO_PLANTA]       =   {gMonPalette_Egg_Grass1,    SPECIES_EGG},
    [TIPO_ELECTRICO]    =   {gMonPalette_Egg_Electric1, SPECIES_EGG},
    [TIPO_PSIQUICO]     =   {gMonPalette_Egg_Psychic1,  SPECIES_EGG},
    [TIPO_HIELO]        =   {gMonPalette_Egg_Ice1,      SPECIES_EGG},
    [TIPO_DRAGON]       =   {gMonPalette_Egg_Dragon1,   SPECIES_EGG},
    [TIPO_SINIESTRO]    =   {gMonPalette_Egg_Dark1,     SPECIES_EGG},
    [TIPO_HADA]         =   {gMonPalette_Egg_Fairy1,    SPECIES_EGG}
};

const struct SpritePalette gEgg2PaletteTable[] =
{
    [TIPO_NORMAL]       =   {gMonPalette_Egg_Normal2,   SPECIES_EGG},
    [TIPO_LUCHA]        =   {gMonPalette_Egg_Fighting2, SPECIES_EGG},
    [TIPO_VOLADOR]      =   {gMonPalette_Egg_Flying2,   SPECIES_EGG},
    [TIPO_VENENO]       =   {gMonPalette_Egg_Poison2,   SPECIES_EGG},
    [TIPO_TIERRA]       =   {gMonPalette_Egg_Ground2,   SPECIES_EGG},
    [TIPO_ROCA]         =   {gMonPalette_Egg_Rock2,     SPECIES_EGG},
    [TIPO_BICHO]        =   {gMonPalette_Egg_Bug2,      SPECIES_EGG},
    [TIPO_FANTASMA]     =   {gMonPalette_Egg_Ghost2,    SPECIES_EGG},
    [TIPO_ACERO]        =   {gMonPalette_Egg_Steel2,    SPECIES_EGG},
    [TIPO_FUEGO]        =   {gMonPalette_Egg_Fire2,     SPECIES_EGG},
    [TIPO_AGUA]         =   {gMonPalette_Egg_Water2,    SPECIES_EGG},
    [TIPO_PLANTA]       =   {gMonPalette_Egg_Grass2,    SPECIES_EGG},
    [TIPO_ELECTRICO]    =   {gMonPalette_Egg_Electric2, SPECIES_EGG},
    [TIPO_PSIQUICO]     =   {gMonPalette_Egg_Psychic2,  SPECIES_EGG},
    [TIPO_HIELO]        =   {gMonPalette_Egg_Ice2,      SPECIES_EGG},
    [TIPO_DRAGON]       =   {gMonPalette_Egg_Dragon2,   SPECIES_EGG},
    [TIPO_SINIESTRO]    =   {gMonPalette_Egg_Dark2,     SPECIES_EGG},
    [TIPO_HADA]         =   {gMonPalette_Egg_Fairy2,    SPECIES_EGG}
};

#include "data/text/follower_messages.h"

const struct Trainer gTrainers[] =
{
#include "data/trainers.h"
};

#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "sound.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"

enum {
    ANIMDATA_ROT_IDX,
    ANIMDATA_ROT_SPEED,
    ANIMDATA_SIN_AMPLITUDE,
    ANIMDATA_COS_AMPLITUDE,
    ANIMDATA_TIME,
    ANIMDATA_ROT_ACCEL,
    ANIMDATA_TARGET_X,
    ANIMDATA_TARGET_Y,
    ANIMDATA_APPR_TIME,
    ANIMDATA_IS_LAST,
    NUM_ANIMDATA
};

#define MON_X 48
#define MON_Y 80

struct PokeblockFeed
{
    struct Sprite *monSpritePtr;
    struct Sprite savedMonSprite;
    u8 tilemapBuffer[BG_SCREEN_SIZE];
    s16 monAnimX[0x200];
    s16 monAnimY[0x200];
    u8 animRunState;
    u8 animId;
    u8 unused2;
    bool8 noMonFlip;
    u16 species;
    u16 monAnimLength;
    u16 timer;
    u8 nature;
    u8 monSpriteId_; // Duplicated unnecessarily
    u8 unused3;
    u8 monSpriteId;
    u8 pokeblockCaseSpriteId;
    u8 pokeblockSpriteId;
    s16 animData[NUM_ANIMDATA];
    s16 monInitX;
    s16 monInitY;
    s16 maxAnimStageTime;
    s16 monX;
    s16 monY;
    s16 loadGfxState;
    u8 unused4;
};

static void HandleInitBackgrounds(void);
static void HandleInitWindows(void);
static void LaunchPokeblockFeedTask(void);
static void SetPokeblockSpritePal(u8);
static void CalculateMonAnimLength(void);
static void DoPokeblockCaseThrowEffect(u32 spriteId, bool8 horizontalThrow);
static void StartMonJumpForPokeblock(u32 spriteId);
static void Task_PrintAtePokeblockMessage(u8);
static void Task_FadeOutPokeblockFeed(u8);
static void UpdateMonAnim(void);
static void SpriteCB_MonJumpForPokeblock(struct Sprite *);
static bool8 LoadMonAndSceneGfx(struct Pokemon *);
static u8 CreatePokeblockSprite(void);
static u8 CreatePokeblockCaseSpriteForFeeding(void);
static u8 CreateMonSprite(struct Pokemon *);
static void SpriteCB_ThrownPokeblock(struct Sprite *);

static const u8 sText_Var1AteTheVar2[] = _("{VAR_TEXTO_1} ate the\n{VAR_TEXTO_2}.{PAUSE_UNTIL_PRESS}");
static const u8 sText_Var1HappilyAteVar2[] = _("{VAR_TEXTO_1} happily ate the\n{VAR_TEXTO_2}.{PAUSE_UNTIL_PRESS}");
static const u8 sText_Var1DisdainfullyAteVar2[] = _("{VAR_TEXTO_1} disdainfully ate the\n{VAR_TEXTO_2}.{PAUSE_UNTIL_PRESS}");

EWRAM_DATA static struct PokeblockFeed *sPokeblockFeed = NULL;
EWRAM_DATA static struct CompressedSpritePalette sPokeblockSpritePal = {0};

// Data for the animation the Pokémon does while readying to jump for the Pokéblock
// Each nature can have up to 8 anim 'stages' it progresses through, and each stage has its own array of data.
// The elements in each array correspond in order to the following:
// - ANIMDATA_ROT_IDX      : Index into sin/cos table for circular movement
// - ANIMDATA_ROT_SPEED    : Circular movement speed
// - ANIMDATA_SIN_AMPLITUDE: How far on the x to move
// - ANIMDATA_COS_AMPLITUDE: How far on the y to move
// - ANIMDATA_TIME         : How long in frames this part of the animation takes
// - ANIMDATA_ROT_ACCEL    : How much to increase circular movement speed
// - ANIMDATA_TARGET_X     : Target x coord offset from start position
// - ANIMDATA_TARGET_Y     : Target y coord offset from start position
// - ANIMDATA_APPR_TIME    : The time over which the target position should be approached
// - ANIMDATA_IS_LAST      : TRUE if it's the last anim stage for this nature, FALSE otherwise
//

static const union AffineAnimCmd sAffineAnim_Mon_None[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUp[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 12, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 30),
    AFFINEANIMCMD_FRAME(0, 0, -12, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUp_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 12, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 28),
    AFFINEANIMCMD_FRAME(0, 0, -4, 3),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUpAndDown[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUpAndDown_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDown[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDown_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDownSlow[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDownSlow_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDownSlight[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnDownSlight_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUpHigh[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -12, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Mon_TurnUpHigh_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 16),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -12, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Mon[] =
{
    // Animations for non-flipped mon sprites
    [AFFINE_NONE]             = sAffineAnim_Mon_None,
    [AFFINE_TURN_UP]          = sAffineAnim_Mon_TurnUp,
    [AFFINE_TURN_UP_AND_DOWN] = sAffineAnim_Mon_TurnUpAndDown,
    [AFFINE_TURN_DOWN]        = sAffineAnim_Mon_TurnDown,
    [AFFINE_TURN_DOWN_SLOW]   = sAffineAnim_Mon_TurnDownSlow,
    [AFFINE_TURN_DOWN_SLIGHT] = sAffineAnim_Mon_TurnDownSlight,
    [AFFINE_TURN_UP_HIGH]     = sAffineAnim_Mon_TurnUpHigh,

    // Animations for flipped mon sprites
    [AFFINE_NONE + NUM_MON_AFFINES]             = sAffineAnim_Mon_None,
    [AFFINE_TURN_UP + NUM_MON_AFFINES]          = sAffineAnim_Mon_TurnUp_Flipped,
    [AFFINE_TURN_UP_AND_DOWN + NUM_MON_AFFINES] = sAffineAnim_Mon_TurnUpAndDown_Flipped,
    [AFFINE_TURN_DOWN + NUM_MON_AFFINES]        = sAffineAnim_Mon_TurnDown_Flipped,
    [AFFINE_TURN_DOWN_SLOW + NUM_MON_AFFINES]   = sAffineAnim_Mon_TurnDownSlow_Flipped,
    [AFFINE_TURN_DOWN_SLIGHT + NUM_MON_AFFINES] = sAffineAnim_Mon_TurnDownSlight_Flipped,
    [AFFINE_TURN_UP_HIGH + NUM_MON_AFFINES]     = sAffineAnim_Mon_TurnUpHigh_Flipped,

    sAffineAnim_Mon_None, // ? Extra for some reason
};

static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = FONDO_0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_1,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = FONDO_0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xA
    },
    DUMMY_WIN_TEMPLATE
};

// - 1 excludes PBLOCK_CLR_NONE
static const u32 *const sPokeblocksPals[] =
{
    [PBLOCK_CLR_RED - 1]       = gPokeblockRed_Pal,
    [PBLOCK_CLR_BLUE - 1]      = gPokeblockBlue_Pal,
    [PBLOCK_CLR_PINK - 1]      = gPokeblockPink_Pal,
    [PBLOCK_CLR_GREEN - 1]     = gPokeblockGreen_Pal,
    [PBLOCK_CLR_YELLOW - 1]    = gPokeblockYellow_Pal,
    [PBLOCK_CLR_PURPLE - 1]    = gPokeblockPurple_Pal,
    [PBLOCK_CLR_INDIGO - 1]    = gPokeblockIndigo_Pal,
    [PBLOCK_CLR_BROWN - 1]     = gPokeblockBrown_Pal,
    [PBLOCK_CLR_LITE_BLUE - 1] = gPokeblockLiteBlue_Pal,
    [PBLOCK_CLR_OLIVE - 1]     = gPokeblockOlive_Pal,
    [PBLOCK_CLR_GRAY - 1]      = gPokeblockGray_Pal,
    [PBLOCK_CLR_BLACK - 1]     = gPokeblockBlack_Pal,
    [PBLOCK_CLR_WHITE - 1]     = gPokeblockWhite_Pal,
    [PBLOCK_CLR_GOLD - 1]      = gPokeblockGold_Pal
};

static const union AffineAnimCmd sAffineAnim_Still[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_MonNoFlip[] =
{
    sAffineAnim_Still
};

static const union AffineAnimCmd sAffineAnim_PokeblockCase_ThrowFromVertical[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 16, 1),
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_PokeblockCase_ThrowFromHorizontal[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 1),
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_PokeblockCase_Still[] =
{
    sAffineAnim_Still
};

static const union AffineAnimCmd *const sAffineAnims_PokeblockCase_ThrowFromVertical[] =
{
    sAffineAnim_PokeblockCase_ThrowFromVertical
};

static const union AffineAnimCmd *const sAffineAnims_PokeblockCase_ThrowFromHorizontal[] =
{
    sAffineAnim_PokeblockCase_ThrowFromHorizontal
};

static const struct OamData sOamData_Pokeblock =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_Pokeblock[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Pokeblock[] =
{
    sAnim_Pokeblock,
};

static const union AffineAnimCmd sAffineAnim_Pokeblock[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd *const sAffineAnims_Pokeblock[] =
{
    sAffineAnim_Pokeblock
};

static const struct CompressedSpriteSheet sSpriteSheet_Pokeblock =
{
    gPokeblock_Gfx, 0x20, TAG_POKEBLOCK
};

static const struct SpriteTemplate sSpriteTemplate_Pokeblock =
{
    .tileTag = TAG_POKEBLOCK,
    .paletteTag = TAG_POKEBLOCK,
    .oam = &sOamData_Pokeblock,
    .anims = sAnims_Pokeblock,
    .images = NULL,
    .affineAnims = sAffineAnims_Pokeblock,
    .callback = SpriteCB_ThrownPokeblock
};

static void CB2_PokeblockFeed(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    CopiaTilemapProgramadoVram();
    UpdatePaletteFade();
}

static void VBlankCB_PokeblockFeed(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 LoadPokeblockFeedScene(void)
{
    switch (gMain.state)
    {
    case 0:
        sPokeblockFeed = AllocZeroed(sizeof(*sPokeblockFeed));
        SetVBlankHBlankCallbacksToNull();
        LimpiaCopiaTilemapProgramadaVram();
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        gFundidoPaletas.transferenciaBufferDeshabilitada = TRUE;
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 4:
        AllocateMonSpritesGfx();
        gMain.state++;
        break;
    case 5:
        HandleInitBackgrounds();
        gMain.state++;
        break;
    case 6:
        HandleInitWindows();
        gMain.state++;
        break;
    case 7:
        if (LoadMonAndSceneGfx(&gPlayerParty[gPokeblockMonId]))
            gMain.state++;
        break;
    case 8:
        sPokeblockFeed->pokeblockCaseSpriteId = CreatePokeblockCaseSpriteForFeeding();
        gMain.state++;
        break;
    case 9:
        sPokeblockFeed->monSpriteId = CreateMonSprite(&gPlayerParty[gPokeblockMonId]);
        gMain.state++;
        break;
    case 10:
        DrawStdFrameWithCustomTileAndPalette(0, TRUE, 1, 14);
        gMain.state++;
        break;
    case 11:
        LaunchPokeblockFeedTask();
        gMain.state++;
        break;
    case 12:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 13:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_PokeblockFeed);
        SetMainCallback2(CB2_PokeblockFeed);
        return TRUE;
    }
    return FALSE;
}

void PreparePokeblockFeedScene(void)
{
    while(1)
    {
        if (LoadPokeblockFeedScene() == TRUE)
            break;
    }
}

static void HandleInitBackgrounds(void)
{
    ResetVramOamAndBgCntRegs();

    ResetBgsAndClearDma3BusyFlags();
    IniciaFondosDesdePlantillas(MODO_0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(1, sPokeblockFeed->tilemapBuffer);
    ResetAllBgsCoordinates();
    ProgramaCopiaTilemapVram(FONDO_1);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(1);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadMonAndSceneGfx(struct Pokemon *mon)
{
    u16 species;
    u32 personality;
    bool32 isShiny;

    switch (sPokeblockFeed->loadGfxState)
    {
    case 0:
        // Load mon gfx
        species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        HandleLoadSpecialPokePic(TRUE, gMonSpritesGfxPtr->spritesGfx[OPONENTE_IZQUIERDA], species, personality);
        sPokeblockFeed->loadGfxState++;
        break;
    case 1:
        // Load mon palette
        species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
        LoadCompressedSpritePaletteWithTag(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), species);
        SetMultiuseSpriteTemplateToPokemon(species, OPONENTE_IZQUIERDA);
        sPokeblockFeed->loadGfxState++;
        break;
    case 2:
        LoadCompressedSpriteSheet(&gPokeblockCase_SpriteSheet);
        sPokeblockFeed->loadGfxState++;
        break;
    case 3:
        LoadCompressedSpritePalette(&gPokeblockCase_SpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sSpriteSheet_Pokeblock);
        sPokeblockFeed->loadGfxState++;
        break;
    case 5:
        SetPokeblockSpritePal(gSpecialVar_ItemId);
        LoadCompressedSpritePalette(&sPokeblockSpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 6:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, gBattleTerrainTiles_Building, 0, 0, 0);
        sPokeblockFeed->loadGfxState++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(gPokeblockFeedBg_Tilemap, sPokeblockFeed->tilemapBuffer);
            sPokeblockFeed->loadGfxState++;
        }
        break;
    case 8:
        sPokeblockFeed->loadGfxState = 0;
        return TRUE;
    }

    return FALSE;
}

static void HandleInitWindows(void)
{
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    ProgramaCopiaTilemapVram(FONDO_0);
}

static void SetPokeblockSpritePal(u8 pokeblockCaseId)
{
    u8 colorId = GetPokeblockData(&gSaveBlockPtr->pokeblocks[pokeblockCaseId], PBLOCK_COLOR);
    sPokeblockSpritePal.data = sPokeblocksPals[colorId - 1];
    sPokeblockSpritePal.tag = TAG_POKEBLOCK;
}

// defines for task data fields

#define tState            data[0]
#define tHorizontalThrow  data[1]

#define STATE_START_THROW  255 // If the length of the Pokémon's animation exceeds 255 the throw may happen twice
#define STATE_SPAWN_PBLOCK (STATE_START_THROW + 14)
#define STATE_START_JUMP   (STATE_SPAWN_PBLOCK + 12)
#define STATE_PRINT_MSG    (STATE_START_JUMP + 16)

static void Task_HandlePokeblockFeed(u8 taskId)
{
    if (!gFundidoPaletas.activo)
    {
        switch (gTasks[taskId].tState)
        {
        case 0:
            sPokeblockFeed->animRunState = 0;
            sPokeblockFeed->timer = 0;
            CalculateMonAnimLength();
            break;
        case STATE_START_THROW:
            DoPokeblockCaseThrowEffect(sPokeblockFeed->pokeblockCaseSpriteId, gTasks[taskId].tHorizontalThrow);
            break;
        case STATE_SPAWN_PBLOCK:
            sPokeblockFeed->pokeblockSpriteId = CreatePokeblockSprite();
            break;
        case STATE_START_JUMP:
            StartMonJumpForPokeblock(sPokeblockFeed->monSpriteId);
            break;
        case STATE_PRINT_MSG:
            gTasks[taskId].func = Task_PrintAtePokeblockMessage;
            return;
        }

        if (sPokeblockFeed->timer < sPokeblockFeed->monAnimLength)
            UpdateMonAnim();
        else if (sPokeblockFeed->timer == sPokeblockFeed->monAnimLength)
            gTasks[taskId].tState = STATE_START_THROW - 1;

        sPokeblockFeed->timer++;
        gTasks[taskId].tState++;
    }
}

static void LaunchPokeblockFeedTask(void)
{
    u8 taskId = CreateTask(Task_HandlePokeblockFeed, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tHorizontalThrow = TRUE;
}

static void Task_WaitForAtePokeblockMessage(u8 taskId)
{
    if (RunTextPrintersRetIsActive(0) != TRUE)
        gTasks[taskId].func = Task_FadeOutPokeblockFeed;
}

static void Task_PrintAtePokeblockMessage(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPokeblockMonId];
    struct Pokeblock *pokeblock = &gSaveBlockPtr->pokeblocks[gSpecialVar_ItemId];

    gPokeblockGain = PokeblockGetGain(Naturaleza(mon), pokeblock);
    GetMonNickname(mon, gVariableTexto1);
    PokeblockCopyName(pokeblock, gVariableTexto2);

    if (gPokeblockGain == 0)
        StringExpandPlaceholders(gVariableTextoAmpliada, sText_Var1AteTheVar2);
    else if (gPokeblockGain > 0)
        StringExpandPlaceholders(gVariableTextoAmpliada, sText_Var1HappilyAteVar2);
    else
        StringExpandPlaceholders(gVariableTextoAmpliada, sText_Var1DisdainfullyAteVar2);

    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(0, FONT_NORMAL, gVariableTextoAmpliada, GetPlayerTextSpeedDelay(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    gTasks[taskId].func = Task_WaitForAtePokeblockMessage;
}

static void Task_ExitPokeblockFeed(u8 taskId)
{
    if (!gFundidoPaletas.activo)
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        Free(sPokeblockFeed);
        FreeMonSpritesGfx();
    }
}

static void Task_FadeOutPokeblockFeed(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitPokeblockFeed;
}

#undef tState
#undef tHorizontalThrow

// Sprite data for Pokéblock and Pokémon
#define sSpeed   data[0]
#define sAccel   data[1]
#define sSpecies data[2]

static u8 CreateMonSprite(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    u32 spriteId = CreateSprite(&gMultiuseSpriteTemplate, MON_X, MON_Y, 2);

    sPokeblockFeed->species = species;
    sPokeblockFeed->monSpriteId_ = spriteId;
    sPokeblockFeed->nature = Naturaleza(mon);
    gSprites[spriteId].sSpecies = species;
    gSprites[spriteId].callback = SpriteCallbackDummy;

    sPokeblockFeed->noMonFlip = TRUE;
    if (!IsMonSpriteNotFlipped(species))
    {
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_MonNoFlip;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        sPokeblockFeed->noMonFlip = FALSE;
    }

    return spriteId;
}

static void StartMonJumpForPokeblock(u32 spriteId)
{
    gSprites[spriteId].x = MON_X;
    gSprites[spriteId].y = MON_Y;
    gSprites[spriteId].sSpeed = -8;
    gSprites[spriteId].sAccel = 1;
    gSprites[spriteId].callback = SpriteCB_MonJumpForPokeblock;
}

static void SpriteCB_MonJumpForPokeblock(struct Sprite *sprite)
{
    sprite->x += 4;
    sprite->y += sprite->sSpeed;
    sprite->sSpeed += sprite->sAccel;

    // Play cry at jump peak
    if (sprite->sSpeed == 0)
        PlayCry_Normal(sprite->sSpecies, 0);

    if (sprite->sSpeed == 9)
        sprite->callback = SpriteCallbackDummy;
}

static u8 CreatePokeblockCaseSpriteForFeeding(void)
{
    u32 spriteId = CreatePokeblockCaseSprite(188, 100, 2);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].affineAnims = sAffineAnims_PokeblockCase_Still;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    return spriteId;
}

static void DoPokeblockCaseThrowEffect(u32 spriteId, bool8 horizontalThrow)
{
    FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;

    if (!horizontalThrow)
        gSprites[spriteId].affineAnims = sAffineAnims_PokeblockCase_ThrowFromVertical; // Never used, horizontalThrow always TRUE
    else
        gSprites[spriteId].affineAnims = sAffineAnims_PokeblockCase_ThrowFromHorizontal;

    InitSpriteAffineAnim(&gSprites[spriteId]);
}

static u8 CreatePokeblockSprite(void)
{
    u32 spriteId = CreateSprite(&sSpriteTemplate_Pokeblock, 174, 84, 1);
    gSprites[spriteId].sSpeed = -12;
    gSprites[spriteId].sAccel = 1;
    return spriteId;
}

static void SpriteCB_ThrownPokeblock(struct Sprite *sprite)
{
    sprite->x -= 4;
    sprite->y += sprite->sSpeed;
    sprite->sSpeed += sprite->sAccel;
    if (sprite->sSpeed == 10)
        DestroySprite(sprite);
}

static void CalculateMonAnimLength(void)
{

}

static void UpdateMonAnim(void)
{

}

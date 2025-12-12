#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/battle_anim.h"

static const struct OamData sVsLetter_V_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sVsLetter_S_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 64,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds0[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sVsLetterAffineAnimTable[] =
{
    sVsLetterAffineAnimCmds0,
    sVsLetterAffineAnimCmds1,
};

#define TAG_VS_LETTERS 10000

static const struct SpriteTemplate sVsLetter_V_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_V_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct SpriteTemplate sVsLetter_S_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_S_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct CompressedSpriteSheet sVsLettersSpriteSheet =
{
    gVsLettersGfx, 0x1000, TAG_VS_LETTERS
};

const struct BgTemplate gBattleBgTemplates[] =
{
    {
        .bg = FONDO_0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = FONDO_32x64,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = FONDO_32x64,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = FONDO_64x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = FONDO_3,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = FONDO_64x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 3,
        .baseTile = 0
    },
};

const struct WindowTemplate sBattleWindowTemplates[] =
{
    [B_WIN_MSG] = {
        .bg = FONDO_0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 19,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x0090,
    },
    [B_WIN_MOVE_NAME_1] = {
        .bg = FONDO_0,
        .tilemapLeft = 3,
        .tilemapTop = 54,
        .width = 9,
        .height = 3,
        .paletteNum = 12,
        .baseBlock = 768,
    },
    [B_WIN_MOVE_NAME_2] = {
        .bg = FONDO_0,
        .tilemapLeft = 18,
        .tilemapTop = 54,
        .width = 9,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 801,
    },
    [B_WIN_MOVE_NAME_3] = {
        .bg = FONDO_0,
        .tilemapLeft = 3,
        .tilemapTop = 57,
        .width = 9,
        .height = 3,
        .paletteNum = 14,
        .baseBlock = 834,
    },
    [B_WIN_MOVE_NAME_4] = {
        .bg = FONDO_0,
        .tilemapLeft = 18,
        .tilemapTop = 57,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 867,
    },
    [B_WIN_PP_1] = {
        .bg = FONDO_0,
        .tilemapLeft = 13,
        .tilemapTop = 54,
        .width = 2,
        .height = 3,
        .paletteNum = 12,
        .baseBlock = 656,
    },
    [B_WIN_PP_2] = {
        .bg = FONDO_0,
        .tilemapLeft = 28,
        .tilemapTop = 54,
        .width = 2,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 662,
    },
    [B_WIN_PP_3] = {
        .bg = FONDO_0,
        .tilemapLeft = 13,
        .tilemapTop = 57,
        .width = 2,
        .height = 3,
        .paletteNum = 14,
        .baseBlock = 668,
    },
    [B_WIN_PP_4] = {
        .bg = FONDO_0,
        .tilemapLeft = 28,
        .tilemapTop = 57,
        .width = 2,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 674,
    },
    [B_WIN_YESNO] = {
        .bg = FONDO_0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .bg = FONDO_1,
        .tilemapLeft = 19,
        .tilemapTop = 8,
        .width = 10,
        .height = 11,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .bg = FONDO_2,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x016e,
    },
    [B_WIN_VS_PLAYER] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_OPPONENT] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0060,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0080,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .bg = FONDO_0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .bg = FONDO_0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .bg = FONDO_0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00b0,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .bg = FONDO_0,
        .tilemapLeft = 1,
        .tilemapTop = 47,
        .width = 18,
        .height = 6,
        .paletteNum = 5,
        .baseBlock = 0x0350,
    },
    DUMMY_WIN_TEMPLATE
};

const struct BattleBackground sBattleTerrainTable[] =
{
    [BATTLE_TERRAIN_GRASS] =
    {
        .tileset = gBattleTerrainTiles_TallGrass,
        .tilemap = gBattleTerrainTilemap_TallGrass,
        .entryTileset = gBattleTerrainAnimTiles_TallGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_TallGrass,
        .palette = gBattleTerrainPalette_TallGrass,
    },

    [BATTLE_TERRAIN_LONG_GRASS] =
    {
        .tileset = gBattleTerrainTiles_LongGrass,
        .tilemap = gBattleTerrainTilemap_LongGrass,
        .entryTileset = gBattleTerrainAnimTiles_LongGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_LongGrass,
        .palette = gBattleTerrainPalette_LongGrass,
    },

    [BATTLE_TERRAIN_SAND] =
    {
        .tileset = gBattleTerrainTiles_Sand,
        .tilemap = gBattleTerrainTilemap_Sand,
        .entryTileset = gBattleTerrainAnimTiles_Sand,
        .entryTilemap = gBattleTerrainAnimTilemap_Sand,
        .palette = gBattleTerrainPalette_Sand,
    },

    [BATTLE_TERRAIN_UNDERWATER] =
    {
        .tileset = gBattleTerrainTiles_Underwater,
        .tilemap = gBattleTerrainTilemap_Underwater,
        .entryTileset = gBattleTerrainAnimTiles_Underwater,
        .entryTilemap = gBattleTerrainAnimTilemap_Underwater,
        .palette = gBattleTerrainPalette_Underwater,
    },

    [BATTLE_TERRAIN_WATER] =
    {
        .tileset = gBattleTerrainTiles_Water,
        .tilemap = gBattleTerrainTilemap_Water,
        .entryTileset = gBattleTerrainAnimTiles_Water,
        .entryTilemap = gBattleTerrainAnimTilemap_Water,
        .palette = gBattleTerrainPalette_Water,
    },

    [BATTLE_TERRAIN_POND] =
    {
        .tileset = gBattleTerrainTiles_PondWater,
        .tilemap = gBattleTerrainTilemap_PondWater,
        .entryTileset = gBattleTerrainAnimTiles_PondWater,
        .entryTilemap = gBattleTerrainAnimTilemap_PondWater,
        .palette = gBattleTerrainPalette_PondWater,
    },

    [BATTLE_TERRAIN_MOUNTAIN] =
    {
        .tileset = gBattleTerrainTiles_Rock,
        .tilemap = gBattleTerrainTilemap_Rock,
        .entryTileset = gBattleTerrainAnimTiles_Rock,
        .entryTilemap = gBattleTerrainAnimTilemap_Rock,
        .palette = gBattleTerrainPalette_Rock,
    },

    [BATTLE_TERRAIN_CAVE] =
    {
        .tileset = gBattleTerrainTiles_Cave,
        .tilemap = gBattleTerrainTilemap_Cave,
        .entryTileset = gBattleTerrainAnimTiles_Cave,
        .entryTilemap = gBattleTerrainAnimTilemap_Cave,
        .palette = gBattleTerrainPalette_Cave,
    },

    [BATTLE_TERRAIN_BUILDING] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Building,
    },

    [BATTLE_TERRAIN_PLAIN] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Plain,
    },
};

void BattleInitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags();
    InitBgsFromTemplates(0, gBattleBgTemplates, ARRAY_COUNT(gBattleBgTemplates));
    InitWindows(sBattleWindowTemplates);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    BattleInitBgsAndWindows();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

void LoadBattleMenuWindowGfx(void)
{
    LoadCompressedPalette(gBattleWindowTextPalette, BG_PLTT_ID(5), PLTT_SIZE_4BPP);
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & TIPO_BATALLA_LEGENDARIO)
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleTerrainTiles_Water, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleTerrainTiles_Rayquaza, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Rayquaza, (void*)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_Rayquaza, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        default:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
    else
    {
        if (EsContraEntrenador())
        {
            u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        default:
        case BATTLE_BACKGROUND_NORMAL:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_GYM:
            LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_MAGMA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_AQUA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_SIDNEY:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_PHOEBE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_GLACIA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_DRAKE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadCompressedPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    LoadBattleMenuWindowGfx();
    if (B_TERRAIN_BG_CHANGE == TRUE)
        DrawTerrainTypeBattleBackground();
    else
        DrawMainBattleBackground();
}

void DrawBattleEntryBackground(void)
{
    if (gBattleTypeFlags & TIPO_BATALLA_LEGENDARIO)
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleTerrainAnimTiles_Cave, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Cave, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleTerrainAnimTiles_Underwater, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Underwater, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleTerrainAnimTiles_Rayquaza, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Rayquaza, (void*)(BG_SCREEN_ADDR(28)));
            break;
        default:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
            break;
        }
    }
    else
    {
        if (EsContraEntrenador())
        {
            u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
        }

        if (GetCurrentMapBattleScene() == BATTLE_BACKGROUND_NORMAL)
        {
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadCompressedPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        break;
    case 3:
        if (gBattleTypeFlags & TIPO_BATALLA_LEGENDARIO)
        {
            switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
            {
            case SPECIES_GROUDON:
                LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
                break;
            case SPECIES_KYOGRE:
                LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(BG_SCREEN_ADDR(2)));
                break;
            }
        }
        else
        {
            if (EsContraEntrenador())
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_GYM:
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_AQUA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            }
        }
        break;
    case 4:
        if (gBattleTypeFlags & TIPO_BATALLA_LEGENDARIO)
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            else
                LZDecompressVram(gBattleTerrainTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        }
        else
        {
            if (EsContraEntrenador())
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_GYM:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_AQUA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            }
        }
        break;
    case 5:
        if (gBattleTypeFlags & TIPO_BATALLA_LEGENDARIO)
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LoadCompressedPalette(gBattleTerrainPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            else
                LoadCompressedPalette(gBattleTerrainPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else
        {
            if (EsContraEntrenador())
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LoadCompressedPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_GYM:
                LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_AQUA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            }
        }
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}

void DrawTerrainTypeBattleBackground(void)
{
    switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
    {
    case STATUS_FIELD_GRASSY_TERRAIN:
        LoadMoveBg(BG_GRASSY_TERRAIN);
        break;
    case STATUS_FIELD_MISTY_TERRAIN:
        LoadMoveBg(BG_MISTY_TERRAIN);
        break;
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        LoadMoveBg(BG_ELECTRIC_TERRAIN);
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        LoadMoveBg(BG_PSYCHIC_TERRAIN);
        break;
    default:
        DrawMainBattleBackground();
        break;
    }
}


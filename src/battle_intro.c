#include "global.h"
#include "depuracion_mgba.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "distorsion_fondo.h"
#include "task.h"
#include "trig.h"
#include "constants/trainers.h"

static void BattleIntroSlide1(u8);
static void BattleIntroSlide2(u8);
static void BattleIntroSlide3(u8);

static const u8 sBattleAnimBgCnts[] = {REG_OFFSET_BG0CNT, REG_OFFSET_BG1CNT, REG_OFFSET_BG2CNT, REG_OFFSET_BG3CNT};

static const TaskFunc sBattleIntroSlideFuncs[] =
{
    [BATTLE_TERRAIN_GRASS]      = BattleIntroSlide1,
    [BATTLE_TERRAIN_LONG_GRASS] = BattleIntroSlide1,
    [BATTLE_TERRAIN_SAND]       = BattleIntroSlide2,
    [BATTLE_TERRAIN_UNDERWATER] = BattleIntroSlide2,
    [BATTLE_TERRAIN_WATER]      = BattleIntroSlide2,
    [BATTLE_TERRAIN_POND]       = BattleIntroSlide1,
    [BATTLE_TERRAIN_MOUNTAIN]   = BattleIntroSlide1,
    [BATTLE_TERRAIN_CAVE]       = BattleIntroSlide1,
    [BATTLE_TERRAIN_BUILDING]   = BattleIntroSlide3,
    [BATTLE_TERRAIN_PLAIN]      = BattleIntroSlide3,
    // Sin entrada, CreateTask recibia NULL y la animacion de entrada no se
    // ejecutaba nunca: los sprites se quedaban con x2 != 0, el oponente no
    // llegaba a completar su comando y el combate se colgaba en PREPARA_VARS.
    [BATTLE_TERRAIN_SOARING]           = BattleIntroSlide3,
    [BATTLE_TERRAIN_SKY_PILLAR]        = BattleIntroSlide3,
    [BATTLE_TERRAIN_BURIAL_GROUND]     = BattleIntroSlide3,
    [BATTLE_TERRAIN_PUDDLE]            = BattleIntroSlide2,
    [BATTLE_TERRAIN_MARSH]             = BattleIntroSlide2,
    [BATTLE_TERRAIN_SWAMP]             = BattleIntroSlide2,
    [BATTLE_TERRAIN_SNOW]              = BattleIntroSlide1,
    [BATTLE_TERRAIN_ICE]               = BattleIntroSlide1,
    [BATTLE_TERRAIN_VOLCANO]           = BattleIntroSlide1,
    [BATTLE_TERRAIN_DISTORTION_WORLD]  = BattleIntroSlide3,
    [BATTLE_TERRAIN_SPACE]             = BattleIntroSlide3,
    [BATTLE_TERRAIN_ULTRA_SPACE]       = BattleIntroSlide3,
};

void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value)
{
    if (bgId < 4)
    {
        u32 bgCnt = GetGpuReg(sBattleAnimBgCnts[bgId]);
        switch (attributeId)
        {
        case BG_ANIM_SCREEN_SIZE:
            ((vBgCnt *)&bgCnt)->screenSize = value;
            break;
        case BG_ANIM_AREA_OVERFLOW_MODE:
            ((vBgCnt *)&bgCnt)->areaOverflowMode = value;
            break;
        case BG_ANIM_MOSAIC:
            ((vBgCnt *)&bgCnt)->mosaic = value;
            break;
        case BG_ANIM_CHAR_BASE_BLOCK:
            ((vBgCnt *)&bgCnt)->charBaseBlock = value;
            break;
        case BG_ANIM_PRIORITY:
            ((vBgCnt *)&bgCnt)->priority = value;
            break;
        case BG_ANIM_PALETTES_MODE:
            ((vBgCnt *)&bgCnt)->palettes = value;
            break;
        case BG_ANIM_SCREEN_BASE_BLOCK:
            ((vBgCnt *)&bgCnt)->screenBaseBlock = value;
            break;
        }

        SetGpuReg(sBattleAnimBgCnts[bgId], bgCnt);
    }
}

int GetAnimBgAttribute(u8 bgId, u8 attributeId)
{
    u32 bgCnt;

    if (bgId < 4)
    {
        bgCnt = GetGpuReg(sBattleAnimBgCnts[bgId]);
        switch (attributeId)
        {
        case BG_ANIM_SCREEN_SIZE:
            return ((vBgCnt *)&bgCnt)->screenSize;
        case BG_ANIM_AREA_OVERFLOW_MODE:
            return ((vBgCnt *)&bgCnt)->areaOverflowMode;
        case BG_ANIM_MOSAIC:
            return ((vBgCnt *)&bgCnt)->mosaic;
        case BG_ANIM_CHAR_BASE_BLOCK:
            return ((vBgCnt *)&bgCnt)->charBaseBlock;
        case BG_ANIM_PRIORITY:
            return ((vBgCnt *)&bgCnt)->priority;
        case BG_ANIM_PALETTES_MODE:
            return ((vBgCnt *)&bgCnt)->palettes;
        case BG_ANIM_SCREEN_BASE_BLOCK:
            return ((vBgCnt *)&bgCnt)->screenBaseBlock;
        }
    }

    return 0;
}

#define tState data[0]
#define tTerrain data[1]

void HandleIntroSlide(u8 terrain)
{
    u8 taskId;

    if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_KYOGRE)
    {
        terrain = BATTLE_TERRAIN_UNDERWATER;
        taskId = CreateTask(BattleIntroSlide2, 0);
    }
    else
    {
        TaskFunc funcion = terrain < ARRAY_COUNT(sBattleIntroSlideFuncs)
                         ? sBattleIntroSlideFuncs[terrain] : NULL;

        // Red de seguridad: sin funcion valida el combate se quedaria colgado
        // esperando a que termine una animacion que nunca arranca.
        if (funcion == NULL)
        {
            funcion = BattleIntroSlide3;
            terrain = BATTLE_TERRAIN_PLAIN;
        }
        taskId = CreateTask(funcion, 0);
    }

    gTasks[taskId].tState = 0;
    gTasks[taskId].tTerrain = terrain;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
}

static void BattleIntroSlideEnd(u8 taskId)
{
    DestroyTask(taskId);
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
}

static void BattleIntroSlide1(u8 taskId)
{
    u32 i;

    gBattle_BG1_X += 6;
    switch (gTasks[taskId].tState)
    {
    case 0:
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].tState++;
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].tState++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].tState++;
            gTasks[taskId].data[2] = ANCHO_PANTALLA;
            gTasks[taskId].data[3] = 32;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            gTasks[taskId].data[3]--;
        }
        else
        {
            if (gTasks[taskId].tTerrain == BATTLE_TERRAIN_LONG_GRASS)
            {
                if (gBattle_BG1_Y != (u16)(-80))
                    gBattle_BG1_Y -= 2;
            }
            else
            {
                if (gBattle_BG1_Y != (u16)(-56))
                    gBattle_BG1_Y -= 1;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < ALTURA_PANTALLA / 2; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < ALTURA_PANTALLA; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = -gTasks[taskId].data[2];

        if (gTasks[taskId].data[2] == 0)
        {
            gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_PARAR;
            gTasks[taskId].tState++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        BattleIntroSlideEnd(taskId);
        break;
    }
}

static void BattleIntroSlide2(u8 taskId)
{
    u32 i;

    switch (gTasks[taskId].tTerrain)
    {
    case BATTLE_TERRAIN_SAND:
    case BATTLE_TERRAIN_WATER:
        gBattle_BG1_X += 8;
        break;
    case BATTLE_TERRAIN_UNDERWATER:
        gBattle_BG1_X += 6;
        break;
    }

    if (gTasks[taskId].tTerrain == BATTLE_TERRAIN_WATER)
    {
        gBattle_BG1_Y = Cos2(gTasks[taskId].data[6]) / 512 - 8;
        if (gTasks[taskId].data[6] < 180)
            gTasks[taskId].data[6] += 4;
        else
            gTasks[taskId].data[6] += 6;

        if (gTasks[taskId].data[6] == 360)
            gTasks[taskId].data[6] = 0;
    }

    switch (gTasks[taskId].tState)
    {
    case 0:
        gTasks[taskId].data[4] = 16;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].tState++;
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].tState++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].tState++;
            gTasks[taskId].data[2] = ANCHO_PANTALLA;
            gTasks[taskId].data[3] = 32;
            gTasks[taskId].data[5] = 1;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            if (--gTasks[taskId].data[3] == 0)
            {
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(15, 0));
                SetGpuReg(REG_OFFSET_BLDY, 0);
            }
        }
        else
        {
            if ((gTasks[taskId].data[4] & 0x1F) && --gTasks[taskId].data[5] == 0)
            {
                gTasks[taskId].data[4] += 0xFF;
                gTasks[taskId].data[5] = 4;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < ALTURA_PANTALLA / 2; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < ALTURA_PANTALLA; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = -gTasks[taskId].data[2];

        if (gTasks[taskId].data[2] == 0)
        {
            gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_PARAR;
            gTasks[taskId].tState++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        BattleIntroSlideEnd(taskId);
        break;
    }

    if (gTasks[taskId].tState != 4)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[4], 0));
}

static void BattleIntroSlide3(u8 taskId)
{
    u32 i;

    gBattle_BG1_X += 8;
    switch (gTasks[taskId].tState)
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[4] = BLDALPHA_BLEND(8, 8);
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].tState++;
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].tState++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].tState++;
            gTasks[taskId].data[2] = ANCHO_PANTALLA;
            gTasks[taskId].data[3] = 32;
            gTasks[taskId].data[5] = 1;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            gTasks[taskId].data[3]--;
        }
        else
        {
            if ((gTasks[taskId].data[4] & 0xF) && --gTasks[taskId].data[5] == 0)
            {
                gTasks[taskId].data[4] += 0xFF;
                gTasks[taskId].data[5] = 6;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < ALTURA_PANTALLA / 2; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < ALTURA_PANTALLA; i++)
            gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = -gTasks[taskId].data[2];

        if (gTasks[taskId].data[2] == 0)
        {
            gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_PARAR;
            gTasks[taskId].tState++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        BattleIntroSlideEnd(taskId);
        break;
    }

    if (gTasks[taskId].tState != 4)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[4], 0));
}

void DrawBattlerOnBg(int bgId, u8 x, u8 y, u8 battlerPosition, u8 paletteId, u8 *tiles, u16 *tilemap, u16 tilesOffset)
{
    u32 i, j;
    int offset = tilesOffset;
    CopiaCpu16(gMonSpritesGfxPtr->spritesGfx[battlerPosition], tiles, BG_SCREEN_SIZE);
    CargaTilesFondo(bgId, tiles, 0x1000, tilesOffset);
    for (i = y; i < y + 8; i++)
    {
        for (j = x; j < x + 8; j++)
        {
            tilemap[i * 32 + j] = offset | (paletteId << 12);
            offset++;
        }
    }
    LoadBgTilemap(bgId, tilemap, BG_SCREEN_SIZE, 0);
}

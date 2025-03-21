#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_gimmick.h"
#include "battle_z_move.h"
#include "battle_setup.h"
#include "battle_util.h"
#include "item.h"
#include "palette.h"
#include "pokemon.h"
#include "sprite.h"
#include "util.h"

#include "data/gimmicks.h"

// Populates gBattleStruct->gimmick.usableGimmick for each battler.
void AssignUsableGimmicks(void)
{
    u32 battler, gimmick;
    for (battler = 0; battler < gBattlersCount; ++battler)
    {
        gBattleStruct->gimmick.usableGimmick[battler] = GIMMICK_NONE;
        for (gimmick = 0; gimmick < GIMMICKS_COUNT; ++gimmick)
        {
            if (CanActivateGimmick(battler, gimmick))
            {
                gBattleStruct->gimmick.usableGimmick[battler] = gimmick;
                break;
            }
        }
    }
}

// Returns whether a battler is able to use a gimmick. Checks consumption and gimmick specific functions.
bool32 CanActivateGimmick(u32 battler, enum Gimmick gimmick)
{
    return gGimmicksInfo[gimmick].CanActivate != NULL && gGimmicksInfo[gimmick].CanActivate(battler);
}

// Returns whether the player has a gimmick selected while in the move selection menu.
bool32 IsGimmickSelected(u32 battler, enum Gimmick gimmick)
{
    return FALSE;
}

// Sets a battler as having a gimmick active using their party index.
void SetActiveGimmick(u32 battler, enum Gimmick gimmick)
{
    gBattleStruct->gimmick.activeGimmick[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]] = gimmick;
}

// Returns a battler's active gimmick, if any.
enum Gimmick GetActiveGimmick(u32 battler)
{
    return gBattleStruct->gimmick.activeGimmick[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
}

// Returns whether a trainer mon is intended to use an unrestrictive gimmick via .useGimmick (i.e Tera).
bool32 ShouldTrainerBattlerUseGimmick(u32 battler, enum Gimmick gimmick)
{
    return FALSE;
}

// Returns whether a trainer has used a gimmick during a battle.
bool32 HasTrainerUsedGimmick(u32 battler, enum Gimmick gimmick)
{
    // Check whether partner battler has used gimmick or plans to during turn.
    if (EsContraEntrenador()
        && IsPartnerMonFromSameTrainer(battler)
        && (gBattleStruct->gimmick.activated[BATTLE_PARTNER(battler)][gimmick]
        || ((gBattleStruct->gimmick.toActivate & (1u << BATTLE_PARTNER(battler))
        && gBattleStruct->gimmick.usableGimmick[BATTLE_PARTNER(battler)] == gimmick))))
    {
        return TRUE;
    }
    // Otherwise, return whether current battler has used gimmick.
    else
    {
        return gBattleStruct->gimmick.activated[battler][gimmick];
    }
}

// Sets a gimmick as used by a trainer with checks for Multi Battles.
void SetGimmickAsActivated(u32 battler, enum Gimmick gimmick)
{
    gBattleStruct->gimmick.activated[battler][gimmick] = TRUE;
    if (EsContraEntrenador() && IsPartnerMonFromSameTrainer(battler))
        gBattleStruct->gimmick.activated[BATTLE_PARTNER(battler)][gimmick] = TRUE;
}

#define SINGLES_GIMMICK_TRIGGER_POS_X_OPTIMAL (30)
#define SINGLES_GIMMICK_TRIGGER_POS_X_PRIORITY (31)
#define SINGLES_GIMMICK_TRIGGER_POS_X_SLIDE (15)
#define SINGLES_GIMMICK_TRIGGER_POS_Y_DIFF (-11)

#define DOUBLES_GIMMICK_TRIGGER_POS_X_OPTIMAL (30)
#define DOUBLES_GIMMICK_TRIGGER_POS_X_PRIORITY (31)
#define DOUBLES_GIMMICK_TRIGGER_POS_X_SLIDE (15)
#define DOUBLES_GIMMICK_TRIGGER_POS_Y_DIFF (-4)

#define tBattler    data[0]
#define tHide       data[1]

void ChangeGimmickTriggerSprite(u32 spriteId, u32 animId)
{
    StartSpriteAnim(&gSprites[spriteId], animId);
}

bool32 IsGimmickTriggerSpriteActive(void)
{
    if (GetSpriteTileStartByTag(TAG_GIMMICK_TRIGGER_TILE) == 0xFFFF)
        return FALSE;
    else if (IndexOfSpritePaletteTag(TAG_GIMMICK_TRIGGER_PAL) != 0xFF)
        return TRUE;
    else
        return FALSE;
}

void HideGimmickTriggerSprite(void)
{
    if (gBattleStruct->gimmick.triggerSpriteId != 0xFF)
    {
        ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, 0);
        gSprites[gBattleStruct->gimmick.triggerSpriteId].tHide = TRUE;
    }
}

void DestroyGimmickTriggerSprite(void)
{
    FreeSpritePaletteByTag(TAG_GIMMICK_TRIGGER_PAL);
    FreeSpriteTilesByTag(TAG_GIMMICK_TRIGGER_TILE);
    if (gBattleStruct->gimmick.triggerSpriteId != 0xFF)
        DestroySprite(&gSprites[gBattleStruct->gimmick.triggerSpriteId]);
    gBattleStruct->gimmick.triggerSpriteId = 0xFF;
}

static void SpriteCb_GimmickTrigger(struct Sprite *sprite)
{
    s32 xSlide, xPriority, xOptimal;
    s32 yDiff;

    if (EsContraEntrenador())
    {
        xSlide = DOUBLES_GIMMICK_TRIGGER_POS_X_SLIDE;
        xPriority = DOUBLES_GIMMICK_TRIGGER_POS_X_PRIORITY;
        xOptimal = DOUBLES_GIMMICK_TRIGGER_POS_X_OPTIMAL;
        yDiff = DOUBLES_GIMMICK_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        xSlide = SINGLES_GIMMICK_TRIGGER_POS_X_SLIDE;
        xPriority = SINGLES_GIMMICK_TRIGGER_POS_X_PRIORITY;
        xOptimal = SINGLES_GIMMICK_TRIGGER_POS_X_OPTIMAL;
        yDiff = SINGLES_GIMMICK_TRIGGER_POS_Y_DIFF;
    }

    if (sprite->tHide)
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            sprite->x++;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
        if (sprite->x == gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            DestroyGimmickTriggerSprite();
    }
    else
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xOptimal)
            sprite->x--;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
    }
}

#undef tBattler
#undef tHide

// for sprite data fields
#define tBattler        data[0]
#define tPosX           data[2]
#define tLevelXDelta    data[3] // X position depends whether level has 3, 2 or 1 digit

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_Battler               data[6]

static void SpriteCb_GimmickIndicator(struct Sprite *sprite)
{
    u32 battler = sprite->tBattler;

    sprite->x = gSprites[gHealthboxSpriteIds[battler]].x + sprite->tPosX + sprite->tLevelXDelta;
    sprite->x2 = gSprites[gHealthboxSpriteIds[battler]].x2;
    sprite->y2 = gSprites[gHealthboxSpriteIds[battler]].y2;
}

static inline u32 GetIndicatorSpriteId(u32 healthboxId)
{
    return gBattleStruct->gimmick.indicatorSpriteId[gSprites[healthboxId].hMain_Battler];
}

u32 GetIndicatorTileTag(u32 battler)
{
    return TAG_NONE;
}

u32 GetIndicatorPalTag(u32 battler)
{
    return TAG_NONE;
}

void UpdateIndicatorVisibilityAndType(u32 healthboxId, bool32 invisible)
{
    u32 battler = gSprites[healthboxId].hMain_Battler;
    u32 tileTag = GetIndicatorTileTag(battler);
    u32 palTag = GetIndicatorPalTag(battler);
    struct Sprite *sprite = &gSprites[GetIndicatorSpriteId(healthboxId)];

    if (GetIndicatorSpriteId(healthboxId) == 0) // safari zone means the player doesn't have an indicator sprite id
        return;

    if (tileTag != TAG_NONE && palTag != TAG_NONE)
    {
        sprite->oam.tileNum = GetSpriteTileStartByTag(tileTag);
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(palTag);
        sprite->invisible = invisible;
    }
    else // in case of error
    {
        sprite->invisible = TRUE;
    }
}

void UpdateIndicatorOamPriority(u32 healthboxId, u32 oamPriority)
{
    gSprites[GetIndicatorSpriteId(healthboxId)].oam.priority = oamPriority;
}

void UpdateIndicatorLevelData(u32 healthboxId, u32 level)
{
    s32 xDelta = 0;

    if (level >= 100)
        xDelta -= 4;
    else if (level < 10)
        xDelta += 5;

    gSprites[GetIndicatorSpriteId(healthboxId)].tLevelXDelta = xDelta;
}

static const s8 sIndicatorPositions[][2] =
{
    [B_POSITION_PLAYER_LEFT] = {53, -9},
    [B_POSITION_OPPONENT_LEFT] = {44, -9},
    [B_POSITION_PLAYER_RIGHT] = {52, -9},
    [B_POSITION_OPPONENT_RIGHT] = {44, -9},
};

#undef tBattler
#undef tPosX
#undef tLevelXDelta

#undef hMain_Battler

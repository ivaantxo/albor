#include "global.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"

// Definidas en src/data/field_effects/field_effect_objects.h.
extern const struct SpritePalette gSpritePalette_GeneralFieldEffect0;
extern const struct SpritePalette gSpritePalette_GeneralFieldEffect1;
extern const struct SpritePalette gSpritePalette_SmallSparkle;
extern const struct SpritePalette gSpritePalette_Ash;
#include "constants/rgb.h"
#include "constants/songs.h"

#define OBJ_EVENT_PAL_TAG_NONE 0x11FF // duplicate of define in event_object_movement.c
#define PAL_TAG_REFLECTION_OFFSET 0x2000 // reflection tag value is paletteTag + 0x2000
#define PAL_RAW_REFLECTION_OFFSET 0x4000 // raw reflection tag is paletteNum + 0x4000
#define HIGH_BRIDGE_PAL_TAG 0x4010
// Build a unique tag for reflection's palette based on based tag, or paletteNum
#define REFLECTION_PAL_TAG(tag, num) ((tag) == TAG_NONE ? (num) + PAL_RAW_REFLECTION_OFFSET : (tag) + PAL_TAG_REFLECTION_OFFSET)

static void UpdateObjectReflectionSprite(struct Sprite *);
static void LoadObjectReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *sprite);
static void LoadObjectHighBridgeReflectionPalette(struct ObjectEvent *, struct Sprite *sprite);
static void LoadObjectRegularReflectionPalette(struct ObjectEvent *, struct Sprite *);

static void UpdateGrassFieldEffectSubpriority(struct Sprite *, u8, u8);
static void FadeFootprintsTireTracks_Step0(struct Sprite *);
static void FadeFootprintsTireTracks_Step1(struct Sprite *);
static void UpdateFeetInFlowingWaterFieldEffect(struct Sprite *);
static void UpdateAshFieldEffect_Wait(struct Sprite *);
static void UpdateAshFieldEffect_Show(struct Sprite *);
static void UpdateAshFieldEffect_End(struct Sprite *);
static void SpriteCB_BamboleoBajoElAgua(struct Sprite *);

// Data used by all the field effects that share UpdateJumpImpactEffect
#define sJumpElevation  data[0]
#define sJumpFldEff     data[1]

// Data used by all the field effects that share WaitFieldEffectSpriteAnim
#define sWaitFldEff  data[0]

#define sReflectionObjEventId       data[0]
#define sReflectionObjEventLocalId  data[1]
#define sReflectionVerticalOffset   data[2]
#define sIsStillReflection          data[7]

void SetUpShadow(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FldEff_Shadow(objectEvent->localId,
                  gSaveBlockPtr->location.mapNum,
                  gSaveBlockPtr->location.mapGroup);
}

void SetUpReflection(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 stillReflection)
{
    struct Sprite *reflectionSprite;

    reflectionSprite = &gSprites[CreateCopySpriteAt(sprite, sprite->x, sprite->y, 152)];
    reflectionSprite->callback = UpdateObjectReflectionSprite;
    reflectionSprite->oam.priority = 3;
    reflectionSprite->usingSheet = TRUE;
    reflectionSprite->anims = gDummySpriteAnimTable;
    StartSpriteAnim(reflectionSprite, 0);
    reflectionSprite->affineAnims = gDummySpriteAffineAnimTable;
    reflectionSprite->affineAnimBeginning = TRUE;
    reflectionSprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    reflectionSprite->subspriteTableNum = 0;
    reflectionSprite->sReflectionObjEventId = sprite->sReflectionObjEventId;
    reflectionSprite->sReflectionObjEventLocalId = objectEvent->localId;
    reflectionSprite->sIsStillReflection = stillReflection;
    LoadObjectReflectionPalette(objectEvent, reflectionSprite);

    if (!stillReflection)
        reflectionSprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
}

static s16 GetReflectionVerticalOffset(struct ObjectEvent *objectEvent)
{
    return GetObjectEventGraphicsInfo(objectEvent->graphicsId)->height - 2;
}

static void LoadObjectReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *reflectionSprite)
{
    u8 bridgeType;
    u16 bridgeReflectionVerticalOffsets[] = {
        [BRIDGE_TYPE_POND_LOW - 1] = 12,
        [BRIDGE_TYPE_POND_MED - 1] = 28,
        [BRIDGE_TYPE_POND_HIGH - 1] = 44
    };
    reflectionSprite->sReflectionVerticalOffset = 0;
    if ((bridgeType = MetatileBehavior_GetBridgeType(objectEvent->previousMetatileBehavior))
        || (bridgeType = MetatileBehavior_GetBridgeType(objectEvent->currentMetatileBehavior)))
    {
        reflectionSprite->sReflectionVerticalOffset = bridgeReflectionVerticalOffsets[bridgeType - 1];
        LoadObjectHighBridgeReflectionPalette(objectEvent, reflectionSprite);
    }
    else
    {
        LoadObjectRegularReflectionPalette(objectEvent, reflectionSprite);
    }
}

// Apply a blue tint effect to a palette
static void ApplyPondFilter(u8 paletteNum, u16 *dest)
{
    u32 i, r, g, b;
    u16 *src = gPlttBufferUnfaded + OBJ_PLTT_ID(paletteNum);
    *dest++ = *src++; // copy transparency
    for (i = 0; i < 16 - 1; i++)
    {
        r = GET_R(src[i]);
        g = GET_G(src[i]);
        b = GET_B(src[i]);
        b += 10;
        if (b > 31)
            b = 31;
        *dest++ = RGB2(r, g, b);
    }
}

// Apply a ice tint effect to a palette
static void ApplyIceFilter(u8 paletteNum, u16 *dest)
{
    u32 i, r, g, b;
    u16 *src = gPlttBufferUnfaded + OBJ_PLTT_ID(paletteNum);
    *dest++ = *src++; // copy transparency
    for (i = 0; i < 16 - 1; i++)
    {
        r = GET_R(src[i]);
        r -= 5;
        if (r > 31)
            r = 0;
        g = GET_G(src[i]);
        g += 3;
        if (g > 31)
            g = 31;
        b = GET_B(src[i]);
        b += 16;
        if (b > 31)
            b = 31;
        *dest++ = RGB2(r, g, b);
    }
}

static void LoadObjectRegularReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    const struct Sprite *mainSprite = &gSprites[objectEvent->spriteId];
    u16 baseTag = GetSpritePaletteTagByPaletteNum(mainSprite->oam.paletteNum);
    u16 paletteTag = REFLECTION_PAL_TAG(baseTag, mainSprite->oam.paletteNum);
    u32 paletteNum = IndexOfSpritePaletteTag(paletteTag);
    if (paletteNum <= 16)
    {
        // Load filtered palette
        u16 filteredData[16];
        struct SpritePalette filteredPal = {.tag = paletteTag, .data = filteredData};
        if (sprite->sIsStillReflection == FALSE)
            ApplyPondFilter(mainSprite->oam.paletteNum, filteredData);
        else
            ApplyIceFilter(mainSprite->oam.paletteNum, filteredData);
        paletteNum = LoadSpritePalette(&filteredPal);
        UpdateSpritePaletteWithWeather(paletteNum, TRUE);
    }
    sprite->oam.paletteNum = paletteNum;
    sprite->oam.objMode = ST_OAM_OBJ_BLEND;
}

// When walking on a bridge high above water (Route 120), the reflection is a solid dark blue color.
// This is so the sprite blends in with the dark water metatile underneath the bridge.
static void LoadObjectHighBridgeReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u16 blueData[16];
    struct SpritePalette bluePalette = {.tag = HIGH_BRIDGE_PAL_TAG, .data = blueData};
    CpuFill16(0x55C9, blueData, PLTT_SIZE_4BPP);
    sprite->oam.paletteNum = LoadSpritePalette(&bluePalette);
    UpdateSpritePaletteWithWeather(sprite->oam.paletteNum, TRUE);
}

static void UpdateObjectReflectionSprite(struct Sprite *reflectionSprite)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[reflectionSprite->sReflectionObjEventId];
    struct Sprite *mainSprite = &gSprites[objectEvent->spriteId];

    if (!objectEvent->active || !objectEvent->hasReflection || objectEvent->localId != reflectionSprite->sReflectionObjEventLocalId)
    {
        reflectionSprite->inUse = FALSE;
        FieldEffectFreePaletteIfUnused(reflectionSprite->oam.paletteNum);
        return;
    }

    // Only filter palette if not using the high bridge blue palette
    // This is basically a copy of LoadObjectRegularReflectionPalette
    if (IndexOfSpritePaletteTag(HIGH_BRIDGE_PAL_TAG) != reflectionSprite->oam.paletteNum)
    {
        u16 baseTag = GetSpritePaletteTagByPaletteNum(mainSprite->oam.paletteNum);
        u16 paletteTag = REFLECTION_PAL_TAG(baseTag, mainSprite->oam.paletteNum);
        u32 paletteNum = IndexOfSpritePaletteTag(paletteTag);
        if (paletteNum >= 16)
        {
            // Build filtered palette
            u16 filteredData[16];
            struct SpritePalette filteredPal = {.tag = paletteTag, .data = filteredData};
            // Free palette if unused
            reflectionSprite->inUse = FALSE;
            FieldEffectFreePaletteIfUnused(reflectionSprite->oam.paletteNum);
            reflectionSprite->inUse = TRUE;
            if (reflectionSprite->sIsStillReflection == FALSE)
                ApplyPondFilter(mainSprite->oam.paletteNum, filteredData);
            else
                ApplyIceFilter(mainSprite->oam.paletteNum, filteredData);
            paletteNum = LoadSpritePalette(&filteredPal);
            UpdateSpritePaletteWithWeather(paletteNum, TRUE);
        }
        reflectionSprite->oam.paletteNum = paletteNum;
    }
    reflectionSprite->oam.shape = mainSprite->oam.shape;
    reflectionSprite->oam.size = mainSprite->oam.size;
    reflectionSprite->oam.matrixNum = mainSprite->oam.matrixNum | ST_OAM_VFLIP;
    reflectionSprite->oam.tileNum = mainSprite->oam.tileNum;
    reflectionSprite->subspriteTables = mainSprite->subspriteTables;
    reflectionSprite->invisible = mainSprite->invisible;
    reflectionSprite->x = mainSprite->x;
    // sReflectionVerticalOffset is only set for high bridges
    reflectionSprite->y = mainSprite->y + GetReflectionVerticalOffset(objectEvent) + reflectionSprite->sReflectionVerticalOffset;
    reflectionSprite->centerToCornerVecX = mainSprite->centerToCornerVecX;
    reflectionSprite->centerToCornerVecY = mainSprite->centerToCornerVecY;
    reflectionSprite->x2 = mainSprite->x2;
    reflectionSprite->y2 = -mainSprite->y2;
    reflectionSprite->coordOffsetEnabled = mainSprite->coordOffsetEnabled;

    if (objectEvent->hideReflection == TRUE)
        reflectionSprite->invisible = TRUE;

    // Support "virtual" sprites which can't be rotated via affines
    if (reflectionSprite->subspriteTables[0].subsprites)
    {
        reflectionSprite->oam.affineMode = ST_OAM_AFFINE_OFF;
        return;
    }
    if (reflectionSprite->sIsStillReflection == FALSE)
    {
        // Sets the reflection sprite's rot/scale matrix to the correct
        // water reflection matrix based on the main sprite's facing direction.
        // If the sprite is facing east, then it's flipped, and its matrixNum is 1.
        reflectionSprite->oam.matrixNum = (mainSprite->oam.matrixNum & ST_OAM_HFLIP) ? 1 : 0;
    }
}

#undef sReflectionObjEventId
#undef sReflectionObjEventLocalId
#undef sReflectionVerticalOffset
#undef sIsStillReflection

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#define sPrevX data[0]
#define sPrevY data[1]

u8 CreateWarpArrowSprite(void)
{
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ARROW], 0, 0, 82);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        // Can use either gender's palette, so try to use the one that should be loaded
        sprite->oam.paletteNum = LoadPlayerObjectEventPalette(gSaveBlockPtr->playerGender);
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->invisible = TRUE;
    }
    return spriteId;
}

void SetSpriteInvisible(u32 spriteId)
{
    gSprites[spriteId].invisible = TRUE;
}

void ShowWarpArrowSprite(u32 spriteId, u8 direction, s16 x, s16 y)
{
    struct Sprite *sprite = &gSprites[spriteId];
    if (sprite->invisible || sprite->sPrevX != x || sprite->sPrevY != y)
    {
        s16 x2, y2;
        SetSpritePosToMapCoords(x, y, &x2, &y2);
        sprite = &gSprites[spriteId];
        sprite->x = x2 + 8;
        sprite->y = y2 + 8;
        sprite->invisible = FALSE;
        sprite->sPrevX = x;
        sprite->sPrevY = y;
        StartSpriteAnim(sprite, direction - 1);
    }
}

#undef sPrevX
#undef sPrevY

static const u8 sShadowEffectTemplateIds[] = {
    FLDEFFOBJ_SHADOW_S,
    FLDEFFOBJ_SHADOW_M,
    FLDEFFOBJ_SHADOW_L,
    FLDEFFOBJ_SHADOW_XL
};

const u16 gShadowVerticalOffsets[] = {
    4,
    4,
    4,
    16
};

// La sombra gasta un unico color, el indice 9, y en negro: lo que la hace
// sombra es la mezcla del OAM -ST_OAM_OBJ_BLEND-, no el color. Antes se colgaba
// de la paleta del clima solo para tomar prestado ese negro, y cualquier cambio
// de etiqueta la dejaba con la paleta de otro.
static const u16 sPaletaSombra[16] = { [9] = RGB_BLACK };
static const struct SpritePalette sFichaPaletaSombra = { sPaletaSombra, PALTAG_SOMBRA };

// Sprite data for FLDEFF_SHADOW
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sYOffset  data[3]

void FldEff_Shadow(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_SHADOW);

    u32 objectEventId;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    u32 spriteId;
    s32 i;
    for (i = MAX_SPRITES - 1; i > -1; i--)
    { // Search backwards, because of CreateSpriteAtEnd
        // Return early if a shadow sprite already exists
        if (gSprites[i].data[0] == localId && gSprites[i].callback == UpdateShadowFieldEffect)
            return;
    }
    objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
    if (graphicsInfo->shadowSize == SHADOW_SIZE_NONE) // don't create a shadow at all
        return;
    LoadSpriteSheetByTemplate(gFieldEffectObjectTemplatePointers[sShadowEffectTemplateIds[graphicsInfo->shadowSize]], 0, 0);
    LoadSpritePalette(&sFichaPaletaSombra);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[sShadowEffectTemplateIds[graphicsInfo->shadowSize]], 0, 0, 0x94 + 1); // higher = farther back; shadows should be behind object events
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].sLocalId = localId;
        gSprites[spriteId].sMapNum = mapNum;
        gSprites[spriteId].sMapGroup = mapGroup;
        gSprites[spriteId].sYOffset = (graphicsInfo->height >> 1) - gShadowVerticalOffsets[graphicsInfo->shadowSize];
    }
    return;
}

void UpdateShadowFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
    {
        FieldEffectStop(sprite, FLDEFF_SHADOW);
    }
    else
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->oam.priority = linkedSprite->oam.priority;
        sprite->x = linkedSprite->x;
        sprite->y = linkedSprite->y + sprite->sYOffset;
        sprite->invisible = linkedSprite->invisible;
        if (!objectEvent->active
         || objectEvent->inHotSprings
         || objectEvent->inSandPile
         || MetatileBehavior_IsPokeGrass(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsPuddle(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(objectEvent->previousMetatileBehavior))
        {
            FieldEffectStop(sprite, FLDEFF_SHADOW);
        }
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sYOffset

// Sprite data for FLDEFF_TALL_GRASS and FLDEFF_LONG_GRASS
#define sElevation   data[0]
#define sX           data[1]
#define sY           data[2]
#define sMapNum      data[3]      // Lower 8 bits
#define sLocalId     data[3] >> 8 // Upper 8 bits
#define sMapGroup    data[4]
#define sCurrentMap  data[5]
#define sObjectMoved data[7]

void FldEff_TallGrass(s16 x, s16 y, u8 elevacion, u8 prioridad, u16 objetoYMapa, u8 mapGroup, u16 mapaActual, bool8 saltarAnimacion)
{
    FieldEffectActiveListAdd(FLDEFF_TALL_GRASS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 spriteId;
    // Ojo: SetSpritePosToOffsetMapCoords modifica lo que se le pasa. El sprite
    // se coloca con las coordenadas de pantalla, pero guarda las de mapa, que son
    // las que usa despues para saber si sigue donde tiene que estar.
    s16 pantallaX = x;
    s16 pantallaY = y;

    SetSpritePosToOffsetMapCoords(&pantallaX, &pantallaY, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_TALL_GRASS], pantallaX, pantallaY, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sElevation = elevacion;
        sprite->sX = x;
        sprite->sY = y;
        sprite->sMapNum = objetoYMapa; // Also sLocalId
        sprite->sMapGroup = mapGroup;
        sprite->sCurrentMap = mapaActual;

        if (saltarAnimacion)
            SeekSpriteAnim(sprite, 4); // Skip to end of anim
    }
    return;
}

void UpdateTallGrassFieldEffect(struct Sprite *sprite)
{
    u8 metatileBehavior;
    u8 localId;
    u32 objectEventId;
    u8 mapNum = sprite->sCurrentMap >> 8;
    u8 mapGroup = sprite->sCurrentMap;

    if (gCamera.active && (gSaveBlockPtr->location.mapNum != mapNum || gSaveBlockPtr->location.mapGroup != mapGroup))
    {
        sprite->sX -= gCamera.x;
        sprite->sY -= gCamera.y;
        sprite->sCurrentMap = ((u8)gSaveBlockPtr->location.mapNum << 8) | (u8)gSaveBlockPtr->location.mapGroup;
    }
    localId = sprite->sLocalId;
    mapNum = sprite->sMapNum;
    mapGroup = sprite->sMapGroup;
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->sX, sprite->sY);

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
     || !MetatileBehavior_IsTallGrass(metatileBehavior)
     || (sprite->sObjectMoved && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_TALL_GRASS);
    }
    else
    {
        // Check if the object that triggered the effect has moved away
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        if ((objectEvent->currentCoords.x != sprite->sX || objectEvent->currentCoords.y != sprite->sY)
        && (objectEvent->previousCoords.x != sprite->sX || objectEvent->previousCoords.y != sprite->sY))
            sprite->sObjectMoved = TRUE;

        // Metatile behavior var re-used as subpriority
        metatileBehavior = 0;
        if (sprite->animCmdIndex == 0)
            metatileBehavior = 4;

        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        UpdateGrassFieldEffectSubpriority(sprite, sprite->sElevation, metatileBehavior);
    }
}

void FldEff_JumpTallGrass(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_JUMP_TALL_GRASS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_TALL_GRASS], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sJumpElevation = subprioridad;
        sprite->sJumpFldEff = FLDEFF_JUMP_TALL_GRASS;
    }
    return;
}

u8 FindTallGrassFieldEffectSpriteId(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u32 i;
    for (i = 0; i < MAX_SPRITES; i ++)
    {
        if (gSprites[i].inUse)
        {
            struct Sprite *sprite = &gSprites[i];
            if (sprite->callback == UpdateTallGrassFieldEffect
                && (x == sprite->sX && y == sprite->sY)
                && localId == (u8)(sprite->sLocalId)
                && mapNum == (sprite->sMapNum & 0xFF)
                && mapGroup == sprite->sMapGroup)
                return i;
        }
    }
    return MAX_SPRITES;
}

void FldEff_LongGrass(s16 x, s16 y, u8 elevacion, u16 objetoYMapa, u8 mapGroup, u16 mapaActual, bool8 saltarAnimacion)
{
    FieldEffectActiveListAdd(FLDEFF_LONG_GRASS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 spriteId;
    // Ojo: SetSpritePosToOffsetMapCoords modifica lo que se le pasa. El sprite
    // se coloca con las coordenadas de pantalla, pero guarda las de mapa, que son
    // las que usa despues para saber si sigue donde tiene que estar.
    s16 pantallaX = x;
    s16 pantallaY = y;

    SetSpritePosToOffsetMapCoords(&pantallaX, &pantallaY, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_LONG_GRASS], pantallaX, pantallaY, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = ElevationToPriority(elevacion);
        sprite->sElevation = elevacion;
        sprite->sX = x;
        sprite->sY = y;
        sprite->sMapNum = objetoYMapa; // Also sLocalId
        sprite->sMapGroup = mapGroup;
        sprite->sCurrentMap = mapaActual;

        if (saltarAnimacion)
            SeekSpriteAnim(sprite, 6); // Skip to end of anim
    }
    return;
}

void UpdateLongGrassFieldEffect(struct Sprite *sprite)
{
    u8 metatileBehavior;
    u8 localId;
    u32 objectEventId;
    u8 mapNum = sprite->sCurrentMap >> 8;
    u8 mapGroup = sprite->sCurrentMap;

    if (gCamera.active && (gSaveBlockPtr->location.mapNum != mapNum || gSaveBlockPtr->location.mapGroup != mapGroup))
    {
        sprite->sX -= gCamera.x;
        sprite->sY -= gCamera.y;
        sprite->sCurrentMap = ((u8)gSaveBlockPtr->location.mapNum << 8) | (u8)gSaveBlockPtr->location.mapGroup;
    }
    localId = sprite->sLocalId;
    mapNum = sprite->sMapNum;
    mapGroup = sprite->sMapGroup;
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->sX, sprite->sY);
    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
     || !MetatileBehavior_IsLongGrass(metatileBehavior)
     || (sprite->sObjectMoved && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_LONG_GRASS);
    }
    else
    {
        // Check if the object that triggered the effect has moved away
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        if ((objectEvent->currentCoords.x != sprite->sX || objectEvent->currentCoords.y != sprite->sY)
         && (objectEvent->previousCoords.x != sprite->sX || objectEvent->previousCoords.y != sprite->sY))
            sprite->sObjectMoved = TRUE;

        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        UpdateGrassFieldEffectSubpriority(sprite, sprite->sElevation, 0);
    }
}

#undef sElevation
#undef sX
#undef sY
#undef sMapNum
#undef sLocalId
#undef sMapGroup
#undef sCurrentMap
#undef sObjectMoved

// Effectively unused as it's not possible in vanilla to jump onto long grass (no adjacent ledges, and can't ride the Acro Bike in it).
// The graphics for this effect do not visually correspond to long grass either. Perhaps these graphics were its original design?
void FldEff_JumpLongGrass(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_JUMP_LONG_GRASS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_LONG_GRASS], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sJumpElevation = subprioridad;
        sprite->sJumpFldEff = FLDEFF_JUMP_LONG_GRASS;
    }
    return;
}

// Sprite data for FLDEFF_SHORT_GRASS
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

void FldEff_ShortGrass(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_SHORT_GRASS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SHORT_GRASS], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &(gSprites[spriteId]);
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = localId;
        sprite->sMapNum = mapNum;
        sprite->sMapGroup = mapGroup;
        sprite->sPrevX = gSprites[objectEvent->spriteId].x;
        sprite->sPrevY = gSprites[objectEvent->spriteId].y;
    }
    return;
}

void UpdateShortGrassFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inShortGrass)
    {
        FieldEffectStop(sprite, FLDEFF_SHORT_GRASS);
    }
    else
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
        struct Sprite *linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        s16 parentY = linkedSprite->y;
        s16 parentX = linkedSprite->x;
        if (parentX != sprite->sPrevX || parentY != sprite->sPrevY)
        {
            // Parent sprite moved, try to restart the animation
            sprite->sPrevX = parentX;
            sprite->sPrevY = parentY;
            if (sprite->animEnded)
                StartSpriteAnim(sprite, 0);
        }
        sprite->x = parentX;
        sprite->y = parentY;
        // Offset the grass sprite halfway down the parent sprite.
        sprite->y2 = (graphicsInfo->height >> 1) - 8;
        sprite->subpriority = linkedSprite->subpriority - 1;
        sprite->oam.priority = linkedSprite->oam.priority;
        UpdateObjectEventSpriteInvisibility(sprite, linkedSprite->invisible);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

// Sprite data for FLDEFF_SAND_FOOTPRINTS, FLDEFF_DEEP_SAND_FOOTPRINTS, and FLDEFF_BIKE_TIRE_TRACKS
#define sState   data[0]
#define sTimer   data[1]
#define sFldEff  data[7]

void FldEff_SandFootprints(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_SAND_FOOTPRINTS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SAND_FOOTPRINTS], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sFldEff = FLDEFF_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void FldEff_DeepSandFootprints(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_DEEP_SAND_FOOTPRINTS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_DEEP_SAND_FOOTPRINTS], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sFldEff = FLDEFF_DEEP_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void FldEff_TracksBug(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_TRACKS_BUG);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;
    struct Sprite *sprite;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_TRACKS_BUG], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->data[7] = FLDEFF_TRACKS_BUG;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void FldEff_TracksSpot(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_TRACKS_SPOT);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;
    struct Sprite *sprite;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_TRACKS_SPOT], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->data[7] = FLDEFF_TRACKS_SPOT;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void FldEff_BikeTireTracks(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_BIKE_TIRE_TRACKS);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_BIKE_TIRE_TRACKS], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sFldEff = FLDEFF_BIKE_TIRE_TRACKS;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void FldEff_TracksSlither(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion)
{
    FieldEffectActiveListAdd(FLDEFF_TRACKS_SLITHER);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;
    struct Sprite *sprite;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_TRACKS_SLITHER], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->data[7] = FLDEFF_TRACKS_SLITHER;
        StartSpriteAnim(sprite, animacion);
    }
    return;
}

void (*const gFadeFootprintsTireTracksFuncs[])(struct Sprite *) = {
    FadeFootprintsTireTracks_Step0,
    FadeFootprintsTireTracks_Step1
};

void UpdateFootprintsTireTracksFieldEffect(struct Sprite *sprite)
{
    gFadeFootprintsTireTracksFuncs[sprite->sState](sprite);
}

static void FadeFootprintsTireTracks_Step0(struct Sprite *sprite)
{
    // Wait 40 frames before the flickering starts.
    if (++sprite->sTimer > 40)
        sprite->sState = 1;

    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
}

static void FadeFootprintsTireTracks_Step1(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    sprite->sTimer++;
    UpdateObjectEventSpriteInvisibility(sprite, sprite->invisible);
    if (sprite->sTimer > 56)
        FieldEffectStop(sprite, sprite->sFldEff);
}

#undef sState
#undef sTimer
#undef sFldEff

// Sprite data for FLDEFF_SPLASH
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]

void FldEff_Splash(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_SPLASH);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPLASH], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *linkedSprite;
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->oam.priority = linkedSprite->oam.priority;
        sprite->sLocalId = localId;
        sprite->sMapNum = mapNum;
        sprite->sMapGroup = mapGroup;
        sprite->y2 = (graphicsInfo->height >> 1) - 4;
        PlaySE(SE_PUDDLE);
    }
    return;
}

void UpdateSplashFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (sprite->animEnded || TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
    {
        FieldEffectStop(sprite, FLDEFF_SPLASH);
    }
    else
    {
        sprite->x = gSprites[gObjectEvents[objectEventId].spriteId].x;
        sprite->y = gSprites[gObjectEvents[objectEventId].spriteId].y;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup

void FldEff_JumpSmallSplash(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_JUMP_SMALL_SPLASH);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_SMALL_SPLASH], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sJumpElevation = subprioridad;
        sprite->sJumpFldEff = FLDEFF_JUMP_SMALL_SPLASH;
    }
    return;
}

void FldEff_JumpBigSplash(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_JUMP_BIG_SPLASH);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_BIG_SPLASH], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sJumpElevation = subprioridad;
        sprite->sJumpFldEff = FLDEFF_JUMP_BIG_SPLASH;
    }
    return;
}

// Sprite data for FLDEFF_FEET_IN_FLOWING_WATER
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

void FldEff_FeetInFlowingWater(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_FEET_IN_FLOWING_WATER);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPLASH], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->callback = UpdateFeetInFlowingWaterFieldEffect;
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = localId;
        sprite->sMapNum = mapNum;
        sprite->sMapGroup = mapGroup;
        sprite->sPrevX = -1;
        sprite->sPrevY = -1;
        sprite->y2 = (graphicsInfo->height >> 1) - 4;
        StartSpriteAnim(sprite, 1);
    }
    return;
}

static void UpdateFeetInFlowingWaterFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inShallowFlowingWater)
    {
        FieldEffectStop(sprite, FLDEFF_FEET_IN_FLOWING_WATER);
    }
    else
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->x = linkedSprite->x;
        sprite->y = linkedSprite->y;
        sprite->subpriority = linkedSprite->subpriority;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        if (objectEvent->currentCoords.x != sprite->sPrevX || objectEvent->currentCoords.y != sprite->sPrevY)
        {
            sprite->sPrevX = objectEvent->currentCoords.x;
            sprite->sPrevY = objectEvent->currentCoords.y;
            if (!sprite->invisible)
                PlaySE(SE_PUDDLE);
        }
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

void FldEff_Ripple(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_RIPPLE);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_RIPPLE], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sWaitFldEff = FLDEFF_RIPPLE;
    }
    return;
}

// Sprite data for FLDEFF_HOT_SPRINGS_WATER
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

void FldEff_HotSpringsWater(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_HOT_SPRINGS_WATER);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect1);

    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_HOT_SPRINGS_WATER], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = localId;
        sprite->sMapNum = mapNum;
        sprite->sMapGroup = mapGroup;
        sprite->sPrevX = gSprites[objectEvent->spriteId].x; // Unused
        sprite->sPrevY = gSprites[objectEvent->spriteId].y; // Unused
    }
    return;
}

void UpdateHotSpringsWaterFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inHotSprings)
    {
        FieldEffectStop(sprite, FLDEFF_HOT_SPRINGS_WATER);
    }
    else
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
        struct Sprite *linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        sprite->x = linkedSprite->x;
        sprite->y = (graphicsInfo->height >> 1) + linkedSprite->y - 8;
        sprite->subpriority = linkedSprite->subpriority - 1;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

void FldEff_WaterSurfacing(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_WATER_SURFACING);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_WATER_SURFACING], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sWaitFldEff = FLDEFF_WATER_SURFACING;
    }
    return;
}

// Sprite data for FLDEFF_ASH
#define sState      data[0]
#define sX          data[1]
#define sY          data[2]
#define sMetatileId data[3]
#define sDelay      data[4]

void StartAshFieldEffect(s16 x, s16 y, u16 metatileId, s16 delay)
{
    FldEff_Ash(x, y, 82, 1, metatileId, delay);
}

void FldEff_Ash(s16 x, s16 y, u8 subprioridad, u8 prioridad, u16 metatile, u8 retardo)
{
    FieldEffectActiveListAdd(FLDEFF_ASH);
    CargaPaletaDeEfecto(&gSpritePalette_Ash);

    u32 spriteId;

    // Ojo: SetSpritePosToOffsetMapCoords modifica lo que se le pasa. El sprite
    // se coloca con las coordenadas de pantalla, pero guarda las de mapa, que son
    // las que usa despues para saber si sigue donde tiene que estar.
    s16 pantallaX = x;
    s16 pantallaY = y;

    SetSpritePosToOffsetMapCoords(&pantallaX, &pantallaY, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ASH], pantallaX, pantallaY, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sX = x;
        sprite->sY = y;
        sprite->sMetatileId = metatile;
        sprite->sDelay = retardo;
    }
    return;
}

void (*const gAshFieldEffectFuncs[])(struct Sprite *) = {
    UpdateAshFieldEffect_Wait,
    UpdateAshFieldEffect_Show,
    UpdateAshFieldEffect_End
};

void UpdateAshFieldEffect(struct Sprite *sprite)
{
    gAshFieldEffectFuncs[sprite->sState](sprite);
}

static void UpdateAshFieldEffect_Wait(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
    sprite->animPaused = TRUE;
    if (--sprite->sDelay == 0)
        sprite->sState = 1;
}

static void UpdateAshFieldEffect_Show(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    sprite->animPaused = FALSE;
    MapGridSetMetatileIdAt(sprite->sX, sprite->sY, sprite->sMetatileId);
    CurrentMapDrawMetatileAt(sprite->sX, sprite->sY);
    gObjectEvents[gPlayerAvatar.objectEventId].triggerGroundEffectsOnMove = TRUE;
    sprite->sState = 2;
}

static void UpdateAshFieldEffect_End(struct Sprite *sprite)
{
    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_ASH);
}

#undef sState
#undef sX
#undef sY
#undef sMetatileId
#undef sDelay

// Datos del sprite invisible que lleva el bamboleo.
#define sSpriteId data[0]
#define sBobY     data[1]
#define sTimer    data[2]

// Bambolea arriba y abajo el sprite que se le pase, que buceando es el del
// propio jugador. Se hace con un sprite invisible aparte porque el que se
// bambolea tiene ya su propio callback y no se le puede quitar.
u8 EmpiezaBamboleoBajoElAgua(u8 spriteIdABambolear)
{
    u32 spriteId = CreateSpriteAtEnd(&gDummySpriteTemplate, 0, 0, -1);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->callback = SpriteCB_BamboleoBajoElAgua;
    sprite->invisible = TRUE;
    sprite->sSpriteId = spriteIdABambolear;
    sprite->sBobY = 1;
    return spriteId;
}

static void SpriteCB_BamboleoBajoElAgua(struct Sprite *sprite)
{
    struct Sprite *bamboleado = &gSprites[sprite->sSpriteId];

    if (((sprite->sTimer++) & 3) == 0)
        bamboleado->y2 += sprite->sBobY;
    // Reverse direction
    if ((sprite->sTimer & 15) == 0)
        sprite->sBobY = -sprite->sBobY;
}

#undef sSpriteId
#undef sBobY
#undef sTimer

void FldEff_Dust(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_DUST);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_GROUND_IMPACT_DUST], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        sprite->sJumpElevation = subprioridad;
        sprite->sJumpFldEff = FLDEFF_DUST;
    }
    return;
}

// Sprite data for FLDEFF_SAND_PILE
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

void FldEff_SandPile(u8 localId, u8 mapNum, u8 mapGroup)
{
    FieldEffectActiveListAdd(FLDEFF_SAND_PILE);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u32 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SAND_PILE], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = localId;
        sprite->sMapNum = mapNum;
        sprite->sMapGroup = mapGroup;
        sprite->sPrevX = gSprites[objectEvent->spriteId].x;
        sprite->sPrevY = gSprites[objectEvent->spriteId].y;
        sprite->y2 = (graphicsInfo->height >> 1) - 2;
        SeekSpriteAnim(sprite, 2);
    }
    return;
}

void UpdateSandPileFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inSandPile)
    {
        FieldEffectStop(sprite, FLDEFF_SAND_PILE);
    }
    else
    {
        s16 parentY = gSprites[gObjectEvents[objectEventId].spriteId].y;
        s16 parentX = gSprites[gObjectEvents[objectEventId].spriteId].x;
        if (parentX != sprite->sPrevX || parentY != sprite->sPrevY)
        {
            sprite->sPrevX = parentX;
            sprite->sPrevY = parentY;
            if (sprite->animEnded)
                StartSpriteAnim(sprite, 0);
        }
        sprite->x = parentX;
        sprite->y = parentY;
        sprite->subpriority = gSprites[gObjectEvents[objectEventId].spriteId].subpriority;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

void FldEff_Bubbles(s16 x, s16 y)
{
    FieldEffectActiveListAdd(FLDEFF_BUBBLES);
    CargaPaletaDeEfecto(&gSpritePalette_GeneralFieldEffect0);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 0);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_BUBBLES], x, y, 82);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = 1;
    }
    return;
}

#define sY data[0]

void UpdateBubblesFieldEffect(struct Sprite *sprite)
{
    // Move up 1 every other frame.
    sprite->sY += ((1 << 8) / 2);
    sprite->sY &= (1 << 8);
    sprite->y -= sprite->sY >> 8;
    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (sprite->invisible || sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_BUBBLES);
}

#undef sY

void FldEff_BerryTreeGrowthSparkle(s16 x, s16 y, u8 subprioridad, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);

    u32 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], x, y, subprioridad);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = prioridad;
        UpdateSpritePaletteByTemplate(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], sprite);
        sprite->sWaitFldEff = FLDEFF_BERRY_TREE_GROWTH_SPARKLE;
    }
    return;
}

// Sprite data for FLDEFF_TREE_DISGUISE / FLDEFF_MOUNTAIN_DISGUISE / FLDEFF_SAND_DISGUISE
#define sState      data[0]
#define sFldEff     data[1]
#define sLocalId    data[2]
#define sMapNum     data[3]
#define sMapGroup   data[4]
#define sReadyToEnd data[7]

void ShowSandDisguiseFieldEffect(void)
{
    return;
}

void UpdateDisguiseFieldEffect(struct Sprite *sprite)
{
    u32 objectEventId;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    struct Sprite *linkedSprite;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
        FieldEffectStop(sprite, sprite->sFldEff);

    graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
    linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
    sprite->invisible = linkedSprite->invisible;
    sprite->x = linkedSprite->x;
    sprite->y = (graphicsInfo->height >> 1) + linkedSprite->y - 16;
    sprite->subpriority = linkedSprite->subpriority - 1;

    if (sprite->sState == 1)
    {
        sprite->sState++;
        StartSpriteAnim(sprite, 1);
    }

    if (sprite->sState == 2 && sprite->animEnded)
        sprite->sReadyToEnd = TRUE;

    if (sprite->sState == 3)
        FieldEffectStop(sprite, sprite->sFldEff);
}

bool8 UpdateRevealDisguise(struct ObjectEvent *objectEvent)
{
    struct Sprite *sprite;

    if (objectEvent->directionSequenceIndex == 2)
        return TRUE;

    if (objectEvent->directionSequenceIndex == 0)
        return TRUE;

    sprite = &gSprites[objectEvent->fieldEffectSpriteId];
    if (sprite->sReadyToEnd)
    {
        objectEvent->directionSequenceIndex = 2;
        sprite->sState++;
        return TRUE;
    }
    return FALSE;
}

#undef sState
#undef sFldEff
#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sReadyToEnd

// Sprite data for FLDEFF_SPARKLE
#define sFinished data[0]
#define sEndTimer data[1]

void FldEff_Sparkle(s16 x, s16 y, u8 prioridad)
{
    FieldEffectActiveListAdd(FLDEFF_SPARKLE);
    CargaPaletaDeEfecto(&gSpritePalette_SmallSparkle);

    u32 spriteId;

    x += MAP_OFFSET;
    y += MAP_OFFSET;
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SMALL_SPARKLE], x, y, 82);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.priority = prioridad;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
    }
    return;
}

void UpdateSparkleFieldEffect(struct Sprite *sprite)
{
    if (!sprite->sFinished)
    {
        if (sprite->animEnded)
        {
            sprite->invisible = TRUE;
            sprite->sFinished++;
        }
    }

    if (sprite->sFinished && ++sprite->sEndTimer > 34)
        FieldEffectStop(sprite, FLDEFF_SPARKLE);
}

#undef sFinished
#undef sEndTimer

#define sTimer       data[0]
#define sMoveTimer   data[1]
#define sState       data[2]
#define sVelocity    data[3]
#define sStartY      data[4]
#define sCounter     data[5]
#define sAnimCounter data[6]
#define sAnimState   data[7]

// Same as InitSpriteForFigure8Anim
static void InitRayquazaForFigure8Anim(struct Sprite *sprite)
{
    sprite->sAnimCounter = 0;
    sprite->sAnimState = 0;
}

// Only different from AnimateSpriteInFigure8 by the addition of SetGpuReg to move the spotlight
static bool8 AnimateRayquazaInFigure8(struct Sprite *sprite)
{
    bool8 finished = FALSE;

    switch (sprite->sAnimState)
    {
    case 0:
        sprite->x2 += GetFigure8XOffset(sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset(sprite->sAnimCounter);
        break;
    case 1:
        sprite->x2 -= GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        break;
    case 2:
        sprite->x2 -= GetFigure8XOffset(sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset(sprite->sAnimCounter);
        break;
    case 3:
        sprite->x2 += GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        break;
    }

    // Update spotlight to sweep left and right with Rayquaza
    SetGpuReg(REG_OFFSET_BG0HOFS, -sprite->x2);

    if (++sprite->sAnimCounter == FIGURE_8_LENGTH)
    {
        sprite->sAnimCounter = 0;
        sprite->sAnimState++;
    }
    if (sprite->sAnimState == 4)
    {
        sprite->y2 = 0;
        sprite->x2 = 0;
        finished = TRUE;
    }

    return finished;
}

void UpdateRayquazaSpotlightEffect(struct Sprite *sprite)
{
    u32 i, j;

    switch (sprite->sState)
    {
        case 0:
            SetGpuReg(REG_OFFSET_BG0VOFS, ANCHO_PANTALLA / 2 - (sprite->sTimer / 3));
            if (sprite->sTimer == 96)
            {
                for (i = 0; i < 3; i++)
                {
                    for (j = 12; j < 18; j++)
                    {
                        ((u16 *)(BG_SCREEN_ADDR(31)))[i * 32 + j] = 0xBFF4 + i * 6 + j + 1;
                    }
                }
            }
            if (sprite->sTimer > 311)
            {
                sprite->sState = 1;
                sprite->sTimer = 0;
            }
            break;
        case 1:
            sprite->y = (gSineTable[sprite->sTimer / 3] >> 2) + sprite->sStartY;
            if (sprite->sTimer == 189)
            {
                sprite->sState = 2;
                sprite->sCounter = 0;
                sprite->sTimer = 0;
            }
            break;
        case 2:
            if (sprite->sTimer == 60)
            {
                sprite->sCounter++;
                sprite->sTimer = 0;
            }
            if (sprite->sCounter == 7)
            {
                sprite->sCounter = 0;
                sprite->sState = 3;
            }
            break;
        case 3:
            if (sprite->y2 == 0)
            {
                sprite->sTimer = 0;
                sprite->sState++;
            }
            if (sprite->sTimer == 5)
            {
                sprite->sTimer = 0;
                if (sprite->y2 > 0)
                    sprite->y2--;
                else
                    sprite->y2++;
            }
            break;
        case 4:
            if (sprite->sTimer == 60)
            {
                sprite->sState = 5;
                sprite->sTimer = 0;
                sprite->sCounter = 0;
            }
            break;
        case 5:
            InitRayquazaForFigure8Anim(sprite);
            sprite->sState = 6;
            sprite->sTimer = 0;
            break;
        case 6:
            if (AnimateRayquazaInFigure8(sprite))
            {
                sprite->sTimer = 0;
                if (++sprite->sCounter <= 2)
                {
                    InitRayquazaForFigure8Anim(sprite);
                }
                else
                {
                    sprite->sCounter = 0;
                    sprite->sState = 7;
                }
            }
            break;
        case 7:
            if (sprite->sTimer == 30)
            {
                sprite->sState = 8;
                sprite->sTimer = 0;
            }
            break;
        case 8:
            for (i = 0; i < 15; i++)
            {
                for (j = 12; j < 18; j++)
                {
                    ((u16 *)(BG_SCREEN_ADDR(31)))[i * 32 + j] = 0;
                }
            }
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            FieldEffectStop(sprite, FLDEFF_RAYQUAZA_SPOTLIGHT);
            break;
    }

    if (sprite->sState == 1)
    {
        // Update movement
        if ((sprite->sMoveTimer & 7) == 0)
            sprite->y2 += sprite->sVelocity;
        // Reverse direction
        if ((sprite->sMoveTimer & 15) == 0)
            sprite->sVelocity = -sprite->sVelocity;
        sprite->sMoveTimer++;
    }

    sprite->sTimer++;
}

#undef sTimer
#undef sMoveTimer
#undef sState
#undef sStartY
#undef sVelocity
#undef sCounter
#undef sAnimCounter
#undef sAnimState

void UpdateJumpImpactEffect(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        FieldEffectStop(sprite, sprite->sJumpFldEff);
    }
    else
    {
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        SetObjectSubpriorityByElevation(sprite->sJumpElevation, sprite, 0);
    }
}

void WaitFieldEffectSpriteAnim(struct Sprite *sprite)
{
    if (sprite->animEnded)
        FieldEffectStop(sprite, sprite->sWaitFldEff);
    else
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
}

static void UpdateGrassFieldEffectSubpriority(struct Sprite *sprite, u8 elevation, u8 subpriority)
{
    u32 i;
    s16 var, xhi, lyhi, yhi, ylo;

    SetObjectSubpriorityByElevation(elevation, sprite, subpriority);
    for (i = 0; i < OBJECT_EVENTS_COUNT; i ++)
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[i];
        if (objectEvent->active)
        {
            struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];

            xhi = sprite->x + sprite->centerToCornerVecX;
            var = sprite->x - sprite->centerToCornerVecX;
            if (xhi < linkedSprite->x && var > linkedSprite->x)
            {
                lyhi = linkedSprite->y + linkedSprite->centerToCornerVecY;
                var = linkedSprite->y;
                ylo = sprite->y - sprite->centerToCornerVecY;
                yhi = ylo + linkedSprite->centerToCornerVecY;
                if ((lyhi < yhi || lyhi < ylo) && var > yhi && sprite->subpriority <= linkedSprite->subpriority)
                {
                    sprite->subpriority = linkedSprite->subpriority + 2;
                    break;
                }
            }
        }
    }
}

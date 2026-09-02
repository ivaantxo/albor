#ifndef GUARD_FIELD_EFFECT_HELPERS_H
#define GUARD_FIELD_EFFECT_HELPERS_H

// States for bobbing up and down while surfing
// Efectos que se enganchan a un objeto del mapa: se identifican por el trio
// que lo localiza, no por variables globales puestas antes de llamar.
void FldEff_Shadow(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_Splash(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_FeetInFlowingWater(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_SandPile(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_ShortGrass(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_HotSpringsWater(u8 localId, u8 mapNum, u8 mapGroup);

// Efectos que se pintan en una casilla concreta.
void FldEff_AshLaunch(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_BerryTreeGrowthSparkle(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_BikeTireTracks(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_DeepSandFootprints(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_Dust(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_JumpBigSplash(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_JumpLongGrass(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_JumpSmallSplash(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_JumpTallGrass(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_PokeballTrail(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_Ripple(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_SandFootprints(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_TracksBug(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_TracksSlither(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_TracksSpot(s16 x, s16 y, u8 subprioridad, u8 prioridad, u8 animacion);
void FldEff_WaterSurfacing(s16 x, s16 y, u8 subprioridad, u8 prioridad);

void FldEff_Bubbles(s16 x, s16 y);
void FldEff_Sparkle(s16 x, s16 y, u8 prioridad);

// El objeto y el mapa van empaquetados dos a dos, como los guarda el sprite:
// objetoYMapa = localId << 8 | mapNum, mapaActual = mapNum << 8 | mapGroup.
void FldEff_Ash(s16 x, s16 y, u8 subprioridad, u8 prioridad, u16 metatile, u8 retardo);
void FldEff_TallGrass(s16 x, s16 y, u8 elevacion, u8 prioridad, u16 objetoYMapa, u8 mapGroup, u16 mapaActual, bool8 saltarAnimacion);
void FldEff_LongGrass(s16 x, s16 y, u8 elevacion, u16 objetoYMapa, u8 mapGroup, u16 mapaActual, bool8 saltarAnimacion);

u8 CreateWarpArrowSprite(void);
u8 EmpiezaBamboleoBajoElAgua(u8 spriteIdABambolear);
bool8 UpdateRevealDisguise(struct ObjectEvent *);
void StartAshFieldEffect(s16, s16, u16, s16);
void SetUpReflection(struct ObjectEvent *, struct Sprite *, u8);
void SetUpShadow(struct ObjectEvent *, struct Sprite *);
u8 FindTallGrassFieldEffectSpriteId(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void UpdateRayquazaSpotlightEffect(struct Sprite *);
void UpdateShadowFieldEffect(struct Sprite *);
void UpdateTallGrassFieldEffect(struct Sprite *);
void WaitFieldEffectSpriteAnim(struct Sprite *);
void UpdateAshFieldEffect(struct Sprite *);
void UpdateJumpImpactEffect(struct Sprite *);
void UpdateFootprintsTireTracksFieldEffect(struct Sprite *);
void UpdateSplashFieldEffect(struct Sprite *);
void UpdateLongGrassFieldEffect(struct Sprite *);
void UpdateSandPileFieldEffect(struct Sprite *);
void UpdateDisguiseFieldEffect(struct Sprite *);
void UpdateShortGrassFieldEffect(struct Sprite *);
void UpdateHotSpringsWaterFieldEffect(struct Sprite *);
void UpdateBubblesFieldEffect(struct Sprite *);
void UpdateSparkleFieldEffect(struct Sprite *);
void SetSpriteInvisible(u32 spriteId);
void ShowWarpArrowSprite(u32 spriteId, u8 direction, s16 x, s16 y);

#endif //GUARD_FIELD_EFFECT_HELPERS_H

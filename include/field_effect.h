#ifndef GUARD_FIELD_EFFECTS_H
#define GUARD_FIELD_EFFECTS_H

extern s32 gFieldEffectArguments[8];
extern void (*gPostMenuFieldCallback)(void);
extern bool8 (*gFieldCallback2)(void);

void FieldEffectStart(u8);
void CargaPaletaDeEfecto(const struct SpritePalette *paleta);
// Fuera de la tabla de efectos: devuelve el sprite que crea, y quien la llama lo
// necesita para esperar a que termine su animacion.
u8 FldEff_AshPuff(s16 x, s16 y, u8 subprioridad, u8 prioridad);
void FldEff_NPCFlyOut(u16 spriteIdAve);
void FldEff_UseFly(u8 monId);
void FldEff_DestroyDeoxysRock(u8 localId, u8 mapNum, u8 mapGroup);
// Los iconos que salen sobre la cabeza de un personaje. La interrogacion sirve
// ademas para las emociones del follower: emocion a -1 es el icono normal.
void FldEff_ExclamationMarkIcon(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_QuestionMarkIcon(u8 localId, u8 mapNum, u8 mapGroup, s8 emocion);
void FldEff_HeartIcon(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_XIcon(u8 localId, u8 mapNum, u8 mapGroup);
void FldEff_DoubleExclMarkIcon(u8 localId, u8 mapNum, u8 mapGroup);
// Mostrar el Pokemon al usar un movimiento de campo son dos pasos: el primero
// mira que Pokemon es y llama al segundo, que es el que lo dibuja.
void FldEff_FieldMoveShowMonInit(u8 ranuraEquipo, bool8 sinAgacharse);
void FldEff_FieldMoveShowMon(u16 especie, bool8 variocolor, u32 personalidad, bool8 sinAgacharse);
bool8 FieldEffectActiveListContains(u8 id);
void FieldEffectActiveListClear(void);
void ReturnToFieldFromFlyMapSelect(void);
void FieldCallback_UseFly(void);
u8 AddNewGameBirchObject(s16, s16, u8);
void FieldEffectStop(struct Sprite *sprite, u8 id);
// Ya no recibe buffer prestado: la descompresion reserva y suelta por su cuenta.
u8 CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority);
void FldEff_TeleportWarpOut(void);
void FieldEffectActiveListRemove(u8 id);
void MultiplyInvertedPaletteRGBComponents(u32 i, u8 r, u8 g, u8 b);
void FieldEffectActiveListAdd(u8 id);
void FieldEffectFreeGraphicsResources(struct Sprite *sprite);
void FieldEffectFreeTilesIfUnused(u16 tileStart);
void FieldEffectFreePaletteIfUnused(u8 paletteNum);
void FieldCB_FallWarpExit(void);
void StartEscalatorWarp(u8 metatileBehavior, u8 priority);
void StartLavaridgeGymB1FWarp(u8 priority);
void StartLavaridgeGym1FWarp(u8 priority);

void SpriteCB_AshPuff(struct Sprite *);
void SpriteCB_AshLaunch(struct Sprite *);

void MultiplyPaletteRGBComponents(u32 i, u8 r, u8 g, u8 b);
void FreeResourcesAndDestroySprite(struct Sprite *sprite, u32 spriteId);
u32 CreateMonSprite_PicBox(u32 species, s32 x, s32 y, u32 subpriority);
void StartEscapeRopeFieldEffect(void);

#endif // GUARD_FIELD_EFFECTS_H

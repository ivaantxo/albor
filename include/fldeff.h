#ifndef GUARD_FLDEFF_H
#define GUARD_FLDEFF_H

// cut
bool8 SetUpFieldMove_Cut(void);
void FldEff_UseCutOnGrass(void);
void FldEff_UseCutOnTree(void);
void FldEff_CutGrass(void);
void FixLongGrassMetatilesWindowTop(s16 x, s16 y);
void FixLongGrassMetatilesWindowBottom(s16 x, s16 y);

extern const struct SpritePalette gSpritePalette_CutGrass;
extern struct MapPosition gPlayerFacingPosition;

// escalator
void StartEscalator(bool8 var);
void StopEscalator(void);
bool8 IsEscalatorMoving(void);

// soft-boiled
bool8 SetUpFieldMove_SoftBoiled(void);
void Task_TryUseSoftboiledOnPartyMon(u8 taskId);
void ChooseMonForSoftboiled(u8 taskId);

// flash
bool8 SetUpFieldMove_Flash(void);
void CB2_DoChangeMap(void);
bool8 GetMapPairFadeToType(u8 _fromType, u8 _toType);
bool8 GetMapPairFadeFromType(u8 _fromType, u8 _toType);

// strength
bool8 SetUpFieldMove_Strength(void);
void FldEff_UseStrength(void);

// sweet scent

// teleport
bool8 SetUpFieldMove_Teleport(void);
void FldEff_UseTeleport(void);

// dig
bool8 SetUpFieldMove_Dig(void);
void FldEff_UseDig(void);

// rock smash
bool8 CheckObjectGraphicsInFrontOfPlayer(u16 graphicsId);
u8 CreateFieldMoveTask(void);
bool8 SetUpFieldMove_RockSmash(void);
void FldEff_UseRockSmash(void);

#endif // GUARD_FLDEFF_H

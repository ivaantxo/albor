#ifndef GUARD_BATTLE_MAIN_H
#define GUARD_BATTLE_MAIN_H

#include "pokemon.h"
#include "data.h"

// For displaying a multi battle partner's Pokémon in the party menu
struct MultiPartnerMenuPokemon
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 heldItem;
    /*0x04*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 maxhp;
    /*0x14*/ u32 status;
    /*0x18*/ u32 personality;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
};

enum EfectosBote
{
    BOUNCE_MON,
    BOUNCE_HEALTHBOX,
};

enum EstadosIntroBatalla
{
    ESTADO_INTRO_BATALLA_OBTEN_DATOS_POKEMON,
    ESTADO_INTRO_BATALLA_LOOP_DATOS_POKEMON,
    ESTADO_INTRO_BATALLA_PREPARA_DESLIZAMIENTO_FONDO,
    ESTADO_INTRO_BATALLA_ESPERA_DESLIZAMIENTO_FONDO,
    ESTADO_INTRO_BATALLA_DIBUJA_SPRITES,
    ESTADO_INTRO_BATALLA_DIBUJA_SUMARIO_EQUIPO,
    ESTADO_INTRO_BATALLA_ESPERA_SUMARIO_EQUIPO,
    ESTADO_INTRO_BATALLA_TEXTO_INICIAL,
    ESTADO_INTRO_BATALLA_ESPERA_TEXTO_INICIAL,
    ESTADO_INTRO_BATALLA_TEXTO_ENTRENADOR,
    ESTADO_INTRO_BATALLA_ESPERA_TEXTO_ENTRENADOR,
    ESTADO_INTRO_BATALLA_ANIMACION_ENVIAR_POKEMON,
    ESTADO_INTRO_BATALLA_ESPERA_TEXTO_BATALLA_SALVAJE,
    ESTADO_INTRO_BATALLA_TEXTO_BATALLA_ENTRADA_JUGADOR,
    ESTADO_INTRO_BATALLA_ESPERA_TEXTO_BATALLA_ENTRADA_JUGADOR,
    ESTADO_INTRO_BATALLA_PREPARA_VARS
};

enum {
    FIRST_TURN_EVENTS_START,
    FIRST_TURN_EVENTS_OVERWORLD_WEATHER,
    FIRST_TURN_EVENTS_TERRAIN,
    FIRST_TURN_EVENTS_STARTING_STATUS,
    FIRST_TURN_EVENTS_NEUTRALIZING_GAS,
    FIRST_TURN_EVENTS_SWITCH_IN_ABILITIES,
    FIRST_TURN_EVENTS_OPPORTUNIST_1,
    FIRST_TURN_EVENTS_ITEM_EFFECTS,
    FIRST_TURN_EVENTS_OPPORTUNIST_2,
    FIRST_TURN_EVENTS_END,
};

void CB2_InitBattle(void);
void BattleMainCB2(void);
void VBlankCB_Battle(void);
void SpriteCB_VsLetterDummy(struct Sprite *sprite);
void SpriteCB_VsLetterInit(struct Sprite *sprite);
u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId);
u32 GetBattleWindowTemplatePixelWidth(u32 tableId);
void SpriteCB_WildMon(struct Sprite *sprite);
void SpriteCB_FaintOpponentMon(struct Sprite *sprite);
void SpriteCB_ShowAsMoveTarget(struct Sprite *sprite);
void SpriteCB_HideAsMoveTarget(struct Sprite *sprite);
void SpriteCB_OpponentMonFromBall(struct Sprite *sprite);
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite);
void SpriteCB_FaintSlideAnim(struct Sprite *sprite);
void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude);
void EndBounceEffect(u8 battler, u8 which);
void SpriteCB_PlayerMonFromBall(struct Sprite *sprite);
void SpriteCB_PlayerMonSlideIn(struct Sprite *sprite);
void SpriteCB_TrainerThrowObject(struct Sprite *sprite);
void AnimSetCenterToCornerVecX(struct Sprite *sprite);
void BeginBattleIntroDummy(void);
void BeginBattleIntro(void);
void SwitchInClearSetData(u32 battler);
const u8* FaintClearSetData(u32 battler);
void BattleTurnPassed(void);
u32 IntentaEscaparBatalla(u32 combatiente);
void SwitchTwoBattlersInParty(u32 battler, u32 battler2);
void SwitchPartyOrder(u32 battlerId);
void SwapTurnOrder(u8 id1, u8 id2);
u32 GetBattlerTotalSpeedStatArgs(u32 battler, u32 ability, u32 holdEffect);
u32 GetBattlerTotalSpeedStat(u32 battler);
s8 GetChosenMovePriority(u32 battlerId);
s8 GetMovePriority(u32 battlerId, u16 move);
s32 GetWhichBattlerFasterArgs(u32 battler1, u32 battler2, bool32 ignoreChosenMoves, u32 ability1, u32 ability2,
                              u32 holdEffectBattler1, u32 holdEffectBattler2, u32 speedBattler1, u32 speedBattler2, s32 priority1, s32 priority2);
s32 GetWhichBattlerFasterOrTies(u32 battler1, u32 battler2, bool32 ignoreChosenMoves);
s32 GetWhichBattlerFaster(u32 battler1, u32 battler2, bool32 ignoreChosenMoves);
void RunBattleScriptCommands_PopCallbacksStack(void);
void RunBattleScriptCommands(void);
void SpecialStatusesClear(void);
u32 GetDynamicMoveType(struct Pokemon *mon, u32 move, u32 battler, u8 *ateBoost);
void SetTypeBeforeUsingMove(u32 move, u32 battlerAtk);
bool32 IsWildMonSmart(void);
u8 CreateNPCTrainerPartyFromTrainer(struct Pokemon *party, const struct Trainer *trainer, bool32 firstTrainer, u32 battleTypeFlags);
void ModifyPersonalityForNature(u32 *personality, u32 newNature);
u32 GeneratePersonalityForGender(u32 gender, u32 species);
void CustomTrainerPartyAssignMoves(struct Pokemon *mon, const struct TrainerMon *partyEntry);

extern struct MultiPartnerMenuPokemon gMultiPartnerParty[MULTI_PARTY_SIZE + 1];

extern const struct OamData gOamData_BattleSpriteOpponentSide;
extern const struct OamData gOamData_BattleSpritePlayerSide;
extern const struct TypeInfo gTypesInfo[NUMERO_DE_TIPOS];
extern const uq4_12_t gTypeEffectivenessTable[NUMERO_DE_TIPOS][NUMERO_DE_TIPOS];

extern const u8 *const gStatusConditionStringsTable[7];

#endif // GUARD_BATTLE_MAIN_H

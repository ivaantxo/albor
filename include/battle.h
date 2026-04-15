#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

// should they be included here or included individually by every file?
#include "constants/battle.h"
#include "constants/form_change_types.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_ai_switch_items.h"
#include "battle_gfx_sfx_util.h"
#include "battle_bg.h"
#include "pokeball.h"
#include "battle_debug.h"
#include "random.h" // for rng_value_t

// Helper for accessing command arguments and advancing gBattlescriptCurrInstr.
//
// For example accuracycheck is defined as:
//
//     .macro accuracycheck failInstr:req, move:req
//     .byte 0x1
//     .4byte \failInstr
//     .2byte \move
//     .endm
//
// Which corresponds to:
//
//     CMD_ARGS(const u8 *failInstr, u16 move);
//
// The arguments can be accessed as cmd->failInstr and cmd->move.
// gBattlescriptCurrInstr = cmd->nextInstr; advances to the next instruction.
#define CMD_ARGS(...)                                          \
    const struct __attribute__((packed))                       \
    {                                                          \
        u8 opcode;                                             \
        RECURSIVELY(R_FOR_EACH(APPEND_SEMICOLON, __VA_ARGS__)) \
        const u8 nextInstr[0];                                 \
    } *const cmd UNUSED = (const void *)gBattlescriptCurrInstr
#define VARIOUS_ARGS(...) CMD_ARGS(u8 battler, u8 id, ##__VA_ARGS__)
#define NATIVE_ARGS(...) CMD_ARGS(void (*func)(void), ##__VA_ARGS__)

// Battle Actions
// These determine what each battler will do in a turn
#define B_ACTION_USE_MOVE 0
#define B_ACTION_SWITCH 1
#define B_ACTION_RUN 2
#define B_ACTION_EXEC_SCRIPT 3
#define B_ACTION_TRY_FINISH 4
#define B_ACTION_FINISHED 5
#define B_ACTION_CANCEL_PARTNER 6
#define B_ACTION_NOTHING_FAINTED 7
#define B_ACTION_DEBUG 8
#define B_ACTION_THROW_BALL 9
#define B_ACTION_SUBIO_NIVEL 10
#define B_ACTION_NONE 0xFF

// enum AccionesBatalla
//{
//
// },

// For defining EFFECT_HIT etc. with battle TV scores and flags etc.
struct __attribute__((packed, aligned(2))) BattleMoveEffect
{
    const u8 *battleScript;
    u16 encourageEncore : 1;
    u16 twoTurnEffect : 1;
    u16 semiInvulnerableEffect : 1;
    u16 usesProtectCounter : 1;
    u16 padding : 9;
};

#define GET_MOVE_BATTLESCRIPT(move) gBattleMoveEffects[gMovimientos[move].effect].battleScript

#define RESOURCE_FLAG_FLASH_FIRE 1
#define RESOURCE_FLAG_ROOST 2
#define RESOURCE_FLAG_UNBURDEN 3
#define RESOURCE_FLAG_NEUTRALIZING_GAS 4

struct DisableStruct
{
    u16 disabledMove;
    u16 encoredMove;
    u8 protectUses : 4;
    u8 stockpileCounter : 4;
    s8 stockpileDef;
    s8 stockpileSpDef;
    s8 stockpileBeforeDef;
    s8 stockpileBeforeSpDef;
    u8 substituteHP;
    u8 encoredMovePos;
    u8 disableTimer : 4;
    u8 encoreTimer : 4;
    u8 perishSongTimer : 4;
    u8 rolloutTimer : 4;
    u8 rolloutTimerStartValue : 4;
    u8 tauntTimer : 4;
    u8 furyCutterCounter;
    u8 battlerPreventingEscape;
    u8 battlerWithSureHit;
    u8 chargeTimer : 4;
    u8 rechargeTimer;
    u8 autotomizeCount;
    u8 embargoTimer;
    u8 magnetRiseTimer;
    u8 telekinesisTimer;
    u8 throatChopTimer;
    u8 wrapTurns;
    u8 tormentTimer : 4;
    u8 usedMoves : 4;
    u8 cudChew : 1;
    u8 spikesDone : 1;
    u8 toxicSpikesDone : 1;
    u8 stickyWebDone : 1;
    u8 stealthRockDone : 1;
    bool32 esPrimerTurno;
};

struct ProtectStruct
{
    u32 protected : 1;
    u32 spikyShielded : 1;
    u32 noValidMoves : 1;
    u32 stealMove : 1;
    u32 prlzImmobility : 1;
    u32 sleepImmobility : 1;
    u32 confusionSelfDmg : 1;
    u32 targetAffected : 1;
    u32 chargingTurn : 1;
    u32 usedImprisonedMove : 1;
    u32 loveImmobility : 1;
    u32 usedDisabledMove : 1;
    u32 usedTauntedMove : 1;
    u32 flinchImmobility : 1;
    u32 notFirstStrike : 1;
    u32 usedGravityPreventedMove : 1;
    u32 powderSelfDmg : 1;
    u32 usedThroatChopPreventedMove : 1;
    u32 statRaised : 1;
    u32 touchedProtectLike : 1;
    u16 disableEjectPack : 1;
    u16 statFell : 1;
    u16 silkTrapped : 1;
    bool32 prioridadBromista;
};

struct SpecialStatus
{
    u8 changedStatsBattlerId; // Battler that was responsible for the latest stat change. Can be self.
    u8 statLowered : 1;
    u8 lightningRodRedirected : 1;
    u8 restoredBattlerSprite : 1;
    u8 faintedHasReplacement : 1;
    // End of byte
    u8 stormDrainRedirected : 1;
    u8 switchInAbilityDone : 1;
    u8 switchInItemDone : 1;
    u8 berryReduced : 1;
    u8 parentalBondState : 2;
    u8 multiHitOn : 1;
    u8 announceNeutralizingGas : 1; // See Cmd_switchineffects
    u8 neutralizingGasRemoved : 1;  // See VARIOUS_TRY_END_NEUTRALIZING_GAS
    // End of byte
    u8 damagedMons : 4; // Mons that have been damaged directly by using a move, includes substitute.
    u8 preventLifeOrbDamage : 1; // So that Life Orb doesn't activate various effects.
    bool32 potenciadoGema;
};

struct SideTimer
{
    u8 reflectTimer;
    u8 reflectBattlerId;
    u8 lightscreenTimer;
    u8 lightscreenBattlerId;
    u8 mistTimer;
    u8 mistBattlerId;
    u8 safeguardTimer;
    u8 safeguardBattlerId;
    u8 spikesAmount;
    u8 toxicSpikesAmount;
    u8 stealthRockAmount;
    u8 stickyWebAmount;
    u8 stickyWebBattlerId;
    u8 stickyWebBattlerSide; // Used for Court Change
    u8 auroraVeilTimer;
    u8 auroraVeilBattlerId;
    u8 tailwindTimer;
    u8 tailwindBattlerId;
    u8 luckyChantTimer;
    u8 luckyChantBattlerId;
    // Timers below this point are not swapped by Court Change
    u8 followmeTimer;
    u8 followmeTarget : 3;
    u8 followmePowder : 1; // Rage powder, does not affect grass type pokemon.
    u8 retaliateTimer;
    u8 damageNonTypesTimer;
    u8 damageNonTypesType;
};

struct FieldTimer
{
    u8 wonderRoomTimer;
    u8 magicRoomTimer;
    u8 trickRoomTimer;
    u8 gravityTimer;
};

struct AI_SavedBattleMon
{
    u16 ability;
    u16 moves[MAX_MON_MOVES];
    u16 heldItem;
    u16 species : 15;
    u16 saved : 1;
    u8 types[NUMERO_TIPOS_POR_POKEMON];
};

struct AIPartyMon
{
    u16 species;
    u16 item;
    u16 heldEffect;
    u16 ability;
    u16 gender;
    u16 level;
    u16 moves[MAX_MON_MOVES];
    u32 status;
    bool8 isFainted;
    bool8 wasSentInBattle;
    u8 switchInCount; // Counts how many times this Pokemon has been sent out or switched into in a battle.
};

struct AIPartyData // Opposing battlers - party mons.
{
    struct AIPartyMon mons[NUMERO_LADOS][PARTY_SIZE]; // 2 parties(player, opponent). Used to save information on opposing party.
    u8 count[NUMERO_LADOS];
};

struct SwitchinCandidate
{
    struct BattlePokemon battleMon;
    bool8 hypotheticalStatus;
};

// AI Data used when deciding which move to use, computed only once before each turn's start.
struct AILogicData
{
    u16 abilities[NUMERO_COMBATIENTES];
    u16 items[NUMERO_COMBATIENTES];
    u16 holdEffects[NUMERO_COMBATIENTES];
    u8 holdEffectParams[NUMERO_COMBATIENTES];
    u16 lastUsedMove[NUMERO_COMBATIENTES];
    u8 hpPercents[NUMERO_COMBATIENTES];
    u16 partnerMove;
    u16 speedStats[NUMERO_COMBATIENTES];                                       // Speed stats for all battles, calculated only once, same way as damages
    s32 simulatedDmg[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAX_MON_MOVES]; // attacker, target, moveIndex
    u8 effectiveness[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAX_MON_MOVES]; // attacker, target, moveIndex
    u8 moveAccuracy[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAX_MON_MOVES];  // attacker, target, moveIndex
    u8 moveLimitations[NUMERO_COMBATIENTES];
    u8 monToSwitchInId[NUMERO_COMBATIENTES];    // ID of the mon to switch in.
    u8 mostSuitableMonId[NUMERO_COMBATIENTES];  // Stores result of GetMostSuitableMonToSwitchInto, which decides which generic mon the AI would switch into if they decide to switch. This can be overruled by specific mons found in ShouldSwitch; the final resulting mon is stored in AI_monToSwitchIntoId.
    struct SwitchinCandidate switchinCandidate; // Struct used for deciding which mon to switch to in battle_ai_switch_items.c
    u8 ejectButtonSwitch : 1;                   // Tracks whether current switch out was from Eject Button
    u8 ejectPackSwitch : 1;                     // Tracks whether current switch out was from Eject Pack
    u8 padding : 5;
    u8 shouldSwitch; // Stores result of ShouldSwitch, which decides whether a mon should be switched out
    u8 aiCalcInProgress : 1;
};

struct AI_ThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s32 score[MAX_MON_MOVES];
    u32 funcResult;
    u32 aiFlags[NUMERO_COMBATIENTES];
    u8 aiAction;
    u8 aiLogicId;
    struct AI_SavedBattleMon saved[NUMERO_COMBATIENTES];
};

#define AI_MOVE_HISTORY_COUNT 3

struct BattleHistory
{
    u16 abilities[NUMERO_COMBATIENTES];
    u8 itemEffects[NUMERO_COMBATIENTES];
    u16 usedMoves[NUMERO_COMBATIENTES][MAX_MON_MOVES];
    u16 moveHistory[NUMERO_COMBATIENTES][AI_MOVE_HISTORY_COUNT]; // 3 last used moves for each battler
    u8 moveHistoryIndex[NUMERO_COMBATIENTES];
    u16 trainerItems[NUMERO_COMBATIENTES];
    u8 itemsNo;
    u16 heldItems[NUMERO_COMBATIENTES];
};

struct BattleScriptsStack
{
    const u8 *ptr[8];
    u8 size;
};

struct BattleCallbacksStack
{
    void (*function[8])(void);
    u8 size;
};

struct StatsArray
{
    u16 stats[NUMERO_ESTADISTICAS];
};

struct BattleResources
{
    struct SecretBase *secretBase;
    struct BattleScriptsStack *battleScriptsStack;
    struct BattleCallbacksStack *battleCallbackStack;
    struct StatsArray *beforeLvlUp;
    struct AI_ThinkingStruct *ai;
    struct AILogicData *aiData;
    struct AIPartyData *aiParty;
    struct BattleHistory *battleHistory;
    u8 bufferA[NUMERO_COMBATIENTES][512];
    u8 bufferB[NUMERO_COMBATIENTES][512];
    u8 transferBuffer[256];
    u32 flags[NUMERO_COMBATIENTES];
};

#define AI_THINKING_STRUCT ((struct AI_ThinkingStruct *)(gBattleResources->ai))
#define AI_DATA ((struct AILogicData *)(gBattleResources->aiData))
#define AI_PARTY ((struct AIPartyData *)(gBattleResources->aiParty))
#define BATTLE_HISTORY ((struct BattleHistory *)(gBattleResources->battleHistory))

struct EfectosFinTurno
{
    enum EfectosFinTurnoCampo campo;
    enum EfectosFinTurnoIndividuales individual;
    enum PosicionesCombate indiceCombatiente;
};

struct Clima
{
    u32 turnos;
    enum ClimasCombate modo;
}

struct Combate
{
    u32 contadorTurnos;
    u32 contadorDebilitadosJugador;
    u32 contadorDebilitadosRival;
    u32 numeroCambiosJugador;
    u32 danioRecibido[NUMERO_COMBATIENTES];
    u32 contadorMultigolpes;
    u16 wrappedMove[NUMERO_COMBATIENTES];
    u16 moveTarget[NUMERO_COMBATIENTES];
    u32 expValue;
    u8 expGettersOrder[PARTY_SIZE]; // First battlers which were sent out, then via exp-share
    u8 expGetterMonId;
    u8 expOrderId : 3;
    u8 expGetterBattlerId : 2;
    u8 givenExpMons;  // Bits for enemy party's pokemon that gave exp to player's party.
    u8 expSentInMons; // As bits for player party mons - not including exp share mons.
    u8 dynamicMoveType;
    u8 wrappedBy[NUMERO_COMBATIENTES];
    u8 focusPunchBattlers; // as bits
    u8 battlerPreventingSwitchout;
    u8 moneyMultiplier : 6;
    u8 moneyMultiplierItem : 1;
    u8 savedTurnActionNumber;
    u8 eventsBeforeFirstTurnState;
    u8 faintedActionsState;
    u8 faintedActionsBattlerId;
    u8 scriptPartyIdx; // for printing the nickname
    bool8 selectionScriptFinished[NUMERO_COMBATIENTES];
    u8 battlerPartyIndexes[NUMERO_COMBATIENTES];
    u8 monToSwitchIntoId[NUMERO_COMBATIENTES];
    u8 battlerPartyOrders[NUMERO_COMBATIENTES][PARTY_SIZE / 2];
    u8 caughtMonNick[POKEMON_NAME_LENGTH + 1];
    u8 chosenMovePositions[NUMERO_COMBATIENTES];
    u8 stateIdAfterSelScript[NUMERO_COMBATIENTES];
    u8 prevSelectedPartySlot;
    u8 absentBattlerFlags;
    u16 hpOnSwitchout[NUMERO_LADOS];
    u16 abilityPreventingSwitchout;
    u8 hpScale;
    u16 synchronizeMoveEffect;
    u8 multipleSwitchInBattlers : 4; // One bit per battler
    u8 multipleSwitchInState : 2;
    u8 multipleSwitchInCursor : 3;
    u8 multipleSwitchInSortedBattlers[NUMERO_COMBATIENTES];
    u16 usedHeldItems[PARTY_SIZE][NUMERO_LADOS]; // For each party member and side. For harvest, recycle
    u16 choicedMove[NUMERO_COMBATIENTES];
    u16 changedItems[NUMERO_COMBATIENTES];
    u8 switchInBattlerCounter;
    u8 turnSideTracker;
    u8 perishSongState;
    u8 perishSongBattlerId;
    u8 isAtkCancelerForCalledMove : 1; // Certain cases in atk canceler should only be checked once, when the original move is called, however others need to be checked the twice.
    u8 atkCancellerTracker;
    u8 AI_monToSwitchIntoId[NUMERO_COMBATIENTES];
    u8 debugBattler;
    u8 magnitudeBasePower;
    u8 presentBasePower;
    u8 savedBattlerTarget[5];
    u8 savedBattlerAttacker[5];
    u8 savedTargetCount : 4;
    u8 savedAttackerCount : 4;
    u8 activeAbilityPopUps;                           // as bits for each battler
    u8 abilityPopUpSpriteIds[NUMERO_COMBATIENTES][2]; // two per battler
    const u8 *trainerSlideMsg;
    enum EstadosIntroBatalla estadoIntro;
    u8 ateBerry[2];                              // array id determined by side, each party pokemon as bit
    u8 stolenStats[NUMERO_ESTADISTICAS_BATALLA]; // hp byte is used for which stats to raise, other inform about by how many stages
    u16 tracedAbility[NUMERO_COMBATIENTES];
    u16 hpBefore[NUMERO_COMBATIENTES];                                          // Hp of battlers before using a move. For Berserk and Anger Shell.
    s32 IA_Puntuacion[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAX_MON_MOVES]; // AI, target, moves to make debugging easier
    u8 IA_Eleccion[NUMERO_COMBATIENTES];
    u8 IA_Objetivo[NUMERO_COMBATIENTES];
    u8 soulheartBattlerId;
    u8 sameMoveTurns[NUMERO_COMBATIENTES];        // For ECHOED VOICE, number of times the same moves has been SUCCESFULLY used.
    u16 moveEffect2;                              // For Desarme
    u16 changedSpecies[NUMERO_LADOS][PARTY_SIZE]; // For forms when multiple mons can change into the same pokemon.
    u32 objetoPerdido[NUMERO_LADOS][PARTY_SIZE];
    u8 forcedSwitch : 4;             // For each battler
    u8 additionalEffectsCounter : 4; // A counter for the additionalEffects applied by the current move in Cmd_setadditionaleffects
    u8 snatchedMoveIsUsed : 1;
    u8 ackBallUseBtn : 1; // Used for the last used ball feature
    u8 ballSwapped : 1;   // Used for the last used ball feature
    u8 ballSpriteIds[2];  // item gfx, window gfx
    // When using a move which hits multiple opponents which is then bounced by a target, we need to make sure, the move hits both opponents, the one with bounce, and the one without.
    u8 attackerBeforeBounce : 2;
    u8 hitSwitchTargetFailed : 1;
    u8 effectsBeforeUsingMoveDone : 1;             // Mega Evo and Focus Punch/Shell Trap effects.
    u8 targetsDone[NUMERO_COMBATIENTES];           // Each battler as a bit.
    u16 overwrittenAbilities[NUMERO_COMBATIENTES]; // abilities overwritten during battle (keep separate from battle history in case of switching)
    u8 itemPartyIndex[NUMERO_COMBATIENTES];
    u8 itemMoveIndex[NUMERO_COMBATIENTES];
    u8 trainerSlideFirstCriticalHitMsgState : 2;
    u8 trainerSlideFirstSuperEffectiveHitMsgState : 2;
    u8 trainerSlideFirstSTABMoveMsgState : 2;
    u8 trainerSlidePlayerMonUnaffectedMsgState : 2;
    u8 trainerSlideHalfHpMsgDone : 1;
    u8 trainerSlideBeforeFirstTurnMsgDone : 1;
    u8 trainerSlideLowHpMsgDone : 1;
    u8 timesGotHit[NUMERO_LADOS][PARTY_SIZE];
    u8 speedTieBreaks; // NUMERO_COMBATIENTES! values.
    u8 usedEjectItem;
    u8 usedMicleBerry;
    bool32 movimientoEspejoMagicoRebota;
    uq4_12_t resultadoMovimiento;
    u32 potenciaMovimientosRecibidosTurno[NUMERO_COMBATIENTES];
    struct EfectosFinTurno efectoFinTurno;
    struct Clima clima;
};

#define CAMBIA_TIPO_COMBATIENTE(combatiente, tipo)      \
    {                                                   \
        gBattleMons[combatiente].types[TIPO_1] = tipo;  \
        gBattleMons[combatiente].types[TIPO_2] = tipo;  \
    }

#define RESTORE_BATTLER_TYPE(battlerId)                                                                    \
    {                                                                                                      \
        gBattleMons[battlerId].types[TIPO_1] = gSpeciesInfo[gBattleMons[battlerId].species].types[TIPO_1]; \
        gBattleMons[battlerId].types[TIPO_2] = gSpeciesInfo[gBattleMons[battlerId].species].types[TIPO_2]; \
    }

#define IS_BATTLER_PROTECTED(battlerId) (gProtectStructs[battlerId].protected || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_WIDE_GUARD || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_QUICK_GUARD || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_CRAFTY_SHIELD || gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_MAT_BLOCK || gProtectStructs[battlerId].spikyShielded || gProtectStructs[battlerId].silkTrapped)

#define GET_STAT_BUFF_ID(n) ((n & 7)) // first three bits 0x1, 0x2, 0x4
#define GET_STAT_BUFF_VALUE_WITH_SIGN(n) ((n & 0xF8))
#define GET_STAT_BUFF_VALUE(n) (((n >> 3) & 0xF)) // 0x8, 0x10, 0x20, 0x40
#define STAT_BUFF_NEGATIVE 0x80                   // 0x80, the sign bit

#define SET_STAT_BUFF_VALUE(n) ((((n) << 3) & 0xF8))

#define SET_STATCHANGER(statId, stage, goesDown) (gBattleScripting.statChanger = (statId) + ((stage) << 3) + (goesDown << 7))
#define SET_STATCHANGER2(dst, statId, stage, goesDown) (dst = (statId) + ((stage) << 3) + (goesDown << 7))

// NOTE: The members of this struct have hard-coded offsets
//       in include/constants/battle_script_commands.h
struct BattleScripting
{
    u8 multihitString[6];
    u8 animArg1;
    u8 animArg2;
    u16 savedStringId;
    u8 moveendState;
    u8 shiftSwitched; // When the game tells you the next enemy's pokemon and you switch. Option for noobs but oh well.
    u8 battler;
    u8 animTurn;
    u8 animTargetsHit;
    u8 statChanger;
    bool8 statAnimPlayed;
    u8 getexpState;
    u8 drawlvlupboxState;
    u8 learnMoveState;
    u8 savedBattler;
    u8 levelUpHP;
    bool8 monCaught;
    s32 savedDmg;
    u16 savedMoveEffect; // For moves hitting multiple targets.
    u16 moveEffect;
    u16 multihitMoveEffect;
    bool8 fixedPopup; // Force ability popup to stick until manually called back
    u16 abilityPopupOverwrite;
    u8 switchCase; // Special switching conditions, eg. red card
    u8 overrideBerryRequirements;
    u8 stickyWebStatDrop; // To prevent Defiant activating on a Court Change'd Sticky Web
};

struct BattleSpriteInfo
{
    u16 invisible : 1;        // 0x1
    u16 lowHpSong : 1;        // 0x2
    u16 behindSubstitute : 1; // 0x4
    u16 flag_x8 : 1;          // Marcador de que el sprite del pokemon esta siendo usado para mostrar el HP, para que no se muestre el HP en la barra de HP
    u16 hpNumbersNoBars : 1;  // 0x10
};

struct BattleAnimationInfo
{
    u16 animArg; // to fill up later
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 ballThrowCaseId : 6;
    u8 introAnimActive : 1;
    u8 wildMonInvisible : 1;
    u8 field_9_x1C : 3;
    u8 field_9_x20 : 1;
    u8 field_9_x40 : 1;
    u8 field_9_x80 : 1;
    u8 numBallParticles;
    u8 field_B;
    s16 ballSubpx;
    u8 field_E;
    u8 field_F;
};

struct BattleHealthboxInfo
{
    u8 partyStatusSummaryShown : 1;
    u8 healthboxIsBouncing : 1;
    u8 battlerIsBouncing : 1;
    u8 ballAnimActive : 1;      // 0x8
    u8 statusAnimActive : 1;    // x10
    u8 animFromTableActive : 1; // x20
    u8 specialAnimActive : 1;   // x40
    u8 triedShinyMonAnim : 1;
    u8 finishedShinyMonAnim : 1;
    u8 opponentDrawPartyStatusSummaryDelay : 4;
    u8 bgmRestored : 1;
    u8 waitForCry : 1;
    u8 healthboxSlideInStarted : 1;
    u8 healthboxBounceSpriteId;
    u8 battlerBounceSpriteId;
    u8 animationState;
    u8 partyStatusDelayTimer;
    u8 matrixNum;

    u8 shadowSpriteIdPrimary;
    u8 shadowSpriteIdSecondary;

    u8 soundTimer;
    u8 introEndDelay;
    u8 field_A;
    u8 field_B;
};

struct BattleBarInfo
{
    u8 healthboxSpriteId;
    s32 maxValue;
    s32 oldValue;
    s32 receivedValue;
    s32 currValue;
};

struct BattleSpriteData
{
    struct BattleSpriteInfo *battlerData;
    struct BattleHealthboxInfo *healthBoxesData;
    struct BattleAnimationInfo *animationData;
    struct BattleBarInfo *battleBars;
};

#include "sprite.h"

struct MonSpritesGfx
{
    void *firstDecompressed; // ptr to the decompressed sprite of the first Pokémon
    u8 *spritesGfx[NUMERO_COMBATIENTES];
    struct SpriteTemplate templates[NUMERO_COMBATIENTES];
    struct SpriteFrameImage frameImages[NUMERO_COMBATIENTES][NUMERO_FRAMES_POKEMON];
    u16 *buffer;
};

// All battle variables are declared in battle_main.c
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u8 gDisplayedStringBattle[425];
extern u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT];
extern u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT];
extern u32 gBattleTypeFlags;
extern u8 gBattleTerrain;
extern u8 *gBattleAnimBgTileBuffer;
extern u8 *gBattleAnimBgTilemapBuffer;
extern u32 gFlagCombatientesOcupados[NUMERO_COMBATIENTES];
extern u8 gBattlersCount;
extern u16 gBattlerPartyIndexes[NUMERO_COMBATIENTES];
extern u8 gActionsByTurnOrder[NUMERO_COMBATIENTES];
extern u8 gBattlerByTurnOrder[NUMERO_COMBATIENTES];
extern u8 gCurrentTurnActionNumber;
extern u8 gCurrentActionFuncId;
extern struct BattlePokemon gBattleMons[NUMERO_COMBATIENTES];
extern u8 gBattlerSpriteIds[NUMERO_COMBATIENTES];
extern u8 gCurrMovePos;
extern u8 gChosenMovePos;
extern u16 gCurrentMove;
extern u16 gChosenMove;
extern u16 gCalledMove;
extern s32 gBattleMoveDamage;
extern s32 gHpDealt;
extern u16 gLastUsedItem;
extern u16 gLastUsedAbility;
extern u8 gBattlerAttacker;
extern u8 gBattlerTarget;
extern u8 gBattlerFainted;
extern u8 gEffectBattler;
extern u8 gPotentialItemEffectBattler;
extern u8 gAbsentBattlerFlags;
extern u32 gEsGolpeCritico;
extern const u8 *gBattlescriptCurrInstr;
extern u32 gAccionElegida[NUMERO_COMBATIENTES];
extern const u8 *gSelectionBattleScripts[NUMERO_COMBATIENTES];
extern u16 gLastPrintedMoves[NUMERO_COMBATIENTES];
extern u16 gLastMoves[NUMERO_COMBATIENTES];
extern u16 gLastLandedMoves[NUMERO_COMBATIENTES];
extern u16 gLastHitByType[NUMERO_COMBATIENTES];
extern u16 gLastUsedMoveType[NUMERO_COMBATIENTES];
extern u16 gLastResultingMoves[NUMERO_COMBATIENTES];
extern u16 gLockedMoves[NUMERO_COMBATIENTES];
extern u16 gLastUsedMove;
extern u8 gLastHitBy[NUMERO_COMBATIENTES];
extern u16 gMovimientoElegido[NUMERO_COMBATIENTES];
extern u32 gHitMarker;
extern u32 gSideStatuses[NUMERO_LADOS];
extern struct SideTimer gSideTimers[NUMERO_LADOS];
extern u32 gStatuses3[NUMERO_COMBATIENTES];
extern struct DisableStruct gDisableStructs[NUMERO_COMBATIENTES];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u32 gEstadoAccion[NUMERO_COMBATIENTES];
extern u32 gMensajeBatalla;
extern bool32 gMostrarMensajeBatalla;
extern u32 gPosicionCursorSiNo;
extern u8 gBattleOutcome;
extern struct ProtectStruct gProtectStructs[NUMERO_COMBATIENTES];
extern struct SpecialStatus gSpecialStatuses[NUMERO_COMBATIENTES];
extern u16 gIntroSlideFlags;
extern u8 gSentPokesToOpponent[2];
extern struct BattleScripting gBattleScripting;
extern struct Combate *gCombate;
extern struct BattleResources *gBattleResources;
extern u8 gActionSelectionCursor[NUMERO_COMBATIENTES];
extern u8 gMoveSelectionCursor[NUMERO_COMBATIENTES];
extern u8 gBattlerStatusSummaryTaskId[NUMERO_COMBATIENTES];
extern u8 gBattlerInMenuId;
extern bool8 gDoingBattleAnim;
extern u8 gPlayerDpadHoldFrames;
extern struct BattleSpriteData *gBattleSpritesDataPtr;
extern struct MonSpritesGfx *gMonSpritesGfxPtr;
extern u16 gBattleMovePower;
extern u16 gMoveToLearn;
extern u32 gFieldStatuses;
extern struct FieldTimer gFieldTimers;
extern u32 gBattlerAbility;
extern const struct BattleMoveEffect gBattleMoveEffects[];

extern void (*gPreBattleCallback1)(void);
extern void (*gBattleMainFunc)(void);
extern u8 gLeveledUpInBattle;
extern u8 gHealthboxSpriteIds[NUMERO_COMBATIENTES];
extern u8 gNumberOfMovesToChoose;
extern u8 gLastUsedBall;
extern u16 gLastThrownBall;
extern u16 gBallToDisplay;
extern bool8 gLastUsedBallMenuPresent;
extern u8 gCategoryIconSpriteId;

static inline bool32 EsTipo(u32 combatiente, u32 tipo)
{
    return (gBattleMons[combatiente].types[TIPO_1] == tipo || gBattleMons[combatiente].types[TIPO_2] == tipo);
}

static inline bool32 EsPrimerTurno(u32 combatiente)
{
    return (gDisableStructs[combatiente].esPrimerTurno);
}

static inline bool32 EstaDormido(u32 combatiente)
{
    return (gBattleMons[combatiente].status1 & STATUS1_SLEEP);
}

static inline bool32 HaSidoDaniado(u32 combatiente)
{
    return gCombate[combatiente].danioRecibido != 0; // Solo por movimientos, no por confusión/retroceso.
}

static inline bool32 IsBattlerAtMaxHp(u32 battler)
{
    return gBattleMons[battler].hp == gBattleMons[battler].maxHP;
}

static inline u32 GetBattlerSide(u32 combatiente)
{
    return (combatiente & BIT_SIDE);
}

static inline struct Pokemon *GetPartyBattlerData(u32 battler)
{
    u32 index = gBattlerPartyIndexes[battler];
    return (GetBattlerSide(battler) == LADO_OPONENTE) ? &gEnemyParty[index] : &gPlayerParty[index];
}

static inline struct Pokemon *GetSideParty(u32 side)
{
    return (side == LADO_JUGADOR) ? gPlayerParty : gEnemyParty;
}

static inline struct Pokemon *GetBattlerParty(u32 battler)
{
    return GetSideParty(GetBattlerSide(battler));
}

static inline bool32 EsContraEntrenador(void)
{
    return (gBattleTypeFlags & COMBATE_ENTRENADOR);
}

static inline bool32 MovimientoEsEfectivo(uq4_12_t resultadoMovimiento)
{
    return (resultadoMovimiento == MOVIMIENTO_POCO_EFECTIVO || resultadoMovimiento == MOVIMIENTO_NEUTRO || resultadoMovimiento == MOVIMIENTO_SUPER_EFECTIVO);
}

static inline bool32 EsMovimientoFisico(u32 movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_FISICA);
}

static inline bool32 EsMovimientoEspecial(u32 movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_ESPECIAL);
}

static inline bool32 EsMovimientoDeEstado(u32 movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_ESTADO);
}

static inline bool32 EsPrimerGolpe(void)
{
    return (gCombate.contadorMultigolpes == 0);
}

static inline bool32 HaceDanioRetroceso(u32 movimiento)
{
    return (gMovimientos[movimiento].retroceso > 0);
}

static inline bool32 EsMovimientoDeSonido(u32 movimiento)
{
    return (gMovimientos[movimiento].soundMove);
}

static inline bool32 EsMovimientoDeClima(u32 movimiento)
{
    return (gMovimientos[movimiento].climatico);
}

static inline bool32 EsMovimientoDeCabeza(u32 movimiento)
{
    return (gMovimientos[movimiento].cabezazo);
}

static inline bool32 EsClimaCombateSol(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_SOL_HABILIDAD || clima == CLIMA_COMBATE_SOL_MOVIMIENTO);
}

static inline bool32 EsClimaCombateLluvia(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_LLUVIA_HABILIDAD || clima == CLIMA_COMBATE_LLUVIA_MOVIMIENTO);
}

static inline bool32 EsClimaCombateArena(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_ARENA_HABILIDAD || clima == CLIMA_COMBATE_ARENA_MOVIMIENTO);
}

static inline bool32 EsClimaCombateNieve(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_NIEVE_HABILIDAD || clima == CLIMA_COMBATE_NIEVE_MOVIMIENTO);
}

static inline bool32 EsHabilidadClimatica(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_LLUVIA_HABILIDAD
         || clima == CLIMA_COMBATE_SOL_HABILIDAD
         || clima == CLIMA_COMBATE_ARENA_HABILIDAD
         || clima == CLIMA_COMBATE_NIEVE_HABILIDAD);
}

static inline bool32 EsClimaPorMovimiento(enum ClimasCombate clima)
{
    return (clima != CLIMA_COMBATE_NINGUNO && !EsClimaHabilidad(clima));
}

static inline bool32 ArgumentoMovimientoCoincideClima(enum ClimasMovimientos climaMovimiento)
{
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    switch (climaMovimiento)
    {
        case CLIMA_MOVIMIENTO_SOL:
            return EsClimaCombateSol(climaCombate);
        case CLIMA_MOVIMIENTO_LLUVIA:
            return EsClimaCombateLluvia(climaCombate);
        case CLIMA_MOVIMIENTO_ARENA:
            return EsClimaCombateArena(climaCombate);
        case CLIMA_MOVIMIENTO_NIEVE:
            return EsClimaCombateNieve(climaCombate);
    }
    return FALSE;
}

static inline bool32 ClimaTieneEfecto(void)
{
    return !EstaHabilidadEnCampo(ABILITY_SEPTIMO_CIELO);
}

static inline u32 CategoriaMovimiento(u32 movimiento)
{
    return gMovimientos[movimiento].category;
}

static inline enum PrioridadMovimientos PrioridadMovimiento(u32 movimiento)
{
    return gMovimientos[movimiento].prioridad;
}

#endif // GUARD_BATTLE_H

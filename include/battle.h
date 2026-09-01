#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

// should they be included here or included individually by every file?
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/abilities.h"
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
    u16 usesProtectCounter : 1; // Revisar
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
    u8 posicionFijada;   // hueco al que apunta un movimiento encadenado
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
    u8 chargeTimer : 4;
    u8 rechargeTimer;
    u8 autotomizeCount;
    u8 throatChopTimer;
    u8 tormentTimer : 4;
    u8 usedMoves : 4;
    u16 trampasEntradaProcesadas;
    bool32 rumianteHaConsumidoBaya;
    bool32 esPrimerTurno;
};

struct ProtectStruct
{
    u32 protected : 1;
    u32 noValidMoves : 1;
    u32 prlzImmobility : 1;
    u32 sleepImmobility : 1;
    u32 confusionSelfDmg : 1;
    u32 chargingTurn : 1;
    u32 usedImprisonedMove : 1;
    u32 loveImmobility : 1;
    u32 usedDisabledMove : 1;
    u32 usedTauntedMove : 1;
    u32 flinchImmobility : 1;
    u32 notFirstStrike : 1;
    u32 usedThroatChopPreventedMove : 1;
    u32 statRaised : 1;
    u16 disableEjectPack : 1;
    u16 statFell : 1;
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
    bool32 habilidadEntranteHecha;
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
    u8 stickyWebBattlerId;
    u8 stickyWebBattlerSide; // Used for Court Change
    u8 enredaderasBattlerId;
    u8 enredaderasBattlerSide;
    u8 auroraVeilTimer;
    u8 auroraVeilBattlerId;
    u8 tailwindTimer;
    u8 tailwindBattlerId;
    // Timers below this point are not swapped by Court Change
    u8 followmeTimer;
    u8 followmeTarget : 3;
    u8 followmePowder : 1; // Rage powder, does not affect grass type pokemon.
    u8 retaliateTimer;
};

// Un u16 por trampa permite consultar o cambiar el lado con una sola operacion
// de 16 bits, sin contadores ni capas. Solo se usan los dos bits inferiores.
struct TrampasEntrada
{
    u16 brasas;
    u16 espinas;
    u16 puasToxicas;
    u16 rocasPuntiagudas;
    u16 puas;
    u16 penitentes;
    u16 redViscosa;
    u16 enredaderas;
};


struct AI_SavedBattleMon
{
    u16 ability;
    enum Movimientos movimientos[MAXIMO_MOVIMIENTOS_POKEMON];
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
    enum Movimientos movimientos[MAXIMO_MOVIMIENTOS_POKEMON];
    u8 estado;   // enum EstadoPrincipal
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
    enum Movimientos ultimoMovimientoUsado[NUMERO_COMBATIENTES];
    u8 hpPercents[NUMERO_COMBATIENTES];
    u16 partnerMove;
    u16 speedStats[NUMERO_COMBATIENTES];                                       // Speed stats for all battles, calculated only once, same way as damages
    s32 simulatedDmg[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAXIMO_MOVIMIENTOS_POKEMON]; // attacker, target, moveIndex
    u8 effectiveness[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAXIMO_MOVIMIENTOS_POKEMON]; // attacker, target, moveIndex
    u8 moveAccuracy[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAXIMO_MOVIMIENTOS_POKEMON];  // attacker, target, moveIndex
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
    s32 score[MAXIMO_MOVIMIENTOS_POKEMON];
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
    enum Movimientos usedMoves[NUMERO_COMBATIENTES][MAXIMO_MOVIMIENTOS_POKEMON];
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
    u16 turnos;
    enum ClimasCombate modo;
    enum OrigenClima origen;
};

struct Combate
{
    u16 contadorTurnos;
    u16 contadorDebilitadosJugador;
    u16 contadorDebilitadosRival;
    u16 numeroCambiosJugador;
    u16 danioRecibido[NUMERO_COMBATIENTES];
    u16 contadorMultigolpes;
    u16 turnosEspacioRaro;
    u16 wrappedMove[NUMERO_COMBATIENTES];
    u16 moveTarget[NUMERO_COMBATIENTES];
    u32 expValue;
    u8 expGettersOrder[PARTY_SIZE]; // First battlers which were sent out, then via exp-share
    u8 expGetterMonId;
    u8 expOrderId : 3;
    u8 expGetterBattlerId : 2;
    u8 givenExpMons;  // Bits for enemy party's pokemon that gave exp to player's party.
    u8 expSentInMons; // As bits for player party mons - not including exp share mons.
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
    s32 IA_Puntuacion[NUMERO_COMBATIENTES][NUMERO_COMBATIENTES][MAXIMO_MOVIMIENTOS_POKEMON]; // AI, target, moves to make debugging easier
    u8 IA_Eleccion[NUMERO_COMBATIENTES];
    u8 IA_Objetivo[NUMERO_COMBATIENTES];
    u8 soulheartBattlerId;
    u8 sameMoveTurns[NUMERO_COMBATIENTES];        // For ECHOED VOICE, number of times the same moves has been SUCCESFULLY used.
    u16 moveEffect2;                              // For Desarme
    u16 changedSpecies[NUMERO_LADOS][PARTY_SIZE]; // For forms when multiple mons can change into the same pokemon.
    u32 objetoPerdido[NUMERO_LADOS][PARTY_SIZE];
    u8 forcedSwitch : 4;             // For each battler
    u8 additionalEffectsCounter : 4; // A counter for the additionalEffects applied by the current move in Cmd_setadditionaleffects
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
    bool16 movimientoEspejoMagicoRebota;
    uq4_12_t resultadoMovimiento;
    enum ResultadoMovimiento resultadoAtaque;
    const u8 *textoResultadoOverride;
    u16 potenciaMovimientosRecibidosTurno[NUMERO_COMBATIENTES];
    struct EfectosFinTurno efectoFinTurno;
    struct Clima clima;
    enum TiposCombate tipoCombate;
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

#define IS_BATTLER_PROTECTED(battlerId) (gProtectStructs[battlerId].protected)

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
    // Las animaciones pasan al Pokemon a una capa de fondo y apagan su sprite.
    // Sigue estando a la vista, solo que dibujado por otro medio, asi que lo que
    // cuelgue de el -la sombra- no debe esconderse por ver el sprite apagado.
    u16 enFondoAnimacion : 1;
    u16 flag_x8 : 1;          // Marcador de que el sprite del pokemon esta siendo usado para mostrar el HP, para que no se muestre el HP en la barra de HP
    u16 transformSpecies;
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
extern bool32 gEsGolpeCritico;
extern const u8 *gBattlescriptCurrInstr;
extern u32 gAccionElegida[NUMERO_COMBATIENTES];
extern const u8 *gSelectionBattleScripts[NUMERO_COMBATIENTES];
extern u16 gLastPrintedMoves[NUMERO_COMBATIENTES];
extern u16 gLastMoves[NUMERO_COMBATIENTES];
extern enum Movimientos gLastLandedMoves[NUMERO_COMBATIENTES];
extern u16 gLastResultingMoves[NUMERO_COMBATIENTES];
extern u16 gLockedMoves[NUMERO_COMBATIENTES];
extern u16 gLastUsedMove;
extern u8 gLastHitBy[NUMERO_COMBATIENTES];
extern u16 gMovimientoElegido[NUMERO_COMBATIENTES];
extern u8 gMarcasGolpe[NUMERO_MARCAS_GOLPE];
extern u8 gCombatienteDebilitado[NUMERO_COMBATIENTES];
extern u32 gSideStatuses[NUMERO_LADOS];
extern struct SideTimer gSideTimers[NUMERO_LADOS];
extern struct TrampasEntrada gTrampasEntrada;
extern u16 gTrampaEntradaActiva;
extern u32 gEstadosTransitorios[NUMERO_COMBATIENTES];
extern struct DisableStruct gDisableStructs[NUMERO_COMBATIENTES];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u32 gEstadoAccion[NUMERO_COMBATIENTES];
extern u8 gEstadoMultiuso;
extern u8 gElegidorTextoMultiple;
extern bool32 gMostrarMensajeBatalla;
// Qué ha pasado en el último cambio de estadística. Es estado interno de C: los
// scripts no lo miran nunca, preguntan con jumpifestadisticaallimite y escriben
// con EscribeTextoCambioEstadistica. Sustituye a los B_MSG_ que indexaban
// gStatUpStringIds / gStatDownStringIds.
enum ResultadoCambioEstadistica
{
    CAMBIO_ESTADISTICA_ATACANTE,   // la estadística del atacante subió o bajó
    CAMBIO_ESTADISTICA_DEFENSOR,   // la del objetivo
    CAMBIO_ESTADISTICA_TOPE,       // ya estaba al máximo o al mínimo
    CAMBIO_ESTADISTICA_SILENCIOSO, // cambió, pero sin mensaje
    CAMBIO_ESTADISTICA_OBJETO,     // lo provocó un objeto equipado
    CAMBIO_ESTADISTICA_MAX_SUBIDA, // Impulso y similares
};

extern enum ResultadoCambioEstadistica gResultadoCambioEstadistica;
// Lo pone ChangeStatBuffs cuando la bajada recae sobre gBattlerTarget; lo consume
// IntentaHabilidadPorBajadaEstadistica.
extern bool32 gBajadaEstadisticaEnObjetivo;
// Lo pone el bucle de Intimidacion antes de cada bajada, para que Cobardia sepa
// que le toca; lo consume IntentaHabilidadPorBajadaEstadistica.
extern bool32 gBajadaEstadisticaPorIntimidacion;
// Distingue si el estado alterado lo causo un movimiento o una habilidad.
extern bool32 gEstadoAlteradoPorHabilidad;

// Por que no prendio un estado alterado. Sustituye a los B_MSG_ que indexaban
// gBRN/gPRLZ/gPSNPreventionStringIds.
enum ResultadoPrevencionEstado
{
    PREVENCION_POR_HABILIDAD_PROPIA,   // la habilidad del objetivo lo impide
    PREVENCION_POR_HABILIDAD_ATACANTE, // la del atacante anula la del objetivo
    PREVENCION_SIN_EFECTO,             // no le hizo nada
};

extern enum ResultadoPrevencionEstado gResultadoPrevencionEstado;

// Banderas para los mensajes cuyo resultado el propio codigo pisa despues, asi que
// no se puede deducir del estado del combate cuando toca imprimir.
extern bool32 gDescansoCuroEstado;
extern bool32 gAbsorbeFuegoSubioPotencia;
extern bool32 gBayaNormalizoEstado;
extern bool32 gCuraEquipoPorAroma;
extern u32 gSacudidasBall;

// Insonorizar frente a Cascabel Cura: mascara de bits, no un indice de mensaje.
#define INSONORIZADO_ATACANTE (1 << 0)
#define INSONORIZADO_ALIADO   (1 << 1)
extern u32 gInsonorizadoCascabel;

enum ResultadoDrenadoras   { DRENADORAS_PUESTAS, DRENADORAS_FALLO, DRENADORAS_INMUNE };
enum ResultadoCambioObjeto { OBJETO_TOMADO, OBJETO_DADO, OBJETO_AMBOS };
enum CuraHierbaMental      { HIERBA_ENAMORAMIENTO, HIERBA_MOFA, HIERBA_BIS, HIERBA_TORMENTO, HIERBA_ANULACION };
enum TipoBarrera           { BARRERA_FALLO, BARRERA_REFLEJO, BARRERA_PANTALLA_LUZ, BARRERA_VELO_SAGRADO };

extern enum ResultadoDrenadoras gResultadoDrenadoras;
extern enum ResultadoCambioObjeto gResultadoCambioObjeto;
extern enum CuraHierbaMental gCuraHierbaMental;
extern enum TipoBarrera gTipoBarreraPuesta;
extern u32 gPosicionCursorSiNo;
extern u8 gBattleOutcome;
extern struct ProtectStruct gProtectStructs[NUMERO_COMBATIENTES];
extern struct SpecialStatus gSpecialStatuses[NUMERO_COMBATIENTES];
extern u16 gIntroSlideFlags;
extern u8 gSentPokesToOpponent[2];
extern struct BattleScripting gBattleScripting;
extern struct Combate *gCombate;
extern enum TiposCombate gTipoCombatePendiente;
void FijaTipoCombate(enum TiposCombate tipo);
extern struct BattleResources *gBattleResources;
extern u8 gActionSelectionCursor[NUMERO_COMBATIENTES];
extern u8 gMoveSelectionCursor[NUMERO_COMBATIENTES];
extern u8 gBattlerInMenuId;
extern bool8 gDoingBattleAnim;
extern struct BattleSpriteData *gBattleSpritesDataPtr;
extern struct MonSpritesGfx *gMonSpritesGfxPtr;
extern u16 gBattleMovePower;
extern u16 gMoveToLearn;
extern u32 gBattlerAbility;
extern const struct BattleMoveEffect gBattleMoveEffects[];

extern void (*gPreBattleCallback1)(void);
extern void (*gBattleMainFunc)(void);
extern u8 gLeveledUpInBattle;
extern u8 gMarcadorSpriteIds[NUMERO_COMBATIENTES];
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
    return gBattleMons[combatiente].estado == ESTADO_SUENO;
}

static inline bool32 HaSidoDaniado(u32 combatiente)
{
    return gCombate->danioRecibido[combatiente] != 0; // Solo por movimientos, no por confusión/retroceso.
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

static inline struct Pokemon *GetBattlerParty(u32 combatiente)
{
    return GetSideParty(GetBattlerSide(combatiente));
}

static inline bool32 MovimientoEsEfectivo(uq4_12_t resultadoMovimiento)
{
    return (resultadoMovimiento == MOVIMIENTO_POCO_EFECTIVO || resultadoMovimiento == MOVIMIENTO_NEUTRO || resultadoMovimiento == MOVIMIENTO_SUPER_EFECTIVO);
}

static inline u32 CategoriaMovimiento(enum Movimientos movimiento)
{
    return gMovimientos[movimiento].category;
}

static inline bool32 EsMovimientoFisico(enum Movimientos movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_FISICA);
}

static inline bool32 EsMovimientoEspecial(enum Movimientos movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_ESPECIAL);
}

static inline bool32 EsMovimientoEstado(enum Movimientos movimiento)
{
    return (CategoriaMovimiento(movimiento) == CATEGORIA_ESTADO);
}

static inline bool32 EsPrimerGolpe(void)
{
    return (gCombate->contadorMultigolpes == 0);
}

static inline bool32 EstaEspacioRaroPuesto(void)
{
    return gCombate->turnosEspacioRaro != 0;
}

static inline bool32 HaceDanioRetroceso(enum Movimientos movimiento)
{
    return (gMovimientos[movimiento].retroceso > 0);
}

static inline bool32 EsMovimientoSonido(enum Movimientos movimiento)
{
    return (gMovimientos[movimiento].soundMove);
}

static inline bool32 EsMovimientoClima(enum Movimientos movimiento)
{
    return (gMovimientos[movimiento].climatico);
}

static inline bool32 EsMovimientoCabeza(enum Movimientos movimiento)
{
    return (gMovimientos[movimiento].cabezazo);
}

static inline bool32 EsMovimientoAltoIndiceCritico(enum Movimientos movimiento)
{
    return (gMovimientos[movimiento].altoIndiceCritico);
}

static inline bool32 EsMovimientoCura(enum Movimientos movimiento)
{
    return gMovimientos[movimiento].curativo;
}

static inline bool32 EstaMovimientoPotenciadoPotenciaBruta(enum Movimientos movimiento)
{
    for (u32 indiceMovimiento = 0; indiceMovimiento < gMovimientos[movimiento].numAdditionalEffects; indiceMovimiento++)
    {
        if (gMovimientos[movimiento].additionalEffects[indiceMovimiento].chance > 0)
            return TRUE;
    }
    return FALSE;
}

static inline bool32 MovimientoImpideEscapar(enum Movimientos movimiento)
{
    switch (gMovimientos[movimiento].effect)
    {
    case EFFECT_MEAN_LOOK:
        return TRUE;
    default:
        return MoveHasAdditionalEffect(movimiento, MOVE_EFFECT_PREVENT_ESCAPE) || MoveHasAdditionalEffect(movimiento, MOVE_EFFECT_WRAP);
    }
}

static inline bool32 EsClimaCombateSol(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_SOL);
}

static inline bool32 EsClimaCombateLluvia(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_LLUVIA);
}

static inline bool32 EsClimaCombateArena(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_ARENA);
}

static inline bool32 EsClimaCombateNieve(enum ClimasCombate clima)
{
    return (clima == CLIMA_COMBATE_NIEVE);
}

static inline bool32 EsClimaPorOverworld(void)
{
    return (gCombate->clima.modo != CLIMA_COMBATE_NINGUNO 
         && gCombate->clima.origen == ORIGEN_CLIMA_OVERWORLD);
}

static inline bool32 EsClimaPorHabilidad(void)
{
    return (gCombate->clima.modo != CLIMA_COMBATE_NINGUNO 
         && gCombate->clima.origen == ORIGEN_CLIMA_HABILIDAD);
}

static inline bool32 EsClimaPorMovimiento(void)
{
    return (gCombate->clima.modo != CLIMA_COMBATE_NINGUNO 
         && gCombate->clima.origen == ORIGEN_CLIMA_MOVIMIENTO);
}

static inline bool32 ClimaMovimientoCoincide(enum ClimasCombate climaMovimiento)
{
    return (ObtenClimaCombate() == climaMovimiento);
}

static inline bool32 EstadoMovimientoCoincide(u32 combatiente, u32 estadoMovimiento)
{
    return gBattleMons[combatiente].estado == estadoMovimiento;
}

static inline bool32 ClimaTieneEfecto(void)
{
    return !EstaHabilidadEnCampo(ABILITY_SEPTIMO_CIELO);
}

static inline enum PrioridadMovimientos PrioridadMovimiento(enum Movimientos movimiento)
{
    return gMovimientos[movimiento].prioridad;
}

static inline enum TiposPokemon ObtenTipoCombatiente(u32 combatiente, enum IndiceTiposPokemon indiceTipo)
{
    enum TiposPokemon tipo1, tipo2;
    tipo1 = gBattleMons[combatiente].types[TIPO_1];
    tipo2 = gBattleMons[combatiente].types[TIPO_2];

    if (gBattleResources->flags[combatiente] & RESOURCE_FLAG_ROOST)
    {
        if (tipo1 == TIPO_VOLADOR && tipo2 == TIPO_VOLADOR)
            return TIPO_NORMAL;

        if (tipo1 == TIPO_VOLADOR)
            return tipo2;

        if (tipo2 == TIPO_VOLADOR)
            return tipo1;
    }

    return (indiceTipo == TIPO_1) ? tipo1 : tipo2;
}

static inline bool32 EsTipoDual(u32 combatiente)
{
    return ObtenTipoCombatiente(combatiente, TIPO_1) != ObtenTipoCombatiente(combatiente, TIPO_2);
}

static inline bool32 EsCombateContraEntrenador(enum TiposCombate tipoCombate)
{
    return (tipoCombate == COMBATE_ENTRENADOR);
}

static inline bool32 EsCombateContraSalvaje(enum TiposCombate tipoCombate)
{
    return (tipoCombate == COMBATE_SALVAJE);
}

static inline bool32 EsCombateContraLegendario(enum TiposCombate tipoCombate)
{
    return (tipoCombate == COMBATE_LEGENDARIO);
}

#endif // GUARD_BATTLE_H

#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_controllers.h"
#include "battle_setup.h"
#include "data.h"
#include "debug.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "util.h"
#include "script.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/trainers.h"

static u32 ChooseMoveOrAction_Singles(u32 battlerAI);
static u32 ChooseMoveOrAction_Doubles(u32 battlerAI);
static inline void BattleAI_DoAIProcessing(struct AI_ThinkingStruct *aiThink, u32 battlerAI, u32 battlerDef);

// ewram
EWRAM_DATA u8 sBattler_AI = 0;
EWRAM_DATA AIScoreFunc sDynamicAIFunc = NULL;

// const rom data
static s32 AI_CheckBadMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_TryToFaint(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_CheckViability(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_ForceSetupFirstTurn(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_Risky(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PreferStrongestMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PreferRelevo(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_HPAware(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_DoubleBattle(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_PowerfulStatus(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);
static s32 AI_DynamicFunc(u32 battlerAtk, u32 battlerDef, u32 move, s32 score);

static s32 (*const sBattleAIFuncTable[])(u32, u32, u32, s32) =
    {
        [0] = AI_CheckBadMove,        // AI_FLAG_CHECK_BAD_MOVE
        [1] = AI_TryToFaint,          // AI_FLAG_TRY_TO_FAINT
        [2] = AI_CheckViability,      // AI_FLAG_CHECK_VIABILITY
        [3] = AI_ForceSetupFirstTurn, // AI_FLAG_FORCE_SETUP_FIRST_TURN
        [4] = AI_Risky,               // AI_FLAG_RISKY
        [5] = AI_PreferStrongestMove, // AI_FLAG_PREFER_STRONGEST_MOVE
        [6] = AI_PreferRelevo,        // AI_FLAG_PREFER_BATON_PASS
        [7] = AI_DoubleBattle,        // AI_FLAG_DOUBLE_BATTLE
        [8] = AI_HPAware,             // AI_FLAG_HP_AWARE
        [9] = AI_PowerfulStatus,      // AI_FLAG_POWERFUL_STATUS
        [10] = NULL,                  // AI_FLAG_NEGATE_UNAWARE
        [11] = NULL,                  // AI_FLAG_WILL_SUICIDE
        [12] = NULL,                  // Unused
        [13] = NULL,                  // Unused
        [14] = NULL,                  // Unused
        [15] = NULL,                  // Unused
        [16] = NULL,                  // Unused
        [17] = NULL,                  // Unused
        [18] = NULL,                  // Unused
        [19] = NULL,                  // Unused
        [20] = NULL,                  // Unused
        [21] = NULL,                  // Unused
        [22] = NULL,                  // Unused
        [23] = NULL,                  // Unused
        [24] = NULL,                  // Unused
        [25] = NULL,                  // Unused
        [26] = NULL,                  // Unused
        [27] = NULL,                  // Unused
        [28] = AI_DynamicFunc,        // AI_FLAG_DYNAMIC_FUNC
        [29] = NULL,                  // Unused
        [30] = NULL,                  // Unused
        [31] = NULL,                  // Unused
};

// Functions
void BattleAI_SetupItems(void)
{
    s32 i;
    u8 *data = (u8 *)BATTLE_HISTORY;
    const u16 *items = GetTrainerItemsFromId(gTrainerBattleOpponent);

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    // Items are allowed to use in ONLY trainer battles.
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (items[i] != ITEM_NONE)
            {
                BATTLE_HISTORY->trainerItems[BATTLE_HISTORY->itemsNo] = items[i];
                BATTLE_HISTORY->itemsNo++;
            }
        }
    }
}

static u32 GetWildAIFlags(void)
{
    u32 avgLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u32 flags = 0;

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        avgLevel = (GetMonData(&gEnemyParty[0], MON_DATA_LEVEL) + GetMonData(&gEnemyParty[1], MON_DATA_LEVEL)) / 2;

    flags |= AI_FLAG_CHECK_BAD_MOVE;
    if (avgLevel >= 20)
        flags |= AI_FLAG_CHECK_VIABILITY;
    if (avgLevel >= 60)
        flags |= AI_FLAG_PREFER_STRONGEST_MOVE;
    if (avgLevel >= 80)
        flags |= AI_FLAG_HP_AWARE;

    if (B_VAR_WILD_AI_FLAGS != 0 && VarGet(B_VAR_WILD_AI_FLAGS) != 0)
        flags |= VarGet(B_VAR_WILD_AI_FLAGS);

    return flags;
}

static u32 GetAIFlags(u16 trainerId)
{
    u32 flags = 0;

    if (trainerId == 0xFFFF)
    {
        flags = GetWildAIFlags();
    }
    else
    {
        flags = GetTrainerAIFlagsFromId(trainerId);
    }

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        flags |= AI_FLAG_DOUBLE_BATTLE;
    }

    // Automatically includes AI_FLAG_SMART_MON_CHOICES to improve smart switching
    if (flags & AI_FLAG_SMART_SWITCHING)
        flags |= AI_FLAG_SMART_MON_CHOICES;

    if (sDynamicAIFunc != NULL)
        flags |= AI_FLAG_DYNAMIC_FUNC;

    return flags;
}

void BattleAI_SetupFlags(void)
{
    AI_THINKING_STRUCT->aiFlags[JUGADOR_IZQUIERDA] = 0; // player has no AI
    AI_THINKING_STRUCT->aiFlags[JUGADOR_DERECHA] = 0;   // player

    if (DEBUG_OVERWORLD_MENU && gIsDebugBattle)
    {
        AI_THINKING_STRUCT->aiFlags[OPONENTE_IZQUIERDA] = gDebugAIFlags;
        AI_THINKING_STRUCT->aiFlags[OPONENTE_DERECHA] = gDebugAIFlags;
        return;
    }

    AI_THINKING_STRUCT->aiFlags[OPONENTE_IZQUIERDA] = GetAIFlags(gTrainerBattleOpponent);
    AI_THINKING_STRUCT->aiFlags[OPONENTE_DERECHA] = AI_THINKING_STRUCT->aiFlags[OPONENTE_IZQUIERDA];
}

void BattleAI_SetupAIData(u8 defaultScoreMoves, u32 battler)
{
    s32 i;
    u8 moveLimitations;
    u32 flags[NUMERO_COMBATIENTES];

    // Clear AI data but preserve the flags.
    memcpy(&flags[0], &AI_THINKING_STRUCT->aiFlags[0], sizeof(u32) * NUMERO_COMBATIENTES);
    memset(AI_THINKING_STRUCT, 0, sizeof(struct AI_ThinkingStruct));
    memcpy(&AI_THINKING_STRUCT->aiFlags[0], &flags[0], sizeof(u32) * NUMERO_COMBATIENTES);

    // Conditional score reset, unlike Ruby.
    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (defaultScoreMoves & 1)
            SET_SCORE(battler, i, AI_SCORE_DEFAULT);
        else
            SET_SCORE(battler, i, 0);

        defaultScoreMoves >>= 1;
    }

    moveLimitations = AI_DATA->moveLimitations[battler];

    // Ignore moves that aren't possible to use.
    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if ((1u << i) & moveLimitations)
            SET_SCORE(battler, i, 0);
    }

    // sBattler_AI = battler;
    gBattlerTarget = SetRandomTarget(sBattler_AI);
    gCombate->IA_Objetivo[sBattler_AI] = gBattlerTarget;
}

u32 BattleAI_ChooseMoveOrAction(void)
{
    u32 ret;

    if (!EsCombateContraEntrenador(gCombate->tipoCombate))
        ret = ChooseMoveOrAction_Singles(sBattler_AI);
    else
        ret = ChooseMoveOrAction_Doubles(sBattler_AI);

    // Clear protect structures, some flags may be set during AI calcs
    // e.g. prioridadBromista from PrioridadMovimientoMasHabilidad
    memset(&gProtectStructs, 0, NUMERO_COMBATIENTES * sizeof(struct ProtectStruct));
    return ret;
}

static void CopyBattlerDataToAIParty(u32 bPosition, u32 side)
{
    u32 battler = bPosition;
    struct AIPartyMon *aiMon = &AI_PARTY->mons[side][gBattlerPartyIndexes[battler]];
    struct BattlePokemon *bMon = &gBattleMons[battler];

    aiMon->species = bMon->species;
    aiMon->level = bMon->level;
    aiMon->status = bMon->status1;
    aiMon->gender = GetBattlerGender(battler);
    aiMon->isFainted = FALSE;
    aiMon->wasSentInBattle = TRUE;
    aiMon->switchInCount++;
}

void AI_InitPartyStruct(void)
{
    u32 i;
    bool32 isOmniscient = (AI_THINKING_STRUCT->aiFlags[OPONENTE_IZQUIERDA] & AI_FLAG_OMNISCIENT) || (AI_THINKING_STRUCT->aiFlags[OPONENTE_DERECHA] & AI_FLAG_OMNISCIENT);
    struct Pokemon *mon;

    AI_PARTY->count[LADO_JUGADOR] = gPlayerPartyCount;
    AI_PARTY->count[LADO_OPONENTE] = gEnemyPartyCount;

    // Save first 2 or 4(in doubles) mons
    CopyBattlerDataToAIParty(JUGADOR_IZQUIERDA, LADO_JUGADOR);
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        CopyBattlerDataToAIParty(JUGADOR_DERECHA, LADO_JUGADOR);

    // Find fainted mons
    for (i = 0; i < AI_PARTY->count[LADO_JUGADOR]; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
            AI_PARTY->mons[LADO_JUGADOR][i].isFainted = TRUE;

        if (isOmniscient)
        {
            u32 j;
            mon = &gPlayerParty[i];
            AI_PARTY->mons[LADO_JUGADOR][i].item = GetMonData(mon, MON_DATA_HELD_ITEM);
            AI_PARTY->mons[LADO_JUGADOR][i].heldEffect = ItemId_GetHoldEffect(AI_PARTY->mons[LADO_JUGADOR][i].item);
            AI_PARTY->mons[LADO_JUGADOR][i].ability = GetMonAbility(mon);
            for (j = 0; j < MAXIMO_MOVIMIENTOS_POKEMON; j++)
                AI_PARTY->mons[LADO_JUGADOR][i].movimientos[j] = GetMonData(mon, MON_DATA_MOVE1 + j);
        }
    }
}

void AI_UpdateSwitchInData(u32 battler)
{
    u32 i;
    u32 side = GetBattlerSide(battler);
    struct AIPartyMon *aiMon = &AI_PARTY->mons[side][gBattlerPartyIndexes[battler]];

    // See if the switched-in mon has been already in battle
    if (aiMon->wasSentInBattle)
    {
        if (aiMon->ability)
            BATTLE_HISTORY->abilities[battler] = aiMon->ability;
        if (aiMon->heldEffect)
            BATTLE_HISTORY->itemEffects[battler] = aiMon->heldEffect;
        for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
        {
            if (aiMon->movimientos[i])
                BATTLE_HISTORY->usedMoves[battler][i] = aiMon->movimientos[i];
        }
        aiMon->switchInCount++;
        aiMon->status = gBattleMons[battler].status1; // Copy status, because it could've been changed in battle.
    }
    else // If not, copy the newly switched-in mon in battle and clear battle history.
    {
        ClearBattlerMoveHistory(battler);
        ClearBattlerAbilityHistory(battler);
        ClearBattlerItemEffectHistory(battler);
        CopyBattlerDataToAIParty(battler, side);
    }
}

void AI_UpdateFaintData(u32 battler)
{
    struct AIPartyMon *aiMon = &AI_PARTY->mons[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
    ClearBattlerMoveHistory(battler);
    ClearBattlerAbilityHistory(battler);
    ClearBattlerItemEffectHistory(battler);
    aiMon->isFainted = TRUE;
}

void SetBattlerAIData(u32 battler, struct AILogicData *aiData)
{
    u32 ability, holdEffect;

    ability = aiData->abilities[battler] = AI_DecideKnownAbilityForTurn(battler);
    aiData->items[battler] = gBattleMons[battler].item;
    holdEffect = aiData->holdEffects[battler] = AI_DecideHoldEffectForTurn(battler);
    aiData->holdEffectParams[battler] = GetBattlerHoldEffectParam(battler);
    aiData->ultimoMovimientoUsado[battler] = gLastMoves[battler];
    aiData->hpPercents[battler] = GetHealthPercentage(battler);
    aiData->moveLimitations[battler] = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    aiData->speedStats[battler] = GetBattlerTotalSpeedStatArgs(battler, ability, holdEffect);
}

static u32 AI_SetMoveAccuracy(struct AILogicData *aiData, u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 accuracy;
    u32 abilityAtk = aiData->abilities[battlerAtk];
    u32 abilityDef = aiData->abilities[battlerDef];
    if (gMovimientos[move].accuracy == 0)
        accuracy = 100;
    else
        accuracy = GetTotalAccuracy(battlerAtk, battlerDef, move, abilityAtk, abilityDef, aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]);

    return accuracy;
}

static void SetBattlerAIMovesData(struct AILogicData *aiData, u32 battlerAtk, u32 battlersCount, enum ClimasCombate climaCombate)
{
    u32 battlerDef, moveIndex, move;
    SaveBattlerData(battlerAtk);
    enum Movimientos *moves = ObtenMovimientos(battlerAtk);

    SetBattlerData(battlerAtk);

    // Simulate dmg for both ai controlled mons and for player controlled mons.
    for (battlerDef = 0; battlerDef < battlersCount; battlerDef++)
    {
        if (battlerAtk == battlerDef || !IsBattlerAlive(battlerDef))
            continue;

        SaveBattlerData(battlerDef);
        SetBattlerData(battlerDef);
        for (moveIndex = 0; moveIndex < MAXIMO_MOVIMIENTOS_POKEMON; moveIndex++)
        {
            s32 simulatedDmg = 0;
            u8 effectiveness = AI_EFFECTIVENESS_x0;
            move = moves[moveIndex];

            if (move != 0 && move != 0xFFFF
                //&& !EsMovimientoEstado(gMovimientos[move])  /* we want to get effectiveness and accuracy of status moves */
                && !(aiData->moveLimitations[battlerAtk] & (1u << moveIndex)))
            {
                simulatedDmg = AI_CalcDamage(move, battlerAtk, battlerDef, &effectiveness, climaCombate);
                aiData->moveAccuracy[battlerAtk][battlerDef][moveIndex] = AI_SetMoveAccuracy(aiData, battlerAtk, battlerDef, move);
            }
            aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = simulatedDmg;
            aiData->effectiveness[battlerAtk][battlerDef][moveIndex] = effectiveness;
        }
        RestoreBattlerData(battlerDef);
    }
    RestoreBattlerData(battlerAtk);
}

void SetAILogicDataForTurn(struct AILogicData *aiData)
{
    u32 battlerAtk, battlersCount;
    enum ClimasCombate climaCombate;

    memset(aiData, 0, sizeof(struct AILogicData));

    climaCombate = ObtenClimaCombate();

    // get/assume all battler data and simulate AI damage
    battlersCount = gBattlersCount;

    AI_DATA->aiCalcInProgress = TRUE;
    for (battlerAtk = 0; battlerAtk < battlersCount; battlerAtk++)
    {
        if (!IsBattlerAlive(battlerAtk))
            continue;

        SetBattlerAIData(battlerAtk, aiData);
    }

    for (battlerAtk = 0; battlerAtk < battlersCount; battlerAtk++)
    {
        if (!IsBattlerAlive(battlerAtk))
            continue;

        SetBattlerAIMovesData(aiData, battlerAtk, battlersCount, climaCombate);
    }
    AI_DATA->aiCalcInProgress = FALSE;
}

static u32 ChooseMoveOrAction_Singles(u32 battlerAI)
{
    u8 currentMoveArray[MAXIMO_MOVIMIENTOS_POKEMON];
    u8 consideredMoveArray[MAXIMO_MOVIMIENTOS_POKEMON];
    u32 numOfBestMoves;
    s32 i;
    u32 flags = AI_THINKING_STRUCT->aiFlags[battlerAI];

    AI_DATA->partnerMove = 0; // no ally
    while (flags != 0)
    {
        if (flags & 1)
        {
            BattleAI_DoAIProcessing(AI_THINKING_STRUCT, battlerAI, gBattlerTarget);
        }
        flags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
    }

    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        gCombate->IA_Puntuacion[battlerAI][gBattlerTarget][i] = AI_THINKING_STRUCT->score[i];
    }

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (gBattleMons[battlerAI].movimientos[i] != MOVE_NONE)
        {
            // In ruby, the order of these if statements is reversed.
            if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
            {
                currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }
    return consideredMoveArray[Random() % numOfBestMoves];
}

static u32 ChooseMoveOrAction_Doubles(u32 battlerAI)
{
    s32 i, j;
    u32 flags;
    s32 bestMovePointsForTarget[NUMERO_COMBATIENTES];
    u8 mostViableTargetsArray[NUMERO_COMBATIENTES];
    u8 actionOrMoveIndex[NUMERO_COMBATIENTES];
    s32 mostViableMovesScores[MAXIMO_MOVIMIENTOS_POKEMON];
    u8 mostViableMovesIndices[MAXIMO_MOVIMIENTOS_POKEMON];
    u32 mostViableTargetsNo;
    u32 mostViableMovesNo;
    s32 mostMovePoints;

    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        if (i == battlerAI || gBattleMons[i].hp == 0)
        {
            actionOrMoveIndex[i] = 0xFF;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            BattleAI_SetupAIData(0xF, battlerAI);
            gBattlerTarget = i;
            AI_DATA->partnerMove = GetAllyChosenMove(battlerAI);
            AI_THINKING_STRUCT->aiLogicId = 0;
            AI_THINKING_STRUCT->movesetIndex = 0;
            flags = AI_THINKING_STRUCT->aiFlags[sBattler_AI];

            while (flags != 0)
            {
                if (flags & 1)
                {
                    BattleAI_DoAIProcessing(AI_THINKING_STRUCT, battlerAI, gBattlerTarget);
                }
                flags >>= 1;
                AI_THINKING_STRUCT->aiLogicId++;
            }

            mostViableMovesScores[0] = AI_THINKING_STRUCT->score[0];
            mostViableMovesIndices[0] = 0;
            mostViableMovesNo = 1;
            for (j = 1; j < MAXIMO_MOVIMIENTOS_POKEMON; j++)
            {
                if (gBattleMons[battlerAI].movimientos[j] != MOVE_NONE)
                {
                    if (mostViableMovesScores[0] == AI_THINKING_STRUCT->score[j])
                    {
                        mostViableMovesScores[mostViableMovesNo] = AI_THINKING_STRUCT->score[j];
                        mostViableMovesIndices[mostViableMovesNo] = j;
                        mostViableMovesNo++;
                    }
                    if (mostViableMovesScores[0] < AI_THINKING_STRUCT->score[j])
                    {
                        mostViableMovesScores[0] = AI_THINKING_STRUCT->score[j];
                        mostViableMovesIndices[0] = j;
                        mostViableMovesNo = 1;
                    }
                }
            }
            actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
            bestMovePointsForTarget[i] = mostViableMovesScores[0];

            // Don't use a move against ally if it has less than 100 points.
            if (i == ALIADO(battlerAI) && bestMovePointsForTarget[i] < AI_SCORE_DEFAULT)
            {
                bestMovePointsForTarget[i] = -1;
            }

            for (j = 0; j < MAXIMO_MOVIMIENTOS_POKEMON; j++)
            {
                gCombate->IA_Puntuacion[battlerAI][gBattlerTarget][j] = AI_THINKING_STRUCT->score[j];
            }
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < NUMERO_COMBATIENTES; i++)
    {
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattlerTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    gCombate->IA_Objetivo[battlerAI] = gBattlerTarget;
    return actionOrMoveIndex[gBattlerTarget];
}

static inline bool32 ShouldConsiderMoveForBattler(u32 battlerAI, u32 battlerDef, u32 move)
{
    if (battlerAI == ALIADO(battlerDef))
    {
        if (gMovimientos[move].target == MOVE_TARGET_BOTH || gMovimientos[move].target == MOVE_TARGET_OPPONENTS_FIELD)
            return FALSE;
    }
    return TRUE;
}

static inline void BattleAI_DoAIProcessing(struct AI_ThinkingStruct *aiThink, u32 battlerAI, u32 battlerDef)
{
    do
    {
        if (gBattleMons[battlerAI].pp[aiThink->movesetIndex] == 0)
            aiThink->moveConsidered = MOVE_NONE;
        else
            aiThink->moveConsidered = gBattleMons[battlerAI].movimientos[aiThink->movesetIndex];

        // There is no point in calculating scores for all 3 battlers(2 opponents + 1 ally) with certain moves.
        if (aiThink->moveConsidered != MOVE_NONE && aiThink->score[aiThink->movesetIndex] > 0 && ShouldConsiderMoveForBattler(battlerAI, battlerDef, aiThink->moveConsidered))
        {
            if (aiThink->aiLogicId < ARRAY_COUNT(sBattleAIFuncTable) && sBattleAIFuncTable[aiThink->aiLogicId] != NULL)
            {
                // Call AI function
                aiThink->score[aiThink->movesetIndex] =
                    sBattleAIFuncTable[aiThink->aiLogicId](battlerAI,
                                                           battlerDef,
                                                           aiThink->moveConsidered,
                                                           aiThink->score[aiThink->movesetIndex]);
            }
        }
        else
        {
            aiThink->score[aiThink->movesetIndex] = 0;
        }
        aiThink->movesetIndex++;
    } while (aiThink->movesetIndex < MAXIMO_MOVIMIENTOS_POKEMON);

    aiThink->movesetIndex = 0;
}

// AI Score Functions
// AI_FLAG_CHECK_BAD_MOVE - decreases move scores
static s32 AI_CheckBadMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // move data
    u32 moveEffect = gMovimientos[move].effect;
    s32 moveType;
    u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, move);
    struct AILogicData *aiData = AI_DATA;
    u32 effectiveness = aiData->effectiveness[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex];
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;
    enum ClimasCombate climaCombate = ObtenClimaCombate();
    enum Movimientos movimientoPredecido = aiData->ultimoMovimientoUsado[battlerDef];

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    moveType = TipoMovimiento(move, battlerAtk);

    if (gMovimientos[move].powderMove
     && !IsAffectedByPowder(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef]))
        RETURN_SCORE_MINUS(10);

    if (IsSemiInvulnerable(battlerDef, move)
     && moveEffect != EFFECT_SEMI_INVULNERABLE
     && AI_IsFaster(battlerAtk, battlerDef, move))
        RETURN_SCORE_MINUS(10);

    if (IsTwoTurnNotSemiInvulnerableMove(battlerAtk, move)
     && CanTargetFaintAI(battlerDef, battlerAtk))
        RETURN_SCORE_MINUS(10);

    // check if negates type
    switch (effectiveness)
    {
    case AI_EFFECTIVENESS_x0:
        RETURN_SCORE_MINUS(20);
        break;
    case AI_EFFECTIVENESS_x0_25:
        RETURN_SCORE_MINUS(10);
        break;
    }

    // check non-user target
    if (!(moveTarget & MOVE_TARGET_USER))
    {
        // target ability checks
        if (!DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
        {
            if (CanAbilityBlockMove(battlerAtk, battlerDef, move, aiData->abilities[battlerDef]))
                RETURN_SCORE_MINUS(20);

            if (CanAbilityAbsorbMove(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, moveType))
                RETURN_SCORE_MINUS(20);

            switch (aiData->abilities[battlerDef])
            {
            case ABILITY_MAGIC_GUARD:
                switch (moveEffect)
                {
                case EFFECT_POISON:
                case EFFECT_WILL_O_WISP:
                case EFFECT_TOXIC:
                case EFFECT_LEECH_SEED:
                    ADJUST_SCORE(-5);
                    break;
                case EFFECT_CURSE:
                    if (EsTipo(battlerAtk, TIPO_FANTASMA)) // Don't use Curse if you're a ghost type vs a Magic Guard user, they'll take no damage.
                        ADJUST_SCORE(-5);
                    break;
                }
                break;
            case ABILITY_GUARDA:
                if (effectiveness == AI_EFFECTIVENESS_x1)
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_JUSTIFIED:
                if (!EsMovimientoEstado(move) && (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA || moveType == TIPO_DRAGON))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_RATTLED:
                if (!EsMovimientoEstado(move) && (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA || moveType == TIPO_BICHO))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_ALAS_HIDROFOBAS:
                if (!EsMovimientoEstado(move) && (moveType == TIPO_AGUA))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_RESPONDON:
                if (IsStatLoweringEffect(moveEffect))
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_CLEAR_BODY:
            case ABILITY_WHITE_SMOKE:
                if (IsStatLoweringEffect(moveEffect))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_DEFIANT:
            case ABILITY_COMPETITIVE:
                if (IsStatLoweringEffect(moveEffect) && !IS_TARGETING_PARTNER(battlerAtk, battlerDef))
                    RETURN_SCORE_MINUS(8);
                break;
            } // def ability checks

            // target partner ability checks & not attacking partner
            if (isDoubleBattle)
            {
                if (CanPartnerAbilityBlockMove(battlerAtk, battlerDef, move, aiData->abilities[ALIADO(battlerDef)]))
                    RETURN_SCORE_MINUS(20);

                switch (aiData->abilities[ALIADO(battlerDef)])
                {
                case ABILITY_LIGHTNING_ROD:
                    if (moveType == TIPO_ELECTRICO && !IsMoveRedirectionPrevented(move, aiData->abilities[battlerAtk]))
                        RETURN_SCORE_MINUS(20);
                    break;
                case ABILITY_STORM_DRAIN:
                    if (moveType == TIPO_AGUA && !IsMoveRedirectionPrevented(move, aiData->abilities[battlerAtk]))
                        RETURN_SCORE_MINUS(20);
                    break;
                }
            } // def partner ability checks
        } // ignore def ability check

        // gen7+ dark type mons immune to priority->elevated moves from prankster
        if (EsTipo(battlerDef, TIPO_SINIESTRO) && aiData->abilities[battlerAtk] == ABILITY_BROMISTA && EsMovimientoEstado(move) && !(moveTarget & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_USER)))
            RETURN_SCORE_MINUS(10);
    } // end check MOVE_TARGET_USER

    // the following checks apply to any target (including user)

    // throat chop check
    if (gDisableStructs[battlerAtk].throatChopTimer && EsMovimientoSonido(move))
        return 0; // Can't even select move at all

    // check move effects
    switch (moveEffect)
    {
    case EFFECT_HIT: // only applies to Vital Throw
        if (PrioridadMovimiento(move) == PRIORIDAD_MOVIMIENTO_NEGATIVA && AI_IsFaster(battlerAtk, battlerDef, move) && aiData->hpPercents[battlerAtk] < 40)
            ADJUST_SCORE(-2); // don't want to move last
        break;
    default:
        break; // check move damage
    case EFFECT_SLEEP:
        if (!AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_EXPLOSION:
        if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE))
            ADJUST_SCORE(-2);

        if (effectiveness == AI_EFFECTIVENESS_x0)
        {
            ADJUST_SCORE(-10);
        }
        else if (EstaHabilidadEnCampo(ABILITY_DAMP) && !DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
        {
            ADJUST_SCORE(-10);
        }
        else if (CountUsablePartyMons(battlerAtk) == 0)
        {
            if (CountUsablePartyMons(battlerDef) != 0)
                ADJUST_SCORE(-10);
            else
                ADJUST_SCORE(-1);
        }
        break;
        // stat raising effects
    case EFFECT_ATTACK_UP:
    case EFFECT_ATTACK_UP_2:
    case EFFECT_ATTACK_UP_USER_ALLY:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DEFENSE_UP:
    case EFFECT_DEFENSE_UP_2:
    case EFFECT_DEFENSE_UP_3:
    case EFFECT_DEFENSE_CURL:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPECIAL_ATTACK_UP:
    case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE_ESPECIAL) || !HasMoveWithCategory(battlerAtk, CATEGORIA_ESPECIAL))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPECIAL_DEFENSE_UP:
    case EFFECT_SPECIAL_DEFENSE_UP_2:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA_ESPECIAL))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ACCURACY_UP:
    case EFFECT_ACCURACY_UP_2:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_PRECISION))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_EVASION_UP:
    case EFFECT_EVASION_UP_2:
    case EFFECT_MINIMIZE:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_EVASION))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_COSMIC_POWER:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA_ESPECIAL))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_BULK_UP:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_CALM_MIND:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE_ESPECIAL))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA_ESPECIAL))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_DRAGON_DANCE:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_VELOCIDAD))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_COIL:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_PRECISION))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
            ADJUST_SCORE(-8);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-6);
        break;
    case EFFECT_ATTACK_ACCURACY_UP: // hone claws
        if (aiData->abilities[battlerAtk] != ABILITY_RESPONDON)
        {
            if (gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE] >= ESTADISTICA_MAS_6 && (gBattleMons[battlerAtk].statStages[ESTADISTICA_PRECISION] >= ESTADISTICA_MAS_6 || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA)))
                ADJUST_SCORE(-10);
            break;
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_CHARGE:
        if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP)
            ADJUST_SCORE(-20);
        else if (!HasMoveWithType(battlerAtk, TIPO_ELECTRICO))
            ADJUST_SCORE(-10);
        else if (B_CHARGE_SPDEF_RAISE >= GEN_5 && !BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA_ESPECIAL))
            ADJUST_SCORE(-5);
        break;
    case EFECTO_SUBE_ATAQUE_ESPECIAL_VELOCIDAD:
        if (gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE_ESPECIAL] >= ESTADISTICA_MAS_6 || !HasMoveWithCategory(battlerAtk, CATEGORIA_ESPECIAL))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_VELOCIDAD))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_SHIFT_GEAR:
        if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
            ADJUST_SCORE(-10);
        else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_VELOCIDAD))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_SHELL_SMASH:
        if (aiData->abilities[battlerAtk] == ABILITY_RESPONDON)
        {
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
                ADJUST_SCORE(-10);
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA_ESPECIAL))
                ADJUST_SCORE(-8);
        }
        else
        {
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
                ADJUST_SCORE(-10);
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE_ESPECIAL) || !HasMoveWithCategory(battlerAtk, CATEGORIA_ESPECIAL))
                ADJUST_SCORE(-8);
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_VELOCIDAD))
                ADJUST_SCORE(-6);
        }
        break;
    case EFFECT_GROWTH:
    case EFFECT_ATTACK_SPATK_UP: // work up
        if ((!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) && !BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE_ESPECIAL)) || (!TieneMovimientoOfensivo(battlerAtk)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_GEAR_UP:
        if (aiData->abilities[battlerAtk] == ABILITY_PLUS || aiData->abilities[battlerAtk] == ABILITY_MINUS)
        {
            // same as growth, work up
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
                ADJUST_SCORE(-10);
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE_ESPECIAL) || !HasMoveWithCategory(battlerAtk, CATEGORIA_ESPECIAL))
                ADJUST_SCORE(-8);
            break;
        }
        else if (!isDoubleBattle)
        {
            ADJUST_SCORE(-10); // no partner and our stats wont rise, so don't use
        }

        if (isDoubleBattle)
        {
            if (aiData->abilities[ALIADO(battlerAtk)] == ABILITY_PLUS || aiData->abilities[ALIADO(battlerAtk)] == ABILITY_MINUS)
            {
                if ((!BattlerStatCanRise(ALIADO(battlerAtk), aiData->abilities[ALIADO(battlerAtk)], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA)) && (!BattlerStatCanRise(ALIADO(battlerAtk), aiData->abilities[ALIADO(battlerAtk)], ESTADISTICA_ATAQUE_ESPECIAL) || !HasMoveWithCategory(battlerAtk, CATEGORIA_ESPECIAL)))
                    ADJUST_SCORE(-10);
            }
            else if (aiData->abilities[battlerAtk] != ABILITY_PLUS && aiData->abilities[battlerAtk] != ABILITY_MINUS)
            {
                ADJUST_SCORE(-10); // nor our or our partner's ability is plus/minus
            }
        }
        break;
        // stat lowering effects
    case EFFECT_ATTACK_DOWN:
    case EFFECT_ATTACK_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE)) //|| !HasMoveWithCategory(battlerDef, CATEGORIA_FISICA))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_DEFENSE_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPEED_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_VELOCIDAD))
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_SPEED_BOOST)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE_ESPECIAL)) //|| !HasMoveWithCategory(battlerDef, CATEGORIA_ESPECIAL))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_DEFENSA_ESPECIAL))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_ACCURACY_DOWN_2:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_PRECISION))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_EVASION_DOWN:
    case EFFECT_EVASION_DOWN_2:
    case EFFECT_TICKLE:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE))
            ADJUST_SCORE(-10);
        else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_DEFENSA))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_VENOM_DRENCH:
        if (!(gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_VELOCIDAD))
                ADJUST_SCORE(-10);
            else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE_ESPECIAL))
                ADJUST_SCORE(-8);
            else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE))
                ADJUST_SCORE(-6);
        }
        break;
    case EFFECT_RUGIDO_NOBLE:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE_ESPECIAL))
            ADJUST_SCORE(-10);
        else if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_ATAQUE))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_CAPTIVATE:
        if (!AreBattlersOfOppositeGender(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        break;
        // other
    case EFFECT_HAZE:
        if (PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
        {
            ADJUST_SCORE(-10); // partner already using haze
        }
        else
        {
            for (i = ESTADISTICA_ATAQUE; i < NUMERO_ESTADISTICAS_BATALLA; i++)
            {
                if (gBattleMons[battlerAtk].statStages[i] > ESTADISTICA_NEUTRA || gBattleMons[ALIADO(battlerAtk)].statStages[i] > ESTADISTICA_NEUTRA)
                    ADJUST_SCORE(-10); // Don't want to reset our boosted stats
            }
            for (i = ESTADISTICA_ATAQUE; i < NUMERO_ESTADISTICAS_BATALLA; i++)
            {
                if (gBattleMons[battlerDef].statStages[i] < ESTADISTICA_NEUTRA || gBattleMons[ALIADO(battlerDef)].statStages[i] < ESTADISTICA_NEUTRA)
                    ADJUST_SCORE(-10); // Don't want to reset enemy lowered stats
            }
        }
        break;
    case EFFECT_PRESENT:
    case EFFECT_FOCUS_PUNCH:
        // AI_CBM_HighRiskForDamage
        if (aiData->abilities[battlerDef] == ABILITY_GUARDA && effectiveness == AI_EFFECTIVENESS_x1)
            ADJUST_SCORE(-10);
        break;

    case EFFECT_FUERZA_CAMBIO_OBJETIVO:
        if (CountUsablePartyMons(battlerDef) == 0)
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TOXIC_THREAD:
        if (!ShouldLowerStat(battlerDef, aiData->abilities[battlerDef], ESTADISTICA_VELOCIDAD))
            ADJUST_SCORE(-1); // may still want to just poison
        // fallthrough
    case EFFECT_POISON:
    case EFFECT_TOXIC:
        if (!AI_CanPoison(battlerAtk, battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_LIGHT_SCREEN:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_LIGHTSCREEN || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REFLECT:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_REFLECT || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFECTO_VELO_AURORA:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove) || !EsClimaCombateNieve(climaCombate))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NEBLINA:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CONFUSE:
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
        if (!AI_CanConfuse(battlerAtk, battlerDef, aiData->abilities[battlerDef], ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PARALYZE:
        if (!AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SUBSTITUTE:
        if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE || aiData->abilities[battlerDef] == ABILITY_SIGILOSO)
            ADJUST_SCORE(-8);
        else if (aiData->hpPercents[battlerAtk] <= 25)
            ADJUST_SCORE(-10);
        else if (TieneMovimientoIgnoreSustituto(battlerDef))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_LEECH_SEED:
        if (gStatuses3[battlerDef] & STATUS3_LEECHSEED || EsTipo(battlerDef, TIPO_PLANTA) || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
            ADJUST_SCORE(-3);
        break;
    case EFFECT_DISABLE:
        if (gDisableStructs[battlerDef].disableTimer == 0 && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB) && !PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move)) // Attacker should go first
            {
                if (gLastMoves[battlerDef] == MOVE_NONE || gLastMoves[battlerDef] == 0xFFFF)
                    ADJUST_SCORE(-10); // no anticipated move to disable
            }
            else if (movimientoPredecido == MOVE_NONE)
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_ENCORE:
        if (gDisableStructs[battlerDef].encoreTimer == 0 && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB) && !DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move)) // Attacker should go first
            {
                if (gLastMoves[battlerDef] == MOVE_NONE || gLastMoves[battlerDef] == 0xFFFF)
                    ADJUST_SCORE(-10); // no anticipated move to encore
            }
            else if (movimientoPredecido == MOVE_NONE)
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_SNORE:
        if (IsWakeupTurn(battlerAtk) || !EstaDormido(battlerAtk))
            ADJUST_SCORE(-10); // if mon will wake up, is not asleep
        break;
    case EFFECT_MEAN_LOOK:
        if (IsBattlerTrapped(battlerDef, TRUE) || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NIGHTMARE:
        if (gBattleMons[battlerDef].status2 & STATUS2_NIGHTMARE)
            ADJUST_SCORE(-10);
        else if (!EstaDormido(battlerDef))
            ADJUST_SCORE(-8);
        else if (DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CURSE:
        if (EsTipo(battlerAtk, TIPO_FANTASMA))
        {
            if (gBattleMons[battlerDef].status2 & STATUS2_CURSED || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
                ADJUST_SCORE(-10);
            else if (aiData->hpPercents[battlerAtk] <= 50)
                ADJUST_SCORE(-6);
        }
        else // regular curse
        {
            if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_ATAQUE) || !HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA))
                ADJUST_SCORE(-10);
            else if (!BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], ESTADISTICA_DEFENSA))
                ADJUST_SCORE(-8);
        }
        break;
    case EFFECT_SPIKES:
        if (gSideTimers[GetBattlerSide(battlerDef)].spikesAmount >= 3)
            ADJUST_SCORE(-10);
        else if (PartnerMoveIsSameNoTarget(ALIADO(battlerAtk), move, aiData->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].spikesAmount == 2)
            ADJUST_SCORE(-10); // only one mon needs to set up the last layer of Spikes
        break;
    case EFFECT_STEALTH_ROCK:
        if (gSideTimers[GetBattlerSide(battlerDef)].stealthRockAmount > 0 || PartnerMoveIsSameNoTarget(ALIADO(battlerAtk), move, aiData->partnerMove)) // Only one mon needs to set up Stealth Rocks
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TOXIC_SPIKES:
        if (gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount >= 2)
            ADJUST_SCORE(-10);
        else if (PartnerMoveIsSameNoTarget(ALIADO(battlerAtk), move, aiData->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount == 1)
            ADJUST_SCORE(-10); // only one mon needs to set up the last layer of Toxic Spikes
        break;
    case EFFECT_STICKY_WEB:
        if (gSideTimers[GetBattlerSide(battlerDef)].stickyWebAmount)
            ADJUST_SCORE(-10);
        else if (PartnerMoveIsSameNoTarget(ALIADO(battlerAtk), move, aiData->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].stickyWebAmount)
            ADJUST_SCORE(-10); // only one mon needs to set up Sticky Web
        break;
    case EFFECT_FORESIGHT:
        if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] <= 4 || !(EsTipo(battlerDef, TIPO_FANTASMA)) || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-9);
        break;
    case EFFECT_PERISH_SONG:
        if (isDoubleBattle)
        {
            if (CountUsablePartyMons(battlerAtk) == 0 && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF && aiData->abilities[ALIADO(battlerAtk)] != ABILITY_SOUNDPROOF && CountUsablePartyMons(FOE(battlerAtk)) >= 1)
            {
                ADJUST_SCORE(-10); // Don't wipe your team if you're going to lose
            }
            else if ((!IsBattlerAlive(FOE(battlerAtk)) || aiData->abilities[FOE(battlerAtk)] == ABILITY_SOUNDPROOF || gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG) && (!IsBattlerAlive(ALIADO(FOE(battlerAtk))) || aiData->abilities[ALIADO(FOE(battlerAtk))] == ABILITY_SOUNDPROOF || gStatuses3[ALIADO(FOE(battlerAtk))] & STATUS3_PERISH_SONG))
            {
                ADJUST_SCORE(-10); // Both enemies are perish songed
            }
            else if (DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            if (CountUsablePartyMons(battlerAtk) == 0 && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF && CountUsablePartyMons(battlerDef) >= 1)
                ADJUST_SCORE(-10);

            if (gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG || aiData->abilities[FOE(battlerAtk)] == ABILITY_SOUNDPROOF)
                ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_TORMENTA_ARENA:
        if (EsClimaCombateArena(climaCombate) || IsMoveEffectWeather(aiData->partnerMove))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_DIA_SOLEADO:
        if (EsClimaCombateSol(climaCombate) || IsMoveEffectWeather(aiData->partnerMove))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_DANZA_LLUVIA:
        if (EsClimaCombateLluvia(climaCombate) || IsMoveEffectWeather(aiData->partnerMove))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_NEVADA:
        if (EsClimaCombateNieve(climaCombate) || IsMoveEffectWeather(aiData->partnerMove))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_ATTRACT:
        if (!AI_CanBeInfatuated(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SAFEGUARD:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_MAGNITUDE:
        if (aiData->abilities[battlerDef] == ABILITY_LEVITATE)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PARTING_SHOT:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);
        break;
    case EFECTO_RELEVO:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE)) || AnyStatIsRaised(battlerAtk))
            break;
        else
            ADJUST_SCORE(-6);
        break;
    case EFFECT_HIT_ESCAPE:
        break;
    case EFFECT_BELLY_DRUM:
        if (aiData->abilities[battlerAtk] == ABILITY_RESPONDON)
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] <= 60)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (!EsPrimerTurno(battlerAtk))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_STOCKPILE:
        if (gDisableStructs[battlerAtk].stockpileCounter >= 3)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SWALLOW:
        if (gDisableStructs[battlerAtk].stockpileCounter == 0)
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            if (AI_BattlerAtMaxHp(battlerAtk))
                ADJUST_SCORE(-10);
            else if (aiData->hpPercents[battlerAtk] >= 80)
                ADJUST_SCORE(-5); // do it if nothing better
        }
        break;
    case EFFECT_TORMENT:
        if (gBattleMons[battlerDef].status2 & STATUS2_TORMENT || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            ADJUST_SCORE(-10);
            break;
        }
        if (B_MENTAL_HERB >= GEN_5 && aiData->holdEffects[battlerDef] == HOLD_EFFECT_MENTAL_HERB)
            ADJUST_SCORE(-6);
        break;
    case EFFECT_WILL_O_WISP:
        if (!AI_CanBurn(battlerAtk, battlerDef, aiData->abilities[battlerDef], ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FOLLOW_ME:
        if (!isDoubleBattle || !IsBattlerAlive(ALIADO(battlerAtk)) || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove) || (aiData->partnerMove != MOVE_NONE && EsMovimientoEstado(aiData->partnerMove)) || *(gCombate->monToSwitchIntoId + ALIADO(battlerAtk)) != PARTY_SIZE) // Partner is switching out.
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TRICK:
    case EFFECT_CORROSIVE_GAS:
        if (aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD || aiData->abilities[battlerDef] == ABILITY_TERRITORIAL)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_INGRAIN:
        if (gStatuses3[battlerAtk] & STATUS3_ROOTED)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_AQUA_RING:
        if (gStatuses3[battlerAtk] & STATUS3_AQUA_RING)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_RECYCLE:
        if (GetUsedHeldItem(battlerAtk) == 0 || gBattleMons[battlerAtk].item != 0)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_IMPRISON:
        if (gStatuses3[battlerAtk] & STATUS3_IMPRISONED_OTHERS)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REFRESH:
        if (!(gBattleMons[battlerDef].status1 & (STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_CONGELACION)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ABSORB:
        if (aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
            ADJUST_SCORE(-6);
        break;
    case EFFECT_STRENGTH_SAP:
        break;
    case EFFECT_HIT_SWITCH_TARGET:
        if (DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10); // don't scare away pokemon twice
        else if (aiData->hpPercents[battlerDef] < 10 && GetBattlerSecondaryDamage(battlerDef))
            ADJUST_SCORE(-10); // don't blow away mon that will faint soon
        else if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REST:
        if (!CanBeSlept(battlerAtk, aiData->abilities[battlerAtk]))
            ADJUST_SCORE(-10);
        // fallthrough
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
        if (AI_BattlerAtMaxHp(battlerAtk))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(-9); // No point in healing, but should at least do it if nothing better
        break;
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (EsClimaCombateLluvia(climaCombate) || EsClimaCombateArena(climaCombate) || EsClimaCombateNieve(climaCombate))
            ADJUST_SCORE(-3);
        else if (AI_BattlerAtMaxHp(battlerAtk))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(-9); // No point in healing, but should at least do it if nothing better
        break;
    case EFFECT_PURIFY:
        if (!(gBattleMons[battlerDef].status1 & STATUS1_ANY))
            ADJUST_SCORE(-10);
        else if (battlerDef == ALIADO(battlerAtk))
            break; // Always heal your ally
        else if (AI_BattlerAtMaxHp(battlerAtk))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(-8); // No point in healing, but should at least do it if nothing better
        break;
    case EFFECT_LOCK_ON:
        if (gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DESTINY_BOND:
        if (gBattleMons[battlerDef].status2 & STATUS2_DESTINY_BOND)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HEAL_BELL:
        if (!AnyPartyMemberStatused(battlerAtk, EsMovimientoSonido(move)) || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PROTECT:
    {
        if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]))
        {
            ADJUST_SCORE(-10);
            break;
        }
        if (GetBattlerSecondaryDamage(battlerAtk) >= gBattleMons[battlerAtk].hp && aiData->abilities[battlerDef] != ABILITY_AUTOESTIMA && aiData->abilities[battlerDef] != ABILITY_BEAST_BOOST)
        {
            ADJUST_SCORE(-10); // Don't protect if you're going to faint after protecting
        }
        else if (gDisableStructs[battlerAtk].protectUses == 1 && Random() % 100 < 50)
        {
            if (!isDoubleBattle)
                ADJUST_SCORE(-6);
            else
                ADJUST_SCORE(-10); // Don't try double protecting in doubles
        }
        else if (gDisableStructs[battlerAtk].protectUses >= 2)
        {
            ADJUST_SCORE(-10);
        }

        /*if (AI_THINKING_STRUCT->aiFlags[battlerAtk] == AI_SCRIPT_CHECK_BAD_MOVE //Only basic AI
        && EsCombateContraEntrenador(gCombate->tipoCombate)) //Make the regular AI know how to use Protect minimally in Doubles
        {
            u8 shouldProtect = ShouldProtect(battlerAtk, battlerDef, move);
            if (shouldProtect == USE_PROTECT || shouldProtect == PROTECT_FROM_FOES)
                IncreaseFoeProtectionViability(&viability, 0xFF, battlerAtk, battlerDef);
            else if (shouldProtect == PROTECT_FROM_ALLIES)
                IncreaseAllyProtectionViability(&viability, 0xFF);
        }*/
    }
    break;
    case EFFECT_DEFOG:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST) || gSideTimers[GetBattlerSide(battlerDef)].auroraVeilTimer != 0 || gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY)
        {
            if (PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10); // Only need one hazards removal
                break;
            }
        }

        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_HAZARDS_ANY)
        {
            ADJUST_SCORE(-10); // Don't blow away opposing hazards
            break;
        }

        if (isDoubleBattle)
        {
            if (IsHazardMoveEffect(gMovimientos[aiData->partnerMove].effect)           // partner is going to set up hazards
                && AI_IsFaster(ALIADO(battlerAtk), battlerAtk, aiData->partnerMove)) // partner is going to set up before the potential Defog
            {
                ADJUST_SCORE(-10);
                break; // Don't use Defog if partner is going to set up hazards
            }
        }

        if (gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] == ESTADISTICA_MENOS_6 || ((aiData->abilities[battlerDef] == ABILITY_RESPONDON) && !IS_TARGETING_PARTNER(battlerAtk, battlerDef))) // don't want to raise target stats unless its your partner
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PSYCH_UP: // haze stats check
    {
        for (i = ESTADISTICA_ATAQUE; i < NUMERO_ESTADISTICAS_BATALLA; i++)
        {
            if (gBattleMons[battlerAtk].statStages[i] > ESTADISTICA_NEUTRA || gBattleMons[ALIADO(battlerAtk)].statStages[i] > ESTADISTICA_NEUTRA)
                ADJUST_SCORE(-10); // Don't want to reset our boosted stats
        }
        for (i = ESTADISTICA_ATAQUE; i < NUMERO_ESTADISTICAS_BATALLA; i++)
        {
            if (gBattleMons[battlerDef].statStages[i] < ESTADISTICA_NEUTRA || gBattleMons[ALIADO(battlerDef)].statStages[i] < ESTADISTICA_NEUTRA)
                ADJUST_SCORE(-10); // Don't want to copy enemy lowered stats
        }
    }
    break;
    case EFFECT_SEMI_INVULNERABLE:
        if (movimientoPredecido != MOVE_NONE
         && AI_IsSlower(battlerAtk, battlerDef, move)
         && gMovimientos[movimientoPredecido].effect == EFFECT_SEMI_INVULNERABLE)
            ADJUST_SCORE(-10); // Don't Fly/dig/etc if opponent is going to fly/dig/etc after you

        if (BattlerWillFaintFromWeather(battlerAtk, aiData->abilities[battlerAtk])
        && (move == MOVE_FLY || move == MOVE_BOUNCE))
            ADJUST_SCORE(-10); // Attacker will faint while in the air
        break;
    case EFFECT_TAUNT:
        if (gDisableStructs[battlerDef].tauntTimer > 0 || DoesPartnerHaveSameMoveEffect(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_GASTRO_ACID:
        if (gStatuses3[battlerDef] & STATUS3_GASTRO_ACID)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ESPACIO_RARO:
        if (PartnerMoveIs(ALIADO(battlerAtk), aiData->partnerMove, MOVE_ESPACIO_RARO))
        {
            ADJUST_SCORE(-10);
        }
        else if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
        {
            if (EstaEspacioRaroPuesto())
            {
                if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef)) // Attacker side slower than target side
                    ADJUST_SCORE(-10);                                                               // Keep the Trick Room up
            }
            else
            {
                if (GetBattlerSideSpeedAverage(battlerAtk) >= GetBattlerSideSpeedAverage(battlerDef)) // Attacker side faster than target side
                    ADJUST_SCORE(-10);                                                                // Keep the Trick Room down
            }
        }
        break;
    case EFFECT_EMBARGO:
        if (gDisableStructs[battlerDef].embargoTimer != 0 || PartnerMoveIsSameAsAttacker(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TELEKINESIS:
        if (gStatuses3[battlerDef] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN) || aiData->holdEffects[battlerDef] == HOLD_EFFECT_IRON_BALL || IsTelekinesisBannedSpecies(gBattleMons[battlerDef].species) || PartnerMoveIsSameAsAttacker(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HEAL_PULSE:                                // and floral healing
        if (!IS_TARGETING_PARTNER(battlerAtk, battlerDef)) // Don't heal enemies
        {
            ADJUST_SCORE(-10);
            break;
        }
        // fallthrough
    case EFFECT_HIT_ENEMY_HEAL_ALLY: // pollen puff
        if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        {
            if (AI_BattlerAtMaxHp(battlerDef))
                ADJUST_SCORE(-10);
            else if (gBattleMons[battlerDef].hp > gBattleMons[battlerDef].maxHP / 2)
                ADJUST_SCORE(-5);
        }
        break;
    case EFFECT_TOPSY_TURVY:
        if (!IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        {
            u32 targetPositiveStages = CountPositiveStatStages(battlerDef);
            u32 targetNegativeStages = CountNegativeStatStages(battlerDef);

            if (targetPositiveStages == 0 // No good stat changes to make bad
                || PartnerMoveIsSameAsAttacker(ALIADO(battlerAtk), battlerDef, move, aiData->partnerMove))
                ADJUST_SCORE(-10);

            else if (targetNegativeStages < targetPositiveStages)
                ADJUST_SCORE(-5); // More stages would be made positive than negative
        }
        break;
    case EFFECT_GOLPE_BAJO:
        if (movimientoPredecido != MOVE_NONE)
        {
            if (EsMovimientoEstado(movimientoPredecido) || AI_IsSlower(battlerAtk, battlerDef, move)) // Opponent going first
                ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_VIENTO_AFIN:
        if (gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer != 0 || PartnerMoveIs(ALIADO(battlerAtk), aiData->partnerMove, MOVE_VIENTO_AFIN) || gCombate->turnosEspacioRaro > 1)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_MAGNET_RISE:
        if (gDisableStructs[battlerAtk].magnetRiseTimer != 0 || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_IRON_BALL || gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_MAGNET_RISE | STATUS3_SMACKED_DOWN) || !EstaCombatienteEnSuelo(battlerAtk))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PALMA_RAUDA:
    {
        enum PrioridadMovimientos prioridad = PrioridadMovimientoMasHabilidad(battlerDef, movimientoPredecido);

        if (movimientoPredecido == MOVE_NONE || EsMovimientoEstado(movimientoPredecido))
        {
            ADJUST_SCORE(-10);
            break;
        }

        if (prioridad == PRIORIDAD_MOVIMIENTO_ALTA)
        {

            ADJUST_SCORE(10);
        }
        else if (prioridad == PRIORIDAD_MOVIMIENTO_MUY_ALTA)
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move))
                ADJUST_SCORE(10);
            else
                ADJUST_SCORE(-10);
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    }
    } // move effect checks

    // Choice items
    if (HOLD_EFFECT_CHOICE(aiData->holdEffects[battlerAtk]))
    {
        // Don't use user-target moves ie. Swords Dance, with exceptions
        if ((moveTarget & MOVE_TARGET_USER) && moveEffect != EFFECT_DESTINY_BOND && !(moveEffect == EFECTO_VELO_AURORA && EsClimaCombateNieve(climaCombate)))
            ADJUST_SCORE(-30);
        // Don't use a status move if the mon is the last one in the party, has no good switchin, or is trapped
        else if (CategoriaMovimiento(move) == CATEGORIA_ESTADO && (CountUsablePartyMons(battlerAtk) < 1 || AI_DATA->mostSuitableMonId[battlerAtk] == PARTY_SIZE || IsBattlerTrapped(battlerAtk, TRUE)))
            ADJUST_SCORE(-30);
    }

    if (score < 0)
        score = 0;

    return score;
}

static s32 AI_TryToFaint(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 movesetIndex = AI_THINKING_STRUCT->movesetIndex;

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (EsMovimientoEstado(move))
        return score; // status moves aren't accounted here

    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, 0) && gMovimientos[move].effect != EFFECT_EXPLOSION)
    {
        if (AI_IsFaster(battlerAtk, battlerDef, move))
            ADJUST_SCORE(FAST_KILL);
        else
            ADJUST_SCORE(SLOW_KILL);
    }
    else if (CanTargetFaintAI(battlerDef, battlerAtk) && GetWhichBattlerFasterOrTies(battlerAtk, battlerDef, TRUE) != AI_IS_FASTER && PrioridadMovimientoMasHabilidad(battlerAtk, move) > 0)
    {
        ADJUST_SCORE(LAST_CHANCE);
    }

    return score;
}

// double battle logic
static s32 AI_DoubleBattle(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // move data
    u32 moveType = gMovimientos[move].type;
    u32 effect = gMovimientos[move].effect;
    u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, move);
    // ally data
    u32 battlerAtkPartner = ALIADO(battlerAtk);
    struct AILogicData *aiData = AI_DATA;
    u32 atkPartnerAbility = aiData->abilities[ALIADO(battlerAtk)];
    u32 atkPartnerHoldEffect = aiData->holdEffects[ALIADO(battlerAtk)];
    bool32 partnerProtecting = (gMovimientos[aiData->partnerMove].effect == EFFECT_PROTECT);
    enum Movimientos movimientoPredecido = aiData->ultimoMovimientoUsado[battlerDef];

    moveType = TipoMovimiento(move, battlerAtk);

    // check what effect partner is using
    if (aiData->partnerMove != 0)
    {
        switch (gMovimientos[aiData->partnerMove].effect)
        {
        case EFFECT_PERISH_SONG:
            if (!(gBattleMons[battlerDef].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED)))
            {
                if (MovimientoImpideEscapar(aiData->partnerMove) || movimientoPredecido == MOVE_INGRAIN)
                    ADJUST_SCORE(WEAK_EFFECT);
            }
            break;
        // Don't change weather if ally already decided to do so.
        case EFFECT_DIA_SOLEADO:
        case EFFECT_NEVADA:
        case EFFECT_DANZA_LLUVIA:
        case EFFECT_TORMENTA_ARENA:
            if (IsMoveEffectWeather(move))
                ADJUST_SCORE(-10);
            break;
        }
    } // check partner move effect

    // Adjust for always crit moves
    if (gMovimientos[aiData->partnerMove].alwaysCriticalHit && aiData->abilities[battlerAtk] == ABILITY_ANGER_POINT)
    {
        if (AI_IsSlower(battlerAtk, battlerAtkPartner, move)) // Partner moving first
        {
            // discourage raising our attack since it's about to be maxed out
            if (IsAttackBoostMoveEffect(effect))
                ADJUST_SCORE(-3);
            // encourage moves hitting multiple opponents
            if (!EsMovimientoEstado(move) && (moveTarget & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
                ADJUST_SCORE(GOOD_EFFECT);
        }
    }

    // consider our move effect relative to partner state
    switch (effect)
    {
    case EFFECT_PERISH_SONG:
        if (aiData->partnerMove != 0 && HasTrappingMoveEffect(battlerAtkPartner))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_MAGNET_RISE:
        if (EstaCombatienteEnSuelo(battlerAtk) && (HasMove(battlerAtkPartner, MOVE_EARTHQUAKE) || HasMove(battlerAtkPartner, MOVE_MAGNITUDE)) && (IA_EfectividadMovimiento(MOVE_EARTHQUAKE, battlerAtk, battlerAtkPartner) != AI_EFFECTIVENESS_x0)) // Doesn't resist ground move
        {
            RETURN_SCORE_PLUS(DECENT_EFFECT); // partner has earthquake or magnitude -> good idea to use magnet rise
        }
        break;
    } // our effect relative to partner

    // consider global move effects
    switch (effect)
    {
    case EFFECT_TORMENTA_ARENA:
        if (ShouldSetSandstorm(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT); // our partner benefits from sandstorm
        }
        break;
    case EFFECT_DANZA_LLUVIA:
        if (ShouldSetRain(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT); // our partner benefits from rain
        }
        break;
    case EFFECT_DIA_SOLEADO:
        if (ShouldSetSun(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(WEAK_EFFECT); // our partner benefits from sun
        }
        break;
    case EFFECT_NEVADA:
        if (IsBattlerAlive(battlerAtkPartner) && DeberiaPonerNieve(battlerAtkPartner, atkPartnerAbility, atkPartnerHoldEffect))
        {
            RETURN_SCORE_PLUS(DECENT_EFFECT); // our partner benefits from snow
        }
        break;
    } // global move effect check

    // check specific target
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
    {
        // partner ability checks
        if (!partnerProtecting && moveTarget != MOVE_TARGET_BOTH && !DoesBattlerIgnoreAbilityChecks(aiData->abilities[battlerAtk], move))
        {
            switch (atkPartnerAbility)
            {
            case ABILITY_ANGER_POINT:
                if (gMovimientos[move].alwaysCriticalHit == TRUE && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_ATAQUE) && AI_IsFaster(battlerAtk, battlerAtkPartner, move) && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(GOOD_EFFECT);
                }
                break;
            case ABILITY_VOLT_ABSORB:
                if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_HP_AWARE))
                {
                    RETURN_SCORE_MINUS(10);
                }
                break; // handled in AI_HPAware
            case ABILITY_MOTOR_DRIVE:
                if (moveType == TIPO_ELECTRICO && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_VELOCIDAD))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_LIGHTNING_ROD:
                if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5 && moveType == TIPO_ELECTRICO && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_ESPECIAL) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_ATAQUE_ESPECIAL))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_WATER_ABSORB:
            case ABILITY_BANO_BARRO:
                if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_HP_AWARE))
                {
                    RETURN_SCORE_MINUS(10);
                }
                break; // handled in AI_HPAware
            case ABILITY_STORM_DRAIN:
                if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5 && moveType == TIPO_AGUA && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_ESPECIAL) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_ATAQUE_ESPECIAL))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_WATER_COMPACTION:
                if (moveType == TIPO_AGUA && GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) >= 4)
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT); // only mon with this ability is weak to water so only make it okay if we do very little damage
                }
                RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_FLASH_FIRE:
                if (moveType == TIPO_FUEGO && HasMoveWithType(battlerAtkPartner, TIPO_FUEGO) && !(gBattleResources->flags[battlerAtkPartner] & RESOURCE_FLAG_FLASH_FIRE))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_SAP_SIPPER:
                if (moveType == TIPO_PLANTA && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_FISICA) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_ATAQUE))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_JUSTIFIED:
                if ((moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA || moveType == TIPO_DRAGON) && !EsMovimientoEstado(move) && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_FISICA) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_ATAQUE) && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_RATTLED:
                if (!EsMovimientoEstado(move) && (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA || moveType == TIPO_BICHO) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_VELOCIDAD) && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_ALAS_HIDROFOBAS:
                if (!EsMovimientoEstado(move) && (moveType == TIPO_AGUA) && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, ESTADISTICA_VELOCIDAD) && !CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, AI_THINKING_STRUCT->movesetIndex, 1))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case ABILITY_RESPONDON:
                if (IsStatLoweringEffect(effect))
                {
                    RETURN_SCORE_PLUS(DECENT_EFFECT);
                }
                break;
            }
        } // ability checks

        // attacker move effects specifically targeting partner
        if (!partnerProtecting)
        {
            switch (effect)
            {
            case EFFECT_PURIFY:
                if (gBattleMons[battlerAtkPartner].status1 & STATUS1_ANY)
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_SWAGGER:
                if (gBattleMons[battlerAtkPartner].statStages[ESTADISTICA_ATAQUE] < ESTADISTICA_MAS_6 && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_FISICA) && (!AI_CanBeConfused(battlerAtk, battlerAtkPartner, move, atkPartnerAbility) || atkPartnerHoldEffect == HOLD_EFFECT_CURE_CONFUSION || atkPartnerHoldEffect == HOLD_EFFECT_CURE_STATUS))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_FLATTER:
                if (gBattleMons[battlerAtkPartner].statStages[ESTADISTICA_ATAQUE_ESPECIAL] < ESTADISTICA_MAS_6 && HasMoveWithCategory(battlerAtkPartner, CATEGORIA_ESPECIAL) && (!AI_CanBeConfused(battlerAtk, battlerAtkPartner, move, atkPartnerAbility) || atkPartnerHoldEffect == HOLD_EFFECT_CURE_CONFUSION || atkPartnerHoldEffect == HOLD_EFFECT_CURE_STATUS))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_GASTRO_ACID:
                RETURN_SCORE_PLUS(WEAK_EFFECT);
            case EFFECT_HEAL_PULSE:
            case EFFECT_HIT_ENEMY_HEAL_ALLY:
                if (AI_IsFaster(battlerAtk, FOE(battlerAtk), move) && AI_IsFaster(battlerAtk, ALIADO(FOE(battlerAtk)), move) && gBattleMons[battlerAtkPartner].hp < gBattleMons[battlerAtkPartner].maxHP / 2)
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                break;
            } // attacker move effects
        } // check partner protecting

        ADJUST_SCORE(-30); // otherwise, don't target partner
    }

    return score;
}

static s32 CompareMoveAccuracies(u32 battlerAtk, u32 battlerDef, u32 moveSlot1, u32 moveSlot2)
{
    u32 acc1 = AI_DATA->moveAccuracy[battlerAtk][battlerDef][moveSlot1];
    u32 acc2 = AI_DATA->moveAccuracy[battlerAtk][battlerDef][moveSlot2];

    if (acc1 > acc2)
        return 1;
    else if (acc2 > acc1)
        return -1;
    return 0;
}

static inline bool32 ShouldUseSpreadDamageMove(u32 battlerAtk, u32 move, u32 moveIndex, u32 hitsToFaintOpposingBattler)
{
    u32 partnerBattler = ALIADO(battlerAtk);
    u32 noOfHitsToFaintPartner = GetNoOfHitsToKOBattler(battlerAtk, partnerBattler, moveIndex);
    return (EsCombateContraEntrenador(gCombate->tipoCombate) && noOfHitsToFaintPartner != 0 // Immunity check
            && IsBattlerAlive(partnerBattler) && gMovimientos[move].target == MOVE_TARGET_FOES_AND_ALLY && !(noOfHitsToFaintPartner < 4 && hitsToFaintOpposingBattler == 1) && noOfHitsToFaintPartner < 7);
}

static s32 AI_CompareDamagingMoves(u32 atacante, u32 defensor, u32 currId)
{
    u32 i;
    bool32 multipleBestMoves = FALSE;
    s32 viableMoveScores[MAXIMO_MOVIMIENTOS_POKEMON];
    s32 bestViableMoveScore;
    s32 noOfHits[MAXIMO_MOVIMIENTOS_POKEMON];
    s32 score = 0;
    s32 leastHits = 1000;
    enum Movimientos *movimientos = ObtenMovimientos(atacante);
    bool32 isTwoTurnNotSemiInvulnerableMove[MAXIMO_MOVIMIENTOS_POKEMON];

    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (movimientos[i] != MOVE_NONE && gMovimientos[movimientos[i]].power)
        {
            noOfHits[i] = GetNoOfHitsToKOBattler(atacante, defensor, i);
            if (ShouldUseSpreadDamageMove(atacante, movimientos[i], i, noOfHits[i]))
            {
                noOfHits[i] = -1;
                viableMoveScores[i] = 0;
                isTwoTurnNotSemiInvulnerableMove[i] = FALSE;
            }
            else if (noOfHits[i] < leastHits && noOfHits[i] != 0)
            {
                leastHits = noOfHits[i];
            }
            viableMoveScores[i] = AI_SCORE_DEFAULT;
            isTwoTurnNotSemiInvulnerableMove[i] = IsTwoTurnNotSemiInvulnerableMove(atacante, movimientos[i]);
        }
        else
        {
            noOfHits[i] = -1;
            viableMoveScores[i] = 0;
            isTwoTurnNotSemiInvulnerableMove[i] = FALSE;
        }
        /*
            Test_MgbaPrintf("%S: required hits: %d Dmg: %d", gMoveNames[movimientos[i]], noOfHits[i], AI_DATA->simulatedDmg[atacante][defensor][i]);
        */
    }

    // Priority list:
    // 1. Less no of hits to ko
    // 2. Not charging
    // 3. More accuracy
    // 4. Better effect

    // Current move requires the least hits to KO. Compare with other moves.
    if (leastHits == noOfHits[currId])
    {
        for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
        {
            if (i == currId)
                continue;
            if (noOfHits[currId] == noOfHits[i])
            {
                multipleBestMoves = TRUE;
                // We need to make sure it's the current move which is objectively better.
                if (isTwoTurnNotSemiInvulnerableMove[i] && !isTwoTurnNotSemiInvulnerableMove[currId])
                    viableMoveScores[i] -= 3;
                else if (!isTwoTurnNotSemiInvulnerableMove[i] && isTwoTurnNotSemiInvulnerableMove[currId])
                    viableMoveScores[currId] -= 3;

                switch (CompareMoveAccuracies(atacante, defensor, currId, i))
                {
                case 1:
                    viableMoveScores[i] -= 2;
                    break;
                case -1:
                    viableMoveScores[currId] -= 2;
                    break;
                }
                switch (AI_WhichMoveBetter(movimientos[currId], movimientos[i], atacante, defensor, noOfHits[currId]))
                {
                case 1:
                    viableMoveScores[i] -= 1;
                    break;
                case -1:
                    viableMoveScores[currId] -= 1;
                    break;
                }
            }
        }
        // Turns out the current move deals the most dmg compared to the other 3.
        if (!multipleBestMoves)
            ADJUST_SCORE(BEST_DAMAGE_MOVE);
        else
        {
            bestViableMoveScore = 0;
            for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
            {
                if (viableMoveScores[i] > bestViableMoveScore)
                    bestViableMoveScore = viableMoveScores[i];
            }
            // Unless a better move was found increase score of current move
            if (viableMoveScores[currId] == bestViableMoveScore)
                ADJUST_SCORE(BEST_DAMAGE_MOVE);
        }
    }

    return score;
}

static u32 AI_CalcMoveEffectScore(u32 battlerAtk, u32 battlerDef, u32 move)
{
    // move data
    u32 moveEffect = gMovimientos[move].effect;
    struct AILogicData *aiData = AI_DATA;
    u32 movesetIndex = AI_THINKING_STRUCT->movesetIndex;
    u32 effectiveness = aiData->effectiveness[battlerAtk][battlerDef][movesetIndex];

    s32 score = 0;
    enum Movimientos movimientoPredecido = aiData->ultimoMovimientoUsado[battlerDef];
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    // check status move preference
    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_PREFER_STATUS_MOVES && EsMovimientoEstado(move) && effectiveness != AI_EFFECTIVENESS_x0)
        ADJUST_SCORE(10);

    // check burn / frostbite
    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING && AI_DATA->abilities[battlerAtk] == ABILITY_NATURAL_CURE)
    {
        if ((gBattleMons[battlerAtk].status1 & STATUS1_BURN && HasOnlyMovesWithCategory(battlerAtk, CATEGORIA_FISICA, TRUE)) || (gBattleMons[battlerAtk].status1 & STATUS1_CONGELACION && HasOnlyMovesWithCategory(battlerAtk, CATEGORIA_ESPECIAL, TRUE)))
            ADJUST_SCORE(-20); // Force switch if all your attacking moves are physical and you have Natural Cure.
    }

    // move effect checks
    switch (moveEffect)
    {
    case EFFECT_SLEEP:
        IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_ABSORB:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT && effectiveness >= AI_EFFECTIVENESS_x1)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_EXPLOSION:
        if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE && gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] < 7)
        {
            if (aiData->hpPercents[battlerAtk] < 50 && AI_RandLessThan(128))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_ATTACK_UP:
    case EFFECT_ATTACK_UP_USER_ALLY:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        break;
    case EFFECT_ATTACK_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK_2));
        break;
    case EFFECT_DEFENSE_UP:
    case EFFECT_DEFENSE_UP_3:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF));
        break;
    case EFFECT_DEFENSE_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF_2));
        break;
    case EFFECT_SPEED_UP:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED));
        break;
    case EFFECT_SPEED_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED_2));
        break;
    case EFFECT_SPECIAL_ATTACK_UP:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK));
        break;
    case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK_2));
        break;
    case EFFECT_SPECIAL_DEFENSE_UP:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF));
        break;
    case EFFECT_SPECIAL_DEFENSE_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF_2));
        break;
    case EFFECT_ACCURACY_UP:
    case EFFECT_ACCURACY_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC));
        break;
    case EFFECT_EVASION_UP:
    case EFFECT_EVASION_UP_2:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_EVASION));
        break;
    case EFFECT_ATTACK_DOWN:
    case EFFECT_ATTACK_DOWN_2:
        if (!ShouldLowerAttack(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE] < ESTADISTICA_NEUTRA)
            ADJUST_SCORE(-1);
        else if (aiData->hpPercents[battlerAtk] <= 90)
            ADJUST_SCORE(-1);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE] > 3 && !AI_RandLessThan(50))
            ADJUST_SCORE(-2);
        else if (aiData->hpPercents[battlerDef] < 70)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_DEFENSE_DOWN_2:
        if (!ShouldLowerDefense(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if ((aiData->hpPercents[battlerAtk] < 70 && !AI_RandLessThan(50)) || (gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA] <= 3 && !AI_RandLessThan(50)))
            ADJUST_SCORE(-2);
        if (aiData->hpPercents[battlerDef] <= 70)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPEED_DOWN_2:
        if (AI_IsFaster(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-3);
        else if (!AI_RandLessThan(70))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
        if (!ShouldLowerSpAtk(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE_ESPECIAL] < ESTADISTICA_NEUTRA)
            ADJUST_SCORE(-1);
        else if (aiData->hpPercents[battlerAtk] <= 90)
            ADJUST_SCORE(-1);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE_ESPECIAL] > 3 && !AI_RandLessThan(50))
            ADJUST_SCORE(-2);
        else if (aiData->hpPercents[battlerDef] < 70)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
        if (!ShouldLowerSpDef(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if ((aiData->hpPercents[battlerAtk] < 70 && !AI_RandLessThan(50)) || (gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA_ESPECIAL] <= 3 && !AI_RandLessThan(50)))
            ADJUST_SCORE(-2);
        if (aiData->hpPercents[battlerDef] <= 70)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_ACCURACY_DOWN_2:
        if (ShouldLowerAccuracy(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if ((aiData->hpPercents[battlerAtk] < 70 || aiData->hpPercents[battlerDef] < 70) && AI_RandLessThan(100))
            ADJUST_SCORE(-1);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_PRECISION] <= 4 && !AI_RandLessThan(80))
            ADJUST_SCORE(-2);
        if (gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY && !AI_RandLessThan(70))
            ADJUST_SCORE(DECENT_EFFECT);
        if (gStatuses3[battlerDef] & STATUS3_LEECHSEED && !AI_RandLessThan(70))
            ADJUST_SCORE(DECENT_EFFECT);
        if (gStatuses3[battlerDef] & STATUS3_ROOTED && AI_RandLessThan(128))
            ADJUST_SCORE(WEAK_EFFECT);
        if (gBattleMons[battlerDef].status2 & STATUS2_CURSED && !AI_RandLessThan(70))
            ADJUST_SCORE(DECENT_EFFECT);
        if (aiData->hpPercents[battlerAtk] > 70 || gBattleMons[battlerDef].statStages[ESTADISTICA_PRECISION] < ESTADISTICA_NEUTRA)
            break;
        else if (aiData->hpPercents[battlerAtk] < 40 || aiData->hpPercents[battlerDef] < 40 || !AI_RandLessThan(70))
            ADJUST_SCORE(-2);
        break;
    case EFFECT_EVASION_DOWN:
    case EFFECT_EVASION_DOWN_2:
        if (!ShouldLowerEvasion(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-2);
        if ((aiData->hpPercents[battlerAtk] < 70 || gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] <= 3) && !AI_RandLessThan(50))
            ADJUST_SCORE(-2);
        if (aiData->hpPercents[battlerDef] <= 70)
            ADJUST_SCORE(-2);
        if (gBattleMons[battlerAtk].statStages[ESTADISTICA_PRECISION] < ESTADISTICA_NEUTRA)
            ADJUST_SCORE(WEAK_EFFECT);
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] < 7)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_ATTACK_ACCURACY_UP: // hone claws
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC));
        break;
    case EFFECT_GROWTH:
    case EFFECT_ATTACK_SPATK_UP: // work up
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK));
        break;
    case EFFECT_HAZE:
        if (AnyStatIsRaised(ALIADO(battlerAtk)) || PartnerHasSameMoveEffectWithoutTarget(ALIADO(battlerAtk), move, aiData->partnerMove))
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, isDoubleBattle);
        break;
    case EFFECT_FUERZA_CAMBIO_OBJETIVO:
        if ((EsMovimientoSonido(move) && aiData->abilities[battlerDef] == ABILITY_SOUNDPROOF) || aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS || EsTipo(battlerDef, TIPO_TIERRA))
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, isDoubleBattle);
        break;
    case EFFECT_MULTI_HIT:
        if (AI_MoveMakesContact(aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk], move) && aiData->abilities[battlerAtk] != ABILITY_MAGIC_GUARD && aiData->holdEffects[battlerDef] == HOLD_EFFECT_ROCKY_HELMET)
            ADJUST_SCORE(-2);
        break;
    case EFFECT_SWALLOW:
        if (gDisableStructs[battlerAtk].stockpileCounter == 0)
        {
            break;
        }
        else
        {
            u32 healPercent = 0;
            switch (gDisableStructs[battlerAtk].stockpileCounter)
            {
            case 1:
                healPercent = 25;
                break;
            case 2:
                healPercent = 50;
                break;
            case 3:
                healPercent = 100;
                break;
            default:
                break;
            }

            if (ShouldRecover(battlerAtk, battlerDef, move, healPercent))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            ADJUST_SCORE(GOOD_EFFECT);
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TOXIC:
    case EFFECT_POISON:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFECTO_VELO_AURORA:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
        {
            ADJUST_SCORE(BEST_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_LIGHT_CLAY)
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_REST:
        if (!(CanBeSlept(battlerAtk, aiData->abilities[battlerAtk])))
        {
            break;
        }
        else if (ShouldRecover(battlerAtk, battlerDef, move, 100))
        {
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_SLP || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_STATUS || HasMoveEffect(battlerAtk, EFFECT_SNORE) || aiData->abilities[battlerAtk] == ABILITY_MUDAR || (EsClimaCombateLluvia(climaCombate) && gCombate->clima.turnos != 1 && aiData->abilities[battlerAtk] == ABILITY_HYDRATION && aiData->holdEffects[battlerAtk] != HOLD_EFFECT_UTILITY_UMBRELLA))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_MEAN_LOOK:
        if (ShouldTrap(battlerAtk, battlerDef, move))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_CONFUSE:
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_PARALYZE:
        IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_SUBSTITUTE:
        IncreaseSubstituteMoveScore(battlerAtk, battlerDef, move, &score);
    case EFFECT_LEECH_SEED:
        if (EsTipo(battlerDef, TIPO_PLANTA) || gStatuses3[battlerDef] & STATUS3_LEECHSEED || HasMoveWithAdditionalEffect(battlerDef, MOVE_EFFECT_GIRO_RAPIDO) || aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE || aiData->abilities[battlerDef] == ABILITY_MAGIC_GUARD)
            break;
        ADJUST_SCORE(GOOD_EFFECT);
        if (!TieneMovimientoOfensivo(battlerDef) || IsBattlerTrapped(battlerDef, FALSE))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_HIT_ESCAPE:
    case EFFECT_PARTING_SHOT:
        if (!EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            switch (ShouldPivot(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, movesetIndex))
            {
            case DONT_PIVOT:
                ADJUST_SCORE(-10); // technically should go in CheckBadMove, but this is easier/less computationally demanding
                break;
            case CAN_TRY_PIVOT:
                break;
            case SHOULD_PIVOT:
                ADJUST_SCORE(BEST_EFFECT);
                break;
            }
        }
        else // Double Battle
        {
            if (CountUsablePartyMons(battlerAtk) == 0)
                break; // Can't switch

            // if (switchAbility == ABILITY_INTIMIDATE && PartyHasMoveCategory(battlerDef, CATEGORIA_FISICA)) REVISAR
            // ADJUST_SCORE(7);

            // if (switchAbility == ABILITY_MAL_AURA && PartyHasMoveCategory(battlerDef, CATEGORIA_ESPECIAL)) REVISAR
            // ADJUST_SCORE(7);
        }
        break;
    case EFECTO_RELEVO:
        if ((AI_DATA->shouldSwitch & (1u << battlerAtk)) && (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE)) || AnyStatIsRaised(battlerAtk)))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_DISABLE:
        if (gDisableStructs[battlerDef].disableTimer == 0 && (gLastMoves[battlerDef] != MOVE_NONE) && (gLastMoves[battlerDef] != 0xFFFF) && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB) && (AI_IsFaster(battlerAtk, battlerDef, move)))
        {
            if (PuedeMovimientoDebilitarObjetivo(gLastMoves[battlerDef], battlerDef, battlerAtk, 1))
                ADJUST_SCORE(GOOD_EFFECT); // Disable move that can kill attacker
        }
        break;
    case EFFECT_ENCORE:
        if (gDisableStructs[battlerDef].encoreTimer == 0 && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB) && (gBattleMoveEffects[gMovimientos[gLastMoves[battlerDef]].effect].encourageEncore))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_SNORE:
        if (!IsWakeupTurn(battlerAtk) && gBattleMons[battlerAtk].status1 & STATUS1_SLEEP)
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_LOCK_ON:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 85, TRUE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_DESTINY_BOND:
        if (AI_IsFaster(battlerAtk, battlerDef, move) && CanTargetFaintAI(battlerDef, battlerAtk))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_HEAL_BELL:
        if (ShouldUseWishAromatherapy(battlerAtk, battlerDef, move))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_CURSE:
        if (EsTipo(battlerAtk, TIPO_FANTASMA))
        {
            if (IsBattlerTrapped(battlerDef, TRUE))
                ADJUST_SCORE(GOOD_EFFECT);
            else
                ADJUST_SCORE(WEAK_EFFECT);
        }
        else
        {
            ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
            ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF));
        }
        break;
    case EFFECT_PROTECT:
        if (movimientoPredecido == 0xFFFF)
            movimientoPredecido = MOVE_NONE;
        ProtectChecks(battlerAtk, battlerDef, move, movimientoPredecido, &score);
        break;
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, aiData))
        {
            if (EsPrimerTurno(battlerAtk))
                ADJUST_SCORE(BEST_EFFECT);
            else
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_FORESIGHT:
        if (aiData->abilities[battlerAtk] == ABILITY_SCRAPPY)
            break;
        else if (gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION] > ESTADISTICA_NEUTRA || (EsTipo(battlerDef, TIPO_FANTASMA) && (HasMoveWithType(battlerAtk, TIPO_NORMAL) || HasMoveWithType(battlerAtk, TIPO_LUCHA))))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PERISH_SONG:
        if (IsBattlerTrapped(battlerDef, TRUE))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_TORMENTA_ARENA:
        if (ShouldSetSandstorm(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            ADJUST_SCORE(DECENT_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_SMOOTH_ROCK)
                ADJUST_SCORE(WEAK_EFFECT);
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN) || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS) || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    case EFFECT_NEVADA:
        if (DeberiaPonerNieve(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            if ((HasMoveEffect(battlerAtk, EFECTO_VELO_AURORA) || HasMoveEffect(ALIADO(battlerAtk), EFECTO_VELO_AURORA)) && ShouldSetScreen(battlerAtk, battlerDef, EFECTO_VELO_AURORA))
                ADJUST_SCORE(GOOD_EFFECT);

            ADJUST_SCORE(DECENT_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_ICY_ROCK)
                ADJUST_SCORE(WEAK_EFFECT);
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN) || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS) || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    case EFFECT_DANZA_LLUVIA:
        if (ShouldSetRain(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            ADJUST_SCORE(DECENT_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_DAMP_ROCK)
                ADJUST_SCORE(WEAK_EFFECT);
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN) || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS) || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                ADJUST_SCORE(WEAK_EFFECT);
            if (HasMoveWithType(battlerDef, TIPO_FUEGO) || HasMoveWithType(ALIADO(battlerDef), TIPO_FUEGO))
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    case EFFECT_DIA_SOLEADO:
        if (ShouldSetSun(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]))
        {
            ADJUST_SCORE(DECENT_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_HEAT_ROCK)
                ADJUST_SCORE(WEAK_EFFECT);
            if (HasMoveWithType(battlerDef, TIPO_AGUA) || HasMoveWithType(ALIADO(battlerDef), TIPO_AGUA))
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    case EFFECT_FELL_STINGER:
        if (gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE] < ESTADISTICA_MAS_6 && aiData->abilities[battlerAtk] != ABILITY_RESPONDON && CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, 0))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_BELLY_DRUM:
        if (!CanTargetFaintAI(battlerDef, battlerAtk) && gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE] < ESTADISTICA_MAS_6 - 2 && HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA) && aiData->abilities[battlerAtk] != ABILITY_RESPONDON)
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_PSYCH_UP:
        score += AI_ShouldCopyStatChanges(battlerAtk, battlerDef);
        break;
    case EFFECT_SEMI_INVULNERABLE:
        if (movimientoPredecido != MOVE_NONE && !isDoubleBattle)
        {
            if ((AI_IsFaster(battlerAtk, battlerDef, move)) && (gMovimientos[movimientoPredecido].effect == EFFECT_EXPLOSION || gMovimientos[movimientoPredecido].effect == EFFECT_PROTECT))
                ADJUST_SCORE(GOOD_EFFECT);
            else if (gMovimientos[movimientoPredecido].effect == EFFECT_SEMI_INVULNERABLE && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_DEFENSE_CURL:
        if (HasMoveEffect(battlerAtk, EFFECT_ROLLOUT) && !(gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL))
            ADJUST_SCORE(DECENT_EFFECT);
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF));
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (DeberiaUsarSorpresa(battlerAtk, battlerDef, move))
            ADJUST_SCORE(GOOD_EFFECT);
        else if (EsPrimerTurno(battlerAtk) && GetBestDmgMoveFromBattler(battlerAtk, battlerDef) == move)
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_STOCKPILE:
        break;
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
        if (HasMoveEffect(battlerAtk, EFFECT_FOUL_PLAY) || HasMoveEffect(battlerAtk, EFFECT_PSYCH_UP) || HasMoveWithAdditionalEffect(battlerAtk, MOVE_EFFECT_SPECTRAL_THIEF))
            ADJUST_SCORE(DECENT_EFFECT);
        if (aiData->abilities[battlerDef] == ABILITY_RESPONDON)
            ADJUST_SCORE(GOOD_EFFECT);
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FURY_CUTTER:
        if (!isDoubleBattle && aiData->holdEffects[battlerAtk] == HOLD_EFFECT_METRONOME)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_ATTRACT:
        if (!isDoubleBattle && (AI_IsSlower(battlerAtk, battlerDef, move)) && BattlerWillFaintFromSecondaryDamage(battlerDef, aiData->abilities[battlerDef]))
            break; // Don't use if the attract won't have a change to activate
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY || (gBattleMons[battlerDef].status2 & STATUS2_CONFUSION) || IsBattlerTrapped(battlerDef, TRUE))
            ADJUST_SCORE(GOOD_EFFECT);
        else
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_SAFEGUARD:
        if (!EstaCombatienteEnSuelo(battlerAtk)) // Revisar
            ADJUST_SCORE(DECENT_EFFECT);         // TODO: check if opp has status move?
        // if (CountUsablePartyMons(battlerDef) != 0)
        // ADJUST_SCORE(8);
        break;
    case EFFECT_PURSUIT:
        // TODO
        // if (IsPredictedToSwitch(battlerDef, battlerAtk))
        //     ADJUST_SCORE(GOOD_EFFECT);
        // else if (IsPredictedToUsePursuitableMove(battlerDef, battlerAtk) && !MoveWouldHitFirst(move, battlerAtk, battlerDef)) //Pursuit against fast U-Turn
        //     ADJUST_SCORE(GOOD_EFFECT);
        // break;
    case EFFECT_DEFOG:
        if ((gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY && CountUsablePartyMons(battlerAtk) != 0) || (gSideStatuses[GetBattlerSide(battlerDef)] & (SIDE_STATUS_SCREEN_ANY | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)))
        {
            ADJUST_SCORE(GOOD_EFFECT);
        }
        else if (!(gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SPIKES)) // Don't blow away hazards if you set them up
        {
            if (isDoubleBattle)
            {
                if (IsHazardMoveEffect(gMovimientos[aiData->partnerMove].effect) // Partner is going to set up hazards
                    && AI_IsSlower(battlerAtk, ALIADO(battlerAtk), move))      // Partner going first
                    break;                                                     // Don't use Defog if partner is going to set up hazards
            }
            if (ShouldLowerEvasion(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_TORMENT:
        break;
    case EFFECT_WILL_O_WISP:
        IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FOLLOW_ME:
        if (isDoubleBattle && move != MOVE_SPOTLIGHT && !IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]) && (move != MOVE_RAGE_POWDER || IsAffectedByPowder(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef])) // Rage Powder doesn't affect powder immunities
            && IsBattlerAlive(ALIADO(battlerAtk)))
        {
            enum Movimientos movimientoPredecidoEnAliado = gLastMoves[ALIADO(battlerAtk)];
            if (movimientoPredecidoEnAliado != MOVE_NONE && !EsMovimientoEstado(movimientoPredecidoEnAliado))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_CHARGE:
        if (TieneMovimientoOfensivoTipo(battlerAtk, TIPO_ELECTRICO))
            ADJUST_SCORE(DECENT_EFFECT);
        if (B_CHARGE_SPDEF_RAISE >= GEN_5)
            ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF));
        break;
    case EFFECT_TAUNT:
        if (EsMovimientoEstado(movimientoPredecido))
            ADJUST_SCORE(GOOD_EFFECT);
        else if (HasMoveWithCategory(battlerDef, CATEGORIA_ESTADO))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TRICK:
        switch (aiData->holdEffects[battlerAtk])
        {
        case HOLD_EFFECT_CHOICE_SCARF:
            ADJUST_SCORE(DECENT_EFFECT); // assume its beneficial
            break;
        case HOLD_EFFECT_CHOICE_BAND:
            if (!HasMoveWithCategory(battlerDef, CATEGORIA_FISICA))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_CHOICE_SPECS:
            if (!HasMoveWithCategory(battlerDef, CATEGORIA_ESPECIAL))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            if (!ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]) && CanBeBurned(battlerAtk, aiData->abilities[battlerDef]))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_BLACK_SLUDGE:
            if (!EsTipo(battlerDef, TIPO_VENENO) && aiData->abilities[battlerDef] != ABILITY_MAGIC_GUARD)
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_IRON_BALL:
            if (!EstaCombatienteEnSuelo(battlerDef))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_LAGGING_TAIL:
        case HOLD_EFFECT_STICKY_BARB:
            ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_UTILITY_UMBRELLA:
            break;
        case HOLD_EFFECT_EJECT_BUTTON:
            if (TieneMovimientoOfensivo(battlerAtk) || (isDoubleBattle && IsBattlerAlive(ALIADO(battlerAtk)) && TieneMovimientoOfensivo(ALIADO(battlerAtk))))
                ADJUST_SCORE(DECENT_EFFECT); // Force 'em out next turn
            break;
        default:
            if (aiData->items[battlerAtk] == ITEM_NONE && aiData->items[battlerDef] != ITEM_NONE)
            {
                switch (aiData->holdEffects[battlerDef])
                {
                case HOLD_EFFECT_CHOICE_BAND:
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (EsTipo(battlerAtk, TIPO_VENENO) || aiData->abilities[battlerAtk] == ABILITY_MAGIC_GUARD)
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_IRON_BALL:
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                default:
                    ADJUST_SCORE(WEAK_EFFECT); // other hold effects generally universally good
                    break;
                }
            }
        }
        break;
    case EFFECT_CORROSIVE_GAS:
        if (PuedeQuitarObjeto(battlerDef, aiData->items[battlerDef]))
        {
            switch (aiData->holdEffects[battlerDef])
            {
            case HOLD_EFFECT_IRON_BALL:
            case HOLD_EFFECT_LAGGING_TAIL:
            case HOLD_EFFECT_STICKY_BARB:
                break;
            default:
                ADJUST_SCORE(DECENT_EFFECT);
                break;
            }
        }
        break;
    case EFFECT_INGRAIN:
        ADJUST_SCORE(WEAK_EFFECT);
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_RECYCLE:
        if (GetUsedHeldItem(battlerAtk) != ITEM_NONE)
            ADJUST_SCORE(WEAK_EFFECT);
        if (IsRecycleEncouragedItem(GetUsedHeldItem(battlerAtk)))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_BRICK_BREAK:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_REFLECT)
            ADJUST_SCORE(DECENT_EFFECT);
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_LIGHTSCREEN)
            ADJUST_SCORE(DECENT_EFFECT);
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_AURORA_VEIL)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_GASTRO_ACID:
        ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_IMPRISON:
        if (movimientoPredecido != MOVE_NONE && HasMove(battlerAtk, movimientoPredecido))
            ADJUST_SCORE(DECENT_EFFECT);
        else if (EsPrimerTurno(battlerAtk))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_REFRESH:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TICKLE:
        if (gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA] > 4 && HasMoveWithCategory(battlerAtk, CATEGORIA_FISICA) && aiData->abilities[battlerDef] != ABILITY_RESPONDON && ShouldLowerDefense(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(DECENT_EFFECT);
        else if (ShouldLowerAttack(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_COSMIC_POWER:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF));
        break;
    case EFFECT_BULK_UP:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_DEF));
        break;
    case EFFECT_CALM_MIND:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPDEF));
        break;
    case EFECTO_SUBE_ATAQUE_ESPECIAL_VELOCIDAD:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK));
        break;
    case EFFECT_SHELL_SMASH:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_RESTORE_STATS)
            ADJUST_SCORE(WEAK_EFFECT);

        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPATK));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        break;
    case EFFECT_DRAGON_DANCE:
    case EFFECT_SHIFT_GEAR:
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED));
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ATK));
        break;
    case EFFECT_ESPACIO_RARO:
        if (!(AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
        {
            if (!EstaEspacioRaroPuesto() && GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
                ADJUST_SCORE(GOOD_EFFECT);
            else if (EstaEspacioRaroPuesto() && GetBattlerSideSpeedAverage(battlerAtk) >= GetBattlerSideSpeedAverage(battlerDef))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_EMBARGO:
        if (aiData->holdEffects[battlerDef] != HOLD_EFFECT_NONE)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TELEKINESIS:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef]) || !EstaCombatienteEnSuelo(battlerDef))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TOPSY_TURVY:
        if (CountPositiveStatStages(battlerDef) > CountNegativeStatStages(battlerDef))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_VIENTO_AFIN:
        if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_MAGNET_RISE:
        if (EstaCombatienteEnSuelo(battlerAtk) && TieneMovimientoOfensivoTipo(battlerDef, TIPO_ELECTRICO) && !(IA_EfectividadMovimiento(MOVE_EARTHQUAKE, battlerDef, battlerAtk) == AI_EFFECTIVENESS_x0)) // Doesn't resist ground move
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move)) // Attacker goes first
            {
                if (gMovimientos[movimientoPredecido].type == TIPO_TIERRA)
                    ADJUST_SCORE(GOOD_EFFECT); // Cause the enemy's move to fail
                break;
            }
            else // Opponent Goes First
            {
                if (TieneMovimientoOfensivoTipo(battlerDef, TIPO_TIERRA))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            }
        }
        break;
    case EFFECT_TOXIC_THREAD:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_SPEED));
        break;
    case EFFECT_SHORE_UP:
        if (EsClimaCombateArena(climaCombate) && ShouldRecover(battlerAtk, battlerDef, move, 67))
            ADJUST_SCORE(DECENT_EFFECT);
        else if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    } // move effect checks

    // check move additional effects that are likely to happen
    for (i = 0; i < gMovimientos[move].numAdditionalEffects; i++)
    {
        // Only consider effects with a guaranteed chance to happen
        if (!EfectoSecundarioGarantizado(aiData->abilities[battlerAtk], &gMovimientos[move].additionalEffects[i]))
            continue;

        // Consider move effects that target self
        if (gMovimientos[move].additionalEffects[i].self)
        {
            u32 StageStatId;

            if (aiData->abilities[battlerAtk] != ABILITY_RESPONDON)
            {
                switch (gMovimientos[move].additionalEffects[i].moveEffect)
                {
                case MOVE_EFFECT_ATK_PLUS_1:
                case MOVE_EFFECT_DEF_PLUS_1:
                case MOVE_EFFECT_SPD_PLUS_1:
                case MOVE_EFFECT_SP_ATK_PLUS_1:
                case MOVE_EFFECT_SP_DEF_PLUS_1:
                    StageStatId = STAT_CHANGE_ATK + gMovimientos[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_PLUS_1;
                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, StageStatId));
                    break;
                case MOVE_EFFECT_ATK_PLUS_2:
                case MOVE_EFFECT_DEF_PLUS_2:
                case MOVE_EFFECT_SPD_PLUS_2:
                case MOVE_EFFECT_SP_ATK_PLUS_2:
                case MOVE_EFFECT_SP_DEF_PLUS_2:
                    StageStatId = STAT_CHANGE_ATK_2 + gMovimientos[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_PLUS_1;
                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, StageStatId));
                    break;
                case MOVE_EFFECT_ACC_PLUS_1:
                case MOVE_EFFECT_ACC_PLUS_2:
                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_ACC));
                    break;
                case MOVE_EFFECT_EVS_PLUS_1:
                case MOVE_EFFECT_EVS_PLUS_2:
                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_CHANGE_EVASION));
                    break;
                case MOVE_EFFECT_GIRO_RAPIDO:
                    if ((gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY && CountUsablePartyMons(battlerAtk) != 0) || (gStatuses3[battlerAtk] & STATUS3_LEECHSEED || gBattleMons[battlerAtk].status2 & STATUS2_WRAPPED))
                        ADJUST_SCORE(GOOD_EFFECT);
                    break;
                }
            }
            else
            {
                switch (gMovimientos[move].additionalEffects[i].moveEffect)
                {
                case MOVE_EFFECT_ATK_MINUS_1:
                case MOVE_EFFECT_DEF_MINUS_1:
                case MOVE_EFFECT_SPD_MINUS_1:
                case MOVE_EFFECT_SP_ATK_MINUS_1:
                case MOVE_EFFECT_SP_DEF_MINUS_1:
                    StageStatId = STAT_CHANGE_ATK + gMovimientos[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_MINUS_1;
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, StageStatId));
                    break;
                case MOVE_EFFECT_ATK_MINUS_2:
                case MOVE_EFFECT_DEF_MINUS_2:
                case MOVE_EFFECT_SPD_MINUS_2:
                case MOVE_EFFECT_SP_ATK_MINUS_2:
                case MOVE_EFFECT_SP_DEF_MINUS_2:
                    StageStatId = STAT_CHANGE_ATK + gMovimientos[move].additionalEffects[i].moveEffect - MOVE_EFFECT_ATK_MINUS_2;
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, StageStatId));
                    break;
                case MOVE_EFFECT_ACC_MINUS_1:
                case MOVE_EFFECT_ACC_MINUS_2:
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_ACC));
                    break;
                case MOVE_EFFECT_EVS_MINUS_1:
                case MOVE_EFFECT_EVS_MINUS_2:
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_EVASION));
                    break;
                case MOVE_EFFECT_DEF_SPDEF_DOWN:
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_DEF));
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_SPDEF));
                    break;
                case MOVE_EFFECT_ATK_DEF_DOWN:
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_ATK));
                    ADJUST_SCORE(IncreaseStatUpScoreContrary(battlerAtk, battlerDef, STAT_CHANGE_DEF));
                    break;
                }
            }
        }
        else // consider move effects that hinder the target
        {
            switch (gMovimientos[move].additionalEffects[i].moveEffect)
            {
            case MOVE_EFFECT_FLINCH:
                score += ShouldTryToFlinch(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move);
                break;
            case MOVE_EFFECT_SPD_MINUS_1:
            case MOVE_EFFECT_SPD_MINUS_2:
                if (!ShouldLowerSpeed(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
                    break;
            case MOVE_EFFECT_ATK_MINUS_1:
            case MOVE_EFFECT_DEF_MINUS_1:
            case MOVE_EFFECT_SP_ATK_MINUS_1:
            case MOVE_EFFECT_SP_DEF_MINUS_1:
            case MOVE_EFFECT_ACC_MINUS_1:
            case MOVE_EFFECT_EVS_MINUS_1:
            case MOVE_EFFECT_ATK_MINUS_2:
            case MOVE_EFFECT_DEF_MINUS_2:
            case MOVE_EFFECT_SP_ATK_MINUS_2:
            case MOVE_EFFECT_SP_DEF_MINUS_2:
            case MOVE_EFFECT_ACC_MINUS_2:
            case MOVE_EFFECT_EVS_MINUS_2:
                if (aiData->abilities[battlerDef] != ABILITY_RESPONDON)
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_POISON:
                IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
                break;
            case MOVE_EFFECT_CLEAR_SMOG:
                score += AI_TryToClearStats(battlerAtk, battlerDef, FALSE);
                break;
            case MOVE_EFFECT_SPECTRAL_THIEF:
                score += AI_ShouldCopyStatChanges(battlerAtk, battlerDef);
                break;
            case MOVE_EFFECT_BUG_BITE: // And pluck
                if (gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE || aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD || aiData->abilities[battlerDef] == ABILITY_TERRITORIAL)
                    break;
                else if (ItemId_GetPocket(aiData->items[battlerDef]) == POCKET_BERRIES)
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_SMACK_DOWN:
                if (!EstaCombatienteEnSuelo(battlerDef) && TieneMovimientoOfensivoTipo(battlerAtk, TIPO_TIERRA) && !CanTargetFaintAI(battlerDef, battlerAtk))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case EFECTO_MOVIMIENTO_QUITAR_OBJETO:
                if (PuedeQuitarObjeto(battlerDef, aiData->items[battlerDef]))
                {
                    switch (aiData->holdEffects[battlerDef])
                    {
                    case HOLD_EFFECT_IRON_BALL:
                    case HOLD_EFFECT_LAGGING_TAIL:
                    case HOLD_EFFECT_STICKY_BARB:
                        break;
                    default:
                        ADJUST_SCORE(DECENT_EFFECT);
                        break;
                    }
                }
                break;
            case MOVE_EFFECT_STEAL_ITEM:
            {
                bool32 canSteal = FALSE;

                if (GetBattlerSide(battlerAtk) == LADO_JUGADOR)
                    canSteal = TRUE;

                if (canSteal && aiData->items[battlerAtk] == ITEM_NONE && aiData->items[battlerDef] != ITEM_NONE && !HasMoveEffect(battlerAtk, EFFECT_ACROBATICS) && aiData->abilities[battlerDef] != ABILITY_STICKY_HOLD && aiData->abilities[battlerDef] != ABILITY_TERRITORIAL)
                {
                    switch (aiData->holdEffects[battlerDef])
                    {
                    case HOLD_EFFECT_NONE:
                        break;
                    case HOLD_EFFECT_CHOICE_BAND:
                    case HOLD_EFFECT_CHOICE_SCARF:
                    case HOLD_EFFECT_CHOICE_SPECS:
                        ADJUST_SCORE(DECENT_EFFECT);
                        break;
                    case HOLD_EFFECT_TOXIC_ORB:
                        if (ShouldPoisonSelf(battlerAtk, aiData->abilities[battlerAtk]))
                            ADJUST_SCORE(DECENT_EFFECT);
                        break;
                    case HOLD_EFFECT_FLAME_ORB:
                        if (ShouldBurnSelf(battlerAtk, aiData->abilities[battlerAtk]))
                            ADJUST_SCORE(DECENT_EFFECT);
                        break;
                    case HOLD_EFFECT_BLACK_SLUDGE:
                        if (EsTipo(battlerAtk, TIPO_VENENO))
                            ADJUST_SCORE(DECENT_EFFECT);
                        break;
                    case HOLD_EFFECT_IRON_BALL:
                    case HOLD_EFFECT_LAGGING_TAIL:
                    case HOLD_EFFECT_STICKY_BARB:
                        break;
                    default:
                        ADJUST_SCORE(WEAK_EFFECT);
                        break;
                    }
                }
                break;
            }
            break;
            case MOVE_EFFECT_STEALTH_ROCK:
            case MOVE_EFFECT_SPIKES:
                if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, aiData))
                {
                    if (EsPrimerTurno(battlerAtk))
                        ADJUST_SCORE(BEST_EFFECT);
                    else
                        ADJUST_SCORE(DECENT_EFFECT);
                }
                break;
            case MOVE_EFFECT_FEINT:
                if (gMovimientos[movimientoPredecido].effect == EFFECT_PROTECT)
                    ADJUST_SCORE(GOOD_EFFECT);
                break;
            case MOVE_EFFECT_THROAT_CHOP:
                if (gMovimientos[GetBestDmgMoveFromBattler(battlerDef, battlerAtk)].soundMove)
                {
                    if (AI_IsFaster(battlerAtk, battlerDef, move))
                        ADJUST_SCORE(GOOD_EFFECT);
                    else
                        ADJUST_SCORE(DECENT_EFFECT);
                }
                break;
            case MOVE_EFFECT_WRAP:
                if (!HasMoveWithAdditionalEffect(battlerDef, MOVE_EFFECT_GIRO_RAPIDO) && ShouldTrap(battlerAtk, battlerDef, move))
                    ADJUST_SCORE(BEST_EFFECT);
                break;
            }
        }
    }

    return score;
}

// AI_FLAG_CHECK_VIABILITY - Chooses best possible move to hit player
static s32 AI_CheckViability(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    // Targeting partner, check benefits of doing that instead
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (gMovimientos[move].power)
    {
        if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 0)
            ADJUST_AND_RETURN_SCORE(NO_DAMAGE_OR_FAILS); // No point in checking the move further so return early
        else
        {
            if ((AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_RISKY) && GetBestDmgMoveFromBattler(battlerAtk, battlerDef) == move)
                ADJUST_SCORE(BEST_DAMAGE_MOVE);
            else
                ADJUST_SCORE(AI_CompareDamagingMoves(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex));
        }
    }

    ADJUST_SCORE(AI_CalcMoveEffectScore(battlerAtk, battlerDef, move));

    return score;
}

// Effects that are encouraged on the first turn of battle
static s32 AI_ForceSetupFirstTurn(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 i;
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef) || gCombate->contadorTurnos != 0)
        return score;

    if (AI_THINKING_STRUCT->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING && AI_IsSlower(battlerAtk, battlerDef, move) && CanTargetFaintAI(battlerDef, battlerAtk) && PrioridadMovimientoMasHabilidad(battlerAtk, move) == 0)
    {
        RETURN_SCORE_MINUS(20); // No point in setting up if you will faint. Should just switch if possible..
    }

    // check effects to prioritize first turn
    switch (gMovimientos[move].effect)
    {
    case EFFECT_ATTACK_UP:
    case EFFECT_ATTACK_UP_USER_ALLY:
    case EFFECT_DEFENSE_UP:
    case EFFECT_SPEED_UP:
    case EFFECT_SPECIAL_ATTACK_UP:
    case EFFECT_SPECIAL_DEFENSE_UP:
    case EFFECT_ACCURACY_UP:
    case EFFECT_EVASION_UP:
    case EFFECT_ATTACK_DOWN:
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_EVASION_DOWN:
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_CONFUSE:
    case EFFECT_ATTACK_UP_2:
    case EFFECT_DEFENSE_UP_2:
    case EFFECT_DEFENSE_UP_3:
    case EFFECT_SPEED_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
    case EFFECT_SPECIAL_DEFENSE_UP_2:
    case EFFECT_ACCURACY_UP_2:
    case EFFECT_EVASION_UP_2:
    case EFFECT_ATTACK_DOWN_2:
    case EFFECT_DEFENSE_DOWN_2:
    case EFFECT_SPEED_DOWN_2:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
    case EFFECT_ACCURACY_DOWN_2:
    case EFFECT_EVASION_DOWN_2:
    case EFFECT_REFLECT:
    case EFFECT_POISON:
    case EFFECT_PARALYZE:
    case EFFECT_SUBSTITUTE:
    case EFFECT_LEECH_SEED:
    case EFFECT_MINIMIZE:
    case EFFECT_CURSE:
    case EFFECT_SWAGGER:
    case EFFECT_DEFENSE_CURL:
    case EFFECT_TORMENT:
    case EFFECT_FLATTER:
    case EFFECT_WILL_O_WISP:
    case EFFECT_INGRAIN:
    case EFFECT_IMPRISON:
    case EFFECT_TICKLE:
    case EFFECT_COSMIC_POWER:
    case EFFECT_BULK_UP:
    case EFFECT_CALM_MIND:
    case EFFECT_AUTOTOMIZE:
    case EFFECT_SHIFT_GEAR:
    case EFFECT_SHELL_SMASH:
    case EFFECT_GROWTH:
    case EFECTO_SUBE_ATAQUE_ESPECIAL_VELOCIDAD:
    case EFFECT_ATTACK_SPATK_UP:
    case EFFECT_ATTACK_ACCURACY_UP:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_TOXIC_SPIKES:
    case EFFECT_ESPACIO_RARO:
    case EFFECT_VIENTO_AFIN:
    case EFFECT_DRAGON_DANCE:
    case EFFECT_STICKY_WEB:
    case EFFECT_DANZA_LLUVIA:
    case EFFECT_DIA_SOLEADO:
    case EFFECT_TORMENTA_ARENA:
    case EFFECT_NEVADA:
        ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_HIT:
    {
        // TEMPORARY - should applied to all moves regardless of EFFECT
        // Consider move effects
        for (i = 0; i < gMovimientos[move].numAdditionalEffects; i++)
        {
            switch (gMovimientos[move].additionalEffects[i].moveEffect)
            {
            case MOVE_EFFECT_STEALTH_ROCK:
            case MOVE_EFFECT_SPIKES:
                ADJUST_SCORE(DECENT_EFFECT);
                break;
            default:
                break;
            }
        }
    }
    default:
        break;
    }

    return score;
}

// Adds score bonus to 'riskier' move effects and high crit moves
static s32 AI_Risky(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 i;
    struct AILogicData *aiData = AI_DATA;

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (EsMovimientoAltoIndiceCritico(move))
        ADJUST_SCORE(DECENT_EFFECT);

    // +3 Score
    switch (gMovimientos[move].effect)
    {
    case EFFECT_EXPLOSION:
        ADJUST_SCORE(STRONG_RISKY_EFFECT);
        break;
    case EFFECT_BELLY_DRUM:
        if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
    case EFFECT_ATTRACT:
        ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_HIT:
    {
        // TEMPORARY - should applied to all moves regardless of EFFECT
        // Consider move effects
        for (i = 0; i < gMovimientos[move].numAdditionalEffects; i++)
        {
            switch (gMovimientos[move].additionalEffects[i].moveEffect)
            {
            case MOVE_EFFECT_ALL_STATS_UP:
                if (Random() & 1)
                    ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
                break;
            default:
                break;
            }
        }
    }
    default:
        break;
    }

    return score;
}

// Adds score bonus to best powered move
static s32 AI_PreferStrongestMove(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
        return score;

    if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 1)
        ADJUST_SCORE(BEST_EFFECT);
    else if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex) == 2)
        ADJUST_SCORE(DECENT_EFFECT);

    return score;
}

// Prefers moves that are good for baton pass
static s32 AI_PreferRelevo(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef) || CountUsablePartyMons(battlerAtk) == 0 || !EsMovimientoEstado(move) || !HasMoveEffect(battlerAtk, EFECTO_RELEVO) || IsBattlerTrapped(battlerAtk, TRUE))
        return score;

    if (IsStatRaisingEffect(gMovimientos[move].effect))
    {
        if (gCombate->contadorTurnos == 0)
            ADJUST_SCORE(GOOD_EFFECT);
        else if (AI_DATA->hpPercents[battlerAtk] < 60)
            ADJUST_SCORE(-10);
        else
            ADJUST_SCORE(WEAK_EFFECT);
    }

    // other specific checks
    switch (gMovimientos[move].effect)
    {
    case EFFECT_INGRAIN:
        if (!(gStatuses3[battlerAtk] & STATUS3_ROOTED))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_AQUA_RING:
        if (!(gStatuses3[battlerAtk] & STATUS3_AQUA_RING))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PROTECT:
        if (gLastMoves[battlerAtk] == MOVE_PROTECT)
            ADJUST_SCORE(-2);
        else
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFECTO_RELEVO:
        if (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING))
            ADJUST_SCORE(DECENT_EFFECT);
        if (gStatuses3[battlerAtk] & STATUS3_LEECHSEED)
            ADJUST_SCORE(-3);
        ADJUST_SCORE(CountPositiveStatStages(battlerAtk) - CountNegativeStatStages(battlerAtk));
        break;
    default:
        break;
    }

    return score;
}

static s32 AI_HPAware(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 effect = gMovimientos[move].effect;
    u32 moveType = 0;

    moveType = TipoMovimiento(move, battlerAtk);

    if (IS_TARGETING_PARTNER(battlerAtk, battlerDef))
    {
        if ((effect == EFFECT_HEAL_PULSE || effect == EFFECT_HIT_ENEMY_HEAL_ALLY) || (moveType == TIPO_ELECTRICO && AI_DATA->abilities[ALIADO(battlerAtk)] == ABILITY_VOLT_ABSORB) || (moveType == TIPO_TIERRA && AI_DATA->abilities[ALIADO(battlerAtk)] == ABILITY_BANO_BARRO) || (moveType == TIPO_AGUA && AI_DATA->abilities[ALIADO(battlerAtk)] == ABILITY_WATER_ABSORB))
        {
            if (CanTargetFaintAI(FOE(battlerAtk), ALIADO(battlerAtk)) || (CanTargetFaintAI(ALIADO(FOE(battlerAtk)), ALIADO(battlerAtk))))
                ADJUST_SCORE(-1);

            if (AI_DATA->hpPercents[battlerDef] <= 50)
                ADJUST_SCORE(WEAK_EFFECT);
        }
    }
    else
    {
        // Consider AI HP
        if (AI_DATA->hpPercents[battlerAtk] > 70)
        {
            // high hp
            switch (effect)
            {
            case EFFECT_EXPLOSION:
            case EFFECT_RESTORE_HP:
            case EFFECT_REST:
            case EFFECT_DESTINY_BOND:
            case EFFECT_MORNING_SUN:
            case EFFECT_SYNTHESIS:
            case EFFECT_MOONLIGHT:
            case EFFECT_SHORE_UP:
            case EFFECT_SOFTBOILED:
            case EFFECT_ROOST:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else if (AI_DATA->hpPercents[battlerAtk] > 30)
        {
            // med hp
            if (IsStatRaisingEffect(effect) || IsStatLoweringEffect(effect))
                ADJUST_SCORE(-2);

            switch (effect)
            {
            case EFFECT_EXPLOSION:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_REFLECT:
            case EFFECT_NEBLINA:
            case EFFECT_SAFEGUARD:
            case EFFECT_BELLY_DRUM:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else
        {
            // low hp
            if (IsStatRaisingEffect(effect) || IsStatLoweringEffect(effect))
                ADJUST_SCORE(-2);

            // check other discouraged low hp effects
            switch (effect)
            {
            case EFFECT_REFLECT:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_NEBLINA:
            case EFFECT_RAGE:
            case EFFECT_LOCK_ON:
            case EFFECT_SAFEGUARD:
            case EFFECT_BELLY_DRUM:
            case EFFECT_PSYCH_UP:
            case EFFECT_TICKLE:
            case EFFECT_DIA_SOLEADO:
            case EFFECT_TORMENTA_ARENA:
            case EFFECT_NEVADA:
            case EFFECT_DANZA_LLUVIA:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
    }

    // consider target HP
    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
    {
        ADJUST_SCORE(DECENT_EFFECT);
    }
    else
    {
        if (AI_DATA->hpPercents[battlerDef] > 70)
        {
            // high HP
            ; // nothing yet
        }
        else if (AI_DATA->hpPercents[battlerDef] > 30)
        {
            // med HP - check discouraged effects
            switch (effect)
            {
            case EFFECT_ATTACK_UP:
            case EFFECT_ATTACK_UP_USER_ALLY:
            case EFFECT_DEFENSE_UP:
            case EFFECT_SPEED_UP:
            case EFFECT_SPECIAL_ATTACK_UP:
            case EFFECT_SPECIAL_DEFENSE_UP:
            case EFFECT_ACCURACY_UP:
            case EFFECT_EVASION_UP:
            case EFFECT_ATTACK_DOWN:
            case EFFECT_DEFENSE_DOWN:
            case EFFECT_SPEED_DOWN:
            case EFFECT_SPECIAL_ATTACK_DOWN:
            case EFFECT_SPECIAL_DEFENSE_DOWN:
            case EFFECT_ACCURACY_DOWN:
            case EFFECT_EVASION_DOWN:
            case EFFECT_NEBLINA:
            case EFFECT_ATTACK_UP_2:
            case EFFECT_DEFENSE_UP_2:
            case EFFECT_SPEED_UP_2:
            case EFFECT_SPECIAL_ATTACK_UP_2:
            case EFFECT_SPECIAL_DEFENSE_UP_2:
            case EFFECT_ACCURACY_UP_2:
            case EFFECT_EVASION_UP_2:
            case EFFECT_ATTACK_DOWN_2:
            case EFFECT_DEFENSE_DOWN_2:
            case EFFECT_SPEED_DOWN_2:
            case EFFECT_SPECIAL_ATTACK_DOWN_2:
            case EFFECT_SPECIAL_DEFENSE_DOWN_2:
            case EFFECT_ACCURACY_DOWN_2:
            case EFFECT_EVASION_DOWN_2:
            case EFFECT_POISON:
            case EFFECT_PERISH_SONG:
            case EFFECT_SAFEGUARD:
            case EFFECT_TICKLE:
            case EFFECT_COSMIC_POWER:
            case EFFECT_BULK_UP:
            case EFFECT_CALM_MIND:
            case EFFECT_DRAGON_DANCE:
            case EFFECT_DEFENSE_UP_3:
            case EFFECT_SPECIAL_ATTACK_UP_3:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else
        {
            // low HP
            if (EsMovimientoEstado(move))
                ADJUST_SCORE(-2); // don't use status moves if target is at low health
        }
    }

    return score;
}

static s32 AI_PowerfulStatus(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    u32 moveEffect = gMovimientos[move].effect;
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    if (gMovimientos[move].category != CATEGORIA_ESTADO || gMovimientos[AI_DATA->partnerMove].effect == moveEffect)
        return score;

    switch (moveEffect)
    {
    case EFFECT_VIENTO_AFIN:
        if (!gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer && !(gCombate->turnosEspacioRaro > 1))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_ESPACIO_RARO:
        if (!EstaEspacioRaroPuesto() && !HasMoveEffect(battlerDef, EFFECT_ESPACIO_RARO))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_SAFEGUARD:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_NEBLINA:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFECTO_VELO_AURORA:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, AI_DATA))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_TORMENTA_ARENA:
        if (!EsClimaCombateArena(climaCombate))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_DIA_SOLEADO:
        if (!EsClimaCombateSol(climaCombate))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_DANZA_LLUVIA:
        if (!EsClimaCombateLluvia(climaCombate))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_NEVADA:
        if (!EsClimaCombateNieve(climaCombate))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
    }

    return score;
}

// Dynamic AI Functions
// For specific battle scenarios

// Example - prefer attacking opposite foe in a tag battle
s32 AI_TagBattlePreferFoe(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (!IsBattlerAlive(OPONENTE(battlerAtk)) || !IsBattlerAlive(ALIADO(OPONENTE(battlerAtk))))
    {
        /* partner is defeated so attack normally */
        return score;
    }
    else if (battlerDef == OPONENTE(battlerAtk))
    {
        /* attacking along the diagonal */
        ADJUST_SCORE(-20);
    }

    return score;
}

static s32 AI_DynamicFunc(u32 battlerAtk, u32 battlerDef, u32 move, s32 score)
{
    if (sDynamicAIFunc != NULL)
        score = sDynamicAIFunc(battlerAtk, battlerDef, move, score);
    return score;
}

void ScriptSetDynamicAIFunc(struct ScriptContext *ctx)
{
    AIScoreFunc func = (AIScoreFunc)ScriptReadWord(ctx);
    sDynamicAIFunc = func;
}

void ResetDynamicAIFunc(void)
{
    sDynamicAIFunc = NULL;
}

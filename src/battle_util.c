#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "party_menu.h"
#include "pokemon.h"
#include "international_string_util.h"
#include "item.h"
#include "util.h"
#include "battle_scripts.h"
#include "random.h"
#include "text.h"
#include "safari_zone.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "window.h"
#include "battle_message.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "event_data.h"
#include "malloc.h"
#include "berry.h"
#include "pokedex.h"
#include "mail.h"
#include "field_weather.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"
#include "constants/pokemon.h"

/*
NOTE: The data and functions in this file up until (but not including) sSoundMovesTable
are actually part of battle_main.c. They needed to be moved to this file in order to
match the ROM; this is also why sSoundMovesTable's declaration is in the middle of
functions instead of at the top of the file with the other declarations.
*/

static bool32 TryRemoveScreens(u32 battler);
static void SetRandomMultiHitCounter();
static u32 GetBattlerItemHoldEffectParam(u32 battler, u32 item);
static bool32 CanBeInfinitelyConfused(u32 battler);

extern const u8 *const gBattlescriptsForRunningByItem[];

#define HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(funcionChequeo, estado)                       \
    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)                                      \
     && IsBattlerAlive(gBattlerAttacker)                                                 \
     && !gProtectStructs[gBattlerAttacker].confusionSelfDmg                              \
     && IsBattlerTurnDamaged(gBattlerAttacker)                                           \
     && funcionChequeo(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker))            \
     && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS      \
     && IsMoveMakingContact(move, gBattlerAttacker))                                     \
    {                                                                                    \
        gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | estado;                 \
        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);                      \
        BattleScriptPushCursor();                                                        \
        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;                       \
        gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;                                   \
        effect++;                                                                        \
    }

static const u8 sPkblToEscapeFactor[][3] = {
    {
        [B_MSG_MON_CURIOUS]    = 0,
        [B_MSG_MON_ENTHRALLED] = 0,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 3,
        [B_MSG_MON_ENTHRALLED] = 5,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 2,
        [B_MSG_MON_ENTHRALLED] = 3,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 2,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 1,
        [B_MSG_MON_IGNORED]    = 0
    }
};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

static void CheckSetUnburden(u8 battler)
{
    if (GetBattlerAbility(battler) == ABILITY_UNBURDEN)
    {
        gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_UNBURDEN;
        RecuerdaHabilidadCombate(battler, ABILITY_UNBURDEN);
    }
}

bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move)
{
    u32 ability = GetBattlerAbility(battlerAtk);

    if (gSideTimers[defSide].followmeTimer == 0
        || !IsBattlerAlive(gSideTimers[defSide].followmeTarget)
        || gMovesInfo[move].effect == EFFECT_SNIPE_SHOT
        || gMovesInfo[move].effect == EFFECT_SKY_DROP
        || ability == ABILITY_PROPELLER_TAIL || ability == ABILITY_STALWART)
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowder(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk, TRUE)))
        return FALSE;

    return TRUE;
}

// Functions
void HandleAction_UseMove(void)
{
    u32 battler, i, side, moveType, var = 4;
    u16 moveTarget;

    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gBattleStruct->absentBattlerFlags & (1u << gBattlerAttacker)
     || !IsBattlerAlive(gBattlerAttacker))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gEsGolpeCritico = FALSE;
    gBattleStruct->atkCancellerTracker = 0;
    gMoveResultFlags = 0;
    gMultiHitCounter = 0;
    gBattleScripting.savedDmg = 0;
    gMensajeBatalla = 0;
    gBattleScripting.savedMoveEffect = 0;
    gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = FALSE;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(MOVE_STRUGGLE, NO_TARGET_OVERRIDE);
    }
    else if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
             && gDisableStructs[gBattlerAttacker].encoredMove == gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrentMove = gChosenMove = gDisableStructs[gBattlerAttacker].encoredMove;
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE
          && gDisableStructs[gBattlerAttacker].encoredMove != gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gDisableStructs[gBattlerAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].encoredMovePos = 0;
        gDisableStructs[gBattlerAttacker].encoreTimer = 0;
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gMovimientoElegido[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        *(gBattleStruct->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    if (IsBattlerAlive(gBattlerAttacker))
    {
        if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    // Set dynamic move type.
    SetTypeBeforeUsingMove(gChosenMove, gBattlerAttacker);
    moveType = GetMoveType(gCurrentMove);

    moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    // choose target
    side = OPONENTE(GetBattlerSide(gBattlerAttacker));
    if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove)
        && moveTarget == MOVE_TARGET_SELECTED
        && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gSideTimers[side].followmeTarget))
    {
        gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = gSideTimers[side].followmeTarget; // follow me moxie fix
    }
    else if (EsContraEntrenador()
           && gSideTimers[side].followmeTimer == 0
           && (!IS_MOVE_STATUS(gCurrentMove) || (moveTarget != MOVE_TARGET_USER && moveTarget != MOVE_TARGET_ALL_BATTLERS))
           && ((GetBattlerAbility(*(gBattleStruct->moveTarget + gBattlerAttacker)) != ABILITY_LIGHTNING_ROD && moveType == TIPO_ELECTRICO)
            || (GetBattlerAbility(*(gBattleStruct->moveTarget + gBattlerAttacker)) != ABILITY_STORM_DRAIN && moveType == TIPO_AGUA)))
    {
        side = GetBattlerSide(gBattlerAttacker);
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (side != GetBattlerSide(battler)
                && *(gBattleStruct->moveTarget + gBattlerAttacker) != battler
                && ((GetBattlerAbility(battler) == ABILITY_LIGHTNING_ROD && moveType == TIPO_ELECTRICO)
                 || (GetBattlerAbility(battler) == ABILITY_STORM_DRAIN && moveType == TIPO_AGUA))
                && GetBattlerTurnOrderNum(battler) < var
                && gMovesInfo[gCurrentMove].effect != EFFECT_SNIPE_SHOT
                && GetBattlerAbility(gBattlerAttacker) != ABILITY_PROPELLER_TAIL
                && GetBattlerAbility(gBattlerAttacker) != ABILITY_STALWART)
            {
                var = GetBattlerTurnOrderNum(battler);
            }
        }
        if (var == 4)
        {
            if (moveTarget & MOVE_TARGET_RANDOM)
            {
                gBattlerTarget = SetRandomTarget(gBattlerAttacker);
            }
            else if (moveTarget & MOVE_TARGET_FOES_AND_ALLY)
            {
                for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
                {
                    if (gBattlerTarget == gBattlerAttacker)
                        continue;
                    if (IsBattlerAlive(gBattlerTarget))
                        break;
                }
            }
            else
            {
                gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
            }

            if (!IsBattlerAlive(gBattlerTarget) && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            {
                gBattlerTarget = ALIADO(gBattlerTarget);
            }
        }
        else
        {
            u16 battlerAbility;
            battler = gBattlerByTurnOrder[var];
            battlerAbility = GetBattlerAbility(battler);

            RecuerdaHabilidadCombate(battler, gBattleMons[battler].ability);
            if (battlerAbility == ABILITY_LIGHTNING_ROD && gCurrentMove != MOVE_TEATIME)
                gSpecialStatuses[battler].lightningRodRedirected = TRUE;
            else if (battlerAbility == ABILITY_STORM_DRAIN)
                gSpecialStatuses[battler].stormDrainRedirected = TRUE;
            gBattlerTarget = battler;
        }
    }
	else if (EsContraEntrenador() && moveTarget & MOVE_TARGET_RANDOM)
    {
        gBattlerTarget = SetRandomTarget(gBattlerAttacker);
        if (gAbsentBattlerFlags & (1u << gBattlerTarget)
            && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
        {
            gBattlerTarget = ALIADO(gBattlerTarget);
        }
    }
    else if (moveTarget == MOVE_TARGET_ALLY)
    {
        if (IsBattlerAlive(ALIADO(gBattlerAttacker)))
            gBattlerTarget = ALIADO(gBattlerAttacker);
        else
            gBattlerTarget = gBattlerAttacker;
    }
	else if (EsContraEntrenador() && moveTarget == MOVE_TARGET_FOES_AND_ALLY)
    {
        for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
        {
            if (gBattlerTarget == gBattlerAttacker)
                continue;
            if (IsBattlerAlive(gBattlerTarget))
                break;
        }
    }
    else
    {
        gBattlerTarget = *(gBattleStruct->moveTarget + gBattlerAttacker);
        if (!IsBattlerAlive(gBattlerTarget)
         && moveTarget != MOVE_TARGET_OPPONENTS_FIELD
         && (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)))
        {
            gBattlerTarget = ALIADO(gBattlerTarget);
        }
    }

    if ((GetBattlerSide(gBattlerAttacker) == GetBattlerSide(gBattlerTarget))
     && (!IsBattlerAlive(gBattlerTarget) || gProtectStructs[ALIADO(gBattlerAttacker)].usedAllySwitch))
    {
        gBattlescriptCurrInstr = BattleScript_FailedFromAtkCanceler;
    }
    else
    {
        gBattlescriptCurrInstr = GET_MOVE_BATTLESCRIPT(gCurrentMove);
    }

    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        gBattleStruct->hpBefore[i] = gBattleMons[i].hp;
    }

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gBattleStruct->battlerPartyIndexes + gBattlerAttacker))

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;

    TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_SWITCH);
}

void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gCurrentTurnActionNumber = gBattlersCount;

    if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
        gBattleOutcome = B_OUTCOME_RAN;
    else
        gBattleOutcome = B_OUTCOME_MON_FLED;
}

void HandleAction_ThrowBall(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gLastUsedItem = gBallToDisplay;
    RemoveBagItem(gLastUsedItem, 1);
    gBattlescriptCurrInstr = ScriptBatalla_LanzaPokeball;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_TryFinish(void)
{
    if (!HandleFaintedMonActions())
    {
        gBattleStruct->faintedActionsState = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
    }
}

void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_PASSIVE_DAMAGE
                    | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING);
}

void HandleAction_ActionFinished(void)
{
    u32 i, j;
    bool32 afterYouActive = gSpecialStatuses[gBattlerByTurnOrder[gCurrentTurnActionNumber + 1]].afterYou;
    *(gBattleStruct->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = gSelectedMonPartyId = PARTY_SIZE;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_PASSIVE_DAMAGE
                    | HITMARKER_SYNCHRONISE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_IGNORE_DISGUISE);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.moveendState = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;

    if (B_RECALC_TURN_AFTER_ACTIONS >= GEN_8 && !afterYouActive)
    {
        // i starts at `gCurrentTurnActionNumber` because we don't want to recalculate turn order for mon that have already
        // taken action. It's been previously increased, which we want in order to not recalculate the turn of the mon that just finished its action
        for (i = gCurrentTurnActionNumber; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                u32 battler1 = gBattlerByTurnOrder[i];
                u32 battler2 = gBattlerByTurnOrder[j];

                // We recalculate order only for action of the same priority. If any action other than switch/move has been taken, they should
                // have been executed before. The only recalculation needed is for moves/switch. Mega evolution is handled in src/battle_main.c/TryChangeOrder
                if((gActionsByTurnOrder[i] == B_ACTION_USE_MOVE && gActionsByTurnOrder[j] == B_ACTION_USE_MOVE))
                {
                    if (GetWhichBattlerFaster(battler1, battler2, FALSE) == -1)
                        SwapTurnOrder(i, j);
                }
                else if ((gActionsByTurnOrder[i] == B_ACTION_SWITCH && gActionsByTurnOrder[j] == B_ACTION_SWITCH))
                {
                    if (GetWhichBattlerFaster(battler1, battler2, TRUE) == -1) // If the actions chosen are switching, we recalc order but ignoring the moves
                        SwapTurnOrder(i, j);
                }
            }
        }
    }
}

static const u8 sHoldEffectToType[][2] =
{
    {HOLD_EFFECT_BUG_POWER, TIPO_BICHO},
    {HOLD_EFFECT_STEEL_POWER, TIPO_ACERO},
    {HOLD_EFFECT_GROUND_POWER, TIPO_TIERRA},
    {HOLD_EFFECT_ROCK_POWER, TIPO_ROCA},
    {HOLD_EFFECT_GRASS_POWER, TIPO_PLANTA},
    {HOLD_EFFECT_DARK_POWER, TIPO_SINIESTRO},
    {HOLD_EFFECT_FIGHTING_POWER, TIPO_LUCHA},
    {HOLD_EFFECT_ELECTRIC_POWER, TIPO_ELECTRICO},
    {HOLD_EFFECT_WATER_POWER, TIPO_AGUA},
    {HOLD_EFFECT_FLYING_POWER, TIPO_VOLADOR},
    {HOLD_EFFECT_POISON_POWER, TIPO_VENENO},
    {HOLD_EFFECT_ICE_POWER, TIPO_HIELO},
    {HOLD_EFFECT_GHOST_POWER, TIPO_FANTASMA},
    {HOLD_EFFECT_PSYCHIC_POWER, TIPO_PSIQUICO},
    {HOLD_EFFECT_FIRE_POWER, TIPO_FUEGO},
    {HOLD_EFFECT_DRAGON_POWER, TIPO_DRAGON},
    {HOLD_EFFECT_NORMAL_POWER, TIPO_NORMAL},
    {HOLD_EFFECT_FAIRY_POWER, TIPO_HADA},
};

// percent in UQ_4_12 format
static const uq4_12_t sPercentToModifier[] =
{
    UQ_4_12(0.00), // 0
    UQ_4_12(0.01), // 1
    UQ_4_12(0.02), // 2
    UQ_4_12(0.03), // 3
    UQ_4_12(0.04), // 4
    UQ_4_12(0.05), // 5
    UQ_4_12(0.06), // 6
    UQ_4_12(0.07), // 7
    UQ_4_12(0.08), // 8
    UQ_4_12(0.09), // 9
    UQ_4_12(0.10), // 10
    UQ_4_12(0.11), // 11
    UQ_4_12(0.12), // 12
    UQ_4_12(0.13), // 13
    UQ_4_12(0.14), // 14
    UQ_4_12(0.15), // 15
    UQ_4_12(0.16), // 16
    UQ_4_12(0.17), // 17
    UQ_4_12(0.18), // 18
    UQ_4_12(0.19), // 19
    UQ_4_12(0.20), // 20
    UQ_4_12(0.21), // 21
    UQ_4_12(0.22), // 22
    UQ_4_12(0.23), // 23
    UQ_4_12(0.24), // 24
    UQ_4_12(0.25), // 25
    UQ_4_12(0.26), // 26
    UQ_4_12(0.27), // 27
    UQ_4_12(0.28), // 28
    UQ_4_12(0.29), // 29
    UQ_4_12(0.30), // 30
    UQ_4_12(0.31), // 31
    UQ_4_12(0.32), // 32
    UQ_4_12(0.33), // 33
    UQ_4_12(0.34), // 34
    UQ_4_12(0.35), // 35
    UQ_4_12(0.36), // 36
    UQ_4_12(0.37), // 37
    UQ_4_12(0.38), // 38
    UQ_4_12(0.39), // 39
    UQ_4_12(0.40), // 40
    UQ_4_12(0.41), // 41
    UQ_4_12(0.42), // 42
    UQ_4_12(0.43), // 43
    UQ_4_12(0.44), // 44
    UQ_4_12(0.45), // 45
    UQ_4_12(0.46), // 46
    UQ_4_12(0.47), // 47
    UQ_4_12(0.48), // 48
    UQ_4_12(0.49), // 49
    UQ_4_12(0.50), // 50
    UQ_4_12(0.51), // 51
    UQ_4_12(0.52), // 52
    UQ_4_12(0.53), // 53
    UQ_4_12(0.54), // 54
    UQ_4_12(0.55), // 55
    UQ_4_12(0.56), // 56
    UQ_4_12(0.57), // 57
    UQ_4_12(0.58), // 58
    UQ_4_12(0.59), // 59
    UQ_4_12(0.60), // 60
    UQ_4_12(0.61), // 61
    UQ_4_12(0.62), // 62
    UQ_4_12(0.63), // 63
    UQ_4_12(0.64), // 64
    UQ_4_12(0.65), // 65
    UQ_4_12(0.66), // 66
    UQ_4_12(0.67), // 67
    UQ_4_12(0.68), // 68
    UQ_4_12(0.69), // 69
    UQ_4_12(0.70), // 70
    UQ_4_12(0.71), // 71
    UQ_4_12(0.72), // 72
    UQ_4_12(0.73), // 73
    UQ_4_12(0.74), // 74
    UQ_4_12(0.75), // 75
    UQ_4_12(0.76), // 76
    UQ_4_12(0.77), // 77
    UQ_4_12(0.78), // 78
    UQ_4_12(0.79), // 79
    UQ_4_12(0.80), // 80
    UQ_4_12(0.81), // 81
    UQ_4_12(0.82), // 82
    UQ_4_12(0.83), // 83
    UQ_4_12(0.84), // 84
    UQ_4_12(0.85), // 85
    UQ_4_12(0.86), // 86
    UQ_4_12(0.87), // 87
    UQ_4_12(0.88), // 88
    UQ_4_12(0.89), // 89
    UQ_4_12(0.90), // 90
    UQ_4_12(0.91), // 91
    UQ_4_12(0.92), // 92
    UQ_4_12(0.93), // 93
    UQ_4_12(0.94), // 94
    UQ_4_12(0.95), // 95
    UQ_4_12(0.96), // 96
    UQ_4_12(0.97), // 97
    UQ_4_12(0.98), // 98
    UQ_4_12(0.99), // 99
    UQ_4_12(1.00), // 100
};

// code
u8 GetBattlerForBattleScript(u8 caseId)
{
    u8 ret = 0;
    switch (caseId)
    {
    case BS_TARGET:
        ret = gBattlerTarget;
        break;
    case BS_ATTACKER:
        ret = gBattlerAttacker;
        break;
    case BS_ATTACKER_PARTNER:
        ret = ALIADO(gBattlerAttacker);
        break;
    case BS_EFFECT_BATTLER:
        ret = gEffectBattler;
        break;
    case BS_BATTLER_0:
        ret = 0;
        break;
    case BS_SCRIPTING:
        ret = gBattleScripting.battler;
        break;
    case BS_FAINTED:
        ret = gBattlerFainted;
        break;
    case BS_FAINTED_MULTIPLE_1:
        ret = gBattlerFainted;
        break;
    case BS_ATTACKER_WITH_PARTNER:
    case BS_FAINTED_MULTIPLE_2:
    case BS_ATTACKER_SIDE:
    case BS_TARGET_SIDE:
        ret = JUGADOR_IZQUIERDA;
        break;
    case BS_OPPONENT:
        ret = OPONENTE_IZQUIERDA;
        break;
    case BS_ABILITY_BATTLER:
        ret = gBattlerAbility;
        break;
    }
    return ret;
}

void MarcaCombatienteOcupado(u32 combatiente)
{
    gFlagCombatientesOcupados[combatiente] = TRUE;
}

void DesmarcaCombatienteOcupado(u32 combatiente)
{
    gFlagCombatientesOcupados[combatiente] = FALSE;
}

bool32 EstaCombatienteOcupado(u32 combatiente)
{
    return gFlagCombatientesOcupados[combatiente];
}

bool32 HayAlgunCombatienteOcupado(void)
{
    for (u32 combatiente = JUGADOR_IZQUIERDA; combatiente < NUMERO_COMBATIENTES; combatiente++)
    {
        if (EstaCombatienteOcupado(combatiente))
            return TRUE;
    }
    return FALSE;
}

const u8* CancelMultiTurnMoves(u32 battler)
{
    const u8 *result = NULL;
    gBattleMons[battler].status2 &= ~(STATUS2_UPROAR);
    gBattleMons[battler].status2 &= ~(STATUS2_BIDE);

    if (B_RAMPAGE_CANCELLING < GEN_5)
    {
        gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
        gBattleMons[battler].status2 &= ~(STATUS2_LOCK_CONFUSE);
    }
    else if (!(gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE)
     || ((gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE) > STATUS2_LOCK_CONFUSE_TURN(1)))
    {
        gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
    }

    // Clear battler's semi-invulnerable bits if they are not held by Sky Drop.
    if (!(gStatuses3[battler] & STATUS3_SKY_DROPPED))
        gStatuses3[battler] &= ~(STATUS3_SEMI_INVULNERABLE);

    // Check to see if this Pokemon was in the middle of using Sky Drop. If so, release the target.
    if (gBattleStruct->skyDropTargets[battler] != 0xFF && !(gStatuses3[battler] & STATUS3_SKY_DROPPED))
    {
        // Get the target's battler id
        u8 otherSkyDropper = gBattleStruct->skyDropTargets[battler];

        // Clears sky_dropped and on_air statuses
        gStatuses3[otherSkyDropper] &= ~(STATUS3_SKY_DROPPED | STATUS3_ON_AIR);

        // Makes both attacker and target's sprites visible
        gSprites[gBattlerSpriteIds[battler]].invisible = FALSE;
        gSprites[gBattlerSpriteIds[otherSkyDropper]].invisible = FALSE;

        // If target was sky dropped in the middle of Outrage/Thrash/Petal Dance,
        // confuse them upon release and display "confused by fatigue" message & animation.
        // Don't do this if this CancelMultiTurnMoves is caused by falling asleep via Yawn.
        if (gBattleMons[otherSkyDropper].status2 & STATUS2_LOCK_CONFUSE && gBattleStruct->turnEffectsTracker != 24)
        {
            gBattleMons[otherSkyDropper].status2 &= ~(STATUS2_LOCK_CONFUSE);

            // If the target can be confused, confuse them.
            // Don't use CanBeConfused, can cause issues in edge cases.
            if (!(GetBattlerAbility(otherSkyDropper) == ABILITY_OWN_TEMPO
                || gBattleMons[otherSkyDropper].status2 & STATUS2_CONFUSION))
            {
                // Set confused status
                gBattleMons[otherSkyDropper].status2 |= STATUS2_CONFUSION_TURN(((Random()) % 4) + 2);

                // If this CancelMultiTurnMoves is occuring due to attackcanceller
                if (gBattlescriptCurrInstr[0] == 0x0)
                {
                    gBattleStruct->skyDropTargets[battler] = 0xFE;
                }
                // If this CancelMultiTurnMoves is occuring due to VARIOUS_GRAVITY_ON_AIRBORNE_MONS
                // Reapplying STATUS3_SKY_DROPPED allows for avoiding unecessary messages when Gravity is applied to the target.
                else if (gBattlescriptCurrInstr[0] == 0x76 && gBattlescriptCurrInstr[2] == 76)
                {
                    gBattleStruct->skyDropTargets[battler] = 0xFE;
                    gStatuses3[otherSkyDropper] |= STATUS3_SKY_DROPPED;
                }
                // If this CancelMultiTurnMoves is occuring due to cancelmultiturnmoves script
                else if (gBattlescriptCurrInstr[0] == 0x76 && gBattlescriptCurrInstr[2] == 0)
                {
                    gBattlerAttacker = otherSkyDropper;
                    result = BattleScript_ThrashConfuses;
                }
                // If this CancelMultiTurnMoves is occuring due to receiving Sleep/Freeze status
                else if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT)
                {
                    gBattlerAttacker = otherSkyDropper;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    result = BattleScript_ThrashConfuses;
                }
            }
        }

        // Clear skyDropTargets data, unless this CancelMultiTurnMoves is caused by Yawn, attackcanceler, or VARIOUS_GRAVITY_ON_AIRBORNE_MONS
        if (!(gBattleMons[otherSkyDropper].status2 & STATUS2_LOCK_CONFUSE) && gBattleStruct->skyDropTargets[battler] < 4)
        {
            gBattleStruct->skyDropTargets[battler] = 0xFF;
            gBattleStruct->skyDropTargets[otherSkyDropper] = 0xFF;
        }
    }

    gDisableStructs[battler].rolloutTimer = 0;
    gDisableStructs[battler].furyCutterCounter = 0;

    return result;
}

bool32 WasUnableToUseMove(u32 battler)
{
    if (gProtectStructs[battler].prlzImmobility
        || gProtectStructs[battler].sleepImmobility
        || gProtectStructs[battler].usedImprisonedMove
        || gProtectStructs[battler].loveImmobility
        || gProtectStructs[battler].usedDisabledMove
        || gProtectStructs[battler].usedTauntedMove
        || gProtectStructs[battler].usedGravityPreventedMove
        || gProtectStructs[battler].usedHealBlockedMove
        || gProtectStructs[battler].flag2Unknown
        || gProtectStructs[battler].flinchImmobility
        || gProtectStructs[battler].confusionSelfDmg
        || gProtectStructs[battler].powderSelfDmg
        || gProtectStructs[battler].usedThroatChopPreventedMove)
        return TRUE;
    else
        return FALSE;
}

void PrepareStringBattle(u16 stringId, u32 battler)
{
    u32 targetSide = GetBattlerSide(gBattlerTarget);
    u16 battlerAbility = GetBattlerAbility(battler);
    u16 targetAbility = GetBattlerAbility(gBattlerTarget);
    // Support for Contrary ability.
    // If a move attempted to raise stat - print "won't increase".
    // If a move attempted to lower stat - print "won't decrease".
    if (stringId == STRINGID_STATSWONTDECREASE && !(gBattleScripting.statChanger & STAT_BUFF_NEGATIVE))
        stringId = STRINGID_STATSWONTINCREASE;
    else if (stringId == STRINGID_STATSWONTINCREASE && gBattleScripting.statChanger & STAT_BUFF_NEGATIVE)
        stringId = STRINGID_STATSWONTDECREASE;

    else if (stringId == STRINGID_STATSWONTDECREASE2 && battlerAbility == ABILITY_CONTRARY)
        stringId = STRINGID_STATSWONTINCREASE2;
    else if (stringId == STRINGID_STATSWONTINCREASE2 && battlerAbility == ABILITY_CONTRARY)
        stringId = STRINGID_STATSWONTDECREASE2;

    // Check Defiant and Competitive stat raise whenever a stat is lowered.
    else if ((stringId == STRINGID_DEFENDERSSTATFELL || stringId == STRINGID_PKMNCUTSATTACKWITH)
              && ((targetAbility == ABILITY_DEFIANT && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
                 || (targetAbility == ABILITY_COMPETITIVE && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR)))
              && gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != ALIADO(gBattlerTarget)
              && ((gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != gBattlerTarget) || gBattleScripting.stickyWebStatDrop == 1)
              && !(gBattleScripting.stickyWebStatDrop == 1 && gSideTimers[targetSide].stickyWebBattlerSide == targetSide)) // Sticky Web must have been set by the foe
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_AbilityRaisesDefenderStat;
        if (targetAbility == ABILITY_DEFIANT)
            SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);
        else
            SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE);
    }
    else if (stringId == STRINGID_PKMNCUTSATTACKWITH
            && targetAbility == ABILITY_RATTLED
            && CompareStat(gBattlerTarget, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_AbilityRaisesDefenderStat;
        SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
    }

    // Signal for the trainer slide-in system.
    if ((stringId == STRINGID_ITDOESNTAFFECT || stringId == STRINGID_PKMNWASNTAFFECTED)
     && GetBattlerSide(gBattlerTarget) == LADO_OPONENTE
     && gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState != 2)
        gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState = 1;

    BtlController_EmitPrintString(battler, BUFFER_A, stringId);
    MarcaCombatienteOcupado(battler);
}

void ResetSentPokesToOpponentValue(void)
{
    s32 i;
    u32 bits = 0;

    gSentPokesToOpponent[0] = 0;
    gSentPokesToOpponent[1] = 0;

    for (i = 0; i < gBattlersCount; i += 2)
        bits |= 1u << gBattlerPartyIndexes[i];

    for (i = 1; i < gBattlersCount; i += 2)
        gSentPokesToOpponent[(i & BIT_FLANK) >> 1] = bits;
}

void OpponentSwitchInResetSentPokesToOpponentValue(u32 battler)
{
    s32 i = 0;
    u32 bits = 0;

    if (GetBattlerSide(battler) == LADO_OPONENTE)
    {
        u8 flank = ((battler & BIT_FLANK) >> 1);
        gSentPokesToOpponent[flank] = 0;

        for (i = 0; i < gBattlersCount; i += 2)
        {
            if (!(gAbsentBattlerFlags & (1u << i)))
                bits |= 1u << gBattlerPartyIndexes[i];
        }
        gSentPokesToOpponent[flank] = bits;
    }
}

void UpdateSentPokesToOpponentValue(u32 battler)
{
    if (GetBattlerSide(battler) == LADO_OPONENTE)
    {
        OpponentSwitchInResetSentPokesToOpponentValue(battler);
    }
    else
    {
        s32 i;
        for (i = 1; i < gBattlersCount; i++)
            gSentPokesToOpponent[(i & BIT_FLANK) >> 1] |= 1u << gBattlerPartyIndexes[battler];
    }
}

void BattleScriptPush(const u8 *bsPtr)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = gBattlescriptCurrInstr;
}

void BattleScriptPop(void)
{
    if (gBattleResources->battleScriptsStack->size != 0)
        gBattlescriptCurrInstr = gBattleResources->battleScriptsStack->ptr[--gBattleResources->battleScriptsStack->size];
}

static bool32 IsGravityPreventingMove(u32 move)
{
    if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        return FALSE;

    return gMovesInfo[move].gravityBanned;
}

bool32 IsHealBlockPreventingMove(u32 battler, u32 move)
{
    if (!(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
        return FALSE;

    return gMovesInfo[move].healingMove;
}

bool32 IsBelchPreventingMove(u32 battler, u32 move)
{
    if (gMovesInfo[move].effect != EFFECT_BELCH)
        return FALSE;

    return !(gBattleStruct->ateBerry[battler & BIT_SIDE] & (1u << gBattlerPartyIndexes[battler]));
}

u32 TrySetCantSelectMoveBattleScript(u32 battler)
{
    u32 limitations = 0;
    u8 moveId = gBattleResources->bufferB[battler][2];
    u32 move = gBattleMons[battler].moves[moveId];
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[battler];

    if (gDisableStructs[battler].disabledMove == move && move != MOVE_NONE)
    {
        gBattleScripting.battler = battler;
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingDisabledMove;
        limitations++;
    }

    if (move == gLastMoves[battler] && move != MOVE_STRUGGLE && (gBattleMons[battler].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(battler);
        gSelectionBattleScripts[battler] = BattleScript_SelectingTormentedMove;
        limitations++;
    }

    if (gDisableStructs[battler].tauntTimer != 0 && IS_MOVE_STATUS(move))
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveTaunt;
        limitations++;
    }

    if (gDisableStructs[battler].throatChopTimer != 0 && gMovesInfo[move].soundMove)
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveThroatChop;
        limitations++;
    }

    if (GetImprisonedMovesCount(battler, move))
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingImprisonedMove;
        limitations++;
    }

    if (IsGravityPreventingMove(move))
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveGravity;
        limitations++;
    }

    if (IsHealBlockPreventingMove(battler, move))
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveHealBlock;
        limitations++;
    }

    if (IsBelchPreventingMove(battler, move))
    {
        gCurrentMove = move;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedBelch;
        limitations++;
    }

    if (gMovesInfo[move].cantUseTwice && move == gLastResultingMoves[battler])
    {
        gCurrentMove = move;
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gCurrentMove);
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedCurrentMove;
        limitations++;
    }

    if (HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != MOVE_NONE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[battler].item;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
        limitations++;
    }

    else if ((GetBattlerAbility(battler) == ABILITY_GORILLA_TACTICS || HOLD_EFFECT_CHOICE(holdEffect)) 
            && *choicedMove != MOVE_NONE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[battler].item;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
        limitations++;
    }

    else if ((holdEffect == HOLD_EFFECT_ASSAULT_VEST || holdEffect == HOLD_EFFECT_CHALECO_TACTICO) 
            && IS_MOVE_STATUS(move) && gMovesInfo[move].effect != EFFECT_ME_FIRST)
    {
        gCurrentMove = move;
        gLastUsedItem = gBattleMons[battler].item;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveAssaultVest;
        limitations++;
    }

    if (gBattleMons[battler].pp[moveId] == 0)
    {
        gSelectionBattleScripts[battler] = BattleScript_SelectingMoveWithNoPP;
        limitations++;
    }

    if (gMovesInfo[move].effect == SIN_EFECTO)
    {
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedPlaceholder;
        limitations++;
    }

    return limitations;
}

u8 CheckMoveLimitations(u32 battler, u8 unusableMoves, u16 check)
{
    u32 move, moveEffect;
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    u16 *choicedMove = &gBattleStruct->choicedMove[battler];
    s32 i;

    gPotentialItemEffectBattler = battler;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[battler].moves[i];
        moveEffect = gMovesInfo[move].effect;
        // No move
        if (check & MOVE_LIMITATION_ZEROMOVE && move == MOVE_NONE)
            unusableMoves |= 1u << i;
        // No PP
        else if (check & MOVE_LIMITATION_PP && gBattleMons[battler].pp[i] == 0)
            unusableMoves |= 1u << i;
        // Placeholder
        else if (check & MOVE_LIMITATION_PLACEHOLDER && moveEffect == SIN_EFECTO)
            unusableMoves |= 1u << i;
        // Disable
        else if (check & MOVE_LIMITATION_DISABLED && move == gDisableStructs[battler].disabledMove)
            unusableMoves |= 1u << i;
        // Torment
        else if (check & MOVE_LIMITATION_TORMENTED && move == gLastMoves[battler] && gBattleMons[battler].status2 & STATUS2_TORMENT)
            unusableMoves |= 1u << i;
        // Taunt
        else if (check & MOVE_LIMITATION_TAUNT && gDisableStructs[battler].tauntTimer && IS_MOVE_STATUS(move))
            unusableMoves |= 1u << i;
        // Imprison
        else if (check & MOVE_LIMITATION_IMPRISON && GetImprisonedMovesCount(battler, move))
            unusableMoves |= 1u << i;
        // Encore
        else if (check & MOVE_LIMITATION_ENCORE && gDisableStructs[battler].encoreTimer && gDisableStructs[battler].encoredMove != move)
            unusableMoves |= 1u << i;
        // Choice Items
        else if (check & MOVE_LIMITATION_CHOICE_ITEM && HOLD_EFFECT_CHOICE(holdEffect) && *choicedMove != MOVE_NONE && *choicedMove != move)
            unusableMoves |= 1u << i;
        // Assault Vest
        else if (check & MOVE_LIMITATION_ASSAULT_VEST && holdEffect == HOLD_EFFECT_ASSAULT_VEST && IS_MOVE_STATUS(move) && gMovesInfo[move].effect != EFFECT_ME_FIRST)
            unusableMoves |= 1u << i;
        // Chaleco Táctico
        else if (check & MOVE_LIMITATION_ASSAULT_VEST && holdEffect == HOLD_EFFECT_CHALECO_TACTICO && IS_MOVE_STATUS(move) && gMovesInfo[move].effect != EFFECT_ME_FIRST)
            unusableMoves |= 1u << i;
        // Gravity
        else if (check & MOVE_LIMITATION_GRAVITY && IsGravityPreventingMove(move))
            unusableMoves |= 1u << i;
        // Heal Block
        else if (check & MOVE_LIMITATION_HEAL_BLOCK && IsHealBlockPreventingMove(battler, move))
            unusableMoves |= 1u << i;
        // Belch
        else if (check & MOVE_LIMITATION_BELCH && IsBelchPreventingMove(battler, move))
            unusableMoves |= 1u << i;
        // Throat Chop
        else if (check & MOVE_LIMITATION_THROAT_CHOP && gDisableStructs[battler].throatChopTimer && gMovesInfo[move].soundMove)
            unusableMoves |= 1u << i;
        // Stuff Cheeks
        else if (check & MOVE_LIMITATION_STUFF_CHEEKS && moveEffect == EFFECT_STUFF_CHEEKS && ItemId_GetPocket(gBattleMons[battler].item) != POCKET_BERRIES)
            unusableMoves |= 1u << i;
        // Gorilla Tactics
        else if (check & MOVE_LIMITATION_CHOICE_ITEM && GetBattlerAbility(battler) == ABILITY_GORILLA_TACTICS && *choicedMove != MOVE_NONE && *choicedMove != move)
            unusableMoves |= 1u << i;
        // Can't Use Twice flag
        else if (check & MOVE_LIMITATION_CANT_USE_TWICE && gMovesInfo[move].cantUseTwice && move == gLastResultingMoves[battler])
            unusableMoves |= 1u << i;
    }
    return unusableMoves;
}

#define ALL_MOVES_MASK ((1 << MAX_MON_MOVES) - 1)
bool32 AreAllMovesUnusable(u32 battler)
{
    u8 unusable = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);

    if (unusable == ALL_MOVES_MASK) // All moves are unusable.
    {
        gProtectStructs[battler].noValidMoves = TRUE;
        gSelectionBattleScripts[battler] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[battler].noValidMoves = FALSE;
    }

    return (unusable == ALL_MOVES_MASK);
}

u8 GetImprisonedMovesCount(u32 battler, u16 move)
{
    s32 i;
    u8 imprisonedMoves = 0;
    u32 battlerSide = GetBattlerSide(battler);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (battlerSide != GetBattlerSide(i) && gStatuses3[i] & STATUS3_IMPRISONED_OTHERS)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < MAX_MON_MOVES)
                imprisonedMoves++;
        }
    }

    return imprisonedMoves;
}

enum
{
    ENDTURN_ORDER,
    ENDTURN_REFLECT,
    ENDTURN_LIGHT_SCREEN,
    ENDTURN_AURORA_VEIL,
    ENDTURN_MIST,
    ENDTURN_LUCKY_CHANT,
    ENDTURN_SAFEGUARD,
    ENDTURN_TAILWIND,
    ENDTURN_WISH,
    ENDTURN_RAIN,
    ENDTURN_SANDSTORM,
    ENDTURN_SUN,
    ENDTURN_HAIL,
    ENDTURN_SNOW,
    ENDTURN_FOG,
    ENDTURN_DAMAGE_NON_TYPES,
    ENDTURN_GRAVITY,
    ENDTURN_WATER_SPORT,
    ENDTURN_MUD_SPORT,
    ENDTURN_TRICK_ROOM,
    ENDTURN_WONDER_ROOM,
    ENDTURN_MAGIC_ROOM,
    ENDTURN_FAIRY_LOCK,
    ENDTURN_STATUS_HEAL,
    ENDTURN_FIELD_COUNT,
};

u8 DoFieldEndTurnEffects(void)
{
    u8 effect = 0;

    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount && gAbsentBattlerFlags & (1u << gBattlerAttacker); gBattlerAttacker++)
    {
    }
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount && gAbsentBattlerFlags & (1u << gBattlerTarget); gBattlerTarget++)
    {
    }

    do
    {
        s32 i;
        u32 side;

        switch (gBattleStruct->turnCountersTracker)
        {
        case ENDTURN_ORDER:
            for (i = 0; i < gBattlersCount; i++)
            {
                gBattlerByTurnOrder[i] = i;
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    if (GetWhichBattlerFaster(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], FALSE) == -1)
                        SwapTurnOrder(i, j);
                }
            }

            gBattleStruct->turnCountersTracker++;
            gBattleStruct->turnSideTracker = 0;
            // fall through
        case ENDTURN_REFLECT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].reflectBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimers[side].reflectTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_REFLECT;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_REFLECT);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LIGHT_SCREEN:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].lightscreenBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimers[side].lightscreenTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LIGHTSCREEN;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_LIGHT_SCREEN);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_AURORA_VEIL:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].auroraVeilBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_AURORA_VEIL)
                {
                    if (--gSideTimers[side].auroraVeilTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_AURORA_VEIL;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_AURORA_VEIL);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_MIST:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].mistBattlerId;
                if (gSideTimers[side].mistTimer != 0 && --gSideTimers[side].mistTimer == 0)
                {
                    gSideStatuses[side] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(BattleScript_SideStatusWoreOff);
                    gBattleCommunication[MULTISTRING_CHOOSER] = side;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_MIST);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SAFEGUARD:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].safeguardBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimers[side].safeguardTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_SAFEGUARD;
                        BattleScriptExecute(BattleScript_SafeguardEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LUCKY_CHANT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].luckyChantBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LUCKY_CHANT)
                {
                    if (--gSideTimers[side].luckyChantTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LUCKY_CHANT;
                        BattleScriptExecute(BattleScript_LuckyChantEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TAILWIND:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].tailwindBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_TAILWIND)
                {
                    if (gSideTimers[side].tailwindTimer > 0 && --gSideTimers[side].tailwindTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_TAILWIND;
                        BattleScriptExecute(BattleScript_TailwindEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_WISH:
            while (gBattleStruct->turnSideTracker < gBattlersCount)
            {
                u32 battler = gBattlerByTurnOrder[gBattleStruct->turnSideTracker];
                if (gWishFutureKnock.wishCounter[battler] != 0
                 && --gWishFutureKnock.wishCounter[battler] == 0
                 && IsBattlerAlive(battler))
                {
                    gBattlerTarget = battler;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_RAIN:
            if (gBattleWeather & B_WEATHER_RAIN)
            {
                if (!(gBattleWeather & B_WEATHER_RAIN_PERMANENT))
                {
                    if (--gWishFutureKnock.weatherDuration == 0)
                    {
                        gBattleWeather &= ~B_WEATHER_RAIN_TEMPORARY;
                        gMensajeBatalla = B_MSG_RAIN_STOPPED;
                    }
                    else
                        gMensajeBatalla = B_MSG_RAIN_CONTINUES;
                }
                else
                {
                    gMensajeBatalla = B_MSG_RAIN_CONTINUES;
                }

                BattleScriptExecute(BattleScript_RainContinuesOrEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SANDSTORM:
            if (gBattleWeather & B_WEATHER_SANDSTORM)
            {
                if (!(gBattleWeather & B_WEATHER_SANDSTORM_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_SANDSTORM_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailSnowEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                gMensajeBatalla = B_MSG_SANDSTORM;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SUN:
            if (gBattleWeather & B_WEATHER_SUN)
            {
                if (!(gBattleWeather & B_WEATHER_SUN_PERMANENT)
                 && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_SUN_TEMPORARY;
                    for (i = 0; i < gBattlersCount; i++)
                        gDisableStructs[i].weatherAbilityDone = FALSE;
                    gBattlescriptCurrInstr = BattleScript_SunlightFaded;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_SunlightContinues;
                }

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_HAIL:
            if (gBattleWeather & B_WEATHER_HAIL)
            {
                if (!(gBattleWeather & B_WEATHER_HAIL_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_HAIL_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailSnowEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                gMensajeBatalla = B_MSG_HAIL;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SNOW:
            if (gBattleWeather & B_WEATHER_SNOW)
            {
                if (!(gBattleWeather & B_WEATHER_SNOW_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_SNOW_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailSnowEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_SNOW_CONTINUES;
                gMensajeBatalla = B_MSG_SNOW;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FOG:
            if (gBattleWeather & B_WEATHER_FOG)
            {
                if (!(gBattleWeather & B_WEATHER_FOG_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_FOG_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_FogEnded;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_FogContinues;
                }

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_DAMAGE_NON_TYPES:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                if (gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES && --gSideTimers[side].damageNonTypesTimer == 0)
                {
                    // There is no in-game message when this side status ends.
                    gSideStatuses[side] &= ~SIDE_STATUS_DAMAGE_NON_TYPES;
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TRICK_ROOM:
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 0 && --gFieldTimers.trickRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_TRICK_ROOM;
                BattleScriptExecute(BattleScript_TrickRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM && gFieldTimers.wonderRoomTimer > 0 && --gFieldTimers.wonderRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_WONDER_ROOM;
                BattleScriptExecute(BattleScript_WonderRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM && gFieldTimers.magicRoomTimer > 0 && --gFieldTimers.magicRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_MAGIC_ROOM;
                BattleScriptExecute(BattleScript_MagicRoomEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_WATER_SPORT:
            if (gFieldStatuses & STATUS_FIELD_WATERSPORT && --gFieldTimers.waterSportTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_WATERSPORT;
                BattleScriptExecute(BattleScript_WaterSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_MUD_SPORT:
            if (gFieldStatuses & STATUS_FIELD_MUDSPORT && --gFieldTimers.mudSportTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_MUDSPORT;
                BattleScriptExecute(BattleScript_MudSportEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && --gFieldTimers.gravityTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_GRAVITY;
                BattleScriptExecute(BattleScript_GravityEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FAIRY_LOCK:
            if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK && --gFieldTimers.fairyLockTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_FAIRY_LOCK;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_STATUS_HEAL:
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FIELD_COUNT:
            effect++;
            break;
        }
    } while (effect == 0);

    return (gBattleMainFunc != BattleTurnPassed);
}

enum
{
    ENDTURN_WEATHER_DAMAGE,
    ENDTURN_INGRAIN,
    ENDTURN_AQUA_RING,
    ENDTURN_ABILITIES,
    ENDTURN_ITEMS1,
    ENDTURN_LEECH_SEED,
    ENDTURN_POISON,
    ENDTURN_BAD_POISON,
    ENDTURN_BURN,
    ENDTURN_FROSTBITE,
    ENDTURN_NIGHTMARES,
    ENDTURN_CURSE,
    ENDTURN_WRAP,
    ENDTURN_OCTOLOCK,
    ENDTURN_UPROAR,
    ENDTURN_THRASH,
    ENDTURN_FLINCH,
    ENDTURN_DISABLE,
    ENDTURN_ENCORE,
    ENDTURN_MAGNET_RISE,
    ENDTURN_TELEKINESIS,
    ENDTURN_HEALBLOCK,
    ENDTURN_EMBARGO,
    ENDTURN_LOCK_ON,
    ENDTURN_LASER_FOCUS,
    ENDTURN_CHARGE,
    ENDTURN_TAUNT,
    ENDTURN_YAWN,
    ENDTURN_ITEMS2,
    ENDTURN_ORBS,
    ENDTURN_ROOST,
    ENDTURN_ELECTRIFY,
    ENDTURN_POWDER,
    ENDTURN_THROAT_CHOP,
    ENDTURN_CUD_CHEW,
    ENDTURN_TORMENT, // supposedly this goes after Taunt, before Encore, but Encore is first right now?
    ENDTURN_SALT_CURE,
    ENDTURN_ITEMS3,
    ENDTURN_BATTLER_COUNT
};

// Ingrain, Leech Seed, Strength Sap and Aqua Ring
s32 GetDrainedBigRootHp(u32 battler, s32 hp)
{
    if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_BIG_ROOT)
        hp = (hp * 1300) / 1000;
    if (hp == 0)
        hp = 1;

    return hp * -1;
}

#define MAGIC_GUARD_CHECK \
if (ability == ABILITY_MAGIC_GUARD) \
{\
    RecuerdaHabilidadCombate(battler, ability);\
    gBattleStruct->turnEffectsTracker++;\
            break;\
}


u8 DoBattlerEndTurnEffects(void)
{
    u32 battler, ability, i, effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);
    while (gBattleStruct->turnEffectsBattlerId < gBattlersCount && gBattleStruct->turnEffectsTracker <= ENDTURN_BATTLER_COUNT)
    {
        battler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->turnEffectsBattlerId];
        if (gAbsentBattlerFlags & (1u << battler))
        {
            gBattleStruct->turnEffectsBattlerId++;
            continue;
        }

        ability = GetBattlerAbility(battler);
        switch (gBattleStruct->turnEffectsTracker)
        {
        case ENDTURN_WEATHER_DAMAGE:
            ability = GetBattlerAbility(battler);
            if (!IsBattlerAlive(battler) || !WEATHER_HAS_EFFECT || ability == ABILITY_MAGIC_GUARD)
            {
                gBattleStruct->turnEffectsTracker++;
                break;
            }
            else if (gBattleWeather & B_WEATHER_SANDSTORM
                  && ability != ABILITY_SAND_VEIL
                  && ability != ABILITY_SAND_FORCE
                  && ability != ABILITY_SAND_RUSH
                  && ability != ABILITY_OVERCOAT
                  && !ES_COMBATIENTE_TIPO(gBattlerAttacker, TIPO_ROCA)
                  && !ES_COMBATIENTE_TIPO(gBattlerAttacker, TIPO_TIERRA)
                  && !ES_COMBATIENTE_TIPO(gBattlerAttacker, TIPO_ACERO)
                  && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                  && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_DamagingWeather);
                effect++;
            }
            else if (gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)
                  && ability == ABILITY_ICE_BODY
                  && !(gStatuses3[battler] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                  && !IsBattlerAtMaxHp(battler)
                  && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = -1 * max(1, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_IceBodyHeal);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_HAIL
                  && !ES_COMBATIENTE_TIPO(battler, TIPO_HIELO)
                  && ability != ABILITY_SNOW_CLOAK
                  && ability != ABILITY_OVERCOAT
                  && ability != ABILITY_ICE_BODY
                  && !(gStatuses3[battler] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                  && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_DamagingWeather);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_INGRAIN:  // ingrain
            if ((gStatuses3[battler] & STATUS3_ROOTED)
             && !IsBattlerAtMaxHp(battler)
             && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)
             && IsBattlerAlive(battler))
            {
                gBattleMoveDamage = GetDrainedBigRootHp(battler, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_IngrainTurnHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_AQUA_RING:  // aqua ring
            if ((gStatuses3[battler] & STATUS3_AQUA_RING)
             && !IsBattlerAtMaxHp(battler)
             && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)
             && IsBattlerAlive(battler))
            {
                gBattleMoveDamage = GetDrainedBigRootHp(battler, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_AquaRingHeal);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ABILITIES:  // end turn abilities
            if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, battler, 0, 0, 0))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS1:  // item effects
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS2:  // item effects again
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, TRUE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ITEMS3:  // berry effects
            if (gItemsInfo[gBattleMons[battler].item].pocket == POCKET_BERRIES
             || GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_RESTORE_HP)  // Edge case for Berry Juice
            {
                if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
                    effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ORBS:
            if (IsBattlerAlive(battler) && ItemBattleEffects(ITEMEFFECT_ORBS, battler, FALSE))
                effect++;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LEECH_SEED:  // leech seed
            if ((gStatuses3[battler] & STATUS3_LEECHSEED)
             && IsBattlerAlive(gStatuses3[battler] & STATUS3_LEECHSEED_BATTLER)
             && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;

                gBattlerTarget = gStatuses3[battler] & STATUS3_LEECHSEED_BATTLER; // Notice gBattlerTarget is actually the HP receiver.
                gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleScripting.animArg1 = gBattlerTarget;
                gBattleScripting.animArg2 = gBattlerAttacker;
                BattleScriptExecute(BattleScript_LeechSeedTurnDrain);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_POISON:  // poison
            if ((gBattleMons[battler].status1 & STATUS1_POISON)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!IsBattlerAtMaxHp(battler) && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                    {
                        gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BAD_POISON:  // toxic poison
            if ((gBattleMons[battler].status1 & STATUS1_TOXIC_POISON)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!IsBattlerAtMaxHp(battler) && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                    {
                        gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        BattleScriptExecute(BattleScript_PoisonHealActivates);
                        effect++;
                    }
                }
                else
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if ((gBattleMons[battler].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                        gBattleMons[battler].status1 += STATUS1_TOXIC_TURN(1);
                    gBattleMoveDamage *= (gBattleMons[battler].status1 & STATUS1_TOXIC_COUNTER) >> 8;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BURN:  // burn
            if ((gBattleMons[battler].status1 & STATUS1_BURN)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                if (gBattleWeather & B_WEATHER_RAIN)
                {
                    gBattleMoveDamage = 0;
                }
                else
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / (B_BURN_DAMAGE >= GEN_7 ? 16 : 8);
                    if (ability == ABILITY_HEATPROOF)
                    {
                        if (gBattleMoveDamage > (gBattleMoveDamage / 2) + 1) // Record ability if the burn takes less damage than it normally would.
                            RecuerdaHabilidadCombate(battler, ABILITY_HEATPROOF);
                        gBattleMoveDamage /= 2;
                    }
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_BurnTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_FROSTBITE:  // burn
            if ((gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                if (gBattleWeather & B_WEATHER_SUN)
                {
                    gBattleMoveDamage = 0;
                }
                else
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / (B_BURN_DAMAGE >= GEN_7 ? 16 : 8);
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_FrostbiteTurnDmg);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_NIGHTMARES:  // spooky nightmares
            if ((gBattleMons[battler].status2 & STATUS2_NIGHTMARE)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                // R/S does not perform this sleep check, which causes the nightmare effect to
                // persist even after the affected Pokémon has been awakened by Shed Skin.
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_NightmareTurnDmg);
                    effect++;
                }
                else
                {
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CURSE:  // curse
            if ((gBattleMons[battler].status2 & STATUS2_CURSED)
                && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_CurseTurnDmg);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_WRAP:  // wrap
            if ((gBattleMons[battler].status2 & STATUS2_WRAPPED) && IsBattlerAlive(battler))
            {
                if (--gDisableStructs[battler].wrapTurns != 0)  // damaged by wrap
                {
                    MAGIC_GUARD_CHECK;

                    gBattleScripting.animArg1 = gBattleStruct->wrappedMove[battler];
                    gBattleScripting.animArg2 = gBattleStruct->wrappedMove[battler] >> 8;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[battler]);
                    gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;
                    if (GetBattlerHoldEffect(gBattleStruct->wrappedBy[battler], TRUE) == HOLD_EFFECT_BINDING_BAND)
                        gBattleMoveDamage = CuantosPSMaximos(battler) / (B_BINDING_DAMAGE >= GEN_6 ? 6 : 8);
                    else
                        gBattleMoveDamage = CuantosPSMaximos(battler) / (B_BINDING_DAMAGE >= GEN_6 ? 8 : 16);

                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                }
                else  // broke free
                {
                    gBattleMons[battler].status2 &= ~STATUS2_WRAPPED;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[battler]);
                    gBattlescriptCurrInstr = BattleScript_WrapEnds;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_OCTOLOCK:
        {
            if (gDisableStructs[battler].octolock)
            {
                gBattlerTarget = battler;
                BattleScriptExecute(BattleScript_OctolockEndTurn);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
        }
            break;
        case ENDTURN_UPROAR:  // uproar
            if (gBattleMons[battler].status2 & STATUS2_UPROAR)
            {
                for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                {
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                     && (B_UPROAR_IGNORE_SOUNDPROOF >= GEN_5 || GetBattlerAbility(gBattlerAttacker) != ABILITY_SOUNDPROOF))
                    {
                        gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        BattleScriptExecute(BattleScript_MonWokeUpInUproar);
                        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerAttacker].status1);
                        MarcaCombatienteOcupado(gBattlerAttacker);
                        break;
                    }
                }
                if (gBattlerAttacker != gBattlersCount)
                {
                    effect = 2;  // a Pokémon was awaken
                    break;
                }
                else
                {
                    gBattlerAttacker = battler;
                    gBattleMons[battler].status2 -= STATUS2_UPROAR_TURN(1);  // uproar timer goes down
                    if (WasUnableToUseMove(battler))
                    {
                        CancelMultiTurnMoves(battler);
                        gMensajeBatalla = B_MSG_UPROAR_ENDS;
                    }
                    else if (gBattleMons[battler].status2 & STATUS2_UPROAR)
                    {
                        gMensajeBatalla = B_MSG_UPROAR_CONTINUES;
                        gBattleMons[battler].status2 |= STATUS2_MULTIPLETURNS;
                    }
                    else
                    {
                        gMensajeBatalla = B_MSG_UPROAR_ENDS;
                        CancelMultiTurnMoves(battler);
                    }
                    BattleScriptExecute(BattleScript_PrintUproarOverTurns);
                    effect = 1;
                }
            }
            if (effect != 2)
                gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_THRASH:  // thrash
            // Don't decrement STATUS2_LOCK_CONFUSE if the target is held by Sky Drop
            if (gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE && !(gStatuses3[battler] & STATUS3_SKY_DROPPED))
            {
                gBattleMons[battler].status2 -= STATUS2_LOCK_CONFUSE_TURN(1);
                if (WasUnableToUseMove(battler))
                    CancelMultiTurnMoves(battler);
                else if (!(gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE)
                 && (gBattleMons[battler].status2 & STATUS2_MULTIPLETURNS))
                {
                    gBattleMons[battler].status2 &= ~STATUS2_MULTIPLETURNS;
                    if (!(gBattleMons[battler].status2 & STATUS2_CONFUSION))
                    {
                        gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER;
                        SetMoveEffect(TRUE, FALSE);
                        if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                            BattleScriptExecute(BattleScript_ThrashConfuses);
                        effect++;
                    }
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_FLINCH:  // reset flinch
            gBattleMons[battler].status2 &= ~STATUS2_FLINCHED;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_DISABLE:  // disable
            if (gDisableStructs[battler].disableTimer != 0)
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gDisableStructs[battler].disabledMove == gBattleMons[battler].moves[i])
                        break;
                }
                if (i == MAX_MON_MOVES)  // Pokémon does not have the disabled move anymore
                {
                    gDisableStructs[battler].disabledMove = 0;
                    gDisableStructs[battler].disableTimer = 0;
                }
                else if (--gDisableStructs[battler].disableTimer == 0)  // disable ends
                {
                    gDisableStructs[battler].disabledMove = 0;
                    BattleScriptExecute(BattleScript_DisabledNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ENCORE:  // encore
            if (gDisableStructs[battler].encoreTimer != 0)
            {
                if (gBattleMons[battler].moves[gDisableStructs[battler].encoredMovePos] != gDisableStructs[battler].encoredMove)  // Pokémon does not have the encored move anymore
                {
                    gDisableStructs[battler].encoredMove = 0;
                    gDisableStructs[battler].encoreTimer = 0;
                }
                else if (--gDisableStructs[battler].encoreTimer == 0
                 || gBattleMons[battler].pp[gDisableStructs[battler].encoredMovePos] == 0)
                {
                    gDisableStructs[battler].encoredMove = 0;
                    gDisableStructs[battler].encoreTimer = 0;
                    BattleScriptExecute(BattleScript_EncoredNoMore);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LOCK_ON:
            if (gStatuses3[battler] & STATUS3_ALWAYS_HITS)
                gStatuses3[battler] -= STATUS3_ALWAYS_HITS_TURN(1);
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CHARGE:
            if (gDisableStructs[battler].chargeTimer > 0 && --gDisableStructs[battler].chargeTimer == 0)
                gStatuses3[battler] &= ~STATUS3_CHARGED_UP;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TAUNT:
            if (gDisableStructs[battler].tauntTimer && --gDisableStructs[battler].tauntTimer == 0)
            {
                BattleScriptExecute(BattleScript_BufferEndTurn);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_YAWN:
            if (gStatuses3[battler] & STATUS3_YAWN)
            {
                u16 battlerAbility = GetBattlerAbility(battler);
                gStatuses3[battler] -= STATUS3_YAWN_TURN(1);
                if (!(gStatuses3[battler] & STATUS3_YAWN) && !(gBattleMons[battler].status1 & STATUS1_ANY)
                 && battlerAbility != ABILITY_VITAL_SPIRIT
                 && battlerAbility != ABILITY_INSOMNIA && !UproarWakeUpCheck(battler)
                 && !IsLeafGuardProtected(battler))
                {
                    CancelMultiTurnMoves(battler);
                    gEffectBattler = battler;
                    gBattleMons[battler].status1 |= STATUS1_SLEEP;
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarcaCombatienteOcupado(battler);
                    BattleScriptExecute(BattleScript_YawnMakesAsleep);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_LASER_FOCUS:
            if (gStatuses3[battler] & STATUS3_LASER_FOCUS)
            {
                if (gDisableStructs[battler].laserFocusTimer == 0 || --gDisableStructs[battler].laserFocusTimer == 0)
                    gStatuses3[battler] &= ~STATUS3_LASER_FOCUS;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_EMBARGO:
            if (gStatuses3[battler] & STATUS3_EMBARGO)
            {
                if (gDisableStructs[battler].embargoTimer == 0 || --gDisableStructs[battler].embargoTimer == 0)
                {
                    gStatuses3[battler] &= ~STATUS3_EMBARGO;
                    BattleScriptExecute(BattleScript_EmbargoEndTurn);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_MAGNET_RISE:
            if (gStatuses3[battler] & STATUS3_MAGNET_RISE)
            {
                if (gDisableStructs[battler].magnetRiseTimer == 0 || --gDisableStructs[battler].magnetRiseTimer == 0)
                {
                    gStatuses3[battler] &= ~STATUS3_MAGNET_RISE;
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_STRING_BUFFER(gBattleTextBuff1, STRINGID_ELECTROMAGNETISM);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TELEKINESIS:
            if (gStatuses3[battler] & STATUS3_TELEKINESIS)
            {
                if (gDisableStructs[battler].telekinesisTimer == 0 || --gDisableStructs[battler].telekinesisTimer == 0)
                {
                    gStatuses3[battler] &= ~STATUS3_TELEKINESIS;
                    BattleScriptExecute(BattleScript_TelekinesisEndTurn);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_HEALBLOCK:
            if (gStatuses3[battler] & STATUS3_HEAL_BLOCK)
            {
                if (gDisableStructs[battler].healBlockTimer == 0 || --gDisableStructs[battler].healBlockTimer == 0)
                {
                    gStatuses3[battler] &= ~STATUS3_HEAL_BLOCK;
                    BattleScriptExecute(BattleScript_BufferEndTurn);
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_HEAL_BLOCK);
                    effect++;
                }
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ROOST: // Return flying type.
            if (gBattleResources->flags->flags[battler] & RESOURCE_FLAG_ROOST)
                gBattleResources->flags->flags[battler] &= ~RESOURCE_FLAG_ROOST;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_ELECTRIFY:
            gStatuses4[battler] &= ~STATUS4_ELECTRIFIED;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_POWDER:
            gBattleMons[battler].status2 &= ~STATUS2_POWDER;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_THROAT_CHOP:
            if (gDisableStructs[battler].throatChopTimer && --gDisableStructs[battler].throatChopTimer == 0)
            {
                BattleScriptExecute(BattleScript_ThroatChopEndTurn);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_CUD_CHEW:
            if (GetBattlerAbility(battler) == ABILITY_CUD_CHEW && !gDisableStructs[battler].cudChew && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                gDisableStructs[battler].cudChew = TRUE;
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_SALT_CURE:
            if (gStatuses4[battler] & STATUS4_SALT_CURE && IsBattlerAlive(battler))
            {
                gBattlerTarget = battler;
                if (ES_COMBATIENTE_TIPO(gBattlerTarget, TIPO_ACERO) || ES_COMBATIENTE_TIPO(gBattlerTarget, TIPO_AGUA))
                    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 4;
                else
                    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_SALT_CURE);
                BattleScriptExecute(BattleScript_SaltCureExtraDamage);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_TORMENT:
            if (gDisableStructs[battler].tormentTimer != PERMANENT_TORMENT
                && --gDisableStructs[battler].tormentTimer == 0)
            {
                gBattleMons[battler].status2 &= ~STATUS2_TORMENT;
                BattleScriptExecute(BattleScript_TormentEnds);
                effect++;
            }
            gBattleStruct->turnEffectsTracker++;
            break;
        case ENDTURN_BATTLER_COUNT:  // done
            gBattleStruct->turnEffectsTracker = 0;
            gBattleStruct->turnEffectsBattlerId++;
            break;
        }

        if (effect != 0)
            return effect;

    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);
    return 0;
}

bool32 HandleWishPerishSongOnTurnEnd(void)
{
    u32 battler;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);
    switch (gBattleStruct->wishPerishSongState)
    {
    case 0:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            battler = gBattleStruct->wishPerishSongBattlerId;

            gBattleStruct->wishPerishSongBattlerId++;

            if (gWishFutureKnock.futureSightCounter[battler] != 0
             && --gWishFutureKnock.futureSightCounter[battler] == 0
             && !(gAbsentBattlerFlags & (1u << battler)))
            {
                struct Pokemon *party;

                if (gWishFutureKnock.futureSightCounter[battler] == 0
                 && gWishFutureKnock.futureSightCounter[ALIADO(battler)] == 0)
                {
                    gSideStatuses[GetBattlerSide(battler)] &= ~SIDE_STATUS_FUTUREATTACK;
                }

                if (!IsBattlerAlive(battler))
                    continue;

                if (gWishFutureKnock.futureSightMove[battler] == MOVE_FUTURE_SIGHT)
                    gMensajeBatalla = B_MSG_FUTURE_SIGHT;
                else
                    gMensajeBatalla = B_MSG_DOOM_DESIRE;

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gWishFutureKnock.futureSightMove[battler]);

                gBattlerTarget = battler;
                gBattlerAttacker = gWishFutureKnock.futureSightBattlerIndex[battler];
                gSpecialStatuses[gBattlerTarget].shellBellDmg = IGNORE_SHELL_BELL;
                gCurrentMove = gWishFutureKnock.futureSightMove[battler];

                party = GetSideParty(GetBattlerSide(gBattlerAttacker));
                if (&party[gWishFutureKnock.futureSightPartyIndex[gBattlerTarget]] == &party[gBattlerPartyIndexes[gBattlerAttacker]])
                    SetTypeBeforeUsingMove(gCurrentMove, gBattlerAttacker);

                BattleScriptExecute(BattleScript_MonTookFutureAttack);

                return TRUE;
            }
        }
        gBattleStruct->wishPerishSongState = 1;
        gBattleStruct->wishPerishSongBattlerId = 0;
        // fall through
    case 1:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            battler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->wishPerishSongBattlerId];
            if (gAbsentBattlerFlags & (1u << battler))
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }
            gBattleStruct->wishPerishSongBattlerId++;
            if (gStatuses3[battler] & STATUS3_PERISH_SONG)
            {
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[battler].perishSongTimer);
                if (gDisableStructs[battler].perishSongTimer == 0)
                {
                    gStatuses3[battler] &= ~STATUS3_PERISH_SONG;
                    gBattleMoveDamage = gBattleMons[battler].hp;
                    gBattlescriptCurrInstr = BattleScript_PerishSongTakesLife;
                }
                else
                {
                    gDisableStructs[battler].perishSongTimer--;
                    gBattlescriptCurrInstr = BattleScript_PerishSongCountGoesDown;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                return TRUE;
            }
        }
        gBattleStruct->wishPerishSongState = 2;
        gBattleStruct->wishPerishSongBattlerId = 0;
        // fall through
    case 2:
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);

    return FALSE;
}

#define FAINTED_ACTIONS_MAX_CASE 7

bool32 HandleFaintedMonActions(void)
{
    do
    {
        s32 i;
        switch (gBattleStruct->faintedActionsState)
        {
        case 0:
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & (1u << i) && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(1u << i);
            }
            // fall through
        case 1:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gBattleStruct->givenExpMons & (1u << gBattlerPartyIndexes[gBattleStruct->faintedActionsBattlerId]))
                 && !(gAbsentBattlerFlags & (1u << gBattleStruct->faintedActionsBattlerId)))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gBattleStruct->faintedActionsState = 2;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 3;
            break;
        case 2:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 3;
            else
                gBattleStruct->faintedActionsState = 1;
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4
                && gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                gAbsentBattlerFlags |= 1u << gBattlerFainted;
                if (gBattleStruct->faintedActionsState != 1)
                    return FALSE;
            }
            break;
        case 3:
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4
                && gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                return FALSE;
            }
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            // fall through
        case 4:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gAbsentBattlerFlags & (1u << gBattleStruct->faintedActionsBattlerId)))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gBattleStruct->faintedActionsState = 5;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 6;
            break;
        case 5:
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 6;
            else
                gBattleStruct->faintedActionsState = 4;
            break;
        case 6:
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, 0, TRUE))
                return TRUE;
            gBattleStruct->faintedActionsState++;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gBattleStruct->faintedActionsState != FAINTED_ACTIONS_MAX_CASE);
    return FALSE;
}

void TryClearRageAndFuryCutter(void)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gMovimientoElegido[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~STATUS2_RAGE;
        if (gDisableStructs[i].furyCutterCounter != 0 && gMovimientoElegido[i] != MOVE_FURY_CUTTER)
            gDisableStructs[i].furyCutterCounter = 0;
    }
}

void SetAtkCancellerForCalledMove(void)
{
    gBattleStruct->atkCancellerTracker = CANCELLER_HEAL_BLOCKED;
    gBattleStruct->isAtkCancelerForCalledMove = TRUE;
}

u8 AtkCanceller_UnableToUseMove(u32 moveType)
{
    u8 effect = 0;
    u32 ability = GetBattlerAbility(gBattlerAttacker);

    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_FLAGS: // flags clear
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_DESTINY_BOND;
            gStatuses3[gBattlerAttacker] &= ~STATUS3_GRUDGE;
            gStatuses4[gBattlerAttacker] &= ~STATUS4_GLAIVE_RUSH;
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_SKY_DROP:
            // If Pokemon is being held in Sky Drop
            if (gStatuses3[gBattlerAttacker] & STATUS3_SKY_DROPPED)
            {
                gBattlescriptCurrInstr = BattleScript_MoveEnd;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_ASLEEP: // check being asleep
            if (!gBattleStruct->isAtkCancelerForCalledMove && (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) && !PorcentajeAleatorio(75))
            {
                if (UproarWakeUpCheck(gBattlerAttacker))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptPushCursor();
                    gMensajeBatalla = B_MSG_WOKE_UP_UPROAR;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u8 toSub;
                    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    else
                        gBattleMons[gBattlerAttacker].status1 -= toSub;
                    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                    {
                        if (gChosenMove != MOVE_SNORE && gChosenMove != MOVE_SLEEP_TALK)
                        {
                            gProtectStructs[gBattlerAttacker].sleepImmobility = TRUE;
                            gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                            effect = 1;
                        }
                    }
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_RECHARGE: // recharge
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
            {
                gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_RECHARGE;
                gDisableStructs[gBattlerAttacker].rechargeTimer = 0;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_FLINCH: // flinch
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FLINCHED)
            {
                gProtectStructs[gBattlerAttacker].flinchImmobility = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_DISABLED: // disabled move
            if (gDisableStructs[gBattlerAttacker].disabledMove == gCurrentMove && gDisableStructs[gBattlerAttacker].disabledMove != MOVE_NONE)
            {
                gProtectStructs[gBattlerAttacker].usedDisabledMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_HEAL_BLOCKED:
            if (gStatuses3[gBattlerAttacker] & STATUS3_HEAL_BLOCK && IsHealBlockPreventingMove(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedHealBlockedMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedHealBlockPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && IsGravityPreventingMove(gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedGravityPreventedMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedGravityPrevents;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_TAUNTED: // taunt
            if (gDisableStructs[gBattlerAttacker].tauntTimer && IS_MOVE_STATUS(gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedTauntedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_IMPRISONED: // imprisoned
            if (GetImprisonedMovesCount(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedImprisonedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_CONFUSED: // confusion
            if (!gBattleStruct->isAtkCancelerForCalledMove && gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
            {
                if (!(gStatuses4[gBattlerAttacker] & STATUS4_INFINITE_CONFUSION))
                    gBattleMons[gBattlerAttacker].status2 -= STATUS2_CONFUSION_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
                {
                     // confusion dmg
                    if (PorcentajeAleatorio(33))
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                        gBattlerTarget = gBattlerAttacker;
                        struct DamageCalculationData damageCalcData;
                        damageCalcData.battlerAtk = damageCalcData.battlerDef = gBattlerAttacker;
                        damageCalcData.move = MOVE_NONE;
                        damageCalcData.moveType = TIPO_MISTERIO;
                        damageCalcData.isCrit = FALSE;
                        damageCalcData.updateFlags = TRUE;
                        gBattleMoveDamage = CalculateMoveDamage(&damageCalcData, 40);
                        gProtectStructs[gBattlerAttacker].confusionSelfDmg = TRUE;
                        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                        BattleScriptPushCursor();
                    }
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                }
                else // snapped out of confusion
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_PARALYSED:
            if (!gBattleStruct->isAtkCancelerForCalledMove && (gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && !PorcentajeAleatorio(10))
            {
                gProtectStructs[gBattlerAttacker].prlzImmobility = TRUE;
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_IN_LOVE: // infatuation
            if (!gBattleStruct->isAtkCancelerForCalledMove && gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
            {
                gBattleScripting.battler = CountTrailingZeroBits((gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION) >> 0x10);
                if (!PorcentajeAleatorio(50))
                {
                    BattleScriptPushCursor();
                }
                else
                {
                    BattleScriptPush(BattleScript_MoveUsedIsInLoveCantAttack);
                    gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    gProtectStructs[gBattlerAttacker].loveImmobility = TRUE;
                    CancelMultiTurnMoves(gBattlerAttacker);
                }
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_BIDE: // bide
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_BIDE_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
                {
                    gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
                }
                else
                {
                    // This is removed in FRLG and Emerald for some reason
                    //gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_MULTIPLETURNS;
                    if (gBideDmg[gBattlerAttacker])
                    {
                        gCurrentMove = MOVE_BIDE;
                        gBattleScripting.bideDmg = gBideDmg[gBattlerAttacker] * 2;
                        gBattlerTarget = gBideTarget[gBattlerAttacker];
                        if (gAbsentBattlerFlags & (1u << gBattlerTarget))
                            gBattlerTarget = GetMoveTarget(MOVE_BIDE, MOVE_TARGET_SELECTED + 1);
                        gBattlescriptCurrInstr = BattleScript_BideAttack;
                    }
                    else
                    {
                        gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
                    }
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_MOVE:
            if ((gMovesInfo[gCurrentMove].powderMove) && (gBattlerAttacker != gBattlerTarget))
            {
                if ((ES_COMBATIENTE_TIPO(gBattlerTarget, TIPO_PLANTA) || GetBattlerAbility(gBattlerTarget) == ABILITY_OVERCOAT))
                {
                    gBattlerAbility = gBattlerTarget;
                    effect = 1;
                }
                else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_SAFETY_GOGGLES)
                {
                    RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_SAFETY_GOGGLES);
                    gLastUsedItem = gBattleMons[gBattlerTarget].item;
                    effect = 1;
                }

                if (effect != 0)
                    gBattlescriptCurrInstr = BattleScript_PowderMoveNoEffect;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_THROAT_CHOP:
            if (gDisableStructs[gBattlerAttacker].throatChopTimer && gMovesInfo[gCurrentMove].soundMove)
            {
                gProtectStructs[gBattlerAttacker].usedThroatChopPreventedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsThroatChopPrevented;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_EXPLODING_DAMP:
        {
            u32 dampBattler = QueCombatienteTieneHabilidad(ABILITY_DAMP);
            if (dampBattler && (gMovesInfo[gCurrentMove].effect == EFFECT_EXPLOSION
                             || gMovesInfo[gCurrentMove].effect == EFFECT_MIND_BLOWN))
            {
                gBattleScripting.battler = dampBattler - 1;
                gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        }
        case CANCELLER_MULTIHIT_MOVES:
            if (gMovesInfo[gCurrentMove].effect == EFFECT_MULTI_HIT)
            {
                if (ability == ABILITY_SKILL_LINK)
                {
                    gMultiHitCounter = 5;
                }
                else if (ability == ABILITY_ENJAMBRE)
                {
                    gMultiHitCounter = 5;
                }
                else if (ability == ABILITY_BATTLE_BOND
                && gCurrentMove == MOVE_WATER_SHURIKEN
                && gBattleMons[gBattlerAttacker].species == SPECIES_GRENINJA)
                {
                    gMultiHitCounter = 3;
                }
                else
                {
                    SetRandomMultiHitCounter();
                }

                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (gMovesInfo[gCurrentMove].strikeCount > 1)
            {
                if (gMovesInfo[gCurrentMove].effect == EFFECT_POPULATION_BOMB && GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LOADED_DICE)
                {
                    gMultiHitCounter = NumeroAleatorioEnRango(4, 10);
                }
                else if (gMovesInfo[gCurrentMove].strikeCount == 2 && ability == ABILITY_HAZLO_TRIPLE)
                {
                    gMultiHitCounter = 3;
                    PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
                }
                else
                {
                    gMultiHitCounter = gMovesInfo[gCurrentMove].strikeCount;

                    if (gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_DARTS
                     && CanTargetPartner(gBattlerAttacker, gBattlerTarget)
                     && TargetFullyImmuneToCurrMove(gBattlerAttacker, gBattlerTarget))
                        gBattlerTarget = ALIADO(gBattlerTarget);
                }

                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 3, 0)
            }
            else if (gMovesInfo[gCurrentMove].effect == EFECTO_ATAQUE_EQUIPO)
            {
                struct Pokemon* party = GetBattlerParty(gBattlerAttacker);
                u32 i;

                for (i = 0; i < PARTY_SIZE; i++)
                {
                    if (GetMonData(&party[i], MON_DATA_HP)
                    && GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
                    && !GetMonData(&party[i], MON_DATA_IS_EGG))
                        gMultiHitCounter++;
                }

                gBattleStruct->posicionPokemonEquipo = 0;
                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else
            {
                gMultiHitCounter = 0;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_END:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END && gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    if (effect == 2)
    {
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerAttacker].status1);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }
    return effect;
}

// After Protean Activation.
u8 AtkCanceller_UnableToUseMove2(void)
{
    u8 effect = 0;

    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case CANCELLER_END:
            gBattleStruct->atkCancellerTracker++;
            break;
        case CANCELLER_END2:
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != CANCELLER_END2 && effect == 0);

    return effect;
}

bool32 HasNoMonsToSwitch(u32 battler, u8 partyIdBattlerOn1, u8 partyIdBattlerOn2)
{
    u32 i, side, playerId, flankId;
    struct Pokemon *party;

    if (!EsContraEntrenador())
        return FALSE;

    side = GetBattlerSide(battler);

    if (side == LADO_OPONENTE)
    {
        flankId = OPONENTE_IZQUIERDA;
        playerId = OPONENTE_DERECHA;
        party = gEnemyParty;
    }
    else
    {
        flankId = JUGADOR_IZQUIERDA;
        playerId = JUGADOR_DERECHA;
        party = gPlayerParty;
    }

    if (partyIdBattlerOn1 == PARTY_SIZE)
        partyIdBattlerOn1 = gBattlerPartyIndexes[flankId];
    if (partyIdBattlerOn2 == PARTY_SIZE)
        partyIdBattlerOn2 = gBattlerPartyIndexes[playerId];

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (IsValidForBattle(&party[i])
            && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
            && i != *(gBattleStruct->monToSwitchIntoId + flankId) && i != playerId[gBattleStruct->monToSwitchIntoId])
            break;
    }
    return (i == PARTY_SIZE);
}

static const u16 sWeatherFlagsInfo[][3] =
{
    [ENUM_WEATHER_RAIN] = {B_WEATHER_RAIN_TEMPORARY, B_WEATHER_RAIN_PERMANENT, HOLD_EFFECT_DAMP_ROCK},
    [ENUM_WEATHER_SUN] = {B_WEATHER_SUN_TEMPORARY, B_WEATHER_SUN_PERMANENT, HOLD_EFFECT_HEAT_ROCK},
    [ENUM_WEATHER_SANDSTORM] = {B_WEATHER_SANDSTORM_TEMPORARY, B_WEATHER_SANDSTORM_PERMANENT, HOLD_EFFECT_SMOOTH_ROCK},
    [ENUM_WEATHER_HAIL] = {B_WEATHER_HAIL_TEMPORARY, B_WEATHER_HAIL_PERMANENT, HOLD_EFFECT_ICY_ROCK},
    [ENUM_WEATHER_SNOW] = {B_WEATHER_SNOW_TEMPORARY, B_WEATHER_SNOW_PERMANENT, HOLD_EFFECT_ICY_ROCK},
    [ENUM_WEATHER_FOG] = {B_WEATHER_FOG_TEMPORARY, B_WEATHER_FOG_PERMANENT, HOLD_EFFECT_NONE},
};

bool32 TryChangeBattleWeather(u32 battler, u32 weatherEnumId, bool32 viaAbility)
{
    if (B_ABILITY_WEATHER < GEN_6 && viaAbility && !(gBattleWeather & sWeatherFlagsInfo[weatherEnumId][1]))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1]);
        return TRUE;
    }
    else if (!(gBattleWeather & (sWeatherFlagsInfo[weatherEnumId][0] | sWeatherFlagsInfo[weatherEnumId][1])))
    {
        gBattleWeather = (sWeatherFlagsInfo[weatherEnumId][0]);
        if (GetBattlerHoldEffect(battler, TRUE) == sWeatherFlagsInfo[weatherEnumId][2])
            gWishFutureKnock.weatherDuration = 8;
        else
            gWishFutureKnock.weatherDuration = 5;
        return TRUE;
    }
    return FALSE;
}

static void ForewarnChooseMove(u32 battler)
{
    struct Forewarn {
        u8 battler;
        u8 power;
        u16 moveId;
    };
    u32 i, j, bestId, count;
    struct Forewarn *data = Alloc(sizeof(struct Forewarn) * NUMERO_COMBATIENTES * MAX_MON_MOVES);

    // Put all moves
    for (count = 0, i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        if (IsBattlerAlive(i) && GetBattlerSide(i) != GetBattlerSide(battler))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[i].moves[j] == MOVE_NONE)
                    continue;
                data[count].moveId = gBattleMons[i].moves[j];
                data[count].battler = i;
                switch (gMovesInfo[data[count].moveId].effect)
                {
                case EFFECT_COUNTER:
                case EFFECT_MIRROR_COAT:
                case EFFECT_METAL_BURST:
                    data[count].power = 120;
                    break;
                default:
                    if (gMovesInfo[data[count].moveId].power == 1)
                        data[count].power = 80;
                    else
                        data[count].power = gMovesInfo[data[count].moveId].power;
                    break;
                }
                count++;
            }
        }
    }

    for (bestId = 0, i = 1; i < count; i++)
    {
        if (data[i].power > data[bestId].power)
            bestId = i;
        else if (data[i].power == data[bestId].power && Random() & 1)
            bestId = i;
    }

    gBattlerTarget = data[bestId].battler;
    PREPARE_MOVE_BUFFER(gBattleTextBuff1, data[bestId].moveId)
    RecordKnownMove(gBattlerTarget, data[bestId].moveId);

    Free(data);
}

static inline u8 GetSideFaintCounter(u32 side)
{
    return (side == LADO_JUGADOR) ? gBattleResults.playerFaintCounter : gBattleResults.opponentFaintCounter;
}

static inline u8 GetBattlerSideFaintCounter(u32 battler)
{
    return GetSideFaintCounter(GetBattlerSide(battler));
}

static inline bool32 MenosDeMediaVida(u32 combatiente)
{
    u32 mediaVida = gBattleMons[combatiente].maxHP / 2;
     return (gBattleStruct->hpBefore[combatiente] > mediaVida
             && gBattleMons[combatiente].hp <= mediaVida);
}

enum AnimacionesEstadisticas
{
    ANIM_ESTADISTICA_PS,
    ANIM_ESTADISTICA_ATAQUE,
    ANIM_ESTADISTICA_DEFENSA,
    ANIM_ESTADISTICA_ATAQUE_ESPECIAL,
    ANIM_ESTADISTICA_DEFENSA_ESPECIAL,
    ANIM_ESTADISTICA_VELOCIDAD,
    ANIM_ESTADISTICA_PRECISION,
    ANIM_ESTADISTICA_EVASION,
};

static void ChooseStatBoostAnimation(u32 battler)
{
    u32 stat;
    bool32 statBuffMoreThan1 = FALSE;
    u32 static const statsOrder[NUMERO_ESTADISTICAS_BATALLA] =
    {
        [ANIM_ESTADISTICA_PS]                   = ESTADISTICA_PS,
        [ANIM_ESTADISTICA_ATAQUE]               = ESTADISTICA_ATAQUE,
        [ANIM_ESTADISTICA_DEFENSA]              = ESTADISTICA_DEFENSA,
        [ANIM_ESTADISTICA_ATAQUE_ESPECIAL]      = ESTADISTICA_ATAQUE_ESPECIAL,
        [ANIM_ESTADISTICA_DEFENSA_ESPECIAL]     = ESTADISTICA_DEFENSA_ESPECIAL,
        [ANIM_ESTADISTICA_VELOCIDAD]            = ESTADISTICA_VELOCIDAD,
        [ANIM_ESTADISTICA_PRECISION]            = ESTADISTICA_PRECISION,
        [ANIM_ESTADISTICA_EVASION]              = ESTADISTICA_EVASION,
    };
    gBattleScripting.animArg1 = 0;

    for (stat = 1; stat < NUMERO_ESTADISTICAS_BATALLA; stat++) // Start loop at 1 to avoid ESTADISTICA_PS
    {
        if ((gQueuedStatBoosts[battler].stats & (1 << statsOrder[stat])) == 0)
            continue;

        if (!statBuffMoreThan1)
            statBuffMoreThan1 = ((gQueuedStatBoosts[battler].stats & (1 << statsOrder[stat])) > 1);

        if (gBattleScripting.animArg1 != 0) // Already set in a different stat so now boosting multiple stats
            gBattleScripting.animArg1 = (statBuffMoreThan1 ? STAT_ANIM_MULTIPLE_PLUS2 : STAT_ANIM_MULTIPLE_PLUS1);
        else
            gBattleScripting.animArg1 = GET_STAT_BUFF_ID((statsOrder[stat] + 1)) + (statBuffMoreThan1 ? STAT_ANIM_PLUS2 : STAT_ANIM_PLUS1);
    }
}
#undef ANIM_ESTADISTICA_PS
#undef ANIM_ESTADISTICA_ATAQUE
#undef ANIM_ESTADISTICA_DEFENSA
#undef ANIM_ESTADISTICA_ATAQUE_ESPECIAL
#undef ANIM_ESTADISTICA_DEFENSA_ESPECIAL
#undef ANIM_ESTADISTICA_VELOCIDAD
#undef ANIM_ESTADISTICA_PRECISION
#undef ANIM_ESTADISTICA_EVASION

u32 CanAbilityBlockMove(u32 battlerAtk, u32 battlerDef, u32 move, u32 abilityDef)
{
    enum MoveBlocked effect = MOVE_BLOCKED_BY_NO_ABILITY;

    switch (abilityDef)
    {
    case ABILITY_SOUNDPROOF:
        if (gMovesInfo[move].soundMove && !(GetBattlerMoveTargetType(battlerAtk, move) & MOVE_TARGET_USER))
            effect = MOVE_BLOCKED_BY_SOUNDPROOF_OR_BULLETPROOF;
        break;
    case ABILITY_BULLETPROOF:
        if (gMovesInfo[move].balistico)
            effect = MOVE_BLOCKED_BY_SOUNDPROOF_OR_BULLETPROOF;
        break;
    case ABILITY_DAZZLING:
    case ABILITY_QUEENLY_MAJESTY:
    case ABILITY_ARMOR_TAIL:
    case ABILITY_BELLO_PLUMAJE:
        if (GetBattlerSide(battlerAtk) != GetBattlerSide(battlerDef))
        {
            u32 priority = AI_DATA->aiCalcInProgress ? GetMovePriority(battlerAtk, move) : GetChosenMovePriority(battlerAtk);
            if (priority > 0)
                effect = MOVE_BLOCKED_BY_DAZZLING;
        }
        break;
    case ABILITY_EXUVIA:
        if (IS_MOVE_STATUS(move))
        {
            u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, move);
            if (!(moveTarget & MOVE_TARGET_OPPONENTS_FIELD) && !(moveTarget & MOVE_TARGET_ALL_BATTLERS))
                effect = MOVIMIENTO_BLOQUEADO_POR_EXUVIA;
        }
        break;
    }

    if (!effect)
        effect = CanPartnerAbilityBlockMove(battlerAtk, battlerDef, move, GetBattlerAbility(ALIADO(battlerDef)));

    return effect;
}

u32 CanPartnerAbilityBlockMove(u32 battlerAtk, u32 battlerDef, u32 move, u32 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_DAZZLING:
    case ABILITY_QUEENLY_MAJESTY:
    case ABILITY_ARMOR_TAIL:
    case ABILITY_BELLO_PLUMAJE:
        if (GetBattlerSide(battlerAtk) != GetBattlerSide(battlerDef))
        {
            s32 priority = AI_DATA->aiCalcInProgress ? GetMovePriority(battlerAtk, move) : GetChosenMovePriority(battlerAtk);
            if (priority > 0)
                return MOVE_BLOCKED_BY_PARTNER_DAZZLING;
        }
        break;
    }
    return MOVE_BLOCKED_BY_NO_ABILITY;
}

u32 CanAbilityAbsorbMove(u32 battlerAtk, u32 battlerDef, u32 abilityDef, u32 move, u32 moveType)
{
    enum MoveAbsorbed effect = MOVE_ABSORBED_BY_NO_ABILITY;

    switch (abilityDef)
    {
    default:
        effect = MOVE_ABSORBED_BY_NO_ABILITY;
        break;
    case ABILITY_VOLT_ABSORB:
        if (moveType == TIPO_ELECTRICO && gMovesInfo[move].target != MOVE_TARGET_ALL_BATTLERS)
            effect = MOVE_ABSORBED_BY_DRAIN_HP_ABILITY;
        break;
    case ABILITY_WATER_ABSORB:
    case ABILITY_DRY_SKIN:
        if (moveType == TIPO_AGUA)
            effect = MOVE_ABSORBED_BY_DRAIN_HP_ABILITY;
        break;
    case ABILITY_EARTH_EATER:
        if (moveType == TIPO_TIERRA)
            effect = MOVE_ABSORBED_BY_DRAIN_HP_ABILITY;
        break;
    case ABILITY_MOTOR_DRIVE:
        if (moveType == TIPO_ELECTRICO && gMovesInfo[move].target != MOVE_TARGET_ALL_BATTLERS) // Potential bug in singles (might be solved with simu hp reudction)
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_LIGHTNING_ROD:
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5 && moveType == TIPO_ELECTRICO && gMovesInfo[move].target != MOVE_TARGET_ALL_BATTLERS) // Potential bug in singles (might be solved with simu hp reudction)
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_STORM_DRAIN:
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5 && moveType == TIPO_AGUA)
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_SAP_SIPPER:
        if (moveType == TIPO_PLANTA)
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_WELL_BAKED_BODY:
        if (moveType == TIPO_FUEGO)
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_WIND_RIDER:
        if (gMovesInfo[move].windMove && !(GetBattlerMoveTargetType(battlerAtk, move) & MOVE_TARGET_USER))
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TIPO_FUEGO && (B_FLASH_FIRE_FROZEN >= GEN_5 || !(gBattleMons[battlerDef].status1 & STATUS1_FREEZE)))
            effect = MOVE_ABSORBED_BY_BOOST_FLASH_FIRE;
        break;
    }

    return effect;
}

u32 AbilityBattleEffects(u32 caseID, u32 battler, u32 ability, u32 special, u32 moveArg)
{
    u32 effect = 0;
    u32 moveType = 0, move = 0;
    u32 side = 0;
    u32 i = 0, j = 0;
    u32 partner = 0;

    if (gBattlerAttacker >= gBattlersCount)
        gBattlerAttacker = battler;

    if (special)
        gLastUsedAbility = special;
    else
        gLastUsedAbility = GetBattlerAbility(battler);

    if (moveArg)
        move = moveArg;
    else
        move = gCurrentMove;

    moveType = GetMoveType(move);

    switch (caseID)
    {
    case ABILITYEFFECT_SWITCH_IN_WEATHER:
        gBattleScripting.battler = battler;
        switch (GetCurrentWeather())
        {
        case WEATHER_RAIN:
        case WEATHER_RAIN_THUNDERSTORM:
        case WEATHER_DOWNPOUR:
            if (!(gBattleWeather & B_WEATHER_RAIN))
            {
                gBattleWeather = (B_WEATHER_RAIN_TEMPORARY | B_WEATHER_RAIN_PERMANENT);
                gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
                effect++;
            }
            break;
        case WEATHER_SANDSTORM:
            if (!(gBattleWeather & B_WEATHER_SANDSTORM))
            {
                gBattleWeather = B_WEATHER_SANDSTORM;
                gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                effect++;
            }
            break;
        case WEATHER_DROUGHT:
            if (!(gBattleWeather & B_WEATHER_SUN))
            {
                gBattleWeather = (B_WEATHER_SUN_PERMANENT | B_WEATHER_SUN_TEMPORARY);
                gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
                effect++;
            }
            break;
        case WEATHER_SNOW:
            if (!(gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)))
            {
                if (B_OVERWORLD_SNOW >= GEN_9)
                {
                    gBattleWeather = B_WEATHER_SNOW;
                    gBattleScripting.animArg1 = B_ANIM_SNOW_CONTINUES;
                }
                else
                {
                    gBattleWeather = B_WEATHER_HAIL;
                    gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                }
                effect++;
            }
            break;
        }
        if (effect != 0)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeather();
            BattleScriptPushCursorAndCallback(BattleScript_OverworldWeatherStarts);
        }
        break;
    case ABILITYEFFECT_ON_SWITCHIN:
        gBattleScripting.battler = battler;
        switch (gLastUsedAbility)
        {
        case ABILITY_TRACE:
            {
                u32 chosenTarget;
                u32 target1;
                u32 target2;

                if (gSpecialStatuses[battler].switchInAbilityDone)
                    break;

                side = (OPONENTE(battler)) & BIT_SIDE;
                target1 = side;
                target2 = side + BIT_FLANK;
                if (EsContraEntrenador())
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0
                        && !gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = (PorcentajeAleatorio(50 * 2) | side), effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = target2, effect++;
                }
                else
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                }

                if (effect != 0)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_TraceActivates);
                    gBattleStruct->tracedAbility[battler] = gLastUsedAbility = gBattleMons[chosenTarget].ability;
                    RecuerdaHabilidadCombate(chosenTarget, gLastUsedAbility); // Record the opposing battler has this ability
                    gBattlerAbility = battler;

                    PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff1, chosenTarget, gBattlerPartyIndexes[chosenTarget])
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
                }
            }
            break;
        case ABILITY_MAGO:
            {
                u32 chosenTarget = 0;
                u32 target1;
                u32 target2;

                if (gSpecialStatuses[battler].switchInAbilityDone)
                    break;
                if (gBattleResources->flags->flags[battler] & RESOURCE_FLAG_MAGO)
                    break;

                side = (OPONENTE(battler)) & BIT_SIDE;
                target1 = side;
                target2 = side + BIT_FLANK;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                if (EsContraEntrenador())
                {
                    if (gBattleMons[target1].item != ITEM_NONE && gBattleMons[target1].hp != 0
                        && gBattleMons[target2].item != ITEM_NONE && gBattleMons[target2].hp != 0)
                        chosenTarget = (PorcentajeAleatorio(50 * 2) | side);
                    else if (gBattleMons[target1].item != ITEM_NONE && gBattleMons[target1].hp != 0)
                        chosenTarget = target1;
                    else if (gBattleMons[target2].item != ITEM_NONE && gBattleMons[target2].hp != 0)
                        chosenTarget = target2;
                }
                else
                {
                    if (gBattleMons[target1].item != ITEM_NONE && gBattleMons[target1].hp != 0)
                        chosenTarget = target1;
                }

                if (chosenTarget != 0)
                {
                    if (gWishFutureKnock.knockedOffMons[side] & (1u << gBattlerPartyIndexes[chosenTarget]))
                    {
                        gBattlescriptCurrInstr = BattleScript_MagoEnd;
                    }
                    else if ((gBattleMons[battler].item == ITEM_NONE && gBattleMons[chosenTarget].item == ITEM_NONE))
                    {
                        gBattlescriptCurrInstr = BattleScript_MagoEnd;
                    }
                    else if (GetBattlerAbility(chosenTarget) == ABILITY_STICKY_HOLD || GetBattlerAbility(chosenTarget) == ABILITY_TERRITORIAL)
                    {
                        gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
                        gLastUsedAbility = gBattleMons[chosenTarget].ability;
                        RecuerdaHabilidadCombate(chosenTarget, gLastUsedAbility);
                    }
                    else
                    {
                        u16 oldItemAtk, newItemAtk;

                        newItemAtk = gBattleMons[chosenTarget].item;
                        oldItemAtk = gBattleMons[battler].item;

                        gBattleMons[battler].item = newItemAtk;
                        gBattleMons[chosenTarget].item = oldItemAtk;

                        RecordItemEffectBattle(battler, ItemId_GetHoldEffect(newItemAtk));
                        RecordItemEffectBattle(chosenTarget, ItemId_GetHoldEffect(oldItemAtk));

                        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battler].item), &gBattleMons[battler].item);
                        MarcaCombatienteOcupado(battler);

                        BtlController_EmitSetMonData(chosenTarget, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[chosenTarget].item), &gBattleMons[chosenTarget].item);
                        MarcaCombatienteOcupado(chosenTarget);

                        gBattleStruct->choicedMove[chosenTarget] = MOVE_NONE;
                        gBattleStruct->choicedMove[battler] = MOVE_NONE;

                        gBattlerAttacker = battler;
                        gBattlerTarget = chosenTarget;
                        PREPARE_ITEM_BUFFER(gBattleTextBuff1, newItemAtk)
                        PREPARE_ITEM_BUFFER(gBattleTextBuff2, oldItemAtk)

                        if (oldItemAtk != ITEM_NONE && newItemAtk != ITEM_NONE)
                        {
                            gMensajeBatalla = B_MSG_ITEM_SWAP_BOTH;
                        }
                        else if (oldItemAtk == ITEM_NONE && newItemAtk != ITEM_NONE)
                        {
                            if (GetBattlerAbility(battler) == ABILITY_UNBURDEN && gBattleResources->flags->flags[battler] & RESOURCE_FLAG_UNBURDEN)
                                gBattleResources->flags->flags[battler] &= ~RESOURCE_FLAG_UNBURDEN;

                            gMensajeBatalla = B_MSG_ITEM_SWAP_TAKEN;
                        }
                        else
                        {
                            CheckSetUnburden(battler);
                            gMensajeBatalla = B_MSG_ITEM_SWAP_GIVEN;
                        }
                        BattleScriptPushCursorAndCallback(BattleScript_MagoActivadoEnd);
                        gBattleResources->flags->flags[battler] &= ~RESOURCE_FLAG_MAGO;
                        effect++;
                    }
                }
            }
            break;
        case ABILITY_IMPOSTER:
            if (IsBattlerAlive(OPONENTE(battler))
                && !(gBattleMons[OPONENTE(battler)].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))
                && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED)
                && !(gBattleStruct->illusion[OPONENTE(battler)].on)
                && !(gStatuses3[OPONENTE(battler)] & STATUS3_SEMI_INVULNERABLE))
            {
                gBattlerAttacker = battler;
                gBattlerTarget = OPONENTE(battler);
                BattleScriptPushCursorAndCallback(BattleScript_ImposterActivates);
                effect++;
            }
            break;
        case ABILITY_MOLD_BREAKER:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_MOLDBREAKER;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_UNNERVE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_UNNERVE;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_CURIOUS_MEDICINE:
            break;
        case ABILITY_ANTICIPATION:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                u32 side = GetBattlerSide(battler);

                for (i = 0; i < NUMERO_COMBATIENTES; i++)
                {
                    if (IsBattlerAlive(i) && side != GetBattlerSide(i))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            move = gBattleMons[i].moves[j];
                            moveType = GetMoveType(move);
                            if (CalcTypeEffectivenessMultiplier(move, moveType, i, battler, ABILITY_ANTICIPATION, FALSE) >= UQ_4_12(2.0))
                            {
                                effect++;
                                break;
                            }
                        }
                    }
                }

                if (effect != 0)
                {
                    gMensajeBatalla = B_MSG_SWITCHIN_ANTICIPATION;
                    gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                    BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                }
            }
            break;
        case ABILITY_FRISK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                gBattleScripting.battler = battler;
                BattleScriptPushCursorAndCallback(BattleScript_FriskActivates); // Try activate
                effect++;
            }
            return effect; // Note: It returns effect as to not record the ability if Frisk does not activate.
        case ABILITY_FOREWARN:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                ForewarnChooseMove(battler);
                gMensajeBatalla = B_MSG_SWITCHIN_FOREWARN;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DOWNLOAD:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                u32 statId, opposingBattler;
                u32 opposingDef = 0, opposingSpDef = 0;

                opposingBattler = OPONENTE(battler);
                for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
                {
                    if (IsBattlerAlive(opposingBattler))
                    {
                        opposingDef += gBattleMons[opposingBattler].defense
                                    * gMultiplicadoresEstadisticas[gBattleMons[opposingBattler].statStages[ESTADISTICA_DEFENSA]] >> 8;
                        opposingSpDef += gBattleMons[opposingBattler].spDefense
                                        * gMultiplicadoresEstadisticas[gBattleMons[opposingBattler].statStages[ESTADISTICA_DEFENSA_ESPECIAL]] >> 8;
                    }
                }

                if (opposingDef < opposingSpDef)
                    statId = ESTADISTICA_ATAQUE;
                else
                    statId = ESTADISTICA_ATAQUE_ESPECIAL;

                gSpecialStatuses[battler].switchInAbilityDone = TRUE;

                if (CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR))
                {
                    SET_STATCHANGER(statId, 1, FALSE);
                    gBattlerAttacker = battler;
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                    effect++;
                }
            }
            break;
        case ABILITY_IMPENETRABLE:
        case ABILITY_RESERVA_NATURAL:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                u32 statId, opposingBattler;
                u32 opposingAtk = 0, opposingSpAtk = 0;

                opposingBattler = OPONENTE(battler);
                for (i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
                {
                    if (IsBattlerAlive(opposingBattler))
                    {
                        opposingAtk += gBattleMons[opposingBattler].attack
                                    * gMultiplicadoresEstadisticas[gBattleMons[opposingBattler].statStages[ESTADISTICA_ATAQUE]] 
                                    >> 8;
                        opposingSpAtk += gBattleMons[opposingBattler].spAttack
                                        * gMultiplicadoresEstadisticas[gBattleMons[opposingBattler].statStages[ESTADISTICA_ATAQUE_ESPECIAL]] 
                                        >> 8;
                    }
                }

                if (opposingAtk < opposingSpAtk)
                    statId = ESTADISTICA_DEFENSA_ESPECIAL;
                else
                    statId = ESTADISTICA_DEFENSA;

                gSpecialStatuses[battler].switchInAbilityDone = TRUE;

                if (CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR))
                {
                    SET_STATCHANGER(statId, 1, FALSE);
                    gBattlerAttacker = battler;
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerAbilityStatRaiseEnd3);
                    effect++;
                }
            }
            break;
        case ABILITY_PRESSURE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_PRESSURE;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DARK_AURA:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_DARKAURA;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_GENERADOR:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_GENERADOR;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_FAIRY_AURA:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_FAIRYAURA;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AURA_BREAK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_AURABREAK;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_COMATOSE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_COMATOSE;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SCREEN_CLEANER:
            if (!gSpecialStatuses[battler].switchInAbilityDone && TryRemoveScreens(battler))
            {
                gMensajeBatalla = B_MSG_SWITCHIN_SCREENCLEANER;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DRIZZLE:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
                effect++;
            }
            break;
        case ABILITY_SAND_STREAM:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SANDSTORM, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SandstreamActivates);
                effect++;
            }
            break;
        case ABILITY_DROUGHT:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SUN, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_DroughtActivates);
                effect++;
            }
            break;
        case ABILITY_SNOW_WARNING:
            if (B_SNOW_WARNING >= GEN_9 && TryChangeBattleWeather(battler, ENUM_WEATHER_SNOW, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SnowWarningActivatesSnow);
                effect++;
            }
            else if (B_SNOW_WARNING < GEN_9 && TryChangeBattleWeather(battler, ENUM_WEATHER_HAIL, TRUE))
            {
                BattleScriptPushCursorAndCallback(BattleScript_SnowWarningActivatesHail);
                effect++;
            }
            break;
        case ABILITY_INTIMIDATE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, TRUE);
                BattleScriptPushCursorAndCallback(BattleScript_IntimidateActivates);
                effect++;
            }
            break;
        case ABILITY_CLOUD_NINE:
        case ABILITY_AIR_LOCK:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(BattleScript_AnnounceAirLockCloudNine);
                effect++;
            }
            break;
        case ABILITY_SCHOOLING:
            if (gBattleMons[battler].level < 20)
                break;
        // Fallthrough
        case ABILITY_ZEN_MODE:
        case ABILITY_SHIELDS_DOWN:
            if (TryBattleFormChange(battler, FORM_CHANGE_BATTLE_HP_PERCENT))
            {
                gBattlerAttacker = battler;
                BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                effect++;
            }
            break;
        case ABILITY_INTREPID_SWORD:
            if (!gSpecialStatuses[battler].switchInAbilityDone && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR)
                 && !(gBattleStruct->intrepidSwordBoost[GetBattlerSide(battler)] & (1u << gBattlerPartyIndexes[battler])))
            {
                gBattleScripting.savedBattler = gBattlerAttacker;
                gBattlerAttacker = battler;
                if (B_INTREPID_SWORD == GEN_9)
                    gBattleStruct->intrepidSwordBoost[GetBattlerSide(battler)] |= 1u << gBattlerPartyIndexes[battler];
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
            break;
        case ABILITY_DAUNTLESS_SHIELD:
            if (!gSpecialStatuses[battler].switchInAbilityDone && CompareStat(battler, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, COMPARACION_MENOR)
                 && !(gBattleStruct->dauntlessShieldBoost[GetBattlerSide(battler)] & (1u << gBattlerPartyIndexes[battler])))
            {
                gBattleScripting.savedBattler = gBattlerAttacker;
                gBattlerAttacker = battler;
                if (B_DAUNTLESS_SHIELD == GEN_9)
                    gBattleStruct->dauntlessShieldBoost[GetBattlerSide(battler)] |= 1u << gBattlerPartyIndexes[battler];
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_DEFENSA, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
            break;
        case ABILITY_WIND_RIDER:
            if (!gSpecialStatuses[battler].switchInAbilityDone
             && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR)
             && gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
            {
                gBattleScripting.savedBattler = gBattlerAttacker;
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
                effect++;
            }
            break;
        case ABILITY_COSTAR:
        case ABILITY_REY_DEL_MAR:
            if (!gSpecialStatuses[battler].switchInAbilityDone
             && EsContraEntrenador()
             && IsBattlerAlive(ALIADO(battler))
             && CountBattlerStatIncreases(ALIADO(battler), FALSE))
            {
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                gBattlerAttacker = gBattlerAbility = battler;
                for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
                    gBattleMons[battler].statStages[i] = gBattleMons[ALIADO(battler)].statStages[i];
                gBattleScripting.battler = ALIADO(battler);
                BattleScriptPushCursorAndCallback(BattleScript_CostarActivates);
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_ENDTURN:
        if (IsBattlerAlive(battler))
        {
            gBattlerAttacker = battler;
            switch (gLastUsedAbility)
            {
            case ABILITY_HARVEST:
                if ((IsBattlerWeatherAffected(battler, B_WEATHER_SUN) || PorcentajeAleatorio(50))
                 && gBattleMons[battler].item == ITEM_NONE
                 && gBattleStruct->changedItems[battler] == ITEM_NONE   // Will not inherit an item
                 && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                {
                    gLastUsedItem = GetUsedHeldItem(battler);
                    BattleScriptPushCursorAndCallback(BattleScript_HarvestActivates);
                    effect++;
                }
                break;
            // Dry Skin works similarly to Rain Dish in Rain
            case ABILITY_RAIN_DISH:
                if (IsBattlerWeatherAffected(battler, B_WEATHER_RAIN)
                 && !IsBattlerAtMaxHp(battler)
                 && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
                break;
            case ABILITY_FOTOSINTESIS:
                if (IsBattlerWeatherAffected(battler, B_WEATHER_SUN)
                 && !IsBattlerAtMaxHp(battler)
                 && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    effect++;
                }
                break;
            case ABILITY_HYDRATION:
                if (IsBattlerWeatherAffected(battler, B_WEATHER_RAIN)
                 && gBattleMons[battler].status1 & STATUS1_ANY)
                {
                    goto ABILITY_HEAL_MON_STATUS;
                }
                break;
            case ABILITY_MUDAR:
                if ((gBattleMons[battler].status1 & STATUS1_ANY)
                && PorcentajeAleatorio(50))
                {
                ABILITY_HEAL_MON_STATUS:
                    if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
                        StringCopy(gBattleTextBuff1, gText_Poison);
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                        StringCopy(gBattleTextBuff1, gText_Sleep);
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                        StringCopy(gBattleTextBuff1, gText_Paralysis);
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                        StringCopy(gBattleTextBuff1, gText_Burn);
                    if (gBattleMons[battler].status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE))
                        StringCopy(gBattleTextBuff1, gText_Ice);

                    gBattleMons[battler].status1 = 0;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    gBattleScripting.battler = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_ShedSkinActivates);
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarcaCombatienteOcupado(battler);
                    effect++;
                }
                break;
            case ABILITY_SPEED_BOOST:
                if (CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR) && gDisableStructs[battler].isFirstTurn != 2)
                {
                    SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_MOODY:
                if (gDisableStructs[battler].isFirstTurn != 2)
                {
                    u32 validToRaise = 0, validToLower = 0;
                    u32 statsNum = B_MOODY_ACC_EVASION >= GEN_8 ? NUMERO_ESTADISTICAS : NUMERO_ESTADISTICAS_BATALLA;

                    for (i = ESTADISTICA_ATAQUE; i < statsNum; i++)
                    {
                        if (CompareStat(battler, i, ESTADISTICA_MENOS_6, COMPARACION_MAYOR))
                            validToLower |= 1u << i;
                        if (CompareStat(battler, i, ESTADISTICA_MAS_6, COMPARACION_MENOR))
                            validToRaise |= 1u << i;
                    }

                    if (validToLower != 0 || validToRaise != 0) // Can lower one stat, or can raise one stat
                    {
                        gBattleScripting.statChanger = gBattleScripting.savedStatChanger = 0; // for raising and lowering stat respectively
                        if (validToRaise != 0) // Find stat to raise
                        {
                            do
                            {
                                i = (Random() % statsNum) + ESTADISTICA_ATAQUE;
                            } while (!(validToRaise & (1u << i)));
                            SET_STATCHANGER(i, 2, FALSE);
                            validToLower &= ~(1u << i); // Can't lower the same stat as raising.
                        }
                        if (validToLower != 0) // Find stat to lower
                        {
                            do
                            {
                                i = (Random() % statsNum) + ESTADISTICA_ATAQUE;
                            } while (!(validToLower & (1u << i)));
                            SET_STATCHANGER2(gBattleScripting.savedStatChanger, i, 1, TRUE);
                        }
                        BattleScriptPushCursorAndCallback(BattleScript_MoodyActivates);
                        effect++;
                    }
                }
                break;
            case ABILITY_BAD_DREAMS:
                BattleScriptPushCursorAndCallback(BattleScript_BadDreamsActivates);
                effect++;
                break;
            case ABILITY_HEALER:
                gBattleScripting.battler = ALIADO(battler);
                if (IsBattlerAlive(gBattleScripting.battler)
                    && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY
                    && PorcentajeAleatorio(30))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_HealerActivates);
                    effect++;
                }
                break;
            // Fallthrough
            case ABILITY_ZEN_MODE:
                if (TryBattleFormChange(battler, FORM_CHANGE_BATTLE_HP_PERCENT))
                {
                    gBattlerAttacker = battler;
                    BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeEnd3);
                    effect++;
                }
                break;
            }
        }
        break;
    case ABILITYEFFECT_WOULD_BLOCK:
        effect = CanAbilityBlockMove(gBattlerAttacker, battler, move, gLastUsedAbility);
        if (effect && gLastUsedAbility != 0xFFFF)
            RecuerdaHabilidadCombate(battler, gLastUsedAbility);
        break;
    case ABILITYEFFECT_MOVES_BLOCK:
        {
            effect = CanAbilityBlockMove(gBattlerAttacker, battler, move, gLastUsedAbility);
            const u8 * battleScriptBlocksMove = NULL;
            switch (effect)
            {
            case MOVE_BLOCKED_BY_SOUNDPROOF_OR_BULLETPROOF:
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                    gHitMarker |= HITMARKER_NO_PPDEDUCT;
                battleScriptBlocksMove = BattleScript_SoundproofProtected;
                break;
            case MOVE_BLOCKED_BY_DAZZLING:
            case MOVE_BLOCKED_BY_PARTNER_DAZZLING:
                if (effect == MOVE_BLOCKED_BY_PARTNER_DAZZLING)
                    gBattleScripting.battler = ALIADO(battler);
                else
                    gBattleScripting.battler = battler;
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                    gHitMarker |= HITMARKER_NO_PPDEDUCT;
                battleScriptBlocksMove = BattleScript_HabilidadProtegeEquipoDePrioridad;
                break;
            case MOVIMIENTO_BLOQUEADO_POR_EXUVIA:
                battleScriptBlocksMove = BattleScript_GoodAsGoldActivates;
                break;
            default:
                if (GetChosenMovePriority(gBattlerAttacker) > 0
                 && BlocksPrankster(move, gBattlerAttacker, gBattlerTarget, TRUE)
                 && !(IS_MOVE_STATUS(move) && (gLastUsedAbility == ABILITY_MAGIC_BOUNCE || gProtectStructs[gBattlerTarget].bounceMove)))
                {
                    if (!EsContraEntrenador()
                    || !(GetBattlerMoveTargetType(gBattlerAttacker, move) & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
                        CancelMultiTurnMoves(gBattlerAttacker); // Don't cancel moves that can hit two targets bc one target might not be protected
                    gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
                    battleScriptBlocksMove = BattleScript_DarkTypePreventsPrankster;
                    effect = 1;
                }
            }
            if (effect)
                gBattlescriptCurrInstr = battleScriptBlocksMove;
        }
        break;
    case ABILITYEFFECT_WOULD_ABSORB:
        effect = CanAbilityAbsorbMove(gBattlerAttacker, battler, gLastUsedAbility, move, moveType);
        if (effect && gLastUsedAbility != 0xFFFF)
            RecuerdaHabilidadCombate(battler, gLastUsedAbility);
        return effect;
    case ABILITYEFFECT_ABSORBING:
        {
            u32 statId = 0;
            u32 statAmount = 1;
            effect = CanAbilityAbsorbMove(gBattlerAttacker, battler, gLastUsedAbility, move, moveType);
            if (effect)
            {
                switch(gLastUsedAbility)
                {
                case ABILITY_MOTOR_DRIVE:
                    statId = ESTADISTICA_VELOCIDAD;
                    break;
                case ABILITY_LIGHTNING_ROD:
                case ABILITY_STORM_DRAIN:
                    statId = ESTADISTICA_ATAQUE_ESPECIAL;
                    break;
                case ABILITY_SAP_SIPPER:
                case ABILITY_WIND_RIDER:
                    statId = ESTADISTICA_ATAQUE;
                    break;
                case ABILITY_WELL_BAKED_BODY:
                    statAmount = 2;
                    statId = ESTADISTICA_DEFENSA;
                    break;
                }
            }
            switch (effect)
            {
            case MOVE_ABSORBED_BY_DRAIN_HP_ABILITY:
                if (IsBattlerAtMaxHp(battler) || (B_HEAL_BLOCKING >= GEN_5 && gStatuses3[battler] & STATUS3_HEAL_BLOCK))
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;

                    gBattleMoveDamage = CuantosPSMaximos(battler) / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                }
                break;
            case MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY:
                if (!CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR))
                {
                    if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                    else
                        gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                }
                else
                {
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveStatDrain_PPLoss;

                    SET_STATCHANGER(statId, statAmount, FALSE);
                    if (B_ABSORBING_ABILITY_STRING < GEN_5)
                        PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
                }
                break;
            case MOVE_ABSORBED_BY_BOOST_FLASH_FIRE:
                if (!(gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
                {
                    gMensajeBatalla = B_MSG_FLASH_FIRE_BOOST;
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                    else
                        gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                    gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
                }
                else
                {
                    gMensajeBatalla = B_MSG_FLASH_FIRE_NO_BOOST;
                    if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                        gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                    else
                        gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                }
                break;
            }
            if (effect)
                gMultiHitCounter = 0; // Prevent multi-hit moves from hitting more than once after move has been absorbed.

        }
        break;
    case ABILITYEFFECT_MOVE_END: // Think contact abilities.
        switch (gLastUsedAbility)
        {
        case ABILITY_JUSTIFIED:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && (moveType == TIPO_SINIESTRO || moveType == TIPO_DRAGON || moveType == TIPO_FANTASMA)
             && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && (moveType == TIPO_SINIESTRO || moveType == TIPO_BICHO || moveType == TIPO_FANTASMA)
             && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_ALAS_HIDROFOBAS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && moveType == TIPO_AGUA
             && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_STAMINA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattlerAttacker != gBattlerTarget
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && CompareStat(battler, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_DEFENSA, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_IRA_PRIMATE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattlerAttacker != gBattlerTarget
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_COLERA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && MenosDeMediaVida(battler)
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove))
             && CompareStat(battler, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_CABLE_PELADO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && MenosDeMediaVida(battler)
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1)
             && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove))
             && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && (CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR) // Don't activate if both Speed and Defense cannot be raised.
               || CompareStat(battler, ESTADISTICA_DEFENSA, ESTADISTICA_MENOS_6, COMPARACION_MAYOR)))
            {
                if (gMovesInfo[gCurrentMove].effect == EFFECT_HIT_ESCAPE && CanBattlerSwitch(gBattlerAttacker))
                    gProtectStructs[battler].disableEjectPack = TRUE;  // Set flag for target

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WeakArmorActivates;
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && gDisableStructs[gBattlerAttacker].disabledMove == MOVE_NONE
             && IsBattlerAlive(gBattlerAttacker)
             && !EstaHabilidadEnElLadoDeCombatiente(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0
             && PorcentajeAleatorio(50))
            {
                gDisableStructs[gBattlerAttacker].disabledMove = gChosenMove;
                gDisableStructs[gBattlerAttacker].disableTimer = 4;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CursedBodyActivates;
                effect++;
            }
            break;
        case ABILITY_LINGERING_AROMA:
        case ABILITY_MUMMY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker)
             && gBattleStruct->overwrittenAbilities[gBattlerAttacker] != GetBattlerAbility(gBattlerTarget)
             && gBattleMons[gBattlerAttacker].ability != ABILITY_MUMMY
             && gBattleMons[gBattlerAttacker].ability != ABILITY_LINGERING_AROMA
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSuppressed)
            {
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                gBattleMons[gBattlerAttacker].ability = gBattleStruct->overwrittenAbilities[gBattlerAttacker] = gBattleMons[gBattlerTarget].ability;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MummyActivates;
                effect++;
                break;
            }
            break;
        case ABILITY_WANDERING_SPIRIT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSwapped)
            {
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                gBattleMons[gBattlerAttacker].ability = gBattleStruct->overwrittenAbilities[gBattlerAttacker] = gBattleMons[gBattlerTarget].ability;
                gBattleMons[gBattlerTarget].ability = gBattleStruct->overwrittenAbilities[gBattlerTarget] = gLastUsedAbility;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WanderingSpiritActivates;
                effect++;
                break;
            }
            break;
        case ABILITY_ANGER_POINT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gEsGolpeCritico
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                SET_STATCHANGER(ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6 - gBattleMons[battler].statStages[ESTADISTICA_ATAQUE], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
            break;
        case ABILITY_GOOEY:
        case ABILITY_TANGLING_HAIR:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && (CompareStat(gBattlerAttacker, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, COMPARACION_MAYOR) || GetBattlerAbility(gBattlerAttacker) == ABILITY_MIRROR_ARMOR)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, TRUE);
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_GooeyActivates;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_ROUGH_SKIN:
        case ABILITY_IRON_BARBS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / (B_ROUGH_SKIN_DMG >= GEN_4 ? 8 : 16);
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !IsBattlerAlive(gBattlerTarget)
             && IsBattlerAlive(gBattlerAttacker)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker))
            {
                u32 battler;
                if ((battler = QueCombatienteTieneHabilidad(ABILITY_DAMP)))
                {
                    gBattleScripting.battler = battler - 1;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_DampPreventsAftermath;
                }
                else
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                }
                effect++;
            }
            break;
        case ABILITY_INNARDS_OUT:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !IsBattlerAlive(gBattlerTarget)
             && IsBattlerAlive(gBattlerAttacker))
            {
                gBattleMoveDamage = gSpecialStatuses[gBattlerTarget].shellBellDmg;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AftermathDmg;
                effect++;
            }
            break;
        case ABILITY_PSICODELICO:
        {
            u32 ability = GetBattlerAbility(gBattlerAttacker);
            if ((!ES_COMBATIENTE_TIPO(gBattlerAttacker, TIPO_PLANTA))
            && ability != ABILITY_OVERCOAT
            && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES
            && (PorcentajeAleatorio(50)))
            {
                enum EstadosPsicodelico
                {
                    ESTADO_PSICODELICO_QUEMADO,
                    ESTADO_PSICODELICO_PARALIZADO,
                    ESTADO_PSICODELICO_CONGELADO,
                    ESTADO_PSICODELICO_ENVENENADO,
                    NUMERO_ESTADOS_PSICODELICO
                };
                u32 estado = ElementoAleatorio(NUMERO_ESTADOS_PSICODELICO);
                switch (estado)
                {
                    case ESTADO_PSICODELICO_QUEMADO:
                        HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBeBurned, MOVE_EFFECT_BURN);
                        break;
                    case ESTADO_PSICODELICO_PARALIZADO:
                        HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBeParalyzed, MOVE_EFFECT_PARALYSIS);
                        break;
                    case ESTADO_PSICODELICO_CONGELADO:
                        HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBeFrozen, MOVE_EFFECT_FROSTBITE);
                        break;
                    case ESTADO_PSICODELICO_ENVENENADO:
                        HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBePoisoned, MOVE_EFFECT_POISON);
                        break;                    
                }
            }
        }
            break;
        case ABILITY_POISON_POINT:
            if (PorcentajeAleatorio(50))
            {
                HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBePoisoned, MOVE_EFFECT_POISON)
            }
            break;
        case ABILITY_STATIC:
            if (PorcentajeAleatorio(50))
            {
                HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBeParalyzed, MOVE_EFFECT_PARALYSIS)
            }
            break;
        case ABILITY_SUENO_ELECTRICO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerAttacker)
             && CanBeParalyzed(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker))
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker)
             &&(gBattleMons[gBattlerTarget].status1 & STATUS1_SLEEP))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_PARALYSIS;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_FLAME_BODY:
            if (PorcentajeAleatorio(50))
            {
                HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(CanBeBurned, MOVE_EFFECT_BURN)
            }
            break;
        case ABILITY_CUTE_CHARM:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerTarget)
             && IsBattlerAlive(gBattlerTarget)
             && (PorcentajeAleatorio(50))
             && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
             && AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget)
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_OBLIVIOUS
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker)
             && !EstaHabilidadEnElLadoDeCombatiente(gBattlerAttacker, ABILITY_AROMA_VEIL))
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
            break;
        case ABILITY_NUEVE_COLAS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && (IsMoveMakingContact(move, gBattlerAttacker))
             && IsBattlerTurnDamaged(gBattlerTarget)
             && PorcentajeAleatorio(50))
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_CURSED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_NueveColas;
                effect++;
            }
            break;
        case ABILITY_PARASITO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerAttacker].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && (IsMoveMakingContact(move, gBattlerAttacker))
             && IsBattlerTurnDamaged(gBattlerTarget)
             && !(gStatuses3[gBattlerAttacker] & STATUS3_LEECHSEED)
             && !(ES_COMBATIENTE_TIPO(gBattlerAttacker, TIPO_PLANTA))
             && PorcentajeAleatorio(50))
            {
                gStatuses3[gBattlerAttacker] |= STATUS3_LEECHSEED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_Parasito;
                effect++;
            }
            break;
        case ABILITY_ILLUSION:
            if (gBattleStruct->illusion[gBattlerTarget].on && !gBattleStruct->illusion[gBattlerTarget].broken && IsBattlerTurnDamaged(gBattlerTarget))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_IllusionOff;
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerAlive(gBattlerAttacker)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerTarget))
            {
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CottonDownActivates;
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR)
             && (moveType == TIPO_FUEGO || moveType == TIPO_AGUA))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 6, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_SAND_SPIT:
            break;
        case ABILITY_PERISH_BODY:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(battler)
             && IsBattlerAlive(battler)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && (IsMoveMakingContact(move, gBattlerAttacker))
             && !(gStatuses3[gBattlerAttacker] & STATUS3_PERISH_SONG))
            {
                if (!(gStatuses3[battler] & STATUS3_PERISH_SONG))
                {
                    gStatuses3[battler] |= STATUS3_PERISH_SONG;
                    gDisableStructs[battler].perishSongTimer = 3;
                }
                gStatuses3[gBattlerAttacker] |= STATUS3_PERISH_SONG;
                gDisableStructs[gBattlerAttacker].perishSongTimer = 3;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PerishBodyActivates;
                effect++;
            }
            break;
        case ABILITY_SEED_SOWER:
            break;
        case ABILITY_THERMAL_EXCHANGE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && IsBattlerTurnDamaged(gBattlerTarget)
             && IsBattlerAlive(gBattlerTarget)
             && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR)
             && moveType == TIPO_FUEGO)
            {
                gEffectBattler = gBattlerTarget;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_ANGER_SHELL:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerTarget)
             && (gMultiHitCounter == 0 || gMultiHitCounter == 1) // Activates after all hits from a multi-hit move.
             && IsBattlerAlive(gBattlerTarget)
             && MenosDeMediaVida(gBattlerTarget)
             && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AngerShellActivates;
                effect++;
            }
            break;
        case ABILITY_WIND_POWER:
            if (!(gMovesInfo[gCurrentMove].windMove))
                break;
            // fall through
        case ABILITY_ELECTROMORPHOSIS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IsBattlerTurnDamaged(gBattlerTarget)
             && IsBattlerAlive(gBattlerTarget))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WindPowerActivates;
                effect++;
            }
            break;
        case ABILITY_TOXIC_DEBRIS:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && IsBattlerTurnDamaged(gBattlerTarget)
             && (gSideTimers[GetBattlerSide(gBattlerAttacker)].toxicSpikesAmount != 2))
            {
                SWAP(gBattlerAttacker, gBattlerTarget, i);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ToxicDebrisActivates;
                effect++;
            }
            break;
        case ABILITY_PUNZON:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && IS_MOVE_PHYSICAL(gCurrentMove)
             && IsBattlerTurnDamaged(gBattlerTarget)
             && (gSideTimers[gBattlerAttacker].spikesAmount != 2))
            {
                SWAP(gBattlerAttacker, gBattlerTarget, i);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_PunzonActivates;
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER: // Same as above, but for attacker
        switch (gLastUsedAbility)
        {
        case ABILITY_PESTE_BUBONICA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBePoisoned(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
             && (gMovesInfo[move].bitingMove)
             && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
             && IsMoveMakingContact(move, gBattlerAttacker)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_AGUJA_ENVENENADA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
            && gBattleMons[gBattlerTarget].hp != 0
            && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
            && CanBePoisoned(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
            && (gMovesInfo[move].movimientoPunzante)
            && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
            && IsMoveMakingContact(move, gBattlerAttacker)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_HECHICERO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeBurned(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
             && (gMovesInfo[move].type == TIPO_PSIQUICO)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_ALTO_VOLTAJE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeParalyzed(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
             && (gMovesInfo[move].type == TIPO_LUCHA)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_VOZ_DULCE:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeSlept(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
             && (gMovesInfo[move].soundMove)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_VOZ_HELADA:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanGetFrostbite(gBattlerTarget)
             && (gMovesInfo[move].soundMove)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_ULTRASONIDO:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
             && gBattleMons[gBattlerTarget].hp != 0
             && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
             && CanBeSlept(gBattlerTarget, GetBattlerAbility(gBattlerTarget))
             && (gMovesInfo[move].soundMove)
             && IsBattlerTurnDamaged(gBattlerTarget)
            && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_OTHER: // Abilities that activate on *another* battler's moveend: Dancer, Soul-Heart, Receiver, Symbiosis
        switch (GetBattlerAbility(battler))
        {
        case ABILITY_DANCER:
            if (IsBattlerAlive(battler)
             && (gMovesInfo[gCurrentMove].danceMove)
             && !gSpecialStatuses[battler].dancerUsedMove
             && gBattlerAttacker != battler)
            {
                // Set bit and save Dancer mon's original target
                gSpecialStatuses[battler].dancerUsedMove = TRUE;
                gSpecialStatuses[battler].dancerOriginalTarget = *(gBattleStruct->moveTarget + battler) | 0x4;
                gBattleStruct->atkCancellerTracker = 0;
                gBattlerAttacker = gBattlerAbility = battler;
                gCalledMove = gCurrentMove;

                // Set the target to the original target of the mon that first used a Dance move
                gBattlerTarget = gBattleScripting.savedBattler & 0x3;

                // Edge case for dance moves that hit multiply targets
                gHitMarker &= ~HITMARKER_NO_ATTACKSTRING;
                SetTypeBeforeUsingMove(gCalledMove, battler);

                // Make sure that the target isn't an ally - if it is, target the original user
                if (GetBattlerSide(gBattlerTarget) == GetBattlerSide(gBattlerAttacker))
                    gBattlerTarget = (gBattleScripting.savedBattler & 0xF0) >> 4;
                gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
                BattleScriptExecute(BattleScript_DancerActivates);
                effect++;
            }
            break;
        }
        break;
    case ABILITYEFFECT_OPPORTUNIST:
        /* Similar to ABILITYEFFECT_IMMUNITY in that it loops through all battlers.
         * Is called after ABILITYEFFECT_ON_SWITCHIN to copy any boosts
         * from switch in abilities e.g. intrepid sword, as
         */
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            switch (GetBattlerAbility(battler))
            {
            case ABILITY_OPPORTUNIST:
            case ABILITY_REY_DEL_MAR:
                if (gProtectStructs[battler].activateOpportunist == 2)
                {
                    gBattleScripting.animArg1 = 0;
                    gBattleScripting.battler = battler;
                    gProtectStructs[battler].activateOpportunist--;
                    ChooseStatBoostAnimation(battler);
                    BattleScriptPushCursorAndCallback(BattleScript_OpportunistCopyStatChange);
                    effect = 1;
                }
                break;
            }
        }
        break;
    case ABILITYEFFECT_IMMUNITY:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            switch (GetBattlerAbility(battler))
            {
            case ABILITY_IMMUNITY:
                if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
                {
                    StringCopy(gBattleTextBuff1, gText_Poison);
                    effect = 1;
                }
                break;
            case ABILITY_OWN_TEMPO:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    StringCopy(gBattleTextBuff1, gText_Confusion);
                    effect = 2;
                }
                break;
            case ABILITY_LIMBER:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    StringCopy(gBattleTextBuff1, gText_Paralysis);
                    effect = 1;
                }
                break;
            case ABILITY_INSOMNIA:
            case ABILITY_VITAL_SPIRIT:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    StringCopy(gBattleTextBuff1, gText_Sleep);
                    effect = 1;
                }
                break;
            case ABILITY_WATER_VEIL:
            case ABILITY_WATER_BUBBLE:
            case ABILITY_TIERRA_HUMEDA:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    StringCopy(gBattleTextBuff1, gText_Burn);
                    effect = 1;
                }
                break;
            case ABILITY_MAGMA_ARMOR:
                if (gBattleMons[battler].status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE))
                {
                    StringCopy(gBattleTextBuff1, gText_Ice);
                    effect = 1;
                }
                break;
            case ABILITY_OBLIVIOUS:
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                    effect = 3;
                else if (gDisableStructs[battler].tauntTimer != 0)
                    effect = 4;
                break;
            }

            if (effect != 0)
            {
                switch (effect)
                {
                case 1: // status cleared
                    gBattleMons[battler].status1 = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 2: // get rid of confusion
                    RemoveConfusionStatus(battler);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    break;
                case 3: // get rid of infatuation
                    gBattleMons[battler].status2 &= ~STATUS2_INFATUATION;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerGotOverItsInfatuation;
                    break;
                case 4: // get rid of taunt
                    gDisableStructs[battler].tauntTimer = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BattlerShookOffTaunt;
                    break;
                }

                gBattleScripting.battler = gBattlerAbility = battler;
                BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                MarcaCombatienteOcupado(battler);
                return effect;
            }
        }
        break;
    case ABILITYEFFECT_SYNCHRONIZE:
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~HITMARKER_SYNCHRONISE_EFFECT;

            if (!(gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (B_SYNCHRONIZE_TOXIC < GEN_5 && gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect + MOVE_EFFECT_AFFECTS_USER;
                gBattleScripting.battler = gBattlerAbility = gBattlerTarget;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_ATK_SYNCHRONIZE:
        if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
        {
            gHitMarker &= ~HITMARKER_SYNCHRONISE_EFFECT;

            if (!(gBattleMons[gBattlerTarget].status1 & STATUS1_ANY))
            {
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gBattleStruct->synchronizeMoveEffect;
                gBattleScripting.battler = gBattlerAbility = gBattlerAttacker;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
        }
        break;
    case ABILITYEFFECT_NEUTRALIZINGGAS:
        // Prints message only. separate from ABILITYEFFECT_ON_SWITCHIN bc activates before entry hazards
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleMons[i].ability == ABILITY_NEUTRALIZING_GAS && !(gBattleResources->flags->flags[i] & RESOURCE_FLAG_NEUTRALIZING_GAS))
            {
                gBattleResources->flags->flags[i] |= RESOURCE_FLAG_NEUTRALIZING_GAS;
                gBattlerAbility = i;
                gMensajeBatalla = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }

            if (effect != 0)
                break;
        }
        break;
    case ABILITYEFFECT_FIELD_SPORT:
        switch (gLastUsedAbility)
        {
        case ABILITYEFFECT_MUD_SPORT:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gStatuses4[i] & STATUS4_MUD_SPORT)
                    effect = i + 1;
            }
            break;
        case ABILITYEFFECT_WATER_SPORT:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gStatuses4[i] & STATUS4_WATER_SPORT)
                    effect = i + 1;
            }
            break;
        default:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        }
        break;
    case ABILITYEFFECT_ON_WEATHER: // For ability effects that activate when the battle weather changes.
        gLastUsedAbility = GetBattlerAbility(battler);
        switch (gLastUsedAbility)
        {
        case ABILITY_FORECAST:
        case ABILITY_FLOWER_GIFT:
            if ((IsBattlerWeatherAffected(battler, gBattleWeather)
             || gBattleWeather == B_WEATHER_NONE
             || !WEATHER_HAS_EFFECT) // Air Lock active
             && TryBattleFormChange(battler, FORM_CHANGE_BATTLE_WEATHER))
            {
                gBattleScripting.battler = battler;
                BattleScriptPushCursorAndCallback(BattleScript_BattlerFormChangeWithStringEnd3);
                effect++;
            }
            break;
        }
        break;
    }

    if (effect && gLastUsedAbility != 0xFFFF)
        RecuerdaHabilidadCombate(battler, gLastUsedAbility);
    if (effect && caseID <= ABILITYEFFECT_MOVE_END)
        gBattlerAbility = battler;

    return effect;
}

bool32 IsNeutralizingGasOnField(void)
{
    u32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerAlive(i) && gBattleMons[i].ability == ABILITY_NEUTRALIZING_GAS && !(gStatuses3[i] & STATUS3_GASTRO_ACID))
            return TRUE;
    }

    return FALSE;
}

bool32 IsMoldBreakerTypeAbility(u32 battler, u32 ability)
{
    if (gStatuses3[battler] & STATUS3_GASTRO_ACID)
        return FALSE;

    return (ability == ABILITY_MOLD_BREAKER);
}

static inline bool32 CanBreakThroughAbility(u32 battlerAtk, u32 battlerDef, u32 ability)
{
    return ((IsMoldBreakerTypeAbility(battlerAtk, ability) || gMovesInfo[gCurrentMove].ignoresTargetAbility)
         && battlerDef != battlerAtk
         && gAbilitiesInfo[gBattleMons[battlerDef].ability].breakable
         && gBattlerByTurnOrder[gCurrentTurnActionNumber] == battlerAtk
         && gActionsByTurnOrder[gCurrentTurnActionNumber] == B_ACTION_USE_MOVE
         && gCurrentTurnActionNumber < gBattlersCount);
}

u32 GetBattlerAbility(u32 combatiente)
{
    bool32 noAbilityShield = GetBattlerHoldEffectIgnoreAbility(combatiente, TRUE) != HOLD_EFFECT_ABILITY_SHIELD;
    bool32 abilityCantBeSuppressed = gAbilitiesInfo[gBattleMons[combatiente].ability].cantBeSuppressed;

    if (abilityCantBeSuppressed)
    {
        // Edge case: pokemon under the effect of gastro acid transforms into a pokemon with Comatose (Todo: verify how other unsuppressable abilities behave)
        if (gBattleMons[combatiente].status2 & STATUS2_TRANSFORMED
            && gStatuses3[combatiente] & STATUS3_GASTRO_ACID
            && gBattleMons[combatiente].ability == ABILITY_COMATOSE)
                return ABILITY_NONE;

        if (noAbilityShield && CanBreakThroughAbility(gBattlerAttacker, combatiente, gBattleMons[gBattlerAttacker].ability))
            return ABILITY_NONE;

        return gBattleMons[combatiente].ability;
    }

    if (gStatuses3[combatiente] & STATUS3_GASTRO_ACID)
        return ABILITY_NONE;

    if (IsNeutralizingGasOnField()
     && gBattleMons[combatiente].ability != ABILITY_NEUTRALIZING_GAS
     && noAbilityShield)
        return ABILITY_NONE;

    if (noAbilityShield && CanBreakThroughAbility(gBattlerAttacker, combatiente, gBattleMons[gBattlerAttacker].ability))
        return ABILITY_NONE;

    return gBattleMons[combatiente].ability;
}

u32 QueCombatienteTieneHabilidad(u32 habilidad)
{
    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        if (IsBattlerAlive(combatiente) && GetBattlerAbility(combatiente) == habilidad)
            return combatiente;
    }
    return 0xFF;
}

bool32 EstaHabilidadEnElLadoDeCombatiente(u32 combatiente, u32 habilidad)
{
    if (IsBattlerAlive(combatiente) && GetBattlerAbility(combatiente) == habilidad)
        return TRUE;
    else if (IsBattlerAlive(ALIADO(combatiente)) && GetBattlerAbility(ALIADO(combatiente)) == habilidad)
        return TRUE;
    else
        return FALSE;
}

bool32 EstaHabilidadEnCampoContrario(u32 combatiente, u32 habilidad)
{
    return EstaHabilidadEnElLadoDeCombatiente(OPONENTE(combatiente), habilidad);
}

bool32 EstaHabilidadEnCampo(u32 habilidad)
{
    u32 combatiente;

    for (combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        if (IsBattlerAlive(combatiente) && GetBattlerAbility(combatiente) == habilidad)
            return TRUE;
    }

    return FALSE;
}

bool32 HabilidadImpideCambiar(u32 combatiente)
{
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_SHADOW_TAG) && IsBattlerGrounded(combatiente))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_ARENA_TRAP) && IsBattlerGrounded(combatiente))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_IMAN) && ES_COMBATIENTE_TIPO(combatiente, TIPO_ACERO))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_MATAMOSCAS) && ES_COMBATIENTE_TIPO(combatiente, TIPO_BICHO))
        return TRUE;

    return FALSE;
}

bool32 PuedeCambiar(u32 combatiente)
{
    if (GetBattlerHoldEffect(combatiente, TRUE) == HOLD_EFFECT_SHED_SHELL)
        return TRUE;
    if (ES_COMBATIENTE_TIPO(combatiente, TIPO_FANTASMA))
        return TRUE;
    if (GetBattlerAbility(combatiente) == ABILITY_HUIDIZO)
        return TRUE;
    if (gBattleMons[combatiente].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        return FALSE;
    if (gStatuses3[combatiente] & (STATUS3_ROOTED | STATUS3_SKY_DROPPED))
        return FALSE;
    if (HabilidadImpideCambiar(combatiente))
        return FALSE;

    return TRUE;
}

void BattleScriptExecute(const u8 *BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands_PopCallbacksStack;
    gCurrentActionFuncId = 0;
}

void BattleScriptPushCursorAndCallback(const u8 *BS_ptr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands;
}

enum
{
    ITEM_NO_EFFECT,
    ITEM_STATUS_CHANGE,
    ITEM_EFFECT_OTHER,
    ITEM_PP_CHANGE,
    ITEM_HP_CHANGE,
    ITEM_STATS_CHANGE,
};

bool32 CanBeSlept(u32 battler, u32 ability)
{
    if (ability == ABILITY_INSOMNIA
     || ability == ABILITY_VITAL_SPIRIT
     || ability == ABILITY_COMATOSE
     || ability == ABILITY_PURIFYING_SALT
     || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battler].status1 & STATUS1_ANY
     || EstaHabilidadEnElLadoDeCombatiente(battler, ABILITY_SWEET_VEIL)
     || IsAbilityStatusProtected(battler)
        return FALSE;
    return TRUE;
}

bool32 CanBePoisoned(u32 battler, u32 ability)
{
    if (!(CanPoisonType(battler))
     || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battler].status1 & STATUS1_ANY
     || ability == ABILITY_IMMUNITY
     || ability == ABILITY_COMATOSE
     || ability == ABILITY_PURIFYING_SALT
     || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 CanBeBurned(u32 battler, u32 ability)
{
    if (ES_COMBATIENTE_TIPO(battler, TIPO_FUEGO)
     || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battler].status1 & STATUS1_ANY
     || ability == ABILITY_WATER_VEIL
     || ability == ABILITY_WATER_BUBBLE
     || ability == ABILITY_COMATOSE
     || ability == ABILITY_THERMAL_EXCHANGE
     || ability == ABILITY_PURIFYING_SALT
     || ability == ABILITY_TIERRA_HUMEDA
     || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 CanBeParalyzed(u32 battler, u32 ability)
{
    if ((B_PARALYZE_ELECTRIC >= GEN_6 && ES_COMBATIENTE_TIPO(battler, TIPO_ELECTRICO))
      || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
      || ability == ABILITY_LIMBER
      || ability == ABILITY_COMATOSE
      || ability == ABILITY_PURIFYING_SALT
      || gBattleMons[battler].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 CanBeFrozen(u32 battler, u32 ability)
{
    if (ES_COMBATIENTE_TIPO(battler, TIPO_HIELO)
     || IsBattlerWeatherAffected(battler, B_WEATHER_SUN)
     || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
     || ability == ABILITY_MAGMA_ARMOR
     || ability == ABILITY_COMATOSE
     || ability == ABILITY_PURIFYING_SALT
     || gBattleMons[battler].status1 & STATUS1_ANY
     || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 CanGetFrostbite(u32 battler)
{
    u16 ability = GetBattlerAbility(battler);
    if (ES_COMBATIENTE_TIPO(battler, TIPO_HIELO)
      || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
      || ability == ABILITY_MAGMA_ARMOR
      || ability == ABILITY_COMATOSE
      || ability == ABILITY_PURIFYING_SALT
      || gBattleMons[battler].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 CanBeConfused(u32 battler)
{
    if (GetBattlerAbility(battler) == ABILITY_OWN_TEMPO
     || gBattleMons[battler].status2 & STATUS2_CONFUSION)
        return FALSE;
    return TRUE;
}

// second argument is 1/X of current hp compared to max hp
bool32 HasEnoughHpToEatBerry(u32 battler, u32 hpFraction, u32 itemId)
{
    bool32 isBerry = (ItemId_GetPocket(itemId) == POCKET_BERRIES);

    if (!IsBattlerAlive(battler))
        return FALSE;
    if (gBattleScripting.overrideBerryRequirements)
        return TRUE;
    // Unnerve prevents consumption of opponents' berries.
    if (isBerry && EstaHabilidadEnCampoContrario(battler, ABILITY_UNNERVE))
        return FALSE;
    if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / hpFraction)
        return TRUE;

    if (hpFraction <= 4 && GetBattlerAbility(battler) == ABILITY_GLUTTONY && isBerry
         && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2)
    {
        RecuerdaHabilidadCombate(battler, ABILITY_GLUTTONY);
        return TRUE;
    }

    return FALSE;
}

static u8 HealConfuseBerry(u32 battler, u32 itemId, u32 flavorId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battler, (B_CONFUSE_BERRIES_HEAL >= GEN_7 ? 4 : 2), itemId)
     && (B_HEAL_BLOCKING < GEN_5 || !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)))
    {
        PREPARE_FLAVOR_BUFFER(gBattleTextBuff1, flavorId);

        gBattleMoveDamage = CuantosPSMaximos(battler) / GetBattlerItemHoldEffectParam(battler, itemId);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (GetBattlerAbility(battler) == ABILITY_RIPEN)
        {
            gBattleMoveDamage *= 2;
            gBattlerAbility = battler;
        }
        gBattleScripting.battler = battler;
        if (end2)
        {
            if (GetFlavorRelationByPersonality(gBattleMons[battler].personality, flavorId) < 0)
                BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
            else
                BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            if (GetFlavorRelationByPersonality(gBattleMons[battler].personality, flavorId) < 0)
                gBattlescriptCurrInstr = BattleScript_BerryConfuseHealRet;
            else
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }

        return ITEM_HP_CHANGE;
    }
    return 0;
}

static u8 StatRaiseBerry(u32 battler, u32 itemId, u32 statId, bool32 end2)
{
    if (CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR) && HasEnoughHpToEatBerry(battler, GetBattlerItemHoldEffectParam(battler, itemId), itemId))
    {
        BufferStatChange(battler, statId, STRINGID_STATROSE);
        gEffectBattler = battler;
        if (GetBattlerAbility(battler) == ABILITY_RIPEN)
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + statId;
        gBattleScripting.animArg2 = 0;

        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 RandomStatRaiseBerry(u32 battler, u32 itemId, bool32 end2)
{
    s32 i;
    u16 stringId;

    for (i = 0; i < NUMERO_ESTADISTICAS - 1; i++)
    {
        if (CompareStat(battler, ESTADISTICA_ATAQUE + i, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            break;
    }
    if (i != NUMERO_ESTADISTICAS - 1 && HasEnoughHpToEatBerry(battler, GetBattlerItemHoldEffectParam(battler, itemId), itemId))
    {
        u16 battlerAbility = GetBattlerAbility(battler);
        do
        {
            i = Random() % (NUMERO_ESTADISTICAS - 1);
        } while (!CompareStat(battler, ESTADISTICA_ATAQUE + i, ESTADISTICA_MAS_6, COMPARACION_MENOR));

        PREPARE_STAT_BUFFER(gBattleTextBuff1, i + 1);
        stringId = (battlerAbility == ABILITY_CONTRARY) ? STRINGID_STATFELL : STRINGID_STATROSE;
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        gBattleTextBuff2[1] = B_BUFF_STRING;
        gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
        gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
        gBattleTextBuff2[4] = B_BUFF_STRING;
        gBattleTextBuff2[5] = stringId;
        gBattleTextBuff2[6] = stringId >> 8;
        gBattleTextBuff2[7] = EOS;
        gEffectBattler = battler;
        if (battlerAbility == ABILITY_RIPEN)
            SET_STATCHANGER(i + 1, 4, FALSE);
        else
            SET_STATCHANGER(i + 1, 2, FALSE);

        gBattleScripting.animArg1 = STAT_ANIM_PLUS2 + i + 1;
        gBattleScripting.animArg2 = 0;
        if (end2)
        {
            BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }

        return ITEM_STATS_CHANGE;
    }
    return 0;
}

static u8 TrySetMicleBerry(u32 battler, u32 itemId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battler, 4, itemId))
    {
        gBattleStruct->usedMicleBerry |= 1u << battler;
        if (end2)
        {
            BattleScriptExecute(BattleScript_MicleBerryActivateEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MicleBerryActivateRet;
        }
        return ITEM_EFFECT_OTHER;
    }
    return 0;
}

static u8 DamagedStatBoostBerryEffect(u32 battler, u8 statId, u8 category)
{
    if (IsBattlerAlive(battler)
     && CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR)
     && (gBattleScripting.overrideBerryRequirements
         || (!DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
             && GetBattleMoveCategory(gCurrentMove) == category
             && battler != gBattlerAttacker
             && IsBattlerTurnDamaged(battler)))
        )
    {
        BufferStatChange(battler, statId, STRINGID_STATROSE);

        gEffectBattler = battler;
        if (GetBattlerAbility(battler) == ABILITY_RIPEN)
            SET_STATCHANGER(statId, 2, FALSE);
        else
            SET_STATCHANGER(statId, 1, FALSE);

        gBattleScripting.battler = battler;
        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + statId;
        gBattleScripting.animArg2 = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        return ITEM_STATS_CHANGE;
    }
    return 0;
}

u8 TryHandleSeed(u32 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute)
{
    return 0;
}

static u32 ItemRestorePp(u32 battler, u32 itemId, bool32 execute)
{
    struct Pokemon *party = GetBattlerParty(battler);
    struct Pokemon *mon = &party[gBattlerPartyIndexes[battler]];
    u32 i, changedPP = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = GetMonData(mon, MON_DATA_MOVE1 + i);
        u32 currentPP = GetMonData(mon, MON_DATA_PP1 + i);
        u32 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        u32 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
        if (move && (currentPP == 0 || (gBattleScripting.overrideBerryRequirements && currentPP != maxPP)))
        {
            u32 ppRestored = GetBattlerItemHoldEffectParam(battler, itemId);

            if (GetBattlerAbility(battler) == ABILITY_RIPEN)
            {
                ppRestored *= 2;
                gBattlerAbility = battler;
            }
            if (currentPP + ppRestored > maxPP)
                changedPP = maxPP;
            else
                changedPP = currentPP + ppRestored;

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);

            if (execute)
            {
                BattleScriptExecute(BattleScript_BerryPPHealEnd2);
            }
            else
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_BerryPPHealRet;
            }
            BtlController_EmitSetMonData(battler, BUFFER_A, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
            MarcaCombatienteOcupado(battler);
            if (MOVE_IS_PERMANENT(battler, i))
                gBattleMons[battler].pp[i] = changedPP;
            return ITEM_PP_CHANGE;
        }
    }
    return 0;
}

static u8 ItemHealHp(u32 battler, u32 itemId, bool32 end2, bool32 percentHeal)
{
    if (!(gBattleScripting.overrideBerryRequirements && gBattleMons[battler].hp == gBattleMons[battler].maxHP)
        && (B_HEAL_BLOCKING < GEN_5 || !(gStatuses3[battler] & STATUS3_HEAL_BLOCK))
        && HasEnoughHpToEatBerry(battler, 2, itemId))
    {
        if (percentHeal)
            gBattleMoveDamage = (CuantosPSMaximos(battler) * GetBattlerItemHoldEffectParam(battler, itemId) / 100) * -1;
        else
            gBattleMoveDamage = GetBattlerItemHoldEffectParam(battler, itemId) * -1;

        // check ripen
        if (ItemId_GetPocket(itemId) == POCKET_BERRIES && GetBattlerAbility(battler) == ABILITY_RIPEN)
            gBattleMoveDamage *= 2;

        gBattlerAbility = battler;    // in SWSH, berry juice shows ability pop up but has no effect. This is mimicked here
        if (end2)
        {
            BattleScriptExecute(BattleScript_ItemHealHP_RemoveItemEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ItemHealHP_RemoveItemRet;
        }

        return ITEM_HP_CHANGE;
    }
    return 0;
}

static bool32 UnnerveOn(u32 battler, u32 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES && EstaHabilidadEnCampoContrario(battler, ABILITY_UNNERVE))
        return TRUE;
    return FALSE;
}

static bool32 GetMentalHerbEffect(u32 battler)
{
    bool32 ret = FALSE;

    // Check infatuation
    if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
    {
        gBattleMons[battler].status2 &= ~STATUS2_INFATUATION;
        gMensajeBatalla = B_MSG_MENTALHERBCURE_INFATUATION;  // STRINGID_TARGETGOTOVERINFATUATION
        StringCopy(gBattleTextBuff1, gText_Love);
        ret = TRUE;
    }
    if (B_MENTAL_HERB >= GEN_5)
    {
        // Check taunt
        if (gDisableStructs[battler].tauntTimer != 0)
        {
            gDisableStructs[battler].tauntTimer = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
            ret = TRUE;
        }
        // Check encore
        if (gDisableStructs[battler].encoreTimer != 0)
        {
            gDisableStructs[battler].encoredMove = 0;
            gDisableStructs[battler].encoreTimer = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_ENCORE;   // STRINGID_PKMNENCOREENDED
            ret = TRUE;
        }
        // Check torment
        if (gBattleMons[battler].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battler].status2 &= ~STATUS2_TORMENT;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_TORMENT;
            ret = TRUE;
        }
        // Check heal block
        if (gStatuses3[battler] & STATUS3_HEAL_BLOCK)
        {
            gStatuses3[battler] &= ~STATUS3_HEAL_BLOCK;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_HEALBLOCK;
            ret = TRUE;
        }
        // Check disable
        if (gDisableStructs[battler].disableTimer != 0)
        {
            gDisableStructs[battler].disableTimer = 0;
            gDisableStructs[battler].disabledMove = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_DISABLE;
            ret = TRUE;
        }
    }
    return ret;
}

static u8 TryConsumeMirrorHerb(u32 battler, bool32 execute)
{
    u8 effect = 0;

    if (gProtectStructs[battler].eatMirrorHerb)
    {

        gLastUsedItem = gBattleMons[battler].item;
        gBattleScripting.battler = battler;
        gProtectStructs[battler].eatMirrorHerb = 0;
        ChooseStatBoostAnimation(battler);
        if (execute)
        {
            BattleScriptExecute(BattleScript_MirrorHerbCopyStatChangeEnd2);
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MirrorHerbCopyStatChange;
        }
        effect = ITEM_STATS_CHANGE;
    }
    return effect;
}

static u32 RestoreWhiteHerbStats(u32 battler)
{
    u32 i, effect = 0;

    for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
    {
        if (gBattleMons[battler].statStages[i] < ESTADISTICA_NEUTRA)
        {
            gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA;
            effect = ITEM_STATS_CHANGE;
        }
    }
    if (effect != 0)
    {
        gBattleScripting.battler = battler;
        gPotentialItemEffectBattler = battler;
    }
    return effect;
}

static u8 ItemEffectMoveEnd(u32 battler, u16 holdEffect)
{
    u8 effect = 0;

    switch (holdEffect)
    {
    case HOLD_EFFECT_MICLE_BERRY:
        if (B_HP_BERRIES >= GEN_4)
            effect = TrySetMicleBerry(battler, gLastUsedItem, FALSE);
        break;
    case HOLD_EFFECT_RESTORE_HP:
        if (B_HP_BERRIES >= GEN_4)
            effect = ItemHealHp(battler, gLastUsedItem, FALSE, FALSE);
        break;
    case HOLD_EFFECT_RESTORE_PCT_HP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = ItemHealHp(battler, gLastUsedItem, FALSE, TRUE);
        break;
    case HOLD_EFFECT_RESTORE_PP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = ItemRestorePp(battler, gLastUsedItem, FALSE);
        break;
    case HOLD_EFFECT_CONFUSE_SPICY:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SPICY, FALSE);
        break;
    case HOLD_EFFECT_CONFUSE_DRY:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_DRY, FALSE);
        break;
    case HOLD_EFFECT_CONFUSE_SWEET:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SWEET, FALSE);
        break;
    case HOLD_EFFECT_CONFUSE_BITTER:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_BITTER, FALSE);
        break;
    case HOLD_EFFECT_CONFUSE_SOUR:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SOUR, FALSE);
        break;
    case HOLD_EFFECT_ATTACK_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE, FALSE);
        break;
    case HOLD_EFFECT_DEFENSE_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA, FALSE);
        break;
    case HOLD_EFFECT_SPEED_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_VELOCIDAD, FALSE);
        break;
    case HOLD_EFFECT_SP_ATTACK_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE_ESPECIAL, FALSE);
        break;
    case HOLD_EFFECT_SP_DEFENSE_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA_ESPECIAL, FALSE);
        break;
    case HOLD_EFFECT_ENIGMA_BERRY:
        break;
    case HOLD_EFFECT_KEE_BERRY:  // consume and boost defense if used physical move
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA, CATEGORIA_FISICA);
        break;
    case HOLD_EFFECT_MARANGA_BERRY:  // consume and boost sp. defense if used special move
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA_ESPECIAL, CATEGORIA_ESPECIAL);
        break;
    case HOLD_EFFECT_RANDOM_STAT_UP:
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = RandomStatRaiseBerry(battler, gLastUsedItem, FALSE);
        break;
    case HOLD_EFFECT_CURE_PAR:
        if (gBattleMons[battler].status1 & STATUS1_PARALYSIS && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureParRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CURE_PSN:
        if (gBattleMons[battler].status1 & STATUS1_PSN_ANY && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCurePsnRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CURE_BRN:
        if (gBattleMons[battler].status1 & STATUS1_BURN && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_BURN;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureBrnRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CURE_FRZ:
        if (gBattleMons[battler].status1 & STATUS1_FREEZE && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_FREEZE;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
            effect = ITEM_STATUS_CHANGE;
        }
        if (gBattleMons[battler].status1 & STATUS1_FROSTBITE && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_FROSTBITE;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureFrbRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CURE_SLP:
        if (gBattleMons[battler].status1 & STATUS1_SLEEP && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
            gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureSlpRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CURE_CONFUSION:
        if (gBattleMons[battler].status2 & STATUS2_CONFUSION && !UnnerveOn(battler, gLastUsedItem))
        {
            RemoveConfusionStatus(battler);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureConfusionRet;
            effect = ITEM_EFFECT_OTHER;
        }
        break;
    case HOLD_EFFECT_MENTAL_HERB:
        if (GetMentalHerbEffect(battler))
        {
            gBattleScripting.savedBattler = gBattlerAttacker;
            gBattlerAttacker = battler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MentalHerbCureRet;
            effect = ITEM_EFFECT_OTHER;
        }
        break;
    case HOLD_EFFECT_CURE_STATUS:
        if ((gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION) && !UnnerveOn(battler, gLastUsedItem))
        {
            if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                StringCopy(gBattleTextBuff1, gText_Poison);

            if (gBattleMons[battler].status1 & STATUS1_SLEEP)
            {
                gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                StringCopy(gBattleTextBuff1, gText_Sleep);
            }

            if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                StringCopy(gBattleTextBuff1, gText_Paralysis);

            if (gBattleMons[battler].status1 & STATUS1_BURN)
                StringCopy(gBattleTextBuff1, gText_Burn);

            if (gBattleMons[battler].status1 & STATUS1_FREEZE || gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                StringCopy(gBattleTextBuff1, gText_Ice);

            if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                StringCopy(gBattleTextBuff1, gText_Confusion);

            gBattleMons[battler].status1 = 0;
            RemoveConfusionStatus(battler);
            BattleScriptPushCursor();
            gMensajeBatalla = B_MSG_CURED_PROBLEM;
            gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
            effect = ITEM_STATUS_CHANGE;
        }
        break;
    case HOLD_EFFECT_CRITICAL_UP: // lansat berry
        if (B_BERRIES_INSTANT >= GEN_4
            && !(gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY_ANY)
            && HasEnoughHpToEatBerry(battler, GetBattlerItemHoldEffectParam(battler, gLastUsedItem), gLastUsedItem))
        {
            gBattleMons[battler].status2 |= STATUS2_FOCUS_ENERGY;
            gBattleScripting.battler = battler;
            gPotentialItemEffectBattler = battler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryFocusEnergyRet;
            effect = ITEM_EFFECT_OTHER;
        }
        break;
    case HOLD_EFFECT_BERSERK_GENE:
        BufferStatChange(battler, ESTADISTICA_ATAQUE, STRINGID_STATROSE);
        gEffectBattler = battler;
        if (CanBeInfinitelyConfused(gEffectBattler))
        {
            gStatuses4[gEffectBattler] |= STATUS4_INFINITE_CONFUSION;
        }
        SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);

        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + ESTADISTICA_ATAQUE;
        gBattleScripting.animArg2 = 0;

        BattleScriptPushCursorAndCallback(BattleScript_BerserkGeneRet);
        effect = ITEM_STATS_CHANGE;
        break;
    case HOLD_EFFECT_MIRROR_HERB:
        effect = TryConsumeMirrorHerb(battler, FALSE);
        break;
    }

    return effect;
}

u8 ItemBattleEffects(u8 caseID, u32 battler, bool32 moveTurn)
{
    u32 i = 0, moveType;
    u8 effect = ITEM_NO_EFFECT;
    u32 battlerHoldEffect = 0, atkHoldEffect;
    u8 atkHoldEffectParam;
    u16 atkItem;

    if (caseID != ITEMEFFECT_USE_LAST_ITEM)
    {
        gLastUsedItem = gBattleMons[battler].item;
        battlerHoldEffect = GetBattlerHoldEffect(battler, TRUE);
    }

    atkItem = gBattleMons[gBattlerAttacker].item;
    atkHoldEffect = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    atkHoldEffectParam = GetBattlerHoldEffectParam(gBattlerAttacker);

    switch (caseID)
    {
    case ITEMEFFECT_ON_SWITCH_IN:
        if (!gSpecialStatuses[battler].switchInItemDone)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_DOUBLE_PRIZE:
                if (GetBattlerSide(battler) == LADO_JUGADOR && !gBattleStruct->moneyMultiplierItem)
                {
                    gBattleStruct->moneyMultiplier *= 2;
                    gBattleStruct->moneyMultiplierItem = 1;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                effect = RestoreWhiteHerbStats(battler);
                if (effect != 0)
                {
                    gBattlerAttacker = battler;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_VELOCIDAD, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE_ESPECIAL, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA_ESPECIAL, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (B_BERRIES_INSTANT >= GEN_4
                    && !(gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY_ANY)
                    && HasEnoughHpToEatBerry(battler, GetBattlerItemHoldEffectParam(battler, gLastUsedItem), gLastUsedItem))
                {
                    gBattleMons[battler].status2 |= STATUS2_FOCUS_ENERGY;
                    gBattleScripting.battler = battler;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battler, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (B_BERRIES_INSTANT >= GEN_4
                    && gBattleMons[battler].status1 & STATUS1_PARALYSIS
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_BURN)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_BURN;
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_FREEZE)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FREEZE;
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FROSTBITE;
                    BattleScriptExecute(BattleScript_BerryCureFrbEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (B_BERRIES_INSTANT >= GEN_4
                    && (gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION)
                    && !UnnerveOn(battler, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gText_Poison);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                        StringCopy(gBattleTextBuff1, gText_Sleep);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gText_Paralysis);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gText_Burn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE || gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                    {
                        StringCopy(gBattleTextBuff1, gText_Ice);
                        i++;
                    }
                    if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gText_Confusion);
                        i++;
                    }
                    if (i <= 1)
                        gMensajeBatalla = B_MSG_CURED_PROBLEM;
                    else
                        gMensajeBatalla = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battler].status1 = 0;
                    RemoveConfusionStatus(battler);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battler, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = ItemHealHp(battler, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_AIR_BALLOON:
                effect = ITEM_EFFECT_OTHER;
                gBattleScripting.battler = battler;
                BattleScriptPushCursorAndCallback(BattleScript_AirBaloonMsgIn);
                RecordItemEffectBattle(battler, HOLD_EFFECT_AIR_BALLOON);
                break;
            case HOLD_EFFECT_ROOM_SERVICE:
                if (TryRoomService(battler))
                {
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SEEDS:
                break;
            case HOLD_EFFECT_EJECT_PACK:
                if (gProtectStructs[battler].statFell
                 && gProtectStructs[battler].disableEjectPack == 0
                 && CountUsablePartyMons(battler) > 0
                 && !(gCurrentMove == MOVE_PARTING_SHOT && CanBattlerSwitch(gBattlerAttacker))) // Does not activate if attacker used Parting Shot and can switch out
                {
                    gProtectStructs[battler].statFell = FALSE;
                    gBattleScripting.battler = battler;
                    effect = ITEM_STATS_CHANGE;
                    if (moveTurn)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_EjectPackActivate_Ret;
                    }
                    else
                    {
                        BattleScriptExecute(BattleScript_EjectPackActivate_End2);
                    }
                }
                break;
            case HOLD_EFFECT_BERSERK_GENE:
                BufferStatChange(battler, ESTADISTICA_ATAQUE, STRINGID_STATROSE);
                gEffectBattler = battler;
                if (CanBeInfinitelyConfused(gEffectBattler))
                {
                    gStatuses4[gEffectBattler] |= STATUS4_INFINITE_CONFUSION;
                }
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);

                gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + ESTADISTICA_ATAQUE;
                gBattleScripting.animArg2 = 0;

                BattleScriptPushCursorAndCallback(BattleScript_BerserkGeneRet);
                effect = ITEM_STATS_CHANGE;
                break;
            case HOLD_EFFECT_MIRROR_HERB:
                effect = TryConsumeMirrorHerb(battler, TRUE);
                break;
            case HOLD_EFFECT_BOOSTER_ENERGY:
                break;
            }
            if (effect != 0)
            {
                gSpecialStatuses[battler].switchInItemDone = TRUE;
                gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battler;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarcaCombatienteOcupado(battler);
                    break;
                }
            }
        }
        break;
    case ITEMEFFECT_NORMAL:
        if (gBattleMons[battler].hp)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battler, gLastUsedItem, TRUE, FALSE);
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (!moveTurn)
                    effect = ItemHealHp(battler, gLastUsedItem, TRUE, TRUE);
                break;
            case HOLD_EFFECT_RESTORE_PP:
                if (!moveTurn)
                    effect = ItemRestorePp(battler, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                effect = RestoreWhiteHerbStats(battler);
                if (effect != 0)
                {
                    gBattlerAttacker = battler;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_BLACK_SLUDGE:
                if (ES_COMBATIENTE_TIPO(battler, TIPO_VENENO))
                {
                    goto LEFTOVERS;
                }
                else if (GetBattlerAbility(battler) != ABILITY_MAGIC_GUARD && !moveTurn)
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_ItemHurtEnd2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battler, battlerHoldEffect);
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                }
                break;
            case HOLD_EFFECT_LEFTOVERS:
            LEFTOVERS:
                if (gBattleMons[battler].hp < gBattleMons[battler].maxHP && !moveTurn
                  && (B_HEAL_BLOCKING < GEN_5 || !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)))
                {
                    gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_End2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battler, battlerHoldEffect);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SPICY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (!moveTurn)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_DRY, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (!moveTurn)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SWEET, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (!moveTurn)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_BITTER, TRUE);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (!moveTurn)
                    effect = HealConfuseBerry(battler, gLastUsedItem, FLAVOR_SOUR, TRUE);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE, TRUE);
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA, TRUE);
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_VELOCIDAD, TRUE);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_ATAQUE_ESPECIAL, TRUE);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (!moveTurn)
                    effect = StatRaiseBerry(battler, gLastUsedItem, ESTADISTICA_DEFENSA_ESPECIAL, TRUE);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (!moveTurn && !(gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY_ANY)
                    && HasEnoughHpToEatBerry(battler, GetBattlerItemHoldEffectParam(battler, gLastUsedItem), gLastUsedItem))
                {
                    gBattleMons[battler].status2 |= STATUS2_FOCUS_ENERGY;
                    gBattleScripting.battler = battler;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (!moveTurn)
                    effect = RandomStatRaiseBerry(battler, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battler].status1 & STATUS1_PSN_ANY && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battler].status1 & STATUS1_BURN && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_BURN;
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battler].status1 & STATUS1_FREEZE && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FREEZE;
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                if (gBattleMons[battler].status1 & STATUS1_FROSTBITE && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FROSTBITE;
                    BattleScriptExecute(BattleScript_BerryCureFrbEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION && !UnnerveOn(battler, gLastUsedItem))
                {
                    RemoveConfusionStatus(battler);
                    BattleScriptExecute(BattleScript_BerryCureConfusionEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if ((gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION) && !UnnerveOn(battler, gLastUsedItem))
                {
                    i = 0;
                    if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gText_Poison);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                        StringCopy(gBattleTextBuff1, gText_Sleep);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gText_Paralysis);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gText_Burn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE || gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                    {
                        StringCopy(gBattleTextBuff1, gText_Ice);
                        i++;
                    }
                    if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gText_Confusion);
                        i++;
                    }
                    if (i <= 1)
                        gMensajeBatalla = B_MSG_CURED_PROBLEM;
                    else
                        gMensajeBatalla = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battler].status1 = 0;
                    RemoveConfusionStatus(battler);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_MENTAL_HERB:
                if (GetMentalHerbEffect(battler))
                {
                    gBattleScripting.savedBattler = gBattlerAttacker;
                    gBattlerAttacker = battler;
                    BattleScriptExecute(BattleScript_MentalHerbCureEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_MICLE_BERRY:
                if (!moveTurn)
                    effect = TrySetMicleBerry(battler, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_BERSERK_GENE:
                BufferStatChange(battler, ESTADISTICA_ATAQUE, STRINGID_STATROSE);
                gEffectBattler = battler;
                if (CanBeInfinitelyConfused(gEffectBattler))
                {
                    gStatuses4[gEffectBattler] |= STATUS4_INFINITE_CONFUSION;
                }
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);

                gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + ESTADISTICA_ATAQUE;
                gBattleScripting.animArg2 = 0;

                BattleScriptPushCursorAndCallback(BattleScript_BerserkGeneRet);
                effect = ITEM_STATS_CHANGE;
                break;
            case HOLD_EFFECT_MIRROR_HERB:
                effect = TryConsumeMirrorHerb(battler, TRUE);
                break;
            case HOLD_EFFECT_BOOSTER_ENERGY:
                break;
            }

            if (effect != 0)
            {
                gBattlerAttacker = gPotentialItemEffectBattler = gBattleScripting.battler = battler;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarcaCombatienteOcupado(battler);
                    break;
                }
            }
        }
        break;
    case ITEMEFFECT_USE_LAST_ITEM:
        effect = ItemEffectMoveEnd(battler, ItemId_GetHoldEffect(gLastUsedItem));
        gBattleScripting.overrideBerryRequirements = 2; // to exit VARIOUS_CONSUME_BERRIES
        if (effect)
        {
            gPotentialItemEffectBattler = gBattleScripting.battler = battler;
            if (effect == ITEM_STATUS_CHANGE)
            {
                BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                MarcaCombatienteOcupado(battler);
            }
            break;
        }
        break;
    case ITEMEFFECT_MOVE_END:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            gLastUsedItem = gBattleMons[battler].item;
            effect = ItemEffectMoveEnd(battler, GetBattlerHoldEffect(battler, TRUE));
            if (effect)
            {
                gPotentialItemEffectBattler = gBattleScripting.battler = battler;
                if (effect == ITEM_STATUS_CHANGE)
                {
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarcaCombatienteOcupado(battler);
                }
                break;
            }
        }
        break;
    case ITEMEFFECT_KINGSROCK:
        // Occur on each hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_FLINCH:
            {
                u16 ability = GetBattlerAbility(gBattlerAttacker);
                if (B_SERENE_GRACE_BOOST >= GEN_5 && ability == ABILITY_SERENE_GRACE)
                    atkHoldEffectParam *= 2;
                if (gBattleMoveDamage != 0  // Need to have done damage
                    && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && IsBattlerTurnDamaged(gBattlerTarget)
                    && !gMovesInfo[gCurrentMove].ignoresKingsRock
                    && gBattleMons[gBattlerTarget].hp
                    && PorcentajeAleatorio(atkHoldEffectParam))
                {
                    gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                    BattleScriptPushCursor();
                    SetMoveEffect(FALSE, FALSE);
                    BattleScriptPop();
                }
            }
            break;
        case HOLD_EFFECT_BLUNDER_POLICY:
            if (gBattleStruct->blunderPolicy
             && IsBattlerAlive(gBattlerAttacker)
             && CompareStat(gBattlerAttacker, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gBattleStruct->blunderPolicy = FALSE;
                gLastUsedItem = atkItem;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 2, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_LIFEORB_SHELLBELL:
        // Occur after the final hit of a multi-strike move
        switch (atkHoldEffect)
        {
        case HOLD_EFFECT_SHELL_BELL:
            if (gSpecialStatuses[gBattlerAttacker].damagedMons  // Need to have done damage
                && gBattlerAttacker != gBattlerTarget
                && gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP
                && IsBattlerAlive(gBattlerAttacker)
                && (B_HEAL_BLOCKING < GEN_5 || !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)))
            {
                gLastUsedItem = atkItem;
                gPotentialItemEffectBattler = gBattlerAttacker;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleMoveDamage = (gSpecialStatuses[gBattlerTarget].shellBellDmg / atkHoldEffectParam) * -1;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = -1;
                gSpecialStatuses[gBattlerTarget].shellBellDmg = 0;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHealHP_Ret;
                effect = ITEM_HP_CHANGE;
            }
            break;
        case HOLD_EFFECT_LIFE_ORB:
            if (IsBattlerAlive(gBattlerAttacker)
                && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove))
                && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD
                && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                && !gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage
                && gSpecialStatuses[gBattlerAttacker].damagedMons)
            {
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                effect = ITEM_HP_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHurtRet;
                gLastUsedItem = gBattleMons[gBattlerAttacker].item;
            }
            break;
        case HOLD_EFFECT_THROAT_SPRAY:  // Does NOT need to be a damaging move
            if (gProtectStructs[gBattlerAttacker].targetAffected
             && IsBattlerAlive(gBattlerAttacker)
             && gMovesInfo[gCurrentMove].soundMove
             && CompareStat(gBattlerAttacker, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR)
             && !NoAliveMonsForEitherParty())   // Don't activate if battle will end
            {
                gLastUsedItem = atkItem;
                gBattleScripting.battler = gBattlerAttacker;
                SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE);
                effect = ITEM_STATS_CHANGE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AttackerItemStatRaise;
            }
            break;
        }
        break;
    case ITEMEFFECT_TARGET:
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            moveType = GetMoveType(gCurrentMove);
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_AIR_BALLOON:
                if (IsBattlerTurnDamaged(gBattlerAttacker))
                {
                    effect = ITEM_EFFECT_OTHER;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AirBaloonMsgPop;
                }
                break;
            case HOLD_EFFECT_ROCKY_HELMET:
                if (IsBattlerTurnDamaged(gBattlerAttacker)
                    && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
                    && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                    && IsBattlerAlive(gBattlerAttacker)
                    && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 6;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_RockyHelmetActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battler, HOLD_EFFECT_ROCKY_HELMET);
                }
                break;
            case HOLD_EFFECT_WEAKNESS_POLICY:
                if (IsBattlerAlive(battler)
                    && IsBattlerTurnDamaged(battler)
                    && gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WeaknessPolicy;
                }
                break;
            case HOLD_EFFECT_SNOWBALL:
                if (IsBattlerAlive(battler)
                    && IsBattlerTurnDamaged(battler)
                    && moveType == TIPO_HIELO)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_DEFENSA, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_LUMINOUS_MOSS:
                if (IsBattlerAlive(battler)
                    && IsBattlerTurnDamaged(battler)
                    && moveType == TIPO_AGUA)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_DEFENSA_ESPECIAL, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_CELL_BATTERY:
                if (IsBattlerAlive(battler)
                    && IsBattlerTurnDamaged(battler)
                    && moveType == TIPO_ELECTRICO)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_ABSORB_BULB:
                if (IsBattlerAlive(battler)
                    && IsBattlerTurnDamaged(battler)
                    && moveType == TIPO_AGUA)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_ENIGMA_BERRY:
                break;
            case HOLD_EFFECT_JABOCA_BERRY:  // consume and damage attacker if used physical move
                if (IsBattlerAlive(battler)
                 && IsBattlerTurnDamaged(battler)
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                 && IS_MOVE_PHYSICAL(gCurrentMove)
                 && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (GetBattlerAbility(battler) == ABILITY_RIPEN)
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battler, HOLD_EFFECT_JABOCA_BERRY);
                }
                break;
            case HOLD_EFFECT_ROWAP_BERRY:  // consume and damage attacker if used special move
                if (IsBattlerAlive(battler)
                 && IsBattlerTurnDamaged(battler)
                 && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                 && IS_MOVE_SPECIAL(gCurrentMove)
                 && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (GetBattlerAbility(battler) == ABILITY_RIPEN)
                        gBattleMoveDamage *= 2;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battler, HOLD_EFFECT_ROWAP_BERRY);
                }
                break;
            case HOLD_EFFECT_KEE_BERRY:  // consume and boost defense if used physical move
                effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA, CATEGORIA_FISICA);
                break;
            case HOLD_EFFECT_MARANGA_BERRY:  // consume and boost sp. defense if used special move
                effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA_ESPECIAL, CATEGORIA_ESPECIAL);
                break;
            case HOLD_EFFECT_STICKY_BARB:
                if (IsBattlerTurnDamaged(gBattlerAttacker)
                  && (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                  && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS
                  && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)
                  && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                  && IsBattlerAlive(gBattlerAttacker)
                  && CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
                  && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
                {
                    // No sticky hold checks.
                    gEffectBattler = battler; // gEffectBattler = target
                    StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker takes target's barb
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_StickyBarbTransfer;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            }
        }
        break;
    case ITEMEFFECT_ORBS:
    {
        u16 battlerAbility = GetBattlerAbility(battler);
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_TOXIC_ORB:
            if (CanBePoisoned(battler, GetBattlerAbility(battler)))
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battler].status1 = STATUS1_TOXIC_POISON;
                BattleScriptExecute(BattleScript_ToxicOrb);
                RecordItemEffectBattle(battler, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (CanBeBurned(battler, battlerAbility))
            {
                effect = ITEM_STATUS_CHANGE;
                gBattleMons[battler].status1 = STATUS1_BURN;
                BattleScriptExecute(BattleScript_FlameOrb);
                RecordItemEffectBattle(battler, battlerHoldEffect);
            }
            break;
        case HOLD_EFFECT_STICKY_BARB:   // Not an orb per se, but similar effect, and needs to NOT activate with pickpocket
            if (battlerAbility != ABILITY_MAGIC_GUARD)
            {
                gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_ItemHurtEnd2);
                effect = ITEM_HP_CHANGE;
                RecordItemEffectBattle(battler, battlerHoldEffect);
                PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
            }
            break;
        }

        if (effect == ITEM_STATUS_CHANGE)
        {
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
            MarcaCombatienteOcupado(battler);
        }
    }
        break;
    case ITEMEFFECT_STATS_CHANGED:
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_RESTORE_STATS:
            effect = RestoreWhiteHerbStats(battler);
            if (effect != 0)
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WhiteHerbRet;
            }
            break;
        }
        break;
    }

    // Berry was successfully used on a Pokemon.
    if (effect && (gLastUsedItem >= FIRST_BERRY_INDEX && gLastUsedItem <= LAST_BERRY_INDEX))
        gBattleStruct->ateBerry[battler & BIT_SIDE] |= 1u << gBattlerPartyIndexes[battler];

    return effect;
}

void ClearVariousBattlerFlags(u32 battler)
{
    gDisableStructs[battler].furyCutterCounter = 0;
    gBattleMons[battler].status2 &= ~STATUS2_DESTINY_BOND;
    gStatuses3[battler] &= ~STATUS3_GRUDGE;
    gStatuses4[battler] &= ~ STATUS4_GLAIVE_RUSH;
}

void HandleAction_RunBattleScript(void) // identical to RunBattleScriptCommands
{
    if (!HayAlgunCombatienteOcupado())
        gBattleScriptingCommandsTable[*gBattlescriptCurrInstr]();
}

u32 SetRandomTarget(u32 battlerAtk)
{
    u32 target;
    static const u8 targets[2][2] =
    {
        [LADO_JUGADOR] = {OPONENTE_IZQUIERDA, OPONENTE_DERECHA},
        [LADO_OPONENTE] = {JUGADOR_IZQUIERDA, JUGADOR_DERECHA},
    };

    if (EsContraEntrenador())
    {
        target = targets[GetBattlerSide(battlerAtk][NumeroAleatorioEnRango(0, 1)]);
        if (!IsBattlerAlive(target))
            target ^= BIT_FLANK;
    }
    else
    {
        target = targets[GetBattlerSide(battlerAtk][0]);
    }

    return target;
}

u32 GetMoveTarget(u16 move, u8 setTarget)
{
    u8 targetBattler = 0;
    u32 moveTarget, side;
    u32 moveType = GetMoveType(move);

    if (setTarget != NO_TARGET_OVERRIDE)
        moveTarget = setTarget - 1;
    else
        moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, move);

    switch (moveTarget)
    {
    case MOVE_TARGET_SELECTED:
        side = OPONENTE(GetBattlerSide(gBattlerAttacker));
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
        {
            targetBattler = gSideTimers[side].followmeTarget;
        }
        else
        {
            targetBattler = SetRandomTarget(gBattlerAttacker);
            if (moveType == TIPO_ELECTRICO
                && EstaHabilidadEnCampoContrario(gBattlerAttacker, ABILITY_LIGHTNING_ROD)
                && GetBattlerAbility(targetBattler) != ABILITY_LIGHTNING_ROD)
            {
                targetBattler ^= BIT_FLANK;
                RecuerdaHabilidadCombate(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].lightningRodRedirected = TRUE;
            }
            else if (moveType == TIPO_AGUA
                && EstaHabilidadEnCampoContrario(gBattlerAttacker, ABILITY_STORM_DRAIN)
                && GetBattlerAbility(targetBattler) != ABILITY_STORM_DRAIN)
            {
                targetBattler ^= BIT_FLANK;
                RecuerdaHabilidadCombate(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].stormDrainRedirected = TRUE;
            }
        }
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
        targetBattler = OPONENTE(GetBattlerSide(gBattlerAttacker));
        if (!IsBattlerAlive(targetBattler))
            targetBattler ^= BIT_FLANK;
        break;
    case MOVE_TARGET_OPPONENTS_FIELD:
        targetBattler = OPONENTE(GetBattlerSide(gBattlerAttacker));
        break;
    case MOVE_TARGET_RANDOM:
        side = OPONENTE(GetBattlerSide(gBattlerAttacker));
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
            targetBattler = gSideTimers[side].followmeTarget;
        else if (EsContraEntrenador() && moveTarget & MOVE_TARGET_RANDOM)
            targetBattler = SetRandomTarget(gBattlerAttacker);
        else
            targetBattler = OPONENTE(GetBattlerSide(gBattlerAttacker));
        break;
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
    default:
        targetBattler = gBattlerAttacker;
        break;
    case MOVE_TARGET_ALLY:
        if (IsBattlerAlive(ALIADO(gBattlerAttacker)))
            targetBattler = ALIADO(gBattlerAttacker);
        else
            targetBattler = gBattlerAttacker;
        break;
    }

    *(gBattleStruct->moveTarget + gBattlerAttacker) = targetBattler;

    return targetBattler;
}

u32 GetBattlerHoldEffect(u32 battler, bool32 checkNegating)
{
    return GetBattlerHoldEffectInternal(battler, checkNegating, TRUE);
}

u32 GetBattlerHoldEffectIgnoreAbility(u32 battler, bool32 checkNegating)
{
    return GetBattlerHoldEffectInternal(battler, checkNegating, FALSE);
}

u32 GetBattlerHoldEffectInternal(u32 battler, bool32 checkNegating, bool32 checkAbility)
{
    if (checkNegating)
    {
        if (gStatuses3[battler] & STATUS3_EMBARGO)
            return HOLD_EFFECT_NONE;
        if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
            return HOLD_EFFECT_NONE;
    }

    gPotentialItemEffectBattler = battler;

    return ItemId_GetHoldEffect(gBattleMons[battler].item);
}

static u32 GetBattlerItemHoldEffectParam(u32 battler, u32 item)
{
    return ItemId_GetHoldEffectParam(item);
}

u32 GetBattlerHoldEffectParam(u32 battler)
{
    return ItemId_GetHoldEffectParam(gBattleMons[battler].item);
}

bool32 IsMoveMakingContact(u32 move, u32 battlerAtk)
{
    u32 atkHoldEffect = GetBattlerHoldEffect(battlerAtk, TRUE);

    if (!gMovesInfo[move].makesContact)
    {
        if (gMovesInfo[move].effect == EFFECT_SHELL_SIDE_ARM && gBattleStruct->shellSideArmCategory[battlerAtk][gBattlerTarget] == CATEGORIA_FISICA)
            return TRUE;
        else
            return FALSE;
    }
    else if ((atkHoldEffect == HOLD_EFFECT_PUNCHING_GLOVE && gMovesInfo[move].punchingMove)
           || GetBattlerAbility(battlerAtk) == ABILITY_NINJA
           || GetBattlerAbility(battlerAtk) == ABILITY_LONG_REACH)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool32 IsBattlerProtected(u32 battlerAtk, u32 battlerDef, u32 move)
{
    // Decorate bypasses protect and detect, but not crafty shield
    if (move == MOVE_DECORATE)
    {
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_CRAFTY_SHIELD)
            return TRUE;
        else if (gProtectStructs[battlerDef].protected)
            return FALSE;
    }

    if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_CRAFTY_SHIELD
             && IS_MOVE_STATUS(move))
        return TRUE;
    else if (gMovesInfo[move].ignoresProtect)
        return FALSE;
    else if (gProtectStructs[battlerDef].protected)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_WIDE_GUARD
             && GetBattlerMoveTargetType(gBattlerAttacker, move) & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
        return TRUE;
    else if (gProtectStructs[battlerDef].banefulBunkered)
        return TRUE;
    else if (gProtectStructs[battlerDef].burningBulwarked)
        return TRUE;
    else if ((gProtectStructs[battlerDef].obstructed || gProtectStructs[battlerDef].silkTrapped) && !IS_MOVE_STATUS(move))
        return TRUE;
    else if (gProtectStructs[battlerDef].spikyShielded)
        return TRUE;
    else if (gProtectStructs[battlerDef].kingsShielded && !IS_MOVE_STATUS(move))
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_QUICK_GUARD
             && GetChosenMovePriority(gBattlerAttacker) > 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_MAT_BLOCK
             && !IS_MOVE_STATUS(move))
        return TRUE;
    else
        return FALSE;
}

// Only called directly when calculating damage type effectiveness
static bool32 IsBattlerGroundedInverseCheck(u32 battler, bool32 considerInverse)
{
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);

    if (holdEffect == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    if (B_ROOTED_GROUNDING >= GEN_4 && gStatuses3[battler] & STATUS3_ROOTED)
        return TRUE;
    if (gStatuses3[battler] & STATUS3_SMACKED_DOWN)
        return TRUE;
    if (gStatuses3[battler] & STATUS3_TELEKINESIS)
        return FALSE;
    if (gStatuses3[battler] & STATUS3_MAGNET_RISE)
        return FALSE;
    if (holdEffect == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    if ((AI_DATA->aiCalcInProgress ? AI_DATA->abilities[battler] : GetBattlerAbility(battler)) == ABILITY_LEVITATE)
        return FALSE;
    if (ES_COMBATIENTE_TIPO(battler, TIPO_VOLADOR) && (!considerInverse || !FlagGet(B_FLAG_INVERSE_BATTLE)))
        return FALSE;
    return TRUE;
}

bool32 IsBattlerGrounded(u32 battler)
{
    return IsBattlerGroundedInverseCheck(battler, FALSE);
}

bool32 IsBattlerAlive(u32 battler)
{
    if (gBattleMons[battler].hp == 0)
        return FALSE;
    else if (battler >= gBattlersCount)
        return FALSE;
    else if (gAbsentBattlerFlags & (1u << battler))
        return FALSE;
    else
        return TRUE;
}

u32 GetMoveSlot(u16 *moves, u32 move)
{
    u32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == move)
            break;
    }
    return i;
}

u32 GetBattlerWeight(u32 battler)
{
    return 0;
}

u32 CountBattlerStatIncreases(u32 battler, bool32 countEvasionAcc)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
    {
        if ((i == ESTADISTICA_PRECISION || i == ESTADISTICA_EVASION) && !countEvasionAcc)
            continue;
        if (gBattleMons[battler].statStages[i] > ESTADISTICA_NEUTRA) // Stat is increased.
            count += gBattleMons[battler].statStages[i] - ESTADISTICA_NEUTRA;
    }

    return count;
}

u32 GetMoveTargetCount(struct DamageCalculationData *damageCalcData)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;

    switch (GetBattlerMoveTargetType(battlerAtk, move))
    {
    case MOVE_TARGET_BOTH:
        return !(gAbsentBattlerFlags & (1u << battlerDef))
             + !(gAbsentBattlerFlags & (1u << ALIADO(battlerDef)));
    case MOVE_TARGET_FOES_AND_ALLY:
        return !(gAbsentBattlerFlags & (1u << battlerDef))
             + !(gAbsentBattlerFlags & (1u << ALIADO(battlerDef)))
             + !(gAbsentBattlerFlags & (1u << ALIADO(battlerAtk)));
    case MOVE_TARGET_OPPONENTS_FIELD:
        return 1;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_USER_OR_SELECTED:
        return IsBattlerAlive(battlerDef);
    case MOVE_TARGET_USER:
        return IsBattlerAlive(battlerAtk);
    default:
        return 0;
    }
}

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
};

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
{
    100, 20,
    250, 40,
    500, 60,
    1000, 80,
    2000, 100,
    0xFFFF, 0xFFFF
};

static const u8 sSpeedDiffPowerTable[] = {40, 60, 80, 120, 150};
static const u8 sHeatCrashPowerTable[] = {40, 40, 60, 80, 100, 120};
static const u8 sTrumpCardPowerTable[] = {200, 80, 60, 50, 40};

u32 CalcRolloutBasePower(u32 battlerAtk, u32 basePower, u32 rolloutTimer)
{
    u32 i;
    for (i = 1; i < (5 - rolloutTimer); i++)
        basePower *= 2;
    if (gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL)
        basePower *= 2;
    return basePower;
}

u32 CalcFuryCutterBasePower(u32 basePower, u32 furyCutterCounter)
{
    u32 i;
    for (i = 1; i < furyCutterCounter; i++)
        basePower *= 2;
    return basePower;
}

static inline u32 CalcMoveBasePower(struct DamageCalculationData *damageCalcData, u32 abilityDef, u32 weather)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;

    u32 i;
    u32 basePower = gMovesInfo[move].power;
    u32 weight, hpFraction, speed;

    switch (gMovesInfo[move].effect)
    {
    case EFFECT_POWER_BASED_ON_USER_HP:
        basePower = gBattleMons[battlerAtk].hp * basePower / gBattleMons[battlerAtk].maxHP;
        break;
    case EFFECT_FLAIL:
        hpFraction = GetScaledHPFraction(gBattleMons[battlerAtk].hp, gBattleMons[battlerAtk].maxHP, 48);
        for (i = 0; i < sizeof(sFlailHpScaleToPowerTable); i += 2)
        {
            if (hpFraction <= sFlailHpScaleToPowerTable[i])
                break;
        }
        basePower = sFlailHpScaleToPowerTable[i + 1];
        break;
    case EFFECT_RETURN:
        basePower = 10 * (gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FURY_CUTTER:
        basePower = CalcFuryCutterBasePower(basePower, gDisableStructs[battlerAtk].furyCutterCounter);
        break;
    case EFFECT_ROLLOUT:
        basePower = CalcRolloutBasePower(battlerAtk, basePower, gDisableStructs[battlerAtk].rolloutTimer);
        break;
    case EFFECT_MAGNITUDE:
        basePower = gBattleStruct->magnitudeBasePower;
        break;
    case EFFECT_PRESENT:
        basePower = gBattleStruct->presentBasePower;
        break;
    case EFFECT_TRIPLE_KICK:
        basePower *= 1 + gMovesInfo[move].strikeCount - gMultiHitCounter;
        break;
    case EFFECT_SPIT_UP:
        basePower = 100 * gDisableStructs[battlerAtk].stockpileCounter;
        break;
    case EFFECT_REVENGE:
        if ((gProtectStructs[battlerAtk].physicalDmg
                && gProtectStructs[battlerAtk].physicalBattlerId == battlerDef)
            || (gProtectStructs[battlerAtk].specialDmg
                && gProtectStructs[battlerAtk].specialBattlerId == battlerDef))
            basePower *= 2;
        break;
    case EFFECT_WEATHER_BALL:
        if (weather & B_WEATHER_ANY)
            basePower *= 2;
        break;
    case EFFECT_PURSUIT:
        if (gActionsByTurnOrder[GetBattlerTurnOrderNum(battlerDef)] == B_ACTION_SWITCH)
            basePower *= 2;
        break;        
    case EFFECT_DOUBLE_POWER_ON_ARG_STATUS:
        // Comatose targets treated as if asleep
        if ((gBattleMons[battlerDef].status1 | (STATUS1_SLEEP * (abilityDef == ABILITY_COMATOSE))) & gMovesInfo[move].argument
         && !((gMovesInfo[move].additionalEffects->moveEffect == MOVE_EFFECT_REMOVE_STATUS) && DoesSubstituteBlockMove(battlerAtk, battlerDef, move)))
        {
            basePower *= 2;
        }
        break;
    case EFFECT_POWER_BASED_ON_TARGET_HP:
        basePower = gBattleMons[battlerDef].hp * basePower / gBattleMons[battlerDef].maxHP;
        break;
    case EFFECT_ASSURANCE:
        if (gProtectStructs[battlerDef].physicalDmg != 0 || gProtectStructs[battlerDef].specialDmg != 0 || gProtectStructs[battlerDef].confusionSelfDmg)
            basePower *= 2;
        break;
    case EFFECT_TRUMP_CARD:
        i = GetMoveSlot(gBattleMons[battlerAtk].moves, move);
        if (i != MAX_MON_MOVES)
        {
            if (gBattleMons[battlerAtk].pp[i] >= ARRAY_COUNT(sTrumpCardPowerTable))
                basePower = sTrumpCardPowerTable[ARRAY_COUNT(sTrumpCardPowerTable) - 1];
            else
                basePower = sTrumpCardPowerTable[gBattleMons[battlerAtk].pp[i]];
        }
        break;
    case EFFECT_ACROBATICS:
        if (gBattleMons[battlerAtk].item == ITEM_NONE
            // Edge case, because removal of items happens after damage calculation.
            || (gSpecialStatuses[battlerAtk].gemBoost && GetBattlerHoldEffect(battlerAtk, FALSE) == HOLD_EFFECT_GEMS))
            basePower *= 2;
        break;
    case EFFECT_LOW_KICK:
        weight = GetBattlerWeight(battlerDef);
        for (i = 0; sWeightToDamageTable[i] != 0xFFFF; i += 2)
        {
            if (sWeightToDamageTable[i] > weight)
                break;
        }
        if (sWeightToDamageTable[i] != 0xFFFF)
            basePower = sWeightToDamageTable[i + 1];
        else
            basePower = 120;
        break;
    case EFFECT_HEAT_CRASH:
        weight = GetBattlerWeight(battlerAtk) / GetBattlerWeight(battlerDef);
        if (weight >= ARRAY_COUNT(sHeatCrashPowerTable))
            basePower = sHeatCrashPowerTable[ARRAY_COUNT(sHeatCrashPowerTable) - 1];
        else
            basePower = sHeatCrashPowerTable[weight];
        break;
    case EFFECT_PUNISHMENT:
        basePower = 60 + (CountBattlerStatIncreases(battlerDef, FALSE) * 20);
        if (basePower > 200)
            basePower = 200;
        break;
    case EFFECT_STORED_POWER:
        basePower += (CountBattlerStatIncreases(battlerAtk, TRUE) * 20);
        break;
    case EFFECT_ELECTRO_BALL:
        speed = GetBattlerTotalSpeedStat(battlerAtk) / GetBattlerTotalSpeedStat(battlerDef);
        if (speed >= ARRAY_COUNT(sSpeedDiffPowerTable))
            speed = ARRAY_COUNT(sSpeedDiffPowerTable) - 1;
        basePower = sSpeedDiffPowerTable[speed];
        break;
    case EFFECT_GYRO_BALL:
        basePower = ((25 * GetBattlerTotalSpeedStat(battlerDef)) / GetBattlerTotalSpeedStat(battlerAtk)) + 1;
        if (basePower > 150)
            basePower = 150;
        break;
    case EFFECT_ECHOED_VOICE:
        // gBattleStruct->sameMoveTurns incremented in ppreduce
        if (gBattleStruct->sameMoveTurns[battlerAtk] != 0)
        {
            basePower += (basePower * gBattleStruct->sameMoveTurns[battlerAtk]);
            if (basePower > 200)
                basePower = 200;
        }
        break;
    case EFFECT_PAYBACK:
        if (GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef)
            && gDisableStructs[battlerDef].isFirstTurn != 2)
        {
            basePower *= 2;
        }
        break;
    case EFFECT_BOLT_BEAK:
        if (GetBattlerTurnOrderNum(battlerAtk) < GetBattlerTurnOrderNum(battlerDef)
            || gDisableStructs[battlerDef].isFirstTurn == 2)
            basePower *= 2;
        break;
    case EFFECT_FUSION_COMBO:
        if (gMovesInfo[gLastUsedMove].effect == EFFECT_FUSION_COMBO && move != gLastUsedMove)
            basePower *= 2;
        break;
    case EFFECT_LASH_OUT:
        if (gProtectStructs[battlerAtk].statFell)
            basePower *= 2;
        break;
    case EFFECT_EXPLOSION:
        break;
    case EFFECT_HIDDEN_POWER:
        break;
    case EFFECT_EXPANDING_FORCE:
        break;
    case EFFECT_RISING_VOLTAGE:
        break;
    case EFFECT_PSYBLADE:
        break;
    case EFFECT_RAGE_FIST:
        basePower += 25 * gBattleStruct->timesGotHit[GetBattlerSide(battlerAtk)][gBattlerPartyIndexes[battlerAtk]];
        basePower = (basePower > 200) ? 200 : basePower;
        break;
    case EFFECT_LAST_RESPECTS:
        basePower += (basePower * min(100, GetBattlerSideFaintCounter(battlerAtk)));
        break;
    }

    // Move-specific base power changes
    switch (move)
    {
    case MOVE_WATER_SHURIKEN:
        if (gBattleMons[battlerAtk].species == SPECIES_GRENINJA)
            basePower = 20;
        break;
    }

    if (basePower == 0)
        basePower = 1;
    return basePower;
}

static inline u32 CalcMoveBasePowerAfterModifiers(struct DamageCalculationData *damageCalcData, u32 atkAbility, u32 defAbility, u32 holdEffectAtk, u32 weather)
{
    u32 i;
    u32 holdEffectParamAtk;
    u32 basePower = CalcMoveBasePower(damageCalcData, defAbility, weather);
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    uq4_12_t holdEffectModifier;
    uq4_12_t modifier = UQ_4_12(1.0);
    u32 atkSide = GetBattlerSide(battlerAtk);

    // move effect
    switch (gMovesInfo[move].effect)
    {
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS | STATUS1_FROSTBITE))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_RETALIATE:
        if (gSideTimers[atkSide].retaliateTimer == 1)
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_SOLAR_BEAM:
        if (IsBattlerWeatherAffected(battlerAtk, (B_WEATHER_HAIL | B_WEATHER_SANDSTORM | B_WEATHER_RAIN | B_WEATHER_SNOW | B_WEATHER_FOG)))
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
        break;
    case EFFECT_STOMPING_TANTRUM:
        if (gBattleStruct->lastMoveFailed & (1u << battlerAtk))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    }

    // various effects
    if (gProtectStructs[battlerAtk].helpingHand)
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
    if (gSpecialStatuses[battlerAtk].gemBoost)
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.0) + sPercentToModifier[gSpecialStatuses[battlerAtk].gemParam]);
    if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP && moveType == TIPO_ELECTRICO)
        modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
    if (gStatuses3[battlerAtk] & STATUS3_ME_FIRST)
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
    if (moveType == TIPO_ELECTRICO && ((gFieldStatuses & STATUS_FIELD_MUDSPORT)
    || AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, ABILITYEFFECT_MUD_SPORT, 0)))
        modifier = uq4_12_multiply(modifier, UQ_4_12(B_SPORT_DMG_REDUCTION >= GEN_5 ? 0.33 : 0.5));
    if (moveType == TIPO_FUEGO && ((gFieldStatuses & STATUS_FIELD_WATERSPORT)
    || AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, ABILITYEFFECT_WATER_SPORT, 0)))
        modifier = uq4_12_multiply(modifier, UQ_4_12(B_SPORT_DMG_REDUCTION >= GEN_5 ? 0.33 : 0.5));

    // attacker's abilities
    switch (atkAbility)
    {
    case ABILITY_TECHNICIAN:
        if (basePower <= 60)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_FLARE_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && IS_MOVE_SPECIAL(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TOXIC_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && IS_MOVE_PHYSICAL(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_RECKLESS:
        if (IS_MOVE_RECOIL(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_IRON_FIST:
        if (gMovesInfo[move].punchingMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_SHEER_FORCE:
        if (MoveIsAffectedBySheerForce(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_SAND_FORCE:
        if ((moveType == TIPO_ACERO || moveType == TIPO_ROCA || moveType == TIPO_TIERRA)
            && weather & B_WEATHER_SANDSTORM)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_RIVALRY:
        if (AreBattlersOfSameGender(battlerAtk, battlerDef))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_ANALYTIC:
    case ABILITY_AGRESIVIDAD:
        if (GetBattlerTurnOrderNum(battlerAtk) == gBattlersCount - 1 && move != MOVE_FUTURE_SIGHT && move != MOVE_DOOM_DESIRE)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TOUGH_CLAWS:
        if (IsMoveMakingContact(move, battlerAtk))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STRONG_JAW:
    case ABILITY_NAVAJAS:
        if (gMovesInfo[move].bitingMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_MEGADISPARADOR:
        if (gMovesInfo[move].balistico)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_CARPINTERO:
        if (gMovesInfo[move].movimientoPunzante)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_MARTILLADOR:
        if (gMovesInfo[move].hammerMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_DINOCOLA:
        if (gMovesInfo[move].tailMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_CORNAMENTA:
        if (gMovesInfo[move].movimientoPunzante)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_LENGUALARGA:
        if (gMovesInfo[move].lickMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_ESCALOFRIO:
        if (moveType == TIPO_HIELO)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_WATER_BUBBLE:
        if (moveType == TIPO_AGUA)
           modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case ABILITY_STEELWORKER:
        if (moveType == TIPO_ACERO)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PIXILATE:
        if (moveType == TIPO_HADA)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_GALVANIZE:
        if (moveType == TIPO_ELECTRICO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_REFRIGERATE:
        if (moveType == TIPO_HIELO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_CELESTE:
        if (moveType == TIPO_VOLADOR)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_VIDAS_PASADAS:
        if (moveType == TIPO_FANTASMA)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_EXTRASENSORIAL:
        if (moveType == TIPO_PSIQUICO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_LUNA_MENGUANTE:
        if (moveType == TIPO_SINIESTRO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_NORMALIDAD:
        if (moveType == TIPO_NORMAL)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_SURFERO:
        if (moveType == TIPO_AGUA)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_PUNK_ROCK:
        if (gMovesInfo[move].soundMove)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_PERCUSIONISTA:
        if (gMovesInfo[move].soundMove)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_ARTES_OSCURAS:
    case ABILITY_NOCTURNO:
        if (moveType == TIPO_SINIESTRO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_EN_METALICO:
        if (moveType == TIPO_ACERO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_VENENOSO:
        if (moveType == TIPO_VENENO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_STEELY_SPIRIT:
        if (moveType == TIPO_ACERO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TRANSISTOR:
        if (moveType == TIPO_ELECTRICO)
        {
            if (B_TRANSISTOR_BOOST >= GEN_9)
                modifier = uq4_12_multiply(modifier, UQ_4_12(5325 / 4096));
            else
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_DRAGONS_MAW:
        if (moveType == TIPO_DRAGON)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_GORILLA_TACTICS:
        if (IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TERRESTRE:
        if (moveType == TIPO_TIERRA)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_SHARPNESS:
        if (gMovesInfo[move].slicingMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_CARA_DURA:
        if (gMovesInfo[move].headMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    }

    // attacker partner's abilities
    if (IsBattlerAlive(ALIADO(battlerAtk)))
    {
        switch (GetBattlerAbility(ALIADO(battlerAtk)))
        {
        case ABILITY_BATTERY:
            if (IS_MOVE_SPECIAL(move))
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
            break;
        case ABILITY_POWER_SPOT:
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
            break;
        case ABILITY_STEELY_SPIRIT:
            if (moveType == TIPO_ACERO)
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
            break;
        }
    }

    // target's abilities
    switch (defAbility)
    {
    case ABILITY_HEATPROOF:
    case ABILITY_WATER_BUBBLE:
        if (moveType == TIPO_FUEGO)
        {
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, defAbility);
        }
        break;
    case ABILITY_DRY_SKIN:
        if (moveType == TIPO_FUEGO)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    }

    holdEffectParamAtk = GetBattlerHoldEffectParam(battlerAtk);
    if (holdEffectParamAtk > 100)
        holdEffectParamAtk = 100;

    holdEffectModifier = UQ_4_12(1.0) + sPercentToModifier[holdEffectParamAtk];

    // attacker's hold effect
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (IS_MOVE_SPECIAL(move))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_SOUL_DEW:
        break;
    case HOLD_EFFECT_BUG_POWER:
    case HOLD_EFFECT_STEEL_POWER:
    case HOLD_EFFECT_GROUND_POWER:
    case HOLD_EFFECT_ROCK_POWER:
    case HOLD_EFFECT_GRASS_POWER:
    case HOLD_EFFECT_DARK_POWER:
    case HOLD_EFFECT_FIGHTING_POWER:
    case HOLD_EFFECT_ELECTRIC_POWER:
    case HOLD_EFFECT_WATER_POWER:
    case HOLD_EFFECT_FLYING_POWER:
    case HOLD_EFFECT_POISON_POWER:
    case HOLD_EFFECT_ICE_POWER:
    case HOLD_EFFECT_GHOST_POWER:
    case HOLD_EFFECT_PSYCHIC_POWER:
    case HOLD_EFFECT_FIRE_POWER:
    case HOLD_EFFECT_DRAGON_POWER:
    case HOLD_EFFECT_NORMAL_POWER:
    case HOLD_EFFECT_FAIRY_POWER:
        for (i = 0; i < ARRAY_COUNT(sHoldEffectToType); i++)
        {
            if (holdEffectAtk == sHoldEffectToType[i][0])
            {
                if (moveType == sHoldEffectToType[i][1])
                    modifier = uq4_12_multiply(modifier, holdEffectModifier);
                break;
            }
        }
        break;
    case HOLD_EFFECT_PLATE:
        if (moveType == ItemId_GetSecondaryId(gBattleMons[battlerAtk].item))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_PUNCHING_GLOVE:
        if (gMovesInfo[move].punchingMove)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.1));
        break;
    }

    return uq4_12_multiply_by_int_half_down(modifier, basePower);
}

static inline u32 CalcAttackStat(struct DamageCalculationData *damageCalcData, u32 atkAbility, u32 defAbility, u32 holdEffectAtk, u32 weather)
{
    u8 atkStage;
    u32 atkStat;
    uq4_12_t modifier;
    u16 atkBaseSpeciesId;
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    atkBaseSpeciesId = GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species);

    if (gMovesInfo[move].effect == EFFECT_FOUL_PLAY)
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerDef].attack;
            atkStage = gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE];
        }
        else
        {
            atkStat = gBattleMons[battlerDef].spAttack;
            atkStage = gBattleMons[battlerDef].statStages[ESTADISTICA_ATAQUE_ESPECIAL];
        }
    }
    else if (gMovesInfo[move].effect == EFFECT_BODY_PRESS)
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerAtk].defense;
            // Edge case: Body Press used during Wonder Room. For some reason, it still uses Defense over Sp.Def, but uses Sp.Def stat changes
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
                atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_DEFENSA_ESPECIAL];
            else
                atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_DEFENSA];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spDefense;
            atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_DEFENSA_ESPECIAL];
        }
    }
    else
    {
        if (IS_MOVE_PHYSICAL(move))
        {
            atkStat = gBattleMons[battlerAtk].attack;
            atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spAttack;
            atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE_ESPECIAL];
        }
    }

    if (damageCalcData->isCrit && atkStage < ESTADISTICA_NEUTRA)
        atkStage = ESTADISTICA_NEUTRA;

    if (defAbility == ABILITY_UNAWARE)
        atkStage = ESTADISTICA_NEUTRA;

    atkStat *= gMultiplicadoresEstadisticas[atkStage] >> 8;

    // apply attack stat modifiers
    modifier = UQ_4_12(1.0);

    // attacker's abilities
    switch (atkAbility)
    {
    case ABILITY_PODER_SOLAR:
        if (IsBattlerWeatherAffected(battlerAtk, B_WEATHER_SUN))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_DEFEATIST:
        if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 2))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TIPO_FUEGO && gBattleResources->flags->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SWARM:
        if (moveType == TIPO_BICHO && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TORRENT:
        if (moveType == TIPO_AGUA && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_BLAZE:
        if (moveType == TIPO_FUEGO && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_OVERGROW:
        if (moveType == TIPO_PLANTA && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PLUS:
        if (IS_MOVE_SPECIAL(move) && IsBattlerAlive(ALIADO(battlerAtk)))
        {
            u32 partnerAbility = GetBattlerAbility(ALIADO(battlerAtk));
            if (partnerAbility == ABILITY_MINUS
            || (B_PLUS_MINUS_INTERACTION >= GEN_5 && partnerAbility == ABILITY_PLUS))
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_MINUS:
        if (IS_MOVE_SPECIAL(move) && IsBattlerAlive(ALIADO(battlerAtk)))
        {
            u32 partnerAbility = GetBattlerAbility(ALIADO(battlerAtk));
            if (partnerAbility == ABILITY_PLUS
            || (B_PLUS_MINUS_INTERACTION >= GEN_5 && partnerAbility == ABILITY_MINUS))
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_GENERADOR:
        if (moveType == TIPO_ELECTRICO)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case ABILITY_HUSTLE:
        if (IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_STAKEOUT:
        if (gDisableStructs[battlerDef].isFirstTurn == 2) // just switched in
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case ABILITY_GUTS:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    }

    // target's abilities
    switch (defAbility)
    {
    case ABILITY_SEBO:
        if (moveType == TIPO_FUEGO || moveType == TIPO_HIELO)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_SEBO);
        }
        break;
    case ABILITY_ILLUMINATE:
        if (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_ILLUMINATE);
        }
        break;
    case ABILITY_GUARDIAN:
        if (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_GUARDIAN);
        }
        break;
    case ABILITY_TIERRA_HUMEDA:
        if (moveType == TIPO_FUEGO)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_TIERRA_HUMEDA);
        }
        break;
    }

    // ally's abilities
    if (IsBattlerAlive(ALIADO(battlerAtk)))
    {
        switch (GetBattlerAbility(ALIADO(battlerAtk)))
        {
        case ABILITY_GENERADOR:
            if (moveType == TIPO_ELECTRICO)
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
            break;        
        }
    }

    // attacker's hold effect
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((atkBaseSpeciesId == SPECIES_CUBONE || atkBaseSpeciesId == SPECIES_MAROWAK) && IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && IS_MOVE_SPECIAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (atkBaseSpeciesId == SPECIES_PICHU || atkBaseSpeciesId == SPECIES_PIKACHU || atkBaseSpeciesId == SPECIES_RAICHU || atkBaseSpeciesId == SPECIES_RAICHU_ALOLA)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_CUCHARA_TORCIDA:
        if (atkBaseSpeciesId == SPECIES_ABRA || atkBaseSpeciesId == SPECIES_KADABRA || atkBaseSpeciesId == SPECIES_ALAKAZAM)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_ELECTRIZADOR:
        if (atkBaseSpeciesId == SPECIES_ELEKID || atkBaseSpeciesId == SPECIES_ELECTABUZZ || atkBaseSpeciesId == SPECIES_ELECTIVIRE)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_MAGMATIZADOR:
        if (atkBaseSpeciesId == SPECIES_MAGBY || atkBaseSpeciesId == SPECIES_MAGMAR || atkBaseSpeciesId == SPECIES_MAGMORTAR)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_DISCO_EXTRANO:
        if (atkBaseSpeciesId == SPECIES_MAGBY || atkBaseSpeciesId == SPECIES_MAGMAR || atkBaseSpeciesId == SPECIES_MAGMORTAR)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_PROTECTOR:
        if (atkBaseSpeciesId == SPECIES_RHYHORN || atkBaseSpeciesId == SPECIES_RHYDON || atkBaseSpeciesId == SPECIES_RHYPERIOR)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.25));
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (IS_MOVE_PHYSICAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (IS_MOVE_SPECIAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    }

    // The offensive stats of a Player's Pokémon are boosted by x1.1 (+10%) if they have the 1st badge and 7th badges.
    // Having the 1st badge boosts physical attack while having the 7th badge boosts special attack.
    if (ShouldGetStatBadgeBoost(FLAG_BADGE01_GET, battlerAtk) && IS_MOVE_PHYSICAL(move))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.1));
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerAtk) && IS_MOVE_SPECIAL(move))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.1));

    return uq4_12_multiply_by_int_half_down(modifier, atkStat);
}

static bool32 CanEvolve(u32 species)
{
    u32 i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions != NULL)
    {
        for (i = 0; evolutions[i].method != EVO_FIN; i++)
        {
            if (evolutions[i].method
             && SanitizeSpeciesId(evolutions[i].targetSpecies) != SPECIES_NONE)
                return TRUE;
        }
    }
    return FALSE;
}

static inline u32 CalcDefenseStat(struct DamageCalculationData *damageCalcData, u32 atkAbility, u32 defAbility, u32 holdEffectDef, u32 weather)
{
    bool32 usesDefStat;
    u8 defStage;
    u32 defStat, def, spDef;
    uq4_12_t modifier;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) // the defense stats are swapped
    {
        def = gBattleMons[battlerDef].spDefense;
        spDef = gBattleMons[battlerDef].defense;
    }
    else
    {
        def = gBattleMons[battlerDef].defense;
        spDef = gBattleMons[battlerDef].spDefense;
    }

    if (gMovesInfo[move].effect == EFFECT_PSYSHOCK || IS_MOVE_PHYSICAL(move))
    {
        defStat = def;
        defStage = gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA];
        usesDefStat = TRUE;
    }
    else
    {
        defStat = spDef;
        defStage = gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA_ESPECIAL];
        usesDefStat = FALSE;
    }

    if (damageCalcData->isCrit && defStage > ESTADISTICA_NEUTRA)
        defStage = ESTADISTICA_NEUTRA;

    if (atkAbility == ABILITY_UNAWARE)
        defStage = ESTADISTICA_NEUTRA;

    if (gMovesInfo[move].ignoresTargetDefenseEvasionStages)
        defStage = ESTADISTICA_NEUTRA;

    defStat *= gMultiplicadoresEstadisticas[defStage] >> 8;

    // apply defense stat modifiers
    modifier = UQ_4_12(1.0);

    // target's abilities
    switch (defAbility)
    {
    case ABILITY_MARVEL_SCALE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY && usesDefStat)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_MARVEL_SCALE);
        }
        break;
    case ABILITY_FUR_COAT:
        if (usesDefStat)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
            if (damageCalcData->updateFlags)
                RecuerdaHabilidadCombate(battlerDef, ABILITY_FUR_COAT);
        }
        break;
    case ABILITY_GRASS_PELT:
        break;
    case ABILITY_FLOWER_GIFT:
        break;
    case ABILITY_PURIFYING_SALT:
        if (moveType == TIPO_FANTASMA)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    }

    // ally's abilities
    if (IsBattlerAlive(ALIADO(battlerDef)))
    {
        switch (GetBattlerAbility(ALIADO(battlerDef)))
        {
        case ABILITY_FLOWER_GIFT:
            break;
        }
    }

    // target's hold effects
    switch (holdEffectDef)
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_EVIOLITE:
        if (CanEvolve(gBattleMons[battlerDef].species))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (!usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHALECO_TACTICO:
        if (usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_SOUL_DEW:
        if (B_SOUL_DEW_BOOST < GEN_7
         && (gBattleMons[battlerDef].species == SPECIES_LATIAS || gBattleMons[battlerDef].species == SPECIES_LATIOS)
         && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    }

    // sandstorm sp.def boost for rock types
    if (ES_COMBATIENTE_TIPO(battlerDef, TIPO_ROCA) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_SANDSTORM) && !usesDefStat)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
    // snow def boost for ice types
    if (ES_COMBATIENTE_TIPO(battlerDef, TIPO_HIELO) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_HAIL) && usesDefStat)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
    if (ES_COMBATIENTE_TIPO(battlerDef, TIPO_HIELO) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_RAIN) && usesDefStat && defAbility == ABILITY_HUMEDAD_RELATIVA)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
    // somnolientos -25% defensa
    if (gBattleMons[battlerDef].status1 & STATUS1_BURN && usesDefStat)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.75));
    // The defensive stats of a Player's Pokémon are boosted by x1.1 (+10%) if they have the 5th badge and 7th badges.
    // Having the 5th badge boosts physical defense while having the 7th badge boosts special defense.
    if (ShouldGetStatBadgeBoost(FLAG_BADGE05_GET, battlerDef) && IS_MOVE_PHYSICAL(move))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.1));
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerDef) && IS_MOVE_SPECIAL(move))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.1));

    return uq4_12_multiply_by_int_half_down(modifier, defStat);
}

// base damage formula before adding any modifiers
static inline s32 CalculateBaseDamage(u32 power, u32 userFinalAttack, u32 level, u32 targetFinalDefense)
{
    return power * userFinalAttack * (2 * level / 5 + 2) / targetFinalDefense / 50 + 2;
}

static inline uq4_12_t GetTargetDamageModifier(struct DamageCalculationData *damageCalcData)
{
    if (EsContraEntrenador() && GetMoveTargetCount(damageCalcData) >= 2)
        return B_MULTIPLE_TARGETS_DMG >= GEN_4 ? UQ_4_12(0.75) : UQ_4_12(0.5);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetParentalBondModifier(u32 battlerAtk)
{
    if (gSpecialStatuses[battlerAtk].parentalBondState != PARENTAL_BOND_2ND_HIT)
        return UQ_4_12(1.0);
    return UQ_4_12(0.25);
}

static inline uq4_12_t GetSameTypeAttackBonusModifier(struct DamageCalculationData *damageCalcData, u32 abilityAtk)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 moveType = damageCalcData->moveType;

    if (ES_COMBATIENTE_TIPO(battlerAtk, moveType))
    {
        if (GetBattlerType(battlerAtk, 0) != GetBattlerType(battlerAtk, 1))
            return UQ_4_12(1.25);
        else
            return UQ_4_12(1.5);
    }
    else
        return UQ_4_12(1.0);    
}

// Utility Umbrella holders take normal damage from what would be rain- and sun-weakened attacks.
static uq4_12_t GetWeatherDamageModifier(struct DamageCalculationData *damageCalcData, u32 holdEffectAtk, u32 holdEffectDef, u32 weather)
{
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    if (weather == B_WEATHER_NONE)
        return UQ_4_12(1.0);
    if (gMovesInfo[move].effect == EFFECT_HYDRO_STEAM && (weather & B_WEATHER_SUN) && holdEffectAtk != HOLD_EFFECT_UTILITY_UMBRELLA)
        return UQ_4_12(1.5);
    if (holdEffectDef == HOLD_EFFECT_UTILITY_UMBRELLA)
        return UQ_4_12(1.0);

    if (weather & B_WEATHER_RAIN)
    {
        if (moveType != TIPO_FUEGO && moveType != TIPO_AGUA)
            return UQ_4_12(1.0);
        return (moveType == TIPO_FUEGO) ? UQ_4_12(0.5) : UQ_4_12(1.25);
    }
    if (weather & B_WEATHER_SUN)
    {
        if (moveType != TIPO_FUEGO && moveType != TIPO_AGUA)
            return UQ_4_12(1.0);
        return (moveType == TIPO_AGUA) ? UQ_4_12(0.5) : UQ_4_12(1.25);
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetBurnOrFrostBiteModifier(struct DamageCalculationData *damageCalcData, u32 abilityAtk)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 move = damageCalcData->move;

    if (gBattleMons[battlerAtk].status1 & STATUS1_BURN
        && IS_MOVE_PHYSICAL(move)
        && (B_BURN_FACADE_DMG < GEN_6 || gMovesInfo[move].effect != EFFECT_FACADE)
        && abilityAtk != ABILITY_GUTS)
    {
        return UQ_4_12(0.75);        
    }
    if (gBattleMons[battlerAtk].status1 & STATUS1_FROSTBITE
        && IS_MOVE_SPECIAL(move)
        && (B_BURN_FACADE_DMG < GEN_6 || gMovesInfo[move].effect != EFFECT_FACADE))
    {
        return UQ_4_12(0.75);
    }
    else 
    {
        return UQ_4_12(1.0);
    }

}

static inline uq4_12_t GetCriticalModifier(bool32 isCrit)
{
    if (isCrit)
        return B_CRIT_MULTIPLIER >= GEN_6 ? UQ_4_12(1.5) : UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetGlaiveRushModifier(u32 battlerDef)
{
    if (gStatuses4[battlerDef] & STATUS4_GLAIVE_RUSH)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetMinimizeModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].minimizeDoubleDamage && gStatuses3[battlerDef] & STATUS3_MINIMIZED)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetUndergroundModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesUnderground && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDiveModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesUnderwater && gStatuses3[battlerDef] & STATUS3_UNDERWATER)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAirborneModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesAirborneDoubleDamage && gStatuses3[battlerDef] & STATUS3_ON_AIR)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetScreensModifier(u32 move, u32 battlerAtk, u32 battlerDef, bool32 isCrit, u32 abilityAtk)
{
    u32 sideStatus = gSideStatuses[GetBattlerSide(battlerDef)];
    bool32 lightScreen = (sideStatus & SIDE_STATUS_LIGHTSCREEN) && IS_MOVE_SPECIAL(move);
    bool32 reflect = (sideStatus & SIDE_STATUS_REFLECT) && IS_MOVE_PHYSICAL(move);
    bool32 auroraVeil = sideStatus & SIDE_STATUS_AURORA_VEIL;

    if (isCrit || abilityAtk == ABILITY_SIGILOSO || gProtectStructs[battlerAtk].confusionSelfDmg)
        return UQ_4_12(1.0);
    if (reflect || lightScreen || auroraVeil)
        return (EsContraEntrenador()) ? UQ_4_12(0.667) : UQ_4_12(0.5);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAttackerAbilitiesModifier(u32 battlerAtk, uq4_12_t typeEffectivenessModifier, bool32 isCrit, u32 abilityAtk)
{
    switch (abilityAtk)
    {
        case ABILITY_SNIPER:
            if (isCrit)
                return UQ_4_12(1.5);
            break;
        case ABILITY_CROMOLENTE:
            if (typeEffectivenessModifier < UQ_4_12(1.0))
                return UQ_4_12(1.0);
            break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDefenderAbilitiesModifier(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, uq4_12_t typeEffectivenessModifier, u32 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_GUARDA:
        if (typeEffectivenessModifier == UQ_4_12(1.0))
            return UQ_4_12(0.5);
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDefenderPartnerAbilitiesModifier(u32 battlerPartnerDef)
{
    if (!IsBattlerAlive(battlerPartnerDef))
        return UQ_4_12(1.0);

    switch (GetBattlerAbility(battlerPartnerDef))
    {
    case ABILITY_FRIEND_GUARD:
        return UQ_4_12(0.75);
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAttackerItemsModifier(u32 battlerAtk, uq4_12_t typeEffectivenessModifier, u32 holdEffectAtk)
{
    u32 percentBoost;
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_METRONOME:
        percentBoost = min((gBattleStruct->sameMoveTurns[battlerAtk] * GetBattlerHoldEffectParam(battlerAtk)), 100);
        return uq4_12_add(sPercentToModifier[percentBoost], UQ_4_12(1.0));
        break;
    case HOLD_EFFECT_EXPERT_BELT:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            return UQ_4_12(1.2);
        break;
    case HOLD_EFFECT_LIFE_ORB:
        return UQ_4_12(1.25);
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDefenderItemsModifier(struct DamageCalculationData *damageCalcData, uq4_12_t typeEffectivenessModifier, u32 abilityDef, u32 holdEffectDef)
{
    u32 battlerDef = damageCalcData->battlerDef;
    u32 moveType = damageCalcData->moveType;

    u32 holdEffectDefParam = GetBattlerHoldEffectParam(battlerDef);
    u32 itemDef = gBattleMons[battlerDef].item;

    switch (holdEffectDef)
    {
    case HOLD_EFFECT_RESIST_BERRY:
        if (UnnerveOn(battlerDef, itemDef))
            return UQ_4_12(1.0);
        if (moveType == holdEffectDefParam && (moveType == TIPO_NORMAL || typeEffectivenessModifier >= UQ_4_12(2.0)))
        {
            if (damageCalcData->updateFlags)
                gSpecialStatuses[battlerDef].berryReduced = TRUE;
            return (abilityDef == ABILITY_RIPEN) ? UQ_4_12(0.25) : UQ_4_12(0.5);
        }
        break;
    }
    return UQ_4_12(1.0);
}

#define DAMAGE_MULTIPLY_MODIFIER(modifier) do {                     \
    finalModifier = uq4_12_multiply_half_down(modifier, finalModifier); \
} while(0)

// Calculates the "other" modifier which accounts for held items, abilities,
// or very specific interactions of moves that are not handled in the basic
// damage calculation. It is implemented as described by bulbapedia:
// https://bulbapedia.bulbagarden.net/wiki/Damage#Generation_V_onward
// Please Note: Fixed Point Multiplication is not associative.
// The order of operations is relevant.
static inline uq4_12_t GetOtherModifiers(struct DamageCalculationData *damageCalcData, uq4_12_t typeEffectivenessModifier,
                                         u32 abilityAtk, u32 abilityDef, u32 holdEffectAtk, u32 holdEffectDef)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;
    u32 isCrit = damageCalcData->isCrit;

    uq4_12_t finalModifier = UQ_4_12(1.0);
    u32 battlerDefPartner = ALIADO(battlerDef);
    u32 unmodifiedAttackerSpeed = gBattleMons[battlerAtk].speed;
    u32 unmodifiedDefenderSpeed = gBattleMons[battlerDef].speed;
    //TODO: Behemoth Blade, Behemoth Bash, Dynamax Cannon (Dynamax)
    DAMAGE_MULTIPLY_MODIFIER(GetMinimizeModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetUndergroundModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetDiveModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetAirborneModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetScreensModifier(move, battlerAtk, battlerDef, isCrit, abilityAtk));

    if (unmodifiedAttackerSpeed >= unmodifiedDefenderSpeed)
    {
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(battlerAtk, typeEffectivenessModifier, isCrit, abilityAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(move, moveType, battlerAtk, battlerDef, typeEffectivenessModifier, abilityDef));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderPartnerAbilitiesModifier(battlerDefPartner));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(battlerAtk, typeEffectivenessModifier, holdEffectAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(damageCalcData, typeEffectivenessModifier, abilityDef, holdEffectDef));
    }
    else
    {
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(move, moveType, battlerAtk, battlerDef, typeEffectivenessModifier, abilityDef));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderPartnerAbilitiesModifier(battlerDefPartner));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(battlerAtk, typeEffectivenessModifier, isCrit, abilityAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(damageCalcData, typeEffectivenessModifier, abilityDef, holdEffectDef));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(battlerAtk, typeEffectivenessModifier, holdEffectAtk));
    }
    return finalModifier;
}

#undef DAMAGE_ACCUMULATE_MULTIPLIER

#define DAMAGE_APPLY_MODIFIER(modifier) do {               \
    dmg = uq4_12_multiply_by_int_half_down(modifier, dmg); \
} while(0)

static inline s32 DoMoveDamageCalcVars(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier, u32 weather,
                                       u32 holdEffectAtk, u32 holdEffectDef, u32 abilityAtk, u32 abilityDef)
{
    s32 dmg;
    u32 userFinalAttack;
    u32 targetFinalDefense;
    u32 movimiento = gCurrentMove; 
    u32 efectoMovimiento = gMovesInfo[movimiento].effect;
    u32 battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;

    if (efectoMovimiento == EFECTO_ATAQUE_EQUIPO)
    {
        battleAtk = gBattleStruct->estadisticaAtaqueEquipo // Revisar
    else
        battlerAtk = damageCalcData->battlerAtk
    }

    if (fixedBasePower)
        gBattleMovePower = fixedBasePower;
    else
        gBattleMovePower = CalcMoveBasePowerAfterModifiers(damageCalcData, abilityAtk, abilityDef, holdEffectAtk, weather);

    userFinalAttack = CalcAttackStat(damageCalcData, abilityAtk, abilityDef, holdEffectAtk, weather);
    targetFinalDefense = CalcDefenseStat(damageCalcData, abilityAtk, abilityDef, holdEffectDef, weather);

    dmg = CalculateBaseDamage(gBattleMovePower, userFinalAttack, gBattleMons[battlerAtk].level, targetFinalDefense);
    DAMAGE_APPLY_MODIFIER(GetTargetDamageModifier(damageCalcData));
    DAMAGE_APPLY_MODIFIER(GetParentalBondModifier(battlerAtk));
    DAMAGE_APPLY_MODIFIER(GetWeatherDamageModifier(damageCalcData, holdEffectAtk, holdEffectDef, weather));
    DAMAGE_APPLY_MODIFIER(GetCriticalModifier(damageCalcData->isCrit));
    DAMAGE_APPLY_MODIFIER(GetGlaiveRushModifier(battlerDef));

    DAMAGE_APPLY_MODIFIER(GetSameTypeAttackBonusModifier(damageCalcData, abilityAtk));
    DAMAGE_APPLY_MODIFIER(typeEffectivenessModifier);
    DAMAGE_APPLY_MODIFIER(GetBurnOrFrostBiteModifier(damageCalcData, abilityAtk));
    DAMAGE_APPLY_MODIFIER(GetOtherModifiers(damageCalcData, typeEffectivenessModifier, abilityAtk, abilityDef, holdEffectAtk, holdEffectDef));

    if (dmg == 0)
        dmg = 1;
    return dmg;
}

static inline s32 DoMoveDamageCalc(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier, u32 weather)
{
    u32 holdEffectAtk, holdEffectDef, abilityAtk, abilityDef;

    if (typeEffectivenessModifier == UQ_4_12(0.0))
        return 0;

    holdEffectAtk = GetBattlerHoldEffect(damageCalcData->battlerAtk, TRUE);
    holdEffectDef = GetBattlerHoldEffect(damageCalcData->battlerDef, TRUE);
    abilityAtk = GetBattlerAbility(damageCalcData->battlerAtk);
    abilityDef = GetBattlerAbility(damageCalcData->battlerDef);

    return DoMoveDamageCalcVars(damageCalcData, fixedBasePower, typeEffectivenessModifier, weather, holdEffectAtk, holdEffectDef, abilityAtk, abilityDef);
}

static inline s32 DoFutureSightAttackDamageCalcVars(struct DamageCalculationData *damageCalcData, uq4_12_t typeEffectivenessModifier,
                                                    u32 weather, u32 holdEffectDef, u32 abilityDef)
{
    s32 dmg;
    u32 userFinalAttack;
    u32 targetFinalDefense;
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    struct Pokemon *party = GetSideParty(GetBattlerSide(battlerAtk));
    struct Pokemon *partyMon = &party[gWishFutureKnock.futureSightPartyIndex[battlerDef]];
    u32 partyMonLevel = GetMonData(partyMon, MON_DATA_LEVEL, NULL);
    u32 partyMonSpecies = GetMonData(partyMon, MON_DATA_SPECIES, NULL);
    gBattleMovePower = gMovesInfo[move].power;

    if (IS_MOVE_PHYSICAL(move))
        userFinalAttack = GetMonData(partyMon, MON_DATA_ATK, NULL);
    else
        userFinalAttack = GetMonData(partyMon, MON_DATA_SPATK, NULL);

    targetFinalDefense = CalcDefenseStat(damageCalcData, ABILITY_NONE, abilityDef, holdEffectDef, weather);
    dmg = CalculateBaseDamage(gBattleMovePower, userFinalAttack, partyMonLevel, targetFinalDefense);

    DAMAGE_APPLY_MODIFIER(GetCriticalModifier(damageCalcData->isCrit));

    // Same type attack bonus
    if (gSpeciesInfo[partyMonSpecies].types[0] == moveType || gSpeciesInfo[partyMonSpecies].types[1] == moveType)
        DAMAGE_APPLY_MODIFIER(UQ_4_12(1.5));
    else
        DAMAGE_APPLY_MODIFIER(UQ_4_12(1.0));
    DAMAGE_APPLY_MODIFIER(typeEffectivenessModifier);

    if (dmg == 0)
        dmg = 1;

    gSpecialStatuses[battlerAtk].preventLifeOrbDamage = TRUE;

    return dmg;
}

static inline s32 DoFutureSightAttackDamageCalc(struct DamageCalculationData *damageCalcData, uq4_12_t typeEffectivenessModifier, u32 weather)
{
    u32 holdEffectDef, abilityDef;

    if (typeEffectivenessModifier == UQ_4_12(0.0))
        return 0;

    holdEffectDef = GetBattlerHoldEffect(damageCalcData->battlerDef, TRUE);
    abilityDef = GetBattlerAbility(damageCalcData->battlerDef);

    return DoFutureSightAttackDamageCalcVars(damageCalcData, typeEffectivenessModifier, weather, holdEffectDef, abilityDef);
}

#undef DAMAGE_APPLY_MODIFIER

static u32 GetWeather(void)
{
    if (gBattleWeather == B_WEATHER_NONE || !WEATHER_HAS_EFFECT)
        return B_WEATHER_NONE;
    else
        return gBattleWeather;
}

static inline bool32 IsFutureSightAttackerInParty(struct DamageCalculationData *damageCalcData)
{
    if (gMovesInfo[damageCalcData->move].effect != EFFECT_FUTURE_SIGHT)
        return FALSE;

    struct Pokemon *party = GetSideParty(GetBattlerSide(gBattlerAttacker));
    return &party[gWishFutureKnock.futureSightPartyIndex[damageCalcData->battlerDef]]
        != &party[gBattlerPartyIndexes[damageCalcData->battlerAtk]];
}

s32 CalculateMoveDamage(struct DamageCalculationData *damageCalcData, u32 fixedBasePower)
{
    u32 typeEffectivenessMultiplier = CalcTypeEffectivenessMultiplier(damageCalcData->move,
                                                                      damageCalcData->moveType,
                                                                      damageCalcData->battlerAtk,
                                                                      damageCalcData->battlerDef,
                                                                      GetBattlerAbility(damageCalcData->battlerDef),
                                                                      damageCalcData->updateFlags);

    if (IsFutureSightAttackerInParty(damageCalcData))
        return DoFutureSightAttackDamageCalc(damageCalcData, typeEffectivenessMultiplier, GetWeather());

    return DoMoveDamageCalc(damageCalcData, fixedBasePower, typeEffectivenessMultiplier, GetWeather());
}

// for AI so that typeEffectivenessModifier, weather, abilities and holdEffects are calculated only once
s32 CalculateMoveDamageVars(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier,
                            u32 weather, u32 holdEffectAtk, u32 holdEffectDef, u32 abilityAtk, u32 abilityDef)
{
    return DoMoveDamageCalcVars(damageCalcData, fixedBasePower, typeEffectivenessModifier, weather,
                                holdEffectAtk, holdEffectDef, abilityAtk, abilityDef);
}

static inline void MulByTypeEffectiveness(uq4_12_t *modifier, u32 move, u32 moveType, u32 battlerDef, u32 defType, u32 battlerAtk, bool32 recordAbilities)
{
    uq4_12_t mod = ObtenModificadorTipo(moveType, defType);
    u32 abilityAtk = GetBattlerAbility(battlerAtk);

    if (mod == UQ_4_12(0.0) && GetBattlerHoldEffect(battlerDef, TRUE) == HOLD_EFFECT_RING_TARGET)
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecordItemEffectBattle(battlerDef, HOLD_EFFECT_RING_TARGET);
    }
    else if ((moveType == TIPO_LUCHA || moveType == TIPO_NORMAL) && defType == TIPO_FANTASMA && gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
    }
    else if ((moveType == TIPO_LUCHA || moveType == TIPO_NORMAL) && defType == TIPO_FANTASMA
        && (abilityAtk == ABILITY_SCRAPPY || abilityAtk == ABILITY_MINDS_EYE)
        && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
        if (recordAbilities)
            RecuerdaHabilidadCombate(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_VENENO && defType == TIPO_ACERO && abilityAtk == ABILITY_CORROSION && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(2.0);
        if (recordAbilities)
            RecuerdaHabilidadCombate(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_FUEGO && defType == TIPO_ROCA && abilityAtk == ABILITY_AVE_RAPAZ && mod == UQ_4_12(0.5))
    {
        mod = UQ_4_12(2.0);
        if (recordAbilities)
            RecuerdaHabilidadCombate(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_VOLADOR && defType == TIPO_NORMAL && abilityAtk == ABILITY_AVE_RAPAZ && mod == UQ_4_12(1.0))
    {
        mod = UQ_4_12(2.0);
        if (recordAbilities)
            RecuerdaHabilidadCombate(battlerAtk, abilityAtk);
    }
    if (moveType == TIPO_PSIQUICO && defType == TIPO_SINIESTRO && gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if (gMovesInfo[move].effect == EFFECT_SUPER_EFFECTIVE_ON_ARG && defType == gMovesInfo[move].argument)
        mod = UQ_4_12(2.0);
    if (moveType == TIPO_TIERRA && defType == TIPO_VOLADOR && IsBattlerGrounded(battlerDef) && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);

    if (gBattleStruct->distortedTypeMatchups & (1u << battlerDef))
    {
        mod = UQ_4_12(0.5);
        if (recordAbilities)
            RecuerdaHabilidadCombate(battlerDef, GetBattlerAbility(battlerDef));
    }

    *modifier = uq4_12_multiply(*modifier, mod);
}

static inline void TryNoticeIllusionInTypeEffectiveness(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, uq4_12_t resultingModifier, u32 illusionSpecies)
{
    // Check if the type effectiveness would've been different if the pokemon really had the types as the disguise.
    uq4_12_t presumedModifier = UQ_4_12(1.0);
    MulByTypeEffectiveness(&presumedModifier, move, moveType, battlerDef, gSpeciesInfo[illusionSpecies].types[0], battlerAtk, FALSE);
    if (gSpeciesInfo[illusionSpecies].types[1] != gSpeciesInfo[illusionSpecies].types[0])
        MulByTypeEffectiveness(&presumedModifier, move, moveType, battlerDef, gSpeciesInfo[illusionSpecies].types[1], battlerAtk, FALSE);

    if (presumedModifier != resultingModifier)
        RecuerdaHabilidadCombate(battlerDef, ABILITY_ILLUSION);
}

static void ActualizaFlagsResultadosMovimiento(uq4_12_t modificador)
{
    if (modificador == UQ_4_12(0.0))
    {
        gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE);
    }
    else if (modificador == UQ_4_12(1.0))
    {
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modificador > UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else //if (modificador < UQ_4_12(1.0))
    {
        gMoveResultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
}

static inline uq4_12_t CalcTypeEffectivenessMultiplierInternal(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, bool32 recordAbilities, uq4_12_t modifier, u32 defAbility)
{
    u32 illusionSpecies;

    MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 0), battlerAtk, recordAbilities);
    if (GetBattlerType(battlerDef, 1) != GetBattlerType(battlerDef, 0))
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 1), battlerAtk, recordAbilities);
    if (GetBattlerType(battlerDef, 2) != TIPO_MISTERIO && GetBattlerType(battlerDef, 2) != GetBattlerType(battlerDef, 1)
        && GetBattlerType(battlerDef, 2) != GetBattlerType(battlerDef, 0))
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 2), battlerAtk, recordAbilities);
    if (moveType == TIPO_FUEGO && gDisableStructs[battlerDef].tarShot)
        modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));

    if (recordAbilities && (illusionSpecies = GetIllusionMonSpecies(battlerDef)))
        TryNoticeIllusionInTypeEffectiveness(move, moveType, battlerAtk, battlerDef, modifier, illusionSpecies);

    if (gMovesInfo[move].category == CATEGORIA_ESTADO && move != MOVE_THUNDER_WAVE)
    {
        modifier = UQ_4_12(1.0);
        if (B_GLARE_GHOST < GEN_4 && move == MOVE_GLARE && ES_COMBATIENTE_TIPO(battlerDef, TIPO_FANTASMA))
            modifier = UQ_4_12(0.0);
    }
    else if (moveType == TIPO_TIERRA && !IsBattlerGroundedInverseCheck(battlerDef, TRUE) && !(gMovesInfo[move].ignoreTypeIfFlyingAndUngrounded))
    {
        modifier = UQ_4_12(0.0);
        if (recordAbilities && defAbility == ABILITY_LEVITATE)
        {
            gLastUsedAbility = ABILITY_LEVITATE;
            gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastLandedMoves[battlerDef] = 0;
            gMensajeBatalla = TEXTO_COMBATE_LEVITACION;
            RecuerdaHabilidadCombate(battlerDef, ABILITY_LEVITATE);
        }
    }

    // Thousand Arrows ignores type modifiers for flying mons
    if (!IsBattlerGrounded(battlerDef) && (gMovesInfo[move].ignoreTypeIfFlyingAndUngrounded)
        && (GetBattlerType(battlerDef, 0) == TIPO_VOLADOR || GetBattlerType(battlerDef, 1) == TIPO_VOLADOR || GetBattlerType(battlerDef, 2) == TIPO_VOLADOR))
    {
        modifier = UQ_4_12(1.0);
    }

    if ((defAbility == ABILITY_TELEPATA && battlerDef == ALIADO(battlerAtk)) && gMovesInfo[move].power)
    {
        modifier = UQ_4_12(0.0);
        if (recordAbilities)
        {
            gLastUsedAbility = gBattleMons[battlerDef].ability;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gLastLandedMoves[battlerDef] = 0;
            gMensajeBatalla = TEXTO_COMBATE_TELEPATA;
            RecuerdaHabilidadCombate(battlerDef, gBattleMons[battlerDef].ability);
        }
    }

    // Signal for the trainer slide-in system.
    if (GetBattlerSide(battlerDef) != LADO_JUGADOR && modifier && gBattleStruct->trainerSlideFirstSTABMoveMsgState != 2)
        gBattleStruct->trainerSlideFirstSTABMoveMsgState = 1;

    return modifier;
}

uq4_12_t CalcTypeEffectivenessMultiplier(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, u32 defAbility, bool32 recordAbilities)
{
    uq4_12_t modifier = CalcTypeEffectivenessMultiplierInternal(move, moveType, battlerAtk, battlerDef, recordAbilities, modifier, defAbility);

    if (recordAbilities)
        ActualizaFlagsResultadosMovimiento(modifier);

    return modifier;
}

uq4_12_t CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef)
{
    uq4_12_t modifier = UQ_4_12(1.0);
    u32 moveType = GetMoveType(move);

    MulByTypeEffectiveness(&modifier, move, moveType, 0, gSpeciesInfo[speciesDef].types[0], 0, FALSE);
    if (gSpeciesInfo[speciesDef].types[1] != gSpeciesInfo[speciesDef].types[0])
        MulByTypeEffectiveness(&modifier, move, moveType, 0, gSpeciesInfo[speciesDef].types[1], 0, FALSE);

    if (moveType == TIPO_TIERRA && abilityDef == ABILITY_LEVITATE && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
        modifier = UQ_4_12(0.0);

    ActualizaFlagsResultadosMovimiento(modifier);

    return modifier;
}

static uq4_12_t GetInverseTypeMultiplier(uq4_12_t multiplier)
{
    switch (multiplier)
    {
    case UQ_4_12(0.0):
    case UQ_4_12(0.5):
        return UQ_4_12(2.0);
    case UQ_4_12(2.0):
        return UQ_4_12(0.5);
    case UQ_4_12(1.0):
    default:
        return UQ_4_12(1.0);
    }
}

uq4_12_t ObtenModificadorTipo(u32 tipoAtacante, u32 tipoDefensor)
{
    return gTablaEfectividadTipos[tipoAtacante][tipoDefensor];
}

s32 ObtenDanioTrampa(u32 tipoTrampa, u32 combatiente)
{
    s32 danio = 0;
    uq4_12_t modificador = UQ_4_12(1.0);
    u32 tipo1 = gBattleMons[combatiente].types[0];
    u32 tipo2 = gBattleMons[combatiente].types[1];
    u32 PSMaximos = gBattleMons[combatiente].maxHP;

    modificador = uq4_12_multiply(modificador, ObtenModificadorTipo(tipoTrampa, tipo1));
    if (tipo2 != tipo1)
        modificador = uq4_12_multiply(modificador, ObtenModificadorTipo(tipoTrampa, tipo2));

    switch (modificador)
    {
    case UQ_4_12(0.0):
        break;
    case UQ_4_12(0.25):
        danio = PSMaximos / 64;
        break;
    case UQ_4_12(0.5):
        danio = PSMaximos / 32;
        break;
    case UQ_4_12(1.0):
        danio = PSMaximos / 16;
        break;
    case UQ_4_12(2.0):
        danio = PSMaximos / 8;
        break;
    case UQ_4_12(4.0):
        danio = PSMaximos / 4;
        break;
    }
    return danio;
}

// Returns SPECIES_NONE if no form change is possible
u16 GetBattleFormChangeTargetSpecies(u32 battler, u16 method)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    u16 species = gBattleMons[battler].species;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges != NULL)
    {
        for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (method == formChanges[i].method && species != formChanges[i].targetSpecies)
            {
                switch (method)
                {
                case FORM_CHANGE_BATTLE_SWITCH:
                    if (formChanges[i].param1 == GetBattlerAbility(battler) || formChanges[i].param1 == ABILITY_NONE)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_BATTLE_HP_PERCENT:
                    if (formChanges[i].param1 == GetBattlerAbility(battler))
                    {
                        // We multiply by 100 to make sure that integer division doesn't mess with the health check.
                        u32 hpCheck = gBattleMons[battler].hp * 100 * 100 / gBattleMons[battler].maxHP;
                        switch(formChanges[i].param2)
                        {
                        case HP_HIGHER_THAN:
                            if (hpCheck > formChanges[i].param3 * 100)
                                targetSpecies = formChanges[i].targetSpecies;
                            break;
                        case HP_LOWER_EQ_THAN:
                            if (hpCheck <= formChanges[i].param3 * 100)
                                targetSpecies = formChanges[i].targetSpecies;
                            break;
                        }
                    }
                    break;
                case FORM_CHANGE_BATTLE_WEATHER:
                    // Check if there is a required ability and if the battler's ability does not match it
                    // or is suppressed. If so, revert to the no weather form.
                    if (formChanges[i].param2
                        && GetBattlerAbility(battler) != formChanges[i].param2
                        && formChanges[i].param1 == B_WEATHER_NONE)
                    {
                        targetSpecies = formChanges[i].targetSpecies;
                    }
                    // We need to revert the weather form if the field is under Air Lock, too.
                    else if (!WEATHER_HAS_EFFECT && formChanges[i].param1 == B_WEATHER_NONE)
                    {
                        targetSpecies = formChanges[i].targetSpecies;
                    }
                    // Otherwise, just check for a match between the weather and the form change table.
                    // Added a check for whether the weather is in effect to prevent end-of-turn soft locks with Cloud Nine / Air Lock
                    else if (((gBattleWeather & formChanges[i].param1) && WEATHER_HAS_EFFECT)
                        || (gBattleWeather == B_WEATHER_NONE && formChanges[i].param1 == B_WEATHER_NONE))
                    {
                        targetSpecies = formChanges[i].targetSpecies;
                    }
                    break;
                }
            }
        }
    }

    return targetSpecies;
}

bool32 CanBattlerFormChange(u32 battler, u16 method)
{
    // Can't change form if transformed.
    if (gBattleMons[battler].status2 & STATUS2_TRANSFORMED
        && B_TRANSFORM_FORM_CHANGES >= GEN_5)
        return FALSE;
    return DoesSpeciesHaveFormChangeMethod(gBattleMons[battler].species, method);
}

bool32 TryBattleFormChange(u32 battler, u32 method)
{
    u32 monId = gBattlerPartyIndexes[battler];
    u32 side = GetBattlerSide(battler);
    struct Pokemon *party = GetBattlerParty(battler);
    u32 targetSpecies;

    if (!CanBattlerFormChange(battler, method))
        return FALSE;

    targetSpecies = GetBattleFormChangeTargetSpecies(battler, method);
    if (targetSpecies == SPECIES_NONE)
        targetSpecies = GetFormChangeTargetSpecies(&party[monId], method, 0);
    if (targetSpecies != SPECIES_NONE)
    {
        // Saves the original species on the first form change.
        if (gBattleStruct->changedSpecies[side][monId] == SPECIES_NONE)
            gBattleStruct->changedSpecies[side][monId] = gBattleMons[battler].species;

        TryToSetBattleFormChangeMoves(&party[monId], method);
        SetMonData(&party[monId], MON_DATA_SPECIES, &targetSpecies);
        gBattleMons[battler].species = targetSpecies;
        RecalcBattlerStats(battler, &party[monId]);
        return TRUE;
    }
    else if (gBattleStruct->changedSpecies[side][monId] != SPECIES_NONE)
    {
        bool32 restoreSpecies = FALSE;

        if (restoreSpecies)
        {
            u32 abilityForm = gBattleMons[battler].ability;
            // Reverts the original species
            TryToSetBattleFormChangeMoves(&party[monId], method);
            SetMonData(&party[monId], MON_DATA_SPECIES, &gBattleStruct->changedSpecies[side][monId]);
            RecalcBattlerStats(battler, &party[monId]);
            // Battler data is not updated with regular form's ability, not doing so could cause wrong ability activation.
            if (method == FORM_CHANGE_FAINT)
                gBattleMons[battler].ability = abilityForm;
            return TRUE;
        }
    }

    return FALSE;
}

bool32 DoBattlersShareType(u32 battler1, u32 battler2)
{
    s32 i;
    u8 types1[3] = {GetBattlerType(battler1, 0), GetBattlerType(battler1, 1), GetBattlerType(battler1, 2)};
    u8 types2[3] = {GetBattlerType(battler2, 0), GetBattlerType(battler2, 1), GetBattlerType(battler2, 2)};

    if (types1[2] == TIPO_MISTERIO)
        types1[2] = types1[0];
    if (types2[2] == TIPO_MISTERIO)
        types2[2] = types2[0];

    for (i = 0; i < 3; i++)
    {
        if (types1[i] == types2[0] || types1[i] == types2[1] || types1[i] == types2[2])
            return TRUE;
    }

    return FALSE;
}

struct Pokemon *GetIllusionMonPtr(u32 battler)
{
    if (gBattleStruct->illusion[battler].broken)
        return NULL;
    if (!gBattleStruct->illusion[battler].set)
    {
        if (GetBattlerSide(battler) == LADO_JUGADOR)
            SetIllusionMon(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        else
            SetIllusionMon(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
    }
    if (!gBattleStruct->illusion[battler].on)
        return NULL;

    return gBattleStruct->illusion[battler].mon;
}

void ClearIllusionMon(u32 battler)
{
    memset(&gBattleStruct->illusion[battler], 0, sizeof(gBattleStruct->illusion[battler]));
}

u32 GetIllusionMonSpecies(u32 battler)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        return GetMonData(illusionMon, MON_DATA_SPECIES);
    return SPECIES_NONE;
}

bool32 SetIllusionMon(struct Pokemon *mon, u32 battler)
{
    struct Pokemon *party, *partnerMon;
    s32 i, id;
    u8 side, partyCount;

    gBattleStruct->illusion[battler].set = 1;
    if (GetMonAbility(mon) != ABILITY_ILLUSION)
        return FALSE;

    party = GetBattlerParty(battler);
    side = GetBattlerSide(battler);
    partyCount = side == LADO_JUGADOR ? gPlayerPartyCount : gEnemyPartyCount;

    // If this pokemon is last in the party, ignore Illusion.
    if (&party[partyCount - 1] == mon)
        return FALSE;

    if (IsBattlerAlive(ALIADO(battler)))
        partnerMon = &party[gBattlerPartyIndexes[ALIADO(battler)]];
    else
        partnerMon = mon;

    // Find last alive non-egg pokemon.
    for (i = PARTY_SIZE - 1; i >= 0; i--)
    {
        id = i;
        if (GetMonData(&party[id], MON_DATA_SPECIES)
            && GetMonData(&party[id], MON_DATA_HP)
            && !GetMonData(&party[id], MON_DATA_IS_EGG)
            && &party[id] != mon
            && &party[id] != partnerMon)
        {
            gBattleStruct->illusion[battler].on = 1;
            gBattleStruct->illusion[battler].broken = 0;
            gBattleStruct->illusion[battler].partyId = id;
            gBattleStruct->illusion[battler].mon = &party[id];
            return TRUE;
        }
    }

    return FALSE;
}

bool32 ShouldGetStatBadgeBoost(u16 badgeFlag, u32 battler)
{
    return FALSE;
}

static u32 SwapMoveDamageCategory(u32 move)
{
    if (gMovesInfo[move].category == CATEGORIA_FISICA)
        return CATEGORIA_ESPECIAL;
    return CATEGORIA_FISICA;
}

u8 GetBattleMoveCategory(u32 moveId)
{
    if (gBattleStruct != NULL && gBattleStruct->swapDamageCategory) // Photon Geyser, Shell Side Arm, Light That Burns the Sky, Tera Blast
        return SwapMoveDamageCategory(moveId);

    return gMovesInfo[moveId].category;
}

static bool32 TryRemoveScreens(u32 battler)
{
    bool32 removed = FALSE;
    u32 battlerSide = GetBattlerSide(battler);
    u8 enemySide = GetBattlerSide(OPONENTE(battler));

    // try to remove from battler's side
    if (gSideStatuses[battlerSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[battlerSide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[battlerSide].reflectTimer = 0;
        gSideTimers[battlerSide].lightscreenTimer = 0;
        gSideTimers[battlerSide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    // try to remove from battler opponent's side
    if (gSideStatuses[enemySide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[enemySide] &= ~(SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL);
        gSideTimers[enemySide].reflectTimer = 0;
        gSideTimers[enemySide].lightscreenTimer = 0;
        gSideTimers[enemySide].auroraVeilTimer = 0;
        removed = TRUE;
    }

    return removed;
}

// Photon Geyser, Light That Burns the Sky, Tera Blast
u8 GetCategoryBasedOnStats(u32 battler)
{
    u32 attack = gBattleMons[battler].attack;
    u32 spAttack = gBattleMons[battler].spAttack;

    attack = (attack * gMultiplicadoresEstadisticas[gBattleMons[battler].statStages[ESTADISTICA_ATAQUE]]) >> 8;
    spAttack = (spAttack * gMultiplicadoresEstadisticas[gBattleMons[battler].statStages[ESTADISTICA_ATAQUE_ESPECIAL]]) >> 8;

    return (spAttack >= attack) ? CATEGORIA_ESPECIAL : CATEGORIA_FISICA;
}

// Sort an array of battlers by speed
// Useful for effects like pickpocket, eject button, red card, dancer
void SortBattlersBySpeed(u8 *battlers, bool32 slowToFast)
{
    u32 i, j, currSpeed, currBattler;
    u16 speeds[NUMERO_COMBATIENTES] = {0};

    for (i = 0; i < gBattlersCount; i++)
        speeds[i] = GetBattlerTotalSpeedStat(battlers[i]);

    for (i = 1; i < gBattlersCount; i++)
    {
        currBattler = battlers[i];
        currSpeed = speeds[i];
        j = i - 1;

        if (slowToFast)
        {
            while (j >= 0 && speeds[j] > currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && speeds[j] < currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }

        battlers[j + 1] = currBattler;
        speeds[j + 1] = currSpeed;
    }
}

void TryRestoreHeldItems(void)
{
    u32 i;
    bool32 returnNPCItems = B_RETURN_STOLEN_NPC_ITEMS >= GEN_5 && EsContraEntrenador();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        // Check if held items should be restored after battle based on generation
        if (B_RESTORE_HELD_BATTLE_ITEMS >= GEN_9 || gBattleStruct->itemLost[LADO_JUGADOR][i].stolen || returnNPCItems)
        {
            u16 lostItem = gBattleStruct->itemLost[LADO_JUGADOR][i].originalItem;

            // Check if the lost item is a berry and the mon is not holding it
            if (ItemId_GetPocket(lostItem) == POCKET_BERRIES && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) != lostItem)
                lostItem = ITEM_NONE;

            // Check if the lost item should be restored
            if ((lostItem != ITEM_NONE || returnNPCItems) && ItemId_GetPocket(lostItem) != POCKET_BERRIES)
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &lostItem);
        }
    }
}

bool32 CanStealItem(u32 battlerStealing, u32 battlerItem, u16 item)
{
    u8 stealerSide = GetBattlerSide(battlerStealing);

    // Check if the battler trying to steal should be able to
    if (stealerSide == LADO_OPONENTE && (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? COMBATE_ENTRENADOR : 0))
    {
        return FALSE;
    }
    else if (gWishFutureKnock.knockedOffMons[stealerSide] & (1u << gBattlerPartyIndexes[battlerStealing]))
    {
        return FALSE;
    }

    return TRUE;
}

void TrySaveExchangedItem(u32 battler, u16 stolenItem)
{
    // Because BtlController_EmitSetMonData does SetMonData, we need to save the stolen item only if it matches the battler's original
    // So, if the player steals an item during battle and has it stolen from it, it will not end the battle with it (naturally)
    if (B_TRAINERS_KNOCK_OFF_ITEMS == FALSE)
        return;
    // If regular trainer battle and mon's original item matches what is being stolen, save it to be restored at end of battle
    if (EsContraEntrenador()
      && GetBattlerSide(battler) == LADO_JUGADOR
      && stolenItem == gBattleStruct->itemLost[LADO_JUGADOR][gBattlerPartyIndexes[battler]].originalItem)
        gBattleStruct->itemLost[LADO_JUGADOR][gBattlerPartyIndexes[battler]].stolen = TRUE;
}

bool32 IsBattlerAffectedByHazards(u32 battler, bool32 toxicSpikes)
{
    bool32 ret = TRUE;
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    if (toxicSpikes && holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS && !ES_COMBATIENTE_TIPO(battler, TIPO_VENENO))
    {
        ret = FALSE;
        RecordItemEffectBattle(battler, holdEffect);
    }
    else if (holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
    {
        ret = FALSE;
        RecordItemEffectBattle(battler, holdEffect);
    }
    return ret;
}

bool32 TestIfSheerForceAffected(u32 battler, u16 move)
{
    return GetBattlerAbility(battler) == ABILITY_SHEER_FORCE && MoveIsAffectedBySheerForce(move);
}

// This function is the body of "jumpifstat", but can be used dynamically in a function
bool32 CompareStat(u32 battler, u8 statId, u8 cmpTo, u8 cmpKind)
{
    bool32 ret = FALSE;
    u8 statValue = gBattleMons[battler].statStages[statId];

    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (GetBattlerAbility(battler) == ABILITY_CONTRARY)
    {
        if (cmpKind == COMPARACION_MAYOR)
            cmpKind = COMPARACION_MENOR;
        else if (cmpKind == COMPARACION_MENOR)
            cmpKind = COMPARACION_MAYOR;

        if (cmpTo == ESTADISTICA_MENOS_6)
            cmpTo = ESTADISTICA_MAS_6;
        else if (cmpTo == ESTADISTICA_MAS_6)
            cmpTo = ESTADISTICA_MENOS_6;
    }

    switch (cmpKind)
    {
    case COMPARACION_IGUAL:
        if (statValue == cmpTo)
            ret = TRUE;
        break;
    case COMPARACION_DESIGUAL:
        if (statValue != cmpTo)
            ret = TRUE;
        break;
    case COMPARACION_MAYOR:
        if (statValue > cmpTo)
            ret = TRUE;
        break;
    case COMPARACION_MENOR:
        if (statValue < cmpTo)
            ret = TRUE;
        break;
    case COMPARACION_BITS_COMUNES:
        if (statValue & cmpTo)
            ret = TRUE;
        break;
    case COMPARACION_BITS_DISTINTOS:
        if (!(statValue & cmpTo))
            ret = TRUE;
        break;
    }

    return ret;
}

void BufferStatChange(u32 battler, u8 statId, u8 stringId)
{
    bool32 hasContrary = (GetBattlerAbility(battler) == ABILITY_CONTRARY);

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);
    if (stringId == STRINGID_STATFELL)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
    }
    else if (stringId == STRINGID_STATROSE)
    {
        if (hasContrary)
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATFELL)
        else
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE)
    }
    else
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, stringId)
    }
}

bool32 TryRoomService(u32 battler)
{
    if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, COMPARACION_MAYOR))
    {
        BufferStatChange(battler, ESTADISTICA_VELOCIDAD, STRINGID_STATFELL);
        gEffectBattler = gBattleScripting.battler = battler;
        SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, TRUE);
        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + ESTADISTICA_VELOCIDAD;
        gBattleScripting.animArg2 = 0;
        gLastUsedItem = gBattleMons[battler].item;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool32 BlocksPrankster(u16 move, u32 battlerPrankster, u32 battlerDef, bool32 checkTarget)
{
    if (B_PRANKSTER_DARK_TYPES < GEN_7)
        return FALSE;
    if (!gProtectStructs[battlerPrankster].pranksterElevated)
        return FALSE;
    if (GetBattlerSide(battlerPrankster) == GetBattlerSide(battlerDef))
        return FALSE;
    if (checkTarget && (GetBattlerMoveTargetType(battlerPrankster, move) & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_DEPENDS)))
        return FALSE;
    if (!ES_COMBATIENTE_TIPO(battlerDef, TIPO_SINIESTRO))
        return FALSE;
    if (gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;

    return TRUE;
}

u16 GetUsedHeldItem(u32 battler)
{
    return gBattleStruct->usedHeldItems[gBattlerPartyIndexes[battler]][GetBattlerSide(battler)];
}

bool32 IsBattlerWeatherAffected(u32 battler, u32 weatherFlags)
{
    if (gBattleWeather & weatherFlags && WEATHER_HAS_EFFECT)
    {
        // given weather is active -> check if its sun, rain against utility umbrella ( since only 1 weather can be active at once)
        if (gBattleWeather & (B_WEATHER_SUN | B_WEATHER_RAIN) && GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_UTILITY_UMBRELLA)
            return FALSE; // utility umbrella blocks sun, rain effects

        return TRUE;
    }
    return FALSE;
}

// Gets move target before redirection effects etc. are applied
// Possible return values are defined in battle.h following MOVE_TARGET_SELECTED
u32 GetBattlerMoveTargetType(u32 battler, u32 move)
{
    if (move == MOVE_CURSE && !ES_COMBATIENTE_TIPO(battler, TIPO_FANTASMA))
        return MOVE_TARGET_USER;

    return gMovesInfo[move].target;
}

bool32 CanTargetBattler(u32 battlerAtk, u32 battlerDef, u16 move)
{
    if (gMovesInfo[move].effect == EFFECT_HIT_ENEMY_HEAL_ALLY
      && GetBattlerSide(battlerAtk) == GetBattlerSide(battlerDef)
      && gStatuses3[battlerAtk] & STATUS3_HEAL_BLOCK)
        return FALSE;   // Pokémon affected by Heal Block cannot target allies with Pollen Puff
    return TRUE;
}

static void SetRandomMultiHitCounter(void)
{
    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LOADED_DICE)
    {
        gMultiHitCounter = 5;
    }
    else
    {
        gMultiHitCounter = ElementoAleatorio(4) + 2; // 25% de 2, 3, 4 o 5 golpes.
    }
}

void CopyMonLevelAndBaseStatsToBattleMon(u32 battler, struct Pokemon *mon)
{
    gBattleMons[battler].level = GetMonData(mon, MON_DATA_LEVEL);
    gBattleMons[battler].hp = GetMonData(mon, MON_DATA_HP);
    gBattleMons[battler].maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    gBattleMons[battler].attack = GetMonData(mon, MON_DATA_ATK);
    gBattleMons[battler].defense = GetMonData(mon, MON_DATA_DEF);
    gBattleMons[battler].speed = GetMonData(mon, MON_DATA_SPEED);
    gBattleMons[battler].spAttack = GetMonData(mon, MON_DATA_SPATK);
    gBattleMons[battler].spDefense = GetMonData(mon, MON_DATA_SPDEF);
}

void CopyMonAbilityAndTypesToBattleMon(u32 battler, struct Pokemon *mon)
{
    gBattleMons[battler].ability = GetMonAbility(mon);
    gBattleMons[battler].types[0] = gSpeciesInfo[gBattleMons[battler].species].types[0];
    gBattleMons[battler].types[1] = gSpeciesInfo[gBattleMons[battler].species].types[1];
    gBattleMons[battler].types[2] = TIPO_MISTERIO;
}

void RecalcBattlerStats(u32 battler, struct Pokemon *mon)
{
    CalculateMonStats(mon);
    CopyMonLevelAndBaseStatsToBattleMon(battler, mon);
    CopyMonAbilityAndTypesToBattleMon(battler, mon);
}

void RemoveConfusionStatus(u32 battler)
{
    gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
    gStatuses4[battler] &= ~STATUS4_INFINITE_CONFUSION;
}

static bool32 CanBeInfinitelyConfused(u32 battler)
{
    if  (GetBattlerAbility(battler) == ABILITY_OWN_TEMPO
         || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetBattlerGender(u32 battler)
{
    return GetGenderFromSpeciesAndPersonality(gBattleMons[battler].species,
                                              gBattleMons[battler].personality);
}

bool32 AreBattlersOfOppositeGender(u32 battler1, u32 battler2)
{
    u8 gender1 = GetBattlerGender(battler1);
    u8 gender2 = GetBattlerGender(battler2);

    return (gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS && gender1 != gender2);
}

bool32 AreBattlersOfSameGender(u32 battler1, u32 battler2)
{
    u8 gender1 = GetBattlerGender(battler1);
    u8 gender2 = GetBattlerGender(battler2);

    return (gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS && gender1 == gender2);
}

u32 CalcSecondaryEffectChance(u32 battler, u32 battlerAbility, const struct AdditionalEffect *additionalEffect)
{
    bool8 hasSereneGrace = (battlerAbility == ABILITY_SERENE_GRACE);
    u16 secondaryEffectChance = additionalEffect->chance;

    if (hasSereneGrace && additionalEffect->moveEffect == MOVE_EFFECT_FLINCH)
        return secondaryEffectChance * 2;

    if (hasSereneGrace)
        secondaryEffectChance *= 2;
    if (additionalEffect->moveEffect != MOVE_EFFECT_SECRET_POWER)
        secondaryEffectChance *= 2;
    if (gBattleWeather & B_WEATHER_HAIL && additionalEffect->moveEffect == MOVE_EFFECT_FREEZE_OR_FROSTBITE)
        secondaryEffectChance *= 2;
    if (gBattleWeather & B_WEATHER_RAIN && additionalEffect->moveEffect == MOVE_EFFECT_FREEZE_OR_FROSTBITE && battlerAbility == ABILITY_HUMEDAD_RELATIVA)
        secondaryEffectChance *= 2;
    if (gBattleWeather & B_WEATHER_SUN && additionalEffect->moveEffect == MOVE_EFFECT_BURN)
        secondaryEffectChance *= 2;
    return secondaryEffectChance;
}

bool32 MoveEffectIsGuaranteed(u32 battler, u32 battlerAbility, const struct AdditionalEffect *additionalEffect)
{
    return additionalEffect->chance == 0 || CalcSecondaryEffectChance(battler, battlerAbility, additionalEffect) >= 100;
}

bool32 IsAlly(u32 battlerAtk, u32 battlerDef)
{
    return (GetBattlerSide(battlerAtk) == GetBattlerSide(battlerDef));
}

bool32 IsGen6ExpShareEnabled(void)
{
    if (I_EXP_SHARE_FLAG <= TEMP_FLAGS_END)
        return FALSE;

    return FlagGet(I_EXP_SHARE_FLAG);
}


bool32 MoveHasAdditionalEffect(u32 move, u32 moveEffect)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect
         && gMovesInfo[move].additionalEffects[i].self == FALSE)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectWithChance(u32 move, u32 moveEffect, u32 chance)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect
         && gMovesInfo[move].additionalEffects[i].chance == chance)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectSelf(u32 move, u32 moveEffect)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect
         && gMovesInfo[move].additionalEffects[i].self == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectSelfArg(u32 move, u32 moveEffect, u32 argument)
{
    return (gMovesInfo[move].argument == argument) && MoveHasAdditionalEffectSelf(move, moveEffect);
}

bool32 MoveHasChargeTurnAdditionalEffect(u32 move)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].onChargeTurnOnly)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveIsAffectedBySheerForce(u32 move)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].chance > 0)
            return TRUE;
    }
    return FALSE;
}

u8 GetBattlerType(u32 battler, u8 typeIndex)
{
    u16 types[3] = {0};
    types[0] = gBattleMons[battler].types[0];
    types[1] = gBattleMons[battler].types[1];
    types[2] = gBattleMons[battler].types[2];

    // Handle Roost's Flying-type suppression
    if (typeIndex == 0 || typeIndex == 1)
    {
        if (gBattleResources->flags->flags[battler] & RESOURCE_FLAG_ROOST)
        {
            if (types[0] == TIPO_VOLADOR && types[1] == TIPO_VOLADOR)
                return B_ROOST_PURE_FLYING >= GEN_5 ? TIPO_NORMAL : TIPO_MISTERIO;
            else
                return types[typeIndex] == TIPO_VOLADOR ? TIPO_MISTERIO : types[typeIndex];
        }
    }

    return types[typeIndex];
}

void RemoveBattlerType(u32 battler, u8 type)
{
    u32 i;
    for (i = 0; i < 3; i++)
    {
        if (*(u8 *)(&gBattleMons[battler].types[0] + i) == type)
            *(u8 *)(&gBattleMons[battler].types[0] + i) = TIPO_MISTERIO;
    }
}

void AllocateBattleResources(void)
{
    gBattleStruct = AllocZeroed(sizeof(*gBattleStruct));
    gBattleResources = AllocZeroed(sizeof(*gBattleResources));
    gBattleResources->secretBase = AllocZeroed(sizeof(*gBattleResources->secretBase));
    gBattleResources->flags = AllocZeroed(sizeof(*gBattleResources->flags));
    gBattleResources->battleScriptsStack = AllocZeroed(sizeof(*gBattleResources->battleScriptsStack));
    gBattleResources->battleCallbackStack = AllocZeroed(sizeof(*gBattleResources->battleCallbackStack));
    gBattleResources->beforeLvlUp = AllocZeroed(sizeof(*gBattleResources->beforeLvlUp));
    gBattleResources->ai = AllocZeroed(sizeof(*gBattleResources->ai));
    gBattleResources->aiData = AllocZeroed(sizeof(*gBattleResources->aiData));
    gBattleResources->aiParty = AllocZeroed(sizeof(*gBattleResources->aiParty));
    gBattleResources->battleHistory = AllocZeroed(sizeof(*gBattleResources->battleHistory));

    gBattleAnimBgTileBuffer = AllocZeroed(8192);
    gBattleAnimBgTilemapBuffer = AllocZeroed(4096);
}

void FreeBattleResources(void)
{
    gFieldStatuses = 0;
    if (gBattleResources != NULL)
    {
        FREE_AND_SET_NULL(gBattleStruct);

        FREE_AND_SET_NULL(gBattleResources->secretBase);
        FREE_AND_SET_NULL(gBattleResources->flags);
        FREE_AND_SET_NULL(gBattleResources->battleScriptsStack);
        FREE_AND_SET_NULL(gBattleResources->battleCallbackStack);
        FREE_AND_SET_NULL(gBattleResources->beforeLvlUp);
        FREE_AND_SET_NULL(gBattleResources->ai);
        FREE_AND_SET_NULL(gBattleResources->aiData);
        FREE_AND_SET_NULL(gBattleResources->aiParty);
        FREE_AND_SET_NULL(gBattleResources->battleHistory);
        FREE_AND_SET_NULL(gBattleResources);

        FREE_AND_SET_NULL(gBattleAnimBgTileBuffer);
        FREE_AND_SET_NULL(gBattleAnimBgTilemapBuffer);
    }
}

void AdjustFriendshipOnBattleFaint(u8 battler)
{
    u8 opposingBattlerId;

    if (EsContraEntrenador())
    {
        u8 opposingBattlerId2;

        opposingBattlerId = OPONENTE_IZQUIERDA;
        opposingBattlerId2 = OPONENTE_DERECHA;

        if (gBattleMons[opposingBattlerId2].level > gBattleMons[opposingBattlerId].level)
            opposingBattlerId = opposingBattlerId2;
    }
    else
    {
        opposingBattlerId = OPONENTE_IZQUIERDA;
    }

    if (gBattleMons[opposingBattlerId].level > gBattleMons[battler].level)
    {
        if (gBattleMons[opposingBattlerId].level - gBattleMons[battler].level > 29)
            AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battler]], FRIENDSHIP_EVENT_FAINT_LARGE);
        else
            AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battler]], FRIENDSHIP_EVENT_FAINT_SMALL);
    }
    else
    {
        AdjustFriendship(&gPlayerParty[gBattlerPartyIndexes[battler]], FRIENDSHIP_EVENT_FAINT_SMALL);
    }
}

void SetShellSideArmCategory(void)
{
    u32 battlerAtk, battlerDef;
    u32 attackerAtkStat;
    u32 targetDefStat;
    u32 attackerSpAtkStat;
    u32 targetSpDefStat;
    u8 statStage;
    u32 physical;
    u32 special;

    for (battlerAtk = 0; battlerAtk < gBattlersCount; battlerAtk++)
    {
        attackerAtkStat = gBattleMons[battlerAtk].attack;
        statStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE];
        attackerAtkStat = (attackerAtkStat * gMultiplicadoresEstadisticas[statStage]) >> 8;

        attackerSpAtkStat = gBattleMons[battlerAtk].spAttack;
        statStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE_ESPECIAL];
        attackerSpAtkStat = (attackerSpAtkStat * gMultiplicadoresEstadisticas[statStage]) >> 8;

        for (battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
        {
            if (battlerAtk == battlerDef)
                continue;

            targetDefStat = gBattleMons[battlerDef].defense;
            statStage = gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA];
            targetDefStat = (targetDefStat * gMultiplicadoresEstadisticas[statStage]) >> 8;

            physical = ((((2 * gBattleMons[battlerAtk].level / 5 + 2) * gMovesInfo[MOVE_SHELL_SIDE_ARM].power * attackerAtkStat) / targetDefStat) / 50);

            targetSpDefStat = gBattleMons[battlerDef].spDefense;
            statStage = gBattleMons[battlerDef].statStages[ESTADISTICA_DEFENSA_ESPECIAL];
            targetSpDefStat = (targetSpDefStat * gMultiplicadoresEstadisticas[statStage]) >> 8;

            special = ((((2 * gBattleMons[battlerAtk].level / 5 + 2) * gMovesInfo[MOVE_SHELL_SIDE_ARM].power * attackerSpAtkStat) / targetSpDefStat) / 50);

            if ((physical > special) || (physical == special && PorcentajeAleatorio(50)))
                gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] = CATEGORIA_FISICA;
            else
                gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] = CATEGORIA_ESPECIAL;
        }
    }
}

bool32 CanTargetPartner(u32 battlerAtk, u32 battlerDef)
{
    return (EsContraEntrenador()
         && IsBattlerAlive(ALIADO(battlerDef))
         && battlerDef != ALIADO(battlerAtk));
}

static inline bool32 DoesBattlerHaveAbilityImmunity(u32 battlerDef)
{
    return (AbilityBattleEffects(ABILITYEFFECT_WOULD_BLOCK, battlerDef, 0, 0, 0)
         || AbilityBattleEffects(ABILITYEFFECT_WOULD_ABSORB, battlerDef, 0, 0, 0));
}

bool32 TargetFullyImmuneToCurrMove(u32 battlerAtk, u32 battlerDef)
{
    return ((CalcTypeEffectivenessMultiplier(gCurrentMove, GetMoveType(gCurrentMove), battlerAtk, battlerDef, GetBattlerAbility(battlerDef), FALSE) == UQ_4_12(0.0))
         || IsBattlerProtected(battlerAtk, battlerDef, gCurrentMove)
         || IsSemiInvulnerable(battlerDef, gCurrentMove)
         || DoesBattlerHaveAbilityImmunity(battlerDef));
}


u32 GetMoveType(u32 move)
{
    if (gMain.inBattle && gBattleStruct->dynamicMoveType)
        return gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK;
    else if (B_UPDATED_MOVE_TYPES < GEN_5
         && (move == MOVE_PALIZA
          || move == MOVE_FUTURE_SIGHT
          || move == MOVE_DOOM_DESIRE))
          return TIPO_MISTERIO;
    return gMovesInfo[move].type;
}

u32 CuantosPSLeQuedan(u32 combatiente)
{
    return gBattleMons[combatiente].hp;
}

u32 CuantosPSMaximos(u32 combatiente)
{
    return gBattleMons[combatiente].maxHP;
}

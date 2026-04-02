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

static bool32 TryRemoveScreens(u32 battler);
static void SetRandomMultiHitCounter();
static u32 GetBattlerItemHoldEffectParam(u32 battler, u32 item);

#define HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(funcionChequeo, estado)                                                                                                                                                                                                                                                                                                                                   \
    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerAttacker) && funcionChequeo(gBattlerAttacker, HabilidadCombatiente(gBattlerAttacker)) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker)) \
    {                                                                                                                                                                                                                                                                                                                                                                                                \
        gBattleScripting.moveEffect = MOVE_EFFECT_AFFECTS_USER | estado;                                                                                                                                                                                                                                                                                                                             \
        PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);                                                                                                                                                                                                                                                                                                                                  \
        BattleScriptPushCursor();                                                                                                                                                                                                                                                                                                                                                                    \
        gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;                                                                                                                                                                                                                                                                                                                                   \
        gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;                                                                                                                                                                                                                                                                                                                                               \
        effect++;                                                                                                                                                                                                                                                                                                                                                                                    \
    }

static void CheckSetUnburden(u8 battler)
{
    if (HabilidadCombatiente(battler) == ABILITY_UNBURDEN)
    {
        gBattleResources->flags[battler] |= RESOURCE_FLAG_UNBURDEN;
        RecuerdaHabilidad(battler, ABILITY_UNBURDEN);
    }
}

bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move)
{
    u32 ability = HabilidadCombatiente(battlerAtk);

    if (gSideTimers[defSide].followmeTimer == 0 || !IsBattlerAlive(gSideTimers[defSide].followmeTarget) || gMovesInfo[move].effect == EFFECT_SNIPE_SHOT || ability == ABILITY_PROPELLER_TAIL || ability == ABILITY_STALWART)
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowder(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk, TRUE)))
        return FALSE;

    return TRUE;
}

void HandleAction_UseMove(void)
{
    u32 battler, i, side, moveType, var = 4;
    u16 moveTarget;

    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gCombate->absentBattlerFlags & (1u << gBattlerAttacker) || !IsBattlerAlive(gBattlerAttacker))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gEsGolpeCritico = FALSE;
    gCombate->atkCancellerTracker = 0;
    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    gCombate.contadorMultigolpes = 0;
    gBattleScripting.savedDmg = 0;
    gBattleScripting.savedMoveEffect = 0;
    gCurrMovePos = gChosenMovePos = *(gCombate->chosenMovePositions + gBattlerAttacker);

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = FALSE;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        IncrementGameStat(GAME_STAT_USED_STRUGGLE);
        gHitMarker |= HITMARKER_NO_PPDEDUCT;
        *(gCombate->moveTarget + gBattlerAttacker) = GetMoveTarget(MOVE_STRUGGLE, NO_TARGET_OVERRIDE);
    }
    else if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS || gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE && gDisableStructs[gBattlerAttacker].encoredMove == gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrentMove = gChosenMove = gDisableStructs[gBattlerAttacker].encoredMove;
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        *(gCombate->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    // check if the encored move wasn't overwritten
    else if (gDisableStructs[gBattlerAttacker].encoredMove != MOVE_NONE && gDisableStructs[gBattlerAttacker].encoredMove != gBattleMons[gBattlerAttacker].moves[gDisableStructs[gBattlerAttacker].encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gDisableStructs[gBattlerAttacker].encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gDisableStructs[gBattlerAttacker].encoredMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].encoredMovePos = 0;
        gDisableStructs[gBattlerAttacker].encoreTimer = 0;
        *(gCombate->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gMovimientoElegido[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        *(gCombate->moveTarget + gBattlerAttacker) = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);
    IntentaActivarGema(gBattlerAttacker, gCurrentMove);
    moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    // choose target
    side = OPONENTE(GetBattlerSide(gBattlerAttacker));
    if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove) && moveTarget == MOVE_TARGET_SELECTED && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gSideTimers[side].followmeTarget))
    {
        gCombate->moveTarget[gBattlerAttacker] = gBattlerTarget = gSideTimers[side].followmeTarget; // follow me moxie fix
    }
    else if (EsContraEntrenador() && gSideTimers[side].followmeTimer == 0 && (!EsMovimientoDeEstado(gCurrentMove) || (moveTarget != MOVE_TARGET_USER && moveTarget != MOVE_TARGET_ALL_BATTLERS)) && ((HabilidadCombatiente(*(gCombate->moveTarget + gBattlerAttacker)) != ABILITY_LIGHTNING_ROD && moveType == TIPO_ELECTRICO) || (HabilidadCombatiente(*(gCombate->moveTarget + gBattlerAttacker)) != ABILITY_STORM_DRAIN && moveType == TIPO_AGUA)))
    {
        side = GetBattlerSide(gBattlerAttacker);
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (side != GetBattlerSide(battler) && *(gCombate->moveTarget + gBattlerAttacker) != battler && ((HabilidadCombatiente(battler) == ABILITY_LIGHTNING_ROD && moveType == TIPO_ELECTRICO) || (HabilidadCombatiente(battler) == ABILITY_STORM_DRAIN && moveType == TIPO_AGUA)) && GetBattlerTurnOrderNum(battler) < var && gMovesInfo[gCurrentMove].effect != EFFECT_SNIPE_SHOT && HabilidadCombatiente(gBattlerAttacker) != ABILITY_PROPELLER_TAIL && HabilidadCombatiente(gBattlerAttacker) != ABILITY_STALWART)
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
                gBattlerTarget = *(gCombate->moveTarget + gBattlerAttacker);
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
            battlerAbility = HabilidadCombatiente(battler);

            RecuerdaHabilidad(battler, gBattleMons[battler].ability);
            if (battlerAbility == ABILITY_LIGHTNING_ROD)
                gSpecialStatuses[battler].lightningRodRedirected = TRUE;
            else if (battlerAbility == ABILITY_STORM_DRAIN)
                gSpecialStatuses[battler].stormDrainRedirected = TRUE;
            gBattlerTarget = battler;
        }
    }
    else if (EsContraEntrenador() && moveTarget & MOVE_TARGET_RANDOM)
    {
        gBattlerTarget = SetRandomTarget(gBattlerAttacker);
        if (gAbsentBattlerFlags & (1u << gBattlerTarget) && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
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
        gBattlerTarget = *(gCombate->moveTarget + gBattlerAttacker);
        if (!IsBattlerAlive(gBattlerTarget) && moveTarget != MOVE_TARGET_OPPONENTS_FIELD && (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)))
        {
            gBattlerTarget = ALIADO(gBattlerTarget);
        }
    }

    if ((GetBattlerSide(gBattlerAttacker) == GetBattlerSide(gBattlerTarget)) && (!IsBattlerAlive(gBattlerTarget)))
    {
        gBattlescriptCurrInstr = BattleScript_FailedFromAtkCanceler;
    }
    else
    {
        gBattlescriptCurrInstr = GET_MOVE_BATTLESCRIPT(gCurrentMove);
    }

    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        gCombate->hpBefore[i] = gBattleMons[i].hp;
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

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gCombate->battlerPartyIndexes + gBattlerAttacker))

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    gCombate.numeroCambiosJugador++;

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
        gCombate->faintedActionsState = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
    }
}

void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_PASSIVE_DAMAGE | HITMARKER_SYNCHRONISE_EFFECT | HITMARKER_CHARGING);
}

void HandleAction_ActionFinished(void)
{
    u32 i, j;
    bool32 afterYouActive = gSpecialStatuses[gBattlerByTurnOrder[gCurrentTurnActionNumber + 1]].afterYou;
    *(gCombate->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = gSelectedMonPartyId = PARTY_SIZE;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_PASSIVE_DAMAGE | HITMARKER_SYNCHRONISE_EFFECT | HITMARKER_CHARGING);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gCombate->dynamicMoveType = 0;
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
                if ((gActionsByTurnOrder[i] == B_ACTION_USE_MOVE && gActionsByTurnOrder[j] == B_ACTION_USE_MOVE))
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

static const u8 sHoldEffectToType[][NUMERO_TIPOS_POR_POKEMON] =
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

const u8 *CancelMultiTurnMoves(u32 battler)
{
    const u8 *result = NULL;
    gBattleMons[battler].status2 &= ~(STATUS2_UPROAR);

    if (B_RAMPAGE_CANCELLING < GEN_5)
    {
        gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
        gBattleMons[battler].status2 &= ~(STATUS2_LOCK_CONFUSE);
    }
    else if (!(gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE) || ((gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE) > STATUS2_LOCK_CONFUSE_TURN(1)))
    {
        gBattleMons[battler].status2 &= ~(STATUS2_MULTIPLETURNS);
    }

    gStatuses3[battler] &= ~(STATUS3_SEMI_INVULNERABLE);

    gDisableStructs[battler].rolloutTimer = 0;
    gDisableStructs[battler].furyCutterCounter = 0;

    return result;
}

bool32 WasUnableToUseMove(u32 battler)
{
    if (gProtectStructs[battler].prlzImmobility || gProtectStructs[battler].sleepImmobility || gProtectStructs[battler].usedImprisonedMove || gProtectStructs[battler].loveImmobility || gProtectStructs[battler].usedDisabledMove || gProtectStructs[battler].usedTauntedMove || gProtectStructs[battler].usedGravityPreventedMove || gProtectStructs[battler].flinchImmobility || gProtectStructs[battler].confusionSelfDmg || gProtectStructs[battler].powderSelfDmg || gProtectStructs[battler].usedThroatChopPreventedMove)
        return TRUE;
    else
        return FALSE;
}

void PrepareStringBattle(u16 stringId, u32 battler)
{
    u32 targetSide = GetBattlerSide(gBattlerTarget);
    u16 battlerAbility = HabilidadCombatiente(battler);
    u16 targetAbility = HabilidadCombatiente(gBattlerTarget);
    // Support for Contrary ability.
    // If a move attempted to raise stat - print "won't increase".
    // If a move attempted to lower stat - print "won't decrease".
    if (stringId == STRINGID_STATSWONTDECREASE && !(gBattleScripting.statChanger & STAT_BUFF_NEGATIVE))
        stringId = STRINGID_STATSWONTINCREASE;
    else if (stringId == STRINGID_STATSWONTINCREASE && gBattleScripting.statChanger & STAT_BUFF_NEGATIVE)
        stringId = STRINGID_STATSWONTDECREASE;

    else if (stringId == STRINGID_STATSWONTDECREASE2 && battlerAbility == ABILITY_RESPONDON)
        stringId = STRINGID_STATSWONTINCREASE2;
    else if (stringId == STRINGID_STATSWONTINCREASE2 && battlerAbility == ABILITY_RESPONDON)
        stringId = STRINGID_STATSWONTDECREASE2;

    // Check Defiant and Competitive stat raise whenever a stat is lowered.
    else if ((stringId == STRINGID_DEFENDERSSTATFELL || stringId == STRINGID_PKMNCUTSATTACKWITH) && ((targetAbility == ABILITY_DEFIANT && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR)) || (targetAbility == ABILITY_COMPETITIVE && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR))) && gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != ALIADO(gBattlerTarget) && ((gSpecialStatuses[gBattlerTarget].changedStatsBattlerId != gBattlerTarget) || gBattleScripting.stickyWebStatDrop == 1) && !(gBattleScripting.stickyWebStatDrop == 1 && gSideTimers[targetSide].stickyWebBattlerSide == targetSide)) // Sticky Web must have been set by the foe
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_AbilityRaisesDefenderStat;
        if (targetAbility == ABILITY_DEFIANT)
            SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);
        else
            SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE);
    }
    else if (stringId == STRINGID_PKMNCUTSATTACKWITH && targetAbility == ABILITY_RATTLED && CompareStat(gBattlerTarget, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
    {
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_AbilityRaisesDefenderStat;
        SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
    }

    // Signal for the trainer slide-in system.
    if ((stringId == STRINGID_ITDOESNTAFFECT || stringId == STRINGID_PKMNWASNTAFFECTED) && GetBattlerSide(gBattlerTarget) == LADO_OPONENTE && gCombate->trainerSlidePlayerMonUnaffectedMsgState != 2)
        gCombate->trainerSlidePlayerMonUnaffectedMsgState = 1;

    ControladorCombate_EscribeTexto(battler, BUFFER_A, stringId);
    MarcaCombatienteOcupado(battler);
}

void EscribeTextoCombate(u32 combatiente, const u8 *texto)
{
    if (HayAlgunCombatienteOcupado())
        return;

    ControladorCombate_EscribeTexto(combatiente, BUFFER_A, texto);
    MarcaCombatienteOcupado(combatiente);
    gMostrarMensajeBatalla = TRUE;
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

bool32 IsBelchPreventingMove(u32 battler, u32 move)
{
    if (gMovesInfo[move].effect != EFFECT_BELCH)
        return FALSE;

    return !(gCombate->ateBerry[battler & BIT_SIDE] & (1u << gBattlerPartyIndexes[battler]));
}

u32 TrySetCantSelectMoveBattleScript(u32 battler)
{
    u32 limitations = 0;
    u8 moveId = gBattleResources->bufferB[battler][2];
    u32 move = gBattleMons[battler].moves[moveId];
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    u16 *choicedMove = &gCombate->choicedMove[battler];

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

    if (gDisableStructs[battler].tauntTimer != 0 && EsMovimientoDeEstado(move))
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

    else if ((HabilidadCombatiente(battler) == ABILITY_GORILLA_TACTICS || HOLD_EFFECT_CHOICE(holdEffect)) && *choicedMove != MOVE_NONE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[battler].item;
        gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
        limitations++;
    }

    else if ((holdEffect == HOLD_EFFECT_ASSAULT_VEST || holdEffect == HOLD_EFFECT_CHALECO_TACTICO) && EsMovimientoDeEstado(move))
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

    return limitations;
}

u8 CheckMoveLimitations(u32 battler, u8 unusableMoves, u16 check)
{
    u32 move, moveEffect;
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    u16 *choicedMove = &gCombate->choicedMove[battler];
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
        // Disable
        else if (check & MOVE_LIMITATION_DISABLED && move == gDisableStructs[battler].disabledMove)
            unusableMoves |= 1u << i;
        // Torment
        else if (check & MOVE_LIMITATION_TORMENTED && move == gLastMoves[battler] && gBattleMons[battler].status2 & STATUS2_TORMENT)
            unusableMoves |= 1u << i;
        // Taunt
        else if (check & MOVE_LIMITATION_TAUNT && gDisableStructs[battler].tauntTimer && EsMovimientoDeEstado(move))
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
        else if (check & MOVE_LIMITATION_ASSAULT_VEST && holdEffect == HOLD_EFFECT_ASSAULT_VEST && EsMovimientoDeEstado(move))
            unusableMoves |= 1u << i;
        // Chaleco Táctico
        else if (check & MOVE_LIMITATION_ASSAULT_VEST && holdEffect == HOLD_EFFECT_CHALECO_TACTICO && EsMovimientoDeEstado(move))
            unusableMoves |= 1u << i;
        // Gravity
        else if (check & MOVE_LIMITATION_GRAVITY && IsGravityPreventingMove(move))
            unusableMoves |= 1u << i;
        // Belch
        else if (check & MOVE_LIMITATION_BELCH && IsBelchPreventingMove(battler, move))
            unusableMoves |= 1u << i;
        // Throat Chop
        else if (check & MOVE_LIMITATION_THROAT_CHOP && gDisableStructs[battler].throatChopTimer && gMovesInfo[move].soundMove)
            unusableMoves |= 1u << i;
        // Gorilla Tactics
        else if (check & MOVE_LIMITATION_CHOICE_ITEM && HabilidadCombatiente(battler) == ABILITY_GORILLA_TACTICS && *choicedMove != MOVE_NONE && *choicedMove != move)
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

        switch (gCombate->efectoFinTurno.campo)
        {
        case FIN_TURNO_ORDEN:
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

            gCombate->efectoFinTurno.campo++;
            gCombate->turnSideTracker = 0;
            // fall through
        case ENDTURN_REFLECT:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LIGHT_SCREEN:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_AURORA_VEIL:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_MIST:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
                gBattlerAttacker = gSideTimers[side].mistBattlerId;
                if (gSideTimers[side].mistTimer != 0 && --gSideTimers[side].mistTimer == 0)
                {
                    gSideStatuses[side] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(BattleScript_SideStatusWoreOff);
                    gBattleCommunication[MULTISTRING_CHOOSER] = side;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_MIST);
                    effect++;
                }
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SAFEGUARD:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LUCKY_CHANT:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TAILWIND:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
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
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_WISH:
            while (gCombate->turnSideTracker < gBattlersCount)
            {
                u32 battler = gBattlerByTurnOrder[gCombate->turnSideTracker];
                if (gWishFutureKnock.wishCounter[battler] != 0 && --gWishFutureKnock.wishCounter[battler] == 0 && IsBattlerAlive(battler))
                {
                    gBattlerTarget = battler;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
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
            gCombate->efectoFinTurno.campo++;
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
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_SUN:
            if (gBattleWeather & B_WEATHER_SUN)
            {
                if (!(gBattleWeather & B_WEATHER_SUN_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
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
            gCombate->efectoFinTurno.campo++;
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
            gCombate->efectoFinTurno.campo++;
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
            gCombate->efectoFinTurno.campo++;
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
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_DAMAGE_NON_TYPES:
            while (gCombate->turnSideTracker < 2)
            {
                side = gCombate->turnSideTracker;
                if (gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES && --gSideTimers[side].damageNonTypesTimer == 0)
                {
                    // There is no in-game message when this side status ends.
                    gSideStatuses[side] &= ~SIDE_STATUS_DAMAGE_NON_TYPES;
                    effect++;
                }
                gCombate->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (!effect)
            {
                gCombate->efectoFinTurno.campo++;
                gCombate->turnSideTracker = 0;
            }
            break;
        case ENDTURN_TRICK_ROOM:
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 0 && --gFieldTimers.trickRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_TRICK_ROOM;
                BattleScriptExecute(BattleScript_TrickRoomEnds);
                effect++;
            }
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM && gFieldTimers.wonderRoomTimer > 0 && --gFieldTimers.wonderRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_WONDER_ROOM;
                BattleScriptExecute(BattleScript_WonderRoomEnds);
                effect++;
            }
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM && gFieldTimers.magicRoomTimer > 0 && --gFieldTimers.magicRoomTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_MAGIC_ROOM;
                BattleScriptExecute(BattleScript_MagicRoomEnds);
                effect++;
            }
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_GRAVITY:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY && --gFieldTimers.gravityTimer == 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_GRAVITY;
                BattleScriptExecute(BattleScript_GravityEnds);
                effect++;
            }
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_STATUS_HEAL:
            gCombate->efectoFinTurno.campo++;
            break;
        case ENDTURN_FIELD_COUNT:
            effect++;
            break;
        }
    } while (effect == 0);

    return (gBattleMainFunc != BattleTurnPassed);
}

// Ingrain, Leech Seed, Strength Sap and Aqua Ring
s32 GetDrainedBigRootHp(u32 battler, s32 hp)
{
    if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_BIG_ROOT)
        hp = (hp * 1300) / 1000;
    if (hp == 0)
        hp = 1;

    return hp * -1;
}

#define MAGIC_GUARD_CHECK                      \
    if (ability == ABILITY_MAGIC_GUARD)        \
    {                                          \
        RecuerdaHabilidad(battler, ability);   \
        gCombate->efectoFinTurno.individual++; \
        break;                                 \
    }

u8 DoBattlerEndTurnEffects(void)
{
    u32 battler, ability, i, effect = 0;

    while (gCombate->gCombate->efectoFinTurno.indiceCombatiente < gBattlersCount && gCombate->efectoFinTurno.individual <= ENDTURN_BATTLER_COUNT)
    {
        battler = gBattlerAttacker = gBattlerByTurnOrder[gCombate->gCombate->efectoFinTurno.indiceCombatiente];
        if (gAbsentBattlerFlags & (1u << battler))
        {
            gCombate->gCombate->efectoFinTurno.indiceCombatiente++;
            continue;
        }

        ability = HabilidadCombatiente(battler);
        switch (gCombate->efectoFinTurno.individual)
        {
        case ENDTURN_WEATHER_DAMAGE:
            ability = HabilidadCombatiente(battler);
            if (!IsBattlerAlive(battler) || !WEATHER_HAS_EFFECT || ability == ABILITY_MAGIC_GUARD)
            {
                gCombate->efectoFinTurno.individual++;
                break;
            }
            else if (gBattleWeather & B_WEATHER_SANDSTORM && ability != ABILITY_SAND_VEIL && ability != ABILITY_SAND_FORCE && ability != ABILITY_SAND_RUSH && ability != ABILITY_OVERCOAT && !EsTipo(gBattlerAttacker, TIPO_ROCA) && !EsTipo(gBattlerAttacker, TIPO_TIERRA) && !EsTipo(gBattlerAttacker, TIPO_ACERO) && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER)) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_DamagingWeather);
                effect++;
            }
            else if (gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW) && ability == ABILITY_ICE_BODY && !(gStatuses3[battler] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER)) && !IsBattlerAtMaxHp(battler))
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = -1 * max(1, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_IceBodyHeal);
                effect++;
            }
            else if (gBattleWeather & B_WEATHER_HAIL && !EsTipo(battler, TIPO_HIELO) && ability != ABILITY_SNOW_CLOAK && ability != ABILITY_OVERCOAT && ability != ABILITY_ICE_BODY && !(gStatuses3[battler] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER)) && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleScripting.battler = battler;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_DamagingWeather);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_INGRAIN: // ingrain
            if ((gStatuses3[battler] & STATUS3_ROOTED) && !IsBattlerAtMaxHp(battler) && IsBattlerAlive(battler))
            {
                gBattleMoveDamage = GetDrainedBigRootHp(battler, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_IngrainTurnHeal);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_AQUA_RING: // aqua ring
            if ((gStatuses3[battler] & STATUS3_AQUA_RING) && !IsBattlerAtMaxHp(battler) && IsBattlerAlive(battler))
            {
                gBattleMoveDamage = GetDrainedBigRootHp(battler, CuantosPSMaximos(battler) / 16);
                BattleScriptExecute(BattleScript_AquaRingHeal);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ABILITIES: // end turn abilities
            if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, battler, 0, 0, 0))
                effect++;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ITEMS1: // item effects
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
                effect++;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ITEMS2: // item effects again
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, TRUE))
                effect++;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ITEMS3:                                                                                                                     // berry effects
            if (gItemsInfo[gBattleMons[battler].item].pocket == POCKET_BERRIES || GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_RESTORE_HP) // Edge case for Berry Juice
            {
                if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
                    effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ORBS:
            if (IsBattlerAlive(battler) && ItemBattleEffects(ITEMEFFECT_ORBS, battler, FALSE))
                effect++;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_LEECH_SEED: // leech seed
            if ((gStatuses3[battler] & STATUS3_LEECHSEED) && IsBattlerAlive(gStatuses3[battler] & STATUS3_LEECHSEED_BATTLER) && IsBattlerAlive(battler))
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
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_POISON: // poison
            if ((gBattleMons[battler].status1 & STATUS1_POISON) && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!IsBattlerAtMaxHp(battler))
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
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_BAD_POISON: // toxic poison
            if ((gBattleMons[battler].status1 & STATUS1_TOXIC_POISON) && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;

                if (ability == ABILITY_POISON_HEAL)
                {
                    if (!IsBattlerAtMaxHp(battler))
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
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_BURN: // burn
            if ((gBattleMons[battler].status1 & STATUS1_BURN) && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_BurnTurnDmg);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case FIN_TURNO_CONGELACION:
            if ((gBattleMons[battler].status1 & STATUS1_CONGELACION) && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(ScriptCombate_DanioCongelacion);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_NIGHTMARES: // spooky nightmares
            if ((gBattleMons[battler].status2 & STATUS2_NIGHTMARE) && IsBattlerAlive(battler))
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
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_CURSE: // curse
            if ((gBattleMons[battler].status2 & STATUS2_CURSED) && IsBattlerAlive(battler))
            {
                MAGIC_GUARD_CHECK;
                gBattleMoveDamage = CuantosPSMaximos(battler) / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                BattleScriptExecute(BattleScript_CurseTurnDmg);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_WRAP: // wrap
            if ((gBattleMons[battler].status2 & STATUS2_WRAPPED) && IsBattlerAlive(battler))
            {
                if (--gDisableStructs[battler].wrapTurns != 0) // damaged by wrap
                {
                    MAGIC_GUARD_CHECK;

                    gBattleScripting.animArg1 = gCombate->wrappedMove[battler];
                    gBattleScripting.animArg2 = gCombate->wrappedMove[battler] >> 8;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gCombate->wrappedMove[battler]);
                    gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;
                    if (GetBattlerHoldEffect(gCombate->wrappedBy[battler], TRUE) == HOLD_EFFECT_BINDING_BAND)
                        gBattleMoveDamage = CuantosPSMaximos(battler) / 8;
                    else
                        gBattleMoveDamage = CuantosPSMaximos(battler) / 16;

                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                }
                else // broke free
                {
                    gBattleMons[battler].status2 &= ~STATUS2_WRAPPED;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, gCombate->wrappedMove[battler]);
                    gBattlescriptCurrInstr = BattleScript_WrapEnds;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_UPROAR: // uproar
            if (gBattleMons[battler].status2 & STATUS2_UPROAR)
            {
                for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                {
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) && (B_UPROAR_IGNORE_SOUNDPROOF >= GEN_5 || HabilidadCombatiente(gBattlerAttacker) != ABILITY_SOUNDPROOF))
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
                    effect = 2; // a Pokémon was awaken
                    break;
                }
                else
                {
                    gBattlerAttacker = battler;
                    gBattleMons[battler].status2 -= STATUS2_UPROAR_TURN(1); // uproar timer goes down
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
                gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_THRASH: // thrash
            // Don't decrement STATUS2_LOCK_CONFUSE if the target is held by Sky Drop
            if (gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE)
            {
                gBattleMons[battler].status2 -= STATUS2_LOCK_CONFUSE_TURN(1);
                if (WasUnableToUseMove(battler))
                    CancelMultiTurnMoves(battler);
                else if (!(gBattleMons[battler].status2 & STATUS2_LOCK_CONFUSE) && (gBattleMons[battler].status2 & STATUS2_MULTIPLETURNS))
                {
                    gBattleMons[battler].status2 &= ~STATUS2_MULTIPLETURNS;
                    if (!(gBattleMons[battler].status2 & STATUS2_CONFUSION))
                    {
                        gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER;
                        SetMoveEffect(TRUE);
                        if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                            BattleScriptExecute(BattleScript_ThrashConfuses);
                        effect++;
                    }
                }
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_FLINCH: // reset flinch
            gBattleMons[battler].status2 &= ~STATUS2_FLINCHED;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_DISABLE: // disable
            if (gDisableStructs[battler].disableTimer != 0)
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gDisableStructs[battler].disabledMove == gBattleMons[battler].moves[i])
                        break;
                }
                if (i == MAX_MON_MOVES) // Pokémon does not have the disabled move anymore
                {
                    gDisableStructs[battler].disabledMove = 0;
                    gDisableStructs[battler].disableTimer = 0;
                }
                else if (--gDisableStructs[battler].disableTimer == 0) // disable ends
                {
                    gDisableStructs[battler].disabledMove = 0;
                    BattleScriptExecute(BattleScript_DisabledNoMore);
                    effect++;
                }
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ENCORE: // encore
            if (gDisableStructs[battler].encoreTimer != 0)
            {
                if (gBattleMons[battler].moves[gDisableStructs[battler].encoredMovePos] != gDisableStructs[battler].encoredMove) // Pokémon does not have the encored move anymore
                {
                    gDisableStructs[battler].encoredMove = 0;
                    gDisableStructs[battler].encoreTimer = 0;
                }
                else if (--gDisableStructs[battler].encoreTimer == 0 || gBattleMons[battler].pp[gDisableStructs[battler].encoredMovePos] == 0)
                {
                    gDisableStructs[battler].encoredMove = 0;
                    gDisableStructs[battler].encoreTimer = 0;
                    BattleScriptExecute(BattleScript_EncoredNoMore);
                    effect++;
                }
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_LOCK_ON:
            if (gStatuses3[battler] & STATUS3_ALWAYS_HITS)
                gStatuses3[battler] -= STATUS3_ALWAYS_HITS_TURN(1);
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_CHARGE:
            if (gDisableStructs[battler].chargeTimer > 0 && --gDisableStructs[battler].chargeTimer == 0)
                gStatuses3[battler] &= ~STATUS3_CHARGED_UP;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_TAUNT:
            if (gDisableStructs[battler].tauntTimer && --gDisableStructs[battler].tauntTimer == 0)
            {
                BattleScriptExecute(BattleScript_BufferEndTurn);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
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
            gCombate->efectoFinTurno.individual++;
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
            gCombate->efectoFinTurno.individual++;
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
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_ROOST: // Return flying type.
            if (gBattleResources->flags[battler] & RESOURCE_FLAG_ROOST)
                gBattleResources->flags[battler] &= ~RESOURCE_FLAG_ROOST;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_POWDER:
            gBattleMons[battler].status2 &= ~STATUS2_POWDER;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_THROAT_CHOP:
            if (gDisableStructs[battler].throatChopTimer && --gDisableStructs[battler].throatChopTimer == 0)
            {
                BattleScriptExecute(BattleScript_ThroatChopEndTurn);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_CUD_CHEW:
            if (HabilidadCombatiente(battler) == ABILITY_CUD_CHEW && !gDisableStructs[battler].cudChew && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                gDisableStructs[battler].cudChew = TRUE;
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_TORMENT:
            if (gDisableStructs[battler].tormentTimer != PERMANENT_TORMENT && --gDisableStructs[battler].tormentTimer == 0)
            {
                gBattleMons[battler].status2 &= ~STATUS2_TORMENT;
                BattleScriptExecute(BattleScript_TormentEnds);
                effect++;
            }
            gCombate->efectoFinTurno.individual++;
            break;
        case ENDTURN_BATTLER_COUNT: // done
            gCombate->efectoFinTurno.individual = ENDTURN_WEATHER_DAMAGE;
            gCombate->gCombate->efectoFinTurno.indiceCombatiente++;
            break;
        }

        if (effect != 0)
            return effect;
    }
    return 0;
}

bool32 HandleWishPerishSongOnTurnEnd(void)
{
    u32 battler;

    switch (gCombate->wishPerishSongState)
    {
    case 0:
        while (gCombate->wishPerishSongBattlerId < gBattlersCount)
        {
            battler = gCombate->wishPerishSongBattlerId;

            gCombate->wishPerishSongBattlerId++;

            if (gWishFutureKnock.futureSightCounter[battler] != 0 && --gWishFutureKnock.futureSightCounter[battler] == 0 && !(gAbsentBattlerFlags & (1u << battler)))
            {
                struct Pokemon *party;

                if (gWishFutureKnock.futureSightCounter[battler] == 0 && gWishFutureKnock.futureSightCounter[ALIADO(battler)] == 0)
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
                gCurrentMove = gWishFutureKnock.futureSightMove[battler];

                party = GetSideParty(GetBattlerSide(gBattlerAttacker));
                if (&party[gWishFutureKnock.futureSightPartyIndex[gBattlerTarget]] == &party[gBattlerPartyIndexes[gBattlerAttacker]])
                    IntentaActivarGema(gBattlerAttacker, gCurrentMove);

                BattleScriptExecute(BattleScript_MonTookFutureAttack);

                return TRUE;
            }
        }
        gCombate->wishPerishSongState = 1;
        gCombate->wishPerishSongBattlerId = 0;
        // fall through
    case 1:
        while (gCombate->wishPerishSongBattlerId < gBattlersCount)
        {
            battler = gBattlerAttacker = gBattlerByTurnOrder[gCombate->wishPerishSongBattlerId];
            if (gAbsentBattlerFlags & (1u << battler))
            {
                gCombate->wishPerishSongBattlerId++;
                continue;
            }
            gCombate->wishPerishSongBattlerId++;
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
        gCombate->wishPerishSongState = 2;
        gCombate->wishPerishSongBattlerId = 0;
        // fall through
    case 2:
        break;
    }

    return FALSE;
}

#define FAINTED_ACTIONS_MAX_CASE 7

bool32 HandleFaintedMonActions(void)
{
    do
    {
        s32 i;
        switch (gCombate->faintedActionsState)
        {
        case 0:
            gCombate->faintedActionsBattlerId = 0;
            gCombate->faintedActionsState++;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & (1u << i) && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(1u << i);
            }
            // fall through
        case 1:
            do
            {
                gBattlerFainted = gBattlerTarget = gCombate->faintedActionsBattlerId;
                if (gBattleMons[gCombate->faintedActionsBattlerId].hp == 0 && !(gCombate->givenExpMons & (1u << gBattlerPartyIndexes[gCombate->faintedActionsBattlerId])) && !(gAbsentBattlerFlags & (1u << gCombate->faintedActionsBattlerId)))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gCombate->faintedActionsState = 2;
                    return TRUE;
                }
            } while (++gCombate->faintedActionsBattlerId != gBattlersCount);
            gCombate->faintedActionsState = 3;
            break;
        case 2:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gCombate->faintedActionsBattlerId == gBattlersCount)
                gCombate->faintedActionsState = 3;
            else
                gCombate->faintedActionsState = 1;
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4 && gBattleOutcome == 0 && !NoAliveMonsForEitherParty() && gCurrentTurnActionNumber != gBattlersCount)
            {
                gAbsentBattlerFlags |= 1u << gBattlerFainted;
                if (gCombate->faintedActionsState != 1)
                    return FALSE;
            }
            break;
        case 3:
            // Don't switch mons until all pokemon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4 && gBattleOutcome == 0 && !NoAliveMonsForEitherParty() && gCurrentTurnActionNumber != gBattlersCount)
            {
                return FALSE;
            }
            gCombate->faintedActionsBattlerId = 0;
            gCombate->faintedActionsState++;
            // fall through
        case 4:
            do
            {
                gBattlerFainted = gBattlerTarget = gCombate->faintedActionsBattlerId;
                if (gBattleMons[gCombate->faintedActionsBattlerId].hp == 0 && !(gAbsentBattlerFlags & (1u << gCombate->faintedActionsBattlerId)))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gCombate->faintedActionsState = 5;
                    return TRUE;
                }
            } while (++gCombate->faintedActionsBattlerId != gBattlersCount);
            gCombate->faintedActionsState = 6;
            break;
        case 5:
            if (++gCombate->faintedActionsBattlerId == gBattlersCount)
                gCombate->faintedActionsState = 6;
            else
                gCombate->faintedActionsState = 4;
            break;
        case 6:
            if (ItemBattleEffects(ITEMEFFECT_NORMAL, 0, TRUE))
                return TRUE;
            gCombate->faintedActionsState++;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gCombate->faintedActionsState != FAINTED_ACTIONS_MAX_CASE);
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
    gCombate->isAtkCancelerForCalledMove = TRUE;
}

u8 AtkCanceller_UnableToUseMove(u32 moveType)
{
    u8 effect = 0;
    u32 ability = HabilidadCombatiente(gBattlerAttacker);

    do
    {
        switch (gCombate->atkCancellerTracker)
        {
        case CANCELLER_FLAGS: // flags clear
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_DESTINY_BOND;
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_ASLEEP: // check being asleep
            if (!gCombate->isAtkCancelerForCalledMove && (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) && !PorcentajeAleatorio(75))
            {
                if (UproarWakeUpCheck(gBattlerAttacker))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptPushCursor();
                    EscribeTextoCombate(gBattlerAttacker, "The uproar woke {B_ATK_NAME_WITH_PREFIX}!");
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) < 1)
                        gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    else
                        gBattleMons[gBattlerAttacker].status1 -= 1;
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
            gCombate->atkCancellerTracker++;
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_FLINCH:
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FLINCHED)
            {
                gProtectStructs[gBattlerAttacker].flinchImmobility = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_DISABLED:
            if (gDisableStructs[gBattlerAttacker].disabledMove == gCurrentMove && gDisableStructs[gBattlerAttacker].disabledMove != MOVE_NONE)
            {
                gProtectStructs[gBattlerAttacker].usedDisabledMove = TRUE;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gCombate->atkCancellerTracker++;
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_TAUNTED: // taunt
            if (gDisableStructs[gBattlerAttacker].tauntTimer && EsMovimientoDeEstado(gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedTauntedMove = TRUE;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gCombate->atkCancellerTracker++;
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_CONFUSED: // confusion
            if (!gCombate->isAtkCancelerForCalledMove && gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
            {
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_PARALYSED:
            if (!gCombate->isAtkCancelerForCalledMove && (gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && !PorcentajeAleatorio(10))
            {
                gProtectStructs[gBattlerAttacker].prlzImmobility = TRUE;
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_IN_LOVE: // infatuation
            if (!gCombate->isAtkCancelerForCalledMove && gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_POWDER_MOVE:
            if ((gMovesInfo[gCurrentMove].powderMove) && (gBattlerAttacker != gBattlerTarget))
            {
                if ((EsTipo(gBattlerTarget, TIPO_PLANTA) || HabilidadCombatiente(gBattlerTarget) == ABILITY_OVERCOAT))
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
            gCombate->atkCancellerTracker++;
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
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_EXPLODING_DAMP:
        {
            u32 dampBattler = QueCombatienteTieneHabilidad(ABILITY_DAMP);
            if (dampBattler && (gMovesInfo[gCurrentMove].effect == EFFECT_EXPLOSION))
            {
                gBattleScripting.battler = dampBattler - 1;
                gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gCombate->atkCancellerTracker++;
            break;
        }
        case CANCELLER_MULTIHIT_MOVES:
            if (gMovesInfo[gCurrentMove].effect == EFFECT_MULTI_HIT)
            {
                if (ability == ABILITY_SKILL_LINK || ability == ABILITY_ENJAMBRE)
                {
                    gCombate.contadorMultigolpes = MAXIMO_MULTIGOLPES;
                }
                else
                {
                    SetRandomMultiHitCounter();
                }

                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else if (gMovesInfo[gCurrentMove].strikeCount > 1)
            {
                if (gMovesInfo[gCurrentMove].strikeCount == 2 && ability == ABILITY_HAZLO_TRIPLE)
                {
                    gCombate.contadorMultigolpes = 3;
                    PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
                }
                else
                {
                    gCombate.contadorMultigolpes = gMovesInfo[gCurrentMove].strikeCount;

                    if (gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_DARTS && CanTargetPartner(gBattlerAttacker, gBattlerTarget) && TargetFullyImmuneToCurrMove(gBattlerAttacker, gBattlerTarget))
                        gBattlerTarget = ALIADO(gBattlerTarget);
                }

                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 3, 0)
            }
            else if (gMovesInfo[gCurrentMove].effect == EFECTO_ATAQUE_EQUIPO)
            {
                struct Pokemon *party = GetBattlerParty(gBattlerAttacker);
                u32 i;

                for (i = 0; i < PARTY_SIZE; i++)
                {
                    if (GetMonData(&party[i], MON_DATA_HP) && GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&party[i], MON_DATA_IS_EGG))
                        gCombate.contadorMultigolpes++;
                }

                gCombate->posicionPokemonEquipo = 0;
                PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
            }
            else
            {
                gCombate.contadorMultigolpes = 0;
            }
            gCombate->atkCancellerTracker++;
            break;
        case CANCELLER_END:
            break;
        }

    } while (gCombate->atkCancellerTracker != CANCELLER_END && effect == 0);

    if (effect == 2)
    {
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerAttacker].status1);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }
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
        if (IsValidForBattle(&party[i]) && i != partyIdBattlerOn1 && i != partyIdBattlerOn2 && i != *(gCombate->monToSwitchIntoId + flankId) && i != playerId[gCombate->monToSwitchIntoId])
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
    struct Forewarn
    {
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
    return (side == LADO_JUGADOR) ? gCombate.contadorDebilitadosJugador : gCombate.contadorDebilitadosRival;
}

static inline u8 GetBattlerSideFaintCounter(u32 battler)
{
    return GetSideFaintCounter(GetBattlerSide(battler));
}

static inline bool32 MenosDeMediaVida(u32 combatiente)
{
    u32 mediaVida = gBattleMons[combatiente].maxHP / 2;
    return (gCombate->hpBefore[combatiente] > mediaVida && gBattleMons[combatiente].hp <= mediaVida);
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
    case ABILITY_BELLO_PLUMAJE:
        if (GetBattlerSide(battlerAtk) != GetBattlerSide(battlerDef))
        {
            u32 priority = AI_DATA->aiCalcInProgress ? GetMovePriority(battlerAtk, move) : GetChosenMovePriority(battlerAtk);
            if (priority > 0)
                effect = MOVE_BLOCKED_BY_DAZZLING;
        }
        break;
    case ABILITY_EXUVIA:
        if (EsMovimientoDeEstado(move))
        {
            u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, move);
            if (!(moveTarget & MOVE_TARGET_OPPONENTS_FIELD) && !(moveTarget & MOVE_TARGET_ALL_BATTLERS))
                effect = MOVIMIENTO_BLOQUEADO_POR_EXUVIA;
        }
        break;
    }

    if (!effect)
        effect = CanPartnerAbilityBlockMove(battlerAtk, battlerDef, move, HabilidadCombatiente(ALIADO(battlerDef)));

    return effect;
}

u32 CanPartnerAbilityBlockMove(u32 battlerAtk, u32 battlerDef, u32 move, u32 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_DAZZLING:
    case ABILITY_QUEENLY_MAJESTY:
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
        if (moveType == TIPO_AGUA)
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
    case ABILITY_WIND_RIDER:
        if (gMovesInfo[move].windMove && !(GetBattlerMoveTargetType(battlerAtk, move) & MOVE_TARGET_USER))
            effect = MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY;
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TIPO_FUEGO)
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
        gLastUsedAbility = HabilidadCombatiente(battler);

    if (moveArg)
        move = moveArg;
    else
        move = gCurrentMove;

    moveType = TipoMovimiento(move, gBattlerAttacker);

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
                if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0 && !gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
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
                gCombate->tracedAbility[battler] = gLastUsedAbility = gBattleMons[chosenTarget].ability;
                RecuerdaHabilidad(chosenTarget, gLastUsedAbility); // Record the opposing battler has this ability
                gBattlerAbility = battler;

                PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff1, chosenTarget, gBattlerPartyIndexes[chosenTarget])
                PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
            }
        }
        break;
        case ABILITY_CAZATESOROS:
        case ABILITY_MAGO:
        {
            u32 target1, target2;
            u32 chosenTarget = 0;

            if (gSpecialStatuses[battler].switchInAbilityDone)
                break;

            side = (OPONENTE(battler)) & BIT_SIDE;
            target1 = side;
            target2 = side + BIT_FLANK;

            if (EsContraEntrenador())
            {
                bool32 t1Valido = (gBattleMons[target1].hp != 0);
                bool32 t2Valido = (gBattleMons[target2].hp != 0);

                if (t1Valido && t2Valido)
                {
                    chosenTarget = (ElementoAleatorio(2) == 0) ? target1 : target2;
                }
                else if (t1Valido)
                {
                    chosenTarget = target1;
                }
                else if (t2Valido)
                {
                    chosenTarget = target2;
                }
            }
            else
            {
                if (gBattleMons[target1].hp != 0)
                    chosenTarget = target1;
            }

            if (chosenTarget != 0 || (chosenTarget == 0 && gBattleMons[0].hp != 0))
            {
                if (gBattleMons[battler].item == ITEM_NONE && gBattleMons[chosenTarget].item == ITEM_NONE)
                {
                    break;
                }

                if (HabilidadCombatiente(chosenTarget) == ABILITY_STICKY_HOLD || HabilidadCombatiente(chosenTarget) == ABILITY_TERRITORIAL)
                {
                    gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
                    gLastUsedAbility = gBattleMons[chosenTarget].ability;
                    RecuerdaHabilidad(chosenTarget, gLastUsedAbility);
                    effect++;
                }
                else
                {
                    u32 itemUser = gBattleMons[battler].item;
                    u32 itemTarget = gBattleMons[chosenTarget].item;

                    gBattleMons[battler].item = itemTarget;
                    gBattleMons[chosenTarget].item = itemUser;

                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battler].item), &gBattleMons[battler].item);
                    MarcaCombatienteOcupado(battler);

                    BtlController_EmitSetMonData(chosenTarget, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[chosenTarget].item), &gBattleMons[chosenTarget].item);
                    MarcaCombatienteOcupado(chosenTarget);

                    gCombate->choicedMove[chosenTarget] = MOVE_NONE;
                    gCombate->choicedMove[battler] = MOVE_NONE;

                    gBattlerAttacker = battler;
                    gBattlerTarget = chosenTarget;

                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, itemTarget)
                    PREPARE_ITEM_BUFFER(gBattleTextBuff2, itemUser)

                    if (itemUser != ITEM_NONE && itemTarget != ITEM_NONE)
                        gMensajeBatalla = B_MSG_ITEM_SWAP_BOTH;
                    else if (itemUser == ITEM_NONE && itemTarget != ITEM_NONE)
                        gMensajeBatalla = B_MSG_ITEM_SWAP_TAKEN;
                    else
                        gMensajeBatalla = B_MSG_ITEM_SWAP_GIVEN;

                    BattleScriptPushCursorAndCallback(ScriptCombate_ActivacionHabilidadCambioObjeto);
                    effect++;
                }
            }
            gSpecialStatuses[battler].switchInAbilityDone = TRUE;
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
                for (i = 0; i < 2; i++, opposingBattler ^= BIT_FLANK)
                {
                    if (IsBattlerAlive(opposingBattler))
                    {
                        opposingDef += uq4_12_multiply_by_int(gMultiplicadorEstadistica[gBattleMons[opposingBattler].statStages[ESTADISTICA_DEFENSA]],
                                                              gBattleMons[opposingBattler].defense);

                        opposingSpDef += uq4_12_multiply_by_int(gMultiplicadorEstadistica[gBattleMons[opposingBattler].statStages[ESTADISTICA_DEFENSA_ESPECIAL]],
                                                                gBattleMons[opposingBattler].spDefense);
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

                for (i = 0; i < 2; i++, opposingBattler ^= BIT_FLANK)
                {
                    if (IsBattlerAlive(opposingBattler))
                    {
                        opposingAtk += uq4_12_multiply_by_int(gMultiplicadorEstadistica[gBattleMons[opposingBattler].statStages[ESTADISTICA_ATAQUE]],
                                                              gBattleMons[opposingBattler].attack);

                        opposingSpAtk += uq4_12_multiply_by_int(gMultiplicadorEstadistica[gBattleMons[opposingBattler].statStages[ESTADISTICA_ATAQUE_ESPECIAL]],
                                                                gBattleMons[opposingBattler].spAttack);
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
        case ABILITY_GENERADOR:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gMensajeBatalla = B_MSG_SWITCHIN_GENERADOR;
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
        case ABILITY_LLOVIZNA:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_RAIN, TRUE))
            {
                BattleScriptPushCursorAndCallback(ScriptCombate_ActivaLlovizna);
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
        case ABILITY_NEVADA:
            if (TryChangeBattleWeather(battler, ENUM_WEATHER_SNOW, TRUE))
            {
                Pausa(PAUSA_CORTA);
                CreaMensajeHabilidad(battler, gBattleMons[battler].ability);
                Pausa(PAUSA_MEDIA);
                RecuerdaHabilidad(battler, gBattleMons[battler].ability);
                EscribeTextoCombate(battler, "¡Ha empezado a nevar!");
                PlayAnimation(battler, B_ANIM_SNOW_CONTINUES); // Habría que convertirla de algún modo.
                effect++;
            }
            break;
        case ABILITY_INTIMIDATE:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, TRUE);
                BattleScriptPushCursorAndCallback(ScriptCombate_ActivacionIntimidacionMalAura);
                effect++;
            }
            break;
        case ABILITY_MAL_AURA:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE);
                BattleScriptPushCursorAndCallback(ScriptCombate_ActivacionIntimidacionMalAura);
                effect++;
            }
            break;
        case ABILITY_ASPECTO_ENGANIOSO:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_DEFENSA, 1, TRUE);
                BattleScriptPushCursorAndCallback(ScriptCombate_ActivacionAspectoEnganioso);
                effect++;
            }
            break;
        case ABILITY_SEPTIMO_CIELO:
            if (!gSpecialStatuses[battler].switchInAbilityDone)
            {
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                BattleScriptPushCursorAndCallback(ScriptCombate_SeptimoCielo);
                effect++;
            }
            break;
        case ABILITY_WIND_RIDER:
            if (!gSpecialStatuses[battler].switchInAbilityDone && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR) && gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
            {
                gBattleScripting.savedBattler = gBattlerAttacker;
                gBattlerAttacker = battler;
                gSpecialStatuses[battler].switchInAbilityDone = TRUE;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursorAndCallback(BattleScript_BattlerAbilityStatRaiseOnSwitchIn);
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
                if ((IsBattlerWeatherAffected(battler, B_WEATHER_SUN) || PorcentajeAleatorio(50)) && gBattleMons[battler].item == ITEM_NONE && gCombate->changedItems[battler] == ITEM_NONE // Will not inherit an item
                    && ItemId_GetPocket(GetUsedHeldItem(battler)) == POCKET_BERRIES)
                {
                    gLastUsedItem = GetUsedHeldItem(battler);
                    BattleScriptPushCursorAndCallback(BattleScript_HarvestActivates);
                    effect++;
                }
                break;
            // Dry Skin works similarly to Rain Dish in Rain
            case ABILITY_RAIN_DISH:
                if (IsBattlerWeatherAffected(battler, B_WEATHER_RAIN) && !IsBattlerAtMaxHp(battler))
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
                if (IsBattlerWeatherAffected(battler, B_WEATHER_SUN) && !IsBattlerAtMaxHp(battler))
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
                if (IsBattlerWeatherAffected(battler, B_WEATHER_RAIN) && gBattleMons[battler].status1 & STATUS1_ANY)
                {
                    goto ABILITY_HEAL_MON_STATUS;
                }
                break;
            case ABILITY_MUDAR:
                if ((gBattleMons[battler].status1 & STATUS1_ANY) && PorcentajeAleatorio(50))
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
                    if (gBattleMons[battler].status1 & (STATUS1_CONGELACION))
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
                if (CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR) && !EsPrimerTurno(battler))
                {
                    SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                    BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_BAD_DREAMS:
                BattleScriptPushCursorAndCallback(BattleScript_BadDreamsActivates);
                effect++;
                break;
            case ABILITY_HEALER:
                gBattleScripting.battler = ALIADO(battler);
                if (IsBattlerAlive(gBattleScripting.battler) && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY && PorcentajeAleatorio(30))
                {
                    BattleScriptPushCursorAndCallback(BattleScript_HealerActivates);
                    effect++;
                }
                break;
            }
        }
        break;
    case ABILITYEFFECT_WOULD_BLOCK:
        effect = CanAbilityBlockMove(gBattlerAttacker, battler, move, gLastUsedAbility);
        if (effect && gLastUsedAbility != 0xFFFF)
            RecuerdaHabilidad(battler, gLastUsedAbility);
        break;
    case ABILITYEFFECT_MOVES_BLOCK:
    {
        effect = CanAbilityBlockMove(gBattlerAttacker, battler, move, gLastUsedAbility);
        const u8 *battleScriptBlocksMove = NULL;
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
            battleScriptBlocksMove = ScriptCombate_ActivacionExuvia;
            break;
        default:
            if (GetChosenMovePriority(gBattlerAttacker) > 0 && BlocksPrankster(move, gBattlerAttacker, gBattlerTarget, TRUE) && !(EsMovimientoDeEstado(move) && (gLastUsedAbility == ABILITY_ESPEJO_MAGICO)))
            {
                if (!EsContraEntrenador() || !(GetBattlerMoveTargetType(gBattlerAttacker, move) & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY)))
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
            RecuerdaHabilidad(battler, gLastUsedAbility);
        return effect;
    case ABILITYEFFECT_ABSORBING:
    {
        u32 statId = 0;
        u32 statAmount = 1;
        effect = CanAbilityAbsorbMove(gBattlerAttacker, battler, gLastUsedAbility, move, moveType);
        if (effect)
        {
            switch (gLastUsedAbility)
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
            }
        }
        switch (effect)
        {
        case MOVE_ABSORBED_BY_DRAIN_HP_ABILITY:
            if (IsBattlerAtMaxHp(battler))
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
            if (!(gBattleResources->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
            {
                gMensajeBatalla = B_MSG_FLASH_FIRE_BOOST;
                if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                    gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                else
                    gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                gBattleResources->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
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
            gCombate.contadorMultigolpes = 0; // Prevent multi-hit moves from hitting more than once after move has been absorbed.
    }
    break;
    case ABILITYEFFECT_MOVE_END:
        switch (gLastUsedAbility)
        {
        case ABILITY_JUSTIFIED:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && (moveType == TIPO_SINIESTRO || moveType == TIPO_DRAGON || moveType == TIPO_FANTASMA) && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && (moveType == TIPO_SINIESTRO || moveType == TIPO_BICHO || moveType == TIPO_FANTASMA) && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_ALAS_HIDROFOBAS:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && moveType == TIPO_AGUA && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_STAMINA:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattlerAttacker != gBattlerTarget && HaSidoDaniado(battler) && IsBattlerAlive(battler) && CompareStat(battler, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_DEFENSA, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_IRA_PRIMATE:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattlerAttacker != gBattlerTarget && HaSidoDaniado(battler) && IsBattlerAlive(battler) && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_COLERA:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && MenosDeMediaVida(battler) && (gCombate.contadorMultigolpes == 0 || gCombate.contadorMultigolpes == 1) && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)) && CompareStat(battler, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_CABLE_PELADO:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && MenosDeMediaVida(battler) && (gCombate.contadorMultigolpes == 0 || gCombate.contadorMultigolpes == 1) && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)) && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && EsMovimientoFisico(gCurrentMove) && (CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR) // Don't activate if both Speed and Defense cannot be raised.
                                                                                                                                                                 || CompareStat(battler, ESTADISTICA_DEFENSA, ESTADISTICA_MENOS_6, COMPARACION_MAYOR)))
            {
                if (gMovesInfo[gCurrentMove].effect == EFFECT_HIT_ESCAPE && CanBattlerSwitch(gBattlerAttacker))
                    gProtectStructs[battler].disableEjectPack = TRUE; // Set flag for target

                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WeakArmorActivates;
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(gBattlerAttacker) && gDisableStructs[gBattlerAttacker].disabledMove == MOVE_NONE && IsBattlerAlive(gBattlerAttacker) && gBattleMons[gBattlerAttacker].pp[gChosenMovePos] != 0 && PorcentajeAleatorio(50))
            {
                gDisableStructs[gBattlerAttacker].disabledMove = gChosenMove;
                gDisableStructs[gBattlerAttacker].disableTimer = 4;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CursedBodyActivates;
                effect++;
            }
            break;
        case ABILITY_ANGER_POINT:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gEsGolpeCritico && HaSidoDaniado(battler) && IsBattlerAlive(battler) && CompareStat(battler, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                SET_STATCHANGER(ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6 - gBattleMons[battler].statStages[ESTADISTICA_ATAQUE], FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetsStatWasMaxedOut;
                effect++;
            }
            break;
        case ABILITY_GOOEY:
        case ABILITY_TANGLING_HAIR:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && (CompareStat(gBattlerAttacker, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, COMPARACION_MAYOR) || HabilidadCombatiente(gBattlerAttacker) == ABILITY_MIRROR_ARMOR) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerAttacker) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerAttacker) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = ScriptCombate_ActivacionHabilidadDanioAtacante;
                effect++;
            }
            break;
        case ABILITY_RENCOR:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerAttacker))
                ;
            {
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = ScriptCombate_ActivacionHabilidadDanioAtacante;
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && !IsBattlerAlive(gBattlerTarget) && IsBattlerAlive(gBattlerAttacker) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker))
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
        case ABILITY_PSICODELICO:
        {
            u32 ability = HabilidadCombatiente(gBattlerAttacker);
            if ((!EsTipo(gBattlerAttacker, TIPO_PLANTA)) && ability != ABILITY_OVERCOAT && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES && (PorcentajeAleatorio(50)))
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
                    HABILIDAD_CAUSA_ESTADO_SI_CONTACTA(PuedeSerCongelado, EFECTO_MOVIMIENTO_CONGELACION);
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerAttacker].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerAttacker) && CanBeParalyzed(gBattlerAttacker, HabilidadCombatiente(gBattlerAttacker)) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker) && (gBattleMons[gBattlerTarget].status1 & STATUS1_SLEEP))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerTarget) && IsBattlerAlive(gBattlerTarget) && (PorcentajeAleatorio(50)) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION) && AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_OBLIVIOUS && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker))
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                effect++;
            }
            break;
        case ABILITY_NUEVE_COLAS:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerAttacker].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && (IsMoveMakingContact(move, gBattlerAttacker)) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
            {
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_CURSED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_NueveColas;
                effect++;
            }
            break;
        case ABILITY_PARASITO:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerAttacker].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && (IsMoveMakingContact(move, gBattlerAttacker)) && HaSidoDaniado(gBattlerTarget) && !(gStatuses3[gBattlerAttacker] & STATUS3_LEECHSEED) && !(EsTipo(gBattlerAttacker, TIPO_PLANTA)) && PorcentajeAleatorio(50))
            {
                gStatuses3[gBattlerAttacker] |= STATUS3_LEECHSEED;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_Parasito;
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerTarget))
            {
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_CottonDownActivates;
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(battler) && IsBattlerAlive(battler) && CompareStat(battler, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, COMPARACION_MENOR) && (moveType == TIPO_FUEGO || moveType == TIPO_AGUA))
            {
                gEffectBattler = battler;
                SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 6, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_TargetAbilityStatRaiseRet;
                effect++;
            }
            break;
        case ABILITY_WIND_POWER:
            if (!(gMovesInfo[gCurrentMove].windMove))
                break;
            // fall through
        case ABILITY_ELECTROMORPHOSIS:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && HaSidoDaniado(gBattlerTarget) && IsBattlerAlive(gBattlerTarget))
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_WindPowerActivates;
                effect++;
            }
            break;
        case ABILITY_PUNZON:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && EsMovimientoFisico(gCurrentMove) && HaSidoDaniado(gBattlerTarget) && (gSideTimers[gBattlerAttacker].spikesAmount != 2))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBePoisoned(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].bitingMove) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBePoisoned(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].punzante) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(move, gBattlerAttacker) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBeBurned(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].type == TIPO_PSIQUICO) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBeParalyzed(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].type == TIPO_LUCHA) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBeSlept(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].soundMove) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && PuedeSerCongelado(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].soundMove) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
            {
                gBattleScripting.moveEffect = EFECTO_MOVIMIENTO_CONGELACION;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AbilityStatusEffect;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITY_ULTRASONIDO:
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].hp != 0 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && CanBeSlept(gBattlerTarget, HabilidadCombatiente(gBattlerTarget)) && (gMovesInfo[move].soundMove) && HaSidoDaniado(gBattlerTarget) && PorcentajeAleatorio(50))
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
    case ABILITYEFFECT_IMMUNITY:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            switch (HabilidadCombatiente(battler))
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
            case ABILITY_TIERRA_HUMEDA:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    StringCopy(gBattleTextBuff1, gText_Burn);
                    effect = 1;
                }
                break;
            case ABILITY_MAGMA_ARMOR:
                if (gBattleMons[battler].status1 & STATUS1_CONGELACION)
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
                gCombate->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (B_SYNCHRONIZE_TOXIC < GEN_5 && gCombate->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gCombate->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gCombate->synchronizeMoveEffect + MOVE_EFFECT_AFFECTS_USER;
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
                gCombate->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gCombate->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gCombate->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleScripting.moveEffect = gCombate->synchronizeMoveEffect;
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
            if (gBattleMons[i].ability == ABILITY_NEUTRALIZING_GAS && !(gBattleResources->flags[i] & RESOURCE_FLAG_NEUTRALIZING_GAS))
            {
                gBattleResources->flags[i] |= RESOURCE_FLAG_NEUTRALIZING_GAS;
                gBattlerAbility = i;
                gMensajeBatalla = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
                BattleScriptPushCursorAndCallback(BattleScript_SwitchInAbilityMsg);
                effect++;
            }

            if (effect != 0)
                break;
        }
        break;
    case ABILITYEFFECT_ON_WEATHER: // For ability effects that activate when the battle weather changes.
        gLastUsedAbility = HabilidadCombatiente(battler);
        switch (gLastUsedAbility)
        {
        case ABILITY_FORECAST:
            if ((IsBattlerWeatherAffected(battler, gBattleWeather) || gBattleWeather == B_WEATHER_NONE || !WEATHER_HAS_EFFECT) // Air Lock active
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
        RecuerdaHabilidad(battler, gLastUsedAbility);
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
    return ((IsMoldBreakerTypeAbility(battlerAtk, ability) || gMovesInfo[gCurrentMove].ignoresTargetAbility) && battlerDef != battlerAtk && gAbilitiesInfo[gBattleMons[battlerDef].ability].breakable && gBattlerByTurnOrder[gCurrentTurnActionNumber] == battlerAtk && gActionsByTurnOrder[gCurrentTurnActionNumber] == B_ACTION_USE_MOVE && gCurrentTurnActionNumber < gBattlersCount);
}

u32 HabilidadCombatiente(u32 combatiente)
{
    bool32 noAbilityShield = GetBattlerHoldEffectIgnoreAbility(combatiente, TRUE) != HOLD_EFFECT_ABILITY_SHIELD;

    if (gStatuses3[combatiente] & STATUS3_GASTRO_ACID)
        return ABILITY_NONE;

    if (IsNeutralizingGasOnField() && gBattleMons[combatiente].ability != ABILITY_NEUTRALIZING_GAS && noAbilityShield)
        return ABILITY_NONE;

    if (noAbilityShield && CanBreakThroughAbility(gBattlerAttacker, combatiente, gBattleMons[gBattlerAttacker].ability))
        return ABILITY_NONE;

    return gBattleMons[combatiente].ability;
}

u32 QueCombatienteTieneHabilidad(u32 habilidad)
{
    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        if (IsBattlerAlive(combatiente) && HabilidadCombatiente(combatiente) == habilidad)
            return combatiente;
    }
    return 0xFF;
}

bool32 EstaHabilidadEnElLadoDeCombatiente(u32 combatiente, u32 habilidad)
{
    if (IsBattlerAlive(combatiente) && HabilidadCombatiente(combatiente) == habilidad)
        return TRUE;
    else if (IsBattlerAlive(ALIADO(combatiente)) && HabilidadCombatiente(ALIADO(combatiente)) == habilidad)
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
        if (IsBattlerAlive(combatiente) && HabilidadCombatiente(combatiente) == habilidad)
            return TRUE;
    }

    return FALSE;
}

bool32 HabilidadImpideCambiar(u32 combatiente)
{
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_SHADOW_TAG) && EstaCombatienteEnSuelo(combatiente))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_ARENA_TRAP) && EstaCombatienteEnSuelo(combatiente))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_IMAN) && EsTipo(combatiente, TIPO_ACERO))
        return TRUE;
    if (EstaHabilidadEnCampoContrario(combatiente, ABILITY_MATAMOSCAS) && EsTipo(combatiente, TIPO_BICHO))
        return TRUE;

    return FALSE;
}

bool32 PuedeCambiar(u32 combatiente)
{
    if (GetBattlerHoldEffect(combatiente, TRUE) == HOLD_EFFECT_SHED_SHELL)
        return TRUE;
    if (EsTipo(combatiente, TIPO_FANTASMA))
        return TRUE;
    if (HabilidadCombatiente(combatiente) == ABILITY_HUIDIZO)
        return TRUE;
    if (gBattleMons[combatiente].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        return FALSE;
    if (gStatuses3[combatiente] & (STATUS3_ROOTED))
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
    if (ability == ABILITY_INSOMNIA || ability == ABILITY_VITAL_SPIRIT || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD || gBattleMons[battler].status1 & STATUS1_ANY)
        return FALSE;
    return TRUE;
}

bool32 CanBePoisoned(u32 battler, u32 ability)
{
    if (!(CanPoisonType(battler)) || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD || gBattleMons[battler].status1 & STATUS1_ANY || ability == ABILITY_IMMUNITY)
        return FALSE;
    return TRUE;
}

bool32 CanBeBurned(u32 battler, u32 ability)
{
    if (EsTipo(battler, TIPO_FUEGO) || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD || gBattleMons[battler].status1 & STATUS1_ANY || ability == ABILITY_WATER_VEIL || ability == ABILITY_TIERRA_HUMEDA)
        return FALSE;
    return TRUE;
}

bool32 CanBeParalyzed(u32 battler, u32 ability)
{
    if ((EsTipo(battler, TIPO_ELECTRICO)) || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD || ability == ABILITY_LIMBER || gBattleMons[battler].status1 & STATUS1_ANY)
        return FALSE;
    return TRUE;
}

bool32 PuedeSerCongelado(u32 combatiente, u32 habilidad)
{
    if (EsTipo(combatiente, TIPO_HIELO) || gSideStatuses[GetBattlerSide(combatiente)] & SIDE_STATUS_SAFEGUARD || habilidad == ABILITY_MAGMA_ARMOR || gBattleMons[combatiente].status1 & STATUS1_ANY)
        return FALSE;
    return TRUE;
}

bool32 CanBeConfused(u32 battler)
{
    if (HabilidadCombatiente(battler) == ABILITY_OWN_TEMPO || gBattleMons[battler].status2 & STATUS2_CONFUSION)
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

    if (hpFraction <= 4 && HabilidadCombatiente(battler) == ABILITY_GLUTTONY && isBerry && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2)
    {
        RecuerdaHabilidad(battler, ABILITY_GLUTTONY);
        return TRUE;
    }

    return FALSE;
}

static u8 HealConfuseBerry(u32 battler, u32 itemId, u32 flavorId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battler, (B_CONFUSE_BERRIES_HEAL >= GEN_7 ? 4 : 2), itemId))
    {
        PREPARE_FLAVOR_BUFFER(gBattleTextBuff1, flavorId);

        gBattleMoveDamage = CuantosPSMaximos(battler) / GetBattlerItemHoldEffectParam(battler, itemId);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

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
    return 0;
}

static u8 RandomStatRaiseBerry(u32 battler, u32 itemId, bool32 end2)
{
    return 0;
}

static u8 TrySetMicleBerry(u32 battler, u32 itemId, bool32 end2)
{
    if (HasEnoughHpToEatBerry(battler, 4, itemId))
    {
        gCombate->usedMicleBerry |= 1u << battler;
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
    if (IsBattlerAlive(battler) && CompareStat(battler, statId, ESTADISTICA_MAS_6, COMPARACION_MENOR) && (gBattleScripting.overrideBerryRequirements || (!DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && CategoriaMovimiento(gCurrentMove) == category && battler != gBattlerAttacker && HaSidoDaniado(battler))))
    {
        BufferStatChange(battler, statId, STRINGID_STATROSE);

        gEffectBattler = battler;
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
        u32 maxPP = PPMovimiento(move);
        if (move && (currentPP == 0 || (gBattleScripting.overrideBerryRequirements && currentPP != maxPP)))
        {
            u32 ppRestored = GetBattlerItemHoldEffectParam(battler, itemId);

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
            gBattleMons[battler].pp[i] = changedPP;
            return ITEM_PP_CHANGE;
        }
    }
    return 0;
}

static u8 ItemHealHp(u32 battler, u32 itemId, bool32 end2, bool32 percentHeal)
{
    if (!(gBattleScripting.overrideBerryRequirements && gBattleMons[battler].hp == gBattleMons[battler].maxHP) && HasEnoughHpToEatBerry(battler, 2, itemId))
    {
        if (percentHeal)
            gBattleMoveDamage = (CuantosPSMaximos(battler) * GetBattlerItemHoldEffectParam(battler, itemId) / 100) * -1;
        else
            gBattleMoveDamage = GetBattlerItemHoldEffectParam(battler, itemId) * -1;

        gBattlerAbility = battler; // in SWSH, berry juice shows ability pop up but has no effect. This is mimicked here
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
        gMensajeBatalla = B_MSG_MENTALHERBCURE_INFATUATION; // STRINGID_TARGETGOTOVERINFATUATION
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
            gMensajeBatalla = B_MSG_MENTALHERBCURE_ENCORE; // STRINGID_PKMNENCOREENDED
            ret = TRUE;
        }
        // Check torment
        if (gBattleMons[battler].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battler].status2 &= ~STATUS2_TORMENT;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_TORMENT;
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
    case HOLD_EFFECT_KEE_BERRY: // consume and boost defense if used physical move
        if (B_BERRIES_INSTANT >= GEN_4)
            effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA, CATEGORIA_FISICA);
        break;
    case HOLD_EFFECT_MARANGA_BERRY: // consume and boost sp. defense if used special move
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
        if (gBattleMons[battler].status1 & STATUS1_CONGELACION && !UnnerveOn(battler, gLastUsedItem))
        {
            gBattleMons[battler].status1 &= ~STATUS1_CONGELACION;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
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

            if (gBattleMons[battler].status1 & STATUS1_CONGELACION)
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
                if (GetBattlerSide(battler) == LADO_JUGADOR && !gCombate->moneyMultiplierItem)
                {
                    gCombate->moneyMultiplier *= 2;
                    gCombate->moneyMultiplierItem = 1;
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
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (B_BERRIES_INSTANT >= GEN_4)
                    effect = RandomStatRaiseBerry(battler, gLastUsedItem, TRUE);
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (B_BERRIES_INSTANT >= GEN_4 && gBattleMons[battler].status1 & STATUS1_PARALYSIS && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battler].status1 & STATUS1_PSN_ANY) && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battler].status1 & STATUS1_BURN) && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_BURN;
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battler].status1 & STATUS1_CONGELACION) && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_CONGELACION;
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battler].status1 & STATUS1_SLEEP) && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (B_BERRIES_INSTANT >= GEN_4 && (gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION) && !UnnerveOn(battler, gLastUsedItem))
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
                    if (gBattleMons[battler].status1 & STATUS1_CONGELACION)
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
                if (gProtectStructs[battler].statFell && gProtectStructs[battler].disableEjectPack == 0 && CountUsablePartyMons(battler) > 0 && !(gCurrentMove == MOVE_PARTING_SHOT && CanBattlerSwitch(gBattlerAttacker))) // Does not activate if attacker used Parting Shot and can switch out
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
                if (EsTipo(battler, TIPO_VENENO))
                {
                    goto LEFTOVERS;
                }
                else if (HabilidadCombatiente(battler) != ABILITY_MAGIC_GUARD && !moveTurn)
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
                if (gBattleMons[battler].hp < gBattleMons[battler].maxHP && !moveTurn)
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
                if (gBattleMons[battler].status1 & STATUS1_CONGELACION && !UnnerveOn(battler, gLastUsedItem))
                {
                    gBattleMons[battler].status1 &= ~STATUS1_CONGELACION;
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
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
                    if (gBattleMons[battler].status1 & STATUS1_CONGELACION)
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
    case ITEMEFFECT_LIFEORB:
        // Occur after the final hit of a multi-strike move
        if (atkHoldEffect == HOLD_EFFECT_LIFE_ORB && IsBattlerAlive(gBattlerAttacker) && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_MAGIC_GUARD && !gProtectStructs[gBattlerAttacker].confusionSelfDmg && !gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage && gSpecialStatuses[gBattlerAttacker].damagedMons)
        {
            gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 16;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            effect = ITEM_HP_CHANGE;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ItemHurtRet;
            gLastUsedItem = atkItem;
        }
        break;
    case ITEMEFFECT_TARGET:
        if (MovimientoEsEfectivo(gCombate->resultadoMovimiento))
        {
            moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_AIR_BALLOON:
                if (HaSidoDaniado(gBattlerAttacker))
                {
                    effect = ITEM_EFFECT_OTHER;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AirBaloonMsgPop;
                }
                break;
            case HOLD_EFFECT_ROCKY_HELMET:
                if (HaSidoDaniado(gBattlerAttacker) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(gCurrentMove, gBattlerAttacker) && IsBattlerAlive(gBattlerAttacker) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
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
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && gCombate->resultadoMovimiento == MOVIMIENTO_SUPER_EFECTIVO)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WeaknessPolicy;
                }
                break;
            case HOLD_EFFECT_SNOWBALL:
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && moveType == TIPO_HIELO)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_DEFENSA, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_LUMINOUS_MOSS:
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && moveType == TIPO_AGUA)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_DEFENSA_ESPECIAL, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_CELL_BATTERY:
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && moveType == TIPO_ELECTRICO)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_ABSORB_BULB:
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && moveType == TIPO_AGUA)
                {
                    effect = ITEM_STATS_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_TargetItemStatRaise;
                    SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE);
                }
                break;
            case HOLD_EFFECT_ENIGMA_BERRY:
                break;
            case HOLD_EFFECT_JABOCA_BERRY: // consume and damage attacker if used physical move
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && EsMovimientoFisico(gCurrentMove) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battler, HOLD_EFFECT_JABOCA_BERRY);
                }
                break;
            case HOLD_EFFECT_ROWAP_BERRY: // consume and damage attacker if used special move
                if (IsBattlerAlive(battler) && HaSidoDaniado(battler) && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && EsMovimientoEspecial(gCurrentMove) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;

                    effect = ITEM_HP_CHANGE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_JabocaRowapBerryActivates;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    RecordItemEffectBattle(battler, HOLD_EFFECT_ROWAP_BERRY);
                }
                break;
            case HOLD_EFFECT_KEE_BERRY: // consume and boost defense if used physical move
                effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA, CATEGORIA_FISICA);
                break;
            case HOLD_EFFECT_MARANGA_BERRY: // consume and boost sp. defense if used special move
                effect = DamagedStatBoostBerryEffect(battler, ESTADISTICA_DEFENSA_ESPECIAL, CATEGORIA_ESPECIAL);
                break;
            case HOLD_EFFECT_STICKY_BARB:
                if (HaSidoDaniado(gBattlerAttacker) && (MovimientoEsEfectivo(gCombate->resultadoMovimiento)) && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_PROTECTIVE_PADS && IsMoveMakingContact(gCurrentMove, gBattlerAttacker) && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && IsBattlerAlive(gBattlerAttacker) && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
                {
                    // No sticky hold checks.
                    gEffectBattler = battler;                          // gEffectBattler = target
                    StealTargetItem(gBattlerAttacker, gBattlerTarget); // Attacker takes target's barb
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
        u16 battlerAbility = HabilidadCombatiente(battler);
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_TOXIC_ORB:
            if (CanBePoisoned(battler, HabilidadCombatiente(battler)))
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
        case HOLD_EFFECT_STICKY_BARB: // Not an orb per se, but similar effect, and needs to NOT activate with pickpocket
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
        gCombate->ateBerry[battler & BIT_SIDE] |= 1u << gBattlerPartyIndexes[battler];

    return effect;
}

void ClearVariousBattlerFlags(u32 battler)
{
    gDisableStructs[battler].furyCutterCounter = 0;
    gBattleMons[battler].status2 &= ~STATUS2_DESTINY_BOND;
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
    u32 moveType = TipoMovimiento(move, gBattlerAttacker);

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
            if (moveType == TIPO_ELECTRICO && EstaHabilidadEnCampoContrario(gBattlerAttacker, ABILITY_LIGHTNING_ROD) && HabilidadCombatiente(targetBattler) != ABILITY_LIGHTNING_ROD)
            {
                targetBattler ^= BIT_FLANK;
                RecuerdaHabilidad(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].lightningRodRedirected = TRUE;
            }
            else if (moveType == TIPO_AGUA && EstaHabilidadEnCampoContrario(gBattlerAttacker, ABILITY_STORM_DRAIN) && HabilidadCombatiente(targetBattler) != ABILITY_STORM_DRAIN)
            {
                targetBattler ^= BIT_FLANK;
                RecuerdaHabilidad(targetBattler, gBattleMons[targetBattler].ability);
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

    *(gCombate->moveTarget + gBattlerAttacker) = targetBattler;

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
        return FALSE;
    }
    else if ((atkHoldEffect == HOLD_EFFECT_PUNCHING_GLOVE && gMovesInfo[move].punchingMove) || HabilidadCombatiente(battlerAtk) == ABILITY_NINJA || HabilidadCombatiente(battlerAtk) == ABILITY_LONG_REACH)
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
    if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_CRAFTY_SHIELD && EsMovimientoDeEstado(move))
        return TRUE;
    else if (gMovesInfo[move].ignoresProtect)
        return FALSE;
    else if (gProtectStructs[battlerDef].protected)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_WIDE_GUARD && GetBattlerMoveTargetType(gBattlerAttacker, move) & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
        return TRUE;
    else if (gProtectStructs[battlerDef].spikyShielded)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_QUICK_GUARD && GetChosenMovePriority(gBattlerAttacker) > 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_MAT_BLOCK && !EsMovimientoDeEstado(move))
        return TRUE;
    else
        return FALSE;
}

static bool32 EstaCombatienteEnSuelo(u32 combatiente)
{
    u32 holdEffect = GetBattlerHoldEffect(combatiente, TRUE);

    if (holdEffect == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    if (gStatuses3[combatiente] & STATUS3_ROOTED)
        return TRUE;
    if (gStatuses3[combatiente] & STATUS3_SMACKED_DOWN)
        return TRUE;
    if (gStatuses3[combatiente] & STATUS3_TELEKINESIS)
        return FALSE;
    if (gStatuses3[combatiente] & STATUS3_MAGNET_RISE)
        return FALSE;
    if (holdEffect == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    if ((AI_DATA->aiCalcInProgress ? AI_DATA->abilities[combatiente] : HabilidadCombatiente(combatiente)) == ABILITY_LEVITATE)
        return FALSE;
    if (EsTipo(combatiente, TIPO_VOLADOR))
        return FALSE;
    return TRUE;
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
        return !(gAbsentBattlerFlags & (1u << battlerDef)) + !(gAbsentBattlerFlags & (1u << ALIADO(battlerDef)));
    case MOVE_TARGET_FOES_AND_ALLY:
        return !(gAbsentBattlerFlags & (1u << battlerDef)) + !(gAbsentBattlerFlags & (1u << ALIADO(battlerDef))) + !(gAbsentBattlerFlags & (1u << ALIADO(battlerAtk)));
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
        48, 20};

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
    {
        100, 20,
        250, 40,
        500, 60,
        1000, 80,
        2000, 100,
        0xFFFF, 0xFFFF};

static const u8 sSpeedDiffPowerTable[] = {40, 60, 80, 120, 150};
static const u8 sHeatCrashPowerTable[] = {40, 40, 60, 80, 100, 120};

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
    case EFFECT_FURY_CUTTER:
        basePower = CalcFuryCutterBasePower(basePower, gDisableStructs[battlerAtk].furyCutterCounter);
        break;
    case EFFECT_ROLLOUT:
        basePower = CalcRolloutBasePower(battlerAtk, basePower, gDisableStructs[battlerAtk].rolloutTimer);
        break;
    case EFFECT_MAGNITUDE:
        basePower = gCombate->magnitudeBasePower;
        break;
    case EFFECT_PRESENT:
        basePower = gCombate->presentBasePower;
        break;
    case EFFECT_SPIT_UP:
        basePower = 100 * gDisableStructs[battlerAtk].stockpileCounter;
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
        if ((gBattleMons[battlerDef].status1 & gMovesInfo[move].argument) && !((gMovesInfo[move].additionalEffects->moveEffect == MOVE_EFFECT_REMOVE_STATUS) && DoesSubstituteBlockMove(battlerAtk, battlerDef, move)))
        {
            basePower *= 2;
        }
        break;
    case EFFECT_POWER_BASED_ON_TARGET_HP:
        basePower = gBattleMons[battlerDef].hp * basePower / gBattleMons[battlerDef].maxHP;
        break;
    case EFFECT_ASSURANCE:
        if (HaSidoDaniado(battlerDef) != 0)
            basePower *= 2;
        break;
    case EFFECT_ACROBATICS:
        if (gBattleMons[battlerAtk].item == ITEM_NONE
            // Edge case, because removal of items happens after damage calculation.
            || (gSpecialStatuses[battlerAtk].potenciadoGema && GetBattlerHoldEffect(battlerAtk, FALSE) == HOLD_EFFECT_GEMS))
            basePower *= 2;
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
        // gCombate->sameMoveTurns incremented in ppreduce
        if (gCombate->sameMoveTurns[battlerAtk] != 0)
        {
            basePower += (basePower * gCombate->sameMoveTurns[battlerAtk]);
            if (basePower > 200)
                basePower = 200;
        }
        break;
    case EFFECT_PAYBACK:
        if (GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef) && !EsPrimerTurno(battlerDef))
        {
            basePower *= 2;
        }
        break;
    case EFFECT_LASH_OUT:
        if (gProtectStructs[battlerAtk].statFell)
            basePower *= 2;
        break;
    case EFFECT_EXPLOSION:
        break;
    case EFFECT_RAGE_FIST:
        basePower += 25 * gCombate->timesGotHit[GetBattlerSide(battlerAtk)][gBattlerPartyIndexes[battlerAtk]];
        basePower = (basePower > 200) ? 200 : basePower;
        break;
    case EFFECT_LAST_RESPECTS:
        basePower += (basePower * min(100, GetBattlerSideFaintCounter(battlerAtk)));
        break;
    case EFFECT_VUDU:
        basePower = gCombate->potenciaMovimientosRecibidosTurno[battlerAtk];
        if (basePower < 10)
            basePower = 10;
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
    u32 basePower = CalcMoveBasePower(damageCalcData, defAbility, weather);
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    uq4_12_t modifier = MOVIMIENTO_NEUTRO;
    u32 atkSide = GetBattlerSide(battlerAtk);

    // move effect
    switch (gMovesInfo[move].effect)
    {
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS | STATUS1_CONGELACION))
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    case EFFECT_RETALIATE:
        if (gSideTimers[atkSide].retaliateTimer == 1)
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    }

    if (gSpecialStatuses[battlerAtk].potenciadoGema)
        MULTIPLICA(modifier, MAS_50_POR_CIENTO);

    if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP && moveType == TIPO_ELECTRICO)
        MULTIPLICA(modifier, MAS_100_POR_CIENTO);

    // attacker's abilities
    switch (atkAbility)
    {
    case ABILITY_TECHNICIAN:
        if (basePower <= 60)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_FLARE_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && EsMovimientoEspecial(move))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_TOXIC_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && EsMovimientoFisico(move))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_AUDAZ:
        if (HaceDanioRetroceso(move))
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_IRON_FIST:
        if (gMovesInfo[move].punchingMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_PATADA_FEROZ:
        if (gMovesInfo[move].patada)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_SHEER_FORCE:
        if (MoveIsAffectedBySheerForce(move))
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_SAND_FORCE:
        if ((moveType == TIPO_ACERO || moveType == TIPO_ROCA || moveType == TIPO_TIERRA) && weather & B_WEATHER_SANDSTORM)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_RIVALRY:
        if (AreBattlersOfSameGender(battlerAtk, battlerDef))
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_ANALYTIC:
    case ABILITY_AGRESIVIDAD:
        if (GetBattlerTurnOrderNum(battlerAtk) == gBattlersCount - 1 && move != MOVE_FUTURE_SIGHT && move != MOVE_DOOM_DESIRE)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_TOUGH_CLAWS:
        if (IsMoveMakingContact(move, battlerAtk))
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_MANDIBULA_FUERTE:
    case ABILITY_NAVAJAS:
        if (gMovesInfo[move].bitingMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_MEGADISPARADOR:
        if (gMovesInfo[move].balistico)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_CARPINTERO:
        if (gMovesInfo[move].punzante)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_MARTILLADOR:
        if (gMovesInfo[move].hammerMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_DINOCOLA:
        if (gMovesInfo[move].tailMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_CORNAMENTA:
        if (gMovesInfo[move].punzante)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_LENGUALARGA:
        if (gMovesInfo[move].lickMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_ESCALOFRIO:
        if (moveType == TIPO_HIELO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_STEELWORKER:
        if (moveType == TIPO_ACERO)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_PIXILATE:
        if (moveType == TIPO_HADA)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_GALVANIZE:
        if (moveType == TIPO_ELECTRICO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_REFRIGERATE:
        if (moveType == TIPO_HIELO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_CELESTE:
        if (moveType == TIPO_VOLADOR)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_VIDAS_PASADAS:
        if (moveType == TIPO_FANTASMA)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_EXTRASENSORIAL:
        if (moveType == TIPO_PSIQUICO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_LUNA_MENGUANTE:
        if (moveType == TIPO_SINIESTRO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_NORMALIDAD:
        if (moveType == TIPO_NORMAL)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_SURFERO:
        if (moveType == TIPO_AGUA)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_PUNK_ROCK:
        if (gMovesInfo[move].soundMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_PERCUSIONISTA:
        if (gMovesInfo[move].soundMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_ARTES_OSCURAS:
    case ABILITY_NOCTURNO:
        if (moveType == TIPO_SINIESTRO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_EN_METALICO:
        if (moveType == TIPO_ACERO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_VENENOSO:
        if (moveType == TIPO_VENENO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_STEELY_SPIRIT:
        if (moveType == TIPO_ACERO)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_TRANSISTOR:
        if (moveType == TIPO_ELECTRICO)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_DRAGONS_MAW:
        if (moveType == TIPO_DRAGON)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_GORILLA_TACTICS:
        if (EsMovimientoFisico(move))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_TERRESTRE:
        if (moveType == TIPO_TIERRA)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_SHARPNESS:
        if (gMovesInfo[move].slicingMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_CARA_DURA:
        if (gMovesInfo[move].headMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    }

    // attacker partner's abilities
    if (IsBattlerAlive(ALIADO(battlerAtk)))
    {
        switch (HabilidadCombatiente(ALIADO(battlerAtk)))
        {
        case ABILITY_BATTERY:
            if (EsMovimientoEspecial(move))
                MULTIPLICA(modifier, MAS_25_POR_CIENTO);
            break;
        case ABILITY_POWER_SPOT:
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
            break;
        case ABILITY_STEELY_SPIRIT:
            if (moveType == TIPO_ACERO)
                MULTIPLICA(modifier, MAS_50_POR_CIENTO);
            break;
        }
    }

    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (EsMovimientoFisico(move))
            MULTIPLICA(modifier, MAS_12_5_POR_CIENTO);
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (EsMovimientoEspecial(move))
            MULTIPLICA(modifier, MAS_12_5_POR_CIENTO);
        break;
    case HOLD_EFFECT_PUNCHING_GLOVE:
        if (gMovesInfo[move].punchingMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_THROAT_SPRAY:
        if (gMovesInfo[move].soundMove)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
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
            if (holdEffectAtk == sHoldEffectToType[i][TIPO_1])
            {
                if (moveType == sHoldEffectToType[i][TIPO_2])
                    MULTIPLICA(modifier, MAS_25_POR_CIENTO);
                break;
            }
        }
        break;
    }

    return uq4_12_multiply_by_int(modifier, basePower);
}

static inline u32 CalcAttackStat(struct DamageCalculationData *damageCalcData, u32 atkAbility, u32 defAbility, u32 holdEffectAtk, u32 weather)
{
    u32 atkStage, atkStat, atkBaseSpeciesId;
    uq4_12_t modifier = NEUTRO;
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    atkBaseSpeciesId = GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species);

    if (EsMovimientoFisico(move))
    {
        atkStat = gBattleMons[battlerAtk].attack;
        atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE];
    }
    else
    {
        atkStat = gBattleMons[battlerAtk].spAttack;
        atkStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_ATAQUE_ESPECIAL];
    }

    if (damageCalcData->isCrit && atkStage < ESTADISTICA_NEUTRA)
        atkStage = ESTADISTICA_NEUTRA;

    MULTIPLICA(modifier, gMultiplicadorEstadistica[atkStage]);

    switch (atkAbility)
    {
    case ABILITY_PODER_SOLAR:
        if (IsBattlerWeatherAffected(battlerAtk, B_WEATHER_SUN))
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TIPO_FUEGO && gBattleResources->flags[battlerAtk] & RESOURCE_FLAG_FLASH_FIRE)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_SWARM:
        if (moveType == TIPO_BICHO && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_BLAZE:
        if (moveType == TIPO_FUEGO && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_GENERADOR:
        if (moveType == TIPO_ELECTRICO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_ENTUSIASMO:
        MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case ABILITY_AGALLAS:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    }

    switch (defAbility)
    {
    case ABILITY_SEBO:
        if (moveType == TIPO_FUEGO || moveType == TIPO_HIELO)
        {
            MULTIPLICA(modifier, MENOS_50_POR_CIENTO);
            if (damageCalcData->updateFlags)
                RecuerdaHabilidad(battlerDef, ABILITY_SEBO);
        }
        break;
    case ABILITY_ILLUMINATE:
    case ABILITY_GUARDIAN:
        if (moveType == TIPO_SINIESTRO || moveType == TIPO_FANTASMA)
        {
            MULTIPLICA(modifier, MENOS_50_POR_CIENTO);
            if (damageCalcData->updateFlags)
                RecuerdaHabilidad(battlerDef, defAbility);
        }
        break;
    case ABILITY_TIERRA_HUMEDA:
        if (moveType == TIPO_FUEGO)
        {
            MULTIPLICA(modifier, MENOS_50_POR_CIENTO);
            if (damageCalcData->updateFlags)
                RecuerdaHabilidad(battlerDef, ABILITY_TIERRA_HUMEDA);
        }
        break;
    case ABILITY_SHELL_ARMOR:
        if (moveType == TIPO_FUEGO)
        {
            MULTIPLICA(modifier, MENOS_50_POR_CIENTO);
            if (damageCalcData->updateFlags)
                RecuerdaHabilidad(battlerDef, ABILITY_TIERRA_HUMEDA);
        }
        break;
    }

    if (IsBattlerAlive(ALIADO(battlerAtk)))
    {
        if (HabilidadCombatiente(ALIADO(battlerAtk)) == ABILITY_GENERADOR && moveType == TIPO_ELECTRICO)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
    }

    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((atkBaseSpeciesId == SPECIES_CUBONE || atkBaseSpeciesId == SPECIES_MAROWAK) && EsMovimientoFisico(move))
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && EsMovimientoEspecial(move))
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (atkBaseSpeciesId == SPECIES_PICHU || atkBaseSpeciesId == SPECIES_PIKACHU || atkBaseSpeciesId == SPECIES_RAICHU || atkBaseSpeciesId == SPECIES_RAICHU_ALOLA)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_CUCHARA_TORCIDA:
        if (atkBaseSpeciesId == SPECIES_ABRA || atkBaseSpeciesId == SPECIES_KADABRA || atkBaseSpeciesId == SPECIES_ALAKAZAM)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_ELECTRIZADOR:
        if (atkBaseSpeciesId == SPECIES_ELEKID || atkBaseSpeciesId == SPECIES_ELECTABUZZ || atkBaseSpeciesId == SPECIES_ELECTIVIRE)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_MAGMATIZADOR:
    case HOLD_EFFECT_DISCO_EXTRANO:
        if (atkBaseSpeciesId == SPECIES_MAGBY || atkBaseSpeciesId == SPECIES_MAGMAR || atkBaseSpeciesId == SPECIES_MAGMORTAR)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_PROTECTOR:
        if (atkBaseSpeciesId == SPECIES_RHYHORN || atkBaseSpeciesId == SPECIES_RHYDON || atkBaseSpeciesId == SPECIES_RHYPERIOR)
            MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (EsMovimientoFisico(move))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (EsMovimientoEspecial(move))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    }

    return uq4_12_multiply_by_int(modifier, atkStat);
}

static bool32 CanEvolve(u32 species)
{
    u32 i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions != NULL)
    {
        for (i = 0; evolutions[i].method != EVO_FIN; i++)
        {
            if (evolutions[i].method && SanitizeSpeciesId(evolutions[i].targetSpecies) != SPECIES_NONE)
                return TRUE;
        }
    }
    return FALSE;
}

static inline u32 CalcDefenseStat(struct DamageCalculationData *damageCalcData, u32 atkAbility, u32 defAbility, u32 holdEffectDef, u32 weather)
{
    bool32 usesDefStat;
    u32 defStage, defStat, def, spDef;
    uq4_12_t modifier = NEUTRO;
    u32 battlerDef = damageCalcData->battlerDef;
    u32 move = damageCalcData->move;

    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
    {
        def = gBattleMons[battlerDef].spDefense;
        spDef = gBattleMons[battlerDef].defense;
    }
    else
    {
        def = gBattleMons[battlerDef].defense;
        spDef = gBattleMons[battlerDef].spDefense;
    }

    if (gMovesInfo[move].effect == EFFECT_PSYSHOCK || EsMovimientoFisico(move))
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

    if (gMovesInfo[move].ignoresTargetDefenseEvasionStages)
        defStage = ESTADISTICA_NEUTRA;

    MULTIPLICA(modifier, gMultiplicadorEstadisticas[defStage]);

    switch (defAbility)
    {
    case ABILITY_MARVEL_SCALE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY && usesDefStat)
        {
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
            if (damageCalcData->updateFlags)
                RecuerdaHabilidad(battlerDef, ABILITY_MARVEL_SCALE);
        }
        break;
    }

    switch (holdEffectDef)
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && !usesDefStat)
            MULTIPLICA(modifier, MAS_100_POR_CIENTO);
        break;
    case HOLD_EFFECT_EVIOLITE:
        if (CanEvolve(gBattleMons[battlerDef].species))
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (!usesDefStat)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case HOLD_EFFECT_CHALECO_TACTICO:
        if (usesDefStat)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    case HOLD_EFFECT_SOUL_DEW:
        if (B_SOUL_DEW_BOOST < GEN_7 && (gBattleMons[battlerDef].species == SPECIES_LATIAS || gBattleMons[battlerDef].species == SPECIES_LATIOS) && !usesDefStat)
            MULTIPLICA(modifier, MAS_50_POR_CIENTO);
        break;
    }

    if (EsTipo(battlerDef, TIPO_ROCA) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_SANDSTORM) && !usesDefStat)
        MULTIPLICA(modifier, MAS_50_POR_CIENTO);

    if (EsTipo(battlerDef, TIPO_HIELO) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_HAIL) && usesDefStat)
        MULTIPLICA(modifier, MAS_50_POR_CIENTO);

    if (EsTipo(battlerDef, TIPO_HIELO) && IsBattlerWeatherAffected(battlerDef, B_WEATHER_RAIN) && usesDefStat && defAbility == ABILITY_HUMEDAD_RELATIVA)
        MULTIPLICA(modifier, MAS_50_POR_CIENTO);

    if (gBattleMons[battlerDef].status1 & STATUS1_BURN && usesDefStat)
        MULTIPLICA(modifier, MENOS_25_POR_CIENTO);

    return uq4_12_multiply_by_int(modifier, defStat);
}

// base damage formula before adding any modifiers
static inline s32 CalculateBaseDamage(u32 power, u32 userFinalAttack, u32 level, u32 targetFinalDefense)
{
    return power * userFinalAttack * (2 * level / 5 + 2) / targetFinalDefense / 50 + 2;
}

static inline uq4_12_t GetTargetDamageModifier(struct DamageCalculationData *damageCalcData)
{
    if (EsContraEntrenador() && GetMoveTargetCount(damageCalcData) >= 2)
        return MENOS_50_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetParentalBondModifier(u32 battlerAtk)
{
    if (gSpecialStatuses[battlerAtk].parentalBondState != PARENTAL_BOND_2ND_HIT)
        return MOVIMIENTO_NEUTRO;
    return MOVIMIENTO_MUY_POCO_EFECTIVO;
}

static inline uq4_12_t GetSameTypeAttackBonusModifier(struct DamageCalculationData *damageCalcData, u32 abilityAtk)
{
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 moveType = damageCalcData->moveType;

    if (EsTipo(battlerAtk, moveType))
    {
        if (GetBattlerType(battlerAtk, 0) != GetBattlerType(battlerAtk, 1))
            return MAS_25_POR_CIENTO;
        else
            return MAS_50_POR_CIENTO;
    }
    else
        return MOVIMIENTO_NEUTRO;
}

// Utility Umbrella holders take normal damage from what would be rain- and sun-weakened attacks.
static uq4_12_t GetWeatherDamageModifier(struct DamageCalculationData *damageCalcData, u32 holdEffectAtk, u32 holdEffectDef, u32 weather)
{
    u32 move = damageCalcData->move;
    u32 moveType = damageCalcData->moveType;

    if (weather == B_WEATHER_NONE)
        return MOVIMIENTO_NEUTRO;
    if (gMovesInfo[move].effect == EFFECT_HYDRO_STEAM && (weather & B_WEATHER_SUN) && holdEffectAtk != HOLD_EFFECT_UTILITY_UMBRELLA)
        return MAS_50_POR_CIENTO;
    if (holdEffectDef == HOLD_EFFECT_UTILITY_UMBRELLA)
        return MOVIMIENTO_NEUTRO;

    if (weather & B_WEATHER_RAIN)
    {
        if (moveType != TIPO_FUEGO && moveType != TIPO_AGUA)
            return MOVIMIENTO_NEUTRO;
        return (moveType == TIPO_FUEGO) ? MOVIMIENTO_POCO_EFECTIVO : MAS_25_POR_CIENTO;
    }
    if (weather & B_WEATHER_SUN)
    {
        if (moveType != TIPO_FUEGO && moveType != TIPO_AGUA)
            return MOVIMIENTO_NEUTRO;
        return (moveType == TIPO_AGUA) ? MOVIMIENTO_POCO_EFECTIVO : MAS_25_POR_CIENTO;
    }
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t ModificadorQuemaduraCongelacion(const struct DamageCalculationData *datosMovimiento, u32 habilidad)
{
    u32 atacante = datosMovimiento->battlerAtk;
    u32 movimiento = datosMovimiento->move;

    if (habilidad == ABILITY_AGALLAS || gMovesInfo[movimiento].effect == EFFECT_FACADE)
    {
        return MOVIMIENTO_NEUTRO;
    }

    if ((gBattleMons[atacante].status1 & STATUS1_BURN) && EsMovimientoFisico(movimiento))
    {
        return MENOS_25_POR_CIENTO;
    }

    if ((gBattleMons[atacante].status1 & STATUS1_CONGELACION) && EsMovimientoEspecial(movimiento))
    {
        return MENOS_25_POR_CIENTO;
    }

    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetCriticalModifier(bool32 isCrit)
{
    if (isCrit)
        return MAS_50_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetMinimizeModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].minimizeDoubleDamage && gStatuses3[battlerDef] & STATUS3_MINIMIZED)
        return MAS_100_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetUndergroundModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesUnderground && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
        return MAS_100_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetDiveModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesUnderwater && gStatuses3[battlerDef] & STATUS3_UNDERWATER)
        return MAS_100_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetAirborneModifier(u32 move, u32 battlerDef)
{
    if (gMovesInfo[move].damagesAirborneDoubleDamage && gStatuses3[battlerDef] & STATUS3_ON_AIR)
        return MAS_100_POR_CIENTO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetScreensModifier(u32 move, u32 battlerAtk, u32 battlerDef, bool32 isCrit, u32 abilityAtk)
{
    u32 sideStatus = gSideStatuses[GetBattlerSide(battlerDef)];
    bool32 lightScreen = (sideStatus & SIDE_STATUS_LIGHTSCREEN) && EsMovimientoEspecial(move);
    bool32 reflect = (sideStatus & SIDE_STATUS_REFLECT) && EsMovimientoFisico(move);
    bool32 auroraVeil = sideStatus & SIDE_STATUS_AURORA_VEIL;

    if (isCrit || abilityAtk == ABILITY_SIGILOSO || gProtectStructs[battlerAtk].confusionSelfDmg)
        return MOVIMIENTO_NEUTRO;
    if (reflect || lightScreen || auroraVeil)
        return MOVIMIENTO_POCO_EFECTIVO;
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetAttackerAbilitiesModifier(u32 battlerAtk, uq4_12_t typeEffectivenessModifier, bool32 isCrit, u32 abilityAtk)
{
    switch (abilityAtk)
    {
    case ABILITY_SNIPER:
        if (isCrit)
            return MAS_50_POR_CIENTO;
        break;
    case ABILITY_CROMOLENTE:
        if (typeEffectivenessModifier < MOVIMIENTO_NEUTRO)
            return MOVIMIENTO_NEUTRO;
        break;
    }
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetDefenderAbilitiesModifier(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, uq4_12_t typeEffectivenessModifier, u32 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_GUARDA:
        if (typeEffectivenessModifier == MOVIMIENTO_NEUTRO)
            return MOVIMIENTO_POCO_EFECTIVO;
        break;
    }
    return MOVIMIENTO_NEUTRO;
}

static inline uq4_12_t GetAttackerItemsModifier(u32 battlerAtk, uq4_12_t typeEffectivenessModifier, u32 holdEffectAtk)
{
    u32 percentBoost;
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_METRONOME:
        if (gCombate->sameMoveTurns[battlerAtk] > 0)
            return MAS_25_POR_CIENTO;
        break;
    case HOLD_EFFECT_EXPERT_BELT:
        if (typeEffectivenessModifier >= MOVIMIENTO_SUPER_EFECTIVO)
            return MAS_25_POR_CIENTO;
        break;
    case HOLD_EFFECT_LIFE_ORB:
        return MAS_25_POR_CIENTO;
        break;
    }
    return MOVIMIENTO_NEUTRO;
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
            return MOVIMIENTO_NEUTRO;
        if (moveType == holdEffectDefParam && (moveType == TIPO_NORMAL || typeEffectivenessModifier >= MOVIMIENTO_SUPER_EFECTIVO))
        {
            if (damageCalcData->updateFlags)
                gSpecialStatuses[battlerDef].berryReduced = TRUE;
            return MOVIMIENTO_POCO_EFECTIVO;
        }
        break;
    }
    return MOVIMIENTO_NEUTRO;
}

#define DAMAGE_MULTIPLY_MODIFIER(modifier)                        \
    do                                                            \
    {                                                             \
        finalModifier = uq4_12_multiply(modifier, finalModifier); \
    } while (0)

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

    uq4_12_t finalModifier = MOVIMIENTO_NEUTRO;
    u32 battlerDefPartner = ALIADO(battlerDef);
    u32 unmodifiedAttackerSpeed = gBattleMons[battlerAtk].speed;
    u32 unmodifiedDefenderSpeed = gBattleMons[battlerDef].speed;

    DAMAGE_MULTIPLY_MODIFIER(GetMinimizeModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetUndergroundModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetDiveModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetAirborneModifier(move, battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetScreensModifier(move, battlerAtk, battlerDef, isCrit, abilityAtk));

    if (unmodifiedAttackerSpeed >= unmodifiedDefenderSpeed)
    {
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(battlerAtk, typeEffectivenessModifier, isCrit, abilityAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(move, moveType, battlerAtk, battlerDef, typeEffectivenessModifier, abilityDef));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(battlerAtk, typeEffectivenessModifier, holdEffectAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(damageCalcData, typeEffectivenessModifier, abilityDef, holdEffectDef));
    }
    else
    {
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(move, moveType, battlerAtk, battlerDef, typeEffectivenessModifier, abilityDef));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(battlerAtk, typeEffectivenessModifier, isCrit, abilityAtk));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(damageCalcData, typeEffectivenessModifier, abilityDef, holdEffectDef));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(battlerAtk, typeEffectivenessModifier, holdEffectAtk));
    }
    return finalModifier;
}

#undef DAMAGE_ACCUMULATE_MULTIPLIER

#define DAMAGE_APPLY_MODIFIER(modifier)              \
    do                                               \
    {                                                \
        dmg = uq4_12_multiply_by_int(modifier, dmg); \
    } while (0)

static inline s32 DoMoveDamageCalcVars(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier, u32 weather, u32 holdEffectAtk, u32 holdEffectDef, u32 abilityAtk, u32 abilityDef)
{
    s32 dmg;
    u32 userFinalAttack;
    u32 targetFinalDefense;
    u32 battlerAtk = damageCalcData->battlerAtk;
    u32 battlerDef = damageCalcData->battlerDef;

    if (gMovesInfo[gCurrentMove].effect == EFECTO_ATAQUE_EQUIPO)
        userFinalAttack = gCombate->estadisticaAtaqueEquipo;
    else
        userFinalAttack = CalcAttackStat(damageCalcData, abilityAtk, abilityDef, holdEffectAtk, weather);

    if (fixedBasePower)
        gBattleMovePower = fixedBasePower;
    else
        gBattleMovePower = CalcMoveBasePowerAfterModifiers(damageCalcData, abilityAtk, abilityDef, holdEffectAtk, weather);

    targetFinalDefense = CalcDefenseStat(damageCalcData, abilityAtk, abilityDef, holdEffectDef, weather);

    dmg = CalculateBaseDamage(gBattleMovePower, userFinalAttack, gBattleMons[battlerAtk].level, targetFinalDefense);

    DAMAGE_APPLY_MODIFIER(GetTargetDamageModifier(damageCalcData));
    DAMAGE_APPLY_MODIFIER(GetWeatherDamageModifier(damageCalcData, holdEffectAtk, holdEffectDef, weather));
    DAMAGE_APPLY_MODIFIER(GetCriticalModifier(damageCalcData->isCrit));
    DAMAGE_APPLY_MODIFIER(GetSameTypeAttackBonusModifier(damageCalcData, abilityAtk));
    DAMAGE_APPLY_MODIFIER(typeEffectivenessModifier);
    DAMAGE_APPLY_MODIFIER(ModificadorQuemaduraCongelacion(damageCalcData, abilityAtk));
    DAMAGE_APPLY_MODIFIER(GetOtherModifiers(damageCalcData, typeEffectivenessModifier, abilityAtk, abilityDef, holdEffectAtk, holdEffectDef));

    if (dmg <= 0)
        dmg = 1;

    return dmg;
}

static inline s32 DoMoveDamageCalc(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier, u32 weather)
{
    u32 holdEffectAtk, holdEffectDef, abilityAtk, abilityDef;

    if (typeEffectivenessModifier == MOVIMIENTO_NO_EFECTIVO)
        return 0;

    holdEffectAtk = GetBattlerHoldEffect(damageCalcData->battlerAtk, TRUE);
    holdEffectDef = GetBattlerHoldEffect(damageCalcData->battlerDef, TRUE);
    abilityAtk = HabilidadCombatiente(damageCalcData->battlerAtk);
    abilityDef = HabilidadCombatiente(damageCalcData->battlerDef);

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

    if (EsMovimientoFisico(move))
        userFinalAttack = GetMonData(partyMon, MON_DATA_ATK, NULL);
    else
        userFinalAttack = GetMonData(partyMon, MON_DATA_SPATK, NULL);

    targetFinalDefense = CalcDefenseStat(damageCalcData, ABILITY_NONE, abilityDef, holdEffectDef, weather);
    dmg = CalculateBaseDamage(gBattleMovePower, userFinalAttack, partyMonLevel, targetFinalDefense);

    DAMAGE_APPLY_MODIFIER(GetCriticalModifier(damageCalcData->isCrit));

    // STAB
    if (gSpeciesInfo[partyMonSpecies].types[TIPO_1] == moveType || gSpeciesInfo[partyMonSpecies].types[TIPO_2] == moveType)
        DAMAGE_APPLY_MODIFIER(MAS_50_POR_CIENTO);
    else
        DAMAGE_APPLY_MODIFIER(MOVIMIENTO_NEUTRO);
    DAMAGE_APPLY_MODIFIER(typeEffectivenessModifier);

    if (dmg == 0)
        dmg = 1;

    gSpecialStatuses[battlerAtk].preventLifeOrbDamage = TRUE;

    return dmg;
}

static inline s32 DoFutureSightAttackDamageCalc(struct DamageCalculationData *damageCalcData, uq4_12_t typeEffectivenessModifier, u32 weather)
{
    u32 holdEffectDef, abilityDef;

    if (typeEffectivenessModifier == MOVIMIENTO_NO_EFECTIVO)
        return 0;

    holdEffectDef = GetBattlerHoldEffect(damageCalcData->battlerDef, TRUE);
    abilityDef = HabilidadCombatiente(damageCalcData->battlerDef);

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
    return &party[gWishFutureKnock.futureSightPartyIndex[damageCalcData->battlerDef]] != &party[gBattlerPartyIndexes[damageCalcData->battlerAtk]];
}

s32 CalculateMoveDamage(struct DamageCalculationData *damageCalcData, u32 fixedBasePower)
{
    u32 typeEffectivenessMultiplier = CalcTypeEffectivenessMultiplier(damageCalcData->move,
                                                                      damageCalcData->moveType,
                                                                      damageCalcData->battlerAtk,
                                                                      damageCalcData->battlerDef,
                                                                      HabilidadCombatiente(damageCalcData->battlerDef),
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
    uq4_12_t mod = ModificadorTipo(moveType, defType);
    u32 abilityAtk = HabilidadCombatiente(battlerAtk);

    if (mod == MOVIMIENTO_NO_EFECTIVO && GetBattlerHoldEffect(battlerDef, TRUE) == HOLD_EFFECT_RING_TARGET)
    {
        mod = MOVIMIENTO_NEUTRO;
        if (recordAbilities)
            RecordItemEffectBattle(battlerDef, HOLD_EFFECT_RING_TARGET);
    }
    else if ((moveType == TIPO_LUCHA || moveType == TIPO_NORMAL) && defType == TIPO_FANTASMA && gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT && mod == MOVIMIENTO_NO_EFECTIVO)
    {
        mod = MOVIMIENTO_NEUTRO;
    }
    else if ((moveType == TIPO_LUCHA || moveType == TIPO_NORMAL) && defType == TIPO_FANTASMA && (abilityAtk == ABILITY_SCRAPPY) && mod == MOVIMIENTO_NO_EFECTIVO)
    {
        mod = MOVIMIENTO_NEUTRO;
        if (recordAbilities)
            RecuerdaHabilidad(battlerAtk, abilityAtk);
    }
    else if (defType == TIPO_BICHO && abilityAtk == ABILITY_MATAMOSCAS)
    {
        mod = MOVIMIENTO_SUPER_EFECTIVO;
        if (recordAbilities)
            RecuerdaHabilidad(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_VENENO && defType == TIPO_ACERO && abilityAtk == ABILITY_CORROSION && mod == MOVIMIENTO_NO_EFECTIVO)
    {
        mod = MOVIMIENTO_SUPER_EFECTIVO;
        if (recordAbilities)
            RecuerdaHabilidad(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_FUEGO && defType == TIPO_ROCA && abilityAtk == ABILITY_AVE_RAPAZ && mod == MOVIMIENTO_POCO_EFECTIVO)
    {
        mod = MOVIMIENTO_SUPER_EFECTIVO;
        if (recordAbilities)
            RecuerdaHabilidad(battlerAtk, abilityAtk);
    }
    else if (moveType == TIPO_VOLADOR && defType == TIPO_NORMAL && abilityAtk == ABILITY_AVE_RAPAZ && mod == MOVIMIENTO_NEUTRO)
    {
        mod = MOVIMIENTO_SUPER_EFECTIVO;
        if (recordAbilities)
            RecuerdaHabilidad(battlerAtk, abilityAtk);
    }
    if (gMovesInfo[move].effect == EFFECT_SUPER_EFFECTIVE_ON_ARG && defType == gMovesInfo[move].argument)
        mod = MOVIMIENTO_SUPER_EFECTIVO;
    if (moveType == TIPO_TIERRA && defType == TIPO_VOLADOR && EstaCombatienteEnSuelo(battlerDef) && mod == MOVIMIENTO_NO_EFECTIVO)
        mod = MOVIMIENTO_NEUTRO;

    *modifier = uq4_12_multiply(*modifier, mod);
}

static inline uq4_12_t CalcTypeEffectivenessMultiplierInternal(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, bool32 recordAbilities, uq4_12_t modifier, u32 defAbility)
{
    MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 0), battlerAtk, recordAbilities);
    if (GetBattlerType(battlerDef, 1) != GetBattlerType(battlerDef, 0))
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 1), battlerAtk, recordAbilities);
    if (GetBattlerType(battlerDef, 2) != TIPO_MISTERIO && GetBattlerType(battlerDef, 2) != GetBattlerType(battlerDef, 1) && GetBattlerType(battlerDef, 2) != GetBattlerType(battlerDef, 0))
        MulByTypeEffectiveness(&modifier, move, moveType, battlerDef, GetBattlerType(battlerDef, 2), battlerAtk, recordAbilities);

    if (moveType == TIPO_TIERRA && !EstaCombatienteEnSuelo(battlerDef))
    {
        modifier = MOVIMIENTO_NO_EFECTIVO;
        if (recordAbilities && defAbility == ABILITY_LEVITATE)
        {
            gLastUsedAbility = ABILITY_LEVITATE;
            gMoveResultFlags |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastLandedMoves[battlerDef] = MOVE_NONE;
            gMensajeBatalla = TEXTO_COMBATE_LEVITACION;
            RecuerdaHabilidad(battlerDef, ABILITY_LEVITATE);
        }
    }

    if ((defAbility == ABILITY_TELEPATA && battlerDef == ALIADO(battlerAtk)) && gMovesInfo[move].power)
    {
        modifier = MOVIMIENTO_NO_EFECTIVO;
        if (recordAbilities)
        {
            gLastUsedAbility = gBattleMons[battlerDef].ability;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gLastLandedMoves[battlerDef] = MOVE_NONE;
            gMensajeBatalla = TEXTO_COMBATE_TELEPATA;
            RecuerdaHabilidad(battlerDef, gBattleMons[battlerDef].ability);
        }
    }

    // Signal for the trainer slide-in system.
    if (GetBattlerSide(battlerDef) != LADO_JUGADOR && modifier && gCombate->trainerSlideFirstSTABMoveMsgState != 2)
        gCombate->trainerSlideFirstSTABMoveMsgState = 1;

    return modifier;
}

uq4_12_t CalcTypeEffectivenessMultiplier(u32 move, u32 moveType, u32 battlerAtk, u32 battlerDef, u32 defAbility, bool32 recordAbilities)
{
    uq4_12_t modificador = CalcTypeEffectivenessMultiplierInternal(move, moveType, battlerAtk, battlerDef, recordAbilities, modifier, defAbility);

    if (recordAbilities)
        gCombate->resultadoMovimiento = modificador;

    return modificador;
}

uq4_12_t CalcPartyMonTypeEffectivenessMultiplier(u16 move, u16 speciesDef, u16 abilityDef)
{
    uq4_12_t modificador = MOVIMIENTO_NEUTRO;
    u32 moveType = TipoMovimiento(move);

    MulByTypeEffectiveness(&modificador, move, moveType, 0, gSpeciesInfo[speciesDef].types[TIPO_1], 0, FALSE);
    if (gSpeciesInfo[speciesDef].types[TIPO_2] != gSpeciesInfo[speciesDef].types[TIPO_1])
        MulByTypeEffectiveness(&modificador, move, moveType, 0, gSpeciesInfo[speciesDef].types[TIPO_2], 0, FALSE);

    if (moveType == TIPO_TIERRA && abilityDef == ABILITY_LEVITATE && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
        modificador = MOVIMIENTO_NO_EFECTIVO;

    gCombate->resultadoMovimiento = modificador;

    return modificador;
}

uq4_12_t ModificadorTipo(u32 tipoAtacante, u32 tipoDefensor)
{
    return gTablaEfectividadTipos[tipoAtacante][tipoDefensor];
}

s32 DanioTrampa(u32 tipoTrampa, u32 combatiente)
{
    s32 danio = 0;
    uq4_12_t modificador = MOVIMIENTO_NEUTRO;
    u32 tipo1 = gBattleMons[combatiente].types[TIPO_1];
    u32 tipo2 = gBattleMons[combatiente].types[TIPO_2];
    u32 PSMaximos = gBattleMons[combatiente].maxHP;

    modificador = uq4_12_multiply(modificador, ModificadorTipo(tipoTrampa, tipo1));
    if (tipo2 != tipo1)
        modificador = uq4_12_multiply(modificador, ModificadorTipo(tipoTrampa, tipo2));

    switch (modificador)
    {
    case MOVIMIENTO_NO_EFECTIVO:
    case MOVIMIENTO_MUY_POCO_EFECTIVO:
    case MOVIMIENTO_POCO_EFECTIVO:
    case MOVIMIENTO_NEUTRO:
        danio = 0;
        break;
    case MOVIMIENTO_SUPER_EFECTIVO:
        danio = PSMaximos / 8;
        break;
    case MOVIMIENTO_ULTRA_EFECTIVO:
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
                    if (formChanges[i].param1 == HabilidadCombatiente(battler) || formChanges[i].param1 == ABILITY_NONE)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_BATTLE_HP_PERCENT:
                    if (formChanges[i].param1 == HabilidadCombatiente(battler))
                    {
                        // We multiply by 100 to make sure that integer division doesn't mess with the health check.
                        u32 hpCheck = gBattleMons[battler].hp * 100 * 100 / gBattleMons[battler].maxHP;
                        switch (formChanges[i].param2)
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
                    if (formChanges[i].param2 && HabilidadCombatiente(battler) != formChanges[i].param2 && formChanges[i].param1 == B_WEATHER_NONE)
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
                    else if (((gBattleWeather & formChanges[i].param1) && WEATHER_HAS_EFFECT) || (gBattleWeather == B_WEATHER_NONE && formChanges[i].param1 == B_WEATHER_NONE))
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
        if (gCombate->changedSpecies[side][monId] == SPECIES_NONE)
            gCombate->changedSpecies[side][monId] = gBattleMons[battler].species;

        TryToSetBattleFormChangeMoves(&party[monId], method);
        SetMonData(&party[monId], MON_DATA_SPECIES, &targetSpecies);
        gBattleMons[battler].species = targetSpecies;
        RecalcBattlerStats(battler, &party[monId]);
        return TRUE;
    }
    else if (gCombate->changedSpecies[side][monId] != SPECIES_NONE)
    {
        bool32 restoreSpecies = FALSE;

        if (restoreSpecies)
        {
            u32 abilityForm = gBattleMons[battler].ability;
            // Reverts the original species
            TryToSetBattleFormChangeMoves(&party[monId], method);
            SetMonData(&party[monId], MON_DATA_SPECIES, &gCombate->changedSpecies[side][monId]);
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

u32 CategoriaMovimiento(u32 movimiento)
{
    return gMovesInfo[movimiento].category;
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

// Sort an array of battlers by speed
// Useful for effects like pickpocket, eject button, red card
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

void RecuperaObjetoPerdido(void)
{
    for (u32 indicePokemon = 0; indicePokemon < PARTY_SIZE; indicePokemon++)
    {
        if (EsContraEntrenador())
        {
            u32 objetoPerdido = gCombate->objetoPerdido[LADO_JUGADOR][indicePokemon];

            // Check if the lost item is a berry and the mon is not holding it
            if (ItemId_GetPocket(objetoPerdido) == POCKET_BERRIES && GetMonData(&gPlayerParty[indicePokemon], MON_DATA_HELD_ITEM) != objetoPerdido)
                objetoPerdido = ITEM_NONE;

            // Check if the lost item should be restored
            if ((objetoPerdido != ITEM_NONE || EsContraEntrenador()) && ItemId_GetPocket(objetoPerdido) != POCKET_BERRIES)
                SetMonData(&gPlayerParty[indicePokemon], MON_DATA_HELD_ITEM, &objetoPerdido);
        }
    }
}

bool32 IsBattlerAffectedByHazards(u32 battler, bool32 toxicSpikes)
{
    bool32 ret = TRUE;
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    if (toxicSpikes && holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS && !EsTipo(battler, TIPO_VENENO))
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
    return HabilidadCombatiente(battler) == ABILITY_SHEER_FORCE && MoveIsAffectedBySheerForce(move);
}

// This function is the body of "jumpifstat", but can be used dynamically in a function
bool32 CompareStat(u32 battler, u8 statId, u8 cmpTo, u8 cmpKind)
{
    bool32 ret = FALSE;
    u8 statValue = gBattleMons[battler].statStages[statId];

    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (GetBattlerAbility(battler) == ABILITY_RESPONDON)
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
    bool32 hasContrary = (GetBattlerAbility(battler) == ABILITY_RESPONDON);

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
    if (!gProtectStructs[battlerPrankster].prioridadBromista)
        return FALSE;
    if (GetBattlerSide(battlerPrankster) == GetBattlerSide(battlerDef))
        return FALSE;
    if (checkTarget && (GetBattlerMoveTargetType(battlerPrankster, move) & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_DEPENDS)))
        return FALSE;
    if (!EsTipo(battlerDef, TIPO_SINIESTRO))
        return FALSE;
    if (gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;

    return TRUE;
}

u16 GetUsedHeldItem(u32 battler)
{
    return gCombate->usedHeldItems[gBattlerPartyIndexes[battler]][GetBattlerSide(battler)];
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
    if (move == MOVE_CURSE && !EsTipo(battler, TIPO_FANTASMA))
        return MOVE_TARGET_USER;

    return gMovesInfo[move].target;
}

static void SetRandomMultiHitCounter(void)
{
    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LOADED_DICE)
    {
        gCombate.contadorMultigolpes = MAXIMO_MULTIGOLPES;
    }
    else
    {
        gCombate.contadorMultigolpes = NumeroAleatorioEnRango(MINIMO_MULTIGOLPES, MAXIMO_MULTIGOLPES);
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
    gBattleMons[battler].types[TIPO_1] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_1];
    gBattleMons[battler].types[TIPO_2] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_2];
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

u32 CalculaProbabilidadEfectoSecundario(u32 habilidad, const struct AdditionalEffect *efectoSecundario)
{
    u32 probabilidad = efectoSecundario->chance;

    if (habilidad == ABILITY_SERENE_GRACE)
        probabilidad *= 2;
    if (gBattleWeather & B_WEATHER_HAIL && efectoSecundario->moveEffect == EFECTO_MOVIMIENTO_CONGELACION)
        probabilidad *= 2;
    if (gBattleWeather & B_WEATHER_RAIN && efectoSecundario->moveEffect == EFECTO_MOVIMIENTO_CONGELACION && habilidad == ABILITY_HUMEDAD_RELATIVA)
        probabilidad *= 2;
    if (gBattleWeather & B_WEATHER_SUN && efectoSecundario->moveEffect == MOVE_EFFECT_BURN)
        probabilidad *= 2;
    return probabilidad;
}

bool32 EfectoSecundarioGarantizado(u32 habilidad, const struct AdditionalEffect *efectoSecundario)
{
    return efectoSecundario->chance == 0 || CalculaProbabilidadEfectoSecundario(habilidad, efectoSecundario) >= 100;
}

bool32 EsAliado(u32 atacante, u32 defensor)
{
    return (GetBattlerSide(atacante) == GetBattlerSide(defensor));
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
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect && gMovesInfo[move].additionalEffects[i].self == FALSE)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectWithChance(u32 move, u32 moveEffect, u32 chance)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect && gMovesInfo[move].additionalEffects[i].chance == chance)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectSelf(u32 move, u32 moveEffect)
{
    u32 i;
    for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
    {
        if (gMovesInfo[move].additionalEffects[i].moveEffect == moveEffect && gMovesInfo[move].additionalEffects[i].self == TRUE)
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
    u16 types[NUMERO_TIPOS_POR_POKEMON] = {0};
    types[TIPO_1] = gBattleMons[battler].types[TIPO_1];
    types[TIPO_2] = gBattleMons[battler].types[TIPO_2];

    // Handle Roost's Flying-type suppression
    if (typeIndex == TIPO_1 || typeIndex == TIPO_2)
    {
        if (gBattleResources->flags[battler] & RESOURCE_FLAG_ROOST)
        {
            if (types[TIPO_1] == TIPO_VOLADOR && types[TIPO_2] == TIPO_VOLADOR)
            {
                return TIPO_NORMAL;
            }
            if (types[typeIndex] == TIPO_VOLADOR)
            {
                return (typeIndex == TIPO_1) ? types[TIPO_2] : types[TIPO_1];
            }
        }
    }

    return types[typeIndex];
}

void RemoveBattlerType(u32 battler, u8 type)
{
    u32 i;
    for (i = 0; i < 3; i++)
    {
        if (*(u8 *)(&gBattleMons[battler].types[TIPO_1] + i) == type)
            *(u8 *)(&gBattleMons[battler].types[TIPO_1] + i) = TIPO_MISTERIO;
    }
}

void AllocateBattleResources(void)
{
    gCombate = AllocZeroed(sizeof(*gCombate));
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
        FREE_AND_SET_NULL(gCombate);

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

bool32 CanTargetPartner(u32 battlerAtk, u32 battlerDef)
{
    return (EsContraEntrenador() && IsBattlerAlive(ALIADO(battlerDef)) && battlerDef != ALIADO(battlerAtk));
}

static inline bool32 DoesBattlerHaveAbilityImmunity(u32 battlerDef)
{
    return (AbilityBattleEffects(ABILITYEFFECT_WOULD_BLOCK, battlerDef, 0, 0, 0) || AbilityBattleEffects(ABILITYEFFECT_WOULD_ABSORB, battlerDef, 0, 0, 0));
}

bool32 TargetFullyImmuneToCurrMove(u32 battlerAtk, u32 battlerDef)
{
    return ((CalcTypeEffectivenessMultiplier(gCurrentMove, TipoMovimiento(gCurrentMove, battlerAtk), battlerAtk, battlerDef, HabilidadCombatiente(battlerDef), FALSE) == MOVIMIENTO_NO_EFECTIVO) || IsBattlerProtected(battlerAtk, battlerDef, gCurrentMove) || IsSemiInvulnerable(battlerDef, gCurrentMove) || DoesBattlerHaveAbilityImmunity(battlerDef));
}

u32 CuantosPSLeQuedan(u32 combatiente)
{
    return gBattleMons[combatiente].hp;
}

u32 CuantosPSMaximos(u32 combatiente)
{
    return gBattleMons[combatiente].maxHP;
}

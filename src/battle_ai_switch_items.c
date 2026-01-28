#include "global.h"
#include "battle.h"
#include "constants/battle_ai.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_main.h"
#include "constants/hold_effects.h"
#include "battle_setup.h"
#include "data.h"
#include "item.h"
#include "party_menu.h"
#include "pokemon.h"
#include "random.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/item_effects.h"
#include "constants/battle_move_effects.h"
#include "constants/items.h"
#include "constants/moves.h"

// this file's functions
static bool32 HasSuperEffectiveMoveAgainstOpponents(u32 battler, bool32 noRng);
static bool32 FindMonWithFlagsAndSuperEffective(u32 battler, u16 flags, u32 moduloPercent);
static bool32 AIExpectsToFaintPlayer(u32 battler);
static u32 GetSwitchinHazardsDamage(u32 battler, struct BattlePokemon *battleMon);
static bool32 CanAbilityTrapOpponent(u16 ability, u32 opponent);

static void InitializeSwitchinCandidate(struct Pokemon *mon)
{
    PokemonToBattleMon(mon, &AI_DATA->switchinCandidate.battleMon);
    AI_DATA->switchinCandidate.hypotheticalStatus = FALSE;
}

static bool32 IsAceMon(u32 battler, u32 monPartyId)
{
    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_ACE_POKEMON
            && !(gBattleStruct->forcedSwitch & (1u << battler))
            && monPartyId == CalculateEnemyPartyCount()-1)
        return TRUE;
    return FALSE;
}

void GetAIPartyIndexes(u32 battler, s32 *firstId, s32 *lastId)
{
    *firstId = 0, *lastId = PARTY_SIZE;
}

static inline bool32 SetSwitchinAndSwitch(u32 battler, u32 switchinId)
{
    gBattleStruct->AI_monToSwitchIntoId[battler] = switchinId;
    return TRUE;
}

// Note that as many return statements as possible are INTENTIONALLY put after all of the loops;
// the function can take a max of about 0.06s to run, and this prevents the player from identifying
// whether the mon will switch or not by seeing how long the delay is before they select a move
static bool32 ShouldSwitchIfHasBadOdds(u32 battler)
{
    //Variable initialization
    u8 opposingPosition, atkType1, atkType2, defType1, defType2, effectiveness;
    s32 i, damageDealt = 0, maxDamageDealt = 0, damageTaken = 0, maxDamageTaken = 0;
    u32 aiMove, playerMove, aiBestMove = MOVE_NONE, aiAbility = AI_DATA->abilities[battler], opposingBattler, weather = AI_GetWeather(AI_DATA);
    bool32 getsOneShot = FALSE, hasStatusMove = FALSE, hasSuperEffectiveMove = FALSE;
    u16 typeEffectiveness = UQ_4_12(1.0), aiMoveEffect; //baseline typing damage

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // Double Battles aren't included in AI_FLAG_SMART_MON_CHOICE. Defaults to regular switch in logic
    if (EsContraEntrenador())
        return FALSE;

    opposingPosition = OPONENTE(battler);
    opposingBattler = opposingPosition;

    // Gets types of player (opposingBattler) and computer (battler)
    atkType1 = gBattleMons[opposingBattler].types[0];
    atkType2 = gBattleMons[opposingBattler].types[1];
    defType1 = gBattleMons[battler].types[0];
    defType2 = gBattleMons[battler].types[1];

    // Check AI moves for damage dealt
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        aiMove = gBattleMons[battler].moves[i];
        aiMoveEffect = gMovesInfo[aiMove].effect;
        if (aiMove != MOVE_NONE)
        {
            // Check if mon has an "important" status move
            if (aiMoveEffect == EFFECT_REFLECT || aiMoveEffect == EFFECT_LIGHT_SCREEN
            || aiMoveEffect == EFFECT_SPIKES || aiMoveEffect == EFFECT_TOXIC_SPIKES || aiMoveEffect == EFFECT_STEALTH_ROCK || aiMoveEffect == EFFECT_STICKY_WEB || aiMoveEffect == EFFECT_LEECH_SEED
            || aiMoveEffect == EFFECT_EXPLOSION
            || aiMoveEffect == EFFECT_SLEEP || aiMoveEffect == EFFECT_YAWN || aiMoveEffect == EFFECT_TOXIC || aiMoveEffect == EFFECT_WILL_O_WISP || aiMoveEffect == EFFECT_PARALYZE
            || aiMoveEffect == EFFECT_TRICK || aiMoveEffect == EFFECT_TRICK_ROOM || aiMoveEffect== EFFECT_WONDER_ROOM || aiMoveEffect ==  EFFECT_PSYCHO_SHIFT || aiMoveEffect == EFFECT_FIRST_TURN_ONLY
            )
            {
                hasStatusMove = TRUE;
            }

            // Only check damage if move has power
            if (!ES_MOVIMIENTO_ESTADO(aiMove))
            {
                // Check if mon has a super effective move
                if (IA_EfectividadMovimiento(aiMove, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
                    hasSuperEffectiveMove = TRUE;

                // Get maximum damage mon can deal
                damageDealt = AI_DATA->simulatedDmg[battler][opposingBattler][i];
                if(damageDealt > maxDamageDealt)
                {
                    maxDamageDealt = damageDealt;
                    aiBestMove = aiMove;
                }

            }
        }
    }

    // Calculate type advantage
    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType1)));
    if (atkType2 != atkType1)
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType1)));
    if (defType2 != defType1)
    {
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType2)));
        if (atkType2 != atkType1)
            typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType2)));
    }

    // Get max damage mon could take
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        playerMove = gBattleMons[opposingBattler].moves[i];
        if (playerMove != MOVE_NONE && !ES_MOVIMIENTO_ESTADO(playerMove))
        {
            damageTaken = AI_CalcDamage(playerMove, opposingBattler, battler, &effectiveness, weather);
            if (damageTaken > maxDamageTaken)
                maxDamageTaken = damageTaken;
        }
    }

    // Check if mon gets one shot
    if(maxDamageTaken > gBattleMons[battler].hp)
    {
        getsOneShot = TRUE;
    }

    // Check if current mon can outspeed and KO in spite of bad matchup, and don't switch out if it can
    if(damageDealt > gBattleMons[opposingBattler].hp)
    {
        if (AI_IsFaster(battler, opposingBattler, aiBestMove))
            return FALSE;
    }

    // If we don't have any other viable options, don't switch out
    if (AI_DATA->mostSuitableMonId[battler] == PARTY_SIZE)
        return FALSE;

    // Start assessing whether or not mon has bad odds
    // Jump straight to switching out in cases where mon gets OHKO'd
    if (((getsOneShot && gBattleMons[opposingBattler].speed > gBattleMons[battler].speed) // If the player OHKOs and outspeeds OR OHKOs, doesn't outspeed but isn't 2HKO'd
            || (getsOneShot && gBattleMons[opposingBattler].speed <= gBattleMons[battler].speed && maxDamageDealt < gBattleMons[opposingBattler].hp / 2))
        && (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2 // And the current mon has at least 1/2 their HP, or 1/4 HP and Regenerator
            || (aiAbility == ABILITY_REGENERATOR
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 4)))
    {
        // 50% chance to stay in regardless
        if (PorcentajeAleatorio(50))
            return FALSE;

        // Switch mon out
        return SetSwitchinAndSwitch(battler, PARTY_SIZE);
    }

    // General bad type matchups have more wiggle room
    if (typeEffectiveness >= UQ_4_12(2.0)) // If the player has at least a 2x type advantage
    {
        if (!hasSuperEffectiveMove // If the AI doesn't have a super effective move
        && (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2 // And the current mon has at least 1/2 their HP, or 1/4 HP and Regenerator
            || (aiAbility == ABILITY_REGENERATOR
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 4)))
        {
            // Then check if they have an important status move, which is worth using even in a bad matchup
            if (hasStatusMove)
                return FALSE;

            // 50% chance to stay in regardless
            if (PorcentajeAleatorio(50))
                return FALSE;

            // Switch mon out
            return SetSwitchinAndSwitch(battler, PARTY_SIZE);
        }
    }
    return FALSE;
}

static bool32 ShouldSwitchIfAllMovesBad(u32 battler)
{
    for (u32 indiceMovimiento = 0; indiceMovimiento < MAX_MON_MOVES; indiceMovimiento++)
    {
        u32 opposingBattler = OPONENTE(battler);
        u32 opposingPartner = ALIADO(opposingBattler);
        u32 movimientoIA = gBattleMons[battler].moves[indiceMovimiento];
        if ((IA_EfectividadMovimiento(movimientoIA, battler, opposingBattler) > AI_EFFECTIVENESS_x0
                || IA_EfectividadMovimiento(movimientoIA, battler, opposingPartner) > AI_EFFECTIVENESS_x0)
                && movimientoIA != MOVE_NONE)
            return FALSE;
    }

    return SetSwitchinAndSwitch(battler, PARTY_SIZE);
}

static bool32 FindMonThatAbsorbsOpponentsMove(u32 battler)
{
    u8 battlerIn1, battlerIn2;
    u8 numAbsorbingAbilities = 0;
    u16 absorbingTypeAbilities[3]; // Array size is maximum number of absorbing abilities for a single type
    s32 firstId;
    s32 lastId;
    struct Pokemon *party;
    u16 monAbility;
    u32 opposingBattler = OPONENTE(battler);
    u32 incomingMove = AI_DATA->lastUsedMove[opposingBattler];
    u32 predictedMove = incomingMove; // Update for move prediction
    bool32 isOpposingBattlerChargingOrInvulnerable = (IsSemiInvulnerable(opposingBattler, incomingMove) || IsTwoTurnNotSemiInvulnerableMove(opposingBattler, incomingMove));
    s32 i, j;

    if (!(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;
    if (HasSuperEffectiveMoveAgainstOpponents(battler, TRUE) && PorcentajeAleatorio(66))
        return FALSE;

    if (EsContraEntrenador())
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & (1u << ALIADO(battler)))
            battlerIn2 = battler;
        else
            battlerIn2 = ALIADO(battler);
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    // Create an array of possible absorb abilities so the AI considers all of them
    if (gMovesInfo[predictedMove].type == TIPO_FUEGO)
    {
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_FLASH_FIRE;
    }
    else if (gMovesInfo[predictedMove].type == TIPO_AGUA || (isOpposingBattlerChargingOrInvulnerable && gMovesInfo[incomingMove].type == TIPO_AGUA))
    {
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_WATER_ABSORB;
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_DRY_SKIN;
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5)
            absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_STORM_DRAIN;
    }
    else if (gMovesInfo[predictedMove].type == TIPO_ELECTRICO || (isOpposingBattlerChargingOrInvulnerable && gMovesInfo[incomingMove].type == TIPO_ELECTRICO))
    {
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_VOLT_ABSORB;
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_MOTOR_DRIVE;
        if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5)
            absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_LIGHTNING_ROD;
    }
    else if (gMovesInfo[predictedMove].type == TIPO_PLANTA || (isOpposingBattlerChargingOrInvulnerable && gMovesInfo[incomingMove].type == TIPO_PLANTA))
    {
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_SAP_SIPPER;
    }
    else if (gMovesInfo[predictedMove].type == TIPO_TIERRA || (isOpposingBattlerChargingOrInvulnerable && gMovesInfo[incomingMove].type == TIPO_TIERRA))
    {
        absorbingTypeAbilities[numAbsorbingAbilities++] = ABILITY_EARTH_EATER;
    }
    else if (gMovesInfo[gLastLandedMoves[battler]].type == TIPO_TIERRA)
    {
        absorbingTypeAbilities[0] = ABILITY_BANO_BARRO;
        numAbsorbingAbilities = 1;
    }
    else
    {
        return FALSE;
    }

    // Check current mon for all absorbing abilities
    for (i = 0; i < numAbsorbingAbilities; i++)
    {
        if (gBattleMons[battler].ability == absorbingTypeAbilities[i])
            return FALSE;
    }

    // Check party for mon with ability that absorbs move
    GetAIPartyIndexes(battler, &firstId, &lastId);
    party = GetBattlerParty(battler);

    for (i = firstId; i < lastId; i++)
    {
        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn1])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn2])
            continue;
        if (IsAceMon(battler, i))
            continue;

        monAbility = GetMonAbility(&party[i]);

        for (j = 0; j < numAbsorbingAbilities; j++)
        {
            // Found a mon
            if (absorbingTypeAbilities[j] == monAbility)
                return SetSwitchinAndSwitch(battler, i);
        }
    }
    return FALSE;
}

static bool32 ShouldSwitchIfOpponentChargingOrInvulnerable(u32 battler)
{
    u32 opposingBattler = OPONENTE(battler);
    u32 incomingMove = AI_DATA->lastUsedMove[opposingBattler];
    bool32 isOpposingBattlerChargingOrInvulnerable = (IsSemiInvulnerable(opposingBattler, incomingMove) || IsTwoTurnNotSemiInvulnerableMove(opposingBattler, incomingMove));

    if (EsContraEntrenador() || !(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    if (isOpposingBattlerChargingOrInvulnerable && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE)
        return SetSwitchinAndSwitch(battler, PARTY_SIZE);

    return FALSE;
}

static bool32 ShouldSwitchIfTrapperInParty(u32 battler)
{
    s32 firstId;
    s32 lastId;
    struct Pokemon *party;
    s32 i;
    u16 monAbility;
    s32 opposingBattler =  OPONENTE(battler);

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // Check if current mon has an ability that traps opponent
    if (CanAbilityTrapOpponent(gBattleMons[battler].ability, opposingBattler))
        return FALSE;

    // Check party for mon with ability that traps opponent
    GetAIPartyIndexes(battler, &firstId, &lastId);
    party = GetBattlerParty(battler);

    for (i = firstId; i < lastId; i++)
    {
        if (IsAceMon(battler, i))
            return FALSE;

        monAbility = GetMonAbility(&party[i]);

        if (CanAbilityTrapOpponent(monAbility, opposingBattler))
        {
            // If mon in slot i is the most suitable switchin candidate, then it's a trapper than wins 1v1
            if (i == AI_DATA->mostSuitableMonId[battler])
                return SetSwitchinAndSwitch(battler, PARTY_SIZE);
        }
    }
    return FALSE;
}

static bool32 ShouldSwitchIfBadlyStatused(u32 battler)
{
    bool32 switchMon = FALSE;
    u16 monAbility = AI_DATA->abilities[battler];
    u16 holdEffect = AI_DATA->holdEffects[battler];
    u8 opposingPosition = OPONENTE(battler);
    u8 opposingBattler = opposingPosition;
    bool32 hasStatRaised = AnyStatIsRaised(battler);

    //Perish Song
    if (gStatuses3[battler] & STATUS3_PERISH_SONG
        && gDisableStructs[battler].perishSongTimer == 0
        && monAbility != ABILITY_SOUNDPROOF)
        switchMon = TRUE;

    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING)
    {
        //Yawn
        if (gStatuses3[battler] & STATUS3_YAWN
            && CanBeSlept(battler, monAbility)
            && gBattleMons[battler].hp > gBattleMons[battler].maxHP / 3)
        {
            switchMon = TRUE;

            // Check if Active Pokemon can KO opponent instead of switching
            // Will still fall asleep, but take out opposing Pokemon first
            if (AIExpectsToFaintPlayer(battler))
                switchMon = FALSE;

            // Checks to see if active Pokemon can do something against sleep
            if ((monAbility == ABILITY_NATURAL_CURE
                || monAbility == ABILITY_MUDAR
                || monAbility == ABILITY_EARLY_BIRD)
                || holdEffect == (HOLD_EFFECT_CURE_SLP | HOLD_EFFECT_CURE_STATUS)
                || HasMove(battler, MOVE_SLEEP_TALK)
                || (HasMoveEffect(battler, MOVE_SNORE) && IA_EfectividadMovimiento(MOVE_SNORE, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
                )
                switchMon = FALSE;

            // Check if Active Pokemon evasion boosted and might be able to dodge until awake
            if (gBattleMons[battler].statStages[ESTADISTICA_EVASION] > (ESTADISTICA_NEUTRA + 3)
                && AI_DATA->abilities[opposingBattler] != ABILITY_UNAWARE
                && AI_DATA->abilities[opposingBattler] != ABILITY_MINDS_EYE
                && !(gBattleMons[battler].status2 & STATUS2_FORESIGHT)
                && !(gStatuses3[battler] & STATUS3_MIRACLE_EYED))
                switchMon = FALSE;
        }

        // Secondary Damage
        if (monAbility != ABILITY_MAGIC_GUARD
            && !AIExpectsToFaintPlayer(battler))
        {
            //Toxic
            if (((gBattleMons[battler].status1 & STATUS1_TOXIC_COUNTER) >= STATUS1_TOXIC_TURN(2))
                && gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / 3)
                && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                && (hasStatRaised ? PorcentajeAleatorio(20) : PorcentajeAleatorio(50)))
                switchMon = TRUE;

            //Cursed
            if (gBattleMons[battler].status2 & STATUS2_CURSED
                && (hasStatRaised ? PorcentajeAleatorio(20) : PorcentajeAleatorio(50)))
                switchMon = TRUE;

            //Nightmare
            if (gBattleMons[battler].status2 & STATUS2_NIGHTMARE
                && (hasStatRaised ? PorcentajeAleatorio(15) : PorcentajeAleatorio(33)))
                switchMon = TRUE;

            //Leech Seed
            if (gStatuses3[battler] & STATUS3_LEECHSEED
                && (hasStatRaised ? PorcentajeAleatorio(10) : PorcentajeAleatorio(25)))
                switchMon = TRUE;
        }

        // Infatuation
        if (gBattleMons[battler].status2 & STATUS2_INFATUATION
            && !AIExpectsToFaintPlayer(battler))
            switchMon = TRUE;
    }

    if (switchMon)
        return SetSwitchinAndSwitch(battler, PARTY_SIZE);
    else
        return FALSE;
}

static bool32 ShouldSwitchIfAbilityBenefit(u32 battler)
{
    bool32 hasStatRaised = AnyStatIsRaised(battler);

    //Check if ability is blocked
    if (gStatuses3[battler] & STATUS3_GASTRO_ACID
        || IsNeutralizingGasOnField())
        return FALSE;

    switch(AI_DATA->abilities[battler])
    {
        case ABILITY_NATURAL_CURE:
            //Attempt to cure bad ailment
            if (gBattleMons[battler].status1 & (STATUS1_SLEEP | STATUS1_CONGELACION | STATUS1_TOXIC_POISON)
                && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                && (hasStatRaised ? PorcentajeAleatorio(10) : PorcentajeAleatorio(66)))
                break;
            //Attempt to cure lesser ailment
            if ((gBattleMons[battler].status1 & STATUS1_ANY)
                && (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2)
                && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                && (hasStatRaised ? PorcentajeAleatorio(10) : PorcentajeAleatorio(25)))
                break;

            return FALSE;

        case ABILITY_REGENERATOR:
            //Don't switch if ailment
            if (gBattleMons[battler].status1 & STATUS1_ANY)
                return FALSE;
            if ((gBattleMons[battler].hp <= ((gBattleMons[battler].maxHP * 2) / 3))
                 && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                 && (hasStatRaised ? PorcentajeAleatorio(20) : PorcentajeAleatorio(50)))
                break;

            return FALSE;

        default:
            return FALSE;
    }

    return SetSwitchinAndSwitch(battler, PARTY_SIZE);
}

static bool32 HasSuperEffectiveMoveAgainstOpponents(u32 battler, bool32 noRng)
{
    s32 i;
    u16 move;

    u32 opposingPosition = OPONENTE(battler);
    u32 opposingBattler = opposingPosition;

    if (!(gAbsentBattlerFlags & (1u << opposingBattler)))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[battler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (IA_EfectividadMovimiento(move, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    if (!EsContraEntrenador())
        return FALSE;

    opposingBattler = ALIADO(opposingPosition);

    if (!(gAbsentBattlerFlags & (1u << opposingBattler)))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[battler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (IA_EfectividadMovimiento(move, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static bool32 AreStatsRaised(u32 battler)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
    {
        if (gBattleMons[battler].statStages[i] > ESTADISTICA_NEUTRA)
            buffedStatsValue += gBattleMons[battler].statStages[i] - ESTADISTICA_NEUTRA;
    }

    return (buffedStatsValue > 3);
}

static bool32 FindMonWithFlagsAndSuperEffective(u32 battler, u16 flags, u32 percentChance)
{
    u32 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;

    // Similar functionality handled more thoroughly by ShouldSwitchIfHasBadOdds
    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING)
        return FALSE;

    if (gLastLandedMoves[battler] == MOVE_NONE)
        return FALSE;
    if (gLastHitBy[battler] == 0xFF)
        return FALSE;
    if (ES_MOVIMIENTO_ESTADO(gLastLandedMoves[battler]))
        return FALSE;

    if (EsContraEntrenador())
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & (1u << ALIADO(battler)))
            battlerIn2 = battler;
        else
            battlerIn2 = ALIADO(battler);
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);
    party = GetBattlerParty(battler);

    for (i = firstId; i < lastId; i++)
    {
        u16 species, monAbility;

        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn1])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn2])
            continue;
        if (IsAceMon(battler, i))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        monAbility = GetMonAbility(&party[i]);
        CalcPartyMonTypeEffectivenessMultiplier(gLastLandedMoves[battler], species, monAbility);
        if (gMoveResultFlags & flags)
        {
            battlerIn1 = gLastHitBy[battler];

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                if (IA_EfectividadMovimiento(move, battler, battlerIn1) >= AI_EFFECTIVENESS_x2 && PorcentajeAleatorio(percentChance))
                    return SetSwitchinAndSwitch(battler, i);
            }
        }
    }

    return FALSE;
}

static bool32 CanMonSurviveHazardSwitchin(u32 battler)
{
    u32 battlerIn1, battlerIn2;
    u32 hazardDamage = 0, battlerHp = gBattleMons[battler].hp;
    u32 ability = AI_DATA->abilities[battler], aiMove;
    s32 firstId, lastId, i, j;
    struct Pokemon *party;

    if (ability == ABILITY_REGENERATOR)
        battlerHp = (battlerHp * 133) / 100; // Account for Regenerator healing

    hazardDamage = GetSwitchinHazardsDamage(battler, &gBattleMons[battler]);

    // Battler will faint to hazards, check to see if another mon can clear them
    if (hazardDamage > battlerHp)
    {
        if (EsContraEntrenador())
        {
            battlerIn1 = battler;
            if (gAbsentBattlerFlags & (1u << ALIADO(battler)))
                battlerIn2 = battler;
            else
                battlerIn2 = ALIADO(battler);
        }
        else
        {
            battlerIn1 = battler;
            battlerIn2 = battler;
        }

        GetAIPartyIndexes(battler, &firstId, &lastId);
        party = GetBattlerParty(battler);

        for (i = firstId; i < lastId; i++)
        {
            if (!IsValidForBattle(&party[i]))
                continue;
            if (i == gBattlerPartyIndexes[battlerIn1])
                continue;
            if (i == gBattlerPartyIndexes[battlerIn2])
                continue;
            if (i == gBattleStruct->monToSwitchIntoId[battlerIn1])
                continue;
            if (i == gBattleStruct->monToSwitchIntoId[battlerIn2])
                continue;
            if (IsAceMon(battler, i))
                continue;

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                aiMove = GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL);
                if (MoveHasAdditionalEffectSelf(aiMove, MOVE_EFFECT_RAPID_SPIN)
                 || (gMovesInfo[aiMove].effect == EFFECT_DEFOG))
                {
                    // Have a mon that can clear the hazards, so switching out is okay
                    return TRUE;
                }
            }
        }
        // Faints to hazards and party can't clear them, don't switch out
        return FALSE;
    }
    return TRUE;
}

static bool32 ShouldSwitchIfEncored(u32 battler)
{
    u32 encoredMove = gDisableStructs[battler].encoredMove;
    u32 opposingBattler = OPONENTE(battler);

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // If not Encore'd don't switch
    if (encoredMove == MOVE_NONE)
        return FALSE;

    // Switch out if status move
    if (gMovesInfo[encoredMove].category == CATEGORIA_ESTADO)
        return SetSwitchinAndSwitch(battler, PARTY_SIZE);

    // Stay in if effective move
    else if (IA_EfectividadMovimiento(encoredMove, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
        return FALSE;

    // Switch out 50% of the time otherwise
    else if (PorcentajeAleatorio(50) && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE)
        return SetSwitchinAndSwitch(battler, PARTY_SIZE);

    return FALSE;
}

static bool32 ShouldSwitchIfBadChoiceLock(u32 battler)
{
    u32 holdEffect = GetBattlerHoldEffect(battler, FALSE);

    if (HOLD_EFFECT_CHOICE(holdEffect))
    {
        if (gMovesInfo[gLastUsedMove].category == CATEGORIA_ESTADO)
            return SetSwitchinAndSwitch(battler, PARTY_SIZE);
    }

    return FALSE;
}

// AI should switch if it's become setup fodder and has something better to switch to
static bool32 ShouldSwitchIfAttackingStatsLowered(u32 battler)
{
    s8 attackingStage = gBattleMons[battler].statStages[ESTADISTICA_ATAQUE];
    s8 spAttackingStage = gBattleMons[battler].statStages[ESTADISTICA_ATAQUE_ESPECIAL];

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // Physical attacker
    if (gBattleMons[battler].attack > gBattleMons[battler].spAttack)
    {
        // Don't switch if attack isn't below -1
        if (attackingStage > ESTADISTICA_NEUTRA - 2)
            return FALSE;
        // 50% chance if attack at -2 and have a good candidate mon
        else if (attackingStage == ESTADISTICA_NEUTRA - 2)
        {
            if (AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE && PorcentajeAleatorio(50))
                return SetSwitchinAndSwitch(battler, PARTY_SIZE);
        }
        // If at -3 or worse, switch out regardless
        else if (attackingStage < ESTADISTICA_NEUTRA - 2)
            return SetSwitchinAndSwitch(battler, PARTY_SIZE);
    }

    // Special attacker
    else
    {
        // Don't switch if attack isn't below -1
        if (spAttackingStage > ESTADISTICA_NEUTRA - 2)
            return FALSE;
        // 50% chance if attack at -2 and have a good candidate mon
        else if (spAttackingStage == ESTADISTICA_NEUTRA - 2)
        {
            if (AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE && PorcentajeAleatorio(50))
                return SetSwitchinAndSwitch(battler, PARTY_SIZE);
        }
        // If at -3 or worse, switch out regardless
        else if (spAttackingStage < ESTADISTICA_NEUTRA - 2)
            return SetSwitchinAndSwitch(battler, PARTY_SIZE);
    }
    return FALSE;
}

bool32 ShouldSwitch(u32 battler)
{
    u32 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;
    bool32 hasAceMon = FALSE;

    if (gBattleMons[battler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[battler] & STATUS3_ROOTED)
        return FALSE;
    if (HabilidadImpideCambiar(battler) == TRUE)
        return FALSE;

    // Sequence Switching AI never switches mid-battle
    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SEQUENCE_SWITCHING)
        return FALSE;

    availableToSwitch = 0;

    if (EsContraEntrenador())
    {
        u32 partner = ALIADO(battler);
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & (1u << partner))
            battlerIn2 = battler;
        else
            battlerIn2 = partner;
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);
    party = GetBattlerParty(battler);

    for (i = firstId; i < lastId; i++)
    {
        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn1])
            continue;
        if (i == gBattleStruct->monToSwitchIntoId[battlerIn2])
            continue;
        if (IsAceMon(battler, i))
        {
            hasAceMon = TRUE;
            continue;
        }

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
    {
        if (hasAceMon) // If the ace mon is the only available mon, use it
            availableToSwitch++;
        else
            return FALSE;
    }

    // NOTE: The sequence of the below functions matter! Do not change unless you have carefully considered the outcome.
    // Since the order is sequencial, and some of these functions prompt switch to specific party members.

    // These Functions can prompt switch to specific party members that override GetMostSuitableMonToSwitchInto
    if (FindMonThatAbsorbsOpponentsMove(battler))
        return TRUE;

    // These Functions can prompt switch to party member returned by GetMostSuitableMonToSwitchInto
    if ((AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING) && (CanMonSurviveHazardSwitchin(battler) == FALSE))
        return FALSE;
    if (ShouldSwitchIfTrapperInParty(battler))
        return TRUE;
    if (ShouldSwitchIfOpponentChargingOrInvulnerable(battler))
        return TRUE;
    if (ShouldSwitchIfAllMovesBad(battler))
        return TRUE;
    if (ShouldSwitchIfBadlyStatused(battler))
        return TRUE;
    if (ShouldSwitchIfAbilityBenefit(battler))
        return TRUE;
    if (ShouldSwitchIfHasBadOdds(battler))
        return TRUE;
    if (ShouldSwitchIfEncored(battler))
        return TRUE;
    if (ShouldSwitchIfBadChoiceLock(battler))
        return TRUE;
    if (ShouldSwitchIfAttackingStatsLowered(battler))
        return TRUE;

    // Removing switch capabilites under specific conditions
    // These Functions prevent the "FindMonWithFlagsAndSuperEffective" from getting out of hand.
    // We don't use FindMonWithFlagsAndSuperEffective with AI_FLAG_SMART_SWITCHING, so we can bail early.
    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_SWITCHING)
        return FALSE;
    if (HasSuperEffectiveMoveAgainstOpponents(battler, FALSE))
        return FALSE;
    if (AreStatsRaised(battler))
        return FALSE;

    // Default Function
    // Can prompt switch if AI has a pokemon in party that resists current opponent & has super effective move
    if (FindMonWithFlagsAndSuperEffective(battler, MOVE_RESULT_DOESNT_AFFECT_FOE, 50)
        || FindMonWithFlagsAndSuperEffective(battler, MOVE_RESULT_NOT_VERY_EFFECTIVE, 33))
        return TRUE;

    return FALSE;
}

bool32 IsSwitchinValid(u32 battler)
{
    // Edge case: See if partner already chose to switch into the same mon
    if (EsContraEntrenador())
    {
        u32 partner = ALIADO(battler);
        if (gBattleStruct->AI_monToSwitchIntoId[battler] == PARTY_SIZE) // Generic switch
        {
            if ((AI_DATA->shouldSwitch & (1u << partner)) && AI_DATA->monToSwitchInId[partner] == AI_DATA->mostSuitableMonId[battler])
            {
                return FALSE;
            }
        }
        else // Override switch
        {
            if ((AI_DATA->shouldSwitch & (1u << partner)) && AI_DATA->monToSwitchInId[partner] == gBattleStruct->AI_monToSwitchIntoId[battler])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void AI_TrySwitchOrUseItem(u32 battler)
{
    struct Pokemon *party;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    u8 battlerPosition = battler;
    party = GetBattlerParty(battler);

    if (EsContraEntrenador())
    {
        if (AI_DATA->shouldSwitch & (1u << battler) && IsSwitchinValid(battler))
        {
            BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
            if (gBattleStruct->AI_monToSwitchIntoId[battler] == PARTY_SIZE)
            {
                s32 monToSwitchId = AI_DATA->mostSuitableMonId[battler];
                if (monToSwitchId == PARTY_SIZE)
                {
                    if (!EsContraEntrenador())
                    {
                        battlerIn1 = battlerPosition;
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = battlerPosition;
                        battlerIn2 = ALIADO(battlerPosition);
                    }

                    GetAIPartyIndexes(battler, &firstId, &lastId);

                    for (monToSwitchId = (lastId-1); monToSwitchId >= firstId; monToSwitchId--)
                    {
                        if (!IsValidForBattle(&party[monToSwitchId]))
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn2])
                            continue;
                        if (monToSwitchId == gBattleStruct->monToSwitchIntoId[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattleStruct->monToSwitchIntoId[battlerIn2])
                            continue;
                        if (IsAceMon(battler, monToSwitchId))
                            continue;

                        break;
                    }
                }

                gBattleStruct->AI_monToSwitchIntoId[battler] = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + battler) = gBattleStruct->AI_monToSwitchIntoId[battler];
            AI_DATA->monToSwitchInId[battler] = gBattleStruct->AI_monToSwitchIntoId[battler];
            return;
        }
    }

    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_USE_MOVE, OPONENTE(battler) << 8);
}

// If there are two(or more) mons to choose from, always choose one that has baton pass
// as most often it can't do much on its own.
static u32 GetBestMonRelevo(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, int aliveCount, u32 battler, u32 opposingBattler)
{
    u32 combatiente, bits = 0;

    for (combatiente = firstId; combatiente < lastId; combatiente++)
    {
        if (invalidMons & (1u << combatiente))
            continue;

        for (u32 indiceMovimiento = 0; indiceMovimiento < MAX_MON_MOVES; indiceMovimiento++)
        {
            if (gMovesInfo[GetMonData(&party[combatiente], MON_DATA_MOVE1 + indiceMovimiento)].effect == EFECTO_RELEVO)
            {
                bits |= 1u << combatiente;
                break;
            }
        }
    }

    if ((aliveCount == 2 || (aliveCount > 2 && Random() % 3 == 0)) && bits)
    {
        do
        {
            combatiente = (Random() % (lastId - firstId)) + firstId;
        } while (!(bits & (1 << combatiente)));
        return combatiente;
    }

    return PARTY_SIZE;
}

static u32 GetBestMonTypeMatchup(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 battler, u32 opposingBattler)
{
    u32 i, bits = 0;

    while (bits != 0x3F) // All mons were checked.
    {
        uq4_12_t bestResist = UQ_4_12(1.0);
        int bestMonId = PARTY_SIZE;
        // Find the mon whose type is the most suitable defensively.
        for (i = firstId; i < lastId; i++)
        {
            if (!((1u << i) & invalidMons) && !((1u << i) & bits))
            {
                u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                uq4_12_t typeEffectiveness = UQ_4_12(1.0);

                u8 atkType1 = gBattleMons[opposingBattler].types[0];
                u8 atkType2 = gBattleMons[opposingBattler].types[1];
                u8 defType1 = gSpeciesInfo[species].types[0];
                u8 defType2 = gSpeciesInfo[species].types[1];

                typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType1)));
                if (atkType2 != atkType1)
                    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType1)));
                if (defType2 != defType1)
                {
                    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType2)));
                    if (atkType2 != atkType1)
                        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType2)));
                }
                if (typeEffectiveness < bestResist)
                {
                    bestResist = typeEffectiveness;
                    bestMonId = i;
                }
            }
        }

        // Ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != PARTY_SIZE)
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                u32 move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
                if (move != MOVE_NONE && IA_EfectividadMovimiento(move, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
                    break;
            }

            if (i != MAX_MON_MOVES)
                return bestMonId; // Has both the typing and at least one super effective move.

            bits |= (1u << bestMonId); // Sorry buddy, we want something better.
        }
        else
        {
            bits = 0x3F; // No viable mon to switch.
        }
    }

    return PARTY_SIZE;
}

static u32 GetBestMonDmg(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 battler, u32 opposingBattler)
{
    u32 i, j;
    int dmg, bestDmg = 0;
    int bestMonId = PARTY_SIZE;

    u32 aiMove;

    gMoveResultFlags = 0;
    // If we couldn't find the best mon in terms of typing, find the one that deals most damage.
    for (i = firstId; i < lastId; i++)
    {
        if ((1 << (i)) & invalidMons)
            continue;
        InitializeSwitchinCandidate(&party[i]);
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            aiMove = AI_DATA->switchinCandidate.battleMon.moves[j];
            if (aiMove != MOVE_NONE && !ES_MOVIMIENTO_ESTADO(aiMove))
            {
                aiMove = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                dmg = AI_CalcPartyMonDamage(aiMove, battler, opposingBattler, AI_DATA->switchinCandidate.battleMon, TRUE);
                if (bestDmg < dmg)
                {
                    bestDmg = dmg;
                    bestMonId = i;
                }
            }
        }
    }

    return bestMonId;
}

bool32 EstaPokemonEnSuelo(u32 efectoObjeto, u32 habilidad, u32 tipo1, u32 tipo2)
{
    // List that makes mon not grounded
    if (tipo1 == TIPO_VOLADOR || tipo2 == TIPO_VOLADOR || habilidad == ABILITY_LEVITATE || (efectoObjeto == HOLD_EFFECT_AIR_BALLOON))
             {
        // List that overrides being off the ground
        if ((efectoObjeto == HOLD_EFFECT_IRON_BALL) || (gFieldStatuses & STATUS_FIELD_GRAVITY) || (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM))
            return TRUE;
        else
            return FALSE;
    }
    else
        return TRUE;
}

// Gets hazard damage
static u32 GetSwitchinHazardsDamage(u32 battler, struct BattlePokemon *battleMon)
{
    u8 defType1 = battleMon->types[0], defType2 = battleMon->types[1], tSpikesLayers;
    u16 heldItemEffect = ItemId_GetHoldEffect(battleMon->item);
    u32 maxHP = battleMon->maxHP, ability = battleMon->ability, status = battleMon->status1;
    u32 spikesDamage = 0, tSpikesDamage = 0, hazardDamage = 0;
    u32 hazardFlags = gSideStatuses[GetBattlerSide(battler)] & (SIDE_STATUS_SPIKES | SIDE_STATUS_STEALTH_ROCK | SIDE_STATUS_STICKY_WEB | SIDE_STATUS_TOXIC_SPIKES | SIDE_STATUS_SAFEGUARD);

    // Check ways mon might avoid all hazards
    if (ability != ABILITY_MAGIC_GUARD || (heldItemEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS &&
        !((gFieldStatuses & STATUS_FIELD_MAGIC_ROOM))))
    {
        // Stealth Rock
        if ((hazardFlags & SIDE_STATUS_STEALTH_ROCK) && heldItemEffect != HOLD_EFFECT_HEAVY_DUTY_BOOTS)
            hazardDamage += DanioTrampa(gMovesInfo[MOVE_STEALTH_ROCK].type, battler);
        // Spikes
        if ((hazardFlags & SIDE_STATUS_SPIKES) && EstaPokemonEnSuelo(heldItemEffect, ability, defType1, defType2))
        {
            spikesDamage = maxHP / ((5 - gSideTimers[GetBattlerSide(battler)].spikesAmount) * 2);
            if (spikesDamage == 0)
                spikesDamage = 1;
            hazardDamage += spikesDamage;
        }

        if ((hazardFlags & SIDE_STATUS_TOXIC_SPIKES) && (defType1 != TIPO_VENENO && defType2 != TIPO_VENENO
            && ability != ABILITY_IMMUNITY && ability != ABILITY_POISON_HEAL
            && status == 0
            && !(hazardFlags & SIDE_STATUS_SAFEGUARD))
            && !(IsAbilityStatusProtected(battler))
            && heldItemEffect != HOLD_EFFECT_CURE_PSN && heldItemEffect != HOLD_EFFECT_CURE_STATUS
            && EstaPokemonEnSuelo(heldItemEffect, ability, defType1, defType2))
        {
            tSpikesLayers = gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount;
            if (tSpikesLayers == 1)
            {
                tSpikesDamage = maxHP / 8;
                if (tSpikesDamage == 0)
                    tSpikesDamage = 1;
            }
            else if (tSpikesLayers >= 2)
            {
                tSpikesDamage = maxHP / 16;
                if (tSpikesDamage == 0)
                    tSpikesDamage = 1;
            }
            hazardDamage += tSpikesDamage;
        }
    }
    return hazardDamage;
}

// Gets damage / healing from weather
static s32 GetSwitchinWeatherImpact(void)
{
    s32 weatherImpact = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u32 holdEffect = ItemId_GetHoldEffect(AI_DATA->switchinCandidate.battleMon.item);

    if (WEATHER_HAS_EFFECT)
    {
        // Damage
        if (holdEffect != HOLD_EFFECT_SAFETY_GOGGLES && ability != ABILITY_MAGIC_GUARD && ability != ABILITY_OVERCOAT)
        {
            if ((gBattleWeather & B_WEATHER_HAIL)
             && (AI_DATA->switchinCandidate.battleMon.types[0] != TIPO_HIELO || AI_DATA->switchinCandidate.battleMon.types[1] != TIPO_HIELO)
             && ability != ABILITY_SNOW_CLOAK && ability != ABILITY_ICE_BODY)
            {
                weatherImpact = maxHP / 16;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
            else if ((gBattleWeather & B_WEATHER_SANDSTORM)
                && (AI_DATA->switchinCandidate.battleMon.types[0] != TIPO_TIERRA && AI_DATA->switchinCandidate.battleMon.types[1] != TIPO_TIERRA
                && AI_DATA->switchinCandidate.battleMon.types[0] != TIPO_ROCA && AI_DATA->switchinCandidate.battleMon.types[1] != TIPO_ROCA
                && ability != ABILITY_SAND_VEIL && ability != ABILITY_SAND_RUSH && ability != ABILITY_SAND_FORCE))
            {
                weatherImpact = maxHP / 16;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
        }
        if ((gBattleWeather & B_WEATHER_SUN) && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA
         && (ability == ABILITY_DRY_SKIN))
        {
            weatherImpact = maxHP / 8;
            if (weatherImpact == 0)
                weatherImpact = 1;
        }

        // Healing
        if (gBattleWeather & B_WEATHER_RAIN && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
        {
            if (ability == ABILITY_DRY_SKIN)
            {
                weatherImpact = -(maxHP / 8);
                if (weatherImpact == 0)
                    weatherImpact = -1;
            }
            else if (ability == ABILITY_RAIN_DISH)
            {
                weatherImpact = -(maxHP / 8);
                if (weatherImpact == 0)
                    weatherImpact = -1;
            }
        }
        if (((gBattleWeather & B_WEATHER_HAIL) || (gBattleWeather & B_WEATHER_SNOW)) && ability == ABILITY_ICE_BODY)
        {
            weatherImpact = -(maxHP / 8);
            if (weatherImpact == 0)
                weatherImpact = -1;
        }
        if ((gBattleWeather & B_WEATHER_SUN) && ability == ABILITY_FOTOSINTESIS)
        {
            weatherImpact = -(maxHP / 8);
            if (weatherImpact == 0)
                weatherImpact = -1;
        }
    }
    return weatherImpact;
}

// Gets one turn of recurring healing
static u32 GetSwitchinRecurringHealing(void)
{
    u32 recurringHealing = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u32 holdEffect = ItemId_GetHoldEffect(AI_DATA->switchinCandidate.battleMon.item);

    // Items

    if (holdEffect == HOLD_EFFECT_BLACK_SLUDGE && (AI_DATA->switchinCandidate.battleMon.types[0] == TIPO_VENENO || AI_DATA->switchinCandidate.battleMon.types[1] == TIPO_VENENO))
    {
        recurringHealing = maxHP / 16;
        if (recurringHealing == 0)
            recurringHealing = 1;
    }
    else if (holdEffect == HOLD_EFFECT_LEFTOVERS)
    {
        recurringHealing = maxHP / 16;
        if (recurringHealing == 0)
            recurringHealing = 1;
    } // Intentionally omitting Shell Bell for its inconsistency

    // Abilities
    if (ability == ABILITY_POISON_HEAL && (AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_POISON))
    {
        u32 healing = maxHP / 8;
        if (healing == 0)
            healing = 1;
        recurringHealing += healing;
    }
    return recurringHealing;
}

// Gets one turn of recurring damage
static u32 GetSwitchinRecurringDamage(void)
{
    u32 passiveDamage = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u32 holdEffect = ItemId_GetHoldEffect(AI_DATA->switchinCandidate.battleMon.item);

    // Items
    if (ability != ABILITY_MAGIC_GUARD)
    {
        if (holdEffect == HOLD_EFFECT_BLACK_SLUDGE && AI_DATA->switchinCandidate.battleMon.types[0] != TIPO_VENENO && AI_DATA->switchinCandidate.battleMon.types[1] != TIPO_VENENO)
        {
            passiveDamage = maxHP / 16;
            if (passiveDamage == 0)
                passiveDamage = 1;
        }
        else if (holdEffect == HOLD_EFFECT_LIFE_ORB && ability != ABILITY_SHEER_FORCE)
        {
            passiveDamage = maxHP / 16;
            if (passiveDamage == 0)
                passiveDamage = 1;
        }
        else if (holdEffect == HOLD_EFFECT_STICKY_BARB)
        {
            passiveDamage = maxHP / 8;
            if(passiveDamage == 0)
                passiveDamage = 1;
        }
    }
    return passiveDamage;
}

// Gets one turn of status damage
static u32 GetSwitchinStatusDamage(u32 battler)
{
    u32 defType1 = AI_DATA->switchinCandidate.battleMon.types[0], defType2 = AI_DATA->switchinCandidate.battleMon.types[1];
    u8 tSpikesLayers = gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount;
    u16 heldItemEffect = ItemId_GetHoldEffect(AI_DATA->switchinCandidate.battleMon.item);
    u32 status = AI_DATA->switchinCandidate.battleMon.status1, ability = AI_DATA->switchinCandidate.battleMon.ability, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP;
    u32 statusDamage = 0;

    // Status condition damage
    if ((status != 0) && AI_DATA->switchinCandidate.battleMon.ability != ABILITY_MAGIC_GUARD)
    {
        if (status & STATUS1_BURN)
        {
            statusDamage = maxHP / 16;
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if (status & STATUS1_CONGELACION)
        {
            statusDamage = maxHP / 16;
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if ((status & STATUS1_POISON) && ability != ABILITY_POISON_HEAL)
        {
            statusDamage = maxHP / 8;
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if ((status & STATUS1_TOXIC_POISON) && ability != ABILITY_POISON_HEAL)
        {
            if ((status & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                AI_DATA->switchinCandidate.battleMon.status1 += STATUS1_TOXIC_TURN(1);
            statusDamage = maxHP / 16;
            if (statusDamage == 0)
                statusDamage = 1;
            statusDamage *= AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_TOXIC_COUNTER >> 8;
        }
    }

    // Apply hypothetical poisoning from Toxic Spikes, which means the first turn of damage already added in GetSwitchinHazardsDamage
    // Do this last to skip one iteration of Poison / Toxic damage, and start counting Toxic damage one turn later.
    if (tSpikesLayers != 0 && (defType1 != TIPO_VENENO && defType2 != TIPO_VENENO
        && ability != ABILITY_IMMUNITY && ability != ABILITY_POISON_HEAL
        && status == 0
        && !(heldItemEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS
            && (((gFieldStatuses & STATUS_FIELD_MAGIC_ROOM))))
        && heldItemEffect != HOLD_EFFECT_CURE_PSN && heldItemEffect != HOLD_EFFECT_CURE_STATUS
        && EstaPokemonEnSuelo(heldItemEffect, ability, defType1, defType2)))
    {
        if (tSpikesLayers == 1)
        {
            AI_DATA->switchinCandidate.battleMon.status1 = STATUS1_POISON; // Assign "hypothetical" status to the switchin candidate so we can get the damage it would take from TSpikes
            AI_DATA->switchinCandidate.hypotheticalStatus = TRUE;
        }
        if (tSpikesLayers == 2)
        {
            AI_DATA->switchinCandidate.battleMon.status1 = STATUS1_TOXIC_POISON; // Assign "hypothetical" status to the switchin candidate so we can get the damage it would take from TSpikes
            AI_DATA->switchinCandidate.battleMon.status1 += STATUS1_TOXIC_TURN(1);
            AI_DATA->switchinCandidate.hypotheticalStatus = TRUE;
        }
    }
    return statusDamage;
}

// Gets number of hits to KO factoring in hazards, healing held items, status, and weather
static u32 GetSwitchinHitsToKO(s32 damageTaken, u32 battler)
{
    u32 startingHP = AI_DATA->switchinCandidate.battleMon.hp - GetSwitchinHazardsDamage(battler, &AI_DATA->switchinCandidate.battleMon);
    s32 weatherImpact = GetSwitchinWeatherImpact(); // Signed to handle both damage and healing in the same value
    u32 recurringDamage = GetSwitchinRecurringDamage();
    u32 recurringHealing = GetSwitchinRecurringHealing();
    u32 statusDamage = GetSwitchinStatusDamage(battler);
    u32 hitsToKO = 0, singleUseItemHeal = 0;
    u16 maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, item = AI_DATA->switchinCandidate.battleMon.item, heldItemEffect = ItemId_GetHoldEffect(item);
    u8 weatherDuration = gWishFutureKnock.weatherDuration, holdEffectParam = ItemId_GetHoldEffectParam(item);
    u32 opposingBattler = OPONENTE(battler);
    u32 opposingAbility = gBattleMons[opposingBattler].ability, ability = AI_DATA->switchinCandidate.battleMon.ability;
    bool32 usedSingleUseHealingItem = FALSE, opponentCanBreakMold = IsMoldBreakerTypeAbility(opposingBattler, opposingAbility);
    s32 currentHP = startingHP;

    // No damage being dealt
    if ((damageTaken + statusDamage + recurringDamage <= recurringHealing) || damageTaken + statusDamage + recurringDamage == 0)
        return startingHP;

    // Mon fainted to hazards
    if (startingHP == 0)
        return 1;

    // Find hits to KO
    while (currentHP > 0)
    {
        // Remove weather damage when it would run out
        if (weatherImpact != 0 && weatherDuration == 0)
            weatherImpact = 0;

        // Take attack damage for the turn
        currentHP = currentHP - damageTaken;

        // One shot prevention effects
        if (damageTaken >= maxHP && currentHP == maxHP && (heldItemEffect == HOLD_EFFECT_FOCUS_SASH || (!opponentCanBreakMold && B_STURDY >= GEN_5 && ability == ABILITY_STURDY)))
            currentHP = 1;

        // If mon is still alive, apply weather impact first, as it might KO the mon before it can heal with its item (order is weather -> item -> status)
        if (currentHP != 0)
            currentHP = currentHP - weatherImpact;

        // Check if we're at a single use healing item threshold
        if (usedSingleUseHealingItem == FALSE
         && !(opposingAbility == ABILITY_UNNERVE && GetPocketByItemId(item) == POCKET_BERRIES))
        {
            switch (heldItemEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (currentHP < maxHP / 2)
                    singleUseItemHeal = holdEffectParam;
                break;
            case HOLD_EFFECT_RESTORE_PCT_HP:
                if (currentHP < maxHP / 2)
                {
                    singleUseItemHeal = maxHP / holdEffectParam;
                    if (singleUseItemHeal == 0)
                        singleUseItemHeal = 1;
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
            case HOLD_EFFECT_CONFUSE_DRY:
            case HOLD_EFFECT_CONFUSE_SWEET:
            case HOLD_EFFECT_CONFUSE_BITTER:
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (currentHP < maxHP / CONFUSE_BERRY_HP_FRACTION)
                {
                    singleUseItemHeal = maxHP / holdEffectParam;
                    if (singleUseItemHeal == 0)
                        singleUseItemHeal = 1;
                }
                break;
            }

            // If we used one, apply it without overcapping our maxHP
            if (singleUseItemHeal > 0)
            {
                if ((currentHP + singleUseItemHeal) > maxHP)
                    currentHP = maxHP;
                else
                    currentHP = currentHP + singleUseItemHeal;
                usedSingleUseHealingItem = TRUE;
            }
        }

        // Healing from items occurs before status so we can do the rest in one line
        if (currentHP >= 0)
            currentHP = currentHP + recurringHealing - recurringDamage - statusDamage;

        // Recalculate toxic damage if needed
        if (AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_TOXIC_POISON)
            statusDamage = GetSwitchinStatusDamage(battler);

        // Reduce weather duration
        if (weatherDuration != 0)
            weatherDuration--;

        hitsToKO++;
    }

    // If mon had a hypothetical status from TSpikes, clear it
    if (AI_DATA->switchinCandidate.hypotheticalStatus == TRUE)
    {
        AI_DATA->switchinCandidate.battleMon.status1 = 0;
        AI_DATA->switchinCandidate.hypotheticalStatus = FALSE;
    }
    return hitsToKO;
}

static u16 GetSwitchinTypeMatchup(u32 opposingBattler, struct BattlePokemon battleMon)
{

    // Check type matchup
    u16 typeEffectiveness = UQ_4_12(1.0);
    u8 atkType1 = gSpeciesInfo[gBattleMons[opposingBattler].species].types[0], atkType2 = gSpeciesInfo[gBattleMons[opposingBattler].species].types[1],
    defType1 = battleMon.types[0], defType2 = battleMon.types[1];

    // Multiply type effectiveness by a factor depending on type matchup
    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType1)));
    if (atkType2 != atkType1)
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType1)));
    if (defType2 != defType1)
    {
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType1, defType2)));
        if (atkType2 != atkType1)
            typeEffectiveness = uq4_12_multiply(typeEffectiveness, (ModificadorTipo(atkType2, defType2)));
    }
    return typeEffectiveness;
}

static int GetRandomSwitchinWithRelevo(int aliveCount, int bits, int firstId, int lastId, int currentMonId)
{
    // Breakout early if there aren't any Baton Pass mons to save computation time
    if (bits == 0)
        return PARTY_SIZE;

    // GetBestMonRelevo randomly chooses between all mons that met Baton Pass check
    if ((aliveCount == 2 || (aliveCount > 2 && Random() % 3 == 0)) && bits)
    {
        do
        {
            return (Random() % (lastId - firstId)) + firstId;
        } while (!(bits & (1 << (currentMonId))));
    }

    // Catch any other cases (such as only one mon alive and it has Baton Pass)
    else
        return PARTY_SIZE;
}

static s32 GetMaxDamagePlayerCouldDealToSwitchin(u32 battler, u32 opposingBattler, struct BattlePokemon battleMon)
{
    u32 i = 0;
    u32 playerMove;
    s32 damageTaken = 0, maxDamageTaken = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        playerMove = gBattleMons[opposingBattler].moves[i];
        if (playerMove != MOVE_NONE && !ES_MOVIMIENTO_ESTADO(playerMove))
        {
            damageTaken = AI_CalcPartyMonDamage(playerMove, opposingBattler, battler, battleMon, FALSE);
            if (damageTaken > maxDamageTaken)
                maxDamageTaken = damageTaken;
        }
    }
    return maxDamageTaken;
}

static bool32 CanAbilityTrapOpponent(u16 ability, u32 opponent)
{
    if ((B_GHOSTS_ESCAPE >= GEN_6 && ES_TIPO(opponent, TIPO_FANTASMA)))
        return FALSE;
    else if (ability == ABILITY_SHADOW_TAG)
    {
        return TRUE;
    }
    else if (ability == ABILITY_ARENA_TRAP && IsBattlerGrounded(opponent))
        return TRUE;
    else if (ability == ABILITY_IMAN && ES_TIPO(opponent, TIPO_ACERO))
        return TRUE;
    else if (ability == ABILITY_MATAMOSCAS && ES_TIPO(opponent, TIPO_BICHO))
        return TRUE;
    else
        return FALSE;
}

static inline bool32 IsFreeSwitch(bool32 isSwitchAfterKO, u32 battlerSwitchingOut, u32 opposingBattler)
{
    bool32 movedSecond = GetBattlerTurnOrderNum(battlerSwitchingOut) > GetBattlerTurnOrderNum(opposingBattler) ? TRUE : FALSE;

    // Switch out effects
    if (!EsContraEntrenador()) // Not handling doubles' additional complexity
    {
        if (IsSwitchOutEffect(gMovesInfo[gLastUsedMove].effect) && movedSecond)
            return TRUE;
        if (AI_DATA->ejectButtonSwitch)
            return TRUE;
        if (AI_DATA->ejectPackSwitch)
        {
            // If faster, not a free switch; likely lowered own stats
            if (!movedSecond)
                return FALSE;
            // Otherwise, free switch
            return TRUE;
        }
    }

    // Post KO check has to be last because the GetMostSuitableMonToSwitchInto call in OpponentHandleChoosePokemon assumes a KO rather than a forced switch choice
    if (isSwitchAfterKO)
        return TRUE;
    else
        return FALSE;
}

static inline bool32 CanSwitchinWin1v1(u32 hitsToKOAI, u32 hitsToKOPlayer, bool32 isSwitchinFirst, bool32 isFreeSwitch)
{
    // Free switch, need to outspeed or take 1 extra hit
    if (isFreeSwitch)
    {
        if (hitsToKOAI > hitsToKOPlayer || (hitsToKOAI == hitsToKOPlayer && isSwitchinFirst))
            return TRUE;
    }
    // Mid battle switch, need to take 1 or 2 extra hits depending on speed
    if (hitsToKOAI > hitsToKOPlayer + 1 || (hitsToKOAI == hitsToKOPlayer + 1 && isSwitchinFirst))
        return TRUE;
    return FALSE;
}

// This function splits switching behaviour depending on whether the switch is free.
// Everything runs in the same loop to minimize computation time. This makes it harder to read, but hopefully the comments can guide you!
static u32 GetBestMonIntegrated(struct Pokemon *party, int firstId, int lastId, u32 battler, u32 opposingBattler, u32 battlerIn1, u32 battlerIn2, bool32 isSwitchAfterKO)
{
    u32 revengeKillerId = PARTY_SIZE, slowRevengeKillerId = PARTY_SIZE, fastThreatenId = PARTY_SIZE, slowThreatenId = PARTY_SIZE, damageMonId = PARTY_SIZE;
    u32 conRelevo = PARTY_SIZE, typeMatchupId = PARTY_SIZE, typeMatchupEffectiveId = PARTY_SIZE, defensiveMonId = PARTY_SIZE, aceMonId = PARTY_SIZE, trapperId = PARTY_SIZE;
    u32 i, j, aliveCount = 0, bits = 0;
    s32 defensiveMonHitKOThreshold = 3; // 3HKO threshold that candidate defensive mons must exceed
    s32 playerMonHP = gBattleMons[opposingBattler].hp, maxDamageDealt = 0, damageDealt = 0;
    u32 aiMove, hitsToKOAI, maxHitsToKO = 0;
    u16 bestResist = UQ_4_12(1.0), bestResistEffective = UQ_4_12(1.0), typeMatchup;
    bool32 isFreeSwitch = IsFreeSwitch(isSwitchAfterKO, battlerIn1, opposingBattler), isSwitchinFirst, canSwitchinWin1v1;

    // Iterate through mons
    for (i = firstId; i < lastId; i++)
    {
        // Check mon validity
        if (!IsValidForBattle(&party[i])
            || gBattlerPartyIndexes[battlerIn1] == i
            || gBattlerPartyIndexes[battlerIn2] == i
            || i == gBattleStruct->monToSwitchIntoId[battlerIn1]
            || i == gBattleStruct->monToSwitchIntoId[battlerIn2])
        {
            continue;
        }
        // Save Ace Pokemon for last
        else if (IsAceMon(battler, i))
        {
            aceMonId = i;
            continue;
        }
        else
            aliveCount++;

        InitializeSwitchinCandidate(&party[i]);

        // Get max number of hits for player to KO AI mon and type matchup for defensive switching
        hitsToKOAI = GetSwitchinHitsToKO(GetMaxDamagePlayerCouldDealToSwitchin(battler, opposingBattler, AI_DATA->switchinCandidate.battleMon), battler);
        typeMatchup = GetSwitchinTypeMatchup(opposingBattler, AI_DATA->switchinCandidate.battleMon);

        // Track max hits to KO and set defensive mon
        if(hitsToKOAI > maxHitsToKO)
        {
            maxHitsToKO = hitsToKOAI;
            if(maxHitsToKO > defensiveMonHitKOThreshold)
                defensiveMonId = i;
        }

        // Check through current mon's moves
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            aiMove = AI_DATA->switchinCandidate.battleMon.moves[j];

            if (aiMove != MOVE_NONE && !ES_MOVIMIENTO_ESTADO(aiMove))
            {
                damageDealt = AI_CalcPartyMonDamage(aiMove, battler, opposingBattler, AI_DATA->switchinCandidate.battleMon, TRUE);
            }

            // Offensive switchin decisions are based on which whether switchin moves first and whether it can win a 1v1
            isSwitchinFirst = AI_WhoStrikesFirstPartyMon(battler, opposingBattler, AI_DATA->switchinCandidate.battleMon, aiMove);
            canSwitchinWin1v1 = CanSwitchinWin1v1(hitsToKOAI, GetNoOfHitsToKOBattlerDmg(damageDealt, opposingBattler), isSwitchinFirst, isFreeSwitch);

            // Check for Baton Pass; hitsToKO requirements mean mon can boost and BP without dying whether it's slower or not
            if (gMovesInfo[aiMove].effect == EFECTO_RELEVO)
            {
                if ((isSwitchinFirst && hitsToKOAI > 1) || hitsToKOAI > 2) // Need to take an extra hit if slower
                    bits |= 1u << i;
            }

            // Check that good type matchups get at least two turns and set best type matchup mon
            if (typeMatchup < bestResist)
            {
                if (canSwitchinWin1v1)
                {
                    bestResist = typeMatchup;
                    typeMatchupId = i;
                }
            }

            // Check for mon with resistance and super effective move for best type matchup mon with effective move
            if (aiMove != MOVE_NONE && !ES_MOVIMIENTO_ESTADO(aiMove))
            {
                if (typeMatchup < bestResistEffective)
                {
                    if (IA_EfectividadMovimiento(aiMove, battler, opposingBattler) >= AI_EFFECTIVENESS_x2)
                    {
                        if (canSwitchinWin1v1)
                        {
                            bestResistEffective = typeMatchup;
                            typeMatchupEffectiveId = i;
                        }
                    }
                }

                // If a self destruction move doesn't OHKO, don't factor it into revenge killing
                if (gMovesInfo[aiMove].effect == EFFECT_EXPLOSION && damageDealt < playerMonHP)
                    continue;

                // Check that mon isn't one shot and set best damage mon
                if (damageDealt > maxDamageDealt)
                {
                    if((isFreeSwitch && hitsToKOAI > 1) || hitsToKOAI > 2) // This is a "default", we have uniquely low standards
                    {
                        maxDamageDealt = damageDealt;
                        damageMonId = i;
                    }
                }

                // Check if current mon can revenge kill in some capacity
                // If AI mon can one shot
                if (damageDealt > playerMonHP)
                {
                    if (canSwitchinWin1v1)
                    {
                        if (isSwitchinFirst)
                            revengeKillerId = i;
                        else
                            slowRevengeKillerId = i;
                    }
                }

                // If AI mon can two shot
                if (damageDealt > playerMonHP / 2)
                {
                    if (canSwitchinWin1v1)
                    {
                        if (isSwitchinFirst)
                            fastThreatenId = i;
                        else
                            slowThreatenId = i;
                    }
                }

                // If mon can trap
                if (CanAbilityTrapOpponent(AI_DATA->switchinCandidate.battleMon.ability, opposingBattler)
                    && CountUsablePartyMons(opposingBattler) > 0
                    && canSwitchinWin1v1)
                    trapperId = i;
            }
        }
    }

    conRelevo = GetRandomSwitchinWithRelevo(aliveCount, bits, firstId, lastId, i);

    // Different switching priorities depending on switching mid battle vs switching after a KO or slow switch
    if (isFreeSwitch)
    {
        // Return Trapper > Revenge Killer > Type Matchup > Baton Pass > Best Damage
        if (trapperId != PARTY_SIZE)                    return trapperId;
        else if (revengeKillerId != PARTY_SIZE)         return revengeKillerId;
        else if (slowRevengeKillerId != PARTY_SIZE)     return slowRevengeKillerId;
        else if (fastThreatenId != PARTY_SIZE)          return fastThreatenId;
        else if (slowThreatenId != PARTY_SIZE)          return slowThreatenId;
        else if (typeMatchupEffectiveId != PARTY_SIZE)  return typeMatchupEffectiveId;
        else if (typeMatchupId != PARTY_SIZE)           return typeMatchupId;
        else if (conRelevo != PARTY_SIZE)             return conRelevo;
        else if (damageMonId != PARTY_SIZE)             return damageMonId;
    }
    else
    {
        // Return Trapper > Type Matchup > Best Defensive > Baton Pass
        if (trapperId != PARTY_SIZE)                    return trapperId;
        else if (typeMatchupEffectiveId != PARTY_SIZE)  return typeMatchupEffectiveId;
        else if (typeMatchupId != PARTY_SIZE)           return typeMatchupId;
        else if (defensiveMonId != PARTY_SIZE)          return defensiveMonId;
        else if (conRelevo != PARTY_SIZE)             return conRelevo;
    }
    // If ace mon is the last available Pokemon and U-Turn/Volt Switch was used - switch to the mon.
    if (aceMonId != PARTY_SIZE && IsSwitchOutEffect(gMovesInfo[gLastUsedMove].effect))
        return aceMonId;

    return PARTY_SIZE;
}

static u32 GetNextMonInParty(struct Pokemon *party, int firstId, int lastId, u32 battlerIn1, u32 battlerIn2)
{
    u32 i;
    // Iterate through mons
    for (i = firstId; i < lastId; i++)
    {
        // Check mon validity
        if (!IsValidForBattle(&party[i])
            || gBattlerPartyIndexes[battlerIn1] == i
            || gBattlerPartyIndexes[battlerIn2] == i
            || i == gBattleStruct->monToSwitchIntoId[battlerIn1]
            || i == gBattleStruct->monToSwitchIntoId[battlerIn2])
        {
            continue;
        }
        return i;
    }
    return PARTY_SIZE;
}

u32 GetMostSuitableMonToSwitchInto(u32 battler, bool32 switchAfterMonKOd)
{
    u32 opposingBattler = 0;
    u32 bestMonId = PARTY_SIZE;
    u32 battlerIn1 = 0, battlerIn2 = 0;
    s32 firstId = 0;
    s32 lastId = 0; // + 1
    struct Pokemon *party;

    if (*(gBattleStruct->monToSwitchIntoId + battler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + battler);

    if (EsContraEntrenador())
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & (1u << ALIADO(battler)))
            battlerIn2 = battler;
        else
            battlerIn2 = ALIADO(battler);

        opposingBattler = OPONENTE(battlerIn1);
        if (gAbsentBattlerFlags & (1u << opposingBattler))
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = OPONENTE(battler);
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);
    party = GetBattlerParty(battler);

    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SEQUENCE_SWITCHING)
    {
        bestMonId = GetNextMonInParty(party, firstId, lastId, battlerIn1, battlerIn2);
        return bestMonId;
    }

    // Only use better mon selection if AI_FLAG_SMART_MON_CHOICES is set for the trainer.
    if (AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_SMART_MON_CHOICES && !EsContraEntrenador()) // Double Battles aren't included in AI_FLAG_SMART_MON_CHOICE. Defaults to regular switch in logic
    {
        bestMonId = GetBestMonIntegrated(party, firstId, lastId, battler, opposingBattler, battlerIn1, battlerIn2, switchAfterMonKOd);
        return bestMonId;
    }

    // This all handled by the GetBestMonIntegrated function if the AI_FLAG_SMART_MON_CHOICES flag is set
    else
    {
        s32 i, aliveCount = 0;
        u32 invalidMons = 0, aceMonId = PARTY_SIZE;
        // Get invalid slots ids.
        for (i = firstId; i < lastId; i++)
        {
            if (!IsValidForBattle(&party[i])
                || gBattlerPartyIndexes[battlerIn1] == i
                || gBattlerPartyIndexes[battlerIn2] == i
                || i == gBattleStruct->monToSwitchIntoId[battlerIn1]
                || i == gBattleStruct->monToSwitchIntoId[battlerIn2])
            {
                invalidMons |= 1u << i;
            }
            else if (IsAceMon(battler, i)) // Save Ace Pokemon for last.
            {
                aceMonId = i;
                invalidMons |= 1u << i;
            }
            else
            {
                aliveCount++;
            }
        }
        bestMonId = GetBestMonRelevo(party, firstId, lastId, invalidMons, aliveCount, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        bestMonId = GetBestMonTypeMatchup(party, firstId, lastId, invalidMons, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        bestMonId = GetBestMonDmg(party, firstId, lastId, invalidMons, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        // If ace mon is the last available Pokemon and switch move was used - switch to the mon.
        if (aceMonId != PARTY_SIZE)
            return aceMonId;

        return PARTY_SIZE;
    }
}

static bool32 AIExpectsToFaintPlayer(u32 battler)
{
    u8 target = gBattleStruct->aiChosenTarget[battler];

    if (gBattleStruct->IA_Eleccion[battler] > 3)
        return FALSE; // AI not planning to use move

    if (GetBattlerSide(target) != GetBattlerSide(battler)
      && CanIndexMoveFaintTarget(battler, target, gBattleStruct->IA_Eleccion[battler], 0)
      && AI_IsFaster(battler, target, GetAIChosenMove(battler)))
    {
        // We expect to faint the target and move first -> dont use an item
        return TRUE;
    }

    return FALSE;
}

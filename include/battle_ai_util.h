#ifndef GUARD_BATTLE_AI_UTIL_H
#define GUARD_BATTLE_AI_UTIL_H

#define FOE(combatiente) ((OPONENTE(combatiente)) & BIT_SIDE)

enum AIPivot
{
    DONT_PIVOT,
    CAN_TRY_PIVOT,
    SHOULD_PIVOT,
};

bool32 AI_IsFaster(u32 battlerAI, u32 battlerDef, enum Movimientos movimiento);
bool32 AI_IsSlower(u32 battlerAI, u32 battlerDef, enum Movimientos movimiento);
bool32 AI_RandLessThan(u32 val);

static inline bool32 CombatienteEsIA(u32 combatiente)
{
    return EsCombateContraEntrenador(gCombate->tipoCombate)
        && ((combatiente & BIT_SIDE) == LADO_OPONENTE);
};

bool32 IsAIBattlerAware(u32 battlerId);
void ClearBattlerMoveHistory(u32 battlerId);
void RecordLastUsedMoveBy(u32 battlerId, enum Movimientos movimiento);
void RecordAllMoves(u32 battler);
void RecordKnownMove(u32 battlerId, enum Movimientos movimiento);
void RecuerdaHabilidad(u32 combatiente, u32 habilidad);
void ClearBattlerAbilityHistory(u32 battlerId);
void RecordItemEffectBattle(u32 battlerId, u32 itemEffect);
void ClearBattlerItemEffectHistory(u32 battlerId);
void SaveBattlerData(u32 battlerId);
void SetBattlerData(u32 battlerId);
void SetBattlerAIData(u32 battlerId, struct AILogicData *aiData);
void RestoreBattlerData(u32 battlerId);
u32 GetAIChosenMove(u32 battlerId);
u32 GetTotalBaseStat(u32 species);
bool32 AI_BattlerAtMaxHp(u32 battler);
u32 GetHealthPercentage(u32 battler);
bool32 IsBattlerTrapped(u32 battler, bool32 switching);
s32 AI_WhoStrikesFirst(u32 battlerAI, u32 battler2, enum Movimientos movimientoConsiderado);
bool32 CanTargetFaintAI(u32 battlerDef, u32 battlerAtk);
u32 NoOfHitsForTargetToFaintAI(u32 battlerDef, u32 battlerAtk);
u32 GetBestDmgMoveFromBattler(u32 battlerAtk, u32 battlerDef);
u32 GetBestDmgFromBattler(u32 battler, u32 battlerTarget);
bool32 PuedeMovimientoDebilitarObjetivo(enum Movimientos movimiento, u32 defensor, u32 atacante, u32 numeroGolpes);
bool32 CanTargetFaintAIWithMod(u32 battlerDef, u32 battlerAtk, s32 hpMod, s32 dmgMod);
s32 AI_DecideKnownAbilityForTurn(u32 battlerId);
u32 AI_DecideHoldEffectForTurn(u32 battlerId);
bool32 DoesBattlerIgnoreAbilityChecks(u32 atkAbility, enum Movimientos movimiento);
bool32 CanAIFaintTarget(u32 battlerAtk, u32 battlerDef, u32 numHits);
bool32 CanIndexMoveFaintTarget(u32 battlerAtk, u32 battlerDef, u32 index, u32 numHits);
bool32 TieneMovimientoOfensivo(u32 combatiente);
bool32 TieneMovimientoOfensivoTipo(u32 combatiente, u32 tipo);
u32 GetBattlerSecondaryDamage(u32 battlerId);
bool32 BattlerWillFaintFromWeather(u32 battler, u32 ability);
bool32 BattlerWillFaintFromSecondaryDamage(u32 battler, u32 ability);
bool32 ShouldUseRecoilMove(u32 battlerAtk, u32 battlerDef, u32 recoilDmg);
u32 GetBattlerSideSpeedAverage(u32 battler);
bool32 ShouldAbsorb(u32 battlerAtk, u32 battlerDef, enum Movimientos movimiento, s32 damage);
bool32 ShouldRecover(u32 battlerAtk, u32 battlerDef, enum Movimientos movimiento, u32 healPercent);
bool32 ShouldSetScreen(u32 battlerAtk, u32 battlerDef, u32 moveEffect);
enum AIPivot ShouldPivot(u32 battlerAtk, u32 battlerDef, u32 defAbility, enum Movimientos movimiento, u32 moveIndex);
bool32 IsRecycleEncouragedItem(u32 item);
bool32 ShouldRestoreHpBerry(u32 battlerAtk, u32 item);
bool32 IsStatBoostingBerry(u32 item);
bool32 PuedeQuitarObjeto(u32 combatiente, u32 objeto);
bool32 AI_MoveMakesContact(u32 ability, u32 holdEffect, enum Movimientos movimiento);

// stat stage checks
bool32 AnyStatIsRaised(u32 battlerId);
bool32 ShouldLowerStat(u32 battler, u32 battlerAbility, u32 stat);
bool32 BattlerStatCanRise(u32 battler, u32 battlerAbility, u32 stat);
bool32 AreBattlersStatsMaxed(u32 battler);
u32 CountPositiveStatStages(u32 battlerId);
u32 CountNegativeStatStages(u32 battlerId);
bool32 ShouldLowerAttack(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerDefense(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerSpeed(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerSpAtk(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerSpDef(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerAccuracy(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 ShouldLowerEvasion(u32 battlerAtk, u32 battlerDef, u32 defAbility);

// move checks
bool32 IsAffectedByPowder(u32 battler, u32 ability, u32 holdEffect);
bool32 MovesWithCategoryUnusable(u32 attacker, u32 target, u32 category);
s32 AI_WhichMoveBetter(u32 move1, u32 move2, u32 battlerAtk, u32 battlerDef, s32 noOfHitsToKo);
s32 AI_CalcDamage(u32 move, u32 battlerAtk, u32 battlerDef, u8 *typeEffectiveness, enum ClimasCombate climaCombate);
bool32 AI_IsDamagedByRecoil(u32 battler);
u32 GetNoOfHitsToKO(u32 dmg, s32 hp);
u32 GetNoOfHitsToKOBattlerDmg(u32 dmg, u32 battlerDef);
u32 GetNoOfHitsToKOBattler(u32 battlerAtk, u32 battlerDef, u32 moveIndex);
u32 GetCurrDamageHpPercent(u32 battlerAtk, u32 battlerDef);
uq4_12_t IA_EfectividadTipo(enum Movimientos movimiento, u32 atacante, u32 defensor);
u32 IA_EfectividadMovimiento(enum Movimientos movimiento, u32 atacante, u32 defensor);
enum Movimientos *ObtenMovimientos(u32 combatiente);
bool32 IsConfusionMoveEffect(u32 moveEffect);
bool32 HasMove(u32 battlerId, enum Movimientos movimiento);
bool32 HasOnlyMovesWithCategory(u32 battlerId, u32 category, bool32 onlyOffensive);
bool32 HasMoveWithCategory(u32 battler, u32 category);
bool32 HasMoveWithType(u32 battler, u32 type);
bool32 HasMoveEffect(u32 battlerId, u32 moveEffect);
bool32 HasMoveWithAdditionalEffect(u32 battlerId, u32 moveEffect);
bool32 HasMoveWithCriticalHitChance(u32 battlerId);
bool32 HasMoveWithMoveEffectExcept(u32 battlerId, u32 moveEffect, u32 exception);
bool32 HasMoveThatLowersOwnStats(u32 battlerId);
bool32 HasMoveWithLowAccuracy(u32 battlerAtk, u32 battlerDef, u32 accCheck, bool32 ignoreStatus, u32 atkAbility, u32 defAbility, u32 atkHoldEffect, u32 defHoldEffect);
bool32 HasAnyKnownMove(u32 battlerId);
bool32 IsNonVolatileStatusMoveEffect(u32 moveEffect);
bool32 IsMoveRedirectionPrevented(u32 move, u32 atkAbility);
bool32 IsHazardMoveEffect(u32 moveEffect);
bool32 IsTwoTurnNotSemiInvulnerableMove(u32 battlerAtk, u32 move);
void ProtectChecks(u32 battlerAtk, u32 battlerDef, u32 move, u32 predictedMove, s32 *score);
bool32 ShouldSetSandstorm(u32 battler, u32 ability, u32 holdEffect);
bool32 DeberiaPonerNieve(u32 combatiente, u32 habilidad, u32 efectoObjeto);
bool32 ShouldSetRain(u32 battlerAtk, u32 ability, u32 holdEffect);
bool32 ShouldSetSun(u32 battlerAtk, u32 atkAbility, u32 holdEffect);
bool32 TieneMovimientoCura(u32 battler);
bool32 HasTrappingMoveEffect(u32 battler);
bool32 DeberiaUsarSorpresa(u32 battlerAtk, u32 battlerDef, u32 move);
bool32 IsStatRaisingEffect(u32 effect);
bool32 IsStatLoweringEffect(u32 effect);
bool32 IsSelfStatLoweringEffect(u32 effect);
bool32 IsSwitchOutEffect(u32 effect);
bool32 IsAttackBoostMoveEffect(u32 effect);
bool32 IsUngroundingEffect(u32 effect);
bool32 IsSemiInvulnerable(u32 battlerDef, u32 move);
bool32 TieneMovimientoIgnoreSustituto(u32 combatiente);
bool32 TieneMovimientoAltoIndiceCritico(u32 combatiente);

// status checks
bool32 AI_CanBeConfused(u32 battlerAtk, u32 battlerDef, u32 move, u32 ability);
bool32 IsBattlerIncapacitated(u32 battler, u32 ability);
bool32 AI_CanPutToSleep(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 partnerMove);
bool32 ShouldPoisonSelf(u32 battler, u32 ability);
bool32 AI_CanPoison(u32 battlerAtk, u32 battlerDef, u32 move, u32 partnerMove);
bool32 AI_CanParalyze(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 partnerMove);
bool32 AI_CanConfuse(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 battlerAtkPartner, u32 move, u32 partnerMove);
bool32 ShouldBurnSelf(u32 battler, u32 ability);
bool32 AI_CanBurn(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 battlerAtkPartner, u32 move, u32 partnerMove);
bool32 IA_PuedeCongelar(u32 atacante, u32 defensor, u32 habilidad, u32 aliado, u32 movimiento, u32 movimientoAliado);
bool32 AI_CanBeInfatuated(u32 battlerAtk, u32 battlerDef, u32 defAbility);
bool32 AnyPartyMemberStatused(u32 battlerId, bool32 checkSoundproof);
u32 ShouldTryToFlinch(u32 battlerAtk, u32 battlerDef, u32 atkAbility, u32 defAbility, u32 move);
bool32 ShouldTrap(u32 battlerAtk, u32 battlerDef, u32 move);
bool32 IsWakeupTurn(u32 battler);

// partner logic
#define IS_TARGETING_PARTNER(battlerAtk, battlerDef)    ((battlerAtk) == (battlerDef ^ BIT_FLANK))
u32 GetAllyChosenMove(u32 battlerId);
bool32 IsValidDoubleBattle(u32 battlerAtk);
bool32 DoesPartnerHaveSameMoveEffect(u32 battlerAtkPartner, u32 battlerDef, u32 move, u32 partnerMove);
bool32 PartnerHasSameMoveEffectWithoutTarget(u32 battlerAtkPartner, u32 move, u32 partnerMove);
bool32 PartnerMoveEffectIsStatusSameTarget(u32 battlerAtkPartner, u32 battlerDef, u32 partnerMove);
bool32 IsMoveEffectWeather(u32 move);
bool32 PartnerMoveIs(u32 battlerAtkPartner, u32 partnerMove, u32 moveCheck);
bool32 PartnerMoveIsSameAsAttacker(u32 battlerAtkPartner, u32 battlerDef, u32 move, u32 partnerMove);
bool32 PartnerMoveIsSameNoTarget(u32 battlerAtkPartner, u32 move, u32 partnerMove);
bool32 ShouldUseWishAromatherapy(u32 battlerAtk, u32 battlerDef, u32 move);

// party logic
struct BattlePokemon *AllocSaveBattleMons(void);
void FreeRestoreBattleMons(struct BattlePokemon *savedBattleMons);
s32 CountUsablePartyMons(u32 battlerId);
bool32 IsPartyFullyHealedExceptBattler(u32 battler);
bool32 PartyHasMoveCategory(u32 battlerId, u32 category);
bool32 SideHasMoveCategory(u32 battlerId, u32 category);

// score increases
u32 IncreaseStatUpScore(u32 battlerAtk, u32 battlerDef, u32 statId);
u32 IncreaseStatUpScoreContrary(u32 battlerAtk, u32 battlerDef, u32 statId);
void IncreasePoisonScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);
void IncreaseBurnScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);
void IncreaseParalyzeScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);
void IncreaseSleepScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);
void IncreaseConfusionScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);
void AumentaPuntuacionCongelacion(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);

s32 AI_CalcPartyMonDamage(u32 move, u32 battlerAtk, u32 battlerDef, struct BattlePokemon switchinCandidate, bool32 isPartyMonAttacker);
u32 AI_WhoStrikesFirstPartyMon(u32 battlerAtk, u32 battlerDef, struct BattlePokemon switchinCandidate, u32 moveConsidered);
s32 AI_TryToClearStats(u32 battlerAtk, u32 battlerDef, bool32 isDoubleBattle);
bool32 AI_ShouldCopyStatChanges(u32 battlerAtk, u32 battlerDef);
bool32 AI_ShouldSetUpHazards(u32 battlerAtk, u32 battlerDef, struct AILogicData *aiData);
void IncreaseSubstituteMoveScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score);

#endif //GUARD_BATTLE_AI_UTIL_H

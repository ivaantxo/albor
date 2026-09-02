#ifndef GUARD_BATTLE_UTIL_H
#define GUARD_BATTLE_UTIL_H

#define MOVE_LIMITATION_ZEROMOVE                (1 << 0)
#define MOVE_LIMITATION_PP                      (1 << 1)
#define MOVE_LIMITATION_DISABLED                (1 << 2)
#define MOVE_LIMITATION_TORMENTED               (1 << 3)
#define MOVE_LIMITATION_TAUNT                   (1 << 4)
#define MOVE_LIMITATION_IMPRISON                (1 << 5)
#define MOVE_LIMITATION_ENCORE                  (1 << 6)
#define MOVE_LIMITATION_CHOICE_ITEM             (1 << 7)
#define MOVE_LIMITATION_ASSAULT_VEST            (1 << 8)
#define MOVE_LIMITATION_BELCH                   (1 << 9)
#define MOVE_LIMITATION_THROAT_CHOP             (1 << 10)
#define MOVE_LIMITATION_CANT_USE_TWICE          (1 << 11)

#define MOVE_LIMITATIONS_ALL                    0xFFFF

enum MoveBlocked
{
    MOVE_BLOCKED_BY_NO_ABILITY,
    MOVE_BLOCKED_BY_SOUNDPROOF_OR_BULLETPROOF,
    MOVE_BLOCKED_BY_DAZZLING,
    MOVE_BLOCKED_BY_PARTNER_DAZZLING,
    MOVIMIENTO_BLOQUEADO_POR_EXUVIA,
};

enum MoveAbsorbed
{
    MOVE_ABSORBED_BY_NO_ABILITY,
    MOVE_ABSORBED_BY_DRAIN_HP_ABILITY,
    MOVE_ABSORBED_BY_STAT_INCREASE_ABILITY,
    MOVE_ABSORBED_BY_BOOST_FLASH_FIRE,
};

enum {
    ABILITYEFFECT_ON_SWITCHIN,
    ABILITYEFFECT_ENDTURN,
    ABILITYEFFECT_MOVES_BLOCK,
    ABILITYEFFECT_WOULD_BLOCK,         // Checks immunity without triggering a script
    ABILITYEFFECT_ABSORBING,
    ABILITYEFFECT_WOULD_ABSORB,        // Checks immunity without triggering a script
    ABILITYEFFECT_MOVE_END_ATTACKER,
    ABILITYEFFECT_MOVE_END,
    ABILITYEFFECT_IMMUNITY,
    ABILITYEFFECT_SYNCHRONIZE,
    ABILITYEFFECT_ATK_SYNCHRONIZE,
    ABILITYEFFECT_NEUTRALIZINGGAS,
    ABILITYEFFECT_ON_WEATHER,
};

// For the first argument of ItemBattleEffects, to deteremine which block of item effects to try
enum ItemEffectsBattle
{
    ITEMEFFECT_ON_SWITCH_IN,
    ITEMEFFECT_NORMAL,
    ITEMEFFECT_MOVE_END,
    ITEMEFFECT_TARGET,
    ITEMEFFECT_ORBS,
    ITEMEFFECT_LIFEORB,
    ITEMEFFECT_USE_LAST_ITEM,
    ITEMEFFECT_STATS_CHANGED,
};

#define IS_WHOLE_SIDE_ALIVE(battler)    ((IsBattlerAlive(battler) && IsBattlerAlive(ALIADO(battler))))
#define IS_ALIVE_AND_PRESENT(battler)   (IsBattlerAlive(battler) && IsBattlerSpritePresent(battler))

struct TypePower
{
    u8 type;
    u8 power;
    u16 effect;
};

enum
{
    CANCELLER_FLAGS,
    CANCELLER_ASLEEP,
    CANCELLER_RECHARGE,
    CANCELLER_FLINCH,
    CANCELLER_DISABLED,
    CANCELLER_TAUNTED,
    CANCELLER_IMPRISONED,
    CANCELLER_CONFUSED,
    CANCELLER_PARALYSED,
    CANCELLER_IN_LOVE,
    CANCELLER_POWDER_MOVE,
    CANCELLER_THROAT_CHOP,
    CANCELLER_EXPLODING_DAMP,
    CANCELLER_MULTIHIT_MOVES,
    CANCELLER_END,
};

struct DamageCalculationData
{
    u32 battlerAtk;
    u32 battlerDef;
    u32 moveType;
    u32 isCrit;
    u32 updateFlags;
    enum Movimientos movimiento;
};

void HandleAction_ThrowBall(void);
bool32 IsAffectedByFollowMe(u32 battlerAtk, u32 defSide, u32 move);
void HandleAction_UseMove(void);
void HandleAction_Switch(void);
bool32 TryRunFromBattle(u32 battler);
void HandleAction_Run(void);
void HandleAction_TryFinish(void);
void HandleAction_NothingIsFainted(void);
void HandleAction_ActionFinished(void);
u8 GetBattlerForBattleScript(u8 caseId);
void MarcaCombatienteOcupado(u32 combatiente);
void DesmarcaCombatienteOcupado(u32 combatiente);
bool32 EstaCombatienteOcupado(u32 combatiente);
bool32 HayAlgunCombatienteOcupado(void);
const u8* CancelMultiTurnMoves(u32 battler);
bool32 WasUnableToUseMove(u32 battler);
void PrepareStringBattle(u16 stringId, u32 battler);
void EscribeTextoCombate(u32 combatiente, const u8 *texto);
void EscribeTextoSeleccion(u32 combatiente, const u8 *texto);
void IntentaHabilidadPorBajadaEstadistica(void);
void ResetSentPokesToOpponentValue(void);
void OpponentSwitchInResetSentPokesToOpponentValue(u32 battler);
void UpdateSentPokesToOpponentValue(u32 battler);
void BattleScriptPush(const u8 *bsPtr);
void BattleScriptPushCursor(void);
void BattleScriptPop(void);
u32 TrySetCantSelectMoveBattleScript(u32 battler);
u8 CheckMoveLimitations(u32 battler, u8 unusableMoves, u16 check);
bool32 AreAllMovesUnusable(u32 battler);
u8 DoFieldEndTurnEffects(void);
s32 GetDrainedBigRootHp(u32 battler, s32 hp);
u8 DoBattlerEndTurnEffects(void);
bool32 HandleWishPerishSongOnTurnEnd(void);
bool32 HandlePerishSongOnTurnEnd(void);
bool32 HandleFaintedMonActions(void);
void TryClearRageAndFuryCutter(void);
u8 AtkCanceller_UnableToUseMove(u32 moveType);
void SetAtkCancellerForCalledMove(void);
bool32 HasNoMonsToSwitch(u32 battler, u8 r1, u8 r2);
bool32 IntentaCambiarClimaCombate(u32 combatiente, enum ClimasCombate nuevoClima, enum OrigenClima origen);
u32 CanAbilityBlockMove(u32 battlerAtk, u32 battlerDef, enum Movimientos movimiento, u32 abilityDef);
u32 CanPartnerAbilityBlockMove(u32 battlerAtk, u32 battlerDef, enum Movimientos movimiento, u32 abilityDef);
u32 CanAbilityAbsorbMove(u32 battlerAtk, u32 battlerDef, u32 abilityDef, enum Movimientos movimiento, u32 moveType);
u32 AbilityBattleEffects(u32 caseID, u32 battler, u32 ability, u32 special, u32 moveArg);
bool32 IsNeutralizingGasOnField(void);
bool32 IsMoldBreakerTypeAbility(u32 battler, u32 ability);
u32 HabilidadCombatiente(u32 combatiente);
bool32 EstaHabilidadEnElLadoDeCombatiente(u32 battler, u32 ability);
u32 QueCombatienteTieneHabilidad(u32 habilidad);
bool32 EstaHabilidadEnCampoContrario(u32 combatiente, u32 habilidad);
bool32 EstaHabilidadEnCampo(u32 habilidad);
bool32 HabilidadImpideCambiar(u32 combatiente);
bool32 IsBattlerProtected(u32 battlerAtk, u32 battlerDef, enum Movimientos movimiento);
bool32 PuedeCambiar(u32 combatiente);
void BattleScriptExecute(const u8 *BS_ptr);
void BattleScriptPushCursorAndCallback(const u8 *BS_ptr);
u8 ItemBattleEffects(u8 caseID, u32 battler, bool32 moveTurn);
void ClearVariousBattlerFlags(u32 battler);
void HandleAction_RunBattleScript(void);
u32 SetRandomTarget(u32 battler);
u32 GetMoveTarget(enum Movimientos movimiento, u8 setTarget);
u32 GetBattlerHoldEffect(u32 battler, bool32 checkNegating);
u32 GetBattlerHoldEffectIgnoreAbility(u32 battler, bool32 checkNegating);
u32 GetBattlerHoldEffectInternal(u32 battler, bool32 checkNegating, bool32 checkAbility);
u32 GetBattlerHoldEffectParam(u32 battler);
bool32 IsMoveMakingContact(enum Movimientos movimiento, u32 battlerAtk);
bool32 EstaCombatienteEnSuelo(u32 battler);
bool32 IsBattlerAlive(u32 battler);
bool32 TransitorioActivo(u32 combatiente, u32 estado);
void PonTransitorio(u32 combatiente, u32 estado);
void QuitaTransitorio(u32 combatiente, u32 estado);
void QuitaTodosTransitorios(u32 combatiente);
bool32 EstadoActivo(u32 combatiente, u32 estado);
u32 EstadoParaIcono(u32 combatiente);
bool32 HayAlgunEstado(u32 combatiente);
void PonEstado(u32 combatiente, u32 estado);
void QuitaEstado(u32 combatiente, u32 estado);
void QuitaTodosEstados(u32 combatiente);
uq4_12_t ModificadorEstadoSobreEstadistica(u32 combatiente, u32 estadistica);
bool32 HayAlgunCombatienteDebilitado(void);
u32 ObtenIndiceMovimiento(enum Movimientos *movimientos, enum Movimientos movimiento);
u32 GetBattlerWeight(u32 battler);
u32 CalcRolloutBasePower(u32 battlerAtk, u32 basePower, u32 rolloutTimer);
u32 CalcFuryCutterBasePower(u32 basePower, u32 furyCutterCounter);
s32 CalculateMoveDamage(struct DamageCalculationData *damageCalcData, u32 fixedBasePower);
uq4_12_t ObtenModificadorDanioObjetivoMultiple(struct DamageCalculationData *damageCalcData);
s32 CalculateMoveDamageVars(struct DamageCalculationData *damageCalcData, u32 fixedBasePower, uq4_12_t typeEffectivenessModifier,
                            enum ClimasCombate climaCombate, u32 holdEffectAtk, u32 holdEffectDef, u32 abilityAtk, u32 abilityDef);
uq4_12_t CalcTypeEffectivenessMultiplier(enum Movimientos movimiento, u32 moveType, u32 battlerAtk, u32 battlerDef, u32 defAbility, bool32 recordAbilities);
uq4_12_t CalcPartyMonTypeEffectivenessMultiplier(enum Movimientos movimiento, u16 speciesDef, u16 abilityDef);
uq4_12_t ModificadorTipo(u32 tipoAtacante, u32 tipoDefensor);
s32 DanioTrampa(u32 tipoTrampa, u32 combatiente);
s32 CalculaDanioTrampa(u32 tipoTrampa, u32 tipo1, u32 tipo2, u32 psMaximos);
u32 CalculaDanioTrampasEntrada(u32 lado, u32 tipo1, u32 tipo2, u32 psMaximos);
bool32 HayTrampaEntrada(u32 trampa, u32 lado);
bool32 HayAlgunaTrampaEntrada(u32 lado);
bool32 HayAlgunaTrampaDanio(u32 lado);
bool32 ColocaTrampaEntrada(u32 trampa, u32 lado);
void QuitaTrampaEntrada(u32 trampa, u32 lado);
void QuitaTodasTrampasEntrada(u32 lado);
void ReiniciaTrampasEntrada(void);
u32 TipoTrampaEntrada(u32 trampa);
u32 TrampaEntradaPorTipo(u32 tipo);
enum Movimientos MovimientoTrampaEntrada(u32 trampa);
u32 CuentaTrampasAbsorbibles(u32 lado, u32 tipo1, u32 tipo2);
u32 AbsorbeTrampasPorTipo(u32 lado, u32 tipo1, u32 tipo2);
bool32 EsInmuneATrampas(u32 combatiente);
u16 GetBattleFormChangeTargetSpecies(u32 battler, u16 method);
bool32 TryBattleFormChange(u32 battler, u32 method);
bool32 IsTelekinesisBannedSpecies(u16 species);
bool32 IsBelchPreventingMove(u32 battler, u32 move);
bool32 HasEnoughHpToEatBerry(u32 battler, u32 hpFraction, u32 itemId);
bool32 EstaPotenciadoPotenciaBruta(u32 combatiente, enum Movimientos movimiento);
void RecuperaObjetoPerdido(void);
u8 TryHandleSeed(u32 battler, u32 terrainFlag, u8 statId, u16 itemId, bool32 execute);
void SortBattlersBySpeed(u8 *battlers, bool32 slowToFast);
bool32 CompareStat(u32 battler, u8 statId, u8 cmpTo, u8 cmpKind);
bool32 TryRoomService(u32 battler);
void BufferStatChange(u32 battler, u8 statId, bool32 subio);
bool32 BlocksPrankster(enum Movimientos movimiento, u32 battlerPrankster, u32 battlerDef, bool32 checkTarget);
u16 GetUsedHeldItem(u32 battler);
u32 GetBattlerMoveTargetType(u32 battler, enum Movimientos movimiento);
void CopyMonLevelAndBaseStatsToBattleMon(u32 battler, struct Pokemon *mon);
void CopyMonAbilityAndTypesToBattleMon(u32 battler, struct Pokemon *mon);
void RecalcBattlerStats(u32 battler, struct Pokemon *mon);
bool32 EsAliado(u32 atacante, u32 defensor);
bool32 IsGen6ExpShareEnabled(void);
bool32 MoveHasAdditionalEffect(enum Movimientos movimiento, u32 moveEffect);
bool32 MoveHasAdditionalEffectWithChance(enum Movimientos movimiento, u32 moveEffect, u32 chance);
bool32 MoveHasAdditionalEffectSelf(enum Movimientos movimiento, u32 moveEffect);
bool32 MoveHasChargeTurnAdditionalEffect(enum Movimientos movimiento);
bool32 CanTargetPartner(u32 battlerAtk, u32 battlerDef);
bool32 TargetFullyImmuneToCurrMove(u32 battlerAtk, u32 battlerDef);

bool32 CanBeSlept(u32 battler, u32 ability);
bool32 CanBePoisoned(u32 battler, u32 ability);
bool32 CanBeBurned(u32 battler, u32 ability);
bool32 CanBeParalyzed(u32 battler, u32 ability);
bool32 PuedeSerCongelado(u32 combatiente, u32 habilidad);
bool32 CanBeConfused(u32 battler);
u32 CountBattlerStatIncreases(u32 battler, bool32 countEvasionAcc);
void RemoveConfusionStatus(u32 battler);
u8 GetBattlerGender(u32 battler);
bool32 PuedeEnamorarse(u32 combatiente, u32 habilidad);
bool32 AreBattlersOfOppositeGender(u32 battler1, u32 battler2);
bool32 AreBattlersOfSameGender(u32 battler1, u32 battler2);
u32 CalculaProbabilidadEfectoSecundario(u32 habilidad, const struct AdditionalEffect *efectoSecundario);
bool32 EfectoSecundarioGarantizado(u32 habilidad, const struct AdditionalEffect *efectoSecundario);
void AllocateBattleResources(void);
void FreeBattleResources(void);
void AdjustFriendshipOnBattleFaint(u8 battler);
u32 CuantosPSLeQuedan(u32 combatiente);
u32 CuantosPSMaximos(u32 combatiente);
enum ClimasCombate ObtenClimaCombate(void);

#endif // GUARD_BATTLE_UTIL_H

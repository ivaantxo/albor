#include "config/general.h"
#include "config/battle.h"
#include "constants/global.h"
#include "constants/battle.h"
#include "constants/pokemon.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/battle_string_ids.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/trainers.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

BattleScript_LowerAtkSpAtk::
	jumpifstat BS_EFFECT_BATTLER, COMPARACION_MAYOR, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_LowerAtkSpAtkDoAnim
	jumpifstat BS_EFFECT_BATTLER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MENOS_6, BattleScript_LowerAtkSpAtkEnd

BattleScript_LowerAtkSpAtkDoAnim::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_EFFECT_BATTLER, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_LowerAtkSpAtkTrySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_LowerAtkSpAtkTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_LowerAtkSpAtkTrySpAtk::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_LowerAtkSpAtkEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_LowerAtkSpAtkEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_LowerAtkSpAtkEnd:
	return

ScriptCombate_EfectoPalmaRauda::
	attackcanceler
	IntentaPalmaRauda BattleScript_FailedFromAtkString
	goto BattleScript_HitFromAccCheck

BattleScript_MoveSwitch:
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_MoveSwitchEnd
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} went back to {B_ATK_TRAINER_NAME}!"
	waitmessage PAUSA_CORTA

BattleScript_MoveSwitchOpenPartyScreen:
	openpartyscreen BS_ATTACKER, BattleScript_MoveSwitchEnd
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER, FALSE
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER

BattleScript_MoveSwitchEnd:
	end

BattleScript_HurtTarget_NoString:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET
	return

BattleScript_EffectCorrosiveGas::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_CorrosiveGasFail
	jumpifcantloseitem BS_TARGET, BattleScript_CorrosiveGasFail
	attackanimation
	waitanimation
	jumpifability BS_TARGET, ABILITY_STICKY_HOLD, BattleScript_StickyHoldActivates
	setlastuseditem BS_TARGET
	removeitem BS_TARGET
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} corroded {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_CorrosiveGasFail:
	pause PAUSA_CORTA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	EscribeTextoCombate "It had no effect on {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTakeHeart::
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalysedorpoisoned BattleScript_CalmMindTryToRaiseStats
	attackanimation
	waitanimation
	updatestatusicon BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s status returned to normal!"
	waitmessage PAUSA_LARGA
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CalmMindStatRaise
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CalmMindStatRaise
	goto BattleScript_CantRaiseMultipleStats

BattleScript_StealthRockActivates::
	setstealthrock BattleScript_MoveEnd
	printfromtable gDmgHazardsStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_SpikesActivates::
	trysetspikes BattleScript_MoveEnd
	printfromtable gDmgHazardsStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectAttackUpUserAlly::
	jumpifnoally BS_ATTACKER, BattleScript_EffectAttackUp
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_EffectAttackUpUserAlly_Works
	jumpifstat BS_ATTACKER_PARTNER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_ButItFailed

BattleScript_EffectAttackUpUserAlly_Works:
	attackanimation
	waitanimation
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAttackUpUserAlly_TryAlly
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectAttackUpUserAllyUser_PrintString
	setgraphicalstatchangevalues

	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_EffectAttackUpUserAllyUser_PrintString:
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_EffectAttackUpUserAlly_TryAlly:
	setallytonexttarget BattleScript_EffectAttackUpUserAlly_TryAlly_

BattleScript_EffectAttackUpUserAlly_End:
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUpUserAlly_TryAlly_:
	jumpifblockedbysoundproof BS_ATTACKER_PARTNER, BattleScript_EffectAttackUpUserAlly_TryAllyBlocked
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAttackUpUserAlly_End
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectAttackUpUserAlly_AllyAnim
	pause PAUSA_MUY_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"
	waitmessage PAUSA_LARGA
	goto BattleScript_EffectAttackUpUserAlly_End

BattleScript_EffectAttackUpUserAlly_AllyAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_EffectAttackUpUserAlly_End

BattleScript_EffectAttackUpUserAlly_TryAllyBlocked:
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_AbilityPopUpTarget
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} blocks {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPhotonGeyser::
	setphotongeysercategory
	goto BattleScript_EffectHit

BattleScript_EffectAuraWheel:: @ Aura Wheel can only be used by Morpeko
	goto BattleScript_PokemonCantUseTheMove

BattleScript_EffectOctolock::
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetoctolock BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} can no longer escape because of Octolock!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_OctolockEndTurn::
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_OctolockTryLowerSpDef
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_OctolockTryLowerSpDef:
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_OctlockTurnDmgEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_OctlockTurnDmgEnd:
	end2

BattleScript_EffectPoltergeist::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	checkpoltergeist BS_TARGET, BattleScript_ButItFailed
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} is about to be attacked by its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_HitFromCritCalc

BattleScript_EffectNoRetreat::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trynoretreat BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	call BattleScript_AllStatsUp
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_MoveEnd
	seteffectprimary MOVE_EFFECT_PREVENT_ESCAPE | MOVE_EFFECT_AFFECTS_USER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can no longer escape because it used No Retreat!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_BothCanNoLongerEscape::
	EscribeTextoCombate "Neither Pokémon can run away!"
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectSparklySwirl::
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET
	healpartystatus
	waitstate
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectCoaching::
	attackcanceler
	attackstring
	ppreduce
	jumpifnoally BS_ATTACKER, BattleScript_ButItFailed
	copybyte gBattlerTarget, gBattlerAttacker
	setallytonexttarget EffectCoaching_CheckAllyStats
	goto BattleScript_ButItFailed

EffectCoaching_CheckAllyStats:
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_CoachingWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_CoachingWorks
	goto BattleScript_ButItFailed   @ ally at max atk, def

BattleScript_CoachingWorks:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_CoachingBoostDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, 2, BattleScript_CoachingBoostDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CoachingBoostDef:
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR | STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_MoveEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, 2, BattleScript_MoveEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRelicSong::
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET
	moveendall
	tryrelicsong
	end

BattleScript_EffectFairyLock::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetfairylock BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "No one will be able to run away during the next turn!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_FailIfNotArgType::
	attackcanceler
	attackstring
	ppreduce
	jumpifnotcurrentmoveargtype BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_RemoveFireType::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} burned itself out!"
	waitmessage PAUSA_LARGA
	return

BattleScript_DefDown::
	modifybattlerstatstage BS_TARGET, ESTADISTICA_DEFENSA, DECREASE, 1, BattleScript_DefDown_Ret, ANIM_ON

BattleScript_DefDown_Ret:
	return

BattleScript_EffectPurify::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_PurifyWorks
	goto BattleScript_ButItFailed

BattleScript_PurifyWorks:
	attackanimation
	waitanimation
	curestatus BS_TARGET
	updatestatusicon BS_TARGET
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} cured {B_DEF_NAME_WITH_PREFIX}'s problem!"
	waitmessage PAUSA_LARGA
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	goto BattleScript_RestoreHp

BattleScript_EffectStrengthSap::
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_StrengthSapTryLower
	pause PAUSA_CORTA
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd
BattleScript_StrengthSapTryLower:
	getstatvalue BS_TARGET, ESTADISTICA_ATAQUE
	jumpiffullhp BS_ATTACKER, BattleScript_StrengthSapMustLower
	attackanimation
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StrengthSapHp
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_StrengthSapHp
BattleScript_StrengthSapLower:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_StrengthSapHp

@ Drain HP without lowering a stat
BattleScript_StrengthSapHp:
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_StrengthSapManipulateDmg
	jumpiffullhp BS_ATTACKER, BattleScript_MoveEnd

BattleScript_StrengthSapManipulateDmg:
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_StrengthSapLiquidOoze
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNENERGYDRAINED
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_StrengthSapLiquidOoze:
	call BattleScript_AbilityPopUpTarget
	manipulatedamage DMG_CHANGE_SIGN
	setword gMensajeBatalla, B_MSG_ABSORB_OOZE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printfromtable gAbsorbDrainStringIds
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_StrengthSapMustLower:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_MoveEnd
	attackanimation
	waitanimation
	goto BattleScript_StrengthSapLower

BattleScript_MoveEffectIncinerate::
	EscribeTextoCombate "{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} was burnt up!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectBugBite::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} stole and ate its target's {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, 1   @ override the requirements for eating berries
	savetarget
	consumeberry BS_ATTACKER, FALSE
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
	setbyte sBERRY_OVERRIDE, 0
	trysymbiosis
	restoretarget
	return

BattleScript_SpectralThiefSteal::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} stole the target's boosted stats!"
	waitmessage PAUSA_LARGA
	setbyte sB_ANIM_ARG2, 0
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	spectralthiefprintstats
	return

BattleScript_EffectPartingShot::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, COMPARACION_MAYOR, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_EffectPartingShotTryAtk
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MENOS_6, BattleScript_CantLowerMultipleStats

BattleScript_EffectPartingShotTryAtk:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectPartingShotTrySpAtk
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_EffectPartingShotTrySpAtk:
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectPartingShotSwitch
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_EffectPartingShotSwitch:
	moveendall
	goto BattleScript_MoveSwitch

BattleScript_EffectPowder::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_POWDER, BattleScript_ButItFailed
	setpowder BS_TARGET
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} is covered in powder!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectAromaticMist::
	attackcanceler
	attackstring
	ppreduce
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_ButItFailed
	jumpiftargetally BattleScript_EffectAromaticMistWorks
	goto BattleScript_ButItFailed

BattleScript_EffectAromaticMistWorks:
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_EffectAromaticMistEnd
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AromaticMistAnim
	pause PAUSA_MUY_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"
	waitmessage PAUSA_LARGA
	goto BattleScript_EffectAromaticMistEnd

BattleScript_AromaticMistAnim:
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_EffectAromaticMistEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectGearUp::
	goto BattleScript_ButItFailed

BattleScript_EffectAcupressure::
	attackcanceler
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_EffectAcupressureTry
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_PrintMoveMissed
BattleScript_EffectAcupressureTry:
	attackstring
	ppreduce
	tryaccupressure BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	statbuffchange MOVE_EFFECT_CERTAIN, BattleScript_MoveEnd
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFeint::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} fell for the feint!"
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectRototiller::
	attackcanceler
	attackstring
	ppreduce
	getrototillertargets BattleScript_ButItFailed
	@ at least one battler is affected
	attackanimation
	waitanimation
	savetarget
	setbyte gBattlerTarget, 0

BattleScript_RototillerLoop:
	movevaluescleanup
	jumpifstat BS_TARGET, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_RototillerCheckAffected
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_RototillerCantRaiseMultipleStats

BattleScript_RototillerCheckAffected:
	jumpifnotrototilleraffected BS_TARGET, BattleScript_RototillerNoEffect
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerTrySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_RototillerTrySpAtk::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RototillerMoveTargetEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_RototillerMoveTargetEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_RototillerMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RototillerLoop
	end

BattleScript_RototillerCantRaiseMultipleStats:
	copybyte gBattlerAttacker, gBattlerTarget
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage PAUSA_LARGA
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_RototillerNoEffect:
	pause PAUSA_CORTA
	EscribeTextoCombate "It had no effect on {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_RototillerMoveTargetEnd

BattleScript_EffectBestow::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	trybestow BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM} from {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	trysymbiosis
	goto BattleScript_MoveEnd

BattleScript_EffectAfterYou::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryafteryou BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} took the kind offer!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_MoveEffectFlameBurst::
	tryfaintmon BS_TARGET
	copybyte sBATTLER, sSAVED_BATTLER
	EscribeTextoCombate "The bursting flames hit {B_SCR_ACTIVE_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	savetarget
	copybyte gBattlerTarget, sSAVED_BATTLER
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	tryfaintmon BS_TARGET
	restoretarget
	goto BattleScript_MoveEnd

BattleScript_EffectPowerTrick::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	powertrick BS_ATTACKER
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} switched its Attack and Defense!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSynchronoise::
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget

BattleScript_SynchronoiseLoop:
	movevaluescleanup
	jumpifcantusesynchronoise BattleScript_SynchronoiseNoEffect
	accuracycheck BattleScript_SynchronoiseMissed, ACC_CURR_MOVE
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
	tryfaintmon BS_TARGET

BattleScript_SynchronoiseMoveTargetEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_SynchronoiseLoop
	end

BattleScript_SynchronoiseMissed:
	pause PAUSA_CORTA
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_SynchronoiseMoveTargetEnd

BattleScript_SynchronoiseNoEffect:
	pause PAUSA_CORTA
	EscribeTextoCombate "It had no effect on {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_SynchronoiseMoveTargetEnd

BattleScript_MoveEffectSmackDown::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} fell straight down!"
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectHitEnemyHealAlly::
	jumpiftargetally BattleScript_EffectHealPulse
	goto BattleScript_EffectHit

BattleScript_EffectDefog::
	setstatchanger ESTADISTICA_EVASION, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_DefogIfCanClearHazards
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_EVASION, ESTADISTICA_MENOS_6, BattleScript_DefogWorks
BattleScript_DefogIfCanClearHazards:
	trydefog FALSE, BattleScript_FailedFromAtkString
BattleScript_DefogWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_DefogTryHazardsWithAnim
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_DefogDoAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_DefogTryHazardsWithAnim
	pause PAUSA_CORTA
	goto BattleScript_DefogPrintString
BattleScript_DefogDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_DefogPrintString::
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
BattleScript_DefogTryHazards::
	copybyte gEffectBattler, gBattlerAttacker
	trydefog TRUE, NULL
	copybyte gBattlerAttacker, gEffectBattler
	goto BattleScript_MoveEnd
BattleScript_DefogTryHazardsWithAnim:
	attackanimation
	waitanimation
	goto BattleScript_DefogTryHazards

BattleScript_EffectAutotomize::
	setstatchanger ESTADISTICA_VELOCIDAD, 2, FALSE
	attackcanceler
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AutotomizeWeightLoss
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AutotomizeAttackAnim
	pause PAUSA_CORTA
	goto BattleScript_AutotomizePrintString

BattleScript_AutotomizeAttackAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_AutotomizePrintString::
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AutotomizeWeightLoss::
	jumpifmovehadnoeffect BattleScript_MoveEnd
	tryautotomize BS_ATTACKER, BattleScript_MoveEnd
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} became nimble!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectHitSwitchTarget::
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET
	jumpiffainted BS_TARGET, TRUE, BattleScript_MoveEnd
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifability BS_TARGET, ABILITY_GUARD_DOG, BattleScript_MoveEnd
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	tryhitswitchtarget BattleScript_MoveEnd
	forcerandomswitch BattleScript_HitSwitchTargetForceRandomSwitchFailed
	goto BattleScript_MoveEnd

BattleScript_HitSwitchTargetForceRandomSwitchFailed:
	hitswitchtargetfailed
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd

BattleScript_EffectToxicThread::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, BattleScript_ToxicThreadWorks
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_FailedFromAtkString

BattleScript_ToxicThreadWorks:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_ToxicThreadTryPsn
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_ToxicThreadDoAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_ToxicThreadTryPsn
	pause PAUSA_CORTA
	goto BattleScript_ToxicThreadPrintString

BattleScript_ToxicThreadDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_ToxicThreadPrintString::
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_ToxicThreadTryPsn::
	seteffectprimary MOVE_EFFECT_POISON
	goto BattleScript_MoveEnd

BattleScript_EffectVenomDrench::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_TARGET, STATUS1_PSN_ANY, BattleScript_EffectVenomDrenchCanBeUsed
	goto BattleScript_ButItFailed

BattleScript_EffectVenomDrenchCanBeUsed:
	jumpifstat BS_TARGET, COMPARACION_MAYOR, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, COMPARACION_MAYOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MENOS_6, BattleScript_VenomDrenchDoMoveAnim
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, BattleScript_CantLowerMultipleStats

BattleScript_VenomDrenchDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK | BIT_SPEED, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpAtk
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_VenomDrenchTryLowerSpAtk::
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchTryLowerSpeed
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchTryLowerSpeed
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_VenomDrenchTryLowerSpeed::
	playstatchangeanimation BS_TARGET, BIT_SPEED, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_VELOCIDAD, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_VenomDrenchEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_VenomDrenchEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_VenomDrenchEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectRugidoNoble::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, COMPARACION_MAYOR, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_RugidoNobleDoMoveAnim
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MENOS_6, BattleScript_CantLowerMultipleStats

BattleScript_RugidoNobleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RugidoNobleTryLowerSpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_RugidoNobleTryLowerSpAtk
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_RugidoNobleTryLowerSpAtk::
	playstatchangeanimation BS_TARGET, BIT_SPATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RugidoNobleEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_RugidoNobleEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_RugidoNobleEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectShellSmash::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, COMPARACION_MAYOR, ESTADISTICA_DEFENSA, ESTADISTICA_MENOS_6, BattleScript_ShellSmashTryDef
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MENOS_6, BattleScript_ButItFailed

BattleScript_ShellSmashTryDef::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShellSmashTrySpDef:
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_ShellSmashTryAttack
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTryAttack
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShellSmashTryAttack:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_ATK | BIT_SPEED, STAT_CHANGE_BY_TWO
	setstatchanger ESTADISTICA_ATAQUE, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShellSmashTrySpAtk:
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashTrySpeed
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashTrySpeed
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShellSmashTrySpeed:
	setstatchanger ESTADISTICA_VELOCIDAD, 2, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShellSmashEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShellSmashEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShellSmashEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectLastResort::
	attackcanceler
	attackstring
	ppreduce
	jumpifcantuselastresort BS_ATTACKER, BattleScript_ButItFailed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectGrowth::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_GrowthDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_GrowthDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthAtk2
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	goto BattleScript_GrowthAtk

BattleScript_GrowthAtk2:
	setstatchanger ESTADISTICA_ATAQUE, 2, FALSE

BattleScript_GrowthAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthTrySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_GrowthTrySpAtk::
	jumpifweatheraffected BS_ATTACKER, B_WEATHER_SUN, BattleScript_GrowthSpAtk2
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	goto BattleScript_GrowthSpAtk

BattleScript_GrowthSpAtk2:
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE

BattleScript_GrowthSpAtk:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_GrowthEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_GrowthEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_GrowthEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectReflectType::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	tryreflecttype BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} became the same type as {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectShiftGear::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_ShiftGearDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_ShiftGearDoMoveAnim:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	jumpifstat BS_ATTACKER, COMPARACION_MAYOR, ESTADISTICA_VELOCIDAD, 10, BattleScript_ShiftGearSpeedBy1
	playstatchangeanimation BS_ATTACKER, BIT_SPEED | BIT_ATK, STAT_CHANGE_BY_TWO
	setstatchanger ESTADISTICA_VELOCIDAD, 2, FALSE
	goto BattleScript_ShiftGearDoSpeed

BattleScript_ShiftGearSpeedBy1:
	playstatchangeanimation BS_ATTACKER, BIT_SPEED | BIT_ATK, 0
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE

BattleScript_ShiftGearDoSpeed:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShiftGearTryAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShiftGearTryAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShiftGearTryAtk:
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_ShiftGearEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_ShiftGearEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_ShiftGearEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectCoil::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_CoilDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_PRECISION, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_CoilDoMoveAnim:
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_ACC, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CoilTryDef:
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilTryAcc
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilTryAcc
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CoilTryAcc:
	setstatchanger ESTADISTICA_PRECISION, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CoilEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CoilEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CoilEnd:
	goto BattleScript_MoveEnd

ScriptCombate_EfectoSubeAtaqueEspecialVelocidad::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_DanzaAleteoDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_DanzaAleteoDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF | BIT_SPEED, 0
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DanzaAleteoTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DanzaAleteoTrySpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DanzaAleteoTrySpDef::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DanzaAleteoTrySpeed
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DanzaAleteoTrySpeed
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DanzaAleteoTrySpeed::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DanzaAleteoEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DanzaAleteoEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DanzaAleteoEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectAttackSpAttackUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_AttackSpAttackUpDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_AttackSpAttackUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPATK, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpTrySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpTrySpAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AttackSpAttackUpTrySpAtk::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackSpAttackUpEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackSpAttackUpEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AttackSpAttackUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectAttackAccUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_AttackAccUpDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_PRECISION, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_AttackAccUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpTrySpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AttackAccUpTrySpDef::
	setstatchanger ESTADISTICA_PRECISION, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackAccUpEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_AttackAccUpEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AttackAccUpEnd:
	goto BattleScript_MoveEnd

BattleScript_EffectTopsyTurvy::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_DEFENSA, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE_ESPECIAL, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_DEFENSA_ESPECIAL, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_VELOCIDAD, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_DESIGUAL, ESTADISTICA_PRECISION, 6, BattleScript_EffectTopsyTurvyWorks
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_EVASION, 6, BattleScript_ButItFailed

BattleScript_EffectTopsyTurvyWorks:
	attackanimation
	waitanimation
	invertstatstages BS_TARGET
	EscribeTextoCombate "All stat changes on {B_DEF_NAME_WITH_PREFIX} were inverted!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectHealPulse::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifsubstituteblocks BattleScript_ButItFailed
	tryhealpulse BattleScript_AlreadyAtFullHp
	attackanimation
	waitanimation
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} regained health!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSimpleBeam::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setabilitysimple BS_TARGET, BattleScript_ButItFailed
	attackanimation
	waitanimation
	copybyte gBattlerAbility, gBattlerTarget
	call BattleScript_AbilityPopUpOverwriteThenNormal
	recordability BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} acquired Simple!"
	waitmessage PAUSA_LARGA
	tryrevertweatherform
	tryendneutralizinggas BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectGolpeBajo::
	attackcanceler
	golpebajocheck BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromAtkString

BattleScript_EffectLuckyChant::
	attackcanceler
	attackstring
	ppreduce
	setluckychant BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "The {B_CURRENT_MOVE} shielded {B_ATK_TEAM2} team from critical hits!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats ESTADISTICA_ATAQUE
	averagestats ESTADISTICA_ATAQUE_ESPECIAL
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} shared its power with the target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	averagestats ESTADISTICA_DEFENSA
	averagestats ESTADISTICA_DEFENSA_ESPECIAL
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} shared its guard with the target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectHeartSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages ESTADISTICA_ATAQUE
	swapstatstages ESTADISTICA_DEFENSA
	swapstatstages ESTADISTICA_VELOCIDAD
	swapstatstages ESTADISTICA_ATAQUE_ESPECIAL
	swapstatstages ESTADISTICA_DEFENSA_ESPECIAL
	swapstatstages ESTADISTICA_EVASION
	swapstatstages ESTADISTICA_PRECISION
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} switched stat changes with the target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPowerSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages ESTADISTICA_ATAQUE
	swapstatstages ESTADISTICA_ATAQUE_ESPECIAL
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} switched stat changes with the target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectGuardSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstatstages ESTADISTICA_DEFENSA
	swapstatstages ESTADISTICA_DEFENSA_ESPECIAL
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} switched stat changes with the target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSpeedSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	swapstats ESTADISTICA_VELOCIDAD
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} switched {B_BUFF1} with its target!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTelekinesis::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, NO_ACC_CALC_CHECK_LOCK_ON
	attackstring
	ppreduce
	settelekinesis BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} was hurled into the air!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectStealthRock::
	attackcanceler
	attackstring
	ppreduce
	setstealthrock BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_POINTEDSTONESFLOAT
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectStickyWeb::
	attackcanceler
	attackstring
	ppreduce
	setstickyweb BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "A sticky web has been laid out on the ground around {B_DEF_TEAM2} team!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectGastroAcid::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setgastroacid BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s ability was suppressed!"
	waitmessage PAUSA_LARGA
	tryrevertweatherform
	tryendneutralizinggas BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectToxicSpikes::
	attackcanceler
	attackstring
	ppreduce
	settoxicspikes BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "¡Han caído púas tóxicas en el campo de {B_DEF_TEAM2}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectMagnetRise::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_MAGNET_RISE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} levitated on electromagnetism!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTrickRoom::
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage PAUSA_LARGA
	call BattleScript_TryRoomServiceLoop
	goto BattleScript_MoveEnd

BattleScript_TryRoomServiceLoop:
	savetarget
	setbyte gBattlerTarget, 0

BattleScript_RoomServiceLoop:
	copybyte sBATTLER, gBattlerTarget
	tryroomservice BS_TARGET, BattleScript_RoomServiceLoop_NextBattler
	removeitem BS_TARGET

BattleScript_RoomServiceLoop_NextBattler:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_RoomServiceLoop
	restoretarget
	return

BattleScript_EffectWonderRoom::
BattleScript_EffectMagicRoom::
	attackcanceler
	attackstring
	ppreduce
	setroom
	attackanimation
	waitanimation
	printfromtable gRoomsStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectAquaRing::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_AQUA_RING, BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} surrounded itself with a veil of water!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectEmbargo::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setembargo BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} can't use items anymore!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTailwind::
	attackcanceler
	attackstring
	ppreduce
	settailwind BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "The tailwind blew from behind {B_ATK_TEAM2} team!"
	waitmessage PAUSA_LARGA
	call BattleScript_TryTailwindAbilitiesLoop
	goto BattleScript_MoveEnd

BattleScript_TryTailwindAbilitiesLoop:
	savetarget
	setbyte gBattlerTarget, 0

BattleScript_TryTailwindAbilitiesLoop_Iter:
	trywindriderpower BS_TARGET, BattleScript_TryTailwindAbilitiesLoop_Increment
	jumpifability BS_TARGET, ABILITY_WIND_RIDER, BattleScript_TryTailwindAbilitiesLoop_WindRider
	jumpifability BS_TARGET, ABILITY_WIND_POWER, BattleScript_TryTailwindAbilitiesLoop_WindPower
	jumpifability BS_TARGET, ABILITY_GLOBO, BattleScript_TryTailwindAbilitiesLoop_Globo

BattleScript_TryTailwindAbilitiesLoop_Increment:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TryTailwindAbilitiesLoop_Iter
	restoretarget
	return

BattleScript_TryTailwindAbilitiesLoop_WindRider:
	call BattleScript_AbilityPopUp
	modifybattlerstatstage BS_TARGET, ESTADISTICA_ATAQUE, INCREASE, 1, BattleScript_TryTailwindAbilitiesLoop_Increment, ANIM_ON
	goto BattleScript_TryTailwindAbilitiesLoop_Increment

BattleScript_TryTailwindAbilitiesLoop_WindPower:
	call BattleScript_AbilityPopUp
	setcharge BS_TARGET
	EscribeTextoCombate "Being hit by {B_CURRENT_MOVE} charged {B_DEF_NAME_WITH_PREFIX} with power!"
	waitmessage PAUSA_LARGA
	goto BattleScript_TryTailwindAbilitiesLoop_Increment

BattleScript_TryTailwindAbilitiesLoop_Globo:
	call BattleScript_AbilityPopUp
	modifybattlerstatstage BS_TARGET, ESTADISTICA_DEFENSA, INCREASE, 1, BattleScript_TryTailwindAbilitiesLoop_Increment, ANIM_ON
	goto BattleScript_TryTailwindAbilitiesLoop_Increment

BattleScript_EffectMircleEye::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmiracleeye BattleScript_ButItFailed
	goto BattleScript_IdentifiedFoe

BattleScript_EffectGravity::
	attackcanceler
	attackstring
	ppreduce
	setgravity BattleScript_ButItFailed
	attackanimation
	waitanimation

BattleScript_EffectGravitySuccess::
	EscribeTextoCombate "Gravity intensified!"
	waitmessage PAUSA_LARGA
	selectfirstvalidtarget

BattleScript_GravityLoop:
	movevaluescleanup
	jumpifstatus3 BS_TARGET, STATUS3_ON_AIR | STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS, BattleScript_GravityLoopDrop
	goto BattleScript_GravityLoopEnd

BattleScript_GravityLoopDrop:
	bringdownairbornebattler BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} can't stay airborne because of gravity!"
	waitmessage PAUSA_LARGA

BattleScript_GravityLoopEnd:
	moveendto MOVEEND_NEXT_TARGET
	jumpifnexttargetvalid BattleScript_GravityLoop
	end

BattleScript_EffectRoost::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
	setroost
	goto BattleScript_PresentHealTarget

BattleScript_EffectCaptivate::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, TRUE
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	jumpifoppositegenders BattleScript_CaptivateCheckAcc
	goto BattleScript_FailedFromAtkString

BattleScript_CaptivateCheckAcc:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_StatDownFromAttackString

BattleScript_EffectHitEscape::
	call BattleScript_EffectHit_Ret
	jumpifmovehadnoeffect BattleScript_MoveEnd
	tryfaintmon BS_TARGET
	moveendto MOVEEND_ATTACKER_VISIBLE
	moveendfrom MOVEEND_TARGET_VISIBLE
	jumpifbattleend BattleScript_HitEscapeEnd
	jumpifbyte COMPARACION_DESIGUAL, gBattleOutcome, 0, BattleScript_HitEscapeEnd
	goto BattleScript_MoveSwitch

BattleScript_HitEscapeEnd:
	end

BattleScript_EffectHit::
	attackcanceler

BattleScript_HitFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE

BattleScript_HitFromAtkString::
	attackstring
	ppreduce

BattleScript_HitFromCritCalc::
	critcalc
	damagecalc
	adjustdamage

BattleScript_HitFromAtkAnimation::
	call BattleScript_Hit_RetFromAtkAnimation

BattleScript_MoveEnd::
	moveendall
	end

BattleScript_EffectHit_Ret::
	attackcanceler

BattleScript_EffectHit_RetFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce

BattleScript_EffectHit_RetFromCritCalc::
	critcalc
	damagecalc
	adjustdamage

BattleScript_Hit_RetFromAtkAnimation::
	attackanimation
	waitanimation
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
	setadditionaleffects
	return

BattleScript_MakeMoveMissed::
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED

BattleScript_PrintMoveMissed::
	attackstring
	ppreduce

BattleScript_MoveMissedPause::
	pause PAUSA_CORTA

BattleScript_MoveMissed::
	HazSonidoEfectividad
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectDarkVoid::
BattleScript_EffectSleep::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_AlreadyAsleep
	jumpifuproarwakes BattleScript_CantMakeAsleep
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_InsomniaProtects
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_InsomniaProtects
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_SLEEP
	goto BattleScript_MoveEnd

BattleScript_AbilityProtectsDoesntAffectRet::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage PAUSA_LARGA
	return

BattleScript_AbilityProtectsDoesntAffect:
	call BattleScript_AbilityProtectsDoesntAffectRet
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_InsomniaProtects:
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} stayed awake using its {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	pause PAUSA_CORTA
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} ya está durmiendo!"
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_WasntAffected::
	pause PAUSA_CORTA
	printstring STRINGID_PKMNWASNTAFFECTED
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause PAUSA_CORTA
	printfromtable gUproarAwakeStringIds
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_EffectAbsorb::
	call BattleScript_EffectHit_Ret
	setdrainedhp
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_AbsorbLiquidOoze
	setword gMensajeBatalla, B_MSG_ABSORB
	goto BattleScript_AbsorbUpdateHp

BattleScript_AbsorbLiquidOoze::
	call BattleScript_AbilityPopUpTarget
	manipulatedamage DMG_CHANGE_SIGN
	setword gMensajeBatalla, B_MSG_ABSORB_OOZE

BattleScript_AbsorbUpdateHp::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_AbsorbTryFainting
	printfromtable gAbsorbDrainStringIds
	waitmessage PAUSA_LARGA

BattleScript_AbsorbTryFainting::
	tryfaintmon BS_ATTACKER

BattleScript_EffectExplosion::
	attackcanceler
	attackstring
	ppreduce
	tryexplosion
	setatkhptozero
	waitstate
	jumpiffainted BS_TARGET, TRUE, BattleScript_MoveEnd
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_FaintAttackerForExplosion::
	tryfaintmon BS_ATTACKER
	return

BattleScript_MaxHp50Recoil::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	return

BattleScript_EffectDreamEater::
	attackcanceler
	jumpifsubstituteblocks BattleScript_DreamEaterNoEffect
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_DreamEaterWorked
BattleScript_DreamEaterNoEffect:
	attackstring
	ppreduce
	waitmessage PAUSA_LARGA
	goto BattleScript_WasntAffected
BattleScript_DreamEaterWorked:
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
	setdrainedhp
	manipulatedamage DMG_BIG_ROOT
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_DreamEaterTryFaintEnd
	printstring STRINGID_PKMNENERGYDRAINED
	waitmessage PAUSA_LARGA

BattleScript_DreamEaterTryFaintEnd:
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp::
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp::
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp::
	setstatchanger ESTADISTICA_PRECISION, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp::
	setstatchanger ESTADISTICA_EVASION, 1, FALSE

BattleScript_EffectStatUp::
	attackcanceler

BattleScript_EffectStatUpAfterAtkCanceler::
	attackstring
	ppreduce
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_StatUpEnd
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpAttackAnim
	pause PAUSA_CORTA
	goto BattleScript_StatUpPrintString

BattleScript_StatUpAttackAnim::
	attackanimation
	waitanimation

BattleScript_StatUpDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_StatUpPrintString::
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_StatUpEnd::
	goto BattleScript_MoveEnd

BattleScript_StatUp::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_StatUpMsg::
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectAttackDown::
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown::
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown::
	setstatchanger ESTADISTICA_PRECISION, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown::
	setstatchanger ESTADISTICA_EVASION, 1, TRUE
BattleScript_EffectStatDown:
	attackcanceler
	jumpifsubstituteblocks BattleScript_FailedFromAtkString
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_StatDownFromAttackString:
	attackstring
	ppreduce
BattleScript_EffectStatDownFromStatBuffChange:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StatDownEnd
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_StatDownDoAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_StatDownEnd
	pause PAUSA_CORTA
	goto BattleScript_StatDownPrintString
BattleScript_StatDownDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	bicword gHitMarker, HITMARKER_DISABLE_ANIMATION
BattleScript_StatDownPrintString::
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
BattleScript_StatDownEnd::
	goto BattleScript_MoveEnd

BattleScript_MirrorArmorReflect::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	jumpifsubstituteblocks BattleScript_AbilityNoSpecificStatLoss

BattleScript_MirrorArmorReflectStatLoss:
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_MIRROR_ARMOR | STAT_CHANGE_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_MirrorArmorReflectEnd
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_MirrorArmorReflectAnim
	goto BattleScript_MirrorArmorReflectWontFall

BattleScript_MirrorArmorReflectAnim:
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_MirrorArmorReflectPrintString:
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_MirrorArmorReflectEnd:
	return

BattleScript_MirrorArmorReflectWontFall:
	copybyte gBattlerTarget, gBattlerAttacker   @ STRINGID_STATSWONTDECREASE uses target
	goto BattleScript_MirrorArmorReflectPrintString

@ gBattlerTarget is battler with Mirror Armor
BattleScript_MirrorArmorReflectStickyWeb:
	call BattleScript_AbilityPopUp
	setattackertostickywebuser
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_StickyWebOnSwitchInEnd   @ Sticky web user not on field -> no stat loss
	call BattleScript_MirrorArmorReflectStatLoss
	goto BattleScript_StickyWebOnSwitchInEnd

BattleScript_StatDown::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_EffectHaze::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	normalisebuffs
	EscribeTextoCombate "All stat changes were eliminated!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRoar::
	attackcanceler
	attackstring
	ppreduce
	jumpifroarfails BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_GUARD_DOG, BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	forcerandomswitch BattleScript_ButItFailed

BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage PAUSA_LARGA
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	EscribeTextoCombate "¡Golpeó {B_BUFF1} veces!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ScaleShot::
	call BattleScript_MultiHitPrintStrings
	goto BattleScript_DefDownSpeedUp

BattleScript_EffectConversion::
	attackcanceler
	attackstring
	ppreduce
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRestoreHp::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
BattleScript_RestoreHp:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} regained health!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectToxic::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON | STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_TOXIC
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned::
	pause PAUSA_LARGA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} ya está envenenado."
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected::
	copybyte gEffectBattler, gBattlerTarget
	call BattleScript_AbilityPopUp
	setword gMensajeBatalla, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PSNPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectAuroraVeil::
	attackcanceler
	attackstring
	ppreduce
	setauroraveil BS_ATTACKER
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectLightScreen::
	attackcanceler
	attackstring
	ppreduce
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectRest::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifuproarwakes BattleScript_RestCantSleep
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_InsomniaProtects
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_InsomniaProtects
	trysetrest BattleScript_AlreadyAtFullHp
	pause PAUSA_CORTA
	printfromtable gRestUsedStringIds
	waitmessage PAUSA_LARGA
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_PresentHealTarget

BattleScript_RestCantSleep::
	pause PAUSA_LARGA
	printfromtable gUproarAwakeStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep::
	pause PAUSA_CORTA
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} ya está durmiendo!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRecoilIfMiss::
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
.if B_CRASH_IF_TARGET_IMMUNE >= GEN_4
	typecalc
	jumpifhalfword COMPARACION_BITS_COMUNES, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveMissedDoDamage
.endif
	goto BattleScript_HitFromAtkString
BattleScript_MoveMissedDoDamage::
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_PrintMoveMissed
	attackstring
	ppreduce
	pause PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
.if B_CRASH_IF_TARGET_IMMUNE < GEN_4
	jumpifhalfword COMPARACION_BITS_COMUNES, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
.endif
	moveendcase MOVEEND_PROTECT_LIKE_EFFECT @ Spiky Shield's damage happens before recoil.
	jumpifhasnohp BS_ATTACKER, BattleScript_MoveEnd
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} kept going and crashed!"
	waitmessage PAUSA_LARGA
	damagecalc
	typecalc
	adjustdamage
.if B_CRASH_IF_TARGET_IMMUNE == GEN_4
	manipulatedamage DMG_RECOIL_FROM_IMMUNE
.else
	manipulatedamage DMG_RECOIL_FROM_MISS
.endif
.if B_CRASH_IF_TARGET_IMMUNE >= GEN_4
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
.else
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
.endif
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
.if B_CRASH_IF_TARGET_IMMUNE >= GEN_4
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
.else
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED
.endif
	goto BattleScript_MoveEnd

BattleScript_EffectMist::
	attackcanceler
	attackstring
	ppreduce
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectConfuse::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_CONFUSION
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AlreadyConfused::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} is already confused!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp2::
	setstatchanger ESTADISTICA_ATAQUE, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp2::
	setstatchanger ESTADISTICA_DEFENSA, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp3::
	setstatchanger ESTADISTICA_DEFENSA, 3, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp2::
	setstatchanger ESTADISTICA_VELOCIDAD, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp2::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp3::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 3, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp2::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAccuracyUp2::
	setstatchanger ESTADISTICA_PRECISION, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp2::
	setstatchanger ESTADISTICA_EVASION, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectAttackDown2::
	setstatchanger ESTADISTICA_ATAQUE, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown2::
	setstatchanger ESTADISTICA_DEFENSA, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown2::
	setstatchanger ESTADISTICA_VELOCIDAD, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown2::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialAttackDown2::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown2::
	setstatchanger ESTADISTICA_PRECISION, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown2::
	setstatchanger ESTADISTICA_EVASION, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectReflect::
	attackcanceler
	attackstring
	ppreduce
	setreflect

BattleScript_PrintReflectLightScreenSafeguardString::
	attackanimation
	waitanimation

BattleScript_EffectAuroraVeilSuccess::
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPoison::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	trypoisontype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_POISON
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectParalyze::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_LIMBER, BattleScript_LimberProtected
	jumpifsubstituteblocks BattleScript_ButItFailed
	typecalc
	jumpifmovehadnoeffect BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_AlreadyParalyzed
	tryparalyzetype BS_ATTACKER, BS_TARGET, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	bichalfword gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_PARALYSIS
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_VoltAbsorbHeal:
	copybyte gBattlerAbility, gBattlerTarget
	tryhealquarterhealth BS_TARGET BattleScript_MonMadeMoveUseless @ Check if max hp
	goto BattleScript_MoveHPDrain

BattleScript_AlreadyParalyzed:
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} is already paralyzed!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_LimberProtected::
	copybyte gEffectBattler, gBattlerTarget
	setword gMensajeBatalla, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_PRLZPrevention
	goto BattleScript_MoveEnd

BattleScript_PowerHerbActivation:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} became fully charged due to its {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
	return

BattleScript_EffectTwoTurnsAttack::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword COMPARACION_BITS_COMUNES, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	tryfiretwoturnmovewithoutcharging BS_ATTACKER, BattleScript_EffectHit @ e.g. Solar Beam
	call BattleScript_FirstChargingTurn
	tryfiretwoturnmoveaftercharging BS_ATTACKER, BattleScript_TwoTurnMovesSecondTurn @ e.g. Electro Shot
	jumpifholdeffect BS_ATTACKER, HOLD_EFFECT_POWER_HERB, BattleScript_TwoTurnMovesSecondPowerHerbActivates
	goto BattleScript_MoveEnd

BattleScript_FirstChargingTurn::
	attackcanceler
@ before Gen 5, charge moves did not print an attack string on the charge turn
.if B_UPDATED_MOVE_DATA >= GEN_5
	attackstring
	waitmessage PAUSA_LARGA
.endif
	ppreduce

BattleScript_TwoTurnMovesSecondPowerHerbActivates:
	call BattleScript_PowerHerbActivation
BattleScript_FromTwoTurnMovesSecondTurnRet:
	call BattleScript_TwoTurnMovesSecondTurnRet
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
@ before Gen 5, charge moves did not print an attack string on the charge turn
.if B_UPDATED_MOVE_DATA < GEN_5
	attackstring
.endif
	goto BattleScript_HitFromCritCalc

BattleScript_TwoTurnMovesSecondTurn::
	attackcanceler
	call BattleScript_TwoTurnMovesSecondTurnRet
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	goto BattleScript_HitFromAccCheck

BattleScript_TwoTurnMovesSecondTurnRet:
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_CHARGING
	clearsemiinvulnerablebit @ only for moves with EFFECT_SEMI_INVULNERABLE
	return

BattleScript_EffectSubstitute::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	setsubstitute
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_SUBSTITUTE_FAILED, BattleScript_SubstituteString
	orword gHitMarker, HITMARKER_PASSIVE_DAMAGE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER

BattleScript_SubstituteString::
	pause PAUSA_CORTA
	printfromtable gSubstituteUsedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AlreadyHasSubstitute::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} already has a SUBSTITUTE!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_MoveUsedMustRecharge::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} must recharge!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRage::
	attackcanceler
	accuracycheck BattleScript_RageMiss, ACC_CURR_MOVE
	seteffectprimary MOVE_EFFECT_RAGE
	goto BattleScript_HitFromAtkString

BattleScript_RageMiss::
	clearstatusfromeffect BS_ATTACKER, MOVE_EFFECT_RAGE
	goto BattleScript_PrintMoveMissed

BattleScript_EffectLeechSeed::
	attackcanceler
	attackstring
	pause PAUSA_CORTA
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_DoLeechSeed, ACC_CURR_MOVE

BattleScript_DoLeechSeed::
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectDisable::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectEncore::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} got an ENCORE!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSnore::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SnoreIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SnoreIsAsleep::
	jumpifhalfword COMPARACION_IGUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoSnore
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is fast asleep."
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER

BattleScript_DoSnore::
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectConversion2::
	attackcanceler
	attackstring
	ppreduce
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	setalwayshitflag
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} took aim at {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSleepTalk::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SleepTalkIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SleepTalkIsAsleep::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is fast asleep."
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	attackstring
	ppreduce
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	trychoosesleeptalkmove BattleScript_SleepTalkUsingMove
	pause PAUSA_LARGA
	goto BattleScript_ButItFailed

BattleScript_SleepTalkUsingMove::
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove TRUE

BattleScript_EffectDestinyBond::
	attackcanceler
	attackstring
	ppreduce
	setdestinybond
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is trying to take its foe with it!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectEerieSpell::
	call BattleScript_EffectHit_Ret
	tryfaintmon BS_TARGET
	eeriespellppreduce BattleScript_MoveEnd
	EscribeTextoCombate "Reduced {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} by {B_BUFF2}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell::
	attackcanceler
	attackstring
	ppreduce
	healpartystatus
	waitstate
	attackanimation
	waitanimation
	printfromtable gPartyStatusHealStringIds
	waitmessage PAUSA_LARGA
	jumpifnotmove MOVE_HEAL_BELL, BattleScript_PartyHealEnd
	jumpifword COMPARACION_BITS_DISTINTOS, gMensajeBatalla, B_MSG_BELL_SOUNDPROOF_ATTACKER, BattleScript_CheckHealBellMon2Unaffected
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} blocks {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA

BattleScript_CheckHealBellMon2Unaffected::
	jumpifword COMPARACION_BITS_DISTINTOS, gMensajeBatalla, B_MSG_BELL_SOUNDPROOF_PARTNER, BattleScript_PartyHealEnd
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} blocks {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA

BattleScript_PartyHealEnd::
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectMeanLook::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpiftype BS_TARGET, TIPO_FANTASMA, BattleScript_ButItFailed
	jumpifability BS_TARGET, ABILITY_HUIDIZO, BattleScript_ButItFailed
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_PREVENT_ESCAPE
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed

BattleScript_NightmareWorked::
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_NIGHTMARE
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} fell into a NIGHTMARE!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectMinimize::
	attackcanceler
	setminimize
.if B_MINIMIZE_EVASION >= GEN_5
	setstatchanger ESTADISTICA_EVASION, 2, FALSE
.else
	setstatchanger ESTADISTICA_EVASION, 1, FALSE
.endif
	goto BattleScript_EffectStatUpAfterAtkCanceler

BattleScript_EffectCurse::
	jumpiftype BS_ATTACKER, TIPO_FANTASMA, BattleScript_GhostCurse
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MAYOR, ESTADISTICA_VELOCIDAD, ESTADISTICA_MENOS_6, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, COMPARACION_DESIGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_ButItFailed

BattleScript_CurseTrySpeed::
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	setstatchanger ESTADISTICA_VELOCIDAD, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryAttack
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_CurseTryAttack::
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseTryDefense
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CurseTryDefense::
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CurseEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CurseEnd::
	goto BattleScript_MoveEnd

BattleScript_GhostCurse::
	jumpifbytenotequal gBattlerAttacker, gBattlerTarget, BattleScript_DoGhostCurse
	getmovetarget BS_ATTACKER

BattleScript_DoGhostCurse::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	cursetarget BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	setbyte sB_ANIM_TURN, 0
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} cut its own HP and laid a CURSE on {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectMatBlock::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	goto BattleScript_ProtectLikeAtkString

BattleScript_EffectProtect::
	attackcanceler
BattleScript_ProtectLikeAtkString:
	attackstring
	ppreduce
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes::
	attackcanceler
	trysetspikes BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectForesight::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifstatus2 BS_TARGET, STATUS2_FORESIGHT, BattleScript_ButItFailed
	setforesight

BattleScript_IdentifiedFoe:
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} identified {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong::
	attackcanceler
	attackstring
	ppreduce
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "All affected POKéMON will faint in three turns!"
	waitmessage PAUSA_LARGA
	setbyte gBattlerTarget, 0

BattleScript_PerishSongLoop::
	jumpifblockedbysoundproof BS_TARGET, BattleScript_PerishSongBlocked
	jumpifpranksterblocked BS_TARGET, BattleScript_PerishSongNotAffected

BattleScript_PerishSongLoopIncrement::
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_PerishSongLoop
	goto BattleScript_MoveEnd

BattleScript_PerishSongBlocked::
	copybyte sBATTLER, gBattlerTarget
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} blocks {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_PerishSongLoopIncrement

BattleScript_PerishSongNotAffected:
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage PAUSA_LARGA
	goto BattleScript_PerishSongLoopIncrement

BattleScript_EffectSandstorm::
	attackcanceler
	attackstring
	ppreduce
	setfieldweather ENUM_WEATHER_SANDSTORM
	goto BattleScript_MoveWeatherChange

BattleScript_EffectRollout::
	attackcanceler
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_RolloutCheckAccuracy
	ppreduce
BattleScript_RolloutCheckAccuracy::
	accuracycheck BattleScript_RolloutHit, ACC_CURR_MOVE
BattleScript_RolloutHit::
	typecalc
	handlerollout
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSwagger::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed ESTADISTICA_ATAQUE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger ESTADISTICA_ATAQUE, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_SwaggerTryConfuse
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_SwaggerTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
BattleScript_SwaggerTryConfuse:
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	seteffectprimary MOVE_EFFECT_CONFUSION
	goto BattleScript_MoveEnd

BattleScript_EffectFuryCutter::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_FuryCutterHit, ACC_CURR_MOVE
BattleScript_FuryCutterHit:
	handlefurycutter
	critcalc
	damagecalc
	jumpifmovehadnoeffect BattleScript_FuryCutterHit
	adjustdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_TryDestinyKnotTarget:
	jumpifnoholdeffect BS_ATTACKER, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotTargetRet
	infatuatewithbattler BS_TARGET, BS_ATTACKER
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	status2animation BS_TARGET, STATUS2_INFATUATION
	waitanimation
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} fell in love because of the {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA

BattleScript_TryDestinyKnotTargetRet:
	return

BattleScript_TryDestinyKnotAttacker:
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_DESTINY_KNOT, BattleScript_TryDestinyKnotAttackerRet
	infatuatewithbattler BS_ATTACKER, BS_TARGET
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	waitanimation
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} fell in love because of the {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA

BattleScript_TryDestinyKnotAttackerRet:
	return

BattleScript_EffectAttract::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage PAUSA_LARGA
	call BattleScript_TryDestinyKnotAttacker
	goto BattleScript_MoveEnd

BattleScript_EffectPresent::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	presentdamagecalculation

BattleScript_EffectSafeguard::
	attackcanceler
	attackstring
	ppreduce
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectMagnitude::
	jumpifword COMPARACION_BITS_COMUNES, gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT, BattleScript_EffectMagnitudeTarget
	attackcanceler
	attackstring
	ppreduce
	magnitudedamagecalculation
	pause PAUSA_CORTA
	EscribeTextoCombate "MAGNITUDE {B_BUFF1}!"
	waitmessage PAUSA_LARGA

BattleScript_EffectMagnitudeTarget:
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectRelevo::
	attackcanceler
	attackstring
	ppreduce
	jumpifcantswitch SWITCH_IGNORE_ESCAPE_PREVENTION | BS_ATTACKER, BattleScript_ButItFailed
	attackanimation
	waitanimation
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER, FALSE
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, TRUE
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectMorningSun::
BattleScript_EffectSynthesis::
BattleScript_EffectMoonlight::
BattleScript_EffectShoreUp::
	attackcanceler
	attackstring
	ppreduce
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_PresentHealTarget

BattleScript_EffectRainDance::
	attackcanceler
	attackstring
	ppreduce
	setfieldweather ENUM_WEATHER_RAIN
BattleScript_MoveWeatherChange::
	attackanimation
	waitanimation
	call BattleScript_MoveWeatherChangeRet
	goto BattleScript_MoveEnd

BattleScript_MoveWeatherChangeRet::
	printfromtable gMoveWeatherChangeStringIds
	waitmessage PAUSA_LARGA
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_EffectSunnyDay::
	attackcanceler
	attackstring
	ppreduce
	setfieldweather ENUM_WEATHER_SUN
	goto BattleScript_MoveWeatherChange

BattleScript_EffectBellyDrum::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_ButItFailed
	halvehp BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	playstatchangeanimation BS_ATTACKER, BIT_ATK, STAT_CHANGE_BY_TWO
	setstatchanger ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_MoveEnd
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} cut its own HP and maximized ATTACK!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectPsychUp::
	attackcanceler
	attackstring
	ppreduce
	copyfoestats
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} copied {B_DEF_NAME_WITH_PREFIX}'s stat changes!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectFutureSight::
	attackcanceler
	attackstring
	ppreduce
	trysetfutureattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

ScriptBatalla_EfectoAtaqueEquipo::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	intentaataqueequipo
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectDefenseCurl::
	attackcanceler
	attackstring
	ppreduce
	setdefensecurlbit
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DefenseCurlDoStatUpAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_StatUpPrintString
	attackanimation
	waitanimation
BattleScript_DefenseCurlDoStatUpAnim::
	goto BattleScript_StatUpDoAnim

BattleScript_EffectSoftboiled::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
BattleScript_PresentHealTarget::
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} regained health!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp::
	pause PAUSA_CORTA
	printstring STRINGID_PKMNHPFULL
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectFirstTurnOnly::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	goto BattleScript_EffectHit

BattleScript_FailedFromAtkCanceler::
	attackcanceler
BattleScript_FailedFromAtkString::
	attackstring
BattleScript_FailedFromPpReduce::
	ppreduce
BattleScript_ButItFailed::
	pause PAUSA_CORTA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd
BattleScript_RestoreAttackerButItFailed:
	restoreattacker
	goto BattleScript_ButItFailed

BattleScript_NotAffected::
	pause PAUSA_CORTA
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_NotAffectedAbilityPopUp::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUpTarget
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectUproar::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_UproarHit
	ppreduce
BattleScript_UproarHit::
	goto BattleScript_HitFromCritCalc

BattleScript_EffectStockpile::
	attackcanceler
	attackstring
	ppreduce
	stockpile 0
	attackanimation
	waitanimation
	printfromtable gStockpileUsedStringIds
	waitmessage PAUSA_LARGA
	.if B_STOCKPILE_RAISES_DEFS < GEN_4
	goto BattleScript_EffectStockpileEnd
	.endif
	jumpifmovehadnoeffect BattleScript_EffectStockpileEnd
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_EffectStockpileDef
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_EffectStockpileEnd
BattleScript_EffectStockpileDef:
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileSpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileSpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
BattleScript_EffectStockpileSpDef::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectStockpileEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectStockpileEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
BattleScript_EffectStockpileEnd:
	stockpile 1
	goto BattleScript_MoveEnd

BattleScript_MoveEffectStockpileWoreOff::
	.if B_STOCKPILE_RAISES_DEFS >= GEN_4
	dostockpilestatchangeswearoff BS_ATTACKER, BattleScript_StockpileStatChangeDown
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s stockpiled effect wore off!"
	waitmessage PAUSA_CORTA
	.endif
	return

BattleScript_StockpileStatChangeDown:
	statbuffchange MOVE_EFFECT_AFFECTS_USER, BattleScript_StockpileStatChangeDown_Ret
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_StockpileStatChangeDown_Ret:
	return

BattleScript_EffectSpitUp::
	attackcanceler
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, TEXTO_COMBATE_PROTECCION, BattleScript_SpitUpFailProtect
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	damagecalc
	adjustdamage
	stockpiletobasedamage BattleScript_SpitUpFail
	goto BattleScript_HitFromAtkAnimation

BattleScript_SpitUpFail::
	checkparentalbondcounter 2, BattleScript_SpitUpEnd
	pause PAUSA_CORTA
	EscribeTextoCombate "But it failed to spit up a thing!"
	waitmessage PAUSA_LARGA

BattleScript_SpitUpEnd:
	goto BattleScript_MoveEnd

BattleScript_SpitUpFailProtect::
	attackstring
	ppreduce
	pause PAUSA_LARGA
	stockpiletobasedamage BattleScript_SpitUpFail
	resultmessage
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSwallow::
	attackcanceler
	attackstring
	ppreduce
	stockpiletohpheal BattleScript_SwallowFail
	goto BattleScript_PresentHealTarget

BattleScript_SwallowFail::
	pause PAUSA_CORTA
	printfromtable gSwallowFailStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectHail::
	attackcanceler
	attackstring
	ppreduce
	setfieldweather ENUM_WEATHER_HAIL
	goto BattleScript_MoveWeatherChange

BattleScript_EffectTorment::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectFlatter::
	attackcanceler
	jumpifsubstituteblocks BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed ESTADISTICA_ATAQUE_ESPECIAL, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_FlatterTryConfuse
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_FlatterTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_FlatterTryConfuse::
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsafeguard BattleScript_SafeguardProtected
	seteffectprimary MOVE_EFFECT_CONFUSION
	goto BattleScript_MoveEnd

BattleScript_EffectWillOWisp::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_BURN, BattleScript_AlreadyBurned
	jumpiftype BS_TARGET, TIPO_FUEGO, BattleScript_NotAffected
	jumpifability BS_TARGET, ABILITY_WATER_VEIL, BattleScript_AbilityPreventsBurn
	jumpifability BS_TARGET, ABILITY_TIERRA_HUMEDA, BattleScript_AbilityPreventsBurn
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsafeguard BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary MOVE_EFFECT_BURN
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsBurn::
	call BattleScript_AbilityPopUp
	copybyte gEffectBattler, gBattlerTarget
	setword gMensajeBatalla, B_MSG_ABILITY_PREVENTS_MOVE_STATUS
	call BattleScript_BRNPrevention
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} already has a burn."
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectFocusPunch::
	attackcanceler
	jumpifnodamage BattleScript_HitFromAccCheck
	ppreduce
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} lost its focus and couldn't move!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectFollowMe::
	attackcanceler
	attackstring
	ppreduce
	.if B_UPDATED_MOVE_DATA >= GEN_8
	jumpifnotbattletype COMBATE_ENTRENADOR, BattleScript_ButItFailed
	.endif
	setforcedtarget
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} became the center of attention!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectCharge::
	attackcanceler
	attackstring
	ppreduce
	setcharge BS_ATTACKER
	attackanimation
	waitanimation
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_EffectChargeString
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_EffectChargeString
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_EffectChargeString:
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} began charging power!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} fell for the Taunt!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectTrick::
	attackcanceler
	attackstring
	ppreduce
	jumpifsubstituteblocks BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryswapitems BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} cambió objetos con el rival!"
	waitmessage PAUSA_LARGA
	printfromtable gItemSwapStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectWish::
	attackcanceler
	attackstring
	ppreduce
	trywish 0, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd


BattleScript_EffectIngrain::
	attackcanceler
	attackstring
	ppreduce
	setuserstatus3 STATUS3_ROOTED, BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} planted its roots!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectMagicCoat::
	attackcanceler
	trysetmagiccoat BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} shrouded itself in {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle::
	attackcanceler
	attackstring
	ppreduce
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} found one {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectBrickBreak::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	EliminaPantallas
	critcalc
	damagecalc
	adjustdamage
	jumpifbyte COMPARACION_IGUAL, sB_ANIM_TURN, 0, BattleScript_BrickBreakAnim
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE

BattleScript_BrickBreakAnim::
	attackanimation
	waitanimation
	jumpifbyte COMPARACION_MENOR, sB_ANIM_TURN, 2, BattleScript_BrickBreakDoHit
	EscribeTextoCombate "The wall shattered!"
	waitmessage PAUSA_LARGA

BattleScript_BrickBreakDoHit::
	typecalc
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
	setadditionaleffects
	tryfaintmon BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_PrintBattlerAbilityMadeIneffective::
	copybyte sBATTLER, gBattlerAbility

BattleScript_PrintAbilityMadeIneffective::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} made it ineffective!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSkillSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
	jumpiftargetally BattleScript_EffectSkillSwap_AfterAbilityPopUp
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUpOverwriteThenNormal
	copybyte gBattlerAbility, gBattlerTarget
	copyhword sABILITY_OVERWRITE, gLastUsedAbility
	call BattleScript_AbilityPopUpOverwriteThenNormal

BattleScript_EffectSkillSwap_AfterAbilityPopUp:
	recordability BS_ATTACKER
	recordability BS_TARGET
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} swapped abilities with its opponent!"
	waitmessage PAUSA_LARGA
.if B_SKILL_SWAP >= GEN_4
	switchinabilities BS_ATTACKER
	switchinabilities BS_TARGET
.endif
	goto BattleScript_MoveEnd

BattleScript_EffectImprison::
	attackcanceler
	attackstring
	ppreduce
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} sealed the opponent's move(s)!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh::
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalysedorpoisoned BattleScript_ButItFailed
	attackanimation
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s status returned to normal!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch::
	attackcanceler
	trysetsnatch BattleScript_FailedFromAtkString
	attackstring
	ppreduce
	attackanimation
	waitanimation
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} waits for a target to make a move!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectRecoilHP25::
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectTickle::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, COMPARACION_MAYOR, ESTADISTICA_ATAQUE, ESTADISTICA_MENOS_6, BattleScript_TickleDoMoveAnim
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_DEFENSA, ESTADISTICA_MENOS_6, BattleScript_CantLowerMultipleStats

BattleScript_TickleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_TARGET, BIT_ATK, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleTryLowerDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleTryLowerDef
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_TickleTryLowerDef::
	playstatchangeanimation BS_TARGET, BIT_DEF, STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_TickleEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_TickleEnd
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_TickleEnd::
	goto BattleScript_MoveEnd

BattleScript_CantLowerMultipleStats::
	pause PAUSA_CORTA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTDECREASE2
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectCosmicPower::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_CosmicPowerDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_CosmicPowerDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerTrySpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CosmicPowerTrySpDef::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CosmicPowerEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CosmicPowerEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CosmicPowerEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectBulkUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_BulkUpDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_BulkUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpTryDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpTryDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_BulkUpTryDef::
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_BulkUpEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_BulkUpEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_BulkUpEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCalmMind::
	attackcanceler
	attackstring
	ppreduce

BattleScript_CalmMindTryToRaiseStats::
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CalmMindDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_CalmMindDoMoveAnim::
	attackanimation
	waitanimation

BattleScript_CalmMindStatRaise::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindTrySpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CalmMindTrySpDef::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_CalmMindEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_CalmMindEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_CalmMindEnd::
	goto BattleScript_MoveEnd

BattleScript_CantRaiseMultipleStats::
	pause PAUSA_CORTA
	orhalfword gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDance::
	attackcanceler
	attackstring
	ppreduce

BattleScript_EffectDragonDanceFromStatUp::
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_DragonDanceDoMoveAnim
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_CantRaiseMultipleStats

BattleScript_DragonDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceTrySpeed
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DragonDanceTrySpeed::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_DragonDanceEnd
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DragonDanceEnd
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DragonDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_FaintAttacker::
	playfaintcry BS_ATTACKER
	pause PAUSA_LARGA
	dofaintanimation BS_ATTACKER
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} se debilitó!"
	cleareffectsonfaint BS_ATTACKER
	tryactivatesoulheart
	tryactivatereceiver BS_ATTACKER
	trytrainerslidefirstdownmsg BS_ATTACKER
	return

BattleScript_FaintTarget::
	playfaintcry BS_TARGET
	pause PAUSA_LARGA
	dofaintanimation BS_TARGET
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} cayó debilitado!"
	cleareffectsonfaint BS_TARGET
	tryactivatefellstinger BS_ATTACKER
	tryactivatesoulheart
	tryactivatereceiver BS_TARGET
	intentaactivarautoestima BS_ATTACKER
	tryactivatecarnivoro BS_ATTACKER
	tryactivatebeastboost BS_ATTACKER
	trytrainerslidefirstdownmsg BS_TARGET
	return

BattleScript_GiveExp::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end2

BattleScript_HandleFaintedMon::
	setbyte sSHIFT_SWITCHED, 0
	checkteamslost BattleScript_HandleFaintedMonMultiple
	jumpifbyte COMPARACION_DESIGUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype COMBATE_ENTRENADOR, BattleScript_FaintedMonTryChoose
	jumpifword COMPARACION_BITS_DISTINTOS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChoose
	EscribeTextoCombate "¿Quieres usar otro Pokémon?"
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte COMPARACION_IGUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChoose
	goto BattleScript_FaintedMonEnd

BattleScript_FaintedMonTryChoose:
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	goto BattleScript_FaintedMonSendOutNew

BattleScript_FaintedMonSendOutNew:
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	resetplayerfainted
	trytrainerslidelastonmsg BS_FAINTED
	jumpifbytenotequal sSHIFT_SWITCHED, sZero, BattleScript_FaintedMonShiftSwitched

BattleScript_FaintedMonSendOutNewEnd:
	switchineffects BS_FAINTED
	jumpifbattletype COMBATE_ENTRENADOR, BattleScript_FaintedMonEnd
	cancelallactions

BattleScript_FaintedMonEnd::
	end2

BattleScript_FaintedMonShiftSwitched:
	copybyte sSAVED_BATTLER, gBattlerTarget
	switchineffects BS_ATTACKER
	resetsentmonsvalue
	copybyte gBattlerTarget, sSAVED_BATTLER
	goto BattleScript_FaintedMonSendOutNewEnd

BattleScript_HandleFaintedMonMultiple::
	openpartyscreen BS_FAINTED_MULTIPLE_1, BattleScript_HandleFaintedMonMultipleStart

BattleScript_HandleFaintedMonMultipleStart::
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_FAINTED_MULTIPLE_2, BattleScript_HandleFaintedMonMultipleEnd
	switchhandleorder BS_FAINTED, 0

BattleScript_HandleFaintedMonLoop::
	switchhandleorder BS_FAINTED, 3 @ Revisar
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, FALSE
	waitstate
	switchineffects BS_FAINTED_MULTIPLE_1
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_HandleFaintedMonLoop

BattleScript_HandleFaintedMonMultipleEnd::
	switchineffects BS_FAINTED_MULTIPLE_2
	end2

BattleScript_LocalTrainerBattleWon::
	EscribeTextoCombate "¡Has vencido a {B_TRAINER_CLASS} {B_TRAINER_NAME}!"
	goto BattleScript_LocalBattleWonLoseTexts

BattleScript_LocalBattleWonLoseTexts::
	trainerslidein BS_OPPONENT
	waitstate
	EscribeTextoCombate "{B_TRAINER_LOSE_TEXT}"
	goto BattleScript_LocalBattleWonReward

BattleScript_LocalBattleWonReward::
	getmoneyreward
	EscribeTextoCombate "{B_PLAYER_NAME} got ¥{B_BUFF1} for winning!"
	waitmessage PAUSA_LARGA

BattleScript_PayDayMoney::
	givepaydaymoney
	end2

BattleScript_LocalBattleLost::
	goto BattleScript_LocalBattleLostPrintWhiteOut

BattleScript_LocalBattleLostPrintWhiteOut::
	jumpifbattletype COMBATE_ENTRENADOR, BattleScript_LocalBattleLostEnd
	EscribeTextoCombate "{B_PLAYER_NAME} is out of usable POKéMON!"
	waitmessage PAUSA_LARGA
	getmoneyreward
	EscribeTextoCombate "You panicked and dropped ¥{B_BUFF1}… You were overwhelmed by your defeat!{PAUSE_UNTIL_PRESS}"
	waitmessage PAUSA_LARGA
	end2

BattleScript_LocalBattleLostEnd::
	EscribeTextoCombate "{B_PLAYER_NAME} is out of usable POKéMON! Player lost against {B_TRAINER_CLASS} {B_TRAINER_NAME}!{PAUSE_UNTIL_PRESS}"
	waitmessage PAUSA_LARGA
	getmoneyreward
	EscribeTextoCombate "{B_PLAYER_NAME} paid ¥{B_BUFF1} as the prize money… … … … {B_PLAYER_NAME} whited out!{PAUSE_UNTIL_PRESS}"
	waitmessage PAUSA_LARGA
	end2

BattleScript_LocalBattleLostPrintTrainersWinText::
	jumpifnotbattletype COMBATE_ENTRENADOR, BattleScript_LocalBattleLostPrintWhiteOut
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
	trainerslidein BS_OPPONENT
	waitstate
	EscribeTextoCombate "{B_TRAINER_WIN_TEXT}"
	end2

BattleScript_GotAwaySafely::
	EscribeTextoCombate "{PLAY_SE SE_FLEE}¡Lograste huir!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_WildMonFled::
	EscribeTextoCombate "¡{PLAY_SE SE_FLEE}El {B_BUFF1} salvaje huyó!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_PrintCantRunFromTrainer::
	EscribeTextoCombate "No! There's no running from a TRAINER battle!"
	end2

BattleScript_PrintFullBox::
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch::
	hpthresholds2 BS_ATTACKER
	saveattacker
	printstring STRINGID_RETURNMON
	jumpifbattletype COMBATE_ENTRENADOR, BattleScript_PursuitSwitchDmgSetMultihit
	setmultihit 1
	goto BattleScript_PursuitSwitchDmgLoop

BattleScript_PursuitSwitchDmgSetMultihit::
	setmultihit 2

BattleScript_PursuitSwitchDmgLoop::
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	swapattackerwithtarget
	trysetdestinybondtohappen
	call BattleScript_PursuitDmgOnSwitchOut
	swapattackerwithtarget

BattleScript_DoSwitchOut::
	decrementmultihit BattleScript_PursuitSwitchDmgLoop
	switchoutabilities BS_ATTACKER
	waitstate
	restoreattacker
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, FALSE
	waitstate
	switchineffects BS_ATTACKER
	moveendcase MOVEEND_STATUS_IMMUNITY_ABILITIES
	end2

BattleScript_PursuitDmgOnSwitchOut::
	pause PAUSA_CORTA
	attackstring
	ppreduce
	critcalc
	damagecalc
	adjustdamage
	attackanimation
	waitanimation
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA
	resultmessage
	waitmessage PAUSA_LARGA
	tryfaintmon BS_TARGET
	moveendfromto MOVEEND_ABILITIES, MOVEEND_ATTACKER_INVISIBLE @ MOVEEND_CHOICE_MOVE has to be included
	jumpiffainted BS_TARGET, FALSE, BattleScript_PursuitDmgOnSwitchOutRet
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET

BattleScript_PursuitDmgOnSwitchOutRet:
	return

BattleScript_Pausex20::
	pause PAUSA_CORTA
	return

BattleScript_LevelUp::
	fanfare MUS_LEVEL_UP
	EscribeTextoCombate "¡{B_BUFF1} subió al nivel {B_BUFF2}!{WAIT_SE}"
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, TRUE
	goto BattleScript_AskToLearnMove

BattleScript_TryLearnMoveLoop::
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, FALSE

BattleScript_AskToLearnMove::
	buffermovetolearn
	printstring "{B_BUFF1} puede aprender {B_BUFF2}, pero ya conoce cuatro. ¿Cuál quieres que olvide?"
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_TryLearnMoveLoop

BattleScript_ForgotAndLearnedNewMove::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS

BattleScript_LearnedNewMove::
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage PAUSA_LARGA
	updatechoicemoveonlvlup BS_ATTACKER
	goto BattleScript_TryLearnMoveLoop

BattleScript_LearnMoveReturn::
	return

BattleScript_RainContinuesOrEnds::
	printfromtable gRainContinuesStringIds
	waitmessage PAUSA_LARGA
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_RAIN_STOPPED, BattleScript_RainContinuesOrEndsEnd
	playanimation BS_ATTACKER, B_ANIM_RAIN_CONTINUES

BattleScript_RainContinuesOrEndsEnd::
	call BattleScript_ActivateWeatherAbilities
	end2

BattleScript_DamagingWeatherContinues::
	printfromtable gSandStormHailSnowContinuesStringIds
	waitmessage PAUSA_LARGA
	playanimation_var BS_ATTACKER, sB_ANIM_ARG1
	setbyte gBattleCommunication, 0
	end2

BattleScript_DamagingWeather::
	printfromtable gSandStormHailDmgStringIds
	waitmessage PAUSA_LARGA
	HazSonidoEfectividad
	hitanimation BS_SCRIPTING
	goto BattleScript_DoTurnDmg

BattleScript_IceBodyHeal::
	call BattleScript_AbilityPopUpScripting
	playanimation BS_SCRIPTING, B_ANIM_SIMPLE_HEAL
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} healed it a little bit!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_SandStormHailSnowEnds::
	printfromtable gSandStormHailSnowEndStringIds
	waitmessage PAUSA_LARGA
	call BattleScript_ActivateWeatherAbilities
	end2

BattleScript_SunlightContinues::
	printstring STRINGID_SUNLIGHTSTRONG
	waitmessage PAUSA_LARGA
	playanimation BS_ATTACKER, B_ANIM_SUN_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end2

BattleScript_SunlightFaded::
	printstring STRINGID_SUNLIGHTFADED
	waitmessage PAUSA_LARGA
	call BattleScript_ActivateWeatherAbilities
	end2

BattleScript_FogContinues::
	printstring STRINGID_FOGISDEEP
	waitmessage PAUSA_LARGA
	playanimation BS_ATTACKER, B_ANIM_FOG_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end2

BattleScript_FogEnded_Ret::
	printstring STRINGID_FOGLIFTED
	waitmessage PAUSA_LARGA
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_FogEnded::
	call BattleScript_FogEnded_Ret
	end2

BattleScript_OverworldWeatherStarts::
	printfromtable gWeatherStartsStringIds
	waitmessage PAUSA_LARGA
	playanimation_var BS_BATTLER_0, sB_ANIM_ARG1
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_SideStatusWoreOff::
	EscribeTextoCombate "{B_ATK_PREFIX1}'s {B_BUFF1} wore off!",
	waitmessage PAUSA_LARGA
	end2

BattleScript_SideStatusWoreOffReturn::
	EscribeTextoCombate "{B_ATK_PREFIX1}'s {B_BUFF1} wore off!"
	waitmessage PAUSA_LARGA
	return

BattleScript_LuckyChantEnds::
	EscribeTextoCombate "{B_ATK_TEAM1} team's Lucky Chant wore off!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_TailwindEnds::
	EscribeTextoCombate "{B_ATK_TEAM1} team's Tailwind petered out!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_TrickRoomEnds::
	printstring STRINGID_TRICKROOMENDS
	waitmessage PAUSA_LARGA
	end2

BattleScript_WonderRoomEnds::
	printstring STRINGID_WONDERROOMENDS
	waitmessage PAUSA_LARGA
	end2

BattleScript_MagicRoomEnds::
	printstring STRINGID_MAGICROOMENDS
	waitmessage PAUSA_LARGA
	end2

BattleScript_GravityEnds::
	EscribeTextoCombate "Gravity returned to normal!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_SafeguardProtected::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s party is protected by Safeguard!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_SafeguardEnds::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_ATK_PREFIX3}'s party is no longer protected by Safeguard!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_LeechSeedTurnDrain::
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifability BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_LeechSeedTurnPrintLiquidOoze
	setword gMensajeBatalla, B_MSG_LEECH_SEED_DRAIN
	manipulatedamage DMG_BIG_ROOT
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_LeechSeedTurnPrintLiquidOoze::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setword gMensajeBatalla, B_MSG_LEECH_SEED_OOZE

BattleScript_LeechSeedTurnPrintAndUpdateHp::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gLeechSeedStringIds
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	tryfaintmon BS_TARGET
	end2

BattleScript_RoarSuccessSwitch::
	call BattleScript_RoarSuccessRet
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	switchinanim BS_TARGET, FALSE
	waitstate
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} was dragged out!"
	switchineffects BS_TARGET
	jumpifbyte COMPARACION_IGUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessSwitch_Ret
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	goto BattleScript_MoveEnd

BattleScript_RoarSuccessSwitch_Ret:
	swapattackerwithtarget  @ continuation of RedCardActivates
	restoretarget
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	return

BattleScript_RoarSuccessEndBattle::
	call BattleScript_RoarSuccessRet
	setbyte sSWITCH_CASE, B_SWITCH_NORMAL
	setoutcomeonteleport BS_ATTACKER
	finishaction

BattleScript_RoarSuccessRet:
	jumpifbyte COMPARACION_IGUAL, sSWITCH_CASE, B_SWITCH_HIT, BattleScript_RoarSuccessRet_Ret
	jumpifbyte COMPARACION_IGUAL, sSWITCH_CASE, B_SWITCH_RED_CARD, BattleScript_RoarSuccessRet_Ret
	attackanimation
	waitanimation
BattleScript_RoarSuccessRet_Ret:
	switchoutabilities BS_TARGET
	returntoball BS_TARGET, FALSE
	waitstate
	return

BattleScript_WeaknessPolicy::
	copybyte sBATTLER, gBattlerTarget
	jumpifstat BS_TARGET, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_WeaknessPolicyAtk
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_WeaknessPolicyEnd
BattleScript_WeaknessPolicyAtk:
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, STAT_CHANGE_BY_TWO
	setstatchanger ESTADISTICA_ATAQUE, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicySpAtk
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicySpAtk
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage PAUSA_LARGA
BattleScript_WeaknessPolicySpAtk:
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 2, FALSE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeaknessPolicyRemoveItem
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_WeaknessPolicyRemoveItem
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage PAUSA_LARGA
BattleScript_WeaknessPolicyRemoveItem:
	removeitem BS_TARGET
BattleScript_WeaknessPolicyEnd:
	return

BattleScript_TargetItemStatRaise::
	copybyte sBATTLER, gBattlerTarget
	statbuffchange 0, BattleScript_TargetItemStatRaiseRemoveItemRet
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_TargetItemStatRaiseRemoveItemRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage PAUSA_LARGA
	removeitem BS_TARGET
BattleScript_TargetItemStatRaiseRemoveItemRet:
	return

BattleScript_AttackerItemStatRaise::
	copybyte sBATTLER, gBattlerAttacker
	statbuffchange MOVE_EFFECT_AFFECTS_USER, BattleScript_AttackerItemStatRaiseRet
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, 2, BattleScript_AttackerItemStatRaiseRet
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
BattleScript_AttackerItemStatRaiseRet:
	return

BattleScript_MistProtected::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} is protected by MIST!"
	waitmessage PAUSA_LARGA
	return

BattleScript_RageIsBuilding::
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_RageIsBuildingEnd
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s RAGE is building!"
	waitmessage PAUSA_LARGA
BattleScript_RageIsBuildingEnd:
	return

BattleScript_MoveUsedIsDisabled::
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove::
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore::
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage PAUSA_LARGA
	end2

BattleScript_EncoredNoMore::
	printstring STRINGID_PKMNENCOREENDED
	waitmessage PAUSA_LARGA
	end2

BattleScript_DestinyBondTakesLife::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} took {B_ATK_NAME_WITH_PREFIX} with it!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	return

BattleScript_DmgHazardsOnAttacker::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_ATTACKER
	tryfaintmon_spikes BS_ATTACKER, BattleScript_DmgHazardsOnAttackerFainted
	return

BattleScript_DmgHazardsOnAttackerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_ATTACKER
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnTarget::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_TARGET
	tryfaintmon_spikes BS_TARGET, BattleScript_DmgHazardsOnTargetFainted
	return

BattleScript_DmgHazardsOnTargetFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnBattlerScripting::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_SCRIPTING
	tryfaintmon_spikes BS_SCRIPTING, BattleScript_DmgHazardsOnBattlerScriptingFainted
	return

BattleScript_DmgHazardsOnBattlerScriptingFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_SCRIPTING
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_DmgHazardsOnFaintedBattler::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_FAINTED
	datahpupdate BS_FAINTED
	call BattleScript_PrintHurtByDmgHazards
	tryfaintmon BS_FAINTED
	tryfaintmon_spikes BS_FAINTED, BattleScript_DmgHazardsOnFaintedBattlerFainted
	return

BattleScript_DmgHazardsOnFaintedBattlerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_FAINTED
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_PrintHurtByDmgHazards::
	printfromtable gDmgHazardsStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_ToxicSpikesAbsorbed::
	EscribeTextoCombate "The poison spikes disappeared from around {B_DEF_TEAM2} team's feet!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ToxicSpikesPoisoned::
	EscribeTextoCombate "¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} fue envenenado por las púas tóxicas!"
	waitmessage PAUSA_LARGA
	statusanimation BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	waitstate
	return

BattleScript_StickyWebOnSwitchIn::
	savetarget
	saveattacker
	copybyte gBattlerTarget, sBATTLER
	setbyte sSTICKY_WEB_STAT_DROP, 1
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} was caught in a Sticky Web!"
	waitmessage PAUSA_LARGA
	jumpifability BS_TARGET, ABILITY_MIRROR_ARMOR, BattleScript_MirrorArmorReflectStickyWeb
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_StickyWebOnSwitchInEnd
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_StickyWebOnSwitchInStatAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_StickyWebOnSwitchInEnd
	pause PAUSA_CORTA
	goto BattleScript_StickyWebOnSwitchInPrintStatMsg

BattleScript_StickyWebOnSwitchInStatAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1

BattleScript_StickyWebOnSwitchInPrintStatMsg:
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_StickyWebOnSwitchInEnd:
	restoretarget
	restoreattacker
	setbyte sSTICKY_WEB_STAT_DROP, 0
	return

BattleScript_PerishSongTakesLife::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s PERISH count fell to {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	end2

BattleScript_WindPowerActivates::
	call BattleScript_AbilityPopUp
	setcharge BS_TARGET
	EscribeTextoCombate "Being hit by {B_CURRENT_MOVE} charged {B_DEF_NAME_WITH_PREFIX} with power!"
	waitmessage PAUSA_LARGA
	return

BattleScript_PunzonActivates::
	call BattleScript_AbilityPopUp
	pause PAUSA_CORTA
	settoxicspikes BattleScript_PunzonRet
	printstring STRINGID_SPIKESSCATTERED
	waitmessage PAUSA_LARGA

BattleScript_PunzonRet:
	copybyte sBATTLER, gBattlerTarget
	copybyte gBattlerTarget, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	return

BattleScript_PerishSongCountGoesDown::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s PERISH count fell to {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_AllStatsUp::
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_DEFENSA, ESTADISTICA_MAS_6, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, COMPARACION_MENOR, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_DEFENSA_ESPECIAL, ESTADISTICA_MAS_6, BattleScript_AllStatsUpRet

BattleScript_AllStatsUpAtk::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger ESTADISTICA_ATAQUE, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AllStatsUpDef::
	setstatchanger ESTADISTICA_DEFENSA, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpeed
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AllStatsUpSpeed::
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AllStatsUpSpAtk::
	setstatchanger ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpSpDef
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AllStatsUpSpDef::
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AllStatsUpRet
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_AllStatsUpRet::
	return

BattleScript_GiroRapidoAway::
	girorapidofree
	return

BattleScript_WrapFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} got free of {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	copybyte gBattlerTarget, sBATTLER
	return

BattleScript_LeechSeedFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} shed LEECH SEED!"
	waitmessage PAUSA_LARGA
	return

BattleScript_SpikesFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} blew away spikes!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ToxicSpikesFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} blew away Toxic Spikes!"
	waitmessage PAUSA_LARGA
	return

BattleScript_StickyWebFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} blew away Sticky Web!"
	waitmessage PAUSA_LARGA
	return

BattleScript_StealthRockFree::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} blew away Stealth Rock!"
	waitmessage PAUSA_LARGA
	return

BattleScript_SpikesDefog::
	EscribeTextoCombate "The spikes disappeared from the ground around {B_ATK_TEAM2} team!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ToxicSpikesDefog::
	EscribeTextoCombate "The poison spikes disappeared from the ground around {B_ATK_TEAM2} team!"
	waitmessage PAUSA_LARGA
	return

BattleScript_StickyWebDefog::
	EscribeTextoCombate "The sticky web has disappeared from the ground around {B_ATK_TEAM2} team!"
	waitmessage PAUSA_LARGA
	return

BattleScript_StealthRockDefog::
	EscribeTextoCombate "The pointed stones disappeared from around {B_ATK_TEAM2} team!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MonTookFutureAttack::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} took the {B_BUFF1} attack!"
	waitmessage PAUSA_LARGA
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_FUTURE_SIGHT, BattleScript_CheckDoomDesireMiss
	accuracycheck BattleScript_FutureAttackMiss, MOVE_FUTURE_SIGHT
	goto BattleScript_FutureAttackAnimate

BattleScript_CheckDoomDesireMiss::
	accuracycheck BattleScript_FutureAttackMiss, MOVE_DOOM_DESIRE

BattleScript_FutureAttackAnimate::
	critcalc
	damagecalc
	adjustdamage
	jumpifmovehadnoeffect BattleScript_DoFutureAttackResult
	jumpifword COMPARACION_DESIGUAL, gMensajeBatalla, B_MSG_FUTURE_SIGHT, BattleScript_FutureHitAnimDoomDesire
	playanimation BS_ATTACKER, B_ANIM_FUTURE_SIGHT_HIT
	goto BattleScript_DoFutureAttackHit

BattleScript_FutureHitAnimDoomDesire::
	playanimation BS_ATTACKER, B_ANIM_DOOM_DESIRE_HIT

BattleScript_DoFutureAttackHit::
	HazSonidoEfectividad
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage PAUSA_LARGA

BattleScript_DoFutureAttackResult:
	resultmessage
	waitmessage PAUSA_LARGA
	tryfaintmon BS_TARGET
	checkteamslost BattleScript_FutureAttackEnd

BattleScript_FutureAttackEnd::
	moveendcase MOVEEND_RAGE
	moveendcase MOVEEND_ABILITIES
	moveendfromto MOVEEND_ITEM_EFFECTS_ALL, MOVEEND_UPDATE_LAST_MOVES
	setbyte gMoveResultFlags, 0
	end2

BattleScript_FutureAttackMiss::
	pause PAUSA_CORTA
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage PAUSA_LARGA
	sethword gMoveResultFlags, 0
	end2

BattleScript_NoMovesLeft::
	printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	endselectionscript

BattleScript_SelectingMoveWithNoPP::
	printselectionstring STRINGID_NOPPLEFT
	endselectionscript

BattleScript_NoPPForMove::
	attackstring
	pause PAUSA_CORTA
	EscribeTextoCombate "But there was no PP left for the move!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	endselectionscript

BattleScript_MoveUsedIsTormented::
	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTaunt::
	printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	endselectionscript

BattleScript_MoveUsedIsTaunted::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveThroatChop::
	printselectionstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	endselectionscript

BattleScript_MoveUsedIsThroatChopPrevented::
	printstring STRINGID_PKMNCANTUSEMOVETHROATCHOP
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_ThroatChopEndTurn::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can use sound-based moves again!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_SelectingNotAllowedMoveGravity::
	printselectionstring STRINGID_GRAVITYPREVENTSUSAGE
	endselectionscript

BattleScript_SelectingNotAllowedBelch::
	printselectionstring STRINGID_BELCHCANTSELECT
	endselectionscript

BattleScript_MoveUsedGravityPrevents::
	printstring STRINGID_GRAVITYPREVENTSUSAGE
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedCurrentMove::
	printselectionstring STRINGID_CURRENTMOVECANTSELECT
	endselectionscript

BattleScript_WishComesTrue::
	trywish 1, BattleScript_WishButFullHp
	playanimation BS_TARGET, B_ANIM_WISH_HEAL
	EscribeTextoCombate "{B_BUFF1}'s WISH came true!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} regained health!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_WishButFullHp::
	EscribeTextoCombate "{B_BUFF1}'s WISH came true!"
	waitmessage PAUSA_LARGA
	pause PAUSA_CORTA
	printstring STRINGID_PKMNHPFULL
	waitmessage PAUSA_LARGA
	end2

BattleScript_IngrainTurnHeal::
	playanimation BS_ATTACKER, B_ANIM_INGRAIN_HEAL
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} absorbed nutrients with its roots!"

BattleScript_TurnHeal:
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_AquaRingHeal::
	playanimation BS_ATTACKER, B_ANIM_AQUA_RING_HEAL
	EscribeTextoCombate "Aqua Ring restored {B_ATK_NAME_WITH_PREFIX}'s HP!"
	goto BattleScript_TurnHeal

BattleScript_PrintMonIsRooted::
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} anchored itself with its roots!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AtkDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_ATK, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownTryDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownTryDef
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_AtkDefDownTryDef:
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_AtkDefDownRet
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_AtkDefDownRet
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_AtkDefDownRet:
	return

BattleScript_DefSpDefDown::
	setbyte sSTAT_ANIM_PLAYED, FALSE
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE | STAT_CHANGE_MULTIPLE_STATS
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownTrySpDef
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownTrySpDef
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_DefSpDefDownTrySpDef::
	playstatchangeanimation BS_ATTACKER, BIT_SPDEF, STAT_CHANGE_CANT_PREVENT | STAT_CHANGE_NEGATIVE
	setstatchanger ESTADISTICA_DEFENSA_ESPECIAL, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_DefSpDefDownRet
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_DefSpDefDownRet
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_DefSpDefDownRet::
	return

BattleScript_DefDownSpeedUp::
	jumpifstat BS_ATTACKER, COMPARACION_MAYOR, ESTADISTICA_DEFENSA, ESTADISTICA_MENOS_6, BattleScript_DefDownSpeedUpTryDef
	jumpifstat BS_ATTACKER, COMPARACION_IGUAL, ESTADISTICA_VELOCIDAD, ESTADISTICA_MAS_6, BattleScript_DefDownSpeedUpRet

BattleScript_DefDownSpeedUpTryDef::
	playstatchangeanimation BS_ATTACKER, BIT_DEF, STAT_CHANGE_NEGATIVE | STAT_CHANGE_CANT_PREVENT
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_DefDownSpeedUpTrySpeed
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DefDownSpeedUpTrySpeed
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA

BattleScript_DefDownSpeedUpTrySpeed:
	playstatchangeanimation BS_ATTACKER, BIT_SPEED, 0
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR | MOVE_EFFECT_CERTAIN, BattleScript_DefDownSpeedUpRet
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_DefDownSpeedUpRet
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_DefDownSpeedUpRet::
	return

BattleScript_KnockedOff::
	playanimation BS_TARGET, B_ANIM_ITEM_KNOCKOFF
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} knocked off {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveUsedIsImprisoned::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	endselectionscript

BattleScript_MagicBounce::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back by {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	setmagiccoattarget
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_ALLOW_NO_PP
	bicword gHitMarker, HITMARKER_NO_ATTACKSTRING
	return

BattleScript_MagicCoat::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	setmagiccoattarget
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back by MAGIC COAT!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_ALLOW_NO_PP
	bicword gHitMarker, HITMARKER_NO_ATTACKSTRING
	return

BattleScript_MagicCoatPrankster::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back by MAGIC COAT!"
	waitmessage PAUSA_LARGA
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd

BattleScript_SnatchedMove::
	attackstring
	ppreduce
	snatchsetbattlers
	playanimation BS_TARGET, B_ANIM_SNATCH_MOVE
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} snatched {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s move!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_ALLOW_NO_PP
	swapattackerwithtarget
	return

BattleScript_OneHitKOMsg::
	printstring STRINGID_ONEHITKO
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectClearSmog::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s stat changes were removed!"
	waitmessage PAUSA_LARGA
	return

BattleScript_FocusPunchSetUp::
	playanimation BS_ATTACKER, B_ANIM_FOCUS_PUNCH_SETUP
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is tightening its focus!"
	waitmessage PAUSA_LARGA
	end3

BattleScript_AttackerFormChange::
	pause PAUSA_MUY_CORTA
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp

BattleScript_AttackerFormChangeNoPopup::
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_ATTACKER, 2
	return

BattleScript_AttackerFormChangeEnd3::
	call BattleScript_AttackerFormChange
	end3

BattleScript_AttackerFormChangeEnd3NoPopup::
	call BattleScript_AttackerFormChangeNoPopup
	end3

BattleScript_AttackerFormChangeWithString::
	pause PAUSA_MUY_CORTA
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp

BattleScript_AttackerFormChangeWithStringNoPopup::
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_ATTACKER, 2
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!"
	waitmessage PAUSA_LARGA
	return

BattleScript_AttackerFormChangeWithStringEnd3::
	call BattleScript_AttackerFormChangeWithString
	end3

BattleScript_AttackerFormChangeWithStringEnd3NoPopup::
	call BattleScript_AttackerFormChangeWithStringNoPopup
	end3

BattleScript_AttackerFormChangeMoveEffect::
	waitmessage 1
	handleformchange BS_ATTACKER, 0
	handleformchange BS_ATTACKER, 1
	playanimation BS_ATTACKER, B_ANIM_FORM_CHANGE
	waitanimation
	copybyte sBATTLER, gBattlerAttacker
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!"
	waitmessage PAUSA_LARGA
	handleformchange BS_ATTACKER, 2
	return

BattleScript_CudChewActivates::
	pause PAUSA_MUY_CORTA
	call BattleScript_AbilityPopUp
	setbyte sBERRY_OVERRIDE, 1 @ override the requirements for eating berries
	consumeberry BS_SCRIPTING, FALSE
	setbyte sBERRY_OVERRIDE, 0
	end3

BattleScript_TargetFormChangeNoPopup:
	handleformchange BS_SCRIPTING, 0
	handleformchange BS_SCRIPTING, 1
	playanimation BS_TARGET, B_ANIM_FORM_CHANGE
	waitanimation
	handleformchange BS_SCRIPTING, 2
	return

BattleScript_TargetFormChange::
	pause PAUSA_MUY_CORTA
	call BattleScript_AbilityPopUpTarget
	call BattleScript_TargetFormChangeNoPopup
	return

BattleScript_TargetFormChangeWithString::
	pause PAUSA_MUY_CORTA
	call BattleScript_AbilityPopUpTarget
	call BattleScript_TargetFormChangeNoPopup
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!"
	waitmessage PAUSA_LARGA
	return

BattleScript_TargetFormChangeWithStringNoPopup::
	call BattleScript_TargetFormChangeNoPopup
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!"
	waitmessage PAUSA_LARGA
	return

BattleScript_BattlerFormChangeWithStringEnd3::
	pause PAUSA_MUY_CORTA
	call BattleScript_AbilityPopUpScripting
	handleformchange BS_SCRIPTING, 0
	handleformchange BS_SCRIPTING, 1
	playanimation BS_SCRIPTING, B_ANIM_FORM_CHANGE, NULL
	waitanimation
	handleformchange BS_SCRIPTING, 2
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!"
	waitmessage PAUSA_LARGA
	end3

BattleScript_CottonDownActivates::
	copybyte sSAVED_BATTLER, gBattlerAttacker
	call BattleScript_AbilityPopUpTarget
	copybyte gEffectBattler, gBattlerTarget
	swapattackerwithtarget
	setbyte gBattlerTarget, 0

BattleScript_CottonDownLoop:
	jumpiffainted BS_TARGET, TRUE, BattleScript_CottonDownLoopIncrement
	setstatchanger ESTADISTICA_VELOCIDAD, 1, TRUE
	jumpifbyteequal gBattlerTarget, gEffectBattler, BattleScript_CottonDownLoopIncrement
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_CottonDownTargetSpeedCantGoLower
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_CottonDownLoopIncrement

BattleScript_CottonDownTargetSpeedCantGoLower:
	printstring STRINGID_STATSWONTDECREASE
	waitmessage PAUSA_LARGA

BattleScript_CottonDownLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_CottonDownLoop
	swapattackerwithtarget
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return

BattleScript_AftermathDmg::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_AftermathDmgRet
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was hurt!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER

BattleScript_AftermathDmgRet:
	return

BattleScript_DampPreventsAftermath::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	pause PAUSA_MEDIA
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} from working!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveUsedIsAsleep::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is fast asleep."
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedWokeUp::
	waitmessage PAUSA_LARGA
	updatestatusicon BS_ATTACKER
	return

BattleScript_MonWokeUpInUproar::
	EscribeTextoCombate "The uproar woke {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_ATTACKER
	end2

BattleScript_PoisonTurnDmg::
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} es herido por el veneno!"
	waitmessage PAUSA_LARGA

BattleScript_DoStatusTurnDmg::
	statusanimation BS_ATTACKER

BattleScript_DoTurnDmg:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER
	checkteamslost BattleScript_DoTurnDmgEnd

BattleScript_DoTurnDmgEnd:
	end2

BattleScript_PoisonHealActivates::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "The poisoning healed {B_ATK_NAME_WITH_PREFIX} a little bit!"
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_BurnTurnDmg::
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} está dolido por su quemadura!"
	waitmessage PAUSA_LARGA
	goto BattleScript_DoStatusTurnDmg

ScriptCombate_DanioCongelacion::
	EscribeTextoCombate "¡A {B_ATK_NAME_WITH_PREFIX} le duele su congelación!"
	waitmessage PAUSA_LARGA
	goto BattleScript_DoStatusTurnDmg

BattleScript_MoveUsedIsParalyzed::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is paralyzed! It can't move!"
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	cancelmultiturnmoves BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EstaSomnoliento::
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} está echando una cabezada!"
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	cancelmultiturnmoves BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_PowderMoveNoEffect::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	jumpiftype BS_TARGET, TIPO_PLANTA, BattleScript_PowderMoveNoEffectPrint
	jumpifability BS_TARGET, ABILITY_OVERCOAT, BattleScript_PowderMoveNoEffectOvercoat
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} is not affected thanks to its {B_LAST_ITEM}!"
	goto BattleScript_PowderMoveNoEffectWaitMsg

BattleScript_PowderMoveNoEffectOvercoat:
	call BattleScript_AbilityPopUp

BattleScript_PowderMoveNoEffectPrint:
	printstring STRINGID_ITDOESNTAFFECT

BattleScript_PowderMoveNoEffectWaitMsg:
	waitmessage PAUSA_LARGA
	cancelmultiturnmoves BS_ATTACKER
	sethword gMoveResultFlags, MOVE_RESULT_FAILED
	goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinched::
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} retrocedió!"
	waitmessage PAUSA_LARGA

BattleScript_PrintUproarOverTurns::
	printfromtable gUproarOverTurnStringIds
	waitmessage PAUSA_LARGA
	end2

BattleScript_ThrashConfuses::
	chosenstatus2animation BS_ATTACKER, STATUS2_CONFUSION
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} became confused due to fatigue!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_MoveUsedIsConfused::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is confused!"
	waitmessage PAUSA_LARGA
	status2animation BS_ATTACKER, STATUS2_CONFUSION
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, FALSE, BattleScript_MoveUsedIsConfusedRet

BattleScript_DoSelfConfusionDmg::
	cancelmultiturnmoves BS_ATTACKER
	adjustdamage
	EscribeTextoCombate "It hurt itself in its confusion!"
	waitmessage PAUSA_LARGA
	HazSonidoEfectividad
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	resultmessage
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfusedRet::
	return

BattleScript_MoveUsedPowder::
	bicword gHitMarker, HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED
	attackstring
	ppreduce
	pause PAUSA_CORTA
	cancelmultiturnmoves BS_ATTACKER
	status2animation BS_ATTACKER, STATUS2_POWDER
	waitanimation
	HazSonidoEfectividad
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "When the flame touched the powder on the Pokémon, it exploded!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfusedNoMore::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} snapped out of confusion!"
	waitmessage PAUSA_LARGA
	return

BattleScript_PrintPayDayMoneyString::
	EscribeTextoCombate "{B_PLAYER_NAME} picked up ¥{B_BUFF1}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_WrapTurnDmg::
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_DoTurnDmgEnd
	playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_DoTurnDmg

BattleScript_WrapEnds::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_MoveUsedIsInLove::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is in love with {B_SCR_ACTIVE_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	return

BattleScript_MoveUsedIsInLoveCantAttack::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is immobilized by love!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_NightmareTurnDmg::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is locked in a NIGHTMARE!"
	waitmessage PAUSA_LARGA
	status2animation BS_ATTACKER, STATUS2_NIGHTMARE
	goto BattleScript_DoTurnDmg

BattleScript_CurseTurnDmg::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is afflicted by the CURSE!"
	waitmessage PAUSA_LARGA
	status2animation BS_ATTACKER, STATUS2_CURSED
	goto BattleScript_DoTurnDmg

BattleScript_TargetPRLZHeal::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} was healed of paralysis!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_TARGET
	return

BattleScript_TargetWokeUp::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} woke up!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_TARGET
	return

BattleScript_TargetBurnHeal::
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} se curó de su quemadura!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_TARGET
	return

BattleScript_TargetPoisonHealed::
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} se curó de su envenamiento!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_TARGET
	return

ScriptCombate_SeCuroCongelacion::
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} se curó de su congelación!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_TARGET
	return

BattleScript_MoveEffectSleep::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gFellAsleepStringIds
	waitmessage PAUSA_LARGA

BattleScript_UpdateEffectStatusIconRet::
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	return

BattleScript_EmbargoEndTurn::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can use items again!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_TelekinesisEndTurn::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was freed from the telekinesis!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_BufferEndTurn::
	printstring STRINGID_BUFFERENDS
	waitmessage PAUSA_LARGA
	end2

BattleScript_ToxicOrb::
	setword gMensajeBatalla, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectToxic
	end2

BattleScript_FlameOrb::
	setword gMensajeBatalla, 0
	copybyte gEffectBattler, gBattlerAttacker
	call BattleScript_MoveEffectBurn
	end2

BattleScript_MoveEffectPoison::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotPoisonedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectBurn::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_UpdateEffectStatusIconRet

ScriptCombate_EfectoMovimientoCongelacion::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrozenStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectParalysis::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotParalyzedStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectUproar::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} caused an uproar!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectToxic::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNBADLYPOISONED
	waitmessage PAUSA_LARGA
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectPayDay::
	EscribeTextoCombate "Coins were scattered everywhere!"
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectWrap::
	printfromtable gWrappedStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectConfusion::
	chosenstatus2animation BS_EFFECT_BATTLER, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage PAUSA_LARGA
	return

BattleScript_MoveEffectRecoil::
	jumpifmove MOVE_STRUGGLE, BattleScript_DoRecoil
	jumpifability BS_ATTACKER, ABILITY_ROCK_HEAD, BattleScript_RecoilEnd
	jumpifability BS_ATTACKER, ABILITY_MAGIC_GUARD, BattleScript_RecoilEnd

BattleScript_DoRecoil::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} is hit with recoil!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER

BattleScript_RecoilEnd::
	return

BattleScript_ItemSteal::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} stole {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	return

ScriptCombate_ActivaLlovizna::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} invocó la lluvia!"
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_AbilityRaisesDefenderStat::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	statbuffchange 0, NULL
	setgraphicalstatchangevalues
	playanimation BS_ABILITY_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_DEFENDERSSTATROSE
	waitmessage PAUSA_LARGA
	return

BattleScript_AbilityPopUpTarget:
	copybyte gBattlerAbility, gBattlerTarget

BattleScript_AbilityPopUp:
	showabilitypopup BS_ABILITY_BATTLER
	pause PAUSA_MEDIA
	recordability BS_ABILITY_BATTLER
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_AbilityPopUpScripting:
	showabilitypopup BS_SCRIPTING
	pause PAUSA_MEDIA
	recordability BS_SCRIPTING
	sethword sABILITY_OVERWRITE, 0
	return

BattleScript_AbilityPopUpOverwriteThenNormal:
	setbyte sFIXED_ABILITY_POPUP, TRUE
	showabilitypopup BS_ABILITY_BATTLER
	pause PAUSA_LARGA
	sethword sABILITY_OVERWRITE, 0
	updateabilitypopup BS_ABILITY_BATTLER
	pause PAUSA_CORTA
	recordability BS_ABILITY_BATTLER
	DestruyeMensajeHabilidad
	pause PAUSA_MEDIA
	return

BattleScript_SpeedBoostActivates::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_SpeedBoostActivatesEnd
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} raised its SPEED!"
	waitmessage PAUSA_LARGA

BattleScript_SpeedBoostActivatesEnd:
	end3

BattleScript_TraceActivates::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUpScripting
	EscribeTextoCombate "¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} rastreó {B_BUFF2} de {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	settracedability BS_SCRIPTING
	switchinabilities BS_SCRIPTING
	end3

BattleScript_MagoActivado::
	call BattleScript_AbilityPopUp
	waitmessage PAUSA_LARGA
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} cambió objetos con el rival!"
	waitmessage PAUSA_LARGA
	printfromtable gItemSwapStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_MagoActivadoEnd::
	call BattleScript_MagoActivado
	end3

BattleScript_MagoEnd::
	end3

BattleScript_ReceiverActivates::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} was taken over!"
	waitmessage PAUSA_LARGA
	settracedability BS_ABILITY_BATTLER
	return

BattleScript_AbilityHpHeal:
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} le hizo recuperar salud!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_RainDishActivates::
	call BattleScript_AbilityHpHeal
	end3

BattleScript_HarvestActivates::
	pause PAUSA_MUY_CORTA
	tryrecycleitem BattleScript_HarvestActivatesEnd
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} harvested its {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA

BattleScript_HarvestActivatesEnd:
	end3

BattleScript_HealerActivates::
	call BattleScript_AbilityPopUp
	curestatus BS_SCRIPTING
	updatestatusicon BS_SCRIPTING
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} cured {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s problem!"
	waitmessage PAUSA_LARGA
	end3

BattleScript_SandstreamActivates::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} whipped up a sandstorm!"
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_SandSpitActivates::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "A sandstorm kicked up!"
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	return

BattleScript_ShedSkinActivates::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} cured its {B_BUFF1} problem!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_ATTACKER
	end3

BattleScript_ActivateWeatherAbilities:
	savetarget
	setbyte gBattlerTarget, 0

BattleScript_ActivateWeatherAbilities_Loop:
	copybyte sBATTLER, gBattlerTarget
	activateweatherchangeabilities BS_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_ActivateWeatherAbilities_Loop
	restoretarget
	return

BattleScript_TryIntimidateHoldEffects:
	itemstatchangeeffects BS_TARGET
	jumpifnoholdeffect BS_TARGET, HOLD_EFFECT_ADRENALINE_ORB, BattleScript_TryIntimidateHoldEffectsRet
	jumpifstat BS_TARGET, COMPARACION_IGUAL, ESTADISTICA_VELOCIDAD, 12, BattleScript_TryIntimidateHoldEffectsRet
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN | STAT_CHANGE_ALLOW_PTR, BattleScript_TryIntimidateHoldEffectsRet
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	copybyte sBATTLER, gBattlerTarget
	setlastuseditem BS_TARGET
	printstring STRINGID_USINGITEMSTATOFPKMNROSE
	waitmessage PAUSA_LARGA
	removeitem BS_TARGET

BattleScript_TryIntimidateHoldEffectsRet:
	return

BattleScript_IntimidateActivates::
	savetarget
	showabilitypopup BS_ATTACKER
	pause PAUSA_LARGA
	DestruyeMensajeHabilidad
	setbyte gBattlerTarget, 0
BattleScript_IntimidateLoop:
	jumpifbyteequal gBattlerTarget, gBattlerAttacker, BattleScript_IntimidateLoopIncrement
	jumpiftargetally BattleScript_IntimidateLoopIncrement
	jumpifabsent BS_TARGET, BattleScript_IntimidateLoopIncrement
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_IntimidateLoopIncrement
	jumpifability BS_TARGET, ABILITY_FUERZA_MENTAL, BattleScript_IntimidatePrevented
	jumpifability BS_TARGET, ABILITY_SCRAPPY, BattleScript_IntimidatePrevented
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_IntimidatePrevented
	jumpifability BS_TARGET, ABILITY_OBLIVIOUS, BattleScript_IntimidatePrevented
	jumpifability BS_TARGET, ABILITY_GUARD_DOG, BattleScript_IntimidateInReverse

BattleScript_IntimidateEffect:
	copybyte sBATTLER, gBattlerAttacker
	setstatchanger ESTADISTICA_ATAQUE, 1, TRUE
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | STAT_CHANGE_ALLOW_PTR, BattleScript_IntimidateLoopIncrement
	setgraphicalstatchangevalues
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_IntimidateWontDecrease
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSATTACKWITH

BattleScript_IntimidateEffect_WaitString:
	waitmessage PAUSA_LARGA
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_TryIntimidateHoldEffects

BattleScript_IntimidateLoopIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_IntimidateLoop
	copybyte sBATTLER, gBattlerAttacker
	DestruyeMensajeHabilidad
	restoretarget
	pause PAUSA_MEDIA
	end3

BattleScript_IntimidatePrevented:
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents stat loss!"
	goto BattleScript_IntimidateEffect_WaitString

BattleScript_IntimidateWontDecrease:
	printstring STRINGID_STATSWONTDECREASE
	goto BattleScript_IntimidateEffect_WaitString

BattleScript_IntimidateInReverse:
	copybyte sBATTLER, gBattlerTarget
	call BattleScript_AbilityPopUpTarget
	pause PAUSA_CORTA
	modifybattlerstatstage BS_TARGET, ESTADISTICA_ATAQUE, INCREASE, 1, BattleScript_IntimidateLoopIncrement, ANIM_ON
	call BattleScript_TryIntimidateHoldEffects
	goto BattleScript_IntimidateLoopIncrement

BattleScript_DroughtActivates::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} intensified the sun's rays!"
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end3

ScriptCombate_Nevada::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "¡Ha empezado a nevar!"
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SNOW_CONTINUES
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_BadDreamsActivates::
	setbyte gBattlerTarget, 0

BattleScript_BadDreamsLoop:
	jumpiftargetally BattleScript_BadDreamsIncrement
	jumpifability BS_TARGET, ABILITY_MAGIC_GUARD, BattleScript_BadDreamsIncrement
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_BadDreams_Dmg
	goto BattleScript_BadDreamsIncrement

BattleScript_BadDreams_Dmg:
	jumpifbyteequal sFIXED_ABILITY_POPUP, sZero, BattleScript_BadDreams_ShowPopUp

BattleScript_BadDreams_DmgAfterPopUp:
	printstring STRIN("{B_DEF_NAME_WITH_PREFIX} is tormented!")GID_BADDREAMSDMG
	waitmessage PAUSA_LARGA
	dmg_1_8_targethp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	jumpifhasnohp BS_TARGET, BattleScript_BadDreams_HidePopUp

BattleScript_BadDreamsIncrement:
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_BadDreamsLoop
	jumpifbyteequal sFIXED_ABILITY_POPUP, sZero, BattleScript_BadDreamsEnd
	DestruyeMensajeHabilidad
	pause PAUSA_MUY_CORTA

BattleScript_BadDreamsEnd:
	end3

BattleScript_BadDreams_ShowPopUp:
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setbyte sFIXED_ABILITY_POPUP, TRUE
	goto BattleScript_BadDreams_DmgAfterPopUp

BattleScript_BadDreams_HidePopUp:
	DestruyeMensajeHabilidad
	tryfaintmon BS_TARGET
	goto BattleScript_BadDreamsIncrement

BattleScript_TookAttack::
	attackstring
	pause PAUSA_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} took the attack!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED
	return

BattleScript_DampStopsExplosion::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUpScripting
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!"
	pause PAUSA_LARGA
	moveendto MOVEEND_NEXT_TARGET
	moveendcase MOVEEND_CLEAR_BITS
	end

BattleScript_MoveHPDrain_PPLoss::
	ppreduce

BattleScript_MoveHPDrain::
	attackstring
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} restored HP using its {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_MoveStatDrain_PPLoss::
	ppreduce

BattleScript_MoveStatDrain::
	attackstring
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_MoveStatDrain_Cont
.if B_ABSORBING_ABILITY_STRING >= GEN_5
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA
.else
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
.endif

BattleScript_MoveStatDrain_Cont:
	clearsemiinvulnerablebit
	goto BattleScript_MoveEnd

BattleScript_MonMadeMoveUseless_PPLoss::
	ppreduce

BattleScript_MonMadeMoveUseless::
	attackstring
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} made {B_CURRENT_MOVE} useless!"
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_FlashFireBoost_PPLoss::
	ppreduce

BattleScript_FlashFireBoost::
	attackstring
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	printfromtable gFlashFireStringIds
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsPhasingOut::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} anchors itself with {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AbilityNoStatLoss::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents stat loss!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ItemNoStatLoss::
	pause PAUSA_CORTA
	EscribeTextoCombate "The effects of the {B_LAST_ITEM} held by {B_DEF_NAME_WITH_PREFIX} prevents its stats from being lowered!"
	waitmessage PAUSA_LARGA
	return

BattleScript_BRNPrevention::
	pause PAUSA_CORTA
	printfromtable gBRNPreventionStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_PRLZPrevention::
	pause PAUSA_CORTA
	printfromtable gPRLZPreventionStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_PSNPrevention::
	pause PAUSA_CORTA
	printfromtable gPSNPreventionStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_ObliviousPreventsAttraction::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents romance!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_FlinchPrevention::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} prevents flinching!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_OwnTempoPrevents::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents confusion!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_SoundproofProtected::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} blocks {B_CURRENT_MOVE}!"
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_HabilidadProtegeEquipoDePrioridad::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUpScripting
	EscribeTextoCombate "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} protege al equipo de ataques de prioridad."
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_AbilityNoSpecificStatLoss::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents {B_BUFF1} loss!"
	waitmessage PAUSA_LARGA
	setword gMensajeBatalla, B_MSG_STAT_FELL_EMPTY
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	return

BattleScript_StickyHoldActivates::
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUp
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_ColorChangeActivates::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} made it the {B_BUFF1} type!"
	waitmessage PAUSA_LARGA
	return

BattleScript_ProteanActivates::
	pause PAUSA_MUY_CORTA
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"
	waitmessage PAUSA_LARGA
	return

BattleScript_CursedBodyActivates::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled by {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_TargetsStatWasMaxedOut::
	call BattleScript_AbilityPopUp
	statbuffchange STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} maxed its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_BattlerAbilityStatRaiseOnSwitchIn::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	copybyte gBattlerAttacker, sSAVED_BATTLER
	end3

BattleScript_ScriptingAbilityStatRaise::
	copybyte gBattlerAbility, sBATTLER
	call BattleScript_AbilityPopUp
	copybyte sSAVED_DMG, gBattlerAttacker
	copybyte gBattlerAttacker, sBATTLER
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_NOT_PROTECT_AFFECTED | MOVE_EFFECT_CERTAIN, NULL
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	copybyte gBattlerAttacker, sSAVED_DMG
	return

BattleScript_WeakArmorActivates::
	call BattleScript_AbilityPopUp
	setstatchanger ESTADISTICA_DEFENSA, 1, TRUE
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorActivatesSpeed
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_DECREASE, BattleScript_WeakArmorDefAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_FELL_EMPTY, BattleScript_WeakArmorActivatesSpeed
	pause PAUSA_MUY_CORTA
	printfromtable gStatDownStringIds
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED @ Set by statbuffchange when stat can't be decreased
	waitmessage PAUSA_LARGA
	goto BattleScript_WeakArmorActivatesSpeed

BattleScript_WeakArmorDefAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} lowered its {B_BUFF1}!"
	waitmessage PAUSA_LARGA

BattleScript_WeakArmorActivatesSpeed:
.if B_WEAK_ARMOR_SPEED >= GEN_7
	setstatchanger ESTADISTICA_VELOCIDAD, 2, FALSE
.else
	setstatchanger ESTADISTICA_VELOCIDAD, 1, FALSE
.endif
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_WeakArmorActivatesEnd
	jumpifword COMPARACION_MENOR, gMensajeBatalla, B_MSG_STAT_WONT_INCREASE, BattleScript_WeakArmorSpeedAnim
	jumpifword COMPARACION_IGUAL, gMensajeBatalla, B_MSG_STAT_ROSE_EMPTY, BattleScript_WeakArmorActivatesEnd
	pause PAUSA_MUY_CORTA
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"
	bichalfword gMoveResultFlags, MOVE_RESULT_MISSED
	waitmessage PAUSA_LARGA
	goto BattleScript_WeakArmorActivatesEnd

BattleScript_WeakArmorSpeedAnim:
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA

BattleScript_WeakArmorActivatesEnd:
	return

BattleScript_RaiseStatOnFaintingTarget::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_RaiseStatOnFaintingTarget_End
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA

BattleScript_RaiseStatOnFaintingTarget_End:
	return

BattleScript_Carnivoro::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "¡{B_ATK_NAME_WITH_PREFIX} ha usado a {B_DEF_NAME_WITH_PREFIX} para recuperarse!"
	waitmessage PAUSA_LARGA
	statusanimation BS_ATTACKER
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_AttackerAbilityStatRaise::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_AttackerAbilityStatRaise_End
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} raised its {B_BUFF1}!"
	waitmessage PAUSA_LARGA

BattleScript_AttackerAbilityStatRaise_End:
	return

BattleScript_FellStingerRaisesStat::
	statbuffchange MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_ALLOW_PTR, BattleScript_FellStingerRaisesAtkEnd
	jumpifword COMPARACION_MAYOR, gMensajeBatalla, B_MSG_DEFENDER_STAT_ROSE, BattleScript_FellStingerRaisesAtkEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage PAUSA_LARGA

BattleScript_FellStingerRaisesAtkEnd:
	return

BattleScript_AttackerAbilityStatRaiseEnd3::
	call BattleScript_AttackerAbilityStatRaise
	end3

BattleScript_SwitchInAbilityMsg::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage PAUSA_LARGA
	end3

BattleScript_SwitchInAbilityMsgRet::
	call BattleScript_AbilityPopUp
	printfromtable gSwitchInAbilityStringIds
	waitmessage PAUSA_LARGA
	return

BattleScript_FriskMsgWithPopup::
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp

BattleScript_FriskMsg::
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} frisked {B_DEF_NAME_WITH_PREFIX} and found its {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_FriskActivates::
	saveattacker
	copybyte gBattlerAttacker, sBATTLER
	tryfriskmsg BS_SCRIPTING
	restoreattacker
	end3

BattleScript_HurtAttacker:
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was hurt by {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	return

BattleScript_RoughSkinActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_HurtAttacker
	return

BattleScript_RockyHelmetActivates::
	@ don't play the animation for a fainted mon
	jumpifabsent BS_TARGET, BattleScript_RockyHelmetActivatesDmg
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation

BattleScript_RockyHelmetActivatesDmg:
	call BattleScript_HurtAttacker
	return

BattleScript_SpikyShieldEffect::
	jumpifabsent BS_ATTACKER, BattleScript_SpikyShieldRet
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	bichalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was hurt by {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	orhalfword gMoveResultFlags, MOVE_RESULT_MISSED

BattleScript_SpikyShieldRet::
	return

BattleScript_CuteCharmActivates::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage PAUSA_LARGA
	call BattleScript_TryDestinyKnotTarget
	return

BattleScript_NueveColas::
	call BattleScript_AbilityPopUp
	status2animation BS_ATTACKER, STATUS2_CURSED
	EscribeTextoCombate "¡Se ha activado la maldición de las nueve colas!"
	waitmessage PAUSA_LARGA
	return

BattleScript_Parasito::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "¡{B_DEF_NAME_WITH_PREFIX} le ha pasado su {B_DEF_ABILITY} a {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_GooeyActivates::
	waitstate
	call BattleScript_AbilityPopUp
	swapattackerwithtarget  @ for defiant, mirror armor
	seteffectsecondary MOVE_EFFECT_SPD_MINUS_1
	swapattackerwithtarget
	return

BattleScript_AbilityStatusEffect::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectsecondary
	return

BattleScript_SynchronizeActivates::
	waitstate
	call BattleScript_AbilityPopUp
	seteffectprimary
	return

BattleScript_NoItemSteal::
	call BattleScript_AbilityPopUpTarget
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage PAUSA_LARGA
	return

BattleScript_AbilityCuredStatus::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} cured its {B_BUFF1} problem!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	return

BattleScript_BattlerShookOffTaunt::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} shook off the taunt!"
	waitmessage PAUSA_LARGA
	return

BattleScript_BattlerGotOverItsInfatuation::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} got over its infatuation!"
	waitmessage PAUSA_LARGA
	return

BattleScript_SubstituteFade::
	playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s SUBSTITUTE faded!"
	return

BattleScript_BerryCurePrlzEnd2::
	call BattleScript_BerryCureParRet
	end2

BattleScript_BerryCureParRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured paralysis!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCurePsnEnd2::
	call BattleScript_BerryCurePsnRet
	end2

BattleScript_BerryCurePsnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured poison!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureBrnEnd2::
	call BattleScript_BerryCureBrnRet
	end2

BattleScript_BerryCureBrnRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} healed its burn!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureFrzEnd2::
	call BattleScript_BerryCureFrzRet
	end2

BattleScript_BerryCureFrzRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} defrosted it!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureSlpEnd2::
	call BattleScript_BerryCureSlpRet
	end2

BattleScript_BerryCureSlpRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} woke it from its sleep!"
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_GemActivates::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setlastuseditem BS_ATTACKER
	EscribeTextoCombate "The {B_LAST_ITEM} strengthened {B_ATK_NAME_WITH_PREFIX}'s power!"
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
	return

BattleScript_BerryReduceDmg::
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	setlastuseditem BS_TARGET
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} ate its {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	removeitem BS_TARGET
	return

BattleScript_PrintBerryReduceString::
	waitmessage PAUSA_LARGA
	EscribeTextoCombate "The {B_LAST_ITEM} weakened the damage to {B_DEF_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_BerryCureConfusionEnd2::
	call BattleScript_BerryCureConfusionRet
	end2

BattleScript_BerryCureConfusionRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} snapped it out of confusion!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureChosenStatusEnd2::
	call BattleScript_BerryCureChosenStatusRet
	end2

BattleScript_BerryCureChosenStatusRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	printfromtable gBerryEffectStringIds
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_MentalHerbCureRet::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	printfromtable gMentalHerbCureStringIds
	waitmessage PAUSA_LARGA
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	copybyte gBattlerAttacker, sSAVED_BATTLER   @ restore the original attacker just to be safe
	return

BattleScript_MentalHerbCureEnd2::
	call BattleScript_MentalHerbCureRet
	end2

BattleScript_WhiteHerbEnd2::
	call BattleScript_WhiteHerbRet
	end2

BattleScript_WhiteHerbRet::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored its status!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	return

BattleScript_ItemHealHP_RemoveItemRet::
	goto BattleScript_ItemHealHP_RemoveItemRet_Anim

BattleScript_ItemHealHP_RemoveItemRet_AbilityPopUp:
	call BattleScript_AbilityPopUp

BattleScript_ItemHealHP_RemoveItemRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored health!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_ItemHealHP_RemoveItemEnd2::
	goto BattleScript_ItemHealHP_RemoveItemEnd2_Anim

BattleScript_ItemHealHP_RemoveItemEnd2_AbilityPopUp:
	call BattleScript_AbilityPopUp

BattleScript_ItemHealHP_RemoveItemEnd2_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored health!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	removeitem BS_ATTACKER
	end2

BattleScript_BerryPPHealRet::
	goto BattleScript_BerryPPHeal_Anim

BattleScript_BerryPPHeal_AbilityPopup:
	call BattleScript_AbilityPopUp

BattleScript_BerryPPHeal_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored {B_BUFF1}'s PP!"
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
	return

BattleScript_BerryPPHealEnd2::
	call BattleScript_BerryPPHealRet
	end2

BattleScript_ItemHealHP_End2::
	call BattleScript_ItemHealHP_Ret
	end2

BattleScript_AirBaloonMsgIn::
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} floats in the air with its Air Balloon!"
	waitmessage PAUSA_LARGA
	end3

BattleScript_AirBaloonMsgPop::
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX}'s Air Balloon popped!"
	waitmessage PAUSA_LARGA
	removeitem BS_TARGET
	return

BattleScript_ItemHurtRet::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} was hurt by the {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	tryfaintmon BS_ATTACKER
	return

BattleScript_ItemHurtEnd2::
	playanimation BS_ATTACKER, B_ANIM_MON_HIT
	waitanimation
	call BattleScript_ItemHurtRet
	end2

BattleScript_ItemHealHP_Ret::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored its HP a little!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_SelectingNotAllowedMoveChoiceItem::
	printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveGorillaTactics::
	printselectionstring STRINGID_ABILITYALLOWSONLYMOVE
	endselectionscript

BattleScript_SelectingNotAllowedMoveAssaultVest::
	printselectionstring STRINGID_ASSAULTVESTDOESNTALLOW
	endselectionscript

BattleScript_BerryConfuseHealEnd2::
	goto BattleScript_BerryConfuseHealEnd2_Anim

BattleScript_BerryConfuseHealEnd2_AbilityPopup:
	call BattleScript_AbilityPopUp

BattleScript_BerryConfuseHealEnd2_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored health!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	seteffectprimary MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER
	removeitem BS_SCRIPTING
	end2

BattleScript_BerryConfuseHealRet::
	goto BattleScript_BerryConfuseHealRet_Anim

BattleScript_BerryConfuseHealRet_AbilityPopup:
	call BattleScript_AbilityPopUp

BattleScript_BerryConfuseHealRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored health!"
	waitmessage PAUSA_LARGA
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_PASSIVE_DAMAGE
	healthbarupdate BS_SCRIPTING
	datahpupdate BS_SCRIPTING
	seteffectprimary MOVE_EFFECT_CONFUSION | MOVE_EFFECT_CERTAIN
	removeitem BS_TARGET
	return

BattleScript_BerryStatRaiseEnd2::
	goto BattleScript_BerryStatRaiseEnd2_Anim

BattleScript_BerryStatRaiseEnd2_AbilityPopup:
	call BattleScript_AbilityPopUp

BattleScript_BerryStatRaiseEnd2_Anim:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseEnd2_End
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setword gMensajeBatalla, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_ATTACKER

BattleScript_BerryStatRaiseEnd2_End::
	end2

BattleScript_BerryStatRaiseRet::
	goto BattleScript_BerryStatRaiseRet_Anim

BattleScript_BerryStatRaiseRet_AbilityPopup:
	call BattleScript_AbilityPopUp

BattleScript_BerryStatRaiseRet_Anim:
	statbuffchange STAT_CHANGE_ALLOW_PTR, BattleScript_BerryStatRaiseRet_End
	setgraphicalstatchangevalues
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT, sB_ANIM_ARG1
	setword gMensajeBatalla, B_MSG_STAT_ROSE_ITEM
	call BattleScript_StatUp
	removeitem BS_SCRIPTING

BattleScript_BerryStatRaiseRet_End:
	return

BattleScript_ActionSelectionItemsCantBeUsed::
	printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	endselectionscript

BattleScript_AskIfWantsToForfeitMatch::
	printselectionstring STRINGID_QUESTIONFORFEITMATCH
	forfeityesnobox BS_ATTACKER
	endselectionscript

BattleScript_PrintPlayerForfeited::
	EscribeTextoCombate "The match was forfeited."
	waitmessage PAUSA_LARGA
	end2

ScriptCombate_SeptimoCielo::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "Han desaparecido los efectos del clima."
	waitmessage PAUSA_LARGA
	call BattleScript_ActivateWeatherAbilities
	end3

BattleScript_QuickClawActivation::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_QuickDrawActivation::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	end2

BattleScript_CustapBerryActivation::
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	waitanimation
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!"
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
	end2

BattleScript_MicleBerryActivateEnd2::
	goto BattleScript_MicleBerryActivateEnd2_Anim

BattleScript_MicleBerryActivateEnd2_Anim:
	playanimation BS_ATTACKER, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} boosted the accuracy of its next move using {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	removeitem BS_ATTACKER
	end2

BattleScript_MicleBerryActivateRet::
	goto BattleScript_MicleBerryActivateRet_Anim

BattleScript_MicleBerryActivateRet_Anim:
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} boosted the accuracy of its next move using {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	return

BattleScript_JabocaRowapBerryActivates::
	goto BattleScript_JabocaRowapBerryActivate_Anim

BattleScript_JabocaRowapBerryActivate_Anim:
	jumpifabsent BS_TARGET, BattleScript_JabocaRowapBerryActivate_Dmg   @ dont play the animation for a fainted target
	playanimation BS_TARGET, B_ANIM_HELD_ITEM_EFFECT
	waitanimation

BattleScript_JabocaRowapBerryActivate_Dmg:
	call BattleScript_HurtAttacker
	removeitem BS_TARGET
	return

BattleScript_Pickpocket::
	call BattleScript_AbilityPopUp
	jumpifability BS_ATTACKER, ABILITY_STICKY_HOLD, BattleScript_PickpocketPrevented
	swapattackerwithtarget
	call BattleScript_ItemSteal
	swapattackerwithtarget
	activateitemeffects BS_TARGET
	return

BattleScript_PickpocketPrevented:
	pause PAUSA_CORTA
	copybyte gBattlerAbility, gBattlerAttacker
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_ATK_NAME_WITH_PREFIX}'s item cannot be removed!"
	waitmessage PAUSA_LARGA
	return

BattleScript_StickyBarbTransfer::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL
	EscribeTextoCombate "The {B_LAST_ITEM} attached itself to {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	removeitem BS_TARGET
	return

BattleScript_RedCardActivationNoSwitch::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} held up its Red Card against {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	restoretarget
	return

BattleScript_RedCardActivates::
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} held up its Red Card against {B_ATK_NAME_WITH_PREFIX}!"
	waitmessage PAUSA_LARGA
	swapattackerwithtarget
	jumpifstatus3 BS_EFFECT_BATTLER, STATUS3_ROOTED, BattleScript_RedCardIngrain
	jumpifability BS_EFFECT_BATTLER, ABILITY_SUCTION_CUPS, BattleScript_RedCardSuctionCups
	removeitem BS_SCRIPTING
	setbyte sSWITCH_CASE, B_SWITCH_RED_CARD
	forcerandomswitch BattleScript_RedCardEnd
	@ changes the current battle script. the rest happens in BattleScript_RoarSuccessSwitch_Ret, if switch is successful

BattleScript_RedCardEnd:
	return

BattleScript_RedCardIngrain:
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} anchored itself with its roots!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	restoretarget
	return

BattleScript_RedCardSuctionCups:
	EscribeTextoCombate "{B_DEF_NAME_WITH_PREFIX} anchors itself with {B_DEF_ABILITY}!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	restoretarget
	return

BattleScript_EjectButtonActivates::
	makevisible BS_ATTACKER
	playanimation BS_SCRIPTING, B_ANIM_HELD_ITEM_EFFECT
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} is switched out with the {B_LAST_ITEM}!"
	waitmessage PAUSA_LARGA
	removeitem BS_SCRIPTING
	makeinvisible BS_SCRIPTING
	openpartyscreen BS_SCRIPTING, BattleScript_EjectButtonEnd
	switchoutabilities BS_SCRIPTING
	waitstate
	switchhandleorder BS_SCRIPTING 2
	returntoball BS_SCRIPTING, FALSE
	getswitchedmondata BS_SCRIPTING
	switchindataupdate BS_SCRIPTING
	hpthresholds BS_SCRIPTING
	EscribeTextoCombate "Qué"
	switchinanim BS_SCRIPTING 1
	waitstate
	switchineffects BS_SCRIPTING

BattleScript_EjectButtonEnd:
	return

BattleScript_EjectPackActivate_Ret::
	goto BattleScript_EjectButtonActivates

BattleScript_EjectPackActivate_End2::
	call BattleScript_EjectPackActivate_Ret
	end2

BattleScript_EjectPackActivates::
	jumpifcantswitch BS_SCRIPTING, BattleScript_EjectButtonEnd
	goto BattleScript_EjectPackActivate_Ret

BattleScript_DarkTypePreventsPrankster::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage PAUSA_LARGA
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	goto BattleScript_MoveEnd

BattleScript_WindRiderActivatesMoveEnd::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	call BattleScript_AbilityPopUpTarget
	orhalfword gMoveResultFlags, MOVE_RESULT_NO_EFFECT
	modifybattlerstatstage BS_TARGET, ESTADISTICA_ATAQUE, INCREASE, 1, BattleScript_WindRiderActivatesMoveEnd_End, ANIM_ON

BattleScript_WindRiderActivatesMoveEnd_End:
	goto BattleScript_MoveEnd

ScriptCombate_ActivacionExuvia::
	attackstring
	ppreduce
	call BattleScript_AbilityPopUpTarget
	pause PAUSA_CORTA
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage PAUSA_MEDIA
	goto BattleScript_MoveEnd

BattleScript_NeutralizingGasExits::
	savetarget
	pause PAUSA_CORTA
	EscribeTextoCombate "The effects of the neutralizing gas wore off!"
	waitmessage PAUSA_LARGA
	setbyte gBattlerTarget, 0

BattleScript_NeutralizingGasExitsLoop:
	switchinabilities BS_TARGET
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_NeutralizingGasExitsLoop
	restoretarget
	return

BattleScript_MagicianActivates::
	call BattleScript_AbilityPopUp
	call BattleScript_ItemSteal
	return

BattleScript_SymbiosisActivates::
	call BattleScript_AbilityPopUp
	EscribeTextoCombate "{B_SCR_ACTIVE_NAME_WITH_PREFIX} passed its {B_LAST_ITEM} to {B_ATK_NAME_WITH_PREFIX} through {B_LAST_ABILITY}!"
	waitmessage PAUSA_LARGA
	return

BattleScript_TargetAbilityStatRaiseRet::
	copybyte sSAVED_BATTLER, gBattlerAttacker
	copybyte gBattlerAbility, gEffectBattler
	copybyte gBattlerAttacker, gBattlerTarget
	call BattleScript_AbilityPopUp
	statbuffchange MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN, BattleScript_TargetAbilityStatRaiseRet_End
	setgraphicalstatchangevalues
	call BattleScript_StatUp

BattleScript_TargetAbilityStatRaiseRet_End:
	copybyte gBattlerAttacker, sSAVED_BATTLER
	return

BattleScript_PokemonCantUseTheMove::
	attackstring
	ppreduce
	pause PAUSA_CORTA
	EscribeTextoCombate "But {B_ATK_NAME_WITH_PREFIX} can't use the move!"
	waitmessage PAUSA_LARGA
	goto BattleScript_MoveEnd

BattleScript_EffectSnow::
	attackcanceler
	attackstring
	ppreduce
	setfieldweather ENUM_WEATHER_SNOW
	goto BattleScript_MoveWeatherChange

ScriptBatalla_LanzaPokeball::
	EscribeTextoCombate "¡Ahí va la Pokéball!"
	handleballthrow

BattleScript_SuccessBallThrow::
	setbyte sMON_CAUGHT, TRUE
	incrementgamestat GAME_STAT_POKEMON_CAPTURES
	EscribeTextoCombate "¡Lo tienes! ¡Capturaste a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}"
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	sethword gBattle_BG2_X, 0

BattleScript_TryPrintCaughtMonInfo:
	trysetcaughtmondexflags BattleScript_TryNicknameCaughtMon
	EscribeTextoCombate "Los datos de {B_DEF_NAME} se añadieron a la Pokédex."
	waitstate
	setbyte gBattleCommunication, 0
	displaydexinfo

BattleScript_TryNicknameCaughtMon::
	EscribeTextoCombate "¿Quieres ponerle un mote a {B_DEF_NAME}?"
	waitstate
	setbyte gBattleCommunication, 0
	trygivecaughtmonnick BattleScript_GiveCaughtMonEnd
	givecaughtmon
	EscribeTextoCombate "Se mandó a {VAR_TEXTO_2} a\n{VAR_TEXTO_1} del PC."
	waitmessage PAUSA_LARGA
	goto BattleScript_SuccessBallThrowEnd

BattleScript_GiveCaughtMonEnd::
	givecaughtmon

BattleScript_SuccessBallThrowEnd::
	setbyte gBattleOutcome, B_OUTCOME_CAUGHT
	finishturn

BattleScript_ShakeBallThrow::
	printfromtable gBallEscapeStringIds
	waitmessage PAUSA_LARGA
	finishaction

BattleScript_TrainerBallBlock::
	waitmessage PAUSA_LARGA
	EscribeTextoCombate "The TRAINER blocked the BALL!"
	waitmessage PAUSA_LARGA
	EscribeTextoCombate "Don't be a thief!"
	waitmessage PAUSA_LARGA
	finishaction

BattleScript_TrainerSlideMsgRet::
	handletrainerslidemsg BS_SCRIPTING, 0
	trainerslidein BS_OPPONENT
	handletrainerslidemsg BS_SCRIPTING, 1
	waitstate
	trainerslideout BS_OPPONENT
	waitstate
	handletrainerslidemsg BS_SCRIPTING, 2
	return

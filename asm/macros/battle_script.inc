#include "include/constants/battle_script_commands.h"
	.macro attackcanceler
	.byte BATTLE_CMD_attackcanceler
	.endm

	.macro accuracycheck failInstr:req, move:req
	.byte BATTLE_CMD_accuracycheck
	.4byte \failInstr
	.2byte \move
	.endm

	.macro attackstring
	.byte BATTLE_CMD_attackstring
	.endm

	.macro ppreduce
	.byte BATTLE_CMD_ppreduce
	.endm

	.macro critcalc
	.byte BATTLE_CMD_critcalc
	.endm

	.macro damagecalc
	.byte BATTLE_CMD_damagecalc
	.endm

	.macro typecalc
	.byte BATTLE_CMD_typecalc
	.endm

	.macro adjustdamage
	.byte BATTLE_CMD_adjustdamage
	.endm

	.macro multihitresultmessage
	.byte BATTLE_CMD_multihitresultmessage
	.endm

	.macro attackanimation
	.byte BATTLE_CMD_attackanimation
	.endm

	.macro waitanimation
	.byte BATTLE_CMD_waitanimation
	.endm

	.macro healthbarupdate battler:req
	.byte BATTLE_CMD_healthbarupdate
	.byte \battler
	.endm

	.macro datahpupdate battler:req
	.byte BATTLE_CMD_datahpupdate
	.byte \battler
	.endm

	.macro critmessage
	.byte BATTLE_CMD_critmessage
	.endm

	.macro HazSonidoEfectividad
	.byte BATTLE_CMD_HazSonidoEfectividad
	.endm

	.macro resultmessage
	.byte BATTLE_CMD_resultmessage
	.endm

	.macro EscribeTextoCombate id:req
	.byte BATTLE_CMD_EscribeTextoCombate
	.2byte \id
	.endm

	.macro printselectionstring id:req
	.byte BATTLE_CMD_printselectionstring
	.2byte \id
	.endm

	.macro waitmessage time:req
	.byte BATTLE_CMD_waitmessage
	.2byte \time
	.endm

	.macro printfromtable ptr:req
	.byte BATTLE_CMD_printfromtable
	.4byte \ptr
	.endm

	.macro setadditionaleffects
	1:
	.byte BATTLE_CMD_setadditionaleffects
	jumpifhalfword COMPARACION_IGUAL, sMOVE_EFFECT, MOVE_EFFECT_CONTINUE, 1b
	.endm

	.macro seteffectprimary moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte BATTLE_CMD_seteffectprimary
	.endm

	.macro seteffectsecondary moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte BATTLE_CMD_seteffectsecondary
	.endm

	.macro clearstatusfromeffect battler:req, moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte BATTLE_CMD_clearstatusfromeffect
	.byte \battler
	.endm

	.macro tryfaintmon battler:req
	.byte BATTLE_CMD_tryfaintmon
	.byte \battler
	.byte FALSE
	.4byte NULL
	.endm

	.macro tryfaintmon_spikes battler:req, instr:req
	.byte BATTLE_CMD_tryfaintmon
	.byte \battler
	.byte TRUE
	.4byte \instr
	.endm

	.macro dofaintanimation battler:req
	.byte BATTLE_CMD_dofaintanimation
	.byte \battler
	.endm

	.macro cleareffectsonfaint battler:req
	.byte BATTLE_CMD_cleareffectsonfaint
	.byte \battler
	.endm

	.macro jumpifstatus battler:req, flags:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifstatus
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifstatus2 battler:req, flags:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifstatus2
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifability battler:req, ability:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifability
	.byte \battler
	.2byte \ability
	.4byte \jumpInstr
	.endm

	.macro jumpifsideaffecting battler:req, flags:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifsideaffecting
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifstat battler:req, comparison:req, stat:req, value:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifstat
	.byte \battler
	.byte \comparison
	.byte \stat
	.byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifstatus3condition battler:req, flags:req, jumpIfTrue:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifstatus3condition
	.byte \battler
	.4byte \flags
	.byte \jumpIfTrue
	.4byte \jumpInstr
	.endm

	.macro jumpbasedontype battler:req, type:req, jumpIfType:req, jumpInstr:req
	.byte BATTLE_CMD_jumpbasedontype
	.byte \battler
	.byte \type
	.byte \jumpIfType
	.4byte \jumpInstr
	.endm

	.macro jumpiftype battler:req, type:req, jumpInstr:req
	jumpbasedontype \battler, \type, TRUE, \jumpInstr
	.endm

	.macro jumpifnottype battler:req, type:req, jumpInstr:req
	jumpbasedontype \battler, \type, FALSE, \jumpInstr
	.endm

	.macro getexp battler:req
	.byte BATTLE_CMD_getexp
	.byte \battler
	.endm

	.macro checkteamslost jumpInstr:req
	.byte BATTLE_CMD_checkteamslost
	.4byte \jumpInstr
	.endm

	.macro movevaluescleanup
	.byte BATTLE_CMD_movevaluescleanup
	.endm

	.macro setmultihit value:req
	.byte BATTLE_CMD_setmultihit
	.byte \value
	.endm

	.macro decrementmultihit loopInstr:req
	.byte BATTLE_CMD_decrementmultihit
	.4byte \loopInstr
	.endm

	.macro goto instr:req
	.byte BATTLE_CMD_goto
	.4byte \instr
	.endm

	.macro jumpifbyte comparison:req, bytePtr:req, value:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifbyte
	.byte \comparison
	.4byte \bytePtr
	.byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifhalfword comparison:req, halfwordPtr:req, value:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifhalfword
	.byte \comparison
	.4byte \halfwordPtr
	.2byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifword comparison:req, wordPtr:req, value:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifword
	.byte \comparison
	.4byte \wordPtr
	.4byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifarrayequal array1:req, array2:req, size:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifarrayequal
	.4byte \array1
	.4byte \array2
	.byte \size
	.4byte \jumpInstr
	.endm

	.macro jumpifarraynotequal array1:req, array2:req, size:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifarraynotequal
	.4byte \array1
	.4byte \array2
	.byte \size
	.4byte \jumpInstr
	.endm

	.macro setbyte bytePtr:req, value:req
	.byte BATTLE_CMD_setbyte
	.4byte \bytePtr
	.byte \value
	.endm

	.macro addbyte bytePtr:req, value:req
	.byte BATTLE_CMD_addbyte
	.4byte \bytePtr
	.byte \value
	.endm

	.macro subbyte bytePtr:req, value:req
	.byte BATTLE_CMD_subbyte
	.4byte \bytePtr
	.byte \value
	.endm

	.macro copyarray dest:req, src:req, size:req
	.byte BATTLE_CMD_copyarray
	.4byte \dest
	.4byte \src
	.byte \size
	.endm

	.macro copyarraywithindex dest:req, src:req, indexPtr:req, size:req
	.byte BATTLE_CMD_copyarraywithindex
	.4byte \dest
	.4byte \src
	.4byte \indexPtr
	.byte \size
	.endm

	.macro orbyte bytePtr:req, value:req
	.byte BATTLE_CMD_orbyte
	.4byte \bytePtr
	.byte \value
	.endm

	.macro orhalfword halfwordPtr:req, value:req
	.byte BATTLE_CMD_orhalfword
	.4byte \halfwordPtr
	.2byte \value
	.endm

	.macro orword wordPtr:req, value:req
	.byte BATTLE_CMD_orword
	.4byte \wordPtr
	.4byte \value
	.endm

	.macro bicbyte bytePtr:req, value:req
	.byte BATTLE_CMD_bicbyte
	.4byte \bytePtr
	.byte \value
	.endm

	.macro bichalfword halfwordPtr:req, value:req
	.byte BATTLE_CMD_bichalfword
	.4byte \halfwordPtr
	.2byte \value
	.endm

	.macro bicword wordPtr:req, value:req
	.byte BATTLE_CMD_bicword
	.4byte \wordPtr
	.4byte \value
	.endm

	.macro pause frames:req
	.byte BATTLE_CMD_pause
	.2byte \frames
	.endm

	.macro waitstate
	.byte BATTLE_CMD_waitstate
	.endm

	.macro healthbar_update battler:req
	.byte BATTLE_CMD_healthbar_update
	.byte \battler
	.endm

	.macro return
	.byte BATTLE_CMD_return
	.endm

	.macro end
	.byte BATTLE_CMD_end
	.endm

	.macro end2
	.byte BATTLE_CMD_end2
	.endm

	.macro end3
	.byte BATTLE_CMD_end3
	.endm

	.macro call instr:req
	.byte BATTLE_CMD_call
	.4byte \instr
	.endm

	.macro setroost
	.byte BATTLE_CMD_setroost
	.endm

	.macro jumpifabilitypresent ability:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifabilitypresent
	.2byte \ability
	.4byte \jumpInstr
	.endm

	.macro endselectionscript
	.byte BATTLE_CMD_endselectionscript
	.endm

	.macro playanimation battler:req, animId:req, argPtr=NULL
	.byte BATTLE_CMD_playanimation
	.byte \battler
	.byte \animId
	.4byte \argPtr
	.endm

	.macro playanimation_var battler:req, animIdPtr:req, argPtr=NULL
	.byte BATTLE_CMD_playanimation_var
	.byte \battler
	.4byte \animIdPtr
	.4byte \argPtr
	.endm

	.macro setgraphicalstatchangevalues
	.byte BATTLE_CMD_setgraphicalstatchangevalues
	.endm

	.macro playstatchangeanimation battler:req, stats:req, flags:req
	.byte BATTLE_CMD_playstatchangeanimation
	.byte \battler
	.byte \stats
	.byte \flags
	.endm

	.macro moveend endMode:req, endState:req
	.byte BATTLE_CMD_moveend
	.byte \endMode
	.byte \endState
	.endm

	@ Help macros for 5 uses of moveend command

	@ All cases
	.macro moveendall
	setbyte sMOVEEND_STATE, 0
	moveend 0, 0
	.endm

	@ Chosen case
	.macro moveendcase case:req
	setbyte sMOVEEND_STATE, \case
	moveend 1, 0
	.endm

	@ All cases from (inclusive)
	.macro moveendfrom from:req
	setbyte sMOVEEND_STATE, \from
	moveend 0, 0
	.endm

	@ All cases from 0 to (not inclusive)
	.macro moveendto to:req
	setbyte sMOVEEND_STATE, 0
	moveend 2, \to
	.endm

	@ Cases from (inclusive) to (not inclusive)
	.macro moveendfromto from:req, to:req
	setbyte sMOVEEND_STATE, \from
	moveend 2, \to
	.endm

	.macro returnatktoball
	.byte BATTLE_CMD_returnatktoball
	.endm

	.macro getswitchedmondata battler:req
	.byte BATTLE_CMD_getswitchedmondata
	.byte \battler
	.endm

	.macro switchindataupdate battler:req
	.byte BATTLE_CMD_switchindataupdate
	.byte \battler
	.endm

	.macro switchinanim battler:req, dontClearSubstitute:req
	.byte BATTLE_CMD_switchinanim
	.byte \battler
	.byte \dontClearSubstitute
	.endm

	.macro jumpifcantswitch battler:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifcantswitch
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro openpartyscreen battler:req, failInstr:req
	.byte BATTLE_CMD_openpartyscreen
	.byte \battler
	.4byte \failInstr
	.endm

	.macro switchhandleorder battler:req, state:req
	.byte BATTLE_CMD_switchhandleorder
	.byte \battler
	.byte \state
	.endm

	.macro switchineffects battler:req
	.byte BATTLE_CMD_switchineffects
	.byte \battler
	.endm

	.macro trainerslidein position:req
	.byte BATTLE_CMD_trainerslidein
	.byte \position
	.endm

	.macro playse song:req
	.byte BATTLE_CMD_playse
	.2byte \song
	.endm

	.macro fanfare song:req
	.byte BATTLE_CMD_fanfare
	.2byte \song
	.endm

	.macro playfaintcry battler:req
	.byte BATTLE_CMD_playfaintcry
	.byte \battler
	.endm

	.macro returntoball battler:req, changingForm:req
	.byte BATTLE_CMD_returntoball
	.byte \battler
	.byte \changingForm
	.endm

	.macro handlelearnnewmove learnedMoveInstr:req, nothingToLearnInstr:req, isFirstMove:req
	.byte BATTLE_CMD_handlelearnnewmove
	.4byte \learnedMoveInstr
	.4byte \nothingToLearnInstr
	.byte \isFirstMove
	.endm

	.macro yesnoboxlearnmove forgotMoveInstr:req
	.byte BATTLE_CMD_yesnoboxlearnmove
	.4byte \forgotMoveInstr
	.endm

	.macro yesnoboxstoplearningmove noInstr:req
	.byte BATTLE_CMD_yesnoboxstoplearningmove
	.4byte \noInstr
	.endm

	.macro hitanimation battler:req
	.byte BATTLE_CMD_hitanimation
	.byte \battler
	.endm

	.macro getmoneyreward
	.byte BATTLE_CMD_getmoneyreward
	.endm

	.macro callnative func:req
	.byte BATTLE_CMD_callnative
	.4byte \func
	.endm

	.macro swapattackerwithtarget
	.byte BATTLE_CMD_swapattackerwithtarget
	.endm

	.macro incrementgamestat stat:req
	.byte BATTLE_CMD_incrementgamestat
	.byte \stat
	.endm

	.macro drawpartystatussummary battler:req
	.byte BATTLE_CMD_drawpartystatussummary
	.byte \battler
	.endm

	.macro hidepartystatussummary battler:req
	.byte BATTLE_CMD_hidepartystatussummary
	.byte \battler
	.endm

	.macro jumptocalledmove notChosenMove:req
	.byte BATTLE_CMD_jumptocalledmove
	.byte \notChosenMove
	.endm

	.macro statusanimation battler:req
	.byte BATTLE_CMD_statusanimation
	.byte \battler
	.endm

	.macro status2animation battler:req, status2:req
	.byte BATTLE_CMD_status2animation
	.byte \battler
	.4byte \status2
	.endm

	.macro chosenstatusanimation battler:req, isStatus2:req, status:req
	.byte BATTLE_CMD_chosenstatusanimation
	.byte \battler
	.byte \isStatus2
	.4byte \status
	.endm

	.macro yesnobox
	.byte BATTLE_CMD_yesnobox
	.endm

	.macro cancelallactions
	.byte BATTLE_CMD_cancelallactions
	.endm

	.macro setgravity failInstr:req
	.byte BATTLE_CMD_setgravity
	.4byte \failInstr
	.endm

	.macro removeitem battler:req
	.byte BATTLE_CMD_removeitem
	.byte \battler
	.endm

	.macro atknameinbuff1
	.byte BATTLE_CMD_atknameinbuff1
	.endm

	.macro drawlvlupbox
	.byte BATTLE_CMD_drawlvlupbox
	.endm

	.macro resetsentmonsvalue
	.byte BATTLE_CMD_resetsentmonsvalue
	.endm

	.macro setatktoplayer0
	.byte BATTLE_CMD_setatktoplayer0
	.endm

	.macro makevisible battler:req
	.byte BATTLE_CMD_makevisible
	.byte \battler
	.endm

	.macro recordability battler:req
	.byte BATTLE_CMD_recordability
	.byte \battler
	.endm

	.macro buffermovetolearn
	.byte BATTLE_CMD_buffermovetolearn
	.endm

	.macro hpthresholds battler:req
	.byte BATTLE_CMD_hpthresholds
	.byte \battler
	.endm

	.macro hpthresholds2 battler:req
	.byte BATTLE_CMD_hpthresholds2
	.byte \battler
	.endm

	.macro useitemonopponent
	.byte BATTLE_CMD_useitemonopponent
	.endm

	.macro various battler:req, id:req
	.byte BATTLE_CMD_various
	.byte \battler
	.byte \id
	.endm

	.macro setprotectlike
	.byte BATTLE_CMD_setprotectlike
	.endm

	.macro tryexplosion
	.byte BATTLE_CMD_tryexplosion
	.endm

	.macro setatkhptozero
	.byte BATTLE_CMD_setatkhptozero
	.endm

	.macro jumpifnexttargetvalid jumpInstr:req
	.byte BATTLE_CMD_jumpifnexttargetvalid
	.4byte \jumpInstr
	.endm

	.macro tryhealhalfhealth failInstr:req, battler:req
	.byte BATTLE_CMD_tryhealhalfhealth
	.4byte \failInstr
	.byte \battler
	.endm

	.macro setfieldweather weather:req
	.byte BATTLE_CMD_setfieldweather
	.byte \weather
	.endm

	.macro setreflect
	.byte BATTLE_CMD_setreflect
	.endm

	.macro setseeded
	.byte BATTLE_CMD_setseeded
	.endm

	.macro manipulatedamage mode:req
	.byte BATTLE_CMD_manipulatedamage
	.byte \mode
	.endm

	.macro trysetrest failInstr:req
	.byte BATTLE_CMD_trysetrest
	.4byte \failInstr
	.endm

	.macro jumpifnotfirstturn jumpInstr:req
	.byte BATTLE_CMD_jumpifnotfirstturn
	.4byte \jumpInstr
	.endm

	.macro jumpifuproarwakes jumpInstr:req
	.byte BATTLE_CMD_jumpifuproarwakes
	.4byte \jumpInstr
	.endm

	.macro stockpile id:req
	.byte BATTLE_CMD_stockpile
	.byte \id
	.endm

	.macro stockpiletobasedamage failInstr:req
	.byte BATTLE_CMD_stockpiletobasedamage
	.4byte \failInstr
	.endm

	.macro stockpiletohpheal failInstr:req
	.byte BATTLE_CMD_stockpiletohpheal
	.4byte \failInstr
	.endm

	.macro setdrainedhp
	.byte BATTLE_CMD_setdrainedhp
	.endm

	.macro statbuffchange flags:req, failInstr:req
	.byte BATTLE_CMD_statbuffchange
	.2byte \flags
	.4byte \failInstr
	.endm

	.macro normalisebuffs
	.byte BATTLE_CMD_normalisebuffs
	.endm

	.macro forcerandomswitch failInstr:req
	.byte BATTLE_CMD_forcerandomswitch
	.4byte \failInstr
	.endm

	.macro givepaydaymoney
	.byte BATTLE_CMD_givepaydaymoney
	.endm

	.macro setlightscreen
	.byte BATTLE_CMD_setlightscreen
	.endm

	.macro damagetohalftargethp
	.byte BATTLE_CMD_damagetohalftargethp
	.endm

	.macro tryinfatuating failInstr:req
	.byte BATTLE_CMD_tryinfatuating
	.4byte \failInstr
	.endm

	.macro updatestatusicon battler:req
	.byte BATTLE_CMD_updatestatusicon
	.byte \battler
	.endm

	.macro setmist
	.byte BATTLE_CMD_setmist
	.endm

	.macro setsubstitute
	.byte BATTLE_CMD_setsubstitute
	.endm

	.macro disablelastusedattack failInstr:req
	.byte BATTLE_CMD_disablelastusedattack
	.4byte \failInstr
	.endm

	.macro trysetencore failInstr:req
	.byte BATTLE_CMD_trysetencore
	.4byte \failInstr
	.endm

	.macro setalwayshitflag
	.byte BATTLE_CMD_setalwayshitflag
	.endm

	.macro trychoosesleeptalkmove failInstr:req
	.byte BATTLE_CMD_trychoosesleeptalkmove
	.4byte \failInstr
	.endm

	.macro setdestinybond
	.byte BATTLE_CMD_setdestinybond
	.endm

	.macro trysetdestinybondtohappen
	.byte BATTLE_CMD_trysetdestinybondtohappen
	.endm

	.macro settailwind failInstr:req
	.byte BATTLE_CMD_settailwind
	.4byte \failInstr
	.endm

	.macro healpartystatus
	.byte BATTLE_CMD_healpartystatus
	.endm

	.macro cursetarget failInstr:req
	.byte BATTLE_CMD_cursetarget
	.4byte \failInstr
	.endm

	.macro trysetspikes failInstr:req
	.byte BATTLE_CMD_trysetspikes
	.4byte \failInstr
	.endm

	.macro setforesight
	.byte BATTLE_CMD_setforesight
	.endm

	.macro trysetperishsong failInstr:req
	.byte BATTLE_CMD_trysetperishsong
	.4byte \failInstr
	.endm

	.macro handlerollout
	.byte BATTLE_CMD_handlerollout
	.endm

	.macro jumpifconfusedandstatmaxed stat:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifconfusedandstatmaxed
	.byte \stat
	.4byte \jumpInstr
	.endm

	.macro handlefurycutter
	.byte BATTLE_CMD_handlefurycutter
	.endm

	.macro setembargo failInstr:req
	.byte BATTLE_CMD_setembargo
	.4byte \failInstr
	.endm

	.macro presentdamagecalculation
	.byte BATTLE_CMD_presentdamagecalculation
	.endm

	.macro setsafeguard
	.byte BATTLE_CMD_setsafeguard
	.endm

	.macro magnitudedamagecalculation
	.byte BATTLE_CMD_magnitudedamagecalculation
	.endm

	.macro jumpifnopursuitswitchdmg jumpInstr:req
	.byte BATTLE_CMD_jumpifnopursuitswitchdmg
	.4byte \jumpInstr
	.endm

	.macro halvehp failInstr:req
	.byte BATTLE_CMD_halvehp
	.4byte \failInstr
	.endm

	.macro copyfoestats
	.byte BATTLE_CMD_copyfoestats
	.endm

	.macro girorapidofree
	.byte BATTLE_CMD_girorapidofree
	.endm

	.macro setdefensecurlbit
	.byte BATTLE_CMD_setdefensecurlbit
	.endm

	.macro RecuperaSaludSegunClima failInstr:req
	.byte BATTLE_CMD_RecuperaSaludSegunClima
	.4byte \failInstr
	.endm

	.macro setstickyweb failInstr:req
	.byte BATTLE_CMD_setstickyweb
	.4byte \failInstr
	.endm

	.macro selectfirstvalidtarget
	.byte BATTLE_CMD_selectfirstvalidtarget
	.endm

	.macro setsemiinvulnerablebit clear=FALSE
	.byte BATTLE_CMD_setsemiinvulnerablebit
	.byte \clear
	.endm

	.macro clearsemiinvulnerablebit
	setsemiinvulnerablebit TRUE
	.endm

	.macro tryfiretwoturnmovenowbyeffect battler:req, checkChargeTurnEffects:req, jumpInstr:req
	.byte BATTLE_CMD_tryfiretwoturnmovenowbyeffect
	.byte \battler
	.byte \checkChargeTurnEffects
	.4byte \jumpInstr
	.endm

	.macro tryfiretwoturnmovewithoutcharging battler:req, jumpInstr:req
	tryfiretwoturnmovenowbyeffect \battler, TRUE, \jumpInstr
	.endm

	.macro tryfiretwoturnmoveaftercharging battler:req, jumpInstr:req
	tryfiretwoturnmovenowbyeffect \battler, FALSE, \jumpInstr
	.endm

	.macro setminimize
	.byte BATTLE_CMD_setminimize
	.endm

	.macro setforcedtarget
	.byte BATTLE_CMD_setforcedtarget
	.endm

	.macro setcharge battler:req
	.byte BATTLE_CMD_setcharge
	.byte \battler
	.endm

	.macro cureifburnedparalysedorpoisoned failInstr:req
	.byte BATTLE_CMD_cureifburnedparalysedorpoisoned
	.4byte \failInstr
	.endm

	.macro settorment failInstr:req
	.byte BATTLE_CMD_settorment
	.4byte \failInstr
	.endm

	.macro jumpifnodamage jumpInstr:req
	.byte BATTLE_CMD_jumpifnodamage
	.4byte \jumpInstr
	.endm

	.macro settaunt failInstr:req
	.byte BATTLE_CMD_settaunt
	.4byte \failInstr
	.endm

	.macro tryswapitems failInstr:req
	.byte BATTLE_CMD_tryswapitems
	.4byte \failInstr
	.endm

	.macro trycopyability battler:req, failInstr:req
	.byte BATTLE_CMD_trycopyability
	.byte \battler
	.4byte \failInstr
	.endm

	.macro settoxicspikes failInstr:req
	.byte BATTLE_CMD_settoxicspikes
	.4byte \failInstr
	.endm

	.macro setgastroacid failInstr:req
	.byte BATTLE_CMD_setgastroacid
	.4byte \failInstr
	.endm

	.macro setdamagetohealthdifference failInstr:req
	.byte BATTLE_CMD_setdamagetohealthdifference
	.4byte \failInstr
	.endm

	.macro setroom
	.byte BATTLE_CMD_setroom
	.endm

	.macro tryimprison failInstr:req
	.byte BATTLE_CMD_tryimprison
	.4byte \failInstr
	.endm

	.macro setstealthrock failInstr:req
	.byte BATTLE_CMD_setstealthrock
	.4byte \failInstr
	.endm

	.macro setuserstatus3 flags:req, failInstr:req
	.byte BATTLE_CMD_setuserstatus3
	.4byte \flags
	.4byte \failInstr
	.endm

	.macro trysetsnatch failInstr:req
	.byte BATTLE_CMD_trysetsnatch
	.4byte \failInstr
	.endm

	.macro switchoutabilities battler:req
	.byte BATTLE_CMD_switchoutabilities
	.byte \battler
	.endm

	.macro jumpifhasnohp battler:req, jumpInstr:req
	.byte BATTLE_CMD_jumpifhasnohp
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro jumpifnotcurrentmoveargtype battler:req, failInstr:req
	.byte BATTLE_CMD_jumpifnotcurrentmoveargtype
	.byte \battler
	.4byte \failInstr
	.endm

	.macro jumpifsubstituteblocks jumpInstr:req
	.byte BATTLE_CMD_jumpifsubstituteblocks
	.4byte \jumpInstr
	.endm

	.macro tryrecycleitem failInstr:req
	.byte BATTLE_CMD_tryrecycleitem
	.4byte \failInstr
	.endm

	.macro snatchsetbattlers
	.byte BATTLE_CMD_snatchsetbattlers
	.endm

	.macro EliminaPantallas
	.byte BATTLE_CMD_EliminaPantallas
	.endm

	.macro handleballthrow
	.byte BATTLE_CMD_handleballthrow
	.endm

	.macro givecaughtmon
	.byte BATTLE_CMD_givecaughtmon
	.endm

	.macro trysetcaughtmondexflags failInstr:req
	.byte BATTLE_CMD_trysetcaughtmondexflags
	.4byte \failInstr
	.endm

	.macro displaydexinfo
	.byte BATTLE_CMD_displaydexinfo
	.endm

	.macro trygivecaughtmonnick successInstr:req
	.byte BATTLE_CMD_trygivecaughtmonnick
	.4byte \successInstr
	.endm

	.macro subattackerhpbydmg
	.byte BATTLE_CMD_subattackerhpbydmg
	.endm

	.macro removeattackerstatus1
	.byte BATTLE_CMD_removeattackerstatus1
	.endm

	.macro finishaction
	.byte BATTLE_CMD_finishaction
	.endm

	.macro finishturn
	.byte BATTLE_CMD_finishturn
	.endm

	.macro trainerslideout position:req
	.byte BATTLE_CMD_trainerslideout
	.byte \position
	.endm

	.macro settelekinesis failInstr:req
	.byte BATTLE_CMD_settelekinesis
	.4byte \failInstr
	.endm

	.macro swapstatstages stat:req
	.byte BATTLE_CMD_swapstatstages
	.byte \stat
	.endm

	.macro averagestats stat:req
	.byte BATTLE_CMD_averagestats
	.byte \stat
	.endm

	.macro jumpifoppositegenders jumpInstr:req
	.byte BATTLE_CMD_jumpifoppositegenders
	.4byte \jumpInstr
	.endm

	.macro savetarget
	callnative BS_SaveTarget
	.endm

	.macro restoretarget
	callnative BS_RestoreTarget
	.endm

	.macro saveattacker
	callnative BS_SaveAttacker
	.endm

	.macro restoreattacker
	callnative BS_RestoreAttacker
	.endm

	.macro itemstatchangeeffects battler:req
	callnative BS_RunStatChangeItems
	.byte \battler
	.endm

	.macro dostockpilestatchangeswearoff, battler:req, statChangeInstr:req
	callnative BS_DoStockpileStatChangesWearOff
	.byte \battler
	.4byte \statChangeInstr
	.endm

	.macro jumpifmorethanhalfHP battler:req, jumpInstr:req
	callnative BS_JumpIfMoreThanHalfHP
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro itemcurestatus jumpInstr:req
	callnative BS_ItemCureStatus
	.4byte \jumpInstr
	.endm

	.macro itemincreasestat
	callnative BS_ItemIncreaseStat
	.endm

	.macro tryrevertweatherform
	callnative BS_TryRevertWeatherForm
	.endm

	.macro tryrelicsong
	callnative BS_TryRelicSong
	.endm

	.macro checkparentalbondcounter counter:req, ptr:req
	callnative BS_CheckParentalBondCounter
	.byte \counter
	.4byte \ptr
	.endm

	.macro jumpifcantloseitem battler:req, ptr:req
	callnative BS_JumpIfCantLoseItem
	.byte \battler
	.4byte \ptr
	.endm

	.macro jumpifargument argument:req, jumpInstr:req
	callnative BS_JumpIfArgument
	.byte \argument
	.4byte \jumpInstr
	.endm

	.macro trysetstatus1, ptr:req
	callnative BS_TrySetStatus1
	.4byte \ptr
	.endm

	.macro trysetstatus2, ptr:req
	callnative BS_TrySetStatus2
	.4byte \ptr
	.endm

	.macro tryhealsixthhealth, ptr:req
	callnative BS_HealOneSixth
	.4byte \ptr
	.endm

	.macro tryrecycleberry, ptr:req
	callnative BS_TryRecycleBerry
	.4byte \ptr
	.endm

	.macro tryhealpulse failInstr:req
	callnative BS_TryHealPulse
	.4byte \failInstr
	.endm

	.macro trydefog clear:req, failInstr:req
	callnative BS_TryDefog
	.byte \clear
	.4byte \failInstr
	.endm

	.macro IntentaPalmaRauda failInstr:req
	callnative ScriptCombate_PalmaRauda
	.4byte \failInstr
	.endm

	.macro damagetoquartertargethp
	callnative BS_DamageToQuarterTargetHP
	.endm

	.macro trywindriderpower battler:req, failInstr:req
	callnative BS_TryWindRiderPower
	.byte \battler
	.4byte \failInstr
	.endm

	.macro activateweatherchangeabilities battler:req
	callnative BS_ActivateWeatherChangeAbilities
	.byte \battler
	.endm

	.macro hitswitchtargetfailed
	callnative BS_HitSwitchTargetFailed
	.endm

	.macro jumpifblockedbysoundproof battler:req, failInstr:req
	callnative BS_JumpIfBlockedBySoundproof
	.byte \battler
	.4byte \failInstr
	.endm

	.macro waitfanfare
	callnative BS_WaitFanfare
	.endm

	.macro tryhitswitchtarget failInstr:req
	callnative BS_TryHitSwitchTarget
	.4byte \failInstr
	.endm

	.macro ObjetivoEspejoMagico
	callnative BS_ObjetivoEspejoMagico
	.endm

@ various command changed to more readable macros
	.macro cancelmultiturnmoves battler:req
	various \battler, VARIOUS_CANCEL_MULTI_TURN_MOVES
	.endm

	.macro getmovetarget battler:req
	various \battler, VARIOUS_GET_MOVE_TARGET
	.endm

	.macro getbattlerfainted battler:req
	various \battler, VARIOUS_GET_BATTLER_FAINTED
	.endm

	.macro resetswitchinabilitybits battler:req
	various \battler, VARIOUS_RESET_SWITCH_IN_ABILITY_BITS
	.endm

	.macro updatechoicemoveonlvlup battler:req
	various \battler, VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP
	.endm

	.macro resetplayerfainted
	various BS_ATTACKER, VARIOUS_RESET_PLAYER_FAINTED
	.endm

	.macro forfeityesnobox battler:req
	various \battler, VARIOUS_EMIT_YESNOBOX
	.endm

	.macro waitcry battler:req
	various \battler, VARIOUS_WAIT_CRY
	.endm

	.macro returnopponentmon1toball battler:req
	various \battler, VARIOUS_RETURN_OPPONENT_MON1
	.endm

	.macro returnopponentmon2toball battler:req
	various \battler, VARIOUS_RETURN_OPPONENT_MON2
	.endm

	.macro volumedown
	various BS_ATTACKER, VARIOUS_VOLUME_DOWN
	.endm

	.macro volumeup
	various BS_ATTACKER, VARIOUS_VOLUME_UP
	.endm

	.macro setoutcomeonteleport battler:req
	various \battler, VARIOUS_SET_TELEPORT_OUTCOME
	.endm

	.macro playtrainerdefeatbgm battler:req
	various \battler, VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC
	.endm

	.macro stattextbuffer battler:req
	various \battler, VARIOUS_STAT_TEXT_BUFFER
	.endm

	.macro switchinabilities battler:req
	various \battler, VARIOUS_SWITCHIN_ABILITIES
	.endm

	.macro instanthpdrop battler:req
	various \battler, VARIOUS_INSTANT_HP_DROP
	.endm

	.macro clearstatus battler:req
	various \battler, VARIOUS_CLEAR_STATUS
	.endm

	.macro intentaactivarautoestima battler:req
	various \battler, VARIOUS_INTENTA_ACTIVAR_AUTOESTIMA
	.endm

	.macro tryactivatebeastboost battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_BEAST_BOOST
	.endm

	.macro tryactivatereceiver battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_RECEIVER
	.endm

	.macro tryactivatesoulheart
	various BS_ATTACKER, VARIOUS_TRY_ACTIVATE_SOULHEART
	.endm

	.macro tryactivatefellstinger battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_FELL_STINGER
	.endm

	.macro playmoveanimation battler:req, move:req
	various \battler, VARIOUS_PLAY_MOVE_ANIMATION
	.2byte \move
	.endm

	.macro setluckychant battler:req, failInstr:req
	various \battler VARIOUS_SET_LUCKY_CHANT
	.4byte \failInstr
	.endm

	.macro golpebajocheck failInstr:req
	various BS_ATTACKER, VARIOUS_GOLPE_BAJO_CHECK
	.4byte \failInstr
	.endm

	.macro setlastusedability battler:req
	various \battler, VARIOUS_SET_LAST_USED_ABILITY
	.endm

	.macro invertstatstages battler:req
	various \battler, VARIOUS_INVERT_STAT_STAGES
	.endm

	.macro jumpifbattleend jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_BATTLE_END
	.4byte \jumpInstr
	.endm

	.macro handleformchange battler:req, case:req
	various \battler, VARIOUS_HANDLE_FORM_CHANGE
	.byte \case
	.endm

	.macro jumpifcantuselastresort battler:req, jumpInstr:req
	various \battler, VARIOUS_TRY_LAST_RESORT
	.4byte \jumpInstr
	.endm

	.macro setargtobattledamage
	various BS_ATTACKER, VARIOUS_SET_ARG_TO_BATTLE_DAMAGE
	.endm

	.macro tryautotomize battler:req, failInstr:req
	various \battler, VARIOUS_TRY_AUTOTOMIZE
	.4byte \failInstr
	.endm

	.macro showabilitypopup battler:req
	various \battler, VARIOUS_ABILITY_POPUP
	.endm

	.macro updateabilitypopup battler:req
	various \battler, VARIOUS_UPDATE_ABILITY_POPUP
	.endm

	.macro jumpiftargetally jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_TARGET_ALLY
	.4byte \jumpInstr
	.endm

	.macro curestatus battler:req
	various \battler, VARIOUS_CURE_STATUS
	.endm

	.macro powertrick battler:req
	various \battler, VARIOUS_POWER_TRICK
	.endm

	.macro jumpifnotgrounded battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NOT_GROUNDED
	.4byte \jumpInstr
	.endm

	.macro handletrainerslidemsg battler:req, case:req
	various \battler, VARIOUS_HANDLE_TRAINER_SLIDE_MSG
	.byte \case
	.endm

	.macro trytrainerslidefirstdownmsg battler:req
	various \battler, VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF
	.endm

	.macro trytrainerslidelastonmsg battler:req
	various \battler, VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON
	.endm

	.macro setauroraveil battler:req
	various \battler, VARIOUS_SET_AURORA_VEIL
	.endm

	.macro spectralthiefprintstats
	various BS_ATTACKER, VARIOUS_SPECTRAL_THIEF
	.endm

	.macro bringdownairbornebattler battler:req
	various \battler, VARIOUS_GRAVITY_ON_AIRBORNE_MONS
	.endm

	.macro jumpifnotberry battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NOT_BERRY
	.4byte \jumpInstr
	.endm

	.macro jumpifroarfails jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_ROAR_FAILS
	.4byte \jumpInstr
	.endm

	.macro settracedability battler:req
	various \battler, VARIOUS_TRACE_ABILITY
	.endm

	.macro updatenick battler:req
	various \battler, VARIOUS_UPDATE_NICK
	.endm

	.macro jumpiffullhp battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_FULL_HP
	.4byte \jumpInstr
	.endm

	.macro trypoisontype attacker:req, target:req, failInstr:req
	various \attacker, VARIOUS_POISON_TYPE_IMMUNITY
	.byte \target
	.4byte \failInstr
	.endm

	.macro tryparalyzetype attacker:req, target:req, failInstr:req
	various \attacker, VARIOUS_PARALYZE_TYPE_IMMUNITY
	.byte \target
	.4byte \failInstr
	.endm

	.macro jumpifnoally battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NO_ALLY
	.4byte \jumpInstr
	.endm

	.macro jumpifholdeffect battler:req, holdEffect:req, jumpInstr:req, equal=TRUE
	various \battler, VARIOUS_JUMP_IF_HOLD_EFFECT
	.byte \holdEffect
	.4byte \jumpInstr
	.byte \equal
	.endm

	.macro jumpifnoholdeffect battler:req, holdEffect:req, jumpInstr:req
	jumpifholdeffect \battler, \holdEffect, \jumpInstr, FALSE
	.endm

	.macro infatuatewithbattler battler:req, infatuateWith:req
	various \battler, VARIOUS_INFATUATE_WITH_BATTLER
	.byte \infatuateWith
	.endm

	.macro setlastuseditem battler:req
	various \battler, VARIOUS_SET_LAST_USED_ITEM
	.endm

	.macro jumpifabsent battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_ABSENT
	.4byte \jumpInstr
	.endm

	.macro DestruyeMensajeHabilidad
	various BS_ABILITY_BATTLER, VARIOUS_DESTROY_ABILITY_POPUP
	.endm

	.macro consumeberry battler:req, fromBattler:req
	various \battler, VARIOUS_CONSUME_BERRY
	.byte \fromBattler
	.endm

	.macro activateitemeffects battler:req
	various \battler, VARIOUS_MOVEEND_ITEM_EFFECTS
	.endm

	.macro pickpocketsteal
	various 0, VARIOUS_PICKPOCKET
	.endm

	.macro makeinvisible battler:req
	various \battler, VARIOUS_MAKE_INVISIBLE
	.endm

	.macro tryroomservice battler:req, failInstr:req
	various \battler, VARIOUS_ROOM_SERVICE
	.4byte \failInstr
	.endm

	.macro jumpifpranksterblocked battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_BROMISTA_BLOCKED
	.4byte \jumpInstr
	.endm

	.macro jumpifteamhealthy battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_TEAM_HEALTHY
	.4byte \jumpInstr
	.endm

	.macro tryhealquarterhealth battler:req, failInstr:req
	various \battler, VARIOUS_TRY_HEAL_QUARTER_HP
	.4byte \failInstr
	.endm

	.macro setattackertostickywebuser
	various BS_TARGET, VARIOUS_SET_ATTACKER_STICKY_WEB_USER
	.endm

	.macro jumpifweatheraffected battler:req, flags:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_WEATHER_AFFECTED
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifspecies battler:req, species:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_SPECIES
	.2byte \species
	.4byte \jumpInstr
	.endm

	.macro tryendneutralizinggas battler:req
	various \battler, VARIOUS_TRY_END_NEUTRALIZING_GAS
	.endm

	.macro cutonethirdhpraisestats failInstr:req
	various BS_ATTACKER, VARIOUS_CUT_1_3_HP_RAISE_STATS
	.4byte \failInstr
	.endm

	.macro curecertainstatuses battler:req
	various \battler, VARIOUS_CURE_CERTAIN_STATUSES
	.endm

	.macro tryresetnegativestatstages battler:req
	various \battler, VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES
	.endm

	.macro jumpiflastuseditemberry jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY
	.4byte \jumpInstr
	.endm

	.macro jumpiflastuseditemholdeffect battler:req, holdEffect:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT
	.byte \holdEffect
	.4byte \jumpInstr
	.endm

	.macro savebattleritem battler:req
	various \battler, VARIOUS_SAVE_BATTLER_ITEM
	.endm

	.macro restorebattleritem battler:req
	various \battler, VARIOUS_RESTORE_BATTLER_ITEM
	.endm

	.macro battleritemtolastuseditem battler:req
	various \battler, VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM
	.endm

	.macro swapstats stat:req
	various BS_ATTACKER, VARIOUS_SWAP_STATS
	.byte \stat
	.endm

@ helpful macros
	.macro setstatchanger stat:req, stages:req, down:req
	setbyte sSTATCHANGER, \stat | \stages << 3 | \down << 7
	.endm

	.macro setmoveeffect effect:req
	sethword sMOVE_EFFECT, \effect
	sethword sSAVED_MOVE_EFFECT, \effect
	.endm

	.macro chosenstatus1animation battler:req, status:req
	chosenstatusanimation \battler, 0x0, \status
	.endm

	.macro chosenstatus2animation battler:req, status:req
	chosenstatusanimation \battler, 0x1, \status
	.endm

	.macro sethword dst:req, value:req
	setbyte \dst, (\value) & 0xFF
	setbyte \dst + 1, ((\value) >> 8) & 0xFF
	.endm

	.macro setword dst:req, value:req
	setbyte \dst, (\value) & 0xFF
	setbyte \dst + 1, ((\value) >> 8) & 0xFF
	setbyte \dst + 2, ((\value) >> 16) & 0xFF
	setbyte \dst + 3, ((\value) >> 24) & 0xFF
	.endm

	.macro copybyte dst:req, src:req
	copyarray \dst, \src, 0x1
	.endm

	.macro copyhword dst:req, src:req
	copyarray \dst, \src, 0x2
	.endm

	.macro copyword dst:req, src:req
	copyarray \dst, \src, 0x4
	.endm

	.macro jumpifbytenotequal byte1:req, byte2:req, jumpInstr:req
	jumpifarraynotequal \byte1, \byte2, 0x1, \jumpInstr
	.endm

	.macro jumpifbyteequal byte1:req, byte2:req, jumpInstr:req
	jumpifarrayequal \byte1, \byte2, 0x1, \jumpInstr
	.endm

	.macro jumpifmove move:req, jumpInstr:req
	jumpifhalfword COMPARACION_IGUAL, gCurrentMove, \move, \jumpInstr
	.endm

	.macro jumpifnotmove move:req, jumpInstr:req
	jumpifhalfword COMPARACION_DESIGUAL, gCurrentMove, \move, \jumpInstr
	.endm

	.macro jumpifnotchosenmove move:req, jumpInstr:req
	jumpifhalfword COMPARACION_DESIGUAL, gChosenMove, \move, \jumpInstr
	.endm

	.macro jumpifstatus3 battler:req, flags:req, jumpInstr:req
	jumpifstatus3condition \battler, \flags, FALSE, \jumpInstr
	.endm

	.macro jumpifnostatus3 battler:req, flags:req, jumpInstr:req
	jumpifstatus3condition \battler, \flags, TRUE, \jumpInstr
	.endm

	.macro jumpifmovehadnoeffect jumpInstr:req
	jumpifbyte COMPARACION_BITS_COMUNES, gMoveResultFlags, MOVE_RESULT_NO_EFFECT, \jumpInstr
	.endm

	.macro jumpifbattletype flags:req, jumpInstr:req
	jumpifword COMPARACION_BITS_COMUNES, gBattleTypeFlags, \flags, \jumpInstr
	.endm

	.macro jumpifnotbattletype flags:req, jumpInstr:req
	jumpifword COMPARACION_BITS_DISTINTOS, gBattleTypeFlags, \flags, \jumpInstr
	.endm

	.macro dmg_1_8_targethp
	manipulatedamage DMG_1_8_TARGET_HP
	.endm

	.macro dmgtomaxattackerhp
	manipulatedamage DMG_FULL_ATTACKER_HP
	.endm

	.macro dmgtocurrattackerhp
	manipulatedamage DMG_CURR_ATTACKER_HP
	.endm

	.macro setallytonexttarget jumpInstr:req
	jumpifbyte COMPARACION_MAYOR, gBattlerTarget, 0x1, 1f
	addbyte gBattlerTarget, 0x2
	goto \jumpInstr
	1:
	subbyte gBattlerTarget, 0x2
	goto \jumpInstr
	.endm

	.macro setallytonextattacker jumpInstr:req
	jumpifbyte COMPARACION_MAYOR, gBattlerAttacker, 0x1, 1f
	addbyte gBattlerAttacker, 0x2
	goto \jumpInstr
	1:
	subbyte gBattlerAttacker, 0x2
	goto \jumpInstr
	.endm

	.macro jumpifsafeguard jumpInstr:req
	jumpifability BS_ATTACKER, ABILITY_SIGILOSO, 1f
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, \jumpInstr
	1:
	.endm

	@ Tries to increase or decrease a battler's stat's stat stage by a specified amount. If impossible, jumps to \script.
	.macro modifybattlerstatstage battler:req, stat:req, mode:req, amount:req, script:req, animation:req, customString

	@ \mode parameters
	INCREASE = FALSE
	DECREASE = TRUE

	@ \animation parameters
	ANIM_OFF = FALSE
	ANIM_ON = TRUE

	setstatchanger \stat, \amount, \mode
	statbuffchange STAT_CHANGE_ALLOW_PTR, \script
	setgraphicalstatchangevalues
	.if \animation == TRUE
		playanimation \battler, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	.endif
	.ifnb \customString
		EscribeTextoCombate \customString
	.else
		.if \mode == DECREASE
			printfromtable gStatDownStringIds
		.else
		.if \mode == INCREASE
			printfromtable gStatUpStringIds
		.endif
		.endif
	.endif
	waitmessage PAUSA_LARGA
	.endm

	@ Will jump to script pointer if the specified battler has or has not fainted.
	.macro jumpiffainted battler:req, value:req, ptr:req
	getbattlerfainted \battler
	jumpifbyte COMPARACION_IGUAL, gBattleCommunication, \value, \ptr
	.endm

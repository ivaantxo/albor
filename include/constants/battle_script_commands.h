#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

// The following correspond to the struct members of BattleScripting by adding their offset
#define sPAINSPLIT_HP                (gBattleScripting)                 // painSplitHp (s32) -> 4 bytes
#define sMULTIHIT_STRING             (sPAINSPLIT_HP + 4)                // multihitString (u8[6]) -> 6 bytes
#define sB_ANIM_ARG1                 (sMULTIHIT_STRING + 6)             // animArg1 (u8) -> 1 byte
#define sB_ANIM_ARG2                 (sB_ANIM_ARG1 + 1)                 // animArg2 (u8) -> 1 byte
#define sSAVED_STRING_ID             (sB_ANIM_ARG2 + 1)                 // savedStringId (u16) -> 2 bytes
#define sMOVEEND_STATE               (sSAVED_STRING_ID + 2)             // moveendState (u8) -> 1 byte
#define sSHIFT_SWITCHED              (sMOVEEND_STATE + 1)               // shiftSwitched (u8) -> 1 byte
#define sBATTLER                     (sSHIFT_SWITCHED + 1)              // battler (u8) -> 1 byte
#define sB_ANIM_TURN                 (sBATTLER + 1)                     // animTurn (u8) -> 1 byte
#define sB_ANIM_TARGETS_HIT          (sB_ANIM_TURN + 1)                 // animTargetsHit (u8) -> 1 byte
#define sSTATCHANGER                 (sB_ANIM_TARGETS_HIT + 1)          // statChanger (u8) -> 1 byte
#define sSTAT_ANIM_PLAYED            (sSTATCHANGER + 1)                 // statAnimPlayed (bool8) -> 1 byte
#define sGIVEEXP_STATE               (sSTAT_ANIM_PLAYED + 1)            // getexpState (u8) -> 1 byte
#define sLVLBOX_STATE                (sGIVEEXP_STATE + 1)               // drawlvlupboxState (u8) -> 1 byte
#define sLEARNMOVE_STATE             (sLVLBOX_STATE + 1)                // learnMoveState (u8) -> 1 byte
#define sSAVED_BATTLER               (sLEARNMOVE_STATE + 1)             // savedBattler (u8) -> 1 byte
#define sLVLUP_HP                    (sSAVED_BATTLER + 1)               // levelUpHP (u8) -> 1 byte
#define sMON_CAUGHT                  (sLVLUP_HP + 1)                    // monCaught (bool8) -> 1 byte
#define sSAVED_DMG                   (sMON_CAUGHT + 1)                  // savedDmg (s32) -> 4 bytes
#define sSAVED_MOVE_EFFECT           (sSAVED_DMG + 4)                   // savedMoveEffect (u16) -> 2 bytes
#define sMOVE_EFFECT                 (sSAVED_MOVE_EFFECT + 2)           // moveEffect (u16) -> 2 bytes
#define sMULTIHIT_EFFECT             (sMOVE_EFFECT + 2)                 // multihitMoveEffect (u16) -> 2 bytes
#define sFIXED_ABILITY_POPUP         (sMULTIHIT_EFFECT + 2)             // fixedPopup (bool8) -> 1 byte
#define sABILITY_OVERWRITE           (sFIXED_ABILITY_POPUP + 1)         // abilityPopupOverwrite (u16) -> 2 bytes
#define sSWITCH_CASE                 (sABILITY_OVERWRITE + 2)           // switchCase (u8) -> 1 byte
#define sBERRY_OVERRIDE              (sSWITCH_CASE + 1)                 // overrideBerryRequirements (u8) -> 1 byte
#define sSTICKY_WEB_STAT_DROP        (sBERRY_OVERRIDE + 1)              // stickyWebStatDrop (u8) -> 1 byte

enum ScriptsBatallaCombatientes
{
    BS_TARGET,
    BS_ATTACKER,
    BS_EFFECT_BATTLER,
    BS_ATTACKER_WITH_PARTNER,   //  updatestatusicon
    BS_FAINTED_MULTIPLE_1,      //  openpartyscreen
    BS_FAINTED_MULTIPLE_2,      //  openpartyscreen
    BS_BATTLER_0,
    BS_ATTACKER_SIDE,           //  jumpifability
    BS_TARGET_SIDE,             //  jumpifability
    BS_SCRIPTING,
    BS_OPPONENT,
    BS_ABILITY_BATTLER,
    BS_ATTACKER_PARTNER,
};

// BATTLE_CMD_accuracycheck
#define NO_ACC_CALC_CHECK_LOCK_ON 0xFFFF
#define ACC_CURR_MOVE 0

enum Comparaciones
{
    COMPARACION_IGUAL,
    COMPARACION_DESIGUAL,
    COMPARACION_MAYOR,
    COMPARACION_MENOR,
    COMPARACION_BITS_COMUNES,
    COMPARACION_BITS_DISTINTOS,
};

enum Various
{
    VARIOUS_CANCEL_MULTI_TURN_MOVES,
    VARIOUS_SET_MAGIC_COAT_TARGET,
    VARIOUS_GET_MOVE_TARGET,
    VARIOUS_GET_BATTLER_FAINTED,
    VARIOUS_RESET_SWITCH_IN_ABILITY_BITS,
    VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP,
    VARIOUS_RESET_PLAYER_FAINTED,
    VARIOUS_EMIT_YESNOBOX,
    VARIOUS_WAIT_CRY,
    VARIOUS_RETURN_OPPONENT_MON1,
    VARIOUS_RETURN_OPPONENT_MON2,
    VARIOUS_VOLUME_DOWN,
    VARIOUS_VOLUME_UP,
    VARIOUS_SET_TELEPORT_OUTCOME,
    VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC,
    VARIOUS_STAT_TEXT_BUFFER,
    VARIOUS_SWITCHIN_ABILITIES,
    VARIOUS_INSTANT_HP_DROP,
    VARIOUS_CLEAR_STATUS,
    VARIOUS_RESTORE_PP,
    VARIOUS_INTENTA_ACTIVAR_AUTOESTIMA,
    VARIOUS_TRY_ACTIVATE_FELL_STINGER,
    VARIOUS_PLAY_MOVE_ANIMATION,
    VARIOUS_SET_LUCKY_CHANT,
    VARIOUS_GOLPE_BAJO_CHECK,
    VARIOUS_SET_SIMPLE_BEAM,
    VARIOUS_SET_LAST_USED_ABILITY,
    VARIOUS_INVERT_STAT_STAGES,
    VARIOUS_JUMP_IF_BATTLE_END,
    VARIOUS_TRY_REFLECT_TYPE,
    VARIOUS_TRY_LAST_RESORT,
    VARIOUS_SET_ARG_TO_BATTLE_DAMAGE,
    VARIOUS_TRY_HIT_SWITCH_TARGET,
    VARIOUS_TRY_AUTOTOMIZE,
    VARIOUS_ABILITY_POPUP,
    VARIOUS_JUMP_IF_TARGET_ALLY,
    VARIOUS_TRY_SYNCHRONOISE,
    VARIOUS_PSYCHO_SHIFT,
    VARIOUS_CURE_STATUS,
    VARIOUS_POWER_TRICK,
    VARIOUS_AFTER_YOU,
    VARIOUS_BESTOW,
    VARIOUS_JUMP_IF_NOT_GROUNDED,
    VARIOUS_HANDLE_TRAINER_SLIDE_MSG,
    VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF,
    VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON,
    VARIOUS_SET_AURORA_VEIL,
    VARIOUS_ACUPRESSURE,
    VARIOUS_SET_POWDER,
    VARIOUS_SPECTRAL_THIEF,
    VARIOUS_GRAVITY_ON_AIRBORNE_MONS,
    VARIOUS_JUMP_IF_ROAR_FAILS,
    VARIOUS_TRY_INSTRUCT,
    VARIOUS_JUMP_IF_NOT_BERRY,
    VARIOUS_TRACE_ABILITY,
    VARIOUS_UPDATE_NICK,
    VARIOUS_HANDLE_FORM_CHANGE,
    VARIOUS_GET_STAT_VALUE,
    VARIOUS_JUMP_IF_FULL_HP,
    VARIOUS_LOSE_TYPE,
    VARIOUS_TRY_ACTIVATE_SOULHEART,
    VARIOUS_TRY_ACTIVATE_RECEIVER,
    VARIOUS_TRY_ACTIVATE_BEAST_BOOST,
    VARIOUS_TRY_FRISK,
    VARIOUS_TRY_FAIRY_LOCK,
    VARIOUS_JUMP_IF_NO_ALLY,
    VARIOUS_POISON_TYPE_IMMUNITY,
    VARIOUS_JUMP_IF_HOLD_EFFECT,
    VARIOUS_INFATUATE_WITH_BATTLER,
    VARIOUS_SET_LAST_USED_ITEM,
    VARIOUS_PARALYZE_TYPE_IMMUNITY,
    VARIOUS_JUMP_IF_ABSENT,
    VARIOUS_DESTROY_ABILITY_POPUP,
    VARIOUS_MOVEEND_ITEM_EFFECTS,
    VARIOUS_MAKE_INVISIBLE,
    VARIOUS_ROOM_SERVICE,
    VARIOUS_EERIE_SPELL_PP_REDUCE,
    VARIOUS_JUMP_IF_TEAM_HEALTHY,
    VARIOUS_TRY_HEAL_QUARTER_HP,
    VARIOUS_JUMP_IF_PRANKSTER_BLOCKED,
    VARIOUS_GET_ROTOTILLER_TARGETS,
    VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED,
    VARIOUS_CONSUME_BERRY,
    VARIOUS_JUMP_IF_SPECIES,
    VARIOUS_UPDATE_ABILITY_POPUP,
    VARIOUS_JUMP_IF_WEATHER_AFFECTED,
    VARIOUS_SET_ATTACKER_STICKY_WEB_USER,
    VARIOUS_TRY_NO_RETREAT,
    VARIOUS_TRY_TAR_SHOT,
    VARIOUS_CAN_TAR_SHOT_WORK,
    VARIOUS_CHECK_POLTERGEIST,
    VARIOUS_CUT_1_3_HP_RAISE_STATS,
    VARIOUS_TRY_END_NEUTRALIZING_GAS,
    VARIOUS_JUMP_IF_UNDER_200,
    VARIOUS_CURE_CERTAIN_STATUSES,
    VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES,
    VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY,
    VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT,
    VARIOUS_SAVE_BATTLER_ITEM,
    VARIOUS_RESTORE_BATTLER_ITEM,
    VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM,
    VARIOUS_SWAP_STATS,
    VARIOUS_TRY_ACTIVATE_CARNIVORO,
};

// BATTLE_CMD_manipulatedamage
#define DMG_CHANGE_SIGN            0
#define DMG_RECOIL_FROM_MISS       1
#define DMG_DOUBLED                2
#define DMG_1_8_TARGET_HP          3
#define DMG_FULL_ATTACKER_HP       4
#define DMG_CURR_ATTACKER_HP       5
#define DMG_BIG_ROOT               6
#define DMG_RECOIL_FROM_IMMUNE     7 // Used to calculate recoil for the Gen 4 version of Jump Kick

// BATTLE_CMD_jumpifcantswitch
#define SWITCH_IGNORE_ESCAPE_PREVENTION   (1 << 7)

// BATTLE_CMD_statbuffchange
#define STAT_CHANGE_ALLOW_PTR               (1 << 0)   // If set, allow use of jumpptr. Set in every use of statbuffchange
#define STAT_CHANGE_MIRROR_ARMOR            (1 << 1)   // Stat change redirection caused by Mirror Armor ability.
#define STAT_CHANGE_NOT_PROTECT_AFFECTED    (1 << 5)
#define STAT_CHANGE_UPDATE_MOVE_EFFECT      (1 << 6)

// stat change flags for BATTLE_CMD_playstatchangeanimation
#define STAT_CHANGE_NEGATIVE             (1 << 0)
#define STAT_CHANGE_BY_TWO               (1 << 1)
#define STAT_CHANGE_MULTIPLE_STATS       (1 << 2)
#define STAT_CHANGE_CANT_PREVENT         (1 << 3)

// stat flags for BATTLE_CMD_playstatchangeanimation
#define BIT_HP                      (1 << 0)
#define BIT_ATK                     (1 << 1)
#define BIT_DEF                     (1 << 2)
#define BIT_SPEED                   (1 << 3)
#define BIT_SPATK                   (1 << 4)
#define BIT_SPDEF                   (1 << 5)
#define BIT_ACC                     (1 << 6)
#define BIT_EVASION                 (1 << 7)

#define PARTY_SCREEN_OPTIONAL (1 << 7) // Flag for first argument to openpartyscreen

// cases for BATTLE_CMD_moveend
enum MoveEndEffects
{
    MOVEEND_SUM_DAMAGE,
    MOVEEND_PROTECT_LIKE_EFFECT,
    MOVEEND_RAGE,
    MOVEEND_SYNCHRONIZE_TARGET,
    MOVEEND_ABILITIES,
    MOVEEND_ABILITIES_ATTACKER,
    MOVEEND_STATUS_IMMUNITY_ABILITIES,
    MOVEEND_SYNCHRONIZE_ATTACKER,
    MOVEEND_CHOICE_MOVE,
    MOVEEND_ATTACKER_INVISIBLE,
    MOVEEND_ATTACKER_VISIBLE,
    MOVEEND_TARGET_VISIBLE,
    MOVEEND_ITEM_EFFECTS_TARGET,
    MOVEEND_MOVE_EFFECTS2,
    MOVEEND_ITEM_EFFECTS_ALL,
    MOVEEND_NUM_HITS,
    MOVEEND_SUBSTITUTE,
    MOVEEND_UPDATE_LAST_MOVES,
    MOVEEND_MIRROR_MOVE,
    MOVEEND_NEXT_TARGET, // Everything up until here is handled for each strike of a multi-hit move
    MOVEEND_MULTIHIT_MOVE,
    MOVEEND_RECOIL,
    MOVEEND_ITEM_EFFECTS_ATTACKER,
    MOVEEND_EJECT_ITEMS,
    MOVEEND_WHITE_HERB,
    MOVEEND_RED_CARD,
    MOVEEND_LIFEORB_SHELLBELL, // Includes shell bell, throat spray, etc
    MOVEEND_CHANGED_ITEMS,
    MOVEEND_PICKPOCKET,
    MOVEEND_SYMBIOSIS,
    MOVEEND_OPPORTUNIST, // Occurs after other stat change items/abilities to try and copy the boosts
    MOVEEND_SAME_MOVE_TURNS,
    MOVEEND_CLEAR_BITS,
    MOVEEND_COUNT,
};

// switch cases
#define B_SWITCH_NORMAL     0
#define B_SWITCH_HIT        1   // dragon tail, circle throw
#define B_SWITCH_RED_CARD   2

enum BattleScriptCommands
{
    BATTLE_CMD_attackcanceler,
    BATTLE_CMD_accuracycheck,
    BATTLE_CMD_attackstring,
    BATTLE_CMD_ppreduce,
    BATTLE_CMD_critcalc,
    BATTLE_CMD_damagecalc,
    BATTLE_CMD_typecalc,
    BATTLE_CMD_adjustdamage,
    BATTLE_CMD_multihitresultmessage,
    BATTLE_CMD_attackanimation,
    BATTLE_CMD_waitanimation,
    BATTLE_CMD_healthbarupdate,
    BATTLE_CMD_datahpupdate,
    BATTLE_CMD_critmessage,
    BATTLE_CMD_HazSonidoEfectividad,
    BATTLE_CMD_resultmessage,
    BATTLE_CMD_printstring,
    BATTLE_CMD_printselectionstring,
    BATTLE_CMD_waitmessage,
    BATTLE_CMD_printfromtable,
    BATTLE_CMD_setadditionaleffects,
    BATTLE_CMD_seteffectprimary,
    BATTLE_CMD_seteffectsecondary,
    BATTLE_CMD_clearstatusfromeffect,
    BATTLE_CMD_tryfaintmon,
    BATTLE_CMD_dofaintanimation,
    BATTLE_CMD_cleareffectsonfaint,
    BATTLE_CMD_jumpifstatus,
    BATTLE_CMD_jumpifstatus2,
    BATTLE_CMD_jumpifability,
    BATTLE_CMD_jumpifsideaffecting,
    BATTLE_CMD_jumpifstat,
    BATTLE_CMD_jumpifstatus3condition,
    BATTLE_CMD_jumpbasedontype,
    BATTLE_CMD_getexp,
    BATTLE_CMD_checkteamslost,
    BATTLE_CMD_movevaluescleanup,
    BATTLE_CMD_setmultihit,
    BATTLE_CMD_decrementmultihit,
    BATTLE_CMD_goto,
    BATTLE_CMD_jumpifbyte,
    BATTLE_CMD_jumpifhalfword,
    BATTLE_CMD_jumpifword,
    BATTLE_CMD_jumpifarrayequal,
    BATTLE_CMD_jumpifarraynotequal,
    BATTLE_CMD_setbyte,
    BATTLE_CMD_addbyte,
    BATTLE_CMD_subbyte,
    BATTLE_CMD_copyarray,
    BATTLE_CMD_copyarraywithindex,
    BATTLE_CMD_orbyte,
    BATTLE_CMD_orhalfword,
    BATTLE_CMD_orword,
    BATTLE_CMD_bicbyte,
    BATTLE_CMD_bichalfword,
    BATTLE_CMD_bicword,
    BATTLE_CMD_pause,
    BATTLE_CMD_waitstate,
    BATTLE_CMD_healthbar_update,
    BATTLE_CMD_return,
    BATTLE_CMD_end,
    BATTLE_CMD_end2,
    BATTLE_CMD_end3,
    BATTLE_CMD_call,
    BATTLE_CMD_setroost,
    BATTLE_CMD_jumpifabilitypresent,
    BATTLE_CMD_endselectionscript,
    BATTLE_CMD_playanimation,
    BATTLE_CMD_playanimation_var,
    BATTLE_CMD_setgraphicalstatchangevalues,
    BATTLE_CMD_playstatchangeanimation,
    BATTLE_CMD_moveend,
    BATTLE_CMD_sethealblock,
    BATTLE_CMD_returnatktoball,
    BATTLE_CMD_getswitchedmondata,
    BATTLE_CMD_switchindataupdate,
    BATTLE_CMD_switchinanim,
    BATTLE_CMD_jumpifcantswitch,
    BATTLE_CMD_openpartyscreen,
    BATTLE_CMD_switchhandleorder,
    BATTLE_CMD_switchineffects,
    BATTLE_CMD_trainerslidein,
    BATTLE_CMD_playse,
    BATTLE_CMD_fanfare,
    BATTLE_CMD_playfaintcry,
    BATTLE_CMD_returntoball,
    BATTLE_CMD_handlelearnnewmove,
    BATTLE_CMD_yesnoboxlearnmove,
    BATTLE_CMD_yesnoboxstoplearningmove,
    BATTLE_CMD_hitanimation,
    BATTLE_CMD_getmoneyreward,
    BATTLE_CMD_callnative,
    BATTLE_CMD_swapattackerwithtarget,
    BATTLE_CMD_incrementgamestat,
    BATTLE_CMD_drawpartystatussummary,
    BATTLE_CMD_hidepartystatussummary,
    BATTLE_CMD_jumptocalledmove,
    BATTLE_CMD_statusanimation,
    BATTLE_CMD_status2animation,
    BATTLE_CMD_chosenstatusanimation,
    BATTLE_CMD_yesnobox,
    BATTLE_CMD_cancelallactions,
    BATTLE_CMD_setgravity,
    BATTLE_CMD_removeitem,
    BATTLE_CMD_atknameinbuff1,
    BATTLE_CMD_drawlvlupbox,
    BATTLE_CMD_resetsentmonsvalue,
    BATTLE_CMD_setatktoplayer0,
    BATTLE_CMD_makevisible,
    BATTLE_CMD_recordability,
    BATTLE_CMD_buffermovetolearn,
    BATTLE_CMD_hpthresholds,
    BATTLE_CMD_hpthresholds2,
    BATTLE_CMD_useitemonopponent,
    BATTLE_CMD_various,
    BATTLE_CMD_setprotectlike,
    BATTLE_CMD_tryexplosion,
    BATTLE_CMD_setatkhptozero,
    BATTLE_CMD_jumpifnexttargetvalid,
    BATTLE_CMD_tryhealhalfhealth,
    BATTLE_CMD_trymirrormove,
    BATTLE_CMD_setfieldweather,
    BATTLE_CMD_setreflect,
    BATTLE_CMD_setseeded,
    BATTLE_CMD_manipulatedamage,
    BATTLE_CMD_trysetrest,
    BATTLE_CMD_jumpifnotfirstturn,
    BATTLE_CMD_setmiracleeye,
    BATTLE_CMD_jumpifuproarwakes,
    BATTLE_CMD_stockpile,
    BATTLE_CMD_stockpiletobasedamage,
    BATTLE_CMD_stockpiletohpheal,
    BATTLE_CMD_setdrainedhp,
    BATTLE_CMD_statbuffchange,
    BATTLE_CMD_normalisebuffs,
    BATTLE_CMD_forcerandomswitch,
    BATTLE_CMD_tryconversiontypechange,
    BATTLE_CMD_givepaydaymoney,
    BATTLE_CMD_setlightscreen,
    BATTLE_CMD_damagetohalftargethp,
    BATTLE_CMD_tryinfatuating,
    BATTLE_CMD_updatestatusicon,
    BATTLE_CMD_setmist,
    BATTLE_CMD_setfocusenergy,
    BATTLE_CMD_transformdataexecution,
    BATTLE_CMD_setsubstitute,
    BATTLE_CMD_mimicattackcopy,
    BATTLE_CMD_dmgtolevel,
    BATTLE_CMD_counterdamagecalculator,
    BATTLE_CMD_mirrorcoatdamagecalculator,
    BATTLE_CMD_disablelastusedattack,
    BATTLE_CMD_trysetencore,
    BATTLE_CMD_painsplitdmgcalc,
    BATTLE_CMD_settypetorandomresistance,
    BATTLE_CMD_setalwayshitflag,
    BATTLE_CMD_trychoosesleeptalkmove,
    BATTLE_CMD_setdestinybond,
    BATTLE_CMD_trysetdestinybondtohappen,
    BATTLE_CMD_settailwind,
    BATTLE_CMD_tryspiteppreduce,
    BATTLE_CMD_healpartystatus,
    BATTLE_CMD_cursetarget,
    BATTLE_CMD_trysetspikes,
    BATTLE_CMD_setforesight,
    BATTLE_CMD_trysetperishsong,
    BATTLE_CMD_handlerollout,
    BATTLE_CMD_jumpifconfusedandstatmaxed,
    BATTLE_CMD_handlefurycutter,
    BATTLE_CMD_setembargo,
    BATTLE_CMD_presentdamagecalculation,
    BATTLE_CMD_setsafeguard,
    BATTLE_CMD_magnitudedamagecalculation,
    BATTLE_CMD_jumpifnopursuitswitchdmg,
    BATTLE_CMD_halvehp,
    BATTLE_CMD_copyfoestats,
    BATTLE_CMD_girorapidofree,
    BATTLE_CMD_setdefensecurlbit,
    BATTLE_CMD_recoverbasedonsunlight,
    BATTLE_CMD_setstickyweb,
    BATTLE_CMD_selectfirstvalidtarget,
    BATTLE_CMD_trysetfutureattack,
    BATTLE_CMD_intentaataqueequipo,
    BATTLE_CMD_setsemiinvulnerablebit,
    BATTLE_CMD_tryfiretwoturnmovenowbyeffect,
    BATTLE_CMD_setminimize,
    BATTLE_CMD_trymemento,
    BATTLE_CMD_setforcedtarget,
    BATTLE_CMD_setcharge,
    BATTLE_CMD_cureifburnedparalysedorpoisoned,
    BATTLE_CMD_settorment,
    BATTLE_CMD_jumpifnodamage,
    BATTLE_CMD_settaunt,
    BATTLE_CMD_tryswapitems,
    BATTLE_CMD_trycopyability,
    BATTLE_CMD_trywish,
    BATTLE_CMD_settoxicspikes,
    BATTLE_CMD_setgastroacid,
    BATTLE_CMD_setyawn,
    BATTLE_CMD_setdamagetohealthdifference,
    BATTLE_CMD_setroom,
    BATTLE_CMD_tryswapabilities,
    BATTLE_CMD_tryimprison,
    BATTLE_CMD_setstealthrock,
    BATTLE_CMD_setuserstatus3,
    BATTLE_CMD_assistattackselect,
    BATTLE_CMD_trysetmagiccoat,
    BATTLE_CMD_trysetsnatch,
    BATTLE_CMD_switchoutabilities,
    BATTLE_CMD_jumpifhasnohp,
    BATTLE_CMD_jumpifnotcurrentmoveargtype,
    BATTLE_CMD_jumpifsubstituteblocks,
    BATTLE_CMD_tryrecycleitem,
    BATTLE_CMD_snatchsetbattlers,
    BATTLE_CMD_EliminaPantallas,
    BATTLE_CMD_handleballthrow,
    BATTLE_CMD_givecaughtmon,
    BATTLE_CMD_trysetcaughtmondexflags,
    BATTLE_CMD_displaydexinfo,
    BATTLE_CMD_trygivecaughtmonnick,
    BATTLE_CMD_subattackerhpbydmg,
    BATTLE_CMD_removeattackerstatus1,
    BATTLE_CMD_finishaction,
    BATTLE_CMD_finishturn,
    BATTLE_CMD_trainerslideout,
    BATTLE_CMD_settelekinesis,
    BATTLE_CMD_swapstatstages,
    BATTLE_CMD_averagestats,
    BATTLE_CMD_jumpifoppositegenders,
};

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

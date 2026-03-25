#ifndef GUARD_CONSTANTS_BATTLE_STRING_IDS_H
#define GUARD_CONSTANTS_BATTLE_STRING_IDS_H

enum TextosCombate
{
    TEXTO_COMBATE_INTRO, //dinámico
    TEXTO_COMBATE_ENVIAR_POKEMON, // dinámico
    STRINGID_RETURNMON, // dinámico
    STRINGID_SWITCHINMON, // dinámico
    STRINGID_USEDMOVE, // buffer
    STRINGID_TRAINERSLIDE, // buffer
    STRINGID_PKMNGAINEDEXP, // PrepareString
    STRINGID_PKMNLEARNEDMOVE, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_TRYTOLEARNMOVE1, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_TRYTOLEARNMOVE2, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_TRYTOLEARNMOVE3, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_PKMNFORGOTMOVE, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_STOPLEARNINGMOVE, // BattleStringExpandPlaceholdersToDisplayedString
    STRINGID_DIDNOTLEARNMOVE, // BattleStringExpandPlaceholdersToDisplayedString
    TEXTO_COMBATE_ATAQUE_FALLO_ATACANTE, // gMensajeBatalla
    TEXTO_COMBATE_ATAQUE_FALLO_DEFENSOR, // gMensajeBatalla
    TEXTO_COMBATE_PROTECCION, // gMensajeBatalla
    STRINGID_STATSWONTINCREASE2, // PrepareStringBattle
    TEXTO_COMBATE_TELEPATA, // gMensajeBatalla
    STRINGID_ITDOESNTAFFECT, // PrepareStringBattle
    STRINGID_PKMNFELLASLEEP, // printfromtable
    STRINGID_PKMNMADESLEEP, // printfromtable
    STRINGID_PKMNWASNTAFFECTED, // PrepareStringBattle
    STRINGID_PKMNWASPOISONED, // printfromtable
    STRINGID_PKMNPOISONEDBY, // printfromtable
    STRINGID_PKMNBADLYPOISONED, // printfromtable
    STRINGID_PKMNENERGYDRAINED, // printfromtable
    STRINGID_PKMNWASBURNED, // printfromtable
    STRINGID_PKMNBURNEDBY, // printfromtable
    STRINGID_PKMNWASPARALYZED, //printfromtable
    STRINGID_PKMNWASPARALYZEDBY, //printfromtable
    STRINGID_STATSWONTINCREASE, //printstring + PrepareStringBattle
    STRINGID_STATSWONTDECREASE,//printstring + PrepareStringBattle
    STRINGID_PKMNWASCONFUSED,//printstring + printfromtable
    STRINGID_PKMNFELLINLOVE,//printstring + printfromtable
    STRINGID_PKMNHPFULL, //printstrign + printfromtable
    STRINGID_PKMNRAISEDSPDEF, //printfromtable
    STRINGID_PKMNRAISEDDEF, //printfromtable
    STRINGID_PKMNCOVEREDBYVEIL, //printfromtable
    STRINGID_PKMNWENTTOSLEEP, //printfromtable
    STRINGID_PKMNSLEPTHEALTHY, //printfromtable
    STRINGID_PKMNTOOKSUNLIGHT, //TWO_TURN_ARG
    STRINGID_PKMNLOWEREDHEAD,//TWO_TURN_ARG
    STRINGID_PKMNFLEWHIGH, //TWO_TURN_ARG
    STRINGID_PKMNDUGHOLE, //TWO_TURN_ARG
    STRINGID_PKMNSQUEEZEDBYBIND, //printfromtable
    STRINGID_PKMNTRAPPEDINVORTEX, //printfromtable
    STRINGID_PKMNWRAPPEDBY,//printfromtable
    STRINGID_PKMNSHROUDEDINMIST, //printstring + printfromtable
    STRINGID_PKMNBUFFETEDBYSANDSTORM,//printstring + printfromtable
    STRINGID_PKMNPELTEDBYHAIL,//printstring + printfromtable
    STRINGID_PKMNSEEDED,//printstring + printfromtable
    STRINGID_PKMNEVADEDATTACK,//printstring + printfromtable
    STRINGID_PKMNSAPPEDBYLEECHSEED,//printstring + printfromtable
    STRINGID_PKMNMAKINGUPROAR, //printfromtable
    STRINGID_PKMNCALMEDDOWN, //printfromtable
    STRINGID_PKMNSTOCKPILED, //printfromtable
    STRINGID_PKMNCANTSTOCKPILE, //printfromtable
    STRINGID_PKMNCANTSLEEPINUPROAR2, //printfromtable
    STRINGID_UPROARKEPTPKMNAWAKE, //printfromtable
    STRINGID_PKMNTRANSFORMEDINTO, //printfromtable
    STRINGID_PKMNMADESUBSTITUTE, // printfromtable
    STRINGID_SUBSTITUTEDAMAGED, // PrepareStringBattle
    STRINGID_PKMNMOVEISDISABLED, //printstring + printselectionstring
    STRINGID_PKMNMOVEDISABLEDNOMORE, //printstring + printselectionstring
    STRINGID_PKMNENCOREENDED, //printstring + printfromtable
    STRINGID_TARGETCANTESCAPENOW, //printstring + printselectionstring
    STRINGID_PKMNHASNOMOVESLEFT, //printselectionstring
    STRINGID_PKMNSUBJECTEDTOTORMENT, //printstring + printfromtable
    STRINGID_PKMNCANTUSEMOVETORMENT, //printstring + printselectionstring
    STRINGID_PKMNCANTUSEMOVETAUNT, //printstring + printselectionstring
    STRINGID_ATTACKERSSTATROSE,//printfromtable
    STRINGID_DEFENDERSSTATROSE, //printstring + printfromtable
    STRINGID_ATTACKERSSTATFELL, //printfromtable
    STRINGID_DEFENDERSSTATFELL, //printfromtable + preparestringbattle
    STRINGID_CRITICALHIT, //PrepareStringBattle
    STRINGID_ONEHITKO, //printstring + resultmessage
    STRINGID_123POOF,//printstring + evolution
    STRINGID_ANDELLIPSIS, //printstring + evolution
    STRINGID_NOTVERYEFFECTIVE, //resultmessage
    STRINGID_SUPEREFFECTIVE,//resultmessage
    STRINGID_ITEMALLOWSONLYYMOVE, //PRINTSELECTIONSTRING
    STRINGID_PKMNSXPREVENTSBURNS, //printfromtable
    STRINGID_PKMNSXINFATUATEDY, //printstring + printfromtable
    STRINGID_PKMNSXMADEYINEFFECTIVE, //printstring + printfromtable
    STRINGID_ITSUCKEDLIQUIDOOZE, //printfromtable
    STRINGID_PKMNHIDUNDERWATER, //two_turn_arg
    STRINGID_PKMNSPRANGUP,//two_turn_arg
    STRINGID_SOOTHINGAROMA, //printfromtable
    STRINGID_ITEMSCANTBEUSEDNOW, //printselectionstring
    STRINGID_USINGITEMSTATOFPKMNROSE, //printstring + printfromtable
    STRINGID_PKMNUSEDXTOGETPUMPED, //printstring + printfromtable
    STRINGID_PKMNTRAPPEDBYSANDTOMB, //printstring + printfromtable
    TEXTO_COMBATE_LEVITACION, // revisar
    STRINGID_PKMNCHOSEXASDESTINY, //printfromtable
    STRINGID_PKMNSITEMNORMALIZEDSTATUS, //printfromtable
    STRINGID_BOXISFULL, //printselectionstring
    STRINGID_THUNDERCAGETRAPPED, //printfromtable
    STRINGID_STARTEDSNOW, //printfromtable
    STRINGID_SNOWCONTINUES, // printfromtable
    STRINGID_SNOWSTOPPED, //printfromtable
    STRINGID_CURRENTMOVECANTSELECT, //printselectionstring
    STRINGID_ELECTROSHOTCHARGING, //TWO_TURN_ARG
    STRINGID_GENERADOR, //printfromtable
    STRINGID_FOGCREPTUP,//printfromtable
    STRINGID_FOGISDEEP,//printstring + printfromtable
    STRINGID_FOGLIFTED,//printstring + printfromtable
    STRINGID_ITISSNOWING, //printfromtable
    STRINGID_HACEMUCHOCALOR, //printstring + printfromtable
    STRINGID_NOPPLEFT, //printselectionstring
    STRINGID_ITISRAINING, //printfromtable
    STRINGID_SANDSTORMISRAGING, //printfromtable
    STRINGID_PKMNOBTAINEDX,//printfromtable
    STRINGID_PKMNOBTAINEDX2, //printfromtable
    STRINGID_PKMNOBTAINEDXYOBTAINEDZ, //printfromtable
    STRINGID_PKMNSXHADNOEFFECTONY, //printfromtable
    STRINGID_QUESTIONFORFEITMATCH, // printselectionstring
    STRINGID_VANISHEDINSTANTLY, //TWO_TURN_ARG
    STRINGID_PROTECTEDTEAM, //printfromtable
    STRINGID_MOLDBREAKERENTERS, //printfromtable
    STRINGID_ASSAULTVESTDOESNTALLOW, //printselectionstring
    STRINGID_GRAVITYPREVENTSUSAGE, //printstring + printselectionstring
    STRINGID_HEALBLOCKPREVENTSUSAGE,//printstring + printselectionstring
    STRINGID_DRASTICALLY, // ChangeStatBuffs
    STRINGID_SEVERELY, // ChangeStatBuffs
    STRINGID_INFESTATION, //printfromtable
    STRINGID_SPIKESSCATTERED, //PRINTSTRING + printfromtable
    STRINGID_PKMNHURTBYSPIKES, //printfromtable
    STRINGID_PKMNBRACEDITSELF, //printfromtable
    STRINGID_PKMNFORESAWATTACK, //printfromtable
    STRINGID_PKMNCANTUSEMOVESEALED, //printstring + printselectionstring
    STRINGID_PKMNPREVENTSPARALYSISWITH, //printfromtable
    STRINGID_PKMNPREVENTSPOISONINGWITH, //printfromtable
    STRINGID_PKMNRAISEDFIREPOWERWITH,//printfromtable
    STRINGID_PKMNCUTSATTACKWITH, //printstring + preparestringbattle
    STRINGID_STATSHARPLY, //changestatbuffs
    STRINGID_STATROSE,//changestatbuffs + bufferstatchange
    STRINGID_STATHARSHLY,//changestatbuffs
    STRINGID_STATFELL,//changestatbuffs + bufferstatchange
    STRINGID_BUTITFAILED, //resultmessage + printfromtable
    STRINGID_STARTEDTORAIN, //printfromtable
    STRINGID_RAINCONTINUES, //printfromtable
    STRINGID_RAINSTOPPED, //printfromtable
    STRINGID_SANDSTORMBREWED, //printfromtable
    STRINGID_SANDSTORMRAGES, //printfromtable
    STRINGID_SANDSTORMSUBSIDED, //printfromtable
    STRINGID_SUNLIGHTGOTBRIGHT,//printfromtable
    STRINGID_SUNLIGHTSTRONG,//printfromtable
    STRINGID_SUNLIGHTFADED,//printfromtable
    STRINGID_STARTEDHAIL,//printfromtable
    STRINGID_HAILCONTINUES,//printfromtable
    STRINGID_HAILSTOPPED,//printfromtable
    STRINGID_FAILEDTOSWALLOW,//printfromtable
    STRINGID_TOOWEAKFORSUBSTITUTE, //printfromtable
    STRINGID_BELLCHIMED, //printfromtable
    STRINGID_PKMNBROKEFREE, //printfromtable
    STRINGID_ITAPPEAREDCAUGHT,//printfromtable
    STRINGID_AARGHALMOSTHADIT,//printfromtable
    STRINGID_PKMNSITEMCUREDPROBLEM, //printfromtable
    STRINGID_STATSWONTDECREASE2, //PrepareStringBattle
    STRINGID_PKMNSXPREVENTSYSZ, //printfromtable
    STRINGID_PKMNTWISTEDDIMENSIONS, //printfromtable
    STRINGID_POINTEDSTONESFLOAT, //printfromtable
    STRINGID_TRAPPEDBYSWIRLINGMAGMA, //printfromtable
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, //printfromtable
    STRINGID_HELDITEMSLOSEEFFECTS, //printfromtable
    STRINGID_ELECTROMAGNETISM, //PrepareStringBattle
    STRINGID_BUFFERENDS, //printfromtable
    STRINGID_TRICKROOMENDS, //printfromtable
    STRINGID_WONDERROOMENDS, //printstring + printfromtable
    STRINGID_MAGICROOMENDS, //printstring + printfromtable
    STRINGID_FOREWARNACTIVATES, //printfromtable
    STRINGID_UNNERVEENTERS, //printfromtable
    STRINGID_STEALTHROCKDMG, //printfromtable
    STRINGID_BELCHCANTSELECT, //printselectionstring
    STRINGID_PKMNCANTUSEMOVETHROATCHOP, //printselectionstring
    STRINGID_CLOAKEDINAFREEZINGLIGHT, //two_turn
    STRINGID_SCREENCLEANERENTERS, //printfromtable
    STRINGID_CURIOUSMEDICINEENTERS, //printfromtable
    STRINGID_ATKGOTOVERINFATUATION, //printfromtable
    STRINGID_TORMENTEDNOMORE, //printfromtable
    STRINGID_HEALBLOCKEDNOMORE, //printstring + printfromtable
    STRINGID_STUFFCHEEKSCANTSELECT, //printselectionstring
    STRINGID_ABILITYALLOWSONLYMOVE, //printselectionstring
    STRINGID_NEUTRALIZINGGASENTERS, //printfromtable
    STRINGID_METEORBEAMCHARGING, //two_turn_arg

    NUMERO_TEXTOS_COMBATE,
};

// The below IDs are all indexes into battle message tables,
// used to determine which of a set of messages to print.
// They are assigned to gMensajeBatalla
// and read when e.g. the command printfromtable is used.

// gStatUpStringIds
#define B_MSG_ATTACKER_STAT_ROSE 0
#define B_MSG_DEFENDER_STAT_ROSE 1
#define B_MSG_STAT_WONT_INCREASE 2
#define B_MSG_STAT_ROSE_EMPTY    3
#define B_MSG_STAT_ROSE_ITEM     4
#define B_MSG_USED_DIRE_HIT      5

// gStatDownStringIds
#define B_MSG_ATTACKER_STAT_FELL 0
#define B_MSG_DEFENDER_STAT_FELL 1
#define B_MSG_STAT_WONT_DECREASE 2
#define B_MSG_STAT_FELL_EMPTY    3

// gAbsorbDrainStringIds
#define B_MSG_ABSORB      0
#define B_MSG_ABSORB_OOZE 1

// gLeechSeedStringIds
#define B_MSG_LEECH_SEED_SET   0
#define B_MSG_LEECH_SEED_MISS  1
#define B_MSG_LEECH_SEED_FAIL  2
#define B_MSG_LEECH_SEED_DRAIN 3
#define B_MSG_LEECH_SEED_OOZE  4

// gMoveWeatherChangeStringIds
#define B_MSG_STARTED_RAIN      0
#define B_MSG_STARTED_DOWNPOUR  1
#define B_MSG_WEATHER_FAILED    2
#define B_MSG_STARTED_SANDSTORM 3
#define B_MSG_STARTED_SUNLIGHT  4
#define B_MSG_STARTED_HAIL      5
#define B_MSG_STARTED_SNOW      6
#define B_MSG_STARTED_FOG       7

// gWeatherEndsStringIds
#define B_MSG_WEATHER_END_RAIN         0
#define B_MSG_WEATHER_END_SANDSTORM    1
#define B_MSG_WEATHER_END_SUN          2
#define B_MSG_WEATHER_END_HAIL         3
#define B_MSG_WEATHER_END_SNOW         5
#define B_MSG_WEATHER_END_FOG          6
#define B_MSG_WEATHER_END_COUNT        7

// gRainContinuesStringIds
#define B_MSG_RAIN_CONTINUES     0
#define B_MSG_RAIN_STOPPED       2

// gSandStormHailSnowContinuesStringIds / gSandStormHailDmgStringIds/ gSandStormHailSnowEndStringIds
#define B_MSG_SANDSTORM  0
#define B_MSG_HAIL       1
#define B_MSG_SNOW       2

// gReflectLightScreenSafeguardStringIds
#define B_MSG_SIDE_STATUS_FAILED     0
#define B_MSG_SET_REFLECT_SINGLE     1
#define B_MSG_SET_REFLECT_DOUBLE     2
#define B_MSG_SET_LIGHTSCREEN_SINGLE 3
#define B_MSG_SET_LIGHTSCREEN_DOUBLE 4
#define B_MSG_SET_SAFEGUARD          5

// gProtectLikeUsedStringIds
#define B_MSG_PROTECTED_ITSELF 0
#define B_MSG_BRACED_ITSELF    1
#define B_MSG_PROTECT_FAILED   2
#define B_MSG_PROTECTED_TEAM   3

// gRestUsedStringIds
#define B_MSG_REST           0
#define B_MSG_REST_STATUSED  1

// gUproarAwakeStringIds
#define B_MSG_CANT_SLEEP_UPROAR  0
#define B_MSG_UPROAR_KEPT_AWAKE  1

// gUproarOverTurnStringIds
#define B_MSG_UPROAR_CONTINUES  0
#define B_MSG_UPROAR_ENDS       1

// gStockpileUsedStringIds
#define B_MSG_STOCKPILED     0
#define B_MSG_CANT_STOCKPILE 1

// gSwallowFailStringIds
#define B_MSG_SWALLOW_FAILED  0
#define B_MSG_SWALLOW_FULL_HP 1

// gMistUsedStringIds
#define B_MSG_SET_MIST    0
#define B_MSG_MIST_FAILED 1

// gTransformUsedStringIds
#define B_MSG_TRANSFORMED      0
#define B_MSG_TRANSFORM_FAILED 1

// gSubstituteUsedStringIds
#define B_MSG_SET_SUBSTITUTE    0
#define B_MSG_SUBSTITUTE_FAILED 1

// gPartyStatusHealStringIds
#define B_MSG_BELL                     0
#define B_MSG_BELL_SOUNDPROOF_ATTACKER 1
#define B_MSG_BELL_SOUNDPROOF_PARTNER  2
#define B_MSG_BELL_BOTH_SOUNDPROOF     3
#define B_MSG_SOOTHING_AROMA           4

// gFutureMoveUsedStringIds
#define B_MSG_FUTURE_SIGHT 0
#define B_MSG_DOOM_DESIRE  1

// gItemSwapStringIds
#define B_MSG_ITEM_SWAP_TAKEN 0
#define B_MSG_ITEM_SWAP_GIVEN 1
#define B_MSG_ITEM_SWAP_BOTH  2

// gFlashFireStringIds
#define B_MSG_FLASH_FIRE_BOOST    0
#define B_MSG_FLASH_FIRE_NO_BOOST 1

// gBerryEffectStringIds
#define B_MSG_CURED_PROBLEM     0
#define B_MSG_NORMALIZED_STATUS 1

// gGotPoisonedStringIds / gGotParalyzedStringIds / gFellAsleepStringIds
// gGotBurnedStringIds / gAttractUsedStringIds
#define B_MSG_STATUSED            0
#define B_MSG_STATUSED_BY_ABILITY 1

// gBRNPreventionStringIds / gPRLZPreventionStringIds / gPSNPreventionStringIds
#define B_MSG_ABILITY_PREVENTS_MOVE_STATUS    0
#define B_MSG_ABILITY_PREVENTS_ABILITY_STATUS 1
#define B_MSG_STATUS_HAD_NO_EFFECT            2

// gSwitchInAbilityStringIds
#define B_MSG_SWITCHIN_MOLDBREAKER      0
#define B_MSG_SWITCHIN_UNNERVE          4
#define B_MSG_SWITCHIN_FOREWARN         6
#define B_MSG_SWITCHIN_SCREENCLEANER    12
#define B_MSG_SWITCHIN_CURIOUS_MEDICINE 14
#define B_MSG_SWITCHIN_NEUTRALIZING_GAS 16
#define B_MSG_SWITCHIN_GENERADOR        17

// gMentalHerbCureStringIds
#define B_MSG_MENTALHERBCURE_INFATUATION       0
#define B_MSG_MENTALHERBCURE_TAUNT             1
#define B_MSG_MENTALHERBCURE_ENCORE            2
#define B_MSG_MENTALHERBCURE_TORMENT           3
#define B_MSG_MENTALHERBCURE_HEALBLOCK         4
#define B_MSG_MENTALHERBCURE_DISABLE           5

// gWrappedStringIds
#define B_MSG_WRAPPED_BIND         0
#define B_MSG_WRAPPED_WRAP         1
#define B_MSG_WRAPPED_FIRE_SPIN    2
#define B_MSG_WRAPPED_WHIRLPOOL    4
#define B_MSG_WRAPPED_SAND_TOMB    5
#define B_MSG_WRAPPED_MAGMA_STORM  6
#define B_MSG_WRAPPED_INFESTATION  7
#define B_MSG_WRAPPED_THUNDER_CAGE 8
#define NUM_TRAPPING_MOVES         9

#endif // GUARD_CONSTANTS_BATTLE_STRING_IDS_H

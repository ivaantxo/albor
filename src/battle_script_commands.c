#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_scripts.h"
#include "bg.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "item.h"
#include "util.h"
#include "pokemon.h"
#include "random.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "text.h"
#include "sound.h"
#include "pokedex.h"
#include "window.h"
#include "reshow_battle_screen.h"
#include "main.h"
#include "palette.h"
#include "money.h"
#include "malloc.h"
#include "bg.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "m4a.h"
#include "mail.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "naming_screen.h"
#include "battle_setup.h"
#include "overworld.h"
#include "wild_encounter.h"
#include "rtc.h"
#include "party_menu.h"
#include "field_specials.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "data.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/flags.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/map_types.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "battle_util.h"
#include "constants/pokemon.h"
#include "config/battle.h"
#include "data/battle_move_effects.h"
#include "constants/battle_script_commands.h"

// table to avoid ugly powing on gba (courtesy of doesnt)
// this returns (i^2.5)/4
// the quarters cancel so no need to re-quadruple them in actual calculation
static const s32 sExperienceScalingFactors[] =
    {
        0,
        0,
        1,
        3,
        8,
        13,
        22,
        32,
        45,
        60,
        79,
        100,
        124,
        152,
        183,
        217,
        256,
        297,
        343,
        393,
        447,
        505,
        567,
        634,
        705,
        781,
        861,
        946,
        1037,
        1132,
        1232,
        1337,
        1448,
        1563,
        1685,
        1811,
        1944,
        2081,
        2225,
        2374,
        2529,
        2690,
        2858,
        3031,
        3210,
        3396,
        3587,
        3786,
        3990,
        4201,
        4419,
        4643,
        4874,
        5112,
        5357,
        5608,
        5866,
        6132,
        6404,
        6684,
        6971,
        7265,
        7566,
        7875,
        8192,
        8515,
        8847,
        9186,
        9532,
        9886,
        10249,
        10619,
        10996,
        11382,
        11776,
        12178,
        12588,
        13006,
        13433,
        13867,
        14310,
        14762,
        15222,
        15690,
        16167,
        16652,
        17146,
        17649,
        18161,
        18681,
        19210,
        19748,
        20295,
        20851,
        21417,
        21991,
        22574,
        23166,
        23768,
        24379,
        25000,
        25629,
        26268,
        26917,
        27575,
        28243,
        28920,
        29607,
        30303,
        31010,
        31726,
        32452,
        33188,
        33934,
        34689,
        35455,
        36231,
        37017,
        37813,
        38619,
        39436,
        40262,
        41099,
        41947,
        42804,
        43673,
        44551,
        45441,
        46340,
        47251,
        48172,
        49104,
        50046,
        50999,
        51963,
        52938,
        53924,
        54921,
        55929,
        56947,
        57977,
        59018,
        60070,
        61133,
        62208,
        63293,
        64390,
        65498,
        66618,
        67749,
        68891,
        70045,
        71211,
        72388,
        73576,
        74777,
        75989,
        77212,
        78448,
        79695,
        80954,
        82225,
        83507,
        84802,
        86109,
        87427,
        88758,
        90101,
        91456,
        92823,
        94202,
        95593,
        96997,
        98413,
        99841,
        101282,
        102735,
        104201,
        105679,
        107169,
        108672,
        110188,
        111716,
        113257,
        114811,
        116377,
        117956,
        119548,
        121153,
        122770,
        124401,
        126044,
        127700,
        129369,
        131052,
        132747,
        134456,
        136177,
        137912,
        139660,
        141421,
        143195,
        144983,
        146784,
        148598,
        150426,
        152267,
        154122,
        155990,
        157872,
        159767,
};

static const u16 sBadgeFlags[8] = {
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static const u16 sWhiteOutBadgeMoney[9] = {8, 16, 24, 36, 48, 64, 80, 100, 120};

#define STAT_CHANGE_WORKED 0
#define STAT_CHANGE_DIDNT_WORK 1

#define LEVEL_UP_BANNER_START 416
#define LEVEL_UP_BANNER_END 512

#define TAG_LVLUP_BANNER_MON_ICON 55130

static void TrySetDestinyBondToHappen(void);
static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr);
static bool32 IsMonGettingExpSentOut(void);
static void InitLevelUpBanner(void);
static bool8 SlideInLevelUpBanner(void);
static bool8 SlideOutLevelUpBanner(void);
static void DrawLevelUpWindow1(void);
static void DrawLevelUpWindow2(void);
static void PutMonIconOnLvlUpBanner(void);
static void DrawLevelUpBannerText(void);
static void SpriteCB_MonIconOnLvlUpBanner(struct Sprite *sprite);
static bool8 IsFinalStrikeEffect(u32 moveEffect);
void ApplyExperienceMultipliers(s32 *expAmount, u8 expGetterMonId, u8 faintedBattler);
static bool8 CanAbilityPreventStatLoss(u16 abilityDef);
static u32 GetNextTarget(u32 moveTarget, bool32 excludeCurrent);
static void AccuracyCheck(bool32 recalcDragonDarts, const u8 *nextInstr, const u8 *failInstr, u16 move);

static void Cmd_attackcanceler(void);
static void Cmd_accuracycheck(void);
static void Cmd_attackstring(void);
static void Cmd_ppreduce(void);
static void Cmd_critcalc(void);
static void Cmd_damagecalc(void);
static void Cmd_typecalc(void);
static void Cmd_adjustdamage(void);
static void Cmd_multihitresultmessage(void);
static void Cmd_attackanimation(void);
static void Cmd_waitanimation(void);
static void Cmd_healthbarupdate(void);
static void Cmd_datahpupdate(void);
static void Cmd_critmessage(void);
static void Cmd_HazSonidoEfectividad(void);
static void Cmd_resultmessage(void);
static void Cmd_EscribeTextoCombate(void);
static void Cmd_printselectionstring(void);
static void Cmd_waitmessage(void);
static void Cmd_printfromtable(void);
static void Cmd_setadditionaleffects(void);
static void Cmd_seteffectprimary(void);
static void Cmd_seteffectsecondary(void);
static void Cmd_clearstatusfromeffect(void);
static void Cmd_tryfaintmon(void);
static void Cmd_dofaintanimation(void);
static void Cmd_cleareffectsonfaint(void);
static void Cmd_jumpifstatus(void);
static void Cmd_jumpifstatus2(void);
static void Cmd_jumpifability(void);
static void Cmd_jumpifsideaffecting(void);
static void Cmd_jumpifstat(void);
static void Cmd_jumpifstatus3condition(void);
static void Cmd_jumpbasedontype(void);
static void Cmd_getexp(void);
static void Cmd_checkteamslost(void);
static void Cmd_movevaluescleanup(void);
static void Cmd_setmultihit(void);
static void Cmd_decrementmultihit(void);
static void Cmd_goto(void);
static void Cmd_jumpifbyte(void);
static void Cmd_jumpifhalfword(void);
static void Cmd_jumpifword(void);
static void Cmd_jumpifarrayequal(void);
static void Cmd_jumpifarraynotequal(void);
static void Cmd_setbyte(void);
static void Cmd_addbyte(void);
static void Cmd_subbyte(void);
static void Cmd_copyarray(void);
static void Cmd_copyarraywithindex(void);
static void Cmd_orbyte(void);
static void Cmd_orhalfword(void);
static void Cmd_orword(void);
static void Cmd_bicbyte(void);
static void Cmd_bichalfword(void);
static void Cmd_bicword(void);
static void Cmd_pause(void);
static void Cmd_waitstate(void);
static void Cmd_healthbar_update(void);
static void Cmd_return(void);
static void Cmd_end(void);
static void Cmd_end2(void);
static void Cmd_end3(void);
static void Cmd_call(void);
static void Cmd_setroost(void);
static void Cmd_jumpifabilitypresent(void);
static void Cmd_endselectionscript(void);
static void Cmd_playanimation(void);
static void Cmd_playanimation_var(void);
static void Cmd_setgraphicalstatchangevalues(void);
static void Cmd_playstatchangeanimation(void);
static void Cmd_moveend(void);
static void Cmd_returnatktoball(void);
static void Cmd_getswitchedmondata(void);
static void Cmd_switchindataupdate(void);
static void Cmd_switchinanim(void);
static void Cmd_jumpifcantswitch(void);
static void Cmd_openpartyscreen(void);
static void Cmd_switchhandleorder(void);
static void Cmd_switchineffects(void);
static void Cmd_trainerslidein(void);
static void Cmd_playse(void);
static void Cmd_fanfare(void);
static void Cmd_playfaintcry(void);
static void Cmd_returntoball(void);
static void Cmd_handlelearnnewmove(void);
static void Cmd_yesnoboxlearnmove(void);
static void Cmd_yesnoboxstoplearningmove(void);
static void Cmd_hitanimation(void);
static void Cmd_getmoneyreward(void);
static void Cmd_swapattackerwithtarget(void);
static void Cmd_incrementgamestat(void);
static void Cmd_drawpartystatussummary(void);
static void Cmd_hidepartystatussummary(void);
static void Cmd_statusanimation(void);
static void Cmd_status2animation(void);
static void Cmd_chosenstatusanimation(void);
static void Cmd_yesnobox(void);
static void Cmd_CancelaAccionesSiNoEntrenador(void);
static void Cmd_removeitem(void);
static void Cmd_atknameinbuff1(void);
static void Cmd_drawlvlupbox(void);
static void Cmd_resetsentmonsvalue(void);
static void Cmd_setatktoplayer0(void);
static void Cmd_makevisible(void);
static void Cmd_recordability(void);
static void Cmd_buffermovetolearn(void);
static void Cmd_hpthresholds(void);
static void Cmd_hpthresholds2(void);
static void Cmd_useitemonopponent(void);
static void Cmd_various(void);
static void Cmd_ColocaProteccion(void);
static void Cmd_tryexplosion(void);
static void Cmd_setatkhptozero(void);
static void Cmd_jumpifnexttargetvalid(void);
static void Cmd_tryhealhalfhealth(void);
static void Cmd_setfieldweather(void);
static void Cmd_setreflect(void);
static void Cmd_setseeded(void);
static void Cmd_manipulatedamage(void);
static void Cmd_trysetrest(void);
static void Cmd_jumpifnotfirstturn(void);
static void Cmd_jumpifuproarwakes(void);
static void Cmd_stockpile(void);
static void Cmd_stockpiletobasedamage(void);
static void Cmd_stockpiletohpheal(void);
static void Cmd_setdrainedhp(void);
static void Cmd_statbuffchange(void);
static void Cmd_normalisebuffs(void);
static void Cmd_forcerandomswitch(void);
static void Cmd_givepaydaymoney(void);
static void Cmd_setlightscreen(void);
static void Cmd_damagetohalftargethp(void);
static void Cmd_tryinfatuating(void);
static void Cmd_updatestatusicon(void);
static void Cmd_setmist(void);
static void Cmd_setsubstitute(void);
static void Cmd_disablelastusedattack(void);
static void Cmd_trysetencore(void);
static void Cmd_setalwayshitflag(void);
static void Cmd_setdestinybond(void);
static void Cmd_trysetdestinybondtohappen(void);
static void Cmd_settailwind(void);
static void Cmd_healpartystatus(void);
static void Cmd_cursetarget(void);
static void Cmd_trysetspikes(void);
static void Cmd_setforesight(void);
static void Cmd_trysetperishsong(void);
static void Cmd_handlerollout(void);
static void Cmd_jumpifconfusedandstatmaxed(void);
static void Cmd_handlefurycutter(void);
static void Cmd_setembargo(void);
static void Cmd_presentdamagecalculation(void);
static void Cmd_setsafeguard(void);
static void Cmd_magnitudedamagecalculation(void);
static void Cmd_jumpifnopursuitswitchdmg(void);
static void Cmd_halvehp(void);
static void Cmd_copyfoestats(void);
static void Cmd_girorapidofree(void);
static void Cmd_setdefensecurlbit(void);
static void Cmd_RecuperaSaludSegunClima(void);
static void Cmd_setstickyweb(void);
static void Cmd_selectfirstvalidtarget(void);
static void Cmd_setsemiinvulnerablebit(void);
static void Cmd_tryfiretwoturnmovenowbyeffect(void);
static void Cmd_setminimize(void);
static void Cmd_setforcedtarget(void);
static void Cmd_setcharge(void);
static void Cmd_cureifburnedparalysedorpoisoned(void);
static void Cmd_settorment(void);
static void Cmd_jumpifnodamage(void);
static void Cmd_settaunt(void);
static void Cmd_tryswapitems(void);
static void Cmd_trycopyability(void);
static void Cmd_settoxicspikes(void);
static void Cmd_setgastroacid(void);
static void Cmd_setdamagetohealthdifference(void);
static void Cmd_PonEspacioRaro(void);
static void Cmd_tryimprison(void);
static void Cmd_setstealthrock(void);
static void Cmd_setuserstatus3(void);
static void Cmd_switchoutabilities(void);
static void Cmd_jumpifhasnohp(void);
static void Cmd_jumpifnotcurrentmoveargtype(void);
static void Cmd_jumpifsubstituteblocks(void);
static void Cmd_tryrecycleitem(void);
static void Cmd_EliminaPantallas(void);
static void Cmd_handleballthrow(void);
static void Cmd_givecaughtmon(void);
static void Cmd_trysetcaughtmondexflags(void);
static void Cmd_displaydexinfo(void);
static void Cmd_trygivecaughtmonnick(void);
static void Cmd_subattackerhpbydmg(void);
static void Cmd_removeattackerstatus1(void);
static void Cmd_finishaction(void);
static void Cmd_finishturn(void);
static void Cmd_trainerslideout(void);
static void Cmd_settelekinesis(void);
static void Cmd_swapstatstages(void);
static void Cmd_averagestats(void);
static void Cmd_jumpifoppositegenders(void);
static void Cmd_callnative(void);

#define BATTLE_CMD(name) [BATTLE_CMD_##name] = Cmd_##name

void (*const gBattleScriptingCommandsTable[])(void) =
    {
        BATTLE_CMD(attackcanceler),
        BATTLE_CMD(accuracycheck),
        BATTLE_CMD(attackstring),
        BATTLE_CMD(ppreduce),
        BATTLE_CMD(critcalc),
        BATTLE_CMD(damagecalc),
        BATTLE_CMD(typecalc),
        BATTLE_CMD(adjustdamage),
        BATTLE_CMD(multihitresultmessage),
        BATTLE_CMD(attackanimation),
        BATTLE_CMD(waitanimation),
        BATTLE_CMD(healthbarupdate),
        BATTLE_CMD(datahpupdate),
        BATTLE_CMD(critmessage),
        BATTLE_CMD(HazSonidoEfectividad),
        BATTLE_CMD(resultmessage),
        BATTLE_CMD(EscribeTextoCombate),
        BATTLE_CMD(printselectionstring),
        BATTLE_CMD(waitmessage),
        BATTLE_CMD(printfromtable),
        BATTLE_CMD(setadditionaleffects),
        BATTLE_CMD(seteffectprimary),
        BATTLE_CMD(seteffectsecondary),
        BATTLE_CMD(clearstatusfromeffect),
        BATTLE_CMD(tryfaintmon),
        BATTLE_CMD(dofaintanimation),
        BATTLE_CMD(cleareffectsonfaint),
        BATTLE_CMD(jumpifstatus),
        BATTLE_CMD(jumpifstatus2),
        BATTLE_CMD(jumpifability),
        BATTLE_CMD(jumpifsideaffecting),
        BATTLE_CMD(jumpifstat),
        BATTLE_CMD(jumpifstatus3condition),
        BATTLE_CMD(jumpbasedontype),
        BATTLE_CMD(getexp),
        BATTLE_CMD(checkteamslost),
        BATTLE_CMD(movevaluescleanup),
        BATTLE_CMD(setmultihit),
        BATTLE_CMD(decrementmultihit),
        BATTLE_CMD(goto),
        BATTLE_CMD(jumpifbyte),
        BATTLE_CMD(jumpifhalfword),
        BATTLE_CMD(jumpifword),
        BATTLE_CMD(jumpifarrayequal),
        BATTLE_CMD(jumpifarraynotequal),
        BATTLE_CMD(setbyte),
        BATTLE_CMD(addbyte),
        BATTLE_CMD(subbyte),
        BATTLE_CMD(copyarray),
        BATTLE_CMD(copyarraywithindex),
        BATTLE_CMD(orbyte),
        BATTLE_CMD(orhalfword),
        BATTLE_CMD(orword),
        BATTLE_CMD(bicbyte),
        BATTLE_CMD(bichalfword),
        BATTLE_CMD(bicword),
        BATTLE_CMD(pause),
        BATTLE_CMD(waitstate),
        BATTLE_CMD(healthbar_update),
        BATTLE_CMD(return),
        BATTLE_CMD(end),
        BATTLE_CMD(end2),
        BATTLE_CMD(end3),
        BATTLE_CMD(call),
        BATTLE_CMD(setroost),
        BATTLE_CMD(jumpifabilitypresent),
        BATTLE_CMD(endselectionscript),
        BATTLE_CMD(playanimation),
        BATTLE_CMD(playanimation_var),
        BATTLE_CMD(setgraphicalstatchangevalues),
        BATTLE_CMD(playstatchangeanimation),
        BATTLE_CMD(moveend),
        BATTLE_CMD(returnatktoball),
        BATTLE_CMD(getswitchedmondata),
        BATTLE_CMD(switchindataupdate),
        BATTLE_CMD(switchinanim),
        BATTLE_CMD(jumpifcantswitch),
        BATTLE_CMD(openpartyscreen),
        BATTLE_CMD(switchhandleorder),
        BATTLE_CMD(switchineffects),
        BATTLE_CMD(trainerslidein),
        BATTLE_CMD(playse),
        BATTLE_CMD(fanfare),
        BATTLE_CMD(playfaintcry),
        BATTLE_CMD(returntoball),
        BATTLE_CMD(handlelearnnewmove),
        BATTLE_CMD(yesnoboxlearnmove),
        BATTLE_CMD(yesnoboxstoplearningmove),
        BATTLE_CMD(hitanimation),
        BATTLE_CMD(getmoneyreward),
        BATTLE_CMD(callnative),
        BATTLE_CMD(swapattackerwithtarget),
        BATTLE_CMD(incrementgamestat),
        BATTLE_CMD(drawpartystatussummary),
        BATTLE_CMD(hidepartystatussummary),
        BATTLE_CMD(statusanimation),
        BATTLE_CMD(status2animation),
        BATTLE_CMD(chosenstatusanimation),
        BATTLE_CMD(yesnobox),
        BATTLE_CMD(CancelaAccionesSiNoEntrenador),
        BATTLE_CMD(removeitem),
        BATTLE_CMD(atknameinbuff1),
        BATTLE_CMD(drawlvlupbox),
        BATTLE_CMD(resetsentmonsvalue),
        BATTLE_CMD(setatktoplayer0),
        BATTLE_CMD(makevisible),
        BATTLE_CMD(recordability),
        BATTLE_CMD(buffermovetolearn),
        BATTLE_CMD(hpthresholds),
        BATTLE_CMD(hpthresholds2),
        BATTLE_CMD(useitemonopponent),
        BATTLE_CMD(various),
        BATTLE_CMD(ColocaProteccion),
        BATTLE_CMD(tryexplosion),
        BATTLE_CMD(setatkhptozero),
        BATTLE_CMD(jumpifnexttargetvalid),
        BATTLE_CMD(tryhealhalfhealth),
        BATTLE_CMD(setfieldweather),
        BATTLE_CMD(setreflect),
        BATTLE_CMD(setseeded),
        BATTLE_CMD(manipulatedamage),
        BATTLE_CMD(trysetrest),
        BATTLE_CMD(jumpifnotfirstturn),
        BATTLE_CMD(jumpifuproarwakes),
        BATTLE_CMD(stockpile),
        BATTLE_CMD(stockpiletobasedamage),
        BATTLE_CMD(stockpiletohpheal),
        BATTLE_CMD(setdrainedhp),
        BATTLE_CMD(statbuffchange),
        BATTLE_CMD(normalisebuffs),
        BATTLE_CMD(forcerandomswitch),
        BATTLE_CMD(givepaydaymoney),
        BATTLE_CMD(setlightscreen),
        BATTLE_CMD(damagetohalftargethp),
        BATTLE_CMD(tryinfatuating),
        BATTLE_CMD(updatestatusicon),
        BATTLE_CMD(setmist),
        BATTLE_CMD(setsubstitute),
        BATTLE_CMD(disablelastusedattack),
        BATTLE_CMD(trysetencore),
        BATTLE_CMD(setalwayshitflag),
        BATTLE_CMD(setdestinybond),
        BATTLE_CMD(trysetdestinybondtohappen),
        BATTLE_CMD(settailwind),
        BATTLE_CMD(healpartystatus),
        BATTLE_CMD(cursetarget),
        BATTLE_CMD(trysetspikes),
        BATTLE_CMD(setforesight),
        BATTLE_CMD(trysetperishsong),
        BATTLE_CMD(handlerollout),
        BATTLE_CMD(jumpifconfusedandstatmaxed),
        BATTLE_CMD(handlefurycutter),
        BATTLE_CMD(setembargo),
        BATTLE_CMD(presentdamagecalculation),
        BATTLE_CMD(setsafeguard),
        BATTLE_CMD(magnitudedamagecalculation),
        BATTLE_CMD(jumpifnopursuitswitchdmg),
        BATTLE_CMD(halvehp),
        BATTLE_CMD(copyfoestats),
        BATTLE_CMD(girorapidofree),
        BATTLE_CMD(setdefensecurlbit),
        BATTLE_CMD(RecuperaSaludSegunClima),
        BATTLE_CMD(setstickyweb),
        BATTLE_CMD(selectfirstvalidtarget),
        BATTLE_CMD(setsemiinvulnerablebit),
        BATTLE_CMD(tryfiretwoturnmovenowbyeffect),
        BATTLE_CMD(setminimize),
        BATTLE_CMD(setforcedtarget),
        BATTLE_CMD(setcharge),
        BATTLE_CMD(cureifburnedparalysedorpoisoned),
        BATTLE_CMD(settorment),
        BATTLE_CMD(jumpifnodamage),
        BATTLE_CMD(settaunt),
        BATTLE_CMD(tryswapitems),
        BATTLE_CMD(trycopyability),
        BATTLE_CMD(settoxicspikes),
        BATTLE_CMD(setgastroacid),
        BATTLE_CMD(setdamagetohealthdifference),
        BATTLE_CMD(PonEspacioRaro),
        BATTLE_CMD(tryimprison),
        BATTLE_CMD(setstealthrock),
        BATTLE_CMD(setuserstatus3),
        BATTLE_CMD(switchoutabilities),
        BATTLE_CMD(jumpifhasnohp),
        BATTLE_CMD(jumpifnotcurrentmoveargtype),
        BATTLE_CMD(jumpifsubstituteblocks),
        BATTLE_CMD(tryrecycleitem),
        BATTLE_CMD(EliminaPantallas),
        BATTLE_CMD(handleballthrow),
        BATTLE_CMD(givecaughtmon),
        BATTLE_CMD(trysetcaughtmondexflags),
        BATTLE_CMD(displaydexinfo),
        BATTLE_CMD(trygivecaughtmonnick),
        BATTLE_CMD(subattackerhpbydmg),
        BATTLE_CMD(removeattackerstatus1),
        BATTLE_CMD(finishaction),
        BATTLE_CMD(finishturn),
        BATTLE_CMD(trainerslideout),
        BATTLE_CMD(settelekinesis),
        BATTLE_CMD(swapstatstages),
        BATTLE_CMD(averagestats),
        BATTLE_CMD(jumpifoppositegenders),
};

static const u32 sStatusFlagsForMoveEffects[NUM_MOVE_EFFECTS] =
    {
        [MOVE_EFFECT_SLEEP] = STATUS1_SLEEP,
        [MOVE_EFFECT_POISON] = STATUS1_POISON,
        [MOVE_EFFECT_BURN] = STATUS1_BURN,
        [EFECTO_MOVIMIENTO_CONGELACION] = STATUS1_CONGELACION,
        [MOVE_EFFECT_PARALYSIS] = STATUS1_PARALYSIS,
        [MOVE_EFFECT_TOXIC] = STATUS1_TOXIC_POISON,
        [MOVE_EFFECT_CONFUSION] = STATUS2_CONFUSION,
        [MOVE_EFFECT_FLINCH] = STATUS2_FLINCHED,
        [MOVE_EFFECT_UPROAR] = STATUS2_UPROAR,
        [MOVE_EFFECT_CHARGING] = STATUS2_MULTIPLETURNS,
        [MOVE_EFFECT_WRAP] = STATUS2_WRAPPED,
        [MOVE_EFFECT_RECHARGE] = STATUS2_RECHARGE,
        [MOVE_EFFECT_PREVENT_ESCAPE] = STATUS2_ESCAPE_PREVENTION,
        [MOVE_EFFECT_NIGHTMARE] = STATUS2_NIGHTMARE,
        [MOVE_EFFECT_THRASH] = STATUS2_LOCK_CONFUSE,
};

static const u8 *const sMoveEffectBS_Ptrs[] =
    {
        [MOVE_EFFECT_SLEEP] = BattleScript_MoveEffectSleep,
        [MOVE_EFFECT_POISON] = BattleScript_MoveEffectPoison,
        [MOVE_EFFECT_BURN] = BattleScript_MoveEffectBurn,
        [EFECTO_MOVIMIENTO_CONGELACION] = ScriptCombate_EfectoMovimientoCongelacion,
        [MOVE_EFFECT_PARALYSIS] = BattleScript_MoveEffectParalysis,
        [MOVE_EFFECT_TOXIC] = BattleScript_MoveEffectToxic,
        [MOVE_EFFECT_CONFUSION] = BattleScript_MoveEffectConfusion,
        [MOVE_EFFECT_UPROAR] = BattleScript_MoveEffectUproar,
        [EFECTO_MOVIMIENTO_SALTA_DINERO] = ScriptCombate_EfectoMovimientoDiaDePago,
        [MOVE_EFFECT_WRAP] = BattleScript_MoveEffectWrap,
};

static const u16 sLevelUpBanner_Pal[] = INCBIN_U16("graphics/battle_interface/level_up_banner.gbapal");
static const u32 sLevelUpBanner_Gfx[] = INCBIN_U32("graphics/battle_interface/level_up_banner.4bpp.lz");

static const struct OamData sOamData_MonIconOnLvlUpBanner =
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(32x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(32x32),
        .tileNum = 0,
        .priority = 0,
        .paletteNum = 0,
        .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_MonIconOnLvlUpBanner =
    {
        .tileTag = TAG_LVLUP_BANNER_MON_ICON,
        .paletteTag = TAG_LVLUP_BANNER_MON_ICON,
        .oam = &sOamData_MonIconOnLvlUpBanner,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_MonIconOnLvlUpBanner};

static const u16 sProtectSuccessRates[] = {USHRT_MAX, USHRT_MAX / 2, USHRT_MAX / 4, USHRT_MAX / 8};

static const u16 sFinalStrikeOnlyEffects[] =
    {
        MOVE_EFFECT_BUG_BITE,
        MOVE_EFFECT_STEAL_ITEM,
        MOVE_EFFECT_SMACK_DOWN,
        MOVE_EFFECT_REMOVE_STATUS,
        MOVE_EFFECT_PREVENT_ESCAPE,
        MOVE_EFFECT_WRAP,
};

static bool32 NoTargetPresent(u8 battler, u32 move)
{
    if (!IsBattlerAlive(gBattlerTarget))
        gBattlerTarget = GetMoveTarget(move, NO_TARGET_OVERRIDE);

    switch (GetBattlerMoveTargetType(battler, move))
    {
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_RANDOM:
        if (!IsBattlerAlive(gBattlerTarget))
            return TRUE;
        break;
    case MOVE_TARGET_BOTH:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(ALIADO(gBattlerTarget)))
            return TRUE;
        break;
    case MOVE_TARGET_FOES_AND_ALLY:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(ALIADO(gBattlerTarget)) && !IsBattlerAlive(ALIADO(gBattlerAttacker)))
            return TRUE;
        break;
    }

    return FALSE;
}

static void Cmd_attackcanceler(void)
{
    CMD_ARGS();

    s32 i;
    u32 attackerAbility = HabilidadCombatiente(gBattlerAttacker);
    u32 moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);
    u32 habilidadObjetivo = HabilidadCombatiente(gBattlerTarget);

    if (gCombate->usedEjectItem & (1u << gBattlerAttacker))
    {
        gCombate->usedEjectItem = 0;
        gCurrentActionFuncId = B_ACTION_TRY_FINISH;
        return;
    }

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    if (!IsBattlerAlive(gBattlerAttacker) && gMovimientos[gCurrentMove].effect != EFFECT_EXPLOSION && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
    {
        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return;
    }

    if (AtkCanceller_UnableToUseMove(moveType))
        return;

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_OFF && HabilidadCombatiente(gBattlerAttacker) == ABILITY_PARENTAL_BOND && IsMoveAffectedByParentalBond(gCurrentMove, gBattlerAttacker) && !(gAbsentBattlerFlags & (1u << gBattlerTarget)))
    {
        gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_1ST_HIT;
        gCombate->contadorMultigolpes = 2;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
        return;
    }

    if (attackerAbility == ABILITY_MUTATIPO &&
       (gBattleMons[gBattlerAttacker].types[TIPO_1] != moveType || gBattleMons[gBattlerAttacker].types[TIPO_2] != moveType))
    {
        CAMBIA_TIPO_COMBATIENTE(gBattlerAttacker, moveType);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        gBattlerAbility = gBattlerAttacker;
        BattleScriptPushCursor();
        // PrepareStringBattle(STRINGID_EMPTYSTRING3, gBattlerAttacker);
        gMostrarMensajeBatalla = TRUE;
        gBattlescriptCurrInstr = ScriptCombate_ActivaHabilidadCambioTipoOfensivo;
        return;
    }

    if (habilidadObjetivo == ABILITY_CAMUFLAJE &&
       (gBattleMons[gBattlerTarget].types[TIPO_1] != moveType || gBattleMons[gBattlerTarget].types[TIPO_2] != moveType))
    {
        CAMBIA_TIPO_COMBATIENTE(gBattlerTarget, moveType);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gMostrarMensajeBatalla = TRUE;
        gBattlescriptCurrInstr = ScriptCombate_ActivaHabilidadCambioTipoDefensivo;
        return;
    }

    if (AbilityBattleEffects(ABILITYEFFECT_MOVES_BLOCK, gBattlerTarget, 0, 0, 0))
        return;

    if (!gBattleMons[gBattlerAttacker].pp[gCurrMovePos] && gCurrentMove != MOVE_STRUGGLE && !(gHitMarker & (HITMARKER_ALLOW_NO_PP | HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT)) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        return;
    }

    gHitMarker &= ~HITMARKER_ALLOW_NO_PP;

    // Check if no available target present on the field or if Sky Battles ban the move
    if ((NoTargetPresent(gBattlerAttacker, gCurrentMove) && (!gBattleMoveEffects[gMovimientos[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))))
    {
        gBattlescriptCurrInstr = BattleScript_FailedFromAtkString;

        if (!gBattleMoveEffects[gMovimientos[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
            CancelMultiTurnMoves(gBattlerAttacker);
        return;
    }

    if (gMovimientos[gCurrentMove].espejoMagico && !gCombate->movimientoEspejoMagicoRebota)
    {
        u32 battler = gBattlerTarget;

        if (HabilidadCombatiente(gBattlerTarget) == ABILITY_ESPEJO_MAGICO)
        {
            battler = gBattlerTarget;
            gCombate->movimientoEspejoMagicoRebota = TRUE;
        }
        else if (EsCombateContraEntrenador(gCombate->tipoCombate) && gMovimientos[gCurrentMove].target == MOVE_TARGET_OPPONENTS_FIELD && HabilidadCombatiente(ALIADO(gBattlerTarget)) == ABILITY_ESPEJO_MAGICO)
        {
            gBattlerTarget = battler = ALIADO(gBattlerTarget);
            gCombate->movimientoEspejoMagicoRebota = TRUE;
        }

        if (gCombate->movimientoEspejoMagicoRebota)
        {
            // Edge case for bouncing a powder move against a grass type pokemon.
            SetAtkCancellerForCalledMove();
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MagicBounce;
            gBattlerAbility = battler;
            return;
        }
    }

    if (gSpecialStatuses[gBattlerTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBattlerTarget].lightningRodRedirected = FALSE;
        gLastUsedAbility = ABILITY_LIGHTNING_ROD;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecuerdaHabilidad(gBattlerTarget, gLastUsedAbility);
    }
    else if (gSpecialStatuses[gBattlerTarget].stormDrainRedirected)
    {
        gSpecialStatuses[gBattlerTarget].stormDrainRedirected = FALSE;
        gLastUsedAbility = ABILITY_STORM_DRAIN;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecuerdaHabilidad(gBattlerTarget, gLastUsedAbility);
    }
    else if (IsBattlerProtected(gBattlerAttacker, gBattlerTarget, gCurrentMove) && (gCurrentMove != MOVE_CURSE || EsTipo(gBattlerAttacker, TIPO_FANTASMA)) && (!gBattleMoveEffects[gMovimientos[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)) && gMovimientos[gCurrentMove].effect != EFFECT_GOLPE_BAJO && gMovimientos[gCurrentMove].effect != EFFECT_PALMA_RAUDA)
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastLandedMoves[gBattlerTarget] = MOVE_NONE;

        if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT)
        {
            gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_OFF; // No second hit if first hit was blocked
            gSpecialStatuses[gBattlerAttacker].multiHitOn = 0;
            gCombate->contadorMultigolpes = 0;
        }
        gMensajeBatalla = TEXTO_COMBATE_PROTECCION;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 JumpIfMoveFailed(u32 movimiento)
{
    if (!MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gLastLandedMoves[gBattlerTarget] = MOVE_NONE;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        return TRUE;
    }
    else
    {
        TrySetDestinyBondToHappen();
        if (AbilityBattleEffects(ABILITYEFFECT_ABSORBING, gBattlerTarget, 0, 0, movimiento))
            return TRUE;
    }
    gBattlescriptCurrInstr += 7;
    return FALSE;
}

static bool8 JumpIfMoveAffectedByProtect(u16 move)
{
    bool8 affected = FALSE;
    if (IsBattlerProtected(gBattlerAttacker, gBattlerTarget, move))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(move);
        gMensajeBatalla = TEXTO_COMBATE_PROTECCION;
        affected = TRUE;
    }
    return affected;
}

u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move, u32 atkAbility, u32 defAbility, u32 atkHoldEffect, u32 defHoldEffect)
{
    u32 moveAcc;
    s32 buff, accStage, evasionStage;
    uq4_12_t modifier = NEUTRO;
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    gPotentialItemEffectBattler = battlerDef;
    accStage = gBattleMons[battlerAtk].statStages[ESTADISTICA_PRECISION];
    evasionStage = gBattleMons[battlerDef].statStages[ESTADISTICA_EVASION];

    if (gMovimientos[move].ignoresTargetDefenseEvasionStages)
        evasionStage = ESTADISTICA_NEUTRA;

    buff = accStage + ESTADISTICA_NEUTRA - evasionStage;

    if (buff < ESTADISTICA_MENOS_6)
        buff = ESTADISTICA_MENOS_6;
    if (buff > ESTADISTICA_MAS_6)
        buff = ESTADISTICA_MAS_6;

    moveAcc = gMovimientos[move].accuracy;

    if (gMovimientos[move].effect == EFFECT_PRECISION_INCREMENTADA_CLIMA)
    {
        if (ClimaTieneEfecto()
         && ClimaMovimientoCoincide(gMovimientos[move].clima))
        {
            moveAcc = 100;
        }
    }

    MULTIPLICA(modifier, gMultiplicadorEstadisticas[buff]);

    switch (atkAbility)
    {
    case ABILITY_OJO_COMPUESTO:
    case ABILITY_VISTA_LINCE:
        MULTIPLICA(modifier, MAS_25_POR_CIENTO);
        break;
    case ABILITY_ENTUSIASMO:
        MULTIPLICA(modifier, MENOS_12_5_POR_CIENTO);
        break;
    }

    switch (defAbility)
    {
    case ABILITY_SAND_VEIL:
        if (EsClimaCombateArena(climaCombate))
            MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    case ABILITY_SNOW_CLOAK:
        if (EsClimaCombateNieve(climaCombate))
            MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    case ABILITY_OLOR_FLUVIAL:
        if (EsClimaCombateLluvia(climaCombate))
            MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    case ABILITY_TANGLED_FEET:
        if (gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
            MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    case ABILITY_HIBERNADOR:
        if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP)
            MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    case ABILITY_ESQUIVO:
        MULTIPLICA(modifier, MENOS_25_POR_CIENTO);
        break;
    }

    if (atkHoldEffect == HOLD_EFFECT_WIDE_LENS)
        MULTIPLICA(modifier, MAS_25_POR_CIENTO);

    return UQ412MultiplicaPorEntero(modifier, moveAcc);
}

static void AccuracyCheck(bool32 recalcDragonDarts, const u8 *nextInstr, const u8 *failInstr, u16 move)
{
    u32 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, move);
    u32 abilityAtk = GetBattlerAbility(gBattlerAttacker);
    u32 abilityDef = GetBattlerAbility(gBattlerTarget);
    u32 holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);

    if (move == ACC_CURR_MOVE)
        move = gCurrentMove;

    if (move == NO_ACC_CALC_CHECK_LOCK_ON)
    {
        if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
            gBattlescriptCurrInstr = nextInstr;
        else if (gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE))
            gBattlescriptCurrInstr = failInstr;
        else if (!JumpIfMoveAffectedByProtect(gCurrentMove))
            gBattlescriptCurrInstr = nextInstr;
    }
    else if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_2ND_HIT || (gSpecialStatuses[gBattlerAttacker].multiHitOn && (abilityAtk == ABILITY_SKILL_LINK || abilityAtk == ABILITY_ENJAMBRE || holdEffectAtk == HOLD_EFFECT_LOADED_DICE)))
    {
        // No acc checks for second hit of Parental Bond or multi hit moves, except Patada Triple/Triple Axel/Population Bomb
        gBattlescriptCurrInstr = nextInstr;
    }
    else
    {
        u32 accuracy = GetTotalAccuracy(gBattlerAttacker, gBattlerTarget, move, abilityAtk, abilityDef, holdEffectAtk, GetBattlerHoldEffect(gBattlerTarget, TRUE));
        u32 type = TipoMovimiento(move, gBattlerAttacker);

        if (JumpIfMoveAffectedByProtect(move))
            return;

        if (!PorcentajeAleatorio(accuracy))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (gMovimientos[gCurrentMove].effect == EFFECT_DRAGON_DARTS && !recalcDragonDarts // So we don't jump back and forth between targets
                && CanTargetPartner(gBattlerAttacker, gBattlerTarget) && !TargetFullyImmuneToCurrMove(gBattlerAttacker, ALIADO(gBattlerTarget)))
            {
                // Smart target to partner if miss
                gBattlerTarget = ALIADO(gBattlerTarget);
                gMoveResultFlags &= ~MOVE_RESULT_MISSED;
                AccuracyCheck(TRUE, nextInstr, failInstr, move);
                return;
            }

            if (EsCombateContraEntrenador(gCombate->tipoCombate) &&
                (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY))
                gMensajeBatalla = TEXTO_COMBATE_ATAQUE_FALLO_DEFENSOR;
            else
                gMensajeBatalla = TEXTO_COMBATE_ATAQUE_FALLO_ATACANTE;

            if (gMovimientos[move].power)
                CalcTypeEffectivenessMultiplier(move, type, gBattlerAttacker, gBattlerTarget, abilityDef, TRUE);
        }
        JumpIfMoveFailed(move);
    }
}

static void Cmd_accuracycheck(void)
{
    CMD_ARGS(const u8 *failInstr, enum Movimientos movimiento);

    // The main body of this function has been moved to AccuracyCheck() to accomodate
    // Dragon Darts' multiple accuracy checks on a single attack;
    // each dart can try to re-target once after missing.
    AccuracyCheck(FALSE, cmd->nextInstr, cmd->failInstr, cmd->movimiento);
}

static void Cmd_attackstring(void)
{
    CMD_ARGS();

    if (HayAlgunCombatienteOcupado())
        return;

    if (!(gHitMarker & (HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED)))
    {
        PrepareStringBattle(STRINGID_USEDMOVE, gBattlerAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
    gMostrarMensajeBatalla = FALSE;
}

static void Cmd_ppreduce(void)
{
    CMD_ARGS();

    s32 i, ppToDeduct = 1;
    u32 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    if (HayAlgunCombatienteOcupado())
        return;

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
        gHitMarker |= HITMARKER_NO_PPDEDUCT;

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBattlerAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBattlerAttacker].notFirstStrike = TRUE;

        // For item Metronome, echoed voice
        if (gCurrentMove != gLastResultingMoves[gBattlerAttacker] || WasUnableToUseMove(gBattlerAttacker))
            gCombate->sameMoveTurns[gBattlerAttacker] = 0;

        if (gBattleMons[gBattlerAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 0;

        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0,
                                     sizeof(gBattleMons[gBattlerAttacker].pp[gCurrMovePos]),
                                     &gBattleMons[gBattlerAttacker].pp[gCurrMovePos]);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }

    gHitMarker &= ~HITMARKER_NO_PPDEDUCT;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

enum IndicesGolpesCriticos
{
    INDICE_GOLPE_CRITICO_NEUTRO,
    INDICE_GOLPE_CRITICO_MAS_1,
    INDICE_GOLPE_CRITICO_MAS_2,
    INDICE_GOLPE_CRITICO_MAS_3,
    INDICE_GOLPE_CRITICO_MAS_4,
};

static const u32 sPosibilidadesGolpeCritico[] =
    {
        [INDICE_GOLPE_CRITICO_NEUTRO] = 6,
        [INDICE_GOLPE_CRITICO_MAS_1] = 12,
        [INDICE_GOLPE_CRITICO_MAS_2] = 24,
        [INDICE_GOLPE_CRITICO_MAS_3] = 48,
        [INDICE_GOLPE_CRITICO_MAS_4] = 96,
};

static inline u32 PosibilidadGolpeCritico(u32 posibilidadesCritico)
{
    return sPosibilidadesGolpeCritico[posibilidadesCritico];
}

s32 GetCritHitOdds(s32 critChanceIndex)
{
    if (critChanceIndex < 0)
        return -1;
    else
        return PosibilidadGolpeCritico(critChanceIndex);
}

s32 CalcCritChanceStageArgs(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility, u32 abilityAtk, u32 abilityDef, u32 holdEffectAtk)
{
    s32 critChance = 0;

    if (gMovimientos[move].alwaysCriticalHit || (abilityAtk == ABILITY_MERCILESS && gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
    {
        critChance = -2;
    }
    else
    {
        critChance = EsMovimientoAltoIndiceCritico(move)
                  + (holdEffectAtk == HOLD_EFFECT_SCOPE_LENS)
                  + 2 * (abilityAtk == ABILITY_SUPER_LUCK)
                  + 2 * (abilityAtk == ABILITY_DISPARO_CERTERO);

        if (gMovimientos[gCurrentMove].soundMove
        && (abilityAtk == ABILITY_PERCUSIONISTA))
            critChance = +1; // REVISAR

        if (critChance >= ARRAY_COUNT(sPosibilidadesGolpeCritico))
            critChance = ARRAY_COUNT(sPosibilidadesGolpeCritico) - 1;
    }

    if (critChance != -1 && (abilityDef == ABILITY_BATTLE_ARMOR || abilityDef == ABILITY_SHELL_ARMOR))
    {
        // Record ability only if move had 100% chance to get a crit
        if (recordAbility)
        {
            if (critChance == -2)
                RecuerdaHabilidad(battlerDef, abilityDef);
            else if (PosibilidadGolpeCritico(critChance) == 1)
                RecuerdaHabilidad(battlerDef, abilityDef);
        }
        critChance = -1;
    }

    return critChance;
}

s32 CalcCritChanceStage(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility)
{
    u32 abilityAtk = HabilidadCombatiente(gBattlerAttacker);
    u32 abilityDef = HabilidadCombatiente(gBattlerTarget);
    u32 holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);
    return CalcCritChanceStageArgs(battlerAtk, battlerDef, move, recordAbility, abilityAtk, abilityDef, holdEffectAtk);
}

static void Cmd_critcalc(void)
{
    CMD_ARGS();

    s32 critChance;

    critChance = CalcCritChanceStage(gBattlerAttacker, gBattlerTarget, gCurrentMove, TRUE);

    gPotentialItemEffectBattler = gBattlerAttacker;

    if (critChance == -1)
        gEsGolpeCritico = FALSE;
    else if (critChance == -2)
        gEsGolpeCritico = TRUE;
    else
    {
        gEsGolpeCritico = PorcentajeAleatorio(PosibilidadGolpeCritico(critChance));
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_damagecalc(void)
{
    CMD_ARGS();

    struct DamageCalculationData damageCalcData;
    damageCalcData.battlerAtk = gBattlerAttacker;
    damageCalcData.battlerDef = gBattlerTarget;
    damageCalcData.movimiento = gCurrentMove;
    damageCalcData.moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);
    damageCalcData.isCrit = gEsGolpeCritico;
    damageCalcData.updateFlags = TRUE;

    gBattleMoveDamage = CalculateMoveDamage(&damageCalcData, 0);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_typecalc(void)
{
    CMD_ARGS();

    u32 moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);
    CalcTypeEffectivenessMultiplier(gCurrentMove, moveType, gBattlerAttacker, gBattlerTarget, HabilidadCombatiente(gBattlerTarget), TRUE);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_adjustdamage(void)
{
    CMD_ARGS();

    gBattlescriptCurrInstr = cmd->nextInstr;

    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMoveDamage >= 1)
        gSpecialStatuses[gBattlerAttacker].damagedMons |= (1 << (gBattlerTarget));

    // Check gems and damage reducing berries.
    if (gSpecialStatuses[gBattlerTarget].berryReduced && MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerTarget].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryReduceDmg;
        gLastUsedItem = gBattleMons[gBattlerTarget].item;
    }
    if (gSpecialStatuses[gBattlerAttacker].potenciadoGema && MovimientoEsEfectivo(gCombate->resultadoMovimiento) && gBattleMons[gBattlerAttacker].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_GemActivates;
        gLastUsedItem = gBattleMons[gBattlerAttacker].item;
    }
}

static void Cmd_multihitresultmessage(void)
{
    CMD_ARGS();

    if (HayAlgunCombatienteOcupado())
        return;

    gBattlescriptCurrInstr = cmd->nextInstr;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced && MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gCombate->ateBerry[gBattlerTarget & BIT_SIDE] |= 1u << gBattlerPartyIndexes[gBattlerTarget];
        gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

static void Cmd_attackanimation(void)
{
    CMD_ARGS();

    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    if (HayAlgunCombatienteOcupado())
        return;

    if ((gHitMarker & (HITMARKER_DISABLE_ANIMATION)) && gCurrentMove != MOVE_SUBSTITUTE)
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
        gBattleScripting.animTurn++;
        gBattleScripting.animTargetsHit++;
    }
    else
    {
        if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_2ND_HIT)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }

        if ((moveTarget & MOVE_TARGET_BOTH || moveTarget & MOVE_TARGET_FOES_AND_ALLY || moveTarget & MOVE_TARGET_DEPENDS) && gBattleScripting.animTargetsHit)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
        if (MovimientoEsEfectivo(gCombate->resultadoMovimiento))
        {
            u8 multihit;

            if (gBattleMons[gBattlerTarget].status2 & STATUS2_SUBSTITUTE)
                multihit = gCombate->contadorMultigolpes;
            else if (gCombate->contadorMultigolpes != 0 && gCombate->contadorMultigolpes != 1)
            {
                if (gBattleMons[gBattlerTarget].hp <= gBattleMoveDamage)
                    multihit = 1;
                else
                    multihit = gCombate->contadorMultigolpes;
            }
            else
                multihit = gCombate->contadorMultigolpes;

            BtlController_EmitMoveAnimation(gBattlerAttacker, BUFFER_A, gCurrentMove, gBattleScripting.animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBattlerAttacker].friendship, &gDisableStructs[gBattlerAttacker], multihit);
            gBattleScripting.animTurn++;
            gBattleScripting.animTargetsHit++;
            MarcaCombatienteOcupado(gBattlerAttacker);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_Pausex20;
        }
    }
}

static void Cmd_waitanimation(void)
{
    CMD_ARGS();

    if (!HayAlgunCombatienteOcupado())
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_healthbarupdate(void)
{
    CMD_ARGS(u8 battler);

    if (HayAlgunCombatienteOcupado())
        return;

    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) || (gHitMarker & HITMARKER_PASSIVE_DAMAGE))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);

        if (DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && gDisableStructs[battler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(STRINGID_SUBSTITUTEDAMAGED, battler);
        }
        s16 healthValue = min(gBattleMoveDamage, 10000); // Max damage (10000) not present in R/S, ensures that huge damage values don't change sign

        BtlController_EmitHealthBarUpdate(battler, BUFFER_A, healthValue);
        MarcaCombatienteOcupado(battler);
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Update the active battler's HP and various HP trackers (Substitute, etc.)
static void Cmd_datahpupdate(void)
{
    CMD_ARGS(u8 battler);

    u32 battler;

    if (HayAlgunCombatienteOcupado())
        return;

    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) || (gHitMarker & HITMARKER_PASSIVE_DAMAGE))
    {
        battler = GetBattlerForBattleScript(cmd->battler);
        if (DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && gDisableStructs[battler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            if (gDisableStructs[battler].substituteHP >= gBattleMoveDamage)
            {
                gDisableStructs[battler].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                gHpDealt = gDisableStructs[battler].substituteHP;
                gDisableStructs[battler].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[battler].substituteHP == 0)
            {
                gBattlescriptCurrInstr = cmd->nextInstr;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        else
        {
            gHitMarker &= ~HITMARKER_IGNORE_SUBSTITUTE;
            if (gBattleMoveDamage < 0)
            {
                // Negative damage is HP gain
                gBattleMons[battler].hp += -gBattleMoveDamage;
                if (gBattleMons[battler].hp > gBattleMons[battler].maxHP)
                    gBattleMons[battler].hp = gBattleMons[battler].maxHP;
            }
            else
            {
                // Deal damage to the battler
                if (gBattleMons[battler].hp > gBattleMoveDamage)
                {
                    gBattleMons[battler].hp -= gBattleMoveDamage;
                    gHpDealt = gBattleMoveDamage;
                }
                else
                {
                    gHpDealt = gBattleMons[battler].hp;
                    gBattleMons[battler].hp = 0;
                }

                gCombate[battler].danioRecibido = gHpDealt;
            }
            gHitMarker &= ~HITMARKER_PASSIVE_DAMAGE;

            // Send updated HP
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[battler].hp), &gBattleMons[battler].hp);
            MarcaCombatienteOcupado(battler);
        }
    }
    else
    {
        battler = GetBattlerForBattleScript(cmd->battler);
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_critmessage(void)
{
    CMD_ARGS();

    if (!HayAlgunCombatienteOcupado())
    {
        if (gEsGolpeCritico == TRUE
         && MovimientoEsEfectivo(gCombate->resultadoMovimiento))
        {
            PrepareStringBattle(STRINGID_CRITICALHIT, gBattlerAttacker);

            // Signal for the trainer slide-in system.
            if (GetBattlerSide(gBattlerTarget) != LADO_JUGADOR && gCombate->trainerSlideFirstCriticalHitMsgState != 2)
                gCombate->trainerSlideFirstCriticalHitMsgState = 1;

            gMostrarMensajeBatalla = TRUE;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_HazSonidoEfectividad(void)
{
    CMD_ARGS();

    if (HayAlgunCombatienteOcupado())
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_MISSED))
    {
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_SUPER_EFFECTIVE);
            MarcaCombatienteOcupado(gBattlerTarget);
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_NOT_EFFECTIVE);
            MarcaCombatienteOcupado(gBattlerTarget);
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
        case MOVE_RESULT_FAILED:
            // no sound
            break;
        default:
            if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_SUPER_EFFECTIVE);
                MarcaCombatienteOcupado(gBattlerTarget);
            }
            else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_NOT_EFFECTIVE);
                MarcaCombatienteOcupado(gBattlerTarget);
            }
            else if (!(gMoveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_EFFECTIVE);
                MarcaCombatienteOcupado(gBattlerTarget);
            }
            break;
        }
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_resultmessage(void)
{
    CMD_ARGS();

    u32 stringId = 0;

    if (HayAlgunCombatienteOcupado())
        return;

    if (gMoveResultFlags & MOVE_RESULT_MISSED && (!(gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE) || gMensajeBatalla == TEXTO_COMBATE_LEVITACION || gMensajeBatalla == TEXTO_COMBATE_TELEPATA))
    {
        if (gMensajeBatalla == TEXTO_COMBATE_LEVITACION || gMensajeBatalla == TEXTO_COMBATE_TELEPATA)
            CreaMensajeHabilidad(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
        stringId = gMensajeBatalla;
        gMostrarMensajeBatalla = TRUE;
    }
    else
    {
        gMostrarMensajeBatalla = TRUE;
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            if (!gCombate->contadorMultigolpes) // Don't print effectiveness on each hit in a multi hit attack
            {
                // Signal for the trainer slide-in system.
                if (GetBattlerSide(gBattlerTarget) != LADO_JUGADOR && gCombate->trainerSlideFirstSuperEffectiveHitMsgState != 2)
                    gCombate->trainerSlideFirstSuperEffectiveHitMsgState = 1;

                stringId = STRINGID_SUPEREFFECTIVE;
            }
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            if (!gCombate->contadorMultigolpes)
                stringId = STRINGID_NOTVERYEFFECTIVE;
            break;
        case MOVE_RESULT_FAILED:
            stringId = STRINGID_BUTITFAILED;
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
            stringId = STRINGID_ITDOESNTAFFECT;
            break;
        default:
            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                stringId = STRINGID_ITDOESNTAFFECT;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FAILED)
            {
                stringId = STRINGID_BUTITFAILED;
            }
            else
            {
                gMostrarMensajeBatalla = FALSE;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced && MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gCombate->ateBerry[gBattlerTarget & BIT_SIDE] |= 1u << gBattlerPartyIndexes[gBattlerTarget];
        gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

static void Cmd_EscribeTextoCombate(void)
{
    CMD_ARGS(const u8 *texto);

    if (!HayAlgunCombatienteOcupado())
    {
        EscribeTextoCombate(gBattlerAttacker, cmd->texto);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_printselectionstring(void)
{
    CMD_ARGS(u16 id);

    BtlController_EmitPrintSelectionString(gBattlerAttacker, BUFFER_A, cmd->id);
    MarcaCombatienteOcupado(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
    gMostrarMensajeBatalla = TRUE;
}

static void Cmd_waitmessage(void)
{
    CMD_ARGS(u16 time);

    if (!HayAlgunCombatienteOcupado())
    {
        if (gMostrarMensajeBatalla == FALSE)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            u16 toWait = cmd->time;
            if (++gPauseCounterBattle >= toWait)
            {
                gPauseCounterBattle = 0;
                gBattlescriptCurrInstr = cmd->nextInstr;
                gMostrarMensajeBatalla = FALSE;
            }
        }
    }
}

static void Cmd_printfromtable(void)
{
    CMD_ARGS(const u32 *ptr);

    if (!HayAlgunCombatienteOcupado())
    {
        const u32 *ptr = cmd->ptr;
        ptr += gMensajeBatalla;

        gBattlescriptCurrInstr = cmd->nextInstr;
        PrepareStringBattle(*ptr, gBattlerAttacker);
        gMostrarMensajeBatalla = TRUE;
    }
}

u8 GetBattlerTurnOrderNum(u8 battler)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattlerByTurnOrder[i] == battler)
            break;
    }
    return i;
}

static void CheckSetUnburden(u8 battler)
{
    if (HabilidadCombatiente(battler) == ABILITY_UNBURDEN)
    {
        gBattleResources->flags[battler] |= RESOURCE_FLAG_UNBURDEN;
        RecuerdaHabilidad(battler, ABILITY_UNBURDEN);
    }
}

// battlerStealer steals the item of battlerItem
void StealTargetItem(u8 battlerStealer, u8 battlerItem)
{
    gLastUsedItem = gBattleMons[battlerItem].item;
    gBattleMons[battlerItem].item = 0;

    RecordItemEffectBattle(battlerItem, 0);
    RecordItemEffectBattle(battlerStealer, ItemId_GetHoldEffect(gLastUsedItem));
    gBattleMons[battlerStealer].item = gLastUsedItem;

    CheckSetUnburden(battlerItem);
    gBattleResources->flags[battlerStealer] &= ~RESOURCE_FLAG_UNBURDEN;

    BtlController_EmitSetMonData(battlerStealer, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gLastUsedItem), &gLastUsedItem); // set attacker item
    MarcaCombatienteOcupado(battlerStealer);

    BtlController_EmitSetMonData(battlerItem, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[battlerItem].item); // remove target item
    MarcaCombatienteOcupado(battlerItem);

    gCombate->choicedMove[battlerItem] = 0;
}

#define INCREMENT_RESET_RETURN           \
    {                                    \
        gBattlescriptCurrInstr++;        \
        gBattleScripting.moveEffect = 0; \
        return;                          \
    }

#define RESET_RETURN                     \
    {                                    \
        gBattleScripting.moveEffect = 0; \
        return;                          \
    }

void SetMoveEffect(bool32 primary)
{
    s32 i, affectsUser = 0;
    bool32 statusChanged = FALSE;
    bool32 mirrorArmorReflected = (HabilidadCombatiente(gBattlerTarget) == ABILITY_MIRROR_ARMOR);
    u32 flags = 0;
    u16 battlerAbility;
    bool8 activateAfterFaint = FALSE;

    // NULL move effect
    if (gBattleScripting.moveEffect == 0)
        return;

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT && IsBattlerAlive(gBattlerTarget) && IsFinalStrikeEffect(gBattleScripting.moveEffect))
    {
        gBattlescriptCurrInstr++;
        return;
    }

    switch (gBattleScripting.moveEffect) // Set move effects which happen later on
    {
    case EFECTO_MOVIMIENTO_QUITAR_OBJETO:
    case MOVE_EFFECT_SMACK_DOWN:
    case MOVE_EFFECT_REMOVE_STATUS:
    case MOVE_EFFECT_STOCKPILE_WORE_OFF:
        gCombate->moveEffect2 = gBattleScripting.moveEffect;
        gBattlescriptCurrInstr++;
        return;
    case MOVE_EFFECT_STEALTH_ROCK:
    case MOVE_EFFECT_SPIKES:
    case EFECTO_MOVIMIENTO_SALTA_DINERO:
    case MOVE_EFFECT_STEAL_ITEM:
    case MOVE_EFFECT_BUG_BITE:
        activateAfterFaint = TRUE;
        break;
    }

    if (gBattleScripting.moveEffect & MOVE_EFFECT_AFFECTS_USER)
    {
        gEffectBattler = gBattlerAttacker; // battler that effects get applied on
        gBattleScripting.moveEffect &= ~MOVE_EFFECT_AFFECTS_USER;
        affectsUser = MOVE_EFFECT_AFFECTS_USER;
        gBattleScripting.battler = gBattlerTarget; // theoretically the attacker
    }
    else
    {
        gEffectBattler = gBattlerTarget;
        gBattleScripting.battler = gBattlerAttacker;
    }

    battlerAbility = HabilidadCombatiente(gEffectBattler);

    // Just in case this flag is still set
    gBattleScripting.moveEffect &= ~MOVE_EFFECT_CERTAIN;

    if (!primary && affectsUser != MOVE_EFFECT_AFFECTS_USER && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && (battlerAbility == ABILITY_SHIELD_DUST || GetBattlerHoldEffect(gEffectBattler, TRUE) == HOLD_EFFECT_COVERT_CLOAK))
    {
        if (battlerAbility == ABILITY_SHIELD_DUST)
            RecuerdaHabilidad(gEffectBattler, battlerAbility);
        else
            RecordItemEffectBattle(gEffectBattler, HOLD_EFFECT_COVERT_CLOAK);
        INCREMENT_RESET_RETURN
    }

    if (gSideStatuses[GetBattlerSide(gEffectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && !primary && gBattleScripting.moveEffect <= MOVE_EFFECT_CONFUSION)
        INCREMENT_RESET_RETURN

    if (!(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && EstaPotenciadoPotenciaBruta(gBattlerAttacker, gCurrentMove) && !primary && gBattleScripting.moveEffect != MOVE_EFFECT_CHARGING)
        INCREMENT_RESET_RETURN

    if (!IsBattlerAlive(gEffectBattler) && !activateAfterFaint)
        INCREMENT_RESET_RETURN

    if (DoesSubstituteBlockMove(gBattlerAttacker, gEffectBattler, gCurrentMove) && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT) // status change
    {
        const u8 *cancelMultiTurnMovesResult = NULL;
        switch (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
        case STATUS1_SLEEP:
            // check active uproar
            if (battlerAbility != ABILITY_SOUNDPROOF || B_UPROAR_IGNORE_SOUNDPROOF >= GEN_5)
            {
                for (i = 0; i < gBattlersCount && !(gBattleMons[i].status2 & STATUS2_UPROAR); i++)
                    ;
            }
            else
            {
                i = gBattlersCount;
            }

            if (i != gBattlersCount)
                break;
            if (!CanBeSlept(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
                break;

            cancelMultiTurnMovesResult = CancelMultiTurnMoves(gEffectBattler);
            if (cancelMultiTurnMovesResult)
                gBattlescriptCurrInstr = cancelMultiTurnMovesResult;
            statusChanged = TRUE;
            break;
        case STATUS1_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY) && (primary == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecuerdaHabilidad(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gEffectBattler) && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && (primary == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gMensajeBatalla = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (!CanBePoisoned(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_BURN:
            if ((battlerAbility == ABILITY_WATER_VEIL || battlerAbility == ABILITY_TIERRA_HUMEDA) && (primary == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecuerdaHabilidad(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (EsTipo(gEffectBattler, TIPO_FUEGO) && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && (primary == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;

                gMensajeBatalla = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }

            if (!CanBeBurned(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_CONGELACION:
            if (!PuedeSerCongelado(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
                break;

            cancelMultiTurnMovesResult = CancelMultiTurnMoves(gEffectBattler);
            if (cancelMultiTurnMovesResult)
                gBattlescriptCurrInstr = cancelMultiTurnMovesResult;
            statusChanged = TRUE;
            break;
        case STATUS1_PARALYSIS:
            if (battlerAbility == ABILITY_LIMBER)
            {
                if (primary == TRUE)
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecuerdaHabilidad(gEffectBattler, ABILITY_LIMBER);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                    if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                    {
                        gMensajeBatalla = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                        gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                    }
                    else
                    {
                        gMensajeBatalla = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                    }
                    RESET_RETURN
                }
                else
                    break;
            }
            if (!CanParalyzeType(gEffectBattler) && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && (primary == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (!CanParalyzeType(gEffectBattler))
                break;
            if (!CanBeParalyzed(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_TOXIC_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY) && (primary == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecuerdaHabilidad(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gMensajeBatalla = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gEffectBattler) && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && (primary == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gMensajeBatalla = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (CanBePoisoned(gEffectBattler, HabilidadCombatiente(gEffectBattler)))
            {
                // It's redundant, because at this point we know the status1 value is 0.
                gBattleMons[gEffectBattler].status1 &= ~STATUS1_TOXIC_POISON;
                gBattleMons[gEffectBattler].status1 &= ~STATUS1_POISON;
                statusChanged = TRUE;
                break;
            }
            else
            {
                gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
            }
            break;
        }
        if (statusChanged == TRUE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            gBattleMons[gEffectBattler].status1 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];

            gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

            BtlController_EmitSetMonData(gEffectBattler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].status1), &gBattleMons[gEffectBattler].status1);
            MarcaCombatienteOcupado(gEffectBattler);

            if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
            {
                gMensajeBatalla = B_MSG_STATUSED_BY_ABILITY;
                gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
            }
            else
            {
                gMensajeBatalla = B_MSG_STATUSED;
            }

            // for synchronize
            if (gBattleScripting.moveEffect == MOVE_EFFECT_POISON || gBattleScripting.moveEffect == MOVE_EFFECT_TOXIC || gBattleScripting.moveEffect == MOVE_EFFECT_PARALYSIS || gBattleScripting.moveEffect == MOVE_EFFECT_BURN)
            {
                gCombate->synchronizeMoveEffect = gBattleScripting.moveEffect;
                gHitMarker |= HITMARKER_SYNCHRONISE_EFFECT;
            }
            return;
        }
        else if (statusChanged == FALSE)
        {
            gBattleScripting.moveEffect = 0;
            gBattlescriptCurrInstr++;
            return;
        }
        return;
    }
    else
    {
        if (gBattleMons[gEffectBattler].status2 & sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            switch (gBattleScripting.moveEffect)
            {
            case MOVE_EFFECT_CONFUSION:
                if (!CanBeConfused(gEffectBattler))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_CONFUSION_TURN(((Random()) % 4) + 2); // 2-5 turns
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                }
                break;
            case MOVE_EFFECT_FLINCH:
                if (battlerAbility == ABILITY_FUERZA_MENTAL)
                {
                    // Inner Focus ALWAYS prevents flinching but only activates
                    // on a move that's supposed to flinch, like Sorpresa
                    if (primary == TRUE)
                    {
                        gLastUsedAbility = ABILITY_FUERZA_MENTAL;
                        gBattlerAbility = gEffectBattler;
                        RecuerdaHabilidad(gEffectBattler, ABILITY_FUERZA_MENTAL);
                        gBattlescriptCurrInstr = BattleScript_FlinchPrevention;
                    }
                    else
                    {
                        gBattlescriptCurrInstr++;
                    }
                }
                else if (GetBattlerTurnOrderNum(gEffectBattler) > gCurrentTurnActionNumber)
                {
                    gBattleMons[gEffectBattler].status2 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_UPROAR:
                if (!(gBattleMons[gEffectBattler].status2 & STATUS2_UPROAR))
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBattler] = gCurrentMove;
                    gBattleMons[gEffectBattler].status2 |= STATUS2_UPROAR_TURN(B_UPROAR_TURNS >= GEN_5 ? 3 : (Random() & 3) + 2);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case EFECTO_MOVIMIENTO_SALTA_DINERO:
                // Don't scatter coins on the second hit of Parental Bond
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_2ND_HIT)
                {
                    u16 payday = gPaydayMoney;
                    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
                    gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
                    if (payday > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;

                    // For a move that hits multiple targets (i.e. Make it Rain)
                    // we only want to print the message on the final hit
                    if (!((moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY) && GetNextTarget(moveTarget, TRUE) != NUMERO_COMBATIENTES))
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = ScriptCombate_EfectoMovimientoDiaDePago;
                    }
                    else
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_CHARGING:
                gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gProtectStructs[gEffectBattler].chargingTurn = TRUE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_WRAP:
                if (gBattleMons[gEffectBattler].status2 & STATUS2_WRAPPED)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_WRAPPED;
                    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                        gDisableStructs[gEffectBattler].wrapTurns = 8;
                    else
                        gDisableStructs[gEffectBattler].wrapTurns = 4;

                    gCombate->wrappedMove[gEffectBattler] = gCurrentMove;
                    gCombate->wrappedBy[gEffectBattler] = gBattlerAttacker;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

                    for (gBattleCommunication[MULTISTRING_CHOOSER] = 0; gBattleCommunication[MULTISTRING_CHOOSER] < NUM_TRAPPING_MOVES; gBattleCommunication[MULTISTRING_CHOOSER]++)
                    {
                        static const u16 sTrappingMoves[NUM_TRAPPING_MOVES] =
                            {
                                MOVE_BIND,
                                MOVE_WRAP,
                                MOVE_FIRE_SPIN,
                                MOVE_CLAMP, --> STRINGID_PKMNCLAMPED MOVE_WHIRLPOOL,
                                MOVE_SAND_TOMB,
                                MOVE_MAGMA_STORM,
                                MOVE_INFESTATION,
                                MOVE_THUNDER_CAGE};
                        if (sTrappingMoves[gBattleCommunication[MULTISTRING_CHOOSER]] == gCurrentMove)
                            break;
                    }
                }
                break;
            case MOVE_EFFECT_ATK_PLUS_1:
            case MOVE_EFFECT_DEF_PLUS_1:
            case MOVE_EFFECT_SPD_PLUS_1:
            case MOVE_EFFECT_SP_ATK_PLUS_1:
            case MOVE_EFFECT_SP_DEF_PLUS_1:
            case MOVE_EFFECT_ACC_PLUS_1:
            case MOVE_EFFECT_EVS_PLUS_1:
                if (NoAliveMonsForEitherParty() || ChangeStatBuffs(SET_STAT_BUFF_VALUE(1),
                                                                   gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_1 + 1,
                                                                   affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0) == STAT_CHANGE_DIDNT_WORK)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatUp;
                }
                break;
            case MOVE_EFFECT_ATK_MINUS_1:
            case MOVE_EFFECT_DEF_MINUS_1:
            case MOVE_EFFECT_SPD_MINUS_1:
            case MOVE_EFFECT_SP_ATK_MINUS_1:
            case MOVE_EFFECT_SP_DEF_MINUS_1:
            case MOVE_EFFECT_ACC_MINUS_1:
            case MOVE_EFFECT_EVS_MINUS_1:
                if (affectsUser == MOVE_EFFECT_AFFECTS_USER)
                    flags = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN;
                else
                    flags = 0;
                if (mirrorArmorReflected)
                    flags |= (STAT_CHANGE_ALLOW_PTR * !affectsUser);
                else
                    flags |= STAT_CHANGE_UPDATE_MOVE_EFFECT;

                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_1 + 1,
                                    flags, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
                {
                    if (!mirrorArmorReflected)
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatDown;
                }
                break;
            case MOVE_EFFECT_ATK_PLUS_2:
            case MOVE_EFFECT_DEF_PLUS_2:
            case MOVE_EFFECT_SPD_PLUS_2:
            case MOVE_EFFECT_SP_ATK_PLUS_2:
            case MOVE_EFFECT_SP_DEF_PLUS_2:
            case MOVE_EFFECT_ACC_PLUS_2:
            case MOVE_EFFECT_EVS_PLUS_2:
                if (NoAliveMonsForEitherParty() || ChangeStatBuffs(SET_STAT_BUFF_VALUE(2),
                                                                   gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_2 + 1,
                                                                   affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0) == STAT_CHANGE_DIDNT_WORK)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatUp;
                }
                break;
            case MOVE_EFFECT_ATK_MINUS_2:
            case MOVE_EFFECT_DEF_MINUS_2:
            case MOVE_EFFECT_SPD_MINUS_2:
            case MOVE_EFFECT_SP_ATK_MINUS_2:
            case MOVE_EFFECT_SP_DEF_MINUS_2:
            case MOVE_EFFECT_ACC_MINUS_2:
            case MOVE_EFFECT_EVS_MINUS_2:
                if (affectsUser == MOVE_EFFECT_AFFECTS_USER)
                    flags = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN;
                else
                    flags = 0;
                if (mirrorArmorReflected && !affectsUser)
                    flags |= STAT_CHANGE_ALLOW_PTR;
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_2 + 1,
                                    flags | STAT_CHANGE_UPDATE_MOVE_EFFECT, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
                {
                    if (!mirrorArmorReflected)
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatDown;
                }
                break;
            case MOVE_EFFECT_RECHARGE:
                gBattleMons[gEffectBattler].status2 |= STATUS2_RECHARGE;
                gDisableStructs[gEffectBattler].rechargeTimer = 2;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_RAGE:
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_RAGE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_STEAL_ITEM:
            {
                if (gBattleMons[gBattlerAttacker].item != ITEM_NONE || gBattleMons[gBattlerTarget].item == ITEM_NONE)
                {
                    gBattlescriptCurrInstr++;
                }
                else if (HabilidadCombatiente(gBattlerTarget) == ABILITY_STICKY_HOLD || HabilidadCombatiente(gBattlerTarget) == ABILITY_TERRITORIAL)
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_NoItemSteal;

                    gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
                    RecuerdaHabilidad(gBattlerTarget, gLastUsedAbility);
                }
                else
                {
                    StealTargetItem(gBattlerAttacker, gBattlerTarget);             // Attacker steals target item
                    gBattleMons[gBattlerAttacker].item = ITEM_NONE;                // Item assigned later on with thief (see MOVEEND_CHANGED_ITEMS)
                    gCombate->changedItems[gBattlerAttacker] = gLastUsedItem; // Stolen item to be assigned later
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_ItemSteal;
                }
            }
            break;
            case MOVE_EFFECT_PREVENT_ESCAPE:
                gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_NIGHTMARE:
                gBattleMons[gBattlerTarget].status2 |= STATUS2_NIGHTMARE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_ALL_STATS_UP:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_AllStatsUp;
                }
                break;
            case MOVE_EFFECT_GIRO_RAPIDO:
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_GiroRapidoAway;
                break;
            case MOVE_EFFECT_ATK_DEF_DOWN:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_AtkDefDown;
                }
                break;
            case MOVE_EFFECT_DEF_SPDEF_DOWN:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_DefSpDefDown;
                }
                break;
            case MOVE_EFFECT_THRASH:
                gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gBattleMons[gEffectBattler].status2 |= STATUS2_LOCK_CONFUSE_TURN(NumeroAleatorioEnRango(2, 3));
                break;
            case MOVE_EFFECT_CLEAR_SMOG:
                for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
                {
                    if (gBattleMons[gEffectBattler].statStages[i] != ESTADISTICA_NEUTRA)
                        break;
                }
                if ((HaSidoDaniado(gEffectBattler)) && i != NUMERO_ESTADISTICAS_BATALLA)
                {
                    for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
                        gBattleMons[gEffectBattler].statStages[i] = ESTADISTICA_NEUTRA;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
                }
                break;
            case MOVE_EFFECT_FLAME_BURST:
                if (IsBattlerAlive(ALIADO(gBattlerTarget)) && !(gStatuses3[ALIADO(gBattlerTarget)] & STATUS3_SEMI_INVULNERABLE) && HabilidadCombatiente(ALIADO(gBattlerTarget)) != ABILITY_MAGIC_GUARD)
                {
                    gBattleScripting.savedBattler = ALIADO(gBattlerTarget);
                    gBattleMoveDamage = gBattleMons[ALIADO(gBattlerTarget)].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
                }
                break;
            case MOVE_EFFECT_FEINT:
                if (IS_BATTLER_PROTECTED(gBattlerTarget))
                {
                    gProtectStructs[gBattlerTarget].protected = FALSE;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
                }
                break;
            case MOVE_EFFECT_THROAT_CHOP:
                gDisableStructs[gEffectBattler].throatChopTimer = 2;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_BUG_BITE:
                if (ItemId_GetPocket(gBattleMons[gEffectBattler].item) == POCKET_BERRIES && (battlerAbility != ABILITY_STICKY_HOLD || battlerAbility != ABILITY_TERRITORIAL))
                {
                    // target loses their berry
                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    CheckSetUnburden(gEffectBattler);

                    BtlController_EmitSetMonData(gEffectBattler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
                    MarcaCombatienteOcupado(gEffectBattler);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
                }
                break;
            case MOVE_EFFECT_TRAP_BOTH:
                if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_BothCanNoLongerEscape;
                }
                if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
                    gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;

                if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
                    gDisableStructs[gBattlerAttacker].battlerPreventingEscape = gBattlerTarget;

                gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_ESCAPE_PREVENTION;
                break;
            case MOVE_EFFECT_DIRE_CLAW:
                break;
            case MOVE_EFFECT_STEALTH_ROCK:
                if (!(gSideStatuses[GetBattlerSide(gEffectBattler)] & SIDE_STATUS_STEALTH_ROCK))
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StealthRockActivates;
                }
                break;
            case MOVE_EFFECT_SPIKES:
                if (gSideTimers[GetBattlerSide(gEffectBattler)].spikesAmount < 3)
                {
                    gMensajeBatalla = B_MSG_SPIKESSCATTERED;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_SpikesActivates;
                }
                break;
            case MOVE_EFFECT_SECRET_POWER:
                break;
            }
        }
    }

    gBattleScripting.moveEffect = 0;
}

static bool32 CanApplyAdditionalEffect(const struct AdditionalEffect *additionalEffect)
{
    // Self-targeting move effects only apply after the last mon has been hit
    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
    if (additionalEffect->self && (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY) && GetNextTarget(moveTarget, TRUE) != NUMERO_COMBATIENTES)
        return FALSE;

    // Certain move effects only apply if the target raised stats this turn (e.g. Burning Jealousy)
    if (additionalEffect->onlyIfTargetRaisedStats && !gProtectStructs[gBattlerTarget].statRaised)
        return FALSE;

    // Certain additional effects only apply on a two-turn move's charge turn
    if (additionalEffect->onChargeTurnOnly != gProtectStructs[gBattlerAttacker].chargingTurn)
        return FALSE;

    return TRUE;
}

static void Cmd_setadditionaleffects(void)
{
    CMD_ARGS();

    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        if (gMovimientos[gCurrentMove].numAdditionalEffects > gCombate->additionalEffectsCounter)
        {
            u32 percentChance;
            const struct AdditionalEffect *additionalEffect = &gMovimientos[gCurrentMove].additionalEffects[gCombate->additionalEffectsCounter];
            const u8 *currentPtr = gBattlescriptCurrInstr;

            // Various checks for if this move effect can be applied this turn
            if (CanApplyAdditionalEffect(additionalEffect))
            {
                percentChance = CalculaProbabilidadEfectoSecundario(HabilidadCombatiente(gBattlerAttacker), additionalEffect);

                // Activate effect if it's primary (chance == 0) or if RNGesus says so
                if ((percentChance == 0) || PorcentajeAleatorio(percentChance))
                {
                    gBattleScripting.moveEffect = additionalEffect->moveEffect | (MOVE_EFFECT_AFFECTS_USER * (additionalEffect->self));
                    SetMoveEffect(percentChance == 0);
                }
            }

            // Move script along if we haven't jumped elsewhere
            if (gBattlescriptCurrInstr == currentPtr)
                gBattlescriptCurrInstr = cmd->nextInstr;

            // Call setadditionaleffects again in the case of a move with multiple effects
            gCombate->additionalEffectsCounter++;
            if (gMovimientos[gCurrentMove].numAdditionalEffects > gCombate->additionalEffectsCounter)
                gBattleScripting.moveEffect = MOVE_EFFECT_CONTINUE;
            else
                gBattleScripting.moveEffect = gCombate->additionalEffectsCounter = 0;
        }
        else
        {
            gBattleScripting.moveEffect = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattleScripting.moveEffect = 0;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }

    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_seteffectprimary(void)
{
    CMD_ARGS();

    SetMoveEffect(TRUE);
}

static void Cmd_seteffectsecondary(void)
{
    CMD_ARGS();

    SetMoveEffect(FALSE);
}

static void Cmd_clearstatusfromeffect(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT)
        gBattleMons[battler].status1 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
    else
    {
        gBattleMons[battler].status2 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
        if (gBattleScripting.moveEffect == MOVE_EFFECT_CHARGING)
            gProtectStructs[battler].chargingTurn = FALSE;
    }

    gBattleScripting.moveEffect = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_tryfaintmon(void)
{
    CMD_ARGS(u8 battler, bool8 isSpikes, const u8 *instr);
    u32 battler, destinyBondBattler;
    const u8 *faintScript;

    battler = GetBattlerForBattleScript(cmd->battler);
    if (cmd->isSpikes != 0)
    {
        if (gHitMarker & HITMARKER_FAINTED(battler))
        {
            BattleScriptPop();
            gBattlescriptCurrInstr = cmd->instr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        if (cmd->battler == BS_ATTACKER)
        {
            destinyBondBattler = gBattlerTarget;
            faintScript = BattleScript_FaintAttacker;
        }
        else
        {
            destinyBondBattler = gBattlerAttacker;
            faintScript = BattleScript_FaintTarget;
        }
        if (!(gAbsentBattlerFlags & (1u << battler)) && !IsBattlerAlive(battler))
        {
            gHitMarker |= HITMARKER_FAINTED(battler);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = faintScript;
            if (GetBattlerSide(battler) == LADO_JUGADOR)
            {
                gHitMarker |= HITMARKER_PLAYER_FAINTED;
                gCombate->contadorDebilitadosJugador++;
                AdjustFriendshipOnBattleFaint(battler);
                gSideTimers[LADO_JUGADOR].retaliateTimer = 2;
            }
            else
            {
                gCombate->contadorDebilitadosRival++;
                gSideTimers[LADO_OPONENTE].retaliateTimer = 2;
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && IsBattlerAlive(gBattlerAttacker))
            {
                gHitMarker &= ~HITMARKER_DESTINYBOND;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattleMoveDamage = gBattleMons[destinyBondBattler].hp;
                gBattlescriptCurrInstr = BattleScript_DestinyBondTakesLife;
            }
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_dofaintanimation(void)
{
    CMD_ARGS(u8 battler);

    if (!HayAlgunCombatienteOcupado())
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitFaintAnimation(battler, BUFFER_A);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_cleareffectsonfaint(void)
{
    CMD_ARGS(u8 battler);

    if (!HayAlgunCombatienteOcupado())
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        const u8 *clearDataResult = NULL;
        if (!IsBattlerAlive(battler))
        {
            gBattleMons[battler].status1 = 0;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
            MarcaCombatienteOcupado(battler);
        }

        clearDataResult = FaintClearSetData(battler); // Effects like attractions, trapping, etc.
        if (clearDataResult)
            gBattlescriptCurrInstr = clearDataResult;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifstatus(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battler].status1 & flags && IsBattlerAlive(battler))
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus2(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battler].status2 & flags && IsBattlerAlive(battler))
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifability(void)
{
    CMD_ARGS(u8 battler, u16 ability, const u8 *jumpInstr);

    u32 foundBattler = 0xFF;
    u32 checkBattler;

    switch (cmd->battler)
    {
    default:
        checkBattler = GetBattlerForBattleScript(cmd->battler);
        if (HabilidadCombatiente(checkBattler) == cmd->ability)
            foundBattler = checkBattler;
        break;

    case BS_ATTACKER_SIDE:
        for (checkBattler = 0; checkBattler < gBattlersCount; checkBattler++)
        {
            if (GetBattlerSide(checkBattler) == GetBattlerSide(gBattlerAttacker) && IsBattlerAlive(checkBattler) && HabilidadCombatiente(checkBattler) == cmd->ability)
            {
                foundBattler = checkBattler;
                break;
            }
        }
        break;

    case BS_TARGET_SIDE:
        for (checkBattler = 0; checkBattler < gBattlersCount; checkBattler++)
        {
            if (GetBattlerSide(checkBattler) != GetBattlerSide(gBattlerAttacker) && IsBattlerAlive(checkBattler) && HabilidadCombatiente(checkBattler) == cmd->ability)
            {
                foundBattler = checkBattler;
                break;
            }
        }
        break;
    }

    if (foundBattler != 0xFF)
    {
        gLastUsedAbility = cmd->ability;
        gBattlerAbility = foundBattler;
        RecuerdaHabilidad(foundBattler, gLastUsedAbility);
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifsideaffecting(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u32 side = GetBattlerSide(GetBattlerForBattleScript(cmd->battler));

    if (gSideStatuses[side] & cmd->flags)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstat(void)
{
    CMD_ARGS(u8 battler, u8 comparison, u8 stat, u8 value, const u8 *jumpInstr);

    bool32 ret = 0;
    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u8 stat = cmd->stat;
    u8 value = cmd->value;
    u8 comparison = cmd->comparison;

    ret = CompareStat(battler, stat, value, comparison);

    if (ret)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus3condition(void)
{
    CMD_ARGS(u8 battler, u32 flags, bool8 jumpIfTrue, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (cmd->jumpIfTrue)
    {
        if ((gStatuses3[battler] & cmd->flags) != 0)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        if ((gStatuses3[battler] & cmd->flags) != 0)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpbasedontype(void)
{
    CMD_ARGS(u8 battler, u8 type, u8 jumpIfType, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u8 type = cmd->type;
    const u8 *jumpInstr = cmd->jumpInstr;

    // jumpiftype
    if (cmd->jumpIfType)
    {
        if (EsTipo(battler, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    // jumpifnottype
    else
    {
        if (!EsTipo(battler, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static u32 GetMonHoldEffect(struct Pokemon *mon)
{
    u32 holdEffect;
    u32 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    holdEffect = ItemId_GetHoldEffect(item);

    return holdEffect;
}

static void Cmd_getexp(void)
{
    CMD_ARGS(u8 battler);

    s32 i; // also used as stringId
    u8 *expMonId = &gCombate->expGetterMonId;

    gBattlerFainted = GetBattlerForBattleScript(cmd->battler);

    switch (gBattleScripting.getexpState)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBattlerFainted) != LADO_OPONENTE)
            gBattleScripting.getexpState = 6; // goto last case
        else
        {
            gBattleScripting.getexpState++;
            gCombate->givenExpMons |= (1u << gBattlerPartyIndexes[gBattlerFainted]);
        }
        break;
    case 1: // calculate experience points to redistribute
    {
        u32 orderId = 0;
        u32 calculatedExp = 0;
        u32 *exp = &gCombate->expValue;
        u32 sentInBits = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];
        s32 viaSentIn = 0;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (!IsValidForBattle(&gPlayerParty[i]))
                continue;
            if ((1u << i) & sentInBits)
                viaSentIn++;
        }
        // Get order of mons getting exp: 1. all mons via sent in, 2. all mons via exp share
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if ((1u << i) & sentInBits)
                gCombate->expGettersOrder[orderId++] = i;
        }
        if (orderId < PARTY_SIZE)
            gCombate->expGettersOrder[orderId] = PARTY_SIZE;

        calculatedExp = gSpeciesInfo[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level;

        if (EsCombateContraEntrenador(gCombate->tipoCombate))
            calculatedExp = (calculatedExp * 150) / 100;

        *exp = calculatedExp;

        gBattleScripting.getexpState++;
        gCombate->expOrderId = 0;
        *expMonId = gCombate->expGettersOrder[0];
        gCombate->expSentInMons = sentInBits;
    }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (!HayAlgunCombatienteOcupado())
        {
            bool32 wasSentOut = (gCombate->expSentInMons & (1u << *expMonId)) != 0;

            if (GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            {
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if (GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL) == MAX_LEVEL)
            {
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
                MonGainEVs(&gPlayerParty[*expMonId], gBattleMons[gBattlerFainted].species);
            }
            else
            {
                // Music change in a wild battle after fainting opposing pokemon.
                if (!(EsCombateContraEntrenador(gCombate->tipoCombate)) && (gBattleMons[0].hp || (EsCombateContraEntrenador(gCombate->tipoCombate) && gBattleMons[2].hp)) && !IsBattlerAlive(OPONENTE_IZQUIERDA) && !IsBattlerAlive(OPONENTE_DERECHA))
                {
                    BattleStopLowHpSound();
                    PlayBGM(MUS_VICTORY_WILD);
                }

                if (IsValidForBattle(&gPlayerParty[*expMonId]))
                {
                    if (wasSentOut)
                        gBattleMoveDamage = gCombate->expValue;
                    else
                        gBattleMoveDamage = 0;

                    ApplyExperienceMultipliers(&gBattleMoveDamage, *expMonId, gBattlerFainted);

                    // i = STRINGID_EMPTYSTRING4;

                    // get exp getter battler
                    if (EsCombateContraEntrenador(gCombate->tipoCombate))
                    {
                        if (gBattlerPartyIndexes[2] == *expMonId && !(gAbsentBattlerFlags & 4))
                            gCombate->expGetterBattlerId = 2;
                        else
                        {
                            if (!(gAbsentBattlerFlags & 1))
                                gCombate->expGetterBattlerId = 0;
                            else
                                gCombate->expGetterBattlerId = 2;
                        }
                    }
                    else
                        gCombate->expGetterBattlerId = 0;

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gCombate->expGetterBattlerId, *expMonId);
                    // buffer 'gained' or 'gained a boosted'
                    // PREPARE_STRING_BUFFER(gBattleTextBuff2, i);
                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 6, gBattleMoveDamage);

                    if (wasSentOut)
                        PrepareStringBattle(STRINGID_PKMNGAINEDEXP, gCombate->expGetterBattlerId);

                    MonGainEVs(&gPlayerParty[*expMonId], gBattleMons[gBattlerFainted].species);
                }
                gBattleScripting.getexpState++;
            }
        }
        break;
    case 3: // Set stats and give exp
        if (!HayAlgunCombatienteOcupado())
        {
            gBattleResources->bufferB[gCombate->expGetterBattlerId][0] = 0;
            if (GetMonData(&gPlayerParty[*expMonId], MON_DATA_HP) && GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL) != MAX_LEVEL)
            {
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_PS] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_MAX_HP);
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_ATAQUE] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_ATK);
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_DEFENSA] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_DEF);
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_VELOCIDAD] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPEED);
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_ATAQUE_ESPECIAL] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPATK);
                gBattleResources->beforeLvlUp->stats[ESTADISTICA_DEFENSA_ESPECIAL] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPDEF);

                BtlController_EmitExpUpdate(gCombate->expGetterBattlerId, BUFFER_A, *expMonId, gBattleMoveDamage);
                MarcaCombatienteOcupado(gCombate->expGetterBattlerId);
            }
            gBattleScripting.getexpState++;
        }
        break;
    case 4: // lvl up if necessary
        if (!HayAlgunCombatienteOcupado())
        {
            u32 expBattler = gCombate->expGetterBattlerId;
            if (gBattleResources->bufferB[expBattler][0] == CONTROLLER_TWORETURNVALUES && gBattleResources->bufferB[expBattler][1] == B_ACTION_SUBIO_NIVEL)
            {
                u16 temp, battler = 0xFF;
                if (EsCombateContraEntrenador(gCombate->tipoCombate) && gBattlerPartyIndexes[expBattler] == *expMonId)
                    HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[expBattler]], expBattler);

                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, expBattler, *expMonId);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL));

                BattleScriptPushCursor();
                gLeveledUpInBattle |= 1 << *expMonId;
                gBattlescriptCurrInstr = BattleScript_LevelUp;
                gBattleMoveDamage = T1_READ_32(&gBattleResources->bufferB[expBattler][2]);
                AdjustFriendship(&gPlayerParty[*expMonId], FRIENDSHIP_EVENT_GROW_LEVEL);

                BattleAnimateBackSprite(&gSprites[gBattlerSpriteIds[expBattler]], gBattleMons[expBattler].species); // baile al subir de nivel

                // update battle mon structure after level up
                if (gBattlerPartyIndexes[0] == *expMonId && gBattleMons[0].hp)
                    battler = 0;
                else if (gBattlerPartyIndexes[2] == *expMonId && gBattleMons[2].hp && (EsCombateContraEntrenador(gCombate->tipoCombate)))
                    battler = 2;

                if (battler != 0xFF)
                {
                    CopyMonLevelAndBaseStatsToBattleMon(battler, &gPlayerParty[*expMonId]);
                }

                gBattleScripting.getexpState = 5;
            }
            else
            {
                gBattleMoveDamage = 0;
                gBattleScripting.getexpState = 5;
            }
        }
        break;
    case 5:                    // looper increment
        if (gBattleMoveDamage) // there is exp to give, goto case 3 that gives exp
        {
            gBattleScripting.getexpState = 3;
        }
        else
        {
            if ((++gCombate->expOrderId) < PARTY_SIZE)
            {
                *expMonId = gCombate->expGettersOrder[gCombate->expOrderId];
                if (*expMonId < PARTY_SIZE)
                {
                    gBattleScripting.getexpState = 2; // loop again
                    break;
                }
            }
            gBattleScripting.getexpState = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (!HayAlgunCombatienteOcupado())
        {
            // not sure why gf clears the item and ability here
            gCombate->expOrderId = 0;
            gBattleMons[gBattlerFainted].item = ITEM_NONE;
            gBattleMons[gBattlerFainted].ability = ABILITY_NONE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

bool32 NoAliveMonsForPlayer(void)
{
    u32 i;
    u32 maxI = PARTY_SIZE;
    u32 HP_count = 0;

    // Get total HP for the player's party to determine if the player has lost
    for (i = 0; i < maxI; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
        }
    }

    return (HP_count == 0);
}

static bool32 NoAliveMonsForOpponent(void)
{
    u32 i;
    u32 HP_count = 0;

    // Get total HP for the enemy's party to determine if the player has won
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG))
            HP_count += GetMonData(&gEnemyParty[i], MON_DATA_HP);
    }

    return (HP_count == 0);
}

bool32 NoAliveMonsForEitherParty(void)
{
    return (NoAliveMonsForPlayer() || NoAliveMonsForOpponent());
}

// The only thing this command does is check whether the player has won/lost by totaling each team's HP.
// It then sets gBattleOutcome accordingly, if necessary.
static void Cmd_checkteamslost(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (HayAlgunCombatienteOcupado())
        return;

    if (NoAliveMonsForPlayer())
        gBattleOutcome |= B_OUTCOME_LOST;

    if (NoAliveMonsForOpponent())
        gBattleOutcome |= B_OUTCOME_WON;

    // Fair switching - everyone has to switch in most at the same time, without knowing which pokemon the other trainer selected.
    // In vanilla Emerald this was only used for link battles, in expansion it's also used for regular trainer battles.
    // For battles that haven't ended, count number of empty battler spots
    // In multi battles, jump to pointer if more than 1 spot empty
    // In non-multi battles, jump to pointer if 1 spot is missing on both sides
    if (gBattleOutcome == 0 && (EsCombateContraEntrenador(gCombate->tipoCombate)))
    {
        s32 i, emptyPlayerSpots, emptyOpponentSpots;

        for (emptyPlayerSpots = 0, i = 0; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_FAINTED(i)) && (!gSpecialStatuses[i].faintedHasReplacement))
                emptyPlayerSpots++;
        }

        emptyOpponentSpots = 0;
        for (i = 1; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_FAINTED(i)) && (!gSpecialStatuses[i].faintedHasReplacement))
                emptyOpponentSpots++;
        }

        if (emptyOpponentSpots != 0 && emptyPlayerSpots != 0)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void MoveValuesCleanUp(void)
{
    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    gEsGolpeCritico = FALSE;
    gBattleScripting.moveEffect = 0;
    if (!gCombate->contadorMultigolpes)
        gHitMarker &= ~HITMARKER_DESTINYBOND;
    gHitMarker &= ~HITMARKER_SYNCHRONISE_EFFECT;
}

static void Cmd_movevaluescleanup(void)
{
    CMD_ARGS();

    MoveValuesCleanUp();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setmultihit(void)
{
    CMD_ARGS(u8 value);

    gCombate->contadorMultigolpes = cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_decrementmultihit(void)
{
    CMD_ARGS(const u8 *loopInstr);

    if (--gCombate->contadorMultigolpes == 0)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->loopInstr;
}

static void Cmd_goto(void)
{
    CMD_ARGS(const u8 *instr);

    gBattlescriptCurrInstr = cmd->instr;
}

static void Cmd_jumpifbyte(void)
{
    CMD_ARGS(u8 comparison, const u8 *bytePtr, u8 value, const u8 *jumpInstr);

    u8 comparison = cmd->comparison;
    const u8 *bytePtr = cmd->bytePtr;
    u8 value = cmd->value;
    const u8 *jumpInstr = cmd->jumpInstr;

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (comparison)
    {
    case COMPARACION_IGUAL:
        if (*bytePtr == value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_DESIGUAL:
        if (*bytePtr != value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_MAYOR:
        if (*bytePtr > value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_MENOR:
        if (*bytePtr < value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_BITS_COMUNES:
        if (*bytePtr & value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_BITS_DISTINTOS:
        if (!(*bytePtr & value))
            gBattlescriptCurrInstr = jumpInstr;
        break;
    }
}

static void Cmd_jumpifhalfword(void)
{
    CMD_ARGS(u8 comparison, const u16 *halfwordPtr, u16 value, const u8 *jumpInstr);

    u8 comparison = cmd->comparison;
    const u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;
    const u8 *jumpInstr = cmd->jumpInstr;

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (comparison)
    {
    case COMPARACION_IGUAL:
        if (*halfwordPtr == value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_DESIGUAL:
        if (*halfwordPtr != value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_MAYOR:
        if (*halfwordPtr > value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case COMPARACION_MENOR:
        if (*halfwordPtr < value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    }
}

static void Cmd_jumpifword(void)
{
    CMD_ARGS(u8 comparison, const u32 *wordPtr, u32 value, const u8 *jumpInstr);

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (cmd->comparison)
    {
    case COMPARACION_IGUAL:
        if (*cmd->wordPtr == cmd->value)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;

    case COMPARACION_DESIGUAL:
        if (*cmd->wordPtr != cmd->value)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;

    case COMPARACION_MAYOR:
        if (*cmd->wordPtr > cmd->value)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;

    case COMPARACION_MENOR:
        if (*cmd->wordPtr < cmd->value)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;

    case COMPARACION_BITS_COMUNES:
        if (*cmd->wordPtr & cmd->value)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;

    case COMPARACION_BITS_DISTINTOS:
        if (!(*cmd->wordPtr & cmd->value))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        break;
    }
}

static void Cmd_jumpifarrayequal(void)
{
    CMD_ARGS(const u8 *array1, const u8 *array2, u8 size, const u8 *jumpInstr);

    const u8 *array1 = cmd->array1;
    const u8 *array2 = cmd->array2;
    u32 size = cmd->size;
    const u8 *jumpInstr = cmd->jumpInstr;

    u32 i;
    for (i = 0; i < size; i++)
    {
        if (*array1 != *array2)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            break;
        }
        array1++, array2++;
    }

    if (i == size)
        gBattlescriptCurrInstr = jumpInstr;
}

static void Cmd_jumpifarraynotequal(void)
{
    CMD_ARGS(const u8 *array1, const u8 *array2, u8 size, const u8 *jumpInstr);

    u8 equalBytes = 0;
    const u8 *array1 = cmd->array1;
    const u8 *array2 = cmd->array2;
    u32 size = cmd->size;
    const u8 *jumpInstr = cmd->jumpInstr;

    u32 i;
    for (i = 0; i < size; i++)
    {
        if (*array1 == *array2)
            equalBytes++;
        array1++, array2++;
    }

    if (equalBytes != size)
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setbyte(void)
{
    CMD_ARGS(u8 * bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr = cmd->value;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_addbyte(void)
{
    CMD_ARGS(u8 * bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr += cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_subbyte(void)
{
    CMD_ARGS(u8 * bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr -= cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_copyarray(void)
{
    CMD_ARGS(u8 * dest, const u8 *src, u8 size);

    u8 *dest = cmd->dest;
    const u8 *src = cmd->src;
    s32 size = cmd->size;

    s32 i;
    for (i = 0; i < size; i++)
        dest[i] = src[i];

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_copyarraywithindex(void)
{
    CMD_ARGS(u8 * dest, const u8 *src, const u8 *indexPtr, u8 size);

    u8 *dest = cmd->dest;
    const u8 *src = cmd->src;
    const u8 *indexPtr = cmd->indexPtr;
    s32 size = cmd->size;

    s32 i;
    for (i = 0; i < size; i++)
        dest[i] = src[i + *indexPtr];

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orbyte(void)
{
    CMD_ARGS(u8 * bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr |= cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orhalfword(void)
{
    CMD_ARGS(u16 * halfwordPtr, u16 value);

    u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;

    *halfwordPtr |= value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orword(void)
{
    CMD_ARGS(u32 * wordPtr, u32 value);

    u32 *wordPtr = cmd->wordPtr;
    u32 value = cmd->value;

    *wordPtr |= value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bicbyte(void)
{
    CMD_ARGS(u8 * bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr &= ~cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bichalfword(void)
{
    CMD_ARGS(u16 * halfwordPtr, u16 value);

    u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;

    *halfwordPtr &= ~value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bicword(void)
{
    CMD_ARGS(u32 * wordPtr, u32 value);

    u32 *wordPtr = cmd->wordPtr;
    u32 value = cmd->value;

    *wordPtr &= ~value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_pause(void)
{
    CMD_ARGS(u16 frames);

    if (!HayAlgunCombatienteOcupado())
    {
        u16 value = cmd->frames;
        if (++gPauseCounterBattle >= value)
        {
            gPauseCounterBattle = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Pausa(u32 numeroFrames)
{
    if (!HayAlgunCombatienteOcupado())
    {
        if (++gPauseCounterBattle >= numeroFrames)
        {
            gPauseCounterBattle = 0;
        }
    }
}

static void Cmd_waitstate(void)
{
    CMD_ARGS();

    if (!HayAlgunCombatienteOcupado())
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_healthbar_update(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (cmd->battler == BS_TARGET)
        battler = gBattlerTarget;
    else
        battler = gBattlerAttacker;

    BtlController_EmitHealthBarUpdate(battler, BUFFER_A, gBattleMoveDamage);
    MarcaCombatienteOcupado(battler);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_return(void)
{
    BattleScriptPop();
}

static void Cmd_end(void)
{
    CMD_ARGS();
    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

static void Cmd_end2(void)
{
    CMD_ARGS();

    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

// Pops the main function stack
static void Cmd_end3(void)
{
    CMD_ARGS();

    BattleScriptPop();
    if (gBattleResources->battleCallbackStack->size != 0)
        gBattleResources->battleCallbackStack->size--;
    gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
}

static void Cmd_call(void)
{
    CMD_ARGS(const u8 *instr);

    BattleScriptPush(cmd->nextInstr);
    gBattlescriptCurrInstr = cmd->instr;
}

static void Cmd_setroost(void)
{
    CMD_ARGS();

    gBattleResources->flags[gBattlerAttacker] |= RESOURCE_FLAG_ROOST;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifabilitypresent(void)
{
    CMD_ARGS(u32 habilidad, const u8 *jumpInstr);

    u32 habilidad = cmd->habilidad;
    u32 combatienteConHabilidad = QueCombatienteTieneHabilidad(habilidad);
    if (combatienteConHabilidad)
    {
        gBattlerAbility = combatienteConHabilidad - 1; //??????? comprobar
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_endselectionscript(void)
{
    CMD_ARGS();

    *(gBattlerAttacker + gCombate->selectionScriptFinished) = TRUE;
}

static void PlayAnimation(u32 battler, u8 animId, const u16 *argPtr, const u8 *nextInstr)
{
    if (animId == B_ANIM_STATS_CHANGE || animId == B_ANIM_FORM_CHANGE || animId == B_ANIM_SUBSTITUTE_FADE)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
    else if (gHitMarker & (HITMARKER_DISABLE_ANIMATION) && animId != B_ANIM_RESTORE_BG)
    {
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
    }
    else if (animId == B_ANIM_RAIN_CONTINUES || animId == B_ANIM_SUN_CONTINUES || animId == B_ANIM_SANDSTORM_CONTINUES || animId == B_ANIM_SNOW_CONTINUES || animId == B_ANIM_FOG_CONTINUES)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
    else if (gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr = nextInstr;
    }
    else
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
}

static void Cmd_playanimation(void)
{
    CMD_ARGS(u8 battler, u8 animId, const u16 *argPtr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    PlayAnimation(battler, cmd->animId, cmd->argPtr, cmd->nextInstr);
}

// Same as playanimation, except it takes a pointer to some animation id, instead of taking the value directly
static void Cmd_playanimation_var(void)
{
    CMD_ARGS(u8 battler, const u8 *animIdPtr, const u16 *argPtr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    PlayAnimation(battler, *(cmd->animIdPtr), cmd->argPtr, cmd->nextInstr);
}

static void Cmd_setgraphicalstatchangevalues(void)
{
    CMD_ARGS();

    u8 value = GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger);

    switch (value)
    {
    case SET_STAT_BUFF_VALUE(1): // +1
        value = STAT_ANIM_PLUS1 + 1;
        break;
    case SET_STAT_BUFF_VALUE(2): // +2
        value = STAT_ANIM_PLUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(3): // +3
        value = STAT_ANIM_PLUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE: // -1
        value = STAT_ANIM_MINUS1 + 1;
        break;
    case SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE: // -2
        value = STAT_ANIM_MINUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(3) | STAT_BUFF_NEGATIVE: // -3
        value = STAT_ANIM_MINUS2 + 1;
        break;
    default: // <-12,-4> and <4, 12>
        if (value & STAT_BUFF_NEGATIVE)
            value = STAT_ANIM_MINUS2 + 1;
        else
            value = STAT_ANIM_PLUS2 + 1;
        break;
    }
    gBattleScripting.animArg1 = GET_STAT_BUFF_ID(gBattleScripting.statChanger) + value - 1;
    gBattleScripting.animArg2 = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playstatchangeanimation(void)
{
    CMD_ARGS(u8 battler, u8 stats, u8 flags);

    u32 currStat = 0;
    u32 statAnimId = 0;
    u32 changeableStatsCount = 0;
    u32 startingStatAnimId = 0;
    u32 flags = cmd->flags;
    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u32 ability = HabilidadCombatiente(battler);
    u32 stats = cmd->stats;

    if (ability == ABILITY_RESPONDON)
    {
        flags ^= STAT_CHANGE_NEGATIVE;
        RecuerdaHabilidadCombate(battler, ability);
    }
    else if (ability == ABILITY_SIMPLE)
    {
        flags |= STAT_CHANGE_BY_TWO;
        RecuerdaHabilidad(battler, ability);
    }

    if (flags & STAT_CHANGE_NEGATIVE) // goes down
    {
        if (flags & STAT_CHANGE_BY_TWO)
            startingStatAnimId = STAT_ANIM_MINUS2;
        else
            startingStatAnimId = STAT_ANIM_MINUS1;

        while (stats != 0)
        {
            if (stats & 1)
            {
                if (flags & STAT_CHANGE_CANT_PREVENT)
                {
                    if (gBattleMons[battler].statStages[currStat] > ESTADISTICA_MENOS_6)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
                else if (!gSideTimers[GetBattlerSide(battler)].mistTimer && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_CLEAR_AMULET && ability != ABILITY_CLEAR_BODY && ability != ABILITY_WHITE_SMOKE)
                {
                    if (gBattleMons[battler].statStages[currStat] > ESTADISTICA_MENOS_6)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & STAT_CHANGE_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_MINUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_MINUS1;
        }
    }
    else // goes up
    {
        if (flags & STAT_CHANGE_BY_TWO)
            startingStatAnimId = STAT_ANIM_PLUS2;
        else
            startingStatAnimId = STAT_ANIM_PLUS1;

        while (stats != 0)
        {
            if (stats & 1 && gBattleMons[battler].statStages[currStat] < ESTADISTICA_MAS_6)
            {
                statAnimId = startingStatAnimId + currStat;
                changeableStatsCount++;
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & STAT_CHANGE_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_PLUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_PLUS1;
        }
    }

    if (flags & STAT_CHANGE_MULTIPLE_STATS && changeableStatsCount < 2)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (changeableStatsCount != 0 && !gBattleScripting.statAnimPlayed)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, B_ANIM_STATS_CHANGE, &gDisableStructs[battler], statAnimId);
        MarcaCombatienteOcupado(battler);
        if (flags & STAT_CHANGE_MULTIPLE_STATS && changeableStatsCount > 1)
            gBattleScripting.statAnimPlayed = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 IntentaScriptCombateQuitarObjeto(u32 defensor)
{
    if (gBattleMons[defensor].item != 0 && !NoAliveMonsForEitherParty())
    {
        if ((HabilidadCombatiente(defensor) == ABILITY_STICKY_HOLD || HabilidadCombatiente(defensor) == ABILITY_TERRITORIAL) && IsBattlerAlive(defensor))
        {
            gBattlerAbility = defensor;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
        }
        else
        {
            u32 side = GetBattlerSide(defensor);

            gLastUsedItem = gBattleMons[defensor].item;
            gBattleMons[defensor].item = 0;
            if (gBattleMons[defensor].ability != ABILITY_GORILLA_TACTICS)
                gCombate->choicedMove[defensor] = 0;
            CheckSetUnburden(defensor);

            BtlController_EmitSetMonData(defensor, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[defensor].item), &gBattleMons[defensor].item);
            MarcaCombatienteOcupado(defensor);

            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_KnockedOff;
        }
        return TRUE;
    }
    return FALSE;
}

static u32 GetNextTarget(u32 moveTarget, bool32 excludeCurrent)
{
    u32 battler;
    for (battler = 0; battler < NUMERO_COMBATIENTES; battler++)
    {
        if (battler != gBattlerAttacker && !(excludeCurrent && battler == gBattlerTarget) && IsBattlerAlive(battler) && !(gCombate->targetsDone[gBattlerAttacker] & (1u << battler)) && (GetBattlerSide(battler) != GetBattlerSide(gBattlerAttacker) || moveTarget == MOVE_TARGET_FOES_AND_ALLY))
            break;
    }
    return battler;
}

static void CalculaDanioRetroceso(u32 movimiento)
{
    u32 retroceso = gMovimientos[movimiento].retroceso;

    if (retroceso == 0)
        return;

    u32 danio = gBattleScripting.savedDmg;

    gBattleMoveDamage = max(1, (danio * retroceso) / 100);
}

static void Cmd_moveend(void)
{
    CMD_ARGS(u8 endMode, u8 endState);

    s32 i;
    bool32 effect = FALSE;
    u32 moveType = 0;
    u32 holdEffectAtk = 0;
    u32 endMode, endState;
    u32 originallyUsedMove = gChosenMove;

    endMode = cmd->endMode;
    endState = cmd->endState;

    holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    moveType = TipoMovimiento(gCurrentMove, gBattlerAttacker);

    do
    {
        switch (gBattleScripting.moveendState)
        {
        case MOVEEND_SUM_DAMAGE: // Sum and store damage dealt for multi strike recoil
            gBattleScripting.savedDmg += gHpDealt;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RAGE: // rage check
            if (gBattleMons[gBattlerTarget].status2 & STATUS2_RAGE && IsBattlerAlive(gBattlerTarget) && gBattlerAttacker != gBattlerTarget && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget) && MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(gBattlerTarget) && !EsMovimientoEstado(gCurrentMove) && CompareStat(gBattlerTarget, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RECOIL:
            if (gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
            {
                gBattleScripting.moveendState++;
                break;
            }
            else if (HaceDanioRetroceso(gCurrentMove) && MovimientoEsEfectivo(gCombate->resultadoMovimiento) && IsBattlerAlive(gBattlerAttacker) && gBattleScripting.savedDmg != 0) // Some checks may be redundant alongside this one
            {
                CalculaDanioRetroceso(gCurrentMove);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                effect = TRUE;
            }
            else if (gMovimientos[gCurrentMove].effect == EFFECT_EXPLOSION && !EstaHabilidadEnCampo(ABILITY_DAMP))
            {
                gBattleMoveDamage = 0;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_FaintAttackerForExplosion;
                effect = TRUE;
            }
        case MOVEEND_ITEM_EFFECTS_ATTACKER:
            if (ItemBattleEffects(ITEMEFFECT_MOVE_END, gBattlerAttacker, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SYNCHRONIZE_TARGET: // target synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_SYNCHRONIZE, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ABILITIES: // Such as abilities activating on contact(Poison Spore, Rough Skin, etc.).
            if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ABILITIES_ATTACKER: // Poison Touch, possibly other in the future
            if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_ATTACKER, gBattlerAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_STATUS_IMMUNITY_ABILITIES: // status immunities
            if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, 0, 0, 0, 0))
                effect = TRUE; // it loops through all battlers, so we increment after its done with all battlers
            else
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_SYNCHRONIZE_ATTACKER: // attacker synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_ATK_SYNCHRONIZE, gBattlerAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_CHOICE_MOVE: // update choice band move
        {
            u16 *choicedMoveAtk = &gCombate->choicedMove[gBattlerAttacker];
            if ((HOLD_EFFECT_CHOICE(holdEffectAtk) || HabilidadCombatiente(gBattlerAttacker) == ABILITY_GORILLA_TACTICS) && gChosenMove != MOVE_STRUGGLE && (*choicedMoveAtk == MOVE_NONE))
            {
                if ((gMovimientos[gChosenMove].effect == EFECTO_RELEVO) && !(gMoveResultFlags & MOVE_RESULT_FAILED))
                {
                    gBattleScripting.moveendState++;
                    break;
                }
                *choicedMoveAtk = gChosenMove;
            }
            for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
            {
                if (gBattleMons[gBattlerAttacker].moves[i] == *choicedMoveAtk)
                    break;
            }
            if (i == MAXIMO_MOVIMIENTOS_POKEMON)
            {
                *choicedMoveAtk = MOVE_NONE;
            }
            gBattleScripting.moveendState++;
            break;
        }
        case MOVEEND_CHANGED_ITEMS: // changed held items
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gCombate->changedItems[i] != ITEM_NONE)
                {
                    gBattleMons[i].item = gCombate->changedItems[i];
                    gCombate->changedItems[i] = ITEM_NONE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ITEM_EFFECTS_TARGET:
            if (ItemBattleEffects(ITEMEFFECT_TARGET, gBattlerTarget, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_MOVE_EFFECTS2: // For effects which should happen after target items, for example Desarme after damage from Rocky Helmet.
        {
            switch (gCombate->moveEffect2)
            {
            case EFECTO_MOVIMIENTO_QUITAR_OBJETO:
                if (!DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    effect = IntentaScriptCombateQuitarObjeto(gBattlerTarget);
                }
                break;
            case MOVE_EFFECT_STOCKPILE_WORE_OFF:
                if (gDisableStructs[gBattlerAttacker].stockpileCounter != 0)
                {
                    gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectStockpileWoreOff;
                }
                break;
            case MOVE_EFFECT_SMACK_DOWN:
                if (!EstaCombatienteEnSuelo(gBattlerTarget) && IsBattlerAlive(gBattlerTarget) && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    gStatuses3[gBattlerTarget] |= STATUS3_SMACKED_DOWN;
                    gStatuses3[gBattlerTarget] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectSmackDown;
                }
                break;
            case MOVE_EFFECT_REMOVE_STATUS:
                if ((gBattleMons[gBattlerTarget].status1 & gMovimientos[gCurrentMove].argument) && IsBattlerAlive(gBattlerTarget) && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    gBattleMons[gBattlerTarget].status1 &= ~(gMovimientos[gCurrentMove].argument);

                    BtlController_EmitSetMonData(gBattlerTarget, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerTarget].status1);
                    MarcaCombatienteOcupado(gBattlerTarget);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    switch (gMovimientos[gCurrentMove].argument)
                    {
                    case STATUS1_PARALYSIS:
                        gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
                        break;
                    case STATUS1_SLEEP:
                        gBattlescriptCurrInstr = BattleScript_TargetWokeUp;
                        break;
                    case STATUS1_BURN:
                        gBattlescriptCurrInstr = BattleScript_TargetBurnHeal;
                        break;
                    case STATUS1_CONGELACION:
                        gBattlescriptCurrInstr = ScriptCombate_SeCuroCongelacion;
                        break;
                    case STATUS1_POISON:
                    case STATUS1_TOXIC_POISON:
                    case STATUS1_PSN_ANY:
                        gBattlescriptCurrInstr = BattleScript_TargetPoisonHealed;
                        break;
                    }
                }
                break; // MOVE_EFFECT_REMOVE_STATUS
            }
            gCombate->moveEffect2 = 0;
            gBattleScripting.moveendState++;
            break; // MOVEEND_MOVE_EFFECTS2
        }
        case MOVEEND_ITEM_EFFECTS_ALL: // item effects for all battlers
            if (ItemBattleEffects(ITEMEFFECT_MOVE_END, 0, FALSE))
                effect = TRUE;
            else
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_ATTACKER_INVISIBLE: // make attacker sprite invisible
            if (gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE) && gHitMarker & (HITMARKER_DISABLE_ANIMATION))
            {
                BtlController_EmitSpriteInvisibility(gBattlerAttacker, BUFFER_A, TRUE);
                MarcaCombatienteOcupado(gBattlerAttacker);
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ATTACKER_VISIBLE: // make attacker sprite visible
            if (!(EsMovimientoEfectivo(gCombate->resultadoMovimiento)) || !(gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE)) || WasUnableToUseMove(gBattlerAttacker))
            {
                BtlController_EmitSpriteInvisibility(gBattlerAttacker, BUFFER_A, FALSE);
                MarcaCombatienteOcupado(gBattlerAttacker);
                gStatuses3[gBattlerAttacker] &= ~STATUS3_SEMI_INVULNERABLE;
                gSpecialStatuses[gBattlerAttacker].restoredBattlerSprite = TRUE;
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_TARGET_VISIBLE: // make target sprite visible
            if (!gSpecialStatuses[gBattlerTarget].restoredBattlerSprite && gBattlerTarget < gBattlersCount && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE))
            {
                BtlController_EmitSpriteInvisibility(gBattlerTarget, BUFFER_A, FALSE);
                MarcaCombatienteOcupado(gBattlerTarget);
                gStatuses3[gBattlerTarget] &= ~STATUS3_SEMI_INVULNERABLE;
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_NUM_HITS:
            if (gBattlerAttacker != gBattlerTarget 
             && gMovimientos[gCurrentMove].category != CATEGORIA_ESTADO 
             && MovimientoEsEfectivo(gCombate->resultadoMovimiento)
             && HaSidoDaniado(gBattlerTarget))
            {
                u32 potencia = gMovimientos[gCurrentMove].power;
                struct DamageCalculationData damageCalcData = {0};
                damageCalcData.battlerAtk = gBattlerAttacker;
                damageCalcData.battlerDef = gBattlerTarget;
                damageCalcData.movimiento = gCurrentMove;

                uq4_12_t modificador = ObtenModificadorDanioObjetivoMultiple(&damageCalcData);

                potencia = UQ412MultiplicaPorEntero(modificador, potencia);
                gCombate->potenciaMovimientosRecibidosTurno[gBattlerTarget] += potencia;

                gCombate->timesGotHit[GetBattlerSide(gBattlerTarget)][gBattlerPartyIndexes[gBattlerTarget]]++;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SUBSTITUTE: // update substitute
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gDisableStructs[i].substituteHP == 0)
                    gBattleMons[i].status2 &= ~STATUS2_SUBSTITUTE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_UPDATE_LAST_MOVES:
            if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
            {
                u8 temp;
                SWAP(gBattlerAttacker, gBattlerTarget, temp);
                gHitMarker &= ~HITMARKER_SWAP_ATTACKER_TARGET;
            }
            gDisableStructs[gBattlerAttacker].usedMoves |= 1u << gCurrMovePos;
            if (gHitMarker & HITMARKER_ATTACKSTRING_PRINTED)
            {
                gLastPrintedMoves[gBattlerAttacker] = gChosenMove;
                gLastUsedMove = gCurrentMove;
            }
            if (!(gAbsentBattlerFlags & (1u << gBattlerAttacker)) && !(gCombate->absentBattlerFlags & (1u << gBattlerAttacker)) && gMovimientos[originallyUsedMove].effect != EFECTO_RELEVO)
            {
                gLastMoves[gBattlerAttacker] = gChosenMove;
                RecordKnownMove(gBattlerAttacker, gChosenMove);
                gLastResultingMoves[gBattlerAttacker] = gCurrentMove;

                if (!(gHitMarker & HITMARKER_FAINTED(gBattlerTarget)))
                    gLastHitBy[gBattlerTarget] = gBattlerAttacker;

                if (MovimientoEsEfectivo(gCombate->resultadoMovimiento))
                {
                    if (gChosenMove == MOVE_NONE)
                    {
                        gLastLandedMoves[gBattlerTarget] = gChosenMove;
                    }
                    else
                    {
                        gLastLandedMoves[gBattlerTarget] = gCurrentMove;
                    }
                }
                else
                {
                    gLastLandedMoves[gBattlerTarget] = MOVE_NONE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_NEXT_TARGET: // For moves hitting two opposing Pokemon.
        {
            u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
            gCombate->targetsDone[gBattlerAttacker] |= 1u << gBattlerTarget;
            if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE) && EsCombateContraEntrenador(gCombate->tipoCombate) && !gProtectStructs[gBattlerAttacker].chargingTurn && (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY) && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
            {
                u32 nextTarget = GetNextTarget(moveTarget, FALSE);
                gHitMarker |= HITMARKER_NO_PPDEDUCT;

                if (nextTarget != NUMERO_COMBATIENTES)
                {
                    gCombate->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget; // Fix for moxie spread moves
                    gBattleScripting.moveendState = 0;
                    MoveValuesCleanUp();
                    gBattleScripting.moveEffect = gBattleScripting.savedMoveEffect;

                    if (gMovimientos[gCurrentMove].effect == EFFECT_EXPLOSION)
                        BattleScriptPush(gBattleMoveEffects[EFFECT_HIT].battleScript); // Edge case for Explosion not changing targets
                    else
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                    return;
                }
                // Check if the move used was actually a bounced move. If so, we need to go back to the original attacker and make sure, its move hits all 2 or 3 pokemon.
                else if (gCombate->movimientoEspejoMagicoRebota)
                {
                    u8 originalBounceTarget = gBattlerAttacker;
                    gCombate->movimientoEspejoMagicoRebota = FALSE;
                    gBattlerAttacker = gCombate->attackerBeforeBounce;
                    gCombate->targetsDone[gBattlerAttacker] |= 1u << originalBounceTarget;
                    gCombate->targetsDone[originalBounceTarget] = 0;

                    nextTarget = GetNextTarget(moveTarget, FALSE);
                    if (nextTarget != NUMERO_COMBATIENTES)
                    {
                        // We found another target for the original move user.
                        gCombate->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget;
                        gBattleScripting.moveendState = 0;
                        gBattleScripting.animTurn = 0;
                        gBattleScripting.animTargetsHit = 0;
                        MoveValuesCleanUp();
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                        return;
                    }
                }

                gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                gHitMarker &= ~HITMARKER_NO_PPDEDUCT;
            }
            RecordLastUsedMoveBy(gBattlerAttacker, gCurrentMove);
            gBattleScripting.moveendState++;
            break;
        }
        case MOVEEND_MULTIHIT_MOVE:
        {
            if (MovimientoEsEfectivo(gCombate->resultadoMovimiento) && !(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE) && gCombate->contadorMultigolpes && !(gMovimientos[gCurrentMove].effect == EFFECT_PRESENT && gCombate->presentBasePower == 0)) // Silly edge case
            {
                gCombate->contadorMultigolpes--;
                if (!IsBattlerAlive(gBattlerTarget) && gMovimientos[gCurrentMove].effect != EFFECT_DRAGON_DARTS)
                    gCombate->contadorMultigolpes = 0;

                gBattleScripting.multihitString[4]++;
                if (gCombate->contadorMultigolpes == 0)
                {
                    BattleScriptPushCursor();
                    if (gMovimientos[gCurrentMove].argument == MOVE_EFFECT_SCALE_SHOT && !NoAliveMonsForEitherParty())
                        gBattlescriptCurrInstr = BattleScript_ScaleShot;
                    else
                        gBattlescriptCurrInstr = BattleScript_MultiHitPrintStrings;
                    effect = TRUE;
                }
                else
                {
                    if (gMovimientos[gCurrentMove].effect == EFFECT_DRAGON_DARTS && gCombate->moveTarget[gBattlerAttacker] == gBattlerTarget // Haven't already changed targets
                        && CanTargetPartner(gBattlerAttacker, gBattlerTarget) && !TargetFullyImmuneToCurrMove(gBattlerAttacker, ALIADO(gBattlerTarget)))
                        gBattlerTarget = ALIADO(gBattlerTarget); // Target the partner in doubles for second hit.

                    if (gBattleMons[gBattlerAttacker].hp && gBattleMons[gBattlerTarget].hp
                        && (gChosenMove == MOVE_SNORE || !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
                        && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_CONGELACION))
                    {
                        if (gSpecialStatuses[gBattlerAttacker].parentalBondState)
                            gSpecialStatuses[gBattlerAttacker].parentalBondState--;

                        gHitMarker |= (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING);
                        gBattleScripting.animTargetsHit = 0;
                        gBattleScripting.moveendState = 0;
                        gSpecialStatuses[gBattlerAttacker].multiHitOn = TRUE;
                        MoveValuesCleanUp();
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                        return;
                    }
                    else
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_MultiHitPrintStrings;
                        effect = TRUE;
                    }
                }
            }
            gCombate->contadorMultigolpes = 0;
            gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_OFF;
            gSpecialStatuses[gBattlerAttacker].multiHitOn = 0;
            gBattleScripting.moveendState++;
            break;
        }
        case MOVEEND_EJECT_ITEMS:
        {
            // Because sorting the battlers by speed takes lots of cycles, it's better to just check if any of the battlers has the Eject items.
            u32 ejectPackBattlers = 0, ejectButtonBattlers = 0, i;
            for (i = 0; i < gBattlersCount; i++)
            {
                u32 holdEffect;
                holdEffect = GetBattlerHoldEffect(i, TRUE);
                if (holdEffect == HOLD_EFFECT_EJECT_BUTTON)
                    ejectButtonBattlers |= 1u << i;
                else if (holdEffect == HOLD_EFFECT_EJECT_PACK)
                    ejectPackBattlers |= 1u << i;
            }
            if (ejectButtonBattlers || ejectPackBattlers)
            {
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE);

                for (i = 0; i < gBattlersCount; i++)
                {
                    u32 battler = battlers[i];

                    if (battler != gBattlerAttacker && ejectButtonBattlers & (1u << battler))
                    {
                        if (EstaPotenciadoPotenciaBruta(gBattlerAttacker, gCurrentMove)) // Apparently Sheer Force blocks Eject Button, but not Eject Pack
                            continue;
                        // Since we check if battler was damaged, we don't need to check move result.
                        // In fact, doing so actually prevents multi-target moves from activating eject button properly
                        if (!HaSidoDaniado(battler))
                            continue;
                    }
                    else if (ejectPackBattlers & (1u << battler))
                    {
                        if (!gProtectStructs[battler].statFell || gProtectStructs[battler].disableEjectPack)
                            continue;
                    }
                    else
                    {
                        continue;
                    }

                    if (IsBattlerAlive(battler) && CountUsablePartyMons(battler) > 0 // Has mon to switch into
                                                                                     // Does not activate if attacker used Parting Shot and can switch out
                        && !(gMovimientos[gCurrentMove].effect == EFFECT_HIT_SWITCH_TARGET && CanBattlerSwitch(gBattlerAttacker)))
                    {
                        gBattleScripting.battler = battler;
                        gLastUsedItem = gBattleMons[battler].item;
                        if (gMovimientos[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                            gBattlescriptCurrInstr = BattleScript_MoveEnd; // Prevent user switch-in selection
                        effect = TRUE;
                        BattleScriptPushCursor();
                        gCombate->usedEjectItem |= 1u << battler;
                        if (ejectButtonBattlers & (1u << battler))
                        {
                            gBattlescriptCurrInstr = BattleScript_EjectButtonActivates;
                            AI_DATA->ejectButtonSwitch = TRUE;
                        }
                        else // Eject Pack
                        {
                            gBattlescriptCurrInstr = BattleScript_EjectPackActivates;
                            AI_DATA->ejectPackSwitch = TRUE;
                            // Are these 2 lines below needed?
                            gProtectStructs[battler].statFell = FALSE;
                            gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = TRUE;
                        }
                        break; // Only the fastest Eject item activates
                    }
                }
            }
        }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_WHITE_HERB:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (IsBattlerAlive(i) && ItemBattleEffects(ITEMEFFECT_STATS_CHANGED, i, FALSE))
                {
                    effect = TRUE;
                    break;
                }
            }
            if (!effect)
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_RED_CARD:
        {
            u32 redCardBattlers = 0, i;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i == gBattlerAttacker)
                    continue;
                if (GetBattlerHoldEffect(i, TRUE) == HOLD_EFFECT_RED_CARD)
                    redCardBattlers |= (1u << i);
            }
            if (redCardBattlers && (gMovimientos[gCurrentMove].effect != EFFECT_HIT_SWITCH_TARGET || gCombate->hitSwitchTargetFailed) && IsBattlerAlive(gBattlerAttacker) && !EstaPotenciadoPotenciaBruta(gBattlerAttacker, gCurrentMove) && HabilidadCombatiente(gBattlerAttacker) != ABILITY_GUARD_DOG)
            {
                // Since we check if battler was damaged, we don't need to check move result.
                // In fact, doing so actually prevents multi-target moves from activating red card properly
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE);
                for (i = 0; i < gBattlersCount; i++)
                {
                    u32 battler = battlers[i];
                    // Search for fastest hit pokemon with a red card
                    // Attacker is the one to be switched out, battler is one with red card
                    if (redCardBattlers & (1u << battler) && IsBattlerAlive(battler) && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && HaSidoDaniado(battler) && CanBattlerSwitch(gBattlerAttacker))
                    {
                        gLastUsedItem = gBattleMons[battler].item;
                        SaveBattlerTarget(battler); // save battler with red card
                        gBattleScripting.battler = battler;
                        gEffectBattler = gBattlerAttacker;
                        if (gMovimientos[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                            gBattlescriptCurrInstr = BattleScript_MoveEnd; // Prevent user switch-in selection
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_RedCardActivates;
                        gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = TRUE;
                        effect = TRUE;
                        break; // Only fastest red card activates
                    }
                }
            }
        }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_LIFEORB:
            if (ItemBattleEffects(ITEMEFFECT_LIFEORB, 0, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_PICKPOCKET:
            if (IsBattlerAlive(gBattlerAttacker) && gBattleMons[gBattlerAttacker].item != ITEM_NONE // Attacker must be holding an item
                && !(EstaPotenciadoPotenciaBruta(gBattlerAttacker, gCurrentMove))                      // Pickpocket doesn't activate for sheer force
                && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)                              // Pickpocket requires contact
                && MovimientoEsEfectivo(gCombate->resultadoMovimiento))                             // Obviously attack needs to have worked
            {
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE); // Pickpocket activates for fastest mon without item
                for (i = 0; i < gBattlersCount; i++)
                {
                    u8 battler = battlers[i];
                    // Attacker is mon who made contact, battler is mon with pickpocket
                    if (battler != gBattlerAttacker                                          // Cannot pickpocket yourself
                        && HabilidadCombatiente(battler) == ABILITY_PICKPOCKET               // Target must have pickpocket ability
                        && HaSidoDaniado(battler)                                            // Target needs to have been damaged
                        && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) // Subsitute unaffected
                        && IsBattlerAlive(battler)                                           // Battler must be alive to pickpocket
                        && gBattleMons[battler].item == ITEM_NONE)                           // Pickpocketer can't have an item already
                    {
                        gBattlerTarget = gBattlerAbility = battler;
                        // Battle scripting is super brittle so we shall do the item exchange now (if possible)
                        if (HabilidadCombatiente(gBattlerAttacker) != ABILITY_STICKY_HOLD || HabilidadCombatiente(gBattlerAttacker) != ABILITY_TERRITORIAL)
                            StealTargetItem(gBattlerTarget, gBattlerAttacker); // Target takes attacker's item

                        gEffectBattler = gBattlerAttacker;
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_Pickpocket; // Includes sticky hold check to print separate string
                        effect = TRUE;
                        break; // Pickpocket activates on fastest mon, so exit loop.
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SAME_MOVE_TURNS:
            if (gCurrentMove != gLastResultingMoves[gBattlerAttacker] || !(MovimientoEsEfectivo(gCombate->resultadoMovimiento)))
                gCombate->sameMoveTurns[gBattlerAttacker] = 0;
            else if (gCurrentMove == gLastResultingMoves[gBattlerAttacker] && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_1ST_HIT)
                gCombate->sameMoveTurns[gBattlerAttacker]++;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_CLEAR_BITS:                                                                                   // Clear/Set bits for things like using a move for all targets and all hits.
            if (B_RAMPAGE_CANCELLING >= GEN_5 && MoveHasAdditionalEffectSelf(gCurrentMove, MOVE_EFFECT_THRASH)     // If we're rampaging
                && !(EsMovimientoEfectivo(gCombate->resultadoMovimiento))                                          // And it is unusable
                && (gBattleMons[gBattlerAttacker].status2 & STATUS2_LOCK_CONFUSE) != STATUS2_LOCK_CONFUSE_TURN(1)) // And won't end this turn
                CancelMultiTurnMoves(gBattlerAttacker);                                                            // Cancel it

            gCombate->targetsDone[gBattlerAttacker] = 0;
            gSpecialStatuses[gBattlerAttacker].potenciadoGema = FALSE;
            gSpecialStatuses[gBattlerAttacker].damagedMons = 0;
            gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = 0;
            gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
            gBattleScripting.moveEffect = 0;
            gCombate->hitSwitchTargetFailed = FALSE;
            gCombate->isAtkCancelerForCalledMove = FALSE;
            gCombate->movimientoEspejoMagicoRebota = FALSE;
            gCombate->additionalEffectsCounter = 0;
            if (B_CHARGE <= GEN_8 || moveType == TIPO_ELECTRICO)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_CHARGED_UP);
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_COUNT:
            break;
        }

        if (endMode == 1 && effect == FALSE)
            gBattleScripting.moveendState = MOVEEND_COUNT;
        if (endMode == 2 && endState == gBattleScripting.moveendState)
            gBattleScripting.moveendState = MOVEEND_COUNT;

    } while (gBattleScripting.moveendState != MOVEEND_COUNT && effect == FALSE);

    if (gBattleScripting.moveendState == MOVEEND_COUNT && effect == FALSE)
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_returnatktoball(void)
{
    CMD_ARGS();

    if (!(gHitMarker & HITMARKER_FAINTED(gBattlerAttacker)))
    {
        BtlController_EmitReturnMonToBall(gBattlerAttacker, BUFFER_A, FALSE);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_getswitchedmondata(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (HayAlgunCombatienteOcupado())
        return;

    gBattlerPartyIndexes[battler] = gCombate->monToSwitchIntoId[battler];

    BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, 1u << gBattlerPartyIndexes[battler]);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchindataupdate(void)
{
    CMD_ARGS(u8 battler);

    struct BattlePokemon oldData;
    u32 battler, i;
    u8 *monData;

    if (HayAlgunCombatienteOcupado())
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    oldData = gBattleMons[battler];
    monData = (u8 *)(&gBattleMons[battler]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
        monData[i] = gBattleResources->bufferB[battler][4 + i];

    // Edge case: the sent out pokemon has 0 HP. This should never happen.
    if (!IsBattlerAlive(battler))
    {
        struct Pokemon *party = GetBattlerParty(battler);
        // Find the first possible replacement for the not valid pokemon.
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (IsValidForBattle(&party[i]))
                break;
        }
        // There is valid replacement.
        if (i != PARTY_SIZE)
        {
            gBattlerPartyIndexes[battler] = gCombate->monToSwitchIntoId[battler] = i;
            BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, 1u << gBattlerPartyIndexes[battler]);
            MarcaCombatienteOcupado(battler);
            return;
        }
    }

    gBattleMons[battler].types[TIPO_1] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_1];
    gBattleMons[battler].types[TIPO_2] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_2];
    gBattleMons[battler].ability = GetAbilityBySpecies(gBattleMons[battler].species, gBattleMons[battler].abilityNum);

    if (gMovimientos[gCurrentMove].effect == EFECTO_RELEVO)
    {
        for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
        {
            gBattleMons[battler].statStages[i] = oldData.statStages[i];
        }
        gBattleMons[battler].status2 = oldData.status2;
    }

    SwitchInClearSetData(battler);

    gBattleScripting.battler = battler;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchinanim(void)
{
    u32 battler;

    CMD_ARGS(u8 battler, bool8 dontClearSubstitute);

    if (HayAlgunCombatienteOcupado())
        return;

    battler = GetBattlerForBattleScript(cmd->battler);

    if (GetBattlerSide(battler) == LADO_OPONENTE)
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[battler].species), FLAG_SET_SEEN);

    gAbsentBattlerFlags &= ~(1u << battler);

    BtlController_EmitSwitchInAnim(battler, BUFFER_A, gBattlerPartyIndexes[battler], cmd->dontClearSubstitute);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

bool32 CanBattlerSwitch(u32 battler)
{
    s32 i, battlerIn1, battlerIn2;
    bool32 ret = FALSE;
    struct Pokemon *party;

    if (GetBattlerSide(battler) == LADO_OPONENTE)
    {
        battlerIn1 = OPONENTE_IZQUIERDA;

        if (EsCombateContraEntrenador(gCombate->tipoCombate))
            battlerIn2 = OPONENTE_DERECHA;
        else
            battlerIn2 = battlerIn1;

        party = gEnemyParty;
    }
    else
    {
        // Check if attacker side has mon to switch into
        battlerIn1 = JUGADOR_IZQUIERDA;

        if (EsCombateContraEntrenador(gCombate->tipoCombate))
            battlerIn2 = JUGADOR_DERECHA;
        else
            battlerIn2 = battlerIn1;

        party = gPlayerParty;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) != 0 && GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&party[i], MON_DATA_IS_EGG) && i != gBattlerPartyIndexes[battlerIn1] && i != gBattlerPartyIndexes[battlerIn2])
            break;
    }

    ret = (i != PARTY_SIZE);
    return ret;
}

static void Cmd_jumpifcantswitch(void)
{
    CMD_ARGS(u8 battler : 7, u8 ignoreEscapePrevention : 1, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (!cmd->ignoreEscapePrevention && !PuedeCambiar(battler))
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        if (CanBattlerSwitch(battler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

// Opens the party screen to choose a new Pokémon to send out.
// slotId is the Pokémon to replace.
// Note that this is not used by the Switch action, only replacing fainted Pokémon or Baton Pass
static void ChooseMonToSendOut(u32 battler, u8 slotId)
{
    gCombate->battlerPartyIndexes[battler] = gBattlerPartyIndexes[battler];
    gCombate->monToSwitchIntoId[battler] = PARTY_SIZE;

    BtlController_EmitChoosePokemon(battler, BUFFER_A, PARTY_ACTION_SEND_OUT, slotId, ABILITY_NONE, gCombate->battlerPartyOrders[battler]);
    MarcaCombatienteOcupado(battler);
}

static void Cmd_openpartyscreen(void)
{
    CMD_ARGS(u8 battler : 7, u8 partyScreenOptional : 1, const u8 *failInstr);

    u32 flags = 0;
    u8 hitmarkerFaintBits = 0;
    u32 i, battler = 0;
    const u8 *failInstr = cmd->failInstr;

    if (cmd->battler == BS_FAINTED_MULTIPLE_1)
    {
        if (!EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gHitMarker & HITMARKER_FAINTED(battler))
                {
                    if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= 1u << battler;
                        gHitMarker &= ~HITMARKER_FAINTED(battler);
                        MarcaCombatienteOcupado(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, PARTY_SIZE);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                }
                else
                {
                    MarcaCombatienteOcupado(battler);
                }
            }
        }
        else if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            bool32 hasReplacement;

            hitmarkerFaintBits = gHitMarker >> 28;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (((1u << i) & hitmarkerFaintBits))
                {
                    if (i > 1 && ((1u << ALIADO(i)) & hitmarkerFaintBits))
                        continue;

                    battler = i;
                    if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= 1u << battler;
                        gHitMarker &= ~HITMARKER_FAINTED(battler);
                        BtlController_EmitCantSwitch(battler, BUFFER_A);
                        MarcaCombatienteOcupado(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, gCombate->monToSwitchIntoId[ALIADO(battler)]);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                    else if (battler < 2 || (battler > 1 && !(flags & ALIADO(battler))))
                    {
                        MarcaCombatienteOcupado(battler);
                        flags |= battler;
                    }
                }
            }

            for (i = 0; i < NUM_BATTLE_SIDES; i++)
            {
                if (!(gSpecialStatuses[i].faintedHasReplacement))
                {
                    hasReplacement = gSpecialStatuses[ALIADO(i)].faintedHasReplacement;
                    if (!hasReplacement && hitmarkerFaintBits != 0)
                    {
                        if (gAbsentBattlerFlags & (1 << i))
                            battler = ALIADO(i);
                        else
                            battler = i;

                        MarcaCombatienteOcupado(battler);
                    }
                }
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (cmd->battler == BS_FAINTED_MULTIPLE_2)
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            hitmarkerFaintBits = gHitMarker >> 28;
            for (i = 0; i < NUM_BATTLE_SIDES; i++)
            {
                if ((1 << ALIADO(i)) & hitmarkerFaintBits && (1 << i) & hitmarkerFaintBits)
                {
                    battler = ALIADO(i);
                    if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= (1u << battler);
                        gHitMarker &= ~(HITMARKER_FAINTED(battler));
                        BtlController_EmitCantSwitch(battler, BUFFER_A);
                        MarcaCombatienteOcupado(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, gCombate->monToSwitchIntoId[i]);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                }
            }
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            // Not multi or double battle
            gBattlescriptCurrInstr = cmd->nextInstr;
        }

        hitmarkerFaintBits = gHitMarker >> 28;

        gBattlerFainted = 0;
        while (!((1u << gBattlerFainted) & hitmarkerFaintBits) && gBattlerFainted < gBattlersCount)
            gBattlerFainted++;

        if (gBattlerFainted == gBattlersCount)
            gBattlescriptCurrInstr = failInstr;
    }
    else
    {
        if (cmd->partyScreenOptional)
            hitmarkerFaintBits = PARTY_ACTION_CHOOSE_MON; // Used here as the caseId for the EmitChoose function.
        else
            hitmarkerFaintBits = PARTY_ACTION_SEND_OUT;

        battler = GetBattlerForBattleScript(cmd->battler);
        if (gSpecialStatuses[battler].faintedHasReplacement)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
        {
            gAbsentBattlerFlags |= 1u << battler;
            gHitMarker &= ~HITMARKER_FAINTED(battler);
            gBattlescriptCurrInstr = failInstr;
        }
        else
        {
            *(gCombate->battlerPartyIndexes + battler) = gBattlerPartyIndexes[battler];
            *(gCombate->monToSwitchIntoId + battler) = PARTY_SIZE;

            BtlController_EmitChoosePokemon(battler, BUFFER_A, hitmarkerFaintBits, *(gCombate->monToSwitchIntoId + ALIADO(battler)), ABILITY_NONE, gCombate->battlerPartyOrders[battler]);
            MarcaCombatienteOcupado(battler);

            gBattlescriptCurrInstr = cmd->nextInstr;

            u32 battlerOpposite = OPONENTE(battler);
            if (gAbsentBattlerFlags & (1u << battlerOpposite))
                battlerOpposite ^= BIT_FLANK;

            // Make sure we're checking a valid battler. In edge case scenarios - battler could be absent and battlerOpposite would become a non-existent one softlocking the game.
            if (battlerOpposite < gBattlersCount)
            {
                MarcaCombatienteOcupado(battlerOpposite);
            }
        }
    }
}

static void Cmd_switchhandleorder(void)
{
    CMD_ARGS(u8 battler, u8 state);

    u32 combatiente;
    if (HayAlgunCombatienteOcupado())
        return;

    combatiente = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->state)
    {
    case 0:
        for (u32 indiceCombatiente = 0; indiceCombatiente < gBattlersCount; indiceCombatiente++)
        {
            if (gBattleResources->bufferB[indiceCombatiente][0] == CONTROLLER_CHOSENMONRETURNVALUE)
            {
                *(gCombate->monToSwitchIntoId + indiceCombatiente) = gBattleResources->bufferB[indiceCombatiente][1];
            }
        }
        break;
    case 1:
        SwitchPartyOrder(combatiente);
        break;
    case 2:
        gBattleCommunication[MULTIUSE_STATE] = gBattleResources->bufferB[combatiente][1];
        *(gCombate->monToSwitchIntoId + combatiente) = gBattleResources->bufferB[combatiente][1];
        SwitchPartyOrder(combatiente);

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species)
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, battler, gBattleResources->bufferB[combatiente][1])
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void SetDmgHazardsBattlescript(u8 battler, u8 multistringId)
{
    gBattleMons[battler].status2 &= ~STATUS2_DESTINY_BOND;
    gHitMarker &= ~HITMARKER_DESTINYBOND;
    gBattleScripting.battler = battler;
    gBattleCommunication[MULTISTRING_CHOOSER] = multistringId;

    BattleScriptPushCursor();
    if (gBattlescriptCurrInstr[1] == BS_TARGET)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnTarget;
    else if (gBattlescriptCurrInstr[1] == BS_ATTACKER)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnAttacker;
    else if (gBattlescriptCurrInstr[1] == BS_SCRIPTING)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnBattlerScripting;
    else
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnFaintedBattler;
}

bool32 DoSwitchInAbilities(u32 battler)
{
    return (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battler, 0, 0, 0) ||
           (gBattleWeather & B_WEATHER_ANY && ClimaTieneEfecto() && AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battler, 0, 0, 0)));
}

static void UpdateSentMonFlags(u32 battler)
{
    UpdateSentPokesToOpponentValue(battler);

    gHitMarker &= ~HITMARKER_FAINTED(battler);
    gSpecialStatuses[battler].faintedHasReplacement = FALSE;
}

static bool32 DoSwitchInEffectsForBattler(u32 battler)
{
    u32 i = 0;
    // Neutralizing Gas announces itself before hazards
    if (gBattleMons[battler].ability == ABILITY_NEUTRALIZING_GAS && gSpecialStatuses[battler].announceNeutralizingGas == 0)
    {
        gMensajeBatalla = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
        gSpecialStatuses[battler].announceNeutralizingGas = TRUE;
        gBattlerAbility = battler;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SwitchInAbilityMsgRet;
    }
    else if (!(gDisableStructs[battler].spikesDone) && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SPIKES) && HabilidadCombatiente(battler) != ABILITY_MAGIC_GUARD && IsBattlerAffectedByHazards(battler, FALSE) && EstaCombatienteEnSuelo(battler))
    {
        u8 spikesDmg = (5 - gSideTimers[GetBattlerSide(battler)].spikesAmount) * 2;
        gBattleMoveDamage = CuantosPSMaximos(battler) / (spikesDmg);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gDisableStructs[battler].spikesDone = TRUE;
        SetDmgHazardsBattlescript(battler, B_MSG_PKMNHURTBYSPIKES);
    }
    else if (!(gDisableStructs[battler].stealthRockDone) && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_STEALTH_ROCK) && IsBattlerAffectedByHazards(battler, FALSE) && HabilidadCombatiente(battler) != ABILITY_MAGIC_GUARD)
    {
        gDisableStructs[battler].stealthRockDone = TRUE;
        gBattleMoveDamage = DanioTrampa(gMovimientos[MOVE_STEALTH_ROCK].type, battler);

        if (gBattleMoveDamage != 0)
            SetDmgHazardsBattlescript(battler, B_MSG_STEALTHROCKDMG);
    }
    else if (!(gDisableStructs[battler].toxicSpikesDone) && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TOXIC_SPIKES) && EstaCombatienteEnSuelo(battler))
    {
        gDisableStructs[battler].toxicSpikesDone = TRUE;
        if (EsTipo(battler, TIPO_VENENO)) // Absorb the toxic spikes.
        {
            gSideStatuses[GetBattlerSide(battler)] &= ~SIDE_STATUS_TOXIC_SPIKES;
            gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount = 0;
            gBattleScripting.battler = battler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ToxicSpikesAbsorbed;
        }
        else if (IsBattlerAffectedByHazards(battler, TRUE))
        {
            i = HabilidadCombatiente(battler);
            if (!(gBattleMons[battler].status1 & STATUS1_ANY) && i != ABILITY_IMMUNITY && !(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD))
            {
                if (gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount >= 2)
                    gBattleMons[battler].status1 |= STATUS1_TOXIC_POISON;
                else
                    gBattleMons[battler].status1 |= STATUS1_POISON;

                BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
                MarcaCombatienteOcupado(battler);
                gBattleScripting.battler = battler;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesPoisoned;
            }
        }
    }
    else if (!(gDisableStructs[battler].stickyWebDone) && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_STICKY_WEB) && IsBattlerAffectedByHazards(battler, FALSE) && EstaCombatienteEnSuelo(battler))
    {
        gDisableStructs[battler].stickyWebDone = TRUE;
        gBattleScripting.battler = battler;
        SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, TRUE);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebOnSwitchIn;
    }
    else
    {
        if (DoSwitchInAbilities(battler) || ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, battler, FALSE))
            return TRUE;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (i == battler)
                continue;

            switch (HabilidadCombatiente(i))
            {
            case ABILITY_TRACE:
                if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, i, 0, 0, 0))
                    return TRUE;
                break;
            case ABILITY_FORECAST:
                if (AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, i, 0, 0, 0))
                    return TRUE;
                break;
            }
        }

        gDisableStructs[battler].stickyWebDone = FALSE;
        gDisableStructs[battler].spikesDone = FALSE;
        gDisableStructs[battler].toxicSpikesDone = FALSE;
        gDisableStructs[battler].stealthRockDone = FALSE;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == battler)
                gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;

            gCombate->hpOnSwitchout[GetBattlerSide(i)] = gBattleMons[i].hp;
        }

        gCombate->forcedSwitch &= ~(1u << battler);
        return FALSE;
    }

    return TRUE; // Effect's script plays.
}

static void Cmd_switchineffects(void)
{
    CMD_ARGS(u8 battler);
    u32 i, battler = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->battler)
    {
    // Multiple mons fainted and are being switched-in. Their abilities/hazards will play according to speed ties.
    case BS_FAINTED_MULTIPLE_1: // Saves the battlers.
        gCombate->multipleSwitchInBattlers |= 1 << battler;
        UpdateSentMonFlags(battler);

        // Increment fainted battler.
        do
        {
            gBattlerFainted++;
            if (gBattlerFainted >= gBattlersCount)
                break;
            if (gHitMarker & HITMARKER_FAINTED(gBattlerFainted) && !(gAbsentBattlerFlags & (1u << gBattlerFainted)))
                break;
        } while (1);

        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    case BS_FAINTED_MULTIPLE_2: // Plays hazards/abilities.
        switch (gCombate->multipleSwitchInState)
        {
        case 0: // Sort battlers by speed
            for (i = 0; i < gBattlersCount; i++)
                gCombate->multipleSwitchInSortedBattlers[i] = i;
            SortBattlersBySpeed(gCombate->multipleSwitchInSortedBattlers, FALSE);
            gCombate->multipleSwitchInState++;
            gCombate->multipleSwitchInCursor = 0;
            // Loop through all available battlers
        case 1:
            for (; gCombate->multipleSwitchInCursor < gBattlersCount; gCombate->multipleSwitchInCursor++)
            {
                gBattlerFainted = gCombate->multipleSwitchInSortedBattlers[gCombate->multipleSwitchInCursor];
                if (gCombate->multipleSwitchInBattlers & (1 << (gBattlerFainted)))
                {
                    if (DoSwitchInEffectsForBattler(gBattlerFainted))
                        return;
                }
            }
            // All battlers done, end
            gCombate->multipleSwitchInBattlers = 0;
            gCombate->multipleSwitchInState = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    default:
        UpdateSentMonFlags(battler);
        if (!DoSwitchInEffectsForBattler(battler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    }
}

static void Cmd_trainerslidein(void)
{
    CMD_ARGS(u8 position);

    u32 battler = GetBattlerForBattleScript(cmd->position);
    BtlController_EmitTrainerSlide(battler, BUFFER_A);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playse(void)
{
    CMD_ARGS(u16 song);

    BtlController_EmitPlaySE(gBattlerAttacker, BUFFER_A, cmd->song);
    MarcaCombatienteOcupado(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_fanfare(void)
{
    CMD_ARGS(u16 song);

    BtlController_EmitPlayFanfareOrBGM(gBattlerAttacker, BUFFER_A, cmd->song, FALSE);
    MarcaCombatienteOcupado(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playfaintcry(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitFaintingCry(battler, BUFFER_A);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_returntoball(void)
{
    CMD_ARGS(u8 battler, bool8 changingForm);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitReturnMonToBall(battler, BUFFER_A, TRUE);
    MarcaCombatienteOcupado(battler);

    // Don't always execute a form change here otherwise we can stomp gigantamax
    if (!cmd->changingForm)
        TryBattleFormChange(battler, FORM_CHANGE_BATTLE_SWITCH);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlelearnnewmove(void)
{
    CMD_ARGS(const u8 *learnedMovePtr, const u8 *nothingToLearnPtr, bool8 isFirstMove);

    u32 monId = gCombate->expGetterMonId;
    u16 learnMove = MonTryLearningNewMove(&gPlayerParty[monId], cmd->isFirstMove);
    while (learnMove == MON_ALREADY_KNOWS_MOVE)
        learnMove = MonTryLearningNewMove(&gPlayerParty[monId], FALSE);

    if (learnMove == MOVE_NONE)
    {
        gBattlescriptCurrInstr = cmd->nothingToLearnPtr;
    }
    else if (learnMove == MON_HAS_MAX_MOVES)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        u32 battler = JUGADOR_IZQUIERDA;

        if (gBattlerPartyIndexes[battler] == monId)
        {
            GiveMoveToBattleMon(&gBattleMons[battler], learnMove);
        }
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            battler = JUGADOR_DERECHA;
            if (gBattlerPartyIndexes[battler] == monId)
            {
                GiveMoveToBattleMon(&gBattleMons[battler], learnMove);
            }
        }

        gBattlescriptCurrInstr = cmd->learnedMovePtr;
    }
}

static void Cmd_yesnoboxlearnmove(void) // revisar, aquí no hace falta un global seguramente
{
    CMD_ARGS(const u8 *forgotMovePtr);

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleScripting.learnMoveState++;
        gPosicionCursorSiNo = CURSOR_SI;
        CreaCursorBatallaSiNo();
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gPosicionCursorSiNo == CURSOR_NO)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_SI;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(DPAD_DOWN) && gPosicionCursorSiNo == CURSOR_SI)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_NO;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gPosicionCursorSiNo == CURSOR_SI)
            {
                HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gBattleScripting.learnMoveState++;
            }
            else
            {
                gBattleScripting.learnMoveState = 5;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleScripting.learnMoveState = 5;
        }
        break;
    case 2:
        if (!gFundidoPaletas.activo)
        {
            FreeAllWindowBuffers();
            ShowSelectMovePokemonSummaryScreen(gPlayerParty, gCombate->expGetterMonId, gPlayerPartyCount - 1, ReshowBattleScreenAfterMenu, gMoveToLearn);
            gBattleScripting.learnMoveState++;
        }
        break;
    case 3:
        if (!gFundidoPaletas.activo && gMain.callback2 == BattleMainCB2)
        {
            gBattleScripting.learnMoveState++;
        }
        break;
    case 4:
        if (!gFundidoPaletas.activo && gMain.callback2 == BattleMainCB2)
        {
            u8 movePosition = GetMoveSlotToReplace();
            if (movePosition == MAXIMO_MOVIMIENTOS_POKEMON)
            {
                gBattleScripting.learnMoveState = 5;
            }
            else
            {
                u16 moveId = GetMonData(&gPlayerParty[gCombate->expGetterMonId], MON_DATA_MOVE1 + movePosition);
                gBattlescriptCurrInstr = cmd->forgotMovePtr;

                PREPARE_MOVE_BUFFER(gBattleTextBuff2, moveId)

                SetMonMoveSlot(&gPlayerParty[gCombate->expGetterMonId], gMoveToLearn, movePosition);

                if (gBattlerPartyIndexes[0] == gCombate->expGetterMonId)
                {
                    SetBattleMonMoveSlot(&gBattleMons[0], gMoveToLearn, movePosition);
                }
                if (EsCombateContraEntrenador(gCombate->tipoCombate) && gBattlerPartyIndexes[2] == gCombate->expGetterMonId)
                {
                    SetBattleMonMoveSlot(&gBattleMons[2], gMoveToLearn, movePosition);
                }
            }
        }
        break;
    case 5:
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    case 6:
        if (!HayAlgunCombatienteOcupado())
        {
            gBattleScripting.learnMoveState = 2;
        }
        break;
    }
}

static void Cmd_yesnoboxstoplearningmove(void)-- > posiblemente no haga falta un global aquí, revisar
{
    CMD_ARGS(const u8 *noInstr);

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleScripting.learnMoveState++;
        gPosicionCursorSiNo = CURSOR_SI;
        CreaCursorBatallaSiNo();
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gPosicionCursorSiNo == CURSOR_NO)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_SI;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(DPAD_DOWN) && gPosicionCursorSiNo == CURSOR_SI)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_NO;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);

            if (gPosicionCursorSiNo == CURSOR_NO)
                gBattlescriptCurrInstr = cmd->noInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;

            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattlescriptCurrInstr = cmd->noInstr;
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        }
        break;
    }
}

static void Cmd_hitanimation(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (!MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)) || gDisableStructs[battler].substituteHP == 0)
    {
        BtlController_EmitHitAnimation(battler, BUFFER_A);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 lastMonLevel = 0;
    u32 moneyReward;
    u8 trainerMoney = 0;

    const struct TrainerMon *party = GetTrainerPartyFromId(trainerId);
    if (party == NULL)
        return 20;
    lastMonLevel = party[GetTrainerPartySizeFromId(trainerId) - 1].lvl;
    trainerMoney = gTrainerClasses[GetTrainerClassFromId(trainerId)].money;

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        moneyReward = 4 * lastMonLevel * gCombate->moneyMultiplier * 2 * trainerMoney;
    else
        moneyReward = 4 * lastMonLevel * gCombate->moneyMultiplier * trainerMoney;

    return moneyReward;
}

static void Cmd_getmoneyreward(void)
{
    CMD_ARGS();

    u32 money;
    u8 sPartyLevel = 1;

    if (gBattleOutcome == B_OUTCOME_WON)
    {
        money = GetTrainerMoneyToGive(gTrainerBattleOpponent);
        AddMoney(&gSaveBlockPtr->money, money);
    }
    else
    {
        s32 i, count;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) > sPartyLevel)
                    sPartyLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            }
        }
        for (count = 0, i = 0; i < ARRAY_COUNT(sBadgeFlags); i++)
        {
            if (FlagGet(sBadgeFlags[i]) == TRUE)
                ++count;
        }
        money = sWhiteOutBadgeMoney[count] * sPartyLevel;
        RemoveMoney(&gSaveBlockPtr->money, money);
    }

    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 5, money);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_swapattackerwithtarget(void)
{
    CMD_ARGS();

    u8 temp;
    SWAP(gBattlerAttacker, gBattlerTarget, temp);

    if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
        gHitMarker &= ~HITMARKER_SWAP_ATTACKER_TARGET;
    else
        gHitMarker |= HITMARKER_SWAP_ATTACKER_TARGET;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_incrementgamestat(void)
{
    CMD_ARGS(u8 stat);

    if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
        IncrementGameStat(cmd->stat);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_drawpartystatussummary(void)
{
    CMD_ARGS(u8 battler);

    u32 battler, i;
    struct Pokemon *party;
    struct HpAndStatus hpStatuses[PARTY_SIZE];

    if (HayAlgunCombatienteOcupado())
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    party = GetBattlerParty(battler);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE || GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
        {
            hpStatuses[i].hp = 0xFFFF;
            hpStatuses[i].status = 0;
        }
        else
        {
            hpStatuses[i].hp = GetMonData(&party[i], MON_DATA_HP);
            hpStatuses[i].status = GetMonData(&party[i], MON_DATA_STATUS);
        }
    }

    BtlController_EmitDrawPartyStatusSummary(battler, BUFFER_A, hpStatuses, 1);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hidepartystatussummary(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitHidePartyStatusSummary(battler, BUFFER_A);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_statusanimation(void)
{
    CMD_ARGS(u8 battler);

    if (!HayAlgunCombatienteOcupado())
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[battler].substituteHP == 0 && !(gHitMarker & (HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, FALSE, gBattleMons[battler].status1);
            MarcaCombatienteOcupado(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_status2animation(void)
{
    CMD_ARGS(u8 battler, u32 status2);

    if (!HayAlgunCombatienteOcupado())
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 status2ToAnim = cmd->status2;
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[battler].substituteHP == 0 && !(gHitMarker & (HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, TRUE, gBattleMons[battler].status2 & status2ToAnim);
            MarcaCombatienteOcupado(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_chosenstatusanimation(void)
{
    CMD_ARGS(u8 battler, bool8 isStatus2, u32 status);

    if (!HayAlgunCombatienteOcupado())
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 wantedStatus = cmd->status;
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE) && gDisableStructs[battler].substituteHP == 0 && !(gHitMarker & (HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, cmd->isStatus2, wantedStatus);
            MarcaCombatienteOcupado(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_yesnobox(void)
{
    CMD_ARGS();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleCommunication[MULTIUSE_STATE]++;
        gPosicionCursorSiNo = CURSOR_SI;
        CreaCursorBatallaSiNo();
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gPosicionCursorSiNo == CURSOR_NO)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_SI;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(DPAD_DOWN) && gPosicionCursorSiNo == CURSOR_SI)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_NO;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(B_BUTTON))
        {
            gPosicionCursorSiNo = CURSOR_NO;
            PlaySE(SE_SELECT);
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

static void Cmd_CancelaAccionesSiNoEntrenador(void)
{
    CMD_ARGS();

    if (!EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        for (s32 i = 0; i < gBattlersCount; i++)
            gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_removeitem(void)
{
    CMD_ARGS(u8 battler);

    u32 battler;
    u16 itemId = 0;

    if (gBattleScripting.overrideBerryRequirements)
    {
        // bug bite / pluck - don't remove current item
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    battler = GetBattlerForBattleScript(cmd->battler);
    itemId = gBattleMons[battler].item;

    // Popped Air Balloon cannot be restored by any means.
    // Corroded items cannot be restored either.
    if (GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_AIR_BALLOON && gMovimientos[gCurrentMove].effect != EFFECT_CORROSIVE_GAS)
        gCombate->usedHeldItems[gBattlerPartyIndexes[battler]][GetBattlerSide(battler)] = itemId; // Remember if switched out

    gBattleMons[battler].item = ITEM_NONE;
    CheckSetUnburden(battler);

    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battler].item), &gBattleMons[battler].item);
    MarcaCombatienteOcupado(battler);

    ClearBattlerItemEffectHistory(battler);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_atknameinbuff1(void)
{
    CMD_ARGS();

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_drawlvlupbox(void)
{
    CMD_ARGS();

    if (gBattleScripting.drawlvlupboxState == 0)
    {
        // If the Pokémon getting exp is not in-battle then
        // slide out a banner with their name and icon on it.
        // Otherwise skip ahead.
        if (IsMonGettingExpSentOut())
            gBattleScripting.drawlvlupboxState = 3;
        else
            gBattleScripting.drawlvlupboxState = 1;
    }

    switch (gBattleScripting.drawlvlupboxState)
    {
    case 1:
        // Start level up banner
        gBattle_BG2_Y = 96;
        SetBgAttribute(2, BG_ATTR_PRIORITY, 0);
        ShowBg(2);
        InitLevelUpBanner();
        gBattleScripting.drawlvlupboxState = 2;
        break;
    case 2:
        if (!SlideInLevelUpBanner())
            gBattleScripting.drawlvlupboxState = 3;
        break;
    case 3:
        // Init level up box
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 256;
        SetBgAttribute(0, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 0);
        ShowBg(0);
        ShowBg(1);
        HandleBattleWindow(18, 7, 29, 19, WINDOW_BG1);
        gBattleScripting.drawlvlupboxState = 4;
        break;
    case 4:
        // Draw page 1 of level up box
        DrawLevelUpWindow1();
        PutWindowTilemap(B_WIN_LEVEL_UP_BOX);
        CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_FULL);
        gBattleScripting.drawlvlupboxState++;
        break;
    case 5:
    case 7:
        // Wait for draw after each page
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattle_BG1_Y = 0;
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 6:
        if (gMain.newKeys != 0)
        {
            // Draw page 2 of level up box
            PlaySE(SE_SELECT);
            DrawLevelUpWindow2();
            CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_GFX);
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 8:
        if (gMain.newKeys != 0)
        {
            // Close level up box
            PlaySE(SE_SELECT);
            HandleBattleWindow(18, 7, 29, 19, WINDOW_BG1 | WINDOW_CLEAR);
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 9:
        if (!SlideOutLevelUpBanner())
        {
            ClearWindowTilemap(B_WIN_LEVEL_UP_BANNER);
            CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_MAP);

            ClearWindowTilemap(B_WIN_LEVEL_UP_BOX);
            CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_MAP);

            SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
            ShowBg(2);

            gBattleScripting.drawlvlupboxState = 10;
        }
        break;
    case 10:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
            SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
            ShowBg(0);
            ShowBg(1);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

static void DrawLevelUpWindow1(void)
{
    u16 currStats[NUMERO_ESTADISTICAS];

    GetMonLevelUpWindowStats(&gPlayerParty[gCombate->expGetterMonId], currStats);
    DrawLevelUpWindowPg1(B_WIN_LEVEL_UP_BOX, gBattleResources->beforeLvlUp->stats, currStats, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_4, TEXT_DYNAMIC_COLOR_6);
}

static void DrawLevelUpWindow2(void)
{
    u16 currStats[NUMERO_ESTADISTICAS];

    GetMonLevelUpWindowStats(&gPlayerParty[gCombate->expGetterMonId], currStats);
    DrawLevelUpWindowPg2(B_WIN_LEVEL_UP_BOX, currStats, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_4, TEXT_DYNAMIC_COLOR_6);
}

static void InitLevelUpBanner(void)
{
    gBattle_BG2_Y = 0;
    gBattle_BG2_X = LEVEL_UP_BANNER_START;

    LoadPalette(sLevelUpBanner_Pal, BG_PLTT_ID(6), sizeof(sLevelUpBanner_Pal));
    CopyToWindowPixelBuffer(B_WIN_LEVEL_UP_BANNER, sLevelUpBanner_Gfx, 0, 0);
    PutWindowTilemap(B_WIN_LEVEL_UP_BANNER);
    CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_FULL);

    PutMonIconOnLvlUpBanner();
}

static bool8 SlideInLevelUpBanner(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return TRUE;

    if (gBattle_BG2_X == LEVEL_UP_BANNER_END)
        return FALSE;

    if (gBattle_BG2_X == LEVEL_UP_BANNER_START)
        DrawLevelUpBannerText();

    gBattle_BG2_X += 8;
    if (gBattle_BG2_X >= LEVEL_UP_BANNER_END)
        gBattle_BG2_X = LEVEL_UP_BANNER_END;

    return (gBattle_BG2_X != LEVEL_UP_BANNER_END);
}

static void DrawLevelUpBannerText(void)
{
    struct TextPrinterTemplate printerTemplate;
    u8 *txtPtr;
    u32 var;

    struct Pokemon *mon = &gPlayerParty[gCombate->expGetterMonId];
    u32 monLevel = GetMonData(mon, MON_DATA_LEVEL);
    u8 monGender = GetMonGender(mon);
    GetMonNickname(mon, gVariableTextoAmpliada);

    printerTemplate.currentChar = gVariableTextoAmpliada;
    printerTemplate.windowId = B_WIN_LEVEL_UP_BANNER;
    printerTemplate.fontId = FONT_SMALL;
    printerTemplate.x = 32;
    printerTemplate.y = 0;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 0;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.fgColor = TEXT_COLOR_WHITE;
    printerTemplate.bgColor = TEXT_COLOR_TRANSPARENT;
    printerTemplate.shadowColor = TEXT_COLOR_DARK_GRAY;

    AddTextPrinter(&printerTemplate, TEXT_SKIP_DRAW, NULL);

    txtPtr = gVariableTextoAmpliada;
    *(txtPtr)++ = CHAR_EXTRA_SYMBOL;
    *(txtPtr)++ = CHAR_LV_2;

    var = (u32)(txtPtr);
    txtPtr = ConvertIntToDecimalStringN(txtPtr, monLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
    var = (u32)(txtPtr)-var;
    txtPtr = StringFill(txtPtr, CHAR_SPACER, 4 - var);

    if (monGender != MON_GENDERLESS)
    {
        if (monGender == MON_MALE)
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, TEXT_DYNAMIC_COLOR_3);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, TEXT_DYNAMIC_COLOR_4);
            *(txtPtr++) = CHAR_MALE;
        }
        else
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, TEXT_DYNAMIC_COLOR_5);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, TEXT_DYNAMIC_COLOR_6);
            *(txtPtr++) = CHAR_FEMALE;
        }
        *(txtPtr++) = EOS;
    }

    printerTemplate.y = 10;
    printerTemplate.currentY = 10;
    AddTextPrinter(&printerTemplate, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_GFX);
}

static bool8 SlideOutLevelUpBanner(void)
{
    if (gBattle_BG2_X == LEVEL_UP_BANNER_START)
        return FALSE;

    if (gBattle_BG2_X - 16 < LEVEL_UP_BANNER_START)
        gBattle_BG2_X = LEVEL_UP_BANNER_START;
    else
        gBattle_BG2_X -= 16;

    return (gBattle_BG2_X != LEVEL_UP_BANNER_START);
}

#define sDestroy data[0]
#define sXOffset data[1]

static void PutMonIconOnLvlUpBanner(void)
{
    u32 spriteId;
    struct SpriteSheet iconSheet;

    struct Pokemon *mon = &gPlayerParty[gCombate->expGetterMonId];
    // u32 index = AllocSpritePalette(TAG_LVLUP_BANNER_MON_ICON);
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);

    iconSheet.data = GraficosIconoPokemon(species, personality);
    iconSheet.size = 0x200;
    iconSheet.tag = TAG_LVLUP_BANNER_MON_ICON;

    LoadSpriteSheet(&iconSheet);

    spriteId = CreateSprite(&sSpriteTemplate_MonIconOnLvlUpBanner, 256, 10, 0);
    gSprites[spriteId].sDestroy = FALSE;
    gSprites[spriteId].sXOffset = gBattle_BG2_X;
    // SetMonIconPalette(&gPlayerParty[gCombate->expGetterMonId], NULL, index);
}

static void SpriteCB_MonIconOnLvlUpBanner(struct Sprite *sprite)
{
    sprite->x2 = sprite->sXOffset - gBattle_BG2_X;

    if (sprite->x2 != 0)
    {
        sprite->sDestroy = TRUE;
    }
    else if (sprite->sDestroy)
    {
        DestroySprite(sprite);
        FreeSpriteTilesByTag(TAG_LVLUP_BANNER_MON_ICON);
        FreeSpritePaletteByTag(TAG_LVLUP_BANNER_MON_ICON);
    }
}

#undef sDestroy
#undef sXOffset

static bool32 IsMonGettingExpSentOut(void)
{
    if (gBattlerPartyIndexes[0] == gCombate->expGetterMonId)
        return TRUE;
    if (EsCombateContraEntrenador(gCombate->tipoCombate) && gBattlerPartyIndexes[2] == gCombate->expGetterMonId)
        return TRUE;

    return FALSE;
}

static void Cmd_resetsentmonsvalue(void)
{
    CMD_ARGS();

    ResetSentPokesToOpponentValue();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setatktoplayer0(void)
{
    CMD_ARGS();

    gBattlerAttacker = JUGADOR_IZQUIERDA;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_makevisible(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (HayAlgunCombatienteOcupado())
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitSpriteInvisibility(battler, BUFFER_A, FALSE);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_recordability(void)
{
    CMD_ARGS(u8 battler);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    RecuerdaHabilidad(battler, gBattleMons[battler].ability);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BufferMoveToLearnIntoBattleTextBuff2(void)
{
    PREPARE_MOVE_BUFFER(gBattleTextBuff2, gMoveToLearn);
}

static void Cmd_buffermovetolearn(void)
{
    CMD_ARGS();

    BufferMoveToLearnIntoBattleTextBuff2();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hpthresholds(void)
{
    CMD_ARGS(u8 battler);

    if (!(EsCombateContraEntrenador(gCombate->tipoCombate)))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 opposingBattler = OPONENTE(battler);

        s32 result = gBattleMons[opposingBattler].hp * 100 / gBattleMons[opposingBattler].maxHP;
        if (result == 0)
            result = 1;

        if (result > 69 || !IsBattlerAlive(opposingBattler))
            gCombate->hpScale = 0;
        else if (result > 39)
            gCombate->hpScale = 1;
        else if (result > 9)
            gCombate->hpScale = 2;
        else
            gCombate->hpScale = 3;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hpthresholds2(void)
{
    CMD_ARGS(u8 battler);

    if (!(EsCombateContraEntrenador(gCombate->tipoCombate)))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 opposingBattler = OPONENTE(battler);
        u8 hpSwitchout = *(gCombate->hpOnSwitchout + GetBattlerSide(opposingBattler));
        s32 result = (hpSwitchout - gBattleMons[opposingBattler].hp) * 100 / hpSwitchout;

        if (gBattleMons[opposingBattler].hp >= hpSwitchout)
            gCombate->hpScale = 0;
        else if (result <= 29)
            gCombate->hpScale = 1;
        else if (result <= 69)
            gCombate->hpScale = 2;
        else
            gCombate->hpScale = 3;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_useitemonopponent(void)
{
    CMD_ARGS();

    gBattlerInMenuId = gBattlerAttacker;
    PokemonUseItemEffects(&gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]], gLastUsedItem, gBattlerPartyIndexes[gBattlerAttacker], 0, TRUE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static bool32 HasAttackerFaintedTarget(void)
{
    if (MovimientoEsEfectivo(gCombate->resultadoMovimiento)
     && !EsMovimientoEstado(gCurrentMove)
     && (gLastHitBy[gBattlerTarget] == 0xFF || gLastHitBy[gBattlerTarget] == gBattlerAttacker)
     && gCombate->moveTarget[gBattlerAttacker] == gBattlerTarget
     && gBattlerTarget != gBattlerAttacker
     && gCurrentTurnActionNumber == GetBattlerTurnOrderNum(gBattlerAttacker)
     && (gChosenMove == gMovimientoElegido[gBattlerAttacker] || gChosenMove == gBattleMons[gBattlerAttacker].moves[gChosenMovePos]))
        return TRUE;
    else
        return FALSE;
}

bool32 CanPoisonType(u32 objetivo)
{
    return (!EsTipo(objetivo, TIPO_VENENO));
}

bool32 CanParalyzeType(u32 objetivo)
{
    return (!EsTipo(objetivo, TIPO_ELECTRICO));
}

#define DEFOG_CLEAR(status, structField, battlescript, move)     \
    {                                                            \
        if (*sideStatuses & status)                              \
        {                                                        \
            if (clear)                                           \
            {                                                    \
                if (move)                                        \
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, move); \
                *sideStatuses &= ~status;                        \
                sideTimer->structField = 0;                      \
                BattleScriptPushCursor();                        \
                gBattlescriptCurrInstr = battlescript;           \
            }                                                    \
            else                                                 \
            {                                                    \
                gBattlerAttacker = saveBattler;                  \
            }                                                    \
            return TRUE;                                         \
        }                                                        \
    }

static bool32 TryDefogClear(u32 battlerAtk, bool32 clear)
{
    u32 lado;
    u32 combatientePrevio = gBattlerAttacker;

    for (lado = 0; lado < NUMERO_LADOS; lado++)
    {
        struct SideTimer *sideTimer = &gSideTimers[lado];
        u32 *sideStatuses = &gSideStatuses[lado];

        if (GetBattlerSide(battlerAtk) != lado)
        {
            gBattlerAttacker = lado; // For correct battle string. Ally's / Foe's
            DEFOG_CLEAR(SIDE_STATUS_REFLECT, reflectTimer, BattleScript_SideStatusWoreOffReturn, MOVE_REFLECT);
            DEFOG_CLEAR(SIDE_STATUS_LIGHTSCREEN, lightscreenTimer, BattleScript_SideStatusWoreOffReturn, MOVE_LIGHT_SCREEN);
            DEFOG_CLEAR(SIDE_STATUS_MIST, mistTimer, BattleScript_SideStatusWoreOffReturn, MOVE_NEBLINA);
            DEFOG_CLEAR(SIDE_STATUS_AURORA_VEIL, auroraVeilTimer, BattleScript_SideStatusWoreOffReturn, MOVE_VELO_AURORA);
            DEFOG_CLEAR(SIDE_STATUS_SAFEGUARD, safeguardTimer, BattleScript_SideStatusWoreOffReturn, MOVE_SAFEGUARD);
        }
        gBattlerAttacker = lado; // For correct battle string. Ally's / Foe's
        DEFOG_CLEAR(SIDE_STATUS_SPIKES, spikesAmount, BattleScript_SpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STEALTH_ROCK, stealthRockAmount, BattleScript_StealthRockDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_TOXIC_SPIKES, toxicSpikesAmount, BattleScript_ToxicSpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STICKY_WEB, stickyWebAmount, BattleScript_StickyWebDefog, 0);
    }

    gBattlerAttacker = combatientePrevio;

    return FALSE;
}

u32 GetHighestStatId(u32 battler)
{
    u32 i, highestId = ESTADISTICA_ATAQUE, highestStat = gBattleMons[battler].attack;

    for (i = ESTADISTICA_DEFENSA; i < NUMERO_ESTADISTICAS; i++)
    {
        u16 *statVal = &gBattleMons[battler].attack + (i - 1);
        if (*statVal > highestStat && i != ESTADISTICA_VELOCIDAD)
        {
            highestStat = *statVal;
            highestId = i;
        }
    }
    if (gBattleMons[battler].speed > highestStat)
        highestId = ESTADISTICA_VELOCIDAD;

    return highestId;
}

static void Cmd_various(void)
{
    CMD_ARGS(u8 battler, u8 id);

    struct Pokemon *mon;
    s32 i;
    u8 data[10];
    u32 battler, bits;

    if (HayAlgunCombatienteOcupado())
        return;

    battler = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->id)
    {
    // Roar will fail in a double wild battle when used by the player against one of the two alive wild mons.
    // Also when an opposing wild mon uses it againt its partner.
    // Also when B_FLAG_NO_RUNNING is enabled.
    case VARIOUS_JUMP_IF_ROAR_FAILS:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_ABSENT:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerAlive(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_HOLD_EFFECT:
    {
        VARIOUS_ARGS(u8 holdEffect, const u8 *jumpInstr, u8 equal);
        if ((GetBattlerHoldEffect(battler, TRUE) == cmd->holdEffect) == cmd->equal)
        {
            if (cmd->equal)
                gLastUsedItem = gBattleMons[battler].item; // For B_LAST_USED_ITEM
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            if (!cmd->equal)
                gLastUsedItem = gBattleMons[battler].item; // For B_LAST_USED_ITEM
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NO_ALLY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerAlive(ALIADO(battler)))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_INFATUATE_WITH_BATTLER:
    {
        VARIOUS_ARGS(u8 infatuateWith);
        gBattleScripting.battler = battler;
        gBattleMons[battler].status2 |= STATUS2_INFATUATED_WITH(GetBattlerForBattleScript(cmd->infatuateWith));
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gLastUsedItem = gBattleMons[battler].item;
        break;
    }
    case VARIOUS_JUMP_IF_FULL_HP:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsBattlerAtMaxHp(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_POISON_TYPE_IMMUNITY:
    {
        VARIOUS_ARGS(u8 target, const u8 *failInstr);
        if (!CanPoisonType(GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PARALYZE_TYPE_IMMUNITY:
    {
        VARIOUS_ARGS(u8 target, const u8 *failInstr);
        if (!CanParalyzeType(GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRACE_ABILITY:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].ability = gCombate->overwrittenAbilities[battler] = gCombate->tracedAbility[battler];
        break;
    }
    case VARIOUS_UPDATE_NICK:
    {
        VARIOUS_ARGS();
        if (GetBattlerSide(battler) == LADO_JUGADOR)
            mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
        else
            mon = &gEnemyParty[gBattlerPartyIndexes[battler]];
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_NICK);
        break;
    }
    case VARIOUS_JUMP_IF_NOT_BERRY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gBattleMons[battler].item) == POCKET_BERRIES)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_SPECTRAL_THIEF:
    {
        VARIOUS_ARGS();
        // Raise stats
        for (i = ESTADISTICA_ATAQUE; i < NUMERO_ESTADISTICAS_BATALLA; i++)
        {
            if (gCombate->stolenStats[0] & (1u << i))
            {
                gCombate->stolenStats[0] &= ~(1u << i);
                SET_STATCHANGER(i, gCombate->stolenStats[i], FALSE);
                if (ChangeStatBuffs(GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger), i, MOVE_EFFECT_CERTAIN | MOVE_EFFECT_AFFECTS_USER, NULL) == STAT_CHANGE_WORKED)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_StatUpMsg;
                    return;
                }
            }
        }
        break;
    }
    case VARIOUS_CANCEL_MULTI_TURN_MOVES:
    {
        VARIOUS_ARGS();
        const u8 *result;
        result = CancelMultiTurnMoves(battler);
        if (result)
        {
            gBattlescriptCurrInstr = result;
            return;
        }
        break;
    }
    case VARIOUS_GET_MOVE_TARGET:
    {
        VARIOUS_ARGS();
        gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
        break;
    }
    case VARIOUS_GET_BATTLER_FAINTED:
    {
        VARIOUS_ARGS();
        if (gHitMarker & HITMARKER_FAINTED(battler))
            gBattleCommunication[MULTIUSE_STATE] = TRUE;
        else
            gBattleCommunication[MULTIUSE_STATE] = FALSE;
        break;
    }
    case VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP:
    {
        VARIOUS_ARGS();
        if (gBattlerPartyIndexes[0] == gCombate->expGetterMonId || gBattlerPartyIndexes[2] == gCombate->expGetterMonId)
        {
            if (gBattlerPartyIndexes[0] == gCombate->expGetterMonId)
                battler = 0;
            else
                battler = 2;

            for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
            {
                if (gBattleMons[battler].moves[i] == gCombate->choicedMove[battler])
                    break;
            }
            if (i == MAXIMO_MOVIMIENTOS_POKEMON)
                gCombate->choicedMove[battler] = MOVE_NONE;
        }
        break;
    }
    case VARIOUS_RESET_PLAYER_FAINTED:
    {
        VARIOUS_ARGS();
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && IsBattlerAlive(JUGADOR_IZQUIERDA) && IsBattlerAlive(OPONENTE_IZQUIERDA))
        {
            gHitMarker &= ~HITMARKER_PLAYER_FAINTED;
        }
        break;
    }
    case VARIOUS_EMIT_YESNOBOX:
    {
        VARIOUS_ARGS();
        BtlController_EmitYesNoBox(battler, BUFFER_A);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_WAIT_CRY:
    {
        VARIOUS_ARGS();
        if (!IsCryFinished())
            return;
        break;
    }
    case VARIOUS_RETURN_OPPONENT_MON1:
    {
        VARIOUS_ARGS();
        battler = 1;
        if (IsBattlerAlive(battler))
        {
            BtlController_EmitReturnMonToBall(battler, BUFFER_A, FALSE);
            MarcaCombatienteOcupado(battler);
        }
        break;
    }
    case VARIOUS_RETURN_OPPONENT_MON2:
    {
        VARIOUS_ARGS();
        if (gBattlersCount > 3)
        {
            battler = 3;
            if (IsBattlerAlive(battler))
            {
                BtlController_EmitReturnMonToBall(battler, BUFFER_A, FALSE);
                MarcaCombatienteOcupado(battler);
            }
        }
        break;
    }
    case VARIOUS_VOLUME_DOWN:
    {
        VARIOUS_ARGS();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_BAJO);
        break;
    }
    case VARIOUS_VOLUME_UP:
    {
        VARIOUS_ARGS();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
        break;
    }
    case VARIOUS_SET_TELEPORT_OUTCOME:
    {
        VARIOUS_ARGS();
        // Don't end the battle if one of the wild mons teleported from the wild double battle
        // and its partner is still alive.
        if (GetBattlerSide(battler) == LADO_OPONENTE && IsBattlerAlive(ALIADO(battler)))
        {
            gAbsentBattlerFlags |= 1u << battler;
            gHitMarker |= HITMARKER_FAINTED(battler);
            gBattleMons[battler].hp = 0;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP, &gBattleMons[battler].hp);
            SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
            FaintClearSetData(battler);
        }
        else if (GetBattlerSide(battler) == LADO_JUGADOR)
        {
            gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        }
        else
        {
            gBattleOutcome = B_OUTCOME_MON_TELEPORTED;
        }
        break;
    }
    case VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC:
    {
        VARIOUS_ARGS();
        BtlController_EmitPlayFanfareOrBGM(battler, BUFFER_A, MUS_VICTORY_TRAINER, TRUE);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_STAT_TEXT_BUFFER:
    {
        VARIOUS_ARGS();
        PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleCommunication[MULTIUSE_STATE]);
        break;
    }
    case VARIOUS_SWITCHIN_ABILITIES:
    {
        VARIOUS_ARGS();
        gBattlescriptCurrInstr = cmd->nextInstr;
        AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, battler, 0, 0, 0);
        AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battler, 0, 0, 0);
        return;
    }
    case VARIOUS_INSTANT_HP_DROP:
    {
        VARIOUS_ARGS();
        BtlController_EmitHealthBarUpdate(battler, BUFFER_A, INSTANT_HP_BAR_DROP);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_CLEAR_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].status1 = 0;
        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_INTENTA_ACTIVAR_AUTOESTIMA: // and chilling neigh + as one ice rider
    {
        VARIOUS_ARGS();

        u16 battlerAbility = HabilidadCombatiente(battler);

        if ((battlerAbility == ABILITY_AUTOESTIMA) && HasAttackerFaintedTarget() && !NoAliveMonsForEitherParty() && CompareStat(gBattlerAttacker, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
        {
            SET_STATCHANGER(ESTADISTICA_ATAQUE, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, ESTADISTICA_ATAQUE);
            BattleScriptPush(cmd->nextInstr);
            gLastUsedAbility = battlerAbility;
            gBattlescriptCurrInstr = BattleScript_RaiseStatOnFaintingTarget;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_BEAST_BOOST:
    {
        VARIOUS_ARGS();

        i = GetHighestStatId(battler);
        if (HabilidadCombatiente(battler) == ABILITY_BEAST_BOOST && HasAttackerFaintedTarget() && !NoAliveMonsForEitherParty() && CompareStat(gBattlerAttacker, i, ESTADISTICA_MAS_6, COMPARACION_MENOR))
        {
            SET_STATCHANGER(i, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, i);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_AttackerAbilityStatRaise;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_SOULHEART:
    {
        VARIOUS_ARGS();
        while (gCombate->soulheartBattlerId < gBattlersCount)
        {
            gBattleScripting.battler = gCombate->soulheartBattlerId++;
            if (HabilidadCombatiente(gBattleScripting.battler) == ABILITY_SOUL_HEART && IsBattlerAlive(gBattleScripting.battler) && !NoAliveMonsForEitherParty() && CompareStat(gBattleScripting.battler, ESTADISTICA_ATAQUE_ESPECIAL, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                SET_STATCHANGER(ESTADISTICA_ATAQUE_ESPECIAL, 1, FALSE);
                PREPARE_STAT_BUFFER(gBattleTextBuff1, ESTADISTICA_ATAQUE_ESPECIAL);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ScriptingAbilityStatRaise;
                return;
            }
        }
        gCombate->soulheartBattlerId = 0;
        break;
    }
    case VARIOUS_TRY_ACTIVATE_FELL_STINGER:
    {
        VARIOUS_ARGS();
        if (gMovimientos[gCurrentMove].effect == EFFECT_FELL_STINGER && HasAttackerFaintedTarget() && !NoAliveMonsForEitherParty() && CompareStat(gBattlerAttacker, ESTADISTICA_ATAQUE, ESTADISTICA_MAS_6, COMPARACION_MENOR))
        {
            SET_STATCHANGER(ESTADISTICA_ATAQUE, 2, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, ESTADISTICA_ATAQUE);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_FellStingerRaisesStat;
            return;
        }
        break;
    }
    case VARIOUS_PLAY_MOVE_ANIMATION:
    {
        VARIOUS_ARGS(u16 move);
        BtlController_EmitMoveAnimation(battler, BUFFER_A, cmd->move, gBattleScripting.animTurn, 0, 0, gBattleMons[battler].friendship, &gDisableStructs[battler], gCombate->contadorMultigolpes);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_GOLPE_BAJO_CHECK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->failInstr;
        else if (EsMovimientoEstado(gBattleMons[gBattlerTarget].moves[gCombate->chosenMovePositions[gBattlerTarget]]))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LAST_USED_ABILITY:
    {
        VARIOUS_ARGS();
        gLastUsedAbility = gBattleMons[battler].ability;
        break;
    }
    case VARIOUS_INVERT_STAT_STAGES:
    {
        VARIOUS_ARGS();
        for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
        {
            if (gBattleMons[battler].statStages[i] < ESTADISTICA_NEUTRA) // Negative becomes positive.
                gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA + (ESTADISTICA_NEUTRA - gBattleMons[battler].statStages[i]);
            else if (gBattleMons[battler].statStages[i] > ESTADISTICA_NEUTRA) // Positive becomes negative.
                gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA - (gBattleMons[battler].statStages[i] - ESTADISTICA_NEUTRA);
        }
        break;
    }
    case VARIOUS_JUMP_IF_BATTLE_END:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (NoAliveMonsForEitherParty())
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_HANDLE_FORM_CHANGE:
    {
        VARIOUS_ARGS(u8 case_);
        mon = GetPartyBattlerData(battler);

        // Change species.
        if (cmd->case_ == 0)
        {
            /* What was the idea here?
            if (!gBattleTextBuff1)
                PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battler].species);
            */
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_SPECIES_BATTLE, 1u << gBattlerPartyIndexes[battler], sizeof(gBattleMons[battler].species), &gBattleMons[battler].species);
            MarcaCombatienteOcupado(battler);
        }
        // Change stats.
        else if (cmd->case_ == 1)
        {
            RecalcBattlerStats(battler, mon);
        }
        // Update healthbox.
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_ALL);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_ARG_TO_BATTLE_DAMAGE:
    {
        VARIOUS_ARGS();
        gBattleMoveDamage = gMovimientos[gCurrentMove].argument;
        break;
    }
    case VARIOUS_TRY_AUTOTOMIZE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerWeight(battler) > 1)
        {
            gDisableStructs[battler].autotomizeCount++;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        CreaMensajeHabilidad(battler, gBattleMons[battler].ability);
        break;
    }
    case VARIOUS_UPDATE_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        ActualizaVentanaHabilidad(battler);
        break;
    }
    case VARIOUS_JUMP_IF_TARGET_ALLY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_CURE_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].status1 = 0;
        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_JUMP_IF_NOT_GROUNDED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!EstaCombatienteEnSuelo(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_HANDLE_TRAINER_SLIDE_MSG:
    {
        VARIOUS_ARGS(u8 case_);
        if (cmd->case_ == 0)
        {
            // Save sprite IDs, because trainer slide in will overwrite gBattlerSpriteIds variable.
            gBattleScripting.savedDmg = (gBattlerSpriteIds[battler] & 0xFF) | (gBattlerSpriteIds[ALIADO(battler)] << 8);
        }
        else if (cmd->case_ == 1)
        {
            ControladorCombate_EscribeTexto(battler, BUFFER_A, STRINGID_TRAINERSLIDE);
            MarcaCombatienteOcupado(battler);
        }
        else
        {
            gBattlerSpriteIds[ALIADO(battler)] = gBattleScripting.savedDmg >> 8;
            gBattlerSpriteIds[battler] = gBattleScripting.savedDmg & 0xFF;
            if (IsBattlerAlive(battler))
            {
                SetBattlerShadowSpriteCallback(battler, gBattleMons[battler].species);
                BattleLoadMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
            }
            i = ALIADO(battler);
            if (IsBattlerAlive(i))
            {
                SetBattlerShadowSpriteCallback(i, gBattleMons[i].species);
                BattleLoadMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[i]], i);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(battler, TRAINER_SLIDE_FIRST_DOWN)))
        {
            gBattleScripting.battler = battler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_TrainerSlideMsgRet;
            return;
        }
        break;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(battler, TRAINER_SLIDE_LAST_SWITCHIN)))
        {
            gBattleScripting.battler = battler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_TrainerSlideMsgRet;
            return;
        }
        break;
    }
    case VARIOUS_SET_AURORA_VEIL:
    {
        VARIOUS_ARGS();
        if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_AURORA_VEIL || !(ClimaTieneEfecto() && gBattleWeather & B_WEATHER_SNOW))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
        else
        {
            gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_AURORA_VEIL;
            if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                gSideTimers[GetBattlerSide(battler)].auroraVeilTimer = TURNOS_EFECTOS * 2;
            else
                gSideTimers[GetBattlerSide(battler)].auroraVeilTimer = TURNOS_EFECTOS;
            gSideTimers[GetBattlerSide(battler)].auroraVeilBattlerId = battler;

            if (EsCombateContraEntrenador(gCombate->tipoCombate) && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
        }
        break;
    }
    case VARIOUS_DESTROY_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        DestruyeMensajeHabilidad(battler);
        break;
    }
    case VARIOUS_MOVEEND_ITEM_EFFECTS:
    {
        VARIOUS_ARGS();
        if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
            return;
        break;
    }
    case VARIOUS_ROOM_SERVICE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_ROOM_SERVICE && TryRoomService(battler))
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_MAKE_INVISIBLE:
    {
        VARIOUS_ARGS();
        if (HayAlgunCombatienteOcupado())
            break;

        BtlController_EmitSpriteInvisibility(battler, BUFFER_A, TRUE);
        MarcaCombatienteOcupado(battler);
        break;
    }
    case VARIOUS_JUMP_IF_TEAM_HEALTHY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if ((EsCombateContraEntrenador(gCombate->tipoCombate)) && IsBattlerAlive(ALIADO(battler)))
        {
            u8 partner = ALIADO(battler);
            if ((gBattleMons[battler].hp == gBattleMons[battler].maxHP && !(gBattleMons[battler].status1 & STATUS1_ANY)) && (gBattleMons[partner].hp == gBattleMons[partner].maxHP && !(gBattleMons[partner].status1 & STATUS1_ANY)))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else // single battle
        {
            if (gBattleMons[battler].hp == gBattleMons[battler].maxHP && !(gBattleMons[battler].status1 & STATUS1_ANY))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_HEAL_QUARTER_HP:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        gBattleMoveDamage = CuantosPSMaximos(battler) / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (gBattleMons[battler].hp == gBattleMons[battler].maxHP)
            gBattlescriptCurrInstr = cmd->failInstr; // fail
        else
            gBattlescriptCurrInstr = cmd->nextInstr; // can heal
        return;
    }
    case VARIOUS_JUMP_IF_BROMISTA_BLOCKED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (BlocksPrankster(gCurrentMove, gBattlerAttacker, battler, TRUE))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_END_NEUTRALIZING_GAS:
    {
        VARIOUS_ARGS();
        if (gSpecialStatuses[battler].neutralizingGasRemoved)
        {
            gSpecialStatuses[battler].neutralizingGasRemoved = FALSE;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_NeutralizingGasExits;
            return;
        }
        break;
    }
    case VARIOUS_CONSUME_BERRY:
    {
        VARIOUS_ARGS(bool8 fromBattler);
        if (gBattleScripting.overrideBerryRequirements == 2)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }

        if (cmd->fromBattler)
            gLastUsedItem = gBattleMons[battler].item;

        gCombate->ateBerry[battler & BIT_SIDE] |= 1u << gBattlerPartyIndexes[battler];
        gBattleScripting.battler = gEffectBattler = gBattlerTarget = battler; // Cover all berry effect battler cases. e.g. ChangeStatBuffs uses target ID
        if (ItemBattleEffects(ITEMEFFECT_USE_LAST_ITEM, battler, FALSE))
            return;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_WEATHER_AFFECTED:
    {
        VARIOUS_ARGS(u32 flags, const u8 *jumpInstr);
        u32 flags = cmd->flags;
        if (IsBattlerWeatherAffected(battler, flags)) // Revisar + gBattleWeather ClimaTieneEfecto
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_SPECIES:
    {
        VARIOUS_ARGS(u16 species, const u8 *jumpInstr);
        if (gBattleMons[battler].species == cmd->species)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_ATTACKER_STICKY_WEB_USER:
    {
        VARIOUS_ARGS();
        // For Mirror Armor: "If the Pokémon with this Ability is affected by Sticky Web, the effect is reflected back to the Pokémon which set it up.
        //  If Pokémon which set up Sticky Web is not on the field, no Pokémon have their Speed lowered."
        gBattlerAttacker = gBattlerTarget; // Initialize 'fail' condition
        SET_STATCHANGER(ESTADISTICA_VELOCIDAD, 1, TRUE);
        if (gSideTimers[GetBattlerSide(battler)].stickyWebBattlerId != 0xFF)
            gBattlerAttacker = gSideTimers[GetBattlerSide(battler)].stickyWebBattlerId;
        break;
    }
    case VARIOUS_CUT_1_3_HP_RAISE_STATS:
    {
        VARIOUS_ARGS(const u8 *failInstr);

        bool8 atLeastOneStatBoosted = FALSE;
        u16 hpFraction = max(1, CuantosPSMaximos(gBattlerAttacker) / 3);

        for (i = 1; i < NUMERO_ESTADISTICAS; i++)
        {
            if (CompareStat(gBattlerAttacker, i, ESTADISTICA_MAS_6, COMPARACION_MENOR))
            {
                atLeastOneStatBoosted = TRUE;
                break;
            }
        }
        if (atLeastOneStatBoosted && gBattleMons[gBattlerAttacker].hp > hpFraction)
        {
            gBattleMoveDamage = hpFraction;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_CURE_CERTAIN_STATUSES:
    {
        VARIOUS_ARGS();
        // Check infatuation
        if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
        {
            gBattleMons[battler].status2 &= ~(STATUS2_INFATUATION);
            gMensajeBatalla = B_MSG_MENTALHERBCURE_INFATUATION; // STRINGID_TARGETGOTOVERINFATUATION
            StringCopy(gBattleTextBuff1, gText_Love);
        }
        // Check taunt
        if (gDisableStructs[battler].tauntTimer != 0)
        {
            gDisableStructs[battler].tauntTimer = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
        }
        // Check encore
        if (gDisableStructs[battler].encoreTimer != 0)
        {
            gDisableStructs[battler].encoredMove = 0;
            gDisableStructs[battler].encoreTimer = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_ENCORE; // STRINGID_PKMNENCOREENDED
        }
        // Check torment
        if (gBattleMons[battler].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battler].status2 &= ~(STATUS2_TORMENT);
            gMensajeBatalla = B_MSG_MENTALHERBCURE_TORMENT;
        }
        // Check disable
        if (gDisableStructs[battler].disableTimer != 0)
        {
            gDisableStructs[battler].disableTimer = 0;
            gDisableStructs[battler].disabledMove = 0;
            gMensajeBatalla = B_MSG_MENTALHERBCURE_DISABLE;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES:
    {
        VARIOUS_ARGS();
        battler = gBattlerTarget;
        for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
            if (gBattleMons[battler].statStages[i] < ESTADISTICA_NEUTRA)
                gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gLastUsedItem) == POCKET_BERRIES)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT:
    {
        VARIOUS_ARGS(u8 holdEffect, const u8 *jumpInstr);
        if (ItemId_GetHoldEffect(gLastUsedItem) == cmd->holdEffect)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SAVE_BATTLER_ITEM:
    {
        VARIOUS_ARGS();
        gBattleResources->battleHistory->heldItems[battler] = gBattleMons[battler].item;
        break;
    }
    case VARIOUS_RESTORE_BATTLER_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].item = gBattleResources->battleHistory->heldItems[battler];
        break;
    }
    case VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].item = gLastUsedItem;
        break;
    }
    case VARIOUS_SWAP_STATS:
    {
        VARIOUS_ARGS(u8 stat);

        u8 stat = cmd->stat;
        u16 temp;

        switch (stat)
        {
        case ESTADISTICA_PS:
            SWAP(gBattleMons[gBattlerAttacker].hp, gBattleMons[gBattlerTarget].hp, temp);
            break;
        case ESTADISTICA_ATAQUE:
            SWAP(gBattleMons[gBattlerAttacker].attack, gBattleMons[gBattlerTarget].attack, temp);
            break;
        case ESTADISTICA_DEFENSA:
            SWAP(gBattleMons[gBattlerAttacker].defense, gBattleMons[gBattlerTarget].defense, temp);
            break;
        case ESTADISTICA_VELOCIDAD:
            SWAP(gBattleMons[gBattlerAttacker].speed, gBattleMons[gBattlerTarget].speed, temp);
            break;
        case ESTADISTICA_ATAQUE_ESPECIAL:
            SWAP(gBattleMons[gBattlerAttacker].spAttack, gBattleMons[gBattlerTarget].spAttack, temp);
            break;
        case ESTADISTICA_DEFENSA_ESPECIAL:
            SWAP(gBattleMons[gBattlerAttacker].spDefense, gBattleMons[gBattlerTarget].spDefense, temp);
            break;
        }
        PREPARE_STAT_BUFFER(gBattleTextBuff1, stat);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    } // End of switch (cmd->id)

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void TryResetProtectUseCounter(u32 battler)
{
    u32 lastMove = gLastResultingMoves[battler];
    if (lastMove == MOVE_NONE || !gBattleMoveEffects[gMovimientos[lastMove].effect].usesProtectCounter)
        gDisableStructs[battler].protectUses = 0;
}

static void Cmd_ColocaProteccion(void)
{
    CMD_ARGS();

    bool32 fail = TRUE;
    bool32 notLastTurn = TRUE;

    TryResetProtectUseCounter(gBattlerAttacker);
    if (gCurrentTurnActionNumber == (gBattlersCount - 1))
        notLastTurn = FALSE;

    if (sProtectSuccessRates[gDisableStructs[gBattlerAttacker].protectUses] >= Random() && notLastTurn)
    {
        gProtectStructs[gBattlerAttacker].protected = TRUE;
        gMensajeBatalla = TEXTO_COMBATE_PROTECCION;
        gDisableStructs[gBattlerAttacker].protectUses++;
        fail = FALSE;
    }

    if (fail)
    {
        gDisableStructs[gBattlerAttacker].protectUses = 0;
        gMensajeBatalla = B_MSG_PROTECT_FAILED;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryexplosion(void)
{
    CMD_ARGS();

    if (HayAlgunCombatienteOcupado())
        return;

    gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp;
    BtlController_EmitHealthBarUpdate(gBattlerAttacker, BUFFER_A, INSTANT_HP_BAR_DROP);
    MarcaCombatienteOcupado(gBattlerAttacker);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setatkhptozero(void)
{
    CMD_ARGS();

    if (HayAlgunCombatienteOcupado())
        return;

    gBattleMons[gBattlerAttacker].hp = 0;
    BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].hp), &gBattleMons[gBattlerAttacker].hp);
    MarcaCombatienteOcupado(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnexttargetvalid(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    const u8 *jumpInstr = cmd->jumpInstr;

    for (gBattlerTarget++; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove) & MOVE_TARGET_USER))
            continue;
        if (IsBattlerAlive(gBattlerTarget))
            break;
    }

    if (gBattlerTarget >= gBattlersCount)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = jumpInstr;
}

static void Cmd_tryhealhalfhealth(void)
{
    CMD_ARGS(const u8 *failInstr, u8 battler);

    const u8 *failInstr = cmd->failInstr;

    if (cmd->battler == BS_ATTACKER)
        gBattlerTarget = gBattlerAttacker;

    gBattleMoveDamage = CuantosPSMaximos(gBattlerTarget) / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
        gBattlescriptCurrInstr = failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setfieldweather(void)
{
    CMD_ARGS(u8 weather);

    u8 weather = cmd->weather;

    if (!TryChangeBattleWeather(gBattlerAttacker, weather, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_WEATHER_FAILED;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    switch (weather)
    {
    case ENUM_WEATHER_RAIN:
        gMensajeBatalla = B_MSG_STARTED_RAIN;
        break;
    case ENUM_WEATHER_SUN:
        gMensajeBatalla = B_MSG_STARTED_SUNLIGHT;
        break;
    case ENUM_WEATHER_SANDSTORM:
        gMensajeBatalla = B_MSG_STARTED_SANDSTORM;
        break;
    case ENUM_WEATHER_SNOW:
        gMensajeBatalla = B_MSG_STARTED_SNOW;
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setreflect(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_REFLECT)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_REFLECT;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectTimer = TURNOS_EFECTOS * 2;
        else
            gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectTimer = TURNOS_EFECTOS;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectBattlerId = gBattlerAttacker;

        if (EsCombateContraEntrenador(gCombate->tipoCombate) && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
            gMensajeBatalla = B_MSG_SET_REFLECT_DOUBLE;
        else
            gMensajeBatalla = B_MSG_SET_REFLECT_SINGLE;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setseeded(void)
{
    CMD_ARGS();

    if (!(EsMovimientoEfectivo(gCombate->resultadoMovimiento)) || gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_LEECH_SEED_MISS;
    }
    else if (EsTipo(gBattlerTarget, TIPO_PLANTA))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_LEECH_SEED_FAIL;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= gBattlerAttacker;
        gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
        gMensajeBatalla = B_MSG_LEECH_SEED_SET;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_manipulatedamage(void)
{
    CMD_ARGS(u8 mode);

    switch (cmd->mode)
    {
    case DMG_CHANGE_SIGN:
        gBattleMoveDamage *= -1;
        break;
    case DMG_1_8_TARGET_HP:
        gBattleMoveDamage = CuantosPSMaximos(gBattlerTarget) / 8;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case DMG_FULL_ATTACKER_HP:
        gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker);
        break;
    case DMG_CURR_ATTACKER_HP:
        gBattleMoveDamage = CuantosPSLeQuedan(gBattlerAttacker);
        break;
    case DMG_BIG_ROOT:
        gBattleMoveDamage = GetDrainedBigRootHp(gBattlerAttacker, gBattleMoveDamage);
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetrest(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;
    gBattlerTarget = gBattlerAttacker;
    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP * (-1);

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
    {
        gBattlescriptCurrInstr = failInstr;
    }
    else
    {
        if (gBattleMons[gBattlerTarget].status1 & ((u8)(~STATUS1_SLEEP)))
            gMensajeBatalla = B_MSG_REST_STATUSED;
        else
            gMensajeBatalla = B_MSG_REST;

        gBattleMons[gBattlerTarget].status1 = STATUS1_SLEEP;
        BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
        MarcaCombatienteOcupado(gBattlerTarget);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifnotfirstturn(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    const u8 *jumpInstr = cmd->jumpInstr;

    if (EsPrimerTurno(gBattlerAttacker))
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = jumpInstr;
}

bool8 UproarWakeUpCheck(u8 battler)
{
    s32 i;
    bool32 hasSoundproof = (B_UPROAR_IGNORE_SOUNDPROOF < GEN_5 && HabilidadCombatiente(battler) == ABILITY_SOUNDPROOF);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || hasSoundproof)
            continue;

        gBattleScripting.battler = i;

        if (gBattlerTarget == 0xFF)
            gBattlerTarget = i;
        else if (gBattlerTarget == i)
            gMensajeBatalla = B_MSG_CANT_SLEEP_UPROAR;
        else
            gMensajeBatalla = B_MSG_UPROAR_KEPT_AWAKE;

        break;
    }

    if (i == gBattlersCount)
        return FALSE;
    else
        return TRUE;
}

static void Cmd_jumpifuproarwakes(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (UproarWakeUpCheck(gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_stockpile(void)
{
    CMD_ARGS(u8 id);

    switch (cmd->id)
    {
    case 0:
        if (gDisableStructs[gBattlerAttacker].stockpileCounter >= 3)
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gMensajeBatalla = B_MSG_CANT_STOCKPILE;
        }
        else
        {
            gDisableStructs[gBattlerAttacker].stockpileCounter++;
            gDisableStructs[gBattlerAttacker].stockpileBeforeDef = gBattleMons[gBattlerAttacker].statStages[ESTADISTICA_DEFENSA];
            gDisableStructs[gBattlerAttacker].stockpileBeforeSpDef = gBattleMons[gBattlerAttacker].statStages[ESTADISTICA_DEFENSA_ESPECIAL];
            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gBattlerAttacker].stockpileCounter);
            gMensajeBatalla = B_MSG_STOCKPILED;
        }
        break;
    case 1: // Save def/sp def stats.
        if (MovimientoEsEfectivo(gCombate->resultadoMovimiento))
        {
            gDisableStructs[gBattlerAttacker].stockpileDef += gBattleMons[gBattlerAttacker].statStages[ESTADISTICA_DEFENSA] - gDisableStructs[gBattlerAttacker].stockpileBeforeDef;
            gDisableStructs[gBattlerAttacker].stockpileSpDef += gBattleMons[gBattlerAttacker].statStages[ESTADISTICA_DEFENSA_ESPECIAL] - gDisableStructs[gBattlerAttacker].stockpileBeforeSpDef;
        }
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_stockpiletobasedamage(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;
    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = failInstr;
    }
    else
    {
        if (gMensajeBatalla != TEXTO_COMBATE_PROTECCION)
            gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;

        if (!(gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT && IsBattlerAlive(gBattlerTarget)))
        {
            gCombate->moveEffect2 = MOVE_EFFECT_STOCKPILE_WORE_OFF;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_stockpiletohpheal(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;

    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = failInstr;
        gMensajeBatalla = B_MSG_SWALLOW_FAILED;
    }
    else
    {
        if (gBattleMons[gBattlerAttacker].maxHP == gBattleMons[gBattlerAttacker].hp)
        {
            gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
            gBattlescriptCurrInstr = failInstr;
            gBattlerTarget = gBattlerAttacker;
            gMensajeBatalla = B_MSG_SWALLOW_FULL_HP;
        }
        else
        {
            if (gDisableStructs[gBattlerAttacker].stockpileCounter > 0)
            {
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / (1 << (3 - gDisableStructs[gBattlerAttacker].stockpileCounter));
                gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;
                gCombate->moveEffect2 = MOVE_EFFECT_STOCKPILE_WORE_OFF;
            }

            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;

            gBattlescriptCurrInstr = cmd->nextInstr;
            gBattlerTarget = gBattlerAttacker;
        }
    }
}

// Sign change for drained HP handled in GetDrainedBigRootHp
static void Cmd_setdrainedhp(void)
{
    CMD_ARGS();

    if (gMovimientos[gCurrentMove].argument != 0)
        gBattleMoveDamage = (gHpDealt * gMovimientos[gCurrentMove].argument / 100);
    else
        gBattleMoveDamage = (gHpDealt / 2);

    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static u16 ReverseStatChangeMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    // +1
    case MOVE_EFFECT_ATK_PLUS_1:
        return MOVE_EFFECT_ATK_MINUS_1;
    case MOVE_EFFECT_DEF_PLUS_1:
        return MOVE_EFFECT_DEF_MINUS_1;
    case MOVE_EFFECT_SPD_PLUS_1:
        return MOVE_EFFECT_SPD_MINUS_1;
    case MOVE_EFFECT_SP_ATK_PLUS_1:
        return MOVE_EFFECT_SP_ATK_MINUS_1;
    case MOVE_EFFECT_SP_DEF_PLUS_1:
        return MOVE_EFFECT_SP_DEF_MINUS_1;
    case MOVE_EFFECT_ACC_PLUS_1:
        return MOVE_EFFECT_ACC_MINUS_1;
    case MOVE_EFFECT_EVS_PLUS_1:
        return MOVE_EFFECT_EVS_MINUS_1;
    // -1
    case MOVE_EFFECT_ATK_MINUS_1:
        return MOVE_EFFECT_ATK_PLUS_1;
    case MOVE_EFFECT_DEF_MINUS_1:
        return MOVE_EFFECT_DEF_PLUS_1;
    case MOVE_EFFECT_SPD_MINUS_1:
        return MOVE_EFFECT_SPD_PLUS_1;
    case MOVE_EFFECT_SP_ATK_MINUS_1:
        return MOVE_EFFECT_SP_ATK_PLUS_1;
    case MOVE_EFFECT_SP_DEF_MINUS_1:
        return MOVE_EFFECT_SP_DEF_PLUS_1;
    case MOVE_EFFECT_ACC_MINUS_1:
        return MOVE_EFFECT_ACC_PLUS_1;
    case MOVE_EFFECT_EVS_MINUS_1:
    // +2
    case MOVE_EFFECT_ATK_PLUS_2:
        return MOVE_EFFECT_ATK_MINUS_2;
    case MOVE_EFFECT_DEF_PLUS_2:
        return MOVE_EFFECT_DEF_MINUS_2;
    case MOVE_EFFECT_SPD_PLUS_2:
        return MOVE_EFFECT_SPD_MINUS_2;
    case MOVE_EFFECT_SP_ATK_PLUS_2:
        return MOVE_EFFECT_SP_ATK_MINUS_2;
    case MOVE_EFFECT_SP_DEF_PLUS_2:
        return MOVE_EFFECT_SP_DEF_MINUS_2;
    case MOVE_EFFECT_ACC_PLUS_2:
        return MOVE_EFFECT_ACC_MINUS_2;
    case MOVE_EFFECT_EVS_PLUS_2:
        return MOVE_EFFECT_EVS_MINUS_2;
    // -2
    case MOVE_EFFECT_ATK_MINUS_2:
        return MOVE_EFFECT_ATK_PLUS_2;
    case MOVE_EFFECT_DEF_MINUS_2:
        return MOVE_EFFECT_DEF_PLUS_2;
    case MOVE_EFFECT_SPD_MINUS_2:
        return MOVE_EFFECT_SPD_PLUS_2;
    case MOVE_EFFECT_SP_ATK_MINUS_2:
        return MOVE_EFFECT_SP_ATK_PLUS_2;
    case MOVE_EFFECT_SP_DEF_MINUS_2:
        return MOVE_EFFECT_SP_DEF_PLUS_2;
    case MOVE_EFFECT_ACC_MINUS_2:
        return MOVE_EFFECT_ACC_PLUS_2;
    case MOVE_EFFECT_EVS_MINUS_2:
        return MOVE_EFFECT_EVS_PLUS_2;
    default:
        return 0;
    }
}

static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr)
{
    bool32 certain = FALSE;
    bool32 notProtectAffected = FALSE;
    u32 index, battler, battlerAbility, battlerHoldEffect;
    bool32 affectsUser = (flags & MOVE_EFFECT_AFFECTS_USER);
    bool32 mirrorArmored = (flags & STAT_CHANGE_MIRROR_ARMOR);

    if (affectsUser)
        battler = gBattlerAttacker;
    else
        battler = gBattlerTarget;

    battlerAbility = HabilidadCombatiente(battler);
    battlerHoldEffect = GetBattlerHoldEffect(battler, TRUE);

    gSpecialStatuses[battler].changedStatsBattlerId = gBattlerAttacker;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_MIRROR_ARMOR);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain = TRUE;
    flags &= ~MOVE_EFFECT_CERTAIN;

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~STAT_CHANGE_NOT_PROTECT_AFFECTED;

    if (battlerAbility == ABILITY_RESPONDON)
    {
        statValue ^= STAT_BUFF_NEGATIVE;
        gBattleScripting.statChanger ^= STAT_BUFF_NEGATIVE;
        RecuerdaHabilidadCombate(battler, battlerAbility);
        if (flags & STAT_CHANGE_UPDATE_MOVE_EFFECT)
        {
            flags &= ~STAT_CHANGE_UPDATE_MOVE_EFFECT;
            gBattleScripting.moveEffect = ReverseStatChangeMoveEffect(gBattleScripting.moveEffect);
        }
    }
    else if (battlerAbility == ABILITY_SIMPLE)
    {
        statValue = (SET_STAT_BUFF_VALUE(GET_STAT_BUFF_VALUE(statValue) * 2)) | ((statValue <= -1) ? STAT_BUFF_NEGATIVE : 0);
    }

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);

    if (statValue <= -1) // Stat decrease.
    {
        if (gSideTimers[GetBattlerSide(battler)].mistTimer && !certain && gCurrentMove != MOVE_CURSE && !(battler == gBattlerTarget && HabilidadCombatiente(gBattlerAttacker) == ABILITY_SIGILOSO))
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = battler;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gCurrentMove != MOVE_CURSE && notProtectAffected != TRUE && JumpIfMoveAffectedByProtect(gCurrentMove))
        {
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET || CanAbilityPreventStatLoss(battlerAbility)) && (!affectsUser || mirrorArmored) && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    gBattleScripting.battler = battler;
                    if (battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET)
                    {
                        gLastUsedItem = gBattleMons[battler].item;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_ItemNoStatLoss;
                        RecordItemEffectBattle(battler, HOLD_EFFECT_CLEAR_AMULET);
                    }
                    else
                    {
                        gBattlerAbility = battler;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                        gLastUsedAbility = battlerAbility;
                        RecuerdaHabilidad(battler, gLastUsedAbility);
                    }
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (battlerAbility == ABILITY_MIRROR_ARMOR && !affectsUser && !mirrorArmored && gBattlerAttacker != gBattlerTarget && battler == gBattlerTarget)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = battler;
                gBattlerAbility = battler;
                gBattlescriptCurrInstr = BattleScript_MirrorArmorReflect;
                RecuerdaHabilidad(battler, gBattleMons[battler].ability);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
            if (gBattleMons[battler].statStages[statId] == 1)
                statValue = -1;
            else if (gBattleMons[battler].statStages[statId] == 2 && statValue < -2)
                statValue = -2;
            gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
            index = 1;
            if (statValue == -2)
            {
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = STRINGID_STATHARSHLY;
                gBattleTextBuff2[3] = STRINGID_STATHARSHLY >> 8;
                index = 4;
            }
            else if (statValue <= -3)
            {
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = STRINGID_SEVERELY & 0xFF;
                gBattleTextBuff2[3] = STRINGID_SEVERELY >> 8;
                index = 4;
            }
            gBattleTextBuff2[index++] = B_BUFF_STRING;
            gBattleTextBuff2[index++] = STRINGID_STATFELL;
            gBattleTextBuff2[index++] = STRINGID_STATFELL >> 8;
            gBattleTextBuff2[index] = B_BUFF_EOS;

            if (gBattleMons[battler].statStages[statId] == ESTADISTICA_MENOS_6)
            {
                gMensajeBatalla = B_MSG_STAT_WONT_DECREASE;
            }
            else
            {
                gProtectStructs[battler].statFell = TRUE;                                // Eject pack, lash out
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler); // B_MSG_ATTACKER_STAT_FELL or B_MSG_DEFENDER_STAT_FELL
            }
        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
        if (gBattleMons[battler].statStages[statId] == 11)
            statValue = 1;
        else if (gBattleMons[battler].statStages[statId] == 10 && statValue > 2)
            statValue = 2;
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        index = 1;
        if (statValue == 2)
        {
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
            gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
            index = 4;
        }
        else if (statValue >= 3)
        {
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = STRINGID_DRASTICALLY & 0xFF;
            gBattleTextBuff2[3] = STRINGID_DRASTICALLY >> 8;
            index = 4;
        }
        gBattleTextBuff2[index++] = B_BUFF_STRING;
        gBattleTextBuff2[index++] = STRINGID_STATROSE;
        gBattleTextBuff2[index++] = STRINGID_STATROSE >> 8;
        gBattleTextBuff2[index] = B_BUFF_EOS;

        if (gBattleMons[battler].statStages[statId] == ESTADISTICA_MAS_6)
        {
            gMensajeBatalla = B_MSG_STAT_WONT_INCREASE;
        }
        else
        {
            u32 statIncrease;
            if ((statValue + gBattleMons[battler].statStages[statId]) > ESTADISTICA_MAS_6)
                statIncrease = ESTADISTICA_MAS_6 - gBattleMons[battler].statStages[statId];
            else
                statIncrease = statValue;

            gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler);
            gProtectStructs[battler].statRaised = TRUE;
        }
    }

    gBattleMons[battler].statStages[statId] += statValue;
    if (gBattleMons[battler].statStages[statId] < ESTADISTICA_MENOS_6)
        gBattleMons[battler].statStages[statId] = ESTADISTICA_MENOS_6;
    if (gBattleMons[battler].statStages[statId] > ESTADISTICA_MAS_6)
        gBattleMons[battler].statStages[statId] = ESTADISTICA_MAS_6;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_INCREASE && flags & STAT_CHANGE_ALLOW_PTR)
        gMoveResultFlags |= MOVE_RESULT_MISSED;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_INCREASE && !(flags & STAT_CHANGE_ALLOW_PTR))
        return STAT_CHANGE_DIDNT_WORK;

    return STAT_CHANGE_WORKED;
}

static void Cmd_statbuffchange(void)
{
    CMD_ARGS(u16 flags, const u8 *failInstr);

    u16 flags = cmd->flags;
    const u8 *ptrBefore = gBattlescriptCurrInstr;
    const u8 *failInstr = cmd->failInstr;

    if (ChangeStatBuffs(GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger), GET_STAT_BUFF_ID(gBattleScripting.statChanger), flags, failInstr) == STAT_CHANGE_WORKED)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else if (gBattlescriptCurrInstr == ptrBefore) // Prevent infinite looping.
        gBattlescriptCurrInstr = failInstr;
}

bool32 TryResetBattlerStatChanges(u8 battler)
{
    u32 j;
    bool32 ret = FALSE;

    gDisableStructs[battler].stockpileDef = 0;
    gDisableStructs[battler].stockpileSpDef = 0;
    for (j = 0; j < NUMERO_ESTADISTICAS_BATALLA; j++)
    {
        if (gBattleMons[battler].statStages[j] != ESTADISTICA_NEUTRA)
            ret = TRUE; // returns TRUE if any stat was reset

        gBattleMons[battler].statStages[j] = ESTADISTICA_NEUTRA;
    }

    return ret;
}

// Haze
static void Cmd_normalisebuffs(void)
{
    CMD_ARGS();

    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        TryResetBattlerStatChanges(i);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_forcerandomswitch(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;
    s32 battler1PartyId = 0;
    s32 battler2PartyId = 0;

    s32 firstMonId;
    s32 lastMonId = 0; // + 1
    struct Pokemon *party = NULL;
    u8 validMons[PARTY_SIZE];
    s32 validMonsCount = 0;

    bool32 redCardForcedSwitch = FALSE;

    // Red card checks against wild pokemon. If we have reached here, the player has a mon to switch into
    // Red card swaps attacker with target to get the animation correct, so here we check attacker which is really the target. Thanks GF...
    if (gBattleScripting.switchCase == B_SWITCH_RED_CARD && !(EsCombateContraEntrenador(gCombate->tipoCombate)) && GetBattlerSide(gBattlerAttacker) == LADO_OPONENTE) // Check opponent's red card activating
    {
        gBattlescriptCurrInstr = BattleScript_RoarSuccessEndBattle;
        return;
    }

    // Swapping pokemon happens in:
    // trainer battles
    if ((EsCombateContraEntrenador(gCombate->tipoCombate)) || redCardForcedSwitch)
    {
        party = GetBattlerParty(gBattlerTarget);

        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[ALIADO(gBattlerTarget)];
        }
        else
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget]; // there is only one Pokémon out in single battles
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget];
        }

        for (i = firstMonId; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&party[i], MON_DATA_IS_EGG) && GetMonData(&party[i], MON_DATA_HP) != 0 && i != battler1PartyId && i != battler2PartyId)
            {
                validMons[validMonsCount++] = i;
            }
        }

        if (validMonsCount == 0)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            *(gCombate->battlerPartyIndexes + gBattlerTarget) = gBattlerPartyIndexes[gBattlerTarget];
            gBattlescriptCurrInstr = BattleScript_RoarSuccessSwitch;
            gCombate->forcedSwitch |= 1u << gBattlerTarget;
            *(gCombate->monToSwitchIntoId + gBattlerTarget) = validMons[NumeroAleatorioEnRango(0, validMonsCount - 1)];
            SwitchPartyOrder(gBattlerTarget);
        }
    }
    else
    {
        // In normal wild doubles, Roar will always fail if the user's level is less than the target's.
        if (gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
            gBattlescriptCurrInstr = BattleScript_RoarSuccessEndBattle;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_givepaydaymoney(void)
{
    CMD_ARGS();

    if (gPaydayMoney != 0)
    {
        u32 bonusMoney = gPaydayMoney * gCombate->moneyMultiplier;
        AddMoney(&gSaveBlockPtr->money, bonusMoney);

        PREPARE_HWORD_NUMBER_BUFFER(gBattleTextBuff1, 5, bonusMoney)

        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_PrintDiaDePagoMoneyString;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setlightscreen(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_LIGHTSCREEN)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_LIGHTSCREEN;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenTimer = TURNOS_EFECTOS * 2;
        else
            gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenTimer = TURNOS_EFECTOS;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenBattlerId = gBattlerAttacker;

        if (EsCombateContraEntrenador(gCombate->tipoCombate) && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
            gMensajeBatalla = B_MSG_SET_LIGHTSCREEN_DOUBLE;
        else
            gMensajeBatalla = B_MSG_SET_LIGHTSCREEN_SINGLE;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Super Fang
static void Cmd_damagetohalftargethp(void)
{
    CMD_ARGS();

    gBattleMoveDamage = CuantosPSLeQuedan(gBattlerTarget) / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryinfatuating(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (HabilidadCombatiente(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecuerdaHabilidad(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION || !AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMons[gBattlerTarget].status2 |= STATUS2_INFATUATED_WITH(gBattlerAttacker);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_updatestatusicon(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (HayAlgunCombatienteOcupado())
        return;

    if (cmd->battler == BS_ATTACKER_WITH_PARTNER)
    {
        battler = gBattlerAttacker;
        if (!(gAbsentBattlerFlags & (1u << battler)))
        {
            BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
            MarcaCombatienteOcupado(battler);
        }
        if ((EsCombateContraEntrenador(gCombate->tipoCombate)))
        {
            battler = ALIADO(gBattlerAttacker);
            if (!(gAbsentBattlerFlags & (1u << battler)))
            {
                BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
                MarcaCombatienteOcupado(battler);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        battler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
        MarcaCombatienteOcupado(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setmist(void)
{
    CMD_ARGS();

    if (gSideTimers[GetBattlerSide(gBattlerAttacker)].mistTimer)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gMensajeBatalla = B_MSG_MIST_FAILED;
    }
    else
    {
        gSideTimers[GetBattlerSide(gBattlerAttacker)].mistTimer = TURNOS_EFECTOS;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].mistBattlerId = gBattlerAttacker;
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_MIST;
        gMensajeBatalla = B_MSG_SET_MIST;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setsubstitute(void)
{
    CMD_ARGS();

    u32 hp = CuantosPSMaximos(gBattlerAttacker) / 4; // one bit value will only work for Pokémon which max hp can go to 1020(which is more than possible in games)

    if (hp == 0)
        hp = 1;

    if (gBattleMons[gBattlerAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gMensajeBatalla = B_MSG_SUBSTITUTE_FAILED;
    }
    else
    {
        gBattleMoveDamage = hp;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_SUBSTITUTE;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_WRAPPED;
        gDisableStructs[gBattlerAttacker].substituteHP = gBattleMoveDamage;
        gMensajeBatalla = B_MSG_SET_SUBSTITUTE;
        gHitMarker |= HITMARKER_IGNORE_SUBSTITUTE;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_disablelastusedattack(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;

    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }
    if (gDisableStructs[gBattlerTarget].disabledMove == MOVE_NONE && i != MAXIMO_MOVIMIENTOS_POKEMON && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].moves[i])

        gDisableStructs[gBattlerTarget].disabledMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].disableTimer = TURNOS_EFECTOS;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_trysetencore(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;

    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }

    if ((gMovimientos[gLastMoves[gBattlerTarget]].encoreBanned) || gLastMoves[gBattlerTarget] == MOVE_NONE)
    {
        i = MAXIMO_MOVIMIENTOS_POKEMON;
    }

    if (gDisableStructs[gBattlerTarget].encoredMove == MOVE_NONE && i != MAXIMO_MOVIMIENTOS_POKEMON && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].encoredMovePos = i;
        // Encore always lasts 3 turns, but we need to account for a scenario where Encore changes the move during the same turn.
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gDisableStructs[gBattlerTarget].encoreTimer = 4;
        else
            gDisableStructs[gBattlerTarget].encoreTimer = 3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setalwayshitflag(void)
{
    CMD_ARGS();

    gStatuses3[gBattlerTarget] &= ~STATUS3_ALWAYS_HITS;
    gStatuses3[gBattlerTarget] |= STATUS3_ALWAYS_HITS_TURN(2);
    gDisableStructs[gBattlerTarget].battlerWithSureHit = gBattlerAttacker;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setdestinybond(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DESTINY_BOND;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void TrySetDestinyBondToHappen(void)
{
    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gBattlerTarget);
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_DESTINY_BOND && sideAttacker != sideTarget)
    {
        gHitMarker |= HITMARKER_DESTINYBOND;
    }
}

static void Cmd_trysetdestinybondtohappen(void)
{
    CMD_ARGS();

    TrySetDestinyBondToHappen();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_settailwind(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 side = GetBattlerSide(gBattlerAttacker);

    if (!(gSideStatuses[side] & SIDE_STATUS_TAILWIND))
    {
        gSideStatuses[side] |= SIDE_STATUS_TAILWIND;
        gSideTimers[side].tailwindBattlerId = gBattlerAttacker;
        gSideTimers[side].tailwindTimer = TURNOS_EFECTOS;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_healpartystatus(void)
{
    CMD_ARGS();

    u32 zero = 0;
    u32 partner = ALIADO(gBattlerAttacker);
    u8 toHeal = 0;

    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon *party = GetBattlerParty(gBattlerAttacker);
        s32 i;

        gMensajeBatalla = B_MSG_BELL;

        if (HabilidadCombatiente(gBattlerAttacker) != ABILITY_SOUNDPROOF || B_HEAL_BELL_SOUNDPROOF == GEN_5 || B_HEAL_BELL_SOUNDPROOF >= GEN_8)
        {
            gBattleMons[gBattlerAttacker].status1 = 0;
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
        }
        else
        {
            RecuerdaHabilidad(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= B_MSG_BELL_SOUNDPROOF_ATTACKER;
        }

        gBattleScripting.battler = partner;

        if (IsBattlerAlive(partner))
        {
            if (HabilidadCombatiente(partner) != ABILITY_SOUNDPROOF || B_HEAL_BELL_SOUNDPROOF == GEN_5)
            {
                gBattleMons[partner].status1 = 0;
                gBattleMons[partner].status2 &= ~STATUS2_NIGHTMARE;
            }
            else
            {
                RecuerdaHabilidad(partner, gBattleMons[partner].ability);
                gBattleCommunication[MULTISTRING_CHOOSER] |= B_MSG_BELL_SOUNDPROOF_PARTNER;
            }
        }

        // Because the above MULTISTRING_CHOOSER are ORd, if both are set then it will be B_MSG_BELL_BOTH_SOUNDPROOF

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
            u8 abilityNum = GetMonData(&party[i], MON_DATA_ABILITY_NUM);

            if (species != SPECIES_NONE && species != SPECIES_EGG)
            {
                u16 ability;
                bool32 isAttacker = gBattlerPartyIndexes[gBattlerAttacker] == i;
                bool32 isDoublesPartner = gBattlerPartyIndexes[partner] == i && IsBattlerAlive(partner);

                if (B_HEAL_BELL_SOUNDPROOF == GEN_5 || (isAttacker && B_HEAL_BELL_SOUNDPROOF >= GEN_8))
                    ability = ABILITY_NONE;
                else if (B_HEAL_BELL_SOUNDPROOF > GEN_5 && !isAttacker && !isDoublesPartner)
                    ability = ABILITY_NONE;
                else if (isAttacker)
                    ability = HabilidadCombatiente(gBattlerAttacker);
                else if (isDoublesPartner)
                    ability = HabilidadCombatiente(partner);
                else
                {
                    ability = GetAbilityBySpecies(species, abilityNum);
                }

                if (ability != ABILITY_SOUNDPROOF)
                    toHeal |= (1 << i);
            }
        }
    }
    else // Aromatherapy
    {
        gMensajeBatalla = B_MSG_SOOTHING_AROMA;
        toHeal = (1 << PARTY_SIZE) - 1;

        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;

        if (EsCombateContraEntrenador(gCombate->tipoCombate) && !(gAbsentBattlerFlags & (1u << partner)))
        {
            gBattleMons[partner].status1 = 0;
            gBattleMons[partner].status2 &= ~STATUS2_NIGHTMARE;
        }
    }

    if (toHeal)
    {
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, toHeal, sizeof(zero), &zero);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_cursetarget(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_CURSED;
        gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_trysetspikes(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = OPONENTE(GetBattlerSide(gBattlerAttacker));

    if (gSideTimers[targetSide].spikesAmount == 3)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_SPIKES;
        gSideTimers[targetSide].spikesAmount++;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setforesight(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerTarget].status2 |= STATUS2_FORESIGHT;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetperishsong(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;
    s32 notAffectedCount = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gStatuses3[i] & STATUS3_PERISH_SONG || HabilidadCombatiente(i) == ABILITY_SOUNDPROOF || BlocksPrankster(gCurrentMove, gBattlerAttacker, i, TRUE))
        {
            notAffectedCount++;
        }
        else
        {
            gStatuses3[i] |= STATUS3_PERISH_SONG;
            gDisableStructs[i].perishSongTimer = 3;
        }
    }

    if (notAffectedCount == gBattlersCount)
        gBattlescriptCurrInstr = cmd->failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlerollout(void)
{
    CMD_ARGS();

    if (!MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)) // First hit.
        {
            gDisableStructs[gBattlerAttacker].rolloutTimer = 5;
            gDisableStructs[gBattlerAttacker].rolloutTimerStartValue = 5;
            gBattleMons[gBattlerAttacker].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gBattlerAttacker] = gCurrentMove;
        }
        if (--gDisableStructs[gBattlerAttacker].rolloutTimer == 0) // Last hit.
        {
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_MULTIPLETURNS;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifconfusedandstatmaxed(void)
{
    CMD_ARGS(u8 stat, const u8 *jumpInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CONFUSION && !CompareStat(gBattlerTarget, cmd->stat, ESTADISTICA_MAS_6, COMPARACION_MENOR))
        gBattlescriptCurrInstr = cmd->jumpInstr; // Fails if we're confused AND stat cannot be raised
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlefurycutter(void)
{
    CMD_ARGS();

    if (!MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gDisableStructs[gBattlerAttacker].furyCutterCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        u32 max;

        if (B_UPDATED_MOVE_DATA >= GEN_6)
            max = 3;
        else if (B_UPDATED_MOVE_DATA == GEN_5)
            max = 4;
        else
            max = 5;

        if (gDisableStructs[gBattlerAttacker].furyCutterCounter < max && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_2ND_HIT) // Don't increment counter on second hit
            gDisableStructs[gBattlerAttacker].furyCutterCounter++;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setembargo(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & STATUS3_EMBARGO)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_EMBARGO;
        gDisableStructs[gBattlerTarget].embargoTimer = TURNOS_EFECTOS;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_presentdamagecalculation(void)
{
    CMD_ARGS();

    u32 rand = Random() & 0xFF;

    /* Don't reroll present effect/power for the second hit of Parental Bond.
     * Not sure if this is the correct behaviour, but bulbapedia states
     * that if present heals the foe, it doesn't strike twice, and if it deals
     * damage, the second strike will always deal damage too. This is a simple way
     * to replicate that effect.
     */
    if (gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_2ND_HIT)
    {
        if (rand < 102)
        {
            gCombate->presentBasePower = 40;
        }
        else if (rand < 178)
        {
            gCombate->presentBasePower = 80;
        }
        else if (rand < 204)
        {
            gCombate->presentBasePower = 120;
        }
        else
        {
            gBattleMoveDamage = CuantosPSMaximos(gBattlerTarget) / 4;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;
            gCombate->presentBasePower = 0;
        }
    }

    if (gCombate->presentBasePower)
    {
        gBattlescriptCurrInstr = BattleScript_HitFromCritCalc;
    }
    else if (gBattleMons[gBattlerTarget].maxHP == gBattleMons[gBattlerTarget].hp)
    {
        gBattlescriptCurrInstr = BattleScript_AlreadyAtFullHp;
    }
    else
    {
        gMoveResultFlags &= ~MOVE_RESULT_DOESNT_AFFECT_FOE;
        gBattlescriptCurrInstr = BattleScript_PresentHealTarget;
    }
}

static void Cmd_setsafeguard(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_SAFEGUARD)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gMensajeBatalla = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].safeguardTimer = TURNOS_EFECTOS;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].safeguardBattlerId = gBattlerAttacker;
        gMensajeBatalla = B_MSG_SET_SAFEGUARD;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_magnitudedamagecalculation(void)
{
    CMD_ARGS();

    u32 magnitude = Random() % 100;

    if (magnitude < 5)
    {
        gCombate->magnitudeBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gCombate->magnitudeBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gCombate->magnitudeBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gCombate->magnitudeBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gCombate->magnitudeBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gCombate->magnitudeBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gCombate->magnitudeBasePower = 150;
        magnitude = 10;
    }

    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude)

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker)
            continue;
        if (!(gAbsentBattlerFlags & (1u << gBattlerTarget))) // A valid target was found.
            break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnopursuitswitchdmg(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (gCombate->contadorMultigolpes == 1)
    {
        if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
            gBattlerTarget = OPONENTE_IZQUIERDA;
        else
            gBattlerTarget = JUGADOR_IZQUIERDA;
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
            gBattlerTarget = OPONENTE_DERECHA;
        else
            gBattlerTarget = JUGADOR_DERECHA;
    }

    if (gAccionElegida[gBattlerTarget] == B_ACTION_USE_MOVE
     && gBattlerAttacker == *(gCombate->moveTarget + gBattlerTarget)
     && !(gBattleMons[gBattlerTarget].status1 & (STATUS1_SLEEP | STATUS1_CONGELACION))
     && gBattleMons[gBattlerAttacker].hp && gMovimientos[gMovimientoElegido[gBattlerTarget]].effect == EFFECT_PURSUIT)
    {
        s32 i;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerTarget)
                gActionsByTurnOrder[i] = B_ACTION_TRY_FINISH;
        }

        gCurrentMove = gChosenMove = gMovimientoElegido[gBattlerTarget];
        gCurrMovePos = gChosenMovePos = *(gCombate->chosenMovePositions + gBattlerTarget);
        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleScripting.animTurn = 1;
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

// Belly Drum, Fillet Away
static void Cmd_halvehp(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 halfHp = CuantosPSMaximos(gBattlerAttacker) / 2;

    if (!(CuantosPSMaximos(gBattlerAttacker) / 2))
        halfHp = 1;

    if (gBattleMons[gBattlerAttacker].hp > halfHp)
    {
        gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Psych Up
static void Cmd_copyfoestats(void)
{
    CMD_ARGS();

    s32 i;

    for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
    {
        gBattleMons[gBattlerAttacker].statStages[i] = gBattleMons[gBattlerTarget].statStages[i];
    }
}

static void Cmd_girorapidofree(void)
{
    CMD_ARGS();

    u8 atkSide = GetBattlerSide(gBattlerAttacker);

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_WRAPPED)
    {
        gBattleScripting.battler = gBattlerTarget;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_WRAPPED;
        gBattlerTarget = *(gCombate->wrappedBy + gBattlerAttacker);
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gCombate->wrappedMove[gBattlerAttacker]);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_WrapFree;
    }
    else if (gStatuses3[gBattlerAttacker] & STATUS3_LEECHSEED)
    {
        gStatuses3[gBattlerAttacker] &= ~STATUS3_LEECHSEED;
        gStatuses3[gBattlerAttacker] &= ~STATUS3_LEECHSEED_BATTLER;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LeechSeedFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_SPIKES)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_SPIKES;
        gSideTimers[atkSide].spikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_TOXIC_SPIKES)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_TOXIC_SPIKES;
        gSideTimers[atkSide].toxicSpikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_ToxicSpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STICKY_WEB)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_STICKY_WEB;
        gSideTimers[atkSide].stickyWebAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_STEALTH_ROCK;
        gSideTimers[atkSide].stealthRockAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StealthRockFree;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setdefensecurlbit(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DEFENSE_CURL;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_RecuperaSaludSegunClima(void)
{
    CMD_ARGS(const u8 *failInstr);

    enum ClimasCombate climaCombate = ObtenClimaCombate();

    gBattlerTarget = gBattlerAttacker;
    if (gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP)
    {
        if (gCurrentMove == MOVE_SHORE_UP)
        {
            if (EsClimaCombateArena(climaCombate))
                gBattleMoveDamage = 20 * CuantosPSMaximos(gBattlerAttacker) / 30;
            else
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 2;
        }
        else
        {
            if (!(gBattleWeather & B_WEATHER_ANY) || !ClimaTieneEfecto())
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 2;
            else if (EsClimaCombateSol(climaCombate))
                gBattleMoveDamage = 20 * CuantosPSMaximos(gBattlerAttacker) / 30;
            else // not sunny weather
                gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 4;
        }

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setstickyweb(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);

    if (gSideStatuses[targetSide] & SIDE_STATUS_STICKY_WEB)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STICKY_WEB;
        gSideTimers[targetSide].stickyWebBattlerId = gBattlerAttacker;                   // For Mirror Armor
        gSideTimers[targetSide].stickyWebBattlerSide = GetBattlerSide(gBattlerAttacker); // For Court Change/Defiant - set this to the user's side
        gSideTimers[targetSide].stickyWebAmount = 1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_selectfirstvalidtarget(void)
{
    CMD_ARGS();

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove) & MOVE_TARGET_USER))
            continue;
        if (IsBattlerAlive(gBattlerTarget))
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setsemiinvulnerablebit(void)
{
    CMD_ARGS(bool8 clear);

    if (gBattleMoveEffects[gMovimientos[gCurrentMove].effect].semiInvulnerableEffect == TRUE)
    {
        u32 semiInvulnerableEffect = UNCOMPRESS_BITS(HIHALF(gMovimientos[gCurrentMove].argument));
        if (cmd->clear)
            gStatuses3[gBattlerAttacker] &= ~semiInvulnerableEffect;
        else
            gStatuses3[gBattlerAttacker] |= semiInvulnerableEffect;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static bool32 CheckIfCanFireTwoTurnMoveNow(u8 battler, bool8 checkChargeTurnEffects)
{
    // Semi-invulnerable moves cannot skip their charge turn (except with Power Herb)
    if (gBattleMoveEffects[gMovimientos[gCurrentMove].effect].semiInvulnerableEffect == TRUE)
        return FALSE;

    // If this move has charge turn effects, it must charge, activate them, then try to fire
    if (checkChargeTurnEffects && MoveHasChargeTurnAdditionalEffect(gCurrentMove))
        return FALSE;

    // Certain two-turn moves may fire on the first turn in the right weather (Solar Beam, Electro Shot)
    // By default, all two-turn moves have the option of adding weather to their argument
    if (ClimaMovimientoCoincide(HIHALF(gMovimientos[gCurrentMove].argument)))
        return TRUE;

    return FALSE;
}

static void Cmd_tryfiretwoturnmovenowbyeffect(void)
{
    CMD_ARGS(u8 battler, bool8 checkChargeTurnEffects, const u8 *jumpInstr);

    if (CheckIfCanFireTwoTurnMoveNow(cmd->battler, cmd->checkChargeTurnEffects) == TRUE)
    {
        gBattleScripting.animTurn = 1;
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setminimize(void)
{
    CMD_ARGS();

    gStatuses3[gBattlerAttacker] |= STATUS3_MINIMIZED;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Follow Me
static void Cmd_setforcedtarget(void)
{
    CMD_ARGS();

    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTarget = gBattlerTarget;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmePowder = gMovimientos[gCurrentMove].powderMove;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setcharge(void)
{
    CMD_ARGS(u8 battler);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    gStatuses3[battler] |= STATUS3_CHARGED_UP;
    if (B_CHARGE < GEN_9)
        gDisableStructs[battler].chargeTimer = 2;
    else
        gDisableStructs[battler].chargeTimer = 0;
    gBattlescriptCurrInstr++;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Refresh
static void Cmd_cureifburnedparalysedorpoisoned(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerAttacker].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_CONGELACION))
    {
        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattlescriptCurrInstr = cmd->nextInstr;
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].status1), &gBattleMons[gBattlerAttacker].status1);
        MarcaCombatienteOcupado(gBattlerAttacker);
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_settorment(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TORMENT)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_TORMENT;
        gDisableStructs[gBattlerTarget].tormentTimer = PERMANENT_TORMENT; // permanent
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifnodamage(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (HaSidoDaniado(gBattlerAttacker))
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->jumpInstr;
}

static void Cmd_settaunt(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (B_OBLIVIOUS_TAUNT >= GEN_6 && HabilidadCombatiente(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecuerdaHabilidad(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
    {
        gDisableStructs[gBattlerTarget].tauntTimer = TURNOS_EFECTOS; // Revisar que, efectivamente, son 5 turnos EN CUALQUIER CIRCUNSTANCIA
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Trick
static void Cmd_tryswapitems(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gBattlerTarget);

    if ((gBattleMons[gBattlerAttacker].item == ITEM_NONE && gBattleMons[gBattlerTarget].item == ITEM_NONE))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    // check if ability prevents swapping
    else if (HabilidadCombatiente(gBattlerTarget) == ABILITY_STICKY_HOLD || HabilidadCombatiente(gBattlerTarget) == ABILITY_TERRITORIAL)
    {
        gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
        gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
        RecuerdaHabilidad(gBattlerTarget, gLastUsedAbility);
    }
    // took a while, but all checks passed and items can be safely swapped
    else
    {
        u16 oldItemAtk, *newItemAtk;

        newItemAtk = &gCombate->changedItems[gBattlerAttacker];
        oldItemAtk = gBattleMons[gBattlerAttacker].item;
        *newItemAtk = gBattleMons[gBattlerTarget].item;

        gBattleMons[gBattlerAttacker].item = ITEM_NONE;
        gBattleMons[gBattlerTarget].item = oldItemAtk;

        RecordItemEffectBattle(gBattlerAttacker, 0);
        RecordItemEffectBattle(gBattlerTarget, ItemId_GetHoldEffect(oldItemAtk));

        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(*newItemAtk), newItemAtk);
        MarcaCombatienteOcupado(gBattlerAttacker);

        BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[gBattlerTarget].item);
        MarcaCombatienteOcupado(gBattlerTarget);

        gCombate->choicedMove[gBattlerTarget] = MOVE_NONE;
        gCombate->choicedMove[gBattlerAttacker] = MOVE_NONE;

        gBattlescriptCurrInstr = cmd->nextInstr;

        PREPARE_ITEM_BUFFER(gBattleTextBuff1, *newItemAtk)
        PREPARE_ITEM_BUFFER(gBattleTextBuff2, oldItemAtk)

        if (oldItemAtk != ITEM_NONE && *newItemAtk != ITEM_NONE)
        {
            gMensajeBatalla = B_MSG_ITEM_SWAP_BOTH; // attacker's item -> <- target's item
        }
        else if (oldItemAtk == ITEM_NONE && *newItemAtk != ITEM_NONE)
        {
            if (HabilidadCombatiente(gBattlerAttacker) == ABILITY_UNBURDEN && gBattleResources->flags[gBattlerAttacker] & RESOURCE_FLAG_UNBURDEN)
                gBattleResources->flags[gBattlerAttacker] &= ~RESOURCE_FLAG_UNBURDEN;

            gMensajeBatalla = B_MSG_ITEM_SWAP_TAKEN; // nothing -> <- target's item
        }
        else
        {
            CheckSetUnburden(gBattlerAttacker);
            gMensajeBatalla = B_MSG_ITEM_SWAP_GIVEN; // attacker's item -> <- nothing
        }
    }
}

// Role Play
static void Cmd_trycopyability(void)
{
    CMD_ARGS(u8 battler, const u8 *failInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u16 defAbility = gBattleMons[gBattlerTarget].ability;

    gBattleScripting.abilityPopupOverwrite = gBattleMons[battler].ability;
    gBattleMons[battler].ability = gCombate->overwrittenAbilities[battler] = defAbility;
    gLastUsedAbility = defAbility;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_settoxicspikes(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideTimers[targetSide].toxicSpikesAmount >= 2)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideTimers[targetSide].toxicSpikesAmount++;
        gSideStatuses[targetSide] |= SIDE_STATUS_TOXIC_SPIKES;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setgastroacid(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].ability == ABILITY_NEUTRALIZING_GAS)
        gSpecialStatuses[gBattlerTarget].neutralizingGasRemoved = TRUE;

    gStatuses3[gBattlerTarget] |= STATUS3_GASTRO_ACID;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setdamagetohealthdifference(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (CuantosPSLeQuedan(gBattlerTarget) <= gBattleMons[gBattlerAttacker].hp)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMoveDamage = CuantosPSLeQuedan(gBattlerTarget) - gBattleMons[gBattlerAttacker].hp;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_PonEspacioRaro(void)
{
    CMD_ARGS();

    if (EstaEspacioRaroPuesto())
    {
        gCombate->turnosEspacioRaro = 0;
    }
    else
    {
        gCombate->turnosEspacioRaro = TURNOS_EFECTOS;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryimprison(void)
{
    CMD_ARGS(const u8 *failInstr);

    if ((gStatuses3[gBattlerAttacker] & STATUS3_IMPRISONED_OTHERS))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (B_IMPRISON >= GEN_5)
    {
        gStatuses3[gBattlerAttacker] |= STATUS3_IMPRISONED_OTHERS;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        u8 battler, sideAttacker;

        sideAttacker = GetBattlerSide(gBattlerAttacker);
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (sideAttacker != GetBattlerSide(battler))
            {
                s32 attackerMoveId;
                for (attackerMoveId = 0; attackerMoveId < MAXIMO_MOVIMIENTOS_POKEMON; attackerMoveId++)
                {
                    s32 i;
                    for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
                    {
                        if (gBattleMons[gBattlerAttacker].moves[attackerMoveId] == gBattleMons[battler].moves[i] && gBattleMons[gBattlerAttacker].moves[attackerMoveId] != MOVE_NONE)
                            break;
                    }
                    if (i != MAXIMO_MOVIMIENTOS_POKEMON)
                        break;
                }
                if (attackerMoveId != MAXIMO_MOVIMIENTOS_POKEMON)
                {
                    gStatuses3[gBattlerAttacker] |= STATUS3_IMPRISONED_OTHERS;
                    gBattlescriptCurrInstr = cmd->nextInstr;
                    break;
                }
            }
        }
        if (battler == gBattlersCount) // In Generation 3 games, Imprison fails if the user doesn't share any moves with any of the foes.
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setstealthrock(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideStatuses[targetSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STEALTH_ROCK;
        gSideTimers[targetSide].stealthRockAmount = 1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setuserstatus3(void)
{
    CMD_ARGS(u32 flags, const u8 *failInstr);

    u32 flags = cmd->flags;

    if (gStatuses3[gBattlerAttacker] & flags)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerAttacker] |= flags;
        if (flags & STATUS3_MAGNET_RISE)
            gDisableStructs[gBattlerAttacker].magnetRiseTimer = 5;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_switchoutabilities(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[battler].ability == ABILITY_NEUTRALIZING_GAS)
    {
        gBattleMons[battler].ability = ABILITY_NONE;
        BattleScriptPush(gBattlescriptCurrInstr);
        gBattlescriptCurrInstr = BattleScript_NeutralizingGasExits;
    }
    else
    {
        switch (HabilidadCombatiente(battler))
        {
        case ABILITY_NATURAL_CURE:
            gBattleMons[battler].status1 = 0;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE,
                                         1u << *(gCombate->battlerPartyIndexes + battler),
                                         sizeof(gBattleMons[battler].status1),
                                         &gBattleMons[battler].status1);
            MarcaCombatienteOcupado(battler);
            break;
        case ABILITY_REGENERATOR:
            gBattleMoveDamage = CuantosPSMaximos(gBattlerAttacker) / 3;
            gBattleMoveDamage += gBattleMons[battler].hp;
            if (gBattleMoveDamage > gBattleMons[battler].maxHP)
                gBattleMoveDamage = gBattleMons[battler].maxHP;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HP_BATTLE,
                                         1u << *(gCombate->battlerPartyIndexes + battler),
                                         sizeof(gBattleMoveDamage),
                                         &gBattleMoveDamage);
            MarcaCombatienteOcupado(battler);
            break;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifhasnohp(void)
{
    CMD_ARGS(u8 battler, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (!IsBattlerAlive(battler))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnotcurrentmoveargtype(void)
{
    CMD_ARGS(u8 battler, const u8 *failInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    const u8 *failInstr = cmd->failInstr;

    if (!EsTipo(battler, gMovimientos[gCurrentMove].argument))
        gBattlescriptCurrInstr = failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

bool32 DoesSubstituteBlockMove(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (!(gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE))
        return FALSE;
    else if (gMovimientos[move].ignoresSubstitute)
        return FALSE;
    else if (HabilidadCombatiente(battlerAtk) == ABILITY_SIGILOSO)
        return FALSE;
    else
        return TRUE;
}

static void Cmd_jumpifsubstituteblocks(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryrecycleitem(void)
{
    CMD_ARGS(const u8 *failInstr);

    u16 *usedHeldItem;

    usedHeldItem = &gCombate->usedHeldItems[gBattlerPartyIndexes[gBattlerAttacker]][GetBattlerSide(gBattlerAttacker)];
    if (*usedHeldItem != ITEM_NONE && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = ITEM_NONE;
        gBattleMons[gBattlerAttacker].item = gLastUsedItem;

        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].item), &gBattleMons[gBattlerAttacker].item);
        MarcaCombatienteOcupado(gBattlerAttacker);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_EliminaPantallas(void)
{
    CMD_ARGS();

    u32 lado = GetBattlerSide(gBattlerTarget);

    if (EsMovimientoEfectivo(gCombate->resultadoMovimiento) && (gSideTimers[lado].reflectTimer || gSideTimers[lado].lightscreenTimer || gSideTimers[lado].auroraVeilTimer))
    {
        gSideStatuses[lado] &= ~SIDE_STATUS_REFLECT;
        gSideStatuses[lado] &= ~SIDE_STATUS_LIGHTSCREEN;
        gSideStatuses[lado] &= ~SIDE_STATUS_AURORA_VEIL;
        gSideTimers[lado].reflectTimer = 0;
        gSideTimers[lado].lightscreenTimer = 0;
        gSideTimers[lado].auroraVeilTimer = 0;
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 1;
    }
    else
    {
        gBattleScripting.animTurn = 0;
        gBattleScripting.animTargetsHit = 0;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

u8 GetCatchingBattler(void)
{
    if (IsBattlerAlive(OPONENTE_IZQUIERDA))
        return OPONENTE_IZQUIERDA;
    else
        return OPONENTE_DERECHA;
}

u8 CalculateShakes(u32 odds)
{
    u8 shakes = 0;
    u8 maxShakes = BALL_3_SHAKES_SUCCESS;

    if (gLastUsedItem == ITEM_MASTER_BALL)
    {
        shakes = maxShakes;
    }
    else
    {
        if (odds < 1)
            odds = 1;
        if (odds > 255)
            odds = 255; // Limita a 255

        u8 probabilityScale = (255 - odds) * maxShakes / 255;

        for (shakes = 0; shakes < maxShakes && (Random() & 0xFF) < probabilityScale; shakes++)
            ;
    }

    return shakes;
}

static void Cmd_handleballthrow(void)
{
    CMD_ARGS();

    u32 odds;
    u8 catchRate = gSpeciesInfo[gBattleMons[gBattlerTarget].species].catchRate;
    u16 ballMultiplier = 100;

    if (HayAlgunCombatienteOcupado())
        return;

    gBattlerTarget = GetCatchingBattler();

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_TRAINER_BLOCK);
        MarcaCombatienteOcupado(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else
    {
        gLastThrownBall = gLastUsedItem;
        gBallToDisplay = gLastThrownBall;

        u8 currentHP = gBattleMons[gBattlerTarget].hp;
        u8 maxHP = gBattleMons[gBattlerTarget].maxHP;
        u8 hpLossMultiplier;

        if (currentHP >= 80)
            hpLossMultiplier = 1; // 100 - 80
        else if (currentHP >= 60)
            hpLossMultiplier = 2; // 79 - 60
        else if (currentHP >= 40)
            hpLossMultiplier = 3; // 59 - 40
        else if (currentHP >= 20)
            hpLossMultiplier = 4; // 39 - 20
        else
            hpLossMultiplier = 5; // < 20

        odds = (catchRate * ballMultiplier / 100) * (maxHP * 3 - currentHP * 2) / (3 * maxHP);

        odds = (odds * 255) / 100;
        if (odds > 255)
            odds = 255;

        odds = (odds * hpLossMultiplier) / 7;

        if (gBattleMons[gBattlerTarget].status1 & (STATUS1_ANY))
            odds = (odds * 2 > 255) ? 255 : odds * 2;

        if (odds >= 255) // Captura garantizada
        {
            BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_3_SHAKES_SUCCESS);
            MarcaCombatienteOcupado(gBattlerAttacker);
            TryBattleFormChange(gBattlerTarget, FORM_CHANGE_END_BATTLE);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);
            gBattleCommunication[MULTISTRING_CHOOSER] = (CalculatePlayerPartyCount() == PARTY_SIZE) ? 0 : 1;
            return;
        }

        if ((Random() & 0xFF) < odds) // Captura exitosa
        {
            BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_3_SHAKES_SUCCESS);
            MarcaCombatienteOcupado(gBattlerAttacker);
            TryBattleFormChange(gBattlerTarget, FORM_CHANGE_END_BATTLE);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);
        }
        else // No capturado
        {
            u8 shakes = CalculateShakes(odds);
            BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, shakes);
            MarcaCombatienteOcupado(gBattlerAttacker);
            gBattleCommunication[MULTISTRING_CHOOSER] = shakes;
            gBattlescriptCurrInstr = BattleScript_ShakeBallThrow;
        }
    }
}

static void Cmd_givecaughtmon(void)
{
    CMD_ARGS();

    u32 combatiente = GetCatchingBattler();
    u32 indiceEquipo = gBattlerPartyIndexes[combatiente];
    struct Pokemon *pokemon = &gEnemyParty[indiceEquipo];
    u32 objetoPerdido = gCombate->objetoPerdido[LADO_OPONENTE][indiceEquipo];

    if (objetoPerdido != ITEM_NONE && ItemId_GetPocket(objetoPerdido) != POCKET_BERRIES)
    {
        SetMonData(pokemon, MON_DATA_HELD_ITEM, &objetoPerdido);
    }

    if (GiveMonToPlayer(pokemon) != MON_GIVEN_TO_PARTY)
    {
        StringCopy(gVariableTexto1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
    }

    GetMonData(pokemon, MON_DATA_NICKNAME, gVariableTexto2);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetcaughtmondexflags(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES);

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_displaydexinfo(void)
{
    CMD_ARGS();

    u32 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES);
    u8 taskId;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (!gFundidoPaletas.activo)
        {
            struct Pokemon *mon = &gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]];
            FreeAllWindowBuffers();
            taskId = DisplayCaughtMonDexPage(species, GetMonData(mon, MON_DATA_IS_SHINY), GetMonData(mon, MON_DATA_PERSONALITY));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gFundidoPaletas.activo && gMain.callback2 == BattleMainCB2 && !gTasks[taskId].isActive)
        {
            SetVBlankCallback(VBlankCB_Battle);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        InitBattleBgsVideo();
        LoadBattleTextboxAndBackground();
        gBattle_BG3_X = 256;
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            BeginNormalPaletteFade(PALETTES_BG, 0, 16, 0, RGB_BLACK);
            ShowBg(0);
            ShowBg(3);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (!gFundidoPaletas.activo)
            gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    }
}

void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags)
{
    s32 destY, destX, bgId;
    u16 var = 0;

    for (destY = yStart; destY <= yEnd; destY++)
    {
        for (destX = xStart; destX <= xEnd; destX++)
        {
            if (destY == yStart)
            {
                if (destX == xStart)
                    var = 0x1022;
                else if (destX == xEnd)
                    var = 0x1024;
                else
                    var = 0x1023;
            }
            else if (destY == yEnd)
            {
                if (destX == xStart)
                    var = 0x1028;
                else if (destX == xEnd)
                    var = 0x102A;
                else
                    var = 0x1029;
            }
            else
            {
                if (destX == xStart)
                    var = 0x1025;
                else if (destX == xEnd)
                    var = 0x1027;
                else
                    var = 0x1026;
            }

            if (flags & WINDOW_CLEAR)
                var = 0;

            bgId = (flags & WINDOW_BG1) ? 1 : 0;
            CopyToBgTilemapBufferRect_ChangePalette(bgId, &var, destX, destY, 1, 1, 0x11);
        }
    }
}

void CreaCursorBatallaSiNo(void)
{
    u16 src[2];
    src[0] = 1;
    src[1] = 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 19, 9 + (2 * gPosicionCursorSiNo), 1, 2, 11);
    CopyBgTilemapBufferToVram(0);
}

void BattleDestroyYesNoCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 1016;
    src[1] = 1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 19, 9 + (2 * cursorPosition), 1, 2, 11);
    CopyBgTilemapBufferToVram(0);
}

static void Cmd_trygivecaughtmonnick(void)
{
    CMD_ARGS(const u8 *successInstr);

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleCommunication[MULTIUSE_STATE]++;
        gPosicionCursorSiNo = CURSOR_SI;
        CreaCursorBatallaSiNo();
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gPosicionCursorSiNo == CURSOR_NO)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_SI;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(DPAD_DOWN) && gPosicionCursorSiNo == CURSOR_SI)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gPosicionCursorSiNo);
            gPosicionCursorSiNo = CURSOR_NO;
            CreaCursorBatallaSiNo();
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gPosicionCursorSiNo == CURSOR_SI)
            {
                gBattleCommunication[MULTIUSE_STATE]++;
                EmpiezaFundidoPaletasRapido(FUNDIDO_A_NEGRO);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE]++;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gFundidoPaletas.activo)
        {
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_NICKNAME, gCombate->caughtMonNick);
            FreeAllWindowBuffers();

            DoNamingScreen(NAMING_SCREEN_CAUGHT_MON, gCombate->caughtMonNick,
                           GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_SPECIES),
                           GetMonGender(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]]),
                           GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_PERSONALITY),
                           BattleMainCB2,
                           GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_IS_SHINY));

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (gMain.callback2 == BattleMainCB2 && !gFundidoPaletas.activo)
        {
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_NICKNAME, gCombate->caughtMonNick);
            gBattlescriptCurrInstr = cmd->successInstr;
        }
        break;
    case 4:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->successInstr;
        break;
    }
}

static void Cmd_subattackerhpbydmg(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].hp -= gBattleMoveDamage;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_removeattackerstatus1(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status1 = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// CMD_ARGS is not needed for these functions as they end the script execution.
static void Cmd_finishaction(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
}

static void Cmd_finishturn(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
    gCurrentTurnActionNumber = gBattlersCount;
}

static void Cmd_trainerslideout(void)
{
    CMD_ARGS(u8 position);

    u32 battler = GetBattlerForBattleScript(cmd->position);
    BtlController_EmitTrainerSlideBack(battler, BUFFER_A);
    MarcaCombatienteOcupado(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static const u16 sTelekinesisBanList[] =
    {
        SPECIES_SANDYGAST,
        SPECIES_PALOSSAND,
};

bool32 IsTelekinesisBannedSpecies(u16 species)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sTelekinesisBanList); i++)
    {
        if (species == sTelekinesisBanList[i])
            return TRUE;
    }
    return FALSE;
}

static void Cmd_settelekinesis(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN) || IsTelekinesisBannedSpecies(gBattleMons[gBattlerTarget].species))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_TELEKINESIS;
        gDisableStructs[gBattlerTarget].telekinesisTimer = 3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_swapstatstages(void)
{
    CMD_ARGS(u8 stat);

    u8 stat = cmd->stat;
    s8 atkStatStage = gBattleMons[gBattlerAttacker].statStages[stat];
    s8 defStatStage = gBattleMons[gBattlerTarget].statStages[stat];

    gBattleMons[gBattlerAttacker].statStages[stat] = defStatStage;
    gBattleMons[gBattlerTarget].statStages[stat] = atkStatStage;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static u16 *GetBattlerStat(struct BattlePokemon *battler, u32 stat)
{
    switch (stat)
    {
    case ESTADISTICA_ATAQUE:
        return &battler->attack;
    case ESTADISTICA_DEFENSA:
        return &battler->defense;
    case ESTADISTICA_ATAQUE_ESPECIAL:
        return &battler->spAttack;
    case ESTADISTICA_DEFENSA_ESPECIAL:
        return &battler->spDefense;
    default:
        return NULL;
    }
}

static void Cmd_averagestats(void)
{
    CMD_ARGS(u8 stat);

    u16 *stat1 = GetBattlerStat(&gBattleMons[gBattlerAttacker], cmd->stat);
    u16 *stat2 = GetBattlerStat(&gBattleMons[gBattlerTarget], cmd->stat);
    u16 avg = (*stat1 + *stat2) / 2;
    *stat1 = *stat2 = avg;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifoppositegenders(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_callnative(void)
{
    CMD_ARGS(void (*func)(void));
    void (*func)(void) = cmd->func;
    func();
}

// Callnative Funcs

void SaveBattlerTarget(u32 battler)
{
    if (gCombate->savedTargetCount < ARRAY_COUNT(gCombate->savedBattlerTarget))
        gCombate->savedBattlerTarget[gCombate->savedTargetCount++] = battler;
}

void SaveBattlerAttacker(u32 battler)
{
    if (gCombate->savedAttackerCount < ARRAY_COUNT(gCombate->savedBattlerAttacker))
        gCombate->savedBattlerAttacker[gCombate->savedAttackerCount++] = battler;
}

void BS_SaveTarget(void)
{
    NATIVE_ARGS();
    SaveBattlerTarget(gBattlerTarget);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_RestoreTarget(void)
{
    NATIVE_ARGS();
    if (gCombate->savedTargetCount > 0)
    {
        gCombate->savedTargetCount--;
        gBattlerTarget = gCombate->savedBattlerTarget[gCombate->savedTargetCount];
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SaveAttacker(void)
{
    NATIVE_ARGS();
    SaveBattlerAttacker(gBattlerAttacker);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_RestoreAttacker(void)
{
    NATIVE_ARGS();
    if (gCombate->savedAttackerCount > 0)
    {
        gCombate->savedAttackerCount--;
        gBattlerAttacker = gCombate->savedBattlerAttacker[gCombate->savedAttackerCount];
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfMoreThanHalfHP(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[battler].hp > (gBattleMons[battler].maxHP + 1) / 2)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_DoStockpileStatChangesWearOff(void)
{
    NATIVE_ARGS(u8 battler, const u8 *statChangeInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gDisableStructs[battler].stockpileDef != 0)
    {
        SET_STATCHANGER(ESTADISTICA_DEFENSA, abs(gDisableStructs[battler].stockpileDef), TRUE);
        gDisableStructs[battler].stockpileDef = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = cmd->statChangeInstr;
    }
    else if (gDisableStructs[battler].stockpileSpDef)
    {
        SET_STATCHANGER(ESTADISTICA_DEFENSA_ESPECIAL, abs(gDisableStructs[battler].stockpileSpDef), TRUE);
        gDisableStructs[battler].stockpileSpDef = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = cmd->statChangeInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

bool32 IsMoveAffectedByParentalBond(u32 move, u32 battler)
{
    if (move != MOVE_NONE && move != MOVE_STRUGGLE && !gMovimientos[move].parentalBondBanned && gMovimientos[move].category != CATEGORIA_ESTADO && gMovimientos[move].strikeCount < 2 && gMovimientos[move].effect != EFFECT_MULTI_HIT)
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            switch (GetBattlerMoveTargetType(battler, move))
            {
            // Both foes are alive, spread move strikes once
            case MOVE_TARGET_BOTH:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerTarget) >= 2)
                    return FALSE;
                break;
            // Either both foes or one foe and its ally are alive; spread move strikes once
            case MOVE_TARGET_FOES_AND_ALLY:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, gBattlerAttacker) >= 2)
                    return FALSE;
                break;
            default:
                break;
            }
        }
        return TRUE;
    }
    return FALSE;
}

static bool8 IsFinalStrikeEffect(u32 moveEffect)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sFinalStrikeOnlyEffects); i++)
    {
        if (moveEffect == sFinalStrikeOnlyEffects[i])
            return TRUE;
    }
    return FALSE;
}

static bool8 CanAbilityPreventStatLoss(u16 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_CLEAR_BODY:
    case ABILITY_WHITE_SMOKE:
        return TRUE;
    }
    return FALSE;
}

void BS_CheckParentalBondCounter(void)
{
    NATIVE_ARGS(u8 counter, const u8 *jumpInstr);
    // Some effects should only happen on the first or second strike of Parental Bond,
    // so a way to check this in battle scripts is useful
    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == cmd->counter && IsBattlerAlive(gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfCantLoseItem(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u16 item = gBattleMons[battler].item;

    if (item == ITEM_NONE)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

u8 GetFirstFaintedPartyIndex(u8 battler)
{
    u32 i;
    u32 start = 0;
    u32 end = PARTY_SIZE;
    struct Pokemon *party = GetBattlerParty(battler);

    // Loop through to find fainted battler.
    for (i = start; i < end; ++i)
    {
        u32 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&party[i], MON_DATA_HP) == 0)
        {
            return i;
        }
    }

    // Returns PARTY_SIZE if none found.
    return PARTY_SIZE;
}

void ApplyExperienceMultipliers(s32 *expAmount, u8 expGetterMonId, u8 faintedBattler)
{
    u32 holdEffect = GetMonHoldEffect(&gPlayerParty[expGetterMonId]);

    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
        *expAmount = (*expAmount * 150) / 100;
    if (CheckBagHasItem(ITEM_EXP_CHARM, 1)) // is also for other exp boosting Powers if/when implemented
        *expAmount = (*expAmount * 150) / 100;

    // Note: There is an edge case where if a pokemon receives a large amount of exp, it wouldn't be properly calculated
    //       because of multiplying by scaling factor(the value would simply be larger than an u32 can hold). Hence u64 is needed.
    u64 value = *expAmount;
    u8 faintedLevel = gBattleMons[faintedBattler].level;
    u8 expGetterLevel = GetMonData(&gPlayerParty[expGetterMonId], MON_DATA_LEVEL);

    value *= sExperienceScalingFactors[(faintedLevel * 2) + 10];
    value /= sExperienceScalingFactors[faintedLevel + expGetterLevel + 10];

    *expAmount = value + 1;
}

void BS_ItemCureStatus(void)
{
    NATIVE_ARGS(const u8 *noStatusInstr);
    u32 battler = gBattlerAttacker;
    u32 side = GetBattlerSide(gBattlerAttacker);
    u32 previousStatus2 = 0;
    bool32 statusChanged = FALSE;
    struct Pokemon *party = GetSideParty(side);

    // Heal Status2 conditions if battler is active.
    if (gCombate->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
    {
        previousStatus2 = gBattleMons[battler].status2;
        gBattleMons[gBattlerAttacker].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
    }
    else if (EsCombateContraEntrenador(gCombate->tipoCombate) && gCombate->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[ALIADO(gBattlerAttacker)])
    {
        battler = ALIADO(gBattlerAttacker);
        previousStatus2 = gBattleMons[battler].status2;
        gBattleMons[battler].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
    }

    if (previousStatus2 != gBattleMons[battler].status2)
        statusChanged = TRUE;

    // Heal Status1 conditions.
    if (!HealStatusConditions(&party[gCombate->itemPartyIndex[gBattlerAttacker]], GetItemStatus1Mask(gLastUsedItem), battler))
    {
        statusChanged = TRUE;
        if (GetItemStatus1Mask(gLastUsedItem) & STATUS1_SLEEP)
            gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
    }

    if (statusChanged)
    {
        gBattleScripting.battler = battler;
        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gCombate->itemPartyIndex[gBattlerAttacker]], MON_DATA_SPECIES));
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->noStatusInstr;
    }
}

void BS_ItemIncreaseStat(void)
{
    NATIVE_ARGS();
    u16 statId = ItemId_GetEffect(gLastUsedItem)[1];
    u16 stages = ItemId_GetHoldEffectParam(gLastUsedItem);
    SET_STATCHANGER(statId, stages, FALSE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryRevertWeatherForm(void)
{
    NATIVE_ARGS();
    if (TryBattleFormChange(gBattlerTarget, FORM_CHANGE_BATTLE_WEATHER))
    {
        gBattleScripting.battler = gBattlerTarget;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_TargetFormChangeWithStringNoPopup;
        return;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfArgument(void)
{
    NATIVE_ARGS(u8 argument, const u8 *jumpInstr);

    if (gMovimientos[gCurrentMove].argument == cmd->argument)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryRelicSong(void)
{
    NATIVE_ARGS();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryHealPulse(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (IsBattlerAtMaxHp(gBattlerTarget))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        if (HabilidadCombatiente(gBattlerAttacker) == ABILITY_MEGADISPARADOR && gMovimientos[gCurrentMove].balistico)
            gBattleMoveDamage = -(CuantosPSMaximos(gBattlerTarget) * 75 / 100);
        else
            gBattleMoveDamage = -(CuantosPSMaximos(gBattlerTarget) / 2);

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = -1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryDefog(void)
{
    NATIVE_ARGS(u8 clear, const u8 *failInstr);

    if (cmd->clear)
    {
        if (TryDefogClear(gEffectBattler, TRUE))
            return;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        if (TryDefogClear(gBattlerAttacker, FALSE))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void ScriptCombate_PalmaRauda(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    u32 objetivo = gBattlerTarget;
    u32 movimiento = gMovimientoElegido[objetivo];
    enum PrioridadMovimientos prioridad = PrioridadMovimiento(movimiento);

    if (movimiento == MOVE_NONE || EsMovimientoEstado(movimiento))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }

    switch (prioridad)
    {
    case PRIORIDAD_MOVIMIENTO_ALTA:
        gBattlescriptCurrInstr = cmd->nextInstr;
        break;

    case PRIORIDAD_MOVIMIENTO_MUY_ALTA:
        if (GetBattlerSpeed(gBattlerAttacker) > GetBattlerSpeed(objetivo))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
        break;

    case PRIORIDAD_MOVIMIENTO_NEGATIVA:
    case PRIORIDAD_MOVIMIENTO_NORMAL:
    default:
        gBattlescriptCurrInstr = cmd->failInstr;
        break;
    }
}

void BS_RunStatChangeItems(void)
{
    NATIVE_ARGS(u8 battler);

    // Change instruction before calling ItemBattleEffects.
    gBattlescriptCurrInstr = cmd->nextInstr;
    ItemBattleEffects(ITEMEFFECT_STATS_CHANGED, GetBattlerForBattleScript(cmd->battler), FALSE);
}

void BS_DamageToQuarterTargetHP(void)
{
    NATIVE_ARGS();
    gBattleMoveDamage = (3 * CuantosPSLeQuedan(gBattlerTarget)) / 4;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfBlockedBySoundproof(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gMovimientos[gCurrentMove].soundMove && HabilidadCombatiente(battler) == ABILITY_SOUNDPROOF)
    {
        gLastUsedAbility = ABILITY_SOUNDPROOF;
        gBattlescriptCurrInstr = cmd->jumpInstr;
        RecuerdaHabilidad(battler, gLastUsedAbility);
        gBattlerAbility = battler;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryWindRiderPower(void)
{
    NATIVE_ARGS(u8 battler, const u8 *failInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u16 ability = HabilidadCombatiente(battler);
    if (GetBattlerSide(battler) == GetBattlerSide(gBattlerAttacker) && (ability == ABILITY_WIND_RIDER || ability == ABILITY_WIND_POWER))
    {
        gLastUsedAbility = ability;
        RecuerdaHabilidad(battler, gLastUsedAbility);
        gBattlerAbility = gBattleScripting.battler = battler;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void BS_TryHitSwitchTarget(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (IsBattlerAlive(gBattlerAttacker) && IsBattlerAlive(gBattlerTarget) && MovimientoEsEfectivo(gCombate->resultadoMovimiento) && HaSidoDaniado(gBattlerTarget) && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_1ST_HIT && HabilidadCombatiente(gBattlerTarget) != ABILITY_GUARD_DOG)
    {
        gBattleScripting.switchCase = B_SWITCH_HIT;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void BS_ActivateWeatherChangeAbilities(void)
{
    NATIVE_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    gBattlescriptCurrInstr = cmd->nextInstr;
    AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battler, 0, 0, 0);
}

void BS_HitSwitchTargetFailed(void)
{
    NATIVE_ARGS();
    gCombate->hitSwitchTargetFailed = TRUE;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ObjetivoEspejoMagico(void)
{
    NATIVE_ARGS();
    u32 side;
    gCombate->attackerBeforeBounce = gBattleScripting.battler = gBattlerAttacker;
    gBattlerAttacker = gBattlerTarget;
    side = OPONENTE(GetBattlerSide(gBattlerAttacker));
    if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove))
        gBattlerTarget = gSideTimers[side].followmeTarget;
    else
        gBattlerTarget = gCombate->attackerBeforeBounce;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_resultmessage(void) // Por terminar
{
    CMD_ARGS();

    u32 stringId = 0;

    if (HayAlgunCombatienteOcupado())
        return;

    gMostrarMensajeBatalla = TRUE;
    switch (gCombate->resultadoMovimiento)
    {
    case MOVIMIENTO_POCO_EFECTIVO:
        if (EsPrimerGolpe())
            stringId = STRINGID_NOTVERYEFFECTIVE;
        break;
    case MOVIMIENTO_NEUTRO:
    default:
        gMostrarMensajeBatalla = FALSE;
        break;
    case MOVIMIENTO_SUPER_EFECTIVO:
        if (EsPrimerGolpe())
        {
            if (GetBattlerSide(gBattlerTarget) != LADO_JUGADOR && gCombate->trainerSlideFirstSuperEffectiveHitMsgState != 2)
                gCombate->trainerSlideFirstSuperEffectiveHitMsgState = 1;

            stringId = STRINGID_SUPEREFFECTIVE;
        }
        break;
    }

    if (gMoveResultFlags & MOVE_RESULT_MISSED && (!(gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE) || gMensajeBatalla == TEXTO_COMBATE_LEVITACION || gMensajeBatalla == TEXTO_COMBATE_TELEPATA))
    {
        if (gMensajeBatalla == TEXTO_COMBATE_LEVITACION || gMensajeBatalla == TEXTO_COMBATE_TELEPATA)
            CreaMensajeHabilidad(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
        stringId = gMensajeBatalla;
        gMostrarMensajeBatalla = TRUE;
    }
    else
    {
        gMostrarMensajeBatalla = TRUE;
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            if (!gCombate->contadorMultigolpes) // Don't print effectiveness on each hit in a multi hit attack
            {
                // Signal for the trainer slide-in system.
                if (GetBattlerSide(gBattlerTarget) != LADO_JUGADOR && gCombate->trainerSlideFirstSuperEffectiveHitMsgState != 2)
                    gCombate->trainerSlideFirstSuperEffectiveHitMsgState = 1;

                stringId = STRINGID_SUPEREFFECTIVE;
            }
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            if (!gCombate->contadorMultigolpes)
                stringId = STRINGID_NOTVERYEFFECTIVE;
            break;
        case MOVE_RESULT_FAILED:
            stringId = STRINGID_BUTITFAILED;
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
            stringId = STRINGID_ITDOESNTAFFECT;
            break;
        default:
            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                stringId = STRINGID_ITDOESNTAFFECT;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FAILED)
            {
                stringId = STRINGID_BUTITFAILED;
            }
            else
            {
                gMostrarMensajeBatalla = FALSE;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced && MovimientoEsEfectivo(gCombate->resultadoMovimiento))
    {
        gCombate->ateBerry[gBattlerTarget & BIT_SIDE] |= 1u << gBattlerPartyIndexes[gBattlerTarget];
        gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

void IntentaRecuperarSaludTrasVencer(void)
{
    u32 combatiente = gBattlerAttacker; 
    u32 habilidad = HabilidadCombatiente(combatiente);

    if ((habilidad == ABILITY_CARNIVORO || habilidad == ABILITY_VAMPIRO) 
        && HasAttackerFaintedTarget() 
        && !NoAliveMonsForEitherParty())
    {

        s32 maxHP = CuantosPSMaximos(battler);
        gBattleMoveDamage = (maxHP / 3) + gBattleMons[battler].hp;

        if (gBattleMoveDamage > maxHP)
            gBattleMoveDamage = maxHP;

        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMoveDamage), &gBattleMoveDamage);
        MarcaCombatienteOcupado(battler);

        BattleScriptPushCursor(); 
        
        gLastUsedAbility = habilidad;
        gBattlescriptCurrInstr = ScriptCombate_HabilidadRecuperacionSaludTrasVencer;
    }
}

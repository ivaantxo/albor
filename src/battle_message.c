#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "menu.h"
#include "palette.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};


// todo: make some of those names less vague: attacker/target vs pkmn, etc.

const u8 *const gStatNamesTable[NUMERO_ESTADISTICAS_BATALLA] =
{
    gText_PS, gText_Ataque, gText_Defensa,
    gText_Velocidad, gText_AtEsp, gText_DefEsp,
    gText_Precision, gText_Evasion
};

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("was too spicy!"),
    [FLAVOR_DRY]    = COMPOUND_STRING("was too dry!"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("was too sweet!"),
    [FLAVOR_BITTER] = COMPOUND_STRING("was too bitter!"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("was too sour!")
};

const u8 gText_PkmnIsEvolving[] = _("What? {VAR_TEXTO_1} is evolving!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {VAR_TEXTO_1} evolved into {VAR_TEXTO_2}!{WAIT_SE}");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {VAR_TEXTO_1} stopped evolving!");
const u8 gText_EllipsisQuestionMark[] = _("……?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes No");

const u8 gText_Sleep[] = _("sleep");
const u8 gText_Poison[] = _("poison");
const u8 gText_Burn[] = _("burn");
const u8 gText_Paralysis[] = _("paralysis");
const u8 gText_Ice[] = _("ice");
const u8 gText_Confusion[] = _("confusion");
const u8 gText_Love[] = _("love");
const u8 gText_Are[] = _("are");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Draw");

static const struct BattleWindowText sTextOnWindowsInfo[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 6,
        .bgColor = 2,
        .shadowColor = 4,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_PP_1] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_2] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_3] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_4] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

// Los textos que siguen no se pueden escribir en línea en el script porque su
// contenido depende del estado en tiempo de ejecución.

void EscribeTextoIntroCombate(void)
{
    const u8 *texto;

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        texto = COMPOUND_STRING("¡{B_TRAINER_CLASS} {B_TRAINER_NAME} quiere luchar!");
    else if (EsCombateContraLegendario(gCombate->tipoCombate))
        texto = COMPOUND_STRING("¡El Legendario {B_OPPONENT_MON1_NAME}!");
    else
        texto = COMPOUND_STRING("¡Un {B_OPPONENT_MON1_NAME} salvaje!");

    EscribeTextoCombate(JUGADOR_IZQUIERDA, texto);
}

void EscribeTextoEnviarPokemon(u32 combatiente)
{
    const u8 *texto;

    if (GetBattlerSide(combatiente) == LADO_JUGADOR)
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[ALIADO(combatiente)]]))
            texto = COMPOUND_STRING("¡Vamos! ¡{B_PLAYER_MON1_NAME} y {B_PLAYER_MON2_NAME}!");
        else
            texto = COMPOUND_STRING("¡Vamos, {B_PLAYER_MON1_NAME}!");
    }
    else
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[ALIADO(combatiente)]]))
            texto = COMPOUND_STRING("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
        else
            texto = COMPOUND_STRING("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_OPPONENT_MON1_NAME}!");
    }

    EscribeTextoCombate(combatiente, texto);
}

void EscribeTextoDevolverPokemon(u32 combatiente)
{
    const u8 *texto;

    if (GetBattlerSide(combatiente) == LADO_JUGADOR)
    {
        if (gCombate->hpScale == 0)
            texto = COMPOUND_STRING("¡{B_BUFF1}, ya es suficiente! ¡Vuelve!");
        else if (gCombate->hpScale == 1 || EsCombateContraEntrenador(gCombate->tipoCombate))
            texto = COMPOUND_STRING("¡{B_BUFF1}, ven conmigo!");
        else if (gCombate->hpScale == 2)
            texto = COMPOUND_STRING("¡{B_BUFF1}, bien! ¡Cambio!");
        else
            texto = COMPOUND_STRING("¡Lo has hecho bien, {B_BUFF1}! ¡Descansa!");
    }
    else
    {
        texto = COMPOUND_STRING("{B_TRAINER_CLASS} {B_TRAINER_NAME} guardó a {B_BUFF1}!");
    }

    EscribeTextoCombate(combatiente, texto);
}

void EscribeTextoEntraPokemon(u32 combatiente)
{
    const u8 *texto;

    if (GetBattlerSide(combatiente) == LADO_JUGADOR)
    {
        if (gCombate->hpScale == 0 || EsCombateContraEntrenador(gCombate->tipoCombate))
            texto = COMPOUND_STRING("¡A luchar, {B_BUFF1}!");
        else if (gCombate->hpScale == 1)
            texto = COMPOUND_STRING("¡Hazlo, {B_BUFF1}!");
        else if (gCombate->hpScale == 2)
            texto = COMPOUND_STRING("¡A por ello, {B_BUFF1}!");
        else
            texto = COMPOUND_STRING("¡Tu rival está débil! ¡Tú puedes, {B_BUFF1}!");
    }
    else
    {
        texto = COMPOUND_STRING("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_BUFF1}!");
    }

    EscribeTextoCombate(combatiente, texto);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, COMPOUND_STRING("$$$$$$$"), min(ARRAY_COUNT(status), ARRAY_COUNT(COMPOUND_STRING("$$$$$$$"))));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][4]))
            return gStatusConditionStringsTable[i];
    }
    return NULL;
}

static void GetBattlerNick(u32 battler, u8 *dst)
{
    struct Pokemon *mon = GetPartyBattlerData(battler);

    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                          \
    GetBattlerNick(battler, text);                                    \
    toCpy = text;                                                     \
        while (*toCpy != EOS)                                         \
        {                                                             \
            dst[dstID] = *toCpy;                                      \
            dstID++;                                                  \
            toCpy++;                                                  \
        }                                                             \
    if (GetBattlerSide(battler) != LADO_JUGADOR)                     \
    {                                                                 \
        if (EsCombateContraEntrenador(gCombate->tipoCombate))               \
            toCpy = COMPOUND_STRING(" rival");                              \
        else                                                          \
            toCpy = COMPOUND_STRING(" salvaje");                             \
    }

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId)
{
    const u8 *toCpy = GetTrainerNameFromId(trainerId);

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 battler)
{
    const u8 *toCpy = NULL;

    switch (battler)
    {
    case OPONENTE_IZQUIERDA:
    case OPONENTE_DERECHA:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 battler)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR)
        return gSaveBlockPtr->nombreJugador;
    else
        return BattleStringGetOpponentName(battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u32 lastValidSkip = 0;
    u32 toCpyWidth = 0;
    u32 dstWidth = 0;
    // This buffer may hold either the name of a trainer, Pokémon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 fontId = FONT_NORMAL;
    s16 letterSpacing = 0;
    u32 lineNum = 1;

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;
        dstWidth = GetStringLineWidth(fontId, dst, letterSpacing, lineNum, dstSize);

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gVariableTexto1);
                    toCpy = gVariableTexto1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gVariableTexto2);
                    toCpy = gVariableTexto2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gVariableTexto3);
                    toCpy = gVariableTexto3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gVariableTexto1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gVariableTexto2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gVariableTexto3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(JUGADOR_IZQUIERDA, text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(OPONENTE_IZQUIERDA, text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(JUGADOR_DERECHA, text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(OPONENTE_DERECHA, text);
                toCpy = text;
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(ALIADO(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                toCpy = ObtenNombreMovimiento(gCurrentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                toCpy = ObtenNombreMovimiento(gChosenMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                CopyItemName(gLastUsedItem, text);
                toCpy = text;
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[gBattleMons[gBattleScripting.battler].ability].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[gBattleMons[gEffectBattler].ability].name;
                break;
            case B_TXT_TRAINER_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent);
                break;
            case B_TXT_TRAINER_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent);
                break;
            case B_TXT_PLAYER_NAME:
                toCpy = gSaveBlockPtr->nombreJugador;
                break;
            case B_TXT_TRAINER_LOSE_TEXT: // trainerA lose text
                toCpy = GetTrainerLoseText();
                break;
            case B_TXT_PC_CREATOR_NAME:
                toCpy = COMPOUND_STRING("PC de Bill.");
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Opposing");
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Opposing");
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Foe");
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Foe");
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Opposing");
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Ally");
                else
                    toCpy = COMPOUND_STRING("Opposing");
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = gSaveBlockPtr->nombreJugador;
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (gBattlerAttacker)
                {
                case JUGADOR_DERECHA:
                    break;
                case OPONENTE_IZQUIERDA:
                case OPONENTE_DERECHA:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("Tu");
                else
                    toCpy = COMPOUND_STRING("Rival");
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("tu");
                else
                    toCpy = COMPOUND_STRING("rival");
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy =COMPOUND_STRING("Tu");
                else
                    toCpy = COMPOUND_STRING("Rival");
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = COMPOUND_STRING("tu");
                else
                    toCpy = COMPOUND_STRING("rival");
                break;
            }

            if (toCpy != NULL)
            {
                toCpyWidth = GetStringLineWidth(fontId, toCpy, letterSpacing, 1, dstSize);

                if (dstWidth + toCpyWidth > BATTLE_MSG_MAX_WIDTH)
                {
                    dst[lastValidSkip] = lineNum == 1 ? CHAR_NEWLINE : CHAR_PROMPT_SCROLL;
                    dstWidth = GetStringLineWidth(fontId, dst, letterSpacing, lineNum, dstSize);
                    lineNum++;
                }
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER_LOSE_TEXT
                || *src == B_TXT_TRAINER_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            toCpyWidth = GetGlyphWidth(dst[dstID + 1], fontId);
            dst[dstID] = *src;
            if (dstWidth + toCpyWidth > BATTLE_MSG_MAX_WIDTH)
            {
                dst[lastValidSkip] = lineNum == 1 ? CHAR_NEWLINE : CHAR_PROMPT_SCROLL;
                lineNum++;
                dstWidth = 0;
            }
            switch (*src)
            {
            case CHAR_NEWLINE:
            case CHAR_PROMPT_SCROLL:
            case CHAR_PROMPT_CLEAR:
                lineNum++;
                dstWidth = 0;
                //fallthrough
            case CHAR_SPACE:
                lastValidSkip = dstID;
                break;
            }
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string (puntero directo)
            StringAppend(dst, T1_READ_PTR(&src[srcID + 1]));
            srcID += 5;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, ObtenNombreMovimiento(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTipos[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (GetBattlerSide(src[srcID + 1]) == LADO_JUGADOR)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (EsCombateContraEntrenador(gCombate->tipoCombate))
                    StringAppend(dst, COMPOUND_STRING(" rival"));
                else
                    StringAppend(dst, COMPOUND_STRING(" salvaje"));

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == LADO_JUGADOR)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            CopyItemName(hword, dst);
            srcID += 3;
            break;
        }
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sTextOnWindowsInfo;
    struct TextPrinterTemplate printerTemplate;
    u32 speed;

    FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * LADO_TILE);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    gTextFlags.useAlternateDownArrow = TRUE;
    gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG)
    {
        speed = GetPlayerTextSpeedDelay();
        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
    const u8 *msgLastHalfHp;
    const u8 *msgFirstCriticalHit;
    const u8 *msgFirstSuperEffectiveHit;
    const u8 *msgFirstSTABMove;
    const u8 *msgPlayerMonUnaffected;
    const u8 *msgBeforeFirstTurn;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    /* Put any trainer slide-in messages inside this array.
    Example:
    {
        .trainerId = TRAINER_WALLY_VR_2,
        .msgLastSwitchIn = COMPOUND_STRING("Aargh! Almost had it!"),
        .msgLastLowHp = COMPOUND_STRING("La caja está llena. ¡No puedes capturar más!"),
        .msgFirstDown = COMPOUND_STRING("{PAUSE 32}1, {PAUSE 15}2, y{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}¡Guau!"),
        .msgLastHalfHp = sText_ShootSoClose,
        .msgFirstCriticalHit = COMPOUND_STRING("¡Un golpe crítico!"),
        .msgFirstSuperEffectiveHit = COMPOUND_STRING("¡Es super efectivo!"),
        .msgFirstSTABMove = sText_ABoosted,
        .msgPlayerMonUnaffected = sText_ButNoEffect,
        .msgBeforeFirstTurn = COMPOUND_STRING("Gravity intensified!"),
    },
    */
};

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

enum
{
    LESS_THAN,
    EQUAL,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL,
};

u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
    case LESS_THAN:
        return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
    case EQUAL:
        return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN:
        return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
    case LESS_THAN_OR_EQUAL:
        return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN_OR_EQUAL:
        return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
    case NOT_EQUAL:
    default:
        return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

bool32 ShouldDoTrainerSlide(u32 battler, u32 which)
{
    u32 i, firstId, lastId, trainerId, retValue = 1;

    if (!(EsCombateContraEntrenador(gCombate->tipoCombate)) || GetBattlerSide(battler) != LADO_OPONENTE)
        return FALSE;

    firstId = 0, lastId = PARTY_SIZE;
    trainerId = gTrainerBattleOpponent;

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId)
        {
            gBattleScripting.battler = battler;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && !CanBattlerSwitch(battler))
                {
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(firstId, lastId, TRUE) == 1
                    && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 4)
                    && !gCombate->trainerSlideLowHpMsgDone)
                {
                    gCombate->trainerSlideLowHpMsgDone = TRUE;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1)
                {
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_HALF_HP:
                if (sTrainerSlides[i].msgLastHalfHp != NULL
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1
                 && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 2) && BattlerHPPercentage(battler, GREATER_THAN, 4)
                 && !gCombate->trainerSlideHalfHpMsgDone)
                {
                    gCombate->trainerSlideHalfHpMsgDone = TRUE;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgLastHalfHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_CRITICAL_HIT:
                if (sTrainerSlides[i].msgFirstCriticalHit != NULL && gCombate->trainerSlideFirstCriticalHitMsgState == 1)
                {
                    gCombate->trainerSlideFirstCriticalHitMsgState = 2;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgFirstCriticalHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_SUPER_EFFECTIVE_HIT:
                if (sTrainerSlides[i].msgFirstSuperEffectiveHit != NULL
                    && gCombate->trainerSlideFirstSuperEffectiveHitMsgState == 1
                    && gBattleMons[battler].hp)
                {
                    gCombate->trainerSlideFirstSuperEffectiveHitMsgState = 2;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgFirstSuperEffectiveHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_STAB_MOVE:
                if (sTrainerSlides[i].msgFirstSTABMove != NULL
                 && gCombate->trainerSlideFirstSTABMoveMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gCombate->trainerSlideFirstSTABMoveMsgState = 2;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgFirstSTABMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_PLAYER_MON_UNAFFECTED:
                if (sTrainerSlides[i].msgPlayerMonUnaffected != NULL
                 && gCombate->trainerSlidePlayerMonUnaffectedMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gCombate->trainerSlidePlayerMonUnaffectedMsgState = 2;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgPlayerMonUnaffected;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_BEFORE_FIRST_TURN:
                if (sTrainerSlides[i].msgBeforeFirstTurn != NULL && !gCombate->trainerSlideBeforeFirstTurnMsgDone)
                {
                    gCombate->trainerSlideBeforeFirstTurnMsgDone = TRUE;
                    gCombate->trainerSlideMsg = sTrainerSlides[i].msgBeforeFirstTurn;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return FALSE;
}

#include "global.h"
#include "depuracion_mgba.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "constants/battle_ai.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "item.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"

static u8 CountAIAliveNonEggMonsExcept(u8 slotToIgnore);

static void OpponentBufferExecCompleted(u32 combatiente);
static void SwitchIn_HandleSoundAndEnd(u32 battler);


void SetControllerToOpponent(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = OpponentBufferExecCompleted;
    gBattlerControllerFuncs[battler] = EjecutaComandoEnCurso;
}


static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        OpponentBufferExecCompleted(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool8 healthboxAnimDone = FALSE;
    bool8 twoMons;

    twoMons = TwoOpponentIntroMons(battler);
    if (!twoMons)
    {
        if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
        twoMons = FALSE;
    }
    else
    {
        if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy
         && gSprites[gMarcadorSpriteIds[ALIADO(battler)]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
        twoMons = TRUE;
    }

    if (healthboxAnimDone)
    {
        if (twoMons == TRUE)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
             && gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim)
            {
                gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim = FALSE;
                FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
                FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
            }
            else
                return;
        }
        else if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
        {
            if (battler == 3)
            {
                if (!gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].triedShinyMonAnim
                 && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim)
                {
                    FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
                    FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
                }
                else
                    return;
            }
                gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        }
        else
            return;

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
    }
}

static void TrySetBattlerShadowSpriteCallback(u32 battler)
{
    if (gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback == SpriteCallbackDummy)
        SetBattlerShadowSpriteCallback(battler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES));
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;
    bool32 twoMons;

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
        TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);

    twoMons = TwoOpponentIntroMons(battler);
    if (twoMons
     && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim)
        TryShinyAnimation(ALIADO(battler), &gEnemyParty[gBattlerPartyIndexes[ALIADO(battler)]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (twoMons)
            {
                ActualizaMarcador(gMarcadorSpriteIds[ALIADO(battler)], &gEnemyParty[gBattlerPartyIndexes[ALIADO(battler)]], MARCADOR_TODO);
                StartHealthboxSlideIn(ALIADO(battler));
                MuestraMarcador(gMarcadorSpriteIds[ALIADO(battler)]);
            }
            ActualizaMarcador(gMarcadorSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);
            StartHealthboxSlideIn(battler);
            MuestraMarcador(gMarcadorSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    if (!twoMons)
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy)
        {
            TrySetBattlerShadowSpriteCallback(battler);
            if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
            {
                battlerAnimsDone = TRUE;
            }
        }
    }
    else
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattleControllerData[ALIADO(battler)]].callback == SpriteCallbackDummy)
        {
            TrySetBattlerShadowSpriteCallback(battler);
            TrySetBattlerShadowSpriteCallback(ALIADO(battler));
            if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
                && gSprites[gBattlerSpriteIds[ALIADO(battler)]].callback == SpriteCallbackDummy)
            {
                battlerAnimsDone = TRUE;
            }
        }
    }

    if (bgmRestored && battlerAnimsDone)
    {
        if (twoMons)
            DestroySprite(&gSprites[gBattleControllerData[ALIADO(battler)]]);

        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void TryShinyAnimAfterMonAnim(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].x2 == 0
        && !gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
        TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);

    if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        OpponentBufferExecCompleted(battler);
    }
}

static void SwitchIn_ShowSubstitute(u32 battler)
{
    if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);
        gBattlerControllerFuncs[battler] = SwitchIn_HandleSoundAndEnd;
    }
}

static void SwitchIn_HandleSoundAndEnd(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
            OpponentBufferExecCompleted(battler);
        }
    }
}

static void SwitchIn_ShowHealthbox(u32 battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        ActualizaMarcador(gMarcadorSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);
        StartHealthboxSlideIn(battler);
        MuestraMarcador(gMarcadorSpriteIds[battler]);
        CopyBattleSpriteInvisibility(battler);
        gBattlerControllerFuncs[battler] = SwitchIn_ShowSubstitute;
    }
}

static void SwitchIn_TryShinyAnim(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);

    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        SetBattlerShadowSpriteCallback(battler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES));
        gBattlerControllerFuncs[battler] = SwitchIn_ShowHealthbox;
    }
}

static void OpponentBufferExecCompleted(u32 combatiente)
{
    gBattlerControllerFuncs[combatiente] = EjecutaComandoEnCurso;
    DesmarcaCombatienteOcupado(combatiente);
}

void OpponentHandleLoadMonSprite(u32 battler)
{
    BtlController_HandleLoadMonSprite(battler, TryShinyAnimAfterMonAnim);
}

void OpponentHandleSwitchInAnim(u32 battler)
{
    gCombate->monToSwitchIntoId[battler] = PARTY_SIZE;
    BtlController_HandleSwitchInAnim(battler, FALSE, SwitchIn_TryShinyAnim);
}

static u32 OpponentGetTrainerPicId(u32 battlerId)
{
    u32 trainerPicId = GetTrainerPicFromId(gTrainerBattleOpponent);
    return trainerPicId;
}

void OpponentHandleDrawTrainerPic(u32 battler)
{
    s16 xPos = 176;
    u32 trainerPicId = OpponentGetTrainerPicId(battler);

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, TRUE, xPos, 40, -1);
}

void OpponentHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId = OpponentGetTrainerPicId(battler);
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

void OpponentHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, TRUE);
}

void OpponentHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler);
}

void OpponentHandleChooseAction(u32 battler)
{
    AI_TrySwitchOrUseItem(battler);
    OpponentBufferExecCompleted(battler);
}

void OpponentHandleChooseMove(u32 battler)
{
    u32 chosenMoveId = gCombate->IA_Eleccion[battler];
    struct DatosMovimiento *moveInfo = &gArgumentosComando[battler].datosMovimiento;
    u32 chosenMove;

    // La eleccion de la IA no siempre es un indice de movimiento: hay estados que
    // significan "no pienso atacar" y valen mas de 3 (AIExpectsToFaintPlayer ya lo
    // comprueba por su cuenta). Aqui se indexaba sin mirar, leyendo fuera de la
    // estructura y sacando un numero de movimiento inventado.
    if (chosenMoveId >= MAXIMO_MOVIMIENTOS_POKEMON)
    {
        LOG("IA eleccion fuera de rango. combatiente/valor", battler, chosenMoveId);
        chosenMoveId = 0;
    }

    chosenMove = moveInfo->movimiento[chosenMoveId];
    // LOG("IA elige movimiento/id", chosenMove, chosenMoveId);
    gBattlerTarget = gCombate->IA_Objetivo[battler];

    if (GetBattlerMoveTargetType(battler, chosenMove) & (MOVE_TARGET_USER_OR_SELECTED | MOVE_TARGET_USER))
        gBattlerTarget = battler;
    if (GetBattlerMoveTargetType(battler, chosenMove) & MOVE_TARGET_BOTH)
    {
        gBattlerTarget = JUGADOR_IZQUIERDA;
        if (gAbsentBattlerFlags & (1u << gBattlerTarget))
            gBattlerTarget = JUGADOR_DERECHA;
    }
    RespondeDosValores(battler, SELECCION_MOVIMIENTO, (chosenMoveId) | (gBattlerTarget << 8));
    OpponentBufferExecCompleted(battler);
}

void OpponentHandleChoosePokemon(u32 battler)
{
    s32 chosenMonId;
    s32 pokemonInBattle = 1;

    // Choosing Revival Blessing target
    if ((gArgumentosComando[battler].caso & 0xF) == PARTY_ACTION_CHOOSE_FAINTED_MON)
    {
        chosenMonId = gSelectedMonPartyId = GetFirstFaintedPartyIndex(battler);
    }
    // Switching out
    else if (gCombate->AI_monToSwitchIntoId[battler] == PARTY_SIZE)
    {
        chosenMonId = GetMostSuitableMonToSwitchInto(battler, TRUE);
        if (chosenMonId == PARTY_SIZE)
        {
            s32 battler1, battler2, firstId, lastId;

            if (!EsCombateContraEntrenador(gCombate->tipoCombate))
            {
                battler2 = battler1 = OPONENTE_IZQUIERDA;
            }
            else
            {
                battler1 = OPONENTE_IZQUIERDA;
                battler2 = OPONENTE_DERECHA;
                pokemonInBattle = 2;
            }

            GetAIPartyIndexes(battler, &firstId, &lastId);
            for (chosenMonId = (lastId-1); chosenMonId >= firstId; chosenMonId--)
            {
                if (!IsValidForBattle(&gEnemyParty[chosenMonId]))
                    continue;
                if (chosenMonId == gBattlerPartyIndexes[battler1]
                 || chosenMonId == gBattlerPartyIndexes[battler2])
                    continue;
                if ((AI_THINKING_STRUCT->aiFlags[battler] & AI_FLAG_ACE_POKEMON)
                 && ((chosenMonId != CalculateEnemyPartyCount() - 1) || CountAIAliveNonEggMonsExcept(PARTY_SIZE) == pokemonInBattle))
                    continue;
                // mon is valid
                break;
            }
        }
        gCombate->monToSwitchIntoId[battler] = chosenMonId;
    }
    else
    {
        chosenMonId = gCombate->AI_monToSwitchIntoId[battler];
        gCombate->AI_monToSwitchIntoId[battler] = PARTY_SIZE;
        gCombate->monToSwitchIntoId[battler] = chosenMonId;
    }
    RespondePokemonElegido(battler, chosenMonId, NULL);
    OpponentBufferExecCompleted(battler);

}

static u8 CountAIAliveNonEggMonsExcept(u8 slotToIgnore)
{
    u32 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (i != slotToIgnore
            && IsValidForBattle(&gEnemyParty[i]))
        {
            count++;
        }
    }

    return count;
}

void OpponentHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler);
}

void OpponentHandleIntroTrainerBallThrow(u32 battler)
{
    BtlController_HandleIntroTrainerBallThrow(battler, 0, NULL, 0, Intro_TryShinyAnimShowHealthbox);
}

void OpponentHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, LADO_OPONENTE, TRUE);
}

void OpponentHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, FALSE);
}

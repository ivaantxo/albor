#include "global.h"
#include "depuracion_mgba.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"
#include "menu.h"
#include "pokemon_summary_screen.h"

static void PlayerBufferExecCompleted(u32 combatiente);

static void MoveSelectionDisplayPpNumber(u32 battler);
static void MoveSelectionDisplayMoveType(u32 battler);
static void DestruyeIconosTipo(void);
static void AseguraIconosTipo(u32 battler);
static void MoveSelectionDisplayMoveNames(u32 battler);
static void SwitchIn_HandleSoundAndEnd(u32 battler);
static void WaitForMonSelection(u32 battler);
static void Task_LaunchLvlUpAnim(u8);
static void Task_SetControllerToWaitForString(u8);
static void Task_UpdateLvlInHealthbox(u8);

#define TAG_ICON_TYPES 30005

static EWRAM_DATA u8 monIconData;
// A que combatiente pertenece el icono, para copiarle el bote.
#define sIconoCombatiente data[0]

static void SpriteCB_IconoAccion(struct Sprite *sprite)
{
    u32 combatiente = sprite->sIconoCombatiente;

    if (combatiente < NUMERO_COMBATIENTES)
        sprite->y2 = gSprites[gBattlerSpriteIds[combatiente]].y2;
}
static EWRAM_DATA u8 sIconTypeId[MAXIMO_MOVIMIENTOS_POKEMON] = {0};


void SetControllerToPlayer(u32 battler)
{
    sIconTypeId[0] = 0xFF;
    sIconTypeId[1] = 0xFF;
    sIconTypeId[2] = 0xFF;
    sIconTypeId[3] = 0xFF;
    gBattlerControllerEndFuncs[battler] = PlayerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = EjecutaComandoEnCurso;
    gDoingBattleAnim = FALSE;
}

static void PlayerBufferExecCompleted(u32 combatiente)
{
    // Se registra que funcion de controlador estaba activa al liberar: eso
    // identifica al llamante sin tener que instrumentar 33 puntos de llamada.
    LOG("LIBERA comando/func", gComandoEnCurso[combatiente],
        (u32)gBattlerControllerFuncs[combatiente]);
    gBattlerControllerFuncs[combatiente] = EjecutaComandoEnCurso;
    DesmarcaCombatienteOcupado(combatiente);
}


static void CompleteOnBattlerSpritePosX_0(u32 combatiente)
{
    if (gSprites[gBattlerSpriteIds[combatiente]].x2 == 0)
        PlayerBufferExecCompleted(combatiente);
}

static u16 GetPrevBall(u16 ballId)
{
    u16 ballPrev;
    s32 i, j;
    CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);
    for (i = 0; i < gBagPockets[BALLS_POCKET].capacity; i++)
    {
        if (ballId == gBagPockets[BALLS_POCKET].itemSlots[i].itemId)
        {
            if (i <= 0)
            {
                for (j = gBagPockets[BALLS_POCKET].capacity - 1; j >= 0; j--)
                {
                    ballPrev = gBagPockets[BALLS_POCKET].itemSlots[j].itemId;
                    if (ballPrev != ITEM_NONE)
                        return ballPrev;
                }
            }
            i--;
            break;
        }
    }
    return gBagPockets[BALLS_POCKET].itemSlots[i].itemId;
}

static u32 GetNextBall(u32 ballId)
{
    u32 ballNext = ITEM_NONE;
    s32 i;
    CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);
    for (i = 1; i < gBagPockets[BALLS_POCKET].capacity; i++)
    {
        if (ballId == gBagPockets[BALLS_POCKET].itemSlots[i-1].itemId)
        {
            ballNext = gBagPockets[BALLS_POCKET].itemSlots[i].itemId;
            break;
        }
    }
    if (ballNext == ITEM_NONE)
        return gBagPockets[BALLS_POCKET].itemSlots[0].itemId; // Zeroth slot
    else
        return ballNext;
}

static void HandleInputChooseAction(u32 battler)
{
    DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
    DoBounceEffect(battler, BOUNCE_MON, 7, 1);


    if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == TRUE)
    {
        if (!gLastUsedBallMenuPresent)
        {
            gCombate->ackBallUseBtn = FALSE;
        }
        else if (JOY_NEW(B_LAST_USED_BALL_BUTTON))
        {
            gCombate->ackBallUseBtn = TRUE;
            gCombate->ballSwapped = FALSE;
            ArrowsChangeColorLastBallCycle(TRUE);
        }

        if (gCombate->ackBallUseBtn)
        {
            if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_DOWN) || JOY_NEW(DPAD_RIGHT)))
            {
                bool32 sameBall = FALSE;
                u32 nextBall = GetNextBall(gBallToDisplay);
                gCombate->ballSwapped = TRUE;
                if (gBallToDisplay == nextBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = nextBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_LEFT)))
            {
                bool32 sameBall = FALSE;
                u32 prevBall = GetPrevBall(gBallToDisplay);
                gCombate->ballSwapped = TRUE;
                if (gBallToDisplay == prevBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = prevBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_NEW(B_BUTTON) || (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && gCombate->ballSwapped))
            {
                gCombate->ackBallUseBtn = FALSE;
                gCombate->ballSwapped = FALSE;
                ArrowsChangeColorLastBallCycle(FALSE);
            }
            else if (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
            {
                gCombate->ackBallUseBtn = FALSE;
                PlaySE(SE_SELECT);
                ArrowsChangeColorLastBallCycle(FALSE);
                TryHideLastUsedBall();
                RespondeDosValores(battler, B_ACTION_THROW_BALL, 0);
                PlayerBufferExecCompleted(battler);
            }
            return;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();

        switch (gActionSelectionCursor[battler])
        {
        case 0:
            RespondeDosValores(battler, B_ACTION_USE_MOVE, 0);
            break;
        case 1:
            RespondeDosValores(battler, B_ACTION_SWITCH, 0);
            break;
        case 2:
            RespondeDosValores(battler, B_ACTION_RUN, 0);
            break;
        }
        PlayerBufferExecCompleted(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1) // De Pokémon a Luchar
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] -= 1;
            LoadCompressedPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        else if (gActionSelectionCursor[battler] & 2)// De Huir a Pokémon
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] -= 1;
            LoadCompressedPalette(gBattleActionsPalPokemon, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        else // De Luchar a Huir
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] += 2;
            LoadCompressedPalette(gBattleActionsPalRun, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (gActionSelectionCursor[battler] & 2) // De Huir a Luchar
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] -= 2;
            LoadCompressedPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        else if (gActionSelectionCursor[battler] & 1) // De Pokémon a Huir
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] += 1;
            LoadCompressedPalette(gBattleActionsPalRun, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        else // De Luchar a Pokémon
        {
            PlaySE(SE_SELECT);
            gActionSelectionCursor[battler] += 1;
            LoadCompressedPalette(gBattleActionsPalPokemon, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate)
         && battler == JUGADOR_DERECHA
         && !(gAbsentBattlerFlags & (1u << JUGADOR_IZQUIERDA)))
        {
            PlaySE(SE_SELECT);
            RespondeDosValores(battler, B_ACTION_CANCEL_PARTNER, 0);
            PlayerBufferExecCompleted(battler);
        DestroySpriteAndFreeResources(&gSprites[monIconData]);
            MoveSelectionDestroyCursor();
        }
        else if (B_QUICK_MOVE_CURSOR_TO_RUN)
        {
            if (!(EsCombateContraEntrenador(gCombate->tipoCombate))) // If wild battle, pressing B moves cursor to "Run".
            {
                PlaySE(SE_SELECT);
                gActionSelectionCursor[battler] = 2;
                LoadCompressedPalette(gBattleActionsPalRun, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            }
        }
    }
    else if (DEBUG_BATTLE_MENU == TRUE && JOY_NEW(SELECT_BUTTON))
    {
        RespondeDosValores(battler, B_ACTION_DEBUG, 0);
        PlayerBufferExecCompleted(battler);
    }
    else if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == FALSE
             && JOY_NEW(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();
        RespondeDosValores(battler, B_ACTION_THROW_BALL, 0);
        PlayerBufferExecCompleted(battler);
        DestroySpriteAndFreeResources(&gSprites[monIconData]);
    }
}

void HandleInputChooseTarget(u32 battler)
{
    s32 i;
    static const u8 identities[NUMERO_COMBATIENTES] = {JUGADOR_IZQUIERDA, JUGADOR_DERECHA, OPONENTE_DERECHA, OPONENTE_IZQUIERDA};
    u16 move = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_MOVE1 + gMoveSelectionCursor[battler]);
    u16 moveTarget = GetBattlerMoveTargetType(battler, move);

    DoBounceEffect(gPosicionCursorSiNo, BOUNCE_HEALTHBOX, 15, 1); // REVISAR
    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gPosicionCursorSiNo) // REVISAR
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_HideAsMoveTarget; // REVISAR
        RespondeDosValores(battler, SELECCION_MOVIMIENTO, gMoveSelectionCursor[battler] | (gPosicionCursorSiNo << 8));
        EndBounceEffect(gPosicionCursorSiNo, BOUNCE_HEALTHBOX); // REVISAR
        TryHideLastUsedBall();
        PlayerBufferExecCompleted(battler);
        MoveSelectionDestroyCursor();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_HideAsMoveTarget; // REVISAR
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
        EndBounceEffect(gPosicionCursorSiNo, BOUNCE_HEALTHBOX); // REVISAR
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_UP))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_HideAsMoveTarget; // REVISAR

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gPosicionCursorSiNo ^= BIT_FLANK; // REVISAR
        }
        else
        {
            do
            {
                u32 currSelIdentity = gPosicionCursorSiNo; // REVISAR

                for (i = 0; i < NUMERO_COMBATIENTES; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (--i < 0)
                        i = NUMERO_COMBATIENTES - 1;
                    gPosicionCursorSiNo = identities[i]; // REVISAR
                } while (gPosicionCursorSiNo == gBattlersCount); // REVISAR

                i = 0;
                switch (gPosicionCursorSiNo) // REVISAR
                {
                case JUGADOR_IZQUIERDA:
                case JUGADOR_DERECHA:
                    if (battler != gPosicionCursorSiNo) // REVISAR
                        i++;
                    else if (moveTarget & MOVE_TARGET_USER_OR_SELECTED)
                        i++;
                    break;
                case OPONENTE_IZQUIERDA:
                case OPONENTE_DERECHA:
                    i++;
                    break;
                }

                if (gAbsentBattlerFlags & (1u << gPosicionCursorSiNo)) // REVISAR
                    i = 0;
            } while (i == 0);
        }
        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_ShowAsMoveTarget; // REVISAR
    }
    else if (JOY_NEW(DPAD_RIGHT | DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_HideAsMoveTarget; // REVISAR

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gPosicionCursorSiNo ^= BIT_FLANK; // REVISAR
        }
        else
        {
            do
            {
                u32 currSelIdentity = gPosicionCursorSiNo; // REVISAR

                for (i = 0; i < NUMERO_COMBATIENTES; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (++i > 3)
                        i = 0;
                    gPosicionCursorSiNo = identities[i]; // REVISAR
                } while (gPosicionCursorSiNo == gBattlersCount); // REVISAR

                i = 0;
                switch (gPosicionCursorSiNo) // REVISAR
                {
                case JUGADOR_IZQUIERDA:
                case JUGADOR_DERECHA:
                    if (battler != gPosicionCursorSiNo) // REVISAR
                        i++;
                    else if (moveTarget & MOVE_TARGET_USER_OR_SELECTED)
                        i++;
                    break;
                case OPONENTE_IZQUIERDA:
                case OPONENTE_DERECHA:
                    i++;
                    break;
                }

                if (gAbsentBattlerFlags & (1u << gPosicionCursorSiNo)) // REVISAR
                    i = 0;
            } while (i == 0);
        }

        gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_ShowAsMoveTarget; // REVISAR
    }
}

static void HideAllTargets(void)
{
    s32 i;
    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

static void HideShownTargets(u32 battler)
{
    s32 i;
    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing && i != battler)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

void HandleInputShowEntireFieldTargets(u32 battler)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        RespondeDosValores(battler, SELECCION_MOVIMIENTO, gMoveSelectionCursor[battler] | (gPosicionCursorSiNo << 8));
        PlayerBufferExecCompleted(battler);
        MoveSelectionDestroyCursor();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

void HandleInputShowTargets(u32 battler)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        RespondeDosValores(battler, SELECCION_MOVIMIENTO, gMoveSelectionCursor[battler] | (gPosicionCursorSiNo << 8));
        TryHideLastUsedBall();
        PlayerBufferExecCompleted(battler);
        MoveSelectionDestroyCursor();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

static void TryShowAsTarget(u32 battler)
{
    if (IsBattlerAlive(battler))
    {
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 15, 1);
        gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_ShowAsMoveTarget;
    }
}

void HandleInputChooseMove(u32 battler)
{
    u16 moveTarget;
    u32 canSelectTarget = 0;
    struct DatosMovimiento *datosMovimiento = &gArgumentosComando[battler].datosMovimiento;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        moveTarget = GetBattlerMoveTargetType(battler, datosMovimiento->movimiento[gMoveSelectionCursor[battler]]);

        if (moveTarget & MOVE_TARGET_USER)
            gPosicionCursorSiNo = battler; // REVISAR
        else
            gPosicionCursorSiNo = OPONENTE(GetBattlerSide(battler)); // REVISAR

        if (!gArgumentosComando[battler].esCombateDoble) // not a double battle
        {
            if (moveTarget & MOVE_TARGET_USER_OR_SELECTED && !gArgumentosComando[battler].sinNumeroDePP)
                canSelectTarget = 1;
        }
        else // double battle
        {
            if (!(moveTarget & (MOVE_TARGET_RANDOM | MOVE_TARGET_BOTH | MOVE_TARGET_DEPENDS | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_USER | MOVE_TARGET_ALLY)))
                canSelectTarget = 1; // either selected or user
            if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY) && IsBattlerAlive(ALIADO(battler)))
                canSelectTarget = 1;

            if (datosMovimiento->pp[gMoveSelectionCursor[battler]] == 0)
            {
                canSelectTarget = 0;
            }
            else if (!(moveTarget & (MOVE_TARGET_USER | MOVE_TARGET_USER_OR_SELECTED)) && CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, battler) <= 1)
            {
                gPosicionCursorSiNo = GetDefaultMoveTarget(battler);  // REVISAR
                canSelectTarget = 0;
            }

            if (B_SHOW_TARGETS == TRUE)
            {
                // Show all available targets for multi-target moves
                if ((moveTarget & MOVE_TARGET_ALL_BATTLERS) == MOVE_TARGET_ALL_BATTLERS)
                {
                    u32 i = 0;
                    for (i = 0; i < gBattlersCount; i++)
                        TryShowAsTarget(i);

                    canSelectTarget = 3;
                }
                else if (moveTarget & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
                {
                    TryShowAsTarget(gPosicionCursorSiNo); // REVISAR
                    TryShowAsTarget(ALIADO(gPosicionCursorSiNo)); // REVISAR
                    if (moveTarget & MOVE_TARGET_FOES_AND_ALLY)
                        TryShowAsTarget(ALIADO(battler));
                    canSelectTarget = 2;
                }
            }
        }

        switch (canSelectTarget)
        {
        case 0:
        default:
            RespondeDosValores(battler, SELECCION_MOVIMIENTO, gMoveSelectionCursor[battler] | (gPosicionCursorSiNo << 8));
            TryHideLastUsedBall();
            PlayerBufferExecCompleted(battler);
            MoveSelectionDestroyCursor();
            break;
        case 1:
            gBattlerControllerFuncs[battler] = HandleInputChooseTarget;

            if (moveTarget & (MOVE_TARGET_USER | MOVE_TARGET_USER_OR_SELECTED))
                gPosicionCursorSiNo = battler; // REVISAR
            else if (gAbsentBattlerFlags & (1u << OPONENTE_IZQUIERDA))
                gPosicionCursorSiNo = OPONENTE_DERECHA; // REVISAR
            else
                gPosicionCursorSiNo = OPONENTE_IZQUIERDA; // REVISAR

            gSprites[gBattlerSpriteIds[gPosicionCursorSiNo]].callback = SpriteCB_ShowAsMoveTarget; // REVISAR
            break;
        case 2:
            gBattlerControllerFuncs[battler] = HandleInputShowTargets;
            break;
        case 3: // Entire field
            gBattlerControllerFuncs[battler] = HandleInputShowEntireFieldTargets;
            break;
        }
    }
    else if ((JOY_NEW(B_BUTTON)))
    {
        PlaySE(SE_SELECT);
        RespondeDosValores(battler, SELECCION_CANCELADA, 0);
        PlayerBufferExecCompleted(battler);
        LoadBattleMenuWindowGfx();
        MoveSelectionDestroyCursor();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gMoveSelectionCursor[battler] & 1)
        {
            MoveSelectionDestroyCursor();
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler]);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gMoveSelectionCursor[battler] & 1)
         && (gMoveSelectionCursor[battler] ^ 1) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursor();
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler]);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gMoveSelectionCursor[battler] & 2)
        {
            MoveSelectionDestroyCursor();
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler]);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gMoveSelectionCursor[battler] & 2)
         && (gMoveSelectionCursor[battler] ^ 2) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursor();
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler]);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
}

static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        PlayerBufferExecCompleted(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool8 healthboxAnimDone = FALSE;

    // Check if healthbox has finished sliding in
    if (TwoPlayerIntroMons(battler))
    {
        if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy
         && gSprites[gMarcadorSpriteIds[ALIADO(battler)]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }
    else
    {
        if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }

    // If healthbox and shiny anim are done
    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim)
    {
        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);

        if (TwoPlayerIntroMons(battler))
            HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[ALIADO(battler)]], ALIADO(battler));

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;

    // Start shiny animation if applicable for 1st Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);

    // Start shiny animation if applicable for 2nd Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].ballAnimActive)
        TryShinyAnimation(ALIADO(battler), &gPlayerParty[gBattlerPartyIndexes[ALIADO(battler)]]);

    // Show healthbox after ball anim
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[ALIADO(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (TwoPlayerIntroMons(battler))
            {
                ActualizaMarcador(gMarcadorSpriteIds[ALIADO(battler)], &gPlayerParty[gBattlerPartyIndexes[ALIADO(battler)]], MARCADOR_TODO);
                StartHealthboxSlideIn(ALIADO(battler));
                MuestraMarcador(gMarcadorSpriteIds[ALIADO(battler)]);
            }
            ActualizaMarcador(gMarcadorSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);
            StartHealthboxSlideIn(battler);
            MuestraMarcador(gMarcadorSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    // Restore bgm after cry has played and healthbox anim is started
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

    // Wait for battler anims
    if (TwoPlayerIntroMons(battler))
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattleControllerData[ALIADO(battler)]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[ALIADO(battler)]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }
    else
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }

    // Clean up
    if (bgmRestored && battlerAnimsDone)
    {
        if (TwoPlayerIntroMons(battler))
            DestroySprite(&gSprites[gBattleControllerData[ALIADO(battler)]]);
        DestroySprite(&gSprites[gBattleControllerData[battler]]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void SwitchIn_CleanShinyAnimShowSubstitute(u32 battler)
{
    if (gSprites[gMarcadorSpriteIds[battler]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(battler);

        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        // Check if Substitute should be shown
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[battler] = SwitchIn_HandleSoundAndEnd;
    }
}

static void SwitchIn_HandleSoundAndEnd(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive
        && !IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        PlayerBufferExecCompleted(battler);
    }
}

static void SwitchIn_TryShinyAnimShowHealthbox(u32 battler)
{
    // Start shiny animation if applicable
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);

    // Wait for ball anim, then show healthbox
    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        ActualizaMarcador(gMarcadorSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);
        StartHealthboxSlideIn(battler);
        MuestraMarcador(gMarcadorSpriteIds[battler]);
        gBattlerControllerFuncs[battler] = SwitchIn_CleanShinyAnimShowSubstitute;
    }
}

void Task_PlayerController_RestoreBgmAfterCry(u8 taskId)
{
    if (!IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, VOLUMEN_MAXIMO);
        DestroyTask(taskId);
    }
}

#define tExpTask_monId          data[0]
#define tExpTask_battler        data[2]
#define tExpTask_gainedExp_1    data[3]
#define tExpTask_gainedExp_2    data[4] // Stored as two half-words containing a word.
#define tExpTask_frames         data[10]

static s32 GetTaskExpValue(u8 taskId)
{
    return (u16)(gTasks[taskId].tExpTask_gainedExp_1) | (gTasks[taskId].tExpTask_gainedExp_2 << 16);
}




// Sin barra de experiencia la ganancia no tiene nada que animar, asi que se
// aplica de una vez para todos los Pokemon del equipo por igual.
static void Task_GiveExpToMon(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].tExpTask_monId);
    u8 battler = gTasks[taskId].tExpTask_battler;
    s32 gainedExp = GetTaskExpValue(taskId);
    struct Pokemon *mon = &gPlayerParty[monId];
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    u32 currExp = GetMonData(mon, MON_DATA_EXP);
    u32 nextLvlExp = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1];

    if (currExp + gainedExp >= nextLvlExp)
    {
        SetMonData(mon, MON_DATA_EXP, &nextLvlExp);
        CalculateMonStats(mon);

        gainedExp -= nextLvlExp - currExp;
        RespondeDosValores(battler, B_ACTION_SUBIO_NIVEL, gainedExp);

        // La animacion de subida de nivel solo tiene sentido sobre el Pokemon que
        // esta en el terreno; los del banquillo suben en silencio.
        if (monId == gBattlerPartyIndexes[battler]
         || (WhichBattleCoords(battler) == DOBLES && monId == gBattlerPartyIndexes[ALIADO(battler)]))
            gTasks[taskId].func = Task_LaunchLvlUpAnim;
        else
            gTasks[taskId].func = Task_SetControllerToWaitForString;
    }
    else
    {
        currExp += gainedExp;
        SetMonData(mon, MON_DATA_EXP, &currExp);
        gBattlerControllerFuncs[battler] = Controller_WaitForString;
        DestroyTask(taskId);
    }
}

static void Task_LaunchLvlUpAnim(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    u8 monIndex = gTasks[taskId].tExpTask_monId;

    if (EsCombateContraEntrenador(gCombate->tipoCombate) && monIndex == gBattlerPartyIndexes[ALIADO(battler)])
        battler ^= BIT_FLANK;

    InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_LVL_UP);
    gTasks[taskId].func = Task_UpdateLvlInHealthbox;
}

static void Task_UpdateLvlInHealthbox(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
    {
        u8 monIndex = gTasks[taskId].tExpTask_monId;

        if (EsCombateContraEntrenador(gCombate->tipoCombate) && monIndex == gBattlerPartyIndexes[ALIADO(battler)])
            ActualizaMarcador(gMarcadorSpriteIds[ALIADO(battler)], &gPlayerParty[monIndex], MARCADOR_TODO);
        else
            ActualizaMarcador(gMarcadorSpriteIds[battler], &gPlayerParty[monIndex], MARCADOR_TODO);

        gTasks[taskId].func = Task_SetControllerToWaitForString;
    }
}

static void Task_SetControllerToWaitForString(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    gBattlerControllerFuncs[battler] = Controller_WaitForString;
    DestroyTask(taskId);
}

static void OpenPartyMenuToChooseMon(u32 battler)
{
    if (!gFundidoPaletas.activo)
    {
        u8 caseId;

        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        caseId = gTasks[gBattleControllerData[battler]].data[0];
        DestroyTask(gBattleControllerData[battler]);
        FreeAllWindowBuffers();
        OpenPartyMenuInBattle(caseId);
    }
}

static void WaitForMonSelection(u32 battler)
{
    // Basta con haber vuelto al combate; esperar ademas a que el fundido TERMINE
    // era lo que descuadraba la interfaz. Con esa espera, el menu de accion y el
    // icono no empezaban a montarse hasta que la pantalla ya se veia entera, asi
    // que aparecian varios fotogramas despues que el textbox y los Pokemon.
    // Quien abre el menu ya espera al fundido de salida antes de dejar aqui el
    // control, asi que esta condicion sola es suficiente.
    if (gMain.callback2 == BattleMainCB2)
    {
        if (gPartyMenuUseExitCallback == TRUE)
            RespondePokemonElegido(battler, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            RespondePokemonElegido(battler, PARTY_SIZE, NULL);

        PlayerBufferExecCompleted(battler);
    }
}

static void PlayerHandleYesNoInput(u32 battler)
{
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
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);

        if (gPosicionCursorSiNo == CURSOR_NO)
            RespondeDosValores(battler, 14, 0);
        else
            RespondeDosValores(battler, 13, 0);

        PlayerBufferExecCompleted(battler);
    }
    if (JOY_NEW(B_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);
        PlayerBufferExecCompleted(battler);
    }
}

static void MoveSelectionDisplayMoveNames(u32 battler)
{
    struct DatosMovimiento *moveInfo = &gArgumentosComando[battler].datosMovimiento;
    gNumberOfMovesToChoose = 0;

    for (u32 i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        MoveSelectionDestroyCursor();
        StringCopy(gDisplayedStringBattle, ObtenNombreMovimiento(moveInfo->movimiento[i]));
        // Prints on windows B_WIN_MOVE_NAME_1, B_WIN_MOVE_NAME_2, B_WIN_MOVE_NAME_3, B_WIN_MOVE_NAME_4
        BattlePutTextOnWindow(gDisplayedStringBattle, i + B_WIN_MOVE_NAME_1);
        if (moveInfo->movimiento[i] != MOVE_NONE)
            gNumberOfMovesToChoose++;
    }
}

static void MoveSelectionDisplayPpNumber(u32 battler)
{
    struct DatosMovimiento *moveInfo = &gArgumentosComando[battler].datosMovimiento;

    if (gArgumentosComando[battler].sinNumeroDePP == TRUE) // check if we didn't want to display pp number
        return;

    for (u32 i = 0; i < 4; i++)
    {
        if (moveInfo->movimiento[i] != MOVE_NONE)
        {
            ConvertIntToDecimalStringN(gDisplayedStringBattle, moveInfo->pp[i], STR_CONV_MODE_RIGHT_ALIGN, 2);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP_1 + i); // B_WIN_PP_1, B_WIN_PP_2, etc.
        }
        else
        {
            BattlePutTextOnWindow(gText_OneDash, B_WIN_PP_1 + i); // B_WIN_PP_1, B_WIN_PP_2, etc.
        }
    }
}

static const struct OamData sOamData_IconTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_IconTypeNormal[] = {
    ANIMCMD_FRAME(TIPO_NORMAL * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeFighting[] = {
    ANIMCMD_FRAME(TIPO_LUCHA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeFlying[] = {
    ANIMCMD_FRAME(TIPO_VOLADOR * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypePoison[] = {
    ANIMCMD_FRAME(TIPO_VENENO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeGround[] = {
    ANIMCMD_FRAME(TIPO_TIERRA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeRock[] = {
    ANIMCMD_FRAME(TIPO_ROCA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeBug[] = {
    ANIMCMD_FRAME(TIPO_BICHO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeGhost[] = {
    ANIMCMD_FRAME(TIPO_FANTASMA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeSteel[] = {
    ANIMCMD_FRAME(TIPO_ACERO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeFire[] = {
    ANIMCMD_FRAME(TIPO_FUEGO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeWater[] = {
    ANIMCMD_FRAME(TIPO_AGUA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeGrass[] = {
    ANIMCMD_FRAME(TIPO_PLANTA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeElectric[] = {
    ANIMCMD_FRAME(TIPO_ELECTRICO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypePsychic[] = {
    ANIMCMD_FRAME(TIPO_PSIQUICO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeIce[] = {
    ANIMCMD_FRAME(TIPO_HIELO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeDragon[] = {
    ANIMCMD_FRAME(TIPO_DRAGON * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeDark[] = {
    ANIMCMD_FRAME(TIPO_SINIESTRO * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_IconTypeFairy[] = {
    ANIMCMD_FRAME(TIPO_HADA * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_IconTypes[NUMERO_TIPOS] = {
    sSpriteAnim_IconTypeNormal,
    sSpriteAnim_IconTypeFighting,
    sSpriteAnim_IconTypeFlying,
    sSpriteAnim_IconTypePoison,
    sSpriteAnim_IconTypeGround,
    sSpriteAnim_IconTypeRock,
    sSpriteAnim_IconTypeBug,
    sSpriteAnim_IconTypeGhost,
    sSpriteAnim_IconTypeSteel,
    sSpriteAnim_IconTypeFire,
    sSpriteAnim_IconTypeWater,
    sSpriteAnim_IconTypeGrass,
    sSpriteAnim_IconTypeElectric,
    sSpriteAnim_IconTypePsychic,
    sSpriteAnim_IconTypeIce,
    sSpriteAnim_IconTypeDragon,
    sSpriteAnim_IconTypeDark,
    sSpriteAnim_IconTypeFairy,
};

const struct CompressedSpriteSheet sSpriteSheet_IconTypes =
{
    .data = gIconTypes_Gfx,
    .size = (NUMERO_TIPOS) * 128,
    .tag = TAG_ICON_TYPES
};
const struct SpriteTemplate sSpriteTemplate_IconTypes =
{
    .tileTag = TAG_ICON_TYPES,
    .paletteTag = TAG_ICON_TYPES,
    .oam = &sOamData_IconTypes,
    .anims = sSpriteAnimTable_IconTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u8 sMoveTypeToOamPaletteNum[NUMERO_TIPOS] =
{
    [TIPO_NORMAL] = 14,
    [TIPO_LUCHA] = 13,
    [TIPO_VOLADOR] = 14,
    [TIPO_VENENO] = 15,
    [TIPO_TIERRA] = 14,
    [TIPO_ROCA] = 15,
    [TIPO_BICHO] = 13,
    [TIPO_FANTASMA] = 14,
    [TIPO_ACERO] = 15,
    [TIPO_FUEGO] = 14,
    [TIPO_AGUA] = 14,
    [TIPO_PLANTA] = 13,
    [TIPO_ELECTRICO] = 13,
    [TIPO_PSIQUICO] = 15,
    [TIPO_HIELO] = 14,
    [TIPO_DRAGON] = 13,
    [TIPO_SINIESTRO] = 13,
    [TIPO_HADA] = 13,
};

static void CargaPaletaTipo(u32 tipo, u32 paletteId)
{
    static const u32 *const sPaletasPorTipo[] =
    {
        [TIPO_BICHO]     = gMoveTypePalBug,
        [TIPO_SINIESTRO] = gMoveTypePalDark,
        [TIPO_DRAGON]    = gMoveTypePalDragon,
        [TIPO_ELECTRICO] = gMoveTypePalElectric,
        [TIPO_HADA]      = gMoveTypePalFairy,
        [TIPO_LUCHA]     = gMoveTypePalFight,
        [TIPO_FUEGO]     = gMoveTypePalFire,
        [TIPO_VOLADOR]   = gMoveTypePalFlying,
        [TIPO_FANTASMA]  = gMoveTypePalGhost,
        [TIPO_PLANTA]    = gMoveTypePalGrass,
        [TIPO_TIERRA]    = gMoveTypePalGround,
        [TIPO_HIELO]     = gMoveTypePalIce,
        [TIPO_NORMAL]    = gMoveTypePalNormal,
        [TIPO_VENENO]    = gMoveTypePalPoison,
        [TIPO_PSIQUICO]  = gMoveTypePalPsychic,
        [TIPO_ROCA]      = gMoveTypePalRock,
        [TIPO_ACERO]     = gMoveTypePalSteel,
        [TIPO_AGUA]      = gMoveTypePalWater,
    };
    LoadCompressedPalette(sPaletasPorTipo[tipo], BG_PLTT_ID(paletteId), PLTT_SIZE_4BPP);
}

void LoadPalettesTypes(u32 combatiente)
{
    struct DatosMovimiento *datosMovimiento = &gArgumentosComando[combatiente].datosMovimiento;

    for (u32 i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
        CargaPaletaTipo(gMovimientos[datosMovimiento->movimiento[i]].type, 12 + i);
}

// Los cuatro iconos comparten una sola hoja de tiles, asi que hay que soltarla
// UNA vez y no una por sprite. Sus paletas se cargan a mano con
// LoadCompressedPalette, no por el repartidor de paletas de sprites, asi que
// tampoco hay que liberarlas: DestroySpriteAndFreeResources lo intentaba igual.
static void DestruyeIconosTipo(void)
{
    bool32 habia = FALSE;

    for (u32 i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (sIconTypeId[i] == 0xFF)
            continue;

        DestroySprite(&gSprites[sIconTypeId[i]]);
        sIconTypeId[i] = 0xFF;
        habia = TRUE;
    }

    if (habia)
        FreeSpriteTilesByTag(TAG_ICON_TYPES);
}

// Los iconos de tipo pertenecen a la pagina de seleccion de movimiento, que es la
// que muestra BG0 desplazado dos pantallas. Su vida se ata a esa pagina en vez de
// crearlos y destruirlos a mano en cada camino: antes cada sitio lo hacia en un
// momento distinto y quedaban un fotograma por delante o por detras del resto.
//
// Gobierna las dos direcciones a proposito. Solo destruyendo no bastaba: se crean
// al preparar la pantalla, que es ANTES de que la pagina cambie, asi que la propia
// comprobacion los borraba en ese mismo fotograma y no volvian a aparecer.
// Guarda el combatiente MAS UNO, porque las variables de EWRAM solo pueden
// inicializarse a cero: asi el cero significa "todavia no hay dueno".
static EWRAM_DATA u8 sDuenoIconosTipoMasUno = 0;

void SincronizaIconosTipoConPantalla(void)
{
    if (gBattle_BG0_Y == ALTURA_PANTALLA * 2)
    {
        if (sDuenoIconosTipoMasUno != 0)
            AseguraIconosTipo(sDuenoIconosTipoMasUno - 1);
    }
    else
    {
        DestruyeIconosTipo();
    }
}

static void AseguraIconosTipo(u32 battler)
{
    // Esquina superior izquierda de cada icono, en el orden de los movimientos.
    static const struct { u8 x, y; } sPosicionIconoTipo[MAXIMO_MOVIMIENTOS_POKEMON] =
    {
        {  9, 124}, {129, 124}, {  9, 148}, {129, 148},
    };
    struct DatosMovimiento *datosMovimiento = &gArgumentosComando[battler].datosMovimiento;
    bool32 hayQueCrear = FALSE;

    for (u32 i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        if (sIconTypeId[i] == 0xFF && datosMovimiento->movimiento[i] != MOVE_NONE)
            hayQueCrear = TRUE;
    }

    // Esto se llamaba en CADA movimiento del cursor, y con el rehacia ocho
    // descompresiones y volvia a pedir tiles para una hoja ya cargada, que se
    // reservaban de nuevo sin soltar los anteriores. Ahora solo se carga cuando
    // de verdad hay iconos que crear.
    if (!hayQueCrear)
        return;

    LoadPalettesTypes(battler);
    LoadCompressedSpriteSheet(&sSpriteSheet_IconTypes);
    LoadCompressedPalette(gIconTypes_Pal, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);

    for (u32 i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
    {
        u32 tipo;
        struct Sprite *icono;

        if (sIconTypeId[i] != 0xFF || datosMovimiento->movimiento[i] == MOVE_NONE)
            continue;

        sIconTypeId[i] = CreateSprite(&sSpriteTemplate_IconTypes,
                                      sPosicionIconoTipo[i].x, sPosicionIconoTipo[i].y, 0);
        if (sIconTypeId[i] >= MAX_SPRITES)
        {
            sIconTypeId[i] = 0xFF;
            continue;
        }

        tipo = gMovimientos[datosMovimiento->movimiento[i]].type;
        icono = &gSprites[sIconTypeId[i]];
        StartSpriteAnim(icono, tipo);
        icono->oam.paletteNum = sMoveTypeToOamPaletteNum[tipo];
        icono->oam.priority = 0;
        icono->subpriority = 1;
    }
}

static void MoveSelectionDisplayMoveType(u32 battler)
{
    sDuenoIconosTipoMasUno = battler + 1;
    AseguraIconosTipo(battler);
}

void CB2_SetUpReshowBattleScreenAfterMenu(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

void CB2_SetUpReshowBattleScreenAfterMenu2(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

void PlayerHandleLoadMonSprite(u32 battler)
{
    BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    gBattlerControllerFuncs[battler] = CompleteOnBattlerSpritePosX_0;
}

void PlayerHandleSwitchInAnim(u32 battler)
{
    gActionSelectionCursor[battler] = 0;
    gMoveSelectionCursor[battler] = 0;
    BtlController_HandleSwitchInAnim(battler, TRUE, SwitchIn_TryShinyAnimShowHealthbox);
}

static u32 PlayerGetTrainerBackPicId(void)
{
    u32 trainerPicId = gSaveBlockPtr->playerGender + TRAINER_BACK_PIC_BRENDAN;

    return trainerPicId;
}

// In emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven)
// that use an animated back pic.
void PlayerHandleDrawTrainerPic(u32 battler)
{
    s16 xPos = 80;
    u32 trainerPicId = PlayerGetTrainerBackPicId();
    s16 yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, FALSE, xPos, yPos, -1);
}

void PlayerHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId = PlayerGetTrainerBackPicId();
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

void PlayerHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 50, TRUE);
}



void PlayerHandleBallThrowAnim(u32 battler)
{
    BtlController_HandleBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW);
}


void PlayerHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler);
}

static void HandleChooseActionAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = ALTURA_PANTALLA;
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
    }
}

void PlayerHandleChooseAction(u32 battler)
{
    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;

    // El resaltado del menu no es un cursor sino un cambio de paleta de fondo, y
    // al volver de otra pantalla se recarga siempre la de "Luchar". Si no se
    // reinicia el indice, lo resaltado y lo elegido dejan de coincidir: se veia
    // Luchar y al pulsar A se abria el equipo.
    gActionSelectionCursor[battler] = 0;

    TryRestoreLastUsedBall();
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);

    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
    u32 personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
    monIconData = CreaIconoPokemon(species, 20, 132, 1, personality);
    gSprites[monIconData].oam.priority = 0;
    StartSpriteAnim(&gSprites[monIconData], 0);

    // El icono no carga paleta propia: usa la del combatiente, que ya esta
    // cargada en el hueco 'battler' y ya viene desplazada por su personalidad.
    // Antes se quedaba con el 0xFF que devuelve IndexOfSpritePaletteTag cuando no
    // encuentra la etiqueta, y ese valor en un campo de cuatro bits es la paleta
    // 15: de ahi que saliera negro, y que cambiara de color segun quien ocupara
    // ese hueco despues.
    gSprites[monIconData].oam.paletteNum = battler;

    // El icono se queda en el fotograma 0 y copia el bote del propio Pokemon. Con
    // un motor aparte iba a la misma velocidad pero arrancaba en otro fotograma,
    // asi que quedaba desfasado; copiando la y2 no puede desincronizarse.
    gSprites[monIconData].sIconoCombatiente = battler;
    gSprites[monIconData].callback = SpriteCB_IconoAccion;
}

void PlayerHandleYesNoBox(u32 battler)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR)
    {
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gPosicionCursorSiNo = CURSOR_NO; //REVISAR?
        CreaCursorBatallaSiNo();
        gBattlerControllerFuncs[battler] = PlayerHandleYesNoInput;
    }
    else
    {
        PlayerBufferExecCompleted(battler);
    }
}

void HandleChooseMoveAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = ALTURA_PANTALLA * 2;
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
    }
}

void PlayerHandleChooseMove(u32 battler)
{
    InitMoveSelectionsVarsAndStrings(battler);
    gBattlerControllerFuncs[battler] = HandleChooseMoveAfterDma3;
}

void InitMoveSelectionsVarsAndStrings(u32 battler)
{
        DestroySpriteAndFreeResources(&gSprites[monIconData]);
    MoveSelectionDisplayMoveNames(battler);
    MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler]);
    MoveSelectionDisplayPpNumber(battler);
    MoveSelectionDisplayMoveType(battler);
}

void PlayerHandleChoosePokemon(u32 battler)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gArgumentosComando[battler].datosEleccion[i];

    gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
    gTasks[gBattleControllerData[battler]].data[0] = gArgumentosComando[battler].caso & 0xF;
    gCombate->battlerPreventingSwitchout = gArgumentosComando[battler].caso >> 4;
    gCombate->prevSelectedPartySlot = gArgumentosComando[battler].ranura;
    gCombate->abilityPreventingSwitchout = gArgumentosComando[battler].habilidad;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
    gBattlerInMenuId = battler;
}

void PlayerHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler);
}

void PlayerHandleExpUpdate(u32 battler)
{
    u8 monId = gArgumentosComando[battler].indiceEquipo;
    s32 taskId, expPointsToGive;

    if (GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL) >= MAX_LEVEL)
    {
        PlayerBufferExecCompleted(battler);
    }
    else
    {
        expPointsToGive = gArgumentosComando[battler].experiencia;
        taskId = CreateTask(Task_GiveExpToMon, 10);
        gTasks[taskId].tExpTask_monId = monId;
        gTasks[taskId].tExpTask_gainedExp_1 = expPointsToGive;
        gTasks[taskId].tExpTask_gainedExp_2 = expPointsToGive >> 16;
        gTasks[taskId].tExpTask_battler = battler;
        gBattlerControllerFuncs[battler] = BattleControllerDummy;
    }
}

#undef tExpTask_monId
#undef tExpTask_battler
#undef tExpTask_gainedExp_1
#undef tExpTask_gainedExp_2
#undef tExpTask_frames







void PlayerHandleIntroTrainerBallThrow(u32 battler)
{
    const u32 *trainerPal = gTrainerBacksprites[gSaveBlockPtr->playerGender].palette.data;
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

void PlayerHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, LADO_JUGADOR, TRUE);
}

void PlayerHandleEndBounceEffect(u32 battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    PlayerBufferExecCompleted(battler);
}

void PlayerHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, TRUE);
}

void PlayerHandleResetActionMoveSelection(u32 battler)
{
    switch (gArgumentosComando[battler].caso)
    {
    case RESET_ACTION_MOVE_SELECTION:
        gActionSelectionCursor[battler] = 0;
        gMoveSelectionCursor[battler] = 0;
        break;
    case RESET_ACTION_SELECTION:
        gActionSelectionCursor[battler] = 0;
        break;
    case RESET_MOVE_SELECTION:
        gMoveSelectionCursor[battler] = 0;
        break;
    }
    PlayerBufferExecCompleted(battler);
}

static void Controller_WaitForDebug(u32 battler)
{
    // Basta con haber vuelto al combate; esperar ademas a que el fundido TERMINE
    // era lo que descuadraba la interfaz. Con esa espera, el menu de accion y el
    // icono no empezaban a montarse hasta que la pantalla ya se veia entera, asi
    // que aparecian varios fotogramas despues que el textbox y los Pokemon.
    // Quien abre el menu ya espera al fundido de salida antes de dejar aqui el
    // control, asi que esta condicion sola es suficiente.
    if (gMain.callback2 == BattleMainCB2)
    {
        PlayerBufferExecCompleted(battler);
    }
}

void PlayerHandleBattleDebug(u32 battler)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    SetMainCallback2(CB2_BattleDebugMenu);
    gBattlerControllerFuncs[battler] = Controller_WaitForDebug;
}

#include "global.h"
#include "gpu_regs.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "event_object_movement.h"
#include "constants/songs.h"

EWRAM_DATA struct MapPosition gPlayerFacingPosition = {0};

static void Task_ComputerScreenOpenEffect(u8);
static void Task_ComputerScreenCloseEffect(u8);
static void CreateComputerScreenEffectTask(TaskFunc, u16, u16, u8);

static void Task_WateringBerryTreeAnim_Start(u8);
static void Task_WateringBerryTreeAnim_Continue(u8);
static void Task_WateringBerryTreeAnim_End(u8);

// For accessing Pokémon storage PC or the Hall of Fame PC
void ComputerScreenOpenEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenOpenEffect, increment, unused, priority);
}

void ComputerScreenCloseEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenCloseEffect, increment, unused, priority);
}

bool8 IsComputerScreenOpenEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenOpenEffect);
}

bool8 IsComputerScreenCloseEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenCloseEffect);
}

#define tState         data[0]
#define tHorzIncrement data[1]
#define tVertIncrement data[2]
#define tWinLeft       data[3]
#define tWinRight      data[4]
#define tWinTop        data[5]
#define tWinBottom     data[6]
#define tBlendCnt      data[7]
#define tBlendY        data[8]

static void CreateComputerScreenEffectTask(void (*taskfunc) (u8), u16 increment, u16 unused, u8 priority)
{
    u8 taskId = CreateTask(taskfunc, priority);

    gTasks[taskId].tState = 0;
    gTasks[taskId].tHorzIncrement = increment == 0 ? 16 : increment;
    gTasks[taskId].tVertIncrement = increment == 0 ? 20 : increment;
    gTasks[taskId].func(taskId);
}

static void Task_ComputerScreenOpenEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWinLeft = ANCHO_PANTALLA / 2;
        task->tWinRight = ANCHO_PANTALLA / 2;
        task->tWinTop = ALTURA_PANTALLA / 2;
        task->tWinBottom = ALTURA_PANTALLA / 2 + 1;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);

        break;
    case 1:
        task->tBlendCnt = GetGpuReg(REG_OFFSET_BLDCNT);
        task->tBlendY = GetGpuReg(REG_OFFSET_BLDY);

        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 16);

        break;
    case 2:
        task->tWinLeft -= task->tHorzIncrement;
        task->tWinRight += task->tHorzIncrement;

        if (task->tWinLeft < 1 || task->tWinRight > ANCHO_PANTALLA - 1)
        {
            task->tWinLeft = 0;
            task->tWinRight = ANCHO_PANTALLA;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->tBlendCnt);
            BlendPalettes(PALETTES_ALL, 0, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != 0)
            return;
        break;
    case 3:
        task->tWinTop -= task->tVertIncrement;
        task->tWinBottom += task->tVertIncrement;

        if (task->tWinTop < 1 || task->tWinBottom > ALTURA_PANTALLA - 1)
        {
            task->tWinTop = 0;
            task->tWinBottom = ALTURA_PANTALLA;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != 0)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->tBlendCnt);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

static void Task_ComputerScreenCloseEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        gPlttBufferFaded[0] = 0;
        break;
    case 1:
        task->tWinLeft = 0;
        task->tWinRight = ANCHO_PANTALLA;
        task->tWinTop = 0;
        task->tWinBottom = ALTURA_PANTALLA;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->tWinTop += task->tVertIncrement;
        task->tWinBottom -= task->tVertIncrement;

        if (task->tWinTop >= ALTURA_PANTALLA / 2 || task->tWinBottom <= ALTURA_PANTALLA / 2 + 1)
        {
            task->tWinTop = ALTURA_PANTALLA / 2;
            task->tWinBottom = ALTURA_PANTALLA / 2 + 1;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 16);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != ALTURA_PANTALLA / 2)
            return;
        break;
    case 3:
        task->tWinLeft += task->tHorzIncrement;
        task->tWinRight -= task->tHorzIncrement;

        if (task->tWinLeft >= ANCHO_PANTALLA / 2 || task->tWinRight <= ANCHO_PANTALLA / 2)
        {
            task->tWinLeft = ANCHO_PANTALLA / 2;
            task->tWinRight = ANCHO_PANTALLA / 2;
            BlendPalettes(PALETTES_ALL, 16, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != ANCHO_PANTALLA / 2)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

#undef tState
#undef tHorzIncrement
#undef tVertIncrement
#undef tWinLeft
#undef tWinRight
#undef tWinTop
#undef tWinBottom
#undef tBlendCnt
#undef tBlendY

#define tState  data[0]
#define tMosaic data[1]

static void Task_FieldPoisonEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        tMosaic += 2;
        if (tMosaic > 8)
            tState++;
        break;
    case 1:
        tMosaic -= 2;
        if (tMosaic == 0)
            tState++;
        break;
    case 2:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_MOSAIC, (tMosaic << 4) | tMosaic);
}

#undef tState
#undef tMosaic

void FldEffPoison_Start(void)
{
    PlaySE(SE_FIELD_POISON);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 FldEffPoison_IsActive(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

static void Task_WateringBerryTreeAnim(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_Start;
}

static void Task_WateringBerryTreeAnim_Start(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObjEvent)
        || ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        // Start watering
        SetPlayerAvatarWatering(GetPlayerFacingDirection());
        ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_Continue;
    }
}

static void Task_WateringBerryTreeAnim_Continue(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        s16 value = gTasks[taskId].data[1]++;

        // Continue holding watering action 10 times, then end
        if (value < 10)
            ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_End;
    }
}

static void Task_WateringBerryTreeAnim_End(u8 taskId)
{
    SetPlayerAvatarTransitionFlags(GetPlayerAvatarFlags());
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim, 80);
}

#include "global.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "script_movement.h"
#include "task.h"
#include "trainer_see.h"
#include "constants/event_objects.h"

bool8 IsPlayerStandingStill(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION)
        return FALSE;
    else
        return TRUE;
}

// Freeze player once their movement is finished
static void Task_FreezePlayer(u8 taskId)
{
    if (IsPlayerStandingStill())
    {
        PlayerFreeze();
        DestroyTask(taskId);
    }
}

bool8 IsFreezePlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezePlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}


void FreezeObjects_WaitForPlayer(void)
{
    FreezeObjectEvents();
    CreateTask(Task_FreezePlayer, 80);
}

#define tPlayerFrozen data[0]
#define tObjectFrozen data[1]
#define tObjectId     data[2]

// Freeze selected object and player once their movement is finished
static void Task_FreezeSelectedObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!task->tPlayerFrozen && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->tPlayerFrozen = TRUE;
    }
    if (!task->tObjectFrozen && !gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        task->tObjectFrozen = TRUE;
    }
    if (task->tPlayerFrozen && task->tObjectFrozen)
        DestroyTask(taskId);
}

bool8 IsFreezeSelectedObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeSelectedObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}

// Freeze all objects immediately except the selected object and the player.
// The selected object and player are frozen once their movement is finished.
void FreezeObjects_WaitForPlayerAndSelected(void)
{
    u8 taskId;
    FreezeObjectEventsExceptOne(gSelectedObjectEvent);
    taskId = CreateTask(Task_FreezeSelectedObjectAndPlayer, 80);
    if (!gObjectEvents[gSelectedObjectEvent].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[gSelectedObjectEvent]);
        gTasks[taskId].tObjectFrozen = TRUE;
    }
}

void ScriptUnfreezeObjectEvents(void)
{
    u32 playerObjectId = GetObjectEventIdByLocalIdAndMap(LOCALID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
    ScriptMovement_UnfreezeObjectEvents();
    UnfreezeObjectEvents();
}

void Script_FacePlayer(void)
{
    ObjectEventFaceOppositeDirection(&gObjectEvents[gSelectedObjectEvent], gSpecialVar_Facing);
}

void Script_ClearHeldMovement(void)
{
    ObjectEventClearHeldMovementIfActive(&gObjectEvents[gSelectedObjectEvent]);
}

// Freeze designated object and player once their movement is finished
static void Task_FreezeObjectAndPlayer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u32 objectEventId = task->tObjectId;

    if (!task->tPlayerFrozen && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->tPlayerFrozen = TRUE;
    }
    if (!task->tObjectFrozen && !gObjectEvents[objectEventId].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[objectEventId]);
        task->tObjectFrozen = TRUE;
    }
    if (task->tPlayerFrozen && task->tObjectFrozen)
        DestroyTask(taskId);
}

// Freeze all objects immediately except the player and the approaching trainers.
// The approaching trainers and player are frozen once their movement is finished
void FreezeForApproachingTrainers(void)
{
    u8 trainerObjectId, taskId;
    struct ObjectEvent *followerObj = GetFollowerObject();
    trainerObjectId = gApproachingTrainer.objectEventId;

    FreezeObjectEventsExceptOne(trainerObjectId);
    taskId = CreateTask(Task_FreezeObjectAndPlayer, 80);
    gTasks[taskId].tObjectId = trainerObjectId;
    if (!gObjectEvents[trainerObjectId].singleMovementActive)
    {
        FreezeObjectEvent(&gObjectEvents[trainerObjectId]);
        gTasks[taskId].tObjectFrozen = TRUE;
    }
    if (followerObj) // Unfreeze follower so it can move behind player
        UnfreezeObjectEvent(followerObj);
}

bool8 IsFreezeObjectAndPlayerFinished(void)
{
    if (FuncIsActiveTask(Task_FreezeObjectAndPlayer))
    {
        return FALSE;
    }
    else
    {
        StopPlayerAvatar();
        return TRUE;
    }
}

#undef tPlayerFrozen
#undef tObjectFrozen
#undef tObjectId

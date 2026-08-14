#include "global.h"
#include "play_time.h"
#include "rtc.h"

enum
{
    STOPPED,
    RUNNING,
    MAXED_OUT
};

static u8 sPlayTimeCounterState;

void PlayTimeCounter_Reset(void)
{
    sPlayTimeCounterState = STOPPED;

    gSaveBlockPtr->playTimeHours = 0;
    gSaveBlockPtr->playTimeMinutes = 0;
    gSaveBlockPtr->playTimeSeconds = 0;
    gSaveBlockPtr->playTimeVBlanks = 0;
}

void PlayTimeCounter_Start(void)
{
    sPlayTimeCounterState = RUNNING;

    if (gSaveBlockPtr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_Stop(void)
{
    sPlayTimeCounterState = STOPPED;
}

void PlayTimeCounter_Update(void)
{
    if (sPlayTimeCounterState != RUNNING)
        return;

    gSaveBlockPtr->playTimeVBlanks++;

    if (gSaveBlockPtr->playTimeVBlanks < 60)
        return;

    gSaveBlockPtr->playTimeVBlanks = 0;
    gSaveBlockPtr->playTimeSeconds++;
    Rtc_TickTimeForward();

    if (gSaveBlockPtr->playTimeSeconds < 60)
        return;

    gSaveBlockPtr->playTimeSeconds = 0;
    gSaveBlockPtr->playTimeMinutes++;

    if (gSaveBlockPtr->playTimeMinutes < 60)
        return;

    gSaveBlockPtr->playTimeMinutes = 0;
    gSaveBlockPtr->playTimeHours++;

    if (gSaveBlockPtr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_SetToMax(void)
{
    sPlayTimeCounterState = MAXED_OUT;

    gSaveBlockPtr->playTimeHours = 999;
    gSaveBlockPtr->playTimeMinutes = 59;
    gSaveBlockPtr->playTimeSeconds = 59;
    gSaveBlockPtr->playTimeVBlanks = 59;
}

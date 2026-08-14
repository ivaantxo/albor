#include "global.h"
#include "rtc.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "event_data.h"

// iwram common
COMMON_DATA struct Time gLocalTime = {0};

// This fork has no real-hardware RTC: time only exists as an in-game clock
// that advances while the game is running, driven by PlayTimeCounter_Update's
// frame counter (see Rtc_TickTimeForward).
struct Time *Rtc_GetCurrentTime(void)
{
    return &gSaveBlockPtr->gameClock;
}

void Rtc_TickTimeForward(void)
{
    if (FlagGet(OW_FLAG_PAUSE_TIME))
        return;

    Rtc_AdvanceTimeBy(0, 0, Rtc_GetSecondsRatio());
}

void Rtc_AdvanceTimeBy(u32 hours, u32 minutes, u32 seconds)
{
    struct Time *time = Rtc_GetCurrentTime();
    seconds += time->seconds;
    minutes += time->minutes;
    hours += time->hours;

    while (seconds >= SEGUNDOS_POR_MINUTO)
    {
        minutes++;
        seconds -= SEGUNDOS_POR_MINUTO;
    }

    while (minutes >= MINUTOS_POR_HORA)
    {
        hours++;
        minutes -= MINUTOS_POR_HORA;
    }

    while (hours >= HORAS_POR_DIA)
    {
        time->days++;
        hours -= HORAS_POR_DIA;
    }

    time->seconds = seconds;
    time->minutes = minutes;
    time->hours = hours;
}

u32 Rtc_GetSecondsRatio(void)
{
    return 20;
}

void RtcReset(void)
{
    memset(Rtc_GetCurrentTime(), 0, sizeof(struct Time));
}

void FormatDecimalTime(u8 *dest, s32 hour, s32 minute, s32 second)
{
    dest = ConvertIntToDecimalStringN(dest, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToDecimalStringN(dest, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToDecimalStringN(dest, second, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest = EOS;
}

void FormatHexTime(u8 *dest, s32 hour, s32 minute, s32 second)
{
    dest = ConvertIntToHexStringN(dest, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToHexStringN(dest, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_COLON;
    dest = ConvertIntToHexStringN(dest, second, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest = EOS;
}

void FormatDecimalDate(u8 *dest, s32 year, s32 month, s32 day)
{
    dest = ConvertIntToDecimalStringN(dest, year, STR_CONV_MODE_LEADING_ZEROS, 4);
    *dest++ = CHAR_HYPHEN;
    dest = ConvertIntToDecimalStringN(dest, month, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_HYPHEN;
    dest = ConvertIntToDecimalStringN(dest, day, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest = EOS;
}

void FormatHexDate(u8 *dest, s32 year, s32 month, s32 day)
{
    dest = ConvertIntToHexStringN(dest, year, STR_CONV_MODE_LEADING_ZEROS, 4);
    *dest++ = CHAR_HYPHEN;
    dest = ConvertIntToHexStringN(dest, month, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest++ = CHAR_HYPHEN;
    dest = ConvertIntToHexStringN(dest, day, STR_CONV_MODE_LEADING_ZEROS, 2);
    *dest = EOS;
}

void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2)
{
    result->seconds = t2->seconds - t1->seconds;
    result->minutes = t2->minutes - t1->minutes;
    result->hours = t2->hours - t1->hours;
    result->days = t2->days - t1->days;

    if (result->seconds < 0)
    {
        result->seconds += SEGUNDOS_POR_MINUTO;
        --result->minutes;
    }

    if (result->minutes < 0)
    {
        result->minutes += MINUTOS_POR_HORA;
        --result->hours;
    }

    if (result->hours < 0)
    {
        result->hours += HORAS_POR_DIA;
        --result->days;
    }
}

void RtcCalcLocalTime(void)
{
    CalcTimeDifference(&gLocalTime, &gSaveBlockPtr->localTimeOffset, Rtc_GetCurrentTime());
}

bool8 IsBetweenHours(s32 hours, s32 begin, s32 end)
{
    if (end < begin)
        return hours >= begin || hours < end;
    else
        return hours >= begin && hours < end;
}

u8 GetTimeOfDay(void)
{
    RtcCalcLocalTime();
    if (IsBetweenHours(gLocalTime.hours, HORA_INICIO_MANANA, HORA_FINAL_MANANA))
        return TIEMPO_MANANA;
    else if (IsBetweenHours(gLocalTime.hours, HORA_INICIO_TARDE, HORA_FINAL_TARDE))
        return TIEMPO_TARDE;
    else if (IsBetweenHours(gLocalTime.hours, HORA_INICIO_NOCHE, HORA_FINAL_NOCHE))
        return TIEMPO_NOCHE;
    return TIEMPO_DIA;
}

void RtcInitLocalTimeOffset(s32 hour, s32 minute)
{
    RtcCalcLocalTimeOffset(0, hour, minute, 0);
}

void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds)
{
    gLocalTime.days = days;
    gLocalTime.hours = hours;
    gLocalTime.minutes = minutes;
    gLocalTime.seconds = seconds;
    CalcTimeDifference(&gSaveBlockPtr->localTimeOffset, &gLocalTime, Rtc_GetCurrentTime());
}

void FormatDecimalTimeWithoutSeconds(u8 *txtPtr, s8 hour, s8 minute, bool32 is24Hour)
{
    if (is24Hour)
    {
        txtPtr = ConvertIntToDecimalStringN(txtPtr, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        *txtPtr++ = CHAR_COLON;
        txtPtr = ConvertIntToDecimalStringN(txtPtr, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
    }
    else
    {
        if (hour == 0)
            txtPtr = ConvertIntToDecimalStringN(txtPtr, 12, STR_CONV_MODE_LEADING_ZEROS, 2);
        else if (hour < 13)
            txtPtr = ConvertIntToDecimalStringN(txtPtr, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        else
            txtPtr = ConvertIntToDecimalStringN(txtPtr, hour - 12, STR_CONV_MODE_LEADING_ZEROS, 2);

        *txtPtr++ = CHAR_COLON;
        txtPtr = ConvertIntToDecimalStringN(txtPtr, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
        txtPtr = StringAppend(txtPtr, COMPOUND_STRING(" "));
        if (hour < 12)
            txtPtr = StringAppend(txtPtr, gText_AM);
        else
            txtPtr = StringAppend(txtPtr, gText_PM);
    }

    *txtPtr++ = EOS;
    *txtPtr = EOS;
}

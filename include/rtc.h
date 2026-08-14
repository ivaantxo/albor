#ifndef GUARD_RTC_UTIL_H
#define GUARD_RTC_UTIL_H

#define HORAS_POR_DIA        24
#define MINUTOS_POR_HORA     60
#define SEGUNDOS_POR_MINUTO  60

#define HORA_INICIO_MANANA          6
#define HORA_MEDIA_MANANA           8
#define HORA_FINAL_MANANA           10

#define HORA_INICIO_DIA             10
#define HORA_FINAL_DIA              18

#define HORA_INICIO_TARDE           18
#define HORA_MEDIA_TARDE            20
#define HORA_FINAL_TARDE            22

#define HORA_INICIO_NOCHE           22
#define HORA_FINAL_NOCHE            6

#define TIEMPO_MANANA               0
#define TIEMPO_DIA                  1
#define TIEMPO_TARDE                2
#define TIEMPO_NOCHE                3

extern struct Time gLocalTime;

struct Time *Rtc_GetCurrentTime(void);
void Rtc_AdvanceTimeBy(u32 hours, u32 minutes, u32 seconds);
void Rtc_TickTimeForward(void);
u32 Rtc_GetSecondsRatio(void);
void RtcReset(void);
void FormatDecimalTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatDecimalDate(u8 *dest, s32 year, s32 month, s32 day);
void FormatHexDate(u8 *dest, s32 year, s32 month, s32 day);
void RtcCalcLocalTime(void);
bool8 IsBetweenHours(s32 hours, s32 begin, s32 end);
u8 GetTimeOfDay(void);
void RtcInitLocalTimeOffset(s32 hour, s32 minute);
void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds);
void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2);
void FormatDecimalTimeWithoutSeconds(u8 *dest, s8 hour, s8 minute, bool32 is24Hour);

#endif // GUARD_RTC_UTIL_H

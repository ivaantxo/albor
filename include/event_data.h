#ifndef GUARD_EVENT_DATA_H
#define GUARD_EVENT_DATA_H

void InitEventData(void);
void ClearTempFieldEventData(void);
void ClearDailyFlags(void);
void DisableResetRTC(void);
void EnableResetRTC(void);
bool32 CanResetRTC(void);
u16 *GetVarPointer(u16 id);
u16 VarGet(u16 id);
u16 VarGetIfExist(u16 id);
bool8 VarSet(u16 id, u16 value);
u16 VarGetObjectEventGraphicsId(u8 id);
u8 *GetFlagPointer(u32);
u8 *GetTrainerFlagPointer(u32);
u32 FlagSet(u32);
u32 TrainerFlagSet(u32);
u32 FlagToggle(u32);
u32 FlagClear(u32);
u32 TrainerFlagClear(u32);
bool32 FlagGet(u32);
bool32 TrainerFlagGet(u32);

extern u16 gSpecialVar_0x8000;
extern u16 gSpecialVar_0x8001;
extern u16 gSpecialVar_0x8002;
extern u16 gSpecialVar_0x8003;
extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
extern u16 gSpecialVar_0x8006;
extern u16 gSpecialVar_0x8007;
extern u16 gSpecialVar_0x8008;
extern u16 gSpecialVar_0x8009;
extern u16 gSpecialVar_0x800A;
extern u16 gSpecialVar_0x800B;
extern u16 gSpecialVar_Result;
extern u16 gSpecialVar_LastTalked;
extern u16 gSpecialVar_Facing;
extern u16 gSpecialVar_MonBoxId;
extern u16 gSpecialVar_MonBoxPos;

#endif // GUARD_EVENT_DATA_H

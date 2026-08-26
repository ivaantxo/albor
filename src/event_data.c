#include "global.h"
#include "event_data.h"
#include "pokedex.h"

// Hacia arriba: con menos de ocho banderas especiales la division daba cero y el
// array se quedaba sin un solo byte donde escribir.
#define SPECIAL_FLAGS_SIZE  ROUND_BITS_TO_BYTES(NUM_SPECIAL_FLAGS)
#define TEMP_VARS_SIZE      (NUM_TEMP_VARS * 2)      // 1/2 var per byte

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_Result = 0;
EWRAM_DATA u16 gSpecialVar_LastTalked = 0;
EWRAM_DATA u16 gSpecialVar_Facing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA static u8 sSpecialFlags[SPECIAL_FLAGS_SIZE] = {0};

extern u16 *const gSpecialVars[];

void InitEventData(void)
{
    memset(&gSaveBlockPtr->banderas, 0, sizeof(gSaveBlockPtr->banderas));
    memset(gSaveBlockPtr->vars, 0, sizeof(gSaveBlockPtr->vars));
    memset(sSpecialFlags, 0, sizeof(sSpecialFlags));
}

void ClearTempFieldEventData(void)
{
    memset(gSaveBlockPtr->banderas.temporales, 0, sizeof(gSaveBlockPtr->banderas.temporales));
    memset(&gSaveBlockPtr->vars[TEMP_VARS_START - VARS_START], 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
}

void ClearDailyFlags(void)
{
    memset(gSaveBlockPtr->banderas.diarias, 0, sizeof(gSaveBlockPtr->banderas.diarias));
    // Los entrenadores tambien: en este proyecto todos vuelven a ser combatibles cada
    // dia, no solo los revanchistas como en vanilla.
    memset(gSaveBlockPtr->banderas.entrenadores, 0, sizeof(gSaveBlockPtr->banderas.entrenadores));
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < VARS_START)
        return NULL;
    else if (id < SPECIAL_VARS_START)
        return &gSaveBlockPtr->vars[id - VARS_START];
    else
        return gSpecialVars[id - SPECIAL_VARS_START];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

u16 VarGetIfExist(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return 65535;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u16 VarGetObjectEventGraphicsId(u8 id)
{
    return VarGet(VAR_OBJ_GFX_ID_0 + id);
}

// Traduce el identificador de una bandera al byte que la contiene. Es el unico sitio
// donde vive el reparto por familias: el resto del juego solo maneja el numero.
u8 *GetFlagPointer(u32 id)
{
    struct BanderasGuardadas *b = &gSaveBlockPtr->banderas;

    if (id == 0)
        return NULL;                        // el 0 significa "sin bandera"

    if (id <= TEMP_FLAGS_END)
        return &b->temporales[id / 8];

    if (id < SYSTEM_FLAGS)
        return &b->guion[(id - (TEMP_FLAGS_END + 1)) / 8];

    if (id < DAILY_FLAGS_START)
        return &b->sistema[(id - SYSTEM_FLAGS) / 8];

    if (id < SPECIAL_FLAGS_START)
        return &b->diarias[(id - DAILY_FLAGS_START) / 8];

    return &sSpecialFlags[(id - SPECIAL_FLAGS_START) / 8];
}

u8 *GetTrainerFlagPointer(u32 id)
{
    if (id == 0 || id >= TRAINERS_COUNT)
        return NULL;

    return &gSaveBlockPtr->banderas.entrenadores[id / 8];
}

u32 FlagSet(u32 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u32 TrainerFlagSet(u32 id)
{
    u8 *ptr = GetTrainerFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id % 8);
    return 0;
}

u32 FlagToggle(u32 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr ^= 1 << (id & 7);
    return 0;
}

u32 FlagClear(u32 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

u32 TrainerFlagClear(u32 id)
{
    u8 *ptr = GetTrainerFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id % 8));
    return 0;
}

bool32 FlagGet(u32 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}

bool32 TrainerFlagGet(u32 id)
{
    u8 *ptr = GetTrainerFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id % 8)) & 1))
        return FALSE;

    return TRUE;
}

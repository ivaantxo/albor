#include "global.h"
#include "debug.h"
#include "malloc.h"
#include "battle.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "load_save.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tilesets.h"
#include "wallclock.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/map_types.h"
#include "constants/songs.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/weather.h"
#include "constants/metatile_labels.h"
#include "palette.h"
#include "battle_util.h"



EWRAM_DATA bool8 gBikeCyclingChallenge = FALSE;
EWRAM_DATA u8 gBikeCollisions = 0;
static EWRAM_DATA u32 sBikeCyclingTimer = 0;
static EWRAM_DATA u8 sSlidingDoorNextFrameCounter = 0;
static EWRAM_DATA u8 sSlidingDoorFrame = 0;

static EWRAM_DATA u8 sPCBoxToSendMon = 0;


void TryLoseFansFromPlayTime(void);
void SetPlayerGotFirstFans(void);
u16 GetNumFansOfPlayerInTrainerFanClub(void);

static void RecordCyclingRoadResults(u32, u8);
static void Task_PetalburgGymSlideOpenRoomDoors(u8);
static void PetalburgGymSetDoorMetatiles(u8, u16);
static void Task_PCTurnOnEffect(u8);
static void PCTurnOnEffect(struct Task *);
static void PCTurnOnEffect_SetMetatile(s16, s8, s8);
static void PCTurnOffEffect(void);
static void Task_LotteryCornerComputerEffect(u8);
static void LotteryCornerComputerEffect(struct Task *);
static void Task_ShakeCamera(u8);
static void StopCameraShake(u8);
static void Task_DeoxysRockInteraction(u8);
static void ChangeDeoxysRockLevel(u8);
static void Task_LoopWingFlapSE(u8);
static void SetInitialFansOfPlayer(void);

void Special_ViewWallClock(void)
{
    gMain.savedCallback = CB2_ReturnToField;
    SetMainCallback2(CB2_ViewWallClock);
    LockPlayerFieldControls();
}

void Special_BeginCyclingRoadChallenge(void)
{
    gBikeCyclingChallenge = TRUE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = gMain.vblankCounter;
}

u16 GetPlayerAvatarBike(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        return 1;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        return 2;
    return 0;
}

static void DetermineCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u8 result;

    if (numBikeCollisions < 100)
    {
        ConvertIntToDecimalStringN(gVariableTexto1, numBikeCollisions, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gVariableTexto1, gText_SpaceTimes);
    }
    else
    {
        StringCopy(gVariableTexto1, gText_99TimesPlus);
    }

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gVariableTexto2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gVariableTexto2[2] = CHAR_COMMA;
        ConvertIntToDecimalStringN(&gVariableTexto2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gVariableTexto2, gText_SpaceSeconds);
    }
    else
    {
        StringCopy(gVariableTexto2, gText_1MinutePlus);
    }

    result = 0;
    if (numBikeCollisions == 0)
        result = 5;
    else if (numBikeCollisions < 4)
        result = 4;
    else if (numBikeCollisions < 10)
        result = 3;
    else if (numBikeCollisions < 20)
        result = 2;
    else if (numBikeCollisions < 100)
        result = 1;

    if (numFrames / 60 <= 10)
        result += 5;
    else if (numFrames / 60 <= 15)
        result += 4;
    else if (numFrames / 60 <= 20)
        result += 3;
    else if (numFrames / 60 <= 40)
        result += 2;
    else if (numFrames / 60 < 60)
        result += 1;

    gSpecialVar_Result = result;
}

void FinishCyclingRoadChallenge(void)
{
    const u32 numFrames = gMain.vblankCounter - sBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
}

static void RecordCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord > numFrames || framesRecord == 0)
    {
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_L, numFrames);
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_H, numFrames >> 16);
        VarSet(VAR_CYCLING_ROAD_RECORD_COLLISIONS, numBikeCollisions);
    }
}

u16 GetRecordedCyclingRoadResults(void)
{
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord == 0)
        return FALSE;

    DetermineCyclingRoadResults(framesRecord, VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void)
{

}

void SetSSTidalFlag(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    *GetVarPointer(VAR_CRUISE_STEP_COUNT) = 0;
}

void ResetSSTidalFlag(void)
{
    FlagClear(FLAG_SYS_CRUISE_MODE);
}

// Returns TRUE if the Cruise is over
bool32 CountSSTidalStep(u16 delta)
{
    if (!FlagGet(FLAG_SYS_CRUISE_MODE) || (*GetVarPointer(VAR_CRUISE_STEP_COUNT) += delta) < SS_TIDAL_MAX_STEPS)
        return FALSE;

    return TRUE;
}

u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y)
{
    return 0;
}

bool32 ShouldDoWallyCall(void)
{
    if (FlagGet(FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_WALLY_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottFortreeCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_FORTREE_GYM))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_SCOTT_FORTREE_CALL_STEP_COUNTER)) < 10)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRoxanneCall(void)
{
    if (FlagGet(FLAG_ENABLE_ROXANNE_FIRST_CALL))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_ROXANNE_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRivalRayquazaCall(void)
{
    if (FlagGet(FLAG_DEFEATED_MAGMA_SPACE_CENTER))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

static const struct UCoords8 sMauvilleGymSwitchCoords[] =
{
    { 0 + MAP_OFFSET, 15 + MAP_OFFSET},
    { 4 + MAP_OFFSET, 12 + MAP_OFFSET},
    { 3 + MAP_OFFSET,  9 + MAP_OFFSET},
    { 8 + MAP_OFFSET,  9 + MAP_OFFSET}
};

// Presses the stepped-on switch and raises the rest
void MauvilleGymPressSwitch(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sMauvilleGymSwitchCoords); i++)
    {
        if (i == gSpecialVar_0x8004)
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_MauvilleGym_PressedSwitch);
        else
            MapGridSetMetatileIdAt(sMauvilleGymSwitchCoords[i].x, sMauvilleGymSwitchCoords[i].y, METATILE_MauvilleGym_RaisedSwitch);
    }
}

// Sets the gym barriers back to the default state; their alt state is handled by MauvilleCity_Gym_EventScript_SetAltBarriers
void MauvilleGymSetDefaultBarriers(void)
{
    int x, y;
    // All switches/barriers are within these coord ranges
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_MauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_On);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_On);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH1_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_On);
                break;
            case METATILE_MauvilleGym_RedBeamH2_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_On);
                break;
            case METATILE_MauvilleGym_RedBeamH3_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_RedBeamH4_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_GreenBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_Off | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_PoleBottom_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamV1_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_FloorTile:
                if (MapGridGetMetatileIdAt(x, y - 1) == METATILE_MauvilleGym_GreenBeamV1_On)
                    MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamV2_On | MAPGRID_COLLISION_MASK);
                else
                    MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamV2_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_PoleBottom_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamV1_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_PoleTop_Off:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_Off);
                break;
            }
        }
    }
}

// Presses all switches and deactivates all beams.
void MauvilleGymDeactivatePuzzle(void)
{
    u32 i, x, y;
    const struct UCoords8 *switchCoords = sMauvilleGymSwitchCoords;
    // 'i' es u32, asi que 'i >= 0' seria siempre cierto y el bucle no terminaria
    // nunca: al llegar a cero el i-- daria 0xFFFFFFFF y switchCoords se saldria del
    // array escribiendo metatiles en coordenadas basura. Con 'i-- > 0' la condicion
    // se evalua antes de restar, que es la forma correcta de contar hacia atras sin
    // signo.
    for (i = ARRAY_COUNT(sMauvilleGymSwitchCoords); i-- > 0;)
    {
        MapGridSetMetatileIdAt(switchCoords->x, switchCoords->y, METATILE_MauvilleGym_PressedSwitch);
        switchCoords++;
    }
    for (y = 5 + MAP_OFFSET; y < 17 + MAP_OFFSET; y++)
    {
        for (x = 0 + MAP_OFFSET; x < 9 + MAP_OFFSET; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
            case METATILE_MauvilleGym_GreenBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH1_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH2_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH3_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_GreenBeamH4_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH1_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH2_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH3_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH3_Off);
                break;
            case METATILE_MauvilleGym_RedBeamH4_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_RedBeamH4_Off);
                break;
            case METATILE_MauvilleGym_GreenBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_On | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_RedBeamV1_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleBottom_Off | MAPGRID_COLLISION_MASK);
                break;
            case METATILE_MauvilleGym_GreenBeamV2_On:
            case METATILE_MauvilleGym_RedBeamV2_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_FloorTile);
                break;
            case METATILE_MauvilleGym_PoleTop_On:
                MapGridSetMetatileIdAt(x, y, METATILE_MauvilleGym_PoleTop_Off);
                break;
            }
        }
    }
}

static const bool8 sSlidingDoorNextFrameDelay[] = {0, 1, 1, 1, 1};

static const u16 sPetalburgGymSlidingDoorMetatiles[] = {
    METATILE_PetalburgGym_SlidingDoor_Frame0,
    METATILE_PetalburgGym_SlidingDoor_Frame1,
    METATILE_PetalburgGym_SlidingDoor_Frame2,
    METATILE_PetalburgGym_SlidingDoor_Frame3,
    METATILE_PetalburgGym_SlidingDoor_Frame4,
};

void PetalburgGymSlideOpenRoomDoors(void)
{
    sSlidingDoorNextFrameCounter = 0;
    sSlidingDoorFrame = 0;
    PlaySE(SE_UNLOCK);
    CreateTask(Task_PetalburgGymSlideOpenRoomDoors, 8);
}

static void Task_PetalburgGymSlideOpenRoomDoors(u8 taskId)
{
    if (sSlidingDoorNextFrameDelay[sSlidingDoorFrame] == sSlidingDoorNextFrameCounter)
    {
        PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[sSlidingDoorFrame]);
        sSlidingDoorNextFrameCounter = 0;
        if ((++sSlidingDoorFrame) == ARRAY_COUNT(sPetalburgGymSlidingDoorMetatiles))
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
    }
    else
    {
        sSlidingDoorNextFrameCounter++;
    }
}

static void PetalburgGymSetDoorMetatiles(u8 roomNumber, u16 metatileId)
{
    u16 doorCoordsX[4];
    u16 doorCoordsY[4];
    u32 i;
    u8 nDoors = 0;
    switch (roomNumber)
    {
    case 1:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 104;
        doorCoordsY[1] = 104;
        break;
    case 2:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 78;
        doorCoordsY[1] = 78;
        break;
    case 3:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 91;
        doorCoordsY[1] = 91;
        break;
    case 4:
        nDoors = 1;
        doorCoordsX[0] = 7;
        doorCoordsY[0] = 39;
        break;
    case 5:
        nDoors = 2;
        doorCoordsX[0] = 1;
        doorCoordsX[1] = 7;
        doorCoordsY[0] = 52;
        doorCoordsY[1] = 52;
        break;
    case 6:
        nDoors = 1;
        doorCoordsX[0] = 1;
        doorCoordsY[0] = 65;
        break;
    case 7:
        nDoors = 1;
        doorCoordsX[0] = 7;
        doorCoordsY[0] = 13;
        break;
    case 8:
        nDoors = 1;
        doorCoordsX[0] = 1;
        doorCoordsY[0] = 26;
        break;
    }
    for (i = 0; i < nDoors; i++)
    {
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET, metatileId | MAPGRID_COLLISION_MASK);
        MapGridSetMetatileIdAt(doorCoordsX[i] + MAP_OFFSET, doorCoordsY[i] + MAP_OFFSET + 1, (metatileId + METATILE_ROW_WIDTH) | MAPGRID_COLLISION_MASK);
    }
    DrawWholeMapView();
}

void PetalburgGymUnlockRoomDoors(void)
{
    PetalburgGymSetDoorMetatiles(gSpecialVar_0x8004, sPetalburgGymSlidingDoorMetatiles[4]);
}

void ShowFieldMessageStringVar4(void)
{
    ShowFieldMessage(gVariableTextoAmpliada);
}

void StorePlayerCoordsInVars(void)
{
    gSpecialVar_0x8004 = gSaveBlockPtr->pos.x;
    gSpecialVar_0x8005 = gSaveBlockPtr->pos.y;
}

void GetPlayerBigGuyGirlString(void)
{
    if (gSaveBlockPtr->playerGender == MALE)
        StringCopy(gVariableTexto1, gText_BigGuy);
    else
        StringCopy(gVariableTexto1, gText_BigGirl);
}

void GetRivalSonDaughterString(void)
{
    if (gSaveBlockPtr->playerGender == MALE)
        StringCopy(gVariableTexto1, gText_Daughter);
    else
        StringCopy(gVariableTexto1, gText_Son);
}

void SetHiddenItemFlag(void)
{
    FlagSet(gSpecialVar_0x8004);
}

u16 GetWeekCount(void)
{
    u16 weekCount = gLocalTime.days / 7;
    if (weekCount > 9999)
        weekCount = 9999;

    return weekCount;
}

u8 GetLeadMonFriendshipScore(void)
{
    return GetMonFriendshipScore(&gPlayerParty[GetLeadMonIndex()]);
}

static void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}

static bool32 IsBuildingPCTile(u32 tileId)
{
    return gMapHeader.mapLayout->primaryTileset == &gTileset_Building && (tileId == METATILE_Building_PC_On || tileId == METATILE_Building_PC_Off);
}

static bool32 IsPlayerHousePCTile(u32 tileId)
{
    return gMapHeader.mapLayout->secondaryTileset == &gTileset_BrendansMaysHouse
        && (tileId == METATILE_BrendansMaysHouse_BrendanPC_On
            || tileId == METATILE_BrendansMaysHouse_BrendanPC_Off
            || tileId == METATILE_BrendansMaysHouse_MayPC_On
            || tileId == METATILE_BrendansMaysHouse_MayPC_Off);
}

static bool8 IsPlayerInFrontOfPC(void)
{
    s16 x, y;
    u32 tileInFront;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tileInFront = MapGridGetMetatileIdAt(x, y);

    return IsBuildingPCTile(tileInFront) || IsPlayerHousePCTile(tileInFront);
}

// Task data for Task_PCTurnOnEffect and Task_LotteryCornerComputerEffect
#define tPaused       data[0] // Never set
#define tTaskId       data[1]
#define tFlickerCount data[2]
#define tTimer        data[3]
#define tIsScreenOn   data[4]

// For this special, gSpecialVar_0x8004 is expected to be some PC_LOCATION_* value.
void DoPCTurnOnEffect(void)
{
    if (FuncIsActiveTask(Task_PCTurnOnEffect) != TRUE && IsPlayerInFrontOfPC() == TRUE)
    {
        u8 taskId = CreateTask(Task_PCTurnOnEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

static void Task_PCTurnOnEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        PCTurnOnEffect(task);
}

static void PCTurnOnEffect(struct Task *task)
{
    u8 playerDirection;
    s8 dx = 0;
    s8 dy = 0;
    if (task->tTimer == 6)
    {
        task->tTimer = 0;

        // Get where the PC should be, depending on where the player is looking.
        playerDirection = GetPlayerFacingDirection();
        switch (playerDirection)
        {
        case DIR_NORTH:
            dx = 0;
            dy = -1;
            break;
        case DIR_WEST:
            dx = -1;
            dy = -1;
            break;
        case DIR_EAST:
            dx = 1;
            dy = -1;
            break;
        }

        // Update map
        PCTurnOnEffect_SetMetatile(task->tIsScreenOn, dx, dy);
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

static void PCTurnOnEffect_SetMetatile(s16 isScreenOn, s8 dx, s8 dy)
{
    u16 metatileId = 0;
    if (isScreenOn)
    {
        // Screen is on, set it off
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = METATILE_Building_PC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_Off;
    }
    else
    {
        // Screen is off, set it on
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = METATILE_Building_PC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_On;
    }
    MapGridSetMetatileIdAt(gSaveBlockPtr->pos.x + dx + MAP_OFFSET, gSaveBlockPtr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_COLLISION_MASK);
}

// For this special, gSpecialVar_0x8004 is expected to be some PC_LOCATION_* value.
void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}

static void PCTurnOffEffect(void)
{
    s8 dx = 0;
    s8 dy = 0;
    u16 metatileId = 0;

    // Get where the PC should be, depending on where the player is looking.
    u8 playerDirection = GetPlayerFacingDirection();

    if (IsPlayerInFrontOfPC() == FALSE)
        return;
    switch (playerDirection)
    {
    case DIR_NORTH:
        dx = 0;
        dy = -1;
        break;
    case DIR_WEST:
        dx = -1;
        dy = -1;
        break;
    case DIR_EAST:
        dx = 1;
        dy = -1;
        break;
    }

    if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
        metatileId = METATILE_Building_PC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_MayPC_Off;

    MapGridSetMetatileIdAt(gSaveBlockPtr->pos.x + dx + MAP_OFFSET, gSaveBlockPtr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
}

void DoLotteryCornerComputerEffect(void)
{
    if (FuncIsActiveTask(Task_LotteryCornerComputerEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_LotteryCornerComputerEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

static void Task_LotteryCornerComputerEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        LotteryCornerComputerEffect(task);
}

static void LotteryCornerComputerEffect(struct Task *task)
{
    if (task->tTimer == 6)
    {
        task->tTimer = 0;
        if (task->tIsScreenOn)
        {
            // Screen is on, set it off
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_COLLISION_MASK);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_COLLISION_MASK);
        }
        else
        {
            // Screen is off, set it on
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Flash | MAPGRID_COLLISION_MASK);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Flash | MAPGRID_COLLISION_MASK);
        }
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

void EndLotteryCornerComputerEffect(void)
{
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
}

#undef tPaused
#undef tTaskId
#undef tFlickerCount
#undef tTimer
#undef tIsScreenOn

bool8 CheckLeadMonCool(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_COOL) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonBeauty(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_BEAUTY) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonCute(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_CUTE) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonSmart(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_SMART) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonTough(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_TOUGH) < 200)
        return FALSE;

    return TRUE;
}

void IsGrassTypeInParty(void)
{
    u32 i;
    u16 species;
    struct Pokemon *pokemon;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            if (gSpeciesInfo[species].types[TIPO_1] == TIPO_PLANTA || gSpeciesInfo[species].types[TIPO_2] == TIPO_PLANTA)
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }
    gSpecialVar_Result = FALSE;
}

void SpawnCameraObject(void)
{
    u8 obj = SpawnSpecialObjectEventParameterized(OBJ_EVENT_GFX_BOY_1,
                                                  MOVEMENT_TYPE_FACE_DOWN,
                                                  LOCALID_CAMERA,
                                                  gSaveBlockPtr->pos.x + MAP_OFFSET,
                                                  gSaveBlockPtr->pos.y + MAP_OFFSET,
                                                  3); // elevation
    gObjectEvents[obj].invisible = TRUE;
    CameraObjectSetFollowedSpriteId(gObjectEvents[obj].spriteId);
}

void RemoveCameraObject(void)
{
    CameraObjectSetFollowedSpriteId(GetPlayerAvatarSpriteId());
    RemoveObjectEventByLocalIdAndMap(LOCALID_CAMERA, gSaveBlockPtr->location.mapNum, gSaveBlockPtr->location.mapGroup);
}

bool8 LeadMonHasEffortRibbon(void)
{
    return GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_EFFORT_RIBBON, NULL);
}

void GiveLeadMonEffortRibbon(void)
{
    bool8 ribbonSet;
    struct Pokemon *leadMon;
    IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
    FlagSet(FLAG_SYS_RIBBON_GET);
    ribbonSet = TRUE;
    leadMon = &gPlayerParty[GetLeadMonIndex()];
    SetMonData(leadMon, MON_DATA_EFFORT_RIBBON, &ribbonSet);
}

bool8 Special_AreLeadMonEVsMaxedOut(void)
{
    if (GetMonEVCount(&gPlayerParty[GetLeadMonIndex()]) >= MAX_TOTAL_EVS)
        return TRUE;

    return FALSE;
}

u8 TryUpdateRusturfTunnelState(void)
{
    return 0;
}

void SetShoalItemFlag(u16 unused)
{
    FlagSet(FLAG_SYS_SHOAL_ITEM);
}

bool8 IsStarterInParty(void)
{
    u32 i;
    u16 starter = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) == starter)
            return TRUE;
    }
    return FALSE;
}

bool8 ScriptCheckFreePokemonStorageSpace(void)
{
    return CheckFreePokemonStorageSpace();
}

bool8 IsPokerusInParty(void)
{
    if (!CheckPartyPokerus(gPlayerParty, (1 << PARTY_SIZE) - 1))
        return FALSE;

    return TRUE;
}

// Task data for Task_ShakeCamera
#define tHorizontalPan  data[0]
#define tDelayCounter   data[1]
#define tNumShakes      data[2]
#define tDelay          data[3]
#define tVerticalPan    data[4]

void ShakeCamera(void)
{
    u8 taskId = CreateTask(Task_ShakeCamera, 9);
    gTasks[taskId].tHorizontalPan = gSpecialVar_0x8005;
    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tNumShakes = gSpecialVar_0x8006;
    gTasks[taskId].tDelay = gSpecialVar_0x8007;
    gTasks[taskId].tVerticalPan = gSpecialVar_0x8004;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_M_STRENGTH);
}

static void Task_ShakeCamera(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tDelayCounter++;
    if (tDelayCounter % tDelay == 0)
    {
        tDelayCounter = 0;
        tNumShakes--;
        tHorizontalPan = -tHorizontalPan;
        tVerticalPan = -tVerticalPan;
        SetCameraPanning(tHorizontalPan, tVerticalPan);
        if (tNumShakes == 0)
        {
            StopCameraShake(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void StopCameraShake(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#undef tHorizontalPan
#undef tDelayCounter
#undef tNumShakes
#undef tDelay
#undef tVerticalPan

void SetRoute119Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE119_CYCLE);
}

void SetRoute123Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE123_CYCLE);
}

u8 GetLeadMonIndex(void)
{
    u32 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE)
            return i;
    }
    return 0;
}

u16 ScriptGetPartyMonSpecies(void)
{
    return GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES_OR_EGG, NULL);
}

u16 GetDaysUntilPacifidlogTMAvailable(void)
{
    u16 tmReceivedDay = VarGet(VAR_PACIFIDLOG_TM_RECEIVED_DAY);
    if (gLocalTime.days - tmReceivedDay >= 7)
        return 0;
    else if (gLocalTime.days < 0)
        return 8;

    return 7 - (gLocalTime.days - tmReceivedDay);
}

u16 SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, gLocalTime.days);
    return gLocalTime.days;
}

bool8 MonOTNameNotPlayer(void)
{
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_OT_NAME, gVariableTexto1);

    if (!StringCompare(gSaveBlockPtr->nombreJugador, gVariableTexto1))
        return FALSE;

    return TRUE;
}

void BufferLottoTicketNumber(void)
{
    if (gSpecialVar_Result >= 10000)
    {
        ConvertIntToDecimalStringN(0, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 1000)
    {
        gVariableTexto1[0] = CHAR_0;
        ConvertIntToDecimalStringN(gVariableTexto1 + 1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 100)
    {
        gVariableTexto1[0] = CHAR_0;
        gVariableTexto1[1] = CHAR_0;
        ConvertIntToDecimalStringN(gVariableTexto1 + 2, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 10)
    {
        gVariableTexto1[0] = CHAR_0;
        gVariableTexto1[1] = CHAR_0;
        gVariableTexto1[2] = CHAR_0;
        ConvertIntToDecimalStringN(gVariableTexto1 + 3, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else
    {
        gVariableTexto1[0] = CHAR_0;
        gVariableTexto1[1] = CHAR_0;
        gVariableTexto1[2] = CHAR_0;
        gVariableTexto1[3] = CHAR_0;
        ConvertIntToDecimalStringN(gVariableTexto1 + 4, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
}

bool8 BufferTMHMMoveName(void)
{
    if (gSpecialVar_0x8004 >= ITEM_TM01 && gSpecialVar_0x8004 <= ITEM_HM08)
    {
        StringCopy(gVariableTexto2, ObtenNombreMovimiento(ItemIdToBattleMoveId(gSpecialVar_0x8004)));
        return TRUE;
    }

    return FALSE;
}

void OffsetCameraForBattle(void)
{
    SetCameraPanningCallback(NULL);
    SetCameraPanning(8, 0);
}

static const u8 *const sDeptStoreFloorNames[] =
{
    [DEPT_STORE_FLOORNUM_B4F] = gText_B4F,
    [DEPT_STORE_FLOORNUM_B3F] = gText_B3F,
    [DEPT_STORE_FLOORNUM_B2F] = gText_B2F,
    [DEPT_STORE_FLOORNUM_B1F] = gText_B1F,
    [DEPT_STORE_FLOORNUM_1F] = gText_1F,
    [DEPT_STORE_FLOORNUM_2F] = gText_2F,
    [DEPT_STORE_FLOORNUM_3F] = gText_3F,
    [DEPT_STORE_FLOORNUM_4F] = gText_4F,
    [DEPT_STORE_FLOORNUM_5F] = gText_5F,
    [DEPT_STORE_FLOORNUM_6F] = gText_6F,
    [DEPT_STORE_FLOORNUM_7F] = gText_7F,
    [DEPT_STORE_FLOORNUM_8F] = gText_8F,
    [DEPT_STORE_FLOORNUM_9F] = gText_9F,
    [DEPT_STORE_FLOORNUM_10F] = gText_10F,
    [DEPT_STORE_FLOORNUM_11F] = gText_11F,
    [DEPT_STORE_FLOORNUM_ROOFTOP] = gText_Rooftop
};

void SetDeptStoreFloor(void)
{

}

u16 GetDeptStoreDefaultFloorChoice(void)
{
    return 0;
}

bool8 UsedPokemonCenterWarp(void)
{
    static const u16 sPokemonCenters[] =
    {
        MAP_UNDEFINED
    };

    u32 i;
    u16 map = (gLastUsedWarp.mapGroup << 8) + gLastUsedWarp.mapNum;

    for (i = 0; sPokemonCenters[i] != MAP_UNDEFINED; i++)
    {
        if (sPokemonCenters[i] == map)
            return TRUE;
    }

    return FALSE;
}

// Scrollable Multichoice task data defines
#define tMaxItemsOnScreen    data[0]
#define tNumItems            data[1]
#define tLeft                data[2]
#define tTop                 data[3]
#define tWidth               data[4]
#define tHeight              data[5]
#define tKeepOpenAfterSelect data[6]
#define tScrollOffset        data[7]
#define tSelectedRow         data[8]
#define tScrollMultiId       data[11]
#define tScrollArrowId       data[12]
#define tWindowId            data[13]
#define tListTaskId          data[14]
#define tTaskId              data[15]
// data[9] and [10] unused

// Never run, tKeepOpenAfterSelect is FALSE for all scrollable multichoices.
// Never called
// Removed for Emerald (replaced by ShowScrollableMultichoice)
void ShowGlassWorkshopMenu(void)
{

}

// Undefine Scrollable Multichoice task data macros
#undef tMaxItemsOnScreen
#undef tNumItems
#undef tLeft
#undef tTop
#undef tWidth
#undef tHeight
#undef tKeepOpenAfterSelect
#undef tScrollOffset
#undef tSelectedRow
#undef tScrollMultiId
#undef tScrollArrowId
#undef tWindowId
#undef tListTaskId
#undef tTaskId

#define DEOXYS_ROCK_LEVELS 11

void DoDeoxysRockInteraction(void)
{
    CreateTask(Task_DeoxysRockInteraction, 8);
}

static const u16 sDeoxysRockPalettes[DEOXYS_ROCK_LEVELS][16] = {
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_1.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_2.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_3.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_4.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_5.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_6.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_7.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_8.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_9.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_10.gbapal"),
    INCBIN_U16("graphics/field_effects/palettes/deoxys_rock_11.gbapal"),
};

static const u8 sDeoxysRockCoords[DEOXYS_ROCK_LEVELS][2] = {
    { 15, 12 },
    { 11, 14 },
    { 15,  8 },
    { 19, 14 },
    { 12, 11 },
    { 18, 11 },
    { 15, 14 },
    { 11, 14 },
    { 19, 14 },
    { 15, 15 },
    { 15, 10 },
};

static void Task_DeoxysRockInteraction(u8 taskId)
{
    static const u8 sStoneMaxStepCounts[DEOXYS_ROCK_LEVELS - 1] = { 4, 8, 8, 8, 4, 4, 4, 6, 3, 3 };

    if (FlagGet(FLAG_DEOXYS_ROCK_COMPLETE) == TRUE)
    {
        gSpecialVar_Result = DEOXYS_ROCK_COMPLETE;
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
    else
    {
        u16 rockLevel = VarGet(VAR_DEOXYS_ROCK_LEVEL);
        u16 stepCount = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);

        VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        if (rockLevel != 0 && sStoneMaxStepCounts[rockLevel - 1] < stepCount)
        {
            // Player failed to take the shortest path to the stone, so it resets.
            ChangeDeoxysRockLevel(0);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, 0);
            gSpecialVar_Result = DEOXYS_ROCK_FAILED;
            DestroyTask(taskId);
        }
        else if (rockLevel == DEOXYS_ROCK_LEVELS - 1)
        {
            FlagSet(FLAG_DEOXYS_ROCK_COMPLETE);
            gSpecialVar_Result = DEOXYS_ROCK_SOLVED;
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
        else
        {
            rockLevel++;
            ChangeDeoxysRockLevel(rockLevel);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, rockLevel);
            gSpecialVar_Result = DEOXYS_ROCK_PROGRESSED;
            DestroyTask(taskId);
        }
    }
}

static void ChangeDeoxysRockLevel(u8 rockLevel)
{

}

void IncrementBirthIslandRockStepCount(void)
{
    
}

// called before fade-in
void SetDeoxysRockPalette(void)
{
    u32 paletteNum = IndexOfSpritePaletteTag(OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE);
    LoadPalette(&sDeoxysRockPalettes[(u8)VarGet(VAR_DEOXYS_ROCK_LEVEL)], OBJ_PLTT_ID(paletteNum), PLTT_SIZEOF(4));
    // Set faded to all black, weather blending handled during fade-in
    CpuFill16(0, &gPlttBufferFaded[OBJ_PLTT_ID(paletteNum)], 32);
}

void SetPCBoxToSendMon(u8 boxId)
{
    sPCBoxToSendMon = boxId;
}

u16 GetPCBoxToSendMon(void)
{
    return sPCBoxToSendMon;
}

bool8 ShouldShowBoxWasFullMessage(void)
{
    return FALSE;
}

bool8 IsDestinationBoxFull(void)
{
    int box;
    u32 i;
    SetPCBoxToSendMon(VarGet(VAR_PC_BOX_TO_SEND_MON));
    box = StorageGetCurrentBox();
    do
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (GetBoxMonData(GetBoxedMonPtr(box, i), MON_DATA_SPECIES, 0) == SPECIES_NONE)
            {
                VarSet(VAR_PC_BOX_TO_SEND_MON, box);
                return ShouldShowBoxWasFullMessage();
            }
        }

        if (++box == TOTAL_BOXES_COUNT)
            box = 0;
    } while (box != StorageGetCurrentBox());
    return FALSE;
}

void CreateAbnormalWeatherEvent(void)
{
    u16 randomValue = Random();
    VarSet(VAR_ABNORMAL_WEATHER_STEP_COUNTER, 0);

    if (FlagGet(FLAG_DEFEATED_KYOGRE) == TRUE)
    {
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % TERRA_CAVE_LOCATIONS) + TERRA_CAVE_LOCATIONS_START);
    }
    else if (FlagGet(FLAG_DEFEATED_GROUDON) == TRUE)
    {
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % MARINE_CAVE_LOCATIONS) + MARINE_CAVE_LOCATIONS_START);
    }
    else if ((randomValue & 1) == 0)
    {
        randomValue = Random();
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % TERRA_CAVE_LOCATIONS) + TERRA_CAVE_LOCATIONS_START);
    }
    else
    {
        randomValue = Random();
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, (randomValue % MARINE_CAVE_LOCATIONS) + MARINE_CAVE_LOCATIONS_START);
    }
}

// Saves the map name for the current abnormal weather location in gVariableTexto1, then
// returns TRUE if the weather is for Kyogre, and FALSE if it's for Groudon.
bool32 GetAbnormalWeatherMapNameAndType(void)
{
    return FALSE;
}

// All mart employees have a local id of 1, so function always returns 1
u32 GetMartEmployeeObjectEventId(void)
{
    return 1;
}

// Always returns FALSE
bool32 ShouldDistributeEonTicket(void)
{
    if (!VarGet(VAR_DISTRIBUTE_EON_TICKET))
        return FALSE;

    return TRUE;
}

#define playCount data[0]
#define delay     data[1]

void LoopWingFlapSE(void)
{
    CreateTask(Task_LoopWingFlapSE, 8);
    PlaySE(SE_M_WING_ATTACK);
}

static void Task_LoopWingFlapSE(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    delay++;
    if (delay == gSpecialVar_0x8005)
    {
        playCount++;
        delay = 0;
        PlaySE(SE_M_WING_ATTACK);
    }

    if (playCount == gSpecialVar_0x8004 - 1)
        DestroyTask(taskId);
}

#undef playCount
#undef delay

#define CURTAIN_HEIGHT 4
#define CURTAIN_WIDTH 3
#define tFrameTimer   data
#define tCurrentFrame data[3]

#undef CURTAIN_HEIGHT
#undef CURTAIN_WIDTH
#undef tFrameTimer
#undef tCurrentFrame

// Used to avoid a potential softlock if the player respawns on Dewford with no way off
void ResetHealLocationFromDewford(void)
{

}

bool8 InPokemonCenter(void)
{
    static const u16 sPokemonCenters[] =
    {
        MAP_UNDEFINED
    };

    u32 i;
    u16 map = (gSaveBlockPtr->location.mapGroup << 8) + gSaveBlockPtr->location.mapNum;

    for (i = 0; sPokemonCenters[i] != MAP_UNDEFINED; i++)
    {
        if (sPokemonCenters[i] == map)
            return TRUE;
    }
    return FALSE;
}

/*  Summary of the Lilycove Trainer Fan Club, because it's a little messy

    ## The Fan Club room itself
    There are initially 4 members of the Fan Club (+ an interviewer), none of whom are fans of the player
    After becoming the champion there will be 8 members of the Fan Club, 3 of whom are automatically fans of the player
    After this point, if a club member is a fan of the player they will sit at the front table and comment on the player
    If they are not fans of the player, they will sit at the far table and can make comments about a different trainer (see BufferFanClubTrainerName)

    ## Gaining/losing fans
    After every link battle the player will gain a fan if they won, or lose a fan if they lost
    If the player has at least 3 fans, this is the only way to gain fans
    If the player has fewer than 3 fans, they may also gain fans by completing certain tasks enough times (see TryGainNewFanFromCounter)
    If the player has at least 5 fans, they can lose a fan every 12 real-time hours, or more often if the timer variable is reset (see TryLoseFansFromPlayTime)
    If the player has only 1 fan left it cannot be lost

    ## Variables
    VAR_FANCLUB_FAN_COUNTER, a bitfield for tracking the fans
      Bits  1-7: Counter for when to add new fans
      Bit     8: Flag set after receiving the initial 3 fans
      Bits 9-16: Flags for each of the 8 club members, set to 1 when theyre a fan of the player and 0 when theyre not

    VAR_FANCLUB_LOSE_FAN_TIMER, a timer for when to lose fans
      Compared against playTimeHours. When theyre equal, a fan is ready to be lost
      For every fan thats lost this way 12 hours are added to the timer

    VAR_LILYCOVE_FAN_CLUB_STATE
      0: Player is not the champion yet
      1: Player is the champion, ready to meet their initial fans
      2: Player has met their initial fans
*/

#define FANCLUB_BITFIELD (gSaveBlockPtr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START])
#define FANCLUB_COUNTER    0x007F

#define GET_TRAINER_FAN_CLUB_FLAG(flag)  (FANCLUB_BITFIELD >> (flag) & 1)
#define SET_TRAINER_FAN_CLUB_FLAG(flag)  (FANCLUB_BITFIELD |= 1 << (flag))
#define FLIP_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD ^= 1 << (flag))

#define GET_TRAINER_FAN_CLUB_COUNTER         (FANCLUB_BITFIELD & FANCLUB_COUNTER)
#define SET_TRAINER_FAN_CLUB_COUNTER(count)  (FANCLUB_BITFIELD = (FANCLUB_BITFIELD & ~FANCLUB_COUNTER) | (count))
#define INCR_TRAINER_FAN_CLUB_COUNTER(count) (FANCLUB_BITFIELD += (count))
#define CLEAR_TRAINER_FAN_CLUB_COUNTER       (FANCLUB_BITFIELD &= ~FANCLUB_COUNTER)

void ResetFanClub(void)
{
    gSaveBlockPtr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START] = 0;
    gSaveBlockPtr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = 0;
}

void UpdateTrainerFanClubGameClear(void)
{
    if (!GET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS))
    {
        SetPlayerGotFirstFans();
        SetInitialFansOfPlayer();
        gSaveBlockPtr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlockPtr->playTimeHours;
        FlagClear(FLAG_HIDE_FANCLUB_OLD_LADY);
        FlagClear(FLAG_HIDE_FANCLUB_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LITTLE_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LADY);
        FlagClear(FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER);
        VarSet(VAR_LILYCOVE_FAN_CLUB_STATE, 1);
    }
}

// Loops through the fan club members, and if theyre a fan of the player there is a 50% chance for them to stop being a fan
// Stops if a fan is removed, or if the player has only one fan left
// If no fan was lost while looping, the last current fan in the list will stop being a fan
static u16 PlayerLoseRandomTrainerFan(void)
{
    static const u8 sFanClubMemberIds[NUM_TRAINER_FAN_CLUB_MEMBERS] =
    {
        FANCLUB_MEMBER1,
        FANCLUB_MEMBER6,
        FANCLUB_MEMBER7,
        FANCLUB_MEMBER4,
        FANCLUB_MEMBER3,
        FANCLUB_MEMBER5,
        FANCLUB_MEMBER8,
        FANCLUB_MEMBER2
    };

    u32 i;
    u8 idx = 0;

    if (GetNumFansOfPlayerInTrainerFanClub() == 1)
        return 0;

    for (i = 0; i < ARRAY_COUNT(sFanClubMemberIds); i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]))
        {
            idx = i;
            if (Random() & 1)
            {
                FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
                return idx;
            }
        }
    }

    if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]))
        FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);

    return idx;
}

u16 GetNumFansOfPlayerInTrainerFanClub(void)
{
    u32 i;
    u8 numFans = 0;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(i + FANCLUB_MEMBER1))
            numFans++;
    }

    return numFans;
}

// If the player has > 5 fans in the Trainer Fan Club, then lose 1 fan for every 12 hours since the last fan loss / timer reset
void TryLoseFansFromPlayTime(void)
{
    u32 i = 0;
    if (gSaveBlockPtr->playTimeHours < 999)
    {
        while (TRUE)
        {
            if (GetNumFansOfPlayerInTrainerFanClub() < 5)
            {
                gSaveBlockPtr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlockPtr->playTimeHours;
                break;
            }
            else if (i == NUM_TRAINER_FAN_CLUB_MEMBERS)
            {
                break;
            }
            else if (gSaveBlockPtr->playTimeHours - gSaveBlockPtr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] < 12)
            {
                return;
            }
            PlayerLoseRandomTrainerFan();
            gSaveBlockPtr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] += 12;
            i++;
        }
    }
}

bool8 IsFanClubMemberFanOfPlayer(void)
{
    return GET_TRAINER_FAN_CLUB_FLAG(gSpecialVar_0x8004);
}

static void SetInitialFansOfPlayer(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER6);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER1);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER3);
}

void BufferFanClubTrainerName(void)
{

}

void SetPlayerGotFirstFans(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS);
}

void GetObjectPosition(u16* xPointer, u16* yPointer, u32 localId, u32 useTemplate)
{
    u32 objectId;
    struct ObjectEvent* objEvent;

    if (useTemplate)
    {
        const struct ObjectEventTemplate *objTemplate = FindObjectEventTemplateByLocalId(localId, gSaveBlockPtr->objectEventTemplates, gMapHeader.events->objectEventCount);
        *xPointer = objTemplate->x;
        *yPointer = objTemplate->y;
        return;
    }

    objectId = GetObjectEventIdByLocalId(localId);
    objEvent = &gObjectEvents[objectId];
    *xPointer = objEvent->currentCoords.x - 7;
    *yPointer = objEvent->currentCoords.y - 7;
}

bool32 CheckObjectAtXY(u32 x, u32 y)
{
    u32 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            continue;

        if (gObjectEvents[i].currentCoords.x != x)
            continue;

        if (gObjectEvents[i].currentCoords.y != y)
            continue;
        return TRUE;
    }
    return FALSE;
}

bool32 CheckPartyHasSpecies(u32 givenSpecies)
{
    u32 partyIndex;

    for (partyIndex = 0; partyIndex < CalculatePlayerPartyCount(); partyIndex++)
        if (GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES) == givenSpecies)
            return TRUE;

    return FALSE;
}

void UseBlankMessageToCancelPokemonPic(void)
{
    u8 t = EOS;
    AddTextPrinterParameterized(0, FUENTE_NORMAL, &t, 0, 1, 0, NULL);
    ScriptMenu_HidePokemonPic();
}

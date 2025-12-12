#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "constants/event_bg.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/map_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainers.h"

#define TAG_SCROLL_ARROW 5112

// Values for registryStatus
enum {
    UNREGISTERED,
    REGISTERED,
    NEW, // Temporary, so new secret bases mixed at the same time don't overwrite each other
};

struct SecretBaseRegistryMenu
{
    struct ListMenuItem items[11];
    u8 names[11][32];
};

struct SecretBaseEntranceMetatiles
{
    u16 closedMetatileId;
    u16 openMetatileId;
};

static EWRAM_DATA u8 sCurSecretBaseId = 0;
static EWRAM_DATA bool8 sInFriendSecretBase = FALSE;
static EWRAM_DATA struct SecretBaseRegistryMenu *sRegistryMenu = NULL;

static void Task_ShowSecretBaseRegistryMenu(u8);
static void BuildRegistryMenuItems(u8);
static void RegistryMenu_OnCursorMove(s32, bool8, struct ListMenu *);
static void FinalizeRegistryMenu(u8);
static void AddRegistryMenuScrollArrows(u8);
static void HandleRegistryMenuInput(u8);
static void ShowRegistryMenuActions(u8);
static void HandleRegistryMenuActionsInput(u8);
static void ShowRegistryMenuDeleteConfirmation(u8);
static void ShowRegistryMenuDeleteYesNo(u8);
static void DeleteRegistry_Yes(u8);
static void DeleteRegistry_No(u8);
static void ReturnToMainRegistryMenu(u8);
static void GoToSecretBasePCRegisterMenu(u8);
static u8 GetSecretBaseOwnerType(u8);

static const struct SecretBaseEntranceMetatiles sSecretBaseEntranceMetatiles[] =
{
    {.closedMetatileId = METATILE_General_SecretBase_TreeLeft,  .openMetatileId = METATILE_General_SecretBase_VineLeft},
    {.closedMetatileId = METATILE_General_SecretBase_TreeRight, .openMetatileId = METATILE_General_SecretBase_VineRight},
    {.closedMetatileId = METATILE_General_RedCaveIndent,        .openMetatileId = METATILE_General_RedCaveOpen},
    {.closedMetatileId = METATILE_General_YellowCaveIndent,     .openMetatileId = METATILE_General_YellowCaveOpen},
    {.closedMetatileId = METATILE_General_BlueCaveIndent,       .openMetatileId = METATILE_General_BlueCaveOpen},
    {.closedMetatileId = METATILE_Fallarbor_BrownCaveIndent,    .openMetatileId = METATILE_Fallarbor_BrownCaveOpen},
    {.closedMetatileId = METATILE_Fortree_SecretBase_Shrub,     .openMetatileId = METATILE_Fortree_SecretBase_ShrubOpen},
};

static const struct MenuAction sRegistryMenuActions[] =
{
    {
        .text = gText_DelRegist,
        .func = { .void_u8 = ShowRegistryMenuDeleteConfirmation},
    },
    {
        .text = gText_Salir,
        .func = { .void_u8 = ReturnToMainRegistryMenu},
    },
};

static const struct YesNoFuncTable sDeleteRegistryYesNoFuncs =
{
    .yesFunc = DeleteRegistry_Yes,
    .noFunc = DeleteRegistry_No,
};

static const u16 sSecretBaseOwnerGfxIds[10] =
{
    // Male
    OBJ_EVENT_GFX_YOUNGSTER,
    OBJ_EVENT_GFX_BUG_CATCHER,
    OBJ_EVENT_GFX_RICH_BOY,
    OBJ_EVENT_GFX_CAMPER,
    OBJ_EVENT_GFX_MAN_3,
    // Female
    OBJ_EVENT_GFX_LASS,
    OBJ_EVENT_GFX_GIRL_3,
    OBJ_EVENT_GFX_WOMAN_2,
    OBJ_EVENT_GFX_PICNICKER,
    OBJ_EVENT_GFX_WOMAN_5,
};

static const struct WindowTemplate sRegistryWindowTemplates[] =
{
    {
        .bg = FONDO_0,
        .tilemapLeft = 18,
        .tilemapTop = 1,
        .width = 11,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x01,
    },
    {
        .bg = FONDO_0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xc7,
    }
};

static const struct ListMenuTemplate sRegistryListMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = RegistryMenu_OnCursorMove,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 9,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

static void ClearSecretBase(struct SecretBase *secretBase)
{
    u32 i;
    CpuFastFill16(0, secretBase, sizeof(struct SecretBase));
    for (i = 0; i < MAXIMO_CARACTERES_NOMBRE_JUGADOR; i++)
        secretBase->trainerName[i] = EOS;
}

void ClearSecretBases(void)
{
    u32 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
        ClearSecretBase(&gSaveBlockPtr->secretBases[i]);
}

static void SetCurSecretBaseId(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
}

void TrySetCurSecretBaseIndex(void)
{
    u32 i;

    gSpecialVar_Result = FALSE;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (sCurSecretBaseId == gSaveBlockPtr->secretBases[i].secretBaseId)
        {
            gSpecialVar_Result = TRUE;
            VarSet(VAR_CURRENT_SECRET_BASE, i);
            break;
        }
    }
}

void CheckPlayerHasSecretBase(void)
{
    // The player's secret base is always the first in the array.
    if (gSaveBlockPtr->secretBases[0].secretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 GetSecretBaseTypeInFrontOfPlayer_(void)
{
    return 0;
}

void GetSecretBaseTypeInFrontOfPlayer(void)
{
    gSpecialVar_0x8007 = GetSecretBaseTypeInFrontOfPlayer_();
}

// Opens or closes the secret base entrance metatile in front of the player.
void ToggleSecretBaseEntranceMetatile(void)
{
    u32 i;
    s16 x, y;
    s16 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileId = MapGridGetMetatileIdAt(x, y);

    // Look for entrance metatiles to open
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | MAPGRID_COLLISION_MASK);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }

    // Look for entrance metatiles to close
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].openMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].closedMetatileId | MAPGRID_COLLISION_MASK);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}

static u8 GetNameLength(const u8 *secretBaseOwnerName)
{
    u32 i;
    for (i = 0; i < MAXIMO_CARACTERES_NOMBRE_JUGADOR; i++)
    {
        if (secretBaseOwnerName[i] == EOS)
            return i;
    }

    return MAXIMO_CARACTERES_NOMBRE_JUGADOR;
}

void SetPlayerSecretBase(void)
{

}

// Set the 'open' entrance metatile for any occupied secret base on this map
void SetOccupiedSecretBaseEntranceMetatiles(struct MapEvents const *events)
{

}

static void SetSecretBaseWarpDestination(void)
{

}

#define tState data[0]

static void Task_EnterSecretBase(u8 taskId)
{
    u16 secretBaseIdx;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gFundidoPaletas.activo)
            gTasks[taskId].tState = 1;
        break;
    case 1:
        secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        if (gSaveBlockPtr->secretBases[secretBaseIdx].numTimesEntered < 255)
            gSaveBlockPtr->secretBases[secretBaseIdx].numTimesEntered++;

        SetSecretBaseWarpDestination();
        WarpIntoMap();
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

#undef tState

void EnterSecretBase(void)
{
    CreateTask(Task_EnterSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
    SetDynamicWarp(0, gSaveBlockPtr->location.mapGroup, gSaveBlockPtr->location.mapNum, WARP_ID_NONE);
}

bool8 SecretBaseMapPopupEnabled(void)
{
    return FALSE;
}

bool8 CurMapIsSecretBase(void)
{
    return FALSE;
}

void InitSecretBaseAppearance(bool8 hidePC)
{

}

void InitSecretBaseDecorationSprites(void)
{
    u32 i;
    u8 *decorations;
    u8 *decorationPositions;
    u32 objectEventId;
    u8 metatileBehavior;
    u8 category;
    u8 permission;
    u8 numDecorations;

    objectEventId = 0;
    if (!CurMapIsSecretBase())
    {
        decorations = gSaveBlockPtr->playerRoomDecorations;
        decorationPositions = gSaveBlockPtr->playerRoomDecorationPositions;
        numDecorations = DECOR_MAX_PLAYERS_HOUSE;
    }
    else
    {
        u16 secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        decorations = gSaveBlockPtr->secretBases[secretBaseIdx].decorations;
        decorationPositions = gSaveBlockPtr->secretBases[secretBaseIdx].decorationPositions;
        numDecorations = DECOR_MAX_SECRET_BASE;
    }

    for (i = 0; i < numDecorations; i++)
    {
        if (decorations[i] == DECOR_NONE)
            continue;

        permission = gDecorations[decorations[i]].permission;
        category = gDecorations[decorations[i]].category;
        if (permission == DECORPERM_SPRITE)
        {
            for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
            {
                if (gMapHeader.events->objectEvents[objectEventId].flagId == FLAG_DECORATION_1 + gSpecialVar_0x8004)
                    break;
            }

            if (objectEventId == gMapHeader.events->objectEventCount)
                continue;

            gSpecialVar_0x8006 = decorationPositions[i] >> 4;
            gSpecialVar_0x8007 = decorationPositions[i] & 0xF;
            metatileBehavior = MapGridGetMetatileBehaviorAt(gSpecialVar_0x8006 + MAP_OFFSET, gSpecialVar_0x8007 + MAP_OFFSET);
            if (MetatileBehavior_HoldsSmallDecoration(metatileBehavior) == TRUE
             || MetatileBehavior_HoldsLargeDecoration(metatileBehavior) == TRUE)
            {
                gSpecialVar_Result = VAR_OBJ_GFX_ID_0 + (gMapHeader.events->objectEvents[objectEventId].graphicsId - OBJ_EVENT_GFX_VAR_0);
                VarSet(gSpecialVar_Result, gDecorations[decorations[i]].tiles[0]);
                gSpecialVar_Result = gMapHeader.events->objectEvents[objectEventId].localId;
                FlagClear(FLAG_DECORATION_1 + gSpecialVar_0x8004);
                TrySpawnObjectEvent(gSpecialVar_Result, gSaveBlockPtr->location.mapNum, gSaveBlockPtr->location.mapGroup);
                TryMoveObjectEventToMapCoords(gSpecialVar_Result, gSaveBlockPtr->location.mapNum, gSaveBlockPtr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
                TryOverrideObjectEventTemplateCoords(gSpecialVar_Result, gSaveBlockPtr->location.mapNum, gSaveBlockPtr->location.mapGroup);
                if (CurMapIsSecretBase() == TRUE && VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                {
                    if (category == DECORCAT_DOLL)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlockPtr->location.mapNum,
                            gSaveBlockPtr->location.mapGroup,
                            DECORCAT_DOLL);
                    }
                    else if (category == DECORCAT_CUSHION)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlockPtr->location.mapNum,
                            gSaveBlockPtr->location.mapGroup,
                            DECORCAT_CUSHION);
                    }
                }

                gSpecialVar_0x8004++;
            }
        }
    }
}

void HideSecretBaseDecorationSprites(void)
{
    u32 objectEventId;
    u16 flag;

    for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
    {
        flag = gMapHeader.events->objectEvents[objectEventId].flagId;
        if (flag >= FLAG_DECORATION_1 && flag <= FLAG_DECORATION_14)
        {
            RemoveObjectEventByLocalIdAndMap(
                gMapHeader.events->objectEvents[objectEventId].localId,
                gSaveBlockPtr->location.mapNum,
                gSaveBlockPtr->location.mapGroup);
            FlagSet(flag);
        }
    }
}

void SetSecretBaseOwnerGfxId(void)
{
    VarSet(VAR_OBJ_GFX_ID_F, sSecretBaseOwnerGfxIds[GetSecretBaseOwnerType(VarGet(VAR_CURRENT_SECRET_BASE))]);
}

void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events)
{

}

void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events)
{

}

bool8 TrySetCurSecretBase(void)
{
    SetCurSecretBaseId();
    TrySetCurSecretBaseIndex();
    if (gSpecialVar_Result == TRUE)
        return FALSE;

    return TRUE;
}

static void Task_WarpOutOfSecretBase(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        LockPlayerFieldControls();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (!gFundidoPaletas.activo)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        SetWarpDestinationToDynamicWarp(WARP_ID_SECRET_BASE);
        WarpIntoMap();
        gFieldCallback = FieldCB_DefaultWarpExit;
        SetMainCallback2(CB2_LoadMap);
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    }
}

static void WarpOutOfSecretBase(void)
{
    CreateTask(Task_WarpOutOfSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

void IsCurSecretBaseOwnedByAnotherPlayer(void)
{
    if (gSaveBlockPtr->secretBases[0].secretBaseId != sCurSecretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 *GetSecretBaseName(u8 *dest, u8 secretBaseIdx)
{
    *StringCopyN(dest, gSaveBlockPtr->secretBases[secretBaseIdx].trainerName, GetNameLength(gSaveBlockPtr->secretBases[secretBaseIdx].trainerName)) = EOS;
    ConvertInternationalString(dest, gSaveBlockPtr->secretBases[secretBaseIdx].language);
    return StringAppend(dest, gText_ApostropheSBase);
}

u8 *GetSecretBaseMapName(u8 *dest)
{
    return GetSecretBaseName(dest, VarGet(VAR_CURRENT_SECRET_BASE));
}

void CopyCurSecretBaseOwnerName_StrVar1(void)
{
    u8 secretBaseIdx;
    const u8 *name;

    secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
    name = gSaveBlockPtr->secretBases[secretBaseIdx].trainerName;
    *StringCopyN(gVariableTexto1, name, GetNameLength(name)) = EOS;
    ConvertInternationalString(gVariableTexto1, gSaveBlockPtr->secretBases[secretBaseIdx].language);
}

static bool8 IsSecretBaseRegistered(u8 secretBaseIdx)
{
    if (gSaveBlockPtr->secretBases[secretBaseIdx].registryStatus)
        return TRUE;

    return FALSE;
}

static u8 GetAverageEVs(struct Pokemon *pokemon)
{
    u16 evTotal;
    evTotal  = GetMonData(pokemon, MON_DATA_HP_EV);
    evTotal += GetMonData(pokemon, MON_DATA_ATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_DEF_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPEED_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPDEF_EV);
    return evTotal / 6;
}

void SetPlayerSecretBaseParty(void)
{
    u32 i;
    u16 moveIdx;
    u16 partyId;
    struct SecretBaseParty *party;

    partyId = 0;
    party = &gSaveBlockPtr->secretBases[0].party;
    if (gSaveBlockPtr->secretBases[0].secretBaseId)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            for (moveIdx = 0; moveIdx < MAX_MON_MOVES; moveIdx++)
                party->moves[i * MAX_MON_MOVES + moveIdx] = MOVE_NONE;

            party->species[i] = SPECIES_NONE;
            party->heldItems[i] = ITEM_NONE;
            party->levels[i] = 0;
            party->personality[i] = 0;
            party->EVs[i] = 0;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {
                for (moveIdx = 0; moveIdx < MAX_MON_MOVES; moveIdx++)
                    party->moves[partyId * MAX_MON_MOVES + moveIdx] = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + moveIdx);

                party->species[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
                party->heldItems[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
                party->levels[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
                party->personality[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
                party->EVs[partyId] = GetAverageEVs(&gPlayerParty[i]);
                partyId++;
            }
        }
    }
}

void ClearAndLeaveSecretBase(void)
{
    u16 temp = gSaveBlockPtr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlockPtr->secretBases[0]);
    gSaveBlockPtr->secretBases[0].numSecretBasesReceived = temp;
    WarpOutOfSecretBase();
}

void MoveOutOfSecretBase(void)
{
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    ClearAndLeaveSecretBase();
}

static void ClosePlayerSecretBaseEntrance(void)
{

}

// When the player moves to a new secret base by interacting with a new secret base
// entrance in the overworld.
void MoveOutOfSecretBaseFromOutside(void)
{
    u16 temp;

    ClosePlayerSecretBaseEntrance();
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    temp = gSaveBlockPtr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlockPtr->secretBases[0]);
    gSaveBlockPtr->secretBases[0].numSecretBasesReceived = temp;
}

static u8 GetNumRegisteredSecretBases(void)
{
    s16 i;
    u8 count = 0;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (IsSecretBaseRegistered(i) == TRUE)
            count++;
    }

    return count;
}

void GetCurSecretBaseRegistrationValidity(void)
{
    if (IsSecretBaseRegistered(VarGet(VAR_CURRENT_SECRET_BASE)) == TRUE)
        gSpecialVar_Result = 1;
    else if (GetNumRegisteredSecretBases() >= 10)
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}

void ToggleCurSecretBaseRegistry(void)
{
    gSaveBlockPtr->secretBases[VarGet(VAR_CURRENT_SECRET_BASE)].registryStatus ^= 1;
    FlagSet(FLAG_SECRET_BASE_REGISTRY_ENABLED);
}

void ShowSecretBaseDecorationMenu(void)
{
    CreateTask(DoSecretBaseDecorationMenu, 0);
}

void ShowSecretBaseRegistryMenu(void)
{
    CreateTask(Task_ShowSecretBaseRegistryMenu, 0);
}

#define tNumBases       data[0]
#define tSelectedRow    data[1]
#define tScrollOffset   data[2]
#define tMaxShownItems  data[3]
#define tSelectedBaseId data[4]
#define tListTaskId     data[5]
#define tMainWindowId   data[6]
#define tActionWindowId data[7]
#define tArrowTaskId    data[8]

static void Task_ShowSecretBaseRegistryMenu(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    LockPlayerFieldControls();
    tNumBases = GetNumRegisteredSecretBases();
    if (tNumBases != 0)
    {
        tSelectedRow = 0;
        tScrollOffset = 0;
        ClearDialogWindowAndFrame(0, FALSE);
        sRegistryMenu = AllocZeroed(sizeof(*sRegistryMenu));
        tMainWindowId = AddWindow(&sRegistryWindowTemplates[0]);
        BuildRegistryMenuItems(taskId);
        FinalizeRegistryMenu(taskId);
        gTasks[taskId].func = HandleRegistryMenuInput;
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_NoRegistry, GoToSecretBasePCRegisterMenu);
    }
}

static void BuildRegistryMenuItems(u8 taskId)
{
    s16 *data;
    u32 i;
    u8 count;

    data = gTasks[taskId].data;
    count = 0;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (IsSecretBaseRegistered(i))
        {
            GetSecretBaseName(sRegistryMenu->names[count], i);
            sRegistryMenu->items[count].name = sRegistryMenu->names[count];
            sRegistryMenu->items[count].id = i;
            count++;
        }
    }

    sRegistryMenu->items[count].name = gText_Salir;
    sRegistryMenu->items[count].id = LIST_CANCEL;
    tNumBases = count + 1;
    if (tNumBases < 8)
        tMaxShownItems = tNumBases;
    else
        tMaxShownItems = 8;

    gMultiuseListMenuTemplate = sRegistryListMenuTemplate;
    gMultiuseListMenuTemplate.windowId = tMainWindowId;
    gMultiuseListMenuTemplate.totalItems = tNumBases;
    gMultiuseListMenuTemplate.items = sRegistryMenu->items;
    gMultiuseListMenuTemplate.maxShowed = tMaxShownItems;
}

static void RegistryMenu_OnCursorMove(s32 unused, bool8 flag, struct ListMenu *menu)
{
    if (flag != TRUE)
        PlaySE(SE_SELECT);
}

static void FinalizeRegistryMenu(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    SetStandardWindowBorderStyle(tMainWindowId, FALSE);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, tScrollOffset, tSelectedRow);
    AddRegistryMenuScrollArrows(taskId);
    ScheduleBgCopyTilemapToVram(0);
}

static void AddRegistryMenuScrollArrows(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    tArrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 188, 12, 148, tNumBases - tMaxShownItems, TAG_SCROLL_ARROW, TAG_SCROLL_ARROW, &tScrollOffset);
}

static void HandleRegistryMenuInput(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    s32 input = ListMenu_ProcessInput(tListTaskId);
    ListMenuGetScrollAndRow(tListTaskId, &tScrollOffset, &tSelectedRow);

    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        DestroyListMenuTask(tListTaskId, NULL, NULL);
        RemoveScrollIndicatorArrowPair(tArrowTaskId);
        ClearStdWindowAndFrame(tMainWindowId, FALSE);
        ClearWindowTilemap(tMainWindowId);
        RemoveWindow(tMainWindowId);
        ScheduleBgCopyTilemapToVram(0);
        Free(sRegistryMenu);
        GoToSecretBasePCRegisterMenu(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        tSelectedBaseId = input;
        ShowRegistryMenuActions(taskId);
        break;
    }
}

static void ShowRegistryMenuActions(u8 taskId)
{
    struct WindowTemplate template;
    u16 *data = (u16*) gTasks[taskId].data;
    RemoveScrollIndicatorArrowPair(tArrowTaskId);
    template = sRegistryWindowTemplates[1];
    template.width = GetMaxWidthInMenuTable(sRegistryMenuActions, 2);
    tActionWindowId = AddWindow(&template);
    SetStandardWindowBorderStyle(tActionWindowId, FALSE);
    PrintMenuTable(tActionWindowId, ARRAY_COUNT(sRegistryMenuActions), sRegistryMenuActions);
    InitMenuInUpperLeftCornerNormal(tActionWindowId, ARRAY_COUNT(sRegistryMenuActions), 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = HandleRegistryMenuActionsInput;
}

static void HandleRegistryMenuActionsInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrap();
    switch (input)
    {
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        ReturnToMainRegistryMenu(taskId);
        break;
    case MENU_NOTHING_CHOSEN:
        break;
    default:
        PlaySE(SE_SELECT);
        sRegistryMenuActions[input].func.void_u8(taskId);
        break;
    }
}

static void ShowRegistryMenuDeleteConfirmation(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    ClearStdWindowAndFrame(tMainWindowId, FALSE);
    ClearStdWindowAndFrame(tActionWindowId, FALSE);
    ClearWindowTilemap(tMainWindowId);
    ClearWindowTilemap(tActionWindowId);
    RemoveWindow(tActionWindowId);
    ScheduleBgCopyTilemapToVram(0);
    GetSecretBaseName(gVariableTexto1, tSelectedBaseId);
    StringExpandPlaceholders(gVariableTextoAmpliada, gText_OkayToDeleteFromRegistry);
    DisplayItemMessageOnField(taskId, gVariableTextoAmpliada, ShowRegistryMenuDeleteYesNo);
}

static void ShowRegistryMenuDeleteYesNo(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    DoYesNoFuncWithChoice(taskId, &sDeleteRegistryYesNoFuncs);
}

void DeleteRegistry_Yes_Callback(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    ClearDialogWindowAndFrame(0, FALSE);
    DestroyListMenuTask(tListTaskId, &tScrollOffset, &tSelectedRow);
    gSaveBlockPtr->secretBases[tSelectedBaseId].registryStatus = UNREGISTERED;
    BuildRegistryMenuItems(taskId);
    SetCursorWithinListBounds(&tScrollOffset, &tSelectedRow, tMaxShownItems, tNumBases);
    FinalizeRegistryMenu(taskId);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void DeleteRegistry_Yes(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_RegisteredDataDeleted, DeleteRegistry_Yes_Callback);
}

static void DeleteRegistry_No(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    ClearDialogWindowAndFrame(0, FALSE);
    DestroyListMenuTask(tListTaskId, &tScrollOffset, &tSelectedRow);
    FinalizeRegistryMenu(taskId);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void ReturnToMainRegistryMenu(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    AddRegistryMenuScrollArrows(taskId);
    ClearStdWindowAndFrame(tActionWindowId, FALSE);
    ClearWindowTilemap(tActionWindowId);
    RemoveWindow(tActionWindowId);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void GoToSecretBasePCRegisterMenu(u8 taskId)
{

}

#undef tNumBases
#undef tSelectedRow
#undef tScrollOffset
#undef tMaxShownItems
#undef tSelectedBaseId
#undef tListTaskId
#undef tMainWindowId
#undef tActionWindowId
#undef tArrowTaskId

static u8 GetSecretBaseOwnerType(u8 secretBaseIdx)
{
    return (gSaveBlockPtr->secretBases[secretBaseIdx].trainerId[0] % 5)
         + (gSaveBlockPtr->secretBases[secretBaseIdx].gender * 5);
}

const u8 *GetSecretBaseTrainerLoseText(void)
{
    return 0;
}

void PrepSecretBaseBattleFlags(void)
{

}

void SetBattledOwnerFromResult(void)
{
    gSaveBlockPtr->secretBases[VarGet(VAR_CURRENT_SECRET_BASE)].battledOwnerToday = gSpecialVar_Result;
}

void GetSecretBaseOwnerAndState(void)
{

}

#define tStepCb  data[0] // See Task_RunPerStepCallback
#define tState   data[1]
#define tPlayerX data[2]
#define tPlayerY data[3]
#define tFldEff  data[4]

void SecretBasePerStepCallback(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        if (VarGet(VAR_CURRENT_SECRET_BASE))
            sInFriendSecretBase = TRUE;
        else
            sInFriendSecretBase = FALSE;

        PlayerGetDestCoords(&tPlayerX, &tPlayerY);
        tState = 1;
        break;
    case 1:
        break;
    case 2:
        // This state is never reached, and tFldEff is never set
        if (!FieldEffectActiveListContains(tFldEff))
            tState = 1;
        break;
    }
}

#undef tStepCb
#undef tState
#undef tPlayerX
#undef tPlayerY
#undef tFldEff

void InitSecretBaseVars(void)
{
    sInFriendSecretBase = FALSE;
}

void CheckLeftFriendsSecretBase(void)
{
    sInFriendSecretBase = FALSE;
}

void CheckInteractedWithFriendsDollDecor(void)
{

}

void CheckInteractedWithFriendsCushionDecor(void)
{

}

void DeclinedSecretBaseBattle(void)
{

}

void WonSecretBaseBattle(void)
{

}

void LostSecretBaseBattle(void)
{

}

void DrewSecretBaseBattle(void)
{

}

void CheckInteractedWithFriendsPosterDecor(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case METATILE_SecretBase_PikaPoster_Left:
        case METATILE_SecretBase_PikaPoster_Right:
        case METATILE_SecretBase_LongPoster_Left:
        case METATILE_SecretBase_LongPoster_Right:
        case METATILE_SecretBase_SeaPoster_Left:
        case METATILE_SecretBase_SeaPoster_Right:
        case METATILE_SecretBase_SkyPoster_Left:
        case METATILE_SecretBase_SkyPoster_Right:
        case METATILE_SecretBase_KissPoster_Left:
        case METATILE_SecretBase_KissPoster_Right:
        case METATILE_SecretBase_BallPoster:
        case METATILE_SecretBase_GreenPoster:
        case METATILE_SecretBase_RedPoster:
        case METATILE_SecretBase_BluePoster:
        case METATILE_SecretBase_CutePoster:
            break;
    }
}

void CheckInteractedWithFriendsFurnitureBottom(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case METATILE_SecretBase_GlassOrnament_Base1:
        case METATILE_SecretBase_GlassOrnament_Base2:
            break;
        case METATILE_SecretBase_RedPlant_Base1:
        case METATILE_SecretBase_RedPlant_Base2:
        case METATILE_SecretBase_TropicalPlant_Base1:
        case METATILE_SecretBase_TropicalPlant_Base2:
        case METATILE_SecretBase_PrettyFlowers_Base1:
        case METATILE_SecretBase_PrettyFlowers_Base2:
        case METATILE_SecretBase_ColorfulPlant_BaseLeft1:
        case METATILE_SecretBase_ColorfulPlant_BaseRight1:
        case METATILE_SecretBase_ColorfulPlant_BaseLeft2:
        case METATILE_SecretBase_ColorfulPlant_BaseRight2:
        case METATILE_SecretBase_BigPlant_BaseLeft1:
        case METATILE_SecretBase_BigPlant_BaseRight1:
        case METATILE_SecretBase_BigPlant_BaseLeft2:
        case METATILE_SecretBase_BigPlant_BaseRight2:
        case METATILE_SecretBase_GorgeousPlant_BaseLeft1:
        case METATILE_SecretBase_GorgeousPlant_BaseRight1:
        case METATILE_SecretBase_GorgeousPlant_BaseLeft2:
        case METATILE_SecretBase_GorgeousPlant_BaseRight2:
            break;
        case METATILE_SecretBase_Fence_Horizontal:
        case METATILE_SecretBase_Fence_Vertical:
            break;
        case METATILE_SecretBase_Tire_BottomLeft:
        case METATILE_SecretBase_Tire_BottomRight:
            break;
        case METATILE_SecretBase_RedBrick_Bottom:
        case METATILE_SecretBase_YellowBrick_Bottom:
        case METATILE_SecretBase_BlueBrick_Bottom:
            break;
        case METATILE_SecretBase_SmallDesk:
        case METATILE_SecretBase_PokemonDesk:
        case METATILE_SecretBase_HeavyDesk_BottomLeft:
        case METATILE_SecretBase_HeavyDesk_BottomMid:
        case METATILE_SecretBase_HeavyDesk_BottomRight:
        case METATILE_SecretBase_RaggedDesk_BottomLeft:
        case METATILE_SecretBase_RaggedDesk_BottomMid:
        case METATILE_SecretBase_RaggedDesk_BottomRight:
        case METATILE_SecretBase_ComfortDesk_BottomLeft:
        case METATILE_SecretBase_ComfortDesk_BottomMid:
        case METATILE_SecretBase_ComfortDesk_BottomRight:
        case METATILE_SecretBase_BrickDesk_BottomLeft:
        case METATILE_SecretBase_BrickDesk_BottomMid:
        case METATILE_SecretBase_BrickDesk_BottomRight:
        case METATILE_SecretBase_CampDesk_BottomLeft:
        case METATILE_SecretBase_CampDesk_BottomMid:
        case METATILE_SecretBase_CampDesk_BottomRight:
        case METATILE_SecretBase_HardDesk_BottomLeft:
        case METATILE_SecretBase_HardDesk_BottomMid:
        case METATILE_SecretBase_HardDesk_BottomRight:
        case METATILE_SecretBase_PrettyDesk_BottomLeft:
        case METATILE_SecretBase_PrettyDesk_BottomMid:
        case METATILE_SecretBase_PrettyDesk_BottomRight:
            break;
    }
}

void CheckInteractedWithFriendsFurnitureMiddle(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case METATILE_SecretBase_HeavyDesk_TopMid:
        case METATILE_SecretBase_RaggedDesk_TopMid:
        case METATILE_SecretBase_ComfortDesk_TopMid:
        case METATILE_SecretBase_BrickDesk_TopMid:
        case METATILE_SecretBase_BrickDesk_Center:
        case METATILE_SecretBase_CampDesk_TopMid:
        case METATILE_SecretBase_CampDesk_Center:
        case METATILE_SecretBase_HardDesk_TopMid:
        case METATILE_SecretBase_HardDesk_Center:
        case METATILE_SecretBase_PrettyDesk_TopMid:
        case METATILE_SecretBase_PrettyDesk_Center:
            break;
    }
}

void CheckInteractedWithFriendsFurnitureTop(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case METATILE_SecretBase_HeavyDesk_TopLeft:
        case METATILE_SecretBase_HeavyDesk_TopRight:
        case METATILE_SecretBase_RaggedDesk_TopLeft:
        case METATILE_SecretBase_RaggedDesk_TopRight:
        case METATILE_SecretBase_ComfortDesk_TopLeft:
        case METATILE_SecretBase_ComfortDesk_TopRight:
        case METATILE_SecretBase_BrickDesk_TopLeft:
        case METATILE_SecretBase_BrickDesk_TopRight:
        case METATILE_SecretBase_BrickDesk_MidLeft:
        case METATILE_SecretBase_BrickDesk_MidRight:
        case METATILE_SecretBase_CampDesk_TopLeft:
        case METATILE_SecretBase_CampDesk_TopRight:
        case METATILE_SecretBase_CampDesk_MidLeft:
        case METATILE_SecretBase_CampDesk_MidRight:
        case METATILE_SecretBase_HardDesk_TopLeft:
        case METATILE_SecretBase_HardDesk_TopRight:
        case METATILE_SecretBase_HardDesk_MidLeft:
        case METATILE_SecretBase_HardDesk_MidRight:
        case METATILE_SecretBase_PrettyDesk_TopLeft:
        case METATILE_SecretBase_PrettyDesk_TopRight:
        case METATILE_SecretBase_PrettyDesk_MidLeft:
        case METATILE_SecretBase_PrettyDesk_MidRight:
            break;
        case METATILE_SecretBase_Tire_TopLeft:
        case METATILE_SecretBase_Tire_TopRight:
            break;
        case METATILE_SecretBase_RedBrick_Top:
        case METATILE_SecretBase_YellowBrick_Top:
        case METATILE_SecretBase_BlueBrick_Top:
            break;
    }
}

void CheckInteractedWithFriendsSandOrnament(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch ((int)MapGridGetMetatileIdAt(x, y))
    {
        case METATILE_SecretBase_SandOrnament_Base1:
        case METATILE_SecretBase_SandOrnament_Base2:
            break;
    }
}

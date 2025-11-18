#include "global.h"
#include "save_location.h"

#define LIST_END 0xFFFF

static bool32 IsCurMapInLocationList(const u16 *list)
{
    s32 i;
    u16 map = (gSaveBlockPtr->location.mapGroup << 8) + gSaveBlockPtr->location.mapNum;

    for (i = 0; list[i] != LIST_END; i++)
    {
        if (list[i] == map)
            return TRUE;
    }

    return FALSE;
}

static const u16 sSaveLocationPokeCenterList[] =
{
    LIST_END,
};

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(sSaveLocationPokeCenterList);
}

static const u16 sSaveLocationReloadLocList[] = // There's only 1 location, and it's presumed its for the save reload feature for battle tower.
{
    LIST_END,
};

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(sSaveLocationReloadLocList);
}

// Nulled out list. Unknown what this would have been.
static const u16 sEmptyMapList[] =
{
    LIST_END,
};

static bool32 IsCurMapInEmptyList(void)
{
    return IsCurMapInLocationList(sEmptyMapList);
}

static void TrySetPokeCenterWarpStatus(void)
{
    if (!IsCurMapPokeCenter())
        gSaveBlockPtr->specialSaveWarpFlags &= ~POKECENTER_SAVEWARP;
    else
        gSaveBlockPtr->specialSaveWarpFlags |= POKECENTER_SAVEWARP;
}

static void TrySetReloadWarpStatus(void)
{
    if (!IsCurMapReloadLocation())
        gSaveBlockPtr->specialSaveWarpFlags &= ~LOBBY_SAVEWARP;
    else
        gSaveBlockPtr->specialSaveWarpFlags |= LOBBY_SAVEWARP;
}

// Unknown save warp flag. Never set because map list is empty.
static void TrySetUnknownWarpStatus(void)
{
    if (!IsCurMapInEmptyList())
        gSaveBlockPtr->specialSaveWarpFlags &= ~UNK_SPECIAL_SAVE_WARP_FLAG_3;
    else
        gSaveBlockPtr->specialSaveWarpFlags |= UNK_SPECIAL_SAVE_WARP_FLAG_3;
}

void TrySetMapSaveWarpStatus(void)
{
    TrySetPokeCenterWarpStatus();
    TrySetReloadWarpStatus();
    TrySetUnknownWarpStatus();
}

void SetChampionSaveWarp(void)
{
    gSaveBlockPtr->specialSaveWarpFlags |= CHAMPION_SAVEWARP;
}

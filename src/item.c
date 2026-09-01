#include "global.h"
#include "item.h"
#include "berry.h"
#include "string_util.h"
#include "text.h"
#include "event_data.h"
#include "malloc.h"
#include "item_menu.h"
#include "party_menu.h"
#include "strings.h"
#include "load_save.h"
#include "item_use.h"
#include "graphics.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/item_effects.h"
#include "constants/hold_effects.h"

static const u8 *ItemId_GetPluralName(u16);
static bool32 DoesItemHavePluralName(u16);

EWRAM_DATA struct BagPocket gBagPockets[POCKETS_COUNT] = {0};

#include "data/pokemon/item_effects.h"
#include "data/items.h"

static u16 GetBagItemQuantity(u16 *quantity)
{
    return *quantity;
}

static void SetBagItemQuantity(u16 *quantity, u16 newValue)
{
    *quantity = newValue;
}

void SetBagItemsPointers(void)
{
    gBagPockets[ITEMS_POCKET].itemSlots = gSaveBlockPtr->bagPocket_Items;
    gBagPockets[ITEMS_POCKET].capacity = BAG_ITEMS_COUNT;

    gBagPockets[KEYITEMS_POCKET].itemSlots = gSaveBlockPtr->bagPocket_KeyItems;
    gBagPockets[KEYITEMS_POCKET].capacity = BAG_KEYITEMS_COUNT;

    gBagPockets[BALLS_POCKET].itemSlots = gSaveBlockPtr->bagPocket_PokeBalls;
    gBagPockets[BALLS_POCKET].capacity = BAG_POKEBALLS_COUNT;

    gBagPockets[TMHM_POCKET].itemSlots = gSaveBlockPtr->bagPocket_TMHM;
    gBagPockets[TMHM_POCKET].capacity = BAG_TMHM_COUNT;

    gBagPockets[BERRIES_POCKET].itemSlots = gSaveBlockPtr->bagPocket_Berries;
    gBagPockets[BERRIES_POCKET].capacity = BAG_BERRIES_COUNT;
}

u8 *CopyItemName(u16 itemId, u8 *dst)
{
    return StringCopy(dst, ItemId_GetName(itemId));
}

const u8 sText_s[] =_("s");

u8 *CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity)
{
    if (quantity == 1)
    {
        return StringCopy(dst, ItemId_GetName(itemId));
    }
    else if (DoesItemHavePluralName(itemId))
    {
        return StringCopy(dst, ItemId_GetPluralName(itemId));
    }
    else
    {
        u8 *end = StringCopy(dst, ItemId_GetName(itemId));
        return StringCopy(end, sText_s);
    }
}

bool8 IsBagPocketNonEmpty(u8 pocket)
{
    u32 i;

    for (i = 0; i < gBagPockets[pocket - 1].capacity; i++)
    {
        if (gBagPockets[pocket - 1].itemSlots[i].itemId != 0)
            return TRUE;
    }
    return FALSE;
}

bool8 CheckBagHasItem(u16 itemId, u16 count)
{
    u32 i;
    u8 pocket;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;
    pocket = ItemId_GetPocket(itemId) - 1;
    // Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this item slot contain enough of the item?
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity >= count)
                return TRUE;
            count -= quantity;
            // Does this item slot and all previous slots contain enough of the item?
            if (count == 0)
                return TRUE;
        }
    }
    return FALSE;
}

bool8 HasAtLeastOneBerry(void)
{
    u32 i;

    for (i = FIRST_BERRY_INDEX; i <= LAST_BERRY_INDEX; i++)
    {
        if (CheckBagHasItem(i, 1) == TRUE)
        {
            gSpecialVar_Result = TRUE;
            return TRUE;
        }
    }
    gSpecialVar_Result = FALSE;
    return FALSE;
}

bool8 HasAtLeastOnePokeBall(void)
{
    u32 i;

    for (i = FIRST_BALL; i <= LAST_BALL; i++)
    {
        if (CheckBagHasItem(i, 1) == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool8 CheckBagHasSpace(u16 itemId, u16 count)
{
    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return FALSE;

    return GetFreeSpaceForItemInBag(itemId) >= count;
}

u32 GetFreeSpaceForItemInBag(u16 itemId)
{
    u32 i;
    u8 pocket = ItemId_GetPocket(itemId) - 1;
    u16 ownedCount;
    u32 spaceForItem = 0;

    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return 0;

    // Check space in any existing item slots that already contain this item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            ownedCount = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            spaceForItem += max(0, MAX_BAG_ITEM_CAPACITY - ownedCount);
        }
        else if (gBagPockets[pocket].itemSlots[i].itemId == ITEM_NONE)
        {
            spaceForItem += MAX_BAG_ITEM_CAPACITY;
        }
    }
    return spaceForItem;
}

bool8 AddBagItem(u16 itemId, u16 count)
{
    u32 i;

    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return FALSE;

    struct BagPocket *itemPocket;
    struct ItemSlot *newItems;
    u16 ownedCount;
    u8 pocket = ItemId_GetPocket(itemId) - 1;

    itemPocket = &gBagPockets[pocket];
    newItems = AllocZeroed(itemPocket->capacity * sizeof(struct ItemSlot));
    memcpy(newItems, itemPocket->itemSlots, itemPocket->capacity * sizeof(struct ItemSlot));

    if (pocket == TMHM_POCKET)
    {
        if (!CheckBagHasItem(ITEM_TM_CASE, 1))
            AddBagItem(ITEM_TM_CASE, 1);
    }

    for (i = 0; i < itemPocket->capacity; i++)
    {
        if (newItems[i].itemId == itemId)
        {
            ownedCount = GetBagItemQuantity(&newItems[i].quantity);
            // check if won't exceed max slot capacity
            if (ownedCount + count <= MAX_BAG_ITEM_CAPACITY)
            {
                // successfully added to already existing item's count
                SetBagItemQuantity(&newItems[i].quantity, ownedCount + count);
                memcpy(itemPocket->itemSlots, newItems, itemPocket->capacity * sizeof(struct ItemSlot));
                Free(newItems);
                return TRUE;
            }
            else
            {
                // try creating another instance of the item if possible
                if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                {
                    Free(newItems);
                    return FALSE;
                }
                else
                {
                    count -= MAX_BAG_ITEM_CAPACITY - ownedCount;
                    SetBagItemQuantity(&newItems[i].quantity, MAX_BAG_ITEM_CAPACITY);
                    // don't create another instance of the item if it's at max slot capacity and count is equal to 0
                    if (count == 0)
                    {
                        break;
                    }
                }
            }
        }
    }

    // we're done if quantity is equal to 0
    if (count > 0)
    {
        // either no existing item was found or we have to create another instance, because the capacity was exceeded
        for (i = 0; i < itemPocket->capacity; i++)
        {
            if (newItems[i].itemId == ITEM_NONE)
            {
                newItems[i].itemId = itemId;
                if (count > MAX_BAG_ITEM_CAPACITY)
                {
                    // try creating a new slot with max capacity if duplicates are possible
                    if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                    {
                        Free(newItems);
                        return FALSE;
                    }
                    count -= MAX_BAG_ITEM_CAPACITY;
                    SetBagItemQuantity(&newItems[i].quantity, MAX_BAG_ITEM_CAPACITY);
                }
                else
                {
                    // created a new slot and added quantity
                    SetBagItemQuantity(&newItems[i].quantity, count);
                    count = 0;
                    break;
                }
            }
        }

        if (count > 0)
        {
            Free(newItems);
            return FALSE;
        }
    }
    memcpy(itemPocket->itemSlots, newItems, itemPocket->capacity * sizeof(struct ItemSlot));
    Free(newItems);
    return TRUE;
}

bool8 RemoveBagItem(u16 itemId, u16 count)
{
    u32 i;
    u16 totalQuantity = 0;

    if (ItemId_GetPocket(itemId) == POCKET_NONE || itemId == ITEM_NONE)
        return FALSE;

    u8 pocket;
    u8 var;
    u16 ownedCount;
    struct BagPocket *itemPocket;

    pocket = ItemId_GetPocket(itemId) - 1;
    itemPocket = &gBagPockets[pocket];

    for (i = 0; i < itemPocket->capacity; i++)
    {
        if (itemPocket->itemSlots[i].itemId == itemId)
            totalQuantity += GetBagItemQuantity(&itemPocket->itemSlots[i].quantity);
    }

    if (totalQuantity < count)
        return FALSE;   // We don't have enough of the item

    var = GetItemListPosition(pocket);
    if (itemPocket->capacity > var
        && itemPocket->itemSlots[var].itemId == itemId)
    {
        ownedCount = GetBagItemQuantity(&itemPocket->itemSlots[var].quantity);
        if (ownedCount >= count)
        {
            SetBagItemQuantity(&itemPocket->itemSlots[var].quantity, ownedCount - count);
            count = 0;
        }
        else
        {
            count -= ownedCount;
            SetBagItemQuantity(&itemPocket->itemSlots[var].quantity, 0);
        }

        if (GetBagItemQuantity(&itemPocket->itemSlots[var].quantity) == 0)
            itemPocket->itemSlots[var].itemId = ITEM_NONE;

        if (count == 0)
            return TRUE;
    }

    for (i = 0; i < itemPocket->capacity; i++)
    {
        if (itemPocket->itemSlots[i].itemId == itemId)
        {
            ownedCount = GetBagItemQuantity(&itemPocket->itemSlots[i].quantity);
            if (ownedCount >= count)
            {
                SetBagItemQuantity(&itemPocket->itemSlots[i].quantity, ownedCount - count);
                count = 0;
            }
            else
            {
                count -= ownedCount;
                SetBagItemQuantity(&itemPocket->itemSlots[i].quantity, 0);
            }

            if (GetBagItemQuantity(&itemPocket->itemSlots[i].quantity) == 0)
                itemPocket->itemSlots[i].itemId = ITEM_NONE;

            if (count == 0)
                return TRUE;
        }
    }
    return TRUE;
}

u8 GetPocketByItemId(u16 itemId)
{
    return ItemId_GetPocket(itemId);
}

void ClearItemSlots(struct ItemSlot *itemSlots, u8 itemCount)
{
    u32 i;

    for (i = 0; i < itemCount; i++)
    {
        itemSlots[i].itemId = ITEM_NONE;
        SetBagItemQuantity(&itemSlots[i].quantity, 0);
    }
}

void SwapRegisteredBike(void)
{
    switch (gSaveBlockPtr->registeredItem)
    {
    case ITEM_MACH_BIKE:
        gSaveBlockPtr->registeredItem = ITEM_ACRO_BIKE;
        break;
    case ITEM_ACRO_BIKE:
        gSaveBlockPtr->registeredItem = ITEM_MACH_BIKE;
        break;
    }
}

u16 BagGetItemIdByPocketPosition(u8 pocketId, u16 pocketPos)
{
    return gBagPockets[pocketId - 1].itemSlots[pocketPos].itemId;
}

u16 BagGetQuantityByPocketPosition(u8 pocketId, u16 pocketPos)
{
    return GetBagItemQuantity(&gBagPockets[pocketId - 1].itemSlots[pocketPos].quantity);
}

static void SwapItemSlots(struct ItemSlot *a, struct ItemSlot *b)
{
    struct ItemSlot temp;
    SWAP(*a, *b, temp);
}

void CompactItemsInBagPocket(struct BagPocket *bagPocket)
{
    u32 i, j;

    for (i = 0; i < bagPocket->capacity - 1; i++)
    {
        for (j = i + 1; j < bagPocket->capacity; j++)
        {
            if (GetBagItemQuantity(&bagPocket->itemSlots[i].quantity) == 0)
                SwapItemSlots(&bagPocket->itemSlots[i], &bagPocket->itemSlots[j]);
        }
    }
}

void SortBerriesOrTMHMs(struct BagPocket *bagPocket)
{
    u32 i, j;

    for (i = 0; i < bagPocket->capacity - 1; i++)
    {
        for (j = i + 1; j < bagPocket->capacity; j++)
        {
            if (GetBagItemQuantity(&bagPocket->itemSlots[i].quantity) != 0)
            {
                if (GetBagItemQuantity(&bagPocket->itemSlots[j].quantity) == 0)
                    continue;
                if (bagPocket->itemSlots[i].itemId <= bagPocket->itemSlots[j].itemId)
                    continue;
            }
            SwapItemSlots(&bagPocket->itemSlots[i], &bagPocket->itemSlots[j]);
        }
    }
}

void MoveItemSlotInList(struct ItemSlot* itemSlots_, u32 from, u32 to_)
{
    // dumb assignments needed to match
    struct ItemSlot *itemSlots = itemSlots_;
    u32 to = to_;

    if (from != to)
    {
        s16 i, count;
        struct ItemSlot firstSlot = itemSlots[from];

        if (to > from)
        {
            to--;
            for (i = from, count = to; i < count; i++)
                itemSlots[i] = itemSlots[i + 1];
        }
        else
        {
            for (i = from, count = to; i > count; i--)
                itemSlots[i] = itemSlots[i - 1];
        }
        itemSlots[to] = firstSlot;
    }
}

void ClearBag(void)
{
    u32 i;

    for (i = 0; i < POCKETS_COUNT; i++)
    {
        ClearItemSlots(gBagPockets[i].itemSlots, gBagPockets[i].capacity);
    }
}

u16 CountTotalItemQuantityInBag(u16 itemId)
{
    u32 i;
    u16 ownedCount = 0;
    struct BagPocket *bagPocket = &gBagPockets[ItemId_GetPocket(itemId) - 1];

    for (i = 0; i < bagPocket->capacity; i++)
    {
        if (bagPocket->itemSlots[i].itemId == itemId)
            ownedCount += GetBagItemQuantity(&bagPocket->itemSlots[i].quantity);
    }

    return ownedCount;
}

static u16 SanitizeItemId(u16 itemId)
{
    if (itemId >= ITEMS_COUNT)
        return ITEM_NONE;
    else
        return itemId;
}

const u8 *ItemId_GetName(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].name;
}

u32 ItemId_GetPrice(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].price;
}

static bool32 DoesItemHavePluralName(u16 itemId)
{
    return (gItemsInfo[SanitizeItemId(itemId)].pluralName[0] != '\0');
}

static const u8 *ItemId_GetPluralName(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pluralName;
}

const u8 *ItemId_GetEffect(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].effect;
}

u32 ItemId_GetHoldEffect(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].holdEffect;
}

u32 ItemId_GetHoldEffectParam(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].holdEffectParam;
}

const u8 *ItemId_GetDescription(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].description;
}

u8 ItemId_GetImportance(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].importance;
}

u8 ItemId_GetConsumability(u16 itemId)
{
    return !gItemsInfo[SanitizeItemId(itemId)].notConsumed;
}

u8 ItemId_GetPocket(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pocket;
}

u8 ItemId_GetType(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].type;
}

ItemUseFunc ItemId_GetFieldFunc(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].fieldUseFunc;
}

// Returns an item's battle effect script ID.
u8 ItemId_GetBattleUsage(u16 itemId)
{
    u16 item = SanitizeItemId(itemId);
    return gItemsInfo[item].battleUsage;
}

u8 ItemId_GetSecondaryId(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].secondaryId;
}

// TRUE si un objeto que cura "estadoQueCura" sirve contra el estado que hay.
bool32 CuraEsteEstado(u32 estado, u32 estadoQueCura)
{
    if (estado == ESTADO_NINGUNO)
        return FALSE;
    return estado == estadoQueCura || estadoQueCura == ESTADO_CUALQUIERA;
}

u32 EstadoQueCura(u16 itemId)
{
    const u8 *effect = ItemId_GetEffect(itemId);
    switch (effect[3])
    {
        case ITEM3_PARALYSIS:
            return ESTADO_PARALISIS;
        case ITEM3_FREEZE:
            return ESTADO_CONGELACION;
        case ITEM3_BURN:
            return ESTADO_QUEMADURA;
        case ITEM3_POISON:
            return ESTADO_VENENO;
        case ITEM3_SLEEP:
            return ESTADO_SUENO;
        case ITEM3_STATUS_ALL:
            return ESTADO_CUALQUIERA;
    }
    return 0;
}

// Que estado transitorio cura un objeto, +1 para que el cero sea "ninguno".
u32 TransitorioQueCura(u16 itemId)
{
    const u8 *effect = ItemId_GetEffect(itemId);
    if (effect[3] & ITEM3_STATUS_ALL)
        return TRANSITORIO_CONFUSION + 1;
    else if (effect[3] & ITEM3_CONFUSION)
        return TRANSITORIO_CONFUSION + 1;
    else
        return 0;
}

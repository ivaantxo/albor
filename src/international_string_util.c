#include "global.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "pokedex.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"


int GetStringCenterAlignXOffset(int fontId, const u8 *str, int totalWidth)
{
    return GetStringCenterAlignXOffsetWithLetterSpacing(fontId, str, totalWidth, 0);
}

int GetStringRightAlignXOffset(int fontId, const u8 *str, int totalWidth)
{
    return GetStringWidthDifference(fontId, str, totalWidth, 0);
}

int GetStringCenterAlignXOffsetWithLetterSpacing(int fontId, const u8 *str, int totalWidth, int letterSpacing)
{
    return GetStringWidthDifference(fontId, str, totalWidth, letterSpacing) / 2;
}

int GetStringWidthDifference(int fontId, const u8 *str, int totalWidth, int letterSpacing)
{
    int stringWidth = GetStringWidth(fontId, str, letterSpacing);
    if (totalWidth > stringWidth)
        return totalWidth - stringWidth;
    else
        return 0;
}

int GetMaxWidthInMenuTable(const struct MenuAction *actions, int numActions)
{
    u32 i, maxWidth;

    for (maxWidth = 0, i = 0; i < numActions; i++)
    {
        int stringWidth = GetStringWidth(FONT_NORMAL, actions[i].text, 0);
        if (stringWidth > maxWidth)
            maxWidth = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(maxWidth);
}

int GetMaxWidthInSubsetOfMenuTable(const struct MenuAction *actions, const u8 *actionIds, int numActions)
{
    u32 i, maxWidth;

    for (maxWidth = 0, i = 0; i < numActions; i++)
    {
        int stringWidth = GetStringWidth(FONT_NORMAL, actions[actionIds[i]].text, 0);
        if (stringWidth > maxWidth)
            maxWidth = stringWidth;
    }

    return ConvertPixelWidthToTileWidth(maxWidth);
}

int Intl_GetListMenuWidth(const struct ListMenuTemplate *listMenu)
{
    u32 i, maxWidth, finalWidth;
    const struct ListMenuItem *items = listMenu->items;

    maxWidth = 0;
    for (i = 0; i < listMenu->totalItems; i++)
    {
        int width = GetStringWidth(listMenu->fontId, items[i].name, 0);
        if (width > maxWidth)
            maxWidth = width;
    }

    finalWidth = maxWidth + listMenu->item_X + 9;
    finalWidth /= 8;
    if (finalWidth > 28)
        finalWidth = 28;

    return finalWidth;
}

u8 *GetStringClearToWidth(u8 *dest, int fontId, const u8 *str, int totalStringWidth)
{
    u8 *buffer;
    int width;
    int clearWidth;

    if (str)
    {
        buffer = StringCopy(dest, str);
        width = GetStringWidth(fontId, str, 0);
    }
    else
    {
        buffer = dest;
        width = 0;
    }

    clearWidth = totalStringWidth - width;
    if (clearWidth > 0)
    {
        *(buffer++) = EXT_CTRL_CODE_BEGIN;
        *(buffer++) = EXT_CTRL_CODE_CLEAR;
        *(buffer++) = clearWidth;
        *buffer = EOS;
    }

    return buffer;
}

void PadNameString(u8 *dest, u8 padChar)
{
    u8 length;

    StripExtCtrlCodes(dest);
    length = StringLength(dest);
    if (padChar == EXT_CTRL_CODE_BEGIN)
    {
        while (length < PLAYER_NAME_LENGTH - 1)
        {
            dest[length] = EXT_CTRL_CODE_BEGIN;
            dest[length + 1] = EXT_CTRL_CODE_RESET_FONT;
            length += 2;
        }
    }
    else
    {
        while (length < PLAYER_NAME_LENGTH - 1)
        {
            dest[length] = padChar;
            length++;
        }
    }

    dest[length] = EOS;
}

// Used by Pokénav's Match Call to erase the previous trainer's flavor text when switching between their info pages.
void FillWindowTilesByRow(int windowId, int columnStart, int rowStart, int numFillTiles, int numRows)
{
    u8 *windowTileData;
    int fillSize, windowRowSize, i;
    struct Window *window = &gWindows[windowId];

    fillSize = numFillTiles * TILE_SIZE_4BPP;
    windowRowSize = window->window.width * TILE_SIZE_4BPP;
    windowTileData = window->tileData + (rowStart * windowRowSize) + (columnStart * TILE_SIZE_4BPP);
    if (numRows > 0)
    {
        for (i = numRows; i != 0; i--)
        {
            CpuFastFill8(0x11, windowTileData, fillSize);
            windowTileData += windowRowSize;
        }
    }
}

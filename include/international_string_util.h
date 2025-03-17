#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

#include "menu.h"
#include "list_menu.h"

int GetStringCenterAlignXOffset(int fontId, const u8 *str, int totalWidth);
int GetStringRightAlignXOffset(int fontId, const u8 *str, int totalWidth);
int GetStringCenterAlignXOffsetWithLetterSpacing(int fontId, const u8 *str, int totalWidth, int letterSpacing);
int GetStringWidthDifference(int fontId, const u8 *str, int totalWidth, int letterSpacing);
int GetMaxWidthInMenuTable(const struct MenuAction *actions, int numActions);
int GetMaxWidthInSubsetOfMenuTable(const struct MenuAction *actions, const u8 *actionIds, int numActions);
int Intl_GetListMenuWidth(const struct ListMenuTemplate *listMenu);
u8 *GetStringClearToWidth(u8 *dest, int fontId, const u8 *str, int totalStringWidth);
void PadNameString(u8 *dest, u8 padChar);
void FillWindowTilesByRow(int windowId, int columnStart, int rowStart, int numFillTiles, int numRows);

#endif // GUARD_INTERNATIONAL_STRING_UTIL_H

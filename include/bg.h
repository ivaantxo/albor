#ifndef GUARD_BG_H
#define GUARD_BG_H

enum
{
    BG_ATTR_CHARBASEINDEX = 1,
    BG_ATTR_MAPBASEINDEX,
    BG_ATTR_SCREENSIZE,
    BG_ATTR_PALETTEMODE,
    BG_ATTR_MOSAIC,
    BG_ATTR_WRAPAROUND,
    BG_ATTR_PRIORITY,
    BG_ATTR_METRIC,
    BG_ATTR_TYPE,
    BG_ATTR_BASETILE,
};

enum {
    BG_TYPE_NORMAL,
    BG_TYPE_AFFINE,
    BG_TYPE_NONE = 0xFFFF
};

// Modes for ChangeBgX / ChangeBgY
enum {
    BG_COORD_SET,
    BG_COORD_ADD,
    BG_COORD_SUB,
};

struct BgTemplate
{
    u16 bg:2;                   // 0x1, 0x2 -> 0x3
    u16 charBaseIndex:2;        // 0x4, 0x8 -> 0xC
    u16 mapBaseIndex:5;         // 0x10, 0x20, 0x40, 0x80, 0x100 -> 0x1F0
    u16 screenSize:2;           // 0x200, 0x400 -> 0x600
    u16 paletteMode:1;          // 0x800
    u16 priority:2;             // 0x1000, 0x2000 > 0x3000
    u16 baseTile:10;
};

void ResetBgs(void);
u32 GetBgMode(void);
void ResetBgControlStructs(void);
u32 LoadBgVram(u32 bg, const void *src, u32 size, u32 destOffset, u32 mode);
void SetTextModeAndHideBgs(void);
bool32 IsInvalidBg(u32 bg);
void ResetBgsAndClearDma3BusyFlags(void);
void InitBgsFromTemplates(u32 bgMode, const struct BgTemplate *templates, u32 numTemplates);
void InitBgFromTemplate(const struct BgTemplate *template);
void SetBgMode(u32 bgMode);
u32 LoadBgTiles(u32 bg, const void *src, u32 size, u32 destOffset);
u32 LoadBgTilemap(u32 bg, const void *src, u32 size, u32 destOffset);
bool32 IsDma3ManagerBusyWithBgCopy(void);
void ShowBg(u32 bg);
void HideBg(u32 bg);
void SetBgAttribute(u32 bg, u32 attributeId, u32 value);
u32 GetBgAttribute(u32 bg, u32 attributeId);
s32 ChangeBgX(u32 bg, s32 value, u32 op);
s32 GetBgX(u32 bg);
s32 ChangeBgY(u32 bg, s32 value, u32 op);
s32 ChangeBgY_ScreenOff(u32 bg, s32 value, u32 op);
s32 GetBgY(u32 bg);
void SetBgAffine(u32 bg, s32 srcCenterX, s32 srcCenterY, s32 dispCenterX, s32 dispCenterY, s32 scaleX, s32 scaleY, u32 rotationAngle);
void SetBgTilemapBuffer(u32 bg, void *tilemap);
void UnsetBgTilemapBuffer(u32 bg);
void *GetBgTilemapBuffer(u32 bg);
void CopyToBgTilemapBuffer(u32 bg, const void *src, u32 mode, u32 destOffset);
void CopyBgTilemapBufferToVram(u32 bg);
void CopyToBgTilemapBufferRect(u32 bg, const void *src, u32 destX, u32 destY, u32 width, u32 height);
void CopyToBgTilemapBufferRect_ChangePalette(u32 bg, const void *src, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight, u32 palette);
void CopyRectToBgTilemapBufferRect(u32 bg, const void *src, u32 srcX, u32 srcY, u32 srcWidth, u32 srcHeight, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight, u32 palette1, s32 tileOffset, s32 palette2);
void FillBgTilemapBufferRect_Palette0(u32 bg, u32 tileNum, u32 x, u32 y, u32 width, u32 height);
void FillBgTilemapBufferRect(u32 bg, u32 tileNum, u32 x, u32 y, u32 width, u32 height, u32 palette);
void WriteSequenceToBgTilemapBuffer(u32 bg, u16 firstTileNum, u32 x, u32 y, u32 width, u32 height, u32 paletteSlot, s32 tileNumDelta);
u32 GetBgMetricTextMode(u32 bg, u32 whichMetric);
u32 GetBgMetricAffineMode(u32 bg, u32 whichMetric);
u32 GetTileMapIndexFromCoords(u32 x, u32 y, u32 screenSize, u32 screenWidth, u32 screenHeight);
void CopyTileMapEntry(const u16 *src, u16 *dest, s32 palette1, s32 tileOffset, s32 palette2);
bool32 IsTileMapOutsideWram(u32 bg);

#endif // GUARD_BG_H

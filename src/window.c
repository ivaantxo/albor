#include "global.h"
#include "window.h"
#include "malloc.h"
#include "bg.h"
#include "blit.h"

COMMON_DATA void *gWindowBgTilemapBuffers[NUMERO_FONDOS] = {0};

EWRAM_DATA struct Window gWindows[WINDOWS_MAX] = {0};

static u32 GetNumActiveWindowsOnBg(u32 bgId);

static const struct WindowTemplate sDummyWindowTemplate = DUMMY_WIN_TEMPLATE;

static void DummyWindowBgTilemap(void)
{

}

bool32 InitWindows(const struct WindowTemplate *templates)
{
    u32 i;
    void *bgTilemapBuffer;
    u32 j;
    u32 bgLayer;
    u32 attrib;
    u8 *allocatedTilemapBuffer;

    for (i = 0; i < NUMERO_FONDOS; ++i)
    {
        bgTilemapBuffer = GetBgTilemapBuffer(i);
        if (bgTilemapBuffer != NULL)
            gWindowBgTilemapBuffers[i] = DummyWindowBgTilemap;
        else
            gWindowBgTilemapBuffers[i] = bgTilemapBuffer;
    }

    for (i = 0; i < WINDOWS_MAX; ++i)
    {
        gWindows[i].window = sDummyWindowTemplate;
        gWindows[i].tileData = NULL;
    }

    for (i = 0, bgLayer = templates[i].bg; bgLayer != 0xFF && i < WINDOWS_MAX; ++i, bgLayer = templates[i].bg)
    {
        if (gWindowBgTilemapBuffers[bgLayer] == NULL)
        {
            attrib = GetBgAttribute(bgLayer, BG_ATTR_METRIC);

            if (attrib != 0xFFFF)
            {
                allocatedTilemapBuffer = AllocZeroed(attrib);

                if (allocatedTilemapBuffer == NULL)
                {
                    FreeAllWindowBuffers();
                    return FALSE;
                }

                for (j = 0; j < attrib; ++j)
                    allocatedTilemapBuffer[j] = 0;

                gWindowBgTilemapBuffers[bgLayer] = allocatedTilemapBuffer;
                SetBgTilemapBuffer(bgLayer, allocatedTilemapBuffer);
            }
        }

        allocatedTilemapBuffer = AllocZeroed((u16)(32 * (templates[i].width * templates[i].height)));

        if (allocatedTilemapBuffer == NULL)
        {
            if ((GetNumActiveWindowsOnBg(bgLayer) == 0) && (gWindowBgTilemapBuffers[bgLayer] != DummyWindowBgTilemap))
            {
                Free(gWindowBgTilemapBuffers[bgLayer]);
                gWindowBgTilemapBuffers[bgLayer] = allocatedTilemapBuffer;
            }

            return FALSE;
        }

        gWindows[i].tileData = allocatedTilemapBuffer;
        gWindows[i].window = templates[i];
    }

    return TRUE;
}

u32 AddWindow(const struct WindowTemplate *template)
{
    u32 win;
    u32 bgLayer;
    u32 attrib;
    u8 *allocatedTilemapBuffer;
    u32 i;

    for (win = 0; win < WINDOWS_MAX; ++win)
    {
        if ((bgLayer = gWindows[win].window.bg) == 0xFF)
            break;
    }

    if (win == WINDOWS_MAX)
        return WINDOW_NONE;

    bgLayer = template->bg;

    if (gWindowBgTilemapBuffers[bgLayer] == NULL)
    {
        attrib = GetBgAttribute(bgLayer, BG_ATTR_METRIC);

        if (attrib != 0xFFFF)
        {
            allocatedTilemapBuffer = AllocZeroed(attrib);

            if (allocatedTilemapBuffer == NULL)
                return WINDOW_NONE;

            for (i = 0; i < attrib; ++i)
                allocatedTilemapBuffer[i] = 0;

            gWindowBgTilemapBuffers[bgLayer] = allocatedTilemapBuffer;
            SetBgTilemapBuffer(bgLayer, allocatedTilemapBuffer);
        }
    }

    allocatedTilemapBuffer = AllocZeroed((u16)(32 * (template->width * template->height)));

    if (allocatedTilemapBuffer == NULL)
    {
        if ((GetNumActiveWindowsOnBg(bgLayer) == 0) && (gWindowBgTilemapBuffers[bgLayer] != DummyWindowBgTilemap))
        {
            Free(gWindowBgTilemapBuffers[bgLayer]);
            gWindowBgTilemapBuffers[bgLayer] = allocatedTilemapBuffer;
        }
        return WINDOW_NONE;
    }

    gWindows[win].tileData = allocatedTilemapBuffer;
    gWindows[win].window = *template;

    return win;
}

u32 AddWindowWithoutTileMap(const struct WindowTemplate *template)
{
    u32 win;

    for (win = 0; win < WINDOWS_MAX; ++win)
    {
        if (gWindows[win].window.bg == 0xFF)
            break;
    }

    if (win == WINDOWS_MAX)
        return WINDOW_NONE;

    gWindows[win].window = *template;

    return win;
}

void RemoveWindow(u32 windowId)
{
    u32 bgLayer = gWindows[windowId].window.bg;

    gWindows[windowId].window = sDummyWindowTemplate;

    if (GetNumActiveWindowsOnBg(bgLayer) == 0)
    {
        if (gWindowBgTilemapBuffers[bgLayer] != DummyWindowBgTilemap)
        {
            Free(gWindowBgTilemapBuffers[bgLayer]);
            gWindowBgTilemapBuffers[bgLayer] = NULL;
        }
    }

    if (gWindows[windowId].tileData != NULL)
    {
        Free(gWindows[windowId].tileData);
        gWindows[windowId].tileData = NULL;
    }
}

void FreeAllWindowBuffers(void)
{
    u32 i;

    for (i = 0; i < NUMERO_FONDOS; ++i)
    {
        if (gWindowBgTilemapBuffers[i] != NULL && gWindowBgTilemapBuffers[i] != DummyWindowBgTilemap)
        {
            Free(gWindowBgTilemapBuffers[i]);
            gWindowBgTilemapBuffers[i] = NULL;
        }
    }

    for (i = 0; i < WINDOWS_MAX; ++i)
    {
        if (gWindows[i].tileData != NULL)
        {
            Free(gWindows[i].tileData);
            gWindows[i].tileData = NULL;
        }
    }
}

void CopyWindowToVram(u32 windowId, u32 mode)
{
    struct Window windowLocal = gWindows[windowId];
    u32 windowSize = 32 * (windowLocal.window.width * windowLocal.window.height);

    switch (mode)
    {
    case COPYWIN_MAP:
        CopyBgTilemapBufferToVram(windowLocal.window.bg);
        break;
    case COPYWIN_GFX:
        LoadBgTiles(windowLocal.window.bg, windowLocal.tileData, windowSize, windowLocal.window.baseBlock);
        break;
    case COPYWIN_FULL:
        LoadBgTiles(windowLocal.window.bg, windowLocal.tileData, windowSize, windowLocal.window.baseBlock);
        CopyBgTilemapBufferToVram(windowLocal.window.bg);
        break;
    }
}

void CopyWindowRectToVram(u32 windowId, u32 mode, u32 x, u32 y, u32 w, u32 h)
{
    struct Window windowLocal;
    u32 rectSize;
    u32 rectPos;

    if (w != 0 && h != 0)
    {
        windowLocal = gWindows[windowId];

        rectSize = ((h - 1) * windowLocal.window.width);
        rectSize += (windowLocal.window.width - x);
        rectSize -= (windowLocal.window.width - (x + w));
        rectSize *= 32;

        rectPos = (y * windowLocal.window.width) + x;

        switch (mode)
        {
        case COPYWIN_MAP:
            CopyBgTilemapBufferToVram(windowLocal.window.bg);
            break;
        case COPYWIN_GFX:
            LoadBgTiles(windowLocal.window.bg, windowLocal.tileData + (rectPos * 32), rectSize, windowLocal.window.baseBlock + rectPos);
            break;
        case COPYWIN_FULL:
            LoadBgTiles(windowLocal.window.bg, windowLocal.tileData + (rectPos * 32), rectSize, windowLocal.window.baseBlock + rectPos);
            CopyBgTilemapBufferToVram(windowLocal.window.bg);
            break;
        }
    }
}

void PutWindowTilemap(u32 windowId)
{
    struct Window windowLocal = gWindows[windowId];

    WriteSequenceToBgTilemapBuffer(
        windowLocal.window.bg,
        GetBgAttribute(windowLocal.window.bg, BG_ATTR_BASETILE) + windowLocal.window.baseBlock,
        windowLocal.window.tilemapLeft,
        windowLocal.window.tilemapTop,
        windowLocal.window.width,
        windowLocal.window.height,
        windowLocal.window.paletteNum,
        1);
}

void PutWindowRectTilemapOverridePalette(u32 windowId, u32 x, u32 y, u32 width, u32 height, u32 palette)
{
    struct Window windowLocal = gWindows[windowId];
    u32 currentRow = windowLocal.window.baseBlock + (y * windowLocal.window.width) + x + GetBgAttribute(windowLocal.window.bg, BG_ATTR_BASETILE);
    u32 i;

    for (i = 0; i < height; ++i)
    {
        WriteSequenceToBgTilemapBuffer(
            windowLocal.window.bg,
            currentRow,
            windowLocal.window.tilemapLeft + x,
            windowLocal.window.tilemapTop + y + i,
            width,
            1,
            palette,
            1);

        currentRow += windowLocal.window.width;
    }
}

// Fills a window with transparent tiles.
void ClearWindowTilemap(u32 windowId)
{
    struct Window windowLocal = gWindows[windowId];

    FillBgTilemapBufferRect(
        windowLocal.window.bg,
        0,
        windowLocal.window.tilemapLeft,
        windowLocal.window.tilemapTop,
        windowLocal.window.width,
        windowLocal.window.height,
        windowLocal.window.paletteNum);
}

void PutWindowRectTilemap(u32 windowId, u32 x, u32 y, u32 width, u32 height)
{
    struct Window windowLocal = gWindows[windowId];
    u32 currentRow = windowLocal.window.baseBlock + (y * windowLocal.window.width) + x + GetBgAttribute(windowLocal.window.bg, BG_ATTR_BASETILE);
    u32 i;

    for (i = 0; i < height; ++i)
    {
        WriteSequenceToBgTilemapBuffer(
            windowLocal.window.bg,
            currentRow,
            windowLocal.window.tilemapLeft + x,
            windowLocal.window.tilemapTop + y + i,
            width,
            1,
            windowLocal.window.paletteNum,
            1);

        currentRow += windowLocal.window.width;
    }
}

void BlitBitmapToWindow(u32 windowId, const u8 *pixels, u32 x, u32 y, u32 width, u32 height)
{
    BlitBitmapRectToWindow(windowId, pixels, 0, 0, width, height, x, y, width, height);
}

void BlitBitmapRectToWindow(u32 windowId, const u8 *pixels, u32 srcX, u32 srcY, u32 srcWidth, u32 srcHeight, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight)
{
    struct Bitmap sourceRect;
    struct Bitmap destRect;

    sourceRect.pixels = (u8 *)pixels;
    sourceRect.width = srcWidth;
    sourceRect.height = srcHeight;

    destRect.pixels = gWindows[windowId].tileData;
    destRect.width = 8 * gWindows[windowId].window.width;
    destRect.height = 8 * gWindows[windowId].window.height;

    BlitBitmapRect4Bit(&sourceRect, &destRect, srcX, srcY, destX, destY, rectWidth, rectHeight, 0);
}

void FillWindowPixelRect(u32 windowId, u32 fillValue, u32 x, u32 y, u32 width, u32 height)
{
    struct Bitmap pixelRect;

    pixelRect.pixels = gWindows[windowId].tileData;
    pixelRect.width = 8 * gWindows[windowId].window.width;
    pixelRect.height = 8 * gWindows[windowId].window.height;

    FillBitmapRect4Bit(&pixelRect, x, y, width, height, fillValue);
}

void CopyToWindowPixelBuffer(u32 windowId, const void *src, u32 size, u32 tileOffset)
{
    if (size != 0)
        CopiaCpu16(src, gWindows[windowId].tileData + (32 * tileOffset), size);
    else
        LZ77UnCompWram(src, gWindows[windowId].tileData + (32 * tileOffset));
}

// Sets all pixels within the window to the fillValue color.
void FillWindowPixelBuffer(u32 windowId, u32 fillValue)
{
    u32 fillSize = gWindows[windowId].window.width * gWindows[windowId].window.height;
    CpuFastFill8(fillValue, gWindows[windowId].tileData, 32 * fillSize);
}

#define MOVE_TILES_DOWN(a)                                                      \
{                                                                               \
    destOffset = i + (a);                                                       \
    srcOffset = i + (((width * (distanceLoop & ~7)) | (distanceLoop & 7)) * 4); \
    if (srcOffset < size)                                                       \
        *(u32 *)(tileData + destOffset) = *(u32 *)(tileData + srcOffset);         \
    else                                                                        \
        *(u32 *)(tileData + destOffset) = fillValue32;                           \
    distanceLoop++;                                                             \
}

#define MOVE_TILES_UP(a)                                                        \
{                                                                               \
    destOffset = i + (a);                                                       \
    srcOffset = i + (((width * (distanceLoop & ~7)) | (distanceLoop & 7)) * 4); \
    if (srcOffset < size)                                                       \
        *(u32 *)(tileData - destOffset) = *(u32 *)(tileData - srcOffset);         \
    else                                                                        \
        *(u32 *)(tileData - destOffset) = fillValue32;                           \
    distanceLoop++;                                                             \
}

void ScrollWindow(u32 windowId, u32 direction, u32 distance, u32 fillValue)
{
    struct WindowTemplate window = gWindows[windowId].window;
    u8 *tileData = gWindows[windowId].tileData;
    u32 fillValue32 = (fillValue << 24) | (fillValue << 16) | (fillValue << 8) | fillValue;
    s32 size = window.height * window.width * 32;
    u32 width = window.width;
    s32 i;
    s32 srcOffset, destOffset;
    u32 distanceLoop;

    switch (direction)
    {
    case 0:
        for (i = 0; i < size; i += 32)
        {
            distanceLoop = distance;
            MOVE_TILES_DOWN(0)
            MOVE_TILES_DOWN(4)
            MOVE_TILES_DOWN(8)
            MOVE_TILES_DOWN(12)
            MOVE_TILES_DOWN(16)
            MOVE_TILES_DOWN(20)
            MOVE_TILES_DOWN(24)
            MOVE_TILES_DOWN(28)
        }
        break;
    case 1:
        tileData += size - 4;
        for (i = 0; i < size; i += 32)
        {
            distanceLoop = distance;
            MOVE_TILES_UP(0)
            MOVE_TILES_UP(4)
            MOVE_TILES_UP(8)
            MOVE_TILES_UP(12)
            MOVE_TILES_UP(16)
            MOVE_TILES_UP(20)
            MOVE_TILES_UP(24)
            MOVE_TILES_UP(28)
        }
        break;
    case 2:
        break;
    }
}

void CallWindowFunction(u32 windowId, void ( *func)(u8, u8, u8, u8, u8, u8))
{
    struct WindowTemplate window = gWindows[windowId].window;
    func(window.bg, window.tilemapLeft, window.tilemapTop, window.width, window.height, window.paletteNum);
}

bool32 SetWindowAttribute(u32 windowId, u32 attributeId, u32 value)
{
    switch (attributeId)
    {
    case WINDOW_TILEMAP_LEFT:
        gWindows[windowId].window.tilemapLeft = value;
        return FALSE;
    case WINDOW_TILEMAP_TOP:
        gWindows[windowId].window.tilemapTop = value;
        return FALSE;
    case WINDOW_PALETTE_NUM:
        gWindows[windowId].window.paletteNum = value;
        return FALSE;
    case WINDOW_BASE_BLOCK:
        gWindows[windowId].window.baseBlock = value;
        return FALSE;
    case WINDOW_TILE_DATA:
        gWindows[windowId].tileData = (u8 *)(value);
        return TRUE;
    case WINDOW_BG:
    case WINDOW_WIDTH:
    case WINDOW_HEIGHT:
    default:
        return TRUE;
    }
}

u32 GetWindowAttribute(u32 windowId, u32 attributeId)
{
    switch (attributeId)
    {
    case WINDOW_BG:
        return gWindows[windowId].window.bg;
    case WINDOW_TILEMAP_LEFT:
        return gWindows[windowId].window.tilemapLeft;
    case WINDOW_TILEMAP_TOP:
        return gWindows[windowId].window.tilemapTop;
    case WINDOW_WIDTH:
        return gWindows[windowId].window.width;
    case WINDOW_HEIGHT:
        return gWindows[windowId].window.height;
    case WINDOW_PALETTE_NUM:
        return gWindows[windowId].window.paletteNum;
    case WINDOW_BASE_BLOCK:
        return gWindows[windowId].window.baseBlock;
    case WINDOW_TILE_DATA:
        return (u32)(gWindows[windowId].tileData);
    default:
        return 0;
    }
}

static u32 GetNumActiveWindowsOnBg(u32 bgId)
{
    u32 windowsNum = 0;
    s32 i;
    for (i = 0; i < WINDOWS_MAX; i++)
    {
        if (gWindows[i].window.bg == bgId)
            windowsNum++;
    }
    return windowsNum;
}

u32 WindowWidthPx(u32 windowId)
{
    return gWindows[windowId].window.width * LADO_TILE;
}

u32 WindowTemplateWidthPx(const struct WindowTemplate *template)
{
    return template->width * LADO_TILE;
}

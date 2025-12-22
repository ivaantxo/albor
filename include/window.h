#ifndef GUARD_WINDOW_H
#define GUARD_WINDOW_H

#define WINDOWS_MAX  32

#define PIXEL_FILL(num) ((num) | ((num) << 4))

enum {
    WINDOW_BG,
    WINDOW_TILEMAP_LEFT,
    WINDOW_TILEMAP_TOP,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_PALETTE_NUM,
    WINDOW_BASE_BLOCK,
    WINDOW_TILE_DATA
};

enum ModosCopiaVentanas
{
    COPIA_VENTANA_NO,
    COPIA_VENTANA_TILEMAP,
    COPIA_VENTANA_TILES,
    COPIA_VENTANA_COMPLETA,
};

enum DireccionScrollWindow
{
    DIRECCION_SCROLL_VENTANA_ABAJO,
    DIRECCION_SCROLL_VENTANA_ARRIBA,
};

struct WindowTemplate
{
    u32 bg;
    u32 tilemapLeft;
    u32 tilemapTop;
    u32 width;
    u32 height;
    u32 paletteNum;
    u32 baseBlock;
};

#define DUMMY_WIN_TEMPLATE          \
{                                   \
    .bg = 0xFF,                     \
}

#define WINDOW_NONE 0xFF

struct Window
{
    struct WindowTemplate window;
    u32 *tileData;
};

bool32 InitWindows(const struct WindowTemplate *templates);
u32 AddWindow(const struct WindowTemplate *template);
u32 AddWindowWithoutTileMap(const struct WindowTemplate *template);
void RemoveWindow(u32 windowId);
void FreeAllWindowBuffers(void);
void CopyWindowToVram(u32 windowId, enum ModosCopiaVentanas modo);
void CopyWindowRectToVram(u32 windowId, enum ModosCopiaVentanas modo, u32 x, u32 y, u32 w, u32 h);
void PutWindowTilemap(u32 windowId);
void PutWindowRectTilemapOverridePalette(u32 windowId, u32 x, u32 y, u32 width, u32 height, u32 palette);
void ClearWindowTilemap(u32 windowId);
void PutWindowRectTilemap(u32 windowId, u32 x, u32 y, u32 width, u32 height);
void BlitBitmapToWindow(u32 windowId, const u32 *pixels, u32 x, u32 y, u32 width, u32 height);
void BlitBitmapRectToWindow(u32 windowId, const u32 *pixels, u32 srcX, u32 srcY, u32 srcWidth, u32 srcHeight, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight);
void FillWindowPixelRect(u32 windowId, u32 fillValue, u32 x, u32 y, u32 width, u32 height);
void CopyToWindowPixelBuffer(u32 windowId, const void *src, u32 size, u32 tileOffset);
void FillWindowPixelBuffer(u32 windowId, u32 fillValue);
void ScrollWindow(u32 windowId, enum DireccionScrollWindow direccion, u32 distance, u32 fillValue);
void CallWindowFunction(u32 windowId, void ( *func)(u32, u32, u32, u32, u32, u32));
bool32 SetWindowAttribute(u32 windowId, u32 attributeId, u32 value);
u32 GetWindowAttribute(u32 windowId, u32 attributeId);
u32 WindowWidthPx(u32 windowId);
u32 WindowTemplateWidthPx(const struct WindowTemplate *template);

extern struct Window gWindows[];
extern void *gWindowBgTilemapBuffers[];

#endif // GUARD_WINDOW_H

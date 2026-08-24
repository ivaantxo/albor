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
    u16 bg:2; // Revisar si es posible hacerlo u16
    u16 charBaseIndex:2;
    u16 mapBaseIndex:5;
    u16 screenSize:2;
    u16 paletteMode:1;
    u16 priority:2;
    u16 baseTile:10;
    //u16 mosaic:1;
    //u16 wrapAround:1;
};

enum ModosFondos
{
    MODO_0, // 4 fondos normales
    MODO_1, // Fondos 0 y 1 normales, fondo 2 afín
    MODO_2, // Fondos 2 y 3 afines
};

enum Fondos
{
    FONDO_0,
    FONDO_1,
    FONDO_2,
    FONDO_3,
    NUMERO_FONDOS
};

enum ModosPaletas
{
    MODO_PALETAS_4BPP,
    MODO_PALETAS_8BPP,
};

enum DimensionesFondo
{
    FONDO_32x32,
    FONDO_64x32,
    FONDO_32x64,
    FONDO_64x64,
};

enum DimensionesFondoAfin
{
    FONDO_AFIN_16x16,
    FONDO_AFIN_32x32,
    FONDO_AFIN_64x64,
    FONDO_AFIN_128x128,
};

void ResetBgs(void);
u32 GetBgMode(void);
void ResetBgControlStructs(void);
u32 CargaFondoVram(u32 bg, const void *src, u32 size, u32 destOffset, enum ModosFondos modo);
void SetTextModeAndHideBgs(void);
bool32 IsInvalidBg(u32 bg);
void ResetBgsAndClearDma3BusyFlags(void);
void IniciaFondosDesdePlantillas(enum ModosFondos modo, const struct BgTemplate *plantillas, u32 numeroPlantillas);
void InitBgFromTemplate(const struct BgTemplate *template);
void SetBgMode(enum ModosFondos modo);
u32 CargaTilesFondo(u32 fondo, const void *ubicacionTiles, u32 tamanio, u32 posicionDestino);
u32 LoadBgTilemap(u32 bg, const void *src, u32 size, u32 destOffset);
bool32 IsDma3ManagerBusyWithBgCopy(void);
void ShowBg(u32 bg);
void HideBg(u32 bg);
void SetBgAttribute(u32 bg, u32 attributeId, u32 value);
u32 GetBgAttribute(u32 bg, u32 attributeId);
void ChangeBgX(u32 bg, s32 value, u32 op);
void ChangeBgY(u32 bg, s32 value, u32 op);
void ChangeBgY_ScreenOff(u32 bg, s32 value, u32 op);
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

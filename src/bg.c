#include <limits.h>
#include "global.h"
#include "bg.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "palette.h"

#define DISPCNT_ALL_BG_AND_MODE_BITS    (DISPCNT_BG_ALL_ON | 7)

struct BgControl
{
    struct BgConfig {
        bool32 visible;
        u32 screenSize;
        u32 priority;
        bool32 mosaic;
        bool32 wraparound;

        u32 charBaseIndex;
        u32 mapBaseIndex;
        u32 paletteMode;
    } configs[NUMERO_FONDOS];

    u32 bgVisibilityAndMode;
};

struct BgConfig2
{
    u32 baseTile;
    u32 basePalette;

    void *tilemap;
    s32 bg_x;
    s32 bg_y;
};

static struct BgControl sGpuBgConfigs;
static struct BgConfig2 sGpuBgConfigs2[NUMERO_FONDOS];
static u32 sDmaBusyBitfield[NUMERO_FONDOS];

static const struct BgConfig sZeroedBgControlStruct = { 0 };

static u32 GetBgType(u32 bg);

void ResetBgs(void)
{
    ResetBgControlStructs();
    sGpuBgConfigs.bgVisibilityAndMode = 0;
    SetTextModeAndHideBgs();
}

void SetBgMode(enum ModosFondos modo)
{
    sGpuBgConfigs.bgVisibilityAndMode &= ~7;
    sGpuBgConfigs.bgVisibilityAndMode |= modo;
}

u32 GetBgMode(void)
{
    return sGpuBgConfigs.bgVisibilityAndMode & 7;
}

void ResetBgControlStructs(void)
{
    u32 i;

    for (i = 0; i < NUMERO_FONDOS; i++)
    {
        sGpuBgConfigs.configs[i] = sZeroedBgControlStruct;
    }
}

enum
{
    BG_CTRL_ATTR_VISIBLE = 1,
    BG_CTRL_ATTR_CHARBASEINDEX = 2,
    BG_CTRL_ATTR_MAPBASEINDEX = 3,
    BG_CTRL_ATTR_SCREENSIZE = 4,
    BG_CTRL_ATTR_PALETTEMODE = 5,
    BG_CTRL_ATTR_PRIORITY = 6,
    BG_CTRL_ATTR_MOSAIC = 7,
    BG_CTRL_ATTR_WRAPAROUND = 8,
};

static void SetBgControlAttributes(u32 bg, u32 charBaseIndex, u32 mapBaseIndex, u32 screenSize, u32 paletteMode, u32 priority, u32 mosaic, u32 wraparound)
{
    if (!IsInvalidBg(bg))
    {
        if (charBaseIndex != 0xFF)
        {
            sGpuBgConfigs.configs[bg].charBaseIndex = charBaseIndex;
        }

        if (mapBaseIndex != 0xFF)
        {
            sGpuBgConfigs.configs[bg].mapBaseIndex = mapBaseIndex;
        }

        if (screenSize != 0xFF)
        {
            sGpuBgConfigs.configs[bg].screenSize = screenSize;
        }

        if (paletteMode != 0xFF)
        {
            sGpuBgConfigs.configs[bg].paletteMode = paletteMode;
        }

        if (priority != 0xFF)
        {
            sGpuBgConfigs.configs[bg].priority = priority;
        }

        if (mosaic != 0xFF)
        {
            sGpuBgConfigs.configs[bg].mosaic = mosaic;
        }

        if (wraparound != 0xFF)
        {
            sGpuBgConfigs.configs[bg].wraparound = wraparound;
        }

        sGpuBgConfigs.configs[bg].visible = 1;
    }
}

static u32 GetBgControlAttribute(u32 bg, u32 attributeId)
{
    if (!IsInvalidBg(bg) && sGpuBgConfigs.configs[bg].visible)
    {
        switch (attributeId)
        {
        case BG_CTRL_ATTR_VISIBLE:
            return sGpuBgConfigs.configs[bg].visible;
        case BG_CTRL_ATTR_CHARBASEINDEX:
            return sGpuBgConfigs.configs[bg].charBaseIndex;
        case BG_CTRL_ATTR_MAPBASEINDEX:
            return sGpuBgConfigs.configs[bg].mapBaseIndex;
        case BG_CTRL_ATTR_SCREENSIZE:
            return sGpuBgConfigs.configs[bg].screenSize;
        case BG_CTRL_ATTR_PALETTEMODE:
            return sGpuBgConfigs.configs[bg].paletteMode;
        case BG_CTRL_ATTR_PRIORITY:
            return sGpuBgConfigs.configs[bg].priority;
        case BG_CTRL_ATTR_MOSAIC:
            return sGpuBgConfigs.configs[bg].mosaic;
        case BG_CTRL_ATTR_WRAPAROUND:
            return sGpuBgConfigs.configs[bg].wraparound;
        }
    }

    return 0xFF;
}

u32 CargaFondoVram(u32 bg, const void *src, u32 size, u32 destOffset, enum ModosFondos modo)
{
    u32 offset;
    s32 cursor;

    if (IsInvalidBg(bg) || !sGpuBgConfigs.configs[bg].visible)
        return -1;

    switch (modo)
    {
    case MODO_1:
        offset = sGpuBgConfigs.configs[bg].charBaseIndex * BG_CHAR_SIZE;
        offset = destOffset + offset;
        cursor = RequestDma3Copy(src, (void *)(offset + BG_VRAM), size, DMA_REQUEST_COPY16);
        if (cursor == -1)
            return -1;
        break;
    case MODO_2:
        offset = sGpuBgConfigs.configs[bg].mapBaseIndex * BG_SCREEN_SIZE;
        offset = destOffset + offset;
        cursor = RequestDma3Copy(src, (void *)(offset + BG_VRAM), size, DMA_REQUEST_COPY16);
        if (cursor == -1)
            return -1;
        break;
    default:
        cursor = -1;
        break;
    }

    return cursor;
}

static void SyncBgVisibilityAndMode(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, (GetGpuReg(REG_OFFSET_DISPCNT) & ~DISPCNT_ALL_BG_AND_MODE_BITS) | sGpuBgConfigs.bgVisibilityAndMode);
}

void ShowBg(u32 bg)
{
    u32 value;
    if (!IsInvalidBg(bg) && sGpuBgConfigs.configs[bg].visible)
    {
        value = sGpuBgConfigs.configs[bg].priority |
                (sGpuBgConfigs.configs[bg].charBaseIndex << 2) |
                (sGpuBgConfigs.configs[bg].mosaic << 6) |
                (sGpuBgConfigs.configs[bg].paletteMode << 7) |
                (sGpuBgConfigs.configs[bg].mapBaseIndex << 8) |
                (sGpuBgConfigs.configs[bg].wraparound << 13) |
                (sGpuBgConfigs.configs[bg].screenSize << 14);

        SetGpuReg((bg << 1) + REG_OFFSET_BG0CNT, value);

        sGpuBgConfigs.bgVisibilityAndMode |= 1 << (bg + 8);
        sGpuBgConfigs.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
    SyncBgVisibilityAndMode();
}

void HideBg(u32 bg)
{
    if (!IsInvalidBg(bg))
    {
        sGpuBgConfigs.bgVisibilityAndMode &= ~(1 << (bg + 8));
        sGpuBgConfigs.bgVisibilityAndMode &= DISPCNT_ALL_BG_AND_MODE_BITS;
    }
    SyncBgVisibilityAndMode();
}

void SetTextModeAndHideBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) & ~DISPCNT_ALL_BG_AND_MODE_BITS);
}

void SetBgAffine(u32 bg, s32 srcCenterX, s32 srcCenterY, s32 dispCenterX, s32 dispCenterY, s32 scaleX, s32 scaleY, u32 rotationAngle)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    switch (sGpuBgConfigs.bgVisibilityAndMode & 7)
    {
    default:
    case 0:
        return;
    case 1:
        if (bg != 2)
            return;
        break;
    case 2:
        if (bg != 2 && bg != 3)
            return;
        break;
    }

    src.texX = srcCenterX;
    src.texY = srcCenterY;
    src.scrX = dispCenterX;
    src.scrY = dispCenterY;
    src.sx = scaleX;
    src.sy = scaleY;
    src.alpha = rotationAngle;

    BgAffineSet(&src, &dest, 1);

    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2X_L, (s16)(dest.dx));
    SetGpuReg(REG_OFFSET_BG2X_H, (s16)(dest.dx >> 16));
    SetGpuReg(REG_OFFSET_BG2Y_L, (s16)(dest.dy));
    SetGpuReg(REG_OFFSET_BG2Y_H, (s16)(dest.dy >> 16));
}

bool32 IsInvalidBg(u32 bg)
{
    if (bg >= NUMERO_FONDOS)
        return TRUE;
    else
        return FALSE;
}

void ResetBgsAndClearDma3BusyFlags(void)
{
    u32 i;
    ResetBgs();

    for (i = 0; i < NUMERO_FONDOS; i++)
    {
        sDmaBusyBitfield[i] = 0;
    }
}

void IniciaFondosDesdePlantillas(enum ModosFondos modo, const struct BgTemplate *plantillas, u32 numeroPlantillas)
{
    u32 fondo;

    SetBgMode(modo);
    ResetBgControlStructs();

    for (u32 i = 0; i < numeroPlantillas; i++)
    {
        fondo = plantillas[i].bg;
        if (fondo < NUMERO_FONDOS)
        {
            SetBgControlAttributes(fondo,
                                   plantillas[i].charBaseIndex,
                                   plantillas[i].mapBaseIndex,
                                   plantillas[i].screenSize,
                                   plantillas[i].paletteMode,
                                   plantillas[i].priority,
                                   FALSE,
                                   FALSE);

            sGpuBgConfigs2[fondo].baseTile = plantillas[i].baseTile;
            sGpuBgConfigs2[fondo].basePalette = BG_PLTT_OFFSET;

            sGpuBgConfigs2[fondo].tilemap = NULL;
            sGpuBgConfigs2[fondo].bg_x = 0;
            sGpuBgConfigs2[fondo].bg_y = 0;
        }
    }
}

void InitBgFromTemplate(const struct BgTemplate *template)
{
    u32 bg = template->bg;

    if (bg < NUMERO_FONDOS)
    {
        SetBgControlAttributes(bg,
                               template->charBaseIndex,
                               template->mapBaseIndex,
                               template->screenSize,
                               template->paletteMode,
                               template->priority,
                               0,
                               0);

        sGpuBgConfigs2[bg].baseTile = template->baseTile;
        sGpuBgConfigs2[bg].basePalette = 0;

        sGpuBgConfigs2[bg].tilemap = NULL;
        sGpuBgConfigs2[bg].bg_x = 0;
        sGpuBgConfigs2[bg].bg_y = 0;
    }
}

u32 CargaTilesFondo(u32 fondo, const void *ubicacionTiles, u32 tamanio, u32 posicionDestino)
{
    u32 tileOffset;
    u32 cursor;

    if (fondo > 3)
        return -1;

    if (GetBgControlAttribute(fondo, BG_CTRL_ATTR_PALETTEMODE) == MODO_PALETAS_4BPP)
    {
        tileOffset = POSICION_TILE_4BPP(sGpuBgConfigs2[fondo].baseTile + posicionDestino);
    }
    else
    {
        tileOffset = POSICION_TILE_8BPP(sGpuBgConfigs2[fondo].baseTile + posicionDestino);
    }

    cursor = CargaFondoVram(fondo, ubicacionTiles, tamanio, tileOffset, MODO_1);

    if (cursor == 0xFF)
    {
        return -1;
    }

    sDmaBusyBitfield[cursor / TILE_4BPP] |= (1 << (cursor % TILE_4BPP));

    return cursor;
}

u32 LoadBgTilemap(u32 bg, const void *src, u32 size, u32 destOffset)
{
    u32 cursor = CargaFondoVram(bg, src, size, destOffset * 2, MODO_2);

    if (cursor == 0xFF)
    {
        return -1;
    }

    sDmaBusyBitfield[cursor / 32] |= (1 << (cursor % 32));

    return cursor;
}

bool32 IsDma3ManagerBusyWithBgCopy(void)
{
    u32 i;

    for (i = 0; i < 128; i++)
    {
        u32 div = i / 32;
        u32 mod = i % 32;

        if ((sDmaBusyBitfield[div] & (1 << mod)))
        {
            s32 reqSpace = CheckForSpaceForDma3Request(i);
            if (reqSpace == -1)
            {
                return TRUE;
            }

            sDmaBusyBitfield[div] &= ~(1 << mod);
        }
    }

    return FALSE;
}

void SetBgAttribute(u32 bg, u32 attributeId, u32 value)
{
    switch (attributeId)
    {
    case BG_ATTR_CHARBASEINDEX:
        SetBgControlAttributes(bg, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_MAPBASEINDEX:
        SetBgControlAttributes(bg, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_SCREENSIZE:
        SetBgControlAttributes(bg, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_PALETTEMODE:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF, 0xFF);
        break;
    case BG_ATTR_PRIORITY:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF, 0xFF);
        break;
    case BG_ATTR_MOSAIC:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value, 0xFF);
        break;
    case BG_ATTR_WRAPAROUND:
        SetBgControlAttributes(bg, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, value);
        break;
    }
}

u32 GetBgAttribute(u32 bg, u32 attributeId)
{
    switch (attributeId)
    {
    case BG_ATTR_CHARBASEINDEX:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_CHARBASEINDEX);
    case BG_ATTR_MAPBASEINDEX:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_MAPBASEINDEX);
    case BG_ATTR_SCREENSIZE:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
    case BG_ATTR_PALETTEMODE:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_PALETTEMODE);
    case BG_ATTR_PRIORITY:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_PRIORITY);
    case BG_ATTR_MOSAIC:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_MOSAIC);
    case BG_ATTR_WRAPAROUND:
        return GetBgControlAttribute(bg, BG_CTRL_ATTR_WRAPAROUND);
    case BG_ATTR_METRIC:
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            return GetBgMetricTextMode(bg, 0) * 2048;
        case BG_TYPE_AFFINE:
            return GetBgMetricAffineMode(bg, 0) * 256;
        default:
            return 0;
        }
    case BG_ATTR_TYPE:
        return GetBgType(bg);
    case BG_ATTR_BASETILE:
        return sGpuBgConfigs2[bg].baseTile;
    default:
        return -1;
    }
}

s32 ChangeBgX(u32 bg, s32 value, u32 op)
{
    u32 mode, temp1, temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_x = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_x += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_x -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_x >> 8;
        SetGpuReg(REG_OFFSET_BG0HOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_x >> 8;
        SetGpuReg(REG_OFFSET_BG1HOFS, temp1);
        break;
    case 2:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[2].bg_x >> 8;
            SetGpuReg(REG_OFFSET_BG2HOFS, temp1);
        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_x >> 16;
            temp2 = sGpuBgConfigs2[2].bg_x & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG2X_H, temp1);
            SetGpuReg(REG_OFFSET_BG2X_L, temp2);
        }
        break;
    case 3:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[3].bg_x >> 8;
            SetGpuReg(REG_OFFSET_BG3HOFS, temp1);
        }
        else if (mode == MODO_2)
        {
            temp1 = sGpuBgConfigs2[3].bg_x >> 16;
            temp2 = sGpuBgConfigs2[3].bg_x & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG3X_H, temp1);
            SetGpuReg(REG_OFFSET_BG3X_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_x;
}

s32 GetBgX(u32 bg)
{
    if (IsInvalidBg(bg))
        return -1;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return -1;
    else
        return sGpuBgConfigs2[bg].bg_x;
}

s32 ChangeBgY(u32 bg, s32 value, u32 op)
{
    u32 mode, temp1, temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_y = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_y += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_y -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_y >> 8;
        SetGpuReg(REG_OFFSET_BG0VOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_y >> 8;
        SetGpuReg(REG_OFFSET_BG1VOFS, temp1);
        break;
    case 2:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 8;
            SetGpuReg(REG_OFFSET_BG2VOFS, temp1);
        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 16;
            temp2 = sGpuBgConfigs2[2].bg_y & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG2Y_H, temp1);
            SetGpuReg(REG_OFFSET_BG2Y_L, temp2);
        }
        break;
    case 3:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 8;
            SetGpuReg(REG_OFFSET_BG3VOFS, temp1);
        }
        else if (mode == MODO_2)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 16;
            temp2 = sGpuBgConfigs2[3].bg_y & 0xFFFF;
            SetGpuReg(REG_OFFSET_BG3Y_H, temp1);
            SetGpuReg(REG_OFFSET_BG3Y_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_y;
}

s32 ChangeBgY_ScreenOff(u32 bg, s32 value, u32 op)
{
    u32 mode, temp1, temp2;

    if (IsInvalidBg(bg) || !GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        return -1;
    }

    switch (op)
    {
    case BG_COORD_SET:
    default:
        sGpuBgConfigs2[bg].bg_y = value;
        break;
    case BG_COORD_ADD:
        sGpuBgConfigs2[bg].bg_y += value;
        break;
    case BG_COORD_SUB:
        sGpuBgConfigs2[bg].bg_y -= value;
        break;
    }

    mode = GetBgMode();

    switch (bg)
    {
    case 0:
        temp1 = sGpuBgConfigs2[0].bg_y >> 8;
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, temp1);
        break;
    case 1:
        temp1 = sGpuBgConfigs2[1].bg_y >> 8;
        SetGpuReg_ForcedBlank(REG_OFFSET_BG1VOFS, temp1);
        break;
    case 2:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 8;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2VOFS, temp1);

        }
        else
        {
            temp1 = sGpuBgConfigs2[2].bg_y >> 16;
            temp2 = sGpuBgConfigs2[2].bg_y & 0xFFFF;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_H, temp1);
            SetGpuReg_ForcedBlank(REG_OFFSET_BG2Y_L, temp2);
        }
        break;
    case 3:
        if (mode == MODO_0)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 8;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3VOFS, temp1);
        }
        else if (mode == MODO_2)
        {
            temp1 = sGpuBgConfigs2[3].bg_y >> 16;
            temp2 = sGpuBgConfigs2[3].bg_y & 0xFFFF;
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_H, temp1);
            SetGpuReg_ForcedBlank(REG_OFFSET_BG3Y_L, temp2);
        }
        break;
    }

    return sGpuBgConfigs2[bg].bg_y;
}

s32 GetBgY(u32 bg)
{
    if (IsInvalidBg(bg))
        return -1;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return -1;
    else
        return sGpuBgConfigs2[bg].bg_y;
}

void SetBgTilemapBuffer(u32 bg, void *tilemap)
{
    if (!IsInvalidBg(bg) && GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        sGpuBgConfigs2[bg].tilemap = tilemap;
    }
}

void UnsetBgTilemapBuffer(u32 bg)
{
    if (!IsInvalidBg(bg) && GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
    {
        sGpuBgConfigs2[bg].tilemap = NULL;
    }
}

void *GetBgTilemapBuffer(u32 bg)
{
    if (IsInvalidBg(bg))
        return NULL;
    else if (!GetBgControlAttribute(bg, BG_CTRL_ATTR_VISIBLE))
        return NULL;
    else
        return sGpuBgConfigs2[bg].tilemap;
}

void CopyToBgTilemapBuffer(u32 bg, const void *src, u32 mode, u32 destOffset)
{
    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        if (mode != MODO_0)
            CopiaCpu16(src, (void *)(sGpuBgConfigs2[bg].tilemap + (destOffset * 2)), mode);
        else
            LZ77UnCompWram(src, (void *)(sGpuBgConfigs2[bg].tilemap + (destOffset * 2)));
    }
}

void CopyBgTilemapBufferToVram(u32 bg)
{
    u32 sizeToLoad;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            sizeToLoad = GetBgMetricTextMode(bg, 0) * 2048;
            break;
        case BG_TYPE_AFFINE:
            sizeToLoad = GetBgMetricAffineMode(bg, 0) * 256;
            break;
        default:
            sizeToLoad = 0;
            break;
        }
        CargaFondoVram(bg, sGpuBgConfigs2[bg].tilemap, sizeToLoad, 0, MODO_2);
    }
}

void CopyToBgTilemapBufferRect(u32 bg, const void *src, u32 destX, u32 destY, u32 width, u32 height)
{
    u32 mode;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
        {
            const u16 *srcCopy = src;
            for (u32 j = destY; j < (destY + height); j++)
            {
                for (u32 i = destX; i < (destX + width); i++)
                {
                    ((u16 *)sGpuBgConfigs2[bg].tilemap)[((j * 32) + i)] = *srcCopy++;
                }
            }
            break;
        }
        case BG_TYPE_AFFINE:
        {
            const u8 *srcCopy = src;
            mode = GetBgMetricAffineMode(bg, 1);
            for (u32 j = destY; j < (destY + height); j++)
            {
                for (u32 i = destX; i < (destX + width); i++)
                {
                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[((j * mode) + i)] = *srcCopy++;
                }
            }
            break;
        }
        }
    }
}

void CopyToBgTilemapBufferRect_ChangePalette(u32 bg, const void *src, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight, u32 palette)
{
    CopyRectToBgTilemapBufferRect(bg, src, 0, 0, rectWidth, rectHeight, destX, destY, rectWidth, rectHeight, palette, 0, 0);
}

void CopyRectToBgTilemapBufferRect(u32 bg, const void *src, u32 srcX, u32 srcY, u32 srcWidth, u32 srcHeight, u32 destX, u32 destY, u32 rectWidth, u32 rectHeight, u32 palette1, s32 tileOffset, s32 palette2)
{
    u32 screenWidth, screenHeight, screenSize, var;
    const void *srcPtr;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
        screenWidth = GetBgMetricTextMode(bg, 1) * 32;
        screenHeight = GetBgMetricTextMode(bg, 2) * 32;
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            srcPtr = src + ((srcY * srcWidth) + srcX) * 2;
            for (u32 j = destY; j < (destY + rectHeight); j++)
            {
                for (u32 i = destX; i < (destX + rectWidth); i++)
                {
                    u32 index = GetTileMapIndexFromCoords(i, j, screenSize, screenWidth, screenHeight);
                    CopyTileMapEntry(srcPtr, sGpuBgConfigs2[bg].tilemap + (index * 2), palette1, tileOffset, palette2);
                    srcPtr += 2;
                }
            }
            break;
        case BG_TYPE_AFFINE:
            srcPtr = src + ((srcY * srcWidth) + srcX);
            var = GetBgMetricAffineMode(bg, 1);
            for (u32 j = destY; j < (destY + rectHeight); j++)
            {
                for (u32 i = destX; i < (destX + rectWidth); i++)
                {
                    *(u8 *)(sGpuBgConfigs2[bg].tilemap + ((var * j) + i)) = *(u8 *)(srcPtr) + tileOffset;
                    srcPtr++;
                }
                srcPtr += (srcWidth - rectWidth);
            }
            break;
        }
    }
}

void FillBgTilemapBufferRect_Palette0(u32 bg, u32 tileNum, u32 x, u32 y, u32 width, u32 height)
{
    u32 mode;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    ((u16 *)sGpuBgConfigs2[bg].tilemap)[((j * 32) + i)] = tileNum;
                }
            }
            break;
        case BG_TYPE_AFFINE:
            mode = GetBgMetricAffineMode(bg, 1);
            for (u32 j = y; j < (y + height); j++)
            {
                for (u32 i = x; i < (x + width); i++)
                {
                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[((j * mode) + i)] = tileNum;
                }
            }
            break;
        }
    }
}

void FillBgTilemapBufferRect(u32 bg, u32 tileNum, u32 x, u32 y, u32 width, u32 height, u32 palette)
{
    WriteSequenceToBgTilemapBuffer(bg, tileNum, x, y, width, height, palette, 0);
}

void WriteSequenceToBgTilemapBuffer(u32 bg, u16 firstTileNum, u32 x, u32 y, u32 width, u32 height, u32 paletteSlot, s32 tileNumDelta)
{
    u32 mode, mode2, mode3, attribute;

    if (!IsInvalidBg(bg) && !IsTileMapOutsideWram(bg))
    {
        attribute = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);
        mode = GetBgMetricTextMode(bg, 1) * 32;
        mode2 = GetBgMetricTextMode(bg, 2) * 32;

        switch (GetBgType(bg))
        {
        case BG_TYPE_NORMAL:
            for (u32 j = 0; j < height; j++)
            {
                for (u32 i = 0; i < width; i++)
                {
                    u32 actualX = x + i;
                    u32 actualY = y + j;

                    CopyTileMapEntry(
                        &firstTileNum,
                        &((u16 *)sGpuBgConfigs2[bg].tilemap)[GetTileMapIndexFromCoords(actualX, actualY, attribute, mode, mode2)],
                        paletteSlot,
                        0,
                        0);

                    firstTileNum = (firstTileNum & 64512) + ((firstTileNum + tileNumDelta) & 1023);
                }
            }
            break;

        case BG_TYPE_AFFINE:
            mode3 = GetBgMetricAffineMode(bg, 1);

            for (u32 j = 0; j < height; j++)
            {
                for (u32 i = 0; i < width; i++)
                {
                    u32 actualX = x + i;
                    u32 actualY = y + j;

                    ((u8 *)sGpuBgConfigs2[bg].tilemap)[(actualY * mode3) + actualX] = firstTileNum;

                    firstTileNum = (firstTileNum & 64512) + ((firstTileNum + tileNumDelta) & 1023);
                }
            }
            break;
        }
    }
}

u32 GetBgMetricTextMode(u32 bg, u32 whichMetric)
{
    u32 screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);

    switch (whichMetric)
    {
    case 0:
        switch (screenSize)
        {
        case 0:
            return 1;
        case 1:
        case 2:
            return 2;
        case 3:
            return 4;
        }
        break;
    case 1:
        switch (screenSize)
        {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        }
        break;
    case 2:
        switch (screenSize)
        {
        case 0:
        case 1:
            return 1;
        case 2:
        case 3:
            return 2;
        }
        break;
    }
    return 0;
}

u32 GetBgMetricAffineMode(u32 bg, u32 whichMetric)
{
    u32 screenSize = GetBgControlAttribute(bg, BG_CTRL_ATTR_SCREENSIZE);

    switch (whichMetric)
    {
    case 0:
        switch (screenSize)
        {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 16;
        case 3:
            return 64;
        }
        break;
    case 1:
    case 2:
        return 16 << screenSize;
    }
    return 0;
}

u32 GetTileMapIndexFromCoords(u32 x, u32 y, u32 screenSize, u32 screenWidth, u32 screenHeight)
{
    x = x & (screenWidth - 1);
    y = y & (screenHeight - 1);

    if (x >= screenWidth || y >= screenHeight)
    {
        return 0;
    }

    switch (screenSize)
    {
    case 0:
    case 2:
        break;
    case 3:
        if (y >= 32)
            y += 32;
    case 1:
        if (x >= 32)
        {
            x -= 32;
            y += 32;
        }
        break;
    }
    return (y * 32) + x;
}

void CopyTileMapEntry(const u16 *src, u16 *dest, s32 palette1, s32 tileOffset, s32 palette2)
{
    u32 var;

    switch (palette1)
    {
    case 0 ... 15:
        var = ((*src + tileOffset) & 0xFFF) + ((palette1 + palette2) << 12);
        break;
    case 16:
        var = *dest;
        var &= 64512;
        var += palette2 << 12;
        var |= (*src + tileOffset) & 1023;
        break;
    default:
    case 17 ... INT_MAX:
        var = *src + tileOffset + (palette2 << 12);
        break;
    }
    *dest = var;
}

static u32 GetBgType(u32 bg)
{
    u32 mode = GetBgMode();

    switch (bg)
    {
    case 0:
    case 1:
        switch (mode)
        {
        case MODO_0:
        case MODO_1:
            return BG_TYPE_NORMAL;
        }
        break;
    case 2:
        switch (mode)
        {
        case MODO_0:
            return BG_TYPE_NORMAL;
        case MODO_1:
        case MODO_2:
            return BG_TYPE_AFFINE;
        }
        break;
    case 3:
        switch (mode)
        {
        case 0:
            return BG_TYPE_NORMAL;
        case 2:
            return BG_TYPE_AFFINE;
        }
        break;
    }

    return BG_TYPE_NONE;
}

bool32 IsTileMapOutsideWram(u32 bg)
{
    if (sGpuBgConfigs2[bg].tilemap > (void *)IWRAM_END)
        return TRUE;
    else if (sGpuBgConfigs2[bg].tilemap == NULL)
        return TRUE;
    else
        return FALSE;
}

#include "global.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "fieldmap.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sTilesetAnimCounter;
static u16 sTilesetAnimCounterMax;
static void (*sTilesetAnimCallback)(u16);

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    u32 i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i ++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

// Animaciones de los tilesets de albor, las que mete tools/mapeado (o el fork de
// porymap). El animations.bin del tileset tiene una ficha por animacion, una a cero al
// final, y detras los fotogramas, seguidos y en 4bpp. Cada `interval` fotogramas del
// juego se copia el siguiente encima de los tiles de la animacion en la VRAM. Las
// paletas no cambian: los tiles se pintan con la que tenga cargada el mapa.
struct TilesetAnimation
{
    u16 tile;       // el primero
    u16 numTiles;
    u16 numFrames;
    u16 interval;
    u32 offset;     // desde el principio del archivo hasta su fotograma 0
    u8 palette;     // la del tileset; el juego no la necesita
    u8 width;       // en tiles; tampoco
    u8 name[18];
};

static const u32 *sTilesetAnimations;

static void TilesetAnim_Animations(u16 timer)
{
    const struct TilesetAnimation *anim;
    u32 frame, size;

    for (anim = (const struct TilesetAnimation *)sTilesetAnimations; anim->numTiles != 0; anim++)
    {
        if (anim->numFrames < 2 || anim->interval == 0 || timer % anim->interval != 0)
            continue;
        frame = (timer / anim->interval) % anim->numFrames;
        size = anim->numTiles * TILE_4BPP;
        AppendTilesetAnimToBuffer((const u16 *)((const u8 *)sTilesetAnimations + anim->offset + frame * size),
                                  (u16 *)(BG_VRAM + POSICION_TILE_4BPP(anim->tile)), size);
    }
}

static u32 Mcd(u32 a, u32 b)
{
    while (b != 0)
    {
        u32 r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// El contador vuelve a 0 cuando todas han dado una vuelta entera, para que ninguna
// pegue un salto; si eso pasa de 65535, se da por bueno el salto.
static void InitTilesetAnim_Animations(const u32 *animations)
{
    const struct TilesetAnimation *anim = (const struct TilesetAnimation *)animations;
    u32 vuelta = 1;

    if (anim == NULL || anim->numTiles == 0)
        return;
    for (; anim->numTiles != 0; anim++)
    {
        u32 suya = anim->interval * anim->numFrames;
        if (suya != 0)
            vuelta = vuelta / Mcd(vuelta, suya) * suya;
        if (vuelta > 0xFFFF)
            vuelta = 0xFFFF;
    }
    sTilesetAnimations = animations;
    sTilesetAnimCounter = 0;
    sTilesetAnimCounterMax = vuelta;
    sTilesetAnimCallback = TilesetAnim_Animations;
}

// El callback del tileset, si tiene, va despues: para lo que no sea cambiar tiles.
void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    sTilesetAnimCounter = 0;
    sTilesetAnimCounterMax = 0;
    sTilesetAnimCallback = NULL;
    InitTilesetAnim_Animations(gMapHeader.mapLayout->tileset->animations);
    if (gMapHeader.mapLayout->tileset->callback)
        gMapHeader.mapLayout->tileset->callback();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sTilesetAnimCounter >= sTilesetAnimCounterMax)
        sTilesetAnimCounter = 0;
    if (sTilesetAnimCallback)
        sTilesetAnimCallback(sTilesetAnimCounter);
}

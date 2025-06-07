#include "global.h"
#include "util.h"
#include "sprite.h"
#include "palette.h"
#include "pokemon.h"
#include "constants/rgb.h"

static const struct SpriteTemplate sInvisibleSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *))
{
    u8 sprite = CreateSprite(&sInvisibleSpriteTemplate, DISPLAY_WIDTH + 8, DISPLAY_HEIGHT + 8, 14);
    gSprites[sprite].invisible = TRUE;
    gSprites[sprite].callback = callback;
    return sprite;
}

void StoreWordInTwoHalfwords(u16 *h, u32 w)
{
    h[0] = (u16)(w);
    h[1] = (u16)(w >> 16);
}

void LoadWordFromTwoHalfwords(u16 *h, u32 *w)
{
    *w = h[0] | (s16)h[1] << 16;
}

int CountTrailingZeroBits(u32 value)
{
    u32 i;

    for (i = 0; i < 32; i++)
    {
        if ((value & 1) == 0)
            value >>= 1;
        else
            return i;
    }
    return 0;
}

void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor)
{
    u32 i;
    struct PlttData *data2 = (struct PlttData *)&blendColor;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
        s8 r = data1->r;
        s8 g = data1->g;
        s8 b = data1->b;

        gPlttBufferFaded[index] = RGB(r + (((data2->r - r) * coeff) >> 4),
                                      g + (((data2->g - g) * coeff) >> 4),
                                      b + (((data2->b - b) * coeff) >> 4));
    }
}

#define LIMITADOR_VARIACION_PALETAS 80  // Rango total en grados en HSL (que van desde 0 a 360º). 80 = ± 40

static s32 CalcularDesplazamientoDesdePersonalidad(u32 personalidad)
{
    u32 semilla = personalidad & 0xFF; // Solo 8 bits
    return ((semilla * LIMITADOR_VARIACION_PALETAS) / 255) - (LIMITADOR_VARIACION_PALETAS / 2);
}

static void DesplazaTonoPaletaBase(const u16 *src, u16 *dst, s32 desplazamiento)
{
    for (u32 i = 0; i < COLORES_POR_PALETA; i++)
    {
        u32 color = src[i];
        s32 r = GET_R(color);
        s32 g = GET_G(color);
        s32 b = GET_B(color);

        s32 max = r > g ? (r > b ? r : b) : (g > b ? g : b);
        s32 min = r < g ? (r < b ? r : b) : (g < b ? g : b);
        s32 delta = max - min;

        s32 tono;
        if (delta == 0)
            tono = 0;
        else if (max == r)
            tono = 60 * (g - b) / delta;
        else if (max == g)
            tono = 60 * (b - r) / delta + 120;
        else
            tono = 60 * (r - g) / delta + 240;

        if (tono < 0)
            tono += 360;

        tono = (tono + desplazamiento) % 360;
        if (tono < 0)
            tono += 360;

        s32 sat = (max == 0) ? 0 : ((delta * 255) / max);
        s32 val = max;

        s32 C = (val * sat) / 255;
        s32 X = (C * (60 - abs((tono % 120) - 60))) / 60;
        s32 m = val - C;

        s32 r1 = 0, g1 = 0, b1 = 0;
        if (tono < 60)          { r1 = C; g1 = X; b1 = 0; }
        else if (tono < 120)    { r1 = X; g1 = C; b1 = 0; }
        else if (tono < 180)    { r1 = 0; g1 = C; b1 = X; }
        else if (tono < 240)    { r1 = 0; g1 = X; b1 = C; }
        else if (tono < 300)    { r1 = X; g1 = 0; b1 = C; }
        else                    { r1 = C; g1 = 0; b1 = X; }

        s32 R = r1 + m;
        s32 G = g1 + m;
        s32 B = b1 + m;

        if (R > RGB_MAXIMO) R = RGB_MAXIMO;
        if (G > RGB_MAXIMO) G = RGB_MAXIMO;
        if (B > RGB_MAXIMO) B = RGB_MAXIMO;

        dst[i] = RGB(R, G, B);
    }
}

void DesplazaTonoPaleta(u32 offsetPaleta, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoPaletaBase(&gPlttBufferUnfaded[offsetPaleta], &gPlttBufferFaded[offsetPaleta], desplazamiento);
    CpuSmartCopy32(&gPlttBufferFaded[offsetPaleta], &gPlttBufferUnfaded[offsetPaleta], PLTT_SIZE_4BPP);
}

void DesplazaTonoPaletaBuffer(u16 *buffer, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoPaletaBase(buffer, buffer, desplazamiento);
}

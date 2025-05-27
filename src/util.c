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

const u8 gMiscBlank_Gfx[] = INCBIN_U8("graphics/interface/blank.4bpp");

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
    u8 i;

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
    u16 i;
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

#define LIMITADOR_DESPLAZAMIENTO_PALETA 80  // GRADOS EN VALOR ABSOLUTO QUE PUEDE VARIAR LA PALETA EN HSL (0-360). POR EJEMPLO, 30 PUEDE SER +-15

void DesplazaTonoPaleta(u32 offsetPaleta, u32 personalidad)
{
    s32 desplazamiento = (s32)((personalidad & 0xFF) * LIMITADOR_DESPLAZAMIENTO_PALETA / 255) - (LIMITADOR_DESPLAZAMIENTO_PALETA / 2);

    for (u32 i = 0; i < NUMERO_COLORES_POR_PALETA; i++)
    {
        u32 color = gPlttBufferUnfaded[offsetPaleta + i];

        u32 r = GET_R(color);
        u32 g = GET_G(color);
        u32 b = GET_B(color);

        u32 max = r > g ? (r > b ? r : b) : (g > b ? g : b);
        u32 min = r < g ? (r < b ? r : b) : (g < b ? g : b);
        s32 delta = (s32)(max - min);
        s32 tono;

        if (delta == 0)
            tono = 0;
        else if (max == r)
            tono = 60 * ((s32)(g - b)) / delta;
        else if (max == g)
            tono = 60 * ((s32)(b - r)) / delta + 120;
        else
            tono = 60 * ((s32)(r - g)) / delta + 240;

        if (tono < 0)
            tono += 360;

        tono = (tono + desplazamiento) % 360;
        if (tono < 0)
            tono += 360;

        // Saturación y valor (con escala 0–31)
        u32 valor = max;
        u32 sat = (max == 0) ? 0 : (255 * (u32)delta) / max;

        u32 C = (valor * sat) / 255;
        u32 X = (C * (60 - abs((tono % 120) - 60))) / 60;
        u32 m = valor - C;

        u32 r1 = 0, g1 = 0, b1 = 0;
        if (tono < 60)       { r1 = C; g1 = X; b1 = 0; }
        else if (tono < 120) { r1 = X; g1 = C; b1 = 0; }
        else if (tono < 180) { r1 = 0; g1 = C; b1 = X; }
        else if (tono < 240) { r1 = 0; g1 = X; b1 = C; }
        else if (tono < 300) { r1 = X; g1 = 0; b1 = C; }
        else                 { r1 = C; g1 = 0; b1 = X; }

        u32 nuevoR = r1 + m;
        u32 nuevoG = g1 + m;
        u32 nuevoB = b1 + m;

        if (nuevoR > RGB_MAXIMO) nuevoR = RGB_MAXIMO;
        if (nuevoG > RGB_MAXIMO) nuevoG = RGB_MAXIMO;
        if (nuevoB > RGB_MAXIMO) nuevoB = RGB_MAXIMO;

        gPlttBufferFaded[offsetPaleta + i] = RGB(nuevoR, nuevoG, nuevoB);
    }
}

void DesplazaTonoPaletaBuffer(u16 *buffer, u32 personalidad)
{
    s32 desplazamiento = (s32)((personalidad & 0xFF) * LIMITADOR_DESPLAZAMIENTO_PALETA / 255) - (LIMITADOR_DESPLAZAMIENTO_PALETA / 2);

    for (u32 i = 0; i < NUMERO_COLORES_POR_PALETA; i++)
    {
        u16 color = buffer[i];

        u32 r = GET_R(color);
        u32 g = GET_G(color);
        u32 b = GET_B(color);

        u32 max = r > g ? (r > b ? r : b) : (g > b ? g : b);
        u32 min = r < g ? (r < b ? r : b) : (g < b ? g : b);
        s32 delta = (s32)(max - min);
        s32 tono;

        if (delta == 0)
            tono = 0;
        else if (max == r)
            tono = 60 * ((s32)(g - b)) / delta;
        else if (max == g)
            tono = 60 * ((s32)(b - r)) / delta + 120;
        else
            tono = 60 * ((s32)(r - g)) / delta + 240;

        if (tono < 0)
            tono += 360;

        tono = (tono + desplazamiento) % 360;
        if (tono < 0)
            tono += 360;

        u32 valor = max;
        u32 sat = (max == 0) ? 0 : (255 * delta) / max;

        u32 C = (valor * sat) / 255;
        u32 X = (C * (60 - abs((tono % 120) - 60))) / 60;
        u32 m = valor - C;

        u32 r1 = 0, g1 = 0, b1 = 0;
        if (tono < 60)       { r1 = C; g1 = X; b1 = 0; }
        else if (tono < 120) { r1 = X; g1 = C; b1 = 0; }
        else if (tono < 180) { r1 = 0; g1 = C; b1 = X; }
        else if (tono < 240) { r1 = 0; g1 = X; b1 = C; }
        else if (tono < 300) { r1 = X; g1 = 0; b1 = C; }
        else                 { r1 = C; g1 = 0; b1 = X; }

        u32 nuevoR = r1 + m;
        u32 nuevoG = g1 + m;
        u32 nuevoB = b1 + m;

        if (nuevoR > RGB_MAXIMO) nuevoR = RGB_MAXIMO;
        if (nuevoG > RGB_MAXIMO) nuevoG = RGB_MAXIMO;
        if (nuevoB > RGB_MAXIMO) nuevoB = RGB_MAXIMO;

        buffer[i] = RGB(nuevoR, nuevoG, nuevoB);
    }
}

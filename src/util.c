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

#define CONSTANTE_DE_PALETAS_UNICAS 100

void UniquePalette(u16 palOffset, u32 personality)
{
    u32 i;
    u32 value = ((personality >> 8) & 65535) % CONSTANTE_DE_PALETAS_UNICAS;

    for (i = 0; i < 16; i++)
    {
        u32 index = i + palOffset;
        struct PlttData *data = (struct PlttData *)&gPlttBufferUnfaded[index];
        
        s32 r = (data->r * 1000) / 31;
        s32 g = (data->g * 1000) / 31;
        s32 b = (data->b * 1000) / 31;
        s32 maxv, minv, d, h, s, l, o, p, q;

        maxv = r;
        if (g > maxv) maxv = g;
        if (b > maxv) maxv = b;

        minv = r;
        if (g < minv) minv = g;
        if (b < minv) minv = b;

        d = maxv - minv;
        l = (maxv + minv) / 2;
        s = (maxv == minv) ? 0 : ((l > 500) ? (1000 * d / (2000 - maxv - minv)) : (1000 * d / (maxv + minv)));

        if (maxv != minv)
        {
            if (maxv == r)
                h = (g < b) ? (1000 * (g - b) / d + 6000) : (1000 * (g - b) / d);
            else if (maxv == g)
                h = 1000 * (b - r) / d + 2000;
            else
                h = 1000 * (r - g) / d + 4000;

            h /= 6;
        }
        else
            h = 0;

        if (personality % 2 == 0)
            h = (h + value + 1000) % 1000;
        else 
            h = (h - value + 1000) % 1000;

        if (s != 0)
        {
            o = (h + 333) % 1000;

            p = (l < 500) ? (l * (s + 1000) / 1000) : (l + s - l * s / 1000);
            q = l * 2 - p;

            if (o < 167)
                r = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                r = p;
            else if (o < 667)
                r = q + (p - q) * (667 - o) * 6 / 1000;
            else
                r = q;

            o = h;

            if (o < 167)
                g = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                g = p;
            else if (o < 667)
                g = q + (p - q) * (667 - o) * 6 / 1000;
            else
                g = q;

            o = (h + 1000 - 333) % 1000;

            if (o < 167)
                b = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                b = p;
            else if (o < 667)
                b = q + (p - q) * (667 - o) * 6 / 1000;
            else
                b = q;
        }
        else
        {
            r = l;
            g = l;
            b = l;
        }
        gPlttBufferFaded[index] = RGB((u8)(r * 31 / 1000), (u8)(g * 31 / 1000), (u8)(b * 31 / 1000));
    }
}

void UniquePaletteBuffered(u16 * buffer, u32 personality)
{
    u32 i;
    u32 value = ((personality >> 8) & 65535) % CONSTANTE_DE_PALETAS_UNICAS;

    for (i = 0; i < 16; i++)
    {
        struct PlttData *data = (struct PlttData *)&buffer[i];

        s32 r = (data->r * 1000) / 31;
        s32 g = (data->g * 1000) / 31;
        s32 b = (data->b * 1000) / 31;
        s32 maxv, minv, d, h, s, l, o, p, q;

        maxv = r;
        if (g > maxv) maxv = g;
        if (b > maxv) maxv = b;

        minv = r;
        if (g < minv) minv = g;
        if (b < minv) minv = b;

        d = maxv - minv;
        l = (maxv + minv) / 2;
        s = (maxv == minv) ? 0 : ((l > 500) ? (1000 * d / (2000 - maxv - minv)) : (1000 * d / (maxv + minv)));

        if (maxv != minv)
        {
            if (maxv == r)
                h = (g < b) ? (1000 * (g - b) / d + 6000) : (1000 * (g - b) / d);
            else if (maxv == g)
                h = 1000 * (b - r) / d + 2000;
            else
                h = 1000 * (r - g) / d + 4000;
            h /= 6;
        }
        else
            h = 0;

        if (personality % 2 == 0)
            h = (h + value + 1000) % 1000;
        else 
            h = (h - value + 1000) % 1000;

        if (s != 0)
        {
            o = (h + 333) % 1000;

            p = (l < 500) ? (l * (s + 1000) / 1000) : (l + s - l * s / 1000);
            q = l * 2 - p;

            if (o < 167)
                r = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                r = p;
            else if (o < 667)
                r = q + (p - q) * (667 - o) * 6 / 1000;
            else
                r = q;

            o = h;

            if (o < 167)
                g = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                g = p;
            else if (o < 667)
                g = q + (p - q) * (667 - o) * 6 / 1000;
            else
                g = q;

            o = (h + 1000 - 333) % 1000;

            if (o < 167)
                b = q + (p - q) * o * 6 / 1000;
            else if (o < 500)
                b = p;
            else if (o < 667)
                b = q + (p - q) * (667 - o) * 6 / 1000;
            else
                b = q;
        }
        else
        {
            r = l;
            g = l;
            b = l;
        }

        buffer[i] = RGB((u8)(r * 31 / 1000), (u8)(g * 31 / 1000), (u8)(b * 31 / 1000));
    }
}

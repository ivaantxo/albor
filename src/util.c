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
    u8 sprite = CreateSprite(&sInvisibleSpriteTemplate, ANCHO_PANTALLA + 8, ALTURA_PANTALLA + 8, 14);
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

void BlendPalette(u32 palOffset, u32 numEntries, u32 coeff, u32 blendColor)
{
    struct PlttData *data2 = (struct PlttData *)&blendColor;
    for (u32 i = 0; i < numEntries; i++)
    {
        u32 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
        s32 r = data1->r;
        s32 g = data1->g;
        s32 b = data1->b;

        gPlttBufferFaded[index] = RGB(r + (((data2->r - r) * coeff) >> 4),
                                      g + (((data2->g - g) * coeff) >> 4),
                                      b + (((data2->b - b) * coeff) >> 4));
    }
}

#define LIMITADOR_VARIACION_PALETAS 80 // Rango total en grados en HSL (que van desde 0 a 360º). 80 = ± 40

static s32 CalcularDesplazamientoDesdePersonalidad(u32 personalidad)
{
    u32 semilla = personalidad & 0xFF; // Solo 8 bits
    return ((semilla * LIMITADOR_VARIACION_PALETAS) / 255) - (LIMITADOR_VARIACION_PALETAS / 2);
}

// Convierte 5 bits [0..31] a 8 bits [0..255]
static inline s32 Componente5a8(s32 c5)
{
    return (c5 * 255 + 15) / 31;
}

// Convierte 8 bits [0..255] a 5 bits [0..31]
static inline s32 Componente8a5(s32 c8)
{
    return (c8 * 31 + 127) / 255;
}

// Rota solo el tono del color en espacio HSV, manteniendo saturación y valor.
static void DesplazaTonoPaletaBase(const u16 *src, u16 *dst, s32 desplazamiento)
{
    for (u32 i = 0; i < COLORES_POR_PALETA; i++)
    {
        u16 colorRaw = src[i];
        u16 marcador = IS_ALPHA(colorRaw) ? RGB_ALPHA : 0;
        u16 color15 = colorRaw & ~RGB_ALPHA;

        s32 r = Componente5a8(GET_R(color15));
        s32 g = Componente5a8(GET_G(color15));
        s32 b = Componente5a8(GET_B(color15));

        s32 maxc = r > g ? (r > b ? r : b) : (g > b ? g : b);
        s32 minc = r < g ? (r < b ? r : b) : (g < b ? g : b);
        s32 delta = maxc - minc;

        // Si el color es neutro (gris, blanco, negro), no tiene tono → no se modifica.
        if (delta == 0)
        {
            dst[i] = colorRaw;
            continue;
        }

        // Calcula el tono original (0..359)
        s32 h;
        if (maxc == r)
            h = 60 * (g - b) / delta;
        else if (maxc == g)
            h = 60 * (b - r) / delta + 120;
        else
            h = 60 * (r - g) / delta + 240;
        if (h < 0)
            h += 360;

        // Aplica desplazamiento (solo tono)
        h = (h + desplazamiento) % 360;
        if (h < 0)
            h += 360;

        // Conserva saturación y valor originales
        s32 s = (maxc == 0) ? 0 : (delta * 255) / maxc;
        s32 v = maxc;

        // Reconstruye color en base a nuevo tono (manteniendo s y v)
        s32 C = (v * s) / 255;
        s32 hueMod = h % 120;
        s32 X = (C * (60 - abs(hueMod - 60))) / 60;
        s32 m = v - C;

        s32 r1, g1, b1;
        if (h < 60)
        {
            r1 = C;
            g1 = X;
            b1 = 0;
        }
        else if (h < 120)
        {
            r1 = X;
            g1 = C;
            b1 = 0;
        }
        else if (h < 180)
        {
            r1 = 0;
            g1 = C;
            b1 = X;
        }
        else if (h < 240)
        {
            r1 = 0;
            g1 = X;
            b1 = C;
        }
        else if (h < 300)
        {
            r1 = X;
            g1 = 0;
            b1 = C;
        }
        else
        {
            r1 = C;
            g1 = 0;
            b1 = X;
        }

        // Ajusta brillo base (m)
        s32 R8 = r1 + m;
        s32 G8 = g1 + m;
        s32 B8 = b1 + m;

        // Clamp y convierte a 5 bits
        s32 R5 = Componente8a5(R8 < 0 ? 0 : (R8 > 255 ? 255 : R8));
        s32 G5 = Componente8a5(G8 < 0 ? 0 : (G8 > 255 ? 255 : G8));
        s32 B5 = Componente8a5(B8 < 0 ? 0 : (B8 > 255 ? 255 : B8));

        dst[i] = RGB(R5, G5, B5) | marcador;
    }
}

void DesplazaTonoPaleta(u32 offsetPaleta, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoPaletaBase(&gPlttBufferUnfaded[offsetPaleta], &gPlttBufferFaded[offsetPaleta], desplazamiento);
    CopiaCpu32(&gPlttBufferFaded[offsetPaleta], &gPlttBufferUnfaded[offsetPaleta], PLTT_SIZE_4BPP);
}

void DesplazaTonoPaletaBuffer(u16 *buffer, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoPaletaBase(buffer, buffer, desplazamiento);
}

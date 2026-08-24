#include "global.h"
#include "util.h"
#include "sprite.h"
#include "palette.h"
#include "pokemon.h"
#include "constants/rgb.h"
#include "fpmath.h"

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
    u32 sprite = CreateSprite(&sInvisibleSpriteTemplate, ANCHO_PANTALLA + 8, ALTURA_PANTALLA + 8, 14);
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

// 1/43 en formato UQ4.12 => (1.0 / 43.0) * 4096 = 95.25... => 95
#define UQ_INV_43 95 

// Tabla de recíprocos: UQ4.12 (4096 / delta)
static const uq4_12_t sReciprocosDelta_Q12[] = {
    0, 4096, 2048, 1365, 1024, 819, 683, 585, 512, 455, 410, 372, 341, 315, 293, 273,
    256, 241, 228, 216, 205, 195, 186, 178, 171, 164, 158, 152, 146, 141, 137, 132
};

static void IWRAM_INIT DesplazaTonoOptimizado(const u16 *src, u16 *dst, s32 desplazamiento)
{
    for (u32 i = 1; i < 16; i++)
    {
        u32 color = src[i];
        if (color == 0x0000 || (color & 0x7FFF) == 0x7FFF) { 
            dst[i] = color; 
            continue; 
        }

        u32 r = GET_R(color);
        u32 g = GET_G(color);
        u32 b = GET_B(color);

        u32 max = r, min = r;
        if (g > max) max = g; else if (g < min) min = g;
        if (b > max) max = b; else if (b < min) min = b;

        u32 delta = max - min;
        if (delta == 0) { dst[i] = color; continue; }

        // --- CÁLCULO DE TONO ---
        s32 h;
        uq4_12_t res = sReciprocosDelta_Q12[delta];
        
        // Usamos 43 como multiplicador para que el rango sea ~256 (43 * 6 = 258)
        if (max == r)      h = (43 * res * (s32)(g - b)) >> UQ_4_12_SHIFT;
        else if (max == g) h = ((43 * res * (s32)(b - r)) >> UQ_4_12_SHIFT) + 85;
        else               h = ((43 * res * (s32)(r - g)) >> UQ_4_12_SHIFT) + 171;

        // CRÍTICO: El cast a (u8) obliga a que el valor de h + desplazamiento 
        // dé la vuelta correctamente (Ej: -1 se convierte en 255)
        u8 nuevoH = (u8)(h + desplazamiento);

        // --- RECONSTRUCCIÓN ---
        // Usamos el multiplicador exacto para que 255 / 43 = 5
        u32 sector = (nuevoH * UQ_INV_43) >> UQ_4_12_SHIFT; 
        u32 f = nuevoH - (sector * 43);
        
        // Limitar f para evitar que x exceda a delta por errores de redondeo
        if (f > 43) f = 43; 

        u32 x = UQ412MultiplicaPorEntero(UQ_INV_43 * f, delta);
        if (x > delta) x = delta; // Guardrail de precisión
        
        u32 invX = delta - x;
        u32 r1, g1, b1;

        switch (sector) {
            case 0:  r1 = delta; g1 = x;     b1 = 0;     break; // Rojo -> Amarillo
            case 1:  r1 = invX;  g1 = delta; b1 = 0;     break; // Amarillo -> Verde
            case 2:  r1 = 0;     g1 = delta; b1 = x;     break; // Verde -> Cian
            case 3:  r1 = 0;     g1 = invX;  b1 = delta; break; // Cian -> Azul
            case 4:  r1 = x;     g1 = 0;     b1 = delta; break; // Azul -> Magenta
            default: r1 = delta; g1 = 0;     b1 = invX;  break; // Magenta -> Rojo
        }

        dst[i] = RGB(r1 + min, g1 + min, b1 + min) | (color & 0x8000);
    }
}

void DesplazaTonoPaleta(u32 offsetPaleta, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoOptimizado(&gPlttBufferUnfaded[offsetPaleta], &gPlttBufferFaded[offsetPaleta], desplazamiento);
    CopiaCpu32(&gPlttBufferFaded[offsetPaleta], &gPlttBufferUnfaded[offsetPaleta], PLTT_SIZE_4BPP);
}

void DesplazaTonoPaletaBuffer(u16 *buffer, u32 personalidad)
{
    s32 desplazamiento = CalcularDesplazamientoDesdePersonalidad(personalidad);
    DesplazaTonoOptimizado(buffer, buffer, desplazamiento);
}

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

// Cuanto puede desviarse el tono de un Pokemon respecto al de su especie. La unidad
// es 1/384 de vuelta (ver mas abajo por que 384). Con 20, el desplazamiento cae en
// [-10, +10], y eso da como maximo 5 puntos de diferencia por canal sobre los 31 que
// tiene el color: comprobado sobre los 32768 colores posibles. Es mucha variedad sin
// que ningun Pokemon deje de parecerse a los de su especie.
#define LIMITADOR_VARIACION_PALETAS 80

static s32 CalcularDesplazamientoDesdePersonalidad(u32 personalidad)
{
    u32 semilla = personalidad & 0xFF; // Solo 8 bits
    return ((semilla * LIMITADOR_VARIACION_PALETAS) / 255) - (LIMITADOR_VARIACION_PALETAS / 2);
}

// La rueda de tonos se divide en 384 pasos: seis sectores de 64.
//
// El numero no es caprichoso. Un tono en HSV son seis tramos (rojo->amarillo->verde->
// cian->azul->magenta), asi que la vuelta tiene que ser divisible entre seis, y 64 por
// tramo hace que repartir el tono en sector y posicion dentro del sector sean un
// desplazamiento y una mascara, sin una sola division. Con 256 pasos -que es lo que
// pedia el cast a u8- no cuadra: seis sectores de 43 suman 258, y ese descuadre de dos
// unidades desalinea el redondeo y tine ligeramente colores que no deberian cambiar.
#define PASOS_RUEDA_TONO   384
#define PASOS_POR_SECTOR    64
#define BITS_SECTOR          6   // 64 = 1 << 6

// Reciprocos 16384/delta en Q14. Sustituyen a la unica division con divisor variable
// que tenia el calculo del tono, que era lo caro de verdad: el ARM7TDMI no divide por
// hardware y cada una son decenas de ciclos. Q14 es el punto justo: el mayor valor
// (16384, para delta 1) todavia cabe en u16, y el error que introduce en el tono se
// queda en 0,06 pasos, invisible tras el redondeo.
static const u16 sReciprocoDelta_Q14[32] =
{
        0, 16384,  8192,  5461,  4096,  3277,  2731,  2341,
     2048,  1820,  1638,  1489,  1365,  1260,  1170,  1092,
     1024,   964,   910,   862,   819,   780,   745,   712,
      683,   655,   630,   607,   585,   565,   546,   529,
};

// Gira el tono de una paleta dejando intactos saturacion y brillo.
//
// Vive en IWRAM (IWRAM_INIT) porque se llama al entrar en combate y por cada Pokemon
// que aparece: alli el bus es de 32 bits y sin esperas, frente a los 16 bits y dos
// esperas de la ROM.
//
// Trabaja directamente en los 5 bits por canal del color de GBA. La version anterior
// expandia a 8 bits, hacia las cuentas y volvia a comprimir, y ese viaje de ida y
// vuelta perdia precision por su cuenta.
static void IWRAM_INIT DesplazaTonoOptimizado(const u16 *src, u16 *dst, s32 desplazamiento)
{
    // Desde el 0, y esto NO es un descuido que optimizar.
    //
    // En las especies con paleta .pla el indice 0 no es un transparente cualquiera:
    // es una copia de uno de los 15 colores de verdad, la que el sistema de brillo
    // mezcla de noche. Si se queda sin girar, el resplandor conserva el tono original
    // mientras el resto del Pokemon cambia. Un Ampharos con la luz amarilla en vez de
    // roja se veria rojo, que es justo lo contrario de lo que se busca.
    for (u32 i = 0; i < COLORES_POR_PALETA; i++)
    {
        u32 color = src[i];
        u32 r = GET_R(color);
        u32 g = GET_G(color);
        u32 b = GET_B(color);
        u32 max = r, min = r;
        u32 delta;
        s32 diferencia, base, tono;
        u32 sector, dentro, medio, resto;
        u32 r1, g1, b1;

        if (g > max) max = g; else if (g < min) min = g;
        if (b > max) max = b; else if (b < min) min = b;

        delta = max - min;

        // Gris, blanco o negro: no tienen tono que girar. Aqui entran tambien el negro
        // puro y el blanco puro, asi que no hacen falta casos aparte para ellos.
        if (delta == 0)
        {
            dst[i] = color;
            continue;
        }

        // Que canal manda decide el tercio de la rueda; la diferencia entre los otros
        // dos, la posicion dentro de el.
        if (max == r)      { diferencia = (s32)g - (s32)b; base = 0;   }
        else if (max == g) { diferencia = (s32)b - (s32)r; base = 128; }
        else               { diferencia = (s32)r - (s32)g; base = 256; }

        // OJO con los tipos: la cuenta tiene que ir con signo de principio a fin.
        // 'diferencia' es negativa la mitad de las veces, y si algun operando fuese sin
        // signo toda la expresion se volveria sin signo, el >> pasaria a ser logico en
        // vez de aritmetico y el resultado saldria mal por 2^18. Por eso los dos
        // valores van forzados a s32 y la tabla se lee como s32.
        tono = base + ((PASOS_POR_SECTOR * diferencia * (s32)sReciprocoDelta_Q14[delta] + 8192) >> 14);

        tono += desplazamiento;
        if (tono < 0)
            tono += PASOS_RUEDA_TONO;
        else if (tono >= PASOS_RUEDA_TONO)
            tono -= PASOS_RUEDA_TONO;

        // Aqui se cobra lo de elegir 384: ni una division, solo un desplazamiento y una
        // mascara. El canal intermedio se reconstruye con redondeo al mas cercano, que
        // es lo que hace que un desplazamiento de 0 devuelva el color exacto.
        sector = (u32)tono >> BITS_SECTOR;
        dentro = (u32)tono & (PASOS_POR_SECTOR - 1);
        medio = (dentro * delta + (PASOS_POR_SECTOR / 2)) >> BITS_SECTOR;
        resto = delta - medio;

        switch (sector)
        {
        case 0:  r1 = delta; g1 = medio; b1 = 0;     break;   // rojo    -> amarillo
        case 1:  r1 = resto; g1 = delta; b1 = 0;     break;   // amarillo-> verde
        case 2:  r1 = 0;     g1 = delta; b1 = medio; break;   // verde   -> cian
        case 3:  r1 = 0;     g1 = resto; b1 = delta; break;   // cian    -> azul
        case 4:  r1 = medio; g1 = 0;     b1 = delta; break;   // azul    -> magenta
        default: r1 = delta; g1 = 0;     b1 = resto; break;   // magenta -> rojo
        }

        // El bit 15 viaja intacto: es el marcador del sistema de brillo, no color.
        dst[i] = RGB(r1 + min, g1 + min, b1 + min) | (color & RGB_ALPHA);
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

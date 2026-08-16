#include "global.h"
#include "sombra_pokemon.h"
#include "decompress.h"
#include "palette.h"
#include "sprite.h"

// La hoja guarda 4 tamanos consecutivos; cada uno ocupa 8 tiles, repartidos en
// 4 para la mitad izquierda y 4 para la derecha.
#define TILES_POR_MITAD  4
#define TILES_POR_TAMANO (TILES_POR_MITAD * 2)

// Separacion de cada mitad respecto al centro del Pokemon, y bajada hasta los pies.
#define SEPARACION_MITAD 16
#define BAJADA_A_LOS_PIES 16

void CargaGraficosSombraPokemon(void)
{
    LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadowsSized);
    // La sombra no tiene paleta propia: reutiliza la del marcador de vida.
    LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
}

void FijaTamanoSombraPokemon(struct Sprite *sombra, u32 tamano)
{
    sombra->oam.tileNum = sombra->sSombraTileBase + (TILES_POR_TAMANO * tamano);
}

// Crea una de las dos mitades. Nace invisible: cada sistema decide cuando y bajo
// que condiciones mostrarla. Devuelve MAX_SPRITES si no hay hueco.
u8 CreaMitadSombraPokemon(s16 x, s16 y, u8 subprioridad, u32 lado, u32 tamano)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_EnemyShadow, x, y, subprioridad);
    struct Sprite *sombra;

    if (spriteId >= MAX_SPRITES)
        return MAX_SPRITES;

    sombra = &gSprites[spriteId];
    sombra->sSombraLado = lado;
    sombra->sSombraTileBase = sombra->oam.tileNum
                            + (lado == SOMBRA_DERECHA ? TILES_POR_MITAD : 0);
    FijaTamanoSombraPokemon(sombra, tamano);
    sombra->invisible = TRUE;

    return spriteId;
}

void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY)
{
    s32 separacion = (sombra->sSombraLado == SOMBRA_IZQUIERDA) ? -SEPARACION_MITAD : SEPARACION_MITAD;

    sombra->x  = dueno->x + desplazamientoX + separacion;
    sombra->x2 = dueno->x2;
    sombra->y  = dueno->y + desplazamientoY + BAJADA_A_LOS_PIES;
}

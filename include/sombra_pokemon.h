#ifndef GUARD_SOMBRA_POKEMON_H
#define GUARD_SOMBRA_POKEMON_H

#include "sprite.h"

// Sombra que se dibuja bajo un Pokemon. Se compone SIEMPRE de dos sprites de
// 32x8, uno por mitad, porque la hoja de graficos guarda cada tamano como 8
// tiles: 4 para la mitad izquierda y 4 para la derecha.
//
// Este modulo reune lo que comparten los dos sistemas que dibujan sombras
// (el combate y el visualizador de sprites): los recursos graficos, la creacion
// de cada mitad, la geometria de colocacion y el calculo de tiles por tamano.
// Cada sistema conserva su propio callback, porque las reglas de visibilidad y
// el origen de los desplazamientos si son distintos.

enum LadoSombra
{
    SOMBRA_IZQUIERDA,
    SOMBRA_DERECHA,
};

// Campos comunes del sprite de sombra. Quien la use puede emplear data[3] en
// adelante para lo suyo.
#define sSombraDueno    data[0] // id del sprite o combatiente al que sigue
#define sSombraLado     data[1] // enum LadoSombra
#define sSombraTileBase data[2] // tile inicial de esta mitad, sin el ajuste de tamano

void CargaGraficosSombraPokemon(void);
u8 CreaMitadSombraPokemon(s16 x, s16 y, u8 subprioridad, u32 lado, u32 tamano);
void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY);
void FijaTamanoSombraPokemon(struct Sprite *sombra, u32 tamano);

extern const struct SpriteTemplate gSpriteTemplate_EnemyShadow;
extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadowsSized;
extern const struct SpritePalette sSpritePalettes_HealthBoxHealthBar[2];

#endif // GUARD_SOMBRA_POKEMON_H

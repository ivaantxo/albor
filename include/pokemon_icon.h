#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

const struct SpriteFrameImage *ObtenGraficosIconoPokemon(u32 especie, u32 personalidad);
void BorraIconoPokemon(struct Sprite *sprite);
u32 CreaIconoPokemon(u32 especie, s32 x, s32 y, u32 subprioridad, u32 personalidad);

#endif // GUARD_POKEMON_ICON_H

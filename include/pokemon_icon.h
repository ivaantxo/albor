#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

const struct SpriteFrameImage *GetMonIconTiles(u16 species, u32 personality);
void FreeAndDestroyMonIconSprite(struct Sprite *sprite);
u8 CreateMonIcon(u16 species, s16 x, s16 y, u8 subpriority, u32 personality);
void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum);

#endif // GUARD_POKEMON_ICON_H

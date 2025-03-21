#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

extern const u8 gMiscBlank_Gfx[];

u8 CreateInvisibleSpriteWithCallback(void (*)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *, u32);
void LoadWordFromTwoHalfwords(u16 *, u32 *);
int CountTrailingZeroBits(u32 value);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor);
void UniquePalette(u16 palOffset, u32 personality);
void UniquePaletteBuffered(u16 * buffer, u32 personality);

#endif // GUARD_UTIL_H

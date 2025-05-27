#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

extern const u8 gMiscBlank_Gfx[];

u8 CreateInvisibleSpriteWithCallback(void (*)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *, u32);
void LoadWordFromTwoHalfwords(u16 *, u32 *);
int CountTrailingZeroBits(u32 value);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor);
void DesplazaTonoPaleta(u32 offsetPaleta, u32 personalidad);
void DesplazaTonoPaletaBuffer(u16 *buffer, u32 personalidad);

#endif // GUARD_UTIL_H

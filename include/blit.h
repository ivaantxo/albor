#ifndef GUARD_BLIT_H
#define GUARD_BLIT_H

struct Bitmap
{
    u8 *pixels;
    u32 width:16;
    u32 height:16;
};

void BlitBitmapRect4Bit(const struct Bitmap *src, struct Bitmap *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height, u32 colorKey);
void FillBitmapRect4Bit(struct Bitmap *surface, u32 x, u32 y, u32 width, u32 height, u32 fillValue);

#endif // GUARD_BLIT_H

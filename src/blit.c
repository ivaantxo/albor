#include "global.h"
#include "blit.h"

void BlitBitmapRect4Bit(const struct Bitmap *src, struct Bitmap *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height, u32 colorKey)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierSrcY;
    s32 multiplierDstY;
    s32 loopSrcY, loopDstY;
    s32 loopSrcX, loopDstX;
    const u8 *pixelsSrc;
    u8 *pixelsDst;
    s32 toOrr;
    s32 toAnd;
    s32 toShift;

    if (dst->width - dstX < width)
        xEnd = (dst->width - dstX) + srcX;
    else
        xEnd = srcX + width;

    if (dst->height - dstY < height)
        yEnd = (dst->height - dstY) + srcY;
    else
        yEnd = height + srcY;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    if (colorKey == 0xFF)
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B);
                pixelsDst = dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + (((loopDstY >> 3) * multiplierDstY) << 5) + ((u32)(loopDstY << 0x1d) >> 0x1B);
                toOrr = ((*pixelsSrc >> ((loopSrcX & 1) << 2)) & 0xF);
                toShift = ((loopDstX & 1) << 2);
                toOrr <<= toShift;
                toAnd = 0xF0 >> (toShift);
                *pixelsDst = toOrr | (*pixelsDst & toAnd);
            }
        }
    }
    else
    {
        for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
        {
            for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
            {
                pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B);
                pixelsDst = dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + (((loopDstY >> 3) * multiplierDstY) << 5) + ((u32)(loopDstY << 0x1d) >> 0x1B);
                toOrr = ((*pixelsSrc >> ((loopSrcX & 1) << 2)) & 0xF);
                if (toOrr != colorKey)
                {
                    toShift = ((loopDstX & 1) << 2);
                    toOrr <<= toShift;
                    toAnd = 0xF0 >> (toShift);
                    *pixelsDst = toOrr | (*pixelsDst & toAnd);
                }
            }
        }
    }
}

void FillBitmapRect4Bit(struct Bitmap *surface, u32 x, u32 y, u32 width, u32 height, u32 fillValue)
{
    s32 xEnd;
    s32 yEnd;
    s32 multiplierY;
    s32 loopX, loopY;
    u32 toOrr1, toOrr2;

    xEnd = x + width;
    if (xEnd > surface->width)
        xEnd = surface->width;

    yEnd = y + height;
    if (yEnd > surface->height)
        yEnd = surface->height;

    multiplierY = (surface->width + (surface->width & 7)) >> 3;
    toOrr1 = fillValue << 4;
    toOrr2 = fillValue & 0xF;

    for (loopY = y; loopY < yEnd; loopY++)
    {
        for (loopX = x; loopX < xEnd; loopX++)
        {
            u8 *pixels = surface->pixels + ((loopX >> 1) & 3) + ((loopX >> 3) << 5) + (((loopY >> 3) * multiplierY) << 5) + ((u32)(loopY << 0x1d) >> 0x1B);
            if ((loopX << 0x1F) != 0)
                *pixels = toOrr1 | (*pixels & 0xF);
            else
                *pixels = toOrr2 | (*pixels & 0xF0);
        }
    }
}

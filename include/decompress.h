#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "sprite.h"

// Ya no hay buffer compartido: cada quien reserva del monton lo que necesita y lo
// suelta. Esto se queda solo como tope para validar cabeceras LZ77, no como tamano
// de nada reservado.
#define MAX_TAMANO_DESCOMPRESION 12288

void LZDecompressWram(const u32 *src, void *dest);
void LZDecompressVram(const u32 *src, void *dest);

u32 IsLZ77Data(const void *ptr, u32 minSize, u32 maxSize);

u16 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src);
u16 LoadCompressedSpriteSheetByTemplate(const struct SpriteTemplate *template, s32 offset);
void LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer);
void LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet *src);

void LoadSpritePaletteWithTag(const u16 *pal, u16 tag);
u32 LoadSpritePaletteWithTagHueShifted(const u16 *pal, u16 tag, u32 personality);
void LoadCompressedEggSpritePalette(const struct SpritePalette *src1, const struct SpritePalette *src2);
void LoadCompressedEggHatchSpritePalette(const struct SpritePalette *src1, const struct SpritePalette *src2);

void LoadCompressedSpriteSheetAndPaletteUsingHeap(const struct CompressedSpriteSheetAndPalette *src);

void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void *buffer);

void HandleLoadSpecialPokePic(bool32 isFrontPic, void *dest, s32 species, u32 personality);

void LoadSpecialPokePic(void *dest, s32 species, u32 personality, bool8 isFrontPic);

u32 GetDecompressedDataSize(const u32 *ptr);

#endif // GUARD_DECOMPRESS_H

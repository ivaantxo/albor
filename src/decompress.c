#include "global.h"
#include "malloc.h"
#include "data.h"
#include "decompress.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_sprite_visualizer.h"
#include "text.h"



void LZDecompressWram(const u32 *src, void *dest)
{
    LZ77UnCompWram(src, dest);
}

void LZDecompressVram(const u32 *src, void *dest)
{
    LZ77UnCompVram(src, dest);
}

// Checks if `ptr` is likely LZ77 data
// Checks word-alignment, min/max size, and header byte
// Returns uncompressed size if true, 0 otherwise
u32 IsLZ77Data(const void *ptr, u32 minSize, u32 maxSize)
{
    const u8 *data = ptr;
    u32 size;
    // Compressed data must be word aligned
    if (((u32)ptr) & 3)
        return 0;
    // Check LZ77 header byte
    // See https://problemkaputt.de/gbatek.htm#biosdecompressionfunctions
    if (data[0] != 0x10)
        return 0;

    // Read 24-bit uncompressed size
    size = data[1] | (data[2] << 8) | (data[3] << 16);
    if (size >= minSize && size <= maxSize)
        return size;
    return 0;
}

u16 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src)
{
    struct SpriteSheet dest;
    void *buffer;
    u16 resultado;
    // Hay que reservar lo que dice la cabecera LZ77, no lo que declara la ficha: las
    // dos cosas no son lo mismo. El .size es cuanto se copia a VRAM, y hay fichas
    // donde se queda corto respecto al grafico real (press_start declara 0x520 y
    // ocupa 0x600). Mientras todo se descomprimia sobre el buffer compartido de
    // 16 KB el exceso caia en su hueco y no molestaba; reservando justo, quedarse
    // corto machaca el bloque siguiente del monton.
    u32 tamano = IsLZ77Data(src->data, TILE_4BPP, MAX_TAMANO_DESCOMPRESION);

    if (tamano < src->size)
        tamano = src->size;

    buffer = AllocZeroed(tamano);
    if (buffer == NULL)
        return 0xFFFF;

    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;
    resultado = LoadSpriteSheet(&dest);
    Free(buffer);
    return resultado;
}

// This can be used for either compressed or uncompressed sprite sheets
u16 LoadCompressedSpriteSheetByTemplate(const struct SpriteTemplate *template, s32 offset)
{
    struct SpriteTemplate myTemplate;
    struct SpriteFrameImage myImage;
    u32 size;
    void *buffer;
    u16 resultado;

    // Check for LZ77 header and read uncompressed size, or fallback if not compressed (zero size)
    if ((size = IsLZ77Data(template->images->data, TILE_4BPP, MAX_TAMANO_DESCOMPRESION)) == 0)
        return LoadSpriteSheetByTemplate(template, 0, offset);

    buffer = AllocZeroed(size + offset);
    if (buffer == NULL)
        return 0xFFFF;

    LZ77UnCompWram(template->images->data, buffer);
    myImage.data = buffer;
    myImage.size = size + offset;
    myTemplate.images = &myImage;
    myTemplate.tileTag = template->tileTag;

    resultado = LoadSpriteSheetByTemplate(&myTemplate, 0, offset);
    Free(buffer);
    return resultado;
}

void LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer)
{
    struct SpriteSheet dest;

    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;
    LoadSpriteSheet(&dest);
}


void LoadSpritePaletteWithTag(const u16 *pal, u16 tag)
{
    struct SpritePalette dest;

    dest.data = pal;
    dest.tag = tag;
    LoadSpritePalette(&dest);
}

// Devuelve el slot concreto que se ha usado. Es importante no volver a buscarlo
// por etiqueta: LoadUniqueSpritePalette siempre ocupa un slot libre nuevo, asi que
// puede haber varios slots con la misma etiqueta (dos Pokemon de la misma especie
// con personalidades distintas) e IndexOfSpritePaletteTag devolveria el primero.
u32 LoadSpritePaletteWithTagHueShifted(const u16 *pal, u16 tag, u32 personality)
{
    struct SpritePalette dest;

    dest.data = pal;
    dest.tag = tag;
    return LoadUniqueSpritePalette(&dest, personality);
}


void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void *buffer)
{
    LZ77UnCompWram(src->data, buffer);
}

void HandleLoadSpecialPokePic(bool32 isFrontPic, void *dest, s32 species, u32 personality)
{
    LoadSpecialPokePic(dest, species, personality, isFrontPic);
}

void LoadSpecialPokePic(void *dest, s32 species, u32 personality, bool8 isFrontPic)
{
    species = SanitizeSpeciesId(species);
    if (isFrontPic)
    {
        if (gSpeciesInfo[species].frontPicFemale != NULL && IsPersonalityFemale(species, personality))
            LZ77UnCompWram(gSpeciesInfo[species].frontPicFemale, dest);
        else if (gSpeciesInfo[species].frontPic != NULL)
            LZ77UnCompWram(gSpeciesInfo[species].frontPic, dest);
        else
            LZ77UnCompWram(gSpeciesInfo[SPECIES_NONE].frontPic, dest);
    }
    else
    {
        if (gSpeciesInfo[species].backPicFemale != NULL && IsPersonalityFemale(species, personality))
            LZ77UnCompWram(gSpeciesInfo[species].backPicFemale, dest);
        else if (gSpeciesInfo[species].backPic != NULL)
            LZ77UnCompWram(gSpeciesInfo[species].backPic, dest);
        else
            LZ77UnCompWram(gSpeciesInfo[SPECIES_NONE].backPic, dest);
    }
}

u32 GetDecompressedDataSize(const u32 *ptr)
{
    const u8 *ptr8 = (const u8 *)ptr;
    return (ptr8[3] << 16) | (ptr8[2] << 8) | (ptr8[1]);
}

void LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet *src)
{
    struct SpriteSheet dest;
    void *buffer;

    buffer = AllocZeroed(src->data[0] >> 8);
    if (buffer == NULL)
        return;

    LZ77UnCompWram(src->data, buffer);

    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;

    LoadSpriteSheet(&dest);
    Free(buffer);
}


void LoadCompressedEggSpritePalette(const struct SpritePalette *src1, const struct SpritePalette *src2)
{
    struct SpritePalette dest1, dest2;
    dest1.data = src1->data;
    dest1.tag = src1->tag;

    dest2.data = src2->data;
    dest2.tag = src2->tag;

    LoadEggSpritePalette(&dest1, &dest2);
}

void LoadCompressedEggHatchSpritePalette(const struct SpritePalette *src1, const struct SpritePalette *src2)
{
    struct SpritePalette dest1, dest2;

    dest1.data = src1->data;
    dest1.tag = 54321;

    dest2.data = src2->data;
    dest2.tag = src2->tag;

    LoadEggSpritePalette(&dest1, &dest2);
}

void LoadCompressedSpriteSheetAndPaletteUsingHeap(const struct CompressedSpriteSheetAndPalette *src)
{
    struct SpriteSheet sheetDest;
    void *sheetBuffer;
    // Mismo cuidado que en LoadCompressedSpriteSheet: manda la cabecera, no sheetSize.
    u32 tamano = IsLZ77Data(src->sheet, TILE_4BPP, MAX_TAMANO_DESCOMPRESION);

    if (tamano < src->sheetSize)
        tamano = src->sheetSize;

    sheetBuffer = AllocZeroed(tamano);
    if (sheetBuffer == NULL)
        return;

    LZ77UnCompWram(src->sheet, sheetBuffer);

    sheetDest.data = sheetBuffer;
    sheetDest.size = src->sheetSize;
    sheetDest.tag  = src->tag;

    LoadSpriteSheet(&sheetDest);
    Free(sheetBuffer);

    // La paleta ya no se descomprime: va cruda en la ROM. Se acabaron la reserva de
    // heap, la descompresion LZ y la copia intermedia; se carga tal cual.
    struct SpritePalette palDest = { src->palette, src->tag };

    LoadSpritePalette(&palDest);
}

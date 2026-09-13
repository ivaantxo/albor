#include "global.h"
#include "sprite.h"
#include "window.h"
#include "malloc.h"
#include "palette.h"
#include "decompress.h"
#include "trainer_pokemon_sprites.h"
#include "data.h"
#include "pokemon.h"
#include "pic_combate.h"
#include "util.h"
#include "constants/trainers.h"

#define PICS_COUNT 8

// Needs to be large enough to store either a decompressed Pokémon pic or trainer pic
#define PIC_SPRITE_SIZE max(MON_PIC_SIZE, TRAINER_PIC_SIZE)
#define MAX_PIC_FRAMES  max(NUMERO_FRAMES_POKEMON, MAX_TRAINER_PIC_FRAMES)

struct PicData
{
    u8 *frames;
    struct SpriteFrameImage *images;
    u16 paletteTag;
    u32 spriteId;
    u8 active;
};

static EWRAM_DATA struct SpriteTemplate sCreatingSpriteTemplate = {};
static EWRAM_DATA struct PicData sSpritePics[PICS_COUNT] = {};

static const struct PicData sDummyPicData = {};

static const struct OamData sOamData_Normal =
{
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64)
};

static const struct OamData sOamData_Affine =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64)
};

static void DummyPicSpriteCallback(struct Sprite *sprite)
{

}

bool16 ResetAllPicSprites(void)
{
    u32 i;

    for (i = 0; i < PICS_COUNT; i ++)
        sSpritePics[i] = sDummyPicData;

    return FALSE;
}

static bool16 DecompressPic(u16 species, u32 personality, bool8 isFrontPic, u8 *dest, bool8 isTrainer)
{
    if (!isTrainer)
    {
        LoadSpecialPokePic(dest, species, personality, isFrontPic);
    }
    else
    {
        if (isFrontPic)
            DecompressPicFromTable(&gTrainerSprites[species].frontPic, dest);
        else
        {
            const struct TrainerBacksprite *back = &gTrainerBacksprites[species];

            if (IsLZ77Data(back->backPic.data, back->bytesPorFotograma, back->backPic.size))
                DecompressPicFromTable(&back->backPic, dest);
            else
                CopiaCpu32(back->backPic.data, dest, back->backPic.size);
        }
    }
    return FALSE;
}

static void LoadPicPaletteByTagOrSlot(u16 species, bool8 isShiny, u32 personality, u8 paletteSlot, u16 paletteTag, bool8 isTrainer, bool8 isFrontPic)
{
    if (!isTrainer)
    {
        if (paletteTag == TAG_NONE)
        {
            sCreatingSpriteTemplate.paletteTag = TAG_NONE;
            LoadPalette(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
            DesplazaTonoPaleta(OBJ_PLTT_ID(paletteSlot), personality);
        }
        else
        {
            sCreatingSpriteTemplate.paletteTag = paletteTag;
            LoadSpritePaletteWithTagHueShifted(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), species, personality);
        }
    }
    else
    {
        const struct SpritePalette *palette = isFrontPic ? &gTrainerSprites[species].palette
                                                        : &gTrainerBacksprites[species].palette;

        if (paletteTag == TAG_NONE)
        {
            sCreatingSpriteTemplate.paletteTag = TAG_NONE;
            LoadPalette(palette->data, OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
        }
        else
        {
            sCreatingSpriteTemplate.paletteTag = palette->tag;
            LoadSpritePalette(palette);
        }
    }
}

static void LoadPicPaletteBySlot(u16 species, bool8 isShiny, u32 personality, u8 paletteSlot, bool8 isTrainer, bool8 isFrontPic)
{
    if (!isTrainer)
    {
        LoadPalette(GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality), PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
        DesplazaTonoPaleta(PLTT_ID(paletteSlot), personality);
    }
    else
    {
        const struct SpritePalette *palette = isFrontPic ? &gTrainerSprites[species].palette
                                                        : &gTrainerBacksprites[species].palette;

        LoadPalette(palette->data, PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    }
}

static void AssignSpriteAnimsTable(u16 species, bool8 isTrainer, bool8 isFrontPic)
{
    if (!isTrainer)
        sCreatingSpriteTemplate.anims = gAnims_MonPic;
    else
    {
        sCreatingSpriteTemplate.anims = isFrontPic ? gTrainerSprites[species].animation
                                                   : gTrainerBacksprites[species].animation;
        if (sCreatingSpriteTemplate.anims == NULL)
            sCreatingSpriteTemplate.anims = gAnims_Trainer;
    }
}

static u16 CreatePicSprite(u16 species, bool8 isShiny, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag, bool8 isTrainer)
{
    u32 i;
    u8 *framePics;
    struct SpriteFrameImage *images;
    u32 j;
    u32 spriteId;
    u32 frameSize = PIC_SPRITE_SIZE;
    u32 totalSize = PIC_SPRITE_SIZE * MAX_PIC_FRAMES;
    u32 frameCount = MAX_PIC_FRAMES;
    u32 imageCount = MAX_PIC_FRAMES;
    u16 newTrainerPaletteTag = TAG_NONE;

    if (isTrainer)
    {
        frameSize = isFrontPic ? GetTrainerFrontPicFrameSize(species)
                               : gTrainerBacksprites[species].bytesPorFotograma;
        totalSize = isFrontPic ? GetTrainerFrontPicTotalSize(species)
                               : gTrainerBacksprites[species].backPic.size;
        frameCount = totalSize / frameSize;
        imageCount = max(imageCount, frameCount);
    }

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(totalSize);
    if (!framePics)
        return 0xFFFF;

    images = Alloc(sizeof(struct SpriteFrameImage) * imageCount);
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }
    if (DecompressPic(species, personality, isFrontPic, framePics, isTrainer))
    {
        Free(images);
        Free(framePics);
        return 0xFFFF;
    }
    if (isTrainer)
        ReordenaPicTroceado(framePics, frameCount, frameSize);
    for (j = 0; j < imageCount; j ++)
    {
        images[j].data = framePics + frameSize * (j < frameCount ? j : 0);
        images[j].size = frameSize;
    }
    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.oam = &sOamData_Normal;
    AssignSpriteAnimsTable(species, isTrainer, isFrontPic);
    sCreatingSpriteTemplate.images = images;
    sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;
    if (isTrainer && paletteTag != TAG_NONE)
    {
        u16 tag = isFrontPic ? gTrainerSprites[species].palette.tag : gTrainerBacksprites[species].palette.tag;

        if (IndexOfSpritePaletteTag(tag) == 0xFF)
            newTrainerPaletteTag = tag;
    }
    LoadPicPaletteByTagOrSlot(species, isShiny, personality, paletteSlot, paletteTag, isTrainer, isFrontPic);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    if (spriteId == MAX_SPRITES)
    {
        if (newTrainerPaletteTag != TAG_NONE)
            FreeSpritePaletteByTag(newTrainerPaletteTag);
        Free(images);
        Free(framePics);
        return 0xFFFF;
    }
    if (isTrainer)
        AplicaSubspritesSinMover(spriteId);
    if (paletteTag == TAG_NONE)
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = paletteTag;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;
    return spriteId;
}

u16 CreateMonPicSprite_Affine(u16 species, bool8 isShiny, u32 personality, u8 flags, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u8 *framePics;
    struct SpriteFrameImage *images;
    u32 j;
    u32 i;
    u32 spriteId;
    u8 type;
    species = SanitizeSpeciesId(species);

    for (i = 0; i < PICS_COUNT; i++)
    {
        if (!sSpritePics[i].active)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = Alloc(MON_PIC_SIZE * NUMERO_FRAMES_POKEMON);
    if (!framePics)
        return 0xFFFF;

    if (flags & F_MON_PIC_NO_AFFINE)
    {
        flags &= ~F_MON_PIC_NO_AFFINE;
        type = MON_PIC_AFFINE_NONE;
    }
    else
    {
        type = flags;
    }
    images = Alloc(sizeof(struct SpriteFrameImage) * NUMERO_FRAMES_POKEMON);
    if (!images)
    {
        Free(framePics);
        return 0xFFFF;
    }
    if (DecompressPic(species, personality, flags, framePics, FALSE))
    {
        // debug trap?
        return 0xFFFF;
    }
    for (j = 0; j < NUMERO_FRAMES_POKEMON; j ++)
    {
        images[j].data = framePics + MON_PIC_SIZE * j;
        images[j].size = MON_PIC_SIZE;
    }
    sCreatingSpriteTemplate.tileTag = TAG_NONE;
    sCreatingSpriteTemplate.anims = gSpeciesInfo[species].frontAnimFrames;
    sCreatingSpriteTemplate.images = images;
    if (type == MON_PIC_AFFINE_FRONT)
    {
        sCreatingSpriteTemplate.affineAnims = gAffineAnims_BattleSpriteOpponentSide;
        sCreatingSpriteTemplate.oam = &sOamData_Affine;
    }
    else if (type == MON_PIC_AFFINE_BACK)
    {
        sCreatingSpriteTemplate.affineAnims = gAffineAnims_BattleSpritePlayerSide;
        sCreatingSpriteTemplate.oam = &sOamData_Affine;
    }
    else // MON_PIC_AFFINE_NONE
    {
        sCreatingSpriteTemplate.oam = &sOamData_Normal;
        sCreatingSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    }
    sCreatingSpriteTemplate.callback = DummyPicSpriteCallback;
    LoadPicPaletteByTagOrSlot(species, isShiny, personality, paletteSlot, paletteTag, FALSE, flags);
    spriteId = CreateSprite(&sCreatingSpriteTemplate, x, y, 0);
    if (paletteTag == TAG_NONE)
        gSprites[spriteId].oam.paletteNum = paletteSlot;
    sSpritePics[i].frames = framePics;
    sSpritePics[i].images = images;
    sSpritePics[i].paletteTag = paletteTag;
    sSpritePics[i].spriteId = spriteId;
    sSpritePics[i].active = TRUE;
    return spriteId;
}

static u16 FreeAndDestroyPicSpriteInternal(u16 spriteId, bool8 clearPalette)
{
    u32 i;
    u8 *framePics;
    struct SpriteFrameImage *images;

    for (i = 0; i < PICS_COUNT; i ++)
    {
        if (sSpritePics[i].spriteId == spriteId)
            break;
    }
    if (i == PICS_COUNT)
        return 0xFFFF;

    framePics = sSpritePics[i].frames;
    images = sSpritePics[i].images;
    if (clearPalette && sSpritePics[i].paletteTag != TAG_NONE)
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[spriteId].oam.paletteNum));
    DestroySprite(&gSprites[spriteId]);
    Free(framePics);
    Free(images);
    sSpritePics[i] = sDummyPicData;
    return 0;
}

static u16 CreateTrainerCardSprite(u16 species, bool8 isShiny, u32 personality, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId, bool8 isTrainer)
{
    u8 *framePics;
    u32 totalSize = TRAINER_PIC_SIZE * MAX_TRAINER_PIC_FRAMES;
    u32 side = TRAINER_PIC_WIDTH;

    if (isTrainer)
    {
        u32 frameSize = isFrontPic ? GetTrainerFrontPicFrameSize(species)
                                   : gTrainerBacksprites[species].bytesPorFotograma;

        totalSize = isFrontPic ? GetTrainerFrontPicTotalSize(species)
                               : gTrainerBacksprites[species].backPic.size;
        if (frameSize == PIC_80_BYTES)
            side = PIC_80_LADO;
    }

    framePics = Alloc(totalSize);
    if (framePics && !DecompressPic(species, personality, isFrontPic, framePics, isTrainer))
    {
        BlitBitmapRectToWindow(windowId, framePics, 0, 0, side, side, destX, destY, side, side);
        LoadPicPaletteBySlot(species, isShiny, personality, paletteSlot, isTrainer, isFrontPic);
        Free(framePics);
        return 0;
    }
    return 0xFFFF;
}

u16 CreateMonPicSprite(u16 species, bool8 isShiny, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    return CreatePicSprite(species, isShiny, personality, isFrontPic, x, y, paletteSlot, paletteTag, FALSE);
}

u16 FreeAndDestroyMonPicSprite(u16 spriteId)
{
    return FreeAndDestroyPicSpriteInternal(spriteId, TRUE);
}

u16 FreeAndDestroyMonPicSpriteNoPalette(u16 spriteId)
{
    return FreeAndDestroyPicSpriteInternal(spriteId, FALSE);
}

u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    return CreatePicSprite(species, FALSE, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
}

u16 FreeAndDestroyTrainerPicSprite(u16 spriteId)
{
    return FreeAndDestroyPicSpriteInternal(spriteId, TRUE);
}

u16 CreateTrainerCardTrainerPicSprite(u16 species, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId)
{
    return CreateTrainerCardSprite(species, FALSE, 0, isFrontPic, destX, destY, paletteSlot, windowId, TRUE);
}

u16 PlayerGenderToFrontTrainerPicId_Debug(u8 gender, bool8 getClass)
{
    if (getClass == TRUE)
    {
        if (gender != MALE)
            return TRAINER_PIC_MAY;
        else
            return TRAINER_PIC_BRENDAN;
    }
    return gender;
}

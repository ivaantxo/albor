#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "util.h"
#include "data.h"
#include "decompress.h"
#include "constants/etiquetas.h"

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const struct SpriteFrameImage *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(2, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(2, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

u8 CreateMonIcon(u16 species, s16 x, s16 y, u8 subpriority, u32 personality)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = SpriteCallbackDummy,
        .paletteTag = ETIQUETA_ICONO_POKEMON,
    };

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    CopiaCpu32(GetMonIconTiles(species, personality),(void *)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP),512
    );

    return spriteId;
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

const struct SpriteFrameImage *GetMonIconTiles(u16 species, u32 personality)
{
    const struct SpriteFrameImage *iconSprite;

    if (species >= NUM_SPECIES)
        species = SPECIES_NONE;

    if (IsPersonalityFemale(species, personality) && gSpeciesInfo[species].followerDataFemale.images != NULL)
        iconSprite = gSpeciesInfo[species].followerDataFemale.images->data;
    else if (gSpeciesInfo[species].followerData.images != NULL)
        iconSprite = gSpeciesInfo[species].followerData.images->data;
    else
        iconSprite = gSpeciesInfo[SPECIES_NONE].followerData.images->data;

    return iconSprite;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}

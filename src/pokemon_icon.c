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

u8 CreateMonIcon(u16 species, s16 x, s16 y, u8 subpriority, u32 personality)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = gDummySpriteAnimTable,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
        .paletteTag = ETIQUETA_ICONO_POKEMON,
    };

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    CopiaCpu32(GetMonIconTiles(species, personality),(void *)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP), 512);

    return spriteId;
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, 32 * 32 / 2 };
    sprite->images = &image;
    DestroySprite(sprite);
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

    struct SpriteFrameImage image = { NULL, 32 * 32 / 2  };

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
    return spriteId;
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}

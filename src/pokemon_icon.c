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

static const struct OamData sOamIconoPokemon =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct SpriteFrameImage sPrimerFrameIconoPokemon =
{
    .data = NULL,
    .size = 32 * 32 / 2,
    .relativeFrames = FALSE,
};

static const struct SpriteTemplate gPlantillaIconoPokemon =
{
    .tileTag = TAG_NONE,
    .paletteTag = ETIQUETA_ICONO_POKEMON,
    .oam = &sOamIconoPokemon,
    .anims = gDummySpriteAnimTable,
    .images = &sPrimerFrameIconoPokemon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

u32 CreaIconoPokemon(u32 especie, s32 x, s32 y, u32 subprioridad, u32 personalidad)
{
    u32 spriteId;

    spriteId = CreateSprite(&gPlantillaIconoPokemon, x, y, subprioridad);
    CopiaCpu32(GraficosIconoPokemon(especie, personalidad),(void *)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_4BPP), sPrimerFrameIconoPokemon.size);

    return spriteId;
}

void BorraIconoPokemon(struct Sprite *sprite)
{
    sprite->images = &sPrimerFrameIconoPokemon;
    DestroySprite(sprite);
}

const struct SpriteFrameImage *GraficosIconoPokemon(u32 especie, u32 personalidad)
{
    const struct SpriteFrameImage *frameIconoPokemon;

    if (especie >= NUM_SPECIES)
        especie = SPECIES_NONE;

    if (IsPersonalityFemale(especie, personalidad) && gSpeciesInfo[especie].followerDataFemale.images != NULL)
        frameIconoPokemon = gSpeciesInfo[especie].followerDataFemale.images->data;
    else if (gSpeciesInfo[especie].followerData.images != NULL)
        frameIconoPokemon = gSpeciesInfo[especie].followerData.images->data;
    else
        frameIconoPokemon = gSpeciesInfo[SPECIES_NONE].followerData.images->data;

    return frameIconoPokemon;
}

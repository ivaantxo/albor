#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) (1 << (x))

// Look at the .pla files to mark colors as lights.

const struct Tileset gTileset_Principal =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Principal,
    .palettes = gTilesetPalettes_Principal,
    .metatiles = gMetatiles_Principal,
    .metatilePalettes = gMetatilePalettes_Principal,
    .metatileAttributes = gMetatileAttributes_Principal,
    .callback = NULL,
    .animations = gTilesetAnimations_Principal,
};

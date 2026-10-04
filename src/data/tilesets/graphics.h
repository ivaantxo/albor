// Todas las paletas del tileset, palettes/00.pal, 01.pal..., juntas (graphics_file_rules.mk).
// Van seguidas, sin las llaves de cada paleta.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
const u16 ALIGNED(4) gTilesetPalettes_Principal[][16] = INCBIN_U16("data/tilesets/primary/principal/palettes.gbapal");
#pragma GCC diagnostic pop

const u32 gTilesetTiles_Principal[] = INCBIN_U32("data/tilesets/primary/principal/tiles.4bpp.lz");

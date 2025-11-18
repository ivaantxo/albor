#include "global.h"
#include "data.h"
#include "pokemon_icon.h"
#include "decoration.h"
#include "battle_main.h"
#include "item.h"
#include "pokeball.h"

// The purpose of this struct is for outside applications to be
// able to access parts of the ROM or its save file, like a public API.
// In vanilla, it was used by Colosseum and XD to access Pokémon graphics.
//
// If this struct is rearranged in any way, it defeats the purpose of
// having it at all. Applications like PKHex or streaming HUDs may find
// these values useful, so there's some potential benefit to keeping it.
// If there's a compilation problem below, just comment out the assignment
// instead of changing this struct.
struct GFRomHeader
{
    u32 version;
    u8 gameName[32];
    const struct CompressedSpriteSheet * monFrontPics;
    const struct CompressedSpriteSheet * monBackPics;
    const struct CompressedSpritePalette * monNormalPalettes;
    const struct CompressedSpritePalette * monShinyPalettes;
    const u8 (* monSpeciesNames)[];
    const u8 (* moveNames)[];
    const struct Decoration * decorations;
    u32 flagsOffset;
    u32 varsOffset;
    u32 pokedexOffset;
    u32 seenOffset;
    u32 pokedexFlag;
    u32 pokedexCount;
    u8 playerNameLength;
    u8 trainerNameLength;
    u8 pokemonNameLength1;
    u8 pokemonNameLength2;
    u32 saveBlockSize;
    u32 partyCountOffset;
    u32 partyOffset;
    u32 warpFlagsOffset;
    u32 trainerIdOffset;
    u32 playerNameOffset;
    u32 playerGenderOffset;
    const struct SpeciesInfo * speciesInfo;
    const u8 (* abilityNames)[];
    const u8 *const * abilityDescriptions;
    const struct Item * items;
    const struct MoveInfo * moves;
    const struct CompressedSpriteSheet * ballGfx;
    const struct CompressedSpritePalette * ballPalettes;
    u32 gameClearFlag;
    u32 ribbonFlag;
    u8 bagCountItems;
    u8 bagCountKeyItems;
    u8 bagCountPokeballs;
    u8 bagCountTMHMs;
    u8 bagCountBerries;
    u32 giftRibbonsOffset;
    const u8 *moveDescriptions;
};

// This seems to need to be in the text section for some reason.
// To avoid a changed section attributes warning it's put in a special .text.consts section.
__attribute__((section(".text.consts")))
static const struct GFRomHeader sGFRomHeader = {
    .version = GAME_VERSION,
    .gameName = "pokemon emerald version",
    .decorations = gDecorations,
    .flagsOffset = offsetof(struct SaveBlock, flags),
    .varsOffset = offsetof(struct SaveBlock, vars),
    .pokedexOffset = offsetof(struct SaveBlock, pokedexOrder),
    .seenOffset = offsetof(struct SaveBlock, dexSeen),
    .pokedexFlag = FLAG_RECEIVED_POKEDEX_FROM_BIRCH,
    .pokedexCount = DEX_COUNT,
    .playerNameLength = PLAYER_NAME_LENGTH,
    .trainerNameLength = TRAINER_NAME_LENGTH,
    .pokemonNameLength1 = POKEMON_NAME_LENGTH,
    .pokemonNameLength2 = POKEMON_NAME_LENGTH,
    .saveBlockSize = sizeof(struct SaveBlock),
    .partyCountOffset = offsetof(struct SaveBlock, playerPartyCount),
    .partyOffset = offsetof(struct SaveBlock, playerParty),
    .warpFlagsOffset = offsetof(struct SaveBlock, specialSaveWarpFlags),
    .trainerIdOffset = offsetof(struct SaveBlock, personalidadJugador),
    .playerNameOffset = offsetof(struct SaveBlock, playerName),
    .playerGenderOffset = offsetof(struct SaveBlock, playerGender),
    .speciesInfo = gSpeciesInfo,
    .items = gItemsInfo,
    .moves = gMovesInfo,
    .ballGfx = gBallSpriteSheets,
    .ballPalettes = gBallSpritePalettes,
    .gameClearFlag = FLAG_SYS_GAME_CLEAR,
    .ribbonFlag = FLAG_SYS_RIBBON_GET,
    .bagCountItems = BAG_ITEMS_COUNT,
    .bagCountKeyItems = BAG_KEYITEMS_COUNT,
    .bagCountPokeballs = BAG_POKEBALLS_COUNT,
    .bagCountTMHMs = BAG_TMHM_COUNT,
    .bagCountBerries = BAG_BERRIES_COUNT,
    .giftRibbonsOffset = offsetof(struct SaveBlock, giftRibbons),
    .moveDescriptions = NULL,
};

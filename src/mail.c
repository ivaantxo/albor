#include "global.h"
#include "mail.h"
#include "constants/items.h"
#include "main.h"
#include "overworld.h"
#include "task.h"
#include "efecto_horizontal.h"
#include "palette.h"
#include "text.h"
#include "menu.h"
#include "menu_helpers.h"
#include "text_window.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "gpu_regs.h"
#include "bg.h"
#include "pokemon_icon.h"
#include "malloc.h"
#include "graphics.h"
#include "constants/rgb.h"

// Bead and Dream mail feature an icon of the Pokémon holding it.
enum {
    ICON_TYPE_NONE,
    ICON_TYPE_BEAD,
    ICON_TYPE_DREAM,
};

struct MailLineLayout
{
    u8 xOffset:6;
    u8 height;
};

struct MailLayout
{
    u8 numLines;
    u8 signatureYPos;
    u8 signatureWidth;
    u8 wordsYPos;
    u8 wordsXPos;
    const struct MailLineLayout *lines;
};

struct MailGraphics
{
    const u16 *palette;
    const u8 *tiles;
    const u8 *tileMap;
    u16 textColor;
    u16 textShadow;
};

struct MailRead
{
    /*0x0000*/ u8 message[8][64];
    /*0x0200*/ u8 playerName[12];
    /*0x020C*/ MainCallback exitCallback;
    /*0x0210*/ MainCallback callback;
    /*0x0214*/ struct Mail *mail;
    /*0x0218*/ bool8 hasText;
    /*0x0219*/ u8 signatureWidth;
    /*0x021a*/ u8 mailType;
    /*0x021b*/ u8 iconType;
    /*0x021c*/ u8 monIconSpriteId;
    /*0x021d*/ u8 language;
    /*0x021e*/ bool8 international;
    /*0x0220*/ u8 *(*parserSingle)(u8 *dest, u16 word);
    /*0x0224*/ u8 *(*parserMultiple)(u8 *dest, const u16 *src, u16 length1, u16 length2);
    /*0x0228*/ const struct MailLayout *layout;
    /*0x022c*/ u8 bg1TilemapBuffer[0x1000];
    /*0x122c*/ u8 bg2TilemapBuffer[0x1000];
};

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = FONDO_0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = FONDO_1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 1
    }, {
        .bg = FONDO_2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .priority = 2
    }
};

static const struct WindowTemplate sWindowTemplates[] = {
    {
        .bg = FONDO_0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sTextColors[] = {
    TEXT_COLOR_TRANSPARENT,
    TEXT_DYNAMIC_COLOR_1,
    TEXT_DYNAMIC_COLOR_2
};

// Background is alternating bars of a dark/light color.
// Either blue or red depending on player's gender
static const u16 sBgColors[GENDER_COUNT][2] = {
    [MALE]   = { RGB(13, 22, 26), RGB(5, 13, 20) },
    [FEMALE] = { RGB(28, 15, 17), RGB(20, 6, 14) }
};

static const struct MailGraphics sMailGraphics[] = {
    [ITEM_TO_MAIL(ITEM_ORANGE_MAIL)] = {
        .palette = gMailPalette_Orange,
        .tiles = gMailTiles_Orange,
        .tileMap = gMailTilemap_Orange,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_HARBOR_MAIL)] = {
        .palette = gMailPalette_Harbor,
        .tiles = gMailTiles_Harbor,
        .tileMap = gMailTilemap_Harbor,
        .textColor = RGB_WHITE,
        .textShadow = RGB(17, 17, 17),
    },
    [ITEM_TO_MAIL(ITEM_GLITTER_MAIL)] = {
        .palette = gMailPalette_Glitter,
        .tiles = gMailTiles_Glitter,
        .tileMap = gMailTilemap_Glitter,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_MECH_MAIL)] = {
        .palette = gMailPalette_Mech,
        .tiles = gMailTiles_Mech,
        .tileMap = gMailTilemap_Mech,
        .textColor = RGB_WHITE,
        .textShadow = RGB(17, 17, 17),
    },
    [ITEM_TO_MAIL(ITEM_WOOD_MAIL)] = {
        .palette = gMailPalette_Wood,
        .tiles = gMailTiles_Wood,
        .tileMap = gMailTilemap_Wood,
        .textColor = RGB_WHITE,
        .textShadow = RGB(17, 17, 17),
    },
    [ITEM_TO_MAIL(ITEM_WAVE_MAIL)] = {
        .palette = gMailPalette_Wave,
        .tiles = gMailTiles_Wave,
        .tileMap = gMailTilemap_Wave,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_BEAD_MAIL)] = {
        .palette = gMailPalette_Bead,
        .tiles = gMailTiles_Bead,
        .tileMap = gMailTilemap_Bead,
        .textColor = RGB_WHITE,
        .textShadow = RGB(17, 17, 17),
    },
    [ITEM_TO_MAIL(ITEM_SHADOW_MAIL)] = {
        .palette = gMailPalette_Shadow,
        .tiles = gMailTiles_Shadow,
        .tileMap = gMailTilemap_Shadow,
        .textColor = RGB_WHITE,
        .textShadow = RGB(17, 17, 17),
    },
    [ITEM_TO_MAIL(ITEM_TROPIC_MAIL)] = {
        .palette = gMailPalette_Tropic,
        .tiles = gMailTiles_Tropic,
        .tileMap = gMailTilemap_Tropic,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_DREAM_MAIL)] = {
        .palette = gMailPalette_Dream,
        .tiles = gMailTiles_Dream,
        .tileMap = gMailTilemap_Dream,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_FAB_MAIL)] = {
        .palette = gMailPalette_Fab,
        .tiles = gMailTiles_Fab,
        .tileMap = gMailTilemap_Fab,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    },
    [ITEM_TO_MAIL(ITEM_RETRO_MAIL)] = {
        .palette = gMailPalette_Retro,
        .tiles = gMailTiles_Retro,
        .tileMap = gMailTilemap_Retro,
        .textColor = RGB(10, 10, 10),
        .textShadow = RGB(25, 25, 25),
    }
};

static const struct MailLineLayout sLineLayouts_Wide[] = {
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 }
};

static const struct MailLayout sMailLayouts_Wide[] = {
    [ITEM_TO_MAIL(ITEM_ORANGE_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_HARBOR_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_GLITTER_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_MECH_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_WOOD_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_WAVE_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_BEAD_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_SHADOW_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_TROPIC_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_DREAM_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_FAB_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 8,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 4,
        .lines = sLineLayouts_Wide,
    },
    [ITEM_TO_MAIL(ITEM_RETRO_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Wide),
        .signatureYPos = 0,
        .signatureWidth = 0,
        .wordsYPos = 2,
        .wordsXPos = 0,
        .lines = sLineLayouts_Wide,
    },
};

static const struct MailLineLayout sLineLayouts_Tall[] = {
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 },
    { .xOffset = 0, .height = 16 }
};

static const struct MailLayout sMailLayouts_Tall[] = {
    [ITEM_TO_MAIL(ITEM_ORANGE_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 7,
        .signatureWidth = 88,
        .wordsYPos = 11,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_HARBOR_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 10,
        .signatureWidth = 96,
        .wordsYPos = 9,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_GLITTER_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 12,
        .signatureWidth = 104,
        .wordsYPos = 5,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_MECH_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 5,
        .signatureWidth = 96,
        .wordsYPos = 8,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_WOOD_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 10,
        .signatureWidth = 96,
        .wordsYPos = 9,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_WAVE_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 9,
        .signatureWidth = 112,
        .wordsYPos = 5,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_BEAD_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 12,
        .signatureWidth = 104,
        .wordsYPos = 9,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_SHADOW_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 13,
        .signatureWidth = 104,
        .wordsYPos = 13,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_TROPIC_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 9,
        .signatureWidth = 96,
        .wordsYPos = 9,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_DREAM_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 9,
        .signatureWidth = 96,
        .wordsYPos = 9,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_FAB_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 17,
        .signatureWidth = 104,
        .wordsYPos = 15,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
    [ITEM_TO_MAIL(ITEM_RETRO_MAIL)] = {
        .numLines = ARRAY_COUNT(sLineLayouts_Tall),
        .signatureYPos = 9,
        .signatureWidth = 96,
        .wordsYPos = 5,
        .wordsXPos = 30,
        .lines = sLineLayouts_Tall,
    },
};

void ReadMail(struct Mail *mail, void (*exitCallback)(void), bool8 hasText)
{

}

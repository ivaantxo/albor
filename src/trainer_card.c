#include "global.h"
#include "distorsion_fondo.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "malloc.h"
#include "bg.h"
#include "sound.h"
#include "overworld.h"
#include "menu.h"
#include "text.h"
#include "event_data.h"
#include "money.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "graphics.h"
#include "trainer_pokemon_sprites.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/trainers.h"

enum {
    WIN_MSG,
    WIN_CARD_TEXT,
    WIN_TRAINER_PIC,
};

struct TrainerCardData
{
    u8 mainState;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    u8 flipDrawState;
    u8 timeColonBlinkTimer;
    bool8 timeColonInvisible;
    bool8 onBack;
    bool8 allowDMACopy;
    bool8 hasPokedex;
    bool8 hasHofResult;
    bool8 hasTrades;
    u8 badgeCount[NUM_BADGES];
    u8 textPlayersCard[70];
    u8 textHofTime[70];
    u8 textNumTrades[140];
    u16 monIconPal[16 * PARTY_SIZE];
    s8 flipBlendY;
    bool8 timeColonNeedDraw;
    u8 cardType;
    bool8 isHoenn;
    u16 blendColor;
    void (*callback2)(void);
    struct TrainerCard trainerCard;
    u16 frontTilemap[600];
    u16 backTilemap[600];
    u16 bgTilemap[600];
    u8 badgeTiles[0x80 * NUM_BADGES];
    u8 stickerTiles[0x200];
    u8 cardTiles[0x2300];
    u16 cardTilemapBuffer[0x1000];
    u16 bgTilemapBuffer[0x1000];
    u16 cardTop;
    u8 language;
};

// EWRAM
EWRAM_DATA struct TrainerCard gTrainerCards[4] = {0};
EWRAM_DATA static struct TrainerCardData *sData = NULL;

//this file's functions
static void VblankCb_TrainerCard(void);
static void HblankCb_TrainerCard(void);
static void BlinkTimeColon(void);
static void CB2_TrainerCard(void);
static void CloseTrainerCard(u8 task);
static bool8 PrintAllOnCardFront(void);
static void DrawTrainerCardWindow(u8);
static void CreateTrainerCardTrainerPic(void);
static void DrawCardScreenBackground(u16 *);
static void DrawCardFrontOrBack(u16 *);
static void DrawStarsAndBadgesOnCard(void);
static void PrintTimeOnCard(void);
static void FlipTrainerCard(void);
static bool8 LoadCardGfx(void);
static void CB2_InitTrainerCard(void);
static void SetPlayerCardData(struct TrainerCard *, u8);
static void TrainerCard_GenerateCardForPlayer(struct TrainerCard *);
static u8 VersionToCardType(u8);
static void SetDataFromTrainerCard(void);
static void InitGpuRegs(void);
static void ResetGpuRegs(void);
static void InitBgsAndWindows(void);
static void SetTrainerCardCb2(void);
static void SetUpTrainerCardTask(void);
static void InitTrainerCardData(void);
static void PrintNameOnCardFront(void);
static void PrintIdOnCard(void);
static void PrintMoneyOnCard(void);
static void PrintPokedexOnCard(void);
static void PrintProfilePhraseOnCard(void);
static bool8 PrintAllOnCardBack(void);
static void PrintNameOnCardBack(void);
static void PrintHofDebutTimeOnCard(void);
static void PrintTradesStringOnCard(void);
static void PrintPokeblockStringOnCard(void);
static void PrintUnionStringOnCard(void);
static void PrintContestStringOnCard(void);
static void PrintPokemonIconsOnCard(void);
static void PrintStickersOnCard(void);
static void BufferTextsVarsForCardPage2(void);
static void BufferNameForCardBack(void);
static void BufferHofDebutTime(void);
static void BufferNumTrades(void);
static void PrintStatOnBackOfCard(u8 top, const u8 *str1, u8 *str2, const u8 *color);
static void LoadStickerGfx(void);
static u8 SetCardBgsAndPals(void);
static void DrawCardBackStats(void);
static void Task_DoCardFlipTask(u8);
static bool8 Task_BeginCardFlip(struct Task *task);
static bool8 Task_AnimateCardFlipDown(struct Task *task);
static bool8 Task_DrawFlippedCardSide(struct Task *task);
static bool8 Task_SetCardFlipped(struct Task *task);
static bool8 Task_AnimateCardFlipUp(struct Task *task);
static bool8 Task_EndCardFlip(struct Task *task);
static void UpdateCardFlipRegs(u16);

static const u32 sTrainerCardStickers_Gfx[]      = INCBIN_U32("graphics/trainer_card/frlg/stickers.4bpp.lz");
static const u16 sUnused_Pal[]                   = INCBIN_U16("graphics/trainer_card/unused.gbapal");
static const u16 sHoennTrainerCardBronze_Pal[]   = INCBIN_U16("graphics/trainer_card/bronze.gbapal");
static const u16 sKantoTrainerCardGreen_Pal[]    = INCBIN_U16("graphics/trainer_card/frlg/green.gbapal");
static const u16 sHoennTrainerCardCopper_Pal[]   = INCBIN_U16("graphics/trainer_card/copper.gbapal");
static const u16 sKantoTrainerCardBronze_Pal[]   = INCBIN_U16("graphics/trainer_card/frlg/bronze.gbapal");
static const u16 sHoennTrainerCardSilver_Pal[]   = INCBIN_U16("graphics/trainer_card/silver.gbapal");
static const u16 sKantoTrainerCardSilver_Pal[]   = INCBIN_U16("graphics/trainer_card/frlg/silver.gbapal");
static const u16 sHoennTrainerCardGold_Pal[]     = INCBIN_U16("graphics/trainer_card/gold.gbapal");
static const u16 sKantoTrainerCardGold_Pal[]     = INCBIN_U16("graphics/trainer_card/frlg/gold.gbapal");
static const u16 sHoennTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg.gbapal");
static const u16 sKantoTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/frlg/female_bg.gbapal");
static const u16 sHoennTrainerCardBadges_Pal[]   = INCBIN_U16("graphics/trainer_card/badges.gbapal");
static const u16 sKantoTrainerCardBadges_Pal[]   = INCBIN_U16("graphics/trainer_card/frlg/badges.gbapal");
static const u16 sTrainerCardStar_Pal[]          = INCBIN_U16("graphics/trainer_card/star.gbapal");
static const u16 sTrainerCardSticker1_Pal[]      = INCBIN_U16("graphics/trainer_card/frlg/stickers1.gbapal");
static const u16 sTrainerCardSticker2_Pal[]      = INCBIN_U16("graphics/trainer_card/frlg/stickers2.gbapal");
static const u16 sTrainerCardSticker3_Pal[]      = INCBIN_U16("graphics/trainer_card/frlg/stickers3.gbapal");
static const u16 sTrainerCardSticker4_Pal[]      = INCBIN_U16("graphics/trainer_card/frlg/stickers4.gbapal");
static const u32 sHoennTrainerCardBadges_Gfx[]   = INCBIN_U32("graphics/trainer_card/badges.4bpp.lz");
static const u32 sKantoTrainerCardBadges_Gfx[]   = INCBIN_U32("graphics/trainer_card/frlg/badges.4bpp.lz");

static const struct BgTemplate sTrainerCardBgTemplates[4] =
{
    {
        .bg = FONDO_0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = FONDO_32x64,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = FONDO_1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = FONDO_3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 1,
        .baseTile = 192
    },
};

static const struct WindowTemplate sTrainerCardWindowTemplates[] =
{
    [WIN_MSG] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x253,
    },
    [WIN_CARD_TEXT] = {
        .bg = FONDO_1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    [WIN_TRAINER_PIC] = {
        .bg = FONDO_3,
        .tilemapLeft = 19,
        .tilemapTop = 5,
        .width = 9,
        .height = 10,
        .paletteNum = 8,
        .baseBlock = 0x150,
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 *const sHoennTrainerCardPals[] =
{
    gHoennTrainerCardGreen_Pal,  // Default (0 stars)
    sHoennTrainerCardBronze_Pal, // 1 star
    sHoennTrainerCardCopper_Pal, // 2 stars
    sHoennTrainerCardSilver_Pal, // 3 stars
    sHoennTrainerCardGold_Pal,   // 4 stars
};

static const u16 *const sKantoTrainerCardPals[] =
{
    gKantoTrainerCardBlue_Pal,   // Default (0 stars)
    sKantoTrainerCardGreen_Pal,  // 1 star
    sKantoTrainerCardBronze_Pal, // 2 stars
    sKantoTrainerCardSilver_Pal, // 3 stars
    sKantoTrainerCardGold_Pal,   // 4 stars
};

static const u8 sTrainerCardTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTrainerCardStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 sTimeColonInvisibleTextColors[6] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT};

static const u8 sTrainerPicOffset[2][GENDER_COUNT][2] =
{
    // Kanto
    {
        [MALE]   = {13, 4},
        [FEMALE] = {13, 4}
    },
    // Hoenn
    {
        [MALE]   = {1, 0},
        [FEMALE] = {1, 0}
    },
};

static bool8 (*const sTrainerCardFlipTasks[])(struct Task *) =
{
    Task_BeginCardFlip,
    Task_AnimateCardFlipDown,
    Task_DrawFlippedCardSide,
    Task_SetCardFlipped,
    Task_AnimateCardFlipUp,
    Task_EndCardFlip,
};

static void VblankCb_TrainerCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    BlinkTimeColon();
    if (sData->allowDMACopy)
        DmaCopy16(3, &gRegistrosBuffersDistorsionFondo[0], &gRegistrosBuffersDistorsionFondo[1], 0x140);
}

static void HblankCb_TrainerCard(void)
{
    u16 backup;
    u16 bgVOffset;

    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gRegistrosBuffersDistorsionFondo[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_TrainerCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CloseTrainerCard(u8 taskId)
{
    SetMainCallback2(sData->callback2);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    DestroyTask(taskId);
}

// States for Task_TrainerCard. Skips the initial states, which are done once in order
#define STATE_HANDLE_INPUT_FRONT  10
#define STATE_HANDLE_INPUT_BACK   11
#define STATE_WAIT_FLIP_TO_BACK   12
#define STATE_WAIT_FLIP_TO_FRONT  13
#define STATE_CLOSE_CARD          14

static void Task_TrainerCard(u8 taskId)
{
    switch (sData->mainState)
    {
    // Draw card initially
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(WIN_CARD_TEXT, PIXEL_FILL(0));
            sData->mainState++;
        }
        break;
    case 1:
        if (PrintAllOnCardFront())
            sData->mainState++;
        break;
    case 2:
        DrawTrainerCardWindow(WIN_CARD_TEXT);
        sData->mainState++;
        break;
    case 3:
        FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
        CreateTrainerCardTrainerPic();
        DrawTrainerCardWindow(WIN_TRAINER_PIC);
        sData->mainState++;
        break;
    case 4:
        DrawCardScreenBackground(sData->bgTilemap);
        sData->mainState++;
        break;
    case 5:
        DrawCardFrontOrBack(sData->frontTilemap);
        sData->mainState++;
        break;
    case 6:
        DrawStarsAndBadgesOnCard();
        sData->mainState++;
        break;
    // Fade in
    case 7:
        BlendPalettes(PALETTES_ALL, 16, sData->blendColor);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, sData->blendColor);
        SetVBlankCallback(VblankCb_TrainerCard);
        sData->mainState++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_FRONT;
        }
        break;
    case 9:
        if (!IsSEPlaying())
            sData->mainState++;
        break;
    case STATE_HANDLE_INPUT_FRONT:
        PrintTimeOnCard();
        DrawTrainerCardWindow(WIN_CARD_TEXT);
        sData->timeColonNeedDraw = FALSE;
        if (JOY_NEW(A_BUTTON))
        {
            FlipTrainerCard();
            PlaySE(SE_RG_CARD_FLIP);
            sData->mainState = STATE_WAIT_FLIP_TO_BACK;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_WAIT_FLIP_TO_BACK:
        break;
    case STATE_HANDLE_INPUT_BACK:
        if (JOY_NEW(B_BUTTON))
        {
            FlipTrainerCard();
            sData->mainState = STATE_WAIT_FLIP_TO_FRONT;
            PlaySE(SE_RG_CARD_FLIP);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!UpdatePaletteFade())
            CloseTrainerCard(taskId);
        break;
    case STATE_WAIT_FLIP_TO_FRONT:
        break;
   }
}

static bool8 LoadCardGfx(void)
{
    switch (sData->gfxLoadState)
    {
    case 0:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gHoennTrainerCardBg_Tilemap, sData->bgTilemap);
        else
            LZ77UnCompWram(gKantoTrainerCardBg_Tilemap, sData->bgTilemap);
        break;
    case 1:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gHoennTrainerCardBack_Tilemap, sData->backTilemap);
        else
            LZ77UnCompWram(gKantoTrainerCardBack_Tilemap, sData->backTilemap);
        break;
    case 2:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gHoennTrainerCardFront_Tilemap, sData->frontTilemap);
        else
            LZ77UnCompWram(gKantoTrainerCardFront_Tilemap, sData->frontTilemap);
        break;
    case 3:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(sHoennTrainerCardBadges_Gfx, sData->badgeTiles);
        else
            LZ77UnCompWram(sKantoTrainerCardBadges_Gfx, sData->badgeTiles);
        break;
    case 4:
        if (sData->cardType != CARD_TYPE_FRLG)
            LZ77UnCompWram(gHoennTrainerCard_Gfx, sData->cardTiles);
        else
            LZ77UnCompWram(gKantoTrainerCard_Gfx, sData->cardTiles);
        break;
    case 5:
        if (sData->cardType == CARD_TYPE_FRLG)
            LZ77UnCompWram(sTrainerCardStickers_Gfx, sData->stickerTiles);
        break;
    default:
        sData->gfxLoadState = 0;
        return TRUE;
    }
    sData->gfxLoadState++;
    return FALSE;
}

static void CB2_InitTrainerCard(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetGpuRegs();
        SetUpTrainerCardTask();
        gMain.state++;
        break;
    case 1:
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        if (!sData->blendColor)
            DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 7:
        LoadStickerGfx();
        gMain.state++;
        break;
    case 8:
        InitGpuRegs();
        gMain.state++;
        break;
    case 9:
        BufferTextsVarsForCardPage2();
        gMain.state++;
        break;
    case 10:
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
        SetTrainerCardCb2();
        break;
    }
}

u32 CountPlayerTrainerStars(void)
{
    u8 stars = 0;

    if (GetGameStat(GAME_STAT_ENTERED_HOF))
        stars++;
    if (HasAllMons())
        stars++;

    return stars;
}

static void SetPlayerCardData(struct TrainerCard *trainerCard, u8 cardType)
{

}

static void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    trainerCard->version = GAME_VERSION;
    SetPlayerCardData(trainerCard, CARD_TYPE_EMERALD);
}

void CopyTrainerCardData(struct TrainerCard *dst, struct TrainerCard *src, u8 gameVersion)
{
    memset(dst, 0, sizeof(struct TrainerCard));
    dst->version = gameVersion;

    switch (VersionToCardType(gameVersion))
    {
    case CARD_TYPE_FRLG:
        memcpy(dst, src, 0x60);
        break;
    case CARD_TYPE_RS:
        memcpy(dst, src, 0x38);
        break;
    case CARD_TYPE_EMERALD:
        memcpy(dst, src, 0x60);
        break;
    }
}

static void SetDataFromTrainerCard(void)
{
    u32 i;
    u32 badgeFlag;

    sData->hasPokedex = FALSE;
    sData->hasHofResult = FALSE;
    sData->hasTrades = FALSE;
    memset(sData->badgeCount, 0, sizeof(sData->badgeCount));
    if (sData->trainerCard.hasPokedex)
        sData->hasPokedex++;

    if (sData->trainerCard.hofDebutHours
     || sData->trainerCard.hofDebutMinutes
     || sData->trainerCard.hofDebutSeconds)
        sData->hasHofResult++;

    if (sData->trainerCard.pokemonTrades)
        sData->hasTrades++;

    for (i = 0, badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++, i++)
    {
        if (FlagGet(badgeFlag))
            sData->badgeCount[i]++;
    }
}

static void InitGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, ALTURA_PANTALLA);
    SetGpuReg(REG_OFFSET_WIN0H, ANCHO_PANTALLA);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

static void UpdateCardFlipRegs(u16 cardTop)
{
    s8 blendY = (cardTop + 40) / 10;

    if (blendY <= 4)
        blendY = 0;
    sData->flipBlendY = blendY;
    SetGpuReg(REG_OFFSET_BLDY, sData->flipBlendY);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(sData->cardTop, ALTURA_PANTALLA - sData->cardTop));
}

static void ResetGpuRegs(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

static void InitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags();
    IniciaFondosDesdePlantillas(MODO_0, sTrainerCardBgTemplates, ARRAY_COUNT(sTrainerCardBgTemplates));
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    InitWindows(sTrainerCardWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void SetTrainerCardCb2(void)
{
    SetMainCallback2(CB2_TrainerCard);
}

static void SetUpTrainerCardTask(void)
{
    ResetTasks();
    ParaDistorsionFondo();
    CreateTask(Task_TrainerCard, 0);
    InitTrainerCardData();
    SetDataFromTrainerCard();
}

static bool8 PrintAllOnCardFront(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCardFront();
        break;
    case 1:
        PrintIdOnCard();
        break;
    case 2:
        PrintMoneyOnCard();
        break;
    case 3:
        PrintPokedexOnCard();
        break;
    case 4:
        PrintTimeOnCard();
        break;
    case 5:
        PrintProfilePhraseOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static bool8 PrintAllOnCardBack(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCardBack();
        break;
    case 1:
        PrintHofDebutTimeOnCard();
        break;
    case 2:
        break;
    case 3:
        PrintTradesStringOnCard();
        break;
    case 4:
        PrintPokeblockStringOnCard();
        break;
    case 5:
        PrintUnionStringOnCard();
        PrintContestStringOnCard();
        break;
    case 6:
        PrintPokemonIconsOnCard();
        break;
    case 7:
        PrintStickersOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void BufferTextsVarsForCardPage2(void)
{
    BufferNameForCardBack();
    BufferHofDebutTime();
    BufferNumTrades();
}

static void PrintNameOnCardFront(void)
{
    u8 buffer[32];
    u8 *txtPtr;
    txtPtr = StringCopy(buffer, gText_TrainerCardName);
    StringCopy(txtPtr, sData->trainerCard.playerName);
    ConvertInternationalString(txtPtr, sData->language);
    if (sData->cardType == CARD_TYPE_FRLG)
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 20, 28, sTrainerCardTextColors, TEXT_SKIP_DRAW, buffer);
    else
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 33, sTrainerCardTextColors, TEXT_SKIP_DRAW, buffer);
}

static void PrintIdOnCard(void)
{
    u8 buffer[32];
    u8 *txtPtr;
    s32 xPos;
    u32 top;
    txtPtr = StringCopy(buffer, gText_TrainerCardIDNo);
    ConvertIntToDecimalStringN(txtPtr, sData->trainerCard.trainerId, STR_CONV_MODE_LEADING_ZEROS, 5);
    if (sData->cardType == CARD_TYPE_FRLG)
    {
        xPos = GetStringCenterAlignXOffset(FONT_NORMAL, buffer, 80) + 132;
        top = 9;
    }
    else
    {
        xPos = GetStringCenterAlignXOffset(FONT_NORMAL, buffer, 96) + 120;
        top = 9;
    }

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xPos, top, sTrainerCardTextColors, TEXT_SKIP_DRAW, buffer);
}

static void PrintMoneyOnCard(void)
{
    s32 xOffset;
    u8 top;

    if (!sData->isHoenn)
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 20, 56, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardMoney);
    else
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 57, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardMoney);

    ConvertIntToDecimalStringN(gVariableTexto1, sData->trainerCard.money, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    StringExpandPlaceholders(gVariableTextoAmpliada, gText_PokedollarVar1);
    if (!sData->isHoenn)
    {
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gVariableTextoAmpliada, 144);
        top = 56;
    }
    else
    {
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gVariableTextoAmpliada, 128);
        top = 57;
    }
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xOffset, top, sTrainerCardTextColors, TEXT_SKIP_DRAW, gVariableTextoAmpliada);
}

static void PrintPokedexOnCard(void)
{
    s32 xOffset;
    u8 top;
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        if (!sData->isHoenn)
            AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 20, 72, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardPokedex);
        else
            AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 73, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardPokedex);
        StringCopy(ConvertIntToDecimalStringN(gVariableTextoAmpliada, sData->trainerCard.caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 4), gText_EmptyString);
        if (!sData->isHoenn)
        {
            xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gVariableTextoAmpliada, 144);
            top = 72;
        }
        else
        {
            xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gVariableTextoAmpliada, 128);
            top = 73;
        }
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xOffset, top, sTrainerCardTextColors, TEXT_SKIP_DRAW, gVariableTextoAmpliada);
    }
}

static const u8 *const sTimeColonTextColors[] = {sTrainerCardTextColors, sTimeColonInvisibleTextColors};

static void PrintTimeOnCard(void)
{
    u16 hours;
    u16 minutes;
    s32 width;
    u32 x, y, totalWidth;

    if (!sData->isHoenn)
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 20, 88, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardTime);
    else
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 16, 89, sTrainerCardTextColors, TEXT_SKIP_DRAW, gText_TrainerCardTime);

    hours = gSaveBlockPtr->playTimeHours;
    minutes = gSaveBlockPtr->playTimeMinutes;

    if (hours > 999)
        hours = 999;
    if (minutes > 59)
        minutes = 59;
    width = GetStringWidth(FONT_NORMAL, gText_Colon2, 0);

    if (!sData->isHoenn)
    {
        x = 144;
        y = 88;
    }
    else
    {
        x = 128;
        y = 89;
    }
    totalWidth = width + 30;
    x -= totalWidth;

    FillWindowPixelRect(WIN_CARD_TEXT, PIXEL_FILL(0), x, y, totalWidth, 15);
    ConvertIntToDecimalStringN(gVariableTextoAmpliada, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, x, y, sTrainerCardTextColors, TEXT_SKIP_DRAW, gVariableTextoAmpliada);
    x += 18;
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, x, y, sTimeColonTextColors[sData->timeColonInvisible], TEXT_SKIP_DRAW, gText_Colon2);
    x += width;
    ConvertIntToDecimalStringN(gVariableTextoAmpliada, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, x, y, sTrainerCardTextColors, TEXT_SKIP_DRAW, gVariableTextoAmpliada);
}

static void PrintProfilePhraseOnCard(void)
{

}

static void BufferNameForCardBack(void)
{
    StringCopy(sData->textPlayersCard, sData->trainerCard.playerName);
    ConvertInternationalString(sData->textPlayersCard, sData->language);
    if (sData->cardType != CARD_TYPE_FRLG)
    {
        StringCopy(gVariableTexto1, sData->textPlayersCard);
        StringExpandPlaceholders(sData->textPlayersCard, gText_Var1sTrainerCard);
    }
}

static void PrintNameOnCardBack(void)
{
    if (!sData->isHoenn)
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, 136, 9, sTrainerCardTextColors, TEXT_SKIP_DRAW, sData->textPlayersCard);
    else
        AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, sData->textPlayersCard, 216), 9, sTrainerCardTextColors, TEXT_SKIP_DRAW, sData->textPlayersCard);
}

static const u8 sText_HofTime[] = _("{VAR_TEXTO_1}:{VAR_TEXTO_2}:{VAR_TEXTO_3}");

static void BufferHofDebutTime(void)
{
    if (sData->hasHofResult)
    {
        ConvertIntToDecimalStringN(gVariableTexto1, sData->trainerCard.hofDebutHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gVariableTexto2, sData->trainerCard.hofDebutMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        ConvertIntToDecimalStringN(gVariableTexto3, sData->trainerCard.hofDebutSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(sData->textHofTime, sText_HofTime);
    }
}

static void PrintStatOnBackOfCard(u8 top, const u8 *statName, u8 *stat, const u8 *color)
{
    static const u8 xOffsets[] = {8, 16};
    static const u8 widths[] = {216, 216};

    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, xOffsets[sData->isHoenn], top * 16 + 33, sTrainerCardTextColors, TEXT_SKIP_DRAW, statName);
    AddTextPrinterParameterized3(WIN_CARD_TEXT, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, stat, widths[sData->isHoenn]), top * 16 + 33, color, TEXT_SKIP_DRAW, stat);
}

static void PrintHofDebutTimeOnCard(void)
{
    if (sData->hasHofResult)
        PrintStatOnBackOfCard(0, gText_HallOfFameDebut, sData->textHofTime, sTrainerCardStatColors);
}

static void BufferNumTrades(void)
{
    if (sData->hasTrades)
        ConvertIntToDecimalStringN(sData->textNumTrades, sData->trainerCard.pokemonTrades, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintTradesStringOnCard(void)
{
    if (sData->hasTrades)
        PrintStatOnBackOfCard(2, gText_PokemonTrades, sData->textNumTrades, sTrainerCardStatColors);
}

static void PrintUnionStringOnCard(void)
{

}

static void PrintPokeblockStringOnCard(void)
{

}

static void PrintContestStringOnCard(void)
{

}

static void PrintPokemonIconsOnCard(void)
{
    u32 i;
    u8 paletteSlots[PARTY_SIZE] = {5, 6, 7, 14, 9, 10};
    u8 xOffsets[PARTY_SIZE] = {0, 4, 8, 12, 16, 20};

    if (sData->cardType == CARD_TYPE_FRLG)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sData->trainerCard.monSpecies[i])
            {
                WriteSequenceToBgTilemapBuffer(3, 16 * i + 224, xOffsets[i] + 3, 15, 4, 4, paletteSlots[i], 1);
            }
        }
    }
}

static void PrintStickersOnCard(void)
{
    u32 i;
    u8 paletteSlots[4] = {11, 12, 13, 14};

    if (sData->cardType == CARD_TYPE_FRLG && sData->trainerCard.shouldDrawStickers == TRUE)
    {
        for (i = 0; i < TRAINER_CARD_STICKER_TYPES; i++)
        {
            u8 sticker = sData->trainerCard.stickers[i];
            if (sData->trainerCard.stickers[i])
                WriteSequenceToBgTilemapBuffer(3, i * 4 + 320, i * 3 + 2, 2, 2, 2, paletteSlots[sticker - 1], 1);
        }
    }
}

static void LoadStickerGfx(void)
{
    LoadPalette(sTrainerCardSticker1_Pal, BG_PLTT_ID(11), PLTT_SIZE_4BPP);
    LoadPalette(sTrainerCardSticker2_Pal, BG_PLTT_ID(12), PLTT_SIZE_4BPP);
    LoadPalette(sTrainerCardSticker3_Pal, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
    LoadPalette(sTrainerCardSticker4_Pal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    CargaTilesFondo(3, sData->stickerTiles, 1024, 128);
}

static void DrawTrainerCardWindow(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static u8 SetCardBgsAndPals(void)
{
    switch (sData->bgPalLoadState)
    {
    case 0:
        CargaTilesFondo(3, sData->badgeTiles, ARRAY_COUNT(sData->badgeTiles), 0);
        break;
    case 1:
        CargaTilesFondo(0, sData->cardTiles, 0x1800, 0);
        break;
    case 2:
        if (sData->cardType != CARD_TYPE_FRLG)
        {
            LoadPalette(sHoennTrainerCardPals[sData->trainerCard.stars], BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
            LoadPalette(sHoennTrainerCardBadges_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sHoennTrainerCardFemaleBg_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        else
        {
            LoadPalette(sKantoTrainerCardPals[sData->trainerCard.stars], BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
            LoadPalette(sKantoTrainerCardBadges_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sKantoTrainerCardFemaleBg_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        }
        LoadPalette(sTrainerCardStar_Pal, BG_PLTT_ID(4), PLTT_SIZE_4BPP);
        break;
    case 3:
        SetBgTilemapBuffer(0, sData->cardTilemapBuffer);
        SetBgTilemapBuffer(2, sData->bgTilemapBuffer);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return 1;
    }
    sData->bgPalLoadState++;
    return 0;
}

static void DrawCardScreenBackground(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->bgTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(2);
}

static void DrawCardFrontOrBack(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->cardTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(0);
}

static void DrawStarsAndBadgesOnCard(void)
{
    static const u8 yOffsets[] = {7, 7};

    s16 i, x;
    u16 tileNum = 192;
    u8 palNum = 3;

    FillBgTilemapBufferRect(3, 143, 15, yOffsets[sData->isHoenn], sData->trainerCard.stars, 1, 4);
    x = 4;
    for (i = 0; i < NUM_BADGES; i++, tileNum += 2, x += 3)
    {
        if (sData->badgeCount[i])
        {
            FillBgTilemapBufferRect(3, tileNum, x, 15, 1, 1, palNum);
            FillBgTilemapBufferRect(3, tileNum + 1, x + 1, 15, 1, 1, palNum);
            FillBgTilemapBufferRect(3, tileNum + 16, x, 16, 1, 1, palNum);
            FillBgTilemapBufferRect(3, tileNum + 17, x + 1, 16, 1, 1, palNum);
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void DrawCardBackStats(void)
{
    if (sData->cardType == CARD_TYPE_FRLG)
    {
        if (sData->hasTrades)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 1);
        }
    }
    else
    {
        if (sData->hasTrades)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 0);
        }
        if (sData->trainerCard.contestsWithFriends)
        {
            FillBgTilemapBufferRect(3, 141, 27, 13, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 14, 1, 1, 0);
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void BlinkTimeColon(void)
{
    if (++sData->timeColonBlinkTimer > 60)
    {
        sData->timeColonBlinkTimer = 0;
        sData->timeColonInvisible ^= 1;
        sData->timeColonNeedDraw = TRUE;
    }
}

u8 GetTrainerCardStars(u8 cardId)
{
    struct TrainerCard *trainerCards = gTrainerCards;
    return trainerCards[cardId].stars;
}

#define tFlipState data[0]
#define tCardTop   data[1]

static void FlipTrainerCard(void)
{
    u8 taskId = CreateTask(Task_DoCardFlipTask, 0);
    Task_DoCardFlipTask(taskId);
    SetHBlankCallback(HblankCb_TrainerCard);
}

static void Task_DoCardFlipTask(u8 taskId)
{
    while(sTrainerCardFlipTasks[gTasks[taskId].tFlipState](&gTasks[taskId]))
        ;
}

static bool8 Task_BeginCardFlip(struct Task *task)
{
    u32 i;

    HideBg(1);
    HideBg(3);
    ParaDistorsionFondo();
    LimpiaDistorsionFondo();
    for (i = 0; i < ALTURA_PANTALLA; i++)
        gRegistrosBuffersDistorsionFondo[1][i] = 0;
    task->tFlipState++;
    return FALSE;
}

// Note: Cannot be ALTURA_PANTALLA / 2, or cardHeight will be 0
#define CARD_FLIP_Y ((ALTURA_PANTALLA / 2) - 3)

static bool8 Task_AnimateCardFlipDown(struct Task *task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tCardTop = CARD_FLIP_Y;
    else
        task->tCardTop += 7;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = ALTURA_PANTALLA - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (ALTURA_PANTALLA << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 *= 2;

    for (i = 0; i < cardTop; i++)
        gRegistrosBuffersDistorsionFondo[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 -= r10;
        gRegistrosBuffersDistorsionFondo[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < ALTURA_PANTALLA; i++)
        gRegistrosBuffersDistorsionFondo[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_DrawFlippedCardSide(struct Task *task)
{
    sData->allowDMACopy = FALSE;
    switch (sData->flipDrawState)
    {
    case 0:
        FillWindowPixelBuffer(WIN_CARD_TEXT, PIXEL_FILL(0));
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        break;
    case 1:
        if (!sData->onBack)
        {
            if (!PrintAllOnCardBack())
                return FALSE;
        }
        else
        {
            if (!PrintAllOnCardFront())
                return FALSE;
        }
        break;
    case 2:
        if (!sData->onBack)
            DrawCardFrontOrBack(sData->backTilemap);
        else
            DrawTrainerCardWindow(WIN_CARD_TEXT);
        break;
    case 3:
        if (!sData->onBack)
            DrawCardBackStats();
        else
            FillWindowPixelBuffer(WIN_TRAINER_PIC, PIXEL_FILL(0));
        break;
    case 4:
        if (sData->onBack)
            CreateTrainerCardTrainerPic();
        break;
    default:
        task->tFlipState++;
        sData->allowDMACopy = TRUE;
        sData->flipDrawState = 0;
        return FALSE;
    }
    sData->flipDrawState++;

    return FALSE;
}

static bool8 Task_SetCardFlipped(struct Task *task)
{
    sData->allowDMACopy = FALSE;

    // If on back of card, draw front of card because its being flipped
    if (sData->onBack)
    {
        DrawTrainerCardWindow(WIN_TRAINER_PIC);
        DrawCardScreenBackground(sData->bgTilemap);
        DrawCardFrontOrBack(sData->frontTilemap);
        DrawStarsAndBadgesOnCard();
    }
    DrawTrainerCardWindow(WIN_CARD_TEXT);
    sData->onBack ^= 1;
    task->tFlipState++;
    sData->allowDMACopy = TRUE;
    PlaySE(SE_RG_CARD_FLIPPING);
    return FALSE;
}

static bool8 Task_AnimateCardFlipUp(struct Task *task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop <= 5)
        task->tCardTop = 0;
    else
        task->tCardTop -= 5;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = ALTURA_PANTALLA - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (ALTURA_PANTALLA << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 /= 2;

    for (i = 0; i < cardTop; i++)
        gRegistrosBuffersDistorsionFondo[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 += r10;
        gRegistrosBuffersDistorsionFondo[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < ALTURA_PANTALLA; i++)
        gRegistrosBuffersDistorsionFondo[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop <= 0)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_EndCardFlip(struct Task *task)
{
    ShowBg(1);
    ShowBg(3);
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(Task_DoCardFlipTask));
    return FALSE;
}

void ShowPlayerTrainerCard(void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    sData->blendColor = RGB_BLACK;

    TrainerCard_GenerateCardForPlayer(&sData->trainerCard);
    SetMainCallback2(CB2_InitTrainerCard);
}

static void InitTrainerCardData(void)
{

}

static u8 VersionToCardType(u8 version)
{
    if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        return CARD_TYPE_FRLG;
    else if (version == VERSION_EMERALD)
        return CARD_TYPE_EMERALD;
    else
        return CARD_TYPE_RS;
}

static void CreateTrainerCardTrainerPic(void)
{

}

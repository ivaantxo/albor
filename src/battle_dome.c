#include "global.h"
#include "battle_dome.h"
#include "battle.h"
#include "battle_ai_util.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "event_data.h"
#include "overworld.h"
#include "util.h"
#include "malloc.h"
#include "string_util.h"
#include "random.h"
#include "task.h"
#include "main.h"
#include "gpu_regs.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "palette.h"
#include "decompress.h"
#include "party_menu.h"
#include "menu.h"
#include "sound.h"
#include "pokemon_icon.h"
#include "data.h"
#include "international_string_util.h"
#include "trainer_pokemon_sprites.h"
#include "scanline_effect.h"
#include "script_pokemon_util.h"
#include "graphics.h"
#include "constants/battle_dome.h"
#include "constants/battle_move_effects.h"
#include "constants/frontier_util.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/abilities.h"
#include "constants/songs.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"

#define TAG_BUTTONS 0

// Enough space to hold 2 match info cards worth of trainers and their parties
#define NUM_INFOCARD_SPRITES ((FRONTIER_PARTY_SIZE + 1) * 4)
#define NUM_INFOCARD_TRAINERS 2

// An 'Info Card' is a trainer or match information page that can be viewed on the Tourney Tree
struct TourneyTreeInfoCard
{
    u8 spriteIds[NUM_INFOCARD_SPRITES];
    u8 pos;
    u8 tournamentIds[NUM_INFOCARD_TRAINERS];
};

struct TourneyTreeLineSection
{
    u8 x;
    u8 y;
    u16 tile;
};

#define DOME_TRAINERS gSaveBlockPtr->frontier.domeTrainers
#define DOME_MONS     gSaveBlockPtr->frontier.domeMonIds

#define tState              data[0]

// Task data for Task_ShowTourneyTree
#define tNotInteractive     data[1]
#define tIsPrevTourneyTree  data[4]

// Task data for Task_ShowTourneyInfoCard
#define tTournamentId       data[1]
#define tMode               data[2]
#define tPrevTaskId         data[3]

enum {
    EFFECTIVENESS_MODE_GOOD,
    EFFECTIVENESS_MODE_BAD,
    EFFECTIVENESS_MODE_AI_VS_AI,
};

// Window IDs for the tourney tree
enum {
    TOURNEYWIN_NAMES_LEFT,
    TOURNEYWIN_NAMES_RIGHT,
    TOURNEYWIN_TITLE,
};

// Window IDs for the trainer (WIN_TRAINER_*) and match (WIN_MATCH_*) info cards.
// All 9 have a duplicate window at WIN + NUM_INFO_CARD_WINDOWS used by the alternate info card
enum {
    WIN_TRAINER_NAME,
    WIN_TRAINER_MON1_NAME,
    WIN_TRAINER_MON2_NAME, // Used implicitly
    WIN_TRAINER_MON3_NAME, // Used implicitly
    WIN_TRAINER_FLAVOR_TEXT = WIN_TRAINER_MON1_NAME + FRONTIER_PARTY_SIZE, // Trainer's potential, battle style, and stat texts
    WIN_MATCH_NUMBER,
    WIN_MATCH_TRAINER_NAME_LEFT,
    WIN_MATCH_TRAINER_NAME_RIGHT,
    WIN_MATCH_WIN_TEXT,
    NUM_INFO_CARD_WINDOWS
};

static u8 GetDomeTrainerMonIvs(u16);
static void SwapDomeTrainers(int, int, u16 *);
static void CalcDomeMonStats(const struct TrainerMon *fmon, int level, u8 ivs, int *stats);
static void CreateDomeOpponentMons(u16);
static int SelectOpponentMons_Good(u16, bool8);
static int SelectOpponentMons_Bad(u16, bool8);
static void Task_ShowTourneyInfoCard(u8);
static void Task_HandleInfoCardInput(u8);
static u8 Task_GetInfoCardInput(u8);
static void SetFacilityTrainerAndMonPtrs(void);
static int TrainerIdToTournamentId(u16);
static u16 TrainerIdOfPlayerOpponent(void);
static void Task_ShowTourneyTree(u8);
static void CB2_TourneyTree(void);
static void VblankCb_TourneyInfoCard(void);
static void DisplayMatchInfoOnCard(u8, u8);
static void DisplayTrainerInfoOnCard(u8, u8);
static int BufferDomeWinString(u8, u8 *);
static void CopyDomeTrainerName(u8 *, u16);
static void DecideRoundWinners(u8);
static void SpriteCB_HorizontalScrollArrow(struct Sprite *);
static void SpriteCB_VerticalScrollArrow(struct Sprite *);
static void InitDomeChallenge(void);
static void GetDomeData(void);
static void SetDomeData(void);
static void BufferDomeRoundText(void);
static void BufferDomeOpponentName(void);
static void InitDomeOpponentParty(void);
static void ShowDomeOpponentInfo(void);
static void ShowDomeTourneyTree(void);
static void ShowPreviousDomeTourneyTree(void);
static void SetDomeOpponentId(void);
static void SetDomeOpponentGraphicsId(void);
static void ShowNonInteractiveDomeTourneyTree(void);
static void ResolveDomeRoundWinners(void);
static void SaveDomeChallenge(void);
static void IncrementDomeStreaks(void);
static void ResetSketchedMoves(void);
static void RestoreDomePlayerPartyHeldItems(void);
static void ReduceDomePlayerPartyToSelectedMons(void);
static void GetPlayerSeededBeforeOpponent(void);
static void BufferLastDomeWinnerName(void);
static void InitRandomTourneyTreeResults(void);
static void InitDomeTrainers(void);

static EWRAM_DATA struct TourneyTreeInfoCard *sInfoCard = {0};

// 1st array is for cursor position (sprite id): cursor can be on a trainer info button, a match info button, or the exit/cancel button
// 2nd array is for round count. For some reason this array contains an inaccessible Round 5 which is identical to Round 4
// 3rd array is movement direction (see the MOVE_DIR_* constants in UpdateTourneyTreeCursor)
// The values are sprite IDs for the cursor position to move to, with 0xFF being an invalid move
static const u8 sTourneyTreeCursorMovementMap[DOME_TOURNAMENT_TRAINERS_COUNT + DOME_TOURNAMENT_MATCHES_COUNT + 1][DOME_ROUNDS_COUNT + 1][4]=
{
    [0]  = {{   7,    1,    8,   16}, {   7,    1,    8,   16}, {   7,    1,    8,   16}, {   7,    1,    8,   16}, {   7,    1,    8,   16}},
    [1]  = {{   0,    2,    9,   16}, {   0,    2,    9,   16}, {   0,    2,    9,   16}, {   0,    2,    9,   16}, {   0,    2,    9,   16}},
    [2]  = {{   1,    3,   10,   17}, {   1,    3,   10,   17}, {   1,    3,   10,   17}, {   1,    3,   10,   17}, {   1,    3,   10,   17}},
    [3]  = {{   2,    4,   11,   17}, {   2,    4,   11,   17}, {   2,    4,   11,   17}, {   2,    4,   11,   17}, {   2,    4,   11,   17}},
    [4]  = {{   3,    5,   12,   18}, {   3,    5,   12,   18}, {   3,    5,   12,   18}, {   3,    5,   12,   18}, {   3,    5,   12,   18}},
    [5]  = {{   4,    6,   13,   18}, {   4,    6,   13,   18}, {   4,    6,   13,   18}, {   4,    6,   13,   18}, {   4,    6,   13,   18}},
    [6]  = {{   5,    7,   14,   19}, {   5,    7,   14,   19}, {   5,    7,   14,   19}, {   5,    7,   14,   19}, {   5,    7,   14,   19}},
    [7]  = {{   6,    0,   15,   19}, {   6,    0,   15,   19}, {   6,    0,   15,   19}, {   6,    0,   15,   19}, {   6,    0,   15,   19}},
    [8]  = {{  31,    9,   20,   31}, {  31,    9,   20,   31}, {  31,    9,   20,   31}, {  31,    9,   20,   31}, {  31,    9,   20,   31}},
    [9]  = {{   8,   10,   20,    1}, {   8,   10,   20,    1}, {   8,   10,   20,    1}, {   8,   10,   20,    1}, {   8,   10,   20,    1}},
    [10] = {{   9,   11,   21,    2}, {   9,   11,   21,    2}, {   9,   11,   21,    2}, {   9,   11,   21,    2}, {   9,   11,   21,    2}},
    [11] = {{  10,   12,   21,    3}, {  10,   12,   21,    3}, {  10,   12,   21,    3}, {  10,   12,   21,    3}, {  10,   12,   21,    3}},
    [12] = {{  11,   13,   22,    4}, {  11,   13,   22,    4}, {  11,   13,   22,    4}, {  11,   13,   22,    4}, {  11,   13,   22,    4}},
    [13] = {{  12,   14,   22,    5}, {  12,   14,   22,    5}, {  12,   14,   22,    5}, {  12,   14,   22,    5}, {  12,   14,   22,    5}},
    [14] = {{  13,   15,   23,    6}, {  13,   15,   23,    6}, {  13,   15,   23,    6}, {  13,   15,   23,    6}, {  13,   15,   23,    6}},
    [15] = {{  14,   31,   23,    7}, {  14,   31,   23,    7}, {  14,   31,   23,    7}, {  14,   31,   23,    7}, {  14,   31,   23,    7}},
    [16] = {{  19,   17,    0,   20}, {  19,   17,    0,   24}, {  19,   17,    0,   24}, {  19,   17,    0,   24}, {  19,   17,    0,   24}},
    [17] = {{  16,   18,    2,   21}, {  16,   18,    2,   24}, {  16,   18,    2,   24}, {  16,   18,    2,   24}, {  16,   18,    2,   24}},
    [18] = {{  17,   19,    4,   22}, {  17,   19,    4,   25}, {  17,   19,    4,   25}, {  17,   19,    4,   25}, {  17,   19,    4,   25}},
    [19] = {{  18,   16,    6,   23}, {  18,   16,    6,   25}, {  18,   16,    6,   25}, {  18,   16,    6,   25}, {  18,   16,    6,   25}},
    [20] = {{  23,   21,   16,    8}, {  23,   21,   26,    8}, {  23,   21,   26,    8}, {  23,   21,   26,    8}, {  23,   21,   26,    8}},
    [21] = {{  20,   22,   17,   10}, {  20,   22,   26,   10}, {  20,   22,   26,   10}, {  20,   22,   26,   10}, {  20,   22,   26,   10}},
    [22] = {{  21,   23,   18,   12}, {  21,   23,   27,   12}, {  21,   23,   27,   12}, {  21,   23,   27,   12}, {  21,   23,   27,   12}},
    [23] = {{  22,   20,   19,   14}, {  22,   20,   27,   14}, {  22,   20,   27,   14}, {  22,   20,   27,   14}, {  22,   20,   27,   14}},
    [24] = {{0xFF, 0xFF, 0xFF, 0xFF}, {  25,   25,   16,   26}, {  25,   25,   16,   28}, {  25,   25,   16,   28}, {  25,   25,   16,   28}},
    [25] = {{0xFF, 0xFF, 0xFF, 0xFF}, {  24,   24,   18,   27}, {  24,   24,   18,   28}, {  24,   24,   18,   28}, {  24,   24,   18,   28}},
    [26] = {{0xFF, 0xFF, 0xFF, 0xFF}, {  27,   27,   24,   20}, {  27,   27,   29,   20}, {  27,   27,   29,   20}, {  27,   27,   29,   20}},
    [27] = {{0xFF, 0xFF, 0xFF, 0xFF}, {  26,   26,   25,   22}, {  26,   26,   29,   22}, {  26,   26,   29,   22}, {  26,   26,   29,   22}},
    [28] = {{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF,   24,   29}, {0xFF, 0xFF,   24,   30}, {0xFF, 0xFF,   24,   30}},
    [29] = {{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF,   28,   26}, {0xFF, 0xFF,   30,   26}, {0xFF, 0xFF,   30,   26}},
    [30] = {{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF,   28,   29}, {0xFF, 0xFF,   28,   29}},
    [31] = {{  15,    8,    8,    0}, {  15,    8,    8,    0}, {  15,    8,    8,    0}, {  15,    8,    8,    0}, {  15,    8,    8,    0}}, // TOURNEY_TREE_CLOSE_BUTTON
};

static const struct BgTemplate sTourneyTreeBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct BgTemplate sInfoCardBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 20,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 24,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct WindowTemplate sTourneyTreeWindowTemplates[] =
{
    [TOURNEYWIN_NAMES_LEFT] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 3,
        .width = 8,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 16,
    },
    [TOURNEYWIN_NAMES_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 3,
        .width = 8,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 144,
    },
    [TOURNEYWIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 1,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 272,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sInfoCardWindowTemplates[] =
{
    [WIN_TRAINER_NAME] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_TRAINER_MON1_NAME] = {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 53,
    },
    [WIN_TRAINER_MON2_NAME] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 7,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 69,
    },
    [WIN_TRAINER_MON3_NAME] = {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 96,
    },
    [WIN_TRAINER_FLAVOR_TEXT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 12,
        .width = 26,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 112,
    },
    [WIN_MATCH_NUMBER] = {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 23,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 294,
    },
    [WIN_MATCH_TRAINER_NAME_LEFT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 340,
    },
    [WIN_MATCH_TRAINER_NAME_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 356,
    },
    [WIN_MATCH_WIN_TEXT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 16,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 372,
    },
    // Duplicate windows used by the alternate info card
    // Same as above but on bg 1 instead of bg 0
    [WIN_TRAINER_NAME + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_TRAINER_MON1_NAME + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 16,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 53,
    },
    [WIN_TRAINER_MON2_NAME + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 7,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 69,
    },
    [WIN_TRAINER_MON3_NAME + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 16,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 96,
    },
    [WIN_TRAINER_FLAVOR_TEXT + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 12,
        .width = 26,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 112,
    },
    [WIN_MATCH_NUMBER + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 23,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 294,
    },
    [WIN_MATCH_TRAINER_NAME_LEFT + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 340,
    },
    [WIN_MATCH_TRAINER_NAME_RIGHT + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 20,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 356,
    },
    [WIN_MATCH_WIN_TEXT + NUM_INFO_CARD_WINDOWS] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 16,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 372,
    },
    #ifdef UBFIX
    DUMMY_WIN_TEMPLATE,
    #endif
};

static const struct ScanlineEffectParams sTourneyTreeScanlineEffectParams =
{
    .dmaDest = &REG_BG3CNT,
    .dmaControl = SCANLINE_EFFECT_DMACNT_16BIT,
    .initState = 1,
};

static const struct CompressedSpriteSheet sTourneyTreeButtonsSpriteSheet[] =
{
    {.data = gDomeTourneyTreeButtons_Gfx, .size = 0x0600, .tag = TAG_BUTTONS},
    {},
};

static const struct OamData sOamData_TourneyTreePokeball =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// For Exit/Cancel buttons
static const struct OamData sOamData_TourneyTreeCloseButton =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 1,
    .affineParam = 0,
};

static const struct OamData sOamData_VerticalScrollArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 2,
    .affineParam = 0,
};

static const struct OamData sOamData_HorizontalScrollArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 2,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_TourneyTreePokeballNormal[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};
static const union AnimCmd sSpriteAnim_TourneyTreePokeballSelected[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_TourneyTreePokeball[] =
{
    sSpriteAnim_TourneyTreePokeballNormal,
    sSpriteAnim_TourneyTreePokeballSelected,
};

// Sprite template for the pokeballs on the tourney tree that act as buttons to view a trainer/match info card
static const struct SpriteTemplate sTourneyTreePokeballSpriteTemplate =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_TourneyTreePokeball,
    .anims = sSpriteAnimTable_TourneyTreePokeball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd sSpriteAnim_TourneyTreeCancelButtonNormal[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_TourneyTreeCancelButtonSelected[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_TourneyTreeCancelButton[] =
{
    sSpriteAnim_TourneyTreeCancelButtonNormal,
    sSpriteAnim_TourneyTreeCancelButtonSelected,
};

static const struct SpriteTemplate sCancelButtonSpriteTemplate =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_TourneyTreeCloseButton,
    .anims = sSpriteAnimTable_TourneyTreeCancelButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd sSpriteAnim_TourneyTreeExitButtonNormal[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_TourneyTreeExitButtonSelected[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
 };

static const union AnimCmd * const sSpriteAnimTable_TourneyTreeExitButton[] =
{
    sSpriteAnim_TourneyTreeExitButtonNormal,
    sSpriteAnim_TourneyTreeExitButtonSelected,
};

static const struct SpriteTemplate sExitButtonSpriteTemplate =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_TourneyTreeCloseButton,
    .anims = sSpriteAnimTable_TourneyTreeExitButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd sSpriteAnim_UpArrow[] =
{
    ANIMCMD_FRAME(18, 1),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_DownArrow[] =
{
    ANIMCMD_FRAME(18, 1, .vFlip = TRUE),
    ANIMCMD_END,
 };

static const union AnimCmd sSpriteAnim_LeftArrow[] =
{
    ANIMCMD_FRAME(16, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_RightArrow[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_VerticalScrollArrow[] =
{
    sSpriteAnim_UpArrow,
    sSpriteAnim_DownArrow,
};

static const union AnimCmd * const sSpriteAnimTable_HorizontalScrollArrow[] =
{
    sSpriteAnim_LeftArrow,
    sSpriteAnim_RightArrow,
};

static const struct SpriteTemplate sHorizontalScrollArrowSpriteTemplate =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_HorizontalScrollArrow,
    .anims = sSpriteAnimTable_HorizontalScrollArrow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_HorizontalScrollArrow
};

static const struct SpriteTemplate sVerticalScrollArrowSpriteTemplate =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_VerticalScrollArrow,
    .anims = sSpriteAnimTable_VerticalScrollArrow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_VerticalScrollArrow
};

// Organized by seed starting position, i.e. seed 0 battles seed 8 first
static const u8 sTourneyTreeTrainerIds[DOME_TOURNAMENT_TRAINERS_COUNT] = {0, 8, 12, 4, 7, 15, 11, 3, 2, 10, 14, 6, 5, 13, 9, 1};

static void (* const sBattleDomeFunctions[])(void) =
{
    [BATTLE_DOME_FUNC_INIT]                     = InitDomeChallenge,
    [BATTLE_DOME_FUNC_GET_DATA]                 = GetDomeData,
    [BATTLE_DOME_FUNC_SET_DATA]                 = SetDomeData,
    [BATTLE_DOME_FUNC_GET_ROUND_TEXT]           = BufferDomeRoundText,
    [BATTLE_DOME_FUNC_GET_OPPONENT_NAME]        = BufferDomeOpponentName,
    [BATTLE_DOME_FUNC_INIT_OPPONENT_PARTY]      = InitDomeOpponentParty,
    [BATTLE_DOME_FUNC_SHOW_OPPONENT_INFO]       = ShowDomeOpponentInfo,
    [BATTLE_DOME_FUNC_SHOW_TOURNEY_TREE]        = ShowDomeTourneyTree,
    [BATTLE_DOME_FUNC_SHOW_PREV_TOURNEY_TREE]   = ShowPreviousDomeTourneyTree,
    [BATTLE_DOME_FUNC_SET_OPPONENT_ID]          = SetDomeOpponentId,
    [BATTLE_DOME_FUNC_SET_OPPONENT_GFX]         = SetDomeOpponentGraphicsId,
    [BATTLE_DOME_FUNC_SHOW_STATIC_TOURNEY_TREE] = ShowNonInteractiveDomeTourneyTree,
    [BATTLE_DOME_FUNC_RESOLVE_WINNERS]          = ResolveDomeRoundWinners,
    [BATTLE_DOME_FUNC_SAVE]                     = SaveDomeChallenge,
    [BATTLE_DOME_FUNC_INCREMENT_STREAK]         = IncrementDomeStreaks,
    [BATTLE_DOME_FUNC_SET_TRAINERS]             = SetFacilityTrainerAndMonPtrs,
    [BATTLE_DOME_FUNC_RESET_SKETCH]             = ResetSketchedMoves,
    [BATTLE_DOME_FUNC_RESTORE_HELD_ITEMS]       = RestoreDomePlayerPartyHeldItems,
    [BATTLE_DOME_FUNC_REDUCE_PARTY]             = ReduceDomePlayerPartyToSelectedMons,
    [BATTLE_DOME_FUNC_COMPARE_SEEDS]            = GetPlayerSeededBeforeOpponent,
    [BATTLE_DOME_FUNC_GET_WINNER_NAME]          = BufferLastDomeWinnerName,
    [BATTLE_DOME_FUNC_INIT_RESULTS_TREE]        = InitRandomTourneyTreeResults,
    [BATTLE_DOME_FUNC_INIT_TRAINERS]            = InitDomeTrainers,
};

static const u32 sWinStreakFlags[][2] =
{
    {STREAK_DOME_SINGLES_50, STREAK_DOME_SINGLES_OPEN},
    {STREAK_DOME_DOUBLES_50, STREAK_DOME_DOUBLES_OPEN},
};

static const u32 sWinStreakMasks[][2] =
{
    {~(STREAK_DOME_SINGLES_50), ~(STREAK_DOME_SINGLES_OPEN)},
    {~(STREAK_DOME_DOUBLES_50), ~(STREAK_DOME_DOUBLES_OPEN)},
};

// TODO: The below two arrays probably need better names. The one below for example is only true of sIdToOpponentId[i][0]
static const u8 sIdToOpponentId[DOME_TOURNAMENT_TRAINERS_COUNT][DOME_ROUNDS_COUNT] =
{
    [0]  = { 8,  0,  4,  8},
    [1]  = { 9, 12,  8,  0},
    [2]  = {10,  8, 12,  0},
    [3]  = {11,  4,  0,  8},
    [4]  = {12,  0,  4,  8},
    [5]  = {13, 12,  8,  0},
    [6]  = {14,  8, 12,  0},
    [7]  = {15,  4,  0,  8},
    [8]  = { 0,  0,  4,  8},
    [9]  = { 1, 12,  8,  0},
    [10] = { 2,  8, 12,  0},
    [11] = { 3,  4,  0,  8},
    [12] = { 4,  0,  4,  8},
    [13] = { 5, 12,  8,  0},
    [14] = { 6,  8, 12,  0},
    [15] = { 7,  4,  0,  8},
};

// sTourneyTreeTrainerIds with every other pair swapped
static const u8 sTourneyTreeTrainerOpponentIds[DOME_TOURNAMENT_TRAINERS_COUNT] = { 0, 8, 4, 12, 7, 15, 3, 11, 2, 10, 6, 14, 5, 13, 1, 9 };

// The match number - 1 that a given tournament trainer will participate in for a given round
static const u8 sIdToMatchNumber[DOME_TOURNAMENT_TRAINERS_COUNT][DOME_ROUNDS_COUNT] =
{
    { 0,  8, 12, 14},
    { 0,  8, 12, 14},
    { 1,  8, 12, 14},
    { 1,  8, 12, 14},
    { 2,  9, 12, 14},
    { 2,  9, 12, 14},
    { 3,  9, 12, 14},
    { 3,  9, 12, 14},
    { 4, 10, 13, 14},
    { 4, 10, 13, 14},
    { 5, 10, 13, 14},
    { 5, 10, 13, 14},
    { 6, 11, 13, 14},
    { 6, 11, 13, 14},
    { 7, 11, 13, 14},
    { 7, 11, 13, 14},
};

static const u8 sLastMatchCardNum[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = 23,
    [DOME_ROUND2]    = 27,
    [DOME_SEMIFINAL] = 29,
    [DOME_FINAL]     = 30
};

static const u8 sTrainerAndRoundToLastMatchCardNum[DOME_TOURNAMENT_TRAINERS_COUNT / 2][DOME_ROUNDS_COUNT] =
{
    {16, 24, 28, 30},
    {17, 24, 28, 30},
    {18, 25, 28, 30},
    {19, 25, 28, 30},
    {20, 26, 29, 30},
    {21, 26, 29, 30},
    {22, 27, 29, 30},
    {23, 27, 29, 30},
};

static const u8 sTournamentIdToPairedTrainerIds[DOME_TOURNAMENT_TRAINERS_COUNT] = {0, 15, 8, 7, 3, 12, 11, 4, 1, 14, 9, 6, 2, 13, 10, 5};

static const u8 *const sBattleDomeMatchNumberTexts[DOME_TOURNAMENT_MATCHES_COUNT] =
{
    BattleDome_Text_Round1Match1,
    BattleDome_Text_Round1Match2,
    BattleDome_Text_Round1Match3,
    BattleDome_Text_Round1Match4,
    BattleDome_Text_Round1Match5,
    BattleDome_Text_Round1Match6,
    BattleDome_Text_Round1Match7,
    BattleDome_Text_Round1Match8,
    BattleDome_Text_Round2Match1,
    BattleDome_Text_Round2Match2,
    BattleDome_Text_Round2Match3,
    BattleDome_Text_Round2Match4,
    BattleDome_Text_SemifinalMatch1,
    BattleDome_Text_SemifinalMatch2,
    BattleDome_Text_FinalMatch,
};

static const u8 *const sBattleDomeWinTexts[] =
{
    [DOME_TEXT_NO_WINNER_YET]    = BattleDome_Text_LetTheBattleBegin,
    [DOME_TEXT_WON_USING_MOVE]   = BattleDome_Text_TrainerWonUsingMove,
    [DOME_TEXT_CHAMP_USING_MOVE] = BattleDome_Text_TrainerBecameChamp,
    [DOME_TEXT_WON_ON_FORFEIT]   = BattleDome_Text_TrainerWonByDefault,
    [DOME_TEXT_CHAMP_ON_FORFEIT] = BattleDome_Text_TrainerWonOutrightByDefault,
    [DOME_TEXT_WON_NO_MOVES]     = BattleDome_Text_TrainerWonNoMoves,
    [DOME_TEXT_CHAMP_NO_MOVES]   = BattleDome_Text_TrainerWonOutrightNoMoves,
};

static const u8 sLeftTrainerMonX[FRONTIER_PARTY_SIZE]  = { 96,  96,  96};
static const u8 sLeftTrainerMonY[FRONTIER_PARTY_SIZE]  = { 56,  80, 104};
static const u8 sRightTrainerMonX[FRONTIER_PARTY_SIZE] = {144, 144, 144};
static const u8 sRightTrainerMonY[FRONTIER_PARTY_SIZE] = { 56,  80, 104};

// Duplicate of sTourneyTreeTrainerIds
static const u8 sTourneyTreeTrainerIds2[DOME_TOURNAMENT_TRAINERS_COUNT] = {0, 8, 12, 4, 7, 15, 11, 3, 2, 10, 14, 6, 5, 13, 9, 1};

// The number of possible trainers that could be competing in a given match
#define NUM_POSSIBLE_MATCH_TRAINERS(round) (DOME_TOURNAMENT_TRAINERS_COUNT / (1 << (DOME_ROUNDS_COUNT - round - 1)))

// The range of tournament trainers to check as possible participants in a given match
// Given by the offset in sCompetitorRangeByMatch[][0], the number of trainers in sCompetitorRangeByMatch[][1], and the round
static const u8 sCompetitorRangeByMatch[DOME_TOURNAMENT_MATCHES_COUNT][3] =
{
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 0,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 1,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 2,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 3,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 4,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 5,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 6,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1) * 7,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND1),    DOME_ROUND1},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2) * 0,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2),    DOME_ROUND2},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2) * 1,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2),    DOME_ROUND2},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2) * 2,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2),    DOME_ROUND2},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2) * 3,    NUM_POSSIBLE_MATCH_TRAINERS(DOME_ROUND2),    DOME_ROUND2},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_SEMIFINAL) * 0, NUM_POSSIBLE_MATCH_TRAINERS(DOME_SEMIFINAL), DOME_SEMIFINAL},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_SEMIFINAL) * 1, NUM_POSSIBLE_MATCH_TRAINERS(DOME_SEMIFINAL), DOME_SEMIFINAL},
    { NUM_POSSIBLE_MATCH_TRAINERS(DOME_FINAL) * 0,     NUM_POSSIBLE_MATCH_TRAINERS(DOME_FINAL),     DOME_FINAL},
};

#define NAME_ROW_HEIGHT 16

// 1st value is the windowId, 2nd value is the y coord
static const u8 sTrainerNamePositions[DOME_TOURNAMENT_TRAINERS_COUNT][2] =
{
    { TOURNEYWIN_NAMES_LEFT,  0 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 7 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 0 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  7 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  3 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 4 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 3 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  4 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  1 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 6 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 1 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  6 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  2 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 5 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_RIGHT, 2 * NAME_ROW_HEIGHT},
    { TOURNEYWIN_NAMES_LEFT,  5 * NAME_ROW_HEIGHT},
};

// Coords for the pokeballs on the tourney tree that act as buttons to view trainer/match info
static const u8 sTourneyTreePokeballCoords[DOME_TOURNAMENT_TRAINERS_COUNT + DOME_TOURNAMENT_MATCHES_COUNT][2] =
{
    { 68,  33}, // Left side trainers
    { 68,  49},
    { 68,  65},
    { 68,  81},
    { 68,  97},
    { 68, 113},
    { 68, 129},
    { 68, 145},
    {172,  33}, // Right side trainers
    {172,  49},
    {172,  65},
    {172,  81},
    {172,  97},
    {172, 113},
    {172, 129},
    {172, 145},
    { 87,  41}, // Left side Round 1 matches
    { 87,  73},
    { 87, 105},
    { 87, 137},
    {153,  41}, // Right side Round 1 matches
    {153,  73},
    {153, 105},
    {153, 137},
    { 95,  57}, // Left side Round 2 matches
    { 95, 121},
    {145,  57}, // Right side Round 2 matches
    {145, 121},
    {103,  89}, // Left side semifinal match
    {137,  89}, // Right side semifinal match
    {120,  89}, // Final match
};

// Tile values from tourney_tree.png for the highlighted lines of the tourney tree.
// These tiles will be used to replace the existing, unhighlighted line tiles on the tourney tree tilemap.
#define LINE_PAL           (6 << 12)
#define LINE_H             (LINE_PAL | 0x21) // Horizontal
#define LINE_CORNER_R      (LINE_PAL | 0x23) // Horizontal into a right-side vertical
#define LINE_CORNER_L      (LINE_PAL | 0x25) // Horizontal into a left-side vertical
#define LINE_V_R           (LINE_PAL | 0x27) // Right-side vertical
#define LINE_V_L           (LINE_PAL | 0x29) // Left-side vertical
#define LINE_H_BOTTOM      (LINE_PAL | 0x2B) // Horizontal on the bottom of the tree
#define LINE_H_LOGO1       (LINE_PAL | 0x2C) // Horizontal, logo behind
#define LINE_H_LOGO2       (LINE_PAL | 0x2D) // Horizontal, logo behind
#define LINE_H_LOGO3       (LINE_PAL | 0x2E) // Horizontal, logo behind
#define LINE_H_LOGO4       (LINE_PAL | 0x2F) // Horizontal, logo behind
#define LINE_V_R_LOGO1     (LINE_PAL | 0x30) // Right-side vertical, logo behind
#define LINE_V_R_LOGO2     (LINE_PAL | 0x31) // Right-side vertical, logo behind
#define LINE_V_R_LOGO3     (LINE_PAL | 0x32) // Right-side vertical, logo behind
#define LINE_V_R_LOGO4     (LINE_PAL | 0x33) // Right-side vertical, logo behind
#define LINE_V_L_LOGO1     (LINE_PAL | 0x35) // Left-side vertical, logo behind
#define LINE_V_L_LOGO2     (LINE_PAL | 0x36) // Left-side vertical, logo behind
#define LINE_V_L_LOGO3     (LINE_PAL | 0x37) // Left-side vertical, logo behind
#define LINE_V_L_LOGO4     (LINE_PAL | 0x38) // Left-side vertical, logo behind
#define LINE_V_R_HALF_LOGO (LINE_PAL | 0x3B) // Right-side vertical, half lit from the top, logo behind
#define LINE_V_L_HALF_LOGO (LINE_PAL | 0x3C) // Left-side vertical, half lit from the top, logo behind
#define LINE_CORNER_R_HALF (LINE_PAL | 0x43) // Lit horizontal, unlit right-side vertical
#define LINE_CORNER_L_HALF (LINE_PAL | 0x45) // Lit horizontal, unlit left-side vertical
#define LINE_V_R_HALF      (LINE_PAL | 0x47) // Right-side vertical, half lit from the top
#define LINE_V_L_HALF      (LINE_PAL | 0x49) // Left-side vertical, half lit from the top

// Each of these line sections define the position of the advancement line on the tourney tree for the victor of that round
// The trainers here are numbered by tourney ID (rank/seed) and ordered according to where they start on the tourney tree
#define LINESECTION_ROUND1_TRAINER1(lastTile) \
    {.tile = LINE_H,        .y =  4, .x =  9}, \
    {.tile = LINE_CORNER_R, .y =  4, .x = 10}, \
    {.tile = LINE_V_R_HALF, .y =  5, .x = 10}, \
    {.tile = lastTile,      .y =  5, .x = 11},

#define LINESECTION_ROUND1_TRAINER9(lastTile) \
    {.tile = LINE_H,   .y =  6, .x =  9}, \
    {.tile = LINE_H,   .y =  6, .x = 10}, \
    {.tile = LINE_V_R, .y =  5, .x = 10}, \
    {.tile = lastTile, .y =  5, .x = 11},

#define LINESECTION_ROUND1_TRAINER13(lastTile) \
    {.tile = LINE_H,        .y =  8, .x =  9}, \
    {.tile = LINE_CORNER_R, .y =  8, .x = 10}, \
    {.tile = LINE_V_R_HALF, .y =  9, .x = 10}, \
    {.tile = lastTile,      .y =  9, .x = 11},

#define LINESECTION_ROUND1_TRAINER5(lastTile) \
    {.tile = LINE_H,   .y = 10, .x =  9}, \
    {.tile = LINE_H,   .y = 10, .x = 10}, \
    {.tile = LINE_V_R, .y =  9, .x = 10}, \
    {.tile = lastTile, .y =  9, .x = 11},

#define LINESECTION_ROUND1_TRAINER8(lastTile) \
    {.tile = LINE_H,        .y = 12, .x =  9}, \
    {.tile = LINE_CORNER_R, .y = 12, .x = 10}, \
    {.tile = LINE_V_R_HALF, .y = 13, .x = 10}, \
    {.tile = lastTile,      .y = 13, .x = 11},

#define LINESECTION_ROUND1_TRAINER16(lastTile) \
    {.tile = LINE_H,   .y = 14, .x =  9}, \
    {.tile = LINE_H,   .y = 14, .x = 10}, \
    {.tile = LINE_V_R, .y = 13, .x = 10}, \
    {.tile = lastTile, .y = 13, .x = 11},

#define LINESECTION_ROUND1_TRAINER12(lastTile) \
    {.tile = LINE_H,        .y = 16, .x =  9}, \
    {.tile = LINE_CORNER_R, .y = 16, .x = 10}, \
    {.tile = LINE_V_R_HALF, .y = 17, .x = 10}, \
    {.tile = lastTile,      .y = 17, .x = 11},

#define LINESECTION_ROUND1_TRAINER4(lastTile) \
    {.tile = LINE_H_BOTTOM, .y = 18, .x =  9}, \
    {.tile = LINE_H_BOTTOM, .y = 18, .x = 10}, \
    {.tile = LINE_V_R,      .y = 17, .x = 10}, \
    {.tile = lastTile,      .y = 17, .x = 11},

#define LINESECTION_ROUND1_TRAINER3(lastTile) \
    {.tile = LINE_H,        .y =  4, .x = 20}, \
    {.tile = LINE_CORNER_L, .y =  4, .x = 19}, \
    {.tile = LINE_V_L_HALF, .y =  5, .x = 19}, \
    {.tile = lastTile,      .y =  5, .x = 18},

#define LINESECTION_ROUND1_TRAINER11(lastTile) \
    {.tile = LINE_H,   .y =  6, .x = 20}, \
    {.tile = LINE_H,   .y =  6, .x = 19}, \
    {.tile = LINE_V_L, .y =  5, .x = 19}, \
    {.tile = lastTile, .y =  5, .x = 18},

#define LINESECTION_ROUND1_TRAINER15(lastTile) \
    {.tile = LINE_H,        .y =  8, .x = 20}, \
    {.tile = LINE_CORNER_L, .y =  8, .x = 19}, \
    {.tile = LINE_V_L_HALF, .y =  9, .x = 19}, \
    {.tile = lastTile,      .y =  9, .x = 18},

#define LINESECTION_ROUND1_TRAINER7(lastTile) \
    {.tile = LINE_H,   .y = 10, .x = 20}, \
    {.tile = LINE_H,   .y = 10, .x = 19}, \
    {.tile = LINE_V_L, .y =  9, .x = 19}, \
    {.tile = lastTile, .y =  9, .x = 18},

#define LINESECTION_ROUND1_TRAINER6(lastTile) \
    {.tile = LINE_H,        .y = 12, .x = 20}, \
    {.tile = LINE_CORNER_L, .y = 12, .x = 19}, \
    {.tile = LINE_V_L_HALF, .y = 13, .x = 19}, \
    {.tile = lastTile,      .y = 13, .x = 18},

#define LINESECTION_ROUND1_TRAINER14(lastTile) \
    {.tile = LINE_H,   .y = 14, .x = 20}, \
    {.tile = LINE_H,   .y = 14, .x = 19}, \
    {.tile = LINE_V_L, .y = 13, .x = 19}, \
    {.tile = lastTile, .y = 13, .x = 18},

#define LINESECTION_ROUND1_TRAINER10(lastTile) \
    {.tile = LINE_H,        .y = 16, .x = 20}, \
    {.tile = LINE_CORNER_L, .y = 16, .x = 19}, \
    {.tile = LINE_V_L_HALF, .y = 17, .x = 19}, \
    {.tile = lastTile,      .y = 17, .x = 18},

#define LINESECTION_ROUND1_TRAINER2(lastTile) \
    {.tile = LINE_H_BOTTOM, .y = 18, .x = 20}, \
    {.tile = LINE_H_BOTTOM, .y = 18, .x = 19}, \
    {.tile = LINE_V_L,      .y = 17, .x = 19}, \
    {.tile = lastTile,      .y = 17, .x = 18},

#define LINESECTION_ROUND2_MATCH1(lastTile) \
    {.tile = LINE_V_R,      .y =  6, .x = 11}, \
    {.tile = LINE_V_R_HALF, .y =  7, .x = 11}, \
    {.tile = lastTile,      .y =  7, .x = 12},

#define LINESECTION_ROUND2_MATCH2(lastTile) \
    {.tile = LINE_V_R, .y =  8, .x = 11}, \
    {.tile = LINE_V_R, .y =  7, .x = 11}, \
    {.tile = lastTile, .y =  7, .x = 12},

#define LINESECTION_ROUND2_MATCH3(lastTile) \
    {.tile = LINE_V_R,      .y = 14, .x = 11}, \
    {.tile = LINE_V_R_HALF, .y = 15, .x = 11}, \
    {.tile = lastTile,      .y = 15, .x = 12},

#define LINESECTION_ROUND2_MATCH4(lastTile) \
    {.tile = LINE_V_R, .y = 16, .x = 11}, \
    {.tile = LINE_V_R, .y = 15, .x = 11}, \
    {.tile = lastTile, .y = 15, .x = 12},

#define LINESECTION_ROUND2_MATCH5(lastTile) \
    {.tile = LINE_V_L,      .y =  6, .x = 18}, \
    {.tile = LINE_V_L_HALF, .y =  7, .x = 18}, \
    {.tile = lastTile,      .y =  7, .x = 17},

#define LINESECTION_ROUND2_MATCH6(lastTile) \
    {.tile = LINE_V_L, .y =  8, .x = 18}, \
    {.tile = LINE_V_L, .y =  7, .x = 18}, \
    {.tile = lastTile, .y =  7, .x = 17},

#define LINESECTION_ROUND2_MATCH7(lastTile) \
    {.tile = LINE_V_L,      .y = 14, .x = 18}, \
    {.tile = LINE_V_L_HALF, .y = 15, .x = 18}, \
    {.tile = lastTile,      .y = 15, .x = 17},

#define LINESECTION_ROUND2_MATCH8(lastTile) \
    {.tile = LINE_V_L, .y = 16, .x = 18}, \
    {.tile = LINE_V_L, .y = 15, .x = 18}, \
    {.tile = lastTile, .y = 15, .x = 17},

#define LINESECTION_SEMIFINAL_TOP_LEFT \
    {.tile = LINE_V_R,           .y =  8, .x = 12}, \
    {.tile = LINE_V_R,           .y =  9, .x = 12}, \
    {.tile = LINE_V_R,           .y = 10, .x = 12}, \
    {.tile = LINE_V_R_HALF_LOGO, .y = 11, .x = 12},

#define LINESECTION_SEMIFINAL_BOTTOM_LEFT \
    {.tile = LINE_V_R_LOGO4, .y = 14, .x = 12}, \
    {.tile = LINE_V_R_LOGO3, .y = 13, .x = 12}, \
    {.tile = LINE_V_R_LOGO2, .y = 12, .x = 12}, \
    {.tile = LINE_V_R_LOGO1, .y = 11, .x = 12},

#define LINESECTION_SEMIFINAL_TOP_RIGHT \
    {.tile = LINE_V_L,           .y =  8, .x = 17}, \
    {.tile = LINE_V_L,           .y =  9, .x = 17}, \
    {.tile = LINE_V_L,           .y = 10, .x = 17}, \
    {.tile = LINE_V_L_HALF_LOGO, .y = 11, .x = 17},

#define LINESECTION_SEMIFINAL_BOTTOM_RIGHT \
    {.tile = LINE_V_L_LOGO4, .y = 14, .x = 17}, \
    {.tile = LINE_V_L_LOGO3, .y = 13, .x = 17}, \
    {.tile = LINE_V_L_LOGO2, .y = 12, .x = 17}, \
    {.tile = LINE_V_L_LOGO1, .y = 11, .x = 17},

#define LINESECTION_FINAL_LEFT \
    {.tile = LINE_H_LOGO1, .y = 11, .x = 13}, \
    {.tile = LINE_H_LOGO2, .y = 11, .x = 14},

#define LINESECTION_FINAL_RIGHT \
    {.tile = LINE_H_LOGO4, .y = 11, .x = 16}, \
    {.tile = LINE_H_LOGO3, .y = 11, .x = 15},


static const struct TourneyTreeLineSection sLineSectionTrainer1Round1[] =
{
    LINESECTION_ROUND1_TRAINER1(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer1Round2[] =
{
    LINESECTION_ROUND1_TRAINER1(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer1Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER1(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer1Final[] =
{
    LINESECTION_ROUND1_TRAINER1(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer9Round1[] =
{
    LINESECTION_ROUND1_TRAINER9(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer9Round2[] =
{
    LINESECTION_ROUND1_TRAINER9(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer9Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER9(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer9Final[] =
{
    LINESECTION_ROUND1_TRAINER9(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH1(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer13Round1[] =
{
    LINESECTION_ROUND1_TRAINER13(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer13Round2[] =
{
    LINESECTION_ROUND1_TRAINER13(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer13Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER13(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer13Final[] =
{
    LINESECTION_ROUND1_TRAINER13(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer5Round1[] =
{
    LINESECTION_ROUND1_TRAINER5(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer5Round2[] =
{
    LINESECTION_ROUND1_TRAINER5(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer5Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER5(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer5Final[] =
{
    LINESECTION_ROUND1_TRAINER5(LINE_H)
    LINESECTION_ROUND2_MATCH2(LINE_CORNER_R)
    LINESECTION_SEMIFINAL_TOP_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer8Round1[] =
{
    LINESECTION_ROUND1_TRAINER8(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer8Round2[] =
{
    LINESECTION_ROUND1_TRAINER8(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer8Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER8(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer8Final[] =
{
    LINESECTION_ROUND1_TRAINER8(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer16Round1[] =
{
    LINESECTION_ROUND1_TRAINER16(LINE_CORNER_R_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer16Round2[] =
{
    LINESECTION_ROUND1_TRAINER16(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer16Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER16(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer16Final[] =
{
    LINESECTION_ROUND1_TRAINER16(LINE_CORNER_R)
    LINESECTION_ROUND2_MATCH3(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer12Round1[] =
{
    LINESECTION_ROUND1_TRAINER12(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer12Round2[] =
{
    LINESECTION_ROUND1_TRAINER12(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer12Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER12(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer12Final[] =
{
    LINESECTION_ROUND1_TRAINER12(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer4Round1[] =
{
    LINESECTION_ROUND1_TRAINER4(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer4Round2[] =
{
    LINESECTION_ROUND1_TRAINER4(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer4Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER4(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer4Final[] =
{
    LINESECTION_ROUND1_TRAINER4(LINE_H)
    LINESECTION_ROUND2_MATCH4(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_LEFT
    LINESECTION_FINAL_LEFT
};

static const struct TourneyTreeLineSection sLineSectionTrainer3Round1[] =
{
    LINESECTION_ROUND1_TRAINER3(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer3Round2[] =
{
    LINESECTION_ROUND1_TRAINER3(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer3Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER3(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer3Final[] =
{
    LINESECTION_ROUND1_TRAINER3(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer11Round1[] =
{
    LINESECTION_ROUND1_TRAINER11(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer11Round2[] =
{
    LINESECTION_ROUND1_TRAINER11(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer11Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER11(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer11Final[] =
{
    LINESECTION_ROUND1_TRAINER11(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH5(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer15Round1[] =
{
    LINESECTION_ROUND1_TRAINER15(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer15Round2[] =
{
    LINESECTION_ROUND1_TRAINER15(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer15Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER15(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer15Final[] =
{
    LINESECTION_ROUND1_TRAINER15(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer7Round1[] =
{
    LINESECTION_ROUND1_TRAINER7(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer7Round2[] =
{
    LINESECTION_ROUND1_TRAINER7(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer7Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER7(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer7Final[] =
{
    LINESECTION_ROUND1_TRAINER7(LINE_H)
    LINESECTION_ROUND2_MATCH6(LINE_CORNER_L)
    LINESECTION_SEMIFINAL_TOP_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer6Round1[] =
{
    LINESECTION_ROUND1_TRAINER6(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer6Round2[] =
{
    LINESECTION_ROUND1_TRAINER6(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer6Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER6(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer6Final[] =
{
    LINESECTION_ROUND1_TRAINER6(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer14Round1[] =
{
    LINESECTION_ROUND1_TRAINER14(LINE_CORNER_L_HALF)
};

static const struct TourneyTreeLineSection sLineSectionTrainer14Round2[] =
{
    LINESECTION_ROUND1_TRAINER14(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer14Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER14(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer14Final[] =
{
    LINESECTION_ROUND1_TRAINER14(LINE_CORNER_L)
    LINESECTION_ROUND2_MATCH7(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer10Round1[] =
{
    LINESECTION_ROUND1_TRAINER10(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer10Round2[] =
{
    LINESECTION_ROUND1_TRAINER10(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer10Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER10(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer10Final[] =
{
    LINESECTION_ROUND1_TRAINER10(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer2Round1[] =
{
    LINESECTION_ROUND1_TRAINER2(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer2Round2[] =
{
    LINESECTION_ROUND1_TRAINER2(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
};

static const struct TourneyTreeLineSection sLineSectionTrainer2Semifinal[] =
{
    LINESECTION_ROUND1_TRAINER2(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
};

static const struct TourneyTreeLineSection sLineSectionTrainer2Final[] =
{
    LINESECTION_ROUND1_TRAINER2(LINE_H)
    LINESECTION_ROUND2_MATCH8(LINE_H)
    LINESECTION_SEMIFINAL_BOTTOM_RIGHT
    LINESECTION_FINAL_RIGHT
};

static const struct TourneyTreeLineSection *const sTourneyTreeLineSections[DOME_TOURNAMENT_TRAINERS_COUNT][DOME_ROUNDS_COUNT] =
{
    {sLineSectionTrainer1Round1,  sLineSectionTrainer1Round2,  sLineSectionTrainer1Semifinal,  sLineSectionTrainer1Final},
    {sLineSectionTrainer2Round1,  sLineSectionTrainer2Round2,  sLineSectionTrainer2Semifinal,  sLineSectionTrainer2Final},
    {sLineSectionTrainer3Round1,  sLineSectionTrainer3Round2,  sLineSectionTrainer3Semifinal,  sLineSectionTrainer3Final},
    {sLineSectionTrainer4Round1,  sLineSectionTrainer4Round2,  sLineSectionTrainer4Semifinal,  sLineSectionTrainer4Final},
    {sLineSectionTrainer5Round1,  sLineSectionTrainer5Round2,  sLineSectionTrainer5Semifinal,  sLineSectionTrainer5Final},
    {sLineSectionTrainer6Round1,  sLineSectionTrainer6Round2,  sLineSectionTrainer6Semifinal,  sLineSectionTrainer6Final},
    {sLineSectionTrainer7Round1,  sLineSectionTrainer7Round2,  sLineSectionTrainer7Semifinal,  sLineSectionTrainer7Final},
    {sLineSectionTrainer8Round1,  sLineSectionTrainer8Round2,  sLineSectionTrainer8Semifinal,  sLineSectionTrainer8Final},
    {sLineSectionTrainer9Round1,  sLineSectionTrainer9Round2,  sLineSectionTrainer9Semifinal,  sLineSectionTrainer9Final},
    {sLineSectionTrainer10Round1, sLineSectionTrainer10Round2, sLineSectionTrainer10Semifinal, sLineSectionTrainer10Final},
    {sLineSectionTrainer11Round1, sLineSectionTrainer11Round2, sLineSectionTrainer11Semifinal, sLineSectionTrainer11Final},
    {sLineSectionTrainer12Round1, sLineSectionTrainer12Round2, sLineSectionTrainer12Semifinal, sLineSectionTrainer12Final},
    {sLineSectionTrainer13Round1, sLineSectionTrainer13Round2, sLineSectionTrainer13Semifinal, sLineSectionTrainer13Final},
    {sLineSectionTrainer14Round1, sLineSectionTrainer14Round2, sLineSectionTrainer14Semifinal, sLineSectionTrainer14Final},
    {sLineSectionTrainer15Round1, sLineSectionTrainer15Round2, sLineSectionTrainer15Semifinal, sLineSectionTrainer15Final},
    {sLineSectionTrainer16Round1, sLineSectionTrainer16Round2, sLineSectionTrainer16Semifinal, sLineSectionTrainer16Final},
};

static const u8 sTourneyTreeLineSectionArrayCounts[DOME_TOURNAMENT_TRAINERS_COUNT][DOME_ROUNDS_COUNT] =
{
    {ARRAY_COUNT(sLineSectionTrainer1Round1),  ARRAY_COUNT(sLineSectionTrainer1Round2),  ARRAY_COUNT(sLineSectionTrainer1Semifinal),  ARRAY_COUNT(sLineSectionTrainer1Final)},
    {ARRAY_COUNT(sLineSectionTrainer2Round1),  ARRAY_COUNT(sLineSectionTrainer2Round2),  ARRAY_COUNT(sLineSectionTrainer2Semifinal),  ARRAY_COUNT(sLineSectionTrainer2Final)},
    {ARRAY_COUNT(sLineSectionTrainer3Round1),  ARRAY_COUNT(sLineSectionTrainer3Round2),  ARRAY_COUNT(sLineSectionTrainer3Semifinal),  ARRAY_COUNT(sLineSectionTrainer3Final)},
    {ARRAY_COUNT(sLineSectionTrainer4Round1),  ARRAY_COUNT(sLineSectionTrainer4Round2),  ARRAY_COUNT(sLineSectionTrainer4Semifinal),  ARRAY_COUNT(sLineSectionTrainer4Final)},
    {ARRAY_COUNT(sLineSectionTrainer5Round1),  ARRAY_COUNT(sLineSectionTrainer5Round2),  ARRAY_COUNT(sLineSectionTrainer5Semifinal),  ARRAY_COUNT(sLineSectionTrainer5Final)},
    {ARRAY_COUNT(sLineSectionTrainer6Round1),  ARRAY_COUNT(sLineSectionTrainer6Round2),  ARRAY_COUNT(sLineSectionTrainer6Semifinal),  ARRAY_COUNT(sLineSectionTrainer6Final)},
    {ARRAY_COUNT(sLineSectionTrainer7Round1),  ARRAY_COUNT(sLineSectionTrainer7Round2),  ARRAY_COUNT(sLineSectionTrainer7Semifinal),  ARRAY_COUNT(sLineSectionTrainer7Final)},
    {ARRAY_COUNT(sLineSectionTrainer8Round1),  ARRAY_COUNT(sLineSectionTrainer8Round2),  ARRAY_COUNT(sLineSectionTrainer8Semifinal),  ARRAY_COUNT(sLineSectionTrainer8Final)},
    {ARRAY_COUNT(sLineSectionTrainer9Round1),  ARRAY_COUNT(sLineSectionTrainer9Round2),  ARRAY_COUNT(sLineSectionTrainer9Semifinal),  ARRAY_COUNT(sLineSectionTrainer9Final)},
    {ARRAY_COUNT(sLineSectionTrainer10Round1), ARRAY_COUNT(sLineSectionTrainer10Round2), ARRAY_COUNT(sLineSectionTrainer10Semifinal), ARRAY_COUNT(sLineSectionTrainer10Final)},
    {ARRAY_COUNT(sLineSectionTrainer11Round1), ARRAY_COUNT(sLineSectionTrainer11Round2), ARRAY_COUNT(sLineSectionTrainer11Semifinal), ARRAY_COUNT(sLineSectionTrainer11Final)},
    {ARRAY_COUNT(sLineSectionTrainer12Round1), ARRAY_COUNT(sLineSectionTrainer12Round2), ARRAY_COUNT(sLineSectionTrainer12Semifinal), ARRAY_COUNT(sLineSectionTrainer12Final)},
    {ARRAY_COUNT(sLineSectionTrainer13Round1), ARRAY_COUNT(sLineSectionTrainer13Round2), ARRAY_COUNT(sLineSectionTrainer13Semifinal), ARRAY_COUNT(sLineSectionTrainer13Final)},
    {ARRAY_COUNT(sLineSectionTrainer14Round1), ARRAY_COUNT(sLineSectionTrainer14Round2), ARRAY_COUNT(sLineSectionTrainer14Semifinal), ARRAY_COUNT(sLineSectionTrainer14Final)},
    {ARRAY_COUNT(sLineSectionTrainer15Round1), ARRAY_COUNT(sLineSectionTrainer15Round2), ARRAY_COUNT(sLineSectionTrainer15Semifinal), ARRAY_COUNT(sLineSectionTrainer15Final)},
    {ARRAY_COUNT(sLineSectionTrainer16Round1), ARRAY_COUNT(sLineSectionTrainer16Round2), ARRAY_COUNT(sLineSectionTrainer16Semifinal), ARRAY_COUNT(sLineSectionTrainer16Final)},
};

void CallBattleDomeFunction(void)
{
    sBattleDomeFunctions[gSpecialVar_0x8004]();
}

static void InitDomeChallenge(void)
{
    u32 lvlMode = gSaveBlockPtr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlockPtr->frontier.challengeStatus = 0;
    gSaveBlockPtr->frontier.curChallengeBattleNum = 0;
    gSaveBlockPtr->frontier.challengePaused = FALSE;
    gSaveBlockPtr->frontier.disableRecordBattle = FALSE;
    if (!(gSaveBlockPtr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]))
        gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlockPtr->location.mapGroup, gSaveBlockPtr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void GetDomeData(void)
{
    u32 lvlMode = gSaveBlockPtr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case DOME_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case DOME_DATA_WIN_STREAK_ACTIVE:
        gSpecialVar_Result = ((gSaveBlockPtr->frontier.winStreakActiveFlags & sWinStreakFlags[battleMode][lvlMode]) != 0);
        break;
    case DOME_DATA_ATTEMPTED_SINGLES_50:
        gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedSingles50;
        break;
    case DOME_DATA_ATTEMPTED_SINGLES_OPEN:
        gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedSinglesOpen;
        break;
    case DOME_DATA_HAS_WON_SINGLES_50:
        gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonSingles50;
        break;
    case DOME_DATA_HAS_WON_SINGLES_OPEN:
        gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonSinglesOpen;
        break;
    case DOME_DATA_ATTEMPTED_CHALLENGE:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedDoublesOpen;
            else
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedDoubles50;
        }
        else
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedSinglesOpen;
            else
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeAttemptedSingles50;
        }
        break;
    case DOME_DATA_HAS_WON_CHALLENGE:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonDoublesOpen;
            else
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonDoubles50;
        }
        else
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonSinglesOpen;
            else
                gSpecialVar_Result = gSaveBlockPtr->frontier.domeHasWonSingles50;
        }
        break;
    case DOME_DATA_SELECTED_MONS:
        ClearSelectedPartyOrder();
        gSelectedOrderFromParty[0] = gSaveBlockPtr->frontier.selectedPartyMons[3];
        gSelectedOrderFromParty[1] = gSaveBlockPtr->frontier.selectedPartyMons[3] >> 8;
        break;
    case DOME_DATA_PREV_TOURNEY_TYPE:
        gSpecialVar_Result = (gSaveBlockPtr->frontier.domeLvlMode * 2) - 3 + gSaveBlockPtr->frontier.domeBattleMode;
        break;
    }
}

static void SetDomeData(void)
{
    u32 lvlMode = gSaveBlockPtr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case DOME_DATA_WIN_STREAK:
        gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case DOME_DATA_WIN_STREAK_ACTIVE:
        if (gSpecialVar_0x8006)
            gSaveBlockPtr->frontier.winStreakActiveFlags |= sWinStreakFlags[battleMode][lvlMode];
        else
            gSaveBlockPtr->frontier.winStreakActiveFlags &= sWinStreakMasks[battleMode][lvlMode];
        break;
    case DOME_DATA_ATTEMPTED_SINGLES_50:
        gSaveBlockPtr->frontier.domeAttemptedSingles50 = gSpecialVar_0x8006;
        break;
    case DOME_DATA_ATTEMPTED_SINGLES_OPEN:
        gSaveBlockPtr->frontier.domeAttemptedSinglesOpen = gSpecialVar_0x8006;
        break;
    case DOME_DATA_HAS_WON_SINGLES_50:
        gSaveBlockPtr->frontier.domeHasWonSingles50 = gSpecialVar_0x8006;
        break;
    case DOME_DATA_HAS_WON_SINGLES_OPEN:
        gSaveBlockPtr->frontier.domeHasWonSinglesOpen = gSpecialVar_0x8006;
        break;
    case DOME_DATA_ATTEMPTED_CHALLENGE:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSaveBlockPtr->frontier.domeAttemptedDoublesOpen = gSpecialVar_0x8006;
            else
                gSaveBlockPtr->frontier.domeAttemptedDoubles50 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSaveBlockPtr->frontier.domeAttemptedSinglesOpen = gSpecialVar_0x8006;
            else
                gSaveBlockPtr->frontier.domeAttemptedSingles50 = gSpecialVar_0x8006;
        }
        break;
    case DOME_DATA_HAS_WON_CHALLENGE:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSaveBlockPtr->frontier.domeHasWonDoublesOpen = gSpecialVar_0x8006;
            else
                gSaveBlockPtr->frontier.domeHasWonDoubles50 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode != FRONTIER_LVL_50)
                gSaveBlockPtr->frontier.domeHasWonSinglesOpen = gSpecialVar_0x8006;
            else
                gSaveBlockPtr->frontier.domeHasWonSingles50 = gSpecialVar_0x8006;
        }
        break;
    case DOME_DATA_SELECTED_MONS:
        gSaveBlockPtr->frontier.selectedPartyMons[3] = T1_READ_16(gSelectedOrderFromParty);
        break;
    }
}

static void InitDomeTrainers(void)
{

}

#define CALC_STAT(base, statIndex)                                                          \
{                                                                                           \
    u8 baseStat = gSpeciesInfo[fmon->species].base;                                         \
    stats[statIndex] = (((2 * baseStat + ivs + evs[statIndex] / 4) * level) / 100) + 5;     \
    stats[statIndex] = (u8) ModifyStatByNature(fmon->nature, stats[statIndex], statIndex);  \
}

static void CalcDomeMonStats(const struct TrainerMon *fmon, int level, u8 ivs, int *stats)
{
    int evs[NUMERO_ESTADISTICAS];
    int i;

    for (i = 0; i < NUMERO_ESTADISTICAS; i++)
    {
        if (fmon->ev != NULL)
            evs[i] = fmon->ev[i];
        else
            evs[i] = 0;
    }

    if (fmon->species == SPECIES_SHEDINJA)
    {
        stats[ESTADISTICA_PS] = 1;
    }
    else
    {
        int n = 2 * gSpeciesInfo[fmon->species].baseHP;
        stats[ESTADISTICA_PS] = (((n + ivs + evs[ESTADISTICA_PS] / 4) * level) / 100) + level + 10;
    }

    CALC_STAT(baseAttack, ESTADISTICA_ATAQUE);
    CALC_STAT(baseDefense, ESTADISTICA_DEFENSA);
    CALC_STAT(baseSpeed, ESTADISTICA_VELOCIDAD);
    CALC_STAT(baseSpAttack, ESTADISTICA_ATAQUE_ESPECIAL);
    CALC_STAT(baseSpDefense, ESTADISTICA_DEFENSA_ESPECIAL);
}

static void SwapDomeTrainers(int id1, int id2, u16 *statsArray)
{
    int i;
    u16 temp;

    SWAP(statsArray[id1], statsArray[id2], temp);
    SWAP(DOME_TRAINERS[id1].trainerId, DOME_TRAINERS[id2].trainerId, temp);

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        SWAP(DOME_MONS[id1][i], DOME_MONS[id2][i], temp);
}

static void BufferDomeRoundText(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlockPtr->frontier.curChallengeBattleNum]);
}

static void BufferDomeOpponentName(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlockPtr->frontier.curChallengeBattleNum]);
    CopyDomeTrainerName(gStringVar2, gTrainerBattleOpponent_A);
}

static void InitDomeOpponentParty(void)
{
    CalculatePlayerPartyCount();
    CreateDomeOpponentMons(TrainerIdToTournamentId(gTrainerBattleOpponent_A));
}

static void CreateDomeOpponentMon(u8 monPartyId, u16 tournamentTrainerId, u8 tournamentMonId, u32 otId)
{
    #ifdef BUGFIX
    u8 fixedIv = GetDomeTrainerMonIvs(DOME_TRAINERS[tournamentTrainerId].trainerId);
    #else
    u8 fixedIv = GetDomeTrainerMonIvs(tournamentTrainerId); // BUG: Using the wrong ID. As a result, all Pokémon have ivs of 3.
    #endif
    u8 level = SetFacilityPtrsGetLevel();

    CreateFacilityMon(&gFacilityTrainerMons[DOME_MONS[tournamentTrainerId][tournamentMonId]],
                      level, fixedIv, otId, 0, &gEnemyParty[monPartyId]);
}

static void CreateDomeOpponentMons(u16 tournamentTrainerId)
{
    u8 monsCount = 0;
    u32 otId = 0;
    int i, selectedMonBits;

    ZeroEnemyPartyMons();
    selectedMonBits = GetDomeTrainerSelectedMons(tournamentTrainerId);
    otId = Random32();

    if (Random() % 10 > 5)
    {
        // Create mon if it was selected, starting from front
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            if (selectedMonBits & 1)
            {
                CreateDomeOpponentMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            selectedMonBits >>= 1;
        }
    }
    else
    {
        // Create mon if it was selected, starting from back
        for (i = FRONTIER_PARTY_SIZE - 1; i >= 0; i--)
        {
            if (selectedMonBits & (1 << (FRONTIER_PARTY_SIZE - 1)))
            {
                CreateDomeOpponentMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            selectedMonBits <<= 1;
        }
    }
}

// Returns a bitmask representing which 2 of the trainer's 3 Pokémon to select.
// The choice is calculated solely depending on the type effectiveness of their
// movesets against the player's Pokémon.
// There is a 50% chance of either a "good" or "bad" selection mode being used.
// In the good mode movesets are preferred which are more effective against the
// player, and in the bad mode the opposite is true. If all 3 Pokémon tie, the
// other mode will be tried. If they tie again, the Pokémon selection is random.
int GetDomeTrainerSelectedMons(u16 tournamentTrainerId)
{
    int selectedMonBits;
    if (Random() & 1)
    {
        selectedMonBits = SelectOpponentMons_Good(tournamentTrainerId, FALSE);
        if (selectedMonBits == 0)
            selectedMonBits = SelectOpponentMons_Bad(tournamentTrainerId, TRUE);
    }
    else
    {
        selectedMonBits = SelectOpponentMons_Bad(tournamentTrainerId, FALSE);
        if (selectedMonBits == 0)
            selectedMonBits = SelectOpponentMons_Good(tournamentTrainerId, TRUE);
    }

    return selectedMonBits;
}

static int SelectOpponentMons_Good(u16 tournamentTrainerId, bool8 allowRandom)
{
    return 0;
}

// Identical to function above, but uses EFFECTIVENESS_MODE_BAD
static int SelectOpponentMons_Bad(u16 tournamentTrainerId, bool8 allowRandom)
{
    return 0;
}

#define TYPE_x0     0
#define TYPE_x0_25  5
#define TYPE_x0_50  10
#define TYPE_x1     20
#define TYPE_x2     40
#define TYPE_x4     80

// NOTE: In CreateDomeOpponentMon a tournament trainer ID (0-15) is passed instead, resulting in all IVs of 3
//       To fix, see CreateDomeOpponentMon
static u8 GetDomeTrainerMonIvs(u16 trainerId)
{
    u8 fixedIv;

    if (trainerId <= FRONTIER_TRAINER_JILL)         // 0 - 99
        fixedIv = 3;
    else if (trainerId <= FRONTIER_TRAINER_CHLOE)   // 100 - 119
        fixedIv = 6;
    else if (trainerId <= FRONTIER_TRAINER_SOFIA)   // 120 - 139
        fixedIv = 9;
    else if (trainerId <= FRONTIER_TRAINER_JAZLYN)  // 140 - 159
        fixedIv = 12;
    else if (trainerId <= FRONTIER_TRAINER_ALISON)  // 160 - 179
        fixedIv = 15;
    else if (trainerId <= FRONTIER_TRAINER_LAMAR)   // 180 - 199
        fixedIv = 18;
    else if (trainerId <= FRONTIER_TRAINER_TESS)    // 200 - 219
        fixedIv = 21;
    else                                            // 220+ (- 299)
        fixedIv = MAX_PER_STAT_IVS;

    return fixedIv;
}

static void SetDomeOpponentId(void)
{
    gTrainerBattleOpponent_A = TrainerIdOfPlayerOpponent();
}

// While not an issue in-game, this will overflow if called after the player's opponent for the current round has been eliminated
static u16 TrainerIdOfPlayerOpponent(void)
{
    return 0;
}

static void SetDomeOpponentGraphicsId(void)
{
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void SaveDomeChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlockPtr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlockPtr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void IncrementDomeStreaks(void)
{
    u8 lvlMode = gSaveBlockPtr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode] < 999)
        gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode]++;
    if (gSaveBlockPtr->frontier.domeTotalChampionships[battleMode][lvlMode] < 999)
        gSaveBlockPtr->frontier.domeTotalChampionships[battleMode][lvlMode]++;

    if (gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode] > gSaveBlockPtr->frontier.domeRecordWinStreaks[battleMode][lvlMode])
        gSaveBlockPtr->frontier.domeRecordWinStreaks[battleMode][lvlMode] = gSaveBlockPtr->frontier.domeWinStreaks[battleMode][lvlMode];
}

// For showing the opponent info card of the upcoming trainer
static void ShowDomeOpponentInfo(void)
{
    u8 taskId = CreateTask(Task_ShowTourneyInfoCard, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tTournamentId = TrainerIdToTournamentId(TrainerIdOfPlayerOpponent());
    gTasks[taskId].tMode = INFOCARD_NEXT_OPPONENT;
    gTasks[taskId].tPrevTaskId = 0;

    SetMainCallback2(CB2_TourneyTree);
}

// For showing the opponent info card or the match info card
static void Task_ShowTourneyInfoCard(u8 taskId)
{
    int i;
    int tournamentId = gTasks[taskId].tTournamentId;
    int mode = gTasks[taskId].tMode;
    int id = gTasks[taskId].tPrevTaskId;

    switch (gTasks[taskId].tState)
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        EnableInterrupts(INTR_FLAG_VBLANK);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags();
        InitBgsFromTemplates(0, sInfoCardBgTemplates, ARRAY_COUNT(sInfoCardBgTemplates));
        InitWindows(sInfoCardWindowTemplates);
        DeactivateAllTextPrinters();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        if (mode == INFOCARD_MATCH)
            gBattle_BG2_X = 0, gBattle_BG2_Y = 0;
        else
            gBattle_BG2_X = 0, gBattle_BG2_Y = DISPLAY_HEIGHT;

        gTasks[taskId].tState++;
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        gTasks[taskId].tState++;
        break;
    case 2:
        DecompressAndLoadBgGfxUsingHeap(2, gDomeTourneyInfoCard_Gfx, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, gDomeTourneyInfoCard_Tilemap, 0x2000, 0, 1);
        DecompressAndLoadBgGfxUsingHeap(3, gDomeTourneyInfoCardBg_Tilemap, 0x800, 0, 1);
        LoadCompressedSpriteSheet(sTourneyTreeButtonsSpriteSheet);
        LoadCompressedPalette(gDomeTourneyTree_Pal, BG_PLTT_OFFSET, BG_PLTT_SIZE);
        LoadCompressedPalette(gDomeTourneyTreeButtons_Pal, OBJ_PLTT_OFFSET, OBJ_PLTT_SIZE);
        LoadCompressedPalette(gBattleWindowTextPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        if (mode == INFOCARD_MATCH)
            LoadCompressedPalette(gDomeTourneyMatchCardBg_Pal, BG_PLTT_ID(5), PLTT_SIZE_4BPP); // Changes the moving info card bg to orange when in match card mode
        CpuFill32(0, gPlttBufferFaded, PLTT_SIZE);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gTasks[taskId].tState++;
        break;
    case 3:
        SetVBlankCallback(VblankCb_TourneyInfoCard);
        sInfoCard = AllocZeroed(sizeof(*sInfoCard));
        for (i = 0; i < NUM_INFOCARD_SPRITES; i++)
            sInfoCard->spriteIds[i] = SPRITE_NONE;
        //LoadMonIconPalettes();
        i = CreateTask(Task_HandleInfoCardInput, 0);
        gTasks[i].data[0] = 0;
        gTasks[i].data[2] = 0;
        gTasks[i].data[3] = mode;
        gTasks[i].data[4] = id;
        if (mode == INFOCARD_MATCH)
        {
            DisplayMatchInfoOnCard(0, tournamentId);
            sInfoCard->pos = 1;
        }
        else
        {
            DisplayTrainerInfoOnCard(0, tournamentId);
        }
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        if (mode != INFOCARD_NEXT_OPPONENT)
        {
            // Scroll up arrow
            id = CreateSprite(&sVerticalScrollArrowSpriteTemplate, 120, 4, 0);
            StartSpriteAnim(&gSprites[id], 0);
            gSprites[id].data[0] = i;

            // Scroll down arrow
            id = CreateSprite(&sVerticalScrollArrowSpriteTemplate, 120, 156, 0);
            StartSpriteAnim(&gSprites[id], 1);
            gSprites[id].data[0] = i;

            // Scroll left arrow
            id = CreateSprite(&sHorizontalScrollArrowSpriteTemplate, 6, 80, 0);
            StartSpriteAnim(&gSprites[id], 0);
            gSprites[id].data[0] = i;
            gSprites[id].data[1] = 0;
            if (mode == INFOCARD_TRAINER)
                gSprites[id].invisible = TRUE;

            // Scroll right arrow
            id = CreateSprite(&sHorizontalScrollArrowSpriteTemplate, 234, 80, 0);
            StartSpriteAnim(&gSprites[id], 1);
            gSprites[id].data[0] = i;
            gSprites[id].data[1] = 1;
        }
        DestroyTask(taskId);
        break;
    }
}

// Note: Card scrolling up means the current card goes down and another one appears from top.
// The same is true for scrolling left.
// That means that the sprite needs to move with the moving card in the opposite scrolling direction.
static void SpriteCB_TrainerIconCardScrollUp(struct Sprite *sprite)
{
    sprite->y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->y >= -32)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->y >= 192)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCB_TrainerIconCardScrollDown(struct Sprite *sprite)
{
    sprite->y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->y <= 192)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->y <= -32)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCB_TrainerIconCardScrollLeft(struct Sprite *sprite)
{
    sprite->x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->x >= -32)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->x >= DISPLAY_WIDTH + 32)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCB_TrainerIconCardScrollRight(struct Sprite *sprite)
{
    sprite->x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->x <= DISPLAY_WIDTH + 32)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->x <= -32)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

#define sMonIconStill data[3]

static void SpriteCB_MonIconDomeInfo(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
}

static void SpriteCB_MonIconCardScrollUp(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->y >= -16)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCB_MonIconDomeInfo;
    }
    else
    {
        if (sprite->y >= 176)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyMonIconSprite(sprite);
        }
    }
}

static void SpriteCB_MonIconCardScrollDown(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->y <= 176)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCB_MonIconDomeInfo;
    }
    else
    {
        if (sprite->y <= -16)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyMonIconSprite(sprite);
        }
    }
}

static void SpriteCB_MonIconCardScrollLeft(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->x >= -16)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCB_MonIconDomeInfo;
    }
    else
    {
        if (sprite->x >= DISPLAY_WIDTH + 16)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyMonIconSprite(sprite);
        }
    }
}

static void SpriteCB_MonIconCardScrollRight(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->x <= DISPLAY_WIDTH + 16)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCB_MonIconDomeInfo;
    }
    else
    {
        if (sprite->x <= -16)
        {
            sInfoCard->spriteIds[sprite->data[2]] = SPRITE_NONE;
            FreeAndDestroyMonIconSprite(sprite);
        }
    }
}

static void SpriteCB_HorizontalScrollArrow(struct Sprite *sprite)
{
    int taskId1 = sprite->data[0];
    int arrId = gTasks[gTasks[taskId1].data[4]].data[1];
    int tournmanetTrainerId = sTourneyTreeTrainerIds[arrId];
    int roundId = gSaveBlockPtr->frontier.curChallengeBattleNum;

    if (gTasks[taskId1].data[3] == 1)
    {
        if (sprite->data[1])
        {
            if ((DOME_TRAINERS[tournmanetTrainerId].isEliminated
                && sInfoCard->pos - 1 < DOME_TRAINERS[tournmanetTrainerId].eliminatedAt))
            {
                sprite->invisible = FALSE;
            }
            else if (!DOME_TRAINERS[tournmanetTrainerId].isEliminated
                     && sInfoCard->pos - 1 < roundId)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
        else
        {
            if (sInfoCard->pos != 0)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
    }
    else
    {
        if (sprite->data[1])
        {
            if (sInfoCard->pos > 1)
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
            else
            {
                sprite->invisible = FALSE;
            }
        }
        else
        {
            if (sInfoCard->pos != 0)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
    }
}

static void SpriteCB_VerticalScrollArrow(struct Sprite *sprite)
{
    int taskId1 = sprite->data[0];

    if (gTasks[taskId1].data[3] == 1)
    {
        if (sInfoCard->pos != 0)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
        }
    }
    else
    {
        if (sInfoCard->pos != 1)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
        }
    }
}

// Task states for Task_HandleInfoCardInput
#define STATE_FADE_IN      0
#define STATE_WAIT_FADE    1
#define STATE_GET_INPUT    2
#define STATE_REACT_INPUT  3
#define STATE_MOVE_UP      4
#define STATE_MOVE_DOWN    5
#define STATE_MOVE_LEFT    6
#define STATE_MOVE_RIGHT   7
#define STATE_CLOSE_CARD   8

#define tUsingAlternateSlot data[2] // CARD_ALTERNATE_SLOT

static void Task_HandleInfoCardInput(u8 taskId)
{
    int i;
    int windowId = 0;
    int mode = gTasks[taskId].data[3];
    int taskId2 = gTasks[taskId].data[4];
    int trainerTourneyId = 0;
    int matchNo = 0;

    switch (gTasks[taskId].tState)
    {
    case STATE_FADE_IN:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
            gTasks[taskId].tState = STATE_WAIT_FADE;
        }
        break;
    case STATE_WAIT_FADE:
        if (!gPaletteFade.active)
            gTasks[taskId].tState = STATE_GET_INPUT;
        break;
    case STATE_GET_INPUT:
        i = Task_GetInfoCardInput(taskId);
        switch (i)
        {
        case INFOCARD_INPUT_AB:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].tState = STATE_CLOSE_CARD;
            break;
        case TRAINERCARD_INPUT_UP ... TRAINERCARD_INPUT_RIGHT:
        case MATCHCARD_INPUT_UP ... MATCHCARD_INPUT_RIGHT:
            gTasks[taskId].data[5] = i;
            if (gTasks[taskId].tUsingAlternateSlot)
                windowId = NUM_INFO_CARD_WINDOWS;
            else
                windowId = 0;

            for (i = windowId; i < windowId + NUM_INFO_CARD_WINDOWS; i++)
            {
                CopyWindowToVram(i, COPYWIN_GFX);
                FillWindowPixelBuffer(i, PIXEL_FILL(0));
            }
            gTasks[taskId].tState = STATE_REACT_INPUT;
            break;
        case INFOCARD_INPUT_NONE:
            break;
        }
        break;
    case STATE_REACT_INPUT:
        i = gTasks[taskId].data[5];
        switch (i)
        {
        case TRAINERCARD_INPUT_UP:
        case MATCHCARD_INPUT_UP:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = DISPLAY_HEIGHT;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = DISPLAY_HEIGHT;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == TRAINERCARD_INPUT_UP)
            {
                if (sInfoCard->pos == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT * 2;
                    trainerTourneyId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_UP, trainerTourneyId);
                }
                else
                {
                    gBattle_BG2_X = DISPLAY_WIDTH + 16;
                    gBattle_BG2_Y = 0;
                    trainerTourneyId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_UP, trainerTourneyId);
                    sInfoCard->pos = 0;
                }
            }
            else // i == MATCHCARD_INPUT_UP
            {
                if (sInfoCard->pos == 0)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    BufferDomeWinString(matchNo, sInfoCard->tournamentIds);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT * 2;
                    trainerTourneyId = sInfoCard->tournamentIds[0];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_UP, trainerTourneyId);
                }
                else if (sInfoCard->pos == 2)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    BufferDomeWinString(matchNo, sInfoCard->tournamentIds);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT * 2;
                    trainerTourneyId = sInfoCard->tournamentIds[1];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_UP, trainerTourneyId);
                }
                else
                {
                    gBattle_BG2_X = DISPLAY_WIDTH + 16;
                    gBattle_BG2_Y = DISPLAY_HEIGHT;
                    matchNo = gTasks[taskId2].data[1] - 16;
                    DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_UP, matchNo);
                }
            }

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollUp;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollUp;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollUp;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollUp;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_UP;
            gTasks[taskId].data[5] = 0;
            break;
        case TRAINERCARD_INPUT_DOWN:
        case MATCHCARD_INPUT_DOWN:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = -DISPLAY_HEIGHT;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = -DISPLAY_HEIGHT;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == TRAINERCARD_INPUT_DOWN)
            {
                if (sInfoCard->pos == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT;
                    trainerTourneyId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_DOWN, trainerTourneyId);
                }
                else
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 0;
                    trainerTourneyId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_DOWN, trainerTourneyId);
                    sInfoCard->pos = 0;
                }
            }
            else // i == MATCHCARD_INPUT_DOWN
            {
                if (sInfoCard->pos == 0)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    BufferDomeWinString(matchNo, sInfoCard->tournamentIds);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT;
                    trainerTourneyId = sInfoCard->tournamentIds[0];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_DOWN, trainerTourneyId);
                }
                else if (sInfoCard->pos == 2)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    BufferDomeWinString(matchNo, sInfoCard->tournamentIds);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = DISPLAY_HEIGHT;
                    trainerTourneyId = sInfoCard->tournamentIds[1];
                    DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_DOWN, trainerTourneyId);
                }
                else
                {
                    gBattle_BG2_X = DISPLAY_WIDTH + 16;
                    gBattle_BG2_Y = 0;
                    matchNo = gTasks[taskId2].data[1] - 16;
                    DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_DOWN, matchNo);
                }
            }

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollDown;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollDown;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollDown;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollDown;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_DOWN;
            gTasks[taskId].data[5] = 0;
            break;
        case TRAINERCARD_INPUT_LEFT:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = DISPLAY_WIDTH + 16;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = DISPLAY_WIDTH + 16;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sInfoCard->pos == 0)
            {
                gBattle_BG2_X = DISPLAY_WIDTH + 16;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
                trainerTourneyId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_LEFT, trainerTourneyId);
            }
            else
            {
                gBattle_BG2_X = DISPLAY_WIDTH + 16;
                gBattle_BG2_Y = 0;
                matchNo = sIdToMatchNumber[gTasks[taskId2].data[1]][sInfoCard->pos - 1];
                DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_LEFT, matchNo);
            }

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_LEFT;
            gTasks[taskId].data[5] = 0;
            break;
        case MATCHCARD_INPUT_LEFT:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = DISPLAY_WIDTH + 16;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = DISPLAY_WIDTH + 16;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sInfoCard->pos == 0)
            {
                gBattle_BG2_X = DISPLAY_WIDTH + 16;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
                trainerTourneyId = sInfoCard->tournamentIds[0];
                DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_LEFT, trainerTourneyId);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
                matchNo = gTasks[taskId2].data[1] - 16;
                DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_LEFT, matchNo);
            }

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollLeft;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_LEFT;
            gTasks[taskId].data[5] = 0;
            break;
        case TRAINERCARD_INPUT_RIGHT:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -(DISPLAY_WIDTH + 16);
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -(DISPLAY_WIDTH + 16);
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sInfoCard->pos == 1)
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 0;
            }
            matchNo = sIdToMatchNumber[gTasks[taskId2].data[1]][sInfoCard->pos - 1];
            DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_RIGHT, matchNo);

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_RIGHT;
            gTasks[taskId].data[5] = 0;
            break;
        case MATCHCARD_INPUT_RIGHT:
            if (gTasks[taskId].tUsingAlternateSlot)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -(DISPLAY_WIDTH + 16);
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -(DISPLAY_WIDTH + 16);
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sInfoCard->pos == 2)
            {
                gBattle_BG2_X = DISPLAY_WIDTH + 16;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
                trainerTourneyId = sInfoCard->tournamentIds[1];
                DisplayTrainerInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_RIGHT, trainerTourneyId);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = DISPLAY_HEIGHT;
                matchNo = gTasks[taskId2].data[1] - 16;
                DisplayMatchInfoOnCard(gTasks[taskId].tUsingAlternateSlot | MOVE_CARD_RIGHT, matchNo);
            }

            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot ^ 1;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_TrainerIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                        gSprites[sInfoCard->spriteIds[i]].data[3] = sInfoCard->spriteIds[i];
                    }
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                    {
                        gSprites[sInfoCard->spriteIds[i]].callback = SpriteCB_MonIconCardScrollRight;
                        gSprites[sInfoCard->spriteIds[i]].data[0] = gTasks[taskId].tUsingAlternateSlot;
                        gSprites[sInfoCard->spriteIds[i]].data[1] = 0;
                        gSprites[sInfoCard->spriteIds[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].tState = STATE_MOVE_RIGHT;
            gTasks[taskId].data[5] = 0;
            break;
        }
        break;
    case STATE_MOVE_UP:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y -= 4;
            gBattle_BG1_Y -= 4;
            gBattle_BG2_Y -= 4;
        }
        else
        {
            gTasks[taskId].tState = STATE_GET_INPUT;
        }
        break;
    case STATE_MOVE_DOWN:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y += 4;
            gBattle_BG1_Y += 4;
            gBattle_BG2_Y += 4;
        }
        else
        {
            gTasks[taskId].tState = STATE_GET_INPUT;
        }
        break;
    case STATE_MOVE_LEFT:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X -= 4;
            gBattle_BG1_X -= 4;
            gBattle_BG2_X -= 4;
        }
        else
        {
            gTasks[taskId].tState = STATE_GET_INPUT;
        }
        break;
    case STATE_MOVE_RIGHT:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X += 4;
            gBattle_BG1_X += 4;
            gBattle_BG2_X += 4;
        }
        else
        {
            gTasks[taskId].tState = STATE_GET_INPUT;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!gPaletteFade.active)
        {
            for (i = 0; i < NUM_INFOCARD_SPRITES / 2; i++)
            {
                if (i < 2)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                        FreeAndDestroyTrainerPicSprite(sInfoCard->spriteIds[i]);
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                        FreeAndDestroyMonIconSprite(&gSprites[sInfoCard->spriteIds[i]]);
                }
            }
            for (i = NUM_INFOCARD_SPRITES / 2; i < NUM_INFOCARD_SPRITES; i++)
            {
                if (i < 10)
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                        FreeAndDestroyTrainerPicSprite(sInfoCard->spriteIds[i]);
                }
                else
                {
                    if (sInfoCard->spriteIds[i] != SPRITE_NONE)
                        FreeAndDestroyMonIconSprite(&gSprites[sInfoCard->spriteIds[i]]);
                }
            }

            //FreeMonIconPalettes();
            FREE_AND_SET_NULL(sInfoCard);
            FreeAllWindowBuffers();

            if (mode == INFOCARD_NEXT_OPPONENT)
            {
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            }
            else
            {
                i = CreateTask(Task_ShowTourneyTree, 0);
                gTasks[i].data[0] = 0;
                gTasks[i].tNotInteractive = FALSE;
                gTasks[i].data[2] = 3;
                gTasks[i].data[3] = gTasks[taskId].data[4];
                gTasks[i].tIsPrevTourneyTree = gTasks[taskId2].data[6];
            }
            DestroyTask(taskId);
        }
        break;
    }
}

// undefine task states for Task_HandleInfoCardInput
#undef STATE_FADE_IN
#undef STATE_WAIT_FADE
#undef STATE_GET_INPUT
#undef STATE_REACT_INPUT
#undef STATE_MOVE_UP
#undef STATE_MOVE_DOWN
#undef STATE_MOVE_LEFT
#undef STATE_MOVE_RIGHT
#undef STATE_CLOSE_CARD

static u8 Task_GetInfoCardInput(u8 taskId)
{
    u8 input = INFOCARD_INPUT_NONE;
    int taskId2 = gTasks[taskId].data[4];
    int position = gTasks[taskId2].data[1];
    u8 tourneyId = sTourneyTreeTrainerIds[position];
    u16 roundId = gSaveBlockPtr->frontier.curChallengeBattleNum;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
        input = INFOCARD_INPUT_AB;

    // Next opponent card cant scroll
    if (gTasks[taskId].data[3] == INFOCARD_NEXT_OPPONENT)
        return input;

    if (gTasks[taskId].data[3] == INFOCARD_TRAINER)
    {
        // For trainer info cards, pos is 0 when on a trainer info card (not viewing that trainer's match progression)
        // Scrolling up/down from a trainer info card goes to other trainer info cards
        if (JOY_NEW(DPAD_UP) && sInfoCard->pos == 0)
        {
            if (position == 0)
                position = DOME_TOURNAMENT_TRAINERS_COUNT - 1;
            else
                position--;
            input = TRAINERCARD_INPUT_UP;
        }
        else if (JOY_NEW(DPAD_DOWN) && sInfoCard->pos == 0)
        {
            if (position == DOME_TOURNAMENT_TRAINERS_COUNT - 1)
                position = 0;
            else
                position++;
            input = TRAINERCARD_INPUT_DOWN;
        }
        // Scrolling left can only be done after scrolling right
        else if (JOY_NEW(DPAD_LEFT) && sInfoCard->pos != 0)
        {
            sInfoCard->pos--;
            input = TRAINERCARD_INPUT_LEFT;
        }
        // Scrolling right from a trainer info card shows their match progression
        else if (JOY_NEW(DPAD_RIGHT))
        {
            // Can only scroll right from a trainer card until the round they were eliminated
            if (DOME_TRAINERS[tourneyId].isEliminated && sInfoCard->pos - 1 < DOME_TRAINERS[tourneyId].eliminatedAt)
            {
                sInfoCard->pos++;
                input = TRAINERCARD_INPUT_RIGHT;
            }
            // otherwise can scroll as far right as the current round allows
            if (!DOME_TRAINERS[tourneyId].isEliminated && sInfoCard->pos - 1 < roundId)
            {
                sInfoCard->pos++;
                input = TRAINERCARD_INPUT_RIGHT;
            }
        }

        if (input == INFOCARD_INPUT_AB)
        {
            if (sInfoCard->pos != 0)
                gTasks[taskId2].data[1] = sTrainerAndRoundToLastMatchCardNum[position / 2][sInfoCard->pos - 1];
            else
                gTasks[taskId2].data[1] = position;
        }
    }
    else // gTasks[taskId].data[3] == INFOCARD_MATCH
    {
        // For match info cards, pos is 1 when on the match card, 0 when on the left trainer, and 1 when on the right trainer
        // Scrolling up/down from a match info card goes to the next/previous match
        if (JOY_NEW(DPAD_UP) && sInfoCard->pos == 1)
        {
            if (position == DOME_TOURNAMENT_TRAINERS_COUNT)
                position = sLastMatchCardNum[roundId];
            else
                position--;
            input = MATCHCARD_INPUT_UP;
        }
        else if (JOY_NEW(DPAD_DOWN) && sInfoCard->pos == 1)
        {
            if (position == sLastMatchCardNum[roundId])
                position = DOME_TOURNAMENT_TRAINERS_COUNT;
            else
                position++;
            input = MATCHCARD_INPUT_DOWN;
        }
        // Scrolling left/right from a match info card shows the trainer info card of the competitors for that match
        else if (JOY_NEW(DPAD_LEFT) && sInfoCard->pos != 0)
        {
            input = MATCHCARD_INPUT_LEFT;
            sInfoCard->pos--;
        }
        else if (JOY_NEW(DPAD_RIGHT) && (sInfoCard->pos == 0 || sInfoCard->pos == 1))
        {
            input = MATCHCARD_INPUT_RIGHT;
            sInfoCard->pos++;
        }

        if (input == INFOCARD_INPUT_AB)
        {
            if (sInfoCard->pos == 0) // On left trainer info card
                gTasks[taskId2].data[1] = sTournamentIdToPairedTrainerIds[sInfoCard->tournamentIds[0]];
            else if (sInfoCard->pos == 2) // On right trainer info card
                gTasks[taskId2].data[1] = sTournamentIdToPairedTrainerIds[sInfoCard->tournamentIds[1]];
            else // On match info card
                gTasks[taskId2].data[1] = position;
        }
    }

    if (input != INFOCARD_INPUT_NONE && input != INFOCARD_INPUT_AB)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId2].data[1] = position;
        gTasks[taskId].tUsingAlternateSlot ^= 1;
    }

    return input;
}

#undef tUsingAlternateSlot

// allocatedArray below needs to be large enough to hold stat totals for each mon, or totals of each type of move points
#define ALLOC_ARRAY_SIZE max(NUMERO_ESTADISTICAS * FRONTIER_PARTY_SIZE, NUM_MOVE_POINT_TYPES)

static void DisplayTrainerInfoOnCard(u8 flags, u8 trainerTourneyId)
{

}

static int BufferDomeWinString(u8 matchNum, u8 *tournamentIds)
{
    return 0;
}

static void DisplayMatchInfoOnCard(u8 flags, u8 matchNo)
{

}

static void ShowDomeTourneyTree(void)
{
    u8 taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tNotInteractive = FALSE;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].tIsPrevTourneyTree = FALSE;
    SetMainCallback2(CB2_TourneyTree);
}

// To show the results of the last tourney on the computer in the lobby
static void ShowPreviousDomeTourneyTree(void)
{
    u8 taskId;

    SetFacilityTrainerAndMonPtrs();
    gSaveBlockPtr->frontier.lvlMode = gSaveBlockPtr->frontier.domeLvlMode - 1;
    gSaveBlockPtr->frontier.curChallengeBattleNum = DOME_FINAL;
    taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tNotInteractive = FALSE;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].tIsPrevTourneyTree = TRUE;
    SetMainCallback2(CB2_TourneyTree);
}

// Shows the results of the just-completed round for the current tourney
static void ShowNonInteractiveDomeTourneyTree(void)
{
    u8 taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tNotInteractive = TRUE;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].tIsPrevTourneyTree = FALSE;
    SetMainCallback2(CB2_TourneyTree);
}

static void ResolveDomeRoundWinners(void)
{

}

static void Task_ShowTourneyTree(u8 taskId)
{

}

static void CB2_TourneyTree(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void VblankCb_TourneyInfoCard(void)
{
    ChangeBgX(3, 0x80, BG_COORD_ADD);
    ChangeBgY(3, 0x80, BG_COORD_SUB);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void SetFacilityTrainerAndMonPtrs(void)
{
    gFacilityTrainerMons = gBattleFrontierMons;
    gFacilityTrainers = gBattleFrontierTrainers;
}

static void ResetSketchedMoves(void)
{
    int i, moveSlot;

    for (i = 0; i < DOME_BATTLE_PARTY_SIZE; i++)
    {
        int playerMonId = gSaveBlockPtr->frontier.selectedPartyMons[gSelectedOrderFromParty[i] - 1] - 1;
        int count;

        for (moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
        {
            count = 0;
            while (count < MAX_MON_MOVES)
            {
                if (GetMonData(&gSaveBlockPtr->playerParty[playerMonId], MON_DATA_MOVE1 + count, NULL) == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + moveSlot, NULL))
                    break;
                count++;
            }
            if (count == MAX_MON_MOVES)
                SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, moveSlot);
        }

        gSaveBlockPtr->playerParty[playerMonId] = gPlayerParty[i];
    }
}

static void RestoreDomePlayerPartyHeldItems(void)
{
    int i;

    for (i = 0; i < DOME_BATTLE_PARTY_SIZE; i++)
    {
        int playerMonId = gSaveBlockPtr->frontier.selectedPartyMons[gSelectedOrderFromParty[i] - 1] - 1;
        u16 item = GetMonData(&gSaveBlockPtr->playerParty[playerMonId], MON_DATA_HELD_ITEM, NULL);
        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
    }
}

static void ReduceDomePlayerPartyToSelectedMons(void)
{
    ReducePlayerPartyToSelectedMons();
}

static void GetPlayerSeededBeforeOpponent(void)
{

}

static void BufferLastDomeWinnerName(void)
{
    int i;

    SetFacilityTrainerAndMonPtrs();
    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (!DOME_TRAINERS[i].isEliminated)
            break;
    }
    CopyDomeTrainerName(gStringVar1, DOME_TRAINERS[i].trainerId);
}

// For showing the previous tourney results before the player has entered a challenge
static void InitRandomTourneyTreeResults(void)
{
    int i, j, k;
    int monLevel;
    int species[FRONTIER_PARTY_SIZE];
    int monTypesBits;
    int trainerId;
    int monId;
    int zero1;
    int zero2;
    u8 lvlMode;
    u16 *statSums;
    int *statValues;
    u8 ivs = 0;

    species[0] = 0;
    species[1] = 0;
    species[2] = 0;
    if ((gSaveBlockPtr->frontier.domeLvlMode != -gSaveBlockPtr->frontier.domeBattleMode) && gSaveBlockPtr->frontier.challengeStatus != CHALLENGE_STATUS_SAVING)
        return;

    statSums = AllocZeroed(sizeof(u16) * DOME_TOURNAMENT_TRAINERS_COUNT);
    statValues = AllocZeroed(sizeof(int) * NUMERO_ESTADISTICAS);
    lvlMode = gSaveBlockPtr->frontier.lvlMode;
    gSaveBlockPtr->frontier.lvlMode = FRONTIER_LVL_50;
    zero1 = 0;
    zero2 = 0;

    gSaveBlockPtr->frontier.domeLvlMode = zero1 + 1;
    gSaveBlockPtr->frontier.domeBattleMode = zero2 + 1;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        do
        {
            if (i < 5)
                trainerId = Random() % 10;
            else if (i < 15)
                trainerId = Random() % 20 + 10;
            else
                trainerId = Random() % 10 + 30;

            for (j = 0; j < i; j++)
            {
                if (DOME_TRAINERS[j].trainerId == trainerId)
                    break;
            }
        } while (j != i);

        DOME_TRAINERS[i].trainerId = trainerId;
        for (j = 0; j < FRONTIER_PARTY_SIZE; j++)
        {
            do
            {
                monId = GetRandomFrontierMonFromSet(trainerId);
                for (k = 0; k < j; k++)
                {
                    // Make sure the mon is valid.
                    int alreadySelectedMonId = DOME_MONS[i][k];
                    if (alreadySelectedMonId == monId
                        || species[0] == gFacilityTrainerMons[monId].species
                        || species[1] == gFacilityTrainerMons[monId].species
                        || gFacilityTrainerMons[alreadySelectedMonId].heldItem == gFacilityTrainerMons[monId].heldItem)
                        break;
                }
            } while (k != j);

            DOME_MONS[i][j] = monId;
            species[j] = gFacilityTrainerMons[monId].species;
        }
        DOME_TRAINERS[i].isEliminated = FALSE;
        DOME_TRAINERS[i].eliminatedAt = 0;
        DOME_TRAINERS[i].forfeited = FALSE;
    }

    monLevel = FRONTIER_MAX_LEVEL_50;
    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        monTypesBits = 0;
        statSums[i] = 0;
        ivs = GetDomeTrainerMonIvs(DOME_TRAINERS[i].trainerId);
        for (j = 0; j < FRONTIER_PARTY_SIZE; j++)
        {
            CalcDomeMonStats(&gFacilityTrainerMons[DOME_MONS[i][j]],
                             monLevel, ivs, statValues);

            statSums[i] += statValues[ESTADISTICA_ATAQUE];
            statSums[i] += statValues[ESTADISTICA_DEFENSA];
            statSums[i] += statValues[ESTADISTICA_ATAQUE_ESPECIAL];
            statSums[i] += statValues[ESTADISTICA_DEFENSA_ESPECIAL];
            statSums[i] += statValues[ESTADISTICA_VELOCIDAD];
            statSums[i] += statValues[ESTADISTICA_PS];
            monTypesBits |= 1u << gSpeciesInfo[gFacilityTrainerMons[DOME_MONS[i][j]].species].types[0];
            monTypesBits |= 1u << gSpeciesInfo[gFacilityTrainerMons[DOME_MONS[i][j]].species].types[1];
        }

        // Because GF hates temporary vars, trainerId acts like monTypesCount here.
        for (trainerId = 0, j = 0; j < 32; j++)
        {
            if (monTypesBits & 1)
                trainerId++;
            monTypesBits >>= 1;
        }
        statSums[i] += (trainerId * monLevel) / 20;
    }

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT - 1; i++)
    {
        for (j = i + 1; j < DOME_TOURNAMENT_TRAINERS_COUNT; j++)
        {
            if (statSums[i] < statSums[j])
            {
                SwapDomeTrainers(i, j, statSums);
            }
            else if (statSums[i] == statSums[j])
            {
                if (DOME_TRAINERS[i].trainerId > DOME_TRAINERS[j].trainerId)
                    SwapDomeTrainers(i, j, statSums);
            }
        }
    }

    Free(statSums);
    Free(statValues);

    for (i = 0; i < DOME_ROUNDS_COUNT; i++)
        DecideRoundWinners(i);

    gSaveBlockPtr->frontier.lvlMode = lvlMode;
}

static int TrainerIdToTournamentId(u16 trainerId)
{
    int i;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (DOME_TRAINERS[i].trainerId == trainerId)
            break;
    }

    return i;
}

// The same as the above one, but has global scope.
int TrainerIdToDomeTournamentId(u16 trainerId)
{
    int i;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (DOME_TRAINERS[i].trainerId == trainerId)
            break;
    }

    return i;
}

// Determines which trainers won in the NPC vs NPC battles
static void DecideRoundWinners(u8 roundId)
{

}

static void CopyDomeTrainerName(u8 *str, u16 trainerId)
{

}

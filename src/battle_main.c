#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_util.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "debug.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "field_weather.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "safari_zone.h"
#include "distorsion_fondo.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "util.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/weather.h"

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate sBattleWindowTemplates[];

static void CB2_InitBattleInternal(void);
static void CB2_HandleStartBattle(void);
static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer);
static void BattleMainCB1(void);
static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCB_WildMonAnimate(struct Sprite *sprite);
static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
static void SpriteCB_BlinkVisible(struct Sprite *sprite);
static void SpriteCB_Idle(struct Sprite *sprite);
static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite);
static void TurnValuesCleanUp(bool8 var0);
static void SpriteCB_BounceEffect(struct Sprite *sprite);
static void BattleStartClearSetData(void);
static void DoBattleIntro(void);
static void TryDoEventsBeforeFirstTurn(void);
static void GestionaEstadoSeleccionAccionesTurno(void);
static void RunTurnActionsFunctions(void);
static void SetActionsAndBattlersTurnOrder(void);
static void UpdateBattlerPartyOrdersOnSwitch(u32 battler);
static void FreeResetData_ReturnToOvOrDoEvolutions(void);
static void ReturnFromBattleToOverworld(void);
static void TryEvolvePokemon(void);
static void WaitForEvoSceneToFinish(void);
static void HandleEndTurn_ContinueBattle(void);
static void HandleEndTurn_BattleWon(void);
static void HandleEndTurn_BattleLost(void);
static void HandleEndTurn_RanFromBattle(void);
static void HandleEndTurn_MonFled(void);
static void HandleEndTurn_FinishBattle(void);
static u32 Crc32B(const u8 *data, u32 size);
static u32 GeneratePartyHash(const struct Trainer *trainer, u32 i);
static s32 Factorial(s32);

EWRAM_DATA u16 gBattle_BG0_X = 0;
EWRAM_DATA u16 gBattle_BG0_Y = 0;
EWRAM_DATA u16 gBattle_BG1_X = 0;
EWRAM_DATA u16 gBattle_BG1_Y = 0;
EWRAM_DATA u16 gBattle_BG2_X = 0;
EWRAM_DATA u16 gBattle_BG2_Y = 0;
EWRAM_DATA u16 gBattle_BG3_X = 0;
EWRAM_DATA u16 gBattle_BG3_Y = 0;
EWRAM_DATA u16 gBattle_WIN0H = 0;
EWRAM_DATA u16 gBattle_WIN0V = 0;
EWRAM_DATA u16 gBattle_WIN1H = 0;
EWRAM_DATA u16 gBattle_WIN1V = 0;
EWRAM_DATA u8 gDisplayedStringBattle[425] = {0}; // Increased in size to fit Juan's defeat text (SootopolisCity_Gym_1F_Text_JuanDefeat)
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTerrain = 0;
EWRAM_DATA u8 *gBattleAnimBgTileBuffer = NULL;
EWRAM_DATA u8 *gBattleAnimBgTilemapBuffer = NULL;
EWRAM_DATA bool32 gFlagCombatientesOcupados[NUMERO_COMBATIENTES] = {FALSE};
EWRAM_DATA u8 gBattlersCount = 0;
EWRAM_DATA u16 gBattlerPartyIndexes[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gActionsByTurnOrder[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gBattlerByTurnOrder[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gCurrentTurnActionNumber = 0;
EWRAM_DATA u8 gCurrentActionFuncId = 0;
EWRAM_DATA struct BattlePokemon gBattleMons[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gBattlerSpriteIds[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gCurrMovePos = 0;
EWRAM_DATA u8 gChosenMovePos = 0;
EWRAM_DATA u16 gCurrentMove = 0;
EWRAM_DATA u16 gChosenMove = 0;
EWRAM_DATA u16 gCalledMove = 0;
EWRAM_DATA s32 gBattleMoveDamage = 0;
EWRAM_DATA s32 gHpDealt = 0;
EWRAM_DATA u16 gLastUsedItem = 0;
EWRAM_DATA u16 gLastUsedAbility = 0;
EWRAM_DATA u8 gBattlerAttacker = 0;
EWRAM_DATA u8 gBattlerTarget = 0;
EWRAM_DATA u8 gBattlerFainted = 0;
EWRAM_DATA u8 gEffectBattler = 0;
EWRAM_DATA u8 gPotentialItemEffectBattler = 0;
EWRAM_DATA u8 gAbsentBattlerFlags = 0;
EWRAM_DATA u32 gEsGolpeCritico = FALSE;
EWRAM_DATA const u8 *gBattlescriptCurrInstr = NULL;
EWRAM_DATA u32 gAccionElegida[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA const u8 *gSelectionBattleScripts[NUMERO_COMBATIENTES] = {NULL};
EWRAM_DATA u16 gLastPrintedMoves[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastMoves[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastLandedMoves[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastHitByType[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastUsedMoveType[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastResultingMoves[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLockedMoves[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gLastUsedMove = 0;
EWRAM_DATA u8 gLastHitBy[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gMovimientoElegido[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u32 gHitMarker = 0;
EWRAM_DATA u32 gSideStatuses[NUMERO_LADOS] = {0};
EWRAM_DATA struct SideTimer gSideTimers[NUMERO_LADOS] = {0};
EWRAM_DATA u32 gStatuses3[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA struct DisableStruct gDisableStructs[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gPauseCounterBattle = 0;
EWRAM_DATA u16 gPaydayMoney = 0;
EWRAM_DATA u32 gEstadoAccion[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u32 gMensajeBatalla = 0;
EWRAM_DATA u32 gPosicionCursorSiNo = CURSOR_SI;
EWRAM_DATA bool32 gMostrarMensajeBatalla = FALSE;
EWRAM_DATA u8 gBattleOutcome = 0;
EWRAM_DATA struct ProtectStruct gProtectStructs[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA struct SpecialStatus gSpecialStatuses[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u16 gIntroSlideFlags = 0;
EWRAM_DATA u8 gSentPokesToOpponent[2] = {0};
EWRAM_DATA struct BattleScripting gBattleScripting = {0};
EWRAM_DATA struct Combate *gCombate = NULL;
EWRAM_DATA struct BattleResources *gBattleResources = NULL;
EWRAM_DATA u8 gActionSelectionCursor[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gMoveSelectionCursor[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gBattlerStatusSummaryTaskId[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA u8 gBattlerInMenuId = 0;
EWRAM_DATA bool8 gDoingBattleAnim = FALSE;
EWRAM_DATA u8 gPlayerDpadHoldFrames = 0;
EWRAM_DATA struct BattleSpriteData *gBattleSpritesDataPtr = NULL;
EWRAM_DATA struct MonSpritesGfx *gMonSpritesGfxPtr = NULL;
EWRAM_DATA u16 gBattleMovePower = 0;
EWRAM_DATA u16 gMoveToLearn = 0;
EWRAM_DATA u32 gFieldStatuses = 0;
EWRAM_DATA struct FieldTimer gFieldTimers = {0};
EWRAM_DATA u32 gBattlerAbility = 0;
EWRAM_DATA u8 gLastUsedBall = 0;
EWRAM_DATA u16 gLastThrownBall = 0;
EWRAM_DATA u16 gBallToDisplay = 0;
EWRAM_DATA bool8 gLastUsedBallMenuPresent = FALSE;
EWRAM_DATA static u8 sTriedEvolving = 0;
EWRAM_DATA u8 gCategoryIconSpriteId = 0;

COMMON_DATA void (*gPreBattleCallback1)(void) = NULL;
COMMON_DATA void (*gBattleMainFunc)(void) = NULL;
COMMON_DATA u8 gLeveledUpInBattle = 0;
COMMON_DATA u8 gHealthboxSpriteIds[NUMERO_COMBATIENTES] = {0};
COMMON_DATA u8 gNumberOfMovesToChoose = 0;

static const struct ParametrosDistorsionFondo sIntroScanlineParams16Bit =
    {
        .dmaDest = &REG_BG1HOFS,
        .bitsDMA = DISTORSION_FONDO_DMA_16,
        .estado = 1};

const struct OamData gOamData_BattleSpriteOpponentSide =
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_NORMAL,
        .objMode = ST_OAM_OBJ_NORMAL,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(64x64),
        .x = 0,
        .size = SPRITE_SIZE(64x64),
        .tileNum = 0,
        .priority = 2,
        .paletteNum = 0,
        .affineParam = 0,
};

const struct OamData gOamData_BattleSpritePlayerSide =
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_NORMAL,
        .objMode = ST_OAM_OBJ_NORMAL,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(64x64),
        .x = 0,
        .size = SPRITE_SIZE(64x64),
        .tileNum = 0,
        .priority = 2,
        .paletteNum = 2,
        .affineParam = 0,
};

static const s8 sCenterToCornerVecXs[8] = {-32, -16, -16, -32, -32};

#include "data/types_info.h"

// extra args are money and ball
#define TRAINER_CLASS(trainerClass, trainerName, ...)       \
    [TRAINER_CLASS_##trainerClass] =                        \
        {                                                   \
            .name = _(trainerName),                         \
            .money = DEFAULT(5, __VA_ARGS__),               \
            .ball = DEFAULT_2(ITEM_POKE_BALL, __VA_ARGS__), \
    }

const struct TrainerClass gTrainerClasses[TRAINER_CLASS_COUNT] =
    {
        TRAINER_CLASS(HIKER, "Montañero", 10, ITEM_ULTRA_BALL),
        TRAINER_CLASS(TEAM_AQUA, "Equipo Aqua", 8, ITEM_DIVE_BALL),
        TRAINER_CLASS(PKMN_BREEDER, "Criador {PKMN}", 10, ITEM_HEAL_BALL),
        TRAINER_CLASS(COOLTRAINER, "Molón", 12, ITEM_ULTRA_BALL),
        TRAINER_CLASS(BIRD_KEEPER, "Ornitólogo", 8, ITEM_NEST_BALL),
        TRAINER_CLASS(COLLECTOR, "Colector", 15, ITEM_PREMIER_BALL),
        TRAINER_CLASS(SWIMMER_M, "Nadador", 2, ITEM_DIVE_BALL),
        TRAINER_CLASS(TEAM_MAGMA, "Equipo Magma", 8, ITEM_DUSK_BALL),
        TRAINER_CLASS(EXPERT, "Pokéxperto", 10, ITEM_FRIEND_BALL),
        TRAINER_CLASS(AQUA_ADMIN, "Admin. Aqua", 10, ITEM_DIVE_BALL),
        TRAINER_CLASS(BLACK_BELT, "Karateka", 8, ITEM_ULTRA_BALL),
        TRAINER_CLASS(AQUA_LEADER, "Líder Aqua", 20, ITEM_MASTER_BALL),
        TRAINER_CLASS(HEX_MANIAC, "Bruja", 6, ITEM_HEAVY_BALL),
        TRAINER_CLASS(AROMA_LADY, "Señorita", 10, ITEM_LOVE_BALL),
        TRAINER_CLASS(RUIN_MANIAC, "Ruinamaníaco", 15, ITEM_DUSK_BALL),
        TRAINER_CLASS(INTERVIEWER, "Reportera", 12, ITEM_FRIEND_BALL),
        TRAINER_CLASS(TUBER_F, "Playera", 1, ITEM_NET_BALL),
        TRAINER_CLASS(TUBER_M, "Playero", 1, ITEM_NET_BALL),
        TRAINER_CLASS(LADY, "Damisela", 50, ITEM_LUXURY_BALL),
        TRAINER_CLASS(BEAUTY, "Bella", 20, ITEM_LOVE_BALL),
        TRAINER_CLASS(RICH_BOY, "Niño bien", 50, ITEM_LUXURY_BALL),
        TRAINER_CLASS(POKEMANIAC, "Pokémaniaco", 15, ITEM_NEST_BALL),
        TRAINER_CLASS(GUITARIST, "Guitarrista", 8, ITEM_QUICK_BALL),
        TRAINER_CLASS(KINDLER, "Fogonero", 8, ITEM_QUICK_BALL),
        TRAINER_CLASS(CAMPER, "Campista", 4, ITEM_LEVEL_BALL),
        TRAINER_CLASS(PICNICKER, "Dominguera", 4, ITEM_NEST_BALL),
        TRAINER_CLASS(BUG_MANIAC, "Bichomaníaco", 15, ITEM_NET_BALL),
        TRAINER_CLASS(PSYCHIC, "Médium", 6, ITEM_DUSK_BALL),
        TRAINER_CLASS(GENTLEMAN, "Caballero", 20, ITEM_LUXURY_BALL),
        TRAINER_CLASS(ELITE_FOUR, "Alto Mando", 25, ITEM_ULTRA_BALL),
        TRAINER_CLASS(LEADER, "Líder", 25, ITEM_ULTRA_BALL),
        TRAINER_CLASS(SCHOOL_KID, "Colegial"),
        TRAINER_CLASS(SR_AND_JR, "Estudiantes", 4, ITEM_REPEAT_BALL),
        TRAINER_CLASS(WINSTRATE, "Estratega", 10, ITEM_REPEAT_BALL),
        TRAINER_CLASS(POKEFAN, "Pokéfan", 20, ITEM_PREMIER_BALL),
        TRAINER_CLASS(YOUNGSTER, "Joven", 4, ITEM_NEST_BALL),
        TRAINER_CLASS(CHAMPION, "Campeón", 50, ITEM_ULTRA_BALL),
        TRAINER_CLASS(FISHERMAN, "Pescador", 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? ITEM_DIVE_BALL : ITEM_LURE_BALL),
        TRAINER_CLASS(TRIATHLETE, "Triatleta", 10, ITEM_QUICK_BALL),
        TRAINER_CLASS(DRAGON_TAMER, "Domadragones", 12, ITEM_CHERISH_BALL),
        TRAINER_CLASS(NINJA_BOY, "Ninja", 3, ITEM_MOON_BALL),
        TRAINER_CLASS(BATTLE_GIRL, "Luchadora", 6, ITEM_GREAT_BALL),
        TRAINER_CLASS(PARASOL_LADY, "Dama parasol", 10, ITEM_LUXURY_BALL),
        TRAINER_CLASS(SWIMMER_F, "Nadadora", 2, ITEM_DIVE_BALL),
        TRAINER_CLASS(TWINS, "Gemelas", 3, ITEM_FRIEND_BALL),
        TRAINER_CLASS(SAILOR, "Marinero", 8, ITEM_DIVE_BALL),
        TRAINER_CLASS(MAGMA_ADMIN, "Admin. Magma", 10, ITEM_DUSK_BALL),
        TRAINER_CLASS(RIVAL, "Entrenador", 15, ITEM_ULTRA_BALL),
        TRAINER_CLASS(BUG_CATCHER, "Cazabichos", 4, ITEM_NET_BALL),
        TRAINER_CLASS(PKMN_RANGER, "{PKMN} Ranger", 12, ITEM_ULTRA_BALL),
        TRAINER_CLASS(MAGMA_LEADER, "Líder Magma", 20, ITEM_MASTER_BALL),
        TRAINER_CLASS(LASS, "Señorita", 4, ITEM_LUXURY_BALL),
        TRAINER_CLASS(YOUNG_COUPLE, "Joven pareja", 8, ITEM_LOVE_BALL),
        TRAINER_CLASS(OLD_COUPLE, "Pareja mayor", 10, ITEM_LOVE_BALL),
        TRAINER_CLASS(SIS_AND_BRO, "Hermanos", 3, ITEM_FRIEND_BALL),
        TRAINER_CLASS(RS_PROTAG, "Entrenador"),
};

static void (*const sTurnActionsFuncsTable[])(void) =
    {
        [B_ACTION_USE_MOVE] = HandleAction_UseMove,
        [B_ACTION_SWITCH] = HandleAction_Switch,
        [B_ACTION_RUN] = HandleAction_Run,
        [B_ACTION_EXEC_SCRIPT] = HandleAction_RunBattleScript,
        [B_ACTION_TRY_FINISH] = HandleAction_TryFinish,
        [B_ACTION_FINISHED] = HandleAction_ActionFinished,
        [B_ACTION_NOTHING_FAINTED] = HandleAction_NothingIsFainted,
        [B_ACTION_THROW_BALL] = HandleAction_ThrowBall,
};

static void (*const sEndTurnFuncsTable[])(void) =
    {
        [0] = HandleEndTurn_ContinueBattle,
        [B_OUTCOME_WON] = HandleEndTurn_BattleWon,
        [B_OUTCOME_LOST] = HandleEndTurn_BattleLost,
        [B_OUTCOME_DREW] = HandleEndTurn_BattleLost,
        [B_OUTCOME_RAN] = HandleEndTurn_RanFromBattle,
        [B_OUTCOME_PLAYER_TELEPORTED] = HandleEndTurn_FinishBattle,
        [B_OUTCOME_MON_FLED] = HandleEndTurn_MonFled,
        [B_OUTCOME_CAUGHT] = HandleEndTurn_FinishBattle,
        [B_OUTCOME_FORFEITED] = HandleEndTurn_FinishBattle,
        [B_OUTCOME_MON_TELEPORTED] = HandleEndTurn_FinishBattle,
};

const u8 *const gStatusConditionStringsTable[7] =
    {
        gText_Poison,
        gText_Sleep,
        gText_Paralysis,
        gText_Burn,
        gText_Ice,
        gText_Confusion,
        gText_Love};

void CB2_InitBattle(void)
{
    ResetHeap();
    AllocateBattleResources();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    CB2_InitBattleInternal();
}

static void CB2_InitBattleInternal(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);

    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, ANCHO_PANTALLA);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(ALTURA_PANTALLA / 2, ALTURA_PANTALLA / 2 + 1));
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = ANCHO_PANTALLA;

    gBattle_WIN0V = WIN_RANGE(ALTURA_PANTALLA / 2, ALTURA_PANTALLA / 2 + 1);
    LimpiaDistorsionFondo();

    for (i = 0; i < ALTURA_PANTALLA / 2; i++)
    {
        gRegistrosBuffersDistorsionFondo[0][i] = 0xF0;
        gRegistrosBuffersDistorsionFondo[1][i] = 0xF0;
    }

    for (; i < ALTURA_PANTALLA; i++)
    {
        gRegistrosBuffersDistorsionFondo[0][i] = 0xFF10;
        gRegistrosBuffersDistorsionFondo[1][i] = 0xFF10;
    }

    EscribeParametrosDistorsionFondo(sIntroScanlineParams16Bit);

    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;

    if (!DEBUG_OVERWORLD_MENU || (DEBUG_OVERWORLD_MENU && !gIsDebugBattle))
    {
        gBattleTerrain = BattleSetup_GetTerrainId();
    }

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    DrawBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = NUMERO_COMBATIENTES;
    SetVBlankCallback(VBlankCB_Battle);
    PreparaVarsBatalla();
    SetMainCallback2(CB2_HandleStartBattle);

    if (!DEBUG_OVERWORLD_MENU || (DEBUG_OVERWORLD_MENU && !gIsDebugBattle))
    {
        CreateNPCTrainerParty(&gEnemyParty[0], gTrainerBattleOpponent, TRUE);
        SetWildMonHeldItem();
        CalculateEnemyPartyCount();
    }

    gMain.inBattle = TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        AdjustFriendship(&gPlayerParty[i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);
    }

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

#define BUFFER_PARTY_VS_SCREEN_STATUS(party, flags, i)                    \
    for ((i) = 0; (i) < PARTY_SIZE; (i)++)                                \
    {                                                                     \
        u32 species = GetMonData(&(party)[(i)], MON_DATA_SPECIES_OR_EGG); \
        u32 hp = GetMonData(&(party)[(i)], MON_DATA_HP);                  \
        u32 status = GetMonData(&(party)[(i)], MON_DATA_STATUS);          \
                                                                          \
        if (species == SPECIES_NONE)                                      \
            continue;                                                     \
                                                                          \
        /* Is healthy mon? */                                             \
        if (species != SPECIES_EGG && hp != 0 && status == 0)             \
            (flags) |= 1 << (i) * 2;                                      \
                                                                          \
        /* Is Egg or statused? */                                         \
        if (hp != 0 && (species == SPECIES_EGG || status != 0))           \
            (flags) |= 2 << (i) * 2;                                      \
                                                                          \
        /* Is fainted? */                                                 \
        if (species != SPECIES_EGG && hp == 0)                            \
            (flags) |= 3 << (i) * 2;                                      \
    }

static void CB2_HandleStartBattle(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    if (!IsDma3ManagerBusyWithBgCopy())
    {
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        FillAroundBattleWindows();
    }

    InitBattleControllers();
    IniciaSpritesBatalla();
    gPreBattleCallback1 = gMain.callback1;
    gMain.callback1 = BattleMainCB1;
    SetMainCallback2(BattleMainCB2);
}

void BattleMainCB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

#define sState data[0]
#define sDelay data[4]

static u32 Crc32B(const u8 *data, u32 size)
{
    s32 i, j;
    u32 byte, crc, mask;

    i = 0;
    crc = 0xFFFFFFFF;
    for (i = 0; i < size; ++i)
    {
        byte = data[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; --j)
        {
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
    }
    return ~crc;
}

static u32 GeneratePartyHash(const struct Trainer *trainer, u32 i)
{
    const u8 *buffer = (const u8 *)&trainer->party[i];
    u32 n = sizeof(*trainer->party);
    return Crc32B(buffer, n);
}

void ModifyPersonalityForNature(u32 *personality, u32 newNature)
{
    u32 nature = NaturalezaDePersonalidad(*personality);
    s32 diff = abs((s32)nature - (s32)newNature);
    s32 sign = (nature > newNature) ? 1 : -1;
    if (diff > NUMERO_NATURALEZAS / 2)
    {
        diff = NUMERO_NATURALEZAS - diff;
        sign *= -1;
    }
    *personality -= (diff * sign);
}

u32 GeneratePersonalityForGender(u32 gender, u32 species)
{
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[species];
    if (gender == MON_GENDERLESS)
        return 0;
    else if (gender == MON_MALE)
        return ((255 - speciesInfo->genderRatio) / 2) + speciesInfo->genderRatio;
    else
        return speciesInfo->genderRatio / 2;
}

void CustomTrainerPartyAssignMoves(struct Pokemon *mon, const struct TrainerMon *partyEntry)
{
    bool32 noMoveSet = TRUE;
    u32 j;

    for (j = 0; j < MAXIMO_MOVIMIENTOS_POKEMON; ++j)
    {
        if (partyEntry->moves[j] != MOVE_NONE)
            noMoveSet = FALSE;
    }
    if (noMoveSet)
    {
        // TODO: Figure out a default strategy when moves are not set, to generate a good moveset
        return;
    }

    for (j = 0; j < MAXIMO_MOVIMIENTOS_POKEMON; ++j)
    {
        SetMonData(mon, MON_DATA_MOVE1 + j, &partyEntry->movimientos[j]);
        SetMonData(mon, MON_DATA_PP1 + j, &gMovimientos[partyEntry->movimientos[j]].pp);
    }
}

u8 CreateNPCTrainerPartyFromTrainer(struct Pokemon *party, const struct Trainer *trainer, bool32 firstTrainer)
{
    s32 i;
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        for (i = 0; i < trainer->partySize; i++)
        {
            s32 ball = -1;
            u32 personalityHash = GeneratePartyHash(trainer, i);
            const struct TrainerMon *partyData = trainer->party;
            u32 ability = 0;
            u32 personalityValue = 128;

            personalityValue += personalityHash << 8;
            if (partyData[i].gender == TRAINER_MON_MALE)
                personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender(MON_MALE, partyData[i].species);
            else if (partyData[i].gender == TRAINER_MON_FEMALE)
                personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender(MON_FEMALE, partyData[i].species);
            else if (partyData[i].gender == TRAINER_MON_RANDOM_GENDER)
                personalityValue = (personalityValue & 0xFFFFFF00) | GeneratePersonalityForGender(Random() & 1 ? MON_MALE : MON_FEMALE, partyData[i].species);
            ModifyPersonalityForNature(&personalityValue, partyData[i].nature);
            CreaPokemon(&party[i], partyData[i].species, partyData[i].lvl, TRUE, personalityValue);
            SetMonData(&party[i], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

            CustomTrainerPartyAssignMoves(&party[i], &partyData[i]);
            if (partyData[i].ev != NULL)
            {
                SetMonData(&party[i], MON_DATA_HP_EV, &(partyData[i].ev[0]));
                SetMonData(&party[i], MON_DATA_ATK_EV, &(partyData[i].ev[1]));
                SetMonData(&party[i], MON_DATA_DEF_EV, &(partyData[i].ev[2]));
                SetMonData(&party[i], MON_DATA_SPATK_EV, &(partyData[i].ev[3]));
                SetMonData(&party[i], MON_DATA_SPDEF_EV, &(partyData[i].ev[4]));
                SetMonData(&party[i], MON_DATA_SPEED_EV, &(partyData[i].ev[5]));
            }
            if (partyData[i].ability != ABILITY_NONE)
            {
                const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[partyData[i].species];
                u32 maxAbilities = ARRAY_COUNT(speciesInfo->abilities);
                for (ability = 0; ability < maxAbilities; ++ability)
                {
                    if (speciesInfo->abilities[ability] == partyData[i].ability)
                        break;
                }
                if (ability >= maxAbilities)
                    ability = 0;
            }
            else if (B_TRAINER_MON_RANDOM_ABILITY)
            {
                const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[partyData[i].species];
                ability = personalityHash % 3;
                while (speciesInfo->abilities[ability] == ABILITY_NONE)
                {
                    ability--;
                }
            }
            SetMonData(&party[i], MON_DATA_ABILITY_NUM, &ability);
            SetMonData(&party[i], MON_DATA_FRIENDSHIP, &(partyData[i].friendship));
            if (partyData[i].ball != ITEM_NONE)
            {
                ball = partyData[i].ball;
                SetMonData(&party[i], MON_DATA_POKEBALL, &ball);
            }
            if (partyData[i].nickname != NULL)
            {
                SetMonData(&party[i], MON_DATA_NICKNAME, partyData[i].nickname);
            }
            if (partyData[i].isShiny)
            {
                u32 data = TRUE;
                SetMonData(&party[i], MON_DATA_IS_SHINY, &data);
            }
            CalculateMonStats(&party[i]);

            if (B_TRAINER_CLASS_POKE_BALLS >= GEN_7 && ball == -1)
            {
                ball = gTrainerClasses[trainer->trainerClass].ball ?: ITEM_POKE_BALL;
                SetMonData(&party[i], MON_DATA_POKEBALL, &ball);
            }
        }
    }

    return trainer->partySize;
}

static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer)
{
    u8 retVal;
    retVal = CreateNPCTrainerPartyFromTrainer(party, GetTrainerStructFromId(trainerNum), firstTrainer);
    return retVal;
}

void VBlankCB_Battle(void)
{
    AvanzaAleatoriedad();
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    IniciaTransferenciaDMAEnHblankDistorsionFondo();
}

void SpriteCB_VsLetterDummy(struct Sprite *sprite)
{
}

static void SpriteCB_VsLetter(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->x = sprite->data[1] + ((sprite->data[2] & 0xFF00) >> 8);
    else
        sprite->x = sprite->data[1] - ((sprite->data[2] & 0xFF00) >> 8);

    sprite->data[2] += 0x180;

    if (sprite->affineAnimEnded)
    {
        FreeSpriteTilesByTag(TAG_VS_LETTER);
        FreeSpritePaletteByTag(TAG_VS_LETTER);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void SpriteCB_VsLetterInit(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = SpriteCB_VsLetter;
    PlaySE(SE_MUGSHOT);
}

u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId)
{
    u32 ret = 0;

    switch (caseId)
    {
    case 0:
        ret = gBattleBgTemplates[arrayId].bg;
        break;
    case 1:
        ret = gBattleBgTemplates[arrayId].charBaseIndex;
        break;
    case 2:
        ret = gBattleBgTemplates[arrayId].mapBaseIndex;
        break;
    case 3:
        ret = gBattleBgTemplates[arrayId].screenSize;
        break;
    case 4:
        ret = gBattleBgTemplates[arrayId].paletteMode;
        break;
    case 5: // Only this case is used
        ret = gBattleBgTemplates[arrayId].priority;
        break;
    case 6:
        ret = gBattleBgTemplates[arrayId].baseTile;
        break;
    }

    return ret;
}

u32 GetBattleWindowTemplatePixelWidth(u32 tableId)
{
    return sBattleWindowTemplates[tableId].width * 8;
}

#define sBattler data[0]
#define sSpeciesId data[2]

void SpriteCB_WildMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_MoveWildMonToRight;
    StartSpriteAnimIfDifferent(sprite, 0);
    BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 10, RGB(8, 8, 8));
}

static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite)
{
    if ((gIntroSlideFlags & 1) == 0)
    {
        sprite->x2 += 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_WildMonShowHealthbox;
        }
    }
}

static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        StartHealthboxSlideIn(sprite->sBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[sprite->sBattler]);
        sprite->callback = SpriteCB_WildMonAnimate;
        StartSpriteAnimIfDifferent(sprite, 0);
        BeginNormalPaletteFade((0x10000 << sprite->sBattler), 0, 10, 0, RGB(8, 8, 8));
    }
}

static void SpriteCB_WildMonAnimate(struct Sprite *sprite)
{
    if (!gFundidoPaletas.activo)
    {
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, FALSE, 1);
    }
}

void SpriteCB_FaintOpponentMon(struct Sprite *sprite)
{
    u8 battler = sprite->sBattler;
    u16 species = sprite->sSpeciesId;
    u8 yOffset;

    species = SanitizeSpeciesId(species);
    yOffset = gSpeciesInfo[species].frontPicYOffset;

    sprite->data[3] = 8 - yOffset / 8;
    sprite->data[4] = 1;
    sprite->callback = SpriteCB_AnimFaintOpponent;
}

static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite)
{
    s32 i;

    if (--sprite->data[4] == 0)
    {
        sprite->data[4] = 2;
        sprite->y2 += 8; // Move the sprite down.
        if (--sprite->data[3] < 0)
        {
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
        else // Erase bottom part of the sprite to create a smooth illusion of mon falling down.
        {
            u8 *dst = &gMonSpritesGfxPtr->spritesGfx[sprite->sBattler][(sprite->data[3] << 8)];

            for (i = 0; i < 0x100; i++)
                *(dst++) = 0;

            StartSpriteAnim(sprite, 0);
        }
    }
}

// Used when selecting a move, which can hit multiple targets, in double battles.
void SpriteCB_ShowAsMoveTarget(struct Sprite *sprite)
{
    sprite->data[3] = 8;
    sprite->data[4] = sprite->invisible;
    sprite->callback = SpriteCB_BlinkVisible;
}

static void SpriteCB_BlinkVisible(struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->invisible ^= 1;
        sprite->data[3] = 8;
    }
}

void SpriteCB_HideAsMoveTarget(struct Sprite *sprite)
{
    sprite->invisible = sprite->data[4];
    sprite->data[4] = FALSE;
    sprite->callback = SpriteCallbackDummy;
}

void SpriteCB_OpponentMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAnim(sprite, 1);
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, TRUE, 1);
    }
}

// This callback is frequently overwritten by SpriteCB_TrainerSlideIn
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_BattleSpriteSlideLeft;
}

static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 -= 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_Idle;
            sprite->data[1] = 0;
        }
    }
}

static void SpriteCB_Idle(struct Sprite *sprite)
{
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void SpriteCB_FaintSlideAnim(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        sprite->y2 += sprite->sSpeedY;
    }
}

#undef sSpeedX
#undef sSpeedY

#define sSinIndex data[3]
#define sDelta data[4]
#define sAmplitude data[5]
#define sBouncerSpriteId data[6]
#define sWhich data[7]

void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude)
{
    u8 invisibleSpriteId;
    u8 bouncerSpriteId;

    switch (which)
    {
    case BOUNCE_HEALTHBOX:
    default:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;
        break;
    case BOUNCE_MON:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;
        break;
    }

    invisibleSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_BounceEffect);
    if (which == BOUNCE_HEALTHBOX)
    {
        bouncerSpriteId = gHealthboxSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 128; // 0
    }
    else
    {
        bouncerSpriteId = gBattlerSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 192; // -1
    }
    gSprites[invisibleSpriteId].sDelta = delta;
    gSprites[invisibleSpriteId].sAmplitude = amplitude;
    gSprites[invisibleSpriteId].sBouncerSpriteId = bouncerSpriteId;
    gSprites[invisibleSpriteId].sWhich = which;
    gSprites[invisibleSpriteId].sBattler = battler;
    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

void EndBounceEffect(u8 battler, u8 which)
{
    u8 bouncerSpriteId;

    if (which == BOUNCE_HEALTHBOX)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 0;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 0;
    }

    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

static void SpriteCB_BounceEffect(struct Sprite *sprite)
{
    u8 bouncerSpriteId = sprite->sBouncerSpriteId;
    s32 index = sprite->sSinIndex;
    s32 y = Sin(index, sprite->sAmplitude) + sprite->sAmplitude;

    gSprites[bouncerSpriteId].y2 = y;
    sprite->sSinIndex = (sprite->sSinIndex + sprite->sDelta) & 0xFF;
}

#undef sSinIndex
#undef sDelta
#undef sAmplitude
#undef sBouncerSpriteId
#undef sWhich

void SpriteCB_PlayerMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->sSpeciesId);
}

void SpriteCB_PlayerMonSlideIn(struct Sprite *sprite)
{
    if (sprite->data[3] == 0)
    {
        PlaySE(SE_BALL_TRAY_ENTER);
        sprite->data[3]++;
    }
    else if (sprite->data[3] == 1)
    {
        if (sprite->animEnded)
            return;
        sprite->data[4] = sprite->x;
        sprite->x = -33;
        sprite->invisible = FALSE;
        sprite->data[3]++;
    }
    else if (sprite->data[3] < 27)
    {
        sprite->x += 4;
        sprite->data[3]++;
    }
    else
    {
        sprite->data[3] = 0;
        sprite->x = sprite->data[4];
        sprite->data[4] = 0;
        sprite->callback = SpriteCB_PlayerMonFromBall;
        PlayCry_ByMode(sprite->sSpeciesId, -25, CRY_MODE_NORMAL);
    }
}

static void SpriteCB_TrainerThrowObject_Main(struct Sprite *sprite)
{
    AnimSetCenterToCornerVecX(sprite);
    if (sprite->animEnded)
        sprite->callback = SpriteCB_Idle;
}

// Sprite callback for a trainer back pic to throw an object
// (Wally throwing a ball, throwing Pokéblocks/balls in the Safari Zone)
void SpriteCB_TrainerThrowObject(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = SpriteCB_TrainerThrowObject_Main;
}

void AnimSetCenterToCornerVecX(struct Sprite *sprite)
{
    if (sprite->animDelayCounter == 0)
        sprite->centerToCornerVecX = sCenterToCornerVecXs[sprite->animCmdIndex];
}

void BeginBattleIntroDummy(void)
{
}

void BeginBattleIntro(void)
{
    BattleStartClearSetData();
    gPosicionCursorSiNo = CURSOR_SI;
    gCombate->estadoIntro = ESTADO_INTRO_BATALLA_OBTEN_DATOS_POKEMON;
    gBattleMainFunc = DoBattleIntro;
}

static void BattleMainCB1(void)
{
    u32 battler;

    gBattleMainFunc();
    for (battler = 0; battler < gBattlersCount; battler++)
        gBattlerControllerFuncs[battler](battler);
}

static void ClearSetBScriptingStruct(void)
{
    memset(&gBattleScripting, 0, sizeof(gBattleScripting));
}

static void BattleStartClearSetData(void)
{
    TurnValuesCleanUp(FALSE);
    SpecialStatusesClear();

    memset(&gDisableStructs, 0, sizeof(gDisableStructs));
    memset(&gFieldTimers, 0, sizeof(gFieldTimers));
    memset(&gSideStatuses, 0, sizeof(gSideStatuses));
    memset(&gSideTimers, 0, sizeof(gSideTimers));
    ClearSetBScriptingStruct();

    for (u32 combatiente = JUGADOR_IZQUIERDA; combatiente < NUMERO_COMBATIENTES; combatiente++)
    {
        gStatuses3[combatiente] = 0;
        gDisableStructs[combatiente].esPrimerTurno = TRUE;
        gLastMoves[combatiente] = MOVE_NONE;
        gLastLandedMoves[combatiente] = MOVE_NONE;
        gLastHitByType[combatiente] = 0;
        gLastUsedMoveType[combatiente] = 0;
        gLastResultingMoves[combatiente] = MOVE_NONE;
        gLastHitBy[combatiente] = 0xFF;
        gLockedMoves[combatiente] = MOVE_NONE;
        gLastPrintedMoves[combatiente] = MOVE_NONE;
        gBattleResources->flags[combatiente] = 0;
        gCombate->choicedMove[combatiente] = MOVE_NONE;
        gCombate->changedItems[combatiente] = 0;
        gCombate->AI_monToSwitchIntoId[combatiente] = PARTY_SIZE;
        gCombate->overwrittenAbilities[combatiente] = ABILITY_NONE;
        DesmarcaCombatienteOcupado[combatiente];
    }

    gLastUsedMove = 0;
    gFieldStatuses = 0;

    gLastUsedBall = 0;

    gBattlerAttacker = 0;
    gBattlerTarget = 0;
    gEffectBattler = 0;
    gBattlerAbility = 0;
    gCombate->clima.modo == CLIMA_COMBATE_NINGUNO;
    gHitMarker = 0;
    gCombate->contadorMultigolpes = 0;
    gBattleOutcome = 0;
    gPaydayMoney = 0;
    gBattleResources->battleScriptsStack->size = 0;
    gBattleResources->battleCallbackStack->size = 0;

    for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
        gBattleCommunication[i] = 0;

    gPauseCounterBattle = 0;
    gBattleMoveDamage = 0;
    gIntroSlideFlags = 0;
    gLeveledUpInBattle = 0;
    gAbsentBattlerFlags = 0;
    gCombate->moneyMultiplier = 1;

    gCombate->givenExpMons = 0;

    for (i = 0; i < ARRAY_COUNT(gSideTimers); i++)
    {
        gSideTimers[i].stickyWebBattlerId = 0xFF;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gCombate->usedHeldItems[i][LADO_JUGADOR] = 0;
        gCombate->usedHeldItems[i][LADO_OPONENTE] = 0;
        gCombate->objetoPerdido[LADO_JUGADOR][i] = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
        gCombate->objetoPerdido[LADO_OPONENTE][i] = GetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM);
    }

    gSelectedMonPartyId = PARTY_SIZE; // Revival Blessing
    gCategoryIconSpriteId = 0xFF;
}

static void ReseteaAcciones(u32 combatiente)
{
    gAccionElegida[combatiente] = B_ACTION_NONE;
    gMovimientoElegido[combatiente] = MOVE_NONE;
    gEstadoAccion[combatiente] = ANTES_ACCION;
}

void SwitchInClearSetData(u32 battler)
{
    s32 i;
    struct DisableStruct disableStructCopy = gDisableStructs[battler];

    if (gMovimientos[gCurrentMove].effect != EFECTO_RELEVO)
    {
        for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
            gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA;
        for (i = 0; i < gBattlersCount; i++)
        {
            if ((gBattleMons[i].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[i].battlerPreventingEscape == battler)
                gBattleMons[i].status2 &= ~STATUS2_ESCAPE_PREVENTION;
            if ((gStatuses3[i] & STATUS3_ALWAYS_HITS) && gDisableStructs[i].battlerWithSureHit == battler)
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gDisableStructs[i].battlerWithSureHit = 0;
            }
        }
    }
    if (gMovimientos[gCurrentMove].effect == EFECTO_RELEVO)
    {
        gBattleMons[battler].status2 &= (STATUS2_CONFUSION | STATUS2_SUBSTITUTE | STATUS2_ESCAPE_PREVENTION | STATUS2_CURSED);
        gStatuses3[battler] &= (STATUS3_LEECHSEED_BATTLER | STATUS3_LEECHSEED | STATUS3_ALWAYS_HITS | STATUS3_PERISH_SONG | STATUS3_ROOTED | STATUS3_GASTRO_ACID | STATUS3_EMBARGO | STATUS3_TELEKINESIS | STATUS3_MAGNET_RISE | STATUS3_AQUA_RING | STATUS3_POWER_TRICK);
        for (i = 0; i < gBattlersCount; i++)
        {
            if (GetBattlerSide(battler) != GetBattlerSide(i) && (gStatuses3[i] & STATUS3_ALWAYS_HITS) != 0 && (gDisableStructs[i].battlerWithSureHit == battler))
            {
                gStatuses3[i] &= ~STATUS3_ALWAYS_HITS;
                gStatuses3[i] |= STATUS3_ALWAYS_HITS_TURN(2);
            }
        }
        if (gStatuses3[battler] & STATUS3_POWER_TRICK)
            SWAP(gBattleMons[battler].attack, gBattleMons[battler].defense, i);
    }
    else
    {
        gBattleMons[battler].status2 = 0;
        gStatuses3[battler] = 0;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].status2 & STATUS2_INFATUATED_WITH(battler))
            gBattleMons[i].status2 &= ~STATUS2_INFATUATED_WITH(battler);
        if ((gBattleMons[i].status2 & STATUS2_WRAPPED) && *(gCombate->wrappedBy + i) == battler)
            gBattleMons[i].status2 &= ~STATUS2_WRAPPED;
    }

    gActionSelectionCursor[battler] = 0;
    gMoveSelectionCursor[battler] = 0;

    memset(&gDisableStructs[battler], 0, sizeof(struct DisableStruct));

    if (gMovimientos[gCurrentMove].effect == EFECTO_RELEVO)
    {
        gDisableStructs[battler].substituteHP = disableStructCopy.substituteHP;
        gDisableStructs[battler].battlerWithSureHit = disableStructCopy.battlerWithSureHit;
        gDisableStructs[battler].perishSongTimer = disableStructCopy.perishSongTimer;
        gDisableStructs[battler].battlerPreventingEscape = disableStructCopy.battlerPreventingEscape;
        gDisableStructs[battler].embargoTimer = disableStructCopy.embargoTimer;
    }

    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    gDisableStructs[battler].esPrimerTurno = TRUE;
    gLastMoves[battler] = MOVE_NONE;
    gLastLandedMoves[battler] = MOVE_NONE;
    gLastHitByType[battler] = 0;
    gLastUsedMoveType[battler] = 0;
    gLastResultingMoves[battler] = MOVE_NONE;
    gLastPrintedMoves[battler] = MOVE_NONE;
    gLastHitBy[battler] = 0xFF;
    gCombate->sameMoveTurns[battler] = 0;

    for (i = 0; i < ARRAY_COUNT(gSideTimers); i++)
    {
        // Switched into sticky web user slot, so reset stored battler ID
        if (gSideTimers[i].stickyWebBattlerId == battler)
            gSideTimers[i].stickyWebBattlerId = 0xFF;
    }

    gCombate->choicedMove[battler] = MOVE_NONE;
    gBattleResources->flags[battler] = 0;
    gCurrentMove = MOVE_NONE;

    // Reset damage to prevent things like red card activating if the switched-in mon is holding it
    gCombate[battler].danioRecibido = 0;

    // Reset Eject Button / Eject Pack switch detection
    AI_DATA->ejectButtonSwitch = FALSE;
    AI_DATA->ejectPackSwitch = FALSE;

    gCombate->overwrittenAbilities[battler] = ABILITY_NONE;

    // Clear selected party ID so Revival Blessing doesn't get confused.
    gSelectedMonPartyId = PARTY_SIZE;

    AI_UpdateSwitchInData(battler);
}

const u8 *FaintClearSetData(u32 combatiente)
{
    const u8 *result = NULL;
    u32 ladoCombatiente = GetBattlerSide(combatiente);

    for (u32 indiceEstadistica = 0; indiceEstadistica < NUMERO_ESTADISTICAS_BATALLA; indiceEstadistica++)
        gBattleMons[combatiente].statStages[indiceEstadistica] = ESTADISTICA_NEUTRA;

    gBattleMons[combatiente].status2 = 0;
    gStatuses3[combatiente] &= STATUS3_GASTRO_ACID; // Edge case: Keep Gastro Acid if pokemon's ability can have effect after fainting, for example Innards Out.

    for (u32 indiceCombatiente = JUGADOR_IZQUIERDA; indiceCombatiente < gBattlersCount; indiceCombatiente++)
    {
        if ((gBattleMons[indiceCombatiente].status2 & STATUS2_ESCAPE_PREVENTION) && gDisableStructs[indiceCombatiente].battlerPreventingEscape == combatiente)
            gBattleMons[indiceCombatiente].status2 &= ~STATUS2_ESCAPE_PREVENTION;

        if (gBattleMons[indiceCombatiente].status2 & STATUS2_INFATUATED_WITH(combatiente))
            gBattleMons[indiceCombatiente].status2 &= ~STATUS2_INFATUATED_WITH(combatiente);

        if ((gBattleMons[indiceCombatiente].status2 & STATUS2_WRAPPED) && gCombate->wrappedBy[indiceCombatiente] == combatiente)
            gBattleMons[indiceCombatiente].status2 &= ~STATUS2_WRAPPED;
    }

    gActionSelectionCursor[combatiente] = 0;
    gMoveSelectionCursor[combatiente] = 0;

    memset(&gDisableStructs[combatiente], 0, sizeof(struct DisableStruct));

    gProtectStructs[combatiente].protected = FALSE;
    gProtectStructs[combatiente].spikyShielded = FALSE;
    gProtectStructs[combatiente].silkTrapped = FALSE;
    gProtectStructs[combatiente].noValidMoves = FALSE;
    gProtectStructs[combatiente].stealMove = FALSE;
    gProtectStructs[combatiente].prlzImmobility = FALSE;
    gProtectStructs[combatiente].sleepImmobility = FALSE;
    gProtectStructs[combatiente].confusionSelfDmg = FALSE;
    gProtectStructs[combatiente].targetAffected = FALSE;
    gProtectStructs[combatiente].chargingTurn = FALSE;
    gProtectStructs[combatiente].usedImprisonedMove = FALSE;
    gProtectStructs[combatiente].loveImmobility = FALSE;
    gProtectStructs[combatiente].usedDisabledMove = FALSE;
    gProtectStructs[combatiente].usedTauntedMove = FALSE;
    gProtectStructs[combatiente].flinchImmobility = FALSE;
    gProtectStructs[combatiente].notFirstStrike = FALSE;
    gProtectStructs[combatiente].usedGravityPreventedMove = FALSE;
    gProtectStructs[combatiente].usedThroatChopPreventedMove = FALSE;
    gProtectStructs[combatiente].statRaised = FALSE;
    gProtectStructs[combatiente].statFell = FALSE;
    gProtectStructs[combatiente].prioridadBromista = FALSE;

    gDisableStructs[combatiente].esPrimerTurno = TRUE;

    gLastMoves[combatiente] = MOVE_NONE;
    gLastLandedMoves[combatiente] = MOVE_NONE;
    gLastHitByType[combatiente] = 0;
    gLastUsedMoveType[combatiente] = 0;
    gLastResultingMoves[combatiente] = MOVE_NONE;
    gLastPrintedMoves[combatiente] = MOVE_NONE;
    gLastHitBy[combatiente] = 0xFF;

    gCombate->choicedMove[combatiente] = MOVE_NONE;
    gCombate->sameMoveTurns[combatiente] = 0;

    for (u32 indiceLado = 0; indiceLado < ARRAY_COUNT(gSideTimers); indiceLado++)
    {
        // User of sticky web fainted, so reset the stored battler ID
        if (gSideTimers[indiceLado].stickyWebBattlerId == combatiente)
            gSideTimers[indiceLado].stickyWebBattlerId = 0xFF;
    }

    gBattleResources->flags[combatiente] = 0;

    gBattleMons[combatiente].types[TIPO_1] = gSpeciesInfo[gBattleMons[combatiente].species].types[TIPO_1];
    gBattleMons[combatiente].types[TIPO_2] = gSpeciesInfo[gBattleMons[combatiente].species].types[TIPO_2];

    AI_UpdateFaintData(combatiente);
    TryBattleFormChange(combatiente, FORM_CHANGE_FAINT);

    gCombate->overwrittenAbilities[combatiente] = ABILITY_NONE;

    return result;
}

static void DoBattleIntro(void)
{
    s32 i;
    u32 battler;

    switch (gCombate->estadoIntro)
    {
    case ESTADO_INTRO_BATALLA_OBTEN_DATOS_POKEMON:
        battler = gPosicionCursorSiNo // REVISAR;
            BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, 0);
        MarcaCombatienteOcupado(battler);
        gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_PREPARA_DESLIZAMIENTO_FONDO:
        if (!HayAlgunCombatienteOcupado())
        {
            battler = 0;
            BtlController_EmitIntroSlide(battler, BUFFER_A, gBattleTerrain);
            MarcaCombatienteOcupado(battler);
            gBattleCommunication[MULTIUSE_STATE] = 0;
            gPosicionCursorSiNo = 0; // REVISAR
            gCombate->estadoIntro++;
        }
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_DESLIZAMIENTO_FONDO:
        if (!HayAlgunCombatienteOcupado())
            gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_DIBUJA_SPRITES:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            memcpy(&gBattleMons[battler], &gBattleResources->bufferB[battler][4], sizeof(struct BattlePokemon));
            gBattleMons[battler].types[TIPO_1] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_1];
            gBattleMons[battler].types[TIPO_2] = gSpeciesInfo[gBattleMons[battler].species].types[TIPO_2];
            gBattleMons[battler].ability = GetAbilityBySpecies(gBattleMons[battler].species, gBattleMons[battler].abilityNum);
            gCombate->hpOnSwitchout[GetBattlerSide(battler)] = gBattleMons[battler].hp;
            gBattleMons[battler].status2 = 0; // AQUÍ SE REINICIA STATUS 2 AL ENTRAR EN COMBATE
            for (i = 0; i < NUMERO_ESTADISTICAS_BATALLA; i++)
                gBattleMons[battler].statStages[i] = ESTADISTICA_NEUTRA;

            // Draw sprite.
            switch (battler)
            {
            case JUGADOR_IZQUIERDA: // player sprite
                BtlController_EmitDrawTrainerPic(battler, BUFFER_A);
                MarcaCombatienteOcupado(battler);
                break;
            case OPONENTE_IZQUIERDA:
                if (EsCombateContraEntrenador(gCombate->tipoCombate)) // opponent 1 sprite
                {
                    BtlController_EmitDrawTrainerPic(battler, BUFFER_A);
                    MarcaCombatienteOcupado(battler);
                }
                else // wild mon 1
                {
                    BtlController_EmitLoadMonSprite(battler, BUFFER_A);
                    MarcaCombatienteOcupado(battler);
                }
                break;
            case JUGADOR_DERECHA:
            case OPONENTE_DERECHA:
                break;
            }
        }

        if (EsCombateContraEntrenador(gCombate->tipoCombate))
            gCombate->estadoIntro++;
        else                                                            // Skip party summary since it is a wild battle.
            gCombate->estadoIntro = ESTADO_INTRO_BATALLA_TEXTO_INICIAL; // Don't wait for sprite, print message at the same time.
        break;
    case ESTADO_INTRO_BATALLA_DIBUJA_SUMARIO_EQUIPO:
        if (!HayAlgunCombatienteOcupado())
        {
            struct HpAndStatus hpStatus[PARTY_SIZE];

            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE || GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
                {
                    hpStatus[i].hp = HP_EMPTY_SLOT;
                    hpStatus[i].status = 0;
                }
                else
                {
                    hpStatus[i].hp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                    hpStatus[i].status = GetMonData(&gEnemyParty[i], MON_DATA_STATUS);
                }
            }

            battler = OPONENTE_IZQUIERDA;
            BtlController_EmitDrawPartyStatusSummary(battler, BUFFER_A, hpStatus, PARTY_SUMM_SKIP_DRAW_DELAY);
            MarcaCombatienteOcupado(battler);

            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE || GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
                {
                    hpStatus[i].hp = HP_EMPTY_SLOT;
                    hpStatus[i].status = 0;
                }
                else
                {
                    hpStatus[i].hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                    hpStatus[i].status = GetMonData(&gPlayerParty[i], MON_DATA_STATUS);
                }
            }

            battler = JUGADOR_IZQUIERDA;
            BtlController_EmitDrawPartyStatusSummary(battler, BUFFER_A, hpStatus, PARTY_SUMM_SKIP_DRAW_DELAY);
            MarcaCombatienteOcupado(battler);

            gCombate->estadoIntro++;
        }
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_SUMARIO_EQUIPO:
        if (!HayAlgunCombatienteOcupado())
            gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_TEXTO_INICIAL:
        if (!EstaCombatienteOcupado[JUGADOR_IZQUIERDA])
        {
            PrepareStringBattle(TEXTO_COMBATE_INTRO, JUGADOR_IZQUIERDA);
            gCombate->estadoIntro++;
        }
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_TEXTO_INICIAL:
        if (!EstaCombatienteOcupado[JUGADOR_IZQUIERDA])
        {
            if (EsCombateContraEntrenador(gCombate->tipoCombate))
            {
                gCombate->estadoIntro++;
            }
            else
                gCombate->estadoIntro = ESTADO_INTRO_BATALLA_ESPERA_TEXTO_COMBATE_SALVAJE;
        }
        break;
    case ESTADO_INTRO_BATALLA_TEXTO_ENTRENADOR:
        PrepareStringBattle(TEXTO_COMBATE_ENVIAR_POKEMON, OPONENTE_IZQUIERDA);
        gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_TEXTO_ENTRENADOR:
        if (!HayAlgunCombatienteOcupado())
            gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_ANIMACION_ENVIAR_POKEMON:
        battler = OPONENTE_IZQUIERDA;
        BtlController_EmitIntroTrainerBallThrow(battler, BUFFER_A);
        MarcaCombatienteOcupado(battler);
        gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_TEXTO_COMBATE_SALVAJE:
        if (!EstaCombatienteOcupado[JUGADOR_IZQUIERDA])
            gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_TEXTO_COMBATE_ENTRADA_JUGADOR:
        battler = JUGADOR_IZQUIERDA;
        // A hack that makes fast intro work in trainer battles too.
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && gSprites[gHealthboxSpriteIds[battler ^ BIT_SIDE]].callback == SpriteCallbackDummy)
        {
            return;
        }
        PrepareStringBattle(TEXTO_COMBATE_ENVIAR_POKEMON, battler);
        BtlController_EmitIntroTrainerBallThrow(battler, BUFFER_A);
        MarcaCombatienteOcupado(battler);
        gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_ESPERA_TEXTO_COMBATE_ENTRADA_JUGADOR:
        battler = JUGADOR_IZQUIERDA;
        if (!EstaCombatienteOcupado(battler))
            gCombate->estadoIntro++;
        break;
    case ESTADO_INTRO_BATALLA_PREPARA_VARS:
        if (!HayAlgunCombatienteOcupado())
        {
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (GetBattlerSide(battler) == LADO_OPONENTE)
                {
                    HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[battler].species), FLAG_SET_SEEN);
                }
            }
            gCombate->eventsBeforeFirstTurnState = 0;
            gCombate->switchInBattlerCounter = 0;
            AI_InitPartyStruct(); // Save mons party counts, and first 2/4 mons on the battlefield.
            gBattleMainFunc = TryDoEventsBeforeFirstTurn;
        }
        break;
    }
}

static void TryDoEventsBeforeFirstTurn(void)
{
    s32 i, j;

    if (HayAlgunCombatienteOcupado())
        return;

    switch (gCombate->eventsBeforeFirstTurnState)
    {
    case FIRST_TURN_EVENTS_START:
        // Set invalid mons as absent(for example when starting a double battle with only one pokemon).
        for (i = 0; i < gBattlersCount; i++)
        {
            struct Pokemon *party = GetBattlerParty(i);
            struct Pokemon *mon = &party[gBattlerPartyIndexes[i]];
            if (!IsBattlerAlive(i) || gBattleMons[i].species == SPECIES_NONE || GetMonData(mon, MON_DATA_IS_EGG))
                gAbsentBattlerFlags |= 1u << i;
        }

        gCombate->speedTieBreaks = ElementoAleatorio(Factorial(NUMERO_COMBATIENTES));

        for (i = 0; i < gBattlersCount; i++)
            gBattlerByTurnOrder[i] = i;
        for (i = 0; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                if (GetWhichBattlerFaster(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], TRUE) == -1)
                    SwapTurnOrder(i, j);
            }
        }
        gCombate->eventsBeforeFirstTurnState++;
        break;
    case FIRST_TURN_EVENTS_NEUTRALIZING_GAS:
        if (AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, 0, 0, 0, 0) != 0)
            return;
        gCombate->eventsBeforeFirstTurnState++;
        break;
    case FIRST_TURN_EVENTS_SWITCH_IN_ABILITIES:
        while (gCombate->switchInBattlerCounter < gBattlersCount) // From fastest to slowest
        {
            i = gBattlerByTurnOrder[gCombate->switchInBattlerCounter++];

            if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, i, 0, 0, 0) != 0)
                return;
        }
        gCombate->switchInBattlerCounter = 0;
        gCombate->eventsBeforeFirstTurnState++;
        break;
    case FIRST_TURN_EVENTS_ITEM_EFFECTS:
        while (gCombate->switchInBattlerCounter < gBattlersCount) // From fastest to slowest
        {
            if (ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, gBattlerByTurnOrder[gCombate->switchInBattlerCounter++], FALSE))
                return;
        }
        gCombate->switchInBattlerCounter = 0;
        gCombate->eventsBeforeFirstTurnState++;
        break;
    case FIRST_TURN_EVENTS_END:
        for (i = 0; i < NUMERO_COMBATIENTES; i++)
        {
            *(gCombate->monToSwitchIntoId + i) = PARTY_SIZE;
            ReseteaAcciones(i);
        }
        TurnValuesCleanUp(FALSE);
        SpecialStatusesClear();
        gCombate->absentBattlerFlags = gAbsentBattlerFlags;
        BattlePutTextOnWindow(gText_EmptyString, B_WIN_MSG);
        gBattleMainFunc = GestionaEstadoSeleccionAccionesTurno;
        ResetSentPokesToOpponentValue();

        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;

        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].status2 &= ~STATUS2_FLINCHED;
            gCombate->potenciaMovimientosRecibidosTurno[i] = 0;
        }

        gCombate->efectoFinTurno.individual = ENDTURN_WEATHER_DAMAGE;
        gCombate->gCombate->efectoFinTurno.indiceCombatiente = JUGADOR_IZQUIERDA;
        gCombate->perishSongState = 0;
        gCombate->perishSongBattlerId = 0;
        gBattleScripting.moveendState = 0;
        gCombate->faintedActionsState = 0;
        gCombate->efectoFinTurno.campo = FIN_TURNO_ORDEN;
        gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;

        SetAILogicDataForTurn(AI_DATA); // get assumed abilities, hold effects, etc of all battlers

        if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_BEFORE_FIRST_TURN)))
            BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
        gCombate->eventsBeforeFirstTurnState = 0;
        break;
    }
}

static void HandleEndTurn_ContinueBattle(void)
{
    s32 i;

    if (!HayAlgunCombatienteOcupado())
    {
        gBattleMainFunc = BattleTurnPassed;
        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].status2 &= ~STATUS2_FLINCHED;
            if ((gBattleMons[i].status1 & STATUS1_SLEEP) && (gBattleMons[i].status2 & STATUS2_MULTIPLETURNS))
                CancelMultiTurnMoves(i);
        }
        gCombate->efectoFinTurno.individual = ENDTURN_WEATHER_DAMAGE;
        gCombate->gCombate->efectoFinTurno.indiceCombatiente = JUGADOR_IZQUIERDA;
        gCombate->perishSongState = 0;
        gCombate->perishSongBattlerId = 0;
        gCombate->efectoFinTurno.campo = FIN_TURNO_ORDEN;
        gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;
    }
}

void BattleTurnPassed(void)
{
    s32 i;

    gCombate->speedTieBreaks = ElementoAleatorio(Factorial(NUMERO_COMBATIENTES));

    TurnValuesCleanUp(TRUE);
    if (gBattleOutcome == 0)
    {
        if (DoFieldEndTurnEffects())
            return;
        if (DoBattlerEndTurnEffects())
            return;
    }
    if (HandleWishPerishSongOnTurnEnd())
        return;
    if (HandleFaintedMonActions())
        return;
    gCombate->faintedActionsState = 0;

    TurnValuesCleanUp(FALSE);
    gHitMarker &= ~HITMARKER_NO_ATTACKSTRING;
    gHitMarker &= ~HITMARKER_UNABLE_TO_USE_MOVE;
    gHitMarker &= ~HITMARKER_PLAYER_FAINTED;
    gHitMarker &= ~HITMARKER_PASSIVE_DAMAGE;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleScripting.moveendState = 0;
    gBattleMoveDamage = 0;
    gCombate->resultadoMovimiento = MOVIMIENTO_NEUTRO;

    for (i = 0; i < 5; i++)
        gBattleCommunication[i] = 0;

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        gBattleMainFunc = RunTurnActionsFunctions;
        return;
    }

    gCombate->contadorTurnos++;

    for (i = 0; i < gBattlersCount; i++)
    {
        ReseteaAcciones(i);
    }

    for (i = 0; i < NUMERO_COMBATIENTES; i++)
        *(gCombate->monToSwitchIntoId + i) = PARTY_SIZE;

    gCombate->absentBattlerFlags = gAbsentBattlerFlags;
    BattlePutTextOnWindow(gText_EmptyString, B_WIN_MSG);
    SetAILogicDataForTurn(AI_DATA); // get assumed abilities, hold effects, etc of all battlers

    for (i = 0; i < gBattlersCount; i++)
        {
            gCombate->potenciaMovimientosRecibidosTurno[i] = 0;
        }

    gBattleMainFunc = GestionaEstadoSeleccionAccionesTurno;

    if (gSideTimers[LADO_JUGADOR].retaliateTimer > 0)
        gSideTimers[LADO_JUGADOR].retaliateTimer--;
    if (gSideTimers[LADO_OPONENTE].retaliateTimer > 0)
        gSideTimers[LADO_OPONENTE].retaliateTimer--;

    if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_LAST_LOW_HP)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
    else if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_LAST_HALF_HP)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
    else if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_FIRST_CRITICAL_HIT)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
    else if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_FIRST_SUPER_EFFECTIVE_HIT)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
    else if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_FIRST_STAB_MOVE)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
    else if ((i = ShouldDoTrainerSlide(OPONENTE_IZQUIERDA, TRAINER_SLIDE_PLAYER_MON_UNAFFECTED)))
        BattleScriptExecute(BattleScript_TrainerSlideMsgRet);
}

void SwitchTwoBattlersInParty(u32 battler, u32 battler2)
{
    s32 i;
    u32 partyId1, partyId2;

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8 *)(gCombate->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler2]);
    SwitchPartyMonSlots(partyId1, partyId2);

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
    {
        *(battler * 3 + i + (u8 *)(gCombate->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        *(ALIADO(battler) * 3 + i + (u8 *)(gCombate->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
    }
}

void SwitchPartyOrder(u32 battler)
{
    s32 i;
    u32 partyId1, partyId2;

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8 *)(gCombate->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(*(gCombate->monToSwitchIntoId + battler));
    SwitchPartyMonSlots(partyId1, partyId2);

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gCombate->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
            *(ALIADO(battler) * 3 + i + (u8 *)(gCombate->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
    else
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gCombate->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
}

enum EstadosAccionTurno
{
    ANTES_ACCION,
    PROCESA_ACCION,
    ESPERA_ACCION,
    EJECUTA_ACCION,
};

static void HazCalculosIA(u32 combatiente)
{
    if (!CombatienteEsIA(combatiente))
        return;
    u32 isAIRisky = AI_THINKING_STRUCT->aiFlags[combatiente] & AI_FLAG_RISKY; // Risky AI switches aggressively even mid battle

    // Do AI score computations here so we can use them in AI_TrySwitchOrUseItem
    AI_DATA->aiCalcInProgress = TRUE;

    // Setup battler data
    sBattler_AI = combatiente;
    BattleAI_SetupAIData(15, sBattler_AI);

    // Setup switching data
    AI_DATA->mostSuitableMonId[combatiente] = GetMostSuitableMonToSwitchInto(combatiente, isAIRisky);
    if (ShouldSwitch(combatiente))
        AI_DATA->shouldSwitch |= (1u << combatiente);

    // Do scoring
    gCombate->IA_Eleccion[combatiente] = BattleAI_ChooseMoveOrAction();
    AI_DATA->aiCalcInProgress = FALSE;
}

static void GestionaEstadoSeleccionAccionesTurno(void)
{
    for (u32 combatiente = JUGADOR_IZQUIERDA; combatiente < gBattlersCount; combatiente++)
    {
        switch (gEstadoAccion[combatiente])
        {
        case ANTES_ACCION:
            HazCalculosIA(combatiente);
            *(gCombate->monToSwitchIntoId + combatiente) = PARTY_SIZE;
            if ((combatiente & BIT_FLANK) == FLANCO_IZQUIERDO || gCombate->absentBattlerFlags & (1u << ALIADO(combatiente)) || gEstadoAccion[ALIADO(combatiente)] == EJECUTA_ACCION)
            {
                if ((gCombate->absentBattlerFlags & (1u << combatiente)))
                {
                    gAccionElegida[combatiente] = B_ACTION_NOTHING_FAINTED;
                    gEstadoAccion[combatiente] = EJECUTA_ACCION;
                }
                else
                {
                    if (gBattleMons[combatiente].status2 & STATUS2_MULTIPLETURNS || gBattleMons[combatiente].status2 & STATUS2_RECHARGE)
                    {
                        gAccionElegida[combatiente] = B_ACTION_USE_MOVE;
                        gEstadoAccion[combatiente] = EJECUTA_ACCION;
                    }
                    else
                    {
                        gCombate->itemPartyIndex[combatiente] = PARTY_SIZE;
                        BtlController_EmitChooseAction(combatiente, BUFFER_A, gAccionElegida[combatiente]);
                        MarcaCombatienteOcupado(combatiente);
                        gEstadoAccion[combatiente] = PROCESA_ACCION;
                    }
                }
            }
            break;
        case PROCESA_ACCION:
            if (!EstaCombatienteOcupado(combatiente))
            {
                gAccionElegida[combatiente] = gBattleResources->bufferB[combatiente][1];
                switch (gBattleResources->bufferB[combatiente][1])
                {
                case B_ACTION_USE_MOVE:
                    if (AreAllMovesUnusable(combatiente))
                    {
                        gEstadoAccion[combatiente] = EJECUTA_ACCION;
                        *(gCombate->selectionScriptFinished + combatiente) = FALSE;
                        *(gCombate->stateIdAfterSelScript + combatiente) = EJECUTA_ACCION;
                        *(gCombate->moveTarget + combatiente) = gBattleResources->bufferB[combatiente][3];
                        return;
                    }
                    else if (gDisableStructs[combatiente].encoredMove != 0)
                    {
                        gMovimientoElegido[combatiente] = gDisableStructs[combatiente].encoredMove;
                        *(gCombate->chosenMovePositions + combatiente) = gDisableStructs[combatiente].encoredMovePos;
                        gEstadoAccion[combatiente] = EJECUTA_ACCION;
                        return;
                    }
                    else
                    {
                        for (u32 indiceMovimiento = 0; indiceMovimiento < MAXIMO_MOVIMIENTOS_POKEMON; indiceMovimiento++)
                        {
                            moveInfo.movimiento[indiceMovimiento] = gBattleMons[combatiente].moves[indiceMovimiento];
                            moveInfo.pp[indiceMovimiento] = gBattleMons[combatiente].pp[indiceMovimiento];
                        }

                        BtlController_EmitChooseMove(combatiente, BUFFER_A, EsCombateContraEntrenador(gCombate->tipoCombate), FALSE, &moveInfo);
                        MarcaCombatienteOcupado(combatiente);
                    }
                    break;
                case B_ACTION_SWITCH:
                {
                    u32 aliado = ALIADO(combatiente);

                    *(gCombate->battlerPartyIndexes + combatiente) = gBattlerPartyIndexes[combatiente];

                    if (ItemId_GetHoldEffect(gBattleMons[combatiente].item) != HOLD_EFFECT_SHED_SHELL && HabilidadImpideCambiar(combatiente))
                    {
                        BtlController_EmitChoosePokemon(
                            combatiente,
                            BUFFER_A,
                            PARTY_ACTION_ABILITY_PREVENTS,
                            PARTY_SIZE,
                            ABILITY_NONE,
                            gCombate->battlerPartyOrders[combatiente]);
                    }
                    else
                    {
                        u32 monAliado = PARTY_SIZE; // revisar

                        if (gAccionElegida[aliado] == B_ACTION_SWITCH)
                            monAliado = gCombate->monToSwitchIntoId[aliado];

                        BtlController_EmitChoosePokemon(
                            combatiente,
                            BUFFER_A,
                            PARTY_ACTION_CHOOSE_MON,
                            monAliado,
                            ABILITY_NONE,
                            gCombate->battlerPartyOrders[combatiente]);
                    }
                    MarcaCombatienteOcupado(combatiente);
                    break;
                }
                case B_ACTION_CANCEL_PARTNER:
                    gEstadoAccion[combatiente] = ANTES_ACCION;
                    gEstadoAccion[ALIADO(combatiente)] = ANTES_ACCION;
                    if (gBattleMons[ALIADO(combatiente)].status2 & STATUS2_MULTIPLETURNS || gBattleMons[ALIADO(combatiente)].status2 & STATUS2_RECHARGE)
                    {
                        BtlController_EmitEndBounceEffect(combatiente, BUFFER_A);
                        MarcaCombatienteOcupado(combatiente);
                        return;
                    }

                    BtlController_EmitEndBounceEffect(combatiente, BUFFER_A);
                    MarcaCombatienteOcupado(combatiente);
                    return;
                case B_ACTION_DEBUG:
                    BtlController_EmitDebugMenu(combatiente, BUFFER_A);
                    MarcaCombatienteOcupado(combatiente);
                    break;
                }

                if (EsCombateContraEntrenador(gCombate->tipoCombate) && gBattleResources->bufferB[combatiente][1] == B_ACTION_RUN)
                {
                    BattleScriptExecute(BattleScript_PrintCantRunFromTrainer);
                    gEstadoAccion[combatiente] = ANTES_ACCION;
                }
                else
                {
                    gEstadoAccion[combatiente] = ESPERA_ACCION;
                }
            }
            break;
        case ESPERA_ACCION: // Revisar
            if (!EstaCombatienteOcupado(combatiente))
            {
                switch (gAccionElegida[combatiente])
                {
                case B_ACTION_USE_MOVE:
                    switch (gBattleResources->bufferB[combatiente][1])
                    {
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        gAccionElegida[combatiente] = gBattleResources->bufferB[combatiente][1];
                        return;
                    case 15:
                        gAccionElegida[combatiente] = B_ACTION_SWITCH;
                        UpdateBattlerPartyOrdersOnSwitch(combatiente);
                        return;
                    default:
                        if ((gBattleResources->bufferB[combatiente][2] | (gBattleResources->bufferB[combatiente][3] << 8)) == 0xFFFF)
                        {
                            gEstadoAccion[combatiente] = ANTES_ACCION;
                        }
                        else if (TrySetCantSelectMoveBattleScript(combatiente))
                        {
                            gEstadoAccion[combatiente] = EJECUTA_ACCION;
                            *(gCombate->selectionScriptFinished + combatiente) = FALSE;
                            gBattleResources->bufferB[combatiente][1] = B_ACTION_USE_MOVE;
                            *(gCombate->stateIdAfterSelScript + combatiente) = PROCESA_ACCION;
                            return;
                        }
                        else
                        {
                            // Get the chosen move position (and thus the chosen move) and target from the returned buffer.
                            gCombate->chosenMovePositions[combatiente] = gBattleResources->bufferB[combatiente][2];
                            gMovimientoElegido[combatiente] = gBattleMons[combatiente].moves[gCombate->chosenMovePositions[combatiente]];
                            gCombate->moveTarget[combatiente] = gBattleResources->bufferB[combatiente][3];
                            gEstadoAccion[combatiente] = EJECUTA_ACCION;
                        }
                        break;
                    }
                    break;
                case B_ACTION_SWITCH:
                    if (gBattleResources->bufferB[combatiente][1] == PARTY_SIZE)
                    {
                        gEstadoAccion[combatiente] = ANTES_ACCION;
                    }
                    else
                    {
                        UpdateBattlerPartyOrdersOnSwitch(combatiente);
                        gEstadoAccion[combatiente] = EJECUTA_ACCION;
                    }
                    break;
                case B_ACTION_RUN:
                    gHitMarker |= HITMARKER_RUN;
                    gEstadoAccion[combatiente] = EJECUTA_ACCION;
                    break;
                case B_ACTION_THROW_BALL:
                    gEstadoAccion[combatiente] = EJECUTA_ACCION;
                    break;
                case B_ACTION_DEBUG:
                    gEstadoAccion[combatiente] = ANTES_ACCION;
                    break;
                }
            }
            break;
        case EJECUTA_ACCION:
            if (*(gCombate->selectionScriptFinished + combatiente))
            {
                gEstadoAccion[combatiente] = *(gCombate->stateIdAfterSelScript + combatiente);
            }
            else
            {
                gBattlerAttacker = combatiente;
                gBattlescriptCurrInstr = gSelectionBattleScripts[combatiente];
                if (!EstaCombatienteOcupado(combatiente))
                {
                    gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
                }
                gSelectionBattleScripts[combatiente] = gBattlescriptCurrInstr;
            }
            break;
        }
    }

    if (!HayAlgunCombatienteOcupado())
    {
        gBattleMainFunc = SetActionsAndBattlersTurnOrder;
    }
}

static void UpdateBattlerPartyOrdersOnSwitch(u32 battler)
{
    gCombate->monToSwitchIntoId[battler] = gBattleResources->bufferB[battler][1];
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp;

    SWAP(gActionsByTurnOrder[id1], gActionsByTurnOrder[id2], temp);
    SWAP(gBattlerByTurnOrder[id1], gBattlerByTurnOrder[id2], temp);
}

// For AI, so it doesn't 'cheat' by knowing player's ability
u32 GetBattlerTotalSpeedStatArgs(u32 battler, u32 ability, u32 holdEffect)
{
    u32 velocidad = gBattleMons[battler].speed;
    uq4_12_t modificador = NEUTRO;
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    if ((ability == ABILITY_SWIFT_SWIM || ability == ABILITY_ALAS_HIDROFOBAS) && EsClimaCombateLluvia(climaCombate))
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);
    if (ability == ABILITY_CHLOROPHYLL && EsClimaCombateSol(climaCombate))
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);
    if (ability == ABILITY_SAND_RUSH && EsClimaCombateArena(climaCombate))
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);
    if (ability == ABILITY_SLUSH_RUSH && EsClimaCombateNieve(climaCombate))
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);

    if (ability == ABILITY_QUICK_FEET && (gBattleMons[battler].status1 & STATUS1_ANY))
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);

    if (gBattleResources->flags[battler] & RESOURCE_FLAG_UNBURDEN)
        MULTIPLICA(modificador, MAS_100_POR_CIENTO);

    if (holdEffect == HOLD_EFFECT_MACHO_BRACE || holdEffect == HOLD_EFFECT_POWER_ITEM)
        MULTIPLICA(modificador, MENOS_50_POR_CIENTO);
    else if (holdEffect == HOLD_EFFECT_CHOICE_SCARF)
        MULTIPLICA(modificador, MAS_50_POR_CIENTO);

    if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
        MULTIPLICA(modificador, MAS_100_POR_CIENTO);

    if ((gBattleMons[battler].status1 & STATUS1_PARALYSIS) && ability != ABILITY_QUICK_FEET)
        MULTIPLICA(modificador, MENOS_50_POR_CIENTO);

    MULTIPLICA(modificador, gMultiplicadorEstadisticas[gBattleMons[battler].statStages[ESTADISTICA_VELOCIDAD]]);

    return UQ412MultiplicaPorEntero(modificador, velocidad);
}

u32 GetBattlerTotalSpeedStat(u32 battler)
{
    u32 ability = HabilidadCombatiente(battler);
    u32 holdEffect = GetBattlerHoldEffect(battler, TRUE);
    return GetBattlerTotalSpeedStatArgs(battler, ability, holdEffect);
}

enum PrioridadMovimientos PrioridadMovimientoMasHabilidad(u32 combatiente, u32 movimiento)
{
    enum PrioridadMovimientos prioridad = PrioridadMovimiento(movimiento);
    u32 habilidad = HabilidadCombatiente(combatiente);

    if (gProtectStructs[combatiente].noValidMoves)
        movimiento = MOVE_STRUGGLE;

    gProtectStructs[combatiente].prioridadBromista = FALSE;

    if ((habilidad == ABILITY_ALAS_VENDAVAL && gMovimientos[movimiento].type == TIPO_VOLADOR)   ||
        (habilidad == ABILITY_TIERRA_SUELTA && gMovimientos[movimiento].type == TIPO_TIERRA)    ||
        (habilidad == ABILITY_SUPERORDENADOR && gMovimientos[movimiento].type == TIPO_PSIQUICO) ||
        (habilidad == ABILITY_ENVIO_EXPRESS && gMovimientos[movimiento].type == TIPO_HADA)      ||
        (habilidad == ABILITY_ZUMBANDO && gMovimientos[movimiento].type == TIPO_BICHO)          ||
        (habilidad == ABILITY_BAILARIN && gMovimientos[movimiento].danceMove)                   ||
        (habilidad == ABILITY_ATAQUE_RELAMPAGO && gMovimientos[movimiento].balistico)           ||
        (habilidad == ABILITY_OJOS_PRESTOS && gMovimientos[movimiento].eyesMove)                ||
        (habilidad == ABILITY_CARA_DURA && EsMovimientoCabeza(movimiento))                      ||
        (habilidad == ABILITY_HUIDIZO && gMovimientos[movimiento].effect == EFFECT_HIT_ESCAPE)  ||
        (habilidad == ABILITY_VOZ_CANTANTE && EsMovimientoSonido(movimiento))                   ||
        (habilidad == ABILITY_PACIFISTA && EsMovimientoEstado(movimiento))                      ||
        (habilidad == ABILITY_TRIAGE && EsMovimientoCura(movimiento))                           ||
        (habilidad == ABILITY_FORECAST && EsMovimientoClima(movimiento)))
    {
        prioridad++;
    }

    if (habilidad == ABILITY_BROMISTA && EsMovimientoEstado(movimiento))
    {
        gProtectStructs[combatiente].prioridadBromista = TRUE;
        prioridad++;
    }

    if (prioridad > PRIORIDAD_MOVIMIENTO_MUY_ALTA)
        prioridad = PRIORIDAD_MOVIMIENTO_MUY_ALTA;

    return prioridad;
}

// Function for AI with variables provided as arguments to speed the computation time
s32 GetWhichBattlerFasterArgs(u32 battler1, u32 battler2, bool32 ignoreChosenMoves, u32 ability1, u32 ability2, u32 holdEffectBattler1, u32 holdEffectBattler2, u32 speedBattler1, u32 speedBattler2, enum PrioridadMovimientos prioridad1, enum PrioridadMovimientos prioridad2)
{
    u32 strikesFirst = 0;

    if (prioridad1 == prioridad2)
    {
        if (speedBattler1 == speedBattler2)
        {
            strikesFirst = 0;
        }
        else if (speedBattler1 < speedBattler2)
        {
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
                strikesFirst = 1;
            else
                strikesFirst = -1;
        }
        else
        {
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
                strikesFirst = -1;
            else
                strikesFirst = 1;
        }
    }
    else if (prioridad1 < prioridad2)
    {
        strikesFirst = -1; // battler2's move has greater priority
    }
    else
    {
        strikesFirst = 1; // battler1's move has greater priority
    }
    return strikesFirst;
}

s32 GetWhichBattlerFasterOrTies(u32 battler1, u32 battler2, bool32 ignoreChosenMoves)
{
    enum PrioridadMovimientos prioridad1 = PRIORIDAD_MOVIMIENTO_NORMAL;
    enum PrioridadMovimientos prioridad2 = PRIORIDAD_MOVIMIENTO_NORMAL;
    u32 movimiento1 = MOVE_NONE;
    u32 movimiento2 = MOVE_NONE;

    u32 speedBattler1 = GetBattlerTotalSpeedStat(battler1);
    u32 speedBattler2 = GetBattlerTotalSpeedStat(battler2);

    if (!ignoreChosenMoves)
    {
        if (gAccionElegida[battler1] == B_ACTION_USE_MOVE)
        {
            movimiento1 = gBattleMons[battler1].moves[gCombate->chosenMovePositions[battler1]];
            prioridad1 = PrioridadMovimientoMasHabilidad(battler1, movimiento1);
        }
        if (gAccionElegida[battler2] == B_ACTION_USE_MOVE)
        {
            movimiento2 = gBattleMons[battler2].moves[gCombate->chosenMovePositions[battler2]];
            prioridad2 = PrioridadMovimientoMasHabilidad(battler2, movimiento2);
        }
    }

    return GetWhichBattlerFasterArgs(battler1, battler2, ignoreChosenMoves, HabilidadCombatiente(battler1), HabilidadCombatiente(battler2), 0, 0, prioridad1, prioridad2);
}

// 24 == NUMERO_COMBATIENTES!.
// These are the possible orders if all the battlers speed tie. An order
// is chosen at the start of the turn.
static const u8 sBattlerOrders[24][4] =
    {
        {0, 1, 2, 3},
        {0, 1, 3, 2},
        {0, 2, 1, 3},
        {0, 2, 3, 1},
        {0, 3, 1, 2},
        {0, 3, 2, 1},
        {1, 0, 2, 3},
        {1, 0, 3, 2},
        {1, 2, 0, 3},
        {1, 2, 3, 0},
        {1, 3, 0, 2},
        {1, 3, 2, 0},
        {2, 0, 1, 3},
        {2, 0, 3, 1},
        {2, 1, 0, 3},
        {2, 1, 3, 0},
        {2, 3, 0, 1},
        {2, 3, 1, 0},
        {3, 0, 1, 2},
        {3, 0, 2, 1},
        {3, 1, 0, 2},
        {3, 1, 2, 0},
        {3, 2, 0, 1},
        {3, 2, 1, 0},
};

s32 GetWhichBattlerFaster(u32 battler1, u32 battler2, bool32 ignoreChosenMoves)
{
    s32 strikesFirst = GetWhichBattlerFasterOrTies(battler1, battler2, ignoreChosenMoves);
    if (strikesFirst == 0)
    {
        s32 order1 = sBattlerOrders[gCombate->speedTieBreaks][battler1];
        s32 order2 = sBattlerOrders[gCombate->speedTieBreaks][battler2];
        if (order1 < order2)
            strikesFirst = 1;
        else
            strikesFirst = -1;
    }
    return strikesFirst;
}

static void SetActionsAndBattlersTurnOrder(void)
{
    s32 turnOrderId = 0;
    s32 i, j, battler;

    if (gAccionElegida[JUGADOR_IZQUIERDA] == B_ACTION_RUN)
    {
        battler = JUGADOR_IZQUIERDA;
        turnOrderId = 5;
    }
    if (gAccionElegida[JUGADOR_DERECHA] == B_ACTION_RUN)
    {
        battler = JUGADOR_DERECHA;
        turnOrderId = 5;
    }

    if (turnOrderId == 5) // One of battlers wants to run.
    {
        gActionsByTurnOrder[0] = gAccionElegida[battler];
        gBattlerByTurnOrder[0] = battler;
        turnOrderId = 1;
        for (i = 0; i < gBattlersCount; i++)
        {
            if (i != battler)
            {
                gActionsByTurnOrder[turnOrderId] = gAccionElegida[i];
                gBattlerByTurnOrder[turnOrderId] = i;
                turnOrderId++;
            }
        }
    }
    else
    {
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (gAccionElegida[battler] == B_ACTION_SWITCH || gAccionElegida[battler] == B_ACTION_THROW_BALL)
            {
                gActionsByTurnOrder[turnOrderId] = gAccionElegida[battler];
                gBattlerByTurnOrder[turnOrderId] = battler;
                turnOrderId++;
            }
        }
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (gAccionElegida[battler] != B_ACTION_SWITCH && gAccionElegida[battler] != B_ACTION_THROW_BALL)
            {
                gActionsByTurnOrder[turnOrderId] = gAccionElegida[battler];
                gBattlerByTurnOrder[turnOrderId] = battler;
                turnOrderId++;
            }
        }
        for (i = 0; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                u8 battler1 = gBattlerByTurnOrder[i];
                u8 battler2 = gBattlerByTurnOrder[j];
                if (gActionsByTurnOrder[i] != B_ACTION_SWITCH && gActionsByTurnOrder[j] != B_ACTION_SWITCH && gActionsByTurnOrder[i] != B_ACTION_THROW_BALL && gActionsByTurnOrder[j] != B_ACTION_THROW_BALL)
                {
                    if (GetWhichBattlerFaster(battler1, battler2, FALSE) == -1)
                        SwapTurnOrder(i, j);
                }
            }
        }
    }
}

static void TurnValuesCleanUp(bool8 var0)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (var0)
        {
            gProtectStructs[i].protected = FALSE;
        }
        else
        {
            memset(&gProtectStructs[i], 0, sizeof(struct ProtectStruct));

            if (EsPrimerTurno(i))
                gDisableStructs[i].esPrimerTurno = FALSE;

            if (gDisableStructs[i].rechargeTimer)
            {
                gDisableStructs[i].rechargeTimer--;
                if (gDisableStructs[i].rechargeTimer == 0)
                    gBattleMons[i].status2 &= ~STATUS2_RECHARGE;
            }
        }

        if (gDisableStructs[i].substituteHP == 0)
            gBattleMons[i].status2 &= ~STATUS2_SUBSTITUTE;

        gSpecialStatuses[i].parentalBondState = PARENTAL_BOND_OFF;
    }
    for (u32 lado = LADO_JUGADOR; lado < NUMERO_LADOS; lado++)
    {
        gSideStatuses[lado] &= ~(SIDE_STATUS_WIDE_GUARD | SIDE_STATUS_CRAFTY_SHIELD | SIDE_STATUS_MAT_BLOCK);
        gSideTimers[lado].followmeTimer = 0;
    }

    gCombate->usedEjectItem = 0;
}

void SpecialStatusesClear(void)
{
    memset(&gSpecialStatuses, 0, sizeof(gSpecialStatuses));
}

static void PopulateArrayWithBattlers(u8 *battlers)
{
    u32 i;
    for (i = 0; i < gBattlersCount; i++)
        battlers[i] = i;
}

static bool32 TryDoMoveEffectsBeforeMoves(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        u32 i;
        u8 battlers[NUMERO_COMBATIENTES];

        PopulateArrayWithBattlers(battlers);
        SortBattlersBySpeed(battlers, FALSE);
        for (i = 0; i < gBattlersCount; i++)
        {
            if (!(gCombate->focusPunchBattlers & (1u << battlers[i])) && !(gBattleMons[battlers[i]].status1 & STATUS1_SLEEP) && !(gProtectStructs[battlers[i]].noValidMoves))
            {
                gCombate->focusPunchBattlers |= 1u << battlers[i];
                gBattlerAttacker = battlers[i];
                switch (gMovimientos[gMovimientoElegido[gBattlerAttacker]].effect)
                {
                case EFFECT_FOCUS_PUNCH:
                    BattleScriptExecute(BattleScript_FocusPunchSetUp);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = B_ACTION_FINISHED;

    if (gCurrentActionFuncId == B_ACTION_USE_MOVE && !gCombate->effectsBeforeUsingMoveDone)
    {
        if (TryDoMoveEffectsBeforeMoves())
            return;
        gCombate->effectsBeforeUsingMoveDone = TRUE;
    }

    gCombate->savedTurnActionNumber = gCurrentTurnActionNumber;
    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gBattlersCount) // everyone did their actions, turn finished
    {
        gHitMarker &= ~HITMARKER_PASSIVE_DAMAGE;
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
    }
    else
    {
        if (gCombate->savedTurnActionNumber != gCurrentTurnActionNumber) // action turn has been done, clear hitmarker bits for another battler
        {
            gHitMarker &= ~HITMARKER_NO_ATTACKSTRING;
            gHitMarker &= ~HITMARKER_UNABLE_TO_USE_MOVE;
        }
    }
}

static void HandleEndTurn_BattleWon(void)
{
    gCurrentActionFuncId = 0;

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (GetTrainerClassFromId(gTrainerBattleOpponent))
        {
        case TRAINER_CLASS_ELITE_FOUR:
        case TRAINER_CLASS_CHAMPION:
            PlayBGM(MUS_VICTORY_LEAGUE);
            break;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_ADMIN:
        case TRAINER_CLASS_MAGMA_LEADER:
            PlayBGM(MUS_VICTORY_AQUA_MAGMA);
            break;
        case TRAINER_CLASS_LEADER:
            PlayBGM(MUS_VICTORY_GYM_LEADER);
            break;
        default:
            PlayBGM(MUS_VICTORY_TRAINER);
            break;
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_DiaDePagoMoney;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_BattleLost(void)
{
    gCurrentActionFuncId = 0;
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        gBattlescriptCurrInstr = ScriptCombate_DerrotaContraEntrenador;
    else
        gBattlescriptCurrInstr = ScriptCombate_DerrotaContraSalvajeLegendarios;
    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_RanFromBattle(void)
{
    gCurrentActionFuncId = 0;
    gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_MonFled(void)
{
    gCurrentActionFuncId = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_FinishBattle(void)
{
    u32 i, battler;

    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        EmpiezaFundidoPaletasRapido(FUNDIDO_A_NEGRO);
        DesvaneceMusicaMapa(VELOCIDAD_LENTA_MUSICA);
        RecuperaObjetoPerdido();

        for (i = 0; i < PARTY_SIZE; i++)
        {
            bool8 changedForm = FALSE;

            if (!changedForm)
                changedForm = TryFormChange(i, LADO_JUGADOR, FORM_CHANGE_END_BATTLE);

            // Clear original species field
            gCombate->changedSpecies[LADO_JUGADOR][i] = SPECIES_NONE;
            gCombate->changedSpecies[LADO_OPONENTE][i] = SPECIES_NONE;

            // Recalculate the stats of every party member before the end
            if (!changedForm)
                CalculateMonStats(&gPlayerParty[i]);
        }
        // Clear battle mon species to avoid a bug on the next battle that causes
        // healthboxes loading incorrectly due to it trying to create a Mega Indicator
        // if the previous battler would've had it.
        for (i = 0; i < NUMERO_COMBATIENTES; i++)
        {
            gBattleMons[i].species = SPECIES_NONE;
        }
        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gCB2_AfterEvolution = BattleMainCB2;
    }
    else
    {
        if (!HayAlgunCombatienteOcupado())
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gFundidoPaletas.activo)
    {
        gIsFishingEncounter = FALSE;
        gIsSurfingEncounter = FALSE;
        ResetSpriteData();
        if ((B_EVOLUTION_AFTER_WHITEOUT >= GEN_6 || gBattleOutcome == B_OUTCOME_WON || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
        else
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
    }

    FreeAllWindowBuffers();
    ZeroEnemyPartyMons();
    ResetDynamicAIFunc();
    FreeMonSpritesGfx();
    FreeBattleResources();
    FreeBattleSpritesData();
}

static void TryEvolvePokemon(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!(sTriedEvolving & (1u << i)))
        {
            u16 species = GetEvolutionTargetSpecies(&gPlayerParty[i], ITEM_NONE);
            sTriedEvolving |= 1u << i;

            if (species != SPECIES_NONE)
            {
                FreeAllWindowBuffers();
                gBattleMainFunc = WaitForEvoSceneToFinish;
                EvolutionScene(&gPlayerParty[i], species, i);
                return;
            }
        }
    }
    gBattleMainFunc = ReturnFromBattleToOverworld;
}

static void WaitForEvoSceneToFinish(void)
{
    if (gMain.callback2 == BattleMainCB2)
        gBattleMainFunc = TryEvolvePokemon;
}

static void ReturnFromBattleToOverworld(void)
{
    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = FALSE;
    gMain.callback1 = gPreBattleCallback1;

    m4aSongNumStop(SE_LOW_HEALTH);
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (gBattleResources->battleCallbackStack->size != 0)
            gBattleResources->battleCallbackStack->size--;
        gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
    }
    else
    {
        if (!HayAlgunCombatienteOcupado())
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

void RunBattleScriptCommands(void)
{
    if (!HayAlgunCombatienteOcupado())
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

u32 TipoMovimiento(enum Movimientos movimiento, u32 combatiente)
{
    u32 tipoMovimiento = gMovimientos[movimiento].type;
    // u32 efectoMovimiento = gMovimientos[movimiento].effect;
    u32 habilidad = HabilidadCombatiente(combatiente);
    enum ClimasCombate climaCombate = ObtenClimaCombate();

    if (movimiento == MOVE_METEOROBOLA)
    {
        if (EsClimaCombateLluvia(climaCombate))
            return TIPO_AGUA;
        if (EsClimaCombateArena(climaCombate))
            return TIPO_ROCA;
        if (EsClimaCombateSol(climaCombate))
            return TIPO_FUEGO;
        if (EsClimaCombateNieve(climaCombate))
            return TIPO_HIELO;
    }

    if (movimiento == MOVE_DIA_DE_PAGO
     && habilidad == ABILITY_EN_METALICO)
    {
        return TIPO_ACERO;
    }

    return tipoMovimiento;
}

static void IntentaActivarGema(u32 combatiente, enum Movimientos movimiento)
{
    u32 objetoEquipado = gBattleMons[combatiente].item;
    u32 efectoObjeto = GetBattlerHoldEffect(combatiente, TRUE);
    u32 tipoMovimiento = TipoMovimiento(movimiento, combatiente);

    gSpecialStatuses[combatiente].potenciadoGema = FALSE;

    if (efectoObjeto == HOLD_EFFECT_GEMS
     && tipoMovimiento == ItemId_GetSecondaryId(objetoEquipado))
    {
        gSpecialStatuses[combatiente].potenciadoGema = TRUE;
    }
}

static s32 Factorial(s32 n)
{
    s32 f = 1, i;
    for (i = 2; i <= n; i++)
        f *= i;
    return f;
}

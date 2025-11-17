#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "match_call.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "frontier_util.h"
#include "pokedex.h"
#include "save.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "field_specials.h"
#include "constants/items.h"

extern const u8 EventScript_ResetAllMapFlags[];

static void ResetItemFlags(void);

static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

u32 ObtenPersonalidadJugador(void)
{
    return gSaveBlockPtr->personalidadJugador;
}

static void CreaPersonalidadJugador(void)
{
    gSaveBlockPtr->personalidadJugador = Random();
}

// L=A isnt set here for some reason.
void SetDefaultOptions(void)
{
    gSaveBlockPtr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;
    gSaveBlockPtr->optionsWindowFrameType = 0;
    gSaveBlockPtr->optionsSound = OPTIONS_SOUND_STEREO;
    gSaveBlockPtr->optionsBattleSceneOff = FALSE;
    gSaveBlockPtr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    memset(&gSaveBlockPtr->dexCaught, 0, sizeof(gSaveBlockPtr->dexCaught));
    memset(&gSaveBlockPtr->dexSeen, 0, sizeof(gSaveBlockPtr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();

    // Clear Museum paintings
    for (i = MUSEUM_CONTEST_WINNERS_START; i < NUM_CONTEST_WINNERS; i++)
        gSaveBlockPtr->contestWinners[i] = sContestWinnerPicDummy;
}

void ResetMenuAndMonGlobals(void)
{
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

void NewGameInitData(void)
{
    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

    GeneraSemillaAleatoria();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    gSaveBlockPtr->specialSaveWarpFlags = 0;
    CreaPersonalidadJugador();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearBerryTrees();
    SetMoney(&gSaveBlockPtr->money, 3000);
    SetCoins(0);
    ResetGameStats();
    ClearAllContestWinnerPics();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    DeactivateAllRoamers();
    gSaveBlockPtr->registeredItem = ITEM_NONE;
    ClearBag();
    SetWarpDestination(MAP_GROUP(TEST), MAP_NUM(TEST), WARP_ID_NONE, -1, -1);
    WarpIntoMap();
    RunScriptImmediately(EventScript_ResetAllMapFlags);
    ResetItemFlags();
}

static void ResetItemFlags(void)
{
#if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_FIRST_TIME
    memset(&gSaveBlockPtr->itemFlags, 0, sizeof(gSaveBlockPtr->itemFlags));
#endif
}

#include "global.h"
#include "wild_encounter.h"
#include "nivel_dinamico.h"
#include "pokemon.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "random.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "overworld.h"
#include "battle_setup.h"
#include "script.h"
#include "battle_debug.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"

extern const u8 EventScript_SprayWoreOff[];

#define MAX_ENCOUNTER_RATE 2880

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

#define WILD_CHECK_REPEL    (1 << 0)
#define WILD_CHECK_KEEN_EYE (1 << 1)


static void UpdateChainFishingStreak();
static bool8 IsWildLevelAllowedByRepel(u8 level);
#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex, u32 size);
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex);
#endif
static bool8 IsAbilityAllowingEncounter(u8 level);

EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;
EWRAM_DATA u8 gChainFishingDexNavStreak = 0;

#include "data/wild_encounters.h"

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

// LAND_WILD_COUNT
u32 ChooseWildMonIndex_Land(void)
{
    u32 wildMonIndex = 0;
    bool32 swap = FALSE;
    u32 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        wildMonIndex = 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        wildMonIndex = 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        wildMonIndex = 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        wildMonIndex = 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        wildMonIndex = 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        wildMonIndex = 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        wildMonIndex = 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        wildMonIndex = 10;
    else
        wildMonIndex = 11;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 11 - wildMonIndex;

    return wildMonIndex;
}

// ROCK_WILD_COUNT / WATER_WILD_COUNT
u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u32 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// FISH_WILD_COUNT
static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u32 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;

        if (swap)
            wildMonIndex = 1 - wildMonIndex;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;

        if (swap)
            wildMonIndex = 6 - wildMonIndex;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;

        if (swap)
            wildMonIndex = 14 - wildMonIndex;
        break;
    }
    return wildMonIndex;
}

u32 ChooseWildMonLevel(const struct WildPokemon *wildPokemon, u32 wildMonIndex, u32 area)
{
    // Los rangos de nivel de la tabla de encuentros ya no mandan: todo rival sale al
    // nivel del Pokemon mas fuerte del jugador. Los parametros se conservan para no
    // tocar a todos los que llaman aqui.
    (void)wildPokemon;
    (void)wildMonIndex;
    (void)area;

    return NivelDinamico();
}

u16 ObtenIdCabeceraSalvajesMapaActual(void)
{
    u32 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlockPtr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlockPtr->location.mapNum)
        {
            return i;
        }
    }

    return HEADER_NONE;
}

u32 EscogeNaturalezaPokemonSalvaje(void)
{
    if (!GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE)
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % NUMERO_NATURALEZAS;
    }
    else
        return Random() % NUMERO_NATURALEZAS;
}

// Variante para los Pokemon salvajes del mapa: la personalidad ya se decidio al
// aparecer, asi que no se vuelve a tirar. Es lo que hace que el tono y el
// variocolor que se veian en el overworld sean los del combate.
void CreaPokemonSalvajeConPersonalidad(u32 especie, u32 nivel, u32 personalidad)
{
    ZeroEnemyPartyMons();
    CreaPokemon(&gEnemyParty[0], especie, nivel, TRUE, personalidad);
}

void CreateWildMon(u32 species, u32 level)
{
    bool32 checkCuteCharm = TRUE;

    ZeroEnemyPartyMons();

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreaPokemonConGeneroNaturaleza(&gEnemyParty[0], species, level, gender, EscogeNaturalezaPokemonSalvaje());
        return;
    }

    CreaPokemonConNaturaleza(&gEnemyParty[0], species, level, EscogeNaturalezaPokemonSalvaje());
}
#ifdef BUGFIX
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr, count)
#else
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr)
#endif

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, u8 area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ACERO, ABILITY_IMAN, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ELECTRICO, ABILITY_STATIC, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ELECTRICO, ABILITY_LIGHTNING_ROD, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_FUEGO, ABILITY_FLASH_FIRE, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_HARVEST >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_PLANTA, ABILITY_HARVEST, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_AGUA, ABILITY_STORM_DRAIN, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_BICHO, ABILITY_MATAMOSCAS, &wildMonIndex, LAND_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ACERO, ABILITY_IMAN, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ELECTRICO, ABILITY_STATIC, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_ELECTRICO, ABILITY_LIGHTNING_ROD, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_FUEGO, ABILITY_FLASH_FIRE, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_HARVEST >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_PLANTA, ABILITY_HARVEST, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_AGUA, ABILITY_STORM_DRAIN, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TIPO_BICHO, ABILITY_MATAMOSCAS, &wildMonIndex, WATER_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_WaterRock();
        break;
    }

    level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, area);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

static void GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    u16 wildMonSpecies = wildMonInfo->wildPokemon[wildMonIndex].species;
    u8 level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, WILD_AREA_FISHING);

    UpdateChainFishingStreak();
    CreateWildMon(wildMonSpecies, level);
}




// Returns true if it will try to create a wild encounter.

// When you first step on a different type of metatile, there's a 40% chance it
// skips the wild encounter check entirely.





bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerId = ObtenIdCabeceraSalvajesMapaActual();

    if (headerId != HEADER_NONE && gWildMonHeaders[headerId].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

u32 CalculateChainFishingShinyRolls(void)
{
    return (2 * min(gChainFishingDexNavStreak, FISHING_CHAIN_SHINY_STREAK_MAX));
}

static void UpdateChainFishingStreak()
{
    if (!I_FISHING_CHAIN)
        return;

    if (gChainFishingDexNavStreak >= FISHING_CHAIN_LENGTH_MAX)
        return;

    gChainFishingDexNavStreak++;
}

void FishingWildEncounter(u8 rod)
{
    GenerateFishingWildMon(gWildMonHeaders[ObtenIdCabeceraSalvajesMapaActual()].fishingMonsInfo, rod);
    gIsFishingEncounter = TRUE;
    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = ObtenIdCabeceraSalvajesMapaActual();
    if (headerId == HEADER_NONE)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokémon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    // Water Pokémon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokémon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = ObtenIdCabeceraSalvajesMapaActual();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 repelLureVar = VarGet(VAR_REPEL_STEP_COUNT);
    u16 steps = REPEL_LURE_STEPS(repelLureVar);
    bool32 isLure = IS_LAST_USED_LURE(repelLureVar);

    if (steps != 0)
    {
        steps--;
        if (!isLure)
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }
        else
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps | REPEL_LURE_MASK);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }

    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u32 i;

    if (!REPEL_STEP_COUNT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (I_REPEL_INCLUDE_FAINTED == GEN_1 || I_REPEL_INCLUDE_FAINTED >= GEN_6 || GetMonData(&gPlayerParty[i], MON_DATA_HP))
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                return wildLevel >= GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    u16 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_VISTA_LINCE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMon, u8 *monIndex)
{
    u8 validIndexes[numMon]; // variable length array, an interesting feature
    u32 i, validMonCount;

    for (i = 0; i < numMon; i++)
        validIndexes[i] = 0;

    for (validMonCount = 0, i = 0; i < numMon; i++)
    {
        if (gSpeciesInfo[wildMon[i].species].types[TIPO_1] == type || gSpeciesInfo[wildMon[i].species].types[TIPO_2] == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == numMon)
        return FALSE;

    *monIndex = validIndexes[Random() % validMonCount];
    return TRUE;
}

#include "data.h"

#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex, u32 size)
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u16 ability, u8 *monIndex)
#endif
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG))
        return FALSE;
    else if (GetMonAbility(&gPlayerParty[0]) != ability)
        return FALSE;
    else if (Random() % 2 != 0)
        return FALSE;

#ifdef BUGFIX
    return TryGetRandomWildMonIndexByType(wildMon, type, size, monIndex);
#else
    return TryGetRandomWildMonIndexByType(wildMon, type, LAND_WILD_COUNT, monIndex);
#endif
}



bool8 StandardWildEncounter_Debug(void)
{
    u16 headerId = ObtenIdCabeceraSalvajesMapaActual();
    if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
        return FALSE;

    DoStandardWildBattle_Debug();
    return TRUE;
}

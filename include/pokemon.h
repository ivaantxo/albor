#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "new_game.h"
#include "sprite.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"
#include "constants/map_groups.h"
#include "constants/moves.h"
#include "constants/battle.h"

#define GET_BASE_SPECIES_ID(speciesId) (GetFormSpeciesId(speciesId, 0))
#define FORM_SPECIES_END (0xffff)

// Property labels for Get(Box)MonData / Set(Box)MonData
enum {
    MON_DATA_PERSONALITY,
    MON_DATA_STATUS,
    MON_DATA_LANGUAGE,
    MON_DATA_OT_NAME,
    MON_DATA_MARKINGS,
    MON_DATA_HP,
    MON_DATA_IS_SHINY,
    MON_DATA_NICKNAME,
    MON_DATA_NICKNAME10,
    MON_DATA_SPECIES,
    MON_DATA_HELD_ITEM,
    MON_DATA_MOVE1,
    MON_DATA_MOVE2,
    MON_DATA_MOVE3,
    MON_DATA_MOVE4,
    MON_DATA_PP1,
    MON_DATA_PP2,
    MON_DATA_PP3,
    MON_DATA_PP4,
    MON_DATA_COOL,
    MON_DATA_BEAUTY,
    MON_DATA_CUTE,
    MON_DATA_EXP,
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_FRIENDSHIP,
    MON_DATA_SMART,
    MON_DATA_POKERUS,
    MON_DATA_MET_LOCATION,
    MON_DATA_MET_LEVEL,
    MON_DATA_POKEBALL,
    MON_DATA_IS_EGG,
    MON_DATA_ABILITY_NUM,
    MON_DATA_TOUGH,
    MON_DATA_SHEEN,
    MON_DATA_OT_GENDER,
    MON_DATA_COOL_RIBBON,
    MON_DATA_BEAUTY_RIBBON,
    MON_DATA_CUTE_RIBBON,
    MON_DATA_SMART_RIBBON,
    MON_DATA_TOUGH_RIBBON,
    MON_DATA_LEVEL,
    MON_DATA_MAX_HP,
    MON_DATA_ATK,
    MON_DATA_DEF,
    MON_DATA_SPEED,
    MON_DATA_SPATK,
    MON_DATA_SPDEF,
    MON_DATA_MAIL,
    MON_DATA_SPECIES_OR_EGG,
    MON_DATA_CHAMPION_RIBBON,
    MON_DATA_WINNING_RIBBON,
    MON_DATA_VICTORY_RIBBON,
    MON_DATA_ARTIST_RIBBON,
    MON_DATA_EFFORT_RIBBON,
    MON_DATA_MARINE_RIBBON,
    MON_DATA_LAND_RIBBON,
    MON_DATA_SKY_RIBBON,
    MON_DATA_COUNTRY_RIBBON,
    MON_DATA_NATIONAL_RIBBON,
    MON_DATA_EARTH_RIBBON,
    MON_DATA_WORLD_RIBBON,
    MON_DATA_KNOWN_MOVES,
    MON_DATA_RIBBON_COUNT,
    MON_DATA_RIBBONS,
};

struct BoxPokemon
{
    u32 personality;

    u8 nickname[POKEMON_NAME_LENGTH];

    u32 species:11;
    u32 experience:21;

    u32 heldItem:10;
    u32 pokeball:6;
    u32 friendship:8;

    // No hay intercambios, así que no se guarda entrenador original ni datos de captura.
    // Los PP no se guardan: se regeneran al salir de combate, así que siempre valen el máximo.
    // Los EV y los IV no existen: no influyen en las estadísticas.
    u8 isEgg:1;
    u8 esShiny:1;
    u8 abilityNum:2;

    enum Movimientos move1;
    enum Movimientos move2;
    enum Movimientos move3;
    enum Movimientos move4;
};

struct Pokemon
{
    struct BoxPokemon box;
    u32 status;
    u8 level;
    u16 hp;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
};

struct MonSpritesGfxManager
{
    bool32 active;
    void *spriteBuffer;
    u8 **spritePointers;
    struct SpriteTemplate *templates;
    struct SpriteFrameImage *frameImages;
};

struct BattlePokemon
{
    u16 species;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
    enum Movimientos movimientos[MAXIMO_MOVIMIENTOS_POKEMON];
    u32 abilityNum:2;
    s8 statStages[NUMERO_ESTADISTICAS_BATALLA];
    u16 ability;
    u8 types[NUMERO_TIPOS_POR_POKEMON];
    u8 pp[MAXIMO_MOVIMIENTOS_POKEMON];
    u16 hp;
    u8 level;
    u8 friendship;
    u16 maxHP;
    u16 item;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 otName[MAXIMO_CARACTERES_NOMBRE_JUGADOR + 1];
    u32 experience;
    u32 personality;
    u32 status1;
    u32 status2;
    u8 metLevel;
    bool8 isShiny;
};

struct Evolution
{
    u16 method;
    u16 param;
    u16 targetSpecies;
};

struct SpeciesInfo
{
    u8 baseHP;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;
    u8 types[NUMERO_TIPOS_POR_POKEMON];
    u8 catchRate;
    u8 expYield;
    u16 evYield_HP:2;
    u16 evYield_Attack:2;
    u16 evYield_Defense:2;
    u16 evYield_Speed:2;
    u16 evYield_SpAttack:2;
    u16 evYield_SpDefense:2;
    u16 itemCommon;
    u16 itemRare;
    u8 genderRatio;
    u8 eggCycles;
    u8 friendship;
    u8 growthRate;
    u8 eggGroups[GRUPOS_HUEVO_POR_POKEMON];
    u16 abilities[NUM_ABILITY_SLOTS];
    u8 speciesName[POKEMON_NAME_LENGTH];
    u16 cryId;
    u16 dexNum;
    u8 noFlip:1;
    u8 frontAnimDelay;
    u8 frontAnimId;
    u8 backAnimId;
    const union AnimCmd *const *frontAnimFrames;
    const u32 *frontPic;
    const u32 *frontPicFemale;
    const u32 *backPic;
    const u32 *backPicFemale;
    const u32 *palette;
    const u32 *paletteFemale;
    const u32 *shinyPalette;
    const u32 *shinyPaletteFemale;
    u8 frontPicSize; // The dimensions of this drawn pixel area.
    u8 frontPicSizeFemale; // The dimensions of this drawn pixel area.
    u8 frontPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
    u8 backPicSize; // The dimensions of this drawn pixel area.
    u8 backPicSizeFemale; // The dimensions of this drawn pixel area.
    u8 backPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
    u8 enemyMonElevation; // This determines how much higher above the usual position the enemy Pokémon is during battle. Species that float or fly have nonzero values.
    u32 isLegendary:1;
    bool32 brilla:1;
    bool32 transparente:1;
    s8 enemyShadowXOffset; // This determines the X-offset for an enemy Pokémon's shadow during battle; negative values point left, positive values point right.
    s8 enemyShadowYOffset; // This determines the Y-offset for an enemy Pokémon's shadow during battle; negative values point up, positive values point down.
    u16 suppressEnemyShadow:1; // If set to true, then a shadow will not be drawn beneath an enemy Pokémon's front sprite during battle.
    const struct LevelUpMove *levelUpLearnset;
    const u16 *teachableLearnset;
    const u16 *eggMoveLearnset;
    const struct Evolution *evolutions;
    const u16 *formSpeciesIdTable;
    const struct FormChange *formChangeTable;
    struct ObjectEventGraphicsInfo followerData;
    struct ObjectEventGraphicsInfo followerDataFemale;
};

enum PrioridadMovimientos
{
    PRIORIDAD_MOVIMIENTO_NEGATIVA = -1,
    PRIORIDAD_MOVIMIENTO_NORMAL,
    PRIORIDAD_MOVIMIENTO_ALTA,
    PRIORIDAD_MOVIMIENTO_MUY_ALTA,
};

struct InfoMovimiento
{
    const u8 *name;
    const u8 *description;
    u16 effect;

    u16 type;
    u16 category;

    u16 power;
    u16 accuracy;

    u16 target;
    u16 pp;

    u32 retroceso;

    u32 strikeCount;

    u32 alwaysCriticalHit;

    u32 numAdditionalEffects;

    u32 makesContact:1;
    u32 ignoresProtect:1;
    u32 espejoMagico:1;
    u32 bitingMove:1;
    u32 soundMove:1;
    u32 balistico:1;
    u32 punzante:1;
    u32 hammerMove:1;
    u32 tailMove:1;
    u32 powderMove:1;
    u32 danceMove:1;
    u32 windMove:1;
    u32 slicingMove:1;
    u32 minimizeDoubleDamage:1;
    u32 ignoresTargetAbility:1;
    u32 ignoresTargetDefenseEvasionStages:1;
    u32 damagesUnderground:1;
    u32 damagesUnderwater:1;
    u32 damagesAirborne:1;
    u32 damagesAirborneDoubleDamage:1;
    u32 ignoresSubstitute:1;
    u32 eyesMove:1;
    u32 lickMove:1;
    u32 patada:1;
    u32 encoreBanned:1;
    u32 parentalBondBanned:1;

    bool32 climatico;
    bool32 cabezazo;
    bool32 punietazo;
    bool32 altoIndiceCritico;
    bool32 curativo;

    enum PrioridadMovimientos prioridad;

    u32 argument;
    enum ClimasCombate clima;
    u32 estado; // Convertir a enum, revisar

    const struct AdditionalEffect *additionalEffects;

    const u8 *battleAnimScript;
};

#define EFFECTS_ARR(...) (const struct AdditionalEffect[]) {__VA_ARGS__}
#define ADDITIONAL_EFFECTS(...) EFFECTS_ARR( __VA_ARGS__ ), .numAdditionalEffects = ARRAY_COUNT(EFFECTS_ARR( __VA_ARGS__ ))

struct AdditionalEffect
{
    u16 moveEffect;
    u8 self:1;
    u8 onlyIfTargetRaisedStats:1;
    u8 onChargeTurnOnly:1;
    u8 chance; // 0% = effect certain, primary effect
};

struct Ability
{
    u8 name[ABILITY_NAME_LENGTH + 1];
    const u8 *description;
    u8 cantBeTraced:1; // cannot be copied by Trace
    u8 breakable:1; // can be bypassed by Mold Breaker and clones
};

enum {
    AFFINE_NONE,
    AFFINE_TURN_UP,
    AFFINE_TURN_UP_AND_DOWN,
    AFFINE_TURN_DOWN,
    AFFINE_TURN_DOWN_SLOW,
    AFFINE_TURN_DOWN_SLIGHT,
    AFFINE_TURN_UP_HIGH,
    NUM_MON_AFFINES,
};

struct NatureInfo
{
    const u8 *name;
    u8 statUp;
    u8 backAnim;
};

struct LevelUpMove
{
    enum Movimientos movimiento;
    u16 level;
};

struct FormChange
{
    u16 method;
    u16 targetSpecies;
    u16 param1;
    u16 param2;
    u16 param3;
};

#define VALOR_SHINY(personalidadPokemon) (HIHALF(PersonalidadJugador()) ^ LOHALF(PersonalidadJugador()) ^ HIHALF(personalidadPokemon) ^ LOHALF(personalidadPokemon))

extern u8 gPlayerPartyCount;
extern struct Pokemon gPlayerParty[PARTY_SIZE];
extern u8 gEnemyPartyCount;
extern struct Pokemon gEnemyParty[PARTY_SIZE];
extern struct SpriteTemplate gMultiuseSpriteTemplate;
extern u16 gFollowerSteps;

extern const struct InfoMovimiento gMovimientos[];
extern const struct SpeciesInfo gSpeciesInfo[];
extern const u32 gExperienceTables[TIPOS_CRECIMIENTO][MAX_LEVEL + 1];
extern const uq4_12_t gMultiplicadorEstadisticas[NUMERO_CAMBIOS_ESTADISTICAS];
extern const struct SpriteTemplate gBattlerSpriteTemplates[];
extern const u32 sExpCandyExperienceTable[];
extern const struct Ability gAbilitiesInfo[];
extern const struct NatureInfo gInfoNaturalezas[];

void ZeroBoxMonData(struct BoxPokemon *boxMon);
void ZeroMonData(struct Pokemon *mon);
void ZeroPlayerPartyMons(void);
void ZeroEnemyPartyMons(void);
void CreaPokemon(struct Pokemon *mon, u32 species, u32 level, bool32 hasFixedPersonality, u32 fixedPersonality);
void CreaPokemonCaja(struct BoxPokemon *boxMon, u32 especie, u32 nivel, bool32 tienePersonalidadFija, u32 personalidadFija);
void CreaPokemonConNaturaleza(struct Pokemon *mon, u32 species, u32 level, u32 nature);
void CreaPokemonConGeneroNaturaleza(struct Pokemon *mon, u32 species, u32 level, u32 gender, u32 nature);
void CalculateMonStats(struct Pokemon *mon);
void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest);
u8 GetLevelFromMonExp(struct Pokemon *mon);
u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon);
u16 GiveMoveToMon(struct Pokemon *mon, enum Movimientos movimiento);
u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, enum Movimientos movimiento);
u16 GiveMoveToBattleMon(struct BattlePokemon *mon, enum Movimientos movimiento);
void SetMonMoveSlot(struct Pokemon *mon, enum Movimientos movimiento, u8 slot);
void SetBattleMonMoveSlot(struct BattlePokemon *mon, enum Movimientos movimiento, u8 slot);
void GiveMonInitialMoveset(struct Pokemon *mon);
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, enum Movimientos movimiento);
void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, enum Movimientos movimiento);
u8 CountAliveMonsInBattle(u8 caseId, u32 battler);
u8 GetDefaultMoveTarget(u8 battlerId);
u32 AplicaTiradasShinyExtra(u32 personalidad);
u8 GetMonGender(struct Pokemon *mon);
u8 GetBoxMonGender(struct BoxPokemon *boxMon);
u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality);
bool32 IsPersonalityFemale(u16 species, u32 personality);
void SetMultiuseSpriteTemplateToPokemon(u16 speciesTag, u8 battlerPosition);
void SetMultiuseSpriteTemplateToTrainer(u16 trainerSpriteId, u8 battlerPosition);

/* GameFreak called Get(Box)MonData with either 2 or 3 arguments, for
 * type safety we have a Get(Box)MonData macro which dispatches to
 * either Get(Box)MonData2 or Get(Box)MonData3 based on the number of
 * arguments. The two functions are aliases of each other, but they
 * differ for matching purposes in the caller's codegen. */
#define GetMonData(...) CAT(GetMonData, NARG_8(__VA_ARGS__))(__VA_ARGS__)
#define GetBoxMonData(...) CAT(GetBoxMonData, NARG_8(__VA_ARGS__))(__VA_ARGS__)
u32 GetMonData3(struct Pokemon *mon, s32 field, u8 *data);
u32 GetMonData2(struct Pokemon *mon, s32 field);
u32 GetBoxMonData3(struct BoxPokemon *boxMon, s32 field, u8 *data);
u32 GetBoxMonData2(struct BoxPokemon *boxMon, s32 field);

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg);
void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg);
void CopyMon(void *dest, void *src, size_t size);
u32 GiveMonToPlayer(struct Pokemon *mon);
u32 CopyMonToPC(struct Pokemon *mon);
u8 CalculatePlayerPartyCount(void);
u8 CalculateEnemyPartyCount(void);
u8 GetMonsStateToDoubles(void);
u16 GetAbilityBySpecies(u16 species, u8 abilityNum);
u16 GetMonAbility(struct Pokemon *mon);
bool8 IsPlayerPartyAndPokemonStorageFull(void);
bool8 IsPokemonStorageFull(void);
const u8 *GetSpeciesName(u16 species);
const struct LevelUpMove *GetSpeciesLevelUpLearnset(u16 species);
const u16 *GetSpeciesTeachableLearnset(u16 species);
const u16 *GetSpeciesEggMoves(u16 species);
const struct Evolution *GetSpeciesEvolutions(u16 species);
const u16 *GetSpeciesFormTable(u16 species);
const struct FormChange *GetSpeciesFormChanges(u16 species);
u32 PPMovimiento(enum Movimientos movimiento);
void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst);
void CopyPartyMonToBattleData(u32 battlerId, u32 partyIndex);
bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex);
bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, bool8 usedByAI);
bool8 HealStatusConditions(struct Pokemon *mon, u32 healMask, u8 battlerId);
u8 GetItemEffectParamOffset(u32 battler, u16 itemId, u8 effectByte, u8 effectBit);
u8 *UseStatIncreaseItem(u16 itemId);
u32 Naturaleza(struct Pokemon *pokemon);
u32 NaturalezaDePersonalidad(u32 personalidad);
u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u16 evolutionItem);
u16 NationalPokedexNumToSpecies(u16 nationalNum);
u16 SpeciesToNationalPokedexNum(u16 species);
void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies);
u8 GetTrainerEncounterMusicId(u16 trainerOpponentId);
u32 ModificaEstadisticaPorNaturaleza(u32 naturaleza, u32 estadistica, u32 indiceEstadistica);
void AdjustFriendship(struct Pokemon *mon, u8 event);
void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies);
u16 GetMonEVCount(struct Pokemon *mon);
void RandomlyGivePartyPokerus(struct Pokemon *party);
u8 CheckPartyPokerus(struct Pokemon *party, u8 selection);
u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection);
void UpdatePartyPokerusTime(u16 days);
void PartySpreadPokerus(struct Pokemon *party);
bool8 TryIncrementMonLevel(struct Pokemon *mon);
u8 CanLearnTeachableMove(u16 species, enum Movimientos movimiento);
u8 GetMoveRelearnerMoves(struct Pokemon *mon, enum Movimientos *movimientos);
u8 GetLevelUpMovesBySpecies(u16 species, enum Movimientos *movimientos);
u8 GetNumberOfRelearnableMoves(struct Pokemon *mon);
u16 SpeciesToPokedexNum(u16 species);
u16 GetBattleBGM(void);
void PlayBattleBGM(void);
void PlayMapChosenOrBattleBGM(u16 songId);
void CreateTask_PlayMapChosenOrBattleBGM(u16 songId);
const u32 *GetMonFrontSpritePal(struct Pokemon *mon);
const u32 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, bool32 isShiny, u32 personality);
const u32 *GetMonSpritePalFromSpecies(u16 species, bool32 isShiny, bool32 isFemale);
bool8 IsMonSpriteNotFlipped(u16 species);
s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor);
s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor);
void MonRestorePP(struct Pokemon *mon);
void BoxMonRestorePP(struct BoxPokemon *boxMon);
void SetMonPreventsSwitchingString(void);
void SetWildMonHeldItem(void);
bool8 IsMonShiny(struct Pokemon *mon);
const u8 *GetTrainerPartnerName(void);
void BattleAnimateFrontSprite(struct Sprite *sprite, u16 species, bool8 noCry, u8 panMode);
void DoMonFrontSpriteAnimation(struct Sprite *sprite, u16 species, bool8 noCry, u8 panModeAnimFlag);
void PokemonSummaryDoMonAnimation(struct Sprite *sprite, u16 species, bool8 oneFrame);
void StopPokemonAnimationDelayTask(void);
void BattleAnimateBackSprite(struct Sprite *sprite, u16 species);
u16 PlayerGenderToFrontTrainerPicId(u8 playerGender);
void HandleSetPokedexFlag(u16 nationalNum, u8 caseId);
struct MonSpritesGfxManager *CreateMonSpritesGfxManager(void);
void DestroyMonSpritesGfxManager(void);
u8 *MonSpritesGfxManager_GetSpritePtr(void);
u16 GetFormSpeciesId(u16 speciesId, u8 formId);
u8 GetFormIdFromFormSpeciesId(u16 formSpeciesId);
u16 GetFormChangeTargetSpecies(struct Pokemon *mon, u16 method, u32 arg);
u16 GetFormChangeTargetSpeciesBoxMon(struct BoxPokemon *boxMon, u16 method, u32 arg);
bool32 DoesSpeciesHaveFormChangeMethod(u16 species, u16 method);
u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove);
bool32 SpeciesHasGenderDifferences(u16 species);
bool32 TryFormChange(u32 monId, u32 side, u16 method);
void TryToSetBattleFormChangeMoves(struct Pokemon *mon, u16 method);
u32 GetMonFriendshipScore(struct Pokemon *pokemon);
u8 CalculatePartyCount(struct Pokemon *party);
u16 SanitizeSpeciesId(u16 species);
bool32 IsSpeciesEnabled(u16 species);
u16 GetCryIdBySpecies(u16 species);
u16 GetSpeciesPreEvolution(u16 species);
void HealPokemon(struct Pokemon *mon);
void HealBoxPokemon(struct BoxPokemon *boxMon);
const u8 *ObtenNombreMovimiento(enum Movimientos movimiento);
const u8 *ObtenScriptAnimacionMovimiento(enum Movimientos movimiento);

#endif // GUARD_POKEMON_H

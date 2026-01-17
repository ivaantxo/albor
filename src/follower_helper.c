#include "global.h"
#include "data.h"
#include "event_scripts.h"
#include "follower_helper.h"
#include "overworld.h"
#include "rtc.h"
#include "constants/battle.h"
#include "constants/followers.h"
#include "constants/metatile_behaviors.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define TYPE_NOT_TYPE1 NUMERO_TIPOS

// difficult conditional messages follow
static const u8 sCondMsg00[] = _("{VAR_TEXTO_1} danza feliz.");
static const u8 sCondMsg01[] = _("{VAR_TEXTO_1} baila bien.");
static const u8* const sCelebiTexts[] = {sCondMsg00, sCondMsg01, NULL};
static const u8 sCondMsg02[] = _("{VAR_TEXTO_1} emitted fire and shouted.");
static const u8 sCondMsg03[] = _("¡{VAR_TEXTO_1} lanza llamas!");
static const u8 sCondMsg04[] = _("¡{VAR_TEXTO_1} escupe fuego!");
static const u8 sCondMsg05[] = _("¡{VAR_TEXTO_1} escupe fuego\nvigorosamente!");
static const u8* const sFireTexts[] = {sCondMsg02, sCondMsg03, sCondMsg04, sCondMsg05, NULL};
static const u8 sCondMsg06[] = _("{VAR_TEXTO_1} mira fijamente\nla Liga Pokémon.");
static const u8 sCondMsg07[] = _("Tu Pokémon mira con atención\nla cima de la montaña.");
static const u8 sCondMsg08[] = _("¡Algo huele muy bien aquí!");
static const u8 sCondMsg09[] = _("Your POKéMON is surveying the\nshelves restlessly.");
static const u8 sCondMsg10[] = _("{VAR_TEXTO_1} is staring intently at\nthe shelves.");
static const u8* const sShopTexts[] = {sCondMsg09, sCondMsg10, NULL};
static const u8 sCondMsg11[] = _("{VAR_TEXTO_1} focused with a sharp\ngaze!");
static const u8 sCondMsg12[] = _("{VAR_TEXTO_1} seems very interested in\nthe bicycles.");
static const u8 sCondMsg13[] = _("{VAR_TEXTO_1} seems to want to touch\nthe machines!");
static const u8 sCondMsg14[] = _("{VAR_TEXTO_1} is swaying with the\nboat!");
static const u8 sCondMsg15[] = _("{VAR_TEXTO_1} is dancing along with\nthe rolling of the ship.");
static const u8 sCondMsg16[] = _("{VAR_TEXTO_1} doesn't want to get off\nthe boat yet!");
static const u8* const sBoatTexts[] = {sCondMsg14, sCondMsg15, sCondMsg16, NULL};
static const u8 sCondMsg17[] = _("{VAR_TEXTO_1} is listening to the\nsound of the machines.");
static const u8* const sMachineTexts[] = {sCondMsg13, sCondMsg17, NULL};
static const u8 sCondMsg18[] = _("Waah! your POKéMON suddenly splashed\nwater!");
static const u8 sCondMsg19[] = _("Your POKéMON is blowing sand in the\nair!");
static const u8 sCondMsg20[] = _("{VAR_TEXTO_1} is playing around,\nplucking bits of grass.");
static const u8 sCondMsg21[] = _("¡Tu Pokémon mira feliz\ntus pisadas!");
static const u8 sCondMsg22[] = _("{VAR_TEXTO_1} siente nervios y un\npoco de claustrofobia.");
static const u8 sCondMsg23[] = _("¡{VAR_TEXTO_1} lleva cuidado\npor el poco espacio!");
static const u8* const sElevatorTexts[] = {sCondMsg22, sCondMsg23, NULL};
static const u8 sCondMsg24[] = _("A {VAR_TEXTO_1} le ha estremecido\nel viento helado!");
static const u8 sCondMsg25[] = _("¡Tu {VAR_TEXTO_1} ha resbalado\ny se ha caído!");
static const u8 sCondMsg26[] = _("Tu {VAR_TEXTO_1} parece sorprenderse\npor el hielo.");
static const u8* const sColdTexts[] = {sCondMsg24, sCondMsg25, sCondMsg26, NULL};
static const u8 sCondMsg27[] = _("¡Tu {VAR_TEXTO_1} tiene\nunas flores en la cara!");
static const u8 sCondMsg28[] = _("{VAR_TEXTO_1} gruñe por lo bajo.");
static const u8 sCondMsg29[] = _("{VAR_TEXTO_1} tiembla de miedo.");
static const u8 sCondMsg30[] = _("{VAR_TEXTO_1} parece un poco triste…");
static const u8* const sFearTexts[] = {sCondMsg29, sCondMsg30, NULL};
static const u8 sCondMsg31[] = _("{VAR_TEXTO_1} se refugia de la\nlluvia bajo la hierba.");
static const u8 sCondMsg32[] = _("{VAR_TEXTO_1} parece helarse...");
static const u8 sCondMsg33[] = _("{VAR_TEXTO_1} mira a los lejos\n hacia el mar.");
static const u8 sCondMsg34[] = _("¡{VAR_TEXTO_1} observa atentamente\nel océano!");
static const u8 sCondMsg35[] = _("{VAR_TEXTO_1} mira al inmenso\nmar.");
static const u8* const sSeaTexts[] = {sCondMsg33, sCondMsg34, sCondMsg35, NULL};
static const u8 sCondMsg36[] = _("{VAR_TEXTO_1} escucha con atención\nel sonido de la cascada.");
static const u8 sCondMsg37[] = _("¡{VAR_TEXTO_1} parece pasárselo\npipa bajo la lluvia!");
static const u8 sCondMsg38[] = _("{VAR_TEXTO_1} mira fijamente\nsu reflejo en el agua.");
static const u8 sCondMsg39[] = _("{VAR_TEXTO_1} parece relajarse\ncon el sonido de las hojas…");
static const u8 sCondMsg40[] = _("{VAR_TEXTO_1} está mordisqueando\nel hielo.");
static const u8 sCondMsg41[] = _("{VAR_TEXTO_1} toca el hielo.");
static const u8* const sIceTexts[] = {sCondMsg26, sCondMsg40, sCondMsg41, NULL};
static const u8 sCondMsg42[] = _("¡La quemadura de {VAR_TEXTO_1}\nparece muy dolorosa!");
static const u8 sCondMsg43[] = _("¡A {VAR_TEXTO_1} le encanta\nestar en la calle!");
static const u8 sCondMsg44[] = _("{VAR_TEXTO_1} mira atentamente\nhacia las nubes.");
static const u8* const sDayTexts[] = {sCondMsg43, sCondMsg44, NULL};
static const u8 sCondMsg45[] = _("¡A {VAR_TEXTO_1} le hechiza\nel cielo nocturno!");
static const u8 sCondMsg46[] = _("¡{VAR_TEXTO_1} se emboba\nmirando las estrellas!");
static const u8* const sNightTexts[] = {sCondMsg45, sCondMsg46, NULL};

// See the struct definition in follower_helper.h for more info
const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT] =
{
    [COND_MSG_CELEBI] =
    {
        .text = (u8*)sCelebiTexts,
        .textSpread = 1,
        .script = EventScript_FollowerDance,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_SPECIES(SPECIES_CELEBI),
        },
    },
    [COND_MSG_FIRE] =
    {
        .text = (u8*)sFireTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_TYPES(TIPO_FUEGO, TIPO_FUEGO),
        },
    },
    [COND_MSG_EVER_GRANDE] =
    {
        .text = sCondMsg06,
        .script = EventScript_FollowerFaceUp,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            //MATCH_MAP(EVER_GRANDE_CITY),
        },
    },
    [COND_MSG_ROUTE_112] =
    {
        .text = sCondMsg07,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            //MATCH_MAP(ROUTE112),
        },
    },
    [COND_MSG_DAY_CARE] =
    {
        .text = sCondMsg08,
        .script = EventScript_FollowerNostalgia,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            //MATCH_MAP(ROUTE117_POKEMON_DAY_CARE)
        },
    },
    [COND_MSG_MART] =
    {
        .text = (u8*)sShopTexts,
        .textSpread = 1,
        .script = EventScript_FollowerLookAround,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MUSIC(MUS_POKE_MART)
        },
    },
    [COND_MSG_VICTORY_ROAD] =
    {
        .text = sCondMsg11,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MUSIC(MUS_VICTORY_ROAD)
        },
    },
    [COND_MSG_BIKE_SHOP] =
    {
        .text = sCondMsg12,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            //MATCH_MAP(MAUVILLE_CITY_BIKE_SHOP)
        },
    },
    [COND_MSG_MACHINES] =
    {
        .text = (u8*)sMachineTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .orFlag = 1, // match any of these maps
        .conditions =
        {
            //MATCH_MAP(NEW_MAUVILLE_INSIDE),
            //MATCH_MAP(SLATEPORT_CITY_STERNS_SHIPYARD_1F),
            //MATCH_MAP(SLATEPORT_CITY_STERNS_SHIPYARD_2F),
        },
    },
    [COND_MSG_SAILING] =
    {
        .text = (u8*)sBoatTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .script = EventScript_FollowerLookAround,
        .conditions =
        {
            MATCH_MUSIC(MUS_SAILING),
        },
    },
    [COND_MSG_PUDDLE] =
    {
        .text = sCondMsg18,
        .script = EventScript_FollowerHopping,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SHALLOW_WATER, MB_PUDDLE),
        },
    },
    [COND_MSG_SAND] =
    {
        .text = sCondMsg19,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_DEEP_SAND),
        },
    },
    [COND_MSG_GRASS] =
    {
        .text = sCondMsg20,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_TALL_GRASS, MB_LONG_GRASS),
        },
    },
    [COND_MSG_FOOTPRINTS] =
    {
        .text = sCondMsg21,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_FOOTPRINTS),
        },
    },
    [COND_MSG_ELEVATOR] =
    {
        .text = (u8*)sElevatorTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            //MATCH_MAP(LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR),
        },
    },
    [COND_MSG_ICE_ROOM] =
    {
        .text = (u8*)sColdTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            //MATCH_MAP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        },
    },
    [COND_MSG_ROUTE_117] =
    {
        .text = sCondMsg27,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            //MATCH_MAP(ROUTE117),
        },
    },
    [COND_MSG_DRAGON_GROWL] =
    {
        .text = sCondMsg28,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TIPO_DRAGON, TIPO_DRAGON),
            //MATCH_MAPSEC(MAPSEC_SKY_PILLAR),
        },
    },
    [COND_MSG_FEAR] =
    {
        .text = (u8*)sFearTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_NOT_TYPES(TIPO_FANTASMA, TIPO_FANTASMA),
            //MATCH_MAPSEC(MAPSEC_MT_PYRE),
            MATCH_MUSIC(MUS_MT_PYRE),
        },
    },
    [COND_MSG_FIRE_RAIN] =
    {
        .text = sCondMsg31,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TIPO_FUEGO, TIPO_FUEGO),
            MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM),
        },
    },
    [COND_MSG_FROZEN] =
    {
        .text = sCondMsg32,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
           MATCH_STATUS(STATUS1_FREEZE),
        },
    },
    [COND_MSG_SEASIDE] =
    {
        .text = (u8*)sSeaTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_OCEAN_WATER, 5),
        },
    },
    [COND_MSG_WATERFALL] =
    {
        .text = sCondMsg36,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_WATERFALL, 5),
        },
    },
    [COND_MSG_RAIN] =
    {
        .text = sCondMsg37,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
        MATCH_NOT_TYPES(TIPO_FUEGO, TIPO_FUEGO),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM)
    }
    },
    [COND_MSG_REFLECTION] =
    {
        .text = sCondMsg38,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_POND_WATER, 1),
        },
    },
    [COND_MSG_LEAVES] =
    {
        .text = sCondMsg39,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
    },
    [COND_MSG_ICE] =
    {
        .text = (u8*)sIceTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_ICE, 1),
        },
    },
    [COND_MSG_BURN] =
    {
        .text = sCondMsg42,
        .emotion = FOLLOWER_EMOTION_SAD,
        .conditions =
        {
            MATCH_STATUS(STATUS1_BURN),
        },
    },
    [COND_MSG_DAY] =
    {
    .text = (u8*)sDayTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_TIME_OF_DAY(TIEMPO_DIA)},
    },
    [COND_MSG_NIGHT] =
    {
    .text = (u8*)sNightTexts,
    .textSpread = 1,
    .emotion = FOLLOWER_EMOTION_MUSIC,
    .conditions = {MATCH_TIME_OF_DAY(TIEMPO_NOCHE)},
    },
};

// Pool of "unconditional" follower messages
const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH] =
{
    [FOLLOWER_EMOTION_HAPPY]    = {gFollowerHappyMessages,    EventScript_FollowerGeneric, FOLLOWER_HAPPY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_NEUTRAL]  = {gFollowerNeutralMessages,  EventScript_FollowerGeneric, FOLLOWER_NEUTRAL_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SAD]      = {gFollowerSadMessages,      EventScript_FollowerGeneric, FOLLOWER_SAD_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_UPSET]    = {gFollowerUpsetMessages,    EventScript_FollowerGeneric, FOLLOWER_UPSET_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_ANGRY]    = {gFollowerAngryMessages,    EventScript_FollowerGeneric, FOLLOWER_ANGRY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_PENSIVE]  = {gFollowerPensiveMessages,  EventScript_FollowerGeneric, FOLLOWER_PENSIVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_LOVE]     = {gFollowerLoveMessages,     EventScript_FollowerGeneric, FOLLOWER_LOVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SURPRISE] = {gFollowerSurpriseMessages, EventScript_FollowerGeneric, FOLLOWER_SURPRISE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_CURIOUS]  = {gFollowerCuriousMessages,  EventScript_FollowerGeneric, FOLLOWER_CURIOUS_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_MUSIC]    = {gFollowerMusicMessages,    EventScript_FollowerGeneric, FOLLOWER_MUSIC_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_POISONED] = {gFollowerPoisonedMessages, EventScript_FollowerGeneric, FOLLOWER_POISONED_MESSAGE_COUNT},
};

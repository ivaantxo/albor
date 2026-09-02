#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include <limits.h>
#include "config/general.h" // we need to define config before gba headers as print stuff needs the functions nulled before defines.
#include "gba/gba.h"
#include "fpmath.h"
#include "metaprogram.h"
#include "constants/global.h"
#include "constants/etiquetas.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/species.h"
#include "constants/pokedex.h"
#include "constants/berry.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/items.h"

#define NAKED __attribute__((naked))

/// IDE support
#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__INTELLISENSE__)
// We define these when using certain IDEs to fool preproc
#define _(x)        {x}
#define __(x)       {x}
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#define abs(x) (((x) < 0) ? -(x) : (x))

#define SAFE_DIV(a, b) (((b) != 0) ? (a) / (b) : 0)

// The below macro does a%n, but (to match) will switch to a&(n-1) if n is a power of 2.
// There are cases where GF does a&(n-1) where we would really like to have a%n, because
// if n is changed to a value that isn't a power of 2 then a&(n-1) is unlikely to work as
// intended, and a%n for powers of 2 isn't always optimized to use &.
#define MOD(a, n) (((n) & ((n)-1)) ? ((a) % (n)) : ((a) & ((n)-1)))

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8 *) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void *) T2_READ_32(ptr)

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)
#define JOY_HELD_RAW(button) TEST_BUTTON(gMain.heldKeysRaw, button)
#define JOY_REPEAT(button) TEST_BUTTON(gMain.newAndRepeatedKeys, button)

#define S16TOPOSFLOAT(val)   \
({                           \
    s16 v = (val);           \
    float f = (float)v;      \
    if(v < 0) f += 65536.0f; \
    f;                       \
})

#define DIV_ROUND_UP(val, roundBy) (((val) / (roundBy)) + (((val) % (roundBy)) ? 1 : 0))

#define ROUND_BITS_TO_BYTES(numBits) DIV_ROUND_UP(numBits, 8)

#define NUM_DEX_FLAG_BYTES ROUND_BITS_TO_BYTES(DEX_COUNT)
#define NUM_FLAG_BYTES ROUND_BITS_TO_BYTES(FLAGS_COUNT)

// Las banderas que van a la partida, cada familia en su propio array.
//
// Antes eran un unico bloque y los grupos se delimitaban con aritmetica repetida en
// cada sitio que los borraba: un desplazamiento inicial y un tamano calculados a mano.
// Eso tenia dos problemas. Uno, que equivocarse era facil y silencioso -un tamano mal
// calculado dejaba un grupo sin borrar o pisaba el siguiente-. Y dos, que anadir una
// bandera de guion desplazaba TODAS las de detras, incluidas las diarias, invalidando
// mas partida de la necesaria.
//
// Separados, cada grupo se borra con sizeof y crece sin mover a los demas. Las
// especiales no estan aqui: viven en EWRAM y no se guardan.
struct BanderasGuardadas
{
    // Se borran al cargar cualquier mapa.
    u8 temporales[ROUND_BITS_TO_BYTES(NUM_TEMP_FLAGS + 1)];

    // Progreso y sucesos del mundo. Permanentes.
    u8 guion[ROUND_BITS_TO_BYTES(BANDERAS_GUION_FIN - TEMP_FLAGS_END)];

    // Estado del sistema y del jugador. Permanentes.
    u8 sistema[ROUND_BITS_TO_BYTES(BANDERAS_SISTEMA_FIN - SYSTEM_FLAGS)];

    // Se borran al cambiar el dia.
    u8 diarias[ROUND_BITS_TO_BYTES(NUM_DAILY_FLAGS + 1)];

    // Una por entrenador, indexada por su identificador. En este proyecto tambien se
    // borran a diario, asi que todos vuelven a ser combatibles cada dia.
    u8 entrenadores[ROUND_BITS_TO_BYTES(TRAINERS_COUNT)];
};
#define NUM_TRAINER_FLAG_BYTES ROUND_BITS_TO_BYTES(TRAINERS_COUNT)

// This produces an error at compile-time if expr is zero.
// It looks like file.c:line: size of array `id' is negative
#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

#define FEATURE_FLAG_ASSERT(flag, id) STATIC_ASSERT(flag > TEMP_FLAGS_END || flag == 0, id)

struct Coords8
{
    s8 x;
    s8 y;
};

struct UCoords8
{
    u8 x;
    u8 y;
};

struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct UCoords32
{
    u32 x;
    u32 y;
};

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

#include "constants/items.h"
#define ITEM_FLAGS_COUNT ((ITEMS_COUNT / 8) + ((ITEMS_COUNT % 8) ? 1 : 0))

extern u32 ActualizaPaletaSpriteSegunHora(u32 numeroPaleta);

struct SecretBaseParty
{
    u32 personality[PARTY_SIZE];
    u16 moves[PARTY_SIZE * MAXIMO_MOVIMIENTOS_POKEMON];
    u16 species[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    u8 levels[PARTY_SIZE];
    u8 EVs[PARTY_SIZE];
};

struct SecretBase
{
    /*0x1A9C*/ u8 secretBaseId;
    /*0x1A9D*/ bool8 toRegister:4;
    /*0x1A9D*/ u8 gender:1;
    /*0x1A9D*/ u8 battledOwnerToday:1;
    /*0x1A9D*/ u8 registryStatus:2;
    /*0x1A9E*/ u8 trainerName[MAXIMO_CARACTERES_NOMBRE_JUGADOR];
    /*0x1AA5*/ u8 trainerId[TRAINER_ID_LENGTH]; // byte 0 is used for determining trainer class
    /*0x1AA9*/ u8 language;
    /*0x1AAA*/ u16 numSecretBasesReceived;
    /*0x1AAC*/ u8 numTimesEntered;
    /*0x1AAE*/ u8 decorations[DECOR_MAX_SECRET_BASE];
    /*0x1ABE*/ u8 decorationPositions[DECOR_MAX_SECRET_BASE];
    /*0x1AD0*/ struct SecretBaseParty party;
};

#include "constants/game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "pokemon.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    u32 steps;
};

struct DayCare
{
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u32 offspringPersonality;
    u8 stepCounter;
};

struct MapPosition
{
    s16 x;
    s16 y;
    s8 elevation;
};

// ---------------------------------------------------------------------------
// El bloque de guardado
//
// Va al final del fichero a proposito: necesita que esten definidas todas las
// estructuras de arriba, y asi se ve de un vistazo que no depende de nada mas.
//
// Sobre los tipos. La EWRAM tiene un bus de 16 bits: leer un u16 o un u8 cuesta
// un acceso y leer un u32 cuesta dos. Aqui ancho no es rapido, es lo contrario,
// asi que solo hay u32 donde el valor no cabe en 16 bits. Y no hay campos de
// bits salvo las banderas, que son bits por definicion: empaquetar obliga a
// desplazar y enmascarar en cada lectura, y a leer-modificar-escribir en cada
// escritura, a cambio de unos bytes que aqui sobran.
//
// Sitio libre: el menu de depuracion, Utilities -> SaveBlock, lo dice.
// ---------------------------------------------------------------------------
struct SaveBlock
{
    // --- Jugador ---
    u32 personalidadJugador;
    u8 nombreJugador[MAXIMO_CARACTERES_NOMBRE_JUGADOR + 1];
    u8 playerGender; // MALE, FEMALE

    // --- Opciones ---
    // Sueltas y de un byte cada una: antes iban empaquetadas en un u16 y
    // optionsTextSpeed se consulta en cada linea de texto que se imprime.
    u8 optionsButtonMode;        // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    u8 optionsTextSpeed;         // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
    u8 optionsWindowFrameType;   // uno de los bordes decorativos de los cuadros de texto
    u8 optionsSound;             // OPTIONS_SOUND_[MONO/STEREO]
    u8 optionsBattleSceneOff;    // si las animaciones de combate estan apagadas
    u8 regionMapZoom;            // si el mapa esta acercado

    // --- Tiempo ---
    // RECORDATORIO: playTime y gameClock son el MISMO contador con dos escalas.
    // Aqui no hay reloj de cartucho: Rtc_GetCurrentTime devuelve gameClock, y a
    // gameClock solo lo mueve PlayTimeCounter_Update, una vez por segundo real,
    // sumandole Rtc_GetSecondsRatio() -hoy 20- segundos de juego. O sea que
    // gameClock == playTime * 20 salvo por dos cosas: OW_FLAG_PAUSE_TIME para
    // uno y no el otro, y quien llame a Rtc_AdvanceTimeBy a mano.
    // Uno de los dos se puede derivar del otro y ahorrarse el campo; lo que no
    // se deriva es localTimeOffset, que es la hora que eligio el jugador.
    u16 playTimeHours;
    u8 playTimeMinutes;
    u8 playTimeSeconds;
    u8 playTimeVBlanks;
    struct Time gameClock;
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;

    // --- Posicion y mapa ---
    struct Coords16 pos;
    struct WarpData location;
    struct WarpData continueGameWarp;
    struct WarpData dynamicWarp;
    struct WarpData lastHealLocation; // usado por la derrota y por Teletransporte
    struct WarpData escapeWarp;       // usado por Excavar y Cuerda Huida
    u16 savedMusic;
    u16 mapLayoutId;
    u8 specialSaveWarpFlags;
    u8 weather;
    u8 weatherCycleStage;
    u8 flashLevel;
    u16 mapView[256];

    // --- Equipo ---
    struct Pokemon playerParty[PARTY_SIZE];
    u8 playerPartyCount;

    // --- Dinero y mochila ---
    u32 money;
    u16 registeredItem; // el que responde al boton SELECT
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    u8 itemFlags[ITEM_FLAGS_COUNT];

    // --- Lo que hay puesto en el mapa ---
    struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];

    // --- Estado del guion ---
    struct BanderasGuardadas banderas;
    u16 vars[VARS_COUNT];
    u32 gameStats[NUM_GAME_STATS]; // contadores que se pasan de 65535

    // --- Pokedex ---
    u8 dexSeen[NUM_DEX_FLAG_BYTES];
    u8 dexCaught[NUM_DEX_FLAG_BYTES];

    // --- Otros sistemas ---
    struct BerryTree berryTrees[BERRY_TREES_COUNT];
    struct DayCare daycare;
};

extern struct SaveBlock *gSaveBlockPtr;

#endif // GUARD_GLOBAL_H

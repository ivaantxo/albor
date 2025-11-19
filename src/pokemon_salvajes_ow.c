#include "global.h"
#include "pokemon_salvajes_ow.h"
#include "constants/pokemon_salvajes_ow.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "random.h"
#include "overworld.h"
#include "object_event.h"
#include "event_object_movement.h"
#include "wild_encounter.h"
#include "battle_setup.h"
#include "script.h"

static struct PokemonSalvajeOw sPokemonSalvajesOw[MAXIMO_POKEMON_SALVAJES_OW];

static bool32 EsVisibleEnCamara(s16 x, s16 y)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    if (x < (xJugador - VISIBILIDAD_POKEMON_SALVAJE_OW) || x > (xJugador + VISIBILIDAD_POKEMON_SALVAJE_OW))
        return FALSE;
    if (y < (yJugador - VISIBILIDAD_POKEMON_SALVAJE_OW) || y > (yJugador + VISIBILIDAD_POKEMON_SALVAJE_OW))
        return FALSE;

    return TRUE;
}

static bool32 EsTileDeHierba(s16 x, s16 y)
{
    u32 comportamientoMetatile = MapGridGetMetatileBehaviorAt(x, y);
    return MetatileBehavior_IsTallGrass(comportamientoMetatile);
}

static bool32 EstaDemasiadoCercaDeJugador(s16 x, s16 y)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    s16 distanciaHorizontal = abs(x - xJugador);
    s16 distanciaVertical = abs(y - yJugador);

    return (distanciaHorizontal <= DISTANCIA_MINIMA_POKEMON_SALVAJE_OW && distanciaVertical <= DISTANCIA_MINIMA_POKEMON_SALVAJE_OW);
}

static const struct WildPokemonHeader *ObtenHeaderPokemonSalvajeDeMapa(void)
{
    u32 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *header = &gWildMonHeaders[i];

        if (header->mapGroup == MAP_GROUP(UNDEFINED))
            return NULL;

        if (header->mapGroup == gSaveBlockPtr->location.mapGroup &&
            header->mapNum  == gSaveBlockPtr->location.mapNum)
        {
            return header;
        }
    }
}

static void GeneraEspeciePokemonOw(u16 *especie, u8 *nivel)
{
    const struct WildPokemonHeader *header = ObtenHeaderPokemonSalvajeDeMapa();
    if (header == NULL || header->landMonsInfo == NULL)
        return;

    const struct WildPokemonInfo *info = header->landMonsInfo;
    u32 index = ChooseWildMonIndex_Land();
    *especie = info->wildPokemon[index].species;
    *nivel = ChooseWildMonLevel(info->wildPokemon, index, WILD_AREA_LAND);
}

static u8 CreateWildOwObject(struct PokemonSalvajeOw *slot)
{
    struct ObjectEventTemplate tmpl = {0};

    tmpl.graphicsId = OBJ_EVENT_GFX_MON_ICON;     // usa tu sprite de follower compartido
    tmpl.localId = OBJ_EVENT_ID_PLAYER + 20;      // ID alto para evitar conflictos
    tmpl.x = slot->x;
    tmpl.y = slot->y;
    tmpl.movementType = MOVEMENT_TYPE_WANDER_AROUND; // movimiento base
    tmpl.elevation = 1;

    u8 id = SpawnObjectEvent(&tmpl);
    return id;
}

// ------------------------------------------------------
// Intento de spawn
// ------------------------------------------------------
static void TrySpawnOwMonsterAt(s16 x, s16 y)
{
    if (Random() % FRECUENCIA_APARICION_POKEMON_SALVAJES_OW != 0)
        return;

    for (int i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        struct PokemonSalvajeOw *s = &sPokemonSalvajesOw[i];

        if (s->estado == ESTADO_POKEMON_SALVAJE_INACTIVO)
        {
            if (!GenerateWildSpecies(&s->especie, &s->nivel))
                return;

            s->x = x;
            s->y = y;
            s->estado = ESTADO_POKEMON_SALVAJE_ACTIVO;
            s->personalidad = Random();

            s->idObjetoEvento = CreateWildOwObject(s);
            return;
        }
    }
}

// ------------------------------------------------------
// Movimiento aleatorio simple por hierba
// ------------------------------------------------------
static void MoveOwMonster(struct PokemonSalvajeOw *s)
{
    if (Random() & 1)
        return;

    s16 nx = s->x;
    s16 ny = s->y;

    switch (Random() & 3)
    {
    case 0:
        nx++;
        break;
    case 1:
        nx--;
        break;
    case 2:
        ny++;
        break;
    case 3:
        ny--;
        break;
    }

    if (!EsTileDeHierba(nx, ny))
        return;

    MoveObjectEventToPosition(&gObjectEvents[s->idObjetoEvento], nx, ny);
    s->x = nx;
    s->y = ny;
}

static bool8 IsAdjacentToPlayer(s16 x, s16 y)
{
    s16 px, py;
    PlayerGetDestCoords(&px, &py);

    if ((abs(px - x) + abs(py - y)) == 1)
        return TRUE;

    return FALSE;
}

static void StartOwBattle(struct PokemonSalvajeOw *s)
{
    CreateWildMon(s->especie, s->nivel);

    gEnemyParty[0].personality = s->personalidad;

    gObjectEvents[s->idObjetoEvento].active = FALSE;
    s->estado = ESTADO_POKEMON_SALVAJE_INACTIVO;

    DoStandardWildBattle();
}

void PokemonSalvajesOw_Update(void)
{
    s16 px, py;
    PlayerGetDestCoords(&px, &py);

    for (s16 dx = -8; dx <= 8; dx++)
    {
        for (s16 dy = -6; dy <= 6; dy++)
        {
            s16 x = px + dx;
            s16 y = py + dy;

            if (!EsTileDeHierba(x, y))
                continue;

            if (!EsVisibleEnCamara(x, y))
                continue;

            if (EstaDemasiadoCercaDeJugador(x, y))
                continue;

            TrySpawnOwMonsterAt(x, y);
        }
    }

    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        struct PokemonSalvajeOw *s = &sPokemonSalvajesOw[i];
        if (s->estado != ESTADO_POKEMON_SALVAJE_ACTIVO)
            continue;

        MoveOwMonster(s);

        if (IsAdjacentToPlayer(s->x, s->y))
        {
            StartOwBattle(s);
            return;
        }
    }
}

void IniciarPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
        sPokemonSalvajesOw[i].estado = ESTADO_POKEMON_SALVAJE_INACTIVO;
}

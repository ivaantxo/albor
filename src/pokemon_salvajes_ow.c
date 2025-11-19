#include "global.h"
#include "pokemon_salvajes_ow.h"
#include "constants/pokemon_salvajes_ow.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "random.h"
#include "overworld.h"
#include "event_object_movement.h"
#include "wild_encounter.h"
#include "battle_setup.h"
#include "script.h"
#include "constants/event_objects.h"
#include "constants/wild_encounter.h"

static u8 sPrevTileTransitionState = T_NOT_MOVING;
static u8 sTemporizadorGeneracion = 0;
static struct PokemonSalvajeOw sPokemonSalvajesOw[MAXIMO_POKEMON_SALVAJES_OW];

static bool32 EsTileDeHierba(s16 x, s16 y)
{
    u32 comportamientoMetatile = MapGridGetMetatileBehaviorAt(x, y);
    return MetatileBehavior_IsTallGrass(comportamientoMetatile);
}

static bool32 EstaTileOcupado(s16 x, s16 y)
{
    u32 objId = GetObjectEventIdByXY(x, y);
    return (objId != OBJECT_EVENTS_COUNT);
}

static bool32 EstaDemasiadoCercaDeJugador(s16 x, s16 y)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    return (abs(x - xJugador) <= DISTANCIA_MINIMA_POKEMON_SALVAJE_OW
         && abs(y - yJugador) <= DISTANCIA_MINIMA_POKEMON_SALVAJE_OW);
}

bool32 JugadorHaDadoUnPaso(void)
{
    return gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION;
}

static const struct WildPokemonHeader *ObtenHeaderPokemonSalvajeDeMapa(void)
{
    u32 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *header = &gWildMonHeaders[i];

        if (header->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            return NULL;

        if (header->mapGroup == gSaveBlockPtr->location.mapGroup &&
            header->mapNum  == gSaveBlockPtr->location.mapNum)
        {
            return header;
        }
    }
}

static bool32 GeneraEspeciePokemonOw(u16 *especie, u8 *nivel)
{
    const struct WildPokemonHeader *header = ObtenHeaderPokemonSalvajeDeMapa();
    if (header == NULL || header->landMonsInfo == NULL)
        return FALSE;

    const struct WildPokemonInfo *info = header->landMonsInfo;

    u32 indice = ChooseWildMonIndex_Land();
    *especie = info->wildPokemon[indice].species;
    *nivel   = ChooseWildMonLevel(info->wildPokemon, indice, WILD_AREA_LAND);

    return TRUE;
}

static u32 CreaObjetoPokemonSalvajeOw(struct PokemonSalvajeOw *pokemonSalvaje, u32 indice)
{
    struct ObjectEventTemplate plantilla = {0};

    plantilla.graphicsId = pokemonSalvaje->especie + OBJ_EVENT_MON;

    // ❗ Corregido: localId no puede ser LOCALID_NONE
    plantilla.localId = (u8)(indice + 1);

    plantilla.x = pokemonSalvaje->x;
    plantilla.y = pokemonSalvaje->y;
    plantilla.movementType = MOVEMENT_TYPE_WANDER_AROUND;

    u32 id = SpawnSpecialObjectEvent(&plantilla);
    if (id == OBJECT_EVENTS_COUNT)
        return OBJECT_EVENTS_COUNT;

    pokemonSalvaje->idObjetoEvento = id;
    return id;
}

static void EliminarObjetoPokemonOw(struct PokemonSalvajeOw *pokemonSalvaje)
{
    if (pokemonSalvaje->idObjetoEvento != OBJECT_EVENTS_COUNT)
    {
        RemoveObjectEvent(&gObjectEvents[pokemonSalvaje->idObjetoEvento]);
        pokemonSalvaje->idObjetoEvento = OBJECT_EVENTS_COUNT;
    }
    pokemonSalvaje->estado = ESTADO_POKEMON_SALVAJE_INACTIVO;
}

static void MuevePokemonOw(struct PokemonSalvajeOw *pokemon)
{
    s16 nuevaX = pokemon->x;
    s16 nuevaY = pokemon->y;

    switch (Random() & 3)
    {
        case 0: nuevaX++; break;
        case 1: nuevaX--; break;
        case 2: nuevaY++; break;
        case 3: nuevaY--; break;
    }

    if (!EsTileDeHierba(nuevaX, nuevaY))
        return;

    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);
    if (nuevaX == xJugador && nuevaY == yJugador)
        return;

    if (EstaTileOcupado(nuevaX, nuevaY))
        return;

    MoveObjectEventToMapCoords(&gObjectEvents[pokemon->idObjetoEvento], nuevaX, nuevaY);

    pokemon->x = nuevaX;
    pokemon->y = nuevaY;
}

static bool32 EsAdyacenteAJugador(s16 x, s16 y)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    return (abs(xJugador - x) + abs(yJugador - y)) == 1;
}

static void EmpiezaBatallaPokemonSalvajeOw(struct PokemonSalvajeOw *pokemonSalvaje)
{
    CreateWildMon(pokemonSalvaje->especie, pokemonSalvaje->nivel);

    gEnemyParty[0].box.personality = pokemonSalvaje->personalidad;
    CalculateMonStats(&gEnemyParty[0]);   // ✔ necesario

    EliminarObjetoPokemonOw(pokemonSalvaje);

    DoStandardWildBattle();
}

void ActualizarPokemonSalvajesOw(void)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    if (sTemporizadorGeneracion > 0)
        sTemporizadorGeneracion--;
    bool32 intentoSpawn = (sTemporizadorGeneracion == 0);
    if (intentoSpawn)
        sTemporizadorGeneracion = 20;

    bool32 spawnedThisCycle = FALSE;

    if (intentoSpawn)
    {
        for (s16 dx = -VISIBILIDAD_POKEMON_SALVAJE_OW; dx <= VISIBILIDAD_POKEMON_SALVAJE_OW && !spawnedThisCycle; dx++)
        {
            for (s16 dy = -VISIBILIDAD_POKEMON_SALVAJE_OW; dy <= VISIBILIDAD_POKEMON_SALVAJE_OW && !spawnedThisCycle; dy++)
            {
                s16 x = xJugador + dx;
                s16 y = yJugador + dy;

                if (!EsTileDeHierba(x, y))
                    continue;

                if (EstaDemasiadoCercaDeJugador(x, y))
                    continue;

                if (Random() % FRECUENCIA_APARICION_POKEMON_SALVAJES_OW != 0)
                    continue;

                for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
                {
                    struct PokemonSalvajeOw *p = &sPokemonSalvajesOw[i];

                    if (p->estado == ESTADO_POKEMON_SALVAJE_INACTIVO)
                    {
                        if (!GeneraEspeciePokemonOw(&p->especie, &p->nivel))
                            continue;

                        p->x = x;
                        p->y = y;
                        p->estado = ESTADO_POKEMON_SALVAJE_ACTIVO;
                        p->personalidad = Random();
                        p->temporizador = 0;
                        p->idObjetoEvento = OBJECT_EVENTS_COUNT;

                        u32 id = CreaObjetoPokemonSalvajeOw(p, i);
                        if (id != OBJECT_EVENTS_COUNT)
                        {
                            spawnedThisCycle = TRUE;
                            break;
                        }
                        else
                        {
                            p->estado = ESTADO_POKEMON_SALVAJE_INACTIVO;
                        }
                    }
                }
            }
        }
    }

    bool32 jugadorHaEmpezadoPaso = FALSE;

    u32 state = gPlayerAvatar.tileTransitionState;

    // Detectar SOLO cuando pasa de quieto a empezar transición
    if (sPrevTileTransitionState == T_NOT_MOVING
    && state == T_TILE_TRANSITION)
    {
        jugadorHaEmpezadoPaso = TRUE;
    }

    sPrevTileTransitionState = state;
    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        struct PokemonSalvajeOw *p = &sPokemonSalvajesOw[i];
        if (p->estado != ESTADO_POKEMON_SALVAJE_ACTIVO)
            continue;

        if (jugadorHaEmpezadoPaso)
            p->temporizador = 1;

        if (p->temporizador > 0)
        {
            p->temporizador--;
            if (p->temporizador == 0)
                MuevePokemonOw(p);
        }

        if (EsAdyacenteAJugador(p->x, p->y))
        {
            EmpiezaBatallaPokemonSalvajeOw(p);
            return;
        }
    }
}

void IniciarPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        if (sPokemonSalvajesOw[i].idObjetoEvento != OBJECT_EVENTS_COUNT)
            EliminarObjetoPokemonOw(&sPokemonSalvajesOw[i]);

        sPokemonSalvajesOw[i].estado = ESTADO_POKEMON_SALVAJE_INACTIVO;
        sPokemonSalvajesOw[i].idObjetoEvento = OBJECT_EVENTS_COUNT;
        sPokemonSalvajesOw[i].temporizador = 0;
    }
    sTemporizadorGeneracion = 0;
}

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

static struct PokemonSalvajeOw sPokemonSalvajesOw[MAXIMO_POKEMON_SALVAJES_OW];

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

static u32 CreaObjetoPokemonSalvajeOw(struct PokemonSalvajeOw *pokemonSalvaje, u8 indice)
{
    struct ObjectEventTemplate plantilla = {0};
    // Por ahora, solo especie sin shiny/female
    plantilla.graphicsId = pokemonSalvaje->especie + OBJ_EVENT_MON;

    plantilla.localId = 200 + indice;
    plantilla.x = pokemonSalvaje->x;
    plantilla.y = pokemonSalvaje->y;
    plantilla.movementType = MOVEMENT_TYPE_WANDER_AROUND;
    plantilla.elevation = 1;

    u32 id = SpawnSpecialObjectEvent(&plantilla);

    if (id == OBJECT_EVENTS_COUNT)
        return 0;

    pokemonSalvaje->idObjetoEvento = id;
    return id;
}

static void IntentaCrearPokemonEnPosicion(s16 x, s16 y)
{
    if (Random() % FRECUENCIA_APARICION_POKEMON_SALVAJES_OW != 0)
        return;

    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        struct PokemonSalvajeOw *pokemonSalvaje = &sPokemonSalvajesOw[i];

        if (pokemonSalvaje->estado == ESTADO_POKEMON_SALVAJE_INACTIVO)
        {
            if (!GeneraEspeciePokemonOw(&pokemonSalvaje->especie, &pokemonSalvaje->nivel))
                return;

            pokemonSalvaje->x = x;
            pokemonSalvaje->y = y;
            pokemonSalvaje->estado = ESTADO_POKEMON_SALVAJE_ACTIVO;
            pokemonSalvaje->personalidad = Random();

            pokemonSalvaje->idObjetoEvento = CreaObjetoPokemonSalvajeOw(pokemonSalvaje, i);
            return;
        }
    }
}

static void MuevePokemonOw(struct PokemonSalvajeOw *pokemon)
{
    s16 nuevaXPokemon = pokemon->x;
    s16 nuevaYPokemon = pokemon->y;

    switch (Random() & 3)
    {
    case 0:
        nuevaXPokemon++;
        break;
    case 1:
        nuevaXPokemon--;
        break;
    case 2:
        nuevaYPokemon++;
        break;
    case 3:
        nuevaYPokemon--;
        break;
    }

    if (!EsTileDeHierba(nuevaXPokemon, nuevaYPokemon))
        return;

    MoveObjectEventToMapCoords(&gObjectEvents[pokemon->idObjetoEvento], nuevaXPokemon, nuevaYPokemon); // ???
    pokemon->x = nuevaXPokemon;
    pokemon->y = nuevaYPokemon;
}

static bool32 EsAdyacenteAJugador(s16 x, s16 y)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    if ((abs(xJugador - x) + abs(yJugador - y)) == 1)
        return TRUE;

    return FALSE;
}

static void EmpiezaBatallaPokemonSalvajeOw(struct PokemonSalvajeOw *pokemonSalvaje)
{
    CreateWildMon(pokemonSalvaje->especie, pokemonSalvaje->nivel);

    gEnemyParty[0].box.personality = pokemonSalvaje->personalidad; // ?????

    gObjectEvents[pokemonSalvaje->idObjetoEvento].active = FALSE;
    pokemonSalvaje->estado = ESTADO_POKEMON_SALVAJE_INACTIVO;

    DoStandardWildBattle();
}

void ActualizarPokemonSalvajesOw(void)
{
    s16 xJugador, yJugador;
    PlayerGetDestCoords(&xJugador, &yJugador);

    for (s16 distanciaHorizontal = -VISIBILIDAD_POKEMON_SALVAJE_OW; distanciaHorizontal <= VISIBILIDAD_POKEMON_SALVAJE_OW; distanciaHorizontal++)
    {
        for (s16 distanciaVertical = -VISIBILIDAD_POKEMON_SALVAJE_OW; distanciaVertical <= VISIBILIDAD_POKEMON_SALVAJE_OW; distanciaVertical++)
        {
            s16 x = xJugador + distanciaHorizontal;
            s16 y = yJugador + distanciaVertical;

            if (!EsTileDeHierba(x, y))
                continue;

            if (EstaDemasiadoCercaDeJugador(x, y))
                continue;

            IntentaCrearPokemonEnPosicion(x, y);
        }
    }

    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
    {
        struct PokemonSalvajeOw *pokemonSalvaje = &sPokemonSalvajesOw[i];
        if (pokemonSalvaje->estado != ESTADO_POKEMON_SALVAJE_ACTIVO)
            continue;

        MuevePokemonOw(pokemonSalvaje);

        if (EsAdyacenteAJugador(pokemonSalvaje->x, pokemonSalvaje->y))
        {
            EmpiezaBatallaPokemonSalvajeOw(pokemonSalvaje);
            return;
        }
    }
}

void IniciarPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_POKEMON_SALVAJES_OW; i++)
        sPokemonSalvajesOw[i].estado = ESTADO_POKEMON_SALVAJE_INACTIVO;
}

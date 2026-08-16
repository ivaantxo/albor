#include "global.h"
#include "pokemon_salvajes_ow.h"
#include "battle_setup.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "script.h"
#include "wild_encounter.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/metatile_behaviors.h"
#include "constants/wild_encounter.h"

// Cuantos pueden convivir en el mapa a la vez.
#define MAXIMO_SALVAJES_OW 3

// Todos los plazos se cuentan en pasos del jugador, no en fotogramas.
#define PASOS_ENTRE_APARICIONES  2
#define PASOS_DE_VIDA            8
#define PASOS_TRAS_DESAPARICION  2

// A que distancia del jugador se busca sitio para uno nuevo, y a que distancia
// minima: uno que naciera en una casilla contigua provocaria un combate al paso
// siguiente, que es justo lo que este sistema viene a evitar.
#define RADIO_APARICION            2
#define DISTANCIA_MINIMA_APARICION 2

// Ids locales reservados. El 254 y el 255 ya son el follower y el jugador.
#define LOCALID_SALVAJE_PRIMERO 251

struct SalvajeOw
{
    bool8 activo;
    u8 objectEventId;
    u8 terreno;
    u8 pasosDeVida;   // cuando llega a cero, desaparece
    u16 especie;
    u8 nivel;
    u32 personalidad;
};

static EWRAM_DATA struct SalvajeOw sSalvajes[MAXIMO_SALVAJES_OW] = {0};
static EWRAM_DATA u8 sPasosHastaProximaAparicion = 0;
// Se levanta al arrancar un combate y no se baja hasta volver al mapa. Sin ella,
// la comprobacion por fotograma volveria a dispararse durante la transicion.
static EWRAM_DATA bool8 sCombateArrancado = FALSE;

// Solo se puede aparecer y andar sobre estos comportamientos de metatile. Es una
// tabla y no un if encadenado para que anadir un terreno sea una linea.
static const u8 sComportamientoDeTerreno[TERRENOS_SALVAJES] =
{
    [TERRENO_HIERBA_ALTA] = MB_TALL_GRASS,
    [TERRENO_CUEVA]       = MB_CAVE,
    [TERRENO_OCEANO]      = MB_DEEP_WATER,
};

// De momento solo se generan en hierba alta; los otros dos terrenos ya tienen su
// comportamiento asociado y solo falta decidir cuando se usan.
static const u8 sTerrenosQueAparecen[] =
{
    TERRENO_HIERBA_ALTA,
};

static const s8 sDeltaX[] = { [DIR_SOUTH] = 0, [DIR_NORTH] =  0, [DIR_WEST] = -1, [DIR_EAST] = 1 };
static const s8 sDeltaY[] = { [DIR_SOUTH] = 1, [DIR_NORTH] = -1, [DIR_WEST] =  0, [DIR_EAST] = 0 };

static bool32 EsTerrenoDe(u32 terreno, s16 x, s16 y)
{
    return MapGridGetMetatileBehaviorAt(x, y) == sComportamientoDeTerreno[terreno];
}

static bool32 CasillaLibre(s16 x, s16 y, u8 elevacion)
{
    return GetObjectEventIdByPosition(x, y, elevacion) == OBJECT_EVENTS_COUNT;
}

// Una casilla sirve si es del terreno del Pokemon y no la ocupa nadie.
static bool32 CasillaTransitable(u32 terreno, s16 x, s16 y, u8 elevacion)
{
    return EsTerrenoDe(terreno, x, y) && CasillaLibre(x, y, elevacion);
}

static struct SalvajeOw *RanuraLibre(void)
{
    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        if (!sSalvajes[i].activo)
            return &sSalvajes[i];
    }
    return NULL;
}

static u8 LocalIdDeRanura(const struct SalvajeOw *salvaje)
{
    return LOCALID_SALVAJE_PRIMERO + (salvaje - sSalvajes);
}

// El motor borra objetos por su cuenta: al salir de la vista del jugador y al
// rehacerse el mapa despues de un combate. El hueco que dejan lo reutiliza otro,
// asi que el indice no identifica a nadie. El localId si es unico y estable, y
// comprobarlo es lo que evita mover a un NPC o pelearse con una senal.
static struct ObjectEvent *ObjetoDeSalvaje(struct SalvajeOw *salvaje)
{
    struct ObjectEvent *objEvent;

    if (!salvaje->activo || salvaje->objectEventId >= OBJECT_EVENTS_COUNT)
        return NULL;

    objEvent = &gObjectEvents[salvaje->objectEventId];
    if (!objEvent->active || objEvent->localId != LocalIdDeRanura(salvaje))
    {
        // Ya no esta: la ranura queda libre para uno nuevo.
        salvaje->activo = FALSE;
        salvaje->objectEventId = OBJECT_EVENTS_COUNT;
        return NULL;
    }

    return objEvent;
}

static struct SalvajeOw *SalvajeDeObjeto(u32 objectEventId)
{
    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        if (sSalvajes[i].objectEventId == objectEventId && ObjetoDeSalvaje(&sSalvajes[i]) != NULL)
            return &sSalvajes[i];
    }
    return NULL;
}

bool32 EsObjetoPokemonSalvaje(u32 objectEventId)
{
    return SalvajeDeObjeto(objectEventId) != NULL;
}

static void QuitaSalvaje(struct SalvajeOw *salvaje)
{
    struct ObjectEvent *objEvent = ObjetoDeSalvaje(salvaje);

    if (objEvent != NULL)
        RemoveObjectEvent(objEvent);

    salvaje->activo = FALSE;
    salvaje->objectEventId = OBJECT_EVENTS_COUNT;

    // Un hueco recien liberado no se reutiliza de inmediato.
    if (sPasosHastaProximaAparicion < PASOS_TRAS_DESAPARICION)
        sPasosHastaProximaAparicion = PASOS_TRAS_DESAPARICION;
}

// Se llama al cargar un mapa y al volver de un combate. En el primer caso los
// objetos ya no estan y solo hay que olvidarlos; en el segundo siguen ahi y hay
// que quitarlos, porque al rehacerse el mapa pierden su personalidad y volverian
// con otros colores. Se prefiere que desaparezcan a que cambien de aspecto.
void ReiniciaPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        struct ObjectEvent *objEvent = ObjetoDeSalvaje(&sSalvajes[i]);

        if (objEvent != NULL)
            RemoveObjectEvent(objEvent);

        sSalvajes[i].activo = FALSE;
        sSalvajes[i].objectEventId = OBJECT_EVENTS_COUNT;
    }
    sPasosHastaProximaAparicion = PASOS_ENTRE_APARICIONES;
    sCombateArrancado = FALSE;
}

// Busca una casilla del terreno pedido a RADIO_APARICION o menos del jugador.
// Recorre el cuadrado entero y se queda con una al azar entre las validas, para
// no sesgar la aparicion hacia una esquina.
static bool32 BuscaSitioDeAparicion(u32 terreno, s16 *destinoX, s16 *destinoY)
{
    s16 jugadorX, jugadorY;
    u8 elevacion = gObjectEvents[gPlayerAvatar.objectEventId].currentElevation;
    u32 encontradas = 0;

    PlayerGetDestCoords(&jugadorX, &jugadorY);

    for (s16 dy = -RADIO_APARICION; dy <= RADIO_APARICION; dy++)
    {
        for (s16 dx = -RADIO_APARICION; dx <= RADIO_APARICION; dx++)
        {
            s16 x = jugadorX + dx;
            s16 y = jugadorY + dy;

            u32 distancia = max(abs(dx), abs(dy));

            if (distancia < DISTANCIA_MINIMA_APARICION)
                continue;
            if (!CasillaTransitable(terreno, x, y, elevacion))
                continue;

            // Reservoir sampling: cada casilla valida tiene la misma opcion sin
            // necesidad de guardar la lista entera.
            encontradas++;
            if (Random() % encontradas == 0)
                *destinoX = x, *destinoY = y;
        }
    }

    return encontradas != 0;
}

// Personalidad propia, con sus tiradas de variocolor. Se decide aqui y no en el
// combate para que el sprite del mapa ya ensene el tono definitivo.
static u32 GeneraPersonalidadSalvaje(void)
{
    return AplicaTiradasShinyExtra(Random32());
}

static bool32 EligeEspecieYNivel(u32 terreno, u16 *especie, u8 *nivel)
{
    u16 headerId = ObtenIdCabeceraSalvajesMapaActual();
    const struct WildPokemonInfo *info;
    u32 indice, area;

    if (headerId == HEADER_NONE)
        return FALSE;

    // Los tres terrenos salen de las tablas que ya existen por mapa. Cada tabla
    // tiene su numero de entradas, asi que el selector de indice tiene que ser el
    // suyo: el de tierra llega a 11 y la de agua solo tiene cinco.
    if (terreno == TERRENO_OCEANO)
    {
        info = gWildMonHeaders[headerId].waterMonsInfo;
        area = WILD_AREA_WATER;
    }
    else
    {
        info = gWildMonHeaders[headerId].landMonsInfo;
        area = WILD_AREA_LAND;
    }
    if (info == NULL)
        return FALSE;

    indice = (area == WILD_AREA_WATER) ? ChooseWildMonIndex_WaterRock() : ChooseWildMonIndex_Land();
    *especie = info->wildPokemon[indice].species;
    *nivel = ChooseWildMonLevel(info->wildPokemon, indice, area);
    return TRUE;
}

static void IntentaCrearSalvaje(void)
{
    struct SalvajeOw *salvaje = RanuraLibre();
    u32 terreno = sTerrenosQueAparecen[Random() % ARRAY_COUNT(sTerrenosQueAparecen)];
    u16 especie;
    u8 nivel, objectEventId;
    u32 personalidad;
    u16 graphicsId;
    s16 x, y;

    if (salvaje == NULL)
        return;
    // Cada uno se lleva una paleta entera para tener su tono propio, asi que el
    // numero que puede haber a la vez lo limita el de paletas libres, no solo
    // MAXIMO_SALVAJES_OW. Sin hueco no aparece: antes que quitarle los colores a
    // otro sprite, es preferible que no salga.
    if (PaletasSpriteLibres() == 0)
        return;
    if (!EligeEspecieYNivel(terreno, &especie, &nivel))
        return;
    if (!BuscaSitioDeAparicion(terreno, &x, &y))
        return;

    personalidad = GeneraPersonalidadSalvaje();

    graphicsId = especie + OBJ_EVENT_MON;
    if (VALOR_SHINY(personalidad) < SHINY_ODDS)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (GetGenderFromSpeciesAndPersonality(especie, personalidad) == MON_FEMALE)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    objectEventId = SpawnSpecialObjectEventParameterized(graphicsId, MOVEMENT_TYPE_NONE,
                        LOCALID_SALVAJE_PRIMERO + (salvaje - sSalvajes),
                        x, y, gObjectEvents[gPlayerAvatar.objectEventId].currentElevation);

    if (objectEventId >= OBJECT_EVENTS_COUNT)
        return; // No quedaban objetos de mapa libres.

    FijaPersonalidadObjetoEvento(objectEventId, personalidad);

    salvaje->activo = TRUE;
    salvaje->objectEventId = objectEventId;
    salvaje->terreno = terreno;
    salvaje->pasosDeVida = PASOS_DE_VIDA;
    salvaje->especie = especie;
    salvaje->nivel = nivel;
    salvaje->personalidad = personalidad;
}

// Un movimiento por paso del jugador: o mira hacia un lado, o da un paso hacia
// el. Si el paso no se puede dar, se queda en mirar, que tambien es uno de los
// ocho movimientos posibles y asi no se pierde el turno.
static void MueveSalvaje(struct SalvajeOw *salvaje, struct ObjectEvent *objEvent)
{
    u32 direccion = DIR_SOUTH + (Random() % 4);
    bool32 quiereAndar = (Random() % 2) != 0;

    if (!ObjectEventIsHeldMovementActive(objEvent) || ObjectEventClearHeldMovementIfFinished(objEvent))
    {
        if (quiereAndar)
        {
            s16 x = objEvent->currentCoords.x + sDeltaX[direccion];
            s16 y = objEvent->currentCoords.y + sDeltaY[direccion];

            if (CasillaTransitable(salvaje->terreno, x, y, objEvent->currentElevation))
            {
                ObjectEventSetHeldMovement(objEvent, MOVEMENT_ACTION_WALK_NORMAL_DOWN + (direccion - DIR_SOUTH));
                return;
            }
        }
        ObjectEventSetHeldMovement(objEvent, MOVEMENT_ACTION_FACE_DOWN + (direccion - DIR_SOUTH));
    }
}

void ActualizaPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        struct SalvajeOw *salvaje = &sSalvajes[i];

        struct ObjectEvent *objEvent = ObjetoDeSalvaje(salvaje);

        if (objEvent == NULL)
            continue;

        if (salvaje->pasosDeVida == 0)
        {
            QuitaSalvaje(salvaje);
            continue;
        }

        salvaje->pasosDeVida--;
        MueveSalvaje(salvaje, objEvent);
    }

    if (sPasosHastaProximaAparicion != 0)
    {
        sPasosHastaProximaAparicion--;
    }
    else
    {
        IntentaCrearSalvaje();
        sPasosHastaProximaAparicion = PASOS_ENTRE_APARICIONES;
    }
}

// Devuelve el que este en una casilla ortogonalmente contigua a la del jugador.
// Compara coordenadas contra nuestras propias ranuras en vez de preguntarle al
// mapa quien hay en tal casilla: aquella consulta exige que coincida la altura, y
// bastaba con que el Pokemon estuviera en otra para que el combate no empezara.
// Si hay varios pegados al jugador a la vez, pelea uno al azar y no siempre el
// de la primera ranura, que es lo que salia al recorrerlas en orden.
static struct SalvajeOw *SalvajeContiguoAlJugador(void)
{
    struct SalvajeOw *elegido = NULL;
    s16 jugadorX, jugadorY;
    u32 candidatos = 0;

    PlayerGetDestCoords(&jugadorX, &jugadorY);

    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        struct SalvajeOw *salvaje = &sSalvajes[i];
        struct ObjectEvent *objEvent = ObjetoDeSalvaje(salvaje);

        if (objEvent == NULL)
            continue;

        if (abs(objEvent->currentCoords.x - jugadorX) + abs(objEvent->currentCoords.y - jugadorY) != 1)
            continue;

        candidatos++;
        if (Random() % candidatos == 0)
            elegido = salvaje;
    }

    return elegido;
}

static bool32 EmpiezaCombateCon(struct SalvajeOw *salvaje)
{
    struct ObjectEvent *objEvent = ObjetoDeSalvaje(salvaje);
    s16 jugadorX, jugadorY;

    // Que se miren a la cara antes de empezar.
    PlayerGetDestCoords(&jugadorX, &jugadorY);
    ObjectEventTurn(objEvent, GetDirectionToFace(objEvent->currentCoords.x, objEvent->currentCoords.y, jugadorX, jugadorY));

    // La personalidad que se ha estado ensenando en el mapa es la que se lleva al
    // combate: el tono y el variocolor son los mismos.
    CreaPokemonSalvajeConPersonalidad(salvaje->especie, salvaje->nivel, salvaje->personalidad);

    // El objeto NO se quita aqui: desaparecer durante la transicion queda raro, y
    // mas al lado de otro que sigue ahi. Se lo lleva por delante el reinicio al
    // volver al mapa, que es cuando ya no se ve.
    sCombateArrancado = TRUE;
    BattleSetup_StartWildBattle();
    return TRUE;
}

// El combate salta solo unicamente si el jugador tiene el pie en el mismo terreno
// que el Pokemon. Pasar por un camino rozando la hierba no basta: hay que estar
// dentro. Se compara contra el terreno de ese Pokemon y no contra la hierba alta a
// secas, para que valga igual cuando se activen cuevas y oceano.
bool32 ComprobaContactoPokemonSalvaje(void)
{
    struct SalvajeOw *salvaje;
    s16 jugadorX, jugadorY;

    if (sCombateArrancado || ArePlayerFieldControlsLocked())
        return FALSE;

    salvaje = SalvajeContiguoAlJugador();
    if (salvaje == NULL)
        return FALSE;

    PlayerGetDestCoords(&jugadorX, &jugadorY);
    if (!EsTerrenoDe(salvaje->terreno, jugadorX, jugadorY))
        return FALSE;

    return EmpiezaCombateCon(salvaje);
}

// Pulsando A el jugador lo ha buscado a proposito, asi que da igual donde pise:
// basta con estar en una casilla contigua.
bool32 IntentaCombatePokemonSalvajePulsandoA(void)
{
    struct SalvajeOw *salvaje;

    if (sCombateArrancado || ArePlayerFieldControlsLocked())
        return FALSE;

    salvaje = SalvajeContiguoAlJugador();
    if (salvaje == NULL)
        return FALSE;

    return EmpiezaCombateCon(salvaje);
}

#include "global.h"
#include "pokemon_salvajes_ow.h"
#include "battle_setup.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "m4a.h"
#include "pokemon.h"
#include "random.h"
#include "depuracion_mgba.h"
#include "sound.h"
#include "constants/songs.h"
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
//
// La separacion entre apariciones no es solo ritmo de juego: cada una suena con
// su grito, y demasiado juntas se pisaban unas a otras.
#define PASOS_ENTRE_APARICIONES  6
#define PASOS_DE_VIDA           24
#define PASOS_TRAS_DESAPARICION  6

// A que distancia del jugador se busca sitio para uno nuevo, y a que distancia
// minima: uno que naciera en una casilla contigua provocaria un combate al paso
// siguiente, que es justo lo que este sistema viene a evitar.
#define RADIO_APARICION            2
#define DISTANCIA_MINIMA_APARICION 2

// Ids locales reservados. El 254 y el 255 ya son el follower y el jugador.
#define LOCALID_SALVAJE_PRIMERO 251

#define PANEO_IZQUIERDA         (-64)
#define PANEO_CENTRO            0
#define PANEO_DERECHA           64

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

// El jugador no ocupa una casilla, sino hasta tres: la que pisa, la que acaba de
// dejar y la que va a pisar. La tercera es la que faltaba.
//
// Mirando solo las dos primeras seguia colandose el cruce, porque hay un hueco de
// un fotograma entre que se encarga un paso y las coordenadas se mueven de sitio.
// En ese hueco la casilla de destino no la reclama nadie, y el salvaje se metia
// en la que el jugador estaba dejando mientras el jugador entraba en la suya: los
// dos se atravesaban sin tocarse.
//
// Reservando tambien la casilla de delante, el salvaje no puede pisar el origen
// del jugador y el cruce es imposible por construccion, sin depender de en que
// orden se muevan los dos.
static bool32 CasillaDelJugador(s16 x, s16 y)
{
    const struct ObjectEvent *jugador = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 frenteX = jugador->currentCoords.x + sDeltaX[jugador->facingDirection];
    s16 frenteY = jugador->currentCoords.y + sDeltaY[jugador->facingDirection];

    return (jugador->currentCoords.x == x && jugador->currentCoords.y == y)
        || (jugador->previousCoords.x == x && jugador->previousCoords.y == y)
        || (frenteX == x && frenteY == y);
}

// No basta con mirar donde esta cada objeto AHORA, hay que mirar tambien de donde
// viene: mientras se da un paso se ocupan las dos casillas, la de salida y la de
// llegada, y asi lo comprueba la colision normal del juego.
//
// GetObjectEventIdByPosition solo consulta currentCoords, y por ese hueco se
// colaba el cruce: el jugador arrancaba su paso -su currentCoords pasaba a ser la
// casilla del salvaje- y la casilla que estaba dejando parecia libre, asi que el
// salvaje se metia en ella. Los dos se atravesaban.
static bool32 CasillaLibre(s16 x, s16 y, u8 elevacion)
{
    if (CasillaDelJugador(x, y))
        return FALSE;

    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        const struct ObjectEvent *objeto = &gObjectEvents[i];

        if (!objeto->active)
            continue;

        // Misma regla de alturas que ObjectEventDoesElevationMatch: la altura 0 es
        // comodin y se lleva bien con cualquiera.
        if (objeto->currentElevation != 0 && elevacion != 0 && objeto->currentElevation != elevacion)
            continue;

        if ((objeto->currentCoords.x == x && objeto->currentCoords.y == y)
         || (objeto->previousCoords.x == x && objeto->previousCoords.y == y))
            return FALSE;
    }

    return TRUE;
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
bool32 EsLocalIdDePokemonSalvaje(u32 localId)
{
    return localId >= LOCALID_SALVAJE_PRIMERO
        && localId < LOCALID_SALVAJE_PRIMERO + MAXIMO_SALVAJES_OW;
}

void ReiniciaPokemonSalvajesOw(void)
{
    for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
    {
        sSalvajes[i].activo = FALSE;
        sSalvajes[i].objectEventId = OBJECT_EVENTS_COUNT;
    }

    // Se barren TODOS los objetos del mapa que lleven un localId de salvaje, no
    // solo los que este modulo tenga fichados.
    //
    // Los objetos del mapa se guardan en la partida (ver SaveObjectEvents), asi
    // que una partida guardada con salvajes a la vista los devolvia al cargar. Pero
    // sSalvajes vive en EWRAM y arranca vacio, asi que volvian huerfanos: nadie los
    // movia y nadie miraba si tocabas con ellos. Estaban ahi, muertos.
    //
    // Esto los limpia vengan de donde vengan, incluidas las partidas guardadas
    // antes de arreglarlo.
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && EsLocalIdDePokemonSalvaje(gObjectEvents[i].localId))
            RemoveObjectEvent(&gObjectEvents[i]);
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

// Paneo segun a que lado del jugador ha salido. El registro va de 0 (todo a la
// izquierda) a 255 (todo a la derecha), con 128 en el centro.
static s8 PaneoDesdeJugador(s16 x)
{
    s16 jugadorX, jugadorY;

    PlayerGetDestCoords(&jugadorX, &jugadorY);

    if (x < jugadorX)
        return PANEO_IZQUIERDA;
    if (x > jugadorX)
        return PANEO_DERECHA;

    return PANEO_CENTRO;
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
    bool32 esVariocolor;
    s16 x, y;

    if (salvaje == NULL)
    {
        LOG("SALVAJE sin ranura libre", 0, 0);
        return;
    }
    // Cada uno se lleva una paleta entera para tener su tono propio, asi que el
    // numero que puede haber a la vez lo limita el de paletas libres, no solo
    // MAXIMO_SALVAJES_OW. Sin hueco no aparece: antes que quitarle los colores a
    // otro sprite, es preferible que no salga.
    if (PaletasSpriteLibres() == 0)
    {
        LOG("SALVAJE sin paleta libre", 0, 0);
        return;
    }
    if (!EligeEspecieYNivel(terreno, &especie, &nivel))
    {
        LOG("SALVAJE sin tabla de especies", 0, 0);
        return;
    }
    if (!BuscaSitioDeAparicion(terreno, &x, &y))
    {
        LOG("SALVAJE sin sitio en el terreno", 0, 0);
        return;
    }

    personalidad = GeneraPersonalidadSalvaje();
    esVariocolor = VALOR_SHINY(personalidad) < SHINY_ODDS;

    graphicsId = especie + OBJ_EVENT_MON;
    if (esVariocolor)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (GetGenderFromSpeciesAndPersonality(especie, personalidad) == MON_FEMALE)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    objectEventId = SpawnSpecialObjectEventParameterized(graphicsId, MOVEMENT_TYPE_NONE,
                        LOCALID_SALVAJE_PRIMERO + (salvaje - sSalvajes),
                        x, y, gObjectEvents[gPlayerAvatar.objectEventId].currentElevation);

    if (objectEventId >= OBJECT_EVENTS_COUNT)
    {
        LOG("SALVAJE sin objeto de mapa libre", 0, 0);
        return;
    }

    FijaPersonalidadObjetoEvento(objectEventId, personalidad);
    // La paleta se tino al crear el sprite, cuando la personalidad aun no estaba
    // puesta. Hay que rehacerla para que el tono del mapa sea el del combate.
    RecargaPaletaObjetoPokemon(objectEventId);

    salvaje->activo = TRUE;
    salvaje->objectEventId = objectEventId;
    salvaje->terreno = terreno;
    salvaje->pasosDeVida = PASOS_DE_VIDA;
    salvaje->especie = especie;
    salvaje->nivel = nivel;
    salvaje->personalidad = personalidad;

    {
        u32 vivos = 0;
        for (u32 i = 0; i < MAXIMO_SALVAJES_OW; i++)
            if (sSalvajes[i].activo)
                vivos++;
        LOG("SALVAJE creado. vivos / paletas libres", vivos, PaletasSpriteLibres());
    }

    // Se anuncia con su grito al aparecer, para que se note que hay algo ahi
    // aunque quede fuera de pantalla. El paneo sale de si ha salido a izquierda o
    // derecha del jugador, y va en prioridad ambiental para que no pise a nada.
    PlayCry_NormalNoDucking(especie, PaneoDesdeJugador(x), VOLUMEN_BAJO, CRY_PRIORITY_AMBIENT);

    if (esVariocolor)
        PlaySE(SE_SHINY);
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
                const struct ObjectEvent *jugador = &gObjectEvents[gPlayerAvatar.objectEventId];

                LOG("salvaje anda: desde x,y", objEvent->currentCoords.x, objEvent->currentCoords.y);
                LOG("salvaje anda: hacia x,y", x, y);
                LOG("jugador ahora x,y", jugador->currentCoords.x, jugador->currentCoords.y);
                LOG("jugador antes x,y", jugador->previousCoords.x, jugador->previousCoords.y);
                LOG("jugador mira / se mueve", jugador->facingDirection, jugador->movementDirection);

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

    // Que se miren a la cara los dos, venga el combate de donde venga: si empezo
    // porque solo uno miraba al otro, el otro se gira.
    PlayerGetDestCoords(&jugadorX, &jugadorY);
    ObjectEventTurn(objEvent, GetDirectionToFace(objEvent->currentCoords.x, objEvent->currentCoords.y, jugadorX, jugadorY));
    PlayerTurnInPlace(GetDirectionToFace(jugadorX, jugadorY, objEvent->currentCoords.x, objEvent->currentCoords.y));

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

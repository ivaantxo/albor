#include "global.h"
#include "bike.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "sound.h"
#include "constants/map_types.h"
#include "constants/songs.h"

// La bici.
//
// Hay UNA, sin acro ni mach, y tiene dos velocidades planas: x2 pedaleando y x4 con
// B. No acelera sola. Antes subia de escalon segun los pasos seguidos en recto, y eso
// hacia que cada curva costara la velocidad ganada; asi el ritmo lo decide el jugador
// con el boton y no el tiempo que lleve sin girar.

static void BiciTransition_FaceDirection(u8);
static void BiciTransition_TurnDirection(u8);
static void BiciTransition_TrySpeedUp(u8);
static void BiciTransition_TrySlowDown(u8);
static u8 GetBiciTransition(u8 *);
static u8 GetBikeCollision(u8);
static u8 GetBikeCollisionAt(struct ObjectEvent *, s16, s16, u8, u8);
static bool8 IsRunningDisallowedByMetatile(u8);

// Que hacer en este fotograma: encarar, girar, arrancar o seguir. Encarar no anima y
// girar si, y girar ademas mira si hay pared para hacer el ruido del topetazo.
static void (*const sBiciTransitions[])(u8) =
{
    [BICI_TRANS_FACE_DIRECTION] = BiciTransition_FaceDirection,
    [BICI_TRANS_TURN_DIRECTION] = BiciTransition_TurnDirection,
    [BICI_TRANS_KEEP_MOVING]    = BiciTransition_TrySpeedUp,
    [BICI_TRANS_START_MOVING]   = BiciTransition_TrySlowDown,
};

#define BICI_VELOCIDAD_BASE   0     // PlayerWalkFast,   x2
#define BICI_VELOCIDAD_TURBO  1     // PlayerWalkFaster, x4

static void (*const sBiciSpeedCallbacks[])(u8) =
{
    [BICI_VELOCIDAD_BASE]  = PlayerWalkFast,
    [BICI_VELOCIDAD_TURBO] = PlayerWalkFaster,
};

// Cual toca ahora mismo.
static u32 VelocidadBici(void)
{
    return JOY_HELD(B_BUTTON) ? BICI_VELOCIDAD_TURBO : BICI_VELOCIDAD_BASE;
}

void MovePlayerOnBike(u8 direction)
{
    sBiciTransitions[GetBiciTransition(&direction)](direction);
}

// dirTraveling vale cero cuando el jugador esta parado.
static u8 GetBiciTransition(u8 *dirTraveling)
{
    // Si la direccion se actualizo antes de esta funcion, aqui se recoge.
    u8 direction = GetPlayerMovementDirection();

    // Enderezar la direccion en las escaleras de lado.
    switch (direction)
    {
    case DIR_SOUTHWEST:
    case DIR_NORTHWEST:
        direction = DIR_WEST;
        break;
    case DIR_SOUTHEAST:
    case DIR_NORTHEAST:
        direction = DIR_EAST;
        break;
    }

    if (*dirTraveling == 0)
    {
        *dirTraveling = direction; // O se encara, o se arranca: en los dos casos vale.
        if (gPlayerAvatar.bikeSpeed == PLAYER_SPEED_STANDING)
        {
            gPlayerAvatar.runningState = NOT_MOVING;
            return BICI_TRANS_FACE_DIRECTION;
        }
        gPlayerAvatar.runningState = MOVING;
        return BICI_TRANS_START_MOVING;
    }

    // Ha cambiado la direccion respecto a la ultima, y ademas no se estaba ya en mitad
    // de un paso: eso ultimo es lo que mira el else.
    if (*dirTraveling != direction && gPlayerAvatar.runningState != MOVING)
    {
        if (gPlayerAvatar.bikeSpeed != PLAYER_SPEED_STANDING)
        {
            *dirTraveling = direction;
            gPlayerAvatar.runningState = MOVING;
            return BICI_TRANS_START_MOVING;
        }
        // No se arranco pero la direccion era otra: entonces se gira sobre el sitio.
        gPlayerAvatar.runningState = TURN_DIRECTION;
        return BICI_TRANS_TURN_DIRECTION;
    }
    else
    {
        gPlayerAvatar.runningState = MOVING;
        return BICI_TRANS_KEEP_MOVING;
    }
}

static void BiciTransition_FaceDirection(u8 direction)
{
    PlayerFaceDirection(direction);
    BikeClearState();
}

static void BiciTransition_TurnDirection(u8 direction)
{
    PlayerTurnInPlace(direction);
    BikeClearState();
}

// Que hacer al chocar. Las dos transiciones de movimiento lo tenian copiado.
//
// La diferencia esta en si se venia rodando o se estaba empujando parado contra algo:
// empujando se sigue pedaleando en el sitio, que es lo que uno espera al insistir
// contra una pared, y viniendo con carrerilla hay topetazo y parada.
static void ChocaEnBici(u8 direction, u8 collision)
{
    // Antes de BikeClearState, que es justo quien lo borra.
    bool32 veniaRodando = gPlayerAvatar.bikeSpeed != PLAYER_SPEED_STANDING;

    BikeClearState();

    if (collision == COLLISION_OBJECT_EVENT && IsPlayerCollidingWithFarawayIslandMew(direction))
        PlayerOnBikeCollideWithFarawayIslandMew(direction);
    else if (collision < COLLISION_STOP_SURFING || collision > COLLISION_ROTATING_GATE)
    {
        if (veniaRodando)
            GolpeEnBici(direction);
        else
            PlayerOnBikeCollide(direction);
    }
}

static void BiciTransition_TrySpeedUp(u8 direction)
{
    u8 collision = GetBikeCollision(direction);

    if (collision > 0)
    {
        // Hay algo solido delante, pero si es un bordillo se salta.
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
        }
        else
        {
            ChocaEnBici(direction, collision);
        }
    }
    else
    {
        sBiciSpeedCallbacks[VelocidadBici()](direction);

        // Que el motor la vea SIEMPRE en marcha mientras avanza. Con esto a cero se
        // toman los caminos de encarar y girar, que la paran: es justo lo que hacia
        // perder la velocidad en cada curva.
        gPlayerAvatar.bikeSpeed = PLAYER_SPEED_FAST;
    }
}

static void BiciTransition_TrySlowDown(u8 direction)
{
    u8 collision = GetBikeCollision(direction);

    if (collision > 0)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
        }
        else
        {
            ChocaEnBici(direction, collision);
        }
    }
    else
    {
        sBiciSpeedCallbacks[VelocidadBici()](direction);
    }
}

static u8 GetBikeCollision(u8 direction)
{
    u8 metatileBehavior;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    return GetBikeCollisionAt(playerObjEvent, x, y, direction, metatileBehavior);
}

static u8 GetBikeCollisionAt(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 collision = CheckForObjectEventCollision(objectEvent, x, y, direction, metatileBehavior);

    if (collision > COLLISION_OBJECT_EVENT)
        return collision;

    if (collision == COLLISION_NONE && IsRunningDisallowedByMetatile(metatileBehavior))
        collision = COLLISION_IMPASSABLE;

    return collision;
}

static bool8 IsRunningDisallowedByMetatile(u8 tile)
{
    if (MetatileBehavior_IsRunningDisallowed(tile))
        return TRUE;
    if (MetatileBehavior_IsFortreeBridge(tile) && (PlayerGetElevation() & 1) == 0)
        return TRUE;
    return FALSE;
}

bool8 IsBikingDisallowedByPlayer(void)
{
    s16 x, y;
    u8 tileBehavior;

    if (!(gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER)))
    {
        PlayerGetDestCoords(&x, &y);
        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        if (!IsRunningDisallowedByMetatile(tileBehavior))
            return FALSE;
    }
    return TRUE;
}

void GetOnOffBike(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_BICI)
    {
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
        Overworld_ClearSavedMusic();
        Overworld_PlaySpecialMapMusic();
    }
    else
    {
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_BICI);
        PlaySE(SE_BIKE_BELL);   // encima de la musica, que no la corta
        Overworld_SetSavedMusic(MUS_CYCLING);
        Overworld_ChangeMusicTo(MUS_CYCLING);
    }
}

// La bici, parada. bikeSpeed no es la velocidad a la que se va -eso lo decide el boton
// B en cada paso-, sino si esta rodando o no.
void BikeClearState(void)
{
    gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
}

s16 GetPlayerSpeed(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_BICI)
        return VelocidadBici() == BICI_VELOCIDAD_TURBO ? PLAYER_SPEED_FASTEST : PLAYER_SPEED_FAST;
    else if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_DASH))
        return PLAYER_SPEED_FAST;
    else
        return PLAYER_SPEED_NORMAL;
}

bool32 IsRunningDisallowed(u8 metatile)
{
    // Solo manda el suelo que se pisa. La cabecera del mapa ya no dice nada: correr
    // se puede siempre, dentro y fuera, y el interruptor que lo hacia depender de la
    // generacion se ha ido con ella.
    if (IsRunningDisallowedByMetatile(metatile) == TRUE)
        return TRUE;

    return FALSE;
}

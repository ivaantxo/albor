#ifndef GUARD_BIKE_H
#define GUARD_BIKE_H

// Lo rapido que va el jugador. Se pregunta desde fuera -puertas, verjas giratorias,
// suelo agrietado- para saber si se va lanzado.
enum
{
    PLAYER_SPEED_STANDING,
    PLAYER_SPEED_NORMAL,
    PLAYER_SPEED_FAST,
    PLAYER_SPEED_FASTER,
    PLAYER_SPEED_FASTEST,
};

// Que le toca hacer a la bici en este fotograma.
enum
{
    BICI_TRANS_FACE_DIRECTION,
    BICI_TRANS_TURN_DIRECTION,
    BICI_TRANS_KEEP_MOVING,
    BICI_TRANS_START_MOVING
};

void MovePlayerOnBike(u8 direction);
bool8 IsBikingDisallowedByPlayer(void);
void GetOnOffBike(void);
void BikeClearState(void);
s16 GetPlayerSpeed(void);
bool32 IsRunningDisallowed(u8 metatile);

#endif // GUARD_BIKE_H

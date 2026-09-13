#ifndef GUARD_POKEMON_SPRITE_VISUALIZER_H
#define GUARD_POKEMON_SPRITE_VISUALIZER_H

#include "constants/global.h"
#include "constants/pokemon_sprite_visualizer.h"
#include "constants/pokemon.h"
#include "sprite.h"

//Structs
struct PokemonSpriteVisualizerModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit;
    u8 maxDigits;
    u8 charDigits[MODIFY_DIGITS_MAX];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct PokemonSpriteVisualizerOptionArrows
{
    u8 arrowSpriteId[1];
    u8 currentDigit;
};

struct PokemonSpriteVisualizerYPosModifiyArrows
{
    u8 arrowSpriteId[1];
    u8 currentDigit;
};

struct PokemonSpriteConstValues
{
    u8 backPicCoords;
    u8 frontPicCoords;
    u8 frontElevation;
};

struct PokemonSpriteOffsets
{
    s8 offset_back_picCoords;
    s8 offset_front_elevation;
};

// El ritmo de una animacion continua mientras se prueba en el visor.
//
// La tabla de la especie esta en la ROM y no se toca: lo que se edita es una copia en
// memoria con todas las poses puestas a la misma duracion, que es la constante que
// luego se escribe a mano en animaciones_pokemon.h. Mientras la duracion que se prueba
// sea la que ya trae la especie se usa su tabla original, para no aplanar los tiempos
// por tramo de las que los llevan escritos uno a uno.
struct RitmoDeAnimacion
{
    const union AnimCmd *const *tablaEspecie;
    u8 indice;                  // cual de las animaciones de la tabla es la continua
    u16 duracionEspecie;
    u16 duracionNueva;
    const union AnimCmd *tabla[ANIMACIONES_POR_PIC];
    union AnimCmd comandos[MAX_COMANDOS_ANIM];
};

struct PokemonShadowSettings
{
    s8 definedX;
    s8 definedY;

    s8 overrideX;
    s8 overrideY;
};

struct PokemonSpriteVisualizer
{
    u16 currentmonId;
    u8 currentmonWindowId;
    u8 InstructionsWindowId;
    u8 frontspriteId;
    u8 backspriteId;
    u8 followerspriteId;
    bool8 isShiny;
    bool8 isFemale;
    u8 frontShadowSpriteIdPrimary;
    struct PokemonShadowSettings shadowSettings;
    struct PokemonSpriteVisualizerModifyArrows modifyArrows;
    struct PokemonSpriteVisualizerOptionArrows optionArrows;
    struct PokemonSpriteVisualizerYPosModifiyArrows yPosModifyArrows;
    struct PokemonSpriteConstValues constSpriteValues;
    struct PokemonSpriteOffsets offsetsSpriteValues;
    struct RitmoDeAnimacion ritmoFrente;
    struct RitmoDeAnimacion ritmoEspalda;

    u8 animIdBack;
    u8 animIdFront;
    u8 battleBgType;
    u8 battleTerrain;
    u8 currentSubmenu;
    u8 submenuYpos[3];
};

void CB2_Pokemon_Sprite_Visualizer(void);


#endif // GUARD_POKEMON_SPRITE_VISUALIZER_H

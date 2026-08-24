#include "global.h"
#include "pic_combate.h"
#include "malloc.h"
#include "pokemon.h"
#include "data.h"
#include "constants/pokemon.h"
#include "battle.h"
#include "task.h"
#include "pokemon_animation.h"
#include "depuracion_mgba.h"

// Reparto de un pic de 80x80 en objetos legales de GBA. 80 = 64 + 16 en los dos
// ejes, asi que salen seis piezas y ni un tile desperdiciado:
//
//     +---------------+----+      A 64x64   D 32x16
//     |               | B  |      B 16x32   E 32x16
//     |       A       +----+      C 16x32   F 16x16
//     |               | C  |
//     +-------+-------+----+
//     |   D   |   E   | F  |
//     +-------+-------+----+
//
// Las coordenadas van referidas al centro del sprite, que es lo que espera
// AddSubspritesToOamBuffer.
// Reparto de un pic de 96x96 en objetos legales de GBA. 96 = 64 + 32 en los dos ejes,
// asi que salen cuatro piezas justas y ni un tile de sobra:
//
//     +---------------+-------+      A 64x64 -> 64 tiles
//     |               |       |      B 32x64 -> 32
//     |       A       |   B   |      C 64x32 -> 32
//     |               |       |      D 32x32 -> 16
//     +-------+-------+-------+      TOTAL     144
//     |       C       |   D   |
//     +-------+-------+-------+
//
// Las coordenadas van referidas al centro del sprite, que es lo que espera
// AddSubspritesToOamBuffer.
static const struct Subsprite sPiezasPicGrande[] =
{
    { .x = -48, .y = -48, .shape = ST_OAM_SQUARE,      .size = 3, .tileOffset =   0, .priority = 2 },
    { .x =  16, .y = -48, .shape = ST_OAM_V_RECTANGLE, .size = 3, .tileOffset =  64, .priority = 2 },
    { .x = -48, .y =  16, .shape = ST_OAM_H_RECTANGLE, .size = 3, .tileOffset =  96, .priority = 2 },
    { .x =  16, .y =  16, .shape = ST_OAM_SQUARE,      .size = 2, .tileOffset = 128, .priority = 2 },
};

static const struct SubspriteTable sTablaPicGrande[] =
{
    { ARRAY_COUNT(sPiezasPicGrande), sPiezasPicGrande },
};

// El mismo reparto visto desde la imagen de origen, que llega en tiles de 12 por fila.
static const u8 sBloques[][4] =
{
    // fila, columna, ancho, alto (en tiles)
    { 0, 0, 8, 8 },
    { 0, 8, 4, 8 },
    { 8, 0, 8, 4 },
    { 8, 8, 4, 4 },
};

#define TILES_POR_FILA (PIC_GRANDE_LADO / 8)   // 12

u32 BytesPicCombate(u32 especie, u32 personalidad, bool32 esFront)
{
    u32 medida;

    if (esFront)
    {
        if (gSpeciesInfo[especie].frontPicFemale != NULL && IsPersonalityFemale(especie, personalidad))
            medida = gSpeciesInfo[especie].frontPicSizeFemale;
        else
            medida = gSpeciesInfo[especie].frontPicSize;
    }
    else
    {
        if (gSpeciesInfo[especie].backPicFemale != NULL && IsPersonalityFemale(especie, personalidad))
            medida = gSpeciesInfo[especie].backPicSizeFemale;
        else
            medida = gSpeciesInfo[especie].backPicSize;
    }

    // La medida declarada es el area dibujada, que puede ser menor que el lienzo.
    // Lo que decide es si se sale de 64: entonces el lienzo es de 80.
    if (GET_MON_COORDS_WIDTH(medida) > 64 || GET_MON_COORDS_HEIGHT(medida) > 64)
        return PIC_GRANDE_BYTES;

    return MON_PIC_SIZE;
}

const struct SubspriteTable *SubspritesPicCombate(u32 bytesPorFotograma)
{
    if (bytesPorFotograma == PIC_GRANDE_BYTES)
        return sTablaPicGrande;

    return NULL;
}

void ReordenaPicGrande(u8 *datos, u32 numFotogramas)
{
    // Un fotograma de trabajo: el reparto solo cambia de sitio los tiles, no cambia
    // cuantos hay, asi que basta con copiar aparte el fotograma que se esta tocando.
    u8 *copia = Alloc(PIC_GRANDE_BYTES);

    if (copia == NULL)
    {
        // Sin buffer no se puede recolocar nada, y los tiles se quedan en orden de
        // imagen: cada pieza leeria los que no son y el Pokemon saldria en bandas.
        // Antes esto pasaba callado; ahora al menos se entera uno.
        LOG("REORDENADO SIN MEMORIA: el pic saldra roto", PIC_GRANDE_BYTES, 0);
        return;
    }

    for (u32 fotograma = 0; fotograma < numFotogramas; fotograma++)
    {
        u8 *marco = datos + fotograma * PIC_GRANDE_BYTES;
        const u8 *fuente = copia;
        u32 destino = 0;

        CopiaCpu32(marco, copia, PIC_GRANDE_BYTES);

        for (u32 b = 0; b < ARRAY_COUNT(sBloques); b++)
        {
            u32 fila = sBloques[b][0], columna = sBloques[b][1];
            u32 ancho = sBloques[b][2], alto = sBloques[b][3];

            for (u32 y = 0; y < alto; y++)
            {
                for (u32 x = 0; x < ancho; x++)
                {
                    u32 origen = (fila + y) * TILES_POR_FILA + (columna + x);

                    CopiaCpu32(fuente + origen * TILE_4BPP,
                               marco + destino * TILE_4BPP,
                               TILE_4BPP);
                    destino++;
                }
            }
        }
    }

    Free(copia);
}

// ---------------------------------------------------------------------------
// Ayuda de depuracion: repetir la animacion del Pokemon durante todo el combate.
//
// Sirve para mirar con calma como se comportan las piezas de un pic grande cuando
// entran matrices afines de por medio, en vez de tener una sola pasada al salir.
// Poner a 0 cuando ya no haga falta.
// ---------------------------------------------------------------------------
#define REPITE_ANIMACION_POKEMON 1
// El meneo afin repetido canta: al ser una deformacion de pixel art, las lineas
// diagonales se rompen un poco cada vez que pasa. Queda bien de tarde en tarde,
// como el gesto raro y espaciado que hacen los de BW. A 900 son 15 segundos.

#if REPITE_ANIMACION_POKEMON

// Ahora la animacion continua la lleva la propia tabla de la especie: sAnim_Venusaur
// encadena sus cuatro fotogramas y termina en ANIMCMD_JUMP, asi que gira sola. Lo unico
// que hace falta es asegurarse de que el sprite este reproduciendola y sin pausar, que
// el combate la deja parada en la pose 0 al salir.
static void ArrancaAnimacionContinua(void)
{
    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        u32 spriteId = gBattlerSpriteIds[combatiente];
        struct Sprite *sprite;

        if (spriteId >= MAX_SPRITES)
            continue;

        sprite = &gSprites[spriteId];

        if (!sprite->inUse || sprite->invisible || sprite->images == NULL)
            continue;

        // Solo los pics grandes: los de 64x64 tienen uno o dos fotogramas y pedirles
        // el tercero mostraria basura del buffer.
        if (sprite->images->size != PIC_GRANDE_BYTES)
            continue;

        // Y de momento solo el rival: el back de prueba se importo de una fuente que
        // solo tenia dos fotogramas, asi que los otros dos estan sin escribir.
        if (GetBattlerSide(combatiente) != LADO_OPONENTE)
            continue;

        sprite->animPaused = FALSE;
        StartSpriteAnimIfDifferent(sprite, 1);
    }
}

// Compara lo que hay en VRAM con lo que deberia haber. Es la ultima pieza sin
// verificar de la cadena: arte, reordenado, OAM y posiciones ya estan comprobados.
static void Task_RepiteAnimacionPokemon(u8 taskId)
{
    ArrancaAnimacionContinua();

}

static void ArrancaRepeticionAnimacion(void)
{
    if (!FuncIsActiveTask(Task_RepiteAnimacionPokemon))
        CreateTask(Task_RepiteAnimacionPokemon, 200);
}

#endif // REPITE_ANIMACION_POKEMON

// Engancha las piezas al sprite recien creado, si su pic las necesita. Se apoya en
// el tamano que quedo puesto en images al cargar el pic, asi que no hace falta
// consultar la especie otra vez.
void AplicaSubspritesPic(u32 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    const struct SubspriteTable *tabla;

#if REPITE_ANIMACION_POKEMON
    ArrancaRepeticionAnimacion();
#endif

    if (sprite->images == NULL)
        return;


    tabla = SubspritesPicCombate(sprite->images->size);
    if (tabla == NULL)
    {
        return;
    }

    SetSubspriteTables(sprite, tabla);
    // La prioridad la sigue mandando el combate, no la tabla.
    sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
}


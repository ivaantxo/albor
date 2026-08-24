#include "global.h"
#include "pic_combate.h"
#include "malloc.h"
#include "pokemon.h"
#include "data.h"
#include "constants/pokemon.h"
#include "battle.h"
#include "task.h"
#include "pokemon_animation.h"

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
static const struct Subsprite sPiezasPicGrande[] =
{
    { .x = -40, .y = -40, .shape = ST_OAM_SQUARE,      .size = 3, .tileOffset =   0, .priority = 2 },
    { .x =   8, .y = -40, .shape = ST_OAM_V_RECTANGLE, .size = 3, .tileOffset =  64, .priority = 2 },
    { .x = -40, .y =   8, .shape = ST_OAM_H_RECTANGLE, .size = 3, .tileOffset =  96, .priority = 2 },
    { .x =   8, .y =   8, .shape = ST_OAM_SQUARE,      .size = 2, .tileOffset = 128, .priority = 2 },
};

static const struct SubspriteTable sTablaPicGrande[] =
{
    { ARRAY_COUNT(sPiezasPicGrande), sPiezasPicGrande },
};

// El mismo reparto visto desde la imagen de origen. Las dos ultimas columnas y filas
// aparecen en dos piezas: eso es el solape, y es intencionado.
static const u8 sBloques[][4] =
{
    // fila, columna, ancho, alto (en tiles de la imagen de origen, que es de 10x10)
    { 0, 0, 8, 8 },
    { 0, 6, 4, 8 },
    { 6, 0, 8, 4 },
    { 6, 6, 4, 4 },
};

#define TILES_POR_FILA (PIC_GRANDE_LADO / 8)   // 10

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
    // Hay que copiarlo entero aparte antes de tocar nada: el destino ocupa mas que el
    // origen (144 tiles frente a 100), asi que al escribir el primer fotograma se
    // pisaria el segundo.
    u32 bytesOrigen = PIC_GRANDE_BYTES_ORIGEN * numFotogramas;
    u8 *copia = Alloc(bytesOrigen);

    if (copia == NULL)
        return;

    CopiaCpu32(datos, copia, bytesOrigen);

    for (u32 fotograma = 0; fotograma < numFotogramas; fotograma++)
    {
        u8 *marco = datos + fotograma * PIC_GRANDE_BYTES;
        const u8 *fuente = copia + fotograma * PIC_GRANDE_BYTES_ORIGEN;
        u32 destino = 0;

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
#define FOTOGRAMAS_ENTRE_REPETICIONES 900
#define FOTOGRAMAS_ENTRE_CAMBIOS_FRAME 24   // ~0,4 segundos: el vaiven continuo

#if REPITE_ANIMACION_POKEMON

// Alterna los dos fotogramas del pic, que es lo que hace de verdad una animacion
// estilo BW. Solo en los pics grandes: los de 64x64 tienen un unico fotograma en el
// back, y pedirles el segundo mostraria basura del buffer.
static void CambiaFotogramaPics(u32 cual)
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

        if (sprite->images->size != PIC_GRANDE_BYTES)
            continue;

        StartSpriteAnimIfDifferent(sprite, cual);
    }
}

static void Task_RepiteAnimacionPokemon(u8 taskId)
{
    if (++gTasks[taskId].data[1] >= FOTOGRAMAS_ENTRE_CAMBIOS_FRAME)
    {
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] ^= 1;
        CambiaFotogramaPics(gTasks[taskId].data[2]);
    }

    if (++gTasks[taskId].data[0] < FOTOGRAMAS_ENTRE_REPETICIONES)
        return;

    gTasks[taskId].data[0] = 0;

    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        u32 spriteId = gBattlerSpriteIds[combatiente];
        struct Sprite *sprite;
        u32 especie;

        if (spriteId >= MAX_SPRITES)
            continue;

        sprite = &gSprites[spriteId];

        // Solo si esta en pantalla y quieto: si tiene callback propio es que el
        // combate lo esta moviendo, y no hay que pisarlo.
        if (!sprite->inUse || sprite->invisible || sprite->callback != SpriteCallbackDummy)
            continue;

        especie = sprite->data[2];
        if (especie == SPECIES_NONE || especie >= NUM_SPECIES)
            continue;

        if (GetBattlerSide(combatiente) == LADO_OPONENTE)
            LaunchAnimationTaskForFrontSprite(sprite, gSpeciesInfo[especie].frontAnimId);
        else
            LaunchAnimationTaskForBackSprite(sprite, GetSpeciesBackAnimSet(especie));
    }
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
        return;

    SetSubspriteTables(sprite, tabla);
    // La prioridad la sigue mandando el combate, no la tabla.
    sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
}


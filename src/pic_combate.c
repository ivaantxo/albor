#include "global.h"
#include "battle_main.h"
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
// PROVISIONAL, mientras se prueban los pics grandes: los aparta de donde los deja
// el combate, que cuenta con 64x64. Poner a 0 cuando las coordenadas de los
// combatientes sepan del tamano de cada pic.
#define CORRIGE_SITIO_PIC_GRANDE 1
#define DESPLAZA_PIC_GRANDE_X 16
#define DESPLAZA_PIC_GRANDE_Y 32

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
    // Mientras el Pokemon esta en primer plano no se le toca la animacion.
    //
    // SpriteCB_WildMon la deja pausada a proposito para que la entrada se vea
    // quieta, pero esto corre en cada fotograma y se la despausaba: el pic cambiaba
    // de dibujo estando escalado, y ahi es donde se veia mal. Las piezas de un pic
    // troceado aguantan bien el zoom quieto; lo que no aguantan es cambiar de
    // fotograma en mitad de el.
    if (gZoomEntradaEnMarcha)
        return;

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

        sprite->animPaused = FALSE;

        // Los dos bandos no usan la misma tabla. El frontal tiene la suya por especie,
        // con los cuatro fotogramas y su gesto especial; el de espalda comparte
        // gAnims_MonPic con todos los demas, y ahi el vaiven continuo es el indice 2.
        if (GetBattlerSide(combatiente) == LADO_OPONENTE)
            StartSpriteAnimIfDifferent(sprite, 1);
        else
            StartSpriteAnimIfDifferent(sprite, ANIM_ESPALDA_BUCLE);
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

// Lo minimo que tiene que medir el hueco de un combatiente: no solo guarda los
// fotogramas del pic, tambien lo usan de zona de trabajo battle_intro, el sustituto y
// la escena de evolucion.
#define BYTES_MINIMOS_HUECO (MON_PIC_SIZE * NUMERO_FRAMES_POKEMON)

// Asegura que el hueco de un combatiente mida al menos lo pedido, y devuelve donde
// esta. Reserva UNA sola vez y al tamano definitivo: la version anterior reservaba
// pequeno para los cuatro y luego liberaba y volvia a pedir grande para los que lo
// necesitaban, y eso dejaba huecos de 8 KB que ya no valian para nada. En un combate
// doble con dos frentes de 96x96 el monton se fragmentaba, la ultima reserva fallaba
// y el puntero se quedaba a NULL: el pic se descomprimia sobre la direccion 0 y el
// Pokemon salia transparente.
u8 *HuecoPic(u32 posicion, u32 bytes)
{
    u8 *nuevo;

    if (bytes < BYTES_MINIMOS_HUECO)
        bytes = BYTES_MINIMOS_HUECO;

    if (gMonSpritesGfxPtr->tamanoHueco[posicion] >= bytes)
        return gMonSpritesGfxPtr->spritesGfx[posicion];

    // Se pide lo nuevo ANTES de soltar lo viejo: si no hay sitio, mas vale quedarse
    // con un hueco pequeno -el sprite saldra mal- que con ninguno, que descompone
    // sobre la direccion cero y se lleva por delante lo que pille.
    nuevo = AllocZeroed(bytes);
    if (nuevo == NULL)
    {
        LOG("SIN MEMORIA para el pic de la posicion", posicion, bytes);
        return gMonSpritesGfxPtr->spritesGfx[posicion];
    }

    if (gMonSpritesGfxPtr->spritesGfx[posicion] != NULL)
        Free(gMonSpritesGfxPtr->spritesGfx[posicion]);

    gMonSpritesGfxPtr->spritesGfx[posicion] = nuevo;
    gMonSpritesGfxPtr->tamanoHueco[posicion] = bytes;
    return nuevo;
}

void PreparaHuecoPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront)
{
    const u32 *comprimido = esFront ? gSpeciesInfo[especie].frontPic : gSpeciesInfo[especie].backPic;
    u32 bytes = BytesPicCombate(especie, personalidad, esFront) * NUMERO_FRAMES_POKEMON;

    // Con los fotogramas que trae de verdad, no con el maximo. La cabecera LZ77 dice
    // cuanto ocupa descomprimido, y un back de dos fotogramas necesita la mitad que
    // uno de cuatro. En un combate doble con los cuatro a 96x96, reservar siempre el
    // maximo son 73 KB de los 114 del monton y la ultima peticion se queda sin sitio.
    if (comprimido != NULL)
    {
        u32 real = comprimido[0] >> 8;

        if (real != 0 && real < bytes)
            bytes = real;
    }

    HuecoPic(posicion, bytes);
}

// Y esto DESPUES de descomprimir: recoloca los tiles si el pic es de los grandes y
// deja cada fotograma apuntando a su sitio con el tamano que le toca. Hay que hacerlo
// aqui y no al reservar: hasta que no se sabe que Pokemon entra no se sabe cuanto ocupa.
void AjustaFotogramasPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront)
{
    u32 bytes = BytesPicCombate(especie, personalidad, esFront);
    u32 reales;

    // Cuantos fotogramas caben de verdad en el hueco. NO se puede dar por hecho que
    // sean NUMERO_FRAMES_POKEMON: el hueco se pide segun lo que traiga el pic, y un
    // back de dos fotogramas mide la mitad. Reordenar cuatro sobre un hueco de dos
    // escribe fuera y revienta lo que haya detras.
    reales = gMonSpritesGfxPtr->tamanoHueco[posicion] / bytes;
    if (reales > NUMERO_FRAMES_POKEMON)
        reales = NUMERO_FRAMES_POKEMON;
    if (reales == 0)
        reales = 1;

    if (bytes == PIC_GRANDE_BYTES)
        ReordenaPicGrande(gMonSpritesGfxPtr->spritesGfx[posicion], reales);

    for (u32 fotograma = 0; fotograma < NUMERO_FRAMES_POKEMON; fotograma++)
    {
        // Los fotogramas que el pic no trae apuntan al primero, que siempre existe.
        // Asi, si una animacion pide uno de mas, repite pose en vez de enseñar
        // basura o leer fuera del hueco.
        u32 cual = (fotograma < reales) ? fotograma : 0;

        gMonSpritesGfxPtr->frameImages[posicion][fotograma].data =
            gMonSpritesGfxPtr->spritesGfx[posicion] + (cual * bytes);
        gMonSpritesGfxPtr->frameImages[posicion][fotograma].size = bytes;
    }
}

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

#if CORRIGE_SITIO_PIC_GRANDE
    // PROVISIONAL. Las coordenadas de los combatientes -GetBattlerSpriteCoord y
    // GetBattlerSpriteDefault_Y- estan calculadas para pics de 64x64, asi que uno
    // de 96x96 nace descentrado y con media cabeza tapada. Esto lo aparta para
    // poder mirarlo mientras se prueban el zoom y las piezas.
    //
    // No es el arreglo bueno: el sitio de verdad es la tabla de coordenadas, que
    // tiene que tener en cuenta el tamano del pic de cada especie.
    sprite->x -= DESPLAZA_PIC_GRANDE_X;
    sprite->y -= DESPLAZA_PIC_GRANDE_Y;
#endif
}


// Cierto si el pic de este sprite es de los grandes, o sea de los que se dibujan
// troceados. Lo necesita quien tenga que tratarlos distinto -por ejemplo, para
// darles un zoom de entrada que no abra costuras entre las piezas-.
bool32 EsPicGrande(u32 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];

    return sprite->images != NULL
        && SubspritesPicCombate(sprite->images->size) != NULL;
}

#include "global.h"
#include "battle_main.h"
#include "pic_combate.h"
#include "malloc.h"
#include "pokemon.h"
#include "data.h"
#include "constants/pokemon.h"
#include "battle.h"
#include "battle_controllers.h"
#include "task.h"
#include "pokemon_animation.h"
#include "depuracion_mgba.h"

// Reparto de un pic de 80x80 en objetos legales de GBA. 80 = 64 + 16 en los dos
// ejes, asi que salen seis piezas y ni un tile desperdiciado:
//
//     +---------------+----+      A 64x64 -> 64 tiles    D 32x16 -> 8
//     |               | B  |      B 16x32 ->  8          E 32x16 -> 8
//     |       A       +----+      C 16x32 ->  8          F 16x16 -> 4
//     |               | C  |                             TOTAL    100
//     +-------+-------+----+
//     |   D   |   E   | F  |
//     +-------+-------+----+
//
// Las coordenadas van referidas al centro del sprite -que en 80x80 esta en (40,40)-,
// que es lo que espera AddSubspritesToOamBuffer.
static const struct Subsprite sPiezasPic80[] =
{
    { .x = -40, .y = -40, .shape = ST_OAM_SQUARE,      .size = 3, .tileOffset =  0, .priority = 2 },
    { .x =  24, .y = -40, .shape = ST_OAM_V_RECTANGLE, .size = 2, .tileOffset = 64, .priority = 2 },
    { .x =  24, .y =  -8, .shape = ST_OAM_V_RECTANGLE, .size = 2, .tileOffset = 72, .priority = 2 },
    { .x = -40, .y =  24, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 80, .priority = 2 },
    { .x =  -8, .y =  24, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 88, .priority = 2 },
    { .x =  24, .y =  24, .shape = ST_OAM_SQUARE,      .size = 1, .tileOffset = 96, .priority = 2 },
};

static const struct SubspriteTable sTablaPic80[] =
{
    { ARRAY_COUNT(sPiezasPic80), sPiezasPic80 },
};

// El mismo reparto visto desde la imagen de origen, que llega en tiles de 10 por fila.
static const u8 sBloques80[][4] =
{
    // fila, columna, ancho, alto (en tiles)
    { 0, 0, 8, 8 },
    { 0, 8, 2, 4 },
    { 4, 8, 2, 4 },
    { 8, 0, 4, 2 },
    { 8, 4, 4, 2 },
    { 8, 8, 2, 2 },
};

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

// El pic comprimido de una especie, tal cual lo elegiria LoadSpecialPokePic.
//
// Tiene que ser la MISMA fuente que descomprime el juego: una hembra puede tener un
// lienzo o un numero de poses distintos del macho, y si aqui se mira uno y alli se
// carga otro, todo lo que se calcule a partir de esto sale mal.
static const u32 *PicComprimido(u32 especie, u32 personalidad, bool32 esFront)
{
    const struct SpeciesInfo *info;
    bool32 hembra;

    especie = SanitizeSpeciesId(especie);
    info = &gSpeciesInfo[especie];
    hembra = IsPersonalityFemale(especie, personalidad);

    if (esFront)
    {
        if (hembra && info->frontPicFemale != NULL)
            return info->frontPicFemale;
        if (info->frontPic != NULL)
            return info->frontPic;
        return gSpeciesInfo[SPECIES_NONE].frontPic;
    }

    if (hembra && info->backPicFemale != NULL)
        return info->backPicFemale;
    if (info->backPic != NULL)
        return info->backPic;
    return gSpeciesInfo[SPECIES_NONE].backPic;
}

// Lo que ocupa el pic ENTERO una vez descomprimido, o cero si no hay pic. Lo dice la
// cabecera LZ77, en sus tres bytes altos.
static u32 BytesTotalesPic(u32 especie, u32 personalidad, bool32 esFront)
{
    const u32 *comprimido = PicComprimido(especie, personalidad, esFront);

    return (comprimido != NULL) ? comprimido[0] >> 8 : 0;
}

// Los lienzos que existen, de mayor a menor. El orden importa: se elige el primero
// que encaje.
static const u32 sLienzos[] = { PIC_GRANDE_BYTES, PIC_80_BYTES, MON_PIC_SIZE };

// El primer choque entre lienzos esta en las 9 poses de 64x64. Ver POSES_MAXIMAS_PIC.
STATIC_ASSERT(POSES_MAXIMAS_PIC < 9, poses_maximas_hacen_ambigua_la_deduccion);

// Cuantos bytes hay entre una pose y la siguiente.
//
// El lienzo NO se declara en species_info: se deduce del propio arte. La cabecera
// LZ77 dice lo que pesa el pic entero, y solo un lienzo divide ese peso exacto sin
// pasarse de poses. Asi es imposible que el numero y el dibujo se desincronicen, que
// es justo lo que pasaba cuando esto salia de frontPicSize: ese campo es el AREA
// DIBUJADA -lo que usan las animaciones de combate para saber donde estan los bordes
// del bicho- y no el lienzo, y las dos cosas no tienen por que coincidir.
//
// Dos condiciones, y las dos hacen falta: que el peso se reparta exacto en ese lienzo
// y que salgan poses de las que caben. Lo segundo es lo que deshace los empates -18432
// bytes son 4 poses de 96x96 o 9 de 64x64, y las 9 se descartan por pasarse-, asi que
// no sobra: sin ese tope habria que elegir a ciegas.
//
// El precio de deducir en vez de declarar: un pic que SI trajera 9 poses de 64x64 se
// leeria como uno de 96x96 de 4, y sin ruido. Por eso POSES_MAXIMAS_PIC es un limite
// del arte, no una preferencia. Si algun dia hacen falta mas poses, el lienzo hay que
// sacarlo del ancho del PNG en tiempo de compilacion.
u32 BytesPicCombate(u32 especie, u32 personalidad, bool32 esFront)
{
    u32 total = BytesTotalesPic(especie, personalidad, esFront);

    for (u32 i = 0; i < ARRAY_COUNT(sLienzos); i++)
    {
        if (total != 0 && total % sLienzos[i] == 0 && total / sLienzos[i] <= POSES_MAXIMAS_PIC)
            return sLienzos[i];
    }

    // Sin pic, o con uno que no encaja en ningun lienzo conocido: el de siempre.
    return MON_PIC_SIZE;
}

const struct SubspriteTable *SubspritesPicCombate(u32 bytesPorFotograma)
{
    if (bytesPorFotograma == PIC_GRANDE_BYTES)
        return sTablaPicGrande;
    if (bytesPorFotograma == PIC_80_BYTES)
        return sTablaPic80;

    return NULL;
}

void ReordenaPicTroceado(u8 *datos, u32 numFotogramas, u32 bytesPorFotograma)
{
    const u8 (*bloques)[4];
    u32 cuantosBloques, tilesPorFila;
    u8 *copia;

    if (bytesPorFotograma == PIC_GRANDE_BYTES)
    {
        bloques = sBloques;
        cuantosBloques = ARRAY_COUNT(sBloques);
        tilesPorFila = PIC_GRANDE_LADO / 8;
    }
    else if (bytesPorFotograma == PIC_80_BYTES)
    {
        bloques = sBloques80;
        cuantosBloques = ARRAY_COUNT(sBloques80);
        tilesPorFila = PIC_80_LADO / 8;
    }
    else
    {
        return;     // cabe en un solo objeto: no hay nada que repartir
    }

    // Un fotograma de trabajo: el reparto solo cambia de sitio los tiles, no cambia
    // cuantos hay, asi que basta con copiar aparte el fotograma que se esta tocando.
    copia = Alloc(bytesPorFotograma);

    if (copia == NULL)
    {
        // Sin buffer no se puede recolocar nada, y los tiles se quedan en orden de
        // imagen: cada pieza leeria los que no son y el dibujo saldria en bandas.
        // Antes esto pasaba callado; ahora al menos se entera uno.
        LOG("REORDENADO SIN MEMORIA: el pic saldra roto", bytesPorFotograma, 0);
        return;
    }

    for (u32 fotograma = 0; fotograma < numFotogramas; fotograma++)
    {
        u8 *marco = datos + fotograma * bytesPorFotograma;
        const u8 *fuente = copia;
        u32 destino = 0;

        CopiaCpu32(marco, copia, bytesPorFotograma);

        for (u32 b = 0; b < cuantosBloques; b++)
        {
            u32 fila = bloques[b][0], columna = bloques[b][1];
            u32 ancho = bloques[b][2], alto = bloques[b][3];

            for (u32 y = 0; y < alto; y++)
            {
                for (u32 x = 0; x < ancho; x++)
                {
                    u32 origen = (fila + y) * tilesPorFila + (columna + x);

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
// A 1 el pic sigue cambiando de fotograma mientras esta ampliado, que es lo que se
// quiere mirar. A 0 se queda quieto hasta que el zoom acaba.
#define ANIMA_DURANTE_EL_ZOOM 1

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
#if !ANIMA_DURANTE_EL_ZOOM
    if (gZoomEntradaEnMarcha)
        return;
#endif

    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        u32 spriteId = gBattlerSpriteIds[combatiente];
        struct Sprite *sprite;

        if (spriteId >= MAX_SPRITES)
            continue;

        sprite = &gSprites[spriteId];

        if (!sprite->inUse || sprite->invisible || sprite->images == NULL)
            continue;

        // Mientras la salida no ha terminado no se le toca la animacion.
        //
        // Quien la vigila es el sprite invisible de gBattleControllerData, con
        // SpriteCB_WaitForBattlerBallReleaseAnim: espera a que la animacion del
        // Pokemon acabe -animEnded- y solo entonces se pone en el callback vacio,
        // que es lo que la intro del combate espera para dar paso al menu.
        //
        // Ponerle aqui el vaiven continuo, que da vueltas y no acaba nunca, le
        // borraba ese animEnded justo antes de que lo leyera y el combate se
        // quedaba colgado con el mensaje en pantalla.
        //
        // No sirve mirar el callback del propio Pokemon -es el vacio un instante
        // antes de que la secuencia arranque- ni ballAnimActive, que aqui no se
        // enciende porque el Pokemon del jugador no sale de una Pokeball.
        {
            u32 vigilante = gBattleControllerData[combatiente];

            if (vigilante < MAX_SPRITES && gSprites[vigilante].inUse
                && gSprites[vigilante].callback != SpriteCallbackDummy)
                continue;
        }


        // Solo los que tienen mas de un fotograma, se llamen como se llamen de
        // grandes. Antes esto preguntaba si el pic era de 96x96, y se quedaba fuera
        // cualquier especie animada en una caja menor: AjustaFotogramasPic hace que
        // los fotogramas que el pic NO trae apunten al primero, asi que basta con
        // mirar si el segundo va a otro sitio.
        if (sprite->images[1].data == sprite->images[0].data)
            continue;

        sprite->animPaused = FALSE;

        // Los dos bandos no usan la misma tabla. El frontal tiene la suya por especie,
        // con los cuatro fotogramas y su gesto especial; el de espalda comparte
        // gAnims_MonPic con todos los demas, y ahi el vaiven continuo es el indice 2.
        if (GetBattlerSide(combatiente) == LADO_OPONENTE)
            StartSpriteAnimIfDifferent(sprite, ANIM_FRENTE_BUCLE);
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
// la escena de evolucion. Va por FOTOGRAMAS_ZONA_TRABAJO, que es lo que esos tres
// necesitan, y NO por el techo de fotogramas de la animacion: ver el comentario de
// FOTOGRAMAS_ZONA_TRABAJO en constants/pokemon.h.
#define BYTES_MINIMOS_HUECO (MON_PIC_SIZE * FOTOGRAMAS_ZONA_TRABAJO)

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

// Cuanto ocupa el pic de una especie una vez descomprimido. Es la cifra que hay que
// reservar para descomprimirlo entero: LoadSpecialPokePic vuelca TODOS los fotogramas
// que trae el pic, no solo el primero, asi que quedarse corto escribe fuera del bloque.
//
// Sale de la cabecera, o sea de las poses que el pic trae de verdad y no del techo: un
// back de dos fotogramas necesita la mitad que uno de cuatro. Y manda EN LOS DOS
// SENTIDOS: un pic con mas poses de las que dice NUMERO_FRAMES_POKEMON tambien se
// reserva entero, que si no se descomprime fuera del bloque y calla.
u32 BytesPicDescomprimido(u32 especie, u32 personalidad, bool32 esFront)
{
    u32 total = BytesTotalesPic(especie, personalidad, esFront);

    // Sin pic no hay cabecera que mirar: se reserva el techo, que es lo unico seguro.
    if (total == 0)
        return BytesPicCombate(especie, personalidad, esFront) * NUMERO_FRAMES_POKEMON;

    return total;
}

void PreparaHuecoPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront)
{
    HuecoPic(posicion, BytesPicDescomprimido(especie, personalidad, esFront));
}

// Y esto DESPUES de descomprimir: recoloca los tiles si el pic es de los grandes y
// deja cada fotograma apuntando a su sitio con el tamano que le toca. Hay que hacerlo
// aqui y no al reservar: hasta que no se sabe que Pokemon entra no se sabe cuanto ocupa.
void AjustaFotogramasPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront)
{
    u32 bytes = BytesPicCombate(especie, personalidad, esFront);
    u32 reales;

    // Cuantas poses trae el pic. La division es exacta por construccion: los dos
    // numeros salen de la misma cabecera LZ77.
    //
    // NO vale mirar solo el hueco. HuecoPic unicamente agranda, nunca encoge, asi que
    // el hueco puede ser mayor por la zona de trabajo o porque antes lo uso un Pokemon
    // con mas poses. Esos bytes de mas no son imagenes: contarlos hacia que la ultima
    // pose apuntara a restos del inquilino anterior, y con otro paso de fotograma, o
    // sea a media pieza. El hueco solo manda como tope, por si la ampliacion fallo.
    reales = min(BytesPicDescomprimido(especie, personalidad, esFront),
                 gMonSpritesGfxPtr->tamanoHueco[posicion]) / bytes;
    if (reales > NUMERO_FRAMES_POKEMON)
        reales = NUMERO_FRAMES_POKEMON;
    if (reales == 0)
        reales = 1;

    // Sin condicion: ReordenaPicTroceado sale sola si el pic cabe en un solo objeto.
    ReordenaPicTroceado(gMonSpritesGfxPtr->spritesGfx[posicion], reales, bytes);

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
// Solo las piezas, sin tocar la posicion. Es lo que necesita cualquiera que sepa
// donde va su sprite, como los entrenadores.
void AplicaSubspritesSinMover(u32 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    const struct SubspriteTable *tabla;

    if (sprite->images == NULL)
        return;

    tabla = SubspritesPicCombate(sprite->images->size);
    if (tabla == NULL)
        return;

    SetSubspriteTables(sprite, tabla);
    // La prioridad la sigue mandando el combate, no la tabla.
    sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
}

void AplicaSubspritesPic(u32 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];

#if REPITE_ANIMACION_POKEMON
    ArrancaRepeticionAnimacion();
#endif

    AplicaSubspritesSinMover(spriteId);

    // De aqui para abajo, cosas del Pokemon. El apano de posicion que viene ahora es
    // de las coordenadas de combatiente, y a un entrenador no le corresponde: por eso
    // esta funcion y la de arriba estan separadas.
    if (sprite->subspriteTables == NULL)
        return;

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

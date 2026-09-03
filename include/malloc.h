#ifndef GUARD_ALLOC_H
#define GUARD_ALLOC_H


#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    Free(ptr);                          \
    ptr = NULL;                         \
}

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

// Trece bits, no dieciseis: es lo que sobra en la palabra despues de la marca de
// ocupado y del tamano, y con eso la cabecera baja de dieciseis bytes a doce. El
// valor da igual mientras sea reconocible; lo que importa es que un bloque
// pisoteado casi nunca lo conserve por casualidad.
#define MALLOC_SYSTEM_ID 0x1A3A

// Doce bytes de cabecera por bloque. Antes eran dieciseis: los otros cuatro se iban
// en guardar la linea de codigo que habia pedido el bloque, partida en dos mitades
// para que cupiera entre los demas campos. Nunca se llego a rellenar -las macros
// pasaban siempre NULL- ni a leer, asi que cada reserva del juego pagaba por un
// puntero que valia cero.
struct MemBlock
{
    // Numero magico para detectar bloques pisoteados. Vale MALLOC_SYSTEM_ID.
    u32 magic:13;

    // Si el bloque esta en uso.
    u32 allocated:1;

    // Lo que mide el bloque, sin contar esta cabecera. Dieciocho bits llegan hasta
    // 256 KB, que es toda la EWRAM: el monton no puede pasar de ahi.
    u32 size:18;

    // Previous block pointer. Equals gHeap if this is the first block.
    struct MemBlock *prev;

    // Next block pointer. Equals gHeap if this is the last block.
    struct MemBlock *next;

    // Data in the memory block. (Arrays of length 0 are a GNU extension.)
    u8 data[0];
};

// Doce bytes, comprobado al compilar. Cada bloque del monton paga esta cabecera,
// asi que si alguien vuelve a meter un campo aqui conviene que se entere.
STATIC_ASSERT(sizeof(struct MemBlock) == 12, LaCabeceraDeBloqueHaCambiadoDeTamano);

// 144 KB. Eran 112 y no llegaban: un combate contra un Bulbasaur de BW pide 88 KB
// solo en los dos pic -23 fotogramas su frente y 20 tu espalda-, y de los 112 hay
// 32 apartados antes para los buffers de los combatientes.
//
// El techo es la EWRAM, que son 256 KB y ya lleva 209 de datos: subir mucho mas
// dejaria al enlazador sin sitio. Y size, en la cabecera de bloque, son dieciocho
// bits, o sea 256 KB justos.
#define HEAP_SIZE 147456
extern u8 gHeap[HEAP_SIZE];



void *Alloc(u32 size);
void *AllocZeroed(u32 size);
void Free(void *pointer);
bool32 CheckHeap(void);
void InitHeap(void);

const struct MemBlock *HeapHead(void);

// Cuanto queda libre en total y cuanto mide el mayor hueco seguido. Las dos cifras
// juntas distinguen "no hay memoria" de "la hay, pero partida".
void MideMonton(u32 *libre, u32 *mayorHueco);

#endif // GUARD_ALLOC_H

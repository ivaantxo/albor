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

// El monton NO tiene tamano fijo: se queda con toda la EWRAM que sobre despues de
// los datos, y el enlazador decide cuanta es. Los dos simbolos los pone ld_script.ld,
// que ademas comprueba al enlazar que no baje de 128 KB.
//
// Antes era un array con un numero escrito a mano, y ese numero solo se subia cuando
// algo dejaba de caber: entre subida y subida habia EWRAM pagada y sin usar. Y al
// reves, al anadir datos el monton menguaba sin que nadie se enterara.
//
// El techo de verdad son los dieciocho bits del campo size de la cabecera de bloque:
// 256 KB, que es justo toda la EWRAM, asi que no estorba.
extern u8 __monton_inicio[];
extern u8 __monton_bytes[];

#define gHeap       __monton_inicio
#define HEAP_SIZE   ((u32)__monton_bytes)



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

#ifndef GUARD_PIC_COMBATE_H
#define GUARD_PIC_COMBATE_H

#include "sprite.h"

// Los pics de combate ya no son todos de 64x64. El motor sigue trabajando con un
// solo sprite por combatiente, pero cuando el pic pasa de 64 hay que repartirlo en
// varios objetos, porque 64x64 es el mayor tamano de OBJ que existe en GBA.
#define PIC_GRANDE_LADO       80

// El lienzo son 100 tiles, pero en VRAM ocupa 144: las piezas se solapan 16 px y
// esos tiles van duplicados. Es el precio de que las animaciones afines no abran
// costuras -los OBJ de GBA no tienen posicion subpixel, asi que al rotar cada pieza
// se desalinea hasta un pixel de su vecina; con solape, el hueco lo tapa la de al lado.
#define PIC_GRANDE_TILES_ORIGEN 100
#define PIC_GRANDE_TILES        144
#define PIC_GRANDE_BYTES_ORIGEN (PIC_GRANDE_TILES_ORIGEN * TILE_4BPP)   // 3200
#define PIC_GRANDE_BYTES        (PIC_GRANDE_TILES * TILE_4BPP)          // 4608

// Lo que hay que reservar por fotograma y combatiente: el mayor de los casos.
#define MAX_PIC_BYTES        PIC_GRANDE_BYTES

// Cuantos bytes ocupa un fotograma del pic de esta especie (segun genero).
u32 BytesPicCombate(u32 especie, u32 personalidad, bool32 esFront);

// La tabla de piezas, o NULL si el pic cabe en un solo objeto de 64x64.
const struct SubspriteTable *SubspritesPicCombate(u32 bytesPorFotograma);

// gbagfx entrega los tiles en orden de lectura de la imagen completa; el OAM los
// quiere agrupados por pieza. Esto los recoloca en el sitio.
void ReordenaPicGrande(u8 *datos, u32 numFotogramas);

// Pone las piezas al sprite del combatiente si su pic pasa de 64x64.
void AplicaSubspritesPic(u32 spriteId);

#endif // GUARD_PIC_COMBATE_H

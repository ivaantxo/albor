#ifndef GUARD_PIC_COMBATE_H
#define GUARD_PIC_COMBATE_H

#include "sprite.h"

// Los pics de combate ya no son todos de 64x64. El motor sigue trabajando con un
// solo sprite por combatiente, pero cuando el pic pasa de 64 hay que repartirlo en
// varios objetos, porque 64x64 es el mayor tamano de OBJ que existe en GBA.
// El lienzo de combate para las especies grandes: 96x96, que es el tamano nativo de
// los sprites de BW/B2W2. Son 12x12 = 144 tiles justos, que se reparten en cuatro
// objetos sin desperdiciar ninguno.
//
// No hay solape entre piezas, y eso tiene una consecuencia que conviene tener
// presente: si a uno de estos sprites se le aplica una matriz afin, se le abriran
// costuras. No es un defecto del reparto, es que los OBJ de GBA anclan el muestreo a
// una posicion entera y no hay forma de pedirles medio pixel. Los fondos afines si
// pueden -BG2X/BG2Y tienen 8 bits de parte fraccionaria-, asi que si algun dia hace
// falta un zoom, el sitio donde hacerlo es una capa de fondo, no el sprite.
#define PIC_GRANDE_LADO       96
#define PIC_GRANDE_TILES     144
#define PIC_GRANDE_BYTES     (PIC_GRANDE_TILES * TILE_4BPP)   // 4608

// Lo que hay que reservar por fotograma y combatiente: el mayor de los casos.
#define MAX_PIC_BYTES        PIC_GRANDE_BYTES

// Cuantos bytes ocupa un fotograma del pic de esta especie (segun genero).
u32 BytesPicCombate(u32 especie, u32 personalidad, bool32 esFront);

// La tabla de piezas, o NULL si el pic cabe en un solo objeto de 64x64.
const struct SubspriteTable *SubspritesPicCombate(u32 bytesPorFotograma);

// gbagfx entrega los tiles en orden de lectura de la imagen completa; el OAM los
// quiere agrupados por pieza. Esto los recoloca en el sitio.
void ReordenaPicGrande(u8 *datos, u32 numFotogramas);

// Indice del vaiven continuo dentro de gAnims_MonPic, la tabla de los sprites de
// espalda. Ver src/data.c.
#define ANIM_ESPALDA_BUCLE 2

// Asegura que el hueco de un combatiente mida al menos lo pedido. Devuelve donde esta,
// que puede seguir siendo el anterior si no hubo memoria.
u8 *HuecoPic(u32 posicion, u32 bytes);

// Agranda el hueco del combatiente si su pic lo necesita. Llamar ANTES de descomprimir.
void PreparaHuecoPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront);

// Recoloca los tiles y reparte los fotogramas. Llamar DESPUES de descomprimir.
void AjustaFotogramasPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront);

// Pone las piezas al sprite del combatiente si su pic pasa de 64x64.
void AplicaSubspritesPic(u32 spriteId);

bool32 EsPicGrande(u32 spriteId);

#endif // GUARD_PIC_COMBATE_H

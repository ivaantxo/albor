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

// El otro lienzo troceado: 80x80, que es la medida de los graficos de entrenador.
#define PIC_80_LADO           80
#define PIC_80_TILES         100
#define PIC_80_BYTES         (PIC_80_TILES * TILE_4BPP)       // 3200

// Lo que hay que reservar por fotograma y combatiente: el mayor de los casos.
#define MAX_PIC_BYTES        PIC_GRANDE_BYTES

// Cuantas poses puede traer un pic como mucho.
//
// No es un limite de la animacion -de eso va NUMERO_FRAMES_POKEMON-, es lo que hace
// que el lienzo se pueda DEDUCIR del peso del pic en vez de declararlo a mano. La
// cuenta: 9 poses de 64x64 pesan 18432 bytes, exactamente lo mismo que 4 de 96x96,
// asi que a partir de las 9 el peso deja de decir cual de los dos es. Por debajo, no
// hay dos lienzos que coincidan (los otros choques estan en 16 y en 25 poses).
#define POSES_MAXIMAS_PIC      8

// Cuantos bytes ocupa un fotograma del pic de esta especie (segun genero).
u32 BytesPicCombate(u32 especie, u32 personalidad, bool32 esFront);
u32 BytesPicDescomprimido(u32 especie, u32 personalidad, bool32 esFront);

// La tabla de piezas, o NULL si el pic cabe en un solo objeto de 64x64.
const struct SubspriteTable *SubspritesPicCombate(u32 bytesPorFotograma);

// gbagfx entrega los tiles en orden de lectura de la imagen completa; el OAM los
// quiere agrupados por pieza. Esto los recoloca en el sitio. Vale para los dos
// lienzos troceados: se le pasa cuanto mide un fotograma.
void ReordenaPicTroceado(u8 *datos, u32 numFotogramas, u32 bytesPorFotograma);

// Indice del vaiven continuo dentro de gAnims_MonPic, la tabla de los sprites de
// espalda. Ver src/data.c.
#define ANIM_ESPALDA_BUCLE 2

// Y el del frente, que tiene tabla propia por especie y no comparte reparto con el de
// espalda: ahi la continua es la 1. Ver frontAnimFrames en species_info.h.
#define ANIM_FRENTE_BUCLE 1

// Asegura que el hueco de un combatiente mida al menos lo pedido. Devuelve donde esta,
// que puede seguir siendo el anterior si no hubo memoria.
u8 *HuecoPic(u32 posicion, u32 bytes);

// Reparte el sprite en piezas si su pic no cabe en un objeto, y NADA mas. La version
// con nombre a secas ademas le corrige la posicion, que es un apano de los pics de
// Pokemon y no vale para los entrenadores.
void AplicaSubspritesSinMover(u32 spriteId);

// Agranda el hueco del combatiente si su pic lo necesita. Llamar ANTES de descomprimir.
void PreparaHuecoPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront);

// Recoloca los tiles y reparte los fotogramas. Llamar DESPUES de descomprimir.
void AjustaFotogramasPic(u32 posicion, u32 especie, u32 personalidad, bool32 esFront);

// Pone las piezas al sprite del combatiente si su pic pasa de 64x64.
void AplicaSubspritesPic(u32 spriteId);

bool32 EsPicGrande(u32 spriteId);

#endif // GUARD_PIC_COMBATE_H

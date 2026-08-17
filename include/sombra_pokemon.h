#ifndef GUARD_SOMBRA_POKEMON_H
#define GUARD_SOMBRA_POKEMON_H

#include "sprite.h"

// Sombra de un Pokemon: un duplicado negro y semitransparente de su propia
// silueta, aplastado contra el suelo e inclinado.
//
// Es una segunda entrada de OAM que apunta a los MISMOS tiles del sprite del
// Pokemon, pero con una paleta enteramente negra y en modo semitransparente. Los
// pixeles opacos del bicho salen negros y se mezclan con el fondo; los
// transparentes siguen siendolo. De ahi salen tres propiedades:
//
//   - No gasta un solo tile. La silueta es la del bicho.
//   - Se anima sola con el, porque comparte sus tiles.
//   - La inclinacion sale de una matriz afin, no de dibujarla.
//
// Cuesta un hueco de paleta, compartido por todas las sombras, y reserva la
// mezcla del hardware mientras haya alguna en pantalla.

// Grados de libertad de la sombra, en coma fija 8.8 (256 = 1,0).
//
// APLASTADO  alto respecto al original. 256 la deja igual de alta, 128 a la
//            mitad. Cuanto mas alto, mas se alarga la sombra.
// INCLINACION cuanto se tumba. Positivo la lleva hacia la DERECHA por arriba;
//            negativo, hacia la izquierda.
#define SOMBRA_INCLINACION 160

// El aplastado va por tamano de sombra, que cada especie declara en
// enemyShadowSize. No cambia lo ANCHA que es la sombra -la silueta siempre es la
// del bicho-, sino cuanto se tumba: una sombra menos aplastada se alarga mas.
// 256 la deja tan alta como el original.
#define SOMBRA_APLASTADO_S  120
#define SOMBRA_APLASTADO_M  150
#define SOMBRA_APLASTADO_L  190
#define SOMBRA_APLASTADO_XL 250

// Cuanto del fondo se deja pasar, de 0 a 16. Cuanto mas bajo, mas oscura queda
// la sombra: el duplicado es negro, asi que no aporta color y el resultado es
// simplemente el fondo atenuado en esta proporcion.
#define SOMBRA_MEZCLA_FONDO 10

// La sombra se coloca con el MISMO CENTRO que el Pokemon: encaja sobre el sprite
// original y desde ahi la estira e inclina la matriz afin.
//
// En el visor de sprites los dos numeros NO van a coincidir, y es correcto: la
// sombra usa caja doble (128x128) y el Pokemon caja normal (64x64). El hardware
// situa la caja por su esquina pero dibuja la textura centrada dentro, o sea en
// "esquina + mitad de la caja". Con los dos dibujos encajados, la esquina de la
// sombra sale 32 px por encima y a la izquierda. Igualar las esquinas es lo que
// descuadraria los dibujos, no al reves.
//
// Esa caja doble es la que impide que se recorte lo que sobresale al inclinarla.

// La cizalla pivota sobre el centro del sprite, asi que corre el pie hacia la
// izquierda tanto como corre la cabeza hacia la derecha. Esto lo devuelve a su
// sitio, midiendo desde el centro hasta la linea donde el Pokemon apoya: no es el
// borde de la caja, porque los sprites frontales dejan unos pixeles de aire
// debajo. Se deriva de la inclinacion para que no haya que reajustarlo a mano.
#define SOMBRA_LINEA_PIES  26
#define SOMBRA_CORRIMIENTO ((SOMBRA_INCLINACION * SOMBRA_LINEA_PIES) / 256)

// Cambia el aplastado de una sombra ya creada. Se puede llamar en cualquier
// momento: cada sombra tiene su propia matriz afin, asi que no se pisan entre
// ellas, y la especie puede cambiar en pleno combate (Transformacion).
void FijaAplastadoSombra(struct Sprite *sombra, u32 tamano);

void CargaGraficosSombraPokemon(void);
void PreparaMezclaSombraPokemon(void);
void TerminaMezclaSombraPokemon(void);

// Crea la sombra de un sprite ya existente. Devuelve MAX_SPRITES si no hay hueco
// de sprite, de matriz afin o de paleta. Nace invisible: cada sistema decide
// cuando mostrarla.
u8 CreaSombraPokemon(u8 spriteIdDueno, u8 subprioridad);

// Recoloca la sombra bajo su dueno y la mantiene apuntando a sus tiles actuales.
void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY);

void DestruyeSombraPokemon(u8 spriteIdSombra);

// Campos comunes del sprite de sombra. data[3] en adelante queda para quien la use.
#define sSombraDueno  data[0] // id del sprite o combatiente al que sigue
#define sSombraMatriz data[1] // matriz afin reservada, para poder soltarla
#define sSombraLibre  data[2] // sitio libre para el sistema que la use

#endif // GUARD_SOMBRA_POKEMON_H

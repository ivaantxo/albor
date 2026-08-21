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

// Grados de libertad de la sombra.
//
// Son los mismos tres numeros que se ajustan en la pagina de deformacion del visor
// de sprites, en las mismas unidades: porcentajes de lo que se ve. Lo que salga de
// experimentar alli se copia aqui tal cual.
//
//   ANCHO / ALTO  porcentaje del tamano original. 100 lo deja igual, 50 lo reduce
//                 a la mitad, y un valor negativo voltea la silueta en ese eje.
//   INCLINACION   cuanto se tumba, en porcentaje: 100 equivale a 45 grados, o sea
//                 que la parte de arriba se corre tanto como alta es la silueta.
#define SOMBRA_ANCHO       110
#define SOMBRA_ALTO         75
#define SOMBRA_INCLINACION  82

// Todas las sombras son del mismo tamano. Antes cada especie declaraba el suyo,
// pero como la silueta ya es la del propio Pokemon, la sombra sale proporcionada
// sola: un bicho grande proyecta una sombra grande sin que nadie se lo diga.
//
// Este numero se queda porque los tres de arriba se ajustaron con el puesto; sin
// el habria que reescribirlos y perderian precision al redondear.
#define SOMBRA_TAMANO 85

// Por debajo de esto en ancho o alto la silueta desaparece y la division estalla.
#define SOMBRA_ESCALA_MINIMA 10

// Cuanto del fondo se deja pasar, de 0 a 16. Cuanto mas bajo, mas oscura queda
// la sombra: el duplicado es negro, asi que no aporta color y el resultado es
// simplemente el fondo atenuado en esta proporcion.
//
// El 8 no es arbitrario. BLDALPHA es un unico registro para TODOS los objetos
// semitransparentes, asi que la sombra lo comparte con los sprites de las
// animaciones de combate, que lo fijan a su gusto. De los 294 setalpha de los
// guiones, 275 piden 8, asi que a 8 la inmensa mayoria de las animaciones dejan
// la sombra exactamente igual en vez de cambiarle la densidad a media pelea.
//
// De paso coincide con el overworld, que ya usaba BLDALPHA_BLEND(16, 8) para las
// sombras de los objetos del mapa: la misma densidad en el mapa y en combate.
#define SOMBRA_MEZCLA_FONDO 8

// Proporcion de la PRIMERA capa. A la sombra le da igual cual sea -es negra, y
// negro por cualquier coeficiente sigue siendo negro-, asi que se elige pensando
// en los demas: es la que piden 241 de los 294 setalpha de los guiones de
// animacion. Con ella, "setalpha 12, 8" no cambia nada y las animaciones que lo
// usan se encuentran los registros ya listos.
#define SOMBRA_MEZCLA_SOMBRA 12

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

// La deformacion pivota sobre el centro del sprite, asi que los pies se van de
// sitio: hacia el centro por el encogido y hacia un lado por la inclinacion. Esto
// mide desde el centro hasta la linea donde el Pokemon apoya, que no es el borde de
// la caja porque los sprites frontales dejan unos pixeles de aire debajo.
//
// La correccion que hace falta depende de la deformacion, asi que no es una
// constante: la calcula FijaDeformacionSombra y la deja en el propio sprite.
#define SOMBRA_LINEA_PIES  26

// Devuelve la sombra a la forma declarada arriba. Se puede llamar en cualquier
// momento: cada sombra tiene su propia matriz afin, asi que no se pisan entre ellas.
void FijaFormaSombra(struct Sprite *sombra);

// Cuanto agranda o encoge la sombra el tamano declarado por la especie, en tanto
// por ciento. Lo necesita el visor de sprites para descontarlo y poder mostrar los
// valores BASE, que son los que se copian a las constantes de arriba.
// Calcula la matriz de la sombra a partir de los cuatro valores de deformacion, en
// las mismas unidades que la pagina del visor de sprites. FijaFormaSombra no es mas
// que esta con las constantes de arriba, y el visor llama a esta directamente: hay
// un solo camino, asi que lo ajustado y lo compilado no pueden divergir.
void FijaDeformacionSombra(struct Sprite *sombra, s32 ancho, s32 alto, s32 inclinH, s32 inclinV);

void CargaGraficosSombraPokemon(void);

// Cierto solo si los registros de mezcla estan exactamente como los deja
// PreparaMezclaSombraPokemon. Sirve para que la sombra se aparte sola cuando
// alguien -una animacion, casi siempre- se adueña de la mezcla para otra cosa, y
// vuelva en cuanto se devuelvan al reposo.
bool32 MezclaSirveParaSombra(void);
void PreparaMezclaSombraPokemon(void);
void TerminaMezclaSombraPokemon(void);

// Crea la sombra de un sprite ya existente. Devuelve MAX_SPRITES si no hay hueco
// de sprite, de matriz afin o de paleta. Nace invisible: cada sistema decide
// cuando mostrarla.
u8 CreaSombraPokemon(u8 spriteIdDueno, u8 subprioridad);

// Recoloca la sombra bajo su dueno y la mantiene apuntando a sus tiles actuales.
void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY);

void DestruyeSombraPokemon(u8 spriteIdSombra);

// Reparto de data del sprite de sombra.
//
// De data[0] a data[3] son de ESTE modulo y no las puede tocar nadie mas. De
// data[4] en adelante son de quien use la sombra, y cada sistema las reparte como
// quiera: el combate guarda ahi la ultima especie vista y el visor de sprites sus
// desplazamientos manuales, que son sprites distintos y no coinciden nunca.
//
// Si al modulo le hiciera falta otro campo propio, va dentro de su rango, NUNCA
// ampliando hacia data[4]: eso pisaria en silencio los ajustes del visor.
#define sSombraDueno       data[0] // id del sprite o combatiente al que sigue
#define sSombraMatriz      data[1] // matriz afin reservada, para poder soltarla
#define sSombraCorreccionX data[2] // devuelve los pies a su sitio tras deformar
#define sSombraCorreccionY data[3]

// De aqui en adelante, de quien use la sombra. El combate usa esta:
#define sSombraEspecie data[4] // ultima especie valida vista, ver SpriteCB_EnemyShadow

#endif // GUARD_SOMBRA_POKEMON_H

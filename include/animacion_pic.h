#ifndef GUARD_ANIMACION_PIC_H
#define GUARD_ANIMACION_PIC_H

#include "metaprogram.h"
#include "sprite.h"

// Como se escribe la animacion de reposo de un Pokemon.
//
// Todas siguen la misma forma, sacada de como se mueven los de Blanco y Negro: un
// vaiven corto que se repite unos segundos y, de vez en cuando, un gesto que rompe la
// rutina y vuelve al vaiven. A mano salian cuarenta y tantas lineas por especie con
// el mismo numero repetido en todas; asi son tres.
//
//   static const union AnimCmd sAnim_Bulbasaur[] =
//   {
//       BUCLE_PRINCIPAL(0, 1, 0, 2, 0),
//       BUCLE_ESPECIAL(0, 3, 4),
//       VUELTA_AL_PRINCIPIO,
//   };
//
// Los numeros son POSES, no imagenes distintas: repetir una pose no cuesta memoria
// -el comando solo guarda un indice a la tabla de imagenes-, asi que ese Bulbasaur
// gasta cinco imagenes aunque el guion las nombre ocho veces. Lo que se paga son las
// imagenes distintas, y de ahi sale el reparto de cinco de frente y tres de espalda.
//
// El gesto especial repite a proposito la pose de reposo al empezar: es la frenada,
// el "va a pasar algo" antes de que pase.
//
// Que poses van en cada sitio se elige a mano y por especie. En Bulbasaur el vaiven
// da un saltito hacia delante, y el gesto reaprovecha esa misma pose para frenar en
// seco. Eso no se puede generalizar, y no se intenta.

// Lo que dura cada pose, en fotogramas de pantalla. Igual para todas las especies y
// para los dos lados: es lo que da el aire de BW, y tenerlo suelto por especie solo
// servia para que unas fueran mas rapidas que otras sin querer.
#define DURACION_POSE 20

// Cuanto se esta en el vaiven antes de hacer el gesto. Las repeticiones se calculan
// solas a partir de esto y de lo larga que sea la vuelta de cada especie, asi que una
// de cuatro poses y otra de seis tardan lo mismo en gesticular.
#define SEGUNDOS_DE_REPOSO 10

#define FOTOGRAMAS_POR_SEGUNDO 60

// Cuantas vueltas enteras caben en ese tiempo, y cuantas hay que pedirle al comando
// de bucle: repite el bloque count + 1 veces, asi que se le pide una menos. Un cero
// significa "pasa una sola vez", que es lo que sale si la vuelta ya dura mas que el
// tiempo pedido, y el comando lo admite sin mas.
#define VUELTAS_DE_REPOSO(poses) \
    ((SEGUNDOS_DE_REPOSO) * (FOTOGRAMAS_POR_SEGUNDO) / ((DURACION_POSE) * (poses)))

#define REPETICIONES_DE_REPOSO(poses) \
    (VUELTAS_DE_REPOSO(poses) > 1 ? VUELTAS_DE_REPOSO(poses) - 1 : 0)

// La coma va DELANTE de cada pose menos de la primera. Poniendola detras quedaba una
// coma suelta al final y el que escribiera la tabla no podia cerrar la linea con la
// suya, que es como se escriben todas las demas listas del juego.
#define POSE_SIGUIENTE_(indice) , ANIMCMD_FRAME(indice, DURACION_POSE)
#define POSES(primera, ...)                     \
    ANIMCMD_FRAME(primera, DURACION_POSE)       \
    __VA_OPT__(RECURSIVELY(R_FOR_EACH(POSE_SIGUIENTE_, __VA_ARGS__)))

// El vaiven, repetido hasta llenar SEGUNDOS_DE_REPOSO. Hasta dieciseis poses.
#define BUCLE_PRINCIPAL(...) \
    POSES(__VA_ARGS__), ANIMCMD_LOOP(REPETICIONES_DE_REPOSO(NARG_16(__VA_ARGS__)))

// El gesto, que pasa una sola vez por vuelta. No lleva salto: lo pone quien escribe
// la tabla, para que se vea donde acaba.
#define BUCLE_ESPECIAL(...) POSES(__VA_ARGS__)

#define VUELTA_AL_PRINCIPIO ANIMCMD_JUMP(0)

// Para las que tienen que PARAR en vez de dar vueltas. La entrada al combate espera a
// que se ponga animEnded, y con un salto eso no llega nunca.
#define TERMINA ANIMCMD_END

#endif // GUARD_ANIMACION_PIC_H

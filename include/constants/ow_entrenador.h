#ifndef GUARD_CONSTANTS_OW_ENTRENADOR_H
#define GUARD_CONSTANTS_OW_ENTRENADOR_H

// El reparto de la hoja de overworld de un entrenador.
//
// Una sola hoja de 32x32 por frame, en fila, con TODO lo que hace el personaje:
// andar, correr, bici y montura. Antes cada estado del jugador tenia su propia hoja
// -andando, bici, surf, cana, regadera- y su propia paleta; aqui hay una hoja y una
// paleta por persona, y el estado solo decide que animacion se pide.
//
// Solo existen las poses MIRANDO A LA IZQUIERDA. Las de mirar a la derecha son las
// mismas con el espejo horizontal que ya sabe hacer el OAM, asi que no ocupan arte.
//
// Estos numeros son el contrato con el dibujo: si se reordena la hoja, hay que
// reordenar esto, y no hay forma de que el compilador avise.

enum FrameOwEntrenador
{
    // Andando. La pose de parado es tambien la de hablar.
    OW_PARADO_SUR = 0,
    OW_PASO_SUR_IZQUIERDO,
    OW_PASO_SUR_DERECHO,
    OW_PARADO_NORTE,
    OW_PASO_NORTE_IZQUIERDO,
    OW_PASO_NORTE_DERECHO,
    OW_PARADO_LADO,
    OW_PASO_LADO_IZQUIERDO,
    OW_PASO_LADO_DERECHO,

    // Corriendo. El primero de cada terna NO es un parado: es el frame de
    // transicion, el que se ve un momento al frenar antes de volver al parado de
    // andar. Por eso no se usa como pose fija.
    OW_FRENADA_SUR,
    OW_CARRERA_SUR_IZQUIERDO,
    OW_CARRERA_SUR_DERECHO,
    OW_FRENADA_NORTE,
    OW_CARRERA_NORTE_IZQUIERDO,
    OW_CARRERA_NORTE_DERECHO,
    OW_FRENADA_LADO,
    OW_CARRERA_LADO_IZQUIERDO,
    OW_CARRERA_LADO_DERECHO,

    // Bici. A velocidad normal es UN solo dibujo por direccion, no un vaiven: la
    // pierna solo se mueve al acelerar, que es cuando entran los dos siguientes.
    OW_BICI_SUR,
    OW_BICI_RAPIDO_SUR_IZQUIERDO,
    OW_BICI_RAPIDO_SUR_DERECHO,
    OW_BICI_NORTE,
    OW_BICI_RAPIDO_NORTE_IZQUIERDO,
    OW_BICI_RAPIDO_NORTE_DERECHO,
    OW_BICI_LADO,
    OW_BICI_RAPIDO_LADO_IZQUIERDO,
    OW_BICI_RAPIDO_LADO_DERECHO,

    // Bici parada, que no es el mismo dibujo que la bici andando.
    OW_BICI_QUIETO_SUR,
    OW_BICI_QUIETO_NORTE,
    OW_BICI_QUIETO_LADO,

    // Montura. Hoy solo la usa el surf; la idea es que el personaje se dibuje
    // encima del Pokemon en posicion pero por DEBAJO en prioridad, para que el
    // Pokemon le tape. Ese sistema no existe todavia.
    OW_MONTURA_SUR,
    OW_MONTURA_NORTE,
    OW_MONTURA_LADO,

    OW_FRAMES_ENTRENADOR,
};

#endif // GUARD_CONSTANTS_OW_ENTRENADOR_H

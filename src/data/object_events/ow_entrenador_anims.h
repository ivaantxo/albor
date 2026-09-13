#include "constants/ow_entrenador.h"

// Animaciones del overworld de entrenador, sobre la hoja unica de 33 frames.
//
// El reparto y sus reglas estan en include/constants/ow_entrenador.h. Aqui solo se
// montan las secuencias, y hay tres cosas que las separan de las de vanilla:
//
//   1. Al andar hay dos pasos por direccion en vez de uno, pero el reposo se sigue
//      intercalando entre ellos como en el juego original: paso, reposo, otro paso,
//      reposo. Se probo sin el, alternando los dos pasos a secas, y el personaje
//      parece patinar: el reposo es el punto de apoyo que hace que el paso se lea.
//
//   2. Mirar a la derecha no gasta arte: son las mismas poses de lado con el espejo
//      horizontal del OAM.
//
//   3. La bici pedalea SIEMPRE que se mueve, y usa su dibujo de rodar como paso
//      intermedio, igual que andar usa el de reposo. Parada tiene dibujos propios:
//      no es el mismo que rodando. Parado en bici solo se esta antes de arrancar o
//      al chocar con algo que no se mueve.

// Una pose fija. El 16 es el mismo valor que usa vanilla: da igual, no cambia nunca.
#define POSE_OW(frame)                                  \
{                                                       \
    ANIMCMD_FRAME(frame, 16),                           \
    ANIMCMD_JUMP(0),                                    \
}

#define POSE_OW_ESPEJO(frame)                           \
{                                                       \
    ANIMCMD_FRAME(frame, 16, .hFlip = TRUE),            \
    ANIMCMD_JUMP(0),                                    \
}

// Un paso, el reposo, el otro paso, el reposo.
//
// El dibujo de reposo EN MEDIO no es relleno: es lo que hace que el paso se lea. Sin
// el, los dos pasos se alternan sin punto de apoyo y el personaje parece patinar. Asi
// es como anima el juego original, y se nota en cuanto se quita.
#define PASOS_OW(izquierdo, reposo, derecho, ticksPaso, ticksReposo) \
{                                                       \
    ANIMCMD_FRAME(izquierdo, ticksPaso),                \
    ANIMCMD_FRAME(reposo, ticksReposo),                 \
    ANIMCMD_FRAME(derecho, ticksPaso),                  \
    ANIMCMD_FRAME(reposo, ticksReposo),                 \
    ANIMCMD_JUMP(0),                                    \
}

#define PASOS_OW_ESPEJO(izquierdo, reposo, derecho, ticksPaso, ticksReposo) \
{                                                       \
    ANIMCMD_FRAME(izquierdo, ticksPaso, .hFlip = TRUE), \
    ANIMCMD_FRAME(reposo, ticksReposo, .hFlip = TRUE),  \
    ANIMCMD_FRAME(derecho, ticksPaso, .hFlip = TRUE),   \
    ANIMCMD_FRAME(reposo, ticksReposo, .hFlip = TRUE),  \
    ANIMCMD_JUMP(0),                                    \
}

// Dos dibujos alternos, sin nada en medio: para lo que no tiene pose de reposo que
// intercalar, como el pedaleo de la bici.
#define PASOS_DOS_OW(izquierdo, derecho, ticks)         \
{                                                       \
    ANIMCMD_FRAME(izquierdo, ticks),                    \
    ANIMCMD_FRAME(derecho, ticks),                      \
    ANIMCMD_JUMP(0),                                    \
}

#define PASOS_DOS_OW_ESPEJO(izquierdo, derecho, ticks)  \
{                                                       \
    ANIMCMD_FRAME(izquierdo, ticks, .hFlip = TRUE),     \
    ANIMCMD_FRAME(derecho, ticks, .hFlip = TRUE),       \
    ANIMCMD_JUMP(0),                                    \
}

// Los ritmos, de lento a rapido, como los de vanilla: cada escalon de velocidad del
// motor pide su propia animacion y se distinguen solo en la duracion.
#define TICKS_ANDANDO         8
#define TICKS_ANDANDO_RAPIDO  4
#define TICKS_ANDANDO_MAS     2
#define TICKS_ANDANDO_MAXIMO  1
#define TICKS_CORRIENDO       5

// --- Parado -----------------------------------------------------------------
static const union AnimCmd sAnimOw_ParadoSur[]   = POSE_OW(OW_PARADO_SUR);
static const union AnimCmd sAnimOw_ParadoNorte[] = POSE_OW(OW_PARADO_NORTE);
static const union AnimCmd sAnimOw_ParadoOeste[] = POSE_OW(OW_PARADO_LADO);
static const union AnimCmd sAnimOw_ParadoEste[]  = POSE_OW_ESPEJO(OW_PARADO_LADO);

// --- Andando, en sus cuatro velocidades --------------------------------------
#define ANDANDO_EN(sufijo, ticks)                                                     \
static const union AnimCmd sAnimOw_##sufijo##Sur[] = PASOS_OW(                        \
    OW_PASO_SUR_IZQUIERDO, OW_PARADO_SUR, OW_PASO_SUR_DERECHO, ticks, ticks);         \
static const union AnimCmd sAnimOw_##sufijo##Norte[] = PASOS_OW(                      \
    OW_PASO_NORTE_IZQUIERDO, OW_PARADO_NORTE, OW_PASO_NORTE_DERECHO, ticks, ticks);   \
static const union AnimCmd sAnimOw_##sufijo##Oeste[] = PASOS_OW(                      \
    OW_PASO_LADO_IZQUIERDO, OW_PARADO_LADO, OW_PASO_LADO_DERECHO, ticks, ticks);      \
static const union AnimCmd sAnimOw_##sufijo##Este[] = PASOS_OW_ESPEJO(                \
    OW_PASO_LADO_IZQUIERDO, OW_PARADO_LADO, OW_PASO_LADO_DERECHO, ticks, ticks)

ANDANDO_EN(Anda,       TICKS_ANDANDO);
ANDANDO_EN(AndaRapido, TICKS_ANDANDO_RAPIDO);
ANDANDO_EN(AndaMas,    TICKS_ANDANDO_MAS);
ANDANDO_EN(AndaMaximo, TICKS_ANDANDO_MAXIMO);

// --- Corriendo ---------------------------------------------------------------
// Corriendo va SIN dibujo intermedio, al reves que andar. El original si lo pone, y
// usa para ello el mismo frame que tu reservas para la frenada -el 9, 12 y 15-. Aqui
// no se hace porque tu reparto dice que esos son la transicion al frenar, y una pose
// de frenada repetida en mitad de la carrera se veria mal. Si tu frame de frenada es
// una pose neutra de carrera, esto se cambia en una linea.
static const union AnimCmd sAnimOw_CorreSur[] = PASOS_DOS_OW(
    OW_CARRERA_SUR_IZQUIERDO, OW_CARRERA_SUR_DERECHO, TICKS_CORRIENDO);
static const union AnimCmd sAnimOw_CorreNorte[] = PASOS_DOS_OW(
    OW_CARRERA_NORTE_IZQUIERDO, OW_CARRERA_NORTE_DERECHO, TICKS_CORRIENDO);
static const union AnimCmd sAnimOw_CorreOeste[] = PASOS_DOS_OW(
    OW_CARRERA_LADO_IZQUIERDO, OW_CARRERA_LADO_DERECHO, TICKS_CORRIENDO);
static const union AnimCmd sAnimOw_CorreEste[] = PASOS_DOS_OW_ESPEJO(
    OW_CARRERA_LADO_IZQUIERDO, OW_CARRERA_LADO_DERECHO, TICKS_CORRIENDO);

// La frenada: se ve un momento al dejar de correr y vuelve al parado de andar. No da
// vueltas, TERMINA, porque quien la lanza espera a que acabe para devolver el control.
#define FRENADA_OW(frame)                               \
{                                                       \
    ANIMCMD_FRAME(frame, 6),                            \
    ANIMCMD_END,                                        \
}

#define FRENADA_OW_ESPEJO(frame)                        \
{                                                       \
    ANIMCMD_FRAME(frame, 6, .hFlip = TRUE),             \
    ANIMCMD_END,                                        \
}

static const union AnimCmd sAnimOw_FrenaSur[]   = FRENADA_OW(OW_FRENADA_SUR);
static const union AnimCmd sAnimOw_FrenaNorte[] = FRENADA_OW(OW_FRENADA_NORTE);
static const union AnimCmd sAnimOw_FrenaOeste[] = FRENADA_OW(OW_FRENADA_LADO);
static const union AnimCmd sAnimOw_FrenaEste[]  = FRENADA_OW_ESPEJO(OW_FRENADA_LADO);

// --- Bici --------------------------------------------------------------------
// Parada: su propio dibujo, que no es el de rodar.
static const union AnimCmd sAnimOw_BiciQuietoSur[]   = POSE_OW(OW_BICI_QUIETO_SUR);
static const union AnimCmd sAnimOw_BiciQuietoNorte[] = POSE_OW(OW_BICI_QUIETO_NORTE);
static const union AnimCmd sAnimOw_BiciQuietoOeste[] = POSE_OW(OW_BICI_QUIETO_LADO);
static const union AnimCmd sAnimOw_BiciQuietoEste[]  = POSE_OW_ESPEJO(OW_BICI_QUIETO_LADO);

// Rodando, a cualquier velocidad: pedalada, dibujo de rodar, la otra pedalada, y
// otra vez el de rodar. El de rodar hace de intermedio igual que el reposo al andar,
// que si no las dos piernas se alternan sin punto medio y da el mismo efecto de
// patinaje. Y de paso ese dibujo deja de estar sin usar: la bici NUNCA se mueve a
// velocidad normal -su base ya es la de correr-, asi que como pose suelta no la
// pedia nadie.
#define BICI_EN(sufijo, ticks)                                                        \
static const union AnimCmd sAnimOw_##sufijo##Sur[] = PASOS_OW(                        \
    OW_BICI_RAPIDO_SUR_IZQUIERDO, OW_BICI_SUR,                                        \
    OW_BICI_RAPIDO_SUR_DERECHO, ticks, ticks);                                        \
static const union AnimCmd sAnimOw_##sufijo##Norte[] = PASOS_OW(                      \
    OW_BICI_RAPIDO_NORTE_IZQUIERDO, OW_BICI_NORTE,                                    \
    OW_BICI_RAPIDO_NORTE_DERECHO, ticks, ticks);                                      \
static const union AnimCmd sAnimOw_##sufijo##Oeste[] = PASOS_OW(                      \
    OW_BICI_RAPIDO_LADO_IZQUIERDO, OW_BICI_LADO,                                      \
    OW_BICI_RAPIDO_LADO_DERECHO, ticks, ticks);                                       \
static const union AnimCmd sAnimOw_##sufijo##Este[] = PASOS_OW_ESPEJO(                \
    OW_BICI_RAPIDO_LADO_IZQUIERDO, OW_BICI_LADO,                                      \
    OW_BICI_RAPIDO_LADO_DERECHO, ticks, ticks)

BICI_EN(Bici,        TICKS_ANDANDO);
BICI_EN(BiciRapida,  TICKS_ANDANDO_RAPIDO);
BICI_EN(BiciMas,     TICKS_ANDANDO_MAS);
BICI_EN(BiciMaximo,  TICKS_ANDANDO_MAXIMO);

// --- Montura -----------------------------------------------------------------
// Sin sistema todavia: ver la nota del enum. Se dejan montadas para que el arte no
// quede huerfano y para que el dia que exista solo haya que pedirlas.
static const union AnimCmd sAnimOw_MonturaSur[]   = POSE_OW(OW_MONTURA_SUR);
static const union AnimCmd sAnimOw_MonturaNorte[] = POSE_OW(OW_MONTURA_NORTE);
static const union AnimCmd sAnimOw_MonturaOeste[] = POSE_OW(OW_MONTURA_LADO);
static const union AnimCmd sAnimOw_MonturaEste[]  = POSE_OW_ESPEJO(OW_MONTURA_LADO);

// --- Las tablas --------------------------------------------------------------
//
// Andar y correr comparten tabla; la bici tiene la suya. Los indices los elige el
// motor -ANIM_STD_*-, asi que hay que rellenarlos todos: un hueco a NULL es un salto
// a la nada en cuanto el jugador mire hacia ese lado.
static const union AnimCmd *const sAnimTable_EntrenadorAPie[] = {
    [ANIM_STD_FACE_SOUTH]       = sAnimOw_ParadoSur,
    [ANIM_STD_FACE_NORTH]       = sAnimOw_ParadoNorte,
    [ANIM_STD_FACE_WEST]        = sAnimOw_ParadoOeste,
    [ANIM_STD_FACE_EAST]        = sAnimOw_ParadoEste,
    [ANIM_STD_GO_SOUTH]         = sAnimOw_AndaSur,
    [ANIM_STD_GO_NORTH]         = sAnimOw_AndaNorte,
    [ANIM_STD_GO_WEST]          = sAnimOw_AndaOeste,
    [ANIM_STD_GO_EAST]          = sAnimOw_AndaEste,
    [ANIM_STD_GO_FAST_SOUTH]    = sAnimOw_AndaRapidoSur,
    [ANIM_STD_GO_FAST_NORTH]    = sAnimOw_AndaRapidoNorte,
    [ANIM_STD_GO_FAST_WEST]     = sAnimOw_AndaRapidoOeste,
    [ANIM_STD_GO_FAST_EAST]     = sAnimOw_AndaRapidoEste,
    [ANIM_STD_GO_FASTER_SOUTH]  = sAnimOw_AndaMasSur,
    [ANIM_STD_GO_FASTER_NORTH]  = sAnimOw_AndaMasNorte,
    [ANIM_STD_GO_FASTER_WEST]   = sAnimOw_AndaMasOeste,
    [ANIM_STD_GO_FASTER_EAST]   = sAnimOw_AndaMasEste,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnimOw_AndaMaximoSur,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnimOw_AndaMaximoNorte,
    [ANIM_STD_GO_FASTEST_WEST]  = sAnimOw_AndaMaximoOeste,
    [ANIM_STD_GO_FASTEST_EAST]  = sAnimOw_AndaMaximoEste,
    [ANIM_RUN_SOUTH]            = sAnimOw_CorreSur,
    [ANIM_RUN_NORTH]            = sAnimOw_CorreNorte,
    [ANIM_RUN_WEST]             = sAnimOw_CorreOeste,
    [ANIM_RUN_EAST]             = sAnimOw_CorreEste,
    [ANIM_FRENADA_SOUTH]        = sAnimOw_FrenaSur,
    [ANIM_FRENADA_NORTH]        = sAnimOw_FrenaNorte,
    [ANIM_FRENADA_WEST]         = sAnimOw_FrenaOeste,
    [ANIM_FRENADA_EAST]         = sAnimOw_FrenaEste,
    [ANIM_MONTURA_SOUTH]        = sAnimOw_MonturaSur,
    [ANIM_MONTURA_NORTH]        = sAnimOw_MonturaNorte,
    [ANIM_MONTURA_WEST]         = sAnimOw_MonturaOeste,
    [ANIM_MONTURA_EAST]         = sAnimOw_MonturaEste,
};

// La bici. Parado NO es la pose de a pie: tiene dibujo propio.
static const union AnimCmd *const sAnimTable_EntrenadorEnBici[] = {
    [ANIM_STD_FACE_SOUTH]       = sAnimOw_BiciQuietoSur,
    [ANIM_STD_FACE_NORTH]       = sAnimOw_BiciQuietoNorte,
    [ANIM_STD_FACE_WEST]        = sAnimOw_BiciQuietoOeste,
    [ANIM_STD_FACE_EAST]        = sAnimOw_BiciQuietoEste,
    [ANIM_STD_GO_SOUTH]         = sAnimOw_BiciSur,
    [ANIM_STD_GO_NORTH]         = sAnimOw_BiciNorte,
    [ANIM_STD_GO_WEST]          = sAnimOw_BiciOeste,
    [ANIM_STD_GO_EAST]          = sAnimOw_BiciEste,
    [ANIM_STD_GO_FAST_SOUTH]    = sAnimOw_BiciRapidaSur,
    [ANIM_STD_GO_FAST_NORTH]    = sAnimOw_BiciRapidaNorte,
    [ANIM_STD_GO_FAST_WEST]     = sAnimOw_BiciRapidaOeste,
    [ANIM_STD_GO_FAST_EAST]     = sAnimOw_BiciRapidaEste,
    [ANIM_STD_GO_FASTER_SOUTH]  = sAnimOw_BiciMasSur,
    [ANIM_STD_GO_FASTER_NORTH]  = sAnimOw_BiciMasNorte,
    [ANIM_STD_GO_FASTER_WEST]   = sAnimOw_BiciMasOeste,
    [ANIM_STD_GO_FASTER_EAST]   = sAnimOw_BiciMasEste,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnimOw_BiciMaximoSur,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnimOw_BiciMaximoNorte,
    [ANIM_STD_GO_FASTEST_WEST]  = sAnimOw_BiciMaximoOeste,
    [ANIM_STD_GO_FASTEST_EAST]  = sAnimOw_BiciMaximoEste,
};

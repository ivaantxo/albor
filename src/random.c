#include "global.h"
#include "random.h"
#include "main.h"
#include <alloca.h>

// IWRAM common
COMMON_DATA rng_value_t gRngValue = {0};

EWRAM_DATA static volatile bool8 sRngLoopUnlocked;

#define STREAM 1

// A variant of SFC32 that lets you change the stream.
// stream can be any odd number.
static inline u32 _SFC32_Next_Stream(struct Sfc32State *state, const u8 stream)
{
    const u32 result = state->a + state->b + state->ctr;
    state->ctr += stream;
    state->a = state->b ^ (state->b >> 9);
    state->b = state->c * 9;
    state->c = result + ((state->c << 21) | (state->c >> 11));
    return result;
}

static void SFC32_Seed(struct Sfc32State *state, u32 seed, u8 stream)
{
    u32 i;
    state->a = state->b = 0;
    state->c = seed;
    state->ctr = stream;
    for(i = 0; i < 16; i++)
    {
        _SFC32_Next_Stream(state, stream);
    }
}

/*This ASM implementation uses some shortcuts and is generally faster on the GBA.
* It's not necessarily faster if inlined, or on other platforms.
* In addition, it's extremely non-portable. */
u32 NAKED Random32(void)
{
    asm(".thumb\n\
    push {r4, r5, r6}\n\
    mov r6, #11\n\
    ldr r5, =gRngValue\n\
    ldmia r5!, {r1, r2, r3, r4}\n\
    @ result = a + b + (d+=STREAM)\n\
    add r1, r1, r2\n\
    add r0, r1, r4\n\
    add r4, r4, #" STR(STREAM) "\n\
    @ a = b ^ (b >> 9)\n\
    lsr r1, r2, #9\n\
    eor r1, r1, r2\n\
    @ b = c + (c << 3) [c * 9]\n\
    lsl r2, r3, #3\n\
    add r2, r2, r3\n\
    @ c = rol(c, 21) + result\n\
    ror r3, r3, r6\n\
    add r3, r3, r0\n\
    sub r5, r5, #16\n\
    stmia r5!, {r1, r2, r3, r4}\n\
    pop {r4, r5, r6}\n\
    bx lr\n\
    .ltorg"
    );
}

// De donde sale el azar al encender, y por que de ahi.
//
// La GBA no tiene nada aleatorio al arrancar: el mismo cartucho encendido dos veces
// ejecuta exactamente las mismas instrucciones. Y en albor tampoco hay reloj de
// hardware al que preguntar la hora -Rtc_GetCurrentTime devuelve gameClock, que es un
// reloj de software guardado en la partida-, asi que ese camino tampoco vale.
//
// Lo unico de verdad impredecible es LA PERSONA. Cuanto tarda en pulsar el boton que
// empieza a jugar no se repite nunca dos veces igual, y eso es lo que mide
// gMain.vblankCounter: fotogramas desde que se encendio. Un segundo de diferencia son
// sesenta valores distintos, y nadie acierta el fotograma exacto.
//
// Lo que habia antes leia dos palabras del monton, buscando la basura que quedara en
// la RAM. Eso es peligroso por dos motivos: es memoria que el repartidor ya ha
// entregado a otro, y desde que el monton ocupa lo que sobra de EWRAM su direccion se
// mueve con cada cambio de datos. Ademas casi no daba azar: cuando esto corre, esas
// dos palabras son la cabecera del primer bloque libre, que vale siempre lo mismo.
void GeneraSemillaAleatoria(void)
{
    struct Sfc32State state;

    // Los fotogramas que el jugador ha tardado en llegar hasta aqui. Se mezclan con
    // una multiplicacion para que los bits altos, que es donde esta la cuenta, muevan
    // tambien los bajos: sin eso dos arranques parecidos dan semillas parecidas.
    u32 semilla = gMain.vblankCounter * 1103515245 + 12345;

    // En que punto del barrido de pantalla cayo la llamada, y el temporizador si
    // alguien lo tiene corriendo. Aportan poco por si solos, pero no cuestan nada.
    semilla ^= (REG_VCOUNT << 16) ^ REG_TM0CNT_L;

    // Que teclas trae pulsadas en ese momento, incluidas las que no hacen nada.
    semilla ^= REG_KEYINPUT << 6;

    SFC32_Seed(&state, semilla, STREAM);

    sRngLoopUnlocked = FALSE;
    gRngValue = state;
    sRngLoopUnlocked = TRUE;
}

void AvanzaAleatoriedad(void)
{
    if (sRngLoopUnlocked == TRUE)
        Random();
}

bool32 PorcentajeAleatorio(u32 porcentaje)
{
    return (Random() % 100) < porcentaje;
}

u32 ElementoAleatorio(u32 numeroElementos)
{
    return Random() % numeroElementos;
}

u32 NumeroAleatorioEnRango(u32 minimo, u32 maximo)
{
    return minimo + (Random() % (maximo - minimo + 1));
}

u32 ElementoAleatorioPonderado(const u8 *pesos, u32 numElementos)
{
    u32 suma = 0;

    // Sumar todos los pesos
    for (u32 i = 0; i < numElementos; i++)
        suma += pesos[i];

    // Si todos los pesos son 0 → devolver un valor por defecto
    if (suma == 0)
        return 0;

    // Elegir un valor aleatorio entre 0 y suma-1
    u32 r = NumeroAleatorioEnRango(0, suma - 1);

    // Buscar qué índice corresponde
    u32 acumulado = 0;
    for (u32 i = 0; i < numElementos; i++)
    {
        acumulado += pesos[i];
        if (r < acumulado)
            return i;
    }

    // Failsafe
    return numElementos - 1;
}

#include "global.h"
#include "random.h"
#include "malloc.h"
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

void GeneraSemillaAleatoria(void)
{
    struct Sfc32State state;
    u32 semilla = 0;

    // Línea de escaneo del haz vertical (0–159, se reinicia cada frame)
    semilla ^= REG_VCOUNT << 8;

    // Timer 0 (si está corriendo) — útil si lo usas para temporización
    semilla ^= REG_TM0CNT_L ^ (REG_TM0CNT_H << 16);

    // Entrada del jugador — por si pulsa algún botón
    semilla ^= REG_KEYINPUT;

    // Dirección actual del stack pointer
    register u32 sp;
    __asm__("mov %0, sp" : "=r"(sp));
    semilla ^= sp;

    semilla ^= *(vu32*)(gHeap + 16);
    semilla ^= *(vu32*)(gHeap + 64);

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

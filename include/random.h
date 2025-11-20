#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE(val) (1103515245 * (val) + 12345)

struct Sfc32State {
    u32 a;
    u32 b;
    u32 c;
    u32 ctr;
};

typedef struct Sfc32State rng_value_t;

static inline u32 _SFC32_Next(struct Sfc32State *state)
{
    const u32 result = state->a + state->b + state->ctr++;
    state->a = state->b ^ (state->b >> 9);
    state->b = state->c * 9;
    state->c = result + ((state->c << 21) | (state->c >> 11));
    return result;
}

u32 Random32(void);

static inline u32 Random(void)
{
    return Random32();
}

void GeneraSemillaAleatoria(void);

void AvanzaAleatoriedad(void);

extern rng_value_t gRngValue;

bool32 PorcentajeAleatorio(u32 porcentaje);         //  Devuelve TRUE el porcentaje dado.
u32 ElementoAleatorio(u32 numeroElementos);         //  Random() % número de elementos.
u32 NumeroAleatorioEnRango(u32 minimo, u32 maximo); //  Da un número aleatorio con un rango desde mínimo a máximo.
u32 ElementoAleatorioPonderado(const u8 *pesos, u32 numElementos);

#endif // GUARD_RANDOM_H

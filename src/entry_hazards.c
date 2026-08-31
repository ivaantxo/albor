#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"

// Trampas de entrada.
//
// Cada trampa es un u16 en el que solo cuentan los bits 0 y 1, uno por lado del
// campo. No hay capas ni contadores: una trampa esta puesta o no lo esta, y su
// dano depende solo de lo debil que sea al tipo quien la pisa.
EWRAM_DATA struct TrampasEntrada gTrampasEntrada = {0};
EWRAM_DATA u16 gTrampaEntradaActiva = 0;

// Una trampa por tipo, y el tipo es lo unico que hace falta para saber cual es.
static const u8 sTiposTrampas[NUMERO_TRAMPAS_ENTRADA] =
{
    [TRAMPA_BRASAS]            = TIPO_FUEGO,
    [TRAMPA_ESPINAS]           = TIPO_PLANTA,
    [TRAMPA_PUAS_TOXICAS]      = TIPO_VENENO,
    [TRAMPA_ROCAS_PUNTIAGUDAS] = TIPO_ROCA,
    [TRAMPA_PUAS]              = TIPO_ACERO,
    [TRAMPA_PENITENTES]        = TIPO_HIELO,
    [TRAMPA_RED_VISCOSA]       = TIPO_BICHO,
    [TRAMPA_ENREDADERAS]       = TIPO_PLANTA,
};

static u16 *EstadoTrampaEntrada(u32 trampa)
{
    switch (trampa)
    {
    case TRAMPA_BRASAS:            return &gTrampasEntrada.brasas;
    case TRAMPA_ESPINAS:           return &gTrampasEntrada.espinas;
    case TRAMPA_PUAS_TOXICAS:      return &gTrampasEntrada.puasToxicas;
    case TRAMPA_ROCAS_PUNTIAGUDAS: return &gTrampasEntrada.rocasPuntiagudas;
    case TRAMPA_PUAS:              return &gTrampasEntrada.puas;
    case TRAMPA_PENITENTES:        return &gTrampasEntrada.penitentes;
    case TRAMPA_RED_VISCOSA:       return &gTrampasEntrada.redViscosa;
    case TRAMPA_ENREDADERAS:       return &gTrampasEntrada.enredaderas;
    default:                       return NULL;
    }
}

bool32 HayTrampaEntrada(u32 trampa, u32 lado)
{
    u16 *estado = EstadoTrampaEntrada(trampa);

    return estado != NULL && (*estado & (1u << lado));
}

bool32 HayAlgunaTrampaEntrada(u32 lado)
{
    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_ENTRADA; trampa++)
    {
        if (HayTrampaEntrada(trampa, lado))
            return TRUE;
    }
    return FALSE;
}

bool32 HayAlgunaTrampaDanio(u32 lado)
{
    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_DANIO; trampa++)
    {
        if (HayTrampaEntrada(trampa, lado))
            return TRUE;
    }
    return FALSE;
}

bool32 ColocaTrampaEntrada(u32 trampa, u32 lado)
{
    u16 *estado = EstadoTrampaEntrada(trampa);

    if (estado == NULL || (*estado & (1u << lado)))
        return FALSE;   // ya estaba puesta: el movimiento falla

    *estado |= 1u << lado;
    return TRUE;
}

void QuitaTrampaEntrada(u32 trampa, u32 lado)
{
    u16 *estado = EstadoTrampaEntrada(trampa);

    if (estado != NULL)
        *estado &= ~(1u << lado);
}

void QuitaTodasTrampasEntrada(u32 lado)
{
    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_ENTRADA; trampa++)
        QuitaTrampaEntrada(trampa, lado);
}

void ReiniciaTrampasEntrada(void)
{
    memset(&gTrampasEntrada, 0, sizeof(gTrampasEntrada));
    gTrampaEntradaActiva = TRAMPA_ENTRADA_NINGUNA;
}

u32 TipoTrampaEntrada(u32 trampa)
{
    if (trampa < NUMERO_TRAMPAS_ENTRADA)
        return sTiposTrampas[trampa];
    return NUMERO_TIPOS;
}

u32 TrampaEntradaPorTipo(u32 tipo)
{
    // Solo las de dano: hay dos trampas de tipo Planta -Espinas y Enredaderas- y
    // la que se coloca por tipo de movimiento es siempre la que hace dano.
    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_DANIO; trampa++)
    {
        if (sTiposTrampas[trampa] == tipo)
            return trampa;
    }
    return TRAMPA_ENTRADA_NINGUNA;
}

enum Movimientos MovimientoTrampaEntrada(u32 trampa)
{
    static const enum Movimientos sMovimientosTrampas[NUMERO_TRAMPAS_ENTRADA] =
    {
        [TRAMPA_BRASAS]            = MOVE_BRASAS,
        [TRAMPA_ESPINAS]           = MOVE_ESPINAS,
        [TRAMPA_PUAS_TOXICAS]      = MOVE_TOXIC_SPIKES,
        [TRAMPA_ROCAS_PUNTIAGUDAS] = MOVE_STEALTH_ROCK,
        [TRAMPA_PUAS]              = MOVE_SPIKES,
        [TRAMPA_PENITENTES]        = MOVE_PENITENTES,
        [TRAMPA_RED_VISCOSA]       = MOVE_STICKY_WEB,
        [TRAMPA_ENREDADERAS]       = MOVE_ENREDADERAS,
    };

    if (trampa < NUMERO_TRAMPAS_ENTRADA)
        return sMovimientosTrampas[trampa];
    return MOVE_NONE;
}

// Quien no pisa el suelo no pisa la trampa, y las botas valen contra todas.
//
// A proposito NO libran ni Velo Sagrado, ni Muro Magico, ni ningun otro estado:
// aqui las botas son la unica prenda que sirve.
bool32 EsInmuneATrampas(u32 combatiente)
{
    if (GetBattlerHoldEffect(combatiente, TRUE) == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
        return TRUE;

    return !EstaCombatienteEnSuelo(combatiente);
}

// Un Pokemon del mismo tipo que la trampa se la lleva puesta al entrar: la
// absorbe y el lado se queda limpio de esa.
u32 AbsorbeTrampasPorTipo(u32 lado, u32 tipo1, u32 tipo2)
{
    u32 absorbidas = 0;

    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_DANIO; trampa++)
    {
        u32 tipoTrampa = sTiposTrampas[trampa];

        if (HayTrampaEntrada(trampa, lado) && (tipo1 == tipoTrampa || tipo2 == tipoTrampa))
        {
            QuitaTrampaEntrada(trampa, lado);
            absorbidas++;
        }
    }
    return absorbidas;
}

u32 CuentaTrampasAbsorbibles(u32 lado, u32 tipo1, u32 tipo2)
{
    u32 cantidad = 0;

    for (u32 trampa = 0; trampa < NUMERO_TRAMPAS_DANIO; trampa++)
    {
        u32 tipoTrampa = sTiposTrampas[trampa];

        if (HayTrampaEntrada(trampa, lado) && (tipo1 == tipoTrampa || tipo2 == tipoTrampa))
            cantidad++;
    }
    return cantidad;
}

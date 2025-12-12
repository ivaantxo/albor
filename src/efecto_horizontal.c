#include "global.h"
#include "battle.h"
#include "data.h"
#include "task.h"
#include "trig.h"
#include "efecto_horizontal.h"

static void CopiaValor16Bits(void);
static void CopiaValor32Bits(void);

EWRAM_DATA u16 ALIGNED(4) gRegistrosBuffersEfectoHorizontal[NUMERO_BUFFERS_EFECTO_HORIZONTAL][ANCHO_PANTALLA * EFECTOS_POR_LINEA_HORIZONTAL] = {0};
EWRAM_DATA struct EfectoHorizontal gEfectoHorizontal = {0};
EWRAM_DATA static bool32 sDeberiaPararOnda = FALSE;

void ParaEfectoHorizontal(void)
{
    gEfectoHorizontal.estado = ESTADO_EFECTO_HORIZONTAL_INACTIVO;
    DmaStop(0);
    if (gEfectoHorizontal.tareaOnda != TASK_NONE)
    {
        DestroyTask(gEfectoHorizontal.tareaOnda);
        gEfectoHorizontal.tareaOnda = TASK_NONE;
    }
}

void LimpiaEfectoHorizontal(void)
{
    CpuFill16(0, gRegistrosBuffersEfectoHorizontal, sizeof(gRegistrosBuffersEfectoHorizontal));
    gEfectoHorizontal.dmaSrcBuffers[0] = NULL;
    gEfectoHorizontal.dmaSrcBuffers[1] = NULL;
    gEfectoHorizontal.dmaDest = NULL;
    gEfectoHorizontal.bitsDMA = 0;
    gEfectoHorizontal.srcBuffer = 0;
    gEfectoHorizontal.estado = ESTADO_EFECTO_HORIZONTAL_INACTIVO;
    gEfectoHorizontal.tareaOnda = TASK_NONE;
}

void EscribeParametrosEfectoHorizontal(struct ParametrosEfectoHorizontal parametros)
{
    // Escribe por DMA el valor de la segunda línea horizontal porque
    // el primer DMA ocurre en el hblank después de dibujar la primera línea.
    if (parametros.bitsDMA == EFECTO_HORIZONTAL_DMA_16)
    {
        gEfectoHorizontal.dmaSrcBuffers[0] = (u16 *)gRegistrosBuffersEfectoHorizontal[0] + 1;
        gEfectoHorizontal.dmaSrcBuffers[1] = (u16 *)gRegistrosBuffersEfectoHorizontal[1] + 1;
        gEfectoHorizontal.escribeRegistroPrimeraLinea = CopiaValor16Bits;
    }
    else // EFECTO_HORIZONTAL_DMA_32
    {
        gEfectoHorizontal.dmaSrcBuffers[0] = (u32 *)gRegistrosBuffersEfectoHorizontal[0] + 1;
        gEfectoHorizontal.dmaSrcBuffers[1] = (u32 *)gRegistrosBuffersEfectoHorizontal[1] + 1;
        gEfectoHorizontal.escribeRegistroPrimeraLinea = CopiaValor32Bits;
    }
    gEfectoHorizontal.bitsDMA   = parametros.bitsDMA;
    gEfectoHorizontal.dmaDest   = parametros.dmaDest;
    gEfectoHorizontal.estado    = parametros.estado;
}

void IniciaTransferenciaDMAEnHblankEfectoHorizontal(void)
{
    if (gEfectoHorizontal.estado == ESTADO_EFECTO_HORIZONTAL_INACTIVO)
    {
        return;
    }
    else if (gEfectoHorizontal.estado == ESTADO_EFECTO_HORIZONTAL_PARAR)
    {
        gEfectoHorizontal.estado = ESTADO_EFECTO_HORIZONTAL_INACTIVO;
        DmaStop(0);
        sDeberiaPararOnda = TRUE;
    }
    else // ESTADO_EFECTO_HORIZONTAL_ACTIVO
    {
        DmaStop(0);
        // Prepara DMA para copiar el registro en cada HBlank durante el siguiente frame.
        // La transferencia no ocurre durante el VBlank, así que empieza tras pintar (en el HBlank) el primer frame.
        DmaSet(0, gEfectoHorizontal.dmaSrcBuffers[gEfectoHorizontal.srcBuffer], gEfectoHorizontal.dmaDest, gEfectoHorizontal.bitsDMA);
        // Escribe el valor del registro para la línea 0
        gEfectoHorizontal.escribeRegistroPrimeraLinea();
        // Alterna entre los dos buffers para evitar tearing
        gEfectoHorizontal.srcBuffer ^= 1;
    }
}

static void CopiaValor16Bits(void)
{
    vu16 *dest = (vu16 *)gEfectoHorizontal.dmaDest;
    vu16 *src = (vu16 *)&gRegistrosBuffersEfectoHorizontal[gEfectoHorizontal.srcBuffer];

    *dest = *src;
}

static void CopiaValor32Bits(void)
{
    vu32 *dest = (vu32 *)gEfectoHorizontal.dmaDest;
    vu32 *src = (vu32 *)&gRegistrosBuffersEfectoHorizontal[gEfectoHorizontal.srcBuffer];

    *dest = *src;
}

#define tLineaInicial                   data[0]
#define tLineaFinal                     data[1]
#define tDuracionOnda                   data[2]
#define tPosicionBuffer                data[3]
#define tFramesHastaMovimiento          data[4]
#define tRegistroPosicion               data[5]
#define tAplicaPosicionFondosBatalla    data[6]

static void Tarea_ActualizaOndaPorFrame(u8 taskId)
{
    u32 value = 0;
    u32 i;
    u32 offset;

    if (sDeberiaPararOnda)
    {
        DestroyTask(taskId);
        gEfectoHorizontal.tareaOnda = TASK_NONE;
    }
    else
    {
        if (gTasks[taskId].tAplicaPosicionFondosBatalla)
        {
            switch (gTasks[taskId].tRegistroPosicion)
            {
            case EFECTO_HORIZONTAL_BG_0_HORIZONTAL:
                value = gBattle_BG0_X;
                break;
            case EFECTO_HORIZONTAL_BG_0_VERTICAL:
                value = gBattle_BG0_Y;
                break;
            case EFECTO_HORIZONTAL_BG_1_HORIZONTAL:
                value = gBattle_BG1_X;
                break;
            case EFECTO_HORIZONTAL_BG_1_VERTICAL:
                value = gBattle_BG1_Y;
                break;
            case EFECTO_HORIZONTAL_BG_2_HORIZONTAL:
                value = gBattle_BG2_X;
                break;
            case EFECTO_HORIZONTAL_BG_2_VERTICAL:
                value = gBattle_BG2_Y;
                break;
            case EFECTO_HORIZONTAL_BG_3_HORIZONTAL:
                value = gBattle_BG3_X;
                break;
            case EFECTO_HORIZONTAL_BG_3_VERTICAL:
                value = gBattle_BG3_Y;
                break;
            }
        }
        if (gTasks[taskId].tFramesHastaMovimiento != 0)
        {
            gTasks[taskId].tFramesHastaMovimiento--;
            offset = gTasks[taskId].tPosicionBuffer + 320;
            for (i = gTasks[taskId].tLineaInicial; i < gTasks[taskId].tLineaFinal; i++)
            {
                gRegistrosBuffersEfectoHorizontal[gEfectoHorizontal.srcBuffer][i] = gRegistrosBuffersEfectoHorizontal[0][offset] + value;
                offset++;
            }
        }
        else
        {
            offset = gTasks[taskId].tPosicionBuffer + 320;
            for (i = gTasks[taskId].tLineaInicial; i < gTasks[taskId].tLineaFinal; i++)
            {
                gRegistrosBuffersEfectoHorizontal[gEfectoHorizontal.srcBuffer][i] = gRegistrosBuffersEfectoHorizontal[0][offset] + value;
                offset++;
            }

            // increment src buffer offset
            gTasks[taskId].tPosicionBuffer++;
            if (gTasks[taskId].tPosicionBuffer == gTasks[taskId].tDuracionOnda)
                gTasks[taskId].tPosicionBuffer = 0;
        }
    }
}

static void GeneraOnda(u16 *buffer, u32 frecuencia, u32 amplitud)
{
    u32 i;
    u32 theta = 0;

    for (i = 0; i < 256; i++)
    {
        buffer[i] = (gSineTable[theta & 0xFF] * amplitud) >> 8;
        theta += frecuencia;
    }
}

u32 IniciaEfectoHorizontal(u32 lineaInicial, u32 lineaFinal, u32 frecuencia, u32 amplitud, u32 framesHastaMovimiento, u32 registroPosicion, bool32 aplicaPosicionFondosBatalla)
{
    u32 i;
    u32 posicion = 320; // Para dar suficiente espacio para cálculos de la tabla de seno.
    struct ParametrosEfectoHorizontal parametros;
    u8 taskId;

    LimpiaEfectoHorizontal();

    parametros.dmaDest = (void *)(REG_ADDR_BG0HOFS + registroPosicion);
    parametros.bitsDMA = EFECTO_HORIZONTAL_DMA_16;
    parametros.estado = ESTADO_EFECTO_HORIZONTAL_ACTIVO;
    EscribeParametrosEfectoHorizontal(parametros);

    taskId = CreateTask(Tarea_ActualizaOndaPorFrame, 0);

    gTasks[taskId].tLineaInicial                = lineaInicial;
    gTasks[taskId].tLineaFinal                  = lineaFinal;
    gTasks[taskId].tDuracionOnda                = 256 / frecuencia;
    gTasks[taskId].tPosicionBuffer              = 0;
    gTasks[taskId].tFramesHastaMovimiento       = framesHastaMovimiento;
    gTasks[taskId].tRegistroPosicion            = registroPosicion;
    gTasks[taskId].tAplicaPosicionFondosBatalla = aplicaPosicionFondosBatalla;

    gEfectoHorizontal.tareaOnda = taskId;
    sDeberiaPararOnda = FALSE;

    GeneraOnda(&gRegistrosBuffersEfectoHorizontal[0][posicion], frecuencia, amplitud);

    for (i = lineaInicial; i < lineaFinal; i++)
    {
        gRegistrosBuffersEfectoHorizontal[0][i] = gRegistrosBuffersEfectoHorizontal[0][posicion];
        gRegistrosBuffersEfectoHorizontal[1][i] = gRegistrosBuffersEfectoHorizontal[0][posicion];
        posicion++;
    }

    return taskId;
}

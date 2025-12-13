#include "global.h"
#include "battle.h"
#include "data.h"
#include "task.h"
#include "trig.h"
#include "distorsion_fondo.h"

static void CopiaValor16Bits(void);
static void CopiaValor32Bits(void);

EWRAM_DATA u16 ALIGNED(4) gRegistrosBuffersDistorsionFondo[NUMERO_BUFFERS_DISTORSION_FONDO][ANCHO_PANTALLA * EFECTOS_POR_LINEA_HORIZONTAL] = {0};
EWRAM_DATA struct DistorsionFondo gDistorsionFondo = {0};
EWRAM_DATA static bool32 sDeberiaPararOnda = FALSE;

void ParaDistorsionFondo(void)
{
    gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_PARAR;
    DmaStop(0);
    if (gDistorsionFondo.tareaOnda != TASK_NONE)
    {
        DestroyTask(gDistorsionFondo.tareaOnda);
        gDistorsionFondo.tareaOnda = TASK_NONE;
    }
}

void LimpiaDistorsionFondo(void)
{
    CpuFill16(0, gRegistrosBuffersDistorsionFondo, sizeof(gRegistrosBuffersDistorsionFondo));
    gDistorsionFondo.dmaSrcBuffers[0] = NULL;
    gDistorsionFondo.dmaSrcBuffers[1] = NULL;
    gDistorsionFondo.dmaDest = NULL;
    gDistorsionFondo.bitsDMA = 0;
    gDistorsionFondo.srcBuffer = 0;
    gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_INACTIVO;
    gDistorsionFondo.tareaOnda = TASK_NONE;
}

void EscribeParametrosDistorsionFondo(struct ParametrosDistorsionFondo parametros)
{
    // Escribe por DMA el valor de la segunda línea horizontal porque
    // el primer DMA ocurre en el hblank después de dibujar la primera línea.
    if (parametros.bitsDMA == DISTORSION_FONDO_DMA_16)
    {
        gDistorsionFondo.dmaSrcBuffers[0] = (u16 *)gRegistrosBuffersDistorsionFondo[0] + 1;
        gDistorsionFondo.dmaSrcBuffers[1] = (u16 *)gRegistrosBuffersDistorsionFondo[1] + 1;
        gDistorsionFondo.escribeRegistroPrimeraLinea = CopiaValor16Bits;
    }
    else // DISTORSION_FONDO_DMA_32
    {
        gDistorsionFondo.dmaSrcBuffers[0] = (u32 *)gRegistrosBuffersDistorsionFondo[0] + 1;
        gDistorsionFondo.dmaSrcBuffers[1] = (u32 *)gRegistrosBuffersDistorsionFondo[1] + 1;
        gDistorsionFondo.escribeRegistroPrimeraLinea = CopiaValor32Bits;
    }
    gDistorsionFondo.bitsDMA   = parametros.bitsDMA;
    gDistorsionFondo.dmaDest   = parametros.dmaDest;
    gDistorsionFondo.estado    = parametros.estado;
}

void IniciaTransferenciaDMAEnHblankDistorsionFondo(void)
{
    if (gDistorsionFondo.estado == ESTADO_DISTORSION_FONDO_INACTIVO)
    {
        return;
    }
    else if (gDistorsionFondo.estado == ESTADO_DISTORSION_FONDO_PARAR)
    {
        gDistorsionFondo.estado = ESTADO_DISTORSION_FONDO_INACTIVO;
        DmaStop(0);
        sDeberiaPararOnda = TRUE;
    }
    else // ESTADO_DISTORSION_FONDO_ACTIVO
    {
        DmaStop(0);
        // Prepara DMA para copiar el registro en cada HBlank durante el siguiente frame.
        // La transferencia no ocurre durante el VBlank, así que empieza tras pintar (en el HBlank) el primer frame.
        DmaSet(0, gDistorsionFondo.dmaSrcBuffers[gDistorsionFondo.srcBuffer], gDistorsionFondo.dmaDest, gDistorsionFondo.bitsDMA);
        // Escribe el valor del registro para la línea 0
        gDistorsionFondo.escribeRegistroPrimeraLinea();
        // Alterna entre los dos buffers para evitar tearing
        gDistorsionFondo.srcBuffer ^= 1;
    }
}

static void CopiaValor16Bits(void)
{
    vu16 *dest = (vu16 *)gDistorsionFondo.dmaDest;
    vu16 *src = (vu16 *)&gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer];

    *dest = *src;
}

static void CopiaValor32Bits(void)
{
    vu32 *dest = (vu32 *)gDistorsionFondo.dmaDest;
    vu32 *src = (vu32 *)&gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer];

    *dest = *src;
}

#define tLineaInicial                   data[0]
#define tLineaFinal                     data[1]
#define tDuracionOnda                   data[2]
#define tPosicionBuffer                 data[3]
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
        gDistorsionFondo.tareaOnda = TASK_NONE;
    }
    else
    {
        if (gTasks[taskId].tAplicaPosicionFondosBatalla)
        {
            switch (gTasks[taskId].tRegistroPosicion)
            {
            case DISTORSION_FONDO_BG_0_HORIZONTAL:
                value = gBattle_BG0_X;
                break;
            case DISTORSION_FONDO_BG_0_VERTICAL:
                value = gBattle_BG0_Y;
                break;
            case DISTORSION_FONDO_BG_1_HORIZONTAL:
                value = gBattle_BG1_X;
                break;
            case DISTORSION_FONDO_BG_1_VERTICAL:
                value = gBattle_BG1_Y;
                break;
            case DISTORSION_FONDO_BG_2_HORIZONTAL:
                value = gBattle_BG2_X;
                break;
            case DISTORSION_FONDO_BG_2_VERTICAL:
                value = gBattle_BG2_Y;
                break;
            case DISTORSION_FONDO_BG_3_HORIZONTAL:
                value = gBattle_BG3_X;
                break;
            case DISTORSION_FONDO_BG_3_VERTICAL:
                value = gBattle_BG3_Y;
                break;
            }
        }
        if (gTasks[taskId].tFramesHastaMovimiento != 0)
        {
            gTasks[taskId].tFramesHastaMovimiento--;
            offset = gTasks[taskId].tPosicionBuffer + VALOR_POSICION_ONDA;
            for (i = gTasks[taskId].tLineaInicial; i < gTasks[taskId].tLineaFinal; i++)
            {
                gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = gRegistrosBuffersDistorsionFondo[0][offset] + value;
                offset++;
            }
        }
        else
        {
            offset = gTasks[taskId].tPosicionBuffer + VALOR_POSICION_ONDA;
            for (i = gTasks[taskId].tLineaInicial; i < gTasks[taskId].tLineaFinal; i++)
            {
                gRegistrosBuffersDistorsionFondo[gDistorsionFondo.srcBuffer][i] = gRegistrosBuffersDistorsionFondo[0][offset] + value;
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

u32 IniciaDistorsionFondo(u32 lineaInicial, u32 lineaFinal, u32 frecuencia, u32 amplitud, u32 framesHastaMovimiento, u32 registroPosicion, bool32 aplicaPosicionFondosBatalla)
{
    u32 i;
    u32 posicion = VALOR_POSICION_ONDA;
    struct ParametrosDistorsionFondo parametros;
    u8 taskId;

    LimpiaDistorsionFondo();

    parametros.dmaDest = (void *)(REG_ADDR_BG0HOFS + registroPosicion);
    parametros.bitsDMA = DISTORSION_FONDO_DMA_16;
    parametros.estado = ESTADO_DISTORSION_FONDO_ACTIVO;
    EscribeParametrosDistorsionFondo(parametros);

    taskId = CreateTask(Tarea_ActualizaOndaPorFrame, 0);

    gTasks[taskId].tLineaInicial                = lineaInicial;
    gTasks[taskId].tLineaFinal                  = lineaFinal;
    gTasks[taskId].tDuracionOnda                = 256 / frecuencia;
    gTasks[taskId].tPosicionBuffer              = 0;
    gTasks[taskId].tFramesHastaMovimiento       = framesHastaMovimiento;
    gTasks[taskId].tRegistroPosicion            = registroPosicion;
    gTasks[taskId].tAplicaPosicionFondosBatalla = aplicaPosicionFondosBatalla;

    gDistorsionFondo.tareaOnda = taskId;
    sDeberiaPararOnda = FALSE;

    GeneraOnda(&gRegistrosBuffersDistorsionFondo[0][posicion], frecuencia, amplitud);

    for (i = lineaInicial; i < lineaFinal; i++)
    {
        gRegistrosBuffersDistorsionFondo[0][i] = gRegistrosBuffersDistorsionFondo[0][posicion];
        gRegistrosBuffersDistorsionFondo[1][i] = gRegistrosBuffersDistorsionFondo[0][posicion];
        posicion++;
    }

    return taskId;
}

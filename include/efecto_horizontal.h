#ifndef GUARD_EFECTO_HORIZONTAL_H
#define GUARD_EFECTO_HORIZONTAL_H

#define EFECTO_HORIZONTAL_DMA_16 (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_16BIT | DMA_DEST_RELOAD) << 16) | 1)
#define EFECTO_HORIZONTAL_DMA_32 (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_32BIT | DMA_DEST_RELOAD) << 16) | 1)

#define EFECTO_HORIZONTAL_BG_0_HORIZONTAL   (REG_ADDR_BG0HOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_0_VERTICAL     (REG_ADDR_BG0VOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_1_HORIZONTAL   (REG_ADDR_BG1HOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_1_VERTICAL     (REG_ADDR_BG1VOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_2_HORIZONTAL   (REG_ADDR_BG2HOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_2_VERTICAL     (REG_ADDR_BG2VOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_3_HORIZONTAL   (REG_ADDR_BG3HOFS - REG_ADDR_BG0HOFS)
#define EFECTO_HORIZONTAL_BG_3_VERTICAL     (REG_ADDR_BG3VOFS - REG_ADDR_BG0HOFS)

//  Tiene doble buffer para que se pueda escribir de forma segura en cualquier momento
//  sin borrar el buffer que está leyendo el DMA,
#define NUMERO_BUFFERS_EFECTO_HORIZONTAL    2
//  Número de valores posibles de "efectos" por línea horizontal para DMA.
#define EFECTOS_POR_LINEA_HORIZONTAL        4

enum EstadosEfectoHorizontal
{
    ESTADO_EFECTO_HORIZONTAL_INACTIVO,
    ESTADO_EFECTO_HORIZONTAL_ACTIVO,
    ESTADO_EFECTO_HORIZONTAL_PARAR
};

struct ParametrosEfectoHorizontal
{
    volatile void *dmaDest;
    u32 bitsDMA;
    //enum EstadosEfectoHorizontal estado;
    u32 estado;
};

struct EfectoHorizontal
{
    void *dmaSrcBuffers[NUMERO_BUFFERS_EFECTO_HORIZONTAL];
    volatile void *dmaDest;
    u32 bitsDMA;
    void (*escribeRegistroPrimeraLinea)(void);
    u32 srcBuffer;
    u32 tareaOnda;
    //enum EstadosEfectoHorizontal estado;
    u32 estado;
};

extern struct EfectoHorizontal gEfectoHorizontal;

extern u16 ALIGNED(4) gRegistrosBuffersEfectoHorizontal[NUMERO_BUFFERS_EFECTO_HORIZONTAL][ANCHO_PANTALLA * EFECTOS_POR_LINEA_HORIZONTAL];

void ParaEfectoHorizontal(void);
void LimpiaEfectoHorizontal(void);
void EscribeParametrosEfectoHorizontal(struct ParametrosEfectoHorizontal);
void IniciaTransferenciaDMAEnHblankEfectoHorizontal(void);
u32 IniciaEfectoHorizontal(u32 lineaInicial, u32 lineaFinal, u32 frecuencia, u32 amplitud, u32 framesHastaMovimiento, u32 registroPosicion, bool32 aplicaPosicionFondosBatalla);

#endif // GUARD_EFECTO_HORIZONTAL_H

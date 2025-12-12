#ifndef GUARD_DISTORSION_FONDO_H
#define GUARD_DISTORSION_FONDO_H

#define DISTORSION_FONDO_DMA_16 (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_16BIT | DMA_DEST_RELOAD) << 16) | 1)
#define DISTORSION_FONDO_DMA_32 (((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_SRC_INC | DMA_DEST_INC | DMA_32BIT | DMA_DEST_RELOAD) << 16) | 1)

#define DISTORSION_FONDO_BG_0_HORIZONTAL   (REG_ADDR_BG0HOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_0_VERTICAL     (REG_ADDR_BG0VOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_1_HORIZONTAL   (REG_ADDR_BG1HOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_1_VERTICAL     (REG_ADDR_BG1VOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_2_HORIZONTAL   (REG_ADDR_BG2HOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_2_VERTICAL     (REG_ADDR_BG2VOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_3_HORIZONTAL   (REG_ADDR_BG3HOFS - REG_ADDR_BG0HOFS)
#define DISTORSION_FONDO_BG_3_VERTICAL     (REG_ADDR_BG3VOFS - REG_ADDR_BG0HOFS)

//  Tiene doble buffer para que se pueda escribir de forma segura en cualquier momento
//  sin borrar el buffer que está leyendo el DMA,
#define NUMERO_BUFFERS_DISTORSION_FONDO    2

//  Número de valores posibles de "efectos" por línea horizontal para DMA.
#define EFECTOS_POR_LINEA_HORIZONTAL        4

enum EstadosDistorsionFondo
{
    ESTADO_DISTORSION_FONDO_INACTIVO,
    ESTADO_DISTORSION_FONDO_ACTIVO,
    ESTADO_DISTORSION_FONDO_PARAR
};

struct ParametrosDistorsionFondo
{
    volatile void *dmaDest;
    u32 bitsDMA;
    enum EstadosDistorsionFondo estado;
};

struct DistorsionFondo
{
    void *dmaSrcBuffers[NUMERO_BUFFERS_DISTORSION_FONDO];
    volatile void *dmaDest;
    u32 bitsDMA;
    void (*escribeRegistroPrimeraLinea)(void);
    u32 srcBuffer;
    u32 tareaOnda;
    enum EstadosDistorsionFondo estado;
};

extern struct DistorsionFondo gDistorsionFondo;

extern u16 ALIGNED(4) gRegistrosBuffersDistorsionFondo[NUMERO_BUFFERS_DISTORSION_FONDO][ANCHO_PANTALLA * EFECTOS_POR_LINEA_HORIZONTAL];

void ParaDistorsionFondo(void);
void LimpiaDistorsionFondo(void);
void EscribeParametrosDistorsionFondo(struct ParametrosDistorsionFondo);
void IniciaTransferenciaDMAEnHblankDistorsionFondo(void);
u32 IniciaDistorsionFondo(u32 lineaInicial, u32 lineaFinal, u32 frecuencia, u32 amplitud, u32 framesHastaMovimiento, u32 registroPosicion, bool32 aplicaPosicionFondosBatalla);

#endif // GUARD_DISTORSION_FONDO_H

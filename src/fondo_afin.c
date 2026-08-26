#include "global.h"
#include "bg.h"
#include "depuracion_mgba.h"
#include "fieldmap.h"
#include "fondo_afin.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "window.h"
#include "constants/rgb.h"

// ---------------------------------------------------------------------------
// Captura
//
// La capa baja del metatile -la que en el mapa va al fondo 3- es el suelo, y es
// la unica que interesa: no hay que componer nada, cada casilla del fondo afin
// sale de una sola entrada del tileset.
//
// El truco que hace esto barato es la paleta. En el mapa los tiles son de 4bpp
// repartidos en 13 paletas de 16 colores (6 del tileset primario y 7 del
// secundario), o sea 208 colores que caben enteros en la unica paleta de 256
// del fondo afin. Convertir un pixel es entonces sumarle paleta*16 a su indice,
// sin recolorear ni buscar nada. Y de propina quedan libres las paletas 13, 14
// y 15 para el texto.
// ---------------------------------------------------------------------------

#define AFIN_TILES_TAM  (AFIN_MAX_TILES * 64)
#define TAM_TILE_4BPP   32

// Formato de una entrada del tileset del mapa
#define ENTRADA_TILE(e)    ((e) & 0x03FF)
#define ENTRADA_VOLTEO_H(e) ((e) & 0x0400)
#define ENTRADA_VOLTEO_V(e) ((e) & 0x0800)
#define ENTRADA_PALETA(e)  (((e) >> 12) & 0xF)

static struct FondoAfin *sFondo = NULL;

struct FondoAfin *FondoAfinCapturado(void)
{
    return sFondo;
}

void LiberaFondoAfin(void)
{
    if (sFondo != NULL)
    {
        Free(sFondo);
        sFondo = NULL;
    }
}

// Pasa un tile de 4bpp de la vram del mapa a 8bpp, aplicando volteos y el
// desplazamiento de paleta. El indice 0 se queda en 0 -transparente- en vez de
// convertirse en el color 0 de su paleta: en el mapa esos pixeles tampoco
// pintan nada, dejan ver la capa de debajo.
static void ExpandeTileA8bpp(u8 *destino, const u8 *origen, u32 paleta, bool32 volteoH, bool32 volteoV)
{
    u32 fila;

    for (fila = 0; fila < 8; fila++)
    {
        const u8 *bytes = origen + (volteoV ? 7 - fila : fila) * 4;
        u32 columna;

        for (columna = 0; columna < 8; columna++)
        {
            u32 columnaOrigen = volteoH ? 7 - columna : columna;
            u32 valor = bytes[columnaOrigen >> 1];

            valor = (columnaOrigen & 1) ? (valor >> 4) : (valor & 0xF);
            destino[fila * 8 + columna] = valor ? valor + paleta * 16 : 0;
        }
    }
}

// Devuelve el indice que le toca a esta entrada en el tileset afin, creandolo
// si es la primera vez que se ve.
static u32 IndiceTileAfin(u32 entrada)
{
    u32 i;

    for (i = 0; i < sFondo->numTiles; i++)
    {
        if (sFondo->origen[i] == entrada)
            return i;
    }

    if (sFondo->numTiles >= AFIN_MAX_TILES)
    {
        // El mapa afin indexa con un byte, asi que no hay sitio para mas de 256
        // tiles distintos. Se reutiliza el 0 -vacio- y se avisa al salir.
        sFondo->desbordado++;
        return 0;
    }

    i = sFondo->numTiles++;
    sFondo->origen[i] = entrada;
    ExpandeTileA8bpp(&sFondo->tiles[i * 64],
                     (const u8 *)(BG_VRAM + ENTRADA_TILE(entrada) * TAM_TILE_4BPP),
                     ENTRADA_PALETA(entrada),
                     ENTRADA_VOLTEO_H(entrada),
                     ENTRADA_VOLTEO_V(entrada));
    return i;
}

// Resto siempre positivo: el rango capturado se sale del mapa por arriba y por
// la izquierda, y ahi el operador % de C devuelve negativos.
static s32 Modulo(s32 valor, s32 divisor)
{
    if (divisor <= 0)
        return 0;

    valor %= divisor;
    return valor < 0 ? valor + divisor : valor;
}

// Coordenada del mapa que le toca a una casilla del fondo, repitiendo el mapa
// en las dos direcciones.
//
// Sin esto, todo lo que cae fuera del mapa lo resuelve MapGridGetMetatileIdAt
// con bloques de borde y de relleno, que en un fondo en perspectiva se ven
// muchisimo: son la mancha que aparece al fondo. Repitiendo el mapa el suelo
// sale continuo por grande que sea el area capturada.
static void EnvuelveEnElMapa(s32 *x, s32 *y)
{
    *x = MAP_OFFSET + Modulo(*x - MAP_OFFSET, gMapHeader.mapLayout->width);
    *y = MAP_OFFSET + Modulo(*y - MAP_OFFSET, gMapHeader.mapLayout->height);
}

bool32 CapturaFondoAfin(void)
{
    s32 centroX, centroY;
    s32 fila;

    LiberaFondoAfin();
    sFondo = AllocZeroed(sizeof(*sFondo));
    if (sFondo == NULL)
    {
        LOG("FONDO AFIN: sin memoria", sizeof(struct FondoAfin), 0);
        return FALSE;
    }

    // Las 13 paletas de fondo del mapa, tal cual, como paleta unica de 256.
    CopiaCpu16(gPlttBufferUnfaded, sFondo->paleta, sizeof(sFondo->paleta));

    // El tile 0 se reserva vacio: es el que se usa cuando algo no cabe.
    sFondo->numTiles = 1;
    sFondo->origen[0] = 0xFFFF;

    // pos.x/pos.y es la esquina de la vista, y el jugador esta MAP_OFFSET
    // metatiles mas adentro.
    centroX = gSaveBlockPtr->pos.x + MAP_OFFSET;
    centroY = gSaveBlockPtr->pos.y + MAP_OFFSET;

    for (fila = 0; fila < AFIN_METATILES_LADO; fila++)
    {
        s32 columna;

        for (columna = 0; columna < AFIN_METATILES_LADO; columna++)
        {
            s32 x = centroX - AFIN_METATILES_LADO / 2 + columna;
            s32 y = centroY - AFIN_METATILES_LADO / 2 + fila;
            u32 metatileId;
            const u16 *metatiles;
            const u16 *capaBaja;
            u32 i;

            EnvuelveEnElMapa(&x, &y);
            metatileId = MapGridGetMetatileIdAt(x, y);

            if (metatileId >= NUM_METATILES_TOTAL)
                metatileId = 0;

            if (metatileId < NUM_METATILES_IN_PRIMARY)
            {
                metatiles = gMapHeader.mapLayout->primaryTileset->metatiles;
            }
            else
            {
                metatiles = gMapHeader.mapLayout->secondaryTileset->metatiles;
                metatileId -= NUM_METATILES_IN_PRIMARY;
            }

            if (metatiles == NULL)
                continue;

            capaBaja = metatiles + metatileId * NUM_TILES_PER_METATILE;

            // El metatile son 2x2 casillas
            for (i = 0; i < 4; i++)
            {
                u32 destino = (fila * 2 + (i >> 1)) * AFIN_MAPA_LADO + columna * 2 + (i & 1);
                sFondo->mapa[destino] = IndiceTileAfin(capaBaja[i]);
            }
        }
    }

    LOG("FONDO AFIN capturado: tiles/desbordes", sFondo->numTiles, sFondo->desbordado);
    return TRUE;
}

// ---------------------------------------------------------------------------
// Demo: modo 1 con el fondo 2 afin como suelo en perspectiva
//
// El modo 1 deja dos fondos normales -0 y 1- y uno afin -el 2-. Aqui el 0
// lleva el texto y el 2 el suelo. Las plataformas irian en el 1 cuando toque.
//
// La perspectiva no la hace el hardware: los registros afines describen una
// transformacion plana, asi que para que el suelo se aleje hay que reescribir
// PA, PC, X e Y en cada linea. Eso es lo que se conoce como modo 7, y es un
// interrupcion de HBlank leyendo una tabla precalculada por fotograma.
// ---------------------------------------------------------------------------

#define VRAM_TILES_AFIN   (BG_VRAM + 0x0000)   // base de caracteres 0, 16 KB
#define VRAM_MAPA_AFIN    (BG_VRAM + 0x8000)   // bloque de mapa 16, 4 KB

#define VENTANA_DATOS 0

// El cielo es un tile opaco en el fondo 0, que va por delante del afin. Se
// pinta aqui, y no confiando en el color de fondo, porque asi es ya una capa de
// verdad: el dia que el cielo sea un dibujo, se cambia el tile y nada mas.
#define TILE_CIELO      1   // el 0 se queda transparente para el resto de la pantalla
#define FILA_PANEL      16  // fila de tiles donde empieza el panel de datos
#define COLOR_CIELO     RGB(14, 20, 31)
#define INDICE_CIELO    4   // hueco en la paleta del texto

struct LineaAfin
{
    s16 pa;
    s16 pc;
    s32 x;
    s32 y;
};

struct EstadoDemo
{
    s32 camaraX;
    s32 camaraY;
    s32 angulo;        // 0..255
    s32 altura;        // cuanto se aleja el suelo
    s32 profundidad;   // distancia focal: cuanto de lejos mira la camara
    s32 horizonte;     // linea donde el suelo se pierde
    bool32 perspectiva;
    bool32 saliendo;
};

static EWRAM_DATA struct LineaAfin sLineas[ALTURA_PANTALLA] = {0};
static EWRAM_DATA struct EstadoDemo sDemo = {0};

static const u16 sPaletaTexto[16] =
{
    RGB_BLACK, RGB_WHITE, RGB(8, 8, 8), RGB(20, 20, 20),
    [INDICE_CIELO] = COLOR_CIELO,
};

// Un tile entero del color del cielo
static const u32 sTileCielo[8] =
{
    0x44444444, 0x44444444, 0x44444444, 0x44444444,
    0x44444444, 0x44444444, 0x44444444, 0x44444444,
};

static const struct BgTemplate sPlantillasDemo[] =
{
    {
        .bg = FONDO_0,
        .charBaseIndex = 1,
        .mapBaseIndex = 20,
        .screenSize = FONDO_32x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_2,
        .charBaseIndex = 0,
        .mapBaseIndex = 16,
        .screenSize = FONDO_32x64, // en un fondo afin este valor significa 64x64
        .paletteMode = MODO_PALETAS_8BPP,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct WindowTemplate sVentanasDemo[] =
{
    [VENTANA_DATOS] = {
        .bg = FONDO_0,
        .tilemapLeft = 0,
        .tilemapTop = FILA_PANEL,
        .width = 30,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = TILE_CIELO + 1,
    },
    DUMMY_WIN_TEMPLATE
};

// Rellena la tabla que consume la interrupcion de HBlank.
//
// Para la linea `y` de pantalla, el suelo que se ve esta a una profundidad
// inversamente proporcional a su distancia al horizonte: cuanto mas cerca del
// horizonte, mas lejos, y por tanto mas texels caben en cada pixel.
static void CalculaLineas(void)
{
    s32 seno = Sin(sDemo.angulo, 256);
    s32 coseno = Cos(sDemo.angulo, 256);
    s32 linea;

    for (linea = 0; linea < ALTURA_PANTALLA; linea++)
    {
        struct LineaAfin *l = &sLineas[linea];
        s32 distancia = linea - sDemo.horizonte;
        s32 escala;
        s32 avance;

        if (!sDemo.perspectiva)
        {
            // Sin perspectiva: giro y nada mas, para ver el suelo de frente y
            // comprobar que la captura es correcta.
            //
            // Aqui hay una trampa. El hardware haria avanzar la textura de una
            // linea a la siguiente con PB y PD, pero como este codigo reescribe
            // X e Y en cada HBlank, esos registros internos se reinician y PB y
            // PD no llegan a aplicarse nunca. El avance vertical hay que
            // sumarlo a mano o saldrian las 160 lineas iguales.
            l->pa = coseno;
            l->pc = seno;
            l->x = (sDemo.camaraX << 8) - coseno * (ANCHO_PANTALLA / 2)
                 + seno * (ALTURA_PANTALLA / 2) - seno * linea;
            l->y = (sDemo.camaraY << 8) - seno * (ANCHO_PANTALLA / 2)
                 - coseno * (ALTURA_PANTALLA / 2) + coseno * linea;
            continue;
        }

        if (distancia < 1)
            distancia = 1;

        escala = (sDemo.altura << 8) / distancia;
        // Muy cerca del horizonte cada pixel abarcaria cientos de texels y solo
        // sale ruido. Se corta ahi: por encima el suelo ya no se dibuja.
        if (escala > 0x4000)
            escala = 0x4000;

        l->pa = (escala * coseno) >> 8;
        l->pc = (escala * seno) >> 8;

        avance = (sDemo.profundidad * escala) >> 8;

        l->x = (sDemo.camaraX << 8) - ((avance * seno) >> 8) - l->pa * (ANCHO_PANTALLA / 2);
        l->y = (sDemo.camaraY << 8) + ((avance * coseno) >> 8) - l->pc * (ANCHO_PANTALLA / 2);
    }
}

static void AplicaLinea(const struct LineaAfin *l)
{
    REG_BG2PA = l->pa;
    REG_BG2PC = l->pc;
    REG_BG2X = l->x;
    REG_BG2Y = l->y;
}

static void HBlankCB_FondoAfin(void)
{
    u32 linea = REG_VCOUNT + 1;

    // La escritura en HBlank surte efecto en la linea siguiente, y durante el
    // VBlank no hay ninguna que preparar.
    if (linea < ALTURA_PANTALLA)
        AplicaLinea(&sLineas[linea]);
}

static void VBlankCB_FondoAfin(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    AplicaLinea(&sLineas[0]);
}

static void EscribeDatos(void)
{
    u8 texto[80];
    u8 *p = texto;
    struct FondoAfin *fondo = FondoAfinCapturado();

    FillWindowPixelBuffer(VENTANA_DATOS, PIXEL_FILL(1));

    p = ConvertIntToDecimalStringN(p, fondo != NULL ? fondo->numTiles : 0, STR_CONV_MODE_LEFT_ALIGN, 3);
    *p++ = CHAR_SPACE;
    p = ConvertIntToDecimalStringN(p, sDemo.angulo, STR_CONV_MODE_LEFT_ALIGN, 3);
    *p++ = CHAR_SPACE;
    p = ConvertIntToDecimalStringN(p, sDemo.altura, STR_CONV_MODE_LEFT_ALIGN, 4);
    *p++ = CHAR_SPACE;
    p = ConvertIntToDecimalStringN(p, sDemo.profundidad, STR_CONV_MODE_LEFT_ALIGN, 4);
    *p++ = CHAR_SPACE;
    p = ConvertIntToDecimalStringN(p, sDemo.horizonte, STR_CONV_MODE_LEFT_ALIGN, 3);
    *p = EOS;

    AddTextPrinterParameterized(VENTANA_DATOS, FONT_SMALL, texto, 2, 1, 0, NULL);
    CopyWindowToVram(VENTANA_DATOS, COPYWIN_GFX);
}

static bool32 LeeMandos(void)
{
    s32 seno = Sin(sDemo.angulo, 8);
    s32 coseno = Cos(sDemo.angulo, 8);

    if (JOY_HELD(DPAD_LEFT))
        sDemo.angulo = (sDemo.angulo - 2) & 0xFF;
    if (JOY_HELD(DPAD_RIGHT))
        sDemo.angulo = (sDemo.angulo + 2) & 0xFF;

    // Adelante y atras en la direccion a la que mira la camara
    if (JOY_HELD(DPAD_UP))
    {
        sDemo.camaraX -= seno / 2;
        sDemo.camaraY += coseno / 2;
    }
    if (JOY_HELD(DPAD_DOWN))
    {
        sDemo.camaraX += seno / 2;
        sDemo.camaraY -= coseno / 2;
    }

    if (JOY_HELD(A_BUTTON))
        sDemo.altura += 2;
    if (JOY_HELD(B_BUTTON))
        sDemo.altura -= 2;
    if (sDemo.altura < 8)
        sDemo.altura = 8;

    if (JOY_HELD(L_BUTTON))
        sDemo.horizonte--;
    if (JOY_HELD(R_BUTTON))
        sDemo.horizonte++;
    if (sDemo.horizonte < 0)
        sDemo.horizonte = 0;
    if (sDemo.horizonte > ALTURA_PANTALLA - 8)
        sDemo.horizonte = ALTURA_PANTALLA - 8;

    if (JOY_NEW(SELECT_BUTTON))
        sDemo.perspectiva = !sDemo.perspectiva;

    if (JOY_NEW(START_BUTTON))
        sDemo.saliendo = TRUE;

    return (gMain.heldKeys | gMain.newKeys) != 0;
}

// Rellena de cielo las filas de tiles que quedan por encima del horizonte.
//
// El corte fino lo sigue haciendo la ventana, que trabaja por lineas; esto va
// por filas de ocho. Entre una cosa y otra queda una banda de hasta siete
// lineas donde no hay ni cielo ni suelo, y por eso el color de fondo es el
// mismo del cielo: asi la union no se ve.
static void PintaCielo(void)
{
    u32 filas = (sDemo.perspectiva ? sDemo.horizonte : 0) / 8;

    if (filas != 0)
        FillBgTilemapBufferRect(FONDO_0, TILE_CIELO, 0, 0, 32, filas, 15);

    if (filas < FILA_PANEL)
        FillBgTilemapBufferRect(FONDO_0, 0, 0, filas, 32, FILA_PANEL - filas, 15);

    CopyBgTilemapBufferToVram(FONDO_0);
}

static void ColocaVentanaSuelo(void)
{
    // El suelo solo se dibuja por debajo del horizonte; por encima queda el
    // color de fondo, que hace de cielo. Sin perspectiva no hay horizonte que
    // valga y se ve la pantalla entera.
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, ANCHO_PANTALLA));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(sDemo.perspectiva ? sDemo.horizonte : 0, ALTURA_PANTALLA));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG2 | WININ_WIN0_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ);
}

static void CB2_DemoFondoAfin(void)
{
    if (sDemo.saliendo)
    {
        SetHBlankCallback(NULL);
        DisableInterrupts(INTR_FLAG_HBLANK);
        SetVBlankCallback(NULL);
        FreeAllWindowBuffers();
        LiberaFondoAfin();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
    }

    // El panel solo se vuelve a componer cuando hay algo que cambie: son 120
    // casillas de texto y no vale la pena rehacerlas en cada fotograma.
    if (LeeMandos())
    {
        EscribeDatos();
        PintaCielo();
    }

    CalculaLineas();
    ColocaVentanaSuelo();

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void EntraEnDemoFondoAfin(void)
{
    struct FondoAfin *fondo;

    if (!CapturaFondoAfin())
        return;

    fondo = FondoAfinCapturado();

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    // La captura ya esta a salvo en el monton, asi que se puede barrer la vram
    // del mapa: si no, los tiles viejos asomarian por las casillas vacias.
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);

    ResetPaletteFade();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();

    ResetBgsAndClearDma3BusyFlags();
    IniciaFondosDesdePlantillas(MODO_1, sPlantillasDemo, ARRAY_COUNT(sPlantillasDemo));
    InitWindows(sVentanasDemo);
    DeactivateAllTextPrinters();

    // El fondo afin se sube a pelo: bg.c lleva su propia contabilidad de
    // tilemaps pensada para fondos normales, y aqui el mapa son bytes.
    CopiaRapidaCpu(fondo->tiles, (void *)VRAM_TILES_AFIN, AFIN_TILES_TAM);
    CopiaRapidaCpu(fondo->mapa, (void *)VRAM_MAPA_AFIN, sizeof(fondo->mapa));

    LoadPalette(fondo->paleta, 0, sizeof(fondo->paleta));
    LoadPalette(sPaletaTexto, BG_PLTT_ID(15), sizeof(sPaletaTexto));
    CopiaRapidaCpu(sTileCielo, (void *)(BG_CHAR_ADDR(1) + TILE_CIELO * TAM_TILE_4BPP), TAM_TILE_4BPP);

    // Color de fondo: lo que se ve por encima del horizonte y por los huecos
    // transparentes del suelo.
    gPlttBufferUnfaded[0] = gPlttBufferFaded[0] = COLOR_CIELO;

    sDemo.camaraX = (AFIN_MAPA_LADO / 2) * 8;
    sDemo.camaraY = (AFIN_MAPA_LADO / 2) * 8;
    sDemo.angulo = 0;
    sDemo.altura = 120;
    sDemo.profundidad = 160;
    sDemo.horizonte = 40;
    sDemo.perspectiva = TRUE;
    sDemo.saliendo = FALSE;

    CalculaLineas();
    ColocaVentanaSuelo();

    // La repeticion solo existe en los fondos afines, y la plantilla no tiene
    // campo para ella. Se pone antes de ShowBg, que es quien compone BG2CNT:
    // sin esto, mas alla de los 512x512 del fondo no habria suelo.
    SetBgAttribute(FONDO_2, BG_ATTR_WRAPAROUND, 1);

    ShowBg(FONDO_0);
    ShowBg(FONDO_2);
    PutWindowTilemap(VENTANA_DATOS);
    EscribeDatos();
    PintaCielo();

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);

    SetVBlankCallback(VBlankCB_FondoAfin);
    SetHBlankCallback(HBlankCB_FondoAfin);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);

    SetMainCallback2(CB2_DemoFondoAfin);
}

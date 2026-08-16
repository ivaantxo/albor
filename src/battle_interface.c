#include "global.h"
#include "depuracion_mgba.h"
#include "malloc.h"
#include "battle.h"
#include "bg.h"
#include "pokemon.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "graphics.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "sound.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "battle_anim.h"
#include "data.h"
#include "pokemon_summary_screen.h"
#include "strings.h"
#include "battle_debug.h"
#include "item.h"
#include "item_icon.h"
#include "item_use.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/items.h"

// Los iconos de estado viven en gIconosEstadoCombate_Gfx: cinco estados seguidos,
// de tres tiles cada uno, y ese bloque repetido una vez por combatiente, porque
// cada uno pinta el icono con un color de paleta distinto.
#define TILES_POR_ICONO_ESTADO 4   // 32x8

// Tira de texto del marcador: 96x16, en cuatro columnas de tiles por subsprite.
// Son 16 px de alto y no 8 porque FONT_SMALL mide 12: con una sola fila de tiles
// la fuente se cortaba por la mitad de abajo.
#define TILES_ANCHO_TEXTO      12
#define TILES_ALTO_TEXTO        2
#define TILES_ANCHO_SUBSPRITE   4
#define TILES_TEXTO_MARCADOR   (TILES_ANCHO_TEXTO * TILES_ALTO_TEXTO)

// Reparto de la tira en columnas de 8 px. Nombre a la izquierda, nivel y
// porcentaje pegados a la derecha de su tramo.
#define COL_NOMBRE          0
#define COLS_NOMBRE         6
#define COL_NIVEL           6
#define COLS_NIVEL          3
#define COL_PORCENTAJE      9
#define COLS_PORCENTAJE     3

// Blanco de la paleta compartida: el mismo que dibuja el contorno de la barra.
#define COLOR_TEXTO_MARCADOR 1

enum PiezaMarcador
{
    PIEZA_RELLENO,
    PIEZA_TEXTO,    // nombre, nivel y porcentaje comparten tira
    PIEZA_ESTADO,
    PIEZAS_MARCADOR,
};

// Orden de dibujado de las piezas del marcador: cuanto menor es la subprioridad,
// mas arriba se dibuja. El marcador de fondo es opaco, asi que va el ultimo.
#define SUBPRIORIDAD_TEXTO      0
#define SUBPRIORIDAD_ESTADO     0
#define SUBPRIORIDAD_RELLENO    1
#define SUBPRIORIDAD_CONTORNO   2
#define SUBPRIORIDAD_MARCADOR   3


enum IconoEstado
{
    ICONO_ESTADO_PSN,
    ICONO_ESTADO_PRZ,
    ICONO_ESTADO_SLP,
    ICONO_ESTADO_FRZ,
    ICONO_ESTADO_BRN,
    ICONOS_ESTADO_POR_COMBATIENTE,
};

// Bolas del resumen de equipo, un tile cada una, en el orden de gBolasResumenEquipo_Gfx.
enum BolaResumenEquipo
{
    BOLA_RESUMEN_LLENA,
    BOLA_RESUMEN_VACIA,
    BOLA_RESUMEN_DEBILITADO,
    BOLA_RESUMEN_ESTADO,
    BOLA_RESUMEN_CAPTURADO,
};


static void DibujaIconoEstado(u8);
static void UpdateSpritePos(u32 spriteId, s16 x, s16 y);



static void SpriteCB_PiezaMarcador(struct Sprite *);
static void DibujaPorcentajeVida(u8 marcadorSpriteId, u32 porcentaje);
static void DibujaNombreYNivel(u8 marcadorSpriteId, struct Pokemon *mon);
static void TextoAlSprite(u32 spriteId, const u8 *texto, u32 x, u32 columna, u32 numColumnas);

static s32 CalcNewBarValue(s32, s32, s32, s32 *, u8, u16);
static void MoveBattleBarGraphically(u8);
static u8 CalcBarFilledPixels(s32, s32, s32, s32 *, u8 *, u8);

static void SpriteCb_AbilityPopUp(struct Sprite *);
static void Task_FreeAbilityPopUpGfx(u8);

static void SpriteCB_LastUsedBall(struct Sprite *);
static void SpriteCB_LastUsedBallWin(struct Sprite *);


static const struct SpriteSheet sSpriteSheet_BattleInterfaceSelector =
{
    gBattleInterfaceSelector, 256, TAG_BATTLE_INTERFACE_SELECTOR
};

static const struct OamData sOamData_BattleInterfaceSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sBattleInterfaceSelectorAnim[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sBattleInterfaceSelectorPause[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBattleInterfaceSelectorAnimTable[] =
{
    sBattleInterfaceSelectorAnim,
    sBattleInterfaceSelectorPause
};

static const struct Subsprite sBattleInterfaceSelectorSubsprites[] =
{
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SHAPE(16x16),
        .tileOffset = 0,
        .priority = 0
    },
    {
        .x = 112,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SHAPE(16x16),
        .tileOffset = 1,
        .priority = 0
    },
    {
        .x = 0,
        .y = 16,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SHAPE(16x16),
        .tileOffset = 2,
        .priority = 0
    },
    {
        .x = 112,
        .y = 16,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SHAPE(16x16),
        .tileOffset = 3,
        .priority = 0
    }
};

static const struct SubspriteTable sBattleInterfaceSelectorSubspriteTable[] =
{
    {ARRAY_COUNT(sBattleInterfaceSelectorSubsprites), sBattleInterfaceSelectorSubsprites},
};

static const struct SpriteTemplate sBattleInterfaceSelector =
{
    .tileTag = TAG_BATTLE_INTERFACE_SELECTOR,
    .paletteTag = TAG_MARCADOR_PAL,
    .oam = &sOamData_BattleInterfaceSelector,
    .anims = sBattleInterfaceSelectorAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void MoveSelectionCreateCursorAt(u8 cursorPos)
{
    u32 index = GetSpriteIndexByTileTag(TAG_BATTLE_INTERFACE_SELECTOR);

    if (index == 0xFF)
    {
        LoadSpriteSheet(&sSpriteSheet_BattleInterfaceSelector);
        switch (cursorPos)
        {
        case 0:
            index = CreateSprite(&sBattleInterfaceSelector, 0, 112, 0);
            break;
        case 1:
            index = CreateSprite(&sBattleInterfaceSelector, 120, 112, 0);
            break;
        case 2:
            index = CreateSprite(&sBattleInterfaceSelector, 0, 136, 0);
            break;
        case 3:
            index = CreateSprite(&sBattleInterfaceSelector, 120, 136, 0);
            break;
        }
    }
    gSprites[index].oam.affineParam = (16 | cursorPos);
    SetSubspriteTables(&gSprites[index], sBattleInterfaceSelectorSubspriteTable);
    StartSpriteAnim(&gSprites[index], 0);
}

void MoveSelectionDestroyCursor(void)
{
    u32 cursorId = GetSpriteIndexByTileTag(TAG_BATTLE_INTERFACE_SELECTOR);
    if (cursorId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_BATTLE_INTERFACE_SELECTOR);
        DestroySprite(&gSprites[cursorId]);
    }
}



static const struct OamData sOamData_Healthbar =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};


// El relleno mide 80x8 y el OAM no tiene ningun tamano de 80 de ancho, asi que se
// compone de tres piezas: 32 + 32 + 16. El origen queda a 32 px del borde izquierdo.
/*        v-- Origen
[0     ][1     ][2 ]   80x8
*/
static const struct Subsprite sSubsprites_RellenoBarra[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    },
    {
        .x = 40,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 1
    }
};

static const struct SubspriteTable sSubspriteTable_RellenoBarra[] =
{
    {ARRAY_COUNT(sSubsprites_RellenoBarra), sSubsprites_RellenoBarra}
};

// El contorno es el grafico de 96x16, en tres piezas de 32x16. Colocado sobre el
// mismo origen que el relleno, su interior de 80x8 cae justo encima de este.
static const struct Subsprite sSubsprites_ContornoBarra[] =
{
    {
        .x = -20,
        .y = 0,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 12,
        .y = 0,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 8,
        .priority = 1
    },
    {
        .x = 44,
        .y = 0,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 16,
        .priority = 1
    }
};

static const struct SubspriteTable sSubspriteTable_ContornoBarra[] =
{
    {ARRAY_COUNT(sSubsprites_ContornoBarra), sSubsprites_ContornoBarra}
};

static const struct OamData sOamData_ContornoBarra =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sPlantillaContornoBarra =
{
    .tileTag = TAG_CONTORNO_BARRA,
    .paletteTag = TAG_MARCADOR_PAL,
    .oam = &sOamData_ContornoBarra,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// Tira de 96x16 con el nombre, el nivel y el porcentaje: tres piezas de 32x16.
static const struct Subsprite sSubsprites_TextoMarcador[] =
{
    {.x = -32, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 0,  .priority = 1},
    {.x =   0, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 8,  .priority = 1},
    {.x =  32, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 16, .priority = 1}
};

static const struct SubspriteTable sSubspriteTable_TextoMarcador[] =
{
    {ARRAY_COUNT(sSubsprites_TextoMarcador), sSubsprites_TextoMarcador}
};


// Relleno, porcentaje y texto salen de la misma hoja del combatiente y comparten
// forma de OAM: cada uno se queda con su tramo de tiles.
static const struct SpriteTemplate sPlantillasMarcador[NUMERO_COMBATIENTES] =
{
    [JUGADOR_IZQUIERDA]  = {TAG_MARCADOR_JUGADOR1,  TAG_MARCADOR_PAL, &sOamData_Healthbar, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
    [OPONENTE_IZQUIERDA] = {TAG_MARCADOR_OPONENTE1, TAG_MARCADOR_PAL, &sOamData_Healthbar, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
    [JUGADOR_DERECHA]    = {TAG_MARCADOR_JUGADOR2,  TAG_MARCADOR_PAL, &sOamData_Healthbar, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
    [OPONENTE_DERECHA]   = {TAG_MARCADOR_OPONENTE2, TAG_MARCADOR_PAL, &sOamData_Healthbar, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
};

static const struct SpriteTemplate sPlantillaIconoEstado =
{
    .tileTag = TAG_ICONOS_ESTADO,
    .paletteTag = TAG_MARCADOR_PAL,
    .oam = &sOamData_Healthbar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

enum
{
    PAL_STATUS_PSN,
    PAL_STATUS_PAR,
    PAL_STATUS_SLP,
    PAL_STATUS_FRZ,
    PAL_STATUS_BRN
};

static const u16 sStatusIconColors[] =
{
    [PAL_STATUS_PSN] = RGB(24, 12, 24),
    [PAL_STATUS_PAR] = RGB(23, 23, 3),
    [PAL_STATUS_SLP] = RGB(20, 20, 17),
    [PAL_STATUS_FRZ] = RGB(17, 22, 28),
    [PAL_STATUS_BRN] = RGB(28, 14, 10),
};


// Cada pieza: de que ancla cuelga, cual es, y si esta apagada por su cuenta
// (el icono de estado lo esta mientras no haya estado alterado).
#define sPiezaAncla         data[0]
#define sPiezaIndice        data[1]
#define sPiezaOculta        data[2]
#define sPiezaTileBase      data[3]

// This function is here to cover a specific case - one player's mon in a 2 vs 1 double battle. In this scenario - display singles layout.
// The same goes for a 2 vs 1 where opponent has only one pokemon.
u32 WhichBattleCoords(u32 battlerId)
{
    if (battlerId == JUGADOR_IZQUIERDA
        && gPlayerPartyCount == 1)
        return INDIVIDUAL;
    else if (battlerId == OPONENTE_IZQUIERDA
             && gEnemyPartyCount == 1)
        return INDIVIDUAL;
    else
        return EsCombateContraEntrenador(gCombate->tipoCombate);
}

// ---------------------------------------------------------------------------
// Marcador de combate
//
// No hay caja: son sprites sueltos colgando de un ancla, que es el contorno de
// la barra. gMarcadorSpriteIds[combatiente] guarda el id de esa ancla, y todo
// lo demas la sigue. No hay diferencia entre jugador y rival ni entre combate
// individual y doble: el marcador es siempre el mismo.
//
//   NOMBRE                Lv50
//   [###############  87 %]
//   [EST]
//
// Cada combatiente reserva TILES_MARCADOR tiles seguidos en su propia hoja:
//
//   0 .. 9    relleno de la barra   (80x8, generado en codigo)
//   10 .. 13  porcentaje de vida    (32x8, texto)
//   14 .. 25  nombre y nivel        (96x8, texto)
//
// El contorno y los iconos de estado son graficos compartidos por todos.
// ---------------------------------------------------------------------------

#define TILE_RELLENO_BARRA  0
#define TILE_TEXTO          (TILE_RELLENO_BARRA + TILES_RELLENO_BARRA_VIDA)

// Colocacion de cada pieza respecto al ancla, que esta en el centro de la barra.
#define TEXTO_DESPLAZAMIENTO_Y   -13
#define ESTADO_DESPLAZAMIENTO_X  -16
#define ESTADO_DESPLAZAMIENTO_Y    9

// Destruye el marcador que hubiera para este combatiente. Sin esto, cada vez que
// se rehacen los marcadores (al volver de un menu, por ejemplo) quedaban en
// pantalla las piezas anteriores, que ya no las actualizaba nadie.
void DestruyeMarcadorCombate(u8 battlerId)
{
    u8 anclaSpriteId = gMarcadorSpriteIds[battlerId];

    // gMarcadorSpriteIds arranca a cero, asi que no basta con mirar si el sprite
    // existe: hay que confirmar que de verdad es el ancla de este combatiente y no
    // el sprite 0 de cualquier otra cosa.
    if (anclaSpriteId >= MAX_SPRITES
     || !gSprites[anclaSpriteId].inUse
     || gSprites[anclaSpriteId].template != &sPlantillaContornoBarra
     || gSprites[anclaSpriteId].sMarcadorCombatiente != battlerId)
        return;

    for (u32 pieza = 0; pieza < PIEZAS_MARCADOR; pieza++)
    {
        u8 id = gSprites[anclaSpriteId].sMarcadorPieza(pieza);

        if (id < MAX_SPRITES && gSprites[id].inUse)
            DestroySprite(&gSprites[id]);
    }
    DestroySprite(&gSprites[anclaSpriteId]);
    gMarcadorSpriteIds[battlerId] = MAX_SPRITES;
}

u8 CreaMarcadorCombate(u8 battlerId)
{
    DestruyeMarcadorCombate(battlerId);

    u8 anclaSpriteId, rellenoSpriteId, textoSpriteId, estadoSpriteId;
    struct Sprite *ancla;

    // El contorno hace de ancla porque siempre esta presente y marca donde cae
    // la barra; el resto de piezas se colocan en cada fotograma respecto a el.
    anclaSpriteId = CreateSprite(&sPlantillaContornoBarra, ANCHO_PANTALLA, ALTURA_PANTALLA, SUBPRIORIDAD_CONTORNO);
    ancla = &gSprites[anclaSpriteId];
    SetSubspriteTables(ancla, sSubspriteTable_ContornoBarra);
    ancla->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    ancla->invisible = TRUE;
    ancla->callback = SpriteCallbackDummy;

    rellenoSpriteId = CreateSpriteAtEnd(&sPlantillasMarcador[battlerId], ANCHO_PANTALLA, ALTURA_PANTALLA, SUBPRIORIDAD_RELLENO);
    SetSubspriteTables(&gSprites[rellenoSpriteId], sSubspriteTable_RellenoBarra);
    gSprites[rellenoSpriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    gSprites[rellenoSpriteId].oam.tileNum += TILE_RELLENO_BARRA;

    textoSpriteId = CreateSpriteAtEnd(&sPlantillasMarcador[battlerId], ANCHO_PANTALLA, ALTURA_PANTALLA, SUBPRIORIDAD_TEXTO);
    SetSubspriteTables(&gSprites[textoSpriteId], sSubspriteTable_TextoMarcador);
    gSprites[textoSpriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    gSprites[textoSpriteId].oam.tileNum += TILE_TEXTO;

    estadoSpriteId = CreateSpriteAtEnd(&sPlantillaIconoEstado, ANCHO_PANTALLA, ALTURA_PANTALLA, SUBPRIORIDAD_ESTADO);

    for (u32 pieza = 0; pieza < PIEZAS_MARCADOR; pieza++)
    {
        u8 id = (pieza == PIEZA_RELLENO) ? rellenoSpriteId
              : (pieza == PIEZA_TEXTO)   ? textoSpriteId
              :                            estadoSpriteId;

        ancla->sMarcadorPieza(pieza) = id;
        gSprites[id].sPiezaAncla = anclaSpriteId;
        gSprites[id].sPiezaIndice = pieza;
        gSprites[id].callback = SpriteCB_PiezaMarcador;
        gSprites[id].sPiezaTileBase = gSprites[id].oam.tileNum;
        gSprites[id].oam.priority = 1;
        gSprites[id].invisible = TRUE;
        gSprites[id].sPiezaOculta = (pieza == PIEZA_ESTADO);
    }

    ancla->sMarcadorCombatiente = battlerId;

    gCombate->ballSpriteIds[0] = MAX_SPRITES;
    gCombate->ballSpriteIds[1] = MAX_SPRITES;

    return anclaSpriteId;
}

// Desplazamiento de cada pieza respecto al ancla. En una tabla y no repartido por
// callbacks para que la disposicion del marcador se lea de un vistazo.
static const struct { s8 x, y; } sDesplazamientosPiezas[PIEZAS_MARCADOR] =
{
    [PIEZA_RELLENO] = {0, 0},
    [PIEZA_TEXTO]   = {0, TEXTO_DESPLAZAMIENTO_Y},
    [PIEZA_ESTADO]  = {ESTADO_DESPLAZAMIENTO_X, ESTADO_DESPLAZAMIENTO_Y},
};

// Porcentaje de vida, alineado al borde derecho del interior de la barra.

// El marcador entero comparte paleta, asi que basta con recorrer sus piezas.
void FijaPaletaMarcador(u8 marcadorSpriteId, u8 paletteNum)
{
    gSprites[marcadorSpriteId].oam.paletteNum = paletteNum;
    for (u32 pieza = 0; pieza < PIEZAS_MARCADOR; pieza++)
        gSprites[gSprites[marcadorSpriteId].sMarcadorPieza(pieza)].oam.paletteNum = paletteNum;
}

static void SpriteCB_PiezaMarcador(struct Sprite *sprite)
{
    const struct Sprite *ancla = &gSprites[sprite->sPiezaAncla];
    u32 pieza = sprite->sPiezaIndice;

    sprite->x = ancla->x + sDesplazamientosPiezas[pieza].x;
    sprite->y = ancla->y + sDesplazamientosPiezas[pieza].y;
    sprite->x2 = ancla->x2;
    sprite->y2 = ancla->y2;
    sprite->invisible = ancla->invisible || sprite->sPiezaOculta;
    sprite->oam.priority = ancla->oam.priority;
}


void OcultaMarcador(u8 marcadorSpriteId)
{
    gSprites[marcadorSpriteId].invisible = TRUE;
}

void MuestraMarcador(u8 marcadorSpriteId)
{
    gSprites[marcadorSpriteId].invisible = FALSE;
}

static void UpdateSpritePos(u32 spriteId, s16 x, s16 y)
{
    gSprites[spriteId].x = x;
    gSprites[spriteId].y = y;
}

void FijaPrioridadMarcadores(u8 priority, bool32 hideHPBoxes)
{
    s32 i;

    // Basta con tocar el ancla: las piezas copian su prioridad y su visibilidad.
    for (i = 0; i < gBattlersCount; i++)
    {
        gSprites[gMarcadorSpriteIds[i]].oam.priority = priority;

        if (B_HIDE_HEALTHBOX_IN_ANIMS == TRUE && hideHPBoxes && IsBattlerAlive(i))
            gSprites[gMarcadorSpriteIds[i]].invisible = (priority == 0);
    }
}

void CoordenadasMarcador(u8 battler, s16 *x, s16 *y)
{
    // El ancla marca el centro de la barra, no la esquina de ninguna caja.
    switch (battler)
    {
    case JUGADOR_IZQUIERDA:
    default:
        *x = 174, *y = 88;
        break;
    case JUGADOR_DERECHA:
        *x = 187, *y = 101;
        break;
    case OPONENTE_IZQUIERDA:
        *x = 60, *y = 30;
        break;
    case OPONENTE_DERECHA:
        *x = 48, *y = 44;
        break;
    }
}

void ColocaMarcador(u8 battler)
{
    s16 x, y;

    CoordenadasMarcador(battler, &x, &y);
    UpdateSpritePos(gMarcadorSpriteIds[battler], x, y);
}

// Vuelca los tiles de una ventana de texto a los de un sprite. La ventana solo
// es el lienzo donde el renderizador de fuentes dibuja; lo que se ve es el sprite.

// Nombre a la izquierda y nivel a la derecha, en la misma tira de 96x8.


// Nombre pegado a la izquierda y nivel pegado a la derecha, en la misma tira de
// 96x8. Van en dos pasadas porque una sola ventana no da para dos alineaciones.

// La ventana es solo el lienzo donde el renderizador de fuentes dibuja; lo que se
// ve es el sprite. Tiene el mismo ancho que la tira de texto, asi que el texto se
// pinta ya en su x definitiva y solo hay que llevarse las columnas que interesan.
static const struct WindowTemplate sVentanaMarcador = {
    .bg = FONDO_0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = TILES_ANCHO_TEXTO,
    .height = TILES_ALTO_TEXTO,
    .paletteNum = 0,
    .baseBlock = 0
};

// La ventana guarda sus tiles por filas completas, pero un sprite de 32x16 los
// espera agrupados por subsprite: primero sus cuatro de arriba y luego los cuatro
// de abajo. De ahi que haya que recolocarlos columna a columna en vez de copiar
// el bloque de una vez.
static u32 TileDelSprite(u32 columna, u32 fila)
{
    u32 subsprite = columna / TILES_ANCHO_SUBSPRITE;
    u32 dentro    = columna % TILES_ANCHO_SUBSPRITE;

    return subsprite * (TILES_ANCHO_SUBSPRITE * TILES_ALTO_TEXTO)
         + fila * TILES_ANCHO_SUBSPRITE
         + dentro;
}

static void TextoAlSprite(u32 spriteId, const u8 *texto, u32 x, u32 columna, u32 numColumnas)
{
    u8 color[3];
    u16 windowId;
    const u8 *tilesVentana;
    struct WindowTemplate winTemplate = sVentanaMarcador;
    u32 c, fila;

    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));

    color[0] = 0; // fondo transparente
    color[1] = COLOR_TEXTO_MARCADOR;
    color[2] = 0; // sin sombreado

    AddTextPrinterParameterized4(windowId, FONT_SMALL, x, 0, 0, 0, color, TEXT_SKIP_DRAW, texto);
    tilesVentana = (const u8 *)(GetWindowAttribute(windowId, WINDOW_TILE_DATA));

    for (c = columna; c < columna + numColumnas; c++)
    {
        for (fila = 0; fila < TILES_ALTO_TEXTO; fila++)
        {
            u32 origen  = fila * TILES_ANCHO_TEXTO + c;
            u32 destino = gSprites[spriteId].oam.tileNum + TileDelSprite(c, fila);

            CopiaCpu32(tilesVentana + origen * TILE_4BPP,
                       (void *)(OBJ_VRAM0 + destino * TILE_4BPP), TILE_4BPP);
        }
    }

    RemoveWindow(windowId);
}

// Escribe un texto pegado al borde derecho de su tramo de columnas.
static void TextoDerechaAlSprite(u32 spriteId, const u8 *texto, u32 columna, u32 numColumnas)
{
    s32 hueco = numColumnas * 8;
    s32 ancho = GetStringWidth(FONT_SMALL, texto, 0);

    if (ancho > hueco)
        ancho = hueco;

    TextoAlSprite(spriteId, texto, columna * 8 + (hueco - ancho), columna, numColumnas);
}

// Nombre a la izquierda, nivel a continuacion. El porcentaje va en el mismo sprite
// pero lo refresca la barra, que es quien sabe cuanta vida queda.
static void DibujaNombreYNivel(u8 marcadorSpriteId, struct Pokemon *mon)
{
    u8 nombre[POKEMON_NAME_LENGTH + 1];
    u8 nivel[8], *fin;
    u32 textoSpriteId = gSprites[marcadorSpriteId].sMarcadorPieza(PIEZA_TEXTO);

    GetMonData(mon, MON_DATA_NICKNAME, nombre);
    StringGet_Nickname(nombre);
    TextoAlSprite(textoSpriteId, nombre, COL_NOMBRE * 8, COL_NOMBRE, COLS_NOMBRE);

    fin = nivel;
    *fin++ = CHAR_EXTRA_SYMBOL;
    *fin++ = CHAR_LV_2;
    fin = ConvertIntToDecimalStringN(fin, GetMonData(mon, MON_DATA_LEVEL), STR_CONV_MODE_LEFT_ALIGN, 3);
    *fin = EOS;

    TextoDerechaAlSprite(textoSpriteId, nivel, COL_NIVEL, COLS_NIVEL);
}

static void DibujaPorcentajeVida(u8 marcadorSpriteId, u32 porcentaje)
{
    u8 texto[8], *fin;
    u32 textoSpriteId = gSprites[marcadorSpriteId].sMarcadorPieza(PIEZA_TEXTO);

    fin = ConvertIntToDecimalStringN(texto, porcentaje, STR_CONV_MODE_LEFT_ALIGN, 3);
    *fin++ = CHAR_PERCENT;
    *fin = EOS;

    TextoDerechaAlSprite(textoSpriteId, texto, COL_PORCENTAJE, COLS_PORCENTAJE);
}

static void DibujaIconoEstado(u8 marcadorSpriteId)
{
    u32 battlerId = gSprites[marcadorSpriteId].sMarcadorCombatiente;
    u32 estadoSpriteId = gSprites[marcadorSpriteId].sMarcadorPieza(PIEZA_ESTADO);
    struct Pokemon *party = (GetBattlerSide(battlerId) == LADO_JUGADOR) ? gPlayerParty : gEnemyParty;
    u32 status = GetMonData(&party[gBattlerPartyIndexes[battlerId]], MON_DATA_STATUS);
    u32 icono;

    if (status & STATUS1_SLEEP)
        icono = ICONO_ESTADO_SLP;
    else if (status & STATUS1_PSN_ANY)
        icono = ICONO_ESTADO_PSN;
    else if (status & STATUS1_BURN)
        icono = ICONO_ESTADO_BRN;
    else if (status & STATUS1_CONGELACION)
        icono = ICONO_ESTADO_FRZ;
    else if (status & STATUS1_PARALYSIS)
        icono = ICONO_ESTADO_PRZ;
    else
    {
        // Sin estado alterado no hay icono: el sprite se apaga y ya esta. Antes
        // habia que copiar un tile "en blanco" y ajustar un color de paleta.
        gSprites[estadoSpriteId].sPiezaOculta = TRUE;
        return;
    }

    // La hoja de iconos es una sola para los cuatro combatientes, asi que hay que
    // apuntar al icono que toca, no copiarlo: copiarlo pisaria el de los demas.
    gSprites[estadoSpriteId].oam.tileNum = gSprites[estadoSpriteId].sPiezaTileBase
                                         + icono * TILES_POR_ICONO_ESTADO;
    gSprites[estadoSpriteId].sPiezaOculta = FALSE;
}

void ActualizaMarcador(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId)
{
    // Los dos lados se tratan igual: sin cifras de PS ni barra de experiencia no
    // queda ninguna diferencia entre el marcador del jugador y el del rival.
    u32 battlerId = gSprites[healthboxSpriteId].sMarcadorCombatiente;


    if (elementId == MARCADOR_BARRA || elementId == MARCADOR_TODO)
    {
        SetBattleBarStruct(battlerId, healthboxSpriteId, GetMonData(mon, MON_DATA_MAX_HP), GetMonData(mon, MON_DATA_HP), 0);
        MoveBattleBar(battlerId, healthboxSpriteId);
    }

    // Nombre y nivel comparten tira de tiles, asi que se dibujan de una vez.
    if (elementId == MARCADOR_NOMBRE || elementId == MARCADOR_NIVEL || elementId == MARCADOR_TODO)
        DibujaNombreYNivel(healthboxSpriteId, mon);

    if (elementId == MARCADOR_ESTADO || elementId == MARCADOR_TODO)
        DibujaIconoEstado(healthboxSpriteId);
}

// Interior de la barra: 80 pixeles = 10 tiles de 8x8. En base 10 para que el
// porcentaje y el relleno salgan de la misma cuenta, sin ajustes raros.
#define B_HEALTHBAR_PIXELS 80
#define TILES_BARRA_SALUD  (B_HEALTHBAR_PIXELS / 8)

// Grosor del relleno dentro de la fila de tiles, centrado. Bajarlo adelgaza la
// barra sin tocar nada mas; el interior de barra_salud.png tiene que acompanar.
#define ALTO_RELLENO_BARRA 4

// Indices dentro de la paleta de barra_salud.png. El relleno no tiene grafico
// propio: los tiles se construyen en codigo, que solo escribe estos indices.
#define COLOR_BARRA_VERDE    2
#define COLOR_BARRA_AMARILLO 3
#define COLOR_BARRA_ROJO     4

// Umbrales de cambio de color, en porcentaje de vida restante.
#define UMBRAL_BARRA_VERDE    50
#define UMBRAL_BARRA_AMARILLO 25



// Construye un tile 4bpp de 8x8 con los primeros pixeles de cada fila pintados
// del color indicado y el resto transparente. Sustituye a las variantes de relleno
// que antes venian de hpbar_anim: aqui la precision es de 1 pixel y no hace falta
// ningun grafico.
static void ConstruyeTileBarra(u8 *destino, u32 pixelesLlenos, u32 indiceColor)
{
    u32 fila, byte;

    for (fila = 0; fila < 8; fila++)
    {
        // Fuera del grosor elegido la fila se queda transparente.
        bool32 filaPintada = (fila >= (8 - ALTO_RELLENO_BARRA) / 2)
                          && (fila <  (8 - ALTO_RELLENO_BARRA) / 2 + ALTO_RELLENO_BARRA);

        for (byte = 0; byte < 4; byte++)
        {
            // Cada byte guarda dos pixeles: nibble bajo el izquierdo, alto el derecho.
            u32 pixelIzquierdo = byte * 2;
            u8 valor = 0;

            if (filaPintada && pixelIzquierdo < pixelesLlenos)
                valor |= indiceColor;
            if (filaPintada && pixelIzquierdo + 1 < pixelesLlenos)
                valor |= indiceColor << 4;

            destino[fila * 4 + byte] = valor;
        }
    }
}

void SetBattleBarStruct(u8 battlerId, u8 marcadorSpriteId, s32 maxVal, s32 oldVal, s32 receivedValue)
{
    gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId = marcadorSpriteId;
    gBattleSpritesDataPtr->battleBars[battlerId].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[battlerId].oldValue = oldVal;
    gBattleSpritesDataPtr->battleBars[battlerId].receivedValue = receivedValue;
    gBattleSpritesDataPtr->battleBars[battlerId].currValue = -32768;
}

s32 MoveBattleBar(u8 battlerId, u8 healthboxSpriteId)
{
    u16 hpFraction = B_FAST_HP_DRAIN == FALSE ? 1 : max(gBattleSpritesDataPtr->battleBars[battlerId].maxValue / (B_HEALTHBAR_PIXELS / 2), 1);
    s32 currentBarValue = CalcNewBarValue(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                TILES_BARRA_SALUD, hpFraction);

    MoveBattleBarGraphically(battlerId);

    if (currentBarValue == -1)
        gBattleSpritesDataPtr->battleBars[battlerId].currValue = 0;

    return currentBarValue;
}

// Porcentaje de vida que se muestra dentro de la barra, con precision de 1 %.
// No se saca de los pixeles llenos porque 80 pixeles solo darian saltos de 1,25 %.
static u32 PorcentajeVidaMostrado(u8 battlerId)
{
    s32 maximo = gBattleSpritesDataPtr->battleBars[battlerId].maxValue;
    s32 actual = gBattleSpritesDataPtr->battleBars[battlerId].currValue;
    u32 porcentaje;

    if (maximo <= 0)
        return 0;

    // CalcNewBarValue guarda el valor en coma fija cuando el maximo no llega a
    // cubrir un pixel por punto de vida.
    if (maximo < B_HEALTHBAR_PIXELS)
        actual = Q_24_8_TO_INT(actual);
    if (actual <= 0)
        return 0;

    porcentaje = (actual * 100) / maximo;
    // Mientras quede un solo punto de vida la barra no debe anunciar 0 %.
    if (porcentaje == 0)
        porcentaje = 1;

    return porcentaje;
}

static void MoveBattleBarGraphically(u8 battlerId)
{
    u8 pixelesPorTile[TILES_BARRA_SALUD];
    ALIGNED(4) u8 tile[TILE_4BPP]; // CopiaCpu32 exige alineacion a 4 bytes
    u32 color, i, porcentaje;
    u8 marcadorSpriteId, healthbarSpriteId;

    CalcBarFilledPixels(gBattleSpritesDataPtr->battleBars[battlerId].maxValue,
                        gBattleSpritesDataPtr->battleBars[battlerId].oldValue,
                        gBattleSpritesDataPtr->battleBars[battlerId].receivedValue,
                        &gBattleSpritesDataPtr->battleBars[battlerId].currValue,
                        pixelesPorTile, TILES_BARRA_SALUD);

    porcentaje = PorcentajeVidaMostrado(battlerId);
    if (porcentaje > UMBRAL_BARRA_VERDE)
        color = COLOR_BARRA_VERDE;
    else if (porcentaje > UMBRAL_BARRA_AMARILLO)
        color = COLOR_BARRA_AMARILLO;
    else
        color = COLOR_BARRA_ROJO;

    marcadorSpriteId = gBattleSpritesDataPtr->battleBars[battlerId].healthboxSpriteId;
    healthbarSpriteId = gSprites[marcadorSpriteId].sMarcadorPieza(PIEZA_RELLENO);

    for (i = 0; i < TILES_BARRA_SALUD; i++)
    {
        ConstruyeTileBarra(tile, pixelesPorTile[i], color);
        CopiaCpu32(tile, (void *)(OBJ_VRAM0 + (gSprites[healthbarSpriteId].oam.tileNum + i) * TILE_4BPP), TILE_4BPP);
    }

    DibujaPorcentajeVida(marcadorSpriteId, porcentaje);
}

static s32 CalcNewBarValue(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 scale, u16 toAdd)
{
    s32 ret, newValue;
    scale *= 8;

    if (*currValue == -32768) // first function call
    {
        if (maxValue < scale)
            *currValue = Q_24_8(oldValue);
        else
            *currValue = oldValue;
    }

    newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    if (maxValue < scale)
    {
        if (newValue == Q_24_8_TO_INT(*currValue) && (*currValue & 0xFF) == 0)
            return -1;
    }
    else
    {
        if (newValue == *currValue) // we're done, the bar's value has been updated
            return -1;
    }

    if (maxValue < scale) // handle cases of max var having less pixels than the whole bar
    {
        s32 toAdd = Q_24_8(maxValue) / scale;

        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            if (ret >= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
        else // move bar left
        {
            *currValue -= toAdd;
            ret = Q_24_8_TO_INT(*currValue);
            // try round up
            if ((*currValue & 0xFF) > 0)
                ret++;
            if (ret <= newValue)
            {
                *currValue = Q_24_8(newValue);
                ret = newValue;
            }
        }
    }
    else
    {
        if (receivedValue < 0) // fill bar right
        {
            *currValue += toAdd;
            if (*currValue > newValue)
                *currValue = newValue;
            ret = *currValue;
        }
        else // move bar left
        {
            *currValue -= toAdd;
            if (*currValue < newValue)
                *currValue = newValue;
            ret = *currValue;
        }
    }

    return ret;
}

static u8 CalcBarFilledPixels(s32 maxValue, s32 oldValue, s32 receivedValue, s32 *currValue, u8 *pixelsArray, u8 scale)
{
    u8 pixels, filledPixels, totalPixels;
    u32 i;

    s32 newValue = oldValue - receivedValue;
    if (newValue < 0)
        newValue = 0;
    else if (newValue > maxValue)
        newValue = maxValue;

    totalPixels = scale * 8;

    for (i = 0; i < scale; i++)
        pixelsArray[i] = 0;

    if (maxValue < totalPixels)
        pixels = (*currValue * totalPixels / maxValue) >> 8;
    else
        pixels = *currValue * totalPixels / maxValue;

    filledPixels = pixels;

    if (filledPixels == 0 && newValue > 0)
    {
        pixelsArray[0] = 1;
        filledPixels = 1;
    }
    else
    {
        for (i = 0; i < scale; i++)
        {
            if (pixels >= 8)
            {
                pixelsArray[i] = 8;
            }
            else
            {
                pixelsArray[i] = pixels;
                break;
            }
            pixels -= 8;
        }
    }

    return filledPixels;
}


u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale)
{
    u8 result = hp * scale / maxhp;

    if (result == 0 && hp > 0)
        return 1;

    return result;
}

u8 GetHPBarLevel(s16 hp, s16 maxhp)
{
    u8 result;

    if (hp == maxhp)
    {
        result = HP_BAR_FULL;
    }
    else
    {
        u8 fraction = GetScaledHPFraction(hp, maxhp, B_HEALTHBAR_PIXELS);
        if (fraction > (B_HEALTHBAR_PIXELS * UMBRAL_BARRA_VERDE / 100))
            result = HP_BAR_GREEN;
        else if (fraction > (B_HEALTHBAR_PIXELS * UMBRAL_BARRA_AMARILLO / 100))
            result = HP_BAR_YELLOW;
        else if (fraction > 0)
            result = HP_BAR_RED;
        else
            result = HP_BAR_EMPTY;
    }

    return result;
}








#define ABILITY_POP_UP_TAG 0xD720

// for sprite
#define tOriginalX      data[0]
#define tHide           data[1]
#define tFrames         data[2]
#define tRightToLeft    data[3]
#define tBattlerId      data[4]
#define tIsMain         data[5]

// for task
#define tSpriteId1      data[6]
#define tSpriteId2      data[7]

static const u8 ALIGNED(4) sAbilityPopUpGfx[] = INCBIN_U8("graphics/battle_interface/ability_pop_up.4bpp");
static const u16 sAbilityPopUpPalette[] = INCBIN_U16("graphics/battle_interface/ability_pop_up.gbapal");

static const struct SpriteSheet sSpriteSheet_AbilityPopUp =
{
    sAbilityPopUpGfx, sizeof(sAbilityPopUpGfx), ABILITY_POP_UP_TAG
};
static const struct SpritePalette sSpritePalette_AbilityPopUp =
{
    sAbilityPopUpPalette, ABILITY_POP_UP_TAG
};

static const struct OamData sOamData_AbilityPopUp =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_AbilityPopUp =
{
    .tileTag = ABILITY_POP_UP_TAG,
    .paletteTag = ABILITY_POP_UP_TAG,
    .oam = &sOamData_AbilityPopUp,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_AbilityPopUp
};

#define ABILITY_POP_UP_POS_X_DIFF (64 - 7) // Hide second sprite underneath to gain proper letter spacing
#define ABILITY_POP_UP_POS_X_SLIDE 68

static const s16 sAbilityPopUpCoordsDoubles[NUMERO_COMBATIENTES][2] =
{
    {29, 80}, // player left
    {186, 19}, // opponent left
    {29, 97}, // player right
    {186, 36}, // opponent right
};

static const s16 sAbilityPopUpCoordsSingles[NUMERO_COMBATIENTES][2] =
{
    {29, 97}, // player
    {186, 57}, // opponent
};

#define POPUP_WINDOW_WIDTH 8
#define MAX_POPUP_STRING_WIDTH (POPUP_WINDOW_WIDTH * 8)

static u8* AddTextPrinterAndCreateWindowOnAbilityPopUp(const u8 *str, u32 x, u32 y, u32 color1, u32 color2, u32 color3, u32 *windowId)
{
    u32 fontId;
    u8 color[3] = {color1, color2, color3};
    struct WindowTemplate winTemplate = {0};
    winTemplate.width = POPUP_WINDOW_WIDTH;
    winTemplate.height = 2;

    *windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(*windowId, PIXEL_FILL(color1));

    fontId = GetFontIdToFit(str, FONT_SMALL, 0, 76);
    AddTextPrinterParameterized4(*windowId, fontId, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
    return (u8 *)(GetWindowAttribute(*windowId, WINDOW_TILE_DATA));
}

static void TextIntoAbilityPopUp(void *dest, u8 *windowTileData, s32 xTileAmount, bool32 arg3)
{
    CopiaCpu32(windowTileData + 256, dest + 256, xTileAmount * 32);
    if (xTileAmount > 0)
    {
        do
        {
            if (arg3)
                CopiaCpu32(windowTileData + 16, dest + 16, 16);
            else
                CopiaCpu32(windowTileData + 20, dest + 20, 12);
            dest += 32, windowTileData += 32;
            xTileAmount--;
        } while (xTileAmount != 0);
    }
}

static void PrintOnAbilityPopUp(const u8 *str, u8 *spriteTileData1, u8 *spriteTileData2, u32 x1, u32 x2, u32 y, u32 color1, u32 color2, u32 color3)
{
    u32 windowId;
    u8 *windowTileData;
    u16 width;

    windowTileData = AddTextPrinterAndCreateWindowOnAbilityPopUp(str, x1, y, color1, color2, color3, &windowId);
    TextIntoAbilityPopUp(spriteTileData1, windowTileData, 8, (y == 0));
    RemoveWindow(windowId);

    width = GetStringWidth(FONT_SMALL, str, 0);

    if (width > MAX_POPUP_STRING_WIDTH - 5)
    {
        windowTileData = AddTextPrinterAndCreateWindowOnAbilityPopUp(str, x2 - MAX_POPUP_STRING_WIDTH, y, color1, color2, color3, &windowId);
        TextIntoAbilityPopUp(spriteTileData2, windowTileData, 3, (y == 0));
        RemoveWindow(windowId);
    }
}

static const u8 sText_Spaces20[]= _("                    ");
static void ClearAbilityName(u32 spriteId1, u32 spriteId2)
{
    PrintOnAbilityPopUp(sText_Spaces20,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32) + 256,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32) + 256,
                        5, 12,
                        4,
                        7, 9, 1);
}

static void PrintBattlerOnAbilityPopUp(u8 battlerId, u32 spriteId1, u32 spriteId2)
{
    u32 i;
    u8* textPtr;
    u8 monName[POKEMON_NAME_LENGTH + 3] = {0};
    u8* nick = gBattleMons[battlerId].nickname;

    for (i = 0; i < POKEMON_NAME_LENGTH; ++i)
    {
        monName[i] = nick[i];

        if (nick[i] == EOS || i + 1 == POKEMON_NAME_LENGTH) // End of string
            break;
    }

    textPtr = monName + i + 1;

    if (*(textPtr - 1) == EOS)
        textPtr--;

    PrintOnAbilityPopUp((const u8 *)monName,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32),
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32),
                        5, 12,
                        0,
                        2, 7, 1);
}

static void PrintAbilityOnAbilityPopUp(u32 ability, u32 spriteId1, u32 spriteId2)
{
    ClearAbilityName(spriteId1, spriteId2);
    PrintOnAbilityPopUp(gAbilitiesInfo[ability].name,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * 32) + 256,
                        (void*)(OBJ_VRAM0) + (gSprites[spriteId2].oam.tileNum * 32) + 256,
                        5, 12,
                        4,
                        7, 9, 1);
}

#define PIXEL_COORDS_TO_OFFSET(x, y)(            \
/*Add tiles by X*/                                \
((y / 8) * 32 * 8)                                \
/*Add tiles by X*/                                \
+ ((x / 8) * 32)                                \
/*Add pixels by Y*/                                \
+ ((((y) - ((y / 8) * 8))) * 4)                    \
/*Add pixels by X*/                                \
+ ((((x) - ((x / 8) * 8)) / 2)))

static const u16 sOverwrittenPixelsTable[][2] =
{
    {PIXEL_COORDS_TO_OFFSET(0, 0), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 1), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 2), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 3), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 4), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 5), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 6), 5},
    {PIXEL_COORDS_TO_OFFSET(0, 7), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 8), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 9), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 10), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 11), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 12), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 13), 8},

    {PIXEL_COORDS_TO_OFFSET(8, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(24, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(32, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(40, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(48, 13), 8},
    {PIXEL_COORDS_TO_OFFSET(56, 13), 8},

    {PIXEL_COORDS_TO_OFFSET(0, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(24, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(32, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(40, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(48, 14), 8},
    {PIXEL_COORDS_TO_OFFSET(56, 14), 8},

    {PIXEL_COORDS_TO_OFFSET(0, 15), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 16), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 17), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 18), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 19), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 20), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 21), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 22), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 23), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 24), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 25), 3},
    {PIXEL_COORDS_TO_OFFSET(0, 26), 3},

//Second Row Of Image
    {PIXEL_COORDS_TO_OFFSET(0, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(0, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(0, 47), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(8, 47), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 45), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 46), 8},
    {PIXEL_COORDS_TO_OFFSET(16, 47), 8},
};

static inline void CopyPixels(u8 *dest, const u8 *src, u32 pixelCount)
{
    u32 i = 0;

    if (pixelCount & 1)
    {
        while (pixelCount != 0)
        {
            dest[i] &= ~(0xF);
            dest[i] |= (src[i] & 0xF);
            if (--pixelCount != 0)
            {
                dest[i] &= ~(0xF0);
                dest[i] |= (src[i] & 0xF0);
                pixelCount--;
            }
            i++;
        }
    }
    else
    {
        for (i = 0; i < pixelCount / 2; i++)
            dest[i] = src[i];
    }
}

static void RestoreOverwrittenPixels(u8 *tiles)
{
    u32 i;
    u8 *buffer = Alloc(sizeof(sAbilityPopUpGfx) * 2);

    CopiaCpu32(tiles, buffer, sizeof(sAbilityPopUpGfx));

    for (i = 0; i < ARRAY_COUNT(sOverwrittenPixelsTable); i++)
    {
        CopyPixels(buffer + sOverwrittenPixelsTable[i][0],
                   sAbilityPopUpGfx + sOverwrittenPixelsTable[i][0],
                   sOverwrittenPixelsTable[i][1]);
    }

    CopiaCpu32(buffer, tiles, sizeof(sAbilityPopUpGfx));
    Free(buffer);
}

void CreaMensajeHabilidad(u32 combatiente, u32 habilidad)
{
    const s16 (*coords)[2];
    u32 spriteId1, spriteId2, battlerPosition, taskId;

    if (gBattleScripting.abilityPopupOverwrite != 0)
        habilidad = gBattleScripting.abilityPopupOverwrite;

    if (!gCombate->activeAbilityPopUps)
    {
        LoadSpriteSheet(&sSpriteSheet_AbilityPopUp);
        LoadSpritePalette(&sSpritePalette_AbilityPopUp);
    }
    gCombate->activeAbilityPopUps |= 1u << combatiente;
    battlerPosition = combatiente;

    if ((EsCombateContraEntrenador(gCombate->tipoCombate)))
        coords = sAbilityPopUpCoordsDoubles;
    else
        coords = sAbilityPopUpCoordsSingles;

    if ((battlerPosition & BIT_SIDE) == LADO_JUGADOR)
    {
        spriteId1 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] - ABILITY_POP_UP_POS_X_SLIDE,
                                coords[battlerPosition][1], 0);
        spriteId2 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] - ABILITY_POP_UP_POS_X_SLIDE + ABILITY_POP_UP_POS_X_DIFF,
                                coords[battlerPosition][1], 1); //Appears below

        gSprites[spriteId1].tRightToLeft = TRUE;
        gSprites[spriteId2].tRightToLeft = TRUE;
    }
    else
    {
        spriteId1 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_SLIDE,
                                coords[battlerPosition][1], 0);
        spriteId2 = CreateSprite(&sSpriteTemplate_AbilityPopUp,
                                coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_SLIDE + ABILITY_POP_UP_POS_X_DIFF,
                                coords[battlerPosition][1], 1); //Appears below

        gSprites[spriteId1].tRightToLeft = FALSE;
        gSprites[spriteId2].tRightToLeft = FALSE;
    }

    gSprites[spriteId1].tOriginalX = coords[battlerPosition][0];
    gSprites[spriteId2].tOriginalX = coords[battlerPosition][0] + ABILITY_POP_UP_POS_X_DIFF;
    gSprites[spriteId2].oam.tileNum += (8 * 4); //Second half of pop up 

    gCombate->abilityPopUpSpriteIds[combatiente][0] = spriteId1;
    gCombate->abilityPopUpSpriteIds[combatiente][1] = spriteId2;

    taskId = CreateTask(Task_FreeAbilityPopUpGfx, 5);
    gTasks[taskId].tSpriteId1 = spriteId1;
    gTasks[taskId].tSpriteId2 = spriteId2;

    gSprites[spriteId1].tIsMain = TRUE;
    gSprites[spriteId1].tBattlerId = combatiente;
    gSprites[spriteId2].tBattlerId = combatiente;

    StartSpriteAnim(&gSprites[spriteId1], 0);
    StartSpriteAnim(&gSprites[spriteId2], 0);

    PrintBattlerOnAbilityPopUp(combatiente, spriteId1, spriteId2);
    PrintAbilityOnAbilityPopUp(habilidad, spriteId1, spriteId2);
    RestoreOverwrittenPixels((void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * TILE_4BPP));
}

void ActualizaVentanaHabilidad(u32 combatiente)
{
    u32 spriteId1 = gCombate->abilityPopUpSpriteIds[combatiente][0];
    u32 spriteId2 = gCombate->abilityPopUpSpriteIds[combatiente][1];
    u32 habilidad = (gBattleScripting.abilityPopupOverwrite != 0) ? gBattleScripting.abilityPopupOverwrite : gBattleMons[combatiente].ability;
    PrintAbilityOnAbilityPopUp(habilidad, spriteId1, spriteId2);
    RestoreOverwrittenPixels((void*)(OBJ_VRAM0) + (gSprites[spriteId1].oam.tileNum * TILE_4BPP));
}

#define FRAMES_TO_WAIT 48

static void SpriteCb_AbilityPopUp(struct Sprite *sprite)
{
    if (!sprite->tHide) // Show
    {
        if (sprite->tIsMain && ++sprite->tFrames == 4)
            PlaySE(SE_BALL_TRAY_ENTER);
        if ((!sprite->tRightToLeft && (sprite->x -= 4) <= sprite->tOriginalX)
            || (sprite->tRightToLeft && (sprite->x += 4) >= sprite->tOriginalX)
           )
        {
            sprite->x = sprite->tOriginalX;
            sprite->tHide = TRUE;
            sprite->tFrames = FRAMES_TO_WAIT;
        }
    }
    else // Hide
    {
        if (sprite->tFrames == 0)
        {
            if ((!sprite->tRightToLeft && (sprite->x += 4) >= sprite->tOriginalX + ABILITY_POP_UP_POS_X_SLIDE)
                ||(sprite->tRightToLeft && (sprite->x -= 4) <= sprite->tOriginalX - ABILITY_POP_UP_POS_X_SLIDE)
               )
            {
                gCombate->activeAbilityPopUps &= ~(1u << sprite->tBattlerId);
                DestroySprite(sprite);
            }
        }
        else
        {
            if (!gBattleScripting.fixedPopup)
                sprite->tFrames--;
        }
    }
}

void DestruyeMensajeHabilidad(u32 combatiente)
{
    if (gCombate->activeAbilityPopUps & (1u << combatiente))
    {
        gSprites[gCombate->abilityPopUpSpriteIds[combatiente][0]].tFrames = 0;
        gSprites[gCombate->abilityPopUpSpriteIds[combatiente][1]].tFrames = 0;
    }
    gBattleScripting.fixedPopup = FALSE;
}

static void Task_FreeAbilityPopUpGfx(u8 taskId)
{
    if (!gSprites[gTasks[taskId].tSpriteId1].inUse
        && !gSprites[gTasks[taskId].tSpriteId2].inUse
        && !gCombate->activeAbilityPopUps)
    {
        FreeSpriteTilesByTag(ABILITY_POP_UP_TAG);
        FreeSpritePaletteByTag(ABILITY_POP_UP_TAG);
        DestroyTask(taskId);
    }
}

// last used ball
#define LAST_BALL_WINDOW_TAG 0xD721

static const struct OamData sOamData_LastUsedBall =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = (B_LAST_USED_BALL_CYCLE == TRUE ? SPRITE_SHAPE(32x64) : SPRITE_SHAPE(32x32)),
    .x = 0,
    .matrixNum = 0,
    .size = (B_LAST_USED_BALL_CYCLE == TRUE ? SPRITE_SIZE(32x64) : SPRITE_SIZE(32x32)),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_LastUsedBallWindow =
{
    .tileTag = LAST_BALL_WINDOW_TAG,
    .paletteTag = ABILITY_POP_UP_TAG,
    .oam = &sOamData_LastUsedBall,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_LastUsedBallWin
};

#if B_LAST_USED_BALL_BUTTON == R_BUTTON && B_LAST_USED_BALL_CYCLE == TRUE
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_r_cycle.4bpp");
#elif B_LAST_USED_BALL_CYCLE == TRUE
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_l_cycle.4bpp");
#elif B_LAST_USED_BALL_BUTTON == R_BUTTON
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_r.4bpp");
#else
    static const u8 ALIGNED(4) sLastUsedBallWindowGfx[] = INCBIN_U8("graphics/battle_interface/last_used_ball_l.4bpp");
#endif
static const struct SpriteSheet sSpriteSheet_LastUsedBallWindow =
{
    sLastUsedBallWindowGfx, sizeof(sLastUsedBallWindowGfx), LAST_BALL_WINDOW_TAG
};

#define LAST_USED_BALL_X_F    14
#define LAST_USED_BALL_X_0    -14
#define LAST_USED_BALL_Y      ((EsCombateContraEntrenador(gCombate->tipoCombate)) ? 78 : 68)
#define LAST_USED_BALL_Y_BNC  ((EsCombateContraEntrenador(gCombate->tipoCombate)) ? 76 : 66)

#define LAST_BALL_WIN_X_F       (LAST_USED_BALL_X_F - 0)
#define LAST_BALL_WIN_X_0       (LAST_USED_BALL_X_0 - 0)
#define LAST_USED_WIN_Y         (LAST_USED_BALL_Y - 8)

#define sHide  data[0]
#define sTimer  data[1]
#define sMoving data[2]
#define sBounce data[3] // 0 = Bounce down; 1 = Bounce up

#define sState     data[0]
#define sSameBall  data[1]

bool32 CanThrowLastUsedBall(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return FALSE;
    if (!CanThrowBall())
        return FALSE;
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        return FALSE;
    if (!CheckBagHasItem(gBallToDisplay, 1))
        return FALSE;

    return TRUE;
}

void TryAddLastUsedBallItemSprites(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return;
    if (gLastThrownBall == 0
      || (gLastThrownBall != 0 && !CheckBagHasItem(gLastThrownBall, 1)))
    {
        // we're out of the last used ball, so just set it to the first ball in the bag
        u16 firstBall;

        // we have to compact the bag first bc it is typically only compacted when you open it
        CompactItemsInBagPocket(&gBagPockets[BALLS_POCKET]);

        firstBall = gBagPockets[BALLS_POCKET].itemSlots[0].itemId;
        if (firstBall > ITEM_NONE)
            gBallToDisplay = firstBall;
    }

    if (!CanThrowLastUsedBall())
        return;

    // ball
    if (gCombate->ballSpriteIds[0] == MAX_SPRITES)
    {
        gCombate->ballSpriteIds[0] = AddItemIconSprite(102, 102, gBallToDisplay);
        gSprites[gCombate->ballSpriteIds[0]].x = LAST_USED_BALL_X_0;
        gSprites[gCombate->ballSpriteIds[0]].y = LAST_USED_BALL_Y;
        gSprites[gCombate->ballSpriteIds[0]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
        gSprites[gCombate->ballSpriteIds[0]].callback = SpriteCB_LastUsedBall;
    }

    // window
    LoadSpritePalette(&sSpritePalette_AbilityPopUp);
    if (GetSpriteTileStartByTag(LAST_BALL_WINDOW_TAG) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_LastUsedBallWindow);

    if (gCombate->ballSpriteIds[1] == MAX_SPRITES)
    {
        gCombate->ballSpriteIds[1] = CreateSprite(&sSpriteTemplate_LastUsedBallWindow,
                                                       LAST_BALL_WIN_X_0,
                                                       LAST_USED_WIN_Y, 5);
        gSprites[gCombate->ballSpriteIds[1]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
    }
    if (B_LAST_USED_BALL_CYCLE == TRUE)
        ArrowsChangeColorLastBallCycle(0); //Default the arrows to be invisible
}

static void DestroyLastUsedBallWinGfx(struct Sprite *sprite)
{
    FreeSpriteTilesByTag(LAST_BALL_WINDOW_TAG);
    FreeSpritePaletteByTag(ABILITY_POP_UP_TAG);
    DestroySprite(sprite);
    gCombate->ballSpriteIds[1] = MAX_SPRITES;
}

static void DestroyLastUsedBallGfx(struct Sprite *sprite)
{
    FreeSpriteTilesByTag(102);
    FreeSpritePaletteByTag(102);
    DestroySprite(sprite);
    gCombate->ballSpriteIds[0] = MAX_SPRITES;
}

static void SpriteCB_LastUsedBallWin(struct Sprite *sprite)
{
    if (sprite->sHide)
    {
        if (sprite->x != LAST_BALL_WIN_X_0)
            sprite->x--;

        if (sprite->x == LAST_BALL_WIN_X_0)
            DestroyLastUsedBallWinGfx(sprite);
    }
    else
    {
        if (sprite->x != LAST_BALL_WIN_X_F)
            sprite->x++;
    }
}

static void SpriteCB_LastUsedBall(struct Sprite *sprite)
{
    if (sprite->sHide)
    {
        if (sprite->y < LAST_USED_BALL_Y) // Used to recover from an incomplete bounce before hiding the window
            sprite->y++;

        if (sprite->x != LAST_USED_BALL_X_0)
            sprite->x--;

        if (sprite->x == LAST_USED_BALL_X_0)
            DestroyLastUsedBallGfx(sprite);
    }
    else
    {
        if (sprite->x != LAST_USED_BALL_X_F)
            sprite->x++;
    }
}

static void TryHideOrRestoreLastUsedBall(u8 caseId)
{
    if (B_LAST_USED_BALL == FALSE)
        return;
    if (gCombate->ballSpriteIds[0] == MAX_SPRITES)
        return;

    switch (caseId)
    {
    case 0: // hide
        if (gCombate->ballSpriteIds[0] != MAX_SPRITES)
            gSprites[gCombate->ballSpriteIds[0]].sHide = TRUE;   // hide
        if (gCombate->ballSpriteIds[1] != MAX_SPRITES)
            gSprites[gCombate->ballSpriteIds[1]].sHide = TRUE;   // hide
        gLastUsedBallMenuPresent = FALSE;
        break;
    case 1: // restore
        if (gCombate->ballSpriteIds[0] != MAX_SPRITES)
            gSprites[gCombate->ballSpriteIds[0]].sHide = FALSE;   // restore
        if (gCombate->ballSpriteIds[1] != MAX_SPRITES)
            gSprites[gCombate->ballSpriteIds[1]].sHide = FALSE;   // restore
        gLastUsedBallMenuPresent = TRUE;
        break;
    }
    if (B_LAST_USED_BALL_CYCLE == TRUE)
        ArrowsChangeColorLastBallCycle(0); //Default the arrows to be invisible
}

void TryHideLastUsedBall(void)
{
    if (B_LAST_USED_BALL == TRUE)
        TryHideOrRestoreLastUsedBall(0);
}

void TryRestoreLastUsedBall(void)
{
    if (B_LAST_USED_BALL == FALSE)
        return;

    if (gCombate->ballSpriteIds[0] != MAX_SPRITES)
        TryHideOrRestoreLastUsedBall(1);
    else
        TryAddLastUsedBallItemSprites();
}

static void SpriteCB_LastUsedBallBounce(struct Sprite *sprite)
{
    if ((sprite->sTimer++ % 4) != 0)  // Change the image every 4 frame
        return;
    if (sprite->sBounce)
    {
        if (sprite->y > LAST_USED_BALL_Y_BNC)
            sprite->y--;
        else
            sprite->sMoving = FALSE;
    }
    else
    {
        if (sprite->y < LAST_USED_BALL_Y)
            sprite->y++;
        else
            sprite->sMoving = FALSE;
    }
}

static void Task_BounceBall(u8 taskId)
{
    struct Sprite *sprite = &gSprites[gCombate->ballSpriteIds[0]];
    struct Task *task = &gTasks[taskId];
    switch(task->sState)
    {
    case 0:  // Bounce up
        sprite->sBounce = TRUE;
        sprite->sMoving = TRUE;
        sprite->callback = SpriteCB_LastUsedBallBounce;
        if (task->sSameBall)
            task->sState = 3;
        else
            task->sState = 1;
        break;
    case 1:  // Destroy Icon
        if (!sprite->sMoving)
        {
            DestroyLastUsedBallGfx(sprite);
            task->sState++;
        }  // Passthrough
    case 2: //Create New Icon
        if (!sprite->inUse)
        {
            gCombate->ballSpriteIds[0] = AddItemIconSprite(102, 102, gBallToDisplay);
            gSprites[gCombate->ballSpriteIds[0]].x = LAST_USED_BALL_X_F;
            gSprites[gCombate->ballSpriteIds[0]].y = LAST_USED_BALL_Y_BNC;
            task->sState++;
        }  // Fallthrough
    case 3: // Bounce Down
        if (!sprite->sMoving)
        {
            sprite->sBounce = FALSE;
            sprite->sMoving = TRUE;
            sprite->callback = SpriteCB_LastUsedBallBounce; //Show and bounce down
            task->sState++;
        }
        break;
    case 4:  // Destroy Task
        if(!sprite->sMoving)
        {
            sprite->callback = SpriteCB_LastUsedBall;
            DestroyTask(taskId);
        }
    }
    if (!gLastUsedBallMenuPresent)
    {
        // Used to check if the R button was released before the animation was complete
        sprite->callback = SpriteCB_LastUsedBall;
        DestroyTask(taskId);
    }
}

void SwapBallToDisplay(bool32 sameBall)
{
    u8 taskId;
    taskId = CreateTask(Task_BounceBall, 10);
    gTasks[taskId].sSameBall = sameBall;
}

void ArrowsChangeColorLastBallCycle(bool32 showArrows)
{
#if B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == TRUE
    u16 paletteNum = 16 + gSprites[gCombate->ballSpriteIds[1]].oam.paletteNum;
    struct PlttData *defaultPlttArrow;
    struct PlttData *defaultPlttOutline;
    struct PlttData *pltArrow;
    struct PlttData *pltOutline;
    if (gCombate->ballSpriteIds[1] == MAX_SPRITES)
        return;
    u16 paletteOffset = PLTT_ID(paletteNum);
    pltArrow = (struct PlttData *)&gPlttBufferFaded[paletteOffset + 9];  // Arrow color is in idx 9
    pltOutline = (struct PlttData *)&gPlttBufferFaded[paletteOffset + 8];  // Arrow outline is in idx 8
    if (!showArrows) //Make invisible
    {
        defaultPlttArrow = (struct PlttData *)&gPlttBufferFaded[paletteOffset + 13];  // Background color is idx 13
        pltArrow->r = defaultPlttArrow->r;
        pltArrow->g = defaultPlttArrow->g;
        pltArrow->b = defaultPlttArrow->b;
        pltOutline->r = defaultPlttArrow->r;
        pltOutline->g = defaultPlttArrow->g;
        pltOutline->b = defaultPlttArrow->b;
    }
    else // Make gray
    {
        defaultPlttArrow = (struct PlttData *)&gPlttBufferFaded[paletteOffset + 11];  // Grey color is idx 11
        defaultPlttOutline = (struct PlttData *)&gPlttBufferFaded[paletteOffset + 10];  //Light grey color for outline is idx 10
        pltArrow->r = defaultPlttArrow->r;
        pltArrow->g = defaultPlttArrow->g;
        pltArrow->b = defaultPlttArrow->b;
        pltOutline->r = defaultPlttOutline->r;
        pltOutline->g = defaultPlttOutline->g;
        pltOutline->b = defaultPlttOutline->b;
    }
#endif
}

void CategoryIcons_LoadSpritesGfx(void)
{
    LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
    LoadSpritePalette(&gSpritePal_CategoryIcons);
}

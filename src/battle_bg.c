#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "depuracion_mgba.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sombra_pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/battle_anim.h"

static const struct OamData sVsLetter_V_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sVsLetter_S_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 64,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds0[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sVsLetterAffineAnimTable[] =
{
    sVsLetterAffineAnimCmds0,
    sVsLetterAffineAnimCmds1,
};

#define TAG_VS_LETTERS 10000

static const struct SpriteTemplate sVsLetter_V_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_V_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct SpriteTemplate sVsLetter_S_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_S_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct CompressedSpriteSheet sVsLettersSpriteSheet =
{
    gVsLettersGfx, 0x1000, TAG_VS_LETTERS
};

const struct BgTemplate gBattleBgTemplates[] =
{
    {
        .bg = FONDO_0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = FONDO_32x64,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = FONDO_32x64,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = FONDO_2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = FONDO_64x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = FONDO_3,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = FONDO_64x32,
        .paletteMode = MODO_PALETAS_4BPP,
        .priority = 3,
        .baseTile = 0
    },
};

const struct WindowTemplate sBattleWindowTemplates[] =
{
    [B_WIN_MSG] = {
        .bg = FONDO_0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 19,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x0090,
    },
    [B_WIN_MOVE_NAME_1] = {
        .bg = FONDO_0,
        .tilemapLeft = 3,
        .tilemapTop = 54,
        .width = 9,
        .height = 3,
        .paletteNum = 12,
        .baseBlock = 768,
    },
    [B_WIN_MOVE_NAME_2] = {
        .bg = FONDO_0,
        .tilemapLeft = 18,
        .tilemapTop = 54,
        .width = 9,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 801,
    },
    [B_WIN_MOVE_NAME_3] = {
        .bg = FONDO_0,
        .tilemapLeft = 3,
        .tilemapTop = 57,
        .width = 9,
        .height = 3,
        .paletteNum = 14,
        .baseBlock = 834,
    },
    [B_WIN_MOVE_NAME_4] = {
        .bg = FONDO_0,
        .tilemapLeft = 18,
        .tilemapTop = 57,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 867,
    },
    [B_WIN_PP_1] = {
        .bg = FONDO_0,
        .tilemapLeft = 13,
        .tilemapTop = 54,
        .width = 2,
        .height = 3,
        .paletteNum = 12,
        .baseBlock = 656,
    },
    [B_WIN_PP_2] = {
        .bg = FONDO_0,
        .tilemapLeft = 28,
        .tilemapTop = 54,
        .width = 2,
        .height = 3,
        .paletteNum = 13,
        .baseBlock = 662,
    },
    [B_WIN_PP_3] = {
        .bg = FONDO_0,
        .tilemapLeft = 13,
        .tilemapTop = 57,
        .width = 2,
        .height = 3,
        .paletteNum = 14,
        .baseBlock = 668,
    },
    [B_WIN_PP_4] = {
        .bg = FONDO_0,
        .tilemapLeft = 28,
        .tilemapTop = 57,
        .width = 2,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 674,
    },
    [B_WIN_YESNO] = {
        .bg = FONDO_0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .bg = FONDO_1,
        .tilemapLeft = 19,
        .tilemapTop = 8,
        .width = 10,
        .height = 11,
        .paletteNum = 5,
        .baseBlock = 0x0100,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .bg = FONDO_2,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x016e,
    },
    [B_WIN_VS_PLAYER] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_OPPONENT] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0020,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0040,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .bg = FONDO_1,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0060,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .bg = FONDO_2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x0080,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .bg = FONDO_0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 6,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .bg = FONDO_0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00a0,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .bg = FONDO_0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x00b0,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .bg = FONDO_0,
        .tilemapLeft = 1,
        .tilemapTop = 47,
        .width = 18,
        .height = 6,
        .paletteNum = 5,
        .baseBlock = 0x0350,
    },
    DUMMY_WIN_TEMPLATE
};

const struct BattleBackground sBattleTerrainTable[] =
{
    [BATTLE_TERRAIN_GRASS] =
    {
        .tileset = gBattleTerrainTiles_TallGrass,
        .tilemap = gBattleTerrainTilemap_TallGrass,
        .entryTileset = gBattleTerrainAnimTiles_TallGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_TallGrass,
        .palette = gBattleTerrainPalette_TallGrass,
    },

    [BATTLE_TERRAIN_LONG_GRASS] =
    {
        .tileset = gBattleTerrainTiles_LongGrass,
        .tilemap = gBattleTerrainTilemap_LongGrass,
        .entryTileset = gBattleTerrainAnimTiles_LongGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_LongGrass,
        .palette = gBattleTerrainPalette_LongGrass,
    },

    [BATTLE_TERRAIN_SAND] =
    {
        .tileset = gBattleTerrainTiles_Sand,
        .tilemap = gBattleTerrainTilemap_Sand,
        .entryTileset = gBattleTerrainAnimTiles_Sand,
        .entryTilemap = gBattleTerrainAnimTilemap_Sand,
        .palette = gBattleTerrainPalette_Sand,
    },

    [BATTLE_TERRAIN_UNDERWATER] =
    {
        .tileset = gBattleTerrainTiles_Underwater,
        .tilemap = gBattleTerrainTilemap_Underwater,
        .entryTileset = gBattleTerrainAnimTiles_Underwater,
        .entryTilemap = gBattleTerrainAnimTilemap_Underwater,
        .palette = gBattleTerrainPalette_Underwater,
    },

    [BATTLE_TERRAIN_WATER] =
    {
        .tileset = gBattleTerrainTiles_Water,
        .tilemap = gBattleTerrainTilemap_Water,
        .entryTileset = gBattleTerrainAnimTiles_Water,
        .entryTilemap = gBattleTerrainAnimTilemap_Water,
        .palette = gBattleTerrainPalette_Water,
    },

    [BATTLE_TERRAIN_POND] =
    {
        .tileset = gBattleTerrainTiles_PondWater,
        .tilemap = gBattleTerrainTilemap_PondWater,
        .entryTileset = gBattleTerrainAnimTiles_PondWater,
        .entryTilemap = gBattleTerrainAnimTilemap_PondWater,
        .palette = gBattleTerrainPalette_PondWater,
    },

    [BATTLE_TERRAIN_MOUNTAIN] =
    {
        .tileset = gBattleTerrainTiles_Rock,
        .tilemap = gBattleTerrainTilemap_Rock,
        .entryTileset = gBattleTerrainAnimTiles_Rock,
        .entryTilemap = gBattleTerrainAnimTilemap_Rock,
        .palette = gBattleTerrainPalette_Rock,
    },

    [BATTLE_TERRAIN_CAVE] =
    {
        .tileset = gBattleTerrainTiles_Cave,
        .tilemap = gBattleTerrainTilemap_Cave,
        .entryTileset = gBattleTerrainAnimTiles_Cave,
        .entryTilemap = gBattleTerrainAnimTilemap_Cave,
        .palette = gBattleTerrainPalette_Cave,
    },

    [BATTLE_TERRAIN_BUILDING] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Building,
    },

    [BATTLE_TERRAIN_PLAIN] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Plain,
    },
};

void BattleInitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags();
    IniciaFondosDesdePlantillas(MODO_0, gBattleBgTemplates, ARRAY_COUNT(gBattleBgTemplates));
    InitWindows(sBattleWindowTemplates);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    BattleInitBgsAndWindows();

    // FONDO_1 y FONDO_2 tienen que quedarse con la base de caracteres a cero.
    //
    // Son las capas que usan las animaciones, y monbg escribe en ellas contando 512
    // casillas DESDE su base. Con la base a 1 -que es lo que dice la plantilla- esos
    // tiles caen en 0x8000, que es justo donde vive el tileset del terreno: cada
    // animacion que dibujara al Pokemon en una capa se llevaba el escenario por
    // delante, y clearmonbg remataba rellenando de ceros.
    //
    // Hasta ahora esto no se veia porque la transicion de entrada al combate dejaba
    // la base a cero de camino. O sea que el fallo estaba ahi para cualquier combate
    // arrancado sin transicion, como los del menu de depuracion.
    //
    // Se usa SetBgAttribute y no SetAnimBgAttribute a proposito: el segundo solo
    // toca el registro del hardware, y quien decide donde se escribe es la
    // contabilidad propia de bg.c. Cambiar uno solo los deja diciendo cosas
    // distintas.
    SetBgAttribute(FONDO_1, BG_ATTR_CHARBASEINDEX, 0);
    SetBgAttribute(FONDO_2, BG_ATTR_CHARBASEINDEX, 0);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

// Punto de reposo de los registros de video del combate: como tienen que quedar
// siempre que no haya nada especial ocurriendo.
//
// Quien los toque -animaciones, fundidos, la entrada al combate- vuelve aqui al
// acabar, en vez de apagar a mano lo que cree que encendio. Apagar a mano es lo
// que fallaba: BLDCNT es uno solo y con varios duenos, asi que el ultimo en
// escribir se llevaba por delante los ajustes que el resto daba por hechos.
//
// El caso concreto que lo destapo: la mezcla del hardware NO esta apagada en
// reposo. Es del combate, la usan las sombras de los Pokemon, y estan a la vista
// casi todo el rato. Cada vez que alguien dejaba BLDCNT a cero -o sin bits de
// segunda capa- la sombra se quedaba sin con que mezclarse y salia negra maciza:
// el parpadeo.
void RestauraRegistrosCombate(void)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR
                              | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR
                               | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    // Deja BLDCNT y BLDALPHA como los quiere la sombra.
    PreparaMezclaSombraPokemon();
}

// Que se tine en combate y que no.
//
// Se tine el mundo: el terreno -fondos 2, 3 y 4, donde deja la paleta del
// escenario LoadBattleTextboxAndBackground- y los combatientes, que ocupan una
// paleta de objeto cada uno de la 0 a la 3.
//
// Los fondos 8 a 11 NO entran, aunque BattleLoadMonSpriteGfx deje ahi una copia de
// cada combatiente. Estuvieron un tiempo y fue un error: monbg reutiliza el 8 y el
// 9 para lo suyo cuando dibuja al Pokemon en una capa, asi que la instantania sin
// tenir que se guardaba aqui no correspondia con lo que hubiera en ese momento, y
// al repintar se escribia encima -o peor, se escribia negro, que es lo que hay en
// una instantania que nunca se llego a tomar-.
//
// Tampoco hacen falta: monbg copia desde la paleta de objeto SIN FUNDIR del
// Pokemon, que ya viene tenida, asi que el Pokemon dibujado en la capa hereda la
// luz por ese camino sin que nadie tenga que teñirlo aqui.
//
// Queda inmune todo lo que es interfaz: el cuadro de texto (fondo 0), el menu de
// acciones (fondo 1), el texto de ventana (fondo 5), y por el lado de los objetos
// los marcadores, las barras de vida, los iconos de estado y de tipo y la sombra,
// que viven de la paleta de objeto 4 en adelante.
//
// El indice es plano: 0-15 son paletas de fondo y 16-31 de objeto.
static const u8 sPaletasCombateConHora[] =
{
    2, 3, 4,            // terreno
    16, 17, 18, 19,     // los cuatro combatientes
};

// Copia sin tenir de cada una de esas paletas.
//
// Hace falta porque el tinte se escribe sobre la paleta SIN FUNDIR, no sobre la
// fundida. Es la unica forma de que aguante: cualquier fundido rehace la fundida a
// partir de la sin fundir, asi que un tinte que viva solo en la fundida se pierde
// en cuanto algo se desvanece -la entrada del rival, el paso al menu de Pokemon,
// la salida del combate-. Escribiendolo en la de origen, todos esos fundidos lo
// arrastran solos y no hay que ir parcheandolos uno a uno.
//
// La pega de escribir en la de origen es que se pierde el color original, y sin el
// no se puede volver a tenir cuando cambia la hora sin que el tinte se acumule. De
// ahi esta copia: son 7 paletas, 224 bytes.
static EWRAM_DATA u16 sPaletasCombateSinTenir[7 * 16] = {0};

static u16 *CopiaSinTenirDe(u32 paleta)
{
    for (u32 i = 0; i < ARRAY_COUNT(sPaletasCombateConHora); i++)
    {
        if (sPaletasCombateConHora[i] == paleta)
            return &sPaletasCombateSinTenir[i * 16];
    }

    return NULL;
}

static void TinePaletaCombate(u32 paleta, u16 *cruda)
{
    u32 posicion = PLTT_ID(paleta);

    // Misma regla que en el mapa: bajo techo no entra la luz. En combate
    // gMapHeader sigue siendo el del mapa del que vienes, que es justo lo que
    // interesa: si el combate es en una cueva, no se tine.
    if (!MapaTieneLuzNatural(gMapHeader.mapType))
        return;

    // Aqui NO se llama a UpdateAltBgPalettes. Las paletas alternas salen de los
    // tilesets del mapa, y en combate esos tilesets no estan cargados: mezclaria
    // el escenario de combate contra los colores de otra cosa.
    TimeMixPalettes(1, cruda, gPlttBufferUnfaded + posicion,
                    (struct ConfiguracionBlend *)&gBlendHoraDia[blendHoraActual.tiempoInicial],
                    (struct ConfiguracionBlend *)&gBlendHoraDia[blendHoraActual.tiempoFinal],
                    blendHoraActual.intensidad);

    // Con un fundido en marcha no se toca la paleta fundida: la esta calculando el
    // fundido, y ya la saca de la sin fundir que acabamos de tenir.
    if (!gFundidoPaletas.activo)
        CopiaCpu16(gPlttBufferUnfaded + posicion, gPlttBufferFaded + posicion, PLTT_SIZE_4BPP);
}

// Se llama justo despues de cargar una paleta, cuando todavia tiene su color
// original. Guarda ese color y le aplica la hora.
void GuardaYTinePaletaCombate(u32 paleta)
{
    u16 *cruda = CopiaSinTenirDe(paleta);

    if (cruda == NULL)
        return;

    CopiaCpu16(gPlttBufferUnfaded + PLTT_ID(paleta), cruda, PLTT_SIZE_4BPP);

    TinePaletaCombate(paleta, cruda);
}

// Tine una paleta suelta, de las que no estan en la lista de arriba: la del
// entrenador rival va a una ranura que se asigna sobre la marcha, asi que no se le
// puede reservar sitio fijo para la copia sin tenir.
//
// Al no guardar copia, esto se aplica UNA vez, justo al cargarla, y no se repinta
// si cambia la hora mientras esta en pantalla. Es aceptable porque esos sprites
// duran poco.
void TinePaletaSueltaDeCombate(u32 paleta)
{
    u32 posicion;

    if (paleta >= 32 || !MapaTieneLuzNatural(gMapHeader.mapType))
        return;

    posicion = PLTT_ID(paleta);
    TimeMixPalettes(1, gPlttBufferUnfaded + posicion, gPlttBufferUnfaded + posicion,
                    (struct ConfiguracionBlend *)&gBlendHoraDia[blendHoraActual.tiempoInicial],
                    (struct ConfiguracionBlend *)&gBlendHoraDia[blendHoraActual.tiempoFinal],
                    blendHoraActual.intensidad);

    if (!gFundidoPaletas.activo)
        CopiaCpu16(gPlttBufferUnfaded + posicion, gPlttBufferFaded + posicion, PLTT_SIZE_4BPP);
}

// Repinta todas con la hora actual. Se puede llamar cuantas veces haga falta: el
// tinte sale siempre de la copia sin tenir, asi que no se acumula.
void ActualizaPaletasCombateSegunHora(void)
{
    for (u32 i = 0; i < ARRAY_COUNT(sPaletasCombateConHora); i++)
        TinePaletaCombate(sPaletasCombateConHora[i], &sPaletasCombateSinTenir[i * 16]);
}

void LoadBattleMenuWindowGfx(void)
{
    LoadPalette(gBattleWindowTextPalette, BG_PLTT_ID(5), PLTT_SIZE_4BPP);
}

void DrawMainBattleBackground(void)
{
    if (EsCombateContraLegendario(gCombate->tipoCombate))
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleTerrainTiles_Water, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleTerrainTiles_Rayquaza, (void*)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Rayquaza, (void*)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_Rayquaza, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        default:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
    else
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                LoadPalette(gBattleTerrainPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                LoadPalette(gBattleTerrainPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        default:
        case BATTLE_BACKGROUND_NORMAL:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_GYM:
            LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_MAGMA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_AQUA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_SIDNEY:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_PHOEBE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_GLACIA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case BATTLE_BACKGROUND_DRAKE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadPalette(gBattleTerrainPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    LoadBattleMenuWindowGfx();
    DrawMainBattleBackground();

    // El terreno acaba de entrar con su color original.
    GuardaYTinePaletaCombate(2);
    GuardaYTinePaletaCombate(3);
    GuardaYTinePaletaCombate(4);
}

void DrawBattleEntryBackground(void)
{
    if (EsCombateContraLegendario(gCombate->tipoCombate))
    {
        switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
        {
        case SPECIES_GROUDON:
            LZDecompressVram(gBattleTerrainAnimTiles_Cave, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Cave, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_KYOGRE:
            LZDecompressVram(gBattleTerrainAnimTiles_Underwater, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Underwater, (void*)(BG_SCREEN_ADDR(28)));
            break;
        case SPECIES_RAYQUAZA:
            LZDecompressVram(gBattleTerrainAnimTiles_Rayquaza, (void*)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Rayquaza, (void*)(BG_SCREEN_ADDR(28)));
            break;
        default:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
            break;
        }
    }
    else
    {
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
        }

        if (GetCurrentMapBattleScene() == BATTLE_BACKGROUND_NORMAL)
        {
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(gBattleActionsPalFight, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        break;
    case 3:
        if (EsCombateContraLegendario(gCombate->tipoCombate))
        {
            switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
            {
            case SPECIES_GROUDON:
                LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(BG_CHAR_ADDR(2)));
                break;
            case SPECIES_KYOGRE:
                LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(BG_SCREEN_ADDR(2)));
                break;
            }
        }
        else
        {
            if (EsCombateContraEntrenador(gCombate->tipoCombate))
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_GYM:
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_AQUA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            }
        }
        break;
    case 4:
        if (EsCombateContraLegendario(gCombate->tipoCombate))
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(BG_SCREEN_ADDR(26)));
            else
                LZDecompressVram(gBattleTerrainTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        }
        else
        {
            if (EsCombateContraEntrenador(gCombate->tipoCombate))
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_GYM:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_AQUA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            }
        }
        break;
    case 5:
        if (EsCombateContraLegendario(gCombate->tipoCombate))
        {
            if (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) == SPECIES_GROUDON)
                LoadPalette(gBattleTerrainPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            else
                LoadPalette(gBattleTerrainPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else
        {
            if (EsCombateContraEntrenador(gCombate->tipoCombate))
            {
                u32 trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent);
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadPalette(gBattleTerrainPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadPalette(gBattleTerrainPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case BATTLE_BACKGROUND_NORMAL:
                LoadPalette(sBattleTerrainTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_GYM:
                LoadPalette(gBattleTerrainPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_MAGMA:
                LoadPalette(gBattleTerrainPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_AQUA:
                LoadPalette(gBattleTerrainPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_SIDNEY:
                LoadPalette(gBattleTerrainPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_PHOEBE:
                LoadPalette(gBattleTerrainPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_GLACIA:
                LoadPalette(gBattleTerrainPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case BATTLE_BACKGROUND_DRAKE:
                LoadPalette(gBattleTerrainPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            }
        }
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}

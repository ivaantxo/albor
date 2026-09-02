#include "global.h"
#include "sombra_pokemon.h"
#include "gpu_regs.h"
#include "palette.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"

// Etiqueta de la unica paleta que gastan todas las sombras.

// Negra entera. El indice 0 no se usa -en un sprite siempre es transparente-,
// asi que cualquier pixel opaco del Pokemon cae en un negro.
static const u16 sPaletaSombra[16] =
{
    RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
    RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
    RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
    RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
};

static const struct SpritePalette sPaletaSombraPokemon =
{
    sPaletaSombra, TAG_SOMBRA_PAL
};

// CreateSprite desreferencia template->images aunque el sprite no vaya a usar
// tiles propios: con NULL leia de la direccion 0 y luego copiaba basura a VRAM en
// cada fotograma, que es lo que machacaba la barra de salud. Un tile vacio de
// verdad cuesta 32 bytes y quita el problema de raiz.
static const u8 sTileVacioSombra[TILE_4BPP] = {0};

static const struct SpriteFrameImage sImagenesSombra[] =
{
    { sTileVacioSombra, sizeof(sTileVacioSombra) },
};

// Prioridad 2, la misma que los Pokemon de combate, para quedar por encima del
// terreno. Que se dibuje por DETRAS del bicho lo decide la subprioridad, que es
// alta. La caja es doble porque al inclinarla los pixeles se salen del recuadro
// original y el hardware los recortaria.
static const struct OamData sOamSombra =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sPlantillaSombra =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_SOMBRA_PAL,
    .oam = &sOamSombra,
    .anims = gDummySpriteAnimTable,
    .images = sImagenesSombra,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void CargaGraficosSombraPokemon(void)
{
    LoadSpritePalette(&sPaletaSombraPokemon);
}

// La matriz que usa el hardware es la INVERSA de la transformacion que se ve: el
// GBA recorre pixeles de pantalla y pregunta de que pixel del sprite vienen.
//
// Como es la inversa, el signo va al reves de lo que dice la intuicion: para que
// la silueta se tumbe hacia la DERECHA por arriba hay que muestrear mas a la
// izquierda segun se sube, o sea con el termino en positivo.
//
//   pa = 256      pb = +s*256/k
//   pc = 0        pd = 256*256/k


// Unica funcion que calcula la matriz de una sombra. La usan tanto el juego -con
// las constantes de sombra_pokemon.h- como la pagina de deformacion del visor de
// sprites, para que sea IMPOSIBLE que lo que se ve al ajustar y lo que hace el
// codigo se separen: no hay dos caminos que puedan redondear distinto.
void FijaDeformacionSombra(struct Sprite *sombra, s32 ancho, s32 alto, s32 inclinH, s32 inclinV)
{
    s32 escala = SOMBRA_TAMANO;
    s32 pa, pb, pc, pd, pieX, pieY;

    // Una escala de cero haria estallar la division y dejaria la sombra invisible.
    if (ancho > -SOMBRA_ESCALA_MINIMA && ancho < SOMBRA_ESCALA_MINIMA)
        ancho = (ancho < 0) ? -SOMBRA_ESCALA_MINIMA : SOMBRA_ESCALA_MINIMA;
    if (alto > -SOMBRA_ESCALA_MINIMA && alto < SOMBRA_ESCALA_MINIMA)
        alto = (alto < 0) ? -SOMBRA_ESCALA_MINIMA : SOMBRA_ESCALA_MINIMA;

    // La matriz es la INVERSA de lo que se ve, de ahi que dividir agrande. El
    // tamano de la especie divide los cuatro terminos por igual, asi que cambia lo
    // grande que es la sombra pero no su forma: la luz es la misma para todos.
    pa = (256 * 100 * 100) / (ancho * escala);
    pd = (256 * 100 * 100) / (alto * escala);
    pb = (inclinH * 256 * 100) / (100 * escala);
    pc = (inclinV * 256 * 100) / (100 * escala);

    SetOamMatrix(sombra->sSombraMatriz, (u16)pa, (u16)pb, (u16)pc, (u16)pd);

    // Donde acaban los pies despues de deformar, y cuanto hay que mover la sombra
    // para devolverlos a la linea del suelo. Se despeja de la propia matriz en vez
    // de rehacer la trigonometria: asi sigue valiendo se toquen los numeros que se
    // toquen.
    pieY = (pd != 0) ? (256 * SOMBRA_LINEA_PIES) / pd : SOMBRA_LINEA_PIES;
    pieX = (pa != 0) ? -(pb * pieY) / pa : 0;

    sombra->sSombraCorreccionX = -pieX;
    sombra->sSombraCorreccionY = SOMBRA_LINEA_PIES - pieY;
}

void FijaFormaSombra(struct Sprite *sombra)
{
    FijaDeformacionSombra(sombra, SOMBRA_ANCHO, SOMBRA_ALTO, SOMBRA_INCLINACION, 0);
}

// Un sprite en modo semitransparente se mezcla siempre con lo que tenga detras,
// sin importar los bits de primera capa de BLDCNT. Lo que si hace falta es decir
// cuales son las segundas capas -los fondos- y en que proporcion.
//
// Como el duplicado es negro no aporta color: el resultado es el fondo atenuado,
// y por eso la proporcion de la primera capa va a cero y solo cuenta la del fondo.
// El valor elegido es exactamente el que deja "setalpha 12, 8", que es lo que
// piden 241 de los 294 setalpha de los guiones de animacion. Asi la mezcla en
// reposo ya es la que la mayoria de las animaciones iban a pedir: no cambian nada
// al empezar, y la sombra no cambia de densidad a media pelea.
void PreparaMezclaSombraPokemon(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(SOMBRA_MEZCLA_SOMBRA, SOMBRA_MEZCLA_FONDO));
}

// Con la pantalla lavada a blanco -un fogonazo, un resplandor- la sombra se queda
// negra sobre blanco y canta muchisimo.
//
// Esto no se puede detectar mirando el hardware, que es como la sombra se entera de
// todo lo demas: los blends a blanco de las animaciones tiñen PALETAS, y los
// registros de mezcla siguen exactamente como los dejo la sombra. Asi que se mira el
// resultado. Si a las tres paletas del terreno no les queda un solo tono oscuro, es
// que algo ha blanqueado el fondo, y da igual quien haya sido: vale para cualquier
// animacion, incluidas las que aun no existen.
//
// Sale en cuanto encuentra un color oscuro, que es lo que pasa siempre salvo durante
// el fogonazo, asi que en la practica cuesta una comparacion.
#define SOMBRA_UMBRAL_LAVADO 24

static bool32 CanalOscuro(u32 color)
{
    return (color & 0x1F) < SOMBRA_UMBRAL_LAVADO
        || ((color >> 5) & 0x1F) < SOMBRA_UMBRAL_LAVADO
        || ((color >> 10) & 0x1F) < SOMBRA_UMBRAL_LAVADO;
}

bool32 FondoLavadoABlanco(void)
{
    for (u32 paleta = 2; paleta <= 4; paleta++)
    {
        const u16 *colores = &gPlttBufferFaded[PLTT_ID(paleta)];

        // El indice 0 de una paleta de fondo no se dibuja.
        for (u32 i = 1; i < 16; i++)
        {
            if (CanalOscuro(colores[i]))
                return FALSE;
        }
    }

    return TRUE;
}

// La mezcla es un recurso unico del hardware y la comparten varios. La sombra no
// puede reservarla en exclusiva, asi que hace lo contrario: mira si sigue como la
// dejo y, si no, se esconde. Un OBJ semitransparente se mezcla siempre con lo que
// tenga detras, pero necesita que haya alguna segunda capa declarada; sin ella no
// tiene con que mezclarse y sale negro macizo.
//
// De la PRIMERA capa no se exige nada: la sombra es negra y no aporta color, asi
// que el coeficiente que le pongan da igual y puede convivir con quien lo mueva.
// De la SEGUNDA si, y exactamente el suyo. Ese coeficiente es la densidad de la
// sombra, y tolerar cualquier valor la hacia pulsar: Reciclaje, por ejemplo, lleva
// BLDALPHA de (0,16) a (16,0) para que su flecha aparezca, y por el camino la
// sombra pasaba de invisible a negra maciza y desaparecia de golpe. No es que
// cambie de densidad un rato: es un parpadeo en toda regla.
//
// Esto no la aparta de las animaciones normales. De los 294 setalpha de los
// guiones, 275 piden justo la densidad de la sombra, asi que en esos la mezcla
// sigue siendo valida y la sombra se queda donde esta.
bool32 MezclaSirveParaSombra(void)
{
    u32 bldcnt = GetGpuReg(REG_OFFSET_BLDCNT);

    // En modo mezcla...
    if ((bldcnt & BLDCNT_EFFECT_MASK) != BLDCNT_EFFECT_BLEND)
        return FALSE;

    // ...con algo detras con lo que mezclarse. Los otros objetos no valen: la
    // sombra cae sobre el terreno.
    if (!(bldcnt & (BLDCNT_TGT2_BG_ALL | BLDCNT_TGT2_BD)))
        return FALSE;

    // ...y dejando pasar exactamente lo que la sombra pide. A cero saldria negra
    // maciza y a dieciseis no se veria.
    return ((GetGpuReg(REG_OFFSET_BLDALPHA) >> 8) & 0x1F) == SOMBRA_MEZCLA_FONDO;
}

void TerminaMezclaSombraPokemon(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
}

u8 CreaSombraPokemon(u8 spriteIdDueno, u8 subprioridad)
{
    u8 spriteId;
    u32 matriz;
    struct Sprite *sombra;

    if (spriteIdDueno >= MAX_SPRITES)
        return MAX_SPRITES;

    matriz = AllocOamMatrix();
    if (matriz == 0xFF)
        return MAX_SPRITES;

    spriteId = CreateSprite(&sPlantillaSombra, 0, 0, subprioridad);
    if (spriteId >= MAX_SPRITES)
    {
        FreeOamMatrix(matriz);
        return MAX_SPRITES;
    }

    sombra = &gSprites[spriteId];

    // Sin animacion de ninguna clase. Los tiles los reapunta ColocaSombraPokemon
    // a los del dueno y la matriz la fijamos aqui: si el sistema de animacion
    // corriera, sobreescribiria las dos cosas en cada fotograma.
    sombra->animPaused = TRUE;
    sombra->affineAnimPaused = TRUE;

    sombra->oam.matrixNum = matriz;
    sombra->sSombraMatriz = matriz;
    sombra->sSombraDueno = spriteIdDueno;
    sombra->invisible = TRUE;
    FijaFormaSombra(sombra);

    return spriteId;
}

void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY)
{
    // Apunta a los tiles del dueno en cada fotograma, no solo al crearse: el
    // sprite del Pokemon cambia de fotograma al animarse, y asi la silueta lo
    // sigue sin que haya que enterarse de nada.
    sombra->oam.tileNum = dueno->oam.tileNum;

    sombra->x = dueno->x + desplazamientoX + sombra->sSombraCorreccionX;
    sombra->y = dueno->y + desplazamientoY + sombra->sSombraCorreccionY;
    sombra->x2 = dueno->x2;
    sombra->y2 = dueno->y2;
}

void DestruyeSombraPokemon(u8 spriteIdSombra)
{
    if (spriteIdSombra >= MAX_SPRITES || !gSprites[spriteIdSombra].inUse)
        return;

    FreeOamMatrix(gSprites[spriteIdSombra].sSombraMatriz);
    DestroySprite(&gSprites[spriteIdSombra]);
}

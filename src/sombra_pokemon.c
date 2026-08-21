#include "global.h"
#include "sombra_pokemon.h"
#include "gpu_regs.h"
#include "palette.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"

// Etiqueta de la unica paleta que gastan todas las sombras.
#define TAG_SOMBRA_PAL 0xD759

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
static const u16 sAplastadoPorTamano[] =
{
    [SHADOW_SIZE_S]  = SOMBRA_APLASTADO_S,
    [SHADOW_SIZE_M]  = SOMBRA_APLASTADO_M,
    [SHADOW_SIZE_L]  = SOMBRA_APLASTADO_L,
    [SHADOW_SIZE_XL] = SOMBRA_APLASTADO_XL,
};

void FijaAplastadoSombra(struct Sprite *sombra, u32 tamano)
{
    s32 aplastado;

    if (tamano >= ARRAY_COUNT(sAplastadoPorTamano))
        tamano = SHADOW_SIZE_M;

    aplastado = sAplastadoPorTamano[tamano];
    if (aplastado < 1)
        aplastado = 1;

    SetOamMatrix(sombra->sSombraMatriz,
                 256,
                 (SOMBRA_INCLINACION * 256) / aplastado,
                 0,
                 (256 * 256) / aplastado);
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

// La mezcla es un recurso unico del hardware y la comparten varios. La sombra no
// puede reservarla en exclusiva, asi que hace lo contrario: mira si sigue como la
// dejo y, si no, se esconde. Un OBJ semitransparente se mezcla siempre con lo que
// tenga detras, pero necesita que haya alguna segunda capa declarada; sin ella no
// tiene con que mezclarse y sale negro macizo.
//
// No se exige la configuracion exacta de la sombra, solo que sirva. A la sombra
// le da igual la proporcion de la primera capa -es negra, no aporta color-, asi
// que aguanta la mezcla de otro y como mucho cambia de densidad un rato. Lo unico
// que no puede es quedarse sin nada con lo que mezclarse.
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

    // ...y dejando pasar algo de ese fondo. A cero saldria negra maciza.
    return ((GetGpuReg(REG_OFFSET_BLDALPHA) >> 8) & 0x1F) != 0;
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
    FijaAplastadoSombra(sombra, SHADOW_SIZE_M);

    return spriteId;
}

void ColocaSombraPokemon(struct Sprite *sombra, const struct Sprite *dueno, s32 desplazamientoX, s32 desplazamientoY)
{
    // Apunta a los tiles del dueno en cada fotograma, no solo al crearse: el
    // sprite del Pokemon cambia de fotograma al animarse, y asi la silueta lo
    // sigue sin que haya que enterarse de nada.
    sombra->oam.tileNum = dueno->oam.tileNum;

    sombra->x = dueno->x + desplazamientoX + SOMBRA_CORRIMIENTO;
    sombra->y = dueno->y + desplazamientoY;
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

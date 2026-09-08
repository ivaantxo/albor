#include "global.h"
#include "bike.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "graphics.h"
#include "main.h"
#include "interfaz_movimiento.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "script.h"
#include "task.h"
#include "constants/songs.h"
#include "constants/etiquetas.h"

// Elegir como se anda por el mapa, con SELECT.
//
// Tres formas: a pie andando, a pie corriendo y en bici. Se representan con DOS
// iconos, no tres, porque "andar" es simplemente no tener ninguno puesto:
//
//                       zapatillas        bici
//     andando       ->  correr            bici
//     corriendo     ->  andar             bici
//     en bici       ->  correr            andar
//
// El icono del modo activo va en color y el otro en gris. El gris no es otro dibujo:
// son los mismos tiles con una segunda paleta, que sale de la primera aplastada hacia
// el medio. Duplicar el arte para eso habria costado el doble de VRAM y habria que
// mantener dos ficheros a la vez.

#define ICONO_CORRER 0
#define ICONO_BICI   1
#define CUANTOS_ICONOS 2

// Donde se colocan, en la esquina de abajo a la derecha.
#define ICONOS_X       200
#define ICONOS_Y       128
#define ICONOS_SEPARA   34

#define tSeleccion  data[0]
#define tArrancando data[3]
// Los sprites van en data[1] y data[2], recorridos con un indice.

static void Tarea_SelectorMovimiento(u8 idTarea);
static void CierraSelector(u8 idTarea);

static const u32 sIconosGfx[] = INCBIN_U32("graphics/interfaz_ow/iconos_movimiento.4bpp.lz");
static const u16 sIconosPal[] = INCBIN_U16("graphics/interfaz_ow/iconos_movimiento.gbapal");
static const u16 sIconosPalApagada[] = INCBIN_U16("graphics/interfaz_ow/iconos_apagados.gbapal");

static const struct CompressedSpriteSheet sHojaIconos =
{
    sIconosGfx, CUANTOS_ICONOS * 32 * 32 / 2, TAG_ICONOS_MOVIMIENTO
};

static const struct SpritePalette sPaletaIconos =
{
    sIconosPal, TAG_ICONOS_MOVIMIENTO
};

static const struct SpritePalette sPaletaIconosApagada =
{
    sIconosPalApagada, TAG_ICONOS_MOVIMIENTO_APAGADO
};

static const struct OamData sOamIconos =
{
    .shape = ST_OAM_SQUARE,
    .size = 2,              // 32x32
    .priority = 0,
};

static const union AnimCmd sAnimCorrer[] = { ANIMCMD_FRAME(0, 0), ANIMCMD_END };
static const union AnimCmd sAnimBici[]   = { ANIMCMD_FRAME(16, 0), ANIMCMD_END };

static const union AnimCmd *const sAnimsIconos[] = { sAnimCorrer, sAnimBici };

static const struct SpriteTemplate sPlantillaIconos =
{
    .tileTag = TAG_ICONOS_MOVIMIENTO,
    .paletteTag = TAG_ICONOS_MOVIMIENTO,
    .oam = &sOamIconos,
    .anims = sAnimsIconos,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

bool32 SelectorMovimientoAbierto(void)
{
    return FuncIsActiveTask(Tarea_SelectorMovimiento);
}

// Que icono esta "puesto" ahora mismo, o ninguno si se va andando.
static u32 IconoActivo(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BICI))
        return ICONO_BICI;
    if (gSaveBlockPtr->correSiempre)
        return ICONO_CORRER;

    return CUANTOS_ICONOS;      // ninguno: se va andando
}

// El color de cada icono: el activo a todo color, el resto apagados.
static void PintaIconos(u8 idTarea)
{
    u32 activo = IconoActivo();
    u32 normal = IndexOfSpritePaletteTag(TAG_ICONOS_MOVIMIENTO);
    u32 apagada = IndexOfSpritePaletteTag(TAG_ICONOS_MOVIMIENTO_APAGADO);

    for (u32 i = 0; i < CUANTOS_ICONOS; i++)
    {
        struct Sprite *icono = &gSprites[gTasks[idTarea].data[1 + i]];

        icono->oam.paletteNum = (i == activo) ? normal : apagada;

        // El que esta bajo el cursor se levanta un poco: es la unica marca de
        // seleccion, sin flecha ni recuadro.
        icono->y2 = (i == gTasks[idTarea].tSeleccion) ? -4 : 0;
    }
}

void AbreSelectorMovimiento(void)
{
    u8 idTarea;

    if (SelectorMovimientoAbierto())
        return;

    LoadCompressedSpriteSheet(&sHojaIconos);
    LoadSpritePalette(&sPaletaIconos);
    LoadSpritePalette(&sPaletaIconosApagada);

    idTarea = CreateTask(Tarea_SelectorMovimiento, 80);
    gTasks[idTarea].tSeleccion = 0;

    // La tarea nace DENTRO del proceso de entrada de este fotograma, y RunTasks corre
    // despues: sin esto, la tarea ve el mismo SELECT que acaba de abrirla y se cierra
    // al instante. Desde fuera parece que el boton no hace nada.
    gTasks[idTarea].tArrancando = TRUE;

    for (u32 i = 0; i < CUANTOS_ICONOS; i++)
    {
        u8 spriteId = CreateSprite(&sPlantillaIconos,
                                   ICONOS_X + i * ICONOS_SEPARA, ICONOS_Y, 0);

        gTasks[idTarea].data[1 + i] = spriteId;
        StartSpriteAnim(&gSprites[spriteId], i);
    }

    PintaIconos(idTarea);
    PlaySE(SE_SELECT);

    // Sin esto, izquierda y derecha mueven el cursor y al jugador a la vez.
    FreezeObjectEvents();
    LockPlayerFieldControls();
}

// La bici no es un objeto ni hace falta desbloquearla, pero sigue habiendo sitios
// donde no se puede montar: bajo techo, y encima de tiles donde no se corre. Bajarse
// se puede siempre, que si no se quedaria uno encerrado.
static bool32 SePuedeMontar(void)
{
    return Overworld_IsBikingAllowed() && !IsBikingDisallowedByPlayer();
}

// Lo que pasa al elegir uno u otro. Es la tabla del comentario de arriba, escrita
// una sola vez. Devuelve si se hizo algo.
static bool32 Aplica(u32 icono)
{
    bool32 enBici = TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BICI);

    if (icono == ICONO_BICI)
    {
        // La bici alterna: puesta la quita -y deja andando-, quitada la pone.
        if (!enBici && !SePuedeMontar())
            return FALSE;

        gSaveBlockPtr->correSiempre = FALSE;
        GetOnOffBike();
        return TRUE;
    }

    // Zapatillas: siempre se acaba a pie, y corriendo salvo que ya se corriera.
    if (enBici)
    {
        GetOnOffBike();     // bajarse
        gSaveBlockPtr->correSiempre = TRUE;
    }
    else
    {
        gSaveBlockPtr->correSiempre = !gSaveBlockPtr->correSiempre;
    }

    return TRUE;
}

static void Tarea_SelectorMovimiento(u8 idTarea)
{
    if (gTasks[idTarea].tArrancando)
    {
        gTasks[idTarea].tArrancando = FALSE;
        return;
    }

    if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
    {
        gTasks[idTarea].tSeleccion ^= 1;
        PlaySE(SE_SELECT);
        PintaIconos(idTarea);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (!Aplica(gTasks[idTarea].tSeleccion))
        {
            // Aqui no se puede montar: se queda abierto para elegir otra cosa.
            PlaySE(SE_FAILURE);
            return;
        }

        PlaySE(SE_SELECT);
        CierraSelector(idTarea);
    }
    else if (JOY_NEW(B_BUTTON) || JOY_NEW(SELECT_BUTTON))
    {
        CierraSelector(idTarea);
    }
}

static void CierraSelector(u8 idTarea)
{
    for (u32 i = 0; i < CUANTOS_ICONOS; i++)
        DestroySprite(&gSprites[gTasks[idTarea].data[1 + i]]);

    FreeSpriteTilesByTag(TAG_ICONOS_MOVIMIENTO);
    FreeSpritePaletteByTag(TAG_ICONOS_MOVIMIENTO);
    FreeSpritePaletteByTag(TAG_ICONOS_MOVIMIENTO_APAGADO);

    UnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    DestroyTask(idTarea);
}

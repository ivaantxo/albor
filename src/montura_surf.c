#include "global.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "montura_surf.h"
#include "party_menu.h"
#include "pokemon.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/moves.h"

// El Pokemon sobre el que se surfea.
//
// No es una mancha generica ni un efecto de campo: es el sprite de overworld del
// primer Pokemon del equipo que sepa Surf, con SU gráfico y SU paleta. Asi le afectan
// el variocolor, el sexo y el desplazamiento de tono por personalidad igual que al
// follower, sin arte ni tablas aparte.
//
// ESQUELETO. Lo que falta, y donde:
//
//   - El arte. Hoy sale el follower.png de la especie, que es el mismo dibujo que
//     anda por tierra. Cuando exista graphics/pokemon/<especie>/surfing.png bastara
//     con que InformacionGraficaDesdeEspecie lo devuelva para este caso; aqui no hay
//     que tocar nada.
//   - La personalidad. CreateObjectGraphicsSprite toma la del Pokemon guia, no la del
//     que surfea. Coinciden casi siempre -el guia suele ser el primero-, pero no es lo
//     mismo. Cuando importe, hace falta una variante de CargaPaletaFollower que reciba
//     la personalidad.
//   - El vaiven. El jugador surfeando sube y baja; la montura deberia acompanarlo.

// A cuanto por debajo del jugador se dibuja. Mas alto es mas atras.
#define MONTURA_SUBPRIORIDAD 1

// Cuanto se baja respecto al jugador, en pixeles. El jugador va sentado encima, asi
// que la montura asoma por abajo.
#define MONTURA_DESPLAZA_Y 8

// A cero por narices: la EWRAM del proyecto solo admite inicializadores nulos. Se
// guarda "el id mas uno", asi que el cero significa "no hay montura".
static EWRAM_DATA u8 sMonturaMasUno = 0;

#define SIN_MONTURA 0

static void SpriteCB_MonturaSurf(struct Sprite *sprite);

// El primero del equipo que sepa Surf, o SPECIES_NONE si ninguno.
//
// Se pregunta por CanLearnTeachableMove y no por los movimientos que lleva puestos:
// es el mismo criterio que usa PartyHasMonWithSurf para dejar surfear, y si los dos
// no coinciden se puede acabar surfeando sin montura.
static u32 EspecieQueSurfea(u32 *personalidad)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 especie = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        if (especie == SPECIES_NONE)
            break;

        if (CanLearnTeachableMove(especie, MOVE_SURF))
        {
            if (personalidad != NULL)
                *personalidad = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            return especie;
        }
    }

    return SPECIES_NONE;
}

// El identificador de grafico de overworld de una especie. Es lo mismo que hace el
// macro OBJ_EVENT_GFX_SPECIES, pero con la especie en una variable.
static u16 GraficoDeEspecie(u32 especie, struct Pokemon *mon)
{
    u16 grafico = especie + OBJ_EVENT_MON;

    if (mon != NULL)
    {
        if (GetMonData(mon, MON_DATA_IS_SHINY))
            grafico += OBJ_EVENT_MON_SHINY;
        if (GetMonGender(mon) == MON_FEMALE)
            grafico += OBJ_EVENT_MON_FEMALE;
    }

    return grafico;
}

void CreaMonturaSurf(void)
{
    struct ObjectEvent *jugador = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *spriteJugador = &gSprites[jugador->spriteId];
    u32 personalidad = 0;
    u32 especie = EspecieQueSurfea(&personalidad);

    if (sMonturaMasUno != SIN_MONTURA || especie == SPECIES_NONE)
        return;

    u8 nuevo = CreateObjectGraphicsSprite(GraficoDeEspecie(especie, NULL),
                                                SpriteCB_MonturaSurf,
                                                spriteJugador->x,
                                                spriteJugador->y + MONTURA_DESPLAZA_Y,
                                                spriteJugador->subpriority + MONTURA_SUBPRIORIDAD);

    if (nuevo == MAX_SPRITES)
        return;

    sMonturaMasUno = nuevo + 1;

    // La misma prioridad de OAM que el jugador: los dos van en la misma capa y quien
    // decide cual tapa a cual es la subprioridad. Con prioridades distintas, uno de los
    // dos cruzaria por delante o por detras del agua sin que nadie se lo pidiera.
    gSprites[nuevo].oam.priority = spriteJugador->oam.priority;
    gSprites[nuevo].coordOffsetEnabled = TRUE;
}

void DestruyeMonturaSurf(void)
{
    if (sMonturaMasUno == SIN_MONTURA)
        return;

    DestroySprite(&gSprites[sMonturaMasUno - 1]);
    sMonturaMasUno = SIN_MONTURA;
}

bool32 HayMonturaSurf(void)
{
    return sMonturaMasUno != SIN_MONTURA;
}

// Se pega al jugador cada fotograma en vez de moverse por su cuenta.
//
// Es a proposito: la montura no anda, la lleva el jugador. Dandole movimiento propio
// habria que sincronizar dos maquinas de estado -pasos, giros, colisiones, saltos de
// bordillo- y bastaria un fotograma de desfase para que se separaran.
static void SpriteCB_MonturaSurf(struct Sprite *sprite)
{
    struct ObjectEvent *jugador = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *spriteJugador = &gSprites[jugador->spriteId];

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        DestruyeMonturaSurf();
        return;
    }

    sprite->x = spriteJugador->x;
    sprite->y = spriteJugador->y + MONTURA_DESPLAZA_Y;
    sprite->x2 = spriteJugador->x2;
    sprite->y2 = spriteJugador->y2;
    sprite->subpriority = spriteJugador->subpriority + MONTURA_SUBPRIORIDAD;
    sprite->oam.priority = spriteJugador->oam.priority;
    sprite->invisible = spriteJugador->invisible;

    // Mira a donde mira el jugador. Las animaciones de un sprite de Pokemon del mapa
    // van en el orden de siempre: 0 sur, 1 norte, 2 oeste, 3 este.
    StartSpriteAnimIfDifferent(sprite, GetFaceDirectionAnimNum(jugador->facingDirection));
}

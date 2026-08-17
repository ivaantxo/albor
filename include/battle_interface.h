#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

#include "battle_controllers.h"

enum
{
    HP_CURRENT,
    HP_MAX,
    HP_BOTH
};

enum
{
    HP_BAR_EMPTY,
    HP_BAR_RED,
    HP_BAR_YELLOW,
    HP_BAR_GREEN,
    HP_BAR_FULL,
};

// Una hoja de tiles por combatiente (relleno, porcentaje, nombre y nivel) y una
// sola paleta para todo el marcador: contorno, textos e iconos de estado.
#define TAG_MARCADOR_JUGADOR1           0xD704
#define TAG_MARCADOR_OPONENTE1          0xD705
#define TAG_MARCADOR_JUGADOR2           0xD706
#define TAG_MARCADOR_OPONENTE2          0xD707

#define TAG_MARCADOR_PAL                TAG_MARCADOR_JUGADOR1





#define TAG_CONTORNO_BARRA              0xD75A
#define TAG_ICONOS_ESTADO               0xD75B

// Copia temporal de la paleta del marcador, para el parpadeo de subida de nivel.
#define TAG_MARCADOR_PAL_PARPADEO       0xD75C

// Tiles que reserva cada combatiente para su barra: los diez primeros son el
// relleno de 80x8 y los cuatro siguientes el porcentaje de 32x8. Todos se
// dibujan en codigo, la hoja solo reserva el sitio.
#define TILES_RELLENO_BARRA_VIDA    10
#define TILES_TEXTO_MARCADOR_HOJA   24   // 96x16
#define TILES_RESERVADOS_BARRA_VIDA (TILES_RELLENO_BARRA_VIDA + TILES_TEXTO_MARCADOR_HOJA)

// El contorno y los cinco iconos de estado son compartidos por todo el mundo.
#define TILES_ICONOS_ESTADO 20

// Reparto de los data[] del ancla del marcador. Esta aqui y no en el .c porque
// pokeball.c tambien la toca para la entrada deslizante, y con el reparto en dos
// sitios se pisaban los ids de las piezas.
#define sMarcadorPieza(n)       data[n]   // n = enum PiezaMarcador, 0..2
#define sMarcadorDeslizVelX     data[3]
#define sMarcadorDeslizVelY     data[4]
#define sMarcadorDeslizEspera   data[5]
#define sMarcadorCombatiente    data[6]

// El contorno es un unico grafico de 96x16 compartido por todos los marcadores.
// Geometria de barra_salud.png. El contorno mide 128x16 y deja un hueco de 80x3
// en la posicion (32, 5) para el relleno. Todo lo demas se deriva de aqui, asi
// que si se redibuja el grafico solo hay que tocar estos cinco numeros.
#define CONTORNO_ANCHO      128
#define CONTORNO_ALTO        16
#define HUECO_BARRA_X        32
#define HUECO_BARRA_Y         5
#define HUECO_BARRA_ANCHO    80
#define HUECO_BARRA_ALTO      3

#define TILES_CONTORNO_BARRA ((CONTORNO_ANCHO / 8) * (CONTORNO_ALTO / 8))

#define TAG_BATTLE_INTERFACE_SELECTOR   0xD77F

enum
{
    MARCADOR_TODO,
    MARCADOR_VIDA_ACTUAL,
    MARCADOR_VIDA_MAXIMA,
    MARCADOR_NIVEL,
    MARCADOR_NOMBRE,
    MARCADOR_BARRA,
    MARCADOR_ESTADO,
};

u32 WhichBattleCoords(u32 battlerId);
u8 CreaMarcadorCombate(u8 battler);
void SetBattleBarStruct(u8 battler, u8 healthboxSpriteId, s32 maxVal, s32 currVal, s32 receivedValue);
void OcultaMarcador(u8 healthboxSpriteId);
void FijaPaletaMarcador(u8 marcadorSpriteId, u8 paletteNum);
void MuestraMarcador(u8 healthboxSpriteId);
void FijaPrioridadMarcadores(u8 priority, bool32 hideHpBoxes);
void ColocaMarcador(u8 battler);
void CoordenadasMarcador(u8 battler, s16 *x, s16 *y);
void ActualizaMarcador(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
s32 MoveBattleBar(u8 battler, u8 healthboxSpriteId);
u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u8 GetHPBarLevel(s16 hp, s16 maxhp);
void CreaMensajeHabilidad(u32 combatiente, u32 habilidad);
void DestruyeMensajeHabilidad(u32 combatiente);
bool32 CanThrowLastUsedBall(void);
void TryHideLastUsedBall(void);
void TryRestoreLastUsedBall(void);
void TryAddLastUsedBallItemSprites(void);
void SwapBallToDisplay(bool32 sameBall);
void ArrowsChangeColorLastBallCycle(bool32 showArrows);
void ActualizaVentanaHabilidad(u32 combatiente);
void MoveSelectionCreateCursorAt(u8 cursorPos);
void MoveSelectionDestroyCursor(void);
void CategoryIcons_LoadSpritesGfx(void);

#endif // GUARD_BATTLE_INTERFACE_H

#ifndef GUARD_BATTLE_BG_H
#define GUARD_BATTLE_BG_H

#include "bg.h"

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

void BattleInitBgsAndWindows(void);
void InitBattleBgsVideo(void);
void RestauraRegistrosCombate(void);
void ActualizaPaletasCombateSegunHora(void);

// Cierto mientras hay un fondo de movimiento puesto en vez del terreno. Sirve para
// que el reloj no repinte las paletas del escenario encima de el.
extern bool8 gFondoDeAnimacionPuesto;

// Cierto mientras hay un fondo de movimiento puesto en vez del terreno. Sirve para
// que el reloj no repinte las paletas del escenario encima de el.
extern bool8 gFondoDeAnimacionPuesto;
void GuardaYTinePaletaCombate(u32 paleta);
void TinePaletaSueltaDeCombate(u32 paleta);
void LoadBattleMenuWindowGfx(void);
void DrawMainBattleBackground(void);
void LoadBattleTextboxAndBackground(void);
void DrawBattleEntryBackground(void);
bool8 LoadChosenBattleElement(u8 caseId);

// Como esta configurado cada fondo del combate. Las animaciones lo consultan para
// devolver el BG1 como lo encontraron.
extern const struct BgTemplate gBattleBgTemplates[];

#endif // GUARD_BATTLE_BG_H

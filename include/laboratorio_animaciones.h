#ifndef GUARD_LABORATORIO_ANIMACIONES_H
#define GUARD_LABORATORIO_ANIMACIONES_H

// Laboratorio de animaciones de movimiento.
//
// Es un combate de verdad, no una pantalla aparte. Esa fue la decision de diseno
// importante: el sistema de animaciones da por hecho un monton de cosas montadas
// -gBattlerSpriteIds, gBattlerPartyIndexes, gBattleSpritesDataPtr, las capas de
// fondo que usa monbg- y recrear todo eso a mano en un visor autonomo significaria
// que cada animacion que dependa de algo olvidado falle de una forma distinta. Con
// cientos de movimientos, esa caceria no se acaba.
//
// Asi que se arranca un combate normal y se le quita lo que estorba: en vez del
// menu de accion sale un selector de movimientos que solo lanza la animacion. Sin
// gastar PP, sin dano, sin efectos y sin que el rival haga nada.

extern bool8 gLaboratorioAnimaciones;

// Arranca un combate en modo laboratorio.
void EntraEnLaboratorioAnimaciones(void);

// Se llama donde el jugador elegiria accion. Devuelve cierto si el laboratorio se
// hace cargo, en cuyo caso el combate normal no debe seguir por ahi.
bool32 LaboratorioTomaElControl(u32 combatiente);

#endif // GUARD_LABORATORIO_ANIMACIONES_H

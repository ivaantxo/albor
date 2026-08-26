#ifndef GUARD_NIVEL_DINAMICO_H
#define GUARD_NIVEL_DINAMICO_H

// El nivel al que sale cualquier rival: el del Pokemon mas fuerte del jugador.
u32 NivelDinamico(void);

// La especie que corresponde a ese nivel, aplicando las evoluciones por nivel tantas
// veces como haga falta. Las que dependen de objeto, amistad, hora o movimiento NO se
// aplican: para esas hay que nombrar la especie final en el equipo del entrenador.
u32 EspecieSegunNivel(u32 especie, u32 nivel);

#endif // GUARD_NIVEL_DINAMICO_H

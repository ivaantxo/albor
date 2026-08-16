#ifndef GUARD_POKEMON_SALVAJES_OW_H
#define GUARD_POKEMON_SALVAJES_OW_H

// Pokemon salvajes que viven en el mapa.
//
// No hay encuentros aleatorios al pisar hierba: los Pokemon salvajes aparecen
// como objetos del mapa, se mueven por su terreno y el combate empieza cuando
// quedan en una casilla ortogonalmente adyacente a la del jugador. Todo el
// sistema avanza a base de pasos del jugador, no de fotogramas, para que el
// ritmo sea el suyo y no el del reloj.
//
// Cada Pokemon nace con su propia personalidad, que decide su tono y si es
// variocolor, y esa misma personalidad es la que se le pasa al combate.

enum TerrenoSalvaje
{
    TERRENO_HIERBA_ALTA,
    TERRENO_CUEVA,
    TERRENO_OCEANO,
    TERRENOS_SALVAJES,
};

// Se llama al cargar un mapa: no sobreviven a un cambio de pantalla.
void ReiniciaPokemonSalvajesOw(void);

// Un tic del sistema, que equivale a un paso del jugador: mueve a los que hay,
// destruye a los que se les acabo el tiempo e intenta crear uno nuevo.
void ActualizaPokemonSalvajesOw(void);

// Contacto automatico: hay uno en casilla contigua Y el jugador pisa su mismo
// terreno. Se comprueba cada fotograma.
bool32 ComprobaContactoPokemonSalvaje(void);

// Contacto a proposito: basta con que haya uno en casilla contigua, este el
// jugador donde este. Es la salida cuando el automatico no aplica.
bool32 IntentaCombatePokemonSalvajePulsandoA(void);

bool32 EsObjetoPokemonSalvaje(u32 objectEventId);

#endif // GUARD_POKEMON_SALVAJES_OW_H

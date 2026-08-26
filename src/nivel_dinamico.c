#include "global.h"
#include "nivel_dinamico.h"
#include "pokemon.h"
#include "constants/pokemon.h"

// Los rivales no tienen nivel propio: siempre valen lo que el Pokemon mas fuerte del
// jugador. Asi el juego no obliga a subir de nivel para avanzar, y el reto se mantiene
// donde el jugador lo deje. De ahi que las tablas de niveles de salvajes y de
// entrenadores ya no pinten nada.

u32 NivelDinamico(void)
{
    u32 mayor = 1;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 especie = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        u32 nivel;

        if (especie == SPECIES_NONE || especie == SPECIES_EGG)
            continue;

        nivel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        if (nivel > mayor)
            mayor = nivel;
    }

    return mayor;
}

// Las unicas evoluciones que el nivel dinamico puede resolver por su cuenta.
//
// Las demas -por objeto, por amistad, por movimiento, por hora del dia, por sexo-
// dependen de algo que un rival generado al vuelo no tiene, asi que no se aplican: en
// esos casos hay que nombrar directamente la especie que se quiere en el equipo del
// entrenador. Las cruzadas tipo Eevee tampoco, y ahi es aun mas importante, porque
// elegir una rama al azar daria combates distintos cada vez.
static bool32 EsEvolucionPorNivel(u32 metodo)
{
    switch (metodo)
    {
    case EVO_NIVEL:
    case EVO_NIVEL_MAS_ATAQUE:
    case EVO_NIVEL_IGUAL_ATAQUE:
    case EVO_NIVEL_MENOS_ATAQUE:
    case EVO_NIVEL_HEMBRA:
    case EVO_NIVEL_MACHO:
        return TRUE;
    default:
        return FALSE;
    }
}

u32 EspecieSegunNivel(u32 especie, u32 nivel)
{
    // En bucle: un Pokemon de dos evoluciones tiene que poder recorrerlas las dos si
    // el nivel da para ello. El tope de vueltas evita que un dato mal puesto -una
    // evolucion que apunte hacia atras- cuelgue el juego.
    for (u32 vueltas = 0; vueltas < 5; vueltas++)
    {
        const struct Evolution *evos = gSpeciesInfo[especie].evolutions;
        u32 siguiente = especie;

        if (evos == NULL)
            break;

        for (u32 i = 0; evos[i].method != EVO_FIN; i++)
        {
            if (EsEvolucionPorNivel(evos[i].method) && nivel >= evos[i].param)
            {
                siguiente = evos[i].targetSpecies;
                break;                  // la primera que cumpla: no hay ramas aqui
            }
        }

        if (siguiente == especie)
            break;

        especie = siguiente;
    }

    return especie;
}

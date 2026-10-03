// Compilador de mapeado: del arte por capas de los mapas al tileset y el blockdata.
//
// Es la biblioteca. No lee ni escribe archivos: trabaja con lo que le pasan en memoria,
// para que la pueda usar igual la linea de comandos (main.cpp) que un editor.
//
// Cada mapa se pinta en tres capas de pixeles (baja, media, alta) con arte libre. El
// compilador trocea los mapas en casillas de 16x16, saca de ahi los metatiles, los
// tiles de 8x8 (con volteos) y las paletas, y reescribe el blockdata.
//
// El comportamiento, el nivel y la colision NO salen del arte: se editan despues, los
// dos primeros en los atributos del metatile y la colision en el bloque. Por eso cada
// compilacion parte de lo que habia antes y lo respeta:
//
//   - Una casilla cuyo arte no ha cambiado se queda con su metatile, sus atributos y su
//     colision. Si alguien pinto ahi un duplicado con otro comportamiento, se mantiene.
//   - Una casilla con arte nuevo hereda los atributos de otro metatile que ya tuviera
//     ese mismo arte, si lo hay, y si no se queda en comportamiento normal y nivel auto.
//     La colision siempre es la que tenia la casilla.
//   - Los metatiles y los tiles que siguen existiendo conservan su numero, para que el
//     blockdata y las referencias desde codigo no se muevan.
//   - Los metatiles fijados (con nombre, porque los usa el codigo aunque no esten en
//     ningun mapa) se conservan siempre en su numero, con su arte de antes.
#ifndef MAPEADO_H
#define MAPEADO_H

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace mapeado {

// Color de GBA (BGR555), o TRANSPARENTE.
typedef uint16_t Color;
const Color TRANSPARENTE = 0x8000;

Color DeRgb(int r, int g, int b);
void ARgb(Color c, int *r, int *g, int *b);

enum Capa { CAPA_BAJA, CAPA_MEDIA, CAPA_ALTA, NUM_CAPAS };

struct Imagen {
    int ancho = 0, alto = 0;
    std::vector<Color> px;

    Imagen() {}
    Imagen(int w, int h) : ancho(w), alto(h), px(w * h, TRANSPARENTE) {}
    Color &en(int x, int y) { return px[y * ancho + x]; }
    Color en(int x, int y) const { return px[y * ancho + x]; }
};

// Lo que el juego sabe cargar (include/fieldmap.h y include/global.fieldmap.h).
struct Formato {
    int maxTiles = 1008;
    int maxMetatiles = 0x7FFF;
    int maxPaletas = 13;
    uint16_t mascaraId = 0x7FFF;
    uint16_t mascaraColision = 0x8000;
};

typedef std::array<uint8_t, 64> Tile;        // indices de color 0-15, por filas
typedef std::array<Color, 16> Paleta;        // la 0 es la transparente
typedef std::array<uint16_t, 12> Metatile;   // 4 entradas por capa: baja, media, alta

struct Tileset {
    std::vector<Tile> tiles;
    std::vector<Paleta> paletas;
    std::vector<Metatile> metatiles;
    std::vector<uint16_t> atributos;
};

struct Layout {
    std::string nombre;
    int ancho = 0, alto = 0;              // en casillas
    Imagen capas[NUM_CAPAS];              // ancho*16 x alto*16
    bool tieneArteBorde = false;
    Imagen borde[NUM_CAPAS];              // 32x32, si tieneArteBorde
    std::vector<uint16_t> bloques;        // los de antes; vacio si no habia
    std::vector<uint16_t> bloquesBorde;   // los 4 de antes
};

struct Fijado {
    std::string nombre;
    int metatile;
};

struct Entrada {
    Formato formato;
    Tileset anterior;
    std::vector<Layout> layouts;          // todos los que usan el tileset
    std::vector<Fijado> fijados;
    std::vector<int> tilesFijos;          // tiles que no se tocan (animaciones)
    bool compactar = false;               // renumerar sin respetar los numeros de antes
};

struct Estadisticas {
    int tiles = 0;                        // incluido el 0, transparente
    int metatiles = 0;                    // los que existen, sin contar huecos
    int metatilesHuecos = 0;              // numeros libres por debajo del ultimo
    int paletas = 0;
    std::vector<int> coloresPorPaleta;
    int metatilesNuevos = 0;
    int metatilesQuitados = 0;
    std::vector<int> metatilesPorLayout;  // metatiles distintos en cada layout
};

struct Salida {
    Tileset tileset;
    std::vector<std::vector<uint16_t>> bloques;
    std::vector<std::vector<uint16_t>> bloquesBorde;
    Estadisticas est;
    std::vector<std::string> avisos;
};

// Devuelve false y deja el motivo en `error` si no cabe o el arte no es valido.
bool Compilar(const Entrada &entrada, Salida &salida, std::string &error);

// Lo contrario: las tres capas de un metatile, o de un mapa entero, desde el tileset.
void PintarMetatile(const Tileset &ts, int metatile, Imagen capas[NUM_CAPAS], int x0, int y0);
void PintarLayout(const Tileset &ts, const std::vector<uint16_t> &bloques, int ancho, int alto,
                  uint16_t mascaraId, Imagen capas[NUM_CAPAS]);

} // namespace mapeado

#endif // MAPEADO_H

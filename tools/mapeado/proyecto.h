// Los archivos del proyecto que lee y escribe la linea de comandos. La biblioteca
// (mapeado.h) no sabe nada de esto.
#ifndef MAPEADO_PROYECTO_H
#define MAPEADO_PROYECTO_H

#include "mapeado.h"

#include <string>
#include <vector>

namespace proyecto {

struct InfoLayout {
    std::string id, nombre;
    int ancho = 0, alto = 0;
    std::string tileset;                  // primary_tileset de layouts.json
    std::string blockdata, borde;
    std::string carpeta;                  // la del blockdata
};

struct InfoTileset {
    std::string etiqueta;                 // gTileset_Principal
    std::string tiles;                    // .png
    // Las paletas del tileset, .pal. Con un INCBIN de palettes.gbapal en graphics.h son
    // todas las palettes/NN.pal de su carpeta (00, 01...), que el Makefile junta.
    std::vector<std::string> paletas;
    std::string carpetaPaletas;           // esa carpeta; vacia si van en una lista
    std::string metatiles, atributos;
    // La paleta del tileset de cada entrada de metatile, un byte por entrada. Vacio si
    // el tileset no tiene (entonces la paleta es la de la entrada, y no pasa de 15).
    std::string paletasMetatiles;
    // Sus animaciones (animations.bin, ver CargarAnimaciones). Vacio si no tiene.
    std::string animaciones;
};

extern const char *const kNombreCapa[mapeado::NUM_CAPAS]; // baja, media, alta

bool LeerFormato(mapeado::Formato &f, std::string &error);
bool LeerLayouts(std::vector<InfoLayout> &layouts, std::string &error);
bool LeerInfoTileset(const std::string &etiqueta, InfoTileset &info, std::string &error);
std::vector<mapeado::Fijado> LeerFijados(const std::string &etiqueta);
// tiles_fijos.txt junto al tiles.png: numeros o rangos (a-b), uno por linea, # comenta.
std::vector<int> LeerTilesFijos(const InfoTileset &info);

bool CargarTileset(const InfoTileset &info, mapeado::Tileset &ts, std::string &error);
bool CargarBloques(const std::string &ruta, std::vector<uint16_t> &bloques);
// Cualquier PNG. Transparente: sin opacidad, o el magenta 248,0,248.
bool CargarImagen(const std::string &ruta, mapeado::Imagen &img, std::string &error);

// Escriben solo si el contenido cambia. Devuelven false si no se pudo escribir.
bool GuardarTileset(const InfoTileset &info, const mapeado::Tileset &ts, int *cambiados, std::string &error);
bool GuardarBloques(const std::string &ruta, const std::vector<uint16_t> &bloques, int *cambiados);
bool GuardarCapa(const std::string &ruta, const mapeado::Imagen &img, int *cambiados);
// En layouts.json, los layouts con el tileset `de` pasan a usar `a`.
bool CambiarTilesetDeLayouts(const std::string &de, const std::string &a, int *cambiados);

bool Existe(const std::string &ruta);
std::string RutaPaleta(const std::string &carpeta, int n); // carpeta/NN.pal

} // namespace proyecto

#endif // MAPEADO_PROYECTO_H

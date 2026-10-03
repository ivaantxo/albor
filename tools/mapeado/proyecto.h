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
    std::string carpeta;                  // la del blockdata, donde va el arte
};

struct InfoTileset {
    std::string etiqueta;                 // gTileset_Principal
    std::string tiles;                    // .png
    std::vector<std::string> paletas;     // .pal
    std::string metatiles, atributos;
};

// Nombres de las capas: <carpeta>/baja.png ... y <carpeta>/borde_baja.png ...
extern const char *const kNombreCapa[mapeado::NUM_CAPAS];
std::string RutaCapa(const InfoLayout &l, int capa, bool borde);
bool TieneArte(const InfoLayout &l);

bool LeerFormato(mapeado::Formato &f, std::string &error);
bool LeerLayouts(std::vector<InfoLayout> &layouts, std::string &error);
bool LeerInfoTileset(const std::string &etiqueta, InfoTileset &info, std::string &error);
std::vector<mapeado::Fijado> LeerFijados(const std::string &etiqueta);
// tiles_fijos.txt junto al tiles.png: numeros o rangos (a-b), uno por linea, # comenta.
std::vector<int> LeerTilesFijos(const InfoTileset &info);

bool CargarTileset(const InfoTileset &info, mapeado::Tileset &ts, std::string &error);
bool CargarBloques(const std::string &ruta, std::vector<uint16_t> &bloques);
bool CargarCapa(const std::string &ruta, int ancho, int alto, mapeado::Imagen &img, std::string &error);

// Escriben solo si el contenido cambia. Devuelven false si no se pudo escribir.
bool GuardarTileset(const InfoTileset &info, const mapeado::Tileset &ts, int *cambiados);
bool GuardarBloques(const std::string &ruta, const std::vector<uint16_t> &bloques, int *cambiados);
bool GuardarCapa(const std::string &ruta, const mapeado::Imagen &img, int *cambiados);

bool Existe(const std::string &ruta);

} // namespace proyecto

#endif // MAPEADO_PROYECTO_H

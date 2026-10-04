#ifndef MAPEADO_ARCHIVO_PNG_H
#define MAPEADO_ARCHIVO_PNG_H

#include <cstdint>
#include <string>
#include <vector>

// Cualquier PNG, pasado a RGBA de 8 bits.
bool LeerPngRgba(const std::string &ruta, int *ancho, int *alto, std::vector<uint8_t> &rgba, std::string &error);
// Un PNG con paleta, con los indices tal cual.
bool LeerPngIndices(const std::string &ruta, int *ancho, int *alto, std::vector<uint8_t> &indices, std::string &error);
// Los colores de la paleta de un PNG (r, g, b seguidos); false si no tiene.
bool LeerPngPaleta(const std::string &ruta, std::vector<uint8_t> &rgb);

// Los PNG se escriben en memoria, para no tocar el archivo si no cambia.
std::vector<uint8_t> PngRgba(int ancho, int alto, const std::vector<uint8_t> &rgba);
std::vector<uint8_t> PngIndices(int ancho, int alto, const std::vector<uint8_t> &indices,
                                const std::vector<uint8_t> &paletaRgb);

#endif // MAPEADO_ARCHIVO_PNG_H

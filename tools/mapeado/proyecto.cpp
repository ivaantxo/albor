#include "proyecto.h"

#include "archivo_png.h"
#include "../mapjson/json11.h"

#include <cstdio>
#include <fstream>
#include <regex>
#include <sstream>
#include <sys/stat.h>

namespace proyecto {

using namespace mapeado;

const char *const kNombreCapa[NUM_CAPAS] = {"baja", "media", "alta"};

namespace {

std::string LeerTexto(const std::string &ruta)
{
    std::ifstream f(ruta, std::ios::binary);
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

bool LeerBytes(const std::string &ruta, std::vector<uint8_t> &datos)
{
    std::ifstream f(ruta, std::ios::binary);
    if (!f)
        return false;
    datos.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
    return true;
}

bool EscribirSiCambia(const std::string &ruta, const std::vector<uint8_t> &datos, int *cambiados)
{
    std::vector<uint8_t> antes;
    if (LeerBytes(ruta, antes) && antes == datos)
        return true;
    std::ofstream f(ruta, std::ios::binary | std::ios::trunc);
    if (!f)
        return false;
    f.write(reinterpret_cast<const char *>(datos.data()), datos.size());
    if (cambiados)
        (*cambiados)++;
    return bool(f);
}

std::vector<uint8_t> U16(const std::vector<uint16_t> &v)
{
    std::vector<uint8_t> r;
    for (uint16_t x : v) {
        r.push_back(x & 0xFF);
        r.push_back(x >> 8);
    }
    return r;
}

std::string Carpeta(const std::string &ruta)
{
    size_t i = ruta.rfind('/');
    return i == std::string::npos ? "." : ruta.substr(0, i);
}

std::string CambiaFinal(const std::string &s, const std::string &de, const std::string &a)
{
    if (s.size() >= de.size() && s.compare(s.size() - de.size(), de.size(), de) == 0)
        return s.substr(0, s.size() - de.size()) + a;
    return s;
}

bool Define(const std::string &texto, const std::string &nombre, int *valor)
{
    std::smatch m;
    if (!std::regex_search(texto, m, std::regex("#define\\s+" + nombre + "\\s+([0-9A-Fa-fx]+)")))
        return false;
    *valor = std::stoi(m[1].str(), nullptr, 0);
    return true;
}

bool Incbin(const std::string &texto, const std::string &etiqueta, std::string *ruta)
{
    std::smatch m;
    if (!std::regex_search(texto, m, std::regex(etiqueta + "\\[\\]\\s*=\\s*INCBIN_U(?:16|32)\\(\"([^\"]+)\"\\)")))
        return false;
    *ruta = m[1].str();
    return true;
}

} // namespace

bool Existe(const std::string &ruta)
{
    struct stat st;
    return stat(ruta.c_str(), &st) == 0;
}

std::string RutaCapa(const InfoLayout &l, int capa, bool borde)
{
    return l.carpeta + "/" + (borde ? "borde_" : "") + kNombreCapa[capa] + ".png";
}

bool TieneArte(const InfoLayout &l)
{
    for (int c = 0; c < NUM_CAPAS; c++)
        if (Existe(RutaCapa(l, c, false)))
            return true;
    return false;
}

bool LeerFormato(Formato &f, std::string &error)
{
    std::string fieldmap = LeerTexto("include/fieldmap.h");
    std::string global = LeerTexto("include/global.fieldmap.h");
    int id, colision;
    if (!Define(fieldmap, "NUM_TILES_IN_PRIMARY", &f.maxTiles) ||
        !Define(fieldmap, "NUM_METATILES_IN_PRIMARY", &f.maxMetatiles) ||
        !Define(fieldmap, "NUM_PALS_IN_PRIMARY", &f.maxPaletas) ||
        !Define(global, "MAPGRID_METATILE_ID_MASK", &id) ||
        !Define(global, "MAPGRID_COLLISION_MASK", &colision)) {
        error = "No se encuentran los limites en include/fieldmap.h e include/global.fieldmap.h"
                " (hay que ejecutar esto desde la raiz del proyecto)";
        return false;
    }
    f.mascaraId = id;
    f.mascaraColision = colision;
    return true;
}

bool LeerLayouts(std::vector<InfoLayout> &layouts, std::string &error)
{
    std::string err;
    json11::Json json = json11::Json::parse(LeerTexto("data/layouts/layouts.json"), err);
    if (!err.empty()) {
        error = "data/layouts/layouts.json: " + err;
        return false;
    }
    for (const json11::Json &j : json["layouts"].array_items()) {
        if (j["id"].is_null())
            continue;
        InfoLayout l;
        l.id = j["id"].string_value();
        l.nombre = j["name"].string_value();
        l.ancho = j["width"].int_value();
        l.alto = j["height"].int_value();
        l.tileset = j["primary_tileset"].string_value();
        l.blockdata = j["blockdata_filepath"].string_value();
        l.borde = j["border_filepath"].string_value();
        l.carpeta = Carpeta(l.blockdata);
        layouts.push_back(l);
    }
    return true;
}

bool LeerInfoTileset(const std::string &etiqueta, InfoTileset &info, std::string &error)
{
    std::string cabeceras = LeerTexto("src/data/tilesets/headers.h");
    std::string graficos = LeerTexto("src/data/tilesets/graphics.h");
    std::string metatiles = LeerTexto("src/data/tilesets/metatiles.h");
    info = InfoTileset();
    info.etiqueta = etiqueta;

    std::smatch m;
    if (!std::regex_search(cabeceras, m, std::regex("struct Tileset " + etiqueta + "\\s*=\\s*\\{([^}]*)\\}"))) {
        error = "No se encuentra " + etiqueta + " en src/data/tilesets/headers.h";
        return false;
    }
    std::string cuerpo = m[1].str();
    auto campo = [&](const std::string &nombre) {
        std::smatch c;
        return std::regex_search(cuerpo, c, std::regex("\\." + nombre + "\\s*=\\s*(\\w+)")) ? c[1].str() : "";
    };

    bool bien = true;
    std::string ruta;
    if (Incbin(graficos, campo("tiles"), &ruta))
        info.tiles = CambiaFinal(CambiaFinal(ruta, ".lz", ""), ".4bpp", ".png");
    else
        bien = false;
    if (Incbin(metatiles, campo("metatiles"), &ruta))
        info.metatiles = ruta;
    else
        bien = false;
    if (Incbin(metatiles, campo("metatileAttributes"), &ruta))
        info.atributos = ruta;
    else
        bien = false;
    std::string pal = campo("palettes");
    if (!pal.empty() &&
        std::regex_search(graficos, m, std::regex(pal + "\\[\\]\\[16\\]\\s*=\\s*\\{([^}]*)\\}"))) {
        std::string lista = m[1].str();
        std::regex inc("INCBIN_U16\\(\"([^\"]+)\"\\)");
        for (auto it = std::sregex_iterator(lista.begin(), lista.end(), inc); it != std::sregex_iterator(); ++it)
            info.paletas.push_back(CambiaFinal((*it)[1].str(), ".gbapal", ".pal"));
    }
    if (!bien || info.paletas.empty()) {
        error = "No se encuentran los archivos de " + etiqueta + " en src/data/tilesets/graphics.h y metatiles.h";
        return false;
    }
    return true;
}

std::vector<Fijado> LeerFijados(const std::string &etiqueta)
{
    std::vector<Fijado> r;
    std::string corto = etiqueta;
    if (corto.rfind("gTileset_", 0) == 0)
        corto = corto.substr(9);
    std::string texto = LeerTexto("include/constants/metatile_labels.h");
    std::regex re("#define\\s+(METATILE_" + corto + "_\\w+)\\s+(0x[0-9A-Fa-f]+|[0-9]+)");
    for (auto it = std::sregex_iterator(texto.begin(), texto.end(), re); it != std::sregex_iterator(); ++it)
        r.push_back(Fijado{(*it)[1].str(), std::stoi((*it)[2].str(), nullptr, 0)});
    return r;
}

std::vector<int> LeerTilesFijos(const InfoTileset &info)
{
    std::vector<int> r;
    std::istringstream texto(LeerTexto(Carpeta(info.tiles) + "/tiles_fijos.txt"));
    std::string linea;
    while (std::getline(texto, linea)) {
        linea = linea.substr(0, linea.find('#'));
        int a, b;
        if (sscanf(linea.c_str(), "%i - %i", &a, &b) == 2 || sscanf(linea.c_str(), "%i-%i", &a, &b) == 2) {
            for (int t = a; t <= b; t++)
                r.push_back(t);
        } else if (sscanf(linea.c_str(), "%i", &a) == 1) {
            r.push_back(a);
        }
    }
    return r;
}

bool CargarTileset(const InfoTileset &info, Tileset &ts, std::string &error)
{
    ts = Tileset();
    int w, h;
    std::vector<uint8_t> idx;
    if (!LeerPngIndices(info.tiles, &w, &h, idx, error))
        return false;
    if (w % 8 || h % 8) {
        error = info.tiles + " no mide un numero entero de tiles de 8x8";
        return false;
    }
    for (int ty = 0; ty < h / 8; ty++)
        for (int tx = 0; tx < w / 8; tx++) {
            Tile t;
            for (int y = 0; y < 8; y++)
                for (int x = 0; x < 8; x++)
                    t[y * 8 + x] = idx[(ty * 8 + y) * w + tx * 8 + x] & 0xF;
            ts.tiles.push_back(t);
        }

    for (const std::string &ruta : info.paletas) {
        Paleta p;
        p.fill(0);
        std::istringstream texto(LeerTexto(ruta));
        std::string linea;
        for (int i = 0; i < 3; i++)
            std::getline(texto, linea);
        for (int i = 0; i < 16 && std::getline(texto, linea); i++) {
            int r, g, b;
            if (sscanf(linea.c_str(), "%d %d %d", &r, &g, &b) == 3)
                p[i] = DeRgb(r, g, b);
        }
        ts.paletas.push_back(p);
    }

    std::vector<uint16_t> datos;
    if (!CargarBloques(info.metatiles, datos)) {
        error = "No se puede leer " + info.metatiles;
        return false;
    }
    for (size_t i = 0; i + 12 <= datos.size(); i += 12) {
        Metatile m;
        std::copy(datos.begin() + i, datos.begin() + i + 12, m.begin());
        ts.metatiles.push_back(m);
    }
    if (!CargarBloques(info.atributos, ts.atributos)) {
        error = "No se puede leer " + info.atributos;
        return false;
    }
    return true;
}

bool CargarBloques(const std::string &ruta, std::vector<uint16_t> &bloques)
{
    std::vector<uint8_t> b;
    bloques.clear();
    if (!LeerBytes(ruta, b))
        return false;
    for (size_t i = 0; i + 1 < b.size(); i += 2)
        bloques.push_back(b[i] | (b[i + 1] << 8));
    return true;
}

bool CargarCapa(const std::string &ruta, int ancho, int alto, Imagen &img, std::string &error)
{
    img = Imagen(ancho, alto);
    if (!Existe(ruta))
        return true; // una capa que no esta se queda transparente
    int w, h;
    std::vector<uint8_t> rgba;
    if (!LeerPngRgba(ruta, &w, &h, rgba, error))
        return false;
    if (w != ancho || h != alto) {
        error = ruta + " mide " + std::to_string(w) + "x" + std::to_string(h) + " y tiene que medir " +
                std::to_string(ancho) + "x" + std::to_string(alto);
        return false;
    }
    for (int i = 0; i < w * h; i++) {
        int r = rgba[i * 4], g = rgba[i * 4 + 1], b = rgba[i * 4 + 2], a = rgba[i * 4 + 3];
        Color c = DeRgb(r, g, b);
        // Transparente: sin opacidad, o el magenta que usan porytiles y las paletas.
        img.px[i] = (a < 128 || c == DeRgb(248, 0, 248)) ? TRANSPARENTE : c;
    }
    return true;
}

bool GuardarTileset(const InfoTileset &info, const Tileset &ts, int *cambiados)
{
    const int porFila = 16;
    int filas = (ts.tiles.size() + porFila - 1) / porFila;
    std::vector<uint8_t> idx(porFila * 8 * filas * 8, 0);
    for (size_t t = 0; t < ts.tiles.size(); t++)
        for (int y = 0; y < 8; y++)
            for (int x = 0; x < 8; x++)
                idx[((t / porFila) * 8 + y) * porFila * 8 + (t % porFila) * 8 + x] = ts.tiles[t][y * 8 + x];
    std::vector<uint8_t> grises;
    for (int i = 0; i < 16; i++)
        for (int k = 0; k < 3; k++)
            grises.push_back(i * 16);
    bool bien = EscribirSiCambia(info.tiles, PngIndices(porFila * 8, filas * 8, idx, grises), cambiados);

    for (size_t p = 0; p < info.paletas.size() && p < ts.paletas.size(); p++) {
        std::string texto = "JASC-PAL\r\n0100\r\n16\r\n";
        for (int i = 0; i < 16; i++) {
            int r = 248, g = 0, b = 248;
            if (ts.paletas[p][i] != TRANSPARENTE)
                ARgb(ts.paletas[p][i], &r, &g, &b);
            texto += std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b) + "\r\n";
        }
        bien &= EscribirSiCambia(info.paletas[p], std::vector<uint8_t>(texto.begin(), texto.end()), cambiados);
    }

    std::vector<uint16_t> metatiles;
    for (const Metatile &m : ts.metatiles)
        metatiles.insert(metatiles.end(), m.begin(), m.end());
    bien &= EscribirSiCambia(info.metatiles, U16(metatiles), cambiados);
    bien &= EscribirSiCambia(info.atributos, U16(ts.atributos), cambiados);
    return bien;
}

bool GuardarBloques(const std::string &ruta, const std::vector<uint16_t> &bloques, int *cambiados)
{
    return EscribirSiCambia(ruta, U16(bloques), cambiados);
}

bool GuardarCapa(const std::string &ruta, const Imagen &img, int *cambiados)
{
    std::vector<uint8_t> rgba(img.ancho * img.alto * 4, 0);
    for (int i = 0; i < img.ancho * img.alto; i++) {
        if (img.px[i] == TRANSPARENTE)
            continue;
        int r, g, b;
        ARgb(img.px[i], &r, &g, &b);
        rgba[i * 4] = r;
        rgba[i * 4 + 1] = g;
        rgba[i * 4 + 2] = b;
        rgba[i * 4 + 3] = 255;
    }
    return EscribirSiCambia(ruta, PngRgba(img.ancho, img.alto, rgba), cambiados);
}

} // namespace proyecto

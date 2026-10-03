// mapeado: linea de comandos del motor de mapeado. Ver mapeado.h y README.md.
//
// Lo de verdad va a ir dentro de porymap. Esto sirve para usarlo y probarlo sin el.
#include "mapeado.h"
#include "proyecto.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>
#include <vector>

using namespace mapeado;
using namespace proyecto;

namespace {

const char *const kUso =
    "uso: mapeado <orden> ...\n"
    "\n"
    "  estampar <mapa> <capa> <x> <y> <pieza.png> [--reemplazar]\n"
    "      pinta la pieza en la capa (baja, media o alta) del mapa, con su esquina en\n"
    "      (x, y) pixeles, multiplos de 8, y mete en el tileset lo que falte. Si no\n"
    "      cabe, no toca nada y dice que falta. Con --reemplazar, lo transparente de la\n"
    "      pieza borra la capa; sin el, deja lo que hubiera debajo\n"
    "  optimizar [tileset...] [--compactar]\n"
    "      reempaqueta el tileset desde lo pintado: junta metatiles duplicados, quita\n"
    "      los que no usa ningun mapa y libera tiles y colores. --compactar ademas\n"
    "      renumera desde cero para quitar los huecos\n"
    "  cuentas [tileset...]\n"
    "      lo que ocupa cada tileset ahora, y lo que ocuparia optimizado\n"
    "  exportar <mapa> <carpeta>\n"
    "      las tres capas del mapa en PNG, para mirarlas\n"
    "\n"
    "El mapa se nombra por su layout: Test, Test_Layout o LAYOUT_TEST. El tileset, con o\n"
    "sin gTileset_. Sin nombrar ninguno, se hacen todos los que use algun layout. Se\n"
    "ejecuta desde la raiz del proyecto.\n";

std::string Etiqueta(const std::string &nombre)
{
    return nombre.rfind("gTileset_", 0) == 0 ? nombre : "gTileset_" + nombre;
}

// Un tileset con todos sus mapas, cargado.
struct Cargado {
    InfoTileset info;
    Tileset ts;
    std::vector<InfoLayout> layouts;
    std::vector<MapaDelTileset> mapas;
};

bool Cargar(const std::vector<InfoLayout> &todos, const std::string &etiqueta, Cargado &c, std::string &error)
{
    if (!LeerInfoTileset(etiqueta, c.info, error) || !CargarTileset(c.info, c.ts, error))
        return false;
    for (const InfoLayout &l : todos) {
        if (l.tileset != etiqueta)
            continue;
        MapaDelTileset m;
        m.nombre = l.nombre;
        m.ancho = l.ancho;
        m.alto = l.alto;
        if (!CargarBloques(l.blockdata, m.bloques) || (int)m.bloques.size() != l.ancho * l.alto) {
            error = l.nombre + ": " + l.blockdata + " no tiene " + std::to_string(l.ancho) + "x" +
                    std::to_string(l.alto) + " bloques";
            return false;
        }
        CargarBloques(l.borde, m.borde);
        m.borde.resize(4, 0);
        c.layouts.push_back(l);
        c.mapas.push_back(m);
    }
    return true;
}

bool Guardar(const Cargado &c, const Tileset &ts, const std::vector<std::vector<uint16_t>> &bloques,
             const std::vector<std::vector<uint16_t>> &bordes, int *cambiados)
{
    bool bien = GuardarTileset(c.info, ts, cambiados);
    for (size_t i = 0; i < c.layouts.size(); i++) {
        bien &= GuardarBloques(c.layouts[i].blockdata, bloques[i], cambiados);
        bien &= GuardarBloques(c.layouts[i].borde, bordes[i], cambiados);
    }
    return bien;
}

// Lo que el tileset tiene en uso ahora.
void CuentasActuales(const Formato &f, const Cargado &c)
{
    std::set<int> tiles, metatiles;
    std::vector<std::set<int>> colores(c.ts.paletas.size());
    for (const MapaDelTileset &m : c.mapas)
        for (auto *lista : {&m.bloques, &m.borde})
            for (uint16_t b : *lista)
                metatiles.insert(b & f.mascaraId);
    for (const Metatile &m : c.ts.metatiles)
        for (uint16_t e : m) {
            int t = e & 0x3FF, p = e >> 12;
            if (t == 0 || t >= (int)c.ts.tiles.size())
                continue;
            tiles.insert(t);
            if (p < (int)colores.size())
                for (uint8_t i : c.ts.tiles[t])
                    if (i)
                        colores[p].insert(i);
        }
    int paletas = 0;
    for (auto &s : colores)
        paletas += !s.empty();
    printf("%s: %d/%d tiles (%d en uso), %d metatiles (%d en los mapas), %d/%d paletas, colores por paleta:",
           c.info.etiqueta.c_str(), (int)c.ts.tiles.size(), f.maxTiles, (int)tiles.size() + 1,
           (int)c.ts.metatiles.size(), (int)metatiles.size(), paletas, f.maxPaletas);
    for (auto &s : colores)
        printf(" %d", (int)s.size());
    printf("\n");
}

void CuentasOptimizado(const Formato &f, const Estadisticas &est)
{
    printf("  optimizado: %d/%d tiles, %d metatiles", est.tiles, f.maxTiles, est.metatiles);
    if (est.metatilesHuecos)
        printf(" (y %d huecos)", est.metatilesHuecos);
    printf(", %d/%d paletas, colores por paleta:", est.paletas, f.maxPaletas);
    for (int n : est.coloresPorPaleta)
        printf(" %d", n);
    printf("\n");
}

const InfoLayout *BuscaLayout(const std::vector<InfoLayout> &todos, const std::string &nombre)
{
    for (const InfoLayout &l : todos) {
        size_t barra = l.carpeta.rfind('/');
        std::string carpeta = barra == std::string::npos ? l.carpeta : l.carpeta.substr(barra + 1);
        if (l.nombre == nombre || l.id == nombre || carpeta == nombre)
            return &l;
    }
    return nullptr;
}

int OrdenEstampar(const Formato &f, const std::vector<InfoLayout> &todos, const std::vector<std::string> &args,
                  bool reemplazar)
{
    if (args.size() != 5) {
        fprintf(stderr, "estampar <mapa> <capa> <x> <y> <pieza.png>\n");
        return 1;
    }
    const InfoLayout *l = BuscaLayout(todos, args[0]);
    if (!l) {
        fprintf(stderr, "no hay ningun layout que se llame %s\n", args[0].c_str());
        return 1;
    }
    int capa = -1;
    for (int c = 0; c < NUM_CAPAS; c++)
        if (args[1] == kNombreCapa[c])
            capa = c;
    if (capa < 0) {
        fprintf(stderr, "la capa es baja, media o alta\n");
        return 1;
    }
    std::string error;
    Cargado c;
    Imagen pieza;
    if (!Cargar(todos, l->tileset, c, error) || !CargarImagen(args[4], pieza, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    int objetivo = 0;
    while (c.layouts[objetivo].nombre != l->nombre)
        objetivo++;

    Estampado r = Estampar(f, c.ts, c.mapas, objetivo, pieza, atoi(args[2].c_str()), atoi(args[3].c_str()),
                           (Capa)capa, reemplazar, LeerTilesFijos(c.info));
    if (r.resultado != ESTAMPADO) {
        fprintf(stderr, "%s: no se pinta: %s\n", l->nombre.c_str(), r.mensaje.c_str());
        return 2;
    }
    std::vector<std::vector<uint16_t>> bloques, bordes;
    for (const MapaDelTileset &m : c.mapas) {
        bloques.push_back(m.bloques);
        bordes.push_back(m.borde);
    }
    int cambiados = 0;
    if (!Guardar(c, c.ts, bloques, bordes, &cambiados)) {
        fprintf(stderr, "no se han podido escribir todos los archivos\n");
        return 1;
    }
    printf("%s: %d casillas, %d metatiles nuevos, %d tiles nuevos, %d colores nuevos\n", l->nombre.c_str(),
           r.casillas, r.metatilesNuevos, r.tilesNuevos, r.coloresNuevos);
    return 0;
}

int OrdenOptimizar(const Formato &f, const std::vector<InfoLayout> &todos, const std::string &etiqueta,
                   bool escribir, bool compactar)
{
    std::string error;
    Cargado c;
    if (!Cargar(todos, etiqueta, c, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    Salida s;
    if (!Optimizar(f, c.ts, c.mapas, LeerFijados(etiqueta), LeerTilesFijos(c.info), compactar, s, error)) {
        fprintf(stderr, "%s: %s\n", etiqueta.c_str(), error.c_str());
        return 1;
    }
    for (const std::string &a : s.avisos)
        printf("  aviso: %s\n", a.c_str());
    if (!escribir) {
        CuentasActuales(f, c);
        CuentasOptimizado(f, s.est);
        return 0;
    }
    int cambiados = 0;
    if (!Guardar(c, s.tileset, s.bloques, s.bloquesBorde, &cambiados)) {
        fprintf(stderr, "%s: no se han podido escribir todos los archivos\n", etiqueta.c_str());
        return 1;
    }
    CuentasOptimizado(f, s.est);
    printf("  %d metatiles quitados o juntados; %d archivos cambiados\n", s.est.metatilesQuitados, cambiados);
    return 0;
}

int OrdenExportar(const Formato &f, const std::vector<InfoLayout> &todos, const std::vector<std::string> &args)
{
    if (args.size() != 2) {
        fprintf(stderr, "exportar <mapa> <carpeta>\n");
        return 1;
    }
    const InfoLayout *l = BuscaLayout(todos, args[0]);
    if (!l) {
        fprintf(stderr, "no hay ningun layout que se llame %s\n", args[0].c_str());
        return 1;
    }
    std::string error;
    Cargado c;
    if (!Cargar(todos, l->tileset, c, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    for (const MapaDelTileset &m : c.mapas) {
        if (m.nombre != l->nombre)
            continue;
        Imagen capas[NUM_CAPAS];
        PintarLayout(c.ts, m.bloques, m.ancho, m.alto, f.mascaraId, capas);
        for (int k = 0; k < NUM_CAPAS; k++) {
            std::string ruta = args[1] + "/" + kNombreCapa[k] + ".png";
            if (!GuardarCapa(ruta, capas[k], nullptr)) {
                fprintf(stderr, "no se puede escribir %s\n", ruta.c_str());
                return 1;
            }
            printf("%s\n", ruta.c_str());
        }
    }
    return 0;
}

} // namespace

int main(int argc, char **argv)
{
    if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        fputs(kUso, argc < 2 ? stderr : stdout);
        return argc < 2 ? 1 : 0;
    }
    std::string orden = argv[1];
    bool compactar = false, reemplazar = false;
    std::vector<std::string> args;
    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "--compactar"))
            compactar = true;
        else if (!strcmp(argv[i], "--reemplazar"))
            reemplazar = true;
        else if (argv[i][0] == '-' && !(argv[i][1] >= '0' && argv[i][1] <= '9')) {
            fprintf(stderr, "opcion desconocida: %s\n\n%s", argv[i], kUso);
            return 1;
        } else
            args.push_back(argv[i]);
    }

    std::string error;
    Formato formato;
    std::vector<InfoLayout> layouts;
    if (!LeerFormato(formato, error) || !LeerLayouts(layouts, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }

    if (orden == "estampar")
        return OrdenEstampar(formato, layouts, args, reemplazar);
    if (orden == "exportar")
        return OrdenExportar(formato, layouts, args);
    if (orden == "optimizar" || orden == "cuentas") {
        std::vector<std::string> tilesets;
        for (const std::string &a : args)
            tilesets.push_back(Etiqueta(a));
        if (tilesets.empty()) {
            std::set<std::string> vistos;
            for (const InfoLayout &l : layouts)
                if (vistos.insert(l.tileset).second)
                    tilesets.push_back(l.tileset);
        }
        int fallos = 0;
        for (const std::string &t : tilesets)
            fallos += OrdenOptimizar(formato, layouts, t, orden == "optimizar", compactar) != 0;
        return fallos ? 1 : 0;
    }
    fprintf(stderr, "orden desconocida: %s\n\n%s", orden.c_str(), kUso);
    return 1;
}

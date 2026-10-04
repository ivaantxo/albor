// mapeado: linea de comandos del motor de mapeado. Ver mapeado.h y README.md.
//
// Lo de verdad va a ir dentro de porymap. Esto sirve para usarlo y probarlo sin el.
#include "mapeado.h"
#include "proyecto.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
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
    "      los que no usa ningun mapa, libera tiles y colores y reparte los colores\n"
    "      para que cada mapa cargue las menos paletas posibles. --compactar ademas\n"
    "      renumera desde cero para quitar los huecos\n"
    "  cuentas [tileset...]\n"
    "      lo que ocupa cada tileset ahora, y lo que ocuparia optimizado, con las\n"
    "      paletas que carga cada mapa (cada uno carga solo las de sus metatiles)\n"
    "  exportar <mapa> <carpeta>\n"
    "      las tres capas del mapa en PNG, para mirarlas\n"
    "  animar <tileset> <nombre> <carpeta> [--cada N]\n"
    "      mete en el tileset una animacion con los fotogramas de la carpeta (00.png,\n"
    "      01.png... o 0.png, 1.png..., todos del mismo tamano), o la cambia si ya hay\n"
    "      una con ese nombre. Cada fotograma dura N fotogramas del juego (16 si no se\n"
    "      dice). Al pintar, el fotograma 0 se anima solo\n"
    "  animar <tileset> <nombre> --quitar\n"
    "      quita la animacion: sus tiles se quedan con el fotograma 0\n"
    "  juntar <tileset> <otro tileset>\n"
    "      mete todo el otro tileset en el primero, pasa sus mapas al primero y\n"
    "      optimiza, para que se junte lo repetido. El otro queda sin usar\n"
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
    std::string error;
    bool bien = GuardarTileset(c.info, ts, cambiados, error);
    if (!error.empty()) {
        fprintf(stderr, "%s\n", error.c_str());
        return false;
    }
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
        for (uint32_t e : m) {
            int t = TileDeEntrada(e), p = PaletaDeEntrada(e);
            if (t == 0 || t >= (int)c.ts.tiles.size())
                continue;
            tiles.insert(t);
            if (p < (int)colores.size())
                for (uint8_t i : c.ts.tiles[t])
                    if (i)
                        colores[p].insert(i);
        }
    for (const Animacion &an : c.ts.animaciones)
        for (const auto &fotograma : an.fotogramas)
            for (const Tile &t : fotograma)
                for (uint8_t i : t)
                    if (i && an.paleta < (int)colores.size())
                        colores[an.paleta].insert(i);
    int paletas = 0;
    for (auto &s : colores)
        paletas += !s.empty();
    printf("%s: %d/%d tiles (%d en uso), %d metatiles (%d en los mapas), %d paletas (%d en uso), colores por paleta:",
           c.info.etiqueta.c_str(), (int)c.ts.tiles.size(), f.maxTiles, (int)tiles.size() + 1,
           (int)c.ts.metatiles.size(), (int)metatiles.size(), (int)c.ts.paletas.size(), paletas);
    for (auto &s : colores)
        printf(" %d", (int)s.size());
    printf("\n  paletas que carga cada mapa (caben %d):", f.maxPaletas);
    for (const MapaDelTileset &m : c.mapas)
        printf(" %s %d", m.nombre.c_str(), (int)PaletasDelMapa(c.ts, m.bloques, m.borde, f.mascaraId).size());
    printf("\n");
    for (const Animacion &an : c.ts.animaciones)
        printf("  animacion %s: %d tiles desde el %d (%dx%d), %d fotogramas cada %d, paleta %d\n", an.nombre.c_str(),
               an.ancho * an.alto, an.tile, an.ancho * 8, an.alto * 8, (int)an.fotogramas.size(), an.cada, an.paleta);
}

void CuentasOptimizado(const Formato &f, const Cargado &c, const Estadisticas &est)
{
    printf("  optimizado: %d/%d tiles, %d metatiles", est.tiles, f.maxTiles, est.metatiles);
    if (est.metatilesHuecos)
        printf(" (y %d huecos)", est.metatilesHuecos);
    printf(", %d paletas en uso, colores por paleta:", est.paletas);
    for (int n : est.coloresPorPaleta)
        printf(" %d", n);
    printf("\n  paletas que carga cada mapa (caben %d):", f.maxPaletas);
    for (size_t i = 0; i < c.mapas.size() && i < est.paletasPorLayout.size(); i++)
        printf(" %s %d", c.mapas[i].nombre.c_str(), est.paletasPorLayout[i]);
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
    printf("%s: %d casillas, %d metatiles nuevos, %d tiles nuevos, %d colores nuevos, %d paletas nuevas; "
           "el mapa carga %d de %d paletas%s\n",
           l->nombre.c_str(), r.casillas, r.metatilesNuevos, r.tilesNuevos, r.coloresNuevos, r.paletasNuevas,
           r.paletasMapa, f.maxPaletas, r.paletasDeLaPieza ? " (con las paletas de la imagen)" : "");
    return 0;
}

// Los fotogramas de una carpeta: los PNG en el orden de su numero.
bool CargarFotogramas(const std::string &carpeta, std::vector<Imagen> &fotogramas, std::string &error)
{
    std::vector<std::pair<int, std::string>> archivos;
    if (DIR *d = opendir(carpeta.c_str())) {
        while (struct dirent *e = readdir(d)) {
            std::string nombre = e->d_name;
            if (nombre.size() > 4 && nombre.compare(nombre.size() - 4, 4, ".png") == 0 && isdigit((unsigned char)nombre[0]))
                archivos.push_back(std::make_pair(atoi(nombre.c_str()), nombre));
        }
        closedir(d);
    } else {
        error = "no se puede abrir la carpeta " + carpeta;
        return false;
    }
    std::sort(archivos.begin(), archivos.end());
    for (auto &a : archivos) {
        Imagen im;
        if (!CargarImagen(carpeta + "/" + a.second, im, error))
            return false;
        fotogramas.push_back(im);
    }
    if (fotogramas.empty()) {
        error = carpeta + " no tiene fotogramas (00.png, 01.png...)";
        return false;
    }
    return true;
}

int OrdenAnimar(const Formato &f, const std::vector<InfoLayout> &todos, const std::vector<std::string> &args, int cada,
                bool quitar)
{
    if (args.size() != (quitar ? 2u : 3u)) {
        fprintf(stderr, "animar <tileset> <nombre> <carpeta> [--cada N]  o  animar <tileset> <nombre> --quitar\n");
        return 1;
    }
    std::string error;
    Cargado c;
    if (!Cargar(todos, Etiqueta(args[0]), c, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    const std::string &nombre = args[1];
    if (quitar) {
        if (!QuitarAnimacion(c.ts, nombre)) {
            fprintf(stderr, "%s no tiene ninguna animacion que se llame %s\n", c.info.etiqueta.c_str(), nombre.c_str());
            return 1;
        }
    } else {
        std::vector<Imagen> fotogramas;
        if (!CargarFotogramas(args[2], fotogramas, error)) {
            fprintf(stderr, "%s\n", error.c_str());
            return 1;
        }
        Estampado r = Animar(f, c.ts, c.mapas, nombre, fotogramas, cada, LeerTilesFijos(c.info));
        if (r.resultado != ESTAMPADO) {
            fprintf(stderr, "%s: no se anima: %s\n", c.info.etiqueta.c_str(), r.mensaje.c_str());
            return 2;
        }
        for (const Animacion &an : c.ts.animaciones)
            if (an.nombre == nombre)
                printf("%s: animacion %s: %d tiles desde el %d, %d fotogramas cada %d, paleta %d (%d tiles nuevos, "
                       "%d colores nuevos, %d paletas nuevas)\n",
                       c.info.etiqueta.c_str(), nombre.c_str(), an.ancho * an.alto, an.tile, (int)an.fotogramas.size(),
                       an.cada, an.paleta, r.tilesNuevos, r.coloresNuevos, r.paletasNuevas);
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
        CuentasOptimizado(f, c, s.est);
        return 0;
    }
    int cambiados = 0;
    if (!Guardar(c, s.tileset, s.bloques, s.bloquesBorde, &cambiados)) {
        fprintf(stderr, "%s: no se han podido escribir todos los archivos\n", etiqueta.c_str());
        return 1;
    }
    CuentasOptimizado(f, c, s.est);
    printf("  %d metatiles quitados o juntados; %d archivos cambiados\n", s.est.metatilesQuitados, cambiados);
    return 0;
}

int OrdenJuntar(const Formato &f, std::vector<InfoLayout> &todos, const std::vector<std::string> &args)
{
    if (args.size() != 2) {
        fprintf(stderr, "juntar <tileset> <otro tileset>\n");
        return 1;
    }
    std::string error;
    const std::string destino = Etiqueta(args[0]), origen = Etiqueta(args[1]);
    Cargado d, o;
    if (destino == origen || !Cargar(todos, destino, d, error) || !Cargar(todos, origen, o, error)) {
        fprintf(stderr, "%s\n", error.empty() ? "son el mismo tileset" : error.c_str());
        return 1;
    }
    if (o.layouts.empty()) {
        fprintf(stderr, "ningun layout usa %s: no hay nada que juntar\n", origen.c_str());
        return 1;
    }
    int primero = 0;
    if (!Juntar(f, d.ts, o.ts, &primero, error)) {
        fprintf(stderr, "%s en %s: %s\n", origen.c_str(), destino.c_str(), error.c_str());
        return 2;
    }
    int cambiados = 0;
    bool bien = GuardarTileset(d.info, d.ts, &cambiados, error);
    for (size_t i = 0; i < o.layouts.size(); i++)
        for (auto *lista : {&o.mapas[i].bloques, &o.mapas[i].borde}) {
            for (uint16_t &b : *lista)
                b = (((b & f.mascaraId) + primero) & f.mascaraId) | (b & ~f.mascaraId);
            bien &= GuardarBloques(lista == &o.mapas[i].bloques ? o.layouts[i].blockdata : o.layouts[i].borde,
                                   *lista, &cambiados);
        }
    bien &= CambiarTilesetDeLayouts(origen, destino, &cambiados);
    if (!bien) {
        fprintf(stderr, "%s\n", error.empty() ? "no se han podido escribir todos los archivos" : error.c_str());
        return 1;
    }
    printf("%s: %d tiles, %d paletas, %d metatiles (desde el %d) y %d animaciones de %s; %d layouts pasan a %s\n",
           destino.c_str(), (int)o.ts.tiles.size(), (int)o.ts.paletas.size(), (int)o.ts.metatiles.size(), primero,
           (int)o.ts.animaciones.size(), origen.c_str(), (int)o.layouts.size(), destino.c_str());
    // Lo repetido entre los dos se junta optimizando.
    todos.clear();
    if (!LeerLayouts(todos, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    if (OrdenOptimizar(f, todos, destino, true, false) != 0)
        return 1;
    printf("%s ya no lo usa ningun layout: se puede quitar de src/data/tilesets (headers.h, graphics.h y "
           "metatiles.h) y borrar su carpeta\n", origen.c_str());
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
    bool compactar = false, reemplazar = false, quitar = false;
    int cada = 16;
    std::vector<std::string> args;
    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "--compactar"))
            compactar = true;
        else if (!strcmp(argv[i], "--reemplazar"))
            reemplazar = true;
        else if (!strcmp(argv[i], "--quitar"))
            quitar = true;
        else if (!strcmp(argv[i], "--cada") && i + 1 < argc)
            cada = atoi(argv[++i]);
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
    if (orden == "animar")
        return OrdenAnimar(formato, layouts, args, cada, quitar);
    if (orden == "juntar")
        return OrdenJuntar(formato, layouts, args);
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

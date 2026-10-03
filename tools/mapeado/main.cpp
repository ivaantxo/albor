// mapeado: linea de comandos del compilador de mapeado. Ver mapeado.h y README.md.
#include "mapeado.h"
#include "proyecto.h"

#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <vector>

using namespace mapeado;
using namespace proyecto;

namespace {

const char *const kUso =
    "uso: mapeado <orden> [opciones] [tileset...]\n"
    "\n"
    "  compilar      saca el tileset y el blockdata del arte por capas de los mapas\n"
    "  cuentas       lo mismo sin escribir nada: cuanto ocupa y si cabe\n"
    "  descompilar   pinta el arte por capas desde el tileset y el blockdata de ahora\n"
    "\n"
    "  --compactar   (compilar, cuentas) renumera tiles y metatiles desde cero\n"
    "  --forzar      (descompilar) pisa el arte que ya haya\n"
    "\n"
    "El tileset se nombra como en layouts.json (gTileset_Principal) o sin el prefijo\n"
    "(Principal). Sin nombrar ninguno, compilar y cuentas hacen todos los que tengan\n"
    "algun mapa con arte. Se ejecuta desde la raiz del proyecto.\n";

std::string Etiqueta(const std::string &nombre)
{
    return nombre.rfind("gTileset_", 0) == 0 ? nombre : "gTileset_" + nombre;
}

std::vector<InfoLayout> DelTileset(const std::vector<InfoLayout> &layouts, const std::string &etiqueta)
{
    std::vector<InfoLayout> r;
    for (const InfoLayout &l : layouts)
        if (l.tileset == etiqueta)
            r.push_back(l);
    return r;
}

int Compilar(const Formato &formato, const std::vector<InfoLayout> &todos, const std::string &etiqueta,
             bool escribir, bool compactar, bool nombrado)
{
    std::vector<InfoLayout> layouts = DelTileset(todos, etiqueta);
    std::vector<std::string> sinArte;
    int conArte = 0;
    for (const InfoLayout &l : layouts) {
        if (TieneArte(l))
            conArte++;
        else
            sinArte.push_back(l.nombre);
    }
    if (conArte == 0) {
        if (nombrado)
            fprintf(stderr, "%s: ningun mapa suyo tiene arte por capas\n", etiqueta.c_str());
        return nombrado ? 1 : 0;
    }
    if (!sinArte.empty()) {
        // Se compilan todos los mapas del tileset juntos: uno sin arte se quedaria con
        // numeros de metatile que ya no son los suyos.
        for (const std::string &n : sinArte)
            fprintf(stderr, "%s: %s usa este tileset y no tiene arte por capas (mapeado descompilar %s)\n",
                    etiqueta.c_str(), n.c_str(), etiqueta.c_str());
        return 1;
    }

    std::string error;
    InfoTileset info;
    Entrada e;
    e.formato = formato;
    e.compactar = compactar;
    if (!LeerInfoTileset(etiqueta, info, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    if (Existe(info.tiles) && !CargarTileset(info, e.anterior, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    e.fijados = LeerFijados(etiqueta);
    e.tilesFijos = LeerTilesFijos(info);
    for (const InfoLayout &il : layouts) {
        Layout l;
        l.nombre = il.nombre;
        l.ancho = il.ancho;
        l.alto = il.alto;
        for (int c = 0; c < NUM_CAPAS; c++)
            if (!CargarCapa(RutaCapa(il, c, false), il.ancho * 16, il.alto * 16, l.capas[c], error)) {
                fprintf(stderr, "%s\n", error.c_str());
                return 1;
            }
        for (int c = 0; c < NUM_CAPAS; c++)
            l.tieneArteBorde |= Existe(RutaCapa(il, c, true));
        if (l.tieneArteBorde)
            for (int c = 0; c < NUM_CAPAS; c++)
                if (!CargarCapa(RutaCapa(il, c, true), 32, 32, l.borde[c], error)) {
                    fprintf(stderr, "%s\n", error.c_str());
                    return 1;
                }
        CargarBloques(il.blockdata, l.bloques);
        CargarBloques(il.borde, l.bloquesBorde);
        e.layouts.push_back(l);
    }

    Salida s;
    if (!mapeado::Compilar(e, s, error)) {
        fprintf(stderr, "%s: %s\n", etiqueta.c_str(), error.c_str());
        return 1;
    }
    int ultimaPaleta = -1;
    for (size_t p = 0; p < s.est.coloresPorPaleta.size(); p++)
        if (s.est.coloresPorPaleta[p] > 0)
            ultimaPaleta = p;
    if (ultimaPaleta >= (int)info.paletas.size()) {
        fprintf(stderr, "%s: hacen falta %d paletas y src/data/tilesets/graphics.h solo le pone %d\n",
                etiqueta.c_str(), ultimaPaleta + 1, (int)info.paletas.size());
        return 1;
    }

    const Estadisticas &est = s.est;
    printf("%s: %d/%d tiles, %d metatiles", etiqueta.c_str(), est.tiles, formato.maxTiles, est.metatiles);
    if (est.metatilesHuecos)
        printf(" (y %d huecos)", est.metatilesHuecos);
    printf(", %d/%d paletas, colores por paleta:", est.paletas, formato.maxPaletas);
    for (int n : est.coloresPorPaleta)
        printf(" %d", n);
    printf("\n");
    for (size_t i = 0; i < layouts.size(); i++)
        printf("  %s: %d metatiles distintos\n", layouts[i].nombre.c_str(), est.metatilesPorLayout[i]);
    if (est.metatilesNuevos || est.metatilesQuitados)
        printf("  %d metatiles nuevos o cambiados, %d que ya no estan\n", est.metatilesNuevos, est.metatilesQuitados);
    for (const std::string &a : s.avisos)
        printf("  aviso: %s\n", a.c_str());

    if (!escribir)
        return 0;
    int cambiados = 0;
    bool bien = GuardarTileset(info, s.tileset, &cambiados);
    for (size_t i = 0; i < layouts.size(); i++) {
        bien &= GuardarBloques(layouts[i].blockdata, s.bloques[i], &cambiados);
        bien &= GuardarBloques(layouts[i].borde, s.bloquesBorde[i], &cambiados);
    }
    if (!bien) {
        fprintf(stderr, "%s: no se han podido escribir todos los archivos\n", etiqueta.c_str());
        return 1;
    }
    if (cambiados)
        printf("  %d archivos cambiados\n", cambiados);
    return 0;
}

int Descompilar(const Formato &formato, const std::vector<InfoLayout> &todos, const std::string &etiqueta, bool forzar)
{
    std::vector<InfoLayout> layouts = DelTileset(todos, etiqueta);
    if (layouts.empty()) {
        fprintf(stderr, "%s: no lo usa ningun layout\n", etiqueta.c_str());
        return 1;
    }
    std::string error;
    InfoTileset info;
    Tileset ts;
    if (!LeerInfoTileset(etiqueta, info, error) || !CargarTileset(info, ts, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }
    int fallos = 0;
    for (const InfoLayout &l : layouts) {
        if (TieneArte(l) && !forzar) {
            printf("%s ya tiene arte por capas: no se toca (--forzar para pisarlo)\n", l.nombre.c_str());
            continue;
        }
        std::vector<uint16_t> bloques, borde;
        if (!CargarBloques(l.blockdata, bloques) || (int)bloques.size() != l.ancho * l.alto) {
            fprintf(stderr, "%s: %s no tiene %dx%d bloques\n", l.nombre.c_str(), l.blockdata.c_str(), l.ancho, l.alto);
            fallos++;
            continue;
        }
        CargarBloques(l.borde, borde);
        borde.resize(4, 0);
        Imagen capas[NUM_CAPAS], capasBorde[NUM_CAPAS];
        PintarLayout(ts, bloques, l.ancho, l.alto, formato.mascaraId, capas);
        PintarLayout(ts, borde, 2, 2, formato.mascaraId, capasBorde);
        bool bien = true;
        for (int c = 0; c < NUM_CAPAS; c++) {
            bien &= GuardarCapa(RutaCapa(l, c, false), capas[c], nullptr);
            bien &= GuardarCapa(RutaCapa(l, c, true), capasBorde[c], nullptr);
        }
        if (!bien) {
            fprintf(stderr, "%s: no se han podido escribir las capas\n", l.nombre.c_str());
            fallos++;
            continue;
        }
        printf("%s: capas en %s/{,borde_}{baja,media,alta}.png\n", l.nombre.c_str(), l.carpeta.c_str());
    }
    return fallos ? 1 : 0;
}

} // namespace

int main(int argc, char **argv)
{
    if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        fputs(kUso, argc < 2 ? stderr : stdout);
        return argc < 2 ? 1 : 0;
    }
    std::string orden = argv[1];
    bool compactar = false, forzar = false;
    std::vector<std::string> tilesets;
    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "--compactar"))
            compactar = true;
        else if (!strcmp(argv[i], "--forzar"))
            forzar = true;
        else if (argv[i][0] == '-') {
            fprintf(stderr, "opcion desconocida: %s\n\n%s", argv[i], kUso);
            return 1;
        } else
            tilesets.push_back(Etiqueta(argv[i]));
    }

    std::string error;
    Formato formato;
    std::vector<InfoLayout> layouts;
    if (!LeerFormato(formato, error) || !LeerLayouts(layouts, error)) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }

    int fallos = 0;
    if (orden == "compilar" || orden == "cuentas") {
        bool nombrados = !tilesets.empty();
        if (!nombrados) {
            std::set<std::string> vistos;
            for (const InfoLayout &l : layouts)
                if (TieneArte(l) && vistos.insert(l.tileset).second)
                    tilesets.push_back(l.tileset);
        }
        for (const std::string &t : tilesets)
            fallos += Compilar(formato, layouts, t, orden == "compilar", compactar, nombrados) != 0;
    } else if (orden == "descompilar") {
        if (tilesets.empty()) {
            fprintf(stderr, "descompilar: di que tileset\n");
            return 1;
        }
        for (const std::string &t : tilesets)
            fallos += Descompilar(formato, layouts, t, forzar) != 0;
    } else {
        fprintf(stderr, "orden desconocida: %s\n\n%s", orden.c_str(), kUso);
        return 1;
    }
    return fallos ? 1 : 0;
}

#ifndef GUARD_FONDO_AFIN_H
#define GUARD_FONDO_AFIN_H

// Convierte el terreno que rodea al jugador en un fondo afin de 8bpp, para
// usarlo como suelo con perspectiva tipo modo 7.
//
// La captura tiene que hacerse DESDE el mapa, con su vram y sus paletas vivas:
// lee los tiles directamente de la vram de fondos y las paletas de la de
// paletas, que es donde el mapa ya los tiene descomprimidos.

#define AFIN_METATILES_LADO  32                        // 32x32 metatiles alrededor del jugador
#define AFIN_MAPA_LADO       (AFIN_METATILES_LADO * 2) // 64x64 casillas
#define AFIN_MAX_TILES       256                       // el mapa afin indexa con un byte

struct FondoAfin
{
    ALIGNED(4) u8 tiles[AFIN_MAX_TILES * 64];        // 16 KB de tiles de 8bpp
    ALIGNED(4) u8 mapa[AFIN_MAPA_LADO * AFIN_MAPA_LADO];
    ALIGNED(4) u16 paleta[256];
    u16 origen[AFIN_MAX_TILES];           // entrada del mapa que genero cada tile
    u16 numTiles;
    u16 desbordado;                       // no cupieron todos los tiles distintos
};

bool32 CapturaFondoAfin(void);
void LiberaFondoAfin(void);
struct FondoAfin *FondoAfinCapturado(void);

void EntraEnDemoFondoAfin(void);

#endif // GUARD_FONDO_AFIN_H

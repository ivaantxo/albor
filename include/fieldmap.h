#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

// Un solo tileset por layout: los tiles, los metatiles y las paletas del mapa salen
// todos de el.
//
// El fork de porymap de albor lo sabe por NUM_TILESETS_PER_LAYOUT y entonces no carga
// ningun secundario: el "primario" de porymap es el tileset, con todo. Los nombres
// NUM_*_IN_PRIMARY son los que lee porymap.
#define NUM_TILESETS_PER_LAYOUT 1
#define NUM_TILES_IN_PRIMARY 1008 // Hasta las puertas: ver NUM_TILES_TOTAL
#define NUM_METATILES_IN_PRIMARY 0x7FFF // Todos los IDs del bloque menos MAPGRID_UNDEFINED
#define NUM_PALS_IN_PRIMARY 15 // La 15 es la de la interfaz, texto y bandas (menu.c)

// Paletas por mapa: el tileset guarda las de todos sus mapas, hasta MAX_PALS_IN_TILESET
// (la de cada entrada de metatile es un byte), y cada mapa carga solo las que usan sus
// metatiles, como mucho NUM_PALS_IN_PRIMARY a la vez. Ver LoadMapTilesetPalettes.
#define MAX_PALS_IN_TILESET 256

// Tiles de fondo en la VRAM. Los 16 ultimos, 1008-1023, son de las puertas, que
// field_door.c pone al final.
#define NUM_TILES_TOTAL 1024

#define NUM_TILES_IN_TILESET     NUM_TILES_IN_PRIMARY
#define NUM_METATILES_IN_TILESET NUM_METATILES_IN_PRIMARY
#define NUM_PALS_IN_TILESET      NUM_PALS_IN_PRIMARY

#define MAX_MAP_DATA_SIZE 10240

#define MAX_ELEVATION_LEVEL 7

#define NUM_TILES_PER_METATILE 12

// Map coordinates are offset by 7 when using the map
// buffer because it needs to load sufficient border
// metatiles to fill the player's view (the player has
// 7 metatiles of view horizontally in either direction).
#define MAP_OFFSET 7
#define MAP_OFFSET_W (MAP_OFFSET * 2 + 1)
#define MAP_OFFSET_H (MAP_OFFSET * 2)

#include "main.h"

extern struct BackupMapLayout gBackupMapLayout;
extern u16 ALIGNED(4) sBackupMapData[MAX_MAP_DATA_SIZE];

u32 MapGridGetMetatileIdAt(int, int);
u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void MapGridSetMetatileEntryAt(int, int, u16);
void GetCameraCoords(u16 *, u16 *);
u8 MapGridGetCollisionAt(int, int);
int GetMapBorderIdAt(int x, int y);
bool32 CanCameraMoveInDirection(int direction);
u16 GetMetatileAttributesById(u16 metatileId);
void GetCameraFocusCoords(u16 *x, u16 *y);
u8 MapGridGetMetatileLayerTypeAt(int x, int y);
u8 MapGridGetElevationAt(int x, int y);
u8 GetMetatileElevationById(u16 metatile);
bool32 CameraMove(int deltaX, int deltaY);
void SaveMapView(void);
void SetCameraFocusCoords(u16 x, u16 y);
void InitMap(void);
void InitMapFromSavedGame(void);
void CopyMapTilesetToVram(struct MapLayout const *mapLayout);
void CopyMapTilesetToVramUsingHeap(struct MapLayout const *mapLayout);
void LoadMapTilesetPalettes(struct MapLayout const *mapLayout, bool8 skipFaded);
// Las 12 entradas del metatile como se dibujan en el mapa actual: con el hueco donde
// esta cargada cada paleta del tileset.
void GetMetatileTilesForMap(u32 metatileId, u16 *dst);
// El hueco de paleta de fondo donde esta esa paleta del tileset; la carga si no esta.
u32 GetMapPaletteSlot(u32 palette);
// La paleta del tileset que hay en ese hueco, o -1.
s32 GetMapPaletteInSlot(u32 slot);
const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection);
const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y);
void MapGridSetMetatileImpassabilityAt(int x, int y, bool32 impassable);

// field_region_map.c
void FieldInitRegionMap(MainCallback callback);

#endif //GUARD_FIELDMAP_H

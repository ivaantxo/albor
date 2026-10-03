#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

// Un solo tileset por layout: los tiles, los metatiles y las paletas del mapa salen
// todos de el.
//
// Porymap todavia piensa en primario + secundario. Lee estos cinco nombres y exige que
// el primario quede por debajo del total en tiles y en paletas. Aqui el "primario" es
// el tileset, y lo que queda hasta el total es la parte reservada, que porymap ensena
// como el secundario gTileset_Reservado y que el juego no carga:
//   - Tiles 1008-1023: los de las puertas, que field_door.c pone al final de la VRAM.
//   - Paleta 15: la de la interfaz, texto y bandas (menu.c). El mapa tiene las 0-14.
#define NUM_TILES_IN_PRIMARY 1008
#define NUM_TILES_TOTAL 1024
#define NUM_METATILES_IN_PRIMARY 0x7FFF // Todos los IDs del bloque menos MAPGRID_UNDEFINED
#define NUM_PALS_IN_PRIMARY 15
#define NUM_PALS_TOTAL 16

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
const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection);
const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y);
void MapGridSetMetatileImpassabilityAt(int x, int y, bool32 impassable);

// field_region_map.c
void FieldInitRegionMap(MainCallback callback);

#endif //GUARD_FIELDMAP_H

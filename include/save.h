#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer.
// Only 12 bytes of the footer are used.
#define SECTOR_DATA_SIZE 4084
#define SECTOR_FOOTER_SIZE 12
#define SECTOR_SIZE (SECTOR_DATA_SIZE + SECTOR_FOOTER_SIZE)

// If the sector's signature field is not this value then the sector is either invalid or empty.
// Subir esta firma cada vez que cambie la disposicion de struct SaveBlock
// (por ejemplo al anadir o quitar campos de BoxPokemon). Si no se sube, un
// guardado antiguo se lee con los offsets desplazados y produce datos basura.
#define SECTOR_SIGNATURE 0x8012026

#define SECTOR_ID_SAVEBLOCK_START       0
#define SECTOR_ID_SAVEBLOCK_END         2
#define SECTOR_ID_PKMN_STORAGE_START    3
#define SECTOR_ID_PKMN_STORAGE_END      15

#define SECTORS_COUNT                   16

#define SAVE_STATUS_EMPTY    0
#define SAVE_STATUS_OK       1
#define SAVE_STATUS_CORRUPT  2
#define SAVE_STATUS_NO_FLASH 4
#define SAVE_STATUS_ERROR    0xFF

// Special sector id value for certain save functions to
// indicate that no specific sector should be used.
#define FULL_SAVE_SLOT 0xFFFF

// SetDamagedSectorBits states
enum
{
    ENABLE,
    DISABLE
};

// A save sector location holds a pointer to the data for a particular sector
// and the size of that data. Size cannot be greater than SECTOR_DATA_SIZE.
struct SaveSectorLocation
{
    void *data;
    u16 size;
};

struct SaveSector
{
    u8 data[SECTOR_DATA_SIZE];
    u8 unused[SECTOR_FOOTER_SIZE - 12]; // Unused portion of the footer
    u16 id;
    u16 checksum;
    u32 signature;
    u32 counter;
}; // size is SECTOR_SIZE (0x1000)

extern u16 gLastWrittenSector;
extern u32 gLastSaveCounter;
extern u16 gLastKnownGoodSector;
extern u32 gDamagedSaveSectors;
extern u32 gSaveCounter;
extern u16 gSaveFileStatus;
extern void (*gGameContinueCallback)(void);
extern struct SaveSectorLocation gRamSaveSectorLocations[];

extern struct SaveSector gSaveDataBuffer;

void ClearSaveData(void);
void Save_ResetSaveCounters(void);
void HandleSavingData(void);
u8 TrySavingData(void);
u8 LoadGameSave(void);

// save_failed_screen.c
void DoSaveFailedScreen(void);

#endif // GUARD_SAVE_H

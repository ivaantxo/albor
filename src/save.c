#include "global.h"
#include "agb_flash.h"
#include "gba/flash_internal.h"
#include "fieldmap.h"
#include "save.h"
#include "task.h"
#include "decompress.h"
#include "load_save.h"
#include "overworld.h"
#include "pokemon_storage_system.h"
#include "main.h"
#include "link.h"
#include "constants/game_stat.h"

static u16 CalculateChecksum(void *, u16);
static bool8 ReadFlashSector(u8, struct SaveSector *);
static u8 GetSaveValidStatus(const struct SaveSectorLocation *);
static u8 CopySaveSlotData(u16, struct SaveSectorLocation *);
static u8 TryWriteSector(u8, u8 *);
static u8 HandleWriteSector(u16, const struct SaveSectorLocation *);

#define SAVEBLOCK_CHUNK(structure, chunkNum)                                   \
{                                                                              \
    chunkNum * SECTOR_DATA_SIZE,                                               \
    sizeof(structure) >= chunkNum * SECTOR_DATA_SIZE ?                         \
    min(sizeof(structure) - chunkNum * SECTOR_DATA_SIZE, SECTOR_DATA_SIZE) : 0 \
}

struct
{
    u16 offset;
    u16 size;
} static const sSaveSlotLayout[SECTORS_COUNT] =
{
    SAVEBLOCK_CHUNK(struct SaveBlock, 0), // SECTOR_ID_SAVEBLOCK_START
    SAVEBLOCK_CHUNK(struct SaveBlock, 1),
    SAVEBLOCK_CHUNK(struct SaveBlock, 2), // SECTOR_ID_SAVEBLOCK_END

    SAVEBLOCK_CHUNK(struct PokemonStorage, 0), // SECTOR_ID_PKMN_STORAGE_START
    SAVEBLOCK_CHUNK(struct PokemonStorage, 1),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 2),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 3),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 4),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 5),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 6),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 7),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 8),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 9),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 10),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 11),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 12), // SECTOR_ID_PKMN_STORAGE_END
};

// These will produce an error if a save struct is larger than the space
// alloted for it in the flash.
STATIC_ASSERT(sizeof(struct SaveBlock) <= SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK_END - SECTOR_ID_SAVEBLOCK_START + 1), SaveBlockFreeSpace);
STATIC_ASSERT(sizeof(struct PokemonStorage) <= SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1), PokemonStorageFreeSpace);

COMMON_DATA u16 gLastWrittenSector = 0;
COMMON_DATA u32 gLastSaveCounter = 0;
COMMON_DATA u16 gLastKnownGoodSector = 0;
COMMON_DATA u32 gDamagedSaveSectors = 0;
COMMON_DATA u32 gSaveCounter = 0;
COMMON_DATA struct SaveSector *gReadWriteSector = NULL; // Pointer to a buffer for reading/writing a sector
COMMON_DATA u16 gSaveFileStatus = 0;
COMMON_DATA void (*gGameContinueCallback)(void) = NULL;
COMMON_DATA struct SaveSectorLocation gRamSaveSectorLocations[SECTORS_COUNT] = {0};
COMMON_DATA u16 gSaveAttemptStatus = 0;
EWRAM_DATA struct SaveSector gSaveDataBuffer = {0}; // Buffer used for reading/writing sectors

void ClearSaveData(void)
{
    u32 i;

    for (i = 0; i < SECTORS_COUNT; i++)
    {
        EraseFlashSector(i);
        EraseFlashSector(i + SECTORS_COUNT);
    }
}

void Save_ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gLastWrittenSector = 0;
    gDamagedSaveSectors = 0;
}

static bool32 SetDamagedSectorBits(u8 op, u8 sectorId)
{
    bool32 retVal = FALSE;

    switch (op)
    {
    case ENABLE:
        gDamagedSaveSectors |= (1 << sectorId);
        break;
    case DISABLE:
        gDamagedSaveSectors &= ~(1 << sectorId);
        break;
    }

    return retVal;
}

static void VBlankCB_Saving(void)
{
    AnimateSprites();
    BuildOamBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static u8 WriteSaveSectorOrSlot(u16 sectorId, const struct SaveSectorLocation *locations)
{
    IntrCallback prevVblankCB;
    u32 status;
    u32 i;

    gReadWriteSector = &gSaveDataBuffer;

    if (sectorId != FULL_SAVE_SLOT)
    {
        // A sector was specified, just write that sector.
        // This is never reached, FULL_SAVE_SLOT is always used instead.
        status = HandleWriteSector(sectorId, locations);
    }
    else
    {
        // No sector was specified, write full save slot.
        gLastKnownGoodSector = gLastWrittenSector; // backup the current written sector before attempting to write.
        gLastSaveCounter = gSaveCounter;
        gLastWrittenSector++;
        gLastWrittenSector = gLastWrittenSector % SECTORS_COUNT;
        gSaveCounter++;
        status = SAVE_STATUS_OK;

        prevVblankCB = gMain.vblankCallback;
        SetVBlankCallback(VBlankCB_Saving);
        for (i = 0; i < SECTORS_COUNT; i++)
            HandleWriteSector(i, locations);
        SetVBlankCallback(prevVblankCB);

        if (gDamagedSaveSectors)
        {
            // At least one sector save failed
            status = SAVE_STATUS_ERROR;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }

    return status;
}

static u8 HandleWriteSector(u16 sectorId, const struct SaveSectorLocation *locations)
{
    u32 i;
    u16 sector;
    u8 *data;
    u16 size;

    // Adjust sector id for current save slot
    sector = sectorId + gLastWrittenSector;
    sector %= SECTORS_COUNT; 

    // Get current save data
    data = locations[sectorId].data;
    size = locations[sectorId].size;

    // Clear temp save sector
    for (i = 0; i < SECTOR_SIZE; i++)
        ((u8 *)gReadWriteSector)[i] = 0;

    // Set footer data
    gReadWriteSector->id = sectorId;
    gReadWriteSector->signature = SECTOR_SIGNATURE;
    gReadWriteSector->counter = gSaveCounter;

    // Copy current data to temp buffer for writing
    for (i = 0; i < size; i++)
        gReadWriteSector->data[i] = data[i];

    gReadWriteSector->checksum = CalculateChecksum(data, size);

    return TryWriteSector(sector, gReadWriteSector->data);
}

static u8 TryWriteSector(u8 sector, u8 *data)
{
    if (ProgramFlashSectorAndVerify(sector, data)) // is damaged?
    {
        // Failed
        SetDamagedSectorBits(ENABLE, sector);
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Succeeded
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 TryLoadSaveSlot(u16 sectorId, struct SaveSectorLocation *locations)
{
    u8 status;
    gReadWriteSector = &gSaveDataBuffer;
    if (sectorId != FULL_SAVE_SLOT)
    {
        // This function may not be used with a specific sector id
        status = SAVE_STATUS_ERROR;
    }
    else
    {
        status = GetSaveValidStatus(locations);
        CopySaveSlotData(FULL_SAVE_SLOT, locations);
    }

    return status;
}

// sectorId arg is ignored, this always reads the full save slot
static u8 CopySaveSlotData(u16 sectorId, struct SaveSectorLocation *locations)
{
    u32 i;
    u16 checksum;
    u16 id;

    for (i = 0; i < SECTORS_COUNT; i++)
    {
        ReadFlashSector(i, gReadWriteSector);

        id = gReadWriteSector->id;
        if (id == 0)
            gLastWrittenSector = i;

        checksum = CalculateChecksum(gReadWriteSector->data, locations[id].size);

        // Only copy data for sectors whose signature and checksum fields are correct
        if (gReadWriteSector->signature == SECTOR_SIGNATURE && gReadWriteSector->checksum == checksum)
        {
            u32 j;
            for (j = 0; j < locations[id].size; j++)
                ((u8 *)locations[id].data)[j] = gReadWriteSector->data[j];
        }
    }

    return SAVE_STATUS_OK;
}

static u8 GetSaveValidStatus(const struct SaveSectorLocation *locations)
{
    u32 i;
    u16 checksum;
    u32 validSectorFlags = 0;
    bool8 signatureValid = FALSE;

    for (i = 0; i < SECTORS_COUNT; i++)
    {
        ReadFlashSector(i, gReadWriteSector);
        if (gReadWriteSector->signature == SECTOR_SIGNATURE)
        {
            signatureValid = TRUE;
            checksum = CalculateChecksum(gReadWriteSector->data, locations[gReadWriteSector->id].size);
            if (gReadWriteSector->checksum == checksum)
            {
                validSectorFlags |= 1 << gReadWriteSector->id;
            }
        }
    }

    if (signatureValid)
    {
        return SAVE_STATUS_OK;
    }
    else
    {
        // No sectors have the correct signature, treat it as empty
        return SAVE_STATUS_EMPTY;
    }
}

// Return value always ignored
static bool8 ReadFlashSector(u8 sectorId, struct SaveSector *sector)
{
    ReadFlash(sectorId, 0, sector->data, SECTOR_SIZE);
    return TRUE;
}

static u16 CalculateChecksum(void *data, u16 size)
{
    u32 i;
    u32 checksum = 0;

    for (i = 0; i < (size / 4); i++)
    {
        checksum += *((u32 *)data);
        data += sizeof(u32);
    }

    return ((checksum >> 16) + checksum);
}

static void UpdateSaveAddresses(void)
{
    u32 i;

    for (i = SECTOR_ID_SAVEBLOCK_START; i <= SECTOR_ID_SAVEBLOCK_END; i++)
    {
        gRamSaveSectorLocations[i].data = (void *)(gSaveBlockPtr) + sSaveSlotLayout[i].offset;
        gRamSaveSectorLocations[i].size = sSaveSlotLayout[i].size;
    }

    for (i = SECTOR_ID_PKMN_STORAGE_START; i <= SECTOR_ID_PKMN_STORAGE_END; i++)
    {
        gRamSaveSectorLocations[i].data = (void *)(gPokemonStoragePtr) + sSaveSlotLayout[i].offset;
        gRamSaveSectorLocations[i].size = sSaveSlotLayout[i].size;
    }
}

void HandleSavingData(void)
{
    UpdateSaveAddresses();
    CopyPartyAndObjectsToSave();
    WriteSaveSectorOrSlot(FULL_SAVE_SLOT, gRamSaveSectorLocations);
}

u8 TrySavingData(void)
{
    if (gFlashMemoryPresent != TRUE)
    {
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }

    HandleSavingData();
    if (!gDamagedSaveSectors)
    {
        gSaveAttemptStatus = SAVE_STATUS_OK;
        return SAVE_STATUS_OK;
    }
    else
    {
        DoSaveFailedScreen();
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }
}

u8 LoadGameSave(void)
{
    u8 status;

    if (gFlashMemoryPresent != TRUE)
    {
        gSaveFileStatus = SAVE_STATUS_NO_FLASH;
        return SAVE_STATUS_ERROR;
    }

    UpdateSaveAddresses();
    status = TryLoadSaveSlot(FULL_SAVE_SLOT, gRamSaveSectorLocations);
    CopyPartyAndObjectsFromSave();
    gSaveFileStatus = status;
    gGameContinueCallback = 0;

    return status;
}

#define tState         data[0]
#define tTimer         data[1]

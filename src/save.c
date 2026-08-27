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
#include "constants/game_stat.h"

// Firma que va en el pie de cada sector. Un guardado con otra disposicion se
// leeria con los offsets desplazados y daria basura, asi que tiene que cambiar
// cuando cambie la disposicion.
//
// Ya no hay que acordarse de subirla a mano en el caso normal: el tamano de las
// dos estructuras entra en la cuenta, y anadir o quitar campos lo cambia. Lo
// unico que no detecta es reordenar campos sin tocar el tamano total -cambiar
// dos u16 de sitio, por ejemplo-; para eso esta el contador de abajo.
#define FIRMA_DISPOSICION 1

const u32 gFirmaSector = 0x08010000u
                       ^ ((u32)FIRMA_DISPOSICION << 24)
                       ^ ((u32)sizeof(struct SaveBlock) << 8)
                       ^ (u32)sizeof(struct PokemonStorage);

static u16 CalculateChecksum(const void *, u32);
static u32 TryWriteSector(u32, u8 *);
static u32 HandleWriteSector(u32, const struct SaveSectorLocation *);

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
    SAVEBLOCK_CHUNK(struct SaveBlock, 1), // SECTOR_ID_SAVEBLOCK_END

    SAVEBLOCK_CHUNK(struct PokemonStorage, 0), // SECTOR_ID_PKMN_STORAGE_START
    SAVEBLOCK_CHUNK(struct PokemonStorage, 1),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 2),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 3),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 4),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 5),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 6),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 7),
    SAVEBLOCK_CHUNK(struct PokemonStorage, 8), // SECTOR_ID_PKMN_STORAGE_END
};

// Saltan si una estructura de guardado no cabe en los sectores que tiene
// asignados. Al ajustar el reparto al minimo, anadir campos puede pasarse:
// el menu de depuracion (Utilities) muestra cuanto queda libre.
STATIC_ASSERT(sizeof(struct SaveBlock) <= SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK_END - SECTOR_ID_SAVEBLOCK_START + 1), SaveBlockFreeSpace);
STATIC_ASSERT(sizeof(struct PokemonStorage) <= SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1), PokemonStorageFreeSpace);

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
        EraseFlashSector(i);
}

void Save_ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gDamagedSaveSectors = 0;
}

static bool32 SetDamagedSectorBits(u32 op, u32 sectorId)
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

// Escribe la ranura de guardado completa, sector a sector.
static u32 WriteSaveSlot(const struct SaveSectorLocation *locations)
{
    IntrCallback prevVblankCB;
    u32 status;
    u32 i;

    gReadWriteSector = &gSaveDataBuffer;
    gSaveCounter++;
    status = SAVE_STATUS_OK;

    prevVblankCB = gMain.vblankCallback;
    SetVBlankCallback(VBlankCB_Saving);

    for (i = 0; i < SECTORS_COUNT; i++)
        HandleWriteSector(i, locations);

    SetVBlankCallback(prevVblankCB);

    // Al menos un sector no se pudo escribir
    if (gDamagedSaveSectors)
        status = SAVE_STATUS_ERROR;

    return status;
}

// Comprueba si el sector de la flash ya contiene exactamente estos datos.
// Leerlo entero cuesta unos 2 ms; escribirlo cuesta unos 100 ms, porque hay
// que borrar el sector y programarlo byte a byte esperando a cada uno. Por eso
// compensa comparar siempre antes de escribir: el almacen de Pokemon ocupa 9 de
// los 11 sectores y solo cambia cuando se usa el PC, asi que un guardado normal
// se ahorra casi todo el trabajo.
static bool32 SectorSinCambios(u32 sectorId, const u8 *data, u32 size)
{
    u32 i;

    ReadFlash(sectorId, 0, (u8 *)gReadWriteSector, SECTOR_SIZE);

    // Sector vacio, de una version anterior del guardado, o descolocado.
    if (gReadWriteSector->signature != gFirmaSector || gReadWriteSector->id != sectorId)
        return FALSE;

    // Solo se comparan los bytes utiles: el resto del sector es relleno a cero
    // que HandleWriteSector deja igual en cada escritura.
    for (i = 0; i < size; i++)
    {
        if (gReadWriteSector->data[i] != data[i])
            return FALSE;
    }

    return TRUE;
}

static u32 HandleWriteSector(u32 sectorId, const struct SaveSectorLocation *locations)
{
    u32 i;
    const u8 *data = locations[sectorId].data;
    u32 size = locations[sectorId].size;

    if (SectorSinCambios(sectorId, data, size))
    {
        // Nada que escribir, y el contenido esta verificado: el sector esta sano.
        SetDamagedSectorBits(DISABLE, sectorId);
        return SAVE_STATUS_OK;
    }

    // Limpiar el sector temporal
    for (i = 0; i < SECTOR_SIZE; i++)
        ((u8 *)gReadWriteSector)[i] = 0;

    // Rellenar el pie
    gReadWriteSector->id = sectorId;
    gReadWriteSector->signature = gFirmaSector;
    gReadWriteSector->counter = gSaveCounter;

    // Copiar los datos actuales al buffer que se va a escribir
    for (i = 0; i < size; i++)
        gReadWriteSector->data[i] = data[i];

    gReadWriteSector->checksum = CalculateChecksum(data, size);

    return TryWriteSector(sectorId, gReadWriteSector->data);
}

static u32 TryWriteSector(u32 sector, u8 *data)
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

// Lee la ranura completa en una sola pasada: valida y copia a la vez.
static u32 LoadSaveSlot(struct SaveSectorLocation *locations)
{
    u32 i;
    u32 cargados = 0;

    gReadWriteSector = &gSaveDataBuffer;

    for (i = 0; i < SECTORS_COUNT; i++)
    {
        u32 size;
        u32 j;

        ReadFlash(i, 0, (u8 *)gReadWriteSector, SECTOR_SIZE);

        // La id se comprueba contra la posicion antes de usarla como indice:
        // un sector vacio trae 0xFFFF ahi y indexaria locations[] fuera de rango.
        if (gReadWriteSector->signature != gFirmaSector || gReadWriteSector->id != i)
            continue;

        size = locations[i].size;
        if (gReadWriteSector->checksum != CalculateChecksum(gReadWriteSector->data, size))
            continue;

        for (j = 0; j < size; j++)
            ((u8 *)locations[i].data)[j] = gReadWriteSector->data[j];

        cargados |= 1 << i;
    }

    // Ningun sector valido: la partida esta vacia, no rota.
    if (cargados == 0)
        return SAVE_STATUS_EMPTY;

    // Faltan sectores: se puede continuar, pero avisando.
    if (cargados != (1 << SECTORS_COUNT) - 1)
        return SAVE_STATUS_ERROR;

    return SAVE_STATUS_OK;
}


// Suma de 32 bits doblada a 16. Los tamanos de los trozos son multiplos de 4,
// asi que no queda cola sin sumar.
static u16 CalculateChecksum(const void *data, u32 size)
{
    const u32 *palabras = data;
    u32 checksum = 0;
    u32 i;

    for (i = 0; i < size / 4; i++)
        checksum += palabras[i];

    return (checksum >> 16) + checksum;
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
    WriteSaveSlot(gRamSaveSectorLocations);
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
    u32 status;

    if (gFlashMemoryPresent != TRUE)
    {
        gSaveFileStatus = SAVE_STATUS_NO_FLASH;
        return SAVE_STATUS_ERROR;
    }

    UpdateSaveAddresses();
    status = LoadSaveSlot(gRamSaveSectorLocations);
    CopyPartyAndObjectsFromSave();
    gSaveFileStatus = status;
    gGameContinueCallback = 0;

    return status;
}

#define tState         data[0]
#define tTimer         data[1]

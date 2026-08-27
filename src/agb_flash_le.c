#include "gba/gba.h"
#include "gba/flash_internal.h"

const u16 leMaxTime[] =
{
      10, 65469, TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_256CLK,
      10, 65469, TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_256CLK,
    2000, 65469, TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_256CLK,
    2000, 65469, TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_256CLK,
};

const struct FlashSetupInfo LE26FV10N1TS =
{
    .programFlashByte = ProgramFlashByte_MX,
    .programFlashSector = ProgramFlashSector_MX,
    .eraseFlashSector = EraseFlashSector_MX,
    .WaitForFlashWrite = WaitForFlashWrite_Common,
    .maxTime = leMaxTime,
    .type =
    {
        131072, // ROM size
        {
            4096, // sector size
              12, // bit shift to multiply by sector size (4096 == 1 << 12)
              32, // number of sectors
               0  // appears to be unused
        },
        { 3, 1 }, // wait state setup data
        { { 0x62, 0x13 } } // ID
    }
};

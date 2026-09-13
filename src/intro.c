#include "global.h"
#include "main.h"
#include "palette.h"
#include "distorsion_fondo.h"
#include "task.h"
#include "title_screen.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "decompress.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "expansion_intro.h"
#include "constants/rgb.h"

/*
    Lo que queda de la intro: la pantalla de copyright y nada mas.

    Aqui vivian tres escenas de pelicula -el logo con las gotas de agua, el paseo en
    bici y la pelea de Groudon, Kyogre y Rayquaza-, tres mil lineas y sus graficos.
    Se han ido enteras: este juego arranca con el copyright, pasa a la intro de
    Porygon y el huevo, y de ahi al titulo.

    Se queda tambien PanFadeAndZoomScreen, que no era de las escenas aunque estuviera
    aqui: la usa la pantalla de titulo para mover su fondo afin.
*/

enum {
    COPYRIGHT_INITIALIZE,
    COPYRIGHT_EMULATOR_BLEND,
    COPYRIGHT_START_FADE = 140,
    COPYRIGHT_START_INTRO,
};

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    IniciaTransferenciaDMAEnHblankDistorsionFondo();
}

static void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteOffset)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteOffset, PLTT_SIZE_4BPP);
}

static u8 SetUpCopyrightScreen(void)
{
    switch (gMain.state)
    {
    case COPYRIGHT_INITIALIZE:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, BG_PLTT_ID(0));
        ParaDistorsionFondo();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
    // REG_DISPCNT needs to be overwritten the second time, because otherwise the intro won't show up on VBA 1.7.2 and John GBA Lite emulators.
    // The REG_DISPCNT overwrite is NOT needed in m-GBA, No$GBA, VBA 1.8.0, My Boy and Pizza Boy GBA emulators.
    case COPYRIGHT_EMULATOR_BLEND:
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
    default:
        UpdatePaletteFade();
        gMain.state++;
        break;
    case COPYRIGHT_START_FADE:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); //ojo
        gMain.state++;
        break;
    case COPYRIGHT_START_INTRO:
        if (UpdatePaletteFade())
            break;
        SetMainCallback2(CB2_ExpansionIntro);
        CreateTask(Task_HandleExpansionIntro, 0);
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers();
        ResetMenuAndMonGlobals();
        Save_ResetSaveCounters();
        LoadGameSave();
        if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            SetDefaultOptions();
        SetPokemonCryStereo(gSaveBlockPtr->optionsSound);
        InitHeap();
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

// La usa la pantalla de titulo, no las escenas que se han ido.
void PanFadeAndZoomScreen(u16 screenX, u16 screenY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = screenX;
    src.scrY = screenY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}

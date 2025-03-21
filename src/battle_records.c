#include "global.h"
#include "battle_records.h"
#include "bg.h"
#include "window.h"
#include "link.h"
#include "battle.h"
#include "overworld.h"
#include "text.h"
#include "text_window.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "main.h"
#include "scanline_effect.h"
#include "international_string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "constants/game_stat.h"
#include "trainer_hill.h"
#include "constants/rgb.h"

static void Task_CloseTrainerHillRecordsOnButton(u8 taskId);
static void Task_BeginPaletteFade(u8 taskId);
static void Task_ExitTrainerHillRecords(u8 taskId);
static void RemoveTrainerHillRecordsWindow(u8 windowId);
static void CB2_ShowTrainerHillRecords(void);

EWRAM_DATA u8 gRecordsWindowId = 0;
EWRAM_DATA static u8 *sTilemapBuffer = NULL;

static const u32 sTrainerHillWindowTileset[] = INCBIN_U32("graphics/trainer_hill/records_window.4bpp");
static const u16 sTrainerHillWindowPalette[] = INCBIN_U16("graphics/trainer_hill/records_window.gbapal");
static const u32 sTrainerHillWindowTilemap[] = INCBIN_U32("graphics/trainer_hill/records_window.bin");

static const struct BgTemplate sTrainerHillRecordsBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sTrainerHillRecordsWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 20
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sLinkBattleRecordsWindow =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 26,
    .height = 17,
    .paletteNum = 15,
    .baseBlock = 1
};

static const u8 sText_DashesNoPlayer[] = _("-------");
static const u8 sText_DashesNoScore[] = _("----");

void ClearPlayerLinkBattleRecords(void)
{

}

void UpdatePlayerLinkBattleRecords(s32 battlerId)
{

}

void ShowLinkBattleRecords(void)
{

}

void RemoveRecordsWindow(void)
{
    ClearStdWindowAndFrame(gRecordsWindowId, FALSE);
    RemoveWindow(gRecordsWindowId);
}

static void Task_TrainerHillWaitForPaletteFade(u8 taskId)
{
    if (!gFundidoPaletas.activo)
        gTasks[taskId].func = Task_CloseTrainerHillRecordsOnButton;
}

static void Task_CloseTrainerHillRecordsOnButton(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        task->func = Task_BeginPaletteFade;
    }
}

static void Task_BeginPaletteFade(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_ExitTrainerHillRecords;
}

static void Task_ExitTrainerHillRecords(u8 taskId)
{
    if (!gFundidoPaletas.activo)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        Free(sTilemapBuffer);
        RemoveTrainerHillRecordsWindow(0);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

static void RemoveTrainerHillRecordsWindow(u8 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
    RemoveWindow(windowId);
}

static void ClearVramOamPlttRegs(void)
{
    DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void ClearTasksAndGraphicalStructs(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void ResetBgCoordinates(void)
{
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
}

static void SetDispcntReg(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_1D_MAP);
}

static void LoadTrainerHillRecordsWindowGfx(u8 bgId)
{
    LoadBgTiles(bgId, sTrainerHillWindowTileset, sizeof(sTrainerHillWindowTileset), 0);
    CopyToBgTilemapBufferRect(bgId, sTrainerHillWindowTilemap, 0, 0, 0x20, 0x20);
    LoadPalette(sTrainerHillWindowPalette, BG_PLTT_ID(0), sizeof(sTrainerHillWindowPalette));
}

static void VblankCB_TrainerHillRecords(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_TrainerHillRecords(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void ShowTrainerHillRecords(void)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_ShowTrainerHillRecords);
}

static void CB2_ShowTrainerHillRecords(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPlttRegs();
        gMain.state++;
        break;
    case 1:
        ClearTasksAndGraphicalStructs();
        gMain.state++;
        break;
    case 2:
        sTilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        ResetBgsAndClearDma3BusyFlags();
        InitBgsFromTemplates(0, sTrainerHillRecordsBgTemplates, ARRAY_COUNT(sTrainerHillRecordsBgTemplates));
        SetBgTilemapBuffer(3, sTilemapBuffer);
        ResetBgCoordinates();
        gMain.state++;
        break;
    case 3:
        LoadTrainerHillRecordsWindowGfx(3);
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy() != TRUE)
        {
            ShowBg(0);
            ShowBg(3);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
        }
        break;
    case 5:
        InitWindows(sTrainerHillRecordsWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetDispcntReg();
        SetVBlankCallback(VblankCB_TrainerHillRecords);
        PrintOnTrainerHillRecordsWindow();
        CreateTask(Task_TrainerHillWaitForPaletteFade, 8);
        SetMainCallback2(MainCB2_TrainerHillRecords);
        gMain.state = 0;
        break;
    }
}

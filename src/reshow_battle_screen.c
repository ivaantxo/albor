#include "global.h"
#include "reshow_battle_screen.h"
#include "battle.h"
#include "palette.h"
#include "pokemon.h"
#include "main.h"
#include "distorsion_fondo.h"
#include "text.h"
#include "gpu_regs.h"
#include "bg.h"
#include "battle_controllers.h"
#include "sprite.h"
#include "constants/trainers.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "data.h"

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static bool8 LoadBattlerSpriteGfx(u32 battler);
static void CreateHealthboxSprite(u32 battler);
static void ClearBattleBgCntBaseBlocks(void);

void ReshowBattleScreenDummy(void)
{

}

void ReshowBattleScreenAfterMenu(void)
{
    gFundidoPaletas.transferenciaBufferDeshabilitada = TRUE;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    gBattleScripting.reshowMainState = 0;
    gBattleScripting.reshowHelperState = 0;
    SetMainCallback2(CB2_ReshowBattleScreenAfterMenu);
}

static void CB2_ReshowBattleScreenAfterMenu(void)
{
    switch (gBattleScripting.reshowMainState)
    {
    case 0:
        LimpiaDistorsionFondo();
        BattleInitBgsAndWindows();
        SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
        SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        ResetPaletteFade();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        break;
    case 1:
        CpuFastFill(0, (void *)(VRAM), VRAM_SIZE);
        break;
    case 2:
        LoadBattleTextboxAndBackground();
        break;
    case 3:
        ResetSpriteData();
        break;
    case 4:
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
        break;
    case 5:
        ClearSpritesHealthboxAnimData();
        break;
    case 6:
        if (CargaGraficosBarrasSalud(gBattleScripting.reshowHelperState))
        {
            gBattleScripting.reshowHelperState = 0;
        }
        else
        {
            gBattleScripting.reshowHelperState++;
            gBattleScripting.reshowMainState--;
        }
        break;
    case 7:
        if (!LoadBattlerSpriteGfx(0))
            gBattleScripting.reshowMainState--;
        break;
    case 8:
        if (!LoadBattlerSpriteGfx(1))
            gBattleScripting.reshowMainState--;
        break;
    case 9:
        if (!LoadBattlerSpriteGfx(2))
            gBattleScripting.reshowMainState--;
        break;
    case 10:
        if (!LoadBattlerSpriteGfx(3))
            gBattleScripting.reshowMainState--;
        break;
    case 11:
        CreateBattlerSprite(0);
        break;
    case 12:
        CreateBattlerSprite(1);
        break;
    case 13:
        CreateBattlerSprite(2);
        break;
    case 14:
        CreateBattlerSprite(3);
        break;
    case 15:
        CreateHealthboxSprite(0);
        break;
    case 16:
        CreateHealthboxSprite(1);
        break;
    case 17:
        CreateHealthboxSprite(2);
        break;
    case 18:
        CreateHealthboxSprite(3);
        break;
    case 19:
        {
            u8 opponentBattler;
            u16 species;

            LoadAndCreateEnemyShadowSprites();

            opponentBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBattler]], MON_DATA_SPECIES);
            SetBattlerShadowSpriteCallback(opponentBattler, species);

            if (EsContraEntrenador())
            {
                opponentBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBattler]], MON_DATA_SPECIES);
                SetBattlerShadowSpriteCallback(opponentBattler, species);
            }
        }
        break;
    default:
        SetVBlankCallback(VBlankCB_Battle);
        ClearBattleBgCntBaseBlocks();
        EmpiezaFundidoPaletasHardware(BLDCNT_TGT1_ALL | BLDCNT_EFFECT_BLEND, 0, 16, 0, TRUE);
        gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
        SetMainCallback2(BattleMainCB2);
        FillAroundBattleWindows();
        break;
    }

    gBattleScripting.reshowMainState++;
}

static void ClearBattleBgCntBaseBlocks(void)
{
    vBgCnt *regBgcnt1, *regBgcnt2;

    regBgcnt1 = (vBgCnt *)(&REG_BG1CNT);
    regBgcnt1->charBaseBlock = 0;

    regBgcnt2 = (vBgCnt *)(&REG_BG2CNT);
    regBgcnt2->charBaseBlock = 0;
}

static bool8 LoadBattlerSpriteGfx(u32 battler)
{
    if (battler < gBattlersCount)
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
                BattleLoadMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
            else
                BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);
        }
        else if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        else
            BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);

        gBattleScripting.reshowHelperState = 0;
    }
    return TRUE;
}

void CreateBattlerSprite(u32 battler)
{
    if (battler < gBattlersCount)
    {
        u8 posY;

        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            posY = GetSubstituteSpriteDefault_Y(battler);
        else
            posY = GetBattlerSpriteDefault_Y(battler);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;
            if (gBattleScripting.monCaught) // Don't create opponent sprite if it has been caught.
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        }
        else
        {
            if (!IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[battler]]))
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        }

        gSprites[gBattlerSpriteIds[battler]].invisible = gBattleSpritesDataPtr->battlerData[battler].invisible;
    }
}

static void CreateHealthboxSprite(u32 battler)
{
    if (battler < gBattlersCount)
    {
        u8 healthboxSpriteId = CreateBattlerHealthboxSprites(battler);

        gHealthboxSpriteIds[battler] = healthboxSpriteId;
        InitBattlerHealthboxCoords(battler);
        SetHealthboxSpriteVisible(healthboxSpriteId);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
        else
        {
            if (!IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[battler]]))
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
    }
}

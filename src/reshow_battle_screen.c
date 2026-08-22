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
#include "battle_bg.h"
#include "battle_controllers.h"
#include "sprite.h"
#include "constants/trainers.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "data.h"

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static bool8 LoadBattlerSpriteGfx(u32 battler);
static void CreaMarcadorDe(u32 battler);
static void ClearBattleBgCntBaseBlocks(void);

void ReshowBattleScreenAfterMenu(void)
{
    gFundidoPaletas.transferenciaBufferDeshabilitada = TRUE;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetMainCallback2(CB2_ReshowBattleScreenAfterMenu);
}

static void CB2_ReshowBattleScreenAfterMenu(void)
{
    static u32 sEstadoVueltaBatalla = 0;

    switch (sEstadoVueltaBatalla)
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
        sEstadoVueltaBatalla++;
        break;
    case 1:
        CpuFastFill(0, (void *)(VRAM), VRAM_SIZE);
        sEstadoVueltaBatalla++;
        break;
    case 2:
        LoadBattleTextboxAndBackground();
        sEstadoVueltaBatalla++;
        break;
    case 3:
        // Todo esto es barato: no hay razon para gastar un fotograma en cada paso.
        // Repartido de uno en uno, la vuelta al combate tardaba veinte fotogramas y
        // se veia el textbox mucho antes que el resto.
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = NUMERO_COMBATIENTES;
        ClearSpritesHealthboxAnimData();
        CargaBarrasSalud();
        sEstadoVueltaBatalla++;
        break;
    case 4:
        if (!LoadBattlerSpriteGfx(0))
            return;
        sEstadoVueltaBatalla++;
        break;
    case 5:
        if (!LoadBattlerSpriteGfx(1))
            return;
        sEstadoVueltaBatalla++;
        break;
    case 6:
        if (!LoadBattlerSpriteGfx(2))
            return;
        sEstadoVueltaBatalla++;
        break;
    case 7:
        if (!LoadBattlerSpriteGfx(3))
            return;
        sEstadoVueltaBatalla++;
        break;
    case 8:
    {
        u32 opponentBattler, species;

        // Crear sprites y marcadores tampoco cuesta nada; lo caro era la
        // descompresion de los graficos, que sigue teniendo su propio fotograma.
        for (u32 combatiente = 0; combatiente < NUMERO_COMBATIENTES; combatiente++)
        {
            CreateBattlerSprite(combatiente);
            CreaMarcadorDe(combatiente);
        }

        LoadAndCreateEnemyShadowSprites();
        opponentBattler = OPONENTE_IZQUIERDA;
        species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBattler]], MON_DATA_SPECIES);
        SetBattlerShadowSpriteCallback(opponentBattler, species);
        if (EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            opponentBattler = OPONENTE_DERECHA;
            species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[opponentBattler]], MON_DATA_SPECIES);
            SetBattlerShadowSpriteCallback(opponentBattler, species);
        }
        sEstadoVueltaBatalla++;
        break;
    }
    default:
        SetVBlankCallback(VBlankCB_Battle);
        ClearBattleBgCntBaseBlocks();
        // Aqui habia un fundido por hardware que no fundia nada: pedia mezcla
        // (BLDCNT_EFFECT_BLEND) sin declarar ninguna segunda capa, asi que no
        // habia con que mezclar y BLDY ni se mira en ese modo. Lo unico que hacia
        // era dejar BLDCNT sin segundas capas durante unos fotogramas, que es
        // justo lo que ponia negra la sombra al volver de la pantalla de Pokemon.
        // La pantalla ya reaparece sola al reanudarse el volcado de paletas.
        RestauraRegistrosCombate();
        gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
        SetMainCallback2(BattleMainCB2);
        FillAroundBattleWindows();
        sEstadoVueltaBatalla = 0;
        break;
    }
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
        if (GetBattlerSide(battler) != LADO_JUGADOR)
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

        if (GetBattlerSide(battler) != LADO_JUGADOR)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;
            if (gBattleScripting.monCaught) // Don't create opponent sprite if it has been caught.
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), battler);
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

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), battler);
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

static void CreaMarcadorDe(u32 battler)
{
    if (battler < gBattlersCount)
    {
        u8 marcadorSpriteId = CreaMarcadorCombate(battler);

        gMarcadorSpriteIds[battler] = marcadorSpriteId;
        ColocaMarcador(battler);
        MuestraMarcador(marcadorSpriteId);

        if (GetBattlerSide(battler) != LADO_JUGADOR)
            ActualizaMarcador(gMarcadorSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);
        else
            ActualizaMarcador(gMarcadorSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], MARCADOR_TODO);

        if (GetBattlerSide(battler) != LADO_JUGADOR)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                OcultaMarcador(marcadorSpriteId);
        }
        else
        {
            if (!IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[battler]]))
                OcultaMarcador(marcadorSpriteId);
        }
    }
}

#include "global.h"
#include "sombra_pokemon.h"
#include "depuracion_mgba.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_ai_main.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "constants/battle_anim.h"
#include "battle_interface.h"
#include "main.h"
#include "dma3.h"
#include "malloc.h"
#include "graphics.h"
#include "random.h"
#include "util.h"
#include "pokemon.h"
#include "constants/moves.h"
#include "task.h"
#include "sprite.h"
#include "sound.h"
#include "party_menu.h"
#include "m4a.h"
#include "decompress.h"
#include "data.h"
#include "gpu_regs.h"
#include "palette.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/battle_move_effects.h"

// this file's functions
static void SpriteCB_TrainerSlideVertical(struct Sprite *sprite);
static bool8 ShouldAnimBeDoneRegardlessOfSubstitute(u8 animId);
static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId);
static void Task_ClearBitWhenSpecialAnimDone(u8 taskId);
static void ClearSpritesBattlerHealthboxAnimData(void);

// const rom data
//
// Cada combatiente reserva sus tiles en blanco: el relleno de la barra, el
// porcentaje y la tira de nombre y nivel se dibujan en tiempo de ejecucion, no
// salen de ningun grafico. La hoja solo sirve para apartar el sitio en VRAM.
static const u8 sTilesMarcadorEnBlanco[TILES_RESERVADOS_BARRA_VIDA * TILE_4BPP] = {0};

static const struct SpriteSheet sHojasMarcador[NUMERO_COMBATIENTES] =
{
    [JUGADOR_IZQUIERDA]  = {sTilesMarcadorEnBlanco, sizeof(sTilesMarcadorEnBlanco), TAG_MARCADOR_JUGADOR1},
    [OPONENTE_IZQUIERDA] = {sTilesMarcadorEnBlanco, sizeof(sTilesMarcadorEnBlanco), TAG_MARCADOR_OPONENTE1},
    [JUGADOR_DERECHA]    = {sTilesMarcadorEnBlanco, sizeof(sTilesMarcadorEnBlanco), TAG_MARCADOR_JUGADOR2},
    [OPONENTE_DERECHA]   = {sTilesMarcadorEnBlanco, sizeof(sTilesMarcadorEnBlanco), TAG_MARCADOR_OPONENTE2},
};

// El contorno y los iconos de estado son iguales para todos: una hoja de cada uno.
static const struct SpriteSheet sHojaContornoBarra =
{
    (const void *)gBarraSalud_Gfx, TILES_CONTORNO_BARRA * TILE_4BPP, TAG_CONTORNO_BARRA
};

static const struct SpriteSheet sHojaIconosEstado =
{
    gIconosEstado_Gfx, TILES_ICONOS_ESTADO * TILE_4BPP, TAG_ICONOS_ESTADO
};

// Una sola paleta para todo el marcador: contorno, barra, textos e iconos.
// 1 blanco, 2 verde, 3 amarillo, 4 rojo, 5-9 los fondos de los estados.
const struct SpritePalette sSpritePalettes_HealthBoxHealthBar[2] =
{
    {gBarraSalud_Pal, TAG_MARCADOR_PAL},
    {gBarraSalud_Pal, TAG_MARCADOR_PAL},
};


// code
void AllocateBattleSpritesData(void)
{
    gBattleSpritesDataPtr = AllocZeroed(sizeof(struct BattleSpriteData));
    gBattleSpritesDataPtr->battlerData = AllocZeroed(sizeof(struct BattleSpriteInfo) * NUMERO_COMBATIENTES);
    gBattleSpritesDataPtr->healthBoxesData = AllocZeroed(sizeof(struct BattleHealthboxInfo) * NUMERO_COMBATIENTES);
    gBattleSpritesDataPtr->animationData = AllocZeroed(sizeof(struct BattleAnimationInfo));
    gBattleSpritesDataPtr->battleBars = AllocZeroed(sizeof(struct BattleBarInfo) * NUMERO_COMBATIENTES);
}

void FreeBattleSpritesData(void)
{
    if (gBattleSpritesDataPtr == NULL)
        return;

    FREE_AND_SET_NULL(gBattleSpritesDataPtr->battleBars);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->animationData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->healthBoxesData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr->battlerData);
    FREE_AND_SET_NULL(gBattleSpritesDataPtr);
}

#undef maxGroupNum
#undef minGroupNum
#undef selectedGroup
#undef selectedMoves
#undef moveTarget
#undef numMovesPerGroup
#undef numMultipleMoveGroups
#undef randSelectGroup

// Wait for the Pokémon to finish appearing out from the Poké Ball on send out
void SpriteCB_WaitForBattlerBallReleaseAnim(struct Sprite *sprite)
{
    u32 spriteId = sprite->data[1];

    if (!gSprites[spriteId].affineAnimEnded)
        return;
    if (gSprites[spriteId].invisible)
        return;

    if (gSprites[spriteId].animPaused)
    {
        gSprites[spriteId].animPaused = 0;
    }
    else
    {
        if (gSprites[spriteId].animEnded)
            sprite->callback = SpriteCallbackDummy;
    }
}

#define sSpeedX data[0]

void SpriteCB_TrainerSlideIn(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        if (sprite->x2 == 0)
        {
            if (sprite->y2 != 0)
                sprite->callback = SpriteCB_TrainerSlideVertical;
            else
                sprite->callback = SpriteCallbackDummy;
        }
    }
}

// Slide up to 0 if necessary (used by multi battle intro)
static void SpriteCB_TrainerSlideVertical(struct Sprite *sprite)
{
    sprite->y2 -= 2;
    if (sprite->y2 == 0)
        sprite->callback = SpriteCallbackDummy;
}

#undef sSpeedX

void InitAndLaunchChosenStatusAnimation(u32 battler, bool32 isStatus2, u32 status)
{
    gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 1;
    if (!isStatus2)
    {
        if (status == STATUS1_CONGELACION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_FRZ);
        else if (status == STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_PSN);
        else if (status == STATUS1_BURN)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_BRN);
        else if (status & STATUS1_SLEEP)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_SLP);
        else if (status == STATUS1_PARALYSIS)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_PRZ);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
    }
    else
    {
        if (status & STATUS2_INFATUATION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_INFATUATION);
        else if (status & STATUS2_CONFUSION)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CONFUSION);
        else if (status & STATUS2_CURSED)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_CURSED);
        else if (status & STATUS2_NIGHTMARE)
            LaunchStatusAnimation(battler, B_ANIM_STATUS_NIGHTMARE);
        else // no animation
            gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
    }
}

#define tBattlerId data[0]

bool8 TryHandleLaunchBattleTableAnimation(u8 activeBattler, u8 atkBattler, u8 defBattler, u8 tableId, u16 argument)
{
    u8 taskId;

    if (gBattleSpritesDataPtr->battlerData[activeBattler].behindSubstitute
        && !ShouldAnimBeDoneRegardlessOfSubstitute(tableId))
    {
        return TRUE;
    }
    if (gBattleSpritesDataPtr->battlerData[activeBattler].behindSubstitute
        && tableId == B_ANIM_SUBSTITUTE_FADE
        && gSprites[gBattlerSpriteIds[activeBattler]].invisible)
    {
        LoadBattleMonGfxAndAnimate(activeBattler, TRUE, gBattlerSpriteIds[activeBattler]);
        ClearBehindSubstituteBit(activeBattler);
        return TRUE;
    }

    gBattleAnimAttacker = atkBattler;
    gBattleAnimTarget = defBattler;
    gBattleSpritesDataPtr->animationData->animArg = argument;
    LaunchBattleAnimation(ANIM_TYPE_GENERAL, tableId);
    taskId = CreateTask(Task_ClearBitWhenBattleTableAnimDone, 10);
    gTasks[taskId].tBattlerId = activeBattler;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].animFromTableActive = 1;

    return FALSE;
}

static void Task_ClearBitWhenBattleTableAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].animFromTableActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBattlerId

static bool8 ShouldAnimBeDoneRegardlessOfSubstitute(u8 animId)
{
    switch (animId)
    {
    case B_ANIM_SUBSTITUTE_FADE:
    case B_ANIM_RAIN_CONTINUES:
    case B_ANIM_SUN_CONTINUES:
    case B_ANIM_SANDSTORM_CONTINUES:
    case B_ANIM_SNOW_CONTINUES:
    case B_ANIM_FOG_CONTINUES:
        return TRUE;
    default:
        return FALSE;
    }
}

#define tBattlerId data[0]

void InitAndLaunchSpecialAnimation(u8 activeBattler, u8 atkBattler, u8 defBattler, u8 tableId)
{
    u8 taskId;

    gBattleAnimAttacker = atkBattler;
    gBattleAnimTarget = defBattler;
    LaunchBattleAnimation(ANIM_TYPE_SPECIAL, tableId);
    taskId = CreateTask(Task_ClearBitWhenSpecialAnimDone, 10);
    gTasks[taskId].tBattlerId = activeBattler;
    gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].specialAnimActive = 1;
}

static void Task_ClearBitWhenSpecialAnimDone(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].tBattlerId].specialAnimActive = 0;
        DestroyTask(taskId);
    }
}

#undef tBattlerId

// Check if SE has finished or 30 calls, whichever comes first
bool8 IsBattleSEPlaying(u8 battler)
{
    u8 zero = 0;

    if (IsSEPlaying())
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer++;
        if (gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer < 30)
            return TRUE;

        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
    }
    if (zero == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].soundTimer = 0;
        return FALSE;
    }

    // Never reached
    return TRUE;
}

void BattleLoadMonSpriteGfx(struct Pokemon *mon, u32 battler)
{
    u32 monsPersonality, currentPersonality, isShiny, species, paletteOffset, position;
    const void *lzPaletteData;

    if (GetMonData(mon, MON_DATA_IS_EGG) || GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE) // Don't load GFX of egg pokemon.
        return;

    monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    currentPersonality = monsPersonality;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_NONE)
        species = GetMonData(mon, MON_DATA_SPECIES);
    else
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;

    position = battler;
    if (GetBattlerSide(battler) == LADO_OPONENTE)
    {
        HandleLoadSpecialPokePic(TRUE,
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 species, currentPersonality);
    }
    else
    {
        HandleLoadSpecialPokePic(FALSE,
                                 gMonSpritesGfxPtr->spritesGfx[position],
                                 species, currentPersonality);
    }

    paletteOffset = OBJ_PLTT_ID(battler);

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_NONE)
        lzPaletteData = GetMonFrontSpritePal(mon);
    else
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, currentPersonality);

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, PLTT_SIZE_4BPP);
    LoadPalette(gDecompressionBuffer, BG_PLTT_ID(8) + BG_PLTT_ID(battler), PLTT_SIZE_4BPP);
    DesplazaTonoPaleta(paletteOffset, currentPersonality);
    DesplazaTonoPaleta(BG_PLTT_ID(8) + BG_PLTT_ID(battler), currentPersonality);

    // Ya tiene su color definitivo. Ahora le toca la luz de la hora.
    GuardaYTinePaletaCombate(16 + battler);
    GuardaYTinePaletaCombate(8 + battler);
}

void DecompressTrainerFrontPic(u16 frontPicId, u8 battler)
{
    DecompressPicFromTable(&gTrainerSprites[frontPicId].frontPic,
                           gMonSpritesGfxPtr->spritesGfx[battler]);
    LoadCompressedSpritePalette(&gTrainerSprites[frontPicId].palette);

    // El entrenador rival no va a una ranura fija como el jugador, sino a una que
    // se le asigna por etiqueta, asi que hay que preguntar cual le ha tocado. Era
    // el unico sprite del escenario que se quedaba sin luz.
    {
        u32 ranura = IndexOfSpritePaletteTag(gTrainerSprites[frontPicId].palette.tag);

        if (ranura != 0xFF)
            TinePaletaSueltaDeCombate(16 + ranura);
    }
}

void DecompressTrainerBackPic(u16 backPicId, u8 battler)
{
    DecompressPicFromTable(&gTrainerBacksprites[backPicId].backPic,
                           gMonSpritesGfxPtr->spritesGfx[battler]);
    LoadCompressedPalette(gTrainerBacksprites[backPicId].palette.data,
                          OBJ_PLTT_ID(battler), PLTT_SIZE_4BPP);
    // El entrenador esta en el mismo escenario que los Pokemon, asi que le da la
    // misma luz. Va a la misma ranura de paleta que el combatiente.
    GuardaYTinePaletaCombate(16 + battler);
}

void FreeTrainerFrontPicPalette(u16 frontPicId)
{
    FreeSpritePaletteByTag(gTrainerSprites[frontPicId].palette.tag);
}

void CargaBarrasSalud(void)
{
    LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
    CategoryIcons_LoadSpritesGfx();

    for (u32 combatiente = 0; combatiente < NUMERO_COMBATIENTES; combatiente++)
        LoadSpriteSheet(&sHojasMarcador[combatiente]);

    LoadSpriteSheet(&sHojaContornoBarra);
    LoadSpriteSheet(&sHojaIconosEstado);
}

void IniciaSpritesBatalla(void)
{
    // Los marcadores de vida y las sombras se crean aqui abajo, y todos toman su
    // paleta de la misma etiqueta (TAG_HEALTHBOX_PLAYER1_TILE). Si sus paletas y
    // hojas no estan cargadas antes, CreateSprite no encuentra la etiqueta y les
    // asigna la paleta 15 con tiles sin inicializar: salen como cuadros negros.
    // En el arranque normal del combate nadie mas llamaba a CargaBarrasSalud;
    // solo lo hacia reshow_battle_screen al volver a mostrar la pantalla.
    CargaBarrasSalud();

    ClearSpritesBattlerHealthboxAnimData();
    for (u32 combatiente = 0; combatiente < gBattlersCount; combatiente++)
    {
        gMarcadorSpriteIds[combatiente] = CreaMarcadorCombate(combatiente);
        ColocaMarcador(combatiente);
        if (GetBattlerSide(combatiente) == LADO_JUGADOR)
        {
            ActualizaMarcador(gMarcadorSpriteIds[combatiente], &gPlayerParty[gBattlerPartyIndexes[combatiente]], MARCADOR_TODO);
        }
        else
        {
            ActualizaMarcador(gMarcadorSpriteIds[combatiente], &gEnemyParty[gBattlerPartyIndexes[combatiente]], MARCADOR_TODO);
        }
        OcultaMarcador(gMarcadorSpriteIds[combatiente]);
    }
    LoadAndCreateEnemyShadowSprites();
    BufferBattlePartyCurrentOrder();
}

void ClearSpritesHealthboxAnimData(void)
{
    memset(gBattleSpritesDataPtr->healthBoxesData, 0, sizeof(struct BattleHealthboxInfo) * NUMERO_COMBATIENTES);
    memset(gBattleSpritesDataPtr->animationData, 0, sizeof(struct BattleAnimationInfo));
}

static void ClearSpritesBattlerHealthboxAnimData(void)
{
    ClearSpritesHealthboxAnimData();
    memset(gBattleSpritesDataPtr->battlerData, 0, sizeof(struct BattleSpriteInfo) * NUMERO_COMBATIENTES);
}

void CopyAllBattleSpritesInvisibilities(void)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        gBattleSpritesDataPtr->battlerData[i].invisible = gSprites[gBattlerSpriteIds[i]].invisible;
}

void CopyBattleSpriteInvisibility(u8 battler)
{
    gBattleSpritesDataPtr->battlerData[battler].invisible = gSprites[gBattlerSpriteIds[battler]].invisible;
}

void GestionaCambioGraficoEspecie(u32 atacante, u32 defensor, bool32 usarPersonalidadEnemigo)
{
    u32 personalityValue, position, paletteOffset, targetSpecies;
    bool32 isShiny;
    const void *lzPaletteData, *src;
    void *dst;

    position = atacante;

    if (GetBattlerSide(defensor) == LADO_OPONENTE)
        targetSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[defensor]], MON_DATA_SPECIES);
    else
        targetSpecies = GetMonData(&gPlayerParty[gBattlerPartyIndexes[defensor]], MON_DATA_SPECIES);

    if (GetBattlerSide(atacante) == LADO_JUGADOR)
    {
        if (B_TRANSFORM_SHINY >= GEN_4 && usarPersonalidadEnemigo)
        {
            personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[defensor]], MON_DATA_PERSONALITY);
            isShiny = GetMonData(&gEnemyParty[gBattlerPartyIndexes[defensor]], MON_DATA_IS_SHINY);
        }
        else
        {
            personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[atacante]], MON_DATA_PERSONALITY);
            isShiny = GetMonData(&gPlayerParty[gBattlerPartyIndexes[atacante]], MON_DATA_IS_SHINY);
        }

        HandleLoadSpecialPokePic(FALSE,
                                    gMonSpritesGfxPtr->spritesGfx[position],
                                    targetSpecies,
                                    personalityValue);
    }
    else
    {
        if (B_TRANSFORM_SHINY >= GEN_4 && usarPersonalidadEnemigo)
        {
            personalityValue = GetMonData(&gPlayerParty[gBattlerPartyIndexes[defensor]], MON_DATA_PERSONALITY);
            isShiny = GetMonData(&gPlayerParty[gBattlerPartyIndexes[defensor]], MON_DATA_IS_SHINY);
        }
        else
        {
            personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[atacante]], MON_DATA_PERSONALITY);
            isShiny = GetMonData(&gEnemyParty[gBattlerPartyIndexes[atacante]], MON_DATA_IS_SHINY);
        }

        HandleLoadSpecialPokePic(TRUE,
                                    gMonSpritesGfxPtr->spritesGfx[position],
                                    targetSpecies,
                                    personalityValue);
    }
    src = gMonSpritesGfxPtr->spritesGfx[position];
    dst = (void *)(OBJ_VRAM0 + gSprites[gBattlerSpriteIds[atacante]].oam.tileNum * TILE_4BPP);
    DmaCopy32(3, src, dst, MON_PIC_SIZE);
    paletteOffset = OBJ_PLTT_ID(atacante);
    lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(targetSpecies, isShiny, personalityValue);
    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, PLTT_SIZE_4BPP);

    DesplazaTonoPaleta(paletteOffset, personalityValue);
    BlendPalette(paletteOffset, 16, 6, RGB_WHITE);
    CopiaCpu32(&gPlttBufferFaded[paletteOffset], &gPlttBufferUnfaded[paletteOffset], PLTT_SIZE_4BPP);
    // Transformacion cambia la paleta a media pelea, asi que hay que volver a
    // darle la luz de la hora.
    GuardaYTinePaletaCombate(16 + atacante);

    gSprites[gBattlerSpriteIds[atacante]].y = GetBattlerSpriteDefault_Y(atacante);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[atacante]], 0);
}

void BattleLoadSubstituteOrMonSpriteGfx(u8 battler, bool8 loadMonSprite)
{
    s32 i, position, palOffset;

    if (!loadMonSprite)
    {
        position = battler;

        if (GetBattlerSide(battler) != LADO_JUGADOR)
            LZDecompressVram(gBattleAnimSpriteGfx_Substitute, gMonSpritesGfxPtr->spritesGfx[position]);
        else
            LZDecompressVram(gBattleAnimSpriteGfx_SubstituteBack, gMonSpritesGfxPtr->spritesGfx[position]);

        for (i = 1; i < 4; i++)
        {
            Dma3CopyLarge32_(gMonSpritesGfxPtr->spritesGfx[position], &gMonSpritesGfxPtr->spritesGfx[position][MON_PIC_SIZE * i], MON_PIC_SIZE);
        }

        palOffset = OBJ_PLTT_ID(battler);
        LoadCompressedPalette(gBattleAnimSpritePal_Substitute, palOffset, PLTT_SIZE_4BPP);
        GuardaYTinePaletaCombate(16 + battler);
    }
    else
        BattleLoadMonSpriteGfx(&GetBattlerParty(battler)[gBattlerPartyIndexes[battler]], battler);
}

void LoadBattleMonGfxAndAnimate(u8 battler, bool8 loadMonSprite, u32 spriteId)
{
    BattleLoadSubstituteOrMonSpriteGfx(battler, loadMonSprite);
    StartSpriteAnim(&gSprites[spriteId], 0);

    if (!loadMonSprite)
        gSprites[spriteId].y = GetSubstituteSpriteDefault_Y(battler);
    else
        gSprites[spriteId].y = GetBattlerSpriteDefault_Y(battler);
}

void TrySetBehindSubstituteSpriteBit(u8 battler, enum Movimientos move)
{
    if (gMovimientos[move].effect == EFFECT_SUBSTITUTE)
        gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 1;
}

void ClearBehindSubstituteBit(u8 battler)
{
    gBattleSpritesDataPtr->battlerData[battler].behindSubstitute = 0;
}

void HandleLowHpMusicChange(struct Pokemon *mon, u8 battler)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    if (GetHPBarLevel(hp, maxHP) == HP_BAR_RED)
    {
        if (!gBattleSpritesDataPtr->battlerData[battler].lowHpSong)
        {
            if (!gBattleSpritesDataPtr->battlerData[ALIADO(battler)].lowHpSong)
                PlaySE(SE_LOW_HEALTH);
            gBattleSpritesDataPtr->battlerData[battler].lowHpSong = 1;
        }
    }
    else
    {
        gBattleSpritesDataPtr->battlerData[battler].lowHpSong = 0;
        if (!EsCombateContraEntrenador(gCombate->tipoCombate))
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            return;
        }
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && !gBattleSpritesDataPtr->battlerData[ALIADO(battler)].lowHpSong)
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            return;
        }
    }
}

void BattleStopLowHpSound(void)
{
    u8 playerBattler = JUGADOR_IZQUIERDA;

    gBattleSpritesDataPtr->battlerData[playerBattler].lowHpSong = 0;
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        gBattleSpritesDataPtr->battlerData[ALIADO(playerBattler)].lowHpSong = 0;

    m4aSongNumStop(SE_LOW_HEALTH);
}

u8 GetMonHPBarLevel(struct Pokemon *mon)
{
    u16 hp = GetMonData(mon, MON_DATA_HP);
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    return GetHPBarLevel(hp, maxHP);
}

void HandleBattleLowHpMusicChange(void)
{
    if (gMain.inBattle)
    {
        u8 playerBattler1 = JUGADOR_IZQUIERDA;
        u8 playerBattler2 = JUGADOR_DERECHA;
        u8 battler1PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler1]);
        u8 battler2PartyId = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[playerBattler2]);

        if (GetMonData(&gPlayerParty[battler1PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler1PartyId], playerBattler1);
        if (EsCombateContraEntrenador(gCombate->tipoCombate) && GetMonData(&gPlayerParty[battler2PartyId], MON_DATA_HP) != 0)
            HandleLowHpMusicChange(&gPlayerParty[battler2PartyId], playerBattler2);
    }
}

void SetBattlerSpriteAffineMode(u8 affineMode)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerSpritePresent(i))
        {
            gSprites[gBattlerSpriteIds[i]].oam.affineMode = affineMode;
            if (affineMode == ST_OAM_AFFINE_OFF)
            {
                gBattleSpritesDataPtr->healthBoxesData[i].matrixNum = gSprites[gBattlerSpriteIds[i]].oam.matrixNum;
                gSprites[gBattlerSpriteIds[i]].oam.matrixNum = 0;
            }
            else
            {
                gSprites[gBattlerSpriteIds[i]].oam.matrixNum = gBattleSpritesDataPtr->healthBoxesData[i].matrixNum;
            }
        }
    }
}


void SpriteCB_EnemyShadow(struct Sprite *shadowSprite);

void CreateEnemyShadowSprite(u32 battler)
{
    u8 sombra = CreaSombraPokemon(gBattlerSpriteIds[battler], 0xC8);

    gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary = sombra;

    if (sombra < MAX_SPRITES)
    {
        gSprites[sombra].sSombraDueno = battler;
        gSprites[sombra].callback = SpriteCB_EnemyShadow;
    }
}

void LoadAndCreateEnemyShadowSprites(void)
{
    u32 i;

    CargaGraficosSombraPokemon();
    // Primer ajuste de la mezcla, para las sombras que nacen antes de que el
    // combate llegue a su reposo (la vuelta de un menu, sin entrada que valga).
    // A partir de ahi manda RestauraRegistrosCombate, que pone lo mismo.
    PreparaMezclaSombraPokemon();

    for (i = 0; i < gBattlersCount; i++)
        gBattleSpritesDataPtr->healthBoxesData[i].shadowSpriteIdPrimary = MAX_SPRITES;

    // Solo los rivales proyectan sombra: los propios se ven de espaldas y su
    // sombra caeria fuera de la plataforma.
    CreateEnemyShadowSprite(OPONENTE_IZQUIERDA);

    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        CreateEnemyShadowSprite(OPONENTE_DERECHA);
}

void SpriteCB_EnemyShadow(struct Sprite *shadowSprite)
{
    u32 battler = shadowSprite->sSombraDueno;
    struct Sprite *battlerSprite = &gSprites[gBattlerSpriteIds[battler]];
    s32 desplazamientoX = 0, desplazamientoY = 0;
    bool32 invisible = FALSE;

    if (!battlerSprite->inUse || !IsBattlerSpritePresent(battler))
    {
        shadowSprite->callback = SpriteCB_SetInvisible;
        return;
    }

    // Antes se escondia durante CUALQUIER animacion. No hace falta: solo estorba
    // a las que se adueñan de la mezcla, y esas se detectan solas mirando como han
    // dejado los registros. Las demas -la mayoria- pueden llevar sombra.
    // El sprite apagado por estar dibujado en una capa de fondo no cuenta: el
    // Pokemon sigue viendose, y esa capa tiene mas prioridad que la sombra, asi
    // que el orden entre los dos se mantiene.
    if ((battlerSprite->invisible && !gBattleSpritesDataPtr->battlerData[battler].enFondoAnimacion)
        || !MezclaSirveParaSombra())
    {
        invisible = TRUE;
    }
    else
    {
        // Se lee en vivo porque la especie puede cambiar en combate (Transformacion).
        //
        // Pero al acabar el combate gBattleMons se vacia mientras la sombra sigue
        // dibujandose, y entonces esto devolvia SPECIES_NONE, que no declara
        // SOMBRA(...): tamano S y desplazamientos a cero. De ahi que la sombra se
        // encogiera un poco justo al terminar. Con la especie a cero nos quedamos
        // con la ultima buena.
        u32 especie = SanitizeSpeciesId(gBattleMons[battler].species);

        if (especie == SPECIES_NONE)
            especie = shadowSprite->sSombraEspecie;
        else
            shadowSprite->sSombraEspecie = especie;

        desplazamientoX = gSpeciesInfo[especie].enemyShadowXOffset;
        desplazamientoY = gSpeciesInfo[especie].enemyShadowYOffset;
        FijaAplastadoSombra(shadowSprite, gSpeciesInfo[especie].enemyShadowSize);
        if (gSpeciesInfo[especie].suppressEnemyShadow)
            invisible = TRUE;
    }

    if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
        invisible = TRUE;

    ColocaSombraPokemon(shadowSprite, battlerSprite, desplazamientoX, desplazamientoY);
    shadowSprite->invisible = invisible;
}

#undef tBattlerId

void SpriteCB_SetInvisible(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
}

void SetBattlerShadowSpriteCallback(u8 battler, u16 species)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR || gBattleScripting.monCaught)
    {
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
        return;
    }

    if (gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary >= MAX_SPRITES)
        return;

    if (gSpeciesInfo[SanitizeSpeciesId(species)].suppressEnemyShadow == FALSE)
    {
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_EnemyShadow;
    }
    else
    {
        gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
    }
}

void HideBattlerShadowSprite(u8 battler)
{
    gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback = SpriteCB_SetInvisible;
}

// Color the background tiles surrounding the action selection and move windows
void FillAroundBattleWindows(void)
{
    u16 *vramPtr = (u16 *)(VRAM + 576);
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (!(*vramPtr & 0xF000))
                *vramPtr |= 0xF000;
            if (!(*vramPtr & 0x0F00))
                *vramPtr |= 0x0F00;
            if (!(*vramPtr & 0x00F0))
                *vramPtr |= 0x00F0;
            if (!(*vramPtr & 0x000F))
                *vramPtr |= 0x000F;
            vramPtr++;
        }
    }
}

void ClearTemporarySpeciesSpriteData(u8 battler, bool8 dontClearSubstitute)
{
    if (!dontClearSubstitute)
        ClearBehindSubstituteBit(battler);
}

void AllocateMonSpritesGfx(void)
{
    gMonSpritesGfxPtr = NULL;
    gMonSpritesGfxPtr = AllocZeroed(sizeof(*gMonSpritesGfxPtr));
    gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(MON_PIC_SIZE * NUMERO_FRAMES_POKEMON * NUMERO_COMBATIENTES);

    for (u32 indiceCombatiente = 0; indiceCombatiente < NUMERO_COMBATIENTES; indiceCombatiente++)
    {
        gMonSpritesGfxPtr->spritesGfx[indiceCombatiente] = gMonSpritesGfxPtr->firstDecompressed + (indiceCombatiente * MON_PIC_SIZE * NUMERO_FRAMES_POKEMON);
        gMonSpritesGfxPtr->templates[indiceCombatiente] = gBattlerSpriteTemplates[indiceCombatiente];

        for (u32 frameCombatiente = 0; frameCombatiente < NUMERO_FRAMES_POKEMON; frameCombatiente++)
        {
            if (gMonSpritesGfxPtr->spritesGfx[indiceCombatiente])
            {
                gMonSpritesGfxPtr->frameImages[indiceCombatiente][frameCombatiente].data = gMonSpritesGfxPtr->spritesGfx[indiceCombatiente] + (frameCombatiente * MON_PIC_SIZE);
                gMonSpritesGfxPtr->frameImages[indiceCombatiente][frameCombatiente].size = MON_PIC_SIZE;
            }
        }
        
        gMonSpritesGfxPtr->templates[indiceCombatiente].images = gMonSpritesGfxPtr->frameImages[indiceCombatiente];
    }
}

void FreeMonSpritesGfx(void)
{
    if (gMonSpritesGfxPtr == NULL)
        return;

    TRY_FREE_AND_SET_NULL(gMonSpritesGfxPtr->buffer);
    FREE_AND_SET_NULL(gMonSpritesGfxPtr->firstDecompressed);
    gMonSpritesGfxPtr->spritesGfx[JUGADOR_IZQUIERDA] = NULL;
    gMonSpritesGfxPtr->spritesGfx[OPONENTE_IZQUIERDA] = NULL;
    gMonSpritesGfxPtr->spritesGfx[JUGADOR_DERECHA] = NULL;
    gMonSpritesGfxPtr->spritesGfx[OPONENTE_DERECHA] = NULL;
    FREE_AND_SET_NULL(gMonSpritesGfxPtr);
}

bool32 ShouldPlayNormalMonCry(struct Pokemon *mon)
{
    s16 hp, maxHP;
    s32 barLevel;

    if (GetMonData(mon, MON_DATA_STATUS) & (STATUS1_ANY | STATUS1_TOXIC_COUNTER))
        return FALSE;

    hp = GetMonData(mon, MON_DATA_HP);
    maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    barLevel = GetHPBarLevel(hp, maxHP);
    if (barLevel <= HP_BAR_YELLOW)
        return FALSE;

    return TRUE;
}

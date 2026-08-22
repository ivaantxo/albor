#include "global.h"
#include "depuracion_mgba.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "battle_controllers.h"
#include "battle_gfx_sfx_util.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "event_object_movement.h"
#include "palette.h"
#include "party_menu.h"
#include "string_util.h"
#include "sound.h"
#include "task.h"
#include "util.h"
#include "text.h"
#include "constants/abilities.h"
#include "constants/songs.h"

COMMON_DATA void (*gBattlerControllerFuncs[NUMERO_COMBATIENTES])(u32 battler) = {0};
COMMON_DATA u8 gBattleControllerData[NUMERO_COMBATIENTES] = {0}; // Used by the battle controllers to store misc sprite/task IDs for each battler
COMMON_DATA void (*gBattlerControllerEndFuncs[NUMERO_COMBATIENTES])(u32 battler) = {0}; // Controller's buffer complete function for each battler

static void InitSinglePlayerBtlControllers(void);
static void SetBattlePartyIds(void);
static void Task_StartSendOutAnim(u8 taskId);
static void SpriteCB_FreePlayerSpriteLoadMonSprite(struct Sprite *sprite);
static void SpriteCB_FreeOpponentSprite(struct Sprite *sprite);

void PreparaVarsBatalla(void)
{
    gBattleMainFunc = BeginBattleIntroDummy;

    for (u32 combatiente = JUGADOR_IZQUIERDA; combatiente < NUMERO_COMBATIENTES; combatiente++)
    {
        gBattlerControllerFuncs[combatiente] = BattleControllerDummy;
        gActionSelectionCursor[combatiente] = 0;
        gMoveSelectionCursor[combatiente] = 0;
        DesmarcaCombatienteOcupado(combatiente);
    }

    ClearBattleAnimationVars();
    BattleAI_SetupItems();
    BattleAI_SetupFlags();
}

void InitBattleControllers(void)
{
    InitSinglePlayerBtlControllers();
    SetBattlePartyIds();

    for (u32 combatiente = JUGADOR_IZQUIERDA; combatiente < gBattlersCount; combatiente++)
        BufferBattlePartyCurrentOrderBySide(combatiente);
}

static void InitSinglePlayerBtlControllers(void)
{
    if (!EsCombateContraEntrenador(gCombate->tipoCombate))
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattlerControllerFuncs[0] = SetControllerToPlayer;


        gBattlerControllerFuncs[1] = SetControllerToOpponent;

        gBattlersCount = 2;
    }
    else
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattlerControllerFuncs[0] = SetControllerToPlayer;

        gBattlerControllerFuncs[1] = SetControllerToOpponent;

        gBattlerControllerFuncs[2] = SetControllerToPlayer;

        gBattlerControllerFuncs[3] = SetControllerToOpponent;

        gBattlersCount = NUMERO_COMBATIENTES;
    }
}

bool32 IsValidForBattle(struct Pokemon *mon)
{
    u32 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    return (species != SPECIES_NONE
         && species != SPECIES_EGG
         && GetMonData(mon, MON_DATA_HP) != 0
         && GetMonData(mon, MON_DATA_IS_EGG) == FALSE);
}

static void SetBattlePartyIds(void)
{
    s32 i, j;

    for (i = 0; i < gBattlersCount; i++)
    {
        for (j = 0; j < PARTY_SIZE; j++)
        {
            if (i < 2)
            {
                if (GetBattlerSide(i) == LADO_JUGADOR)
                {
                    if (IsValidForBattle(&gPlayerParty[j]))
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                }
                else
                {
                    if (IsValidForBattle(&gEnemyParty[j]))
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                }
            }
            else
            {
                if (GetBattlerSide(i) == LADO_JUGADOR)
                {
                    if (IsValidForBattle(&gPlayerParty[j]) && gBattlerPartyIndexes[i - 2] != j)
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                }
                else
                {
                    if (IsValidForBattle(&gEnemyParty[j]) && gBattlerPartyIndexes[i - 2] != j)
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                }

                // No valid mons were found. Add the empty slot.
                if (gBattlerPartyIndexes[i - 2] == 0)
                    gBattlerPartyIndexes[i] = 1;
                else
                    gBattlerPartyIndexes[i] = 0;
            }
        }
    }
}

// Estado del comando en curso de cada combatiente.
//
// Antes esto vivia en bufferA y bufferB, dos arrays de 512 bytes por combatiente
// donde los argumentos se empaquetaban byte a byte y el manejador los desempaquetaba
// a continuacion. Ese empaquetado era el protocolo del cable de enlace; el enlace ya
// no esta, asi que solo quedaba el coste.
COMMON_DATA struct ArgumentosComando gArgumentosComando[NUMERO_COMBATIENTES] = {0};
COMMON_DATA struct RespuestaCombatiente gRespuestaCombatiente[NUMERO_COMBATIENTES] = {0};
COMMON_DATA u8 gComandoEnCurso[NUMERO_COMBATIENTES] = {0};

// Deja anotado que comando toca. El manejador se reentra en cada fotograma hasta
// que se da por terminado, de ahi que haga falta recordarlo.
static void ArrancaComando(u32 combatiente, u32 comando)
{
    gComandoEnCurso[combatiente] = comando;
}

// ---------------------------------------------------------------------------
// Ordenes: del guion de combate al combatiente.
// ---------------------------------------------------------------------------

void ComandoObtenDatosPokemon(u32 combatiente, u8 peticion, u8 pokemon)
{
    gArgumentosComando[combatiente].peticion = peticion;
    gArgumentosComando[combatiente].pokemon = pokemon;
    ArrancaComando(combatiente, CONTROLLER_GETMONDATA);
}

void ComandoFijaDatosPokemon(u32 combatiente, u8 peticion, u8 pokemon, u8 bytes, void *datos)
{
    if (bytes > sizeof(gArgumentosComando[combatiente].datos))
        bytes = sizeof(gArgumentosComando[combatiente].datos);

    gArgumentosComando[combatiente].peticion = peticion;
    gArgumentosComando[combatiente].pokemon = pokemon;
    gArgumentosComando[combatiente].bytes = bytes;
    memcpy(gArgumentosComando[combatiente].datos, datos, bytes);
    ArrancaComando(combatiente, CONTROLLER_SETMONDATA);
}

void ComandoCargaSpritePokemon(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_LOADMONSPRITE);
}

void ComandoAnimacionEntrada(u32 combatiente, u8 indiceEquipo, bool8 noLimpiarSustituto)
{
    gArgumentosComando[combatiente].indiceEquipo = indiceEquipo;
    gArgumentosComando[combatiente].noLimpiarSustituto = noLimpiarSustituto;
    ArrancaComando(combatiente, CONTROLLER_SWITCHINANIM);
}

void ComandoDevuelvePokemonABall(u32 combatiente, bool8 saltarAnimacion)
{
    gArgumentosComando[combatiente].saltarAnimacion = saltarAnimacion;
    ArrancaComando(combatiente, CONTROLLER_RETURNMONTOBALL);
}

void ComandoDibujaEntrenador(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_DRAWTRAINERPIC);
}

void ComandoEntrenadorEntra(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_TRAINERSLIDE);
}

void ComandoEntrenadorSale(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_TRAINERSLIDEBACK);
}

void ComandoAnimacionDebilitado(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_FAINTANIMATION);
}

void ComandoAnimacionLanzarBall(u32 combatiente, u8 caso)
{
    gArgumentosComando[combatiente].caso = caso;
    ArrancaComando(combatiente, CONTROLLER_BALLTHROWANIM);
}

void ComandoAnimacionMovimiento(u32 combatiente, enum Movimientos movimiento, u8 turnoDelMovimiento,
                                u16 potencia, s32 dano, u8 amistad, struct DisableStruct *estadoDeshabilitado,
                                u8 golpesMultiples)
{
    struct ArgumentosComando *args = &gArgumentosComando[combatiente];

    args->movimiento = movimiento;
    args->turnoDelMovimiento = turnoDelMovimiento;
    args->potencia = potencia;
    args->dano = dano;
    args->amistad = amistad;
    args->golpesMultiples = golpesMultiples;
    args->clima = ClimaTieneEfecto() ? (1 << gCombate->clima.modo) : 0;
    args->estadoDeshabilitado = *estadoDeshabilitado;
    ArrancaComando(combatiente, CONTROLLER_MOVEANIMATION);
}

void ComandoEligeAccion(u32 combatiente, u8 accion)
{
    gArgumentosComando[combatiente].accion = accion;
    ArrancaComando(combatiente, CONTROLLER_CHOOSEACTION);
}

void ComandoCuadroSiNo(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_YESNOBOX);
}

void ComandoEligeMovimiento(u32 combatiente, bool8 esCombateDoble, bool8 sinNumeroDePP, struct DatosMovimiento *datosMovimiento)
{
    gArgumentosComando[combatiente].esCombateDoble = esCombateDoble;
    gArgumentosComando[combatiente].sinNumeroDePP = sinNumeroDePP;
    gArgumentosComando[combatiente].datosMovimiento = *datosMovimiento;
    ArrancaComando(combatiente, CONTROLLER_CHOOSEMOVE);
}

void ComandoEligePokemon(u32 combatiente, u8 caso, u8 ranura, u16 habilidad, u8 *datos)
{
    gArgumentosComando[combatiente].caso = caso;
    gArgumentosComando[combatiente].ranura = ranura;
    gArgumentosComando[combatiente].habilidad = habilidad;
    for (u32 i = 0; i < 3; i++)
        gArgumentosComando[combatiente].datosEleccion[i] = datos[i];
    ArrancaComando(combatiente, CONTROLLER_CHOOSEPOKEMON);
}

void ComandoActualizaBarraSalud(u32 combatiente, u16 valorPS)
{
    gArgumentosComando[combatiente].valorPS = valorPS;
    ArrancaComando(combatiente, CONTROLLER_HEALTHBARUPDATE);
}

void ComandoActualizaExperiencia(u32 combatiente, u8 indiceEquipo, s32 experiencia)
{
    gArgumentosComando[combatiente].indiceEquipo = indiceEquipo;
    gArgumentosComando[combatiente].experiencia = experiencia;
    ArrancaComando(combatiente, CONTROLLER_EXPUPDATE);
}

void ComandoActualizaIconoEstado(u32 combatiente, u32 estado1, u32 estado2)
{
    gArgumentosComando[combatiente].estado1 = estado1;
    gArgumentosComando[combatiente].estado2 = estado2;
    ArrancaComando(combatiente, CONTROLLER_STATUSICONUPDATE);
}

void ComandoAnimacionEstado(u32 combatiente, bool8 esEstado2, u32 estado)
{
    gArgumentosComando[combatiente].esEstado2 = esEstado2;
    gArgumentosComando[combatiente].estado1 = estado;
    ArrancaComando(combatiente, CONTROLLER_STATUSANIMATION);
}

void ComandoAnimacionGolpe(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_HITANIMATION);
}

void ComandoNoPuedeCambiar(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_CANTSWITCH);
}

void ComandoSuenaEfecto(u32 combatiente, u16 cancion)
{
    gArgumentosComando[combatiente].cancion = cancion;
    ArrancaComando(combatiente, CONTROLLER_PLAYSE);
}

void ComandoSuenaFanfarriaOMusica(u32 combatiente, u16 cancion, bool8 esMusica)
{
    gArgumentosComando[combatiente].cancion = cancion;
    gArgumentosComando[combatiente].esMusica = esMusica;
    ArrancaComando(combatiente, CONTROLLER_PLAYFANFAREORBGM);
}

void ComandoGritoAlDebilitarse(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_FAINTINGCRY);
}

void ComandoEntradaEscenario(u32 combatiente, u8 terreno)
{
    gArgumentosComando[combatiente].terreno = terreno;
    ArrancaComando(combatiente, CONTROLLER_INTROSLIDE);
}

void ComandoEntrenadorLanzaBall(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_INTROTRAINERBALLTHROW);
}

void ComandoMuestraResumenEquipo(u32 combatiente, struct HpAndStatus *resumen, u8 banderas)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
        gArgumentosComando[combatiente].resumenEquipo[i] = resumen[i];
    gArgumentosComando[combatiente].banderas = banderas;
    ArrancaComando(combatiente, CONTROLLER_DRAWPARTYSTATUSSUMMARY);
}

void ComandoOcultaResumenEquipo(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_HIDEPARTYSTATUSSUMMARY);
}

void ComandoTerminaBote(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_ENDBOUNCE);
}

void ComandoVisibilidadSprite(u32 combatiente, bool8 invisible)
{
    gArgumentosComando[combatiente].invisible = invisible;
    ArrancaComando(combatiente, CONTROLLER_SPRITEINVISIBILITY);
}

void ComandoAnimacionCombate(u32 combatiente, u8 animacion, struct DisableStruct *estadoDeshabilitado, u16 argumento)
{
    gArgumentosComando[combatiente].animacion = animacion;
    gArgumentosComando[combatiente].argumentoAnimacion = argumento;
    gArgumentosComando[combatiente].estadoDeshabilitado = *estadoDeshabilitado;
    ArrancaComando(combatiente, CONTROLLER_BATTLEANIMATION);
}

void ComandoReiniciaSeleccion(u32 combatiente, u8 caso)
{
    gArgumentosComando[combatiente].caso = caso;
    ArrancaComando(combatiente, CONTROLLER_RESETACTIONMOVESELECTION);
}

void ComandoMenuDepuracion(u32 combatiente)
{
    ArrancaComando(combatiente, CONTROLLER_DEBUGMENU);
}

// ---------------------------------------------------------------------------
// Respuestas: del combatiente al guion de combate.
// ---------------------------------------------------------------------------

void RespondeDosValores(u32 combatiente, u8 valor8, u32 valor32)
{
    gRespuestaCombatiente[combatiente].tipo = CONTROLLER_TWORETURNVALUES;
    gRespuestaCombatiente[combatiente].valor8 = valor8;
    gRespuestaCombatiente[combatiente].valor32 = valor32;
    gRespuestaCombatiente[combatiente].posicionMovimiento = valor32 & 0xFF;
    gRespuestaCombatiente[combatiente].objetivo = (valor32 >> 8) & 0xFF;
}

void RespondeUnValor(u32 combatiente, u16 valor)
{
    gRespuestaCombatiente[combatiente].tipo = CONTROLLER_ONERETURNVALUE;
    gRespuestaCombatiente[combatiente].valor8 = valor & 0xFF;
    gRespuestaCombatiente[combatiente].valor32 = valor;
}

void RespondePokemonElegido(u32 combatiente, u8 indiceEquipo, u8 *ordenEquipo)
{
    gRespuestaCombatiente[combatiente].tipo = CONTROLLER_CHOSENMONRETURNVALUE;
    gRespuestaCombatiente[combatiente].valor8 = indiceEquipo;
    for (u32 i = 0; i < 3; i++)
        gRespuestaCombatiente[combatiente].datos[i] = ordenEquipo[i];
}

void RespondeDatos(u32 combatiente, u16 tamano, void *datos)
{
    gRespuestaCombatiente[combatiente].tipo = CONTROLLER_DATATRANSFER;
    if (tamano > sizeof(gRespuestaCombatiente[combatiente].datos))
        tamano = sizeof(gRespuestaCombatiente[combatiente].datos);
    memcpy(gRespuestaCombatiente[combatiente].datos, datos, tamano);
}

// Standardized Controller functions

// Can be used for all the controllers.
void BattleControllerComplete(u32 battler)
{
    gBattlerControllerEndFuncs[battler](battler);
}

static u32 GetBattlerMonData(u32 battler, struct Pokemon *party, u32 monId, u8 *dst)
{
    struct BattlePokemon battleMon;
    struct DatosMovimiento datosMovimiento;
    u8 nickname[POKEMON_NAME_LENGTH * 2];
    u16 data16;
    u32 data32;
    s32 size = 0;

    switch (gArgumentosComando[battler].peticion)
    {
    case REQUEST_ALL_BATTLE:
        battleMon.species = GetMonData(&party[monId], MON_DATA_SPECIES);
        battleMon.item = GetMonData(&party[monId], MON_DATA_HELD_ITEM);
        for (size = 0; size < MAXIMO_MOVIMIENTOS_POKEMON; size++)
        {
            battleMon.movimientos[size] = GetMonData(&party[monId], MON_DATA_MOVE1 + size);
            battleMon.pp[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        }
        battleMon.friendship = GetMonData(&party[monId], MON_DATA_FRIENDSHIP);
        battleMon.experience = GetMonData(&party[monId], MON_DATA_EXP);
        battleMon.personality = GetMonData(&party[monId], MON_DATA_PERSONALITY);
        battleMon.status1 = GetMonData(&party[monId], MON_DATA_STATUS);
        battleMon.level = GetMonData(&party[monId], MON_DATA_LEVEL);
        battleMon.hp = GetMonData(&party[monId], MON_DATA_HP);
        battleMon.maxHP = GetMonData(&party[monId], MON_DATA_MAX_HP);
        battleMon.attack = GetMonData(&party[monId], MON_DATA_ATK);
        battleMon.defense = GetMonData(&party[monId], MON_DATA_DEF);
        battleMon.speed = GetMonData(&party[monId], MON_DATA_SPEED);
        battleMon.spAttack = GetMonData(&party[monId], MON_DATA_SPATK);
        battleMon.spDefense = GetMonData(&party[monId], MON_DATA_SPDEF);
        battleMon.abilityNum = GetMonData(&party[monId], MON_DATA_ABILITY_NUM);
        battleMon.metLevel = GetMonData(&party[monId], MON_DATA_MET_LEVEL);
        battleMon.isShiny = GetMonData(&party[monId], MON_DATA_IS_SHINY);
        GetMonData(&party[monId], MON_DATA_NICKNAME, nickname);
        StringCopy_Nickname(battleMon.nickname, nickname);
        GetMonData(&party[monId], MON_DATA_OT_NAME, battleMon.otName);
        memcpy(dst, &battleMon, sizeof(battleMon));
        // Imprescindible: el bucle de movimientos de arriba usa 'size' como contador
        // y la deja valiendo MAXIMO_MOVIMIENTOS_POKEMON. Sin esta linea se transferian
        // solo 4 bytes de los 96 de la estructura, asi que al combatiente le llegaba
        // la especie pero nivel, PS y PS maximos quedaban a cero: se le daba por
        // ausente y el combate se colgaba antes de pedir la primera accion.
        size = sizeof(battleMon);
        break;
    case REQUEST_SPECIES_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPECIES);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_HELDITEM_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_HELD_ITEM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (size = 0; size < MAXIMO_MOVIMIENTOS_POKEMON; size++)
        {
            datosMovimiento.movimiento[size] = GetMonData(&party[monId], MON_DATA_MOVE1 + size);
            datosMovimiento.pp[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        }
        memcpy(dst, &datosMovimiento, sizeof(datosMovimiento));
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_MOVE1 + gArgumentosComando[battler].peticion - REQUEST_MOVE1_BATTLE);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_PP_DATA_BATTLE:
        for (size = 0; size < MAXIMO_MOVIMIENTOS_POKEMON; size++)
            dst[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        size++;
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_PP1 + gArgumentosComando[battler].peticion - REQUEST_PPMOVE1_BATTLE);
        size = 1;
        break;
    case REQUEST_EXP_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_EXP);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_HP_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_HP_EV);
        size = 1;
        break;
    case REQUEST_ATK_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_ATK_EV);
        size = 1;
        break;
    case REQUEST_DEF_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_DEF_EV);
        size = 1;
        break;
    case REQUEST_SPEED_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPEED_EV);
        size = 1;
        break;
    case REQUEST_SPATK_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPATK_EV);
        size = 1;
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPDEF_EV);
        size = 1;
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_FRIENDSHIP);
        size = 1;
        break;
    case REQUEST_POKERUS_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_POKERUS);
        size = 1;
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_MET_LOCATION);
        size = 1;
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_MET_LEVEL);
        size = 1;
        break;
    case REQUEST_POKEBALL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_POKEBALL);
        size = 1;
        break;
    case REQUEST_PERSONALITY_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_PERSONALITY);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_STATUS_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_STATUS);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_LEVEL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_LEVEL);
        size = 1;
        break;
    case REQUEST_HP_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MAX_HP_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_MAX_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_ATK_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_ATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_DEF_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_DEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPEED_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPEED);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPATK_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPDEF_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPDEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_COOL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_COOL);
        size = 1;
        break;
    case REQUEST_BEAUTY_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_BEAUTY);
        size = 1;
        break;
    case REQUEST_CUTE_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_CUTE);
        size = 1;
        break;
    case REQUEST_SMART_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SMART);
        size = 1;
        break;
    case REQUEST_TOUGH_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_TOUGH);
        size = 1;
        break;
    case REQUEST_SHEEN_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SHEEN);
        size = 1;
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_COOL_RIBBON);
        size = 1;
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_BEAUTY_RIBBON);
        size = 1;
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_CUTE_RIBBON);
        size = 1;
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SMART_RIBBON);
        size = 1;
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_TOUGH_RIBBON);
        size = 1;
        break;
    }

    return size;
}

static void SetBattlerMonData(u32 battler, struct Pokemon *party, u32 monId)
{
    struct BattlePokemon *battlePokemon = (struct BattlePokemon *)gArgumentosComando[battler].datos;
    struct DatosMovimiento *datosMovimiento = (struct DatosMovimiento *)gArgumentosComando[battler].datos;
    s32 i;

    switch (gArgumentosComando[battler].peticion)
    {
    case REQUEST_ALL_BATTLE:
        {
            SetMonData(&party[monId], MON_DATA_SPECIES, &battlePokemon->species);
            SetMonData(&party[monId], MON_DATA_HELD_ITEM, &battlePokemon->item);
            for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
            {
                SetMonData(&party[monId], MON_DATA_MOVE1 + i, &battlePokemon->movimientos[i]);
                SetMonData(&party[monId], MON_DATA_PP1 + i, &battlePokemon->pp[i]);
            }
            SetMonData(&party[monId], MON_DATA_FRIENDSHIP, &battlePokemon->friendship);
            SetMonData(&party[monId], MON_DATA_EXP, &battlePokemon->experience);
            SetMonData(&party[monId], MON_DATA_PERSONALITY, &battlePokemon->personality);
            SetMonData(&party[monId], MON_DATA_STATUS, &battlePokemon->status1);
            SetMonData(&party[monId], MON_DATA_LEVEL, &battlePokemon->level);
            SetMonData(&party[monId], MON_DATA_HP, &battlePokemon->hp);
            SetMonData(&party[monId], MON_DATA_MAX_HP, &battlePokemon->maxHP);
            SetMonData(&party[monId], MON_DATA_ATK, &battlePokemon->attack);
            SetMonData(&party[monId], MON_DATA_DEF, &battlePokemon->defense);
            SetMonData(&party[monId], MON_DATA_SPEED, &battlePokemon->speed);
            SetMonData(&party[monId], MON_DATA_SPATK, &battlePokemon->spAttack);
            SetMonData(&party[monId], MON_DATA_SPDEF, &battlePokemon->spDefense);
        }
        break;
    case REQUEST_SPECIES_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPECIES, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_HELDITEM_BATTLE:
        SetMonData(&party[monId], MON_DATA_HELD_ITEM, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (i = 0; i < MAXIMO_MOVIMIENTOS_POKEMON; i++)
        {
            SetMonData(&party[monId], MON_DATA_MOVE1 + i, &datosMovimiento->movimiento[i]);
            SetMonData(&party[monId], MON_DATA_PP1 + i, &datosMovimiento->pp[i]);
        }
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        SetMonData(&party[monId], MON_DATA_MOVE1 + gArgumentosComando[battler].peticion - REQUEST_MOVE1_BATTLE, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_PP_DATA_BATTLE:
        SetMonData(&party[monId], MON_DATA_PP1, &gArgumentosComando[battler].datos[0]);
        SetMonData(&party[monId], MON_DATA_PP2, &gArgumentosComando[battler].datos[1]);
        SetMonData(&party[monId], MON_DATA_PP3, &gArgumentosComando[battler].datos[2]);
        SetMonData(&party[monId], MON_DATA_PP4, &gArgumentosComando[battler].datos[3]);
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        SetMonData(&party[monId], MON_DATA_PP1 + gArgumentosComando[battler].peticion - REQUEST_PPMOVE1_BATTLE, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_EXP_BATTLE:
        SetMonData(&party[monId], MON_DATA_EXP, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_HP_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_ATK_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_ATK_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_DEF_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_DEF_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPEED_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPEED_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPATK_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPATK_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPDEF_EV, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        SetMonData(&party[monId], MON_DATA_FRIENDSHIP, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_POKERUS_BATTLE:
        SetMonData(&party[monId], MON_DATA_POKERUS, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        SetMonData(&party[monId], MON_DATA_MET_LOCATION, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        SetMonData(&party[monId], MON_DATA_MET_LEVEL, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_POKEBALL_BATTLE:
        SetMonData(&party[monId], MON_DATA_POKEBALL, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_PERSONALITY_BATTLE:
        SetMonData(&party[monId], MON_DATA_PERSONALITY, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_STATUS_BATTLE:
        SetMonData(&party[monId], MON_DATA_STATUS, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_LEVEL_BATTLE:
        SetMonData(&party[monId], MON_DATA_LEVEL, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_HP_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_MAX_HP_BATTLE:
        SetMonData(&party[monId], MON_DATA_MAX_HP, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_ATK_BATTLE:
        SetMonData(&party[monId], MON_DATA_ATK, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_DEF_BATTLE:
        SetMonData(&party[monId], MON_DATA_DEF, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPEED_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPEED, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPATK_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPATK, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SPDEF_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPDEF, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_COOL_BATTLE:
        SetMonData(&party[monId], MON_DATA_COOL, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_BEAUTY_BATTLE:
        SetMonData(&party[monId], MON_DATA_BEAUTY, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_CUTE_BATTLE:
        SetMonData(&party[monId], MON_DATA_CUTE, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SMART_BATTLE:
        SetMonData(&party[monId], MON_DATA_SMART, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_TOUGH_BATTLE:
        SetMonData(&party[monId], MON_DATA_TOUGH, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SHEEN_BATTLE:
        SetMonData(&party[monId], MON_DATA_SHEEN, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_COOL_RIBBON, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_BEAUTY_RIBBON, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_CUTE_RIBBON, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_SMART_RIBBON, &gArgumentosComando[battler].datos[0]);
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_TOUGH_RIBBON, &gArgumentosComando[battler].datos[0]);
        break;
    }

    if (GetBattlerSide(battler) == LADO_JUGADOR)
        HandleLowHpMusicChange(&party[gBattlerPartyIndexes[battler]], battler);
}

// In normal singles, if follower pokemon is out, have it slide in instead of being thrown
static bool8 ShouldDoSlideInAnim(void)
{
    struct ObjectEvent *followerObj = GetFollowerObject();
    if (!followerObj || followerObj->invisible)
        return FALSE;
    if (EsCombateContraEntrenador(gCombate->tipoCombate))
        return FALSE;
    return TRUE;
}

void StartSendOutAnim(u32 battler, bool32 dontClearSubstituteBit, bool32 doSlideIn)
{
    LOG("ENVIO 4) StartSendOutAnim battler", battler, 0);
    u16 species;
    u32 side = GetBattlerSide(battler);
    struct Pokemon *party = GetBattlerParty(battler);

    ClearTemporarySpeciesSpriteData(battler, dontClearSubstituteBit);
    gBattlerPartyIndexes[battler] = gArgumentosComando[battler].indiceEquipo;
    species = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
    gBattleControllerData[battler] = CreateInvisibleSpriteWithCallback(SpriteCB_WaitForBattlerBallReleaseAnim);
    // Load sprite for opponent only, player sprite is expected to be already loaded.
    if (side == LADO_OPONENTE)
        BattleLoadMonSpriteGfx(&party[gBattlerPartyIndexes[battler]], battler);
    SetMultiuseSpriteTemplateToPokemon(species, battler);

    gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                        GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2),
                                        GetBattlerSpriteDefault_Y(battler),
                                        GetBattlerSpriteSubpriority(battler));

    gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
    gSprites[gBattlerSpriteIds[battler]].data[2] = species;
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
    gSprites[gBattlerSpriteIds[battler]].invisible = TRUE;
    gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;

    gSprites[gBattleControllerData[battler]].data[1] = gBattlerSpriteIds[battler];
    gSprites[gBattleControllerData[battler]].data[2] = battler;
    gSprites[gBattleControllerData[battler]].data[0] = DoPokeballSendOutAnimation(battler, 0, (side == LADO_OPONENTE) ? POKEBALL_OPPONENT_SENDOUT : (doSlideIn ? POKEBALL_PLAYER_SLIDEIN : POKEBALL_PLAYER_SENDOUT));
}

static void FreeMonSprite(u32 battler)
{
    FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[battler]]);
    DestroySprite(&gSprites[gBattlerSpriteIds[battler]]);
    if (GetBattlerSide(battler) == LADO_OPONENTE)
        HideBattlerShadowSprite(battler);
    OcultaMarcador(gMarcadorSpriteIds[battler]);
}

static void Controller_ReturnMonToBall2(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
    {
        FreeMonSprite(battler);
        BattleControllerComplete(battler);
    }
}

static void Controller_ReturnMonToBall(u32 battler)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[battler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            InitAndLaunchSpecialAnimation(battler, battler, battler, (GetBattlerSide(battler) == LADO_OPONENTE) ? B_ANIM_SWITCH_OUT_OPPONENT_MON : B_ANIM_SWITCH_OUT_PLAYER_MON);
            gBattlerControllerFuncs[battler] = Controller_ReturnMonToBall2;
        }
        break;
    }
}

static void Controller_FaintPlayerMon(u32 battler)
{
    u32 spriteId = gBattlerSpriteIds[battler];
    if (gSprites[spriteId].y + gSprites[spriteId].y2 > ALTURA_PANTALLA)
    {
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        OcultaMarcador(gMarcadorSpriteIds[battler]);
        BattleControllerComplete(battler);
    }
}

static void Controller_FaintOpponentMon(u32 battler)
{
    if (!gSprites[gBattlerSpriteIds[battler]].inUse)
    {
        OcultaMarcador(gMarcadorSpriteIds[battler]);
        BattleControllerComplete(battler);
    }
}

static void Controller_DoMoveAnimation(u32 battler)
{
    u16 move = gArgumentosComando[battler].movimiento;

    switch (gBattleSpritesDataPtr->healthBoxesData[battler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute
            && !gBattleSpritesDataPtr->battlerData[battler].flag_x8)
        {
            gBattleSpritesDataPtr->battlerData[battler].flag_x8 = 1;
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_OFF);
            DoMoveAnim(move);
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 2;
        }
        break;
    case 2:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            u8 multihit = gArgumentosComando[battler].golpesMultiples;

            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_NORMAL);
            if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute && multihit < 2)
            {
                InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->battlerData[battler].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            CopyAllBattleSpritesInvisibilities();
            TrySetBehindSubstituteSpriteBit(battler, gArgumentosComando[battler].movimiento);
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            BattleControllerComplete(battler);
        }
        break;
    }
}

static void Controller_HandleTrainerSlideBack(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (GetBattlerSide(battler) == LADO_OPONENTE)
            FreeTrainerFrontPicPalette(gSprites[gBattlerSpriteIds[battler]].oam.affineParam);
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[battler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[battler]]);
        BattleControllerComplete(battler);
    }
}

void Controller_WaitForHealthBar(u32 battler)
{
    s16 hpValue = MoveBattleBar(battler, gMarcadorSpriteIds[battler]);

    MuestraMarcador(gMarcadorSpriteIds[battler]);
    if (hpValue != -1)
    {
    }
    else
    {
        if (GetBattlerSide(battler) == LADO_JUGADOR)
            HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        BattleControllerComplete(battler);
    }
}

static void Controller_WaitForBallThrow(u32 battler)
{
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        BattleControllerComplete(battler);
}

static void Controller_WaitForBattleAnimation(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].animFromTableActive)
        BattleControllerComplete(battler);
}

static void Controller_WaitForStatusAnimation(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive)
        BattleControllerComplete(battler);
}

static void Controller_WaitForTrainerPic(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        BattleControllerComplete(battler);
}

void Controller_WaitForString(u32 battler)
{
    if (!IsTextPrinterActive(B_WIN_MSG))
        BattleControllerComplete(battler);
}


static void Controller_HitAnimation(u32 battler)
{
    u32 spriteId = gBattlerSpriteIds[battler];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = FALSE;
        gDoingBattleAnim = FALSE;
        BattleControllerComplete(battler);
    }
    else
    {
        if ((gSprites[spriteId].data[1] % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data[1]++;
    }
}

// Used for all the commands which do nothing.
void BtlController_Empty(u32 battler)
{
    BattleControllerComplete(battler);
}

// Dummy function at the end of the table.
void BtlController_TerminatorNop(u32 battler)
{
}

void BattleControllerDummy(u32 battler)
{
}

// Handlers of the controller commands
void BtlController_HandleGetMonData(u32 battler)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    struct Pokemon *party = GetBattlerParty(battler);
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gArgumentosComando[battler].pokemon == 0)
    {
        size += GetBattlerMonData(battler, party, gBattlerPartyIndexes[battler], monData);
    }
    else
    {
        monToCheck = gArgumentosComando[battler].pokemon;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (monToCheck & 1)
                size += GetBattlerMonData(battler, party, i, monData + size);
            monToCheck >>= 1;
        }
    }
    RespondeDatos(battler, size, monData);
    BattleControllerComplete(battler);
}


void BtlController_HandleSetMonData(u32 battler)
{
    struct Pokemon *party = GetBattlerParty(battler);
    u32 i, monToCheck;

    if (gArgumentosComando[battler].pokemon == 0)
    {
        SetBattlerMonData(battler, party, gBattlerPartyIndexes[battler]);
    }
    else
    {
        monToCheck = gArgumentosComando[battler].pokemon;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (monToCheck & 1)
                SetBattlerMonData(battler, party, i);
            monToCheck >>= 1;
        }
    }
    BattleControllerComplete(battler);
}


void BtlController_HandleLoadMonSprite(u32 battler, void (*controllerCallback)(u32 battler))
{
    struct Pokemon *party = GetBattlerParty(battler);
    u16 species = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

    BattleLoadMonSpriteGfx(&party[gBattlerPartyIndexes[battler]], battler);
    SetMultiuseSpriteTemplateToPokemon(species, battler);

    gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                               GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2),
                                               GetBattlerSpriteDefault_Y(battler),
                                               GetBattlerSpriteSubpriority(battler));

    gSprites[gBattlerSpriteIds[battler]].x2 = -ANCHO_PANTALLA;
    gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
    gSprites[gBattlerSpriteIds[battler]].data[2] = species;
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);

    SetBattlerShadowSpriteCallback(battler, species);

    gBattlerControllerFuncs[battler] = controllerCallback;
}

void BtlController_HandleSwitchInAnim(u32 battler, bool32 isPlayerSide, void (*controllerCallback)(u32 battler))
{
    if (isPlayerSide)
        ClearTemporarySpeciesSpriteData(battler, gArgumentosComando[battler].noLimpiarSustituto);
    gBattlerPartyIndexes[battler] = gArgumentosComando[battler].indiceEquipo;
    if (isPlayerSide)
        BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
    StartSendOutAnim(battler, gArgumentosComando[battler].noLimpiarSustituto, FALSE);
    gBattlerControllerFuncs[battler] = controllerCallback;
}

void BtlController_HandleReturnMonToBall(u32 battler)
{
    if (gArgumentosComando[battler].saltarAnimacion == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
        gBattlerControllerFuncs[battler] = Controller_ReturnMonToBall;
    }
    else
    {
        FreeMonSprite(battler);
        BattleControllerComplete(battler);
    }
}

// In emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven)
// that use an animated back pic.

#define sSpeedX data[0]

void BtlController_HandleDrawTrainerPic(u32 battler, u32 trainerPicId, bool32 isFrontPic, s16 xPos, s16 yPos, s32 subpriority)
{
    if (GetBattlerSide(battler) == LADO_OPONENTE) // Always the front sprite for the opponent.
    {
        DecompressTrainerFrontPic(trainerPicId, battler);
        SetMultiuseSpriteTemplateToTrainer(trainerPicId, battler);
        if (subpriority == -1)
            subpriority = GetBattlerSpriteSubpriority(battler);
        gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                   xPos,
                                                   yPos,
                                                   subpriority);

        gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerSprites[trainerPicId].palette.tag);
        gSprites[gBattlerSpriteIds[battler]].x2 = -ANCHO_PANTALLA;
        gSprites[gBattlerSpriteIds[battler]].sSpeedX = 2;
        gSprites[gBattlerSpriteIds[battler]].oam.affineParam = trainerPicId;
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 1);
    }
    else // Player's side
    {
        if (isFrontPic)
        {
            DecompressTrainerFrontPic(trainerPicId, battler);
            SetMultiuseSpriteTemplateToTrainer(trainerPicId, battler);
            if (subpriority == -1)
                subpriority = GetBattlerSpriteSubpriority(battler);
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                             xPos,
                                                             yPos,
                                                             subpriority);

            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerSprites[trainerPicId].palette.tag);
            gSprites[gBattlerSpriteIds[battler]].oam.affineMode = ST_OAM_AFFINE_OFF;
            gSprites[gBattlerSpriteIds[battler]].hFlip = 1;
            gSprites[gBattlerSpriteIds[battler]].y2 = 48;
        }
        else
        {
            DecompressTrainerBackPic(trainerPicId, battler);
            SetMultiuseSpriteTemplateToTrainer(trainerPicId, battler);
            if (subpriority == -1)
                subpriority = GetBattlerSpriteSubpriority(battler);
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                             xPos,
                                                             yPos,
                                                             subpriority);

            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
        }
        gSprites[gBattlerSpriteIds[battler]].x2 = ANCHO_PANTALLA;
        gSprites[gBattlerSpriteIds[battler]].sSpeedX = -2;
    }
    gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_TrainerSlideIn;

    gBattlerControllerFuncs[battler] = Controller_WaitForTrainerPic;
}

void BtlController_HandleTrainerSlide(u32 battler, u32 trainerPicId)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR)
    {
        DecompressTrainerBackPic(trainerPicId, battler);
        SetMultiuseSpriteTemplateToTrainer(trainerPicId, battler);
        gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                         80,
                                                         (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80,
                                                         30);
        gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
        gSprites[gBattlerSpriteIds[battler]].x2 = -96;
        gSprites[gBattlerSpriteIds[battler]].sSpeedX = 2;
    }
    else
    {
        DecompressTrainerFrontPic(trainerPicId, battler);
        SetMultiuseSpriteTemplateToTrainer(trainerPicId, battler);
        gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 176, 40, 30);
        gSprites[gBattlerSpriteIds[battler]].oam.affineParam = trainerPicId;
        gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerSprites[trainerPicId].palette.tag);
        gSprites[gBattlerSpriteIds[battler]].x2 = 96;
        gSprites[gBattlerSpriteIds[battler]].x += 32;
        gSprites[gBattlerSpriteIds[battler]].sSpeedX = -2;
    }
    gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_TrainerSlideIn;

    gBattlerControllerFuncs[battler] = Controller_WaitForTrainerPic;
}

#undef sSpeedX

void BtlController_HandleTrainerSlideBack(u32 battler, s16 data0, bool32 startAnim)
{
    u32 side = GetBattlerSide(battler);

    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattlerSpriteIds[battler]]);
    gSprites[gBattlerSpriteIds[battler]].data[0] = data0;
    gSprites[gBattlerSpriteIds[battler]].data[2] = (side == LADO_JUGADOR) ? -40 : 280;
    gSprites[gBattlerSpriteIds[battler]].data[4] = gSprites[gBattlerSpriteIds[battler]].y;
    gSprites[gBattlerSpriteIds[battler]].callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[battler]], SpriteCallbackDummy);
    if (startAnim)
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 1);
    gBattlerControllerFuncs[battler] = Controller_HandleTrainerSlideBack;
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void BtlController_HandleFaintAnimation(u32 battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].animationState == 0)
    {
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            if (GetBattlerSide(battler) == LADO_JUGADOR)
            {
                HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
                gSprites[gBattlerSpriteIds[battler]].sSpeedX = 0;
                gSprites[gBattlerSpriteIds[battler]].sSpeedY = 5;
                PlaySE12WithPanning(SE_FAINT, SOUND_PAN_ATTACKER);
                gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_FaintSlideAnim;
                gBattlerControllerFuncs[battler] = Controller_FaintPlayerMon;
            }
            else
            {
                PlaySE12WithPanning(SE_FAINT, SOUND_PAN_TARGET);
                gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_FaintOpponentMon;
                gBattlerControllerFuncs[battler] = Controller_FaintOpponentMon;
            }
            // The player's sprite callback just slides the mon, the opponent's removes the sprite.
            // The player's sprite is removed in Controller_FaintPlayerMon. Controller_FaintOpponentMon only removes the healthbox once the sprite is removed by SpriteCB_FaintOpponentMon.
        }
    }
}

#undef sSpeedX
#undef sSpeedY

static void HandleBallThrow(u32 battler, u32 target, u32 animId)
{
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(battler, battler, target, animId);

    gBattlerControllerFuncs[battler] = Controller_WaitForBallThrow;
}

void BtlController_HandleSuccessBallThrowAnim(u32 battler, u32 target, u32 animId)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    HandleBallThrow(battler, target, animId);
}

void BtlController_HandleBallThrowAnim(u32 battler, u32 target, u32 animId)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = gArgumentosComando[battler].caso;
    HandleBallThrow(battler, target, animId);
}

void BtlController_HandleMoveAnimation(u32 battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        gAnimMoveTurn = gArgumentosComando[battler].turnoDelMovimiento;
        gAnimMovePower = gArgumentosComando[battler].potencia;
        gAnimMoveDmg = gArgumentosComando[battler].dano;
        gAnimFriendship = gArgumentosComando[battler].amistad;
        gWeatherMoveAnim = gArgumentosComando[battler].clima;
        gAnimDisableStructPtr = &gArgumentosComando[battler].estadoDeshabilitado;
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
        gBattlerControllerFuncs[battler] = Controller_DoMoveAnimation;
    }
}

void BtlController_HandleHealthBarUpdate(u32 battler)
{
    s32 maxHP, curHP;
    s16 hpVal;
    struct Pokemon *party = GetBattlerParty(battler);

    hpVal = gArgumentosComando[battler].valorPS;
    maxHP = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_MAX_HP);
    curHP = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_HP);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        SetBattleBarStruct(battler, gMarcadorSpriteIds[battler], maxHP, curHP, hpVal);
    }
    else
    {
        SetBattleBarStruct(battler, gMarcadorSpriteIds[battler], maxHP, 0, hpVal);
    }

    gBattlerControllerFuncs[battler] = Controller_WaitForHealthBar;
}

void DoStatusIconUpdate(u32 battler)
{
    struct Pokemon *party = GetBattlerParty(battler);

    ActualizaMarcador(gMarcadorSpriteIds[battler], &party[gBattlerPartyIndexes[battler]], MARCADOR_ESTADO);
    gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
    gBattlerControllerFuncs[battler] = Controller_WaitForStatusAnimation;
}

void BtlController_HandleStatusIconUpdate(u32 battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        DoStatusIconUpdate(battler);
    }
}

void BtlController_HandleStatusAnimation(u32 battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        InitAndLaunchChosenStatusAnimation(battler, gArgumentosComando[battler].esEstado2, gArgumentosComando[battler].estado1);
        gBattlerControllerFuncs[battler] = Controller_WaitForStatusAnimation;
    }
}

void BtlController_HandleHitAnimation(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].invisible == TRUE)
    {
        BattleControllerComplete(battler);
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBattlerSpriteIds[battler]].data[1] = 0;
        DoHitAnimHealthboxEffect(battler);
        gBattlerControllerFuncs[battler] = Controller_HitAnimation;
    }
}

void BtlController_HandlePlaySE(u32 battler)
{
    s8 pan = (GetBattlerSide(battler) == LADO_JUGADOR) ? SOUND_PAN_ATTACKER : SOUND_PAN_TARGET;

    PlaySE12WithPanning(gArgumentosComando[battler].cancion, pan);
    BattleControllerComplete(battler);
}

void BtlController_HandlePlayFanfareOrBGM(u32 battler)
{
    if (gArgumentosComando[battler].esMusica)
    {
        BattleStopLowHpSound();
        PlayBGM(gArgumentosComando[battler].cancion);
    }
    else
    {
        PlayFanfare(gArgumentosComando[battler].cancion);
    }

    BattleControllerComplete(battler);
}

void BtlController_HandleFaintingCry(u32 battler)
{
    struct Pokemon *party;
    s8 pan;

    if (GetBattlerSide(battler) == LADO_JUGADOR)
    {
        party = gPlayerParty;
        pan = -25;
    }
    else
    {
        party = gEnemyParty;
        pan = 25;
    }

    PlayCry_ByMode(GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), pan, CRY_MODE_FAINT);
    BattleControllerComplete(battler);
}

void BtlController_HandleIntroSlide(u32 battler)
{
    HandleIntroSlide(gArgumentosComando[battler].terreno);
    gIntroSlideFlags |= 1;
    BattleControllerComplete(battler);
}

void BtlController_HandleSpriteInvisibility(u32 battler)
{
    if (IsBattlerSpritePresent(battler))
    {
        gSprites[gBattlerSpriteIds[battler]].invisible = gArgumentosComando[battler].invisible;
        CopyBattleSpriteInvisibility(battler);
    }
    BattleControllerComplete(battler);
}

bool32 TwoPlayerIntroMons(u32 battler) // Double battle with both player pokemon active.
{
    return (EsCombateContraEntrenador(gCombate->tipoCombate) && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[battler ^ BIT_FLANK]]));
}

bool32 TwoOpponentIntroMons(u32 battler) // Double battle with both opponent pokemon active.
{
    return (EsCombateContraEntrenador(gCombate->tipoCombate)
            && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[battler]])
            && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[ALIADO(battler)]]));
}

// Task data for Task_StartSendOutAnim
#define tBattlerId          data[0]
#define tStartTimer         data[1]
#define tFramesToWait       data[2]
#define tControllerFunc_1   3 // Stored as two halfwords
#define tControllerFunc_2   4

// Sprite data for SpriteCB_FreePlayerSpriteLoadMonSprite
#define sBattlerId data[5]

void BtlController_HandleIntroTrainerBallThrow(u32 battler, u16 tagTrainerPal, const u32 *trainerPal, s16 framesToWait, void (*controllerCallback)(u32 battler))
{
    LOG("ENVIO 1) BallThrow battler/espera", battler, framesToWait);
    u8 paletteNum, taskId;
    u32 side = GetBattlerSide(battler);

    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattlerSpriteIds[battler]]);
    if (side == LADO_JUGADOR)
    {
        gSprites[gBattlerSpriteIds[battler]].data[0] = 50;
        gSprites[gBattlerSpriteIds[battler]].data[2] = -40;
    }
    else
    {
        gSprites[gBattlerSpriteIds[battler]].data[0] = 35;
        gSprites[gBattlerSpriteIds[battler]].data[2] = 280;
    }

    gSprites[gBattlerSpriteIds[battler]].data[4] = gSprites[gBattlerSpriteIds[battler]].y;
    gSprites[gBattlerSpriteIds[battler]].callback = StartAnimLinearTranslation;
    gSprites[gBattlerSpriteIds[battler]].sBattlerId = battler;

    if (side == LADO_JUGADOR)
    {
        StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[battler]], SpriteCB_FreePlayerSpriteLoadMonSprite);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], ShouldDoSlideInAnim() ? 2 : 1);

        // AllocSpritePalette devuelve 0xFF si no quedan slots. Sin comprobarlo,
        // OBJ_PLTT_ID(0xFF) apunta miles de entradas fuera del buffer de paletas y
        // LoadCompressedPalette corrompe EWRAM; ademas oam.paletteNum solo tiene
        // 4 bits, con lo que 0xFF se truncaba a la paleta 15 (el sprite en negro).
        paletteNum = AllocSpritePalette(tagTrainerPal);
        if (paletteNum != 0xFF)
        {
            LoadCompressedPalette(trainerPal, OBJ_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = paletteNum;

            // Para la animacion de lanzamiento el entrenador se muda a una ranura
            // pedida sobre la marcha, con la paleta recien descomprimida. Ahi se
            // quedaba sin la luz de la hora: empezaba tenido en la ranura del
            // combatiente y la perdia al mudarse.
            TinePaletaSueltaDeCombate(16 + paletteNum);
        }
        else
        {
            LOG("SIN SLOTS DE PALETA en intro, battler", battler, 0);
        }
    }
    else
    {
        StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[battler]], SpriteCB_FreeOpponentSprite);
    }

    taskId = CreateTask(Task_StartSendOutAnim, 5);
    LOG("ENVIO 2) tarea creada id", taskId, battler);
    gTasks[taskId].tBattlerId = battler;
    gTasks[taskId].tFramesToWait = framesToWait;
    SetWordTaskArg(taskId, tControllerFunc_1, (uint32_t)(controllerCallback));

    gBattleSpritesDataPtr->animationData->introAnimActive = TRUE;
    gBattlerControllerFuncs[battler] = BattleControllerDummy;
}

static bool32 TwoMonsAtSendOut(u32 battler)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR)
    {
        if (TwoPlayerIntroMons(battler))
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        if ((!TwoOpponentIntroMons(battler)))
            return FALSE;
        else
            return TRUE;
    }
    return FALSE;
}

// Send out at start of battle
static void Task_StartSendOutAnim(u8 taskId)
{
    if (gTasks[taskId].tFramesToWait != 0 && gTasks[taskId].tStartTimer < gTasks[taskId].tFramesToWait)
    {
        gTasks[taskId].tStartTimer++;
    }
    else
    {
        u32 battlerPartner;
        u32 battler = gTasks[taskId].tBattlerId;

        LOG("ENVIO 3) tarea dispara battler", battler, 0);

        if (TwoMonsAtSendOut(battler))
        {
            gArgumentosComando[battler].indiceEquipo = gBattlerPartyIndexes[battler];
            StartSendOutAnim(battler, FALSE, ShouldDoSlideInAnim());

            battlerPartner = battler ^ BIT_FLANK;
            gArgumentosComando[battlerPartner].indiceEquipo = gBattlerPartyIndexes[battlerPartner];
            BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battlerPartner]], battlerPartner);
            StartSendOutAnim(battlerPartner, FALSE, ShouldDoSlideInAnim());
        }
        else
        {
            gArgumentosComando[battler].indiceEquipo = gBattlerPartyIndexes[battler];
            StartSendOutAnim(battler, FALSE, ShouldDoSlideInAnim());
        }
        gBattlerControllerFuncs[battler] = (void*)(GetWordTaskArg(taskId, tControllerFunc_1));
        DestroyTask(taskId);
    }
}

#undef tBattlerId
#undef tStartTimer
#undef tFramesToWait
#undef tControllerFunc_1
#undef tControllerFunc_2

static void SpriteCB_FreePlayerSpriteLoadMonSprite(struct Sprite *sprite)
{
    u8 battler = sprite->sBattlerId;

    // Free player trainer sprite
    FreeSpriteOamMatrix(sprite);
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));
    DestroySprite(sprite);

    // Load mon sprite
    BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
}

static void SpriteCB_FreeOpponentSprite(struct Sprite *sprite)
{
    FreeTrainerFrontPicPalette(sprite->oam.affineParam);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

#undef sBattlerId

// El resumen de bolas ya no existe: todos los entrenadores llevan seis Pokemon,
// asi que no informaba de nada. Las ordenes se conservan hasta que se simplifiquen
// los controladores, pero no dibujan nada.
void BtlController_HandleDrawPartyStatusSummary(u32 battler, u32 side, bool32 considerDelay)
{
    BattleControllerComplete(battler);
}

void BtlController_HandleHidePartyStatusSummary(u32 battler)
{
    BattleControllerComplete(battler);
}

void BtlController_HandleBattleAnimation(u32 battler, bool32 ignoreSE)
{
    if (ignoreSE || !IsBattleSEPlaying(battler))
    {
        u8 animationId = gArgumentosComando[battler].animacion;
        u16 argument = gArgumentosComando[battler].argumentoAnimacion;

        gAnimDisableStructPtr = &gArgumentosComando[battler].estadoDeshabilitado;

        if (TryHandleLaunchBattleTableAnimation(battler, battler, battler, animationId, argument))
            BattleControllerComplete(battler);
        else
            gBattlerControllerFuncs[battler] = Controller_WaitForBattleAnimation;
    }
}

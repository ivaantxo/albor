#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

enum {
    REQUEST_ALL_BATTLE,
    REQUEST_SPECIES_BATTLE,
    REQUEST_HELDITEM_BATTLE,
    REQUEST_MOVES_PP_BATTLE,
    REQUEST_MOVE1_BATTLE,
    REQUEST_MOVE2_BATTLE,
    REQUEST_MOVE3_BATTLE,
    REQUEST_MOVE4_BATTLE,
    REQUEST_PP_DATA_BATTLE,
    REQUEST_PPMOVE1_BATTLE,
    REQUEST_PPMOVE2_BATTLE,
    REQUEST_PPMOVE3_BATTLE,
    REQUEST_PPMOVE4_BATTLE,
    REQUEST_EXP_BATTLE,
    REQUEST_HP_EV_BATTLE,
    REQUEST_ATK_EV_BATTLE,
    REQUEST_DEF_EV_BATTLE,
    REQUEST_SPEED_EV_BATTLE,
    REQUEST_SPATK_EV_BATTLE,
    REQUEST_SPDEF_EV_BATTLE,
    REQUEST_FRIENDSHIP_BATTLE,
    REQUEST_POKERUS_BATTLE,
    REQUEST_MET_LOCATION_BATTLE,
    REQUEST_MET_LEVEL_BATTLE,
    REQUEST_POKEBALL_BATTLE,
    REQUEST_PERSONALITY_BATTLE,
    REQUEST_STATUS_BATTLE,
    REQUEST_LEVEL_BATTLE,
    REQUEST_HP_BATTLE,
    REQUEST_MAX_HP_BATTLE,
    REQUEST_ATK_BATTLE,
    REQUEST_DEF_BATTLE,
    REQUEST_SPEED_BATTLE,
    REQUEST_SPATK_BATTLE,
    REQUEST_SPDEF_BATTLE,
    REQUEST_COOL_BATTLE,
    REQUEST_BEAUTY_BATTLE,
    REQUEST_CUTE_BATTLE,
    REQUEST_SMART_BATTLE,
    REQUEST_TOUGH_BATTLE,
    REQUEST_SHEEN_BATTLE,
    REQUEST_COOL_RIBBON_BATTLE,
    REQUEST_BEAUTY_RIBBON_BATTLE,
    REQUEST_CUTE_RIBBON_BATTLE,
    REQUEST_SMART_RIBBON_BATTLE,
    REQUEST_TOUGH_RIBBON_BATTLE,
};

// Special arguments for Battle Controller functions.

enum { // Values given to the emit functions to choose gBattleBufferA or gBattleBufferB
    BUFFER_A,
    BUFFER_B
};

enum {
    RESET_ACTION_MOVE_SELECTION,
    RESET_ACTION_SELECTION,
    RESET_MOVE_SELECTION,
};

enum {
    BALL_NO_SHAKES,
    BALL_1_SHAKE,
    BALL_2_SHAKES,
    BALL_3_SHAKES_FAIL,
    BALL_3_SHAKES_SUCCESS,
    BALL_TRAINER_BLOCK,
};

#define INSTANT_HP_BAR_DROP     0x7FFF

#define PARTY_SUMM_SKIP_DRAW_DELAY (1 << 7)

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

struct DatosMovimiento
{
    enum Movimientos movimiento[MAXIMO_MOVIMIENTOS_POKEMON];
    u16 pp[MAXIMO_MOVIMIENTOS_POKEMON];
};

// Argumentos del comando que cada combatiente tiene en curso.
//
// Sustituye a bufferA, que eran 512 bytes por combatiente donde los argumentos se
// empaquetaban byte a byte para que el manejador los desempaquetara dos lineas
// despues. Ese empaquetado existia para mandarlos por el cable de enlace; sin
// enlace, era serializar para uno mismo.
//
// El comando dura varios fotogramas y se reentra en cada uno, asi que sus
// argumentos tienen que sobrevivir entre fotogramas: de ahi que sean un dato por
// combatiente y no parametros de funcion.
struct ArgumentosComando
{
    // Datos del Pokemon
    u8 peticion;
    u8 pokemon;
    u8 bytes;

    // La carga se COPIA, no se apunta. El comando dura varios fotogramas y el
    // manejador lee esto mas tarde: guardar un puntero funcionaria mientras
    // apuntase a un global, pero con la direccion de una variable local se estaria
    // leyendo pila ya muerta. El sistema viejo tambien copiaba.
    u8 datos[sizeof(struct BattlePokemon)];

    // Sprites y animaciones
    u8 indiceEquipo;
    bool8 noLimpiarSustituto;
    bool8 saltarAnimacion;
    bool8 invisible;
    u8 caso;
    u8 terreno;
    u8 animacion;
    u16 argumentoAnimacion;

    // Movimiento
    enum Movimientos movimiento;
    u8 turnoDelMovimiento;
    u16 potencia;
    s32 dano;
    u8 amistad;
    u8 golpesMultiples;
    u16 clima;
    struct DisableStruct estadoDeshabilitado;

    // Eleccion del jugador
    u8 accion;
    bool8 esCombateDoble;
    bool8 sinNumeroDePP;
    struct DatosMovimiento datosMovimiento;
    u8 ranura;
    u16 habilidad;
    u8 datosEleccion[3];

    // Marcador, estado y sonido
    u16 valorPS;
    s32 experiencia;
    u32 estado1;
    u32 estado2;
    bool8 esEstado2;
    u16 cancion;
    bool8 esMusica;
    u8 banderas;
    struct HpAndStatus resumenEquipo[PARTY_SIZE];
};

// Lo que el combatiente le contesta al guion de combate. Sustituye a bufferB, con
// el mismo criterio: datos con nombre en vez de bytes sueltos.
struct RespuestaCombatiente
{
    u8 tipo;                // que comando esta contestando
    u8 valor8;              // accion elegida, indice de equipo...
    u8 posicionMovimiento;
    u8 objetivo;
    u32 valor32;
    u8 datos[sizeof(struct BattlePokemon) + 8];
};

extern struct ArgumentosComando gArgumentosComando[NUMERO_COMBATIENTES];
extern struct RespuestaCombatiente gRespuestaCombatiente[NUMERO_COMBATIENTES];
extern u8 gComandoEnCurso[NUMERO_COMBATIENTES];

enum
{
    CONTROLLER_GETMONDATA,
    CONTROLLER_SETMONDATA,
    CONTROLLER_LOADMONSPRITE,
    CONTROLLER_SWITCHINANIM,
    CONTROLLER_RETURNMONTOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_BALLTHROWANIM,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_YESNOBOX,
    CONTROLLER_CHOOSEMOVE,
    CONTROLLER_CHOOSEPOKEMON,
    CONTROLLER_HEALTHBARUPDATE,
    CONTROLLER_EXPUPDATE,
    CONTROLLER_STATUSICONUPDATE,
    CONTROLLER_STATUSANIMATION,
    CONTROLLER_DATATRANSFER,
    CONTROLLER_TWORETURNVALUES,
    CONTROLLER_CHOSENMONRETURNVALUE,
    CONTROLLER_ONERETURNVALUE,
    CONTROLLER_HITANIMATION,
    CONTROLLER_CANTSWITCH,
    CONTROLLER_PLAYSE,
    CONTROLLER_PLAYFANFAREORBGM,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_INTROTRAINERBALLTHROW,
    CONTROLLER_DRAWPARTYSTATUSSUMMARY,
    CONTROLLER_HIDEPARTYSTATUSSUMMARY,
    CONTROLLER_ENDBOUNCE,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_DEBUGMENU,
    /*new controllers should go here*/
    CONTROLLER_TERMINATOR_NOP,
    CONTROLLER_CMDS_COUNT
};

extern void (*gBattlerControllerFuncs[NUMERO_COMBATIENTES])(u32 battler);
extern void (*gBattlerControllerEndFuncs[NUMERO_COMBATIENTES])(u32 battler);
extern u8 gBattleControllerData[NUMERO_COMBATIENTES];

// general functions
void PreparaVarsBatalla(void);
void InitBattleControllers(void);
bool32 IsValidForBattle(struct Pokemon *mon);

// emitters
void ComandoObtenDatosPokemon(u32 combatiente, u8 requestId, u8 monToCheck);
void ComandoFijaDatosPokemon(u32 combatiente, u8 requestId, u8 monToCheck, u8 bytes, void *data);
void ComandoCargaSpritePokemon(u32 combatiente);
void ComandoAnimacionEntrada(u32 combatiente, u8 partyId, bool8 dontClearSubstituteBit);
void ComandoDevuelvePokemonABall(u32 combatiente, bool8 skipAnim);
void ComandoDibujaEntrenador(u32 combatiente);
void ComandoEntrenadorEntra(u32 combatiente);
void ComandoEntrenadorSale(u32 combatiente);
void ComandoAnimacionDebilitado(u32 combatiente);
void ComandoAnimacionLanzarBall(u32 combatiente, u8 caseId);
void ComandoAnimacionMovimiento(u32 combatiente, enum Movimientos movimiento, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit);
void ComandoEligeAccion(u32 combatiente, u8 action);
void ComandoCuadroSiNo(u32 combatiente);
void ComandoEligeMovimiento(u32 combatiente, bool8 isDoubleBattle, bool8 NoPpNumber, struct DatosMovimiento *datosMovimiento);
void ComandoEligePokemon(u32 combatiente, u8 caseId, u8 slotId, u16 abilityId, u8 *data);
void ComandoActualizaBarraSalud(u32 combatiente, u16 hpValue);
void ComandoActualizaExperiencia(u32 combatiente, u8 partyId, s32 expPoints);
void ComandoActualizaIconoEstado(u32 combatiente, u32 status1, u32 status2);
void ComandoAnimacionEstado(u32 combatiente, bool8 status2, u32 status);
void RespondeDatos(u32 combatiente, u16 size, void *data);
void RespondeDosValores(u32 combatiente, u8 ret8, u32 ret32);
void RespondePokemonElegido(u32 combatiente, u8 partyId, u8 *battlePartyOrder);
void RespondeUnValor(u32 combatiente, u16 ret);
void ComandoAnimacionGolpe(u32 combatiente);
void ComandoNoPuedeCambiar(u32 combatiente);
void ComandoSuenaEfecto(u32 combatiente, u16 songId);
void ComandoSuenaFanfarriaOMusica(u32 combatiente, u16 songId, bool8 playBGM);
void ComandoGritoAlDebilitarse(u32 combatiente);
void ComandoEntradaEscenario(u32 combatiente, u8 terrainId);
void ComandoEntrenadorLanzaBall(u32 combatiente);
void ComandoMuestraResumenEquipo(u32 combatiente, struct HpAndStatus* hpAndStatus, u8 flags);
void ComandoOcultaResumenEquipo(u32 combatiente);
void ComandoTerminaBote(u32 combatiente);
void ComandoVisibilidadSprite(u32 combatiente, bool8 isInvisible);
void ComandoAnimacionCombate(u32 combatiente, u8 animationId, struct DisableStruct* disableStructPtr, u16 argument);
void ComandoReiniciaSeleccion(u32 combatiente, u8 caseId);
void ComandoMenuDepuracion(u32 combatiente);

void BattleControllerComplete(u32 battler); // Can be used for all the controllers.
void BtlController_Empty(u32 battler); // Empty command, does nothing, only completes the execution.
void BtlController_TerminatorNop(u32 battler); // Dummy function at the end of the table.
void BattleControllerDummy(u32 battler);
void StartSendOutAnim(u32 battler, bool32 dontClearSubstituteBit, bool32 doSlideIn);
void Controller_WaitForString(u32 battler);
void Controller_WaitForHealthBar(u32 battler);

// handlers
void BtlController_HandleGetMonData(u32 battler);
void BtlController_HandleGetRawMonData(u32 battler);
void BtlController_HandleSetMonData(u32 battler);
void BtlController_HandleSetRawMonData(u32 battler);
void BtlController_HandleLoadMonSprite(u32 battler, void (*controllerCallback)(u32 battler));
void BtlController_HandleSwitchInAnim(u32 battler, bool32 isPlayerSide, void (*controllerCallback)(u32 battler));
void BtlController_HandleReturnMonToBall(u32 battler);
void BtlController_HandleDrawTrainerPic(u32 battlerId, u32 trainerPicId, bool32 isFrontPic, s16 xPos, s16 yPos, s32 subpriority);
void BtlController_HandleTrainerSlide(u32 battler, u32 trainerPicId);
void BtlController_HandleTrainerSlideBack(u32 battlerId, s16 data0, bool32 startAnim);
void BtlController_HandleFaintAnimation(u32 battler);
void BtlController_HandleSuccessBallThrowAnim(u32 battler, u32 target, u32 animId);
void BtlController_HandleBallThrowAnim(u32 battler, u32 target, u32 animId);
void BtlController_HandleMoveAnimation(u32 battler);
void BtlController_HandleHealthBarUpdate(u32 battler);
void SincronizaIconosTipoConPantalla(void);
void DoStatusIconUpdate(u32 battler);
void BtlController_HandleStatusIconUpdate(u32 battler);
void BtlController_HandleStatusAnimation(u32 battler);
void BtlController_HandleHitAnimation(u32 battler);
void BtlController_HandlePlaySE(u32 battler);
void BtlController_HandlePlayFanfareOrBGM(u32 battler);
void BtlController_HandleFaintingCry(u32 battler);
void BtlController_HandleIntroSlide(u32 battler);
void BtlController_HandleSpriteInvisibility(u32 battler);
bool32 TwoPlayerIntroMons(u32 battlerId); // Double battle with both player pokemon active.
bool32 TwoOpponentIntroMons(u32 battlerId); // Double battle with both opponent pokemon active.
void BtlController_HandleIntroTrainerBallThrow(u32 battler, u16 tagTrainerPal, const u32 *trainerPal, s16 framesToWait, void (*controllerCallback)(u32 battler));
void BtlController_HandleDrawPartyStatusSummary(u32 battler, u32 side, bool32 considerDelay);
void BtlController_HandleHidePartyStatusSummary(u32 battler);
void BtlController_HandleBattleAnimation(u32 battler, bool32 ignoreSE);

// player controller
void SetControllerToPlayer(u32 battler);
void PlayerHandleBallThrowAnim(u32 battler);
void PlayerHandleExpUpdate(u32 battler);
void CB2_SetUpReshowBattleScreenAfterMenu(void);
void CB2_SetUpReshowBattleScreenAfterMenu2(void);
void Task_PlayerController_RestoreBgmAfterCry(u8 taskId);
void InitMoveSelectionsVarsAndStrings(u32 battler);
void MoveSelectionCreateCursorAt(u8 cursorPos);
void MoveSelectionDestroyCursor(void);
void MoveSelectionCreateCursorAt(u8 cursorPos);
void MoveSelectionDestroyCursorAt(u8 cursorPosition);
void PlayerHandleChooseMove(u32 battler);
void HandleInputChooseMove(u32 battler);
void HandleInputChooseTarget(u32 battler);
void HandleInputShowEntireFieldTargets(u32 battler);
void HandleInputShowTargets(u32 battler);
void HandleChooseMoveAfterDma3(u32 battler);

// opponent controller
void SetControllerToOpponent(u32 battler);

#endif // GUARD_BATTLE_CONTROLLERS_H

#include "global.h"
#include "laboratorio_animaciones.h"
#include "battle.h"
#include "depuracion_mgba.h"
#include "palette.h"
#include "gpu_regs.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_gfx_sfx_util.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "main.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "constants/battle.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "pokemon.h"
#include "wild_encounter.h"

// Contra quien se prueban las animaciones. Da igual cual sea; lo que importa es
// que EXISTA: sin rival, el combate lee basura al presentarlo y los ataques que
// buscan un objetivo acaban apuntando al propio Pokemon del jugador.
#define ESPECIE_RIVAL  SPECIES_BULBASAUR
#define NIVEL_RIVAL    50

EWRAM_DATA bool8 gLaboratorioAnimaciones = FALSE;

// Se conserva entre visitas: al volver, se sigue donde se dejo.
// EWRAM solo admite inicializacion a cero, asi que el valor de partida se pone al
// entrar. El 0 es MOVE_NONE y no se ensena nunca.
static EWRAM_DATA u16 sMovimientoElegido = 0;

// Cuanto salta el selector con cada control, para poder recorrer cientos de
// movimientos sin desesperarse.
#define SALTO_FINO    1
#define SALTO_MEDIO  10
#define SALTO_GRUESO 50

enum FaseLaboratorio
{
    LAB_ELIGIENDO,
};

static EWRAM_DATA u8 sFase = 0;

// La funcion de cierre que tenia el combatiente antes de que el laboratorio se
// hiciera cargo, para devolverla al salir.
static void (*sCierreOriginal)(u32 combatiente) = NULL;

static void ControladorLaboratorio(u32 combatiente);

void EntraEnLaboratorioAnimaciones(void)
{
    gLaboratorioAnimaciones = TRUE;
    sFase = LAB_ELIGIENDO;
    if (sMovimientoElegido == 0)
        sMovimientoElegido = 1;
    CreateWildMon(ESPECIE_RIVAL, NIVEL_RIVAL);
    DoStandardWildBattle_Debug();
}

// El combate monta los marcadores durante la entrada; aqui no pintan nada.
static void OcultaLoQueEstorba(void)
{
    for (u32 i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        if (gMarcadorSpriteIds[i] < MAX_SPRITES)
            OcultaMarcador(gMarcadorSpriteIds[i]);
    }
}

static void MueveSeleccion(s32 salto)
{
    s32 movimiento = sMovimientoElegido + salto;

    // Se da la vuelta por los dos extremos: recorrer la lista entera no deberia
    // obligar a cambiar de direccion.
    while (movimiento < 1)
        movimiento += NUMERO_MOVIMIENTOS - 1;
    while (movimiento >= NUMERO_MOVIMIENTOS)
        movimiento -= NUMERO_MOVIMIENTOS - 1;

    sMovimientoElegido = movimiento;
}

// El texto NO puede ser local. BattlePutTextOnWindow se queda con el puntero y va
// imprimiendo a lo largo de varios fotogramas, asi que un array de pila se
// reutiliza por debajo y salen letras aleatorias. Por eso el combate usa
// gDisplayedStringBattle, que es global; aqui se hace lo mismo con uno propio.
static EWRAM_DATA u8 sTextoSeleccion[64] = {0};

static void MuestraSeleccion(void)
{
    static const u8 sFlechaIzquierda[] = _("{LEFT_ARROW} ");
    static const u8 sFlechaDerecha[] = _(" {RIGHT_ARROW}");
    u8 *fin;

    fin = StringCopy(sTextoSeleccion, sFlechaIzquierda);
    fin = StringCopy(fin, gMovimientos[sMovimientoElegido].name);
    fin = StringCopy(fin, sFlechaDerecha);
    *fin = EOS;

    BattlePutTextOnWindow(sTextoSeleccion, B_WIN_MSG);
}

// Cuando el comando de animacion termina, en vez de cerrar el turno se vuelve al
// selector. Sustituye a la funcion de cierre normal solo mientras dura la
// animacion.
static void FinDeAnimacionLaboratorio(u32 combatiente)
{
    // OJO: aqui NO se desmarca al combatiente como libre.
    //
    // Esa bandera hace doble funcion: significa "el controlador esta trabajando" y
    // tambien "ya hay accion elegida". Soltarla al acabar la animacion hacia que el
    // bucle de combate leyera la respuesta -que no existia- y ejecutara un turno de
    // verdad: dano, contraataque y todo. El laboratorio sigue ocupado desde el
    // punto de vista del combate hasta que se sale con B.
    // No se vuelve a escribir el nombre al terminar. Reescribirlo repone el
    // movimiento que se acaba de animar, asi que si se cambiaba la seleccion justo
    // antes, la animacion la deshacia al acabar.
    gBattlerControllerFuncs[combatiente] = ControladorLaboratorio;
    sFase = LAB_ELIGIENDO;
}

// Lanza la animacion por el MISMO camino que el combate de verdad.
//
// Antes se reproducia la secuencia a mano -DoMoveAnim y sondear gAnimScriptActive-
// y faltaba la espera final que hace el controlador real. Sin ella se daba por
// terminada la animacion antes de que monbg hubiera devuelto al Pokemon a su
// sprite, asi que se quedaba oculto y el fondo en negro. Usando el comando de
// verdad no puede haber diferencias.
static void ArrancaAnimacion(u32 combatiente)
{
    u32 rival = (GetBattlerSide(combatiente) == LADO_JUGADOR) ? OPONENTE_IZQUIERDA : JUGADOR_IZQUIERDA;

    gBattlerAttacker = combatiente;
    gBattlerTarget = rival;

    // Se prepara el comando y se le pasa el mando al manejador de verdad, que se
    // instala solo el bucle por fotograma y al terminar llama a BattleControllerComplete
    // -o sea, a nuestra funcion de cierre-. Es el mismo codigo que corre en combate,
    // sin pasar por la bandera de ocupado.
    gBattlerControllerEndFuncs[combatiente] = FinDeAnimacionLaboratorio;
    ComandoAnimacionMovimiento(combatiente, sMovimientoElegido, 0, 0, 0, 0,
                               &gDisableStructs[combatiente], 0);
    gBattlerControllerFuncs[combatiente] = (GetBattlerSide(combatiente) == LADO_JUGADOR)
                                         ? PlayerHandleMoveAnimation
                                         : OpponentHandleMoveAnimation;
}

static void ControladorLaboratorio(u32 combatiente)
{
    if (JOY_NEW(DPAD_RIGHT))       { MueveSeleccion(SALTO_FINO);    MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(DPAD_LEFT))   { MueveSeleccion(-SALTO_FINO);   MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(DPAD_UP))     { MueveSeleccion(SALTO_MEDIO);   MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(DPAD_DOWN))   { MueveSeleccion(-SALTO_MEDIO);  MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(R_BUTTON))    { MueveSeleccion(SALTO_GRUESO);  MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(L_BUTTON))    { MueveSeleccion(-SALTO_GRUESO); MuestraSeleccion(); PlaySE(SE_SELECT); }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ArrancaAnimacion(combatiente);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        // Salir es huir: es la unica forma de que el combate se deshaga por su
        // camino normal en vez de dejar el sistema a medio montar.
        PlaySE(SE_SELECT);
        gBattlerControllerEndFuncs[combatiente] = sCierreOriginal;
        RespondeDosValores(combatiente, B_ACTION_RUN, 0);
        BattleControllerComplete(combatiente);
    }
}

bool32 LaboratorioTomaElControl(u32 combatiente)
{
    if (!gLaboratorioAnimaciones)
        return FALSE;

    OcultaLoQueEstorba();
    MuestraSeleccion();
    sFase = LAB_ELIGIENDO;
    sCierreOriginal = gBattlerControllerEndFuncs[combatiente];
    gBattlerControllerFuncs[combatiente] = ControladorLaboratorio;
    return TRUE;
}

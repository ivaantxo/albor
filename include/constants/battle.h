#ifndef GUARD_CONSTANTS_BATTLE_H
#define GUARD_CONSTANTS_BATTLE_H

/*
 * A battler may be in one of four positions on the field. The first bit determines
 * what side the battler is on, either the player's side or the opponent's side.
 * The second bit determines what flank the battler is on, either the left or right.
 * Note that the opponent's flanks are drawn corresponding to their perspective, so
 * their right mon appears on the left, and their left mon appears on the right.
 * The battler ID is usually the same as the position, except in the case of link battles.
 *
 *   + ------------------------- +
 *   |           Opponent's side |
 *   |            Right    Left  |
 *   |              3       1    |
 *   |                           |
 *   | Player's side             |
 *   |  Left   Right             |
 *   |   0       2               |
 *   ----------------------------+
 *   |                           |
 *   |                           |
 *   +---------------------------+
 */

enum PosicionesCombate
{
    JUGADOR_IZQUIERDA,
    OPONENTE_IZQUIERDA,
    JUGADOR_DERECHA,
    OPONENTE_DERECHA,
    NUMERO_COMBATIENTES
};

// These macros can be used with either battler ID or positions to get the partner or the opposite mon
#define OPONENTE(combatiente) ((combatiente) ^ BIT_SIDE)
#define ALIADO(combatiente) ((combatiente) ^ BIT_FLANK)

enum LadosCombate
{
    LADO_JUGADOR,
    LADO_OPONENTE,
    NUMERO_LADOS
};

// Lo que devuelve un controlador en gRespuestaCombatiente.valor8 al cerrarse una pantalla de
// seleccion. Es un espacio de valores PROPIO: no son acciones de turno
// (B_ACTION_*), aunque viajen por el mismo byte en otro momento del turno.
// Antes se reutilizaban valores de B_ACTION_* como marcadores, y como
// B_ACTION_EXEC_SCRIPT vale 3, "he elegido movimiento" acababa asignandose
// como accion "ejecutar guion" y el Pokemon no atacaba nunca.
enum ResultadoSeleccion
{
    SELECCION_MOVIMIENTO,   // datos = posicion del movimiento | (objetivo << 8)
    SELECCION_CAMBIO,       // datos = indice del Pokemon elegido
    SELECCION_HUIDA,        // huir o rendirse
    SELECCION_DATOS,        // pantalla informativa: no cambia nada
    SELECCION_CANCELADA,    // se volvio atras sin elegir
};

enum FlancosCombate
{
    FLANCO_IZQUIERDO,
    FLANCO_DERECHO,
};

enum BitesLadosCombate
{
    BIT_SIDE = 1,
    BIT_FLANK,
};

enum ModosCombate
{
    INDIVIDUAL,
    DOBLES,
    NUMERO_MODOS
};

enum TiposCombate
{
    COMBATE_SALVAJE,
    COMBATE_ENTRENADOR,
    COMBATE_LEGENDARIO,

    NUMERO_TIPOS_COMBATE = 0xFFFF,
};

enum ResultadosCombate
{
    B_OUTCOME_WON = 1,
    B_OUTCOME_LOST,
    B_OUTCOME_DREW,
    B_OUTCOME_RAN,
    B_OUTCOME_PLAYER_TELEPORTED,
    B_OUTCOME_MON_FLED,
    B_OUTCOME_CAUGHT,
    B_OUTCOME_FORFEITED,
    B_OUTCOME_MON_TELEPORTED,
};

// Non-volatile status conditions
// These remain outside of battle and after switching out.
// If a new STATUS1 is added here, it should also be added to
// sCompressedStatuses in src/pokemon.c or else it will be lost outside
// of battle.
// Estados principales.
//
// Se mantienen al cambiar de Pokemon dentro del combate y se borran al salir de
// el: fuera de combate no existen, asi que no viajan a los datos del equipo.
// Cada uno es su propia casilla, no un bit: pueden acumularse, y el dia que a
// alguno le haga falta guardar algo mas que un si/no, ya cabe.
//
// Ninguno lleva contador de turnos. Duran hasta que algo los cure.
enum EstadoPrincipal
{
    ESTADO_NINGUNO,
    ESTADO_QUEMADURA,
    ESTADO_CONGELACION,
    ESTADO_VENENO,
    ESTADO_PARALISIS,
    ESTADO_SUENO,
    ESTADO_ENAMORADO,
    NUMERO_ESTADOS_PRINCIPALES,
    ESTADO_CUALQUIERA,   // no se guarda: solo lo usan las curaciones que valen para todos
};

//
// La interfaz de arriba -EstadoActivo, PonEstado, QuitaEstado- es la unica que
// deberia usar el juego; estas banderas son el almacen y estan aqui para que
// convivan los sitios que aun no se han pasado. Cuando no quede ninguno, el
// array de casillas sustituye a la palabra y esto se borra entero.

//enum EstadosPokemon
//{
//    SIN_ESTADO,
//    ESTADO_DORMIDO,
//    ESTADO_ENVENENADO,
//    ESTADO_QUEMADO,
//    ESTADO_CONGELADO,
//    ESTADO_PARALIZADO,
//    NUMERO_ESTADOS = 0xFFFF,
//};

// Volatile status ailments
// These are removed after exiting the battle or switching out
// Estados transitorios.
//
// Se borran al cambiar de Pokemon y no salen del combate. A diferencia de los
// permanentes, estos SI se acumulan entre si: son cosas distintas que pueden
// pasarle a la vez al mismo Pokemon.
//
// Antes estaban repartidos en dos palabras -status2 y gStatuses3- solo porque
// no cabian en una; esa frontera no significaba nada y ha desaparecido.
enum EstadoTransitorio
{
    TRANSITORIO_CONFUSION,
    TRANSITORIO_SORPRESA,        // pierde el turno
    TRANSITORIO_TORMENTO,        // no puede repetir movimiento
    TRANSITORIO_ENCADENADO,      // repite contra la misma posicion del campo
    TRANSITORIO_MULTITURNO,      // movimiento de varios turnos en curso
    TRANSITORIO_RIZO_DEFENSA,
    TRANSITORIO_DESCANSO,        // turno de descanso obligatorio
    TRANSITORIO_FURIA,
    TRANSITORIO_SUSTITUTO,
    TRANSITORIO_SIN_ESCAPE,
    TRANSITORIO_MALDICION,
    TRANSITORIO_DRENADORAS,
    TRANSITORIO_CANTO_MORTAL,
    TRANSITORIO_EN_EL_AIRE,
    TRANSITORIO_BAJO_TIERRA,
    TRANSITORIO_BAJO_EL_AGUA,
    TRANSITORIO_GOLPE_FANTASMA,
    TRANSITORIO_CARGADO,
    TRANSITORIO_ARRAIGADO,
    TRANSITORIO_BILIS,
    TRANSITORIO_ACUA_ARO,
    NUMERO_ESTADOS_TRANSITORIOS,
};

// Los cuatro que sacan al Pokemon del campo durante un turno.
#define ES_SEMI_INVULNERABLE(b) (TransitorioActivo(b, TRANSITORIO_EN_EL_AIRE)     \
                              || TransitorioActivo(b, TRANSITORIO_BAJO_TIERRA)    \
                              || TransitorioActivo(b, TRANSITORIO_BAJO_EL_AGUA)   \
                              || TransitorioActivo(b, TRANSITORIO_GOLPE_FANTASMA))

// Marcas del golpe en curso.
//
// Antes eran diecisiete bits repartidos a mano dentro de un u32 -gHitMarker-,
// con huecos por todas partes de banderas que se fueron quitando y sin sitio
// para nada que no fuera un si/no. Ahora cada una es su propia variable: se
// pueden combinar sin presupuesto de bits y, el dia que a alguna le haga falta,
// puede guardar algo mas que un cero o un uno.
enum MarcaGolpe
{
    MARCA_LAZO_DESTINO,             // el atacante lleva Lazo Destino armado
    MARCA_IGNORA_SUSTITUTO,
    MARCA_SIN_TEXTO_ATAQUE,
    MARCA_TEXTO_ATAQUE_ESCRITO,
    MARCA_SIN_GASTAR_PP,
    MARCA_PERMITIR_SIN_PP,
    MARCA_INTERCAMBIA_ATACANTE,
    MARCA_EFECTO_HABILIDAD_ESTADO,
    MARCA_EFECTO_SINCRONIA,
    MARCA_HUYENDO,
    MARCA_SIN_ANIMACION,            // apaga las animaciones dentro de un guion
    MARCA_NO_PUEDE_MOVERSE,
    MARCA_DANIO_PASIVO,
    MARCA_JUGADOR_DEBILITADO,
    MARCA_CARGANDO,
    NUMERO_MARCAS_GOLPE,
};

// Per-side statuses that affect an entire party
#define SIDE_STATUS_REFLECT                 (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN             (1 << 1)
#define SIDE_STATUS_SAFEGUARD               (1 << 4)
#define SIDE_STATUS_MIST                    (1 << 5)
#define SIDE_STATUS_TAILWIND                (1 << 6)
#define SIDE_STATUS_AURORA_VEIL             (1 << 7)

#define SIDE_STATUS_SCREEN_ANY     (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)

// Trampas de entrada. Cada una vive en su propio u16 de EWRAM y solo gasta dos
// bits: uno por lado del campo. Un u16 por trampa permite consultar o cambiar un
// lado con una sola operacion, sin contadores de capas ni mascaras compartidas.
//
// Las de dano van primero a proposito: asi "trampa < NUMERO_TRAMPAS_DANIO" basta
// para separarlas de las que solo bajan Velocidad, y los dos recorridos que hay
// sobre ellas no necesitan ninguna tabla.
enum TrampaEntrada
{
    TRAMPA_BRASAS,              // Fuego
    TRAMPA_ESPINAS,             // Planta
    TRAMPA_PUAS_TOXICAS,        // Veneno
    TRAMPA_ROCAS_PUNTIAGUDAS,   // Roca
    TRAMPA_PUAS,                // Acero
    TRAMPA_PENITENTES,          // Hielo
    NUMERO_TRAMPAS_DANIO,

    TRAMPA_RED_VISCOSA = NUMERO_TRAMPAS_DANIO,  // Bicho, baja Velocidad
    TRAMPA_ENREDADERAS,                         // Planta, baja Velocidad
    NUMERO_TRAMPAS_ENTRADA,

    // Para el guion de combate: la trampa la decide el tipo del movimiento.
    TRAMPA_SEGUN_TIPO_MOVIMIENTO = 0xFE,
    TRAMPA_ENTRADA_NINGUNA       = 0xFF,
};

// Marcas de gDisableStructs[].trampasEntradaProcesadas: un bit por trampa ya
// resuelta en este cambio de Pokemon, mas uno para la absorcion, que va antes
// que todas y solo puede pasar una vez.
enum FaseTrampasEntrada
{
    TRAMPAS_ABSORCION_PROCESADA = 1 << NUMERO_TRAMPAS_ENTRADA,
};

// Qué le ha pasado al movimiento, independientemente de su efectividad
// (que vive en resultadoMovimiento, el multiplicador uq4_12_t). Sustituye a los
// flags gMoveResultFlags/MOVE_RESULT_*.
enum ResultadoMovimiento
{
    RESULTADO_MOVIMIENTO_CONECTA,
    RESULTADO_MOVIMIENTO_FALLO,
    RESULTADO_MOVIMIENTO_NO_AFECTA,
    RESULTADO_MOVIMIENTO_FALLIDO,
};

// Move Effects
#define MOVE_EFFECT_SLEEP               1
#define MOVE_EFFECT_POISON              2
#define MOVE_EFFECT_BURN                3
#define EFECTO_MOVIMIENTO_CONGELACION              4
#define MOVE_EFFECT_PARALYSIS           5
#define MOVE_EFFECT_TOXIC               6
#define PRIMARY_STATUS_MOVE_EFFECT      EFECTO_MOVIMIENTO_CONGELACION // All above move effects apply primary status
#define MOVE_EFFECT_CONFUSION           8
#define MOVE_EFFECT_FLINCH              9
#define MOVE_EFFECT_UPROAR              11
#define EFECTO_MOVIMIENTO_SALTA_DINERO              12
#define MOVE_EFFECT_CHARGING            13
#define MOVE_EFFECT_WRAP                14
#define MOVE_EFFECT_ATK_PLUS_1          15
#define MOVE_EFFECT_DEF_PLUS_1          16
#define MOVE_EFFECT_SPD_PLUS_1          17
#define MOVE_EFFECT_SP_ATK_PLUS_1       18
#define MOVE_EFFECT_SP_DEF_PLUS_1       19
#define MOVE_EFFECT_ACC_PLUS_1          20
#define MOVE_EFFECT_EVS_PLUS_1          21
#define MOVE_EFFECT_ATK_MINUS_1         22
#define MOVE_EFFECT_DEF_MINUS_1         23
#define MOVE_EFFECT_SPD_MINUS_1         24
#define MOVE_EFFECT_SP_ATK_MINUS_1      25
#define MOVE_EFFECT_SP_DEF_MINUS_1      26
#define MOVE_EFFECT_ACC_MINUS_1         27
#define MOVE_EFFECT_EVS_MINUS_1         28
#define MOVE_EFFECT_RECHARGE            30
#define MOVE_EFFECT_RAGE                31
#define MOVE_EFFECT_STEAL_ITEM          32
#define MOVE_EFFECT_PREVENT_ESCAPE      33
#define MOVE_EFFECT_NIGHTMARE           34
#define MOVE_EFFECT_ALL_STATS_UP        35
#define MOVE_EFFECT_GIRO_RAPIDO          36
#define MOVE_EFFECT_REMOVE_STATUS       37
#define MOVE_EFFECT_ATK_DEF_DOWN        38
#define MOVE_EFFECT_ATK_PLUS_2          39
#define MOVE_EFFECT_DEF_PLUS_2          40
#define MOVE_EFFECT_SPD_PLUS_2          41
#define MOVE_EFFECT_SP_ATK_PLUS_2       42
#define MOVE_EFFECT_SP_DEF_PLUS_2       43
#define MOVE_EFFECT_ACC_PLUS_2          44
#define MOVE_EFFECT_EVS_PLUS_2          45
#define MOVE_EFFECT_ATK_MINUS_2         46
#define MOVE_EFFECT_DEF_MINUS_2         47
#define MOVE_EFFECT_SPD_MINUS_2         48
#define MOVE_EFFECT_SP_ATK_MINUS_2      49
#define MOVE_EFFECT_SP_DEF_MINUS_2      50
#define MOVE_EFFECT_ACC_MINUS_2         51
#define MOVE_EFFECT_EVS_MINUS_2         52
#define MOVE_EFFECT_SCALE_SHOT          53
#define MOVE_EFFECT_THRASH              54
#define EFECTO_MOVIMIENTO_QUITAR_OBJETO           55
#define MOVE_EFFECT_DEF_SPDEF_DOWN      56
#define MOVE_EFFECT_CLEAR_SMOG          57
#define MOVE_EFFECT_SMACK_DOWN          58
#define MOVE_EFFECT_FLAME_BURST         59
#define MOVE_EFFECT_FEINT               60
#define MOVE_EFFECT_SPECTRAL_THIEF      61
#define MOVE_EFFECT_THROAT_CHOP         65
#define MOVE_EFFECT_BUG_BITE            67
#define MOVE_EFFECT_TRAP_BOTH           69
#define MOVE_EFFECT_STOCKPILE_WORE_OFF  71
#define MOVE_EFFECT_DIRE_CLAW           72
#define MOVE_EFFECT_STEALTH_ROCK        73
#define MOVE_EFFECT_SPIKES              74
#define MOVE_EFFECT_FLORAL_HEALING      76
#define MOVE_EFFECT_SECRET_POWER        77

#define NUM_MOVE_EFFECTS                78

#define MOVE_EFFECT_AFFECTS_USER        0x2000
#define MOVE_EFFECT_CERTAIN             0x4000
#define MOVE_EFFECT_CONTINUE            0x8000

// Battle terrain defines for gBattleTerrain.
#define BATTLE_TERRAIN_GRASS            0
#define BATTLE_TERRAIN_LONG_GRASS       1
#define BATTLE_TERRAIN_SAND             2
#define BATTLE_TERRAIN_UNDERWATER       3
#define BATTLE_TERRAIN_WATER            4
#define BATTLE_TERRAIN_POND             5
#define BATTLE_TERRAIN_MOUNTAIN         6
#define BATTLE_TERRAIN_CAVE             7
#define BATTLE_TERRAIN_BUILDING         8
#define BATTLE_TERRAIN_PLAIN            9
// New battle terrains are used for Secret Power but not fully implemented.
#define BATTLE_TERRAIN_SOARING          10
#define BATTLE_TERRAIN_SKY_PILLAR       11
#define BATTLE_TERRAIN_BURIAL_GROUND    12
#define BATTLE_TERRAIN_PUDDLE           13
#define BATTLE_TERRAIN_MARSH            14
#define BATTLE_TERRAIN_SWAMP            15
#define BATTLE_TERRAIN_SNOW             16
#define BATTLE_TERRAIN_ICE              17
#define BATTLE_TERRAIN_VOLCANO          18
#define BATTLE_TERRAIN_DISTORTION_WORLD 19
#define BATTLE_TERRAIN_SPACE            20
#define BATTLE_TERRAIN_ULTRA_SPACE      21

#define BATTLE_TERRAIN_COUNT            22

#define PAUSA_LARGA         (PAUSA_MUY_CORTA * 4)
#define PAUSA_MEDIA         (PAUSA_MUY_CORTA * 3)
#define PAUSA_CORTA         (PAUSA_MUY_CORTA * 2)
#define PAUSA_MUY_CORTA     10

// Window Ids for sBattleWindowTemplates
#define B_WIN_MSG                 0
#define B_WIN_MOVE_NAME_1         1 // Top left
#define B_WIN_MOVE_NAME_2         2 // Top right
#define B_WIN_MOVE_NAME_3         3 // Bottom left
#define B_WIN_MOVE_NAME_4         4 // Bottom right
#define B_WIN_PP_1                5
#define B_WIN_PP_2                6
#define B_WIN_PP_3                7
#define B_WIN_PP_4                8
#define B_WIN_YESNO               9
#define B_WIN_LEVEL_UP_BOX        10
#define B_WIN_LEVEL_UP_BANNER     11
#define B_WIN_VS_PLAYER           12
#define B_WIN_VS_OPPONENT         13
#define B_WIN_VS_MULTI_PLAYER_1   14
#define B_WIN_VS_MULTI_PLAYER_2   15
#define B_WIN_VS_MULTI_PLAYER_3   16
#define B_WIN_VS_MULTI_PLAYER_4   17
#define B_WIN_VS_OUTCOME_DRAW     18
#define B_WIN_VS_OUTCOME_LEFT     19
#define B_WIN_VS_OUTCOME_RIGHT    20
#define B_WIN_MOVE_DESCRIPTION    21

// Indicator for the party summary bar to display an empty slot.
#define HP_EMPTY_SLOT 0xFFFF

#define MOVE_TARGET_SELECTED            0
#define MOVE_TARGET_DEPENDS             (1 << 0)
#define MOVE_TARGET_USER_OR_SELECTED    (1 << 1)
#define MOVE_TARGET_RANDOM              (1 << 2)
#define MOVE_TARGET_BOTH                (1 << 3)
#define MOVE_TARGET_USER                (1 << 4)
#define MOVE_TARGET_FOES_AND_ALLY       (1 << 5)
#define MOVE_TARGET_OPPONENTS_FIELD     (1 << 6)
#define MOVE_TARGET_ALLY                (1 << 7)
#define MOVE_TARGET_ALL_BATTLERS        ((1 << 8) | MOVE_TARGET_USER)

// For the second argument of GetMoveTarget, when no target override is needed
#define NO_TARGET_OVERRIDE 0

// Constants for Parental Bond
#define PARENTAL_BOND_1ST_HIT 2
#define PARENTAL_BOND_2ND_HIT 1
#define PARENTAL_BOND_OFF     0

// Constants for Torment
#define PERMANENT_TORMENT   0xF

enum PosicionesCursorSiNo
{
    CURSOR_SI,
    CURSOR_NO,
};


enum EfectosFinTurnoCampo
{
    FIN_TURNO_ORDEN,
    ENDTURN_REFLECT,
    ENDTURN_LIGHT_SCREEN,
    ENDTURN_AURORA_VEIL,
    ENDTURN_MIST,
    ENDTURN_SAFEGUARD,
    ENDTURN_TAILWIND,
    ENDTURN_RAIN,
    ENDTURN_SANDSTORM,
    ENDTURN_SUN,
    ENDTURN_SNOW,
    ENDTURN_ESPACIO_RARO,
    ENDTURN_STATUS_HEAL,
    FIN_TURNO_REPARTO_DRENADORAS,
    ENDTURN_FIELD_COUNT,
};

enum EfectosFinTurnoIndividuales
{
    ENDTURN_WEATHER_DAMAGE,
    ENDTURN_INGRAIN,
    ENDTURN_AQUA_RING,
    ENDTURN_ABILITIES,
    ENDTURN_ITEMS1,
    ENDTURN_LEECH_SEED,
    ENDTURN_POISON,
    ENDTURN_BAD_POISON,
    ENDTURN_BURN,
    FIN_TURNO_CONGELACION,
    ENDTURN_CURSE,
    ENDTURN_THRASH,
    ENDTURN_FLINCH,
    ENDTURN_DISABLE,
    ENDTURN_ENCORE,
    ENDTURN_CHARGE,
    ENDTURN_TAUNT,
    ENDTURN_ITEMS2,
    ENDTURN_ORBS,
    ENDTURN_ROOST,
    ENDTURN_THROAT_CHOP,
    FIN_TURNO_RUMIANTE,
    ENDTURN_TORMENT, // supposedly this goes after Taunt, before Encore, but Encore is first right now?
    ENDTURN_ITEMS3,
    ENDTURN_BATTLER_COUNT
};

#define MINIMO_MULTIGOLPES 2
#define MAXIMO_MULTIGOLPES 5

#define MOVIMIENTO_NO_EFECTIVO              UQ_4_12(0.0)
#define MOVIMIENTO_MUY_POCO_EFECTIVO        UQ_4_12(0.25)
#define MOVIMIENTO_POCO_EFECTIVO            UQ_4_12(0.5)
#define MOVIMIENTO_NEUTRO                   UQ_4_12(1.0)
#define MOVIMIENTO_SUPER_EFECTIVO           UQ_4_12(2.0)
#define MOVIMIENTO_ULTRA_EFECTIVO           UQ_4_12(4.0)

#define TURNOS_EFECTOS                      5
#define TURNOS_CLIMA                        5

enum ClimasCombate
{
    CLIMA_COMBATE_NINGUNO,
    CLIMA_COMBATE_LLUVIA,
    CLIMA_COMBATE_SOL,
    CLIMA_COMBATE_ARENA,
    CLIMA_COMBATE_NIEVE,

    NUMERO_CLIMAS_COMBATE = 0xFFFF,
};

// Máscara de bits sobre enum ClimasCombate, para IsBattlerWeatherAffected / jumpifweatheraffected.
#define B_WEATHER_RAIN      (1 << CLIMA_COMBATE_LLUVIA)
#define B_WEATHER_SUN       (1 << CLIMA_COMBATE_SOL)
#define B_WEATHER_SANDSTORM (1 << CLIMA_COMBATE_ARENA)
#define B_WEATHER_SNOW      (1 << CLIMA_COMBATE_NIEVE)
#define B_WEATHER_ANY       (B_WEATHER_RAIN | B_WEATHER_SUN | B_WEATHER_SANDSTORM | B_WEATHER_SNOW)

enum OrigenClima
{
    ORIGEN_CLIMA_OVERWORLD,
    ORIGEN_CLIMA_MOVIMIENTO,
    ORIGEN_CLIMA_HABILIDAD,
    NUMERO_ORIGENES_CLIMA = 0xFFFF,
};

#endif // GUARD_CONSTANTS_BATTLE_H

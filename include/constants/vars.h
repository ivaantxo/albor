#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VARS_START 0x4000

// Las 16 primeras se borran solas cada vez que se carga un mapa, en
// ClearTempFieldEventData. El bloque tiene que seguir siendo contiguo: alli se
// limpia de una pasada desde TEMP_VARS_START.
enum VariablesTemporales
{
    VAR_TEMP_0  = VARS_START,
    VAR_TEMP_1,
    VAR_TEMP_2,
    VAR_TEMP_3,
    VAR_TEMP_4,
    VAR_TEMP_5,
    VAR_TEMP_6,
    VAR_TEMP_7,
    VAR_TEMP_8,
    VAR_TEMP_9,
    VAR_TEMP_A,
    VAR_TEMP_B,
    VAR_TEMP_C,
    VAR_TEMP_D,
    VAR_TEMP_E,
    VAR_TEMP_F,
};

#define TEMP_VARS_START VAR_TEMP_0
#define TEMP_VARS_END   VAR_TEMP_F
#define NUM_TEMP_VARS   (TEMP_VARS_END - TEMP_VARS_START + 1)

// Las 16 siguientes eligen a mano el sprite de un objeto del mapa cuyo
// graphicsId cae entre OBJ_EVENT_GFX_VAR_0 y _F. Tambien tiene que ser
// contiguo: event_object_movement.c indexa restando OBJ_EVENT_GFX_VAR_0.
enum VariablesGraficoObjeto
{
    VAR_OBJ_GFX_ID_0  = TEMP_VARS_END + 1,
    VAR_OBJ_GFX_ID_1,
    VAR_OBJ_GFX_ID_2,
    VAR_OBJ_GFX_ID_3,
    VAR_OBJ_GFX_ID_4,
    VAR_OBJ_GFX_ID_5,
    VAR_OBJ_GFX_ID_6,
    VAR_OBJ_GFX_ID_7,
    VAR_OBJ_GFX_ID_8,
    VAR_OBJ_GFX_ID_9,
    VAR_OBJ_GFX_ID_A,
    VAR_OBJ_GFX_ID_B,
    VAR_OBJ_GFX_ID_C,
    VAR_OBJ_GFX_ID_D,
    VAR_OBJ_GFX_ID_E,
    VAR_OBJ_GFX_ID_F,
};

// El resto. Aqui no hay bloques ni huecos reservados: se anaden al final y
// VARS_COUNT crece solo.
enum VariablesGuion
{
    VAR_REPEL_STEP_COUNT                  = VAR_OBJ_GFX_ID_F + 1,
    VAR_ICE_STEP_COUNT,
    VAR_STARTER_MON,
    VAR_MIRAGE_RND_H,
    VAR_MIRAGE_RND_L,
    VAR_CYCLING_ROAD_RECORD_COLLISIONS,
    VAR_CYCLING_ROAD_RECORD_TIME_L,
    VAR_CYCLING_ROAD_RECORD_TIME_H,
    VAR_FRIENDSHIP_STEP_COUNTER,
    VAR_POISON_STEP_COUNTER,
    VAR_RESET_RTC_ENABLE,
    VAR_DEOXYS_ROCK_STEP_COUNT,
    VAR_DEOXYS_ROCK_LEVEL,
    VAR_PC_BOX_TO_SEND_MON,
    VAR_ABNORMAL_WEATHER_LOCATION,
    VAR_ABNORMAL_WEATHER_STEP_COUNTER,
    VAR_SHOULD_END_ABNORMAL_WEATHER,
    VAR_FARAWAY_ISLAND_STEP_COUNTER,
    VAR_ALTERING_CAVE_WILD_SET,
    VAR_DISTRIBUTE_EON_TICKET,
    VAR_DAYS,
    VAR_FANCLUB_FAN_COUNTER,
    VAR_FANCLUB_LOSE_FAN_TIMER,
    VAR_POKELOT_PRIZE_ITEM,
    VAR_ASH_GATHER_COUNT,
    VAR_BIRCH_STATE,
    VAR_CRUISE_STEP_COUNT,
    VAR_POKELOT_RND1,
    VAR_POKELOT_RND2,
    VAR_LILYCOVE_FAN_CLUB_STATE,
    VAR_BRINEY_LOCATION,
    VAR_ELITE_4_STATE,
    VAR_SS_TIDAL_STATE,
    VAR_PACIFIDLOG_TM_RECEIVED_DAY,
    VAR_MIRAGE_TOWER_STATE,
    VAR_WALLY_CALL_STEP_COUNTER,
    VAR_SCOTT_FORTREE_CALL_STEP_COUNTER,
    VAR_ROXANNE_CALL_STEP_COUNTER,
    VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER,
};

#define VARS_END   VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER
#define VARS_COUNT (VARS_END - VARS_START + 1)

// Las especiales no se guardan: son los parametros y los valores de retorno de
// los comandos de guion. Viven en gSpecialVars, en RAM, y se pierden al apagar.
#define SPECIAL_VARS_START 0x8000

enum VariablesEspeciales
{
    VAR_0x8000       = SPECIAL_VARS_START,
    VAR_0x8001,
    VAR_0x8002,
    VAR_0x8003,
    VAR_0x8004,
    VAR_0x8005,
    VAR_0x8006,
    VAR_0x8007,
    VAR_0x8008,
    VAR_0x8009,
    VAR_0x800A,
    VAR_0x800B,
    VAR_FACING,
    VAR_RESULT,
    VAR_ITEM_ID,
    VAR_LAST_TALKED,
    VAR_MON_BOX_ID,
    VAR_MON_BOX_POS,
};

#define SPECIAL_VARS_END VAR_MON_BOX_POS

// Si un disparador del mapa usa esta pseudovariable como condicion, el guion se
// lanza con RunScriptImmediately: va mas rapido pero no admite escenas ni esperas.
#define TRIGGER_RUN_IMMEDIATELY 0

// Alias de temporales
#define VAR_TEMP_CHALLENGE_STATUS    VAR_TEMP_0
#define VAR_TEMP_TRANSFERRED_SPECIES VAR_TEMP_1

#endif // GUARD_CONSTANTS_VARS_H

#include "global.h"
#include "main.h"
#include "event_data.h"
#include "hall_of_fame.h"
#include "load_save.h"
#include "overworld.h"
#include "script_pokemon_util.h"
#include "constants/heal_locations.h"

bool8 SetCB2WhiteOut(void)
{
    SetMainCallback2(CB2_WhiteOut);
    return FALSE;
}

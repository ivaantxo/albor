#include "global.h"
#include "script.h"
#include "scrcmd.h"
#include "event_data.h"
#include "field_message_box.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/map_scripts.h"
#include "constants/scr_cmds.h"
#include "field_message_box.h"

enum {
    SCRIPT_MODE_STOPPED,
    SCRIPT_MODE_BYTECODE,
    SCRIPT_MODE_NATIVE,
};

enum {
    CONTEXT_RUNNING,
    CONTEXT_WAITING,
    CONTEXT_SHUTDOWN,
};

static u8 sGlobalScriptContextStatus;
static struct ScriptContext sGlobalScriptContext;
static struct ScriptContext sImmediateScriptContext;
static bool8 sLockFieldControls;
EWRAM_DATA u8 gMsgIsSignPost = FALSE;
EWRAM_DATA u8 gMsgBoxIsCancelable = FALSE;

extern const ScrCmdFunc gScriptCmdTable[];

#define SCR_CMD(nombre)        [SCR_CMD_## nombre] = ScrCmd_## nombre

const ScrCmdFunc gScriptCmdTable[] =
{
    SCR_CMD(end),
    SCR_CMD(return),
    SCR_CMD(call),
    SCR_CMD(goto),
    SCR_CMD(goto_if),
    SCR_CMD(call_if),
    SCR_CMD(gotostd),
    SCR_CMD(callstd),
    SCR_CMD(gotostd_if),
    SCR_CMD(callstd_if),
    SCR_CMD(loadword),
    SCR_CMD(loadbyte),
    SCR_CMD(setptr),
    SCR_CMD(loadbytefromptr),
    SCR_CMD(setptrbyte),
    SCR_CMD(copylocal),
    SCR_CMD(copybyte),
    SCR_CMD(setvar),
    SCR_CMD(addvar),
    SCR_CMD(subvar),
    SCR_CMD(copyvar),
    SCR_CMD(setorcopyvar),
    SCR_CMD(compare_local_to_local),
    SCR_CMD(compare_local_to_value),
    SCR_CMD(compare_local_to_ptr),
    SCR_CMD(compare_ptr_to_local),
    SCR_CMD(compare_ptr_to_value),
    SCR_CMD(compare_ptr_to_ptr),
    SCR_CMD(compare_var_to_value),
    SCR_CMD(compare_var_to_var),
    SCR_CMD(callnative),
    SCR_CMD(gotonative),
    SCR_CMD(special),
    SCR_CMD(specialvar),
    SCR_CMD(waitstate),
    SCR_CMD(delay),
    SCR_CMD(setflag),
    SCR_CMD(clearflag),
    SCR_CMD(checkflag),
    SCR_CMD(initclock),
    SCR_CMD(dotimebasedevents),
    SCR_CMD(gettime),
    SCR_CMD(playse),
    SCR_CMD(waitse),
    SCR_CMD(playfanfare),
    SCR_CMD(waitfanfare),
    SCR_CMD(playbgm),
    SCR_CMD(savebgm),
    SCR_CMD(fadedefaultbgm),
    SCR_CMD(fadenewbgm),
    SCR_CMD(fadeoutbgm),
    SCR_CMD(fadeinbgm),
    SCR_CMD(warp),
    SCR_CMD(warpsilent),
    SCR_CMD(warpdoor),
    SCR_CMD(warphole),
    SCR_CMD(warpteleport),
    SCR_CMD(setwarp),
    SCR_CMD(setdynamicwarp),
    SCR_CMD(setdivewarp),
    SCR_CMD(setholewarp),
    SCR_CMD(getplayerxy),
    SCR_CMD(getpartysize),
    SCR_CMD(additem),
    SCR_CMD(removeitem),
    SCR_CMD(checkitemspace),
    SCR_CMD(checkitem),
    SCR_CMD(checkitemtype),
    SCR_CMD(adddecoration),
    SCR_CMD(removedecoration),
    SCR_CMD(checkdecor),
    SCR_CMD(checkdecorspace),
    SCR_CMD(applymovement),
    SCR_CMD(applymovementat),
    SCR_CMD(waitmovement),
    SCR_CMD(waitmovementat),
    SCR_CMD(removeobject),
    SCR_CMD(removeobjectat),
    SCR_CMD(addobject),
    SCR_CMD(addobjectat),
    SCR_CMD(setobjectxy),
    SCR_CMD(showobjectat),
    SCR_CMD(hideobjectat),
    SCR_CMD(faceplayer),
    SCR_CMD(turnobject),
    SCR_CMD(trainerbattle),
    SCR_CMD(dotrainerbattle),
    SCR_CMD(gotopostbattlescript),
    SCR_CMD(gotobeatenscript),
    SCR_CMD(checktrainerflag),
    SCR_CMD(settrainerflag),
    SCR_CMD(cleartrainerflag),
    SCR_CMD(setobjectxyperm),
    SCR_CMD(copyobjectxytoperm),
    SCR_CMD(setobjectmovementtype),
    SCR_CMD(waitmessage),
    SCR_CMD(message),
    SCR_CMD(closemessage),
    SCR_CMD(lockall),
    SCR_CMD(lock),
    SCR_CMD(releaseall),
    SCR_CMD(release),
    SCR_CMD(waitbuttonpress),
    SCR_CMD(yesnobox),
    SCR_CMD(multichoice),
    SCR_CMD(multichoicedefault),
    SCR_CMD(multichoicegrid),
    SCR_CMD(showmonpic),
    SCR_CMD(hidemonpic),
    SCR_CMD(showcontestpainting),
    SCR_CMD(braillemessage),
    SCR_CMD(giveegg),
    SCR_CMD(setmonmove),
    SCR_CMD(checkpartymove),
    SCR_CMD(bufferspeciesname),
    SCR_CMD(bufferleadmonspeciesname),
    SCR_CMD(bufferpartymonnick),
    SCR_CMD(bufferitemname),
    SCR_CMD(bufferdecorationname),
    SCR_CMD(buffermovename),
    SCR_CMD(buffernumberstring),
    SCR_CMD(bufferstdstring),
    SCR_CMD(bufferstring),
    SCR_CMD(pokemart),
    SCR_CMD(pokemartdecoration),
    SCR_CMD(pokemartdecoration2),
    SCR_CMD(playslotmachine),
    SCR_CMD(setberrytree),
    SCR_CMD(choosecontestmon),
    SCR_CMD(startcontest),
    SCR_CMD(showcontestresults),
    SCR_CMD(random),
    SCR_CMD(addmoney),
    SCR_CMD(removemoney),
    SCR_CMD(checkmoney),
    SCR_CMD(showmoneybox),
    SCR_CMD(hidemoneybox),
    SCR_CMD(updatemoneybox),
    SCR_CMD(fadescreen),
    SCR_CMD(fadescreenspeed),
    SCR_CMD(setflashlevel),
    SCR_CMD(animateflash),
    SCR_CMD(messageautoscroll),
    SCR_CMD(dofieldeffect),
    SCR_CMD(setfieldeffectargument),
    SCR_CMD(waitfieldeffect),
    SCR_CMD(setrespawn),
    SCR_CMD(checkplayergender),
    SCR_CMD(playmoncry),
    SCR_CMD(setmetatile),
    SCR_CMD(resetweather),
    SCR_CMD(setweather),
    SCR_CMD(doweather),
    SCR_CMD(setstepcallback),
    SCR_CMD(setmaplayoutindex),
    SCR_CMD(setobjectsubpriority),
    SCR_CMD(resetobjectsubpriority),
    SCR_CMD(createvobject),
    SCR_CMD(turnvobject),
    SCR_CMD(opendoor),
    SCR_CMD(closedoor),
    SCR_CMD(waitdooranim),
    SCR_CMD(setdooropen),
    SCR_CMD(setdoorclosed),
    SCR_CMD(addelevmenuitem),
    SCR_CMD(showelevmenu),
    SCR_CMD(checkcoins),
    SCR_CMD(addcoins),
    SCR_CMD(removecoins),
    SCR_CMD(setwildbattle),
    SCR_CMD(dowildbattle),
    SCR_CMD(showcoinsbox),
    SCR_CMD(hidecoinsbox),
    SCR_CMD(updatecoinsbox),
    SCR_CMD(incrementgamestat),
    SCR_CMD(setescapewarp),
    SCR_CMD(waitmoncry),
    SCR_CMD(bufferboxname),
    SCR_CMD(warpspinenter),
    SCR_CMD(setmonmetlocation),
    SCR_CMD(moverotatingtileobjects),
    SCR_CMD(turnrotatingtileobjects),
    SCR_CMD(initrotatingtilepuzzle),
    SCR_CMD(freerotatingtilepuzzle),
    SCR_CMD(warpmossdeepgym),
    SCR_CMD(selectapproachingtrainer),
    SCR_CMD(lockfortrainer),
    SCR_CMD(closebraillemessage),
    SCR_CMD(messageinstant),
    SCR_CMD(fadescreenswapbuffers),
    SCR_CMD(buffertrainerclassname),
    SCR_CMD(buffertrainername),
    SCR_CMD(pokenavcall),
    SCR_CMD(warpwhitefade),
    SCR_CMD(buffercontestname),
    SCR_CMD(bufferitemnameplural),
    SCR_CMD(dynmultichoice),
    SCR_CMD(dynmultipush),

    [SCR_CMD_count] = NULL
};

void InitScriptContext(struct ScriptContext *ctx, const void *cmdTable)
{
    s32 i;

    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
    ctx->stackDepth = 0;
    ctx->nativePtr = NULL;
    ctx->cmdTable = cmdTable;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->data); i++)
        ctx->data[i] = 0;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->stack); i++)
        ctx->stack[i] = NULL;
}

u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
    ctx->mode = SCRIPT_MODE_BYTECODE;
    return 1;
}

void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void))
{
    ctx->mode = SCRIPT_MODE_NATIVE;
    ctx->nativePtr = ptr;
}

void StopScript(struct ScriptContext *ctx)
{
    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
}

bool8 RunScriptCommand(struct ScriptContext *ctx)
{
    if (ctx->mode == SCRIPT_MODE_STOPPED)
        return FALSE;

    switch (ctx->mode)
    {
    case SCRIPT_MODE_NATIVE:
        if (ctx->nativePtr)
        {
            if (ctx->nativePtr() == TRUE)
                ctx->mode = SCRIPT_MODE_BYTECODE;
            return TRUE;
        }
        ctx->mode = SCRIPT_MODE_BYTECODE;
        // fallthrough

    case SCRIPT_MODE_BYTECODE:
        while (1)
        {
            u8 cmdCode;

            if (!ctx->scriptPtr)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            #define HALT() do { while (1) asm("svc 0x02"); } while (0)
            if (!ctx->scriptPtr)
                HALT();

            cmdCode = *(ctx->scriptPtr++);
            if (cmdCode >= SCR_CMD_count)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if (ctx->cmdTable[cmdCode](ctx) == TRUE)
                return TRUE;
        }
    }

    return TRUE;
}

static bool8 ScriptPush(struct ScriptContext *ctx, const u8 *ptr)
{
    if (ctx->stackDepth + 1 >= (int)ARRAY_COUNT(ctx->stack))
    {
        return TRUE;
    }
    else
    {
        ctx->stack[ctx->stackDepth] = ptr;
        ctx->stackDepth++;
        return FALSE;
    }
}

static const u8 *ScriptPop(struct ScriptContext *ctx)
{
    if (ctx->stackDepth == 0)
        return NULL;

    ctx->stackDepth--;
    return ctx->stack[ctx->stackDepth];
}

void ScriptJump(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
}

void ScriptCall(struct ScriptContext *ctx, const u8 *ptr)
{
    ScriptPush(ctx, ctx->scriptPtr);
    ctx->scriptPtr = ptr;
}

void ScriptReturn(struct ScriptContext *ctx)
{
    ctx->scriptPtr = ScriptPop(ctx);
}

u16 ScriptReadHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr++);
    value |= *(ctx->scriptPtr++) << 8;
    return value;
}

u32 ScriptReadWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr++);
    u32 value1 = *(ctx->scriptPtr++);
    u32 value2 = *(ctx->scriptPtr++);
    u32 value3 = *(ctx->scriptPtr++);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

u32 ScriptPeekWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr);
    u32 value1 = *(ctx->scriptPtr + 1);
    u32 value2 = *(ctx->scriptPtr + 2);
    u32 value3 = *(ctx->scriptPtr + 3);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

void LockPlayerFieldControls(void)
{
    sLockFieldControls = TRUE;
}

void UnlockPlayerFieldControls(void)
{
    sLockFieldControls = FALSE;
}

bool8 ArePlayerFieldControlsLocked(void)
{
    return sLockFieldControls;
}

// The ScriptContext_* functions work with the primary script context,
// which yields control back to native code should the script make a wait call.

// Checks if the global script context is able to be run right now.
bool8 ScriptContext_IsEnabled(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_RUNNING)
        return TRUE;
    else
        return FALSE;
}

// Re-initializes the global script context to zero.
void ScriptContext_Init(void)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable);
    sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
}

// Runs the script until the script makes a wait* call, then returns true if
// there's more script to run, or false if the script has hit the end.
// This function also returns false if the context is finished
// or waiting (after a call to _Stop)
bool8 ScriptContext_RunScript(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_SHUTDOWN)
        return FALSE;

    if (sGlobalScriptContextStatus == CONTEXT_WAITING)
        return FALSE;

    LockPlayerFieldControls();

    if (!RunScriptCommand(&sGlobalScriptContext))
    {
        sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
        UnlockPlayerFieldControls();
        return FALSE;
    }

    return TRUE;
}

// Sets up a new script in the global context and enables the context
void ScriptContext_SetupScript(const u8 *ptr)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable);
    SetupBytecodeScript(&sGlobalScriptContext, ptr);
    LockPlayerFieldControls();
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
}

// Puts the script into waiting mode; usually called from a wait* script command.
void ScriptContext_Stop(void)
{
    sGlobalScriptContextStatus = CONTEXT_WAITING;
}

// Puts the script into running mode.
void ScriptContext_Enable(void)
{
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
    LockPlayerFieldControls();
}

// Sets up and runs a script in its own context immediately. The script will be
// finished when this function returns. Used mainly by all of the map header
// scripts (except the frame table scripts).
void RunScriptImmediately(const u8 *ptr)
{
    InitScriptContext(&sImmediateScriptContext, gScriptCmdTable);
    SetupBytecodeScript(&sImmediateScriptContext, ptr);
    while (RunScriptCommand(&sImmediateScriptContext) == TRUE);
}

u8 *MapHeaderGetScriptTable(u8 tag)
{
    const u8 *mapScripts = gMapHeader.mapScripts;

    if (!mapScripts)
        return NULL;

    while(1)
    {
        if (!*mapScripts)
            return NULL;
        if (*mapScripts == tag)
        {
            mapScripts++;
            return T2_READ_PTR(mapScripts);
        }
        mapScripts += 5;
    }
}

void MapHeaderRunScriptType(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);
    if (ptr)
        RunScriptImmediately(ptr);
}

u8 *MapHeaderCheckScriptTable(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);

    if (!ptr)
        return NULL;

    while(1)
    {
        u16 varIndex1;
        u16 varIndex2;

        // Read first var (or .2byte terminal value)
        varIndex1 = T1_READ_16(ptr);
        if (!varIndex1)
            return NULL; // Reached end of table
        ptr += 2;

        // Read second var
        varIndex2 = T1_READ_16(ptr);
        ptr += 2;

        // Run map script if vars are equal
        if (VarGet(varIndex1) == VarGet(varIndex2))
            return T2_READ_PTR(ptr);
        ptr += 4;
    }
}

void RunOnLoadMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_LOAD);
}

void RunOnTransitionMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_TRANSITION);
}

void RunOnResumeMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RESUME);
}

void RunOnReturnToFieldMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RETURN_TO_FIELD);
}

void RunOnDiveWarpMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_DIVE_WARP);
}

bool8 TryRunOnFrameMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_FRAME_TABLE);

    if (!ptr)
        return FALSE;

    ScriptContext_SetupScript(ptr);
    return TRUE;
}

void TryRunOnWarpIntoMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE);
    if (ptr)
        RunScriptImmediately(ptr);
}

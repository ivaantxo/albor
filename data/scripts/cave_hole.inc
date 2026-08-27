EventScript_FallDownHole::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_UNDEFINED
	waitstate
	end

EventScript_FallDownHoleMtPyre::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	special DoFallWarp
	waitstate
	end

Movement_SetInvisible:
	set_invisible
	step_end

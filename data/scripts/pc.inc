EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	goto EventScript_AccessPokemonStorage
	end

EventScript_TV::
	msgbox Text_EsteProgramaLeEncantaAMama, MSGBOX_DEFAULT
	closemessage
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	special ShowPokemonStorageSystemPC
	end

Text_EsteProgramaLeEncantaAMama:
	.string "Este programa le encanta a mamá.$"

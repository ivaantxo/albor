@ VAR_0x8004 here is used by ChangePokemonNickname
Common_EventScript_GetGiftMonPartySlot::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	return

Common_EventScript_NameReceivedBoxMon::
	fadescreen FADE_TO_BLACK
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	return

Common_EventScript_TransferredToPC::
	bufferboxname VAR_TEXTO_1, VAR_PC_BOX_TO_SEND_MON
	bufferspeciesname VAR_TEXTO_2, VAR_TEMP_TRANSFERRED_SPECIES
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_TransferredSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_TransferredLanettesPC
	return

EventScript_TransferredSomeonesPC::
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	goto_if_eq VAR_RESULT, TRUE, EventScript_SomeonesPCBoxFull
	msgbox gText_PkmnFueTransferidoAlPC, MSGBOX_DEFAULT
	return

EventScript_SomeonesPCBoxFull::
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname VAR_TEXTO_3, VAR_RESULT
	msgbox gText_PkmnFueTransferidoAlPC, MSGBOX_DEFAULT
	return

EventScript_TransferredLanettesPC::
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	goto_if_eq VAR_RESULT, TRUE, EventScript_LanettesPCBoxFull
	msgbox gText_PkmnFueTransferidoAlPC, MSGBOX_DEFAULT
	return

EventScript_LanettesPCBoxFull::
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname VAR_TEXTO_3, VAR_RESULT
	msgbox gText_PkmnFueTransferidoAlPC, MSGBOX_DEFAULT
	return

Common_EventScript_NoMoreRoomForPokemon::
	msgbox gText_CajasLlenas, MSGBOX_DEFAULT
	release
	end

PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	return

PlayersHouse_1F_EventScript_EnterHouseMovingIn::
	end

PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
	return

PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
	return

PlayersHouse_1F_Movement_PlayerWalkIn:
	walk_up
	step_end

PlayersHouse_1F_EventScript_MomGoSeeRoom::
	end

LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
	end

LittlerootTown_MaysHouse_2F_EventScript_WallClock::
	end

PlayersHouse_2F_EventScript_WallClock::
	end

PlayersHouse_2F_EventScript_MomComesUpstairsMale::
	return

PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
	return

PlayersHouse_2F_EventScript_CheckWallClock::
	end

PlayersHouse_2F_EventScript_SetWallClock::
	return

PlayersHouse_2F_Movement_MomEntersMale:
    end

PlayersHouse_2F_Movement_MomExitsMale:
	walk_right
	walk_up
	delay_8
	step_end

PlayersHouse_2F_Movement_MomEntersFemale:
	delay_8
	walk_down
	walk_in_place_faster_right
	delay_16
	delay_8
	walk_right
	step_end

PlayersHouse_2F_Movement_MomExitsFemale:
	walk_left
	walk_up
	delay_8
	step_end

PlayersHouse_1F_EventScript_SetWatchedBroadcast::
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_EventScript_PetalburgGymReportMale::
	end

PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
	end

PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
	return

PlayersHouse_1F_EventScript_WatchGymBroadcast::
	return

PlayersHouse_1F_Movement_MomApproachDadMale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomApproachDadFemale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerMale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerFemale:
	walk_left
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
	walk_up
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
	walk_up
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
	walk_left
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
	walk_right
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatMale:
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatFemale:
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_EventScript_Mom::
	end

PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
	end

PlayersHouse_1F_EventScript_TryRegisterMom::
	end

PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
    end

PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
	end

PlayersHouse_1F_EventScript_MomHealsParty::
	end

PlayersHouse_1F_EventScript_SeeYouHoney::
	end

PlayersHouse_1F_EventScript_HealParty::
	end

PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
	end

PlayersHouse_1F_EventScript_Vigoroth1::
	end

PlayersHouse_1F_EventScript_Vigoroth2::
	end

PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVMale:
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
	end

@ Never called.
PlayersHouse_1F_EventScript_AirLatiBroadcast::
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
	return

PlayersHouse_1F_EventScript_DadApproachPlayerMale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadApproachPlayerFemale::

PlayersHouse_1F_EventScript_MomApproachDadMale::
	return

PlayersHouse_1F_EventScript_MomApproachDadFemale::
	return

PlayersHouse_1F_EventScript_DadExitsMale::
	return

PlayersHouse_1F_EventScript_DadExitsFemale::
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
	return

PlayersHouse_1F_EventScript_MomApproachPlayerMale::
	return

PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
	return

PlayersHouse_1F_Movement_DadApproachPlayerMale:
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_DadApproachPlayerFemale:
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomMale:
	face_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomFemale:
	face_right
	step_end

PlayersHouse_1F_Movement_DadExitsMale:
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_DadExitsFemale:
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomMale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
	delay_8
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

EventScript_RunningShoesManual::
	end

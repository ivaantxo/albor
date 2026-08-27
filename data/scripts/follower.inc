gText_FollowerLovesYou::
	.string "{VAR_TEXTO_1} is regarding you with\nadoration!$"

gText_WantsToFly::
	.string "{VAR_TEXTO_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

EventScript_Follower::
	lock
	bufferlivemonnickname 0
	playfirstmoncry
	getfolloweraction
	checkpartymove MOVE_FLY
	compare VAR_RESULT 6
	goto_if_eq EventScript_FollowerEnd
	bufferlivemonnickname 0
	msgbox gText_WantsToFly, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_FollowerEnd
	case YES, EventScript_FollowerFly
	case MULTI_B_PRESSED, EventScript_FollowerEnd
EventScript_FollowerFly::
	followerfly
EventScript_FollowerEnd::
	waitfieldeffect FLDEFF_EMOTE
	release
	end

EventScript_FollowerMovement_Heart:
    emote_heart
    step_end

EventScript_FollowerLovesYou::
	applymovement LOCALID_FOLLOWER, EventScript_FollowerMovement_Heart
	waitmovement LOCALID_FOLLOWER
	waitmoncry
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
	return

@ Message address must be loaded into bank 0
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
	faceplayer
EventScript_FollowerGenericSkipFace:
	waitfieldeffect FLDEFF_EMOTE
	message 0x0
	waitmessage
	waitbuttonpress
	return

EnterPokeballMovement::
	enter_pokeball
	step_end

@ Movement scripts below, movements are defined in movement.inc

FollowerSplashMovement::
	jump_in_place_down
	delay_4
	jump_in_place_down
	face_player
	step_end

FollowerShiverVerticalMovement:
	lock_facing_direction
	slide_left
	slide_right
	slide_right
	slide_left
	unlock_facing_direction
	step_end

FollowerShiverHorizontalMovement:
	lock_facing_direction
	slide_up
	slide_down
	slide_down
	slide_up
	unlock_facing_direction
	step_end

FollowerNostalgiaMovement:
	face_away_player
	lock_facing_direction
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	unlock_facing_direction
	face_player
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerSkippingMovement:
	lock_facing_direction
	jump_in_place_down
	delay_4
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerNorth:
	jump_up
	delay_4
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerSouth:
	jump_down
	delay_4
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerEast:
	jump_right
	delay_4
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerWest:
	jump_left
	delay_4
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

FollowerCuddlingNorth:
	face_left
	lock_facing_direction
	walk_up
	walk_in_place_left
	walk_in_place_left
	unlock_facing_direction
	walk_down
	face_player
	step_end

FollowerCuddlingSouth:
	face_right
	lock_facing_direction
	walk_down
	walk_in_place_right
	walk_in_place_right
	unlock_facing_direction
	walk_up
	face_player
	step_end

FollowerCuddlingEast:
	face_down
	lock_facing_direction
	walk_right
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	walk_left
	face_player
	step_end

FollowerCuddlingWest:
	face_down
	lock_facing_direction
	walk_left
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	walk_right
	face_player
	step_end

FollowerGetCloserNorth:
	walk_up
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

FollowerGetCloserSouth:
	walk_down
	delay_16
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

FollowerGetCloserEast:
	walk_right
	delay_16
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

FollowerGetCloserWest:
	walk_left
	delay_16
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FollowerPokeNorth:
	walk_faster_up
	delay_8
	lock_facing_direction
	walk_faster_down
	delay_4
	walk_faster_up
	delay_4
	walk_faster_down
	unlock_facing_direction
	step_end

FollowerPokeSouth:
	walk_faster_down
	delay_8
	lock_facing_direction
	walk_faster_up
	delay_4
	walk_faster_down
	delay_4
	walk_faster_up
	unlock_facing_direction
	step_end

FollowerPokeEast:
	walk_faster_right
	delay_8
	lock_facing_direction
	walk_faster_left
	delay_4
	walk_faster_right
	delay_4
	walk_faster_left
	unlock_facing_direction
	step_end

FollowerPokeWest:
	walk_faster_left
	delay_8
	lock_facing_direction
	walk_faster_right
	delay_4
	walk_faster_left
	delay_4
	walk_faster_right
	unlock_facing_direction
	step_end

FollowerLookAround:
	face_away_player
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	step_end

FollowerLookAway:
	face_away_player
	delay_16
	delay_16
	step_end

FollowerLookAwayBark:
	face_away_player
	lock_facing_direction
	jump_in_place_down
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerLookAwayPokeG:
	face_away_player
	lock_facing_direction
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	step_end

FollowerPokeGround:
	lock_facing_direction
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	step_end

FollowerStartled:
	face_away_player
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	face_player
	step_end

FollowerHopFast:
	jump_in_place_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	face_player
	step_end

FollowerDizzy:
	walk_in_place_left
	walk_in_place_fast_right
	walk_in_place_slow_up
	walk_in_place_fast_down
	delay_4
	face_away_player
	step_end

FollowerLookAroundScared:
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_player
	step_end

FollowerDance:
	lock_facing_direction
	jump_in_place_up
	unlock_facing_direction
	walk_in_place_fast_up
	walk_in_place_fast_left
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_fast_left
	walk_in_place_fast_down
	walk_in_place_fast_right
	jump_in_place_up
	jump_in_place_down
	jump_in_place_up
	face_player
	step_end

@ Movement scripts

EventScript_FollowerIsShivering::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_SOUTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_WEST
	call_if_eq ShiverHorizontal
	compare VAR_FACING, DIR_EAST
	call_if_eq ShiverHorizontal
	goto EventScript_FollowerGeneric

ShiverVertical:
	applymovement LOCALID_FOLLOWER, FollowerShiverVerticalMovement
	waitmovement LOCALID_FOLLOWER
	return

ShiverHorizontal:
	applymovement LOCALID_FOLLOWER, FollowerShiverHorizontalMovement
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerNostalgia::
	applymovement LOCALID_FOLLOWER, FollowerNostalgiaMovement
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerHopping::
	faceplayer
	applymovement LOCALID_FOLLOWER, FollowerSkippingMovement
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGeneric

JumpOnN:
	applymovement LOCALID_FOLLOWER, FollowerJumpOnPlayerNorth
	waitmovement LOCALID_FOLLOWER
	return

JumpOnS:
	applymovement LOCALID_FOLLOWER, FollowerJumpOnPlayerSouth
	waitmovement LOCALID_FOLLOWER
	return

JumpOnE:
	applymovement LOCALID_FOLLOWER, FollowerJumpOnPlayerEast
	waitmovement LOCALID_FOLLOWER
	return

JumpOnW:
	applymovement LOCALID_FOLLOWER, FollowerJumpOnPlayerWest
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerJumpOnPlayer::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq JumpOnS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq JumpOnN
	compare VAR_FACING, DIR_WEST
	call_if_eq JumpOnE
	compare VAR_FACING, DIR_EAST
	call_if_eq JumpOnW
	goto EventScript_FollowerGeneric

CuddleN:
	applymovement LOCALID_FOLLOWER, FollowerCuddlingNorth
	waitmovement LOCALID_FOLLOWER
	return

CuddleS:
	applymovement LOCALID_FOLLOWER, FollowerCuddlingSouth
	waitmovement LOCALID_FOLLOWER
	return

CuddleE:
	applymovement LOCALID_FOLLOWER, FollowerCuddlingEast
	waitmovement LOCALID_FOLLOWER
	return

CuddleW:
	applymovement LOCALID_FOLLOWER, FollowerCuddlingWest
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq CuddleS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CuddleN
	compare VAR_FACING, DIR_WEST
	call_if_eq CuddleE
	compare VAR_FACING, DIR_EAST
	call_if_eq CuddleW
	goto EventScript_FollowerGeneric

ShCuddleN:
	applymovement LOCALID_FOLLOWER FollowerShiverVerticalMovement
	waitmovement LOCALID_FOLLOWER
	applymovement LOCALID_FOLLOWER FollowerCuddlingNorth
	waitmovement LOCALID_FOLLOWER
	return

ShCuddleS:
	applymovement LOCALID_FOLLOWER FollowerShiverVerticalMovement
	waitmovement LOCALID_FOLLOWER
	applymovement LOCALID_FOLLOWER FollowerCuddlingSouth
	waitmovement LOCALID_FOLLOWER
	return

ShCuddleE:
	applymovement LOCALID_FOLLOWER FollowerShiverHorizontalMovement
	waitmovement LOCALID_FOLLOWER
	applymovement LOCALID_FOLLOWER FollowerCuddlingEast
	waitmovement LOCALID_FOLLOWER
	return

ShCuddleW:
	applymovement LOCALID_FOLLOWER FollowerShiverHorizontalMovement
	waitmovement LOCALID_FOLLOWER
	applymovement LOCALID_FOLLOWER FollowerCuddlingWest
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerShiverCuddling::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq ShCuddleS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq ShCuddleN
	compare VAR_FACING, DIR_WEST
	call_if_eq ShCuddleE
	compare VAR_FACING, DIR_EAST
	call_if_eq ShCuddleW
	goto EventScript_FollowerGeneric

CreepCloserN:
	applymovement LOCALID_FOLLOWER FollowerGetCloserNorth
	waitmovement LOCALID_FOLLOWER
	return

CreepCloserS:
	applymovement LOCALID_FOLLOWER FollowerGetCloserSouth
	waitmovement LOCALID_FOLLOWER
	return

CreepCloserE:
	applymovement LOCALID_FOLLOWER FollowerGetCloserEast
	waitmovement LOCALID_FOLLOWER
	return

CreepCloserW:
	applymovement LOCALID_FOLLOWER FollowerGetCloserWest
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerGetCloser::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq CreepCloserS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CreepCloserN
	compare VAR_FACING, DIR_WEST
	call_if_eq CreepCloserE
	compare VAR_FACING, DIR_EAST
	call_if_eq CreepCloserW
	goto EventScript_FollowerGeneric

PokePlayerN:
	applymovement LOCALID_FOLLOWER FollowerGetCloserNorth
	waitmovement LOCALID_FOLLOWER
	return

PokePlayerS:
	applymovement LOCALID_FOLLOWER FollowerGetCloserSouth
	waitmovement LOCALID_FOLLOWER
	return

PokePlayerE:
	applymovement LOCALID_FOLLOWER FollowerGetCloserEast
	waitmovement LOCALID_FOLLOWER
	return

PokePlayerW:
	applymovement LOCALID_FOLLOWER FollowerGetCloserWest
	waitmovement LOCALID_FOLLOWER
	return

EventScript_FollowerPokingPlayer::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq PokePlayerS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq PokePlayerN
	compare VAR_FACING, DIR_WEST
	call_if_eq PokePlayerE
	compare VAR_FACING, DIR_EAST
	call_if_eq PokePlayerW
	goto EventScript_FollowerGeneric

EventScript_FollowerLookAround::
	applymovement LOCALID_FOLLOWER FollowerLookAround
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerLookAway::
	applymovement LOCALID_FOLLOWER FollowerLookAway
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayBark::
	applymovement LOCALID_FOLLOWER FollowerLookAwayBark
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayPoke::
	applymovement LOCALID_FOLLOWER FollowerLookAwayPokeG
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerPokeGround::
	faceplayer
	applymovement LOCALID_FOLLOWER FollowerPokeGround
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerStartled::
	applymovement LOCALID_FOLLOWER FollowerStartled
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFastHopping::
	applymovement LOCALID_FOLLOWER FollowerHopFast
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerDizzy::
	applymovement LOCALID_FOLLOWER FollowerDizzy
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAroundScared::
	applymovement LOCALID_FOLLOWER FollowerLookAroundScared
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerDance::
	faceplayer
	applymovement LOCALID_FOLLOWER FollowerDance
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceUp::
	applymovement LOCALID_FOLLOWER Common_Movement_FaceUp
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_FollowerFaceDown
	case DIR_NORTH, EventScript_FollowerFaceUp
	case DIR_WEST, EventScript_FollowerFaceLeft
	case DIR_EAST, EventScript_FollowerFaceRight
	goto EventScript_FollowerGeneric

EventScript_FollowerFaceDown:
	applymovement LOCALID_FOLLOWER Common_Movement_FaceDown
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceLeft:
	applymovement LOCALID_FOLLOWER Common_Movement_FaceLeft
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceRight:
	applymovement LOCALID_FOLLOWER Common_Movement_FaceRight
	waitmovement LOCALID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

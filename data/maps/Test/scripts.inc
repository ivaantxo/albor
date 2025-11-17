Test_MapScripts::
	.byte 0

Test_EventScript_Arcanine::
    lock
    faceplayer
    msgbox Text_ArcanineRoar, MSGBOX_DEFAULT
    callnative Script_ArcanineTransparentAndFree
    release
    end

Text_ArcanineRoar:
	.string "Grrrrrr.$"

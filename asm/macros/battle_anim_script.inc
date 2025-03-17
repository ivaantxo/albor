@ commands

	.macro loadspritegfx tag:req
	.byte 0
	.2byte \tag
	.endm

	.macro unloadspritegfx tag:req
	.byte 1
	.2byte \tag
	.endm

.macro createsprite template:req, anim_battler:req, subpriority_offset:req, argv:vararg
	.byte 2
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro createvisualtask addr:req, priority:req, argv:vararg
	.byte 3
	.4byte \addr
	.byte \priority
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm

	.macro delay frames:req
	.byte 4
	.byte \frames
	.endm

	.macro waitforvisualfinish
	.byte 5
	.endm

	.macro end
	.byte 6
	.endm

	.macro playse se:req
	.byte 7
	.2byte \se
	.endm

	.macro monbg battler:req
	.byte 8
	.byte \battler
	.endm

	.macro clearmonbg battler:req
	.byte 9
	.byte \battler
	.endm

	.macro setalpha eva:req, evb:req
	.byte 10
	.2byte ((\evb) << 8) | (\eva)
	.endm

	.macro blendoff
	.byte 11
	.endm

	.macro call ptr:req
	.byte 12
	.4byte \ptr
	.endm

	.macro return
	.byte 13
	.endm

	.macro setarg argId:req, value:req
	.byte 14
	.byte \argId
	.2byte \value
	.endm

	.macro choosetwoturnanim ptr1:req, ptr2:req
	.byte 15
	.4byte \ptr1
	.4byte \ptr2
	.endm

	.macro jumpifmoveturn value:req, ptr:req
	.byte 16
	.byte \value
	.4byte \ptr
	.endm

	.macro goto ptr:req
	.byte 17
	.4byte \ptr
	.endm

	.macro fadetobg bg:req
	.byte 18
	.byte \bg
	.endm

	.macro restorebg
	.byte 19
	.endm

	.macro waitbgfadeout
	.byte 20
	.endm

	.macro waitbgfadein
	.byte 21
	.endm

	.macro changebg bg:req
	.byte 22
	.byte \bg
	.endm

	.macro playsewithpan se:req, pan:req
	.byte 23
	.2byte \se
	.byte \pan
	.endm

	.macro setpan pan:req
	.byte 24
	.byte \pan
	.endm

	.macro panse se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 25
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro loopsewithpan se:req, pan:req, wait:req, times:req
	.byte 26
	.2byte \se
	.byte \pan
	.byte \wait
	.byte \times
	.endm

	.macro waitplaysewithpan se:req, pan:req, wait:req
	.byte 27
	.2byte \se
	.byte \pan
	.byte \wait
	.endm

	.macro createsoundtask addr:req, argv:vararg
	.byte 28
	.4byte \addr
	.byte (.Lcreatetask_1F_\@_2 - .Lcreatetask_1F_\@_1) / 2
.Lcreatetask_1F_\@_1:
	.2byte \argv
.Lcreatetask_1F_\@_2:
	.endm

	.macro waitsound
	.byte 29
	.endm

	.macro jumpargeq argId:req, value:req, ptr:req
	.byte 30
	.byte \argId
	.2byte \value
	.4byte \ptr
	.endm

	.macro monbg_static battler:req
	.byte 31
	.byte \battler
	.endm

	.macro clearmonbg_static battler:req
	.byte 32
	.byte \battler
	.endm

	.macro fadetobgfromset bgOpponent:req, bgPlayer:req, bgContest:req
	.byte 33
	.byte \bgOpponent
	.byte \bgPlayer
	.byte \bgContest
	.endm

	.macro panse_adjustnone se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 34
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro panse_adjustall se:req, currentPan:req, targetPan:req, incrementPan:req, delay:req
	.byte 35
	.2byte \se
	.byte \currentPan
	.byte \targetPan
	.byte \incrementPan
	.byte \delay
	.endm

	.macro splitbgprio battler:req
	.byte 36
	.byte \battler
	.endm

	.macro splitbgprio_all
	.byte 37
	.endm

	.macro splitbgprio_foes battler:req
	.byte 38
	.byte \battler
	.endm

	.macro invisible battler:req
	.byte 39
	.byte \battler
	.endm

	.macro visible battler:req
	.byte 40
	.byte \battler
	.endm

	.macro stopsound
	.byte 41
	.endm

	@ same as createvisualtask except takes in battlerargindex, which is the battle anim arg index of the battler to loop through
	.macro createvisualtaskontargets addr:req, priority:req, battlerargindex:req, argv:vararg
	.byte 42
	.4byte \addr
	.byte \priority
	.byte \battlerargindex
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2	@ num_args
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm

	@ same as createsprite except takes in battlerargindex, which is the battle anim arg index of the battler to loop through
	.macro createspriteontargets template:req, anim_battler:req, subpriority_offset:req, battlerargindex:req, argv:vararg
	.byte 43
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte 0x80 | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte \battlerargindex
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	@ does not overwrite gBattleAnimArgs[battlerargindex], some sprite templates are too dependent on the value (e.g. heal block)
	.macro createspriteontargets_onpos template:req, anim_battler:req, subpriority_offset:req, battlerargindex:req, argv:vararg
	.byte 44
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte 0x80 | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte \battlerargindex
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

	.macro createdragondartsprite anim_battler:req, subpriority_offset:req, argv:vararg
	.byte 45
	.if \anim_battler == ANIM_TARGET
	.byte ANIMSPRITE_IS_TARGET | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

@ useful macros
	.macro jumpreteq value:req, ptr:req
	jumpargeq ARG_RET_ID, \value, \ptr
	.endm

	.macro jumprettrue ptr:req
	jumpreteq TRUE, \ptr
	.endm

	.macro jumpretfalse ptr:req
	jumpreteq FALSE, \ptr
	.endm

	.macro saltasientrenador ptr:req
	createvisualtask AnimTask_EsContraEntrenador, 0
	jumprettrue \ptr
	.endm

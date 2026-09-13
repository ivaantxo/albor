# GBA rom header
TITLE       := POKEMON EMER
GAME_CODE   := BPEE
MAKER_CODE  := 01
REVISION    := 0

# `File name`.gba
FILE_NAME := albor
BUILD_DIR := build

# Prueba las selecciones sin reemplazar graphics/pokemon ni la ROM habitual.
BW_SPRITES ?= 0
ifeq ($(BW_SPRITES),1)
FILE_NAME := albor_bw
BUILD_DIR := build_bw
endif

# Default make rule
all: rom

TOOLCHAIN := $(DEVKITARM)

PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
OBJDUMP := $(PREFIX)objdump
AS := $(PREFIX)as
LD := $(PREFIX)ld

CPP := $(PREFIX)cpp

ROM_NAME := $(FILE_NAME).gba
OBJ_DIR_NAME := $(BUILD_DIR)/modern

ELF_NAME := $(ROM_NAME:.gba=.elf)
MAP_NAME := $(ROM_NAME:.gba=.map)

# Pick our active variables
ROM := $(ROM_NAME)
OBJ_DIR := $(OBJ_DIR_NAME)
ELF := $(ROM:.gba=.elf)
MAP := $(ROM:.gba=.map)
SYM := $(ROM:.gba=.sym)

# Commonly used directories
#
# asm/ no esta: solo guarda .inc de macros, no queda ni un .s suelto que ensamblar, y
# las reglas que lo recorrian no producian nada. Los .s vivos estan en src/ y en data/.
C_SUBDIR = src
DATA_SRC_SUBDIR = src/data
DATA_ASM_SUBDIR = data
SONG_SUBDIR = sound/songs
MID_SUBDIR = sound/songs/midi

C_BUILDDIR = $(OBJ_DIR)/$(C_SUBDIR)
DATA_ASM_BUILDDIR = $(OBJ_DIR)/$(DATA_ASM_SUBDIR)
SONG_BUILDDIR = $(OBJ_DIR)/$(SONG_SUBDIR)
MID_BUILDDIR = $(OBJ_DIR)/$(MID_SUBDIR)

SHELL := bash -o pipefail

# Set flags for tools
ASFLAGS := -mcpu=arm7tdmi --defsym MODERN=1

INCLUDE_DIRS := include
INCLUDE_CPP_ARGS := $(INCLUDE_DIRS:%=-iquote %)
INCLUDE_SCANINC_ARGS := $(INCLUDE_DIRS:%=-I %)

O_LEVEL ?= 2
CPPFLAGS := $(INCLUDE_CPP_ARGS) -Wno-trigraphs -DMODERN=1 -std=gnu17
ifeq ($(BW_SPRITES),1)
CPPFLAGS += -DALBOR_BW_SPRITES=1 -I desarrollo/chat_gpt/generated
endif
ARMCC := $(PREFIX)gcc
PATH_ARMCC := PATH="$(PATH)" $(ARMCC)
CC1 := $(shell $(PATH_ARMCC) --print-prog-name=cc1) -quiet
override CFLAGS += -mthumb -mthumb-interwork -O$(O_LEVEL) -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -fno-toplevel-reorder -Wno-pointer-to-int-cast -std=gnu17 -Werror -Wall -Wno-strict-aliasing -Wno-attribute-alias -Woverride-init
LIBPATH := -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libgcc.a))" -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libnosys.a))" -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libc.a))"
LIB := $(LIBPATH) -lc -lnosys -lgcc -L../../libagbsyscall -lagbsyscall

# Variable filled out in other make files
AUTO_GEN_TARGETS :=
include make_tools.mk
# Tool executables
GFX          := $(TOOLS_DIR)/gbagfx/gbagfx
AIF          := $(TOOLS_DIR)/aif2pcm/aif2pcm
MID          := $(TOOLS_DIR)/mid2agb/mid2agb
SCANINC      := $(TOOLS_DIR)/scaninc/scaninc
PREPROC      := $(TOOLS_DIR)/preproc/preproc
FIX          := $(TOOLS_DIR)/gbafix/gbafix
MAPJSON      := $(TOOLS_DIR)/mapjson/mapjson
JSONPROC     := $(TOOLS_DIR)/jsonproc/jsonproc
TRAINERPROC  := $(TOOLS_DIR)/trainerproc/trainerproc
PATCHELF     := $(TOOLS_DIR)/patchelf/patchelf
FAMICONV     := $(TOOLS_DIR)/superfamiconv/superfamiconv

PERL := perl
SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c

MAKEFLAGS += --no-print-directory

# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

RULES_NO_SCAN += libagbsyscall clean clean-assets tidy tidymodern generated clean-generated
# `check` ya no esta: no hay regla que lo defina ni directorio test/ que ejecutar.
.PHONY: all rom modern
.PHONY: $(RULES_NO_SCAN)

infoshell = $(foreach line, $(shell $1 | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))

# Check if we need to scan dependencies based on the chosen rule OR user preference
NODEP ?= 0
# Check if we need to pre-build tools and generate assets based on the chosen rule.
SETUP_PREREQS ?= 1
# Disable dependency scanning for rules that don't need it.
ifneq (,$(MAKECMDGOALS))
  ifeq (,$(filter-out $(RULES_NO_SCAN),$(MAKECMDGOALS)))
    NODEP := 1
    SETUP_PREREQS := 0
  endif
endif

# Si estos dos pasos previos fallan, hay que PARAR aqui.
#
# Antes se miraba $(.SHELLSTATUS), que existe desde Make 4.2. El make que trae macOS es
# la 3.81 de 2006: alli esa variable no la pone nadie, un `?= 0` la dejaba a cero para
# siempre y el `ifneq` no saltaba JAMAS. Un fallo al construir las herramientas seguia
# adelante en silencio y reventaba mas tarde y en otro sitio, culpando a un archivo que
# no tenia nada que ver.
#
# El centinela funciona en las dos. Va pegado al `make` y DENTRO de las llaves, no al
# final de la tuberia: el pipefail de SHELL no llega hasta $(shell) en la 3.81, asi que
# el estado de la tuberia entera es el del sed y siempre vale cero. Colgado del make,
# la palabra entra en el propio texto de salida y da igual quien cierre la tuberia.
#
# La salida se imprime igual que antes, linea a linea, con los espacios disfrazados
# para que $(shell) no las junte todas en una.
CENTINELA_FALLO := __FALLO_DEL_PASO_PREVIO__

ifeq ($(SETUP_PREREQS),1)
  # If set on: Default target or a rule requiring a scan
  # Forcibly execute `make tools` since we need them for what we are doing.
  SALIDA_TOOLS := $(shell { $(MAKE) -f make_tools.mk 2>&1 || echo $(CENTINELA_FALLO); } | sed "s/ /__SPACE__/g")
  $(foreach line, $(SALIDA_TOOLS), $(info $(subst __SPACE__, ,$(line))))
  ifneq (,$(findstring $(CENTINELA_FALLO),$(SALIDA_TOOLS)))
    $(error Errors occurred while building tools. See error messages above for more details)
  endif
  # Oh and also generate mapjson sources before we use `SCANINC`.
  SALIDA_GENERATED := $(shell { $(MAKE) generated 2>&1 || echo $(CENTINELA_FALLO); } | sed "s/ /__SPACE__/g")
  $(foreach line, $(SALIDA_GENERATED), $(info $(subst __SPACE__, ,$(line))))
  ifneq (,$(findstring $(CENTINELA_FALLO),$(SALIDA_GENERATED)))
    $(error Errors occurred while generating map-related sources. See error messages above for more details)
  endif
endif

# Collect sources
C_SRCS_IN := $(wildcard $(C_SUBDIR)/*.c $(C_SUBDIR)/*/*.c $(C_SUBDIR)/*/*/*.c)
C_SRCS := $(foreach src,$(C_SRCS_IN),$(if $(findstring .inc.c,$(src)),,$(src)))
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

C_ASM_SRCS := $(wildcard $(C_SUBDIR)/*.s $(C_SUBDIR)/*/*.s $(C_SUBDIR)/*/*/*.s)
C_ASM_OBJS := $(patsubst $(C_SUBDIR)/%.s,$(C_BUILDDIR)/%.o,$(C_ASM_SRCS))

# get all the data/*.s files EXCEPT the ones with specific rules
REGULAR_DATA_ASM_SRCS := $(filter-out $(DATA_ASM_SUBDIR)/maps.s $(DATA_ASM_SUBDIR)/map_events.s, $(wildcard $(DATA_ASM_SUBDIR)/*.s))

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_SUBDIR)/*.s)
DATA_ASM_OBJS := $(patsubst $(DATA_ASM_SUBDIR)/%.s,$(DATA_ASM_BUILDDIR)/%.o,$(DATA_ASM_SRCS))

SONG_SRCS := $(wildcard $(SONG_SUBDIR)/*.s)
SONG_OBJS := $(patsubst $(SONG_SUBDIR)/%.s,$(SONG_BUILDDIR)/%.o,$(SONG_SRCS))

MID_SRCS := $(wildcard $(MID_SUBDIR)/*.mid)
MID_OBJS := $(patsubst $(MID_SUBDIR)/%.mid,$(MID_BUILDDIR)/%.o,$(MID_SRCS))

OBJS     := $(C_OBJS) $(C_ASM_OBJS) $(DATA_ASM_OBJS) $(SONG_OBJS) $(MID_OBJS)
OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJS))

SUBDIRS  := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(SUBDIRS))

# Pretend rules that are actually flags defer to `make all`
modern: all

# Other rules
rom: $(ROM)

syms: $(SYM)

clean: tidy clean-tools clean-check-tools clean-generated clean-assets
	@$(MAKE) clean -C libagbsyscall

clean-assets:
	rm -f $(MID_SUBDIR)/*.s
	rm -f $(DATA_ASM_SUBDIR)/layouts/layouts.inc $(DATA_ASM_SUBDIR)/layouts/layouts_table.inc
	rm -f $(DATA_ASM_SUBDIR)/maps/connections.inc $(DATA_ASM_SUBDIR)/maps/events.inc $(DATA_ASM_SUBDIR)/maps/groups.inc $(DATA_ASM_SUBDIR)/maps/headers.inc $(DATA_SRC_SUBDIR)/map_group_count.h
	find sound -iname '*.bin' -exec rm {} +
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.rl' -o -iname '*.latfont' \) -exec rm {} +
	find $(DATA_ASM_SUBDIR)/maps \( -iname 'connections.inc' -o -iname 'events.inc' -o -iname 'header.inc' \) -exec rm {} +

tidy: tidymodern

tidymodern:
	rm -f $(ROM_NAME) $(ELF_NAME) $(MAP_NAME)
	rm -rf $(OBJ_DIR_NAME)

# Other rules
include graphics_file_rules.mk
include entrenadores_rules.mk
include map_data_rules.mk
include spritesheet_rules.mk
include json_data_rules.mk
include audio_rules.mk

ifeq ($(BW_SPRITES),1)
BW_GENERATED := desarrollo/chat_gpt/generated
ifeq ($(wildcard $(BW_GENERATED)/assets.mk),)
$(error Ejecuta primero: python3 desarrollo/chat_gpt/integrar.py)
endif
include $(BW_GENERATED)/assets.mk
$(BW_GENERATED)/assets.mk: src/data/pokemon/species_info.h src/data/pokemon/animaciones_pokemon.h species.txt desarrollo/chat_gpt/integrar.py desarrollo/chat_gpt/catalog.py desarrollo/chat_gpt/timing.py $(BW_INPUTS) $(wildcard $(BW_SELECTIONS))
	python3 desarrollo/chat_gpt/integrar.py
$(C_BUILDDIR)/pokemon.o: $(BW_GENERATED)/species_info_bw.h $(BW_GENERATED)/graphics_bw.h $(BW_GENERATED)/animaciones_bw.h $(BW_ASSETS)
endif

# NOTE: Tools must have been built prior (FIXME)
# so you can't really call this rule directly
generated: $(AUTO_GEN_TARGETS)
	@:

%.s:   ;
%.png: ;
%.pal: ;
%.aif: ;

%.1bpp:   %.png  ; $(GFX) $< $@
%.4bpp:   %.png  ; $(GFX) $< $@
%.8bpp:   %.png  ; $(GFX) $< $@
%.gbapal: %.pal  ; $(GFX) $< $@
%.gbapal: %.png  ; $(GFX) $< $@
%.lz:     %      ; $(GFX) $< $@
%.rl:     %      ; $(GFX) $< $@

clean-generated:
	@rm -f $(AUTO_GEN_TARGETS)
	@echo "rm -f <AUTO_GEN_TARGETS>"

COMPETITIVE_PARTY_SYNTAX := $(shell PATH="$(PATH)"; echo 'COMPETITIVE_PARTY_SYNTAX' | $(CPP) $(CPPFLAGS) -imacros include/gba/defines.h -imacros include/config/general.h | tail -n1)
ifeq ($(COMPETITIVE_PARTY_SYNTAX),1)
%.h: %.party ; $(CPP) $(CPPFLAGS) -traditional-cpp - < $< | $(TRAINERPROC) -o $@ -i $< -
endif

# A pokedex.c hay que quitarle -fno-toplevel-reorder, y NADA mas. Antes esto era una
# copia a mano de la lista entera con la marca fuera, y la copia llevaba -O2 escrito a
# fuego: make O_LEVEL=0 compilaba todo a cero menos este archivo, y cualquier flag que
# se anadiera arriba no le llegaba.
$(C_BUILDDIR)/pokedex.o: CFLAGS := $(filter-out -fno-toplevel-reorder,$(CFLAGS))
# Annoyingly we can't turn this on just for src/data/trainers.h
$(C_BUILDDIR)/data.o: CFLAGS += -fno-show-column -fno-diagnostics-show-caret

# Dependency rules (for the *.c & *.s sources to .o files)
# Have to be explicit or else missing files won't be reported.

# As a side effect, they're evaluated immediately instead of when the rule is invoked.
# It doesn't look like $(shell) can be deferred so there might not be a better way (Icedude_907: there is soon).

# Archivos C normales y C++ (que usan nullptr)
CXX_SRCS := src/agb_flash_le.c src/agb_flash_1m.c src/agb_flash_mx.c

# Regla general para compilar C/C++ a .o
#
# Los .c normales (no C++) pasan por el mismo tipo de pipeline de tres pasos que los
# .s, y por la misma razón: preproc -i es quien resuelve _("...") e INCBIN_U8/16/32(...)
# (solo tienen definición real dentro del bloque #if defined(__APPLE__)/IDE de global.h).
# Sin este paso, _()/INCBIN_* no resuelven con ningún compilador fuera de un IDE.
$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.c $(PREPROC) charmap.txt
	@mkdir -p $(dir $@)
ifeq ($(filter $<,$(CXX_SRCS)),)
	@echo "CC $<"
	@$(CPP) $(CPPFLAGS) $< | $(PREPROC) -i $< charmap.txt | $(CC1) $(CFLAGS) -o - - | cat - <(echo -e ".text\n\t.align\t2, 0") | $(AS) $(ASFLAGS) -o $@ -
else
	@echo "CXX $<"
	@$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@
endif

# Dependencias
$(C_BUILDDIR)/%.d: $(C_SUBDIR)/%.c
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ $(INCLUDE_SCANINC_ARGS) -I "" $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(C_SRCS:.c=.d))
endif

# Archivos .s dentro de C
#
# Tres pasos, y el orden importa:
#   1. preproc      charmapea los .string y los literales en linea de las macros
#                   de battle_script (ver tools/preproc/asm_file.cpp).
#   2. cpp          resuelve los #include y los #define de include/, que es de
#                   donde salen BATTLE_CMD_*, MOVE_*, y los .if de config/.
#   3. preproc -ie  convierte los enum de C que acaba de traer cpp en constantes
#                   que entiende el ensamblador.
$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.s $(PREPROC) charmap.txt
	@mkdir -p $(dir $@)
	$(PREPROC) $< charmap.txt | $(CPP) $(INCLUDE_CPP_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@

# Lo mismo que para los de data/, y por lo mismo: crt0.s y m4a_1.s traen dentro
# gba_constants.inc, m4a_constants.inc y asm/macros.inc, y sin estas dependencias
# cambiar una de esas constantes deja los .o viejos sin decir nada. La regla %.d de
# mas arriba solo acepta .c, asi que estos se quedaban fuera.
$(C_BUILDDIR)/%.d: $(C_SUBDIR)/%.s
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ $(INCLUDE_SCANINC_ARGS) -I "" $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(C_ASM_SRCS:.s=.d))
endif

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s $(PREPROC) charmap.txt
	@mkdir -p $(dir $@)
	$(PREPROC) $< charmap.txt | $(CPP) $(INCLUDE_CPP_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@

# Sin esto los .s de data/ no se rehacen aunque cambie una constante que usan:
# mas abajo se hace -include de estos .d, pero nadie los generaba. Un scripts de
# animacion viejo junto a una tabla nueva significa que cada animacion carga el
# sprite equivocado, y no se nota hasta que se mira.
$(DATA_ASM_BUILDDIR)/%.d: $(DATA_ASM_SUBDIR)/%.s
	@mkdir -p $(dir $@)
	$(SCANINC) -M $@ $(INCLUDE_SCANINC_ARGS) -I "" $<
	
ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(REGULAR_DATA_ASM_SRCS:.s=.d))
endif

# Linker script
LD_SCRIPT := ld_script.ld
LD_SCRIPT_DEPS :=

# Final rules

# El .a de verdad, no el nombre corto.
#
# `libagbsyscall` es .PHONY, y un prerrequisito falso esta desactualizado SIEMPRE: el
# enlazado, el gbafix y el objcopy de los 16 MB corrian en cada make aunque no hubiera
# cambiado una coma, y la ROM salia con fecha nueva cada vez. Dependiendo del archivo,
# solo corren cuando toca. El nombre corto se queda para poder invocarlo a mano.
LIBAGBSYSCALL := libagbsyscall/libagbsyscall.a

libagbsyscall: $(LIBAGBSYSCALL)

$(LIBAGBSYSCALL): $(wildcard libagbsyscall/*.s) libagbsyscall/Makefile
	@$(MAKE) -C libagbsyscall TOOLCHAIN=$(TOOLCHAIN) MODERN=1

# Elf from object files
$(ELF): $(LD_SCRIPT) $(LD_SCRIPT_DEPS) $(OBJS) $(LIBAGBSYSCALL)
	@cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ../../$< --print-memory-usage -o ../../$@ $(OBJS_REL) $(LIB) | cat
	@echo "cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ../../$< --print-memory-usage -o ../../$@ <objs> <libs> | cat"
	$(FIX) $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent

# Builds the rom from the elf file
$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@
	$(FIX) $@ -p --silent

# Symbol file (`make syms`)
$(SYM): $(ELF)
	$(OBJDUMP) -t $< | sort -u | grep -E "^0[2389]" | $(PERL) -p -e 's/^(\w{8}) (\w).{6} \S+\t(\w{8}) (\S+)$$/\1 \2 \3 \4/g' > $@

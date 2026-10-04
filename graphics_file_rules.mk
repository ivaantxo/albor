TILESETGFXDIR := data/tilesets
FONTGFXDIR := graphics/fonts
INTERFACEGFXDIR := graphics/interface
BTLANMSPRGFXDIR := graphics/battle_anims/sprites
BATINTGFXDIR := graphics/battle_interface
MASKSGFXDIR := graphics/battle_anims/masks
BATTRANSGFXDIR := graphics/battle_transitions
TYPESGFXDIR := graphics/types
BATTYPESGFXDIR := graphics/battle_interface/types
RAYQUAZAGFXDIR := graphics/rayquaza_scene
ROULETTEGFXDIR := graphics/roulette
PKNAVGFXDIR := graphics/pokenav
PKNAVOPTIONSGFXDIR := graphics/pokenav/options
OBJEVENTGFXDIR := graphics/object_events
MISCGFXDIR := graphics/misc
POKEDEXGFXDIR := graphics/pokedex
STARTERGFXDIR := graphics/starter_choose
NAMINGGFXDIR := graphics/naming_screen
TITLESCREENGFXDIR := graphics/title_screen
DIR_MAPAREGION := graphics/mapa_region

types := normal fight flying poison ground rock bug ghost steel fire water grass electric psychic ice dragon dark fairy

### Tilesets ###

# Las paletas de un tileset de albor, juntas y por orden: palettes/00.pal, 01.pal...
# graphics.h las incluye con un solo INCBIN, asi que una paleta nueva no hay que
# apuntarla en ningun sitio. Cada mapa carga solo las que usan sus metatiles: ver
# LoadMapTilesetPalettes en src/fieldmap.c.
.SECONDEXPANSION:
$(TILESETGFXDIR)/%/palettes.gbapal: $$(addsuffix .gbapal,$$(basename $$(wildcard $(TILESETGFXDIR)/$$*/palettes/*.pal)))
	cat $$(printf '%s\n' $^ | sort -V) >$@

### Animaciones de combate ###

# Un sprite de animacion gasta una paleta de 16 colores, y el cargador copia
# siempre 32 bytes. Un png con menos colores generaba un fichero mas corto y se
# leia fuera de el, asi que aqui se rellena hasta 16.
#
# Solo para los sprites que unicamente tienen png: donde hay .pal manda el .pal,
# porque alguno lleva varias paletas seguidas en el mismo fichero -las notas de
# Campana Cura son cinco- y forzar 16 lo dejaria en la primera.
BTLANMSPR_SOLO_PNG := $(patsubst %.png,%.gbapal,\
    $(filter-out $(patsubst %.pal,%.png,$(wildcard $(BTLANMSPRGFXDIR)/*.pal)),\
                 $(wildcard $(BTLANMSPRGFXDIR)/*.png)))

$(BTLANMSPR_SOLO_PNG): %.gbapal: %.png
	$(GFX) $< $@ -num_colors 16

### Fuentes ###

$(FONTGFXDIR)/normal.latfont: $(FONTGFXDIR)/normal.png
	$(GFX) $< $@

$(FONTGFXDIR)/borde.latfont: $(FONTGFXDIR)/borde.png
	$(GFX) $< $@

$(FONTGFXDIR)/gruesa.latfont: $(FONTGFXDIR)/gruesa.png
	$(GFX) $< $@

### Mapa de Región ###

$(DIR_MAPAREGION)/%_base.gbapal: $(DIR_MAPAREGION)/%.png
	$(FAMICONV) palette \
		--mode gba_affine \
		--palettes 1 \
		--colors 48 \
		--in-image $< \
		--out-data $@

$(DIR_MAPAREGION)/empty_112.gbapal:
	dd if=/dev/zero of=$@ bs=1 count=224 status=none

$(DIR_MAPAREGION)/%_padded.gbapal: \
		$(DIR_MAPAREGION)/empty_112.gbapal \
		$(DIR_MAPAREGION)/%_base.gbapal
	cat $^ > $@

$(DIR_MAPAREGION)/%_text.8bpp: \
		$(DIR_MAPAREGION)/%_padded.gbapal \
		$(DIR_MAPAREGION)/%.png
	$(FAMICONV) tiles \
		--mode gba \
		--bpp 8 \
		--in-image $(DIR_MAPAREGION)/$*.png \
		--in-palette $(DIR_MAPAREGION)/$*_padded.gbapal \
		--out-image $(DIR_MAPAREGION)/$*_text_tiles.png \
		--out-data $@

$(DIR_MAPAREGION)/%_affine.8bpp: \
		$(DIR_MAPAREGION)/%_padded.gbapal \
		$(DIR_MAPAREGION)/%.png
	$(FAMICONV) tiles \
		--mode gba_affine \
		--in-image $(DIR_MAPAREGION)/$*.png \
		--in-palette $(DIR_MAPAREGION)/$*_padded.gbapal \
		--out-image $(DIR_MAPAREGION)/$*_affine_tiles.png \
		--out-data $@

$(DIR_MAPAREGION)/%_text.tilemap: \
		$(DIR_MAPAREGION)/%_padded.gbapal \
		$(DIR_MAPAREGION)/%_text.8bpp \
		$(DIR_MAPAREGION)/%.png
	$(FAMICONV) map \
		--mode gba \
		--bpp 8 \
		--map-width 32 \
		--map-height 32 \
		--in-image $(DIR_MAPAREGION)/$*.png \
		--in-palette $(DIR_MAPAREGION)/$*_padded.gbapal \
		--in-tiles $(DIR_MAPAREGION)/$*_text.8bpp \
		--out-data $@

$(DIR_MAPAREGION)/%_affine.tilemap: \
		$(DIR_MAPAREGION)/%_padded.gbapal \
		$(DIR_MAPAREGION)/%_affine.8bpp \
		$(DIR_MAPAREGION)/%.png
	$(FAMICONV) map \
		--mode gba_affine \
		--map-width 64 \
		--map-height 64 \
		--split-width 64 \
		--split-height 64 \
		--in-image $(DIR_MAPAREGION)/$*.png \
		--in-palette $(DIR_MAPAREGION)/$*_padded.gbapal \
		--in-tiles $(DIR_MAPAREGION)/$*_affine.8bpp \
		--out-data $@

### Miscellaneous ###

$(TITLESCREENGFXDIR)/pokemon_logo.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 224

$(TITLESCREENGFXDIR)/emerald_version.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -mwidth 8 -mheight 4

# El contorno de la barra de vida se dibuja como tres subsprites de 32x16, asi que
# los tiles tienen que salir agrupados en metatiles de 4x2 y no en filas completas.
$(BATINTGFXDIR)/barra_salud.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 2

$(BTLANMSPRGFXDIR)/ice_cube.4bpp: $(BTLANMSPRGFXDIR)/ice_cube_0.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_1.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_2.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_3.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/ice_crystals.4bpp: $(BTLANMSPRGFXDIR)/ice_crystals_0.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_1.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_2.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_3.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_4.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/mud_sand.4bpp: $(BTLANMSPRGFXDIR)/mud_sand_0.4bpp \
                                  $(BTLANMSPRGFXDIR)/mud_sand_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/flower.4bpp: $(BTLANMSPRGFXDIR)/flower_0.4bpp \
                                $(BTLANMSPRGFXDIR)/flower_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/spark.4bpp: $(BTLANMSPRGFXDIR)/spark_0.4bpp \
                               $(BTLANMSPRGFXDIR)/spark_1.4bpp
	@cat $^ >$@


$(BATTRANSGFXDIR)/vs_frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 16 -Wnum_tiles

graphics/party_menu/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 62 -Wnum_tiles

$(TYPESGFXDIR)/move_types.4bpp: $(types:%=$(TYPESGFXDIR)/%.4bpp)
	@cat $^ >$@

$(TYPESGFXDIR)/move_types.gbapal: $(TYPESGFXDIR)/move_types_1.gbapal \
                                  $(TYPESGFXDIR)/move_types_2.gbapal
	@cat $^ >$@

$(BATTYPESGFXDIR)/icon_types.4bpp: $(types:%=$(BATTYPESGFXDIR)/%.4bpp)
	@cat $^ >$@

$(BATTYPESGFXDIR)/icon_types.gbapal: $(BATTYPESGFXDIR)/icon_types_1.gbapal \
                                     $(BATTYPESGFXDIR)/icon_types_2.gbapal \
                                     $(BATTYPESGFXDIR)/icon_types_3.gbapal 
	@cat $^ >$@

graphics/bag/menu.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_2/rayquaza.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 227 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_2/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 313 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_3/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 124 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_4/streaks.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 19 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_4/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 155 -Wnum_tiles

graphics/picture_frame/lobby.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 86 -Wnum_tiles

$(ROULETTEGFXDIR)/roulette_tilt.4bpp: $(ROULETTEGFXDIR)/shroomish.4bpp \
                                      $(ROULETTEGFXDIR)/tailow.4bpp
	@cat $^ >$@

$(ROULETTEGFXDIR)/wheel_icons.4bpp: $(ROULETTEGFXDIR)/wynaut.4bpp \
                                    $(ROULETTEGFXDIR)/azurill.4bpp \
                                    $(ROULETTEGFXDIR)/skitty.4bpp \
                                    $(ROULETTEGFXDIR)/makuhita.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/regis.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(BATTRANSGFXDIR)/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 938 -Wnum_tiles

### Pokémon Storage System ###

$(INTERFACEGFXDIR)/outline_cursor.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 8 -Wnum_tiles

### Pokenav ###

$(PKNAVOPTIONSGFXDIR)/options.4bpp: $(PKNAVOPTIONSGFXDIR)/hoenn_map.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/condition.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/match_call.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/ribbons.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/switch_off.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/party.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/search.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cool.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/beauty.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cute.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/smart.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/tough.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cancel.4bpp
	@cat $^ >$@

$(PKNAVGFXDIR)/header.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAVGFXDIR)/device_outline.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAVGFXDIR)/match_call/ui.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 13 -Wnum_tiles

$(NAMINGGFXDIR)/cursor.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMINGGFXDIR)/cursor_squished.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMINGGFXDIR)/cursor_filled.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

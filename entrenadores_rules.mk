# Graficos de entrenador, una carpeta por nombre.
#
#   graphics/entrenadores/<nombre>/front.png    80x80 por frame, de 1 a 3 frames
#   graphics/entrenadores/<nombre>/back.png     80x80 por frame, 3 frames, solo
#                                               los cuatro protagonistas
#   graphics/entrenadores/<nombre>/ow.png       32x32 por frame, 33 frames
#   graphics/entrenadores/<nombre>/paleta.pal   UNA paleta para los tres dibujos
#
# Las hojas son HORIZONTALES: un frame detras de otro, que es como salen del
# programa de dibujo. gbagfx lee la imagen de corrido, de izquierda a derecha y de
# arriba abajo, asi que sin ayuda mezclaria los tiles de un frame con los del
# siguiente: la primera fila de tiles de una hoja de 33 frames son cuatro tiles del
# frame 0, luego cuatro del 1, y asi. Con -mwidth/-mheight se le dice de que tamano
# son los bloques y los saca agrupados, cada frame entero y seguido.
#
# Por eso el arte NO hay que rehacerlo en vertical, que es como lo pide el resto del
# juego. Comprobado frame a frame: los 33 vuelven a salir identicos.
DIR_ENTRENADORES := graphics/entrenadores

# 80x80 son 10x10 tiles.
$(DIR_ENTRENADORES)/%/front.4bpp: $(DIR_ENTRENADORES)/%/front.png
	$(GFX) $< $@ -mwidth 10 -mheight 10

$(DIR_ENTRENADORES)/%/back.4bpp: $(DIR_ENTRENADORES)/%/back.png
	$(GFX) $< $@ -mwidth 10 -mheight 10

# 32x32 son 4x4 tiles.
$(DIR_ENTRENADORES)/%/ow.4bpp: $(DIR_ENTRENADORES)/%/ow.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

# La paleta la cubre la regla general %.gbapal: %.pal del Makefile, y la compresion
# de los pics de combate la regla general %.lz: %. El OW va sin comprimir, que se
# carga por tiles sueltos.

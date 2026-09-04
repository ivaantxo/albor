#ifndef GUARD_CONSTANTS_POKEMON_SPRITE_VISUALIZER_H
#define GUARD_CONSTANTS_POKEMON_SPRITE_VISUALIZER_H

//Defines
#define VISUALIZER_MON_BACK_X 62
#define VISUALIZER_MON_BACK_Y 80
#define VISUALIZER_ICON_X 224
#define VISUALIZER_ICON_Y 144

#define MODIFY_DIGITS_MAX 4
#define MODIFY_DIGITS_ARROW_X 129
#define MODIFY_DIGITS_ARROW1_Y 94
#define MODIFY_DIGITS_ARROW2_Y 113

#define OPTIONS_ARROW_1_X 4
#define OPTIONS_ARROW_2_X 236
#define OPTIONS_ARROW_Y 119

#define GENDER_MALE 0
#define GENDER_FEMALE 1
#define MON_PIC_BACK 0
#define MON_PIC_FRONT 1

// Cuanto puede alejarse del valor de la especie el ajuste de altura del visor.
//
// Era 20 y NO por ningun motivo del juego: los campos son u8, y en species_info.h ya
// hay espaldas puestas a 21 y a 22, o sea por encima del tope de la herramienta. Era
// solo el limite del mando.
//
// Ahora es la altura del pic, que si es un limite con sentido: pasado eso el dibujo
// se ha ido entero de su sitio. Importa con los sprites recortados a ras del borde de
// abajo, donde la especie parte de cero y los 20 de antes eran todo el recorrido que
// habia hacia arriba.
#define MAX_Y_OFFSET MON_PIC_HEIGHT

//Windows
#define WIN_NAME_NUMBERS 0
#define WIN_INSTRUCTIONS 1
#define WIN_BOTTOM_LEFT 2
#define WIN_BOTTOM_RIGHT 3
#define WIN_END 4

#endif // GUARD_CONSTANTS_POKEMON_SPRITE_VISUALIZER_H

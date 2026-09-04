#ifndef GUARD_CONSTANTS_ETIQUETAS_H
#define GUARD_CONSTANTS_ETIQUETAS_H

// Las etiquetas de sprite -tileTag y paletteTag- son un unico espacio de nombres
// para todo el juego: quien reserva tiles o una ranura de paleta lo hace bajo un
// numero, y dos sistemas que elijan el mismo se pisan. El que carga segundo se
// encuentra la etiqueta ya puesta, se queda con la ranura del otro sin cargar lo
// suyo, y al soltar se lleva por delante la del vecino. Cuesta dar con ello
// porque el sintoma no se parece en nada a la causa.
//
// Por eso van todas aqui y ninguna lleva un numero escrito a mano.
//
// Rangos ocupados que NO salen en esta lista y hay que respetar:
//
//   1 .. 1025          numero de especie: la paleta de un Pokemon en combate se
//                      registra con el suyo (SetMultiuseSpriteTemplateToPokemon)
//   5001 .. 6025       lo mismo en variocolor (especie + SPECIES_SHINY_TAG)
//   10000 .. 10999     sprites de animacion de combate (ANIM_SPRITES_START)
//   0xFFFF             TAG_NONE, "sin etiqueta"
//
// Tiles y paletas llevan tablas separadas, asi que en rigor una etiqueta de
// grafico y una de paleta podrian repetir numero. No se hace: la lista es unica
// a proposito, porque sale gratis -caben 65536- y quita una forma de fallar.

#define ETIQUETAS_INICIO 11000

enum Etiquetas
{
    GFXTAG_DROPS_LOGO = ETIQUETAS_INICIO,
    GFXTAG_EGG,
    GFXTAG_EGG_SHARD,
    GFXTAG_MULTICHOICE_SCROLL_ARROWS,
    GFXTAG_UI,
    GFXTAG_WALL_CLOCK_HAND,
    PALTAG_ARROW,
    PALTAG_DROPS,
    PALTAG_EGG,
    PALTAG_LOGO,
    PALTAG_MULTICHOICE_SCROLL_ARROWS,
    PALTAG_UI,
    PALTAG_WALL_CLOCK_FEMALE,
    PALTAG_WALL_CLOCK_MALE,
    TAG_AREA_MARKER,
    TAG_AREA_UNKNOWN,
    TAG_BAG_SCROLL_ARROW,
    TAG_BATTLE_INTERFACE_SELECTOR,
    TAG_BICYCLE,
    TAG_BRENDAN,
    TAG_BUBBLES,
    TAG_CATEGORY_ICONS,
    TAG_CB_ITEM_ICON,
    TAG_CEILING_CRUMBLE,
    TAG_CONFETTI,
    TAG_CONTORNO_BARRA,
    TAG_DEX_INTERFACE,
    TAG_DIZZY,
    TAG_FLYGON_LATIAS,
    TAG_FLYGON_LATIOS,
    TAG_FLYGON_SILHOUETTE,
    TAG_HELD_ITEM,
    TAG_ICONOS_ESTADO,
    TAG_ICON_TYPES,
    TAG_LIGHTNING,
    TAG_LIST_ARROWS,
    TAG_LVLUP_BANNER_MON_ICON,
    TAG_MANECTRIC,
    TAG_MARCADOR_JUGADOR1,
    TAG_MARCADOR_JUGADOR2,
    TAG_MARCADOR_OPONENTE1,
    TAG_MARCADOR_OPONENTE2,
    TAG_MARCADOR_PAL,
    TAG_MARCADOR_PAL_PARPADEO,
    TAG_MAY,
    TAG_MODE_ARROWS,
    TAG_MON_MARKINGS,
    TAG_MON_STATUS,
    TAG_MOVE_SELECTOR,
    TAG_MOVE_TYPES,
    TAG_MOVING_SCENERY,
    TAG_PARTICLES_BEASTBALL,
    TAG_PARTICLES_CHERISHBALL,
    TAG_PARTICLES_DIVEBALL,
    TAG_PARTICLES_DREAMBALL,
    TAG_PARTICLES_DUSKBALL,
    TAG_PARTICLES_FASTBALL,
    TAG_PARTICLES_FRIENDBALL,
    TAG_PARTICLES_GREATBALL,
    TAG_PARTICLES_HEALBALL,
    TAG_PARTICLES_HEAVYBALL,
    TAG_PARTICLES_LEVELBALL,
    TAG_PARTICLES_LOVEBALL,
    TAG_PARTICLES_LUREBALL,
    TAG_PARTICLES_LUXURYBALL,
    TAG_PARTICLES_MASTERBALL,
    TAG_PARTICLES_MOONBALL,
    TAG_PARTICLES_NESTBALL,
    TAG_PARTICLES_NETBALL,
    TAG_PARTICLES_PARKBALL,
    TAG_PARTICLES_POKEBALL,
    TAG_PARTICLES_PREMIERBALL,
    TAG_PARTICLES_QUICKBALL,
    TAG_PARTICLES_REPEATBALL,
    TAG_PARTICLES_SAFARIBALL,
    TAG_PARTICLES_SPORTBALL,
    TAG_PARTICLES_TIMERBALL,
    TAG_PARTICLES_ULTRABALL,
    TAG_POCKET_SCROLL_ARROW,
    TAG_POKEBALL_SELECT,
    TAG_PORYGON,
    TAG_RAYQUAZA_ORB,
    TAG_SAVING_ANIMATION,
    TAG_SMOKESCREEN,
    TAG_SOMBRA_PAL,
    TAG_STARTER_CIRCLE,
    TAG_STAT_BAR,
    TAG_STAT_BAR_BG,
    TAG_SWAP_LINE,
    TAG_TORCHIC,
    TAG_VOLBEAT,
    TAG_VS_LETTER,
    TAG_VS_LETTERS,

    // Estaban en un enum suelto de item_menu_icons.c.
    TAG_BAG_GFX,
    TAG_ROTATING_BALL_GFX,
    TAG_ITEM_ICON_ALT,

    // Estaban en enums sueltos, cada pantalla eligiendo su numero. Tres de
    // ellos caian dentro del rango de especies -la teleferico arrancaba en 1,
    // o sea Bulbasaur- y era cuestion de tiempo que mordieran.
    // El clima reparte sus graficos y su paleta desde aqui. La sombra del
    // overworld y la transicion de combate piden PALTAG_WEATHER a proposito:
    // comparten la paleta del clima, que es la que lleva la mezcla.
    GFXTAG_CLOUD,                      // field_weather.h
    GFXTAG_FOG_H,                      // field_weather.h
    GFXTAG_ASH,                        // field_weather.h
    GFXTAG_FOG_D,                      // field_weather.h
    GFXTAG_SANDSTORM,                  // field_weather.h
    GFXTAG_BUBBLE,                     // field_weather.h
    GFXTAG_RAIN,                       // field_weather.h
    PALTAG_SOMBRA,                     // la sombra del overworld, ya no presta la del clima
    PALTAG_WEATHER,                    // field_weather.h
    PALTAG_WEATHER_2,                  // field_weather.h
    TAG_CONDITION_MON,                 // menu_specialized.h
    TAG_CONDITION_BALL,                // menu_specialized.h
    TAG_CONDITION_CANCEL,              // menu_specialized.h
    TAG_CONDITION_BALL_PLACEHOLDER,    // menu_specialized.h
    TAG_CONDITION_SPARKLE,             // menu_specialized.h
    TAG_CONDITION_MON_MARKINGS,        // menu_specialized.h
    TAG_CONDITION_MARKINGS_MENU,       // menu_specialized.h
    TAG_CONDITION_MARKINGS_MENU_2,     // menu_specialized.h
    TAG_CABLE_CAR,                     // cable_car.c
    TAG_DOOR,                          // cable_car.c
    TAG_CABLE,                         // cable_car.c
    TAG_PLAYER_ICON,                   // field_region_map.c
    TAG_CURSOR,                        // field_region_map.c
    GFXTAG_BACK_BUTTON,                // naming_screen.c
    GFXTAG_OK_BUTTON,                  // naming_screen.c
    GFXTAG_PAGE_SWAP_FRAME,            // naming_screen.c
    GFXTAG_PAGE_SWAP_BUTTON,           // naming_screen.c
    GFXTAG_PAGE_SWAP_UPPER,            // naming_screen.c
    GFXTAG_PAGE_SWAP_LOWER,            // naming_screen.c
    GFXTAG_PAGE_SWAP_OTHERS,           // naming_screen.c
    GFXTAG_CURSOR,                     // naming_screen.c
    GFXTAG_CURSOR_SQUISHED,            // naming_screen.c
    GFXTAG_CURSOR_FILLED,              // naming_screen.c
    GFXTAG_INPUT_ARROW,                // naming_screen.c
    GFXTAG_UNDERSCORE,                 // naming_screen.c
    PALTAG_MENU,                       // naming_screen.c
    PALTAG_PAGE_SWAP_LOWER,            // naming_screen.c
    PALTAG_PAGE_SWAP_OTHERS,           // naming_screen.c
    PALTAG_CURSOR,                     // naming_screen.c
    PALTAG_BACK_BUTTON,                // naming_screen.c
    PALTAG_OK_BUTTON,                  // naming_screen.c
    TAG_POKEBALL,                      // party_menu.c
    TAG_POKEBALL_SMALL,                // party_menu.c
    TAG_STATUS_ICONS,                  // party_menu.c
    PALTAG_DISPLAY_MON,                // pokemon_storage_system.c
    PALTAG_MISC,                       // pokemon_storage_system.c
    PALTAG_BOX_TITLE,                  // pokemon_storage_system.c
    PALTAG_ITEM_ICON_0,                // pokemon_storage_system.c
    PALTAG_ITEM_ICON_1,                // pokemon_storage_system.c
    GFXTAG_DISPLAY_MON,                // pokemon_storage_system.c
    GFXTAG_BOX_TITLE,                  // pokemon_storage_system.c
    GFXTAG_BOX_TITLE_ALT,              // pokemon_storage_system.c
    GFXTAG_ITEM_ICON_0,                // pokemon_storage_system.c
    GFXTAG_ITEM_ICON_1,                // pokemon_storage_system.c
    GFXTAG_CHOOSE_BOX_MENU_SIDES,      // pokemon_storage_system.c
    GFXTAG_MON_ICON,                   // pokemon_storage_system.c
    TAG_FLY_ICON,                      // region_map.c
    TAG_VERSION,                       // title_screen.c
    TAG_PRESS_START_COPYRIGHT,         // title_screen.c
    TAG_LOGO_SHINE,                    // title_screen.c
    PALTAG_PAGE_SWAP_UPPER,
    PALTAG_PAGE_SWAP,
    PALTAG_ITEM_ICON_2,
    GFXTAG_ITEM_ICON_2,
    GFXTAG_CHOOSE_BOX_MENU,
    TAG_SCROLL_ARROW,

    // Bases de un rango: el codigo hace base + n, asi que se les reserva sitio
    // detras y nadie puede colarse en medio.
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ULTIMA = TAG_ITEM_ICON + 63,
    TAG_ITEM_ICON_BASE,
    TAG_ITEM_ICON_BASE_ULTIMA = TAG_ITEM_ICON_BASE + 63,
    TAG_MUSIC_NOTES_TEMP_BASE,
    TAG_MUSIC_NOTES_TEMP_BASE_ULTIMA = TAG_MUSIC_NOTES_TEMP_BASE + 3,

    // El mismo nombre existia en dos pantallas con valores distintos. Separados
    // para que no dependa de que nunca coincidan.
    TAG_FLECHA_LISTA_MT,
    TAG_FLECHA_LISTA_TIENDA,
    TAG_DESTELLO_EVOLUCION,
    TAG_DESTELLO_INTRO,

    ETIQUETA_ICONO_POKEMON,
    ETIQUETA_ICONO_POKEMON_ULTIMA = ETIQUETA_ICONO_POKEMON + PARTY_SIZE - 1,
};

// La paleta del marcador es la del primer jugador, no una aparte.
#define TAG_MARCADOR_PAL TAG_MARCADOR_JUGADOR1

#endif // GUARD_CONSTANTS_ETIQUETAS_H

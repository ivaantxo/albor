#include "global.h"
#include "constants/characters.h"

// Cada fuente son dos cosas: el dibujo de los glifos, que sale del .png, y la
// tabla de cuanto avanza el cursor por cada caracter.
//
// El ancho es el de la caja, no el del dibujo: incluye la columna de sombra -o
// de contorno- que separa una letra de la siguiente. Como casi todas miden lo
// mismo, la tabla se rellena entera con ANCHO y solo se escriben las que se
// salen, siempre como ANCHO ± algo para que se vea de un vistazo cuanto.
//
// Los bytes que no son ningun caracter se quedan con ANCHO: si un texto usa uno
// se vera como un hueco del tamano de una letra, que es facil de detectar.

// El compilador avisa de que una entrada con nombre pisa el relleno del rango.
// Es justo lo que se busca aqui, asi que se calla en este archivo.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverride-init"

ALIGNED(4) const u16 gGlifosFuenteNormal[] = INCBIN_U16("graphics/fonts/normal.latfont");

#define ANCHO 6
ALIGNED(4) const u8 gAnchosFuenteNormal[256] =
{
    [0 ... 255]            = ANCHO,
    [CHAR_SPACE]           = ANCHO - 3,
    [CHAR_1]               = ANCHO - 2,
    [CHAR_BULLET]          = ANCHO - 4,
    [CHAR_COLON]           = ANCHO - 3,
    [CHAR_COMMA]           = ANCHO - 3,
    [CHAR_EXCL_MARK]       = ANCHO - 4,
    [CHAR_I]               = ANCHO - 2,
    [CHAR_INV_EXCL_MARK]   = ANCHO - 4,
    [CHAR_I_ACUTE]         = ANCHO - 2,
    [CHAR_I_CIRCUMFLEX]    = ANCHO - 2,
    [CHAR_I_DIAERESIS]     = ANCHO - 2,
    [CHAR_I_GRAVE]         = ANCHO - 2,
    [CHAR_LEFT_ARROW]      = ANCHO + 1,
    [CHAR_LEFT_PAREN]      = ANCHO - 2,
    [CHAR_OE]              = ANCHO + 1,
    [CHAR_PERIOD]          = ANCHO - 3,
    [CHAR_RIGHT_ARROW]     = ANCHO + 1,
    [CHAR_RIGHT_PAREN]     = ANCHO - 2,
    [CHAR_SEMICOLON]       = ANCHO - 3,
    [CHAR_SGL_QUOTE_LEFT]  = ANCHO - 3,
    [CHAR_SGL_QUOTE_RIGHT] = ANCHO - 3,
    [CHAR_SUPER_E]         = ANCHO - 1,
    [CHAR_SUPER_ER]        = ANCHO + 2,
    [CHAR_SUPER_RE]        = ANCHO + 2,
    [CHAR_f]               = ANCHO - 1,
    [CHAR_i]               = ANCHO - 4,
    [CHAR_i_ACUTE]         = ANCHO - 3,
    [CHAR_i_CIRCUMFLEX]    = ANCHO - 2,
    [CHAR_i_DIAERESIS]     = ANCHO - 2,
    [CHAR_i_GRAVE]         = ANCHO - 3,
    [CHAR_j]               = ANCHO - 2,
    [CHAR_l]               = ANCHO - 3,
    [CHAR_oe]              = ANCHO + 2,
    [CHAR_t]               = ANCHO - 1,
};
#undef ANCHO

ALIGNED(4) const u16 gGlifosFuenteBorde[] = INCBIN_U16("graphics/fonts/borde.latfont");

#define ANCHO 7
ALIGNED(4) const u8 gAnchosFuenteBorde[256] =
{
    [0 ... 255]            = ANCHO,
    [CHAR_SPACE]           = ANCHO - 4,
    [CHAR_1]               = ANCHO - 2,
    [CHAR_BULLET]          = ANCHO - 4,
    [CHAR_COLON]           = ANCHO - 3,
    [CHAR_COMMA]           = ANCHO - 3,
    [CHAR_EXCL_MARK]       = ANCHO - 4,
    [CHAR_I]               = ANCHO - 2,
    [CHAR_INV_EXCL_MARK]   = ANCHO - 4,
    [CHAR_I_ACUTE]         = ANCHO - 2,
    [CHAR_I_CIRCUMFLEX]    = ANCHO - 2,
    [CHAR_I_DIAERESIS]     = ANCHO - 2,
    [CHAR_I_GRAVE]         = ANCHO - 2,
    [CHAR_LEFT_ARROW]      = ANCHO + 1,
    [CHAR_LEFT_PAREN]      = ANCHO - 2,
    [CHAR_OE]              = ANCHO + 1,
    [CHAR_PERIOD]          = ANCHO - 3,
    [CHAR_RIGHT_ARROW]     = ANCHO + 1,
    [CHAR_RIGHT_PAREN]     = ANCHO - 2,
    [CHAR_SEMICOLON]       = ANCHO - 3,
    [CHAR_SGL_QUOTE_LEFT]  = ANCHO - 3,
    [CHAR_SGL_QUOTE_RIGHT] = ANCHO - 3,
    [CHAR_SUPER_E]         = ANCHO - 1,
    [CHAR_SUPER_ER]        = ANCHO + 2,
    [CHAR_SUPER_RE]        = ANCHO + 2,
    [CHAR_f]               = ANCHO - 1,
    [CHAR_i]               = ANCHO - 4,
    [CHAR_i_ACUTE]         = ANCHO - 3,
    [CHAR_i_CIRCUMFLEX]    = ANCHO - 2,
    [CHAR_i_DIAERESIS]     = ANCHO - 2,
    [CHAR_i_GRAVE]         = ANCHO - 3,
    [CHAR_j]               = ANCHO - 2,
    [CHAR_l]               = ANCHO - 3,
    [CHAR_oe]              = ANCHO + 2,
    [CHAR_t]               = ANCHO - 1,
};
#undef ANCHO

ALIGNED(4) const u16 gGlifosFuenteGruesa[] = INCBIN_U16("graphics/fonts/gruesa.latfont");

#define ANCHO 7
ALIGNED(4) const u8 gAnchosFuenteGruesa[256] =
{
    [0 ... 255]            = ANCHO,
    [CHAR_SPACE]           = ANCHO - 4,
    [CHAR_1]               = ANCHO - 2,
    [CHAR_BULLET]          = ANCHO - 5,
    [CHAR_COLON]           = ANCHO - 4,
    [CHAR_COMMA]           = ANCHO - 4,
    [CHAR_DBL_QUOTE_LEFT]  = ANCHO - 1,
    [CHAR_DBL_QUOTE_RIGHT] = ANCHO - 1,
    [CHAR_ELLIPSIS]        = ANCHO - 1,
    [CHAR_EQUALS]          = ANCHO - 1,
    [CHAR_EXCL_MARK]       = ANCHO - 4,
    [CHAR_I]               = ANCHO - 2,
    [CHAR_INV_EXCL_MARK]   = ANCHO - 4,
    [CHAR_I_ACUTE]         = ANCHO - 2,
    [CHAR_I_GRAVE]         = ANCHO - 2,
    [CHAR_LEFT_PAREN]      = ANCHO - 2,
    [CHAR_PERIOD]          = ANCHO - 4,
    [CHAR_RIGHT_PAREN]     = ANCHO - 2,
    [CHAR_SEMICOLON]       = ANCHO - 4,
    [CHAR_SGL_QUOTE_LEFT]  = ANCHO - 4,
    [CHAR_SGL_QUOTE_RIGHT] = ANCHO - 4,
    [CHAR_f]               = ANCHO - 1,
    [CHAR_i]               = ANCHO - 4,
    [CHAR_i_ACUTE]         = ANCHO - 4,
    [CHAR_i_CIRCUMFLEX]    = ANCHO - 2,
    [CHAR_i_DIAERESIS]     = ANCHO - 2,
    [CHAR_i_GRAVE]         = ANCHO - 3,
    [CHAR_j]               = ANCHO - 2,
    [CHAR_l]               = ANCHO - 3,
    [CHAR_t]               = ANCHO - 1,
};
#undef ANCHO

#pragma GCC diagnostic pop

#ifndef GUARD_RGB_H
#define GUARD_RGB_H

#define GET_R(color) ((color) & 31)
#define GET_G(color) (((color) >> 5) & 31)
#define GET_B(color) (((color) >> 10) & 31)

#define RGB(r, g, b)  ((r) | ((g) << 5) | ((b) << 10))
#define RGB2(r, g, b) (((b) << 10) | ((g) << 5) | (r))
#define _RGB(r, g, b) ((((b) & 31) << 10) + (((g) & 31) << 5) + ((r) & 31))
#define RGB2GBA(r, g, b) (((r >> 3) & 31) | (((g >> 3) & 31) << 5) | (((b >> 3) & 31) << 10))

#define RGB_ALPHA       (1 << 15)
#define IS_ALPHA(color) ((color) & RGB_ALPHA)

#define RGB_BLACK      RGB(0, 0, 0)
#define RGB_WHITE      RGB(31, 31, 31)
#define RGB_RED        RGB(31, 0, 0)
#define RGB_GREEN      RGB(0, 31, 0)
#define RGB_BLUE       RGB(0, 0, 31)
#define RGB_PURPLE     RGB(24, 0, 24)
#define RGB_YELLOW     RGB(31, 31, 0)
#define RGB_MAGENTA    RGB(31, 0, 31)
#define RGB_CYAN       RGB(0, 31, 31)
#define RGB_WHITEALPHA (RGB_WHITE | RGB_ALPHA)

#define RGB_LIME_GREEN          RGB2GBA(222, 230, 49)
#define RGB_AZUL_MARINO         RGB2GBA(46, 68, 130)
#define RGB_NARANJA             RGB2GBA(250, 144, 98)
#define RGB_AMARILLO_CLARO      RGB2GBA(255, 242, 204)
#define RGB_AZUL_PALIDO         RGB2GBA(193, 235, 218)
#define RGB_AZUL_OSCURO         RGB2GBA(23, 69, 125)
#define RGB_VERDE_AMARILLENTO   RGB2GBA(124, 125, 23)
#define RGB_ROSA_CLARO          RGB2GBA(230, 130, 223)
#define RGB_ROJO_VIVO           RGB2GBA(230, 58, 42)
#define RGB_MARRON              RGB2GBA(100, 63, 8)
#define RGB_GRIS_CLARO          RGB2GBA(192, 192, 192)
#define RGB_GRIS_OSCURO         RGB2GBA(71, 71, 71)

#define RGB_MAXIMO  31

#endif // GUARD_RGB_H

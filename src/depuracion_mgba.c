#include "global.h"
#include "depuracion_mgba.h"

#if DEPURACION_MGBA

#include <stdarg.h>
#include "string_util.h"

// Interfaz de registro de mGBA. Escribiendo 0xC0DE en el registro de activacion,
// el emulador responde 0x1DEA si soporta el log; a partir de ahi se escribe el
// texto en el buffer y se envia indicando el nivel.
#define REG_LOG_ACTIVAR (*(vu16 *)0x4FFF780)
#define REG_LOG_ENVIAR  (*(vu16 *)0x4FFF700)
#define BUFFER_LOG      ((char *)0x4FFF600)
#define TAMANO_BUFFER   256
// Nivel WARN a proposito: la emulacion de mGBA escupe sus propias trazas (DMA,
// E/S...) en nivel INFO, asi que en WARN el registro queda limpio de ruido.
#define NIVEL_LOG       2


// Solo admite %s y %d, que es cuanto necesita LOG().
void LogMgba(const char *formato, ...)
{
    va_list args;
    char *dst = BUFFER_LOG;
    char *fin = BUFFER_LOG + TAMANO_BUFFER - 1;

    // Se activa en cada llamada y se escribe sin comprobar la respuesta: si el
    // emulador no soporta el registro, estas escrituras a E/S no usada no hacen nada.
    REG_LOG_ACTIVAR = 0xC0DE;

    va_start(args, formato);
    while (*formato != '\0' && dst < fin)
    {
        if (*formato != '%')
        {
            *dst++ = *formato++;
            continue;
        }

        formato++;
        if (*formato == 's')
        {
            const char *s = va_arg(args, const char *);
            while (*s != '\0' && dst < fin)
                *dst++ = *s++;
        }
        else if (*formato == 'd')
        {
            s32 valor = va_arg(args, int);
            char digitos[12];
            s32 n = 0;

            if (valor < 0)
            {
                *dst++ = '-';
                valor = -valor;
            }
            do {
                digitos[n++] = '0' + (valor % 10);
                valor /= 10;
            } while (valor != 0 && n < (s32)sizeof(digitos));
            while (n > 0 && dst < fin)
                *dst++ = digitos[--n];
        }
        else if (*formato == '%')
        {
            *dst++ = '%';
        }
        formato++;
    }
    va_end(args);

    *dst = '\0';
    REG_LOG_ENVIAR = NIVEL_LOG | 0x100;
}

#endif // DEPURACION_MGBA

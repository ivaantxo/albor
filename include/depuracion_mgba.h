#ifndef GUARD_DEPURACION_MGBA_H
#define GUARD_DEPURACION_MGBA_H

// Registro por la consola de mGBA (Herramientas > Ver registros).
// Poner a 0 para que no ocupe nada en la ROM final.
#define DEPURACION_MGBA 1

#if DEPURACION_MGBA

void LogMgba(const char *formato, ...);

// Marca un punto del codigo con hasta dos valores.
#define LOG(texto, a, b) LogMgba("%s a=%d b=%d", texto, (int)(a), (int)(b))

#else

#define LOG(texto, a, b) ((void)0)

#endif // DEPURACION_MGBA

#endif // GUARD_DEPURACION_MGBA_H

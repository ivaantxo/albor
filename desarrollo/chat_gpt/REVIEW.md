# Casos para revisar

La separación entre ciclo base y gesto especial y la correspondencia anatómica de paletas son heurísticas. Estos casos necesitan especial atención.

## [VENUSAUR](pokemon/venusaur/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [CHARMELEON](pokemon/charmeleon/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [CATERPIE](pokemon/caterpie/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [METAPOD](pokemon/metapod/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [BUTTERFREE](pokemon/butterfree/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female: paleta reducida de 22 a 15 colores opacos.

## [KAKUNA](pokemon/kakuna/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [BEEDRILL](pokemon/beedrill/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [PIDGEY](pokemon/pidgey/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PIDGEOTTO](pokemon/pidgeotto/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PIDGEOT](pokemon/pidgeot/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [RATTATA](pokemon/rattata/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [RATICATE](pokemon/raticate/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SPEAROW](pokemon/spearow/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [FEAROW](pokemon/fearow/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [EKANS](pokemon/ekans/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [ARBOK](pokemon/arbok/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [PIKACHU](pokemon/pikachu/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [RAICHU](pokemon/raichu/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 23 a 15 colores opacos.

## [RAICHU_ALOLA](pokemon/raichu/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 26 a 15 colores opacos.

## [SANDSHREW_ALOLA](pokemon/sandshrew/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 23 a 15 colores opacos.

## [SANDSLASH_ALOLA](pokemon/sandslash/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 28 a 15 colores opacos.

## [NIDORINA](pokemon/nidorina/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [NIDORAN_M](pokemon/nidoran_m/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [CLEFFA](pokemon/cleffa/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [NINETALES](pokemon/ninetales/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [VULPIX_ALOLA](pokemon/vulpix/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [NINETALES_ALOLA](pokemon/ninetales/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 18 a 15 colores opacos.

## [IGGLYBUFF](pokemon/igglybuff/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [ZUBAT](pokemon/zubat/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GOLBAT](pokemon/golbat/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female: paleta reducida de 23 a 15 colores opacos.

## [CROBAT](pokemon/crobat/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ODDISH](pokemon/oddish/selection.json)

- La especie no tiene bloque de datos en species_info.h.

## [GLOOM](pokemon/gloom/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female: paleta reducida de 23 a 15 colores opacos.

## [VILEPLUME](pokemon/vileplume/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female: paleta reducida de 27 a 15 colores opacos.

## [BELLOSSOM](pokemon/bellossom/selection.json)

- La especie no tiene bloque de datos en species_info.h.

## [PARASECT](pokemon/parasect/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [PERSIAN](pokemon/persian/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [PSYDUCK](pokemon/psyduck/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PRIMEAPE](pokemon/primeape/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [ANNIHILAPE](pokemon/annihilape/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 23 a 15 colores opacos.

## [ARCANINE](pokemon/arcanine/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GROWLITHE_HISUI](pokemon/growlithe/hisui/selection.json)

- La especie no tiene bloque de datos en species_info.h.

## [ARCANINE_HISUI](pokemon/arcanine/hisui/selection.json)

- La especie no tiene bloque de datos en species_info.h.

## [POLIWRATH](pokemon/poliwrath/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [POLITOED](pokemon/politoed/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [ABRA](pokemon/abra/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [KADABRA](pokemon/kadabra/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [ALAKAZAM](pokemon/alakazam/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [MACHOKE](pokemon/machoke/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MACHAMP](pokemon/machamp/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [VICTREEBEL](pokemon/victreebel/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [TENTACOOL](pokemon/tentacool/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [TENTACRUEL](pokemon/tentacruel/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GEODUDE](pokemon/geodude/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GRAVELER](pokemon/graveler/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [PONYTA](pokemon/ponyta/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [RAPIDASH](pokemon/rapidash/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SLOWPOKE](pokemon/slowpoke/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SLOWBRO](pokemon/slowbro/selection.json)

- La especie no tiene bloque de datos en species_info.h.

## [SLOWKING](pokemon/slowking/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MAGNEMITE](pokemon/magnemite/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [MAGNETON](pokemon/magneton/selection.json)

- Front revisado visualmente: cinco poses distintas. Los slots 3 y 4 varían ojos e imanes; la fuente no ofrece un gesto especial independiente inequívoco.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DODUO](pokemon/doduo/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 21 a 15 colores opacos.

## [DODRIO](pokemon/dodrio/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female: paleta reducida de 27 a 15 colores opacos.

## [SHELLDER](pokemon/shellder/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CLOYSTER](pokemon/cloyster/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GASTLY](pokemon/gastly/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [HAUNTER](pokemon/haunter/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ONIX](pokemon/onix/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [STEELIX](pokemon/steelix/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [HYPNO](pokemon/hypno/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [KINGLER](pokemon/kingler/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [EXEGGCUTE](pokemon/exeggcute/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [EXEGGUTOR](pokemon/exeggutor/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MAROWAK_ALOLA](pokemon/marowak/alola/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 28 a 15 colores opacos.

## [HITMONLEE](pokemon/hitmonlee/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [HITMONCHAN](pokemon/hitmonchan/selection.json)

- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.

## [LICKITUNG](pokemon/lickitung/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [KOFFING](pokemon/koffing/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [WEEZING](pokemon/weezing/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [WEEZING_GALAR](pokemon/weezing/galar/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [RHYHORN](pokemon/rhyhorn/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [RHYDON](pokemon/rhydon/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [RHYPERIOR](pokemon/rhyperior/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [TANGELA](pokemon/tangela/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [TANGROWTH](pokemon/tangrowth/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 17 a 15 colores opacos.

## [KANGASKHAN](pokemon/kangaskhan/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [HORSEA](pokemon/horsea/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SEADRA](pokemon/seadra/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [KINGDRA](pokemon/kingdra/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GOLDEEN](pokemon/goldeen/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SEAKING](pokemon/seaking/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [STARYU](pokemon/staryu/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [STARMIE](pokemon/starmie/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MR_MIME](pokemon/mr_mime/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SCYTHER](pokemon/scyther/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 20 a 15 colores opacos.

## [SCIZOR](pokemon/scizor/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female: paleta reducida de 19 a 15 colores opacos.

## [KLEAVOR](pokemon/kleavor/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [ELECTIVIRE](pokemon/electivire/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [PINSIR](pokemon/pinsir/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [TAUROS](pokemon/tauros/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MAGIKARP](pokemon/magikarp/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [GYARADOS](pokemon/gyarados/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female: paleta reducida de 20 a 15 colores opacos.

## [EEVEE](pokemon/eevee/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [VAPOREON](pokemon/vaporeon/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SYLVEON](pokemon/sylveon/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [PORYGON](pokemon/porygon/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PORYGON_Z](pokemon/porygon_z/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [OMANYTE](pokemon/omanyte/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [OMASTAR](pokemon/omastar/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [KABUTO](pokemon/kabuto/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [KABUTOPS](pokemon/kabutops/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [AERODACTYL](pokemon/aerodactyl/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [ARTICUNO](pokemon/articuno/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [ZAPDOS](pokemon/zapdos/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [MOLTRES](pokemon/moltres/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DRATINI](pokemon/dratini/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [MEW](pokemon/mew/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MEGANIUM](pokemon/meganium/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SENTRET](pokemon/sentret/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [NOCTOWL](pokemon/noctowl/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [LEDYBA](pokemon/ledyba/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [LEDIAN](pokemon/ledian/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [ARIADOS](pokemon/ariados/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CHINCHOU](pokemon/chinchou/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LANTURN](pokemon/lanturn/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [TOGEPI](pokemon/togepi/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [XATU](pokemon/xatu/selection.json)

- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.

## [MAREEP](pokemon/mareep/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [SUDOWOODO](pokemon/sudowoodo/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [HOPPIP](pokemon/hoppip/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [JUMPLUFF](pokemon/jumpluff/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [AIPOM](pokemon/aipom/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [AMBIPOM](pokemon/ambipom/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SUNFLORA](pokemon/sunflora/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [YANMA](pokemon/yanma/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [YANMEGA](pokemon/yanmega/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [MURKROW](pokemon/murkrow/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MISDREAVUS](pokemon/misdreavus/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MISMAGIUS](pokemon/mismagius/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GIRAFARIG](pokemon/girafarig/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [GLIGAR](pokemon/gligar/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [GLISCOR](pokemon/gliscor/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GRANBULL](pokemon/granbull/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [HERACROSS](pokemon/heracross/selection.json)

- default.back: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SNEASEL](pokemon/sneasel/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [WEAVILE](pokemon/weavile/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SNEASLER](pokemon/sneasler/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 26 a 15 colores opacos.

## [URSARING](pokemon/ursaring/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SLUGMA](pokemon/slugma/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MAGCARGO](pokemon/magcargo/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SWINUB](pokemon/swinub/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [PILOSWINE](pokemon/piloswine/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [MAMOSWINE](pokemon/mamoswine/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 25 a 15 colores opacos.

## [OCTILLERY](pokemon/octillery/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female: paleta reducida de 18 a 15 colores opacos.

## [HOUNDOOM](pokemon/houndoom/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [DONPHAN](pokemon/donphan/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [WYRDEER](pokemon/wyrdeer/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [SUICUNE](pokemon/suicune/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PUPITAR](pokemon/pupitar/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [TYRANITAR](pokemon/tyranitar/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [LUGIA](pokemon/lugia/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [HO_OH](pokemon/ho_oh/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [TREECKO](pokemon/treecko/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [GROVYLE](pokemon/grovyle/selection.json)

- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.

## [TORCHIC](pokemon/torchic/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [COMBUSKEN](pokemon/combusken/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [BLAZIKEN](pokemon/blaziken/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- female: paleta reducida de 23 a 15 colores opacos.

## [BEAUTIFLY](pokemon/beautifly/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [DUSTOX](pokemon/dustox/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [LOTAD](pokemon/lotad/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LUDICOLO](pokemon/ludicolo/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [NUZLEAF](pokemon/nuzleaf/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SHIFTRY](pokemon/shiftry/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- female: paleta reducida de 24 a 15 colores opacos.

## [PELIPPER](pokemon/pelipper/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [RALTS](pokemon/ralts/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SURSKIT](pokemon/surskit/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [MASQUERAIN](pokemon/masquerain/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [SLAKOTH](pokemon/slakoth/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [VIGOROTH](pokemon/vigoroth/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [NINJASK](pokemon/ninjask/selection.json)

- Selección revisada visualmente: el loop conserva el vaivén vertical completo además del aleteo; los especiales front pliegan las patas.
- default.front: Ciclo ampliado para incluir todas las poses base elegidas; la repeticion corta detectaba un movimiento secundario.
- default.back: Ciclo ampliado para incluir todas las poses base elegidas; la repeticion corta detectaba un movimiento secundario.

## [SHEDINJA](pokemon/shedinja/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [WHISMUR](pokemon/whismur/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [EXPLOUD](pokemon/exploud/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [NOSEPASS](pokemon/nosepass/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PROBOPASS](pokemon/probopass/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [SABLEYE](pokemon/sableye/selection.json)

- Front revisado visualmente: las dos inclinaciones de cabeza del especial estaban separadas por una vuelta breve a la base.

## [MEDITITE](pokemon/meditite/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- female.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MEDICHAM](pokemon/medicham/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [ELECTRIKE](pokemon/electrike/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MANECTRIC](pokemon/manectric/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [ROSELIA](pokemon/roselia/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [ROSERADE](pokemon/roserade/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [CARVANHA](pokemon/carvanha/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SHARPEDO](pokemon/sharpedo/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [WAILMER](pokemon/wailmer/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [WAILORD](pokemon/wailord/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [NUMEL](pokemon/numel/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [CAMERUPT](pokemon/camerupt/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SPOINK](pokemon/spoink/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GRUMPIG](pokemon/grumpig/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [TRAPINCH](pokemon/trapinch/selection.json)

- La fuente front solo contiene cuatro poses distintas: los slots 2 y 3 reutilizan APNG 2. Se conservan cinco frames de salida; el parpadeo APNG 6 queda reservado al final del especial.
- default.front: la selección repite poses.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [CACTURNE](pokemon/cacturne/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 21 a 15 colores opacos.

## [SWABLU](pokemon/swablu/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LUNATONE](pokemon/lunatone/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SOLROCK](pokemon/solrock/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [BALTOY](pokemon/baltoy/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [CLAYDOL](pokemon/claydol/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [LILEEP](pokemon/lileep/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [CRADILY](pokemon/cradily/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [FEEBAS](pokemon/feebas/selection.json)

- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [MILOTIC](pokemon/milotic/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [CASTFORM](pokemon/castform/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CASTFORM_SUNNY](pokemon/castform/sunny/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CASTFORM_RAINY](pokemon/castform/rainy/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CASTFORM_SNOWY](pokemon/castform/snowy/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DUSKNOIR](pokemon/dusknoir/selection.json)

- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [TROPIUS](pokemon/tropius/selection.json)

- default.front: El pico especial aparece sin una preparación distinta; revisar el orden de los frames 3 y 4.

## [FROSLASS](pokemon/froslass/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [SPHEAL](pokemon/spheal/selection.json)

- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.

## [LATIOS](pokemon/latios/selection.json)

- default.front: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.
- default.back: El ciclo se detecta por semejanza entre poses, con variaciones; revisar los límites del movimiento especial.

## [KYOGRE](pokemon/kyogre/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [GROUDON](pokemon/groudon/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [RAYQUAZA](pokemon/rayquaza/selection.json)

- default.front: tamaño excepcional; conserva lienzo y coordenadas de origen.
- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [DEOXYS_ATTACK](pokemon/deoxys/attack/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DEOXYS_DEFENSE](pokemon/deoxys/defense/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DEOXYS_SPEED](pokemon/deoxys/speed/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [STARLY](pokemon/starly/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [STARAVIA](pokemon/staravia/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [STARAPTOR](pokemon/staraptor/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 26 a 15 colores opacos.

## [BIDOOF](pokemon/bidoof/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [BIBAREL](pokemon/bibarel/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 19 a 15 colores opacos.

## [KRICKETOT](pokemon/kricketot/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [KRICKETUNE](pokemon/kricketune/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- female: paleta reducida de 20 a 15 colores opacos.

## [SHINX](pokemon/shinx/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [LUXIO](pokemon/luxio/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [LUXRAY](pokemon/luxray/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [COMBEE](pokemon/combee/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female: paleta reducida de 21 a 15 colores opacos.

## [DRIFLOON](pokemon/drifloon/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DRIFBLIM](pokemon/drifblim/selection.json)

- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GIBLE](pokemon/gible/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [GABITE](pokemon/gabite/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [GARCHOMP](pokemon/garchomp/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 26 a 15 colores opacos.

## [DRAPION](pokemon/drapion/selection.json)

- default.back: tamaño excepcional; conserva lienzo y coordenadas de origen.

## [CROAGUNK](pokemon/croagunk/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- female.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [TOXICROAK](pokemon/toxicroak/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [SNOVER](pokemon/snover/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.

## [ABOMASNOW](pokemon/abomasnow/selection.json)

- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female: paleta reducida de 23 a 15 colores opacos.

## [ROTOM_HEAT](pokemon/rotom/heat/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ROTOM_WASH](pokemon/rotom/wash/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ROTOM_FROST](pokemon/rotom/frost/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ROTOM_FAN](pokemon/rotom/fan/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ROTOM_MOW](pokemon/rotom/mow/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [SANDILE](pokemon/sandile/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [KROKOROK](pokemon/krokorok/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [KROOKODILE](pokemon/krookodile/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [YAMASK](pokemon/yamask/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [COFAGRIGUS](pokemon/cofagrigus/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 20 a 15 colores opacos.

## [GOTHITA](pokemon/gothita/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [GOTHORITA](pokemon/gothorita/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GOTHITELLE](pokemon/gothitelle/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.

## [FRILLISH](pokemon/frillish/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [JELLICENT](pokemon/jellicent/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- female.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.front: la selección repite poses.
- female.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- female.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- female.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- female.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- female.back: la selección repite poses.
- female.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- female.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- female.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- female.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [JOLTIK](pokemon/joltik/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GALVANTULA](pokemon/galvantula/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [FERROSEED](pokemon/ferroseed/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [FERROTHORN](pokemon/ferrothorn/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LITWICK](pokemon/litwick/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LAMPENT](pokemon/lampent/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CHANDELURE](pokemon/chandelure/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [AXEW](pokemon/axew/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [FRAXURE](pokemon/fraxure/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [HAXORUS](pokemon/haxorus/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [CUBCHOO](pokemon/cubchoo/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [BEARTIC](pokemon/beartic/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GOLETT](pokemon/golett/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [GOLURK](pokemon/golurk/selection.json)

- La especie no tiene bloque de datos en species_info.h.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [PAWNIARD](pokemon/pawniard/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [BISHARP](pokemon/bisharp/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [DEINO](pokemon/deino/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [ZWEILOUS](pokemon/zweilous/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento especial solo contiene una pose distinta; se repite en los frames 3 y 4.
- default.front: La fuente solo tiene 4 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [HYDREIGON](pokemon/hydreigon/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [LARVESTA](pokemon/larvesta/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [VOLCARONA](pokemon/volcarona/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 3 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [FENNEKIN](pokemon/fennekin/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 18 a 15 colores opacos.

## [BRAIXEN](pokemon/braixen/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [DELPHOX](pokemon/delphox/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 22 a 15 colores opacos.

## [FLETCHLING](pokemon/fletchling/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 25 a 15 colores opacos.

## [FLETCHINDER](pokemon/fletchinder/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 26 a 15 colores opacos.

## [TALONFLAME](pokemon/talonflame/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 23 a 15 colores opacos.

## [TYRUNT](pokemon/tyrunt/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [TYRANTRUM](pokemon/tyrantrum/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 20 a 15 colores opacos.

## [AMAURA](pokemon/amaura/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 16 a 15 colores opacos.

## [AURORUS](pokemon/aurorus/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [ROWLET](pokemon/rowlet/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 18 a 15 colores opacos.

## [DARTRIX](pokemon/dartrix/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [DECIDUEYE](pokemon/decidueye/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [JANGMO_O](pokemon/jangmo_o/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 20 a 15 colores opacos.

## [HAKAMO_O](pokemon/hakamo_o/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 22 a 15 colores opacos.

## [KOMMO_O](pokemon/kommo_o/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 25 a 15 colores opacos.

## [ROOKIDEE](pokemon/rookidee/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 22 a 15 colores opacos.

## [CORVISQUIRE](pokemon/corvisquire/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 17 a 15 colores opacos.

## [CORVIKNIGHT](pokemon/corviknight/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo no ofrece dos desplazamientos opuestos claros respecto a la pose base.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 21 a 15 colores opacos.

## [BLIPBUG](pokemon/blipbug/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 16 a 15 colores opacos.

## [DOTTLER](pokemon/dottler/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [ORBEETLE](pokemon/orbeetle/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 18 a 15 colores opacos.

## [SNOM](pokemon/snom/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.

## [FROSMOTH](pokemon/frosmoth/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 17 a 15 colores opacos.

## [DREEPY](pokemon/dreepy/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 17 a 15 colores opacos.

## [DRAKLOAK](pokemon/drakloak/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 17 a 15 colores opacos.

## [DRAGAPULT](pokemon/dragapult/selection.json)

- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 1 poses distintas para 5 frames; se conservan repeticiones.
- default.back: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.back: Solo hay una pose original: el resultado será estático, sin inventar movimiento.
- default.back: la selección repite poses.
- default.back: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.back: El ciclo base solo contiene una pose distinta; se repite sin inventar movimiento.
- default.back: La fuente solo tiene 1 poses distintas para 3 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.
- default.back: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default: paleta reducida de 19 a 15 colores opacos.

## [REGISTEEL](pokemon/registeel/selection.json)

- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.back: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.

## [EGG](pokemon/egg/selection.json)

- Sin número nacional; EGG no es una especie de la Pokédex.
- default.front: Fuente heredada del juego: se conservan las poses disponibles; no procede de un APNG BW.
- default.front: la selección repite poses.
- default.front: No se identifica un ciclo inicial repetido con confianza; la selección base requiere revisión.
- default.front: El movimiento base desplaza menos de medio píxel el centro; revisar las poses de extremidades.
- default.front: El ciclo base tiene menos de tres poses distintas; se repite una pose fuente.
- default.front: No se detecta un movimiento especial separado del ciclo; revisar manualmente los frames 3 y 4.
- default.front: La fuente solo tiene 2 poses distintas para 5 frames; se conservan repeticiones.
- default.front: El ciclo base no se ha detectado con confianza; revisar su duración y recorrido.
- default.front: No se detecta un especial independiente: se usa una cadencia sintética de ciclos base y una pasada con las cinco poses seleccionadas.


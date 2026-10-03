# Rediseño del mapeado: informe de ejecución

Estado a 3 de octubre de 2026 de lo que pide `rediseno-mapeado.md`, en la rama `claude/rediseno-mapeado-plan-5296ti`. Las fases 0, 1, 2 y 3 están hechas, compilan y están probadas en emulador. Con la 3, la interfaz del overworld es de bandas sin marco y usa una sola paleta, así que el mapa pasa a tener 15. De la 5 está hecho el motor para pintar en porymap: estampar piezas de arte libre en una capa, con el tileset rellenándose solo, y optimizarlo. Falta meterlo en el editor, que va en el fork de porymap. La 4 casi no hace falta, porque porymap se configura sin fork. La 6 es para después.

| Fase | Estado | Commit |
| --- | --- | --- |
| 0. Exploración | Hecha. Este documento | — |
| 1. Bloque nuevo y elevación | Hecha | `5426c692` |
| 2. Tileset único | Hecha, con una capa de compatibilidad para porymap | `f064ba26` |
| 3. UI a una paleta | Hecha: bandas sin marco en la paleta 15, y 15 paletas para el mapa | `b9490edd`, `fd78de8b` |
| 4. Fork de porymap, base | Casi todo resuelto con configuración (ver abajo) | — |
| 5. Pintado por capas y compilador | Motor hecho y probado. El editor necesita el fork | `07b1da5e`, `8c856420` |
| 6. Cambios por zona | Sin hacer: el plan la deja para después | — |

Aparte, `db48160d` arregla un fallo del Makefile que salió al probar la fase 1: `maps.o` no dependía de los `map.bin` ni de los `border.bin`. Pintar en porymap sin tocar `layouts.json` dejaba el mapa viejo dentro de la ROM.

## Dónde el código contradice al plan

1. **El bloque ya no era el de pokeemerald.** Era ID de 12 bits, colisión de 1 y elevación de 3 (0-7). El puente es `MAX_ELEVATION_LEVEL` = 7, no 15. Se ha mantenido 7.
2. **Solo hay dos mapas, `Test` y `CentroPokemon`, sin conexiones ni warps.** Ninguno usaba su secundario: los IDs llegan a 87 y 123, por debajo del primario, y las paletas a la 5. Los 50 secundarios y el `General` de pokeemerald no los usa ningún mapa. La "zona piloto" de la fase 2 no tenía blockdata que convertir.
3. **La elevación 0 solo aparecía en casillas bloqueadas.** Las casillas que se pisan tenían todas 3. Derivarla del metatile no pierde nada en estos mapas.
4. **Atributos de metatile:** los bits 8-11 estaban libres. El dibujo a triple capa no mira el layer type (solo las puertas, con `0xFF`); `shop.c` sí lo usa.
5. **Paletas de la interfaz en el overworld:** el marco de menú, el popup de nombre y la transición de cueva usaban la 14, y la caja de diálogo la 15. La 13 no la cargaba ninguna ventana del overworld, solo pantallas aparte (bolsa, MTs, PC, mapa, combate). Con la fase 3 todo eso queda en la 15, y la 13 y la 14 pasan al mapa. La transición de cueva sigue escribiendo en la 14 y en la 0, pero tapa la pantalla entera y el mapa recarga sus paletas al volver, como ya pasaba con la 0.
6. **Porymap no admite un tileset único.** Rechaza un layout sin secundario y un proyecto sin ningún secundario. Además recorta el primario a total − 1 en tiles y en paletas (comprobado en el código de porymap 6.3.1). Por eso la fase 2 lleva la capa de compatibilidad descrita abajo. Porytiles sí acepta primario = total.
7. **Puertas:** `field_door.c` usa los 16 últimos tiles de la VRAM (1008-1023). El tileset único se queda con 1008 tiles y no 1024.
8. **Paletas de noche:** la versión de noche de la paleta N va en la (N + 9) % 16 del mismo tileset. Con 15 paletas de día solo caben si se renuncia a algunas de día. Ningún tileset actual las usa.
9. **La base del fork (fase 4) casi no hace falta.** Porymap lee las máscaras del bloque de `global.fieldmap.h`, y con elevación 0 deja de pintarla. El nivel se edita como "terrain type". La capa de compatibilidad cubre el tileset único.

## Lo que se ha hecho

### Fase 1

- **Bloque:** ID de 15 bits (`0x7FFF`) y colisión en el bit 15. `MAPGRID_ELEVATION_MASK` se queda definida a 0 solo para porymap; sin ella, porymap aplicaría su valor por defecto, que pisa al ID.
- **Nivel del metatile,** bits 8-11 de los atributos (`METATILE_ATTR_NIVEL_MASK`):
  - `METATILE_NIVEL_AUTO` (0, lo que deja porytiles): se deduce del comportamiento. Agua surfeable → 1, puente sobre agua → 7, lo demás → 3.
  - `METATILE_NIVEL_0` … `METATILE_NIVEL_7` (8-15): nivel fijo, para plataformas y rampas (las rampas van a 0).
- **`GetMetatileElevationById`** hace esa cuenta y `MapGridGetElevationAt` la usa. Lo que consume la elevación no cambia.
- **`tools/mapeado/convertir_bloques.py`** convierte el blockdata y avisa de las casillas que cambiarían de altura. Ya se ha pasado a los dos layouts. Solo hubo un aviso: el dependiente del Centro Pokémon está en (13,5), una casilla bloqueada que pasa de altura 0 a 3. Las tablas de prioridad dan lo mismo para 0 y 3.

### Fase 2

- **El motor carga un tileset por layout** (`MapLayout.tileset`). Admite hasta 1008 tiles, 32767 metatiles y 15 paletas (13 hasta la fase 3). Solo copia los tiles reales del tileset.
- **Conexiones:** al cruzar una, solo se recarga si el mapa nuevo usa otro tileset. En ese caso, lo que queda en pantalla del mapa anterior se ve mal hasta que sale. Conviene que los mapas conectados compartan tileset, como pide el plan.
- **Capa de compatibilidad para porymap:**
  - `fieldmap.h`: el "primario" que ve porymap es el tileset (1008 tiles, 15 paletas). Hasta el total quedan los tiles de las puertas y la paleta 15, la de la interfaz, que no son del tileset.
  - `gTileset_Reservado`: secundario vacío que solo ve porymap. Los dos layouts lo llevan en `layouts.json`, y `mapjson` ya no pasa el secundario al juego.
  - Cuando exista el fork, se quita la capa y `NUM_PALS_TOTAL` deja de importar.

### Fase 3: interfaz en bandas

- **Sin marcos en el overworld.** Cada ventana es una banda que cruza la pantalla entera por las filas o columnas donde iba el marco: horizontal si la ventana es más ancha que alta, vertical si no. Va así para todas: caja de diálogo, carteles, menú de inicio, Sí/No, multichoice, ventanas de datos. Las posiciones son las de antes, solo que la banda no se recorta.
- **Pop-up del nombre del mapa:** una sola banda arriba, con la hora a la derecha. Se han quitado los gráficos y paletas BW y la ventana secundaria.
- **Una paleta, la 15** (`sPaletaBandas` en `menu.c`). La banda es un tile liso del color 1, el mismo con el que se rellenan las ventanas. Los colores del texto se dan la vuelta: banda oscura, letras claras y sombra oscura, y lo mismo con los colores. BG0 se mezcla con el mapa. No se carga ningún gráfico de marco.
- **Fuera del overworld** (mochila, equipo, PC, combate…) siguen los marcos de siempre. `gVentanasEnBandas` lo enciende el overworld al crear sus ventanas, e `InitWindows` lo apaga al cambiar de pantalla.
- **15 paletas para el mapa (0-14).** `NUM_PALS_IN_PRIMARY` es 15 y `NUM_PALS_TOTAL` 16. El tinte de la hora del día y el del tiempo atmosférico llegan hasta la 14 y dejan fuera la 15. `Principal` lleva la 13 y la 14 vacías; `CentroPokemon` ya las tenía.

### Fase 5: motor para pintar en porymap

**Cambio de enfoque.** El primer intento pintaba los mapas fuera de porymap: tres PNG por mapa más el borde, que se compilaban al tileset (`07b1da5e`, `fd2e7770`). Se descartó (`00924135`) porque obliga a exportar y a mantener el tamaño a mano. Además, `make` recompilaba desde los PNG y podía revertir lo pintado en porymap.

**Lo que hay ahora** es porytiles dentro de porymap, pintando el mapa (`8c856420`); está explicado en `tools/mapeado/README.md`:

- **Estampar:** una pieza, cualquier PNG de lado múltiplo de 8 y sin paleta fijada, se estampa en una capa (baja, media o alta) en la rejilla de 8.
  - El tileset se rellena en ese momento: colores, tiles con volteos y un metatile por arte nuevo.
  - El metatile nuevo hereda el comportamiento y el nivel de la casilla. La colisión no cambia.
  - Si no hay hueco de paletas, tiles o metatiles, o un trozo tiene más de 15 colores, no se pinta nada y se dice qué falta.
- **Optimizar:** reempaqueta el tileset desde lo pintado. Junta duplicados, quita lo que no usa ningún mapa y libera tiles y colores. Respeta atributos, colisión, números y fijados.
- **Fuente:** siguen siendo el tileset y el blockdata. No hay arte aparte.
- **Biblioteca:** es C++ y no lee archivos ni depende de nada, para meterla en el fork. Mientras tanto se usa con `tools/mapeado/mapeado estampar | optimizar | cuentas | exportar`.
- **Limpieza de los tilesets:** al pasar por el compilador se juntaron los metatiles duplicados (11 casillas cambian de número en `Test` y 5 en el Centro) y se quitaron los que no usaba nadie. El tileset de `Test` pasa de 128 a 69 metatiles y el del Centro de 128 a 72. Los tiles y las paletas no cambian.

## Cómo se ha comprobado

- **Compilación en cloud** con arm-none-eabi-gcc 13.2, sin avisos (`-Werror`). Hubo que compilar SuperFamiconv 0.9.2 para Linux, porque el de `tools/superfamiconv/` es un binario de Mac; se pasó con `FAMICONV=` sin tocar el repo.
- **Emulador:** con libmgba, el mismo recorrido por `Test` con la ROM de antes y con la de cada fase. El recorrido choca con árboles, pisa hierba alta y llega al borde. En los dos casos el jugador acaba en las mismas casillas, con la misma altura y el mismo comportamiento, y las 9 capturas salen idénticas píxel a píxel.
- **`CentroPokemon`** no se puede alcanzar sin warp. Se ha comprobado por datos: mismo ID y colisión en cada casilla, y el tileset solo usa las paletas 0-5.
- **Porytiles 0.0.7,** compilado para Linux, genera `principal` con los límites nuevos.
- **Porymap:** comprobado leyendo su código (6.3.1), sin abrirlo. Revisado: máscara de elevación 0, carpeta por defecto del secundario vacío, recorte de límites y lista de "terrain type".
- **Motor:** 22 escenarios de estampar y optimizar sobre una copia del proyecto:
  - una pieza nueva y su colocación exacta;
  - repetirla sin gastar nada;
  - una pieza de 32×16 a media casilla;
  - colisión y comportamiento que se conservan;
  - borrar con `--reemplazar`;
  - optimizar y su idempotencia;
  - los cuatro avisos (paletas, tiles, metatiles, más de 15 colores), comprobando que no se toca ningún archivo.

  Además, 15 escenarios del compilador en el que se apoya optimizar, y la limpieza de los dos tilesets da el mismo arte píxel a píxel. En emulador, unas flores estampadas junto al jugador salen en el juego.
- **Interfaz en bandas, en emulador:**
  - Salen como banda el menú de inicio (vertical), la ventana de datos de guardado (arriba), la caja de diálogo (abajo), el pop-up con nombre y hora (arriba) y el Sí/No. El Sí/No se abrió con un parche temporal, porque en `Test` no hay nada que lo pregunte.
  - La mochila sale idéntica píxel a píxel a la ROM de antes, con sus marcos. Al volver al mapa, el menú de inicio vuelve a salir como banda.
  - Al cerrar las ventanas, el mapa queda idéntico píxel a píxel al de la ROM de antes.
  - El recorrido de siempre sigue saliendo idéntico.
- **15 paletas, en emulador:** una tira estampada con piezas en las paletas 0, 1 y 6-14 da 154 colores en pantalla, y siguen ahí con el menú de inicio y las ventanas de guardado abiertas.
- **Sin probar en ejecución:**
  - agua, puentes y rampas (no hay ninguno en los mapas);
  - el cruce de conexiones y las partidas guardadas;
  - el multichoice de los scripts: es el mismo camino que el menú de inicio y la ventana usa la paleta 15, pero no hay ninguno en `Test`.
- **La ficha de entrenador** ("Ivantxo" en el menú) se queda en negro en el emulador. Pasa igual con la ROM de antes de estos cambios, así que no viene de aquí; no lo he investigado.

## Lo que tienes que hacer tú en local

1. **`porymap.project.cfg`** (está en `.gitignore`), para editar el nivel desde el editor de tilesets:
   ```
   metatile_terrain_type_mask=0x00000F00
   regex_terrain_types=\bMETATILE_NIVEL_
   ```
   Las máscaras del bloque no hace falta tocarlas: porymap las lee de `include/global.fieldmap.h`.
2. **Mapas:** de momento, como siempre en porymap. Para probar el pintado con piezas sin el fork: `tools/mapeado/mapeado estampar` (ver `tools/mapeado/README.md`).
3. **Porytiles**, si regeneras un tileset con él, con estos límites:
   ```
   porytiles compile-primary -Wall -tiles-primary-override=1008 -tiles-total-override=1024 \
     -metatiles-primary-override=32767 -metatiles-total-override=32768 \
     -pals-primary-override=15 -pals-total-override=16 \
     -o data/tilesets/primary/<tileset> <fuentes> include/constants/metatile_behaviors_porytiles.h
   ```
4. **Partidas guardadas de antes de la fase 1:** la vista del mapa que se guarda al salvar está en el formato viejo. Las casillas alrededor del jugador se verán mal hasta recargar el mapa. Mejor empezar partida nueva.

## Para seguir

- **Texto como sprites,** si quieres la paleta 16 para el mapa. Con el texto en sprites, BG0 y la paleta de fondo 15 quedan libres, pero:
  - las bandas pasan a ocupar paletas y memoria de sprites;
  - la mezcla con el mapa sigue funcionando (los sprites semitransparentes usan los mismos coeficientes que BG0);
  - porymap no admite primario = total, así que 16 paletas en el mapa necesitan el fork.
- **El fork de porymap** (fase 5, editor) es otro repositorio. Esta sesión solo tiene acceso a `ivaantxo/albor`, así que hay que crearlo y darle acceso. Lo que le toca:
  - importar piezas (cualquier PNG de lado múltiplo de 8) a una biblioteca;
  - estamparlas con `mapeado::Estampar` en la capa activa, en la rejilla de 8 o de 16;
  - visibilidad por capa;
  - un aviso en el momento de pintar cuando no quepa, con la opción de optimizar y reintentar;
  - los contadores en vivo de tiles, paletas y metatiles.
- **Limpieza pendiente, fuera de este plan:** los 50 secundarios y `General` de pokeemerald, que no usa nadie. Sus animaciones en `tileset_anims.c` siguen escritas para el secundario en la posición 512 y ahora apuntarían fuera del tileset si alguien las activara.

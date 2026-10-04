# Rediseño del mapeado: informe de ejecución

Estado a 3 de octubre de 2026 de lo que pide `rediseno-mapeado.md`, en la rama `claude/rediseno-mapeado-plan-5296ti`. Las fases 0, 1, 2 y 3 están hechas, compilan y están probadas en emulador. Con la 3, la interfaz del overworld es de bandas sin marco y usa una sola paleta, así que el mapa pasa a tener 15. La 4 y la 5 están en el fork de porymap ([ivaantxo/porymap](https://github.com/ivaantxo/porymap), misma rama). Ese fork trabaja con un solo tileset por layout, sin secundario, y tiene la pestaña **Piezas** para estampar arte libre en una capa: el tileset se rellena solo, avisa cuando no cabe, tiene contadores, capas visibles, optimizar y camino inteligente con piezas. Desde que albor no tiene secundario, el porymap original ya no lo abre: hace falta el fork. La 6 es para después.

| Fase | Estado | Commit |
| --- | --- | --- |
| 0. Exploración | Hecha. Este documento | — |
| 1. Bloque nuevo y elevación | Hecha | `5426c692` |
| 2. Tileset único | Hecha. Sin secundario desde que el fork lo admite | `f064ba26` |
| 3. UI a una paleta | Hecha: bandas sin marco en la paleta 15, y 15 paletas para el mapa | `b9490edd`, `fd78de8b` |
| 4. Fork de porymap, base | Hecha: un solo tileset por layout; lo demás, con configuración | fork `99086e0b` |
| 5. Pintado por capas y compilador | Hecha: motor en albor y editor en el fork de porymap | `07b1da5e`, `8c856420`; fork `4af73c0e`, `7b4bdbea` |
| 6. Cambios por zona | Sin hacer: el plan la deja para después | — |

Aparte, `db48160d` arregla un fallo del Makefile que salió al probar la fase 1: `maps.o` no dependía de los `map.bin` ni de los `border.bin`. Pintar en porymap sin tocar `layouts.json` dejaba el mapa viejo dentro de la ROM.

## Dónde el código contradice al plan

1. **El bloque ya no era el de pokeemerald.** Era ID de 12 bits, colisión de 1 y elevación de 3 (0-7). El puente es `MAX_ELEVATION_LEVEL` = 7, no 15. Se ha mantenido 7.
2. **Solo hay dos mapas, `Test` y `CentroPokemon`, sin conexiones ni warps.** Ninguno usaba su secundario: los IDs llegan a 87 y 123, por debajo del primario, y las paletas a la 5. Los 50 secundarios y el `General` de pokeemerald no los usa ningún mapa. La "zona piloto" de la fase 2 no tenía blockdata que convertir.
3. **La elevación 0 solo aparecía en casillas bloqueadas.** Las casillas que se pisan tenían todas 3. Derivarla del metatile no pierde nada en estos mapas.
4. **Atributos de metatile:** los bits 8-11 estaban libres. El dibujo a triple capa no mira el layer type (solo las puertas, con `0xFF`); `shop.c` sí lo usa.
5. **Paletas de la interfaz en el overworld:** el marco de menú, el popup de nombre y la transición de cueva usaban la 14, y la caja de diálogo la 15. La 13 no la cargaba ninguna ventana del overworld, solo pantallas aparte (bolsa, MTs, PC, mapa, combate). Con la fase 3 todo eso queda en la 15, y la 13 y la 14 pasan al mapa. La transición de cueva sigue escribiendo en la 14 y en la 0, pero tapa la pantalla entera y el mapa recarga sus paletas al volver, como ya pasaba con la 0.
6. **Porymap no admite un tileset único.** Rechaza un layout sin secundario y un proyecto sin ningún secundario. Además recorta el primario a total − 1 en tiles y en paletas (comprobado en el código de porymap 6.3.1). La fase 2 empezó con un secundario vacío de mentira (`gTileset_Reservado`) para contentarlo; con el fork ya no hace falta. Porytiles sí acepta primario = total.
7. **Puertas:** `field_door.c` usa los 16 últimos tiles de la VRAM (1008-1023). El tileset único se queda con 1008 tiles y no 1024.
8. **Paletas de noche:** la versión de noche de la paleta N va en la (N + 9) % 16 del mismo tileset. Con 15 paletas de día solo caben si se renuncia a algunas de día. Ningún tileset actual las usa.
9. **La base del fork (fase 4) es pequeña.** Porymap lee las máscaras del bloque de `global.fieldmap.h`, y con elevación 0 deja de pintarla. El nivel se edita como "terrain type". Lo único que ha hecho falta tocar es el tileset único.

## Lo que se ha hecho

### Fase 1

- **Bloque:** ID de 15 bits (`0x7FFF`) y colisión en el bit 15. `MAPGRID_ELEVATION_MASK` se queda definida a 0 solo para porymap; sin ella, porymap aplicaría su valor por defecto, que pisa al ID.
- **Nivel del metatile,** bits 8-11 de los atributos (`METATILE_ATTR_NIVEL_MASK`):
  - `METATILE_NIVEL_AUTO` (0, el de un metatile nuevo): se deduce del comportamiento. Agua surfeable → 1, puente sobre agua → 7, lo demás → 3.
  - `METATILE_NIVEL_0` … `METATILE_NIVEL_7` (8-15): nivel fijo, para plataformas y rampas (las rampas van a 0).
- **`GetMetatileElevationById`** hace esa cuenta y `MapGridGetElevationAt` la usa. Lo que consume la elevación no cambia.
- **`tools/mapeado/convertir_bloques.py`** convierte el blockdata y avisa de las casillas que cambiarían de altura. Ya se ha pasado a los dos layouts. Solo hubo un aviso: el dependiente del Centro Pokémon está en (13,5), una casilla bloqueada que pasa de altura 0 a 3. Las tablas de prioridad dan lo mismo para 0 y 3.

### Fase 2

- **El motor carga un tileset por layout** (`MapLayout.tileset`). Admite hasta 1008 tiles, 32767 metatiles y 15 paletas (13 hasta la fase 3). Solo copia los tiles reales del tileset.
- **Conexiones:** al cruzar una, solo se recarga si el mapa nuevo usa otro tileset. En ese caso, lo que queda en pantalla del mapa anterior se ve mal hasta que sale. Conviene que los mapas conectados compartan tileset, como pide el plan.
- **Sin secundario:** `layouts.json` solo lleva `primary_tileset`, y `mapjson` no pasa nada más al juego. `fieldmap.h` define `NUM_TILESETS_PER_LAYOUT` a 1, que es como el fork de porymap sabe que no hay secundario; `NUM_*_IN_PRIMARY` son los límites del tileset (1008 tiles, 32767 metatiles, 15 paletas). `NUM_TILES_TOTAL` (1024) queda solo para las puertas, que van al final de la VRAM.
- **Antes,** mientras porymap no lo admitía, cada layout llevaba un secundario vacío de mentira, `gTileset_Reservado`, que ocupaba los tiles de las puertas y la paleta 15. Ya no existe.

### Fase 3: interfaz en bandas

- **Sin marcos en el overworld.** Cada ventana es una banda que cruza la pantalla entera por las filas o columnas donde iba el marco: horizontal si la ventana es más ancha que alta, vertical si no. Va así para todas: caja de diálogo, carteles, menú de inicio, Sí/No, multichoice, ventanas de datos. Las posiciones son las de antes, solo que la banda no se recorta.
- **Pop-up del nombre del mapa:** una sola banda arriba, con la hora a la derecha. Se han quitado los gráficos y paletas BW y la ventana secundaria.
- **Una paleta, la 15** (`sPaletaBandas` en `menu.c`). La banda es un tile liso del color 1, el mismo con el que se rellenan las ventanas. Los colores del texto se dan la vuelta: banda oscura, letras claras y sombra oscura, y lo mismo con los colores. BG0 se mezcla con el mapa. No se carga ningún gráfico de marco.
- **Fuera del overworld** (mochila, equipo, PC, combate…) siguen los marcos de siempre. `gVentanasEnBandas` lo enciende el overworld al crear sus ventanas, e `InitWindows` lo apaga al cambiar de pantalla.
- **15 paletas para el mapa (0-14).** `NUM_PALS_IN_PRIMARY` es 15. El tinte de la hora del día y el del tiempo atmosférico llegan hasta la 14 y dejan fuera la 15. `Principal` lleva la 13 y la 14 vacías; `CentroPokemon` ya las tenía.

### Fase 5: motor para pintar en porymap

**Cambio de enfoque.** El primer intento pintaba los mapas fuera de porymap: tres PNG por mapa más el borde, que se compilaban al tileset (`07b1da5e`, `fd2e7770`). Se descartó (`00924135`) porque obliga a exportar y a mantener el tamaño a mano. Además, `make` recompilaba desde los PNG y podía revertir lo pintado en porymap.

**Lo que hay ahora** es porytiles dentro de porymap, pintando el mapa (`8c856420`); está explicado en `tools/mapeado/README.md`:

- **Estampar:** una pieza, cualquier PNG de lado múltiplo de 8 y sin paleta fijada, se estampa en una capa (baja, media o alta) en la rejilla de 8.
  - El tileset se rellena en ese momento: colores, tiles con volteos y un metatile por arte nuevo.
  - El metatile nuevo hereda el comportamiento y el nivel de la casilla. La colisión no cambia.
  - Si no hay hueco de paletas, tiles o metatiles, o un trozo tiene más de 15 colores, no se pinta nada y se dice qué falta.
- **Optimizar:** reempaqueta el tileset desde lo pintado. Junta duplicados, quita lo que no usa ningún mapa y libera tiles y colores. Respeta atributos, colisión, números y fijados.
- **Fuente:** siguen siendo el tileset y el blockdata. No hay arte aparte.
- **Biblioteca:** es C++ y no lee archivos ni depende de nada. La usa el fork de porymap, y también la línea de comandos `tools/mapeado/mapeado estampar | optimizar | cuentas | exportar`.
- **Limpieza de los tilesets:** al pasar por el compilador se juntaron los metatiles duplicados (11 casillas cambian de número en `Test` y 5 en el Centro) y se quitaron los que no usaba nadie. El tileset de `Test` pasa de 128 a 69 metatiles y el del Centro de 128 a 72. Los tiles y las paletas no cambian.

### Fase 5: el editor, en el fork de porymap

El fork está en [ivaantxo/porymap](https://github.com/ivaantxo/porymap), rama `claude/rediseno-mapeado-plan-5296ti`. Estaba en la 5.4.1 (diciembre de 2024) y se ha puesto sobre la 6.3.1, la última. Lo nuevo está explicado en su `README.md`:

- **Pestaña Piezas,** junto a Metatiles, Collision y Prefabs:
  - una biblioteca de piezas: cualquier PNG de lado múltiplo de 8, sin paleta fijada. De una hoja se elige con el ratón el trozo que se estampa. La lista se guarda en `porymap.user.cfg`;
  - la capa donde se estampa (baja, media o alta), la rejilla (8 o 16 px) y si lo transparente borra;
  - las capas que se ven, solo mientras la pestaña está abierta;
  - los contadores de tiles, paletas y metatiles en uso, y el botón *Optimizar tileset*.
- **Estampar:** con la pestaña abierta y el lápiz, la pieza sigue al ratón como vista previa; un clic la estampa y arrastrando se repite. Cada trazo se deshace de una vez con Ctrl+Z. Lo que añade al tileset no se deshace, para que rehacer lo encuentre; optimizar limpia lo que sobre.
- **Si no cabe:** no se pinta nada. El panel dice qué falta y sale un aviso con la opción *Optimizar y reintentar*.
- **Optimizar:** reempaqueta el tileset desde todos los mapas que lo usan, guarda el tileset y esos mapas, y vacía su historial de deshacer (avisa antes).
- **Guardar:** el tileset estampado se guarda con el mapa, y cuenta como cambio pendiente al cerrar.
- **Con el editor de tilesets:** si está abierto, se actualiza al estampar. Si tiene cambios sin guardar, no deja estampar ni optimizar hasta que se guarden o se descarten, porque trabaja sobre su propia copia del tileset.
- **El motor** es una copia tal cual de `tools/mapeado/mapeado.{h,cpp}` en `src/lib/mapeado`; `src/core/stamping.cpp` la conecta con los tilesets y layouts de porymap. Los cambios se hacen primero en albor.
- **Camino inteligente con piezas** (`7b4bdbea` en el fork): una pieza de 48×48 es también un juego de camino de 3×3. Con *Smart Paths* (o Mayús) el lápiz pinta como el camino inteligente de porymap, pero decide qué casillas son camino por su arte en la capa elegida, no por el número de metatile. Así da igual lo que haya debajo y optimizar no lo rompe.
- **El camino inteligente de siempre,** con metatiles, va por números: optimizar le quitaba las variantes sin usar y podía pasar casillas a una copia con otro número. Ahora optimizar deja siempre en su sitio los metatiles de los prefabs (además de los que tienen nombre): basta con guardar cada juego de camino como un prefab de 3×3.
- **Un solo tileset por layout** (`99086e0b` en el fork): con `NUM_TILESETS_PER_LAYOUT` a 1, el primario lo tiene todo (hasta 1024 tiles y 16 paletas), no se carga ningún secundario ni sus paletas, el secundario desaparece de la interfaz y `layouts.json` se guarda sin él.
- **CI:** al lanzar a mano el workflow *Build Porymap* desde la pestaña Actions del fork, el job de macOS sube el `.dmg` como artefacto descargable (`70d0677a` en el fork).

### Paletas por mapa

Antes las 15 paletas eran del tileset entero: todos los mapas cargaban las mismas, y lo que se pintaba en uno se quedaba ocupando sitio en los demás. Ahora:

- **El tileset guarda las paletas de todos sus mapas,** hasta 256 (`MAX_PALS_IN_TILESET` en `fieldmap.h`). Están en `palettes/00.pal`, `01.pal`…, y el Makefile las junta en `palettes.gbapal` (regla en `graphics_file_rules.mk`), que `graphics.h` incluye de una vez. Una paleta nueva no hay que apuntarla en ningún sitio.
- **Cada entrada de metatile lleva su paleta del tileset** en `metatile_palettes.bin`, un byte por entrada (`.metatilePalettes` en `headers.h`). En `metatiles.bin` quedan los 4 bits bajos. `Principal` y `CentroPokemon` se han pasado tal cual: cada entrada con la paleta que ya tenía.
- **Cada mapa carga solo las paletas de sus metatiles** (casillas y borde), como mucho 15. No se guarda en ningún sitio: se calcula cada vez, en el editor y en el juego, así que no se arrastra ninguna de un mapa a otro.
- **En el juego,** `LoadMapTilesetPalettes` recorre el blockdata al cargar el mapa y pone sus paletas en los huecos 0-14, por orden; los que sobran quedan en negro. `GetMetatileTilesForMap` da las entradas de un metatile con el hueco de cada paleta, y lo usan el dibujo del mapa, la tienda y las puertas (sus números de paleta son ya paletas del tileset). Una paleta que el mapa no cargó al entrar (un `setmetatile`, una puerta) se carga al dibujarla en un hueco libre. La versión de noche de `swapPalettes` también va por paleta del tileset.
- **Al pintar,** un trozo de 8×8 va primero a una paleta que el mapa ya carga y tiene sus colores; luego a una del tileset que los tenga (el mapa la carga y aprovecha sus tiles); luego a una cargada con sitio; y, si el mapa aún puede cargar otra, a una con parte de los colores, a una que no use nadie o a una nueva. Un metatile que ya tiene el arte se reutiliza si el mapa puede cargar sus paletas.
- **Al optimizar,** los trozos se reparten para que cada mapa cargue las menos paletas posibles, y sin compactar se quedan donde estaban si se puede.
- **Avisos nuevos:** el mapa ya carga las 15 y no les caben los colores; la pieza necesita más paletas nuevas de las que le quedan al mapa; el tileset ya tiene las 256.
- **En el fork de porymap** (`c1d11581`): carga todas las paletas de la carpeta y pinta cada tile con su paleta del tileset. Los editores de tilesets y de paletas eligen entre todas. El contador de la pestaña Piezas dice cuántas paletas carga el mapa (en rojo si pasa de 15 pintando metatiles a mano) y cuántas usa el tileset. Al guardar escribe las paletas nuevas y `metatile_palettes.bin`.

### Animaciones, y fuera porytiles

Porytiles era lo único que sabía meter animaciones de tiles. Con las paletas por mapa ya no se puede usar (rehace el tileset entero desde sus fuentes), así que el pipeline las importa él:

- **Una animación** son unos tiles seguidos del tileset y sus fotogramas, con todos sus colores en una paleta. Se importa desde una carpeta con `00.png`, `01.png`… (los de `desarrollo/graficos/animaciones` sirven tal cual), con un nombre y cuánto dura cada fotograma. Reserva tiles libres y una paleta; importarla otra vez con el mismo nombre la cambia en sus mismos tiles.
- **Al pintar,** el arte igual al fotograma 0 (también volteado) usa los tiles animados. Lo pintado antes de importarla se anima al optimizar, que además deja cada animación en sus tiles y le ajusta los fotogramas si mueve sus colores.
- **En el juego,** `animations.bin` (`.animations` en `headers.h`) lleva una ficha por animación y sus fotogramas en 4bpp. `tileset_anims.c` copia cada fotograma a la VRAM cuando toca, en la segunda ranura de animación. La primera se queda para el `callback` de siempre.
- **Dónde:** `tools/mapeado/mapeado animar <tileset> <nombre> <carpeta> [--cada N]` (y `--quitar`), y en el fork (`cbee81ee`), *Animaciones del tileset* en la pestaña Piezas: importar, elegir (la pone como pieza y la reproduce) y quitar.
- **Fuera porytiles:** la carpeta `porytiles/` (binario, librerías y su tileset de prueba), `metatile_behaviors_porytiles.h`, sus órdenes en `desarrollo/notas_desarrollo.md` y el paso que lo explicaba aquí.

### Piezas con sus paletas

Para trabajar con una hoja hecha en Aseprite, con todo el arte ya organizado por paletas: si una pieza es un PNG indexado con la paleta en filas de 16 colores (el 0 de cada fila, transparente) y cada trozo de 8×8 usa colores de una sola fila, cada fila es una paleta. Al estampar va a una paleta del tileset con esos colores en esos índices (la que ya la tenga, o una nueva con la fila entera) y los tiles guardan los índices de la imagen. Optimizar deja cada trozo en la paleta donde estaba, si puede, así que las filas no se mezclan. Si la pieza no cumple, se reparte sola como siempre; porymap dice debajo de la pieza qué modo usa y por qué. Las animaciones indexadas así usan también su fila.

## Cómo se ha comprobado

- **Compilación en cloud** con arm-none-eabi-gcc 13.2, sin avisos (`-Werror`). Hubo que compilar SuperFamiconv 0.9.2 para Linux, porque el de `tools/superfamiconv/` es un binario de Mac; se pasó con `FAMICONV=` sin tocar el repo.
- **Emulador:** con libmgba, el mismo recorrido por `Test` con la ROM de antes y con la de cada fase. El recorrido choca con árboles, pisa hierba alta y llega al borde. En los dos casos el jugador acaba en las mismas casillas, con la misma altura y el mismo comportamiento, y las 9 capturas salen idénticas píxel a píxel.
- **`CentroPokemon`** no se puede alcanzar sin warp. Se ha comprobado por datos: mismo ID y colisión en cada casilla, y el tileset solo usa las paletas 0-5.
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
- **Fork de porymap,** compilado con Qt 6.4 y con Qt 5.15, sin avisos en lo nuevo, y probado abriendo albor en una pantalla virtual:
  - estampar una flor de 16×16 a media casilla da exactamente los mismos `map.bin`, metatiles, atributos, tiles y paletas que `mapeado estampar` con la misma pieza y posición;
  - optimizar desde porymap da los mismos archivos que `mapeado optimizar`;
  - deshacer y rehacer un estampado, y un arrastre entero con un solo Ctrl+Z;
  - el aviso de paletas llenas con una pieza imposible, sin tocar nada;
  - importar una pieza, elegir un trozo de una hoja, la rejilla de 16 y la capa baja;
  - ocultar capas;
  - el editor de tilesets abierto muestra los metatiles recién estampados;
  - con albor sin secundario: el panel del layout solo muestra el tileset, el editor de tilesets abre, estampar funciona y guardar todo deja `layouts.json` igual, sin `secondary_tileset`;
  - un metatile sin usar que está en un prefab sobrevive a optimizar, y otro sin usar fuera de prefabs se quita;
  - camino inteligente con una pieza de 48×48: un clic deja un cuadrado redondeado de 2×2, un arrastre en L forma el camino con sus bordes, y después de optimizar el camino se sigue alargando y enlaza con lo pintado antes.
- **ROM sin secundario:** compila, y el recorrido de siempre sale idéntico.
- **15 paletas, en emulador:** una tira estampada con piezas en las paletas 0, 1 y 6-14 da 154 colores en pantalla, y siguen ahí con el menú de inicio y las ventanas de guardado abiertas.
- **Paletas por mapa:**
  - la línea de comandos pasa 38 escenarios. Entre los nuevos: un mapa que llega a sus 15 paletas y el aviso con la siguiente; una pieza que necesita más paletas de las que quedan; un segundo layout con el mismo tileset que no carga las de `Test` y estrena la paleta 15 del tileset; repetir allí lo pintado en `Test`, que carga sus paletas sin crear ni tiles ni colores; y optimizar y compactar con los dos mapas, que se siguen viendo igual píxel a píxel;
  - en emulador, el recorrido de siempre sale idéntico píxel a píxel con las paletas por mapa. También al mover las cuatro paletas de `Test` a las 20-23 del tileset y poner a 15 sus 4 bits en `metatiles.bin`: el juego tiene que leerlas de `metatile_palettes.bin` para que salga bien;
  - ocho trozos estampados con colores nuevos, que estrenan ocho paletas, salen en el juego con sus 120 colores (con el tinte de la noche, que es lineal sobre cada color);
  - en el fork: estampar en `Test` sube el contador de 4 a 12 paletas; la pieza siguiente avisa de que no caben; en otro layout con el mismo tileset se estrena la paleta 15; al guardar salen `15.pal` y `metatile_palettes.bin`, que el juego compila y pinta; al volver a abrir se ve igual; el editor de tilesets deja elegir la paleta 15, y optimizar no cambia nada.
- **Animaciones:**
  - la línea de comandos pasa 23 escenarios con `mar` (32 fotogramas de 32×32): los fotogramas guardados se ven tal cual con su paleta; estampar el fotograma 0, también volteado, usa los tiles animados sin tiles ni colores nuevos; el agua pintada antes de importar se anima al optimizar; optimizar y compactar no cambian ni los fotogramas ni el mapa; cambiarla por `mar_buceo` deja sus tiles; una de otro tamaño, una con más de 15 colores y un mapa sin hueco para su paleta avisan sin tocar nada; y quitarla deja el mapa igual;
  - en emulador, dos charcos de `mar` estampados junto al jugador pasan por los fotogramas 4, 5, 6, 7, 8 y 9, uno cada 8 fotogramas del juego, cada uno igual píxel a píxel que el PNG (con el tinte de la noche);
  - en el fork: importar `mar` desde la carpeta, verla reproducirse en la vista de la pieza, estamparla y guardar da los mismos archivos que `mapeado animar` y `mapeado estampar`; al volver a abrir sigue ahí, y quitarla funciona.
- **Piezas con sus paletas:** 9 escenarios con una hoja indexada de dos filas: crea justo dos paletas, que son las filas color a color; los tiles tienen los índices de la imagen; el 0 de la segunda fila (índice 16) sale transparente; repetirla, o estampar parte de una fila, no crea nada; un trozo que mezcla filas se reparte solo; optimizar deja las filas en sus paletas con los mismos índices; y un mapa sin hueco avisa de qué fila no cabe. En el fork, la misma hoja dice «con las paletas de la imagen» y al estamparla da los mismos archivos que la línea de comandos.
- **Sin probar en ejecución:**
  - agua, puentes y rampas (no hay ninguno en los mapas);
  - el cruce de conexiones y las partidas guardadas;
  - el multichoice de los scripts: es el mismo camino que el menú de inicio y la ventana usa la paleta 15, pero no hay ninguno en `Test`;
  - en el fork, el bloqueo de estampar cuando el editor de tilesets tiene cambios sin guardar: no conseguí provocar esos cambios a mano en la pantalla virtual;
  - el fork en macOS: solo se ha compilado en Linux.
- **La ficha de entrenador** ("Ivantxo" en el menú) se queda en negro en el emulador. Pasa igual con la ROM de antes de estos cambios, así que no viene de aquí; no lo he investigado.

## Lo que tienes que hacer tú en local

1. **Usar el fork de porymap:** el original ya no abre albor, porque los layouts no tienen secundario.
2. **`porymap.project.cfg`** (está en `.gitignore`), para editar el nivel desde el editor de tilesets:
   ```
   metatile_terrain_type_mask=0x00000F00
   regex_terrain_types=\bMETATILE_NIVEL_
   ```
   Las máscaras del bloque no hace falta tocarlas: porymap las lee de `include/global.fieldmap.h`.
3. **Conseguir el fork.** Dos formas:
   - **Descargarlo:** en la pestaña Actions de `ivaantxo/porymap`, activar los workflows (en los forks vienen apagados), lanzar *Build Porymap* sobre la rama `claude/rediseno-mapeado-plan-5296ti` y bajar el artefacto `porymap-macos-latest` (o `-15-intel`). No está firmado: la primera vez hay que abrirlo con clic derecho → Abrir.
   - **Compilarlo:** `brew install qt`, y en la rama del fork `qmake porymap.pro && make`.
4. **Porytiles ya no se usa.** Rehace el tileset entero desde sus fuentes: borraría lo pintado en porymap, cambiaría los números de los metatiles y volvería a 16 paletas para todo el tileset. Se ha quitado del repo. Las hojas de `desarrollo/graficos` sirven como piezas, y sus animaciones se importan con la pestaña Piezas o con `tools/mapeado/mapeado animar`.
5. **Partidas guardadas de antes de la fase 1:** la vista del mapa que se guarda al salvar está en el formato viejo. Las casillas alrededor del jugador se verán mal hasta recargar el mapa. Mejor empezar partida nueva.

## Para seguir

- **Texto como sprites,** si quieres la paleta 16 para el mapa. Con el texto en sprites, BG0 y la paleta de fondo 15 quedan libres, pero:
  - las bandas pasan a ocupar paletas y memoria de sprites;
  - la mezcla con el mapa sigue funcionando (los sprites semitransparentes usan los mismos coeficientes que BG0);
  - en porymap ya no hay que hacer nada: el fork admite las 16 paletas con `NUM_PALS_IN_PRIMARY` a 16.
- **Limpieza pendiente, fuera de este plan:** los 50 secundarios y `General` de pokeemerald, que no usa nadie. Sus animaciones en `tileset_anims.c` siguen escritas para el secundario en la posición 512 y ahora apuntarían fuera del tileset si alguien las activara.

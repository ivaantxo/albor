# Rediseño del mapeado: informe de ejecución

Estado a 3 de octubre de 2026 de lo que pide `rediseno-mapeado.md`, en la rama `claude/rediseno-mapeado-plan-5296ti`. Las fases 0, 1 y 2 están hechas, compilan y están probadas en emulador. La 3 espera tu confirmación. La 4 casi no hace falta, porque porymap se configura sin fork. La 5 necesita el fork y dos decisiones. La 6 es para después.

| Fase | Estado | Commit |
| --- | --- | --- |
| 0. Exploración | Hecha. Este documento | — |
| 1. Bloque nuevo y elevación | Hecha | `5426c692` |
| 2. Tileset único | Hecha, con una capa de compatibilidad para porymap | `f064ba26` |
| 3. UI a una paleta | Sin hacer: el plan la deja "si se confirma" | — |
| 4. Fork de porymap, base | Casi todo resuelto con configuración (ver abajo) | — |
| 5. Pintado por capas y compilador | Sin hacer: fork en otro repo y decisiones pendientes | — |
| 6. Cambios por zona | Sin hacer: el plan la deja para después | — |

Aparte, `db48160d` arregla un fallo del Makefile que salió al probar la fase 1: `maps.o` no dependía de los `map.bin` ni de los `border.bin`. Pintar en porymap sin tocar `layouts.json` dejaba el mapa viejo dentro de la ROM.

## Dónde el código contradice al plan

1. **El bloque ya no era el de pokeemerald.** Era ID de 12 bits, colisión de 1 y elevación de 3 (0-7). El puente es `MAX_ELEVATION_LEVEL` = 7, no 15. Se ha mantenido 7.
2. **Solo hay dos mapas, `Test` y `CentroPokemon`, sin conexiones ni warps.** Ninguno usaba su secundario: los IDs llegan a 87 y 123, por debajo del primario, y las paletas a la 5. Los 50 secundarios y el `General` de pokeemerald no los usa ningún mapa. La "zona piloto" de la fase 2 no tenía blockdata que convertir.
3. **La elevación 0 solo aparecía en casillas bloqueadas.** Las casillas que se pisan tenían todas 3. Derivarla del metatile no pierde nada en estos mapas.
4. **Atributos de metatile:** los bits 8-11 estaban libres. El dibujo a triple capa no mira el layer type (solo las puertas, con `0xFF`); `shop.c` sí lo usa.
5. **Paletas de la interfaz en el overworld:** el marco de menú, el popup de nombre y la transición de cueva usan la 14, y la caja de diálogo la 15. **La 13 no la carga ninguna ventana del overworld**; solo pantallas aparte (bolsa, MTs, PC, mapa, combate). Además, el tiempo atmosférico ya la tiñe como paleta del mapa (`sBasePaletteColorMapTypes` en `field_weather.c`: 0-13 sí, 14 y 15 no). En cambio, el tinte de la hora del día la deja fuera, y un comentario de `overworld.c` la cuenta como interfaz. Conviene confirmarlo jugando antes de darla al mapa. Si se confirma, el mapa puede tener 14 paletas sin la fase 3, y 15 con ella.
6. **Porymap no admite un tileset único.** Rechaza un layout sin secundario y un proyecto sin ningún secundario. Además recorta el primario a total − 1 en tiles y en paletas (comprobado en el código de porymap 6.3.1). Por eso la fase 2 lleva la capa de compatibilidad descrita abajo. Porytiles sí acepta primario = total.
7. **Puertas:** `field_door.c` usa los 16 últimos tiles de la VRAM (1008-1023). El tileset único se queda con 1008 tiles y no 1024.
8. **Paletas de noche:** la versión de noche de la paleta N va en la (N + 9) % 16 del mismo tileset. Con 13 paletas de día no caben las de noche de todas. Ningún tileset actual las usa.
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

- **El motor carga un tileset por layout** (`MapLayout.tileset`). Admite hasta 1008 tiles, 32767 metatiles y 13 paletas. Solo copia los tiles reales del tileset.
- **Conexiones:** al cruzar una, solo se recarga si el mapa nuevo usa otro tileset. En ese caso, lo que queda en pantalla del mapa anterior se ve mal hasta que sale. Conviene que los mapas conectados compartan tileset, como pide el plan.
- **Capa de compatibilidad para porymap:**
  - `fieldmap.h`: el "primario" que ve porymap es el tileset (1008 tiles, 13 paletas). Hasta el total quedan los tiles de las puertas y la paleta 13, que el juego no carga.
  - `gTileset_Reservado`: secundario vacío que solo ve porymap. Los dos layouts lo llevan en `layouts.json`, y `mapjson` ya no pasa el secundario al juego.
  - Cuando exista el fork, se quita la capa y `NUM_PALS_TOTAL` deja de importar.

## Cómo se ha comprobado

- **Compilación en cloud** con arm-none-eabi-gcc 13.2, sin avisos (`-Werror`). Hubo que compilar SuperFamiconv 0.9.2 para Linux, porque el de `tools/superfamiconv/` es un binario de Mac; se pasó con `FAMICONV=` sin tocar el repo.
- **Emulador:** con libmgba, el mismo recorrido por `Test` con la ROM de antes y con la de cada fase. El recorrido choca con árboles, pisa hierba alta y llega al borde. En los dos casos el jugador acaba en las mismas casillas, con la misma altura y el mismo comportamiento, y las 9 capturas salen idénticas píxel a píxel.
- **`CentroPokemon`** no se puede alcanzar sin warp. Se ha comprobado por datos: mismo ID y colisión en cada casilla, y el tileset solo usa las paletas 0-5.
- **Porytiles 0.0.7,** compilado para Linux, genera `principal` con los límites nuevos.
- **Porymap:** comprobado leyendo su código (6.3.1), sin abrirlo. Revisado: máscara de elevación 0, carpeta por defecto del secundario vacío, recorte de límites y lista de "terrain type".
- **Sin probar en ejecución:** agua, puentes y rampas (no hay ninguno en los mapas), el cruce de conexiones y las partidas guardadas.

## Lo que tienes que hacer tú en local

1. **`porymap.project.cfg`** (está en `.gitignore`), para editar el nivel desde el editor de tilesets:
   ```
   metatile_terrain_type_mask=0x00000F00
   regex_terrain_types=\bMETATILE_NIVEL_
   ```
   Las máscaras del bloque no hace falta tocarlas: porymap las lee de `include/global.fieldmap.h`.
2. **Porytiles**, al regenerar un tileset:
   ```
   porytiles compile-primary -Wall -tiles-primary-override=1008 -tiles-total-override=1024 \
     -metatiles-primary-override=32767 -metatiles-total-override=32768 \
     -pals-primary-override=13 -pals-total-override=14 \
     -o data/tilesets/primary/<tileset> <fuentes> include/constants/metatile_behaviors_porytiles.h
   ```
3. **Partidas guardadas de antes de la fase 1:** la vista del mapa que se guarda al salvar está en el formato viejo. Las casillas alrededor del jugador se verán mal hasta recargar el mapa. Mejor empezar partida nueva.

## Para seguir

- **Paleta 13 para el mapa,** independiente de la fase 3. Primero hay que confirmar en juego que está libre (punto 5). Si lo está, son tres cambios: `NUM_PALS_IN_PRIMARY` a 14, `NUM_PALS_TOTAL` a 15 (solo para porymap) y `ULTIMA_PALETA_FONDO_DEL_MUNDO` a 13 en `overworld.c`, para que la tiña la hora del día.
- **Fase 3:** dime si la hago.
- **Fase 5, dos decisiones:**
  1. **Formato y sitio del arte por capas.** Propuesta: `data/mapeado/<Layout>/` con `baja.png`, `media.png`, `alta.png` a tamaño de mapa, y un JSON con comportamiento y colisión por casilla.
  2. **Lenguaje del compilador.** C++ si va a vivir dentro del fork, para los contadores en vivo; Python si basta con llamarlo desde el build y desde el fork como proceso aparte.
- **El fork de porymap** es otro repositorio. Esta sesión solo tiene acceso a `ivaantxo/albor`, así que hay que crearlo y darle acceso.
- **Limpieza pendiente, fuera de este plan:** los 50 secundarios y `General` de pokeemerald, que no usa nadie. Sus animaciones en `tileset_anims.c` siguen escritas para el secundario en la posición 512 y ahora apuntarían fuera del tileset si alguien las activara.

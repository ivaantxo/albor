# Rediseño del mapeado: tileset único, bloque nuevo y pintado por capas

> Documento de traspaso desde una conversación de diseño. Se escribió **sin acceso al código**: todo lo que aparece en "A verificar" debe comprobarse en el repo antes de actuar. Si el código contradice este documento, manda el código: avisa y propón.

## Contexto

- ROM hack basado en **pokeemerald**, con **metatiles triple layer** activados.
- Pipeline actual: tiles dibujados en Aseprite por capas y con paletas predefinidas → porytiles genera metatiles → mapas pintados en porymap.
- Plan aparte, fuera de este alcance pero a tener en cuenta en el reparto de VRAM y paletas: un BG adicional para una capa de efectos con transparencias (sombras, cascadas, agua), pasando los textos a sprites o compartiendo fondo.
- Preferencia de diseño: mapas sencillos, no excesivamente complejos.

## Objetivo

Pasar de "tileset → mapa" a "mapa → tileset". Cada mapa se pinta en 3 capas con arte libre dentro de un fork de porymap, y de ahí se generan automáticamente metatiles, tiles y paletas (deduplicación, flips, empaquetado de paletas), como hace porytiles pero a nivel de mapa.

## Decisiones tomadas

1. **Un solo tileset por layout; desaparecen los secundarios.** Por defecto, uno para todo el exterior.
2. **Fork de porymap.** El pintado por capas se hace dentro de porymap, no en Aseprite.
3. **Nuevo formato de bloque (`u16`):**
   - Colisión: 1 bit (pasa / no pasa).
   - Elevación: fuera del bloque.
   - Resto: ID de metatile (15 bits → hasta 32768 metatiles).
4. **Surf y puentes por behavior de metatile.** Los objetos (jugador y NPCs) conservan su propio nivel/elevación, porque es lo que decide su prioridad de sprite y si están encima o debajo de un puente. Rampas y escaleras cambian el nivel del objeto mediante behavior.

## Propuestas pendientes de confirmar

- **UI del overworld con una sola paleta de BG** en vez de tres, para que el mapa pase de 13 a 15 paletas. Implica un único estilo de marco de ventana (o todos diseñados sobre la misma paleta) y que el popup de nombre de mapa comparta esos colores.

## Restricciones del hardware y del motor

- **1024 tiles máximo por BG**: el índice de tile del tilemap tiene 10 bits. Límite duro.
- **Paletas de BG**: 16 en total; en vanilla el mapa usa 13 y el resto la UI. Cada tile 8×8 usa una sola paleta (15 colores + transparente).
- **Solo flips H/V.** El giro de 180° sale con H+V; no existe la rotación de 90°.
- **Conexiones entre mapas**: la parte visible del mapa vecino se dibuja con el tileset y las paletas del mapa actual. Con un tileset único compartido no hay problema, pero cualquier cambio por mapa (fase 6) no puede afectar a lo visible en la franja de conexión (hasta ~7 bloques en horizontal, ~5 en vertical).
- **Los metatiles crecen por combinación**: con 3 capas libres, cada combinación distinta de capas es un metatile nuevo aunque reutilice tiles. Los metatiles se agotan antes que los tiles.
- **Behavior por metatile**: la misma imagen con distinto behavior son metatiles distintos.
- **Tiles animados** (agua, flores…): tienen posiciones fijas en VRAM y hay que reservarlas.
- **IDs estables**: hay metatiles referenciados desde código y scripts (constantes `METATILE_*`, `setmetatile`, animaciones de puertas…). El compilador debe permitir fijar metatiles con nombre para que conserven su ID entre compilaciones.

## A verificar en el código (fase 0)

- Máscaras y desplazamientos del bloque (`MAPGRID_*`), el centinela `MAPGRID_UNDEFINED` y posibles máscaras hardcodeadas.
- Todos los usos de la elevación: `MapGridGetElevationAt`, tablas elevación → prioridad/subprioridad de sprite (16 entradas), comprobaciones de los valores especiales 0 y 15, colisión por desnivel (`COLLISION_ELEVATION_MISMATCH`), lógica de bajar del surf, elevación de los object events en los JSON de mapas, y funciones que preservan la elevación al cambiar un metatile.
- Carga de tilesets: carga completa en warps y recarga solo del secundario al cruzar conexiones (`LoadMapFromCameraTransition` o equivalente). Constantes `NUM_TILES_IN_PRIMARY`, `NUM_METATILES_IN_PRIMARY`, `NUM_PALS_IN_PRIMARY`, `NUM_PALS_TOTAL` y sus equivalentes totales.
- Atributos de metatile: en Emerald son `u16` (behavior en bits 0-7, layer type en 12-15). Comprobar si los bits 8-11 están libres y si la implementación de triple layer de este repo usa el layer type.
- Qué slots de paleta de BG usa la UI del overworld (caja de diálogo, ventanas de menú con marco seleccionable, popup de nombre de mapa) y quién los carga.
- Datos de guardado que almacenan bloques del mapa (vista del mapa guardada al salvar).
- Opciones de porymap para configurar el formato de bloque y el reparto primario/secundario, y opciones de porytiles para límites personalizados.

## Fases

Cada fase debe dejar el juego compilando y jugable. Commits pequeños.

### Fase 0: exploración (sin cambios)
Leer el código relevante del motor y de porymap, comprobar la lista anterior y proponer un plan detallado con los archivos a tocar. Señalar cualquier punto en que este documento esté equivocado.

### Fase 1: formato de bloque y elevación
- Nuevo layout del bloque: colisión 1 bit + ID.
- Elevación de casilla derivada del metatile: agua → 1, puente → 15, resto → 3, o bien un campo de nivel en bits libres de los atributos (preferible a meterlo en el behavior, para no multiplicar behaviors). El código que consume la elevación sigue funcionando sin cambios.
- Script de conversión del blockdata existente: colisión ≠ 0 → 1, eliminar la elevación, reubicar el ID. Avisar de las casillas cuya elevación no se pueda derivar del metatile.
- Porymap: configurar el nuevo formato de bloque (en el fork si la configuración no basta).

### Fase 2: tileset único
- Eliminar los secundarios del motor: carga, recarga al cruzar conexiones y rangos de IDs de tiles, metatiles y paletas.
- Un único tileset por layout con 1024 tiles, los metatiles que permita el nuevo bloque y todas las paletas de mapa.
- Conversión del contenido empezando por una zona piloto (General más todos los secundarios no caben en 1024 tiles).
- Mientras no exista el compilador propio, generar el tileset con porytiles si sus opciones lo permiten.

### Fase 3: UI a una paleta (si se confirma)
Independiente del resto; puede hacerse en cualquier momento.

### Fase 4: fork de porymap, base
Soporte de tileset único y del nuevo bloque, eliminar el pintado de elevación y añadir edición de atributos de metatile (behavior y nivel).

### Fase 5: modo de pintado por capas en porymap

**Editor**
- 3 capas de píxeles por mapa (baja, media, alta), con selección de capa activa y visibilidad por capa.
- Biblioteca de piezas de arte libre (sin límite de tiles) que se estampan con encaje a rejilla de 8 px como mínimo (mejor 16).
- Capas lógicas de behavior y de colisión.
- Contadores en vivo de tiles únicos, metatiles y paletas, resaltando las celdas que cuestan tiles o metatiles nuevos.

**Compilador**
- Unidad de compilación: todos los mapas que usan el tileset, no un mapa suelto. Regenera el blockdata de todos.
- Trocear en celdas de 16×16 y deduplicar (3 capas + behavior + nivel) → metatiles.
- Deduplicar tiles 8×8 con flips y empaquetar paletas.
- Respetar los IDs fijados y los tiles animados reservados.
- Salida en los formatos del proyecto: tiles, paletas, metatiles, atributos y blockdata.

**Arquitectura recomendada**
- Compilador como biblioteca + CLI, separado de la UI, para poder ejecutarlo también desde el build.
- La fuente de verdad pasa a ser el arte por capas de cada mapa; tileset y blockdata son artefactos generados. Decidir formato y ubicación en el repo.

### Fase 6: cambios por zona (opcional, posterior)
Sustituto ligero de los secundarios: overrides por mapa cargados en huecos reservados de VRAM y paletas.
- Solo paleta: no gasta tiles ni metatiles.
- Solo tiles: mismos metatiles con distinto gráfico; cada variante respeta la disposición y la paleta por tile.
- Tiles + paleta.

Regla: lo que cambia no puede aparecer en las franjas de conexión.

## Preguntas abiertas

- ¿Interiores y cuevas en el mismo tileset o en tilesets propios que se cambian al entrar por warp?
- ¿El nivel de los metatiles va en bits libres de los atributos o en behaviors?
- Encaje con el BG extra de efectos: reparto de VRAM y paletas. Si los textos pasan a sprites, compiten con las paletas de OBJ de NPCs y efectos de campo.
- ¿Qué se hace con los mapas vanilla existentes?

# Mapeado: porytiles dentro de porymap

La idea es pintar el mapa directamente con piezas de arte libre: cualquier PNG cuyo ancho y alto sean múltiplos de 8, sin paleta fijada. El tileset se rellena solo al pintar, como haría porytiles: colores, tiles de 8×8 con volteos y metatiles. Si algo no cabe, no se pinta y se dice qué falta:

- el mapa ya carga las 15 paletas que caben y a ninguna le caben los colores (o la pieza necesita más paletas nuevas de las que le quedan al mapa);
- no hay hueco para tiles;
- no hay hueco para metatiles;
- un trozo de 8×8 de la pieza tiene más de 15 colores.

La fuente siguen siendo el tileset y el blockdata, como siempre. No hay arte aparte que exportar ni que mantener del tamaño del mapa.

Esto ya está en el fork de porymap, [ivaantxo/porymap](https://github.com/ivaantxo/porymap) (rama `claude/rediseno-mapeado-plan-5296ti`), en la pestaña **Piezas**. Este directorio tiene el motor, que es lo que usa porymap, y una línea de comandos que hace lo mismo desde la terminal.

## Cómo funciona al pintar

Cada mapa tiene tres capas de píxeles:

| Capa | Qué es |
| --- | --- |
| baja | el suelo, debajo de todo |
| media | encima del suelo y debajo de los personajes |
| alta | encima de los personajes: copas de árbol, tejados |

Una pieza se estampa en una capa, en la rejilla de 8 píxeles. Lo transparente de la pieza (alfa 0, o el magenta 248,0,248) deja ver lo que había debajo; con `--reemplazar`, lo borra. Por cada casilla de 16×16 cuyo arte cambia:

1. **Metatile:** si ya hay uno con ese arte, la casilla pasa a él (al que tenga sus mismos atributos, si puede ser). Si no, se crea uno en un hueco del tileset y hereda el comportamiento y el nivel que tenía la casilla.
2. **Colores:** cada trozo de 8×8 va a una paleta, en este orden (ver *Paletas por mapa*):
   1. una que el mapa ya carga y tiene todos sus colores;
   2. una del tileset que los tenga todos, si el mapa puede cargar una más;
   3. una que el mapa ya carga y tiene sitio para los colores que faltan;
   4. si el mapa aún puede cargar otra, una del tileset que ya tenga parte de los colores, una que no use nadie o una nueva.
3. **Tiles:** se reutilizan si ya están, tal cual o volteados; si no, se añaden.
4. **Colisión:** la casilla conserva la suya.

El comportamiento, el nivel y la colisión se editan aparte, como siempre en porymap. Pintar no los toca.

Cuando el tileset se llena, `optimizar` lo reempaqueta desde lo pintado:

- junta metatiles duplicados;
- quita los que no usa ningún mapa;
- deja libres los tiles y colores que sobran;
- reparte los colores para que cada mapa cargue las menos paletas posibles.

Se conservan los atributos, la colisión y los números de lo que sigue. También los **metatiles fijados**, los que tienen nombre en `include/constants/metatile_labels.h`, porque los usa el código aunque no estén en ningún mapa. Los **tiles fijos** que lista `tiles_fijos.txt`, junto al `tiles.png` (números o rangos `a-b`, para animaciones), no se tocan nunca.

Los límites son los de `include/fieldmap.h` y `include/global.fieldmap.h`: 1008 tiles, 32767 metatiles, 256 paletas en el tileset y 15 por mapa.

## Paletas por mapa

El tileset guarda las paletas de todos sus mapas, hasta 256 (`MAX_PALS_IN_TILESET`). Cada mapa carga solo las que usan sus metatiles, los de sus casillas y los de su borde, como mucho 15 a la vez (`NUM_PALS_IN_PRIMARY`). Una entrada de metatile usa su paleta si su tile no es el 0, que es el transparente.

Qué paletas carga un mapa no se guarda en ningún sitio: sale de sus metatiles cada vez. Así no se arrastra ninguna de un mapa a otro, ni al pintar ni en el juego.

- **Al pintar,** los colores nuevos van primero a las paletas que el mapa ya carga. Si una pieza repite colores que están en una paleta del tileset, el mapa carga esa paleta y aprovecha sus tiles, en vez de duplicar nada.
- **Al optimizar,** cada trozo de 8×8 va a la paleta que menos paletas nuevas haga cargar a los mapas donde sale. Sin `--compactar` se queda, si puede, en la paleta donde estaba.
- **En el juego,** `LoadMapTilesetPalettes` (`src/fieldmap.c`) mira el blockdata al cargar el mapa y pone sus paletas en los huecos 0-14, por orden. Al dibujar, cada entrada lleva el hueco donde está su paleta. Si un script pone un metatile con una paleta que el mapa no cargó, se carga entonces en un hueco libre; si no queda ninguno, se pinta con la del hueco 0.

Los archivos del tileset:

| Archivo | Qué es |
| --- | --- |
| `palettes/00.pal`, `01.pal`… | las paletas del tileset, seguidas desde la 00 |
| `palettes.gbapal` | todas juntas, lo hace el Makefile (`graphics_file_rules.mk`); `graphics.h` lo incluye con un solo `INCBIN`, así que una paleta nueva no hay que apuntarla en ningún sitio |
| `metatiles.bin` | las entradas de siempre; los 4 bits de paleta son los bajos de la paleta del tileset |
| `metatile_palettes.bin` | la paleta del tileset de cada entrada, un byte por entrada (`.metatilePalettes` en `headers.h`) |

Si `metatile_palettes.bin` no cuadra con `metatiles.bin` (porque porytiles ha regenerado el tileset, por ejemplo), vale la paleta de los 4 bits y se vuelve a escribir al guardar.

## Línea de comandos

Se ejecuta desde la raíz del proyecto:

```
tools/mapeado/mapeado estampar <mapa> <capa> <x> <y> <pieza.png> [--reemplazar]
tools/mapeado/mapeado optimizar [tileset...] [--compactar]
tools/mapeado/mapeado cuentas [tileset...]
tools/mapeado/mapeado exportar <mapa> <carpeta>
```

- `estampar`: `x` e `y` son píxeles, múltiplos de 8. El mapa se nombra por su layout: `Test`, `Test_Layout` o `LAYOUT_TEST`.
- `optimizar --compactar`: además renumera desde cero, para quitar los huecos.
- `cuentas`: lo que ocupa cada tileset ahora, y lo que ocuparía optimizado, con las paletas que carga cada mapa.
- `exportar`: saca las tres capas en PNG, solo para mirarlas.

## La biblioteca y el fork de porymap

La biblioteca es `mapeado.h` + `mapeado.cpp`. No lee ni escribe archivos ni depende de nada: trabaja con el tileset y los mapas en memoria.

- **`Estampar`:** lo que hace la herramienta de pintar. Si no cabe, devuelve el motivo y no toca nada.
- **`Optimizar`:** el botón de reempaquetar.
- **`PintarLayout`:** las capas por separado.
- **`PaletasDelMapa`:** las paletas del tileset que carga un mapa.

El fork de porymap lleva una copia tal cual en `src/lib/mapeado`, y `src/core/stamping.cpp` la conecta con sus tilesets y layouts. Los cambios se hacen aquí primero y se copian allí. Estampar y optimizar en porymap dan los mismos archivos que esta línea de comandos.

`proyecto.cpp`, `archivo_png.cpp` y `main.cpp` son solo la línea de comandos.

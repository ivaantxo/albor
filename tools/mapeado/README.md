# Compilador de mapeado

Pasa el arte por capas de cada mapa al tileset y al blockdata. Los metatiles, los tiles y las paletas salen del arte. El comportamiento, el nivel y la colisión se editan después en porymap, y al recompilar se respetan.

## Cómo se trabaja

1. **Pinta el mapa** en tres capas, a tamaño de mapa (16 px por casilla), en la carpeta del layout (`data/layouts/<Mapa>/`):

   | Archivo | Qué es |
   | --- | --- |
   | `baja.png` | El suelo, debajo de todo |
   | `media.png` | Encima del suelo y debajo de los personajes |
   | `alta.png` | Encima de los personajes: copas de árbol, tejados |
   | `borde_baja.png`, `borde_media.png`, `borde_alta.png` | El borde de 2×2 casillas (32×32 px) que se ve fuera del mapa |

   - **Transparente:** alfa 0, o el magenta 248,0,248.
   - **Colores:** se pasan a la rejilla de 5 bits del GBA (se ignoran los 3 bits bajos).
   - **Límite:** cada trozo de 8×8 admite como mucho 15 colores.
   - **Capas que falten:** se toman como transparentes.

2. **Compila** con `make`, que lo hace solo cuando cambia el arte, o a mano con `tools/mapeado/mapeado compilar`. Se compilan juntos todos los mapas que usan el mismo tileset (`primary_tileset` en `layouts.json`). Sale el tileset (tiles, paletas, metatiles y atributos) y se reescribe el blockdata de todos esos mapas.

3. **Edita en porymap:**
   - el comportamiento y el nivel de cada metatile, en el editor de tilesets;
   - la colisión de cada casilla, en la pestaña de colisión.

   Al recompilar se conservan.

Lo que no conviene hacer en porymap es pintar metatiles con otro arte, ni retocar sus tiles: el arte de los PNG manda, y se pierde al recompilar. Lo que sí funciona: duplicar un metatile, darle otro comportamiento y pintarlo encima de casillas con el mismo arte.

## Qué se respeta al recompilar

- **Casilla cuyo arte no cambia:** se queda con su metatile, sus atributos y su colisión, también si es un duplicado con otro comportamiento.
- **Arte que ya tenía otro metatile:** usa ese metatile (el más usado, si hay varios).
- **Arte nuevo:** hereda por mayoría los atributos de los metatiles que había en las casillas donde aparece. Por ejemplo, retocar la hierba alta en todo el mapa mantiene sus encuentros.
- **Colisión:** es siempre la que tenía la casilla.
- **Números de metatile y de tile:** se conservan mientras sigan existiendo. Los nuevos van a los huecos y lo que ya no se usa deja un hueco.
- **Colores de las paletas:** se quedan en su sitio. Uno que deja de usarse se queda como hueco reutilizable.
- **Metatiles fijados:** son los que tienen nombre en `include/constants/metatile_labels.h` (`METATILE_<Tileset>_<Nombre>`; porymap los añade desde el editor de tilesets). Se conservan siempre en su número, con su arte de antes, aunque no estén en ningún mapa, porque los usa el código: `setmetatile`, puertas…
- **Tiles fijos:** los que lista `tiles_fijos.txt`, junto al `tiles.png` del tileset (números o rangos `a-b`, uno por línea, `#` comenta). Se dejan tal cual, para animaciones de tiles.

## Órdenes

```
tools/mapeado/mapeado compilar [tileset...]     # escribe tileset y blockdata
tools/mapeado/mapeado cuentas [tileset...]      # lo mismo sin escribir: cuánto ocupa y si cabe
tools/mapeado/mapeado descompilar <tileset...>  # pinta las capas desde el tileset y el blockdata de ahora
```

- **Desde dónde:** se ejecutan desde la raíz del proyecto.
- **Nombre del tileset:** con o sin `gTileset_`.
- **Sin nombrar ninguno:** `compilar` y `cuentas` hacen todos los que tengan algún mapa con arte.
- **`--compactar`:** renumera tiles y metatiles desde cero para quitar huecos. Respeta igual los atributos, la colisión y los fijados.
- **`descompilar`:** sirve para pasar al arte por capas un mapa que se pintó con metatiles. No pisa capas que ya existan si no se le pone `--forzar`.

Los límites son los de `include/fieldmap.h` y `include/global.fieldmap.h`: 1008 tiles, 13 paletas y 32767 metatiles.

## Para el fork de porymap

La biblioteca es `mapeado.h` + `mapeado.cpp`. No lee ni escribe archivos ni depende de nada: trabaja con imágenes en memoria, y `Compilar` devuelve las cuentas que hacen falta para los contadores del editor. `proyecto.cpp`, `archivo_png.cpp` y `main.cpp` son solo la línea de comandos.

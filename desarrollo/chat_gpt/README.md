# Selector de frames BW

Los sprites generados quedan en esta carpeta. El origen preferente es `desarrollo/.apng_bw` y la lista permitida es `species.txt`. Si falta el APNG de una forma o hembra, se recupera su tira exacta de `graphics/pokemon`; esa carpeta no se modifica. No se generan paletas shiny.

Empieza por [la galería](GALLERY.md), [el informe de cobertura](REPORT.md) y [los casos para revisar](REVIEW.md).

## Probar en el juego, con tamaños y animaciones

Desde la raíz del repositorio, con las selecciones ya generadas:

```sh
python3 desarrollo/chat_gpt/integrar.py
make BW_SPRITES=1 -j4
```

Abre **`albor_bw.gba`** en el emulador y utiliza el visor de sprites. `make` sin esa opción sigue produciendo `albor.gba` con los recursos habituales. La compilación BW utiliza `build_bw/` y lee los sprites directamente de esta carpeta; no es necesario copiarlos a `graphics/pokemon`.

`generated/species_info_bw.h` conserva los datos de juego y actualiza los punteros front/back, variantes hembra, paletas, dimensiones visibles, offsets y tablas de animación. Las dimensiones de `FRONT_PIC`/`BACK_PIC` describen la silueta, redondeada a tiles; el motor obtiene el lienzo 64/80/96 y las poses almacenadas del tamaño descomprimido. Los cinco/tres slots no requieren aumentar `NUMERO_FRAMES_POKEMON`. La deducción del lienzo admite un máximo de ocho poses distintas por tira.

La posición común exportada sitúa el conjunto abajo; los offsets front/back se inicializan a cero y se conserva `ELEVACION_COMO_ENEMIGO` de la especie para que puedas ajustar su altura en el visor. Machos y hembras comparten la secuencia temporal de la especie; sus dibujos, paletas y lienzos pueden diferir.

[generated/integration.json](generated/integration.json) enumera las especies activadas y las excluidas con su motivo. Una especie se activa cuando tiene todos sus front/back, incluidas las variantes hembra, tamaños compatibles y una entrada visual completa en `species_info.h`. Los tamaños excepcionales siguen intactos para tu edición. Las entradas incompletas conservan los datos anteriores en esta ROM.

Si no existe una paleta shiny creada por ti en esta carpeta, la ROM de prueba muestra los colores normales también en shiny. Cuando añadas `shiny.pal` o `shinyf.pal`, ejecuta otra vez `integrar.py` para enlazarla. Debe mantener los mismos índices que su paleta normal. El generador no crea esos archivos.

Después de cambiar selecciones o datos de especie, repite los dos comandos. Make también regenera la integración cuando cambian sus entradas conocidas; añadir archivos nuevos, como una paleta shiny, requiere ejecutar `integrar.py` explícitamente. Tras limpiar `selection.json`, los C ya generados siguen sirviendo para compilar; para regenerarlos tendrás que recuperar las selecciones con `build`.

## Definitivos para testing y limpieza posterior

**`anim_front.png` y `back.png` ya son los definitivos de la selección.** Las imágenes `*_selected.png` muestran esos mismos frames ampliados, con fondo y etiquetas. No hay que renombrarlas ni convertirlas para probar los sprites.

[gestionar_sprites.py](gestionar_sprites.py) facilita preparar una carpeta que contenga solamente los definitivos. No necesita Pillow. Estos comandos se ejecutan desde la raíz del repositorio:

```sh
# Mostrar el plan de exportación, sin escribir nada:
python3 desarrollo/chat_gpt/gestionar_sprites.py exportar

# Copiar los definitivos a desarrollo/chat_gpt/pokemon_definitivos/:
python3 desarrollo/chat_gpt/gestionar_sprites.py exportar --aplicar
```

Se copian `anim_front.png`, `back.png`, `normal.pal` y las variantes `anim_frontf.png`, `backf.png`, `normalf.pal` cuando existan, conservando subcarpetas y bytes originales. También copia `shiny.pal` y `shinyf.pal` si las has creado. Incluye las especies con alguna variante pendiente y los tamaños excepcionales, que seguirán necesitando tu edición antes de usarlos en el motor. La exportación no modifica los sprites de origen ni el código del juego.

Puedes añadir `--solo ARON BULBASAUR` para limitar las especies o `--destino desarrollo/mi_prueba` para elegir otra carpeta independiente. Si vuelves a exportar, los archivos idénticos se omiten; para reemplazar versiones diferentes debes añadir `--sobrescribir`.

La limpieza es un comando separado y actúa sobre `desarrollo/chat_gpt/pokemon/`:

```sh
# Mostrar qué auxiliares se borrarían:
python3 desarrollo/chat_gpt/gestionar_sprites.py limpiar --listar

# Borrarlos cuando hayas terminado de revisar:
python3 desarrollo/chat_gpt/gestionar_sprites.py limpiar --aplicar
```

Elimina únicamente las hojas `*_selected.png`, `*_source.png` y los GIF `*_preview.gif` de los stems `anim_front`, `back`, `anim_frontf`, `backf`, además de `palette.png` y `selection.json`. Conserva los definitivos, las paletas normales, los archivos personales con otros nombres y los scripts, ajustes e informes de la raíz.

Después de limpiar, la galería y los comandos `verify`/`review` perderán sus imágenes o metadatos. `build` puede regenerarlos, pero también sobrescribe los PNG definitivos: guarda una copia si los has retocado a mano.

## Resultado por especie

Dentro de `pokemon/<ruta de graphics/pokemon>/`:

| Archivo | Contenido |
| --- | --- |
| `anim_front.png` | PNG indexado, tira **vertical de 5 frames**: base, arriba/izquierda, abajo/derecha, especial 1, especial 2. |
| `back.png` | PNG indexado, tira **vertical de 3 frames**: base, arriba/izquierda, abajo/derecha. |
| `normal.pal` | JASC-PAL de 16 entradas, compartida por ambas vistas. Índice 0 = RGB 255,0,255 transparente. |
| `anim_frontf.png`, `backf.png`, `normalf.pal` | Variantes hembra. Cada pareja frontf/backf comparte normalf, que puede diferir de normal. Si una vista comparte dibujo con el macho, se registra en `shared_views` y se exporta también con la paleta hembra. |
| `*_preview.gif` | Previsualización de la animación propuesta con la paleta final. |
| `*_selected.png` | Hoja de los frames elegidos con sus índices APNG originales. |
| `*_source.png` | Hoja de todas las poses distintas de la fuente; muestra el primer índice APNG de cada pose. |
| `palette.png` | Colores e índices de la paleta. |
| `selection.json` | Índices, desplazamiento común, tamaño, fuente y hash, métricas, avisos y secuencia de reproducción. |

Las especies o variantes sin fuente quedan pendientes en el informe y en `selection.json`. No se usan los dibujos de otra forma o género para rellenarlas. `SPECIES_NONE` es un centinela y se excluye; `SPECIES_EGG` se conserva como pendiente sin número nacional. La posición en el enum **no** es el número de Pokédex.

Las tiras originales no contienen los tiempos APNG. Se conservan sus poses disponibles, sin inventar dibujos: una espalda original de una sola pose produce tres slots idénticos. Las tiras front antiguas de cuatro poses se adaptan como `[0,1,0,2,3]`; consulta los avisos de origen y selección antes de juzgarlas como una animación BW completa. Las formas mantienen las subcarpetas que utiliza el juego.

## Generar y verificar

Desde la raíz del repositorio:

```sh
python3 desarrollo/chat_gpt/selector.py build --source-sheets
python3 desarrollo/chat_gpt/selector.py verify
```

El script encuentra automáticamente el Python de `.venv` si el del sistema no tiene las dependencias. Para preparar el entorno en otra máquina:

```sh
python3 -m venv desarrollo/chat_gpt/.venv
desarrollo/chat_gpt/.venv/bin/python -m pip install -r desarrollo/chat_gpt/requirements.txt
```

Para trabajar solo sobre una selección de especies:

```sh
python3 desarrollo/chat_gpt/selector.py build --only BULBASAUR IVYSAUR --source-sheets
python3 desarrollo/chat_gpt/selector.py verify --only BULBASAUR IVYSAUR
```

`build` prepara los archivos antes de publicar y sobrescribe los resultados de las especies procesadas en **esta carpeta**. Los archivos generados que dejan de corresponder, por ejemplo al retirar una fuente hembra, pasan a `archive/`. Los archivos personales con otros nombres se conservan. Guarda tus ajustes en `overrides.json`; no edites `selection.json` esperando que el generador lo lea. Si retocas a mano los PNG finales, conserva una copia antes de volver a generarlos.

## Elegir otros frames y ajustar altura

Abre las hojas `*_source.png` y toma sus índices originales, empezando en 0. Puedes regenerarlas sin cambiar los sprites:

```sh
python3 desarrollo/chat_gpt/selector.py review --only BULBASAUR
```

Edita [overrides.json](overrides.json). Ejemplo de estructura con cinco índices front y tres back:

```json
{
  "settings": {"idle_cycles": 4, "frame_ms": 140},
  "species": {
    "BULBASAUR": {
      "default": {
        "front": {"indices": [0, 5, 9, 43, 46], "offset": [0, -2]},
        "back": {"indices": [0, 5, 2]}
      }
    }
  }
}
```

Los índices de este ejemplo son posiciones de la fuente, no los slots de salida 0–4. Omite `indices` para conservar la selección automática; puedes ajustar solamente `offset`. `offset: [x,y]` desplaza **todos los frames de esa vista**: x positivo a la derecha, y positivo hacia abajo, y negativo hacia arriba. Ningún ajuste puede recortar píxeles. Si necesitas más margen, añade `"size": 80` o `96` en esa vista. Después ejecuta `build --only BULBASAUR --source-sheets` y `verify --only BULBASAUR`.

`notes`, dentro de una especie, permite guardar una lista de observaciones que aparecerán en el informe de revisión. La entrega incluye ajustes de selección revisados visualmente para los casos donde la heurística necesitaba corrección.

Por defecto se mide la unión de las cajas visibles de los frames seleccionados, se centra horizontalmente y se coloca lo más abajo posible. La misma traslación se aplica a todos: no se elimina el salto, el balanceo ni el recorrido de las alas. Front y back se encajan por separado para usar el menor lienzo posible.

No hay reescalado. Se elige 64×64, después 80×80 y después 96×96. Si el dibujo seleccionado supera 96 en cualquiera de los ejes, se conservan **el lienzo original completo y sus coordenadas**, aunque no sean cuadrados o múltiplos de 8. Estos archivos se marcan como excepcionales para tu edición; no se fuerzan a un tamaño del motor.

## Paleta y evoluciones

Se reúnen los colores del front y back de cada variante por separado. Hasta 15 colores opacos se preservan exactamente. Si hay más, se reducen conjuntamente a 15 sin dithering; el informe lo señala. Ambos PNG y su `normal.pal` o `normalf.pal` tienen la misma tabla. La transparencia binaria ocupa exclusivamente el índice 0. Separar las paletas por sexo conserva, por ejemplo, el azul y rosa de Frillish sin mezclarlos en una única tabla de 15 colores.

Las referencias de `graphics/pokemon`, las familias evolutivas y las rampas de color guían la agrupación y el orden de oscuro a claro. Es una aproximación revisable: no garantiza reconocer cada zona anatómica ni mantener todos los índices cuando cambian el número de tonos o los colores de una evolución.

Para reordenar manualmente una paleta, añade `palette_order` a la especie: es una permutación completa de 0–15; el 0 permanece primero. Por ejemplo, `[0, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 11, 12, 13, 14, 15]` lleva los colores antiguos 6–10 a los slots 1–5. Los dos PNG de cada variante se reindexan juntos. `palette_order_female` permite un orden distinto para las hembras. Puedes documentar las zonas con `palette_groups`, por ejemplo `[{"name":"cuerpo","indices":[1,2,3,4,5]}]`; estas etiquetas son anotaciones, no cambian la cuantización.

## Añadir fuentes pendientes

Guarda el APNG correcto dentro del repositorio y especifica `source` en la vista de `overrides.json`, relativo a la raíz. Funciona también para especies posteriores, formas y hembras:

```json
{
  "species": {
    "VENUSAUR": {
      "female": {
        "front": {"source": "desarrollo/mis_fuentes/venusaur_front_hembra.png"},
        "back": {"source": "desarrollo/mis_fuentes/venusaur_back_hembra.png"}
      }
    }
  }
}
```

`catalog.py` también reconoce fuentes explícitas por nombre de especie y variante. `source_audit.json` describe los archivos inicialmente disponibles. El generador no descarga imágenes.

## Reproducción y límites de selección

Por defecto, `timing_mode` es `source`: cada intervalo APNG se asigna a una pose conservada y se suma su duración. Se redondean fronteras temporales acumuladas a ticks de pantalla (~60/s), evitando acelerar la animación al eliminar imágenes. Tres intervalos originales de cuatro ticks conservan doce ticks aunque ahora compartan una sola pose. El orden de los slots no obliga a reproducirlos en orden numérico: un vaivén puede recorrer `0 → 2 → 0 → 1`.

Front conserva la cronología y la cadencia del especial cuando se detectan; back utiliza solo el ciclo base. Si no hay un especial fiable, se propone una cadencia de cuatro vueltas y se marca para revisión. Los movimientos secundarios muy rápidos no deben ocultar el ciclo del cuerpo: se amplía el intervalo base cuando alguna pose elegida queda fuera del ciclo detectado.

Los tiempos están en `views[].timing.sequence` de `selection.json`. Los GIF y `generated/animaciones_bw.h` usan esa secuencia. Las hembras heredan los tiempos de `default` porque el motor comparte las tablas por especie. Las tiras originales sin APNG usan tiempos estimados; `settings.frame_ms` e `idle_cycles` controlan ese caso. `settings.timing_mode: "uniform"` permite aplicar el antiguo ritmo uniforme también a los APNG.

Para ajustar una especie, añade `timing` dentro de `default.front` o `default.back` en `overrides.json`. `{"idle_cycles": 3}` fija las vueltas antes del especial; `{"sequence": [{"frame":0,"ticks":12},{"frame":1,"ticks":8},{"frame":0,"ticks":12},{"frame":2,"ticks":8}]}` reemplaza la secuencia completa. Usa cinco slots front y tres back aunque el guion repita cada uno muchas veces. Después regenera la selección y la integración.

En las tablas C, [../../include/animacion_pic.h](../../include/animacion_pic.h) conserva las macros antiguas y añade `POSE_DURANTE(indice, ticks)`. Ejemplo orientativo, con cuatro vueltas base y un gesto con tiempos distintos:

```c
POSE_DURANTE(0, 12),
POSE_DURANTE(1, 8),
POSE_DURANTE(0, 12),
POSE_DURANTE(2, 8),
ANIMCMD_LOOP(3),
POSE_DURANTE(0, 18), // preparación
POSE_DURANTE(3, 6),  // gesto
POSE_DURANTE(4, 10), // culminación/vuelta
VUELTA_AL_PRINCIPIO,
```

Esto almacena cinco dibujos. Las repeticiones y las pausas añaden comandos en ROM, no nuevas poses en heap. La duración concreta depende de cada Pokémon: no hay un rate único que garantice sensación BW. Cinco front y tres back son el punto de partida; antes de añadir poses, ajusta extremos, orden y duración.

El selector busca un ciclo inicial recurrente y un gesto posterior que salga de ese ciclo. Para el especial prioriza preparación y culminación en orden temporal. Si la fuente no contiene un especial claro o suficientes poses, mantiene cinco/tres slots y emite avisos; no inventa dibujos. Las etiquetas arriba/izquierda y abajo/derecha usan el desplazamiento del centro visible, que puede verse afectado por alas o extremidades: consulta `REVIEW.md` y las hojas para decidir artísticamente.

La verificación compara cada frame exportado con su fuente y su traslación, comprueba ausencia de recortes, número de frames, índices 4 bpp, paletas compartidas, transparencia y tamaños excepcionales. `validation.json` contiene el resultado. Las pruebas de los módulos se ejecutan con:

```sh
desarrollo/chat_gpt/.venv/bin/python -m unittest discover -s desarrollo/chat_gpt -p 'test_*.py' -v
```

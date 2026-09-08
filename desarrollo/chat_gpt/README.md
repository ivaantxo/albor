# Selector de frames BW

Todo el trabajo queda en esta carpeta. El origen es `desarrollo/.apng_bw` y la lista permitida es `species.txt`. `graphics/pokemon` se lee para reproducir nombres y usar las paletas existentes como referencia de orden; no se modifica. No se generan paletas shiny.

Empieza por [la galería](GALLERY.md), [el informe de cobertura](REPORT.md) y [los casos para revisar](REVIEW.md).

## Resultado por especie

Dentro de `pokemon/<ruta de graphics/pokemon>/`:

| Archivo | Contenido |
| --- | --- |
| `anim_front.png` | PNG indexado, tira **vertical de 5 frames**: base, arriba/izquierda, abajo/derecha, especial 1, especial 2. |
| `back.png` | PNG indexado, tira **vertical de 3 frames**: base, arriba/izquierda, abajo/derecha. |
| `normal.pal` | JASC-PAL de 16 entradas, compartida por ambas vistas. Índice 0 = RGB 255,0,255 transparente. |
| `anim_frontf.png`, `backf.png`, `normalf.pal` | Variantes hembra cuando exista una fuente propia. Las vistas que el proyecto comparte con el macho se registran en `shared_views`, sin duplicar el dibujo. |
| `*_preview.gif` | Previsualización de la animación propuesta con la paleta final. |
| `*_selected.png` | Hoja de los frames elegidos con sus índices APNG originales. |
| `*_source.png` | Hoja de todas las poses distintas de la fuente; muestra el primer índice APNG de cada pose. |
| `palette.png` | Colores e índices de la paleta. |
| `selection.json` | Índices, desplazamiento común, tamaño, fuente y hash, métricas, avisos y secuencia de reproducción. |

Las especies o variantes sin fuente quedan pendientes en el informe y en `selection.json`. No se usan los dibujos de otra forma o género para rellenarlas. `SPECIES_NONE` es un centinela y se excluye; `SPECIES_EGG` se conserva como pendiente sin número nacional. La posición en el enum **no** es el número de Pokédex.

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

Se reúnen los colores de todos los frames seleccionados de una especie y de sus variantes disponibles. Hasta 15 colores opacos se preservan exactamente. Si hay más, se reducen conjuntamente a 15 sin dithering; el informe lo señala. El PNG y `normal.pal` tienen la misma tabla. La transparencia binaria ocupa exclusivamente el índice 0.

Las referencias de `graphics/pokemon`, las familias evolutivas y las rampas de color guían la agrupación y el orden de oscuro a claro. Es una aproximación revisable: no garantiza reconocer cada zona anatómica ni mantener todos los índices cuando cambian el número de tonos o los colores de una evolución.

Para reordenar manualmente una paleta, añade `palette_order` a la especie: es una permutación completa de 0–15; el 0 permanece primero. Por ejemplo, `[0, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 11, 12, 13, 14, 15]` lleva los colores antiguos 6–10 a los slots 1–5. Todos los PNG de la especie se reindexan juntos. Puedes documentar las zonas con `palette_groups`, por ejemplo `[{"name":"cuerpo","indices":[1,2,3,4,5]}]`; estas etiquetas son anotaciones, no cambian la cuantización.

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

El loop propuesto es `0 → 1 → 0 → 2`. Front repite este ciclo `idle_cycles` veces y después reproduce `0 → 3 → 4 → 0`; back repite únicamente el loop. `frame_ms` controla la duración de cada paso en la previsualización. Por defecto, el gesto aparece cada cuatro ciclos de cuatro pasos. `selection.json` guarda esta programación para trasladarla al motor; **no se modifica el código del juego ni se integra automáticamente la animación**.

El selector busca un ciclo inicial recurrente y un gesto posterior que salga de ese ciclo. Para el especial prioriza preparación y culminación en orden temporal. Si la fuente no contiene un especial claro o suficientes poses, mantiene cinco/tres slots y emite avisos; no inventa dibujos. Las etiquetas arriba/izquierda y abajo/derecha usan el desplazamiento del centro visible, que puede verse afectado por alas o extremidades: consulta `REVIEW.md` y las hojas para decidir artísticamente.

La verificación compara cada frame exportado con su fuente y su traslación, comprueba ausencia de recortes, número de frames, índices 4 bpp, paletas compartidas, transparencia y tamaños excepcionales. `validation.json` contiene el resultado. Las pruebas de los módulos se ejecutan con:

```sh
desarrollo/chat_gpt/.venv/bin/python -m unittest discover -s desarrollo/chat_gpt -p 'test_*.py' -v
```

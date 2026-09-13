# Importación de entrenadores

Fronts de 80×80 y OW de 32×32 por frame. Las tiras se leen horizontalmente, de izquierda a derecha.

## Resultado

- **314** carpetas.
- **240** fronts.
- **356** frames front.
- **58** fronts con animacion.
- **190** ow.
- **116** parejas.
- **124** solo front.
- **74** cajon de sastre.
- **116** ow recoloreados.
- **7** ow con este propio.
- **1190** frames ausentes.

## Formato y paletas

Cada carpeta contiene `front.png`, `ow.png`, `<id>.pal` e `importacion.json`. Los PNG son indexados, comparten exactamente los mismos 16 índices y el índice 0 es magenta transparente (255,0,255). Los píxeles opacos del front y su posición se conservan exactamente, también al unir sus poses en una paleta.

El OW se adapta al color más cercano del front mediante distancia CIELAB ΔE76, sin dithering. La paleta no gana colores procedentes del OW. En `originales/ow.png` está la tira anterior a esa conversión; `ow_todas_las_poses.png` conserva además todas las poses originales y `ow_celdas_fuente.png` conserva sus fondos. Las hojas aportadas tampoco se modifican. Las estadísticas y conversiones color a color están en cada `importacion.json`.

Los OW sin correspondencia segura se separan en `graphics/entrenadores/cajon_de_sastre/<id>/`. Tienen un front transparente de reserva y una paleta provisional propia hasta identificar su front. Los fronts identificados sin OW conservan nueve celdas transparentes. No se han inventado dibujos para completar ausencias.

| Frames OW | Dirección | Orden |
|---|---|---|
| 0, 1, 2 | Sur / frente | Reposo, paso izquierda, paso derecha |
| 3, 4, 5 | Norte / espalda | Reposo, paso izquierda, paso derecha |
| 6, 7, 8 | Oeste | Reposo, paso izquierda, paso derecha |
| 9, 10, 11 | Este, cuando es distinto | Reposo, paso izquierda, paso derecha |

Si la tira tiene nueve frames, el este usa el oeste reflejado. No se elimina un este dibujado si difiere por algún píxel o por su posición. En las hojas que sólo incluyen oeste se utiliza ese reflejo convencional. Las dos fases de paso conservan su orden en la fuente; el juego reproduce paso A → reposo → paso B → reposo.

## Animaciones y código

Se registran todos los fronts disponibles y todos los OW disponibles, incluidos los del cajón de sastre con su ID de procedencia. Los placeholders transparentes no se registran como recursos utilizables. Las constantes exactas aparecen en el catálogo inferior y en los metadatos.

Los fronts con varias poses usan una entrada secuencial de 12 ticks por pose y 24 en la última, y regresan al frame 0. Es una temporización propuesta, porque las hojas PNG no aportan la secuencia temporal original. Las variantes censuradas y UNUSED permanecen independientes. Los backs y el retrato alto de Barry se conservan como extras originales; no se recortan ni deforman para hacerlos pasar por un front.

El motor admite los 80×80 completos en combate y menús. Las transiciones antiguas de mugshot generan una vista temporal de 64×64 en RAM, centrada horizontalmente y alineada arriba; los archivos originales y los sprites de combate mantienen 80×80. No se asignan estos gráficos a equipos o mapas existentes automáticamente.

Ejemplo de uso en un entrenador existente: `.trainerPic = TRAINER_PIC_CYNTHIA_PLATINUM`. En un objeto de mapa: `"graphics_id": "OBJ_EVENT_GFX_CYNTHIA_PLATINUM"`. La paleta compartida se carga desde las tablas registradas, sin indicarla en el mapa.

Los IDs existentes se conservan y los nuevos se añaden al final. Revisar el diff de las constantes antes de reimportar tras añadir o renombrar entidades, porque las entradas nuevas se ordenan por ID.

## Reproducir

Desde la raíz del repositorio:

```sh
desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/inventariar_fronts.py
desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_platinum.py
desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_hgss/build_manifest.py
desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/ow_barry.py
desarrollo/chat_gpt/.venv/bin/python entrenadores/importacion/importar.py
```

Las correcciones de identidades y rectángulos se realizan en los generadores de manifiestos. El importador valida dimensiones, límites, paleta compartida, transparencia y conservación exacta de todos los fronts al guardar. Los PNG generados se reemplazan al reimportar: conserva tus modificaciones artísticas fuera de este paso o actualiza las fuentes.

## Faltantes

| Carpeta | Frames transparentes pendientes |
|---|---|
| [ace_trainer_snow_f_hgss](../../graphics/entrenadores/ace_trainer_snow_f_hgss) | OW 0–8 (sin OW identificado) |
| [ace_trainer_snow_m_hgss](../../graphics/entrenadores/ace_trainer_snow_m_hgss) | OW 0–8 (sin OW identificado) |
| [argenta_hgss](../../graphics/entrenadores/argenta_hgss) | OW 0–8 (sin OW identificado) |
| [argenta_platinum](../../graphics/entrenadores/argenta_platinum) | OW 0–8 (sin OW identificado) |
| [aroma_lady_hgss](../../graphics/entrenadores/aroma_lady_hgss) | OW 0–8 (sin OW identificado) |
| [aroma_lady_platinum](../../graphics/entrenadores/aroma_lady_platinum) | OW 0–8 (sin OW identificado) |
| [aroma_lady_unused_hgss](../../graphics/entrenadores/aroma_lady_unused_hgss) | OW 0–8 (sin OW identificado) |
| [artist_hgss](../../graphics/entrenadores/artist_hgss) | OW 0–8 (sin OW identificado) |
| [artist_platinum](../../graphics/entrenadores/artist_platinum) | OW 0–8 (sin OW identificado) |
| [battle_girl_hgss](../../graphics/entrenadores/battle_girl_hgss) | OW 0–8 (sin OW identificado) |
| [belle_and_pa_platinum](../../graphics/entrenadores/belle_and_pa_platinum) | OW 0–8 (sin OW identificado) |
| [bird_keeper_hgss](../../graphics/entrenadores/bird_keeper_hgss) | OW 0–8 (sin OW identificado) |
| [bird_keeper_johto_hgss](../../graphics/entrenadores/bird_keeper_johto_hgss) | OW 0–8 (sin OW identificado) |
| [bird_keeper_platinum](../../graphics/entrenadores/bird_keeper_platinum) | OW 0–8 (sin OW identificado) |
| [boarder_hgss](../../graphics/entrenadores/boarder_hgss) | OW 0–8 (sin OW identificado) |
| [bug_catcher_platinum](../../graphics/entrenadores/bug_catcher_platinum) | OW 0–8 (sin OW identificado) |
| [burglar_hgss](../../graphics/entrenadores/burglar_hgss) | OW 0–8 (sin OW identificado) |
| [caitlin_hgss](../../graphics/entrenadores/caitlin_hgss) | OW 0–8 (sin OW identificado) |
| [caitlin_platinum](../../graphics/entrenadores/caitlin_platinum) | OW 0–8 (sin OW identificado) |
| [cameraman_hgss](../../graphics/entrenadores/cameraman_hgss) | OW 0–8 (sin OW identificado) |
| [camper_hgss](../../graphics/entrenadores/camper_hgss) | OW 0–8 (sin OW identificado) |
| [camper_unused_hgss](../../graphics/entrenadores/camper_unused_hgss) | OW 0–8 (sin OW identificado) |
| [clown_hgss](../../graphics/entrenadores/clown_hgss) | OW 0–8 (sin OW identificado) |
| [collector_hgss](../../graphics/entrenadores/collector_hgss) | OW 0–8 (sin OW identificado) |
| [collector_platinum](../../graphics/entrenadores/collector_platinum) | OW 0–8 (sin OW identificado) |
| [cowgirl_hgss](../../graphics/entrenadores/cowgirl_hgss) | OW 0–8 (sin OW identificado) |
| [cycler_f_hgss](../../graphics/entrenadores/cycler_f_hgss) | OW 0–8 (sin OW identificado) |
| [cycler_m_hgss](../../graphics/entrenadores/cycler_m_hgss) | OW 0–8 (sin OW identificado) |
| [dahlia_hgss](../../graphics/entrenadores/dahlia_hgss) | OW 0–8 (sin OW identificado) |
| [dahlia_platinum](../../graphics/entrenadores/dahlia_platinum) | OW 0–8 (sin OW identificado) |
| [darach_hgss](../../graphics/entrenadores/darach_hgss) | OW 0–8 (sin OW identificado) |
| [darach_platinum](../../graphics/entrenadores/darach_platinum) | OW 0–8 (sin OW identificado) |
| [dawn_dp_hgss](../../graphics/entrenadores/dawn_dp_hgss) | OW 0–8 (sin OW identificado) |
| [dawn_dp_platinum](../../graphics/entrenadores/dawn_dp_platinum) | OW 0–8 (sin OW identificado) |
| [dawn_dp_unused_hgss](../../graphics/entrenadores/dawn_dp_unused_hgss) | OW 0–8 (sin OW identificado) |
| [dawn_dp_unused_platinum](../../graphics/entrenadores/dawn_dp_unused_platinum) | OW 0–8 (sin OW identificado) |
| [dawn_platinum](../../graphics/entrenadores/dawn_platinum) | OW 0–8 (sin OW identificado) |
| [dawn_platinum_hgss](../../graphics/entrenadores/dawn_platinum_hgss) | OW 0–8 (sin OW identificado) |
| [double_team_hgss](../../graphics/entrenadores/double_team_hgss) | OW 0–8 (sin OW identificado) |
| [double_team_platinum](../../graphics/entrenadores/double_team_platinum) | OW 0–8 (sin OW identificado) |
| [dragon_tamer_hgss](../../graphics/entrenadores/dragon_tamer_hgss) | OW 0–8 (sin OW identificado) |
| [dragon_tamer_platinum](../../graphics/entrenadores/dragon_tamer_platinum) | OW 0–8 (sin OW identificado) |
| [elder_hgss](../../graphics/entrenadores/elder_hgss) | OW 0–8 (sin OW identificado) |
| [ethan_hgss](../../graphics/entrenadores/ethan_hgss) | OW 0–8 (sin OW identificado) |
| [eusine_hgss](../../graphics/entrenadores/eusine_hgss) | OW 0–8 (sin OW identificado) |
| [firebreather_hgss](../../graphics/entrenadores/firebreather_hgss) | OW 0–8 (sin OW identificado) |
| [fisher_hgss](../../graphics/entrenadores/fisher_hgss) | OW 0–8 (sin OW identificado) |
| [guitarist_hgss](../../graphics/entrenadores/guitarist_hgss) | OW 0–8 (sin OW identificado) |
| [guitarist_platinum](../../graphics/entrenadores/guitarist_platinum) | OW 0–8 (sin OW identificado) |
| [hgss_ow_r01_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c04) | front 0 |
| [hgss_ow_r01_c05](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c05) | front 0 |
| [hgss_ow_r01_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c06) | front 0 |
| [hgss_ow_r01_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c10) | front 0 |
| [hgss_ow_r02_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c02) | front 0 |
| [hgss_ow_r02_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c03) | front 0 |
| [hgss_ow_r02_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c04) | front 0 |
| [hgss_ow_r02_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c06) | front 0 |
| [hgss_ow_r02_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c09) | front 0 |
| [hgss_ow_r02_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c10) | front 0 |
| [hgss_ow_r03_c01](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c01) | front 0 |
| [hgss_ow_r03_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c02) | front 0 |
| [hgss_ow_r03_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c04) | front 0 |
| [hgss_ow_r05_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r05_c02) | front 0 |
| [hgss_ow_r06_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c03) | front 0 |
| [hgss_ow_r06_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c08) | front 0 |
| [hgss_ow_r07_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c02) | front 0 |
| [hgss_ow_r07_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c06) | front 0 |
| [hgss_ow_r07_c07](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c07) | front 0 |
| [hgss_ow_r07_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c08) | front 0 |
| [hgss_ow_r07_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c09) | front 0 |
| [hgss_ow_r07_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c10) | front 0 |
| [hgss_ow_r08_c01](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c01) | front 0 |
| [hgss_ow_r08_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c02) | front 0 |
| [hgss_ow_r08_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c03) | front 0 |
| [hgss_ow_r08_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c04) | front 0 |
| [hgss_ow_r08_c05](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c05) | front 0 |
| [hgss_ow_r08_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c06) | front 0 |
| [hgss_ow_r08_c07](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c07) | front 0 |
| [hgss_ow_r08_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c08) | front 0 |
| [hgss_ow_r08_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c09) | front 0 |
| [hgss_ow_r08_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c10) | front 0 |
| [hiker_hgss](../../graphics/entrenadores/hiker_hgss) | OW 0–8 (sin OW identificado) |
| [idol_hgss](../../graphics/entrenadores/idol_hgss) | OW 0–8 (sin OW identificado) |
| [interviewers_platinum](../../graphics/entrenadores/interviewers_platinum) | OW 0–8 (sin OW identificado) |
| [jogger_hgss](../../graphics/entrenadores/jogger_hgss) | OW 0–8 (sin OW identificado) |
| [lady_hgss](../../graphics/entrenadores/lady_hgss) | OW 0–8 (sin OW identificado) |
| [lady_platinum](../../graphics/entrenadores/lady_platinum) | OW 0–8 (sin OW identificado) |
| [lass_platinum](../../graphics/entrenadores/lass_platinum) | OW 0–8 (sin OW identificado) |
| [looker_platinum](../../graphics/entrenadores/cajon_de_sastre/looker_platinum) | front 0 |
| [lucas_dp_hgss](../../graphics/entrenadores/lucas_dp_hgss) | OW 0–8 (sin OW identificado) |
| [lucas_dp_platinum](../../graphics/entrenadores/lucas_dp_platinum) | OW 0–8 (sin OW identificado) |
| [lucas_dp_unused_hgss](../../graphics/entrenadores/lucas_dp_unused_hgss) | OW 0–8 (sin OW identificado) |
| [lucas_dp_unused_platinum](../../graphics/entrenadores/lucas_dp_unused_platinum) | OW 0–8 (sin OW identificado) |
| [lucas_platinum](../../graphics/entrenadores/lucas_platinum) | OW 0–8 (sin OW identificado) |
| [lucas_platinum_hgss](../../graphics/entrenadores/lucas_platinum_hgss) | OW 0–8 (sin OW identificado) |
| [lyra_hgss](../../graphics/entrenadores/lyra_hgss) | OW 0–8 (sin OW identificado) |
| [medium_hgss](../../graphics/entrenadores/medium_hgss) | OW 0–8 (sin OW identificado) |
| [ninja_boy_hgss](../../graphics/entrenadores/ninja_boy_hgss) | OW 0–8 (sin OW identificado) |
| [ninja_boy_platinum](../../graphics/entrenadores/ninja_boy_platinum) | OW 0–8 (sin OW identificado) |
| [palmer_hgss](../../graphics/entrenadores/palmer_hgss) | OW 0–8 (sin OW identificado) |
| [parasol_lady_hgss](../../graphics/entrenadores/parasol_lady_hgss) | OW 0–8 (sin OW identificado) |
| [parasol_lady_platinum](../../graphics/entrenadores/parasol_lady_platinum) | OW 0–8 (sin OW identificado) |
| [petrel_hgss](../../graphics/entrenadores/petrel_hgss) | OW 0–8 (sin OW identificado) |
| [pi_hgss](../../graphics/entrenadores/pi_hgss) | OW 0–8 (sin OW identificado) |
| [pi_platinum](../../graphics/entrenadores/pi_platinum) | OW 0–8 (sin OW identificado) |
| [picnicker_hgss](../../graphics/entrenadores/picnicker_hgss) | OW 0–8 (sin OW identificado) |
| [picnicker_unused_hgss](../../graphics/entrenadores/picnicker_unused_hgss) | OW 0–8 (sin OW identificado) |
| [platinum_ow_b0_c01](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c01) | front 0 |
| [platinum_ow_b0_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c04) | front 0 |
| [platinum_ow_b0_c08](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c08) | front 0 |
| [platinum_ow_b0_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c09) | front 0 |
| [platinum_ow_b1_c05](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c05) | front 0 |
| [platinum_ow_b1_c06](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c06) | front 0 |
| [platinum_ow_b1_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c09) | front 0 |
| [platinum_ow_b1_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c10) | front 0 |
| [platinum_ow_b1_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c16) | front 0 |
| [platinum_ow_b2_c02](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c02) | front 0 |
| [platinum_ow_b2_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c03) | front 0 |
| [platinum_ow_b2_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c04) | front 0 |
| [platinum_ow_b2_c07](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c07) | front 0 |
| [platinum_ow_b2_c14](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c14) | front 0 |
| [platinum_ow_b2_c15](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c15) | front 0 |
| [platinum_ow_b2_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c16) | front 0 |
| [platinum_ow_b3_c02](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c02) | front 0 |
| [platinum_ow_b3_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c03) | front 0 |
| [platinum_ow_b3_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c04) | front 0 |
| [platinum_ow_b3_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c09) | front 0 |
| [platinum_ow_b3_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c10) | front 0 |
| [platinum_ow_b3_c11](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c11) | front 0 |
| [platinum_ow_b3_c12](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c12) | front 0 |
| [platinum_ow_b3_c13](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c13) | front 0 |
| [platinum_ow_b3_c14](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c14) | front 0 |
| [platinum_ow_b3_c15](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c15) | front 0 |
| [platinum_ow_b3_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c16) | front 0 |
| [platinum_ow_b4_c00](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c00) | front 0 |
| [platinum_ow_b4_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c03) | front 0 |
| [platinum_ow_b4_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c04) | front 0 |
| [platinum_ow_b4_c05](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c05) | front 0 |
| [platinum_ow_b4_c06](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c06) | front 0 |
| [platinum_ow_b4_c07](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c07) | front 0 |
| [platinum_ow_b4_c08](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c08) | front 0 |
| [platinum_ow_b4_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c09) | front 0 |
| [platinum_ow_b4_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c10) | front 0 |
| [platinum_ow_b4_c11](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c11) | front 0 |
| [platinum_ow_b5_c12](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b5_c12) | front 0 |
| [poke_kid_hgss](../../graphics/entrenadores/poke_kid_hgss) | OW 0–8 (sin OW identificado) |
| [poke_kid_platinum](../../graphics/entrenadores/poke_kid_platinum) | OW 0–8 (sin OW identificado) |
| [poke_kid_unused_hgss](../../graphics/entrenadores/poke_kid_unused_hgss) | OW 0–8 (sin OW identificado) |
| [pokefan_f_platinum](../../graphics/entrenadores/pokefan_f_platinum) | OW 0–8 (sin OW identificado) |
| [pokefan_m_hgss](../../graphics/entrenadores/pokefan_m_hgss) | OW 0–8 (sin OW identificado) |
| [pokemon_breeder_f_hgss](../../graphics/entrenadores/pokemon_breeder_f_hgss) | OW 0–8 (sin OW identificado) |
| [pokemon_breeder_f_platinum](../../graphics/entrenadores/pokemon_breeder_f_platinum) | OW 0–8 (sin OW identificado) |
| [pokemon_breeder_m_hgss](../../graphics/entrenadores/pokemon_breeder_m_hgss) | OW 0–8 (sin OW identificado) |
| [pokemon_ranger_f_hgss](../../graphics/entrenadores/pokemon_ranger_f_hgss) | OW 0–8 (sin OW identificado) |
| [pokemon_ranger_f_platinum](../../graphics/entrenadores/pokemon_ranger_f_platinum) | OW 0–8 (sin OW identificado) |
| [pokemon_ranger_m_hgss](../../graphics/entrenadores/pokemon_ranger_m_hgss) | OW 0–8 (sin OW identificado) |
| [pokemon_ranger_m_platinum](../../graphics/entrenadores/pokemon_ranger_m_platinum) | OW 0–8 (sin OW identificado) |
| [policeman_hgss](../../graphics/entrenadores/policeman_hgss) | OW 0–8 (sin OW identificado) |
| [professor_elm_hgss](../../graphics/entrenadores/cajon_de_sastre/professor_elm_hgss) | front 0 |
| [professor_rowan_platinum](../../graphics/entrenadores/cajon_de_sastre/professor_rowan_platinum) | front 0 |
| [proton_hgss](../../graphics/entrenadores/proton_hgss) | OW 0–8 (sin OW identificado) |
| [psychic_f_hgss](../../graphics/entrenadores/psychic_f_hgss) | OW 0–8 (sin OW identificado) |
| [psychic_m_hgss](../../graphics/entrenadores/psychic_m_hgss) | OW 0–8 (sin OW identificado) |
| [rancher_hgss](../../graphics/entrenadores/rancher_hgss) | OW 0–8 (sin OW identificado) |
| [rancher_platinum](../../graphics/entrenadores/rancher_platinum) | OW 0–8 (sin OW identificado) |
| [reporter_hgss](../../graphics/entrenadores/reporter_hgss) | OW 0–8 (sin OW identificado) |
| [rich_boy_hgss](../../graphics/entrenadores/rich_boy_hgss) | OW 0–8 (sin OW identificado) |
| [rich_boy_unused_hgss](../../graphics/entrenadores/rich_boy_unused_hgss) | OW 0–8 (sin OW identificado) |
| [roughneck_hgss](../../graphics/entrenadores/roughneck_hgss) | OW 0–8 (sin OW identificado) |
| [ruin_maniac_hgss](../../graphics/entrenadores/ruin_maniac_hgss) | OW 0–8 (sin OW identificado) |
| [sage_hgss](../../graphics/entrenadores/sage_hgss) | OW 0–8 (sin OW identificado) |
| [sage_korean_hgss](../../graphics/entrenadores/sage_korean_hgss) | OW 0–8 (sin OW identificado) |
| [school_kid_f_hgss](../../graphics/entrenadores/school_kid_f_hgss) | OW 0–8 (sin OW identificado) |
| [school_kid_m_hgss](../../graphics/entrenadores/school_kid_m_hgss) | OW 0–8 (sin OW identificado) |
| [school_kid_m_platinum](../../graphics/entrenadores/school_kid_m_platinum) | OW 0–8 (sin OW identificado) |
| [scientist_johto_hgss](../../graphics/entrenadores/scientist_johto_hgss) | OW 0–8 (sin OW identificado) |
| [silver_unused_hgss](../../graphics/entrenadores/silver_unused_hgss) | OW 0–8 (sin OW identificado) |
| [sis_and_bro_unused_censored_platinum](../../graphics/entrenadores/sis_and_bro_unused_censored_platinum) | OW 0–8 (sin OW identificado) |
| [sis_and_bro_unused_platinum](../../graphics/entrenadores/sis_and_bro_unused_platinum) | OW 0–8 (sin OW identificado) |
| [skier_f_hgss](../../graphics/entrenadores/skier_f_hgss) | OW 0–8 (sin OW identificado) |
| [socialite_hgss](../../graphics/entrenadores/socialite_hgss) | OW 0–8 (sin OW identificado) |
| [steven_hgss](../../graphics/entrenadores/cajon_de_sastre/steven_hgss) | front 0 |
| [super_nerd_hgss](../../graphics/entrenadores/super_nerd_hgss) | OW 0–8 (sin OW identificado) |
| [swimmer_m_censored_hgss](../../graphics/entrenadores/swimmer_m_censored_hgss) | OW 0–8 (sin OW identificado) |
| [swimmer_m_censored_platinum](../../graphics/entrenadores/swimmer_m_censored_platinum) | OW 0–8 (sin OW identificado) |
| [swimmer_m_platinum](../../graphics/entrenadores/swimmer_m_platinum) | OW 0–8 (sin OW identificado) |
| [teacher_hgss](../../graphics/entrenadores/teacher_hgss) | OW 0–8 (sin OW identificado) |
| [thorton_hgss](../../graphics/entrenadores/thorton_hgss) | OW 0–8 (sin OW identificado) |
| [thorton_platinum](../../graphics/entrenadores/thorton_platinum) | OW 0–8 (sin OW identificado) |
| [tuber_f_hgss](../../graphics/entrenadores/tuber_f_hgss) | OW 0–8 (sin OW identificado) |
| [tuber_m_hgss](../../graphics/entrenadores/tuber_m_hgss) | OW 0–8 (sin OW identificado) |
| [veteran_hgss](../../graphics/entrenadores/veteran_hgss) | OW 0–8 (sin OW identificado) |
| [veteran_platinum](../../graphics/entrenadores/veteran_platinum) | OW 0–8 (sin OW identificado) |
| [waiter_hgss](../../graphics/entrenadores/waiter_hgss) | OW 0–8 (sin OW identificado) |
| [waitress_hgss](../../graphics/entrenadores/waitress_hgss) | OW 0–8 (sin OW identificado) |
| [worker_hgss](../../graphics/entrenadores/worker_hgss) | OW 0–8 (sin OW identificado) |
| [young_couple_hgss](../../graphics/entrenadores/young_couple_hgss) | OW 0–8 (sin OW identificado) |
| [young_couple_platinum](../../graphics/entrenadores/young_couple_platinum) | OW 0–8 (sin OW identificado) |

## Catálogo e identificadores

| Carpeta | Front | OW | Conversión OW |
|---|---|---|---|
| [aaron_platinum](../../graphics/entrenadores/aaron_platinum) | TRAINER_PIC_AARON_PLATINUM | OBJ_EVENT_GFX_AARON_PLATINUM | 2101 píxeles |
| [ace_trainer_f_hgss](../../graphics/entrenadores/ace_trainer_f_hgss) | TRAINER_PIC_ACE_TRAINER_F_HGSS | OBJ_EVENT_GFX_ACE_TRAINER_F_HGSS | 2091 píxeles |
| [ace_trainer_f_platinum](../../graphics/entrenadores/ace_trainer_f_platinum) | TRAINER_PIC_ACE_TRAINER_F_PLATINUM | OBJ_EVENT_GFX_ACE_TRAINER_F_PLATINUM | 2249 píxeles |
| [ace_trainer_m_hgss](../../graphics/entrenadores/ace_trainer_m_hgss) | TRAINER_PIC_ACE_TRAINER_M_HGSS | OBJ_EVENT_GFX_ACE_TRAINER_M_HGSS | 2046 píxeles |
| [ace_trainer_m_platinum](../../graphics/entrenadores/ace_trainer_m_platinum) | TRAINER_PIC_ACE_TRAINER_M_PLATINUM | OBJ_EVENT_GFX_ACE_TRAINER_M_PLATINUM | 2163 píxeles |
| [ace_trainer_snow_f_hgss](../../graphics/entrenadores/ace_trainer_snow_f_hgss) | TRAINER_PIC_ACE_TRAINER_SNOW_F_HGSS | Pendiente | 0 píxeles |
| [ace_trainer_snow_f_platinum](../../graphics/entrenadores/ace_trainer_snow_f_platinum) | TRAINER_PIC_ACE_TRAINER_SNOW_F_PLATINUM | OBJ_EVENT_GFX_ACE_TRAINER_SNOW_F_PLATINUM | 1994 píxeles |
| [ace_trainer_snow_m_hgss](../../graphics/entrenadores/ace_trainer_snow_m_hgss) | TRAINER_PIC_ACE_TRAINER_SNOW_M_HGSS | Pendiente | 0 píxeles |
| [ace_trainer_snow_m_platinum](../../graphics/entrenadores/ace_trainer_snow_m_platinum) | TRAINER_PIC_ACE_TRAINER_SNOW_M_PLATINUM | OBJ_EVENT_GFX_ACE_TRAINER_SNOW_M_PLATINUM | 1979 píxeles |
| [archer_hgss](../../graphics/entrenadores/archer_hgss) | TRAINER_PIC_ARCHER_HGSS | OBJ_EVENT_GFX_ARCHER_HGSS | 2069 píxeles |
| [argenta_hgss](../../graphics/entrenadores/argenta_hgss) | TRAINER_PIC_ARGENTA_HGSS | Pendiente | 0 píxeles |
| [argenta_platinum](../../graphics/entrenadores/argenta_platinum) | TRAINER_PIC_ARGENTA_PLATINUM | Pendiente | 0 píxeles |
| [ariana_hgss](../../graphics/entrenadores/ariana_hgss) | TRAINER_PIC_ARIANA_HGSS | OBJ_EVENT_GFX_ARIANA_HGSS | 2488 píxeles |
| [aroma_lady_hgss](../../graphics/entrenadores/aroma_lady_hgss) | TRAINER_PIC_AROMA_LADY_HGSS | Pendiente | 0 píxeles |
| [aroma_lady_platinum](../../graphics/entrenadores/aroma_lady_platinum) | TRAINER_PIC_AROMA_LADY_PLATINUM | Pendiente | 0 píxeles |
| [aroma_lady_unused_hgss](../../graphics/entrenadores/aroma_lady_unused_hgss) | TRAINER_PIC_AROMA_LADY_UNUSED_HGSS | Pendiente | 0 píxeles |
| [artist_hgss](../../graphics/entrenadores/artist_hgss) | TRAINER_PIC_ARTIST_HGSS | Pendiente | 0 píxeles |
| [artist_platinum](../../graphics/entrenadores/artist_platinum) | TRAINER_PIC_ARTIST_PLATINUM | Pendiente | 0 píxeles |
| [barry_47490](../../graphics/entrenadores/barry_47490) | TRAINER_PIC_BARRY_47490 | OBJ_EVENT_GFX_BARRY_47490 | 2313 píxeles |
| [barry_platinum](../../graphics/entrenadores/barry_platinum) | TRAINER_PIC_BARRY_PLATINUM | OBJ_EVENT_GFX_BARRY_PLATINUM | 2298 píxeles |
| [battle_girl_hgss](../../graphics/entrenadores/battle_girl_hgss) | TRAINER_PIC_BATTLE_GIRL_HGSS | Pendiente | 0 píxeles |
| [battle_girl_platinum](../../graphics/entrenadores/battle_girl_platinum) | TRAINER_PIC_BATTLE_GIRL_PLATINUM | OBJ_EVENT_GFX_BATTLE_GIRL_PLATINUM | 2461 píxeles |
| [beauty_hgss](../../graphics/entrenadores/beauty_hgss) | TRAINER_PIC_BEAUTY_HGSS | OBJ_EVENT_GFX_BEAUTY_HGSS | 2299 píxeles |
| [beauty_platinum](../../graphics/entrenadores/beauty_platinum) | TRAINER_PIC_BEAUTY_PLATINUM | OBJ_EVENT_GFX_BEAUTY_PLATINUM | 2364 píxeles |
| [belle_and_pa_platinum](../../graphics/entrenadores/belle_and_pa_platinum) | TRAINER_PIC_BELLE_AND_PA_PLATINUM | Pendiente | 0 píxeles |
| [bertha_platinum](../../graphics/entrenadores/bertha_platinum) | TRAINER_PIC_BERTHA_PLATINUM | OBJ_EVENT_GFX_BERTHA_PLATINUM | 2088 píxeles |
| [biker_hgss](../../graphics/entrenadores/biker_hgss) | TRAINER_PIC_BIKER_HGSS | OBJ_EVENT_GFX_BIKER_HGSS | 2237 píxeles |
| [bird_keeper_hgss](../../graphics/entrenadores/bird_keeper_hgss) | TRAINER_PIC_BIRD_KEEPER_HGSS | Pendiente | 0 píxeles |
| [bird_keeper_johto_hgss](../../graphics/entrenadores/bird_keeper_johto_hgss) | TRAINER_PIC_BIRD_KEEPER_JOHTO_HGSS | Pendiente | 0 píxeles |
| [bird_keeper_platinum](../../graphics/entrenadores/bird_keeper_platinum) | TRAINER_PIC_BIRD_KEEPER_PLATINUM | Pendiente | 0 píxeles |
| [black_belt_hgss](../../graphics/entrenadores/black_belt_hgss) | TRAINER_PIC_BLACK_BELT_HGSS | OBJ_EVENT_GFX_BLACK_BELT_HGSS | 2107 píxeles |
| [black_belt_platinum](../../graphics/entrenadores/black_belt_platinum) | TRAINER_PIC_BLACK_BELT_PLATINUM | OBJ_EVENT_GFX_BLACK_BELT_PLATINUM | 1957 píxeles |
| [blaine_hgss](../../graphics/entrenadores/blaine_hgss) | TRAINER_PIC_BLAINE_HGSS | OBJ_EVENT_GFX_BLAINE_HGSS | 1723 píxeles |
| [blue_hgss](../../graphics/entrenadores/blue_hgss) | TRAINER_PIC_BLUE_HGSS | OBJ_EVENT_GFX_BLUE_HGSS | 2430 píxeles |
| [boarder_hgss](../../graphics/entrenadores/boarder_hgss) | TRAINER_PIC_BOARDER_HGSS | Pendiente | 0 píxeles |
| [brock_hgss](../../graphics/entrenadores/brock_hgss) | TRAINER_PIC_BROCK_HGSS | OBJ_EVENT_GFX_BROCK_HGSS | 2265 píxeles |
| [bruno_hgss](../../graphics/entrenadores/bruno_hgss) | TRAINER_PIC_BRUNO_HGSS | OBJ_EVENT_GFX_BRUNO_HGSS | 2323 píxeles |
| [buck_platinum](../../graphics/entrenadores/buck_platinum) | TRAINER_PIC_BUCK_PLATINUM | OBJ_EVENT_GFX_BUCK_PLATINUM | 2047 píxeles |
| [bug_catcher_hgss](../../graphics/entrenadores/bug_catcher_hgss) | TRAINER_PIC_BUG_CATCHER_HGSS | OBJ_EVENT_GFX_BUG_CATCHER_HGSS | 2402 píxeles |
| [bug_catcher_platinum](../../graphics/entrenadores/bug_catcher_platinum) | TRAINER_PIC_BUG_CATCHER_PLATINUM | Pendiente | 0 píxeles |
| [bugsy_hgss](../../graphics/entrenadores/bugsy_hgss) | TRAINER_PIC_BUGSY_HGSS | OBJ_EVENT_GFX_BUGSY_HGSS | 2113 píxeles |
| [burglar_hgss](../../graphics/entrenadores/burglar_hgss) | TRAINER_PIC_BURGLAR_HGSS | Pendiente | 0 píxeles |
| [byron_platinum](../../graphics/entrenadores/byron_platinum) | TRAINER_PIC_BYRON_PLATINUM | OBJ_EVENT_GFX_BYRON_PLATINUM | 2717 píxeles |
| [caitlin_hgss](../../graphics/entrenadores/caitlin_hgss) | TRAINER_PIC_CAITLIN_HGSS | Pendiente | 0 píxeles |
| [caitlin_platinum](../../graphics/entrenadores/caitlin_platinum) | TRAINER_PIC_CAITLIN_PLATINUM | Pendiente | 0 píxeles |
| [cameraman_hgss](../../graphics/entrenadores/cameraman_hgss) | TRAINER_PIC_CAMERAMAN_HGSS | Pendiente | 0 píxeles |
| [cameraman_platinum](../../graphics/entrenadores/cameraman_platinum) | TRAINER_PIC_CAMERAMAN_PLATINUM | OBJ_EVENT_GFX_CAMERAMAN_PLATINUM | 2192 píxeles |
| [camper_hgss](../../graphics/entrenadores/camper_hgss) | TRAINER_PIC_CAMPER_HGSS | Pendiente | 0 píxeles |
| [camper_platinum](../../graphics/entrenadores/camper_platinum) | TRAINER_PIC_CAMPER_PLATINUM | OBJ_EVENT_GFX_CAMPER_PLATINUM | 2189 píxeles |
| [camper_unused_hgss](../../graphics/entrenadores/camper_unused_hgss) | TRAINER_PIC_CAMPER_UNUSED_HGSS | Pendiente | 0 píxeles |
| [candice_platinum](../../graphics/entrenadores/candice_platinum) | TRAINER_PIC_CANDICE_PLATINUM | OBJ_EVENT_GFX_CANDICE_PLATINUM | 2115 píxeles |
| [cheryl_platinum](../../graphics/entrenadores/cheryl_platinum) | TRAINER_PIC_CHERYL_PLATINUM | OBJ_EVENT_GFX_CHERYL_PLATINUM | 2103 píxeles |
| [chuck_hgss](../../graphics/entrenadores/chuck_hgss) | TRAINER_PIC_CHUCK_HGSS | OBJ_EVENT_GFX_CHUCK_HGSS | 1994 píxeles |
| [clair_hgss](../../graphics/entrenadores/clair_hgss) | TRAINER_PIC_CLAIR_HGSS | OBJ_EVENT_GFX_CLAIR_HGSS | 2603 píxeles |
| [clown_hgss](../../graphics/entrenadores/clown_hgss) | TRAINER_PIC_CLOWN_HGSS | Pendiente | 0 píxeles |
| [clown_platinum](../../graphics/entrenadores/clown_platinum) | TRAINER_PIC_CLOWN_PLATINUM | OBJ_EVENT_GFX_CLOWN_PLATINUM | 2469 píxeles |
| [collector_hgss](../../graphics/entrenadores/collector_hgss) | TRAINER_PIC_COLLECTOR_HGSS | Pendiente | 0 píxeles |
| [collector_platinum](../../graphics/entrenadores/collector_platinum) | TRAINER_PIC_COLLECTOR_PLATINUM | Pendiente | 0 píxeles |
| [cowgirl_hgss](../../graphics/entrenadores/cowgirl_hgss) | TRAINER_PIC_COWGIRL_HGSS | Pendiente | 0 píxeles |
| [cowgirl_platinum](../../graphics/entrenadores/cowgirl_platinum) | TRAINER_PIC_COWGIRL_PLATINUM | OBJ_EVENT_GFX_COWGIRL_PLATINUM | 2658 píxeles |
| [crasher_wake_platinum](../../graphics/entrenadores/crasher_wake_platinum) | TRAINER_PIC_CRASHER_WAKE_PLATINUM | OBJ_EVENT_GFX_CRASHER_WAKE_PLATINUM | 2054 píxeles |
| [cycler_f_hgss](../../graphics/entrenadores/cycler_f_hgss) | TRAINER_PIC_CYCLER_F_HGSS | Pendiente | 0 píxeles |
| [cycler_f_platinum](../../graphics/entrenadores/cycler_f_platinum) | TRAINER_PIC_CYCLER_F_PLATINUM | OBJ_EVENT_GFX_CYCLER_F_PLATINUM | 2106 píxeles |
| [cycler_m_hgss](../../graphics/entrenadores/cycler_m_hgss) | TRAINER_PIC_CYCLER_M_HGSS | Pendiente | 0 píxeles |
| [cycler_m_platinum](../../graphics/entrenadores/cycler_m_platinum) | TRAINER_PIC_CYCLER_M_PLATINUM | OBJ_EVENT_GFX_CYCLER_M_PLATINUM | 1930 píxeles |
| [cynthia_platinum](../../graphics/entrenadores/cynthia_platinum) | TRAINER_PIC_CYNTHIA_PLATINUM | OBJ_EVENT_GFX_CYNTHIA_PLATINUM | 1930 píxeles |
| [cyrus_platinum](../../graphics/entrenadores/cyrus_platinum) | TRAINER_PIC_CYRUS_PLATINUM | OBJ_EVENT_GFX_CYRUS_PLATINUM | 2245 píxeles |
| [dahlia_hgss](../../graphics/entrenadores/dahlia_hgss) | TRAINER_PIC_DAHLIA_HGSS | Pendiente | 0 píxeles |
| [dahlia_platinum](../../graphics/entrenadores/dahlia_platinum) | TRAINER_PIC_DAHLIA_PLATINUM | Pendiente | 0 píxeles |
| [darach_hgss](../../graphics/entrenadores/darach_hgss) | TRAINER_PIC_DARACH_HGSS | Pendiente | 0 píxeles |
| [darach_platinum](../../graphics/entrenadores/darach_platinum) | TRAINER_PIC_DARACH_PLATINUM | Pendiente | 0 píxeles |
| [dawn_dp_hgss](../../graphics/entrenadores/dawn_dp_hgss) | TRAINER_PIC_DAWN_DP_HGSS | Pendiente | 0 píxeles |
| [dawn_dp_platinum](../../graphics/entrenadores/dawn_dp_platinum) | TRAINER_PIC_DAWN_DP_PLATINUM | Pendiente | 0 píxeles |
| [dawn_dp_unused_hgss](../../graphics/entrenadores/dawn_dp_unused_hgss) | TRAINER_PIC_DAWN_DP_UNUSED_HGSS | Pendiente | 0 píxeles |
| [dawn_dp_unused_platinum](../../graphics/entrenadores/dawn_dp_unused_platinum) | TRAINER_PIC_DAWN_DP_UNUSED_PLATINUM | Pendiente | 0 píxeles |
| [dawn_platinum](../../graphics/entrenadores/dawn_platinum) | TRAINER_PIC_DAWN_PLATINUM | Pendiente | 0 píxeles |
| [dawn_platinum_hgss](../../graphics/entrenadores/dawn_platinum_hgss) | TRAINER_PIC_DAWN_PLATINUM_HGSS | Pendiente | 0 píxeles |
| [double_team_hgss](../../graphics/entrenadores/double_team_hgss) | TRAINER_PIC_DOUBLE_TEAM_HGSS | Pendiente | 0 píxeles |
| [double_team_platinum](../../graphics/entrenadores/double_team_platinum) | TRAINER_PIC_DOUBLE_TEAM_PLATINUM | Pendiente | 0 píxeles |
| [dragon_tamer_hgss](../../graphics/entrenadores/dragon_tamer_hgss) | TRAINER_PIC_DRAGON_TAMER_HGSS | Pendiente | 0 píxeles |
| [dragon_tamer_platinum](../../graphics/entrenadores/dragon_tamer_platinum) | TRAINER_PIC_DRAGON_TAMER_PLATINUM | Pendiente | 0 píxeles |
| [elder_hgss](../../graphics/entrenadores/elder_hgss) | TRAINER_PIC_ELDER_HGSS | Pendiente | 0 píxeles |
| [erika_hgss](../../graphics/entrenadores/erika_hgss) | TRAINER_PIC_ERIKA_HGSS | OBJ_EVENT_GFX_ERIKA_HGSS | 2042 píxeles |
| [ethan_hgss](../../graphics/entrenadores/ethan_hgss) | TRAINER_PIC_ETHAN_HGSS | Pendiente | 0 píxeles |
| [eusine_hgss](../../graphics/entrenadores/eusine_hgss) | TRAINER_PIC_EUSINE_HGSS | Pendiente | 0 píxeles |
| [falkner_hgss](../../graphics/entrenadores/falkner_hgss) | TRAINER_PIC_FALKNER_HGSS | OBJ_EVENT_GFX_FALKNER_HGSS | 1684 píxeles |
| [fantina_platinum](../../graphics/entrenadores/fantina_platinum) | TRAINER_PIC_FANTINA_PLATINUM | OBJ_EVENT_GFX_FANTINA_PLATINUM | 2761 píxeles |
| [firebreather_hgss](../../graphics/entrenadores/firebreather_hgss) | TRAINER_PIC_FIREBREATHER_HGSS | Pendiente | 0 píxeles |
| [fisher_hgss](../../graphics/entrenadores/fisher_hgss) | TRAINER_PIC_FISHER_HGSS | Pendiente | 0 píxeles |
| [fisher_platinum](../../graphics/entrenadores/fisher_platinum) | TRAINER_PIC_FISHER_PLATINUM | OBJ_EVENT_GFX_FISHER_PLATINUM | 1896 píxeles |
| [flint_platinum](../../graphics/entrenadores/flint_platinum) | TRAINER_PIC_FLINT_PLATINUM | OBJ_EVENT_GFX_FLINT_PLATINUM | 2232 píxeles |
| [galactic_grunt_f_platinum](../../graphics/entrenadores/galactic_grunt_f_platinum) | TRAINER_PIC_GALACTIC_GRUNT_F_PLATINUM | OBJ_EVENT_GFX_GALACTIC_GRUNT_F_PLATINUM | 770 píxeles |
| [galactic_grunt_m_platinum](../../graphics/entrenadores/galactic_grunt_m_platinum) | TRAINER_PIC_GALACTIC_GRUNT_M_PLATINUM | OBJ_EVENT_GFX_GALACTIC_GRUNT_M_PLATINUM | 799 píxeles |
| [gardenia_platinum](../../graphics/entrenadores/gardenia_platinum) | TRAINER_PIC_GARDENIA_PLATINUM | OBJ_EVENT_GFX_GARDENIA_PLATINUM | 2211 píxeles |
| [gentleman_hgss](../../graphics/entrenadores/gentleman_hgss) | TRAINER_PIC_GENTLEMAN_HGSS | OBJ_EVENT_GFX_GENTLEMAN_HGSS | 2097 píxeles |
| [gentleman_platinum](../../graphics/entrenadores/gentleman_platinum) | TRAINER_PIC_GENTLEMAN_PLATINUM | OBJ_EVENT_GFX_GENTLEMAN_PLATINUM | 1872 píxeles |
| [giovanni_hgss](../../graphics/entrenadores/giovanni_hgss) | TRAINER_PIC_GIOVANNI_HGSS | OBJ_EVENT_GFX_GIOVANNI_HGSS | 2297 píxeles |
| [guitarist_hgss](../../graphics/entrenadores/guitarist_hgss) | TRAINER_PIC_GUITARIST_HGSS | Pendiente | 0 píxeles |
| [guitarist_platinum](../../graphics/entrenadores/guitarist_platinum) | TRAINER_PIC_GUITARIST_PLATINUM | Pendiente | 0 píxeles |
| [hgss_ow_r01_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c04) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R01_C04 | 0 píxeles |
| [hgss_ow_r01_c05](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c05) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R01_C05 | 0 píxeles |
| [hgss_ow_r01_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c06) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R01_C06 | 0 píxeles |
| [hgss_ow_r01_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r01_c10) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R01_C10 | 0 píxeles |
| [hgss_ow_r02_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c02) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C02 | 0 píxeles |
| [hgss_ow_r02_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c03) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C03 | 0 píxeles |
| [hgss_ow_r02_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c04) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C04 | 0 píxeles |
| [hgss_ow_r02_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c06) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C06 | 0 píxeles |
| [hgss_ow_r02_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c09) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C09 | 0 píxeles |
| [hgss_ow_r02_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r02_c10) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R02_C10 | 0 píxeles |
| [hgss_ow_r03_c01](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c01) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R03_C01 | 0 píxeles |
| [hgss_ow_r03_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c02) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R03_C02 | 0 píxeles |
| [hgss_ow_r03_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r03_c04) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R03_C04 | 0 píxeles |
| [hgss_ow_r05_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r05_c02) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R05_C02 | 0 píxeles |
| [hgss_ow_r06_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c03) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R06_C03 | 0 píxeles |
| [hgss_ow_r06_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r06_c08) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R06_C08 | 0 píxeles |
| [hgss_ow_r07_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c02) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C02 | 0 píxeles |
| [hgss_ow_r07_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c06) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C06 | 0 píxeles |
| [hgss_ow_r07_c07](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c07) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C07 | 0 píxeles |
| [hgss_ow_r07_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c08) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C08 | 0 píxeles |
| [hgss_ow_r07_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c09) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C09 | 0 píxeles |
| [hgss_ow_r07_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r07_c10) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R07_C10 | 0 píxeles |
| [hgss_ow_r08_c01](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c01) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C01 | 0 píxeles |
| [hgss_ow_r08_c02](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c02) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C02 | 0 píxeles |
| [hgss_ow_r08_c03](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c03) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C03 | 0 píxeles |
| [hgss_ow_r08_c04](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c04) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C04 | 0 píxeles |
| [hgss_ow_r08_c05](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c05) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C05 | 0 píxeles |
| [hgss_ow_r08_c06](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c06) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C06 | 0 píxeles |
| [hgss_ow_r08_c07](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c07) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C07 | 0 píxeles |
| [hgss_ow_r08_c08](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c08) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C08 | 0 píxeles |
| [hgss_ow_r08_c09](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c09) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C09 | 0 píxeles |
| [hgss_ow_r08_c10](../../graphics/entrenadores/cajon_de_sastre/hgss_ow_r08_c10) | Pendiente | OBJ_EVENT_GFX_HGSS_OW_R08_C10 | 0 píxeles |
| [hiker_hgss](../../graphics/entrenadores/hiker_hgss) | TRAINER_PIC_HIKER_HGSS | Pendiente | 0 píxeles |
| [hiker_platinum](../../graphics/entrenadores/hiker_platinum) | TRAINER_PIC_HIKER_PLATINUM | OBJ_EVENT_GFX_HIKER_PLATINUM | 2610 píxeles |
| [idol_hgss](../../graphics/entrenadores/idol_hgss) | TRAINER_PIC_IDOL_HGSS | Pendiente | 0 píxeles |
| [idol_platinum](../../graphics/entrenadores/idol_platinum) | TRAINER_PIC_IDOL_PLATINUM | OBJ_EVENT_GFX_IDOL_PLATINUM | 2041 píxeles |
| [interviewers_platinum](../../graphics/entrenadores/interviewers_platinum) | TRAINER_PIC_INTERVIEWERS_PLATINUM | Pendiente | 0 píxeles |
| [janine_hgss](../../graphics/entrenadores/janine_hgss) | TRAINER_PIC_JANINE_HGSS | OBJ_EVENT_GFX_JANINE_HGSS | 2308 píxeles |
| [jasmine_hgss](../../graphics/entrenadores/jasmine_hgss) | TRAINER_PIC_JASMINE_HGSS | OBJ_EVENT_GFX_JASMINE_HGSS | 1999 píxeles |
| [jogger_hgss](../../graphics/entrenadores/jogger_hgss) | TRAINER_PIC_JOGGER_HGSS | Pendiente | 0 píxeles |
| [jogger_platinum](../../graphics/entrenadores/jogger_platinum) | TRAINER_PIC_JOGGER_PLATINUM | OBJ_EVENT_GFX_JOGGER_PLATINUM | 1738 píxeles |
| [juggler_hgss](../../graphics/entrenadores/juggler_hgss) | TRAINER_PIC_JUGGLER_HGSS | OBJ_EVENT_GFX_JUGGLER_HGSS | 2535 píxeles |
| [jupiter_platinum](../../graphics/entrenadores/jupiter_platinum) | TRAINER_PIC_JUPITER_PLATINUM | OBJ_EVENT_GFX_JUPITER_PLATINUM | 1265 píxeles |
| [karen_hgss](../../graphics/entrenadores/karen_hgss) | TRAINER_PIC_KAREN_HGSS | OBJ_EVENT_GFX_KAREN_HGSS | 2318 píxeles |
| [kimono_girl_hgss](../../graphics/entrenadores/kimono_girl_hgss) | TRAINER_PIC_KIMONO_GIRL_HGSS | OBJ_EVENT_GFX_KIMONO_GIRL_HGSS | 3836 píxeles |
| [koga_hgss](../../graphics/entrenadores/koga_hgss) | TRAINER_PIC_KOGA_HGSS | OBJ_EVENT_GFX_KOGA_HGSS | 2159 píxeles |
| [lady_hgss](../../graphics/entrenadores/lady_hgss) | TRAINER_PIC_LADY_HGSS | Pendiente | 0 píxeles |
| [lady_platinum](../../graphics/entrenadores/lady_platinum) | TRAINER_PIC_LADY_PLATINUM | Pendiente | 0 píxeles |
| [lance_hgss](../../graphics/entrenadores/lance_hgss) | TRAINER_PIC_LANCE_HGSS | OBJ_EVENT_GFX_LANCE_HGSS | 2867 píxeles |
| [lass_hgss](../../graphics/entrenadores/lass_hgss) | TRAINER_PIC_LASS_HGSS | OBJ_EVENT_GFX_LASS_HGSS | 2726 píxeles |
| [lass_platinum](../../graphics/entrenadores/lass_platinum) | TRAINER_PIC_LASS_PLATINUM | Pendiente | 0 píxeles |
| [looker_platinum](../../graphics/entrenadores/cajon_de_sastre/looker_platinum) | Pendiente | OBJ_EVENT_GFX_LOOKER_PLATINUM | 0 píxeles |
| [lt_surge_hgss](../../graphics/entrenadores/lt_surge_hgss) | TRAINER_PIC_LT_SURGE_HGSS | OBJ_EVENT_GFX_LT_SURGE_HGSS | 2254 píxeles |
| [lucas_dp_hgss](../../graphics/entrenadores/lucas_dp_hgss) | TRAINER_PIC_LUCAS_DP_HGSS | Pendiente | 0 píxeles |
| [lucas_dp_platinum](../../graphics/entrenadores/lucas_dp_platinum) | TRAINER_PIC_LUCAS_DP_PLATINUM | Pendiente | 0 píxeles |
| [lucas_dp_unused_hgss](../../graphics/entrenadores/lucas_dp_unused_hgss) | TRAINER_PIC_LUCAS_DP_UNUSED_HGSS | Pendiente | 0 píxeles |
| [lucas_dp_unused_platinum](../../graphics/entrenadores/lucas_dp_unused_platinum) | TRAINER_PIC_LUCAS_DP_UNUSED_PLATINUM | Pendiente | 0 píxeles |
| [lucas_platinum](../../graphics/entrenadores/lucas_platinum) | TRAINER_PIC_LUCAS_PLATINUM | Pendiente | 0 píxeles |
| [lucas_platinum_hgss](../../graphics/entrenadores/lucas_platinum_hgss) | TRAINER_PIC_LUCAS_PLATINUM_HGSS | Pendiente | 0 píxeles |
| [lucian_platinum](../../graphics/entrenadores/lucian_platinum) | TRAINER_PIC_LUCIAN_PLATINUM | OBJ_EVENT_GFX_LUCIAN_PLATINUM | 2044 píxeles |
| [lyra_hgss](../../graphics/entrenadores/lyra_hgss) | TRAINER_PIC_LYRA_HGSS | Pendiente | 0 píxeles |
| [maid_platinum](../../graphics/entrenadores/maid_platinum) | TRAINER_PIC_MAID_PLATINUM | OBJ_EVENT_GFX_MAID_PLATINUM | 2449 píxeles |
| [marley_platinum](../../graphics/entrenadores/marley_platinum) | TRAINER_PIC_MARLEY_PLATINUM | OBJ_EVENT_GFX_MARLEY_PLATINUM | 1925 píxeles |
| [mars_platinum](../../graphics/entrenadores/mars_platinum) | TRAINER_PIC_MARS_PLATINUM | OBJ_EVENT_GFX_MARS_PLATINUM | 1111 píxeles |
| [maylene_platinum](../../graphics/entrenadores/maylene_platinum) | TRAINER_PIC_MAYLENE_PLATINUM | OBJ_EVENT_GFX_MAYLENE_PLATINUM | 2138 píxeles |
| [medium_hgss](../../graphics/entrenadores/medium_hgss) | TRAINER_PIC_MEDIUM_HGSS | Pendiente | 0 píxeles |
| [mira_platinum](../../graphics/entrenadores/mira_platinum) | TRAINER_PIC_MIRA_PLATINUM | OBJ_EVENT_GFX_MIRA_PLATINUM | 1879 píxeles |
| [misty_hgss](../../graphics/entrenadores/misty_hgss) | TRAINER_PIC_MISTY_HGSS | OBJ_EVENT_GFX_MISTY_HGSS | 2566 píxeles |
| [morty_hgss](../../graphics/entrenadores/morty_hgss) | TRAINER_PIC_MORTY_HGSS | OBJ_EVENT_GFX_MORTY_HGSS | 2031 píxeles |
| [ninja_boy_hgss](../../graphics/entrenadores/ninja_boy_hgss) | TRAINER_PIC_NINJA_BOY_HGSS | Pendiente | 0 píxeles |
| [ninja_boy_platinum](../../graphics/entrenadores/ninja_boy_platinum) | TRAINER_PIC_NINJA_BOY_PLATINUM | Pendiente | 0 píxeles |
| [palmer_hgss](../../graphics/entrenadores/palmer_hgss) | TRAINER_PIC_PALMER_HGSS | Pendiente | 0 píxeles |
| [palmer_platinum](../../graphics/entrenadores/palmer_platinum) | TRAINER_PIC_PALMER_PLATINUM | OBJ_EVENT_GFX_PALMER_PLATINUM | 2300 píxeles |
| [parasol_lady_hgss](../../graphics/entrenadores/parasol_lady_hgss) | TRAINER_PIC_PARASOL_LADY_HGSS | Pendiente | 0 píxeles |
| [parasol_lady_platinum](../../graphics/entrenadores/parasol_lady_platinum) | TRAINER_PIC_PARASOL_LADY_PLATINUM | Pendiente | 0 píxeles |
| [petrel_hgss](../../graphics/entrenadores/petrel_hgss) | TRAINER_PIC_PETREL_HGSS | Pendiente | 0 píxeles |
| [pi_hgss](../../graphics/entrenadores/pi_hgss) | TRAINER_PIC_PI_HGSS | Pendiente | 0 píxeles |
| [pi_platinum](../../graphics/entrenadores/pi_platinum) | TRAINER_PIC_PI_PLATINUM | Pendiente | 0 píxeles |
| [picnicker_hgss](../../graphics/entrenadores/picnicker_hgss) | TRAINER_PIC_PICNICKER_HGSS | Pendiente | 0 píxeles |
| [picnicker_platinum](../../graphics/entrenadores/picnicker_platinum) | TRAINER_PIC_PICNICKER_PLATINUM | OBJ_EVENT_GFX_PICNICKER_PLATINUM | 2378 píxeles |
| [picnicker_unused_hgss](../../graphics/entrenadores/picnicker_unused_hgss) | TRAINER_PIC_PICNICKER_UNUSED_HGSS | Pendiente | 0 píxeles |
| [platinum_ow_b0_c01](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c01) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B0_C01 | 0 píxeles |
| [platinum_ow_b0_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c04) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B0_C04 | 0 píxeles |
| [platinum_ow_b0_c08](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c08) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B0_C08 | 0 píxeles |
| [platinum_ow_b0_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b0_c09) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B0_C09 | 0 píxeles |
| [platinum_ow_b1_c05](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c05) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B1_C05 | 0 píxeles |
| [platinum_ow_b1_c06](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c06) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B1_C06 | 0 píxeles |
| [platinum_ow_b1_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c09) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B1_C09 | 0 píxeles |
| [platinum_ow_b1_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c10) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B1_C10 | 0 píxeles |
| [platinum_ow_b1_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b1_c16) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B1_C16 | 0 píxeles |
| [platinum_ow_b2_c02](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c02) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C02 | 0 píxeles |
| [platinum_ow_b2_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c03) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C03 | 0 píxeles |
| [platinum_ow_b2_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c04) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C04 | 0 píxeles |
| [platinum_ow_b2_c07](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c07) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C07 | 0 píxeles |
| [platinum_ow_b2_c14](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c14) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C14 | 0 píxeles |
| [platinum_ow_b2_c15](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c15) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C15 | 0 píxeles |
| [platinum_ow_b2_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b2_c16) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B2_C16 | 0 píxeles |
| [platinum_ow_b3_c02](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c02) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C02 | 0 píxeles |
| [platinum_ow_b3_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c03) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C03 | 0 píxeles |
| [platinum_ow_b3_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c04) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C04 | 0 píxeles |
| [platinum_ow_b3_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c09) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C09 | 0 píxeles |
| [platinum_ow_b3_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c10) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C10 | 0 píxeles |
| [platinum_ow_b3_c11](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c11) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C11 | 0 píxeles |
| [platinum_ow_b3_c12](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c12) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C12 | 0 píxeles |
| [platinum_ow_b3_c13](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c13) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C13 | 0 píxeles |
| [platinum_ow_b3_c14](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c14) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C14 | 0 píxeles |
| [platinum_ow_b3_c15](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c15) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C15 | 0 píxeles |
| [platinum_ow_b3_c16](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b3_c16) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B3_C16 | 0 píxeles |
| [platinum_ow_b4_c00](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c00) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C00 | 0 píxeles |
| [platinum_ow_b4_c03](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c03) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C03 | 0 píxeles |
| [platinum_ow_b4_c04](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c04) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C04 | 0 píxeles |
| [platinum_ow_b4_c05](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c05) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C05 | 0 píxeles |
| [platinum_ow_b4_c06](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c06) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C06 | 0 píxeles |
| [platinum_ow_b4_c07](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c07) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C07 | 0 píxeles |
| [platinum_ow_b4_c08](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c08) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C08 | 0 píxeles |
| [platinum_ow_b4_c09](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c09) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C09 | 0 píxeles |
| [platinum_ow_b4_c10](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c10) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C10 | 0 píxeles |
| [platinum_ow_b4_c11](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b4_c11) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B4_C11 | 0 píxeles |
| [platinum_ow_b5_c12](../../graphics/entrenadores/cajon_de_sastre/platinum_ow_b5_c12) | Pendiente | OBJ_EVENT_GFX_PLATINUM_OW_B5_C12 | 0 píxeles |
| [poke_kid_hgss](../../graphics/entrenadores/poke_kid_hgss) | TRAINER_PIC_POKE_KID_HGSS | Pendiente | 0 píxeles |
| [poke_kid_platinum](../../graphics/entrenadores/poke_kid_platinum) | TRAINER_PIC_POKE_KID_PLATINUM | Pendiente | 0 píxeles |
| [poke_kid_unused_hgss](../../graphics/entrenadores/poke_kid_unused_hgss) | TRAINER_PIC_POKE_KID_UNUSED_HGSS | Pendiente | 0 píxeles |
| [poke_maniac_hgss](../../graphics/entrenadores/poke_maniac_hgss) | TRAINER_PIC_POKE_MANIAC_HGSS | OBJ_EVENT_GFX_POKE_MANIAC_HGSS | 2434 píxeles |
| [pokefan_f_hgss](../../graphics/entrenadores/pokefan_f_hgss) | TRAINER_PIC_POKEFAN_F_HGSS | OBJ_EVENT_GFX_POKEFAN_F_HGSS | 2244 píxeles |
| [pokefan_f_platinum](../../graphics/entrenadores/pokefan_f_platinum) | TRAINER_PIC_POKEFAN_F_PLATINUM | Pendiente | 0 píxeles |
| [pokefan_m_hgss](../../graphics/entrenadores/pokefan_m_hgss) | TRAINER_PIC_POKEFAN_M_HGSS | Pendiente | 0 píxeles |
| [pokefan_m_platinum](../../graphics/entrenadores/pokefan_m_platinum) | TRAINER_PIC_POKEFAN_M_PLATINUM | OBJ_EVENT_GFX_POKEFAN_M_PLATINUM | 2208 píxeles |
| [pokemon_breeder_f_hgss](../../graphics/entrenadores/pokemon_breeder_f_hgss) | TRAINER_PIC_POKEMON_BREEDER_F_HGSS | Pendiente | 0 píxeles |
| [pokemon_breeder_f_platinum](../../graphics/entrenadores/pokemon_breeder_f_platinum) | TRAINER_PIC_POKEMON_BREEDER_F_PLATINUM | Pendiente | 0 píxeles |
| [pokemon_breeder_m_hgss](../../graphics/entrenadores/pokemon_breeder_m_hgss) | TRAINER_PIC_POKEMON_BREEDER_M_HGSS | Pendiente | 0 píxeles |
| [pokemon_breeder_m_platinum](../../graphics/entrenadores/pokemon_breeder_m_platinum) | TRAINER_PIC_POKEMON_BREEDER_M_PLATINUM | OBJ_EVENT_GFX_POKEMON_BREEDER_M_PLATINUM | 2134 píxeles |
| [pokemon_ranger_f_hgss](../../graphics/entrenadores/pokemon_ranger_f_hgss) | TRAINER_PIC_POKEMON_RANGER_F_HGSS | Pendiente | 0 píxeles |
| [pokemon_ranger_f_platinum](../../graphics/entrenadores/pokemon_ranger_f_platinum) | TRAINER_PIC_POKEMON_RANGER_F_PLATINUM | Pendiente | 0 píxeles |
| [pokemon_ranger_m_hgss](../../graphics/entrenadores/pokemon_ranger_m_hgss) | TRAINER_PIC_POKEMON_RANGER_M_HGSS | Pendiente | 0 píxeles |
| [pokemon_ranger_m_platinum](../../graphics/entrenadores/pokemon_ranger_m_platinum) | TRAINER_PIC_POKEMON_RANGER_M_PLATINUM | Pendiente | 0 píxeles |
| [policeman_hgss](../../graphics/entrenadores/policeman_hgss) | TRAINER_PIC_POLICEMAN_HGSS | Pendiente | 0 píxeles |
| [policeman_platinum](../../graphics/entrenadores/policeman_platinum) | TRAINER_PIC_POLICEMAN_PLATINUM | OBJ_EVENT_GFX_POLICEMAN_PLATINUM | 1935 píxeles |
| [professor_elm_hgss](../../graphics/entrenadores/cajon_de_sastre/professor_elm_hgss) | Pendiente | OBJ_EVENT_GFX_PROFESSOR_ELM_HGSS | 0 píxeles |
| [professor_rowan_platinum](../../graphics/entrenadores/cajon_de_sastre/professor_rowan_platinum) | Pendiente | OBJ_EVENT_GFX_PROFESSOR_ROWAN_PLATINUM | 0 píxeles |
| [proton_hgss](../../graphics/entrenadores/proton_hgss) | TRAINER_PIC_PROTON_HGSS | Pendiente | 0 píxeles |
| [pryce_hgss](../../graphics/entrenadores/pryce_hgss) | TRAINER_PIC_PRYCE_HGSS | OBJ_EVENT_GFX_PRYCE_HGSS | 2910 píxeles |
| [psychic_f_hgss](../../graphics/entrenadores/psychic_f_hgss) | TRAINER_PIC_PSYCHIC_F_HGSS | Pendiente | 0 píxeles |
| [psychic_f_platinum](../../graphics/entrenadores/psychic_f_platinum) | TRAINER_PIC_PSYCHIC_F_PLATINUM | OBJ_EVENT_GFX_PSYCHIC_F_PLATINUM | 2234 píxeles |
| [psychic_m_hgss](../../graphics/entrenadores/psychic_m_hgss) | TRAINER_PIC_PSYCHIC_M_HGSS | Pendiente | 0 píxeles |
| [psychic_m_platinum](../../graphics/entrenadores/psychic_m_platinum) | TRAINER_PIC_PSYCHIC_M_PLATINUM | OBJ_EVENT_GFX_PSYCHIC_M_PLATINUM | 2318 píxeles |
| [rancher_hgss](../../graphics/entrenadores/rancher_hgss) | TRAINER_PIC_RANCHER_HGSS | Pendiente | 0 píxeles |
| [rancher_platinum](../../graphics/entrenadores/rancher_platinum) | TRAINER_PIC_RANCHER_PLATINUM | Pendiente | 0 píxeles |
| [red_hgss](../../graphics/entrenadores/red_hgss) | TRAINER_PIC_RED_HGSS | OBJ_EVENT_GFX_RED_HGSS | 1808 píxeles |
| [reporter_hgss](../../graphics/entrenadores/reporter_hgss) | TRAINER_PIC_REPORTER_HGSS | Pendiente | 0 píxeles |
| [reporter_platinum](../../graphics/entrenadores/reporter_platinum) | TRAINER_PIC_REPORTER_PLATINUM | OBJ_EVENT_GFX_REPORTER_PLATINUM | 2176 píxeles |
| [rich_boy_hgss](../../graphics/entrenadores/rich_boy_hgss) | TRAINER_PIC_RICH_BOY_HGSS | Pendiente | 0 píxeles |
| [rich_boy_platinum](../../graphics/entrenadores/rich_boy_platinum) | TRAINER_PIC_RICH_BOY_PLATINUM | OBJ_EVENT_GFX_RICH_BOY_PLATINUM | 1377 píxeles |
| [rich_boy_unused_hgss](../../graphics/entrenadores/rich_boy_unused_hgss) | TRAINER_PIC_RICH_BOY_UNUSED_HGSS | Pendiente | 0 píxeles |
| [riley_platinum](../../graphics/entrenadores/riley_platinum) | TRAINER_PIC_RILEY_PLATINUM | OBJ_EVENT_GFX_RILEY_PLATINUM | 2203 píxeles |
| [roark_platinum](../../graphics/entrenadores/roark_platinum) | TRAINER_PIC_ROARK_PLATINUM | OBJ_EVENT_GFX_ROARK_PLATINUM | 2140 píxeles |
| [rocket_grunt_f_hgss](../../graphics/entrenadores/rocket_grunt_f_hgss) | TRAINER_PIC_ROCKET_GRUNT_F_HGSS | OBJ_EVENT_GFX_ROCKET_GRUNT_F_HGSS | 2041 píxeles |
| [rocket_grunt_m_hgss](../../graphics/entrenadores/rocket_grunt_m_hgss) | TRAINER_PIC_ROCKET_GRUNT_M_HGSS | OBJ_EVENT_GFX_ROCKET_GRUNT_M_HGSS | 1906 píxeles |
| [roughneck_hgss](../../graphics/entrenadores/roughneck_hgss) | TRAINER_PIC_ROUGHNECK_HGSS | Pendiente | 0 píxeles |
| [roughneck_platinum](../../graphics/entrenadores/roughneck_platinum) | TRAINER_PIC_ROUGHNECK_PLATINUM | OBJ_EVENT_GFX_ROUGHNECK_PLATINUM | 1673 píxeles |
| [ruin_maniac_hgss](../../graphics/entrenadores/ruin_maniac_hgss) | TRAINER_PIC_RUIN_MANIAC_HGSS | Pendiente | 0 píxeles |
| [ruin_maniac_platinum](../../graphics/entrenadores/ruin_maniac_platinum) | TRAINER_PIC_RUIN_MANIAC_PLATINUM | OBJ_EVENT_GFX_RUIN_MANIAC_PLATINUM | 1822 píxeles |
| [sabrina_hgss](../../graphics/entrenadores/sabrina_hgss) | TRAINER_PIC_SABRINA_HGSS | OBJ_EVENT_GFX_SABRINA_HGSS | 2150 píxeles |
| [sage_hgss](../../graphics/entrenadores/sage_hgss) | TRAINER_PIC_SAGE_HGSS | Pendiente | 0 píxeles |
| [sage_korean_hgss](../../graphics/entrenadores/sage_korean_hgss) | TRAINER_PIC_SAGE_KOREAN_HGSS | Pendiente | 0 píxeles |
| [sailor_hgss](../../graphics/entrenadores/sailor_hgss) | TRAINER_PIC_SAILOR_HGSS | OBJ_EVENT_GFX_SAILOR_HGSS | 2309 píxeles |
| [sailor_platinum](../../graphics/entrenadores/sailor_platinum) | TRAINER_PIC_SAILOR_PLATINUM | OBJ_EVENT_GFX_SAILOR_PLATINUM | 2201 píxeles |
| [saturn_platinum](../../graphics/entrenadores/saturn_platinum) | TRAINER_PIC_SATURN_PLATINUM | OBJ_EVENT_GFX_SATURN_PLATINUM | 730 píxeles |
| [school_kid_f_hgss](../../graphics/entrenadores/school_kid_f_hgss) | TRAINER_PIC_SCHOOL_KID_F_HGSS | Pendiente | 0 píxeles |
| [school_kid_f_platinum](../../graphics/entrenadores/school_kid_f_platinum) | TRAINER_PIC_SCHOOL_KID_F_PLATINUM | OBJ_EVENT_GFX_SCHOOL_KID_F_PLATINUM | 2095 píxeles |
| [school_kid_m_hgss](../../graphics/entrenadores/school_kid_m_hgss) | TRAINER_PIC_SCHOOL_KID_M_HGSS | Pendiente | 0 píxeles |
| [school_kid_m_platinum](../../graphics/entrenadores/school_kid_m_platinum) | TRAINER_PIC_SCHOOL_KID_M_PLATINUM | Pendiente | 0 píxeles |
| [scientist_hgss](../../graphics/entrenadores/scientist_hgss) | TRAINER_PIC_SCIENTIST_HGSS | OBJ_EVENT_GFX_SCIENTIST_HGSS | 2088 píxeles |
| [scientist_johto_hgss](../../graphics/entrenadores/scientist_johto_hgss) | TRAINER_PIC_SCIENTIST_JOHTO_HGSS | Pendiente | 0 píxeles |
| [scientist_platinum](../../graphics/entrenadores/scientist_platinum) | TRAINER_PIC_SCIENTIST_PLATINUM | OBJ_EVENT_GFX_SCIENTIST_PLATINUM | 1742 píxeles |
| [silver_hgss](../../graphics/entrenadores/silver_hgss) | TRAINER_PIC_SILVER_HGSS | OBJ_EVENT_GFX_SILVER_HGSS | 2312 píxeles |
| [silver_unused_hgss](../../graphics/entrenadores/silver_unused_hgss) | TRAINER_PIC_SILVER_UNUSED_HGSS | Pendiente | 0 píxeles |
| [sis_and_bro_unused_censored_platinum](../../graphics/entrenadores/sis_and_bro_unused_censored_platinum) | TRAINER_PIC_SIS_AND_BRO_UNUSED_CENSORED_PLATINUM | Pendiente | 0 píxeles |
| [sis_and_bro_unused_platinum](../../graphics/entrenadores/sis_and_bro_unused_platinum) | TRAINER_PIC_SIS_AND_BRO_UNUSED_PLATINUM | Pendiente | 0 píxeles |
| [skier_f_hgss](../../graphics/entrenadores/skier_f_hgss) | TRAINER_PIC_SKIER_F_HGSS | Pendiente | 0 píxeles |
| [skier_f_platinum](../../graphics/entrenadores/skier_f_platinum) | TRAINER_PIC_SKIER_F_PLATINUM | OBJ_EVENT_GFX_SKIER_F_PLATINUM | 501 píxeles |
| [skier_m_platinum](../../graphics/entrenadores/skier_m_platinum) | TRAINER_PIC_SKIER_M_PLATINUM | OBJ_EVENT_GFX_SKIER_M_PLATINUM | 2132 píxeles |
| [socialite_hgss](../../graphics/entrenadores/socialite_hgss) | TRAINER_PIC_SOCIALITE_HGSS | Pendiente | 0 píxeles |
| [socialite_platinum](../../graphics/entrenadores/socialite_platinum) | TRAINER_PIC_SOCIALITE_PLATINUM | OBJ_EVENT_GFX_SOCIALITE_PLATINUM | 1009 píxeles |
| [steven_hgss](../../graphics/entrenadores/cajon_de_sastre/steven_hgss) | Pendiente | OBJ_EVENT_GFX_STEVEN_HGSS | 0 píxeles |
| [super_nerd_hgss](../../graphics/entrenadores/super_nerd_hgss) | TRAINER_PIC_SUPER_NERD_HGSS | Pendiente | 0 píxeles |
| [swimmer_f_hgss](../../graphics/entrenadores/swimmer_f_hgss) | TRAINER_PIC_SWIMMER_F_HGSS | OBJ_EVENT_GFX_SWIMMER_F_HGSS | 1903 píxeles |
| [swimmer_f_platinum](../../graphics/entrenadores/swimmer_f_platinum) | TRAINER_PIC_SWIMMER_F_PLATINUM | OBJ_EVENT_GFX_SWIMMER_F_PLATINUM | 2292 píxeles |
| [swimmer_m_censored_hgss](../../graphics/entrenadores/swimmer_m_censored_hgss) | TRAINER_PIC_SWIMMER_M_CENSORED_HGSS | Pendiente | 0 píxeles |
| [swimmer_m_censored_platinum](../../graphics/entrenadores/swimmer_m_censored_platinum) | TRAINER_PIC_SWIMMER_M_CENSORED_PLATINUM | Pendiente | 0 píxeles |
| [swimmer_m_hgss](../../graphics/entrenadores/swimmer_m_hgss) | TRAINER_PIC_SWIMMER_M_HGSS | OBJ_EVENT_GFX_SWIMMER_M_HGSS | 2076 píxeles |
| [swimmer_m_platinum](../../graphics/entrenadores/swimmer_m_platinum) | TRAINER_PIC_SWIMMER_M_PLATINUM | Pendiente | 0 píxeles |
| [teacher_hgss](../../graphics/entrenadores/teacher_hgss) | TRAINER_PIC_TEACHER_HGSS | Pendiente | 0 píxeles |
| [thorton_hgss](../../graphics/entrenadores/thorton_hgss) | TRAINER_PIC_THORTON_HGSS | Pendiente | 0 píxeles |
| [thorton_platinum](../../graphics/entrenadores/thorton_platinum) | TRAINER_PIC_THORTON_PLATINUM | Pendiente | 0 píxeles |
| [tuber_f_hgss](../../graphics/entrenadores/tuber_f_hgss) | TRAINER_PIC_TUBER_F_HGSS | Pendiente | 0 píxeles |
| [tuber_f_platinum](../../graphics/entrenadores/tuber_f_platinum) | TRAINER_PIC_TUBER_F_PLATINUM | OBJ_EVENT_GFX_TUBER_F_PLATINUM | 2044 píxeles |
| [tuber_m_hgss](../../graphics/entrenadores/tuber_m_hgss) | TRAINER_PIC_TUBER_M_HGSS | Pendiente | 0 píxeles |
| [tuber_m_platinum](../../graphics/entrenadores/tuber_m_platinum) | TRAINER_PIC_TUBER_M_PLATINUM | OBJ_EVENT_GFX_TUBER_M_PLATINUM | 1962 píxeles |
| [twins_hgss](../../graphics/entrenadores/twins_hgss) | TRAINER_PIC_TWINS_HGSS | OBJ_EVENT_GFX_TWINS_HGSS | 1661 píxeles |
| [twins_platinum](../../graphics/entrenadores/twins_platinum) | TRAINER_PIC_TWINS_PLATINUM | OBJ_EVENT_GFX_TWINS_PLATINUM | 1700 píxeles |
| [veteran_hgss](../../graphics/entrenadores/veteran_hgss) | TRAINER_PIC_VETERAN_HGSS | Pendiente | 0 píxeles |
| [veteran_platinum](../../graphics/entrenadores/veteran_platinum) | TRAINER_PIC_VETERAN_PLATINUM | Pendiente | 0 píxeles |
| [volkner_platinum](../../graphics/entrenadores/volkner_platinum) | TRAINER_PIC_VOLKNER_PLATINUM | OBJ_EVENT_GFX_VOLKNER_PLATINUM | 2134 píxeles |
| [waiter_hgss](../../graphics/entrenadores/waiter_hgss) | TRAINER_PIC_WAITER_HGSS | Pendiente | 0 píxeles |
| [waiter_platinum](../../graphics/entrenadores/waiter_platinum) | TRAINER_PIC_WAITER_PLATINUM | OBJ_EVENT_GFX_WAITER_PLATINUM | 1395 píxeles |
| [waitress_hgss](../../graphics/entrenadores/waitress_hgss) | TRAINER_PIC_WAITRESS_HGSS | Pendiente | 0 píxeles |
| [waitress_platinum](../../graphics/entrenadores/waitress_platinum) | TRAINER_PIC_WAITRESS_PLATINUM | OBJ_EVENT_GFX_WAITRESS_PLATINUM | 1436 píxeles |
| [whitney_hgss](../../graphics/entrenadores/whitney_hgss) | TRAINER_PIC_WHITNEY_HGSS | OBJ_EVENT_GFX_WHITNEY_HGSS | 2912 píxeles |
| [will_hgss](../../graphics/entrenadores/will_hgss) | TRAINER_PIC_WILL_HGSS | OBJ_EVENT_GFX_WILL_HGSS | 1959 píxeles |
| [worker_hgss](../../graphics/entrenadores/worker_hgss) | TRAINER_PIC_WORKER_HGSS | Pendiente | 0 píxeles |
| [worker_platinum](../../graphics/entrenadores/worker_platinum) | TRAINER_PIC_WORKER_PLATINUM | OBJ_EVENT_GFX_WORKER_PLATINUM | 1721 píxeles |
| [young_couple_hgss](../../graphics/entrenadores/young_couple_hgss) | TRAINER_PIC_YOUNG_COUPLE_HGSS | Pendiente | 0 píxeles |
| [young_couple_platinum](../../graphics/entrenadores/young_couple_platinum) | TRAINER_PIC_YOUNG_COUPLE_PLATINUM | Pendiente | 0 píxeles |
| [youngster_hgss](../../graphics/entrenadores/youngster_hgss) | TRAINER_PIC_YOUNGSTER_HGSS | OBJ_EVENT_GFX_YOUNGSTER_HGSS | 1882 píxeles |
| [youngster_platinum](../../graphics/entrenadores/youngster_platinum) | TRAINER_PIC_YOUNGSTER_PLATINUM | OBJ_EVENT_GFX_YOUNGSTER_PLATINUM | 1840 píxeles |

## Fuentes conservadas

Las hojas conservan sus créditos originales: MufasaKong (fronts), Spacemotion (OW Platinum), Dragoon (OW HGSS) y redblueyellow (Barry). Los manifiestos detallan la procedencia de cada celda.

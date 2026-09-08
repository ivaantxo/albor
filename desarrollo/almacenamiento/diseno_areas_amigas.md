# Almacenamiento en áreas amigas

Diseño técnico, 5 de septiembre de 2026. Revisión estática del motor; todavía no hay implementación ni validación en emulador. Las cifras de ocupación propuestas deben verificarse con el mapa y los efectos reales.

## Experiencia propuesta

El PC conserva su punto de acceso. Al abrir el almacenamiento aparece un selector textual de mundos con nombre y ocupación. Elegir uno entra en un mapa transitable inspirado en las Friend Areas de Mystery Dungeon. El jugador camina y los Pokémon de ese mundo deambulan dentro de zonas accesibles. A delante de un Pokémon lo orienta hacia el jugador, muestra una reacción breve y abre Recoger / Mover / Liberar / Cancelar.

- **Recoger:** con hueco, pasa al equipo. Con seis miembros, aparece una lista textual con mote, especie y nivel; elegir uno propone intercambiarlo por el residente. El miembro saliente ocupa exactamente la plaza que deja el entrante. Cancelar conserva ambos Pokémon.
- **Mover:** selector textual de mundos y ocupación. Se valida el destino antes de transferir. Un mundo lleno no se puede elegir; cancelar no cambia nada.
- **Liberar:** pregunta explícita con el mote y especie, con No seleccionado inicialmente. La eliminación sucede únicamente después del Sí y de las comprobaciones que hoy aplica el almacenamiento.
- **Depositar:** opción necesaria en el menú del área para enviar un miembro del equipo al mundo actual. Lista textual, validación de hueco, correo y equipo válido. También accesible desde el PC para no obligar a entrar en un mapa al depositar.
- **Cambiar mundo / Salir:** menú del área y salida física señalizada. Regreso al PC de origen, con orientación y estado de campo restaurados. B cierra primero el diálogo o menú abierto.

El follower del equipo se oculta temporalmente dentro del área: el jugador visita a los residentes. Evita consumir otro objeto y otra paleta. Los residentes no acompañan al jugador fuera del mapa hasta que hayan pasado al equipo por Recoger.

## Límites contrastados

| Recurso | Evidencia | Consecuencia |
| --- | --- | --- |
| Paletas OBJ | `src/sprite.c`, `IndexOfSpritePaletteTag`: búsqueda en 16 ranuras | Hasta 16 paletas de sprites simultáneas sin multiplexado; no equivale por sí solo a 16 Pokémon. |
| Objetos del mapa | `include/constants/global.h`: `OBJECT_EVENTS_COUNT 16` | Jugador + 15 residentes es el techo actual de objetos, antes de otros NPC/follower. |
| Paletas individuales | `src/event_object_movement.c`, `CargaPaletaFollower` | Se aplica tono por personalidad; no se puede presupuestar que la misma especie comparta paleta. |
| Recarga de paleta | `RecargaPaletaObjetoPokemon` carga la nueva antes de soltar la anterior | Llenar todas las ranuras puede impedir corregir el tono después de crear el objeto. |
| PC actual | `src/pokemon_storage_system.c`, `HBlankCB_PokeStorage` | Cambia paletas en líneas fijas para filas de seis. Ese callback no sirve directamente con residentes que caminan libremente. |
| Guardado | `include/pokemon_storage_system.h`, `PokemonStorage` | 30 cajas de 30 posiciones, 900 plazas. Reducir `IN_BOX_COUNT` alteraría la estructura persistente y sus consumidores. |
| Diálogos | `src/window.c` usa ventanas asociadas a BG | Texto y marco pueden usar paletas de fondo, sin consumir una paleta OBJ adicional. |

Presupuesto inicial recomendado: **14 residentes + jugador**, con una paleta OBJ de margen y un objeto de mapa libre. Es un objetivo de prototipo, no una capacidad garantizada: hay que medir efectos de campo, emotes, sombras/reflejos, VRAM de sprites grandes y carga transitoria de paletas. La reserva se debe gestionar expresamente para que un efecto decorativo no la consuma accidentalmente. Los mapas iniciales usarán suelo sin efectos, iluminación estable y decoración en tiles.

**15 residentes + jugador** es una optimización posterior plausible si se configura la personalidad antes de cargar la paleta y no hay efectos que necesiten otra. **16 residentes + jugador** requiere ampliar o sustituir el sistema de objetos y resolver también las paletas; no se obtiene eliminando el cursor.

## Iconos del equipo en una franja superior

Es técnicamente plausible multiplexar las paletas de los iconos arriba y las del mapa abajo. La separación debe existir en coordenadas de pantalla y abarcar todos los píxeles de cada sprite, incluidos animaciones, sprites altos, cámara y efectos. Que el jugador no pueda pisar la parte superior del mapa no garantiza esa separación.

Haría falta una franja fija, recorte de sprites del mapa en esa franja, restauración de paletas en VBlank y cambio antes de la primera línea visible del área. También habría que comprobar el tiempo del DMA/copiado y la convivencia con otros callbacks. Esto exige un prototipo medido; no está verificado en esta revisión.

Primera versión: selección de equipo completamente textual, con indicador dibujado en BG. Una alternativa futura es una pantalla de equipo independiente, liberando temporalmente los sprites del área. Ambas evitan condicionar todos los mapas a una franja superior.

## Mundos y compatibilidad del guardado

Separar identidad lógica del mundo, escenario gráfico y posición física del Pokémon. El mapa no contiene copias persistentes de Pokémon: cada residente mantiene una referencia `(boxId, slotId)` y cada objeto visible se vincula a ella. Mover un objeto nunca mueve implícitamente datos del guardado.

Propuesta conservadora inicial: mantener intactas las 900 plazas y presentar cada caja como un mundo de **tres sectores**, con intervalos fijos 0–13, 14–27 y 28–29. Cada sector tiene como máximo 14 residentes. Los sectores se cambian mediante transición, no manteniendo ambos cargados. Las plazas vacías no desplazan las referencias de los demás residentes.

Es una solución de compatibilidad con un coste visible: el tercer sector tiene poca capacidad. Si se acepta finalmente 15 residentes, cada mundo se divide naturalmente en dos sectores de 15. No se afirma que una caja de 30 pueda mostrarse completa simultáneamente.

Si se prefiere estrictamente que cada mundo completo tenga solo 14 o 15 plazas, diseñar una segunda fase de reorganización lógica sobre las 900 posiciones. Requiere adaptar todos los consumidores que hoy interpretan caja/nombre/posición, incluidas capturas, selección automática de caja, búsquedas y mensajes; no basta con cambiar la interfaz del PC. No reducir capacidad ni migrar guardados silenciosamente.

El selector debe mostrar ocupación del mundo y del sector y permitir ir directamente a sectores poblados. Al mover se elige mundo y, si procede, sector disponible. Al depositar se usa el sector actual si tiene hueco; si está lleno se ofrece otro explícitamente.

## Mapas editables y recursos

Usar mapas normales del motor, con tilesets, metatiles, colisiones, elevaciones, entrada y puntos de aparición editables en Porymap. Cada definición de área referencia mapa/layout y una lista de posiciones transitables. Los residentes se generan dinámicamente: no se escriben 14 especies fijas en el mapa.

La colección de [Red Rescue Team en The Spriters Resource](https://www.spriters-resource.com/game_boy_advance/pokemonmysterydungeonredrescueteam/) lista 57 Friend Areas. Sirve como punto de partida para seleccionar escenarios; esta revisión no ha descargado ni convertido sus gráficos. Una imagen del escenario no incluye automáticamente colisiones, capas ni un tileset listo para Emerald.

Proceso por escenario: identificar el recurso y su crédito, separar gráficos en tiles de 8×8, ajustar paletas y presupuesto de tiles del proyecto, construir metatiles de 16×16, montar el layout y definir colisiones, capas y posiciones. La [documentación de Porymap](https://huderlem.github.io/porymap/manual/tileset-editor.html) documenta el tileset PNG indexado y la edición de metatiles. La conversión concreta debe probarse con un área antes de preparar el catálogo completo.

Cada residente debe ser alcanzable desde la entrada. Evitar pasos estrechos que puedan bloquear los Pokémon. Los acuáticos pueden ocupar estanques con casillas de interacción desde la orilla; el jugador no necesita activar Surf. Los puntos iniciales y su zona de paseo deben cumplir las mismas reglas. Huevos se muestran inmóviles y tienen interacción propia.

## Integración del motor

1. Conservar `ShowPokemonStorageSystemPC` como acceso y dirigir el nuevo flujo desde allí. Extraer operaciones de almacenamiento de su dependencia de `sStorage`, sprites y tareas de la interfaz antigua.
2. Crear un controlador de sesión de área: origen del PC, mundo/sector, estado de menús y relación objeto→posición. Mantener el contexto de retorno hasta terminar la restauración, incluidas las salidas por fallo de carga.
3. Instanciar los residentes con especie, forma, sexo, shiny y personalidad de su `BoxPokemon`. Revisar la inicialización para evitar cargar primero una paleta provisional que consume la última ranura.
4. Generalizar la interacción de follower para recibir Pokémon y objeto objetivo. Los scripts actuales de `data/scripts/follower*` usan `LOCALID_FOLLOWER`; no se pueden reutilizar sin adaptar ese destino. Las reacciones que consultan al miembro del equipo deben consultar al residente. Usar una conversión temporal a `Pokemon` cuando se necesiten datos derivados, sin escribirla automáticamente al almacenamiento.
5. Mantener el mapa en un contexto de visita: sin encuentros, veneno por pasos, eclosión, scripts de historia ni otras consecuencias de caminar hasta auditar cada hook. No permitir guardar una ubicación temporal sin un mecanismo de recuperación; en la primera versión, guardar se realiza al regresar al mundo normal.
6. Al abrir una interacción, congelar movimiento. Tras confirmar una operación, actualizar datos y después reconstruir los sprites afectados. Un fallo gráfico permite reintentar la visualización, nunca repetir la transferencia.

## Integridad de las operaciones

Validar origen, destino, ocupación y restricciones antes de escribir. Preparar copias temporales para recogida e intercambio, conservando personalidad, OT, objeto, movimientos y demás datos. Usar conversiones oficiales `BoxMonAtToMon` y las API de `BoxPokemon`; respetar el comportamiento actual respecto a curación y datos derivados al depositar/recoger.

El intercambio con equipo lleno debe completarse como una sola operación síncrona, sin menús, guardado ni callbacks entre las escrituras. El Pokémon saliente usa la plaza liberada aunque el mundo esté lleno. Validar que el equipo resultante siga siendo válido, especialmente si el entrante es un huevo.

Liberar reutiliza las restricciones efectivas de `Task_ReleaseMon`/`RunCanReleaseMon`, incluidas las relativas a huevos y movimientos protegidos según configuración. Revisar también correo y tratamiento del objeto equipado para mantener la conducta vigente. No copiar únicamente el borrado de la posición.

## Orden de implementación y aceptación

1. Área piloto editable con jugador y 14 residentes reales, acceso y regreso al PC. Medir paletas, objetos, VRAM y estabilidad con los sprites de mayor tamaño. Demostrar acceso a todos los residentes y retorno correcto.
2. Interacción, recogida, intercambio, depósito, movimiento y liberación confirmada, con listas textuales. Verificar conservación exacta de datos y cancelación en cada paso.
3. Sectores y mundos completos: cargar una partida con 900 plazas ocupadas, comprobar que todas siguen accesibles y que las capturas mantienen el comportamiento previsto. Confirmar también el caso de almacenamiento lleno.
4. Adaptar el primer recurso de Friend Area y verificar su edición en Porymap, capas, colisiones y coste gráfico. Después ampliar el catálogo.
5. Evaluar 15 residentes y, de forma independiente, la franja de iconos. Aceptarlos solo si superan las pruebas de saturación y transiciones.

Casos obligatorios: dos ejemplares iguales con tonos distintos; shiny y variantes de sexo/forma; huevo; equipo lleno; último miembro válido; destino lleno; cancelar confirmación; repetir entrada/salida; mover repetidamente sin fuga de paletas; fallo de creación de sprite; cambio de sector; intercambio en mundo lleno; restauración del follower y del origen del PC. Comparar los Pokémon antes y después de una vuelta guardar/cargar. La inspección estática realizada no sustituye estas pruebas.

La separación entre gráficos BG y OBJ, sus tiles y paletas se apoya en [Tonc](https://gbadev.net/tonc/objbg.html); los límites específicos y puntos de integración anteriores proceden del código de Albor.

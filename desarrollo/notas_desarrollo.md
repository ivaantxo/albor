- Implementar repartir experiencia/buscapelea como opciones de menú.
- Implementar animación de subir de nivel no usada.
- Arreglar formas/evos +3 en Pokédex.
- Indicar que: * No es posible el uso de la mochila en batalla.
               * Para capturar, basta con tener Pokéballs, y para seleccionarla, mantener pulsado B a la vez que R.
- Crear ataques como Tornado, Vendaval...
- L/R icons en storage.
- Crear huevos personalizados en pokédex.
- Intentar crear animaciones de entrenadores.
- Insertar gráfico de tabla de tipos + características de tipos como opción.
- Añadir características especiales a cada tipo.
- Balance:  *480 - 40
            *500 - 45
            *520 - 50
            *540 - 55
            *560 - 60
            *580 - 65
            *600 - 70
            *620 - 75
            *640 - 80
- Testear Generador.
- Destruir icono Pokémon al darle a huir.
- Implementar la opción de rendirse contra entrenadores.
- Crear bomba ácida.
- Crear bg basado en moxie boosted.
- Darle puño furia a Mankey al nivel 31.
- Hacer glaciación un surf con probabilidad de helar.
- Crear ataque Agua helada (Escaldar pero que congele). Milotic, Lapras, Dewgong.
- Falta balancear Parálisis, Dormido, Confuso, Enamorado, Envenenado (y gravemente envenenado), Retroceso.
- Testear Parásito, Nueve Colas, Humedad relativa, Globo.
- Testear Mimetismo, Percusionista.
- Lucky Punch objeto característico de Hitmonchan (hacer que lo lleve equipado).
- Testear Impenetrable.
- Indicar que Breaking Swipe tiene boost de Dinocola.
- Indicar que Poison Sting, Smart Strike tienen boost de Cornamenta.
- Campo magnético
- Indicar y comprobar que Ditto ya no está en el juego, pero que la mayoría de Pokémon que antes no podían criar, ahora sí lo hacen: Los Pokémon legendarios son género neutro y se les ha añadido grupos huevo acordes, para criar solo hay que juntar 2 Pokémon sin género del mismo grupo huevo. 
- Last Respects como una versión de paliza fantasma.
- Cambiar animación de Presente.
- Crear ataque Abducción (animación otra vez).
- Crear habilidad Instinto de supervivencia, sube at. y at. esp y vel. si salud debajo de 50% (relicanth)
- Habilidad Instito maternal: Recibe todos los ataques en dobles (señuelo), kangaskhan, nidoquen.
- Mirar lo que hace la expansión para mostrar tipos dinámicos en combate (Weather ball, día de pago).
- Testear Mago.
- Arreglar animación al subir de nivel (incorporar la no usada como indicador de evo).
- Cambiar animación de Chupasangre usando como referencia Colmillo Veneno.
- Check move_target_all_battlers de lightning rod vs storm drain.
- Hueso quemado (objeto raro en Cubone que lo hace evolucionar a Marowak Alolan).
- Usar viejas partículas: ANIM_TAG_ASCUAS.
- Arreglar tiendas.
- Arreglar icono de guardado que cambia con el día.
- Huevos heredan 50% de las veces habilidad de la madre.
- Huevos tienen 50% en cada estadística de heredar los IVs del padre o de la madre: 2 padres con 31 IVs en ataque darán siempre un huevo con 31 IVs en ataque.
- Huevos heredan 50% naturaleza del padre y 50% de la madre.
- Probabilidad de movimientos que golpean de 2 a 5 veces: 25% cada una.
- Shedinja tiene nueva habilidad: Guarda, resiste (x0.5) los golpes neutros (x1).
- Shedinja ahora tiene nuevos stats, y no tiene solo 1 PS. Además, a la hora de crianza, si tiene naturaleza Ofensiva, pasa a tenerla Ofensiva especial (es atacante especial, mientras que Ninjask es físico).
- Revisar habilidades Cromolente y Guarda, hacer que haya un aviso al golpear (solo la primera vez?).
- Revisar crianza/ia/creación de Shedinja.
- Furia dragón y Bomba sónica ahora son Escaldar de sus tipos respectivos.
- Chequear que no haya roto Sombra trampa.
- gHitMarker voy a por ti.
- Teletransporte un Relevo psíquico (siempre puede escapar de trapping? prioridad?)
- Triataque 3 golpes de diferente tipo (10% cada uno?)
- case ESPERA_ACCION revisar
- Trampas: Ahora hay 6 trampas tipo Trampa rocas: Espinas (planta), Trampa rocas (roca), Púas (acero), Brasas (fuego), Esquirlas heladas (hielo), Púas tóxicas (veneno). Todas funcionan como trampa rocas, hacen daño a Pokémon que estén en el suelo (no causan estados). Trampa rocas ahora no hace efecto a Pokémon voladores o que leviten. Además, no hay "cantidad" de trampa rocas, y el daño se establece según la efectividad del tipo de la trampa con el defensor:
x0 --> 0; x0,25 --> PS máximos / 64; x0,5 --> PS máximos / 32; x1 --> PS máximos / 16; x2 --> PS máximos / 8; x4 --> PS máximos / 4.

- Chequear Volt absorb

- Convertir la lista de gSideStatuses relacionados con trampas en variables dentro de gCombate (quizás un enum?) y hacer una tabla, especificar que ya no se "absorben" las trampas, aunque quizá se pueda añadir un número de veces que sea efectivo (número de turnos? número de veces que hace daño?)

- Revisar Color change vs Growl (y otros). Revisar vs bromista. Revisar vs Toxico (estados), Lanzallamas, etc. Revisar vs moves que pueden fallar, o que Kecleon es inmune ANTES (debería de cambiar tipo SOLO si recibe el ataque).

*limpiar minijuegos y saveblocks

*paletas: 0-12 tileset primario 0-9 (es necesario?) secundario 10-12 (chequear SWAP_PAL)
*paletas primary: 0/arboles 1/centro_pokemon 2/hierba_y_hierba_alta 3/agua 4/agua_playa

porytiles compile-primary -Wall -o /Users/ivanmartinez/Documents/Volverá/albor/data/tilesets/primary/principal /Users/ivanmartinez/Documents/Volverá/albor/desarrollo/graficos /Users/ivanmartinez/Documents/Volverá/albor/include/constants/metatile_behaviors.h

porytiles compile-primary -Wall -o /Users/ivanmartinez/proyectos/albor/data/tilesets/primary/centro_pokemon /Users/ivanmartinez/proyectos/albor/desarrollo/graficos /Users/ivanmartinez/proyectos/albor/include/constants/metatile_behaviors_porytiles.h

*Recordatorio de que el primer color de la paleta del Pokémon no puede ser negro (se bugea el almacenamiento).
*Recordatorio de deserializar las pokeballs.
*Recordatorio de revisar learnsets (encanto, especialmente).
*Recordatorio de limpiar species_info (traducir, solo lo necesario y usar constantes).
*Arreglar .pal de Charmander (y de charmeleon?) No de Charizard.
*Añadir caso de crianza para Latios/Latias y Nidoran.
*¿Cómo criar a Tauros?
*Decouple poké balls de item id
*Jigglypuff evoluciona al aprender Vozarrón.
*Cloyster/Slowking/Slowbro aprenden ataques Veneno (+Ataque custom tipo Control Mental?)
*Golpes críticos: posibilidades neutra: 6%, +1: 12%, +2: 24%, +3: 48%, +4: 96%.
paletas: (\d+) (\d+) (\d+) \d+ --> $1 $2 $3

//falta terminar lista de macros (scrcmd...) y terminar strings, después comprobar que todo va bien, y añadir cambios de rama principal.

//para limpiar archivos generados
find . -name "* 2.inc" -delete

//para limpiar defines a enum
\s+[0-9]+

//revisar animación y crear efecto de Triataque
//solucionar: problema de que se envían 2 pokémon 2 veces + problema iconos al debilitarse un pokémon (quizá también con 2)

// revisar el bug rarísimo: si haces x (entras a cualquier pantalla) y hablas con pokémon, invalid address

// terminar confusión: "añade" daño por retroceso (durante x turnos? al cambiar se limpia?), no posibilidad de no atacar.
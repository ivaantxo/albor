// Los movimientos que recorre el filtro "problemas" del laboratorio. Se rellena a
// mano, y esta pensado para vaciarse y volver a llenarse cada vez que haga falta.
//
// El repaso completo de las animaciones termino: aqui ya no queda la lista de los
// que tocaban monbg. Lo que queda es el esqueleto, que es lo util: cuando se quiera
// mirar un grupo concreto -los que cargan un fondo, los que deforman al Pokemon, los
// que acaban de tocarse- se pegan aqui sus identificadores y START los recorre
// seguidos, sin pasar por los novecientos.
//
// Las listas largas salen de leer data/battle_anim_scripts.s Y las tareas de C: la
// mitad de las cosas -la distorsion, los blends, quien toca los registros- esta en
// la tarea y no se ve en el guion.
//
// Tiene que quedar al menos un elemento: C no admite un array vacio. Ahora mismo
// lleva los dos que tienen un @ TODO de revisar en el guion.
static const u16 sMovimientosProblematicos[] =
{
    MOVE_TAIL_GLOW,        // no remata en el objetivo
    MOVE_WATER_SHURIKEN,   // se ve mal
};

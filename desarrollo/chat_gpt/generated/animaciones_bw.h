// Generado por desarrollo/chat_gpt/integrar.py. Regenerar tras cambiar fuentes o selecciones.
#define PLACEHOLDER_ANIM_SINGLE_FRAME(name)     \
static const __attribute__((unused)) union AnimCmd sAnim_##name[] =     \
{                                               \
    ANIMCMD_FRAME(0, 1),                        \
    ANIMCMD_END,                                \
}

static const __attribute__((unused)) union AnimCmd sAnim_None[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

// El vaiven da un saltito hacia delante -la pose 1- y el gesto reaprovecha esa misma
// pose para frenar en seco antes de agacharse. Cinco imagenes: 0 reposo, 1 arriba,
// 2 abajo, 3 transicion del gesto, 4 gesto.
static const __attribute__((unused)) union AnimCmd sAnim_Bulbasaur[] =
{
    BUCLE_PRINCIPAL(0, 1, 0, 2, 0),
    BUCLE_ESPECIAL(2, 3, 4),
    VUELTA_AL_PRINCIPIO,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ivysaur[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Venusaur[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Charmander[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Charmeleon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Charizard[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Squirtle[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wartortle[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Blastoise[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Caterpie[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Metapod[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Butterfree[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Weedle[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kakuna[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Beedrill[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pidgey[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pidgeotto[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pidgeot[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rattata[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Raticate[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ekans[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Arbok[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pichu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pikachu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Raichu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_RaichuAlola[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sandshrew[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sandslash[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_SandshrewAlola[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};
static const __attribute__((unused)) union AnimCmd sAnim_SandslashAlola[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_NidoranF[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nidorina[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nidoqueen[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_NidoranM[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nidorino[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nidoking[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cleffa[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Clefairy[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Clefable[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Vulpix[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ninetales[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_VulpixAlola[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_NinetalesAlola[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Igglybuff[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Jigglypuff[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wigglytuff[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Zubat[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Golbat[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Crobat[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Paras[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Parasect[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Meowth[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Persian[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Psyduck[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Golduck[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mankey[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Primeape[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Annihilape[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Growlithe[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Arcanine[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Poliwag[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Poliwhirl[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Poliwrath[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Politoed[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Abra[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kadabra[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Alakazam[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Machop[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Machoke[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Machamp[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bellsprout[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Weepinbell[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Victreebel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tentacool[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tentacruel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Geodude[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Graveler[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Golem[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ponyta[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rapidash[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magnemite[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magneton[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magnezone[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Grimer[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Muk[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Shellder[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cloyster[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gastly[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Haunter[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gengar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Onix[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Steelix[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Drowzee[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hypno[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Krabby[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kingler[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Exeggcute[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Exeggutor[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cubone[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Marowak[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};
static const __attribute__((unused)) union AnimCmd sAnim_MarowakAlola[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tyrogue[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hitmonlee[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hitmonchan[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hitmontop[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lickitung[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lickilicky[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Koffing[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Weezing[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

PLACEHOLDER_ANIM_SINGLE_FRAME(WeezingGalar);

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rhyhorn[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rhydon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rhyperior[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tangela[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tangrowth[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kangaskhan[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Horsea[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Seadra[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Kingdra[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Goldeen[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Seaking[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Staryu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Starmie[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_MimeJr[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_MrMime[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Scyther[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Scizor[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

PLACEHOLDER_ANIM_SINGLE_FRAME(Kleavor);

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Smoochum[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Jynx[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Elekid[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Electabuzz[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Electivire[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magby[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magmar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magmortar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pinsir[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tauros[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magikarp[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Gyarados[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lapras[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Eevee[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Vaporeon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Jolteon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Flareon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Espeon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Umbreon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Leafeon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Glaceon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Sylveon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Porygon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Porygon2[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Porygon_Z[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Omanyte[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Omastar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kabuto[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kabutops[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Aerodactyl[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Munchlax[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Snorlax[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Articuno[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Zapdos[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Moltres[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dratini[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dragonair[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dragonite[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mewtwo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mew[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chikorita[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bayleef[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Meganium[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cyndaquil[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Quilava[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Typhlosion[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Totodile[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Croconaw[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Feraligatr[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sentret[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Furret[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hoothoot[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Noctowl[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ledyba[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ledian[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Spinarak[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ariados[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chinchou[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lanturn[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Togepi[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Togetic[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Togekiss[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Natu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Xatu[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mareep[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Flaaffy[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ampharos[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Azurill[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Marill[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Azumarill[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bonsly[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sudowoodo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hoppip[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Skiploom[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Jumpluff[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Aipom[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ambipom[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sunkern[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sunflora[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Yanma[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Yanmega[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Murkrow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Honchkrow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Misdreavus[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mismagius[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Girafarig[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gligar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gliscor[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Snubbull[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Granbull[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Heracross[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sneasel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Weavile[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

PLACEHOLDER_ANIM_SINGLE_FRAME(Sneasler);

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Teddiursa[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ursaring[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Slugma[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Magcargo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Swinub[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Piloswine[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mamoswine[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Delibird[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Houndour[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Houndoom[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Phanpy[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Donphan[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Stantler[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

PLACEHOLDER_ANIM_SINGLE_FRAME(Wyrdeer);

static const __attribute__((unused)) union AnimCmd sAnim_Raikou[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Entei[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Suicune[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Larvitar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pupitar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tyranitar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Lugia[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_HoOh[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Celebi[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Treecko[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Grovyle[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sceptile[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Torchic[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Combusken[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Blaziken[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mudkip[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Marshtomp[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Swampert[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Poochyena[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mightyena[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wurmple[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Silcoon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Beautifly[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cascoon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dustox[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lotad[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lombre[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ludicolo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Seedot[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nuzleaf[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Shiftry[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Taillow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Swellow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wingull[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pelipper[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ralts[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kirlia[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gardevoir[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Gallade[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Surskit[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Masquerain[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Slakoth[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Vigoroth[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Slaking[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nincada[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ninjask[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Shedinja[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Whismur[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Loudred[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Exploud[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Makuhita[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hariyama[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Nosepass[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Probopass[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sableye[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Mawile[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Aron[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lairon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Aggron[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Meditite[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Medicham[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Electrike[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Manectric[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Budew[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Roselia[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Roserade[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Carvanha[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sharpedo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wailmer[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Wailord[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Numel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Camerupt[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Torkoal[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Trapinch[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Vibrava[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Flygon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cacnea[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cacturne[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Swablu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Altaria[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Baltoy[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Claydol[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lileep[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cradily[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Anorith[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Armaldo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Feebas[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Milotic[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};


// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Castform[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_CastformSunny[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_CastformRainy[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_CastformSnowy[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};


static const __attribute__((unused)) union AnimCmd sAnim_CastformSandy[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kecleon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};


// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Duskull[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dusclops[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Dusknoir[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Tropius[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};


// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chingling[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chimecho[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Absol[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Snorunt[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Glalie[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Froslass[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Spheal[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Sealeo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Walrein[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bagon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Shelgon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Salamence[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Beldum[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Metang[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Metagross[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Regirock[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Regice[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Registeel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Latias[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Latios[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kyogre[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Groudon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Rayquaza[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_DeoxysNormal[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_DeoxysAttack[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_DeoxysDefense[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_DeoxysSpeed[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Turtwig[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Grotle[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Torterra[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chimchar[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Monferno[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Infernape[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Piplup[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Prinplup[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Empoleon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Starly[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Staravia[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Staraptor[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bidoof[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bibarel[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Kricketot[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Kricketune[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Shinx[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Luxio[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Luxray[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cranidos[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rampardos[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Shieldon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bastiodon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Combee[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Vespiquen[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Drifloon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Drifblim[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Buneary[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lopunny[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gible[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Gabite[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Garchomp[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Riolu[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lucario[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Skorupi[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Drapion[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Croagunk[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Toxicroak[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Snover[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Abomasnow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Rotom[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_RotomHeat[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_RotomWash[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_RotomFrost[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_RotomFan[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_RotomMow[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Heatran[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Regigigas[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Yamask[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Cofagrigus[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};


// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Frillish[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Jellicent[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Joltik[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Galvantula[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Ferroseed[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Ferrothorn[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Litwick[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lampent[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Chandelure[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Axew[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Fraxure[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Haxorus[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Cubchoo[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Beartic[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Pawniard[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Bisharp[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Deino[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Zweilous[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Hydreigon[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Larvesta[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Volcarona[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Fennekin[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Braixen[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Delphox[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Fletchling[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};
static const __attribute__((unused)) union AnimCmd sAnim_Fletchinder[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Talonflame[] =
{
    ANIMCMD_FRAME(1, 55),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Tyrunt[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Tyrantrum[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Amaura[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Aurorus[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Rowlet[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Dartrix[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Decidueye[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};




static const __attribute__((unused)) union AnimCmd sAnim_Jangmo_O[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Hakamo_O[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Kommo_O[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Lunatone[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

// Animacion de BW: vaiven continuo y, cada tres vueltas, el gesto especial mas la
// transicion de vuelta al reposo. 0 reposo, 1 vaiven, 2 especial, 3 transicion.
static const __attribute__((unused)) union AnimCmd sAnim_Solrock[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_JUMP(0),
};

static const __attribute__((unused)) union AnimCmd sAnim_Rookidee[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Corvisquire[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const __attribute__((unused)) union AnimCmd sAnim_Corviknight[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

PLACEHOLDER_ANIM_SINGLE_FRAME(Blipbug);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dottler);
PLACEHOLDER_ANIM_SINGLE_FRAME(Orbeetle);

PLACEHOLDER_ANIM_SINGLE_FRAME(Snom);
PLACEHOLDER_ANIM_SINGLE_FRAME(Frosmoth);

PLACEHOLDER_ANIM_SINGLE_FRAME(Dreepy);
PLACEHOLDER_ANIM_SINGLE_FRAME(Drakloak);
PLACEHOLDER_ANIM_SINGLE_FRAME(Dragapult);

static const __attribute__((unused)) union AnimCmd sAnim_Egg[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

// ---------------------------------------------------------------------------
// ESPALDAS
//
// El bando del jugador ve espaldas, y hasta hace poco todas compartian una sola
// animacion -gAnims_MonPic-, un vaiven de dos fotogramas. Ahora cada especie puede
// traer la suya, escrita con las mismas macros que el frente. La que no la traiga
// sigue con la compartida, que hace de provisional: eso se decide en
// SetMultiuseSpriteTemplateToPokemon mirando si backAnimFrames esta a NULL, sin
// nombrar a nadie.
//
// Para darle una a una especie hacen falta dos cosas: escribirla aqui con ESPALDA,
// y anadirle ANIM_ESPALDA(Nombre) a su entrada de species_info.h.
// ---------------------------------------------------------------------------

// Quieto en el primer cuadro, y TERMINA. Es la que corre al salir de la Pokeball:
// quien la lanza espera a animEnded para dar el turno por empezado, asi que una que
// salte deja el combate colgado para siempre. Solo hay una, compartida: parar en el
// primer cuadro es lo mismo para todas.
static const __attribute__((unused)) union AnimCmd sAnim_EspaldaQuieta[] =
{
    ANIMCMD_FRAME(0, 0),
    TERMINA,
};

// Monta la tabla de las cuatro animaciones de una espalda a partir de su vaiven.
//
// El reparto NO es libre: el indice 0 es el de la salida de la Pokeball y tiene que
// terminar, y el 2 es el vaiven continuo, que es el unico que puede dar vueltas. Es
// el mismo orden que gAnims_MonPic. Escrito a mano se equivoca uno una vez y el
// combate se queda colgado sin decir por que; con la macro no hay donde fallar.
#define ESPALDA(nombre)                                                 \
static const __attribute__((unused)) union AnimCmd *const sAnimsEspalda_##nombre[ANIMACIONES_POR_PIC] = \
{                                                                       \
    sAnim_EspaldaQuieta,                                                \
    sAnim_EspaldaQuieta,                                                \
    sAnimEspalda_##nombre,                                              \
    sAnim_EspaldaQuieta,                                                \
}

// Bulbasaur: tres imagenes -0 reposo, 1 arriba, 2 abajo- y la misma forma que el
// bucle principal de su frente, sin gesto especial.
static const __attribute__((unused)) union AnimCmd sAnimEspalda_Bulbasaur[] =
{
    BUCLE_PRINCIPAL(0, 1, 0, 2, 0),
    BUCLE_ESPECIAL(2, 3, 4),
    VUELTA_AL_PRINCIPIO,
};

ESPALDA(Bulbasaur);

#define SINGLE_ANIMATION(name)                      \
static const __attribute__((unused)) union AnimCmd *const sAnims_##name[] = \
{                                                   \
    sAnim_GeneralFrame0,                            \
    sAnim_##name,                                   \
}

SINGLE_ANIMATION(None);
SINGLE_ANIMATION(Bulbasaur);
SINGLE_ANIMATION(Ivysaur);
SINGLE_ANIMATION(Venusaur);
SINGLE_ANIMATION(Charmander);
SINGLE_ANIMATION(Charmeleon);
SINGLE_ANIMATION(Charizard);
SINGLE_ANIMATION(Squirtle);
SINGLE_ANIMATION(Wartortle);
SINGLE_ANIMATION(Blastoise);
SINGLE_ANIMATION(Caterpie);
SINGLE_ANIMATION(Metapod);
SINGLE_ANIMATION(Butterfree);
SINGLE_ANIMATION(Weedle);
SINGLE_ANIMATION(Kakuna);
SINGLE_ANIMATION(Beedrill);
SINGLE_ANIMATION(Pidgey);
SINGLE_ANIMATION(Pidgeotto);
SINGLE_ANIMATION(Pidgeot);
SINGLE_ANIMATION(Rattata);
SINGLE_ANIMATION(Raticate);
SINGLE_ANIMATION(Ekans);
SINGLE_ANIMATION(Arbok);
SINGLE_ANIMATION(Pichu);
SINGLE_ANIMATION(Pikachu);
SINGLE_ANIMATION(Raichu);
SINGLE_ANIMATION(RaichuAlola);
SINGLE_ANIMATION(Sandshrew);
SINGLE_ANIMATION(Sandslash);
SINGLE_ANIMATION(SandshrewAlola);
SINGLE_ANIMATION(SandslashAlola);
SINGLE_ANIMATION(NidoranF);
SINGLE_ANIMATION(Nidorina);
SINGLE_ANIMATION(Nidoqueen);
SINGLE_ANIMATION(NidoranM);
SINGLE_ANIMATION(Nidorino);
SINGLE_ANIMATION(Nidoking);
SINGLE_ANIMATION(Cleffa);
SINGLE_ANIMATION(Clefairy);
SINGLE_ANIMATION(Clefable);
SINGLE_ANIMATION(Vulpix);
SINGLE_ANIMATION(Ninetales);
SINGLE_ANIMATION(VulpixAlola);
SINGLE_ANIMATION(NinetalesAlola);
SINGLE_ANIMATION(Igglybuff);
SINGLE_ANIMATION(Jigglypuff);
SINGLE_ANIMATION(Wigglytuff);
SINGLE_ANIMATION(Zubat);
SINGLE_ANIMATION(Golbat);
SINGLE_ANIMATION(Crobat);
SINGLE_ANIMATION(Paras);
SINGLE_ANIMATION(Parasect);
SINGLE_ANIMATION(Meowth);
SINGLE_ANIMATION(Persian);
SINGLE_ANIMATION(Psyduck);
SINGLE_ANIMATION(Golduck);
SINGLE_ANIMATION(Mankey);
SINGLE_ANIMATION(Primeape);
SINGLE_ANIMATION(Annihilape);
SINGLE_ANIMATION(Growlithe);
SINGLE_ANIMATION(Arcanine);
SINGLE_ANIMATION(Poliwag);
SINGLE_ANIMATION(Poliwhirl);
SINGLE_ANIMATION(Poliwrath);
SINGLE_ANIMATION(Politoed);
SINGLE_ANIMATION(Abra);
SINGLE_ANIMATION(Kadabra);
SINGLE_ANIMATION(Alakazam);
SINGLE_ANIMATION(Machop);
SINGLE_ANIMATION(Machoke);
SINGLE_ANIMATION(Machamp);
SINGLE_ANIMATION(Bellsprout);
SINGLE_ANIMATION(Weepinbell);
SINGLE_ANIMATION(Victreebel);
SINGLE_ANIMATION(Tentacool);
SINGLE_ANIMATION(Tentacruel);
SINGLE_ANIMATION(Geodude);
SINGLE_ANIMATION(Graveler);
SINGLE_ANIMATION(Golem);
SINGLE_ANIMATION(Ponyta);
SINGLE_ANIMATION(Rapidash);
SINGLE_ANIMATION(Magnemite);
SINGLE_ANIMATION(Magneton);
SINGLE_ANIMATION(Magnezone);
SINGLE_ANIMATION(Grimer);
SINGLE_ANIMATION(Muk);
SINGLE_ANIMATION(Shellder);
SINGLE_ANIMATION(Cloyster);
SINGLE_ANIMATION(Gastly);
SINGLE_ANIMATION(Haunter);
SINGLE_ANIMATION(Gengar);
SINGLE_ANIMATION(Onix);
SINGLE_ANIMATION(Steelix);
SINGLE_ANIMATION(Drowzee);
SINGLE_ANIMATION(Hypno);
SINGLE_ANIMATION(Krabby);
SINGLE_ANIMATION(Kingler);
SINGLE_ANIMATION(Exeggcute);
SINGLE_ANIMATION(Exeggutor);
SINGLE_ANIMATION(Cubone);
SINGLE_ANIMATION(Marowak);
SINGLE_ANIMATION(MarowakAlola);
SINGLE_ANIMATION(Tyrogue);
SINGLE_ANIMATION(Hitmonlee);
SINGLE_ANIMATION(Hitmonchan);
SINGLE_ANIMATION(Hitmontop);
SINGLE_ANIMATION(Lickitung);
SINGLE_ANIMATION(Lickilicky);
SINGLE_ANIMATION(Koffing);
SINGLE_ANIMATION(Weezing);
SINGLE_ANIMATION(WeezingGalar);
SINGLE_ANIMATION(Rhyhorn);
SINGLE_ANIMATION(Rhydon);
SINGLE_ANIMATION(Rhyperior);
SINGLE_ANIMATION(Tangela);
SINGLE_ANIMATION(Tangrowth);
SINGLE_ANIMATION(Kangaskhan);
SINGLE_ANIMATION(Horsea);
SINGLE_ANIMATION(Seadra);
SINGLE_ANIMATION(Kingdra);
SINGLE_ANIMATION(Goldeen);
SINGLE_ANIMATION(Seaking);
SINGLE_ANIMATION(Staryu);
SINGLE_ANIMATION(Starmie);
SINGLE_ANIMATION(MimeJr);
SINGLE_ANIMATION(MrMime);
SINGLE_ANIMATION(Scyther);
SINGLE_ANIMATION(Scizor);
SINGLE_ANIMATION(Kleavor);
SINGLE_ANIMATION(Smoochum);
SINGLE_ANIMATION(Jynx);
SINGLE_ANIMATION(Elekid);
SINGLE_ANIMATION(Electabuzz);
SINGLE_ANIMATION(Electivire);
SINGLE_ANIMATION(Magby);
SINGLE_ANIMATION(Magmar);
SINGLE_ANIMATION(Magmortar);
SINGLE_ANIMATION(Pinsir);
SINGLE_ANIMATION(Tauros);
SINGLE_ANIMATION(Magikarp);
SINGLE_ANIMATION(Gyarados);
SINGLE_ANIMATION(Lapras);
SINGLE_ANIMATION(Eevee);
SINGLE_ANIMATION(Vaporeon);
SINGLE_ANIMATION(Jolteon);
SINGLE_ANIMATION(Flareon);
SINGLE_ANIMATION(Espeon);
SINGLE_ANIMATION(Umbreon);
SINGLE_ANIMATION(Leafeon);
SINGLE_ANIMATION(Glaceon);
SINGLE_ANIMATION(Sylveon);
SINGLE_ANIMATION(Porygon);
SINGLE_ANIMATION(Porygon2);
SINGLE_ANIMATION(Porygon_Z);
SINGLE_ANIMATION(Omanyte);
SINGLE_ANIMATION(Omastar);
SINGLE_ANIMATION(Kabuto);
SINGLE_ANIMATION(Kabutops);
SINGLE_ANIMATION(Aerodactyl);
SINGLE_ANIMATION(Munchlax);
SINGLE_ANIMATION(Snorlax);
SINGLE_ANIMATION(Articuno);
SINGLE_ANIMATION(Zapdos);
SINGLE_ANIMATION(Moltres);
SINGLE_ANIMATION(Dratini);
SINGLE_ANIMATION(Dragonair);
SINGLE_ANIMATION(Dragonite);
SINGLE_ANIMATION(Mewtwo);
SINGLE_ANIMATION(Mew);
SINGLE_ANIMATION(Chikorita);
SINGLE_ANIMATION(Bayleef);
SINGLE_ANIMATION(Meganium);
SINGLE_ANIMATION(Cyndaquil);
SINGLE_ANIMATION(Quilava);
SINGLE_ANIMATION(Typhlosion);
SINGLE_ANIMATION(Totodile);
SINGLE_ANIMATION(Croconaw);
SINGLE_ANIMATION(Feraligatr);
SINGLE_ANIMATION(Sentret);
SINGLE_ANIMATION(Furret);
SINGLE_ANIMATION(Hoothoot);
SINGLE_ANIMATION(Noctowl);
SINGLE_ANIMATION(Ledyba);
SINGLE_ANIMATION(Ledian);
SINGLE_ANIMATION(Spinarak);
SINGLE_ANIMATION(Ariados);
SINGLE_ANIMATION(Chinchou);
SINGLE_ANIMATION(Lanturn);
SINGLE_ANIMATION(Togepi);
SINGLE_ANIMATION(Togetic);
SINGLE_ANIMATION(Togekiss);
SINGLE_ANIMATION(Natu);
SINGLE_ANIMATION(Xatu);
SINGLE_ANIMATION(Mareep);
SINGLE_ANIMATION(Flaaffy);
SINGLE_ANIMATION(Ampharos);
SINGLE_ANIMATION(Azurill);
SINGLE_ANIMATION(Marill);
SINGLE_ANIMATION(Azumarill);
SINGLE_ANIMATION(Bonsly);
SINGLE_ANIMATION(Sudowoodo);
SINGLE_ANIMATION(Hoppip);
SINGLE_ANIMATION(Skiploom);
SINGLE_ANIMATION(Jumpluff);
SINGLE_ANIMATION(Aipom);
SINGLE_ANIMATION(Ambipom);
SINGLE_ANIMATION(Sunkern);
SINGLE_ANIMATION(Sunflora);
SINGLE_ANIMATION(Yanma);
SINGLE_ANIMATION(Yanmega);
SINGLE_ANIMATION(Murkrow);
SINGLE_ANIMATION(Honchkrow);
SINGLE_ANIMATION(Misdreavus);
SINGLE_ANIMATION(Mismagius);
SINGLE_ANIMATION(Girafarig);
SINGLE_ANIMATION(Gligar);
SINGLE_ANIMATION(Gliscor);
SINGLE_ANIMATION(Snubbull);
SINGLE_ANIMATION(Granbull);
SINGLE_ANIMATION(Heracross);
SINGLE_ANIMATION(Sneasel);
SINGLE_ANIMATION(Weavile);
SINGLE_ANIMATION(Sneasler);
SINGLE_ANIMATION(Teddiursa);
SINGLE_ANIMATION(Ursaring);
SINGLE_ANIMATION(Slugma);
SINGLE_ANIMATION(Magcargo);
SINGLE_ANIMATION(Swinub);
SINGLE_ANIMATION(Piloswine);
SINGLE_ANIMATION(Mamoswine);
SINGLE_ANIMATION(Delibird);
SINGLE_ANIMATION(Houndour);
SINGLE_ANIMATION(Houndoom);
SINGLE_ANIMATION(Phanpy);
SINGLE_ANIMATION(Donphan);
SINGLE_ANIMATION(Stantler);
SINGLE_ANIMATION(Wyrdeer);
SINGLE_ANIMATION(Raikou);
SINGLE_ANIMATION(Entei);
SINGLE_ANIMATION(Suicune);
SINGLE_ANIMATION(Larvitar);
SINGLE_ANIMATION(Pupitar);
SINGLE_ANIMATION(Tyranitar);
SINGLE_ANIMATION(Lugia);
SINGLE_ANIMATION(HoOh);
SINGLE_ANIMATION(Celebi);
SINGLE_ANIMATION(Treecko);
SINGLE_ANIMATION(Grovyle);
SINGLE_ANIMATION(Sceptile);
SINGLE_ANIMATION(Torchic);
SINGLE_ANIMATION(Combusken);
SINGLE_ANIMATION(Blaziken);
SINGLE_ANIMATION(Mudkip);
SINGLE_ANIMATION(Marshtomp);
SINGLE_ANIMATION(Swampert);
SINGLE_ANIMATION(Poochyena);
SINGLE_ANIMATION(Mightyena);
SINGLE_ANIMATION(Wurmple);
SINGLE_ANIMATION(Silcoon);
SINGLE_ANIMATION(Beautifly);
SINGLE_ANIMATION(Cascoon);
SINGLE_ANIMATION(Dustox);
SINGLE_ANIMATION(Lotad);
SINGLE_ANIMATION(Lombre);
SINGLE_ANIMATION(Ludicolo);
SINGLE_ANIMATION(Seedot);
SINGLE_ANIMATION(Nuzleaf);
SINGLE_ANIMATION(Shiftry);
SINGLE_ANIMATION(Taillow);
SINGLE_ANIMATION(Swellow);
SINGLE_ANIMATION(Wingull);
SINGLE_ANIMATION(Pelipper);
SINGLE_ANIMATION(Ralts);
SINGLE_ANIMATION(Kirlia);
SINGLE_ANIMATION(Gardevoir);
SINGLE_ANIMATION(Gallade);
SINGLE_ANIMATION(Surskit);
SINGLE_ANIMATION(Masquerain);
SINGLE_ANIMATION(Slakoth);
SINGLE_ANIMATION(Vigoroth);
SINGLE_ANIMATION(Slaking);
SINGLE_ANIMATION(Nincada);
SINGLE_ANIMATION(Ninjask);
SINGLE_ANIMATION(Shedinja);
SINGLE_ANIMATION(Whismur);
SINGLE_ANIMATION(Loudred);
SINGLE_ANIMATION(Exploud);
SINGLE_ANIMATION(Makuhita);
SINGLE_ANIMATION(Hariyama);
SINGLE_ANIMATION(Nosepass);
SINGLE_ANIMATION(Probopass);
SINGLE_ANIMATION(Sableye);
SINGLE_ANIMATION(Mawile);
SINGLE_ANIMATION(Aron);
SINGLE_ANIMATION(Lairon);
SINGLE_ANIMATION(Aggron);
SINGLE_ANIMATION(Meditite);
SINGLE_ANIMATION(Medicham);
SINGLE_ANIMATION(Electrike);
SINGLE_ANIMATION(Manectric);
SINGLE_ANIMATION(Budew);
SINGLE_ANIMATION(Roselia);
SINGLE_ANIMATION(Roserade);
SINGLE_ANIMATION(Carvanha);
SINGLE_ANIMATION(Sharpedo);
SINGLE_ANIMATION(Wailmer);
SINGLE_ANIMATION(Wailord);
SINGLE_ANIMATION(Numel);
SINGLE_ANIMATION(Camerupt);
SINGLE_ANIMATION(Torkoal);
SINGLE_ANIMATION(Trapinch);
SINGLE_ANIMATION(Vibrava);
SINGLE_ANIMATION(Flygon);
SINGLE_ANIMATION(Cacnea);
SINGLE_ANIMATION(Cacturne);
SINGLE_ANIMATION(Swablu);
SINGLE_ANIMATION(Altaria);
SINGLE_ANIMATION(Baltoy);
SINGLE_ANIMATION(Claydol);
SINGLE_ANIMATION(Lileep);
SINGLE_ANIMATION(Cradily);
SINGLE_ANIMATION(Anorith);
SINGLE_ANIMATION(Armaldo);
SINGLE_ANIMATION(Feebas);
SINGLE_ANIMATION(Milotic);
SINGLE_ANIMATION(Castform);
SINGLE_ANIMATION(CastformSunny);
SINGLE_ANIMATION(CastformRainy);
SINGLE_ANIMATION(CastformSnowy);
SINGLE_ANIMATION(CastformSandy);
SINGLE_ANIMATION(Kecleon);
SINGLE_ANIMATION(Duskull);
SINGLE_ANIMATION(Dusclops);
SINGLE_ANIMATION(Dusknoir);
SINGLE_ANIMATION(Tropius);
SINGLE_ANIMATION(Chingling);
SINGLE_ANIMATION(Chimecho);
SINGLE_ANIMATION(Absol);
SINGLE_ANIMATION(Snorunt);
SINGLE_ANIMATION(Glalie);
SINGLE_ANIMATION(Froslass);
SINGLE_ANIMATION(Spheal);
SINGLE_ANIMATION(Sealeo);
SINGLE_ANIMATION(Walrein);
SINGLE_ANIMATION(Bagon);
SINGLE_ANIMATION(Shelgon);
SINGLE_ANIMATION(Salamence);
SINGLE_ANIMATION(Beldum);
SINGLE_ANIMATION(Metang);
SINGLE_ANIMATION(Metagross);
SINGLE_ANIMATION(Regirock);
SINGLE_ANIMATION(Regice);
SINGLE_ANIMATION(Registeel);
SINGLE_ANIMATION(Latias);
SINGLE_ANIMATION(Latios);
SINGLE_ANIMATION(Kyogre);
SINGLE_ANIMATION(Groudon);
SINGLE_ANIMATION(Rayquaza);
SINGLE_ANIMATION(DeoxysNormal);
SINGLE_ANIMATION(DeoxysAttack);
SINGLE_ANIMATION(DeoxysDefense);
SINGLE_ANIMATION(DeoxysSpeed);
SINGLE_ANIMATION(Turtwig);
SINGLE_ANIMATION(Grotle);
SINGLE_ANIMATION(Torterra);
SINGLE_ANIMATION(Chimchar);
SINGLE_ANIMATION(Monferno);
SINGLE_ANIMATION(Infernape);
SINGLE_ANIMATION(Piplup);
SINGLE_ANIMATION(Prinplup);
SINGLE_ANIMATION(Empoleon);
SINGLE_ANIMATION(Starly);
SINGLE_ANIMATION(Staravia);
SINGLE_ANIMATION(Staraptor);
SINGLE_ANIMATION(Bidoof);
SINGLE_ANIMATION(Bibarel);
SINGLE_ANIMATION(Kricketot);
SINGLE_ANIMATION(Kricketune);
SINGLE_ANIMATION(Shinx);
SINGLE_ANIMATION(Luxio);
SINGLE_ANIMATION(Luxray);
SINGLE_ANIMATION(Cranidos);
SINGLE_ANIMATION(Rampardos);
SINGLE_ANIMATION(Shieldon);
SINGLE_ANIMATION(Bastiodon);
SINGLE_ANIMATION(Combee);
SINGLE_ANIMATION(Vespiquen);
SINGLE_ANIMATION(Drifloon);
SINGLE_ANIMATION(Drifblim);
SINGLE_ANIMATION(Buneary);
SINGLE_ANIMATION(Lopunny);
SINGLE_ANIMATION(Gible);
SINGLE_ANIMATION(Gabite);
SINGLE_ANIMATION(Garchomp);
SINGLE_ANIMATION(Riolu);
SINGLE_ANIMATION(Lucario);
SINGLE_ANIMATION(Skorupi);
SINGLE_ANIMATION(Drapion);
SINGLE_ANIMATION(Croagunk);
SINGLE_ANIMATION(Toxicroak);
SINGLE_ANIMATION(Snover);
SINGLE_ANIMATION(Abomasnow);
SINGLE_ANIMATION(Rotom);
SINGLE_ANIMATION(RotomHeat);
SINGLE_ANIMATION(RotomWash);
SINGLE_ANIMATION(RotomFrost);
SINGLE_ANIMATION(RotomFan);
SINGLE_ANIMATION(RotomMow);
SINGLE_ANIMATION(Heatran);
SINGLE_ANIMATION(Regigigas);
SINGLE_ANIMATION(Yamask);
SINGLE_ANIMATION(Cofagrigus);
SINGLE_ANIMATION(Frillish);
SINGLE_ANIMATION(Jellicent);
SINGLE_ANIMATION(Joltik);
SINGLE_ANIMATION(Galvantula);
SINGLE_ANIMATION(Ferroseed);
SINGLE_ANIMATION(Ferrothorn);
SINGLE_ANIMATION(Litwick);
SINGLE_ANIMATION(Lampent);
SINGLE_ANIMATION(Chandelure);
SINGLE_ANIMATION(Axew);
SINGLE_ANIMATION(Fraxure);
SINGLE_ANIMATION(Haxorus);
SINGLE_ANIMATION(Cubchoo);
SINGLE_ANIMATION(Beartic);
SINGLE_ANIMATION(Pawniard);
SINGLE_ANIMATION(Bisharp);
SINGLE_ANIMATION(Deino);
SINGLE_ANIMATION(Zweilous);
SINGLE_ANIMATION(Hydreigon);
SINGLE_ANIMATION(Larvesta);
SINGLE_ANIMATION(Volcarona);
SINGLE_ANIMATION(Fennekin);
SINGLE_ANIMATION(Braixen);
SINGLE_ANIMATION(Delphox);
SINGLE_ANIMATION(Fletchling);
SINGLE_ANIMATION(Fletchinder);
SINGLE_ANIMATION(Talonflame);
SINGLE_ANIMATION(Tyrunt);
SINGLE_ANIMATION(Tyrantrum);
SINGLE_ANIMATION(Amaura);
SINGLE_ANIMATION(Aurorus);
SINGLE_ANIMATION(Rowlet);
SINGLE_ANIMATION(Dartrix);
SINGLE_ANIMATION(Decidueye);
SINGLE_ANIMATION(Jangmo_O);
SINGLE_ANIMATION(Hakamo_O);
SINGLE_ANIMATION(Kommo_O);
SINGLE_ANIMATION(Lunatone);
SINGLE_ANIMATION(Solrock);
SINGLE_ANIMATION(Rookidee);
SINGLE_ANIMATION(Corvisquire);
SINGLE_ANIMATION(Corviknight);
SINGLE_ANIMATION(Blipbug);
SINGLE_ANIMATION(Dottler);
SINGLE_ANIMATION(Orbeetle);
SINGLE_ANIMATION(Snom);
SINGLE_ANIMATION(Frosmoth);
SINGLE_ANIMATION(Dreepy);
SINGLE_ANIMATION(Drakloak);
SINGLE_ANIMATION(Dragapult);
SINGLE_ANIMATION(Egg);

static const union AnimCmd sAnim_BW_BULBASAUR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BULBASAUR);
static const union AnimCmd sAnimEspalda_BW_BULBASAUR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BULBASAUR);
static const union AnimCmd sAnim_BW_IVYSAUR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_IVYSAUR);
static const union AnimCmd sAnimEspalda_BW_IVYSAUR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_IVYSAUR);
static const union AnimCmd sAnim_BW_VENUSAUR[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 22),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VENUSAUR);
static const union AnimCmd sAnimEspalda_BW_VENUSAUR[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VENUSAUR);
static const union AnimCmd sAnim_BW_CHARMANDER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 72),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHARMANDER);
static const union AnimCmd sAnimEspalda_BW_CHARMANDER[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHARMANDER);
static const union AnimCmd sAnim_BW_CHARMELEON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 67),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHARMELEON);
static const union AnimCmd sAnimEspalda_BW_CHARMELEON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHARMELEON);
static const union AnimCmd sAnim_BW_CHARIZARD[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHARIZARD);
static const union AnimCmd sAnimEspalda_BW_CHARIZARD[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHARIZARD);
static const union AnimCmd sAnim_BW_SQUIRTLE[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 78),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SQUIRTLE);
static const union AnimCmd sAnimEspalda_BW_SQUIRTLE[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 53),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SQUIRTLE);
static const union AnimCmd sAnim_BW_WARTORTLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 67),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WARTORTLE);
static const union AnimCmd sAnimEspalda_BW_WARTORTLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WARTORTLE);
static const union AnimCmd sAnim_BW_BLASTOISE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 31),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BLASTOISE);
static const union AnimCmd sAnimEspalda_BW_BLASTOISE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BLASTOISE);
static const union AnimCmd sAnim_BW_CATERPIE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CATERPIE);
static const union AnimCmd sAnimEspalda_BW_CATERPIE[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CATERPIE);
static const union AnimCmd sAnim_BW_METAPOD[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_METAPOD);
static const union AnimCmd sAnimEspalda_BW_METAPOD[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_METAPOD);
static const union AnimCmd sAnim_BW_BUTTERFREE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BUTTERFREE);
static const union AnimCmd sAnimEspalda_BW_BUTTERFREE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BUTTERFREE);
static const union AnimCmd sAnim_BW_WEEDLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WEEDLE);
static const union AnimCmd sAnimEspalda_BW_WEEDLE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WEEDLE);
static const union AnimCmd sAnim_BW_KAKUNA[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 64),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(0, 64),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(3, 28),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(3, 28),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KAKUNA);
static const union AnimCmd sAnimEspalda_BW_KAKUNA[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 21),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KAKUNA);
static const union AnimCmd sAnim_BW_BEEDRILL[] =
{
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 1),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BEEDRILL);
static const union AnimCmd sAnimEspalda_BW_BEEDRILL[] =
{
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BEEDRILL);
static const union AnimCmd sAnim_BW_PIDGEY[] =
{
    POSE_DURANTE(0, 38),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 145),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PIDGEY);
static const union AnimCmd sAnimEspalda_BW_PIDGEY[] =
{
    POSE_DURANTE(0, 38),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PIDGEY);
static const union AnimCmd sAnim_BW_PIDGEOT[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PIDGEOT);
static const union AnimCmd sAnimEspalda_BW_PIDGEOT[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PIDGEOT);
static const union AnimCmd sAnim_BW_RATTATA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 11),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RATTATA);
static const union AnimCmd sAnimEspalda_BW_RATTATA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RATTATA);
static const union AnimCmd sAnim_BW_RATICATE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RATICATE);
static const union AnimCmd sAnimEspalda_BW_RATICATE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RATICATE);
static const union AnimCmd sAnim_BW_EKANS[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 37),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EKANS);
static const union AnimCmd sAnimEspalda_BW_EKANS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EKANS);
static const union AnimCmd sAnim_BW_ARBOK[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 19),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARBOK);
static const union AnimCmd sAnimEspalda_BW_ARBOK[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARBOK);
static const union AnimCmd sAnim_BW_PICHU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PICHU);
static const union AnimCmd sAnimEspalda_BW_PICHU[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PICHU);
static const union AnimCmd sAnim_BW_PIKACHU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PIKACHU);
static const union AnimCmd sAnimEspalda_BW_PIKACHU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PIKACHU);
static const union AnimCmd sAnim_BW_RAICHU[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RAICHU);
static const union AnimCmd sAnimEspalda_BW_RAICHU[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RAICHU);
static const union AnimCmd sAnim_BW_RAICHU_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RAICHU_ALOLA);
static const union AnimCmd sAnimEspalda_BW_RAICHU_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RAICHU_ALOLA);
static const union AnimCmd sAnim_BW_SANDSHREW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SANDSHREW);
static const union AnimCmd sAnimEspalda_BW_SANDSHREW[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SANDSHREW);
static const union AnimCmd sAnim_BW_SANDSLASH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SANDSLASH);
static const union AnimCmd sAnimEspalda_BW_SANDSLASH[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SANDSLASH);
static const union AnimCmd sAnim_BW_SANDSHREW_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SANDSHREW_ALOLA);
static const union AnimCmd sAnimEspalda_BW_SANDSHREW_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SANDSHREW_ALOLA);
static const union AnimCmd sAnim_BW_SANDSLASH_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SANDSLASH_ALOLA);
static const union AnimCmd sAnimEspalda_BW_SANDSLASH_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SANDSLASH_ALOLA);
static const union AnimCmd sAnim_BW_NIDORAN_F[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDORAN_F);
static const union AnimCmd sAnimEspalda_BW_NIDORAN_F[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDORAN_F);
static const union AnimCmd sAnim_BW_NIDORINA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDORINA);
static const union AnimCmd sAnimEspalda_BW_NIDORINA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDORINA);
static const union AnimCmd sAnim_BW_NIDOQUEEN[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDOQUEEN);
static const union AnimCmd sAnimEspalda_BW_NIDOQUEEN[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 48),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDOQUEEN);
static const union AnimCmd sAnim_BW_NIDORAN_M[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDORAN_M);
static const union AnimCmd sAnimEspalda_BW_NIDORAN_M[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDORAN_M);
static const union AnimCmd sAnim_BW_NIDORINO[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDORINO);
static const union AnimCmd sAnimEspalda_BW_NIDORINO[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDORINO);
static const union AnimCmd sAnim_BW_NIDOKING[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NIDOKING);
static const union AnimCmd sAnimEspalda_BW_NIDOKING[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NIDOKING);
static const union AnimCmd sAnim_BW_CLEFFA[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 34),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CLEFFA);
static const union AnimCmd sAnimEspalda_BW_CLEFFA[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 39),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 31),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CLEFFA);
static const union AnimCmd sAnim_BW_CLEFAIRY[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(0, 21),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CLEFAIRY);
static const union AnimCmd sAnimEspalda_BW_CLEFAIRY[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CLEFAIRY);
static const union AnimCmd sAnim_BW_CLEFABLE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CLEFABLE);
static const union AnimCmd sAnimEspalda_BW_CLEFABLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CLEFABLE);
static const union AnimCmd sAnim_BW_VULPIX[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 13),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VULPIX);
static const union AnimCmd sAnimEspalda_BW_VULPIX[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VULPIX);
static const union AnimCmd sAnim_BW_NINETALES[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NINETALES);
static const union AnimCmd sAnimEspalda_BW_NINETALES[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NINETALES);
static const union AnimCmd sAnim_BW_VULPIX_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VULPIX_ALOLA);
static const union AnimCmd sAnimEspalda_BW_VULPIX_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VULPIX_ALOLA);
static const union AnimCmd sAnim_BW_NINETALES_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NINETALES_ALOLA);
static const union AnimCmd sAnimEspalda_BW_NINETALES_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NINETALES_ALOLA);
static const union AnimCmd sAnim_BW_IGGLYBUFF[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 55),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_IGGLYBUFF);
static const union AnimCmd sAnimEspalda_BW_IGGLYBUFF[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_IGGLYBUFF);
static const union AnimCmd sAnim_BW_JIGGLYPUFF[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JIGGLYPUFF);
static const union AnimCmd sAnimEspalda_BW_JIGGLYPUFF[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JIGGLYPUFF);
static const union AnimCmd sAnim_BW_WIGGLYTUFF[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 33),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WIGGLYTUFF);
static const union AnimCmd sAnimEspalda_BW_WIGGLYTUFF[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WIGGLYTUFF);
static const union AnimCmd sAnim_BW_ZUBAT[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ZUBAT);
static const union AnimCmd sAnimEspalda_BW_ZUBAT[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ZUBAT);
static const union AnimCmd sAnim_BW_CROBAT[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CROBAT);
static const union AnimCmd sAnimEspalda_BW_CROBAT[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CROBAT);
static const union AnimCmd sAnim_BW_PARAS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PARAS);
static const union AnimCmd sAnimEspalda_BW_PARAS[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PARAS);
static const union AnimCmd sAnim_BW_PARASECT[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 31),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PARASECT);
static const union AnimCmd sAnimEspalda_BW_PARASECT[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PARASECT);
static const union AnimCmd sAnim_BW_MEOWTH[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEOWTH);
static const union AnimCmd sAnimEspalda_BW_MEOWTH[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEOWTH);
static const union AnimCmd sAnim_BW_PERSIAN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 78),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 78),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 78),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 78),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PERSIAN);
static const union AnimCmd sAnimEspalda_BW_PERSIAN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 72),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PERSIAN);
static const union AnimCmd sAnim_BW_PSYDUCK[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 110),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(2, 141),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PSYDUCK);
static const union AnimCmd sAnimEspalda_BW_PSYDUCK[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 140),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 111),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PSYDUCK);
static const union AnimCmd sAnim_BW_GOLDUCK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 19),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GOLDUCK);
static const union AnimCmd sAnimEspalda_BW_GOLDUCK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GOLDUCK);
static const union AnimCmd sAnim_BW_MANKEY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MANKEY);
static const union AnimCmd sAnimEspalda_BW_MANKEY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MANKEY);
static const union AnimCmd sAnim_BW_PRIMEAPE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PRIMEAPE);
static const union AnimCmd sAnimEspalda_BW_PRIMEAPE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PRIMEAPE);
static const union AnimCmd sAnim_BW_ANNIHILAPE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ANNIHILAPE);
static const union AnimCmd sAnimEspalda_BW_ANNIHILAPE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ANNIHILAPE);
static const union AnimCmd sAnim_BW_GROWLITHE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 23),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GROWLITHE);
static const union AnimCmd sAnimEspalda_BW_GROWLITHE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GROWLITHE);
static const union AnimCmd sAnim_BW_ARCANINE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARCANINE);
static const union AnimCmd sAnimEspalda_BW_ARCANINE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARCANINE);
static const union AnimCmd sAnim_BW_POLIWAG[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_POLIWAG);
static const union AnimCmd sAnimEspalda_BW_POLIWAG[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_POLIWAG);
static const union AnimCmd sAnim_BW_POLIWHIRL[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_POLIWHIRL);
static const union AnimCmd sAnimEspalda_BW_POLIWHIRL[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_POLIWHIRL);
static const union AnimCmd sAnim_BW_POLIWRATH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_POLIWRATH);
static const union AnimCmd sAnimEspalda_BW_POLIWRATH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_POLIWRATH);
static const union AnimCmd sAnim_BW_POLITOED[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_POLITOED);
static const union AnimCmd sAnimEspalda_BW_POLITOED[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_POLITOED);
static const union AnimCmd sAnim_BW_ABRA[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 84),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 84),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 84),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 37),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 61),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 31),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(4, 13),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ABRA);
static const union AnimCmd sAnimEspalda_BW_ABRA[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ABRA);
static const union AnimCmd sAnim_BW_KADABRA[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(3, 22),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KADABRA);
static const union AnimCmd sAnimEspalda_BW_KADABRA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KADABRA);
static const union AnimCmd sAnim_BW_ALAKAZAM[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 78),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ALAKAZAM);
static const union AnimCmd sAnimEspalda_BW_ALAKAZAM[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ALAKAZAM);
static const union AnimCmd sAnim_BW_MACHOP[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MACHOP);
static const union AnimCmd sAnimEspalda_BW_MACHOP[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MACHOP);
static const union AnimCmd sAnim_BW_MACHOKE[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 67),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 66),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 66),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(4, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MACHOKE);
static const union AnimCmd sAnimEspalda_BW_MACHOKE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 54),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MACHOKE);
static const union AnimCmd sAnim_BW_MACHAMP[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MACHAMP);
static const union AnimCmd sAnimEspalda_BW_MACHAMP[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MACHAMP);
static const union AnimCmd sAnim_BW_BELLSPROUT[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BELLSPROUT);
static const union AnimCmd sAnimEspalda_BW_BELLSPROUT[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BELLSPROUT);
static const union AnimCmd sAnim_BW_WEEPINBELL[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WEEPINBELL);
static const union AnimCmd sAnimEspalda_BW_WEEPINBELL[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WEEPINBELL);
static const union AnimCmd sAnim_BW_VICTREEBEL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VICTREEBEL);
static const union AnimCmd sAnimEspalda_BW_VICTREEBEL[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VICTREEBEL);
static const union AnimCmd sAnim_BW_TENTACOOL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 37),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 42),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TENTACOOL);
static const union AnimCmd sAnimEspalda_BW_TENTACOOL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TENTACOOL);
static const union AnimCmd sAnim_BW_TENTACRUEL[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 22),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TENTACRUEL);
static const union AnimCmd sAnimEspalda_BW_TENTACRUEL[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TENTACRUEL);
static const union AnimCmd sAnim_BW_GEODUDE[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GEODUDE);
static const union AnimCmd sAnimEspalda_BW_GEODUDE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GEODUDE);
static const union AnimCmd sAnim_BW_GRAVELER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GRAVELER);
static const union AnimCmd sAnimEspalda_BW_GRAVELER[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GRAVELER);
static const union AnimCmd sAnim_BW_GOLEM[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GOLEM);
static const union AnimCmd sAnimEspalda_BW_GOLEM[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GOLEM);
static const union AnimCmd sAnim_BW_PONYTA[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PONYTA);
static const union AnimCmd sAnimEspalda_BW_PONYTA[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 22),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PONYTA);
static const union AnimCmd sAnim_BW_RAPIDASH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 26),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 22),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 22),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 26),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 23),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 1),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RAPIDASH);
static const union AnimCmd sAnimEspalda_BW_RAPIDASH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RAPIDASH);
static const union AnimCmd sAnim_BW_MAGNEMITE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 84),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 84),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 84),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 84),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGNEMITE);
static const union AnimCmd sAnimEspalda_BW_MAGNEMITE[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGNEMITE);
static const union AnimCmd sAnim_BW_MAGNETON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 23),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGNETON);
static const union AnimCmd sAnimEspalda_BW_MAGNETON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGNETON);
static const union AnimCmd sAnim_BW_MAGNEZONE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGNEZONE);
static const union AnimCmd sAnimEspalda_BW_MAGNEZONE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGNEZONE);
static const union AnimCmd sAnim_BW_GRIMER[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GRIMER);
static const union AnimCmd sAnimEspalda_BW_GRIMER[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GRIMER);
static const union AnimCmd sAnim_BW_MUK[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MUK);
static const union AnimCmd sAnimEspalda_BW_MUK[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MUK);
static const union AnimCmd sAnim_BW_SHELLDER[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(4, 31),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHELLDER);
static const union AnimCmd sAnimEspalda_BW_SHELLDER[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHELLDER);
static const union AnimCmd sAnim_BW_CLOYSTER[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CLOYSTER);
static const union AnimCmd sAnimEspalda_BW_CLOYSTER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CLOYSTER);
static const union AnimCmd sAnim_BW_GASTLY[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 11),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 11),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GASTLY);
static const union AnimCmd sAnimEspalda_BW_GASTLY[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GASTLY);
static const union AnimCmd sAnim_BW_HAUNTER[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HAUNTER);
static const union AnimCmd sAnimEspalda_BW_HAUNTER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HAUNTER);
static const union AnimCmd sAnim_BW_GENGAR[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 32),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GENGAR);
static const union AnimCmd sAnimEspalda_BW_GENGAR[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GENGAR);
static const union AnimCmd sAnim_BW_STEELIX[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 43),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(4, 29),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STEELIX);
static const union AnimCmd sAnimEspalda_BW_STEELIX[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STEELIX);
static const union AnimCmd sAnim_BW_DROWZEE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 42),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DROWZEE);
static const union AnimCmd sAnimEspalda_BW_DROWZEE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DROWZEE);
static const union AnimCmd sAnim_BW_HYPNO[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 54),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HYPNO);
static const union AnimCmd sAnimEspalda_BW_HYPNO[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HYPNO);
static const union AnimCmd sAnim_BW_KRABBY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KRABBY);
static const union AnimCmd sAnimEspalda_BW_KRABBY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KRABBY);
static const union AnimCmd sAnim_BW_KINGLER[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KINGLER);
static const union AnimCmd sAnimEspalda_BW_KINGLER[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KINGLER);
static const union AnimCmd sAnim_BW_EXEGGCUTE[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EXEGGCUTE);
static const union AnimCmd sAnimEspalda_BW_EXEGGCUTE[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EXEGGCUTE);
static const union AnimCmd sAnim_BW_EXEGGUTOR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EXEGGUTOR);
static const union AnimCmd sAnimEspalda_BW_EXEGGUTOR[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EXEGGUTOR);
static const union AnimCmd sAnim_BW_CUBONE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CUBONE);
static const union AnimCmd sAnimEspalda_BW_CUBONE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CUBONE);
static const union AnimCmd sAnim_BW_MAROWAK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAROWAK);
static const union AnimCmd sAnimEspalda_BW_MAROWAK[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAROWAK);
static const union AnimCmd sAnim_BW_MAROWAK_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAROWAK_ALOLA);
static const union AnimCmd sAnimEspalda_BW_MAROWAK_ALOLA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAROWAK_ALOLA);
static const union AnimCmd sAnim_BW_TYROGUE[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TYROGUE);
static const union AnimCmd sAnimEspalda_BW_TYROGUE[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TYROGUE);
static const union AnimCmd sAnim_BW_HITMONLEE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(3, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HITMONLEE);
static const union AnimCmd sAnimEspalda_BW_HITMONLEE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 39),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HITMONLEE);
static const union AnimCmd sAnim_BW_HITMONCHAN[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HITMONCHAN);
static const union AnimCmd sAnimEspalda_BW_HITMONCHAN[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HITMONCHAN);
static const union AnimCmd sAnim_BW_HITMONTOP[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HITMONTOP);
static const union AnimCmd sAnimEspalda_BW_HITMONTOP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HITMONTOP);
static const union AnimCmd sAnim_BW_LICKITUNG[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 33),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LICKITUNG);
static const union AnimCmd sAnimEspalda_BW_LICKITUNG[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LICKITUNG);
static const union AnimCmd sAnim_BW_LICKILICKY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LICKILICKY);
static const union AnimCmd sAnimEspalda_BW_LICKILICKY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LICKILICKY);
static const union AnimCmd sAnim_BW_KOFFING[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KOFFING);
static const union AnimCmd sAnimEspalda_BW_KOFFING[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KOFFING);
static const union AnimCmd sAnim_BW_WEEZING[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WEEZING);
static const union AnimCmd sAnimEspalda_BW_WEEZING[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WEEZING);
static const union AnimCmd sAnim_BW_WEEZING_GALAR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WEEZING_GALAR);
static const union AnimCmd sAnimEspalda_BW_WEEZING_GALAR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WEEZING_GALAR);
static const union AnimCmd sAnim_BW_RHYHORN[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RHYHORN);
static const union AnimCmd sAnimEspalda_BW_RHYHORN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RHYHORN);
static const union AnimCmd sAnim_BW_RHYDON[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 43),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 78),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RHYDON);
static const union AnimCmd sAnimEspalda_BW_RHYDON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 54),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RHYDON);
static const union AnimCmd sAnim_BW_RHYPERIOR[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RHYPERIOR);
static const union AnimCmd sAnimEspalda_BW_RHYPERIOR[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RHYPERIOR);
static const union AnimCmd sAnim_BW_TANGELA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TANGELA);
static const union AnimCmd sAnimEspalda_BW_TANGELA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TANGELA);
static const union AnimCmd sAnim_BW_TANGROWTH[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TANGROWTH);
static const union AnimCmd sAnimEspalda_BW_TANGROWTH[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TANGROWTH);
static const union AnimCmd sAnim_BW_KANGASKHAN[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KANGASKHAN);
static const union AnimCmd sAnimEspalda_BW_KANGASKHAN[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KANGASKHAN);
static const union AnimCmd sAnim_BW_HORSEA[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(4, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HORSEA);
static const union AnimCmd sAnimEspalda_BW_HORSEA[] =
{
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HORSEA);
static const union AnimCmd sAnim_BW_SEADRA[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SEADRA);
static const union AnimCmd sAnimEspalda_BW_SEADRA[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 27),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SEADRA);
static const union AnimCmd sAnim_BW_KINGDRA[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KINGDRA);
static const union AnimCmd sAnimEspalda_BW_KINGDRA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KINGDRA);
static const union AnimCmd sAnim_BW_GOLDEEN[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 39),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 39),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 39),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 33),
    POSE_DURANTE(3, 19),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GOLDEEN);
static const union AnimCmd sAnimEspalda_BW_GOLDEEN[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GOLDEEN);
static const union AnimCmd sAnim_BW_SEAKING[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(1, 26),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SEAKING);
static const union AnimCmd sAnimEspalda_BW_SEAKING[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 38),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(2, 38),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SEAKING);
static const union AnimCmd sAnim_BW_STARYU[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STARYU);
static const union AnimCmd sAnimEspalda_BW_STARYU[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STARYU);
static const union AnimCmd sAnim_BW_STARMIE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STARMIE);
static const union AnimCmd sAnimEspalda_BW_STARMIE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 9),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STARMIE);
static const union AnimCmd sAnim_BW_MIME_JR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MIME_JR);
static const union AnimCmd sAnimEspalda_BW_MIME_JR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MIME_JR);
static const union AnimCmd sAnim_BW_MR_MIME[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MR_MIME);
static const union AnimCmd sAnimEspalda_BW_MR_MIME[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MR_MIME);
static const union AnimCmd sAnim_BW_SCYTHER[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 31),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SCYTHER);
static const union AnimCmd sAnimEspalda_BW_SCYTHER[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SCYTHER);
static const union AnimCmd sAnim_BW_SCIZOR[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SCIZOR);
static const union AnimCmd sAnimEspalda_BW_SCIZOR[] =
{
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 11),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SCIZOR);
static const union AnimCmd sAnim_BW_KLEAVOR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KLEAVOR);
static const union AnimCmd sAnimEspalda_BW_KLEAVOR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KLEAVOR);
static const union AnimCmd sAnim_BW_SMOOCHUM[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SMOOCHUM);
static const union AnimCmd sAnimEspalda_BW_SMOOCHUM[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SMOOCHUM);
static const union AnimCmd sAnim_BW_JYNX[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JYNX);
static const union AnimCmd sAnimEspalda_BW_JYNX[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JYNX);
static const union AnimCmd sAnim_BW_ELEKID[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ELEKID);
static const union AnimCmd sAnimEspalda_BW_ELEKID[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ELEKID);
static const union AnimCmd sAnim_BW_ELECTABUZZ[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ELECTABUZZ);
static const union AnimCmd sAnimEspalda_BW_ELECTABUZZ[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ELECTABUZZ);
static const union AnimCmd sAnim_BW_MAGBY[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGBY);
static const union AnimCmd sAnimEspalda_BW_MAGBY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 64),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGBY);
static const union AnimCmd sAnim_BW_MAGMAR[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 23),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGMAR);
static const union AnimCmd sAnimEspalda_BW_MAGMAR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGMAR);
static const union AnimCmd sAnim_BW_MAGMORTAR[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGMORTAR);
static const union AnimCmd sAnimEspalda_BW_MAGMORTAR[] =
{
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGMORTAR);
static const union AnimCmd sAnim_BW_PINSIR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PINSIR);
static const union AnimCmd sAnimEspalda_BW_PINSIR[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PINSIR);
static const union AnimCmd sAnim_BW_TAUROS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(3, 2),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TAUROS);
static const union AnimCmd sAnimEspalda_BW_TAUROS[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TAUROS);
static const union AnimCmd sAnim_BW_MAGIKARP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGIKARP);
static const union AnimCmd sAnimEspalda_BW_MAGIKARP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGIKARP);
static const union AnimCmd sAnim_BW_LAPRAS[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(2, 35),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LAPRAS);
static const union AnimCmd sAnimEspalda_BW_LAPRAS[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LAPRAS);
static const union AnimCmd sAnim_BW_EEVEE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EEVEE);
static const union AnimCmd sAnimEspalda_BW_EEVEE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EEVEE);
static const union AnimCmd sAnim_BW_VAPOREON[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 27),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 55),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 27),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 27),
    POSE_DURANTE(1, 27),
    POSE_DURANTE(0, 45),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(4, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VAPOREON);
static const union AnimCmd sAnimEspalda_BW_VAPOREON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 45),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(1, 45),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 45),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 9),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VAPOREON);
static const union AnimCmd sAnim_BW_JOLTEON[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JOLTEON);
static const union AnimCmd sAnimEspalda_BW_JOLTEON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JOLTEON);
static const union AnimCmd sAnim_BW_FLAREON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FLAREON);
static const union AnimCmd sAnimEspalda_BW_FLAREON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FLAREON);
static const union AnimCmd sAnim_BW_ESPEON[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ESPEON);
static const union AnimCmd sAnimEspalda_BW_ESPEON[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 35),
    POSE_DURANTE(2, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ESPEON);
static const union AnimCmd sAnim_BW_UMBREON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_UMBREON);
static const union AnimCmd sAnimEspalda_BW_UMBREON[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_UMBREON);
static const union AnimCmd sAnim_BW_LEAFEON[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(0, 40),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LEAFEON);
static const union AnimCmd sAnimEspalda_BW_LEAFEON[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LEAFEON);
static const union AnimCmd sAnim_BW_GLACEON[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 66),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GLACEON);
static const union AnimCmd sAnimEspalda_BW_GLACEON[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GLACEON);
static const union AnimCmd sAnim_BW_SYLVEON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SYLVEON);
static const union AnimCmd sAnimEspalda_BW_SYLVEON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SYLVEON);
static const union AnimCmd sAnim_BW_PORYGON[] =
{
    POSE_DURANTE(0, 26),
    POSE_DURANTE(2, 34),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 54),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 22),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 22),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PORYGON);
static const union AnimCmd sAnimEspalda_BW_PORYGON[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 55),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PORYGON);
static const union AnimCmd sAnim_BW_PORYGON2[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 33),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 32),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(4, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PORYGON2);
static const union AnimCmd sAnimEspalda_BW_PORYGON2[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PORYGON2);
static const union AnimCmd sAnim_BW_PORYGON_Z[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PORYGON_Z);
static const union AnimCmd sAnimEspalda_BW_PORYGON_Z[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PORYGON_Z);
static const union AnimCmd sAnim_BW_OMANYTE[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_OMANYTE);
static const union AnimCmd sAnimEspalda_BW_OMANYTE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_OMANYTE);
static const union AnimCmd sAnim_BW_OMASTAR[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 43),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 61),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_OMASTAR);
static const union AnimCmd sAnimEspalda_BW_OMASTAR[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 54),
    POSE_DURANTE(2, 54),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_OMASTAR);
static const union AnimCmd sAnim_BW_KABUTO[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 19),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KABUTO);
static const union AnimCmd sAnimEspalda_BW_KABUTO[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KABUTO);
static const union AnimCmd sAnim_BW_KABUTOPS[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KABUTOPS);
static const union AnimCmd sAnimEspalda_BW_KABUTOPS[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KABUTOPS);
static const union AnimCmd sAnim_BW_MUNCHLAX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MUNCHLAX);
static const union AnimCmd sAnimEspalda_BW_MUNCHLAX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MUNCHLAX);
static const union AnimCmd sAnim_BW_SNORLAX[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNORLAX);
static const union AnimCmd sAnimEspalda_BW_SNORLAX[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNORLAX);
static const union AnimCmd sAnim_BW_ARTICUNO[] =
{
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 71),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 70),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 70),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 71),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 46),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 66),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(3, 11),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARTICUNO);
static const union AnimCmd sAnimEspalda_BW_ARTICUNO[] =
{
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 77),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARTICUNO);
static const union AnimCmd sAnim_BW_DRATINI[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 19),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRATINI);
static const union AnimCmd sAnimEspalda_BW_DRATINI[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRATINI);
static const union AnimCmd sAnim_BW_DRAGONAIR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRAGONAIR);
static const union AnimCmd sAnimEspalda_BW_DRAGONAIR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRAGONAIR);
static const union AnimCmd sAnim_BW_DRAGONITE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(1, 39),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRAGONITE);
static const union AnimCmd sAnimEspalda_BW_DRAGONITE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRAGONITE);
static const union AnimCmd sAnim_BW_MEW[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEW);
static const union AnimCmd sAnimEspalda_BW_MEW[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEW);
static const union AnimCmd sAnim_BW_MEWTWO[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 42),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEWTWO);
static const union AnimCmd sAnimEspalda_BW_MEWTWO[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEWTWO);
static const union AnimCmd sAnim_BW_CHIKORITA[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHIKORITA);
static const union AnimCmd sAnimEspalda_BW_CHIKORITA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHIKORITA);
static const union AnimCmd sAnim_BW_BAYLEEF[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 79),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 90),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BAYLEEF);
static const union AnimCmd sAnimEspalda_BW_BAYLEEF[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BAYLEEF);
static const union AnimCmd sAnim_BW_MEGANIUM[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 64),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEGANIUM);
static const union AnimCmd sAnimEspalda_BW_MEGANIUM[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEGANIUM);
static const union AnimCmd sAnim_BW_CYNDAQUIL[] =
{
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CYNDAQUIL);
static const union AnimCmd sAnimEspalda_BW_CYNDAQUIL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CYNDAQUIL);
static const union AnimCmd sAnim_BW_QUILAVA[] =
{
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_QUILAVA);
static const union AnimCmd sAnimEspalda_BW_QUILAVA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_QUILAVA);
static const union AnimCmd sAnim_BW_TYPHLOSION[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 57),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TYPHLOSION);
static const union AnimCmd sAnimEspalda_BW_TYPHLOSION[] =
{
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TYPHLOSION);
static const union AnimCmd sAnim_BW_TOTODILE[] =
{
    POSE_DURANTE(0, 62),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 56),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 57),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TOTODILE);
static const union AnimCmd sAnimEspalda_BW_TOTODILE[] =
{
    POSE_DURANTE(0, 22),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TOTODILE);
static const union AnimCmd sAnim_BW_CROCONAW[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CROCONAW);
static const union AnimCmd sAnimEspalda_BW_CROCONAW[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CROCONAW);
static const union AnimCmd sAnim_BW_FERALIGATR[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FERALIGATR);
static const union AnimCmd sAnimEspalda_BW_FERALIGATR[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FERALIGATR);
static const union AnimCmd sAnim_BW_SENTRET[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 13),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 42),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SENTRET);
static const union AnimCmd sAnimEspalda_BW_SENTRET[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SENTRET);
static const union AnimCmd sAnim_BW_FURRET[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FURRET);
static const union AnimCmd sAnimEspalda_BW_FURRET[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FURRET);
static const union AnimCmd sAnim_BW_HOOTHOOT[] =
{
    POSE_DURANTE(0, 27),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(0, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HOOTHOOT);
static const union AnimCmd sAnimEspalda_BW_HOOTHOOT[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 39),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HOOTHOOT);
static const union AnimCmd sAnim_BW_NOCTOWL[] =
{
    POSE_DURANTE(0, 78),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 85),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 84),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NOCTOWL);
static const union AnimCmd sAnimEspalda_BW_NOCTOWL[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 181),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NOCTOWL);
static const union AnimCmd sAnim_BW_LEDYBA[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LEDYBA);
static const union AnimCmd sAnimEspalda_BW_LEDYBA[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LEDYBA);
static const union AnimCmd sAnim_BW_LEDIAN[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LEDIAN);
static const union AnimCmd sAnimEspalda_BW_LEDIAN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LEDIAN);
static const union AnimCmd sAnim_BW_SPINARAK[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 34),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SPINARAK);
static const union AnimCmd sAnimEspalda_BW_SPINARAK[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SPINARAK);
static const union AnimCmd sAnim_BW_ARIADOS[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARIADOS);
static const union AnimCmd sAnimEspalda_BW_ARIADOS[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARIADOS);
static const union AnimCmd sAnim_BW_CHINCHOU[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHINCHOU);
static const union AnimCmd sAnimEspalda_BW_CHINCHOU[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHINCHOU);
static const union AnimCmd sAnim_BW_LANTURN[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LANTURN);
static const union AnimCmd sAnimEspalda_BW_LANTURN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LANTURN);
static const union AnimCmd sAnim_BW_TOGEPI[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 61),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 54),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TOGEPI);
static const union AnimCmd sAnimEspalda_BW_TOGEPI[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TOGEPI);
static const union AnimCmd sAnim_BW_TOGETIC[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TOGETIC);
static const union AnimCmd sAnimEspalda_BW_TOGETIC[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TOGETIC);
static const union AnimCmd sAnim_BW_TOGEKISS[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 13),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TOGEKISS);
static const union AnimCmd sAnimEspalda_BW_TOGEKISS[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TOGEKISS);
static const union AnimCmd sAnim_BW_NATU[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NATU);
static const union AnimCmd sAnimEspalda_BW_NATU[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NATU);
static const union AnimCmd sAnim_BW_XATU[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_XATU);
static const union AnimCmd sAnimEspalda_BW_XATU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_XATU);
static const union AnimCmd sAnim_BW_MAREEP[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAREEP);
static const union AnimCmd sAnimEspalda_BW_MAREEP[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAREEP);
static const union AnimCmd sAnim_BW_FLAAFFY[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FLAAFFY);
static const union AnimCmd sAnimEspalda_BW_FLAAFFY[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FLAAFFY);
static const union AnimCmd sAnim_BW_AMPHAROS[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 13),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AMPHAROS);
static const union AnimCmd sAnimEspalda_BW_AMPHAROS[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AMPHAROS);
static const union AnimCmd sAnim_BW_AZURILL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 29),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AZURILL);
static const union AnimCmd sAnimEspalda_BW_AZURILL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AZURILL);
static const union AnimCmd sAnim_BW_MARILL[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 90),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 102),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MARILL);
static const union AnimCmd sAnimEspalda_BW_MARILL[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MARILL);
static const union AnimCmd sAnim_BW_AZUMARILL[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 50),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AZUMARILL);
static const union AnimCmd sAnimEspalda_BW_AZUMARILL[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AZUMARILL);
static const union AnimCmd sAnim_BW_BONSLY[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(0, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BONSLY);
static const union AnimCmd sAnimEspalda_BW_BONSLY[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BONSLY);
static const union AnimCmd sAnim_BW_SUDOWOODO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 22),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 27),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 34),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 29),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SUDOWOODO);
static const union AnimCmd sAnimEspalda_BW_SUDOWOODO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SUDOWOODO);
static const union AnimCmd sAnim_BW_HOPPIP[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 63),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 37),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HOPPIP);
static const union AnimCmd sAnimEspalda_BW_HOPPIP[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HOPPIP);
static const union AnimCmd sAnim_BW_SKIPLOOM[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SKIPLOOM);
static const union AnimCmd sAnimEspalda_BW_SKIPLOOM[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SKIPLOOM);
static const union AnimCmd sAnim_BW_JUMPLUFF[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JUMPLUFF);
static const union AnimCmd sAnimEspalda_BW_JUMPLUFF[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JUMPLUFF);
static const union AnimCmd sAnim_BW_AIPOM[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AIPOM);
static const union AnimCmd sAnimEspalda_BW_AIPOM[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AIPOM);
static const union AnimCmd sAnim_BW_AMBIPOM[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AMBIPOM);
static const union AnimCmd sAnimEspalda_BW_AMBIPOM[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AMBIPOM);
static const union AnimCmd sAnim_BW_SUNKERN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SUNKERN);
static const union AnimCmd sAnimEspalda_BW_SUNKERN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SUNKERN);
static const union AnimCmd sAnim_BW_SUNFLORA[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 13),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SUNFLORA);
static const union AnimCmd sAnimEspalda_BW_SUNFLORA[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SUNFLORA);
static const union AnimCmd sAnim_BW_YANMA[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 39),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 26),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 38),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 27),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_YANMA);
static const union AnimCmd sAnimEspalda_BW_YANMA[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_YANMA);
static const union AnimCmd sAnim_BW_YANMEGA[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 62),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 1),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 19),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_YANMEGA);
static const union AnimCmd sAnimEspalda_BW_YANMEGA[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 41),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 19),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_YANMEGA);
static const union AnimCmd sAnim_BW_MURKROW[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MURKROW);
static const union AnimCmd sAnimEspalda_BW_MURKROW[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MURKROW);
static const union AnimCmd sAnim_BW_HONCHKROW[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 43),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 56),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 70),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HONCHKROW);
static const union AnimCmd sAnimEspalda_BW_HONCHKROW[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HONCHKROW);
static const union AnimCmd sAnim_BW_MISDREAVUS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MISDREAVUS);
static const union AnimCmd sAnimEspalda_BW_MISDREAVUS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MISDREAVUS);
static const union AnimCmd sAnim_BW_MISMAGIUS[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MISMAGIUS);
static const union AnimCmd sAnimEspalda_BW_MISMAGIUS[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MISMAGIUS);
static const union AnimCmd sAnim_BW_GIRAFARIG[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(1, 45),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GIRAFARIG);
static const union AnimCmd sAnimEspalda_BW_GIRAFARIG[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GIRAFARIG);
static const union AnimCmd sAnim_BW_GLIGAR[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(1, 26),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GLIGAR);
static const union AnimCmd sAnimEspalda_BW_GLIGAR[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GLIGAR);
static const union AnimCmd sAnim_BW_GLISCOR[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GLISCOR);
static const union AnimCmd sAnimEspalda_BW_GLISCOR[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GLISCOR);
static const union AnimCmd sAnim_BW_SNUBBULL[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 45),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 46),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 45),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(0, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNUBBULL);
static const union AnimCmd sAnimEspalda_BW_SNUBBULL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNUBBULL);
static const union AnimCmd sAnim_BW_GRANBULL[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GRANBULL);
static const union AnimCmd sAnimEspalda_BW_GRANBULL[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GRANBULL);
static const union AnimCmd sAnim_BW_HERACROSS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HERACROSS);
static const union AnimCmd sAnimEspalda_BW_HERACROSS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HERACROSS);
static const union AnimCmd sAnim_BW_SNEASEL[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNEASEL);
static const union AnimCmd sAnimEspalda_BW_SNEASEL[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNEASEL);
static const union AnimCmd sAnim_BW_WEAVILE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WEAVILE);
static const union AnimCmd sAnimEspalda_BW_WEAVILE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WEAVILE);
static const union AnimCmd sAnim_BW_SNEASLER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNEASLER);
static const union AnimCmd sAnimEspalda_BW_SNEASLER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNEASLER);
static const union AnimCmd sAnim_BW_TEDDIURSA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TEDDIURSA);
static const union AnimCmd sAnimEspalda_BW_TEDDIURSA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TEDDIURSA);
static const union AnimCmd sAnim_BW_URSARING[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 54),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_URSARING);
static const union AnimCmd sAnimEspalda_BW_URSARING[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_URSARING);
static const union AnimCmd sAnim_BW_SLUGMA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(4, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SLUGMA);
static const union AnimCmd sAnimEspalda_BW_SLUGMA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SLUGMA);
static const union AnimCmd sAnim_BW_MAGCARGO[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(4, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAGCARGO);
static const union AnimCmd sAnimEspalda_BW_MAGCARGO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAGCARGO);
static const union AnimCmd sAnim_BW_SWINUB[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SWINUB);
static const union AnimCmd sAnimEspalda_BW_SWINUB[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SWINUB);
static const union AnimCmd sAnim_BW_PILOSWINE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PILOSWINE);
static const union AnimCmd sAnimEspalda_BW_PILOSWINE[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PILOSWINE);
static const union AnimCmd sAnim_BW_MAMOSWINE[] =
{
    POSE_DURANTE(0, 40),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 43),
    POSE_DURANTE(3, 27),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(0, 69),
    POSE_DURANTE(3, 27),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(4, 27),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAMOSWINE);
static const union AnimCmd sAnimEspalda_BW_MAMOSWINE[] =
{
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAMOSWINE);
static const union AnimCmd sAnim_BW_DELIBIRD[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DELIBIRD);
static const union AnimCmd sAnimEspalda_BW_DELIBIRD[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DELIBIRD);
static const union AnimCmd sAnim_BW_HOUNDOUR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 44),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HOUNDOUR);
static const union AnimCmd sAnimEspalda_BW_HOUNDOUR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HOUNDOUR);
static const union AnimCmd sAnim_BW_HOUNDOOM[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HOUNDOOM);
static const union AnimCmd sAnimEspalda_BW_HOUNDOOM[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HOUNDOOM);
static const union AnimCmd sAnim_BW_PHANPY[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 38),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 38),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PHANPY);
static const union AnimCmd sAnimEspalda_BW_PHANPY[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PHANPY);
static const union AnimCmd sAnim_BW_DONPHAN[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 61),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 54),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DONPHAN);
static const union AnimCmd sAnimEspalda_BW_DONPHAN[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 66),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DONPHAN);
static const union AnimCmd sAnim_BW_STANTLER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STANTLER);
static const union AnimCmd sAnimEspalda_BW_STANTLER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STANTLER);
static const union AnimCmd sAnim_BW_WYRDEER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WYRDEER);
static const union AnimCmd sAnimEspalda_BW_WYRDEER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WYRDEER);
static const union AnimCmd sAnim_BW_RAIKOU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RAIKOU);
static const union AnimCmd sAnimEspalda_BW_RAIKOU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RAIKOU);
static const union AnimCmd sAnim_BW_ENTEI[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 32),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ENTEI);
static const union AnimCmd sAnimEspalda_BW_ENTEI[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ENTEI);
static const union AnimCmd sAnim_BW_SUICUNE[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SUICUNE);
static const union AnimCmd sAnimEspalda_BW_SUICUNE[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SUICUNE);
static const union AnimCmd sAnim_BW_LARVITAR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 22),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LARVITAR);
static const union AnimCmd sAnimEspalda_BW_LARVITAR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LARVITAR);
static const union AnimCmd sAnim_BW_PUPITAR[] =
{
    POSE_DURANTE(0, 29),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(0, 34),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 23),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 85),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PUPITAR);
static const union AnimCmd sAnimEspalda_BW_PUPITAR[] =
{
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 23),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PUPITAR);
static const union AnimCmd sAnim_BW_TYRANITAR[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(1, 41),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TYRANITAR);
static const union AnimCmd sAnimEspalda_BW_TYRANITAR[] =
{
    POSE_DURANTE(0, 56),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 41),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TYRANITAR);
static const union AnimCmd sAnim_BW_CELEBI[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CELEBI);
static const union AnimCmd sAnimEspalda_BW_CELEBI[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CELEBI);
static const union AnimCmd sAnim_BW_TREECKO[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 57),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 44),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TREECKO);
static const union AnimCmd sAnimEspalda_BW_TREECKO[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TREECKO);
static const union AnimCmd sAnim_BW_GROVYLE[] =
{
    POSE_DURANTE(0, 44),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 64),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 64),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 61),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GROVYLE);
static const union AnimCmd sAnimEspalda_BW_GROVYLE[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 44),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GROVYLE);
static const union AnimCmd sAnim_BW_SCEPTILE[] =
{
    POSE_DURANTE(0, 66),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 91),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 90),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 90),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 97),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SCEPTILE);
static const union AnimCmd sAnimEspalda_BW_SCEPTILE[] =
{
    POSE_DURANTE(0, 66),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SCEPTILE);
static const union AnimCmd sAnim_BW_TORCHIC[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TORCHIC);
static const union AnimCmd sAnimEspalda_BW_TORCHIC[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TORCHIC);
static const union AnimCmd sAnim_BW_COMBUSKEN[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_COMBUSKEN);
static const union AnimCmd sAnimEspalda_BW_COMBUSKEN[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_COMBUSKEN);
static const union AnimCmd sAnim_BW_BLAZIKEN[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 15),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BLAZIKEN);
static const union AnimCmd sAnimEspalda_BW_BLAZIKEN[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BLAZIKEN);
static const union AnimCmd sAnim_BW_MUDKIP[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 123),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MUDKIP);
static const union AnimCmd sAnimEspalda_BW_MUDKIP[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 45),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MUDKIP);
static const union AnimCmd sAnim_BW_MARSHTOMP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(0, 55),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MARSHTOMP);
static const union AnimCmd sAnimEspalda_BW_MARSHTOMP[] =
{
    POSE_DURANTE(0, 23),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MARSHTOMP);
static const union AnimCmd sAnim_BW_SWAMPERT[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 119),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SWAMPERT);
static const union AnimCmd sAnimEspalda_BW_SWAMPERT[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 70),
    POSE_DURANTE(2, 28),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SWAMPERT);
static const union AnimCmd sAnim_BW_POOCHYENA[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 44),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 44),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(1, 31),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_POOCHYENA);
static const union AnimCmd sAnimEspalda_BW_POOCHYENA[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_POOCHYENA);
static const union AnimCmd sAnim_BW_MIGHTYENA[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MIGHTYENA);
static const union AnimCmd sAnimEspalda_BW_MIGHTYENA[] =
{
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MIGHTYENA);
static const union AnimCmd sAnim_BW_WURMPLE[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WURMPLE);
static const union AnimCmd sAnimEspalda_BW_WURMPLE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WURMPLE);
static const union AnimCmd sAnim_BW_SILCOON[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SILCOON);
static const union AnimCmd sAnimEspalda_BW_SILCOON[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SILCOON);
static const union AnimCmd sAnim_BW_BEAUTIFLY[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 9),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BEAUTIFLY);
static const union AnimCmd sAnimEspalda_BW_BEAUTIFLY[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 9),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BEAUTIFLY);
static const union AnimCmd sAnim_BW_CASCOON[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 26),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CASCOON);
static const union AnimCmd sAnimEspalda_BW_CASCOON[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CASCOON);
static const union AnimCmd sAnim_BW_DUSTOX[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DUSTOX);
static const union AnimCmd sAnimEspalda_BW_DUSTOX[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(1, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DUSTOX);
static const union AnimCmd sAnim_BW_LOTAD[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 64),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 49),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 48),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 80),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(2, 41),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LOTAD);
static const union AnimCmd sAnimEspalda_BW_LOTAD[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 72),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LOTAD);
static const union AnimCmd sAnim_BW_LOMBRE[] =
{
    POSE_DURANTE(0, 50),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 82),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 82),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 82),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 77),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LOMBRE);
static const union AnimCmd sAnimEspalda_BW_LOMBRE[] =
{
    POSE_DURANTE(0, 50),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LOMBRE);
static const union AnimCmd sAnim_BW_LUDICOLO[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LUDICOLO);
static const union AnimCmd sAnimEspalda_BW_LUDICOLO[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 64),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LUDICOLO);
static const union AnimCmd sAnim_BW_SEEDOT[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 29),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SEEDOT);
static const union AnimCmd sAnimEspalda_BW_SEEDOT[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SEEDOT);
static const union AnimCmd sAnim_BW_NUZLEAF[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NUZLEAF);
static const union AnimCmd sAnimEspalda_BW_NUZLEAF[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NUZLEAF);
static const union AnimCmd sAnim_BW_TAILLOW[] =
{
    POSE_DURANTE(0, 56),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 80),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 81),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 56),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TAILLOW);
static const union AnimCmd sAnimEspalda_BW_TAILLOW[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 40),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TAILLOW);
static const union AnimCmd sAnim_BW_SWELLOW[] =
{
    POSE_DURANTE(0, 126),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 115),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 114),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 66),
    POSE_DURANTE(3, 13),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SWELLOW);
static const union AnimCmd sAnimEspalda_BW_SWELLOW[] =
{
    POSE_DURANTE(0, 126),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 43),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SWELLOW);
static const union AnimCmd sAnim_BW_WINGULL[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WINGULL);
static const union AnimCmd sAnimEspalda_BW_WINGULL[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WINGULL);
static const union AnimCmd sAnim_BW_PELIPPER[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 58),
    POSE_DURANTE(2, 50),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 59),
    POSE_DURANTE(2, 50),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 58),
    POSE_DURANTE(2, 50),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 58),
    POSE_DURANTE(2, 50),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(1, 34),
    POSE_DURANTE(3, 56),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PELIPPER);
static const union AnimCmd sAnimEspalda_BW_PELIPPER[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PELIPPER);
static const union AnimCmd sAnim_BW_RALTS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RALTS);
static const union AnimCmd sAnimEspalda_BW_RALTS[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RALTS);
static const union AnimCmd sAnim_BW_KIRLIA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KIRLIA);
static const union AnimCmd sAnimEspalda_BW_KIRLIA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KIRLIA);
static const union AnimCmd sAnim_BW_GARDEVOIR[] =
{
    POSE_DURANTE(0, 56),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 89),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 88),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 88),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 57),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 80),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 32),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GARDEVOIR);
static const union AnimCmd sAnimEspalda_BW_GARDEVOIR[] =
{
    POSE_DURANTE(0, 56),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GARDEVOIR);
static const union AnimCmd sAnim_BW_GALLADE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 50),
    POSE_DURANTE(1, 41),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GALLADE);
static const union AnimCmd sAnimEspalda_BW_GALLADE[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 35),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GALLADE);
static const union AnimCmd sAnim_BW_SURSKIT[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 70),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 71),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 77),
    POSE_DURANTE(0, 91),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SURSKIT);
static const union AnimCmd sAnimEspalda_BW_SURSKIT[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 63),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SURSKIT);
static const union AnimCmd sAnim_BW_MASQUERAIN[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MASQUERAIN);
static const union AnimCmd sAnimEspalda_BW_MASQUERAIN[] =
{
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 26),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 2),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MASQUERAIN);
static const union AnimCmd sAnim_BW_SLAKOTH[] =
{
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 23),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SLAKOTH);
static const union AnimCmd sAnimEspalda_BW_SLAKOTH[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 48),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SLAKOTH);
static const union AnimCmd sAnim_BW_VIGOROTH[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VIGOROTH);
static const union AnimCmd sAnimEspalda_BW_VIGOROTH[] =
{
    POSE_DURANTE(0, 50),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VIGOROTH);
static const union AnimCmd sAnim_BW_SLAKING[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 45),
    POSE_DURANTE(2, 99),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SLAKING);
static const union AnimCmd sAnimEspalda_BW_SLAKING[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 41),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SLAKING);
static const union AnimCmd sAnim_BW_NINCADA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NINCADA);
static const union AnimCmd sAnimEspalda_BW_NINCADA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(1, 38),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NINCADA);
static const union AnimCmd sAnim_BW_NINJASK[] =
{
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NINJASK);
static const union AnimCmd sAnimEspalda_BW_NINJASK[] =
{
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 26),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NINJASK);
static const union AnimCmd sAnim_BW_SHEDINJA[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(4, 9),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHEDINJA);
static const union AnimCmd sAnimEspalda_BW_SHEDINJA[] =
{
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 9),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHEDINJA);
static const union AnimCmd sAnim_BW_WHISMUR[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 50),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 55),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 32),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WHISMUR);
static const union AnimCmd sAnimEspalda_BW_WHISMUR[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 26),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WHISMUR);
static const union AnimCmd sAnim_BW_LOUDRED[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 41),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LOUDRED);
static const union AnimCmd sAnimEspalda_BW_LOUDRED[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LOUDRED);
static const union AnimCmd sAnim_BW_EXPLOUD[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 43),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EXPLOUD);
static const union AnimCmd sAnimEspalda_BW_EXPLOUD[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 54),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EXPLOUD);
static const union AnimCmd sAnim_BW_MAKUHITA[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 80),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(0, 23),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAKUHITA);
static const union AnimCmd sAnimEspalda_BW_MAKUHITA[] =
{
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAKUHITA);
static const union AnimCmd sAnim_BW_HARIYAMA[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 75),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 66),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 75),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HARIYAMA);
static const union AnimCmd sAnimEspalda_BW_HARIYAMA[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HARIYAMA);
static const union AnimCmd sAnim_BW_NOSEPASS[] =
{
    POSE_DURANTE(0, 110),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 66),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(2, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NOSEPASS);
static const union AnimCmd sAnimEspalda_BW_NOSEPASS[] =
{
    POSE_DURANTE(0, 110),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 61),
    POSE_DURANTE(1, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NOSEPASS);
static const union AnimCmd sAnim_BW_PROBOPASS[] =
{
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 67),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(4, 50),
    POSE_DURANTE(2, 125),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PROBOPASS);
static const union AnimCmd sAnimEspalda_BW_PROBOPASS[] =
{
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 66),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 115),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PROBOPASS);
static const union AnimCmd sAnim_BW_SABLEYE[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SABLEYE);
static const union AnimCmd sAnimEspalda_BW_SABLEYE[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SABLEYE);
static const union AnimCmd sAnim_BW_MAWILE[] =
{
    POSE_DURANTE(0, 32),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 40),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MAWILE);
static const union AnimCmd sAnimEspalda_BW_MAWILE[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MAWILE);
static const union AnimCmd sAnim_BW_ARON[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 39),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 54),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARON);
static const union AnimCmd sAnimEspalda_BW_ARON[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARON);
static const union AnimCmd sAnim_BW_LAIRON[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(2, 68),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 65),
    POSE_DURANTE(2, 68),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 52),
    POSE_DURANTE(2, 68),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(2, 69),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 52),
    POSE_DURANTE(2, 68),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LAIRON);
static const union AnimCmd sAnimEspalda_BW_LAIRON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 68),
    POSE_DURANTE(1, 56),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LAIRON);
static const union AnimCmd sAnim_BW_AGGRON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 65),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 64),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 60),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AGGRON);
static const union AnimCmd sAnimEspalda_BW_AGGRON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 52),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AGGRON);
static const union AnimCmd sAnim_BW_MEDITITE[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 50),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEDITITE);
static const union AnimCmd sAnimEspalda_BW_MEDITITE[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 29),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEDITITE);
static const union AnimCmd sAnim_BW_MEDICHAM[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MEDICHAM);
static const union AnimCmd sAnimEspalda_BW_MEDICHAM[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MEDICHAM);
static const union AnimCmd sAnim_BW_ELECTRIKE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 37),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ELECTRIKE);
static const union AnimCmd sAnimEspalda_BW_ELECTRIKE[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ELECTRIKE);
static const union AnimCmd sAnim_BW_MANECTRIC[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 72),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 73),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 72),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(2, 72),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(2, 60),
    POSE_DURANTE(3, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MANECTRIC);
static const union AnimCmd sAnimEspalda_BW_MANECTRIC[] =
{
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MANECTRIC);
static const union AnimCmd sAnim_BW_BUDEW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BUDEW);
static const union AnimCmd sAnimEspalda_BW_BUDEW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BUDEW);
static const union AnimCmd sAnim_BW_ROSELIA[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROSELIA);
static const union AnimCmd sAnimEspalda_BW_ROSELIA[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROSELIA);
static const union AnimCmd sAnim_BW_ROSERADE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 22),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROSERADE);
static const union AnimCmd sAnimEspalda_BW_ROSERADE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROSERADE);
static const union AnimCmd sAnim_BW_CARVANHA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CARVANHA);
static const union AnimCmd sAnimEspalda_BW_CARVANHA[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CARVANHA);
static const union AnimCmd sAnim_BW_SHARPEDO[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 55),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHARPEDO);
static const union AnimCmd sAnimEspalda_BW_SHARPEDO[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 42),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHARPEDO);
static const union AnimCmd sAnim_BW_WAILMER[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 55),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WAILMER);
static const union AnimCmd sAnimEspalda_BW_WAILMER[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WAILMER);
static const union AnimCmd sAnim_BW_NUMEL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_NUMEL);
static const union AnimCmd sAnimEspalda_BW_NUMEL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_NUMEL);
static const union AnimCmd sAnim_BW_CAMERUPT[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 66),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CAMERUPT);
static const union AnimCmd sAnimEspalda_BW_CAMERUPT[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CAMERUPT);
static const union AnimCmd sAnim_BW_TORKOAL[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TORKOAL);
static const union AnimCmd sAnimEspalda_BW_TORKOAL[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TORKOAL);
static const union AnimCmd sAnim_BW_TRAPINCH[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TRAPINCH);
static const union AnimCmd sAnimEspalda_BW_TRAPINCH[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TRAPINCH);
static const union AnimCmd sAnim_BW_VIBRAVA[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VIBRAVA);
static const union AnimCmd sAnimEspalda_BW_VIBRAVA[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VIBRAVA);
static const union AnimCmd sAnim_BW_FLYGON[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(2, 22),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FLYGON);
static const union AnimCmd sAnimEspalda_BW_FLYGON[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FLYGON);
static const union AnimCmd sAnim_BW_CACNEA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 64),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 72),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 64),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 49),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(2, 72),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CACNEA);
static const union AnimCmd sAnimEspalda_BW_CACNEA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 72),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CACNEA);
static const union AnimCmd sAnim_BW_CACTURNE[] =
{
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 57),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CACTURNE);
static const union AnimCmd sAnimEspalda_BW_CACTURNE[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 57),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CACTURNE);
static const union AnimCmd sAnim_BW_SWABLU[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SWABLU);
static const union AnimCmd sAnimEspalda_BW_SWABLU[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SWABLU);
static const union AnimCmd sAnim_BW_ALTARIA[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 55),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 60),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ALTARIA);
static const union AnimCmd sAnimEspalda_BW_ALTARIA[] =
{
    POSE_DURANTE(0, 45),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 10),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ALTARIA);
static const union AnimCmd sAnim_BW_LUNATONE[] =
{
    POSE_DURANTE(0, 104),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 57),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 113),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 113),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 57),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 112),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LUNATONE);
static const union AnimCmd sAnimEspalda_BW_LUNATONE[] =
{
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 57),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 56),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LUNATONE);
static const union AnimCmd sAnim_BW_SOLROCK[] =
{
    POSE_DURANTE(0, 96),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 32),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 17),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 32),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 105),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SOLROCK);
static const union AnimCmd sAnimEspalda_BW_SOLROCK[] =
{
    POSE_DURANTE(0, 96),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 105),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SOLROCK);
static const union AnimCmd sAnim_BW_BALTOY[] =
{
    POSE_DURANTE(0, 120),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 41),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 136),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(0, 136),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 137),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(0, 120),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(4, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BALTOY);
static const union AnimCmd sAnimEspalda_BW_BALTOY[] =
{
    POSE_DURANTE(0, 120),
    POSE_DURANTE(2, 48),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BALTOY);
static const union AnimCmd sAnim_BW_CLAYDOL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CLAYDOL);
static const union AnimCmd sAnimEspalda_BW_CLAYDOL[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CLAYDOL);
static const union AnimCmd sAnim_BW_LILEEP[] =
{
    POSE_DURANTE(0, 150),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 168),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 169),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 169),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 66),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(0, 60),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LILEEP);
static const union AnimCmd sAnimEspalda_BW_LILEEP[] =
{
    POSE_DURANTE(0, 48),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 121),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LILEEP);
static const union AnimCmd sAnim_BW_CRADILY[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 37),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CRADILY);
static const union AnimCmd sAnimEspalda_BW_CRADILY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CRADILY);
static const union AnimCmd sAnim_BW_ANORITH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 60),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 61),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ANORITH);
static const union AnimCmd sAnimEspalda_BW_ANORITH[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 60),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ANORITH);
static const union AnimCmd sAnim_BW_ARMALDO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ARMALDO);
static const union AnimCmd sAnimEspalda_BW_ARMALDO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ARMALDO);
static const union AnimCmd sAnim_BW_FEEBAS[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FEEBAS);
static const union AnimCmd sAnimEspalda_BW_FEEBAS[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FEEBAS);
static const union AnimCmd sAnim_BW_MILOTIC[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(2, 72),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(2, 90),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 54),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(2, 72),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MILOTIC);
static const union AnimCmd sAnimEspalda_BW_MILOTIC[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 54),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MILOTIC);
static const union AnimCmd sAnim_BW_CASTFORM[] =
{
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(2, 137),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CASTFORM);
static const union AnimCmd sAnimEspalda_BW_CASTFORM[] =
{
    POSE_DURANTE(0, 46),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CASTFORM);
static const union AnimCmd sAnim_BW_CASTFORM_SUNNY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CASTFORM_SUNNY);
static const union AnimCmd sAnimEspalda_BW_CASTFORM_SUNNY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CASTFORM_SUNNY);
static const union AnimCmd sAnim_BW_CASTFORM_RAINY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CASTFORM_RAINY);
static const union AnimCmd sAnimEspalda_BW_CASTFORM_RAINY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CASTFORM_RAINY);
static const union AnimCmd sAnim_BW_CASTFORM_SNOWY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CASTFORM_SNOWY);
static const union AnimCmd sAnimEspalda_BW_CASTFORM_SNOWY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CASTFORM_SNOWY);
static const union AnimCmd sAnim_BW_KECLEON[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 80),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 51),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KECLEON);
static const union AnimCmd sAnimEspalda_BW_KECLEON[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 50),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KECLEON);
static const union AnimCmd sAnim_BW_DUSKULL[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 26),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(3, 20),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DUSKULL);
static const union AnimCmd sAnimEspalda_BW_DUSKULL[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 25),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DUSKULL);
static const union AnimCmd sAnim_BW_DUSCLOPS[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 45),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 45),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(2, 45),
    POSE_DURANTE(1, 15),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DUSCLOPS);
static const union AnimCmd sAnimEspalda_BW_DUSCLOPS[] =
{
    POSE_DURANTE(0, 25),
    POSE_DURANTE(2, 45),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DUSCLOPS);
static const union AnimCmd sAnim_BW_DUSKNOIR[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DUSKNOIR);
static const union AnimCmd sAnimEspalda_BW_DUSKNOIR[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DUSKNOIR);
static const union AnimCmd sAnim_BW_TROPIUS[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TROPIUS);
static const union AnimCmd sAnimEspalda_BW_TROPIUS[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TROPIUS);
static const union AnimCmd sAnim_BW_CHINGLING[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHINGLING);
static const union AnimCmd sAnimEspalda_BW_CHINGLING[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHINGLING);
static const union AnimCmd sAnim_BW_CHIMECHO[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(2, 29),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHIMECHO);
static const union AnimCmd sAnimEspalda_BW_CHIMECHO[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHIMECHO);
static const union AnimCmd sAnim_BW_ABSOL[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(3, 60),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ABSOL);
static const union AnimCmd sAnimEspalda_BW_ABSOL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ABSOL);
static const union AnimCmd sAnim_BW_SNORUNT[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 5),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNORUNT);
static const union AnimCmd sAnimEspalda_BW_SNORUNT[] =
{
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNORUNT);
static const union AnimCmd sAnim_BW_GLALIE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GLALIE);
static const union AnimCmd sAnimEspalda_BW_GLALIE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GLALIE);
static const union AnimCmd sAnim_BW_FROSLASS[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 79),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 78),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 79),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FROSLASS);
static const union AnimCmd sAnimEspalda_BW_FROSLASS[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FROSLASS);
static const union AnimCmd sAnim_BW_SPHEAL[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 10),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(1, 11),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 10),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 10),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SPHEAL);
static const union AnimCmd sAnimEspalda_BW_SPHEAL[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SPHEAL);
static const union AnimCmd sAnim_BW_SEALEO[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 10),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SEALEO);
static const union AnimCmd sAnimEspalda_BW_SEALEO[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(2, 40),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SEALEO);
static const union AnimCmd sAnim_BW_WALREIN[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(3, 15),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_WALREIN);
static const union AnimCmd sAnimEspalda_BW_WALREIN[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_WALREIN);
static const union AnimCmd sAnim_BW_BAGON[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 11),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BAGON);
static const union AnimCmd sAnimEspalda_BW_BAGON[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 5),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BAGON);
static const union AnimCmd sAnim_BW_SHELGON[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHELGON);
static const union AnimCmd sAnimEspalda_BW_SHELGON[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHELGON);
static const union AnimCmd sAnim_BW_SALAMENCE[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 28),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SALAMENCE);
static const union AnimCmd sAnimEspalda_BW_SALAMENCE[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SALAMENCE);
static const union AnimCmd sAnim_BW_BELDUM[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(3, 48),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(3, 32),
    POSE_DURANTE(4, 33),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(3, 48),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(3, 17),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(3, 48),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 25),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(3, 48),
    POSE_DURANTE(4, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BELDUM);
static const union AnimCmd sAnimEspalda_BW_BELDUM[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BELDUM);
static const union AnimCmd sAnim_BW_METANG[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 22),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 29),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_METANG);
static const union AnimCmd sAnimEspalda_BW_METANG[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 29),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_METANG);
static const union AnimCmd sAnim_BW_METAGROSS[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 57),
    POSE_DURANTE(3, 98),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(0, 63),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_METAGROSS);
static const union AnimCmd sAnimEspalda_BW_METAGROSS[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_METAGROSS);
static const union AnimCmd sAnim_BW_LATIAS[] =
{
    POSE_DURANTE(0, 26),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(1, 22),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 21),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LATIAS);
static const union AnimCmd sAnimEspalda_BW_LATIAS[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LATIAS);
static const union AnimCmd sAnim_BW_LATIOS[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 31),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LATIOS);
static const union AnimCmd sAnimEspalda_BW_LATIOS[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LATIOS);
static const union AnimCmd sAnim_BW_GROUDON[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 22),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GROUDON);
static const union AnimCmd sAnimEspalda_BW_GROUDON[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GROUDON);
static const union AnimCmd sAnim_BW_DEOXYS_NORMAL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DEOXYS_NORMAL);
static const union AnimCmd sAnimEspalda_BW_DEOXYS_NORMAL[] =
{
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 15),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DEOXYS_NORMAL);
static const union AnimCmd sAnim_BW_DEOXYS_ATTACK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DEOXYS_ATTACK);
static const union AnimCmd sAnimEspalda_BW_DEOXYS_ATTACK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DEOXYS_ATTACK);
static const union AnimCmd sAnim_BW_DEOXYS_DEFENSE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DEOXYS_DEFENSE);
static const union AnimCmd sAnimEspalda_BW_DEOXYS_DEFENSE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DEOXYS_DEFENSE);
static const union AnimCmd sAnim_BW_DEOXYS_SPEED[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DEOXYS_SPEED);
static const union AnimCmd sAnimEspalda_BW_DEOXYS_SPEED[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DEOXYS_SPEED);
static const union AnimCmd sAnim_BW_TURTWIG[] =
{
    POSE_DURANTE(0, 27),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(4, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TURTWIG);
static const union AnimCmd sAnimEspalda_BW_TURTWIG[] =
{
    POSE_DURANTE(0, 27),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TURTWIG);
static const union AnimCmd sAnim_BW_GROTLE[] =
{
    POSE_DURANTE(0, 23),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(2, 17),
    POSE_DURANTE(0, 35),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 49),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GROTLE);
static const union AnimCmd sAnimEspalda_BW_GROTLE[] =
{
    POSE_DURANTE(0, 28),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GROTLE);
static const union AnimCmd sAnim_BW_TORTERRA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 41),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 40),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(3, 16),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 64),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TORTERRA);
static const union AnimCmd sAnimEspalda_BW_TORTERRA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 48),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TORTERRA);
static const union AnimCmd sAnim_BW_CHIMCHAR[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHIMCHAR);
static const union AnimCmd sAnimEspalda_BW_CHIMCHAR[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHIMCHAR);
static const union AnimCmd sAnim_BW_MONFERNO[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 20),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 20),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_MONFERNO);
static const union AnimCmd sAnimEspalda_BW_MONFERNO[] =
{
    POSE_DURANTE(0, 20),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 20),
    POSE_DURANTE(1, 16),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_MONFERNO);
static const union AnimCmd sAnim_BW_INFERNAPE[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_INFERNAPE);
static const union AnimCmd sAnimEspalda_BW_INFERNAPE[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_INFERNAPE);
static const union AnimCmd sAnim_BW_PIPLUP[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PIPLUP);
static const union AnimCmd sAnimEspalda_BW_PIPLUP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PIPLUP);
static const union AnimCmd sAnim_BW_PRINPLUP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PRINPLUP);
static const union AnimCmd sAnimEspalda_BW_PRINPLUP[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PRINPLUP);
static const union AnimCmd sAnim_BW_EMPOLEON[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_EMPOLEON);
static const union AnimCmd sAnimEspalda_BW_EMPOLEON[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_EMPOLEON);
static const union AnimCmd sAnim_BW_STARLY[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STARLY);
static const union AnimCmd sAnimEspalda_BW_STARLY[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(0, 15),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STARLY);
static const union AnimCmd sAnim_BW_STARAVIA[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 77),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(4, 77),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STARAVIA);
static const union AnimCmd sAnimEspalda_BW_STARAVIA[] =
{
    POSE_DURANTE(0, 35),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STARAVIA);
static const union AnimCmd sAnim_BW_STARAPTOR[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 49),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(2, 21),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_STARAPTOR);
static const union AnimCmd sAnimEspalda_BW_STARAPTOR[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(2, 28),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_STARAPTOR);
static const union AnimCmd sAnim_BW_BIDOOF[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BIDOOF);
static const union AnimCmd sAnimEspalda_BW_BIDOOF[] =
{
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BIDOOF);
static const union AnimCmd sAnim_BW_BIBAREL[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(4, 21),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 15),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BIBAREL);
static const union AnimCmd sAnimEspalda_BW_BIBAREL[] =
{
    POSE_DURANTE(0, 49),
    POSE_DURANTE(1, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 35),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BIBAREL);
static const union AnimCmd sAnim_BW_KRICKETOT[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 48),
    POSE_DURANTE(3, 36),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KRICKETOT);
static const union AnimCmd sAnimEspalda_BW_KRICKETOT[] =
{
    POSE_DURANTE(0, 36),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KRICKETOT);
static const union AnimCmd sAnim_BW_KRICKETUNE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 30),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KRICKETUNE);
static const union AnimCmd sAnimEspalda_BW_KRICKETUNE[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KRICKETUNE);
static const union AnimCmd sAnim_BW_SHINX[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHINX);
static const union AnimCmd sAnimEspalda_BW_SHINX[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(1, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHINX);
static const union AnimCmd sAnim_BW_LUXIO[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 40),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(4, 20),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 25),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LUXIO);
static const union AnimCmd sAnimEspalda_BW_LUXIO[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LUXIO);
static const union AnimCmd sAnim_BW_LUXRAY[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LUXRAY);
static const union AnimCmd sAnimEspalda_BW_LUXRAY[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(0, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LUXRAY);
static const union AnimCmd sAnim_BW_CRANIDOS[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CRANIDOS);
static const union AnimCmd sAnimEspalda_BW_CRANIDOS[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CRANIDOS);
static const union AnimCmd sAnim_BW_RAMPARDOS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 60),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RAMPARDOS);
static const union AnimCmd sAnimEspalda_BW_RAMPARDOS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RAMPARDOS);
static const union AnimCmd sAnim_BW_SHIELDON[] =
{
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 26),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    POSE_DURANTE(3, 25),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(4, 15),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 25),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SHIELDON);
static const union AnimCmd sAnimEspalda_BW_SHIELDON[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 5),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 20),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SHIELDON);
static const union AnimCmd sAnim_BW_BASTIODON[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 37),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 30),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 60),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BASTIODON);
static const union AnimCmd sAnimEspalda_BW_BASTIODON[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BASTIODON);
static const union AnimCmd sAnim_BW_COMBEE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 10),
    POSE_DURANTE(2, 10),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(3, 3),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 2),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_COMBEE);
static const union AnimCmd sAnimEspalda_BW_COMBEE[] =
{
    POSE_DURANTE(0, 10),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_COMBEE);
static const union AnimCmd sAnim_BW_VESPIQUEN[] =
{
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 23),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 2),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(3, 29),
    POSE_DURANTE(4, 69),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 4),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 2),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 76),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 79),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 3),
    POSE_DURANTE(3, 1),
    POSE_DURANTE(4, 25),
    POSE_DURANTE(3, 5),
    POSE_DURANTE(4, 1),
    POSE_DURANTE(3, 9),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(1, 2),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 2),
    POSE_DURANTE(1, 3),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VESPIQUEN);
static const union AnimCmd sAnimEspalda_BW_VESPIQUEN[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 3),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 5),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 1),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 1),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 3),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VESPIQUEN);
static const union AnimCmd sAnim_BW_DRIFLOON[] =
{
    POSE_DURANTE(0, 66),
    POSE_DURANTE(2, 42),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 19),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 120),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRIFLOON);
static const union AnimCmd sAnimEspalda_BW_DRIFLOON[] =
{
    POSE_DURANTE(0, 60),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRIFLOON);
static const union AnimCmd sAnim_BW_DRIFBLIM[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(2, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRIFBLIM);
static const union AnimCmd sAnimEspalda_BW_DRIFBLIM[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRIFBLIM);
static const union AnimCmd sAnim_BW_BUNEARY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 73),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BUNEARY);
static const union AnimCmd sAnimEspalda_BW_BUNEARY[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BUNEARY);
static const union AnimCmd sAnim_BW_LOPUNNY[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 31),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(2, 54),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LOPUNNY);
static const union AnimCmd sAnimEspalda_BW_LOPUNNY[] =
{
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LOPUNNY);
static const union AnimCmd sAnim_BW_GIBLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 6),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GIBLE);
static const union AnimCmd sAnimEspalda_BW_GIBLE[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 48),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GIBLE);
static const union AnimCmd sAnim_BW_GABITE[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 70),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 71),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(3, 7),
    POSE_DURANTE(1, 35),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GABITE);
static const union AnimCmd sAnimEspalda_BW_GABITE[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 35),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GABITE);
static const union AnimCmd sAnim_BW_GARCHOMP[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 57),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 56),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(4, 72),
    POSE_DURANTE(1, 64),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GARCHOMP);
static const union AnimCmd sAnimEspalda_BW_GARCHOMP[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GARCHOMP);
static const union AnimCmd sAnim_BW_RIOLU[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 19),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(4, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_RIOLU);
static const union AnimCmd sAnimEspalda_BW_RIOLU[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_RIOLU);
static const union AnimCmd sAnim_BW_LUCARIO[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 13),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(4, 12),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 18),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LUCARIO);
static const union AnimCmd sAnimEspalda_BW_LUCARIO[] =
{
    POSE_DURANTE(0, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LUCARIO);
static const union AnimCmd sAnim_BW_SKORUPI[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 24),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(2, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(4, 36),
    POSE_DURANTE(1, 30),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SKORUPI);
static const union AnimCmd sAnimEspalda_BW_SKORUPI[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SKORUPI);
static const union AnimCmd sAnim_BW_CROAGUNK[] =
{
    POSE_DURANTE(0, 18),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 31),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 36),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 30),
    POSE_DURANTE(3, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(0, 6),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CROAGUNK);
static const union AnimCmd sAnimEspalda_BW_CROAGUNK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 42),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(2, 30),
    POSE_DURANTE(0, 12),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CROAGUNK);
static const union AnimCmd sAnim_BW_TOXICROAK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 13),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(3, 18),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(4, 18),
    POSE_DURANTE(3, 6),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TOXICROAK);
static const union AnimCmd sAnimEspalda_BW_TOXICROAK[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 6),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 18),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TOXICROAK);
static const union AnimCmd sAnim_BW_SNOVER[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 33),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(0, 40),
    POSE_DURANTE(3, 40),
    POSE_DURANTE(0, 32),
    POSE_DURANTE(4, 32),
    POSE_DURANTE(0, 24),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNOVER);
static const union AnimCmd sAnimEspalda_BW_SNOVER[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNOVER);
static const union AnimCmd sAnim_BW_ABOMASNOW[] =
{
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 22),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(3, 28),
    POSE_DURANTE(4, 35),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ABOMASNOW);
static const union AnimCmd sAnimEspalda_BW_ABOMASNOW[] =
{
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 28),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ABOMASNOW);
static const union AnimCmd sAnim_BW_ROTOM[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 5),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 12),
    POSE_DURANTE(0, 24),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 9),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(3, 4),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 4),
    POSE_DURANTE(2, 4),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM);
static const union AnimCmd sAnimEspalda_BW_ROTOM[] =
{
    POSE_DURANTE(0, 4),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 28),
    POSE_DURANTE(1, 4),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 4),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM);
static const union AnimCmd sAnim_BW_ROTOM_HEAT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM_HEAT);
static const union AnimCmd sAnimEspalda_BW_ROTOM_HEAT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM_HEAT);
static const union AnimCmd sAnim_BW_ROTOM_WASH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM_WASH);
static const union AnimCmd sAnimEspalda_BW_ROTOM_WASH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM_WASH);
static const union AnimCmd sAnim_BW_ROTOM_FROST[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM_FROST);
static const union AnimCmd sAnimEspalda_BW_ROTOM_FROST[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM_FROST);
static const union AnimCmd sAnim_BW_ROTOM_FAN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM_FAN);
static const union AnimCmd sAnimEspalda_BW_ROTOM_FAN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM_FAN);
static const union AnimCmd sAnim_BW_ROTOM_MOW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROTOM_MOW);
static const union AnimCmd sAnimEspalda_BW_ROTOM_MOW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROTOM_MOW);
static const union AnimCmd sAnim_BW_HEATRAN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 33),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 32),
    POSE_DURANTE(0, 9),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 48),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 160),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 25),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 80),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HEATRAN);
static const union AnimCmd sAnimEspalda_BW_HEATRAN[] =
{
    POSE_DURANTE(0, 16),
    POSE_DURANTE(2, 16),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HEATRAN);
static const union AnimCmd sAnim_BW_YAMASK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_YAMASK);
static const union AnimCmd sAnimEspalda_BW_YAMASK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_YAMASK);
static const union AnimCmd sAnim_BW_COFAGRIGUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_COFAGRIGUS);
static const union AnimCmd sAnimEspalda_BW_COFAGRIGUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_COFAGRIGUS);
static const union AnimCmd sAnim_BW_FRILLISH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FRILLISH);
static const union AnimCmd sAnimEspalda_BW_FRILLISH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FRILLISH);
static const union AnimCmd sAnim_BW_JELLICENT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JELLICENT);
static const union AnimCmd sAnimEspalda_BW_JELLICENT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JELLICENT);
static const union AnimCmd sAnim_BW_JOLTIK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JOLTIK);
static const union AnimCmd sAnimEspalda_BW_JOLTIK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JOLTIK);
static const union AnimCmd sAnim_BW_GALVANTULA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_GALVANTULA);
static const union AnimCmd sAnimEspalda_BW_GALVANTULA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_GALVANTULA);
static const union AnimCmd sAnim_BW_FERROSEED[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FERROSEED);
static const union AnimCmd sAnimEspalda_BW_FERROSEED[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FERROSEED);
static const union AnimCmd sAnim_BW_FERROTHORN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FERROTHORN);
static const union AnimCmd sAnimEspalda_BW_FERROTHORN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FERROTHORN);
static const union AnimCmd sAnim_BW_LITWICK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LITWICK);
static const union AnimCmd sAnimEspalda_BW_LITWICK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LITWICK);
static const union AnimCmd sAnim_BW_LAMPENT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LAMPENT);
static const union AnimCmd sAnimEspalda_BW_LAMPENT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LAMPENT);
static const union AnimCmd sAnim_BW_CHANDELURE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CHANDELURE);
static const union AnimCmd sAnimEspalda_BW_CHANDELURE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CHANDELURE);
static const union AnimCmd sAnim_BW_AXEW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AXEW);
static const union AnimCmd sAnimEspalda_BW_AXEW[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AXEW);
static const union AnimCmd sAnim_BW_FRAXURE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FRAXURE);
static const union AnimCmd sAnimEspalda_BW_FRAXURE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FRAXURE);
static const union AnimCmd sAnim_BW_HAXORUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HAXORUS);
static const union AnimCmd sAnimEspalda_BW_HAXORUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HAXORUS);
static const union AnimCmd sAnim_BW_CUBCHOO[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CUBCHOO);
static const union AnimCmd sAnimEspalda_BW_CUBCHOO[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CUBCHOO);
static const union AnimCmd sAnim_BW_BEARTIC[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BEARTIC);
static const union AnimCmd sAnimEspalda_BW_BEARTIC[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BEARTIC);
static const union AnimCmd sAnim_BW_PAWNIARD[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_PAWNIARD);
static const union AnimCmd sAnimEspalda_BW_PAWNIARD[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_PAWNIARD);
static const union AnimCmd sAnim_BW_BISHARP[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BISHARP);
static const union AnimCmd sAnimEspalda_BW_BISHARP[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BISHARP);
static const union AnimCmd sAnim_BW_DEINO[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DEINO);
static const union AnimCmd sAnimEspalda_BW_DEINO[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DEINO);
static const union AnimCmd sAnim_BW_ZWEILOUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ZWEILOUS);
static const union AnimCmd sAnimEspalda_BW_ZWEILOUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ZWEILOUS);
static const union AnimCmd sAnim_BW_HYDREIGON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HYDREIGON);
static const union AnimCmd sAnimEspalda_BW_HYDREIGON[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HYDREIGON);
static const union AnimCmd sAnim_BW_LARVESTA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_LARVESTA);
static const union AnimCmd sAnimEspalda_BW_LARVESTA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_LARVESTA);
static const union AnimCmd sAnim_BW_VOLCARONA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_VOLCARONA);
static const union AnimCmd sAnimEspalda_BW_VOLCARONA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_VOLCARONA);
static const union AnimCmd sAnim_BW_FENNEKIN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FENNEKIN);
static const union AnimCmd sAnimEspalda_BW_FENNEKIN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FENNEKIN);
static const union AnimCmd sAnim_BW_BRAIXEN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BRAIXEN);
static const union AnimCmd sAnimEspalda_BW_BRAIXEN[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BRAIXEN);
static const union AnimCmd sAnim_BW_DELPHOX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DELPHOX);
static const union AnimCmd sAnimEspalda_BW_DELPHOX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DELPHOX);
static const union AnimCmd sAnim_BW_FLETCHLING[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FLETCHLING);
static const union AnimCmd sAnimEspalda_BW_FLETCHLING[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FLETCHLING);
static const union AnimCmd sAnim_BW_FLETCHINDER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FLETCHINDER);
static const union AnimCmd sAnimEspalda_BW_FLETCHINDER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FLETCHINDER);
static const union AnimCmd sAnim_BW_TALONFLAME[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TALONFLAME);
static const union AnimCmd sAnimEspalda_BW_TALONFLAME[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TALONFLAME);
static const union AnimCmd sAnim_BW_TYRUNT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TYRUNT);
static const union AnimCmd sAnimEspalda_BW_TYRUNT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TYRUNT);
static const union AnimCmd sAnim_BW_TYRANTRUM[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_TYRANTRUM);
static const union AnimCmd sAnimEspalda_BW_TYRANTRUM[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_TYRANTRUM);
static const union AnimCmd sAnim_BW_AMAURA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AMAURA);
static const union AnimCmd sAnimEspalda_BW_AMAURA[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AMAURA);
static const union AnimCmd sAnim_BW_AURORUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_AURORUS);
static const union AnimCmd sAnimEspalda_BW_AURORUS[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_AURORUS);
static const union AnimCmd sAnim_BW_ROWLET[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROWLET);
static const union AnimCmd sAnimEspalda_BW_ROWLET[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROWLET);
static const union AnimCmd sAnim_BW_DARTRIX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DARTRIX);
static const union AnimCmd sAnimEspalda_BW_DARTRIX[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DARTRIX);
static const union AnimCmd sAnim_BW_DECIDUEYE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DECIDUEYE);
static const union AnimCmd sAnimEspalda_BW_DECIDUEYE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DECIDUEYE);
static const union AnimCmd sAnim_BW_JANGMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_JANGMO_O);
static const union AnimCmd sAnimEspalda_BW_JANGMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_JANGMO_O);
static const union AnimCmd sAnim_BW_HAKAMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_HAKAMO_O);
static const union AnimCmd sAnimEspalda_BW_HAKAMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_HAKAMO_O);
static const union AnimCmd sAnim_BW_KOMMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_KOMMO_O);
static const union AnimCmd sAnimEspalda_BW_KOMMO_O[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_KOMMO_O);
static const union AnimCmd sAnim_BW_ROOKIDEE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ROOKIDEE);
static const union AnimCmd sAnimEspalda_BW_ROOKIDEE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ROOKIDEE);
static const union AnimCmd sAnim_BW_CORVISQUIRE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CORVISQUIRE);
static const union AnimCmd sAnimEspalda_BW_CORVISQUIRE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CORVISQUIRE);
static const union AnimCmd sAnim_BW_CORVIKNIGHT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_CORVIKNIGHT);
static const union AnimCmd sAnimEspalda_BW_CORVIKNIGHT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_CORVIKNIGHT);
static const union AnimCmd sAnim_BW_BLIPBUG[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_BLIPBUG);
static const union AnimCmd sAnimEspalda_BW_BLIPBUG[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_BLIPBUG);
static const union AnimCmd sAnim_BW_DOTTLER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DOTTLER);
static const union AnimCmd sAnimEspalda_BW_DOTTLER[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DOTTLER);
static const union AnimCmd sAnim_BW_ORBEETLE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_ORBEETLE);
static const union AnimCmd sAnimEspalda_BW_ORBEETLE[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_ORBEETLE);
static const union AnimCmd sAnim_BW_SNOM[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_SNOM);
static const union AnimCmd sAnimEspalda_BW_SNOM[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_SNOM);
static const union AnimCmd sAnim_BW_FROSMOTH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_FROSMOTH);
static const union AnimCmd sAnimEspalda_BW_FROSMOTH[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_FROSMOTH);
static const union AnimCmd sAnim_BW_DREEPY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DREEPY);
static const union AnimCmd sAnimEspalda_BW_DREEPY[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DREEPY);
static const union AnimCmd sAnim_BW_DRAKLOAK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRAKLOAK);
static const union AnimCmd sAnimEspalda_BW_DRAKLOAK[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRAKLOAK);
static const union AnimCmd sAnim_BW_DRAGAPULT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(4, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_DRAGAPULT);
static const union AnimCmd sAnimEspalda_BW_DRAGAPULT[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(2, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_DRAGAPULT);
static const union AnimCmd sAnim_BW_REGIROCK[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 15),
    POSE_DURANTE(0, 49),
    POSE_DURANTE(3, 21),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(1, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 42),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 21),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_REGIROCK);
static const union AnimCmd sAnimEspalda_BW_REGIROCK[] =
{
    POSE_DURANTE(0, 42),
    POSE_DURANTE(2, 28),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_REGIROCK);
static const union AnimCmd sAnim_BW_REGICE[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 43),
    POSE_DURANTE(3, 14),
    POSE_DURANTE(0, 14),
    POSE_DURANTE(2, 7),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(4, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(2, 21),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_REGICE);
static const union AnimCmd sAnimEspalda_BW_REGICE[] =
{
    POSE_DURANTE(0, 7),
    POSE_DURANTE(1, 14),
    POSE_DURANTE(0, 7),
    POSE_DURANTE(2, 35),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_REGICE);
static const union AnimCmd sAnim_BW_REGISTEEL[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 16),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 17),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 16),
    POSE_DURANTE(3, 24),
    POSE_DURANTE(4, 24),
    POSE_DURANTE(3, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(0, 8),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_REGISTEEL);
static const union AnimCmd sAnimEspalda_BW_REGISTEEL[] =
{
    POSE_DURANTE(0, 8),
    POSE_DURANTE(1, 8),
    POSE_DURANTE(2, 24),
    POSE_DURANTE(1, 8),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_REGISTEEL);
static const union AnimCmd sAnim_BW_REGIGIGAS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 19),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    POSE_DURANTE(3, 42),
    POSE_DURANTE(1, 30),
    POSE_DURANTE(4, 48),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
SINGLE_ANIMATION(BW_REGIGIGAS);
static const union AnimCmd sAnimEspalda_BW_REGIGIGAS[] =
{
    POSE_DURANTE(0, 12),
    POSE_DURANTE(2, 18),
    POSE_DURANTE(0, 12),
    POSE_DURANTE(1, 36),
    VUELTA_AL_PRINCIPIO,
};
ESPALDA(BW_REGIGIGAS);

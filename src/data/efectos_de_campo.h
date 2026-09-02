// Que hace cada efecto de campo: cargar sus paletas y llamar a su funcion.
//
// Esto era un interprete de bytecode -66 guiones en ensamblador, ocho comandos,
// una tabla de despacho y un lector de bytes- para expresar exactamente esta
// tabla: de cero a dos paletas y una llamada. Ni saltos, ni condiciones, ni
// variables. Tres de aquellos ocho comandos no los usaba nadie.
//
// Anadir un efecto ahora es la enum y una fila aqui, y el compilador comprueba
// el tipo de la funcion, que antes no comprobaba nadie.

// Las paletas viven repartidas entre field_effect_objects.h, field_effect.c y
// battle_transition.c; se declaran aqui para que la tabla no dependa del orden
// de los includes.
extern const struct SpritePalette gSpritePalette_Ash;
extern const struct SpritePalette gSpritePalette_CutGrass;
extern const struct SpritePalette gSpritePalette_GeneralFieldEffect0;
extern const struct SpritePalette gSpritePalette_GeneralFieldEffect1;
extern const struct SpritePalette gSpritePalette_HofMonitor;
extern const struct SpritePalette gSpritePalette_Pokeball;
extern const struct SpritePalette gSpritePalette_PokeballGlow;
extern const struct SpritePalette gSpritePalette_SmallSparkle;

void FldEff_CutGrass(void);
void FldEff_FlyIn(void);
void FldEff_HallOfFameRecord(void);
void FldEff_PokecenterHeal(void);
void FldEff_RayquazaSpotlight(void);
void FldEff_UseCutOnGrass(void);
void FldEff_UseCutOnTree(void);
void FldEff_UseDig(void);
void FldEff_UseDive(void);
void FldEff_UseRockSmash(void);
void FldEff_UseStrength(void);
void FldEff_UseSurf(void);
void FldEff_UseTeleport(void);
void FldEff_UseVsSeeker(void);
void FldEff_UseWaterfall(void);
void ShowSandDisguiseFieldEffect(void);

struct EfectoDeCampo
{
    void (*funcion)(void);
    // Hasta dos, en orden. La primera a NULL significa que no lleva ninguna.
    const struct SpritePalette *paletas[2];
    // Las paletas de campo se atenuan con el clima al cargarlas; esta no.
    bool8 sinAtenuar;
};

static const struct EfectoDeCampo sEfectosDeCampo[NUMERO_EFECTOS_CAMPO] =
{
    [FLDEFF_USE_CUT_ON_GRASS         ] = { FldEff_UseCutOnGrass },
    [FLDEFF_USE_CUT_ON_TREE          ] = { FldEff_UseCutOnTree },
    [FLDEFF_USE_SURF                 ] = { FldEff_UseSurf },
    [FLDEFF_POKECENTER_HEAL          ] = { FldEff_PokecenterHeal, { &gSpritePalette_PokeballGlow, &gSpritePalette_GeneralFieldEffect0 } },
    [FLDEFF_FLY_IN                   ] = { FldEff_FlyIn },
    [FLDEFF_SAND_DISGUISE            ] = { ShowSandDisguiseFieldEffect },
    [FLDEFF_USE_ROCK_SMASH           ] = { FldEff_UseRockSmash },
    [FLDEFF_USE_DIG                  ] = { FldEff_UseDig },
    [FLDEFF_USE_STRENGTH             ] = { FldEff_UseStrength },
    [FLDEFF_USE_WATERFALL            ] = { FldEff_UseWaterfall },
    [FLDEFF_USE_DIVE                 ] = { FldEff_UseDive },
    [FLDEFF_CUT_GRASS                ] = { FldEff_CutGrass, { &gSpritePalette_CutGrass } },
    [FLDEFF_HALL_OF_FAME_RECORD      ] = { FldEff_HallOfFameRecord, { &gSpritePalette_PokeballGlow, &gSpritePalette_HofMonitor } },
    [FLDEFF_USE_TELEPORT             ] = { FldEff_UseTeleport },
    [FLDEFF_RAYQUAZA_SPOTLIGHT       ] = { FldEff_RayquazaSpotlight },
    // Sin funcion a proposito: FldEff_MoveDeoxysRock recibe un struct Sprite *,
    // asi que el bytecode la llamaba con basura en el registro. Nadie la lanza.
    [FLDEFF_MOVE_DEOXYS_ROCK         ] = { NULL },
    [FLDEFF_USE_VS_SEEKER            ] = { FldEff_UseVsSeeker },
};

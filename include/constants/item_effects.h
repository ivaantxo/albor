#ifndef GUARD_CONSTANTS_ITEM_EFFECTS_H
#define GUARD_CONSTANTS_ITEM_EFFECTS_H

// field 0 masks
#define ITEM0_DIRE_HIT          0x30 // Works the same way as the move Focus Energy.
#define ITEM0_INFATUATION       0x80

// new field 1 masks
#define ITEM1_X_ATTACK          ESTADISTICA_ATAQUE
#define ITEM1_X_DEFENSE         ESTADISTICA_DEFENSA
#define ITEM1_X_SPEED           ESTADISTICA_VELOCIDAD
#define ITEM1_X_SPATK           ESTADISTICA_ATAQUE_ESPECIAL
#define ITEM1_X_SPDEF           ESTADISTICA_DEFENSA_ESPECIAL
#define ITEM1_X_ACCURACY        ESTADISTICA_PRECISION

// field 3 masks
#define ITEM3_CONFUSION         0x1
#define ITEM3_PARALYSIS         0x2
#define ITEM3_FREEZE            0x4
#define ITEM3_BURN              0x8
#define ITEM3_POISON            0x10
#define ITEM3_SLEEP             0x20
#define ITEM3_LEVEL_UP          0x40
#define ITEM3_GUARD_SPEC        0x80 // Works the same way as the move Mist.

#define ITEM3_STATUS_ALL        (ITEM3_CONFUSION | ITEM3_PARALYSIS | ITEM3_FREEZE | ITEM3_BURN | ITEM3_POISON | ITEM3_SLEEP)

//revisar field 4 y 5
// field 4 masks
#define ITEM4_EV_HP             1
#define ITEM4_EV_ATK            2
#define ITEM4_HEAL_HP           4
#define ITEM4_HEAL_PP           8
#define ITEM4_HEAL_PP_ONE       16
#define ITEM4_REVIVE            32
#define ITEM4_EVO_STONE         64

// field 5 masks
#define ITEM5_EV_DEF            1
#define ITEM5_EV_SPEED          2
#define ITEM5_EV_SPDEF          4
#define ITEM5_EV_SPATK          8
#define ITEM5_FRIENDSHIP_LOW    16
#define ITEM5_FRIENDSHIP_MID    32
#define ITEM5_FRIENDSHIP_HIGH   64

#define ITEM5_FRIENDSHIP_ALL    (ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID | ITEM5_FRIENDSHIP_HIGH)

#define ITEM10_IS_VITAMIN       0x1

// fields 6 and onwards (except field 10) are item-specific arguments
#define ITEM_EFFECT_ARG_START 6

// Special HP recovery amounts for ITEM4_HEAL_HP
#define ITEM6_HEAL_HP_FULL    ((u8) -1)
#define ITEM6_HEAL_HP_HALF    ((u8) -2)
#define ITEM6_HEAL_HP_LVL_UP  ((u8) -3)
#define ITEM6_HEAL_HP_QUARTER ((u8) -4)

// Special PP recovery amounts for ITEM4_HEAL_PP
#define ITEM6_HEAL_PP_FULL   0x7F

// Amount of EV modified by ITEM4_EV_HP, ITEM4_EV_ATK, ITEM5_EV_DEF, ITEM5_EV_SPEED, ITEM5_EV_SPDEF and ITEM5_EV_SPATK
#define ITEM6_ADD_EV       10
#define ITEM6_SUBTRACT_EV -10
#define ITEM6_ADD_ONE_EV    1
#define ITEM6_RESET_EV      0


enum EfectosObjetos
{
    ITEM_EFFECT_X_ITEM,
    ITEM_EFFECT_RAISE_LEVEL,
    ITEM_EFFECT_HEAL_HP,
    ITEM_EFFECT_CURE_POISON,
    ITEM_EFFECT_CURE_SLEEP,
    ITEM_EFFECT_CURE_BURN,
    EFECTO_OBJETO_CURA_CONGELACION,
    ITEM_EFFECT_CURE_PARALYSIS,
    ITEM_EFFECT_CURE_CONFUSION,
    ITEM_EFFECT_CURE_INFATUATION,
    ITEM_EFFECT_CURE_ALL_STATUS,
    ITEM_EFFECT_ATK_EV,
    ITEM_EFFECT_HP_EV,
    ITEM_EFFECT_SPATK_EV,
    ITEM_EFFECT_SPDEF_EV,
    ITEM_EFFECT_SPEED_EV,
    ITEM_EFFECT_DEF_EV,
    ITEM_EFFECT_EVO_STONE,
    ITEM_EFFECT_HEAL_PP,
    ITEM_EFFECT_NONE,
};

#endif // GUARD_CONSTANTS_ITEM_EFFECTS_H

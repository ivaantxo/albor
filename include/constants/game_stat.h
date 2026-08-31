#ifndef GUARD_CONSTANTS_GAME_STAT_H
#define GUARD_CONSTANTS_GAME_STAT_H

// Solo las que alguien incrementa o lee. Renumeradas desde cero: aqui no hay
// partidas viejas que respetar, y la firma del guardado se recalcula sola con
// el tamano de struct SaveBlock.
#define GAME_STAT_SAVED_GAME          0
#define GAME_STAT_PLANTED_BERRIES     1
#define GAME_STAT_STEPS               2
#define GAME_STAT_TOTAL_BATTLES       3
#define GAME_STAT_WILD_BATTLES        4
#define GAME_STAT_TRAINER_BATTLES     5
#define GAME_STAT_ENTERED_HOF         6
#define GAME_STAT_FISHING_ENCOUNTERS  7
#define GAME_STAT_HATCHED_EGGS        8
#define GAME_STAT_EVOLVED_POKEMON     9
#define GAME_STAT_USED_POKECENTER     10
#define GAME_STAT_USED_CUT            11
#define GAME_STAT_USED_ROCK_SMASH     12
#define GAME_STAT_USED_STRUGGLE       13
#define GAME_STAT_SHOPPED             14
#define GAME_STAT_USED_ITEMFINDER     15
#define GAME_STAT_GOT_RAINED_ON       16
#define GAME_STAT_CHECKED_POKEDEX     17
#define GAME_STAT_RECEIVED_RIBBONS    18
#define GAME_STAT_JUMPED_DOWN_LEDGES  19
#define GAME_STAT_USED_DAYCARE        20
#define GAME_STAT_POKEMON_CAPTURES    21

#define NUM_GAME_STATS                22

#endif // GUARD_CONSTANTS_GAME_STAT_H

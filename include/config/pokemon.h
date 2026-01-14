#ifndef GUARD_CONFIG_POKEMON_H
#define GUARD_CONFIG_POKEMON_H

// Evolution settings
#define P_FRIENDSHIP_EVO_THRESHOLD   GEN_LATEST  // Since Gen 8, Pokémon that evolve by friendship evolve at or above 160 friendship instead of 220.

// Breeding settings
#define P_NIDORAN_M_DITTO_BREED         GEN_LATEST  // Since Gen 5, when Nidoran♂ breeds with Ditto it can produce Nidoran♀ offspring. Before, it would only yield male offspring. This change also applies to Volbeat.
#define P_TM_INHERITANCE                GEN_LATEST  // Since Gen 6, the father no longer passes down TMs to the baby.
#define P_MOTHER_EGG_MOVE_INHERITANCE   GEN_LATEST  // Since Gen 6, the mother can also pass down Egg Moves.
#define P_EGG_MOVE_TRANSFER             GEN_8       // Starting in Gen 8, if two Pokémon of the same species are together in the Daycare, one knows an Egg Move, and the other has an empty slot, the other Pokémon will receive the Egg Move in the empty slot. In Gen 9, if a Pokémon holds a Mirror Herb, it will receive Egg Moves from the other regardless of species.

// Other settings
#define P_CAN_FORGET_HIDDEN_MOVE         FALSE       // If TRUE, Pokémon can forget any move, even if it is a Hidden Move.
#define P_SHOW_DYNAMIC_TYPES             FALSE       // If TRUE, moves with dynamic type changes will be reflected as their current type in battle/summary screens.
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  TRUE        // If TRUE, shows an option for Pokémon to relearn moves on the summary screen moves page.
#define P_SUMMARY_MOVE_RELEARNER_FULL_PP TRUE        // If TRUE, the move relearner in the summary screen restores relearned moves' PP to full.
#define P_SUMMARY_SCREEN_RENAME          TRUE        // If TRUE, an option to change Pokémon nicknames replaces the cancel prompt on the summary screen info page.

#endif // GUARD_CONFIG_POKEMON_H

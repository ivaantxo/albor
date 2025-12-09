#ifndef GUARD_CONFIG_GENERAL_H
#define GUARD_CONFIG_GENERAL_H

// Uncomment to fix some identified minor bugs
#define BUGFIX

#define UBFIX

// Generation constants used in configs to define behavior.
#define GEN_1 0
#define GEN_2 1
#define GEN_3 2
#define GEN_4 3
#define GEN_5 4
#define GEN_6 5
#define GEN_7 6
#define GEN_8 7
#define GEN_9 8
// Changing GEN_LATEST's value to a different Generation will change every default setting that uses it at once.
#define GEN_LATEST GEN_9

// General settings
#define EXPANSION_INTRO              TRUE    // If TRUE, a custom RHH intro will play after the vanilla copyright screen.
#define SUMMARY_SCREEN_NATURE_COLORS TRUE    // If TRUE, nature-based stat boosts and reductions will be red and blue in the summary screen.
#define COMPETITIVE_PARTY_SYNTAX     TRUE    // If TRUE, parties are defined in "competitive syntax".
#define AUTO_SCROLL_TEXT             TRUE    // If TRUE, text will automatically scroll to the next line after NUM_FRAMES_AUTO_SCROLL_DELAY. Players can still press A_BUTTON or B_BUTTON to scroll on their own.
#define NUM_FRAMES_AUTO_SCROLL_DELAY 30

#endif // GUARD_CONFIG_GENERAL_H

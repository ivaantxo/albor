#ifndef GUARD_CONFIG_GENERAL_H
#define GUARD_CONFIG_GENERAL_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
#define NDEBUG

// To enable printf debugging, comment out "#define NDEBUG". This allows
// the various AGBPrint functions to be used. (See include/gba/isagbprint.h).
// See below for enabling different pretty printing versions.

#ifndef NDEBUG

#define PRETTY_PRINT_MINI_PRINTF (0)
#define PRETTY_PRINT_LIBC (1)

#define LOG_HANDLER_AGB_PRINT (0)
#define LOG_HANDLER_NOCASH_PRINT (1)
#define LOG_HANDLER_MGBA_PRINT (2)

// Use this switch to choose a handler for pretty printing.
// NOTE: mini_printf supports a custom pretty printing formatter to display preproc encoded strings. (%S)
//       some libc distributions (especially dkp arm-libc) will fail to link pretty printing.
#define PRETTY_PRINT_HANDLER (PRETTY_PRINT_MINI_PRINTF)

// Use this switch to choose a handler for printf output.
// NOTE: These will only work on the respective emulators and should not be used in a productive environment.
//       Some emulators or real hardware might (and is allowed to) crash if they are used.
//       AGB_PRINT is supported on respective debug units.

#define LOG_HANDLER (LOG_HANDLER_MGBA_PRINT)
#endif

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

#define SAVE_TYPE_ERROR_SCREEN              FALSE   // When enabled, this shows an error message when the game is loaded on a cart without a flash chip or on an emulator with the wrong save type setting instead of crashing.
#endif // GUARD_CONFIG_GENERAL_H

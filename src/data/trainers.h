//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/trainers.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/trainers.h' to remove #line markers.
//

#line 1 "src/data/trainers.party"

#line 69
    [TRAINER_NONE] =
    {
#line 71
        .trainerClass = TRAINER_CLASS_HIKER,
#line 72
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 74
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 76
    [TRAINER_LANCE] =
    {
#line 77
        .trainerName = _("LANCE"),
#line 78
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 79
        .trainerPic = TRAINER_PIC_LANCE,
        .encounterMusic_gender = 
#line 81
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 82
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 84
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 85
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 87
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 88
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 90
    [TRAINER_CYNTHIA] =
    {
#line 91
        .trainerName = _("CYNTHIA"),
#line 92
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 93
        .trainerPic = TRAINER_PIC_CYNTHIA,
        .encounterMusic_gender = 
#line 94
F_TRAINER_FEMALE | 
#line 95
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 96
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 98
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 99
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 101
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 102
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },

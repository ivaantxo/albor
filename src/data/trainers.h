//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/trainers.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/trainers.h' to remove #line markers.
//

#line 1 "src/data/trainers.party"

#line 72
    [TRAINER_NONE] =
    {
#line 74
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 75
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 77
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 79
    [TRAINER_SAWYER_1] =
    {
#line 80
        .trainerName = _("SAWYER"),
#line 81
        .trainerClass = TRAINER_CLASS_HIKER,
#line 82
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 84
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 85
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 87
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 89
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 88
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 91
    [TRAINER_GRUNT_AQUA_HIDEOUT_1] =
    {
#line 92
        .trainerName = _("GRUNT"),
#line 93
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 94
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 96
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 97
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 99
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 101
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 100
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 103
    [TRAINER_GRUNT_AQUA_HIDEOUT_2] =
    {
#line 104
        .trainerName = _("GRUNT"),
#line 105
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 106
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 108
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 109
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 111
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 113
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 112
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 115
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 117
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 116
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 119
    [TRAINER_GRUNT_AQUA_HIDEOUT_3] =
    {
#line 120
        .trainerName = _("GRUNT"),
#line 121
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 122
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 124
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 125
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 127
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 129
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 128
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 131
    [TRAINER_GRUNT_AQUA_HIDEOUT_4] =
    {
#line 132
        .trainerName = _("GRUNT"),
#line 133
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 134
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 136
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 137
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 139
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 140
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 143
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_1] =
    {
#line 144
        .trainerName = _("GRUNT"),
#line 145
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 146
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 148
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 149
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 151
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 153
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 152
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 155
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_2] =
    {
#line 156
        .trainerName = _("GRUNT"),
#line 157
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 158
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 160
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 161
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 163
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 165
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 164
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 167
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_3] =
    {
#line 168
        .trainerName = _("GRUNT"),
#line 169
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 170
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 172
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 173
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 175
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 177
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 176
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 179
    [TRAINER_GABRIELLE_1] =
    {
#line 180
        .trainerName = _("GABRIELLE"),
#line 181
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 182
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 183
F_TRAINER_FEMALE | 
#line 184
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 185
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 187
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 189
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 188
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 191
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 193
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 192
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 195
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 197
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 196
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 199
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 201
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 200
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 203
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 205
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 204
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 207
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 209
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 208
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 211
    [TRAINER_GRUNT_PETALBURG_WOODS] =
    {
#line 212
        .trainerName = _("GRUNT"),
#line 213
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 214
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 216
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 217
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 219
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 221
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 220
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 223
    [TRAINER_MARCEL] =
    {
#line 224
        .trainerName = _("MARCEL"),
#line 225
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 226
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 228
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 229
        .items = { ITEM_HYPER_POTION },
#line 230
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 232
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 234
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 233
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 236
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 238
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 237
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 240
    [TRAINER_ALBERTO] =
    {
#line 241
        .trainerName = _("ALBERTO"),
#line 242
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 243
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 245
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 246
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 248
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 249
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 252
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 254
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 253
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 256
    [TRAINER_ED] =
    {
#line 257
        .trainerName = _("ED"),
#line 258
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 259
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 261
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 264
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 266
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 265
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 268
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 270
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 269
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 272
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_4] =
    {
#line 273
        .trainerName = _("GRUNT"),
#line 274
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 275
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 276
F_TRAINER_FEMALE | 
#line 277
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 278
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 280
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 282
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 281
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 284
    [TRAINER_DECLAN] =
    {
#line 285
        .trainerName = _("DECLAN"),
#line 286
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 287
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 289
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 290
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 292
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 294
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 293
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 296
    [TRAINER_GRUNT_RUSTURF_TUNNEL] =
    {
#line 297
        .trainerName = _("GRUNT"),
#line 298
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 299
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 301
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 302
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 304
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 305
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 308
    [TRAINER_GRUNT_WEATHER_INST_1] =
    {
#line 309
        .trainerName = _("GRUNT"),
#line 310
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 311
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 313
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 314
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 316
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 318
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 317
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 320
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 322
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 321
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 324
    [TRAINER_GRUNT_WEATHER_INST_2] =
    {
#line 325
        .trainerName = _("GRUNT"),
#line 326
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 327
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 329
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 330
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 332
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 334
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 333
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 336
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 338
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 337
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 340
    [TRAINER_GRUNT_WEATHER_INST_3] =
    {
#line 341
        .trainerName = _("GRUNT"),
#line 342
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 343
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 345
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 346
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 348
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 350
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 349
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 352
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 354
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 353
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 356
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 358
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 357
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 360
    [TRAINER_GRUNT_MUSEUM_1] =
    {
#line 361
        .trainerName = _("GRUNT"),
#line 362
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 363
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 365
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 366
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 368
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 370
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 369
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 372
    [TRAINER_GRUNT_MUSEUM_2] =
    {
#line 373
        .trainerName = _("GRUNT"),
#line 374
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 375
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 377
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 378
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 380
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 382
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 381
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 384
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 386
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 385
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 388
    [TRAINER_GRUNT_SPACE_CENTER_1] =
    {
#line 389
        .trainerName = _("GRUNT"),
#line 390
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 391
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 393
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 394
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 396
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 398
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 397
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 400
    [TRAINER_GRUNT_MT_PYRE_1] =
    {
#line 401
        .trainerName = _("GRUNT"),
#line 402
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 403
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 405
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 408
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 409
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 412
    [TRAINER_GRUNT_MT_PYRE_2] =
    {
#line 413
        .trainerName = _("GRUNT"),
#line 414
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 415
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 417
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 418
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 420
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 422
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 421
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 424
    [TRAINER_GRUNT_MT_PYRE_3] =
    {
#line 425
        .trainerName = _("GRUNT"),
#line 426
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 427
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 429
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 430
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 432
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 434
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 433
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 436
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 438
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 437
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 440
    [TRAINER_GRUNT_WEATHER_INST_4] =
    {
#line 441
        .trainerName = _("GRUNT"),
#line 442
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 443
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 444
F_TRAINER_FEMALE | 
#line 445
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 446
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 448
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 450
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 449
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 452
    [TRAINER_GRUNT_AQUA_HIDEOUT_5] =
    {
#line 453
        .trainerName = _("GRUNT"),
#line 454
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 455
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 456
F_TRAINER_FEMALE | 
#line 457
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 458
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 460
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 462
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 461
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 464
    [TRAINER_GRUNT_AQUA_HIDEOUT_6] =
    {
#line 465
        .trainerName = _("GRUNT"),
#line 466
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 467
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 468
F_TRAINER_FEMALE | 
#line 469
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 470
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 472
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 474
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 473
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 476
    [TRAINER_FREDRICK] =
    {
#line 477
        .trainerName = _("FREDRICK"),
#line 478
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 479
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 481
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 482
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 484
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 486
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 485
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 488
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 490
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 489
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 492
    [TRAINER_MATT] =
    {
#line 493
        .trainerName = _("MATT"),
#line 494
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 495
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_M,
        .encounterMusic_gender = 
#line 497
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 498
        .items = { ITEM_SUPER_POTION },
#line 499
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 501
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 503
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 502
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 505
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 507
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 506
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 509
    [TRAINER_ZANDER] =
    {
#line 510
        .trainerName = _("ZANDER"),
#line 511
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 512
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 514
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 515
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 517
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 518
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 521
    [TRAINER_SHELLY_WEATHER_INSTITUTE] =
    {
#line 522
        .trainerName = _("SHELLY"),
#line 523
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 524
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender = 
#line 525
F_TRAINER_FEMALE | 
#line 526
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 527
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 529
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 531
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 530
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 533
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 535
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 534
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 537
    [TRAINER_SHELLY_SEAFLOOR_CAVERN] =
    {
#line 538
        .trainerName = _("SHELLY"),
#line 539
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 540
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender = 
#line 541
F_TRAINER_FEMALE | 
#line 542
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 543
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 545
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 547
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 546
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 549
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 551
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 550
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 553
    [TRAINER_ARCHIE] =
    {
#line 554
        .trainerName = _("ARCHIE"),
#line 555
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
#line 556
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .encounterMusic_gender = 
#line 558
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 559
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 560
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 562
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 564
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 563
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 566
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 568
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 567
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 570
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 572
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 571
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 574
    [TRAINER_LEAH] =
    {
#line 575
        .trainerName = _("LEAH"),
#line 576
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 577
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 578
F_TRAINER_FEMALE | 
#line 579
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 582
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 583
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 586
    [TRAINER_DAISY] =
    {
#line 587
        .trainerName = _("DAISY"),
#line 588
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 589
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 590
F_TRAINER_FEMALE | 
#line 591
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 594
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 595
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 598
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 600
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 599
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 602
    [TRAINER_ROSE_1] =
    {
#line 603
        .trainerName = _("ROSE"),
#line 604
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 605
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 606
F_TRAINER_FEMALE | 
#line 607
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 610
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 611
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 614
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 615
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 618
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 620
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 619
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 622
    [TRAINER_FELIX] =
    {
#line 623
        .trainerName = _("FELIX"),
#line 624
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 625
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 627
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 628
        .items = { ITEM_FULL_RESTORE },
#line 629
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 631
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 632
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 634
                MOVE_PSYCHIC,
            },
            },
            {
#line 636
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 638
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 637
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 639
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 642
    [TRAINER_VIOLET] =
    {
#line 643
        .trainerName = _("VIOLET"),
#line 644
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 645
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 646
F_TRAINER_FEMALE | 
#line 647
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 648
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 650
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 652
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 651
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 654
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 655
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 658
    [TRAINER_ROSE_2] =
    {
#line 659
        .trainerName = _("ROSE"),
#line 660
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 661
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 662
F_TRAINER_FEMALE | 
#line 663
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 664
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 666
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 668
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 667
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 670
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 672
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 671
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 674
    [TRAINER_ROSE_3] =
    {
#line 675
        .trainerName = _("ROSE"),
#line 676
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 677
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 678
F_TRAINER_FEMALE | 
#line 679
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 680
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 682
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 684
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 683
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 686
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 688
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 687
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 690
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 692
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 691
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 694
    [TRAINER_ROSE_4] =
    {
#line 695
        .trainerName = _("ROSE"),
#line 696
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 697
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 698
F_TRAINER_FEMALE | 
#line 699
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 700
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 702
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 704
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 703
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 706
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 708
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 707
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 710
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 712
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 711
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 714
    [TRAINER_ROSE_5] =
    {
#line 715
        .trainerName = _("ROSE"),
#line 716
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 717
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 718
F_TRAINER_FEMALE | 
#line 719
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 720
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 722
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 724
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 723
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 726
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 728
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 727
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 730
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 732
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 731
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 734
    [TRAINER_DUSTY_1] =
    {
#line 735
        .trainerName = _("DUSTY"),
#line 736
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 737
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 739
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 740
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 742
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 744
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 743
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 745
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 750
    [TRAINER_CHIP] =
    {
#line 751
        .trainerName = _("CHIP"),
#line 752
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 753
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 755
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 756
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 758
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 760
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 759
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 761
                MOVE_PSYBEAM,
                MOVE_SELF_DESTRUCT,
                MOVE_SANDSTORM,
                MOVE_ANCIENT_POWER,
            },
            },
            {
#line 766
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 768
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 767
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 769
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 774
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 776
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 775
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 777
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 782
    [TRAINER_FOSTER] =
    {
#line 783
        .trainerName = _("FOSTER"),
#line 784
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 785
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 787
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 788
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 790
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 792
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 791
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 793
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 798
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 800
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 799
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 801
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 806
    [TRAINER_DUSTY_2] =
    {
#line 807
        .trainerName = _("DUSTY"),
#line 808
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 809
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 811
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 812
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 814
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 816
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 815
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 817
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 822
    [TRAINER_DUSTY_3] =
    {
#line 823
        .trainerName = _("DUSTY"),
#line 824
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 825
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 827
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 828
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 830
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 832
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 831
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 833
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 838
    [TRAINER_DUSTY_4] =
    {
#line 839
        .trainerName = _("DUSTY"),
#line 840
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 841
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 843
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 844
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 846
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 848
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 847
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 849
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 854
    [TRAINER_DUSTY_5] =
    {
#line 855
        .trainerName = _("DUSTY"),
#line 856
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 857
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 859
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 860
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 862
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 864
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 863
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 865
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 870
    [TRAINER_GABBY_AND_TY_1] =
    {
#line 871
        .trainerName = _("GABBY & TY"),
#line 872
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 873
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 875
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 876
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 878
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 880
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 879
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 882
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 884
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 883
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 886
    [TRAINER_GABBY_AND_TY_2] =
    {
#line 887
        .trainerName = _("GABBY & TY"),
#line 888
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 889
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 891
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 892
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 894
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 896
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 895
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 898
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 900
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 899
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 902
    [TRAINER_GABBY_AND_TY_3] =
    {
#line 903
        .trainerName = _("GABBY & TY"),
#line 904
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 905
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 907
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 908
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 910
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 912
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 911
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 914
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 916
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 915
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 918
    [TRAINER_GABBY_AND_TY_4] =
    {
#line 919
        .trainerName = _("GABBY & TY"),
#line 920
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 921
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 923
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 926
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 928
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 927
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 930
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 932
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 931
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 934
    [TRAINER_GABBY_AND_TY_5] =
    {
#line 935
        .trainerName = _("GABBY & TY"),
#line 936
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 937
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 939
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 942
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 944
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 943
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 946
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 948
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 947
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 950
    [TRAINER_GABBY_AND_TY_6] =
    {
#line 951
        .trainerName = _("GABBY & TY"),
#line 952
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 953
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 955
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 958
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 960
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 959
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 961
                MOVE_SONIC_BOOM,
                MOVE_THUNDER_WAVE,
                MOVE_METAL_SOUND,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 966
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 968
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 967
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 969
                MOVE_ASTONISH,
                MOVE_STOMP,
                MOVE_SUPERSONIC,
                MOVE_HYPER_VOICE,
            },
            },
        },
    },
#line 974
    [TRAINER_LOLA_1] =
    {
#line 975
        .trainerName = _("LOLA"),
#line 976
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 977
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 978
F_TRAINER_FEMALE | 
#line 979
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 982
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 984
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 983
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 986
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 988
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 987
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 990
    [TRAINER_AUSTINA] =
    {
#line 991
        .trainerName = _("AUSTINA"),
#line 992
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 993
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 994
F_TRAINER_FEMALE | 
#line 995
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 998
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1000
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 999
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1002
    [TRAINER_GWEN] =
    {
#line 1003
        .trainerName = _("GWEN"),
#line 1004
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 1005
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 1006
F_TRAINER_FEMALE | 
#line 1007
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1010
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1012
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1011
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1014
    [TRAINER_LOLA_2] =
    {
#line 1015
        .trainerName = _("LOLA"),
#line 1016
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 1017
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 1018
F_TRAINER_FEMALE | 
#line 1019
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1020
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1022
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1024
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1023
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1026
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1028
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1027
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1030
    [TRAINER_LOLA_3] =
    {
#line 1031
        .trainerName = _("LOLA"),
#line 1032
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 1033
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 1034
F_TRAINER_FEMALE | 
#line 1035
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1036
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1038
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1040
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1039
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1042
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1044
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1043
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1046
    [TRAINER_LOLA_4] =
    {
#line 1047
        .trainerName = _("LOLA"),
#line 1048
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 1049
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 1050
F_TRAINER_FEMALE | 
#line 1051
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1052
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1054
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1056
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1055
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1058
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1060
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1059
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1062
    [TRAINER_LOLA_5] =
    {
#line 1063
        .trainerName = _("LOLA"),
#line 1064
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 1065
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 1066
F_TRAINER_FEMALE | 
#line 1067
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1070
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1072
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1071
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1074
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1076
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1075
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1078
    [TRAINER_RICKY_1] =
    {
#line 1079
        .trainerName = _("RICKY"),
#line 1080
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1081
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1083
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1084
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1086
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1088
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1087
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1089
                MOVE_SAND_ATTACK,
                MOVE_HEADBUTT,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1094
    [TRAINER_SIMON] =
    {
#line 1095
        .trainerName = _("SIMON"),
#line 1096
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1097
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1099
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1102
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1104
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1103
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1106
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1108
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1107
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1110
    [TRAINER_CHARLIE] =
    {
#line 1111
        .trainerName = _("CHARLIE"),
#line 1112
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1113
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1115
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1116
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1118
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1120
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1119
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1122
    [TRAINER_RICKY_2] =
    {
#line 1123
        .trainerName = _("RICKY"),
#line 1124
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1125
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1127
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1128
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1130
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1132
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1131
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1133
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1138
    [TRAINER_RICKY_3] =
    {
#line 1139
        .trainerName = _("RICKY"),
#line 1140
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1141
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1143
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1144
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1146
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1148
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1147
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1149
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1154
    [TRAINER_RICKY_4] =
    {
#line 1155
        .trainerName = _("RICKY"),
#line 1156
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1157
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1159
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1160
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1162
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1164
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1163
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1165
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1170
    [TRAINER_RICKY_5] =
    {
#line 1171
        .trainerName = _("RICKY"),
#line 1172
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1173
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1175
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1176
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1178
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1180
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1179
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1181
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1186
    [TRAINER_RANDALL] =
    {
#line 1187
        .trainerName = _("RANDALL"),
#line 1188
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1189
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1191
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1192
        .items = { ITEM_HYPER_POTION },
#line 1193
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1195
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1197
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1196
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1198
                MOVE_QUICK_ATTACK,
                MOVE_AGILITY,
                MOVE_WING_ATTACK,
            },
            },
        },
    },
#line 1202
    [TRAINER_PARKER] =
    {
#line 1203
        .trainerName = _("PARKER"),
#line 1204
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1205
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1207
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1208
        .items = { ITEM_HYPER_POTION },
#line 1209
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1211
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1213
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1212
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1214
                MOVE_TEETER_DANCE,
                MOVE_DIZZY_PUNCH,
                MOVE_FOCUS_PUNCH,
            },
            },
        },
    },
#line 1218
    [TRAINER_GEORGE] =
    {
#line 1219
        .trainerName = _("GEORGE"),
#line 1220
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1221
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1223
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1224
        .items = { ITEM_HYPER_POTION },
#line 1225
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1227
            .species = SPECIES_SLAKOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1227
            .heldItem = ITEM_SITRUS_BERRY,
#line 1229
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1228
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1230
                MOVE_SLACK_OFF,
                MOVE_COUNTER,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 1234
    [TRAINER_BERKE] =
    {
#line 1235
        .trainerName = _("BERKE"),
#line 1236
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1237
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1239
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1240
        .items = { ITEM_HYPER_POTION },
#line 1241
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1243
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1245
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1244
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1246
                MOVE_FOCUS_ENERGY,
                MOVE_SLASH,
            },
            },
        },
    },
#line 1249
    [TRAINER_BRAXTON] =
    {
#line 1250
        .trainerName = _("BRAXTON"),
#line 1251
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1252
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1254
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1255
        .items = { ITEM_HYPER_POTION },
#line 1256
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1258
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1260
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1259
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1261
                MOVE_FOCUS_ENERGY,
                MOVE_QUICK_ATTACK,
                MOVE_WING_ATTACK,
                MOVE_ENDEAVOR,
            },
            },
            {
#line 1266
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1268
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1267
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1269
                MOVE_BITE,
                MOVE_DIG,
                MOVE_FEINT_ATTACK,
                MOVE_SAND_TOMB,
            },
            },
            {
#line 1274
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1276
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1275
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1277
                MOVE_ROLLOUT,
                MOVE_WHIRLPOOL,
                MOVE_ASTONISH,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 1282
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1284
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1283
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1285
                MOVE_THUNDERBOLT,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 1290
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1292
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1291
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1293
                MOVE_GIGA_DRAIN,
                MOVE_FEINT_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 1298
    [TRAINER_VINCENT] =
    {
#line 1299
        .trainerName = _("VINCENT"),
#line 1300
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1301
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1303
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1304
        .items = { ITEM_FULL_RESTORE },
#line 1305
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1307
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1309
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1308
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1311
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1313
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1312
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1315
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1317
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1316
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1319
    [TRAINER_LEROY] =
    {
#line 1320
        .trainerName = _("LEROY"),
#line 1321
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1322
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1324
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1325
        .items = { ITEM_FULL_RESTORE },
#line 1326
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1328
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1330
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1329
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1332
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1334
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1333
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1336
    [TRAINER_WILTON_1] =
    {
#line 1337
        .trainerName = _("WILTON"),
#line 1338
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1339
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1341
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1342
        .items = { ITEM_SUPER_POTION },
#line 1343
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1345
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1347
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1346
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1349
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1351
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1350
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1353
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1355
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1354
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1357
    [TRAINER_EDGAR] =
    {
#line 1358
        .trainerName = _("EDGAR"),
#line 1359
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1360
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1362
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1363
        .items = { ITEM_FULL_RESTORE },
#line 1364
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1366
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1368
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1367
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1370
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1372
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1371
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1374
    [TRAINER_ALBERT] =
    {
#line 1375
        .trainerName = _("ALBERT"),
#line 1376
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1377
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1379
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1380
        .items = { ITEM_FULL_RESTORE },
#line 1381
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1383
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1385
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1384
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1387
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1389
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1388
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1391
    [TRAINER_SAMUEL] =
    {
#line 1392
        .trainerName = _("SAMUEL"),
#line 1393
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1394
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1396
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1397
        .items = { ITEM_FULL_RESTORE },
#line 1398
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1400
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1402
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1401
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1404
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1406
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1405
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1408
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1410
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1409
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1412
    [TRAINER_VITO] =
    {
#line 1413
        .trainerName = _("VITO"),
#line 1414
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1415
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1417
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1418
        .items = { ITEM_FULL_RESTORE },
#line 1419
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1421
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1423
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1422
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1425
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1427
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1426
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1429
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1431
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1430
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1433
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1435
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1434
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1437
    [TRAINER_OWEN] =
    {
#line 1438
        .trainerName = _("OWEN"),
#line 1439
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1440
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1442
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1443
        .items = { ITEM_FULL_RESTORE },
#line 1444
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1446
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1448
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1447
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1450
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1452
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1451
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1454
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1456
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1455
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1458
    [TRAINER_WILTON_2] =
    {
#line 1459
        .trainerName = _("WILTON"),
#line 1460
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1461
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1463
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1464
        .items = { ITEM_HYPER_POTION },
#line 1465
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1467
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1469
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1468
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1471
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1473
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1472
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1475
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1477
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1476
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1479
    [TRAINER_WILTON_3] =
    {
#line 1480
        .trainerName = _("WILTON"),
#line 1481
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1482
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1484
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1485
        .items = { ITEM_HYPER_POTION },
#line 1486
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1488
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1490
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1489
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1492
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1494
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1493
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1496
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1498
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1497
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1500
    [TRAINER_WILTON_4] =
    {
#line 1501
        .trainerName = _("WILTON"),
#line 1502
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1503
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1505
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1506
        .items = { ITEM_FULL_RESTORE },
#line 1507
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1509
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1511
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1510
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1513
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1515
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1514
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1517
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1519
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1518
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1521
    [TRAINER_WILTON_5] =
    {
#line 1522
        .trainerName = _("WILTON"),
#line 1523
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1524
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1526
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1527
        .items = { ITEM_FULL_RESTORE },
#line 1528
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1530
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1532
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1531
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1534
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1536
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1535
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1538
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1540
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1539
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1542
    [TRAINER_WARREN] =
    {
#line 1543
        .trainerName = _("WARREN"),
#line 1544
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1545
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1547
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1548
        .items = { ITEM_FULL_RESTORE },
#line 1549
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1551
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1553
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1552
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1555
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1557
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1556
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1559
    [TRAINER_MARY] =
    {
#line 1560
        .trainerName = _("MARY"),
#line 1561
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1562
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1563
F_TRAINER_FEMALE | 
#line 1564
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1565
        .items = { ITEM_HYPER_POTION },
#line 1566
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1568
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1570
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1569
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1571
                MOVE_FEINT_ATTACK,
                MOVE_SHOCK_WAVE,
            },
            },
        },
    },
#line 1574
    [TRAINER_ALEXIA] =
    {
#line 1575
        .trainerName = _("ALEXIA"),
#line 1576
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1577
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1578
F_TRAINER_FEMALE | 
#line 1579
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1580
        .items = { ITEM_HYPER_POTION },
#line 1581
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1583
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1585
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1584
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1586
                MOVE_DEFENSE_CURL,
                MOVE_DOUBLE_EDGE,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 1590
    [TRAINER_JODY] =
    {
#line 1591
        .trainerName = _("JODY"),
#line 1592
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1593
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1594
F_TRAINER_FEMALE | 
#line 1595
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1596
        .items = { ITEM_HYPER_POTION },
#line 1597
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1599
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1601
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1600
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1602
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
#line 1605
    [TRAINER_WENDY] =
    {
#line 1606
        .trainerName = _("WENDY"),
#line 1607
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1608
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1609
F_TRAINER_FEMALE | 
#line 1610
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1611
        .items = { ITEM_FULL_RESTORE },
#line 1612
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1614
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1616
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1615
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1617
                MOVE_BATON_PASS,
                MOVE_FEINT_ATTACK,
                MOVE_FAKE_TEARS,
                MOVE_BITE,
            },
            },
            {
#line 1622
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1624
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1623
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1625
                MOVE_MEGA_DRAIN,
                MOVE_MAGICAL_LEAF,
                MOVE_GRASS_WHISTLE,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 1630
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1632
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1631
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1633
                MOVE_FLY,
                MOVE_WATER_GUN,
                MOVE_MIST,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 1638
    [TRAINER_KEIRA] =
    {
#line 1639
        .trainerName = _("KEIRA"),
#line 1640
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1641
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1642
F_TRAINER_FEMALE | 
#line 1643
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1644
        .items = { ITEM_FULL_RESTORE },
#line 1645
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1647
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1649
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1648
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1651
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1653
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1652
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1655
    [TRAINER_BROOKE_1] =
    {
#line 1656
        .trainerName = _("BROOKE"),
#line 1657
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1658
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1659
F_TRAINER_FEMALE | 
#line 1660
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1661
        .items = { ITEM_SUPER_POTION },
#line 1662
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1664
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1666
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1665
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1668
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1670
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1669
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1672
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1674
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1673
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1676
    [TRAINER_JENNIFER] =
    {
#line 1677
        .trainerName = _("JENNIFER"),
#line 1678
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1679
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1680
F_TRAINER_FEMALE | 
#line 1681
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1682
        .items = { ITEM_FULL_RESTORE },
#line 1683
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1685
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1687
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 1686
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1689
    [TRAINER_HOPE] =
    {
#line 1690
        .trainerName = _("HOPE"),
#line 1691
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1692
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1693
F_TRAINER_FEMALE | 
#line 1694
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1695
        .items = { ITEM_FULL_RESTORE },
#line 1696
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1698
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1700
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1699
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1702
    [TRAINER_SHANNON] =
    {
#line 1703
        .trainerName = _("SHANNON"),
#line 1704
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1705
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1706
F_TRAINER_FEMALE | 
#line 1707
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1708
        .items = { ITEM_FULL_RESTORE },
#line 1709
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1711
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1713
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1712
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1715
    [TRAINER_MICHELLE] =
    {
#line 1716
        .trainerName = _("MICHELLE"),
#line 1717
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1718
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1719
F_TRAINER_FEMALE | 
#line 1720
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1721
        .items = { ITEM_FULL_RESTORE },
#line 1722
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1724
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1726
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1725
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1728
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1730
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1729
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1732
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1734
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1733
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1736
    [TRAINER_CAROLINE] =
    {
#line 1737
        .trainerName = _("CAROLINE"),
#line 1738
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1739
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1740
F_TRAINER_FEMALE | 
#line 1741
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1742
        .items = { ITEM_FULL_RESTORE },
#line 1743
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1745
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1747
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1746
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1749
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1751
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1750
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1753
    [TRAINER_JULIE] =
    {
#line 1754
        .trainerName = _("JULIE"),
#line 1755
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1756
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1757
F_TRAINER_FEMALE | 
#line 1758
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1759
        .items = { ITEM_FULL_RESTORE },
#line 1760
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1762
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1764
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1763
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1766
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1768
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1767
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1770
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1772
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1771
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1774
    [TRAINER_BROOKE_2] =
    {
#line 1775
        .trainerName = _("BROOKE"),
#line 1776
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1777
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1778
F_TRAINER_FEMALE | 
#line 1779
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1780
        .items = { ITEM_HYPER_POTION },
#line 1781
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1783
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1785
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1784
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1787
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1789
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1788
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1791
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1793
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1792
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1795
    [TRAINER_BROOKE_3] =
    {
#line 1796
        .trainerName = _("BROOKE"),
#line 1797
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1798
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1799
F_TRAINER_FEMALE | 
#line 1800
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1801
        .items = { ITEM_HYPER_POTION },
#line 1802
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1804
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1806
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1805
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1808
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1810
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1809
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1812
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1814
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1813
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1816
    [TRAINER_BROOKE_4] =
    {
#line 1817
        .trainerName = _("BROOKE"),
#line 1818
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1819
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1820
F_TRAINER_FEMALE | 
#line 1821
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1822
        .items = { ITEM_FULL_RESTORE },
#line 1823
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1825
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1827
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1826
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1829
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1831
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1830
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1833
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1835
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1834
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1837
    [TRAINER_BROOKE_5] =
    {
#line 1838
        .trainerName = _("BROOKE"),
#line 1839
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1840
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1841
F_TRAINER_FEMALE | 
#line 1842
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1843
        .items = { ITEM_FULL_RESTORE },
#line 1844
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1846
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1848
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1847
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1850
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1852
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1851
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1854
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1856
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1855
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1858
    [TRAINER_PATRICIA] =
    {
#line 1859
        .trainerName = _("PATRICIA"),
#line 1860
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1861
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1862
F_TRAINER_FEMALE | 
#line 1863
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1866
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1867
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1870
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1872
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1871
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1874
    [TRAINER_KINDRA] =
    {
#line 1875
        .trainerName = _("KINDRA"),
#line 1876
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1877
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1878
F_TRAINER_FEMALE | 
#line 1879
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1882
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1884
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1883
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1886
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1888
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1887
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1890
    [TRAINER_TAMMY] =
    {
#line 1891
        .trainerName = _("TAMMY"),
#line 1892
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1893
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1894
F_TRAINER_FEMALE | 
#line 1895
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1898
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1900
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1899
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1902
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1904
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1903
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1906
    [TRAINER_VALERIE_1] =
    {
#line 1907
        .trainerName = _("VALERIE"),
#line 1908
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1909
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1910
F_TRAINER_FEMALE | 
#line 1911
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1912
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1914
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1916
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1915
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1918
    [TRAINER_TASHA] =
    {
#line 1919
        .trainerName = _("TASHA"),
#line 1920
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1921
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1922
F_TRAINER_FEMALE | 
#line 1923
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1926
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1928
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 1927
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1930
    [TRAINER_VALERIE_2] =
    {
#line 1931
        .trainerName = _("VALERIE"),
#line 1932
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1933
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1934
F_TRAINER_FEMALE | 
#line 1935
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1936
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1938
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1940
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1939
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1942
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1944
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1943
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1946
    [TRAINER_VALERIE_3] =
    {
#line 1947
        .trainerName = _("VALERIE"),
#line 1948
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1949
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1950
F_TRAINER_FEMALE | 
#line 1951
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1952
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1954
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1956
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1955
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1958
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1960
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1959
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1962
    [TRAINER_VALERIE_4] =
    {
#line 1963
        .trainerName = _("VALERIE"),
#line 1964
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1965
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1966
F_TRAINER_FEMALE | 
#line 1967
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1970
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1972
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1971
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1974
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1976
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1975
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1978
    [TRAINER_VALERIE_5] =
    {
#line 1979
        .trainerName = _("VALERIE"),
#line 1980
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1981
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1982
F_TRAINER_FEMALE | 
#line 1983
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1984
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1986
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1988
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1987
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1990
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1992
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1991
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1994
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1996
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1995
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1998
    [TRAINER_CINDY_1] =
    {
#line 1999
        .trainerName = _("CINDY"),
#line 2000
        .trainerClass = TRAINER_CLASS_LADY,
#line 2001
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2002
F_TRAINER_FEMALE | 
#line 2003
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2004
        .items = { ITEM_FULL_RESTORE },
#line 2005
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2007
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2007
            .heldItem = ITEM_NUGGET,
#line 2009
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2008
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2011
    [TRAINER_DAPHNE] =
    {
#line 2012
        .trainerName = _("DAPHNE"),
#line 2013
        .trainerClass = TRAINER_CLASS_LADY,
#line 2014
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2015
F_TRAINER_FEMALE | 
#line 2016
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2017
        .items = { ITEM_FULL_RESTORE },
#line 2018
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2020
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2020
            .heldItem = ITEM_NUGGET,
#line 2022
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2021
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2023
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 2028
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2028
            .heldItem = ITEM_NUGGET,
#line 2030
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2029
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2031
                MOVE_ATTRACT,
                MOVE_SAFEGUARD,
                MOVE_TAKE_DOWN,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 2036
    [TRAINER_GRUNT_SPACE_CENTER_2] =
    {
#line 2037
        .trainerName = _("GRUNT"),
#line 2038
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 2039
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 2041
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 2042
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2044
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2046
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2045
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2048
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2050
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2049
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2052
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2054
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2053
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2056
    [TRAINER_CINDY_2] =
    {
#line 2057
        .trainerName = _("CINDY"),
#line 2058
        .trainerClass = TRAINER_CLASS_LADY,
#line 2059
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2060
F_TRAINER_FEMALE | 
#line 2061
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2062
        .items = { ITEM_FULL_RESTORE },
#line 2063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2065
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2065
            .heldItem = ITEM_NUGGET,
#line 2067
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2066
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2068
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 2071
    [TRAINER_BRIANNA] =
    {
#line 2072
        .trainerName = _("BRIANNA"),
#line 2073
        .trainerClass = TRAINER_CLASS_LADY,
#line 2074
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2075
F_TRAINER_FEMALE | 
#line 2076
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2077
        .items = { ITEM_FULL_RESTORE },
#line 2078
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2080
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2080
            .heldItem = ITEM_NUGGET,
#line 2082
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 2081
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2084
    [TRAINER_NAOMI] =
    {
#line 2085
        .trainerName = _("NAOMI"),
#line 2086
        .trainerClass = TRAINER_CLASS_LADY,
#line 2087
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2088
F_TRAINER_FEMALE | 
#line 2089
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2090
        .items = { ITEM_FULL_RESTORE },
#line 2091
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2093
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2093
            .heldItem = ITEM_NUGGET,
#line 2095
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2094
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2097
    [TRAINER_CINDY_3] =
    {
#line 2098
        .trainerName = _("CINDY"),
#line 2099
        .trainerClass = TRAINER_CLASS_LADY,
#line 2100
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2101
F_TRAINER_FEMALE | 
#line 2102
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2103
        .items = { ITEM_FULL_RESTORE },
#line 2104
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2106
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2106
            .heldItem = ITEM_NUGGET,
#line 2108
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2107
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2110
    [TRAINER_CINDY_4] =
    {
#line 2111
        .trainerName = _("CINDY"),
#line 2112
        .trainerClass = TRAINER_CLASS_LADY,
#line 2113
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2114
F_TRAINER_FEMALE | 
#line 2115
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2116
        .items = { ITEM_FULL_RESTORE },
#line 2117
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2119
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2119
            .heldItem = ITEM_NUGGET,
#line 2121
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2120
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2123
    [TRAINER_CINDY_5] =
    {
#line 2124
        .trainerName = _("CINDY"),
#line 2125
        .trainerClass = TRAINER_CLASS_LADY,
#line 2126
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2127
F_TRAINER_FEMALE | 
#line 2128
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2129
        .items = { ITEM_FULL_RESTORE },
#line 2130
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2132
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2132
            .heldItem = ITEM_NUGGET,
#line 2134
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2133
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2136
    [TRAINER_CINDY_6] =
    {
#line 2137
        .trainerName = _("CINDY"),
#line 2138
        .trainerClass = TRAINER_CLASS_LADY,
#line 2139
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2140
F_TRAINER_FEMALE | 
#line 2141
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2142
        .items = { ITEM_FULL_RESTORE },
#line 2143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2145
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2145
            .heldItem = ITEM_NUGGET,
#line 2147
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2146
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2148
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 2153
    [TRAINER_MELISSA] =
    {
#line 2154
        .trainerName = _("MELISSA"),
#line 2155
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2156
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2157
F_TRAINER_FEMALE | 
#line 2158
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2159
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2161
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2162
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2165
    [TRAINER_SHEILA] =
    {
#line 2166
        .trainerName = _("SHEILA"),
#line 2167
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2168
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2169
F_TRAINER_FEMALE | 
#line 2170
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2173
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2174
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2177
    [TRAINER_SHIRLEY] =
    {
#line 2178
        .trainerName = _("SHIRLEY"),
#line 2179
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2180
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2181
F_TRAINER_FEMALE | 
#line 2182
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2183
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2185
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2186
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2189
    [TRAINER_JESSICA_1] =
    {
#line 2190
        .trainerName = _("JESSICA"),
#line 2191
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2192
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2193
F_TRAINER_FEMALE | 
#line 2194
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2197
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2198
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2200
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2205
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2207
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2206
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2208
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2213
    [TRAINER_CONNIE] =
    {
#line 2214
        .trainerName = _("CONNIE"),
#line 2215
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2216
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2217
F_TRAINER_FEMALE | 
#line 2218
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2221
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2223
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2222
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2225
    [TRAINER_BRIDGET] =
    {
#line 2226
        .trainerName = _("BRIDGET"),
#line 2227
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2228
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2229
F_TRAINER_FEMALE | 
#line 2230
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2231
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2233
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2235
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 2234
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2237
    [TRAINER_OLIVIA] =
    {
#line 2238
        .trainerName = _("OLIVIA"),
#line 2239
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2240
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2241
F_TRAINER_FEMALE | 
#line 2242
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2243
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2245
            .species = SPECIES_CLAMPERL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2247
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2246
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2248
                MOVE_IRON_DEFENSE,
                MOVE_WHIRLPOOL,
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 2253
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2255
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2254
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2256
                MOVE_TAUNT,
                MOVE_CRABHAMMER,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 2260
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2262
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2261
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2263
                MOVE_UPROAR,
                MOVE_FURY_SWIPES,
                MOVE_FAKE_OUT,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 2268
    [TRAINER_TIFFANY] =
    {
#line 2269
        .trainerName = _("TIFFANY"),
#line 2270
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2271
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2272
F_TRAINER_FEMALE | 
#line 2273
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2274
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2276
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2278
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2277
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2280
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2282
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2281
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2284
    [TRAINER_JESSICA_2] =
    {
#line 2285
        .trainerName = _("JESSICA"),
#line 2286
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2287
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2288
F_TRAINER_FEMALE | 
#line 2289
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2290
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2292
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2294
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2293
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2295
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2300
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2302
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2301
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2303
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2308
    [TRAINER_JESSICA_3] =
    {
#line 2309
        .trainerName = _("JESSICA"),
#line 2310
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2311
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2312
F_TRAINER_FEMALE | 
#line 2313
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2314
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2316
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2318
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2317
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2319
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2324
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2326
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2325
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2327
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2332
    [TRAINER_JESSICA_4] =
    {
#line 2333
        .trainerName = _("JESSICA"),
#line 2334
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2335
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2336
F_TRAINER_FEMALE | 
#line 2337
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2338
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2340
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2342
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2341
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2343
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2348
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2350
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2349
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2351
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2356
    [TRAINER_JESSICA_5] =
    {
#line 2357
        .trainerName = _("JESSICA"),
#line 2358
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2359
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2360
F_TRAINER_FEMALE | 
#line 2361
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2362
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2364
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2366
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2365
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2367
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2372
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2374
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2373
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2375
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2380
    [TRAINER_WINSTON_1] =
    {
#line 2381
        .trainerName = _("WINSTON"),
#line 2382
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2383
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2385
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2386
        .items = { ITEM_FULL_RESTORE },
#line 2387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2389
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2389
            .heldItem = ITEM_NUGGET,
#line 2391
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2390
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2393
    [TRAINER_MOLLIE] =
    {
#line 2394
        .trainerName = _("MOLLIE"),
#line 2395
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 2396
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 2397
F_TRAINER_FEMALE | 
#line 2398
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2399
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2401
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2403
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2402
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2405
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2407
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 2406
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2409
    [TRAINER_GARRET] =
    {
#line 2410
        .trainerName = _("GARRET"),
#line 2411
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2412
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2414
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2415
        .items = { ITEM_FULL_RESTORE },
#line 2416
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2418
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2418
            .heldItem = ITEM_NUGGET,
#line 2420
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2419
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2422
    [TRAINER_WINSTON_2] =
    {
#line 2423
        .trainerName = _("WINSTON"),
#line 2424
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2425
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2427
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2428
        .items = { ITEM_FULL_RESTORE },
#line 2429
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2431
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2431
            .heldItem = ITEM_NUGGET,
#line 2433
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2432
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2435
    [TRAINER_WINSTON_3] =
    {
#line 2436
        .trainerName = _("WINSTON"),
#line 2437
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2438
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2440
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2441
        .items = { ITEM_FULL_RESTORE },
#line 2442
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2444
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2444
            .heldItem = ITEM_NUGGET,
#line 2446
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2445
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2448
    [TRAINER_WINSTON_4] =
    {
#line 2449
        .trainerName = _("WINSTON"),
#line 2450
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2451
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2453
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2454
        .items = { ITEM_FULL_RESTORE },
#line 2455
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2457
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2457
            .heldItem = ITEM_NUGGET,
#line 2459
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2458
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2461
    [TRAINER_WINSTON_5] =
    {
#line 2462
        .trainerName = _("WINSTON"),
#line 2463
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2464
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2466
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2467
        .items = { ITEM_FULL_RESTORE },
#line 2468
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2470
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2470
            .heldItem = ITEM_NUGGET,
#line 2472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2471
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2473
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 2478
    [TRAINER_STEVE_1] =
    {
#line 2479
        .trainerName = _("STEVE"),
#line 2480
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2481
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2483
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2484
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2486
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2488
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2487
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2490
    [TRAINER_THALIA_1] =
    {
#line 2491
        .trainerName = _("THALIA"),
#line 2492
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2493
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2494
F_TRAINER_FEMALE | 
#line 2495
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2496
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2498
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2500
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2499
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2502
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2504
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2503
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2506
    [TRAINER_MARK] =
    {
#line 2507
        .trainerName = _("MARK"),
#line 2508
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2509
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2511
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2514
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2515
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2518
    [TRAINER_GRUNT_MT_CHIMNEY_1] =
    {
#line 2519
        .trainerName = _("GRUNT"),
#line 2520
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 2521
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 2522
F_TRAINER_FEMALE | 
#line 2523
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 2524
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2526
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2528
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2527
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2530
    [TRAINER_STEVE_2] =
    {
#line 2531
        .trainerName = _("STEVE"),
#line 2532
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2533
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2535
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2536
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2538
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2540
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2539
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2542
    [TRAINER_STEVE_3] =
    {
#line 2543
        .trainerName = _("STEVE"),
#line 2544
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2545
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2547
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2548
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2550
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2552
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2551
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2554
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2556
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2555
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2558
    [TRAINER_STEVE_4] =
    {
#line 2559
        .trainerName = _("STEVE"),
#line 2560
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2561
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2563
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2564
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2566
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2568
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2567
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2570
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2572
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2571
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2574
    [TRAINER_STEVE_5] =
    {
#line 2575
        .trainerName = _("STEVE"),
#line 2576
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2577
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2579
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2582
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2584
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2583
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2586
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2588
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2587
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2590
    [TRAINER_LUIS] =
    {
#line 2591
        .trainerName = _("LUIS"),
#line 2592
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2593
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2595
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2596
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2598
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2600
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2599
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2602
    [TRAINER_DOMINIK] =
    {
#line 2603
        .trainerName = _("DOMINIK"),
#line 2604
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2605
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2607
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2610
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2611
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2614
    [TRAINER_DOUGLAS] =
    {
#line 2615
        .trainerName = _("DOUGLAS"),
#line 2616
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2617
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2619
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2622
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2624
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2623
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2626
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2628
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2627
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2630
    [TRAINER_DARRIN] =
    {
#line 2631
        .trainerName = _("DARRIN"),
#line 2632
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2633
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2635
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2636
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2638
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2640
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2639
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2642
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2644
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2643
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2646
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2648
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2647
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2650
    [TRAINER_TONY_1] =
    {
#line 2651
        .trainerName = _("TONY"),
#line 2652
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2653
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2655
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2656
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2658
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2660
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2659
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2662
    [TRAINER_JEROME] =
    {
#line 2663
        .trainerName = _("JEROME"),
#line 2664
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2665
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2667
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2668
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2670
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2672
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2671
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2674
    [TRAINER_MATTHEW] =
    {
#line 2675
        .trainerName = _("MATTHEW"),
#line 2676
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2677
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2679
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2680
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2682
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2684
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2683
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2686
    [TRAINER_DAVID] =
    {
#line 2687
        .trainerName = _("DAVID"),
#line 2688
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2689
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2691
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2692
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2694
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2696
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2695
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2698
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2699
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2702
    [TRAINER_SPENCER] =
    {
#line 2703
        .trainerName = _("SPENCER"),
#line 2704
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2705
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2707
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2708
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2710
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2712
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2711
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2714
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2716
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2715
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2718
    [TRAINER_ROLAND] =
    {
#line 2719
        .trainerName = _("ROLAND"),
#line 2720
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2721
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2723
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2724
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2726
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2728
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2727
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2730
    [TRAINER_NOLEN] =
    {
#line 2731
        .trainerName = _("NOLEN"),
#line 2732
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2733
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2735
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2738
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2740
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2739
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2742
    [TRAINER_STAN] =
    {
#line 2743
        .trainerName = _("STAN"),
#line 2744
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2745
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2747
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2748
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2750
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2752
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2751
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2754
    [TRAINER_BARRY] =
    {
#line 2755
        .trainerName = _("BARRY"),
#line 2756
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2757
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2759
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2760
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2762
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2764
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2763
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2766
    [TRAINER_DEAN] =
    {
#line 2767
        .trainerName = _("DEAN"),
#line 2768
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2769
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2771
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2772
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2774
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2775
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2778
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2780
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2779
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2782
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2784
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2783
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2786
    [TRAINER_RODNEY] =
    {
#line 2787
        .trainerName = _("RODNEY"),
#line 2788
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2789
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2791
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2792
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2794
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2796
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2795
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2798
    [TRAINER_RICHARD] =
    {
#line 2799
        .trainerName = _("RICHARD"),
#line 2800
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2801
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2803
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2804
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2806
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2808
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2807
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2810
    [TRAINER_HERMAN] =
    {
#line 2811
        .trainerName = _("HERMAN"),
#line 2812
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2813
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2815
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2816
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2818
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2820
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2819
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2822
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2823
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2826
    [TRAINER_SANTIAGO] =
    {
#line 2827
        .trainerName = _("SANTIAGO"),
#line 2828
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2829
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2831
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2832
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2834
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2836
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2835
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2838
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2840
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2839
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2842
    [TRAINER_GILBERT] =
    {
#line 2843
        .trainerName = _("GILBERT"),
#line 2844
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2845
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2847
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2850
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2852
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2851
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2854
    [TRAINER_FRANKLIN] =
    {
#line 2855
        .trainerName = _("FRANKLIN"),
#line 2856
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2857
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2859
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2860
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2862
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2864
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2863
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2866
    [TRAINER_KEVIN] =
    {
#line 2867
        .trainerName = _("KEVIN"),
#line 2868
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2869
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2871
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2872
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2874
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2875
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2878
    [TRAINER_JACK] =
    {
#line 2879
        .trainerName = _("JACK"),
#line 2880
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2881
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2883
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2884
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2886
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2888
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2887
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2890
    [TRAINER_DUDLEY] =
    {
#line 2891
        .trainerName = _("DUDLEY"),
#line 2892
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2893
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2895
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2898
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2900
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2899
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2902
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2904
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2903
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2906
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2907
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2910
    [TRAINER_CHAD] =
    {
#line 2911
        .trainerName = _("CHAD"),
#line 2912
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2913
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2915
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2916
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2918
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2920
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2919
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2922
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2923
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2926
    [TRAINER_TONY_2] =
    {
#line 2927
        .trainerName = _("TONY"),
#line 2928
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2929
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2931
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2934
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2936
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2935
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2938
    [TRAINER_TONY_3] =
    {
#line 2939
        .trainerName = _("TONY"),
#line 2940
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2941
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2943
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2946
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2948
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2947
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2950
    [TRAINER_TONY_4] =
    {
#line 2951
        .trainerName = _("TONY"),
#line 2952
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2953
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2955
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2958
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2960
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2959
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2962
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2964
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2963
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2966
    [TRAINER_TONY_5] =
    {
#line 2967
        .trainerName = _("TONY"),
#line 2968
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2969
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2971
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2972
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2974
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2976
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2975
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2978
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2980
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2979
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2982
    [TRAINER_TAKAO] =
    {
#line 2983
        .trainerName = _("TAKAO"),
#line 2984
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2985
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2987
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2988
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2990
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2992
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 2991
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2994
    [TRAINER_HITOSHI] =
    {
#line 2995
        .trainerName = _("HITOSHI"),
#line 2996
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2997
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2999
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3002
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3004
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 3003
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3006
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3008
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 3007
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3010
    [TRAINER_KIYO] =
    {
#line 3011
        .trainerName = _("KIYO"),
#line 3012
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3013
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3015
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3016
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3018
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3020
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3019
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3022
    [TRAINER_KOICHI] =
    {
#line 3023
        .trainerName = _("KOICHI"),
#line 3024
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3025
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3027
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3028
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3030
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3032
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3031
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3034
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3036
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 3035
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3038
    [TRAINER_NOB_1] =
    {
#line 3039
        .trainerName = _("NOB"),
#line 3040
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3041
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3043
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3044
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3046
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3048
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3047
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3050
    [TRAINER_NOB_2] =
    {
#line 3051
        .trainerName = _("NOB"),
#line 3052
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3053
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3055
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3056
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3058
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3060
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 3059
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3062
    [TRAINER_NOB_3] =
    {
#line 3063
        .trainerName = _("NOB"),
#line 3064
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3065
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3067
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3070
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3072
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 3071
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3074
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3076
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 3075
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3078
    [TRAINER_NOB_4] =
    {
#line 3079
        .trainerName = _("NOB"),
#line 3080
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3081
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3083
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3084
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3086
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3088
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3087
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3090
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3092
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3091
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3094
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3096
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3095
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3098
    [TRAINER_NOB_5] =
    {
#line 3099
        .trainerName = _("NOB"),
#line 3100
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3101
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3103
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3104
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3106
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3108
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3107
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3110
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3112
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3111
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3114
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3116
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3115
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3118
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3118
            .heldItem = ITEM_BLACK_BELT,
#line 3120
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3119
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3122
    [TRAINER_YUJI] =
    {
#line 3123
        .trainerName = _("YUJI"),
#line 3124
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3125
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3127
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3128
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3130
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3132
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3131
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3134
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3136
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3135
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3138
    [TRAINER_DAISUKE] =
    {
#line 3139
        .trainerName = _("DAISUKE"),
#line 3140
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3141
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3143
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3144
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3146
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3148
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3147
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3150
    [TRAINER_ATSUSHI] =
    {
#line 3151
        .trainerName = _("ATSUSHI"),
#line 3152
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3153
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3155
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3156
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3158
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3160
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3159
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3162
    [TRAINER_KIRK] =
    {
#line 3163
        .trainerName = _("KIRK"),
#line 3164
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3165
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3167
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3168
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3170
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3172
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3171
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3173
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SPARK,
                MOVE_LEER,
            },
            },
            {
#line 3178
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3180
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3179
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3181
                MOVE_CHARGE,
                MOVE_SHOCK_WAVE,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 3185
    [TRAINER_GRUNT_AQUA_HIDEOUT_7] =
    {
#line 3186
        .trainerName = _("GRUNT"),
#line 3187
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 3188
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 3189
F_TRAINER_FEMALE | 
#line 3190
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 3191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3193
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3194
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3197
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3198
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3201
    [TRAINER_GRUNT_AQUA_HIDEOUT_8] =
    {
#line 3202
        .trainerName = _("GRUNT"),
#line 3203
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 3204
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 3206
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 3207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3209
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3210
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3213
    [TRAINER_SHAWN] =
    {
#line 3214
        .trainerName = _("SHAWN"),
#line 3215
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3216
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3218
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3221
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3223
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3222
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3225
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3227
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3226
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3229
    [TRAINER_FERNANDO_1] =
    {
#line 3230
        .trainerName = _("FERNANDO"),
#line 3231
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3232
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3234
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3235
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3237
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3239
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3238
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3241
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3243
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3242
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3245
    [TRAINER_DALTON_1] =
    {
#line 3246
        .trainerName = _("DALTON"),
#line 3247
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3248
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3250
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3251
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3253
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3255
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3254
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3257
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3259
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3258
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3261
    [TRAINER_DALTON_2] =
    {
#line 3262
        .trainerName = _("DALTON"),
#line 3263
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3264
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3266
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3267
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3269
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3271
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3270
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3273
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3275
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3274
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3277
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3279
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3278
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3281
    [TRAINER_DALTON_3] =
    {
#line 3282
        .trainerName = _("DALTON"),
#line 3283
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3284
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3286
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3287
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3289
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3291
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3290
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3293
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3295
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3294
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3297
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3299
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3298
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3301
    [TRAINER_DALTON_4] =
    {
#line 3302
        .trainerName = _("DALTON"),
#line 3303
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3304
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3306
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3309
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3311
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3310
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3313
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3315
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3314
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3317
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3319
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3318
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3321
    [TRAINER_DALTON_5] =
    {
#line 3322
        .trainerName = _("DALTON"),
#line 3323
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3324
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3326
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3327
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3329
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3331
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3330
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3333
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3335
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3334
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3337
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3339
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3338
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3341
    [TRAINER_COLE] =
    {
#line 3342
        .trainerName = _("COLE"),
#line 3343
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3344
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3346
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3347
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3349
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3351
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3350
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3353
    [TRAINER_JEFF] =
    {
#line 3354
        .trainerName = _("JEFF"),
#line 3355
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3356
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3358
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3359
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3361
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3363
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3362
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3365
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3367
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3366
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3369
    [TRAINER_AXLE] =
    {
#line 3370
        .trainerName = _("AXLE"),
#line 3371
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3372
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3374
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3375
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3377
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3379
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3378
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3381
    [TRAINER_JACE] =
    {
#line 3382
        .trainerName = _("JACE"),
#line 3383
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3384
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3386
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3389
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3391
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3390
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3393
    [TRAINER_KEEGAN] =
    {
#line 3394
        .trainerName = _("KEEGAN"),
#line 3395
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3396
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3398
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3399
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3401
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3403
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 3402
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3405
    [TRAINER_BERNIE_1] =
    {
#line 3406
        .trainerName = _("BERNIE"),
#line 3407
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3408
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3410
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3413
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3414
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3417
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3419
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3418
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3421
    [TRAINER_BERNIE_2] =
    {
#line 3422
        .trainerName = _("BERNIE"),
#line 3423
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3424
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3426
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3429
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3431
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3430
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3433
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3435
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3434
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3437
    [TRAINER_BERNIE_3] =
    {
#line 3438
        .trainerName = _("BERNIE"),
#line 3439
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3440
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3442
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3443
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3445
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3447
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3446
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3449
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3451
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3450
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3453
    [TRAINER_BERNIE_4] =
    {
#line 3454
        .trainerName = _("BERNIE"),
#line 3455
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3456
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3458
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3459
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3461
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3463
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3462
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3465
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3467
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3466
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3469
    [TRAINER_BERNIE_5] =
    {
#line 3470
        .trainerName = _("BERNIE"),
#line 3471
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3472
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3474
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3475
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3477
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3479
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3478
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3481
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3483
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3482
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3485
    [TRAINER_DREW] =
    {
#line 3486
        .trainerName = _("DREW"),
#line 3487
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3488
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3490
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3493
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3495
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3494
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3496
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
        },
    },
#line 3501
    [TRAINER_BEAU] =
    {
#line 3502
        .trainerName = _("BEAU"),
#line 3503
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3504
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3506
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3507
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3509
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3511
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3510
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3512
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 3517
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3518
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3520
                MOVE_POISON_STING,
                MOVE_SAND_ATTACK,
                MOVE_SCRATCH,
                MOVE_DIG,
            },
            },
            {
#line 3525
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3527
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3526
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3528
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 3533
    [TRAINER_LARRY] =
    {
#line 3534
        .trainerName = _("LARRY"),
#line 3535
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3536
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3538
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3539
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3541
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3543
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3542
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3545
    [TRAINER_SHANE] =
    {
#line 3546
        .trainerName = _("SHANE"),
#line 3547
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3548
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3550
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3553
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3554
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3557
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3559
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3558
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3561
    [TRAINER_JUSTIN] =
    {
#line 3562
        .trainerName = _("JUSTIN"),
#line 3563
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3564
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3566
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3567
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3569
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3571
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3570
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3573
    [TRAINER_ETHAN_1] =
    {
#line 3574
        .trainerName = _("ETHAN"),
#line 3575
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3576
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3578
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3579
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3581
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3583
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3582
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3585
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3587
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3586
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3589
    [TRAINER_AUTUMN] =
    {
#line 3590
        .trainerName = _("AUTUMN"),
#line 3591
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 3592
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 3593
F_TRAINER_FEMALE | 
#line 3594
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 3595
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3597
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3599
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3598
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3601
    [TRAINER_TRAVIS] =
    {
#line 3602
        .trainerName = _("TRAVIS"),
#line 3603
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3604
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3606
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3607
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3609
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3611
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3610
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3613
    [TRAINER_ETHAN_2] =
    {
#line 3614
        .trainerName = _("ETHAN"),
#line 3615
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3616
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3618
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3621
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3623
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3622
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3625
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3627
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3626
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3629
    [TRAINER_ETHAN_3] =
    {
#line 3630
        .trainerName = _("ETHAN"),
#line 3631
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3632
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3634
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3635
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3637
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3639
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3638
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3641
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3643
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3642
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3645
    [TRAINER_ETHAN_4] =
    {
#line 3646
        .trainerName = _("ETHAN"),
#line 3647
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3648
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3650
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3651
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3653
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3655
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3654
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3657
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3659
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3658
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3661
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3663
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3662
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3665
    [TRAINER_ETHAN_5] =
    {
#line 3666
        .trainerName = _("ETHAN"),
#line 3667
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3668
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3670
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3671
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3673
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3675
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3674
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3677
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3679
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3678
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3681
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3683
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3682
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3685
    [TRAINER_BRENT] =
    {
#line 3686
        .trainerName = _("BRENT"),
#line 3687
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3688
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3690
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3691
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3693
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3695
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3694
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3697
    [TRAINER_DONALD] =
    {
#line 3698
        .trainerName = _("DONALD"),
#line 3699
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3700
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3702
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3703
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3705
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3707
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3706
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3709
            .species = SPECIES_SILCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3711
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3710
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3713
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3715
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3714
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3717
    [TRAINER_TAYLOR] =
    {
#line 3718
        .trainerName = _("TAYLOR"),
#line 3719
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3720
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3722
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3723
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3725
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3727
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3726
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3729
            .species = SPECIES_CASCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3731
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3730
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3733
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3735
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3734
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3737
    [TRAINER_JEFFREY_1] =
    {
#line 3738
        .trainerName = _("JEFFREY"),
#line 3739
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3740
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3742
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3743
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3745
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3747
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3746
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3749
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3751
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3750
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3753
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3755
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3754
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3757
    [TRAINER_DEREK] =
    {
#line 3758
        .trainerName = _("DEREK"),
#line 3759
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3760
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3762
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3763
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3765
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3767
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 3766
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3769
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3771
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 3770
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3773
    [TRAINER_JEFFREY_2] =
    {
#line 3774
        .trainerName = _("JEFFREY"),
#line 3775
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3776
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3778
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3779
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3781
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3783
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3782
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3785
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3787
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3786
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3789
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3791
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3790
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3793
    [TRAINER_JEFFREY_3] =
    {
#line 3794
        .trainerName = _("JEFFREY"),
#line 3795
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3796
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3798
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3799
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3801
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3803
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3802
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3805
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3807
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3806
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3809
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3811
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3810
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3813
    [TRAINER_JEFFREY_4] =
    {
#line 3814
        .trainerName = _("JEFFREY"),
#line 3815
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3816
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3818
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3819
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3821
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3823
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3822
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3825
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3827
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3826
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3829
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3831
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3830
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3833
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3835
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3834
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3837
    [TRAINER_JEFFREY_5] =
    {
#line 3838
        .trainerName = _("JEFFREY"),
#line 3839
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3840
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3842
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3843
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3845
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3847
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3846
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3849
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3851
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3850
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3853
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3855
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3854
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3857
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3857
            .heldItem = ITEM_SILVER_POWDER,
#line 3859
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3858
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3861
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3863
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3862
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3865
    [TRAINER_EDWARD] =
    {
#line 3866
        .trainerName = _("EDWARD"),
#line 3867
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3868
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3870
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3871
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3873
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3875
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3874
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3876
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
#line 3878
    [TRAINER_PRESTON] =
    {
#line 3879
        .trainerName = _("PRESTON"),
#line 3880
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3881
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3883
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3884
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3886
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3888
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3887
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3890
    [TRAINER_VIRGIL] =
    {
#line 3891
        .trainerName = _("VIRGIL"),
#line 3892
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3893
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3895
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3898
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3900
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3899
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3902
    [TRAINER_BLAKE] =
    {
#line 3903
        .trainerName = _("BLAKE"),
#line 3904
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3905
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3907
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3908
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3910
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3912
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3911
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3914
    [TRAINER_WILLIAM] =
    {
#line 3915
        .trainerName = _("WILLIAM"),
#line 3916
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3917
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3919
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3920
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3922
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3923
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3926
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3928
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3927
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3930
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3932
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3931
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3934
    [TRAINER_JOSHUA] =
    {
#line 3935
        .trainerName = _("JOSHUA"),
#line 3936
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3937
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3939
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3942
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3944
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3943
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3946
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3948
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3947
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3950
    [TRAINER_CAMERON_1] =
    {
#line 3951
        .trainerName = _("CAMERON"),
#line 3952
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3953
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3955
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3958
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3959
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3962
    [TRAINER_CAMERON_2] =
    {
#line 3963
        .trainerName = _("CAMERON"),
#line 3964
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3965
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3967
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3970
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3972
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3971
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3974
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3976
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3975
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3978
    [TRAINER_CAMERON_3] =
    {
#line 3979
        .trainerName = _("CAMERON"),
#line 3980
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3981
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3983
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3984
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3986
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3988
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3987
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3990
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3992
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3991
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3994
    [TRAINER_CAMERON_4] =
    {
#line 3995
        .trainerName = _("CAMERON"),
#line 3996
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3997
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3999
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4002
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4004
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4003
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4006
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4008
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4007
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4010
    [TRAINER_CAMERON_5] =
    {
#line 4011
        .trainerName = _("CAMERON"),
#line 4012
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4013
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 4015
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4016
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4018
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4020
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4019
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4022
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4024
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4023
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4026
    [TRAINER_JACLYN] =
    {
#line 4027
        .trainerName = _("JACLYN"),
#line 4028
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4029
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4030
F_TRAINER_FEMALE | 
#line 4031
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4032
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4034
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4036
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4035
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4037
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
#line 4039
    [TRAINER_HANNAH] =
    {
#line 4040
        .trainerName = _("HANNAH"),
#line 4041
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4042
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4043
F_TRAINER_FEMALE | 
#line 4044
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4045
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4047
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4049
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4048
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4051
    [TRAINER_SAMANTHA] =
    {
#line 4052
        .trainerName = _("SAMANTHA"),
#line 4053
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4054
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4055
F_TRAINER_FEMALE | 
#line 4056
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4057
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4059
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4061
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4060
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4063
    [TRAINER_MAURA] =
    {
#line 4064
        .trainerName = _("MAURA"),
#line 4065
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4066
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4067
F_TRAINER_FEMALE | 
#line 4068
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4069
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4071
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4073
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4072
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4075
    [TRAINER_KAYLA] =
    {
#line 4076
        .trainerName = _("KAYLA"),
#line 4077
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4078
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4079
F_TRAINER_FEMALE | 
#line 4080
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4081
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4083
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4085
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4084
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4087
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4089
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4088
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4091
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4093
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4092
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4095
    [TRAINER_ALEXIS] =
    {
#line 4096
        .trainerName = _("ALEXIS"),
#line 4097
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4098
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4099
F_TRAINER_FEMALE | 
#line 4100
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4101
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4103
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4105
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4104
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4107
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4109
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4108
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4111
    [TRAINER_JACKI_1] =
    {
#line 4112
        .trainerName = _("JACKI"),
#line 4113
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4114
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4115
F_TRAINER_FEMALE | 
#line 4116
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4117
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4119
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4121
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4120
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4123
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4125
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4124
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4127
    [TRAINER_JACKI_2] =
    {
#line 4128
        .trainerName = _("JACKI"),
#line 4129
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4130
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4131
F_TRAINER_FEMALE | 
#line 4132
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4133
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4135
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4137
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4136
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4139
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4141
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4140
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4143
    [TRAINER_JACKI_3] =
    {
#line 4144
        .trainerName = _("JACKI"),
#line 4145
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4146
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4147
F_TRAINER_FEMALE | 
#line 4148
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4149
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4151
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4153
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4152
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4155
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4157
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4156
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4159
    [TRAINER_JACKI_4] =
    {
#line 4160
        .trainerName = _("JACKI"),
#line 4161
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4162
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4163
F_TRAINER_FEMALE | 
#line 4164
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4165
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4167
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4169
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4168
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4171
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4173
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4172
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4175
    [TRAINER_JACKI_5] =
    {
#line 4176
        .trainerName = _("JACKI"),
#line 4177
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4178
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4179
F_TRAINER_FEMALE | 
#line 4180
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4181
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4183
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4185
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4184
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4187
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4189
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4188
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4191
    [TRAINER_WALTER_1] =
    {
#line 4192
        .trainerName = _("WALTER"),
#line 4193
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4194
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4196
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4197
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4199
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4201
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4200
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4203
    [TRAINER_MICAH] =
    {
#line 4204
        .trainerName = _("MICAH"),
#line 4205
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4206
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4208
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4209
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4211
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4213
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4212
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4215
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4217
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4216
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4219
    [TRAINER_THOMAS] =
    {
#line 4220
        .trainerName = _("THOMAS"),
#line 4221
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4222
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4224
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4225
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4227
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4229
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4228
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4231
    [TRAINER_WALTER_2] =
    {
#line 4232
        .trainerName = _("WALTER"),
#line 4233
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4234
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4236
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4237
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4239
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4241
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4240
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4243
    [TRAINER_WALTER_3] =
    {
#line 4244
        .trainerName = _("WALTER"),
#line 4245
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4246
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4248
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4249
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4251
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4253
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4252
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4254
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4259
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4261
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4260
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4262
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
#line 4267
    [TRAINER_WALTER_4] =
    {
#line 4268
        .trainerName = _("WALTER"),
#line 4269
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4270
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4272
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4273
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4275
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4277
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4276
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4278
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4283
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4285
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4284
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4286
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 4290
    [TRAINER_WALTER_5] =
    {
#line 4291
        .trainerName = _("WALTER"),
#line 4292
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4293
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4295
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4296
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4298
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4300
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4299
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4301
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4306
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4308
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4307
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4309
                MOVE_FURY_SWIPES,
                MOVE_DISABLE,
                MOVE_CONFUSION,
                MOVE_PSYCH_UP,
            },
            },
            {
#line 4314
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4316
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4315
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4317
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
#line 4322
    [TRAINER_SIDNEY] =
    {
#line 4323
        .trainerName = _("SIDNEY"),
#line 4324
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4325
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .encounterMusic_gender = 
#line 4327
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4328
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4329
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_FORCE_SETUP_FIRST_TURN,
#line 4330
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4332
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4334
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4333
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4335
                MOVE_ROAR,
                MOVE_DOUBLE_EDGE,
                MOVE_SAND_ATTACK,
                MOVE_CRUNCH,
            },
            },
            {
#line 4340
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4342
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4341
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4343
                MOVE_TORMENT,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
                MOVE_EXTRASENSORY,
            },
            },
            {
#line 4348
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4350
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4349
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4351
                MOVE_LEECH_SEED,
                MOVE_FEINT_ATTACK,
                MOVE_NEEDLE_ARM,
                MOVE_COTTON_SPORE,
            },
            },
            {
#line 4356
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4358
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4357
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4359
                MOVE_SURF,
                MOVE_SWORDS_DANCE,
                MOVE_STRENGTH,
                MOVE_FACADE,
            },
            },
            {
#line 4364
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4364
            .heldItem = ITEM_SITRUS_BERRY,
#line 4366
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4365
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4367
                MOVE_AERIAL_ACE,
                MOVE_ROCK_SLIDE,
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
#line 4372
    [TRAINER_PHOEBE] =
    {
#line 4373
        .trainerName = _("PHOEBE"),
#line 4374
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4375
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .encounterMusic_gender = 
#line 4376
F_TRAINER_FEMALE | 
#line 4377
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4378
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4379
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4380
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4382
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4384
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4383
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4385
                MOVE_SHADOW_PUNCH,
                MOVE_CONFUSE_RAY,
                MOVE_CURSE,
                MOVE_PROTECT,
            },
            },
            {
#line 4390
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4392
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4391
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4393
                MOVE_SHADOW_BALL,
                MOVE_GRUDGE,
                MOVE_WILL_O_WISP,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4398
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4400
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4399
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4401
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_TEAM,
                MOVE_NIGHT_SHADE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4406
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4408
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4407
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4409
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_FACADE,
            },
            },
            {
#line 4414
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4414
            .heldItem = ITEM_SITRUS_BERRY,
#line 4416
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4415
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4417
                MOVE_SHADOW_BALL,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 4422
    [TRAINER_GLACIA] =
    {
#line 4423
        .trainerName = _("GLACIA"),
#line 4424
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4425
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .encounterMusic_gender = 
#line 4426
F_TRAINER_FEMALE | 
#line 4427
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4428
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4429
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4430
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4432
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4434
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4433
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4435
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_HAIL,
                MOVE_ICE_BALL,
            },
            },
            {
#line 4440
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4442
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4441
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4443
                MOVE_LIGHT_SCREEN,
                MOVE_CRUNCH,
                MOVE_ICY_WIND,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 4448
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4450
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4449
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4451
                MOVE_ATTRACT,
                MOVE_DOUBLE_EDGE,
                MOVE_HAIL,
                MOVE_BLIZZARD,
            },
            },
            {
#line 4456
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4458
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4457
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4459
                MOVE_SHADOW_BALL,
                MOVE_EXPLOSION,
                MOVE_HAIL,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 4464
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4464
            .heldItem = ITEM_SITRUS_BERRY,
#line 4466
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4465
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4467
                MOVE_SURF,
                MOVE_BODY_SLAM,
                MOVE_ICE_BEAM,
                MOVE_SHEER_COLD,
            },
            },
        },
    },
#line 4472
    [TRAINER_DRAKE] =
    {
#line 4473
        .trainerName = _("DRAKE"),
#line 4474
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4475
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .encounterMusic_gender = 
#line 4477
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4478
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4479
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4480
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4482
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4484
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4483
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4485
                MOVE_ROCK_TOMB,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
                MOVE_DOUBLE_EDGE,
            },
            },
            {
#line 4490
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4492
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4491
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4493
                MOVE_DOUBLE_EDGE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4498
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4500
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4499
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4501
                MOVE_SMOKESCREEN,
                MOVE_DRAGON_DANCE,
                MOVE_SURF,
                MOVE_BODY_SLAM,
            },
            },
            {
#line 4506
            .species = SPECIES_FLYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4508
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4507
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4509
                MOVE_FLAMETHROWER,
                MOVE_CRUNCH,
                MOVE_DRAGON_BREATH,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 4514
            .species = SPECIES_SALAMENCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4514
            .heldItem = ITEM_SITRUS_BERRY,
#line 4516
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4515
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4517
                MOVE_FLAMETHROWER,
                MOVE_DRAGON_CLAW,
                MOVE_ROCK_SLIDE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 4522
    [TRAINER_ROXANNE_1] =
    {
#line 4523
        .trainerName = _("ROXANNE"),
#line 4524
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4525
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 4526
F_TRAINER_FEMALE | 
#line 4527
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4528
        .items = { ITEM_POTION, ITEM_POTION },
#line 4529
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4531
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4533
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4532
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4534
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 4539
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4541
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4540
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4542
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 4547
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4547
            .heldItem = ITEM_ORAN_BERRY,
#line 4549
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4548
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4550
                MOVE_BLOCK,
                MOVE_HARDEN,
                MOVE_TACKLE,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 4555
    [TRAINER_BRAWLY_1] =
    {
#line 4556
        .trainerName = _("BRAWLY"),
#line 4557
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4558
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 4560
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4561
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 4562
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4564
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4566
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4565
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4567
                MOVE_KARATE_CHOP,
                MOVE_LOW_KICK,
                MOVE_SEISMIC_TOSS,
                MOVE_BULK_UP,
            },
            },
            {
#line 4572
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4574
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4573
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4575
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_BULK_UP,
            },
            },
            {
#line 4580
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4580
            .heldItem = ITEM_SITRUS_BERRY,
#line 4582
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4581
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4583
                MOVE_ARM_THRUST,
                MOVE_VITAL_THROW,
                MOVE_REVERSAL,
                MOVE_BULK_UP,
            },
            },
        },
    },
#line 4588
    [TRAINER_WATTSON_1] =
    {
#line 4589
        .trainerName = _("WATTSON"),
#line 4590
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4591
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 4593
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4594
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 4595
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4597
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4599
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4598
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4600
                MOVE_ROLLOUT,
                MOVE_SPARK,
                MOVE_SELF_DESTRUCT,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 4605
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4607
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4606
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4608
                MOVE_SHOCK_WAVE,
                MOVE_LEER,
                MOVE_QUICK_ATTACK,
                MOVE_HOWL,
            },
            },
            {
#line 4613
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4615
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 4614
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4616
                MOVE_SUPERSONIC,
                MOVE_SHOCK_WAVE,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
#line 4621
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4621
            .heldItem = ITEM_SITRUS_BERRY,
#line 4623
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4622
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4624
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SHOCK_WAVE,
                MOVE_HOWL,
            },
            },
        },
    },
#line 4629
    [TRAINER_FLANNERY_1] =
    {
#line 4630
        .trainerName = _("FLANNERY"),
#line 4631
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4632
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 4633
F_TRAINER_FEMALE | 
#line 4634
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4635
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4636
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4638
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4640
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4639
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4641
                MOVE_OVERHEAT,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 4646
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4648
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4647
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4649
                MOVE_OVERHEAT,
                MOVE_SMOG,
                MOVE_LIGHT_SCREEN,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 4654
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4656
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4655
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4657
                MOVE_OVERHEAT,
                MOVE_TACKLE,
                MOVE_SUNNY_DAY,
                MOVE_ATTRACT,
            },
            },
            {
#line 4662
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4662
            .heldItem = ITEM_WHITE_HERB,
#line 4664
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4663
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4665
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_BODY_SLAM,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 4670
    [TRAINER_NORMAN_1] =
    {
#line 4671
        .trainerName = _("NORMAN"),
#line 4672
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4673
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 4675
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4676
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4677
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4679
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4681
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4680
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4682
                MOVE_TEETER_DANCE,
                MOVE_PSYBEAM,
                MOVE_FACADE,
                MOVE_ENCORE,
            },
            },
            {
#line 4687
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4689
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4688
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4690
                MOVE_SLASH,
                MOVE_FACADE,
                MOVE_ENCORE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4695
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4697
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4696
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4698
                MOVE_SLASH,
                MOVE_BELLY_DRUM,
                MOVE_FACADE,
                MOVE_HEADBUTT,
            },
            },
            {
#line 4703
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4703
            .heldItem = ITEM_SITRUS_BERRY,
#line 4705
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4704
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4706
                MOVE_COUNTER,
                MOVE_YAWN,
                MOVE_FACADE,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
#line 4711
    [TRAINER_WINONA_1] =
    {
#line 4712
        .trainerName = _("WINONA"),
#line 4713
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4714
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 4715
F_TRAINER_FEMALE | 
#line 4716
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4717
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4718
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4720
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4722
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4721
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4723
                MOVE_PERISH_SONG,
                MOVE_MIRROR_MOVE,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4728
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4730
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4729
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4731
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 4736
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4738
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4737
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4739
                MOVE_WATER_GUN,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4744
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4746
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 4745
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4747
                MOVE_SAND_ATTACK,
                MOVE_FURY_ATTACK,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4752
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4752
            .heldItem = ITEM_ORAN_BERRY,
#line 4754
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4753
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4755
                MOVE_EARTHQUAKE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
        },
    },
#line 4760
    [TRAINER_TATE_AND_LIZA_1] =
    {
#line 4761
        .trainerName = _("TATE&LIZA"),
#line 4762
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4763
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 4765
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4766
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4767
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4769
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4771
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4770
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4772
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 4777
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4779
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4778
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4780
                MOVE_PSYCHIC,
                MOVE_SUNNY_DAY,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 4785
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4785
            .heldItem = ITEM_SITRUS_BERRY,
#line 4787
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4786
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4788
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_CALM_MIND,
            },
            },
            {
#line 4793
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4793
            .heldItem = ITEM_SITRUS_BERRY,
#line 4795
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4794
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4796
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
#line 4801
    [TRAINER_JUAN_1] =
    {
#line 4802
        .trainerName = _("JUAN"),
#line 4803
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4804
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 4806
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4807
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4808
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4810
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4812
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4811
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4813
                MOVE_WATER_PULSE,
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
            },
            },
            {
#line 4818
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4820
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4819
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4821
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_AMNESIA,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 4826
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4828
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4827
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4829
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_AURORA_BEAM,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 4834
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4836
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4835
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4837
                MOVE_WATER_PULSE,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_LEER,
            },
            },
            {
#line 4842
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4842
            .heldItem = ITEM_CHESTO_BERRY,
#line 4844
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4843
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4845
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 4850
    [TRAINER_JERRY_1] =
    {
#line 4851
        .trainerName = _("JERRY"),
#line 4852
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4853
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4855
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4856
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4858
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4860
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4859
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4862
    [TRAINER_TED] =
    {
#line 4863
        .trainerName = _("TED"),
#line 4864
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4865
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4867
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4868
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4870
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4872
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4871
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4874
    [TRAINER_PAUL] =
    {
#line 4875
        .trainerName = _("PAUL"),
#line 4876
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4877
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4879
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4882
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4884
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4883
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4886
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4888
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4887
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4890
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4892
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4891
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4894
    [TRAINER_JERRY_2] =
    {
#line 4895
        .trainerName = _("JERRY"),
#line 4896
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4897
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4899
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4900
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4902
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4904
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4903
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4906
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4908
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4907
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4910
    [TRAINER_JERRY_3] =
    {
#line 4911
        .trainerName = _("JERRY"),
#line 4912
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4913
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4915
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4916
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4918
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4920
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4919
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4922
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4924
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4923
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4926
    [TRAINER_JERRY_4] =
    {
#line 4927
        .trainerName = _("JERRY"),
#line 4928
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4929
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4931
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4934
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4936
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4935
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4938
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4940
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4939
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4942
    [TRAINER_JERRY_5] =
    {
#line 4943
        .trainerName = _("JERRY"),
#line 4944
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4945
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4947
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4948
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4950
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4952
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4951
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4954
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4956
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4955
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4958
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4960
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4959
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4962
    [TRAINER_KAREN_1] =
    {
#line 4963
        .trainerName = _("KAREN"),
#line 4964
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4965
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4966
F_TRAINER_FEMALE | 
#line 4967
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4970
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4972
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4971
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4974
    [TRAINER_GEORGIA] =
    {
#line 4975
        .trainerName = _("GEORGIA"),
#line 4976
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4977
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4978
F_TRAINER_FEMALE | 
#line 4979
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4982
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4984
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4983
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4986
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4988
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4987
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4990
    [TRAINER_KAREN_2] =
    {
#line 4991
        .trainerName = _("KAREN"),
#line 4992
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4993
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4994
F_TRAINER_FEMALE | 
#line 4995
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4998
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5000
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4999
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5002
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5004
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5003
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5006
    [TRAINER_KAREN_3] =
    {
#line 5007
        .trainerName = _("KAREN"),
#line 5008
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 5009
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 5010
F_TRAINER_FEMALE | 
#line 5011
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 5012
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5014
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5016
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5015
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5018
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5020
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5019
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5022
    [TRAINER_KAREN_4] =
    {
#line 5023
        .trainerName = _("KAREN"),
#line 5024
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 5025
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 5026
F_TRAINER_FEMALE | 
#line 5027
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 5028
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5030
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5032
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5031
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5034
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5036
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5035
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5038
    [TRAINER_KAREN_5] =
    {
#line 5039
        .trainerName = _("KAREN"),
#line 5040
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 5041
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 5042
F_TRAINER_FEMALE | 
#line 5043
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 5044
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5046
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5048
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 5047
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5050
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5052
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 5051
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5054
    [TRAINER_KATE_AND_JOY] =
    {
#line 5055
        .trainerName = _("KATE & JOY"),
#line 5056
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5057
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5059
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5060
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5062
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5063
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5065
                MOVE_HYPNOSIS,
                MOVE_PSYBEAM,
                MOVE_DIZZY_PUNCH,
                MOVE_TEETER_DANCE,
            },
            },
            {
#line 5070
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5072
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5071
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5073
                MOVE_FOCUS_PUNCH,
                MOVE_YAWN,
                MOVE_SLACK_OFF,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
#line 5078
    [TRAINER_ANNA_AND_MEG_1] =
    {
#line 5079
        .trainerName = _("ANNA & MEG"),
#line 5080
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5081
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5083
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5084
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5086
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5088
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5087
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5089
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5094
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5096
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5095
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5097
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5101
    [TRAINER_ANNA_AND_MEG_2] =
    {
#line 5102
        .trainerName = _("ANNA & MEG"),
#line 5103
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5104
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5106
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5107
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5109
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5111
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5110
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5112
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5117
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5119
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5118
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5120
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5124
    [TRAINER_ANNA_AND_MEG_3] =
    {
#line 5125
        .trainerName = _("ANNA & MEG"),
#line 5126
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5127
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5129
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5130
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5132
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5134
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5133
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5135
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5140
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5142
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5141
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5143
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5147
    [TRAINER_ANNA_AND_MEG_4] =
    {
#line 5148
        .trainerName = _("ANNA & MEG"),
#line 5149
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5150
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5152
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5153
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5155
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5157
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5156
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5158
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5163
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5165
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5164
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5166
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5170
    [TRAINER_ANNA_AND_MEG_5] =
    {
#line 5171
        .trainerName = _("ANNA & MEG"),
#line 5172
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5173
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5175
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5176
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5178
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5180
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5179
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5181
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5186
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5188
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5187
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5189
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5193
    [TRAINER_VICTOR] =
    {
#line 5194
        .trainerName = _("VICTOR"),
#line 5195
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5196
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5198
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5201
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5201
            .heldItem = ITEM_ORAN_BERRY,
#line 5203
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5202
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5205
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5205
            .heldItem = ITEM_ORAN_BERRY,
#line 5207
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5206
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5209
    [TRAINER_MIGUEL_1] =
    {
#line 5210
        .trainerName = _("MIGUEL"),
#line 5211
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5212
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5214
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5215
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5217
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5217
            .heldItem = ITEM_ORAN_BERRY,
#line 5219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5218
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5221
    [TRAINER_COLTON] =
    {
#line 5222
        .trainerName = _("COLTON"),
#line 5223
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5224
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5226
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5227
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 5229
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5229
            .heldItem = ITEM_ORAN_BERRY,
#line 5231
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5230
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5232
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5237
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5237
            .heldItem = ITEM_ORAN_BERRY,
#line 5239
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5238
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5240
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5245
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5245
            .heldItem = ITEM_ORAN_BERRY,
#line 5247
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5246
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5248
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5253
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5253
            .heldItem = ITEM_ORAN_BERRY,
#line 5255
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5254
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5256
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5261
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5261
            .heldItem = ITEM_ORAN_BERRY,
#line 5263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5262
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5264
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5269
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5269
            .heldItem = ITEM_ORAN_BERRY,
#line 5271
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5270
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5272
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
        },
    },
#line 5277
    [TRAINER_MIGUEL_2] =
    {
#line 5278
        .trainerName = _("MIGUEL"),
#line 5279
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5280
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5282
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5283
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5285
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5285
            .heldItem = ITEM_ORAN_BERRY,
#line 5287
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5286
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5289
    [TRAINER_MIGUEL_3] =
    {
#line 5290
        .trainerName = _("MIGUEL"),
#line 5291
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5292
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5294
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5295
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5297
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5297
            .heldItem = ITEM_ORAN_BERRY,
#line 5299
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5298
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5301
    [TRAINER_MIGUEL_4] =
    {
#line 5302
        .trainerName = _("MIGUEL"),
#line 5303
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5304
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5306
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5309
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5309
            .heldItem = ITEM_ORAN_BERRY,
#line 5311
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5310
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5313
    [TRAINER_MIGUEL_5] =
    {
#line 5314
        .trainerName = _("MIGUEL"),
#line 5315
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5316
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5318
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5321
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5321
            .heldItem = ITEM_SITRUS_BERRY,
#line 5323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5322
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5325
    [TRAINER_VICTORIA] =
    {
#line 5326
        .trainerName = _("VICTORIA"),
#line 5327
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5328
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5329
F_TRAINER_FEMALE | 
#line 5330
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5331
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5333
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5333
            .heldItem = ITEM_ORAN_BERRY,
#line 5335
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 5334
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5337
    [TRAINER_VANESSA] =
    {
#line 5338
        .trainerName = _("VANESSA"),
#line 5339
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5340
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5341
F_TRAINER_FEMALE | 
#line 5342
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5343
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5345
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5345
            .heldItem = ITEM_ORAN_BERRY,
#line 5347
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5346
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5349
    [TRAINER_BETHANY] =
    {
#line 5350
        .trainerName = _("BETHANY"),
#line 5351
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5352
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5353
F_TRAINER_FEMALE | 
#line 5354
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5355
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5357
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5357
            .heldItem = ITEM_ORAN_BERRY,
#line 5359
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5358
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5361
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5361
            .heldItem = ITEM_ORAN_BERRY,
#line 5363
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5362
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5365
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5365
            .heldItem = ITEM_ORAN_BERRY,
#line 5367
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5366
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5369
    [TRAINER_ISABEL_1] =
    {
#line 5370
        .trainerName = _("ISABEL"),
#line 5371
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5372
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5373
F_TRAINER_FEMALE | 
#line 5374
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5375
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5377
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5377
            .heldItem = ITEM_ORAN_BERRY,
#line 5379
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5378
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5381
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5381
            .heldItem = ITEM_ORAN_BERRY,
#line 5383
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5382
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5385
    [TRAINER_ISABEL_2] =
    {
#line 5386
        .trainerName = _("ISABEL"),
#line 5387
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5388
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5389
F_TRAINER_FEMALE | 
#line 5390
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5391
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5393
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5393
            .heldItem = ITEM_ORAN_BERRY,
#line 5395
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5394
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5397
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5397
            .heldItem = ITEM_ORAN_BERRY,
#line 5399
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5398
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5401
    [TRAINER_ISABEL_3] =
    {
#line 5402
        .trainerName = _("ISABEL"),
#line 5403
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5404
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5405
F_TRAINER_FEMALE | 
#line 5406
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5407
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5409
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5409
            .heldItem = ITEM_ORAN_BERRY,
#line 5411
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5410
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5413
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5413
            .heldItem = ITEM_ORAN_BERRY,
#line 5415
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5414
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5417
    [TRAINER_ISABEL_4] =
    {
#line 5418
        .trainerName = _("ISABEL"),
#line 5419
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5420
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5421
F_TRAINER_FEMALE | 
#line 5422
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5423
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5425
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5425
            .heldItem = ITEM_ORAN_BERRY,
#line 5427
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5426
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5429
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5429
            .heldItem = ITEM_ORAN_BERRY,
#line 5431
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5430
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5433
    [TRAINER_ISABEL_5] =
    {
#line 5434
        .trainerName = _("ISABEL"),
#line 5435
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5436
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5437
F_TRAINER_FEMALE | 
#line 5438
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5439
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5441
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5441
            .heldItem = ITEM_SITRUS_BERRY,
#line 5443
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5442
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5445
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5445
            .heldItem = ITEM_SITRUS_BERRY,
#line 5447
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5446
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5449
    [TRAINER_TIMOTHY_1] =
    {
#line 5450
        .trainerName = _("TIMOTHY"),
#line 5451
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5452
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5454
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5455
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5457
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5459
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5458
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5461
    [TRAINER_TIMOTHY_2] =
    {
#line 5462
        .trainerName = _("TIMOTHY"),
#line 5463
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5464
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5466
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5467
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5469
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5471
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5470
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5472
                MOVE_ARM_THRUST,
                MOVE_KNOCK_OFF,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5477
    [TRAINER_TIMOTHY_3] =
    {
#line 5478
        .trainerName = _("TIMOTHY"),
#line 5479
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5480
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5482
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5483
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5485
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5487
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5486
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5488
                MOVE_ARM_THRUST,
                MOVE_KNOCK_OFF,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5493
    [TRAINER_TIMOTHY_4] =
    {
#line 5494
        .trainerName = _("TIMOTHY"),
#line 5495
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5496
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5498
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5499
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5501
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5503
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5502
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5504
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5509
    [TRAINER_TIMOTHY_5] =
    {
#line 5510
        .trainerName = _("TIMOTHY"),
#line 5511
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5512
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5514
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5515
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5517
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5519
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5518
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5520
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5525
    [TRAINER_VICKY] =
    {
#line 5526
        .trainerName = _("VICKY"),
#line 5527
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5528
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5529
F_TRAINER_FEMALE | 
#line 5530
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5531
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5533
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5535
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5534
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5536
                MOVE_HIGH_JUMP_KICK,
                MOVE_MEDITATE,
                MOVE_CONFUSION,
                MOVE_DETECT,
            },
            },
        },
    },
#line 5541
    [TRAINER_SHELBY_1] =
    {
#line 5542
        .trainerName = _("SHELBY"),
#line 5543
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5544
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5545
F_TRAINER_FEMALE | 
#line 5546
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5547
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5549
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5551
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5550
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5553
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5555
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5554
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5557
    [TRAINER_SHELBY_2] =
    {
#line 5558
        .trainerName = _("SHELBY"),
#line 5559
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5560
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5561
F_TRAINER_FEMALE | 
#line 5562
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5563
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5565
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5567
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5566
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5569
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5571
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5570
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5573
    [TRAINER_SHELBY_3] =
    {
#line 5574
        .trainerName = _("SHELBY"),
#line 5575
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5576
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5577
F_TRAINER_FEMALE | 
#line 5578
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5579
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5581
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5583
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5582
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5585
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5587
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5586
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5589
    [TRAINER_SHELBY_4] =
    {
#line 5590
        .trainerName = _("SHELBY"),
#line 5591
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5592
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5593
F_TRAINER_FEMALE | 
#line 5594
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5595
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5597
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5599
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5598
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5601
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5603
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5602
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5605
    [TRAINER_SHELBY_5] =
    {
#line 5606
        .trainerName = _("SHELBY"),
#line 5607
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5608
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5609
F_TRAINER_FEMALE | 
#line 5610
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5611
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5613
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5615
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5614
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5617
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5619
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5618
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5621
    [TRAINER_CALVIN_1] =
    {
#line 5622
        .trainerName = _("CALVIN"),
#line 5623
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5624
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5626
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5627
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5629
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5631
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5630
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5633
    [TRAINER_BILLY] =
    {
#line 5634
        .trainerName = _("BILLY"),
#line 5635
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5636
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5638
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5639
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5641
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5643
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5642
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5645
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5647
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5646
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5649
    [TRAINER_JOSH] =
    {
#line 5650
        .trainerName = _("JOSH"),
#line 5651
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5652
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5654
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5655
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5657
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5659
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5658
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5660
                MOVE_TACKLE,
            },
            },
        },
    },
#line 5662
    [TRAINER_TOMMY] =
    {
#line 5663
        .trainerName = _("TOMMY"),
#line 5664
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5665
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5667
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5668
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5670
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5672
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 5671
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5674
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5676
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 5675
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5678
    [TRAINER_JOEY] =
    {
#line 5679
        .trainerName = _("JOEY"),
#line 5680
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5681
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5683
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5684
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5686
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5687
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5690
    [TRAINER_BEN] =
    {
#line 5691
        .trainerName = _("BEN"),
#line 5692
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5693
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5695
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5698
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5700
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 5699
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5701
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_GROWL,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 5706
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5708
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 5707
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5709
                MOVE_AMNESIA,
                MOVE_SLUDGE,
                MOVE_YAWN,
                MOVE_POUND,
            },
            },
        },
    },
#line 5714
    [TRAINER_QUINCY] =
    {
#line 5715
        .trainerName = _("QUINCY"),
#line 5716
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5717
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 5719
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5720
        .items = { ITEM_FULL_RESTORE },
#line 5721
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5723
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5725
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5724
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5726
                MOVE_ATTRACT,
                MOVE_ICE_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_FLAMETHROWER,
            },
            },
            {
#line 5731
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5733
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5732
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5734
                MOVE_SKILL_SWAP,
                MOVE_PROTECT,
                MOVE_WILL_O_WISP,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 5739
    [TRAINER_KATELYNN] =
    {
#line 5740
        .trainerName = _("KATELYNN"),
#line 5741
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5742
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 5743
F_TRAINER_FEMALE | 
#line 5744
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5745
        .items = { ITEM_FULL_RESTORE },
#line 5746
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5748
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5750
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5749
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5751
                MOVE_SKILL_SWAP,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_CALM_MIND,
            },
            },
            {
#line 5756
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5758
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5757
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5759
                MOVE_EARTHQUAKE,
                MOVE_SHADOW_BALL,
                MOVE_AERIAL_ACE,
                MOVE_BRICK_BREAK,
            },
            },
        },
    },
#line 5764
    [TRAINER_JAYLEN] =
    {
#line 5765
        .trainerName = _("JAYLEN"),
#line 5766
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5767
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5769
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5770
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5772
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5774
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5773
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5776
    [TRAINER_DILLON] =
    {
#line 5777
        .trainerName = _("DILLON"),
#line 5778
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5779
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5781
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5782
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5784
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5786
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5785
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5788
    [TRAINER_CALVIN_2] =
    {
#line 5789
        .trainerName = _("CALVIN"),
#line 5790
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5791
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5793
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5794
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5796
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5798
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5797
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5800
    [TRAINER_CALVIN_3] =
    {
#line 5801
        .trainerName = _("CALVIN"),
#line 5802
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5803
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5805
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5806
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5808
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5810
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5809
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5812
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5814
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5813
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5816
    [TRAINER_CALVIN_4] =
    {
#line 5817
        .trainerName = _("CALVIN"),
#line 5818
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5819
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5821
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5822
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5824
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5826
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5825
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5828
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5830
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5829
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5832
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5834
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5833
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5836
    [TRAINER_CALVIN_5] =
    {
#line 5837
        .trainerName = _("CALVIN"),
#line 5838
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5839
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5841
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5842
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5844
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5846
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5845
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5848
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5850
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5849
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5852
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5854
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5853
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5856
    [TRAINER_EDDIE] =
    {
#line 5857
        .trainerName = _("EDDIE"),
#line 5858
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5859
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5861
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5862
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5864
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5866
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5865
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5868
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5870
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5869
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5872
    [TRAINER_ALLEN] =
    {
#line 5873
        .trainerName = _("ALLEN"),
#line 5874
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5875
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5877
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5878
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5880
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5882
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5881
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5884
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5886
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5885
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5888
    [TRAINER_TIMMY] =
    {
#line 5889
        .trainerName = _("TIMMY"),
#line 5890
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5891
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5893
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5894
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5896
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5898
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5897
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5900
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5901
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5904
    [TRAINER_WALLACE] =
    {
#line 5905
        .trainerName = _("WALLACE"),
#line 5906
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 5907
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .encounterMusic_gender = 
#line 5909
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5910
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 5911
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 5912
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 5914
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5916
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5915
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5917
                MOVE_RAIN_DANCE,
                MOVE_WATER_SPOUT,
                MOVE_DOUBLE_EDGE,
                MOVE_BLIZZARD,
            },
            },
            {
#line 5922
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5924
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5923
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5925
                MOVE_TOXIC,
                MOVE_HYDRO_PUMP,
                MOVE_SLUDGE_BOMB,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 5930
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5932
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5931
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5933
                MOVE_GIGA_DRAIN,
                MOVE_SURF,
                MOVE_LEECH_SEED,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 5938
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5940
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5939
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5941
                MOVE_EARTHQUAKE,
                MOVE_SURF,
                MOVE_AMNESIA,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 5946
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5948
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5947
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5949
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
                MOVE_SURF,
            },
            },
            {
#line 5954
            .species = SPECIES_MILOTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5954
            .heldItem = ITEM_SITRUS_BERRY,
#line 5956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5955
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5957
                MOVE_RECOVER,
                MOVE_SURF,
                MOVE_ICE_BEAM,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 5962
    [TRAINER_ANDREW] =
    {
#line 5963
        .trainerName = _("ANDREW"),
#line 5964
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5965
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5967
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5970
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5972
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5971
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5974
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5976
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5975
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5978
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5980
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5979
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5982
    [TRAINER_IVAN] =
    {
#line 5983
        .trainerName = _("IVAN"),
#line 5984
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5985
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5987
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5988
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5990
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5992
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5991
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5994
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5996
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5995
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5998
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6000
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5999
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6002
    [TRAINER_CLAUDE] =
    {
#line 6003
        .trainerName = _("CLAUDE"),
#line 6004
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6005
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6007
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6010
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6012
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6011
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6014
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6015
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6018
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6020
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6019
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6022
    [TRAINER_ELLIOT_1] =
    {
#line 6023
        .trainerName = _("ELLIOT"),
#line 6024
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6025
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6027
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6028
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6030
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6032
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6031
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6034
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6036
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6035
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6038
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6040
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6039
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6042
    [TRAINER_NED] =
    {
#line 6043
        .trainerName = _("NED"),
#line 6044
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6045
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6047
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6048
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6050
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6052
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6051
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6054
    [TRAINER_DALE] =
    {
#line 6055
        .trainerName = _("DALE"),
#line 6056
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6057
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6059
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6060
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6062
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6063
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6066
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6068
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6067
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6070
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6072
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6071
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6074
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6076
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6075
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6078
    [TRAINER_NOLAN] =
    {
#line 6079
        .trainerName = _("NOLAN"),
#line 6080
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6081
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6083
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6084
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6086
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6088
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6087
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6090
    [TRAINER_BARNY] =
    {
#line 6091
        .trainerName = _("BARNY"),
#line 6092
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6093
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6095
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6096
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6098
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6100
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6099
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6102
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6104
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6103
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6106
    [TRAINER_WADE] =
    {
#line 6107
        .trainerName = _("WADE"),
#line 6108
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6109
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6111
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6112
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6114
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6116
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6115
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6118
    [TRAINER_CARTER] =
    {
#line 6119
        .trainerName = _("CARTER"),
#line 6120
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6121
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6123
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6124
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6126
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6128
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6127
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6130
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6132
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6131
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6134
    [TRAINER_ELLIOT_2] =
    {
#line 6135
        .trainerName = _("ELLIOT"),
#line 6136
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6137
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6139
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6140
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6142
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6144
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6143
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6146
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6148
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6147
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6150
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6152
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6151
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6154
    [TRAINER_ELLIOT_3] =
    {
#line 6155
        .trainerName = _("ELLIOT"),
#line 6156
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6157
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6159
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6160
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6162
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6164
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6163
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6166
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6168
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6167
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6170
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6172
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6171
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6174
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6176
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6175
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6178
    [TRAINER_ELLIOT_4] =
    {
#line 6179
        .trainerName = _("ELLIOT"),
#line 6180
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6181
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6183
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6184
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6186
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6188
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6187
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6190
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6192
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6191
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6194
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6196
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6195
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6198
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6200
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6199
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6202
    [TRAINER_ELLIOT_5] =
    {
#line 6203
        .trainerName = _("ELLIOT"),
#line 6204
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6205
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6207
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6208
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6210
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6212
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6211
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6214
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6216
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6215
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6218
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6220
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6219
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6222
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6224
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6223
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6226
    [TRAINER_RONALD] =
    {
#line 6227
        .trainerName = _("RONALD"),
#line 6228
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6229
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6231
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6232
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 6234
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6236
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6235
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6238
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6240
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6239
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6242
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6244
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6243
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6246
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6248
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6247
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6250
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6252
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6251
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6254
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6256
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6255
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6258
    [TRAINER_JACOB] =
    {
#line 6259
        .trainerName = _("JACOB"),
#line 6260
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6261
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6263
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6264
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6266
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6268
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6267
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6270
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6272
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6271
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6274
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6276
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 6275
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6278
    [TRAINER_ANTHONY] =
    {
#line 6279
        .trainerName = _("ANTHONY"),
#line 6280
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6281
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6283
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6284
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6286
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6288
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6287
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6290
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6292
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6291
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6294
    [TRAINER_BENJAMIN_1] =
    {
#line 6295
        .trainerName = _("BENJAMIN"),
#line 6296
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6297
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6299
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6300
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6302
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6304
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6303
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6306
    [TRAINER_BENJAMIN_2] =
    {
#line 6307
        .trainerName = _("BENJAMIN"),
#line 6308
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6309
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6311
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6312
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6314
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6316
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6315
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6318
    [TRAINER_BENJAMIN_3] =
    {
#line 6319
        .trainerName = _("BENJAMIN"),
#line 6320
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6321
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6323
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6324
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6326
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6328
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6327
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6330
    [TRAINER_BENJAMIN_4] =
    {
#line 6331
        .trainerName = _("BENJAMIN"),
#line 6332
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6333
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6335
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6336
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6338
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6340
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6339
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6342
    [TRAINER_BENJAMIN_5] =
    {
#line 6343
        .trainerName = _("BENJAMIN"),
#line 6344
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6345
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6347
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6348
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6350
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6352
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6351
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6354
    [TRAINER_ABIGAIL_1] =
    {
#line 6355
        .trainerName = _("ABIGAIL"),
#line 6356
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6357
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6358
F_TRAINER_FEMALE | 
#line 6359
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6362
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6364
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6363
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6366
    [TRAINER_JASMINE] =
    {
#line 6367
        .trainerName = _("JASMINE"),
#line 6368
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6369
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6370
F_TRAINER_FEMALE | 
#line 6371
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6372
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6374
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6376
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6375
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6378
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6380
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6379
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6382
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6384
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6383
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6386
    [TRAINER_ABIGAIL_2] =
    {
#line 6387
        .trainerName = _("ABIGAIL"),
#line 6388
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6389
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6390
F_TRAINER_FEMALE | 
#line 6391
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6392
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6394
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6396
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6395
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6398
    [TRAINER_ABIGAIL_3] =
    {
#line 6399
        .trainerName = _("ABIGAIL"),
#line 6400
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6401
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6402
F_TRAINER_FEMALE | 
#line 6403
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6404
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6406
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6408
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6407
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6410
    [TRAINER_ABIGAIL_4] =
    {
#line 6411
        .trainerName = _("ABIGAIL"),
#line 6412
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6413
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6414
F_TRAINER_FEMALE | 
#line 6415
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6416
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6418
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6420
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6419
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6422
    [TRAINER_ABIGAIL_5] =
    {
#line 6423
        .trainerName = _("ABIGAIL"),
#line 6424
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6425
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6426
F_TRAINER_FEMALE | 
#line 6427
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6428
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6430
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6432
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6431
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6434
    [TRAINER_DYLAN_1] =
    {
#line 6435
        .trainerName = _("DYLAN"),
#line 6436
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6437
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6439
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6440
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6442
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6443
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6446
    [TRAINER_DYLAN_2] =
    {
#line 6447
        .trainerName = _("DYLAN"),
#line 6448
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6449
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6451
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6452
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6454
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6456
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6455
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6458
    [TRAINER_DYLAN_3] =
    {
#line 6459
        .trainerName = _("DYLAN"),
#line 6460
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6461
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6463
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6464
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6466
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6468
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6467
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6470
    [TRAINER_DYLAN_4] =
    {
#line 6471
        .trainerName = _("DYLAN"),
#line 6472
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6473
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6475
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6476
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6478
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6480
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6479
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6482
    [TRAINER_DYLAN_5] =
    {
#line 6483
        .trainerName = _("DYLAN"),
#line 6484
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6485
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6487
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6488
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6490
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6492
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6491
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6494
    [TRAINER_MARIA_1] =
    {
#line 6495
        .trainerName = _("MARIA"),
#line 6496
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6497
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6498
F_TRAINER_FEMALE | 
#line 6499
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6500
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6502
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6504
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6503
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6506
    [TRAINER_MARIA_2] =
    {
#line 6507
        .trainerName = _("MARIA"),
#line 6508
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6509
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6510
F_TRAINER_FEMALE | 
#line 6511
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6514
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6516
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6515
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6518
    [TRAINER_MARIA_3] =
    {
#line 6519
        .trainerName = _("MARIA"),
#line 6520
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6521
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6522
F_TRAINER_FEMALE | 
#line 6523
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6524
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6526
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6528
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6527
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6530
    [TRAINER_MARIA_4] =
    {
#line 6531
        .trainerName = _("MARIA"),
#line 6532
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6533
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6534
F_TRAINER_FEMALE | 
#line 6535
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6536
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6538
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6540
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6539
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6542
    [TRAINER_MARIA_5] =
    {
#line 6543
        .trainerName = _("MARIA"),
#line 6544
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6545
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6546
F_TRAINER_FEMALE | 
#line 6547
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6548
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6550
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6552
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6551
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6554
    [TRAINER_CAMDEN] =
    {
#line 6555
        .trainerName = _("CAMDEN"),
#line 6556
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6557
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6559
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6560
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6562
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6564
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6563
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6566
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6568
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6567
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6570
    [TRAINER_DEMETRIUS] =
    {
#line 6571
        .trainerName = _("DEMETRIUS"),
#line 6572
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 6573
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 6575
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6576
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6578
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6580
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6579
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6582
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6583
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6586
    [TRAINER_ISAIAH_1] =
    {
#line 6587
        .trainerName = _("ISAIAH"),
#line 6588
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6589
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6591
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6594
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6595
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6598
    [TRAINER_PABLO_1] =
    {
#line 6599
        .trainerName = _("PABLO"),
#line 6600
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6601
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6603
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6606
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6608
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6607
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6610
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6611
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6614
    [TRAINER_CHASE] =
    {
#line 6615
        .trainerName = _("CHASE"),
#line 6616
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6617
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6619
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6622
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6624
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6623
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6626
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6628
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6627
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6630
    [TRAINER_ISAIAH_2] =
    {
#line 6631
        .trainerName = _("ISAIAH"),
#line 6632
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6633
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6635
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6636
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6638
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6640
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6639
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6642
    [TRAINER_ISAIAH_3] =
    {
#line 6643
        .trainerName = _("ISAIAH"),
#line 6644
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6645
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6647
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6648
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6650
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6652
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6651
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6654
    [TRAINER_ISAIAH_4] =
    {
#line 6655
        .trainerName = _("ISAIAH"),
#line 6656
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6657
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6659
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6660
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6662
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6664
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6663
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6666
    [TRAINER_ISAIAH_5] =
    {
#line 6667
        .trainerName = _("ISAIAH"),
#line 6668
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6669
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6671
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6672
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6674
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6676
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6675
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6678
    [TRAINER_ISOBEL] =
    {
#line 6679
        .trainerName = _("ISOBEL"),
#line 6680
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6681
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6682
F_TRAINER_FEMALE | 
#line 6683
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6684
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6686
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6687
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6690
    [TRAINER_DONNY] =
    {
#line 6691
        .trainerName = _("DONNY"),
#line 6692
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6693
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6694
F_TRAINER_FEMALE | 
#line 6695
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6698
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6699
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6702
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6704
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 6703
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6706
    [TRAINER_TALIA] =
    {
#line 6707
        .trainerName = _("TALIA"),
#line 6708
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6709
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6710
F_TRAINER_FEMALE | 
#line 6711
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6714
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6716
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6715
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6718
    [TRAINER_KATELYN_1] =
    {
#line 6719
        .trainerName = _("KATELYN"),
#line 6720
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6721
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6722
F_TRAINER_FEMALE | 
#line 6723
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6724
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6726
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6728
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6727
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6730
    [TRAINER_ALLISON] =
    {
#line 6731
        .trainerName = _("ALLISON"),
#line 6732
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6733
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6734
F_TRAINER_FEMALE | 
#line 6735
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6738
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6740
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6739
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6742
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6744
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 6743
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6746
    [TRAINER_KATELYN_2] =
    {
#line 6747
        .trainerName = _("KATELYN"),
#line 6748
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6749
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6750
F_TRAINER_FEMALE | 
#line 6751
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6752
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6754
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6756
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6755
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6758
    [TRAINER_KATELYN_3] =
    {
#line 6759
        .trainerName = _("KATELYN"),
#line 6760
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6761
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6762
F_TRAINER_FEMALE | 
#line 6763
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6764
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6766
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6768
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6767
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6770
    [TRAINER_KATELYN_4] =
    {
#line 6771
        .trainerName = _("KATELYN"),
#line 6772
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6773
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6774
F_TRAINER_FEMALE | 
#line 6775
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6776
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6778
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6780
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6779
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6782
    [TRAINER_KATELYN_5] =
    {
#line 6783
        .trainerName = _("KATELYN"),
#line 6784
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6785
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6786
F_TRAINER_FEMALE | 
#line 6787
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6788
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6790
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6792
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6791
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6794
    [TRAINER_NICOLAS_1] =
    {
#line 6795
        .trainerName = _("NICOLAS"),
#line 6796
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6797
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6799
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6800
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6802
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6804
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6803
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6806
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6808
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6807
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6810
    [TRAINER_NICOLAS_2] =
    {
#line 6811
        .trainerName = _("NICOLAS"),
#line 6812
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6813
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6815
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6816
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6818
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6820
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 6819
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6822
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6824
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 6823
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6826
    [TRAINER_NICOLAS_3] =
    {
#line 6827
        .trainerName = _("NICOLAS"),
#line 6828
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6829
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6831
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6832
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6834
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6836
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 6835
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6838
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6840
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 6839
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6842
    [TRAINER_NICOLAS_4] =
    {
#line 6843
        .trainerName = _("NICOLAS"),
#line 6844
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6845
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6847
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6850
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6852
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6851
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6854
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6856
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6855
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6858
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6860
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6859
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6862
    [TRAINER_NICOLAS_5] =
    {
#line 6863
        .trainerName = _("NICOLAS"),
#line 6864
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6865
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6867
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6868
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6870
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6872
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6871
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6874
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6876
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6875
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6878
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6878
            .heldItem = ITEM_DRAGON_FANG,
#line 6880
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6879
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6882
    [TRAINER_AARON] =
    {
#line 6883
        .trainerName = _("AARON"),
#line 6884
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6885
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6887
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6888
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6890
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6892
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 6891
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 6893
                MOVE_DRAGON_BREATH,
                MOVE_HEADBUTT,
                MOVE_FOCUS_ENERGY,
                MOVE_EMBER,
            },
            },
        },
    },
#line 6898
    [TRAINER_PERRY] =
    {
#line 6899
        .trainerName = _("PERRY"),
#line 6900
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6901
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6903
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6904
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6906
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6907
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6910
    [TRAINER_HUGH] =
    {
#line 6911
        .trainerName = _("HUGH"),
#line 6912
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6913
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6915
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6916
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6918
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6920
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6919
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6922
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6923
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6926
    [TRAINER_PHIL] =
    {
#line 6927
        .trainerName = _("PHIL"),
#line 6928
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6929
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6931
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6934
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6935
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6938
    [TRAINER_JARED] =
    {
#line 6939
        .trainerName = _("JARED"),
#line 6940
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6941
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6943
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6946
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6948
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6947
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6950
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6952
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6951
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6954
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6956
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6955
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6958
    [TRAINER_HUMBERTO] =
    {
#line 6959
        .trainerName = _("HUMBERTO"),
#line 6960
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6961
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6963
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6964
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6966
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6968
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6967
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6970
    [TRAINER_PRESLEY] =
    {
#line 6971
        .trainerName = _("PRESLEY"),
#line 6972
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6973
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6975
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6976
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6978
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6980
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6979
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6982
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6984
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6983
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6986
    [TRAINER_EDWARDO] =
    {
#line 6987
        .trainerName = _("EDWARDO"),
#line 6988
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6989
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6991
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6992
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6994
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6996
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 6995
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6998
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7000
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 6999
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7002
    [TRAINER_COLIN] =
    {
#line 7003
        .trainerName = _("COLIN"),
#line 7004
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7005
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7007
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7010
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7012
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7011
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7014
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7016
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7015
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7018
    [TRAINER_ROBERT_1] =
    {
#line 7019
        .trainerName = _("ROBERT"),
#line 7020
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7021
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7023
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7024
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7026
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7028
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7027
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7030
    [TRAINER_BENNY] =
    {
#line 7031
        .trainerName = _("BENNY"),
#line 7032
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7033
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7035
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7036
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7038
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7040
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7039
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7042
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7044
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7043
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7046
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7048
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7047
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7050
    [TRAINER_CHESTER] =
    {
#line 7051
        .trainerName = _("CHESTER"),
#line 7052
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7053
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7055
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7056
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7058
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7060
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7059
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7062
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7063
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7066
    [TRAINER_ROBERT_2] =
    {
#line 7067
        .trainerName = _("ROBERT"),
#line 7068
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7069
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7071
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7072
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7074
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7076
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 7075
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7078
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7080
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 7079
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7082
    [TRAINER_ROBERT_3] =
    {
#line 7083
        .trainerName = _("ROBERT"),
#line 7084
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7085
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7087
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7088
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7090
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7092
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7091
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7094
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7096
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7095
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7098
    [TRAINER_ROBERT_4] =
    {
#line 7099
        .trainerName = _("ROBERT"),
#line 7100
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7101
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7103
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7104
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7106
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7108
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7107
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7110
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7112
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7111
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7114
    [TRAINER_ROBERT_5] =
    {
#line 7115
        .trainerName = _("ROBERT"),
#line 7116
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7117
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7119
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7120
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7122
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7124
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7123
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7126
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7128
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7127
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7130
    [TRAINER_ALEX] =
    {
#line 7131
        .trainerName = _("ALEX"),
#line 7132
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7133
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7135
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7136
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7138
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7140
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7139
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7142
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7144
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7143
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7146
    [TRAINER_BECK] =
    {
#line 7147
        .trainerName = _("BECK"),
#line 7148
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7149
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7151
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7152
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7154
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7156
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7155
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7158
    [TRAINER_YASU] =
    {
#line 7159
        .trainerName = _("YASU"),
#line 7160
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7161
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7163
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7164
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7166
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7168
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7167
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7170
    [TRAINER_TAKASHI] =
    {
#line 7171
        .trainerName = _("TAKASHI"),
#line 7172
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7173
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7175
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7176
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7178
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7180
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7179
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7182
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7184
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7183
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7186
    [TRAINER_DIANNE] =
    {
#line 7187
        .trainerName = _("DIANNE"),
#line 7188
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 7189
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 7190
F_TRAINER_FEMALE | 
#line 7191
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7192
        .items = { ITEM_FULL_RESTORE },
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7194
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7196
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7195
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7197
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 7200
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7202
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7201
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7203
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 7206
    [TRAINER_JANI] =
    {
#line 7207
        .trainerName = _("JANI"),
#line 7208
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 7209
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 7210
F_TRAINER_FEMALE | 
#line 7211
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7213
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7215
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7214
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7217
    [TRAINER_LAO_1] =
    {
#line 7218
        .trainerName = _("LAO"),
#line 7219
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7220
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7222
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7224
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7226
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7225
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7227
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7232
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7234
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7233
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7235
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7240
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7241
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7243
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 7248
    [TRAINER_LUNG] =
    {
#line 7249
        .trainerName = _("LUNG"),
#line 7250
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7251
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7253
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7255
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7257
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7256
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7259
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7261
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7260
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7263
    [TRAINER_LAO_2] =
    {
#line 7264
        .trainerName = _("LAO"),
#line 7265
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7266
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7268
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7270
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7272
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7271
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7273
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7278
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7279
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7281
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7285
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7287
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7286
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7288
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7293
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7295
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7294
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7296
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7299
    [TRAINER_LAO_3] =
    {
#line 7300
        .trainerName = _("LAO"),
#line 7301
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7302
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7304
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7306
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7308
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7307
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7309
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7314
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7316
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7315
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7317
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7322
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7324
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7323
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7325
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7329
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7331
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7330
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7332
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7335
    [TRAINER_LAO_4] =
    {
#line 7336
        .trainerName = _("LAO"),
#line 7337
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7338
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7340
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7342
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7344
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7343
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7345
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7349
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7351
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7350
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7352
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7356
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7358
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7357
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7359
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7363
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7365
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7364
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7366
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7369
    [TRAINER_LAO_5] =
    {
#line 7370
        .trainerName = _("LAO"),
#line 7371
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7372
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7374
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7376
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7378
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7377
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7379
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7383
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7385
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7384
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7386
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7391
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7393
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7392
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7394
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7399
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7399
            .heldItem = ITEM_SMOKE_BALL,
#line 7401
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7400
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7402
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7405
    [TRAINER_JOCELYN] =
    {
#line 7406
        .trainerName = _("JOCELYN"),
#line 7407
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7408
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7409
F_TRAINER_FEMALE | 
#line 7410
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7413
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7415
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7414
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7417
    [TRAINER_LAURA] =
    {
#line 7418
        .trainerName = _("LAURA"),
#line 7419
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7420
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7421
F_TRAINER_FEMALE | 
#line 7422
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7423
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7425
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7427
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7426
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7429
    [TRAINER_CYNDY_1] =
    {
#line 7430
        .trainerName = _("CYNDY"),
#line 7431
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7432
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7433
F_TRAINER_FEMALE | 
#line 7434
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7437
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7439
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7438
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7441
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7443
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7442
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7445
    [TRAINER_CORA] =
    {
#line 7446
        .trainerName = _("CORA"),
#line 7447
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7448
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7449
F_TRAINER_FEMALE | 
#line 7450
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7451
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7453
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7455
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7454
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7457
    [TRAINER_PAULA] =
    {
#line 7458
        .trainerName = _("PAULA"),
#line 7459
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7460
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7461
F_TRAINER_FEMALE | 
#line 7462
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7465
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7467
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7466
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7469
    [TRAINER_CYNDY_2] =
    {
#line 7470
        .trainerName = _("CYNDY"),
#line 7471
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7472
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7473
F_TRAINER_FEMALE | 
#line 7474
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7475
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7477
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7479
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 7478
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7481
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7483
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 7482
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7485
    [TRAINER_CYNDY_3] =
    {
#line 7486
        .trainerName = _("CYNDY"),
#line 7487
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7488
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7489
F_TRAINER_FEMALE | 
#line 7490
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7493
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7495
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 7494
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7497
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7499
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 7498
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7501
    [TRAINER_CYNDY_4] =
    {
#line 7502
        .trainerName = _("CYNDY"),
#line 7503
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7504
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7505
F_TRAINER_FEMALE | 
#line 7506
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7507
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7509
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7511
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7510
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7513
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7515
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7514
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7517
    [TRAINER_CYNDY_5] =
    {
#line 7518
        .trainerName = _("CYNDY"),
#line 7519
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7520
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7521
F_TRAINER_FEMALE | 
#line 7522
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7525
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7527
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 7526
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7529
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7531
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 7530
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7533
    [TRAINER_MADELINE_1] =
    {
#line 7534
        .trainerName = _("MADELINE"),
#line 7535
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7536
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7537
F_TRAINER_FEMALE | 
#line 7538
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7539
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7541
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7543
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7542
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7544
                MOVE_EMBER,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 7549
    [TRAINER_CLARISSA] =
    {
#line 7550
        .trainerName = _("CLARISSA"),
#line 7551
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7552
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7553
F_TRAINER_FEMALE | 
#line 7554
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7555
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7557
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7559
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7558
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7561
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7563
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7562
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7565
    [TRAINER_ANGELICA] =
    {
#line 7566
        .trainerName = _("ANGELICA"),
#line 7567
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7568
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7569
F_TRAINER_FEMALE | 
#line 7570
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7571
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7573
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7575
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7574
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7576
                MOVE_RAIN_DANCE,
                MOVE_WEATHER_BALL,
                MOVE_THUNDER,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 7581
    [TRAINER_MADELINE_2] =
    {
#line 7582
        .trainerName = _("MADELINE"),
#line 7583
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7584
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7585
F_TRAINER_FEMALE | 
#line 7586
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7589
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7591
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 7590
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7592
                MOVE_EMBER,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 7597
    [TRAINER_MADELINE_3] =
    {
#line 7598
        .trainerName = _("MADELINE"),
#line 7599
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7600
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7601
F_TRAINER_FEMALE | 
#line 7602
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7603
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7605
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7607
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7606
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7608
                MOVE_EMBER,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 7613
    [TRAINER_MADELINE_4] =
    {
#line 7614
        .trainerName = _("MADELINE"),
#line 7615
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7616
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7617
F_TRAINER_FEMALE | 
#line 7618
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7621
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7623
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7622
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7624
                MOVE_LEECH_SEED,
                MOVE_MEGA_DRAIN,
                MOVE_GRASS_WHISTLE,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 7629
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7631
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7630
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7632
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 7637
    [TRAINER_MADELINE_5] =
    {
#line 7638
        .trainerName = _("MADELINE"),
#line 7639
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7640
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7641
F_TRAINER_FEMALE | 
#line 7642
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7643
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7645
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7647
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7646
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7648
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_SOLAR_BEAM,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 7653
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7655
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7654
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7656
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
#line 7661
    [TRAINER_BEVERLY] =
    {
#line 7662
        .trainerName = _("BEVERLY"),
#line 7663
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7664
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7665
F_TRAINER_FEMALE | 
#line 7666
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7667
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7669
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7671
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7670
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7673
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7675
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7674
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7677
    [TRAINER_IMANI] =
    {
#line 7678
        .trainerName = _("IMANI"),
#line 7679
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7680
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7681
F_TRAINER_FEMALE | 
#line 7682
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7683
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7685
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7687
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7686
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7689
    [TRAINER_KYLA] =
    {
#line 7690
        .trainerName = _("KYLA"),
#line 7691
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7692
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7693
F_TRAINER_FEMALE | 
#line 7694
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7695
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7697
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7699
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7698
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7701
    [TRAINER_DENISE] =
    {
#line 7702
        .trainerName = _("DENISE"),
#line 7703
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7704
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7705
F_TRAINER_FEMALE | 
#line 7706
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7707
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7709
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7711
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7710
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7713
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7715
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7714
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7717
    [TRAINER_BETH] =
    {
#line 7718
        .trainerName = _("BETH"),
#line 7719
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7720
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7721
F_TRAINER_FEMALE | 
#line 7722
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7723
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7725
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7727
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7726
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7729
    [TRAINER_TARA] =
    {
#line 7730
        .trainerName = _("TARA"),
#line 7731
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7732
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7733
F_TRAINER_FEMALE | 
#line 7734
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7735
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7737
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7739
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7738
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7741
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7743
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7742
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7745
    [TRAINER_MISSY] =
    {
#line 7746
        .trainerName = _("MISSY"),
#line 7747
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7748
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7749
F_TRAINER_FEMALE | 
#line 7750
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7751
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7753
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7755
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7754
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7757
    [TRAINER_ALICE] =
    {
#line 7758
        .trainerName = _("ALICE"),
#line 7759
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7760
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7761
F_TRAINER_FEMALE | 
#line 7762
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7763
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7765
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7767
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7766
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7769
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7771
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7770
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7773
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7775
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7774
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7777
    [TRAINER_JENNY_1] =
    {
#line 7778
        .trainerName = _("JENNY"),
#line 7779
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7780
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7781
F_TRAINER_FEMALE | 
#line 7782
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7783
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7785
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7787
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7786
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7789
    [TRAINER_GRACE] =
    {
#line 7790
        .trainerName = _("GRACE"),
#line 7791
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7792
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7793
F_TRAINER_FEMALE | 
#line 7794
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7795
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7797
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7799
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7798
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7801
    [TRAINER_TANYA] =
    {
#line 7802
        .trainerName = _("TANYA"),
#line 7803
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7804
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7805
F_TRAINER_FEMALE | 
#line 7806
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7807
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7809
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7811
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7810
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7813
    [TRAINER_SHARON] =
    {
#line 7814
        .trainerName = _("SHARON"),
#line 7815
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7816
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7817
F_TRAINER_FEMALE | 
#line 7818
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7819
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7821
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7823
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7822
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7825
    [TRAINER_NIKKI] =
    {
#line 7826
        .trainerName = _("NIKKI"),
#line 7827
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7828
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7829
F_TRAINER_FEMALE | 
#line 7830
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7831
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7833
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7835
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7834
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7837
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7838
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7841
    [TRAINER_BRENDA] =
    {
#line 7842
        .trainerName = _("BRENDA"),
#line 7843
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7844
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7845
F_TRAINER_FEMALE | 
#line 7846
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7847
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7849
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7851
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7850
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7853
    [TRAINER_KATIE] =
    {
#line 7854
        .trainerName = _("KATIE"),
#line 7855
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7856
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7857
F_TRAINER_FEMALE | 
#line 7858
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7859
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7861
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7863
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7862
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7865
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7867
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7866
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7869
    [TRAINER_SUSIE] =
    {
#line 7870
        .trainerName = _("SUSIE"),
#line 7871
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7872
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7873
F_TRAINER_FEMALE | 
#line 7874
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7875
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7877
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7879
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7878
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7881
    [TRAINER_KARA] =
    {
#line 7882
        .trainerName = _("KARA"),
#line 7883
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7884
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7885
F_TRAINER_FEMALE | 
#line 7886
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7887
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7889
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7891
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7890
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7893
    [TRAINER_DANA] =
    {
#line 7894
        .trainerName = _("DANA"),
#line 7895
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7896
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7897
F_TRAINER_FEMALE | 
#line 7898
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7899
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7901
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7903
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7902
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7905
    [TRAINER_SIENNA] =
    {
#line 7906
        .trainerName = _("SIENNA"),
#line 7907
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7908
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7909
F_TRAINER_FEMALE | 
#line 7910
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7911
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7913
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7915
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7914
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7917
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7919
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7918
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7921
    [TRAINER_DEBRA] =
    {
#line 7922
        .trainerName = _("DEBRA"),
#line 7923
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7924
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7925
F_TRAINER_FEMALE | 
#line 7926
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7927
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7929
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7931
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7930
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7933
    [TRAINER_LINDA] =
    {
#line 7934
        .trainerName = _("LINDA"),
#line 7935
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7936
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7937
F_TRAINER_FEMALE | 
#line 7938
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7939
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7941
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7943
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7942
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7945
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7947
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7946
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7949
    [TRAINER_KAYLEE] =
    {
#line 7950
        .trainerName = _("KAYLEE"),
#line 7951
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7952
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7953
F_TRAINER_FEMALE | 
#line 7954
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7955
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7957
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7959
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7958
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7961
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7963
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7962
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7965
    [TRAINER_LAUREL] =
    {
#line 7966
        .trainerName = _("LAUREL"),
#line 7967
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7968
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7969
F_TRAINER_FEMALE | 
#line 7970
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7971
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7973
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7975
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7974
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7977
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7979
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7978
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7981
    [TRAINER_CARLEE] =
    {
#line 7982
        .trainerName = _("CARLEE"),
#line 7983
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7984
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7985
F_TRAINER_FEMALE | 
#line 7986
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7987
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7989
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7990
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7993
    [TRAINER_JENNY_2] =
    {
#line 7994
        .trainerName = _("JENNY"),
#line 7995
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7996
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7997
F_TRAINER_FEMALE | 
#line 7998
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7999
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8001
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8003
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8002
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8005
    [TRAINER_JENNY_3] =
    {
#line 8006
        .trainerName = _("JENNY"),
#line 8007
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 8008
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 8009
F_TRAINER_FEMALE | 
#line 8010
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 8011
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8013
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8015
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8014
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8017
    [TRAINER_JENNY_4] =
    {
#line 8018
        .trainerName = _("JENNY"),
#line 8019
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 8020
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 8021
F_TRAINER_FEMALE | 
#line 8022
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 8023
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8025
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8027
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8026
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8029
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8031
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8030
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8033
    [TRAINER_JENNY_5] =
    {
#line 8034
        .trainerName = _("JENNY"),
#line 8035
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 8036
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 8037
F_TRAINER_FEMALE | 
#line 8038
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 8039
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8041
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8043
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8042
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8045
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8047
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8046
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8049
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8051
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8050
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8053
    [TRAINER_HEIDI] =
    {
#line 8054
        .trainerName = _("HEIDI"),
#line 8055
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8056
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8057
F_TRAINER_FEMALE | 
#line 8058
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8059
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8061
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8063
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8062
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8064
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
            {
#line 8069
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8071
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8070
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8072
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 8077
    [TRAINER_BECKY] =
    {
#line 8078
        .trainerName = _("BECKY"),
#line 8079
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8080
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8081
F_TRAINER_FEMALE | 
#line 8082
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8085
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8086
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8088
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
                MOVE_DIG,
            },
            },
            {
#line 8093
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8095
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8094
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8096
                MOVE_ROLLOUT,
                MOVE_BUBBLE_BEAM,
                MOVE_TAIL_WHIP,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 8101
    [TRAINER_CAROL] =
    {
#line 8102
        .trainerName = _("CAROL"),
#line 8103
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8104
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8105
F_TRAINER_FEMALE | 
#line 8106
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8107
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8109
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8110
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8113
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8114
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8117
    [TRAINER_NANCY] =
    {
#line 8118
        .trainerName = _("NANCY"),
#line 8119
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8120
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8121
F_TRAINER_FEMALE | 
#line 8122
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8125
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8126
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8129
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8130
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8133
    [TRAINER_MARTHA] =
    {
#line 8134
        .trainerName = _("MARTHA"),
#line 8135
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8136
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8137
F_TRAINER_FEMALE | 
#line 8138
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8141
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8142
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8145
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8146
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8149
    [TRAINER_DIANA_1] =
    {
#line 8150
        .trainerName = _("DIANA"),
#line 8151
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8152
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8153
F_TRAINER_FEMALE | 
#line 8154
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8155
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8157
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8158
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8161
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8162
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8165
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8167
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8166
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8169
    [TRAINER_CEDRIC] =
    {
#line 8170
        .trainerName = _("CEDRIC"),
#line 8171
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 8172
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 8174
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8175
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8177
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8178
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8180
                MOVE_DESTINY_BOND,
                MOVE_SAFEGUARD,
                MOVE_COUNTER,
                MOVE_MIRROR_COAT,
            },
            },
        },
    },
#line 8185
    [TRAINER_IRENE] =
    {
#line 8186
        .trainerName = _("IRENE"),
#line 8187
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8188
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8189
F_TRAINER_FEMALE | 
#line 8190
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8193
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8194
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8197
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8198
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8201
    [TRAINER_DIANA_2] =
    {
#line 8202
        .trainerName = _("DIANA"),
#line 8203
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8204
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8205
F_TRAINER_FEMALE | 
#line 8206
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8209
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8211
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8210
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8213
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8215
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8214
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8217
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8219
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8218
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8221
    [TRAINER_DIANA_3] =
    {
#line 8222
        .trainerName = _("DIANA"),
#line 8223
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8224
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8225
F_TRAINER_FEMALE | 
#line 8226
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8227
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8229
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8231
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8230
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8233
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8235
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8234
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8237
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8239
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8238
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8241
    [TRAINER_DIANA_4] =
    {
#line 8242
        .trainerName = _("DIANA"),
#line 8243
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8244
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8245
F_TRAINER_FEMALE | 
#line 8246
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8247
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8249
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8251
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8250
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8253
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8255
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8254
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8257
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8259
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8258
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8261
    [TRAINER_DIANA_5] =
    {
#line 8262
        .trainerName = _("DIANA"),
#line 8263
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8264
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8265
F_TRAINER_FEMALE | 
#line 8266
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8267
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8269
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8271
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8270
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8273
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8275
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8274
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8277
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8279
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8278
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8281
    [TRAINER_AMY_AND_LIV_1] =
    {
#line 8282
        .trainerName = _("AMY & LIV"),
#line 8283
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8284
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8286
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8287
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8289
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8291
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8290
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8293
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8295
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8294
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8297
    [TRAINER_AMY_AND_LIV_2] =
    {
#line 8298
        .trainerName = _("AMY & LIV"),
#line 8299
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8300
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8302
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8303
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8305
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8307
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8306
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8309
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8311
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8310
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8313
    [TRAINER_GINA_AND_MIA_1] =
    {
#line 8314
        .trainerName = _("GINA & MIA"),
#line 8315
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8316
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8318
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8321
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8322
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8325
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8326
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8329
    [TRAINER_MIU_AND_YUKI] =
    {
#line 8330
        .trainerName = _("MIU & YUKI"),
#line 8331
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8332
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8334
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8335
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8337
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8339
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8338
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8341
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8343
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8342
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8345
    [TRAINER_AMY_AND_LIV_3] =
    {
#line 8346
        .trainerName = _("AMY & LIV"),
#line 8347
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8348
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8350
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8353
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8355
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8354
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8357
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8359
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8358
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8361
    [TRAINER_GINA_AND_MIA_2] =
    {
#line 8362
        .trainerName = _("GINA & MIA"),
#line 8363
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8364
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8366
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8367
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8369
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8371
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8370
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8372
                MOVE_NIGHT_SHADE,
                MOVE_DISABLE,
            },
            },
            {
#line 8375
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8377
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8376
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8378
                MOVE_ABSORB,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 8381
    [TRAINER_AMY_AND_LIV_4] =
    {
#line 8382
        .trainerName = _("AMY & LIV"),
#line 8383
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8384
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8386
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8389
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8391
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8390
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8393
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8395
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8394
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8397
    [TRAINER_AMY_AND_LIV_5] =
    {
#line 8398
        .trainerName = _("AMY & LIV"),
#line 8399
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8400
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8402
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8403
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8405
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8407
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8406
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8408
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
#line 8413
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8415
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8414
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8416
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
#line 8421
    [TRAINER_AMY_AND_LIV_6] =
    {
#line 8422
        .trainerName = _("AMY & LIV"),
#line 8423
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8424
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8426
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8429
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8431
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8430
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8432
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
#line 8437
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8439
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8438
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8440
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
#line 8445
    [TRAINER_HUEY] =
    {
#line 8446
        .trainerName = _("HUEY"),
#line 8447
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8448
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8450
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8451
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8453
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8455
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8454
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8457
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8459
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8458
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8461
    [TRAINER_EDMOND] =
    {
#line 8462
        .trainerName = _("EDMOND"),
#line 8463
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8464
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8466
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8467
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8469
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8471
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8470
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8473
    [TRAINER_ERNEST_1] =
    {
#line 8474
        .trainerName = _("ERNEST"),
#line 8475
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8476
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8478
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8479
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8481
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8483
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8482
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8485
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8487
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8486
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8489
    [TRAINER_DWAYNE] =
    {
#line 8490
        .trainerName = _("DWAYNE"),
#line 8491
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8492
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8494
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8495
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8497
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8499
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8498
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8501
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8503
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8502
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8505
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8507
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8506
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8509
    [TRAINER_PHILLIP] =
    {
#line 8510
        .trainerName = _("PHILLIP"),
#line 8511
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8512
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8514
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8515
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8517
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8519
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8518
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8521
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8523
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8522
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8525
    [TRAINER_LEONARD] =
    {
#line 8526
        .trainerName = _("LEONARD"),
#line 8527
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8528
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8530
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8531
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8533
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8535
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8534
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8537
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8539
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8538
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8541
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8543
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8542
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8545
    [TRAINER_DUNCAN] =
    {
#line 8546
        .trainerName = _("DUNCAN"),
#line 8547
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8548
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8550
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8553
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8555
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8554
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8557
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8559
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8558
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8561
    [TRAINER_ERNEST_2] =
    {
#line 8562
        .trainerName = _("ERNEST"),
#line 8563
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8564
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8566
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8567
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8569
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8571
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8570
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8573
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8575
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8574
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8577
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8579
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8578
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8581
    [TRAINER_ERNEST_3] =
    {
#line 8582
        .trainerName = _("ERNEST"),
#line 8583
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8584
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8586
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8589
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8591
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8590
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8593
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8595
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8594
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8597
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8599
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8598
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8601
    [TRAINER_ERNEST_4] =
    {
#line 8602
        .trainerName = _("ERNEST"),
#line 8603
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8604
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8606
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8607
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8609
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8611
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8610
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8613
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8615
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8614
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8617
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8619
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8618
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8621
    [TRAINER_ERNEST_5] =
    {
#line 8622
        .trainerName = _("ERNEST"),
#line 8623
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8624
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8626
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8627
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8629
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8631
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8630
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8633
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8635
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8634
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8637
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8639
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8638
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8641
    [TRAINER_ELI] =
    {
#line 8642
        .trainerName = _("ELI"),
#line 8643
        .trainerClass = TRAINER_CLASS_HIKER,
#line 8644
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 8646
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 8647
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8649
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8651
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8650
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8653
    [TRAINER_ANNIKA] =
    {
#line 8654
        .trainerName = _("ANNIKA"),
#line 8655
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 8656
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 8657
F_TRAINER_FEMALE | 
#line 8658
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8659
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8661
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8661
            .heldItem = ITEM_ORAN_BERRY,
#line 8663
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8662
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8664
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
            {
#line 8669
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8669
            .heldItem = ITEM_ORAN_BERRY,
#line 8671
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8670
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8672
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 8677
    [TRAINER_JAZMYN] =
    {
#line 8678
        .trainerName = _("JAZMYN"),
#line 8679
        .trainerClass = TRAINER_CLASS_COOLTRAINER_2,
#line 8680
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 8681
F_TRAINER_FEMALE | 
#line 8682
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8683
        .items = { ITEM_HYPER_POTION },
#line 8684
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8686
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8687
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8690
    [TRAINER_JONAS] =
    {
#line 8691
        .trainerName = _("JONAS"),
#line 8692
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 8693
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 8695
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8696
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8698
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8699
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8701
                MOVE_TOXIC,
                MOVE_THUNDER,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
#line 8706
    [TRAINER_KAYLEY] =
    {
#line 8707
        .trainerName = _("KAYLEY"),
#line 8708
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 8709
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 8710
F_TRAINER_FEMALE | 
#line 8711
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8714
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8716
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8715
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8717
                MOVE_SUNNY_DAY,
                MOVE_WEATHER_BALL,
                MOVE_FLAMETHROWER,
                MOVE_SOLAR_BEAM,
            },
            },
        },
    },
#line 8722
    [TRAINER_AURON] =
    {
#line 8723
        .trainerName = _("AURON"),
#line 8724
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 8725
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 8727
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8728
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8730
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8732
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8731
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8734
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8736
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8735
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8738
    [TRAINER_KELVIN] =
    {
#line 8739
        .trainerName = _("KELVIN"),
#line 8740
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8741
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8743
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8744
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8746
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8748
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8747
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8750
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8752
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8751
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8754
    [TRAINER_MARLEY] =
    {
#line 8755
        .trainerName = _("MARLEY"),
#line 8756
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 8757
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 8758
F_TRAINER_FEMALE | 
#line 8759
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8760
        .items = { ITEM_HYPER_POTION },
#line 8761
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8763
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8765
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8764
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8766
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
            },
            },
        },
    },
#line 8771
    [TRAINER_REYNA] =
    {
#line 8772
        .trainerName = _("REYNA"),
#line 8773
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 8774
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 8775
F_TRAINER_FEMALE | 
#line 8776
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8777
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8779
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8781
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8780
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8783
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8785
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 8784
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8787
    [TRAINER_HUDSON] =
    {
#line 8788
        .trainerName = _("HUDSON"),
#line 8789
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8790
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8792
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8793
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8795
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8797
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8796
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8799
    [TRAINER_CONOR] =
    {
#line 8800
        .trainerName = _("CONOR"),
#line 8801
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 8802
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 8804
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8805
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8807
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8808
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8811
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8813
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 8812
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8815
    [TRAINER_EDWIN_1] =
    {
#line 8816
        .trainerName = _("EDWIN"),
#line 8817
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8818
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8820
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8821
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8823
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8825
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8824
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8827
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8829
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8828
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8831
    [TRAINER_HECTOR] =
    {
#line 8832
        .trainerName = _("HECTOR"),
#line 8833
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8834
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8836
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8837
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8839
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8841
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8840
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8843
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8845
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8844
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8847
    [TRAINER_TABITHA_MOSSDEEP] =
    {
#line 8848
        .trainerName = _("TABITHA"),
#line 8849
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 8850
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 8852
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 8853
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8855
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8857
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8856
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8859
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8861
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8860
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8863
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8865
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8864
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8867
    [TRAINER_EDWIN_2] =
    {
#line 8868
        .trainerName = _("EDWIN"),
#line 8869
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8870
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8872
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8873
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8875
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8877
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8876
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8879
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8881
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8880
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8883
    [TRAINER_EDWIN_3] =
    {
#line 8884
        .trainerName = _("EDWIN"),
#line 8885
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8886
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8888
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8889
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8891
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8893
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8892
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8895
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8897
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8896
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8899
    [TRAINER_EDWIN_4] =
    {
#line 8900
        .trainerName = _("EDWIN"),
#line 8901
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8902
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8904
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8905
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8907
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8909
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8908
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8911
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8913
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8912
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8915
    [TRAINER_EDWIN_5] =
    {
#line 8916
        .trainerName = _("EDWIN"),
#line 8917
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8918
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8920
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8921
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8923
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8925
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8924
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8927
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8929
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8928
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8931
    [TRAINER_WALLY_VR_1] =
    {
#line 8932
        .trainerName = _("WALLY"),
#line 8933
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8934
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 8936
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8937
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 8938
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 8940
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8942
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8941
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8943
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 8948
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8950
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8949
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8951
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 8956
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8958
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8957
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8959
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 8964
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8966
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8965
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8967
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
#line 8972
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8974
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 8973
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8975
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 8980
    [TRAINER_BRENDAN_ROUTE_103_MUDKIP] =
    {
#line 8981
        .trainerName = _("BRENDAN"),
#line 8982
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8983
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8985
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8986
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8988
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8990
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8989
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8992
    [TRAINER_BRENDAN_ROUTE_110_MUDKIP] =
    {
#line 8993
        .trainerName = _("BRENDAN"),
#line 8994
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8995
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8997
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8998
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9000
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9002
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9001
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9004
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9006
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9005
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9008
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9010
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9009
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9012
    [TRAINER_BRENDAN_ROUTE_119_MUDKIP] =
    {
#line 9013
        .trainerName = _("BRENDAN"),
#line 9014
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9015
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9017
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9018
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9020
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9022
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9021
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9024
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9026
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9025
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9028
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9030
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9029
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9032
    [TRAINER_BRENDAN_ROUTE_103_TREECKO] =
    {
#line 9033
        .trainerName = _("BRENDAN"),
#line 9034
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9035
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9037
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9038
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9040
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9042
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9041
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9044
    [TRAINER_BRENDAN_ROUTE_110_TREECKO] =
    {
#line 9045
        .trainerName = _("BRENDAN"),
#line 9046
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9047
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9049
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9050
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9052
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9054
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9053
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9056
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9058
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9057
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9060
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9062
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9061
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9064
    [TRAINER_BRENDAN_ROUTE_119_TREECKO] =
    {
#line 9065
        .trainerName = _("BRENDAN"),
#line 9066
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9067
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9069
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9070
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9072
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9074
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9073
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9076
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9078
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9077
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9080
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9082
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9081
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9084
    [TRAINER_BRENDAN_ROUTE_103_TORCHIC] =
    {
#line 9085
        .trainerName = _("BRENDAN"),
#line 9086
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9087
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9089
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9090
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9092
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9094
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9093
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9096
    [TRAINER_BRENDAN_ROUTE_110_TORCHIC] =
    {
#line 9097
        .trainerName = _("BRENDAN"),
#line 9098
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9099
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9101
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9102
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9104
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9106
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9105
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9108
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9110
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9109
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9112
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9114
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9113
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9116
    [TRAINER_BRENDAN_ROUTE_119_TORCHIC] =
    {
#line 9117
        .trainerName = _("BRENDAN"),
#line 9118
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9119
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 9121
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9122
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9124
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9126
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9125
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9128
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9130
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9129
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9132
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9134
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9133
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9136
    [TRAINER_MAY_ROUTE_103_MUDKIP] =
    {
#line 9137
        .trainerName = _("MAY"),
#line 9138
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9139
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9140
F_TRAINER_FEMALE | 
#line 9141
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9142
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9144
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9146
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9145
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9148
    [TRAINER_MAY_ROUTE_110_MUDKIP] =
    {
#line 9149
        .trainerName = _("MAY"),
#line 9150
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9151
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9152
F_TRAINER_FEMALE | 
#line 9153
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9154
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9156
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9158
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9157
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9160
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9162
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9161
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9164
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9166
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9165
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9168
    [TRAINER_MAY_ROUTE_119_MUDKIP] =
    {
#line 9169
        .trainerName = _("MAY"),
#line 9170
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9171
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9172
F_TRAINER_FEMALE | 
#line 9173
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9174
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9176
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9178
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9177
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9180
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9182
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9181
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9184
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9186
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9185
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9188
    [TRAINER_MAY_ROUTE_103_TREECKO] =
    {
#line 9189
        .trainerName = _("MAY"),
#line 9190
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9191
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9192
F_TRAINER_FEMALE | 
#line 9193
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9194
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9196
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9197
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9200
    [TRAINER_MAY_ROUTE_110_TREECKO] =
    {
#line 9201
        .trainerName = _("MAY"),
#line 9202
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9203
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9204
F_TRAINER_FEMALE | 
#line 9205
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9206
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9208
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9210
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9209
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9212
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9214
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9213
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9216
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9218
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9217
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9220
    [TRAINER_MAY_ROUTE_119_TREECKO] =
    {
#line 9221
        .trainerName = _("MAY"),
#line 9222
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9223
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9224
F_TRAINER_FEMALE | 
#line 9225
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9226
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9228
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9230
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9229
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9232
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9234
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9233
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9236
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9238
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9237
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9240
    [TRAINER_MAY_ROUTE_103_TORCHIC] =
    {
#line 9241
        .trainerName = _("MAY"),
#line 9242
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9243
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9244
F_TRAINER_FEMALE | 
#line 9245
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9246
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9248
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9249
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9252
    [TRAINER_MAY_ROUTE_110_TORCHIC] =
    {
#line 9253
        .trainerName = _("MAY"),
#line 9254
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9255
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9256
F_TRAINER_FEMALE | 
#line 9257
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9258
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9260
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9262
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9261
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9264
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9266
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9265
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9268
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9270
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9269
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9272
    [TRAINER_MAY_ROUTE_119_TORCHIC] =
    {
#line 9273
        .trainerName = _("MAY"),
#line 9274
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9275
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9276
F_TRAINER_FEMALE | 
#line 9277
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9278
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9280
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9282
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9281
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9284
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9286
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9285
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9288
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9290
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9289
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9292
    [TRAINER_ISAAC_1] =
    {
#line 9293
        .trainerName = _("ISAAC"),
#line 9294
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9295
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9297
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9298
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9300
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9302
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9301
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9304
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9305
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9308
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9310
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9309
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9312
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9314
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9313
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9316
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9318
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9317
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9320
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9322
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9321
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9324
    [TRAINER_DAVIS] =
    {
#line 9325
        .trainerName = _("DAVIS"),
#line 9326
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9327
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 9329
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9330
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9332
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9334
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9333
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9336
    [TRAINER_MITCHELL] =
    {
#line 9337
        .trainerName = _("MITCHELL"),
#line 9338
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 9339
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 9341
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9342
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9344
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9346
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9345
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9347
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
            },
            },
            {
#line 9352
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9354
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9353
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9355
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 9360
    [TRAINER_ISAAC_2] =
    {
#line 9361
        .trainerName = _("ISAAC"),
#line 9362
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9363
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9365
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9366
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9368
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9370
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9369
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9372
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9374
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9373
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9376
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9378
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9377
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9380
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9382
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9381
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9384
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9386
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9385
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9388
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9390
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9389
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9392
    [TRAINER_ISAAC_3] =
    {
#line 9393
        .trainerName = _("ISAAC"),
#line 9394
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9395
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9397
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9398
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9400
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9402
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9401
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9404
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9406
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9405
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9408
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9410
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9409
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9412
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9414
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9413
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9416
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9418
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9417
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9420
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9422
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9421
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9424
    [TRAINER_ISAAC_4] =
    {
#line 9425
        .trainerName = _("ISAAC"),
#line 9426
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9427
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9429
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9430
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9432
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9434
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9433
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9436
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9438
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9437
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9440
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9442
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9441
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9444
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9446
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9445
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9448
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9450
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9449
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9452
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9454
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9453
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9456
    [TRAINER_ISAAC_5] =
    {
#line 9457
        .trainerName = _("ISAAC"),
#line 9458
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9459
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9461
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9462
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9464
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9466
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9465
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9468
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9470
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9469
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9472
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9474
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9473
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9476
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9478
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9477
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9480
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9482
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9481
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9484
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9486
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9485
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9488
    [TRAINER_LYDIA_1] =
    {
#line 9489
        .trainerName = _("LYDIA"),
#line 9490
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9491
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9492
F_TRAINER_FEMALE | 
#line 9493
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9494
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9496
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9497
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9500
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9502
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9501
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9504
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9506
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9505
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9508
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9510
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9509
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9512
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9514
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9513
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9516
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9518
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9517
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9520
    [TRAINER_HALLE] =
    {
#line 9521
        .trainerName = _("HALLE"),
#line 9522
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 9523
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 9524
F_TRAINER_FEMALE | 
#line 9525
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9526
        .items = { ITEM_FULL_RESTORE },
#line 9527
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9529
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9531
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9530
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9533
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9535
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9534
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9537
    [TRAINER_GARRISON] =
    {
#line 9538
        .trainerName = _("GARRISON"),
#line 9539
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 9540
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 9542
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9543
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9545
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9547
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9546
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9549
    [TRAINER_LYDIA_2] =
    {
#line 9550
        .trainerName = _("LYDIA"),
#line 9551
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9552
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9553
F_TRAINER_FEMALE | 
#line 9554
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9555
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9557
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9559
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9558
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9561
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9563
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9562
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9565
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9567
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9566
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9569
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9571
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9570
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9573
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9575
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9574
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9577
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9579
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9578
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9581
    [TRAINER_LYDIA_3] =
    {
#line 9582
        .trainerName = _("LYDIA"),
#line 9583
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9584
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9585
F_TRAINER_FEMALE | 
#line 9586
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9589
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9591
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9590
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9593
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9595
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9594
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9597
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9599
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9598
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9601
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9603
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9602
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9605
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9607
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9606
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9609
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9611
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9610
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9613
    [TRAINER_LYDIA_4] =
    {
#line 9614
        .trainerName = _("LYDIA"),
#line 9615
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9616
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9617
F_TRAINER_FEMALE | 
#line 9618
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9621
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9623
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9622
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9625
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9627
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9626
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9629
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9631
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9630
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9633
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9635
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9634
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9637
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9639
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9638
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9641
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9643
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9642
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9645
    [TRAINER_LYDIA_5] =
    {
#line 9646
        .trainerName = _("LYDIA"),
#line 9647
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9648
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9649
F_TRAINER_FEMALE | 
#line 9650
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9651
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9653
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9655
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9654
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9657
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9659
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9658
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9661
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9663
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9662
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9665
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9667
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9666
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9669
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9671
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9670
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9673
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9675
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9674
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9677
    [TRAINER_JACKSON_1] =
    {
#line 9678
        .trainerName = _("JACKSON"),
#line 9679
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9680
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9682
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9683
        .items = { ITEM_FULL_RESTORE },
#line 9684
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9686
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9688
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9687
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9690
    [TRAINER_LORENZO] =
    {
#line 9691
        .trainerName = _("LORENZO"),
#line 9692
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9693
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9695
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9696
        .items = { ITEM_FULL_RESTORE },
#line 9697
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9699
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9701
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9700
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9703
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9705
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9704
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9707
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9709
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9708
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9711
    [TRAINER_SEBASTIAN] =
    {
#line 9712
        .trainerName = _("SEBASTIAN"),
#line 9713
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9714
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9716
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9717
        .items = { ITEM_FULL_RESTORE },
#line 9718
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9720
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9722
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9721
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9724
    [TRAINER_JACKSON_2] =
    {
#line 9725
        .trainerName = _("JACKSON"),
#line 9726
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9727
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9729
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9730
        .items = { ITEM_FULL_RESTORE },
#line 9731
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9733
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9735
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9734
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9737
    [TRAINER_JACKSON_3] =
    {
#line 9738
        .trainerName = _("JACKSON"),
#line 9739
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9740
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9742
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9743
        .items = { ITEM_FULL_RESTORE },
#line 9744
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9746
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9748
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9747
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9750
    [TRAINER_JACKSON_4] =
    {
#line 9751
        .trainerName = _("JACKSON"),
#line 9752
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9753
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9755
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9756
        .items = { ITEM_FULL_RESTORE },
#line 9757
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9759
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9761
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9760
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9763
    [TRAINER_JACKSON_5] =
    {
#line 9764
        .trainerName = _("JACKSON"),
#line 9765
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9766
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9768
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9769
        .items = { ITEM_FULL_RESTORE },
#line 9770
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9772
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9774
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9773
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9776
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9778
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9777
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9780
    [TRAINER_CATHERINE_1] =
    {
#line 9781
        .trainerName = _("CATHERINE"),
#line 9782
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9783
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9784
F_TRAINER_FEMALE | 
#line 9785
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9786
        .items = { ITEM_FULL_RESTORE },
#line 9787
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9789
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9791
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9790
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9793
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9795
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9794
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9797
    [TRAINER_JENNA] =
    {
#line 9798
        .trainerName = _("JENNA"),
#line 9799
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9800
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9801
F_TRAINER_FEMALE | 
#line 9802
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9803
        .items = { ITEM_FULL_RESTORE },
#line 9804
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9806
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9808
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9807
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9810
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9812
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9811
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9814
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9816
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9815
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9818
    [TRAINER_SOPHIA] =
    {
#line 9819
        .trainerName = _("SOPHIA"),
#line 9820
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9821
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9822
F_TRAINER_FEMALE | 
#line 9823
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9824
        .items = { ITEM_FULL_RESTORE },
#line 9825
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9827
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9829
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9828
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9831
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9833
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9832
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9835
    [TRAINER_CATHERINE_2] =
    {
#line 9836
        .trainerName = _("CATHERINE"),
#line 9837
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9838
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9839
F_TRAINER_FEMALE | 
#line 9840
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9841
        .items = { ITEM_FULL_RESTORE },
#line 9842
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9844
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9846
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9845
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9848
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9850
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9849
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9852
    [TRAINER_CATHERINE_3] =
    {
#line 9853
        .trainerName = _("CATHERINE"),
#line 9854
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9855
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9856
F_TRAINER_FEMALE | 
#line 9857
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9858
        .items = { ITEM_FULL_RESTORE },
#line 9859
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9861
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9863
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9862
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9865
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9867
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9866
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9869
    [TRAINER_CATHERINE_4] =
    {
#line 9870
        .trainerName = _("CATHERINE"),
#line 9871
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9872
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9873
F_TRAINER_FEMALE | 
#line 9874
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9875
        .items = { ITEM_FULL_RESTORE },
#line 9876
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9878
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9880
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9879
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9882
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9884
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9883
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9886
    [TRAINER_CATHERINE_5] =
    {
#line 9887
        .trainerName = _("CATHERINE"),
#line 9888
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9889
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9890
F_TRAINER_FEMALE | 
#line 9891
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9892
        .items = { ITEM_FULL_RESTORE },
#line 9893
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9895
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9897
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9896
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9899
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9901
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9900
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9903
    [TRAINER_JULIO] =
    {
#line 9904
        .trainerName = _("JULIO"),
#line 9905
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 9906
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 9908
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9909
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9911
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9913
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9912
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9915
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_5] =
    {
#line 9916
        .trainerName = _("GRUNT"),
#line 9917
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 9918
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 9920
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9921
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9923
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9925
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9924
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9927
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9929
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9928
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9931
    [TRAINER_CYNTHIA] =
    {
#line 9932
        .trainerName = _("CYNTHIA"),
#line 9933
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 9934
        .trainerPic = TRAINER_PIC_CYNTHIA,
        .encounterMusic_gender = 
#line 9935
F_TRAINER_FEMALE | 
#line 9936
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 9937
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9939
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9941
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9940
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9943
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9945
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9944
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9947
    [TRAINER_GRUNT_MT_PYRE_4] =
    {
#line 9948
        .trainerName = _("GRUNT"),
#line 9949
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 9950
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 9951
F_TRAINER_FEMALE | 
#line 9952
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9953
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9955
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9957
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9956
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9959
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9961
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9960
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9963
    [TRAINER_GRUNT_JAGGED_PASS] =
    {
#line 9964
        .trainerName = _("GRUNT"),
#line 9965
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 9966
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 9968
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 9969
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9971
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9973
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9972
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9975
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9977
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9976
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9979
    [TRAINER_MARC] =
    {
#line 9980
        .trainerName = _("MARC"),
#line 9981
        .trainerClass = TRAINER_CLASS_HIKER,
#line 9982
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 9984
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9985
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9987
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9989
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9988
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9991
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9993
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 9992
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9995
    [TRAINER_BRENDEN] =
    {
#line 9996
        .trainerName = _("BRENDEN"),
#line 9997
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 9998
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 10000
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10001
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10003
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10005
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10004
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10007
    [TRAINER_LILITH] =
    {
#line 10008
        .trainerName = _("LILITH"),
#line 10009
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 10010
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 10011
F_TRAINER_FEMALE | 
#line 10012
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10013
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10015
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10017
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10016
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10019
    [TRAINER_CRISTIAN] =
    {
#line 10020
        .trainerName = _("CRISTIAN"),
#line 10021
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 10022
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 10024
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10025
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10027
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10029
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 10028
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10031
    [TRAINER_SYLVIA] =
    {
#line 10032
        .trainerName = _("SYLVIA"),
#line 10033
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 10034
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 10035
F_TRAINER_FEMALE | 
#line 10036
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10037
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10039
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10041
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10040
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10043
    [TRAINER_LEONARDO] =
    {
#line 10044
        .trainerName = _("LEONARDO"),
#line 10045
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10046
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 10048
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10049
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10051
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10053
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10052
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10055
    [TRAINER_ATHENA] =
    {
#line 10056
        .trainerName = _("ATHENA"),
#line 10057
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 10058
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 10059
F_TRAINER_FEMALE | 
#line 10060
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10061
        .items = { ITEM_HYPER_POTION },
#line 10062
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10064
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10066
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10065
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10067
                MOVE_THUNDER,
                MOVE_THUNDER_WAVE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 10071
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10073
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10072
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10074
                MOVE_SURF,
                MOVE_THIEF,
            },
            },
        },
    },
#line 10077
    [TRAINER_HARRISON] =
    {
#line 10078
        .trainerName = _("HARRISON"),
#line 10079
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10080
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 10082
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10085
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10086
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10089
    [TRAINER_GRUNT_MT_CHIMNEY_2] =
    {
#line 10090
        .trainerName = _("GRUNT"),
#line 10091
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10092
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10094
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10095
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10097
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10099
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10098
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10101
    [TRAINER_CLARENCE] =
    {
#line 10102
        .trainerName = _("CLARENCE"),
#line 10103
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10104
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 10106
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10107
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10109
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10110
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10113
    [TRAINER_TERRY] =
    {
#line 10114
        .trainerName = _("TERRY"),
#line 10115
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10116
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 10117
F_TRAINER_FEMALE | 
#line 10118
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10119
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10121
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10123
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10122
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10125
    [TRAINER_NATE] =
    {
#line 10126
        .trainerName = _("NATE"),
#line 10127
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 10128
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 10130
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 10131
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10133
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10135
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10134
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10137
    [TRAINER_KATHLEEN] =
    {
#line 10138
        .trainerName = _("KATHLEEN"),
#line 10139
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 10140
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 10141
F_TRAINER_FEMALE | 
#line 10142
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10145
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10147
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10146
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10149
    [TRAINER_CLIFFORD] =
    {
#line 10150
        .trainerName = _("CLIFFORD"),
#line 10151
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 10152
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 10154
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 10155
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10157
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10158
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10161
    [TRAINER_NICHOLAS] =
    {
#line 10162
        .trainerName = _("NICHOLAS"),
#line 10163
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10164
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 10166
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10167
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10169
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10171
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10170
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10173
    [TRAINER_GRUNT_SPACE_CENTER_3] =
    {
#line 10174
        .trainerName = _("GRUNT"),
#line 10175
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10176
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 10177
F_TRAINER_FEMALE | 
#line 10178
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10179
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10181
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10182
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10185
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10186
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10189
    [TRAINER_GRUNT_SPACE_CENTER_4] =
    {
#line 10190
        .trainerName = _("GRUNT"),
#line 10191
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10192
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10194
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10197
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10199
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10198
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10201
    [TRAINER_GRUNT_SPACE_CENTER_5] =
    {
#line 10202
        .trainerName = _("GRUNT"),
#line 10203
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10204
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10206
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10207
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10209
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10210
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10213
    [TRAINER_GRUNT_SPACE_CENTER_6] =
    {
#line 10214
        .trainerName = _("GRUNT"),
#line 10215
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10216
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10218
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10221
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10223
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10222
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10225
    [TRAINER_GRUNT_SPACE_CENTER_7] =
    {
#line 10226
        .trainerName = _("GRUNT"),
#line 10227
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10228
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10230
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10231
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10233
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10235
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10234
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10237
    [TRAINER_MACEY] =
    {
#line 10238
        .trainerName = _("MACEY"),
#line 10239
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10240
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 10241
F_TRAINER_FEMALE | 
#line 10242
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10243
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10245
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10247
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10246
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10249
    [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
    {
#line 10250
        .trainerName = _("BRENDAN"),
#line 10251
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10252
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10254
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10255
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10257
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10259
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10258
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10261
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10263
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10262
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10265
    [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
    {
#line 10266
        .trainerName = _("BRENDAN"),
#line 10267
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10268
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10270
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10273
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10275
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10274
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10277
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10279
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10278
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10281
    [TRAINER_PAXTON] =
    {
#line 10282
        .trainerName = _("PAXTON"),
#line 10283
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 10284
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 10286
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10287
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10289
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10291
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10290
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10293
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10295
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10294
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10297
    [TRAINER_ISABELLA] =
    {
#line 10298
        .trainerName = _("ISABELLA"),
#line 10299
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 10300
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 10301
F_TRAINER_FEMALE | 
#line 10302
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10303
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10305
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10307
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10306
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10309
    [TRAINER_GRUNT_WEATHER_INST_5] =
    {
#line 10310
        .trainerName = _("GRUNT"),
#line 10311
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 10312
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 10313
F_TRAINER_FEMALE | 
#line 10314
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10315
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10317
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10319
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10318
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10321
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10323
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10322
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10325
    [TRAINER_TABITHA_MT_CHIMNEY] =
    {
#line 10326
        .trainerName = _("TABITHA"),
#line 10327
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 10328
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 10330
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10331
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10333
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10335
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10334
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10337
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10339
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10338
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10341
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10343
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10342
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10345
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10347
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10346
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10349
    [TRAINER_JONATHAN] =
    {
#line 10350
        .trainerName = _("JONATHAN"),
#line 10351
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 10352
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 10354
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10355
        .items = { ITEM_HYPER_POTION },
#line 10356
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10358
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10360
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10359
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10362
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10364
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10363
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10366
    [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
    {
#line 10367
        .trainerName = _("BRENDAN"),
#line 10368
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10369
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10371
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10372
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10374
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10376
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10375
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10378
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10380
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10379
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10382
    [TRAINER_MAY_RUSTBORO_MUDKIP] =
    {
#line 10383
        .trainerName = _("MAY"),
#line 10384
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10385
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 10386
F_TRAINER_FEMALE | 
#line 10387
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10388
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10390
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10392
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10391
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10394
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10396
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10395
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10398
    [TRAINER_MAXIE_MAGMA_HIDEOUT] =
    {
#line 10399
        .trainerName = _("MAXIE"),
#line 10400
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 10401
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 10403
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10404
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 10405
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10407
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10409
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10408
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10411
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10413
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10412
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10415
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10417
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10416
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10419
    [TRAINER_MAXIE_MT_CHIMNEY] =
    {
#line 10420
        .trainerName = _("MAXIE"),
#line 10421
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 10422
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 10424
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10425
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 10426
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10428
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10430
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10429
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10432
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10434
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10433
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10436
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10438
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10437
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10440
    [TRAINER_TIANA] =
    {
#line 10441
        .trainerName = _("TIANA"),
#line 10442
        .trainerClass = TRAINER_CLASS_LASS,
#line 10443
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10444
F_TRAINER_FEMALE | 
#line 10445
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10446
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10448
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10450
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10449
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10452
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10454
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10453
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10456
    [TRAINER_HALEY_1] =
    {
#line 10457
        .trainerName = _("HALEY"),
#line 10458
        .trainerClass = TRAINER_CLASS_LASS,
#line 10459
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10460
F_TRAINER_FEMALE | 
#line 10461
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10462
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10464
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10466
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10465
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10468
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10470
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10469
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10472
    [TRAINER_JANICE] =
    {
#line 10473
        .trainerName = _("JANICE"),
#line 10474
        .trainerClass = TRAINER_CLASS_LASS,
#line 10475
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10476
F_TRAINER_FEMALE | 
#line 10477
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10478
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10480
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10482
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10481
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10484
    [TRAINER_VIVI] =
    {
#line 10485
        .trainerName = _("VIVI"),
#line 10486
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 10487
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10488
F_TRAINER_FEMALE | 
#line 10489
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10490
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10492
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10494
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10493
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10496
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10498
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10497
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10500
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10502
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10501
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10504
    [TRAINER_HALEY_2] =
    {
#line 10505
        .trainerName = _("HALEY"),
#line 10506
        .trainerClass = TRAINER_CLASS_LASS,
#line 10507
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10508
F_TRAINER_FEMALE | 
#line 10509
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10510
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10512
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10514
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10513
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10516
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10518
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10517
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10520
    [TRAINER_HALEY_3] =
    {
#line 10521
        .trainerName = _("HALEY"),
#line 10522
        .trainerClass = TRAINER_CLASS_LASS,
#line 10523
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10524
F_TRAINER_FEMALE | 
#line 10525
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10526
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10528
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10530
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10529
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10532
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10534
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10533
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10536
    [TRAINER_HALEY_4] =
    {
#line 10537
        .trainerName = _("HALEY"),
#line 10538
        .trainerClass = TRAINER_CLASS_LASS,
#line 10539
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10540
F_TRAINER_FEMALE | 
#line 10541
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10542
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10544
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10546
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10545
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10548
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10550
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10549
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10552
    [TRAINER_HALEY_5] =
    {
#line 10553
        .trainerName = _("HALEY"),
#line 10554
        .trainerClass = TRAINER_CLASS_LASS,
#line 10555
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10556
F_TRAINER_FEMALE | 
#line 10557
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10558
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10560
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10562
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10561
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10564
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10566
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10565
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10568
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10570
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10569
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10572
    [TRAINER_SALLY] =
    {
#line 10573
        .trainerName = _("SALLY"),
#line 10574
        .trainerClass = TRAINER_CLASS_LASS,
#line 10575
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10576
F_TRAINER_FEMALE | 
#line 10577
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10578
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10580
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10582
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10581
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10584
    [TRAINER_ROBIN] =
    {
#line 10585
        .trainerName = _("ROBIN"),
#line 10586
        .trainerClass = TRAINER_CLASS_LASS,
#line 10587
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10588
F_TRAINER_FEMALE | 
#line 10589
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10590
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10592
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10594
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10593
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10596
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10598
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10597
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10600
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10602
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10601
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10604
    [TRAINER_ANDREA] =
    {
#line 10605
        .trainerName = _("ANDREA"),
#line 10606
        .trainerClass = TRAINER_CLASS_LASS,
#line 10607
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10608
F_TRAINER_FEMALE | 
#line 10609
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10610
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10612
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10614
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10613
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10616
    [TRAINER_CRISSY] =
    {
#line 10617
        .trainerName = _("CRISSY"),
#line 10618
        .trainerClass = TRAINER_CLASS_LASS,
#line 10619
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10620
F_TRAINER_FEMALE | 
#line 10621
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10622
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10624
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10626
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10625
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10628
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10630
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10629
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10632
    [TRAINER_RICK] =
    {
#line 10633
        .trainerName = _("RICK"),
#line 10634
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10635
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10637
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10638
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10640
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10642
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10641
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10644
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10646
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10645
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10648
    [TRAINER_LYLE] =
    {
#line 10649
        .trainerName = _("LYLE"),
#line 10650
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10651
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10653
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10654
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10656
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10658
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10657
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10660
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10662
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10661
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10664
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10666
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10665
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10668
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10670
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10669
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10672
    [TRAINER_JOSE] =
    {
#line 10673
        .trainerName = _("JOSE"),
#line 10674
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10675
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10677
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10678
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10680
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10682
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10681
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10684
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10686
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10685
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10688
    [TRAINER_DOUG] =
    {
#line 10689
        .trainerName = _("DOUG"),
#line 10690
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10691
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10693
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10694
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10696
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10698
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10697
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10700
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10702
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10701
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10704
    [TRAINER_GREG] =
    {
#line 10705
        .trainerName = _("GREG"),
#line 10706
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10707
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10709
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10710
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10712
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10714
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10713
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10716
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10718
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10717
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10720
    [TRAINER_KENT] =
    {
#line 10721
        .trainerName = _("KENT"),
#line 10722
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10723
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10725
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10726
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10728
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10730
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10729
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10732
    [TRAINER_JAMES_1] =
    {
#line 10733
        .trainerName = _("JAMES"),
#line 10734
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10735
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10737
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10738
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10740
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10741
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10744
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10746
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10745
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10748
    [TRAINER_JAMES_2] =
    {
#line 10749
        .trainerName = _("JAMES"),
#line 10750
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10751
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10753
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10754
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10756
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10758
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10757
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10760
    [TRAINER_JAMES_3] =
    {
#line 10761
        .trainerName = _("JAMES"),
#line 10762
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10763
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10765
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10766
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10768
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10770
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10769
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10772
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10774
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10773
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10776
    [TRAINER_JAMES_4] =
    {
#line 10777
        .trainerName = _("JAMES"),
#line 10778
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10779
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10781
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10782
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10784
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10786
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10785
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10788
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10790
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10789
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10792
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10794
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10793
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10796
    [TRAINER_JAMES_5] =
    {
#line 10797
        .trainerName = _("JAMES"),
#line 10798
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10799
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10801
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10802
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10804
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10806
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10805
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10808
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10810
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10809
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10812
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10814
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10813
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10816
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10818
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10817
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10820
    [TRAINER_BRICE] =
    {
#line 10821
        .trainerName = _("BRICE"),
#line 10822
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10823
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10825
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10826
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10828
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10829
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10832
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10834
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10833
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10836
    [TRAINER_TRENT_1] =
    {
#line 10837
        .trainerName = _("TRENT"),
#line 10838
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10839
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10841
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10842
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10844
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10846
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10845
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10848
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10850
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10849
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10852
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10854
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10853
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10856
    [TRAINER_LENNY] =
    {
#line 10857
        .trainerName = _("LENNY"),
#line 10858
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10859
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10861
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10862
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10864
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10866
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10865
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10868
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10870
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10869
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10872
    [TRAINER_LUCAS_1] =
    {
#line 10873
        .trainerName = _("LUCAS"),
#line 10874
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10875
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10877
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10878
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10880
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10882
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10881
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10884
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10886
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10885
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10888
    [TRAINER_ALAN] =
    {
#line 10889
        .trainerName = _("ALAN"),
#line 10890
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10891
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10893
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10894
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10896
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10898
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10897
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10900
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10902
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10901
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10904
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10906
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10905
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10908
    [TRAINER_CLARK] =
    {
#line 10909
        .trainerName = _("CLARK"),
#line 10910
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10911
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10913
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10914
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10916
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10918
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10917
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10920
    [TRAINER_ERIC] =
    {
#line 10921
        .trainerName = _("ERIC"),
#line 10922
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10923
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10925
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10926
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10928
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10930
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10929
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10932
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10934
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10933
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10936
    [TRAINER_LUCAS_2] =
    {
#line 10937
        .trainerName = _("LUCAS"),
#line 10938
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10939
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10941
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10942
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10944
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10946
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10945
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10947
                MOVE_SPLASH,
                MOVE_WATER_GUN,
            },
            },
        },
    },
#line 10950
    [TRAINER_MIKE_1] =
    {
#line 10951
        .trainerName = _("MIKE"),
#line 10952
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10953
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10955
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10958
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10959
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10961
                MOVE_GUST,
                MOVE_GROWL,
            },
            },
            {
#line 10964
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10966
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10965
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10967
                MOVE_BITE,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 10970
    [TRAINER_MIKE_2] =
    {
#line 10971
        .trainerName = _("MIKE"),
#line 10972
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10973
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10975
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10976
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10978
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10980
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10979
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10982
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10984
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10983
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10986
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10988
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10987
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10990
    [TRAINER_TRENT_2] =
    {
#line 10991
        .trainerName = _("TRENT"),
#line 10992
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10993
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10995
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10996
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10998
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11000
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10999
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11002
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11004
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11003
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11006
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11008
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11007
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11010
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11012
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11011
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11014
    [TRAINER_TRENT_3] =
    {
#line 11015
        .trainerName = _("TRENT"),
#line 11016
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11017
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 11019
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11020
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11022
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11024
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11023
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11026
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11028
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11027
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11030
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11032
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11031
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11034
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11036
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11035
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11038
    [TRAINER_TRENT_4] =
    {
#line 11039
        .trainerName = _("TRENT"),
#line 11040
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11041
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 11043
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11044
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11046
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11048
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11047
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11050
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11052
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11051
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11054
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11056
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11055
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11058
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11060
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11059
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11062
    [TRAINER_TRENT_5] =
    {
#line 11063
        .trainerName = _("TRENT"),
#line 11064
        .trainerClass = TRAINER_CLASS_HIKER,
#line 11065
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 11067
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11070
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11072
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11071
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11074
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11076
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11075
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11078
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11080
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11079
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11082
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11084
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11083
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11086
    [TRAINER_DEZ_AND_LUKE] =
    {
#line 11087
        .trainerName = _("DEZ & LUKE"),
#line 11088
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11089
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11091
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11092
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11094
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11096
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11095
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11098
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11100
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11099
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11102
    [TRAINER_LEA_AND_JED] =
    {
#line 11103
        .trainerName = _("LEA & JED"),
#line 11104
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11105
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11107
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11108
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11110
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11112
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11111
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11114
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11116
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11115
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11118
    [TRAINER_KIRA_AND_DAN_1] =
    {
#line 11119
        .trainerName = _("KIRA & DAN"),
#line 11120
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11121
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11123
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11124
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11126
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11128
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11127
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11130
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11132
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11131
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11134
    [TRAINER_KIRA_AND_DAN_2] =
    {
#line 11135
        .trainerName = _("KIRA & DAN"),
#line 11136
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11137
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11139
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11140
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11142
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11144
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11143
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11146
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11148
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11147
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11150
    [TRAINER_KIRA_AND_DAN_3] =
    {
#line 11151
        .trainerName = _("KIRA & DAN"),
#line 11152
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11153
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11155
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11156
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11158
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11160
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11159
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11162
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11164
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11163
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11166
    [TRAINER_KIRA_AND_DAN_4] =
    {
#line 11167
        .trainerName = _("KIRA & DAN"),
#line 11168
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11169
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11171
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11172
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11174
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11176
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11175
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11178
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11180
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11179
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11182
    [TRAINER_KIRA_AND_DAN_5] =
    {
#line 11183
        .trainerName = _("KIRA & DAN"),
#line 11184
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11185
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11187
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11188
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11190
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11192
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11191
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11194
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11196
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11195
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11198
    [TRAINER_JOHANNA] =
    {
#line 11199
        .trainerName = _("JOHANNA"),
#line 11200
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 11201
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 11202
F_TRAINER_FEMALE | 
#line 11203
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11204
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11206
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11208
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11207
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11210
    [TRAINER_GERALD] =
    {
#line 11211
        .trainerName = _("GERALD"),
#line 11212
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11213
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 11215
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11216
        .items = { ITEM_HYPER_POTION },
#line 11217
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11219
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11221
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11220
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11222
                MOVE_FLAMETHROWER,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
                MOVE_BIND,
            },
            },
        },
    },
#line 11227
    [TRAINER_VIVIAN] =
    {
#line 11228
        .trainerName = _("VIVIAN"),
#line 11229
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 11230
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 11231
F_TRAINER_FEMALE | 
#line 11232
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11233
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11235
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11237
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11236
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11238
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_THUNDER_PUNCH,
            },
            },
            {
#line 11243
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11245
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11244
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11246
                MOVE_THUNDER_PUNCH,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_MEDITATE,
            },
            },
        },
    },
#line 11251
    [TRAINER_DANIELLE] =
    {
#line 11252
        .trainerName = _("DANIELLE"),
#line 11253
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 11254
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 11255
F_TRAINER_FEMALE | 
#line 11256
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11257
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11259
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11261
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11260
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11262
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_FIRE_PUNCH,
            },
            },
        },
    },
#line 11267
    [TRAINER_HIDEO] =
    {
#line 11268
        .trainerName = _("HIDEO"),
#line 11269
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11270
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11272
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11273
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11275
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11277
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11276
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11278
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 11283
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11285
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11284
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11286
                MOVE_TACKLE,
                MOVE_POISON_GAS,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
#line 11291
    [TRAINER_KEIGO] =
    {
#line 11292
        .trainerName = _("KEIGO"),
#line 11293
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11294
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11296
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11297
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11299
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11301
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11300
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11302
                MOVE_POISON_GAS,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 11307
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11309
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11308
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11310
                MOVE_SAND_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_FURY_CUTTER,
                MOVE_SWORDS_DANCE,
            },
            },
        },
    },
#line 11315
    [TRAINER_RILEY] =
    {
#line 11316
        .trainerName = _("RILEY"),
#line 11317
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11318
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11320
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11321
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11323
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11325
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11324
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11326
                MOVE_LEECH_LIFE,
                MOVE_FURY_SWIPES,
                MOVE_MIND_READER,
                MOVE_DIG,
            },
            },
            {
#line 11331
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11333
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11332
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11334
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
#line 11339
    [TRAINER_FLINT] =
    {
#line 11340
        .trainerName = _("FLINT"),
#line 11341
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11342
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 11344
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11345
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11347
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11349
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11348
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11351
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11353
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11352
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11355
    [TRAINER_ASHLEY] =
    {
#line 11356
        .trainerName = _("ASHLEY"),
#line 11357
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11358
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 11359
F_TRAINER_FEMALE | 
#line 11360
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11361
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11363
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11365
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11364
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11367
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11369
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11368
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11371
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11373
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11372
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11375
    [TRAINER_WALLY_MAUVILLE] =
    {
#line 11376
        .trainerName = _("WALLY"),
#line 11377
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11378
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11380
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11381
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11383
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11385
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11384
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11387
    [TRAINER_WALLY_VR_2] =
    {
#line 11388
        .trainerName = _("WALLY"),
#line 11389
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11390
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11392
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11393
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11394
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11396
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11398
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11397
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11399
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11404
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11406
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11405
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11407
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11412
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11414
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11413
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11415
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11420
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11422
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11421
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11423
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
#line 11428
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11430
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11429
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11431
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11436
    [TRAINER_WALLY_VR_3] =
    {
#line 11437
        .trainerName = _("WALLY"),
#line 11438
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11439
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11441
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11442
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11443
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11445
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11447
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11446
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11448
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11453
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11455
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11454
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11456
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11461
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11463
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11462
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11464
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11469
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11471
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11470
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11472
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
#line 11477
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11479
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11478
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11480
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11485
    [TRAINER_WALLY_VR_4] =
    {
#line 11486
        .trainerName = _("WALLY"),
#line 11487
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11488
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11490
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11491
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11492
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11494
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11496
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11495
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11497
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11502
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11504
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11503
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11505
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11510
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11512
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11511
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11513
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11518
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11520
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11519
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11521
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
#line 11526
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11528
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11527
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11529
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11534
    [TRAINER_WALLY_VR_5] =
    {
#line 11535
        .trainerName = _("WALLY"),
#line 11536
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11537
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11539
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11540
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11541
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11543
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11545
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11544
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11546
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11551
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11553
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11552
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11554
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11559
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11561
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11560
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11562
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11567
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11569
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11568
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11570
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
#line 11575
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11577
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11576
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11578
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11583
    [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
    {
#line 11584
        .trainerName = _("BRENDAN"),
#line 11585
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11586
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11588
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11589
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11591
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11593
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11592
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11595
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11597
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11596
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11599
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11601
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11600
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11603
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11605
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11604
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11607
    [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
    {
#line 11608
        .trainerName = _("BRENDAN"),
#line 11609
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11610
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11612
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11613
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11615
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11617
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11616
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11619
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11621
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11620
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11623
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11625
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11624
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11627
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11629
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11628
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11631
    [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
    {
#line 11632
        .trainerName = _("BRENDAN"),
#line 11633
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11634
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11636
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11637
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11639
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11641
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11640
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11643
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11645
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11644
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11647
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11649
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11648
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11651
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11653
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11652
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11655
    [TRAINER_MAY_LILYCOVE_MUDKIP] =
    {
#line 11656
        .trainerName = _("MAY"),
#line 11657
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11658
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11659
F_TRAINER_FEMALE | 
#line 11660
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11661
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11663
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11665
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11664
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11667
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11669
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11668
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11671
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11673
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11672
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11675
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11677
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11676
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11679
    [TRAINER_MAY_LILYCOVE_TREECKO] =
    {
#line 11680
        .trainerName = _("MAY"),
#line 11681
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11682
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11683
F_TRAINER_FEMALE | 
#line 11684
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11685
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11687
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11689
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11688
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11691
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11693
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11692
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11695
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11697
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11696
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11699
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11701
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11700
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11703
    [TRAINER_MAY_LILYCOVE_TORCHIC] =
    {
#line 11704
        .trainerName = _("MAY"),
#line 11705
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11706
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11707
F_TRAINER_FEMALE | 
#line 11708
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11709
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11711
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11713
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11712
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11715
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11717
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11716
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11719
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11721
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11720
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11723
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11725
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11724
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11727
    [TRAINER_JONAH] =
    {
#line 11728
        .trainerName = _("JONAH"),
#line 11729
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11730
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11732
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11733
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11735
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11737
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11736
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11739
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11741
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11740
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11743
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11745
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11744
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11747
    [TRAINER_HENRY] =
    {
#line 11748
        .trainerName = _("HENRY"),
#line 11749
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11750
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11752
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11753
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11755
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11757
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11756
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11759
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11761
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11760
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11763
    [TRAINER_ROGER] =
    {
#line 11764
        .trainerName = _("ROGER"),
#line 11765
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11766
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11768
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11769
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11771
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11773
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11772
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11775
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11777
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11776
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11779
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11781
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11780
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11783
    [TRAINER_ALEXA] =
    {
#line 11784
        .trainerName = _("ALEXA"),
#line 11785
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11786
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 11787
F_TRAINER_FEMALE | 
#line 11788
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11789
        .items = { ITEM_FULL_RESTORE },
#line 11790
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11792
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11794
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11793
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11796
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11798
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11797
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11800
    [TRAINER_RUBEN] =
    {
#line 11801
        .trainerName = _("RUBEN"),
#line 11802
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11803
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 11805
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11806
        .items = { ITEM_HYPER_POTION },
#line 11807
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11809
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11811
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11810
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11813
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11815
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11814
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11817
    [TRAINER_KOJI_1] =
    {
#line 11818
        .trainerName = _("KOJI"),
#line 11819
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 11820
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 11822
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11823
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11825
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11826
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11829
    [TRAINER_WAYNE] =
    {
#line 11830
        .trainerName = _("WAYNE"),
#line 11831
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11832
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11834
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11837
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11838
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11841
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11843
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11842
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11845
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11847
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11846
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11849
    [TRAINER_AIDAN] =
    {
#line 11850
        .trainerName = _("AIDAN"),
#line 11851
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 11852
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 11854
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11855
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11857
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11859
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11858
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11861
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11863
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11862
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11865
    [TRAINER_REED] =
    {
#line 11866
        .trainerName = _("REED"),
#line 11867
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 11868
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 11870
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 11871
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11873
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11875
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11874
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11877
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11879
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11878
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11881
    [TRAINER_TISHA] =
    {
#line 11882
        .trainerName = _("TISHA"),
#line 11883
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 11884
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 11885
F_TRAINER_FEMALE | 
#line 11886
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 11887
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11889
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11891
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11890
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11893
    [TRAINER_TORI_AND_TIA] =
    {
#line 11894
        .trainerName = _("TORI & TIA"),
#line 11895
        .trainerClass = TRAINER_CLASS_TWINS,
#line 11896
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 11898
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11899
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11901
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11903
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11902
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11905
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11907
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11906
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11909
    [TRAINER_KIM_AND_IRIS] =
    {
#line 11910
        .trainerName = _("KIM & IRIS"),
#line 11911
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 11912
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 11914
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11915
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11917
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11919
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11918
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11920
                MOVE_SING,
                MOVE_FURY_ATTACK,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 11925
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11926
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11928
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_REST,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 11933
    [TRAINER_TYRA_AND_IVY] =
    {
#line 11934
        .trainerName = _("TYRA & IVY"),
#line 11935
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 11936
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 11938
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11939
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11941
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11943
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11942
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11944
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
                MOVE_MEGA_DRAIN,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 11949
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11951
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11950
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11952
                MOVE_DEFENSE_CURL,
                MOVE_ROLLOUT,
                MOVE_MUD_SPORT,
                MOVE_ROCK_THROW,
            },
            },
        },
    },
#line 11957
    [TRAINER_MEL_AND_PAUL] =
    {
#line 11958
        .trainerName = _("MEL & PAUL"),
#line 11959
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11960
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11962
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11963
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11965
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11967
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11966
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11968
                MOVE_GUST,
                MOVE_PSYBEAM,
                MOVE_TOXIC,
                MOVE_PROTECT,
            },
            },
            {
#line 11973
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11975
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11974
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11976
                MOVE_GUST,
                MOVE_MEGA_DRAIN,
                MOVE_ATTRACT,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 11981
    [TRAINER_JOHN_AND_JAY_1] =
    {
#line 11982
        .trainerName = _("JOHN & JAY"),
#line 11983
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11984
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11986
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11987
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11989
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11991
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11990
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11992
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11997
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11999
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11998
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12000
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 12005
    [TRAINER_JOHN_AND_JAY_2] =
    {
#line 12006
        .trainerName = _("JOHN & JAY"),
#line 12007
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 12008
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 12010
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12011
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12013
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12015
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 12014
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12016
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 12021
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12023
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 12022
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12024
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 12029
    [TRAINER_JOHN_AND_JAY_3] =
    {
#line 12030
        .trainerName = _("JOHN & JAY"),
#line 12031
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 12032
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 12034
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12035
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12037
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12039
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12038
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12040
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 12045
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12047
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 12046
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12048
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 12053
    [TRAINER_JOHN_AND_JAY_4] =
    {
#line 12054
        .trainerName = _("JOHN & JAY"),
#line 12055
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 12056
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 12058
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12059
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12061
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12063
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 12062
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12064
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 12069
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12071
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 12070
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12072
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 12077
    [TRAINER_JOHN_AND_JAY_5] =
    {
#line 12078
        .trainerName = _("JOHN & JAY"),
#line 12079
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 12080
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 12082
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12083
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12085
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12087
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 12086
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12088
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 12093
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12095
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 12094
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 12096
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 12101
    [TRAINER_RELI_AND_IAN] =
    {
#line 12102
        .trainerName = _("RELI & IAN"),
#line 12103
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12104
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12106
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12107
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12109
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12110
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12113
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12114
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12117
    [TRAINER_LILA_AND_ROY_1] =
    {
#line 12118
        .trainerName = _("LILA & ROY"),
#line 12119
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12120
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12122
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12125
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12126
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12129
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12130
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12133
    [TRAINER_LILA_AND_ROY_2] =
    {
#line 12134
        .trainerName = _("LILA & ROY"),
#line 12135
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12136
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12138
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12141
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12142
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12145
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12146
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12149
    [TRAINER_LILA_AND_ROY_3] =
    {
#line 12150
        .trainerName = _("LILA & ROY"),
#line 12151
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12152
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12154
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12155
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12157
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12158
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12161
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12162
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12165
    [TRAINER_LILA_AND_ROY_4] =
    {
#line 12166
        .trainerName = _("LILA & ROY"),
#line 12167
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12168
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12170
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12173
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12174
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12177
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12178
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12181
    [TRAINER_LILA_AND_ROY_5] =
    {
#line 12182
        .trainerName = _("LILA & ROY"),
#line 12183
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12184
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12186
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12187
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12189
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12190
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12193
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12194
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12197
    [TRAINER_LISA_AND_RAY] =
    {
#line 12198
        .trainerName = _("LISA & RAY"),
#line 12199
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12200
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12202
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12205
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12207
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12206
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12209
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12211
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12210
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12213
    [TRAINER_CHRIS] =
    {
#line 12214
        .trainerName = _("CHRIS"),
#line 12215
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12216
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12218
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12221
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12223
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12222
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12225
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12227
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12226
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12229
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12231
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12230
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12233
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12235
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12234
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12237
    [TRAINER_DAWSON] =
    {
#line 12238
        .trainerName = _("DAWSON"),
#line 12239
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 12240
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 12242
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 12243
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12245
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12245
            .heldItem = ITEM_NUGGET,
#line 12247
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12246
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12249
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12250
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12253
    [TRAINER_SARAH] =
    {
#line 12254
        .trainerName = _("SARAH"),
#line 12255
        .trainerClass = TRAINER_CLASS_LADY,
#line 12256
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 12257
F_TRAINER_FEMALE | 
#line 12258
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12259
        .items = { ITEM_FULL_RESTORE },
#line 12260
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12262
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12264
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12263
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12266
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12266
            .heldItem = ITEM_NUGGET,
#line 12268
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12267
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12270
    [TRAINER_DARIAN] =
    {
#line 12271
        .trainerName = _("DARIAN"),
#line 12272
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12273
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12275
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12276
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12278
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12279
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12282
    [TRAINER_HAILEY] =
    {
#line 12283
        .trainerName = _("HAILEY"),
#line 12284
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 12285
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 12286
F_TRAINER_FEMALE | 
#line 12287
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12288
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12290
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12292
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12291
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12294
    [TRAINER_CHANDLER] =
    {
#line 12295
        .trainerName = _("CHANDLER"),
#line 12296
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 12297
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 12299
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12300
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12302
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12304
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12303
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12306
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12308
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12307
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12310
    [TRAINER_KALEB] =
    {
#line 12311
        .trainerName = _("KALEB"),
#line 12312
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 12313
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 12315
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 12316
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12318
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12318
            .heldItem = ITEM_ORAN_BERRY,
#line 12320
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12319
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12322
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12322
            .heldItem = ITEM_ORAN_BERRY,
#line 12324
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12323
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12326
    [TRAINER_JOSEPH] =
    {
#line 12327
        .trainerName = _("JOSEPH"),
#line 12328
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 12329
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 12331
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12332
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12334
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12336
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12335
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12338
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12340
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12339
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12342
    [TRAINER_ALYSSA] =
    {
#line 12343
        .trainerName = _("ALYSSA"),
#line 12344
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 12345
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 12346
F_TRAINER_FEMALE | 
#line 12347
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12348
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12350
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12352
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12351
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12354
    [TRAINER_MARCOS] =
    {
#line 12355
        .trainerName = _("MARCOS"),
#line 12356
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 12357
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 12359
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12362
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12364
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 12363
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12366
    [TRAINER_RHETT] =
    {
#line 12367
        .trainerName = _("RHETT"),
#line 12368
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12369
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 12371
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12372
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12374
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12376
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 12375
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12378
    [TRAINER_TYRON] =
    {
#line 12379
        .trainerName = _("TYRON"),
#line 12380
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12381
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12383
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12384
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12386
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12388
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12387
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12390
    [TRAINER_CELINA] =
    {
#line 12391
        .trainerName = _("CELINA"),
#line 12392
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 12393
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 12394
F_TRAINER_FEMALE | 
#line 12395
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12396
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12398
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12400
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12399
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12402
    [TRAINER_BIANCA] =
    {
#line 12403
        .trainerName = _("BIANCA"),
#line 12404
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12405
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12406
F_TRAINER_FEMALE | 
#line 12407
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12408
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12410
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12412
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12411
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12414
    [TRAINER_HAYDEN] =
    {
#line 12415
        .trainerName = _("HAYDEN"),
#line 12416
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 12417
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 12419
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12420
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12422
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12424
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12423
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12426
    [TRAINER_SOPHIE] =
    {
#line 12427
        .trainerName = _("SOPHIE"),
#line 12428
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12429
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12430
F_TRAINER_FEMALE | 
#line 12431
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12432
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12434
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12436
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12435
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12438
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12440
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12439
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12442
    [TRAINER_COBY] =
    {
#line 12443
        .trainerName = _("COBY"),
#line 12444
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12445
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12447
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12448
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12450
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12451
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12454
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12456
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12455
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12458
    [TRAINER_LAWRENCE] =
    {
#line 12459
        .trainerName = _("LAWRENCE"),
#line 12460
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12461
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12463
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12464
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12466
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12468
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12467
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12470
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12472
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12471
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12474
    [TRAINER_WYATT] =
    {
#line 12475
        .trainerName = _("WYATT"),
#line 12476
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 12477
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 12479
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12480
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12482
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12484
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12483
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12486
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12488
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12487
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12490
    [TRAINER_ANGELINA] =
    {
#line 12491
        .trainerName = _("ANGELINA"),
#line 12492
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12493
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12494
F_TRAINER_FEMALE | 
#line 12495
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12496
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12498
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12500
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12499
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12502
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12504
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12503
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12506
    [TRAINER_KAI] =
    {
#line 12507
        .trainerName = _("KAI"),
#line 12508
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12509
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12511
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12512
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12514
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12516
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12515
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12518
    [TRAINER_CHARLOTTE] =
    {
#line 12519
        .trainerName = _("CHARLOTTE"),
#line 12520
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12521
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12522
F_TRAINER_FEMALE | 
#line 12523
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12524
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12526
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12528
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12527
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12530
    [TRAINER_DEANDRE] =
    {
#line 12531
        .trainerName = _("DEANDRE"),
#line 12532
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 12533
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 12535
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12536
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12538
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12540
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12539
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12542
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12544
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12543
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12546
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12548
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12547
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12550
    [TRAINER_GRUNT_MAGMA_HIDEOUT_1] =
    {
#line 12551
        .trainerName = _("GRUNT"),
#line 12552
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12553
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12555
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12556
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12558
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12560
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12559
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12562
    [TRAINER_GRUNT_MAGMA_HIDEOUT_2] =
    {
#line 12563
        .trainerName = _("GRUNT"),
#line 12564
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12565
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12567
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12568
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12570
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12572
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12571
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12574
    [TRAINER_GRUNT_MAGMA_HIDEOUT_3] =
    {
#line 12575
        .trainerName = _("GRUNT"),
#line 12576
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12577
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12579
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12582
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12583
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12586
    [TRAINER_GRUNT_MAGMA_HIDEOUT_4] =
    {
#line 12587
        .trainerName = _("GRUNT"),
#line 12588
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12589
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12591
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12594
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12595
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12598
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12600
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12599
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12602
    [TRAINER_GRUNT_MAGMA_HIDEOUT_5] =
    {
#line 12603
        .trainerName = _("GRUNT"),
#line 12604
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12605
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12607
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12610
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12611
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12614
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12616
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12615
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12618
    [TRAINER_GRUNT_MAGMA_HIDEOUT_6] =
    {
#line 12619
        .trainerName = _("GRUNT"),
#line 12620
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12621
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12623
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12624
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12626
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12628
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12627
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12630
    [TRAINER_GRUNT_MAGMA_HIDEOUT_7] =
    {
#line 12631
        .trainerName = _("GRUNT"),
#line 12632
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12633
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12635
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12636
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12638
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12640
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12639
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12642
    [TRAINER_GRUNT_MAGMA_HIDEOUT_8] =
    {
#line 12643
        .trainerName = _("GRUNT"),
#line 12644
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12645
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12647
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12648
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12650
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12652
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12651
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12654
    [TRAINER_GRUNT_MAGMA_HIDEOUT_9] =
    {
#line 12655
        .trainerName = _("GRUNT"),
#line 12656
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12657
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12659
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12660
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12662
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12664
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12663
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12666
    [TRAINER_GRUNT_MAGMA_HIDEOUT_10] =
    {
#line 12667
        .trainerName = _("GRUNT"),
#line 12668
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12669
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12671
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12672
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12674
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12676
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12675
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12678
    [TRAINER_GRUNT_MAGMA_HIDEOUT_11] =
    {
#line 12679
        .trainerName = _("GRUNT"),
#line 12680
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12681
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12683
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12684
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12686
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12687
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12690
    [TRAINER_GRUNT_MAGMA_HIDEOUT_12] =
    {
#line 12691
        .trainerName = _("GRUNT"),
#line 12692
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12693
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12695
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12698
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12699
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12702
    [TRAINER_GRUNT_MAGMA_HIDEOUT_13] =
    {
#line 12703
        .trainerName = _("GRUNT"),
#line 12704
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12705
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12707
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12708
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12710
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12712
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12711
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12714
    [TRAINER_GRUNT_MAGMA_HIDEOUT_14] =
    {
#line 12715
        .trainerName = _("GRUNT"),
#line 12716
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12717
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12718
F_TRAINER_FEMALE | 
#line 12719
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12720
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12722
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12724
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12723
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12726
    [TRAINER_GRUNT_MAGMA_HIDEOUT_15] =
    {
#line 12727
        .trainerName = _("GRUNT"),
#line 12728
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12729
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12730
F_TRAINER_FEMALE | 
#line 12731
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12732
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12734
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12736
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12735
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12738
    [TRAINER_GRUNT_MAGMA_HIDEOUT_16] =
    {
#line 12739
        .trainerName = _("GRUNT"),
#line 12740
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12741
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12742
F_TRAINER_FEMALE | 
#line 12743
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12744
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12746
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12748
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12747
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12750
    [TRAINER_TABITHA_MAGMA_HIDEOUT] =
    {
#line 12751
        .trainerName = _("TABITHA"),
#line 12752
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 12753
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 12755
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12756
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12758
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12760
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12759
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12762
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12764
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12763
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12766
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12768
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12767
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12770
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12772
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12771
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12774
    [TRAINER_DARCY] =
    {
#line 12775
        .trainerName = _("DARCY"),
#line 12776
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 12777
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 12778
F_TRAINER_FEMALE | 
#line 12779
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12780
        .items = { ITEM_HYPER_POTION },
#line 12781
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12783
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12785
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12784
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12787
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12789
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12788
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12791
    [TRAINER_MAXIE_MOSSDEEP] =
    {
#line 12792
        .trainerName = _("MAXIE"),
#line 12793
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 12794
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 12796
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12797
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12799
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12801
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12800
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12803
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12805
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12804
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12807
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12809
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12808
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12811
    [TRAINER_PETE] =
    {
#line 12812
        .trainerName = _("PETE"),
#line 12813
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12814
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 12816
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12817
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12819
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12821
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12820
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12823
    [TRAINER_ISABELLE] =
    {
#line 12824
        .trainerName = _("ISABELLE"),
#line 12825
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 12826
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 12827
F_TRAINER_FEMALE | 
#line 12828
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12829
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12831
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12833
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12832
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12835
    [TRAINER_ANDRES_1] =
    {
#line 12836
        .trainerName = _("ANDRES"),
#line 12837
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 12838
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 12840
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12841
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12843
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12845
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12844
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12847
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12849
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12848
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12851
    [TRAINER_JOSUE] =
    {
#line 12852
        .trainerName = _("JOSUE"),
#line 12853
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12854
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12856
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12857
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12859
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12861
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12860
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12863
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12865
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12864
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12867
    [TRAINER_CAMRON] =
    {
#line 12868
        .trainerName = _("CAMRON"),
#line 12869
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 12870
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 12872
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12873
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12875
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12877
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12876
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12879
    [TRAINER_CORY_1] =
    {
#line 12880
        .trainerName = _("CORY"),
#line 12881
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 12882
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 12884
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12885
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12887
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12889
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12888
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12891
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12893
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12892
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12895
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12897
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12896
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12899
    [TRAINER_CAROLINA] =
    {
#line 12900
        .trainerName = _("CAROLINA"),
#line 12901
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 12902
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 12903
F_TRAINER_FEMALE | 
#line 12904
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12905
        .items = { ITEM_HYPER_POTION },
#line 12906
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12908
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12910
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12909
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12912
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12914
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12913
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12916
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12918
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12917
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12920
    [TRAINER_ELIJAH] =
    {
#line 12921
        .trainerName = _("ELIJAH"),
#line 12922
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12923
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12925
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12926
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12928
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12930
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12929
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12932
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12934
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12933
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12936
    [TRAINER_CELIA] =
    {
#line 12937
        .trainerName = _("CELIA"),
#line 12938
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12939
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12940
F_TRAINER_FEMALE | 
#line 12941
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12942
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12944
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12946
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12945
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12948
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12950
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12949
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12952
    [TRAINER_BRYAN] =
    {
#line 12953
        .trainerName = _("BRYAN"),
#line 12954
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 12955
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 12957
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12958
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12960
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12962
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12961
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12964
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12966
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12965
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12968
    [TRAINER_BRANDEN] =
    {
#line 12969
        .trainerName = _("BRANDEN"),
#line 12970
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12971
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12973
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12974
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12976
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12978
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12977
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12980
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12982
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12981
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12984
    [TRAINER_BRYANT] =
    {
#line 12985
        .trainerName = _("BRYANT"),
#line 12986
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 12987
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 12989
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12990
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12992
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12994
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12993
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12996
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12998
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12997
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13000
    [TRAINER_SHAYLA] =
    {
#line 13001
        .trainerName = _("SHAYLA"),
#line 13002
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 13003
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 13004
F_TRAINER_FEMALE | 
#line 13005
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13006
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13008
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13010
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13009
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13012
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13014
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13013
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13016
    [TRAINER_KYRA] =
    {
#line 13017
        .trainerName = _("KYRA"),
#line 13018
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 13019
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 13020
F_TRAINER_FEMALE | 
#line 13021
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13022
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13024
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13026
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13025
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13028
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13030
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13029
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13032
    [TRAINER_JAIDEN] =
    {
#line 13033
        .trainerName = _("JAIDEN"),
#line 13034
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 13035
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 13037
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 13038
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13040
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13042
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13041
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13044
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13046
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13045
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13048
    [TRAINER_ALIX] =
    {
#line 13049
        .trainerName = _("ALIX"),
#line 13050
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13051
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 13052
F_TRAINER_FEMALE | 
#line 13053
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13054
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13056
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13058
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13057
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13060
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13062
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13061
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13064
    [TRAINER_HELENE] =
    {
#line 13065
        .trainerName = _("HELENE"),
#line 13066
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 13067
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 13068
F_TRAINER_FEMALE | 
#line 13069
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13070
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13072
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13074
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13073
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13076
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13078
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13077
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13080
    [TRAINER_MARLENE] =
    {
#line 13081
        .trainerName = _("MARLENE"),
#line 13082
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13083
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 13084
F_TRAINER_FEMALE | 
#line 13085
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13086
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13088
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13090
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13089
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13092
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13094
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13093
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13096
    [TRAINER_DEVAN] =
    {
#line 13097
        .trainerName = _("DEVAN"),
#line 13098
        .trainerClass = TRAINER_CLASS_HIKER,
#line 13099
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 13101
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13102
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13104
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13106
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13105
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13108
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13110
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13109
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13112
    [TRAINER_JOHNSON] =
    {
#line 13113
        .trainerName = _("JOHNSON"),
#line 13114
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 13115
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 13117
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13118
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13120
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13121
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13124
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13126
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13125
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13128
    [TRAINER_MELINA] =
    {
#line 13129
        .trainerName = _("MELINA"),
#line 13130
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 13131
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 13132
F_TRAINER_FEMALE | 
#line 13133
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13134
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13136
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13138
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13137
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13140
    [TRAINER_BRANDI] =
    {
#line 13141
        .trainerName = _("BRANDI"),
#line 13142
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13143
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 13144
F_TRAINER_FEMALE | 
#line 13145
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13146
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13148
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13150
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13149
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13152
    [TRAINER_AISHA] =
    {
#line 13153
        .trainerName = _("AISHA"),
#line 13154
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 13155
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 13156
F_TRAINER_FEMALE | 
#line 13157
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13158
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13160
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13162
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13161
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13164
    [TRAINER_MAKAYLA] =
    {
#line 13165
        .trainerName = _("MAKAYLA"),
#line 13166
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 13167
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 13168
F_TRAINER_FEMALE | 
#line 13169
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13170
        .items = { ITEM_HYPER_POTION },
#line 13171
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13173
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13174
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13177
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13179
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13178
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13181
    [TRAINER_FABIAN] =
    {
#line 13182
        .trainerName = _("FABIAN"),
#line 13183
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 13184
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 13186
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13187
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13189
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13190
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13193
    [TRAINER_DAYTON] =
    {
#line 13194
        .trainerName = _("DAYTON"),
#line 13195
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 13196
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 13198
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13201
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13203
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13202
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13205
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13207
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13206
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13209
    [TRAINER_RACHEL] =
    {
#line 13210
        .trainerName = _("RACHEL"),
#line 13211
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 13212
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 13213
F_TRAINER_FEMALE | 
#line 13214
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13215
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13217
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13218
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13221
    [TRAINER_LEONEL] =
    {
#line 13222
        .trainerName = _("LEONEL"),
#line 13223
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13224
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 13226
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13227
        .items = { ITEM_HYPER_POTION },
#line 13228
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13230
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13232
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13231
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13233
                MOVE_THUNDER,
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
            },
            },
        },
    },
#line 13237
    [TRAINER_CALLIE] =
    {
#line 13238
        .trainerName = _("CALLIE"),
#line 13239
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 13240
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 13241
F_TRAINER_FEMALE | 
#line 13242
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13243
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13245
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13247
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13246
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13249
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13250
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13253
    [TRAINER_CALE] =
    {
#line 13254
        .trainerName = _("CALE"),
#line 13255
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 13256
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 13258
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 13259
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13261
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13263
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13262
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13265
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13266
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13269
    [TRAINER_MYLES] =
    {
#line 13270
        .trainerName = _("MYLES"),
#line 13271
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 13272
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 13274
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13275
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13277
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13279
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13278
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13281
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13283
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13282
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13285
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13287
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13286
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13289
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13291
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13290
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13293
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13295
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13294
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13297
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13299
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13298
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13301
    [TRAINER_PAT] =
    {
#line 13302
        .trainerName = _("PAT"),
#line 13303
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 13304
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 13305
F_TRAINER_FEMALE | 
#line 13306
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13309
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13311
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13310
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13313
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13315
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13314
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13317
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13319
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13318
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13321
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13323
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13322
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13325
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13327
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13326
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13329
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13331
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13330
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13333
    [TRAINER_CRISTIN_1] =
    {
#line 13334
        .trainerName = _("CRISTIN"),
#line 13335
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13336
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 13337
F_TRAINER_FEMALE | 
#line 13338
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13339
        .items = { ITEM_HYPER_POTION },
#line 13340
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13342
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13344
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13343
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13346
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13348
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13347
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13350
    [TRAINER_MAY_RUSTBORO_TREECKO] =
    {
#line 13351
        .trainerName = _("MAY"),
#line 13352
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 13353
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 13354
F_TRAINER_FEMALE | 
#line 13355
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13356
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13358
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13360
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 13359
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13362
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13364
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13363
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13366
    [TRAINER_MAY_RUSTBORO_TORCHIC] =
    {
#line 13367
        .trainerName = _("MAY"),
#line 13368
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 13369
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 13370
F_TRAINER_FEMALE | 
#line 13371
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13372
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13374
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13376
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 13375
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13378
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13380
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13379
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13382
    [TRAINER_ROXANNE_2] =
    {
#line 13383
        .trainerName = _("ROXANNE"),
#line 13384
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13385
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13386
F_TRAINER_FEMALE | 
#line 13387
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13388
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13389
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13391
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13393
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13392
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13394
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13399
            .species = SPECIES_KABUTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13399
            .heldItem = ITEM_SITRUS_BERRY,
#line 13401
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13400
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13402
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13407
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13409
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13408
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13410
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13415
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13415
            .heldItem = ITEM_SITRUS_BERRY,
#line 13417
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13416
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13418
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13423
    [TRAINER_ROXANNE_3] =
    {
#line 13424
        .trainerName = _("ROXANNE"),
#line 13425
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13426
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13427
F_TRAINER_FEMALE | 
#line 13428
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13429
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13430
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13432
            .species = SPECIES_OMANYTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13434
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13433
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13435
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13440
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13442
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13441
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13443
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13448
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13448
            .heldItem = ITEM_SITRUS_BERRY,
#line 13450
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13449
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13451
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13456
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13458
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13457
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13459
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13464
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13464
            .heldItem = ITEM_SITRUS_BERRY,
#line 13466
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13465
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13467
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13472
    [TRAINER_ROXANNE_4] =
    {
#line 13473
        .trainerName = _("ROXANNE"),
#line 13474
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13475
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13476
F_TRAINER_FEMALE | 
#line 13477
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13478
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13479
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13481
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13483
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13482
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13484
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13489
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13491
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13490
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13492
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13497
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13497
            .heldItem = ITEM_SITRUS_BERRY,
#line 13499
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13498
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13500
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13505
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13507
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13506
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13508
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13513
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13513
            .heldItem = ITEM_SITRUS_BERRY,
#line 13515
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13514
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13516
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13521
    [TRAINER_ROXANNE_5] =
    {
#line 13522
        .trainerName = _("ROXANNE"),
#line 13523
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13524
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13525
F_TRAINER_FEMALE | 
#line 13526
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13527
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13528
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13530
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13532
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13531
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13533
                MOVE_ROCK_SLIDE,
                MOVE_HYPER_BEAM,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
            },
            },
            {
#line 13538
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13540
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13539
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13541
                MOVE_FOCUS_PUNCH,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13546
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13548
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13547
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13549
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13554
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13554
            .heldItem = ITEM_SITRUS_BERRY,
#line 13556
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13555
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13557
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13562
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13564
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13563
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13565
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13570
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13570
            .heldItem = ITEM_SITRUS_BERRY,
#line 13572
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13571
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13573
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13578
    [TRAINER_BRAWLY_2] =
    {
#line 13579
        .trainerName = _("BRAWLY"),
#line 13580
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13581
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13583
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13584
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13585
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13587
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13587
            .heldItem = ITEM_SITRUS_BERRY,
#line 13589
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13588
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13590
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13595
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13597
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13596
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13598
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 13603
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13605
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13604
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13606
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
#line 13611
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13611
            .heldItem = ITEM_SITRUS_BERRY,
#line 13613
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13612
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13614
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13619
    [TRAINER_BRAWLY_3] =
    {
#line 13620
        .trainerName = _("BRAWLY"),
#line 13621
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13622
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13624
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13625
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13626
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13628
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13628
            .heldItem = ITEM_SITRUS_BERRY,
#line 13630
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13629
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13631
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13636
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13638
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13637
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13639
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 13644
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13646
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13645
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13647
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
#line 13652
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13652
            .heldItem = ITEM_SITRUS_BERRY,
#line 13654
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13653
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13655
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13660
    [TRAINER_BRAWLY_4] =
    {
#line 13661
        .trainerName = _("BRAWLY"),
#line 13662
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13663
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13665
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13666
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13667
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13669
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13671
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13670
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13672
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_ICE_PUNCH,
            },
            },
            {
#line 13677
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13677
            .heldItem = ITEM_SITRUS_BERRY,
#line 13679
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13678
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13680
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13685
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13687
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13686
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13688
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
#line 13693
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13695
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13694
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13696
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
#line 13701
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13701
            .heldItem = ITEM_SITRUS_BERRY,
#line 13703
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13702
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13704
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13709
    [TRAINER_BRAWLY_5] =
    {
#line 13710
        .trainerName = _("BRAWLY"),
#line 13711
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13712
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13714
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13715
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13716
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13718
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13720
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13719
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13721
                MOVE_MEGA_KICK,
                MOVE_FOCUS_PUNCH,
                MOVE_EARTHQUAKE,
                MOVE_BULK_UP,
            },
            },
            {
#line 13726
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13728
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13727
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13729
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_ICE_PUNCH,
            },
            },
            {
#line 13734
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13734
            .heldItem = ITEM_SITRUS_BERRY,
#line 13736
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13735
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13737
                MOVE_CROSS_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13742
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13744
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13743
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13745
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
#line 13750
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13752
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13751
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13753
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
#line 13758
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13758
            .heldItem = ITEM_SITRUS_BERRY,
#line 13760
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13759
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13761
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13766
    [TRAINER_WATTSON_2] =
    {
#line 13767
        .trainerName = _("WATTSON"),
#line 13768
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13769
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13771
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13772
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13773
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13775
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13777
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13776
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13778
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13783
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13785
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13784
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13786
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13791
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13791
            .heldItem = ITEM_SITRUS_BERRY,
#line 13793
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13792
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13794
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13799
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13799
            .heldItem = ITEM_SITRUS_BERRY,
#line 13801
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13800
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13802
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13807
    [TRAINER_WATTSON_3] =
    {
#line 13808
        .trainerName = _("WATTSON"),
#line 13809
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13810
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13812
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13813
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13814
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13816
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13818
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13817
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13819
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 13824
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13826
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13825
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13827
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13832
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13834
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13833
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13835
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13840
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13840
            .heldItem = ITEM_SITRUS_BERRY,
#line 13842
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13841
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13843
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13848
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13848
            .heldItem = ITEM_SITRUS_BERRY,
#line 13850
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13849
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13851
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13856
    [TRAINER_WATTSON_4] =
    {
#line 13857
        .trainerName = _("WATTSON"),
#line 13858
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13859
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13861
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13862
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13863
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13865
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13867
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13866
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13868
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
            },
            },
            {
#line 13873
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13875
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13874
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13876
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13881
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13883
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13882
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13884
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13889
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13889
            .heldItem = ITEM_SITRUS_BERRY,
#line 13891
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13890
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13892
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13897
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13897
            .heldItem = ITEM_SITRUS_BERRY,
#line 13899
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13898
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13900
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13905
    [TRAINER_WATTSON_5] =
    {
#line 13906
        .trainerName = _("WATTSON"),
#line 13907
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13908
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13910
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13911
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13912
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13914
            .species = SPECIES_ELECTABUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13916
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13915
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13917
                MOVE_SWIFT,
                MOVE_FOCUS_PUNCH,
                MOVE_THUNDER_PUNCH,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13922
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13924
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13923
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13925
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
            },
            },
            {
#line 13930
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13932
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13931
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13933
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13938
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13940
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13939
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13941
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13946
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13946
            .heldItem = ITEM_SITRUS_BERRY,
#line 13948
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13947
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13949
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
#line 13954
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13954
            .heldItem = ITEM_SITRUS_BERRY,
#line 13956
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13955
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13957
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13962
    [TRAINER_FLANNERY_2] =
    {
#line 13963
        .trainerName = _("FLANNERY"),
#line 13964
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13965
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 13966
F_TRAINER_FEMALE | 
#line 13967
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13968
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13969
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13971
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13971
            .heldItem = ITEM_WHITE_HERB,
#line 13973
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13972
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13974
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13979
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13981
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13980
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13982
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 13987
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13987
            .heldItem = ITEM_WHITE_HERB,
#line 13989
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13988
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13990
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 13995
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13995
            .heldItem = ITEM_WHITE_HERB,
#line 13997
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13996
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13998
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14003
    [TRAINER_FLANNERY_3] =
    {
#line 14004
        .trainerName = _("FLANNERY"),
#line 14005
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14006
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 14007
F_TRAINER_FEMALE | 
#line 14008
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14009
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14010
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14012
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14014
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14013
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14015
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 14020
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14020
            .heldItem = ITEM_WHITE_HERB,
#line 14022
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14021
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14023
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 14028
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14030
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14029
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14031
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 14036
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14036
            .heldItem = ITEM_WHITE_HERB,
#line 14038
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14037
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14039
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 14044
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14044
            .heldItem = ITEM_WHITE_HERB,
#line 14046
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14045
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14047
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14052
    [TRAINER_FLANNERY_4] =
    {
#line 14053
        .trainerName = _("FLANNERY"),
#line 14054
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14055
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 14056
F_TRAINER_FEMALE | 
#line 14057
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14058
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14059
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14061
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14063
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14062
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14064
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 14069
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14071
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14070
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14072
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_SUNNY_DAY,
                MOVE_ROAR,
            },
            },
            {
#line 14077
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14077
            .heldItem = ITEM_WHITE_HERB,
#line 14079
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14078
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14080
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 14085
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14087
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14086
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14088
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 14093
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14093
            .heldItem = ITEM_WHITE_HERB,
#line 14095
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14094
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14096
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 14101
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14101
            .heldItem = ITEM_WHITE_HERB,
#line 14103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14102
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14104
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14109
    [TRAINER_FLANNERY_5] =
    {
#line 14110
        .trainerName = _("FLANNERY"),
#line 14111
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14112
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 14113
F_TRAINER_FEMALE | 
#line 14114
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14115
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14116
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14118
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14120
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14119
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14121
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_SUNNY_DAY,
                MOVE_ROAR,
            },
            },
            {
#line 14126
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14126
            .heldItem = ITEM_WHITE_HERB,
#line 14128
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14127
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14129
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 14134
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14136
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14135
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14137
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_SUNNY_DAY,
            },
            },
            {
#line 14142
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14144
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14143
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14145
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 14150
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14150
            .heldItem = ITEM_WHITE_HERB,
#line 14152
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14151
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14153
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 14158
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14158
            .heldItem = ITEM_WHITE_HERB,
#line 14160
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14159
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14161
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14166
    [TRAINER_NORMAN_2] =
    {
#line 14167
        .trainerName = _("NORMAN"),
#line 14168
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14169
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14171
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14172
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14173
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 14175
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14177
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14176
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14178
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14183
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14183
            .heldItem = ITEM_SITRUS_BERRY,
#line 14185
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14184
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14186
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14191
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14193
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14192
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14194
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14199
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14199
            .heldItem = ITEM_SITRUS_BERRY,
#line 14201
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14200
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14202
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14207
    [TRAINER_NORMAN_3] =
    {
#line 14208
        .trainerName = _("NORMAN"),
#line 14209
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14210
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14212
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14213
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14214
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14216
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14216
            .heldItem = ITEM_SITRUS_BERRY,
#line 14218
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14217
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14219
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14224
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14226
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14225
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14227
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14232
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14234
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14233
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14235
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14240
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14242
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14241
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14243
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14248
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14248
            .heldItem = ITEM_SITRUS_BERRY,
#line 14250
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14249
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14251
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14256
    [TRAINER_NORMAN_4] =
    {
#line 14257
        .trainerName = _("NORMAN"),
#line 14258
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14259
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14261
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14262
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14263
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14265
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14265
            .heldItem = ITEM_SITRUS_BERRY,
#line 14267
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14266
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14268
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14273
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14274
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14276
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14281
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14283
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14282
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14284
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14289
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14291
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14290
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14292
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14297
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14297
            .heldItem = ITEM_SITRUS_BERRY,
#line 14299
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14298
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14300
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14305
    [TRAINER_NORMAN_5] =
    {
#line 14306
        .trainerName = _("NORMAN"),
#line 14307
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14308
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14310
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14311
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14312
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14314
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14314
            .heldItem = ITEM_SITRUS_BERRY,
#line 14316
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14315
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14317
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14322
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14324
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14323
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14325
                MOVE_PROTECT,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14330
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14332
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14331
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14333
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14338
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14340
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14339
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14341
                MOVE_TAKE_DOWN,
                MOVE_PROTECT,
                MOVE_FIRE_BLAST,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14346
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14348
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14347
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14349
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14354
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14354
            .heldItem = ITEM_SITRUS_BERRY,
#line 14356
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14355
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14357
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14362
    [TRAINER_WINONA_2] =
    {
#line 14363
        .trainerName = _("WINONA"),
#line 14364
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14365
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14366
F_TRAINER_FEMALE | 
#line 14367
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14368
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14369
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14371
            .species = SPECIES_DRATINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14371
            .heldItem = ITEM_SITRUS_BERRY,
#line 14373
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14372
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14374
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14379
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14381
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14380
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14382
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14387
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14389
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14388
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14390
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14395
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14397
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14396
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14398
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14403
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14403
            .heldItem = ITEM_CHESTO_BERRY,
#line 14405
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14404
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14406
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14411
    [TRAINER_WINONA_3] =
    {
#line 14412
        .trainerName = _("WINONA"),
#line 14413
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14414
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14415
F_TRAINER_FEMALE | 
#line 14416
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14417
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14418
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14420
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14422
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14421
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14423
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14428
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14430
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14429
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14431
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14436
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14436
            .heldItem = ITEM_SITRUS_BERRY,
#line 14438
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14437
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14439
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14444
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14446
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14445
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14447
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14452
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14454
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14453
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14455
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14460
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14460
            .heldItem = ITEM_CHESTO_BERRY,
#line 14462
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14461
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14463
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14468
    [TRAINER_WINONA_4] =
    {
#line 14469
        .trainerName = _("WINONA"),
#line 14470
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14471
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14472
F_TRAINER_FEMALE | 
#line 14473
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14474
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14475
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14477
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14479
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14478
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14480
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14485
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14487
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14486
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14488
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14493
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14493
            .heldItem = ITEM_SITRUS_BERRY,
#line 14495
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14494
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14496
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14501
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14503
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14502
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14504
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14509
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14511
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14510
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14512
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14517
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14517
            .heldItem = ITEM_CHESTO_BERRY,
#line 14519
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14518
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14520
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14525
    [TRAINER_WINONA_5] =
    {
#line 14526
        .trainerName = _("WINONA"),
#line 14527
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14528
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14529
F_TRAINER_FEMALE | 
#line 14530
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14531
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14532
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14534
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14536
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14535
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14537
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14542
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14544
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14543
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14545
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14550
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14552
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14551
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14553
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14558
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14558
            .heldItem = ITEM_SITRUS_BERRY,
#line 14560
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14559
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14561
                MOVE_HYPER_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14566
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14568
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14567
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14569
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14574
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14574
            .heldItem = ITEM_CHESTO_BERRY,
#line 14576
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14575
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14577
                MOVE_SKY_ATTACK,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14582
    [TRAINER_TATE_AND_LIZA_2] =
    {
#line 14583
        .trainerName = _("TATE&LIZA"),
#line 14584
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14585
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14587
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14588
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14589
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14591
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14593
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14592
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14594
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14599
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14601
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14600
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14602
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14607
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14607
            .heldItem = ITEM_CHESTO_BERRY,
#line 14609
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14608
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14610
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14615
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14615
            .heldItem = ITEM_CHESTO_BERRY,
#line 14617
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14616
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14618
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14623
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14623
            .heldItem = ITEM_SITRUS_BERRY,
#line 14625
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14624
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14626
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
#line 14631
    [TRAINER_TATE_AND_LIZA_3] =
    {
#line 14632
        .trainerName = _("TATE&LIZA"),
#line 14633
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14634
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14636
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14637
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14638
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14640
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14642
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14641
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14643
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14648
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14650
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14649
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14651
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14656
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14658
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14657
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14659
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14664
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14664
            .heldItem = ITEM_CHESTO_BERRY,
#line 14666
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14665
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14667
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14672
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14672
            .heldItem = ITEM_CHESTO_BERRY,
#line 14674
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14673
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14675
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14680
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14680
            .heldItem = ITEM_SITRUS_BERRY,
#line 14682
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14681
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14683
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
#line 14688
    [TRAINER_TATE_AND_LIZA_4] =
    {
#line 14689
        .trainerName = _("TATE&LIZA"),
#line 14690
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14691
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14693
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14694
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14695
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14697
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14699
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14698
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14700
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14705
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14707
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14706
            .lvl = 59,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14708
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14713
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14715
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14714
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14716
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14721
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14721
            .heldItem = ITEM_CHESTO_BERRY,
#line 14723
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14722
            .lvl = 59,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14724
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14729
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14729
            .heldItem = ITEM_CHESTO_BERRY,
#line 14731
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14730
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14732
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14737
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14737
            .heldItem = ITEM_SITRUS_BERRY,
#line 14739
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14738
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14740
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
#line 14745
    [TRAINER_TATE_AND_LIZA_5] =
    {
#line 14746
        .trainerName = _("TATE&LIZA"),
#line 14747
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14748
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14750
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14751
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14752
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14754
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14756
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14755
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14757
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14762
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14764
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14763
            .lvl = 64,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14765
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14770
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14772
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14771
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14773
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14778
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14778
            .heldItem = ITEM_CHESTO_BERRY,
#line 14780
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14779
            .lvl = 64,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14781
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14786
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14786
            .heldItem = ITEM_CHESTO_BERRY,
#line 14788
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14787
            .lvl = 65,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14789
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14794
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14794
            .heldItem = ITEM_SITRUS_BERRY,
#line 14796
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14795
            .lvl = 65,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14797
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
#line 14802
    [TRAINER_JUAN_2] =
    {
#line 14803
        .trainerName = _("JUAN"),
#line 14804
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14805
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14807
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14808
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14809
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14811
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14813
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14812
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14814
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14819
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14821
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14820
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14822
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14827
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14829
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14828
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14830
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14835
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14835
            .heldItem = ITEM_CHESTO_BERRY,
#line 14837
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14836
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14838
                MOVE_REST,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14843
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14843
            .heldItem = ITEM_CHESTO_BERRY,
#line 14845
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14844
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14846
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14851
    [TRAINER_JUAN_3] =
    {
#line 14852
        .trainerName = _("JUAN"),
#line 14853
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14854
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14856
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14857
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14858
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14860
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14862
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14861
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14863
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14868
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14870
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14869
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14871
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14876
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14878
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14877
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14879
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14884
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14884
            .heldItem = ITEM_CHESTO_BERRY,
#line 14886
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14885
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14887
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14892
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14892
            .heldItem = ITEM_CHESTO_BERRY,
#line 14894
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14893
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14895
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14900
    [TRAINER_JUAN_4] =
    {
#line 14901
        .trainerName = _("JUAN"),
#line 14902
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14903
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14905
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14906
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14907
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14909
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14911
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14910
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14912
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 14917
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14919
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14918
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14920
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14925
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14927
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14926
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14928
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14933
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14935
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14934
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14936
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14941
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14941
            .heldItem = ITEM_CHESTO_BERRY,
#line 14943
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14942
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14944
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14949
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14949
            .heldItem = ITEM_CHESTO_BERRY,
#line 14951
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14950
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14952
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14957
    [TRAINER_JUAN_5] =
    {
#line 14958
        .trainerName = _("JUAN"),
#line 14959
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14960
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14962
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14963
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14964
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14966
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14968
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14967
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14969
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 14974
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14976
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14975
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14977
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14982
            .species = SPECIES_POLITOED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14984
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14983
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14985
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
            },
            },
            {
#line 14990
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14992
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14991
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14993
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_SHEER_COLD,
            },
            },
            {
#line 14998
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14998
            .heldItem = ITEM_CHESTO_BERRY,
#line 15000
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14999
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15001
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 15006
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15006
            .heldItem = ITEM_CHESTO_BERRY,
#line 15008
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15007
            .lvl = 66,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15009
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 15014
    [TRAINER_ANGELO] =
    {
#line 15015
        .trainerName = _("ANGELO"),
#line 15016
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 15017
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 15019
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 15020
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15022
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15024
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 15023
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15025
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CHARM,
            },
            },
            {
#line 15029
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15031
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 15030
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15032
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CONFUSE_RAY,
            },
            },
        },
    },
#line 15036
    [TRAINER_DARIUS] =
    {
#line 15037
        .trainerName = _("DARIUS"),
#line 15038
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 15039
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 15041
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15042
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15044
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15046
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 15045
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15048
    [TRAINER_STEVEN] =
    {
#line 15049
        .trainerName = _("STEVEN"),
#line 15050
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 15051
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender = 
#line 15053
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15054
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 15055
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15057
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15059
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15058
            .lvl = 77,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15060
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
            },
            },
            {
#line 15065
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15067
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15066
            .lvl = 75,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15068
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_ANCIENT_POWER,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 15073
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15075
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15074
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15076
                MOVE_THUNDER,
                MOVE_EARTHQUAKE,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
            {
#line 15081
            .species = SPECIES_CRADILY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15083
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15082
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15084
                MOVE_GIGA_DRAIN,
                MOVE_ANCIENT_POWER,
                MOVE_INGRAIN,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 15089
            .species = SPECIES_ARMALDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15091
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15090
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15092
                MOVE_WATER_PULSE,
                MOVE_ANCIENT_POWER,
                MOVE_AERIAL_ACE,
                MOVE_SLASH,
            },
            },
            {
#line 15097
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15097
            .heldItem = ITEM_SITRUS_BERRY,
#line 15099
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 15098
            .lvl = 78,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 15100
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_METEOR_MASH,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 15105
    [TRAINER_ANABEL] =
    {
#line 15106
        .trainerName = _("ANABEL"),
#line 15107
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
#line 15108
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .encounterMusic_gender = 
#line 15109
F_TRAINER_FEMALE | 
#line 15110
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15111
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15113
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15114
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15117
    [TRAINER_TUCKER] =
    {
#line 15118
        .trainerName = _("TUCKER"),
#line 15119
        .trainerClass = TRAINER_CLASS_DOME_ACE,
#line 15120
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .encounterMusic_gender = 
#line 15122
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15123
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15125
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15126
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15129
    [TRAINER_SPENSER] =
    {
#line 15130
        .trainerName = _("SPENSER"),
#line 15131
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
#line 15132
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .encounterMusic_gender = 
#line 15134
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15135
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15137
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15139
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15138
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15141
    [TRAINER_GRETA] =
    {
#line 15142
        .trainerName = _("GRETA"),
#line 15143
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
#line 15144
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .encounterMusic_gender = 
#line 15145
F_TRAINER_FEMALE | 
#line 15146
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15147
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15149
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15151
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15150
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15153
    [TRAINER_NOLAND] =
    {
#line 15154
        .trainerName = _("NOLAND"),
#line 15155
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
#line 15156
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .encounterMusic_gender = 
#line 15158
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15159
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15161
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15162
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15165
    [TRAINER_LUCY] =
    {
#line 15166
        .trainerName = _("LUCY"),
#line 15167
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
#line 15168
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .encounterMusic_gender = 
#line 15169
F_TRAINER_FEMALE | 
#line 15170
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15171
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15173
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15175
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15174
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15177
    [TRAINER_BRANDON] =
    {
#line 15178
        .trainerName = _("BRANDON"),
#line 15179
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
#line 15180
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .encounterMusic_gender = 
#line 15182
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15183
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15185
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15186
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15189
    [TRAINER_ANDRES_2] =
    {
#line 15190
        .trainerName = _("ANDRES"),
#line 15191
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15192
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15194
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15195
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15197
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15199
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15198
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15201
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15203
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15202
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15205
    [TRAINER_ANDRES_3] =
    {
#line 15206
        .trainerName = _("ANDRES"),
#line 15207
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15208
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15210
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15211
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15213
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15215
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15214
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15217
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15219
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15218
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15221
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15223
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15222
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15225
    [TRAINER_ANDRES_4] =
    {
#line 15226
        .trainerName = _("ANDRES"),
#line 15227
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15228
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15230
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15231
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15233
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15235
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15234
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15237
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15239
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15238
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15241
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15243
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15242
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15245
    [TRAINER_ANDRES_5] =
    {
#line 15246
        .trainerName = _("ANDRES"),
#line 15247
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15248
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15250
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15251
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15253
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15255
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15254
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15257
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15259
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15258
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15261
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15263
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15262
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15265
    [TRAINER_CORY_2] =
    {
#line 15266
        .trainerName = _("CORY"),
#line 15267
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15268
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15270
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15273
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15275
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15274
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15277
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15279
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15278
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15281
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15283
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15282
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15285
    [TRAINER_CORY_3] =
    {
#line 15286
        .trainerName = _("CORY"),
#line 15287
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15288
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15290
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15291
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15293
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15295
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15294
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15297
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15299
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15298
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15301
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15303
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15302
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15305
    [TRAINER_CORY_4] =
    {
#line 15306
        .trainerName = _("CORY"),
#line 15307
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15308
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15310
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15311
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15313
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15315
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15314
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15317
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15319
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15318
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15321
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15323
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15322
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15325
    [TRAINER_CORY_5] =
    {
#line 15326
        .trainerName = _("CORY"),
#line 15327
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15328
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15330
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15331
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15333
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15335
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15334
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15337
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15339
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15338
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15341
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15343
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15342
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15345
    [TRAINER_PABLO_2] =
    {
#line 15346
        .trainerName = _("PABLO"),
#line 15347
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15348
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15350
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15351
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15353
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15355
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15354
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15357
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15359
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15358
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15361
    [TRAINER_PABLO_3] =
    {
#line 15362
        .trainerName = _("PABLO"),
#line 15363
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15364
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15366
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15367
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15369
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15371
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15370
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15373
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15375
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15374
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15377
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15379
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15378
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15381
    [TRAINER_PABLO_4] =
    {
#line 15382
        .trainerName = _("PABLO"),
#line 15383
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15384
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15386
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15389
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15391
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15390
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15393
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15395
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15394
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15397
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15399
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15398
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15401
    [TRAINER_PABLO_5] =
    {
#line 15402
        .trainerName = _("PABLO"),
#line 15403
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15404
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15406
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15407
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15409
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15411
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15410
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15413
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15415
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15414
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15417
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15419
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15418
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15421
    [TRAINER_KOJI_2] =
    {
#line 15422
        .trainerName = _("KOJI"),
#line 15423
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15424
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15426
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15429
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15431
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15430
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15433
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15435
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15434
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15437
    [TRAINER_KOJI_3] =
    {
#line 15438
        .trainerName = _("KOJI"),
#line 15439
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15440
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15442
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15443
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15445
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15447
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15446
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15449
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15451
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15450
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15453
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15455
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15454
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15457
    [TRAINER_KOJI_4] =
    {
#line 15458
        .trainerName = _("KOJI"),
#line 15459
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15460
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15462
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15465
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15467
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15466
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15469
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15471
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15470
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15473
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15475
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15474
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15477
    [TRAINER_KOJI_5] =
    {
#line 15478
        .trainerName = _("KOJI"),
#line 15479
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15480
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15482
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15485
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15487
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15486
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15489
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15491
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15490
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15493
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15495
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15494
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15497
    [TRAINER_CRISTIN_2] =
    {
#line 15498
        .trainerName = _("CRISTIN"),
#line 15499
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15500
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15501
F_TRAINER_FEMALE | 
#line 15502
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15503
        .items = { ITEM_HYPER_POTION },
#line 15504
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15506
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15508
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 15507
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15510
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15512
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 15511
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15514
    [TRAINER_CRISTIN_3] =
    {
#line 15515
        .trainerName = _("CRISTIN"),
#line 15516
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15517
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15518
F_TRAINER_FEMALE | 
#line 15519
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15520
        .items = { ITEM_HYPER_POTION },
#line 15521
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15523
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15525
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15524
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15527
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15529
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15528
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15531
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15533
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15532
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15535
    [TRAINER_CRISTIN_4] =
    {
#line 15536
        .trainerName = _("CRISTIN"),
#line 15537
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15538
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15539
F_TRAINER_FEMALE | 
#line 15540
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15541
        .items = { ITEM_HYPER_POTION },
#line 15542
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15544
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15546
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 15545
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15548
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15550
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 15549
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15552
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15554
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 15553
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15556
    [TRAINER_CRISTIN_5] =
    {
#line 15557
        .trainerName = _("CRISTIN"),
#line 15558
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15559
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15560
F_TRAINER_FEMALE | 
#line 15561
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15562
        .items = { ITEM_HYPER_POTION },
#line 15563
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15565
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15567
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15566
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15569
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15571
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15570
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15573
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15575
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15574
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15577
    [TRAINER_FERNANDO_2] =
    {
#line 15578
        .trainerName = _("FERNANDO"),
#line 15579
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15580
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15582
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15583
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15585
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15587
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15586
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15589
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15591
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15590
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15593
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15595
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15594
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15597
    [TRAINER_FERNANDO_3] =
    {
#line 15598
        .trainerName = _("FERNANDO"),
#line 15599
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15600
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15602
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15603
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15605
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15607
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15606
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15609
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15611
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15610
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15613
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15615
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15614
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15617
    [TRAINER_FERNANDO_4] =
    {
#line 15618
        .trainerName = _("FERNANDO"),
#line 15619
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15620
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15622
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15623
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15625
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15627
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15626
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15629
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15631
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15630
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15633
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15635
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15634
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15637
    [TRAINER_FERNANDO_5] =
    {
#line 15638
        .trainerName = _("FERNANDO"),
#line 15639
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15640
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15642
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15643
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15645
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15647
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15646
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15649
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15651
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15650
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15653
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15655
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15654
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15657
    [TRAINER_SAWYER_2] =
    {
#line 15658
        .trainerName = _("SAWYER"),
#line 15659
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15660
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15662
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15663
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15665
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15667
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15666
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15669
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15671
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15670
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15673
    [TRAINER_SAWYER_3] =
    {
#line 15674
        .trainerName = _("SAWYER"),
#line 15675
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15676
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15678
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15679
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15681
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15683
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15682
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15685
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15687
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15686
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15689
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15691
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15690
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15693
    [TRAINER_SAWYER_4] =
    {
#line 15694
        .trainerName = _("SAWYER"),
#line 15695
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15696
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15698
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15699
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15701
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15703
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15702
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15705
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15707
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15706
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15709
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15711
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15710
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15713
    [TRAINER_SAWYER_5] =
    {
#line 15714
        .trainerName = _("SAWYER"),
#line 15715
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15716
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15718
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15719
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15721
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15723
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15722
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15725
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15727
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15726
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15729
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15731
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15730
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15733
    [TRAINER_GABRIELLE_2] =
    {
#line 15734
        .trainerName = _("GABRIELLE"),
#line 15735
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15736
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15737
F_TRAINER_FEMALE | 
#line 15738
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15739
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15741
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15743
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15742
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15745
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15747
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15746
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15749
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15751
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15750
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15753
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15755
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15754
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15757
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15759
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15758
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15761
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15763
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15762
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15765
    [TRAINER_GABRIELLE_3] =
    {
#line 15766
        .trainerName = _("GABRIELLE"),
#line 15767
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15768
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15769
F_TRAINER_FEMALE | 
#line 15770
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15771
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15773
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15775
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15774
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15777
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15779
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15778
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15781
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15783
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15782
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15785
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15787
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15786
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15789
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15791
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15790
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15793
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15795
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15794
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15797
    [TRAINER_GABRIELLE_4] =
    {
#line 15798
        .trainerName = _("GABRIELLE"),
#line 15799
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15800
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15801
F_TRAINER_FEMALE | 
#line 15802
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15803
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15805
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15807
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15806
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15809
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15811
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15810
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15813
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15815
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15814
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15817
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15819
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15818
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15821
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15823
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15822
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15825
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15827
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15826
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15829
    [TRAINER_GABRIELLE_5] =
    {
#line 15830
        .trainerName = _("GABRIELLE"),
#line 15831
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15832
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15833
F_TRAINER_FEMALE | 
#line 15834
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15837
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15839
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15838
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15841
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15843
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15842
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15845
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15847
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15846
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15849
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15851
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15850
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15853
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15855
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15854
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15857
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15859
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15858
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15861
    [TRAINER_THALIA_2] =
    {
#line 15862
        .trainerName = _("THALIA"),
#line 15863
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15864
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15865
F_TRAINER_FEMALE | 
#line 15866
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15867
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15869
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15871
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15870
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15873
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15875
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15874
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15877
    [TRAINER_THALIA_3] =
    {
#line 15878
        .trainerName = _("THALIA"),
#line 15879
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15880
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15881
F_TRAINER_FEMALE | 
#line 15882
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15883
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15885
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15887
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15886
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15889
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15891
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15890
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15893
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15895
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15894
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15897
    [TRAINER_THALIA_4] =
    {
#line 15898
        .trainerName = _("THALIA"),
#line 15899
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15900
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15901
F_TRAINER_FEMALE | 
#line 15902
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15903
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15905
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15907
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15906
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15909
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15911
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15910
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15913
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15915
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15914
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15917
    [TRAINER_THALIA_5] =
    {
#line 15918
        .trainerName = _("THALIA"),
#line 15919
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15920
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15921
F_TRAINER_FEMALE | 
#line 15922
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15923
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15925
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15927
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15926
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15929
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15931
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15930
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15933
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15935
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15934
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15937
    [TRAINER_MARIELA] =
    {
#line 15938
        .trainerName = _("MARIELA"),
#line 15939
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 15940
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 15941
F_TRAINER_FEMALE | 
#line 15942
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15944
            .species = SPECIES_CHIMECHO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15946
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15945
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15948
    [TRAINER_ALVARO] =
    {
#line 15949
        .trainerName = _("ALVARO"),
#line 15950
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 15951
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 15953
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15955
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15957
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15956
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15959
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15961
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15960
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15963
    [TRAINER_EVERETT] =
    {
#line 15964
        .trainerName = _("EVERETT"),
#line 15965
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 15966
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 15968
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15970
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15972
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15971
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15974
    [TRAINER_RED] =
    {
#line 15975
        .trainerName = _("RED"),
#line 15976
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 15977
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 15979
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15981
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15982
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15985
    [TRAINER_LEAF] =
    {
#line 15986
        .trainerName = _("LEAF"),
#line 15987
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 15988
        .trainerPic = TRAINER_PIC_LEAF,
        .encounterMusic_gender = 
#line 15989
F_TRAINER_FEMALE | 
#line 15990
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15992
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15994
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15993
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15996
    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
#line 15997
        .trainerName = _("BRENDAN"),
#line 15998
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
#line 15999
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .encounterMusic_gender = 
#line 16001
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 16003
            .species = SPECIES_GROUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 16005
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 16004
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 16007
    [TRAINER_LANCE] =
    {
#line 16008
        .trainerName = _("LANCE"),
#line 16009
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 16010
        .trainerPic = TRAINER_PIC_LANCE,
        .encounterMusic_gender = 
#line 16012
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 16013
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 16015
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 16017
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 16016
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 16019
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 16021
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 16020
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },

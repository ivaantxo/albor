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
        .trainerClass = TRAINER_CLASS_HIKER,
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
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_1] =
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
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 103
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_2] =
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
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 111
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 113
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 112
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 115
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_3] =
    {
#line 116
        .trainerName = _("GRUNT"),
#line 117
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 118
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 120
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 121
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 123
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 125
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 124
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 127
    [TRAINER_GABRIELLE_1] =
    {
#line 128
        .trainerName = _("GABRIELLE"),
#line 129
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 130
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 131
F_TRAINER_FEMALE | 
#line 132
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 133
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 135
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 137
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 136
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 139
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 140
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 143
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 145
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 144
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 147
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 149
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 148
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 151
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 153
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 152
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 155
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 156
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 159
    [TRAINER_GRUNT_PETALBURG_WOODS] =
    {
#line 160
        .trainerName = _("GRUNT"),
#line 161
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 162
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 164
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 165
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 167
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 169
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 168
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 171
    [TRAINER_MARCEL] =
    {
#line 172
        .trainerName = _("MARCEL"),
#line 173
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 174
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 176
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 177
        .items = { ITEM_HYPER_POTION },
#line 178
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 180
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 182
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 181
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 184
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 186
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 185
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 188
    [TRAINER_ALBERTO] =
    {
#line 189
        .trainerName = _("ALBERTO"),
#line 190
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 191
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 193
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 194
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 196
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 197
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 200
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 202
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 201
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 204
    [TRAINER_ED] =
    {
#line 205
        .trainerName = _("ED"),
#line 206
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 207
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 209
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 210
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 212
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 214
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 213
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 216
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 218
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 217
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 220
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_4] =
    {
#line 221
        .trainerName = _("GRUNT"),
#line 222
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 223
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 224
F_TRAINER_FEMALE | 
#line 225
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 226
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 228
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 230
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 229
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 232
    [TRAINER_DECLAN] =
    {
#line 233
        .trainerName = _("DECLAN"),
#line 234
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 235
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 237
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 238
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 240
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 241
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 244
    [TRAINER_GRUNT_RUSTURF_TUNNEL] =
    {
#line 245
        .trainerName = _("GRUNT"),
#line 246
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 247
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 249
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 250
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 252
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 254
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 253
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 256
    [TRAINER_GRUNT_WEATHER_INST_1] =
    {
#line 257
        .trainerName = _("GRUNT"),
#line 258
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 259
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 261
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 264
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 266
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 265
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 268
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 270
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 269
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 272
    [TRAINER_GRUNT_WEATHER_INST_2] =
    {
#line 273
        .trainerName = _("GRUNT"),
#line 274
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 275
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 277
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 278
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 280
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 282
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 281
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 284
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 286
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 285
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 288
    [TRAINER_GRUNT_WEATHER_INST_3] =
    {
#line 289
        .trainerName = _("GRUNT"),
#line 290
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 291
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 293
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 294
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 296
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 298
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 297
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 300
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 302
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 301
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 304
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 306
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 305
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 308
    [TRAINER_GRUNT_MUSEUM_1] =
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
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 316
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 318
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 317
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 320
    [TRAINER_GRUNT_MUSEUM_2] =
    {
#line 321
        .trainerName = _("GRUNT"),
#line 322
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 323
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 325
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 326
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 328
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 330
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 329
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 332
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 334
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 333
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 336
    [TRAINER_GRUNT_SPACE_CENTER_1] =
    {
#line 337
        .trainerName = _("GRUNT"),
#line 338
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 339
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 341
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 342
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 344
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 346
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 345
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 348
    [TRAINER_GRUNT_MT_PYRE_1] =
    {
#line 349
        .trainerName = _("GRUNT"),
#line 350
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 351
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 353
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 354
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 356
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 358
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 357
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 360
    [TRAINER_GRUNT_MT_PYRE_2] =
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
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 372
    [TRAINER_GRUNT_MT_PYRE_3] =
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
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 382
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 381
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 384
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 386
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 385
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 388
    [TRAINER_GRUNT_WEATHER_INST_4] =
    {
#line 389
        .trainerName = _("GRUNT"),
#line 390
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 391
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 392
F_TRAINER_FEMALE | 
#line 393
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 394
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 396
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 398
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 397
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 400
    [TRAINER_FREDRICK] =
    {
#line 401
        .trainerName = _("FREDRICK"),
#line 402
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 403
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 405
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 406
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 408
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 410
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 409
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 412
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 414
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 413
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 416
    [TRAINER_MATT] =
    {
#line 417
        .trainerName = _("MATT"),
#line 418
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 419
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_M,
        .encounterMusic_gender = 
#line 421
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 422
        .items = { ITEM_SUPER_POTION },
#line 423
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 425
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 427
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 426
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 429
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 431
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 430
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 433
    [TRAINER_ZANDER] =
    {
#line 434
        .trainerName = _("ZANDER"),
#line 435
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 436
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 438
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 439
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 441
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 443
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 442
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 445
    [TRAINER_SHELLY_WEATHER_INSTITUTE] =
    {
#line 446
        .trainerName = _("SHELLY"),
#line 447
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 448
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender = 
#line 449
F_TRAINER_FEMALE | 
#line 450
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 451
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 453
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 455
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 454
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 457
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 459
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 458
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 461
    [TRAINER_SHELLY_SEAFLOOR_CAVERN] =
    {
#line 462
        .trainerName = _("SHELLY"),
#line 463
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
#line 464
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender = 
#line 465
F_TRAINER_FEMALE | 
#line 466
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 467
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 469
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 471
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 470
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 473
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 475
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 474
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 477
    [TRAINER_ARCHIE] =
    {
#line 478
        .trainerName = _("ARCHIE"),
#line 479
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
#line 480
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .encounterMusic_gender = 
#line 482
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 483
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 484
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 486
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 488
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 487
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 490
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 492
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 491
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 494
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 496
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 495
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 498
    [TRAINER_LEAH] =
    {
#line 499
        .trainerName = _("LEAH"),
#line 500
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 501
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 502
F_TRAINER_FEMALE | 
#line 503
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 506
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 508
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 507
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 510
    [TRAINER_DAISY] =
    {
#line 511
        .trainerName = _("DAISY"),
#line 512
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 513
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 514
F_TRAINER_FEMALE | 
#line 515
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 516
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 518
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 519
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 522
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 524
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 523
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 526
    [TRAINER_ROSE_1] =
    {
#line 527
        .trainerName = _("ROSE"),
#line 528
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 529
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 530
F_TRAINER_FEMALE | 
#line 531
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 534
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 535
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 538
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 540
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 539
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 542
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 544
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 543
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 546
    [TRAINER_FELIX] =
    {
#line 547
        .trainerName = _("FELIX"),
#line 548
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 549
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 551
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 552
        .items = { ITEM_FULL_RESTORE },
#line 553
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 555
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 557
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 556
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 558
                MOVE_PSYCHIC,
            },
            },
            {
#line 560
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 562
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 561
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 563
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 566
    [TRAINER_VIOLET] =
    {
#line 567
        .trainerName = _("VIOLET"),
#line 568
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 569
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 570
F_TRAINER_FEMALE | 
#line 571
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 572
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 574
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 576
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 575
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 578
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 580
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 579
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 582
    [TRAINER_ROSE_2] =
    {
#line 583
        .trainerName = _("ROSE"),
#line 584
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 585
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 586
F_TRAINER_FEMALE | 
#line 587
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 588
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 590
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 592
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 591
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 594
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 596
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 595
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 598
    [TRAINER_ROSE_3] =
    {
#line 599
        .trainerName = _("ROSE"),
#line 600
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 601
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 602
F_TRAINER_FEMALE | 
#line 603
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 606
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 608
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 607
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 610
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 612
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 611
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 614
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 616
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 615
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 618
    [TRAINER_ROSE_4] =
    {
#line 619
        .trainerName = _("ROSE"),
#line 620
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 621
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 622
F_TRAINER_FEMALE | 
#line 623
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 624
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 626
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 628
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 627
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 630
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 632
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 631
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 634
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 636
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 635
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 638
    [TRAINER_ROSE_5] =
    {
#line 639
        .trainerName = _("ROSE"),
#line 640
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 641
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 642
F_TRAINER_FEMALE | 
#line 643
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 644
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 646
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 648
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 647
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 650
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 652
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 651
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 654
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 656
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 655
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 658
    [TRAINER_DUSTY_1] =
    {
#line 659
        .trainerName = _("DUSTY"),
#line 660
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 661
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 663
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 664
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 666
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 668
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 667
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 669
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 674
    [TRAINER_CHIP] =
    {
#line 675
        .trainerName = _("CHIP"),
#line 676
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 677
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 679
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 680
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 682
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 684
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 683
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 685
                MOVE_PSYBEAM,
                MOVE_SELF_DESTRUCT,
                MOVE_TORMENTA_ARENA,
                MOVE_ANCIENT_POWER,
            },
            },
            {
#line 690
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 692
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 691
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 693
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 698
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 700
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 699
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 701
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 706
    [TRAINER_FOSTER] =
    {
#line 707
        .trainerName = _("FOSTER"),
#line 708
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 709
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 711
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 714
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 716
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 715
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 717
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
#line 722
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 724
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 723
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 725
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 730
    [TRAINER_DUSTY_2] =
    {
#line 731
        .trainerName = _("DUSTY"),
#line 732
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 733
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 735
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 736
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 738
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 740
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 739
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 741
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 746
    [TRAINER_DUSTY_3] =
    {
#line 747
        .trainerName = _("DUSTY"),
#line 748
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 749
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 751
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 752
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 754
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 756
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 755
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 757
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 762
    [TRAINER_DUSTY_4] =
    {
#line 763
        .trainerName = _("DUSTY"),
#line 764
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 765
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 767
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 768
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 770
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 772
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 771
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 773
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 778
    [TRAINER_DUSTY_5] =
    {
#line 779
        .trainerName = _("DUSTY"),
#line 780
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 781
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 783
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 786
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 788
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 787
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 789
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
#line 794
    [TRAINER_GABBY_AND_TY_1] =
    {
#line 795
        .trainerName = _("GABBY & TY"),
#line 796
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 797
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 799
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 800
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 802
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 804
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 803
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 806
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 808
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 807
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 810
    [TRAINER_GABBY_AND_TY_2] =
    {
#line 811
        .trainerName = _("GABBY & TY"),
#line 812
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 813
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 815
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 816
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 818
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 820
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 819
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 822
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 824
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 823
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 826
    [TRAINER_GABBY_AND_TY_3] =
    {
#line 827
        .trainerName = _("GABBY & TY"),
#line 828
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 829
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 831
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 832
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 834
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 836
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 835
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 838
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 840
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 839
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 842
    [TRAINER_GABBY_AND_TY_4] =
    {
#line 843
        .trainerName = _("GABBY & TY"),
#line 844
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 845
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 847
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 850
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 852
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 851
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 854
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 856
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 855
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 858
    [TRAINER_GABBY_AND_TY_5] =
    {
#line 859
        .trainerName = _("GABBY & TY"),
#line 860
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 861
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 863
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 866
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 868
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 867
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 870
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 872
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 871
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 874
    [TRAINER_GABBY_AND_TY_6] =
    {
#line 875
        .trainerName = _("GABBY & TY"),
#line 876
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
#line 877
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender = 
#line 879
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
#line 880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 882
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 884
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 883
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 885
                MOVE_BOMBA_SONICA,
                MOVE_THUNDER_WAVE,
                MOVE_METAL_SOUND,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 890
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 892
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 891
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 893
                MOVE_ASTONISH,
                MOVE_PISOTON,
                MOVE_SUPERSONIC,
                MOVE_HYPER_VOICE,
            },
            },
        },
    },
#line 898
    [TRAINER_LOLA_1] =
    {
#line 899
        .trainerName = _("LOLA"),
#line 900
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 901
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 902
F_TRAINER_FEMALE | 
#line 903
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 904
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 906
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 908
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 907
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 910
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 912
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 911
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 914
    [TRAINER_AUSTINA] =
    {
#line 915
        .trainerName = _("AUSTINA"),
#line 916
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 917
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 918
F_TRAINER_FEMALE | 
#line 919
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 920
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 922
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 923
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 926
    [TRAINER_GWEN] =
    {
#line 927
        .trainerName = _("GWEN"),
#line 928
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 929
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 930
F_TRAINER_FEMALE | 
#line 931
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 934
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 935
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 938
    [TRAINER_LOLA_2] =
    {
#line 939
        .trainerName = _("LOLA"),
#line 940
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 941
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 942
F_TRAINER_FEMALE | 
#line 943
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 946
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 948
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 947
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 950
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 952
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 951
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 954
    [TRAINER_LOLA_3] =
    {
#line 955
        .trainerName = _("LOLA"),
#line 956
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 957
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 958
F_TRAINER_FEMALE | 
#line 959
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 960
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 962
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 964
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 963
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 966
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 968
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 967
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 970
    [TRAINER_LOLA_4] =
    {
#line 971
        .trainerName = _("LOLA"),
#line 972
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 973
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 974
F_TRAINER_FEMALE | 
#line 975
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 976
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 978
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 980
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 979
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 982
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 984
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 983
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 986
    [TRAINER_LOLA_5] =
    {
#line 987
        .trainerName = _("LOLA"),
#line 988
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 989
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 990
F_TRAINER_FEMALE | 
#line 991
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 992
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 994
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 996
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 995
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 998
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1000
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 999
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1002
    [TRAINER_RICKY_1] =
    {
#line 1003
        .trainerName = _("RICKY"),
#line 1004
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1005
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1007
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1010
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1012
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1011
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1013
                MOVE_SAND_ATTACK,
                MOVE_HEADBUTT,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1018
    [TRAINER_SIMON] =
    {
#line 1019
        .trainerName = _("SIMON"),
#line 1020
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1021
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1023
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1024
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1026
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1028
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1027
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1030
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1032
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1031
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1034
    [TRAINER_CHARLIE] =
    {
#line 1035
        .trainerName = _("CHARLIE"),
#line 1036
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1037
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1039
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1040
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1042
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1044
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1043
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1046
    [TRAINER_RICKY_2] =
    {
#line 1047
        .trainerName = _("RICKY"),
#line 1048
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1049
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1051
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1052
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1054
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1056
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1055
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1057
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1062
    [TRAINER_RICKY_3] =
    {
#line 1063
        .trainerName = _("RICKY"),
#line 1064
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1065
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1067
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1070
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1072
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1071
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1073
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1078
    [TRAINER_RICKY_4] =
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
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1087
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1089
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1094
    [TRAINER_RICKY_5] =
    {
#line 1095
        .trainerName = _("RICKY"),
#line 1096
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 1097
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 1099
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 1100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1102
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1104
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1103
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1105
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
#line 1110
    [TRAINER_RANDALL] =
    {
#line 1111
        .trainerName = _("RANDALL"),
#line 1112
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1113
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1115
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1116
        .items = { ITEM_HYPER_POTION },
#line 1117
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1119
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1121
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1120
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1122
                MOVE_QUICK_ATTACK,
                MOVE_AGILITY,
                MOVE_WING_ATTACK,
            },
            },
        },
    },
#line 1126
    [TRAINER_PARKER] =
    {
#line 1127
        .trainerName = _("PARKER"),
#line 1128
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1129
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1131
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1132
        .items = { ITEM_HYPER_POTION },
#line 1133
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1135
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1137
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1136
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1138
                MOVE_TEETER_DANCE,
                MOVE_DIZZY_PUNCH,
                MOVE_FOCUS_PUNCH,
            },
            },
        },
    },
#line 1142
    [TRAINER_GEORGE] =
    {
#line 1143
        .trainerName = _("GEORGE"),
#line 1144
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1145
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1147
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1148
        .items = { ITEM_HYPER_POTION },
#line 1149
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1151
            .species = SPECIES_SLAKOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1151
            .heldItem = ITEM_SITRUS_BERRY,
#line 1153
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1152
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1154
                MOVE_SLACK_OFF,
                MOVE_COUNTER,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 1158
    [TRAINER_BERKE] =
    {
#line 1159
        .trainerName = _("BERKE"),
#line 1160
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1161
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1163
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1164
        .items = { ITEM_HYPER_POTION },
#line 1165
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1167
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1169
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1168
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1170
                MOVE_FOCUS_ENERGY,
                MOVE_SLASH,
            },
            },
        },
    },
#line 1173
    [TRAINER_BRAXTON] =
    {
#line 1174
        .trainerName = _("BRAXTON"),
#line 1175
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1176
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1178
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1179
        .items = { ITEM_HYPER_POTION },
#line 1180
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 1182
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1184
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1183
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1185
                MOVE_FOCUS_ENERGY,
                MOVE_QUICK_ATTACK,
                MOVE_WING_ATTACK,
                MOVE_ENDEAVOR,
            },
            },
            {
#line 1190
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1192
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1191
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1193
                MOVE_BITE,
                MOVE_DIG,
                MOVE_FEINT_ATTACK,
                MOVE_SAND_TOMB,
            },
            },
            {
#line 1198
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1200
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1199
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1201
                MOVE_ROLLOUT,
                MOVE_WHIRLPOOL,
                MOVE_ASTONISH,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 1206
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1208
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1207
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1209
                MOVE_THUNDERBOLT,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_WAVE,
                MOVE_BOMBA_SONICA,
            },
            },
            {
#line 1214
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1216
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1215
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1217
                MOVE_GIGA_DRAIN,
                MOVE_FEINT_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
            },
            },
        },
    },
#line 1222
    [TRAINER_VINCENT] =
    {
#line 1223
        .trainerName = _("VINCENT"),
#line 1224
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1225
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1227
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1228
        .items = { ITEM_FULL_RESTORE },
#line 1229
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1231
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1233
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1232
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1235
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1237
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1236
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1239
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1241
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1240
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1243
    [TRAINER_LEROY] =
    {
#line 1244
        .trainerName = _("LEROY"),
#line 1245
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1246
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1248
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1249
        .items = { ITEM_FULL_RESTORE },
#line 1250
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1252
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1254
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1253
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1256
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1258
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1257
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1260
    [TRAINER_WILTON_1] =
    {
#line 1261
        .trainerName = _("WILTON"),
#line 1262
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1263
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1265
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1266
        .items = { ITEM_SUPER_POTION },
#line 1267
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1269
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1271
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1270
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1273
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1275
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1274
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1277
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1279
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1278
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1281
    [TRAINER_EDGAR] =
    {
#line 1282
        .trainerName = _("EDGAR"),
#line 1283
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1284
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1286
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1287
        .items = { ITEM_FULL_RESTORE },
#line 1288
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1290
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1292
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1291
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1294
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1296
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1295
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1298
    [TRAINER_ALBERT] =
    {
#line 1299
        .trainerName = _("ALBERT"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1307
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1309
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1308
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1311
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1313
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1312
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1315
    [TRAINER_SAMUEL] =
    {
#line 1316
        .trainerName = _("SAMUEL"),
#line 1317
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1318
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1320
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1321
        .items = { ITEM_FULL_RESTORE },
#line 1322
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1324
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1326
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1325
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1328
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1330
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1329
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1332
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1334
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1333
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1336
    [TRAINER_VITO] =
    {
#line 1337
        .trainerName = _("VITO"),
#line 1338
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1339
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1341
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1342
        .items = { ITEM_FULL_RESTORE },
#line 1343
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 1345
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1347
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1346
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1349
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1351
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1350
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1353
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1355
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1354
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1357
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1359
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1358
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1361
    [TRAINER_OWEN] =
    {
#line 1362
        .trainerName = _("OWEN"),
#line 1363
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1364
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1366
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1367
        .items = { ITEM_FULL_RESTORE },
#line 1368
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1370
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1372
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1371
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1374
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1376
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1375
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1378
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1380
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1379
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1382
    [TRAINER_WILTON_2] =
    {
#line 1383
        .trainerName = _("WILTON"),
#line 1384
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1385
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1387
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1388
        .items = { ITEM_HYPER_POTION },
#line 1389
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1391
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1393
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1392
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1395
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1397
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1396
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1399
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1401
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1400
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1403
    [TRAINER_WILTON_3] =
    {
#line 1404
        .trainerName = _("WILTON"),
#line 1405
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1406
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1408
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1409
        .items = { ITEM_HYPER_POTION },
#line 1410
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1412
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1414
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1413
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1416
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1418
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1417
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1420
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1422
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1421
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1424
    [TRAINER_WILTON_4] =
    {
#line 1425
        .trainerName = _("WILTON"),
#line 1426
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1427
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1429
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1430
        .items = { ITEM_FULL_RESTORE },
#line 1431
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1433
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1435
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1434
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1437
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1439
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1438
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1441
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1443
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1442
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1445
    [TRAINER_WILTON_5] =
    {
#line 1446
        .trainerName = _("WILTON"),
#line 1447
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1448
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1450
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1451
        .items = { ITEM_FULL_RESTORE },
#line 1452
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1454
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1456
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1455
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1458
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1460
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1459
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1462
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1464
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1463
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1466
    [TRAINER_WARREN] =
    {
#line 1467
        .trainerName = _("WARREN"),
#line 1468
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1469
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 1471
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1472
        .items = { ITEM_FULL_RESTORE },
#line 1473
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1475
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1477
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1476
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1479
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1481
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1480
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1483
    [TRAINER_MARY] =
    {
#line 1484
        .trainerName = _("MARY"),
#line 1485
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1486
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1487
F_TRAINER_FEMALE | 
#line 1488
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1489
        .items = { ITEM_HYPER_POTION },
#line 1490
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1492
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1494
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1493
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1495
                MOVE_FEINT_ATTACK,
                MOVE_SHOCK_WAVE,
            },
            },
        },
    },
#line 1498
    [TRAINER_ALEXIA] =
    {
#line 1499
        .trainerName = _("ALEXIA"),
#line 1500
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1501
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1502
F_TRAINER_FEMALE | 
#line 1503
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1504
        .items = { ITEM_HYPER_POTION },
#line 1505
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1507
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1509
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1508
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1510
                MOVE_DEFENSE_CURL,
                MOVE_DOUBLE_EDGE,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 1514
    [TRAINER_JODY] =
    {
#line 1515
        .trainerName = _("JODY"),
#line 1516
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1517
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1518
F_TRAINER_FEMALE | 
#line 1519
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1520
        .items = { ITEM_HYPER_POTION },
#line 1521
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1523
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1525
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 1524
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1526
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
#line 1529
    [TRAINER_WENDY] =
    {
#line 1530
        .trainerName = _("WENDY"),
#line 1531
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1532
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1533
F_TRAINER_FEMALE | 
#line 1534
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1535
        .items = { ITEM_FULL_RESTORE },
#line 1536
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1538
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1540
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1539
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1541
                MOVE_RELEVO,
                MOVE_FEINT_ATTACK,
                MOVE_FAKE_TEARS,
                MOVE_BITE,
            },
            },
            {
#line 1546
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1548
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1547
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1549
                MOVE_MEGA_DRAIN,
                MOVE_MAGICAL_LEAF,
                MOVE_SILBATO,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 1554
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1556
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1555
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1557
                MOVE_FLY,
                MOVE_WATER_GUN,
                MOVE_NEBLINA,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 1562
    [TRAINER_KEIRA] =
    {
#line 1563
        .trainerName = _("KEIRA"),
#line 1564
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1565
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1566
F_TRAINER_FEMALE | 
#line 1567
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1568
        .items = { ITEM_FULL_RESTORE },
#line 1569
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1571
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1573
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1572
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1575
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1577
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1576
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1579
    [TRAINER_BROOKE_1] =
    {
#line 1580
        .trainerName = _("BROOKE"),
#line 1581
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1582
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1583
F_TRAINER_FEMALE | 
#line 1584
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1585
        .items = { ITEM_SUPER_POTION },
#line 1586
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1588
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1590
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1589
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1592
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1594
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1593
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1596
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1598
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1597
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1600
    [TRAINER_JENNIFER] =
    {
#line 1601
        .trainerName = _("JENNIFER"),
#line 1602
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1603
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1604
F_TRAINER_FEMALE | 
#line 1605
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1606
        .items = { ITEM_FULL_RESTORE },
#line 1607
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1609
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1611
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 1610
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1613
    [TRAINER_HOPE] =
    {
#line 1614
        .trainerName = _("HOPE"),
#line 1615
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1616
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1617
F_TRAINER_FEMALE | 
#line 1618
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1619
        .items = { ITEM_FULL_RESTORE },
#line 1620
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1622
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1624
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1623
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1626
    [TRAINER_SHANNON] =
    {
#line 1627
        .trainerName = _("SHANNON"),
#line 1628
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1629
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1630
F_TRAINER_FEMALE | 
#line 1631
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1632
        .items = { ITEM_FULL_RESTORE },
#line 1633
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1635
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1637
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1636
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1639
    [TRAINER_MICHELLE] =
    {
#line 1640
        .trainerName = _("MICHELLE"),
#line 1641
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1642
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1643
F_TRAINER_FEMALE | 
#line 1644
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1645
        .items = { ITEM_FULL_RESTORE },
#line 1646
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1648
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1650
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1649
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1652
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1654
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1653
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1656
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1658
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1657
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1660
    [TRAINER_CAROLINE] =
    {
#line 1661
        .trainerName = _("CAROLINE"),
#line 1662
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1663
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1664
F_TRAINER_FEMALE | 
#line 1665
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1666
        .items = { ITEM_FULL_RESTORE },
#line 1667
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1669
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1671
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1670
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1673
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1675
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1674
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1677
    [TRAINER_JULIE] =
    {
#line 1678
        .trainerName = _("JULIE"),
#line 1679
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1680
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1681
F_TRAINER_FEMALE | 
#line 1682
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1683
        .items = { ITEM_FULL_RESTORE },
#line 1684
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1686
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1688
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1687
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1690
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1692
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1691
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1694
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1696
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1695
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1698
    [TRAINER_BROOKE_2] =
    {
#line 1699
        .trainerName = _("BROOKE"),
#line 1700
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1701
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1702
F_TRAINER_FEMALE | 
#line 1703
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1704
        .items = { ITEM_HYPER_POTION },
#line 1705
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1707
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1709
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1708
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1711
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1713
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1712
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1715
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1717
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 1716
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1719
    [TRAINER_BROOKE_3] =
    {
#line 1720
        .trainerName = _("BROOKE"),
#line 1721
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1722
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1723
F_TRAINER_FEMALE | 
#line 1724
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1725
        .items = { ITEM_HYPER_POTION },
#line 1726
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1728
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1730
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1729
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1732
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1734
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1733
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1736
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1738
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 1737
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1740
    [TRAINER_BROOKE_4] =
    {
#line 1741
        .trainerName = _("BROOKE"),
#line 1742
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1743
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1744
F_TRAINER_FEMALE | 
#line 1745
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1746
        .items = { ITEM_FULL_RESTORE },
#line 1747
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1749
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1751
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1750
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1753
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1755
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1754
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1757
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1759
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 1758
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1761
    [TRAINER_BROOKE_5] =
    {
#line 1762
        .trainerName = _("BROOKE"),
#line 1763
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 1764
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 1765
F_TRAINER_FEMALE | 
#line 1766
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 1767
        .items = { ITEM_FULL_RESTORE },
#line 1768
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1770
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1772
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1771
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1774
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1776
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1775
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1778
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1780
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 1779
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1782
    [TRAINER_PATRICIA] =
    {
#line 1783
        .trainerName = _("PATRICIA"),
#line 1784
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1785
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1786
F_TRAINER_FEMALE | 
#line 1787
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1788
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1790
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1792
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1791
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1794
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1796
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1795
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1798
    [TRAINER_KINDRA] =
    {
#line 1799
        .trainerName = _("KINDRA"),
#line 1800
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1801
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1802
F_TRAINER_FEMALE | 
#line 1803
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1804
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1806
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1808
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1807
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1810
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1812
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1811
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1814
    [TRAINER_TAMMY] =
    {
#line 1815
        .trainerName = _("TAMMY"),
#line 1816
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1817
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1818
F_TRAINER_FEMALE | 
#line 1819
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1820
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1822
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1823
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1826
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1828
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1827
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1830
    [TRAINER_VALERIE_1] =
    {
#line 1831
        .trainerName = _("VALERIE"),
#line 1832
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1833
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1834
F_TRAINER_FEMALE | 
#line 1835
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1836
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1838
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1840
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1839
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1842
    [TRAINER_TASHA] =
    {
#line 1843
        .trainerName = _("TASHA"),
#line 1844
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1845
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1846
F_TRAINER_FEMALE | 
#line 1847
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1848
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1850
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1852
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 1851
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1854
    [TRAINER_VALERIE_2] =
    {
#line 1855
        .trainerName = _("VALERIE"),
#line 1856
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1857
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1858
F_TRAINER_FEMALE | 
#line 1859
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1860
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1862
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1864
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1863
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1866
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1868
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 1867
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1870
    [TRAINER_VALERIE_3] =
    {
#line 1871
        .trainerName = _("VALERIE"),
#line 1872
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1873
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1874
F_TRAINER_FEMALE | 
#line 1875
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1876
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1878
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1880
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1879
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1882
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1884
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 1883
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1886
    [TRAINER_VALERIE_4] =
    {
#line 1887
        .trainerName = _("VALERIE"),
#line 1888
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1889
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1890
F_TRAINER_FEMALE | 
#line 1891
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1892
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1894
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1896
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1895
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1898
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1900
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 1899
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1902
    [TRAINER_VALERIE_5] =
    {
#line 1903
        .trainerName = _("VALERIE"),
#line 1904
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 1905
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 1906
F_TRAINER_FEMALE | 
#line 1907
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 1908
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1910
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1912
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1911
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1914
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1916
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1915
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1918
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1920
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 1919
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1922
    [TRAINER_CINDY_1] =
    {
#line 1923
        .trainerName = _("CINDY"),
#line 1924
        .trainerClass = TRAINER_CLASS_LADY,
#line 1925
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 1926
F_TRAINER_FEMALE | 
#line 1927
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 1928
        .items = { ITEM_FULL_RESTORE },
#line 1929
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1931
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1931
            .heldItem = ITEM_NUGGET,
#line 1933
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1932
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1935
    [TRAINER_DAPHNE] =
    {
#line 1936
        .trainerName = _("DAPHNE"),
#line 1937
        .trainerClass = TRAINER_CLASS_LADY,
#line 1938
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 1939
F_TRAINER_FEMALE | 
#line 1940
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 1941
        .items = { ITEM_FULL_RESTORE },
#line 1942
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 1944
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1944
            .heldItem = ITEM_NUGGET,
#line 1946
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1945
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1947
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 1952
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1952
            .heldItem = ITEM_NUGGET,
#line 1954
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 1953
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1955
                MOVE_ATTRACT,
                MOVE_SAFEGUARD,
                MOVE_TAKE_DOWN,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 1960
    [TRAINER_GRUNT_SPACE_CENTER_2] =
    {
#line 1961
        .trainerName = _("GRUNT"),
#line 1962
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 1963
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 1965
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 1966
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 1968
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1970
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1969
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1972
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1974
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1973
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 1976
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1978
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1977
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 1980
    [TRAINER_CINDY_2] =
    {
#line 1981
        .trainerName = _("CINDY"),
#line 1982
        .trainerClass = TRAINER_CLASS_LADY,
#line 1983
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 1984
F_TRAINER_FEMALE | 
#line 1985
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 1986
        .items = { ITEM_FULL_RESTORE },
#line 1987
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 1989
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 1989
            .heldItem = ITEM_NUGGET,
#line 1991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 1990
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 1992
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
#line 1995
    [TRAINER_BRIANNA] =
    {
#line 1996
        .trainerName = _("BRIANNA"),
#line 1997
        .trainerClass = TRAINER_CLASS_LADY,
#line 1998
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 1999
F_TRAINER_FEMALE | 
#line 2000
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2001
        .items = { ITEM_FULL_RESTORE },
#line 2002
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2004
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2004
            .heldItem = ITEM_NUGGET,
#line 2006
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 2005
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2008
    [TRAINER_NAOMI] =
    {
#line 2009
        .trainerName = _("NAOMI"),
#line 2010
        .trainerClass = TRAINER_CLASS_LADY,
#line 2011
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2012
F_TRAINER_FEMALE | 
#line 2013
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2014
        .items = { ITEM_FULL_RESTORE },
#line 2015
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2017
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2017
            .heldItem = ITEM_NUGGET,
#line 2019
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2018
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2021
    [TRAINER_CINDY_3] =
    {
#line 2022
        .trainerName = _("CINDY"),
#line 2023
        .trainerClass = TRAINER_CLASS_LADY,
#line 2024
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2025
F_TRAINER_FEMALE | 
#line 2026
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2027
        .items = { ITEM_FULL_RESTORE },
#line 2028
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2030
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2030
            .heldItem = ITEM_NUGGET,
#line 2032
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2031
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2034
    [TRAINER_CINDY_4] =
    {
#line 2035
        .trainerName = _("CINDY"),
#line 2036
        .trainerClass = TRAINER_CLASS_LADY,
#line 2037
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2038
F_TRAINER_FEMALE | 
#line 2039
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2040
        .items = { ITEM_FULL_RESTORE },
#line 2041
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2043
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2043
            .heldItem = ITEM_NUGGET,
#line 2045
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2044
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2047
    [TRAINER_CINDY_5] =
    {
#line 2048
        .trainerName = _("CINDY"),
#line 2049
        .trainerClass = TRAINER_CLASS_LADY,
#line 2050
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2051
F_TRAINER_FEMALE | 
#line 2052
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2053
        .items = { ITEM_FULL_RESTORE },
#line 2054
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2056
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2056
            .heldItem = ITEM_NUGGET,
#line 2058
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2057
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2060
    [TRAINER_CINDY_6] =
    {
#line 2061
        .trainerName = _("CINDY"),
#line 2062
        .trainerClass = TRAINER_CLASS_LADY,
#line 2063
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 2064
F_TRAINER_FEMALE | 
#line 2065
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2066
        .items = { ITEM_FULL_RESTORE },
#line 2067
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2069
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2069
            .heldItem = ITEM_NUGGET,
#line 2071
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2070
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2072
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 2077
    [TRAINER_MELISSA] =
    {
#line 2078
        .trainerName = _("MELISSA"),
#line 2079
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2080
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2081
F_TRAINER_FEMALE | 
#line 2082
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2085
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2086
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2089
    [TRAINER_SHEILA] =
    {
#line 2090
        .trainerName = _("SHEILA"),
#line 2091
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2092
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2093
F_TRAINER_FEMALE | 
#line 2094
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2095
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2097
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2099
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2098
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2101
    [TRAINER_SHIRLEY] =
    {
#line 2102
        .trainerName = _("SHIRLEY"),
#line 2103
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2104
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2105
F_TRAINER_FEMALE | 
#line 2106
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2107
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2109
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2110
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2113
    [TRAINER_JESSICA_1] =
    {
#line 2114
        .trainerName = _("JESSICA"),
#line 2115
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2116
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2117
F_TRAINER_FEMALE | 
#line 2118
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2119
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2121
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2123
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2122
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2124
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2129
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2130
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2132
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2137
    [TRAINER_CONNIE] =
    {
#line 2138
        .trainerName = _("CONNIE"),
#line 2139
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2140
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2141
F_TRAINER_FEMALE | 
#line 2142
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2145
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2147
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2146
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2149
    [TRAINER_BRIDGET] =
    {
#line 2150
        .trainerName = _("BRIDGET"),
#line 2151
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2152
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2153
F_TRAINER_FEMALE | 
#line 2154
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2155
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2157
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2159
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 2158
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2161
    [TRAINER_OLIVIA] =
    {
#line 2162
        .trainerName = _("OLIVIA"),
#line 2163
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2164
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2165
F_TRAINER_FEMALE | 
#line 2166
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2167
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2169
            .species = SPECIES_CLAMPERL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2171
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2170
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2172
                MOVE_IRON_DEFENSE,
                MOVE_WHIRLPOOL,
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 2177
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2179
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2178
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2180
                MOVE_TAUNT,
                MOVE_CRABHAMMER,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 2184
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2186
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2185
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2187
                MOVE_UPROAR,
                MOVE_FURY_SWIPES,
                MOVE_SORPRESA,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 2192
    [TRAINER_TIFFANY] =
    {
#line 2193
        .trainerName = _("TIFFANY"),
#line 2194
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2195
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2196
F_TRAINER_FEMALE | 
#line 2197
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2198
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2200
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2202
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2201
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2204
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2206
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2205
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2208
    [TRAINER_JESSICA_2] =
    {
#line 2209
        .trainerName = _("JESSICA"),
#line 2210
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2211
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2212
F_TRAINER_FEMALE | 
#line 2213
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2214
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2216
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2218
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2217
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2219
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2224
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2226
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2225
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2227
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2232
    [TRAINER_JESSICA_3] =
    {
#line 2233
        .trainerName = _("JESSICA"),
#line 2234
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2235
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2236
F_TRAINER_FEMALE | 
#line 2237
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2238
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2240
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2242
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2241
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2243
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2248
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2250
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2249
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2251
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2256
    [TRAINER_JESSICA_4] =
    {
#line 2257
        .trainerName = _("JESSICA"),
#line 2258
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2259
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2260
F_TRAINER_FEMALE | 
#line 2261
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2264
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2266
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2265
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2267
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2272
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2274
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2273
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2275
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2280
    [TRAINER_JESSICA_5] =
    {
#line 2281
        .trainerName = _("JESSICA"),
#line 2282
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2283
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2284
F_TRAINER_FEMALE | 
#line 2285
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2286
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2288
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2290
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2289
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2291
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 2296
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2298
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2297
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2299
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 2304
    [TRAINER_WINSTON_1] =
    {
#line 2305
        .trainerName = _("WINSTON"),
#line 2306
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2307
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2309
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2310
        .items = { ITEM_FULL_RESTORE },
#line 2311
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2313
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2313
            .heldItem = ITEM_NUGGET,
#line 2315
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2314
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2317
    [TRAINER_MOLLIE] =
    {
#line 2318
        .trainerName = _("MOLLIE"),
#line 2319
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 2320
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 2321
F_TRAINER_FEMALE | 
#line 2322
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2323
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2325
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2327
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2326
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2329
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2331
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 2330
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2333
    [TRAINER_GARRET] =
    {
#line 2334
        .trainerName = _("GARRET"),
#line 2335
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2336
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2338
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2339
        .items = { ITEM_FULL_RESTORE },
#line 2340
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2342
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2342
            .heldItem = ITEM_NUGGET,
#line 2344
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2343
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2346
    [TRAINER_WINSTON_2] =
    {
#line 2347
        .trainerName = _("WINSTON"),
#line 2348
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2349
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2351
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2352
        .items = { ITEM_FULL_RESTORE },
#line 2353
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2355
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2355
            .heldItem = ITEM_NUGGET,
#line 2357
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2356
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2359
    [TRAINER_WINSTON_3] =
    {
#line 2360
        .trainerName = _("WINSTON"),
#line 2361
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2362
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2364
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2365
        .items = { ITEM_FULL_RESTORE },
#line 2366
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2368
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2368
            .heldItem = ITEM_NUGGET,
#line 2370
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2369
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2372
    [TRAINER_WINSTON_4] =
    {
#line 2373
        .trainerName = _("WINSTON"),
#line 2374
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2375
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2377
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2378
        .items = { ITEM_FULL_RESTORE },
#line 2379
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2381
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2381
            .heldItem = ITEM_NUGGET,
#line 2383
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2382
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2385
    [TRAINER_WINSTON_5] =
    {
#line 2386
        .trainerName = _("WINSTON"),
#line 2387
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 2388
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 2390
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 2391
        .items = { ITEM_FULL_RESTORE },
#line 2392
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2394
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2394
            .heldItem = ITEM_NUGGET,
#line 2396
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2395
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 2397
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
#line 2402
    [TRAINER_STEVE_1] =
    {
#line 2403
        .trainerName = _("STEVE"),
#line 2404
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2405
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2407
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2408
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2410
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2412
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2411
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2414
    [TRAINER_THALIA_1] =
    {
#line 2415
        .trainerName = _("THALIA"),
#line 2416
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 2417
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 2418
F_TRAINER_FEMALE | 
#line 2419
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 2420
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2422
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2424
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2423
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2426
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2428
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2427
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2430
    [TRAINER_MARK] =
    {
#line 2431
        .trainerName = _("MARK"),
#line 2432
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2433
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2435
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2436
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2438
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2440
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2439
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2442
    [TRAINER_GRUNT_MT_CHIMNEY_1] =
    {
#line 2443
        .trainerName = _("GRUNT"),
#line 2444
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 2445
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 2446
F_TRAINER_FEMALE | 
#line 2447
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 2448
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2450
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2452
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2451
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2454
    [TRAINER_STEVE_2] =
    {
#line 2455
        .trainerName = _("STEVE"),
#line 2456
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2457
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2459
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2460
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2462
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2464
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2463
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2466
    [TRAINER_STEVE_3] =
    {
#line 2467
        .trainerName = _("STEVE"),
#line 2468
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2469
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2471
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2472
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2474
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2476
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2475
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2478
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2480
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2479
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2482
    [TRAINER_STEVE_4] =
    {
#line 2483
        .trainerName = _("STEVE"),
#line 2484
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2485
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2487
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2488
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2490
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2492
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2491
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2494
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2496
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2495
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2498
    [TRAINER_STEVE_5] =
    {
#line 2499
        .trainerName = _("STEVE"),
#line 2500
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 2501
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 2503
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 2504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2506
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2508
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2507
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2510
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2512
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2511
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2514
    [TRAINER_LUIS] =
    {
#line 2515
        .trainerName = _("LUIS"),
#line 2516
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2517
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2519
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2520
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2522
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2524
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2523
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2526
    [TRAINER_DOMINIK] =
    {
#line 2527
        .trainerName = _("DOMINIK"),
#line 2528
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2529
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2531
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2534
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2535
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2538
    [TRAINER_DOUGLAS] =
    {
#line 2539
        .trainerName = _("DOUGLAS"),
#line 2540
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2541
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2543
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2544
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2546
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2548
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2547
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2550
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2552
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2551
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2554
    [TRAINER_DARRIN] =
    {
#line 2555
        .trainerName = _("DARRIN"),
#line 2556
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2557
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2559
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2560
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2562
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2564
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2563
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2566
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2568
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2567
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2570
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2572
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2571
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2574
    [TRAINER_TONY_1] =
    {
#line 2575
        .trainerName = _("TONY"),
#line 2576
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2577
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2579
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2582
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2583
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2586
    [TRAINER_JEROME] =
    {
#line 2587
        .trainerName = _("JEROME"),
#line 2588
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2589
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2591
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2594
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2595
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2598
    [TRAINER_MATTHEW] =
    {
#line 2599
        .trainerName = _("MATTHEW"),
#line 2600
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2601
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2603
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2606
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2608
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2607
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2610
    [TRAINER_DAVID] =
    {
#line 2611
        .trainerName = _("DAVID"),
#line 2612
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2613
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2615
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2616
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2618
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2620
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2619
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2622
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2624
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2623
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2626
    [TRAINER_SPENCER] =
    {
#line 2627
        .trainerName = _("SPENCER"),
#line 2628
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2629
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2631
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2632
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2634
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2636
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2635
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2638
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2640
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2639
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2642
    [TRAINER_ROLAND] =
    {
#line 2643
        .trainerName = _("ROLAND"),
#line 2644
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2645
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2647
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2648
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2650
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2652
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2651
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2654
    [TRAINER_NOLEN] =
    {
#line 2655
        .trainerName = _("NOLEN"),
#line 2656
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2657
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2659
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2660
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2662
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2664
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2663
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2666
    [TRAINER_STAN] =
    {
#line 2667
        .trainerName = _("STAN"),
#line 2668
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2669
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2671
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2672
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2674
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2676
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2675
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2678
    [TRAINER_BARRY] =
    {
#line 2679
        .trainerName = _("BARRY"),
#line 2680
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2681
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2683
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2684
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2686
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2688
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2687
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2690
    [TRAINER_DEAN] =
    {
#line 2691
        .trainerName = _("DEAN"),
#line 2692
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2693
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2695
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2698
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2700
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2699
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2702
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2704
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2703
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2706
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2708
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2707
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2710
    [TRAINER_RODNEY] =
    {
#line 2711
        .trainerName = _("RODNEY"),
#line 2712
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2713
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2715
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2716
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2718
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2720
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2719
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2722
    [TRAINER_RICHARD] =
    {
#line 2723
        .trainerName = _("RICHARD"),
#line 2724
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2725
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2727
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2728
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2730
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2732
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2731
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2734
    [TRAINER_HERMAN] =
    {
#line 2735
        .trainerName = _("HERMAN"),
#line 2736
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2737
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2739
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2740
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2742
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2744
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2743
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2746
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2748
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2747
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2750
    [TRAINER_SANTIAGO] =
    {
#line 2751
        .trainerName = _("SANTIAGO"),
#line 2752
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2753
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2755
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2756
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2758
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2760
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2759
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2762
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2764
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2763
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2766
    [TRAINER_GILBERT] =
    {
#line 2767
        .trainerName = _("GILBERT"),
#line 2768
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2769
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2771
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2772
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2774
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2776
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2775
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2778
    [TRAINER_FRANKLIN] =
    {
#line 2779
        .trainerName = _("FRANKLIN"),
#line 2780
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2781
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2783
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2786
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2788
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2787
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2790
    [TRAINER_KEVIN] =
    {
#line 2791
        .trainerName = _("KEVIN"),
#line 2792
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2793
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2795
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2796
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2798
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2800
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2799
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2802
    [TRAINER_JACK] =
    {
#line 2803
        .trainerName = _("JACK"),
#line 2804
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2805
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2807
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2808
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2810
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2812
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2811
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2814
    [TRAINER_DUDLEY] =
    {
#line 2815
        .trainerName = _("DUDLEY"),
#line 2816
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2817
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2819
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2820
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 2822
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2823
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2826
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2828
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2827
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2830
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2832
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2831
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2834
    [TRAINER_CHAD] =
    {
#line 2835
        .trainerName = _("CHAD"),
#line 2836
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2837
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2839
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2840
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2842
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2844
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2843
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2846
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2848
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 2847
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2850
    [TRAINER_TONY_2] =
    {
#line 2851
        .trainerName = _("TONY"),
#line 2852
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2853
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2855
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2856
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2858
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2860
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 2859
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2862
    [TRAINER_TONY_3] =
    {
#line 2863
        .trainerName = _("TONY"),
#line 2864
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2865
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2867
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2868
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2870
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2872
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 2871
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2874
    [TRAINER_TONY_4] =
    {
#line 2875
        .trainerName = _("TONY"),
#line 2876
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2877
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2879
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2882
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2884
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2883
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2886
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2888
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 2887
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2890
    [TRAINER_TONY_5] =
    {
#line 2891
        .trainerName = _("TONY"),
#line 2892
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 2893
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 2895
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 2896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2898
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2900
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2899
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2902
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2904
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 2903
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2906
    [TRAINER_TAKAO] =
    {
#line 2907
        .trainerName = _("TAKAO"),
#line 2908
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2909
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2911
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2912
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2914
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2916
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 2915
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2918
    [TRAINER_HITOSHI] =
    {
#line 2919
        .trainerName = _("HITOSHI"),
#line 2920
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2921
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2923
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2926
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2928
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 2927
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2930
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2932
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 2931
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2934
    [TRAINER_KIYO] =
    {
#line 2935
        .trainerName = _("KIYO"),
#line 2936
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2937
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2939
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2942
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2944
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2943
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2946
    [TRAINER_KOICHI] =
    {
#line 2947
        .trainerName = _("KOICHI"),
#line 2948
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2949
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2951
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2952
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2954
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2956
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2955
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2958
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2960
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 2959
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2962
    [TRAINER_NOB_1] =
    {
#line 2963
        .trainerName = _("NOB"),
#line 2964
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2965
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2967
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2970
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2972
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 2971
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2974
    [TRAINER_NOB_2] =
    {
#line 2975
        .trainerName = _("NOB"),
#line 2976
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2977
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2979
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 2982
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2984
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 2983
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 2986
    [TRAINER_NOB_3] =
    {
#line 2987
        .trainerName = _("NOB"),
#line 2988
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 2989
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 2991
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 2992
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 2994
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 2996
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 2995
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 2998
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3000
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 2999
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3002
    [TRAINER_NOB_4] =
    {
#line 3003
        .trainerName = _("NOB"),
#line 3004
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3005
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3007
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3010
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3012
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3011
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3014
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3016
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3015
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3018
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3020
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 3019
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3022
    [TRAINER_NOB_5] =
    {
#line 3023
        .trainerName = _("NOB"),
#line 3024
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3025
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3027
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3028
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3030
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3032
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3031
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3034
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3036
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3035
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3038
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3040
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3039
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3042
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3042
            .heldItem = ITEM_BLACK_BELT,
#line 3044
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 3043
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3046
    [TRAINER_YUJI] =
    {
#line 3047
        .trainerName = _("YUJI"),
#line 3048
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3049
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3051
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3052
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3054
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3056
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3055
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3058
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3060
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3059
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3062
    [TRAINER_DAISUKE] =
    {
#line 3063
        .trainerName = _("DAISUKE"),
#line 3064
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3065
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3067
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3070
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3072
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3071
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3074
    [TRAINER_ATSUSHI] =
    {
#line 3075
        .trainerName = _("ATSUSHI"),
#line 3076
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 3077
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 3079
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3080
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3082
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3084
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3083
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3086
    [TRAINER_KIRK] =
    {
#line 3087
        .trainerName = _("KIRK"),
#line 3088
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3089
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3091
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3092
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3094
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3096
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3095
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3097
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SPARK,
                MOVE_LEER,
            },
            },
            {
#line 3102
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3104
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3103
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3105
                MOVE_CHARGE,
                MOVE_SHOCK_WAVE,
                MOVE_SCREECH,
            },
            },
        },
    },
#line 3109
    [TRAINER_SHAWN] =
    {
#line 3110
        .trainerName = _("SHAWN"),
#line 3111
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3112
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3114
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3115
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3117
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3119
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3118
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3121
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3123
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3122
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3125
    [TRAINER_FERNANDO_1] =
    {
#line 3126
        .trainerName = _("FERNANDO"),
#line 3127
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3128
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3130
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3131
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3133
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3135
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3134
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3137
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3139
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3138
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3141
    [TRAINER_DALTON_1] =
    {
#line 3142
        .trainerName = _("DALTON"),
#line 3143
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3144
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3146
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3147
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3149
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3151
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3150
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3153
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3155
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3154
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3157
    [TRAINER_DALTON_2] =
    {
#line 3158
        .trainerName = _("DALTON"),
#line 3159
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3160
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3162
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3163
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3165
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3167
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3166
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3169
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3171
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3170
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3173
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3175
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3174
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3177
    [TRAINER_DALTON_3] =
    {
#line 3178
        .trainerName = _("DALTON"),
#line 3179
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3180
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3182
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3183
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3185
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3187
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3186
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3189
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3191
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3190
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3193
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3195
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3194
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3197
    [TRAINER_DALTON_4] =
    {
#line 3198
        .trainerName = _("DALTON"),
#line 3199
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3200
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3202
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3205
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3207
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3206
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3209
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3211
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3210
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3213
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3215
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3214
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3217
    [TRAINER_DALTON_5] =
    {
#line 3218
        .trainerName = _("DALTON"),
#line 3219
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 3220
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 3222
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3223
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3225
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3227
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3226
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3229
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3231
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3230
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3233
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3235
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3234
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3237
    [TRAINER_COLE] =
    {
#line 3238
        .trainerName = _("COLE"),
#line 3239
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3240
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3242
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3243
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3245
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3247
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3246
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3249
    [TRAINER_JEFF] =
    {
#line 3250
        .trainerName = _("JEFF"),
#line 3251
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3252
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3254
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3255
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3257
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3259
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3258
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3261
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3263
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3262
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3265
    [TRAINER_AXLE] =
    {
#line 3266
        .trainerName = _("AXLE"),
#line 3267
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3268
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3270
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3273
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3275
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3274
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3277
    [TRAINER_JACE] =
    {
#line 3278
        .trainerName = _("JACE"),
#line 3279
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3280
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3282
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3283
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3285
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3287
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3286
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3289
    [TRAINER_KEEGAN] =
    {
#line 3290
        .trainerName = _("KEEGAN"),
#line 3291
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3292
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3294
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3295
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3297
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3299
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 3298
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3301
    [TRAINER_BERNIE_1] =
    {
#line 3302
        .trainerName = _("BERNIE"),
#line 3303
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3304
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3306
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3309
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3311
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3310
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3313
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3315
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3314
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3317
    [TRAINER_BERNIE_2] =
    {
#line 3318
        .trainerName = _("BERNIE"),
#line 3319
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3320
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3322
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3323
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3325
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3327
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3326
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3329
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3331
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3330
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3333
    [TRAINER_BERNIE_3] =
    {
#line 3334
        .trainerName = _("BERNIE"),
#line 3335
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3336
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3338
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3339
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3341
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3343
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3342
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3345
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3347
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3346
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3349
    [TRAINER_BERNIE_4] =
    {
#line 3350
        .trainerName = _("BERNIE"),
#line 3351
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3352
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3354
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3355
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3357
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3359
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3358
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3361
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3363
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3362
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3365
    [TRAINER_BERNIE_5] =
    {
#line 3366
        .trainerName = _("BERNIE"),
#line 3367
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 3368
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 3370
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 3371
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3373
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3375
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3374
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3377
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3379
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3378
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3381
    [TRAINER_DREW] =
    {
#line 3382
        .trainerName = _("DREW"),
#line 3383
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3384
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3386
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3389
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3391
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3390
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3392
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
        },
    },
#line 3397
    [TRAINER_BEAU] =
    {
#line 3398
        .trainerName = _("BEAU"),
#line 3399
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3400
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3402
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3403
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3405
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3407
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3406
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3408
                MOVE_GIRO_RAPIDO,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 3413
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3414
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3416
                MOVE_POISON_STING,
                MOVE_SAND_ATTACK,
                MOVE_SCRATCH,
                MOVE_DIG,
            },
            },
            {
#line 3421
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3423
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3422
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3424
                MOVE_GIRO_RAPIDO,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 3429
    [TRAINER_LARRY] =
    {
#line 3430
        .trainerName = _("LARRY"),
#line 3431
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3432
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3434
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3437
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3438
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3441
    [TRAINER_SHANE] =
    {
#line 3442
        .trainerName = _("SHANE"),
#line 3443
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3444
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3446
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3447
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3449
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3451
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3450
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3453
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3455
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3454
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3457
    [TRAINER_JUSTIN] =
    {
#line 3458
        .trainerName = _("JUSTIN"),
#line 3459
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3460
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3462
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3465
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3467
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3466
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3469
    [TRAINER_ETHAN_1] =
    {
#line 3470
        .trainerName = _("ETHAN"),
#line 3471
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3472
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3474
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3475
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3477
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3479
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3478
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3481
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3483
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3482
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3485
    [TRAINER_AUTUMN] =
    {
#line 3486
        .trainerName = _("AUTUMN"),
#line 3487
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 3488
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 3489
F_TRAINER_FEMALE | 
#line 3490
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 3491
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3493
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3495
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3494
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3497
    [TRAINER_TRAVIS] =
    {
#line 3498
        .trainerName = _("TRAVIS"),
#line 3499
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3500
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3502
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3503
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3505
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3507
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3506
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3509
    [TRAINER_ETHAN_2] =
    {
#line 3510
        .trainerName = _("ETHAN"),
#line 3511
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3512
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3514
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3515
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3517
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3519
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3518
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3521
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3523
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3522
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3525
    [TRAINER_ETHAN_3] =
    {
#line 3526
        .trainerName = _("ETHAN"),
#line 3527
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3528
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3530
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3531
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3533
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3535
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3534
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3537
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3539
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3538
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3541
    [TRAINER_ETHAN_4] =
    {
#line 3542
        .trainerName = _("ETHAN"),
#line 3543
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3544
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3546
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3547
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3549
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3551
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3550
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3553
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3555
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3554
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3557
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3559
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3558
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3561
    [TRAINER_ETHAN_5] =
    {
#line 3562
        .trainerName = _("ETHAN"),
#line 3563
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 3564
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 3566
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 3567
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3569
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3571
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3570
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3573
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3575
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3574
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3577
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3579
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3578
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3581
    [TRAINER_BRENT] =
    {
#line 3582
        .trainerName = _("BRENT"),
#line 3583
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3584
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3586
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3587
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3589
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3591
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3590
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3593
    [TRAINER_DONALD] =
    {
#line 3594
        .trainerName = _("DONALD"),
#line 3595
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3596
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3598
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3599
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3601
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3603
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3602
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3605
            .species = SPECIES_SILCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3607
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3606
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3609
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3611
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3610
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3613
    [TRAINER_TAYLOR] =
    {
#line 3614
        .trainerName = _("TAYLOR"),
#line 3615
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3616
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3618
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3621
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3623
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3622
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3625
            .species = SPECIES_CASCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3627
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3626
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3629
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3631
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3630
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3633
    [TRAINER_JEFFREY_1] =
    {
#line 3634
        .trainerName = _("JEFFREY"),
#line 3635
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3636
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3638
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3639
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3641
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3643
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3642
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3645
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3647
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3646
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3649
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3651
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3650
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3653
    [TRAINER_DEREK] =
    {
#line 3654
        .trainerName = _("DEREK"),
#line 3655
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3656
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3658
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3659
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3661
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3663
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 3662
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3665
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3667
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 3666
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3669
    [TRAINER_JEFFREY_2] =
    {
#line 3670
        .trainerName = _("JEFFREY"),
#line 3671
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3672
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3674
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3675
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3677
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3679
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3678
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3681
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3683
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3682
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3685
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3687
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3686
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3689
    [TRAINER_JEFFREY_3] =
    {
#line 3690
        .trainerName = _("JEFFREY"),
#line 3691
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3692
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3694
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3695
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3697
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3699
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3698
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3701
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3703
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3702
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3705
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3707
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3706
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3709
    [TRAINER_JEFFREY_4] =
    {
#line 3710
        .trainerName = _("JEFFREY"),
#line 3711
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3712
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3714
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3715
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 3717
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3719
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3718
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3721
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3723
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3722
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3725
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3727
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3726
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3729
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3731
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3730
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3733
    [TRAINER_JEFFREY_5] =
    {
#line 3734
        .trainerName = _("JEFFREY"),
#line 3735
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 3736
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 3738
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 3739
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 3741
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3743
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3742
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3745
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3747
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3746
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3749
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3751
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3750
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3753
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3753
            .heldItem = ITEM_SILVER_POWDER,
#line 3755
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3754
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3757
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3759
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3758
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3761
    [TRAINER_EDWARD] =
    {
#line 3762
        .trainerName = _("EDWARD"),
#line 3763
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3764
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3766
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3767
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3769
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3771
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3770
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3772
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
#line 3774
    [TRAINER_PRESTON] =
    {
#line 3775
        .trainerName = _("PRESTON"),
#line 3776
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3777
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3779
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3780
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3782
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3784
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3783
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3786
    [TRAINER_VIRGIL] =
    {
#line 3787
        .trainerName = _("VIRGIL"),
#line 3788
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3789
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3791
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3792
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3794
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3796
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3795
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3798
    [TRAINER_BLAKE] =
    {
#line 3799
        .trainerName = _("BLAKE"),
#line 3800
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3801
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3803
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3804
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3806
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3808
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3807
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3810
    [TRAINER_WILLIAM] =
    {
#line 3811
        .trainerName = _("WILLIAM"),
#line 3812
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3813
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3815
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3816
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3818
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3820
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3819
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3822
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3824
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3823
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3826
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3828
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3827
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3830
    [TRAINER_JOSHUA] =
    {
#line 3831
        .trainerName = _("JOSHUA"),
#line 3832
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3833
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3835
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3836
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3838
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3840
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3839
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3842
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3844
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3843
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3846
    [TRAINER_CAMERON_1] =
    {
#line 3847
        .trainerName = _("CAMERON"),
#line 3848
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3849
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3851
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3852
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3854
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3856
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3855
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3858
    [TRAINER_CAMERON_2] =
    {
#line 3859
        .trainerName = _("CAMERON"),
#line 3860
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3861
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3863
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3866
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3868
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3867
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3870
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3872
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 3871
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3874
    [TRAINER_CAMERON_3] =
    {
#line 3875
        .trainerName = _("CAMERON"),
#line 3876
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3877
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3879
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3880
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3882
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3884
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3883
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3886
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3888
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 3887
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3890
    [TRAINER_CAMERON_4] =
    {
#line 3891
        .trainerName = _("CAMERON"),
#line 3892
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3893
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3895
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3896
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3898
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3900
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3899
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3902
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3904
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 3903
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3906
    [TRAINER_CAMERON_5] =
    {
#line 3907
        .trainerName = _("CAMERON"),
#line 3908
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3909
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 3911
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3912
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3914
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3916
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3915
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3918
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3920
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 3919
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3922
    [TRAINER_JACLYN] =
    {
#line 3923
        .trainerName = _("JACLYN"),
#line 3924
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3925
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3926
F_TRAINER_FEMALE | 
#line 3927
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3928
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3930
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3932
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3931
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 3933
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
#line 3935
    [TRAINER_HANNAH] =
    {
#line 3936
        .trainerName = _("HANNAH"),
#line 3937
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3938
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3939
F_TRAINER_FEMALE | 
#line 3940
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3941
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3943
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3945
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3944
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3947
    [TRAINER_SAMANTHA] =
    {
#line 3948
        .trainerName = _("SAMANTHA"),
#line 3949
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3950
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3951
F_TRAINER_FEMALE | 
#line 3952
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3953
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3955
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3957
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3956
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3959
    [TRAINER_MAURA] =
    {
#line 3960
        .trainerName = _("MAURA"),
#line 3961
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3962
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3963
F_TRAINER_FEMALE | 
#line 3964
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3965
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 3967
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3969
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 3968
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3971
    [TRAINER_KAYLA] =
    {
#line 3972
        .trainerName = _("KAYLA"),
#line 3973
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3974
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3975
F_TRAINER_FEMALE | 
#line 3976
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3977
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 3979
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3981
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3980
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3983
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3985
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3984
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 3987
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 3989
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 3988
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 3991
    [TRAINER_ALEXIS] =
    {
#line 3992
        .trainerName = _("ALEXIS"),
#line 3993
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 3994
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 3995
F_TRAINER_FEMALE | 
#line 3996
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 3997
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 3999
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4001
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4000
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4003
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4005
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4004
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4007
    [TRAINER_JACKI_1] =
    {
#line 4008
        .trainerName = _("JACKI"),
#line 4009
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4010
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4011
F_TRAINER_FEMALE | 
#line 4012
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4013
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4015
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4017
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4016
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4019
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4021
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4020
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4023
    [TRAINER_JACKI_2] =
    {
#line 4024
        .trainerName = _("JACKI"),
#line 4025
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4026
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4027
F_TRAINER_FEMALE | 
#line 4028
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4029
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4031
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4033
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4032
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4035
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4037
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4036
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4039
    [TRAINER_JACKI_3] =
    {
#line 4040
        .trainerName = _("JACKI"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4047
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4049
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4048
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4051
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4053
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4052
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4055
    [TRAINER_JACKI_4] =
    {
#line 4056
        .trainerName = _("JACKI"),
#line 4057
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4058
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4059
F_TRAINER_FEMALE | 
#line 4060
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4061
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4063
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4065
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4064
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4067
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4069
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4068
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4071
    [TRAINER_JACKI_5] =
    {
#line 4072
        .trainerName = _("JACKI"),
#line 4073
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 4074
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 4075
F_TRAINER_FEMALE | 
#line 4076
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 4077
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4079
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4081
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4080
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4083
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4085
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4084
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4087
    [TRAINER_WALTER_1] =
    {
#line 4088
        .trainerName = _("WALTER"),
#line 4089
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4090
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4092
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4093
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4095
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4097
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4096
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4099
    [TRAINER_MICAH] =
    {
#line 4100
        .trainerName = _("MICAH"),
#line 4101
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4102
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4104
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4105
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4107
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4109
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4108
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4111
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4113
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4112
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4115
    [TRAINER_THOMAS] =
    {
#line 4116
        .trainerName = _("THOMAS"),
#line 4117
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4118
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4120
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4121
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4123
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4125
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4124
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4127
    [TRAINER_WALTER_2] =
    {
#line 4128
        .trainerName = _("WALTER"),
#line 4129
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4130
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4132
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4133
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4135
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4137
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4136
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4139
    [TRAINER_WALTER_3] =
    {
#line 4140
        .trainerName = _("WALTER"),
#line 4141
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4142
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4144
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4145
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4147
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4149
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4148
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4150
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4155
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4157
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4156
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4158
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
#line 4163
    [TRAINER_WALTER_4] =
    {
#line 4164
        .trainerName = _("WALTER"),
#line 4165
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4166
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4168
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4169
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4171
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4173
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4172
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4174
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4179
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4181
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4180
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4182
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
#line 4186
    [TRAINER_WALTER_5] =
    {
#line 4187
        .trainerName = _("WALTER"),
#line 4188
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 4189
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 4191
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 4192
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4194
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4196
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4195
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4197
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
#line 4202
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4204
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4203
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4205
                MOVE_FURY_SWIPES,
                MOVE_DISABLE,
                MOVE_CONFUSION,
                MOVE_PSYCH_UP,
            },
            },
            {
#line 4210
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4212
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4211
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4213
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
#line 4218
    [TRAINER_SIDNEY] =
    {
#line 4219
        .trainerName = _("SIDNEY"),
#line 4220
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4221
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .encounterMusic_gender = 
#line 4223
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4224
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4225
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_FORCE_SETUP_FIRST_TURN,
#line 4226
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4228
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4230
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4229
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4231
                MOVE_ROAR,
                MOVE_DOUBLE_EDGE,
                MOVE_SAND_ATTACK,
                MOVE_CRUNCH,
            },
            },
            {
#line 4236
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4238
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4237
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4239
                MOVE_TORMENT,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
                MOVE_EXTRASENSORY,
            },
            },
            {
#line 4244
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4246
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4245
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4247
                MOVE_LEECH_SEED,
                MOVE_FEINT_ATTACK,
                MOVE_NEEDLE_ARM,
                MOVE_COTTON_SPORE,
            },
            },
            {
#line 4252
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4254
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4253
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4255
                MOVE_SURF,
                MOVE_SWORDS_DANCE,
                MOVE_STRENGTH,
                MOVE_FACADE,
            },
            },
            {
#line 4260
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4260
            .heldItem = ITEM_SITRUS_BERRY,
#line 4262
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4261
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4263
                MOVE_AERIAL_ACE,
                MOVE_ROCK_SLIDE,
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
#line 4268
    [TRAINER_PHOEBE] =
    {
#line 4269
        .trainerName = _("PHOEBE"),
#line 4270
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4271
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .encounterMusic_gender = 
#line 4272
F_TRAINER_FEMALE | 
#line 4273
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4274
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4275
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4276
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4278
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4280
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4279
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4281
                MOVE_SHADOW_PUNCH,
                MOVE_CONFUSE_RAY,
                MOVE_CURSE,
                MOVE_PROTECT,
            },
            },
            {
#line 4286
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4288
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4287
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4289
                MOVE_SHADOW_BALL,
                MOVE_GRUDGE,
                MOVE_WILL_O_WISP,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4294
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4296
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4295
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4297
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_TEAM,
                MOVE_NIGHT_SHADE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4302
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4304
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4303
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4305
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_FACADE,
            },
            },
            {
#line 4310
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4310
            .heldItem = ITEM_SITRUS_BERRY,
#line 4312
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4311
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4313
                MOVE_SHADOW_BALL,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 4318
    [TRAINER_GLACIA] =
    {
#line 4319
        .trainerName = _("GLACIA"),
#line 4320
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4321
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .encounterMusic_gender = 
#line 4322
F_TRAINER_FEMALE | 
#line 4323
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4324
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4325
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4326
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4328
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4330
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4329
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4331
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_HAIL,
                MOVE_ICE_BALL,
            },
            },
            {
#line 4336
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4338
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4337
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4339
                MOVE_LIGHT_SCREEN,
                MOVE_CRUNCH,
                MOVE_VIENTO_HELADO,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 4344
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4346
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4345
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4347
                MOVE_ATTRACT,
                MOVE_DOUBLE_EDGE,
                MOVE_HAIL,
                MOVE_VENTISCA,
            },
            },
            {
#line 4352
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4354
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4353
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4355
                MOVE_SHADOW_BALL,
                MOVE_EXPLOSION,
                MOVE_HAIL,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 4360
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4360
            .heldItem = ITEM_SITRUS_BERRY,
#line 4362
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4361
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4363
                MOVE_SURF,
                MOVE_BODY_SLAM,
                MOVE_ICE_BEAM,
                MOVE_SHEER_COLD,
            },
            },
        },
    },
#line 4368
    [TRAINER_DRAKE] =
    {
#line 4369
        .trainerName = _("DRAKE"),
#line 4370
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
#line 4371
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .encounterMusic_gender = 
#line 4373
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
#line 4374
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 4375
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 4376
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4378
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4380
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4379
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4381
                MOVE_ROCK_TOMB,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
                MOVE_DOUBLE_EDGE,
            },
            },
            {
#line 4386
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4388
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4387
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4389
                MOVE_DOUBLE_EDGE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4394
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4396
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4395
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4397
                MOVE_SMOKESCREEN,
                MOVE_DRAGON_DANCE,
                MOVE_SURF,
                MOVE_BODY_SLAM,
            },
            },
            {
#line 4402
            .species = SPECIES_FLYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4404
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4403
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4405
                MOVE_LANZALLAMAS,
                MOVE_CRUNCH,
                MOVE_DRAGON_BREATH,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 4410
            .species = SPECIES_SALAMENCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4410
            .heldItem = ITEM_SITRUS_BERRY,
#line 4412
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4411
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4413
                MOVE_LANZALLAMAS,
                MOVE_DRAGON_CLAW,
                MOVE_ROCK_SLIDE,
                MOVE_CRUNCH,
            },
            },
        },
    },
#line 4418
    [TRAINER_ROXANNE_1] =
    {
#line 4419
        .trainerName = _("ROXANNE"),
#line 4420
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4421
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 4422
F_TRAINER_FEMALE | 
#line 4423
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4424
        .items = { ITEM_POTION, ITEM_POTION },
#line 4425
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4427
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4429
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4428
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4430
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 4435
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4437
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4436
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4438
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
#line 4443
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4443
            .heldItem = ITEM_ORAN_BERRY,
#line 4445
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4444
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4446
                MOVE_BLOCK,
                MOVE_HARDEN,
                MOVE_TACKLE,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 4451
    [TRAINER_BRAWLY_1] =
    {
#line 4452
        .trainerName = _("BRAWLY"),
#line 4453
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4454
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 4456
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4457
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 4458
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4460
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4462
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4461
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4463
                MOVE_GOLPE_KARATE,
                MOVE_LOW_KICK,
                MOVE_SEISMIC_TOSS,
                MOVE_BULK_UP,
            },
            },
            {
#line 4468
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4470
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 4469
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4471
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_BULK_UP,
            },
            },
            {
#line 4476
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4476
            .heldItem = ITEM_SITRUS_BERRY,
#line 4478
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4477
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4479
                MOVE_ARM_THRUST,
                MOVE_VITAL_THROW,
                MOVE_REVERSAL,
                MOVE_BULK_UP,
            },
            },
        },
    },
#line 4484
    [TRAINER_WATTSON_1] =
    {
#line 4485
        .trainerName = _("WATTSON"),
#line 4486
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4487
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 4489
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4490
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 4491
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4493
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4495
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4494
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4496
                MOVE_ROLLOUT,
                MOVE_SPARK,
                MOVE_SELF_DESTRUCT,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 4501
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4503
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4502
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4504
                MOVE_SHOCK_WAVE,
                MOVE_LEER,
                MOVE_QUICK_ATTACK,
                MOVE_HOWL,
            },
            },
            {
#line 4509
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4511
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 4510
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4512
                MOVE_SUPERSONIC,
                MOVE_SHOCK_WAVE,
                MOVE_THUNDER_WAVE,
                MOVE_BOMBA_SONICA,
            },
            },
            {
#line 4517
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4517
            .heldItem = ITEM_SITRUS_BERRY,
#line 4519
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4518
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4520
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SHOCK_WAVE,
                MOVE_HOWL,
            },
            },
        },
    },
#line 4525
    [TRAINER_FLANNERY_1] =
    {
#line 4526
        .trainerName = _("FLANNERY"),
#line 4527
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4528
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 4529
F_TRAINER_FEMALE | 
#line 4530
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4531
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4532
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4534
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4536
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4535
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4537
                MOVE_OVERHEAT,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 4542
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4544
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4543
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4545
                MOVE_OVERHEAT,
                MOVE_SMOG,
                MOVE_LIGHT_SCREEN,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 4550
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4552
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4551
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4553
                MOVE_OVERHEAT,
                MOVE_TACKLE,
                MOVE_DIA_SOLEADO,
                MOVE_ATTRACT,
            },
            },
            {
#line 4558
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4558
            .heldItem = ITEM_WHITE_HERB,
#line 4560
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4559
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4561
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_BODY_SLAM,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 4566
    [TRAINER_NORMAN_1] =
    {
#line 4567
        .trainerName = _("NORMAN"),
#line 4568
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4569
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 4571
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4572
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4573
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4575
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4577
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4576
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4578
                MOVE_TEETER_DANCE,
                MOVE_PSYBEAM,
                MOVE_FACADE,
                MOVE_ENCORE,
            },
            },
            {
#line 4583
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4585
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4584
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4586
                MOVE_SLASH,
                MOVE_FACADE,
                MOVE_ENCORE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 4591
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4593
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4592
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4594
                MOVE_SLASH,
                MOVE_BELLY_DRUM,
                MOVE_FACADE,
                MOVE_HEADBUTT,
            },
            },
            {
#line 4599
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4599
            .heldItem = ITEM_SITRUS_BERRY,
#line 4601
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4600
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4602
                MOVE_COUNTER,
                MOVE_YAWN,
                MOVE_FACADE,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
#line 4607
    [TRAINER_WINONA_1] =
    {
#line 4608
        .trainerName = _("WINONA"),
#line 4609
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4610
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 4611
F_TRAINER_FEMALE | 
#line 4612
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4613
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4614
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4616
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4618
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4617
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4619
                MOVE_PERISH_SONG,
                MOVE_MIRROR_MOVE,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4624
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4626
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4625
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4627
                MOVE_DIA_SOLEADO,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
#line 4632
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4634
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 4633
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4635
                MOVE_WATER_GUN,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4640
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4642
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 4641
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4643
                MOVE_SAND_ATTACK,
                MOVE_FURY_ATTACK,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 4648
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4648
            .heldItem = ITEM_ORAN_BERRY,
#line 4650
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 4649
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4651
                MOVE_EARTHQUAKE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
        },
    },
#line 4656
    [TRAINER_TATE_AND_LIZA_1] =
    {
#line 4657
        .trainerName = _("TATE&LIZA"),
#line 4658
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4659
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 4661
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 4662
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4663
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 4665
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4667
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4666
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4668
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 4673
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4675
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4674
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4676
                MOVE_PSYCHIC,
                MOVE_DIA_SOLEADO,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 4681
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4681
            .heldItem = ITEM_SITRUS_BERRY,
#line 4683
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4682
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4684
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_CALM_MIND,
            },
            },
            {
#line 4689
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4689
            .heldItem = ITEM_SITRUS_BERRY,
#line 4691
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4690
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4692
                MOVE_DIA_SOLEADO,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_LANZALLAMAS,
            },
            },
        },
    },
#line 4697
    [TRAINER_JUAN_1] =
    {
#line 4698
        .trainerName = _("JUAN"),
#line 4699
        .trainerClass = TRAINER_CLASS_LEADER,
#line 4700
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 4702
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4703
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
#line 4704
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 4706
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4708
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4707
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4709
                MOVE_WATER_PULSE,
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
            },
            },
            {
#line 4714
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4716
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4715
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4717
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
                MOVE_AMNESIA,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 4722
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4724
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4723
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4725
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_AURORA_BEAM,
                MOVE_WATER_PULSE,
            },
            },
            {
#line 4730
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4732
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 4731
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4733
                MOVE_WATER_PULSE,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_LEER,
            },
            },
            {
#line 4738
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4738
            .heldItem = ITEM_CHESTO_BERRY,
#line 4740
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 4739
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4741
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 4746
    [TRAINER_JERRY_1] =
    {
#line 4747
        .trainerName = _("JERRY"),
#line 4748
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4749
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4751
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4752
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4754
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4756
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4755
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4758
    [TRAINER_TED] =
    {
#line 4759
        .trainerName = _("TED"),
#line 4760
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4761
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4763
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4764
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4766
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4768
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4767
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4770
    [TRAINER_PAUL] =
    {
#line 4771
        .trainerName = _("PAUL"),
#line 4772
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4773
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4775
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4776
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4778
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4780
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4779
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4782
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4784
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4783
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4786
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4788
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4787
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4790
    [TRAINER_JERRY_2] =
    {
#line 4791
        .trainerName = _("JERRY"),
#line 4792
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4793
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4795
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4796
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4798
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4800
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4799
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4802
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4804
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4803
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4806
    [TRAINER_JERRY_3] =
    {
#line 4807
        .trainerName = _("JERRY"),
#line 4808
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4809
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4811
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4812
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4814
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4816
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4815
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4818
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4820
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4819
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4822
    [TRAINER_JERRY_4] =
    {
#line 4823
        .trainerName = _("JERRY"),
#line 4824
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4825
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4827
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4828
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4830
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4832
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4831
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4834
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4836
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4835
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4838
    [TRAINER_JERRY_5] =
    {
#line 4839
        .trainerName = _("JERRY"),
#line 4840
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4841
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender = 
#line 4843
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 4844
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 4846
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4848
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4847
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4850
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4852
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4851
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4854
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4856
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4855
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4858
    [TRAINER_KAREN_1] =
    {
#line 4859
        .trainerName = _("KAREN"),
#line 4860
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4861
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4862
F_TRAINER_FEMALE | 
#line 4863
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 4866
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4868
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4867
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4870
    [TRAINER_GEORGIA] =
    {
#line 4871
        .trainerName = _("GEORGIA"),
#line 4872
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4873
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4874
F_TRAINER_FEMALE | 
#line 4875
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4876
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4878
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4880
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4879
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4882
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4884
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 4883
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4886
    [TRAINER_KAREN_2] =
    {
#line 4887
        .trainerName = _("KAREN"),
#line 4888
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4889
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4890
F_TRAINER_FEMALE | 
#line 4891
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4892
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4894
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4896
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4895
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4898
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4900
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 4899
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4902
    [TRAINER_KAREN_3] =
    {
#line 4903
        .trainerName = _("KAREN"),
#line 4904
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4905
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4906
F_TRAINER_FEMALE | 
#line 4907
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4908
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4910
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4912
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4911
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4914
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4916
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 4915
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4918
    [TRAINER_KAREN_4] =
    {
#line 4919
        .trainerName = _("KAREN"),
#line 4920
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4921
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4922
F_TRAINER_FEMALE | 
#line 4923
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4926
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4928
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4927
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4930
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4932
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 4931
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4934
    [TRAINER_KAREN_5] =
    {
#line 4935
        .trainerName = _("KAREN"),
#line 4936
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
#line 4937
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender = 
#line 4938
F_TRAINER_FEMALE | 
#line 4939
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 4940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4942
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4944
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4943
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 4946
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4948
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 4947
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 4950
    [TRAINER_KATE_AND_JOY] =
    {
#line 4951
        .trainerName = _("KATE & JOY"),
#line 4952
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 4953
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 4955
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 4956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 4958
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4959
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4961
                MOVE_HYPNOSIS,
                MOVE_PSYBEAM,
                MOVE_DIZZY_PUNCH,
                MOVE_TEETER_DANCE,
            },
            },
            {
#line 4966
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4968
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4967
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4969
                MOVE_FOCUS_PUNCH,
                MOVE_YAWN,
                MOVE_SLACK_OFF,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
#line 4974
    [TRAINER_ANNA_AND_MEG_1] =
    {
#line 4975
        .trainerName = _("ANNA & MEG"),
#line 4976
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 4977
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 4979
            TRAINER_ENCOUNTER_MUSIC_TWINS,
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
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4983
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4985
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 4990
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 4992
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 4991
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 4993
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 4997
    [TRAINER_ANNA_AND_MEG_2] =
    {
#line 4998
        .trainerName = _("ANNA & MEG"),
#line 4999
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5000
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5002
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5003
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5005
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5007
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5006
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5008
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5013
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5015
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5014
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5016
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5020
    [TRAINER_ANNA_AND_MEG_3] =
    {
#line 5021
        .trainerName = _("ANNA & MEG"),
#line 5022
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5023
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5025
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5026
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5028
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5030
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5029
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5031
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5036
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5038
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5037
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5039
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5043
    [TRAINER_ANNA_AND_MEG_4] =
    {
#line 5044
        .trainerName = _("ANNA & MEG"),
#line 5045
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5046
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5048
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5049
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5051
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5053
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5052
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5054
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5059
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5061
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5060
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5062
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5066
    [TRAINER_ANNA_AND_MEG_5] =
    {
#line 5067
        .trainerName = _("ANNA & MEG"),
#line 5068
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 5069
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 5071
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5072
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5074
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5076
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5075
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5077
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
#line 5082
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5084
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5083
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5085
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
#line 5089
    [TRAINER_VICTOR] =
    {
#line 5090
        .trainerName = _("VICTOR"),
#line 5091
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5092
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5094
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5095
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5097
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5097
            .heldItem = ITEM_ORAN_BERRY,
#line 5099
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5098
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5101
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5101
            .heldItem = ITEM_ORAN_BERRY,
#line 5103
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5102
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5105
    [TRAINER_MIGUEL_1] =
    {
#line 5106
        .trainerName = _("MIGUEL"),
#line 5107
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5108
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5110
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5111
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5113
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5113
            .heldItem = ITEM_ORAN_BERRY,
#line 5115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5114
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5117
    [TRAINER_COLTON] =
    {
#line 5118
        .trainerName = _("COLTON"),
#line 5119
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5120
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5122
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 5125
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5125
            .heldItem = ITEM_ORAN_BERRY,
#line 5127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5126
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5128
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5133
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5133
            .heldItem = ITEM_ORAN_BERRY,
#line 5135
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5134
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5136
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5141
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5141
            .heldItem = ITEM_ORAN_BERRY,
#line 5143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5142
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5144
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5149
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5149
            .heldItem = ITEM_ORAN_BERRY,
#line 5151
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5150
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5152
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5157
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5157
            .heldItem = ITEM_ORAN_BERRY,
#line 5159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5158
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5160
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
#line 5165
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5165
            .heldItem = ITEM_ORAN_BERRY,
#line 5167
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5166
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5168
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
        },
    },
#line 5173
    [TRAINER_MIGUEL_2] =
    {
#line 5174
        .trainerName = _("MIGUEL"),
#line 5175
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5176
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5178
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5179
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5181
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5181
            .heldItem = ITEM_ORAN_BERRY,
#line 5183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5182
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5185
    [TRAINER_MIGUEL_3] =
    {
#line 5186
        .trainerName = _("MIGUEL"),
#line 5187
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5188
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5190
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5191
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5193
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5193
            .heldItem = ITEM_ORAN_BERRY,
#line 5195
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5194
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5197
    [TRAINER_MIGUEL_4] =
    {
#line 5198
        .trainerName = _("MIGUEL"),
#line 5199
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5200
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 5202
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5205
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5205
            .heldItem = ITEM_ORAN_BERRY,
#line 5207
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5206
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5209
    [TRAINER_MIGUEL_5] =
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
            .heldItem = ITEM_SITRUS_BERRY,
#line 5219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5218
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5221
    [TRAINER_VICTORIA] =
    {
#line 5222
        .trainerName = _("VICTORIA"),
#line 5223
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5224
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5225
F_TRAINER_FEMALE | 
#line 5226
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5227
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5229
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5229
            .heldItem = ITEM_ORAN_BERRY,
#line 5231
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 5230
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5233
    [TRAINER_VANESSA] =
    {
#line 5234
        .trainerName = _("VANESSA"),
#line 5235
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5236
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5237
F_TRAINER_FEMALE | 
#line 5238
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5239
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5241
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5241
            .heldItem = ITEM_ORAN_BERRY,
#line 5243
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5242
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5245
    [TRAINER_BETHANY] =
    {
#line 5246
        .trainerName = _("BETHANY"),
#line 5247
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5248
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5249
F_TRAINER_FEMALE | 
#line 5250
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5251
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5253
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5253
            .heldItem = ITEM_ORAN_BERRY,
#line 5255
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5254
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5257
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5257
            .heldItem = ITEM_ORAN_BERRY,
#line 5259
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5258
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5261
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5261
            .heldItem = ITEM_ORAN_BERRY,
#line 5263
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5262
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5265
    [TRAINER_ISABEL_1] =
    {
#line 5266
        .trainerName = _("ISABEL"),
#line 5267
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5268
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5269
F_TRAINER_FEMALE | 
#line 5270
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5271
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5273
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5273
            .heldItem = ITEM_ORAN_BERRY,
#line 5275
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5274
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5277
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5277
            .heldItem = ITEM_ORAN_BERRY,
#line 5279
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5278
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5281
    [TRAINER_ISABEL_2] =
    {
#line 5282
        .trainerName = _("ISABEL"),
#line 5283
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5284
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5285
F_TRAINER_FEMALE | 
#line 5286
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5287
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5289
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5289
            .heldItem = ITEM_ORAN_BERRY,
#line 5291
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5290
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5293
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5293
            .heldItem = ITEM_ORAN_BERRY,
#line 5295
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5294
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5297
    [TRAINER_ISABEL_3] =
    {
#line 5298
        .trainerName = _("ISABEL"),
#line 5299
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5300
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5301
F_TRAINER_FEMALE | 
#line 5302
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5303
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5305
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5305
            .heldItem = ITEM_ORAN_BERRY,
#line 5307
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5306
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5309
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5309
            .heldItem = ITEM_ORAN_BERRY,
#line 5311
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5310
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5313
    [TRAINER_ISABEL_4] =
    {
#line 5314
        .trainerName = _("ISABEL"),
#line 5315
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5316
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5317
F_TRAINER_FEMALE | 
#line 5318
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5321
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5321
            .heldItem = ITEM_ORAN_BERRY,
#line 5323
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5322
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5325
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5325
            .heldItem = ITEM_ORAN_BERRY,
#line 5327
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5326
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5329
    [TRAINER_ISABEL_5] =
    {
#line 5330
        .trainerName = _("ISABEL"),
#line 5331
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 5332
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 5333
F_TRAINER_FEMALE | 
#line 5334
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 5335
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5337
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5337
            .heldItem = ITEM_SITRUS_BERRY,
#line 5339
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5338
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5341
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5341
            .heldItem = ITEM_SITRUS_BERRY,
#line 5343
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5342
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5345
    [TRAINER_TIMOTHY_1] =
    {
#line 5346
        .trainerName = _("TIMOTHY"),
#line 5347
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5348
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5350
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5351
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5353
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5355
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5354
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5357
    [TRAINER_TIMOTHY_2] =
    {
#line 5358
        .trainerName = _("TIMOTHY"),
#line 5359
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5360
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5362
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5363
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5365
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5367
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5366
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5368
                MOVE_ARM_THRUST,
                MOVE_DESARME,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5373
    [TRAINER_TIMOTHY_3] =
    {
#line 5374
        .trainerName = _("TIMOTHY"),
#line 5375
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5376
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5378
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5379
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5381
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5383
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5382
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5384
                MOVE_ARM_THRUST,
                MOVE_DESARME,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5389
    [TRAINER_TIMOTHY_4] =
    {
#line 5390
        .trainerName = _("TIMOTHY"),
#line 5391
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5392
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5394
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5395
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5397
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5399
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5398
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5400
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5405
    [TRAINER_TIMOTHY_5] =
    {
#line 5406
        .trainerName = _("TIMOTHY"),
#line 5407
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5408
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 5410
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5411
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5413
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5415
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5414
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5416
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
#line 5421
    [TRAINER_VICKY] =
    {
#line 5422
        .trainerName = _("VICKY"),
#line 5423
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 5424
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5425
F_TRAINER_FEMALE | 
#line 5426
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5427
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5429
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5431
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5430
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5432
                MOVE_PATADA_VOLADORA,
                MOVE_MEDITATE,
                MOVE_CONFUSION,
                MOVE_DETECT,
            },
            },
        },
    },
#line 5437
    [TRAINER_SHELBY_1] =
    {
#line 5438
        .trainerName = _("SHELBY"),
#line 5439
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5440
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5441
F_TRAINER_FEMALE | 
#line 5442
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5443
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5445
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5447
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5446
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5449
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5451
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 5450
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5453
    [TRAINER_SHELBY_2] =
    {
#line 5454
        .trainerName = _("SHELBY"),
#line 5455
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5456
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5457
F_TRAINER_FEMALE | 
#line 5458
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5459
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5461
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5463
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5462
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5465
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5467
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 5466
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5469
    [TRAINER_SHELBY_3] =
    {
#line 5470
        .trainerName = _("SHELBY"),
#line 5471
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5472
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5473
F_TRAINER_FEMALE | 
#line 5474
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5475
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5477
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5479
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5478
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5481
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5483
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 5482
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5485
    [TRAINER_SHELBY_4] =
    {
#line 5486
        .trainerName = _("SHELBY"),
#line 5487
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5488
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5489
F_TRAINER_FEMALE | 
#line 5490
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5491
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5493
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5495
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5494
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5497
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5499
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 5498
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5501
    [TRAINER_SHELBY_5] =
    {
#line 5502
        .trainerName = _("SHELBY"),
#line 5503
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 5504
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 5505
F_TRAINER_FEMALE | 
#line 5506
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 5507
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5509
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5511
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5510
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5513
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5515
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 5514
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5517
    [TRAINER_CALVIN_1] =
    {
#line 5518
        .trainerName = _("CALVIN"),
#line 5519
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5520
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5522
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5525
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5527
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5526
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5529
    [TRAINER_BILLY] =
    {
#line 5530
        .trainerName = _("BILLY"),
#line 5531
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5532
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5534
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5535
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5537
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5539
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5538
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5541
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5543
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5542
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5545
    [TRAINER_JOSH] =
    {
#line 5546
        .trainerName = _("JOSH"),
#line 5547
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5548
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5550
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5553
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5555
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5554
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5556
                MOVE_TACKLE,
            },
            },
        },
    },
#line 5558
    [TRAINER_TOMMY] =
    {
#line 5559
        .trainerName = _("TOMMY"),
#line 5560
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5561
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5563
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5564
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5566
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5568
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 5567
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5570
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5572
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 5571
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5574
    [TRAINER_JOEY] =
    {
#line 5575
        .trainerName = _("JOEY"),
#line 5576
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5577
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5579
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5582
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5583
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5586
    [TRAINER_BEN] =
    {
#line 5587
        .trainerName = _("BEN"),
#line 5588
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5589
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5591
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5594
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5596
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 5595
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5597
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_GROWL,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 5602
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5604
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 5603
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5605
                MOVE_AMNESIA,
                MOVE_SLUDGE,
                MOVE_YAWN,
                MOVE_POUND,
            },
            },
        },
    },
#line 5610
    [TRAINER_QUINCY] =
    {
#line 5611
        .trainerName = _("QUINCY"),
#line 5612
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5613
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 5615
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5616
        .items = { ITEM_FULL_RESTORE },
#line 5617
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5619
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5621
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5620
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5622
                MOVE_ATTRACT,
                MOVE_ICE_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_LANZALLAMAS,
            },
            },
            {
#line 5627
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5629
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5628
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5630
                MOVE_SKILL_SWAP,
                MOVE_PROTECT,
                MOVE_WILL_O_WISP,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 5635
    [TRAINER_KATELYNN] =
    {
#line 5636
        .trainerName = _("KATELYNN"),
#line 5637
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 5638
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 5639
F_TRAINER_FEMALE | 
#line 5640
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 5641
        .items = { ITEM_FULL_RESTORE },
#line 5642
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5644
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5646
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5645
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5647
                MOVE_SKILL_SWAP,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_CALM_MIND,
            },
            },
            {
#line 5652
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5654
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 5653
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5655
                MOVE_EARTHQUAKE,
                MOVE_SHADOW_BALL,
                MOVE_AERIAL_ACE,
                MOVE_BRICK_BREAK,
            },
            },
        },
    },
#line 5660
    [TRAINER_JAYLEN] =
    {
#line 5661
        .trainerName = _("JAYLEN"),
#line 5662
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5663
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5665
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5666
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5668
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5670
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5669
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5672
    [TRAINER_DILLON] =
    {
#line 5673
        .trainerName = _("DILLON"),
#line 5674
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5675
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5677
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5678
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5680
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5682
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5681
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5684
    [TRAINER_CALVIN_2] =
    {
#line 5685
        .trainerName = _("CALVIN"),
#line 5686
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5687
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5689
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5690
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5692
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5694
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5693
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5696
    [TRAINER_CALVIN_3] =
    {
#line 5697
        .trainerName = _("CALVIN"),
#line 5698
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5699
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5701
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5702
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5704
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5706
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5705
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5708
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5710
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 5709
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5712
    [TRAINER_CALVIN_4] =
    {
#line 5713
        .trainerName = _("CALVIN"),
#line 5714
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5715
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5717
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5718
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5720
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5722
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5721
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5724
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5726
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5725
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5728
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5730
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 5729
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5732
    [TRAINER_CALVIN_5] =
    {
#line 5733
        .trainerName = _("CALVIN"),
#line 5734
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5735
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5737
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5738
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5740
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5742
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5741
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5744
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5746
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5745
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5748
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5750
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 5749
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5752
    [TRAINER_EDDIE] =
    {
#line 5753
        .trainerName = _("EDDIE"),
#line 5754
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5755
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5757
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5758
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5760
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5762
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5761
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5764
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5766
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5765
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5768
    [TRAINER_ALLEN] =
    {
#line 5769
        .trainerName = _("ALLEN"),
#line 5770
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5771
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5773
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5774
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5776
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5777
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5780
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5782
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5781
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5784
    [TRAINER_TIMMY] =
    {
#line 5785
        .trainerName = _("TIMMY"),
#line 5786
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 5787
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 5789
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5790
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5792
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5794
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5793
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5796
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5798
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5797
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5800
    [TRAINER_WALLACE] =
    {
#line 5801
        .trainerName = _("WALLACE"),
#line 5802
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 5803
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .encounterMusic_gender = 
#line 5805
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 5806
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 5807
        .aiFlags = AI_FLAG_BASIC_TRAINER,
#line 5808
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 5810
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5812
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5811
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5813
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_SPOUT,
                MOVE_DOUBLE_EDGE,
                MOVE_VENTISCA,
            },
            },
            {
#line 5818
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5820
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5819
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5821
                MOVE_TOXIC,
                MOVE_HYDRO_PUMP,
                MOVE_SLUDGE_BOMB,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 5826
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5828
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5827
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5829
                MOVE_GIGA_DRAIN,
                MOVE_SURF,
                MOVE_LEECH_SEED,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 5834
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5836
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5835
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5837
                MOVE_EARTHQUAKE,
                MOVE_SURF,
                MOVE_AMNESIA,
                MOVE_HYPER_BEAM,
            },
            },
            {
#line 5842
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5844
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5843
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5845
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
                MOVE_SURF,
            },
            },
            {
#line 5850
            .species = SPECIES_MILOTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5850
            .heldItem = ITEM_SITRUS_BERRY,
#line 5852
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 5851
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 5853
                MOVE_RECOVER,
                MOVE_SURF,
                MOVE_ICE_BEAM,
                MOVE_TOXIC,
            },
            },
        },
    },
#line 5858
    [TRAINER_ANDREW] =
    {
#line 5859
        .trainerName = _("ANDREW"),
#line 5860
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5861
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5863
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5864
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5866
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5868
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5867
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5870
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5872
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5871
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5874
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5875
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5878
    [TRAINER_IVAN] =
    {
#line 5879
        .trainerName = _("IVAN"),
#line 5880
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5881
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5883
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5884
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5886
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5888
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5887
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5890
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5892
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5891
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5894
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5896
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5895
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5898
    [TRAINER_CLAUDE] =
    {
#line 5899
        .trainerName = _("CLAUDE"),
#line 5900
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5901
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5903
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5904
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5906
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5907
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5910
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5912
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5911
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5914
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5916
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5915
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5918
    [TRAINER_ELLIOT_1] =
    {
#line 5919
        .trainerName = _("ELLIOT"),
#line 5920
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5921
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5923
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5924
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 5926
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5928
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5927
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5930
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5932
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5931
            .lvl = 7,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5934
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5935
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5938
    [TRAINER_NED] =
    {
#line 5939
        .trainerName = _("NED"),
#line 5940
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5941
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5943
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5944
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5946
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5948
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 5947
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5950
    [TRAINER_DALE] =
    {
#line 5951
        .trainerName = _("DALE"),
#line 5952
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5953
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5955
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5956
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 5958
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5959
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5962
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5964
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5963
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5966
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5968
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5967
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5970
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5972
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5971
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5974
    [TRAINER_NOLAN] =
    {
#line 5975
        .trainerName = _("NOLAN"),
#line 5976
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5977
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5979
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5980
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 5982
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5984
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5983
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 5986
    [TRAINER_BARNY] =
    {
#line 5987
        .trainerName = _("BARNY"),
#line 5988
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 5989
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 5991
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 5992
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 5994
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 5996
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5995
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 5998
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6000
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 5999
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6002
    [TRAINER_WADE] =
    {
#line 6003
        .trainerName = _("WADE"),
#line 6004
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6005
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6007
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6008
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6010
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6012
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6011
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6014
    [TRAINER_CARTER] =
    {
#line 6015
        .trainerName = _("CARTER"),
#line 6016
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6017
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6019
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6020
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6022
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6024
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6023
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6026
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6028
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6027
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6030
    [TRAINER_ELLIOT_2] =
    {
#line 6031
        .trainerName = _("ELLIOT"),
#line 6032
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6033
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6035
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6036
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6038
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6040
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6039
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6042
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6044
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6043
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6046
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6048
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6047
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6050
    [TRAINER_ELLIOT_3] =
    {
#line 6051
        .trainerName = _("ELLIOT"),
#line 6052
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6053
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6055
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6056
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6058
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6060
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6059
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6062
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6064
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6063
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6066
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6068
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6067
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6070
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6072
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6071
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6074
    [TRAINER_ELLIOT_4] =
    {
#line 6075
        .trainerName = _("ELLIOT"),
#line 6076
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6077
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6079
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6080
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6082
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6084
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6083
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6086
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6088
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6087
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6090
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6092
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6091
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6094
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6096
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6095
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6098
    [TRAINER_ELLIOT_5] =
    {
#line 6099
        .trainerName = _("ELLIOT"),
#line 6100
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6101
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6103
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6104
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 6106
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6108
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6107
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6110
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6112
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6111
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6114
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6116
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6115
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6118
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6120
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6119
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6122
    [TRAINER_RONALD] =
    {
#line 6123
        .trainerName = _("RONALD"),
#line 6124
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 6125
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 6127
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 6128
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 6130
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6132
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6131
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6134
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6136
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6135
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6138
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6140
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6139
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6142
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6144
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6143
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6146
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6148
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6147
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6150
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6152
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6151
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6154
    [TRAINER_JACOB] =
    {
#line 6155
        .trainerName = _("JACOB"),
#line 6156
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6157
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6159
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6160
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6162
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6164
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6163
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6166
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6168
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6167
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6170
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6172
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 6171
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6174
    [TRAINER_ANTHONY] =
    {
#line 6175
        .trainerName = _("ANTHONY"),
#line 6176
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6177
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6179
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6180
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6182
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6184
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6183
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6186
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6188
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6187
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6190
    [TRAINER_BENJAMIN_1] =
    {
#line 6191
        .trainerName = _("BENJAMIN"),
#line 6192
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6193
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6195
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6196
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6198
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6200
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6199
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6202
    [TRAINER_BENJAMIN_2] =
    {
#line 6203
        .trainerName = _("BENJAMIN"),
#line 6204
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6205
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6207
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6208
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6210
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6212
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6211
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6214
    [TRAINER_BENJAMIN_3] =
    {
#line 6215
        .trainerName = _("BENJAMIN"),
#line 6216
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6217
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6219
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6220
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6222
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6224
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6223
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6226
    [TRAINER_BENJAMIN_4] =
    {
#line 6227
        .trainerName = _("BENJAMIN"),
#line 6228
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6229
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6231
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6232
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6234
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6236
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6235
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6238
    [TRAINER_BENJAMIN_5] =
    {
#line 6239
        .trainerName = _("BENJAMIN"),
#line 6240
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6241
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6243
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6244
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6246
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6248
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6247
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6250
    [TRAINER_ABIGAIL_1] =
    {
#line 6251
        .trainerName = _("ABIGAIL"),
#line 6252
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6253
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6254
F_TRAINER_FEMALE | 
#line 6255
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6256
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6258
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6260
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6259
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6262
    [TRAINER_JASMINE] =
    {
#line 6263
        .trainerName = _("JASMINE"),
#line 6264
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6265
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6266
F_TRAINER_FEMALE | 
#line 6267
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6268
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6270
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6272
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6271
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6274
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6276
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6275
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6278
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6280
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6279
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6282
    [TRAINER_ABIGAIL_2] =
    {
#line 6283
        .trainerName = _("ABIGAIL"),
#line 6284
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6285
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6286
F_TRAINER_FEMALE | 
#line 6287
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6288
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6290
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6292
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6291
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6294
    [TRAINER_ABIGAIL_3] =
    {
#line 6295
        .trainerName = _("ABIGAIL"),
#line 6296
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6297
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6298
F_TRAINER_FEMALE | 
#line 6299
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
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
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6303
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6306
    [TRAINER_ABIGAIL_4] =
    {
#line 6307
        .trainerName = _("ABIGAIL"),
#line 6308
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6309
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6310
F_TRAINER_FEMALE | 
#line 6311
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6312
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6314
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6316
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6315
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6318
    [TRAINER_ABIGAIL_5] =
    {
#line 6319
        .trainerName = _("ABIGAIL"),
#line 6320
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6321
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6322
F_TRAINER_FEMALE | 
#line 6323
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6324
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6326
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6328
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6327
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6330
    [TRAINER_DYLAN_1] =
    {
#line 6331
        .trainerName = _("DYLAN"),
#line 6332
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6333
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
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
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6340
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6339
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6342
    [TRAINER_DYLAN_2] =
    {
#line 6343
        .trainerName = _("DYLAN"),
#line 6344
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6345
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
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
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6352
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6351
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6354
    [TRAINER_DYLAN_3] =
    {
#line 6355
        .trainerName = _("DYLAN"),
#line 6356
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6357
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6359
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6362
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6364
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6363
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6366
    [TRAINER_DYLAN_4] =
    {
#line 6367
        .trainerName = _("DYLAN"),
#line 6368
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6369
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6371
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6372
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6374
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6376
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6375
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6378
    [TRAINER_DYLAN_5] =
    {
#line 6379
        .trainerName = _("DYLAN"),
#line 6380
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6381
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6383
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6384
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6386
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6388
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6387
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6390
    [TRAINER_MARIA_1] =
    {
#line 6391
        .trainerName = _("MARIA"),
#line 6392
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6393
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6394
F_TRAINER_FEMALE | 
#line 6395
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6396
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6398
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6400
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6399
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6402
    [TRAINER_MARIA_2] =
    {
#line 6403
        .trainerName = _("MARIA"),
#line 6404
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6405
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6406
F_TRAINER_FEMALE | 
#line 6407
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6408
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6410
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6412
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6411
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6414
    [TRAINER_MARIA_3] =
    {
#line 6415
        .trainerName = _("MARIA"),
#line 6416
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6417
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6418
F_TRAINER_FEMALE | 
#line 6419
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6420
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6422
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6424
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6423
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6426
    [TRAINER_MARIA_4] =
    {
#line 6427
        .trainerName = _("MARIA"),
#line 6428
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6429
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6430
F_TRAINER_FEMALE | 
#line 6431
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6432
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6434
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6436
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6435
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6438
    [TRAINER_MARIA_5] =
    {
#line 6439
        .trainerName = _("MARIA"),
#line 6440
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6441
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6442
F_TRAINER_FEMALE | 
#line 6443
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 6444
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6446
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6448
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6447
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6450
    [TRAINER_CAMDEN] =
    {
#line 6451
        .trainerName = _("CAMDEN"),
#line 6452
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6453
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6455
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6456
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6458
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6460
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6459
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6462
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6464
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6463
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6466
    [TRAINER_DEMETRIUS] =
    {
#line 6467
        .trainerName = _("DEMETRIUS"),
#line 6468
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 6469
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 6471
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 6472
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6474
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6476
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6475
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6478
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6480
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6479
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6482
    [TRAINER_ISAIAH_1] =
    {
#line 6483
        .trainerName = _("ISAIAH"),
#line 6484
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6485
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6487
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6488
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6490
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6492
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6491
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6494
    [TRAINER_PABLO_1] =
    {
#line 6495
        .trainerName = _("PABLO"),
#line 6496
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6497
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6499
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6500
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6502
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6504
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6503
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6506
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6508
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6507
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6510
    [TRAINER_CHASE] =
    {
#line 6511
        .trainerName = _("CHASE"),
#line 6512
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6513
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6515
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6516
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6518
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6520
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6519
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6522
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6524
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 6523
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6526
    [TRAINER_ISAIAH_2] =
    {
#line 6527
        .trainerName = _("ISAIAH"),
#line 6528
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6529
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6531
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6534
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6536
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6535
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6538
    [TRAINER_ISAIAH_3] =
    {
#line 6539
        .trainerName = _("ISAIAH"),
#line 6540
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6541
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6543
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6544
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6546
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6548
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6547
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6550
    [TRAINER_ISAIAH_4] =
    {
#line 6551
        .trainerName = _("ISAIAH"),
#line 6552
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6553
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6555
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6556
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6558
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6560
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6559
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6562
    [TRAINER_ISAIAH_5] =
    {
#line 6563
        .trainerName = _("ISAIAH"),
#line 6564
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6565
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 6567
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6568
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6570
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6572
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6571
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6574
    [TRAINER_ISOBEL] =
    {
#line 6575
        .trainerName = _("ISOBEL"),
#line 6576
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6577
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6578
F_TRAINER_FEMALE | 
#line 6579
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6580
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6582
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6583
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6586
    [TRAINER_DONNY] =
    {
#line 6587
        .trainerName = _("DONNY"),
#line 6588
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6589
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6590
F_TRAINER_FEMALE | 
#line 6591
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6592
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6594
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6595
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6598
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6600
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
#line 6599
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6602
    [TRAINER_TALIA] =
    {
#line 6603
        .trainerName = _("TALIA"),
#line 6604
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6605
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6606
F_TRAINER_FEMALE | 
#line 6607
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6610
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6611
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6614
    [TRAINER_KATELYN_1] =
    {
#line 6615
        .trainerName = _("KATELYN"),
#line 6616
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6617
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6618
F_TRAINER_FEMALE | 
#line 6619
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6620
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6622
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6624
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6623
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6626
    [TRAINER_ALLISON] =
    {
#line 6627
        .trainerName = _("ALLISON"),
#line 6628
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6629
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6630
F_TRAINER_FEMALE | 
#line 6631
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6632
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6634
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6636
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6635
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6638
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6640
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 6639
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6642
    [TRAINER_KATELYN_2] =
    {
#line 6643
        .trainerName = _("KATELYN"),
#line 6644
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6645
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6646
F_TRAINER_FEMALE | 
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
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6651
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6654
    [TRAINER_KATELYN_3] =
    {
#line 6655
        .trainerName = _("KATELYN"),
#line 6656
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6657
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6658
F_TRAINER_FEMALE | 
#line 6659
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 6660
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6662
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6664
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6663
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6666
    [TRAINER_KATELYN_4] =
    {
#line 6667
        .trainerName = _("KATELYN"),
#line 6668
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 6669
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 6670
F_TRAINER_FEMALE | 
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
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 6675
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6678
    [TRAINER_KATELYN_5] =
    {
#line 6679
        .trainerName = _("KATELYN"),
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
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6688
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 6687
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6690
    [TRAINER_NICOLAS_1] =
    {
#line 6691
        .trainerName = _("NICOLAS"),
#line 6692
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6693
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6695
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6696
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6698
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6700
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6699
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6702
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6704
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6703
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6706
    [TRAINER_NICOLAS_2] =
    {
#line 6707
        .trainerName = _("NICOLAS"),
#line 6708
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6709
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6711
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6712
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6714
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6716
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 6715
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6718
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6720
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 6719
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6722
    [TRAINER_NICOLAS_3] =
    {
#line 6723
        .trainerName = _("NICOLAS"),
#line 6724
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6725
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6727
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6728
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6730
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6732
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 6731
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6734
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6736
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 6735
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6738
    [TRAINER_NICOLAS_4] =
    {
#line 6739
        .trainerName = _("NICOLAS"),
#line 6740
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6741
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6743
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6744
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6746
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6748
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6747
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6750
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6752
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6751
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6754
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6756
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 6755
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6758
    [TRAINER_NICOLAS_5] =
    {
#line 6759
        .trainerName = _("NICOLAS"),
#line 6760
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6761
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6763
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6764
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6766
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6768
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6767
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6770
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6772
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6771
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6774
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6774
            .heldItem = ITEM_DRAGON_FANG,
#line 6776
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 6775
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6778
    [TRAINER_AARON] =
    {
#line 6779
        .trainerName = _("AARON"),
#line 6780
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
#line 6781
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender = 
#line 6783
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 6784
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6786
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6788
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 6787
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 6789
                MOVE_DRAGON_BREATH,
                MOVE_HEADBUTT,
                MOVE_FOCUS_ENERGY,
                MOVE_ASCUAS,
            },
            },
        },
    },
#line 6794
    [TRAINER_PERRY] =
    {
#line 6795
        .trainerName = _("PERRY"),
#line 6796
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6797
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6799
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6800
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6802
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6804
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6803
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6806
    [TRAINER_HUGH] =
    {
#line 6807
        .trainerName = _("HUGH"),
#line 6808
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6809
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6811
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6812
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6814
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6816
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6815
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6818
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6820
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6819
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6822
    [TRAINER_PHIL] =
    {
#line 6823
        .trainerName = _("PHIL"),
#line 6824
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6825
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6827
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6828
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6830
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6832
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6831
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6834
    [TRAINER_JARED] =
    {
#line 6835
        .trainerName = _("JARED"),
#line 6836
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6837
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6839
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6840
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6842
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6844
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6843
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6846
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6848
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6847
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6850
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6852
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 6851
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6854
    [TRAINER_HUMBERTO] =
    {
#line 6855
        .trainerName = _("HUMBERTO"),
#line 6856
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6857
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6859
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6860
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6862
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6864
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 6863
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6866
    [TRAINER_PRESLEY] =
    {
#line 6867
        .trainerName = _("PRESLEY"),
#line 6868
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6869
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6871
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6872
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6874
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6875
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6878
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6880
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6879
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6882
    [TRAINER_EDWARDO] =
    {
#line 6883
        .trainerName = _("EDWARDO"),
#line 6884
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6885
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6887
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6888
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6890
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6892
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 6891
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6894
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6896
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 6895
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6898
    [TRAINER_COLIN] =
    {
#line 6899
        .trainerName = _("COLIN"),
#line 6900
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6901
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6903
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6904
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6906
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6908
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6907
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6910
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6912
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6911
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6914
    [TRAINER_ROBERT_1] =
    {
#line 6915
        .trainerName = _("ROBERT"),
#line 6916
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6917
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6919
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6920
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 6922
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6924
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6923
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6926
    [TRAINER_BENNY] =
    {
#line 6927
        .trainerName = _("BENNY"),
#line 6928
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6929
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6931
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6932
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 6934
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6936
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6935
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6938
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6940
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6939
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6942
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6944
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6943
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6946
    [TRAINER_CHESTER] =
    {
#line 6947
        .trainerName = _("CHESTER"),
#line 6948
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6949
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6951
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6952
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6954
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6956
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6955
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6958
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6960
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 6959
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6962
    [TRAINER_ROBERT_2] =
    {
#line 6963
        .trainerName = _("ROBERT"),
#line 6964
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6965
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6967
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6968
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6970
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6972
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6971
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6974
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6976
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 6975
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6978
    [TRAINER_ROBERT_3] =
    {
#line 6979
        .trainerName = _("ROBERT"),
#line 6980
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6981
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6983
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 6984
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 6986
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6988
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6987
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 6990
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 6992
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 6991
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 6994
    [TRAINER_ROBERT_4] =
    {
#line 6995
        .trainerName = _("ROBERT"),
#line 6996
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 6997
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 6999
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7000
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7002
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7004
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7003
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7006
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7008
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7007
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7010
    [TRAINER_ROBERT_5] =
    {
#line 7011
        .trainerName = _("ROBERT"),
#line 7012
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7013
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7015
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7016
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7018
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7020
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7019
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7022
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7024
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7023
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7026
    [TRAINER_ALEX] =
    {
#line 7027
        .trainerName = _("ALEX"),
#line 7028
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7029
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7031
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7032
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7034
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7036
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7035
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7038
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7040
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7039
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7042
    [TRAINER_BECK] =
    {
#line 7043
        .trainerName = _("BECK"),
#line 7044
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 7045
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 7047
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7048
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7050
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7052
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7051
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7054
    [TRAINER_YASU] =
    {
#line 7055
        .trainerName = _("YASU"),
#line 7056
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7057
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7059
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7060
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7062
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7064
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7063
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7066
    [TRAINER_TAKASHI] =
    {
#line 7067
        .trainerName = _("TAKASHI"),
#line 7068
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7069
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7071
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 7072
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7074
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7076
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7075
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7078
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7080
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7079
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7082
    [TRAINER_DIANNE] =
    {
#line 7083
        .trainerName = _("DIANNE"),
#line 7084
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 7085
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 7086
F_TRAINER_FEMALE | 
#line 7087
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 7088
        .items = { ITEM_FULL_RESTORE },
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7090
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7092
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7091
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7093
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 7096
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7098
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7097
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7099
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 7102
    [TRAINER_JANI] =
    {
#line 7103
        .trainerName = _("JANI"),
#line 7104
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 7105
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 7106
F_TRAINER_FEMALE | 
#line 7107
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7109
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7111
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7110
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7113
    [TRAINER_LAO_1] =
    {
#line 7114
        .trainerName = _("LAO"),
#line 7115
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7116
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7118
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7120
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7122
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7121
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7123
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7128
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7130
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7129
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7131
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7136
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7138
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7137
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7139
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
#line 7144
    [TRAINER_LUNG] =
    {
#line 7145
        .trainerName = _("LUNG"),
#line 7146
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7147
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7149
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7151
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7153
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7152
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7155
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7157
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7156
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7159
    [TRAINER_LAO_2] =
    {
#line 7160
        .trainerName = _("LAO"),
#line 7161
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7162
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7164
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7166
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7168
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7167
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7169
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7174
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7176
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7175
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7177
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7181
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7183
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7182
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7184
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7189
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7190
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7192
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7195
    [TRAINER_LAO_3] =
    {
#line 7196
        .trainerName = _("LAO"),
#line 7197
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7198
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7200
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7202
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7204
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7203
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7205
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7210
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7212
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7211
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7213
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7218
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7220
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7219
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7221
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7225
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7227
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7226
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7228
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7231
    [TRAINER_LAO_4] =
    {
#line 7232
        .trainerName = _("LAO"),
#line 7233
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7234
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7236
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7238
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7240
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7239
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7241
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7245
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7247
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7246
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7248
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7252
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7254
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7253
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7255
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7259
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7261
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7260
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7262
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7265
    [TRAINER_LAO_5] =
    {
#line 7266
        .trainerName = _("LAO"),
#line 7267
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 7268
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 7270
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 7272
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7274
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7273
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7275
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
#line 7279
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7281
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7280
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7282
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7287
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7289
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7288
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7290
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
#line 7295
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7295
            .heldItem = ITEM_SMOKE_BALL,
#line 7297
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7296
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7298
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
#line 7301
    [TRAINER_JOCELYN] =
    {
#line 7302
        .trainerName = _("JOCELYN"),
#line 7303
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7304
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7305
F_TRAINER_FEMALE | 
#line 7306
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7307
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7309
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7311
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7310
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7313
    [TRAINER_LAURA] =
    {
#line 7314
        .trainerName = _("LAURA"),
#line 7315
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7316
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7317
F_TRAINER_FEMALE | 
#line 7318
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7319
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7321
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7323
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 7322
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7325
    [TRAINER_CYNDY_1] =
    {
#line 7326
        .trainerName = _("CYNDY"),
#line 7327
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7328
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7329
F_TRAINER_FEMALE | 
#line 7330
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7331
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7333
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7335
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7334
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7337
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7339
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7338
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7341
    [TRAINER_CORA] =
    {
#line 7342
        .trainerName = _("CORA"),
#line 7343
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7344
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7345
F_TRAINER_FEMALE | 
#line 7346
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7347
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7349
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7351
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7350
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7353
    [TRAINER_PAULA] =
    {
#line 7354
        .trainerName = _("PAULA"),
#line 7355
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7356
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7357
F_TRAINER_FEMALE | 
#line 7358
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7359
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7361
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7363
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 7362
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7365
    [TRAINER_CYNDY_2] =
    {
#line 7366
        .trainerName = _("CYNDY"),
#line 7367
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7368
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7369
F_TRAINER_FEMALE | 
#line 7370
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7371
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7373
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7375
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 7374
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7377
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7379
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 7378
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7381
    [TRAINER_CYNDY_3] =
    {
#line 7382
        .trainerName = _("CYNDY"),
#line 7383
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7384
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7385
F_TRAINER_FEMALE | 
#line 7386
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7387
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7389
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7391
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 7390
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7393
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7395
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 7394
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7397
    [TRAINER_CYNDY_4] =
    {
#line 7398
        .trainerName = _("CYNDY"),
#line 7399
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7400
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7401
F_TRAINER_FEMALE | 
#line 7402
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7403
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7405
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7407
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7406
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7409
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7411
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 7410
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7413
    [TRAINER_CYNDY_5] =
    {
#line 7414
        .trainerName = _("CYNDY"),
#line 7415
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 7416
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 7417
F_TRAINER_FEMALE | 
#line 7418
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 7419
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7421
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7423
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 7422
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7425
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7427
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 7426
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7429
    [TRAINER_MADELINE_1] =
    {
#line 7430
        .trainerName = _("MADELINE"),
#line 7431
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7432
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7433
F_TRAINER_FEMALE | 
#line 7434
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7437
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7438
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7440
                MOVE_ASCUAS,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_DIA_SOLEADO,
            },
            },
        },
    },
#line 7445
    [TRAINER_CLARISSA] =
    {
#line 7446
        .trainerName = _("CLARISSA"),
#line 7447
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7448
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7449
F_TRAINER_FEMALE | 
#line 7450
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7451
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7453
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7455
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7454
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7457
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7459
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7458
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7461
    [TRAINER_ANGELICA] =
    {
#line 7462
        .trainerName = _("ANGELICA"),
#line 7463
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7464
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7465
F_TRAINER_FEMALE | 
#line 7466
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7467
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7469
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7471
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 7470
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7472
                MOVE_DANZA_LLUVIA,
                MOVE_WEATHER_BALL,
                MOVE_THUNDER,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
#line 7477
    [TRAINER_MADELINE_2] =
    {
#line 7478
        .trainerName = _("MADELINE"),
#line 7479
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7480
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7481
F_TRAINER_FEMALE | 
#line 7482
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7485
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7487
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 7486
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7488
                MOVE_ASCUAS,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_DIA_SOLEADO,
            },
            },
        },
    },
#line 7493
    [TRAINER_MADELINE_3] =
    {
#line 7494
        .trainerName = _("MADELINE"),
#line 7495
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7496
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7497
F_TRAINER_FEMALE | 
#line 7498
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7499
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7501
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7503
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 7502
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7504
                MOVE_ASCUAS,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_DIA_SOLEADO,
            },
            },
        },
    },
#line 7509
    [TRAINER_MADELINE_4] =
    {
#line 7510
        .trainerName = _("MADELINE"),
#line 7511
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 7512
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 7513
F_TRAINER_FEMALE | 
#line 7514
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 7515
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7517
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7519
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7518
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7520
                MOVE_LEECH_SEED,
                MOVE_MEGA_DRAIN,
                MOVE_SILBATO,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 7525
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7527
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 7526
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7528
                MOVE_LANZALLAMAS,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_DIA_SOLEADO,
            },
            },
        },
    },
#line 7533
    [TRAINER_MADELINE_5] =
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7541
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7543
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7542
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7544
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_SOLAR_BEAM,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 7549
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7551
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 7550
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7552
                MOVE_LANZALLAMAS,
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_DIA_SOLEADO,
            },
            },
        },
    },
#line 7557
    [TRAINER_BEVERLY] =
    {
#line 7558
        .trainerName = _("BEVERLY"),
#line 7559
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7560
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7561
F_TRAINER_FEMALE | 
#line 7562
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7563
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7565
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7567
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7566
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7569
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7571
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7570
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7573
    [TRAINER_IMANI] =
    {
#line 7574
        .trainerName = _("IMANI"),
#line 7575
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7576
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7577
F_TRAINER_FEMALE | 
#line 7578
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7579
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7581
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7583
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7582
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7585
    [TRAINER_KYLA] =
    {
#line 7586
        .trainerName = _("KYLA"),
#line 7587
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7588
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7589
F_TRAINER_FEMALE | 
#line 7590
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7591
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7593
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7595
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7594
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7597
    [TRAINER_DENISE] =
    {
#line 7598
        .trainerName = _("DENISE"),
#line 7599
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7600
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7601
F_TRAINER_FEMALE | 
#line 7602
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7603
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7605
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7607
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7606
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7609
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7611
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7610
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7613
    [TRAINER_BETH] =
    {
#line 7614
        .trainerName = _("BETH"),
#line 7615
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7616
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7617
F_TRAINER_FEMALE | 
#line 7618
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7619
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7621
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7623
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7622
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7625
    [TRAINER_TARA] =
    {
#line 7626
        .trainerName = _("TARA"),
#line 7627
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7628
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7629
F_TRAINER_FEMALE | 
#line 7630
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7631
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7633
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7635
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7634
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7637
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7639
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7638
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7641
    [TRAINER_MISSY] =
    {
#line 7642
        .trainerName = _("MISSY"),
#line 7643
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7644
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7645
F_TRAINER_FEMALE | 
#line 7646
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7647
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7649
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7651
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7650
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7653
    [TRAINER_ALICE] =
    {
#line 7654
        .trainerName = _("ALICE"),
#line 7655
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7656
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7657
F_TRAINER_FEMALE | 
#line 7658
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7659
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7661
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7663
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7662
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7665
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7667
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7666
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7669
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7671
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7670
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7673
    [TRAINER_JENNY_1] =
    {
#line 7674
        .trainerName = _("JENNY"),
#line 7675
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7676
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7677
F_TRAINER_FEMALE | 
#line 7678
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7679
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7681
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7683
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7682
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7685
    [TRAINER_GRACE] =
    {
#line 7686
        .trainerName = _("GRACE"),
#line 7687
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7688
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7689
F_TRAINER_FEMALE | 
#line 7690
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7691
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7693
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7695
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7694
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7697
    [TRAINER_TANYA] =
    {
#line 7698
        .trainerName = _("TANYA"),
#line 7699
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7700
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7701
F_TRAINER_FEMALE | 
#line 7702
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7703
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7705
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7707
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7706
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7709
    [TRAINER_SHARON] =
    {
#line 7710
        .trainerName = _("SHARON"),
#line 7711
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7712
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7713
F_TRAINER_FEMALE | 
#line 7714
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7715
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7717
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7719
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7718
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7721
    [TRAINER_NIKKI] =
    {
#line 7722
        .trainerName = _("NIKKI"),
#line 7723
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7724
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7725
F_TRAINER_FEMALE | 
#line 7726
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7727
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7729
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7731
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7730
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7733
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7735
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7734
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7737
    [TRAINER_BRENDA] =
    {
#line 7738
        .trainerName = _("BRENDA"),
#line 7739
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7740
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7741
F_TRAINER_FEMALE | 
#line 7742
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7743
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7745
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7747
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7746
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7749
    [TRAINER_KATIE] =
    {
#line 7750
        .trainerName = _("KATIE"),
#line 7751
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7752
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7753
F_TRAINER_FEMALE | 
#line 7754
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7755
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7757
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7759
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7758
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7761
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7763
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7762
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7765
    [TRAINER_SUSIE] =
    {
#line 7766
        .trainerName = _("SUSIE"),
#line 7767
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7768
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7769
F_TRAINER_FEMALE | 
#line 7770
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7771
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7773
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7775
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7774
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7777
    [TRAINER_KARA] =
    {
#line 7778
        .trainerName = _("KARA"),
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
            .species = SPECIES_SEAKING,
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
    [TRAINER_DANA] =
    {
#line 7790
        .trainerName = _("DANA"),
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
            .species = SPECIES_AZUMARILL,
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
    [TRAINER_SIENNA] =
    {
#line 7802
        .trainerName = _("SIENNA"),
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
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7809
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7811
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7810
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7813
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7815
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7814
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7817
    [TRAINER_DEBRA] =
    {
#line 7818
        .trainerName = _("DEBRA"),
#line 7819
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7820
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7821
F_TRAINER_FEMALE | 
#line 7822
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7823
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7825
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7827
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7826
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7829
    [TRAINER_LINDA] =
    {
#line 7830
        .trainerName = _("LINDA"),
#line 7831
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7832
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7833
F_TRAINER_FEMALE | 
#line 7834
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7837
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7838
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7841
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7843
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7842
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7845
    [TRAINER_KAYLEE] =
    {
#line 7846
        .trainerName = _("KAYLEE"),
#line 7847
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7848
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7849
F_TRAINER_FEMALE | 
#line 7850
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7851
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7853
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7855
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7854
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7857
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7859
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7858
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7861
    [TRAINER_LAUREL] =
    {
#line 7862
        .trainerName = _("LAUREL"),
#line 7863
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7864
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7865
F_TRAINER_FEMALE | 
#line 7866
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7867
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7869
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7871
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7870
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7873
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7875
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7874
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7877
    [TRAINER_CARLEE] =
    {
#line 7878
        .trainerName = _("CARLEE"),
#line 7879
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7880
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7881
F_TRAINER_FEMALE | 
#line 7882
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7883
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7885
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7887
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7886
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7889
    [TRAINER_JENNY_2] =
    {
#line 7890
        .trainerName = _("JENNY"),
#line 7891
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7892
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7893
F_TRAINER_FEMALE | 
#line 7894
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7895
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7897
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7899
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7898
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7901
    [TRAINER_JENNY_3] =
    {
#line 7902
        .trainerName = _("JENNY"),
#line 7903
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7904
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7905
F_TRAINER_FEMALE | 
#line 7906
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7907
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 7909
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7911
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7910
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7913
    [TRAINER_JENNY_4] =
    {
#line 7914
        .trainerName = _("JENNY"),
#line 7915
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7916
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7917
F_TRAINER_FEMALE | 
#line 7918
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7919
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7921
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7923
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7922
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7925
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7927
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7926
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7929
    [TRAINER_JENNY_5] =
    {
#line 7930
        .trainerName = _("JENNY"),
#line 7931
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 7932
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 7933
F_TRAINER_FEMALE | 
#line 7934
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 7935
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 7937
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7939
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7938
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7941
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7943
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7942
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 7945
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7947
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7946
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 7949
    [TRAINER_HEIDI] =
    {
#line 7950
        .trainerName = _("HEIDI"),
#line 7951
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 7952
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 7953
F_TRAINER_FEMALE | 
#line 7954
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 7955
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7957
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7959
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7958
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7960
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
            {
#line 7965
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7967
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7966
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7968
                MOVE_GIRO_RAPIDO,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
#line 7973
    [TRAINER_BECKY] =
    {
#line 7974
        .trainerName = _("BECKY"),
#line 7975
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 7976
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 7977
F_TRAINER_FEMALE | 
#line 7978
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 7979
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 7981
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7982
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7984
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
                MOVE_DIG,
            },
            },
            {
#line 7989
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 7991
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 7990
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 7992
                MOVE_ROLLOUT,
                MOVE_BUBBLE_BEAM,
                MOVE_TAIL_WHIP,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
#line 7997
    [TRAINER_CAROL] =
    {
#line 7998
        .trainerName = _("CAROL"),
#line 7999
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8000
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8001
F_TRAINER_FEMALE | 
#line 8002
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8003
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8005
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8007
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8006
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8009
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8011
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8010
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8013
    [TRAINER_NANCY] =
    {
#line 8014
        .trainerName = _("NANCY"),
#line 8015
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8016
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8017
F_TRAINER_FEMALE | 
#line 8018
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8019
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8021
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8023
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8022
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8025
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8027
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8026
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8029
    [TRAINER_MARTHA] =
    {
#line 8030
        .trainerName = _("MARTHA"),
#line 8031
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8032
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8033
F_TRAINER_FEMALE | 
#line 8034
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8035
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8037
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8039
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8038
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8041
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8043
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8042
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8045
    [TRAINER_DIANA_1] =
    {
#line 8046
        .trainerName = _("DIANA"),
#line 8047
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8048
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8049
F_TRAINER_FEMALE | 
#line 8050
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8051
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8053
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8055
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8054
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8057
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8059
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8058
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8061
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8063
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8062
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8065
    [TRAINER_CEDRIC] =
    {
#line 8066
        .trainerName = _("CEDRIC"),
#line 8067
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 8068
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 8070
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8071
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8073
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8075
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8074
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8076
                MOVE_DESTINY_BOND,
                MOVE_SAFEGUARD,
                MOVE_COUNTER,
                MOVE_MIRROR_COAT,
            },
            },
        },
    },
#line 8081
    [TRAINER_IRENE] =
    {
#line 8082
        .trainerName = _("IRENE"),
#line 8083
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8084
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8085
F_TRAINER_FEMALE | 
#line 8086
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8087
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8089
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8091
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8090
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8093
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8095
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8094
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8097
    [TRAINER_DIANA_2] =
    {
#line 8098
        .trainerName = _("DIANA"),
#line 8099
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8100
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8101
F_TRAINER_FEMALE | 
#line 8102
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8103
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8105
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8107
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8106
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8109
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8111
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8110
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8113
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8115
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8114
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8117
    [TRAINER_DIANA_3] =
    {
#line 8118
        .trainerName = _("DIANA"),
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
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8125
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8127
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8126
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8129
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8131
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8130
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8133
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8135
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8134
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8137
    [TRAINER_DIANA_4] =
    {
#line 8138
        .trainerName = _("DIANA"),
#line 8139
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8140
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8141
F_TRAINER_FEMALE | 
#line 8142
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8145
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8147
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8146
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8149
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8151
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8150
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8153
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8155
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8154
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8157
    [TRAINER_DIANA_5] =
    {
#line 8158
        .trainerName = _("DIANA"),
#line 8159
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 8160
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 8161
F_TRAINER_FEMALE | 
#line 8162
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 8163
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8165
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8167
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8166
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8169
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8171
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8170
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8173
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8175
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8174
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8177
    [TRAINER_AMY_AND_LIV_1] =
    {
#line 8178
        .trainerName = _("AMY & LIV"),
#line 8179
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8180
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8182
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8183
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8185
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8186
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8189
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8190
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8193
    [TRAINER_AMY_AND_LIV_2] =
    {
#line 8194
        .trainerName = _("AMY & LIV"),
#line 8195
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8196
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8198
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8201
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8203
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8202
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8205
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8207
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8206
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8209
    [TRAINER_GINA_AND_MIA_1] =
    {
#line 8210
        .trainerName = _("GINA & MIA"),
#line 8211
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8212
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8214
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8215
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8217
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8218
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8221
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8223
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8222
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8225
    [TRAINER_MIU_AND_YUKI] =
    {
#line 8226
        .trainerName = _("MIU & YUKI"),
#line 8227
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8228
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8230
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8231
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8233
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8235
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8234
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8237
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8239
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8238
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8241
    [TRAINER_AMY_AND_LIV_3] =
    {
#line 8242
        .trainerName = _("AMY & LIV"),
#line 8243
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8244
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8246
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8247
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8249
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8251
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8250
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8253
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8255
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8254
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8257
    [TRAINER_GINA_AND_MIA_2] =
    {
#line 8258
        .trainerName = _("GINA & MIA"),
#line 8259
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8260
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8262
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8263
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8265
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8267
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8266
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8268
                MOVE_NIGHT_SHADE,
                MOVE_DISABLE,
            },
            },
            {
#line 8271
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8273
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8272
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8274
                MOVE_ABSORB,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
#line 8277
    [TRAINER_AMY_AND_LIV_4] =
    {
#line 8278
        .trainerName = _("AMY & LIV"),
#line 8279
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8280
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8282
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8283
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8285
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8287
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8286
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8289
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8291
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8290
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8293
    [TRAINER_AMY_AND_LIV_5] =
    {
#line 8294
        .trainerName = _("AMY & LIV"),
#line 8295
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8296
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8298
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8299
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8301
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8303
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8302
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8304
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
#line 8309
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8311
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8310
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8312
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
#line 8317
    [TRAINER_AMY_AND_LIV_6] =
    {
#line 8318
        .trainerName = _("AMY & LIV"),
#line 8319
        .trainerClass = TRAINER_CLASS_TWINS,
#line 8320
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 8322
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8323
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8325
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8327
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8326
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8328
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
#line 8333
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8335
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8334
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8336
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
#line 8341
    [TRAINER_HUEY] =
    {
#line 8342
        .trainerName = _("HUEY"),
#line 8343
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8344
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8346
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8347
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8349
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8351
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8350
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8353
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8355
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8354
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8357
    [TRAINER_EDMOND] =
    {
#line 8358
        .trainerName = _("EDMOND"),
#line 8359
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8360
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8362
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8363
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8365
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8367
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8366
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8369
    [TRAINER_ERNEST_1] =
    {
#line 8370
        .trainerName = _("ERNEST"),
#line 8371
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8372
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8374
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8375
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8377
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8379
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8378
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8381
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8383
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8382
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8385
    [TRAINER_DWAYNE] =
    {
#line 8386
        .trainerName = _("DWAYNE"),
#line 8387
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8388
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8390
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8391
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8393
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8395
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8394
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8397
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8399
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8398
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8401
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8403
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8402
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8405
    [TRAINER_PHILLIP] =
    {
#line 8406
        .trainerName = _("PHILLIP"),
#line 8407
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8408
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8410
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8411
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8413
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8415
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8414
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8417
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8419
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8418
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8421
    [TRAINER_LEONARD] =
    {
#line 8422
        .trainerName = _("LEONARD"),
#line 8423
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8424
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8426
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8427
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8429
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8430
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8433
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8435
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8434
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8437
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8439
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8438
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8441
    [TRAINER_DUNCAN] =
    {
#line 8442
        .trainerName = _("DUNCAN"),
#line 8443
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8444
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8446
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8447
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8449
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8451
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8450
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8453
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8455
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8454
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8457
    [TRAINER_ERNEST_2] =
    {
#line 8458
        .trainerName = _("ERNEST"),
#line 8459
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8460
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8462
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8463
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8465
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8467
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8466
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8469
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8471
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8470
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8473
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8475
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 8474
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8477
    [TRAINER_ERNEST_3] =
    {
#line 8478
        .trainerName = _("ERNEST"),
#line 8479
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8480
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8482
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8485
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8487
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8486
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8489
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8491
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8490
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8493
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8495
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 8494
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8497
    [TRAINER_ERNEST_4] =
    {
#line 8498
        .trainerName = _("ERNEST"),
#line 8499
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8500
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8502
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8503
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8505
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8507
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8506
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8509
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8511
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8510
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8513
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8515
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 8514
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8517
    [TRAINER_ERNEST_5] =
    {
#line 8518
        .trainerName = _("ERNEST"),
#line 8519
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8520
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8522
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8523
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8525
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8527
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8526
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8529
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8531
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8530
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8533
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8535
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 8534
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8537
    [TRAINER_ELI] =
    {
#line 8538
        .trainerName = _("ELI"),
#line 8539
        .trainerClass = TRAINER_CLASS_HIKER,
#line 8540
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 8542
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 8543
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8545
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8547
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8546
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8549
    [TRAINER_ANNIKA] =
    {
#line 8550
        .trainerName = _("ANNIKA"),
#line 8551
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 8552
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender = 
#line 8553
F_TRAINER_FEMALE | 
#line 8554
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 8555
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8557
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8557
            .heldItem = ITEM_ORAN_BERRY,
#line 8559
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8558
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8560
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
            {
#line 8565
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8565
            .heldItem = ITEM_ORAN_BERRY,
#line 8567
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8566
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8568
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 8573
    [TRAINER_JAZMYN] =
    {
#line 8574
        .trainerName = _("JAZMYN"),
#line 8575
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 8576
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 8577
F_TRAINER_FEMALE | 
#line 8578
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8579
        .items = { ITEM_HYPER_POTION },
#line 8580
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8582
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8584
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8583
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8586
    [TRAINER_JONAS] =
    {
#line 8587
        .trainerName = _("JONAS"),
#line 8588
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 8589
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 8591
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8592
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8594
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8595
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8597
                MOVE_TOXIC,
                MOVE_THUNDER,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
#line 8602
    [TRAINER_KAYLEY] =
    {
#line 8603
        .trainerName = _("KAYLEY"),
#line 8604
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 8605
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 8606
F_TRAINER_FEMALE | 
#line 8607
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 8608
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8610
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8612
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8611
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8613
                MOVE_DIA_SOLEADO,
                MOVE_WEATHER_BALL,
                MOVE_LANZALLAMAS,
                MOVE_SOLAR_BEAM,
            },
            },
        },
    },
#line 8618
    [TRAINER_AURON] =
    {
#line 8619
        .trainerName = _("AURON"),
#line 8620
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 8621
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 8623
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8624
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8626
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8628
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8627
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8630
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8632
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8631
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8634
    [TRAINER_KELVIN] =
    {
#line 8635
        .trainerName = _("KELVIN"),
#line 8636
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8637
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8639
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8640
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8642
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8644
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8643
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8646
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8648
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8647
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8650
    [TRAINER_MARLEY] =
    {
#line 8651
        .trainerName = _("MARLEY"),
#line 8652
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 8653
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 8654
F_TRAINER_FEMALE | 
#line 8655
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 8656
        .items = { ITEM_HYPER_POTION },
#line 8657
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8659
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8661
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 8660
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8662
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
            },
            },
        },
    },
#line 8667
    [TRAINER_REYNA] =
    {
#line 8668
        .trainerName = _("REYNA"),
#line 8669
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 8670
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 8671
F_TRAINER_FEMALE | 
#line 8672
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8673
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8675
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8677
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8676
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8679
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8681
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 8680
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8683
    [TRAINER_HUDSON] =
    {
#line 8684
        .trainerName = _("HUDSON"),
#line 8685
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 8686
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 8688
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8689
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8691
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8693
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8692
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8695
    [TRAINER_CONOR] =
    {
#line 8696
        .trainerName = _("CONOR"),
#line 8697
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 8698
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 8700
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 8701
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8703
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8705
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8704
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8707
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8709
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 8708
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8711
    [TRAINER_EDWIN_1] =
    {
#line 8712
        .trainerName = _("EDWIN"),
#line 8713
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8714
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8716
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8717
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8719
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8721
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8720
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8723
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8725
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8724
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8727
    [TRAINER_HECTOR] =
    {
#line 8728
        .trainerName = _("HECTOR"),
#line 8729
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8730
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8732
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8733
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8735
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8737
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8736
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8739
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8741
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8740
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8743
    [TRAINER_TABITHA_MOSSDEEP] =
    {
#line 8744
        .trainerName = _("TABITHA"),
#line 8745
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 8746
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 8748
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 8749
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8751
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8753
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8752
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8755
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8757
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8756
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8759
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8761
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8760
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8763
    [TRAINER_EDWIN_2] =
    {
#line 8764
        .trainerName = _("EDWIN"),
#line 8765
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8766
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8768
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8769
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8771
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8773
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8772
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8775
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8777
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8776
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8779
    [TRAINER_EDWIN_3] =
    {
#line 8780
        .trainerName = _("EDWIN"),
#line 8781
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8782
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8784
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8785
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8787
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8789
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8788
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8791
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8793
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8792
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8795
    [TRAINER_EDWIN_4] =
    {
#line 8796
        .trainerName = _("EDWIN"),
#line 8797
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8798
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8800
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8801
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8803
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8805
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8804
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8807
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8808
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8811
    [TRAINER_EDWIN_5] =
    {
#line 8812
        .trainerName = _("EDWIN"),
#line 8813
        .trainerClass = TRAINER_CLASS_COLLECTOR,
#line 8814
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender = 
#line 8816
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 8817
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 8819
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8821
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8820
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8823
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8825
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8824
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8827
    [TRAINER_WALLY_VR_1] =
    {
#line 8828
        .trainerName = _("WALLY"),
#line 8829
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8830
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 8832
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8833
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 8834
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 8836
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8838
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8837
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8839
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 8844
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8846
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8845
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8847
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 8852
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8854
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8853
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8855
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 8860
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8862
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8861
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8863
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 8868
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8870
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 8869
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 8871
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 8876
    [TRAINER_BRENDAN_ROUTE_103_MUDKIP] =
    {
#line 8877
        .trainerName = _("BRENDAN"),
#line 8878
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8879
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8881
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8882
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8884
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8886
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8885
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8888
    [TRAINER_BRENDAN_ROUTE_110_MUDKIP] =
    {
#line 8889
        .trainerName = _("BRENDAN"),
#line 8890
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8891
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8893
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8894
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8896
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8898
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8897
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8900
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8902
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8901
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8904
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8906
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8905
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8908
    [TRAINER_BRENDAN_ROUTE_119_MUDKIP] =
    {
#line 8909
        .trainerName = _("BRENDAN"),
#line 8910
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8911
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8913
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8914
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8916
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8918
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8917
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8920
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8922
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8921
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8924
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8926
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8925
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8928
    [TRAINER_BRENDAN_ROUTE_103_TREECKO] =
    {
#line 8929
        .trainerName = _("BRENDAN"),
#line 8930
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8931
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8933
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8934
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 8936
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8938
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 8937
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8940
    [TRAINER_BRENDAN_ROUTE_110_TREECKO] =
    {
#line 8941
        .trainerName = _("BRENDAN"),
#line 8942
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8943
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8945
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8946
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8948
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8950
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8949
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8952
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8954
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 8953
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8956
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8958
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8957
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8960
    [TRAINER_BRENDAN_ROUTE_119_TREECKO] =
    {
#line 8961
        .trainerName = _("BRENDAN"),
#line 8962
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 8963
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 8965
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 8966
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 8968
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8970
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8969
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8972
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8974
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 8973
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 8976
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 8978
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 8977
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 8980
    [TRAINER_BRENDAN_ROUTE_103_TORCHIC] =
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
            .species = SPECIES_MUDKIP,
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
    [TRAINER_BRENDAN_ROUTE_110_TORCHIC] =
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
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9002
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9001
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9004
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9006
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9005
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9008
            .species = SPECIES_MARSHTOMP,
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
    [TRAINER_BRENDAN_ROUTE_119_TORCHIC] =
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
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9022
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9021
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9024
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9026
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9025
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9028
            .species = SPECIES_MARSHTOMP,
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
    [TRAINER_MAY_ROUTE_103_MUDKIP] =
    {
#line 9033
        .trainerName = _("MAY"),
#line 9034
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9035
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9036
F_TRAINER_FEMALE | 
#line 9037
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9038
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9040
            .species = SPECIES_TREECKO,
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
    [TRAINER_MAY_ROUTE_110_MUDKIP] =
    {
#line 9045
        .trainerName = _("MAY"),
#line 9046
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9047
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9048
F_TRAINER_FEMALE | 
#line 9049
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
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
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9058
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9057
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9060
            .species = SPECIES_GROVYLE,
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
    [TRAINER_MAY_ROUTE_119_MUDKIP] =
    {
#line 9065
        .trainerName = _("MAY"),
#line 9066
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9067
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9068
F_TRAINER_FEMALE | 
#line 9069
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9070
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9072
            .species = SPECIES_SLUGMA,
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
            .species = SPECIES_GROVYLE,
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
    [TRAINER_MAY_ROUTE_103_TREECKO] =
    {
#line 9085
        .trainerName = _("MAY"),
#line 9086
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9087
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9088
F_TRAINER_FEMALE | 
#line 9089
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9090
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9092
            .species = SPECIES_TORCHIC,
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
    [TRAINER_MAY_ROUTE_110_TREECKO] =
    {
#line 9097
        .trainerName = _("MAY"),
#line 9098
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9099
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9100
F_TRAINER_FEMALE | 
#line 9101
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9102
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9104
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9106
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9105
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9108
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9110
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9109
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9112
            .species = SPECIES_COMBUSKEN,
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
    [TRAINER_MAY_ROUTE_119_TREECKO] =
    {
#line 9117
        .trainerName = _("MAY"),
#line 9118
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 9119
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 9120
F_TRAINER_FEMALE | 
#line 9121
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9122
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9124
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9126
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9125
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9128
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9130
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9129
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9132
            .species = SPECIES_COMBUSKEN,
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
    [TRAINER_MAY_ROUTE_103_TORCHIC] =
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
            .species = SPECIES_MUDKIP,
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
    [TRAINER_MAY_ROUTE_110_TORCHIC] =
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
            .species = SPECIES_LOMBRE,
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
            .species = SPECIES_MARSHTOMP,
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
    [TRAINER_MAY_ROUTE_119_TORCHIC] =
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
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9178
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9177
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9180
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9182
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9181
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9184
            .species = SPECIES_MARSHTOMP,
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
    [TRAINER_ISAAC_1] =
    {
#line 9189
        .trainerName = _("ISAAC"),
#line 9190
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9191
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9193
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9194
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9196
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9198
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9197
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9200
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9202
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9201
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9204
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9206
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9205
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9208
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9210
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9209
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9212
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9214
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9213
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9216
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9218
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9217
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9220
    [TRAINER_DAVIS] =
    {
#line 9221
        .trainerName = _("DAVIS"),
#line 9222
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 9223
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 9225
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9226
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9228
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9230
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9229
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9232
    [TRAINER_MITCHELL] =
    {
#line 9233
        .trainerName = _("MITCHELL"),
#line 9234
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 9235
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 9237
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9238
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9240
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9242
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9241
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9243
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
            },
            },
            {
#line 9248
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9250
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9249
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9251
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 9256
    [TRAINER_ISAAC_2] =
    {
#line 9257
        .trainerName = _("ISAAC"),
#line 9258
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9259
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9261
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9262
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9264
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9266
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9265
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9268
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9270
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9269
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9272
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9274
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9273
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9276
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9278
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9277
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9280
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9282
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9281
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9284
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9286
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9285
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9288
    [TRAINER_ISAAC_3] =
    {
#line 9289
        .trainerName = _("ISAAC"),
#line 9290
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9291
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9293
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9294
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9296
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9298
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9297
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9300
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9302
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9301
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9304
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9306
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9305
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9308
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9310
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9309
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9312
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9314
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9313
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9316
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9318
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9317
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9320
    [TRAINER_ISAAC_4] =
    {
#line 9321
        .trainerName = _("ISAAC"),
#line 9322
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9323
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9325
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9326
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9328
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9330
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9329
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9332
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9334
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9333
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9336
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9338
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9337
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9340
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9342
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9341
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9344
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9346
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9345
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9348
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9350
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9349
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9352
    [TRAINER_ISAAC_5] =
    {
#line 9353
        .trainerName = _("ISAAC"),
#line 9354
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9355
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 9357
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9358
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9360
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9362
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9361
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9364
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9366
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9365
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9368
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9370
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9369
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9372
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9374
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9373
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9376
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9378
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9377
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9380
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9382
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9381
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9384
    [TRAINER_LYDIA_1] =
    {
#line 9385
        .trainerName = _("LYDIA"),
#line 9386
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9387
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9388
F_TRAINER_FEMALE | 
#line 9389
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9390
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9392
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9394
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9393
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9396
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9398
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9397
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9400
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9402
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9401
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9404
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9406
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9405
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9408
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9410
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9409
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9412
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9414
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9413
            .lvl = 11,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9416
    [TRAINER_HALLE] =
    {
#line 9417
        .trainerName = _("HALLE"),
#line 9418
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 9419
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 9420
F_TRAINER_FEMALE | 
#line 9421
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9422
        .items = { ITEM_FULL_RESTORE },
#line 9423
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9425
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9427
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9426
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9429
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9431
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9430
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9433
    [TRAINER_GARRISON] =
    {
#line 9434
        .trainerName = _("GARRISON"),
#line 9435
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 9436
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 9438
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9439
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9441
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9443
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9442
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9445
    [TRAINER_LYDIA_2] =
    {
#line 9446
        .trainerName = _("LYDIA"),
#line 9447
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9448
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9449
F_TRAINER_FEMALE | 
#line 9450
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9451
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9453
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9455
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9454
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9457
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9459
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9458
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9461
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9463
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9462
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9465
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9467
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9466
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9469
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9471
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9470
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9473
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9475
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 9474
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9477
    [TRAINER_LYDIA_3] =
    {
#line 9478
        .trainerName = _("LYDIA"),
#line 9479
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9480
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9481
F_TRAINER_FEMALE | 
#line 9482
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9483
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9485
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9487
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9486
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9489
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9491
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9490
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9493
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9495
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9494
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9497
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9499
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9498
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9501
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9503
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9502
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9505
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9507
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 9506
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9509
    [TRAINER_LYDIA_4] =
    {
#line 9510
        .trainerName = _("LYDIA"),
#line 9511
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9512
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9513
F_TRAINER_FEMALE | 
#line 9514
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9515
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9517
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9519
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9518
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9521
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9523
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9522
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9525
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9527
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9526
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9529
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9531
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9530
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9533
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9535
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9534
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9537
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9539
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 9538
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9541
    [TRAINER_LYDIA_5] =
    {
#line 9542
        .trainerName = _("LYDIA"),
#line 9543
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 9544
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 9545
F_TRAINER_FEMALE | 
#line 9546
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 9547
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 9549
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9551
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9550
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9553
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9555
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9554
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9557
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9559
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9558
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9561
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9563
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9562
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9565
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9567
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9566
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9569
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9571
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 9570
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9573
    [TRAINER_JACKSON_1] =
    {
#line 9574
        .trainerName = _("JACKSON"),
#line 9575
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9576
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9578
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9579
        .items = { ITEM_FULL_RESTORE },
#line 9580
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9582
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9584
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9583
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9586
    [TRAINER_LORENZO] =
    {
#line 9587
        .trainerName = _("LORENZO"),
#line 9588
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9589
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9591
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9592
        .items = { ITEM_FULL_RESTORE },
#line 9593
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9595
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9597
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9596
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9599
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9601
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9600
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9603
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9605
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9604
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9607
    [TRAINER_SEBASTIAN] =
    {
#line 9608
        .trainerName = _("SEBASTIAN"),
#line 9609
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9610
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9612
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9613
        .items = { ITEM_FULL_RESTORE },
#line 9614
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9616
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9618
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9617
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9620
    [TRAINER_JACKSON_2] =
    {
#line 9621
        .trainerName = _("JACKSON"),
#line 9622
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9623
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9625
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9626
        .items = { ITEM_FULL_RESTORE },
#line 9627
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9629
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9631
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9630
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9633
    [TRAINER_JACKSON_3] =
    {
#line 9634
        .trainerName = _("JACKSON"),
#line 9635
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9636
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9638
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9639
        .items = { ITEM_FULL_RESTORE },
#line 9640
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9642
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9644
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9643
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9646
    [TRAINER_JACKSON_4] =
    {
#line 9647
        .trainerName = _("JACKSON"),
#line 9648
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9649
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9651
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9652
        .items = { ITEM_FULL_RESTORE },
#line 9653
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9655
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9657
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9656
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9659
    [TRAINER_JACKSON_5] =
    {
#line 9660
        .trainerName = _("JACKSON"),
#line 9661
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9662
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender = 
#line 9664
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9665
        .items = { ITEM_FULL_RESTORE },
#line 9666
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9668
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9670
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9669
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9672
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9674
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9673
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9676
    [TRAINER_CATHERINE_1] =
    {
#line 9677
        .trainerName = _("CATHERINE"),
#line 9678
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9679
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9680
F_TRAINER_FEMALE | 
#line 9681
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9682
        .items = { ITEM_FULL_RESTORE },
#line 9683
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9685
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9687
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9686
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9689
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9691
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9690
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9693
    [TRAINER_JENNA] =
    {
#line 9694
        .trainerName = _("JENNA"),
#line 9695
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9696
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9697
F_TRAINER_FEMALE | 
#line 9698
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9699
        .items = { ITEM_FULL_RESTORE },
#line 9700
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 9702
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9704
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9703
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9706
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9708
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9707
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9710
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9712
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9711
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9714
    [TRAINER_SOPHIA] =
    {
#line 9715
        .trainerName = _("SOPHIA"),
#line 9716
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9717
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9718
F_TRAINER_FEMALE | 
#line 9719
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9720
        .items = { ITEM_FULL_RESTORE },
#line 9721
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9723
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9725
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9724
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9727
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9729
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9728
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9731
    [TRAINER_CATHERINE_2] =
    {
#line 9732
        .trainerName = _("CATHERINE"),
#line 9733
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9734
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9735
F_TRAINER_FEMALE | 
#line 9736
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9737
        .items = { ITEM_FULL_RESTORE },
#line 9738
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9740
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9742
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9741
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9744
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9746
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
#line 9745
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9748
    [TRAINER_CATHERINE_3] =
    {
#line 9749
        .trainerName = _("CATHERINE"),
#line 9750
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9751
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9752
F_TRAINER_FEMALE | 
#line 9753
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9754
        .items = { ITEM_FULL_RESTORE },
#line 9755
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9757
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9759
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9758
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9761
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9763
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
#line 9762
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9765
    [TRAINER_CATHERINE_4] =
    {
#line 9766
        .trainerName = _("CATHERINE"),
#line 9767
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9768
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9769
F_TRAINER_FEMALE | 
#line 9770
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9771
        .items = { ITEM_FULL_RESTORE },
#line 9772
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9774
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9776
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9775
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9778
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9780
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 9779
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9782
    [TRAINER_CATHERINE_5] =
    {
#line 9783
        .trainerName = _("CATHERINE"),
#line 9784
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
#line 9785
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender = 
#line 9786
F_TRAINER_FEMALE | 
#line 9787
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9788
        .items = { ITEM_FULL_RESTORE },
#line 9789
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9791
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9793
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9792
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9795
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9797
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
#line 9796
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9799
    [TRAINER_JULIO] =
    {
#line 9800
        .trainerName = _("JULIO"),
#line 9801
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 9802
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 9804
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9805
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9807
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9809
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9808
            .lvl = 21,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9811
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_5] =
    {
#line 9812
        .trainerName = _("GRUNT"),
#line 9813
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 9814
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender = 
#line 9816
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9817
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9819
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9821
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9820
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9823
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9825
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9824
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9827
    [TRAINER_CYNTHIA] =
    {
#line 9828
        .trainerName = _("CYNTHIA"),
#line 9829
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 9830
        .trainerPic = TRAINER_PIC_CYNTHIA,
        .encounterMusic_gender = 
#line 9831
F_TRAINER_FEMALE | 
#line 9832
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 9833
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9835
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9837
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9836
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9839
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9841
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9840
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9843
    [TRAINER_GRUNT_MT_PYRE_4] =
    {
#line 9844
        .trainerName = _("GRUNT"),
#line 9845
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 9846
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 9847
F_TRAINER_FEMALE | 
#line 9848
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 9849
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9851
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9853
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9852
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9855
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9857
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9856
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9859
    [TRAINER_GRUNT_JAGGED_PASS] =
    {
#line 9860
        .trainerName = _("GRUNT"),
#line 9861
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 9862
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 9864
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 9865
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9867
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9869
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9868
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9871
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9873
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 9872
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9875
    [TRAINER_MARC] =
    {
#line 9876
        .trainerName = _("MARC"),
#line 9877
        .trainerClass = TRAINER_CLASS_HIKER,
#line 9878
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 9880
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 9881
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9883
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9885
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 9884
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 9887
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9889
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 9888
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9891
    [TRAINER_BRENDEN] =
    {
#line 9892
        .trainerName = _("BRENDEN"),
#line 9893
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 9894
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 9896
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 9897
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9899
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9901
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9900
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9903
    [TRAINER_LILITH] =
    {
#line 9904
        .trainerName = _("LILITH"),
#line 9905
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 9906
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 9907
F_TRAINER_FEMALE | 
#line 9908
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9909
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9911
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9913
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 9912
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9915
    [TRAINER_CRISTIAN] =
    {
#line 9916
        .trainerName = _("CRISTIAN"),
#line 9917
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 9918
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 9920
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 9921
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9923
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9925
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 9924
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9927
    [TRAINER_SYLVIA] =
    {
#line 9928
        .trainerName = _("SYLVIA"),
#line 9929
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 9930
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 9931
F_TRAINER_FEMALE | 
#line 9932
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 9933
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9935
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9937
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9936
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9939
    [TRAINER_LEONARDO] =
    {
#line 9940
        .trainerName = _("LEONARDO"),
#line 9941
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 9942
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 9944
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9945
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9947
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9949
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9948
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9951
    [TRAINER_ATHENA] =
    {
#line 9952
        .trainerName = _("ATHENA"),
#line 9953
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 9954
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 9955
F_TRAINER_FEMALE | 
#line 9956
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 9957
        .items = { ITEM_HYPER_POTION },
#line 9958
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 9960
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9962
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9961
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9963
                MOVE_THUNDER,
                MOVE_THUNDER_WAVE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
#line 9967
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9969
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 9968
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 9970
                MOVE_SURF,
                MOVE_THIEF,
            },
            },
        },
    },
#line 9973
    [TRAINER_HARRISON] =
    {
#line 9974
        .trainerName = _("HARRISON"),
#line 9975
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 9976
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 9978
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 9979
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9981
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9983
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9982
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9985
    [TRAINER_GRUNT_MT_CHIMNEY_2] =
    {
#line 9986
        .trainerName = _("GRUNT"),
#line 9987
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 9988
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 9990
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 9991
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 9993
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 9995
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 9994
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 9997
    [TRAINER_CLARENCE] =
    {
#line 9998
        .trainerName = _("CLARENCE"),
#line 9999
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 10000
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 10002
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10003
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10005
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10007
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10006
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10009
    [TRAINER_TERRY] =
    {
#line 10010
        .trainerName = _("TERRY"),
#line 10011
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10012
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 10013
F_TRAINER_FEMALE | 
#line 10014
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10015
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10017
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10019
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10018
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10021
    [TRAINER_NATE] =
    {
#line 10022
        .trainerName = _("NATE"),
#line 10023
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 10024
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 10026
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 10027
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10029
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10031
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10030
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10033
    [TRAINER_KATHLEEN] =
    {
#line 10034
        .trainerName = _("KATHLEEN"),
#line 10035
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
#line 10036
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender = 
#line 10037
F_TRAINER_FEMALE | 
#line 10038
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 10039
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10041
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10043
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10042
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10045
    [TRAINER_CLIFFORD] =
    {
#line 10046
        .trainerName = _("CLIFFORD"),
#line 10047
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 10048
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 10050
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 10051
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10053
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10055
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10054
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10057
    [TRAINER_NICHOLAS] =
    {
#line 10058
        .trainerName = _("NICHOLAS"),
#line 10059
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10060
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 10062
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10065
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10067
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10066
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10069
    [TRAINER_GRUNT_SPACE_CENTER_3] =
    {
#line 10070
        .trainerName = _("GRUNT"),
#line 10071
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10072
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 10073
F_TRAINER_FEMALE | 
#line 10074
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10075
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10077
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10079
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10078
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10081
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10083
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10082
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10085
    [TRAINER_GRUNT_SPACE_CENTER_4] =
    {
#line 10086
        .trainerName = _("GRUNT"),
#line 10087
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10088
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10090
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10091
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10093
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10095
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10094
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10097
    [TRAINER_GRUNT_SPACE_CENTER_5] =
    {
#line 10098
        .trainerName = _("GRUNT"),
#line 10099
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10100
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10102
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10103
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10105
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10107
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10106
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10109
    [TRAINER_GRUNT_SPACE_CENTER_6] =
    {
#line 10110
        .trainerName = _("GRUNT"),
#line 10111
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10112
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10114
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10115
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10117
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10119
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10118
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10121
    [TRAINER_GRUNT_SPACE_CENTER_7] =
    {
#line 10122
        .trainerName = _("GRUNT"),
#line 10123
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 10124
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 10126
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10127
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10129
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10130
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10133
    [TRAINER_MACEY] =
    {
#line 10134
        .trainerName = _("MACEY"),
#line 10135
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 10136
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 10137
F_TRAINER_FEMALE | 
#line 10138
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10141
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10142
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10145
    [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
    {
#line 10146
        .trainerName = _("BRENDAN"),
#line 10147
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10148
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10150
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10151
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10153
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10155
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10154
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10157
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10159
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10158
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10161
    [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
    {
#line 10162
        .trainerName = _("BRENDAN"),
#line 10163
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10164
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10166
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10167
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10169
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10171
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10170
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10173
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10175
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10174
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10177
    [TRAINER_PAXTON] =
    {
#line 10178
        .trainerName = _("PAXTON"),
#line 10179
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 10180
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender = 
#line 10182
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 10183
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10185
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10187
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10186
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10189
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10191
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10190
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10193
    [TRAINER_ISABELLA] =
    {
#line 10194
        .trainerName = _("ISABELLA"),
#line 10195
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 10196
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 10197
F_TRAINER_FEMALE | 
#line 10198
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 10199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10201
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10203
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10202
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10205
    [TRAINER_GRUNT_WEATHER_INST_5] =
    {
#line 10206
        .trainerName = _("GRUNT"),
#line 10207
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
#line 10208
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender = 
#line 10209
F_TRAINER_FEMALE | 
#line 10210
            TRAINER_ENCOUNTER_MUSIC_AQUA,
#line 10211
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10213
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10215
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10214
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10217
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10219
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10218
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10221
    [TRAINER_TABITHA_MT_CHIMNEY] =
    {
#line 10222
        .trainerName = _("TABITHA"),
#line 10223
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 10224
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 10226
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10227
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10229
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10231
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10230
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10233
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10235
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10234
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10237
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10239
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10238
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10241
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10243
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10242
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10245
    [TRAINER_JONATHAN] =
    {
#line 10246
        .trainerName = _("JONATHAN"),
#line 10247
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 10248
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 10250
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 10251
        .items = { ITEM_HYPER_POTION },
#line 10252
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10254
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10256
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10255
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10258
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10260
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10259
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10262
    [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
    {
#line 10263
        .trainerName = _("BRENDAN"),
#line 10264
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10265
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 10267
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10268
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10270
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10272
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10271
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10274
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10276
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10275
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10278
    [TRAINER_MAY_RUSTBORO_MUDKIP] =
    {
#line 10279
        .trainerName = _("MAY"),
#line 10280
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 10281
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 10282
F_TRAINER_FEMALE | 
#line 10283
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10284
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10286
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10288
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10287
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10290
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10292
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10291
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10294
    [TRAINER_MAXIE_MAGMA_HIDEOUT] =
    {
#line 10295
        .trainerName = _("MAXIE"),
#line 10296
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 10297
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 10299
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10300
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 10301
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10303
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10305
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10304
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10307
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10309
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10308
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10311
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10313
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10312
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10315
    [TRAINER_MAXIE_MT_CHIMNEY] =
    {
#line 10316
        .trainerName = _("MAXIE"),
#line 10317
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 10318
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 10320
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 10321
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
#line 10322
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10324
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10326
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10325
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10328
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10330
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10329
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10332
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10334
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 10333
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10336
    [TRAINER_TIANA] =
    {
#line 10337
        .trainerName = _("TIANA"),
#line 10338
        .trainerClass = TRAINER_CLASS_LASS,
#line 10339
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10340
F_TRAINER_FEMALE | 
#line 10341
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10342
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10344
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10346
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10345
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10348
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10350
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10349
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10352
    [TRAINER_HALEY_1] =
    {
#line 10353
        .trainerName = _("HALEY"),
#line 10354
        .trainerClass = TRAINER_CLASS_LASS,
#line 10355
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10356
F_TRAINER_FEMALE | 
#line 10357
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10358
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10360
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10362
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10361
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10364
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10366
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10365
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10368
    [TRAINER_JANICE] =
    {
#line 10369
        .trainerName = _("JANICE"),
#line 10370
        .trainerClass = TRAINER_CLASS_LASS,
#line 10371
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10372
F_TRAINER_FEMALE | 
#line 10373
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10374
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10376
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10378
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10377
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10380
    [TRAINER_VIVI] =
    {
#line 10381
        .trainerName = _("VIVI"),
#line 10382
        .trainerClass = TRAINER_CLASS_WINSTRATE,
#line 10383
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10384
F_TRAINER_FEMALE | 
#line 10385
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10386
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10388
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10390
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10389
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10392
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10394
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10393
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10396
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10398
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10397
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10400
    [TRAINER_HALEY_2] =
    {
#line 10401
        .trainerName = _("HALEY"),
#line 10402
        .trainerClass = TRAINER_CLASS_LASS,
#line 10403
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10404
F_TRAINER_FEMALE | 
#line 10405
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10406
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10408
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10410
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10409
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10412
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10414
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10413
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10416
    [TRAINER_HALEY_3] =
    {
#line 10417
        .trainerName = _("HALEY"),
#line 10418
        .trainerClass = TRAINER_CLASS_LASS,
#line 10419
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10420
F_TRAINER_FEMALE | 
#line 10421
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10422
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10424
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10426
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10425
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10428
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10430
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10429
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10432
    [TRAINER_HALEY_4] =
    {
#line 10433
        .trainerName = _("HALEY"),
#line 10434
        .trainerClass = TRAINER_CLASS_LASS,
#line 10435
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10436
F_TRAINER_FEMALE | 
#line 10437
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10438
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10440
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10442
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10441
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10444
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10446
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10445
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10448
    [TRAINER_HALEY_5] =
    {
#line 10449
        .trainerName = _("HALEY"),
#line 10450
        .trainerClass = TRAINER_CLASS_LASS,
#line 10451
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10452
F_TRAINER_FEMALE | 
#line 10453
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10454
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10456
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10458
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10457
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10460
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10462
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10461
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10464
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10466
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10465
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10468
    [TRAINER_SALLY] =
    {
#line 10469
        .trainerName = _("SALLY"),
#line 10470
        .trainerClass = TRAINER_CLASS_LASS,
#line 10471
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10472
F_TRAINER_FEMALE | 
#line 10473
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10474
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10476
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10478
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10477
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10480
    [TRAINER_ROBIN] =
    {
#line 10481
        .trainerName = _("ROBIN"),
#line 10482
        .trainerClass = TRAINER_CLASS_LASS,
#line 10483
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10484
F_TRAINER_FEMALE | 
#line 10485
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10486
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10488
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10490
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10489
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10492
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10494
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10493
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10496
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10498
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10497
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10500
    [TRAINER_ANDREA] =
    {
#line 10501
        .trainerName = _("ANDREA"),
#line 10502
        .trainerClass = TRAINER_CLASS_LASS,
#line 10503
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10504
F_TRAINER_FEMALE | 
#line 10505
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10506
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10508
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10510
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10509
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10512
    [TRAINER_CRISSY] =
    {
#line 10513
        .trainerName = _("CRISSY"),
#line 10514
        .trainerClass = TRAINER_CLASS_LASS,
#line 10515
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender = 
#line 10516
F_TRAINER_FEMALE | 
#line 10517
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 10518
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10520
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10522
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10521
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10524
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10526
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 10525
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10528
    [TRAINER_RICK] =
    {
#line 10529
        .trainerName = _("RICK"),
#line 10530
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10531
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10533
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10534
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10536
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10538
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10537
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10540
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10542
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10541
            .lvl = 4,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10544
    [TRAINER_LYLE] =
    {
#line 10545
        .trainerName = _("LYLE"),
#line 10546
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10547
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10549
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10550
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10552
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10554
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10553
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10556
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10558
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10557
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10560
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10562
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10561
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10564
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10566
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10565
            .lvl = 3,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10568
    [TRAINER_JOSE] =
    {
#line 10569
        .trainerName = _("JOSE"),
#line 10570
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10571
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10573
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10574
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10576
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10578
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10577
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10580
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10582
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 10581
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10584
    [TRAINER_DOUG] =
    {
#line 10585
        .trainerName = _("DOUG"),
#line 10586
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10587
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10589
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10590
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10592
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10594
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10593
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10596
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10598
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10597
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10600
    [TRAINER_GREG] =
    {
#line 10601
        .trainerName = _("GREG"),
#line 10602
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10603
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10605
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10606
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10608
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10610
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10609
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10612
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10614
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10613
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10616
    [TRAINER_KENT] =
    {
#line 10617
        .trainerName = _("KENT"),
#line 10618
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10619
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10621
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10622
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10624
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10626
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10625
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10628
    [TRAINER_JAMES_1] =
    {
#line 10629
        .trainerName = _("JAMES"),
#line 10630
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10631
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10633
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10634
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10636
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10638
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10637
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10640
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10642
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10641
            .lvl = 6,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10644
    [TRAINER_JAMES_2] =
    {
#line 10645
        .trainerName = _("JAMES"),
#line 10646
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10647
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10649
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10650
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10652
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10654
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10653
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10656
    [TRAINER_JAMES_3] =
    {
#line 10657
        .trainerName = _("JAMES"),
#line 10658
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10659
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10661
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10662
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10664
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10666
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10665
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10668
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10670
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10669
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10672
    [TRAINER_JAMES_4] =
    {
#line 10673
        .trainerName = _("JAMES"),
#line 10674
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10675
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10677
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10678
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10680
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10682
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10681
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10684
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10686
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10685
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10688
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10690
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10689
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10692
    [TRAINER_JAMES_5] =
    {
#line 10693
        .trainerName = _("JAMES"),
#line 10694
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
#line 10695
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender = 
#line 10697
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 10698
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10700
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10702
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10701
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10704
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10706
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10705
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10708
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10710
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10709
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10712
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10714
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10713
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10716
    [TRAINER_BRICE] =
    {
#line 10717
        .trainerName = _("BRICE"),
#line 10718
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10719
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10721
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10722
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10724
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10726
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10725
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10728
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10730
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10729
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10732
    [TRAINER_TRENT_1] =
    {
#line 10733
        .trainerName = _("TRENT"),
#line 10734
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10735
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10737
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10738
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10740
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10742
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10741
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10744
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10746
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10745
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10748
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10750
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10749
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10752
    [TRAINER_LENNY] =
    {
#line 10753
        .trainerName = _("LENNY"),
#line 10754
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10755
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10757
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10758
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10760
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10762
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10761
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10764
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10766
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10765
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10768
    [TRAINER_LUCAS_1] =
    {
#line 10769
        .trainerName = _("LUCAS"),
#line 10770
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10771
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10773
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10774
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10776
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10778
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10777
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10780
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10782
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10781
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10784
    [TRAINER_ALAN] =
    {
#line 10785
        .trainerName = _("ALAN"),
#line 10786
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10787
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10789
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10790
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10792
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10794
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10793
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10796
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10798
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10797
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10800
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10802
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10801
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10804
    [TRAINER_CLARK] =
    {
#line 10805
        .trainerName = _("CLARK"),
#line 10806
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10807
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10809
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10810
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10812
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10814
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10813
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10816
    [TRAINER_ERIC] =
    {
#line 10817
        .trainerName = _("ERIC"),
#line 10818
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10819
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10821
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10822
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10824
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10825
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10828
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10829
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10832
    [TRAINER_LUCAS_2] =
    {
#line 10833
        .trainerName = _("LUCAS"),
#line 10834
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10835
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10837
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10838
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 10840
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10842
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10841
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10843
                MOVE_WATER_GUN,
            },
            },
        },
    },
#line 10846
    [TRAINER_MIKE_1] =
    {
#line 10847
        .trainerName = _("MIKE"),
#line 10848
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10849
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10851
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10852
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10854
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10856
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10855
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10857
                MOVE_GUST,
                MOVE_GROWL,
            },
            },
            {
#line 10860
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10862
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10861
            .lvl = 10,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 10863
                MOVE_BITE,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
#line 10866
    [TRAINER_MIKE_2] =
    {
#line 10867
        .trainerName = _("MIKE"),
#line 10868
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10869
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10871
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10872
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 10874
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10876
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10875
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10878
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10880
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10879
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10882
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10884
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10883
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10886
    [TRAINER_TRENT_2] =
    {
#line 10887
        .trainerName = _("TRENT"),
#line 10888
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10889
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10891
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10892
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10894
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10896
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10895
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10898
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10900
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10899
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10902
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10904
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10903
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10906
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10908
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 10907
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10910
    [TRAINER_TRENT_3] =
    {
#line 10911
        .trainerName = _("TRENT"),
#line 10912
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10913
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10915
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10916
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10918
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10920
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10919
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10922
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10924
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10923
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10926
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10928
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10927
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10930
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10932
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 10931
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10934
    [TRAINER_TRENT_4] =
    {
#line 10935
        .trainerName = _("TRENT"),
#line 10936
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10937
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10939
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10940
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10942
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10944
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10943
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10946
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10948
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10947
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10950
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10952
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10951
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10954
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10956
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 10955
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10958
    [TRAINER_TRENT_5] =
    {
#line 10959
        .trainerName = _("TRENT"),
#line 10960
        .trainerClass = TRAINER_CLASS_HIKER,
#line 10961
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 10963
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 10964
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 10966
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10968
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10967
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10970
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10972
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10971
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10974
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10976
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10975
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10978
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10980
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 10979
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10982
    [TRAINER_DEZ_AND_LUKE] =
    {
#line 10983
        .trainerName = _("DEZ & LUKE"),
#line 10984
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 10985
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 10987
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 10988
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 10990
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10992
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10991
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 10994
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 10996
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 10995
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 10998
    [TRAINER_LEA_AND_JED] =
    {
#line 10999
        .trainerName = _("LEA & JED"),
#line 11000
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11001
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11003
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11004
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11006
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11008
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11007
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11010
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11012
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11011
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11014
    [TRAINER_KIRA_AND_DAN_1] =
    {
#line 11015
        .trainerName = _("KIRA & DAN"),
#line 11016
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11017
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11019
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11020
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11022
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11024
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11023
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11026
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11028
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11027
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11030
    [TRAINER_KIRA_AND_DAN_2] =
    {
#line 11031
        .trainerName = _("KIRA & DAN"),
#line 11032
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11033
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11035
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11036
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11038
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11040
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11039
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11042
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11044
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 11043
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11046
    [TRAINER_KIRA_AND_DAN_3] =
    {
#line 11047
        .trainerName = _("KIRA & DAN"),
#line 11048
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11049
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11051
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11052
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11054
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11056
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11055
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11058
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11060
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 11059
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11062
    [TRAINER_KIRA_AND_DAN_4] =
    {
#line 11063
        .trainerName = _("KIRA & DAN"),
#line 11064
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11065
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11067
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11068
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11070
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11072
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11071
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11074
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11076
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11075
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11078
    [TRAINER_KIRA_AND_DAN_5] =
    {
#line 11079
        .trainerName = _("KIRA & DAN"),
#line 11080
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11081
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11083
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11084
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11086
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11088
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11087
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11090
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11092
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 11091
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11094
    [TRAINER_JOHANNA] =
    {
#line 11095
        .trainerName = _("JOHANNA"),
#line 11096
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 11097
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 11098
F_TRAINER_FEMALE | 
#line 11099
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11100
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11102
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11104
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11103
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11106
    [TRAINER_GERALD] =
    {
#line 11107
        .trainerName = _("GERALD"),
#line 11108
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11109
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 11111
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11112
        .items = { ITEM_HYPER_POTION },
#line 11113
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11115
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11117
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11116
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11118
                MOVE_LANZALLAMAS,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
                MOVE_BIND,
            },
            },
        },
    },
#line 11123
    [TRAINER_VIVIAN] =
    {
#line 11124
        .trainerName = _("VIVIAN"),
#line 11125
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 11126
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 11127
F_TRAINER_FEMALE | 
#line 11128
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11129
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11131
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11133
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11132
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11134
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_THUNDER_PUNCH,
            },
            },
            {
#line 11139
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11141
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11140
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11142
                MOVE_THUNDER_PUNCH,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_MEDITATE,
            },
            },
        },
    },
#line 11147
    [TRAINER_DANIELLE] =
    {
#line 11148
        .trainerName = _("DANIELLE"),
#line 11149
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 11150
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 11151
F_TRAINER_FEMALE | 
#line 11152
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11153
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11155
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11157
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11156
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11158
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_FIRE_PUNCH,
            },
            },
        },
    },
#line 11163
    [TRAINER_HIDEO] =
    {
#line 11164
        .trainerName = _("HIDEO"),
#line 11165
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11166
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11168
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11169
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11171
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11173
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11172
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11174
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 11179
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11181
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11180
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11182
                MOVE_TACKLE,
                MOVE_POISON_GAS,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
#line 11187
    [TRAINER_KEIGO] =
    {
#line 11188
        .trainerName = _("KEIGO"),
#line 11189
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11190
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11192
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11193
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11195
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11197
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11196
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11198
                MOVE_POISON_GAS,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
#line 11203
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11205
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11204
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11206
                MOVE_SAND_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_FURY_CUTTER,
                MOVE_SWORDS_DANCE,
            },
            },
        },
    },
#line 11211
    [TRAINER_RILEY] =
    {
#line 11212
        .trainerName = _("RILEY"),
#line 11213
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 11214
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 11216
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 11217
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11219
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11221
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11220
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11222
                MOVE_LEECH_LIFE,
                MOVE_FURY_SWIPES,
                MOVE_MIND_READER,
                MOVE_DIG,
            },
            },
            {
#line 11227
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11229
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11228
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11230
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
#line 11235
    [TRAINER_FLINT] =
    {
#line 11236
        .trainerName = _("FLINT"),
#line 11237
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 11238
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 11240
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11241
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11243
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11245
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11244
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11247
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11249
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11248
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11251
    [TRAINER_ASHLEY] =
    {
#line 11252
        .trainerName = _("ASHLEY"),
#line 11253
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 11254
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 11255
F_TRAINER_FEMALE | 
#line 11256
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11257
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11259
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11261
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11260
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11263
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11265
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11264
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11267
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11269
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11268
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11271
    [TRAINER_WALLY_MAUVILLE] =
    {
#line 11272
        .trainerName = _("WALLY"),
#line 11273
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11274
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11276
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11277
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11279
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11281
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 11280
            .lvl = 16,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11283
    [TRAINER_WALLY_VR_2] =
    {
#line 11284
        .trainerName = _("WALLY"),
#line 11285
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11286
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11288
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11289
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11290
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11292
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11294
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11293
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11295
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11300
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11302
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11301
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11303
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11308
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11310
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11309
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11311
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11316
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11318
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11317
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11319
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 11324
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11326
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11325
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11327
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11332
    [TRAINER_WALLY_VR_3] =
    {
#line 11333
        .trainerName = _("WALLY"),
#line 11334
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11335
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11337
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11338
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11339
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11341
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11343
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11342
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11344
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11349
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11351
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11350
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11352
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11357
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11359
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11358
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11360
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11365
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11367
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11366
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11368
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 11373
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11375
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11374
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11376
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11381
    [TRAINER_WALLY_VR_4] =
    {
#line 11382
        .trainerName = _("WALLY"),
#line 11383
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11384
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11386
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11387
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11388
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11390
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11392
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11391
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11393
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11398
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11400
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11399
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11401
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11406
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11408
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11407
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11409
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11414
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11416
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11415
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11417
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 11422
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11424
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11423
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11425
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11430
    [TRAINER_WALLY_VR_5] =
    {
#line 11431
        .trainerName = _("WALLY"),
#line 11432
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11433
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender = 
#line 11435
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11436
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 11437
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 11439
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11441
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11440
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11442
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
#line 11447
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11449
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11448
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11450
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
#line 11455
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11457
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11456
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11458
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
#line 11463
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11465
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11464
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11466
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 11471
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11473
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
#line 11472
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11474
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
#line 11479
    [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
    {
#line 11480
        .trainerName = _("BRENDAN"),
#line 11481
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11482
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11484
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11485
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11487
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11489
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11488
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11491
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11493
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11492
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11495
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11497
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11496
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11499
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11501
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11500
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11503
    [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
    {
#line 11504
        .trainerName = _("BRENDAN"),
#line 11505
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11506
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11508
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11509
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11511
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11513
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11512
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11515
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11517
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11516
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11519
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11521
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11520
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11523
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11525
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11524
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11527
    [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
    {
#line 11528
        .trainerName = _("BRENDAN"),
#line 11529
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11530
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 11532
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 11533
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11535
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11537
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11536
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11539
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11541
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11540
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11543
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11545
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11544
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11547
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11549
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11548
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11551
    [TRAINER_MAY_LILYCOVE_MUDKIP] =
    {
#line 11552
        .trainerName = _("MAY"),
#line 11553
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11554
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11555
F_TRAINER_FEMALE | 
#line 11556
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11557
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11559
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11561
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11560
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11563
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11565
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11564
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11567
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11569
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11568
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11570
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRIATAQUE,
                MOVE_SCREECH,
            },
            },
            {
#line 11571
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11573
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11572
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11575
    [TRAINER_MAY_LILYCOVE_TREECKO] =
    {
#line 11576
        .trainerName = _("MAY"),
#line 11577
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11578
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11579
F_TRAINER_FEMALE | 
#line 11580
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11581
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11583
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11585
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11584
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11587
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11589
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11588
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11591
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11593
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11592
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11595
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11597
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11596
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11599
    [TRAINER_MAY_LILYCOVE_TORCHIC] =
    {
#line 11600
        .trainerName = _("MAY"),
#line 11601
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11602
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 11603
F_TRAINER_FEMALE | 
#line 11604
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 11605
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 11607
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11609
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11608
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11611
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11613
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11612
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11615
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11617
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 11616
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11619
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11621
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11620
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11623
    [TRAINER_JONAH] =
    {
#line 11624
        .trainerName = _("JONAH"),
#line 11625
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11626
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11628
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11629
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11631
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11633
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11632
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11635
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11637
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11636
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11639
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11641
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11640
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11643
    [TRAINER_HENRY] =
    {
#line 11644
        .trainerName = _("HENRY"),
#line 11645
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11646
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11648
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11649
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11651
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11653
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11652
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11655
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11657
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11656
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11659
    [TRAINER_ROGER] =
    {
#line 11660
        .trainerName = _("ROGER"),
#line 11661
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11662
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11664
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11665
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11667
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11669
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11668
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11671
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11673
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11672
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11675
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11677
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11676
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11679
    [TRAINER_ALEXA] =
    {
#line 11680
        .trainerName = _("ALEXA"),
#line 11681
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11682
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 11683
F_TRAINER_FEMALE | 
#line 11684
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11685
        .items = { ITEM_FULL_RESTORE },
#line 11686
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11688
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11690
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11689
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11692
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11694
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11693
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11696
    [TRAINER_RUBEN] =
    {
#line 11697
        .trainerName = _("RUBEN"),
#line 11698
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 11699
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 11701
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11702
        .items = { ITEM_HYPER_POTION },
#line 11703
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11705
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11707
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11706
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11709
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11711
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 11710
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11713
    [TRAINER_KOJI_1] =
    {
#line 11714
        .trainerName = _("KOJI"),
#line 11715
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 11716
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 11718
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11719
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11721
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11723
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11722
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11725
    [TRAINER_WAYNE] =
    {
#line 11726
        .trainerName = _("WAYNE"),
#line 11727
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 11728
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 11730
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 11731
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 11733
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11735
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11734
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11737
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11739
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11738
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11741
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11743
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11742
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11745
    [TRAINER_AIDAN] =
    {
#line 11746
        .trainerName = _("AIDAN"),
#line 11747
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 11748
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 11750
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 11751
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11753
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11755
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11754
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11757
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11759
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11758
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11761
    [TRAINER_REED] =
    {
#line 11762
        .trainerName = _("REED"),
#line 11763
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 11764
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 11766
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 11767
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11769
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11771
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11770
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11773
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11775
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11774
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11777
    [TRAINER_TISHA] =
    {
#line 11778
        .trainerName = _("TISHA"),
#line 11779
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 11780
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 11781
F_TRAINER_FEMALE | 
#line 11782
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 11783
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 11785
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11787
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11786
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11789
    [TRAINER_TORI_AND_TIA] =
    {
#line 11790
        .trainerName = _("TORI & TIA"),
#line 11791
        .trainerClass = TRAINER_CLASS_TWINS,
#line 11792
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender = 
#line 11794
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11795
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11797
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11799
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11798
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 11801
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11803
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11802
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 11805
    [TRAINER_KIM_AND_IRIS] =
    {
#line 11806
        .trainerName = _("KIM & IRIS"),
#line 11807
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 11808
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 11810
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11811
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11813
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11815
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11814
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11816
                MOVE_SING,
                MOVE_FURY_ATTACK,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 11821
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11823
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11822
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11824
                MOVE_LANZALLAMAS,
                MOVE_TAKE_DOWN,
                MOVE_REST,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 11829
    [TRAINER_TYRA_AND_IVY] =
    {
#line 11830
        .trainerName = _("TYRA & IVY"),
#line 11831
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
#line 11832
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender = 
#line 11834
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 11835
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11837
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11839
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11838
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11840
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
                MOVE_MEGA_DRAIN,
                MOVE_LEECH_SEED,
            },
            },
            {
#line 11845
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11847
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11846
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11848
                MOVE_DEFENSE_CURL,
                MOVE_ROLLOUT,
                MOVE_MUD_SPORT,
                MOVE_ROCK_THROW,
            },
            },
        },
    },
#line 11853
    [TRAINER_MEL_AND_PAUL] =
    {
#line 11854
        .trainerName = _("MEL & PAUL"),
#line 11855
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
#line 11856
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender = 
#line 11858
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 11859
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11861
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11863
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11862
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11864
                MOVE_GUST,
                MOVE_PSYBEAM,
                MOVE_TOXIC,
                MOVE_PROTECT,
            },
            },
            {
#line 11869
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11871
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 11870
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11872
                MOVE_GUST,
                MOVE_MEGA_DRAIN,
                MOVE_ATTRACT,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
#line 11877
    [TRAINER_JOHN_AND_JAY_1] =
    {
#line 11878
        .trainerName = _("JOHN & JAY"),
#line 11879
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11880
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11882
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11883
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11885
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11887
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11886
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11888
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11893
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11895
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 11894
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11896
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 11901
    [TRAINER_JOHN_AND_JAY_2] =
    {
#line 11902
        .trainerName = _("JOHN & JAY"),
#line 11903
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11904
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11906
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11907
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11909
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11911
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 11910
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11912
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11917
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11919
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 11918
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11920
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 11925
    [TRAINER_JOHN_AND_JAY_3] =
    {
#line 11926
        .trainerName = _("JOHN & JAY"),
#line 11927
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11928
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11930
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11931
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11933
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11935
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 11934
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11936
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11941
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11943
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
#line 11942
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11944
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 11949
    [TRAINER_JOHN_AND_JAY_4] =
    {
#line 11950
        .trainerName = _("JOHN & JAY"),
#line 11951
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11952
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11954
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11955
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_FORCE_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11957
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11959
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 11958
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11960
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11965
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11967
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
#line 11966
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11968
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 11973
    [TRAINER_JOHN_AND_JAY_5] =
    {
#line 11974
        .trainerName = _("JOHN & JAY"),
#line 11975
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
#line 11976
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender = 
#line 11978
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 11979
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 11981
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11983
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 11982
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11984
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
#line 11989
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 11991
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 11990
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 11992
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
#line 11997
    [TRAINER_RELI_AND_IAN] =
    {
#line 11998
        .trainerName = _("RELI & IAN"),
#line 11999
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12000
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12002
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12003
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12005
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12007
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12006
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12009
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12011
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12010
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12013
    [TRAINER_LILA_AND_ROY_1] =
    {
#line 12014
        .trainerName = _("LILA & ROY"),
#line 12015
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12016
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12018
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12019
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12021
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12023
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12022
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12025
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12027
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12026
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12029
    [TRAINER_LILA_AND_ROY_2] =
    {
#line 12030
        .trainerName = _("LILA & ROY"),
#line 12031
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12032
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12034
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12035
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12037
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12039
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12038
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12041
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12043
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12042
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12045
    [TRAINER_LILA_AND_ROY_3] =
    {
#line 12046
        .trainerName = _("LILA & ROY"),
#line 12047
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12048
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12050
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12051
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12053
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12055
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12054
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12057
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12059
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12058
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12061
    [TRAINER_LILA_AND_ROY_4] =
    {
#line 12062
        .trainerName = _("LILA & ROY"),
#line 12063
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12064
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12066
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12067
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12069
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12071
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12070
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12073
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12075
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12074
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12077
    [TRAINER_LILA_AND_ROY_5] =
    {
#line 12078
        .trainerName = _("LILA & ROY"),
#line 12079
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12080
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12082
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12085
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12086
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12089
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12091
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12090
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12093
    [TRAINER_LISA_AND_RAY] =
    {
#line 12094
        .trainerName = _("LISA & RAY"),
#line 12095
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
#line 12096
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender = 
#line 12098
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12099
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12101
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12103
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12102
            .lvl = 27,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12105
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12107
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12106
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12109
    [TRAINER_CHRIS] =
    {
#line 12110
        .trainerName = _("CHRIS"),
#line 12111
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12112
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12114
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12115
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12117
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12119
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12118
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12121
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12123
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12122
            .lvl = 20,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12125
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12127
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12126
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12129
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12131
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12130
            .lvl = 23,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12133
    [TRAINER_DAWSON] =
    {
#line 12134
        .trainerName = _("DAWSON"),
#line 12135
        .trainerClass = TRAINER_CLASS_RICH_BOY,
#line 12136
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender = 
#line 12138
            TRAINER_ENCOUNTER_MUSIC_RICH,
#line 12139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12141
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12141
            .heldItem = ITEM_NUGGET,
#line 12143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12142
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12145
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12146
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12149
    [TRAINER_SARAH] =
    {
#line 12150
        .trainerName = _("SARAH"),
#line 12151
        .trainerClass = TRAINER_CLASS_LADY,
#line 12152
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender = 
#line 12153
F_TRAINER_FEMALE | 
#line 12154
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12155
        .items = { ITEM_FULL_RESTORE },
#line 12156
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12158
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12160
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12159
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12162
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12162
            .heldItem = ITEM_NUGGET,
#line 12164
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12163
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12166
    [TRAINER_DARIAN] =
    {
#line 12167
        .trainerName = _("DARIAN"),
#line 12168
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12169
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12171
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12172
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12174
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12176
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12175
            .lvl = 9,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12178
    [TRAINER_HAILEY] =
    {
#line 12179
        .trainerName = _("HAILEY"),
#line 12180
        .trainerClass = TRAINER_CLASS_TUBER_F,
#line 12181
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender = 
#line 12182
F_TRAINER_FEMALE | 
#line 12183
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12184
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12186
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12188
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12187
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12190
    [TRAINER_CHANDLER] =
    {
#line 12191
        .trainerName = _("CHANDLER"),
#line 12192
        .trainerClass = TRAINER_CLASS_TUBER_M,
#line 12193
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender = 
#line 12195
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12196
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12198
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12200
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12199
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12202
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12204
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12203
            .lvl = 12,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12206
    [TRAINER_KALEB] =
    {
#line 12207
        .trainerName = _("KALEB"),
#line 12208
        .trainerClass = TRAINER_CLASS_POKEFAN,
#line 12209
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender = 
#line 12211
            TRAINER_ENCOUNTER_MUSIC_TWINS,
#line 12212
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12214
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12214
            .heldItem = ITEM_ORAN_BERRY,
#line 12216
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12215
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12218
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12218
            .heldItem = ITEM_ORAN_BERRY,
#line 12220
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12219
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12222
    [TRAINER_JOSEPH] =
    {
#line 12223
        .trainerName = _("JOSEPH"),
#line 12224
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 12225
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 12227
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12228
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12230
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12232
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12231
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12234
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12236
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12235
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12238
    [TRAINER_ALYSSA] =
    {
#line 12239
        .trainerName = _("ALYSSA"),
#line 12240
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 12241
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 12242
F_TRAINER_FEMALE | 
#line 12243
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12244
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12246
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12248
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12247
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12250
    [TRAINER_MARCOS] =
    {
#line 12251
        .trainerName = _("MARCOS"),
#line 12252
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 12253
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 12255
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12256
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12258
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12260
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 12259
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12262
    [TRAINER_RHETT] =
    {
#line 12263
        .trainerName = _("RHETT"),
#line 12264
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 12265
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 12267
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12268
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12270
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12272
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 12271
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12274
    [TRAINER_TYRON] =
    {
#line 12275
        .trainerName = _("TYRON"),
#line 12276
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12277
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12279
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12280
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12282
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12284
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12283
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12286
    [TRAINER_CELINA] =
    {
#line 12287
        .trainerName = _("CELINA"),
#line 12288
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 12289
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 12290
F_TRAINER_FEMALE | 
#line 12291
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12292
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12294
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12296
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12295
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12298
    [TRAINER_BIANCA] =
    {
#line 12299
        .trainerName = _("BIANCA"),
#line 12300
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12301
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12302
F_TRAINER_FEMALE | 
#line 12303
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12304
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12306
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12308
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12307
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12310
    [TRAINER_HAYDEN] =
    {
#line 12311
        .trainerName = _("HAYDEN"),
#line 12312
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 12313
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 12315
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12316
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12318
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12320
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12319
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12322
    [TRAINER_SOPHIE] =
    {
#line 12323
        .trainerName = _("SOPHIE"),
#line 12324
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12325
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12326
F_TRAINER_FEMALE | 
#line 12327
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12328
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12330
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12332
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12331
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12334
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12336
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12335
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12338
    [TRAINER_COBY] =
    {
#line 12339
        .trainerName = _("COBY"),
#line 12340
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12341
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12343
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12344
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12346
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12348
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12347
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12350
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12352
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12351
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12354
    [TRAINER_LAWRENCE] =
    {
#line 12355
        .trainerName = _("LAWRENCE"),
#line 12356
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12357
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12359
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12360
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12362
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12364
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12363
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12366
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12368
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12367
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12370
    [TRAINER_WYATT] =
    {
#line 12371
        .trainerName = _("WYATT"),
#line 12372
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
#line 12373
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender = 
#line 12375
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12376
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12378
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12380
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12379
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12382
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12384
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12383
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12386
    [TRAINER_ANGELINA] =
    {
#line 12387
        .trainerName = _("ANGELINA"),
#line 12388
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12389
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12390
F_TRAINER_FEMALE | 
#line 12391
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12392
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12394
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12396
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12395
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12398
            .species = SPECIES_MARILL,
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
    [TRAINER_KAI] =
    {
#line 12403
        .trainerName = _("KAI"),
#line 12404
        .trainerClass = TRAINER_CLASS_FISHERMAN,
#line 12405
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender = 
#line 12407
            TRAINER_ENCOUNTER_MUSIC_HIKER,
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
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12414
    [TRAINER_CHARLOTTE] =
    {
#line 12415
        .trainerName = _("CHARLOTTE"),
#line 12416
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12417
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12418
F_TRAINER_FEMALE | 
#line 12419
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12420
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12422
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12424
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12423
            .lvl = 19,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12426
    [TRAINER_DEANDRE] =
    {
#line 12427
        .trainerName = _("DEANDRE"),
#line 12428
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 12429
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 12431
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12432
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12434
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12436
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12435
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12438
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12440
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12439
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12442
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12444
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12443
            .lvl = 14,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12446
    [TRAINER_GRUNT_MAGMA_HIDEOUT_1] =
    {
#line 12447
        .trainerName = _("GRUNT"),
#line 12448
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12449
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12451
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12452
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12454
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12456
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12455
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12458
    [TRAINER_GRUNT_MAGMA_HIDEOUT_2] =
    {
#line 12459
        .trainerName = _("GRUNT"),
#line 12460
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12461
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12463
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12464
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12466
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12468
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12467
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12470
    [TRAINER_GRUNT_MAGMA_HIDEOUT_3] =
    {
#line 12471
        .trainerName = _("GRUNT"),
#line 12472
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12473
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12475
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12476
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12478
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12480
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12479
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12482
    [TRAINER_GRUNT_MAGMA_HIDEOUT_4] =
    {
#line 12483
        .trainerName = _("GRUNT"),
#line 12484
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12485
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12487
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12488
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12490
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12492
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12491
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12494
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12496
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12495
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12498
    [TRAINER_GRUNT_MAGMA_HIDEOUT_5] =
    {
#line 12499
        .trainerName = _("GRUNT"),
#line 12500
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12501
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12503
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12504
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12506
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12508
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12507
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12510
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12512
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12511
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12514
    [TRAINER_GRUNT_MAGMA_HIDEOUT_6] =
    {
#line 12515
        .trainerName = _("GRUNT"),
#line 12516
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12517
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12519
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12520
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12522
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12524
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12523
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12526
    [TRAINER_GRUNT_MAGMA_HIDEOUT_7] =
    {
#line 12527
        .trainerName = _("GRUNT"),
#line 12528
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12529
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12531
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12532
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12534
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12536
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12535
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12538
    [TRAINER_GRUNT_MAGMA_HIDEOUT_8] =
    {
#line 12539
        .trainerName = _("GRUNT"),
#line 12540
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12541
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12543
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12544
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12546
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12548
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12547
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12550
    [TRAINER_GRUNT_MAGMA_HIDEOUT_9] =
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
    [TRAINER_GRUNT_MAGMA_HIDEOUT_10] =
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
            .species = SPECIES_MIGHTYENA,
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
    [TRAINER_GRUNT_MAGMA_HIDEOUT_11] =
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
            .species = SPECIES_BALTOY,
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
    [TRAINER_GRUNT_MAGMA_HIDEOUT_12] =
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
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12594
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12596
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12595
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12598
    [TRAINER_GRUNT_MAGMA_HIDEOUT_13] =
    {
#line 12599
        .trainerName = _("GRUNT"),
#line 12600
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12601
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender = 
#line 12603
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12604
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12606
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12608
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12607
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12610
    [TRAINER_GRUNT_MAGMA_HIDEOUT_14] =
    {
#line 12611
        .trainerName = _("GRUNT"),
#line 12612
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12613
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12614
F_TRAINER_FEMALE | 
#line 12615
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12616
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12618
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12620
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12619
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12622
    [TRAINER_GRUNT_MAGMA_HIDEOUT_15] =
    {
#line 12623
        .trainerName = _("GRUNT"),
#line 12624
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12625
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12626
F_TRAINER_FEMALE | 
#line 12627
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12628
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12630
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12632
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12631
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12634
    [TRAINER_GRUNT_MAGMA_HIDEOUT_16] =
    {
#line 12635
        .trainerName = _("GRUNT"),
#line 12636
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
#line 12637
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender = 
#line 12638
F_TRAINER_FEMALE | 
#line 12639
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12640
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12642
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12644
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12643
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12646
    [TRAINER_TABITHA_MAGMA_HIDEOUT] =
    {
#line 12647
        .trainerName = _("TABITHA"),
#line 12648
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
#line 12649
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender = 
#line 12651
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12652
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 12654
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12656
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12655
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12658
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12660
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12659
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12662
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12664
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12663
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12666
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12668
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
#line 12667
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12670
    [TRAINER_DARCY] =
    {
#line 12671
        .trainerName = _("DARCY"),
#line 12672
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 12673
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 12674
F_TRAINER_FEMALE | 
#line 12675
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12676
        .items = { ITEM_HYPER_POTION },
#line 12677
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12679
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12681
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12680
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12683
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12685
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12684
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12687
    [TRAINER_MAXIE_MOSSDEEP] =
    {
#line 12688
        .trainerName = _("MAXIE"),
#line 12689
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
#line 12690
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender = 
#line 12692
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
#line 12693
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12695
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12697
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12696
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12699
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12701
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12700
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12703
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12705
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
#line 12704
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12707
    [TRAINER_PETE] =
    {
#line 12708
        .trainerName = _("PETE"),
#line 12709
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
#line 12710
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender = 
#line 12712
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12713
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12715
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12717
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12716
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12719
    [TRAINER_ISABELLE] =
    {
#line 12720
        .trainerName = _("ISABELLE"),
#line 12721
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
#line 12722
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender = 
#line 12723
F_TRAINER_FEMALE | 
#line 12724
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12725
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12727
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12729
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12728
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12731
    [TRAINER_ANDRES_1] =
    {
#line 12732
        .trainerName = _("ANDRES"),
#line 12733
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 12734
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 12736
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12737
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12739
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12741
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12740
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12743
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12745
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12744
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12747
    [TRAINER_JOSUE] =
    {
#line 12748
        .trainerName = _("JOSUE"),
#line 12749
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12750
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12752
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12753
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12755
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12757
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12756
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12759
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12761
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12760
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12763
    [TRAINER_CAMRON] =
    {
#line 12764
        .trainerName = _("CAMRON"),
#line 12765
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 12766
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 12768
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 12769
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 12771
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12773
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12772
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12775
    [TRAINER_CORY_1] =
    {
#line 12776
        .trainerName = _("CORY"),
#line 12777
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 12778
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 12780
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12781
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12783
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12785
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12784
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12787
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12789
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12788
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12791
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12793
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12792
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12795
    [TRAINER_CAROLINA] =
    {
#line 12796
        .trainerName = _("CAROLINA"),
#line 12797
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 12798
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 12799
F_TRAINER_FEMALE | 
#line 12800
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12801
        .items = { ITEM_HYPER_POTION },
#line 12802
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 12804
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12806
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12805
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12808
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12810
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12809
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12812
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12814
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 12813
            .lvl = 24,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12816
    [TRAINER_ELIJAH] =
    {
#line 12817
        .trainerName = _("ELIJAH"),
#line 12818
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 12819
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 12821
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 12822
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12824
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12826
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12825
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12828
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12830
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12829
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12832
    [TRAINER_CELIA] =
    {
#line 12833
        .trainerName = _("CELIA"),
#line 12834
        .trainerClass = TRAINER_CLASS_PICNICKER,
#line 12835
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender = 
#line 12836
F_TRAINER_FEMALE | 
#line 12837
            TRAINER_ENCOUNTER_MUSIC_GIRL,
#line 12838
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12840
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12842
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12841
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12844
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12846
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12845
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12848
    [TRAINER_BRYAN] =
    {
#line 12849
        .trainerName = _("BRYAN"),
#line 12850
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 12851
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 12853
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12854
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12856
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12858
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12857
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12860
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12862
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12861
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12864
    [TRAINER_BRANDEN] =
    {
#line 12865
        .trainerName = _("BRANDEN"),
#line 12866
        .trainerClass = TRAINER_CLASS_CAMPER,
#line 12867
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender = 
#line 12869
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 12870
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12872
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12874
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12873
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12876
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12878
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12877
            .lvl = 22,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12880
    [TRAINER_BRYANT] =
    {
#line 12881
        .trainerName = _("BRYANT"),
#line 12882
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 12883
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 12885
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12886
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12888
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12890
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12889
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12892
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12894
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12893
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12896
    [TRAINER_SHAYLA] =
    {
#line 12897
        .trainerName = _("SHAYLA"),
#line 12898
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
#line 12899
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender = 
#line 12900
F_TRAINER_FEMALE | 
#line 12901
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12902
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12904
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12906
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12905
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12908
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12910
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12909
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12912
    [TRAINER_KYRA] =
    {
#line 12913
        .trainerName = _("KYRA"),
#line 12914
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 12915
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 12916
F_TRAINER_FEMALE | 
#line 12917
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 12918
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12920
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12922
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12921
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12924
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12926
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12925
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12928
    [TRAINER_JAIDEN] =
    {
#line 12929
        .trainerName = _("JAIDEN"),
#line 12930
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
#line 12931
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender = 
#line 12933
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 12934
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12936
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12938
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12937
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12940
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12942
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12941
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12944
    [TRAINER_ALIX] =
    {
#line 12945
        .trainerName = _("ALIX"),
#line 12946
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 12947
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 12948
F_TRAINER_FEMALE | 
#line 12949
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12950
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12952
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12954
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12953
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12956
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12958
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12957
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12960
    [TRAINER_HELENE] =
    {
#line 12961
        .trainerName = _("HELENE"),
#line 12962
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 12963
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 12964
F_TRAINER_FEMALE | 
#line 12965
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12966
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12968
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12970
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12969
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12972
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12974
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12973
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12976
    [TRAINER_MARLENE] =
    {
#line 12977
        .trainerName = _("MARLENE"),
#line 12978
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 12979
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 12980
F_TRAINER_FEMALE | 
#line 12981
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 12982
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 12984
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12986
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12985
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 12988
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 12990
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 12989
            .lvl = 18,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 12992
    [TRAINER_DEVAN] =
    {
#line 12993
        .trainerName = _("DEVAN"),
#line 12994
        .trainerClass = TRAINER_CLASS_HIKER,
#line 12995
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 12997
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 12998
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13000
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13002
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13001
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13004
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13006
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13005
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13008
    [TRAINER_JOHNSON] =
    {
#line 13009
        .trainerName = _("JOHNSON"),
#line 13010
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
#line 13011
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender = 
#line 13013
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13014
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13016
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13018
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13017
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13020
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13022
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13021
            .lvl = 8,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13024
    [TRAINER_MELINA] =
    {
#line 13025
        .trainerName = _("MELINA"),
#line 13026
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 13027
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender = 
#line 13028
F_TRAINER_FEMALE | 
#line 13029
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13030
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13032
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13034
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13033
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13036
    [TRAINER_BRANDI] =
    {
#line 13037
        .trainerName = _("BRANDI"),
#line 13038
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 13039
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 13040
F_TRAINER_FEMALE | 
#line 13041
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13042
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13044
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13046
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13045
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13048
    [TRAINER_AISHA] =
    {
#line 13049
        .trainerName = _("AISHA"),
#line 13050
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 13051
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 13052
F_TRAINER_FEMALE | 
#line 13053
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13054
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13056
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13058
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13057
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13060
    [TRAINER_MAKAYLA] =
    {
#line 13061
        .trainerName = _("MAKAYLA"),
#line 13062
        .trainerClass = TRAINER_CLASS_EXPERT,
#line 13063
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender = 
#line 13064
F_TRAINER_FEMALE | 
#line 13065
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13066
        .items = { ITEM_HYPER_POTION },
#line 13067
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13069
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13071
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13070
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13073
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13075
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13074
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13077
    [TRAINER_FABIAN] =
    {
#line 13078
        .trainerName = _("FABIAN"),
#line 13079
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 13080
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 13082
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13085
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13087
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13086
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13089
    [TRAINER_DAYTON] =
    {
#line 13090
        .trainerName = _("DAYTON"),
#line 13091
        .trainerClass = TRAINER_CLASS_KINDLER,
#line 13092
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender = 
#line 13094
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 13095
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13097
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13099
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13098
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13101
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13103
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13102
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13105
    [TRAINER_RACHEL] =
    {
#line 13106
        .trainerName = _("RACHEL"),
#line 13107
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
#line 13108
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender = 
#line 13109
F_TRAINER_FEMALE | 
#line 13110
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13111
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13113
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13115
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13114
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13117
    [TRAINER_LEONEL] =
    {
#line 13118
        .trainerName = _("LEONEL"),
#line 13119
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13120
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender = 
#line 13122
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13123
        .items = { ITEM_HYPER_POTION },
#line 13124
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 13126
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13128
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13127
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13129
                MOVE_THUNDER,
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
            },
            },
        },
    },
#line 13133
    [TRAINER_CALLIE] =
    {
#line 13134
        .trainerName = _("CALLIE"),
#line 13135
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
#line 13136
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender = 
#line 13137
F_TRAINER_FEMALE | 
#line 13138
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 13139
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13141
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13143
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13142
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13145
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13147
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13146
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13149
    [TRAINER_CALE] =
    {
#line 13150
        .trainerName = _("CALE"),
#line 13151
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 13152
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 13154
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 13155
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13157
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13159
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13158
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13161
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13163
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 13162
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13165
    [TRAINER_MYLES] =
    {
#line 13166
        .trainerName = _("MYLES"),
#line 13167
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 13168
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender = 
#line 13170
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13171
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13173
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13175
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13174
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13177
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13179
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13178
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13181
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13183
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13182
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13185
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13187
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13186
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13189
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13191
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13190
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13193
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13195
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13194
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13197
    [TRAINER_PAT] =
    {
#line 13198
        .trainerName = _("PAT"),
#line 13199
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 13200
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 13201
F_TRAINER_FEMALE | 
#line 13202
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13203
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13205
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13207
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13206
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13209
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13211
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13210
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13213
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13215
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13214
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13217
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13219
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13218
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13221
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13223
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13222
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13225
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13227
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 13226
            .lvl = 25,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13229
    [TRAINER_CRISTIN_1] =
    {
#line 13230
        .trainerName = _("CRISTIN"),
#line 13231
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 13232
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 13233
F_TRAINER_FEMALE | 
#line 13234
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 13235
        .items = { ITEM_HYPER_POTION },
#line 13236
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13238
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13240
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13239
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13242
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13244
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 13243
            .lvl = 29,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13246
    [TRAINER_MAY_RUSTBORO_TREECKO] =
    {
#line 13247
        .trainerName = _("MAY"),
#line 13248
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 13249
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 13250
F_TRAINER_FEMALE | 
#line 13251
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13252
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13254
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13256
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 13255
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13258
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13260
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13259
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13262
    [TRAINER_MAY_RUSTBORO_TORCHIC] =
    {
#line 13263
        .trainerName = _("MAY"),
#line 13264
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 13265
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender = 
#line 13266
F_TRAINER_FEMALE | 
#line 13267
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13268
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 13270
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13272
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 13271
            .lvl = 13,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 13274
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13276
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
#line 13275
            .lvl = 15,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 13278
    [TRAINER_ROXANNE_2] =
    {
#line 13279
        .trainerName = _("ROXANNE"),
#line 13280
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13281
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13282
F_TRAINER_FEMALE | 
#line 13283
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13284
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13285
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13287
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13289
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13288
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13290
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13295
            .species = SPECIES_KABUTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13295
            .heldItem = ITEM_SITRUS_BERRY,
#line 13297
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13296
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13298
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13303
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13305
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13304
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13306
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13311
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13311
            .heldItem = ITEM_SITRUS_BERRY,
#line 13313
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13312
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13314
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13319
    [TRAINER_ROXANNE_3] =
    {
#line 13320
        .trainerName = _("ROXANNE"),
#line 13321
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13322
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13323
F_TRAINER_FEMALE | 
#line 13324
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13325
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13326
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13328
            .species = SPECIES_OMANYTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13330
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13329
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13331
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13336
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13338
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13337
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13339
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13344
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13344
            .heldItem = ITEM_SITRUS_BERRY,
#line 13346
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13345
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13347
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13352
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13354
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13353
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13355
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13360
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13360
            .heldItem = ITEM_SITRUS_BERRY,
#line 13362
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13361
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13363
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13368
    [TRAINER_ROXANNE_4] =
    {
#line 13369
        .trainerName = _("ROXANNE"),
#line 13370
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13371
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13372
F_TRAINER_FEMALE | 
#line 13373
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13374
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13375
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13377
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13379
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13378
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13380
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13385
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13387
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13386
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13388
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13393
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13393
            .heldItem = ITEM_SITRUS_BERRY,
#line 13395
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13394
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13396
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13401
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13403
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13402
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13404
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13409
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13409
            .heldItem = ITEM_SITRUS_BERRY,
#line 13411
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13410
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13412
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13417
    [TRAINER_ROXANNE_5] =
    {
#line 13418
        .trainerName = _("ROXANNE"),
#line 13419
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13420
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender = 
#line 13421
F_TRAINER_FEMALE | 
#line 13422
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13423
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13424
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13426
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13428
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13427
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13429
                MOVE_ROCK_SLIDE,
                MOVE_HYPER_BEAM,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
            },
            },
            {
#line 13434
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13436
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13435
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13437
                MOVE_FOCUS_PUNCH,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
#line 13442
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13444
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13443
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13445
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
#line 13450
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13450
            .heldItem = ITEM_SITRUS_BERRY,
#line 13452
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13451
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13453
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13458
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13460
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13459
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13461
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13466
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13466
            .heldItem = ITEM_SITRUS_BERRY,
#line 13468
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13467
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13469
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
#line 13474
    [TRAINER_BRAWLY_2] =
    {
#line 13475
        .trainerName = _("BRAWLY"),
#line 13476
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13477
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13479
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13480
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13481
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13483
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13483
            .heldItem = ITEM_SITRUS_BERRY,
#line 13485
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13484
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13486
                MOVE_GOLPE_KARATE,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13491
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13493
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13492
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13494
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 13499
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13501
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13500
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13502
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_PATADA_TRIPLE,
            },
            },
            {
#line 13507
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13507
            .heldItem = ITEM_SITRUS_BERRY,
#line 13509
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13508
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13510
                MOVE_SORPRESA,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13515
    [TRAINER_BRAWLY_3] =
    {
#line 13516
        .trainerName = _("BRAWLY"),
#line 13517
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13518
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13520
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13521
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13522
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13524
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13524
            .heldItem = ITEM_SITRUS_BERRY,
#line 13526
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13525
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13527
                MOVE_GOLPE_KARATE,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13532
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13534
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13533
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13535
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 13540
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13542
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13541
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13543
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_PATADA_TRIPLE,
            },
            },
            {
#line 13548
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13548
            .heldItem = ITEM_SITRUS_BERRY,
#line 13550
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13549
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13551
                MOVE_SORPRESA,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13556
    [TRAINER_BRAWLY_4] =
    {
#line 13557
        .trainerName = _("BRAWLY"),
#line 13558
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13559
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13561
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13562
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13563
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13565
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13567
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13566
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13568
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_PUNIO_HIELO,
            },
            },
            {
#line 13573
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13573
            .heldItem = ITEM_SITRUS_BERRY,
#line 13575
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13574
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13576
                MOVE_GOLPE_KARATE,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13581
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13583
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13582
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13584
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
#line 13589
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13591
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13590
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13592
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_PATADA_TRIPLE,
            },
            },
            {
#line 13597
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13597
            .heldItem = ITEM_SITRUS_BERRY,
#line 13599
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13598
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13600
                MOVE_SORPRESA,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13605
    [TRAINER_BRAWLY_5] =
    {
#line 13606
        .trainerName = _("BRAWLY"),
#line 13607
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13608
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender = 
#line 13610
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13611
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13612
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13614
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13616
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13615
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13617
                MOVE_MEGA_PATADA,
                MOVE_FOCUS_PUNCH,
                MOVE_EARTHQUAKE,
                MOVE_BULK_UP,
            },
            },
            {
#line 13622
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13624
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13623
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13625
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_PUNIO_HIELO,
            },
            },
            {
#line 13630
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13630
            .heldItem = ITEM_SITRUS_BERRY,
#line 13632
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13631
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13633
                MOVE_CROSS_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
#line 13638
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13640
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13639
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13641
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
#line 13646
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13648
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13647
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13649
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_PATADA_TRIPLE,
            },
            },
            {
#line 13654
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13654
            .heldItem = ITEM_SITRUS_BERRY,
#line 13656
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13655
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13657
                MOVE_SORPRESA,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 13662
    [TRAINER_WATTSON_2] =
    {
#line 13663
        .trainerName = _("WATTSON"),
#line 13664
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13665
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13667
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13668
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13669
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13671
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13673
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13672
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13674
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13679
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13681
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13680
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13682
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13687
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13687
            .heldItem = ITEM_SITRUS_BERRY,
#line 13689
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13688
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13690
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13695
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13695
            .heldItem = ITEM_SITRUS_BERRY,
#line 13697
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13696
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13698
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13703
    [TRAINER_WATTSON_3] =
    {
#line 13704
        .trainerName = _("WATTSON"),
#line 13705
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13706
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13708
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13709
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13710
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13712
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13714
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13713
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13715
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_DANZA_LLUVIA,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 13720
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13722
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13721
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13723
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13728
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13730
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13729
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13731
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13736
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13736
            .heldItem = ITEM_SITRUS_BERRY,
#line 13738
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13737
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13739
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13744
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13744
            .heldItem = ITEM_SITRUS_BERRY,
#line 13746
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13745
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13747
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13752
    [TRAINER_WATTSON_4] =
    {
#line 13753
        .trainerName = _("WATTSON"),
#line 13754
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13755
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13757
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13758
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13759
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13761
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13763
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13762
            .lvl = 44,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13764
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_DANZA_LLUVIA,
                MOVE_PROTECT,
            },
            },
            {
#line 13769
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13771
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13770
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13772
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13777
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13779
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13778
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13780
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13785
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13785
            .heldItem = ITEM_SITRUS_BERRY,
#line 13787
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13786
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13788
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13793
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13793
            .heldItem = ITEM_SITRUS_BERRY,
#line 13795
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13794
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13796
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13801
    [TRAINER_WATTSON_5] =
    {
#line 13802
        .trainerName = _("WATTSON"),
#line 13803
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13804
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender = 
#line 13806
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 13807
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13808
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13810
            .species = SPECIES_ELECTABUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13812
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13811
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13813
                MOVE_SWIFT,
                MOVE_FOCUS_PUNCH,
                MOVE_THUNDER_PUNCH,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13818
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13820
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13819
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13821
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_DANZA_LLUVIA,
                MOVE_PROTECT,
            },
            },
            {
#line 13826
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13828
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13827
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13829
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 13834
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13836
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13835
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13837
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13842
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13842
            .heldItem = ITEM_SITRUS_BERRY,
#line 13844
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13843
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13845
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_DANZA_LLUVIA,
            },
            },
            {
#line 13850
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13850
            .heldItem = ITEM_SITRUS_BERRY,
#line 13852
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13851
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13853
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 13858
    [TRAINER_FLANNERY_2] =
    {
#line 13859
        .trainerName = _("FLANNERY"),
#line 13860
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13861
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 13862
F_TRAINER_FEMALE | 
#line 13863
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13864
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13865
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 13867
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13867
            .heldItem = ITEM_WHITE_HERB,
#line 13869
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13868
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13870
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13875
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13877
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13876
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13878
                MOVE_LANZALLAMAS,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 13883
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13883
            .heldItem = ITEM_WHITE_HERB,
#line 13885
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13884
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13886
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 13891
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13891
            .heldItem = ITEM_WHITE_HERB,
#line 13893
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13892
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13894
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 13899
    [TRAINER_FLANNERY_3] =
    {
#line 13900
        .trainerName = _("FLANNERY"),
#line 13901
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13902
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 13903
F_TRAINER_FEMALE | 
#line 13904
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13905
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13906
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 13908
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13910
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13909
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13911
                MOVE_HELPING_HAND,
                MOVE_LANZALLAMAS,
                MOVE_ROAR,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 13916
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13916
            .heldItem = ITEM_WHITE_HERB,
#line 13918
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13917
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13919
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13924
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13926
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13925
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13927
                MOVE_LANZALLAMAS,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 13932
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13932
            .heldItem = ITEM_WHITE_HERB,
#line 13934
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13933
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13935
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 13940
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13940
            .heldItem = ITEM_WHITE_HERB,
#line 13942
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13941
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13943
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 13948
    [TRAINER_FLANNERY_4] =
    {
#line 13949
        .trainerName = _("FLANNERY"),
#line 13950
        .trainerClass = TRAINER_CLASS_LEADER,
#line 13951
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 13952
F_TRAINER_FEMALE | 
#line 13953
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 13954
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 13955
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 13957
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13959
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13958
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13960
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 13965
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13967
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13966
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13968
                MOVE_HELPING_HAND,
                MOVE_LANZALLAMAS,
                MOVE_DIA_SOLEADO,
                MOVE_ROAR,
            },
            },
            {
#line 13973
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13973
            .heldItem = ITEM_WHITE_HERB,
#line 13975
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13974
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13976
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 13981
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13983
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13982
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13984
                MOVE_LANZALLAMAS,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 13989
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13989
            .heldItem = ITEM_WHITE_HERB,
#line 13991
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13990
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 13992
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 13997
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 13997
            .heldItem = ITEM_WHITE_HERB,
#line 13999
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 13998
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14000
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14005
    [TRAINER_FLANNERY_5] =
    {
#line 14006
        .trainerName = _("FLANNERY"),
#line 14007
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14008
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender = 
#line 14009
F_TRAINER_FEMALE | 
#line 14010
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14011
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14012
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14014
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14016
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14015
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14017
                MOVE_HELPING_HAND,
                MOVE_LANZALLAMAS,
                MOVE_DIA_SOLEADO,
                MOVE_ROAR,
            },
            },
            {
#line 14022
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14022
            .heldItem = ITEM_WHITE_HERB,
#line 14024
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14023
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14025
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
#line 14030
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14032
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14031
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14033
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_DIA_SOLEADO,
            },
            },
            {
#line 14038
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14040
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14039
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14041
                MOVE_LANZALLAMAS,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
#line 14046
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14046
            .heldItem = ITEM_WHITE_HERB,
#line 14048
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14047
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14049
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
#line 14054
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14054
            .heldItem = ITEM_WHITE_HERB,
#line 14056
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14055
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14057
                MOVE_OVERHEAT,
                MOVE_DIA_SOLEADO,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
#line 14062
    [TRAINER_NORMAN_2] =
    {
#line 14063
        .trainerName = _("NORMAN"),
#line 14064
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14065
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14067
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14068
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14069
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
#line 14071
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14073
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14072
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14074
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14079
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14079
            .heldItem = ITEM_SITRUS_BERRY,
#line 14081
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14080
            .lvl = 42,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14082
                MOVE_VENTISCA,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14087
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14089
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14088
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14090
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14095
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14095
            .heldItem = ITEM_SITRUS_BERRY,
#line 14097
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14096
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14098
                MOVE_HYPER_BEAM,
                MOVE_LANZALLAMAS,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14103
    [TRAINER_NORMAN_3] =
    {
#line 14104
        .trainerName = _("NORMAN"),
#line 14105
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14106
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14108
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14109
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14110
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14112
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14112
            .heldItem = ITEM_SITRUS_BERRY,
#line 14114
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14113
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14115
                MOVE_VENTISCA,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14120
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14122
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14121
            .lvl = 47,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14123
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14128
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14130
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14129
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14131
                MOVE_SORPRESA,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14136
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14138
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14137
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14139
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14144
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14144
            .heldItem = ITEM_SITRUS_BERRY,
#line 14146
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14145
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14147
                MOVE_HYPER_BEAM,
                MOVE_LANZALLAMAS,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14152
    [TRAINER_NORMAN_4] =
    {
#line 14153
        .trainerName = _("NORMAN"),
#line 14154
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14155
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14157
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14158
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14159
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14161
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14161
            .heldItem = ITEM_SITRUS_BERRY,
#line 14163
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14162
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14164
                MOVE_VENTISCA,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14169
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14171
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14170
            .lvl = 52,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14172
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14177
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14179
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14178
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14180
                MOVE_SORPRESA,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14185
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14187
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14186
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14188
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14193
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14193
            .heldItem = ITEM_SITRUS_BERRY,
#line 14195
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14194
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14196
                MOVE_HYPER_BEAM,
                MOVE_LANZALLAMAS,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14201
    [TRAINER_NORMAN_5] =
    {
#line 14202
        .trainerName = _("NORMAN"),
#line 14203
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14204
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender = 
#line 14206
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14207
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14208
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14210
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14210
            .heldItem = ITEM_SITRUS_BERRY,
#line 14212
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14211
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14213
                MOVE_VENTISCA,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
#line 14218
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14220
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14219
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14221
                MOVE_PROTECT,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
#line 14226
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14228
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14227
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14229
                MOVE_SORPRESA,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
#line 14234
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14236
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14235
            .lvl = 57,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14237
                MOVE_TAKE_DOWN,
                MOVE_PROTECT,
                MOVE_FIRE_BLAST,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14242
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14244
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14243
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14245
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 14250
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14250
            .heldItem = ITEM_SITRUS_BERRY,
#line 14252
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14251
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14253
                MOVE_HYPER_BEAM,
                MOVE_LANZALLAMAS,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 14258
    [TRAINER_WINONA_2] =
    {
#line 14259
        .trainerName = _("WINONA"),
#line 14260
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14261
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14262
F_TRAINER_FEMALE | 
#line 14263
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14264
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14265
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14267
            .species = SPECIES_DRATINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14267
            .heldItem = ITEM_SITRUS_BERRY,
#line 14269
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14268
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14270
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14275
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14277
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14276
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14278
                MOVE_DIA_SOLEADO,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14283
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14285
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14284
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14286
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14291
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14293
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14292
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14294
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14299
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14299
            .heldItem = ITEM_CHESTO_BERRY,
#line 14301
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14300
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14302
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14307
    [TRAINER_WINONA_3] =
    {
#line 14308
        .trainerName = _("WINONA"),
#line 14309
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14310
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14311
F_TRAINER_FEMALE | 
#line 14312
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14313
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14314
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14316
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14318
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14317
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14319
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14324
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14326
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14325
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14327
                MOVE_DIA_SOLEADO,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14332
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14332
            .heldItem = ITEM_SITRUS_BERRY,
#line 14334
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14333
            .lvl = 45,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14335
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14340
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14342
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14341
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14343
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14348
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14350
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14349
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14351
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14356
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14356
            .heldItem = ITEM_CHESTO_BERRY,
#line 14358
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14357
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14359
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14364
    [TRAINER_WINONA_4] =
    {
#line 14365
        .trainerName = _("WINONA"),
#line 14366
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14367
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14368
F_TRAINER_FEMALE | 
#line 14369
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14370
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14371
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14373
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14375
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14374
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14376
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14381
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14383
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14382
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14384
                MOVE_DIA_SOLEADO,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14389
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14389
            .heldItem = ITEM_SITRUS_BERRY,
#line 14391
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14390
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14392
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14397
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14399
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14398
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14400
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14405
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14407
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14406
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14408
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14413
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14413
            .heldItem = ITEM_CHESTO_BERRY,
#line 14415
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14414
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14416
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14421
    [TRAINER_WINONA_5] =
    {
#line 14422
        .trainerName = _("WINONA"),
#line 14423
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14424
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender = 
#line 14425
F_TRAINER_FEMALE | 
#line 14426
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14427
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14428
        .aiFlags = AI_FLAG_BASIC_TRAINER | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14430
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14432
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14431
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14433
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
#line 14438
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14440
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14439
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14441
                MOVE_DIA_SOLEADO,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14446
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14448
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14447
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14449
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14454
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14454
            .heldItem = ITEM_SITRUS_BERRY,
#line 14456
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14455
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14457
                MOVE_HYPER_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14462
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14464
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14463
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14465
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
#line 14470
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14470
            .heldItem = ITEM_CHESTO_BERRY,
#line 14472
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14471
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14473
                MOVE_SKY_ATTACK,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
#line 14478
    [TRAINER_TATE_AND_LIZA_2] =
    {
#line 14479
        .trainerName = _("TATE&LIZA"),
#line 14480
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14481
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14483
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14484
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14485
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14487
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14489
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14488
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14490
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14495
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14497
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14496
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14498
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14503
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14503
            .heldItem = ITEM_CHESTO_BERRY,
#line 14505
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14504
            .lvl = 49,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14506
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14511
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14511
            .heldItem = ITEM_CHESTO_BERRY,
#line 14513
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14512
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14514
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14519
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14519
            .heldItem = ITEM_SITRUS_BERRY,
#line 14521
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14520
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14522
                MOVE_DIA_SOLEADO,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_LANZALLAMAS,
            },
            },
        },
    },
#line 14527
    [TRAINER_TATE_AND_LIZA_3] =
    {
#line 14528
        .trainerName = _("TATE&LIZA"),
#line 14529
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14530
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14532
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14533
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14534
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14536
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14538
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14537
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14539
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14544
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14546
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14545
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14547
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14552
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14554
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14553
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14555
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14560
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14560
            .heldItem = ITEM_CHESTO_BERRY,
#line 14562
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14561
            .lvl = 54,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14563
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14568
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14568
            .heldItem = ITEM_CHESTO_BERRY,
#line 14570
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14569
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14571
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14576
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14576
            .heldItem = ITEM_SITRUS_BERRY,
#line 14578
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14577
            .lvl = 55,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14579
                MOVE_DIA_SOLEADO,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_LANZALLAMAS,
            },
            },
        },
    },
#line 14584
    [TRAINER_TATE_AND_LIZA_4] =
    {
#line 14585
        .trainerName = _("TATE&LIZA"),
#line 14586
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14587
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14589
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14590
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14591
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14593
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14595
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14594
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14596
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14601
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14603
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14602
            .lvl = 59,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14604
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14609
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14611
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14610
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14612
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14617
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14617
            .heldItem = ITEM_CHESTO_BERRY,
#line 14619
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14618
            .lvl = 59,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14620
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14625
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14625
            .heldItem = ITEM_CHESTO_BERRY,
#line 14627
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14626
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14628
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14633
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14633
            .heldItem = ITEM_SITRUS_BERRY,
#line 14635
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14634
            .lvl = 60,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14636
                MOVE_DIA_SOLEADO,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_LANZALLAMAS,
            },
            },
        },
    },
#line 14641
    [TRAINER_TATE_AND_LIZA_5] =
    {
#line 14642
        .trainerName = _("TATE&LIZA"),
#line 14643
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14644
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender = 
#line 14646
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 14647
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14648
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14650
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14652
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14651
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14653
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
#line 14658
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14660
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14659
            .lvl = 64,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14661
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
#line 14666
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14668
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14667
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14669
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
#line 14674
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14674
            .heldItem = ITEM_CHESTO_BERRY,
#line 14676
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14675
            .lvl = 64,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14677
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14682
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14682
            .heldItem = ITEM_CHESTO_BERRY,
#line 14684
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14683
            .lvl = 65,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14685
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
#line 14690
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14690
            .heldItem = ITEM_SITRUS_BERRY,
#line 14692
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14691
            .lvl = 65,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14693
                MOVE_DIA_SOLEADO,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_LANZALLAMAS,
            },
            },
        },
    },
#line 14698
    [TRAINER_JUAN_2] =
    {
#line 14699
        .trainerName = _("JUAN"),
#line 14700
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14701
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14703
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14704
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14705
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14707
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14709
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14708
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14710
                MOVE_HYPNOSIS,
                MOVE_DANZA_LLUVIA,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14715
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14717
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14716
            .lvl = 46,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14718
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14723
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14725
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14724
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14726
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14731
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14731
            .heldItem = ITEM_CHESTO_BERRY,
#line 14733
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14732
            .lvl = 48,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14734
                MOVE_REST,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14739
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14739
            .heldItem = ITEM_CHESTO_BERRY,
#line 14741
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14740
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14742
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14747
    [TRAINER_JUAN_3] =
    {
#line 14748
        .trainerName = _("JUAN"),
#line 14749
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14750
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14752
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14753
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14754
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
#line 14756
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14758
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14757
            .lvl = 50,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14759
                MOVE_HYPNOSIS,
                MOVE_DANZA_LLUVIA,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14764
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14766
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14765
            .lvl = 51,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14767
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14772
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14774
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14773
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14775
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14780
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14780
            .heldItem = ITEM_CHESTO_BERRY,
#line 14782
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14781
            .lvl = 53,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14783
                MOVE_REST,
                MOVE_GUILLOTINA,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14788
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14788
            .heldItem = ITEM_CHESTO_BERRY,
#line 14790
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14789
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14791
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14796
    [TRAINER_JUAN_4] =
    {
#line 14797
        .trainerName = _("JUAN"),
#line 14798
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14799
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14801
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14802
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14803
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14805
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14807
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14806
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14808
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 14813
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14815
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14814
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14816
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14821
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14823
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14822
            .lvl = 56,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14824
                MOVE_HYPNOSIS,
                MOVE_DANZA_LLUVIA,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
#line 14829
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14831
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14830
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14832
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
#line 14837
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14837
            .heldItem = ITEM_CHESTO_BERRY,
#line 14839
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14838
            .lvl = 58,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14840
                MOVE_REST,
                MOVE_GUILLOTINA,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14845
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14845
            .heldItem = ITEM_CHESTO_BERRY,
#line 14847
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14846
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14848
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14853
    [TRAINER_JUAN_5] =
    {
#line 14854
        .trainerName = _("JUAN"),
#line 14855
        .trainerClass = TRAINER_CLASS_LEADER,
#line 14856
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender = 
#line 14858
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14859
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14860
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14862
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14864
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14863
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14865
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 14870
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14872
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14871
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14873
                MOVE_DANZA_LLUVIA,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
#line 14878
            .species = SPECIES_POLITOED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14880
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14879
            .lvl = 61,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14881
                MOVE_HYPNOSIS,
                MOVE_DANZA_LLUVIA,
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
            },
            },
            {
#line 14886
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14888
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14887
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14889
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_SHEER_COLD,
            },
            },
            {
#line 14894
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14894
            .heldItem = ITEM_CHESTO_BERRY,
#line 14896
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14895
            .lvl = 63,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14897
                MOVE_REST,
                MOVE_GUILLOTINA,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
#line 14902
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14902
            .heldItem = ITEM_CHESTO_BERRY,
#line 14904
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14903
            .lvl = 66,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14905
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
#line 14910
    [TRAINER_ANGELO] =
    {
#line 14911
        .trainerName = _("ANGELO"),
#line 14912
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
#line 14913
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender = 
#line 14915
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
#line 14916
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 14918
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14920
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 14919
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14921
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CHARM,
            },
            },
            {
#line 14925
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14927
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 14926
            .lvl = 17,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14928
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CONFUSE_RAY,
            },
            },
        },
    },
#line 14932
    [TRAINER_DARIUS] =
    {
#line 14933
        .trainerName = _("DARIUS"),
#line 14934
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
#line 14935
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender = 
#line 14937
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 14938
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 14940
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14942
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
#line 14941
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 14944
    [TRAINER_STEVEN] =
    {
#line 14945
        .trainerName = _("STEVEN"),
#line 14946
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 14947
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender = 
#line 14949
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14950
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
#line 14951
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 14953
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14955
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14954
            .lvl = 77,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14956
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
            },
            },
            {
#line 14961
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14963
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14962
            .lvl = 75,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14964
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_ANCIENT_POWER,
                MOVE_EARTHQUAKE,
            },
            },
            {
#line 14969
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14971
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14970
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14972
                MOVE_THUNDER,
                MOVE_EARTHQUAKE,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
            {
#line 14977
            .species = SPECIES_CRADILY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14979
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14978
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14980
                MOVE_GIGA_DRAIN,
                MOVE_ANCIENT_POWER,
                MOVE_INGRAIN,
                MOVE_CONFUSE_RAY,
            },
            },
            {
#line 14985
            .species = SPECIES_ARMALDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14987
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14986
            .lvl = 76,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14988
                MOVE_WATER_PULSE,
                MOVE_ANCIENT_POWER,
                MOVE_AERIAL_ACE,
                MOVE_SLASH,
            },
            },
            {
#line 14993
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 14993
            .heldItem = ITEM_SITRUS_BERRY,
#line 14995
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 14994
            .lvl = 78,
            .nature = NATURALEZA_OFENSIVA,
            .moves = {
#line 14996
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_METEOR_MASH,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
#line 15001
    [TRAINER_ANDRES_2] =
    {
#line 15002
        .trainerName = _("ANDRES"),
#line 15003
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15004
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15006
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15007
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15009
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15011
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15010
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15013
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15015
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15014
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15017
    [TRAINER_ANDRES_3] =
    {
#line 15018
        .trainerName = _("ANDRES"),
#line 15019
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15020
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15022
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15023
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15025
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15027
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15026
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15029
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15031
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15030
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15033
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15035
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15034
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15037
    [TRAINER_ANDRES_4] =
    {
#line 15038
        .trainerName = _("ANDRES"),
#line 15039
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15040
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15042
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15043
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15045
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15047
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15046
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15049
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15051
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15050
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15053
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15055
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15054
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15057
    [TRAINER_ANDRES_5] =
    {
#line 15058
        .trainerName = _("ANDRES"),
#line 15059
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
#line 15060
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender = 
#line 15062
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15063
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15065
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15067
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15066
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15069
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15071
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15070
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15073
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15075
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15074
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15077
    [TRAINER_CORY_2] =
    {
#line 15078
        .trainerName = _("CORY"),
#line 15079
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15080
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15082
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15083
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15085
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15087
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15086
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15089
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15091
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15090
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15093
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15095
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15094
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15097
    [TRAINER_CORY_3] =
    {
#line 15098
        .trainerName = _("CORY"),
#line 15099
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15100
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15102
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15103
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15105
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15107
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15106
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15109
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15111
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15110
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15113
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15115
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15114
            .lvl = 32,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15117
    [TRAINER_CORY_4] =
    {
#line 15118
        .trainerName = _("CORY"),
#line 15119
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15120
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15122
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15123
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15125
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15127
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15126
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15129
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15131
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15130
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15133
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15135
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15134
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15137
    [TRAINER_CORY_5] =
    {
#line 15138
        .trainerName = _("CORY"),
#line 15139
        .trainerClass = TRAINER_CLASS_SAILOR,
#line 15140
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender = 
#line 15142
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 15143
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15145
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15147
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15146
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15149
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15151
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15150
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15153
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15155
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15154
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15157
    [TRAINER_PABLO_2] =
    {
#line 15158
        .trainerName = _("PABLO"),
#line 15159
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15160
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15162
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15163
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15165
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15167
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15166
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15169
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15171
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15170
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15173
    [TRAINER_PABLO_3] =
    {
#line 15174
        .trainerName = _("PABLO"),
#line 15175
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15176
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15178
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15179
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15181
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15183
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15182
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15185
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15187
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15186
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15189
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15191
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15190
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15193
    [TRAINER_PABLO_4] =
    {
#line 15194
        .trainerName = _("PABLO"),
#line 15195
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15196
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15198
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15199
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15201
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15203
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15202
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15205
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15207
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15206
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15209
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15211
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15210
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15213
    [TRAINER_PABLO_5] =
    {
#line 15214
        .trainerName = _("PABLO"),
#line 15215
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
#line 15216
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender = 
#line 15218
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
#line 15219
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15221
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15223
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15222
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15225
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15227
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15226
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15229
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15231
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15230
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15233
    [TRAINER_KOJI_2] =
    {
#line 15234
        .trainerName = _("KOJI"),
#line 15235
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15236
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15238
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15239
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15241
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15243
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15242
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15245
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15247
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15246
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15249
    [TRAINER_KOJI_3] =
    {
#line 15250
        .trainerName = _("KOJI"),
#line 15251
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15252
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15254
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15255
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15257
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15259
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15258
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15261
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15263
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15262
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15265
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15267
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15266
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15269
    [TRAINER_KOJI_4] =
    {
#line 15270
        .trainerName = _("KOJI"),
#line 15271
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15272
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15274
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15275
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15277
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15279
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15278
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15281
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15283
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15282
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15285
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15287
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15286
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15289
    [TRAINER_KOJI_5] =
    {
#line 15290
        .trainerName = _("KOJI"),
#line 15291
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
#line 15292
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender = 
#line 15294
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15295
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15297
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15299
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15298
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15301
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15303
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15302
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15305
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15307
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15306
            .lvl = 43,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15309
    [TRAINER_CRISTIN_2] =
    {
#line 15310
        .trainerName = _("CRISTIN"),
#line 15311
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15312
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15313
F_TRAINER_FEMALE | 
#line 15314
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15315
        .items = { ITEM_HYPER_POTION },
#line 15316
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15318
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15320
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 15319
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15322
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15324
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
#line 15323
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15326
    [TRAINER_CRISTIN_3] =
    {
#line 15327
        .trainerName = _("CRISTIN"),
#line 15328
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15329
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15330
F_TRAINER_FEMALE | 
#line 15331
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15332
        .items = { ITEM_HYPER_POTION },
#line 15333
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15335
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15337
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15336
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15339
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15341
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15340
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15343
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15345
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
#line 15344
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15347
    [TRAINER_CRISTIN_4] =
    {
#line 15348
        .trainerName = _("CRISTIN"),
#line 15349
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15350
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15351
F_TRAINER_FEMALE | 
#line 15352
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15353
        .items = { ITEM_HYPER_POTION },
#line 15354
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15356
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15358
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 15357
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15360
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15362
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
#line 15361
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15364
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15366
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
#line 15365
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15368
    [TRAINER_CRISTIN_5] =
    {
#line 15369
        .trainerName = _("CRISTIN"),
#line 15370
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
#line 15371
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender = 
#line 15372
F_TRAINER_FEMALE | 
#line 15373
            TRAINER_ENCOUNTER_MUSIC_COOL,
#line 15374
        .items = { ITEM_HYPER_POTION },
#line 15375
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15377
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15379
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15378
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15381
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15383
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15382
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15385
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15387
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
#line 15386
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15389
    [TRAINER_FERNANDO_2] =
    {
#line 15390
        .trainerName = _("FERNANDO"),
#line 15391
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15392
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15394
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15395
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15397
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15399
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15398
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15401
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15403
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15402
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15405
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15407
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15406
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15409
    [TRAINER_FERNANDO_3] =
    {
#line 15410
        .trainerName = _("FERNANDO"),
#line 15411
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15412
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15414
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15415
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15417
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15419
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15418
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15421
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15423
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15422
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15425
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15427
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15426
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15429
    [TRAINER_FERNANDO_4] =
    {
#line 15430
        .trainerName = _("FERNANDO"),
#line 15431
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15432
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15434
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15435
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15437
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15439
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15438
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15441
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15443
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15442
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15445
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15447
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15446
            .lvl = 39,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15449
    [TRAINER_FERNANDO_5] =
    {
#line 15450
        .trainerName = _("FERNANDO"),
#line 15451
        .trainerClass = TRAINER_CLASS_GUITARIST,
#line 15452
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender = 
#line 15454
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
#line 15455
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15457
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15459
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15458
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15461
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15463
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15462
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15465
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15467
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15466
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15469
    [TRAINER_SAWYER_2] =
    {
#line 15470
        .trainerName = _("SAWYER"),
#line 15471
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15472
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15474
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15475
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15477
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15479
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15478
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15481
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15483
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15482
            .lvl = 26,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15485
    [TRAINER_SAWYER_3] =
    {
#line 15486
        .trainerName = _("SAWYER"),
#line 15487
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15488
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15490
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15491
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15493
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15495
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15494
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15497
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15499
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15498
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15501
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15503
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15502
            .lvl = 28,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15505
    [TRAINER_SAWYER_4] =
    {
#line 15506
        .trainerName = _("SAWYER"),
#line 15507
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15508
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15510
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15511
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15513
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15515
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15514
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15517
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15519
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15518
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15521
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15523
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15522
            .lvl = 30,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15525
    [TRAINER_SAWYER_5] =
    {
#line 15526
        .trainerName = _("SAWYER"),
#line 15527
        .trainerClass = TRAINER_CLASS_HIKER,
#line 15528
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = 
#line 15530
            TRAINER_ENCOUNTER_MUSIC_HIKER,
#line 15531
        .aiFlags = AI_FLAG_BASIC_TRAINER,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15533
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15535
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15534
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15537
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15539
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15538
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15541
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15543
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15542
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15545
    [TRAINER_GABRIELLE_2] =
    {
#line 15546
        .trainerName = _("GABRIELLE"),
#line 15547
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15548
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15549
F_TRAINER_FEMALE | 
#line 15550
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15551
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15553
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15555
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15554
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15557
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15559
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15558
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15561
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15563
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15562
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15565
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15567
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15566
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15569
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15571
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15570
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15573
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15575
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15574
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15577
    [TRAINER_GABRIELLE_3] =
    {
#line 15578
        .trainerName = _("GABRIELLE"),
#line 15579
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15580
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15581
F_TRAINER_FEMALE | 
#line 15582
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15583
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15585
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15587
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15586
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15589
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15591
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15590
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15593
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15595
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15594
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15597
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15599
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15598
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15601
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15603
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15602
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15605
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15607
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15606
            .lvl = 33,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15609
    [TRAINER_GABRIELLE_4] =
    {
#line 15610
        .trainerName = _("GABRIELLE"),
#line 15611
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15612
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15613
F_TRAINER_FEMALE | 
#line 15614
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15615
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15617
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15619
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15618
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15621
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15623
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15622
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15625
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15627
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15626
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15629
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15631
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15630
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15633
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15635
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15634
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15637
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15639
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15638
            .lvl = 35,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15641
    [TRAINER_GABRIELLE_5] =
    {
#line 15642
        .trainerName = _("GABRIELLE"),
#line 15643
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
#line 15644
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender = 
#line 15645
F_TRAINER_FEMALE | 
#line 15646
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15647
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 15649
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15651
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15650
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15653
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15655
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15654
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15657
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15659
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15658
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15661
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15663
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15662
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15665
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15667
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15666
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15669
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15671
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15670
            .lvl = 37,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15673
    [TRAINER_THALIA_2] =
    {
#line 15674
        .trainerName = _("THALIA"),
#line 15675
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15676
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15677
F_TRAINER_FEMALE | 
#line 15678
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15679
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15681
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15683
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15682
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15685
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15687
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
#line 15686
            .lvl = 34,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15689
    [TRAINER_THALIA_3] =
    {
#line 15690
        .trainerName = _("THALIA"),
#line 15691
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15692
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15693
F_TRAINER_FEMALE | 
#line 15694
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15695
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15697
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15699
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15698
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15701
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15703
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15702
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15705
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15707
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
#line 15706
            .lvl = 36,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15709
    [TRAINER_THALIA_4] =
    {
#line 15710
        .trainerName = _("THALIA"),
#line 15711
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15712
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15713
F_TRAINER_FEMALE | 
#line 15714
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15715
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15717
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15719
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15718
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15721
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15723
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15722
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15725
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15727
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
#line 15726
            .lvl = 38,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15729
    [TRAINER_THALIA_5] =
    {
#line 15730
        .trainerName = _("THALIA"),
#line 15731
        .trainerClass = TRAINER_CLASS_BEAUTY,
#line 15732
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender = 
#line 15733
F_TRAINER_FEMALE | 
#line 15734
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
#line 15735
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15737
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15739
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15738
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15741
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15743
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15742
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15745
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15747
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
#line 15746
            .lvl = 40,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15749
    [TRAINER_MARIELA] =
    {
#line 15750
        .trainerName = _("MARIELA"),
#line 15751
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 15752
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender = 
#line 15753
F_TRAINER_FEMALE | 
#line 15754
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15756
            .species = SPECIES_CHIMECHO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15758
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15757
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15760
    [TRAINER_ALVARO] =
    {
#line 15761
        .trainerName = _("ALVARO"),
#line 15762
        .trainerClass = TRAINER_CLASS_PSYCHIC,
#line 15763
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender = 
#line 15765
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15767
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15769
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15768
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15771
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15773
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15772
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15775
    [TRAINER_EVERETT] =
    {
#line 15776
        .trainerName = _("EVERETT"),
#line 15777
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
#line 15778
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender = 
#line 15780
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15782
            .species = SPECIES_MEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15784
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15783
            .lvl = 41,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15786
    [TRAINER_RED] =
    {
#line 15787
        .trainerName = _("RED"),
#line 15788
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 15789
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender = 
#line 15791
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15793
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15795
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15794
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15797
    [TRAINER_LEAF] =
    {
#line 15798
        .trainerName = _("LEAF"),
#line 15799
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 15800
        .trainerPic = TRAINER_PIC_LEAF,
        .encounterMusic_gender = 
#line 15801
F_TRAINER_FEMALE | 
#line 15802
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15804
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15806
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15805
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15808
    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
#line 15809
        .trainerName = _("BRENDAN"),
#line 15810
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
#line 15811
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .encounterMusic_gender = 
#line 15813
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 15815
            .species = SPECIES_GROUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15817
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15816
            .lvl = 5,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },
#line 15819
    [TRAINER_LANCE] =
    {
#line 15820
        .trainerName = _("LANCE"),
#line 15821
        .trainerClass = TRAINER_CLASS_CHAMPION,
#line 15822
        .trainerPic = TRAINER_PIC_LANCE,
        .encounterMusic_gender = 
#line 15824
            TRAINER_ENCOUNTER_MUSIC_CYNTHIA,
#line 15825
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 15827
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15829
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15828
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
            {
#line 15831
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15833
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
#line 15832
            .lvl = 31,
            .nature = NATURALEZA_OFENSIVA,
            },
        },
    },

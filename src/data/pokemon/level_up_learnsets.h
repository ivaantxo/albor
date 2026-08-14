#define LEVEL_UP_MOVE(lvl, moveLearned) {.movimiento = moveLearned, .level = lvl}
#define LEVEL_UP_END {.movimiento = LEVEL_UP_MOVE_END, .level = 0}

static const struct LevelUpMove sNoneLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBulbasaurLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sIvysaurLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVenusaurLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sCharmanderLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCharmeleonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCharizardLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_END};

static const struct LevelUpMove sSquirtleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWartortleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBlastoiseLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCaterpieLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMetapodLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sButterfreeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWeedleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKakunaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBeedrillLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMENA),
    LEVEL_UP_MOVE(1, MOVE_PAYBACK), // POR HABILIDAD AGRESIVIDAD
    LEVEL_UP_MOVE(1, MOVE_DOBLE_AGUIJON),
    LEVEL_UP_END};

static const struct LevelUpMove sPidgeyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPidgeottoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPidgeotLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRattataLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRaticateLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sEkansLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sArbokLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),

    LEVEL_UP_END};

static const struct LevelUpMove sPichuLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sPikachuLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRaichuLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_END};

static const struct LevelUpMove sRaichuAlolaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSandshrewLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSandslashLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sSandshrewAlolaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSandslashAlolaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sNidoranFLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNidorinaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNidoqueenLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sNidoranMLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNidorinoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNidokingLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sCleffaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sClefairyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sClefableLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVulpixLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sNinetalesLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sVulpixAlolaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sNinetalesAlolaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sIgglybuffLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sJigglypuffLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWigglytuffLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZubatLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sGolbatLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sCrobatLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sParasLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sParasectLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMeowthLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPersianLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DIA_DE_PAGO),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sPsyduckLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGolduckLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_END};

static const struct LevelUpMove sMankeyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sPrimeapeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAnnihilapeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGrowlitheLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sArcanineLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_END};

// static const struct LevelUpMove sArcanineHisuiLevelUpLearnset[] = {
//     LEVEL_UP_END
// };

static const struct LevelUpMove sPoliwagLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPoliwhirlLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPoliwrathLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sPolitoedLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAbraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKadabraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAlakazamLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMachopLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMachokeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMachampLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sBellsproutLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWeepinbellLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVictreebelLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sTentacoolLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTentacruelLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sGeodudeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGravelerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGolemLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sPonytaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRapidashLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_END};

static const struct LevelUpMove sMagnemiteLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMagnetonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMagnezoneLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGrimerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMukLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sShellderLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCloysterLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGastlyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHaunterLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGengarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sOnixLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSteelixLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_END};

static const struct LevelUpMove sDrowzeeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHypnoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKrabbyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKinglerLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sExeggcuteLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_EGG_BOMB),
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_END};

static const struct LevelUpMove sExeggutorLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_EGG_BOMB),
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sCuboneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_END};

static const struct LevelUpMove sMarowakLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMarowakAlolaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTyrogueLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_END};

static const struct LevelUpMove sHitmonleeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_VOLADORA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_MOVE(1, MOVE_TRIPLE_AXEL),
    LEVEL_UP_END};

static const struct LevelUpMove sHitmonchanLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sHitmontopLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_MOVE(1, MOVE_TRIPLE_AXEL),
    LEVEL_UP_END};

static const struct LevelUpMove sLickitungLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLickilickyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sKoffingLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWeezingLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWeezingGalarLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sRhyhornLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRhydonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRhyperiorLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sTangelaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTangrowthLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sKangaskhanLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sHorseaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSeadraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKingdraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGoldeenLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSeakingLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sStaryuLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sStarmieLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMimeJrLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sMrMimeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sScytherLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sScizorLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sKleavorLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sSmoochumLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sJynxLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sElekidLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sElectabuzzLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sElectivireLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sMagbyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sMagmarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMagmortarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPinsirLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sTaurosLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_FURIA_TAURINA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sMagikarpLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGyaradosLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sLaprasLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sEeveeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sVaporeonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sJolteonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_END};

static const struct LevelUpMove sFlareonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_END};

static const struct LevelUpMove sEspeonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sUmbreonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_END};

static const struct LevelUpMove sLeafeonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_END};

static const struct LevelUpMove sGlaceonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSylveonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sPorygonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPorygon2LevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPorygonZLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sOmanyteLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sOmastarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKabutoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKabutopsLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sAerodactylLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_END};

static const struct LevelUpMove sMunchlaxLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSnorlaxLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sArticunoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZapdosLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_END};

static const struct LevelUpMove sMoltresLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDratiniLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDragonairLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDragoniteLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_END};

static const struct LevelUpMove sMewtwoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMewLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sChikoritaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBayleefLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMeganiumLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sCyndaquilLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sQuilavaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTyphlosionLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTotodileLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCroconawLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFeraligatrLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sSentretLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFurretLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sHoothootLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNoctowlLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLedybaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLedianLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_END};

static const struct LevelUpMove sSpinarakLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAriadosLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DOBLE_AGUIJON),
    LEVEL_UP_END};

static const struct LevelUpMove sChinchouLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLanturnLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTogepiLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sTogeticLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTogekissLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNatuLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sXatuLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMareepLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sFlaaffyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAmpharosLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAzurillLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMarillLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAzumarillLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_END};

static const struct LevelUpMove sBonslyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSudowoodoLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sHoppipLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSkiploomLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sJumpluffLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAipomLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAmbipomLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_END};

static const struct LevelUpMove sSunkernLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSunfloraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sYanmaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sYanmegaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMurkrowLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHonchkrowLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sMisdreavusLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMismagiusLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sGirafarigLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sGligarLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sGliscorLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sSnubbullLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sGranbullLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sHeracrossLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_END};

static const struct LevelUpMove sSneaselLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_TRIPLE_AXEL),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sWeavileLevelUpLearnset[] = {

    LEVEL_UP_END};

static const struct LevelUpMove sSneaslerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTeddiursaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sUrsaringLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sSlugmaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMagcargoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSwinubLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPiloswineLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMamoswineLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_END};

static const struct LevelUpMove sCorsolaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDelibirdLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHoundourLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHoundoomLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sPhanpyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sDonphanLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sStantlerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWyrdeerLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sRaikouLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sEnteiLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_END};

static const struct LevelUpMove sSuicuneLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLarvitarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPupitarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTyranitarLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sLugiaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHoOhLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCelebiLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTreeckoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGrovyleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSceptileLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sTorchicLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCombuskenLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBlazikenLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_VOLADORA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sMudkipLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMarshtompLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSwampertLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sPoochyenaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMightyenaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sWurmpleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSilcoonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBeautiflyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCascoonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDustoxLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLotadLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLombreLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLudicoloLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSeedotLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNuzleafLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sShiftryLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sTaillowLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSwellowLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_END};

static const struct LevelUpMove sWingullLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPelipperLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRaltsLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKirliaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGardevoirLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sGalladeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sSurskitLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMasquerainLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSlakothLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVigorothLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSlakingLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sNincadaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNinjaskLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sShedinjaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWhismurLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sLoudredLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sExploudLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMakuhitaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHariyamaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sNosepassLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sProbopassLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSableyeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sMawileLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_END};

static const struct LevelUpMove sAronLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLaironLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAggronLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sMedititeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMedichamLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_VOLADORA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sElectrikeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sManectricLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBudewLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sRoseliaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRoseradeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCarvanhaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSharpedoLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sWailmerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWailordLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sNumelLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCameruptLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTorkoalLevelUpLearnset[] = {
    LEVEL_UP_END};

// static const struct LevelUpMove sSpoinkLevelUpLearnset[] = {
//     LEVEL_UP_END
// }

// static const struct LevelUpMove sGrumpigLevelUpLearnset[] = {
//    LEVEL_UP_MOVE( 1, MOVE_PALMA_RAUDA),
//    LEVEL_UP_MOVE( 1, MOVE_DESTRUCTOR),
//    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
//    LEVEL_UP_MOVE(1, MOVE_PATALETA),
//    LEVEL_UP_MOVE(1, MOVE_PISOTON),
//    LEVEL_UP_END
// };

static const struct LevelUpMove sTrapinchLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVibravaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFlygonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCacneaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCacturneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sSwabluLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAltariaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sLunatoneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sSolrockLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBaltoyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sClaydolLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sLileepLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCradilyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAnorithLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sArmaldoLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sFeebasLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMiloticLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCastformLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sKecleonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDuskullLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDusclopsLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDusknoirLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sTropiusLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sChinglingLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sChimechoLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sAbsolLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sSnoruntLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGlalieLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_END};

static const struct LevelUpMove sFroslassLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sSphealLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSealeoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sWalreinLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sClamperlLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHuntailLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_END};

static const struct LevelUpMove sGorebyssLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRelicanthLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBagonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sShelgonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSalamenceLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_END};

static const struct LevelUpMove sBeldumLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMetangLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMetagrossLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sRegirockLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sRegiceLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRegisteelLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_END};

static const struct LevelUpMove sLatiasLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLatiosLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKyogreLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGroudonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sRayquazaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_END};

static const struct LevelUpMove sDeoxysLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sTurtwigLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGrotleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTorterraLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sChimcharLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sMonfernoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sInfernapeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_IGNEA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_END};

static const struct LevelUpMove sPiplupLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPrinplupLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sEmpoleonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sStarlyLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sStaraviaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sStaraptorLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBidoofLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBibarelLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKricketotLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKricketuneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_END};

static const struct LevelUpMove sShinxLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLuxioLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLuxrayLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_RELAMPAGO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sCranidosLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRampardosLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

// static const struct LevelUpMove sPachirisuLevelUpLearnset[] = {
//     LEVEL_UP_MOVE( 1, MOVE_CANTO_ENCANTADOR),
//     LEVEL_UP_END
// };

static const struct LevelUpMove sShieldonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBastiodonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sCombeeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMENA),
    LEVEL_UP_END};

static const struct LevelUpMove sVespiquenLevelUpLearnset[] = { // AÑADIR ATAQUES MULTIHIT PARA ENJAMBRE
    LEVEL_UP_MOVE(1, MOVE_COLMENA),
    LEVEL_UP_END};

static const struct LevelUpMove sDrifloonLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDrifblimLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBunearyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sLopunnyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_BOFETON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TROPICAL),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_TRIPLE_AXEL),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sGibleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGabiteLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGarchompLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CHUPASANGRE),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sRioluLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLucarioLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_VOLADORA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_TRIPLE),
    LEVEL_UP_END};

static const struct LevelUpMove sHippopotasLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHippowdonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_IGNEO),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_ELECTRICO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_EQUINA),
    LEVEL_UP_MOVE(1, MOVE_PATALETA),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_END};

static const struct LevelUpMove sSkorupiLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDrapionLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_AGUIJON),
    LEVEL_UP_MOVE(1, MOVE_COLMILLO_HELADO),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sCroagunkLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sToxicroakLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_GOLPE_KARATE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_BAJA),
    LEVEL_UP_MOVE(1, MOVE_PUNTAPIE),
    LEVEL_UP_MOVE(1, MOVE_PATADA_HACHA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_SALTO),
    LEVEL_UP_MOVE(1, MOVE_PATADA_VOLADORA),
    LEVEL_UP_MOVE(1, MOVE_PATADA_GIRO),
    LEVEL_UP_MOVE(1, MOVE_DOBLE_PATADA),
    LEVEL_UP_END};

static const struct LevelUpMove sSnoverLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAbomasnowLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sRotomLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHeatranLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRegigigasLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_MOVE(1, MOVE_PALMA_RAUDA),
    LEVEL_UP_MOVE(1, MOVE_DESTRUCTOR),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_FUEGO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_TRUENO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_HIELO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_COMETA),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PUNIO),
    LEVEL_UP_MOVE(1, MOVE_PISOTON),
    LEVEL_UP_MOVE(1, MOVE_MEGA_PATADA),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sYamaskLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCofagrigusLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sZoruaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZoroarkLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZoruaHisuiLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZoroarkHisuiLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFrillishLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sJellicentLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sJoltikLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGalvantulaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFerroseedLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFerrothornLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sElgyemLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBeheeyemLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLitwickLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sLampentLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sChandelureLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sAxewLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFraxureLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHaxorusLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sCubchooLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sBearticLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sPawniardLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBisharpLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_GUILLOTINA),
    LEVEL_UP_END};

static const struct LevelUpMove sDeinoLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sZweilousLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHydreigonLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_END};

static const struct LevelUpMove sLarvestaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sVolcaronaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sFennekinLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBraixenLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDelphoxLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_END};

static const struct LevelUpMove sFroakieLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFrogadierLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGreninjaLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFletchlingLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFletchinderLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTalonflameLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPanchamLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sPangoroLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTyruntLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTyrantrumLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sAmauraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sAurorusLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sGoomyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sSliggooLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sGoodraLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sRowletLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDartrixLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDecidueyeLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_END};

static const struct LevelUpMove sLittenLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sTorracatLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sIncineroarLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sPopplioLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sBrionneLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sPrimarinaLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_CANTO_ENCANTADOR),
    LEVEL_UP_END};

static const struct LevelUpMove sJangmoOLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sHakamoOLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sKommoOLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_ALARIDO),
    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
    LEVEL_UP_END};

static const struct LevelUpMove sRookideeLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCorvisquireLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sCorviknightLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sBlipbugLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BABY_DOLL_EYES),
    LEVEL_UP_END};

static const struct LevelUpMove sDottlerLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sOrbeetleLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sSnomLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sFrosmothLevelUpLearnset[] = {
    LEVEL_UP_END};

static const struct LevelUpMove sDreepyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_END};

static const struct LevelUpMove sDrakloakLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_END};

static const struct LevelUpMove sDragapultLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_LLAMA_AZUL),
    LEVEL_UP_MOVE(1, MOVE_BARRAGE),
    LEVEL_UP_END};

//static const struct LevelUpMove sShuppetLevelUpLearnset[] = {
//    LEVEL_UP_END};

//static const struct LevelUpMove sBanetteLevelUpLearnset[] = {
//    LEVEL_UP_MOVE(1, MOVE_VUDU),
//    LEVEL_UP_END};

//static const struct LevelUpMove sGolettLevelUpLearnset[] = {
//    LEVEL_UP_END};

//static const struct LevelUpMove sGolurkLevelUpLearnset[] = {
//    LEVEL_UP_MOVE(1, MOVE_PUNIO_MARTILLO),
//    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
//    LEVEL_UP_END};

//static const struct LevelUpMove sSandilevelUpLearnset[] = {
//    LEVEL_UP_END};

//static const struct LevelUpMove sKrokorokLevelUpLearnset[] = {
//    LEVEL_UP_END};

//static const struct LevelUpMove sKrookodileLevelUpLearnset[] = {
//    LEVEL_UP_MOVE(1, MOVE_FUERZA_BRUTA),
//    LEVEL_UP_END};

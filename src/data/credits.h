enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_WORLD_DIRECTOR,
    PAGE_LEAD_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_PROGRAMMERS_4,
    PAGE_GRAPHIC_DESIGNERS_1,
    PAGE_GRAPHIC_DESIGNERS_2,
    PAGE_GRAPHIC_DESIGNERS_3,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_SCENARIO_PLOT,
    PAGE_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_BATTLE_FRONTIER_DATA,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1,
    PAGE_PKMN_DESIGNERS_1,
    PAGE_PKMN_DESIGNERS_2,
    PAGE_PKMN_DESIGNERS_3,
    PAGE_PKMN_DESIGNERS_4,
    PAGE_SUPPORT_PROGRAMMERS,
    PAGE_NCL_PRODUCT_TESTING,
    PAGE_PACKAGE_AND_MANUAL,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_ARTWORK_1,
    PAGE_ARTWORK_2,
    PAGE_ARTWORK_3,
    PAGE_COORDINATORS,
    PAGE_ENGLISH_VERSION,
    PAGE_TRANSLATOR,
    PAGE_TEXT_EDITOR,
    PAGE_NCL_COORDINATOR,
    PAGE_PROGRAMMERS_5,
    PAGE_GRAPHIC_DESIGNER,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2,
    PAGE_NOA_TESTING,
    PAGE_SPECIAL_THANKS_5,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[]                    = _("");
static const u8 sCreditsText_PkmnEmeraldVersion[]             = _("POKéMON EMERALD VERSION");
static const u8 sCreditsText_Credits[]                        = _("Credits");
static const u8 sCreditsText_ExecutiveDirector[]              = _("Executive Director");
static const u8 sCreditsText_Director[]                       = _("Director");
static const u8 sCreditsText_ArtDirector[]                    = _("Art Director");
static const u8 sCreditsText_BattleDirector[]                 = _("Battle Director");
static const u8 sCreditsText_MainProgrammer[]                 = _("Main Programmer");
static const u8 sCreditsText_BattleSystemPgrms[]              = _("Battle System Programmers");
static const u8 sCreditsText_FieldSystemPgrms[]               = _("Field System Programmer");
static const u8 sCreditsText_Programmers[]                    = _("Programmers");
static const u8 sCreditsText_MainGraphicDesigner[]            = _("Main Graphic Designer");
static const u8 sCreditsText_GraphicDesigners[]               = _("Graphic Designers");
static const u8 sCreditsText_PkmnDesigners[]                  = _("POKéMON Designers");
static const u8 sCreditsText_MusicComposition[]               = _("Music Composition");
static const u8 sCreditsText_SoundEffectsAndPkmnVoices[]      = _("Sound Effects & POKéMON Voices");
static const u8 sCreditsText_GameDesigners[]                  = _("Game Designers");
static const u8 sCreditsText_ScenarioPlot[]                   = _("Scenario Plot");
static const u8 sCreditsText_Scenario[]                       = _("Scenario");
static const u8 sCreditsText_ScriptDesigners[]                = _("Script Designers");
static const u8 sCreditsText_MapDesigners[]                   = _("Map Designers");
static const u8 sCreditsText_MapDataDesigners[]               = _("Map Data Designers");
static const u8 sCreditsText_ParametricDesigners[]            = _("Parametric Designers");
static const u8 sCreditsText_PokedexText[]                    = _("POKéDEX Text");
static const u8 sCreditsText_EnvAndToolPgrms[]                = _("Environment & Tool Programmers");
static const u8 sCreditsText_NCLProductTesting[]              = _("NCL Product Testing");
static const u8 sCreditsText_SpecialThanks[]                  = _("Special Thanks");
static const u8 sCreditsText_Coordinators[]                   = _("Coordinators");
static const u8 sCreditsText_Producers[]                      = _("Producers");
static const u8 sCreditsText_ExecProducers[]                  = _("Executive Producers");
static const u8 sCreditsText_InfoSupervisors[]                = _("Information Supervisors");
static const u8 sCreditsText_TaskManagers[]                   = _("Task Managers");
static const u8 sCreditsText_WorldDirector[]                  = _("World Director");
static const u8 sCreditsText_BattleFrontierData[]             = _("Battle Frontier Data");
static const u8 sCreditsText_SupportProgrammers[]             = _("Support Programmers");
static const u8 sCreditsText_Artwork[]                        = _("Artwork");
static const u8 sCreditsText_LeadProgrammer[]                 = _("Lead Programmer");
static const u8 sCreditsText_LeadGraphicArtist[]              = _("Lead Graphic Artist");
static const u8 sCreditsText_SatoshiTajiri[]                  = _("Satoshi Tajiri");
static const u8 sCreditsText_JunichiMasuda[]                  = _("Junichi Masuda");
static const u8 sCreditsText_KenSugimori[]                    = _("Ken Sugimori");
static const u8 sCreditsText_ShigekiMorimoto[]                = _("Shigeki Morimoto");
static const u8 sCreditsText_TetsuyaWatanabe[]                = _("Tetsuya Watanabe");
static const u8 sCreditsText_HisashiSogabe[]                  = _("Hisashi Sogabe");
static const u8 sCreditsText_SosukeTamada[]                   = _("Sosuke Tamada");
static const u8 sCreditsText_AkitoMori[]                      = _("Akito Mori");
static const u8 sCreditsText_KeitaKagaya[]                    = _("Keita Kagaya");
static const u8 sCreditsText_YoshinoriMatsuda[]               = _("Yoshinori Matsuda");
static const u8 sCreditsText_HiroyukiNakamura[]               = _("Hiroyuki Nakamura");
static const u8 sCreditsText_MasaoTaya[]                      = _("Masao Taya");
static const u8 sCreditsText_SatoshiNohara[]                  = _("Satoshi Nohara");
static const u8 sCreditsText_TomomichiOhta[]                  = _("Tomomichi Ohta");
static const u8 sCreditsText_MiyukiIwasawa[]                  = _("Miyuki Iwasawa");
static const u8 sCreditsText_TakenoriOhta[]                   = _("Takenori Ohta");
static const u8 sCreditsText_HironobuYoshida[]                = _("Hironobu Yoshida");
static const u8 sCreditsText_MotofumiFujiwara[]               = _("Motofumi Fujiwara");
static const u8 sCreditsText_SatoshiOhta[]                    = _("Satoshi Ohta");
static const u8 sCreditsText_AsukaIwashita[]                  = _("Asuka Iwashita");
static const u8 sCreditsText_AimiTomita[]                     = _("Aimi Tomita");
static const u8 sCreditsText_TakaoUnno[]                      = _("Takao Unno");
static const u8 sCreditsText_KanakoEo[]                       = _("Kanako Eo");
static const u8 sCreditsText_JunOkutani[]                     = _("Jun Okutani");
static const u8 sCreditsText_AtsukoNishida[]                  = _("Atsuko Nishida");
static const u8 sCreditsText_MuneoSaito[]                     = _("Muneo Saito");
static const u8 sCreditsText_RenaYoshikawa[]                  = _("Rena Yoshikawa");
static const u8 sCreditsText_GoIchinose[]                     = _("Go Ichinose");
static const u8 sCreditsText_MorikazuAoki[]                   = _("Morikazu Aoki");
static const u8 sCreditsText_KojiNishino[]                    = _("Koji Nishino");
static const u8 sCreditsText_KenjiMatsushima[]                = _("Kenji Matsushima");
static const u8 sCreditsText_TetsujiOhta[]                    = _("Tetsuji Ohta");
static const u8 sCreditsText_HitomiSato[]                     = _("Hitomi Sato");
static const u8 sCreditsText_TakeshiKawachimaru[]             = _("Takeshi Kawachimaru");
static const u8 sCreditsText_TeruyukiShimoyamada[]            = _("Teruyuki Shimoyamada");
static const u8 sCreditsText_ShigeruOhmori[]                  = _("Shigeru Ohmori");
static const u8 sCreditsText_TadashiTakahashi[]               = _("Tadashi Takahashi");
static const u8 sCreditsText_ToshinobuMatsumiya[]             = _("Toshinobu Matsumiya");
static const u8 sCreditsText_AkihitoTomisawa[]                = _("Akihito Tomisawa");
static const u8 sCreditsText_HirokiEnomoto[]                  = _("Hiroki Enomoto");
static const u8 sCreditsText_KazuyukiTerada[]                 = _("Kazuyuki Terada");
static const u8 sCreditsText_YuriSakurai[]                    = _("Yuri Sakurai");
static const u8 sCreditsText_HiromiSagawa[]                   = _("Hiromi Sagawa");
static const u8 sCreditsText_KenjiTominaga[]                  = _("Kenji Tominaga");
static const u8 sCreditsText_YoshioTajiri[]                   = _("Yoshio Tajiri");
static const u8 sCreditsText_TeikoSasaki[]                    = _("Teiko Sasaki");
static const u8 sCreditsText_SachikoHamano[]                  = _("Sachiko Hamano");
static const u8 sCreditsText_ChieMatsumiya[]                  = _("Chie Matsumiya");
static const u8 sCreditsText_AkikoShinozaki[]                 = _("Akiko Shinozaki");
static const u8 sCreditsText_AstukoFujii[]                    = _("Astuko Fujii");
static const u8 sCreditsText_NozomuSaito[]                    = _("Nozomu Saito");
static const u8 sCreditsText_KenkichiToyama[]                 = _("Kenkichi Toyama");
static const u8 sCreditsText_SuguruNakatsui[]                 = _("Suguru Nakatsui");
static const u8 sCreditsText_YumiFunasaka[]                   = _("Yumi Funasaka");
static const u8 sCreditsText_NaokoYanase[]                    = _("Naoko Yanase");
static const u8 sCreditsText_NCLSuperMarioClub[]              = _("NCL Super Mario Club");
static const u8 sCreditsText_AtsushiTada[]                    = _("Atsushi Tada");
static const u8 sCreditsText_TakahiroOhnishi[]                = _("Takahiro Ohnishi");
static const u8 sCreditsText_NorihideOkamura[]                = _("Norihide Okamura");
static const u8 sCreditsText_HiroNakamura[]                   = _("Hiro Nakamura");
static const u8 sCreditsText_HiroyukiUesugi[]                 = _("Hiroyuki Uesugi");
static const u8 sCreditsText_TerukiMurakawa[]                 = _("Teruki Murakawa");
static const u8 sCreditsText_AkiraKinashi[]                   = _("Akira Kinashi");
static const u8 sCreditsText_MichikoTakizawa[]                = _("Michiko Takizawa");
static const u8 sCreditsText_MakikoTakada[]                   = _("Makiko Takada");
static const u8 sCreditsText_TakanaoKondo[]                   = _("Takanao Kondo");
static const u8 sCreditsText_AiMashima[]                      = _("Ai Mashima");
static const u8 sCreditsText_GakujiNomoto[]                   = _("Gakuji Nomoto");
static const u8 sCreditsText_TakehiroIzushi[]                 = _("Takehiro Izushi");
static const u8 sCreditsText_HitoshiYamagami[]                = _("Hitoshi Yamagami");
static const u8 sCreditsText_KyokoWatanabe[]                  = _("Kyoko Watanabe");
static const u8 sCreditsText_TakaoNakano[]                    = _("Takao Nakano");
static const u8 sCreditsText_HiroyukiJinnai[]                 = _("Hiroyuki Jinnai");
static const u8 sCreditsText_HiroakiTsuru[]                   = _("Hiroaki Tsuru");
static const u8 sCreditsText_TsunekazIshihara[]               = _("Tsunekaz Ishihara");
static const u8 sCreditsText_SatoruIwata[]                    = _("Satoru Iwata");
static const u8 sCreditsText_KazuyaSuyama[]                   = _("Kazuya Suyama");
static const u8 sCreditsText_SatoshiMitsuhara[]               = _("Satoshi Mitsuhara");
static const u8 sCreditsText_TomotakaKomura[]                 = _("Tomotaka Komura");
static const u8 sCreditsText_MikikoOhhashi[]                  = _("Mikiko Ohhashi");
static const u8 sCreditsText_DaisukeHoshino[]                 = _("Daisuke Hoshino");
static const u8 sCreditsText_KenjiroIto[]                     = _("Kenjiro Ito");
static const u8 sCreditsText_RuiKawaguchi[]                   = _("Rui Kawaguchi");
static const u8 sCreditsText_ShunsukeKohori[]                 = _("Shunsuke Kohori");
static const u8 sCreditsText_SachikoNakamichi[]               = _("Sachiko Nakamichi");
static const u8 sCreditsText_FujikoNomura[]                   = _("Fujiko Nomura");
static const u8 sCreditsText_KazukiYoshihara[]                = _("Kazuki Yoshihara");
static const u8 sCreditsText_RetsujiNomoto[]                  = _("Retsuji Nomoto");
static const u8 sCreditsText_AzusaTajima[]                    = _("Azusa Tajima");
static const u8 sCreditsText_ShusakuEgami[]                   = _("Shusaku Egami");
static const u8 sCreditsText_PackageAndManual[]               = _("Package & Manual Illustration");
static const u8 sCreditsText_EnglishVersion[]                 = _("English Version Coordinators");
static const u8 sCreditsText_Translator[]                     = _("Translator");
static const u8 sCreditsText_TextEditor[]                     = _("Text Editor");
static const u8 sCreditsText_NCLCoordinator[]                 = _("NCL Coordinator");
static const u8 sCreditsText_GraphicDesigner[]                = _("Graphic Designer");
static const u8 sCreditsText_NOAProductTesting[]              = _("NOA Product Testing");
static const u8 sCreditsText_HideyukiNakajima[]               = _("Hideyuki Nakajima");
static const u8 sCreditsText_HidenoriSaeki[]                  = _("Hidenori Saeki");
static const u8 sCreditsText_YokoWatanabe[]                   = _("Yoko Watanabe");
static const u8 sCreditsText_SakaeKimura[]                    = _("Sakae Kimura");
static const u8 sCreditsText_ChiakiShinkai[]                  = _("Chiaki Shinkai");
static const u8 sCreditsText_SethMcMahill[]                   = _("Seth McMahill");
static const u8 sCreditsText_NobOgasawara[]                   = _("Nob Ogasawara");
static const u8 sCreditsText_TeresaLillygren[]                = _("Teresa Lillygren");
static const u8 sCreditsText_KimikoNakamichi[]                = _("Kimiko Nakamichi");
static const u8 sCreditsText_SouichiYamamoto[]                = _("Souichi Yamamoto");
static const u8 sCreditsText_YuichiroIto[]                    = _("Yuichiro Ito");
static const u8 sCreditsText_ThomasHertzog[]                  = _("Thomas Hertzog");
static const u8 sCreditsText_MikaKurosawa[]                   = _("Mika Kurosawa");
static const u8 sCreditsText_NationalFederationBlind[]        = _("National Federation of the Blind");
static const u8 sCreditsText_PatriciaAMaurer[]                = _("Patricia A. Maurer");
static const u8 sCreditsText_EuropeanBlindUnion[]             = _("European Blind Union");
static const u8 sCreditsText_RoyalNewZealandFederationBlind[] = _("Royal New Zealand Federation for the Blind");
static const u8 sCreditsText_MotoyasuTojima[]                 = _("Motoyasu Tojima");
static const u8 sCreditsText_NicolaPrattBarlow[]              = _("Nicola Pratt-Barlow");
static const u8 sCreditsText_ShellieDow[]                     = _("Shellie Dow");
static const u8 sCreditsText_ErikJohnson[]                    = _("Erik Johnson");
static const struct CreditsEntry sCreditsEntry_EmptyString                      = {FALSE, sCreditsText_EmptyString};
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion               = {TRUE, sCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry sCreditsEntry_Credits                          = {TRUE, sCreditsText_Credits};
static const struct CreditsEntry sCreditsEntry_ExecutiveDirector                = {TRUE, sCreditsText_ExecutiveDirector};
static const struct CreditsEntry sCreditsEntry_Director                         = {TRUE, sCreditsText_Director};
static const struct CreditsEntry sCreditsEntry_ArtDirector                      = {TRUE, sCreditsText_ArtDirector};
static const struct CreditsEntry sCreditsEntry_BattleDirector                   = {TRUE, sCreditsText_BattleDirector};
static const struct CreditsEntry sCreditsEntry_MainProgrammer                   = {TRUE, sCreditsText_MainProgrammer};
static const struct CreditsEntry sCreditsEntry_BattleSystemPgrms                = {TRUE, sCreditsText_BattleSystemPgrms};
static const struct CreditsEntry sCreditsEntry_FieldSystemPgrms                 = {TRUE, sCreditsText_FieldSystemPgrms};
static const struct CreditsEntry sCreditsEntry_Programmers                      = {TRUE, sCreditsText_Programmers};
static const struct CreditsEntry sCreditsEntry_MainGraphicDesigner              = {TRUE, sCreditsText_MainGraphicDesigner};
static const struct CreditsEntry sCreditsEntry_GraphicDesigners                 = {TRUE, sCreditsText_GraphicDesigners};
static const struct CreditsEntry sCreditsEntry_PkmnDesigners                    = {TRUE, sCreditsText_PkmnDesigners};
static const struct CreditsEntry sCreditsEntry_MusicComposition                 = {TRUE, sCreditsText_MusicComposition};
static const struct CreditsEntry sCreditsEntry_SoundEffectsAndPkmnVoices        = {TRUE, sCreditsText_SoundEffectsAndPkmnVoices};
static const struct CreditsEntry sCreditsEntry_GameDesigners                    = {TRUE, sCreditsText_GameDesigners};
static const struct CreditsEntry sCreditsEntry_ScenarioPlot                     = {TRUE, sCreditsText_ScenarioPlot};
static const struct CreditsEntry sCreditsEntry_Scenario                         = {TRUE, sCreditsText_Scenario};
static const struct CreditsEntry sCreditsEntry_ScriptDesigners                  = {TRUE, sCreditsText_ScriptDesigners};
static const struct CreditsEntry sCreditsEntry_MapDesigners                     = {TRUE, sCreditsText_MapDesigners};
static const struct CreditsEntry sCreditsEntry_MapDataDesigners                 = {TRUE, sCreditsText_MapDataDesigners};
static const struct CreditsEntry sCreditsEntry_ParametricDesigners              = {TRUE, sCreditsText_ParametricDesigners};
static const struct CreditsEntry sCreditsEntry_PokedexText                      = {TRUE, sCreditsText_PokedexText};
static const struct CreditsEntry sCreditsEntry_EnvAndToolPgrms                  = {TRUE, sCreditsText_EnvAndToolPgrms};
static const struct CreditsEntry sCreditsEntry_NCLProductTesting                = {TRUE, sCreditsText_NCLProductTesting};
static const struct CreditsEntry sCreditsEntry_SpecialThanks                    = {TRUE, sCreditsText_SpecialThanks};
static const struct CreditsEntry sCreditsEntry_Coordinators                     = {TRUE, sCreditsText_Coordinators};
static const struct CreditsEntry sCreditsEntry_Producers                        = {TRUE, sCreditsText_Producers};
static const struct CreditsEntry sCreditsEntry_ExecProducers                    = {TRUE, sCreditsText_ExecProducers};
static const struct CreditsEntry sCreditsEntry_InfoSupervisors                  = {TRUE, sCreditsText_InfoSupervisors};
static const struct CreditsEntry sCreditsEntry_TaskManagers                     = {TRUE, sCreditsText_TaskManagers};
static const struct CreditsEntry sCreditsEntry_WorldDirector                    = {TRUE, sCreditsText_WorldDirector};
static const struct CreditsEntry sCreditsEntry_BattleFrontierData               = {TRUE, sCreditsText_BattleFrontierData};
static const struct CreditsEntry sCreditsEntry_SupportProgrammers               = {TRUE, sCreditsText_SupportProgrammers};
static const struct CreditsEntry sCreditsEntry_Artwork                          = {TRUE, sCreditsText_Artwork};
static const struct CreditsEntry sCreditsEntry_LeadProgrammer                   = {TRUE, sCreditsText_LeadProgrammer};
static const struct CreditsEntry sCreditsEntry_LeadGraphicArtist                = {TRUE, sCreditsText_LeadGraphicArtist};
static const struct CreditsEntry sCreditsEntry_SatoshiTajiri                    = {FALSE, sCreditsText_SatoshiTajiri};
static const struct CreditsEntry sCreditsEntry_JunichiMasuda                    = {FALSE, sCreditsText_JunichiMasuda};
static const struct CreditsEntry sCreditsEntry_KenSugimori                      = {FALSE, sCreditsText_KenSugimori};
static const struct CreditsEntry sCreditsEntry_ShigekiMorimoto                  = {FALSE, sCreditsText_ShigekiMorimoto};
static const struct CreditsEntry sCreditsEntry_TetsuyaWatanabe                  = {FALSE, sCreditsText_TetsuyaWatanabe};
static const struct CreditsEntry sCreditsEntry_HisashiSogabe                    = {FALSE, sCreditsText_HisashiSogabe};
static const struct CreditsEntry sCreditsEntry_SosukeTamada                     = {FALSE, sCreditsText_SosukeTamada};
static const struct CreditsEntry sCreditsEntry_AkitoMori                        = {FALSE, sCreditsText_AkitoMori};
static const struct CreditsEntry sCreditsEntry_KeitaKagaya                      = {FALSE, sCreditsText_KeitaKagaya};
static const struct CreditsEntry sCreditsEntry_YoshinoriMatsuda                 = {FALSE, sCreditsText_YoshinoriMatsuda};
static const struct CreditsEntry sCreditsEntry_HiroyukiNakamura                 = {FALSE, sCreditsText_HiroyukiNakamura};
static const struct CreditsEntry sCreditsEntry_MasaoTaya                        = {FALSE, sCreditsText_MasaoTaya};
static const struct CreditsEntry sCreditsEntry_SatoshiNohara                    = {FALSE, sCreditsText_SatoshiNohara};
static const struct CreditsEntry sCreditsEntry_TomomichiOhta                    = {FALSE, sCreditsText_TomomichiOhta};
static const struct CreditsEntry sCreditsEntry_MiyukiIwasawa                    = {FALSE, sCreditsText_MiyukiIwasawa};
static const struct CreditsEntry sCreditsEntry_TakenoriOhta                     = {FALSE, sCreditsText_TakenoriOhta};
static const struct CreditsEntry sCreditsEntry_HironobuYoshida                  = {FALSE, sCreditsText_HironobuYoshida};
static const struct CreditsEntry sCreditsEntry_MotofumiFujiwara                 = {FALSE, sCreditsText_MotofumiFujiwara};
static const struct CreditsEntry sCreditsEntry_SatoshiOhta                      = {FALSE, sCreditsText_SatoshiOhta};
static const struct CreditsEntry sCreditsEntry_AsukaIwashita                    = {FALSE, sCreditsText_AsukaIwashita};
static const struct CreditsEntry sCreditsEntry_AimiTomita                       = {FALSE, sCreditsText_AimiTomita};
static const struct CreditsEntry sCreditsEntry_TakaoUnno                        = {FALSE, sCreditsText_TakaoUnno};
static const struct CreditsEntry sCreditsEntry_KanakoEo                         = {FALSE, sCreditsText_KanakoEo};
static const struct CreditsEntry sCreditsEntry_JunOkutani                       = {FALSE, sCreditsText_JunOkutani};
static const struct CreditsEntry sCreditsEntry_AtsukoNishida                    = {FALSE, sCreditsText_AtsukoNishida};
static const struct CreditsEntry sCreditsEntry_MuneoSaito                       = {FALSE, sCreditsText_MuneoSaito};
static const struct CreditsEntry sCreditsEntry_RenaYoshikawa                    = {FALSE, sCreditsText_RenaYoshikawa};
static const struct CreditsEntry sCreditsEntry_GoIchinose                       = {FALSE, sCreditsText_GoIchinose};
static const struct CreditsEntry sCreditsEntry_MorikazuAoki                     = {FALSE, sCreditsText_MorikazuAoki};
static const struct CreditsEntry sCreditsEntry_KojiNishino                      = {FALSE, sCreditsText_KojiNishino};
static const struct CreditsEntry sCreditsEntry_KenjiMatsushima                  = {FALSE, sCreditsText_KenjiMatsushima};
static const struct CreditsEntry sCreditsEntry_TetsujiOhta                      = {FALSE, sCreditsText_TetsujiOhta};
static const struct CreditsEntry sCreditsEntry_HitomiSato                       = {FALSE, sCreditsText_HitomiSato};
static const struct CreditsEntry sCreditsEntry_TakeshiKawachimaru               = {FALSE, sCreditsText_TakeshiKawachimaru};
static const struct CreditsEntry sCreditsEntry_TeruyukiShimoyamada              = {FALSE, sCreditsText_TeruyukiShimoyamada};
static const struct CreditsEntry sCreditsEntry_ShigeruOhmori                    = {FALSE, sCreditsText_ShigeruOhmori};
static const struct CreditsEntry sCreditsEntry_TadashiTakahashi                 = {FALSE, sCreditsText_TadashiTakahashi};
static const struct CreditsEntry sCreditsEntry_ToshinobuMatsumiya               = {FALSE, sCreditsText_ToshinobuMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkihitoTomisawa                  = {FALSE, sCreditsText_AkihitoTomisawa};
static const struct CreditsEntry sCreditsEntry_HirokiEnomoto                    = {FALSE, sCreditsText_HirokiEnomoto};
static const struct CreditsEntry sCreditsEntry_KazuyukiTerada                   = {FALSE, sCreditsText_KazuyukiTerada};
static const struct CreditsEntry sCreditsEntry_YuriSakurai                      = {FALSE, sCreditsText_YuriSakurai};
static const struct CreditsEntry sCreditsEntry_HiromiSagawa                     = {FALSE, sCreditsText_HiromiSagawa};
static const struct CreditsEntry sCreditsEntry_KenjiTominaga                    = {FALSE, sCreditsText_KenjiTominaga};
static const struct CreditsEntry sCreditsEntry_YoshioTajiri                     = {FALSE, sCreditsText_YoshioTajiri};
static const struct CreditsEntry sCreditsEntry_TeikoSasaki                      = {FALSE, sCreditsText_TeikoSasaki};
static const struct CreditsEntry sCreditsEntry_SachikoHamano                    = {FALSE, sCreditsText_SachikoHamano};
static const struct CreditsEntry sCreditsEntry_ChieMatsumiya                    = {FALSE, sCreditsText_ChieMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkikoShinozaki                   = {FALSE, sCreditsText_AkikoShinozaki};
static const struct CreditsEntry sCreditsEntry_AstukoFujii                      = {FALSE, sCreditsText_AstukoFujii};
static const struct CreditsEntry sCreditsEntry_NozomuSaito                      = {FALSE, sCreditsText_NozomuSaito};
static const struct CreditsEntry sCreditsEntry_KenkichiToyama                   = {FALSE, sCreditsText_KenkichiToyama};
static const struct CreditsEntry sCreditsEntry_SuguruNakatsui                   = {FALSE, sCreditsText_SuguruNakatsui};
static const struct CreditsEntry sCreditsEntry_YumiFunasaka                     = {FALSE, sCreditsText_YumiFunasaka};
static const struct CreditsEntry sCreditsEntry_NaokoYanase                      = {FALSE, sCreditsText_NaokoYanase};
static const struct CreditsEntry sCreditsEntry_NCLSuperMarioClub                = {FALSE, sCreditsText_NCLSuperMarioClub};
static const struct CreditsEntry sCreditsEntry_AtsushiTada                      = {FALSE, sCreditsText_AtsushiTada};
static const struct CreditsEntry sCreditsEntry_TakahiroOhnishi                  = {FALSE, sCreditsText_TakahiroOhnishi};
static const struct CreditsEntry sCreditsEntry_NorihideOkamura                  = {FALSE, sCreditsText_NorihideOkamura};
static const struct CreditsEntry sCreditsEntry_HiroNakamura                     = {FALSE, sCreditsText_HiroNakamura};
static const struct CreditsEntry sCreditsEntry_HiroyukiUesugi                   = {FALSE, sCreditsText_HiroyukiUesugi};
static const struct CreditsEntry sCreditsEntry_TerukiMurakawa                   = {FALSE, sCreditsText_TerukiMurakawa};
static const struct CreditsEntry sCreditsEntry_AkiraKinashi                     = {FALSE, sCreditsText_AkiraKinashi};
static const struct CreditsEntry sCreditsEntry_MichikoTakizawa                  = {FALSE, sCreditsText_MichikoTakizawa};
static const struct CreditsEntry sCreditsEntry_MakikoTakada                     = {FALSE, sCreditsText_MakikoTakada};
static const struct CreditsEntry sCreditsEntry_TakanaoKondo                     = {FALSE, sCreditsText_TakanaoKondo};
static const struct CreditsEntry sCreditsEntry_AiMashima                        = {FALSE, sCreditsText_AiMashima};
static const struct CreditsEntry sCreditsEntry_GakujiNomoto                     = {FALSE, sCreditsText_GakujiNomoto};
static const struct CreditsEntry sCreditsEntry_TakehiroIzushi                   = {FALSE, sCreditsText_TakehiroIzushi};
static const struct CreditsEntry sCreditsEntry_HitoshiYamagami                  = {FALSE, sCreditsText_HitoshiYamagami};
static const struct CreditsEntry sCreditsEntry_KyokoWatanabe                    = {FALSE, sCreditsText_KyokoWatanabe};
static const struct CreditsEntry sCreditsEntry_TakaoNakano                      = {FALSE, sCreditsText_TakaoNakano};
static const struct CreditsEntry sCreditsEntry_HiroyukiJinnai                   = {FALSE, sCreditsText_HiroyukiJinnai};
static const struct CreditsEntry sCreditsEntry_HiroakiTsuru                     = {FALSE, sCreditsText_HiroakiTsuru};
static const struct CreditsEntry sCreditsEntry_TsunekazIshihara                 = {FALSE, sCreditsText_TsunekazIshihara};
static const struct CreditsEntry sCreditsEntry_SatoruIwata                      = {FALSE, sCreditsText_SatoruIwata};
static const struct CreditsEntry sCreditsEntry_KazuyaSuyama                     = {FALSE, sCreditsText_KazuyaSuyama};
static const struct CreditsEntry sCreditsEntry_SatoshiMitsuhara                 = {FALSE, sCreditsText_SatoshiMitsuhara};
static const struct CreditsEntry sCreditsEntry_TomotakaKomura                   = {FALSE, sCreditsText_TomotakaKomura};
static const struct CreditsEntry sCreditsEntry_MikikoOhhashi                    = {FALSE, sCreditsText_MikikoOhhashi};
static const struct CreditsEntry sCreditsEntry_DaisukeHoshino                   = {FALSE, sCreditsText_DaisukeHoshino};
static const struct CreditsEntry sCreditsEntry_KenjiroIto                       = {FALSE, sCreditsText_KenjiroIto};
static const struct CreditsEntry sCreditsEntry_RuiKawaguchi                     = {FALSE, sCreditsText_RuiKawaguchi};
static const struct CreditsEntry sCreditsEntry_ShunsukeKohori                   = {FALSE, sCreditsText_ShunsukeKohori};
static const struct CreditsEntry sCreditsEntry_SachikoNakamichi                 = {FALSE, sCreditsText_SachikoNakamichi};
static const struct CreditsEntry sCreditsEntry_FujikoNomura                     = {FALSE, sCreditsText_FujikoNomura};
static const struct CreditsEntry sCreditsEntry_KazukiYoshihara                  = {FALSE, sCreditsText_KazukiYoshihara};
static const struct CreditsEntry sCreditsEntry_RetsujiNomoto                    = {FALSE, sCreditsText_RetsujiNomoto};
static const struct CreditsEntry sCreditsEntry_AzusaTajima                      = {FALSE, sCreditsText_AzusaTajima};
static const struct CreditsEntry sCreditsEntry_ShusakuEgami                     = {FALSE, sCreditsText_ShusakuEgami};
static const struct CreditsEntry sCreditsEntry_PackageAndManual                 = {TRUE, sCreditsText_PackageAndManual};
static const struct CreditsEntry sCreditsEntry_EnglishVersion                   = {TRUE, sCreditsText_EnglishVersion};
static const struct CreditsEntry sCreditsEntry_Translator                       = {TRUE, sCreditsText_Translator};
static const struct CreditsEntry sCreditsEntry_TextEditor                       = {TRUE, sCreditsText_TextEditor};
static const struct CreditsEntry sCreditsEntry_NCLCoordinator                   = {TRUE, sCreditsText_NCLCoordinator};
static const struct CreditsEntry sCreditsEntry_GraphicDesigner                  = {TRUE, sCreditsText_GraphicDesigner};
static const struct CreditsEntry sCreditsEntry_NOAProductTesting                = {TRUE, sCreditsText_NOAProductTesting};
static const struct CreditsEntry sCreditsEntry_HideyukiNakajima                 = {FALSE, sCreditsText_HideyukiNakajima};
static const struct CreditsEntry sCreditsEntry_HidenoriSaeki                    = {FALSE, sCreditsText_HidenoriSaeki};
static const struct CreditsEntry sCreditsEntry_YokoWatanabe                     = {FALSE, sCreditsText_YokoWatanabe};
static const struct CreditsEntry sCreditsEntry_SakaeKimura                      = {FALSE, sCreditsText_SakaeKimura};
static const struct CreditsEntry sCreditsEntry_ChiakiShinkai                    = {FALSE, sCreditsText_ChiakiShinkai};
static const struct CreditsEntry sCreditsEntry_SethMcMahill                     = {FALSE, sCreditsText_SethMcMahill};
static const struct CreditsEntry sCreditsEntry_NobOgasawara                     = {FALSE, sCreditsText_NobOgasawara};
static const struct CreditsEntry sCreditsEntry_TeresaLillygren                  = {FALSE, sCreditsText_TeresaLillygren};
static const struct CreditsEntry sCreditsEntry_KimikoNakamichi                  = {FALSE, sCreditsText_KimikoNakamichi};
static const struct CreditsEntry sCreditsEntry_SouichiYamamoto                  = {FALSE, sCreditsText_SouichiYamamoto};
static const struct CreditsEntry sCreditsEntry_YuichiroIto                      = {FALSE, sCreditsText_YuichiroIto};
static const struct CreditsEntry sCreditsEntry_ThomasHertzog                    = {FALSE, sCreditsText_ThomasHertzog};
static const struct CreditsEntry sCreditsEntry_MikaKurosawa                     = {FALSE, sCreditsText_MikaKurosawa};
static const struct CreditsEntry sCreditsEntry_NationalFederationBlind          = {FALSE, sCreditsText_NationalFederationBlind};
static const struct CreditsEntry sCreditsEntry_PatriciaAMaurer                  = {FALSE, sCreditsText_PatriciaAMaurer};
static const struct CreditsEntry sCreditsEntry_EuropeanBlindUnion               = {FALSE, sCreditsText_EuropeanBlindUnion};
static const struct CreditsEntry sCreditsEntry_RoyalNewZealandFederationBlind   = {FALSE, sCreditsText_RoyalNewZealandFederationBlind};
static const struct CreditsEntry sCreditsEntry_MotoyasuTojima                   = {FALSE, sCreditsText_MotoyasuTojima};
static const struct CreditsEntry sCreditsEntry_NicolaPrattBarlow                = {FALSE, sCreditsText_NicolaPrattBarlow};
static const struct CreditsEntry sCreditsEntry_ShellieDow                       = {FALSE, sCreditsText_ShellieDow};
static const struct CreditsEntry sCreditsEntry_ErikJohnson                      = {FALSE, sCreditsText_ErikJohnson};

#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnEmeraldVersion,
        &sCreditsEntry_Credits,
        _,
        _
    },
    [PAGE_DIRECTOR] = {
        _,
        &sCreditsEntry_Director,
        &sCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    [PAGE_ART_DIRECTOR] = {
        _,
        &sCreditsEntry_ArtDirector,
        &sCreditsEntry_KenSugimori,
        _,
        _,
    },
    [PAGE_WORLD_DIRECTOR] = {
        _,
        &sCreditsEntry_WorldDirector,
        &sCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    [PAGE_LEAD_PROGRAMMER] = {
        &sCreditsEntry_LeadProgrammer,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_LeadGraphicArtist,
        &sCreditsEntry_MotofumiFujiwara,
        _,
    },
    [PAGE_PROGRAMMERS_1] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_NozomuSaito,
        _,
    },
    [PAGE_PROGRAMMERS_2] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_AkitoMori,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_MasaoTaya,
        _,
    },
    [PAGE_PROGRAMMERS_3] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_SatoshiNohara,
        &sCreditsEntry_MiyukiIwasawa,
        &sCreditsEntry_YoshinoriMatsuda,
        &sCreditsEntry_KeitaKagaya,
    },
    [PAGE_PROGRAMMERS_4] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_TetsuyaWatanabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_TakenoriOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_1] = {
        _,
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_SatoshiOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_2] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenkichiToyama,
        &sCreditsEntry_AsukaIwashita,
        &sCreditsEntry_TakaoUnno,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_3] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_AimiTomita,
        &sCreditsEntry_KanakoEo,
    },
    [PAGE_MUSIC_COMPOSITION] = {
        &sCreditsEntry_MusicComposition,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_MorikazuAoki,
        &sCreditsEntry_HitomiSato,
    },
    [PAGE_SOUND_EFFECTS] = {
        _,
        &sCreditsEntry_SoundEffectsAndPkmnVoices,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_MorikazuAoki,
        _,
    },
    [PAGE_GAME_DESIGNERS_1] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_TakeshiKawachimaru,
        &sCreditsEntry_AkihitoTomisawa,
    },
    [PAGE_GAME_DESIGNERS_2] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_KenjiMatsushima,
    },
    [PAGE_GAME_DESIGNERS_3] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TadashiTakahashi,
    },
    [PAGE_SCENARIO_PLOT] = {
        &sCreditsEntry_ScenarioPlot,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        _,
    },
    [PAGE_SCENARIO] = {
        &sCreditsEntry_Scenario,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    [PAGE_SCRIPT_DESIGNERS] = {
        &sCreditsEntry_ScriptDesigners,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    [PAGE_MAP_DESIGNERS] = {
        &sCreditsEntry_MapDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TetsujiOhta,
    },
    [PAGE_BATTLE_FRONTIER_DATA] = {
        _,
        &sCreditsEntry_BattleFrontierData,
        &sCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    [PAGE_PARAMETRIC_DESIGNERS] = {
        &sCreditsEntry_ParametricDesigners,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_KojiNishino,
    },
    [PAGE_POKEDEX_TEXT] = {
        _,
        &sCreditsEntry_PokedexText,
        &sCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1] = {
        &sCreditsEntry_EnvAndToolPgrms,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_AkitoMori,
    },
    [PAGE_PKMN_DESIGNERS_1] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_ShigekiMorimoto,
        _,
    },
    [PAGE_PKMN_DESIGNERS_2] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_SatoshiOhta,
        &sCreditsEntry_AsukaIwashita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_3] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_TakaoUnno,
        &sCreditsEntry_KanakoEo,
        &sCreditsEntry_AimiTomita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_4] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_AtsukoNishida,
        &sCreditsEntry_MuneoSaito,
        &sCreditsEntry_RenaYoshikawa,
        &sCreditsEntry_JunOkutani,
    },
    [PAGE_SUPPORT_PROGRAMMERS] = {
        _,
        &sCreditsEntry_SupportProgrammers,
        &sCreditsEntry_SatoshiMitsuhara,
        &sCreditsEntry_DaisukeHoshino,
        _,
    },
    [PAGE_NCL_PRODUCT_TESTING] = {
        _,
        &sCreditsEntry_NCLProductTesting,
        &sCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    [PAGE_PACKAGE_AND_MANUAL] = {
        _,
        &sCreditsEntry_PackageAndManual,
        &sCreditsEntry_KenSugimori,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        _,
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KenjiTominaga,
        &sCreditsEntry_HirokiEnomoto,
        _,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KazuyaSuyama,
        &sCreditsEntry_KenjiroIto,
        &sCreditsEntry_MichikoTakizawa,
        &sCreditsEntry_MakikoTakada,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_MikikoOhhashi,
        &sCreditsEntry_TakanaoKondo,
        &sCreditsEntry_RuiKawaguchi,
        _,
    },
    [PAGE_SPECIAL_THANKS_4] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_TakahiroOhnishi,
        &sCreditsEntry_NorihideOkamura,
        &sCreditsEntry_ShunsukeKohori,
        _,
    },
    [PAGE_INFORMATION_SUPERVISORS] = {
        &sCreditsEntry_InfoSupervisors,
        &sCreditsEntry_KazuyukiTerada,
        &sCreditsEntry_YuriSakurai,
        &sCreditsEntry_YumiFunasaka,
        &sCreditsEntry_NaokoYanase,
    },
    [PAGE_ARTWORK_1] = {
        _,
        &sCreditsEntry_Artwork,
        &sCreditsEntry_SachikoNakamichi,
        &sCreditsEntry_FujikoNomura,
        _,
    },
    [PAGE_ARTWORK_2] = {
        _,
        &sCreditsEntry_Artwork,
        &sCreditsEntry_HideyukiNakajima,
        &sCreditsEntry_HidenoriSaeki,
        _,
    },
    [PAGE_ARTWORK_3] = {
        &sCreditsEntry_Artwork,
        &sCreditsEntry_YokoWatanabe,
        &sCreditsEntry_SakaeKimura,
        &sCreditsEntry_ChiakiShinkai,
        _,
    },
    [PAGE_COORDINATORS] = {
        &sCreditsEntry_Coordinators,
        &sCreditsEntry_KazukiYoshihara,
        &sCreditsEntry_AkiraKinashi,
        &sCreditsEntry_RetsujiNomoto,
        _,
    },
    [PAGE_ENGLISH_VERSION] = {
        _,
        &sCreditsEntry_EnglishVersion,
        &sCreditsEntry_HiroNakamura,
        &sCreditsEntry_SethMcMahill,
        _,
    },
    [PAGE_TRANSLATOR] = {
        _,
        &sCreditsEntry_Translator,
        &sCreditsEntry_NobOgasawara,
        _,
        _,
    },
    [PAGE_TEXT_EDITOR] = {
        _,
        &sCreditsEntry_TextEditor,
        &sCreditsEntry_TeresaLillygren,
        _,
        _,
    },
    [PAGE_NCL_COORDINATOR] = {
        _,
        &sCreditsEntry_NCLCoordinator,
        &sCreditsEntry_KimikoNakamichi,
        _,
        _,
    },
    [PAGE_PROGRAMMERS_5] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_TerukiMurakawa,
        &sCreditsEntry_SouichiYamamoto,
        &sCreditsEntry_YuichiroIto,
        &sCreditsEntry_AkiraKinashi,
    },
    [PAGE_GRAPHIC_DESIGNER] = {
        _,
        &sCreditsEntry_GraphicDesigner,
        &sCreditsEntry_AkiraKinashi,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2] = {
        &sCreditsEntry_EnvAndToolPgrms,
        &sCreditsEntry_TerukiMurakawa,
        &sCreditsEntry_SouichiYamamoto,
        &sCreditsEntry_KimikoNakamichi,
        _,
    },
    [PAGE_NOA_TESTING] = {
        &sCreditsEntry_NOAProductTesting,
        &sCreditsEntry_ThomasHertzog,
        &sCreditsEntry_ErikJohnson,
        &sCreditsEntry_MikaKurosawa,
        _,
    },
    [PAGE_SPECIAL_THANKS_5] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_HiroyukiUesugi,
        &sCreditsEntry_MotoyasuTojima,
        &sCreditsEntry_NicolaPrattBarlow,
        &sCreditsEntry_ShellieDow,
    },
    [PAGE_TASK_MANAGERS] = {
        _,
        &sCreditsEntry_TaskManagers,
        &sCreditsEntry_AzusaTajima,
        &sCreditsEntry_ShusakuEgami,
        _,
    },
    [PAGE_PRODUCERS] = {
        &sCreditsEntry_Producers,
        &sCreditsEntry_HiroyukiJinnai,
        &sCreditsEntry_HitoshiYamagami,
        &sCreditsEntry_GakujiNomoto,
        &sCreditsEntry_HiroakiTsuru,
    },
    [PAGE_EXECUTIVE_DIRECTOR] = {
        _,
        &sCreditsEntry_ExecutiveDirector,
        &sCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_1] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_SatoruIwata,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_2] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _

// Tabla de scripts de efectos de campo.
//
// Se indexa por las constantes FLDEFF_* y se construye con inicializadores
// designados a proposito: cada script queda en su indice por nombre, de modo
// que anadir o quitar entradas no puede desplazar a las demas. Antes esta
// tabla vivia en data/field_effect_scripts.s como una lista posicional y al
// eliminarse un efecto intermedio todos los indices siguientes se desplazaron.
//
// Los scripts en si siguen en data/field_effect_scripts.s.

extern u8 gFieldEffectScript_Ash[];
extern u8 gFieldEffectScript_AshLaunch[];
extern u8 gFieldEffectScript_AshPuff[];
extern u8 gFieldEffectScript_BerryTreeGrowthSparkle[];
extern u8 gFieldEffectScript_BikeTireTracks[];
extern u8 gFieldEffectScript_Bubbles[];
extern u8 gFieldEffectScript_DeepSandFootprints[];
extern u8 gFieldEffectScript_DestroyDeoxysRock[];
extern u8 gFieldEffectScript_ExclamationMarkIcon1[];
extern u8 gFieldEffectScript_FeetInFlowingWater[];
extern u8 gFieldEffectScript_FieldMoveShowMon[];
extern u8 gFieldEffectScript_FieldMoveShowMonInit[];
extern u8 gFieldEffectScript_FlyIn[];
extern u8 gFieldEffectScript_GroundImpactDust[];
extern u8 gFieldEffectScript_HallOfFameRecord[];
extern u8 gFieldEffectScript_HeartIcon[];
extern u8 gFieldEffectScript_HotSpringsWater[];
extern u8 gFieldEffectScript_JumpBigSplash[];
extern u8 gFieldEffectScript_JumpLongGrass[];
extern u8 gFieldEffectScript_JumpSmallSplash[];
extern u8 gFieldEffectScript_JumpTallGrass[];
extern u8 gFieldEffectScript_LongGrass[];
extern u8 gFieldEffectScript_MountainDisguise[];
extern u8 gFieldEffectScript_MoveDeoxysRock[];
extern u8 gFieldEffectScript_NPCUseFly[];
extern u8 gFieldEffectScript_PokeCenterHeal[];
extern u8 gFieldEffectScript_PokeballTrail[];
extern u8 gFieldEffectScript_QuestionMarkIcon[];
extern u8 gFieldEffectScript_RayquazaSpotlight[];
extern u8 gFieldEffectScript_Ripple[];
extern u8 gFieldEffectScript_SandDisguisePlaceholder[];
extern u8 gFieldEffectScript_SandFootprints[];
extern u8 gFieldEffectScript_SandPile[];
extern u8 gFieldEffectScript_SandPillar[];
extern u8 gFieldEffectScript_SecretBaseBootPC[];
extern u8 gFieldEffectScript_Shadow[];
extern u8 gFieldEffectScript_ShortGrass[];
extern u8 gFieldEffectScript_ShowCutGrass[];
extern u8 gFieldEffectScript_ShowSecretPowerCave[];
extern u8 gFieldEffectScript_ShowSecretPowerShrub[];
extern u8 gFieldEffectScript_ShowSecretPowerTree[];
extern u8 gFieldEffectScript_Sparkle[];
extern u8 gFieldEffectScript_Splash[];
extern u8 gFieldEffectScript_SurfBlob[];
extern u8 gFieldEffectScript_SweetScent[];
extern u8 gFieldEffectScript_TallGrass[];
extern u8 gFieldEffectScript_TracksBug[];
extern u8 gFieldEffectScript_TracksSlither[];
extern u8 gFieldEffectScript_TracksSpot[];
extern u8 gFieldEffectScript_TreeDisguise[];
extern u8 gFieldEffectScript_UseCutOnTallGrass[];
extern u8 gFieldEffectScript_UseCutOnTree[];
extern u8 gFieldEffectScript_UseDig[];
extern u8 gFieldEffectScript_UseDive[];
extern u8 gFieldEffectScript_UseFly[];
extern u8 gFieldEffectScript_UseRockSmash[];
extern u8 gFieldEffectScript_UseSecretPowerCave[];
extern u8 gFieldEffectScript_UseSecretPowerShrub[];
extern u8 gFieldEffectScript_UseSecretPowerTree[];
extern u8 gFieldEffectScript_UseStrength[];
extern u8 gFieldEffectScript_UseSurf[];
extern u8 gFieldEffectScript_UseTeleport[];
extern u8 gFieldEffectScript_UseWaterfall[];
extern u8 gFieldEffectScript_WaterSurfacing[];
extern u8 gFldEffScript_DoubleExclMarkIcon[];
extern u8 gFldEffScript_UseVsSeeker[];
extern u8 gFldEffScript_XIcon[];

u8 *const gFieldEffectScriptPointers[] =
{
    [FLDEFF_EXCLAMATION_MARK_ICON]     = gFieldEffectScript_ExclamationMarkIcon1,
    [FLDEFF_USE_CUT_ON_GRASS]          = gFieldEffectScript_UseCutOnTallGrass,
    [FLDEFF_USE_CUT_ON_TREE]           = gFieldEffectScript_UseCutOnTree,
    [FLDEFF_SHADOW]                    = gFieldEffectScript_Shadow,
    [FLDEFF_TALL_GRASS]                = gFieldEffectScript_TallGrass,
    [FLDEFF_RIPPLE]                    = gFieldEffectScript_Ripple,
    [FLDEFF_FIELD_MOVE_SHOW_MON]       = gFieldEffectScript_FieldMoveShowMon,
    [FLDEFF_ASH]                       = gFieldEffectScript_Ash,
    [FLDEFF_SURF_BLOB]                 = gFieldEffectScript_SurfBlob,
    [FLDEFF_USE_SURF]                  = gFieldEffectScript_UseSurf,
    [FLDEFF_DUST]                      = gFieldEffectScript_GroundImpactDust,
    [FLDEFF_USE_SECRET_POWER_CAVE]     = gFieldEffectScript_UseSecretPowerCave,
    [FLDEFF_JUMP_TALL_GRASS]           = gFieldEffectScript_JumpTallGrass,
    [FLDEFF_SAND_FOOTPRINTS]           = gFieldEffectScript_SandFootprints,
    [FLDEFF_JUMP_BIG_SPLASH]           = gFieldEffectScript_JumpBigSplash,
    [FLDEFF_SPLASH]                    = gFieldEffectScript_Splash,
    [FLDEFF_JUMP_SMALL_SPLASH]         = gFieldEffectScript_JumpSmallSplash,
    [FLDEFF_LONG_GRASS]                = gFieldEffectScript_LongGrass,
    [FLDEFF_JUMP_LONG_GRASS]           = gFieldEffectScript_JumpLongGrass,
    [FLDEFF_WATER_SURFACING]           = gFieldEffectScript_WaterSurfacing,
    [FLDEFF_BERRY_TREE_GROWTH_SPARKLE] = gFieldEffectScript_BerryTreeGrowthSparkle,
    [FLDEFF_DEEP_SAND_FOOTPRINTS]      = gFieldEffectScript_DeepSandFootprints,
    [FLDEFF_POKECENTER_HEAL]           = gFieldEffectScript_PokeCenterHeal,
    [FLDEFF_USE_SECRET_POWER_TREE]     = gFieldEffectScript_UseSecretPowerTree,
    [FLDEFF_USE_SECRET_POWER_SHRUB]    = gFieldEffectScript_UseSecretPowerShrub,
    [FLDEFF_TREE_DISGUISE]             = gFieldEffectScript_TreeDisguise,
    [FLDEFF_MOUNTAIN_DISGUISE]         = gFieldEffectScript_MountainDisguise,
    [FLDEFF_NPCFLY_OUT]                = gFieldEffectScript_NPCUseFly,
    [FLDEFF_USE_FLY]                   = gFieldEffectScript_UseFly,
    [FLDEFF_FLY_IN]                    = gFieldEffectScript_FlyIn,
    [FLDEFF_QUESTION_MARK_ICON]        = gFieldEffectScript_QuestionMarkIcon,
    [FLDEFF_FEET_IN_FLOWING_WATER]     = gFieldEffectScript_FeetInFlowingWater,
    [FLDEFF_BIKE_TIRE_TRACKS]          = gFieldEffectScript_BikeTireTracks,
    [FLDEFF_SAND_DISGUISE]             = gFieldEffectScript_SandDisguisePlaceholder,
    [FLDEFF_USE_ROCK_SMASH]            = gFieldEffectScript_UseRockSmash,
    [FLDEFF_USE_DIG]                   = gFieldEffectScript_UseDig,
    [FLDEFF_SAND_PILE]                 = gFieldEffectScript_SandPile,
    [FLDEFF_USE_STRENGTH]              = gFieldEffectScript_UseStrength,
    [FLDEFF_SHORT_GRASS]               = gFieldEffectScript_ShortGrass,
    [FLDEFF_HOT_SPRINGS_WATER]         = gFieldEffectScript_HotSpringsWater,
    [FLDEFF_USE_WATERFALL]             = gFieldEffectScript_UseWaterfall,
    [FLDEFF_USE_DIVE]                  = gFieldEffectScript_UseDive,
    [FLDEFF_POKEBALL_TRAIL]            = gFieldEffectScript_PokeballTrail,
    [FLDEFF_HEART_ICON]                = gFieldEffectScript_HeartIcon,
    [FLDEFF_ASH_PUFF]                  = gFieldEffectScript_AshPuff,
    [FLDEFF_ASH_LAUNCH]                = gFieldEffectScript_AshLaunch,
    [FLDEFF_SWEET_SCENT]               = gFieldEffectScript_SweetScent,
    [FLDEFF_SAND_PILLAR]               = gFieldEffectScript_SandPillar,
    [FLDEFF_BUBBLES]                   = gFieldEffectScript_Bubbles,
    [FLDEFF_SPARKLE]                   = gFieldEffectScript_Sparkle,
    [FLDEFF_SECRET_POWER_CAVE]         = gFieldEffectScript_ShowSecretPowerCave,
    [FLDEFF_SECRET_POWER_TREE]         = gFieldEffectScript_ShowSecretPowerTree,
    [FLDEFF_SECRET_POWER_SHRUB]        = gFieldEffectScript_ShowSecretPowerShrub,
    [FLDEFF_CUT_GRASS]                 = gFieldEffectScript_ShowCutGrass,
    [FLDEFF_FIELD_MOVE_SHOW_MON_INIT]  = gFieldEffectScript_FieldMoveShowMonInit,
    [FLDEFF_PCTURN_ON]                 = gFieldEffectScript_SecretBaseBootPC,
    [FLDEFF_HALL_OF_FAME_RECORD]       = gFieldEffectScript_HallOfFameRecord,
    [FLDEFF_USE_TELEPORT]              = gFieldEffectScript_UseTeleport,
    [FLDEFF_RAYQUAZA_SPOTLIGHT]        = gFieldEffectScript_RayquazaSpotlight,
    [FLDEFF_DESTROY_DEOXYS_ROCK]       = gFieldEffectScript_DestroyDeoxysRock,
    [FLDEFF_MOVE_DEOXYS_ROCK]          = gFieldEffectScript_MoveDeoxysRock,
    [FLDEFF_USE_VS_SEEKER]             = gFldEffScript_UseVsSeeker,
    [FLDEFF_X_ICON]                    = gFldEffScript_XIcon,
    [FLDEFF_DOUBLE_EXCL_MARK_ICON]     = gFldEffScript_DoubleExclMarkIcon,
    [FLDEFF_TRACKS_SLITHER]            = gFieldEffectScript_TracksSlither,
    [FLDEFF_TRACKS_BUG]                = gFieldEffectScript_TracksBug,
    [FLDEFF_TRACKS_SPOT]               = gFieldEffectScript_TracksSpot,
};

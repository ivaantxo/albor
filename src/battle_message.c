#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "menu.h"
#include "palette.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static EWRAM_DATA u16 sBattlerAbilities[NUMERO_COMBATIENTES] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_PkmnGainedEXP[] = _("¡{B_BUFF1} ganó {B_BUFF2} {B_BUFF3} puntos de experiencia!");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} aprendió {B_BUFF2}!{WAIT_SE}");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} puede aprender {B_BUFF2}.");
static const u8 sText_TryToLearnMove2[] = _("Pero {B_BUFF1} ya conoce cuatro ataques.");
static const u8 sText_TryToLearnMove3[] = _("¿Quieres que olvide algún ataque?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} olvidó {B_BUFF2}.");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}¿No quieres que aprenda {B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} no aprendió {B_BUFF2}.");
static const u8 sText_ItDoesntAffect[] = _("It doesn't affect {B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_PlayerLostToEnemyTrainer[] = _("{B_PLAYER_NAME} is out of usable POKéMON! Player lost against {B_TRAINER_CLASS} {B_TRAINER_NAME}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _("{B_PLAYER_NAME} paid ¥{B_BUFF1} as the prize money… … … … {B_PLAYER_NAME} whited out!{PAUSE_UNTIL_PRESS}");
static const u8 sText_HitXTimes[] = _("¡Golpeó {B_BUFF1} veces!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX} fell asleep!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1} made {B_EFF_NAME_WITH_PREFIX} sleep!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} is already asleep!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} is already asleep!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX} wasn't affected!");
static const u8 sText_PkmnWasPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue envenenado!");
static const u8 sText_PkmnPoisonedBy[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue envenenado por {B_BUFF1} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBadlyPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX} está gravemente envenenado!");
static const u8 sText_PkmnEnergyDrained[] = _("¡{B_DEF_NAME_WITH_PREFIX} fue drenado!");
static const u8 sText_PkmnWasBurned[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue quemado!");
static const u8 sText_PkmnGotFrostbite[] = _("¡{B_EFF_NAME_WITH_PREFIX} fue congelado!");
static const u8 sText_PkmnBurnedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX} ha quemado a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("¡{B_ATK_NAME_WITH_PREFIX} está dolido por su quemadura!");
static const u8 sText_PkmnHurtByFrostbite[] = _("{B_ATK_NAME_WITH_PREFIX} está dolido por su congelación!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} already has a burn.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} was frozen solid!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1} froze {B_EFF_NAME_WITH_PREFIX} solid!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} is frozen solid!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} was defrosted!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} was defrosted!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} was defrosted by {B_CURRENT_MOVE}!");
static const u8 sText_PkmnFrostbiteHealed[] = _("{B_DEF_NAME_WITH_PREFIX}'s frostbite was healed!");
static const u8 sText_PkmnFrostbiteHealed2[] = _("{B_ATK_NAME_WITH_PREFIX}'s frostbite was healed!");
static const u8 sText_PkmnFrostbiteHealedBy[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} healed its frostbite!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} is paralyzed! It may be unable to move!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1} paralyzed {B_EFF_NAME_WITH_PREFIX}!\lIt may be unable to move!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} is paralyzed! It can't move!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX} is already paralyzed!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX} was healed of paralysis!");
static const u8 sText_PkmnDreamEaten[] = _("{B_DEF_NAME_WITH_PREFIX}'s dream was eaten!");
static const u8 sText_StatsWontIncrease[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} won't go higher!");
static const u8 sText_StatsWontDecrease[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go lower!");
static const u8 sText_TeamStoppedWorking[] = _("Your team's {B_BUFF1} stopped working!");
static const u8 sText_FoeStoppedWorking[] = _("The foe's {B_BUFF1} stopped working!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} is confused!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} snapped out of confusion!");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX} became confused!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} is already confused!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX} fell in love!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} is in love with {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("{B_ATK_NAME_WITH_PREFIX} is immobilized by love!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} was blown away!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} flinched!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} regained health!");
static const u8 sText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX}'s HP is full!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE} raised SP. DEF!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE} raised SP. DEF a little!");
static const u8 sText_PkmnRaisedDef[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE} raised DEFENSE!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_ATK_PREFIX2}'s {B_CURRENT_MOVE} raised DEFENSE a little!");
static const u8 sText_PkmnCoveredByVeil[] = _("{B_ATK_PREFIX2}'s party is covered by a veil!");
static const u8 sText_PkmnUsedSafeguard[] = _("{B_DEF_NAME_WITH_PREFIX}'s party is protected by Safeguard!");
static const u8 sText_PkmnSafeguardExpired[] = _("{B_ATK_PREFIX3}'s party is no longer protected by Safeguard!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} went to sleep!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX} slept and became healthy!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX} whipped up a whirlwind!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} took in sunlight!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} lowered its head!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} is glowing!");
static const u8 sText_PkmnIsCloakedInAHarshLight[] = _("{B_ATK_NAME_WITH_PREFIX} became cloaked in a harsh light!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} flew up high!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} dug a hole!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} hid underwater!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} sprang up!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_DEF_NAME_WITH_PREFIX} was squeezed by {B_ATK_NAME_WITH_PREFIX}'s BIND!");
static const u8 sText_PkmnInSnapTrap[] = _("{B_DEF_NAME_WITH_PREFIX} got trapped by a snap trap!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped in the vortex!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} was trapped by SAND TOMB!");
static const u8 sText_PkmnWrappedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was WRAPPED by {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} CLAMPED {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX} kept going and crashed!");
const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_PREFIX2} became shrouded in MIST!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is protected by MIST!");
const u8 gText_PkmnGettingPumped[] = _("{B_DEF_NAME_WITH_PREFIX} is getting pumped!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX} is hit with recoil!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} is buffeted by the sandstorm!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} is pelted by HAIL!");
static const u8 sText_PkmnsXWoreOff[] = _("{B_ATK_PREFIX1}'s {B_BUFF1} wore off!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} was seeded!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} avoided the attack!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}'s health is sapped by Leech Seed!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} is fast asleep.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} woke up!");
static const u8 sText_PkmnUproarKeptAwake[] = _("But the uproar kept {B_SCR_ACTIVE_NAME_WITH_PREFIX} awake!");
static const u8 sText_PkmnWokeUpInUproar[] = _("The uproar woke {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} caused an uproar!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} is making an uproar!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} calmed down.");
static const u8 sText_PkmnCantSleepInUproar[] = _("But {B_DEF_NAME_WITH_PREFIX} can't sleep in an UPROAR!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} stockpiled {B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} can't stockpile any more!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("But {B_DEF_NAME_WITH_PREFIX} can't sleep in an UPROAR!");
static const u8 sText_UproarKeptPkmnAwake[] = _("But the UPROAR kept {B_DEF_NAME_WITH_PREFIX} awake!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} stayed awake using its {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} is storing energy!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} unleashed energy!");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} became confused due to fatigue!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} picked up ¥{B_BUFF1}!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} transformed into {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} made a SUBSTITUTE!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} already has a SUBSTITUTE!");
static const u8 sText_SubstituteDamaged[] = _("The SUBSTITUTE took damage for {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSubstituteFaded[] = _("{B_DEF_NAME_WITH_PREFIX}'s SUBSTITUTE faded!");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} must recharge!");
static const u8 sText_PkmnRageBuilding[] = _("{B_DEF_NAME_WITH_PREFIX}'s RAGE is building!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} is disabled no more!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX} got an ENCORE!");
static const u8 sText_PkmnEncoreEnded[] = _("{B_ATK_NAME_WITH_PREFIX}'s ENCORE ended!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} took aim at {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} SKETCHED {B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} is trying to take its foe with it!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} took {B_ATK_NAME_WITH_PREFIX} with it!");
static const u8 sText_PkmnReducedPP[] = _("Reduced {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} by {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} stole {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX} can't escape now!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} fell into a NIGHTMARE!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} is locked in a NIGHTMARE!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP and laid a CURSE on {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} is afflicted by the CURSE!");
static const u8 sText_SpikesScattered[] = _("¡Han caído púas en el campo de {B_DEF_TEAM2}!");
static const u8 sText_PkmnHurtBySpikes[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se ha pinchado con las púas!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identified {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("{B_ATK_NAME_WITH_PREFIX}'s PERISH count fell to {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} braced itself!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} ENDURED the hit!");
static const u8 sText_MagnitudeStrength[] = _("MAGNITUDE {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} cut its own HP and maximized ATTACK!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copied {B_DEF_NAME_WITH_PREFIX}'s stat changes!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX} shed LEECH SEED!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX} blew away spikes!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} fled from battle!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} foresaw an attack!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} chose {B_CURRENT_MOVE} as its destiny!");
static const u8 sText_PkmnCenterAttention[] = _("{B_DEF_NAME_WITH_PREFIX} became the center of attention!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX} began charging power!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} was subjected to torment!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} is tightening its focus!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX} fell for the Taunt!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} is ready to help {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("¡{B_ATK_NAME_WITH_PREFIX} cambió objetos con el rival!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} obtuvo {B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} obtuvo {B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} obtuvo {B_BUFF1}. {B_DEF_NAME_WITH_PREFIX} obtuvo {B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copied {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} made a WISH!");
static const u8 sText_PkmnWishCameTrue[] = _("{B_BUFF1}'s WISH came true!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} planted its roots!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} absorbed nutrients with its roots!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} anchored itself with its roots!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} made {B_DEF_NAME_WITH_PREFIX} drowsy!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} knocked off {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} swapped abilities with its opponent!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} sealed the opponent's move(s)!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} wants the opponent to bear a GRUDGE!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} lost all its PP due to the GRUDGE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} shrouded itself in {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back by MAGIC COAT!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} waits for a target to make a move!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} SNATCHED {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s move!");
static const u8 sText_ElectricityWeakened[] = _("Electricity's power was weakened!");
static const u8 sText_FireWeakened[] = _("Fire's power was weakened!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX} found one {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("A soothing aroma wafted through the area!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Items can't be used now.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("For {B_SCR_ACTIVE_NAME_WITH_PREFIX}, {B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used {B_LAST_ITEM} to get pumped!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} was dragged out!");
static const u8 sText_TheWallShattered[] = _("The wall shattered!");
static const u8 sText_PkmnMoveIsDisabled[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} is disabled!");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ATK_NAME_WITH_PREFIX} can't use the same move in a row due to the Torment!");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} after the Taunt!");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ATK_NAME_WITH_PREFIX} can't use the sealed {B_CURRENT_MOVE}!");
static const u8 sText_PkmnCantUseMoveThroatChop[] = _("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} due to Throat Chop!");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} made it rain!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} raised its SPEED!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} was protected by {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents {B_ATK_NAME_WITH_PREFIX}\lfrom using {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} restored HP using its {B_DEF_ABILITY}!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} made it the {B_BUFF1} type!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents paralysis!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents romance!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents poisoning!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents confusion!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} raised its FIRE power!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} anchors itself with {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} cuts {B_DEF_NAME_WITH_PREFIX}'s attack!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents stat loss!");
static const u8 sText_PkmnHurtsWith[] = _("{B_ATK_NAME_WITH_PREFIX} was hurt by {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
static const u8 sText_PkmnTraced[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} rastreó {B_BUFF2} de {B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} prevents burns!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} blocks {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} le hizo recuperar salud!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} whipped up a sandstorm!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} intensified the sun's rays!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents {B_BUFF1} loss!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} infatuated {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_NueveColas[] = _("¡Se ha activado la maldición de las nueve colas!");
static const u8 sText_Parasito[] = _("¡{B_DEF_NAME_WITH_PREFIX} le ha pasado su {B_DEF_ABILITY} a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} made {B_CURRENT_MOVE} ineffective!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} cured its {B_BUFF1} problem!");
static const u8 sText_ItSuckedLiquidOoze[] = _("It sucked up the liquid ooze!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} transformed!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} took the attack!"); //In gen 5+ but without naming the ability
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} prevents flinching!"); //not in gen 5+, ability popup
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} prevents {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} from working!");
static const u8 sText_PkmnsAbilityPreventsAbility[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} prevents {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} from working!"); //not in gen 5+, ability popup
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} cured its {B_BUFF1} problem!"); //not in gen 5+, ability popup
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} had no effect on {B_EFF_NAME_WITH_PREFIX}!"); //not in gen 5+, ability popup
const u8 gText_StatSharply[] = _("sharply ");
const u8 gText_StatRose[] = _("rose!");
static const u8 sText_StatHarshly[] = _("harshly ");
const u8 sText_StatFell[] = _("fell!");
static const u8 sText_AttackersStatRose[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Using {B_LAST_ITEM}, the {B_BUFF1} of {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("¡Las estadísticas de {B_ATK_NAME_WITH_PREFIX} no pueden subir más!");
static const u8 sText_StatsWontDecrease2[] = _("{B_DEF_NAME_WITH_PREFIX}'s stats won't go any lower!");
static const u8 sText_CriticalHit[] = _("¡Un golpe crítico!");
static const u8 sText_OneHitKO[] = _("It's a one-hit KO!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2, y{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}¡Guau!");
static const u8 sText_AndEllipsis[] = _("Y…");
static const u8 sText_NotVeryEffective[] = _("No es muy efectivo…");
static const u8 sText_SuperEffective[] = _("¡Es super efectivo!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}¡Lograste huir!");
static const u8 sText_PkmnFledUsing[] = _("¡{PLAY_SE SE_FLEE}La {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\le permite huir!");
static const u8 sText_WildPkmnFled[] = _("¡{PLAY_SE SE_FLEE}El {B_BUFF1} salvaje huyó!");
static const u8 sText_NoRunningFromTrainers[] = _("No! There's no running from a TRAINER battle!");
static const u8 sText_ButNothingHappened[] = _("¡Pero no ha pasado nada!");
static const u8 sText_ButItFailed[] = _("¡Pero falló!");
static const u8 sText_ItHurtConfusion[] = _("It hurt itself in its confusion!");
static const u8 sText_MirrorMoveFailed[] = _("The Mirror Move failed!");
static const u8 sText_StartedToRain[] = _("¡Ha empezado a llover!");
static const u8 sText_RainContinues[] = _("Sigue lloviendo…");
static const u8 sText_RainStopped[] = _("The rain stopped.");
static const u8 sText_SandstormBrewed[] = _("A sandstorm kicked up!");
static const u8 sText_SandstormRages[] = _("The sandstorm is raging.");
static const u8 sText_SandstormSubsided[] = _("The sandstorm subsided.");
static const u8 sText_SunlightGotBright[] = _("¡El Sol ha empezado a brillar!");
static const u8 sText_SunlightStrong[] = _("El Sol brilla fuerte.");
static const u8 sText_SunlightFaded[] = _("El Sol se ha tapado.");
static const u8 sText_StartedHail[] = _("¡Está granizando!");
static const u8 sText_HailContinues[] = _("Sigue granizando.");
static const u8 sText_HailStopped[] = _("Ha cesado el granizo.");
static const u8 sText_StartedSnow[] = _("¡Ha empezado a nevar!");
static const u8 sText_SnowContinues[] = _("La nieve sigue cayendo");
static const u8 sText_SnowStopped[] = _("La nieve ha parado.");
static const u8 sText_FogCreptUp[] = _("Fog crept up as thick as soup!");
static const u8 sText_FogIsDeep[] = _("The fog is deep…");
static const u8 sText_FogLifted[] = _("The fog lifted.");
static const u8 sText_FailedToSpitUp[] = _("But it failed to spit up a thing!"); //not in gen 5+, uses "but it failed"
static const u8 sText_FailedToSwallow[] = _("But it failed to swallow a thing!"); //not in gen 5+, uses "but it failed"
static const u8 sText_WindBecameHeatWave[] = _("The wind turned into a Heat Wave!"); //unused
static const u8 sText_StatChangesGone[] = _("All stat changes were eliminated!");
static const u8 sText_CoinsScattered[] = _("Coins were scattered everywhere!");
static const u8 sText_TooWeakForSubstitute[] = _("But it does not have enough HP left to make a substitute!");
static const u8 sText_SharedPain[] = _("The battlers shared their pain!");
static const u8 sText_BellChimed[] = _("A bell chimed!");
static const u8 sText_FaintInThree[] = _("All affected POKéMON will faint in three turns!");
static const u8 sText_NoPPLeft[] = _("¡No te quedan PP!");
static const u8 sText_ButNoPPLeft[] = _("But there was no PP left for the move!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignored orders while asleep!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignored orders!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} began to nap!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} is loafing around!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} won't obey!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} turned away!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} pretended not to notice!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER_CLASS} {B_TRAINER_NAME} is about to send out {B_BUFF2}. Will you switch your Pokémon?");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!");
static const u8 sText_UnPokemonSalvaje[] = _("¡Un {B_OPPONENT_MON1_NAME} salvaje!");
static const u8 sText_ElLegendario[] = _("¡El Legendario {B_OPPONENT_MON1_NAME}!");
static const u8 sText_EntrenadorQuiereLuchar[] = _("¡{B_TRAINER_CLASS} {B_TRAINER_NAME} quiere luchar!");
static const u8 sText_TrainerSentOutPkmn[] = _("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_OPPONENT_MON1_NAME}!");
static const u8 sText_TrainerSentOutTwoPkmn[] = _("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TrainerSentOutPkmn2[] = _("{B_TRAINER_CLASS} {B_TRAINER_NAME} sent out {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("¡Vamos, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("¡Vamos! ¡{B_PLAYER_MON1_NAME} y {B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("¡A luchar, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("¡Hazlo, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("¡A por ello, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("¡Tu rival está débil! ¡Tú puedes, {B_BUFF1}!");
static const u8 sText_PkmnThatsEnough[] = _("¡{B_BUFF1}, ya es suficiente! ¡Vuelve!");
static const u8 sText_PkmnComeBack[] = _("¡{B_BUFF1}, ven conmigo!");
static const u8 sText_PkmnOkComeBack[] = _("¡{B_BUFF1}, bien! ¡Cambio!");
static const u8 sText_PkmnGoodComeBack[] = _("¡Lo has hecho bien, {B_BUFF1}! ¡Descansa!");
static const u8 sText_TrainerWithdrewPkmn[] = _("{B_TRAINER_CLASS} {B_TRAINER_NAME} guardó a {B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _(" salvaje");
static const u8 sText_FoePkmnPrefix[] = _(" rival");
static const u8 sText_FoePkmnPrefix2[] = _("Foe");
static const u8 sText_AllyPkmnPrefix[] = _("Ally");
static const u8 sText_FoePkmnPrefix3[] = _("Opposing");
static const u8 sText_AllyPkmnPrefix2[] = _("Ally");
static const u8 sText_FoePkmnPrefix4[] = _("Opposing");
static const u8 sText_AllyPkmnPrefix3[] = _("Ally");
static const u8 sText_AttackerUsedX[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó {B_BUFF3}!");

const u8 *const gStatNamesTable[NUMERO_ESTADISTICAS_BATALLA] =
{
    gText_PS, gText_Ataque, gText_Defensa,
    gText_Velocidad, gText_AtEsp, gText_DefEsp,
    gText_Precision, gText_Evasion
};

static const u8 sText_PokeblockWasTooSpicy[] = _("was too spicy!");
static const u8 sText_PokeblockWasTooDry[] = _("was too dry!");
static const u8 sText_PokeblockWasTooSweet[] = _("was too sweet!");
static const u8 sText_PokeblockWasTooBitter[] = _("was too bitter!");
static const u8 sText_PokeblockWasTooSour[] = _("was too sour!");

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_TrainerBlockedBall[] = _("The TRAINER blocked the BALL!");
static const u8 sText_DontBeAThief[] = _("Don't be a thief!");
static const u8 sText_ItDodgedBall[] = _("It dodged the thrown BALL! This POKéMON can't be caught!");
static const u8 sText_YouMissedPkmn[] = _("You missed the POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Oh, no! The POKéMON broke free!");
static const u8 sText_ItAppearedCaught[] = _("Aww! It appeared to be caught!");
static const u8 sText_AarghAlmostHadIt[] = _("Aargh! Almost had it!");
static const u8 sText_ShootSoClose[] = _("Shoot! It was so close, too!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("¡Lo tienes! ¡Capturaste a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}");
static const u8 sText_GotchaPkmnCaughtWally[] = _("Gotcha! {B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("¿Quieres ponerle un mote a {B_DEF_NAME}?");
static const u8 sText_Someones[] = _("someone's");
static const u8 sText_Lanettes[] = _("LANETTE's");
static const u8 sText_ItIsRaining[] = _("Está lloviendo.");
static const u8 sText_ItIsSnowing[] = _("Está nevando.");
static const u8 sText_HaceMuchoCalor[] = _("Hace mucho calor.");
static const u8 sText_SandstormIsRaging[] = _("La tormenta de arena arrecia.");
static const u8 sText_BoxIsFull[] = _("La caja está llena. ¡No puedes capturar más!");
static const u8 sText_BerrySuffix[] = _(" BERRY");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured paralysis!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured poison!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} healed its burn!");
static const u8 sText_PkmnsItemHealedFrostbite[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} healed its frostbite!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} defrosted it!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} woke it from its sleep!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} snapped it out of confusion!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its {B_BUFF1} problem!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} normalized its status!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored health!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored {B_BUFF1}'s PP!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored its status!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_LAST_ITEM} restored its HP a little!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} allows the use of only {B_CURRENT_MOVE}!");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} hung on using its {B_LAST_ITEM}!");
static const u8 sText_YouThrowABallNowRight[] = _("You throw a BALL now, right? I… I'll do my best!");

// New battle strings.
static const u8 sText_PowerHerbActivation[] = _("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its {B_LAST_ITEM}!");
static const u8 sText_BadlyPoisonedByItem[] = _("{B_EFF_NAME_WITH_PREFIX} was badly poisoned by the {B_LAST_ITEM}!");
static const u8 sText_BurnedByItem[] = _("{B_EFF_NAME_WITH_PREFIX} was burned by the {B_LAST_ITEM}!");
static const u8 sText_TargetAbilityActivates[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} activates!");
static const u8 sText_GravityIntensified[] = _("Gravity intensified!");
static const u8 sText_TargetIdentified[] = _("{B_DEF_NAME_WITH_PREFIX} was identified!");
static const u8 sText_TargetWokeUp[] = _("{B_DEF_NAME_WITH_PREFIX} woke up!");
static const u8 sText_PkmnStoleAndAteItem[] = _("{B_ATK_NAME_WITH_PREFIX} stole and ate {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_PkmnWentBack[] = _("{B_ATK_NAME_WITH_PREFIX} went back to {B_ATK_TRAINER_NAME}!");
static const u8 sText_PkmnCantUseItemsAnymore[] = _("{B_DEF_NAME_WITH_PREFIX} can't use items anymore!");
static const u8 sText_PkmnPreventedFromHealing[] = _("{B_DEF_NAME_WITH_PREFIX} was prevented from healing!");
static const u8 sText_PkmnSwitchedAtkAndDef[] = _("{B_ATK_NAME_WITH_PREFIX} switched its Attack and Defense!");
static const u8 sText_PkmnsAbilitySuppressed[] = _("{B_DEF_NAME_WITH_PREFIX}'s ability was suppressed!");
static const u8 sText_ShieldedFromCriticalHits[] = _("The {B_CURRENT_MOVE} shielded {B_ATK_TEAM2} team from critical hits!");
static const u8 sText_SwitchedAtkAndSpAtk[] = _("{B_ATK_NAME_WITH_PREFIX} switched all its changes to its Attack and Sp. Atk with the target!");
static const u8 sText_SwitchedDefAndSpDef[] = _("{B_ATK_NAME_WITH_PREFIX} switched all its changes to its Defense and Sp. Def with the target!");
static const u8 sText_PkmnAcquiredAbility[] = _("{B_DEF_NAME_WITH_PREFIX} acquired {B_DEF_ABILITY}!");
static const u8 sText_PoisonSpikesScattered[] = _("¡Han caído púas tóxicas en el campo de {B_DEF_TEAM2}!");
static const u8 sText_PkmnSurroundedWithVeilOfWater[] = _("{B_ATK_NAME_WITH_PREFIX} surrounded itself with a veil of water!");
static const u8 sText_PkmnLevitatedOnElectromagnetism[] = _("{B_ATK_NAME_WITH_PREFIX} levitated on electromagnetism!");
static const u8 sText_PkmnTwistedDimensions[] = _("{B_ATK_NAME_WITH_PREFIX} twisted the dimensions!");
static const u8 sText_DimensionsWereTwisted[] = _("The dimensions were twisted!");
static const u8 sText_PointedStonesFloat[] =_("Pointed stones float in the air around {B_DEF_TEAM2} team!");
static const u8 sText_CloakedInMysticalMoonlight[] =_("It became cloaked in mystical moonlight!");
static const u8 sText_TrappedBySwirlingMagma[] =_("{B_DEF_NAME_WITH_PREFIX} became trapped by swirling magma!");
static const u8 sText_VanishedInstantly[] =_("{B_ATK_NAME_WITH_PREFIX} vanished instantly!");
static const u8 sText_ProtectedTeam[] =_("¡{B_CURRENT_MOVE} protegió {B_ATK_TEAM2} equipo!");
static const u8 sText_SharedItsGuard[] =_("{B_ATK_NAME_WITH_PREFIX} shared its guard with the target!");
static const u8 sText_SharedItsPower[] =_("{B_ATK_NAME_WITH_PREFIX} shared its power with the target!");
static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] =_("It created a bizarre area in which the Defense and Sp. Def stats are swapped!");
static const u8 sText_BizzareAreaCreated[] =_("A bizarre area was created in which the Defense and Sp. Def stats are swapped!");
static const u8 sText_BecameNimble[] =_("{B_ATK_NAME_WITH_PREFIX} became nimble!");
static const u8 sText_HurledIntoTheAir[] =_("{B_DEF_NAME_WITH_PREFIX} was hurled into the air!");
static const u8 sText_HeldItemsLoseEffects[] =_("It created a bizarre area in which Pokémon's held items lose their effects!");
static const u8 sText_BizarreArenaCreated[] =_("A bizarre area was created in which Pokémon's held items lose their effects!");
static const u8 sText_FellStraightDown[] =_("{B_DEF_NAME_WITH_PREFIX} fell straight down!");
static const u8 sText_TargetChangedType[] =_("{B_DEF_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!");
static const u8 sText_PkmnAcquiredSimple[] =_("{B_DEF_NAME_WITH_PREFIX} acquired Simple!"); //shouldn't directly use the name
static const u8 sText_KindOffer[] =_("{B_DEF_NAME_WITH_PREFIX} took the kind offer!");
static const u8 sText_ResetsTargetsStatLevels[] =_("{B_DEF_NAME_WITH_PREFIX}'s stat changes were removed!");
static const u8 sText_AllySwitchPosition[] =_("{B_ATK_NAME_WITH_PREFIX} and {B_SCR_ACTIVE_NAME_WITH_PREFIX} switched places!");
static const u8 sText_RestoreTargetsHealth[] =_("{B_DEF_NAME_WITH_PREFIX}'s HP was restored!");
static const u8 sText_TookPkmnIntoTheSky[] =_("{B_ATK_NAME_WITH_PREFIX} took {B_DEF_NAME_WITH_PREFIX} into the sky!");
static const u8 sText_FreedFromSkyDrop[] =_("{B_DEF_NAME_WITH_PREFIX} was freed from the Sky Drop!");
static const u8 sText_PostponeTargetMove[] =_("{B_DEF_NAME_WITH_PREFIX}'s move was postponed!");
static const u8 sText_ReflectTargetsType[] =_("{B_ATK_NAME_WITH_PREFIX} became the same type as {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TransferHeldItem[] =_("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM} from {B_ATK_NAME_WITH_PREFIX}");
static const u8 sText_EmbargoEnds[] = _("{B_ATK_NAME_WITH_PREFIX} can use items again!");
static const u8 sText_Electromagnetism[] = _("electromagnetism");
static const u8 sText_BufferEnds[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} wore off!");
static const u8 sText_ThroatChopEnds[] = _("{B_ATK_NAME_WITH_PREFIX} can use sound-based moves again!");
static const u8 sText_TelekinesisEnds[] = _("{B_ATK_NAME_WITH_PREFIX} was freed from the telekinesis!");
static const u8 sText_TailwindEnds[] = _("{B_ATK_TEAM1} team's Tailwind petered out!");
static const u8 sText_LuckyChantEnds[] = _("{B_ATK_TEAM1} team's Lucky Chant wore off!");
static const u8 sText_TrickRoomEnds[] = _("The twisted dimensions returned to normal!");
static const u8 sText_WonderRoomEnds[] = _("Wonder Room wore off, and Defense and Sp. Def stats returned to normal!");
static const u8 sText_MagicRoomEnds[] = _("Magic Room wore off, and held items' effects returned to normal!");
static const u8 sText_MudSportEnds[] = _("The effects of Mud Sport have faded.");
static const u8 sText_WaterSportEnds[] = _("The effects of Water Sport have faded.");
static const u8 sText_GravityEnds[] = _("Gravity returned to normal!");
static const u8 sText_AquaRingHeal[] = _("Aqua Ring restored {B_ATK_NAME_WITH_PREFIX}'s HP!");
static const u8 sText_TargetAbilityRaisedStat[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} raised its {B_BUFF1}!");
static const u8 sText_TargetAbilityLoweredStat[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} lowered its {B_BUFF1}!");
static const u8 sText_AttackerAbilityRaisedStat[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} raised its {B_BUFF1}!");
static const u8 sText_ScriptingAbilityRaisedStat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} raised its {B_BUFF1}!");
static const u8 sText_TargetsStatWasMaxedOut[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} maxed its {B_BUFF1}!");
static const u8 sText_PoisonHealHpUp[] = _("The poisoning healed {B_ATK_NAME_WITH_PREFIX} a little bit!");
static const u8 sText_Carnivoro[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha usado a {B_DEF_NAME_WITH_PREFIX} para recuperarse!");
static const u8 sText_BadDreamsDmg[] = _("{B_DEF_NAME_WITH_PREFIX} is tormented!");
static const u8 sText_MoldBreakerEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} breaks the mold!");
static const u8 sText_SolarPowerHpDrop[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} takes its toll!"); //don't think this message is displayed anymore
static const u8 sText_AftermathDmg[] = _("{B_ATK_NAME_WITH_PREFIX} was hurt!");
static const u8 sText_AnticipationActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shuddered!");
static const u8 sText_ForewarnActivates[] = _("{B_SCR_ACTIVE_ABILITY} alerted {B_SCR_ACTIVE_NAME_WITH_PREFIX} to {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1}!");
static const u8 sText_IceBodyHpGain[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} healed it a little bit!"); //don't think this message is displayed anymore
static const u8 sText_SnowWarningHail[] = _("It started to hail!");
static const u8 sText_SnowWarningSnow[] = _("It started to snow!");
static const u8 sText_FriskActivates[] = _("{B_ATK_NAME_WITH_PREFIX} frisked {B_DEF_NAME_WITH_PREFIX} and found its {B_LAST_ITEM}!");
static const u8 sText_UnnerveEnters[] = _("The opposing team is too nervous to eat Berries!");
static const u8 sText_HarvestBerry[] = _("{B_ATK_NAME_WITH_PREFIX} harvested its {B_LAST_ITEM}!");
static const u8 sText_LastAbilityRaisedBuff1[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} raised its {B_BUFF1}!");
static const u8 sText_MagicBounceActivates[] = _("The {B_DEF_NAME_WITH_PREFIX} bounced the {B_ATK_NAME_WITH_PREFIX} back!");
static const u8 sText_ProteanTypeChange[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} transformed it into the {B_BUFF1} type!");
static const u8 sText_SymbiosisItemPass[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} passed its {B_LAST_ITEM} to {B_ATK_NAME_WITH_PREFIX} through {B_LAST_ABILITY}!");
static const u8 sText_StealthRockDmg[] = _("Pointed stones dug into {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ToxicSpikesAbsorbed[] = _("The poison spikes disappeared from around {B_DEF_TEAM2} team's feet!");
static const u8 sText_ToxicSpikesPoisoned[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} fue envenenado por las púas tóxicas!");
static const u8 sText_StickyWebSwitchIn[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} was caught in a Sticky Web!");
static const u8 sText_HealingWishCameTrue[] = _("The healing wish came true for {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_HealingWishHealed[] = _("{B_ATK_NAME_WITH_PREFIX} regained health!");
static const u8 sText_LunarDanceCameTrue[] = _("{B_ATK_NAME_WITH_PREFIX} became cloaked in mystical moonlight!");
static const u8 sText_CursedBodyDisabled[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled by {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
static const u8 sText_AttackerAcquiredAbility[] = _("{B_ATK_NAME_WITH_PREFIX} acquired {B_ATK_ABILITY}!");
static const u8 sText_TargetStatWontGoHigher[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!");
static const u8 sText_PkmnMoveBouncedViaAbility[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back by {B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY}!");
static const u8 sText_ImposterTransform[] = _("{B_ATK_NAME_WITH_PREFIX} transformed into {B_DEF_NAME_WITH_PREFIX} using {B_LAST_ABILITY}!");
static const u8 sText_NotDoneYet[] = _("This move effect is not done yet!");
static const u8 sText_PkmnBlewAwayToxicSpikes[] = _("{B_ATK_NAME_WITH_PREFIX} blew away Toxic Spikes!");
static const u8 sText_PkmnBlewAwayStickyWeb[] = _("{B_ATK_NAME_WITH_PREFIX} blew away Sticky Web!");
static const u8 sText_PkmnBlewAwayStealthRock[] = _("{B_ATK_NAME_WITH_PREFIX} blew away Stealth Rock!");
static const u8 sText_SpikesDisappearedFromTeam[] = _("The spikes disappeared from the ground around {B_ATK_TEAM2} team!");
static const u8 sText_ToxicSpikesDisappearedFromTeam[] = _("The poison spikes disappeared from the ground around {B_ATK_TEAM2} team!");
static const u8 sText_StealthRockDisappearedFromTeam[] = _("The pointed stones disappeared from around {B_ATK_TEAM2} team!");
static const u8 sText_StickyWebDisappearedFromTeam[] = _("The sticky web has disappeared from the ground around {B_ATK_TEAM2} team!");
static const u8 sText_StickyWebUsed[] = _("A sticky web has been laid out on the ground around {B_DEF_TEAM2} team!");
static const u8 sText_TopsyTurvySwitchedStats[] = _("All stat changes on {B_DEF_NAME_WITH_PREFIX} were inverted!");
static const u8 sText_TargetElectrified[] = _("{B_DEF_NAME_WITH_PREFIX}'s moves have been electrified!");
static const u8 sText_AssaultVestDoesntAllow[] = _("{B_LAST_ITEM} impide el uso de ataques de estado.");
static const u8 sText_GravityPreventsUsage[] = _("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} because of gravity!");
static const u8 sText_HealBlockPreventsUsage[] = _("{B_ATK_NAME_WITH_PREFIX} was prevented from healing!");
const u8 sText_drastically[] = _("drastically ");
const u8 sText_severely[] = _("severely ");
static const u8 sText_Infestation[] = _("{B_DEF_NAME_WITH_PREFIX} has been afflicted with an infestation by {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_NoEffectOnTarget[] = _("It had no effect on {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_BurstingFlames[] = _("The bursting flames hit {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_BestowItemGiving[] = _("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM} from {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ThirdTypeAdded[] = _("{B_BUFF1} type was added to {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_FellForFeint[] = _("{B_DEF_NAME_WITH_PREFIX} fell for the feint!");
static const u8 sText_PokemonCannotUseMove[] = _("{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE}!");
static const u8 sText_CoveredInPowder[] = _("{B_DEF_NAME_WITH_PREFIX} is covered in powder!");
static const u8 sText_PowderExplodes[] = _("When the flame touched the powder on the Pokémon, it exploded!");
static const u8 sText_BelchCantUse[] = _("Belch cannot be used!");
static const u8 sText_SpectralThiefSteal[] = _("{B_ATK_NAME_WITH_PREFIX} stole the target's boosted stats!");
static const u8 sText_GravityGrounding[] = _("{B_DEF_NAME_WITH_PREFIX} can't stay airborne because of gravity!");
static const u8 sText_SafetyGogglesProtected[] = _("{B_DEF_NAME_WITH_PREFIX} is not affected thanks to its {B_LAST_ITEM}!");
static const u8 sText_FlowerVeilProtected[] = _("¡{B_DEF_NAME_WITH_PREFIX} protegió al equipo con un velo de pétalos!");
static const u8 sText_SweetVeilProtected[] = _("{B_DEF_NAME_WITH_PREFIX} surrounded itself with a veil of sweetness!");
static const u8 sText_AromaVeilProtected[] = _("{B_DEF_NAME_WITH_PREFIX} is protected by an aromatic veil!");
static const u8 sText_CelebrateMessage[] = _("Congratulations, {B_PLAYER_NAME}!");
static const u8 sText_UsedInstructedMove[] = _("{B_ATK_NAME_WITH_PREFIX} followed  {B_BUFF1}'s instructions!");
static const u8 sText_LaserFocusMessage[] = _("{B_ATK_NAME_WITH_PREFIX} concentrated intensely!");
static const u8 sText_GemActivates[] = _("The {B_LAST_ITEM} strengthened {B_ATK_NAME_WITH_PREFIX}'s power!");
static const u8 sText_BerryDmgReducing[] = _("The {B_LAST_ITEM} weakened the damage to {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAteItem[] = _("{B_DEF_NAME_WITH_PREFIX} ate its {B_LAST_ITEM}!");
static const u8 sText_AirBalloonFloat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} floats in the air with its Air Balloon!");
static const u8 sText_AirBalloonPop[] = _("{B_DEF_NAME_WITH_PREFIX}'s Air Balloon popped!");
static const u8 sText_IncinerateBurn[] = _("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} was burnt up!");
static const u8 sText_BugBite[] = _("{B_ATK_NAME_WITH_PREFIX} stole and ate its target's {B_LAST_ITEM}!");
static const u8 sText_IllusionWoreOff[] = _("{B_DEF_NAME_WITH_PREFIX}'s illusion wore off!");
static const u8 sText_AttackerCuredTargetStatus[] = _("{B_ATK_NAME_WITH_PREFIX} cured {B_DEF_NAME_WITH_PREFIX}'s problem!");
static const u8 sText_AttackerLostFireType[] = _("{B_ATK_NAME_WITH_PREFIX} burned itself out!");
static const u8 sText_HealerCure[] = _("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} cured {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s problem!");
static const u8 sText_ReceiverAbilityTakeOver[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} was taken over!");
static const u8 sText_PkmnAbsorbingPower[] = _("{B_ATK_NAME_WITH_PREFIX} is absorbing power!");
static const u8 sText_NoOneWillBeAbleToRun[] = _("No one will be able to run away during the next turn!");
static const u8 sText_DestinyKnotActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} fell in love because of the {B_LAST_ITEM}!");
static const u8 sText_CloakedInAFreezingLight[] = _("{B_ATK_NAME_WITH_PREFIX} became cloaked in a freezing light!");
static const u8 sText_ClearAmuletWontLowerStats[] = _("The effects of the {B_LAST_ITEM} held by {B_DEF_NAME_WITH_PREFIX} prevents its stats from being lowered!");
static const u8 sText_AuraFlaredToLife[] = _("{B_DEF_NAME_WITH_PREFIX}'s aura flared to life!");
static const u8 sText_AirLockActivates[] = _("The effects of weather disappeared.");
static const u8 sText_PressureActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is exerting its pressure!");
static const u8 sText_DarkAuraActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating a dark aura!");
static const u8 sText_Generador[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} genera energía y potencia ataques eléctricos de su equipo!");
static const u8 sText_EstaSomnoliento[] = _("¡{B_ATK_NAME_WITH_PREFIX} está echando una cabezada!");
static const u8 sText_FairyAuraActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is radiating a fairy aura!");
static const u8 sText_AuraBreakActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} reversed all other Pokémon's auras!");
static const u8 sText_ComatoseActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is drowsing!");
static const u8 sText_ScreenCleanerActivates[] = _("All screens on the field were cleansed!");
static const u8 sText_FetchedPokeBall[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} found a {B_LAST_ITEM}!");
static const u8 sText_BattlerAbilityRaisedStat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} raised its {B_BUFF1}!");
static const u8 sText_ASandstormKickedUp[] = _("A sandstorm kicked up!");
static const u8 sText_PkmnsWillPerishIn3Turns[] = _("Both Pokémon will perish in three turns!");  //don't think this message is displayed anymore
static const u8 sText_AbilityRaisedStatDrastically[] = _("{B_DEF_ABILITY} raised {B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} drastically!");
static const u8 sText_PkmnMadeShellGleam[] = _("{B_DEF_NAME_WITH_PREFIX} made its shell gleam! It's distorting type matchups!");
static const u8 sText_CuriousMedicineEnters[] = _("{B_EFF_NAME_WITH_PREFIX}'s stat changes were removed!");
static const u8 sText_CanActFaster[] = _("{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!");
static const u8 sText_MicleBerryActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} boosted the accuracy of its next move using {B_LAST_ITEM}!");
static const u8 sText_PkmnShookOffTheTaunt[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} shook off the taunt!");
static const u8 sText_PkmnGotOverItsInfatuation[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} got over its infatuation!");
static const u8 sText_ItemCannotBeRemoved[] = _("{B_ATK_NAME_WITH_PREFIX}'s item cannot be removed!");
static const u8 sText_StickyBarbTransfer[] = _("The {B_LAST_ITEM} attached itself to {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBurnHealed[] = _("{B_DEF_NAME_WITH_PREFIX}'s burn was cured!");
static const u8 sText_RedCardActivate[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} held up its Red Card against {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_EjectButtonActivate[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} is switched out with the {B_LAST_ITEM}!");
static const u8 sText_AttackerGotOverInfatuation[] =_("{B_ATK_NAME_WITH_PREFIX} got over its infatuation!");
static const u8 sText_TormentedNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} is no longer tormented!");
static const u8 sText_HealBlockedNoMore[] = _("{B_ATK_NAME_WITH_PREFIX} is cured of its heal block!");
static const u8 sText_AttackerBecameFullyCharged[] = _("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its bond with its trainer!");
static const u8 sText_AttackerBecameAshSpecies[] = _("{B_ATK_NAME_WITH_PREFIX} became Ash-Greninja!");
static const u8 sText_ExtremelyHarshSunlight[] = _("The sunlight turned extremely harsh!");
static const u8 sText_ExtremeSunlightFaded[] = _("The extremely harsh sunlight faded!");
static const u8 sText_MoveEvaporatedInTheHarshSunlight[] = _("The Water-type attack evaporated in the extremely harsh sunlight!");
static const u8 sText_ExtremelyHarshSunlightWasNotLessened[] = _("The extremely harsh sunlight was not lessened at all!");
static const u8 sText_HeavyRain[] = _("A heavy rain began to fall!");
static const u8 sText_HeavyRainLifted[] = _("The heavy rain has lifted!");
static const u8 sText_NoReliefFromHeavyRain[] = _("There is no relief from this heavy rain!");
static const u8 sText_StuffCheeksCantSelect[] = _("It can't use the move because it doesn't have a Berry!");
static const u8 sText_ButPokemonCantUseTheMove[] = _("But {B_ATK_NAME_WITH_PREFIX} can't use the move!");
static const u8 sText_ButHoopaCantUseIt[] = _("But {B_ATK_NAME_WITH_PREFIX} can't use it the way it is now!");
static const u8 sText_BrokeThroughProtection[] = _("It broke through {B_DEF_NAME_WITH_PREFIX}'s protection!");
static const u8 sText_AbilityAllowsOnlyMove[] = _("{B_ATK_ABILITY} only allows the use of {B_CURRENT_MOVE}!");
static const u8 sText_SwappedAbilities[] = _("{B_DEF_NAME_WITH_PREFIX} swapped Abilities with its target!");
static const u8 sText_BattlerTypeChangedTo[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s type changed to {B_BUFF1}!");
static const u8 sText_BothCanNoLongerEscape[] = _("Neither Pokémon can run away!");
static const u8 sText_CantEscapeDueToUsedMove[] = _("{B_ATK_NAME_WITH_PREFIX} can no longer escape because it used No Retreat!");
static const u8 sText_PkmnBecameWeakerToFire[] = _("{B_DEF_NAME_WITH_PREFIX} became weaker to fire!");
static const u8 sText_PkmnAboutToBeAttackedByItsItem[] = _("{B_DEF_NAME_WITH_PREFIX} is about to be attacked by its {B_BUFF1}!");
static const u8 sText_CantEscapeBecauseOfCurrentMove[] = _("{B_DEF_NAME_WITH_PREFIX} can no longer escape because of Octolock!");
static const u8 sText_NeutralizingGasEnters[] = _("Neutralizing gas filled the area!");
static const u8 sText_NeutralizingGasOver[] = _("The effects of the neutralizing gas wore off!");
static const u8 sText_PkmnTookTargetHigh[] = _("{B_ATK_NAME_WITH_PREFIX} took {B_DEF_NAME_WITH_PREFIX} into the sky!");
static const u8 sText_TargetTooHeavy[] = _("{B_DEF_NAME_WITH_PREFIX} is too heavy to be lifted!");
static const u8 sText_MeteorBeamCharging[] = _("{B_ATK_NAME_WITH_PREFIX} is overflowing with space power!");
static const u8 sText_AttackerExpelledThePoison[] = _("{B_ATK_NAME_WITH_PREFIX} managed to expel the poison so you wouldn't worry!");
static const u8 sText_AttackerShookItselfAwake[] = _("{B_ATK_NAME_WITH_PREFIX} shook itself awake so you wouldn't worry!");
static const u8 sText_AttackerBrokeThroughParalysis[] = _("{B_ATK_NAME_WITH_PREFIX} gathered all its energy to break through its paralysis so you wouldn't worry!");
static const u8 sText_AttackerHealedItsBurn[] = _("{B_ATK_NAME_WITH_PREFIX} cured its burn through sheer determination so you wouldn't worry!");
static const u8 sText_AttackerHealedItsFrostbite[] = _("{B_ATK_NAME_WITH_PREFIX} cured its frostbite through sheer determination so you wouldn't worry!");
static const u8 sText_TargetToughedItOut[] = _("{B_DEF_NAME_WITH_PREFIX} toughed it out so you wouldn't feel sad!");
static const u8 sText_AttackerLostElectricType[] = _("{B_ATK_NAME_WITH_PREFIX} used up all its electricity!");
static const u8 sText_AttackerSwitchedStatWithTarget[] = _("{B_ATK_NAME_WITH_PREFIX} switched {B_BUFF1} with its target!");
static const u8 sText_BeingHitChargedPkmnWithPower[] = _("Being hit by {B_CURRENT_MOVE} charged {B_DEF_NAME_WITH_PREFIX} with power!");
static const u8 sText_SunlightActivatedAbility[] = _("The harsh sunlight activated {B_SCR_ACTIVE_NAME_WITH_PREFIX}'s Protosynthesis!");
static const u8 sText_StatWasHeightened[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_BUFF1} was heightened!");
static const u8 sText_BoosterEnergyActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used its {B_LAST_ITEM} to activate {B_SCR_ACTIVE_ABILITY}!");
static const u8 sText_AbilityWeakenedSurroundingMonsStat[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}'s {B_SCR_ACTIVE_ABILITY} weakened the {B_BUFF1} of all surrounding Pokémon!");
static const u8 sText_AttackerGainedStrengthFromTheFallen[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} gained strength from the fallen!");
static const u8 sText_StockpiledEffectWoreOff[] = _("{B_ATK_NAME_WITH_PREFIX}'s stockpiled effect wore off!");
static const u8 sText_PkmnRevivedReadyToFight[] = _("{B_BUFF1} was revived and is ready to fight again!");
static const u8 sText_ItemRestoredSpeciesHealth[] = _("{B_BUFF1} had its HP restored.");
static const u8 sText_ItemCuredSpeciesStatus[] = _("{B_BUFF1} had its status healed!");
static const u8 sText_AtkTrappedDef[] = _("{B_ATK_NAME_WITH_PREFIX} trapped {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_MirrorHerbCopied[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} used its Mirror Herb to mirror its opponent's stat changes!");
static const u8 sText_PkmnItemMelted[] = _("{B_ATK_NAME_WITH_PREFIX} corroded {B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ITEM}!");
static const u8 sText_TeamGainedEXP[] = _("The rest of your team gained Exp. Points thanks to the Exp. Share!");
static const u8 sText_CurrentMoveCantSelect[] = _("{B_BUFF1} cannot be used!");
static const u8 sText_TargetIsBeingSaltCured[] = _("{B_DEF_NAME_WITH_PREFIX} is being salt cured!");
static const u8 sText_TargetIsHurtBySaltCure[] = _("{B_DEF_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!");
static const u8 sText_PkmnTellChillingReceptionJoke[] = _("{B_ATK_NAME_WITH_PREFIX} is preparing to tell a chillingly bad joke!");
static const u8 sText_ElectroShotCharging[] = _("{B_ATK_NAME_WITH_PREFIX} absorbed electricity!");
static const u8 sText_ShedItsTail[] = _("{B_ATK_NAME_WITH_PREFIX} shed its tail to create a decoy!");
static const u8 sText_TidyingUpComplete[] = _("Tidying up complete!");
static const u8 sText_WagglingAFinger[] = _("Waggling a finger let it use {B_CURRENT_MOVE}!");

const u8 *const gBattleStringsTable[NUMERO_TEXTOS_COMBATE] =
{
    [STRINGID_TIDYINGUPCOMPLETE] = sText_TidyingUpComplete,
    [STRINGID_SHEDITSTAIL] = sText_ShedItsTail,
    [STRINGID_ELECTROSHOTCHARGING] = sText_ElectroShotCharging,
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE] = sText_PkmnTellChillingReceptionJoke,
    [STRINGID_TARGETISHURTBYSALTCURE] = sText_TargetIsHurtBySaltCure,
    [STRINGID_TARGETISBEINGSALTCURED] = sText_TargetIsBeingSaltCured,
    [STRINGID_CURRENTMOVECANTSELECT] = sText_CurrentMoveCantSelect,
    [STRINGID_PKMNITEMMELTED] = sText_PkmnItemMelted,
    [STRINGID_MIRRORHERBCOPIED] = sText_MirrorHerbCopied,
    [STRINGID_THUNDERCAGETRAPPED] = sText_AtkTrappedDef,
    [STRINGID_ITEMRESTOREDSPECIESHEALTH] = sText_ItemRestoredSpeciesHealth,
    [STRINGID_ITEMCUREDSPECIESSTATUS] = sText_ItemCuredSpeciesStatus,
    [STRINGID_PKMNREVIVEDREADYTOFIGHT] = sText_PkmnRevivedReadyToFight,
    [STRINGID_STOCKPILEDEFFECTWOREOFF] = sText_StockpiledEffectWoreOff,
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN] = sText_AttackerGainedStrengthFromTheFallen,
    [STRINGID_STATWASHEIGHTENED] = sText_StatWasHeightened,
    [STRINGID_BOOSTERENERGYACTIVATES] = sText_BoosterEnergyActivates,
    [STRINGID_SUNLIGHTACTIVATEDABILITY] = sText_SunlightActivatedAbility,
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER] = sText_BeingHitChargedPkmnWithPower,
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET] = sText_AttackerSwitchedStatWithTarget,
    [STRINGID_TARGETTOUGHEDITOUT] = sText_TargetToughedItOut,
    [STRINGID_ATTACKERHEALEDITSBURN] = sText_AttackerHealedItsBurn,
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS] = sText_AttackerBrokeThroughParalysis,
    [STRINGID_ATTACKERSHOOKITSELFAWAKE] = sText_AttackerShookItselfAwake,
    [STRINGID_ATTACKEREXPELLEDTHEPOISON] = sText_AttackerExpelledThePoison,
    [STRINGID_PLAYERPAIDPRIZEMONEY] = sText_PlayerPaidPrizeMoney,
    [STRINGID_METEORBEAMCHARGING] = sText_MeteorBeamCharging,
    [STRINGID_PKMNINSNAPTRAP] = sText_PkmnInSnapTrap,
    [STRINGID_NEUTRALIZINGGASOVER] = sText_NeutralizingGasOver,
    [STRINGID_NEUTRALIZINGGASENTERS] = sText_NeutralizingGasEnters,
    [STRINGID_BATTLERTYPECHANGEDTO] = sText_BattlerTypeChangedTo,
    [STRINGID_SWAPPEDABILITIES] = sText_SwappedAbilities,
    [STRINGID_ABILITYALLOWSONLYMOVE] = sText_AbilityAllowsOnlyMove,
    [STRINGID_BROKETHROUGHPROTECTION] = sText_BrokeThroughProtection,
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE] = sText_ButPokemonCantUseTheMove,
    [STRINGID_BUTHOOPACANTUSEIT] = sText_ButHoopaCantUseIt,
    [STRINGID_STUFFCHEEKSCANTSELECT] = sText_StuffCheeksCantSelect,
    [STRINGID_NORELIEFROMHEAVYRAIN] = sText_NoReliefFromHeavyRain,
    [STRINGID_HEAVYRAINLIFTED] = sText_HeavyRainLifted,
    [STRINGID_HEAVYRAIN] = sText_HeavyRain,
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = sText_ExtremelyHarshSunlightWasNotLessened,
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT] = sText_MoveEvaporatedInTheHarshSunlight,
    [STRINGID_EXTREMESUNLIGHTFADED] = sText_ExtremeSunlightFaded,
    [STRINGID_EXTREMELYHARSHSUNLIGHT] = sText_ExtremelyHarshSunlight,
    [STRINGID_ATTACKERBECAMEASHSPECIES] = sText_AttackerBecameAshSpecies,
    [STRINGID_ATTACKERBECAMEFULLYCHARGED] = sText_AttackerBecameFullyCharged,
    [STRINGID_HEALBLOCKEDNOMORE] = sText_HealBlockedNoMore,
    [STRINGID_TORMENTEDNOMORE] = sText_TormentedNoMore,
    [STRINGID_ATKGOTOVERINFATUATION] = sText_AttackerGotOverInfatuation,
    [STRINGID_EJECTBUTTONACTIVATE] = sText_EjectButtonActivate,
    [STRINGID_REDCARDACTIVATE] = sText_RedCardActivate,
    [STRINGID_PKMNBURNHEALED] = sText_PkmnBurnHealed,
    [STRINGID_STICKYBARBTRANSFER] = sText_StickyBarbTransfer,
    [STRINGID_ITEMCANNOTBEREMOVED] = sText_ItemCannotBeRemoved,
    [STRINGID_PKMNGOTOVERITSINFATUATION] = sText_PkmnGotOverItsInfatuation,
    [STRINGID_PKMNSHOOKOFFTHETAUNT] = sText_PkmnShookOffTheTaunt,
    [STRINGID_MICLEBERRYACTIVATES] = sText_MicleBerryActivates,
    [STRINGID_CANACTFASTERTHANKSTO] = sText_CanActFaster,
    [STRINGID_CURIOUSMEDICINEENTERS] = sText_CuriousMedicineEnters,
    [STRINGID_PKMNMADESHELLGLEAM] = sText_PkmnMadeShellGleam,
    [STRINGID_ABILITYRAISEDSTATDRASTICALLY] = sText_AbilityRaisedStatDrastically,
    [STRINGID_PKMNSWILLPERISHIN3TURNS] = sText_PkmnsWillPerishIn3Turns,
    [STRINGID_ASANDSTORMKICKEDUP] = sText_ASandstormKickedUp,
    [STRINGID_BATTLERABILITYRAISEDSTAT] = sText_BattlerAbilityRaisedStat,
    [STRINGID_FETCHEDPOKEBALL] = sText_FetchedPokeBall,
    [STRINGID_CLEARAMULETWONTLOWERSTATS] = sText_ClearAmuletWontLowerStats,
    [STRINGID_CLOAKEDINAFREEZINGLIGHT] = sText_CloakedInAFreezingLight,
    [STRINGID_DESTINYKNOTACTIVATES] = sText_DestinyKnotActivates,
    [STRINGID_NOONEWILLBEABLETORUNAWAY] = sText_NoOneWillBeAbleToRun,
    [STRINGID_PKNMABSORBINGPOWER] = sText_PkmnAbsorbingPower,
    [STRINGID_RECEIVERABILITYTAKEOVER] = sText_ReceiverAbilityTakeOver,
    [STRINGID_SCRIPTINGABILITYSTATRAISE] = sText_ScriptingAbilityRaisedStat,
    [STRINGID_HEALERCURE] = sText_HealerCure,
    [STRINGID_ATTACKERLOSTFIRETYPE] = sText_AttackerLostFireType,
    [STRINGID_ATTACKERCUREDTARGETSTATUS] = sText_AttackerCuredTargetStatus,
    [STRINGID_ILLUSIONWOREOFF] = sText_IllusionWoreOff,
    [STRINGID_BUGBITE] = sText_BugBite,
    [STRINGID_INCINERATEBURN] = sText_IncinerateBurn,
    [STRINGID_AIRBALLOONPOP] = sText_AirBalloonPop,
    [STRINGID_AIRBALLOONFLOAT] = sText_AirBalloonFloat,
    [STRINGID_TARGETATEITEM] = sText_TargetAteItem,
    [STRINGID_BERRYDMGREDUCES] = sText_BerryDmgReducing,
    [STRINGID_GEMACTIVATES] = sText_GemActivates,
    [STRINGID_LASERFOCUS] = sText_LaserFocusMessage,
    [STRINGID_THROATCHOPENDS] = sText_ThroatChopEnds,
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP] = sText_PkmnCantUseMoveThroatChop,
    [STRINGID_USEDINSTRUCTEDMOVE] = sText_UsedInstructedMove,
    [STRINGID_CELEBRATEMESSAGE] = sText_CelebrateMessage,
    [STRINGID_AROMAVEILPROTECTED] = sText_AromaVeilProtected,
    [STRINGID_SWEETVEILPROTECTED] = sText_SweetVeilProtected,
    [STRINGID_FLOWERVEILPROTECTED] = sText_FlowerVeilProtected,
    [STRINGID_SAFETYGOGGLESPROTECTED] = sText_SafetyGogglesProtected,
    [STRINGID_SPECTRALTHIEFSTEAL] = sText_SpectralThiefSteal,
    [STRINGID_BELCHCANTSELECT] = sText_BelchCantUse,
    [STRINGID_PKMNGAINEDEXP] = sText_PkmnGainedEXP,
    [STRINGID_PKMNLEARNEDMOVE] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE] = sText_DidNotLearnMove,
    [TEXTO_COMBATE_ATAQUE_FALLO_ATACANTE] = COMPOUND_STRING("¡El ataque de {B_ATK_NAME_WITH_PREFIX}  falló!"),
    [TEXTO_COMBATE_ATAQUE_FALLO_DEFENSOR] = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} esquivó el ataque!"),
    [TEXTO_COMBATE_PROTECCION] = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se protegió!"),
    [STRINGID_STATSWONTINCREASE2] = sText_StatsWontIncrease2,
    [TEXTO_COMBATE_TELEPATA] = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} evadió el daño gracias a su compañero!"),
    [STRINGID_ITDOESNTAFFECT] = sText_ItDoesntAffect,
    [STRINGID_PKMNFELLASLEEP] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNBADLYPOISONED] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNTRANSFORMEDINTO] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNSHEDLEECHSEED] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK] = sText_PkmnForesawAttack,
    [STRINGID_PKMNCENTERATTENTION] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER] = sText_PkmnChargingPower,
    [STRINGID_PKMNHASNOMOVESLEFT] = COMPOUND_STRING("¡A {B_ATK_NAME_WITH_PREFIX} no le quedan PPs!"), // printselectionstring
    [STRINGID_PKMNSUBJECTEDTOTORMENT] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY] = gText_StatSharply,
    [STRINGID_STATROSE] = gText_StatRose,
    [STRINGID_STATHARSHLY] = sText_StatHarshly,
    [STRINGID_STATFELL] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT] = sText_CriticalHit,
    [STRINGID_ONEHITKO] = sText_OneHitKO,
    [STRINGID_123POOF] = sText_123Poof,
    [STRINGID_ANDELLIPSIS] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS] = sText_NoRunningFromTrainers,
    [STRINGID_BUTNOTHINGHAPPENED] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN] = sText_StartedToRain,
    [STRINGID_RAINCONTINUES] = sText_RainContinues,
    [STRINGID_RAINSTOPPED] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL] = sText_StartedHail,
    [STRINGID_HAILCONTINUES] = sText_HailContinues,
    [STRINGID_HAILSTOPPED] = sText_HailStopped,
    [STRINGID_STARTEDSNOW] = sText_StartedSnow,
    [STRINGID_SNOWCONTINUES] = sText_SnowContinues,
    [STRINGID_SNOWSTOPPED] = sText_SnowStopped,
    [STRINGID_FOGCREPTUP] = sText_FogCreptUp,
    [STRINGID_FOGISDEEP] = sText_FogIsDeep,
    [STRINGID_FOGLIFTED] = sText_FogLifted,
    [STRINGID_FAILEDTOSPITUP] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN] = sText_SharedPain,
    [STRINGID_BELLCHIMED] = sText_BellChimed,
    [STRINGID_FAINTINTHREE] = sText_FaintInThree,
    [STRINGID_NOPPLEFT] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT] = sText_ButNoPPLeft,
    [STRINGID_TRAINERBLOCKEDBALL] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED] = sText_GiveNicknameCaptured,
    [STRINGID_ITISRAINING] = sText_ItIsRaining,
    [STRINGID_ITISSNOWING] = sText_ItIsSnowing,
    [STRINGID_HACEMUCHOCALOR] = sText_HaceMuchoCalor,
    [STRINGID_SANDSTORMISRAGING] = sText_SandstormIsRaging,
    [STRINGID_PKMNIGNORESASLEEP] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP] = sText_PkmnBeganToNap,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_PKMNSITEMCUREDPARALYSIS] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3] = gText_EmptyString,
    [STRINGID_PKMNSXPREVENTSBURNS] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY] = sText_PkmnsXInfatuatedY,
    [STRINGID_NUEVECOLAS] = sText_NueveColas,
    [STRINGID_PARASITO] = sText_Parasito,
    [STRINGID_PKMNSXMADEYINEFFECTIVE] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP] = sText_PkmnSprangUp,
    [STRINGID_XFOUNDONEY] = sText_XFoundOneY,
    [STRINGID_SOOTHINGAROMA] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4] = sText_EmptyString4,
    [STRINGID_PKMNSXINTENSIFIEDSUN] = sText_PkmnsXIntensifiedSun,
    [TEXTO_COMBATE_LEVITACION] = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} es inmune a Tierra!"),
    [STRINGID_YOUTHROWABALLNOWRIGHT] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNFLEDUSING] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT] = sText_PkmnWasDraggedOut,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_BOXISFULL] = sText_BoxIsFull,
    [STRINGID_PKMNSXPREVENTSFLINCHING] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXWOREOFF] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_PKMNOBTAINEDX] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_PKMNSXHADNOEFFECTONY] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_QUESTIONFORFEITMATCH] = sText_QuestionForfeitMatch,
    [STRINGID_POWERHERB] = sText_PowerHerbActivation,
    [STRINGID_PSNBYITEM] = sText_BadlyPoisonedByItem,
    [STRINGID_BRNBYITEM] = sText_BurnedByItem,
    [STRINGID_DEFABILITYIN] = sText_TargetAbilityActivates,
    [STRINGID_GRAVITYINTENSIFIED] = sText_GravityIntensified,
    [STRINGID_TARGETIDENTIFIED] = sText_TargetIdentified,
    [STRINGID_TARGETWOKEUP] = sText_TargetWokeUp,
    [STRINGID_PKMNSTOLEANDATEITEM] = sText_PkmnStoleAndAteItem,
    [STRINGID_PKMNWENTBACK] = sText_PkmnWentBack,
    [STRINGID_PKMNCANTUSEITEMSANYMORE] = sText_PkmnCantUseItemsAnymore,
    [STRINGID_PKMNPREVENTEDFROMHEALING] = sText_PkmnPreventedFromHealing,
    [STRINGID_PKMNSWITCHEDATKANDDEF] = sText_PkmnSwitchedAtkAndDef,
    [STRINGID_PKMNSABILITYSUPPRESSED] = sText_PkmnsAbilitySuppressed,
    [STRINGID_SHIELDEDFROMCRITICALHITS] = sText_ShieldedFromCriticalHits,
    [STRINGID_SWITCHEDATKANDSPATK] = sText_SwitchedAtkAndSpAtk,
    [STRINGID_SWITCHEDDEFANDSPDEF] = sText_SwitchedDefAndSpDef,
    [STRINGID_PKMNACQUIREDABILITY] = sText_PkmnAcquiredAbility,
    [STRINGID_POISONSPIKESSCATTERED] = sText_PoisonSpikesScattered,
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER] = sText_PkmnSurroundedWithVeilOfWater,
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM] = sText_PkmnLevitatedOnElectromagnetism,
    [STRINGID_PKMNTWISTEDDIMENSIONS] = sText_PkmnTwistedDimensions,
    [STRINGID_DIMENSIONSWERETWISTED] = sText_DimensionsWereTwisted,
    [STRINGID_POINTEDSTONESFLOAT] = sText_PointedStonesFloat,
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT] = sText_CloakedInMysticalMoonlight,
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA] = sText_TrappedBySwirlingMagma,
    [STRINGID_VANISHEDINSTANTLY] = sText_VanishedInstantly,
    [STRINGID_PROTECTEDTEAM] = sText_ProtectedTeam,
    [STRINGID_SHAREDITSGUARD] = sText_SharedItsGuard,
    [STRINGID_SHAREDITSPOWER] = sText_SharedItsPower,
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON] = sText_SwapsDefAndSpDefOfAllPkmn,
    [STRINGID_BIZARREAREACREATED] = sText_BizzareAreaCreated,
    [STRINGID_BECAMENIMBLE] = sText_BecameNimble,
    [STRINGID_HURLEDINTOTHEAIR] = sText_HurledIntoTheAir,
    [STRINGID_HELDITEMSLOSEEFFECTS] = sText_HeldItemsLoseEffects,
    [STRINGID_BIZARREARENACREATED] = sText_BizarreArenaCreated,
    [STRINGID_FELLSTRAIGHTDOWN] = sText_FellStraightDown,
    [STRINGID_TARGETCHANGEDTYPE ] = sText_TargetChangedType,
    [STRINGID_PKMNACQUIREDSIMPLE] = sText_PkmnAcquiredSimple,
    [STRINGID_EMPTYSTRING5] = sText_EmptyString4,
    [STRINGID_KINDOFFER] = sText_KindOffer,
    [STRINGID_RESETSTARGETSSTATLEVELS] = sText_ResetsTargetsStatLevels,
    [STRINGID_EMPTYSTRING6] = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION] = sText_AllySwitchPosition,
    [STRINGID_RESTORETARGETSHEALTH] = sText_RestoreTargetsHealth,
    [STRINGID_TOOKPJMNINTOTHESKY] = sText_TookPkmnIntoTheSky,
    [STRINGID_FREEDFROMSKYDROP] = sText_FreedFromSkyDrop,
    [STRINGID_POSTPONETARGETMOVE] = sText_PostponeTargetMove,
    [STRINGID_REFLECTTARGETSTYPE] = sText_ReflectTargetsType,
    [STRINGID_TRANSFERHELDITEM] = sText_TransferHeldItem,
    [STRINGID_EMBARGOENDS] = sText_EmbargoEnds,
    [STRINGID_ELECTROMAGNETISM] = sText_Electromagnetism,
    [STRINGID_BUFFERENDS] = sText_BufferEnds,
    [STRINGID_TELEKINESISENDS] = sText_TelekinesisEnds,
    [STRINGID_TAILWINDENDS] = sText_TailwindEnds,
    [STRINGID_LUCKYCHANTENDS] = sText_LuckyChantEnds,
    [STRINGID_TRICKROOMENDS] = sText_TrickRoomEnds,
    [STRINGID_WONDERROOMENDS] = sText_WonderRoomEnds,
    [STRINGID_MAGICROOMENDS] = sText_MagicRoomEnds,
    [STRINGID_MUDSPORTENDS] = sText_MudSportEnds,
    [STRINGID_WATERSPORTENDS] = sText_WaterSportEnds,
    [STRINGID_GRAVITYENDS] = sText_GravityEnds,
    [STRINGID_AQUARINGHEAL] = sText_AquaRingHeal,
    [STRINGID_TARGETABILITYSTATRAISE] = sText_TargetAbilityRaisedStat,
    [STRINGID_TARGETSSTATWASMAXEDOUT] = sText_TargetsStatWasMaxedOut,
    [STRINGID_ATTACKERABILITYSTATRAISE] = sText_AttackerAbilityRaisedStat,
    [STRINGID_POISONHEALHPUP] = sText_PoisonHealHpUp,
    [STRINGID_CARNIVORO] = sText_Carnivoro,
    [STRINGID_BADDREAMSDMG] = sText_BadDreamsDmg,
    [STRINGID_MOLDBREAKERENTERS] = sText_MoldBreakerEnters,
    [STRINGID_SOLARPOWERHPDROP] = sText_SolarPowerHpDrop,
    [STRINGID_AFTERMATHDMG] = sText_AftermathDmg,
    [STRINGID_ANTICIPATIONACTIVATES] = sText_AnticipationActivates,
    [STRINGID_FOREWARNACTIVATES] = sText_ForewarnActivates,
    [STRINGID_ICEBODYHPGAIN] = sText_IceBodyHpGain,
    [STRINGID_SNOWWARNINGHAIL] = sText_SnowWarningHail,
    [STRINGID_SNOWWARNINGSNOW] = sText_SnowWarningSnow,
    [STRINGID_FRISKACTIVATES] = sText_FriskActivates,
    [STRINGID_UNNERVEENTERS] = sText_UnnerveEnters,
    [STRINGID_HARVESTBERRY] = sText_HarvestBerry,
    [STRINGID_LASTABILITYRAISEDSTAT] = sText_LastAbilityRaisedBuff1,
    [STRINGID_MAGICBOUNCEACTIVATES] = sText_MagicBounceActivates,
    [STRINGID_PROTEANTYPECHANGE] = sText_ProteanTypeChange,
    [STRINGID_SYMBIOSISITEMPASS] = sText_SymbiosisItemPass,
    [STRINGID_STEALTHROCKDMG] = sText_StealthRockDmg,
    [STRINGID_TOXICSPIKESABSORBED] = sText_ToxicSpikesAbsorbed,
    [STRINGID_TOXICSPIKESPOISONED] = sText_ToxicSpikesPoisoned,
    [STRINGID_STICKYWEBSWITCHIN] = sText_StickyWebSwitchIn,
    [STRINGID_HEALINGWISHCAMETRUE] = sText_HealingWishCameTrue,
    [STRINGID_HEALINGWISHHEALED] = sText_HealingWishHealed,
    [STRINGID_LUNARDANCECAMETRUE] = sText_LunarDanceCameTrue,
    [STRINGID_CUSEDBODYDISABLED] = sText_CursedBodyDisabled,
    [STRINGID_ATTACKERACQUIREDABILITY] = sText_AttackerAcquiredAbility,
    [STRINGID_TARGETABILITYSTATLOWER] = sText_TargetAbilityLoweredStat,
    [STRINGID_TARGETSTATWONTGOHIGHER] = sText_TargetStatWontGoHigher,
    [STRINGID_PKMNMOVEBOUNCEDABILITY] = sText_PkmnMoveBouncedViaAbility,
    [STRINGID_IMPOSTERTRANSFORM] = sText_ImposterTransform,
    [STRINGID_ASSAULTVESTDOESNTALLOW] = sText_AssaultVestDoesntAllow,
    [STRINGID_GRAVITYPREVENTSUSAGE] = sText_GravityPreventsUsage,
    [STRINGID_HEALBLOCKPREVENTSUSAGE] = sText_HealBlockPreventsUsage,
    [STRINGID_NOTDONEYET] = sText_NotDoneYet,
    [STRINGID_STICKYWEBUSED] = sText_StickyWebUsed,
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES] = sText_PkmnBlewAwayToxicSpikes,
    [STRINGID_PKMNBLEWAWAYSTICKYWEB] = sText_PkmnBlewAwayStickyWeb,
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK] = sText_PkmnBlewAwayStealthRock,
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM] = sText_SpikesDisappearedFromTeam,
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM] = sText_ToxicSpikesDisappearedFromTeam,
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM] = sText_StealthRockDisappearedFromTeam,
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM] = sText_StickyWebDisappearedFromTeam,
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM] = sText_SharpSteelDisappearedFromTeam,
    [STRINGID_TOPSYTURVYSWITCHEDSTATS] = sText_TopsyTurvySwitchedStats,
    [STRINGID_TARGETELECTRIFIED] = sText_TargetElectrified,
    [STRINGID_FERVENTWISHREACHED] = sText_FerventWishReached,
    [STRINGID_DRASTICALLY] = sText_drastically,
    [STRINGID_SEVERELY] = sText_severely,
    [STRINGID_INFESTATION] = sText_Infestation,
    [STRINGID_NOEFFECTONTARGET] = sText_NoEffectOnTarget,
    [STRINGID_BURSTINGFLAMESHIT] = sText_BurstingFlames,
    [STRINGID_BESTOWITEMGIVING] = sText_BestowItemGiving,
    [STRINGID_THIRDTYPEADDED] = sText_ThirdTypeAdded,
    [STRINGID_FELLFORFEINT] = sText_FellForFeint,
    [STRINGID_POKEMONCANNOTUSEMOVE] = sText_PokemonCannotUseMove,
    [STRINGID_COVEREDINPOWDER] = sText_CoveredInPowder,
    [STRINGID_POWDEREXPLODES] = sText_PowderExplodes,
    [STRINGID_GRAVITYGROUNDING] = sText_GravityGrounding,
    [STRINGID_AURAFLAREDTOLIFE] = sText_AuraFlaredToLife,
    [STRINGID_AIRLOCKACTIVATES] = sText_AirLockActivates,
    [STRINGID_PRESSUREENTERS] = sText_PressureActivates,
    [STRINGID_DARKAURAENTERS] = sText_DarkAuraActivates,
    [STRINGID_GENERADOR] = sText_Generador,
    [STRINGID_ESTASOMNOLIENTO] = sText_EstaSomnoliento,
    [STRINGID_FAIRYAURAENTERS] = sText_FairyAuraActivates,
    [STRINGID_AURABREAKENTERS] = sText_AuraBreakActivates,
    [STRINGID_COMATOSEENTERS] = sText_ComatoseActivates,
    [STRINGID_SCREENCLEANERENTERS] = sText_ScreenCleanerActivates,
    [STRINGID_BOTHCANNOLONGERESCAPE] = sText_BothCanNoLongerEscape,
    [STRINGID_CANTESCAPEDUETOUSEDMOVE] = sText_CantEscapeDueToUsedMove,
    [STRINGID_PKMNBECAMEWEAKERTOFIRE] = sText_PkmnBecameWeakerToFire,
    [STRINGID_ABOUTTOUSEPOLTERGEIST] = sText_PkmnAboutToBeAttackedByItsItem,
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE] = sText_CantEscapeBecauseOfCurrentMove,
    [STRINGID_PKMNTOOKTARGETHIGH] = sText_PkmnTookTargetHigh,
    [STRINGID_TARGETTOOHEAVY] = sText_TargetTooHeavy,
    [STRINGID_ATTACKERLOSTELECTRICTYPE] = sText_AttackerLostElectricType,
    [STRINGID_PKMNSABILITYPREVENTSABILITY] = sText_PkmnsAbilityPreventsAbility,
    [STRINGID_PKMNHURTBYFROSTBITE] = sText_PkmnHurtByFrostbite,
    [STRINGID_PKMNGOTFROSTBITE] = sText_PkmnGotFrostbite,
    [STRINGID_PKMNSITEMHEALEDFROSTBITE] = sText_PkmnsItemHealedFrostbite,
    [STRINGID_ATTACKERHEALEDITSFROSTBITE] = sText_AttackerHealedItsFrostbite,
    [STRINGID_PKMNFROSTBITEHEALED] = sText_PkmnFrostbiteHealed,
    [STRINGID_PKMNFROSTBITEHEALED2] = sText_PkmnFrostbiteHealed2,
    [STRINGID_PKMNFROSTBITEHEALEDBY] = sText_PkmnFrostbiteHealedBy,
    [STRINGID_TEAMGAINEDEXP] = sText_TeamGainedEXP,
    [STRINGID_CLOAKEDINAHARSHLIGHT] = sText_PkmnIsCloakedInAHarshLight,
};

const u32 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u32 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE, STRINGID_LUNARDANCECAMETRUE
};

const u32 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u32 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_GENERADOR] = STRINGID_GENERADOR,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u32 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u32 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN] = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_SUN] = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_HAIL] = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW] = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG] = STRINGID_FOGLIFTED,
};

const u32 gSandStormHailSnowContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES,
    [B_MSG_SNOW]      = STRINGID_SNOWCONTINUES,
};

const u32 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u32 gSandStormHailSnowEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED,
    [B_MSG_SNOW]      = STRINGID_SNOWSTOPPED,
};

const u32 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u32 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = TEXTO_COMBATE_PROTECCION,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u32 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u32 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u32 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u32 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u32 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u32 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u32 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u32 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u32 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u32 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index copied from move's index in sTrappingMoves
const u32 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA,
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,
};

const u32 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u32 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u32 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u32 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u32 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u32 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u32 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u32 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u32 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE
};

const u32 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED2,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u32 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u32 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u32 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u32 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u32 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u32 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u32 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u32 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u32 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_ITISSNOWING,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_HACEMUCHOCALOR,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u32 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u32 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u32 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u32 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u32 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u32 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u32 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u32 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u32 gStatus2StringIds[] =
{
    STRINGID_PKMNWASCONFUSED, STRINGID_PKMNFELLINLOVE, STRINGID_TARGETCANTESCAPENOW, STRINGID_PKMNSUBJECTEDTOTORMENT
};

const u8 gText_PkmnIsEvolving[] = _("What? {VAR_TEXTO_1} is evolving!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {VAR_TEXTO_1} evolved into {VAR_TEXTO_2}!{WAIT_SE}");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {VAR_TEXTO_1} stopped evolving!");
const u8 gText_EllipsisQuestionMark[] = _("……?");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK} GO NEAR{CLEAR_TO 56}RUN");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should be forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Yes No");

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}Safari Balls");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Left: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("sleep");
const u8 gText_Poison[] = _("poison");
const u8 gText_Burn[] = _("burn");
const u8 gText_Paralysis[] = _("paralysis");
const u8 gText_Ice[] = _("ice");
const u8 gText_Confusion[] = _("confusion");
const u8 gText_Love[] = _("love");
const u8 gText_Are[] = _("are");
const u8 gText_Are2[] = _("are");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Draw");

static const u8 sText_QuestionForfeitMatch[] = _("Would you like to forfeit the match and quit now?");
static const u8 sText_TrainerFled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER_CLASS} {B_TRAINER_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer[] = _("You lost to {B_TRAINER_CLASS} {B_TRAINER_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer[] = _("You battled to a draw against {B_TRAINER_CLASS} {B_TRAINER_NAME}!");
const u8 gText_RecordBattleToPass[] = _("Would you like to record your battle on your Frontier Pass?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}'s battle result was recorded on the Frontier Pass.");
static const u8 sText_Your1[] = _("Your");
static const u8 sText_Opposing1[] = _("The opposing");
static const u8 sText_Your2[] = _("your");
static const u8 sText_Opposing2[] = _("the opposing");

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 6,
        .bgColor = 2,
        .shadowColor = 4,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(2),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 4,
        .speed = 0,
        .fgColor = 4,
        .bgColor = 2,
        .shadowColor = 5,
    },
    [B_WIN_PP_1] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_2] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_3] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_PP_4] = {
        .fillValue = PIXEL_FILL(3),
        .fontId = FONT_NARROW,
        .x = 2,
        .y = 4,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 3,
        .shadowColor = 2,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

void BufferStringBattle(u16 stringID, u32 battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < NUMERO_COMBATIENTES; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case TEXTO_COMBATE_INTRO:
        if (EsContraEntrenador())
        {
            stringPtr = sText_EntrenadorQuiereLuchar;
        }
        else
        {
            if (gBattleTypeFlags & COMBATE_LEGENDARIO)
                stringPtr = sText_ElLegendario;
            else
                stringPtr = sText_UnPokemonSalvaje;
        }
        break;
    case TEXTO_COMBATE_ENVIAR_POKEMON:
        if (GetBattlerSide(battler) == LADO_JUGADOR)
        {
            if (EsContraEntrenador() && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[ALIADO(battler)]]))
            {
                stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (EsContraEntrenador() && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[ALIADO(battler)]]))
            {
                stringPtr = sText_TrainerSentOutTwoPkmn;
            }
            else
            {
                stringPtr = sText_TrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON:
        if (GetBattlerSide(battler) == LADO_JUGADOR)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || EsContraEntrenador())
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            stringPtr = sText_TrainerWithdrewPkmn;
        }
        break;
    case STRINGID_SWITCHINMON:
        if (GetBattlerSide(gBattleScripting.battler) == LADO_JUGADOR)
        {
            if (*(&gBattleStruct->hpScale) == 0 || EsContraEntrenador())
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            stringPtr = sText_TrainerSentOutPkmn2;
        }
        break;
    case STRINGID_USEDMOVE:
        StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default:
        if (stringID >= NUMERO_TEXTOS_COMBATE)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][4]))
            return gStatusConditionStringsTable[i];
    }
    return NULL;
}

static void GetBattlerNick(u32 battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetPartyBattlerData(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                          \
    GetBattlerNick(battler, text);                                    \
    toCpy = text;                                                     \
        while (*toCpy != EOS)                                         \
        {                                                             \
            dst[dstID] = *toCpy;                                      \
            dstID++;                                                  \
            toCpy++;                                                  \
        }                                                             \
    if (GetBattlerSide(battler) != LADO_JUGADOR)                     \
    {                                                                 \
        if (EsContraEntrenador())               \
            toCpy = sText_FoePkmnPrefix;                              \
        else                                                          \
            toCpy = sText_WildPkmnPrefix;                             \
    }

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId)
{
    const u8 *toCpy = GetTrainerNameFromId(trainerId);

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 battler)
{
    const u8 *toCpy = NULL;

    switch (battler)
    {
    case OPONENTE_IZQUIERDA:
    case OPONENTE_DERECHA:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 battler)
{
    if (GetBattlerSide(battler) == LADO_JUGADOR)
        return gSaveBlockPtr->nombreJugador;
    else
        return BattleStringGetOpponentName(battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u32 lastValidSkip = 0;
    u32 toCpyWidth = 0;
    u32 dstWidth = 0;
    // This buffer may hold either the name of a trainer, Pokémon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 fontId = FONT_NORMAL;
    s16 letterSpacing = 0;
    u32 lineNum = 1;

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;
        dstWidth = GetStringLineWidth(fontId, dst, letterSpacing, lineNum, dstSize);

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gVariableTexto1);
                    toCpy = gVariableTexto1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gVariableTexto2);
                    toCpy = gVariableTexto2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gVariableTexto3);
                    toCpy = gVariableTexto3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gVariableTexto1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gVariableTexto2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gVariableTexto3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(JUGADOR_IZQUIERDA, text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(OPONENTE_IZQUIERDA, text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(JUGADOR_DERECHA, text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(OPONENTE_DERECHA, text);
                toCpy = text;
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(ALIADO(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                CopyItemName(gLastUsedItem, text);
                toCpy = text;
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerAttacker]].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerTarget]].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattleScripting.battler]].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gEffectBattler]].name;
                break;
            case B_TXT_TRAINER_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent);
                break;
            case B_TXT_TRAINER_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent);
                break;
            case B_TXT_PLAYER_NAME:
                toCpy = gSaveBlockPtr->nombreJugador;
                break;
            case B_TXT_TRAINER_LOSE_TEXT: // trainerA lose text
                toCpy = GetTrainerLoseText();
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = gSaveBlockPtr->nombreJugador;
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (gBattlerAttacker)
                {
                case JUGADOR_DERECHA:
                    break;
                case OPONENTE_IZQUIERDA:
                case OPONENTE_DERECHA:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == LADO_JUGADOR)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == LADO_JUGADOR)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            }

            if (toCpy != NULL)
            {
                toCpyWidth = GetStringLineWidth(fontId, toCpy, letterSpacing, 1, dstSize);

                if (dstWidth + toCpyWidth > BATTLE_MSG_MAX_WIDTH)
                {
                    dst[lastValidSkip] = lineNum == 1 ? CHAR_NEWLINE : CHAR_PROMPT_SCROLL;
                    dstWidth = GetStringLineWidth(fontId, dst, letterSpacing, lineNum, dstSize);
                    lineNum++;
                }
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER_LOSE_TEXT
                || *src == B_TXT_TRAINER_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            toCpyWidth = GetGlyphWidth(dst[dstID + 1], fontId);
            dst[dstID] = *src;
            if (dstWidth + toCpyWidth > BATTLE_MSG_MAX_WIDTH)
            {
                dst[lastValidSkip] = lineNum == 1 ? CHAR_NEWLINE : CHAR_PROMPT_SCROLL;
                lineNum++;
                dstWidth = 0;
            }
            switch (*src)
            {
            case CHAR_NEWLINE:
            case CHAR_PROMPT_SCROLL:
            case CHAR_PROMPT_CLEAR:
                lineNum++;
                dstWidth = 0;
                //fallthrough
            case CHAR_SPACE:
                lastValidSkip = dstID;
                break;
            }
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void IllusionNickHack(u32 battler, u32 partyId, u8 *dst)
{
    s32 id, i;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(ALIADO(battler)))
            partnerMon = &gEnemyParty[gBattlerPartyIndexes[ALIADO(battler)]];
        else
            partnerMon = mon;

        // Find last alive non-egg pokemon.
        for (i = PARTY_SIZE - 1; i >= 0; i--)
        {
            id = i;
            if (GetMonData(&gEnemyParty[id], MON_DATA_SPECIES)
                && GetMonData(&gEnemyParty[id], MON_DATA_HP)
                && &gEnemyParty[id] != mon
                && &gEnemyParty[id] != partnerMon)
            {
                GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
                return;
            }
        }
    }

    GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (GetBattlerSide(src[srcID + 1]) == LADO_JUGADOR)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (EsContraEntrenador())
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == LADO_JUGADOR)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            CopyItemName(hword, dst);
            srcID += 3;
            break;
        }
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sTextOnWindowsInfo;
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * LADO_TILE);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    gTextFlags.useAlternateDownArrow = TRUE;
    gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG)
    {
        speed = GetPlayerTextSpeedDelay();
        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
    const u8 *msgLastHalfHp;
    const u8 *msgFirstCriticalHit;
    const u8 *msgFirstSuperEffectiveHit;
    const u8 *msgFirstSTABMove;
    const u8 *msgPlayerMonUnaffected;
    const u8 *msgBeforeFirstTurn;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    /* Put any trainer slide-in messages inside this array.
    Example:
    {
        .trainerId = TRAINER_WALLY_VR_2,
        .msgLastSwitchIn = sText_AarghAlmostHadIt,
        .msgLastLowHp = sText_BoxIsFull,
        .msgFirstDown = sText_123Poof,
        .msgLastHalfHp = sText_ShootSoClose,
        .msgFirstCriticalHit = sText_CriticalHit,
        .msgFirstSuperEffectiveHit = sText_SuperEffective,
        .msgFirstSTABMove = sText_ABoosted,
        .msgPlayerMonUnaffected = sText_ButNoEffect,
        .msgBeforeFirstTurn = sText_GravityIntensified,
    },
    */
};

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

enum
{
    LESS_THAN,
    EQUAL,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL,
};

u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
    case LESS_THAN:
        return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
    case EQUAL:
        return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN:
        return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
    case LESS_THAN_OR_EQUAL:
        return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN_OR_EQUAL:
        return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
    case NOT_EQUAL:
    default:
        return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

bool32 ShouldDoTrainerSlide(u32 battler, u32 which)
{
    u32 i, firstId, lastId, trainerId, retValue = 1;

    if (!(EsContraEntrenador()) || GetBattlerSide(battler) != LADO_OPONENTE)
        return FALSE;

    firstId = 0, lastId = PARTY_SIZE;
    trainerId = gTrainerBattleOpponent;

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId)
        {
            gBattleScripting.battler = battler;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && !CanBattlerSwitch(battler))
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(firstId, lastId, TRUE) == 1
                    && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 4)
                    && !gBattleStruct->trainerSlideLowHpMsgDone)
                {
                    gBattleStruct->trainerSlideLowHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_HALF_HP:
                if (sTrainerSlides[i].msgLastHalfHp != NULL
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1
                 && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 2) && BattlerHPPercentage(battler, GREATER_THAN, 4)
                 && !gBattleStruct->trainerSlideHalfHpMsgDone)
                {
                    gBattleStruct->trainerSlideHalfHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastHalfHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_CRITICAL_HIT:
                if (sTrainerSlides[i].msgFirstCriticalHit != NULL && gBattleStruct->trainerSlideFirstCriticalHitMsgState == 1)
                {
                    gBattleStruct->trainerSlideFirstCriticalHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstCriticalHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_SUPER_EFFECTIVE_HIT:
                if (sTrainerSlides[i].msgFirstSuperEffectiveHit != NULL
                    && gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState == 1
                    && gBattleMons[battler].hp)
                {
                    gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSuperEffectiveHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_STAB_MOVE:
                if (sTrainerSlides[i].msgFirstSTABMove != NULL
                 && gBattleStruct->trainerSlideFirstSTABMoveMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlideFirstSTABMoveMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSTABMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_PLAYER_MON_UNAFFECTED:
                if (sTrainerSlides[i].msgPlayerMonUnaffected != NULL
                 && gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgPlayerMonUnaffected;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_BEFORE_FIRST_TURN:
                if (sTrainerSlides[i].msgBeforeFirstTurn != NULL && !gBattleStruct->trainerSlideBeforeFirstTurnMsgDone)
                {
                    gBattleStruct->trainerSlideBeforeFirstTurnMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgBeforeFirstTurn;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return FALSE;
}

#ifndef GUARD_BATTLE_AI_SWITCH_ITEMS_H
#define GUARD_BATTLE_AI_SWITCH_ITEMS_H

void GetAIPartyIndexes(u32 battlerId, s32 *firstId, s32 *lastId);
void AI_TrySwitchOrUseItem(u32 battler);
u32 GetMostSuitableMonToSwitchInto(u32 battler, bool32 switchAfterMonKOd);
bool32 ShouldSwitch(u32 battler);
bool32 EstaPokemonEnSuelo(u32 efectoObjeto, u32 habilidad, u32 tipo1, u32 tipo2);

#endif // GUARD_BATTLE_AI_SWITCH_ITEMS_H

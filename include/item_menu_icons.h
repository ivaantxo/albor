#ifndef GUARD_ITEM_MENU_ICONS_H
#define GUARD_ITEM_MENU_ICONS_H

extern const struct CompressedSpriteSheet gBagMaleSpriteSheet;
extern const struct CompressedSpriteSheet gBagFemaleSpriteSheet;
extern const struct SpritePalette gBagPaletteTable;

void RemoveBagSprite(u8 id);
void AddBagVisualSprite(u8 bagPocketId);
void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets);
void ShakeBagSprite(void);
void AddSwitchPocketRotatingBallSprite(s16 rotationDirection);
void AddBagItemIconSprite(u16 itemId, u8 id);
void RemoveBagItemIconSprite(u8 id);
void CreateItemMenuSwapLine(void);
void SetItemMenuSwapLineInvisibility(bool8 invisible);
void UpdateItemMenuSwapLinePos(u8 y);

#endif // GUARD_ITEM_MENU_ICONS_H

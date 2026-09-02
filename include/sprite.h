#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#define MAX_SPRITES 64
#define SPRITE_NONE 0xFF
#define TAG_NONE 0xFFFF

// Given to SetSpriteMatrixAnchor to skip anchoring one of the coords.
#define NO_ANCHOR 0x800

struct SpriteSheet
{
    const void *data;  // Raw uncompressed pixel data
    u16 size;
    u16 tag;
};

struct CompressedSpriteSheet
{
    const u32 *data;  // LZ77 compressed pixel data
    u16 size;        // Uncompressed size of pixel data
    u16 tag;
};

struct SpriteFrameImage
{
    const void *data;
    u16 size;
    bool8 relativeFrames;
};

#define obj_frame_tiles(ptr) {.data = (u8 *)ptr, .size = sizeof ptr}

#define overworld_frame(ptr, width, height, frame) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}
#define overworld_ascending_frames(ptr, width, height) {.data = (u8 *)ptr, .size = (width * height * 64)/2, .relativeFrames=TRUE}

struct SpritePalette
{
    const u16 *data;  // Raw uncompressed palette data
    u16 tag;
};

struct CompressedSpriteSheetAndPalette
{
    const u32 *sheet;   // LZ77 compressed pixel data
    const u16 *palette; // Raw uncompressed palette data
    u16 sheetSize;      // Uncompressed size of pixel data
    u16 tag;
};

struct AnimFrameCmd
{
    // If the sprite has an array of images, this is the array index.
    // If the sprite has a sheet, this is the tile offset.
    s32 imageValue;

    // Fotogramas que dura este cuadro. Ya no hay tope practico: eran seis bits -63
    // como mucho- y no llegaban para las animaciones lentas, las de un Pokemon
    // parado que parpadea cada pocos segundos.
    u32 duration;
    bool32 hFlip;
    bool32 vFlip;
};

struct AnimLoopCmd
{
    s32 type;
    u32 count;
};

struct AnimJumpCmd
{
    s32 type;
    u32 target;
};

// The first halfword of this union specifies the type of command.
// If it -2, then it is a jump command. If it is -1, then it is the end of the script.
// Otherwise, it is the imageValue for a frame command.
union AnimCmd
{
    s32 type;
    struct AnimFrameCmd frame;
    struct AnimLoopCmd loop;
    struct AnimJumpCmd jump;
};

#define ANIMCMD_FRAME(...) \
    {.frame = {__VA_ARGS__}}
#define ANIMCMD_LOOP(_count) \
    {.loop = {.type = -3, .count = _count}}
#define ANIMCMD_JUMP(_target) \
    {.jump = {.type = -2, .target = _target}}
#define ANIMCMD_END \
    {.type = -1}

struct AffineAnimFrameCmd
{
    s32 xScale;
    s32 yScale;
    s32 rotation;
    u32 duration;
};

struct AffineAnimLoopCmd
{
    s32 type;
    u32 count;
};

struct AffineAnimJumpCmd
{
    s32 type;
    u32 target;
};

struct AffineAnimEndCmdAlt
{
    s32 type;
    u32 val;
};

union AffineAnimCmd
{
    s32 type;
    struct AffineAnimFrameCmd frame;
    struct AffineAnimLoopCmd loop;
    struct AffineAnimJumpCmd jump;
    struct AffineAnimEndCmdAlt end; // unused in code
};

#define AFFINEANIMCMDTYPE_LOOP 0x7FFD
#define AFFINEANIMCMDTYPE_JUMP 0x7FFE
#define AFFINEANIMCMDTYPE_END  0x7FFF

#define AFFINEANIMCMD_FRAME(_xScale, _yScale, _rotation, _duration) \
    {.frame = {.xScale = _xScale, .yScale = _yScale, .rotation = _rotation, .duration = _duration}}
#define AFFINEANIMCMD_LOOP(_count) \
    {.loop = {.type = AFFINEANIMCMDTYPE_LOOP, .count = _count}}
#define AFFINEANIMCMD_JUMP(_target) \
    {.jump = {.type = AFFINEANIMCMDTYPE_JUMP, .target = _target}}
#define AFFINEANIMCMD_END \
    {.type = AFFINEANIMCMDTYPE_END}
#define AFFINEANIMCMD_END_ALT(_val) \
    {.end = {.type = AFFINEANIMCMDTYPE_END, .val = _val}}

struct AffineAnimState
{
    u32 animNum;
    u32 animCmdIndex;
    u32 delayCounter;
    u32 loopCounter;
    s32 xScale;
    s32 yScale;
    s32 rotation;
};

enum
{
    SUBSPRITES_OFF,
    SUBSPRITES_ON,
    SUBSPRITES_IGNORE_PRIORITY, // on but priority is ignored
};

struct Subsprite
{
    s8 x; // was u16 in R/S
    s8 y; // was u16 in R/S
    u16 shape:2;
    u16 size:2;
    u16 tileOffset:10;
    u16 priority:2;
};

struct SubspriteTable
{
    u8 subspriteCount;
    const struct Subsprite *subsprites;
};

struct Sprite;

typedef void (*SpriteCallback)(struct Sprite *);

struct SpriteTemplate
{
    u16 tileTag;
    u16 paletteTag;
    const struct OamData *oam;
    const union AnimCmd *const *anims;
    const struct SpriteFrameImage *images;
    const union AffineAnimCmd *const *affineAnims;
    SpriteCallback callback;
};

// UB: template pointer is often used to point to temporary storage,
// then later dereferenced after being freed. Usually this won't
// be visible in-game, but this is (part of) what causes the item
// icon palette to flicker when changing items in the bag.
struct Sprite
{
    struct OamData oam;
    const union AnimCmd *const *anims;
    const struct SpriteFrameImage *images;
    const union AffineAnimCmd *const *affineAnims;
    const struct SpriteTemplate *template;
    const struct SubspriteTable *subspriteTables;
    SpriteCallback callback;

    s16 x, y;
    s16 x2, y2;
    s32 centerToCornerVecX;
    s32 centerToCornerVecY;

    u32 animNum;
    u32 animCmdIndex;
    u32 animDelayCounter;
    u32 animLoopCounter;

    // data[] se queda en s16 a proposito, y es la unica excepcion.
    //
    // Medio juego guarda ahi contadores y coordenadas contando con que dan la vuelta
    // a los 16 bits, y hay cientos de #define sX data[0] repartidos por las
    // animaciones. Ampliarlo no es cambiar un tipo: es cambiar la aritmetica de todo
    // lo que lo usa.
    s16 data[8];

    bool32 inUse;
    bool32 coordOffsetEnabled;
    bool32 invisible;

    bool32 hFlip;
    bool32 vFlip;
    bool32 animBeginning;
    bool32 affineAnimBeginning;
    bool32 animEnded;
    bool32 affineAnimEnded;
    bool32 usingSheet;
    bool32 anchored;
    bool32 animPaused;
    bool32 affineAnimPaused;

    u32 sheetTileStart;

    // Cuantos tiles se le reservaron al crearlo. Hay que guardarlo porque al
    // destruirlo no se puede volver a preguntar: los sprites basados en 'images'
    // apuntan a un hueco compartido cuyo tamano cambia cada vez que entra otro
    // Pokemon, y liberar por el tamano de entonces suelta tiles que ya son de otro.
    u32 tilesReservados;

    u32 subspriteTableNum;
    u32 subspriteMode;

    u32 subspriteTableNum;
    u32 subspriteMode;

    u32 subpriority;
};

// La duracion del comando y el contador del sprite tienen que aguantar el mismo
// rango, y esto lo comprueba al compilar. Ampliar solo uno de los dos es el error
// facil: si el comando declara mas de lo que el contador puede guardar, el valor se
// trunca al asignarlo y la animacion sale mas RAPIDA, que es justo lo contrario de
// lo que uno pretendia.
STATIC_ASSERT(sizeof(((struct Sprite *)0)->animDelayCounter)
              >= sizeof(((union AnimCmd *)0)->frame.duration),
              ElContadorDeAnimacionNoAguantaLaDuracionDelComando);


struct OamMatrix
{
    s16 a;
    s16 b;
    s16 c;
    s16 d;
};

extern const struct OamData gDummyOamData;
extern const union AnimCmd *const gDummySpriteAnimTable[];
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];
extern const struct SpriteTemplate gDummySpriteTemplate;

extern u8 gReservedSpritePaletteCount;
extern struct Sprite gSprites[];
extern u16 gReservedSpriteTileCount;
extern s16 gSpriteCoordOffsetX;
extern s16 gSpriteCoordOffsetY;
extern struct OamMatrix gOamMatrices[];
extern bool8 gAffineAnimsDisabled;

void ResetSpriteData(void);
void AnimateSprites(void);
void BuildOamBuffer(void);
u32 CreateSprite(const struct SpriteTemplate *template, s16 x, s16 y, u32 subpriority);
u32 CreateSpriteAtEnd(const struct SpriteTemplate *template, s16 x, s16 y, u32 subpriority);
u32 CreateInvisibleSprite(void (*callback)(struct Sprite *));
u32 CreateSpriteAndAnimate(const struct SpriteTemplate *template, s16 x, s16 y, u32 subpriority);
void DestroySprite(struct Sprite *sprite);
void ResetOamRange(u32 start, u32 end);
void LoadOam(void);
void SetOamMatrix(u8 matrixNum, u16 a, u16 b, u16 c, u16 d);
void CalcCenterToCornerVec(struct Sprite *sprite, u8 shape, u8 size, u8 affineMode);
void SpriteCallbackDummy(struct Sprite *sprite);
void ProcessSpriteCopyRequests(void);
void FreeSpriteTiles(struct Sprite *sprite);
void FreeSpritePalette(struct Sprite *sprite);
void FreeSpriteOamMatrix(struct Sprite *sprite);
void DestroySpriteAndFreeResources(struct Sprite *sprite);
void AnimateSprite(struct Sprite *sprite);
void StartSpriteAnim(struct Sprite *sprite, u8 animNum);
void StartSpriteAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void SeekSpriteAnim(struct Sprite *sprite, u8 animCmdIndex);
void StartSpriteAffineAnim(struct Sprite *sprite, u8 animNum);
void StartSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void ChangeSpriteAffineAnim(struct Sprite *sprite, u8 animNum);
void ChangeSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void SetSpriteSheetFrameTileNum(struct Sprite *sprite);
u32 AllocOamMatrix(void);
void FreeOamMatrix(u8 matrixNum);
void InitSpriteAffineAnim(struct Sprite *sprite);
void SetOamMatrixRotationScaling(u8 matrixNum, s16 xScale, s16 yScale, u16 rotation);
u16 LoadSpriteSheet(const struct SpriteSheet *sheet);
u16 CargaSpriteComprimidoConEtiqueta(const u32 *grafico, u16 etiqueta, u32 reserva);
u16 LoadSpriteSheetByTemplate(const struct SpriteTemplate *template, u32 frame, s32 offset);
void LoadSpriteSheets(const struct SpriteSheet *sheets);
s16 AllocSpriteTiles(u16 tileCount);
void FreeSpriteTilesByTag(u16 tag);
void FreeSpriteTileRanges(void);
u16 GetSpriteTileStartByTag(u16 tag);
u16 GetSpriteTileTagByTileStart(u16 start);
void FreeAllSpritePalettes(void);
u32 LoadSpritePalette(const struct SpritePalette *palette);
u32 LoadEggSpritePalette(const struct SpritePalette *palette1, const struct SpritePalette *palette2);
u32 LoadSpritePaletteInSlot(const struct SpritePalette *palette, u8 paletteNum);
void LoadSpritePalettes(const struct SpritePalette *palettes);
u32 AllocSpritePalette(u16 tag);
u32 IndexOfSpritePaletteTag(u16 tag);
u16 GetSpritePaletteTagByPaletteNum(u8 paletteNum);
void FreeSpritePaletteByTag(u16 tag);
void SetSubspriteTables(struct Sprite *sprite, const struct SubspriteTable *subspriteTables);
bool8 AddSpriteToOamBuffer(struct Sprite *object, u8 *oamIndex);
bool8 AddSubspritesToOamBuffer(struct Sprite *sprite, struct OamData *destOam, u8 *oamIndex);
void ClearSpriteCopyRequests(void);
void ResetAffineAnimData(void);
u32 LoadUniqueSpritePalette(const struct SpritePalette *palette, u32 personality);
bool32 EsPaletaSpriteLibre(u32 paletteNum);
u32 PaletasSpriteLibres(void);
void LiberaPaletaSpritePorSlot(u32 paletteNum);
u32 GetSpriteIndexByTileTag(u16 tag);
void RequestSpriteFrameImageCopy(u16 index, u16 tileNum, const struct SpriteFrameImage *images);
void SetSpriteOamFlipBits(struct Sprite *sprite, u8 hFlip, u8 vFlip);

#endif //GUARD_SPRITE_H

#ifndef GUARD_PALETTE_H
#define GUARD_PALETTE_H

#define PLTT_BUFFER_SIZE (PLTT_SIZE / sizeof(u16))

#define PALETTE_FADE_STATUS_DELAY 2
#define PALETTE_FADE_STATUS_ACTIVE 1
#define PALETTE_FADE_STATUS_DONE 0
#define PALETTE_FADE_STATUS_LOADING 255

#define PALETTES_BG      65535
#define PALETTES_OBJECTS 0xFFFF0000
#define PALETTES_ALL     (PALETTES_BG | PALETTES_OBJECTS)

#define PLTT_ID(n) ((n) * 16)
#define BG_PLTT_OFFSET 0
#define OBJ_PLTT_OFFSET 256
#define BG_PLTT_ID(n) (BG_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID(n) (OBJ_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID2(n) (PLTT_ID((n) + 16))

#define COLORES_POR_PALETA 16

struct ConfiguracionBlend 
{
  u32 colorBlend:27;
  u32 coeficiente:5;
};

enum Fundidos
{
  FUNDIDO_DESDE_NEGRO,
  FUNDIDO_A_NEGRO,
};

struct ControlFundidoPaletas
{
  u32 paletasSeleccionadas;
  u32 controlBlend;
  u32 submodo;
  struct ConfiguracionBlend *bld0; // Para DNS
  struct ConfiguracionBlend *bld1; // Para DNS

  u16 colorBlend:15;
  bool16 activo:1;

  u16 intensidad:9; // Para DNS, [0, 256]
  u16 y:5;          // Coeficiente de blend (inicial)
  u16 objetivoY:5;  // Coeficiente de blend (objetivo)
  u16 modo:2;       // Modo de fundido

  bool16 blendDecreciente:1;
  bool16 transferenciaBufferDeshabilitada:1;
  bool16 reseteoRegistroBlend:1;
  bool16 fundidoHardwareAcabado:1;
  bool16 fundidoSoftwareAcabado:1;
  bool16 interruptorPaletasObjetos:1;
  u16 contadorFundidoSoftwareAcabado:5;

  u8 deltaY:4;       // Porcentaje de cambio de y
  u8 contadorRetraso:6;
  s8 retraso;
};

extern const struct ConfiguracionBlend gBlendHoraDia[];

extern struct ControlFundidoPaletas gFundidoPaletas;
extern u16 ALIGNED(4) gPlttBufferUnfaded[PLTT_BUFFER_SIZE];
extern u16 ALIGNED(4) gPlttBufferFaded[PLTT_BUFFER_SIZE];

void LoadCompressedPalette(const u32 *src, u32 offset, u32 size);
void LoadCompressedPaletteFast(const u32 *src, u32 offset, u32 size);
void LoadPalette(const void *src, u32 offset, u32 size);
void LoadPaletteFast(const void *src, u32 offset, u32 size);
void FillPalette(u32 value, u32 offset, u32 size);
void TransferPlttBuffer(void);
u32 UpdatePaletteFade(void);
void ResetPaletteFade(void);
bool32 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u32 blendColor);
bool32 BeginTimeOfDayPaletteFade(u32, s8, u8, u8, struct ConfiguracionBlend *, struct ConfiguracionBlend *, u16, u32);
void InvertPlttBuffer(u32 selectedPalettes);
void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b);
void UnfadePlttBuffer(u32 selectedPalettes);
void EmpiezaFundidoPaletasRapido(u32 submodo);
void EmpiezaFundidoPaletasHardware(u32 controlBlend, u32 retraso, u32 y, u32 targetY, bool32 reseteaRegistrosBlend);
void BlendPalettes(u32 selectedPalettes, u8 coeff, u32 color);
void BlendPalettesFine(u32 palettes, u16 *src, u16 *dst, u32 coeff, u32 color);
void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u32 color);
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id);
void TimeMixPalettes(u32, u16 *, u16 *, struct ConfiguracionBlend *, struct ConfiguracionBlend *, u16);
void AvgPaletteWeighted(u16 *src0, u16 *src1, u16 *dst, u16 intensidadRelativa);

static inline void SetBackdropFromColor(u32 color)
{
  FillPalette(color, 0, PLTT_SIZEOF(1));
}

#endif // GUARD_PALETTE_H

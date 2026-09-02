#include "global.h"
#include "palette.h"
#include "malloc.h"
#include "util.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "constants/rgb.h"

enum ModosFundido
{
    FUNDIDO_NORMAL,
    FUNDIDO_RAPIDO,
    FUNDIDO_HARDWARE,
    FUNDIDO_DNS
};

static u32 UpdateNormalPaletteFade(void);
static u32 UpdateFastPaletteFade(void);
static u32 ActualizaFundidoPaletasHardware(void);
static u32 UpdateTimeOfDayPaletteFade(void);
static void UpdateBlendRegisters(void);
static bool32 IsSoftwarePaletteFadeFinishing(void);
static void Task_BlendPalettesGradually(u8 taskId);

// palette buffers require alignment with agbcc because
// unaligned word reads are issued in BlendPalette otherwise
ALIGNED(4) EWRAM_DATA u16 gPlttBufferUnfaded[PLTT_BUFFER_SIZE] = {0};
ALIGNED(4) EWRAM_DATA u16 gPlttBufferFaded[PLTT_BUFFER_SIZE] = {0};
EWRAM_DATA struct ControlFundidoPaletas gFundidoPaletas = {0};

// Copia de seguridad de las paletas, para los efectos que las oscurecen y luego las
// devuelven.
//
// Es un PUNTERO, no un array: la copia tiene que sobrevivir entre fotogramas -y a
// veces entre dos comandos de guion distintos-, pero el kilobyte solo hace falta
// mientras hay una copia viva. Un array estatico lo ocuparia siempre.
static EWRAM_DATA u16 *sRespaldoPaletas = NULL;

// Guarda las paletas sin fundir. Si no hay memoria, no se guarda nada y la
// restauracion lo detecta y no hace daño.
void GuardaRespaldoPaletas(void)
{
    if (sRespaldoPaletas == NULL)
        sRespaldoPaletas = Alloc(PLTT_SIZE);

    if (sRespaldoPaletas != NULL)
        CopiaCpu32(gPlttBufferUnfaded, sRespaldoPaletas, PLTT_SIZE);
}

void RestauraRespaldoPaletas(void)
{
    if (sRespaldoPaletas == NULL)
        return;

    CopiaCpu32(sRespaldoPaletas, gPlttBufferUnfaded, PLTT_SIZE);
    Free(sRespaldoPaletas);
    sRespaldoPaletas = NULL;
}


void LoadPalette(const void *src, u32 offset, u32 size)
{
    CopiaCpu16(src, &gPlttBufferUnfaded[offset], size);
    CopiaCpu16(src, &gPlttBufferFaded[offset], size);
}

void FillPalette(u32 value, u32 offset, u32 size)
{
    CpuFill16(value, &gPlttBufferUnfaded[offset], size);
    CpuFill16(value, &gPlttBufferFaded[offset], size);
}

void TransferPlttBuffer(void)
{
    if (!gFundidoPaletas.transferenciaBufferDeshabilitada)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        if (gFundidoPaletas.modo == FUNDIDO_HARDWARE && gFundidoPaletas.activo)
            UpdateBlendRegisters();
    }
}

u32 UpdatePaletteFade(void)
{
    u32 result;

    switch (gFundidoPaletas.modo)
    {
        case FUNDIDO_NORMAL:
            result = UpdateNormalPaletteFade();
            break;
        case FUNDIDO_RAPIDO:
            result = UpdateFastPaletteFade();
            break;
        case FUNDIDO_DNS:
            result = UpdateTimeOfDayPaletteFade();
            break;
        default:
            result = ActualizaFundidoPaletasHardware();
            break;
    }

    return result;
}

void BeginNormalPaletteFade(u32 selectedPalettes, s32 delay, u32 startY, u32 targetY, u32 blendColor)
{
    u32 bufferTransferState;

    if (gFundidoPaletas.activo)
    {
        return;
    }

    gFundidoPaletas.deltaY = 2;

    if (delay < 0)
    {
        gFundidoPaletas.deltaY += (delay * -1);
        delay = 0;
    }

    gFundidoPaletas.paletasSeleccionadas = selectedPalettes;
    gFundidoPaletas.contadorRetraso = delay;
    gFundidoPaletas.retraso = delay;
    gFundidoPaletas.y = startY;
    gFundidoPaletas.objetivoY = targetY;
    gFundidoPaletas.colorBlend = blendColor;
    gFundidoPaletas.activo = TRUE;
    gFundidoPaletas.modo = FUNDIDO_NORMAL;
    gFundidoPaletas.blendDecreciente = startY >= targetY;

    UpdatePaletteFade();

    bufferTransferState = gFundidoPaletas.transferenciaBufferDeshabilitada;
    gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
    CopiaCpu32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
    if (gFundidoPaletas.modo == FUNDIDO_HARDWARE && gFundidoPaletas.activo)
        UpdateBlendRegisters();
    gFundidoPaletas.transferenciaBufferDeshabilitada = bufferTransferState;
}

// Like normal palette fade but respects sprite/tile palettes immune to time of day fading
bool32 BeginTimeOfDayPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, struct ConfiguracionBlend *bld0, struct ConfiguracionBlend *bld1, u16 weight, u32 color)
{
    u32 temp;

    if (gFundidoPaletas.activo)
    {
        return FALSE;
    }
    else
    {
        gFundidoPaletas.deltaY = 2;

        if (delay < 0)
        {
            gFundidoPaletas.deltaY += (delay * -1);
            delay = 0;
        }

        gFundidoPaletas.paletasSeleccionadas = selectedPalettes;
        gFundidoPaletas.contadorRetraso = delay;
        gFundidoPaletas.retraso = delay;
        gFundidoPaletas.y = startY;
        gFundidoPaletas.objetivoY = targetY;
        gFundidoPaletas.activo = TRUE;
        gFundidoPaletas.modo = FUNDIDO_DNS;

        gFundidoPaletas.colorBlend = color;
        gFundidoPaletas.bld0 = bld0;
        gFundidoPaletas.bld1 = bld1;
        gFundidoPaletas.intensidad = weight;

        if (startY < targetY)
            gFundidoPaletas.blendDecreciente = FALSE;
        else
            gFundidoPaletas.blendDecreciente = TRUE;

        UpdatePaletteFade();

        temp = gFundidoPaletas.transferenciaBufferDeshabilitada;
        gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
        CopiaCpu32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        if (gFundidoPaletas.modo == FUNDIDO_HARDWARE && gFundidoPaletas.activo)
            UpdateBlendRegisters();
        gFundidoPaletas.transferenciaBufferDeshabilitada = temp;
        return TRUE;
    }
}

void ResetPaletteFade(void)
{
    gFundidoPaletas.paletasSeleccionadas = 0;
    gFundidoPaletas.controlBlend = 0;
    gFundidoPaletas.retraso = 0;
    gFundidoPaletas.submodo = 0;
    gFundidoPaletas.contadorRetraso = 0;
    gFundidoPaletas.y = 0;
    gFundidoPaletas.objetivoY = 0;
    gFundidoPaletas.colorBlend = 0;
    gFundidoPaletas.activo = FALSE;
    gFundidoPaletas.blendDecreciente = FALSE;
    gFundidoPaletas.transferenciaBufferDeshabilitada = FALSE;
    gFundidoPaletas.reseteoRegistroBlend = FALSE;
    gFundidoPaletas.fundidoHardwareAcabado = FALSE;
    gFundidoPaletas.fundidoSoftwareAcabado = FALSE;
    gFundidoPaletas.contadorFundidoSoftwareAcabado = 0;
    gFundidoPaletas.interruptorPaletasObjetos = FALSE;
    gFundidoPaletas.deltaY = 2;
}

// Like normal palette fade, but respects sprite/tile palettes immune to time of day fading
static u32 UpdateTimeOfDayPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;
    u16 timePalettes = 0; // palettes passed to the time-blender
    u16 copyPalettes;
    u16 *src;
    u16 *dst;

    if (!gFundidoPaletas.activo)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
        return gFundidoPaletas.activo? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;

    if (!gFundidoPaletas.interruptorPaletasObjetos)
    {
        if (gFundidoPaletas.contadorRetraso < gFundidoPaletas.retraso)
        {
            gFundidoPaletas.contadorRetraso++;
            return 2;
        }
        gFundidoPaletas.contadorRetraso = 0;
    }

    paletteOffset = 0;

    if (!gFundidoPaletas.interruptorPaletasObjetos)
    {
        selectedPalettes = gFundidoPaletas.paletasSeleccionadas;
    }
    else
    {
        selectedPalettes = gFundidoPaletas.paletasSeleccionadas >> 16;
        paletteOffset = OBJ_PLTT_OFFSET;
    }

    src = gPlttBufferUnfaded + paletteOffset;
    dst = gPlttBufferFaded + paletteOffset;

    // First apply TOD blend to relevant subset of palettes
    if (gFundidoPaletas.interruptorPaletasObjetos) 
    { // Sprite palettes, don't blend those with tags
        u32 i;
        u32 j = 1;
        for (i = 0; i < 16; i++, j <<= 1) 
        { // Mask out palettes that should not be light blended
            if ((selectedPalettes & j) && !(GetSpritePaletteTagByPaletteNum(i) >> 15))
            timePalettes |= j;
        }
    } 
    else 
    { // tile palettes, don't blend [13, 15]
        timePalettes = selectedPalettes & 8191;
    }
    TimeMixPalettes(timePalettes, src, dst, gFundidoPaletas.bld0, gFundidoPaletas.bld1, gFundidoPaletas.intensidad);

    // palettes that were not blended above must be copied through
    if ((copyPalettes = ~timePalettes))
    {
      u16 *src1 = src;
      u16 *dst1 = dst;
      while (copyPalettes) 
        {
        if (copyPalettes & 1)
            CopiaRapidaCpu(src1, dst1, PLTT_SIZE_4BPP);
        copyPalettes >>= 1;
        src1 += 16;
        dst1 += 16;
        }
    }

    // Then, blend from faded->faded with native BlendPalettes
    BlendPalettesFine(selectedPalettes, dst, dst, gFundidoPaletas.y, gFundidoPaletas.colorBlend);

    gFundidoPaletas.interruptorPaletasObjetos ^= TRUE;

    if (!gFundidoPaletas.interruptorPaletasObjetos)
    {
        if ((gFundidoPaletas.blendDecreciente && gFundidoPaletas.y == 0) || (!gFundidoPaletas.blendDecreciente && gFundidoPaletas.y == gFundidoPaletas.objetivoY))
        {
            gFundidoPaletas.paletasSeleccionadas = 0;
            gFundidoPaletas.fundidoSoftwareAcabado = TRUE;
        }
        else
        {
            s8 val;

            if (!gFundidoPaletas.blendDecreciente)
            {
                val = gFundidoPaletas.y;
                val += gFundidoPaletas.deltaY;
                if (val > gFundidoPaletas.objetivoY)
                    val = gFundidoPaletas.objetivoY;
                gFundidoPaletas.y = val;
            }
            else
            {
                val = gFundidoPaletas.y;
                val -= gFundidoPaletas.deltaY;
                if (val < 0)
                    val = 0;
                gFundidoPaletas.y = val;
            }
        }
    }

    return PALETTE_FADE_STATUS_ACTIVE;
}

static u32 UpdateNormalPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gFundidoPaletas.activo)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gFundidoPaletas.activo? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
    else
    {
        if (!gFundidoPaletas.interruptorPaletasObjetos)
        {
            if (gFundidoPaletas.contadorRetraso < gFundidoPaletas.retraso)
            {
                gFundidoPaletas.contadorRetraso++;
                return 2;
            }
            gFundidoPaletas.contadorRetraso = 0;
        }

        paletteOffset = 0;

        if (!gFundidoPaletas.interruptorPaletasObjetos)
        {
            selectedPalettes = gFundidoPaletas.paletasSeleccionadas;
        }
        else
        {
            selectedPalettes = gFundidoPaletas.paletasSeleccionadas >> 16;
            paletteOffset = OBJ_PLTT_OFFSET;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gFundidoPaletas.y,
                    gFundidoPaletas.colorBlend);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gFundidoPaletas.interruptorPaletasObjetos ^= TRUE;

        if (!gFundidoPaletas.interruptorPaletasObjetos)
        {
            if (gFundidoPaletas.y == gFundidoPaletas.objetivoY)
            {
                gFundidoPaletas.paletasSeleccionadas = 0;
                gFundidoPaletas.fundidoSoftwareAcabado = TRUE;
            }
            else
            {
                s8 val;

                if (!gFundidoPaletas.blendDecreciente)
                {
                    val = gFundidoPaletas.y;
                    val += gFundidoPaletas.deltaY;
                    if (val > gFundidoPaletas.objetivoY)
                        val = gFundidoPaletas.objetivoY;
                    gFundidoPaletas.y = val;
                }
                else
                {
                    val = gFundidoPaletas.y;
                    val -= gFundidoPaletas.deltaY;
                    if (val < gFundidoPaletas.objetivoY)
                        val = gFundidoPaletas.objetivoY;
                    gFundidoPaletas.y = val;
                }
            }
        }

        return PALETTE_FADE_STATUS_ACTIVE;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u32 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u32 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u32 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void EmpiezaFundidoPaletasRapido(u32 submodo)
{
    gFundidoPaletas.deltaY = 2;
    gFundidoPaletas.y = 31;
    gFundidoPaletas.submodo = submodo;
    gFundidoPaletas.activo = TRUE;
    gFundidoPaletas.modo = FUNDIDO_RAPIDO;

    if (submodo == FUNDIDO_DESDE_NEGRO)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u32 UpdateFastPaletteFade(void)
{
    u32 i, paletteOffsetStart, paletteOffsetEnd;
    s32 r0, g0, b0, r, g, b;

    if (!gFundidoPaletas.activo)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
        return gFundidoPaletas.activo? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;

    if (gFundidoPaletas.interruptorPaletasObjetos)
    {
        paletteOffsetStart = OBJ_PLTT_OFFSET;
        paletteOffsetEnd = PLTT_BUFFER_SIZE;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = OBJ_PLTT_OFFSET;
    }

    switch (gFundidoPaletas.submodo)
    {
    case FUNDIDO_DESDE_NEGRO:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FUNDIDO_A_NEGRO:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
    }

    gFundidoPaletas.interruptorPaletasObjetos ^= TRUE;

    if (gFundidoPaletas.y - gFundidoPaletas.deltaY < 0)
        gFundidoPaletas.y = 0;
    else
        gFundidoPaletas.y -= gFundidoPaletas.deltaY;

    if (gFundidoPaletas.y == 0)
    {
        switch (gFundidoPaletas.submodo)
        {
        case FUNDIDO_DESDE_NEGRO:
            CopiaCpu32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FUNDIDO_A_NEGRO:
            CpuFill32(0, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gFundidoPaletas.modo = FUNDIDO_NORMAL;
        gFundidoPaletas.fundidoSoftwareAcabado = TRUE;
    }

    return PALETTE_FADE_STATUS_ACTIVE;
}

// El fundido por hardware mueve BLDY, asi que controlBlend TIENE que llevar
// BLDCNT_EFFECT_DARKEN o BLDCNT_EFFECT_LIGHTEN: en modo BLEND el hardware ignora
// BLDY -lo controla BLDALPHA- y el fundido no se ve, dejando un corte seco donde
// deberia haber una transicion.
void EmpiezaFundidoPaletasHardware(u32 controlBlend, u32 retraso, u32 y, u32 targetY, u32 reseteoRegistroBlend)
{
    gFundidoPaletas.controlBlend = controlBlend;
    gFundidoPaletas.contadorRetraso = retraso;
    gFundidoPaletas.retraso = retraso;
    gFundidoPaletas.y = y;
    gFundidoPaletas.objetivoY = targetY;
    gFundidoPaletas.activo = TRUE;
    gFundidoPaletas.modo = FUNDIDO_HARDWARE;
    gFundidoPaletas.reseteoRegistroBlend = reseteoRegistroBlend;
    gFundidoPaletas.fundidoHardwareAcabado = FALSE;

    if (y < targetY)
        gFundidoPaletas.blendDecreciente = FALSE;
    else
        gFundidoPaletas.blendDecreciente = TRUE;
}

static u32 ActualizaFundidoPaletasHardware(void)
{
    if (!gFundidoPaletas.activo)
        return PALETTE_FADE_STATUS_DONE;

    if (gFundidoPaletas.contadorRetraso < gFundidoPaletas.retraso)
    {
        gFundidoPaletas.contadorRetraso++;
        return PALETTE_FADE_STATUS_DELAY;
    }

    gFundidoPaletas.contadorRetraso = 0;

    if (!gFundidoPaletas.blendDecreciente)
    {
        gFundidoPaletas.y++;
        if (gFundidoPaletas.y > gFundidoPaletas.objetivoY)
        {
            gFundidoPaletas.fundidoHardwareAcabado++;
            gFundidoPaletas.y--;
        }
    }
    else
    {
        s32 y = gFundidoPaletas.y--;
        if (y - 1 < gFundidoPaletas.objetivoY)
        {
            gFundidoPaletas.fundidoHardwareAcabado++;
            gFundidoPaletas.y++;
        }
    }

    if (gFundidoPaletas.fundidoHardwareAcabado)
    {
        if (gFundidoPaletas.reseteoRegistroBlend)
        {
            gFundidoPaletas.controlBlend = 0;
            gFundidoPaletas.y = 0;
        }
        gFundidoPaletas.reseteoRegistroBlend = FALSE;
    }

    return PALETTE_FADE_STATUS_ACTIVE;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gFundidoPaletas.controlBlend);
    SetGpuReg(REG_OFFSET_BLDY, gFundidoPaletas.y);
    if (gFundidoPaletas.fundidoHardwareAcabado)
    {
        gFundidoPaletas.fundidoHardwareAcabado = FALSE;
        gFundidoPaletas.modo = 0;
        gFundidoPaletas.controlBlend = 0;
        gFundidoPaletas.y = 0;
        gFundidoPaletas.activo = FALSE;
    }
}

// Fotogramas de cortesia al acabar el fundido, para que al buffer de paletas le
// de tiempo a llegar al hardware. Con uno basta: TransferPlttBuffer vuelca en
// cada vblank. Estaba en cuatro, y son cuatro fotogramas muertos al final de CADA
// fundido por software del juego -con la pantalla ya negra al salir, o ya visible
// pero sin control al entrar-.
#define FOTOGRAMAS_CORTESIA_FUNDIDO 1

static bool32 IsSoftwarePaletteFadeFinishing(void)
{
    if (gFundidoPaletas.fundidoSoftwareAcabado)
    {
        if (gFundidoPaletas.contadorFundidoSoftwareAcabado == FOTOGRAMAS_CORTESIA_FUNDIDO)
        {
            gFundidoPaletas.activo = FALSE;
            gFundidoPaletas.fundidoSoftwareAcabado = FALSE;
            gFundidoPaletas.contadorFundidoSoftwareAcabado = 0;
            return TRUE;
        }
        else
        {
            gFundidoPaletas.contadorFundidoSoftwareAcabado++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
    return FALSE;
}

// optimized based on lucktyphlosion's BlendPalettesFine
void BlendPalettesFine(u32 palettes, u16 *src, u16 *dst, u32 coeff, u32 color) 
{
    s32 newR, newG, newB;

    if (!palettes)
        return;

    coeff *= 2;
    newR = (color << 27) >> 27;
    newG = (color << 22) >> 27;
    newB = (color << 17) >> 27;

    do 
    {
        if (palettes & 1) 
        {
            u16 *srcEnd = src + 16;
            while (src != srcEnd) 
            { // Transparency is blended (for backdrop reasons)
                u32 srcColor = *src;
                s32 r = (srcColor << 27) >> 27;
                s32 g = (srcColor << 22) >> 27;
                s32 b = (srcColor << 16) >> 26;

                *dst++ = ((r + (((newR - r) * (s32)coeff) >> 5)) << 0)
                       | ((g + (((newG - g) * (s32)coeff) >> 5)) << 5)
                       | ((b + (((newB - (b & 31)) * (s32)coeff) >> 5)) << 10);
                src++;
            }
        } 
        else 
        {
            src += 16;
            dst += 16;
        }
        palettes >>= 1;
    } 
    while (palettes);
}

void BlendPalettes(u32 palettes, u8 coeff, u32 color) 
{
    BlendPalettesFine(palettes, gPlttBufferUnfaded, gPlttBufferFaded, coeff, color);
}

// Mezcla colores del DNS según hora del día, si el bit 0 está activado (en .pla), se mezcla con ese color y no con el color por defecto.
void TimeMixPalettes(u32 palettes, u16 *src, u16 *dst, struct ConfiguracionBlend *blend0, struct ConfiguracionBlend *blend1, u16 weight0)
{
    s32 r0, g0, b0, r1, g1, b1, defR, defG, defB, altR, altG, altB;
    u32 color0, coeff0, color1, coeff1;
    u32 defaultColor = RGB_AMARILLO_CLARO;

    if (!palettes)
    return;

    color0 = blend0->colorBlend;
    coeff0 = blend0->coeficiente * 2;
    color1 = blend1->colorBlend;
    coeff1 = blend1->coeficiente * 2;

    r0 = (color0 << 27) >> 27;
    g0 = (color0 << 22) >> 27;
    b0 = (color0 << 17) >> 27;
    r1 = (color1 << 27) >> 27;
    g1 = (color1 << 22) >> 27;
    b1 = (color1 << 17) >> 27;
    defR = (defaultColor << 27) >> 27;
    defG = (defaultColor << 22) >> 27;
    defB = (defaultColor << 17) >> 27;

    do
    {
        if (palettes & 1)
        {
            u16 *srcEnd = src + 16;
            u32 altBlendColor = *dst++ = *src++; // color 0 is copied through
            if (altBlendColor >> 15)
            { // Transparency high bit set; alt blend color
                altR = (altBlendColor << 27) >> 27;
                altG = (altBlendColor << 22) >> 27;
                altB = (altBlendColor << 17) >> 27;
            }
            else 
            {
                altBlendColor = 0;
            }
            while (src != srcEnd)
            {
                u32 srcColor = *src;
                s32 r = (srcColor << 27) >> 27;
                s32 g = (srcColor << 22) >> 27;
                s32 b = (srcColor << 17) >> 27;
                s32 r2, g2, b2;

                if (srcColor >> 15)
                {
                    if (altBlendColor)
                    { // Use alternate blend color
                        r2 = r + (((altR - r) * (s32)coeff1) >> 5);
                        g2 = g + (((altG - g) * (s32)coeff1) >> 5);
                        b2 = b + (((altB - b) * (s32)coeff1) >> 5);
                        r  = r + (((altR - r) * (s32)coeff0) >> 5);
                        g  = g + (((altG - g) * (s32)coeff0) >> 5);
                        b  = b + (((altB - b) * (s32)coeff0) >> 5);
                    }
                    else
                    { // Use default blend color
                        r2 = r + (((defR - r) * (s32)coeff1) >> 5);
                        g2 = g + (((defG - g) * (s32)coeff1) >> 5);
                        b2 = b + (((defB - b) * (s32)coeff1) >> 5);
                        r  = r + (((defR - r) * (s32)coeff0) >> 5);
                        g  = g + (((defG - g) * (s32)coeff0) >> 5);
                        b  = b + (((defB - b) * (s32)coeff0) >> 5);
                    }
                }
                else
                { // Use provided blend colors
                        r2 = (r + (((r1 - r) * (s32)coeff1) >> 5));
                        g2 = (g + (((g1 - g) * (s32)coeff1) >> 5));
                        b2 = (b + (((b1 - b) * (s32)coeff1) >> 5));
                        r = (r + (((r0 - r) * (s32)coeff0) >> 5));
                        g = (g + (((g0 - g) * (s32)coeff0) >> 5));
                        b = (b + (((b0 - b) * (s32)coeff0) >> 5));
                }
                r  = r2 + (((r - r2) * (s32)weight0) >> 8);
                g  = g2 + (((g - g2) * (s32)weight0) >> 8);
                b  = b2 + (((b - b2) * (s32)weight0) >> 8);
                *dst++ = RGB2(r, g, b);
                src++;
            }
        }
        else
        {
            src += 16;
            dst += 16;
        }
        palettes >>= 1;
    }
    while (palettes);
}

// Apply weighted average to palettes, preserving high bits of dst throughout
void AvgPaletteWeighted(u16 *src0, u16 *src1, u16 *dst, u16 intensidadRelativa) 
{
    u16 *srcEnd = src0 + 16;
    src0++;
    src1++;
    dst++; // leave dst transparency unchanged
    while (src0 != srcEnd) 
    {
        u32 src0Color = *src0++;
        s32 r0 = (src0Color << 27) >> 27;
        s32 g0 = (src0Color << 22) >> 27;
        s32 b0 = (src0Color << 17) >> 27;
        u32 src1Color = *src1++;
        s32 r1 = (src1Color << 27) >> 27;
        s32 g1 = (src1Color << 22) >> 27;
        s32 b1 = (src1Color << 17) >> 27;

        // Average and bitwise-OR
        r0 = r1 + (((r0 - r1) * intensidadRelativa) >> 8);
        g0 = g1 + (((g0 - g1) * intensidadRelativa) >> 8);
        b0 = b1 + (((b0 - b1) * intensidadRelativa) >> 8);
        *dst = (*dst & RGB_ALPHA) | RGB2(r0, g0, b0);  // preserve high bit of dst
        dst++;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u32 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

#define tCoeff       data[0]
#define tCoeffTarget data[1]
#define tCoeffDelta  data[2]
#define tDelay       data[3]
#define tDelayTimer  data[4]
#define tPalettes    5 // data[5] and data[6], set/get via Set/GetWordTaskArg
#define tColor       data[7]
#define tId          data[8]

// Blend the selected palettes in a series of steps toward or away from the color.
// Only used by the Groudon/Kyogre fight scene to flash the screen for lightning.
// One call is used to fade the bg from white, while another fades the duo from black
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id)
{
    u32 taskId;

    taskId = CreateTask((void *)Task_BlendPalettesGradually, priority);
    gTasks[taskId].tCoeff = coeff;
    gTasks[taskId].tCoeffTarget = coeffTarget;

    if (delay >= 0)
    {
        gTasks[taskId].tDelay = delay;
        gTasks[taskId].tCoeffDelta = 1;
    }
    else
    {
        gTasks[taskId].tDelay = 0;
        gTasks[taskId].tCoeffDelta = -delay + 1;
    }

    if (coeffTarget < coeff)
        gTasks[taskId].tCoeffDelta *= -1;

    SetWordTaskArg(taskId, tPalettes, selectedPalettes);
    gTasks[taskId].tColor = color;
    gTasks[taskId].tId = id;
    gTasks[taskId].func(taskId);
}

static void Task_BlendPalettesGradually(u8 taskId)
{
    u32 palettes;
    s16 *data;
    s32 target;

    data = gTasks[taskId].data;
    palettes = GetWordTaskArg(taskId, tPalettes);

    if (++tDelayTimer > tDelay)
    {
        tDelayTimer = 0;
        BlendPalettes(palettes, tCoeff, tColor);
        target = tCoeffTarget;
        if (tCoeff == target)
        {
            DestroyTask(taskId);
        }
        else
        {
            tCoeff += tCoeffDelta;
            if (tCoeffDelta >= 0)
            {
                if (tCoeff < target)
                    return;
            }
            else if (tCoeff > target)
            {
                return;
            }
            tCoeff = target;
        }
    }
}

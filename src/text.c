#include "global.h"
#include "battle.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "sound.h"
#include "constants/songs.h"
#include "strings.h"
#include "string_util.h"
#include "window.h"
#include "text.h"
#include "blit.h"
#include "menu.h"
#include "dynamic_placeholder_text_util.h"
#include "fonts.h"

static u16 RenderText(struct TextPrinter *);
static u32 RenderFont(struct TextPrinter *);
static u16 FuncionFuenteNormal(struct TextPrinter *);
static u16 FuncionFuenteBorde(struct TextPrinter *);
static u16 FuncionFuenteGruesa(struct TextPrinter *);
static void SacaGlifoNormal(u16 glifo);
static void SacaGlifoBorde(u16 glifo);
static void SacaGlifoGruesa(u16 glifo);
static u32 AnchoGlifoNormal(u16 glifo);
static u32 AnchoGlifoBorde(u16 glifo);
static u32 AnchoGlifoGruesa(u16 glifo);

static EWRAM_DATA struct TextPrinter sTempTextPrinter = {0};
static EWRAM_DATA struct TextPrinter sTextPrinters[WINDOWS_MAX] = {0};

static u16 sTablaColores[256];
static u16 sUltimoColorFondo;
static u16 sUltimoColorLetra;
static u16 sUltimoColorSombra;
static u16 sUltimoColorContorno;

COMMON_DATA const struct FontInfo *gFonts = NULL;
COMMON_DATA bool8 gDisableTextPrinters = 0;
COMMON_DATA struct TextGlyph gCurGlyph = {0};
COMMON_DATA TextFlags gTextFlags = {0};

static const u8 sDownArrowTiles[] = INCBIN_U8("graphics/fonts/down_arrow.4bpp");
static const u8 sDarkDownArrowTiles[] = INCBIN_U8("graphics/fonts/down_arrow_alt.4bpp");
static const u8 sDownArrowYCoords[] = {0, 1, 2, 1};
static const u8 sWindowVerticalScrollSpeeds[] = {
    [OPTIONS_TEXT_SPEED_SLOW] = 1,
    [OPTIONS_TEXT_SPEED_MID] = 2,
    [OPTIONS_TEXT_SPEED_FAST] = 8,
};

static const struct GlyphWidthFunc sGlyphWidthFuncs[] =
{
    {FUENTE_NORMAL, AnchoGlifoNormal},
    {FUENTE_BORDE,  AnchoGlifoBorde},
    {FUENTE_GRUESA, AnchoGlifoGruesa},
};

struct
{
    u16 tileOffset;
    u8 width;
    u8 height;
} static const sKeypadIcons[] =
{
    [CHAR_A_BUTTON]       = {0,  8, 12},
    [CHAR_B_BUTTON]       = {1,  8, 12},
    [CHAR_L_BUTTON]       = {2, 16, 12},
    [CHAR_R_BUTTON]       = {4, 16, 12},
    [CHAR_START_BUTTON]   = {6, 24, 12},
    [CHAR_SELECT_BUTTON]  = {9, 24, 12},
    [CHAR_DPAD_UP]        = {12, 8, 12},
    [CHAR_DPAD_DOWN]      = {13, 8, 12},
    [CHAR_DPAD_LEFT]      = {14, 8, 12},
    [CHAR_DPAD_RIGHT]     = {15, 8, 12},
    [CHAR_DPAD_UPDOWN]    = {32, 8, 12},
    [CHAR_DPAD_LEFTRIGHT] = {33, 8, 12},
    [CHAR_DPAD_NONE]      = {34, 8, 12}
};

static const u8 sKeypadIconTiles[] = INCBIN_U8("graphics/fonts/keypad_icons.4bpp");

static const struct FontInfo sFontInfos[] =
{
    [FUENTE_NORMAL] = {
        .fontFunction = FuncionFuenteNormal,
        .maxLetterWidth = 6,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
        .colorContorno = 3,
    },
    // Las dos con contorno no llevan sombra: el hueco de la sombra se queda a
    // fondo y el relieve lo da el contorno, que es el cuarto valor del glifo.
    [FUENTE_BORDE] = {
        .fontFunction = FuncionFuenteBorde,
        .maxLetterWidth = 7,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 0,
        .colorContorno = 2,
    },
    [FUENTE_GRUESA] = {
        .fontFunction = FuncionFuenteGruesa,
        .maxLetterWidth = 7,
        .maxLetterHeight = 16,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .fgColor = 1,
        .bgColor = 0,
        .shadowColor = 0,
        .colorContorno = 2,
    },
};

static const u8 sMenuCursorDimensions[][2] =
{
    [FUENTE_NORMAL] = {8, 16},
    [FUENTE_BORDE]  = {8, 16},
    [FUENTE_GRUESA] = {8, 16},
};


static void SetFontsPointer(const struct FontInfo *fonts)
{
    gFonts = fonts;
}

void DeactivateAllTextPrinters(void)
{
    int printer;
    for (printer = 0; printer < WINDOWS_MAX; ++printer)
        sTextPrinters[printer].active = FALSE;
}

u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16))
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = gFonts[fontId].letterSpacing;
    printerTemplate.lineSpacing = gFonts[fontId].lineSpacing;
    printerTemplate.fgColor = gFonts[fontId].fgColor;
    printerTemplate.bgColor = gFonts[fontId].bgColor;
    printerTemplate.shadowColor = gFonts[fontId].shadowColor;
    return AddTextPrinter(&printerTemplate, speed, callback);
}

bool32 AddTextPrinter(struct TextPrinterTemplate *printerTemplate, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16))
{
    u32 i;
    u32 j;

    if (!gFonts)
        return FALSE;

    // El color del contorno no lo elige quien imprime: es del dibujo de la
    // fuente, igual que el propio contorno. Se pone aqui para que no haya que
    // acordarse en cada sitio que rellena una plantilla a mano.
    printerTemplate->colorContorno = gFonts[printerTemplate->fontId].colorContorno;

    sTempTextPrinter.active = TRUE;
    sTempTextPrinter.state = RENDER_STATE_HANDLE_CHAR;
    sTempTextPrinter.textSpeed = speed;
    sTempTextPrinter.delayCounter = 0;
    sTempTextPrinter.scrollDistance = 0;

    for (i = 0; i < (int)ARRAY_COUNT(sTempTextPrinter.subStructFields); i++)
        sTempTextPrinter.subStructFields[i] = 0;

    sTempTextPrinter.printerTemplate = *printerTemplate;
    sTempTextPrinter.callback = callback;
    sTempTextPrinter.minLetterSpacing = 0;

    GeneraTablaColores(printerTemplate->fgColor, printerTemplate->bgColor, printerTemplate->shadowColor, printerTemplate->colorContorno);
    if (speed != TEXT_SKIP_DRAW && speed != 0)
    {
        --sTempTextPrinter.textSpeed;
        sTextPrinters[printerTemplate->windowId] = sTempTextPrinter;
    }
    else
    {
        sTempTextPrinter.textSpeed = 0;

        // Render all text (up to limit) at once
        for (j = 0; j < 1024; ++j)
        {
            if (RenderFont(&sTempTextPrinter) == RENDER_FINISH)
                break;
        }

        // All the text is rendered to the window but don't draw it yet.
        if (speed != TEXT_SKIP_DRAW)
            CopyWindowToVram(sTempTextPrinter.printerTemplate.windowId, COPYWIN_GFX);
        sTextPrinters[printerTemplate->windowId].active = FALSE;
    }
    gDisableTextPrinters = FALSE;
    return TRUE;
}

void RunTextPrinters(void)
{
    u32 i;

    if (!gDisableTextPrinters)
    {
        for (i = 0; i < WINDOWS_MAX; ++i)
        {
            if (sTextPrinters[i].active)
            {
                u16 renderCmd = RenderFont(&sTextPrinters[i]);
                switch (renderCmd)
                {
                case RENDER_PRINT:
                    CopyWindowToVram(sTextPrinters[i].printerTemplate.windowId, COPYWIN_GFX);
                case RENDER_UPDATE:
                    if (sTextPrinters[i].callback != NULL)
                        sTextPrinters[i].callback(&sTextPrinters[i].printerTemplate, renderCmd);
                    break;
                case RENDER_FINISH:
                    sTextPrinters[i].active = FALSE;
                    break;
                }
            }
        }
    }
}

bool32 IsTextPrinterActive(u8 id)
{
    return sTextPrinters[id].active;
}

static u32 RenderFont(struct TextPrinter *textPrinter)
{
    u32 ret;
    while (TRUE)
    {
        ret = gFonts[textPrinter->printerTemplate.fontId].fontFunction(textPrinter);
        if (ret != RENDER_REPEAT)
            return ret;
    }
}

// Los glifos vienen a dos bits por pixel, o sea cuatro valores: fondo, letra,
// sombra y contorno. Esta tabla traduce de una vez los cuatro pixeles que caben
// en un byte a los cuatro medios bytes que quiere la VRAM, asi que se indexa
// directamente con el byte del glifo. Antes eran 81 entradas -3^4- y hacia
// falta una tabla de rebote para llegar a ellas, porque el cuarto valor no se
// usaba; ahora son 4^4 y se entra directo.
void GeneraTablaColores(u8 letra, u8 fondo, u8 sombra, u8 contorno)
{
    const u8 color[4] = { fondo, letra, sombra, contorno };
    u32 i;

    sUltimoColorLetra = letra;
    sUltimoColorFondo = fondo;
    sUltimoColorSombra = sombra;
    sUltimoColorContorno = contorno;

    for (i = 0; i < 256; i++)
    {
        sTablaColores[i] = (color[(i >> 6) & 3])
                         | (color[(i >> 4) & 3] << 4)
                         | (color[(i >> 2) & 3] << 8)
                         | (color[(i >> 0) & 3] << 12);
    }
}

void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    *bgColor = sUltimoColorFondo;
    *fgColor = sUltimoColorLetra;
    *shadowColor = sUltimoColorSombra;
}

void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
{
    GeneraTablaColores(*fgColor, *bgColor, *shadowColor, sUltimoColorContorno);
}

void DecompressGlyphTile(const void *src_, void *dest_)
{
    u32 temp;
    const u16 *src = src_;
    u32 *dest = dest_;

    temp = *(src++);
    *(dest)++ = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);

    temp = *(src++);
    *(dest++) = ((sTablaColores[temp & 255]) << 16) | (sTablaColores[temp >> 8]);
}

inline static void GLYPH_COPY(u8 *windowTiles, u32 widthOffset, u32 j, u32 i, u32 *glyphPixels, s32 width, s32 height)
{
    u32 xAdd, yAdd, pixelData, bits, toOrr, dummyX;
    u8 *dst;

    xAdd = j + width;
    yAdd = i + height;
    dummyX = j;
    for (; i < yAdd; i++)
    {
        pixelData = *glyphPixels++;
        for (j = dummyX; j < xAdd; j++)
        {
            if ((toOrr = pixelData & 15))
            {
                dst = windowTiles + ((j / 8) * 32) + ((j % 8) / 2) + ((i / 8) * widthOffset) + ((i % 8) * 4);
                bits = ((j & 1) * 4);
                *dst = (toOrr << bits) | (*dst & (240 >> bits));
            }
            pixelData >>= 4;
        }
    }
}

void CopyGlyphToWindow(struct TextPrinter *textPrinter)
{
    struct Window *window;
    struct WindowTemplate *template;
    u32 *glyphPixels;
    u32 currX, currY, widthOffset;
    s32 glyphWidth, glyphHeight;
    u8 *windowTiles;

    window = &gWindows[textPrinter->printerTemplate.windowId];
    template = &window->window;

    if ((glyphWidth = (template->width * 8) - textPrinter->printerTemplate.currentX) > gCurGlyph.width)
        glyphWidth = gCurGlyph.width;

    if ((glyphHeight = (template->height * 8) - textPrinter->printerTemplate.currentY) > gCurGlyph.height)
        glyphHeight = gCurGlyph.height;

    currX = textPrinter->printerTemplate.currentX;
    currY = textPrinter->printerTemplate.currentY;
    glyphPixels = gCurGlyph.gfxBufferTop;
    windowTiles = window->tileData;
    widthOffset = template->width * 32;

    if (glyphWidth < 9)
    {
        if (glyphHeight < 9)
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, glyphPixels, glyphWidth, glyphHeight);
        }
        else
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, glyphPixels, glyphWidth, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX, currY + 8, glyphPixels + 16, glyphWidth, glyphHeight - 8);
        }
    }
    else
    {
        if (glyphHeight < 9)
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, glyphPixels, 8, glyphHeight);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY, glyphPixels + 8, glyphWidth - 8, glyphHeight);
        }
        else
        {
            GLYPH_COPY(windowTiles, widthOffset, currX, currY, glyphPixels, 8, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY, glyphPixels + 8, glyphWidth - 8, 8);
            GLYPH_COPY(windowTiles, widthOffset, currX, currY + 8, glyphPixels + 16, 8, glyphHeight - 8);
            GLYPH_COPY(windowTiles, widthOffset, currX + 8, currY + 8, glyphPixels + 24, glyphWidth - 8, glyphHeight - 8);
        }
    }
}

void ClearTextSpan(struct TextPrinter *textPrinter, u32 width)
{
    struct Window *window;
    struct Bitmap pixels_data;
    struct TextGlyph *glyph;
    u8 *glyphHeight;

    if (sUltimoColorFondo != TEXT_COLOR_TRANSPARENT)
    {
        window = &gWindows[textPrinter->printerTemplate.windowId];
        pixels_data.pixels = window->tileData;
        pixels_data.width = window->window.width << 3;
        pixels_data.height = window->window.height << 3;

        glyph = &gCurGlyph;
        glyphHeight = &glyph->height;

        FillBitmapRect4Bit(
            &pixels_data,
            textPrinter->printerTemplate.currentX,
            textPrinter->printerTemplate.currentY,
            width,
            *glyphHeight,
            sUltimoColorFondo);
    }
}

#define FUNCION_DE_FUENTE(nombre, fuente)                                       \
static u16 nombre(struct TextPrinter *textPrinter)                              \
{                                                                               \
    struct TextPrinterSubStruct *sub = (void *)&textPrinter->subStructFields;   \
                                                                                \
    if (sub->hasFontIdBeenSet == FALSE)                                         \
    {                                                                           \
        sub->fontId = fuente;                                                   \
        sub->hasFontIdBeenSet = TRUE;                                           \
    }                                                                           \
    return RenderText(textPrinter);                                             \
}

FUNCION_DE_FUENTE(FuncionFuenteNormal, FUENTE_NORMAL)
FUNCION_DE_FUENTE(FuncionFuenteBorde,  FUENTE_BORDE)
FUNCION_DE_FUENTE(FuncionFuenteGruesa, FUENTE_GRUESA)

void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (gTextFlags.autoScroll == 1)
    {
        subStruct->autoScrollDelay = 0;
    }
    else
    {
        subStruct->downArrowYPosIdx = 0;
        subStruct->downArrowDelay = 0;
    }
}

void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    const u8 *arrowTiles;

    if (gTextFlags.autoScroll == 0)
    {
        if (subStruct->downArrowDelay != 0)
        {
            subStruct->downArrowDelay--;
        }
        else
        {
            FillWindowPixelRect(
                textPrinter->printerTemplate.windowId,
                textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);

            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(
                textPrinter->printerTemplate.windowId,
                arrowTiles,
                0,
                sDownArrowYCoords[subStruct->downArrowYPosIdx],
                8,
                16,
                textPrinter->printerTemplate.currentX,
                textPrinter->printerTemplate.currentY,
                8,
                16);
            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);

            subStruct->downArrowDelay = 8;
            subStruct->downArrowYPosIdx++;
        }
    }
}

void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
{
    FillWindowPixelRect(
        textPrinter->printerTemplate.windowId,
        textPrinter->printerTemplate.bgColor << 4 | textPrinter->printerTemplate.bgColor,
        textPrinter->printerTemplate.currentX,
        textPrinter->printerTemplate.currentY,
        8,
        16);
    CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
}

bool32 TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);

    if (subStruct->autoScrollDelay == NUM_FRAMES_AUTO_SCROLL_DELAY)
    {
        subStruct->autoScrollDelay = 0;
        return TRUE;
    }
    else
    {
        subStruct->autoScrollDelay++;
        return FALSE;
    }
}

void SetResultWithButtonPress(bool32 *result)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        *result = TRUE;
        PlaySE(SE_SELECT);
    }
}

bool32 TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
{
    bool32 result = FALSE;
    if (gTextFlags.autoScroll != 0 || AUTO_SCROLL_TEXT)
    {
        result = TextPrinterWaitAutoMode(textPrinter);

        if (AUTO_SCROLL_TEXT)
            SetResultWithButtonPress(&result);
    }
    else
    {
        TextPrinterDrawDownArrow(textPrinter);
        SetResultWithButtonPress(&result);
    }
    return result;
}

bool32 TextPrinterWait(struct TextPrinter *textPrinter)
{
    bool32 result = FALSE;
    if (gTextFlags.autoScroll != 0 || AUTO_SCROLL_TEXT)
    {
        result = TextPrinterWaitAutoMode(textPrinter);

        if (AUTO_SCROLL_TEXT)
            SetResultWithButtonPress(&result);
    }
    else
    {
        SetResultWithButtonPress(&result);
    }
    return result;
}

void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool32 drawArrow, u8 *counter, u8 *yCoordIndex)
{
    const u8 *arrowTiles;

    if (*counter != 0)
    {
        --*counter;
    }
    else
    {
        FillWindowPixelRect(windowId, (bgColor << 4) | bgColor, x, y, 8, 16);
        if (drawArrow == 0)
        {
            switch (gTextFlags.useAlternateDownArrow)
            {
            case FALSE:
            default:
                arrowTiles = sDownArrowTiles;
                break;
            case TRUE:
                arrowTiles = sDarkDownArrowTiles;
                break;
            }

            BlitBitmapRectToWindow(windowId, arrowTiles, 0, sDownArrowYCoords[*yCoordIndex & 3], 8, 16, x, y - 2, 8, 16);
            CopyWindowToVram(windowId, COPYWIN_GFX);
            *counter = 8;
            ++*yCoordIndex;
        }
    }
}

static u16 RenderText(struct TextPrinter *textPrinter)
{
    struct TextPrinterSubStruct *subStruct = (struct TextPrinterSubStruct *)(&textPrinter->subStructFields);
    u16 currChar;
    s32 width;
    s32 widthHelper;

    switch (textPrinter->state)
    {
    case RENDER_STATE_HANDLE_CHAR:
        if (JOY_HELD(A_BUTTON | B_BUTTON) && subStruct->hasPrintBeenSpedUp)
            textPrinter->delayCounter = 0;

        if (textPrinter->delayCounter && textPrinter->textSpeed)
        {
            textPrinter->delayCounter--;
            if (gTextFlags.canABSpeedUpPrint && (JOY_NEW(A_BUTTON | B_BUTTON)))
            {
                subStruct->hasPrintBeenSpedUp = TRUE;
                textPrinter->delayCounter = 0;
            }
            return RENDER_UPDATE;
        }

        if (gTextFlags.autoScroll)
            textPrinter->delayCounter = 3;
        else
            textPrinter->delayCounter = textPrinter->textSpeed;

        currChar = *textPrinter->printerTemplate.currentChar;
        textPrinter->printerTemplate.currentChar++;

        switch (currChar)
        {
        case CHAR_NEWLINE:
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY += (gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing);
            return RENDER_REPEAT;
        case PLACEHOLDER_BEGIN:
            textPrinter->printerTemplate.currentChar++;
            return RENDER_REPEAT;
        case EXT_CTRL_CODE_BEGIN:
            currChar = *textPrinter->printerTemplate.currentChar;
            textPrinter->printerTemplate.currentChar++;
            switch (currChar)
            {
            case EXT_CTRL_CODE_COLOR:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GeneraTablaColores(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor, textPrinter->printerTemplate.colorContorno);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_HIGHLIGHT:
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GeneraTablaColores(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor, textPrinter->printerTemplate.colorContorno);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHADOW:
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GeneraTablaColores(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor, textPrinter->printerTemplate.colorContorno);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                textPrinter->printerTemplate.fgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.bgColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->printerTemplate.shadowColor = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                GeneraTablaColores(textPrinter->printerTemplate.fgColor, textPrinter->printerTemplate.bgColor, textPrinter->printerTemplate.shadowColor, textPrinter->printerTemplate.colorContorno);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PALETTE:
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FONT:
                subStruct->fontId = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESET_FONT:
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE:
                textPrinter->delayCounter = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                textPrinter->state = RENDER_STATE_PAUSE;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
                textPrinter->state = RENDER_STATE_WAIT;
                if (gTextFlags.autoScroll)
                    subStruct->autoScrollDelay = 0;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_WAIT_SE:
                textPrinter->state = RENDER_STATE_WAIT_SE;
                return RENDER_UPDATE;
            case EXT_CTRL_CODE_PLAY_BGM:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= *textPrinter->printerTemplate.currentChar << 8;
                textPrinter->printerTemplate.currentChar++;
                PlayBGM(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ESCAPE:
                currChar = *textPrinter->printerTemplate.currentChar | 256;
                textPrinter->printerTemplate.currentChar++;
                break;
            case EXT_CTRL_CODE_PLAY_SE:
                currChar = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                currChar |= (*textPrinter->printerTemplate.currentChar << 8);
                textPrinter->printerTemplate.currentChar++;
                PlaySE(currChar);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_RIGHT:
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SHIFT_DOWN:
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y + *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_FILL_WINDOW:
                FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_PAUSE_MUSIC:
                m4aMPlayStop(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_RESUME_MUSIC:
                m4aMPlayContinue(&gMPlayInfo_BGM);
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_CLEAR:
                width = *textPrinter->printerTemplate.currentChar;
                textPrinter->printerTemplate.currentChar++;
                if (width > 0)
                {
                    ClearTextSpan(textPrinter, width);
                    textPrinter->printerTemplate.currentX += width;
                    return RENDER_PRINT;
                }
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_SKIP:
                textPrinter->printerTemplate.currentX = *textPrinter->printerTemplate.currentChar + textPrinter->printerTemplate.x;
                textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_CLEAR_TO:
                {
                    widthHelper = *textPrinter->printerTemplate.currentChar;
                    widthHelper += textPrinter->printerTemplate.x;
                    textPrinter->printerTemplate.currentChar++;
                    width = widthHelper - textPrinter->printerTemplate.currentX;
                    if (width > 0)
                    {
                        ClearTextSpan(textPrinter, width);
                        textPrinter->printerTemplate.currentX += width;
                        return RENDER_PRINT;
                    }
                }
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                textPrinter->minLetterSpacing = *textPrinter->printerTemplate.currentChar++;
                return RENDER_REPEAT;
            case EXT_CTRL_CODE_ENG:
                return RENDER_REPEAT;
            }
            break;
        case CHAR_PROMPT_CLEAR:
            textPrinter->state = RENDER_STATE_CLEAR;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_PROMPT_SCROLL:
            textPrinter->state = RENDER_STATE_SCROLL_START;
            TextPrinterInitDownArrowCounters(textPrinter);
            return RENDER_UPDATE;
        case CHAR_KEYPAD_ICON:
            currChar = *textPrinter->printerTemplate.currentChar++;
            gCurGlyph.width = DrawKeypadIcon(textPrinter->printerTemplate.windowId, currChar, textPrinter->printerTemplate.currentX, textPrinter->printerTemplate.currentY);
            textPrinter->printerTemplate.currentX += gCurGlyph.width + textPrinter->printerTemplate.letterSpacing;
            return RENDER_PRINT;
        case EOS:
            return RENDER_FINISH;
        }

        switch (subStruct->fontId)
        {
        case FUENTE_BORDE:
            SacaGlifoBorde(currChar);
            break;
        case FUENTE_GRUESA:
            SacaGlifoGruesa(currChar);
            break;
        default:
            SacaGlifoNormal(currChar);
            break;
        }

        CopyGlyphToWindow(textPrinter);

        if (textPrinter->minLetterSpacing)
        {
            textPrinter->printerTemplate.currentX += gCurGlyph.width;
            width = textPrinter->minLetterSpacing - gCurGlyph.width;
            if (width > 0)
            {
                ClearTextSpan(textPrinter, width);
                textPrinter->printerTemplate.currentX += width;
            }
        }
        else
        {
            textPrinter->printerTemplate.currentX += gCurGlyph.width;
        }
        return RENDER_PRINT;
    case RENDER_STATE_WAIT:
        if (TextPrinterWait(textPrinter))
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_CLEAR:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            FillWindowPixelBuffer(textPrinter->printerTemplate.windowId, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->printerTemplate.currentY = textPrinter->printerTemplate.y;
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL_START:
        if (TextPrinterWaitWithDownArrow(textPrinter))
        {
            TextPrinterClearDownArrow(textPrinter);
            textPrinter->scrollDistance = gFonts[textPrinter->printerTemplate.fontId].maxLetterHeight + textPrinter->printerTemplate.lineSpacing;
            textPrinter->printerTemplate.currentX = textPrinter->printerTemplate.x;
            textPrinter->state = RENDER_STATE_SCROLL;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_SCROLL:
        if (textPrinter->scrollDistance)
        {
            int scrollSpeed = GetPlayerTextSpeed();
            int speed = sWindowVerticalScrollSpeeds[scrollSpeed];
            if (textPrinter->scrollDistance < speed)
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, textPrinter->scrollDistance, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance = 0;
            }
            else
            {
                ScrollWindow(textPrinter->printerTemplate.windowId, 0, speed, PIXEL_FILL(textPrinter->printerTemplate.bgColor));
                textPrinter->scrollDistance -= speed;
            }
            CopyWindowToVram(textPrinter->printerTemplate.windowId, COPYWIN_GFX);
        }
        else
        {
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        }
        return RENDER_UPDATE;
    case RENDER_STATE_WAIT_SE:
        if (!IsSEPlaying())
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    case RENDER_STATE_PAUSE:
        if (textPrinter->delayCounter != 0)
            textPrinter->delayCounter--;
        else
            textPrinter->state = RENDER_STATE_HANDLE_CHAR;
        return RENDER_UPDATE;
    }

    return RENDER_FINISH;
}

static u32 (*GetFontWidthFunc(u8 fontId))(u16)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sGlyphWidthFuncs); ++i)
    {
        if (fontId == sGlyphWidthFuncs[i].fontId)
            return sGlyphWidthFuncs[i].func;
    }

    return NULL;
}

s32 GetGlyphWidth(u16 glyphId, u8 fontId)
{
    u32 (*func)(u16 fontId);

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;
    return func(glyphId);
}

s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)
{
    int minGlyphWidth;
    u32 (*func)(u16 fontId);
    u32 lineWidth;
    const u8 *bufferPointer;
    int glyphWidth;
    s32 width;

    minGlyphWidth = 0;

    func = GetFontWidthFunc(fontId);
    if (func == NULL)
        return 0;

    width = 0;
    lineWidth = 0;
    bufferPointer = 0;

    while (*str != EOS)
    {
        switch (*str)
        {
        case CHAR_NEWLINE:
            if (lineWidth > width)
                width = lineWidth;
            lineWidth = 0;
            break;
        case PLACEHOLDER_BEGIN:
            switch (*++str)
            {
            case VARIABLE_TEXTO_NOMBRE_JUGADOR:
                bufferPointer = gSaveBlockPtr->nombreJugador;
                break;
            case VARIABLE_TEXTO_1:
                bufferPointer = gVariableTexto1;
                break;
            case VARIABLE_TEXTO_2:
                bufferPointer = gVariableTexto2;
                break;
            case VARIABLE_TEXTO_3:
                bufferPointer = gVariableTexto3;
                break;
            default:
                return 0;
            }
            break;
        case CHAR_DYNAMIC:
            if (bufferPointer == NULL)
                bufferPointer = DynamicPlaceholderTextUtil_GetPlaceholderPtr(*++str);
            while (*bufferPointer != EOS)
            {
                glyphWidth = func(*bufferPointer++);
                if (minGlyphWidth > 0)
                {
                    if (glyphWidth < minGlyphWidth)
                        glyphWidth = minGlyphWidth;
                    lineWidth += glyphWidth;
                }
                else
                {
                    lineWidth += glyphWidth;
                }
            }
            bufferPointer = 0;
            break;
        case EXT_CTRL_CODE_BEGIN:
            switch (*++str)
            {
            case EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW:
                ++str;
            case EXT_CTRL_CODE_PLAY_BGM:
            case EXT_CTRL_CODE_PLAY_SE:
                ++str;
            case EXT_CTRL_CODE_COLOR:
            case EXT_CTRL_CODE_HIGHLIGHT:
            case EXT_CTRL_CODE_SHADOW:
            case EXT_CTRL_CODE_PALETTE:
            case EXT_CTRL_CODE_PAUSE:
            case EXT_CTRL_CODE_ESCAPE:
            case EXT_CTRL_CODE_SHIFT_RIGHT:
            case EXT_CTRL_CODE_SHIFT_DOWN:
                ++str;
                break;
            case EXT_CTRL_CODE_FONT:
                func = GetFontWidthFunc(*++str);
                if (func == NULL)
                    return 0;
                break;
            case EXT_CTRL_CODE_CLEAR:
                glyphWidth = *++str;
                lineWidth += glyphWidth;
                break;
            case EXT_CTRL_CODE_SKIP:
                lineWidth = *++str;
                break;
            case EXT_CTRL_CODE_CLEAR_TO:
                if (*++str > lineWidth)
                    lineWidth = *str;
                break;
            case EXT_CTRL_CODE_MIN_LETTER_SPACING:
                minGlyphWidth = *++str;
                break;
            case EXT_CTRL_CODE_ENG:
                break;
            case EXT_CTRL_CODE_RESET_FONT:
            case EXT_CTRL_CODE_PAUSE_UNTIL_PRESS:
            case EXT_CTRL_CODE_WAIT_SE:
            case EXT_CTRL_CODE_FILL_WINDOW:
            default:
                break;
            }
            break;
        case CHAR_KEYPAD_ICON:
            glyphWidth = GetKeypadIconWidth(*++str);

            if (minGlyphWidth > 0)
            {
                if (glyphWidth < minGlyphWidth)
                    glyphWidth = minGlyphWidth;
                lineWidth += glyphWidth;
            }
            else
            {
                lineWidth += glyphWidth;
            }
            break;
        case CHAR_PROMPT_SCROLL:
        case CHAR_PROMPT_CLEAR:
            break;
        default:
            glyphWidth = func(*str);
            if (minGlyphWidth > 0)
            {
                if (glyphWidth < minGlyphWidth)
                    glyphWidth = minGlyphWidth;
                lineWidth += glyphWidth;
            }
            else
            {
                lineWidth += glyphWidth;
            }
            break;
        }
        ++str;
    }

    if (lineWidth > width)
        return lineWidth;
    return width;
}

s32 GetStringLineWidth(u8 fontId, const u8 *str, s16 letterSpacing, u32 lineNum, u32 strSize)
{
    u32 strWidth = 0, strLen, currLine;
    u8 strCopy[strSize];

    for (currLine = 1; currLine <= lineNum; currLine++)
    {
        strWidth = GetStringWidth(fontId, str, letterSpacing);
        strLen = StringLineLength(str);
        memset(strCopy, EOS, strSize);
        if (currLine == lineNum && strLen != 0)
        {
            StringCopyN(strCopy, str, strLen);
            strWidth = GetStringWidth(fontId, strCopy, letterSpacing);
            strLen = StringLineLength(strCopy);
            StringAppend(strCopy, gText_EmptyString);
        }
        str += strLen + 1;
    }
    return strWidth;
}

u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(
        windowId,
        sKeypadIconTiles + (sKeypadIcons[keypadIconId].tileOffset * 32),
        0,
        0,
        128,
        128,
        x,
        y,
        sKeypadIcons[keypadIconId].width,
        sKeypadIcons[keypadIconId].height);
    return sKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconTileOffset(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].tileOffset;
}

u8 GetKeypadIconWidth(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].width;
}

u8 GetKeypadIconHeight(u8 keypadIconId)
{
    return sKeypadIcons[keypadIconId].height;
}

void SetDefaultFontsPointer(void)
{
    SetFontsPointer(sFontInfos);
}

u8 GetFontAttribute(u8 fontId, u8 attributeId)
{
    int result = 0;
    switch (attributeId)
    {
        case FONTATTR_MAX_LETTER_WIDTH:
            result = sFontInfos[fontId].maxLetterWidth;
            break;
        case FONTATTR_MAX_LETTER_HEIGHT:
            result = sFontInfos[fontId].maxLetterHeight;
            break;
        case FONTATTR_LETTER_SPACING:
            result = sFontInfos[fontId].letterSpacing;
            break;
        case FONTATTR_LINE_SPACING:
            result = sFontInfos[fontId].lineSpacing;
            break;
        case FONTATTR_COLOR_FOREGROUND:
            result = sFontInfos[fontId].fgColor;
            break;
        case FONTATTR_COLOR_BACKGROUND:
            result = sFontInfos[fontId].bgColor;
            break;
        case FONTATTR_COLOR_SHADOW:
            result = sFontInfos[fontId].shadowColor;
            break;
        case FONTATTR_COLOR_CONTORNO:
            result = sFontInfos[fontId].colorContorno;
            break;
    }
    return result;
}

u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
{
    return sMenuCursorDimensions[fontId][whichDimension];
}

// Saca un glifo del .latfont al buffer que luego pega CopyGlyphToWindow. Los
// glifos miden 16x16, o sea dos tiles de ancho por dos de alto, pero los que no
// pasan de 8 pixeles de ancho solo necesitan la columna izquierda.
#define SACA_GLIFO(saca, ancho, glifos, anchos)                                 \
static void saca(u16 glifo)                                                   \
{                                                                               \
    const u16 *dibujo = glifos + (32 * glifo);                                  \
                                                                                \
    gCurGlyph.width = anchos[glifo];                                            \
    gCurGlyph.height = 16;                                                      \
                                                                                \
    DecompressGlyphTile(dibujo, gCurGlyph.gfxBufferTop);                        \
    DecompressGlyphTile(dibujo + 16, gCurGlyph.gfxBufferBottom);                \
    if (gCurGlyph.width > 8)                                                    \
    {                                                                           \
        DecompressGlyphTile(dibujo + 8, gCurGlyph.gfxBufferTop + 8);            \
        DecompressGlyphTile(dibujo + 24, gCurGlyph.gfxBufferBottom + 8);        \
    }                                                                           \
}                                                                               \
static u32 ancho(u16 glifo)                                                     \
{                                                                               \
    return anchos[glifo];                                                       \
}

SACA_GLIFO(SacaGlifoNormal, AnchoGlifoNormal, gGlifosFuenteNormal, gAnchosFuenteNormal)
SACA_GLIFO(SacaGlifoBorde,  AnchoGlifoBorde,  gGlifosFuenteBorde,  gAnchosFuenteBorde)
SACA_GLIFO(SacaGlifoGruesa, AnchoGlifoGruesa, gGlifosFuenteGruesa, gAnchosFuenteGruesa)

// Ya no hay una familia de fuentes mas estrechas a la que caerse. Se mantiene
// la funcion para no tocar los sitios que la llaman: si el texto no cabe se
// recorta, que es mejor que no pintar nada.
u32 GetFontIdToFit(const u8 *string, u32 fontId, u32 letterSpacing, u32 widthPx)
{
    return fontId;
}

u8 *PrependFontIdToFit(u8 *start, u8 *end, u32 fontId, u32 width)
{
    u32 fitFontId = GetFontIdToFit(start, fontId, 0, width);

    if (fitFontId == fontId)
        return end;

    memmove(&start[3], &start[0], end - start);
    start[0] = EXT_CTRL_CODE_BEGIN;
    start[1] = EXT_CTRL_CODE_FONT;
    start[2] = fitFontId;
    end[3] = EOS;
    return end + 3;
}

u8 *WrapFontIdToFit(u8 *start, u8 *end, u32 fontId, u32 width)
{

    u32 fitFontId = GetFontIdToFit(start, fontId, 0, width);
    if (fitFontId != fontId)
    {
        memmove(&start[3], &start[0], end - start);
        start[0] = EXT_CTRL_CODE_BEGIN;
        start[1] = EXT_CTRL_CODE_FONT;
        start[2] = fitFontId;
        end[3] = EXT_CTRL_CODE_BEGIN;
        end[4] = EXT_CTRL_CODE_FONT;
        end[5] = fontId;
        end[6] = EOS;
        return end + 6;
    }
    else
    {
        return end;
    }
}

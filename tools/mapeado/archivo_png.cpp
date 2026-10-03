#include "archivo_png.h"

#include <cstdio>
#include <png.h>

namespace {

struct Archivo {
    FILE *f;
    explicit Archivo(const std::string &ruta) : f(fopen(ruta.c_str(), "rb")) {}
    ~Archivo() { if (f) fclose(f); }
};

bool Leer(const std::string &ruta, bool indices, int *ancho, int *alto, std::vector<uint8_t> &salida,
          std::string &error)
{
    Archivo a(ruta);
    if (!a.f) {
        error = "No se puede abrir " + ruta;
        return false;
    }
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    png_infop info = png_create_info_struct(png);
    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        error = ruta + " no es un PNG valido";
        return false;
    }
    png_init_io(png, a.f);
    png_read_info(png, info);
    int tipo = png_get_color_type(png, info);
    int bits = png_get_bit_depth(png, info);
    if (indices) {
        if (tipo != PNG_COLOR_TYPE_PALETTE) {
            png_destroy_read_struct(&png, &info, nullptr);
            error = ruta + " tiene que ser un PNG con paleta";
            return false;
        }
        if (bits < 8)
            png_set_packing(png);
    } else {
        if (bits == 16)
            png_set_strip_16(png);
        if (tipo == PNG_COLOR_TYPE_PALETTE)
            png_set_palette_to_rgb(png);
        if (tipo == PNG_COLOR_TYPE_GRAY && bits < 8)
            png_set_expand_gray_1_2_4_to_8(png);
        if (png_get_valid(png, info, PNG_INFO_tRNS))
            png_set_tRNS_to_alpha(png);
        if (tipo == PNG_COLOR_TYPE_GRAY || tipo == PNG_COLOR_TYPE_GRAY_ALPHA)
            png_set_gray_to_rgb(png);
        if (!(tipo & PNG_COLOR_MASK_ALPHA))
            png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);
    }
    png_set_interlace_handling(png);
    png_read_update_info(png, info);
    *ancho = png_get_image_width(png, info);
    *alto = png_get_image_height(png, info);
    size_t fila = png_get_rowbytes(png, info);
    salida.assign(fila * *alto, 0);
    std::vector<png_bytep> filas(*alto);
    for (int y = 0; y < *alto; y++)
        filas[y] = &salida[y * fila];
    png_read_image(png, filas.data());
    png_destroy_read_struct(&png, &info, nullptr);
    return true;
}

void Escribe(png_structp png, png_bytep datos, png_size_t n)
{
    auto *v = static_cast<std::vector<uint8_t> *>(png_get_io_ptr(png));
    v->insert(v->end(), datos, datos + n);
}

void Vacia(png_structp) {}

std::vector<uint8_t> Escribir(int ancho, int alto, const std::vector<uint8_t> &datos, int bytesPorPixel,
                              const std::vector<uint8_t> *paletaRgb)
{
    std::vector<uint8_t> salida;
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    png_infop info = png_create_info_struct(png);
    if (setjmp(png_jmpbuf(png))) {
        png_destroy_write_struct(&png, &info);
        return std::vector<uint8_t>();
    }
    png_set_write_fn(png, &salida, Escribe, Vacia);
    if (paletaRgb) {
        png_set_IHDR(png, info, ancho, alto, 8, PNG_COLOR_TYPE_PALETTE, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
        std::vector<png_color> pal(paletaRgb->size() / 3);
        for (size_t i = 0; i < pal.size(); i++)
            pal[i] = png_color{(*paletaRgb)[i * 3], (*paletaRgb)[i * 3 + 1], (*paletaRgb)[i * 3 + 2]};
        png_set_PLTE(png, info, pal.data(), pal.size());
    } else {
        png_set_IHDR(png, info, ancho, alto, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    }
    png_write_info(png, info);
    for (int y = 0; y < alto; y++)
        png_write_row(png, const_cast<png_bytep>(&datos[y * ancho * bytesPorPixel]));
    png_write_end(png, nullptr);
    png_destroy_write_struct(&png, &info);
    return salida;
}

} // namespace

bool LeerPngRgba(const std::string &ruta, int *ancho, int *alto, std::vector<uint8_t> &rgba, std::string &error)
{
    return Leer(ruta, false, ancho, alto, rgba, error);
}

bool LeerPngIndices(const std::string &ruta, int *ancho, int *alto, std::vector<uint8_t> &indices, std::string &error)
{
    return Leer(ruta, true, ancho, alto, indices, error);
}

std::vector<uint8_t> PngRgba(int ancho, int alto, const std::vector<uint8_t> &rgba)
{
    return Escribir(ancho, alto, rgba, 4, nullptr);
}

std::vector<uint8_t> PngIndices(int ancho, int alto, const std::vector<uint8_t> &indices,
                                const std::vector<uint8_t> &paletaRgb)
{
    return Escribir(ancho, alto, indices, 1, &paletaRgb);
}

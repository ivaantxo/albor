CXX ?= g++

CXXFLAGS := -Wall -Wextra -std=c++17 -O2 -DPNG_SKIP_SETJMP_CHECK
CXXFLAGS += $(shell pkg-config --cflags libpng)

LIBS := -lpng -lz
LDFLAGS += $(shell pkg-config --libs-only-L libpng)

# json11 es el de mapjson: solo hace falta para leer layouts.json.
SRCS := main.cpp mapeado.cpp proyecto.cpp archivo_png.cpp ../mapjson/json11.cpp

HEADERS := mapeado.h proyecto.h archivo_png.h ../mapjson/json11.h

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: mapeado$(EXE)
	@:

mapeado$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) mapeado mapeado.exe

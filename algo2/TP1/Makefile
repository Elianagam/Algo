# Flags de gcc. Se usan automáticamente para compilar *.c → *.o
CFLAGS := -g -std=c99 -Wall -Wformat=2
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wconversion -Wno-sign-conversion -Wbad-function-cast

# Se pueden comentar durante el desarrollo.
CFLAGS += -Werror


all: fixcol filesplit strutil.o prom_movil.o

include deps.mk

CFILES = main.c abb.c abb_pruebas.c testing.c pila.c
HFILES = testing.h abb.h pila.h
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

all: abb
	
valgrind: all
	valgrind $(VFLAGS) ./abb

clean:
	rm abb *.o

abb: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) -o abb *.c

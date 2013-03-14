GCCFLAGS = -Wall -Werror -std=gnu99 -g

all: main

main: main.c dict.o
	gcc $(GCCFLAGS) -o main main.c dict.o

dict.o: dict.c dict.h
	gcc $(GCCFLAGS) -c dict.c

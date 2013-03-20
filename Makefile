GCCFLAGS = -Wall -Werror -g -std=gnu99

all: main

main: dict.o main.c
	gcc $(GCCFLAGS) -o main main.c dict.o

dict.o: dict.c
	gcc $(GCCFLAGS) -c dict.c

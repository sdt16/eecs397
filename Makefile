GCCFLAGS = -std=gnu99 -Wall -Werror -g

all: freq

freq: dict.o freq.c
	gcc $(GCCFLAGS) -o freq freq.c dict.o

dict.o: dict.c
	gcc $(GCCFLAGS) -c dict.c

clean: 
	rm dict.o freq

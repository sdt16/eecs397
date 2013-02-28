all: main

clean:
	rm main dmap_vector.o

main: main.c dmap_vector.o
	gcc -Wall -Werror -std=gnu99 -o main main.c dmap_vector.o

dmap_vector.o: dmap_vector.c dmap_vector.h
	gcc -Wall -Werror -std=gnu99 -c dmap_vector.c

CFLAGS = -Wall -Werror -std=gnu99

matrix: matrix.o matrix_lib.o
	gcc -o matrix matrix.o matrix_lib.o

main.o: matrix_lib.h matrix.c
	gcc $(CFLAGS) -c matrix.c -lm

matrix_lib.o: matrix_lib.h matrix_lib.c
	gcc $(CFLAGS) -c matrix_lib.c

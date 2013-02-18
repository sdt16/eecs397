CFLAGS = -Wall -Werror -std=gnu99 -g

all: my_string_test

my_string_test: main.o my_string.o
	gcc $(CFLAGS) -o my_string_test main.o my_string.o

main.o: main.c my_string.h
	gcc $(CFLAGS) -c main.c

test_strncat: my_string.o test_strncat.c
	gcc $(CFLAGS) -o test_strncat test_strncat.c my_string.o

test_strncpy: my_string.o test_strncpy.c
	gcc $(CFLAGS) -o test_strncpy test_strncpy.c my_string.o

test_strstr: my_string.o test_strstr.c
	gcc $(CFLAGS) -o test_strstr test_strstr.c my_string.o

my_string.o: my_string.c my_string.h
	gcc $(CFLAGS) -c my_string.c

clean:
	rm -f *.o
	rm -f my_string_test

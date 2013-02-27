all: maincopy

maincopy: maincopy.c
	gcc -Wall -Werror -std=gnu99 -g -o maincopy maincopy.c

all: maincopy

maincopy: maincopy.c
	gcc -Wall -Werror -std=gnu99 -o maincopy maincopy.c

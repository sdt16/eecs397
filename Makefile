amount: number_to_word.o main.o
	gcc -o amount number_to_word.o main.o

number_to_word.o: number_to_word.c number_to_word.h
	gcc -Wall -Werror -c number_to_word.c

main.o: main.c number_to_word.h
	gcc -Wall -Werror -c main.c

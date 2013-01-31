#include <string.h>
#include <stdio.h>
#include "number_to_word.h"

void print_words_for_amount(int dollars, int cents) 
{
	char* words_for_numbers[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", 
		"seven ", "eight ", "nine "};
	char* words_for_teens[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", 
		"fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
	char* words_for_tens[] = {"", "ten ", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ",
		"sevety ", "eighty ", "ninty "};
	printf("$%d.%02d -> ", dollars, cents);
	char hundreds_string[50];
	int hundreds = dollars/100;
	hundreds_string[0] = '\0';
	if (hundreds) {
		strcat(hundreds_string, words_for_numbers[hundreds]);
		strcat(hundreds_string, "hundred ");
	}

	int tens = dollars/10%10;
	if (tens == 1) {
		printf("%s%s", hundreds_string, words_for_teens[dollars%10]);
	} else {
		printf("%s%s%s", hundreds_string, words_for_tens[tens], dollars>0?words_for_numbers[dollars%10]:"zero ");
	}

	printf("and %d/100 dollars\n", cents);

}

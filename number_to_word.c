#include "number_to_word.h"

void print_words_for_amount(int dollars, int cents) 
{
	char hundreds_string[50];
	int hundreds = dollars/100;
	if (hundreds) {
		strcat(hundreds_string, words_for_numbers[hundreds]);
		strcat(hundreds_string, " hundred");
	}

	int tens = dollars/10%10;
	if (tens == 1) {
		printf("%s %s", hundreds_string, words_for_teens[dollars%10]);
	} else {
		printf("%s %s %s", hundreds_string, words_for_tens[tens], words_for_numbers[dollars%10]);
	}

}

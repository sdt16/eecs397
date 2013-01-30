#ifndef _NUMBER_TO_WORD
#define _NUMBER_TO_WORD

print_words_for_amount(int dollars, int cents);

char* words_for_numbers[] = malloc(10*sizeof(char*));
words_for_numbers[0] = "zero";
words_for_numbers[1] = "one";
words_for_numbers[2] = "two";
words_for_numbers[3] = "three";
words_for_numbers[4] = "four";
words_for_numbers[5] = "five";
words_for_numbers[6] = "six";
words_for_numbers[7] = "seven";
words_for_numbers[8] = "eight";
words_for_numbers[9] = "nine";

char* words_for_teens[] = malloc(10*sizeof(char*));
words_for_teens[0] = "ten";
words_for_teens[1] = "eleven";
words_for_teens[2] = "twelve";
words_for_teens[3] = "thirteen";
words_for_teens[4] = "fourteen";
words_for_teens[5] = "fifteen";
words_for_teens[6] = "sixteen";
words_for_teens[7] = "seventeen";
words_for_teens[8] = "eighteen";
words_for_teens[9] = "nineteen";

char* words_for_tens[] = malloc(10*sizeof(char*));
words_for_tens[0] = "";
words_for_tens[1] = "ten";
words_for_tens[2] = "twenty";
words_for_tens[3] = "thirty";
words_for_tens[4] = "fourty";
words_for_tens[5] = "fifty";
words_for_tens[6] = "sixty";
words_for_tens[7] = "sevety";
words_for_tens[8] = "eighty";
words_for_tens[9] = "ninty";

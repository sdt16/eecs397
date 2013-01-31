#include "number_to_word.h"

int main(int argc, char* argv[])
{
	print_words_for_amount(0, 19);
	print_words_for_amount(1, 0);
	print_words_for_amount(5, 35);
	print_words_for_amount(34, 34);
	print_words_for_amount(156, 10);
	print_words_for_amount(520, 84);
	print_words_for_amount(634, 50);
	print_words_for_amount(789, 74);
	print_words_for_amount(900, 99);

	return 0;
}

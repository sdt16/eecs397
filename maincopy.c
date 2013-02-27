#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

  FILE* this_file = fopen(__FILE__, "r");
  if (this_file == NULL) {
    fprintf(stderr, "Error opening file");
    exit(1);
  }

  char* filename = __FILE__;
  char* ext_loc = strstr(filename, ".c");
  ext_loc[0] = '\0';
  char buf[50];
  snprintf(buf, sizeof(buf), "%sN%s", filename, ".c");

  FILE* new_file = fopen(buf, "w");
  if (new_file == NULL) {
    fprintf(stderr, "Error opening file");
    exit(1);
  }

  int last_char;
  while (EOF != (last_char = getc(this_file))) {
    putc(last_char, new_file);
  }

  fclose(this_file);
  fclose(new_file);

  return 0;

}

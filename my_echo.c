#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_max_argv(int argc) {
  if (argc<4) {
    return argc;
  } else {
    return 4;
  }
}


int has_n(int argc, char* argv[]) 
{
  int max = get_max_argv(argc);
  if (argc > 2) {
    for (int i = 1; i<max; i++) {
      if (strcmp(argv[i], "-n") == 0) {
	return 0;
      }
    }
  }
  return 1;
}

int get_r(int argc, char* argv[], int* has_r)
{
  int max = get_max_argv(argc);
  if (argc > 2) {
    for (int i = 1; i<max; i++) {
      if (strcmp(argv[i], "-r") == 0) {
	*has_r = 1;
	return atoi(argv[i+1]);
      }
    }
  }
  return 1;
}

int get_argc_offset(int n, int has_r)
{
  int offset = 0;
  if (!n) {
    offset++;
  }
  if (has_r) {
    offset += 2;
  }
  return offset;
}

int main(int argc, char* argv[]) 
{
  int has_r = 0;
  int n = has_n(argc, argv);
  int r = get_r(argc, argv, &has_r);
  
  int offset = get_argc_offset(n, has_r);
  
  fprintf(stderr, "n: %d\n", n);
  fprintf(stderr, "r: %d\n", r);

  for (int i = 0; i < r; i++) {
    for (int argc_pos = offset+1; argc_pos < argc; argc_pos++) {
      printf("%s", argv[argc_pos]);
      if (!(argc_pos == argc-1)) {
	printf(" ");
      }
    }
    if (n) {
      printf("\n");
    }
  }
  
  return 0;
}
  


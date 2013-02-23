#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int has_n(int argc, char* argv[]) 
{
  if (argc > 2) {
    for (int i = 1; i<4; i++) {
      if (strcmp(argv[i], "-n") == 0) {
	return 0;
      }
    }
  }
  return 1;
}

int get_r(int argc, char* argv[])
{
  if (argc > 2) {
    for (int i = 1; i<4; i++) {
      if (strcmp(argv[i], "-r") == 0) {
	return atoi(argv[i+1]);
      }
    }
  }
  return 1;
}

int main(int argc, char* argv[]) 
{
  int n = has_n(argc, argv);
  int r = get_r(argc, argv);
  
  fprintf(stderr, "n: %d\n", n);
  fprintf(stderr, "r: %d\n", r);
  for (int i = 0; i < r; i++) {
    printf("%s", argv[argc-1]);
  }
  if (n) {
    printf("\n");
  }

  return 0;
}
  


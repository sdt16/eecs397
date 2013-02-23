#include <stdio.h>

void re_curse(int n)
{
  printf("%d\n", n);
  re_curse(n+1);
}

int main(int argc, char* argv[])
{
  re_curse(1);
  return 0;
}

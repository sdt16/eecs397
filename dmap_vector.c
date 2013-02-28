#include <stdio.h>

// display vector, one value per line
void double_vector_display(double *d, int length)
{
  if (length > 0) {
    printf("%f", d[0]);
    for (int i = 1; i < length; i++) {
      printf(" %f", d[i]);
    }
    printf("\n");
  }
}


// apply function f to each element of d
void double_vector_map(double *d, int length, double (*f)(double))
{
  for (int i = 0; i<length; i++) {
    d[i] = (*f)(d[i]);
  }
}

double identity_f(double x) 
{
  return x;
}

double negate_f(double x) 
{
  return -x;
}

double invert_f(double x)
{
  return (1.0/x);
}

double mul_2_f(double x)
{
  return 2.0 * x;
}

double div_2_f(double x)
{
  return x/2.0;
}

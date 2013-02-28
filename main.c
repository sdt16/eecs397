#include <string.h>
#include "dmap_vector.h"

#define VEC_SIZE 100
int main(int argc, char* argv[])
{
  double vec[VEC_SIZE];
  memset(vec, 0, VEC_SIZE*sizeof(double));

  vec[0] = 5;
  vec[1] = 2;
  vec[2] = 3;
  vec[3] = 4;

  double_vector_display(vec, VEC_SIZE);

  double_vector_map(vec, VEC_SIZE, identity_f);
  double_vector_display(vec, VEC_SIZE);

  double_vector_map(vec, VEC_SIZE, negate_f);
  double_vector_display(vec, VEC_SIZE);

  double_vector_map(vec, VEC_SIZE, mul_2_f);
  double_vector_display(vec, VEC_SIZE);
  return 0;
}




#include <math.h>
#include <stdio.h>
#include "matrix_lib.h"

int main(int argc, char* argv[])
{
	double test_x[NUM_ROWS] = { 1.0, 1.0, 0 };
	double test_r[NUM_ROWS][NUM_ROWS] = {
		{cos(M_PI/2.0), -sin(M_PI/2.0), 0.0},
		{sin(M_PI/2.0), cos(M_PI/2.0), 0.0},
		{0.0, 0.0, 1.0} };
	double test_y[NUM_ROWS];

	printf("x:\n");
	display_vector(test_x);
	printf("rotation matrix r:\n");
	display_matrix(test_r);
	mul_3x3_by_3x1(test_r, test_x, test_y);
	printf("x rotated by r:\n");
	display_vector(test_y);
	return 0;
}

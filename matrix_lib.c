#include <stdio.h>
#include "matrix_lib.h"

void mul_3x3_by_3x1(double r[NUM_ROWS][NUM_ROWS], double x[NUM_ROWS], double y[NUM_ROWS])
{
	for (int row = 0; row < NUM_ROWS; row++) {
		double sum = 0;
		for (int column = 0; column < NUM_ROWS; column++) {
			sum += r[row][column]*x[column];
		}
		y[row] = sum;
	}
}	

void display_matrix(double a[NUM_ROWS][NUM_ROWS])
{
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int column = 0; column < NUM_ROWS; column++) {
			printf("%+#7.3f", a[row][column]);
		}
		printf("\n");
	}	
}

void display_vector(double a[NUM_ROWS])
{
	for (int i = 0; i < NUM_ROWS; i++) {
		printf("%+#7.3f\n", a[i]);
	}
}



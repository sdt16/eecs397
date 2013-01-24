#include <stdio.h>

#define A 1.75
#define B -2.0
#define C 2.5 

double quadratic(double a, double b, double c, double x)
{
	return a * x * x + b + x + c;
}

int main(int argc, char* argv[])
{
	FILE *fout;
	fout = fopen("quadratic.csv", "w");
	
	for (double x = -10.0; x <= 10.0; x += 0.1) {
		double y = quadratic(A, B, C, x);
		fprintf(fout, "%G, %G\n", x, y);
	}
	/* multiple calls to fprintf() ....*/
	/* when complete, close the file */
	fclose(fout);
}

// display vector, one value per line
void double_vector_display(double *d, int length);

// apply function f to each element of d
void *double_vector_map(double *d, int length, double (*f)(double));

double identity_f(double x); // returns x
double negate_f(double x); // returns -x
double invert_f(double x); // returns 1.0 / x
double mul_2_f(double x); // returns 2.0 * x
double div_2_f(double x); // returns x / 2.0


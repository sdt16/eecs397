#include<stdio.h>

#define VECTOR_LENGTH 3

/* implement a function that computes:

    b' = scale * a'
    where a' and b' are vectors of length VECTOR_LENGTH

    recall that in C uses "call by value", but arrays (vectors)
    are passed by reference (really pointers under the covers)
    allowing the array arguments to modified by a function
    */
void scale_vector(double a[], double b[], double scale)
{
}

/* implement a function to display a vector to stdout (printf)
    and remove the duplicated code currently found in main()
    */
void display_vector(double a[])
{
}

int main(int argc, char **argv)
{
    double x[VECTOR_LENGTH];
    double y[VECTOR_LENGTH];
    double scale = 2.0;
    int i;

    x[0] = 1.0;
    x[1] = 2.0;
    x[2] = 3.0;

    printf("vector x:");
    for(i=0; i < VECTOR_LENGTH; i++) {
        printf("%6.3f", x[i]);
    }
    printf("\n");

    printf("scaled by %f is:\n", scale);

    scale_vector(x, y, scale);

    printf("vector y:");
    for(i=0; i < VECTOR_LENGTH; i++) {
        printf("%6.3f", y[i]);
    }
    printf("\n");

    return 0;
}


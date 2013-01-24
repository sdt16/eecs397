#include <stdio.h>

void determine_epsilon_f()
{
	float machEps = 1.0f;
 
    printf( "current Epsilon, 1 + current Epsilon\n" );
    do {
       printf("%G\t%.20f\n", machEps, (1.0f + machEps));
       machEps /= 2.0f;
       // If next epsilon yields 1, then break, because current
       // epsilon is the machine epsilon.
    }
    while ((float)(1.0 + (machEps/2.0)) != 1.0);
 
    printf("\nCalculated Machine epsilon (float): %G\n", machEps);
}

void determine_epsilon_d()
{
	double machEps = 1.0f;
 
    printf( "current Epsilon, 1 + current Epsilon\n" );
    do {
       printf("%G\t%.20f\n", machEps, (1.0f + machEps));
       machEps /= 2.0f;
       // If next epsilon yields 1, then break, because current
       // epsilon is the machine epsilon.
    }
    while ((double)(1.0 + (machEps/2.0)) != 1.0);
 
    printf("\nCalculated Machine epsilon (double): %G\n", machEps);
}

void determine_epsilon_ld()
{
	long double machEps = 1.0f;
 
    printf( "current Epsilon, 1 + current Epsilon\n" );
    do {
       printf("%LG\t%.20Lf\n", machEps, (1.0f + machEps));
       machEps /= 2.0f;
       // If next epsilon yields 1, then break, because current
       // epsilon is the machine epsilon.
    }
    while ((long double)(1.0 + (machEps/2.0)) != 1.0);
 
    printf("\nCalculated Machine epsilon (long double): %LG\n", machEps);
}

int main(int argc, char* argv[])
{
	determine_epsilon_f();
	determine_epsilon_d();
	determine_epsilon_ld();
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

#define TEST_STRING_LENGTH 100

int main(int argc, char *argv[])
{
    char s1[TEST_STRING_LENGTH];
    char s2[TEST_STRING_LENGTH];
    char *result1, *result2;

    int failure = 0;

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    result1 = strncat(s1, "", TEST_STRING_LENGTH);
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncat(s1, "", TEST_STRING_LENGTH);

    if( result1 != result2 ) {
        printf("strncat() != my_strncat()\n");
        failure = 1;
    }

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strncat(s1, "hello, ", TEST_STRING_LENGTH);
    strncat(s1, "world", TEST_STRING_LENGTH - strlen(s1));
    my_strncat(s2, "hello, ", TEST_STRING_LENGTH);
    my_strncat(s2, "world", TEST_STRING_LENGTH - strlen(s1));
   
    if( 0 != strcmp(s1, s2) ) {
        printf("results of strncat() and my_strncat() with multiple calls different\n");
        failure = 1;
    } 

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strncat(s1, "hello, ", 3);
    my_strncat(s2, "hello, ", 3);

    if( 0 != strcmp(s1, s2) ) {
        printf("results of strncat() \"%s\" and my_strncat() \"%s\"with limited copy different\n", s1, s2);
        failure = 1;
    } 


   
 
    
  
    if( failure ) {
        exit(1);
    } 

    return 0;
}

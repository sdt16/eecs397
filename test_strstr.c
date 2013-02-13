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

    result1 = strstr(s1, "");
    result2 = my_strstr(s1, "");

    if ( result1 != result2 ) {
        printf("strstr() did not match return value for my_strstr()\n");
        failure = 1;
    }

    strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
    result1 = my_strstr(s1, "lmno");

    if( 0 != strcmp(strstr(s1, "lmno"), result1) ) {
        printf("failed to find substring with strstr expected \"%s\" not \"%s\"\n", strstr(s1, "lmno"), result1);
        failure = 1;
    }
   
    strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
    result1 = my_strstr(s1, "LMNO");

    if( NULL != result1 ) {
        printf("my_strstr() should have returned null but returned \"%s\" (%p) instead\n", result1, result1);
        failure = 1;
    }
   
    if( failure ) {
        exit(1);
    } 

    return 0;
}

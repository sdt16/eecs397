#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

#define TEST_STRING_LENGTH 100

int main(int argc, char *argv[])
{
    char s1[TEST_STRING_LENGTH];
    char s2[TEST_STRING_LENGTH];
    char src[TEST_STRING_LENGTH];
    char *result1, *result2;

    int failure = 0;

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strcpy(src, "");
    result1 = strncpy(s1, src, TEST_STRING_LENGTH);
    strcpy(src, "");
    result2 = my_strncpy(s1, src, TEST_STRING_LENGTH);

    if( result1 != result2 ) {
        printf(
            "strncpy(\"%s\", \"%s\", %d) returned %p != my_strncpy(\"%s\", \"%s\", %d) returned %p\n",
            s1, src, TEST_STRING_LENGTH, result1, s2, src, TEST_STRING_LENGTH,
            result2);
        failure = 1;
    }

    strcpy(src, "ab");
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncpy(s1, src, TEST_STRING_LENGTH);

    if( !strcmp(s2, "ab") ) {
        printf("failed to copy \"%s\"\n", "ab");
        failure = 1;
    }

    strcpy(src, "abcdefghijklmnopqrstuvwxyz");
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncpy(s1, src, 3);
    s1[3] = '\0';

    if( !strcmp(s2, "abc") ) {
        printf("failed to copy \"%s\" with short\n", "abc");
        failure = 1;
    }


   
    if( failure ) {
        exit(1);
    } 

    return 0;
}

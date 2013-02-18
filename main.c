#include <string.h>
#include <stdio.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
  char test_str[] = "abcdefg";
  if (strlen(test_str) != my_strlen(test_str)) {
    
    printf("Error with my_strlen(), real: %d, my: %d\n", (int)strlen(test_str), (int)my_strlen(test_str));
    return 1;
  } else {
    printf("strlen worked\n");
  }

  char* s1 = "abcdefg";
  char* s2 = "abcdefghi";
  if ((my_strncmp(s1, s2, 10)>0 && strncmp(s1, s2, 10)<= 0) || (my_strncmp(s1, s2, 10)<0 && strncmp(s1, s2, 10)>= 0) ||
      (my_strncmp(s1, s2, 10)==0 && strncmp(s1, s2, 10)!= 0)) {
    
    printf("Error with my_strncmp() 1, real: %d, my: %d\n", (int)strncmp(s1, s2, 10), (int)my_strncmp(s1, s2, 10));
    return 1;
  } else {
    printf("strcmp 1 worked\n");
  }

  if ((my_strncmp(s1, s2, 2)>0 && strncmp(s1, s2, 2)<= 0) || (my_strncmp(s1, s2, 2)<0 && strncmp(s1, s2, 2)>= 0) ||
      (my_strncmp(s1, s2, 2)==0 && strncmp(s1, s2, 2)!= 0)) {
    
    printf("Error with my_strncmp() 2, real: %d, my: %d\n", (int)strncmp(s1, s2, 2), (int)my_strncmp(s1, s2, 2));
    return 1;
  } else {
    printf("strcmp 2 worked\n");
  }

  char dest_real[10];
  char dest_my[10];
  strncpy(dest_real, s1, 10);
  my_strncpy(dest_my, s1, 10);
  if (strcmp(dest_real, dest_my)) {
    printf("my_strncpy failed, my: %s, real: %s\n", dest_my, dest_real);
    return 1;
  } else {
    printf("strncpy worked\n");
  }

  char dest_cat_real[20] = "hi";
  char dest_cat_my[20] = "hi";

  strncat(dest_cat_real, s1, 3);
  my_strncat(dest_cat_my, s1, 3);

  if (strcmp(dest_cat_real, dest_cat_my)) {
    printf("my_strncat failed, my: %s, real: %s\n", dest_cat_my, dest_cat_real);
    return 1;
  } else {
    printf("strncat worked\n");
  }

  
  if (strcmp(strstr(s2, s1), my_strstr(s2, s1))) {
    printf("my_strstr failed, real: %s, my: %s",strstr(s2, s1), my_strstr(s2, s1));
    return 1;
  } else {
    printf("strstr worked\n");
  }

  
  return 0;
}

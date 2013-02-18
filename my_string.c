#include "my_string.h"

size_t my_strlen(const char *s)
{
  int len;
  char seen;
  for (len = 0, seen = 1; seen != '\0'; len++) {
    seen = s[len];
  }

  return len-1;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
  int i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
      dest[i] = src[i];
  } 
  for (;i<n;i++) {
    dest[i] = '\0';
  }

  return dest;
}

char *my_strncat(char *dest, const char *src, size_t n) // implements strncat
{
  int dest_len = my_strlen(dest);
  int i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';

  return dest;
}
int my_strncmp(const char *s1, const char *s2, size_t n)
{
  int i;
  for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] < s2[i]) {
      return -1;
    } else if (s1[i] > s2[i]) {
      return 1;
    }
  }

  if (s1[i] == '\0' && s2[i] != '\0') {
    return -1;
  } else if (s1[i] != '\0' && s2[i] == '\0') {
    return 1;
  }

  return 0;
}

char *my_strstr(const char *src, const char *sub) {

  if (my_strlen(sub) == 0) {
    return (char*)src;
  } else if (my_strlen(sub) > my_strlen(src)) {
    return NULL;
  } 

  int sub_len = my_strlen(sub);
  int i;
  for (i = 0; i + sub_len < my_strlen(src); i++) {
    if (src[i] == sub[0]) {
      int match = 1;
      for (int j = 0; j < sub_len; j++) {
	if (src[i+j] != sub[j]) {
	  match = 0;
	}
      }
      if (match) {
	return (char*)(src+i);
      }
    }
  }
  return NULL;
}

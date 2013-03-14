#include <stdio.h>
#include "dict.h"

int main(int argc, char *argv[])
{
  dict_t my_dict;
  init_dict(&my_dict);

  add_kv(&my_dict, "test", "this is the value");
  char value[VALUE_LENGTH];
  lookup_kv(&my_dict, "test", value);
  printf("The looked up value is: %s\n", value);
  remove_kv(&my_dict, "test");
  printf("The value was found after removal: %d\n", lookup_kv(&my_dict, "test", value));

  free_dict(&my_dict);
  return 0;
}

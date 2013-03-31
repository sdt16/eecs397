#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dict.h"


void remove_other_chars(char *string)
{
  char *read, *write;
 
  for(read = write = string; *read != '\0'; ++read) {
    if(isalpha(*read) || *read == '-') {
      *(write++) = *read;
    }
  }
  *write = '\0';
}


void parse_file(dict_entry* dict, FILE* input)
{
  char* line = NULL;
  size_t len = 0;
  size_t read;

  while((read = getline(&line, &len, input)) != -1) {
      int first = 1;
      char* token = NULL;
      while((token = strtok(first?line:NULL, " ")) != NULL) {
	first = 0;
	char writeable_token[strlen(token)+1];
	strcpy(writeable_token, token);
	for(int i = 0; token[i]; i++) {
	  writeable_token[i] = tolower(writeable_token[i]);
	}
	remove_other_chars(writeable_token);
	int* value = malloc(sizeof(int));
	if (lookup_kv(dict, writeable_token, value) == 1) {
	  *value = *value + 1;
	  add_kv(dict, writeable_token, value);
	} else {
	  int one = 1;
	  add_kv(dict, writeable_token, &one);
	}
	free(value);
      }
    }
}

int main(int argc, char *argv[])
{
  FILE* input = NULL;
  if (argc == 1) {
    input = stdin;
  } else {
    input = fopen(argv[2], "r");
  }

  dict_entry* dict = alloc_dict();

  parse_file(dict, input); 

  print_dict(dict);

  free_dict(dict);

  return 0;
}

#ifndef _DICT_H
#define _DICT_H

#include "list.h"

typedef struct {
  char *key;
  int *value;
  struct list_head list;
}dict_entry;

dict_entry *alloc_dict(void);
void free_dict(dict_entry *d);
int add_kv(dict_entry *d,  char *key,  int *value);
void remove_kv(dict_entry *d,  char *key);
int lookup_kv(dict_entry *d,  char *key, int *value);
void print_dict(dict_entry *d);

#endif

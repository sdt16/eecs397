#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"


dict_entry *alloc_dict(void)
{
  dict_entry* entry = malloc(sizeof(dict_entry));
  INIT_LIST_HEAD(&(entry->list));
  return entry;
}

void free_dict(dict_entry *d)
{
  struct list_head *cur;
  struct list_head *n;

  dict_entry *entry;

  list_for_each_safe(cur, n, &d->list) {
    entry = list_entry(cur, dict_entry, list);
    list_del(cur);
    free(entry->key);
    free(entry->value);
    free(entry);
  }

  free(d);
}

int add_kv(dict_entry *d,  char *key, int *value)
{
  struct list_head *list_cur;
  dict_entry *entry;

  list_for_each(list_cur, &d->list) {
    entry = list_entry(list_cur, dict_entry, list);
    if (strcmp(entry->key, key) == 0) {
      *(entry->value) = *value;
      return 1;
    }
  }

  entry = malloc(sizeof(dict_entry));
  entry->key = calloc(strlen(key) + 1, sizeof(char));
  entry->value = malloc(sizeof(int));
  strcpy(entry->key, key);
  *(entry->value) = *value;
  list_add(&entry->list, list_cur);

  return 1;

}

void remove_kv(dict_entry *d,  char *key)
{

  struct list_head *cur;
  struct list_head *n;

  dict_entry *entry;

  list_for_each_safe(cur, n, &d->list) {
    entry = list_entry(cur, dict_entry, list);
    if (strcmp(entry->key, key) == 0) {
      list_del(cur);
      free(entry->key);
      free(entry->value);
      free(entry);
      return;
    }
  }
  

}

int lookup_kv(dict_entry *d,  char *key, int *value)
{
  struct list_head *cur;

  dict_entry *entry;

  list_for_each(cur, &d->list) {
    entry = list_entry(cur, dict_entry, list);
    if (strcmp(entry->key, key) == 0) { 
      *value = *(entry->value);
      return 1;
    }
  }

  return 0;

}

int compare(const void* s1, const void* s2)
{
  return -strcmp(* (char * const *) s1, * (char * const *) s2);
}

dict_entry* sort_dict(dict_entry* d)
{
  struct list_head *cur;

  dict_entry *entry;
  int size = 0;

  list_for_each(cur, &d->list) {
    size++;
  }

  char* elements[size];
  int i = 0;
  list_for_each(cur, &d->list) {
    entry = list_entry(cur, dict_entry, list);
    elements[i] = entry->key;
    i++;
  }

  qsort(&elements[0], size, sizeof(char*), compare);

  dict_entry* sorted = alloc_dict();
  for (i=0; i<size; i++) {
    int* value = malloc(sizeof(int));
    lookup_kv(d, elements[i], value);
    add_kv(sorted, elements[i], value);
    free(value);
  }

  return sorted;
}

void print_dict(dict_entry *d) 
{
  dict_entry* sorted = sort_dict(d);
  struct list_head *list_cur;
  dict_entry *entry;

  list_for_each(list_cur, &sorted->list) {
    entry = list_entry(list_cur, dict_entry, list);
    printf("%s  %d\n", entry->key, *(entry->value));
  }

  free_dict(sorted);
}

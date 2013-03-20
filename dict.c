#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"


dict_entry *alloc_dict(void)
{
  dict_entry* entry = malloc(sizeof(dict_entry));
  entry->key = calloc(1, sizeof(char));
  entry->value = calloc(1, sizeof(char));
  INIT_LIST_HEAD(&(entry->list));
  return entry;
}

void free_dict(dict_entry *d)
{
  struct list_head *cur;
  struct list_head *n;

  dict_entry *entry;

  list_for_each_safe(cur, n, d->list) {
    entry = list_entry(cur, dict_entry, list);
    list_del(cur);
    free(entry->key);
    free(entry->value);
    free(entry);
  }

  free(d);
}

int add_kv(dict_entry *d,  char *key, char *value)
{
  struct list_head *list_cur;
  dict_entry *entry;

  list_for_each(list_cur, d->list) {
    entry = list_entry(list_curr, dict_entry, list);
    if (strcmp(entry->key, key) == 0) {
      entry->value = realloc(entry->value, strlen(value)+1);
      strcpy(entry->value, value);
      return 1;
    }
  }

  entry = malloc(sizeof(dict_entry));
  entry->key = calloc(strlen(key) + 1, sizeof(char));
  entry->value = calloc(strlen(value) + 1, sizeof(char));
  strcpy(entry->key, key);
  strcpy(entry->value, value);

  list_add(entry, list_cur);

  return 1;

}

void remove_kv(dict_entry *d,  char *key)
{

  struct list_head *cur;
  struct list_head *n;

  dict_entry *entry;

  list_for_each_safe(cur, n, d->list) {
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

int lookup_kv(dict_entry *d,  char *key, char *value)
{
  struct list_head cur;

  dict_entry *entry;

  list_for_each(cur, d->list) {
    entry = list_entry(cur, dict_entry, list);
    if (strcmp(entry->key, key) == 0) { 
      strcpy(value, entry->value);
      return 1;
    }
  }

  return 0;

}

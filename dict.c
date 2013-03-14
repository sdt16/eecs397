#include <string.h>
#include <stdlib.h>
#include "dict.h"

// initialize the dict provided for use
void init_dict(dict_t *d)
{
  //int i;

    // allocate an "array" of keyvaluepair_t structures
    d->entries = calloc(MAX_ENTRIES, sizeof(keyvaluepair_t));


}

void free_dict(dict_t *d)
{
    // free each keyvaluepair_t's members that are non-NULL
  for (int i = 0; i<MAX_ENTRIES; i++) {
    if (d->entries[i].key != NULL) {
      free(d->entries[i].key);
      d->entries[i].key = NULL;
      free(d->entries[i].value);
      d->entries[i].value = NULL;
    }
  }

    // free "array" of keyvaluepair_t structures
    free(d->entries);
    d->entries = NULL;
}

int add_kv(dict_t *d, const char *key, const char *value)
{
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (d->entries[i].key == NULL) {
      d->entries[i].key = calloc(KEY_LENGTH, sizeof(char));
      d->entries[i].value = calloc(VALUE_LENGTH, sizeof(char));
      strcpy(d->entries[i].key, key);
      strcpy(d->entries[i].value, value);
      return 1;
    } else if (strcmp(d->entries[i].key, key) == 0) {
      strcpy(d->entries[i].key, key);
      strcpy(d->entries[i].value, value);
      return 1;
    }
  }
  return 0;
}

void remove_kv(dict_t *d, const char *key)
{
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (strcmp(d->entries[i].key, key) == 0) {
      free(d->entries[i].key);
      d->entries[i].key = NULL;
      free(d->entries[i].value);
      d->entries[i].value = NULL;
      break;
    }
  }
}

int lookup_kv(dict_t *d, const char *key, char *value)
{
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (d->entries[i].key != NULL) {
      if (strcmp(d->entries[i].key, key) == 0)  {
	strcpy(value, d->entries[i].value);
	return 1;
      }
    }
  }
  return 0;
}


#include <string.h>
#include "dict.h"

// initialize the dict provided for use
void init_dict(dict_t *d)
{
  int i;

  for(i=0; i < MAX_ENTRIES; i++) {
    memset(d->entries[i].key, '\0', KEY_LENGTH);
    memset(d->entries[i].value, '\0', VALUE_LENGTH);
  }
}

int add_kv(dict_t *d, const char *key, const char *value)
{
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (strlen(d->entries[i].key) == 0 || strcmp(d->entries[i].key, key) == 0) {
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
      d->entries[i].key[0] = '\0';
      break;
    }
  }
}

int lookup_kv(dict_t *d, const char *key, char *value)
{
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (strcmp(d->entries[i].key, key) == 0)  {
      strcpy(value, d->entries[i].value);
      return 1;
    }
  }
  return 0;
}


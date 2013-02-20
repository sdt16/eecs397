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
    return 0;
}

void remove_kv(dict_t *d, const char *key)
{
}

int lookup_kv(dict_t *d, const char *key, char *value)
{
    return 0;
}


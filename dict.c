#include <string.h>
#include <stdlib.h>
#include "dict.h"

// initialize the dict provided for use
void init_dict(dict_t *d)
{
    int i;

    // allocate an "array" of keyvaluepair_t structures
    d->entries = calloc(MAX_ENTRIES, sizeof(keyvaluepair_t));

}

void free_dict(dict_t *d)
{
    // free each keyvaluepair_t's members that are non-NULL

    // free "array" of keyvaluepair_t structures
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


#ifndef _DICT_H
#define _DICT_H

#define KEY_LENGTH 100
#define VALUE_LENGTH 100
#define MAX_ENTRIES 50

typedef struct {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} keyvaluepair_t;

typedef struct {
    keyvaluepair_t entries[MAX_ENTRIES];
} dict_t;

void init_dict(dict_t *d);

int add_kv(dict_t *d, const char *key, const char *value);
void remove_kv(dict_t *d, const char *key);
int lookup_kv(dict_t *d, const char *key, char *value);

#endif


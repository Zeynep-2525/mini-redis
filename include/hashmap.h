#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef struct HashMap HashMap;


HashMap *hashmap_create(void);
void hashmap_destroy(HashMap *map);

int hashmap_set(HashMap *map, const char *key, const char *value);
char *hashmap_get(HashMap *map, const char *key);
int hashmap_remove(HashMap *map, const char *key);

size_t hashmap_size(HashMap *map);

#endif
#include "../include/hashmap.h"
#include <stdlib.h>
#define INITIAL_CAPACITY 16

typedef struct Entry Entry; // forward declaration

struct HashMap
{
    size_t count;
    size_t bucket_count;
    Entry **buckets;
};

typedef struct Entry
{
    const char *key;
    const char *value;
    struct Entry *next;

} Entry;

HashMap *hashmap_create(void)
{

    HashMap *map = calloc(1, sizeof(*map));
    if (map == NULL)
    {
        return NULL;
    }
    map->count = 0;
    map->bucket_count = INITIAL_CAPACITY;
    Entry **buckets = calloc(map->bucket_count, sizeof(*buckets));
    if (buckets == NULL)
    {
        free(map);
        return NULL;
    }
    map->buckets = buckets;

    return map;
}

static unsigned long hash_djb2(const char *key)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
    {
        hash = hash * 33 + c;
    }
    return hash;
}
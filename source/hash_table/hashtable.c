#include <stdlib.h>
#include "hash_t.h"

// Functions

hash_table_t *create_hashtable(void)
{
    hash_table_t *hashtable = malloc(sizeof hashtable);

    hashtable->linkedLists = malloc((sizeof(LinkedList_t *) * TABLE_SIZE));

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable->linkedLists[i] = NULL;
    }
    return hashtable;
}

unsigned int hash_1(const char *key)
{
    unsigned int hash_key = (unsigned int)*key;
    return 1 + (hash_key % 13);
}
unsigned int hash_2(const char *key)
{
    unsigned int hash_key = (unsigned int)*key;
    return 1 + (hash_key % 11);
}
unsigned int hash_function(const char *key)
{
    int i = TABLE_SIZE - 1000;
    unsigned int hash_key = (hash_1(key) + (hash_2(key) * i)) % TABLE_SIZE;
    return hash_key;
}

//
//
//
//
//      INSERT, SEARCH, DELETE
int insert(hash_table_t *ht_t, LinkedList_t *entity)
{
    if (ht_t == NULL)
        return 0;

    int index = hash_function(entity->key);

    if (ht_t->linkedLists[index] != NULL)
    {
        LinkedList_t *ls = ht_t->linkedLists[index];
        ht_t->linkedLists[index] = entity;
        entity->next = ls;
        return 1;
    }
    ht_t->linkedLists[index] = entity;
    return 1;
}

unsigned int search(hash_table_t *ht_t, const char *key)
{
    int hash = hash_function(key);
    if (ht_t->linkedLists[hash] != NULL)
    {
        return hash;
    }
    return 0;
}
int delete (hash_table_t *ht_t, const char *key)
{
    int hash = hash_function(key);
    if (ht_t->linkedLists[hash] != NULL)
    {
        if (ht_t->linkedLists[hash]->next != NULL)
        {
            LinkedList_t *temp = ht_t->linkedLists[hash]->next;
            free(ht_t->linkedLists[hash]);
            ht_t->linkedLists[hash] = NULL;
            ht_t->linkedLists[hash] = temp;
            return 1;
        }
        free(ht_t->linkedLists[hash]);
        ht_t->linkedLists[hash] = NULL;
        return 1;
    }
    return 0;
}
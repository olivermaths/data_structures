#include <stdlib.h>
#include <stdio.h>
#include "hash_table/hash_t.h"

int main()
{
    hash_table_t *ht = create_hashtable();
    LinkedList_t *ls2 = malloc(sizeof(ls2));
    ls2->key = "Math";
    ls2->value = "Fernandes";
    ls2->next = NULL;
    insert(ht, ls2);
    LinkedList_t *ls = malloc(sizeof(ls));
    ls->key = "Matheus";
    ls->value = "de Oliveira";
    ls->next = NULL;
    insert(ht, ls);
    LinkedList_t *ls3 = malloc(sizeof(ls3));
    ls3->key = "Matheus";
    ls3->value = "Henrique";
    ls3->next = NULL;
    insert(ht, ls3);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (ht->linkedLists[i] != NULL)
        {
            printf("table key: %d, list key: %s, value: %s\n", i, ht->linkedLists[i]->key, ht->linkedLists[i]->value);
            printf("table key: %d, list key: %s, value: %s\n", i, ht->linkedLists[i]->next->key, ht->linkedLists[i]->next->value);
        }
    }

    delete (ht, "Matheus");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (ht->linkedLists[i] != NULL)
        {
            printf("table key: %d, list key: %s, value: %s\n", i, ht->linkedLists[i]->key, ht->linkedLists[i]->value);
            printf("table key: %d, list key: %s, value: %s\n", i, ht->linkedLists[i]->next->key, ht->linkedLists[i]->next->value);
        }
    }
}
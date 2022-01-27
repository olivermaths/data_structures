#define TABLE_SIZE 10000
typedef struct LinkedList_t LinkedList_t;
typedef struct hash_table_t hash_table_t;

typedef struct hash_table_t
{
    LinkedList_t **linkedLists;
} hash_table_t;

typedef struct LinkedList_t
{
    char *key;
    char *value;
    LinkedList_t *next;
} LinkedList_t;

extern hash_table_t *create_hashtable(void);
extern int insert(hash_table_t *ht_t, LinkedList_t *entity);
extern int delete (hash_table_t *ht_t, const char *key);

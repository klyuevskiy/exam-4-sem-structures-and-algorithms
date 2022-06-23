#ifndef internal_chains_h_included
#define internal_chains_h_included

#define DEFAULT_HAST_TABLE_SIZE 1007

typedef enum
{
    FREE,
    FILLED
} hash_entry_state;

struct hash_entry
{
    hash_entry_state state;
    int key;
    struct hash_entry *next;
};

typedef struct hash_entry hash_entry;

typedef struct
{
    hash_entry *table;
    int (*hash)(int), table_size;
} hash_table;

hash_table *create_hash_table(int table_size, int (*hash)(int));
void add_to_hash_table(hash_table *table, int key);
char find_in_hash_table(hash_table *table, int key);
void remove_from_hash_table(hash_table *table, int key);
void delete_hash_table(hash_table *table);

#endif
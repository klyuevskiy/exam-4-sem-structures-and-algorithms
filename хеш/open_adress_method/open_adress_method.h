#ifndef open_adress_method_h_included
#define open_adress_method_h_included

typedef enum
{
    FREE,
    FILLED
} entry_state;

typedef struct
{
    entry_state state;
    int key;
} hash_entry;

typedef struct
{
    int table_size, (*hash)(int, int);
    hash_entry *table;
} hash_table;

hash_table *create_hash_table(int table_size, int (*hash)(int, int));
void add_to_hash_table(hash_table *table, int key);
char find_in_hash_table(hash_table *table, int key);
void remove_from_hash_table(hash_table *table, int key);
void delete_hash_table(hash_table *table);

#endif
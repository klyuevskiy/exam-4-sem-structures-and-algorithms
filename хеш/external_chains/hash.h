#ifndef external_chains_h_included
#define external_chains_h_included

#include "..\..\list\list.h"

typedef struct
{
    int table_size, (*hash)(int);
    list_node **list_arr;
} hash_table;

hash_table *create_hash_table(int table_size, int (*hash)(int));
void add_to_hash_table(hash_table *table, int key);
char find_in_hash_table(hash_table *table, int key);
void remove_from_hash_table(hash_table *table, int key);
void delete_hash_table(hash_table *table);

#endif
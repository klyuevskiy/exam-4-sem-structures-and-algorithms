#include "hash.h"
#include <stdlib.h>

hash_table *create_hash_table(int table_size, int (*hash)(int))
{
    hash_table *table = (hash_table *)malloc(sizeof(hash_table));

    table->table_size = table_size;
    table->hash = hash;
    table->list_arr = (list_node **)calloc(table_size, sizeof(list_node *));

    for (int i = 0; i < table_size; i++)
        table->list_arr[i] = NULL;

    return table;
}

void add_to_hash_table(hash_table *table, int key)
{
    if (find_in_hash_table(table, key))
        return;

    int index = table->hash(key) % table->table_size;

    table->list_arr[index] = add_to_head(table->list_arr[index], key);
}
char find_in_hash_table(hash_table *table, int key)
{
    int index = table->hash(key) % table->table_size;

    return find_in_list(table->list_arr[index], key);
}
void remove_from_hash_table(hash_table *table, int key)
{
    int index = table->hash(key) % table->table_size;

    table->list_arr[index] = remove_from_list(table->list_arr[index], key);
}
void delete_hash_table(hash_table *table)
{
    for (int i = 0; i < table->table_size; i++)
        delete_list(table->list_arr[i]);

    free(table->list_arr);
    free(table);
}
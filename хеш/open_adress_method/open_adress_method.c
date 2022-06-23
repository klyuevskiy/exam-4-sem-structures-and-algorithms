#include "open_adress_method.h"
#include <stdlib.h>

hash_table *create_hash_table(int table_size, int (*hash)(int, int))
{
    hash_table *table = (hash_table *)malloc(sizeof(hash_table));

    table->table_size = table_size;
    table->hash = hash;
    table->table = (hash_entry *)calloc(table_size, sizeof(hash_entry));

    for (int i = 0; i < table_size; i++)
        table->table[i].state = FREE;

    return table;
}

int find_index_to_add(hash_table *table, int key)
{
    int index, i = 0;

    while (/*i < table->table_size &&*/
           table->table[index = (table->hash(key, i)) % table->table_size].state != FREE)
    {
        if (table->table[index].key == key)
            return -1;
        i++;
    }

    return (i == table->table_size ? -1 : index);
}

int find_index_to_find(hash_table *table, int key)
{
    int index, i = 0;

    while (i < table->table_size &&
           (table->table[index = (table->hash(key, i)) % table->table_size].key != key ||
            table->table[index].state != FILLED))
        i++;

    return (i == table->table_size ? -1 : index);
}

void add_to_hash_table(hash_table *table, int key)
{
    int index = find_index_to_add(table, key);

    if (index != -1)
    {
        table->table[index].state = FILLED;
        table->table[index].key = key;
    }
}

char find_in_hash_table(hash_table *table, int key)
{
    return find_index_to_find(table, key) != -1;
}

void remove_from_hash_table(hash_table *table, int key)
{
    int index = find_index_to_find(table, key);

    if (index != -1)
        table->table[index].state = FREE;
}

void delete_hash_table(hash_table *table)
{
    free(table->table);
    free(table);
}
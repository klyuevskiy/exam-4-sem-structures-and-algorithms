#include "hash.h"
#include <stdlib.h>

hash_table *create_hash_table(int table_size, int (*hash)(int))
{
    hash_table *table = (hash_table *)malloc(sizeof(hash_table));

    table->hash = hash;
    table->table_size = table_size;
    table->table = (hash_entry *)calloc(table_size, sizeof(hash_entry));

    for (int i = 0; i < table_size; i++)
    {
        table->table[i].state = FREE;
        table->table[i].next = NULL;
    }

    return table;
}

// поиск первой попавшуюся пустую запись в цепочке
//также ищет попутно конец цепочки(для добавления)
hash_entry *find_free_entry_in_chain(hash_entry *start)
{
    while (start != NULL && start->state != FREE)
        start = start->next;

    return start;
}

//предыдущая функция может не найти конец цепочки, но можно продолжить поиск с полученной позиции
hash_entry *find_last_entry_in_chain(hash_entry *start)
{
    while (start->next != NULL)
        start = start->next;

    return start;
}

hash_entry *find_free_entry_in_table(hash_table *table, int start_index)
{
    for (int i = start_index + 1; i < table->table_size; i++)
        if (table->table[i].state == FREE)
            return &(table->table[i]);

    for (int i = start_index - 1; i >= 0; i--)
        if (table->table[i].state == FREE)
            return &(table->table[i]);

    return NULL;
}

void add_to_hash_table(hash_table *table, int key)
{
    if (find_in_hash_table(table, key))
        return;

    int index = table->hash(key) % table->table_size;

    hash_entry *insert_to = &(table->table[index]);

    // ищем позицию для вставки внутри цепочки
    insert_to = find_free_entry_in_chain(insert_to);

    if (insert_to != NULL)
    {
        insert_to->key = key;
        insert_to->state = FILLED;
    }
    else
    {
        //позиции для вставки внутри цепочки нет
        hash_entry *last_chain_entry = find_last_entry_in_chain(&(table->table[index]));

        // нет проверки на переполнение
        insert_to = find_free_entry_in_table(table, index);

        insert_to->key = key;
        insert_to->state = FILLED;

        last_chain_entry->next = insert_to;
    }
}

hash_entry *find_hash_entry(hash_entry *start, int key)
{
    while (start != NULL && (start->state != FILLED || start->key != key))
        start = start->next;

    return start;
}

char find_in_hash_table(hash_table *table, int key)
{
    int index = table->hash(key) % table->table_size;
    return find_hash_entry(&(table->table[index]), key) != NULL;
}
void remove_from_hash_table(hash_table *table, int key)
{
    int index = table->hash(key) % table->table_size;

    hash_entry *entry = find_hash_entry(&(table->table[index]), key);

    if (entry != NULL)
        entry->state = FREE;
}

void delete_hash_table(hash_table *table)
{
    free(table->table);
    free(table);
}
#include "open_adress_method\open_adress_method.h"
#include <stdio.h>

int hash(int key, int i)
{
    return key + i * (key + 1);
}

int main()
{
    hash_table *table = create_hash_table(11, hash);

    add_to_hash_table(table, 120);
    add_to_hash_table(table, 20);

    remove_from_hash_table(table, 120);
    remove_from_hash_table(table, 20);
    add_to_hash_table(table, 320);
    add_to_hash_table(table, 420);
    add_to_hash_table(table, 10);

    printf("%d %d %d", find_in_hash_table(table, 320), find_in_hash_table(table, 420), find_in_hash_table(table, 120));
}
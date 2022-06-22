#include "index_set.h"
#include <stdlib.h>

index_set *create_index_set(int max_indeces_number)
{
    index_set *set = (index_set *)malloc(sizeof(index_set));

    set->indeces_number = 0;
    set->indeces = (int *)calloc(max_indeces_number, sizeof(int));

    return set;
}

void push(index_set *set, int index)
{
    set->indeces[set->indeces_number++] = index;
}

void pop(index_set *set)
{
    set->indeces_number--;
}

void delete_index_set(index_set *set)
{
    free(set->indeces);
    free(set);
}

void copy(index_set *to, index_set *from)
{
    to->indeces_number = from->indeces_number;

    for (int i = 0; i < to->indeces_number; i++)
        to->indeces[i] = from->indeces[i];
}
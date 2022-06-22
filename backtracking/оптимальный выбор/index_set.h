#ifndef index_set_h_included
#define index_set_h_included

typedef struct
{
    int indeces_number;
    int *indeces;
} index_set;

index_set *create_index_set(int max_indeces_number);
void push(index_set *set, int index);
void pop(index_set *set);
void delete_index_set(index_set *set);
void copy(index_set *to, index_set *from);

#endif
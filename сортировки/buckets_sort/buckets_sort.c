#include "buckets_sort.h"
#include "..\..\list\list.h"
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

void buckets_sort(int *arr, int size, int left_bound, int right_bound, int buckets_number)
{
    int range = right_bound - left_bound;

    list_node **buckets = (list_node **)calloc(buckets_number, sizeof(list_node *));

    for (int i = 0; i < buckets_number; i++)
        buckets[i] = NULL;

    for (int i = 0; i < size; i++)
    {
        int index = max(arr[i] - left_bound - 1, 0) * buckets_number / range;
        buckets[index] = add_order_to_list(buckets[index], arr[i]);
    }

    int j = 0;

    for (int i = 0; i < buckets_number; i++)
    {
        for (list_node *it = buckets[i]; it != NULL; it = it->next)
            arr[j++] = it->data;

        delete_list(buckets[i]);
    }

    free(buckets);
}
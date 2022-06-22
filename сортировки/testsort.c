#include <stdio.h>
#include <stdlib.h>
#include "double_way_insertion_sort\double_way_insertion_sort.h"

int main()
{
    int arr[] = {2, 5, 2, 1, 4, 3, 9, 0},
        size = sizeof(arr) / sizeof(*arr);

    double_way_insertion_sort_array_N(arr, size);

    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
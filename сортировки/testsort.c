#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort\insertion_sort.h"

int main()
{
    int arr[] = {2, 5, 2, 1, 4, 3, 9, 0},
        size = sizeof(arr) / sizeof(*arr);

    list_insertion_sort(arr, size);
    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
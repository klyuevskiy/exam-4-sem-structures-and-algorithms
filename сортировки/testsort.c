#include <stdio.h>
#include <stdlib.h>
#include "buckets_sort.h"

int main()
{
    int arr[] = {2, 5, 2, 1, 4, 3, 9, 0},
        size = sizeof(arr) / sizeof(*arr);

    buckets_sort(arr, size, 0, 9, 10);

    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
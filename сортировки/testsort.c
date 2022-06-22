#include <stdio.h>
#include <stdlib.h>
#include "simple_selection_sort\simple_selection_sort.h"

int main()
{
    int arr[] = {2, 5, 2, 1, 4, 3, 9, 0},
        size = sizeof(arr) / sizeof(*arr);

    simple_selection_sort(arr, size);

    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
#include <stdio.h>
#include "quicksort/quicksort.h"

int main()
{
    int arr[] = {2, 5, 2, 1, 4, 3, 9, 0},
        size = sizeof(arr) / sizeof(*arr);

    quicksort_without_support_elem(arr, size);

    for (int *i = arr; i != arr + size; i++)
        printf("%d ", *i);
}
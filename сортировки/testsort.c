#include <stdio.h>
#include <stdlib.h>
#include "radix_sort\radix_sort.h"

int main()
{
    int arr[] =
        {41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36},
        size = sizeof(arr) / sizeof(*arr);

    radix_sort(arr, size);
    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "quicksort\quicksort.h"

int main()
{
    int arr[] = {5, 2, 9, 1, 4},
        //{41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36},
        size = sizeof(arr) / sizeof(*arr);

    quiksort_iterative_knut(arr, size);
    for (int *i = arr; i != arr + size; i++)
    {
        printf("%d ", *i);
    }
}
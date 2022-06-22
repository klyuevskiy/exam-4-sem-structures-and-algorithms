#include "simple_selection_sort.h"

#define min(arr, i, j) (arr[i] < arr[j] ? i : j)

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

void simple_selection_sort(int *arr, int size)
{
    for (int i = 0; i + 1 < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
            min_index = min(arr, min_index, j);

        swap(int, arr[i], arr[min_index]);
    }
}
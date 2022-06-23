#include "radix_sort.h"

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

void help_sort(int *arr, int left, int right, int bit)
{
    if (left >= right || !bit)
        return;

    int i = left, j = right;

    while (i < j)
    {
        while (i < j && !(arr[i] & bit))
            i++;
        while (i < j && (arr[j] & bit))
            j--;

        if (i < j)
        {
            swap(int, arr[i], arr[j]);
            i++;
            j--;
        }
    }

    while (arr[i] & bit)
        i--;

    help_sort(arr, left, i, bit >> 1);
    help_sort(arr, i + 1, right, bit >> 1);
}

void radix_sort(int *arr, int size)
{
    help_sort(arr, 0, size - 1, 1 << (sizeof(int) * 8 - 2));
}
#include "radix_sort.h"

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

void help_sort(int *arr, int size, int bit)
{
    int i = 0, j = size - 1;

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

    if (!(bit >>= 1))
        return;

    if (i > 0)
        help_sort(arr, i + 1, bit);
    if (size - i - 1 > 1)
        help_sort(arr + i + 1, size - i - 1, bit);
}

void radix_sort(int *arr, int size)
{
    help_sort(arr, size, 1 << (sizeof(int) * 8 - 2));
}
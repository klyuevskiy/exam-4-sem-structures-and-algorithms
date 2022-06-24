#include "find_median.h"

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

int find_median(int *arr, int size, int k)
{
    int l = 0, r = size - 1;

    while (l < r)
    {
        int x = arr[k], i = l, j = r;
        while (i <= j)
        {
            while (arr[i] < x)
                i++;
            while (arr[j] > x)
                j--;

            if (i <= j)
            {
                swap(int, arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (j < k)
            l = i;
        if (i > k)
            r = j;
    }

    return arr[k];
}
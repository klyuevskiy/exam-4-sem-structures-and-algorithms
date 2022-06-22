#include "shell_sort.h"

#define int_swap(a, b) \
    {                  \
        int t = a;     \
        a = b;         \
        b = t;         \
    }

void shell_sort(int *arr, int size)
{
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; i++)
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
                int_swap(arr[j], arr[j + step]);
}
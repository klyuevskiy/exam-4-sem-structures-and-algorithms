#include "quicksort.h"

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

#define int_swap(a, b) swap(int, a, b)

void quicksort_virt(int *arr, size_t size)
{
    int support = arr[size / 2],
        i = 0, j = size - 1;

    while (i <= j)
    {
        while (arr[i] < support && i <= j)
            i++;
        while (arr[j] > support && i <= j)
            j--;

        if (i <= j)
        {
            int_swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (j > 0)
        quicksort_virt(arr, j + 1);
    if (size > i)
        quicksort_virt(arr + i, size - i);
}

void quicksort_knut(int *arr, size_t size)
{
    int support = *arr, i = 0, j = size - 1;

    while (i <= j)
    {
        while (arr[i] < support && i <= j)
            i++;
        while (arr[j] > support && i <= j)
            j--;
        if (i <= j)
        {
            int_swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (j > 0)
        quicksort_knut(arr, j + 1);
    if (size > i)
        quicksort_knut(arr + i, size - i);
}

void sort_help(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int i = 0, j = right;

    while (i < j)
    {
        while (i < j && arr[i] <= arr[j])
            i++;
        int_swap(arr[i], arr[j]);

        while (i < j && arr[i] <= arr[j])
            j--;

        int_swap(arr[i], arr[j]);
    }

    sort_help(arr, left, i - 1);
    sort_help(arr, i, right);
}

void quicksort_without_support_elem(int *arr, size_t size)
{
    sort_help(arr, 0, size - 1);
}
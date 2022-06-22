#include "heap_sort.h"
#include <stdlib.h>

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

void update_heap(int *arr, int size, int index)
{
    int largest = index, l = index * 2 + 1, r = index * 2 + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != index)
    {
        swap(int, arr[index], arr[largest]);
        update_heap(arr, size, largest);
    }
}

void heap_sort(int *arr, int size)
{
    // идём с конца и строим кучу
    for (int i = size / 2 - 1; i >= 0; i--)
        update_heap(arr, size, i);

    // куча постоена, меняем каждый раз первый с последним
    for (int i = size - 1; i >= 0; i--)
    {
        swap(int, arr[0], arr[i]);
        update_heap(arr, i, 0);
    }
}
#include "bubble_shaker_sort.h"

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

void bubble_sort(int *arr, int size)
{
    char swaped = 1;
    for (int i = 0; i < size && swaped; i++)
    {
        swaped = 0;
        for (int j = 0; j + i + 1 < size; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(int, arr[j], arr[j + 1]);
                swaped = 1;
            }
    }
}

void shaker_sort(int *arr, int size)
{
    int l = 0, r = 0;

    char swaped = 1, direction = 1;

    while (l + r < size && swaped)
    {
        swaped = 0;

        if (direction)
        {
            for (int i = l; i + r + 1 < size; i++)
                if (arr[i] > arr[i + 1])
                {
                    swap(int, arr[i], arr[i + 1]);
                    swaped = 1;
                }
            ++r;
        }
        else
        {
            for (int i = size - r - 1; i > l; i--)
                if (arr[i - 1] > arr[i])
                {
                    swap(int, arr[i - 1], arr[i]);
                    swaped = 1;
                }
            ++l;
        }

        direction = !direction;
    }
}
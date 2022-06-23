#include "insertion_sort.h"

void simple_insertion_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int num = arr[i], j;
        for (j = i - 1; j >= 0 && arr[j] > num; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = num;
    }
}

int find_insert_position(int *arr, int elem, int right_board)
{
    int l = 0, r = right_board;

    while (l < r)
    {
        int m = (l + r) / 2;
        if (elem < arr[m])
            r = m;
        else
            l = m + 1;
    }

    return l;
}

void binary_insertion_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        int insert_pos = find_insert_position(arr, num, i);

        for (int j = i - 1; j >= insert_pos; j--)
            arr[j + 1] = arr[j];

        arr[insert_pos] = num;
    }
}
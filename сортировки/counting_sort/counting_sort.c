#include "counting_sort.h"
#include <stdlib.h>

void counting_sort(int *arr, int size)
{
    int *tmp = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
            count += (arr[j] < arr[i] || j < i && arr[j] == arr[i]);

        tmp[count] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = tmp[i];

    free(tmp);
}

void distributive_countig_sort(int *arr, int size, int left_bound, int right_bound)
{
    int range = right_bound - left_bound + 1;
    int *count = (int *)calloc(range, sizeof(int));

    for (int i = 0; i < size; i++)
        count[i] = 0;

    for (int *it = arr; it != arr + size; it++)
        count[*it - left_bound]++;

    int k = 0;
    for (int i = 0; i < range; i++)
        while (count[i]--)
            arr[k++] = i + left_bound;

    free(count);
}
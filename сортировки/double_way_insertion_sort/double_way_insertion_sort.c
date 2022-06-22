#include "double_way_insertion_sort.h"
#include "..\list\list.h"
#include <stdlib.h>

int get_median(int *arr, int size)
{
    if (arr[0] > arr[size / 2] && arr[0] < arr[size - 1] ||
        arr[0] > arr[size - 1] && arr[0] < arr[size / 2])
        return arr[0];

    if (arr[size / 2] > arr[0] && arr[size / 2] < arr[size - 1] ||
        arr[size / 2] > arr[size - 1] && arr[size / 2] < arr[0])
        return arr[size / 2];

    return arr[size - 1];
}

int find_insert_pos(int *arr, int elem, int right_bound)
{
    int l = 0, r = right_bound;

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

void right_shift(int *arr, int start_pos, int right_bound)
{
    for (--right_bound; right_bound >= start_pos; right_bound--)
        arr[right_bound + 1] = arr[right_bound];
}

void double_way_insertion_sort_array_N(int *arr, int size)
{
    int *tarr = (int *)calloc(size, sizeof(int));

    int median = get_median(arr, size),
        tarr_elements_count = 0, arr_elements_count = 0;

    for (int *it = arr; it != arr + size; it++)
    {
        int num = *it;
        int *array = (num < median ? arr : tarr);
        int *elements_count = (num < median ? &arr_elements_count : &tarr_elements_count);

        int insert_pos = find_insert_pos(array, num, *elements_count);
        right_shift(array, insert_pos, (*elements_count)++);
        array[insert_pos] = num;
    }

    for (int i = 0; i < tarr_elements_count; i++)
        arr[arr_elements_count + i] = tarr[i];

    free(tarr);
}

void double_way_insertion_sort_array_2N(int *arr, int size)
{
    int *arrays[2] = {(int *)calloc(size, sizeof(int)), (int *)calloc(size, sizeof(int))};

    int median = get_median(arr, size),
        elements_count[2] = {0, 0};

    for (int *it = arr; it != arr + size; it++)
    {
        int *array = (*it < median ? arrays[0] : arrays[1]);
        int *elements_cnt = (*it < median ? elements_count : elements_count + 1);

        int insert_pos = find_insert_pos(array, *it, *elements_cnt);
        right_shift(array, insert_pos, (*elements_cnt)++);
        array[insert_pos] = *it;
    }

    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < elements_count[i]; j++)
            arr[k++] = arrays[i][j];

    free(arrays[0]);
    free(arrays[1]);
}

void double_way_insertion_sort_list(int *arr, int size)
{
    int median = get_median(arr, size);

    list_node *head[2] = {NULL, NULL};

    for (int *it = arr; it != arr + size; it++)
    {
        list_node **list = (*it < median ? head : head + 1);
        *list = add_order_to_list(*list, *it);
    }

    int j = 0;

    for (int i = 0; i < 2; i++)
    {
        for (list_node *it = head[i]; it != NULL; it = it->next)
            arr[j++] = it->data;

        delete_list(head[i]);
    }
}

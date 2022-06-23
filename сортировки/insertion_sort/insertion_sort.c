#include "insertion_sort.h"
#include "..\list\list.h"
#include <stdlib.h>

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

int find_insert_position(int *arr, int elem, int right_bound)
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

void list_insertion_sort(int *arr, int size)
{
    list_node *head = NULL;

    for (int *it = arr; it != arr + size; it++)
        head = add_order_to_list(head, *it);

    int j = 0;
    for (list_node *it = head; it != NULL; it = it->next)
        arr[j++] = it->data;

    delete_list(head);
}
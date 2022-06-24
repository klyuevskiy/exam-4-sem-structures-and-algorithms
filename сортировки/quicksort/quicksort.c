#include "quicksort.h"
#include <stdlib.h>

#define swap(type, a, b) \
    {                    \
        type t = a;      \
        a = b;           \
        b = t;           \
    }

#define int_swap(a, b) swap(int, a, b)

void quicksort_virt(int *arr, int size)
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

void quicksort_knut(int *arr, int size)
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

void quicksort_without_support_elem(int *arr, int size)
{
    sort_help(arr, 0, size - 1);
}

typedef struct
{
    int left, right;
} stack_node;

typedef struct
{
    stack_node *buffer;
    int elems_count;
} stack;

stack *create_stack(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->elems_count = 0;
    s->buffer = (stack_node *)calloc(size, sizeof(stack_node));

    return s;
}

void add(stack *s, int left, int right)
{
    s->buffer[s->elems_count].left = left;
    s->buffer[(s->elems_count)++].right = right;
}

stack_node pop(stack *s)
{
    return s->buffer[--(s->elems_count)];
}

void delete_stack(stack *s)
{
    free(s->buffer);
    free(s);
}

#include "stdio.h"

void quiksort_iterative_knut(int *arr, int size)
{
    stack *s = create_stack(size);
    add(s, 0, size - 1);

    while (s->elems_count)
    {
        stack_node lr = pop(s);

        printf("%d %d\n", lr.left, lr.right);

        int i = lr.left, j = lr.right, support = arr[lr.left];

        while (i <= j)
        {
            while (arr[i] < support)
                i++;
            while (arr[j] > support)
                j--;

            if (i <= j)
            {
                int_swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (j > lr.left)
            add(s, lr.left, j);
        if (i < lr.right)
            add(s, i, lr.right);
    }

    delete_stack(s);
}
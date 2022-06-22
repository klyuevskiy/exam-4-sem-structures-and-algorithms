#include <stdio.h>
#include <stdlib.h>
#include "index_set.h"

typedef struct
{
    int w, v;
} object;

int n, limw, totv = 0, maxv = 0;

object *items;
index_set *opts,
    *s;

void try(int i, int tw, int av)
{
    if (tw + items[i].w <= limw)
    {
        push(s, i);
        if (i + 1 < n)
            try(i + 1, tw + items[i].w, av);
        else if (av > maxv)
        {
            maxv = av;
            copy(opts, s);
        }
        pop(s);
    }

    int av1 = av - items[i].v;
    if (av1 > maxv)
    {
        if (i + 1 < n)
            try(i + 1, tw, av1);
        else
        {
            maxv = av1;
            copy(opts, s);
        }
    }
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    fscanf(input, "%d %d", &n, &limw);

    items = (object *)calloc(n, sizeof(object));
    opts = create_index_set(n);
    s = create_index_set(n);

    for (object *item = items; item != items + n; item++)
    {
        fscanf(input, "%d %d", &item->w, &item->v);
        totv += item->v;
    }

    try(0, 0, totv);

    for (int i = 0; i < opts->indeces_number; i++)
    {
        printf("%d ", opts->indeces[i]);
    }

    free(items);
    delete_index_set(opts);
    delete_index_set(s);

    return 0;
}
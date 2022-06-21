#include "stdio.h"

#define n 8

// используются, чтобы лучше понимать логику

#define man n
#define woman n
#define rank n

int wmr[man][rank];
int mwr[man][rank];

int rmw[man][woman];
int rwm[woman][man];

int x[man];
int y[woman];

char single[woman];

void read_matrix(FILE *input, int matrix[][n], int ranks[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fscanf(input, "%d", &matrix[i][j]);
            ranks[i][matrix[i][j]] = j;
        }
}

void print()
{
    int rm = 0, rw = 0;

    for (int m = 0; m < n; m++)
    {
        printf("%d ", x[m]);
        rm += rmw[m][x[m]];
        rw += rwm[x[m]][m];
    }

    printf("rm: %d rw: %d\n", rm, rw);
}

char stable(int m, int w, int r)
{
    char res = 1;

    for (int i = 0; i < r && res; i++)
    {
        int pw = wmr[m][i];

        if (!single[pw])
            res = rwm[pw][m] > rwm[pw][y[pw]];
    }

    for (int i = 0; i < rwm[w][m] && res; i++)
    {
        int pm = mwr[w][i];

        if (pm < m)
            res = rmw[pm][w] > rmw[pm][x[pm]];
    }

    return res;
}

void try(int m)
{
    for (int r = 0; r < n; r++)
    {
        int w = wmr[m][r];
        if (single[w] && stable(m, w, r))
        {
            x[m] = w;
            y[w] = m;
            single[w] = 0;

            if (m + 1 < n)
                try(m + 1);
            else
                print();

            single[w] = 1;
        }
    }
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    read_matrix(input, wmr, rmw);
    read_matrix(input, mwr, rwm);

    fclose(input);

    for (int i = 0; i < n; i++)
        single[i] = 1;

    try(0);

    return 0;
}
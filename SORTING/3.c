#include <stdio.h>

void insertionSort(long int *p, long int n)
{
    long int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = p[i];
        j = i - 1;

        while(j >= 0 && p[j] > key)
        {
            p[j + 1] = p[j];
            j--;
        }

        p[j + 1] = key;
    }
}
int main()
{
    long int q;
    scanf("%ld", &q);

    while(q--)
    {
        long int n;
        scanf("%ld", &n);

        long int row[n], col[n];
        long int a[n][n];

        for(long int i = 0; i < n; i++)
        {
            row[i] = 0;

            for(long int j = 0; j < n; j++)
            {
                scanf("%ld", &a[i][j]);
                row[i] += a[i][j];
            }
        }

        for(long int j = 0; j < n; j++)
        {
            col[j] = 0;

            for(long int i = 0; i < n; i++)
            {
                col[j] += a[i][j];
            }
        }

        insertionSort(row, n);
        insertionSort(col, n);

        int possible = 1;

        for(long int i = 0; i < n; i++)
        {
            if(row[i] != col[i])
            {
                possible = 0;
                break;
            }
        }

        if(possible)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
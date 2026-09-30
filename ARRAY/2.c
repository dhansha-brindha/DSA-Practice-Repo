#include <stdio.h>

int main()
{
    int p, q, a[1000][1000];
    int top = 0, bottom, left = 0, right;
    int x = 1, i, j;

    scanf("%d %d", &p, &q);

    bottom = p - 1;
    right = q - 1;

    while(top <= bottom && right >= left)
    {
        for(i = left; i <= right; i++)
            a[top][i] = x;

        for(i = top; i <= bottom; i++)
            a[i][right] = x;

        for(i = right; i >= left; i--)
            a[bottom][i] = x;

        for(i = bottom; i >= top; i--)
            a[i][left] = x;

        top++;
        bottom--;
        left++;
        right--;
        x = 1 - x;
    }

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < q; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("CH.SC.U4CSE25265\n");

    return 0;
}
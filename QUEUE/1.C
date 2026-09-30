#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int biggest = -1;
    int big = -1;
    int third = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > biggest)
        {
            third = big;
            big = biggest;
            biggest = a[i];
        }
        else if (a[i] > big)
        {
            third = big;
            big = a[i];
        }
        else if (a[i] > third)
        {
            third = a[i];
        }
        if (i < 2)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", biggest * big * third);
        }
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int t, n, i, buy;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        buy = -1;
        for(i=0;i<n-1;i++)
        {
            if(arr[i] < arr[i+1])
            {
                if(buy == -1)
                    buy = i;
            }
            else
            {
                if(buy != -1)
                {
                    printf("(%d %d) ",buy,i);
                    buy = -1;
                }
            }
        }
        if(buy != -1)
            printf("(%d %d)",buy,n-1);

        if(buy == -1 && i == n-1)
            printf("No Profit");

        printf("\n");
    }

    printf("CH.SC.U4CSE25265\n");

    return 0;
}
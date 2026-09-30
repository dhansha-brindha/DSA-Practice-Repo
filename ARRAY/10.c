#include <stdio.h>

int main()
{
    int T,n,i,j,a[100],count,sum;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sum=0;

        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
                if(a[j]<=a[i])
                    count++;

            sum+=count;
        }

        printf("%d\n",sum);
    }

    printf("CH.SC.U4CSE25265\n");
    return 0;
}
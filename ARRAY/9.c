#include <stdio.h>

int main()
{
    int r,c,i,j;
    scanf("%d%d",&r,&c);

    int arr[r][c], arrTemp[r][c];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            arrTemp[i][j]=arr[i][j];
        }

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(arr[i][j]==1)
            {
                for(int m=0;m<r;m++)
                    arrTemp[m][j]=1;

                for(int m=0;m<c;m++)
                    arrTemp[i][m]=1;
            }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",arrTemp[i][j]);
        printf("\n");
    }

    printf("CH.SC.U4CSE25265\n");
    return 0;
}
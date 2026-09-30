#include <stdio.h>
void sort(int a[], int n, int flag)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if((flag == 0 && a[j] > a[j + 1]) ||
               (flag == 1 && a[j] < a[j + 1]))
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int A[n], B[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &B[i]);
        sort(A, n, 0);   // ascending
        sort(B, n, 1);   // descending
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += A[i] * B[i];
        printf("%d\n", sum);
    }
    return 0;
}
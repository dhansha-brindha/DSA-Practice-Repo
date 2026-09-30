#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N, K, P;
        scanf("%d %d %d", &N, &K, &P);
        int dp[N + 1][P + 1];
        for(int i = 0; i <= N; i++)
        {
            for(int j = 0; j <= P; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= N; i++)
        {
            int a[K + 1];
            a[0] = 0;
            for(int j = 1; j <= K; j++)
            {
                scanf("%d", &a[j]);
                a[j] += a[j - 1];
            }
            for(int j = 0; j <= P; j++)
            {
                for(int x = 0; x <= K && x <= j; x++)
                {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - x] + a[x]);
                }
            }
        }
        printf("%d\n", dp[N][P]);
    }
    return 0;
}
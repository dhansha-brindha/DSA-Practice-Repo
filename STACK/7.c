#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i < n; i++)
    {
        int f = -1, g = -1;

        // F(i): first greater element
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                f = j;
                break;
            }
        }
        // G(F(i)): first smaller element after F(i)
        if (f != -1)
        {
            for (int j = f + 1; j < n; j++)
            {
                if (a[j] < a[f])
                {
                    g = j;
                    break;
                }
            }
        }
        if (g == -1)
            printf("-1 ");
        else
            printf("%lld ", a[g]);
    }
    return 0;
}
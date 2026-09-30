#include <stdio.h>

int sum(int n)
{
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--)
    {
        int i;
        scanf("%d", &i);
        i--;
        int ans = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (sum(a[j]) > sum(a[i]) && a[j] > a[i])
            {
                ans = j + 1;
                break;
            }
        }
        printf("%d ", ans);
    }
    return 0;
}
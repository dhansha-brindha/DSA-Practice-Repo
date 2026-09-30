#include <stdio.h>

int main()
{
    int n, arr[100000];
    long long ans = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                ans++;
        }
    }

    printf("%lld", ans);

    return 0;
}
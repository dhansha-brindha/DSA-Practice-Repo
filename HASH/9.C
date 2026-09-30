#include <stdio.h>
#include <math.h>

long long divisorCount(int n)
{
    long long count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i)
                count++;
        }
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    long long freq[100] = {0};

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        long long d = divisorCount(x);
        freq[d]++;
    }

    long long answer = 0;

    for (int i = 0; i < 100; i++)
        answer += freq[i] * (freq[i] - 1) / 2;

    printf("%lld\n", answer);

    return 0;
}
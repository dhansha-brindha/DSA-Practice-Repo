#include <stdio.h>
#include <stdlib.h>
#define MAXN 2005
#define HASH 10000007
long long hashTable[HASH];
int exists(long long x)
{
    long long h = x % HASH;
    if (h < 0)
        h += HASH;
    while (hashTable[h] != 0) {
        if (hashTable[h] == x + 1)
            return 1;
        h++;
        if (h == HASH)
            h = 0;
    }
    hashTable[h] = x + 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i; j < n; j++) {
            sum += a[j];

            if (!exists(sum))
                answer += sum;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
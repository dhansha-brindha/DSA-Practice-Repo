#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        long long x = a < b ? a : b;
        long long y = a > b ? a : b;

        double phi = (1.0 + sqrt(5.0)) / 2.0;

        long long k = (long long)(x * phi);

        if (k == x || (long long)(k / phi) != x)
            k = x;

        long long p = (long long)(k * phi);

        if (p == y)
            printf("sami\n");
        else
            printf("canthi\n");
    }

    return 0;
}
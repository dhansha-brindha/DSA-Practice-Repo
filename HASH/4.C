#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int boy[n + 1], girl[n + 1];
        int received[n + 1];

        for (int i = 1; i <= n; i++)
            scanf("%d", &boy[i]);

        for (int i = 1; i <= n; i++)
            scanf("%d", &girl[i]);

        for (int i = 1; i <= n; i++)
            received[i] = 0;

        for (int i = 1; i <= n; i++) {
            int target = girl[boy[i]];

            if (target != i)
                received[target]++;
        }

        int maximum = 0;

        for (int i = 1; i <= n; i++) {
            if (received[i] > maximum)
                maximum = received[i];
        }

        int mutual = 0;

        for (int i = 1; i <= n; i++) {
            int a = girl[boy[i]];

            if (a != i) {
                int b = girl[boy[a]];

                if (b == i)
                    mutual++;
            }
        }

        printf("%d %d\n", maximum, mutual / 2);
    }

    return 0;
}
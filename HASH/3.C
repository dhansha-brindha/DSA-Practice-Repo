#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char name[20];
    int a, b, c;
    int count;
} Festival;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        Festival f[MAX];
        int fc = 0;

        for (int i = 0; i < n; i++) {
            char name[20];
            int x;

            scanf("%s %d", name, &x);

            int pos = -1;

            for (int j = 0; j < fc; j++) {
                if (strcmp(f[j].name, name) == 0) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                pos = fc++;
                strcpy(f[pos].name, name);
                f[pos].a = f[pos].b = f[pos].c = 0;
                f[pos].count = 0;
            }

            f[pos].count++;

            if (x >= f[pos].a) {
                f[pos].c = f[pos].b;
                f[pos].b = f[pos].a;
                f[pos].a = x;
            }
            else if (x >= f[pos].b) {
                f[pos].c = f[pos].b;
                f[pos].b = x;
            }
            else if (x > f[pos].c) {
                f[pos].c = x;
            }
        }

        int best = 0;
        int bestSum = -1;

        for (int i = 0; i < fc; i++) {
            int sum = f[i].a + f[i].b + f[i].c;

            if (sum > bestSum ||
               (sum == bestSum &&
                strcmp(f[i].name, f[best].name) < 0)) {
                bestSum = sum;
                best = i;
            }
        }

        printf("%s %d\n", f[best].name, bestSum);
    }

    return 0;
}
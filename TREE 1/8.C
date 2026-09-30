#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long value;
    int index;
} Employee;

int compare(const void *a, const void *b) {
    Employee *x = (Employee *)a;
    Employee *y = (Employee *)b;

    if (x->value < y->value) return -1;
    if (x->value > y->value) return 1;
    return 0;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    long long salary[n + 1];

    for (int i = 1; i <= n; i++)
        scanf("%lld", &salary[i]);

    while (q--) {
        char type;
        long long a, b;

        scanf(" %c %lld %lld", &type, &a, &b);

        if (type == '!') {
            salary[a] = b;
        } else {
            int count = 0;

            for (int i = 1; i <= n; i++) {
                if (salary[i] >= a && salary[i] <= b)
                    count++;
            }

            printf("%d\n", count);
        }
    }

    return 0;
}
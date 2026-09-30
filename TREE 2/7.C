#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long value;
    int count;
    struct Node *next;
} Node;

int main() {
    int n, q;

    scanf("%d", &n);

    long long *a = malloc((n + 100005) * sizeof(long long));

    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    scanf("%d", &q);

    long long *operations = malloc(q * sizeof(long long));

    for (int i = 0; i < q; i++)
        scanf("%lld", &operations[i]);

    /* Coordinate compression */
    int total = n + q;

    long long *values = malloc(total * sizeof(long long));

    for (int i = 0; i < n; i++)
        values[i] = a[i];

    for (int i = 0; i < q; i++)
        values[n + i] = operations[i];

    int cmp(const void *x, const void *y) {
        long long a = *(long long *)x;
        long long b = *(long long *)y;

        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

    qsort(values, total, sizeof(long long), cmp);

    int m = 0;

    for (int i = 0; i < total; i++) {
        if (i == 0 || values[i] != values[i-1])
            values[m++] = values[i];
    }

    int *cnt = calloc(m, sizeof(int));

    int getIndex(long long x) {
        int l = 0, r = m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (values[mid] == x)
                return mid;

            if (values[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    for (int i = 0; i < n; i++)
        cnt[getIndex(a[i])]++;

    int size = n;

    for (int i = 0; i < q; i++) {
        int id = getIndex(operations[i]);

        /*
           count 0  -> safe
           count 1  -> safe only if it is not already the maximum
           count 2  -> impossible
        */
        int maxId = -1;

        for (int j = m - 1; j >= 0; j--) {
            if (cnt[j] > 0) {
                maxId = j;
                break;
            }
        }

        int accept = 0;

        if (cnt[id] == 0)
            accept = 1;
        else if (cnt[id] == 1 && id != maxId)
            accept = 1;

        if (accept) {
            cnt[id]++;
            size++;
        }

        printf("%d\n", size);
    }

    /* Increasing part */
    for (int i = 0; i < m; i++) {
        if (cnt[i] > 0)
            printf("%lld ", values[i]);
    }

    /* Decreasing part */
    for (int i = m - 1; i >= 0; i--) {
        if (cnt[i] == 2)
            printf("%lld ", values[i]);
    }

    printf("\n");

    free(a);
    free(operations);
    free(values);
    free(cnt);

    return 0;
}
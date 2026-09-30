#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *code = malloc((n - 2) * sizeof(int));
    int *degree = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++)
        degree[i] = 1;

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &code[i]);
        degree[code[i]]++;
    }

    int *heap = malloc(n * sizeof(int));
    int size = 0;

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1)
            heap[size++] = i;
    }

    /* Build min heap */
    for (int i = size / 2 - 1; i >= 0; i--) {
        int x = i;

        while (1) {
            int l = 2 * x + 1;
            int r = 2 * x + 2;
            int smallest = x;

            if (l < size && heap[l] < heap[smallest])
                smallest = l;

            if (r < size && heap[r] < heap[smallest])
                smallest = r;

            if (smallest == x)
                break;

            int temp = heap[x];
            heap[x] = heap[smallest];
            heap[smallest] = temp;

            x = smallest;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int leaf = heap[0];

        printf("%d %d\n", leaf, code[i]);

        degree[leaf]--;
        degree[code[i]]--;

        if (degree[code[i]] == 1) {
            heap[size++] = code[i];

            int x = size - 1;

            while (x > 0) {
                int p = (x - 1) / 2;

                if (heap[p] <= heap[x])
                    break;

                int temp = heap[p];
                heap[p] = heap[x];
                heap[x] = temp;

                x = p;
            }
        }

        heap[0] = heap[--size];

        int x = 0;

        while (1) {
            int l = 2 * x + 1;
            int r = 2 * x + 2;
            int smallest = x;

            if (l < size && heap[l] < heap[smallest])
                smallest = l;

            if (r < size && heap[r] < heap[smallest])
                smallest = r;

            if (smallest == x)
                break;

            int temp = heap[x];
            heap[x] = heap[smallest];
            heap[smallest] = temp;

            x = smallest;
        }
    }

    printf("%d %d\n", heap[0], heap[1]);

    free(code);
    free(degree);
    free(heap);

    return 0;
}
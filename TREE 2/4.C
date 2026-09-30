#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[5005];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int cmp(const void *a, const void *b) {
    Edge *x = (Edge *)a;
    Edge *y = (Edge *)b;

    return y->w - x->w;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        Edge *edges = malloc(m * sizeof(Edge));

        for (int i = 0; i < m; i++)
            scanf("%d %d %d",
                  &edges[i].u,
                  &edges[i].v,
                  &edges[i].w);

        qsort(edges, m, sizeof(Edge), cmp);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        long long answer = 0;
        int used = 0;

        for (int i = 0; i < m && used < n - 1; i++) {
            int a = find(edges[i].u);
            int b = find(edges[i].v);

            if (a != b) {
                parent[a] = b;
                answer += edges[i].w;
                used++;
            }
        }

        printf("%lld\n", answer);

        free(edges);
    }

    return 0;
}
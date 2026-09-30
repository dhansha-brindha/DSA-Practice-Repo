#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int *adj[MAXN];
int deg[MAXN];
int parent[MAXN];

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int getID(int u, int p) {
    int child[MAXN];
    int cnt = 0;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (v != p)
            child[cnt++] = getID(v, u);
    }

    qsort(child, cnt, sizeof(int), cmp);

    int id = 1;
    for (int i = 0; i < cnt; i++)
        id = id * 1000003 + child[i];

    return id;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
            adj[i] = malloc(2 * sizeof(int));
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }

        int id1 = getID(1, 0);

        for (int i = 1; i <= n; i++)
            deg[i] = 0;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }

        int id2 = getID(1, 0);

        printf("%s\n", id1 == id2 ? "YES" : "NO");

        for (int i = 1; i <= n; i++)
            free(adj[i]);
    }

    return 0;
}
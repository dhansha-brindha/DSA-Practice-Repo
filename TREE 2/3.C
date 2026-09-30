#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int adj[MAXN][3];
int deg[MAXN];

int rev[MAXN][3];
int rdeg[MAXN];

int visited[MAXN];
int order[MAXN];
int ord = 0;
int comp[MAXN];

void dfs1(int u) {
    visited[u] = 1;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v])
            dfs1(v);
    }

    order[ord++] = u;
}

void dfs2(int u, int c) {
    comp[u] = c;

    for (int i = 0; i < rdeg[u]; i++) {
        int v = rev[u][i];
        if (comp[v] == 0)
            dfs2(v, c);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *from = malloc(m * sizeof(int));
    int *to = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &from[i], &to[i]);
        adj[from[i]][deg[from[i]]++] = to[i];
        rev[to[i]][rdeg[to[i]]++] = from[i];
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);

    int cc = 0;

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (comp[u] == 0)
            dfs2(u, ++cc);
    }

    if (cc == 1) {
        printf("0\n");
        return 0;
    }

    int *indeg = calloc(cc + 1, sizeof(int));
    int *outdeg = calloc(cc + 1, sizeof(int));
    int *source = malloc(cc * sizeof(int));
    int *sink = malloc(cc * sizeof(int));

    for (int i = 0; i < m; i++) {
        int a = comp[from[i]];
        int b = comp[to[i]];

        if (a != b) {
            outdeg[a]++;
            indeg[b]++;
        }
    }

    int s = 0, t = 0;

    for (int i = 1; i <= cc; i++) {
        if (indeg[i] == 0)
            source[s++] = i;

        if (outdeg[i] == 0)
            sink[t++] = i;
    }

    int k = s > t ? s : t;
    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        int a = sink[i % t];
        int b = source[(i + 1) % s];

        int u = 0, v = 0;

        for (int j = 1; j <= n; j++) {
            if (comp[j] == a) {
                u = j;
                break;
            }
        }

        for (int j = 1; j <= n; j++) {
            if (comp[j] == b) {
                v = j;
                break;
            }
        }

        printf("%d %d\n", u, v);
    }

    return 0;
}
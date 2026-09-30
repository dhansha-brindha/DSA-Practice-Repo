#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int adj[MAXN][2];
int deg[MAXN];

int tin[MAXN], tout[MAXN];
int timer = 0;

char value[MAXN];

int prefix[26][MAXN];

void dfs(int u, int p) {
    tin[u] = ++timer;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];

        if (v != p)
            dfs(v, u);
    }

    tout[u] = timer;
}

int main() {
    int n, q;

    scanf("%d %d", &n, &q);
    scanf("%s", value + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    dfs(1, 0);

    for (int u = 1; u <= n; u++) {
        int pos = tin[u];
        int c = value[u] - 'a';

        prefix[c][pos]++;
    }

    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= n; i++)
            prefix[c][i] += prefix[c][i - 1];
    }

    while (q--) {
        int u;
        char c;

        scanf("%d %c", &u, &c);

        int x = c - 'a';

        printf("%d\n",
            prefix[x][tout[u]] -
            prefix[x][tin[u] - 1]);
    }

    return 0;
}
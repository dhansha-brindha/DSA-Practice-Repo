#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int u, v;
    int cnt;
    int *tok;
} Edge;

int *parent, *sz;

int find(int x)
{
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
}

int connected(int n, int m, Edge *e, int k, int *chosen)
{
    int i, j;
    parent = malloc((n + 1) * sizeof(int));
    sz = malloc((n + 1) * sizeof(int));

    for (i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (i = 0; i < m; i++) {
        int ok = 1;

        for (j = 0; j < e[i].cnt; j++) {
            if (!chosen[e[i].tok[j]]) {
                ok = 0;
                break;
            }
        }

        if (ok)
            unite(e[i].u, e[i].v);
    }

    for (i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            free(parent);
            free(sz);
            return 0;
        }
    }

    free(parent);
    free(sz);
    return 1;
}

int main()
{
    int n, m, k;
    int i, j;

    scanf("%d %d %d", &n, &m, &k);

    ll *cost = malloc((k + 1) * sizeof(ll));
    int *chosen = calloc(k + 1, sizeof(int));

    for (i = 1; i <= k; i++)
        scanf("%lld", &cost[i]);

    Edge *e = malloc(m * sizeof(Edge));

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cnt);

        e[i].tok = malloc(e[i].cnt * sizeof(int));

        for (j = 0; j < e[i].cnt; j++)
            scanf("%d", &e[i].tok[j]);
    }

    /*
       Since every token cost is at least twice the
       previous one, expensive tokens are considered first.
    */

    for (i = k; i >= 1; i--) {
        int possible_without = 1;

        /*
           Temporarily assume all cheaper tokens are available.
        */
        for (j = 1; j < i; j++)
            chosen[j] = 1;

        if (!connected(n, m, e, k, chosen))
            possible_without = 0;

        if (!possible_without)
            chosen[i] = 1;

        for (j = 1; j < i; j++)
            chosen[j] = 0;
    }

    /*
       Check whether the final selected tokens connect
       the complete graph.
    */
    if (!connected(n, m, e, k, chosen)) {
        printf("-1\n");
    } else {
        ll ans = 0;

        for (i = 1; i <= k; i++)
            if (chosen[i])
                ans += cost[i];

        printf("%lld\n", ans);
    }

    for (i = 0; i < m; i++)
        free(e[i].tok);

    free(e);
    free(cost);
    free(chosen);

    return 0;
} 
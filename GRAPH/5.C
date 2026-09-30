#include <stdio.h>

#define MAX 100005

int parent[MAX];
int xr[MAX];
int sz[MAX];

int find(int x)
{
    if (parent[x] == x)
        return x;

    int p = parent[x];

    parent[x] = find(parent[x]);
    xr[x] ^= xr[p];

    return parent[x];
}

int getXor(int x)
{
    find(x);
    return xr[x];
}

int main()
{
    int n, q;

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        xr[i] = 0;
        sz[i] = 1;
    }

    while (q--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        int ru = find(u);
        int xu = xr[u];

        int rv = find(v);
        int xv = xr[v];

        if (ru != rv) {
            parent[rv] = ru;
            xr[rv] = xu ^ xv ^ w;
            sz[ru] += sz[rv];

            printf("YES\n");
        }
        else {
            int cycleXor = xu ^ xv ^ w;

            if (cycleXor == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
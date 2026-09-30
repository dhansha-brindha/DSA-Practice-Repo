#include <stdio.h>

#define MAXN 100005

int p1[MAXN], p2[MAXN];

int find(int p[], int x) {
    if (p[x] == x)
        return x;

    return p[x] = find(p, p[x]);
}

int main() {
    int n, m1, m2;

    scanf("%d %d %d", &n, &m1, &m2);

    for (int i = 1; i <= n; i++) {
        p1[i] = i;
        p2[i] = i;
    }

    for (int i = 0; i < m1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int a = find(p1, u);
        int b = find(p1, v);

        p1[a] = b;
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int a = find(p2, u);
        int b = find(p2, v);

        p2[a] = b;
    }

    int ans = 0;
    int eu[MAXN], ev[MAXN];

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {

            if (find(p1, u) != find(p1, v) &&
                find(p2, u) != find(p2, v)) {

                p1[find(p1, u)] = find(p1, v);
                p2[find(p2, u)] = find(p2, v);

                eu[ans] = u;
                ev[ans] = v;
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < ans; i++)
        printf("%d %d\n", eu[i], ev[i]);

    return 0;
}
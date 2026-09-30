#include <stdio.h>

#define MAX 100005

int parent[MAX];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        unite(a, b);
    }

    int roots[MAX];
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i)
            roots[cnt++] = i;
    }

    printf("%d\n", cnt - 1);

    for (int i = 1; i < cnt; i++)
        printf("%d %d\n", roots[0], roots[i]);

    return 0;
}
#include <stdio.h>

#define MAX 100005

int parent[MAX];
int size[MAX];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void join(int i, int j)
{
    i = find(i);
    j = find(j);

    if (i == j)
        return;

    if (size[i] < size[j]) {
        int t = i;
        i = j;
        j = t;
    }

    parent[j] = i;
    size[i] += size[j];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int components = n;
    int largest = 1;

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ra = find(a);
        int rb = find(b);

        if (ra != rb) {
            join(ra, rb);
            components--;

            ra = find(a);

            if (size[ra] > largest)
                largest = size[ra];
        }

        printf("%d %d\n", components, largest);
    }

    return 0;
}
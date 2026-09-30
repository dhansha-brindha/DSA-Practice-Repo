#include <stdio.h>

#define MAX 1000005

int tree[4 * MAX];

void update(int node, int l, int r, int pos)
{
    if (l == r) {
        tree[node] = 1;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(node * 2, l, mid, pos);
    else
        update(node * 2 + 1, mid + 1, r, pos);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int y)
{
    if (r < y || tree[node] == 0)
        return -1;

    if (l == r)
        return l;

    int mid = (l + r) / 2;

    int left = query(node * 2, l, mid, y);

    if (left != -1)
        return left;

    return query(node * 2 + 1, mid + 1, r, y);
}

int main()
{
    int n, q;

    scanf("%d %d", &n, &q);

    while (q--) {
        int type, x;

        scanf("%d %d", &type, &x);

        if (type == 1) {
            update(1, 1, n, x);
        }
        else {
            printf("%d\n", query(1, 1, n, x));
        }
    }

    return 0;
}
#include <stdio.h>

#define INF 1000000000

int tree[400005];
int a[100005];

void build(int *aa, int k, int l, int r) {
    if (l == r) {
        tree[k] = aa[l];
        return;
    }

    int mid = (l + r) / 2;

    build(aa, 2*k, l, mid);
    build(aa, 2*k+1, mid+1, r);

    tree[k] = tree[2*k] < tree[2*k+1]
              ? tree[2*k]
              : tree[2*k+1];
}

int query(int k, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return INF;

    if (ql <= l && r <= qr)
        return tree[k];

    int mid = (l + r) / 2;

    int left = query(2*k, l, mid, ql, qr);
    int right = query(2*k+1, mid+1, r, ql, qr);

    return left < right ? left : right;
}

int main() {
    int n, q;

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    build(a, 1, 1, n);

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", query(1, 1, n, l, r));
    }

    return 0;
}
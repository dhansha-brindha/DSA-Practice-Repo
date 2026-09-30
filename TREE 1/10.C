#include <stdio.h>

#define MAXN 200005

int tree[4 * MAXN];
int a[MAXN];

void build(int k, int l, int r) {
    if (l == r) {
        tree[k] = 1;
        return;
    }

    int mid = (l + r) / 2;

    build(2*k, l, mid);
    build(2*k+1, mid+1, r);

    tree[k] = tree[2*k] + tree[2*k+1];
}

int removeElement(int k, int l, int r, int pos) {
    if (l == r) {
        tree[k] = 0;
        return a[l];
    }

    int mid = (l + r) / 2;
    int ans;

    if (tree[2*k] >= pos)
        ans = removeElement(2*k, l, mid, pos);
    else
        ans = removeElement(2*k+1, mid+1, r,
                            pos - tree[2*k]);

    tree[k] = tree[2*k] + tree[2*k+1];

    return ans;
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int p[n + 1];

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        int ans = removeElement(1, 1, n, p[i]);
        printf("%d ", ans);
    }

    return 0;
}
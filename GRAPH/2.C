#include <stdio.h>
#include <stdlib.h>

int n, m;
int wish[100005][2];
int ans[100005];
int found = 0;

int check()
{
    int i;

    for (i = 0; i < n; i++) {
        int a = wish[i][0];
        int b = wish[i][1];

        int va = (a > 0) ? ans[a] : !ans[-a];
        int vb = (b > 0) ? ans[b] : !ans[-b];

        if (!va && !vb)
            return 0;
    }

    return 1;
}

void solve(int pos)
{
    if (found)
        return;

    if (pos > m) {
        if (check())
            found = 1;
        return;
    }

    ans[pos] = 0;
    solve(pos + 1);

    if (found)
        return;

    ans[pos] = 1;
    solve(pos + 1);
}

int main()
{
    int i;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        char s1, s2;
        int x, y;

        scanf(" %c%d %c%d", &s1, &x, &s2, &y);

        wish[i][0] = (s1 == '+') ? x : -x;
        wish[i][1] = (s2 == '+') ? y : -y;
    }

    solve(1);

    if (!found) {
        printf("IMPOSSIBLE\n");
    } else {
        for (i = 1; i <= m; i++) {
            if (ans[i])
                printf("+");
            else
                printf("-");
        }
        printf("\n");
    }

    return 0;
}
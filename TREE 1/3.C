#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        char s[n + 1];
        scanf("%s", s + 1);

        for (int j = 1; j <= n; j++) {
            a[i][j] = (s[j] == '*');
        }
    }

    int prefix[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        prefix[i][0] = 0;

    for (int j = 0; j <= n; j++)
        prefix[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] =
                a[i][j]
                + prefix[i-1][j]
                + prefix[i][j-1]
                - prefix[i-1][j-1];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int ans = prefix[y2][x2]
                - prefix[y1-1][x2]
                - prefix[y2][x1-1]
                + prefix[y1-1][x1-1];

        printf("%d\n", ans);
    }

    return 0;
}
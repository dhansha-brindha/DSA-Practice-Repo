#include <stdio.h>

#define MAX 100005

int head[MAX], to[2 * MAX], next[2 * MAX];
int edgeCount;

int dp[MAX][2];

void link(int i, int j)
{
    to[edgeCount] = j;
    next[edgeCount] = head[i];
    head[i] = edgeCount++;
}

void dfs(int u, int parent)
{
    dp[u][0] = 0;
    dp[u][1] = 0;

    for (int e = head[u]; e != -1; e = next[e]) {
        int v = to[e];

        if (v == parent)
            continue;

        dfs(v, u);

        dp[u][0] += dp[v][0] > dp[v][1]
                    ? dp[v][0] : dp[v][1];
    }

    for (int e = head[u]; e != -1; e = next[e]) {
        int v = to[e];

        if (v == parent)
            continue;

        int value = 1 + dp[v][0];

        for (int f = head[u]; f != -1; f = next[f]) {
            int w = to[f];

            if (w == parent || w == v)
                continue;

            value += dp[w][0] > dp[w][1]
                     ? dp[w][0] : dp[w][1];
        }

        if (value > dp[u][1])
            dp[u][1] = value;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        link(a, b);
        link(b, a);
    }

    dfs(1, 0);

    printf("%d\n",
           dp[1][0] > dp[1][1]
           ? dp[1][0] : dp[1][1]);

    return 0;
}
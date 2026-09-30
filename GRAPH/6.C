#include <stdio.h>
#include <string.h>

#define MAX 505

int n, m, k;
int graph[MAX][MAX];
int match[MAX];
int visited[MAX];

int dfs(int boy)
{
    for (int girl = 1; girl <= m; girl++) {
        if (graph[boy][girl] && !visited[girl]) {
            visited[girl] = 1;

            if (match[girl] == 0 || dfs(match[girl])) {
                match[girl] = boy;
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    while (k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));

        if (dfs(i))
            ans++;
    }

    printf("%d\n", ans);

    for (int girl = 1; girl <= m; girl++) {
        if (match[girl])
            printf("%d %d\n", match[girl], girl);
    }

    return 0;
}
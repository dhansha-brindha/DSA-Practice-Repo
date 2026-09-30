#include <stdio.h>
#include <string.h>

#define MAX 505

int cap[MAX][MAX];
int parent[MAX];
int n, m;

int bfs(int s, int t)
{
    int q[MAX], front = 0, rear = 0;
    int vis[MAX] = {0};

    q[rear++] = s;
    vis[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = q[front++];

        for (int v = 1; v <= n; v++) {
            if (!vis[v] && cap[u][v] > 0) {
                vis[v] = 1;
                parent[v] = u;
                q[rear++] = v;

                if (v == t)
                    return 1;
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;

    while (bfs(s, t)) {
        int v = t;

        while (v != s) {
            int u = parent[v];
            cap[u][v]--;
            cap[v][u]++;
            v = u;
        }

        flow++;
    }

    return flow;
}

void printPaths(int s, int t, int flow)
{
    int used[MAX][MAX] = {0};

    for (int k = 0; k < flow; k++) {
        int path[MAX], len = 0;
        int cur = s;

        path[len++] = cur;

        while (cur != t) {
            int found = 0;

            for (int v = 1; v <= n; v++) {
                if (!used[cur][v] && cap[v][cur] > 0) {
                    used[cur][v] = 1;
                    cur = v;
                    path[len++] = cur;
                    found = 1;
                    break;
                }
            }

            if (!found)
                break;
        }

        printf("%d\n", len);

        for (int i = 0; i < len; i++)
            printf("%d%c", path[i], i + 1 == len ? '\n' : ' ');
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cap[a][b] = 1;
    }

    int flow = maxflow(1, n);

    printf("%d\n", flow);

    if (flow > 0)
        printPaths(1, n, flow);

    return 0;
}
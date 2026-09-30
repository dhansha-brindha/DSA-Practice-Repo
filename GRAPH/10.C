#include <stdio.h>

#define MAX 505

int cap[MAX][MAX];
int parent[MAX];
int n, m;

int bfs(int s, int t)
{
    int q[MAX];
    int front = 0, rear = 0;
    int visited[MAX] = {0};

    q[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = q[front++];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cap[u][v] > 0) {
                visited[v] = 1;
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

void markReachable(int s, int visited[])
{
    int q[MAX];
    int front = 0, rear = 0;

    q[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int u = q[front++];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cap[u][v] > 0) {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int edges[MAX][2];

    for (int i = 0; i < m; i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        edges[i][0] = a;
        edges[i][1] = b;

        cap[a][b]++;
        cap[b][a]++;
    }

    int flow = maxflow(1, n);

    int visited[MAX] = {0};
    markReachable(1, visited);

    printf("%d\n", flow);

    for (int i = 0; i < m; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        if (visited[a] && !visited[b])
            printf("%d %d\n", a, b);
        else if (visited[b] && !visited[a])
            printf("%d %d\n", a, b);
    }

    return 0;
}
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

void printPath(int s, int t)
{
    int path[MAX];
    int len = 0;
    int cur = s;

    path[len++] = cur;

    while (cur != t) {
        for (int v = 1; v <= n; v++) {
            if (cap[v][cur] > 0) {
                cap[v][cur]--;
                cur = v;
                path[len++] = cur;
                break;
            }
        }
    }

    printf("%d\n", len);

    for (int i = 0; i < len; i++)
        printf("%d%c", path[i],
               i == len - 1 ? '\n' : ' ');
}

int main()
{
    scanf("%d %d", &n, &m);

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        cap[a][b] = 1;
    }

    int flow = maxflow(1, n);

    printf("%d\n", flow);

    for (int i = 0; i < flow; i++)
        printPath(1, n);

    return 0;
}
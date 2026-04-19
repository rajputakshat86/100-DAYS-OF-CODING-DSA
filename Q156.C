#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timer = 0;

int *adj[MAX];
int size[MAX];

void dfs(int node, int parent, int *vis, int *tin, int *low, int *mark, int V)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;

    for (int i = 0; i < size[node]; i++)
    {
        int v = adj[node][i];

        if (v == parent)
            continue;

        if (!vis[v])
        {
            dfs(v, node, vis, tin, low, mark, V);

            if (low[v] < low[node])
                low[node] = low[v];

            if (low[v] >= tin[node] && parent != -1)
                mark[node] = 1;

            child++;
        }
        else
        {
            if (tin[v] < low[node])
                low[node] = tin[v];
        }
    }

    if (parent == -1 && child > 1)
        mark[node] = 1;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
    {
        adj[i] = (int *)malloc(V * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int vis[MAX] = {0};
    int tin[MAX] = {0};
    int low[MAX] = {0};
    int mark[MAX] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, mark, V);
        }
    }

    int found = 0;
    for (int i = 0; i < V; i++)
    {
        if (mark[i])
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    return 0;
}
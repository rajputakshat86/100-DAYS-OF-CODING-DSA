#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int **adj, int *size, int *vis)
{
    vis[node] = 1;

    for (int i = 0; i < size[node]; i++)
    {
        int nei = adj[node][i];
        if (!vis[nei])
        {
            dfs(nei, adj, size, vis);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int *size = (int *)calloc(n, sizeof(int));
    int *u = (int *)malloc(m * sizeof(int));
    int *v = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u[i], &v[i]);
        u[i]--;
        v[i]--;
        size[u[i]]++;
        size[v[i]]++;
    }

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(size[i] * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        adj[u[i]][size[u[i]]++] = v[i];
        adj[v[i]][size[v[i]]++] = u[i];
    }

    int *vis = (int *)calloc(n, sizeof(int));
    int components = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, size, vis);
            components++;
        }
    }

    printf("%d\n", components);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(size);
    free(u);
    free(v);
    free(vis);

    return 0;
}
#include <stdio.h>

#define MAX 100005

int adj[MAX][100];
int size[MAX];
int visited[MAX];

void addEdge(int u, int v)
{
    adj[u][size[u]++] = v;
    adj[v][size[v]++] = u;
}

int dfs(int node, int parent)
{
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++)
    {
        int neighbor = adj[node][i];

        if (!visited[neighbor])
        {
            if (dfs(neighbor, node))
                return 1;
        }
        else if (neighbor != parent)
        {
            return 1;
        }
    }
    return 0;
}

int hasCycle(int V)
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
    {
        size[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (hasCycle(V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
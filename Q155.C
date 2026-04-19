#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n)
{
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int n, int graph[MAX][MAX])
{
    int key[MAX];
    int visited[MAX];
    int parent[MAX];
    int total_weight = 0;

    for (int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int count = 1; count <= n; count++)
    {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total_weight += key[u];

        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    return total_weight;
}

int main()
{
    int n, m;
    int graph[MAX][MAX] = {0};

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST(n, graph);
    printf("%d\n", result);

    return 0;
}
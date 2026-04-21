#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int findTheCity(int n, int **edges, int edgesSize, int distanceThreshold)
{
    int dist[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int result = -1;
    int minReach = INF;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold)
                count++;
        }
        count--;

        if (count <= minReach)
        {
            minReach = count;
            result = i;
        }
    }

    return result;
}

int main()
{
    int n, m, distanceThreshold;
    scanf("%d %d", &n, &m);

    int **edges = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        edges[i] = (int *)malloc(3 * sizeof(int));
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    scanf("%d", &distanceThreshold);

    int result = findTheCity(n, edges, m, distanceThreshold);

    printf("%d\n", result);

    for (int i = 0; i < m; i++)
    {
        free(edges[i]);
    }
    free(edges);

    return 0;
}
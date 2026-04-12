#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minCostConnectPoints(int points[][2], int n)
{
    int minDist[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
            {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v])
                {
                    minDist[v] = dist;
                }
            }
        }
    }

    return totalCost;
}

int main()
{
    int n;
    scanf("%d", &n);

    int points[n][2];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);
    printf("%d\n", result);

    return 0;
}
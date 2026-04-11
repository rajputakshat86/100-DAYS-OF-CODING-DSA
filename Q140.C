#include <stdio.h>
#include <limits.h>

#define MAX 105

int findCheapestPrice(int n, int flights[][3], int m, int src, int dst, int k)
{
    int dist[MAX], temp[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++)
        {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v])
                temp[v] = dist[u] + w;
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INT_MAX)
        return -1;

    return dist[dst];
}

int main()
{
    int n = 4;
    int flights[][3] = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}};

    int m = 5;
    int src = 0, dst = 3, k = 1;

    int ans = findCheapestPrice(n, flights, m, src, dst, k);

    printf("%d\n", ans);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        int count;
        scanf("%d", &count);
        for (int j = 0; j < count; j++)
        {
            int neighbor;
            scanf("%d", &neighbor);
            adj[i][neighbor] = 1;
        }
    }

    scanf("%d", &s);
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s);
    return 0;
}
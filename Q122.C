#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int **isConnected, int *visited, int city)
{
    visited[city] = 1;
    for (int i = 0; i < n; i++)
    {
        if (isConnected[city][i] == 1 && !visited[i])
        {
            dfs(n, isConnected, visited, i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int **isConnected = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        isConnected[i] = (int *)malloc(n * sizeof(int));
    }
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &isConnected[i][j]);
        }
    }
    int provinces = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(n, isConnected, visited, i);
            provinces++;
        }
    }
    printf("%d\n", provinces);
    for (int i = 0; i < n; i++)
        free(isConnected[i]);
    free(isConnected);
    free(visited);
    return 0;
}
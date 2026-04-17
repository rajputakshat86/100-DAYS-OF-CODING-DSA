#include <stdio.h>

#define MAX 200

void dfs(int isConnected[MAX][MAX], int visited[], int n, int city)
{
    visited[city] = 1;

    for (int i = 0; i < n; i++)
    {
        if (isConnected[city][i] == 1 && !visited[i])
        {
            dfs(isConnected, visited, n, i);
        }
    }
}

int findCircleNum(int isConnected[MAX][MAX], int n)
{
    int visited[MAX] = {0};
    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(isConnected, visited, n, i);
            provinces++;
        }
    }

    return provinces;
}

int main()
{
    int n = 3;
    int isConnected[MAX][MAX] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    int result = findCircleNum(isConnected, n);
    printf("Number of provinces: %d\n", result);

    return 0;
}
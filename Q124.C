#include <stdio.h>
#include <stdlib.h>

void dfs(int **rooms, int *size, int *visited, int room)
{
    visited[room] = 1;

    for (int i = 0; i < size[room]; i++)
    {
        int key = rooms[room][i];
        if (!visited[key])
        {
            dfs(rooms, size, visited, key);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int **rooms = (int **)malloc(n * sizeof(int *));
    int *size = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &size[i]);
        rooms[i] = (int *)malloc(size[i] * sizeof(int));

        for (int j = 0; j < size[i]; j++)
        {
            scanf("%d", &rooms[i][j]);
        }
    }

    dfs(rooms, size, visited, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("false");
            return 0;
        }
    }

    printf("true");

    for (int i = 0; i < n; i++)
        free(rooms[i]);
    free(rooms);
    free(size);
    free(visited);

    return 0;
}
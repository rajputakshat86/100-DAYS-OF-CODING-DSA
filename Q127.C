#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX];

int main()
{
    int n, s;
    int front = 0, rear = 0;

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
            int x;
            scanf("%d", &x);
            adj[i][x] = 1;
        }
    }

    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}
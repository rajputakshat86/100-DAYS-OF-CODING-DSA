#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBipartite(int **graph, int graphSize, int *graphColSize)
{
    int *color = (int *)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    int *queue = (int *)malloc(graphSize * sizeof(int));

    for (int i = 0; i < graphSize; i++)
    {
        if (color[i] == -1)
        {
            int front = 0, rear = 0;
            queue[rear++] = i;
            color[i] = 0;

            while (front < rear)
            {
                int node = queue[front++];

                for (int j = 0; j < graphColSize[node]; j++)
                {
                    int neighbor = graph[node][j];

                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[node];
                        queue[rear++] = neighbor;
                    }
                    else if (color[neighbor] == color[node])
                    {
                        free(color);
                        free(queue);
                        return false;
                    }
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}

int main()
{
    int n = 4;

    int *graphColSize = (int *)malloc(n * sizeof(int));
    graphColSize[0] = 3;
    graphColSize[1] = 2;
    graphColSize[2] = 3;
    graphColSize[3] = 2;

    int **graph = (int **)malloc(n * sizeof(int *));

    graph[0] = (int *)malloc(3 * sizeof(int));
    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[0][2] = 3;

    graph[1] = (int *)malloc(2 * sizeof(int));
    graph[1][0] = 0;
    graph[1][1] = 2;

    graph[2] = (int *)malloc(3 * sizeof(int));
    graph[2][0] = 0;
    graph[2][1] = 1;
    graph[2][2] = 3;

    graph[3] = (int *)malloc(2 * sizeof(int));
    graph[3][0] = 0;
    graph[3][1] = 2;

    if (isBipartite(graph, n, graphColSize))
        printf("true\n");
    else
        printf("false\n");

    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    free(graphColSize);

    return 0;
}
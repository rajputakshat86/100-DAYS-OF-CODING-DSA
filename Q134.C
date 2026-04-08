#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *adj[2000];
int visited[2000];
int stack[2000];
int top = -1;

struct Node *createNode(int v)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

void addEdge(int u, int v)
{
    struct Node *n = createNode(v);
    n->next = adj[u];
    adj[u] = n;
}

int dfs(int v)
{
    if (visited[v] == 1)
        return 1;
    if (visited[v] == 2)
        return 0;

    visited[v] = 1;

    struct Node *temp = adj[v];
    while (temp)
    {
        if (dfs(temp->data))
            return 1;
        temp = temp->next;
    }

    visited[v] = 2;
    stack[++top] = v;
    return 0;
}

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    for (int i = 0; i < numCourses; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(b, a);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (dfs(i))
        {
            *returnSize = 0;
            return NULL;
        }
    }

    int *result = (int *)malloc(numCourses * sizeof(int));
    int idx = 0;

    while (top != -1)
        result[idx++] = stack[top--];

    *returnSize = numCourses;
    return result;
}
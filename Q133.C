#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *adj[100];
int visited[100];
int stack[100];
int top = -1;

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v)
{
    visited[v] = 1;
    struct Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->data])
            dfs(temp->data);
        temp = temp->next;
    }
    stack[++top] = v;
}

void topoSort(int V)
{
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    while (top != -1)
        printf("%d ", stack[top--]);
}

int main()
{
    int V = 6;

    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topoSort(V);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *adj[MAX];
Node *adjT[MAX];
int vis[MAX];
int stack[MAX];
int top = -1;

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *graph[], int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs1(int v)
{
    vis[v] = 1;
    Node *temp = adj[v];
    while (temp)
    {
        if (!vis[temp->data])
            dfs1(temp->data);
        temp = temp->next;
    }
    stack[++top] = v;
}

void dfs2(int v)
{
    vis[v] = 1;
    Node *temp = adjT[v];
    while (temp)
    {
        if (!vis[temp->data])
            dfs2(temp->data);
        temp = temp->next;
    }
}

int kosaraju(int V)
{
    for (int i = 0; i < V; i++)
        vis[i] = 0;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    for (int i = 0; i < V; i++)
        vis[i] = 0;

    int scc = 0;

    while (top != -1)
    {
        int v = stack[top--];
        if (!vis[v])
        {
            dfs2(v);
            scc++;
        }
    }

    return scc;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
        adjT[i] = NULL;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adjT, v, u);
    }

    printf("%d", kosaraju(V));

    return 0;
}
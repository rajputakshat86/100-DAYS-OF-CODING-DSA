#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int V;
    struct Node **adjList;
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

bool isCyclicUtil(struct Graph *graph, int v, bool visited[], bool recStack[])
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        struct Node *temp = graph->adjList[v];
        while (temp)
        {
            int neighbor = temp->vertex;
            if (!visited[neighbor] && isCyclicUtil(graph, neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(struct Graph *graph)
{
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    bool *recStack = (bool *)malloc(graph->V * sizeof(bool));

    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->V; i++)
        if (!visited[i] && isCyclicUtil(graph, i, visited, recStack))
            return true;

    return false;
}

int main()
{
    int V = 4;
    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // Creates a cycle

    if (isCyclic(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
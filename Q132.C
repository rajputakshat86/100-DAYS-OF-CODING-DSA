#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int course;
    struct Node *next;
};

struct Graph
{
    int numCourses;
    struct Node **adjList;
};

struct Node *createNode(int course)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numCourses)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numCourses = numCourses;
    graph->adjList = (struct Node **)malloc(numCourses * sizeof(struct Node *));
    for (int i = 0; i < numCourses; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

bool dfs(struct Graph *graph, int course, bool visited[], bool recStack[])
{
    if (!visited[course])
    {
        visited[course] = true;
        recStack[course] = true;

        struct Node *temp = graph->adjList[course];
        while (temp)
        {
            int neighbor = temp->course;
            if (!visited[neighbor] && dfs(graph, neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
            temp = temp->next;
        }
    }
    recStack[course] = false;
    return false;
}

bool canFinish(int numCourses, int prerequisites[][2], int prerequisitesSize)
{
    struct Graph *graph = createGraph(numCourses);

    // Build the graph
    for (int i = 0; i < prerequisitesSize; i++)
    {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        addEdge(graph, pre, course); // pre → course
    }

    bool *visited = (bool *)malloc(numCourses * sizeof(bool));
    bool *recStack = (bool *)malloc(numCourses * sizeof(bool));
    for (int i = 0; i < numCourses; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (dfs(graph, i, visited, recStack))
                return false; // cycle detected
        }
    }

    return true;
}

int main()
{
    int numCourses = 2;
    int prerequisites[][2] = {{1, 0}};
    int prerequisitesSize = sizeof(prerequisites) / sizeof(prerequisites[0]);

    if (canFinish(numCourses, prerequisites, prerequisitesSize))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
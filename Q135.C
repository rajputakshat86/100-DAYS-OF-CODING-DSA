#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node **adj;

struct Node *newNode(int v)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void addEdge(int u, int v)
{
    struct Node *n = newNode(v);
    n->next = adj[u];
    adj[u] = n;
}

int *kahnTopoSort(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    adj = (struct Node **)malloc(numCourses * sizeof(struct Node *));
    for (int i = 0; i < numCourses; i++)
        adj[i] = NULL;

    int *inDegree = (int *)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++)
        inDegree[i] = 0;

    for (int i = 0; i < prerequisitesSize; i++)
    {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        addEdge(u, v);
        inDegree[v]++;
    }

    int *queue = (int *)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }

    int *topo = (int *)malloc(numCourses * sizeof(int));
    int idx = 0;

    while (front < rear)
    {
        int u = queue[front++];
        topo[idx++] = u;

        struct Node *temp = adj[u];
        while (temp)
        {
            int v = temp->val;
            inDegree[v]--;
            if (inDegree[v] == 0)
                queue[rear++] = v;
            temp = temp->next;
        }
    }

    if (idx != numCourses)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numCourses;
    return topo;
}

int main()
{
    int numCourses = 4;
    int prereqData[4][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int *prerequisites[4];
    for (int i = 0; i < 4; i++)
        prerequisites[i] = prereqData[i];

    int returnSize;
    int *result = kahnTopoSort(numCourses, prerequisites, 4, NULL, &returnSize);

    if (returnSize == 0)
    {
        printf("No valid order (cycle detected)\n");
    }
    else
    {
        printf("Course order: ");
        for (int i = 0; i < returnSize; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}
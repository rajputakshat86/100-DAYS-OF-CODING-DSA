#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node **adj;
int *state;
int *stack;
int top;

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

int dfs(int v)
{
    if (state[v] == 1)
        return 1;
    if (state[v] == 2)
        return 0;

    state[v] = 1;

    struct Node *temp = adj[v];
    while (temp)
    {
        if (dfs(temp->val))
            return 1;
        temp = temp->next;
    }

    state[v] = 2;
    stack[top++] = v;
    return 0;
}

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    adj = (struct Node **)malloc(numCourses * sizeof(struct Node *));
    state = (int *)malloc(numCourses * sizeof(int));
    stack = (int *)malloc(numCourses * sizeof(int));

    for (int i = 0; i < numCourses; i++)
    {
        adj[i] = NULL;
        state[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++)
    {
        addEdge(prerequisites[i][1], prerequisites[i][0]);
    }

    top = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (state[i] == 0 && dfs(i))
        {
            *returnSize = 0;
            return NULL;
        }
    }

    int *ans = (int *)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++)
    {
        ans[i] = stack[numCourses - i - 1];
    }

    *returnSize = numCourses;
    return ans;
}

int main()
{
    int numCourses = 4;

    int prereqData[4][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int *prerequisites[4];
    for (int i = 0; i < 4; i++)
    {
        prerequisites[i] = prereqData[i];
    }

    int returnSize;
    int *result = findOrder(numCourses, prerequisites, 4, NULL, &returnSize);

    if (returnSize == 0)
    {
        printf("No valid order\n");
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
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

struct Node *visited[MAX];

struct Node *createNode(int val, int deg)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = deg;
    node->neighbors = (struct Node **)malloc(deg * sizeof(struct Node *));
    return node;
}

struct Node *cloneGraph(struct Node *node)
{
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node *copy = createNode(node->val, node->numNeighbors);

    visited[node->val] = copy;

    for (int i = 0; i < node->numNeighbors; i++)
    {
        copy->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return copy;
}

int main()
{
    for (int i = 0; i < MAX; i++)
        visited[i] = NULL;

    struct Node *n1 = createNode(1, 2);
    struct Node *n2 = createNode(2, 2);
    struct Node *n3 = createNode(3, 2);
    struct Node *n4 = createNode(4, 2);

    n1->neighbors[0] = n2;
    n1->neighbors[1] = n4;

    n2->neighbors[0] = n1;
    n2->neighbors[1] = n3;

    n3->neighbors[0] = n2;
    n3->neighbors[1] = n4;

    n4->neighbors[0] = n1;
    n4->neighbors[1] = n3;

    struct Node *cloned = cloneGraph(n1);

    printf("Graph cloned successfully. Root value: %d\n", cloned->val);

    return 0;
}
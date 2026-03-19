#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *buildTree(int nodes[], int n)
{
    if (n == 0 || nodes[0] == -1)
        return NULL;
    struct Node *root = createNode(nodes[0]);
    struct Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n)
    {
        struct Node *current = queue[front++];
        if (nodes[i] != -1)
        {
            current->left = createNode(nodes[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && nodes[i] != -1)
        {
            current->right = createNode(nodes[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int nodes[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nodes[i]);
    struct Node *root = buildTree(nodes, n);
    printf("%d\n", height(root));
    return 0;
}
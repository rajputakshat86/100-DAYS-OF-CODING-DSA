#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int front = 0, rear = 0;

    struct Node *root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n)
    {
        struct Node *curr = queue[front++];

        if (arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

struct Node *LCA(struct Node *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node *left = LCA(root->left, p, q);
    struct Node *right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main()
{
    int n, p, q;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &p, &q);

    struct Node *root = buildTree(arr, n);
    struct Node *res = LCA(root, p, q);

    if (res != NULL)
        printf("%d", res->data);

    return 0;
}
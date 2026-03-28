#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode *root = newNode(arr[0]);

    struct TreeNode **queue = (struct TreeNode **)malloc(n * sizeof(struct TreeNode *));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n)
    {
        struct TreeNode *curr = queue[front++];

        if (i < n && arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int isMirror(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
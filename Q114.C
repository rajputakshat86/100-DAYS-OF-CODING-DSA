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
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *build(int arr[], int n, int i)
{
    if (i >= n || arr[i] == -1)
        return NULL;

    struct TreeNode *root = newNode(arr[i]);
    root->left = build(arr, n, 2 * i + 1);
    root->right = build(arr, n, 2 * i + 2);
    return root;
}

void flatten(struct TreeNode *root)
{
    if (!root)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;

    root->left = NULL;
    root->right = left;

    struct TreeNode *temp = root;
    while (temp->right)
        temp = temp->right;

    temp->right = right;
}

void printList(struct TreeNode *root)
{
    while (root)
    {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = build(arr, n, 0);

    flatten(root);

    printList(root);

    return 0;
}
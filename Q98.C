#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }

    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    int n, val, x;
    struct TreeNode *root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insertIntoBST(root, x);
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    root = insertIntoBST(root, val);

    printf("Inorder traversal after insertion: ");
    inorder(root);

    return 0;
}
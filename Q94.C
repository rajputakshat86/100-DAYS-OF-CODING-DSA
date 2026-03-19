#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("%d\n", maxDepth(root));
    return 0;
}
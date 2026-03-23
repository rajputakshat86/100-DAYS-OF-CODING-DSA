#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct TreeNode *LCA(struct TreeNode *root, int p, int q)
{
    while (root != NULL)
    {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main()
{
    int n, val, p, q;
    struct TreeNode *root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    struct TreeNode *res = LCA(root, p, q);

    if (res != NULL)
        printf("%d", res->val);

    return 0;
}
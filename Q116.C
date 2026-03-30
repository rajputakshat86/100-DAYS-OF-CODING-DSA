#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int preIndex = 0;

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == val)
            return i;
    return -1;
}

struct TreeNode *build(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct TreeNode *root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    root->left = build(preorder, inorder, start, inIndex - 1);
    root->right = build(preorder, inorder, inIndex + 1, end);

    return root;
}

void levelOrder(struct TreeNode *root)
{
    struct TreeNode *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct TreeNode *curr = queue[front++];
        if (curr)
        {
            printf("%d ", curr->val);
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
        else
        {
            printf("null ");
        }
    }
}

int main()
{
    int n = 5;
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    struct TreeNode *root = build(preorder, inorder, 0, n - 1);

    levelOrder(root);

    return 0;
}
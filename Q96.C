#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int sumOfLeftLeaves(struct Node *root, int isLeft)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL && isLeft)
        return root->data;
    return sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right, 0);
}

int main()
{
    struct Node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int sum = sumOfLeftLeaves(root, 0);
    printf("%d\n", sum);

    return 0;
}
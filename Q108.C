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
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void zigzagTraversal(struct TreeNode *root)
{
    if (!root)
        return;

    struct TreeNode *queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear)
    {
        int size = rear - front;
        int level[size];

        for (int i = 0; i < size; i++)
        {
            struct TreeNode *node = queue[front++];

            int index = leftToRight ? i : (size - i - 1);
            level[index] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        printf("[");
        for (int i = 0; i < size; i++)
        {
            printf("%d", level[i]);
            if (i < size - 1)
                printf(",");
        }
        printf("] ");

        leftToRight = !leftToRight;
    }
}

int main()
{
    struct TreeNode *root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    zigzagTraversal(root);

    return 0;
}
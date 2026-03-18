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

struct TreeNode *queue[1000];
int front = 0, rear = 0;

void enqueue(struct TreeNode *node)
{
    queue[rear++] = node;
}

struct TreeNode *dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front == rear;
}

void levelOrder(struct TreeNode *root)
{
    if (!root)
        return;

    enqueue(root);

    while (!isEmpty())
    {
        int size = rear - front;

        printf("[");
        for (int i = 0; i < size; i++)
        {
            struct TreeNode *curr = dequeue();
            printf("%d", curr->val);

            if (i < size - 1)
                printf(",");

            if (curr->left)
                enqueue(curr->left);
            if (curr->right)
                enqueue(curr->right);
        }
        printf("]");

        if (!isEmpty())
            printf(",");
    }
}

int main()
{
    struct TreeNode *root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("[");
    levelOrder(root);
    printf("]");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node *node)
{
    if (rear == 999)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = node;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node *root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (front <= rear && i < n)
    {
        struct Node *curr = dequeue();

        if (arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    front = rear = -1;
    enqueue(root);

    while (front <= rear)
    {
        struct Node *curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);
        if (curr->right)
            enqueue(curr->right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);
    levelOrder(root);

    return 0;
}
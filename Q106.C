#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (arr[0] == -1)
        return 0;

    struct Node *root = newNode(arr[0]);

    struct Node *queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n)
    {
        struct Node *curr = queue[front++];

        if (arr[i] != -1)
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

    struct Node *q[n];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r)
    {
        int size = r - f;

        for (int i = 0; i < size; i++)
        {
            struct Node *node = q[f++];
            printf("%d ", node->data);

            if (node->left)
                q[r++] = node->left;
            if (node->right)
                q[r++] = node->right;
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Pair
{
    struct Node *node;
    int hd;
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

    struct Node *root = NULL;
    if (arr[0] != -1)
        root = newNode(arr[0]);
    else
        return 0;

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

    struct Pair q[n];
    int f = 0, r = 0;

    q[r++] = (struct Pair){root, 0};

    int min = 0, max = 0;

    int res[200][200];
    int count[200] = {0};

    while (f < r)
    {
        struct Pair p = q[f++];
        struct Node *curr = p.node;
        int hd = p.hd;

        if (hd < min)
            min = hd;
        if (hd > max)
            max = hd;

        res[hd + 100][count[hd + 100]++] = curr->data;

        if (curr->left)
            q[r++] = (struct Pair){curr->left, hd - 1};
        if (curr->right)
            q[r++] = (struct Pair){curr->right, hd + 1};
    }

    for (int i = min; i <= max; i++)
    {
        for (int j = 0; j < count[i + 100]; j++)
        {
            printf("%d ", res[i + 100][j]);
        }
        printf("\n");
    }

    return 0;
}
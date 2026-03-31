#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node *buildTree(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex)
{
    if (inStart > inEnd)
        return NULL;

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = postorder[*postIndex];
    node->left = node->right = NULL;
    (*postIndex)--;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    int postIndex = N - 1;
    Node *root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    return 0;
}
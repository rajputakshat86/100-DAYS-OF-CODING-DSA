#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteKey(struct Node* head, int key)
{
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

int main()
{
    int n, value, key;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
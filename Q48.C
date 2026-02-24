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

struct Node* removeElements(struct Node* head, int val)
{
    while (head != NULL && head->data == val)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->next->data == val)
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

int main()
{
    int n, value, val;

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

    scanf("%d", &val);

    head = removeElements(head, val);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
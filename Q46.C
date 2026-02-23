#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool hasCycle(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        struct Node *newNode = createNode(val);

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

    tail = temp;

    int pos;
    scanf("%d", &pos);

    if (pos != -1)
    {
        temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        tail->next = temp;
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
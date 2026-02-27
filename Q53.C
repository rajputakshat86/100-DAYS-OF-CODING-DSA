#include <stdio.h>
#include <stdlib.h>

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

struct Node *append(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int getLength(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2)
    {
        while (diff--)
            head1 = head1->next;
    }
    else
    {
        while (diff--)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main()
{
    int n, m, i, value;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head1 = append(head1, value);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &value);
        head2 = append(head2, value);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
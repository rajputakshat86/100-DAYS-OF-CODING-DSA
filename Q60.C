#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode *createList(int n)
{
    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct ListNode *head = NULL, *temp = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        carry = sum / 10;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return reverse(head);
}

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    int n1, n2;

    scanf("%d", &n1);
    struct ListNode *l1 = createList(n1);

    scanf("%d", &n2);
    struct ListNode *l2 = createList(n2);

    struct ListNode *result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *cycleNode = NULL;

    int value;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct ListNode *newNode = createNode(value);

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

        if (i == 0)
            cycleNode = head;
    }

    int pos;
    scanf("%d", &pos);

    if (pos != -1)
    {
        temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        struct ListNode *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
    }

    struct ListNode *result = detectCycle(head);

    if (result == NULL)
        printf("NULL");
    else
        printf("%d", result->val);

    return 0;
}
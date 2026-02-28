#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);

    while (slow != NULL)
    {
        if (head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("false");
        return 0;
    }

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

    if (isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *curr = head;

    while (curr != NULL)
    {
        struct ListNode *prev = dummy;

        while (prev->next != NULL && prev->next->val < curr->val)
        {
            prev = prev->next;
        }

        struct ListNode *nextTemp = curr->next;
        curr->next = prev->next;
        prev->next = curr;

        curr = nextTemp;
    }

    struct ListNode *result = dummy->next;
    free(dummy);
    return result;
}

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    head = insertionSortList(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
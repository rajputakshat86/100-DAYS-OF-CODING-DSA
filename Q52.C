#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return -1;
    Node *cur = obj->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if (!obj->head)
    {
        obj->head = newNode;
    }
    else
    {
        Node *cur = obj->head;
        while (cur->next)
            cur = cur->next;
        cur->next = newNode;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index < 0 || index > obj->size)
        return;
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    Node *cur = obj->head;
    for (int i = 0; i < index - 1; i++)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return;
    Node *toDelete;
    if (index == 0)
    {
        toDelete = obj->head;
        obj->head = obj->head->next;
        free(toDelete);
    }
    else
    {
        Node *cur = obj->head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        toDelete = cur->next;
        cur->next = cur->next->next;
        free(toDelete);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *cur = obj->head;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}

int main()
{
    MyLinkedList *list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);
    printf("%d\n", myLinkedListGet(list, 1));
    myLinkedListDeleteAtIndex(list, 1);
    printf("%d\n", myLinkedListGet(list, 1));
    myLinkedListFree(list);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head)
        return newNode;
    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

bool removeLoop(struct Node* head) {
    if (!head || !head->next)
        return false;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return false;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return true;
}

int main() {
    struct Node* head = NULL;
    int n, i, val, loopPos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }

    printf("Enter loop position (0 for no loop): ");
    scanf("%d", &loopPos);

    if (loopPos > 0) {
        struct Node* temp = head;
        struct Node* loopNode = NULL;
        int count = 1;
        while (temp->next) {
            if (count == loopPos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopNode; 
    }

    if (removeLoop(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
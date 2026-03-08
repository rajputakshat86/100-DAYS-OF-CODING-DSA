#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;
int size = 0, capacity;

bool isFull()
{
    return size == capacity;
}

bool isEmpty()
{
    return size == 0;
}

bool insertFront(int x)
{
    if (isFull())
        return false;

    if (front == -1)
        front = rear = 0;
    else
        front = (front - 1 + capacity) % capacity;

    deque[front] = x;
    size++;
    return true;
}

bool insertLast(int x)
{
    if (isFull())
        return false;

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % capacity;

    deque[rear] = x;
    size++;
    return true;
}

bool deleteFront()
{
    if (isEmpty())
        return false;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % capacity;

    size--;
    return true;
}

bool deleteLast()
{
    if (isEmpty())
        return false;

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + capacity) % capacity;

    size--;
    return true;
}

int getFront()
{
    if (isEmpty())
        return -1;

    return deque[front];
}

int getRear()
{
    if (isEmpty())
        return -1;

    return deque[rear];
}

void display()
{
    if (isEmpty())
        return;

    int i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % capacity;
    }
}

int main()
{
    capacity = 3;

    insertLast(1);
    insertLast(2);
    insertFront(3);
    insertFront(4);

    printf("%d\n", getRear());
    printf("%d\n", isFull());

    deleteLast();
    insertFront(4);

    printf("%d\n", getFront());

    return 0;
}
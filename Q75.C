#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = value;
}

void push_back(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = value;
}

void pop_front()
{
    if (front == -1)
    {
        printf("Underflow\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void pop_back()
{
    if (front == -1)
    {
        printf("Underflow\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int getFront()
{
    if (front == -1)
        return -1;
    return deque[front];
}

int getRear()
{
    if (front == -1)
        return -1;
    return deque[rear];
}

int size()
{
    if (front == -1)
        return 0;
    if (rear >= front)
        return rear - front + 1;
    return MAX - front + rear + 1;
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    pop_back();
    push_back(30);

    display();

    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    printf("Size: %d\n", size());

    return 0;
}
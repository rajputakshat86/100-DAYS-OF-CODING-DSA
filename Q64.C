#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s)
{
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int val)
{
    s->top++;
    s->stack[s->top] = val;

    if (s->minTop == -1 || val <= s->minStack[s->minTop])
    {
        s->minTop++;
        s->minStack[s->minTop] = val;
    }
}

void pop(MinStack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    if (s->stack[s->top] == s->minStack[s->minTop])
    {
        s->minTop--;
    }

    s->top--;
}

int top(MinStack *s)
{
    return s->stack[s->top];
}

int getMin(MinStack *s)
{
    return s->minStack[s->minTop];
}

int main()
{
    MinStack s;
    init(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    printf("Minimum: %d\n", getMin(&s));

    pop(&s);

    printf("Top element: %d\n", top(&s));

    printf("Minimum: %d\n", getMin(&s));

    return 0;
}
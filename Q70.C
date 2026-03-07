#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int x)
{
    s1[++top1] = x;
}

int pop()
{
    if (top2 == -1)
    {
        while (top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    return s2[top2--];
}

int peek()
{
    if (top2 == -1)
    {
        while (top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    return s2[top2];
}

bool empty()
{
    if (top1 == -1 && top2 == -1)
        return true;
    else
        return false;
}

int main()
{
    push(1);
    push(2);

    printf("%d\n", peek());
    printf("%d\n", pop());

    if (empty())
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
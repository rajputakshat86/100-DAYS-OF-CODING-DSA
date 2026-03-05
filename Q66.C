#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    char tokens[MAX][20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", tokens[i]);
    }

    for (int i = 0; i < n; i++)
    {

        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0)
        {

            int a = pop();
            int b = pop();
            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = b + a;
            else if (strcmp(tokens[i], "-") == 0)
                result = b - a;
            else if (strcmp(tokens[i], "*") == 0)
                result = b * a;
            else
                result = b / a;

            push(result);
        }
        else
        {
            push(atoi(tokens[i]));
        }
    }

    printf("%d", pop());

    return 0;
}
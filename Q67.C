#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
    {

        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else
        {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (exp[i])
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            }

            push(result);
            i++;
        }
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isValid(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else
        {
            if (top == -1)
                return false;
            char ch = pop();
            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '['))
                return false;
        }
    }
    return top == -1;
}

int main()
{
    char s[MAX];
    scanf("%s", s);

    if (isValid(s))
        printf("true");
    else
        printf("false");

    return 0;
}
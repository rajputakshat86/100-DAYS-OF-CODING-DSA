#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char *s)
{
    long result = 0;
    long last = 0;
    long num = 0;
    char sign = '+';
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == len - 1)
        {
            if (sign == '+')
            {
                result += last;
                last = num;
            }
            else if (sign == '-')
            {
                result += last;
                last = -num;
            }
            else if (sign == '*')
            {
                last = last * num;
            }
            else if (sign == '/')
            {
                last = last / num;
            }
            sign = s[i];
            num = 0;
        }
    }

    return result + last;
}

int main()
{
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    int len = strlen(expr);
    if (expr[len - 1] == '\n')
        expr[len - 1] = '\0';
    int result = calculate(expr);
    printf("%d\n", result);
    return 0;
}
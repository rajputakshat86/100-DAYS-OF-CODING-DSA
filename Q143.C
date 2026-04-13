#include <stdio.h>

char firstRepeatedChar(char *s)
{
    int visited[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (visited[s[i] - 'a'] == 1)
        {
            return s[i];
        }
        visited[s[i] - 'a'] = 1;
    }
    return '\0';
}

int main()
{
    char s[1000];
    scanf("%s", s);

    char result = firstRepeatedChar(s);

    if (result == '\0')
        printf("-1");
    else
        printf("%c", result);

    return 0;
}
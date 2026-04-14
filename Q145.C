#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int freq[26] = {0};

    scanf("%s", s);

    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++)
    {
        if (freq[s[i] - 'a'] == 1)
        {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("$");

    return 0;
}
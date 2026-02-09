#include <stdio.h>

void reverseString(char s[], int n)
{
    int left = 0, right = n - 1;
    char temp;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    int n;
    char s[100];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters (without spaces): ");
    scanf("%s", s);

    reverseString(s, n);

    printf("Reversed string: ");
    for (int i = 0; i < n; i++)
        printf("%c ", s[i]);

    return 0;
}

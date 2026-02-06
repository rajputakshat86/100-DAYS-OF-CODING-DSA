#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int insertPos = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[insertPos] = nums[i];
            insertPos++;
        }
    }

    for (int i = insertPos; i < n; i++)
    {
        nums[i] = 0;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}

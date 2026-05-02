#include <stdio.h>

void sortColors(int nums[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements (0, 1, 2 only):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    sortColors(nums, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
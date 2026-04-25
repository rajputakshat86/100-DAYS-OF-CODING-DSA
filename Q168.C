#include <stdio.h>

int findPeakElement(int nums[], int n)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int n;

    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int index = findPeakElement(nums, n);

    printf("%d\n", index);

    return 0;
}
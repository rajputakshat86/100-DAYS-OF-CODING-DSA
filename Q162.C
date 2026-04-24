#include <stdio.h>

int binarySearch(int nums[], int n, int target)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int n, target;

    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    int result = binarySearch(nums, n, target);

    printf("%d", result);

    return 0;
}
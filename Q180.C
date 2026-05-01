#include <stdio.h>

int canSplit(int nums[], int n, int k, long maxSum)
{
    int count = 1;
    long currSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currSum + nums[i] <= maxSum)
        {
            currSum += nums[i];
        }
        else
        {
            count++;
            currSum = nums[i];

            if (count > k)
                return 0;
        }
    }
    return 1;
}

int splitArray(int nums[], int n, int k)
{
    long low = nums[0], high = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    long ans = high;

    while (low <= high)
    {
        long mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (int)ans;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", splitArray(nums, n, k));

    return 0;
}
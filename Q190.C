#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maximumGap(int *nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    int minVal = nums[0], maxVal = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < minVal)
            minVal = nums[i];
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    int n = numsSize;
    int bucketSize = (maxVal - minVal) / n + 1;

    int bucketMin[n];
    int bucketMax[n];
    int used[n];

    for (int i = 0; i < n; i++)
    {
        bucketMin[i] = 2147483647;
        bucketMax[i] = -1;
        used[i] = 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int idx = (nums[i] - minVal) / bucketSize;

        if (!used[idx])
        {
            bucketMin[idx] = nums[i];
            bucketMax[idx] = nums[i];
            used[idx] = 1;
        }
        else
        {
            if (nums[i] < bucketMin[idx])
                bucketMin[idx] = nums[i];
            if (nums[i] > bucketMax[idx])
                bucketMax[idx] = nums[i];
        }
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            continue;

        maxGap = max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return maxGap;
}

int main()
{
    int nums[] = {3, 6, 9, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maximumGap(nums, n);

    printf("Maximum Gap: %d\n", result);

    return 0;
}
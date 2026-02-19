#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int totalSum = 0;

    int currMax = 0, maxNormal = INT_MIN;
    int currMin = 0, minSub = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];

        currMax = currMax + nums[i];
        if (currMax > maxNormal)
            maxNormal = currMax;
        if (currMax < 0)
            currMax = 0;

        currMin = currMin + nums[i];
        if (currMin < minSub)
            minSub = currMin;
        if (currMin > 0)
            currMin = 0;
    }

    if (maxNormal < 0)
    {
        printf("%d", maxNormal);
    }
    else
    {
        int maxCircular = totalSum - minSub;
        if (maxNormal > maxCircular)
            printf("%d", maxNormal);
        else
            printf("%d", maxCircular);
    }

    return 0;
}

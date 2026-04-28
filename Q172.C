#include <stdio.h>

int mySqrt(int x)
{
    long long low = 0, high = x, ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid <= x / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return (int)ans;
}

int main()
{
    int x;
    scanf("%d", &x);

    printf("%d", mySqrt(x));

    return 0;
}
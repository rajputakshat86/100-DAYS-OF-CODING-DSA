#include <stdio.h>

int integer_sqrt(int n)
{
    int low = 0, high = n, ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", integer_sqrt(n));
    return 0;
}
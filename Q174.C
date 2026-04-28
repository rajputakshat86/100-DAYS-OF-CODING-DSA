#include <stdio.h>

int canEat(int *piles, int pilesSize, int k, int h)
{
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++)
    {
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}

int maxPile(int *piles, int pilesSize)
{
    int max = piles[0];

    for (int i = 1; i < pilesSize; i++)
    {
        if (piles[i] > max)
            max = piles[i];
    }

    return max;
}

int minEatingSpeed(int *piles, int pilesSize, int h)
{
    int low = 1;
    int high = maxPile(piles, pilesSize);
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canEat(piles, pilesSize, mid, h))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, h;
    scanf("%d", &n);

    int piles[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &piles[i]);

    scanf("%d", &h);

    printf("%d", minEatingSpeed(piles, n, h));

    return 0;
}
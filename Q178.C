#include <stdio.h>

int canShip(int weights[], int n, int days, int capacity)
{
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentLoad + weights[i] > capacity)
        {
            requiredDays++;
            currentLoad = weights[i];
            if (requiredDays > days)
                return 0;
        }
        else
        {
            currentLoad += weights[i];
        }
    }
    return 1;
}

int shipWithinDays(int weights[], int n, int days)
{
    int low = weights[0];
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int result = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canShip(weights, n, days, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int main()
{
    int n, days;
    scanf("%d %d", &n, &days);

    int weights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    int result = shipWithinDays(weights, n, days);
    printf("%d\n", result);

    return 0;
}
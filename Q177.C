#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages)
{
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentPages + arr[i] > maxPages)
        {
            students++;
            currentPages = arr[i];
            if (students > m)
                return 0;
        }
        else
        {
            currentPages += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m)
{
    if (m > n)
        return -1;

    int low = arr[0];
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int result = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid))
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
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);
    printf("%d\n", result);

    return 0;
}
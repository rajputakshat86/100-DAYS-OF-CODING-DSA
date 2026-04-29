#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlace(int pos[], int n, int m, int dist)
{
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++)
    {
        if (pos[i] - last >= dist)
        {
            count++;
            last = pos[i];
        }
    }

    return count >= m;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    int pos[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    scanf("%d", &m);

    qsort(pos, n, sizeof(int), compare);

    int low = 1;
    int high = pos[n - 1] - pos[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlace(pos, n, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}
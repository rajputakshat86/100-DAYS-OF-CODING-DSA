#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}

void mergeIntervals(int intervals[][2], int n)
{
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int res[n][2];
    int k = 0;

    res[k][0] = intervals[0][0];
    res[k][1] = intervals[0][1];
    k++;

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= res[k - 1][1])
        {
            if (intervals[i][1] > res[k - 1][1])
            {
                res[k - 1][1] = intervals[i][1];
            }
        }
        else
        {
            res[k][0] = intervals[i][0];
            res[k][1] = intervals[i][1];
            k++;
        }
    }

    printf("Merged Intervals: ");
    for (int i = 0; i < k; i++)
    {
        printf("[%d,%d] ", res[i][0], res[i][1]);
    }
}

int main()
{
    int intervals[][2] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}};

    int n = sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}
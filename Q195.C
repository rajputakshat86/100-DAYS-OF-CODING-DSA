#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int k = 0;

    result[k] = (int *)malloc(2 * sizeof(int));
    result[k][0] = intervals[0][0];
    result[k][1] = intervals[0][1];
    (*returnColumnSizes)[k] = 2;
    k++;

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] <= result[k - 1][1])
        {
            if (intervals[i][1] > result[k - 1][1])
            {
                result[k - 1][1] = intervals[i][1];
            }
        }
        else
        {
            result[k] = (int *)malloc(2 * sizeof(int));
            result[k][0] = intervals[i][0];
            result[k][1] = intervals[i][1];
            (*returnColumnSizes)[k] = 2;
            k++;
        }
    }

    *returnSize = k;
    return result;
}

int main()
{
    int n = 4;

    int **intervals = (int **)malloc(n * sizeof(int *));

    int data[4][2] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}};

    for (int i = 0; i < n; i++)
    {
        intervals[i] = (int *)malloc(2 * sizeof(int));
        intervals[i][0] = data[i][0];
        intervals[i][1] = data[i][1];
    }

    int returnSize;
    int *returnColumnSizes;

    int **res = merge(intervals, n, NULL, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d,%d] ", res[i][0], res[i][1]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int idx;
} Node;

void merge(Node arr[], int temp[], int count[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    Node tempArr[right - left + 1];

    int t = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i].val <= arr[j].val)
        {
            count[arr[i].idx] += rightCount;
            tempArr[t++] = arr[i++];
        }
        else
        {
            rightCount++;
            tempArr[t++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        count[arr[i].idx] += rightCount;
        tempArr[t++] = arr[i++];
    }

    while (j <= right)
    {
        tempArr[t++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = tempArr[i - left];
    }
}

void mergeSort(Node arr[], int temp[], int count[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);

    merge(arr, temp, count, left, mid, right);
}

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    Node arr[numsSize];

    for (int i = 0; i < numsSize; i++)
    {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    int count[numsSize];
    for (int i = 0; i < numsSize; i++)
        count[i] = 0;

    int temp[numsSize];

    mergeSort(arr, temp, count, 0, numsSize - 1);

    int *res = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        res[i] = count[i];
    }

    *returnSize = numsSize;
    return res;
}

int main()
{
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int *result = countSmaller(nums, n, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}
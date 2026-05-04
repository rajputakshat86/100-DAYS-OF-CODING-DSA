#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int idx;
} Node;

void merge(Node arr[], Node temp[], int count[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i].val <= arr[j].val)
        {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
        else
        {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(Node arr[], Node temp[], int count[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);
    merge(arr, temp, count, left, mid, right);
}

int main()
{
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Node arr[n], temp[n];
    int count[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].val = nums[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, count, 0, n - 1);

    printf("Output: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}
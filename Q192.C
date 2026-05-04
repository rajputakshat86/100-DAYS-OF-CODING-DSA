#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int count = 0;

    j = mid + 1;
    for (i = left; i <= mid; i++)
    {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    i = left;
    j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        count += merge(arr, temp, left, mid, right);
    }
    return count;
}

int reversePairs(int nums[], int n)
{
    int temp[n];
    return mergeSort(nums, temp, 0, n - 1);
}

int main()
{
    int nums[] = {1, 3, 2, 3, 1};
    int n = 5;

    printf("Reverse pairs = %d\n", reversePairs(nums, n));
    return 0;
}
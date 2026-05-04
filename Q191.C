#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;    // left subarray
    int j = mid + 1; // right subarray
    int k = left;
    int inv_count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // key step
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;

    if (left < right)
    {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    int temp[5];

    int result = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %d\n", result);
    return 0;
}
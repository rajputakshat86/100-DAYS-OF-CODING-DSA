#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int findKthLargest(int *nums, int numsSize, int k)
{
    int heap[k];

    for (int i = 0; i < k; i++)
        heap[i] = nums[i];

    for (int i = k / 2 - 1; i >= 0; i--)
        heapify(heap, k, i);

    for (int i = k; i < numsSize; i++)
    {
        if (nums[i] > heap[0])
        {
            heap[0] = nums[i];
            heapify(heap, k, 0);
        }
    }

    return heap[0];
}

int main()
{
    int nums[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = findKthLargest(nums, n, k);

    printf("Kth Largest Element: %d\n", result);

    return 0;
}
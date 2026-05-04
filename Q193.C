#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int **)a)[0] - (*(int **)b)[0];
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int heap[], int size, int i)
{
    while (1)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void push(int heap[], int *size, int val)
{
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

void pop(int heap[], int *size)
{
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(int intervals[][2], int n)
{
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int heap[n];
    int size = 0;

    push(heap, &size, intervals[0][1]);

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= heap[0])
        {
            pop(heap, &size);
        }
        push(heap, &size, intervals[i][1]);
    }

    return size;
}

int main()
{
    int intervals[4][2] = {
        {0, 30},
        {5, 10},
        {15, 20},
        {25, 35}};

    int n = 4;

    int result = minMeetingRooms(intervals, n);

    printf("Minimum meeting rooms required = %d\n", result);

    return 0;
}
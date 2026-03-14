#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *maxHeap;
    int maxSize;
    int *minHeap;
    int minSize;
} MedianFinder;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int *heap, int size)
{
    int i = size - 1;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[i] <= heap[p])
            break;
        swap(&heap[i], &heap[p]);
        i = p;
    }
}

void maxHeapifyDown(int *heap, int size)
{
    int i = 0;
    while (2 * i + 1 < size)
    {
        int l = 2 * i + 1, r = 2 * i + 2, largest = l;
        if (r < size && heap[r] > heap[l])
            largest = r;
        if (heap[i] >= heap[largest])
            break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

void minHeapifyUp(int *heap, int size)
{
    int i = size - 1;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[i] >= heap[p])
            break;
        swap(&heap[i], &heap[p]);
        i = p;
    }
}

void minHeapifyDown(int *heap, int size)
{
    int i = 0;
    while (2 * i + 1 < size)
    {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = l;
        if (r < size && heap[r] < heap[l])
            smallest = r;
        if (heap[i] <= heap[smallest])
            break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

MedianFinder *medianFinderCreate()
{
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    obj->maxHeap = (int *)malloc(sizeof(int) * 100000);
    obj->minHeap = (int *)malloc(sizeof(int) * 100000);
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder *obj, int num)
{
    if (obj->maxSize == 0 || num <= obj->maxHeap[0])
    {
        obj->maxHeap[obj->maxSize++] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
    }
    else
    {
        obj->minHeap[obj->minSize++] = num;
        minHeapifyUp(obj->minHeap, obj->minSize);
    }
    if (obj->maxSize > obj->minSize + 1)
    {
        int tmp = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[obj->maxSize - 1];
        obj->maxSize--;
        maxHeapifyDown(obj->maxHeap, obj->maxSize);
        obj->minHeap[obj->minSize++] = tmp;
        minHeapifyUp(obj->minHeap, obj->minSize);
    }
    if (obj->minSize > obj->maxSize)
    {
        int tmp = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[obj->minSize - 1];
        obj->minSize--;
        minHeapifyDown(obj->minHeap, obj->minSize);
        obj->maxHeap[obj->maxSize++] = tmp;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
    }
}

double medianFinderFindMedian(MedianFinder *obj)
{
    if (obj->maxSize > obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder *obj)
{
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

int main()
{
    MedianFinder *mf = medianFinderCreate();
    medianFinderAddNum(mf, 1);
    medianFinderAddNum(mf, 2);
    printf("%.1f\n", medianFinderFindMedian(mf));
    medianFinderAddNum(mf, 3);
    printf("%.1f\n", medianFinderFindMedian(mf));
    medianFinderFree(mf);
    return 0;
}
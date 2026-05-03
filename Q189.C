#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Node
{
    float data;
    struct Node *next;
};

void insert(struct Node **bucket, float value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL || (*bucket)->data >= value)
    {
        newNode->next = *bucket;
        *bucket = newNode;
    }
    else
    {
        struct Node *curr = *bucket;
        while (curr->next != NULL && curr->next->data < value)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void bucketSort(float arr[], int n)
{
    struct Node *buckets[n];

    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        insert(&buckets[index], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        struct Node *curr = buckets[i];
        while (curr != NULL)
        {
            arr[k++] = curr->data;
            struct Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main()
{
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51, 0.12, 0.09, 0.99};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
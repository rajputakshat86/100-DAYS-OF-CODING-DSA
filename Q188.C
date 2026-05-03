#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr2[] = {2, 1, 4, 3, 9, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int order[1001];
    for (int i = 0; i < 1001; i++)
    {
        order[i] = 0;
    }

    for (int i = 0; i < n2; i++)
    {
        order[arr2[i]] = i + 1;
    }

    for (int i = 0; i < n1 - 1; i++)
    {
        for (int j = 0; j < n1 - i - 1; j++)
        {
            int a = arr1[j];
            int b = arr1[j + 1];

            if ((order[a] == 0 && order[b] == 0 && a > b) ||
                (order[a] == 0 && order[b] != 0) ||
                (order[a] > order[b] && order[b] != 0))
            {
                swap(&arr1[j], &arr1[j + 1]);
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}
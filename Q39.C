#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    int freq[10001] = {0};
    int offset = 5000;

    freq[offset] = 1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (freq[sum + offset] > 0)
        {
            count += freq[sum + offset];
        }

        freq[sum + offset]++;
    }

    printf("Number of subarrays with sum zero: %d\n", count);

    return 0;
}
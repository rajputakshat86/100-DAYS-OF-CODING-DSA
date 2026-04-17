#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n)
{
    int sum = 0, max_len = 0;

    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
    {
        hash[i] = -2;
    }

    int offset = MAX;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // Case 1: sum == 0
        if (sum == 0)
        {
            max_len = i + 1;
        }

        if (hash[sum + offset] != -2)
        {
            int prev_index = hash[sum + offset];
            int len = i - prev_index;
            if (len > max_len)
                max_len = len;
        }
        else
        {

            hash[sum + offset] = i;
        }
    }

    return max_len;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d\n", maxLen(arr, n));

    return 0;
}
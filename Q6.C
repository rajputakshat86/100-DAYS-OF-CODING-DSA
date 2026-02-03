#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n (size of complete range): ");
    scanf("%d", &n);

    int arr[n - 1];
    printf("Enter %d distinct numbers from 1 to %d:\n", n - 1, n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);

    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;
    for (int i = 0; i < n - 1; i++)
        array_sum += arr[i];

    int missing = total_sum - array_sum;
    printf("Missing number is: %d\n", missing);

    return 0;
}

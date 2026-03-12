#include <stdio.h>
#include <stdlib.h>

// Function to calculate daily temperatures
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    *returnSize = temperaturesSize;
    int *answer = (int *)malloc(sizeof(int) * temperaturesSize);
    for (int i = 0; i < temperaturesSize; i++)
        answer[i] = 0;

    int *stack = (int *)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++)
    {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]])
        {
            int index = stack[top--];
            answer[index] = i - index;
        }
        stack[++top] = i;
    }

    free(stack);
    return answer;
}

int main()
{
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int *temperatures = (int *)malloc(sizeof(int) * n);
    printf("Enter temperatures: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &temperatures[i]);

    int returnSize;
    int *answer = dailyTemperatures(temperatures, n, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", answer[i]);
    printf("\n");

    free(temperatures);
    free(answer);

    return 0;
}
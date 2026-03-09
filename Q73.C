#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    int pq[1000];
    int size = 0;

    while (N--)
    {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            int x;
            scanf("%d", &x);
            pq[size++] = x;
        }

        else if (strcmp(op, "delete") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
                continue;
            }

            int minIndex = 0;

            for (int i = 1; i < size; i++)
            {
                if (pq[i] < pq[minIndex])
                {
                    minIndex = i;
                }
            }

            printf("%d\n", pq[minIndex]);

            for (int i = minIndex; i < size - 1; i++)
            {
                pq[i] = pq[i + 1];
            }

            size--;
        }

        else if (strcmp(op, "peek") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
                continue;
            }

            int minValue = pq[0];

            for (int i = 1; i < size; i++)
            {
                if (pq[i] < minValue)
                {
                    minValue = pq[i];
                }
            }

            printf("%d\n", minValue);
        }
    }

    return 0;
}
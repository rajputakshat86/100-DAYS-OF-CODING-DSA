#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minRooms(int start[], int end[], int n)
{
    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n)
    {
        if (start[i] >= end[j])
        {
            j++;
        }
        else
        {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
        }
        i++;
    }

    return maxRooms;
}

int main()
{
    int start[] = {2, 9, 6};
    int end[] = {4, 12, 10};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required = %d\n", minRooms(start, end, n));

    return 0;
}
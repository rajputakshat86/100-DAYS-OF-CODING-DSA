#include <stdio.h>

int leastInterval(char tasks[], int size, int n)
{
    int freq[26] = {0};

    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;

    for (int i = 0; i < 26; i++)
        if (freq[i] > maxFreq)
            maxFreq = freq[i];

    int countMax = 0;

    for (int i = 0; i < 26; i++)
        if (freq[i] == maxFreq)
            countMax++;

    int result = (maxFreq - 1) * (n + 1) + countMax;

    if (result < size)
        return size;

    return result;
}

int main()
{
    char tasks[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int size = sizeof(tasks) / sizeof(tasks[0]);

    printf("%d", leastInterval(tasks, size, n));

    return 0;
}
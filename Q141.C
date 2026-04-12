#include <stdio.h>
#include <string.h>

#define SIZE 100

int hashTable[SIZE];
int m;

// Initialize table
void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

// Insert using quadratic probing
void insert(int key)
{
    int h = key % m;

    for (int i = 0; i < m; i++)
    {
        int index = (h + i * i) % m;

        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            return;
        }
    }
}

// Search using quadratic probing
void search(int key)
{
    int h = key % m;

    for (int i = 0; i < m; i++)
    {
        int index = (h + i * i) % m;

        if (hashTable[index] == -1)
        {
            printf("NOT FOUND\n");
            return;
        }

        if (hashTable[index] == key)
        {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main()
{
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    char operation[10];
    int value;

    for (int i = 0; i < q; i++)
    {
        scanf("%s %d", operation, &value);

        if (strcmp(operation, "INSERT") == 0)
        {
            insert(value);
        }
        else if (strcmp(operation, "SEARCH") == 0)
        {
            search(value);
        }
    }

    return 0;
}
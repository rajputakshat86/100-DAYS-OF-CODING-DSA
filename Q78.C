#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int freq;
} Element;

int compare(const void *a, const void *b)
{
    Element *x = (Element *)a;
    Element *y = (Element *)b;
    return y->freq - x->freq;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &k);

    Element elements[n];
    int unique = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < unique; j++)
        {
            if (elements[j].num == nums[i])
            {
                elements[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            elements[unique].num = nums[i];
            elements[unique].freq = 1;
            unique++;
        }
    }

    qsort(elements, unique, sizeof(Element), compare);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", elements[i].num);
    }
    printf("\n");

    return 0;
}
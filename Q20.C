#include <stdio.h>

int main()
{
    int nums1[100], nums2[100], result[100];
    int n1, n2, i, j, k = 0;

    printf("Enter size of nums1: ");
    scanf("%d", &n1);

    printf("Enter elements of nums1:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    printf("Enter size of nums2: ");
    scanf("%d", &n2);

    printf("Enter elements of nums2:\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                result[k++] = nums1[i];
                nums2[j] = -1;
                break;
            }
        }
    }

    printf("Intersection: ");
    for (i = 0; i < k; i++)
        printf("%d ", result[i]);

    return 0;
}

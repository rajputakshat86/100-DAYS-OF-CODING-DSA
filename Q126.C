#include <stdio.h>

#define MAX 100

int image[MAX][MAX];
int m, n;
int original_color, new_color;

void floodFill(int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (image[r][c] != original_color || image[r][c] == new_color)
        return;

    image[r][c] = new_color;

    floodFill(r + 1, c);
    floodFill(r - 1, c);
    floodFill(r, c + 1);
    floodFill(r, c - 1);
}

int main()
{
    int sr, sc;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &image[i][j]);

    scanf("%d %d %d", &sr, &sc, &new_color);

    original_color = image[sr][sc];
    floodFill(sr, sc);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }
    return 0;
}
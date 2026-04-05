#include <stdio.h>

#define MAX 100

int grid[MAX][MAX];
int queue[MAX * MAX][2];

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int fresh = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int front = 0, rear = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if (grid[i][j] == 1)
                fresh++;
        }
    }

    int minutes = 0;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (front < rear && fresh > 0)
    {
        int size = rear - front;
        for (int i = 0; i < size; i++)
        {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                    fresh--;
                }
            }
        }
        minutes++;
    }

    if (fresh == 0)
        printf("%d", minutes);
    else
        printf("-1");

    return 0;
}
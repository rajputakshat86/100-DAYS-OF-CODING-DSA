#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int solve(int mask, int pos)
{
    if (mask == (1 << n) - 1)
    {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int tsp()
{
    memset(dp, -1, sizeof(dp));
    return solve(1, 0); // start from city 0
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("%d\n", tsp());

    return 0;
}
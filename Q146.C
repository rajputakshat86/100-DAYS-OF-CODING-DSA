#include <stdio.h>

int parent[1001];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

int *findRedundantConnection(int edges[][2], int n)
{
    static int result[2];

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(u) == find(v))
        {
            result[0] = u;
            result[1] = v;
        }
        else
        {
            unionSet(u, v);
        }
    }

    return result;
}

int main()
{
    int edges[3][2] = {{1, 2}, {1, 3}, {2, 3}};
    int n = 3;

    int *ans = findRedundantConnection(edges, n);

    printf("[%d,%d]", ans[0], ans[1]);

    return 0;
}
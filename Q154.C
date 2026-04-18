#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int time = 0;

void dfs(int u, int parent, int** adj, int* size, int* disc, int* low, int* visited) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u, adj, size, disc, low, visited);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                printf("[%d, %d]\n", u, v);
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* size = (int*)calloc(n, sizeof(int));
    int* u = (int*)malloc(m * sizeof(int));
    int* v = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        size[u[i]]++;
        size[v[i]]++;
    }

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        adj[u[i]][size[u[i]]++] = v[i];
        adj[v[i]][size[v[i]]++] = u[i];
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, size, disc, low, visited);
        }
    }

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(size);
    free(u);
    free(v);
    free(disc);
    free(low);
    free(visited);

    return 0;
}
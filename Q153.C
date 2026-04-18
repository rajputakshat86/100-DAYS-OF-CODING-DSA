#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* size, int* visited) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int nei = adj[node][i];
        if (!visited[nei]) {
            dfs(nei, adj, size, visited);
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
        u[i]--; 
        v[i]--;
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

    int* visited = (int*)calloc(n, sizeof(int));

    dfs(0, adj, size, visited);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(size);
    free(u);
    free(v);
    free(visited);

    return 0;
}
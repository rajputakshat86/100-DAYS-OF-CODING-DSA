#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 105

struct Node
{
    int v;
    int w;
    struct Node *next;
};

struct HeapNode
{
    int node;
    int dist;
};

struct MinHeap
{
    int size;
    struct HeapNode arr[MAX * MAX];
};

struct Node *createNode(int v, int w)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Node *adj[], int u, int v, int w)
{
    struct Node *temp = createNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;
}

void swap(struct HeapNode *a, struct HeapNode *b)
{
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap *h, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;

    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap *h)
{
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insert(struct MinHeap *h, int node, int dist)
{
    int i = h->size++;
    h->arr[i].node = node;
    h->arr[i].dist = dist;

    while (i && h->arr[(i - 1) / 2].dist > h->arr[i].dist)
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int networkDelayTime(struct Node *adj[], int n, int k)
{
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[k] = 0;
    insert(&h, k, 0);

    while (h.size > 0)
    {
        struct HeapNode curr = extractMin(&h);
        int u = curr.node;

        struct Node *temp = adj[u];

        while (temp != NULL)
        {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                insert(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > max)
            max = dist[i];
    }

    return max;
}

int main()
{
    int n = 4;
    int k = 2;

    struct Node *adj[MAX] = {NULL};

    addEdge(adj, 2, 1, 1);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 3, 4, 1);

    int result = networkDelayTime(adj, n, k);

    printf("%d\n", result);

    return 0;
}
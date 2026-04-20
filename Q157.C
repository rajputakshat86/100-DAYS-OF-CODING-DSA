#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct MinHeapNode
{
    int vertex;
    int dist;
};

struct MinHeap
{
    int size;
    struct MinHeapNode heap[MAX];
};

struct Node *createNode(int v, int w)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node *adj[], int u, int v, int w)
{
    struct Node *newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void swap(struct MinHeapNode *a, struct MinHeapNode *b)
{
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *h, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i)
    {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

struct MinHeapNode extractMin(struct MinHeap *h)
{
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap *h, int v, int dist)
{
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[i].dist < h->heap[(i - 1) / 2].dist)
    {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(struct Node *adj[], int n, int source)
{
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[source] = 0;
    insertHeap(&h, source, 0);

    while (h.size > 0)
    {
        struct MinHeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        struct Node *temp = adj[u];

        while (temp)
        {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node *adj[MAX] = {NULL};

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(adj, n, source);

    return 0;
}
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

struct HeapNode
{
    int vertex;
    int dist;
};

struct MinHeap
{
    int size;
    struct HeapNode heap[MAX];
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
}

void swap(struct HeapNode *a, struct HeapNode *b)
{
    struct HeapNode temp = *a;
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

struct HeapNode extractMin(struct MinHeap *h)
{
    struct HeapNode root = h->heap[0];
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

    while (i && h->heap[(i - 1) / 2].dist > h->heap[i].dist)
    {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(struct Node *adj[], int V, int src)
{
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (h.size > 0)
    {
        struct HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        struct Node *temp = adj[u];

        while (temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main()
{
    int V = 5;
    struct Node *adj[MAX];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 2, 3, 4);

    dijkstra(adj, V, 0);

    return 0;
}
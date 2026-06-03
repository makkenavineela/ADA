#include <stdio.h>
#include <limits.h>

#define MAX 100

int mindis(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = mindis(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex \t Distance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX], n, src;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1) return 1;
        }
    }

    printf("Enter source vertex: ");
    if (scanf("%d", &src) != 1) return 1;

    dijkstra(graph, n, src);

    return 0;
}

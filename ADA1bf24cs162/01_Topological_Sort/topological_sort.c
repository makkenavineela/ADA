#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, adj[MAX][MAX], indegree[MAX] = {0}, queue[MAX], front = 0, rear = 0;
    int topo[MAX], k = 0;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        topo[k++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (k != n) {
        printf("The graph contains a cycle. Topological ordering is not possible.\n");
    } else {
        printf("Topological ordering: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}

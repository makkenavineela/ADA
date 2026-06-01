#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int adj[MAX][MAX], int V) {
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int topo_order[MAX];
    int count = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != V) {
        printf("Error: Graph contains a cycle.\n");
        return;
    }

    for (int i = 0; i < V; i++) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;
    int adj[MAX][MAX] = {0};

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(adj, V);

    return 0;
}

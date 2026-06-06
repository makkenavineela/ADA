#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskals(int cost[MAX][MAX], int n) {
    int mincost = 0;
    int edge_count = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (edge_count < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            if (find(u) != find(v)){
                unionSets(u, v);
                printf("Edge %d: (%d -> %d) cost: %d\n", edge_count + 1, u, v, min);
                edge_count++;
                mincost += min;
            }
            cost[u][v] = INF;
            cost[v][u] = INF;
        } else {
            break;
        }
    }

    printf("\nMinimum Cost: %d\n", mincost);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter adjacency matrix (99999 for no edge / INF):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    kruskals(cost, n);
    return 0;
}

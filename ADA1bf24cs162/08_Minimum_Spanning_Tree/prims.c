#include <stdio.h>
#define INF 99999
#define MAX 100

void prims(int cost[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int ne = 1;
    int mincost = 0;

    visited[0] = 1;
    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("Edge %d: (%d -> %d) cost: %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
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

    prims(cost, n);
    return 0;
}

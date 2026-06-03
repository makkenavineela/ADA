#include <stdio.h>
#include <stdlib.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int INF = 1e9;
    
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j) {
                adj[i][j] = 0;
            } else {
                adj[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] != INF && adj[k][j] != INF && adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int node = 0;
    int minCount = n;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && adj[i][j] <= distanceThreshold) {
                count++;
            }
        }
        if (count <= minCount) {
            minCount = count;
            node = i;
        }
    }

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return node;
}

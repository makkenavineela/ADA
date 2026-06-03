#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSizes = (int*)calloc(numCourses, sizeof(int));
    int* adjCaps = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adjCaps[i] = 2;
        adj[i] = (int*)malloc(adjCaps[i] * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        inDegree[dest]++;

        if (adjSizes[src] == adjCaps[src]) {
            adjCaps[src] *= 2;
            adj[src] = (int*)realloc(adj[src], adjCaps[src] * sizeof(int));
        }
        adj[src][adjSizes[src]++] = dest;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int resultCount = 0;

    while (head < tail) {
        int u = queue[head++];
        result[resultCount++] = u;

        for (int i = 0; i < adjSizes[u]; i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSizes);
    free(adjCaps);
    free(inDegree);
    free(queue);

    if (resultCount == numCourses) {
        *returnSize = numCourses;
        return result;
    } else {
        free(result);
        *returnSize = 0;
        return NULL;
    }
}

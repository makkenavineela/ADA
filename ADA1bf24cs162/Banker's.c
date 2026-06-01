#include <stdio.h>
#include <stdbool.h>

int main() {
    // P0, P1, P2, P3, P4 are the names of the processes
    int n = 5; // Number of processes
    int m = 3; // Number of resource types

    // Allocation Matrix
    int alloc[5][3] = { { 0, 1, 0 },  // P0
                        { 2, 0, 0 },  // P1
                        { 3, 0, 2 },  // P2
                        { 2, 1, 1 },  // P3
                        { 0, 0, 2 } }; // P4

    // Max Matrix
    int max[5][3] = { { 7, 5, 3 },  // P0
                      { 3, 2, 2 },  // P1
                      { 9, 0, 2 },  // P2
                      { 2, 2, 2 },  // P3
                      { 4, 3, 3 } }; // P4

    // Available Resources
    int avail[3] = { 3, 3, 2 };

    int finish[n], safe_seq[n], ind = 0;
    for (int k = 0; k < n; k++) {
        finish[k] = 0; // Initialize all processes as unfinished
    }

    // Calculate the Need Matrix
    // Need[i][j] = Max[i][j] - Allocation[i][j]
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Safety Algorithm Logic
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) { // If process not yet finished
                int can_allocate = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        can_allocate = 0; // Cannot satisfy the need
                        break;
                    }
                }

                if (can_allocate == 1) {
                    safe_seq[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y]; // Release resources
                    finish[i] = 1;
                }
            }
        }
    }

    // Check if the system is in a safe state
    bool safe = true;
    for(int i = 0; i < n; i++) {
        if(finish[i] == 0) {
            safe = false;
            printf("The system is in an UNSAFE state (Deadlock possible)!\n");
            break;
        }
    }

    if(safe) {
        printf("The system is in a SAFE state.\nSafe Sequence: ");
        for (int i = 0; i < n - 1; i++)
            printf("P%d -> ", safe_seq[i]);
        printf("P%d\n", safe_seq[n - 1]);
    }

    return 0;
}

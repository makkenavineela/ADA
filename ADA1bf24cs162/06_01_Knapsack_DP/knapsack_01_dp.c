#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solveKnapsack(int profits[], int weights[], int n, int capacity) {
    if (capacity <= 0 || n == 0) {
        return 0;
    }

    int dp[n][capacity + 1];

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int c = 0; c <= capacity; c++) {
        if (weights[0] <= c) {
            dp[0][c] = profits[0];
        } else {
            dp[0][c] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int c = 1; c <= capacity; c++) {
            int profit1 = 0;
            int profit2 = 0;

            if (weights[i] <= c) {
                profit1 = profits[i] + dp[i - 1][c - weights[i]];
            }
            profit2 = dp[i - 1][c];

            dp[i][c] = max(profit1, profit2);
        }
    }

    return dp[n - 1][capacity];
}

int main() {
    int n;
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1) return 1;

    int weights[n];
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &weights[i]) != 1) return 1;
    }

    int profits[n];
    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &profits[i]) != 1) return 1;
    }

    int capacity;
    printf("Enter capacity of knapsack: ");
    if (scanf("%d", &capacity) != 1) return 1;

    int maxValue = solveKnapsack(profits, weights, n, capacity);
    printf("Maximum Value: %d\n", maxValue);

    return 0;
}

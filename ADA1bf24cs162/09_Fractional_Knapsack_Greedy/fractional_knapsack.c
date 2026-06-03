#include <stdio.h>

struct Item {
    int id;
    int profit;
    int weight;
    double ratio;
};

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double totalProfit = 0.0;
    int currentWeight = 0;

    printf("\nItems selected in the Knapsack:\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Item %d: Taken completely (Weight: %d, Profit: %d)\n", items[i].id, items[i].weight, items[i].profit);
        } else {
            int remainingCapacity = capacity - currentWeight;
            double fractionProfit = items[i].profit * ((double)remainingCapacity / items[i].weight);
            totalProfit += fractionProfit;
            printf("Item %d: Taken fractionally (Weight taken: %d, Profit gained: %.2f)\n", items[i].id, remainingCapacity, fractionProfit);
            break;
        }
    }

    printf("\nMaximum Total Profit: %.2f\n", totalProfit);
}

int main() {
    int n;
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1) return 1;

    struct Item items[n];
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        if (scanf("%d", &items[i].weight) != 1) return 1;
    }

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &items[i].profit) != 1) return 1;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    int capacity;
    printf("Enter capacity of knapsack: ");
    if (scanf("%d", &capacity) != 1) return 1;

    fractionalKnapsack(items, n, capacity);

    return 0;
}

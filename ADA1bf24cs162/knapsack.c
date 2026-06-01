#include <stdio.h>

struct item {
    int profit;
    float weight, ratio;
};

void sort(struct item arr[], int n);
float fractionalknapsack(int w, struct item arr[], int n);

void sort(struct item arr[], int n) {
    struct item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float fractionalknapsack(int w, struct item arr[], int n) {
    float totalprofit = 0.0;
    float remaining_w = (float)w;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= remaining_w) {
            totalprofit += (float)arr[i].profit;
            remaining_w -= arr[i].weight;
        } else {
            totalprofit += arr[i].ratio * remaining_w;
            remaining_w = 0;
            break;
        }
    }
    return totalprofit;
}

int main() {
    int n, w;
    printf("enter number of item:");
    scanf("%d", &n);
    struct item arr[n];
    printf("enter profit and weight:");
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }
    printf("enter capacity:");
    scanf("%d", &w);
    sort(arr, n);
    float maxprofit = fractionalknapsack(w, arr, n);
    printf("max profit %.2f", maxprofit);
    return 0;
}

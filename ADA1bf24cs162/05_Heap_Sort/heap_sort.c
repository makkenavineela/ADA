#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int larg = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[larg]) {
        larg = left;
    }
    if (right < n && arr[right] > arr[larg]) {
        larg = right;
    }
    if (larg != i) {
        swap(&arr[larg], &arr[i]);
        heapify(arr, n, larg);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[1000], n, i;
    clock_t start, end;
    double CPU_time;

    printf("Enter the size of the array (max 1000): ");
    if (scanf("%d", &n) != 1) return 1;

    if (n > 1000) n = 1000;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    printf("before sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    start = clock();
    heapsort(arr, n);
    end = clock();

    CPU_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken = %f seconds\n", CPU_time);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quciksort(int arr[], int low, int high);

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int piovt = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < piovt) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quciksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quciksort(arr, low, pi - 1);
        quciksort(arr, pi + 1, high);
    }
}

int main() {
    int sizes[] = {10000, 20000, 50000, 100000};
    int num_test = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("%15s|%20s\n", "Elements (n)", "Time Taken (s)");
    printf("------------------------------------\n");

    for (int i = 0; i < num_test; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start = clock();
        quciksort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%15d|%20f\n", n, time_taken);

        free(arr);
    }

    return 0;
}

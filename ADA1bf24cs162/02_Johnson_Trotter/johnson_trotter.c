#include <stdio.h>
#include <stdbool.h>

#define LEFT false
#define RIGHT true

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int getMobile(int a[], bool dir[], int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
        if (dir[i] == RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}

int findPos(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

void swapInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapBool(bool *x, bool *y) {
    bool temp = *x;
    *x = *y;
    *y = temp;
}

void johnsonTrotter(int n) {
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while (1) {
        int mobile = getMobile(a, dir, n);
        if (mobile == 0) break;

        int pos = findPos(a, n, mobile);

        if (dir[pos] == LEFT) {
            swapInt(&a[pos], &a[pos - 1]);
            swapBool(&dir[pos], &dir[pos - 1]);
        } else if (dir[pos] == RIGHT) {
            swapInt(&a[pos], &a[pos + 1]);
            swapBool(&dir[pos], &dir[pos + 1]);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile) {
                if (dir[i] == LEFT) dir[i] = RIGHT;
                else if (dir[i] == RIGHT) dir[i] = LEFT;
            }
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("The permutations are:\n");
    johnsonTrotter(n);

    return 0;
}

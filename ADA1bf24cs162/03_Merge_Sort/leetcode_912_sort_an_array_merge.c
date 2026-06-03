#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* l = (int*)malloc(n1 * sizeof(int));
    int* r = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        l[i] = nums[left + i];
    }
    for (int j = 0; j < n2; j++) {
        r[j] = nums[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            nums[k] = l[i];
            i++;
        } else {
            nums[k] = r[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        nums[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        nums[k] = r[j];
        j++;
        k++;
    }
    
    free(l);
    free(r);
}

void mergesort(int* nums, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergesort(nums, left, mid);
    mergesort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    
    mergesort(nums, left, right);
    
    *returnSize = numsSize; 
    return nums;
}

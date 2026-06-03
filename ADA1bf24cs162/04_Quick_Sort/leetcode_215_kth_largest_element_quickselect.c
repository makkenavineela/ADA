#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL));
    int low = 0;
    int high = numsSize - 1;
    int targetIdx = numsSize - k;

    while (low <= high) {
        int pivotIdx = low + rand() % (high - low + 1);
        int pivot = nums[pivotIdx];
        
        int lt = low;      
        int gt = high;     
        int i = low;       

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[lt], &nums[i]);
                lt++;
                i++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        if (targetIdx >= lt && targetIdx <= gt) {
            return nums[targetIdx];
        } else if (targetIdx < lt) {
            high = lt - 1;
        } else {
            low = gt + 1;
        }
    }
    return -1;
}

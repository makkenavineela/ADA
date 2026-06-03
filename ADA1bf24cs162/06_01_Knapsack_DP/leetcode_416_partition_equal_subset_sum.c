#include <stdbool.h>
#include <string.h>

int memo[201][10001]; 

bool solve(int* nums, int n, int index, int target) {
    if (target == 0) return true;
    if (index >= n || target < 0) return false;

    if (memo[index][target] != -1) {
        return memo[index][target];
    }
    bool included = false;
    if (nums[index] <= target) {
        included = solve(nums, n, index + 1, target - nums[index]);
    }
    
    bool excluded = solve(nums, n, index + 1, target);
    return memo[index][target] = (included || excluded);
}

bool canPartition(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    memset(memo, -1, sizeof(memo));

    return solve(nums, numsSize, 0, target);
}

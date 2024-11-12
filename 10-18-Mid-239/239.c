/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);
    //int *aft = malloc(sizeof(int) * numsSize);
    long mid = nums[0];
    ans[0] = 1;
    ans[1] = nums[0];
    for(int i = 2; i < numsSize; i++){
        mid = mid * nums[i - 1];
        ans[i] = mid;
    }
    mid = 1;
    // mid = nums[numsSize - 1];
    // aft[numsSize - 1] = 1;
    // aft[numsSize - 2] = nums[numsSize - 1];
    // for(int i = numsSize - 3; i >= 0; i--){
    //     mid = mid * nums[i + 1];
    //     aft[i] = mid;
    // }
    for(int i = numsSize - 1; i >= 0; i--){
        ans[i] = ans[i] * mid;
        mid = mid * nums[i];
    }
    *returnSize = numsSize;
    return ans;
}

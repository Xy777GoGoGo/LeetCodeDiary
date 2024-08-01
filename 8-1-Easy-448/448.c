/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *ans = malloc(sizeof(int) * (numsSize + 1));
    int k = 0;
    int p[numsSize + 1];
    memset(p, 0, sizeof(p));
    for (int i = 0; i < numsSize; i++){
        p[nums[i]] = 1;
    }
    for (int i = 1; i <= numsSize; i++){
        if (p[i] != 1){
            ans[k] = i;
            k++;
        }
    }
    *returnSize = k;
    return ans;
}
//看完官方思路：
//
/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *ans = malloc(sizeof(int) * (numsSize + 1));
    int k = 0;
    for (int i = 0; i < numsSize; i++){
           int x =  (nums[i] - 1) % numsSize;
           nums[x] = nums[x] + numsSize;
    }
    for(int i = 0; i < numsSize; i++){
        if (nums[i] <= numsSize){
            ans[k] = i + 1;
            k++;
        }
    }
    *returnSize = k;
    return ans;
}

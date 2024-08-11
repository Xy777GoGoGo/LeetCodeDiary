//自己照搬的一直过不了‘
//#define MAX_SIZE_FACTOR 6
int compInt(const void *a,const void *b) {
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (nums == NULL || numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), compInt); // 排序
    int **ans = (int**)malloc((numsSize + 1) * MAX_SIZE_FACTOR * sizeof(int *));
    *returnColumnSizes = malloc((numsSize + 1) * MAX_SIZE_FACTOR * sizeof(int));
    for (int i = 0; i < numsSize ; i++) {
        if (nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
        if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
        int L = i + 1;
        int R = numsSize - 1;
        while (L < R) {
            int sum = nums[i] + nums[L] + nums[R];
            if(sum == 0) {
                ans[*returnSize] = malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[L];
                ans[*returnSize][2] = nums[R];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (L < R && nums[L] == nums[++L]); // 去重
                while (L < R && nums[R] == nums[--R]); // 去重
            }
            else if (sum < 0) L++;
            else if (sum > 0) R--;
        }
    }
    return ans;
}


int findLengthOfLCIS(int* nums, int numsSize) {
    //dp[i]:以nums[i]结尾最长连续递增子序列
    int dp[numsSize];
    int result = 1;
    for(int i = 0; i < numsSize; i++)
        dp[i] = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        if(dp[i] > result)
            result = dp[i];
    }
    return result;
}

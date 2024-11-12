#define max(a, b) ((a) > (b) ? (a) : (b))
//dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize <= 1){
        return numsSize;
    }
    int dp[numsSize];
    for(int i = 0; i < numsSize; i++){
        dp[i]=1;
    }
    int result = 1;
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > result){
                result = dp[i];
            }
        }
    }
    return result;
}

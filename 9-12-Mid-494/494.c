int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
        return 0;
    }
    int n = numsSize, neg = diff / 2;
    int dp[n + 1][neg + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int num = nums[i - 1];
        for (int j = 0; j <= neg; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= num) {
                dp[i][j] += dp[i - 1][j - num];
            }
        }
    }
    return dp[n][neg];
}

//int findTargetSumWays(int* nums, int numsSize, int target) {
    //肯定有left - right （有正有负） = target，而 left + right = sum
    //所以 left = （sum + target）/2
    //所以题目转化为所有的数字组成left 有几种方式
    //1.确定dp[i][j] 0-i物品凑满j容量的方式
    //2.推导公式
    //i/j 0 1 2 3 4
    //0   1 1 0 0 0   
    //1   1 2 1 0 0
    //2   1 3 3 1 0
    //dp[2][2] :不放物品2：2种（dp[1][2]）
    //         :放物品2（假如能放下)：dp[1][2- nums[2]]
 
//}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int rob(int* nums, int numsSize) {
    //1.dp[i]:第0 - i个房屋能偷窃到的最高金额
    //2.递推公式：dp[i] = max(dp[i - 1],dp[i - 2] + nums[i])
    //      5 2 3 10
    //dp    5 5 8 15
    if(numsSize == 1)
        return nums[0];
    int ans;
    int dp[numsSize];
    memset(dp, 0, sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = nums[0];//偷了0号
    for(int i = 2;i < numsSize - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    ans = dp[numsSize - 2];
    memset(dp, 0, sizeof(int) * numsSize);
    dp[0] = 0;
    dp[1] = nums[1];//偷了1号
    for(int i = 2;i < numsSize; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    if(ans > dp[numsSize - 1])
        return ans;
    return dp[numsSize - 1];
}

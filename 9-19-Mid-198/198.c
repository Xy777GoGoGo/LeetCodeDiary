int tmax(int a, int b, int c){
    if(a >= b && a >= c)
        return a;
    if(b >= a && b >= c)
        return b;
    return c;
}
int rob(int* nums, int numsSize) {
    //1.dp[i]在 不触动警报装置的情况下 偷窃0 - i房的最高金额
    //2.递推公式：
    //dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i],dp[i - 1])
    //3.初始化：dp[0] = nums[0];
    //4.递推方式：左到右
    int dp[numsSize];
    int mid1, mid2;
    memset(dp, 0, sizeof(int) * (numsSize));
    dp[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        mid1 = 0;
        mid2 = 0;
        if(i == 2)
            mid1 = dp[i - 2] + nums[i];
        if(i >= 3){
            mid1 = dp[i - 2] + nums[i];
            mid2 = dp[i - 3] + nums[i];
        }
        if(mid1 > mid2)
            mid2 = mid1;
        dp[i] = tmax(nums[i], mid2, dp[i - 1]);
    }
    return dp[numsSize - 1];
}

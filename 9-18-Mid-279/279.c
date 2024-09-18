int lmin(int a, int b){
    if(a < b)
        return a;
    return b;
}
int numSquares(int n) {
    int nums[100];
    for(int i = 0; i < 100; i++)
        nums[i] = (i + 1) * (i + 1);
    int* dp = malloc(sizeof(int) * (n + 1));
    for(int i = 0; i <= n; i++)
        dp[i] = 10001;
    dp[0] = 0;
    //完全背包，target为n
    //组合数
    //1.dp[i]为凑成i的完全平方数的最小数量
    //2.递推公式：dp[i] = min(dp[i - nums[j]] + 1)
    //3.初始化
    //4.递推顺序：物品在外面，target在里面，里面是顺序
    for(int i = 0; i < 100; i++){
        for(int j = nums[i]; j <= n; j++){
            dp[j] = lmin(dp[j], dp[j - nums[i]] + 1);
        }
    }
    return dp[n];
}

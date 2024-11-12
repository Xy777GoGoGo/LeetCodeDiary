int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int maxProfit(int* prices, int pricesSize, int fee) {
    //每次卖出都得在出2块
    //1.dp[i][0] 表示第i天持有股票所得最多现金
    //  dp[i][1] 表示第i天不持有股票所得最多现金
    //2.递推公式：
    //  dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    //  dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    //3.初始化：
    //5.递推：
    int dp[pricesSize][2];
    memset(dp, 0, sizeof(int) * pricesSize * 2);
    dp[0][0] = - prices[0];
    for(int i = 1; i < pricesSize; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp[pricesSize - 1][1];
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int maxProfit(int k, int* prices, int pricesSize) {
    int dp[pricesSize][k + 1][2];
    memset(dp, 0, sizeof(int) * pricesSize * (k + 1) * 2);
    //1.dp[i][k][0]第i天 第k + 1次未持有股票的最大利润
    //  dp[i][k][1]第i天 第k + 1次持有股票的最大利润
    // 一开始的初始值不算第一次
    //2.递推公式：
    //dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i])
    //要初始化dp[0][j][1]
    //dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i])
    //dp[i][1][1] = max(dp[i - 1][1][1],dp[i - 1][0][0] - prices[i])
    //4.初始化： k =2    2 4 1
    //  第一次 2
    //  dp[0][0][0]:0        dp[0][1][0]:0
    //  dp[0][0][1]:-2       dp[0][1][1]:0
    // 第二次 4
    // dp[1][0][0]:2
    // dp[1][0][1]:-2
    // dp[1][1][0]:0      
    // dp[1][1][1]:-4
    // 第三次 1
    // dp[2][0][0]:2
    // dp[2][0][1]:-1
    // dp[2][1][0]:2
    // dp[2][1][1]:1 
    for(int j = 0; j <= k; j++)
        dp[0][j][1] = -prices[0];
    for(int i = 1; i < pricesSize; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1],dp[i - 1][j - 1][0] - prices[i]);
        }
    }
    return dp[pricesSize - 1][k][0];

}

int maxProfit(int* prices, int pricesSize) {
    int ans= 0;
    for(int i = 0; i < pricesSize - 1; i++){
        int l = prices[i + 1] - prices[i];
        if(l > 0)
            ans = ans + l;
    }
    return ans;
}

// int maxProfit(int* prices, int pricesSize) {
//     int ans= 0;
//     for(int i = 0; i < pricesSize - 1; i++){
//         int l = prices[i + 1] - prices[i];
//         if(l > 0)
//             ans = ans + l;
//     }
//     return ans;
// }
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int maxProfit(int* prices, int pricesSize) {
    //1.dp[i][0] :第i天持有股票所得最多现金(可能今天买也可能之前买的)
    //  dp[i][1] :表示第i天不持有股票所得最多现金
    //2.递推公式：dp[i][0] = max(dp[i - 1][1] - price[i], dp[i - 1][0])
    //           dp[i][1] = max(dp[i - 1][0] + price[i],dp[i -1][1])
    //3.递推顺序：
    //4.初始化：  dp[0][0] = -7  dp[0][1] = 0

    //           dp[1][0] = -1  dp[1][1] = 0
    //           dp[2][0] = -1  dp[2][1] = 4
    //           dp[3][0] = 4 -3 dp[3][1] = 4
    // int dp[pricesSize][2];
    // memset(dp, 0, sizeof(int) * (pricesSize) * 2);
    // dp[0][0] = -prices[0];
    // for(int i = 1; i < pricesSize; i++){
    //     dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
    //     dp[i][1] = max(dp[i - 1][0] + prices[i],dp[i -1][1]);
    // }
    // return max(dp[pricesSize - 1][0], dp[pricesSize -1 ][1]);
    int dp[2];
    dp[0] = -prices[0];
    dp[1] = 0;
    for(int i = 1; i < pricesSize; i++){
        dp[0] = max(dp[1] - prices[i], dp[0]);
        dp[1] = max(dp[0] + prices[i], dp[1]);
    }
    return max(dp[0], dp[1]);
}

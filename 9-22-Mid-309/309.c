#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * 状态一：持有股票状态（今天买入股票，
 * 或者是之前就买入了股票然后没有操作，一直持有）
 * 不持有股票状态，这里就有两种卖出股票状态
 * 状态二：保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。
 * 或者是前一天就是卖出股票状态，一直没操作）
 * 状态三：今天卖出股票
 * 状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！

 */
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 0){
        return 0;
    }
    int dp[pricesSize][4];
    memset(dp, 0, sizeof (int ) * pricesSize * 4);
    dp[0][0] = -prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][2] = dp[i - 1][0] + prices[i];
        dp[i][3] = dp[i - 1][2];
    }
    return max(dp[pricesSize - 1][1], max(dp[pricesSize - 1][2], dp[pricesSize - 1][3]));
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

int maxProfit(int* prices, int pricesSize) {
    int buy1 = prices[0], buy2 = prices[0];
    int profit1 = 0, profit2 = 0;
    for (int i = 0; i < pricesSize; ++i) {
        // 寻找最低点买入
        buy1 = min(buy1, prices[i]);
        // 找到第一次交易的最大盈利,并不断维护这一最大值
        profit1 = max(profit1, prices[i] - buy1);

        // 寻找第二次交易的最低投资点，并且考虑前一次交易的成本
        // 当前价格 - 第一次操作的盈利=新的投入成本（
        // 为了让盈利最大，要寻找最小的成本）
        buy2 = min(buy2, prices[i] - profit1);
        // 第二次卖出后的盈利：当前价格减去成本，不断维护这一最大的总利润
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}
//dp五个状态（也可以四个）

int change(int amount, int* coins, int coinsSize) {
    //背包：amount  物品：coins
    //完全背包
    //1.dp[i]表示总金额为i的组合数
    //2.递推公式：dp[i] = sum[ dp[i - coins]]
    //3.初始化：全为0
    //4.递推顺序：随意
    //5.尝试:
    int dp[amount + 1];
    memset(dp, 0, sizeof(int) * (amount + 1));
    dp[0] = 1;
    for(int i = 0; i < coinsSize; i++){
        for(int j = coins[i]; j <= amount; j++)
            dp[j] += dp[j - coins[i]];
    }
    return dp[amount];
 }
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。

//如果求排列数就是外层for遍历背包，内层for循环遍历物品

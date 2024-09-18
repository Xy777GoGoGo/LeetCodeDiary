int lmin(int a, int b){
    if(a < b)
        return a;
    return b;
}
int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    for (int j = 0; j < amount + 1; j++) {
        dp[j] = INT_MAX;
    }
    dp[0] = 0;
    for(int i = 0; i < coinsSize; i++){
        for(int j = coins[i]; j <= amount; j++){
              if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = lmin(dp[j - coins[i]] + 1, dp[j]);
                }
        }
    }
    if(dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

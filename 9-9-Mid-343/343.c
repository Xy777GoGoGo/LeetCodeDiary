//初始化DP数组
int *initDP(int num) {
    int* dp = (int*)malloc(sizeof(int) * (num + 1));
    int i;
    for(i = 0; i < num + 1; ++i) {
        dp[i] = 0;
    }
    return dp;
}

//取三数最大值
int max(int num1, int num2, int num3) {
    int tempMax = num1 > num2 ? num1 : num2;
    return tempMax > num3 ? tempMax : num3;
}

int integerBreak(int n){
    int *dp = initDP(n);
    //初始化dp[2]为1
    dp[2] = 1;

    int i;
    for(i = 3; i <= n; ++i) {
        int j;
        for(j = 1; j < i - 1; ++j) {
            //取得上次循环:dp[i]，原数相乘，或j*dp[]i-j] 三数中的最大值
            dp[i] = max(dp[i], j * (i - j), j * dp[i - j]);
        }
    }
    return dp[n];
}

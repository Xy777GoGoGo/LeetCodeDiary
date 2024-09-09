int uniquePaths(int m, int n) {
    //1.dp[i][j]的意义：移动到i,j位置的路径总数
    //2.递推公式：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    //3.初始化：dp[0][0] = 0, dp[1][0] = 1; dp[0][1] = 1, dp[1][1] = dp[0][1] + dp[1][0]
    // if(j == 0) dp[i][0] = dp[i - 1][0];
    //if (i == 0) dp[0][j] = dp[0][j - 1];
    //4.从前向后，从上至下
    double **arr = (double **)malloc(sizeof(double *) * (m));
    for(int i = 0; i < m; i++)
        arr[i] = malloc(sizeof(double ) * (n));
    for(int i = 0; i < m; ++i)
        arr[i][0] = 1;
    for(int j = 0; j < n; ++j)
        arr[0][j] = 1;
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
    return arr[m - 1][ n - 1];
}

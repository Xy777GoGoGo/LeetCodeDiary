int imax(int a, int b){
    if(a > b)
        return a;
    return b;
}
int longestPalindromeSubseq(char* s) {
    //1.d[i][j]: i - 1--j - 1中最长的回文子序列
    //2.递推公式：
    //  d[i][j] = if(s[i] == s[j])  为 d[i + 1][j - 1] + 2;
    //               s[i] != s[j]   为max(d[i + 1][j], d[i][j - 1])
    int sSize = strlen(s);
    if(sSize == 1)
        return 1;
    int dp[sSize + 1][sSize + 1];
    memset(dp, 0, sizeof(int) * (sSize + 1) * (sSize + 1));
    //dp[1][1] = 1;
    for(int i = 1; i <= sSize; i ++)
        dp[i][i] = 1;
    for(int j = 1; j <= sSize; j ++){
        for(int i = j - 1; i > 0; i--){
            if(s[i - 1] == s[j - 1])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = imax(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[1][sSize];
}

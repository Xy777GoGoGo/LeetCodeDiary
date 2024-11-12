int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int minDistance(char* word1, char* word2) {
    //求最长公共子序列
    //dp[i][j] 以i结尾的word1 和以j结尾的word2 相同子序列（不用连续）的长度
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1][len2];
    memset(dp, 0, sizeof(int) * len1 * len2);

    for(int i = 0; i < len1; i++){
        if(word1[i] == word2[0]){
            for(int k = i; k < len1; k++)
                dp[k][0] = 1;
            break;
        }
    }
    for(int j = 0; j < len2; j++){
        if(word2[j] == word1[0]){
            for(int k = j; k < len2; k++)
                dp[0][k] = 1;
            break;
        }
    }

    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            if(word1[i] == word2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return len1 + len2 - 2 * dp[len1 - 1][len2 - 1];
}

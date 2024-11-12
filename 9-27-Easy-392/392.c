bool isSubsequence(char* s, char* t) {
    //1.dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]
    //2.递推公式：
    //dp[i][j] = 
    //4.初始化：
    //dp[0][0] = 1 if s[0] == t[0]
    //dp[0][j] ~~~
    //
    int sSize = strlen(s);
    int tSize = strlen(t);
    if(sSize == 0)
        return true;
    if(tSize == 0)
        return false;
    int dp[sSize][tSize];
    memset(dp, 0, sizeof(int) * sSize * tSize);
    for(int j = 0; j < tSize; j++){
        if(s[0] == t[j]){
            for(int k = j; k < tSize; k++)
                dp[0][k] = 1;
            break;
        }
    }
    for(int i = 1; i < sSize; i++){
        for(int j = i; j < tSize; j++){
            if(s[i] == t[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = dp[i][j - 1];
        }
    }
    if(dp[sSize - 1][tSize - 1] == sSize)
        return true;
    return false;
}

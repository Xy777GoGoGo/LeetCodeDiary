int numDistinct(char* s, char* t) {
    //1.dp[i][j] dp[i][j]：以i为结尾的s子序列中出现以j为结尾的t的个数为dp[i][j]
    //2.递推公式
    // dp[i][j] = 如果s[i] == t[j]   两种情况：用是s[i]去匹配（也就是s【i】必选）为dp[i - 1][j - 1]
    //                                        不用s[i]去匹配（也就是s【i】不选）为dp[i - 1][j]
    //            如果不相等为dp[i - 1][j]
    //4.初始化（i >= j）
    //dp[0][0] = 1if(s[0] == t[0]) 从而dp[i][0]也可推出（不需要break,因为可以重复）
    int sSize = strlen(s);
    int tSize = strlen(t);
    int dp[sSize][tSize];
    memset(dp, 0, sizeof(int) * sSize * tSize);
    //初始化
    for(int i = 0; i < sSize; i++){
        if(s[i] == t[0]){
            for(int k = i; k < sSize; k++)
                dp[k][0]++;
        }
    }

    for(int i = 1; i < sSize; i++){
        for(int j = 1; j <= i && j < tSize; j++){
            if(s[i] == t[j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (1000000000 + 7);
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[sSize - 1][tSize - 1] ;
}

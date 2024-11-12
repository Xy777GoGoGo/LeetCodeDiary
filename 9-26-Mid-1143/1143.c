int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int longestCommonSubsequence(char* text1, char* text2) {
    int text1Size = strlen(text1);
    int text2Size = strlen(text2);
    int dp[text1Size][text2Size];
    memset(dp, 0, sizeof(int) * text1Size * text2Size);
    //下面初始化：
    for(int j = 0; j < text2Size; j++){
        if(text1[0] == text2[j]){
            for(int k = j; k < text2Size; k++)
                dp[0][k] = 1;
            break;
        }
    }
    for(int i = 0; i < text1Size; i++){
        if(text2[0] == text1[i]){
            for(int k = i; k < text1Size; k++)
                dp[k][0] = 1;
            break;
        }
    }
    for(int i = 1; i < text1Size; i++){
        for(int j = 1; j < text2Size; j++){
            if(text1[i] == text2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[text1Size - 1][text2Size - 1];
}

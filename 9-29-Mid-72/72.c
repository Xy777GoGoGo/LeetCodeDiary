aint min(int num1, int num2, int num3) {
    return num1 > num2 ? (num2 > num3 ? num3 : num2) : (num1 > num3 ? num3 : num1); 
}

int minDistance(char * word1, char * word2){
    int dp[strlen(word1)+1][strlen(word2)+1];
    dp[0][0] = 0;
    for (int i = 1; i <= strlen(word1); i++) dp[i][0] = i;
    for (int i = 1; i <= strlen(word2); i++) dp[0][i] = i;

    for (int i = 1; i <= strlen(word1); i++) {
        for (int j = 1; j <= strlen(word2); j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
            }
        }
    }
    return dp[strlen(word1)][strlen(word2)];
}

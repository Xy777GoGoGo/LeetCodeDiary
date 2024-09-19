bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    // 初始化
    bool dp[len + 1];
    memset(dp, false, sizeof (dp));
    dp[0] = true;
    for (int i = 1; i < len + 1; ++i) {
        for(int j =  0; j < wordDictSize; j++){
            int wordLen = strlen(wordDict[j]);
            // 分割点是由i和字典单词长度决定
            int k = i - wordLen;
            if(k < 0){
                continue;
            }
            // 这里注意要限制长度，故用strncmp
            dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], wordLen)) || dp[i];
        }
    }
    return dp[len];
}

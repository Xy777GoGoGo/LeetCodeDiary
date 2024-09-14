int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int findMaxForm(char** strs, int strsSize, int m, int n) {
    //思路：需要排序？
    //1.dp[i][j]:最多有i个0和j个1的strs的最大子集的大小为dp[i][j]
    //2.递推公式：d[i][j] = dp[i - znum][j - onum]  + 1
    //所以递推公式：dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
    //3.初始化:为0
    //4.递推顺序：外层从头到尾，内层从尾到头
    int ans[m + 1][n + 1];
    memset(ans, 0, sizeof (int ) * (m + 1) * (n + 1));
    for(int k = 0; k < strsSize; k++){
        int znum = 0, onum = 0;
        for(int l = 0; l < strlen(strs[k]); l++){
            if(strs[k][l] == '0')
                znum++;
            if(strs[k][l] == '1')
                onum++;
        }
        for(int i = m; i >= znum; i --){
            for(int j = n; j >= onum; j--){
                if(i >= znum && j >= onum)
                    ans[i][j] = max(ans[i][j], ans[i - znum][j - onum] + 1);
            }
        }
    }
    return ans[m][n];
}

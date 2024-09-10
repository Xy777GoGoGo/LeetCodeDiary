int numTrees(int n) {
    //1.dp[i]i个节点的二叉搜索树的个数
    //2.递推公式：
    //元素1为头结点搜索树的数量 = 右子树有2个元素的搜索树数量 * 左子树有0个元素的搜索树数量
    //元素2为头结点搜索树的数量 = 右子树有1个元素的搜索树数量 * 左子树有1个元素的搜索树数量
    //元素3为头结点搜索树的数量 = 右子树有0个元素的搜索树数量 * 左子树有2个元素的搜索树数量
    //3.初始化： dp[1] = 1; dp[2] = 2;
    //          dp[3] = dp[0]dp[2] + dp[1]dp[1] + dp[2]dp[0] = 5
    //          dp[4] = dp[0]dp[3] + dp[1]dp[2] + dp[2]dp[1] + dp[3]dp[0]
    //4.递推顺序：
    int* ans = malloc(sizeof(int) * (n + 1));
    if(n < 3)
        return n;
    ans[0] = 1; ans[1] = 1; ans[2] = 2;
    for(int i = 3; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < i; j++)
            sum = sum + ans[j] * ans[i - j - 1];
        ans[i] = sum;
    }
    return ans[n];
}

int min(int a, int b){
    if(a < b)
        return a;
    return b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    //1.确定dp数组以及下标的含义
    //dp[i]： 爬到第i层楼梯最低花费
    //2.确定递推公式
    //dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    //3.dp数组如何初始化
    //dp[1] = 0, dp[0] = 0;
    //4.确定遍历顺序
    //从前向后遍历的
    //5.例推导dp数组
    int mid0 = 0, mid1 = 0, ans;
    //mid0 记录dp[i - 2]
    //mid1 记录dp[i - 1]
    for(int i = 2; i <= costSize; i ++){
        ans = min(mid0 + cost[i - 2], mid1 + cost[i - 1]);
        mid0 = mid1;
        mid1 = ans;
    }
    return ans;
}

int climbStairs(int n) {
    //1.dp[i]所在的爬梯数
    //2.dp[i] = dp[i - 1] + dp[i -2]
    //3.dp[i] = { 1, 2}
    //4.从前向后遍历
    //5.
    double ans = 0;
    int two = n / 2; //最多有two个2个台阶
    for(int i = 0; i <= two; i++){
        //此时有 n - 2 * i 个1阶台阶， 一共n - i 个台阶
        double fenzi = 1, fenmu = 1;
        for(int j = i; j > 0; j--){
            fenzi = fenzi * j;
            fenmu = fenmu * (n - i + j - i);
        }
        ans = ans + fenmu / fenzi;
    }
    return ans;
}


int climbStairs(int n) {
    //爬到第一层楼梯有一种方法，爬到二层楼梯有两种方法。

//那么第一层楼梯再跨两步就到第三层 ，第二层楼梯再跨一步就到第三层。

//所以到第三层楼梯的状态可以由第二层楼梯 和 到第一层楼梯状态推导出来，那么就可以想到动态规划了。
    //1.确定dp数组以及下标的含义
    //dp[i]： 爬到第i层楼梯，有dp[i]种方法

    //2.确定递推公式
    //首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。

//还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。

//那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！

//所以dp[i] = dp[i - 1] + dp[i - 2]
    //3.dp数组如何初始化
    //相信dp[1] = 1，dp[2] = 2，这个初始化大家应该都没有争议的

    //4.确定遍历顺序
    //从前向后遍历的
    //5.例推导dp数组
    if( n < 3)
        return n;
    int p = 1, q = 2, r;
    for(int i = 3; i <= n; i++){
        r = p + q;
        p = q;
        q = r;
    }
    return r;
}
int climbStairs(int n) {
//完全背包
//物品1 ，2   背包 n
//1.dp[i] 代表到到阶梯i有这么多种（排列数）
//2.dp[i] = sum(dp[i - nums[i]])
//3.初始化dp[0] =1
//4.递推顺序：背包在外面，物品在里面，里面循环是顺序
    int dp[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2; j++ ){
            if(i >= j)
                dp[i] = dp[i] + dp[i - j];
        }
    }
    // n: 0 1 2 3 4
    //dp: 1 0 0 0 0
    //  : 1 1 0 0 0
    //  : 1 1 2 
    return dp[n];
}

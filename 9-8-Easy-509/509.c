int fib(int n){
    if(n < 2)
        return n;
    int p = 0, q = 0, r = 1;
    for(int i = 2; i <= n; i++){
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}
动规五部曲：

这里我们要用一个一维dp数组来保存递归的结果

1.确定dp数组以及下标的含义
dp[i]的定义为：第i个数的斐波那契数值是dp[i]

2.确定递推公式
为什么这是一道非常简单的入门题目呢？

因为题目已经把递推公式直接给我们了：状态转移方程 dp[i] = dp[i - 1] + dp[i - 2];

3.dp数组如何初始化
题目中把如何初始化也直接给我们了

4.确定遍历顺序
从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的

5.举例推导dp数组
按照这个递推公式dp[i] = dp[i - 1] + dp[i - 2]，我们来推导一下，当N为10的时候，dp数组应该是如下的数列：

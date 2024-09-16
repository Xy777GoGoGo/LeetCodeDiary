int combinationSum4(int* nums, int numsSize, int target) {
    //先用二维数组把
    //这时完全背包，要找组合数
    //背包容量： target
    //物品 nums[]里面的元素
    int dp[numsSize + 1][ target + 1];
    memset(dp, 0, sizeof(int) * (numsSize + 1) * (target + 1));
    //1.dp[i][j] : 用前i + 1个整数（可以不选某个），凑成j的方案数目
    //2.递推公式：dp[i][j] = 
    //                      dp[i - 1][j - nums[i]] + dp[i - 1][j]
    //                ->    (k)Sum(dp[i][j-nums[k]])
    //该在选取到每个i时，都把从k:0-i的组合都累加一遍
    //意思是去掉任一个数，把这些次数加起来
    //3.初始化：  dp[i][0] = 1
    //4.遍历顺序：i，j 怎么样都行
    //5.递推一下：nums[] = [1, 2 ,3 ]   target = 4
    //i/j  0 1 2 3 4 
    //0    1 1 1 1 1 
    //1    1 1 2 3 5
    //2    1 1 2 4 7 
    for(int i = 0; i <= numsSize; i++)
        dp[i][0] = 1;
    
    for(int i = 0; i <= numsSize; i++){
        for(int j = 1; j <= target; j++){
            long sum = 0;
            for(int l = 0;l < i; l++){
                if(j >= nums[l])
                    sum = sum + dp[i][j - nums[l]];
            }
            dp[i][j] = sum;
        }
    }

    return dp[numsSize][target]; 
}

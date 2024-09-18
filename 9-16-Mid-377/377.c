
/*
 * int combinationSum4(int* nums, int numsSize, int target) {
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
*/
#include <stdio.h>
#include <string.h>
void main(){
	  int dp[5];
		int nums[4] = {3, 1, 2, 4};
		int target = 4;
		int numsSize = 4;
    memset(dp, 0, sizeof(int) * (target + 1));
    //1.dp[i]:数组nums元素组成i的组合数
    //2.递推公式：dp[i] = sum(dp[i - nums[j]])
    //3.初始化：dp[0] = 1
    //4.递推顺序：先i再j
    //5.尝试递推 0 1 2 3 4 
    //           1 1 2 4 8
    dp[0] = 1;
/*
 *
 * 排列数
 * 注意物品的遍历在里面，对每一个target，顺序就会有关系
		for(int i = 1; i <= target; i++){
        int sum = 0;
        for(int j = 0; j < numsSize; j++){
					if(i >= nums[j]){
						 sum = sum + dp[i - nums[j]];
						 printf("%d	", nums[j]);
					}
				}
				printf("\n dp[%d] :%d \n", i, sum);
        dp[i] = sum;
    }
*/
/*	
 *	组合数
		for(int j = 0; j < numsSize; j++){
			printf("nums[%d]: %d\n", j, nums[j]);
			for(int i = nums[j]; i <= target; i++){
					dp[i] = dp[i] + dp[i - nums[j]];
					for(int i = 0; i <= target; i++)
						printf("%d	", dp[i]);
					printf("\n");
			}
			printf("\n");
		}
*/

		//下面看0-1背包
		//主要看那个一位数组的倒序和顺序遍历的不同

//下面是正常实现
		//1.dp[i]代表填满target为i的组合数
		//2.递推公式：
		//	dp[i] = dp[i] + dp[i - nums[j]]
		//和上面的组合数的一模一样
	 for(int j = 0; j < numsSize; j++){//第一层循环就固定了是nums中的某个价值
       printf("nums[%d]: %d\n", j, nums[j]);
       for(int i = target; i >= nums[j]; i--){
           dp[i] = dp[i] + dp[i - nums[j]];
           for(int i = 0; i <= target; i++)
             printf("%d  ", dp[i]);
           printf("\n");
       }
       printf("\n");
     }
//为何一个顺序，一个倒序区别这么大
//倒序为何每个数只能去一个，而顺序的每个数可以取多个
//不妨看个例子：  2 1 3   target 3
//先看顺序的：dp： 1 0 0 0 初始
//对第一个数2		i = 2			 1 0 1 0  ,首先是凑成0 + 凑成2的组合数      选择 2
//	  		      i = 3			 1 0 1 0  ，这边是dp[3]（对上一次的数） + dp[1]	 这边凑不到(暗示选择了2)
//对第二个数1   i = 1      1 1 1 0  ，首先是凑成0 + 凑成1 的组合数    选择 1
//							i = 2			 1 1 2 0  ，这边是dp[2](对上一次的数) + dp[1]（暗示选择了1）   选择  2  以及 1 1 
//							思考： 这边多选了一次1   是因为又加了dp[1],也就是说从左到右循环，总会加上前面选的，造成多次选取
//
//再看倒序的：dp：1 0 0 0 初始
//对第一个数2  i = 3      1 0 0 0,这边是dp[3]（对上一次的数） + dp[1]  这边凑不到
//						 i = 2			1 0 1 0，凑成0 + 凑成2的组合数      选择 2
//对第二个数1  i = 3      1 0 1 1,dp[3]（对上一次的数） + dp[2]    选择 2 ， 1
//						 i = 2      1 0 1 1,dp[2]（对上一次的数） + dp[1]    选择 2
//						 i = 1      1 1 1 1,dp[1]（对上一次的数） + dp[0]    选择 1
//						 思考：为啥只能选一次？由于是从右到左加的dp[i]都是在上一次循环的值，而在上一次循环中是对前一个数的加入与否讨论，导致每个数只能选一次
//												
}

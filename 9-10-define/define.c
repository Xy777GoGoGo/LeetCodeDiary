/*
 * 第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。

  第二行包含 M 个正整数，代表每种研究材料的所占空间。

  第三行包含 M 个正整数，代表每种研究材料的价值。

  输出一个整数，代表小明能够携带的研究材料的最大价值。
  输入实例：
  6 1
  2 2 3 1 5 2
  2 3 1 5 4 3
  输出实例：
  5
 */  
//i  j 0 1 2 3 4 5  
//0    0 
//1		 0
//2		 0
//3		 0
//4		 0
#include <stdio.h>
int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

void main(){
  int value[6]= {2, 3, 1, 5, 4, 3};
	int roomcost[6] = {2, 2, 3, 1, 5, 2};
	int room = 1;
	int number = 6;
	//二维数组实现
	//1.dp[i][j] 定义 ： i： 0 - i 物品    j ：包裹的容量空间
	//总的意思就是 在j的情况下，把0- i物品（每个物品只有一件）放进去的最大价值
	//2.递推公式：对于dp[1][4]首先是放不放物品1,如果不放，则取dp[0][4]
	//																					如果放，得先把空间腾出来，有dp[0][4 - roomcost[1]] + value[1]
	//						于是dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - roomcost[i]] + value[i]);
	//3.初始化：
	//注意到当j = 0, value都为0   当 i = 0， 得看j的容量大不大
	//4.递推顺序
	int ans[6][6] = {0};
//先初始化
	for(int j = 0; j < 6; j++){
			if(j >= roomcost[0])
				ans[0][j] = value[0];
	}
// 下面直接开始
 for(int i = 1; i < 6; i++){
	for(int j = 1; j < 6; j++){
		if(j >= roomcost[i]){
			int mid = j - roomcost[i];
			ans[i][j] = max(ans[i - 1][j], ans[i - 1][mid] + value[i]);
			continue;
		}
		ans[i][j] = ans[i - 1][j];
	}
 }
//打印
 for(int i = 0; i < 6; i++){
   for(int j = 0; j < 6; j++){
		 printf("%d	", ans[i][j]);
	 }
	 printf("\n");
 }

}                                                                                             


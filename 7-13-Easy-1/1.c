/*int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //双指针
    *returnSize = 2;
    int beg, fia, i, j;
    int* a = (int *)malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize - 1; i++)
        for (j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                beg = i;
                fia = j;
            }
        }
    a[0] = beg;
    a[1] = fia;
    return a;
}
*/
//经典的双重循环，但只打败5%的人无论是在内存和时间，下面尝试改良
//看了提示，固定x，在剩下的数字寻找-x
//另一种使用hash map 加快搜素速度
//第一种没思路，第二种闻所未闻（未系统学习hash map）
//看了其他解答，先用排序+二分
#include <stdio.h>
#include <stdlib.h>
	void merge(int *a, int *aux, int lo, int mid, int hi) {
    //aux存储两列数列
    for(int k =lo; k<= hi; k++){
    	aux[k] = a[k];
		}
    int i=lo ,j=mid+1;//分别在这两列已经排好序的数列第一个数标记

   	for(int k =lo; k<= hi; k++){
    	if (i > mid)						//注意i，j都是会增加的，当左边数列的数全部取出，此时i>mid
       		a[k]= aux[j++];     //直接把右边数列的数依次放入nums中
        else if (j > hi)			//同理
        	a[k]= aux[i++];
        else if (aux[j] < aux[i])//比较大小，小的数放在左边第k位，随后j++（aux[j]已经放好了）
        	a[k]= aux[j++];
        else
        	a[k]= aux[i++];//同理
    }
}
void sort(int *a, int *aux, int lo, int hi){
    if (hi <= lo)
        return;
    int mid = lo +(hi - lo) / 2;
    sort (a, aux, lo, mid);//排列左边
    sort (a, aux, mid+1, hi);//排列右边
		if (a[mid + 1] >= a[mid])
       return;								//已经归并好了，直接返回
    merge(a ,aux, lo, mid, hi);//把两边排列好的数列合并
}
//nums是最终排序好的数列
void main(){
	int nums[]={3,2,4};
	int numsSize=3;
	int target = 6;
	  int lo, hi, aux[numsSize];
    int arr[numsSize][2];
    int* a = (int *)malloc(sizeof(int) * 2);
    for (int i = 0;i < numsSize; i++){
        arr[i][0] = nums[i];//值   
        arr[i][1] = i;//下标
    }
    //归并排序
    sort(nums, aux, 0, numsSize - 1);
 //  for (int i = 0;i < numsSize; i++){
   //      printf("%d ",nums[i]);
    // }

    lo = 0, hi = numsSize - 1;
    for (int i = 0;i < numsSize; i++){
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if (arr[mid][0] == target - nums[i] && i != arr[mid][1]){
                a[0] = i;a[1] = arr[mid][1];
								return;
            }
            else if (arr[mid][0] > target - nums[i])  hi = mid - 1;
            else lo = mid + 1;
        }
    }

}
//消耗内存最少的
/*
 * int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
//消耗时间最少的
//#define HashSize 107 // 哈希表大小

typedef struct Node { // 哈希结点
    int value; // 值
    int index; // 下标
    struct Node* next; // 下指针
}Node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int n = numsSize; // 数组长度
    Node* hash[HashSize]; // 哈希表
    for (int i = 0; i < HashSize; i++) { // 初始化哈希表
        hash[i] = (Node*)malloc(sizeof(Node));
        hash[i]->value = hash[i]->index = -1;
        hash[i]->next = NULL;
    }
    for (int i = 0; i < n; i++) { // 遍历一遍原数组
        int pos = abs(target - nums[i]) % HashSize; // 找到 target - nums[i] 在哈希表中对应的位置
        Node* head = hash[pos];
        while (head->next && head->next->value != target - nums[i]) head = head->next; 
	// 找该位置是否有 target - nums[i] 这个值
        if (head->next) { // 找到符合题意的值
            *returnSize = 2;
            int* ans = (int*)malloc(sizeof(int) * 2);
            ans[0] = i; ans[1] = head->next->index; // 写入答案
            for (int i = 0; i < HashSize; i++) free(hash[i]);
            return ans;
        }
        pos = abs(nums[i]) % HashSize; // 找到 nums[i] 在哈希表中对应的位置
        head = hash[pos];
        while (head->next) head = head->next; // 写在这个位置的末尾
        head->next = (Node*)malloc(sizeof(Node));
        head->next->value = nums[i]; // 写入该值
        head->next->index = i; // 写入该值对应的下标
        head->next->next = NULL;
    }
    for (int i = 0; i < HashSize; i++) free(hash[i]);
    *returnSize = 0;
    return NULL;
}

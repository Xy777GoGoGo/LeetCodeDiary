/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //暴力循环
    int *ans = malloc(sizeof(int) * nums1Size);
    int l = 0;
    for (int i = 0; i < nums1Size; i++){
        for (int j = 0; j < nums2Size; j++){
            if (nums1[i] == nums2[j]){
                ans[l] = -1;
                for (int k = j; k < nums2Size; k++){
                    if (nums2[k] > nums2[j]){
                        ans[l] = nums2[k];
                        break;
                    }
                }
                l ++;
            }
        }
    }
    *returnSize = l;
    return ans;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 struct hash{
     int key;   //哈希表的键， 表示当前要寻找的值
     int val;   //哈希表的值， 记录下一个最大元素
     UT_hash_handle hh;
 };

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;  //返回数量为数组一的大小

    struct hash *hash = NULL; //初始化hash表
    int stack[nums2Size];  //栈
    int top = -1;       //栈顶

    for (int i = nums2Size - 1; i >= 0; i--){ //后到前遍历
        //维护单调栈
        while (top > -1 && stack[top] < nums2[i])
            top--;
        //使用哈希表记录
        struct hash *tmp = (struct hash*)malloc(sizeof(struct hash));
        tmp->key = nums2[i];
        tmp->val = top == -1 ? top : stack[top];// 判断top == -1 ，是的话转top，否则转stack[top]
        //记录到哈希表中
        HASH_ADD_INT(hash, key, tmp);
        //入栈
        stack[++top] = nums2[i];
    }

    struct hash *tmp;
    for (int i = 0; i < nums1Size; i++){
        //哈希表中找到当前查找的值
        HASH_FIND_INT(hash, nums1 + i, tmp);
        //赋值
        nums1[i] = tmp->val;
    }

    return nums1;  //返回
}


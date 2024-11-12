/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //双端队列（Deque，全称：Double-ended Queue）是一种线性数据结构，
 //它允许在队列的两端进行插入和删除操作
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    //维护一个双端队列
    int size = numsSize - k + 1;
    int *ans = malloc(sizeof(int) * size);
    int *queue = malloc(sizeof(int) * numsSize);
    //存储所有还没有被移除的下标
    int head = 0, tail = 0;
    for(int i = 0; i < k; i++){
        if(tail == 0)
            queue[tail++] = i;
        //nums[i] 永久地移除
        while(head < tail && nums[i] >= nums[queue[tail - 1]])//此时head指的一定为最大值
            tail--;
        queue[tail++] = i;
    }
    *returnSize = 0;
    ans[(*returnSize)++] = nums[queue[head]];
    //下面进行窗口滑动
    for(int i = k; i < numsSize; i++){
        //同理吧i放入队列
        while(head < tail && nums[i] >= nums[queue[tail - 1]])
            tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k){//说明此时滑动窗口的数量超出了(注意queue记录了下标)
            head++;//弹出
        }
        ans[(*returnSize)++] = nums[queue[head]];
    }   
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++)
        ans[i] = -1;

    int* zhan = (int*)malloc(sizeof(int) * numsSize * 2);
    int head = 0;
    for(int i = 0; i < numsSize * 2; i++){
        //模拟两个数组并在一起的情形
        if(head == 0){
            zhan[head++] = i % numsSize;
            continue;
        }
        if(nums[i % numsSize] <= nums[zhan[head - 1]])
            zhan[head++] = i % numsSize;
        else{
            while(head > 0 && nums[i % numsSize] > nums[zhan[head - 1]]){
                ans[zhan[head - 1]] = nums[i % numsSize];
                head --;
            }
            zhan[head++] = i % numsSize;
        }
    }

    *returnSize = numsSize;
    return ans;
}
